#include "pico/stdlib.h"
#include <stdio.h>

#include "rasterizer.h"
#include "framebuffer.h"
#include "num.h"

inline static fixed barycentric_coord(
    fixed ax, fixed ay,
    fixed bx, fixed by,
    fixed cx, fixed cy
) {
    return fixed_mul(bx - ax, cy - ay) - fixed_mul(by - ay, cx - ax);
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
void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2 a, vec2 b, vec2 c) {
    fixed ax = f32_to_fixed(a.x);
    fixed ay = f32_to_fixed(a.y);
    fixed bx = f32_to_fixed(b.x);
    fixed by = f32_to_fixed(b.y);
    fixed cx = f32_to_fixed(c.x);
    fixed cy = f32_to_fixed(c.y);
    
    // AABB of the triangle
    fixed min_x = min(min(ax, bx), cx);
    fixed min_y = min(min(ay, by), cy);
    fixed max_x = max(max(ax, bx), cx);
    fixed max_y = max(max(ay, by), cy);
    
    // Contain within the framebuffer
    min_x = max(min_x, 0);
    min_y = max(min_y, 0);
    max_x = min(max_x, i32_to_fixed(FRAME_BUFFER_WIDTH) - FIXED_EPSILON);
    max_y = min(max_y, i32_to_fixed(FRAME_BUFFER_HEIGHT) - FIXED_EPSILON);

    // Triangle setup
    fixed A01 = ay - by, B01 = bx - ax;
    fixed A12 = by - cy, B12 = cx - bx;
    fixed A20 = cy - ay, B20 = ax - cx;

    // Barycentric coordinates at min. corner
    fixed w0_row = barycentric_coord(bx, by, cx, cy, min_x, min_y);
    fixed w1_row = barycentric_coord(cx, cy, ax, ay, min_x, min_y);
    fixed w2_row = barycentric_coord(ax, ay, bx, by, min_x, min_y);

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
                sbuf->pixels[i] = (rgb){ 0b11111 };
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

void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, f32 bound) {
    vec2 a;
    vec2 b;
    vec2 c;
    
    printf("Starting benchmark...\n");
    u64 start = time_us_64();
    for (usize i = 0; i < num_iter; i++) {
        a.x = randf() * bound;
        a.y = randf() * bound;
        b.x = randf() * bound;
        b.y = randf() * bound;
        c.x = randf() * bound;
        c.y = randf() * bound;

        rasterizer_draw_triangle(sbuf, a, b, c);
    }
    u64 elapsed = time_us_64() - start;

    printf("Drawing %d triangles took %lldus (avg. %fus/iter).\n", num_iter, elapsed, (f32)elapsed / num_iter);
}