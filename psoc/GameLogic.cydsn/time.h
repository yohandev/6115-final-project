#ifndef TIME_H
#define TIME_H

#include "num.h"
    
struct Time {
    f32 dt;
    f32 time;
};

extern struct Time Time;
    
void time_init();
void time_step();
    
#endif