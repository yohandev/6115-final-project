/*******************************************************************************
* File Name: Action1_Btn.h
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
#if !defined(CY_ISR_Action1_Btn_H)
#define CY_ISR_Action1_Btn_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Action1_Btn_Start(void);
void Action1_Btn_StartEx(cyisraddress address);
void Action1_Btn_Stop(void);

CY_ISR_PROTO(Action1_Btn_Interrupt);

void Action1_Btn_SetVector(cyisraddress address);
cyisraddress Action1_Btn_GetVector(void);

void Action1_Btn_SetPriority(uint8 priority);
uint8 Action1_Btn_GetPriority(void);

void Action1_Btn_Enable(void);
uint8 Action1_Btn_GetState(void);
void Action1_Btn_Disable(void);

void Action1_Btn_SetPending(void);
void Action1_Btn_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Action1_Btn ISR. */
#define Action1_Btn_INTC_VECTOR            ((reg32 *) Action1_Btn__INTC_VECT)

/* Address of the Action1_Btn ISR priority. */
#define Action1_Btn_INTC_PRIOR             ((reg8 *) Action1_Btn__INTC_PRIOR_REG)

/* Priority of the Action1_Btn interrupt. */
#define Action1_Btn_INTC_PRIOR_NUMBER      Action1_Btn__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Action1_Btn interrupt. */
#define Action1_Btn_INTC_SET_EN            ((reg32 *) Action1_Btn__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Action1_Btn interrupt. */
#define Action1_Btn_INTC_CLR_EN            ((reg32 *) Action1_Btn__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Action1_Btn interrupt state to pending. */
#define Action1_Btn_INTC_SET_PD            ((reg32 *) Action1_Btn__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Action1_Btn interrupt. */
#define Action1_Btn_INTC_CLR_PD            ((reg32 *) Action1_Btn__INTC_CLR_PD_REG)


#endif /* CY_ISR_Action1_Btn_H */


/* [] END OF FILE */
