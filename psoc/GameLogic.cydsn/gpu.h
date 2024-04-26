#ifndef GPU_H
#define GPU_H

#include "num.h"

// Meshes overview:
// Vertices (max of 65536) are stored in 8.8 fixed point (half of normal)
// Indices are therefore 16-bit integers
// No textures, but ranges of triangles (its indices) can take on a different color
//
// Consideration must be made to maximize this representation, e.g. the biggest mesh
// in the game should ideally have vertices almost maxing out the 8.8 fixed point. Also,
// because there is no per-vertex color, meshes with lots of similar color are preferred.
struct Mesh {
    u16* vertices;
    u16* indices;
    struct ColorRange {
        rgb rgb;
        u16 start;          // Starting index where this color takes effect
    }* colors;

    usize vertices_len;
    usize indices_len;
    usize colors_len;
};

// System operations
void gpu_init();
bool gpu_is_ready();
void gpu_upload_mesh(usize id, struct Mesh* mesh);

// Framebuffer/swapchain operations
void gpu_clear_buffer();
void gpu_swap_buffer();

// Rendering operations
void gpu_set_camera(vec3 pos, vec3 rot);
void gpu_draw_instanced(usize id, usize len, vec3* pos, vec3* rot);

#endif