#include "time.h"

#include <project.h>

struct Time Time = {
    .dt = 0.0,
    .time = 0.0,
};

void time_init() {
    GameTimeClock_Start();
    GameTimeReg_Read();
}

void time_step() {
    static u8 last_ticks = 0;
    
    u8 ticks = GameTimeReg_Read();
    u8 dtick = ticks - last_ticks;
    
    last_ticks = ticks;
    
    Time.dt = (1/480.0) * dtick;
    Time.time += Time.dt;
}