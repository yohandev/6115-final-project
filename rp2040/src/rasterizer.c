#include "rasterizer.h"
#include "framebuffer.h"
#include "num.h"

inline static f32 barycentric_coord(vec2 a, vec2 b, vec2 c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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
    // AABB of the triangle
    f32 min_x = min(min(a.x, b.x), c.x);
    f32 min_y = min(min(a.y, b.y), c.y);
    f32 max_x = max(max(a.x, b.x), c.x);
    f32 max_y = max(max(a.y, b.y), c.y);
    
    // Contain within the framebuffer
    min_x = max(min_x, 0);
    min_y = max(min_y, 0);
    max_x = min(max_x, FRAME_BUFFER_WIDTH - 1e-4);
    max_y = min(max_y, FRAME_BUFFER_HEIGHT - 1e-4);

    // Draw
    vec2 p;
    for (p.y = min_y; p.y < max_y; p.y += 1.0) {
        for (p.x = min_x; p.x < max_x; p.x += 1.0) {
            int w0 = barycentric_coord(b, c, p);
            int w1 = barycentric_coord(c, a, p);
            int w2 = barycentric_coord(a, b, p);

            // If p is on or inside all edges, render pixel.
            if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                framebuffer_get(sbuf, (usize)p.x, (usize)p.y) = (rgb){ 0b11111 };
            }
        }
    }
}