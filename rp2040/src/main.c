#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_rtt.h"

#include "num.h"

int main() {
    stdio_rtt_init();

    f32 n = 3.14;
    printf("My favorite number is %f\n", n);

    return 0;
}