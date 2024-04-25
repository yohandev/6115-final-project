/*******************************************************************************
* File Name: Joystick_X_PM.c
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

#include "Joystick_X.h"


/***************************************
* Local data allocation
***************************************/

static Joystick_X_BACKUP_STRUCT  Joystick_X_backup =
{
    Joystick_X_DISABLED
};


/*******************************************************************************
* Function Name: Joystick_X_SaveConfig
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
void Joystick_X_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Joystick_X_RestoreConfig
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
void Joystick_X_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Joystick_X_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Joystick_X_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Joystick_X_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Joystick_X_Sleep(void)
{
    if((Joystick_X_PWRMGR_SAR_REG  & Joystick_X_ACT_PWR_SAR_EN) != 0u)
    {
        if((Joystick_X_SAR_CSR0_REG & Joystick_X_SAR_SOF_START_CONV) != 0u)
        {
            Joystick_X_backup.enableState = Joystick_X_ENABLED | Joystick_X_STARTED;
        }
        else
        {
            Joystick_X_backup.enableState = Joystick_X_ENABLED;
        }
        Joystick_X_Stop();
    }
    else
    {
        Joystick_X_backup.enableState = Joystick_X_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Joystick_X_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Joystick_X_Sleep() was called. If the component was enabled before the
*  Joystick_X_Sleep() function was called, the
*  Joystick_X_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Joystick_X_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Joystick_X_Wakeup(void)
{
    if(Joystick_X_backup.enableState != Joystick_X_DISABLED)
    {
        Joystick_X_Enable();
        #if(Joystick_X_DEFAULT_CONV_MODE != Joystick_X__HARDWARE_TRIGGER)
            if((Joystick_X_backup.enableState & Joystick_X_STARTED) != 0u)
            {
                Joystick_X_StartConvert();
            }
        #endif /* End Joystick_X_DEFAULT_CONV_MODE != Joystick_X__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
