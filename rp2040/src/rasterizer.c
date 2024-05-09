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
// here: https://fgiesen.wordpress.com/2013/02/08/triangle-rasterization-in-practice/
// 
// The intution for choosing this algorithm is that since the pixel buffer is so small,
// loop over an AABB might actually be faster than the overhead of e.g. bresenham algorithms
// where no pixels are "wasted" but has a longer initialization time. Moreover, testing for
// a point inside of a triangle (in a loop) can be further optimized to just a handful of
// addition and shifts which the RP2040 accumulator can perform in one cycle. Of course,
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

    // Draw
    for (fixed y = min_y; y <= max_y; y += FIXED_ONE) {
        for (fixed x = min_x; x <= max_x; x += FIXED_ONE) {
            fixed w0 = barycentric_coord(bx, by, cx, by, x, y);
            fixed w1 = barycentric_coord(cx, cy, ax, ay, x, y);
            fixed w2 = barycentric_coord(ax, ay, bx, by, x, y);

            // If p is on or inside all edges, render pixel.
            if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                framebuffer_get(sbuf, fixed_to_i32(x), fixed_to_i32(y)) = (rgb){ 0b11111000000 };
            }
        }
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