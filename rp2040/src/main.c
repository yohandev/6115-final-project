#include <stdio.h>
#include <math.h>

#include "pico/stdlib.h"
// #include "pico/stdio_rtt.h"
#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "hardware/interp.h"

#include "st7789_lcd.pio.h"
#include "raspberry_256x256_rgb565.h"

#include "st7789.h"

struct LCD display = {
    .pins = {
        .clk = 1,
        .mosi = 2,
        .dc = 4,
        .rst = 3,
    },
    .pio = pio0,
    .sm = 0,
    .dma = -1,
};

// Tested with the parts that have the height of 240 and 320
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160
#define IMAGE_SIZE 256
#define LOG_IMAGE_SIZE 8

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

u8 __attribute__((aligned(4))) sbuf[SCREEN_WIDTH * SCREEN_HEIGHT * 2];

int main() {
    // stdio_rtt_init();
    stdio_init_all();

    lcd_init(&display);

    // Other SDKs: static image on screen, lame, boring
    // Raspberry Pi Pico SDK: spinning image on screen, bold, exciting

    // Lane 0 will be u coords (bits 8:1 of addr offset), lane 1 will be v
    // coords (bits 16:9 of addr offset), and we'll represent coords with
    // 16.16 fixed point. ACCUM0,1 will contain current coord, BASE0/1 will
    // contain increment vector, and BASE2 will contain image base pointer
#define UNIT_LSB 16
    interp_config lane0_cfg = interp_default_config();
    interp_config_set_shift(&lane0_cfg, UNIT_LSB - 1); // -1 because 2 bytes per pixel
    interp_config_set_mask(&lane0_cfg, 1, 1 + (LOG_IMAGE_SIZE - 1));
    interp_config_set_add_raw(&lane0_cfg, true); // Add full accumulator to base with each POP
    interp_config lane1_cfg = interp_default_config();
    interp_config_set_shift(&lane1_cfg, UNIT_LSB - (1 + LOG_IMAGE_SIZE));
    interp_config_set_mask(&lane1_cfg, 1 + LOG_IMAGE_SIZE, 1 + (2 * LOG_IMAGE_SIZE - 1));
    interp_config_set_add_raw(&lane1_cfg, true);

    interp_set_config(interp0, 0, &lane0_cfg);
    interp_set_config(interp0, 1, &lane1_cfg);
    interp0->base[2] = (uint32_t) raspberry_256x256;

    float theta = 0.f;
    float theta_max = 2.f * (float) M_PI;
    while (1) {
        theta += 0.02f;
        if (theta > theta_max)
            theta -= theta_max;
        int32_t rotate[4] = {
                (int32_t) (cosf(theta) * (1 << UNIT_LSB)), (int32_t) (-sinf(theta) * (1 << UNIT_LSB)),
                (int32_t) (sinf(theta) * (1 << UNIT_LSB)), (int32_t) (cosf(theta) * (1 << UNIT_LSB))
        };
        interp0->base[0] = rotate[0];
        interp0->base[1] = rotate[2];

        usize i = 0;
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            interp0->accum[0] = rotate[1] * y;
            interp0->accum[1] = rotate[3] * y;
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                uint16_t colour = *(uint16_t *) (interp0->pop[2]);

                sbuf[i++] = colour >> 8;
                sbuf[i++] = colour & 0xff;
            }
        }
        lcd_put(&display, sbuf);
    }
}