#include "player.h"
#include "gamepad.h"
#include "time.h"

struct Player Player = {
    .pos = { .x=-82, .y=-47, .z=49 },
    .rot = {1, 0, 0, 0},
    
    .target_rot = {1, 0, 0, 0},
    .yaw_pitch = {1, 0, 0, 0},
    
    .camera_pos = {0, 0, 0},
    .camera_rot = {1, 0, 0, 0},
};

const f32 YAW_BIAS = 1.75;
const f32 PITCH_BIAS = 2.25;
const f32 ROLL_BIAS = 1.25;
const f32 ACCELERATION = 1.5;
const f32 FORWARD_SPEED = 25;

void player_init() {
    // pass
}

void player_step() {
    f32 yaw = YAW_BIAS * Gamepad.joystick.x;
    f32 pitch = PITCH_BIAS * Gamepad.joystick.y;
    f32 roll = ROLL_BIAS * Gamepad.joystick.x;
    f32 thrust = -FORWARD_SPEED * Time.dt;
    
    quat input = quat_from_euler(yaw * Time.dt, pitch * Time.dt, 0.0);
    quat bank = quat_from_euler(0.0, 0.0, roll);
    
    // Explicit user input (NOT self correcting)
    Player.yaw_pitch = quat_mul(&Player.yaw_pitch, &input);
    
    // Implicit user input (roll snaps back to 0 when not banking)
    Player.target_rot = quat_mul(&Player.yaw_pitch, &bank);
    
    // Integrate
    Player.rot = quat_slerp(&Player.rot, &Player.target_rot, ACCELERATION * Time.dt);
    Player.pos = vec3_add(Player.pos, vec3_scale(quat_forward(&Player.rot), thrust));
}