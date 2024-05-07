#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_rtt.h"

int main() {
    stdio_rtt_init();
    printf("Hello, world!\n");
    return 0;
}