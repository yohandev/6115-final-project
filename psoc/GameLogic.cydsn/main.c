#include <project.h>
#include <stdio.h>

#include "gamepad.h"

char sbuf[256];

int main() {
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_KitProg_Start();
    
    gamepad_init();
    
    while (1) {
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
        
        CyDelay(50);
    }
}