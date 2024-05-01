/*******************************************************************************
* File Name: GameTimeClock.h
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

#if !defined(CY_CLOCK_GameTimeClock_H)
#define CY_CLOCK_GameTimeClock_H

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

void GameTimeClock_Start(void) ;
void GameTimeClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void GameTimeClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void GameTimeClock_StandbyPower(uint8 state) ;
void GameTimeClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 GameTimeClock_GetDividerRegister(void) ;
void GameTimeClock_SetModeRegister(uint8 modeBitMask) ;
void GameTimeClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 GameTimeClock_GetModeRegister(void) ;
void GameTimeClock_SetSourceRegister(uint8 clkSource) ;
uint8 GameTimeClock_GetSourceRegister(void) ;
#if defined(GameTimeClock__CFG3)
void GameTimeClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 GameTimeClock_GetPhaseRegister(void) ;
#endif /* defined(GameTimeClock__CFG3) */

#define GameTimeClock_Enable()                       GameTimeClock_Start()
#define GameTimeClock_Disable()                      GameTimeClock_Stop()
#define GameTimeClock_SetDivider(clkDivider)         GameTimeClock_SetDividerRegister(clkDivider, 1u)
#define GameTimeClock_SetDividerValue(clkDivider)    GameTimeClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define GameTimeClock_SetMode(clkMode)               GameTimeClock_SetModeRegister(clkMode)
#define GameTimeClock_SetSource(clkSource)           GameTimeClock_SetSourceRegister(clkSource)
#if defined(GameTimeClock__CFG3)
#define GameTimeClock_SetPhase(clkPhase)             GameTimeClock_SetPhaseRegister(clkPhase)
#define GameTimeClock_SetPhaseValue(clkPhase)        GameTimeClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(GameTimeClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define GameTimeClock_CLKEN              (* (reg8 *) GameTimeClock__PM_ACT_CFG)
#define GameTimeClock_CLKEN_PTR          ((reg8 *) GameTimeClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define GameTimeClock_CLKSTBY            (* (reg8 *) GameTimeClock__PM_STBY_CFG)
#define GameTimeClock_CLKSTBY_PTR        ((reg8 *) GameTimeClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define GameTimeClock_DIV_LSB            (* (reg8 *) GameTimeClock__CFG0)
#define GameTimeClock_DIV_LSB_PTR        ((reg8 *) GameTimeClock__CFG0)
#define GameTimeClock_DIV_PTR            ((reg16 *) GameTimeClock__CFG0)

/* Clock MSB divider configuration register. */
#define GameTimeClock_DIV_MSB            (* (reg8 *) GameTimeClock__CFG1)
#define GameTimeClock_DIV_MSB_PTR        ((reg8 *) GameTimeClock__CFG1)

/* Mode and source configuration register */
#define GameTimeClock_MOD_SRC            (* (reg8 *) GameTimeClock__CFG2)
#define GameTimeClock_MOD_SRC_PTR        ((reg8 *) GameTimeClock__CFG2)

#if defined(GameTimeClock__CFG3)
/* Analog clock phase configuration register */
#define GameTimeClock_PHASE              (* (reg8 *) GameTimeClock__CFG3)
#define GameTimeClock_PHASE_PTR          ((reg8 *) GameTimeClock__CFG3)
#endif /* defined(GameTimeClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define GameTimeClock_CLKEN_MASK         GameTimeClock__PM_ACT_MSK
#define GameTimeClock_CLKSTBY_MASK       GameTimeClock__PM_STBY_MSK

/* CFG2 field masks */
#define GameTimeClock_SRC_SEL_MSK        GameTimeClock__CFG2_SRC_SEL_MASK
#define GameTimeClock_MODE_MASK          (~(GameTimeClock_SRC_SEL_MSK))

#if defined(GameTimeClock__CFG3)
/* CFG3 phase mask */
#define GameTimeClock_PHASE_MASK         GameTimeClock__CFG3_PHASE_DLY_MASK
#endif /* defined(GameTimeClock__CFG3) */

#endif /* CY_CLOCK_GameTimeClock_H */


/* [] END OF FILE */
