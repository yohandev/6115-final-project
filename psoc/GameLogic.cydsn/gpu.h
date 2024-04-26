#ifndef GPU_H
#define GPU_H

#include "num.h"

// System operations
void gpu_init();
bool gpu_is_ready();
void gpu_upload_mesh(usize id, void* mesh);

// Framebuffer/swapchain operations
void gpu_clear_buffer();
void gpu_swap_buffer();

// Rendering operations
void gpu_set_camera(vec3 pos, vec3 rot);
void gpu_draw_instanced(usize id, usize len, vec3* pos, vec3* rot);

#endif