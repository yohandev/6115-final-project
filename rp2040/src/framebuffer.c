#include "framebuffer.h"

struct Framebuffer SBUF0 = {};
struct Framebuffer SBUF1 = {};

static struct Framebuffer* CURRENT = &SBUF0;
static struct Framebuffer* OFFSCREEN = &SBUF1;

inline struct Framebuffer* framebuffer_get_current() {
    return CURRENT;
}

inline struct Framebuffer* framebuffer_get_offscreen() {
    return OFFSCREEN;
}

void framebuffer_swap() {
    struct Framebuffer* tmp = CURRENT;
    
    CURRENT = OFFSCREEN;
    OFFSCREEN = tmp;
}