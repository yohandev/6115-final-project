#include "pico/stdlib.h"
#include <stdio.h>

#include "rasterizer.h"
#include "framebuffer.h"
#include "num.h"

inline static fixed barycentric_coord(vec2 a, vec2 b, vec2 c) {
    return fixed_mul(b.x - a.x, c.y - a.y) - fixed_mul(b.y - a.y, c.x - a.x);
}

// Implementation of a triangle rasterizer using the barycentric algorithm, as described
// here:
// https://fgiesen.wordpress.com/2013/02/08/triangle-rasterization-in-practice/
// https://fgiesen.wordpress.com/2013/02/10/optimizing-the-basic-rasterizer/
// 
// The intution for choosing this algorithm is that since the pixel buffer is so small,
// loop over an AABB might actually be faster than the overhead of e.g. bresenham algorithms
// where no pixels are "wasted" but has a longer initialization time. Moreover, testing for
// a point inside of a triangle (in a loop) can be further optimized to just a handful of
// addition and shifts which the RP2040 interpolator can perform in one cycle. Of course,
// decisive results would require proper benchmarks over different candidate algorithms.
void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2 a, vec2 b, vec2 c, rgb col) {
    // AABB of the triangle
    fixed min_x = min(min(a.x, b.x), c.x);
    fixed min_y = min(min(a.y, b.y), c.y);
    fixed max_x = max(max(a.x, b.x), c.x);
    fixed max_y = max(max(a.y, b.y), c.y);
    
    // Contain within the framebuffer
    min_x = max(min_x, 0);
    min_y = max(min_y, 0);
    max_x = min(max_x, i32_to_fixed(FRAME_BUFFER_WIDTH) - FIXED_EPSILON);
    max_y = min(max_y, i32_to_fixed(FRAME_BUFFER_HEIGHT) - FIXED_EPSILON);

    // Triangle setup
    fixed A01 = a.y - b.y, B01 = b.x - a.x;
    fixed A12 = b.y - c.y, B12 = c.x - b.x;
    fixed A20 = c.y - a.y, B20 = a.x - c.x;

    // Barycentric coordinates at min. corner
    fixed w0_row = barycentric_coord(b, c, (vec2) { .x=min_x, .y=min_y });
    fixed w1_row = barycentric_coord(c, a, (vec2) { .x=min_x, .y=min_y });
    fixed w2_row = barycentric_coord(a, b, (vec2) { .x=min_x, .y=min_y });

    usize min_yi = fixed_to_i32(min_y);
    usize min_xi = fixed_to_i32(min_x);
    usize max_yi = max(fixed_to_i32(max_y), 0);
    usize max_xi = max(fixed_to_i32(max_x), 0);

    // Keep track of flatenned index to avoid unnecesarry multiplication at each pixel
    usize i = framebuffer_idx(min_xi, min_yi);
    usize i_row = FRAME_BUFFER_WIDTH + min_xi - max_xi - 1;

    // Draw
    for (usize y = min_yi; y <= max_yi; y++) {
        // Barycentric coordinates at start of row
        fixed w0 = w0_row;
        fixed w1 = w1_row;
        fixed w2 = w2_row;

        for (usize x = min_xi; x <= max_xi; x++) {
            // If p is on or inside all edges, render pixel.
            if ((w0 | w1 | w2) >= 0) {
                sbuf->pixels[i] = col;
            }

            // One step to the right
            w0 += A12;
            w1 += A20;
            w2 += A01;
            i++;
        }

        // One row step
        w0_row += B12;
        w1_row += B20;
        w2_row += B01;
        i += i_row;
    }
}

void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, usize log2scale) {
    vec2 a;
    vec2 b;
    vec2 c;
    
    printf("Starting benchmark...\n");
    u64 start = time_us_64();
    for (usize i = 0; i < num_iter; i++) {
        a.x = rand() >> log2scale;
        a.y = rand() >> log2scale;
        b.x = rand() >> log2scale;
        b.y = rand() >> log2scale;
        c.x = rand() >> log2scale;
        c.y = rand() >> log2scale;

        rasterizer_draw_triangle(sbuf, a, b, c, (rgb) { 0b11111 });
    }
    u64 elapsed = time_us_64() - start;

    printf("Drawing %d triangles took %lldus (avg. %fus/iter).\n", num_iter, elapsed, (f32)elapsed / num_iter);
}

void rasterizer_draw_mesh(struct Framebuffer* sbuf, const struct Mesh* mesh, const mat4s* mvp) {
    struct {
        vec2 px;
        vec3 pos;
        u16 idx;
        bool clip;
    } screen_space_cache[RASTERIZER_VERTEX_CACHE_LEN];

    // Invalidate cache at index 0
    screen_space_cache[0].idx = -1;

    // For each triangle
    for (usize i = 0; i < mesh->num_faces * 3; i += 3) {
        vec2 pts[3];
        vec3 spos[3];
        // For each vertex within triangle
        for (usize j = 0; j < 3; j++) {
            u16 idx = mesh->indices[i + j];
            usize hash = idx % RASTERIZER_VERTEX_CACHE_LEN;

            // Cache all computed vertices. Ideally, meshes generated by Blender will
            // contain indices that are roughly monotonically increasing and vertices
            // are typically shared by multiple adjacent faces. There isn't enough space
            // to cache all the screen space vertices but a small cache helps with
            // wasted computation.
            if (screen_space_cache[hash].idx != idx) {
                vec3 pos = mat4s_apply_vec3s(mvp, (vec3s) {
                    .x = mesh->vertices[idx * 3 + 0],
                    .y = mesh->vertices[idx * 3 + 1],
                    .z = mesh->vertices[idx * 3 + 2],
                });
                vec2 out;
                if (pos.z > f32_to_fixed(RASTERIZER_NEAR_CLIP)) {
                    out.x = fixed_mul(fixed_div(pos.x, pos.z), i32_to_fixed(FRAME_BUFFER_WIDTH));
                    out.y = fixed_mul(fixed_div(pos.y, pos.z), i32_to_fixed(FRAME_BUFFER_HEIGHT));

                    out.x += i32_to_fixed(FRAME_BUFFER_WIDTH / 2);
                    out.y += i32_to_fixed(FRAME_BUFFER_HEIGHT / 2);

                    screen_space_cache[hash].clip = false;
                } else {
                    screen_space_cache[hash].clip = true;
                }

                screen_space_cache[hash].pos = pos;
                screen_space_cache[hash].px = out;
                screen_space_cache[hash].idx = idx;
            }

            // If a single vertex is clipped, just skip the entire face
            if (screen_space_cache[hash].clip) {
                goto clip_face;
            }
            pts[j] = (vec2) {
                .x = screen_space_cache[hash].px.x,
                .y = screen_space_cache[hash].px.y,
            };
            spos[j] = screen_space_cache[hash].pos;
        }

        // Cull backfaces
        fixed winding = fixed_mul(pts[1].x - pts[0].x, pts[2].y - pts[0].y) - fixed_mul(pts[2].x - pts[0].x, pts[1].y - pts[0].y);
        if (winding < 0) {
            continue;
        }

        // Lambert lighting
        vec3 norm = vec3_cross(vec3_sub(spos[1], spos[0]), vec3_sub(spos[2], spos[0]));
        fixed light = fixed_div(vec3_dot(norm, SUN_LIGHT), vec3_magnitude(norm));
        u16 c = max(light >> 11, 5) << 11;
        rgb col = { (c >> 8) | (c << 8) };

        // Rasterize face
        rasterizer_draw_triangle(sbuf, pts[0], pts[1], pts[2], col);

        clip_face:;
    }
}