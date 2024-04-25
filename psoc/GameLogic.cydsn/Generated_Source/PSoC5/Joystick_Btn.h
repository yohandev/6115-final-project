/*******************************************************************************
* File Name: Joystick_Btn.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Joystick_Btn_H)
#define CY_ISR_Joystick_Btn_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Joystick_Btn_Start(void);
void Joystick_Btn_StartEx(cyisraddress address);
void Joystick_Btn_Stop(void);

CY_ISR_PROTO(Joystick_Btn_Interrupt);

void Joystick_Btn_SetVector(cyisraddress address);
cyisraddress Joystick_Btn_GetVector(void);

void Joystick_Btn_SetPriority(uint8 priority);
uint8 Joystick_Btn_GetPriority(void);

void Joystick_Btn_Enable(void);
uint8 Joystick_Btn_GetState(void);
void Joystick_Btn_Disable(void);

void Joystick_Btn_SetPending(void);
void Joystick_Btn_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Joystick_Btn ISR. */
#define Joystick_Btn_INTC_VECTOR            ((reg32 *) Joystick_Btn__INTC_VECT)

/* Address of the Joystick_Btn ISR priority. */
#define Joystick_Btn_INTC_PRIOR             ((reg8 *) Joystick_Btn__INTC_PRIOR_REG)

/* Priority of the Joystick_Btn interrupt. */
#define Joystick_Btn_INTC_PRIOR_NUMBER      Joystick_Btn__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Joystick_Btn interrupt. */
#define Joystick_Btn_INTC_SET_EN            ((reg32 *) Joystick_Btn__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Joystick_Btn interrupt. */
#define Joystick_Btn_INTC_CLR_EN            ((reg32 *) Joystick_Btn__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Joystick_Btn interrupt state to pending. */
#define Joystick_Btn_INTC_SET_PD            ((reg32 *) Joystick_Btn__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Joystick_Btn interrupt. */
#define Joystick_Btn_INTC_CLR_PD            ((reg32 *) Joystick_Btn__INTC_CLR_PD_REG)


#endif /* CY_ISR_Joystick_Btn_H */


/* [] END OF FILE */
