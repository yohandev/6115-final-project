#pragma once

#include "framebuffer.h"
#include "mesh.h"

#define RASTERIZER_VERTEX_CACHE_LEN 64

void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2 a, vec2 b, vec2 c);
void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, usize log2scale);

void rasterizer_draw_mesh(const struct Mesh* mesh, struct Framebuffer* sbuf);