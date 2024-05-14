#pragma once

#include "hardware/pio.h"
#include "num.h"

struct PsocRx {
    struct {
        usize sck;
        usize mosi;
    } pins;

    PIO pio;
    usize sm;
};

void psoc_rx_init(struct PsocRx* self);
void psoc_rx_pull();