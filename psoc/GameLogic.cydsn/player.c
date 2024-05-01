#include "player.h"
#include "gamepad.h"
#include "time.h"

struct Player Player = {
    .pos = { .x=-82, .y=-47, .z=49 },
    .rot = {1, 0, 0, 0} //{ .w=0.585, .x=0.216, .y=0.079, .z=0.778 },
};

const f32 YAW_SPEED = 1.25;
const f32 PITCH_SPEED = 1.75;
const f32 FORWARD_SPEED = 15;

void player_init() {
    // pass
}

void player_step() {
    f32 yaw = YAW_SPEED * Gamepad.joystick.x * Time.dt;
    f32 pitch = PITCH_SPEED * Gamepad.joystick.y * Time.dt;
    f32 thrust = -FORWARD_SPEED * Time.dt;
    quat input = quat_from_euler(yaw, pitch, 0.0);

    Player.rot = quat_mul(&Player.rot, &input);
    Player.pos = vec3_add(Player.pos, vec3_scale(quat_forward(&Player.rot), thrust));
}