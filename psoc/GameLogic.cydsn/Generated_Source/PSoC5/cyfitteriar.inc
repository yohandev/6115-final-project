#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* Rx_1 */
Rx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Rx_1__0__MASK EQU 0x40
Rx_1__0__PC EQU CYREG_PRT12_PC6
Rx_1__0__PORT EQU 12
Rx_1__0__SHIFT EQU 6
Rx_1__AG EQU CYREG_PRT12_AG
Rx_1__BIE EQU CYREG_PRT12_BIE
Rx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Rx_1__BYP EQU CYREG_PRT12_BYP
Rx_1__DM0 EQU CYREG_PRT12_DM0
Rx_1__DM1 EQU CYREG_PRT12_DM1
Rx_1__DM2 EQU CYREG_PRT12_DM2
Rx_1__DR EQU CYREG_PRT12_DR
Rx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Rx_1__MASK EQU 0x40
Rx_1__PORT EQU 12
Rx_1__PRT EQU CYREG_PRT12_PRT
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Rx_1__PS EQU CYREG_PRT12_PS
Rx_1__SHIFT EQU 6
Rx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Rx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Rx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Rx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Rx_1__SLW EQU CYREG_PRT12_SLW

/* Tx_1 */
Tx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
Tx_1__0__MASK EQU 0x80
Tx_1__0__PC EQU CYREG_PRT12_PC7
Tx_1__0__PORT EQU 12
Tx_1__0__SHIFT EQU 7
Tx_1__AG EQU CYREG_PRT12_AG
Tx_1__BIE EQU CYREG_PRT12_BIE
Tx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Tx_1__BYP EQU CYREG_PRT12_BYP
Tx_1__DM0 EQU CYREG_PRT12_DM0
Tx_1__DM1 EQU CYREG_PRT12_DM1
Tx_1__DM2 EQU CYREG_PRT12_DM2
Tx_1__DR EQU CYREG_PRT12_DR
Tx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Tx_1__MASK EQU 0x80
Tx_1__PORT EQU 12
Tx_1__PRT EQU CYREG_PRT12_PRT
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Tx_1__PS EQU CYREG_PRT12_PS
Tx_1__SHIFT EQU 7
Tx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Tx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Tx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Tx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Tx_1__SLW EQU CYREG_PRT12_SLW

/* Joystick_X_ADC_SAR */
Joystick_X_ADC_SAR__CLK EQU CYREG_SAR0_CLK
Joystick_X_ADC_SAR__CSR0 EQU CYREG_SAR0_CSR0
Joystick_X_ADC_SAR__CSR1 EQU CYREG_SAR0_CSR1
Joystick_X_ADC_SAR__CSR2 EQU CYREG_SAR0_CSR2
Joystick_X_ADC_SAR__CSR3 EQU CYREG_SAR0_CSR3
Joystick_X_ADC_SAR__CSR4 EQU CYREG_SAR0_CSR4
Joystick_X_ADC_SAR__CSR5 EQU CYREG_SAR0_CSR5
Joystick_X_ADC_SAR__CSR6 EQU CYREG_SAR0_CSR6
Joystick_X_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
Joystick_X_ADC_SAR__PM_ACT_MSK EQU 0x01
Joystick_X_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
Joystick_X_ADC_SAR__PM_STBY_MSK EQU 0x01
Joystick_X_ADC_SAR__SW0 EQU CYREG_SAR0_SW0
Joystick_X_ADC_SAR__SW2 EQU CYREG_SAR0_SW2
Joystick_X_ADC_SAR__SW3 EQU CYREG_SAR0_SW3
Joystick_X_ADC_SAR__SW4 EQU CYREG_SAR0_SW4
Joystick_X_ADC_SAR__SW6 EQU CYREG_SAR0_SW6
Joystick_X_ADC_SAR__TR0 EQU CYREG_SAR0_TR0
Joystick_X_ADC_SAR__WRK0 EQU CYREG_SAR0_WRK0
Joystick_X_ADC_SAR__WRK1 EQU CYREG_SAR0_WRK1

/* Joystick_X_IRQ */
Joystick_X_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Joystick_X_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Joystick_X_IRQ__INTC_MASK EQU 0x08
Joystick_X_IRQ__INTC_NUMBER EQU 3
Joystick_X_IRQ__INTC_PRIOR_NUM EQU 7
Joystick_X_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
Joystick_X_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Joystick_X_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Joystick_X_Pin */
Joystick_X_Pin__0__INTTYPE EQU CYREG_PICU1_INTTYPE0
Joystick_X_Pin__0__MASK EQU 0x01
Joystick_X_Pin__0__PC EQU CYREG_PRT1_PC0
Joystick_X_Pin__0__PORT EQU 1
Joystick_X_Pin__0__SHIFT EQU 0
Joystick_X_Pin__AG EQU CYREG_PRT1_AG
Joystick_X_Pin__AMUX EQU CYREG_PRT1_AMUX
Joystick_X_Pin__BIE EQU CYREG_PRT1_BIE
Joystick_X_Pin__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Joystick_X_Pin__BYP EQU CYREG_PRT1_BYP
Joystick_X_Pin__CTL EQU CYREG_PRT1_CTL
Joystick_X_Pin__DM0 EQU CYREG_PRT1_DM0
Joystick_X_Pin__DM1 EQU CYREG_PRT1_DM1
Joystick_X_Pin__DM2 EQU CYREG_PRT1_DM2
Joystick_X_Pin__DR EQU CYREG_PRT1_DR
Joystick_X_Pin__INP_DIS EQU CYREG_PRT1_INP_DIS
Joystick_X_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Joystick_X_Pin__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Joystick_X_Pin__LCD_EN EQU CYREG_PRT1_LCD_EN
Joystick_X_Pin__MASK EQU 0x01
Joystick_X_Pin__PORT EQU 1
Joystick_X_Pin__PRT EQU CYREG_PRT1_PRT
Joystick_X_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Joystick_X_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Joystick_X_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Joystick_X_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Joystick_X_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Joystick_X_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Joystick_X_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Joystick_X_Pin__PS EQU CYREG_PRT1_PS
Joystick_X_Pin__SHIFT EQU 0
Joystick_X_Pin__SLW EQU CYREG_PRT1_SLW

/* Joystick_X_theACLK */
Joystick_X_theACLK__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
Joystick_X_theACLK__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
Joystick_X_theACLK__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
Joystick_X_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
Joystick_X_theACLK__INDEX EQU 0x02
Joystick_X_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Joystick_X_theACLK__PM_ACT_MSK EQU 0x04
Joystick_X_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Joystick_X_theACLK__PM_STBY_MSK EQU 0x04

/* Joystick_Y_ADC_SAR */
Joystick_Y_ADC_SAR__CLK EQU CYREG_SAR1_CLK
Joystick_Y_ADC_SAR__CSR0 EQU CYREG_SAR1_CSR0
Joystick_Y_ADC_SAR__CSR1 EQU CYREG_SAR1_CSR1
Joystick_Y_ADC_SAR__CSR2 EQU CYREG_SAR1_CSR2
Joystick_Y_ADC_SAR__CSR3 EQU CYREG_SAR1_CSR3
Joystick_Y_ADC_SAR__CSR4 EQU CYREG_SAR1_CSR4
Joystick_Y_ADC_SAR__CSR5 EQU CYREG_SAR1_CSR5
Joystick_Y_ADC_SAR__CSR6 EQU CYREG_SAR1_CSR6
Joystick_Y_ADC_SAR__PM_ACT_CFG EQU CYREG_PM_ACT_CFG11
Joystick_Y_ADC_SAR__PM_ACT_MSK EQU 0x02
Joystick_Y_ADC_SAR__PM_STBY_CFG EQU CYREG_PM_STBY_CFG11
Joystick_Y_ADC_SAR__PM_STBY_MSK EQU 0x02
Joystick_Y_ADC_SAR__SW0 EQU CYREG_SAR1_SW0
Joystick_Y_ADC_SAR__SW2 EQU CYREG_SAR1_SW2
Joystick_Y_ADC_SAR__SW3 EQU CYREG_SAR1_SW3
Joystick_Y_ADC_SAR__SW4 EQU CYREG_SAR1_SW4
Joystick_Y_ADC_SAR__SW6 EQU CYREG_SAR1_SW6
Joystick_Y_ADC_SAR__TR0 EQU CYREG_SAR1_TR0
Joystick_Y_ADC_SAR__WRK0 EQU CYREG_SAR1_WRK0
Joystick_Y_ADC_SAR__WRK1 EQU CYREG_SAR1_WRK1

/* Joystick_Y_IRQ */
Joystick_Y_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Joystick_Y_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Joystick_Y_IRQ__INTC_MASK EQU 0x10
Joystick_Y_IRQ__INTC_NUMBER EQU 4
Joystick_Y_IRQ__INTC_PRIOR_NUM EQU 7
Joystick_Y_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_4
Joystick_Y_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Joystick_Y_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Joystick_Y_Pin */
Joystick_Y_Pin__0__INTTYPE EQU CYREG_PICU1_INTTYPE1
Joystick_Y_Pin__0__MASK EQU 0x02
Joystick_Y_Pin__0__PC EQU CYREG_PRT1_PC1
Joystick_Y_Pin__0__PORT EQU 1
Joystick_Y_Pin__0__SHIFT EQU 1
Joystick_Y_Pin__AG EQU CYREG_PRT1_AG
Joystick_Y_Pin__AMUX EQU CYREG_PRT1_AMUX
Joystick_Y_Pin__BIE EQU CYREG_PRT1_BIE
Joystick_Y_Pin__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Joystick_Y_Pin__BYP EQU CYREG_PRT1_BYP
Joystick_Y_Pin__CTL EQU CYREG_PRT1_CTL
Joystick_Y_Pin__DM0 EQU CYREG_PRT1_DM0
Joystick_Y_Pin__DM1 EQU CYREG_PRT1_DM1
Joystick_Y_Pin__DM2 EQU CYREG_PRT1_DM2
Joystick_Y_Pin__DR EQU CYREG_PRT1_DR
Joystick_Y_Pin__INP_DIS EQU CYREG_PRT1_INP_DIS
Joystick_Y_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Joystick_Y_Pin__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Joystick_Y_Pin__LCD_EN EQU CYREG_PRT1_LCD_EN
Joystick_Y_Pin__MASK EQU 0x02
Joystick_Y_Pin__PORT EQU 1
Joystick_Y_Pin__PRT EQU CYREG_PRT1_PRT
Joystick_Y_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Joystick_Y_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Joystick_Y_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Joystick_Y_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Joystick_Y_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Joystick_Y_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Joystick_Y_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Joystick_Y_Pin__PS EQU CYREG_PRT1_PS
Joystick_Y_Pin__SHIFT EQU 1
Joystick_Y_Pin__SLW EQU CYREG_PRT1_SLW

/* Joystick_Y_theACLK */
Joystick_Y_theACLK__CFG0 EQU CYREG_CLKDIST_DCFG3_CFG0
Joystick_Y_theACLK__CFG1 EQU CYREG_CLKDIST_DCFG3_CFG1
Joystick_Y_theACLK__CFG2 EQU CYREG_CLKDIST_DCFG3_CFG2
Joystick_Y_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
Joystick_Y_theACLK__INDEX EQU 0x03
Joystick_Y_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Joystick_Y_theACLK__PM_ACT_MSK EQU 0x08
Joystick_Y_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Joystick_Y_theACLK__PM_STBY_MSK EQU 0x08

/* RP2040_SPI_BSPIM */
RP2040_SPI_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
RP2040_SPI_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB07_08_CTL
RP2040_SPI_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB07_08_CTL
RP2040_SPI_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB07_08_CTL
RP2040_SPI_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB07_08_CTL
RP2040_SPI_BSPIM_BitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB07_08_MSK
RP2040_SPI_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB07_08_MSK
RP2040_SPI_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB07_08_MSK
RP2040_SPI_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB07_08_MSK
RP2040_SPI_BSPIM_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
RP2040_SPI_BSPIM_BitCounter__CONTROL_REG EQU CYREG_B0_UDB07_CTL
RP2040_SPI_BSPIM_BitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB07_ST_CTL
RP2040_SPI_BSPIM_BitCounter__COUNT_REG EQU CYREG_B0_UDB07_CTL
RP2040_SPI_BSPIM_BitCounter__COUNT_ST_REG EQU CYREG_B0_UDB07_ST_CTL
RP2040_SPI_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_BitCounter__PERIOD_REG EQU CYREG_B0_UDB07_MSK
RP2040_SPI_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
RP2040_SPI_BSPIM_BitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB07_08_ST
RP2040_SPI_BSPIM_BitCounter_ST__MASK_REG EQU CYREG_B0_UDB07_MSK
RP2040_SPI_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
RP2040_SPI_BSPIM_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB07_ST_CTL
RP2040_SPI_BSPIM_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB07_ST_CTL
RP2040_SPI_BSPIM_BitCounter_ST__STATUS_REG EQU CYREG_B0_UDB07_ST
RP2040_SPI_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
RP2040_SPI_BSPIM_RxStsReg__16BIT_STATUS_REG EQU CYREG_B1_UDB06_07_ST
RP2040_SPI_BSPIM_RxStsReg__4__MASK EQU 0x10
RP2040_SPI_BSPIM_RxStsReg__4__POS EQU 4
RP2040_SPI_BSPIM_RxStsReg__5__MASK EQU 0x20
RP2040_SPI_BSPIM_RxStsReg__5__POS EQU 5
RP2040_SPI_BSPIM_RxStsReg__6__MASK EQU 0x40
RP2040_SPI_BSPIM_RxStsReg__6__POS EQU 6
RP2040_SPI_BSPIM_RxStsReg__MASK EQU 0x70
RP2040_SPI_BSPIM_RxStsReg__MASK_REG EQU CYREG_B1_UDB06_MSK
RP2040_SPI_BSPIM_RxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
RP2040_SPI_BSPIM_RxStsReg__STATUS_REG EQU CYREG_B1_UDB06_ST
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_A0_REG EQU CYREG_B0_UDB07_08_A0
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_A1_REG EQU CYREG_B0_UDB07_08_A1
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_D0_REG EQU CYREG_B0_UDB07_08_D0
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_D1_REG EQU CYREG_B0_UDB07_08_D1
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB07_08_ACTL
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F0_REG EQU CYREG_B0_UDB07_08_F0
RP2040_SPI_BSPIM_sR8_Dp_u0__16BIT_F1_REG EQU CYREG_B0_UDB07_08_F1
RP2040_SPI_BSPIM_sR8_Dp_u0__A0_A1_REG EQU CYREG_B0_UDB07_A0_A1
RP2040_SPI_BSPIM_sR8_Dp_u0__A0_REG EQU CYREG_B0_UDB07_A0
RP2040_SPI_BSPIM_sR8_Dp_u0__A1_REG EQU CYREG_B0_UDB07_A1
RP2040_SPI_BSPIM_sR8_Dp_u0__D0_D1_REG EQU CYREG_B0_UDB07_D0_D1
RP2040_SPI_BSPIM_sR8_Dp_u0__D0_REG EQU CYREG_B0_UDB07_D0
RP2040_SPI_BSPIM_sR8_Dp_u0__D1_REG EQU CYREG_B0_UDB07_D1
RP2040_SPI_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB07_ACTL
RP2040_SPI_BSPIM_sR8_Dp_u0__F0_F1_REG EQU CYREG_B0_UDB07_F0_F1
RP2040_SPI_BSPIM_sR8_Dp_u0__F0_REG EQU CYREG_B0_UDB07_F0
RP2040_SPI_BSPIM_sR8_Dp_u0__F1_REG EQU CYREG_B0_UDB07_F1
RP2040_SPI_BSPIM_sR8_Dp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_sR8_Dp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB07_MSK_ACTL
RP2040_SPI_BSPIM_TxStsReg__0__MASK EQU 0x01
RP2040_SPI_BSPIM_TxStsReg__0__POS EQU 0
RP2040_SPI_BSPIM_TxStsReg__1__MASK EQU 0x02
RP2040_SPI_BSPIM_TxStsReg__1__POS EQU 1
RP2040_SPI_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
RP2040_SPI_BSPIM_TxStsReg__16BIT_STATUS_REG EQU CYREG_B1_UDB07_08_ST
RP2040_SPI_BSPIM_TxStsReg__2__MASK EQU 0x04
RP2040_SPI_BSPIM_TxStsReg__2__POS EQU 2
RP2040_SPI_BSPIM_TxStsReg__3__MASK EQU 0x08
RP2040_SPI_BSPIM_TxStsReg__3__POS EQU 3
RP2040_SPI_BSPIM_TxStsReg__4__MASK EQU 0x10
RP2040_SPI_BSPIM_TxStsReg__4__POS EQU 4
RP2040_SPI_BSPIM_TxStsReg__MASK EQU 0x1F
RP2040_SPI_BSPIM_TxStsReg__MASK_REG EQU CYREG_B1_UDB07_MSK
RP2040_SPI_BSPIM_TxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
RP2040_SPI_BSPIM_TxStsReg__STATUS_REG EQU CYREG_B1_UDB07_ST

/* RP2040_SPI_IntClock */
RP2040_SPI_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
RP2040_SPI_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
RP2040_SPI_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
RP2040_SPI_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
RP2040_SPI_IntClock__INDEX EQU 0x01
RP2040_SPI_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
RP2040_SPI_IntClock__PM_ACT_MSK EQU 0x02
RP2040_SPI_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
RP2040_SPI_IntClock__PM_STBY_MSK EQU 0x02

/* RP2040_SPI_MISO_Pin */
RP2040_SPI_MISO_Pin__0__INTTYPE EQU CYREG_PICU3_INTTYPE4
RP2040_SPI_MISO_Pin__0__MASK EQU 0x10
RP2040_SPI_MISO_Pin__0__PC EQU CYREG_PRT3_PC4
RP2040_SPI_MISO_Pin__0__PORT EQU 3
RP2040_SPI_MISO_Pin__0__SHIFT EQU 4
RP2040_SPI_MISO_Pin__AG EQU CYREG_PRT3_AG
RP2040_SPI_MISO_Pin__AMUX EQU CYREG_PRT3_AMUX
RP2040_SPI_MISO_Pin__BIE EQU CYREG_PRT3_BIE
RP2040_SPI_MISO_Pin__BIT_MASK EQU CYREG_PRT3_BIT_MASK
RP2040_SPI_MISO_Pin__BYP EQU CYREG_PRT3_BYP
RP2040_SPI_MISO_Pin__CTL EQU CYREG_PRT3_CTL
RP2040_SPI_MISO_Pin__DM0 EQU CYREG_PRT3_DM0
RP2040_SPI_MISO_Pin__DM1 EQU CYREG_PRT3_DM1
RP2040_SPI_MISO_Pin__DM2 EQU CYREG_PRT3_DM2
RP2040_SPI_MISO_Pin__DR EQU CYREG_PRT3_DR
RP2040_SPI_MISO_Pin__INP_DIS EQU CYREG_PRT3_INP_DIS
RP2040_SPI_MISO_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
RP2040_SPI_MISO_Pin__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
RP2040_SPI_MISO_Pin__LCD_EN EQU CYREG_PRT3_LCD_EN
RP2040_SPI_MISO_Pin__MASK EQU 0x10
RP2040_SPI_MISO_Pin__PORT EQU 3
RP2040_SPI_MISO_Pin__PRT EQU CYREG_PRT3_PRT
RP2040_SPI_MISO_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
RP2040_SPI_MISO_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
RP2040_SPI_MISO_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
RP2040_SPI_MISO_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
RP2040_SPI_MISO_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
RP2040_SPI_MISO_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
RP2040_SPI_MISO_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
RP2040_SPI_MISO_Pin__PS EQU CYREG_PRT3_PS
RP2040_SPI_MISO_Pin__SHIFT EQU 4
RP2040_SPI_MISO_Pin__SLW EQU CYREG_PRT3_SLW

/* RP2040_SPI_MOSI_Pin */
RP2040_SPI_MOSI_Pin__0__INTTYPE EQU CYREG_PICU3_INTTYPE1
RP2040_SPI_MOSI_Pin__0__MASK EQU 0x02
RP2040_SPI_MOSI_Pin__0__PC EQU CYREG_PRT3_PC1
RP2040_SPI_MOSI_Pin__0__PORT EQU 3
RP2040_SPI_MOSI_Pin__0__SHIFT EQU 1
RP2040_SPI_MOSI_Pin__AG EQU CYREG_PRT3_AG
RP2040_SPI_MOSI_Pin__AMUX EQU CYREG_PRT3_AMUX
RP2040_SPI_MOSI_Pin__BIE EQU CYREG_PRT3_BIE
RP2040_SPI_MOSI_Pin__BIT_MASK EQU CYREG_PRT3_BIT_MASK
RP2040_SPI_MOSI_Pin__BYP EQU CYREG_PRT3_BYP
RP2040_SPI_MOSI_Pin__CTL EQU CYREG_PRT3_CTL
RP2040_SPI_MOSI_Pin__DM0 EQU CYREG_PRT3_DM0
RP2040_SPI_MOSI_Pin__DM1 EQU CYREG_PRT3_DM1
RP2040_SPI_MOSI_Pin__DM2 EQU CYREG_PRT3_DM2
RP2040_SPI_MOSI_Pin__DR EQU CYREG_PRT3_DR
RP2040_SPI_MOSI_Pin__INP_DIS EQU CYREG_PRT3_INP_DIS
RP2040_SPI_MOSI_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
RP2040_SPI_MOSI_Pin__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
RP2040_SPI_MOSI_Pin__LCD_EN EQU CYREG_PRT3_LCD_EN
RP2040_SPI_MOSI_Pin__MASK EQU 0x02
RP2040_SPI_MOSI_Pin__PORT EQU 3
RP2040_SPI_MOSI_Pin__PRT EQU CYREG_PRT3_PRT
RP2040_SPI_MOSI_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
RP2040_SPI_MOSI_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
RP2040_SPI_MOSI_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
RP2040_SPI_MOSI_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
RP2040_SPI_MOSI_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
RP2040_SPI_MOSI_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
RP2040_SPI_MOSI_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
RP2040_SPI_MOSI_Pin__PS EQU CYREG_PRT3_PS
RP2040_SPI_MOSI_Pin__SHIFT EQU 1
RP2040_SPI_MOSI_Pin__SLW EQU CYREG_PRT3_SLW

/* RP2040_SPI_SCK_Pin */
RP2040_SPI_SCK_Pin__0__INTTYPE EQU CYREG_PICU3_INTTYPE0
RP2040_SPI_SCK_Pin__0__MASK EQU 0x01
RP2040_SPI_SCK_Pin__0__PC EQU CYREG_PRT3_PC0
RP2040_SPI_SCK_Pin__0__PORT EQU 3
RP2040_SPI_SCK_Pin__0__SHIFT EQU 0
RP2040_SPI_SCK_Pin__AG EQU CYREG_PRT3_AG
RP2040_SPI_SCK_Pin__AMUX EQU CYREG_PRT3_AMUX
RP2040_SPI_SCK_Pin__BIE EQU CYREG_PRT3_BIE
RP2040_SPI_SCK_Pin__BIT_MASK EQU CYREG_PRT3_BIT_MASK
RP2040_SPI_SCK_Pin__BYP EQU CYREG_PRT3_BYP
RP2040_SPI_SCK_Pin__CTL EQU CYREG_PRT3_CTL
RP2040_SPI_SCK_Pin__DM0 EQU CYREG_PRT3_DM0
RP2040_SPI_SCK_Pin__DM1 EQU CYREG_PRT3_DM1
RP2040_SPI_SCK_Pin__DM2 EQU CYREG_PRT3_DM2
RP2040_SPI_SCK_Pin__DR EQU CYREG_PRT3_DR
RP2040_SPI_SCK_Pin__INP_DIS EQU CYREG_PRT3_INP_DIS
RP2040_SPI_SCK_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
RP2040_SPI_SCK_Pin__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
RP2040_SPI_SCK_Pin__LCD_EN EQU CYREG_PRT3_LCD_EN
RP2040_SPI_SCK_Pin__MASK EQU 0x01
RP2040_SPI_SCK_Pin__PORT EQU 3
RP2040_SPI_SCK_Pin__PRT EQU CYREG_PRT3_PRT
RP2040_SPI_SCK_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
RP2040_SPI_SCK_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
RP2040_SPI_SCK_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
RP2040_SPI_SCK_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
RP2040_SPI_SCK_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
RP2040_SPI_SCK_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
RP2040_SPI_SCK_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
RP2040_SPI_SCK_Pin__PS EQU CYREG_PRT3_PS
RP2040_SPI_SCK_Pin__SHIFT EQU 0
RP2040_SPI_SCK_Pin__SLW EQU CYREG_PRT3_SLW

/* Action0_Btn */
Action0_Btn__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Action0_Btn__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Action0_Btn__INTC_MASK EQU 0x01
Action0_Btn__INTC_NUMBER EQU 0
Action0_Btn__INTC_PRIOR_NUM EQU 7
Action0_Btn__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
Action0_Btn__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Action0_Btn__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Action0_Btn_Pin */
Action0_Btn_Pin__0__INTTYPE EQU CYREG_PICU1_INTTYPE3
Action0_Btn_Pin__0__MASK EQU 0x08
Action0_Btn_Pin__0__PC EQU CYREG_PRT1_PC3
Action0_Btn_Pin__0__PORT EQU 1
Action0_Btn_Pin__0__SHIFT EQU 3
Action0_Btn_Pin__AG EQU CYREG_PRT1_AG
Action0_Btn_Pin__AMUX EQU CYREG_PRT1_AMUX
Action0_Btn_Pin__BIE EQU CYREG_PRT1_BIE
Action0_Btn_Pin__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Action0_Btn_Pin__BYP EQU CYREG_PRT1_BYP
Action0_Btn_Pin__CTL EQU CYREG_PRT1_CTL
Action0_Btn_Pin__DM0 EQU CYREG_PRT1_DM0
Action0_Btn_Pin__DM1 EQU CYREG_PRT1_DM1
Action0_Btn_Pin__DM2 EQU CYREG_PRT1_DM2
Action0_Btn_Pin__DR EQU CYREG_PRT1_DR
Action0_Btn_Pin__INP_DIS EQU CYREG_PRT1_INP_DIS
Action0_Btn_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Action0_Btn_Pin__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Action0_Btn_Pin__LCD_EN EQU CYREG_PRT1_LCD_EN
Action0_Btn_Pin__MASK EQU 0x08
Action0_Btn_Pin__PORT EQU 1
Action0_Btn_Pin__PRT EQU CYREG_PRT1_PRT
Action0_Btn_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Action0_Btn_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Action0_Btn_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Action0_Btn_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Action0_Btn_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Action0_Btn_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Action0_Btn_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Action0_Btn_Pin__PS EQU CYREG_PRT1_PS
Action0_Btn_Pin__SHIFT EQU 3
Action0_Btn_Pin__SLW EQU CYREG_PRT1_SLW

/* Action1_Btn */
Action1_Btn__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Action1_Btn__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Action1_Btn__INTC_MASK EQU 0x02
Action1_Btn__INTC_NUMBER EQU 1
Action1_Btn__INTC_PRIOR_NUM EQU 7
Action1_Btn__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
Action1_Btn__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Action1_Btn__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Action1_Btn_Pin */
Action1_Btn_Pin__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
Action1_Btn_Pin__0__MASK EQU 0x10
Action1_Btn_Pin__0__PC EQU CYREG_PRT1_PC4
Action1_Btn_Pin__0__PORT EQU 1
Action1_Btn_Pin__0__SHIFT EQU 4
Action1_Btn_Pin__AG EQU CYREG_PRT1_AG
Action1_Btn_Pin__AMUX EQU CYREG_PRT1_AMUX
Action1_Btn_Pin__BIE EQU CYREG_PRT1_BIE
Action1_Btn_Pin__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Action1_Btn_Pin__BYP EQU CYREG_PRT1_BYP
Action1_Btn_Pin__CTL EQU CYREG_PRT1_CTL
Action1_Btn_Pin__DM0 EQU CYREG_PRT1_DM0
Action1_Btn_Pin__DM1 EQU CYREG_PRT1_DM1
Action1_Btn_Pin__DM2 EQU CYREG_PRT1_DM2
Action1_Btn_Pin__DR EQU CYREG_PRT1_DR
Action1_Btn_Pin__INP_DIS EQU CYREG_PRT1_INP_DIS
Action1_Btn_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Action1_Btn_Pin__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Action1_Btn_Pin__LCD_EN EQU CYREG_PRT1_LCD_EN
Action1_Btn_Pin__MASK EQU 0x10
Action1_Btn_Pin__PORT EQU 1
Action1_Btn_Pin__PRT EQU CYREG_PRT1_PRT
Action1_Btn_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Action1_Btn_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Action1_Btn_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Action1_Btn_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Action1_Btn_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Action1_Btn_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Action1_Btn_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Action1_Btn_Pin__PS EQU CYREG_PRT1_PS
Action1_Btn_Pin__SHIFT EQU 4
Action1_Btn_Pin__SLW EQU CYREG_PRT1_SLW

/* GameTimeReg */
GameTimeReg_sts_sts_reg__0__MASK EQU 0x01
GameTimeReg_sts_sts_reg__0__POS EQU 0
GameTimeReg_sts_sts_reg__1__MASK EQU 0x02
GameTimeReg_sts_sts_reg__1__POS EQU 1
GameTimeReg_sts_sts_reg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
GameTimeReg_sts_sts_reg__16BIT_STATUS_REG EQU CYREG_B0_UDB08_09_ST
GameTimeReg_sts_sts_reg__2__MASK EQU 0x04
GameTimeReg_sts_sts_reg__2__POS EQU 2
GameTimeReg_sts_sts_reg__3__MASK EQU 0x08
GameTimeReg_sts_sts_reg__3__POS EQU 3
GameTimeReg_sts_sts_reg__4__MASK EQU 0x10
GameTimeReg_sts_sts_reg__4__POS EQU 4
GameTimeReg_sts_sts_reg__5__MASK EQU 0x20
GameTimeReg_sts_sts_reg__5__POS EQU 5
GameTimeReg_sts_sts_reg__6__MASK EQU 0x40
GameTimeReg_sts_sts_reg__6__POS EQU 6
GameTimeReg_sts_sts_reg__7__MASK EQU 0x80
GameTimeReg_sts_sts_reg__7__POS EQU 7
GameTimeReg_sts_sts_reg__MASK EQU 0xFF
GameTimeReg_sts_sts_reg__MASK_REG EQU CYREG_B0_UDB08_MSK
GameTimeReg_sts_sts_reg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
GameTimeReg_sts_sts_reg__STATUS_REG EQU CYREG_B0_UDB08_ST

/* Joystick_Btn */
Joystick_Btn__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Joystick_Btn__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Joystick_Btn__INTC_MASK EQU 0x04
Joystick_Btn__INTC_NUMBER EQU 2
Joystick_Btn__INTC_PRIOR_NUM EQU 7
Joystick_Btn__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
Joystick_Btn__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Joystick_Btn__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Joystick_Btn_Pin */
Joystick_Btn_Pin__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
Joystick_Btn_Pin__0__MASK EQU 0x04
Joystick_Btn_Pin__0__PC EQU CYREG_PRT1_PC2
Joystick_Btn_Pin__0__PORT EQU 1
Joystick_Btn_Pin__0__SHIFT EQU 2
Joystick_Btn_Pin__AG EQU CYREG_PRT1_AG
Joystick_Btn_Pin__AMUX EQU CYREG_PRT1_AMUX
Joystick_Btn_Pin__BIE EQU CYREG_PRT1_BIE
Joystick_Btn_Pin__BIT_MASK EQU CYREG_PRT1_BIT_MASK
Joystick_Btn_Pin__BYP EQU CYREG_PRT1_BYP
Joystick_Btn_Pin__CTL EQU CYREG_PRT1_CTL
Joystick_Btn_Pin__DM0 EQU CYREG_PRT1_DM0
Joystick_Btn_Pin__DM1 EQU CYREG_PRT1_DM1
Joystick_Btn_Pin__DM2 EQU CYREG_PRT1_DM2
Joystick_Btn_Pin__DR EQU CYREG_PRT1_DR
Joystick_Btn_Pin__INP_DIS EQU CYREG_PRT1_INP_DIS
Joystick_Btn_Pin__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
Joystick_Btn_Pin__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
Joystick_Btn_Pin__LCD_EN EQU CYREG_PRT1_LCD_EN
Joystick_Btn_Pin__MASK EQU 0x04
Joystick_Btn_Pin__PORT EQU 1
Joystick_Btn_Pin__PRT EQU CYREG_PRT1_PRT
Joystick_Btn_Pin__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
Joystick_Btn_Pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
Joystick_Btn_Pin__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
Joystick_Btn_Pin__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
Joystick_Btn_Pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
Joystick_Btn_Pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
Joystick_Btn_Pin__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
Joystick_Btn_Pin__PS EQU CYREG_PRT1_PS
Joystick_Btn_Pin__SHIFT EQU 2
Joystick_Btn_Pin__SLW EQU CYREG_PRT1_SLW

/* UART_KitProg_BUART */
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB08_09_CTL
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB08_09_CTL
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB08_09_CTL
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB08_09_CTL
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB08_09_MSK
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB08_09_MSK
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB08_09_MSK
UART_KitProg_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB08_09_MSK
UART_KitProg_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
UART_KitProg_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB08_CTL
UART_KitProg_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB08_ST_CTL
UART_KitProg_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB08_CTL
UART_KitProg_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB08_ST_CTL
UART_KitProg_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
UART_KitProg_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
UART_KitProg_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB08_MSK
UART_KitProg_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB08_09_ST
UART_KitProg_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB08_MSK
UART_KitProg_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB08_ST_CTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB08_ST_CTL
UART_KitProg_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB08_ST
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB07_08_A0
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB07_08_A1
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB07_08_D0
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB07_08_D1
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB07_08_F0
UART_KitProg_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB07_08_F1
UART_KitProg_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB07_A0_A1
UART_KitProg_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B1_UDB07_A0
UART_KitProg_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B1_UDB07_A1
UART_KitProg_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB07_D0_D1
UART_KitProg_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B1_UDB07_D0
UART_KitProg_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B1_UDB07_D1
UART_KitProg_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
UART_KitProg_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB07_F0_F1
UART_KitProg_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B1_UDB07_F0
UART_KitProg_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B1_UDB07_F1
UART_KitProg_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB04_05_ACTL
UART_KitProg_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB04_05_ST
UART_KitProg_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_KitProg_BUART_sRX_RxSts__3__POS EQU 3
UART_KitProg_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_KitProg_BUART_sRX_RxSts__4__POS EQU 4
UART_KitProg_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_KitProg_BUART_sRX_RxSts__5__POS EQU 5
UART_KitProg_BUART_sRX_RxSts__MASK EQU 0x38
UART_KitProg_BUART_sRX_RxSts__MASK_REG EQU CYREG_B1_UDB04_MSK
UART_KitProg_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB04_ACTL
UART_KitProg_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B1_UDB04_ST
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B1_UDB06_07_A0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B1_UDB06_07_A1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B1_UDB06_07_D0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B1_UDB06_07_D1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B1_UDB06_07_F0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B1_UDB06_07_F1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B1_UDB06_A0_A1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B1_UDB06_A0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B1_UDB06_A1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B1_UDB06_D0_D1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B1_UDB06_D0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B1_UDB06_D1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B1_UDB06_F0_F1
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B1_UDB06_F0
UART_KitProg_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B1_UDB06_F1
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB05_06_A0
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB05_06_A1
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB05_06_D0
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB05_06_D1
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB05_06_F0
UART_KitProg_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB05_06_F1
UART_KitProg_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB05_A0_A1
UART_KitProg_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B1_UDB05_A0
UART_KitProg_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B1_UDB05_A1
UART_KitProg_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB05_D0_D1
UART_KitProg_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B1_UDB05_D0
UART_KitProg_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B1_UDB05_D1
UART_KitProg_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
UART_KitProg_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB05_F0_F1
UART_KitProg_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B1_UDB05_F0
UART_KitProg_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B1_UDB05_F1
UART_KitProg_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_KitProg_BUART_sTX_TxSts__0__POS EQU 0
UART_KitProg_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_KitProg_BUART_sTX_TxSts__1__POS EQU 1
UART_KitProg_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
UART_KitProg_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB05_06_ST
UART_KitProg_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_KitProg_BUART_sTX_TxSts__2__POS EQU 2
UART_KitProg_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_KitProg_BUART_sTX_TxSts__3__POS EQU 3
UART_KitProg_BUART_sTX_TxSts__MASK EQU 0x0F
UART_KitProg_BUART_sTX_TxSts__MASK_REG EQU CYREG_B1_UDB05_MSK
UART_KitProg_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
UART_KitProg_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B1_UDB05_ST

/* UART_KitProg_IntClock */
UART_KitProg_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
UART_KitProg_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
UART_KitProg_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
UART_KitProg_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_KitProg_IntClock__INDEX EQU 0x00
UART_KitProg_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_KitProg_IntClock__PM_ACT_MSK EQU 0x01
UART_KitProg_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_KitProg_IntClock__PM_STBY_MSK EQU 0x01

/* DebounceClock */
DebounceClock__CFG0 EQU CYREG_CLKDIST_DCFG5_CFG0
DebounceClock__CFG1 EQU CYREG_CLKDIST_DCFG5_CFG1
DebounceClock__CFG2 EQU CYREG_CLKDIST_DCFG5_CFG2
DebounceClock__CFG2_SRC_SEL_MASK EQU 0x07
DebounceClock__INDEX EQU 0x05
DebounceClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
DebounceClock__PM_ACT_MSK EQU 0x20
DebounceClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
DebounceClock__PM_STBY_MSK EQU 0x20

/* GameTimeClock */
GameTimeClock__CFG0 EQU CYREG_CLKDIST_DCFG4_CFG0
GameTimeClock__CFG1 EQU CYREG_CLKDIST_DCFG4_CFG1
GameTimeClock__CFG2 EQU CYREG_CLKDIST_DCFG4_CFG2
GameTimeClock__CFG2_SRC_SEL_MASK EQU 0x07
GameTimeClock__INDEX EQU 0x04
GameTimeClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
GameTimeClock__PM_ACT_MSK EQU 0x10
GameTimeClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
GameTimeClock__PM_STBY_MSK EQU 0x10

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 19
CYDEV_CHIP_DIE_PSOC4A EQU 11
CYDEV_CHIP_DIE_PSOC5LP EQU 18
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 11
CYDEV_CHIP_MEMBER_4C EQU 16
CYDEV_CHIP_MEMBER_4D EQU 7
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 12
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 10
CYDEV_CHIP_MEMBER_4I EQU 15
CYDEV_CHIP_MEMBER_4J EQU 8
CYDEV_CHIP_MEMBER_4K EQU 9
CYDEV_CHIP_MEMBER_4L EQU 14
CYDEV_CHIP_MEMBER_4M EQU 13
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 18
CYDEV_CHIP_MEMBER_5B EQU 17
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_Disable
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x0000001F
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
