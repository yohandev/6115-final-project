/*******************************************************************************
* File Name: RP2040_SPI.h
* Version 2.50
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_RP2040_SPI_H)
#define CY_SPIM_RP2040_SPI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component SPI_Master_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define RP2040_SPI_INTERNAL_CLOCK             (1u)

#if(0u != RP2040_SPI_INTERNAL_CLOCK)
    #include "RP2040_SPI_IntClock.h"
#endif /* (0u != RP2040_SPI_INTERNAL_CLOCK) */

#define RP2040_SPI_MODE                       (1u)
#define RP2040_SPI_DATA_WIDTH                 (8u)
#define RP2040_SPI_MODE_USE_ZERO              (1u)
#define RP2040_SPI_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define RP2040_SPI_TX_BUFFER_SIZE             (4u)
#define RP2040_SPI_RX_BUFFER_SIZE             (4u)
#define RP2040_SPI_INTERNAL_TX_INT_ENABLED    (0u)
#define RP2040_SPI_INTERNAL_RX_INT_ENABLED    (0u)

#define RP2040_SPI_SINGLE_REG_SIZE            (8u)
#define RP2040_SPI_USE_SECOND_DATAPATH        (RP2040_SPI_DATA_WIDTH > RP2040_SPI_SINGLE_REG_SIZE)

#define RP2040_SPI_FIFO_SIZE                  (4u)
#define RP2040_SPI_TX_SOFTWARE_BUF_ENABLED    ((0u != RP2040_SPI_INTERNAL_TX_INT_ENABLED) && \
                                                     (RP2040_SPI_TX_BUFFER_SIZE > RP2040_SPI_FIFO_SIZE))

#define RP2040_SPI_RX_SOFTWARE_BUF_ENABLED    ((0u != RP2040_SPI_INTERNAL_RX_INT_ENABLED) && \
                                                     (RP2040_SPI_RX_BUFFER_SIZE > RP2040_SPI_FIFO_SIZE))


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;
} RP2040_SPI_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  RP2040_SPI_Init(void)                           ;
void  RP2040_SPI_Enable(void)                         ;
void  RP2040_SPI_Start(void)                          ;
void  RP2040_SPI_Stop(void)                           ;

void  RP2040_SPI_EnableTxInt(void)                    ;
void  RP2040_SPI_EnableRxInt(void)                    ;
void  RP2040_SPI_DisableTxInt(void)                   ;
void  RP2040_SPI_DisableRxInt(void)                   ;

void  RP2040_SPI_Sleep(void)                          ;
void  RP2040_SPI_Wakeup(void)                         ;
void  RP2040_SPI_SaveConfig(void)                     ;
void  RP2040_SPI_RestoreConfig(void)                  ;

void  RP2040_SPI_SetTxInterruptMode(uint8 intSrc)     ;
void  RP2040_SPI_SetRxInterruptMode(uint8 intSrc)     ;
uint8 RP2040_SPI_ReadTxStatus(void)                   ;
uint8 RP2040_SPI_ReadRxStatus(void)                   ;
void  RP2040_SPI_WriteTxData(uint8 txData)  \
                                                            ;
uint8 RP2040_SPI_ReadRxData(void) \
                                                            ;
uint8 RP2040_SPI_GetRxBufferSize(void)                ;
uint8 RP2040_SPI_GetTxBufferSize(void)                ;
void  RP2040_SPI_ClearRxBuffer(void)                  ;
void  RP2040_SPI_ClearTxBuffer(void)                  ;
void  RP2040_SPI_ClearFIFO(void)                              ;
void  RP2040_SPI_PutArray(const uint8 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != RP2040_SPI_BIDIRECTIONAL_MODE)
    void  RP2040_SPI_TxEnable(void)                   ;
    void  RP2040_SPI_TxDisable(void)                  ;
#endif /* (0u != RP2040_SPI_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(RP2040_SPI_TX_ISR);
CY_ISR_PROTO(RP2040_SPI_RX_ISR);


/***************************************
*   Variable with external linkage
***************************************/

extern uint8 RP2040_SPI_initVar;


/***************************************
*           API Constants
***************************************/

#define RP2040_SPI_TX_ISR_NUMBER     ((uint8) (RP2040_SPI_TxInternalInterrupt__INTC_NUMBER))
#define RP2040_SPI_RX_ISR_NUMBER     ((uint8) (RP2040_SPI_RxInternalInterrupt__INTC_NUMBER))

#define RP2040_SPI_TX_ISR_PRIORITY   ((uint8) (RP2040_SPI_TxInternalInterrupt__INTC_PRIOR_NUM))
#define RP2040_SPI_RX_ISR_PRIORITY   ((uint8) (RP2040_SPI_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define RP2040_SPI_INT_ON_SPI_DONE    ((uint8) (0u   << RP2040_SPI_STS_SPI_DONE_SHIFT))
#define RP2040_SPI_INT_ON_TX_EMPTY    ((uint8) (0u   << RP2040_SPI_STS_TX_FIFO_EMPTY_SHIFT))
#define RP2040_SPI_INT_ON_TX_NOT_FULL ((uint8) (0u << \
                                                                           RP2040_SPI_STS_TX_FIFO_NOT_FULL_SHIFT))
#define RP2040_SPI_INT_ON_BYTE_COMP   ((uint8) (0u  << RP2040_SPI_STS_BYTE_COMPLETE_SHIFT))
#define RP2040_SPI_INT_ON_SPI_IDLE    ((uint8) (0u   << RP2040_SPI_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define RP2040_SPI_INT_ON_TX_NOT_FULL_DEF ((RP2040_SPI_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (RP2040_SPI_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define RP2040_SPI_TX_INIT_INTERRUPTS_MASK    (RP2040_SPI_INT_ON_SPI_DONE  | \
                                                     RP2040_SPI_INT_ON_TX_EMPTY  | \
                                                     RP2040_SPI_INT_ON_TX_NOT_FULL_DEF | \
                                                     RP2040_SPI_INT_ON_BYTE_COMP | \
                                                     RP2040_SPI_INT_ON_SPI_IDLE)

#define RP2040_SPI_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          RP2040_SPI_STS_RX_FIFO_FULL_SHIFT))
#define RP2040_SPI_INT_ON_RX_NOT_EMPTY    ((uint8) (0u << \
                                                                          RP2040_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define RP2040_SPI_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          RP2040_SPI_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define RP2040_SPI_RX_INIT_INTERRUPTS_MASK    (RP2040_SPI_INT_ON_RX_FULL      | \
                                                     RP2040_SPI_INT_ON_RX_NOT_EMPTY | \
                                                     RP2040_SPI_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define RP2040_SPI_BITCTR_INIT            (((uint8) (RP2040_SPI_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/
#if(CY_PSOC3 || CY_PSOC5)
    #define RP2040_SPI_TXDATA_REG (* (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F0_REG)
    #define RP2040_SPI_TXDATA_PTR (  (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F0_REG)
    #define RP2040_SPI_RXDATA_REG (* (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F1_REG)
    #define RP2040_SPI_RXDATA_PTR (  (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(RP2040_SPI_USE_SECOND_DATAPATH)
        #define RP2040_SPI_TXDATA_REG (* (reg16 *) \
                                          RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define RP2040_SPI_TXDATA_PTR (  (reg16 *) \
                                          RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F0_REG)
        #define RP2040_SPI_RXDATA_REG (* (reg16 *) \
                                          RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
        #define RP2040_SPI_RXDATA_PTR (  (reg16 *) \
                                          RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F1_REG)
    #else
        #define RP2040_SPI_TXDATA_REG (* (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F0_REG)
        #define RP2040_SPI_TXDATA_PTR (  (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F0_REG)
        #define RP2040_SPI_RXDATA_REG (* (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F1_REG)
        #define RP2040_SPI_RXDATA_PTR (  (reg8 *) \
                                                RP2040_SPI_BSPIM_sR8_Dp_u0__F1_REG)
    #endif /* (RP2040_SPI_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define RP2040_SPI_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        RP2040_SPI_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define RP2040_SPI_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        RP2040_SPI_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)

#if(RP2040_SPI_USE_SECOND_DATAPATH)
    #define RP2040_SPI_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        RP2040_SPI_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define RP2040_SPI_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        RP2040_SPI_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* (RP2040_SPI_USE_SECOND_DATAPATH) */

#define RP2040_SPI_COUNTER_PERIOD_REG     (* (reg8 *) RP2040_SPI_BSPIM_BitCounter__PERIOD_REG)
#define RP2040_SPI_COUNTER_PERIOD_PTR     (  (reg8 *) RP2040_SPI_BSPIM_BitCounter__PERIOD_REG)
#define RP2040_SPI_COUNTER_CONTROL_REG    (* (reg8 *) RP2040_SPI_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define RP2040_SPI_COUNTER_CONTROL_PTR    (  (reg8 *) RP2040_SPI_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define RP2040_SPI_TX_STATUS_REG          (* (reg8 *) RP2040_SPI_BSPIM_TxStsReg__STATUS_REG)
#define RP2040_SPI_TX_STATUS_PTR          (  (reg8 *) RP2040_SPI_BSPIM_TxStsReg__STATUS_REG)
#define RP2040_SPI_RX_STATUS_REG          (* (reg8 *) RP2040_SPI_BSPIM_RxStsReg__STATUS_REG)
#define RP2040_SPI_RX_STATUS_PTR          (  (reg8 *) RP2040_SPI_BSPIM_RxStsReg__STATUS_REG)

#define RP2040_SPI_CONTROL_REG            (* (reg8 *) \
                                      RP2040_SPI_BSPIM_BidirMode_CtrlReg__CONTROL_REG)
#define RP2040_SPI_CONTROL_PTR            (  (reg8 *) \
                                      RP2040_SPI_BSPIM_BidirMode_CtrlReg__CONTROL_REG)

#define RP2040_SPI_TX_STATUS_MASK_REG     (* (reg8 *) RP2040_SPI_BSPIM_TxStsReg__MASK_REG)
#define RP2040_SPI_TX_STATUS_MASK_PTR     (  (reg8 *) RP2040_SPI_BSPIM_TxStsReg__MASK_REG)
#define RP2040_SPI_RX_STATUS_MASK_REG     (* (reg8 *) RP2040_SPI_BSPIM_RxStsReg__MASK_REG)
#define RP2040_SPI_RX_STATUS_MASK_PTR     (  (reg8 *) RP2040_SPI_BSPIM_RxStsReg__MASK_REG)

#define RP2040_SPI_TX_STATUS_ACTL_REG     (* (reg8 *) RP2040_SPI_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define RP2040_SPI_TX_STATUS_ACTL_PTR     (  (reg8 *) RP2040_SPI_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define RP2040_SPI_RX_STATUS_ACTL_REG     (* (reg8 *) RP2040_SPI_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define RP2040_SPI_RX_STATUS_ACTL_PTR     (  (reg8 *) RP2040_SPI_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(RP2040_SPI_USE_SECOND_DATAPATH)
    #define RP2040_SPI_AUX_CONTROLDP1     (RP2040_SPI_AUX_CONTROL_DP1_REG)
#endif /* (RP2040_SPI_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define RP2040_SPI_STS_SPI_DONE_SHIFT             (0x00u)
#define RP2040_SPI_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define RP2040_SPI_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define RP2040_SPI_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define RP2040_SPI_STS_SPI_IDLE_SHIFT             (0x04u)
#define RP2040_SPI_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define RP2040_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define RP2040_SPI_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define RP2040_SPI_STS_SPI_DONE           ((uint8) (0x01u << RP2040_SPI_STS_SPI_DONE_SHIFT))
#define RP2040_SPI_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << RP2040_SPI_STS_TX_FIFO_EMPTY_SHIFT))
#define RP2040_SPI_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << RP2040_SPI_STS_TX_FIFO_NOT_FULL_SHIFT))
#define RP2040_SPI_STS_BYTE_COMPLETE      ((uint8) (0x01u << RP2040_SPI_STS_BYTE_COMPLETE_SHIFT))
#define RP2040_SPI_STS_SPI_IDLE           ((uint8) (0x01u << RP2040_SPI_STS_SPI_IDLE_SHIFT))
#define RP2040_SPI_STS_RX_FIFO_FULL       ((uint8) (0x01u << RP2040_SPI_STS_RX_FIFO_FULL_SHIFT))
#define RP2040_SPI_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << RP2040_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define RP2040_SPI_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << RP2040_SPI_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define RP2040_SPI_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define RP2040_SPI_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define RP2040_SPI_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define RP2040_SPI_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define RP2040_SPI_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define RP2040_SPI_FIFO_CLR       (RP2040_SPI_TX_FIFO_CLR | RP2040_SPI_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define RP2040_SPI_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define RP2040_SPI_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define RP2040_SPI_AUX_CTRL_FIFO0_CLR         (0x01u)
#define RP2040_SPI_AUX_CTRL_FIFO1_CLR         (0x02u)
#define RP2040_SPI_AUX_CTRL_FIFO0_LVL         (0x04u)
#define RP2040_SPI_AUX_CTRL_FIFO1_LVL         (0x08u)
#define RP2040_SPI_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define RP2040_SPI_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define RP2040_SPI_IS_ENABLED (0u != (RP2040_SPI_TX_STATUS_ACTL_REG & RP2040_SPI_INT_ENABLE))

/* Retuns TX status register */
#define RP2040_SPI_GET_STATUS_TX(swTxSts) ( (uint8)(RP2040_SPI_TX_STATUS_REG | \
                                                          ((swTxSts) & RP2040_SPI_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define RP2040_SPI_GET_STATUS_RX(swRxSts) ( (uint8)(RP2040_SPI_RX_STATUS_REG | \
                                                          ((swRxSts) & RP2040_SPI_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
* The following code is DEPRECATED and 
* should not be used in new projects.
***************************************/

#define RP2040_SPI_WriteByte   RP2040_SPI_WriteTxData
#define RP2040_SPI_ReadByte    RP2040_SPI_ReadRxData
void  RP2040_SPI_SetInterruptMode(uint8 intSrc)       ;
uint8 RP2040_SPI_ReadStatus(void)                     ;
void  RP2040_SPI_EnableInt(void)                      ;
void  RP2040_SPI_DisableInt(void)                     ;

#define RP2040_SPI_TXDATA                 (RP2040_SPI_TXDATA_REG)
#define RP2040_SPI_RXDATA                 (RP2040_SPI_RXDATA_REG)
#define RP2040_SPI_AUX_CONTROLDP0         (RP2040_SPI_AUX_CONTROL_DP0_REG)
#define RP2040_SPI_TXBUFFERREAD           (RP2040_SPI_txBufferRead)
#define RP2040_SPI_TXBUFFERWRITE          (RP2040_SPI_txBufferWrite)
#define RP2040_SPI_RXBUFFERREAD           (RP2040_SPI_rxBufferRead)
#define RP2040_SPI_RXBUFFERWRITE          (RP2040_SPI_rxBufferWrite)

#define RP2040_SPI_COUNTER_PERIOD         (RP2040_SPI_COUNTER_PERIOD_REG)
#define RP2040_SPI_COUNTER_CONTROL        (RP2040_SPI_COUNTER_CONTROL_REG)
#define RP2040_SPI_STATUS                 (RP2040_SPI_TX_STATUS_REG)
#define RP2040_SPI_CONTROL                (RP2040_SPI_CONTROL_REG)
#define RP2040_SPI_STATUS_MASK            (RP2040_SPI_TX_STATUS_MASK_REG)
#define RP2040_SPI_STATUS_ACTL            (RP2040_SPI_TX_STATUS_ACTL_REG)

#define RP2040_SPI_INIT_INTERRUPTS_MASK  (RP2040_SPI_INT_ON_SPI_DONE     | \
                                                RP2040_SPI_INT_ON_TX_EMPTY     | \
                                                RP2040_SPI_INT_ON_TX_NOT_FULL_DEF  | \
                                                RP2040_SPI_INT_ON_RX_FULL      | \
                                                RP2040_SPI_INT_ON_RX_NOT_EMPTY | \
                                                RP2040_SPI_INT_ON_RX_OVER      | \
                                                RP2040_SPI_INT_ON_BYTE_COMP)
                                                
#define RP2040_SPI_DataWidth                  (RP2040_SPI_DATA_WIDTH)
#define RP2040_SPI_InternalClockUsed          (RP2040_SPI_INTERNAL_CLOCK)
#define RP2040_SPI_InternalTxInterruptEnabled (RP2040_SPI_INTERNAL_TX_INT_ENABLED)
#define RP2040_SPI_InternalRxInterruptEnabled (RP2040_SPI_INTERNAL_RX_INT_ENABLED)
#define RP2040_SPI_ModeUseZero                (RP2040_SPI_MODE_USE_ZERO)
#define RP2040_SPI_BidirectionalMode          (RP2040_SPI_BIDIRECTIONAL_MODE)
#define RP2040_SPI_Mode                       (RP2040_SPI_MODE)
#define RP2040_SPI_DATAWIDHT                  (RP2040_SPI_DATA_WIDTH)
#define RP2040_SPI_InternalInterruptEnabled   (0u)

#define RP2040_SPI_TXBUFFERSIZE   (RP2040_SPI_TX_BUFFER_SIZE)
#define RP2040_SPI_RXBUFFERSIZE   (RP2040_SPI_RX_BUFFER_SIZE)

#define RP2040_SPI_TXBUFFER       RP2040_SPI_txBuffer
#define RP2040_SPI_RXBUFFER       RP2040_SPI_rxBuffer

#endif /* (CY_SPIM_RP2040_SPI_H) */


/* [] END OF FILE */
