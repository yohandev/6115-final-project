#include <project.h>
#include <stdio.h>

char sbuf[256];

int main() {
    CyGlobalIntEnable; /* Enable global interrupts. */

    Joystick_X_Start();
    Joystick_X_StartConvert();
    
    UART_KitProg_Start();
    
    while (1) {
        if (Joystick_X_IsEndConversion(Joystick_X_WAIT_FOR_RESULT)) {
            uint16 joyx = Joystick_X_GetResult16();
            
            snprintf(sbuf, sizeof(sbuf), "Joystick: %d", joyx);
            UART_KitProg_PutString(sbuf);
            
            CyDelay(50);
        }
    }
}