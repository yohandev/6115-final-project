#include "player.h"
#include "gamepad.h"

struct Player Player = {
    .pos = { .x=-82, .y=-47, .z=49 },
    .rot = { .w=0.585, .x=0.216, .y=0.079, .z=0.778 },
};

const f32 YAW_SPEED = 1;
const f32 PITCH_SPEED = 0.75;

void player_init() {
    // pass
}

void player_step() {
    f32 yaw = Gamepad.joystick.x;
    f32 pitch = Gamepad.joystick.y;
    quat input = quat_from_euler(yaw, pitch, 0.0);

    Player.rot = quat_mul(&Player.rot, &input);
    Player.pos = vec3_add(Player.pos, quat_forward(&Player.rot));
}