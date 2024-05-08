// Adapted from:
// https://github.com/raspberrypi/pico-examples/tree/master/pio/st7789_lcd
#include "pico/stdlib.h"
#include "hardware/dma.h"

#include "st7789.h"
#include "st7789.pio.h"

#define SERIAL_CLK_DIV 1.f
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160

// Format: cmd length (including cmd byte), post delay in units of 5 ms, then cmd payload
// Note the delays have been shortened a little
static const u8 st7789_init_seq[] = {
    1, 20, 0x01,                        // Software reset
    1, 10, 0x11,                        // Exit sleep mode
    2, 2, 0x3a, 0x55,                   // Set colour mode to 16 bit
    2, 0, 0x36, 0x00,                   // Set MADCTL: row then column, refresh is bottom to top ????
    5, 0, 0x2a, 0x00, 0x00, SCREEN_WIDTH >> 8, SCREEN_WIDTH & 0xff,   // CASET: column addresses
    5, 0, 0x2b, 0x00, 0x00, SCREEN_HEIGHT >> 8, SCREEN_HEIGHT & 0xff, // RASET: row addresses
    1, 2, 0x21,                         // Inversion on, then 10 ms delay (supposedly a hack?)
    1, 2, 0x13,                         // Normal display on, then 10 ms delay
    1, 2, 0x20,
    1, 2, 0x29,                         // Main screen turn on, then wait 500 ms
    0                                   // Terminate list
};

static inline void lcd_set_dc(struct LCD* self, bool dc) {
    sleep_us(1);
    gpio_put_masked((1u << self->pins.dc), !!dc << self->pins.dc);
    sleep_us(1);
}

static inline void lcd_write_cmd(struct LCD* self, const u8 *cmd, usize count) {
    lcd_pio_wait_idle(self->pio, self->sm);
    lcd_set_dc(self, 0);
    lcd_pio_put(self->pio, self->sm, *cmd++);
    if (count >= 2) {
        lcd_pio_wait_idle(self->pio, self->sm);
        lcd_set_dc(self, 1);
        for (size_t i = 0; i < count - 1; ++i)
            lcd_pio_put(self->pio, self->sm, *cmd++);
    }
    lcd_pio_wait_idle(self->pio, self->sm);
    lcd_set_dc(self, 1);
}

static inline void lcd_start_pixels(struct LCD* self) {
    u8 cmd = 0x2c; // RAMWR
    lcd_write_cmd(self, &cmd, 1);
    lcd_set_dc(self, 1);
}

void lcd_init(struct LCD* self) {
    usize offset = pio_add_program(self->pio, &st7789_lcd_program);
    lcd_pio_program_init(self->pio, self->sm, offset, self->pins.mosi, self->pins.clk, SERIAL_CLK_DIV);

    gpio_init(self->pins.dc);
    gpio_init(self->pins.rst);
    gpio_set_dir(self->pins.dc, GPIO_OUT);
    gpio_set_dir(self->pins.rst, GPIO_OUT);

    if (self->dma < 0) {
        self->dma = dma_claim_unused_channel(true);
    }
    dma_channel_config cfg = dma_channel_get_default_config(self->dma);
    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_8);
    channel_config_set_read_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_PIO0_TX0);
    dma_channel_configure(
        self->dma,
        &cfg,
        self->pio == pio0 ? &pio0_hw->txf[0] : &pio1_hw->txf[0],    // Write address
        NULL,                                                       // Don't provide a read address yet
        (SCREEN_WIDTH * SCREEN_HEIGHT) << 1,                        // Number of writes
        false                                                       // Don't start yet
    );

    gpio_put(self->pins.rst, 1);

    const u8 *cmd = st7789_init_seq;
    while (*cmd) {
        lcd_write_cmd(self, cmd + 2, *cmd);
        sleep_ms(*(cmd + 1) * 5);
        cmd += *cmd + 2;
    }
}

void lcd_put(struct LCD* self, const u8* buf) {
    dma_channel_wait_for_finish_blocking(self->dma);
    lcd_start_pixels(self);
    dma_channel_set_read_addr(self->dma, buf, true);
}