/*******************************************************************************
* File Name: Joystick_Y_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Joystick_Y.h"


/***************************************
* Local data allocation
***************************************/

static Joystick_Y_BACKUP_STRUCT  Joystick_Y_backup =
{
    Joystick_Y_DISABLED
};


/*******************************************************************************
* Function Name: Joystick_Y_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Joystick_Y_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Joystick_Y_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Joystick_Y_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Joystick_Y_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Joystick_Y_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Joystick_Y_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Joystick_Y_Sleep(void)
{
    if((Joystick_Y_PWRMGR_SAR_REG  & Joystick_Y_ACT_PWR_SAR_EN) != 0u)
    {
        if((Joystick_Y_SAR_CSR0_REG & Joystick_Y_SAR_SOF_START_CONV) != 0u)
        {
            Joystick_Y_backup.enableState = Joystick_Y_ENABLED | Joystick_Y_STARTED;
        }
        else
        {
            Joystick_Y_backup.enableState = Joystick_Y_ENABLED;
        }
        Joystick_Y_Stop();
    }
    else
    {
        Joystick_Y_backup.enableState = Joystick_Y_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Joystick_Y_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Joystick_Y_Sleep() was called. If the component was enabled before the
*  Joystick_Y_Sleep() function was called, the
*  Joystick_Y_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Joystick_Y_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Joystick_Y_Wakeup(void)
{
    if(Joystick_Y_backup.enableState != Joystick_Y_DISABLED)
    {
        Joystick_Y_Enable();
        #if(Joystick_Y_DEFAULT_CONV_MODE != Joystick_Y__HARDWARE_TRIGGER)
            if((Joystick_Y_backup.enableState & Joystick_Y_STARTED) != 0u)
            {
                Joystick_Y_StartConvert();
            }
        #endif /* End Joystick_Y_DEFAULT_CONV_MODE != Joystick_Y__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
