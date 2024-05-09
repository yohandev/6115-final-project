#pragma once

#include "framebuffer.h"

void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2f a, vec2f b, vec2f c);
void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, f32 bound);