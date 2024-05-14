#ifndef PLAYER_H
#define PLAYER_H

#include "common/num.h"

struct Player {
    vec3f pos;
    quat rot;
    
    quat target_rot;
    quat yaw_pitch;
    
    vec3f camera_pos;
    quat camera_rot;
};

extern struct Player Player;

void player_init();
void player_step();

#endif