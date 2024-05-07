#pragma once

#include "hardware/pio.h"
#include "num.h"

struct LCD {
    struct {
        usize dc;
        usize rst;
        usize mosi;
        usize clk;    
    } pins;

    PIO pio;
    usize sm;
};

void lcd_init(struct LCD* self);
void lcd_put(struct LCD* self, u8* buf);