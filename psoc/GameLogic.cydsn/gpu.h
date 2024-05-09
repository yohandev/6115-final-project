#ifndef GPU_H
#define GPU_H

#include "common/num.h"
#include "common/mesh.h"

// System operations
void gpu_init();
bool gpu_is_ready();
void gpu_upload_mesh(usize id, const struct Mesh* mesh);

// Framebuffer/swapchain operations
void gpu_clear_buffer();
void gpu_swap_buffer();

// Rendering operations
void gpu_set_camera(vec3f pos, quat rot);
void gpu_draw_instanced(usize id, usize len, vec3f* pos, vec3f* rot);
void gpu_draw_instanced_quat(usize id, usize len, vec3f* pos, quat* rot);
void gpu_draw_instanced_scale(usize id, usize len, vec3f* pos, vec3f* rot, f32* scale);

#endif