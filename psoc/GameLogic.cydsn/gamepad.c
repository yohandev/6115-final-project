#include <project.h>

#include "gamepad.h"

struct Gamepad Gamepad = {
    .joystick = {
        .x = 0,
        .y = 0,
        .sel = 0,
    },
    .buttons = {0, 0},
};

// Latches {action0, action1, joystick}
static int buttons[3] = {0, 0, 0};

CY_ISR(Joystick_Btn_Handler) {
    buttons[2] = 1;
    Joystick_Btn_ClearPending();
}

CY_ISR(Action0_Btn_Handler) {
    buttons[0] = 1;
    Action0_Btn_ClearPending();
}

CY_ISR(Action1_Btn_Handler) {
    buttons[1] = 1;
    Action1_Btn_ClearPending();
}

void gamepad_init() {
    Joystick_X_Start();
    Joystick_X_StartConvert();
    Joystick_Y_Start();
    Joystick_Y_StartConvert();
    
    DebounceClock_Start();
    Joystick_Btn_StartEx(Joystick_Btn_Handler);
    Action0_Btn_StartEx(Action0_Btn_Handler);
    Action1_Btn_StartEx(Action1_Btn_Handler);
}

void gamepad_poll() {
    // Update gamepad structure
    Gamepad.joystick.sel = buttons[2];
    Gamepad.buttons[0] = buttons[0];
    Gamepad.buttons[1] = buttons[1];
    
    // Clear button latches
    buttons[0] = 0;
    buttons[1] = 0;
    buttons[2] = 0;
    
    // Joystick potentiometers
    if (Joystick_X_IsEndConversion(Joystick_X_WAIT_FOR_RESULT)) {
        Gamepad.joystick.x = Joystick_X_GetResult16();
    }
    if (Joystick_Y_IsEndConversion(Joystick_Y_WAIT_FOR_RESULT)) {
        Gamepad.joystick.y = Joystick_Y_GetResult16();
    }
}