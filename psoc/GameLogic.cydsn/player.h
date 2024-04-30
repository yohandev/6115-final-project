#ifndef PLAYER_H
#define PLAYER_H

#include "num.h"

struct Player {
    vec3 pos;
    quat rot;
};

extern struct Player Player;

void player_init();
void player_step();

#endif