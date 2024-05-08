#pragma once

#include "num.h"

#define FRAME_BUFFER_WIDTH 160
#define FRAME_BUFFER_HEIGHT 128

struct Framebuffer {
    rgb pixels[FRAME_BUFFER_WIDTH * FRAME_BUFFER_HEIGHT];
};

#define framebuffer_get(f, x, y) (f).pixels[(x) + ((y) * FRAME_BUFFER_WIDTH)]

inline struct Framebuffer* framebuffer_get_current();   // The one visible/being pushed to the display
inline struct Framebuffer* framebuffer_get_offscreen(); // The one being overwritten for frame N+1
void framebuffer_swap();