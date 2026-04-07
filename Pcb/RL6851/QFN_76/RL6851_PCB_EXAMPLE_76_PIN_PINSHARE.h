/********************************************************************************/
/*   Copyright (c) 2021 Realtek Semiconductor Corp. All rights reserved.        */
/*                                                                              */
/*   SPDX-License-Identifier: LicenseRef-Realtek-Proprietary                    */
/*                                                                              */
/*   This software component is confidential and proprietary to Realtek         */
/*   Semiconductor Corp. Disclosure, reproduction, redistribution, in whole     */
/*   or in part, of this work and its derivatives without express permission    */
/*   is prohibited.                                                             */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6851_PCB_EXAMPLE_76_PIN_PINSHARE.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


///////////////
// PCB Mode  //
///////////////

//---------------------------------------------------------------------------
// PCB Rule Select
//---------------------------------------------------------------------------
#define _PCB_NEW_MODE_SUPPORT                   _ON


////////////////////////////////
// RL6851 Series 76 Pin Share //
////////////////////////////////

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1002
// MCU Ctrl : 0xFFE2[2] at _76PIN_PIN_21_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_21                           (_76PIN_PIN_21_NC)

typedef enum
{
    _76PIN_PIN_21_GPI = 0x00,
    _76PIN_PIN_21_GPO_PP = 0x01,
    _76PIN_PIN_21_GPO_OD = 0x02,
    _76PIN_PIN_21_PWM0_PP = 0x03,
    _76PIN_PIN_21_PWM0_OD = 0x04,
    _76PIN_PIN_21_MCK = 0x05,
    _76PIN_PIN_21_CLKO = 0x06,
    _76PIN_PIN_21_TCON9 = 0x07,
    _76PIN_PIN_21_TEST12B_OUT0 = 0x08,
    _76PIN_PIN_21_TEST12B_OUT1 = 0x09,
    _76PIN_PIN_21_TEST12B_OUT2 = 0x0A,
    _76PIN_PIN_21_TEST12B_OUT3 = 0x0B,
    _76PIN_PIN_21_TEST12B_OUT4 = 0x0C,
    _76PIN_PIN_21_TEST12B_OUT5 = 0x0D,
    _76PIN_PIN_21_TEST12B_OUT6 = 0x0E,
    _76PIN_PIN_21_TEST12B_OUT7 = 0x0F,
    _76PIN_PIN_21_TEST12B_OUT8 = 0x10,
    _76PIN_PIN_21_TEST12B_OUT9 = 0x11,
    _76PIN_PIN_21_TEST12B_OUT10 = 0x12,
    _76PIN_PIN_21_TEST12B_OUT11 = 0x13,
    _76PIN_PIN_21_TTS_CEB = 0x14,
    _76PIN_PIN_21_NC = _76PIN_PIN_21_GPO_PP,
} EnumPinshareInfo76PIN_PIN_21;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1003
// MCU Ctrl : 0xFFE2[3] at _76PIN_PIN_22_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_22                           (_76PIN_PIN_22_NC)

typedef enum
{
    _76PIN_PIN_22_GPI = 0x00,
    _76PIN_PIN_22_GPO_PP = 0x01,
    _76PIN_PIN_22_GPO_OD = 0x02,
    _76PIN_PIN_22_PWM1_PP = 0x03,
    _76PIN_PIN_22_PWM1_OD = 0x04,
    _76PIN_PIN_22_IICSCL_0_3 = 0x05,
    _76PIN_PIN_22_SCK = 0x06,
    _76PIN_PIN_22_IRQB = 0x07,
    _76PIN_PIN_22_TCON13 = 0x08,
    _76PIN_PIN_22_TEST12B_OUT0 = 0x09,
    _76PIN_PIN_22_TEST12B_OUT1 = 0x0A,
    _76PIN_PIN_22_TEST12B_OUT2 = 0x0B,
    _76PIN_PIN_22_TEST12B_OUT3 = 0x0C,
    _76PIN_PIN_22_TEST12B_OUT4 = 0x0D,
    _76PIN_PIN_22_TEST12B_OUT5 = 0x0E,
    _76PIN_PIN_22_TEST12B_OUT6 = 0x0F,
    _76PIN_PIN_22_TEST12B_OUT7 = 0x10,
    _76PIN_PIN_22_TEST12B_OUT8 = 0x11,
    _76PIN_PIN_22_TEST12B_OUT9 = 0x12,
    _76PIN_PIN_22_TEST12B_OUT10 = 0x13,
    _76PIN_PIN_22_TEST12B_OUT11 = 0x14,
    _76PIN_PIN_22_NC = _76PIN_PIN_22_GPO_PP,
} EnumPinshareInfo76PIN_PIN_22;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1004
// MCU Ctrl : 0xFFE2[4] at _76PIN_PIN_23_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_23                           (_76PIN_PIN_23_NC)

typedef enum
{
    _76PIN_PIN_23_GPI = 0x00,
    _76PIN_PIN_23_GPO_PP = 0x01,
    _76PIN_PIN_23_GPO_OD = 0x02,
    _76PIN_PIN_23_PWM2_PP = 0x03,
    _76PIN_PIN_23_PWM2_OD = 0x04,
    _76PIN_PIN_23_IICSDA_0_3 = 0x05,
    _76PIN_PIN_23_CLKO = 0x06,
    _76PIN_PIN_23_WS = 0x08,
    _76PIN_PIN_23_TCON13 = 0x09,
    _76PIN_PIN_23_TEST12B_OUT0 = 0x0A,
    _76PIN_PIN_23_TEST12B_OUT1 = 0x0B,
    _76PIN_PIN_23_TEST12B_OUT2 = 0x0C,
    _76PIN_PIN_23_TEST12B_OUT3 = 0x0D,
    _76PIN_PIN_23_TEST12B_OUT4 = 0x0E,
    _76PIN_PIN_23_TEST12B_OUT5 = 0x0F,
    _76PIN_PIN_23_TEST12B_OUT6 = 0x10,
    _76PIN_PIN_23_TEST12B_OUT7 = 0x11,
    _76PIN_PIN_23_TEST12B_OUT8 = 0x12,
    _76PIN_PIN_23_TEST12B_OUT9 = 0x13,
    _76PIN_PIN_23_TEST12B_OUT10 = 0x14,
    _76PIN_PIN_23_TEST12B_OUT11 = 0x15,
    _76PIN_PIN_23_NC = _76PIN_PIN_23_GPO_PP,
} EnumPinshareInfo76PIN_PIN_23;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1005
// MCU Ctrl : 0xFFE2[5] at _76PIN_PIN_24_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_24                           (_76PIN_PIN_24_NC)

typedef enum
{
    _76PIN_PIN_24_GPI = 0x00,
    _76PIN_PIN_24_GPO_PP = 0x01,
    _76PIN_PIN_24_GPO_OD = 0x02,
    _76PIN_PIN_24_PWM3_PP = 0x03,
    _76PIN_PIN_24_PWM3_OD = 0x04,
    _76PIN_PIN_24_IICSCL_0_0 = 0x05,
    _76PIN_PIN_24_UART_RX_0_0 = 0x06,
    _76PIN_PIN_24_SD0 = 0x0A,
    _76PIN_PIN_24_SPDIF0 = 0x0B,
    _76PIN_PIN_24_TCON11 = 0x0C,
    _76PIN_PIN_24_TEST12B_OUT0 = 0x0D,
    _76PIN_PIN_24_TEST12B_OUT1 = 0x0E,
    _76PIN_PIN_24_TEST12B_OUT2 = 0x0F,
    _76PIN_PIN_24_TEST12B_OUT3 = 0x10,
    _76PIN_PIN_24_TEST12B_OUT4 = 0x11,
    _76PIN_PIN_24_TEST12B_OUT5 = 0x12,
    _76PIN_PIN_24_TEST12B_OUT6 = 0x13,
    _76PIN_PIN_24_TEST12B_OUT7 = 0x14,
    _76PIN_PIN_24_TEST12B_OUT8 = 0x15,
    _76PIN_PIN_24_TEST12B_OUT9 = 0x16,
    _76PIN_PIN_24_TEST12B_OUT10 = 0x17,
    _76PIN_PIN_24_TEST12B_OUT11 = 0x18,
    _76PIN_PIN_24_NC = _76PIN_PIN_24_GPO_PP,
} EnumPinshareInfo76PIN_PIN_24;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1008
// MCU Ctrl : 0xFFE3[0] at _76PIN_PIN_27_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_27                           (_76PIN_PIN_27_NC)

typedef enum
{
    _76PIN_PIN_27_GPI = 0x00,
    _76PIN_PIN_27_GPO_PP = 0x01,
    _76PIN_PIN_27_GPO_OD = 0x02,
    _76PIN_PIN_27_A_ADC_0 = 0x03,
    _76PIN_PIN_27_TCON9 = 0x04,
    _76PIN_PIN_27_TEST12B_OUT0 = 0x05,
    _76PIN_PIN_27_TEST12B_OUT1 = 0x06,
    _76PIN_PIN_27_TEST12B_OUT2 = 0x07,
    _76PIN_PIN_27_TEST12B_OUT3 = 0x08,
    _76PIN_PIN_27_TEST12B_OUT4 = 0x09,
    _76PIN_PIN_27_TEST12B_OUT5 = 0x0A,
    _76PIN_PIN_27_TEST12B_OUT6 = 0x0B,
    _76PIN_PIN_27_TEST12B_OUT7 = 0x0C,
    _76PIN_PIN_27_TEST12B_OUT8 = 0x0D,
    _76PIN_PIN_27_TEST12B_OUT9 = 0x0E,
    _76PIN_PIN_27_TEST12B_OUT10 = 0x0F,
    _76PIN_PIN_27_TEST12B_OUT11 = 0x10,
    _76PIN_PIN_27_NC = _76PIN_PIN_27_GPO_PP,
} EnumPinshareInfo76PIN_PIN_27;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1009
// MCU Ctrl : 0xFFE3[1] at _76PIN_PIN_28_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_28                           (_76PIN_PIN_28_NC)

typedef enum
{
    _76PIN_PIN_28_GPI = 0x00,
    _76PIN_PIN_28_GPO_PP = 0x01,
    _76PIN_PIN_28_GPO_OD = 0x02,
    _76PIN_PIN_28_A_ADC_1 = 0x03,
    _76PIN_PIN_28_TCON12 = 0x04,
    _76PIN_PIN_28_TEST12B_OUT0 = 0x05,
    _76PIN_PIN_28_TEST12B_OUT1 = 0x06,
    _76PIN_PIN_28_TEST12B_OUT2 = 0x07,
    _76PIN_PIN_28_TEST12B_OUT3 = 0x08,
    _76PIN_PIN_28_TEST12B_OUT4 = 0x09,
    _76PIN_PIN_28_TEST12B_OUT5 = 0x0A,
    _76PIN_PIN_28_TEST12B_OUT6 = 0x0B,
    _76PIN_PIN_28_TEST12B_OUT7 = 0x0C,
    _76PIN_PIN_28_TEST12B_OUT8 = 0x0D,
    _76PIN_PIN_28_TEST12B_OUT9 = 0x0E,
    _76PIN_PIN_28_TEST12B_OUT10 = 0x0F,
    _76PIN_PIN_28_TEST12B_OUT11 = 0x10,
    _76PIN_PIN_28_NC = _76PIN_PIN_28_GPO_PP,
} EnumPinshareInfo76PIN_PIN_28;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100A
// MCU Ctrl : 0xFFE3[2] at _76PIN_PIN_29_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_29                           (_76PIN_PIN_29_NC)

typedef enum
{
    _76PIN_PIN_29_GPI = 0x00,
    _76PIN_PIN_29_GPO_PP = 0x01,
    _76PIN_PIN_29_GPO_OD = 0x02,
    _76PIN_PIN_29_A_ADC_2 = 0x03,
    _76PIN_PIN_29_TEST12B_OUT0 = 0x04,
    _76PIN_PIN_29_TEST12B_OUT1 = 0x05,
    _76PIN_PIN_29_TEST12B_OUT2 = 0x06,
    _76PIN_PIN_29_TEST12B_OUT3 = 0x07,
    _76PIN_PIN_29_TEST12B_OUT4 = 0x08,
    _76PIN_PIN_29_TEST12B_OUT5 = 0x09,
    _76PIN_PIN_29_TEST12B_OUT6 = 0x0A,
    _76PIN_PIN_29_TEST12B_OUT7 = 0x0B,
    _76PIN_PIN_29_TEST12B_OUT8 = 0x0C,
    _76PIN_PIN_29_TEST12B_OUT9 = 0x0D,
    _76PIN_PIN_29_TEST12B_OUT10 = 0x0E,
    _76PIN_PIN_29_TEST12B_OUT11 = 0x0F,
    _76PIN_PIN_29_NC = _76PIN_PIN_29_GPO_PP,
} EnumPinshareInfo76PIN_PIN_29;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100C
// MCU Ctrl : 0xFFE3[4] at _76PIN_PIN_30_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_30                           (_76PIN_PIN_30_NC)

typedef enum
{
    _76PIN_PIN_30_GPI = 0x00,
    _76PIN_PIN_30_GPO_PP = 0x01,
    _76PIN_PIN_30_GPO_OD = 0x02,
    _76PIN_PIN_30_PWM1_PP = 0x03,
    _76PIN_PIN_30_PWM1_OD = 0x04,
    _76PIN_PIN_30_TCON7 = 0x05,
    _76PIN_PIN_30_TCON13 = 0x06,
    _76PIN_PIN_30_TEST12B_OUT0 = 0x07,
    _76PIN_PIN_30_TEST12B_OUT1 = 0x08,
    _76PIN_PIN_30_TEST12B_OUT2 = 0x09,
    _76PIN_PIN_30_TEST12B_OUT3 = 0x0A,
    _76PIN_PIN_30_TEST12B_OUT4 = 0x0B,
    _76PIN_PIN_30_TEST12B_OUT5 = 0x0C,
    _76PIN_PIN_30_TEST12B_OUT6 = 0x0D,
    _76PIN_PIN_30_TEST12B_OUT7 = 0x0E,
    _76PIN_PIN_30_TEST12B_OUT8 = 0x0F,
    _76PIN_PIN_30_TEST12B_OUT9 = 0x10,
    _76PIN_PIN_30_TEST12B_OUT10 = 0x11,
    _76PIN_PIN_30_TEST12B_OUT11 = 0x12,
    _76PIN_PIN_30_TTS_SCLK = 0x13,
    _76PIN_PIN_30_NC = _76PIN_PIN_30_GPO_PP,
} EnumPinshareInfo76PIN_PIN_30;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100D
// MCU Ctrl : 0xFFE3[5] at _76PIN_PIN_31_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_31                           (_76PIN_PIN_31_NC)

typedef enum
{
    _76PIN_PIN_31_GPI = 0x00,
    _76PIN_PIN_31_GPO_PP = 0x01,
    _76PIN_PIN_31_GPO_OD = 0x02,
    _76PIN_PIN_31_EEIICSCL = 0x03,
    _76PIN_PIN_31_IICSCL_AUX = 0x04,
    _76PIN_PIN_31_TCON8 = 0x05,
    _76PIN_PIN_31_TCON12 = 0x06,
    _76PIN_PIN_31_TEST12B_OUT0 = 0x07,
    _76PIN_PIN_31_TEST12B_OUT1 = 0x08,
    _76PIN_PIN_31_TEST12B_OUT2 = 0x09,
    _76PIN_PIN_31_TEST12B_OUT3 = 0x0A,
    _76PIN_PIN_31_TEST12B_OUT4 = 0x0B,
    _76PIN_PIN_31_TEST12B_OUT5 = 0x0C,
    _76PIN_PIN_31_TEST12B_OUT6 = 0x0D,
    _76PIN_PIN_31_TEST12B_OUT7 = 0x0E,
    _76PIN_PIN_31_TEST12B_OUT8 = 0x0F,
    _76PIN_PIN_31_TEST12B_OUT9 = 0x10,
    _76PIN_PIN_31_TEST12B_OUT10 = 0x11,
    _76PIN_PIN_31_TEST12B_OUT11 = 0x12,
    _76PIN_PIN_31_NC = _76PIN_PIN_31_GPO_PP,
} EnumPinshareInfo76PIN_PIN_31;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100E
// MCU Ctrl : 0xFFE3[6] at _76PIN_PIN_32_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_32                           (_76PIN_PIN_32_NC)

typedef enum
{
    _76PIN_PIN_32_GPI = 0x00,
    _76PIN_PIN_32_GPO_PP = 0x01,
    _76PIN_PIN_32_GPO_OD = 0x02,
    _76PIN_PIN_32_EEIICSDA = 0x03,
    _76PIN_PIN_32_IICSDA_AUX = 0x04,
    _76PIN_PIN_32_TEST12B_OUT0 = 0x05,
    _76PIN_PIN_32_TEST12B_OUT1 = 0x06,
    _76PIN_PIN_32_TEST12B_OUT2 = 0x07,
    _76PIN_PIN_32_TEST12B_OUT3 = 0x08,
    _76PIN_PIN_32_TEST12B_OUT4 = 0x09,
    _76PIN_PIN_32_TEST12B_OUT5 = 0x0A,
    _76PIN_PIN_32_TEST12B_OUT6 = 0x0B,
    _76PIN_PIN_32_TEST12B_OUT7 = 0x0C,
    _76PIN_PIN_32_TEST12B_OUT8 = 0x0D,
    _76PIN_PIN_32_TEST12B_OUT9 = 0x0E,
    _76PIN_PIN_32_TEST12B_OUT10 = 0x0F,
    _76PIN_PIN_32_TEST12B_OUT11 = 0x10,
    _76PIN_PIN_32_NC = _76PIN_PIN_32_GPO_PP,
} EnumPinshareInfo76PIN_PIN_32;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100F
// MCU Ctrl : 0xFFE3[7] at _76PIN_PIN_33_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_33                           (_76PIN_PIN_33_NC)

typedef enum
{
    _76PIN_PIN_33_GPI = 0x00,
    _76PIN_PIN_33_GPO_PP = 0x01,
    _76PIN_PIN_33_GPO_OD = 0x02,
    _76PIN_PIN_33_DDCSCL_ISP = 0x03,
    _76PIN_PIN_33_DDCSCL_VGA_0_0 = 0x04,
    _76PIN_PIN_33_UART_RX_0_1 = 0x05,
    _76PIN_PIN_33_TEST12B_OUT0 = 0x09,
    _76PIN_PIN_33_TEST12B_OUT1 = 0x0A,
    _76PIN_PIN_33_TEST12B_OUT2 = 0x0B,
    _76PIN_PIN_33_TEST12B_OUT3 = 0x0C,
    _76PIN_PIN_33_TEST12B_OUT4 = 0x0D,
    _76PIN_PIN_33_TEST12B_OUT5 = 0x0E,
    _76PIN_PIN_33_TEST12B_OUT6 = 0x0F,
    _76PIN_PIN_33_TEST12B_OUT7 = 0x10,
    _76PIN_PIN_33_TEST12B_OUT8 = 0x11,
    _76PIN_PIN_33_TEST12B_OUT9 = 0x12,
    _76PIN_PIN_33_TEST12B_OUT10 = 0x13,
    _76PIN_PIN_33_TEST12B_OUT11 = 0x14,
    _76PIN_PIN_33_NC = _76PIN_PIN_33_GPO_PP,
} EnumPinshareInfo76PIN_PIN_33;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1010
// MCU Ctrl : 0xFE00 at _76PIN_PIN_34_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_34                           (_76PIN_PIN_34_NC)

typedef enum
{
    _76PIN_PIN_34_GPI = 0x00,
    _76PIN_PIN_34_GPO_PP = 0x01,
    _76PIN_PIN_34_GPO_OD = 0x02,
    _76PIN_PIN_34_DDCSDA_ISP = 0x03,
    _76PIN_PIN_34_DDCSDA_VGA_0_0 = 0x04,
    _76PIN_PIN_34_UART_TX_0_1 = 0x05,
    _76PIN_PIN_34_TCON11 = 0x09,
    _76PIN_PIN_34_TCON13 = 0x0A,
    _76PIN_PIN_34_TEST12B_OUT0 = 0x0B,
    _76PIN_PIN_34_TEST12B_OUT1 = 0x0C,
    _76PIN_PIN_34_TEST12B_OUT2 = 0x0D,
    _76PIN_PIN_34_TEST12B_OUT3 = 0x0E,
    _76PIN_PIN_34_TEST12B_OUT4 = 0x0F,
    _76PIN_PIN_34_TEST12B_OUT5 = 0x10,
    _76PIN_PIN_34_TEST12B_OUT6 = 0x11,
    _76PIN_PIN_34_TEST12B_OUT7 = 0x12,
    _76PIN_PIN_34_TEST12B_OUT8 = 0x13,
    _76PIN_PIN_34_TEST12B_OUT9 = 0x14,
    _76PIN_PIN_34_TEST12B_OUT10 = 0x15,
    _76PIN_PIN_34_TEST12B_OUT11 = 0x16,
    _76PIN_PIN_34_NC = _76PIN_PIN_34_GPO_PP,
} EnumPinshareInfo76PIN_PIN_34;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1012
// MCU Ctrl : 0xFE02 at _76PIN_PIN_36_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_36                           (_76PIN_PIN_36_NC)

typedef enum
{
    _76PIN_PIN_36_GPI = 0x00,
    _76PIN_PIN_36_GPO_PP = 0x01,
    _76PIN_PIN_36_GPO_OD = 0x02,
    _76PIN_PIN_36_PWM3_PP = 0x03,
    _76PIN_PIN_36_PWM3_OD = 0x04,
    _76PIN_PIN_36_EDPTX_HPD_ORG_0 = 0x05,
    _76PIN_PIN_36_TCON12 = 0x06,
    _76PIN_PIN_36_TEST12B_OUT0 = 0x07,
    _76PIN_PIN_36_TEST12B_OUT1 = 0x08,
    _76PIN_PIN_36_TEST12B_OUT2 = 0x09,
    _76PIN_PIN_36_TEST12B_OUT3 = 0x0A,
    _76PIN_PIN_36_TEST12B_OUT4 = 0x0B,
    _76PIN_PIN_36_TEST12B_OUT5 = 0x0C,
    _76PIN_PIN_36_TEST12B_OUT6 = 0x0D,
    _76PIN_PIN_36_TEST12B_OUT7 = 0x0E,
    _76PIN_PIN_36_TEST12B_OUT8 = 0x0F,
    _76PIN_PIN_36_TEST12B_OUT9 = 0x10,
    _76PIN_PIN_36_TEST12B_OUT10 = 0x11,
    _76PIN_PIN_36_TEST12B_OUT11 = 0x12,
    _76PIN_PIN_36_NC = _76PIN_PIN_36_GPO_PP,
} EnumPinshareInfo76PIN_PIN_36;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101A
// MCU Ctrl : 0xFE0A at _76PIN_PIN_37_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_37                           (_76PIN_PIN_37_NC)

typedef enum
{
    _76PIN_PIN_37_GPI = 0x00,
    _76PIN_PIN_37_GPO_PP = 0x01,
    _76PIN_PIN_37_GPO_OD = 0x02,
    _76PIN_PIN_37_PWM0_PP = 0x03,
    _76PIN_PIN_37_PWM0_OD = 0x04,
    _76PIN_PIN_37_PWM_IN_0_1 = 0x05,
    _76PIN_PIN_37_CLKO = 0x06,
    _76PIN_PIN_37_INT1_0 = 0x07,
    _76PIN_PIN_37_T2 = 0x08,
    _76PIN_PIN_37_M1_IDOMAIN_HS_OUT = 0x09,
    _76PIN_PIN_37_TCON7 = 0x0A,
    _76PIN_PIN_37_TEST12B_OUT0 = 0x0B,
    _76PIN_PIN_37_TEST12B_OUT1 = 0x0C,
    _76PIN_PIN_37_TEST12B_OUT2 = 0x0D,
    _76PIN_PIN_37_TEST12B_OUT3 = 0x0E,
    _76PIN_PIN_37_TEST12B_OUT4 = 0x0F,
    _76PIN_PIN_37_TEST12B_OUT5 = 0x10,
    _76PIN_PIN_37_TEST12B_OUT6 = 0x11,
    _76PIN_PIN_37_TEST12B_OUT7 = 0x12,
    _76PIN_PIN_37_TEST12B_OUT8 = 0x13,
    _76PIN_PIN_37_TEST12B_OUT9 = 0x14,
    _76PIN_PIN_37_TEST12B_OUT10 = 0x15,
    _76PIN_PIN_37_TEST12B_OUT11 = 0x16,
    _76PIN_PIN_37_TTS_SI = 0x17,
    _76PIN_PIN_37_NC = _76PIN_PIN_37_GPO_PP,
} EnumPinshareInfo76PIN_PIN_37;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101B
// MCU Ctrl : 0xFE0B at _76PIN_PIN_38_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_38                           (_76PIN_PIN_38_NC)

typedef enum
{
    _76PIN_PIN_38_GPI = 0x00,
    _76PIN_PIN_38_GPO_PP = 0x01,
    _76PIN_PIN_38_GPO_OD = 0x02,
    _76PIN_PIN_38_PWM2_PP = 0x03,
    _76PIN_PIN_38_PWM2_OD = 0x04,
    _76PIN_PIN_38_PWM_OUT_0_1 = 0x05,
    _76PIN_PIN_38_CLKO = 0x06,
    _76PIN_PIN_38_INT0_0 = 0x07,
    _76PIN_PIN_38_M1_IDOMAIN_DEN_OUT = 0x08,
    _76PIN_PIN_38_TCON8 = 0x09,
    _76PIN_PIN_38_TEST12B_OUT0 = 0x0A,
    _76PIN_PIN_38_TEST12B_OUT1 = 0x0B,
    _76PIN_PIN_38_TEST12B_OUT2 = 0x0C,
    _76PIN_PIN_38_TEST12B_OUT3 = 0x0D,
    _76PIN_PIN_38_TEST12B_OUT4 = 0x0E,
    _76PIN_PIN_38_TEST12B_OUT5 = 0x0F,
    _76PIN_PIN_38_TEST12B_OUT6 = 0x10,
    _76PIN_PIN_38_TEST12B_OUT7 = 0x11,
    _76PIN_PIN_38_TEST12B_OUT8 = 0x12,
    _76PIN_PIN_38_TEST12B_OUT9 = 0x13,
    _76PIN_PIN_38_TEST12B_OUT10 = 0x14,
    _76PIN_PIN_38_TEST12B_OUT11 = 0x15,
    _76PIN_PIN_38_TTS_SO = 0x16,
    _76PIN_PIN_38_NC = _76PIN_PIN_38_GPO_PP,
} EnumPinshareInfo76PIN_PIN_38;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101E
// MCU Ctrl : 0xFE0E at _76PIN_PIN_47_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_47                           (_76PIN_PIN_47_NC)

typedef enum
{
    _76PIN_PIN_47_HI_Z = 0x00,
    _76PIN_PIN_47_GPI = 0x01,
    _76PIN_PIN_47_TXA3P_8B = 0x04,
    _76PIN_PIN_47_NC = _76PIN_PIN_47_GPI,
} EnumPinshareInfo76PIN_PIN_47;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101F
// MCU Ctrl : 0xFE0F at _76PIN_PIN_48_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_48                           (_76PIN_PIN_48_NC)

typedef enum
{
    _76PIN_PIN_48_HI_Z = 0x00,
    _76PIN_PIN_48_GPI = 0x01,
    _76PIN_PIN_48_TXA3N_8B = 0x04,
    _76PIN_PIN_48_NC = _76PIN_PIN_48_GPI,
} EnumPinshareInfo76PIN_PIN_48;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1020
// MCU Ctrl : 0xFE10 at _76PIN_PIN_49_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_49                           (_76PIN_PIN_49_NC)

typedef enum
{
    _76PIN_PIN_49_HI_Z = 0x00,
    _76PIN_PIN_49_GPI = 0x01,
    _76PIN_PIN_49_TXACP_8B = 0x04,
    _76PIN_PIN_49_NC = _76PIN_PIN_49_GPI,
} EnumPinshareInfo76PIN_PIN_49;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1021
// MCU Ctrl : 0xFE11 at _76PIN_PIN_50_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_50                           (_76PIN_PIN_50_NC)

typedef enum
{
    _76PIN_PIN_50_HI_Z = 0x00,
    _76PIN_PIN_50_GPI = 0x01,
    _76PIN_PIN_50_TXACN_8B = 0x04,
    _76PIN_PIN_50_NC = _76PIN_PIN_50_GPI,
} EnumPinshareInfo76PIN_PIN_50;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1022
// MCU Ctrl : 0xFE12 at _76PIN_PIN_51_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_51                           (_76PIN_PIN_51_NC)

typedef enum
{
    _76PIN_PIN_51_HI_Z = 0x00,
    _76PIN_PIN_51_GPI = 0x01,
    _76PIN_PIN_51_TXA2P_8B = 0x04,
    _76PIN_PIN_51_NC = _76PIN_PIN_51_GPI,
} EnumPinshareInfo76PIN_PIN_51;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1023
// MCU Ctrl : 0xFE13 at _76PIN_PIN_52_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_52                           (_76PIN_PIN_52_NC)

typedef enum
{
    _76PIN_PIN_52_HI_Z = 0x00,
    _76PIN_PIN_52_GPI = 0x01,
    _76PIN_PIN_52_TXA2N_8B = 0x04,
    _76PIN_PIN_52_NC = _76PIN_PIN_52_GPI,
} EnumPinshareInfo76PIN_PIN_52;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1024
// MCU Ctrl : 0xFE14 at _76PIN_PIN_53_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_53                           (_76PIN_PIN_53_NC)

typedef enum
{
    _76PIN_PIN_53_HI_Z = 0x00,
    _76PIN_PIN_53_GPI = 0x01,
    _76PIN_PIN_53_TXA1P_8B = 0x04,
    _76PIN_PIN_53_NC = _76PIN_PIN_53_GPI,
} EnumPinshareInfo76PIN_PIN_53;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1025
// MCU Ctrl : 0xFE15 at _76PIN_PIN_54_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_54                           (_76PIN_PIN_54_NC)

typedef enum
{
    _76PIN_PIN_54_HI_Z = 0x00,
    _76PIN_PIN_54_GPI = 0x01,
    _76PIN_PIN_54_TXA1N_8B = 0x04,
    _76PIN_PIN_54_NC = _76PIN_PIN_54_GPI,
} EnumPinshareInfo76PIN_PIN_54;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1026
// MCU Ctrl : 0xFE16 at _76PIN_PIN_55_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_55                           (_76PIN_PIN_55_NC)

typedef enum
{
    _76PIN_PIN_55_HI_Z = 0x00,
    _76PIN_PIN_55_GPI = 0x01,
    _76PIN_PIN_55_TXA0P_8B = 0x04,
    _76PIN_PIN_55_NC = _76PIN_PIN_55_GPI,
} EnumPinshareInfo76PIN_PIN_55;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1027
// MCU Ctrl : 0xFE17 at _76PIN_PIN_56_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_56                           (_76PIN_PIN_56_NC)

typedef enum
{
    _76PIN_PIN_56_HI_Z = 0x00,
    _76PIN_PIN_56_GPI = 0x01,
    _76PIN_PIN_56_TXA0N_8B = 0x04,
    _76PIN_PIN_56_NC = _76PIN_PIN_56_GPI,
} EnumPinshareInfo76PIN_PIN_56;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102D
// MCU Ctrl : 0xFE1D at _76PIN_PIN_58_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_58                           (_76PIN_PIN_58_NC)

typedef enum
{
    _76PIN_PIN_58_GPI = 0x00,
    _76PIN_PIN_58_GPO_PP = 0x01,
    _76PIN_PIN_58_GPO_OD = 0x02,
    _76PIN_PIN_58_M1_IDOMAIN_VS_OUT = 0x03,
    _76PIN_PIN_58_TTL_DVS = 0x04,
    _76PIN_PIN_58_CLKO = 0x05,
    _76PIN_PIN_58_INT0_1 = 0x06,
    _76PIN_PIN_58_TCON11 = 0x07,
    _76PIN_PIN_58_TEST12B_OUT0 = 0x08,
    _76PIN_PIN_58_TEST12B_OUT1 = 0x09,
    _76PIN_PIN_58_TEST12B_OUT2 = 0x0A,
    _76PIN_PIN_58_TEST12B_OUT3 = 0x0B,
    _76PIN_PIN_58_TEST12B_OUT4 = 0x0C,
    _76PIN_PIN_58_TEST12B_OUT5 = 0x0D,
    _76PIN_PIN_58_TEST12B_OUT6 = 0x0E,
    _76PIN_PIN_58_TEST12B_OUT7 = 0x0F,
    _76PIN_PIN_58_TEST12B_OUT8 = 0x10,
    _76PIN_PIN_58_TEST12B_OUT9 = 0x11,
    _76PIN_PIN_58_TEST12B_OUT10 = 0x12,
    _76PIN_PIN_58_TEST12B_OUT11 = 0x13,
    _76PIN_PIN_58_NC = _76PIN_PIN_58_GPO_PP,
} EnumPinshareInfo76PIN_PIN_58;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102E
// MCU Ctrl : 0xFE1E at _76PIN_PIN_59_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_59                           (_76PIN_PIN_59_NC)

typedef enum
{
    _76PIN_PIN_59_GPI = 0x00,
    _76PIN_PIN_59_GPO_PP = 0x01,
    _76PIN_PIN_59_GPO_OD = 0x02,
    _76PIN_PIN_59_PWM2_PP = 0x03,
    _76PIN_PIN_59_PWM2_OD = 0x04,
    _76PIN_PIN_59_IICSCL_0_2 = 0x05,
    _76PIN_PIN_59_UART_TX_0_3 = 0x06,
    _76PIN_PIN_59_INT1_1 = 0x0A,
    _76PIN_PIN_59_M1_IDOMAIN_VS_OUT = 0x0B,
    _76PIN_PIN_59_TCON11 = 0x0C,
    _76PIN_PIN_59_DCLK = 0x0D,
    _76PIN_PIN_59_TTL_DHS = 0x0E,
    _76PIN_PIN_59_TEST12B_OUT0 = 0x0F,
    _76PIN_PIN_59_TEST12B_OUT1 = 0x10,
    _76PIN_PIN_59_TEST12B_OUT2 = 0x11,
    _76PIN_PIN_59_TEST12B_OUT3 = 0x12,
    _76PIN_PIN_59_TEST12B_OUT4 = 0x13,
    _76PIN_PIN_59_TEST12B_OUT5 = 0x14,
    _76PIN_PIN_59_TEST12B_OUT6 = 0x15,
    _76PIN_PIN_59_TEST12B_OUT7 = 0x16,
    _76PIN_PIN_59_TEST12B_OUT8 = 0x17,
    _76PIN_PIN_59_TEST12B_OUT9 = 0x18,
    _76PIN_PIN_59_TEST12B_OUT10 = 0x19,
    _76PIN_PIN_59_TEST12B_OUT11 = 0x1A,
    _76PIN_PIN_59_NC = _76PIN_PIN_59_GPO_PP,
} EnumPinshareInfo76PIN_PIN_59;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102F
// MCU Ctrl : 0xFE1F at _76PIN_PIN_60_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_60                           (_76PIN_PIN_60_NC)

typedef enum
{
    _76PIN_PIN_60_GPI = 0x00,
    _76PIN_PIN_60_GPO_PP = 0x01,
    _76PIN_PIN_60_GPO_OD = 0x02,
    _76PIN_PIN_60_PWM3_PP = 0x03,
    _76PIN_PIN_60_PWM3_OD = 0x04,
    _76PIN_PIN_60_IICSDA_0_2 = 0x05,
    _76PIN_PIN_60_UART_RX_0_3 = 0x06,
    _76PIN_PIN_60_T0 = 0x0A,
    _76PIN_PIN_60_TTL_DEN = 0x0B,
    _76PIN_PIN_60_TCON9 = 0x0C,
    _76PIN_PIN_60_TEST12B_OUT0 = 0x0D,
    _76PIN_PIN_60_TEST12B_OUT1 = 0x0E,
    _76PIN_PIN_60_TEST12B_OUT2 = 0x0F,
    _76PIN_PIN_60_TEST12B_OUT3 = 0x10,
    _76PIN_PIN_60_TEST12B_OUT4 = 0x11,
    _76PIN_PIN_60_TEST12B_OUT5 = 0x12,
    _76PIN_PIN_60_TEST12B_OUT6 = 0x13,
    _76PIN_PIN_60_TEST12B_OUT7 = 0x14,
    _76PIN_PIN_60_TEST12B_OUT8 = 0x15,
    _76PIN_PIN_60_TEST12B_OUT9 = 0x16,
    _76PIN_PIN_60_TEST12B_OUT10 = 0x17,
    _76PIN_PIN_60_TEST12B_OUT11 = 0x18,
    _76PIN_PIN_60_NC = _76PIN_PIN_60_GPO_PP,
} EnumPinshareInfo76PIN_PIN_60;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1030
// MCU Ctrl : 0xFE20 at _76PIN_PIN_61_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_61                           (_76PIN_PIN_61_NC)

typedef enum
{
    _76PIN_PIN_61_GPI = 0x00,
    _76PIN_PIN_61_GPO_PP = 0x01,
    _76PIN_PIN_61_GPO_OD = 0x02,
    _76PIN_PIN_61_PWM2_PP = 0x03,
    _76PIN_PIN_61_PWM2_OD = 0x04,
    _76PIN_PIN_61_PWM3_PP = 0x05,
    _76PIN_PIN_61_PWM3_OD = 0x06,
    _76PIN_PIN_61_T1 = 0x07,
    _76PIN_PIN_61_M1_IDOMAIN_HS_OUT = 0x08,
    _76PIN_PIN_61_TTL_DHS = 0x09,
    _76PIN_PIN_61_TCON13 = 0x0A,
    _76PIN_PIN_61_TEST12B_OUT0 = 0x0B,
    _76PIN_PIN_61_TEST12B_OUT1 = 0x0C,
    _76PIN_PIN_61_TEST12B_OUT2 = 0x0D,
    _76PIN_PIN_61_TEST12B_OUT3 = 0x0E,
    _76PIN_PIN_61_TEST12B_OUT4 = 0x0F,
    _76PIN_PIN_61_TEST12B_OUT5 = 0x10,
    _76PIN_PIN_61_TEST12B_OUT6 = 0x11,
    _76PIN_PIN_61_TEST12B_OUT7 = 0x12,
    _76PIN_PIN_61_TEST12B_OUT8 = 0x13,
    _76PIN_PIN_61_TEST12B_OUT9 = 0x14,
    _76PIN_PIN_61_TEST12B_OUT10 = 0x15,
    _76PIN_PIN_61_TEST12B_OUT11 = 0x16,
    _76PIN_PIN_61_MCK = 0x17,
    _76PIN_PIN_61_NC = _76PIN_PIN_61_GPO_PP,
} EnumPinshareInfo76PIN_PIN_61;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1031
// MCU Ctrl : 0xFE21 at _76PIN_PIN_62_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_62                           (_76PIN_PIN_62_NC)

typedef enum
{
    _76PIN_PIN_62_GPI = 0x00,
    _76PIN_PIN_62_GPO_PP = 0x01,
    _76PIN_PIN_62_GPO_OD = 0x02,
    _76PIN_PIN_62_DDCSCL_VGA_0_1 = 0x03,
    _76PIN_PIN_62_PWM_IN_0_0 = 0x04,
    _76PIN_PIN_62_AUX_D2 = 0x05,
    _76PIN_PIN_62_DCLK = 0x06,
    _76PIN_PIN_62_TCON8 = 0x07,
    _76PIN_PIN_62_T2EX = 0x08,
    _76PIN_PIN_62_TEST12B_OUT0 = 0x09,
    _76PIN_PIN_62_TEST12B_OUT1 = 0x0A,
    _76PIN_PIN_62_TEST12B_OUT2 = 0x0B,
    _76PIN_PIN_62_TEST12B_OUT3 = 0x0C,
    _76PIN_PIN_62_TEST12B_OUT4 = 0x0D,
    _76PIN_PIN_62_TEST12B_OUT5 = 0x0E,
    _76PIN_PIN_62_TEST12B_OUT6 = 0x0F,
    _76PIN_PIN_62_TEST12B_OUT7 = 0x10,
    _76PIN_PIN_62_TEST12B_OUT8 = 0x11,
    _76PIN_PIN_62_TEST12B_OUT9 = 0x12,
    _76PIN_PIN_62_TEST12B_OUT10 = 0x13,
    _76PIN_PIN_62_TEST12B_OUT11 = 0x14,
    _76PIN_PIN_62_NC = _76PIN_PIN_62_GPO_PP,
} EnumPinshareInfo76PIN_PIN_62;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1032
// MCU Ctrl : 0xFE22 at _76PIN_PIN_63_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_63                           (_76PIN_PIN_63_NC)

typedef enum
{
    _76PIN_PIN_63_GPI = 0x00,
    _76PIN_PIN_63_GPO_PP = 0x01,
    _76PIN_PIN_63_GPO_OD = 0x02,
    _76PIN_PIN_63_DDCSDA_VGA_0_1 = 0x03,
    _76PIN_PIN_63_PWM0_PP = 0x04,
    _76PIN_PIN_63_PWM0_OD = 0x05,
    _76PIN_PIN_63_PWM_OUT_0_0 = 0x06,
    _76PIN_PIN_63_AUX_D1 = 0x07,
    _76PIN_PIN_63_TTL_DVS = 0x08,
    _76PIN_PIN_63_TCON7 = 0x09,
    _76PIN_PIN_63_TEST12B_OUT0 = 0x0A,
    _76PIN_PIN_63_TEST12B_OUT1 = 0x0B,
    _76PIN_PIN_63_TEST12B_OUT2 = 0x0C,
    _76PIN_PIN_63_TEST12B_OUT3 = 0x0D,
    _76PIN_PIN_63_TEST12B_OUT4 = 0x0E,
    _76PIN_PIN_63_TEST12B_OUT5 = 0x0F,
    _76PIN_PIN_63_TEST12B_OUT6 = 0x10,
    _76PIN_PIN_63_TEST12B_OUT7 = 0x11,
    _76PIN_PIN_63_TEST12B_OUT8 = 0x12,
    _76PIN_PIN_63_TEST12B_OUT9 = 0x13,
    _76PIN_PIN_63_TEST12B_OUT10 = 0x14,
    _76PIN_PIN_63_TEST12B_OUT11 = 0x15,
    _76PIN_PIN_63_NC = _76PIN_PIN_63_GPO_PP,
} EnumPinshareInfo76PIN_PIN_63;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1037
// MCU Ctrl : 0xFE27 at _76PIN_PIN_70_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_70                           (_76PIN_PIN_70_NC)

typedef enum
{
    _76PIN_PIN_70_GPI = 0x00,
    _76PIN_PIN_70_GPO_PP = 0x01,
    _76PIN_PIN_70_GPO_OD = 0x02,
    _76PIN_PIN_70_DPRX_AUX_P_1 = 0x03,
    _76PIN_PIN_70_DDCSCL_1 = 0x04,
    _76PIN_PIN_70_TEST12B_OUT0 = 0x05,
    _76PIN_PIN_70_TEST12B_OUT1 = 0x06,
    _76PIN_PIN_70_TEST12B_OUT2 = 0x07,
    _76PIN_PIN_70_TEST12B_OUT3 = 0x08,
    _76PIN_PIN_70_TEST12B_OUT4 = 0x09,
    _76PIN_PIN_70_TEST12B_OUT5 = 0x0A,
    _76PIN_PIN_70_TEST12B_OUT6 = 0x0B,
    _76PIN_PIN_70_TEST12B_OUT7 = 0x0C,
    _76PIN_PIN_70_TEST12B_OUT8 = 0x0D,
    _76PIN_PIN_70_TEST12B_OUT9 = 0x0E,
    _76PIN_PIN_70_TEST12B_OUT10 = 0x0F,
    _76PIN_PIN_70_TEST12B_OUT11 = 0x10,
    _76PIN_PIN_70_NC = _76PIN_PIN_70_GPO_PP,
} EnumPinshareInfo76PIN_PIN_70;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1038
// MCU Ctrl : 0xFE28 at _76PIN_PIN_71_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_71                           (_76PIN_PIN_71_NC)

typedef enum
{
    _76PIN_PIN_71_GPI = 0x00,
    _76PIN_PIN_71_GPO_PP = 0x01,
    _76PIN_PIN_71_GPO_OD = 0x02,
    _76PIN_PIN_71_DPRX_AUX_N_1 = 0x03,
    _76PIN_PIN_71_DDCSDA_1 = 0x04,
    _76PIN_PIN_71_TEST12B_OUT0 = 0x05,
    _76PIN_PIN_71_TEST12B_OUT1 = 0x06,
    _76PIN_PIN_71_TEST12B_OUT2 = 0x07,
    _76PIN_PIN_71_TEST12B_OUT3 = 0x08,
    _76PIN_PIN_71_TEST12B_OUT4 = 0x09,
    _76PIN_PIN_71_TEST12B_OUT5 = 0x0A,
    _76PIN_PIN_71_TEST12B_OUT6 = 0x0B,
    _76PIN_PIN_71_TEST12B_OUT7 = 0x0C,
    _76PIN_PIN_71_TEST12B_OUT8 = 0x0D,
    _76PIN_PIN_71_TEST12B_OUT9 = 0x0E,
    _76PIN_PIN_71_TEST12B_OUT10 = 0x0F,
    _76PIN_PIN_71_TEST12B_OUT11 = 0x10,
    _76PIN_PIN_71_NC = _76PIN_PIN_71_GPO_PP,
} EnumPinshareInfo76PIN_PIN_71;

