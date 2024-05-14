/*******************************************************************************
* File Name: RP2040_SPI_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RP2040_SPI_PVT.h"

static RP2040_SPI_BACKUP_STRUCT RP2040_SPI_backup =
{
    RP2040_SPI_DISABLED,
    RP2040_SPI_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: RP2040_SPI_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RP2040_SPI_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: RP2040_SPI_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RP2040_SPI_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: RP2040_SPI_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RP2040_SPI_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RP2040_SPI_Sleep(void) 
{
    /* Save components enable state */
    RP2040_SPI_backup.enableState = ((uint8) RP2040_SPI_IS_ENABLED);

    RP2040_SPI_Stop();
}


/*******************************************************************************
* Function Name: RP2040_SPI_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  RP2040_SPI_backup - used when non-retention registers are restored.
*  RP2040_SPI_txBufferWrite - modified every function call - resets to
*  zero.
*  RP2040_SPI_txBufferRead - modified every function call - resets to
*  zero.
*  RP2040_SPI_rxBufferWrite - modified every function call - resets to
*  zero.
*  RP2040_SPI_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RP2040_SPI_Wakeup(void) 
{
    #if(RP2040_SPI_RX_SOFTWARE_BUF_ENABLED)
        RP2040_SPI_rxBufferFull  = 0u;
        RP2040_SPI_rxBufferRead  = 0u;
        RP2040_SPI_rxBufferWrite = 0u;
    #endif /* (RP2040_SPI_RX_SOFTWARE_BUF_ENABLED) */

    #if(RP2040_SPI_TX_SOFTWARE_BUF_ENABLED)
        RP2040_SPI_txBufferFull  = 0u;
        RP2040_SPI_txBufferRead  = 0u;
        RP2040_SPI_txBufferWrite = 0u;
    #endif /* (RP2040_SPI_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    RP2040_SPI_ClearFIFO();

    /* Restore components block enable state */
    if(0u != RP2040_SPI_backup.enableState)
    {
        RP2040_SPI_Enable();
    }
}


/* [] END OF FILE */
