/*******************************************************************************
* File Name: Joystick_X_theACLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Joystick_X_theACLK_H)
#define CY_CLOCK_Joystick_X_theACLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Joystick_X_theACLK_Start(void) ;
void Joystick_X_theACLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Joystick_X_theACLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Joystick_X_theACLK_StandbyPower(uint8 state) ;
void Joystick_X_theACLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Joystick_X_theACLK_GetDividerRegister(void) ;
void Joystick_X_theACLK_SetModeRegister(uint8 modeBitMask) ;
void Joystick_X_theACLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 Joystick_X_theACLK_GetModeRegister(void) ;
void Joystick_X_theACLK_SetSourceRegister(uint8 clkSource) ;
uint8 Joystick_X_theACLK_GetSourceRegister(void) ;
#if defined(Joystick_X_theACLK__CFG3)
void Joystick_X_theACLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 Joystick_X_theACLK_GetPhaseRegister(void) ;
#endif /* defined(Joystick_X_theACLK__CFG3) */

#define Joystick_X_theACLK_Enable()                       Joystick_X_theACLK_Start()
#define Joystick_X_theACLK_Disable()                      Joystick_X_theACLK_Stop()
#define Joystick_X_theACLK_SetDivider(clkDivider)         Joystick_X_theACLK_SetDividerRegister(clkDivider, 1u)
#define Joystick_X_theACLK_SetDividerValue(clkDivider)    Joystick_X_theACLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define Joystick_X_theACLK_SetMode(clkMode)               Joystick_X_theACLK_SetModeRegister(clkMode)
#define Joystick_X_theACLK_SetSource(clkSource)           Joystick_X_theACLK_SetSourceRegister(clkSource)
#if defined(Joystick_X_theACLK__CFG3)
#define Joystick_X_theACLK_SetPhase(clkPhase)             Joystick_X_theACLK_SetPhaseRegister(clkPhase)
#define Joystick_X_theACLK_SetPhaseValue(clkPhase)        Joystick_X_theACLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Joystick_X_theACLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Joystick_X_theACLK_CLKEN              (* (reg8 *) Joystick_X_theACLK__PM_ACT_CFG)
#define Joystick_X_theACLK_CLKEN_PTR          ((reg8 *) Joystick_X_theACLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Joystick_X_theACLK_CLKSTBY            (* (reg8 *) Joystick_X_theACLK__PM_STBY_CFG)
#define Joystick_X_theACLK_CLKSTBY_PTR        ((reg8 *) Joystick_X_theACLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Joystick_X_theACLK_DIV_LSB            (* (reg8 *) Joystick_X_theACLK__CFG0)
#define Joystick_X_theACLK_DIV_LSB_PTR        ((reg8 *) Joystick_X_theACLK__CFG0)
#define Joystick_X_theACLK_DIV_PTR            ((reg16 *) Joystick_X_theACLK__CFG0)

/* Clock MSB divider configuration register. */
#define Joystick_X_theACLK_DIV_MSB            (* (reg8 *) Joystick_X_theACLK__CFG1)
#define Joystick_X_theACLK_DIV_MSB_PTR        ((reg8 *) Joystick_X_theACLK__CFG1)

/* Mode and source configuration register */
#define Joystick_X_theACLK_MOD_SRC            (* (reg8 *) Joystick_X_theACLK__CFG2)
#define Joystick_X_theACLK_MOD_SRC_PTR        ((reg8 *) Joystick_X_theACLK__CFG2)

#if defined(Joystick_X_theACLK__CFG3)
/* Analog clock phase configuration register */
#define Joystick_X_theACLK_PHASE              (* (reg8 *) Joystick_X_theACLK__CFG3)
#define Joystick_X_theACLK_PHASE_PTR          ((reg8 *) Joystick_X_theACLK__CFG3)
#endif /* defined(Joystick_X_theACLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Joystick_X_theACLK_CLKEN_MASK         Joystick_X_theACLK__PM_ACT_MSK
#define Joystick_X_theACLK_CLKSTBY_MASK       Joystick_X_theACLK__PM_STBY_MSK

/* CFG2 field masks */
#define Joystick_X_theACLK_SRC_SEL_MSK        Joystick_X_theACLK__CFG2_SRC_SEL_MASK
#define Joystick_X_theACLK_MODE_MASK          (~(Joystick_X_theACLK_SRC_SEL_MSK))

#if defined(Joystick_X_theACLK__CFG3)
/* CFG3 phase mask */
#define Joystick_X_theACLK_PHASE_MASK         Joystick_X_theACLK__CFG3_PHASE_DLY_MASK
#endif /* defined(Joystick_X_theACLK__CFG3) */

#endif /* CY_CLOCK_Joystick_X_theACLK_H */


/* [] END OF FILE */
