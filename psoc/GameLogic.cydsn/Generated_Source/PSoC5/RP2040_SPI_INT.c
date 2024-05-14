/*******************************************************************************
* File Name: RP2040_SPI_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RP2040_SPI_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START RP2040_SPI_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: RP2040_SPI_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RP2040_SPI_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  RP2040_SPI_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  RP2040_SPI_txBuffer[RP2040_SPI_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(RP2040_SPI_TX_ISR)
{
    #if(RP2040_SPI_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (RP2040_SPI_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef RP2040_SPI_TX_ISR_ENTRY_CALLBACK
        RP2040_SPI_TX_ISR_EntryCallback();
    #endif /* RP2040_SPI_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START RP2040_SPI_TX_ISR_START` */

    /* `#END` */
    
    #if(RP2040_SPI_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(RP2040_SPI_txBufferRead != RP2040_SPI_txBufferWrite)
        {
            tmpStatus = RP2040_SPI_GET_STATUS_TX(RP2040_SPI_swStatusTx);
            RP2040_SPI_swStatusTx = tmpStatus;

            if(0u != (RP2040_SPI_swStatusTx & RP2040_SPI_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == RP2040_SPI_txBufferFull)
                {
                   RP2040_SPI_txBufferRead++;

                    if(RP2040_SPI_txBufferRead >= RP2040_SPI_TX_BUFFER_SIZE)
                    {
                        RP2040_SPI_txBufferRead = 0u;
                    }
                }
                else
                {
                    RP2040_SPI_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG8(RP2040_SPI_TXDATA_PTR, 
                                             RP2040_SPI_txBuffer[RP2040_SPI_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(RP2040_SPI_txBufferRead == RP2040_SPI_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            RP2040_SPI_TX_STATUS_MASK_REG &= ((uint8) ~RP2040_SPI_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (RP2040_SPI_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START RP2040_SPI_TX_ISR_END` */

    /* `#END` */
    
    #ifdef RP2040_SPI_TX_ISR_EXIT_CALLBACK
        RP2040_SPI_TX_ISR_ExitCallback();
    #endif /* RP2040_SPI_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: RP2040_SPI_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  RP2040_SPI_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  RP2040_SPI_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  RP2040_SPI_rxBuffer[RP2040_SPI_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(RP2040_SPI_RX_ISR)
{
    #if(RP2040_SPI_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint8 rxData;
    #endif /* (RP2040_SPI_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef RP2040_SPI_RX_ISR_ENTRY_CALLBACK
        RP2040_SPI_RX_ISR_EntryCallback();
    #endif /* RP2040_SPI_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START RP2040_SPI_RX_ISR_START` */

    /* `#END` */
    
    #if(RP2040_SPI_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = RP2040_SPI_GET_STATUS_RX(RP2040_SPI_swStatusRx);
        RP2040_SPI_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (RP2040_SPI_swStatusRx & RP2040_SPI_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG8(RP2040_SPI_RXDATA_PTR);

            /* Set next pointer. */
            RP2040_SPI_rxBufferWrite++;
            if(RP2040_SPI_rxBufferWrite >= RP2040_SPI_RX_BUFFER_SIZE)
            {
                RP2040_SPI_rxBufferWrite = 0u;
            }

            if(RP2040_SPI_rxBufferWrite == RP2040_SPI_rxBufferRead)
            {
                RP2040_SPI_rxBufferRead++;
                if(RP2040_SPI_rxBufferRead >= RP2040_SPI_RX_BUFFER_SIZE)
                {
                    RP2040_SPI_rxBufferRead = 0u;
                }

                RP2040_SPI_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            RP2040_SPI_rxBuffer[RP2040_SPI_rxBufferWrite] = rxData;

            tmpStatus = RP2040_SPI_GET_STATUS_RX(RP2040_SPI_swStatusRx);
            RP2040_SPI_swStatusRx = tmpStatus;
        }

    #endif /* (RP2040_SPI_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START RP2040_SPI_RX_ISR_END` */

    /* `#END` */
    
    #ifdef RP2040_SPI_RX_ISR_EXIT_CALLBACK
        RP2040_SPI_RX_ISR_ExitCallback();
    #endif /* RP2040_SPI_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
