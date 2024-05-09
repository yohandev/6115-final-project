#pragma once

#include "framebuffer.h"

void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2 a, vec2 b, vec2 c);
void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, f32 bound);