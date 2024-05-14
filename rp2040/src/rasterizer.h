#pragma once

#include "framebuffer.h"
#include "mesh.h"

#define RASTERIZER_VERTEX_CACHE_LEN 64
#define RASTERIZER_NEAR_CLIP 0.1

static const vec3 SUN_LIGHT = {
    // fixed(norm([3, -2, -2]))
    .x = 47684,
    .y = -31789,
    .z = -31789,
};

void rasterizer_draw_triangle(struct Framebuffer* sbuf, vec2 a, vec2 b, vec2 c, rgb col);
void rasterizer_triangle_bench(struct Framebuffer* sbuf, usize num_iter, usize log2scale);

void rasterizer_draw_mesh(struct Framebuffer* sbuf, const struct Mesh* mesh, const mat4s* mvp);