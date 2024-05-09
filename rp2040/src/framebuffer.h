#pragma once

#include "num.h"

#define FRAME_BUFFER_WIDTH 128
#define FRAME_BUFFER_HEIGHT 160

struct Framebuffer {
    rgb pixels[FRAME_BUFFER_WIDTH * FRAME_BUFFER_HEIGHT];
};

#define framebuffer_idx(x, y) ((x) + ((y) * FRAME_BUFFER_WIDTH))
#define framebuffer_get(f, x, y) (f)->pixels[framebuffer_idx((x), (y))]

struct Framebuffer* framebuffer_get_current();   // The one visible/being pushed to the display
struct Framebuffer* framebuffer_get_offscreen(); // The one being overwritten for frame N+1
void framebuffer_swap();