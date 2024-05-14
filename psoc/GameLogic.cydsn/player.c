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

const f32 YAW_BIAS = 2.25;
const f32 PITCH_BIAS = 2.5;
const f32 ROLL_BIAS = 1.5;
const f32 ACCELERATION = 2.0;
const f32 FORWARD_SPEED = 25;

const f32 CAMERA_DIST = 30.0;
const f32 CAMERA_ACCEL = 2.5;

void player_init() {
    // pass
}

void player_step() {
    f32 yaw = YAW_BIAS * Gamepad.joystick.x;
    f32 pitch = PITCH_BIAS * Gamepad.joystick.y;
    f32 roll = ROLL_BIAS * Gamepad.joystick.x;
    f32 thrust = FORWARD_SPEED;
    
    // Pitch input is relative to aircraft's x axis (without roll)
    //vec3 pitch_axis = vec3_normalized(quat_left(&Player.yaw_pitch));
    //quat pitch_rot = quat_angle_axis(pitch * Time.dt, pitch_axis);
    // Yaw input is absolute about world's y (vertical) axis
    //quat yaw_rot = quat_angle_axis(yaw * Time.dt, (vec3){ .x=0, .y=1, .z=0 });
    // Roll is an implicit input, self-corrects back to 0 when joystick input goes to 0
    //quat roll_rot = quat_angle_axis(roll, (vec3){ .x=0, .y=0, .z=1 });

    //quat yaw_pitch = quat_mul(&pitch_rot, &yaw_rot);
    
    // Integrate
    // Player.yaw_pitch = quat_mul(&Player.yaw_pitch, &yaw_pitch);
    //Player.target_rot = quat_mul(&Player.yaw_pitch, &roll_rot);
    
    // Actual plane's pose is smoothly interpolated
    //Player.rot = quat_slerp(&Player.rot, &Player.target_rot, ACCELERATION * Time.dt);
    // Player.pos = vec3_add(Player.pos, vec3_scale(quat_forward(&Player.rot), thrust * Time.dt));

    // Another control scheme:
    quat input = quat_from_euler(yaw * Time.dt, pitch * Time.dt, 0.0);
    quat bank = quat_from_euler(0.0, 0.0, -roll);
    
    // Explicit user input (NOT self correcting)
    Player.yaw_pitch = quat_mul(&Player.yaw_pitch, &input);
    
    // Implicit user input (roll snaps back to 0 when not banking)
    Player.target_rot = quat_mul(&Player.yaw_pitch, &bank);
    
    // Integrate
    Player.rot = quat_slerp(&Player.rot, &Player.target_rot, ACCELERATION * Time.dt);
    Player.pos = vec3_add(Player.pos, vec3_scale(quat_forward(&Player.rot), thrust * Time.dt));

    // Camera "lags" behind the spaceship
    vec3 camera_target_pos_rel = vec3_scale(quat_forward(&Player.rot), -CAMERA_DIST);
    vec3 camera_target_pos = vec3_add(camera_target_pos_rel, Player.pos);
    
    Player.camera_pos = vec3_lerp(Player.camera_pos, camera_target_pos, CAMERA_ACCEL * Time.dt);
    Player.camera_rot = quat_slerp(&Player.camera_rot, &Player.rot, CAMERA_ACCEL * Time.dt);
}