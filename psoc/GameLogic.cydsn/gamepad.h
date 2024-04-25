#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "utils.h"

struct Gamepad {
    struct {
        u16 x;          // TODO: normalize value
        u16 y;          // TODO: normalize value
        bool sel;       // Pressed down exactly this frame?
    } joystick;
    bool buttons[2];    // Pressed down exactly this frame?
};

extern struct Gamepad Gamepad;

void gamepad_init();
void gamepad_poll();

#endif