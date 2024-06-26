#include <project.h>
#include <stdio.h>

#include "gamepad.h"
#include "player.h"
#include "world.h"
#include "time.h"
#include "gpu.h"
#include "assets/assets.h"

int main() {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_KitProg_Start();
    gamepad_init();
    world_init();
    player_init();

    gpu_init();
    gpu_upload_mesh(ASSET_STAR_DESTROYER_MESH_ID, &ASSET_STAR_DESTROYER_MESH);
    gpu_upload_mesh(ASSET_ASTEROID_MESH_ID, &ASSET_ASTEROID_MESH);
    gpu_upload_mesh(ASSET_XWING_MESH_ID, &ASSET_XWING_MESH);
    
    time_init();
    
    // == Game loop
    while (1) {
        // Throttle since we're not doing much
        CyDelay(10);
        
        // Time
        time_step();

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
        world_step();
        player_step();

        // Render
        while (!gpu_is_ready()) {}  // Stall if GPU is still processing last frame

        gpu_swap_buffer();          // Send last rendered frame (N-1) to the display, swap to unused buffer (N-2)
        gpu_clear_buffer();         // Clear the buffer to black (TODO: skybox would be cool)

        gpu_set_camera(Player.camera_pos, Player.camera_rot);
        gpu_draw_instanced(ASSET_STAR_DESTROYER_MESH_ID, 1, &World.star_destroyer.pos, &World.star_destroyer.rot);
        // gpu_draw_instanced_scale(ASSET_ASTEROID_MESH_ID, WORLD_ASTEROIDS_POOL_LEN, World.asteroids.pos, World.asteroids.rot, World.asteroids.scale);
        gpu_draw_instanced_quat(ASSET_XWING_MESH_ID, 1, &Player.pos, &Player.rot);
    }
}