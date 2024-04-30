#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "num.h"

struct Gamepad {
    struct {
        f32 x;          // TODO: fixed
        f32 y;          // TODO: fixed
        bool sel;       // Pressed down exactly this frame?
    } joystick;
    bool buttons[2];    // Pressed down exactly this frame?
};

extern struct Gamepad Gamepad;

void gamepad_init();
void gamepad_poll();

#endif