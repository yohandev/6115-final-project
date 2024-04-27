#include <project.h>

#include "gpu.h"

#define EMULATED_GPU

#ifdef EMULATED_GPU
/**
 * Implementation running graphics processing on a host laptop via serial
*/

enum PayloadType {
    PACKET_OVER = 0x80,     // Start at an invalid ASCII character so printing can happen too
    UPLOAD_MESH,
    CLEAR_BUFFER,
    SWAP_BUFFER,
    SET_CAMERA,
    DRAW_INSTANCED,
};

void gpu_init() {
    UART_KitProg_Start();
}

bool gpu_is_ready() {
    return true;
}

void gpu_upload_mesh(usize id, const struct Mesh* mesh) {
    // Header
    UART_KitProg_PutChar(UPLOAD_MESH);
    // Mesh identifier
    UART_KitProg_PutArray(&id, sizeof(usize));
    // Vertices
    UART_KitProg_PutArray(&mesh->num_vertices, sizeof(usize));
    UART_KitProg_PutArray(mesh->vertices, mesh->num_vertices * 3 * sizeof(u16));
    // Indices
    UART_KitProg_PutArray(&mesh->num_faces, sizeof(usize));
    UART_KitProg_PutArray(mesh->indices, mesh->num_faces * 3 * sizeof(u16));
    // Color
    UART_KitProg_PutArray(&mesh->num_colors, sizeof(usize));
    UART_KitProg_PutArray(mesh->colors, mesh->num_colors * sizeof(struct ColorRange));
    // Footer
    UART_KitProg_PutChar(PACKET_OVER);
}

void gpu_clear_buffer() {
    // Header
    UART_KitProg_PutChar(CLEAR_BUFFER);
    // Footer
    UART_KitProg_PutChar(PACKET_OVER);
}

void gpu_swap_buffer() {
    // Header
    UART_KitProg_PutChar(SWAP_BUFFER);
    // Footer
    UART_KitProg_PutChar(PACKET_OVER);
}

void gpu_set_camera(vec3 pos, vec3 rot) {
    // Header
    UART_KitProg_PutChar(SET_CAMERA);
    // Payload
    UART_KitProg_PutArray(&pos, sizeof(vec3));
    UART_KitProg_PutArray(&rot, sizeof(vec3));
    // Footer
    UART_KitProg_PutChar(PACKET_OVER);
}

void gpu_draw_instanced(usize id, usize len, vec3* pos, vec3* rot) {
    // Header
    UART_KitProg_PutChar(SET_CAMERA);
    // Mesh identifier
    UART_KitProg_PutArray(&id, sizeof(usize));
    // Amount of instances
    UART_KitProg_PutArray(&len, sizeof(usize));
    // Transformations
    UART_KitProg_PutArray(pos, len * sizeof(vec3));
    UART_KitProg_PutArray(rot, len * sizeof(vec3));
    // Footer
    UART_KitProg_PutChar(PACKET_OVER);
}

#else
// Implementation running on the RP2040
#error RP2040 GPU not yet implemented!
#endif