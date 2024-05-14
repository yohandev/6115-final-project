#include "psoc_rx.h"
#include "psoc_rx.pio.h"

void psoc_rx_init(struct PsocRx* self) {
    assert(self->pins.mosi == self->pins.sck - 1);

    uint offset = pio_add_program(self->pio, &psoc_rx_program);
    psoc_rx_program_init(self->pio, self->sm, offset, self->pins.mosi);
}

void psoc_rx_pull() {

}