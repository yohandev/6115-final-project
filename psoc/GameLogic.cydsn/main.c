#include <project.h>
#include <stdio.h>

#include "gamepad.h"
#include "asteroids.h"
#include "gpu.h"
#include "assets/assets.h"

int main() {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_KitProg_Start();
    gamepad_init();
    asteroids_init();

    gpu_init();
    gpu_upload_mesh(0, &ASSET_STAR_DESTROYER_MESH);
    
    // == Game loop
    while (1) {
        // Throttle since we're not doing much
        CyDelay(10);

        // Input
        gamepad_poll();
        
        if (Gamepad.joystick.sel) {
            UART_KitProg_PutString("Joystick!\n");
        }
        if (Gamepad.buttons[0]) {
            UART_KitProg_PutString("Action #0!\n");
        }
        if (Gamepad.buttons[1]) {
            UART_KitProg_PutString("Action #1!\n");
        }

        // Controllers, Physics Resolver
        asteroids_step();

        // Render
        while (!gpu_is_ready()) {}  // Stall if GPU is still processing last frame

        gpu_swap_buffer();          // Send last rendered frame (N-1) to the display, swap to unused buffer (N-2)
        gpu_clear_buffer();         // Clear the buffer to black (TODO: skybox would be cool)
    }
}