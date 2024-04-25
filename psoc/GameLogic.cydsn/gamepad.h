struct Gamepad {
    struct {
        int x;          // TODO: normalize value
        int y;          // TODO: normalize value
        int sel;        // Pressed down exactly this frame?
    } joystick;
    int buttons[2];     // Pressed down exactly this frame?
};

extern struct Gamepad Gamepad;

void gamepad_init();
void gamepad_poll();