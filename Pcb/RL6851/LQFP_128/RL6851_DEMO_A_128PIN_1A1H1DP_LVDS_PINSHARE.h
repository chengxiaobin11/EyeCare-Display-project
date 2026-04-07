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
// ID Code      : _RL6851_DEMO_128PIN_1A1H1DP_PC99_PINSHARE.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


///////////////
// PCB Mode  //
///////////////

//---------------------------------------------------------------------------
// PCB Rule Select
//---------------------------------------------------------------------------
#define _PCB_NEW_MODE_SUPPORT                   _ON


/////////////////////////////////
// RL6851 Series 128 Pin Share //
/////////////////////////////////

//---------------------------------------------------------------------------
// Function : DP_CABLE_DET_1
// Pinshare : 0x1000
// MCU Ctrl : 0xFFE2[0] at _PIN_21_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_21                                 (_PIN_21_GPI)

typedef enum
{
    _PIN_21_GPI = 0x00,
    _PIN_21_GPO_PP = 0x01,
    _PIN_21_GPO_OD = 0x02,
    _PIN_21_PWM0_PP = 0x03,
    _PIN_21_PWM0_OD = 0x04,
    _PIN_21_M1_IDOMAIN_HS_OUT = 0x06,
    _PIN_21_TTL_DHS = 0x07,
    _PIN_21_TCON7 = 0x08,
    _PIN_21_TEST12B_OUT0 = 0x09,
    _PIN_21_TEST12B_OUT1 = 0x0A,
    _PIN_21_TEST12B_OUT2 = 0x0B,
    _PIN_21_TEST12B_OUT3 = 0x0C,
    _PIN_21_TEST12B_OUT4 = 0x0D,
    _PIN_21_TEST12B_OUT5 = 0x0E,
    _PIN_21_TEST12B_OUT6 = 0x0F,
    _PIN_21_TEST12B_OUT7 = 0x10,
    _PIN_21_TEST12B_OUT8 = 0x11,
    _PIN_21_TEST12B_OUT9 = 0x12,
    _PIN_21_TEST12B_OUT10 = 0x13,
    _PIN_21_TEST12B_OUT11 = 0x14,
    _PIN_21_NC = _PIN_21_GPO_PP,
} EnumPinshareInfoPIN21;

//---------------------------------------------------------------------------
// Function : EDID_WP
// Pinshare : 0x1001
// MCU Ctrl : 0xFFE2[1] at _PIN_22_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_22                                 (_PIN_22_GPO_OD)

typedef enum
{
    _PIN_22_GPI = 0x00,
    _PIN_22_GPO_PP = 0x01,
    _PIN_22_GPO_OD = 0x02,
    _PIN_22_PWM1_PP = 0x03,
    _PIN_22_PWM1_OD = 0x04,
    _PIN_22_TCON8 = 0x05,
    _PIN_22_DCLK = 0x06,
    _PIN_22_TEST12B_OUT0 = 0x07,
    _PIN_22_TEST12B_OUT1 = 0x08,
    _PIN_22_TEST12B_OUT2 = 0x09,
    _PIN_22_TEST12B_OUT3 = 0x0A,
    _PIN_22_TEST12B_OUT4 = 0x0B,
    _PIN_22_TEST12B_OUT5 = 0x0C,
    _PIN_22_TEST12B_OUT6 = 0x0D,
    _PIN_22_TEST12B_OUT7 = 0x0E,
    _PIN_22_TEST12B_OUT8 = 0x0F,
    _PIN_22_TEST12B_OUT9 = 0x10,
    _PIN_22_TEST12B_OUT10 = 0x11,
    _PIN_22_TEST12B_OUT11 = 0x12,
    _PIN_22_NC = _PIN_22_GPO_PP,
} EnumPinshareInfoPIN22;

//---------------------------------------------------------------------------
// Function : TTS_CE
// Pinshare : 0x1002
// MCU Ctrl : 0xFFE2[2] at _PIN_34_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_34                                 (_PIN_34_TTS_CEB)

typedef enum
{
    _PIN_34_GPI = 0x00,
    _PIN_34_GPO_PP = 0x01,
    _PIN_34_GPO_OD = 0x02,
    _PIN_34_PWM0_PP = 0x03,
    _PIN_34_PWM0_OD = 0x04,
    _PIN_34_MCK = 0x05,
    _PIN_34_CLKO = 0x06,
    _PIN_34_TCON9 = 0x07,
    _PIN_34_TEST12B_OUT0 = 0x08,
    _PIN_34_TEST12B_OUT1 = 0x09,
    _PIN_34_TEST12B_OUT2 = 0x0A,
    _PIN_34_TEST12B_OUT3 = 0x0B,
    _PIN_34_TEST12B_OUT4 = 0x0C,
    _PIN_34_TEST12B_OUT5 = 0x0D,
    _PIN_34_TEST12B_OUT6 = 0x0E,
    _PIN_34_TEST12B_OUT7 = 0x0F,
    _PIN_34_TEST12B_OUT8 = 0x10,
    _PIN_34_TEST12B_OUT9 = 0x11,
    _PIN_34_TEST12B_OUT10 = 0x12,
    _PIN_34_TEST12B_OUT11 = 0x13,
    _PIN_34_TTS_CEB = 0x14,
    _PIN_34_NC = _PIN_34_GPO_PP,
} EnumPinshareInfoPIN34;

//---------------------------------------------------------------------------
// Function : onBACKLITE
// Pinshare : 0x1003
// MCU Ctrl : 0xFFE2[3] at _PIN_35_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_35                                 (_PIN_35_GPO_OD)

typedef enum
{
    _PIN_35_GPI = 0x00,
    _PIN_35_GPO_PP = 0x01,
    _PIN_35_GPO_OD = 0x02,
    _PIN_35_PWM1_PP = 0x03,
    _PIN_35_PWM1_OD = 0x04,
    _PIN_35_IICSCL_0_3 = 0x05,
    _PIN_35_SCK = 0x06,
    _PIN_35_IRQB = 0x07,
    _PIN_35_TCON13 = 0x08,
    _PIN_35_TEST12B_OUT0 = 0x09,
    _PIN_35_TEST12B_OUT1 = 0x0A,
    _PIN_35_TEST12B_OUT2 = 0x0B,
    _PIN_35_TEST12B_OUT3 = 0x0C,
    _PIN_35_TEST12B_OUT4 = 0x0D,
    _PIN_35_TEST12B_OUT5 = 0x0E,
    _PIN_35_TEST12B_OUT6 = 0x0F,
    _PIN_35_TEST12B_OUT7 = 0x10,
    _PIN_35_TEST12B_OUT8 = 0x11,
    _PIN_35_TEST12B_OUT9 = 0x12,
    _PIN_35_TEST12B_OUT10 = 0x13,
    _PIN_35_TEST12B_OUT11 = 0x14,
    _PIN_35_NC = _PIN_35_GPO_PP,
} EnumPinshareInfoPIN35;

//---------------------------------------------------------------------------
// Function : VGA_CABLE_DET
// Pinshare : 0x1004
// MCU Ctrl : 0xFFE2[4] at _PIN_36_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_36                                 (_PIN_36_GPI)

typedef enum
{
    _PIN_36_GPI = 0x00,
    _PIN_36_GPO_PP = 0x01,
    _PIN_36_GPO_OD = 0x02,
    _PIN_36_PWM2_PP = 0x03,
    _PIN_36_PWM2_OD = 0x04,
    _PIN_36_IICSDA_0_3 = 0x05,
    _PIN_36_CLKO = 0x06,
    _PIN_36_WS = 0x08,
    _PIN_36_TCON13 = 0x09,
    _PIN_36_TEST12B_OUT0 = 0x0A,
    _PIN_36_TEST12B_OUT1 = 0x0B,
    _PIN_36_TEST12B_OUT2 = 0x0C,
    _PIN_36_TEST12B_OUT3 = 0x0D,
    _PIN_36_TEST12B_OUT4 = 0x0E,
    _PIN_36_TEST12B_OUT5 = 0x0F,
    _PIN_36_TEST12B_OUT6 = 0x10,
    _PIN_36_TEST12B_OUT7 = 0x11,
    _PIN_36_TEST12B_OUT8 = 0x12,
    _PIN_36_TEST12B_OUT9 = 0x13,
    _PIN_36_TEST12B_OUT10 = 0x14,
    _PIN_36_TEST12B_OUT11 = 0x15,
    _PIN_36_NC = _PIN_36_GPO_PP,
} EnumPinshareInfoPIN36;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1005
// MCU Ctrl : 0xFFE2[5] at _PIN_37_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_37                                 (_PIN_37_NC)

typedef enum
{
    _PIN_37_GPI = 0x00,
    _PIN_37_GPO_PP = 0x01,
    _PIN_37_GPO_OD = 0x02,
    _PIN_37_PWM3_PP = 0x03,
    _PIN_37_PWM3_OD = 0x04,
    _PIN_37_IICSCL_0_0 = 0x05,
    _PIN_37_UART_RX_0_0 = 0x06,
    _PIN_37_SD0 = 0x0A,
    _PIN_37_SPDIF0 = 0x0B,
    _PIN_37_TCON11 = 0x0C,
    _PIN_37_TEST12B_OUT0 = 0x0D,
    _PIN_37_TEST12B_OUT1 = 0x0E,
    _PIN_37_TEST12B_OUT2 = 0x0F,
    _PIN_37_TEST12B_OUT3 = 0x10,
    _PIN_37_TEST12B_OUT4 = 0x11,
    _PIN_37_TEST12B_OUT5 = 0x12,
    _PIN_37_TEST12B_OUT6 = 0x13,
    _PIN_37_TEST12B_OUT7 = 0x14,
    _PIN_37_TEST12B_OUT8 = 0x15,
    _PIN_37_TEST12B_OUT9 = 0x16,
    _PIN_37_TEST12B_OUT10 = 0x17,
    _PIN_37_TEST12B_OUT11 = 0x18,
    _PIN_37_NC = _PIN_37_GPO_PP,
} EnumPinshareInfoPIN37;

//---------------------------------------------------------------------------
// Function : GPU_SEL
// Pinshare : 0x1006
// MCU Ctrl : 0xFFE2[6] at _PIN_38_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_38                                 (_PIN_38_GPO_OD)

typedef enum
{
    _PIN_38_GPI = 0x00,
    _PIN_38_GPO_PP = 0x01,
    _PIN_38_GPO_OD = 0x02,
    _PIN_38_PWM2_PP = 0x03,
    _PIN_38_PWM2_OD = 0x04,
    _PIN_38_IICSDA_0_0 = 0x05,
    _PIN_38_UART_TX_0_0 = 0x06,
    _PIN_38_TCON12 = 0x0A,
    _PIN_38_TEST12B_OUT0 = 0x0B,
    _PIN_38_TEST12B_OUT1 = 0x0C,
    _PIN_38_TEST12B_OUT2 = 0x0D,
    _PIN_38_TEST12B_OUT3 = 0x0E,
    _PIN_38_TEST12B_OUT4 = 0x0F,
    _PIN_38_TEST12B_OUT5 = 0x10,
    _PIN_38_TEST12B_OUT6 = 0x11,
    _PIN_38_TEST12B_OUT7 = 0x12,
    _PIN_38_TEST12B_OUT8 = 0x13,
    _PIN_38_TEST12B_OUT9 = 0x14,
    _PIN_38_TEST12B_OUT10 = 0x15,
    _PIN_38_TEST12B_OUT11 = 0x16,
    _PIN_38_NC = _PIN_38_GPO_PP,
} EnumPinshareInfoPIN38;

//---------------------------------------------------------------------------
// Function : DP_HOT_PLUG_1
// Pinshare : 0x1007
// MCU Ctrl : 0xFFE2[7] at _PIN_39_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_39                                 (_PIN_39_GPO_PP)

typedef enum
{
    _PIN_39_GPI = 0x00,
    _PIN_39_GPO_PP = 0x01,
    _PIN_39_GPO_OD = 0x02,
    _PIN_39_PWM3_PP = 0x03,
    _PIN_39_PWM3_OD = 0x04,
    _PIN_39_TCON13 = 0x05,
    _PIN_39_DCLK = 0x06,
    _PIN_39_TEST12B_OUT0 = 0x07,
    _PIN_39_TEST12B_OUT1 = 0x08,
    _PIN_39_TEST12B_OUT2 = 0x09,
    _PIN_39_TEST12B_OUT3 = 0x0A,
    _PIN_39_TEST12B_OUT4 = 0x0B,
    _PIN_39_TEST12B_OUT5 = 0x0C,
    _PIN_39_TEST12B_OUT6 = 0x0D,
    _PIN_39_TEST12B_OUT7 = 0x0E,
    _PIN_39_TEST12B_OUT8 = 0x0F,
    _PIN_39_TEST12B_OUT9 = 0x10,
    _PIN_39_TEST12B_OUT10 = 0x11,
    _PIN_39_TEST12B_OUT11 = 0x12,
    _PIN_39_NC = _PIN_39_GPO_PP,
} EnumPinshareInfoPIN39;

//---------------------------------------------------------------------------
// Function : ADC_KEY1
// Pinshare : 0x1008
// MCU Ctrl : 0xFFE3[0] at _PIN_42_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_42                                 (_PIN_42_A_ADC_0)

typedef enum
{
    _PIN_42_GPI = 0x00,
    _PIN_42_GPO_PP = 0x01,
    _PIN_42_GPO_OD = 0x02,
    _PIN_42_A_ADC_0 = 0x03,
    _PIN_42_TCON9 = 0x04,
    _PIN_42_TEST12B_OUT0 = 0x05,
    _PIN_42_TEST12B_OUT1 = 0x06,
    _PIN_42_TEST12B_OUT2 = 0x07,
    _PIN_42_TEST12B_OUT3 = 0x08,
    _PIN_42_TEST12B_OUT4 = 0x09,
    _PIN_42_TEST12B_OUT5 = 0x0A,
    _PIN_42_TEST12B_OUT6 = 0x0B,
    _PIN_42_TEST12B_OUT7 = 0x0C,
    _PIN_42_TEST12B_OUT8 = 0x0D,
    _PIN_42_TEST12B_OUT9 = 0x0E,
    _PIN_42_TEST12B_OUT10 = 0x0F,
    _PIN_42_TEST12B_OUT11 = 0x10,
    _PIN_42_NC = _PIN_42_GPO_PP,
} EnumPinshareInfoPIN42;

//---------------------------------------------------------------------------
// Function : ADC_KEY2
// Pinshare : 0x1009
// MCU Ctrl : 0xFFE3[1] at _PIN_43_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_43                                 (_PIN_43_A_ADC_1)

typedef enum
{
    _PIN_43_GPI = 0x00,
    _PIN_43_GPO_PP = 0x01,
    _PIN_43_GPO_OD = 0x02,
    _PIN_43_A_ADC_1 = 0x03,
    _PIN_43_TCON12 = 0x04,
    _PIN_43_TEST12B_OUT0 = 0x05,
    _PIN_43_TEST12B_OUT1 = 0x06,
    _PIN_43_TEST12B_OUT2 = 0x07,
    _PIN_43_TEST12B_OUT3 = 0x08,
    _PIN_43_TEST12B_OUT4 = 0x09,
    _PIN_43_TEST12B_OUT5 = 0x0A,
    _PIN_43_TEST12B_OUT6 = 0x0B,
    _PIN_43_TEST12B_OUT7 = 0x0C,
    _PIN_43_TEST12B_OUT8 = 0x0D,
    _PIN_43_TEST12B_OUT9 = 0x0E,
    _PIN_43_TEST12B_OUT10 = 0x0F,
    _PIN_43_TEST12B_OUT11 = 0x10,
    _PIN_43_NC = _PIN_43_GPO_PP,
} EnumPinshareInfoPIN43;

//---------------------------------------------------------------------------
// Function : 2173_SDA
// Pinshare : 0x100A
// MCU Ctrl : 0xFFE3[2] at _PIN_44_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_44                                 (_PIN_44_GPO_OD)

typedef enum
{
    _PIN_44_GPI = 0x00,
    _PIN_44_GPO_PP = 0x01,
    _PIN_44_GPO_OD = 0x02,
    _PIN_44_A_ADC_2 = 0x03,
    _PIN_44_TEST12B_OUT0 = 0x04,
    _PIN_44_TEST12B_OUT1 = 0x05,
    _PIN_44_TEST12B_OUT2 = 0x06,
    _PIN_44_TEST12B_OUT3 = 0x07,
    _PIN_44_TEST12B_OUT4 = 0x08,
    _PIN_44_TEST12B_OUT5 = 0x09,
    _PIN_44_TEST12B_OUT6 = 0x0A,
    _PIN_44_TEST12B_OUT7 = 0x0B,
    _PIN_44_TEST12B_OUT8 = 0x0C,
    _PIN_44_TEST12B_OUT9 = 0x0D,
    _PIN_44_TEST12B_OUT10 = 0x0E,
    _PIN_44_TEST12B_OUT11 = 0x0F,
    _PIN_44_NC = _PIN_44_GPO_PP,
} EnumPinshareInfoPIN44;

//---------------------------------------------------------------------------
// Function : 2173_SCL
// Pinshare : 0x100B
// MCU Ctrl : 0xFFE3[3] at _PIN_45_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_45                                 (_PIN_45_GPO_OD)

typedef enum
{
    _PIN_45_GPI = 0x00,
    _PIN_45_GPO_PP = 0x01,
    _PIN_45_GPO_OD = 0x02,
    _PIN_45_A_ADC_3 = 0x03,
    _PIN_45_CLKO = 0x04,
    _PIN_45_TEST12B_OUT0 = 0x05,
    _PIN_45_TEST12B_OUT1 = 0x06,
    _PIN_45_TEST12B_OUT2 = 0x07,
    _PIN_45_TEST12B_OUT3 = 0x08,
    _PIN_45_TEST12B_OUT4 = 0x09,
    _PIN_45_TEST12B_OUT5 = 0x0A,
    _PIN_45_TEST12B_OUT6 = 0x0B,
    _PIN_45_TEST12B_OUT7 = 0x0C,
    _PIN_45_TEST12B_OUT8 = 0x0D,
    _PIN_45_TEST12B_OUT9 = 0x0E,
    _PIN_45_TEST12B_OUT10 = 0x0F,
    _PIN_45_TEST12B_OUT11 = 0x10,
    _PIN_45_NC = _PIN_45_GPO_PP,
} EnumPinshareInfoPIN45;

//---------------------------------------------------------------------------
// Function : TTS_CLK
// Pinshare : 0x100C
// MCU Ctrl : 0xFFE3[4] at _PIN_46_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_46                                 (_PIN_46_TTS_SCLK)

typedef enum
{
    _PIN_46_GPI = 0x00,
    _PIN_46_GPO_PP = 0x01,
    _PIN_46_GPO_OD = 0x02,
    _PIN_46_PWM1_PP = 0x03,
    _PIN_46_PWM1_OD = 0x04,
    _PIN_46_TCON7 = 0x05,
    _PIN_46_TCON13 = 0x06,
    _PIN_46_TEST12B_OUT0 = 0x07,
    _PIN_46_TEST12B_OUT1 = 0x08,
    _PIN_46_TEST12B_OUT2 = 0x09,
    _PIN_46_TEST12B_OUT3 = 0x0A,
    _PIN_46_TEST12B_OUT4 = 0x0B,
    _PIN_46_TEST12B_OUT5 = 0x0C,
    _PIN_46_TEST12B_OUT6 = 0x0D,
    _PIN_46_TEST12B_OUT7 = 0x0E,
    _PIN_46_TEST12B_OUT8 = 0x0F,
    _PIN_46_TEST12B_OUT9 = 0x10,
    _PIN_46_TEST12B_OUT10 = 0x11,
    _PIN_46_TEST12B_OUT11 = 0x12,
    _PIN_46_TTS_SCLK = 0x13,
    _PIN_46_NC = _PIN_46_GPO_PP,
} EnumPinshareInfoPIN46;

//---------------------------------------------------------------------------
// Function : EESCL
// Pinshare : 0x100D
// MCU Ctrl : 0xFFE3[5] at _PIN_47_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_47                                 (_PIN_47_EEIICSCL)

typedef enum
{
    _PIN_47_GPI = 0x00,
    _PIN_47_GPO_PP = 0x01,
    _PIN_47_GPO_OD = 0x02,
    _PIN_47_EEIICSCL = 0x03,
    _PIN_47_IICSCL_AUX = 0x04,
    _PIN_47_TCON8 = 0x05,
    _PIN_47_TCON12 = 0x06,
    _PIN_47_TEST12B_OUT0 = 0x07,
    _PIN_47_TEST12B_OUT1 = 0x08,
    _PIN_47_TEST12B_OUT2 = 0x09,
    _PIN_47_TEST12B_OUT3 = 0x0A,
    _PIN_47_TEST12B_OUT4 = 0x0B,
    _PIN_47_TEST12B_OUT5 = 0x0C,
    _PIN_47_TEST12B_OUT6 = 0x0D,
    _PIN_47_TEST12B_OUT7 = 0x0E,
    _PIN_47_TEST12B_OUT8 = 0x0F,
    _PIN_47_TEST12B_OUT9 = 0x10,
    _PIN_47_TEST12B_OUT10 = 0x11,
    _PIN_47_TEST12B_OUT11 = 0x12,
    _PIN_47_NC = _PIN_47_GPO_PP,
} EnumPinshareInfoPIN47;

//---------------------------------------------------------------------------
// Function : EESDA
// Pinshare : 0x100E
// MCU Ctrl : 0xFFE3[6] at _PIN_48_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_48                                 (_PIN_48_EEIICSDA)

typedef enum
{
    _PIN_48_GPI = 0x00,
    _PIN_48_GPO_PP = 0x01,
    _PIN_48_GPO_OD = 0x02,
    _PIN_48_EEIICSDA = 0x03,
    _PIN_48_IICSDA_AUX = 0x04,
    _PIN_48_TEST12B_OUT0 = 0x05,
    _PIN_48_TEST12B_OUT1 = 0x06,
    _PIN_48_TEST12B_OUT2 = 0x07,
    _PIN_48_TEST12B_OUT3 = 0x08,
    _PIN_48_TEST12B_OUT4 = 0x09,
    _PIN_48_TEST12B_OUT5 = 0x0A,
    _PIN_48_TEST12B_OUT6 = 0x0B,
    _PIN_48_TEST12B_OUT7 = 0x0C,
    _PIN_48_TEST12B_OUT8 = 0x0D,
    _PIN_48_TEST12B_OUT9 = 0x0E,
    _PIN_48_TEST12B_OUT10 = 0x0F,
    _PIN_48_TEST12B_OUT11 = 0x10,
    _PIN_48_NC = _PIN_48_GPO_PP,
} EnumPinshareInfoPIN48;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x100F
// MCU Ctrl : 0xFFE3[7] at _PIN_49_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_49                                 (_PIN_49_NC)

typedef enum
{
    _PIN_49_GPI = 0x00,
    _PIN_49_GPO_PP = 0x01,
    _PIN_49_GPO_OD = 0x02,
    _PIN_49_DDCSCL_ISP = 0x03,
    _PIN_49_DDCSCL_VGA_0_0 = 0x04,
    _PIN_49_UART_RX_0_1 = 0x05,
    _PIN_49_TEST12B_OUT0 = 0x09,
    _PIN_49_TEST12B_OUT1 = 0x0A,
    _PIN_49_TEST12B_OUT2 = 0x0B,
    _PIN_49_TEST12B_OUT3 = 0x0C,
    _PIN_49_TEST12B_OUT4 = 0x0D,
    _PIN_49_TEST12B_OUT5 = 0x0E,
    _PIN_49_TEST12B_OUT6 = 0x0F,
    _PIN_49_TEST12B_OUT7 = 0x10,
    _PIN_49_TEST12B_OUT8 = 0x11,
    _PIN_49_TEST12B_OUT9 = 0x12,
    _PIN_49_TEST12B_OUT10 = 0x13,
    _PIN_49_TEST12B_OUT11 = 0x14,
    _PIN_49_DDCCSL_MUX_SWAP_PIN_43 = 0x20,
    _PIN_49_NC = _PIN_49_GPO_PP,
} EnumPinshareInfoPIN49;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1010
// MCU Ctrl : 0xFE00 at _PIN_50_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_50                                 (_PIN_50_NC)

typedef enum
{
    _PIN_50_GPI = 0x00,
    _PIN_50_GPO_PP = 0x01,
    _PIN_50_GPO_OD = 0x02,
    _PIN_50_DDCSDA_ISP = 0x03,
    _PIN_50_DDCSDA_VGA_0_0 = 0x04,
    _PIN_50_UART_TX_0_1 = 0x05,
    _PIN_50_TCON11 = 0x09,
    _PIN_50_TCON13 = 0x0A,
    _PIN_50_TEST12B_OUT0 = 0x0B,
    _PIN_50_TEST12B_OUT1 = 0x0C,
    _PIN_50_TEST12B_OUT2 = 0x0D,
    _PIN_50_TEST12B_OUT3 = 0x0E,
    _PIN_50_TEST12B_OUT4 = 0x0F,
    _PIN_50_TEST12B_OUT5 = 0x10,
    _PIN_50_TEST12B_OUT6 = 0x11,
    _PIN_50_TEST12B_OUT7 = 0x12,
    _PIN_50_TEST12B_OUT8 = 0x13,
    _PIN_50_TEST12B_OUT9 = 0x14,
    _PIN_50_TEST12B_OUT10 = 0x15,
    _PIN_50_TEST12B_OUT11 = 0x16,
    _PIN_50_DDCCSL_MUX_SWAP_PIN_44 = 0x20,
    _PIN_50_NC = _PIN_50_GPO_PP,
} EnumPinshareInfoPIN50;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1011
// MCU Ctrl : 0xFE01 at _PIN_52_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_52                                 (_PIN_52_NC)

typedef enum
{
    _PIN_52_GPI = 0x00,
    _PIN_52_GPO_PP = 0x01,
    _PIN_52_GPO_OD = 0x02,
    _PIN_52_PWM0_PP = 0x03,
    _PIN_52_PWM0_OD = 0x04,
    _PIN_52_TCON9 = 0x06,
    _PIN_52_TEST12B_OUT0 = 0x07,
    _PIN_52_TEST12B_OUT1 = 0x08,
    _PIN_52_TEST12B_OUT2 = 0x09,
    _PIN_52_TEST12B_OUT3 = 0x0A,
    _PIN_52_TEST12B_OUT4 = 0x0B,
    _PIN_52_TEST12B_OUT5 = 0x0C,
    _PIN_52_TEST12B_OUT6 = 0x0D,
    _PIN_52_TEST12B_OUT7 = 0x0E,
    _PIN_52_TEST12B_OUT8 = 0x0F,
    _PIN_52_TEST12B_OUT9 = 0x10,
    _PIN_52_TEST12B_OUT10 = 0x11,
    _PIN_52_TEST12B_OUT11 = 0x12,
    _PIN_52_NC = _PIN_52_GPO_PP,
} EnumPinshareInfoPIN52;

//---------------------------------------------------------------------------
// Function : EDPTX_HPD
// Pinshare : 0x1012
// MCU Ctrl : 0xFE02 at _PIN_53_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_53                                 (_PIN_53_EDPTX_HPD_ORG_0)

typedef enum
{
    _PIN_53_GPI = 0x00,
    _PIN_53_GPO_PP = 0x01,
    _PIN_53_GPO_OD = 0x02,
    _PIN_53_PWM3_PP = 0x03,
    _PIN_53_PWM3_OD = 0x04,
    _PIN_53_EDPTX_HPD_ORG_0 = 0x05,
    _PIN_53_TCON12 = 0x06,
    _PIN_53_TEST12B_OUT0 = 0x07,
    _PIN_53_TEST12B_OUT1 = 0x08,
    _PIN_53_TEST12B_OUT2 = 0x09,
    _PIN_53_TEST12B_OUT3 = 0x0A,
    _PIN_53_TEST12B_OUT4 = 0x0B,
    _PIN_53_TEST12B_OUT5 = 0x0C,
    _PIN_53_TEST12B_OUT6 = 0x0D,
    _PIN_53_TEST12B_OUT7 = 0x0E,
    _PIN_53_TEST12B_OUT8 = 0x0F,
    _PIN_53_TEST12B_OUT9 = 0x10,
    _PIN_53_TEST12B_OUT10 = 0x11,
    _PIN_53_TEST12B_OUT11 = 0x12,
    _PIN_53_NC = _PIN_53_GPO_PP,
} EnumPinshareInfoPIN53;

//---------------------------------------------------------------------------
// Function : LINE_INL
// Pinshare : 0x1013
// MCU Ctrl : 0xFE03 at _PIN_55_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_55                                 (_PIN_55_LINE_INL)

typedef enum
{
    _PIN_55_GPI = 0x00,
    _PIN_55_GPO_PP = 0x01,
    _PIN_55_GPO_OD = 0x02,
    _PIN_55_LINE_INL = 0x03,
    _PIN_55_PWM0_PP = 0x04,
    _PIN_55_PWM0_OD = 0x05,
    _PIN_55_MCK = 0x06,
    _PIN_55_TEST12B_OUT0 = 0x07,
    _PIN_55_TEST12B_OUT1 = 0x08,
    _PIN_55_TEST12B_OUT2 = 0x09,
    _PIN_55_TEST12B_OUT3 = 0x0A,
    _PIN_55_TEST12B_OUT4 = 0x0B,
    _PIN_55_TEST12B_OUT5 = 0x0C,
    _PIN_55_TEST12B_OUT6 = 0x0D,
    _PIN_55_TEST12B_OUT7 = 0x0E,
    _PIN_55_TEST12B_OUT8 = 0x0F,
    _PIN_55_TEST12B_OUT9 = 0x10,
    _PIN_55_TEST12B_OUT10 = 0x11,
    _PIN_55_TEST12B_OUT11 = 0x12,
    _PIN_55_NC = _PIN_55_GPO_PP,
} EnumPinshareInfoPIN55;

//---------------------------------------------------------------------------
// Function : LINE_INR
// Pinshare : 0x1014
// MCU Ctrl : 0xFE04 at _PIN_56_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_56                                 (_PIN_56_LINE_INR)

typedef enum
{
    _PIN_56_GPI = 0x00,
    _PIN_56_GPO_PP = 0x01,
    _PIN_56_GPO_OD = 0x02,
    _PIN_56_LINE_INR = 0x03,
    _PIN_56_SCK = 0x04,
    _PIN_56_TEST12B_OUT0 = 0x05,
    _PIN_56_TEST12B_OUT1 = 0x06,
    _PIN_56_TEST12B_OUT2 = 0x07,
    _PIN_56_TEST12B_OUT3 = 0x08,
    _PIN_56_TEST12B_OUT4 = 0x09,
    _PIN_56_TEST12B_OUT5 = 0x0A,
    _PIN_56_TEST12B_OUT6 = 0x0B,
    _PIN_56_TEST12B_OUT7 = 0x0C,
    _PIN_56_TEST12B_OUT8 = 0x0D,
    _PIN_56_TEST12B_OUT9 = 0x0E,
    _PIN_56_TEST12B_OUT10 = 0x0F,
    _PIN_56_TEST12B_OUT11 = 0x10,
    _PIN_56_NC = _PIN_56_GPO_PP,
} EnumPinshareInfoPIN56;

//---------------------------------------------------------------------------
// Function : Audio_REF
// Pinshare : 0x1015
// MCU Ctrl : 0xFE05 at _PIN_57_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_57                                 (_PIN_57_AUDIO_REF)

typedef enum
{
    _PIN_57_GPI = 0x00,
    _PIN_57_GPO_PP = 0x01,
    _PIN_57_GPO_OD = 0x02,
    _PIN_57_AUDIO_REF = 0x03,
    _PIN_57_WS = 0x04,
    _PIN_57_TCON13 = 0x05,
    _PIN_57_TEST12B_OUT0 = 0x06,
    _PIN_57_TEST12B_OUT1 = 0x07,
    _PIN_57_TEST12B_OUT2 = 0x08,
    _PIN_57_TEST12B_OUT3 = 0x09,
    _PIN_57_TEST12B_OUT4 = 0x0A,
    _PIN_57_TEST12B_OUT5 = 0x0B,
    _PIN_57_TEST12B_OUT6 = 0x0C,
    _PIN_57_TEST12B_OUT7 = 0x0D,
    _PIN_57_TEST12B_OUT8 = 0x0E,
    _PIN_57_TEST12B_OUT9 = 0x0F,
    _PIN_57_TEST12B_OUT10 = 0x10,
    _PIN_57_TEST12B_OUT11 = 0x11,
    _PIN_57_NC = _PIN_57_GPO_PP,
} EnumPinshareInfoPIN57;

//---------------------------------------------------------------------------
// Function : AUDIO_SOUTL
// Pinshare : 0x1016
// MCU Ctrl : 0xFE06 at _PIN_58_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_58                                 (_PIN_58_AUDIO_SOUTL)

typedef enum
{
    _PIN_58_GPI = 0x00,
    _PIN_58_GPO_PP = 0x01,
    _PIN_58_GPO_OD = 0x02,
    _PIN_58_AUDIO_SOUTL = 0x03,
    _PIN_58_SD0 = 0x04,
    _PIN_58_SPDIF0 = 0x05,
    _PIN_58_TEST12B_OUT0 = 0x06,
    _PIN_58_TEST12B_OUT1 = 0x07,
    _PIN_58_TEST12B_OUT2 = 0x08,
    _PIN_58_TEST12B_OUT3 = 0x09,
    _PIN_58_TEST12B_OUT4 = 0x0A,
    _PIN_58_TEST12B_OUT5 = 0x0B,
    _PIN_58_TEST12B_OUT6 = 0x0C,
    _PIN_58_TEST12B_OUT7 = 0x0D,
    _PIN_58_TEST12B_OUT8 = 0x0E,
    _PIN_58_TEST12B_OUT9 = 0x0F,
    _PIN_58_TEST12B_OUT10 = 0x10,
    _PIN_58_TEST12B_OUT11 = 0x11,
    _PIN_58_NC = _PIN_58_GPO_PP,
} EnumPinshareInfoPIN58;

//---------------------------------------------------------------------------
// Function : AUDIO_SOUTR
// Pinshare : 0x1017
// MCU Ctrl : 0xFE07 at _PIN_59_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_59                                 (_PIN_59_AUDIO_SOUTR)

typedef enum
{
    _PIN_59_GPI = 0x00,
    _PIN_59_GPO_PP = 0x01,
    _PIN_59_GPO_OD = 0x02,
    _PIN_59_AUDIO_SOUTR = 0x03,
    _PIN_59_TEST12B_OUT0 = 0x04,
    _PIN_59_TEST12B_OUT1 = 0x05,
    _PIN_59_TEST12B_OUT2 = 0x06,
    _PIN_59_TEST12B_OUT3 = 0x07,
    _PIN_59_TEST12B_OUT4 = 0x08,
    _PIN_59_TEST12B_OUT5 = 0x09,
    _PIN_59_TEST12B_OUT6 = 0x0A,
    _PIN_59_TEST12B_OUT7 = 0x0B,
    _PIN_59_TEST12B_OUT8 = 0x0C,
    _PIN_59_TEST12B_OUT9 = 0x0D,
    _PIN_59_TEST12B_OUT10 = 0x0E,
    _PIN_59_TEST12B_OUT11 = 0x0F,
    _PIN_59_NC = _PIN_59_GPO_PP,
} EnumPinshareInfoPIN59;

//---------------------------------------------------------------------------
// Function : AUDIO_HOUTL
// Pinshare : 0x1018
// MCU Ctrl : 0xFE08 at _PIN_60_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_60                                 (_PIN_60_AUDIO_HOUTL)

typedef enum
{
    _PIN_60_GPI = 0x00,
    _PIN_60_GPO_PP = 0x01,
    _PIN_60_GPO_OD = 0x02,
    _PIN_60_AUDIO_HOUTL = 0x03,
    _PIN_60_IICSCL_0_1 = 0x04,
    _PIN_60_UART_RX_0_2 = 0x05,
    _PIN_60_TEST12B_OUT0 = 0x09,
    _PIN_60_TEST12B_OUT1 = 0x0A,
    _PIN_60_TEST12B_OUT2 = 0x0B,
    _PIN_60_TEST12B_OUT3 = 0x0C,
    _PIN_60_TEST12B_OUT4 = 0x0D,
    _PIN_60_TEST12B_OUT5 = 0x0E,
    _PIN_60_TEST12B_OUT6 = 0x0F,
    _PIN_60_TEST12B_OUT7 = 0x10,
    _PIN_60_TEST12B_OUT8 = 0x11,
    _PIN_60_TEST12B_OUT9 = 0x12,
    _PIN_60_TEST12B_OUT10 = 0x13,
    _PIN_60_TEST12B_OUT11 = 0x14,
    _PIN_60_NC = _PIN_60_GPO_PP,
} EnumPinshareInfoPIN60;

//---------------------------------------------------------------------------
// Function : AUDIO_HOUTR
// Pinshare : 0x1019
// MCU Ctrl : 0xFE09 at _PIN_61_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_61                                 (_PIN_61_AUDIO_HOUTR)

typedef enum
{
    _PIN_61_GPI = 0x00,
    _PIN_61_GPO_PP = 0x01,
    _PIN_61_GPO_OD = 0x02,
    _PIN_61_AUDIO_HOUTR = 0x03,
    _PIN_61_IICSDA_0_1 = 0x04,
    _PIN_61_UART_TX_0_2 = 0x05,
    _PIN_61_TEST12B_OUT0 = 0x0A,
    _PIN_61_TEST12B_OUT1 = 0x0B,
    _PIN_61_TEST12B_OUT2 = 0x0C,
    _PIN_61_TEST12B_OUT3 = 0x0D,
    _PIN_61_TEST12B_OUT4 = 0x0E,
    _PIN_61_TEST12B_OUT5 = 0x0F,
    _PIN_61_TEST12B_OUT6 = 0x10,
    _PIN_61_TEST12B_OUT7 = 0x11,
    _PIN_61_TEST12B_OUT8 = 0x12,
    _PIN_61_TEST12B_OUT9 = 0x13,
    _PIN_61_TEST12B_OUT10 = 0x14,
    _PIN_61_TEST12B_OUT11 = 0x15,
    _PIN_61_NC = _PIN_61_GPO_PP,
} EnumPinshareInfoPIN61;

//---------------------------------------------------------------------------
// Function : TTS_SDIN
// Pinshare : 0x101A
// MCU Ctrl : 0xFE0A at _PIN_63_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_63                                 (_PIN_63_TTS_SI)

typedef enum
{
    _PIN_63_GPI = 0x00,
    _PIN_63_GPO_PP = 0x01,
    _PIN_63_GPO_OD = 0x02,
    _PIN_63_PWM0_PP = 0x03,
    _PIN_63_PWM0_OD = 0x04,
    _PIN_63_PWM_IN_0_1 = 0x05,
    _PIN_63_CLKO = 0x06,
    _PIN_63_INT1_0 = 0x07,
    _PIN_63_T2 = 0x08,
    _PIN_63_M1_IDOMAIN_HS_OUT = 0x09,
    _PIN_63_TCON7 = 0x0A,
    _PIN_63_TEST12B_OUT0 = 0x0B,
    _PIN_63_TEST12B_OUT1 = 0x0C,
    _PIN_63_TEST12B_OUT2 = 0x0D,
    _PIN_63_TEST12B_OUT3 = 0x0E,
    _PIN_63_TEST12B_OUT4 = 0x0F,
    _PIN_63_TEST12B_OUT5 = 0x10,
    _PIN_63_TEST12B_OUT6 = 0x11,
    _PIN_63_TEST12B_OUT7 = 0x12,
    _PIN_63_TEST12B_OUT8 = 0x13,
    _PIN_63_TEST12B_OUT9 = 0x14,
    _PIN_63_TEST12B_OUT10 = 0x15,
    _PIN_63_TEST12B_OUT11 = 0x16,
    _PIN_63_TTS_SI = 0x17,
    _PIN_63_NC = _PIN_63_GPO_PP,
} EnumPinshareInfoPIN63;

//---------------------------------------------------------------------------
// Function : TTS_SDOUT
// Pinshare : 0x101B
// MCU Ctrl : 0xFE0B at _PIN_64_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_64                                 (_PIN_64_TTS_SO)

typedef enum
{
    _PIN_64_GPI = 0x00,
    _PIN_64_GPO_PP = 0x01,
    _PIN_64_GPO_OD = 0x02,
    _PIN_64_PWM2_PP = 0x03,
    _PIN_64_PWM2_OD = 0x04,
    _PIN_64_PWM_OUT_0_1 = 0x05,
    _PIN_64_CLKO = 0x06,
    _PIN_64_INT0_0 = 0x07,
    _PIN_64_M1_IDOMAIN_DEN_OUT = 0x08,
    _PIN_64_TCON8 = 0x09,
    _PIN_64_TEST12B_OUT0 = 0x0A,
    _PIN_64_TEST12B_OUT1 = 0x0B,
    _PIN_64_TEST12B_OUT2 = 0x0C,
    _PIN_64_TEST12B_OUT3 = 0x0D,
    _PIN_64_TEST12B_OUT4 = 0x0E,
    _PIN_64_TEST12B_OUT5 = 0x0F,
    _PIN_64_TEST12B_OUT6 = 0x10,
    _PIN_64_TEST12B_OUT7 = 0x11,
    _PIN_64_TEST12B_OUT8 = 0x12,
    _PIN_64_TEST12B_OUT9 = 0x13,
    _PIN_64_TEST12B_OUT10 = 0x14,
    _PIN_64_TEST12B_OUT11 = 0x15,
    _PIN_64_TTS_SO = 0x16,
    _PIN_64_NC = _PIN_64_GPO_PP,
} EnumPinshareInfoPIN64;

//---------------------------------------------------------------------------
// Function : HDMI_HPD_0
// Pinshare : 0x101C
// MCU Ctrl : 0xFE0C at _PIN_65_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_65                                 (_PIN_65_GPO_OD)

typedef enum
{
    _PIN_65_GPI = 0x00,
    _PIN_65_GPO_PP = 0x01,
    _PIN_65_GPO_OD = 0x02,
    _PIN_65_SCK = 0x03,
    _PIN_65_PWM2_PP = 0x04,
    _PIN_65_PWM2_OD = 0x05,
    _PIN_65_TCON9 = 0x06,
    _PIN_65_DCLK = 0x07,
    _PIN_65_TEST12B_OUT0 = 0x08,
    _PIN_65_TEST12B_OUT1 = 0x09,
    _PIN_65_TEST12B_OUT2 = 0x0A,
    _PIN_65_TEST12B_OUT3 = 0x0B,
    _PIN_65_TEST12B_OUT4 = 0x0C,
    _PIN_65_TEST12B_OUT5 = 0x0D,
    _PIN_65_TEST12B_OUT6 = 0x0E,
    _PIN_65_TEST12B_OUT7 = 0x0F,
    _PIN_65_TEST12B_OUT8 = 0x10,
    _PIN_65_TEST12B_OUT9 = 0x11,
    _PIN_65_TEST12B_OUT10 = 0x12,
    _PIN_65_TEST12B_OUT11 = 0x13,
    _PIN_65_NC = _PIN_65_GPO_PP,
} EnumPinshareInfoPIN65;

//---------------------------------------------------------------------------
// Function : EEPROM_WP
// Pinshare : 0x101D
// MCU Ctrl : 0xFE0D at _PIN_66_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_66                                 (_PIN_66_GPO_OD)

typedef enum
{
    _PIN_66_GPI = 0x00,
    _PIN_66_GPO_PP = 0x01,
    _PIN_66_GPO_OD = 0x02,
    _PIN_66_PWM3_PP = 0x03,
    _PIN_66_PWM3_OD = 0x04,
    _PIN_66_MCK = 0x05,
    _PIN_66_M1_IDOMAIN_DEN_OUT = 0x06,
    _PIN_66_TTL_DEN = 0x07,
    _PIN_66_TCON11 = 0x09,
    _PIN_66_TEST12B_OUT0 = 0x0A,
    _PIN_66_TEST12B_OUT1 = 0x0B,
    _PIN_66_TEST12B_OUT2 = 0x0C,
    _PIN_66_TEST12B_OUT3 = 0x0D,
    _PIN_66_TEST12B_OUT4 = 0x0E,
    _PIN_66_TEST12B_OUT5 = 0x0F,
    _PIN_66_TEST12B_OUT6 = 0x10,
    _PIN_66_TEST12B_OUT7 = 0x11,
    _PIN_66_TEST12B_OUT8 = 0x12,
    _PIN_66_TEST12B_OUT9 = 0x13,
    _PIN_66_TEST12B_OUT10 = 0x14,
    _PIN_66_TEST12B_OUT11 = 0x15,
    _PIN_66_NC = _PIN_66_GPO_PP,
} EnumPinshareInfoPIN66;

//---------------------------------------------------------------------------
// Function : TXA3P
// Pinshare : 0x101E
// MCU Ctrl : 0xFE0E at _PIN_79_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_79                                 (_PIN_79_TXA3P_8B)

typedef enum
{
    _PIN_79_HI_Z = 0x00,
    _PIN_79_GPI = 0x01,
    _PIN_79_TXA3P_8B = 0x04,
    _PIN_79_NC = _PIN_79_GPI,
} EnumPinshareInfoPIN79;

//---------------------------------------------------------------------------
// Function : TXA3N
// Pinshare : 0x101F
// MCU Ctrl : 0xFE0F at _PIN_80_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_80                                 (_PIN_80_TXA3N_8B)

typedef enum
{
    _PIN_80_HI_Z = 0x00,
    _PIN_80_GPI = 0x01,
    _PIN_80_TXA3N_8B = 0x04,
    _PIN_80_NC = _PIN_80_GPI,
} EnumPinshareInfoPIN80;

//---------------------------------------------------------------------------
// Function : TXACP
// Pinshare : 0x1020
// MCU Ctrl : 0xFE10 at _PIN_81_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_81                                 (_PIN_81_TXACP_8B)

typedef enum
{
    _PIN_81_HI_Z = 0x00,
    _PIN_81_GPI = 0x01,
    _PIN_81_TXACP_8B = 0x04,
    _PIN_81_NC = _PIN_81_GPI,
} EnumPinshareInfoPIN81;

//---------------------------------------------------------------------------
// Function : TXACN
// Pinshare : 0x1021
// MCU Ctrl : 0xFE11 at _PIN_82_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_82                                 (_PIN_82_TXACN_8B)

typedef enum
{
    _PIN_82_HI_Z = 0x00,
    _PIN_82_GPI = 0x01,
    _PIN_82_TXACN_8B = 0x04,
    _PIN_82_NC = _PIN_82_GPI,
} EnumPinshareInfoPIN82;

//---------------------------------------------------------------------------
// Function : TXA2P
// Pinshare : 0x1022
// MCU Ctrl : 0xFE12 at _PIN_83_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_83                                 (_PIN_83_TXA2P_8B)

typedef enum
{
    _PIN_83_HI_Z = 0x00,
    _PIN_83_GPI = 0x01,
    _PIN_83_TXA2P_8B = 0x04,
    _PIN_83_NC = _PIN_83_GPI,
} EnumPinshareInfoPIN83;

//---------------------------------------------------------------------------
// Function : TXA2N
// Pinshare : 0x1023
// MCU Ctrl : 0xFE13 at _PIN_84_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_84                                 (_PIN_84_TXA2N_8B)

typedef enum
{
    _PIN_84_HI_Z = 0x00,
    _PIN_84_GPI = 0x01,
    _PIN_84_TXA2N_8B = 0x04,
    _PIN_84_NC = _PIN_84_GPI,
} EnumPinshareInfoPIN84;

//---------------------------------------------------------------------------
// Function : TXA1P
// Pinshare : 0x1024
// MCU Ctrl : 0xFE14 at _PIN_85_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_85                                 (_PIN_85_TXA1P_8B)

typedef enum
{
    _PIN_85_HI_Z = 0x00,
    _PIN_85_GPI = 0x01,
    _PIN_85_TXA1P_8B = 0x04,
    _PIN_85_NC = _PIN_85_GPI,
} EnumPinshareInfoPIN85;

//---------------------------------------------------------------------------
// Function : TXA1N
// Pinshare : 0x1025
// MCU Ctrl : 0xFE15 at _PIN_86_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_86                                 (_PIN_86_TXA1N_8B)

typedef enum
{
    _PIN_86_HI_Z = 0x00,
    _PIN_86_GPI = 0x01,
    _PIN_86_TXA1N_8B = 0x04,
    _PIN_86_NC = _PIN_86_GPI,
} EnumPinshareInfoPIN86;

//---------------------------------------------------------------------------
// Function : TXA0P
// Pinshare : 0x1026
// MCU Ctrl : 0xFE16 at _PIN_87_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_87                                 (_PIN_87_TXA0P_8B)

typedef enum
{
    _PIN_87_HI_Z = 0x00,
    _PIN_87_GPI = 0x01,
    _PIN_87_TXA0P_8B = 0x04,
    _PIN_87_NC = _PIN_87_GPI,
} EnumPinshareInfoPIN87;

//---------------------------------------------------------------------------
// Function : TXA0N
// Pinshare : 0x1027
// MCU Ctrl : 0xFE17 at _PIN_88_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_88                                 (_PIN_88_TXA0N_8B)

typedef enum
{
    _PIN_88_HI_Z = 0x00,
    _PIN_88_GPI = 0x01,
    _PIN_88_TXA0N_8B = 0x04,
    _PIN_88_NC = _PIN_88_GPI,
} EnumPinshareInfoPIN88;

//---------------------------------------------------------------------------
// Function : DP_SINK_ASS_N1
// Pinshare : 0x1028
// MCU Ctrl : 0xFE18 at _PIN_90_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_90                                 (_PIN_90_GPI)

typedef enum
{
    _PIN_90_GPI = 0x00,
    _PIN_90_GPO_PP = 0x01,
    _PIN_90_GPO_OD = 0x02,
    _PIN_90_PWM0_PP = 0x03,
    _PIN_90_PWM0_OD = 0x04,
    _PIN_90_TCON12 = 0x05,
    _PIN_90_TEST12B_OUT0 = 0x06,
    _PIN_90_TEST12B_OUT1 = 0x07,
    _PIN_90_TEST12B_OUT2 = 0x08,
    _PIN_90_TEST12B_OUT3 = 0x09,
    _PIN_90_TEST12B_OUT4 = 0x0A,
    _PIN_90_TEST12B_OUT5 = 0x0B,
    _PIN_90_TEST12B_OUT6 = 0x0C,
    _PIN_90_TEST12B_OUT7 = 0x0D,
    _PIN_90_TEST12B_OUT8 = 0x0E,
    _PIN_90_TEST12B_OUT9 = 0x0F,
    _PIN_90_TEST12B_OUT10 = 0x10,
    _PIN_90_TEST12B_OUT11 = 0x11,
    _PIN_90_NC = _PIN_90_GPO_PP,
} EnumPinshareInfoPIN90;

//---------------------------------------------------------------------------
// Function : DP_SINK_ASS_P1
// Pinshare : 0x1029
// MCU Ctrl : 0xFE19 at _PIN_91_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_91                                 (_PIN_91_GPI)

typedef enum
{
    _PIN_91_GPI = 0x00,
    _PIN_91_GPO_PP = 0x01,
    _PIN_91_GPO_OD = 0x02,
    _PIN_91_PWM1_PP = 0x03,
    _PIN_91_PWM1_OD = 0x04,
    _PIN_91_TCON13 = 0x05,
    _PIN_91_TEST12B_OUT0 = 0x06,
    _PIN_91_TEST12B_OUT1 = 0x07,
    _PIN_91_TEST12B_OUT2 = 0x08,
    _PIN_91_TEST12B_OUT3 = 0x09,
    _PIN_91_TEST12B_OUT4 = 0x0A,
    _PIN_91_TEST12B_OUT5 = 0x0B,
    _PIN_91_TEST12B_OUT6 = 0x0C,
    _PIN_91_TEST12B_OUT7 = 0x0D,
    _PIN_91_TEST12B_OUT8 = 0x0E,
    _PIN_91_TEST12B_OUT9 = 0x0F,
    _PIN_91_TEST12B_OUT10 = 0x10,
    _PIN_91_TEST12B_OUT11 = 0x11,
    _PIN_91_NC = _PIN_91_GPO_PP,
} EnumPinshareInfoPIN91;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102A
// MCU Ctrl : 0xFE1A at _PIN_92_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_92                                 (_PIN_92_NC)

typedef enum
{
    _PIN_92_GPI = 0x00,
    _PIN_92_GPO_PP = 0x01,
    _PIN_92_GPO_OD = 0x02,
    _PIN_92_PWM3_PP = 0x03,
    _PIN_92_PWM3_OD = 0x04,
    _PIN_92_TCON7 = 0x05,
    _PIN_92_TEST12B_OUT0 = 0x06,
    _PIN_92_TEST12B_OUT1 = 0x07,
    _PIN_92_TEST12B_OUT2 = 0x08,
    _PIN_92_TEST12B_OUT3 = 0x09,
    _PIN_92_TEST12B_OUT4 = 0x0A,
    _PIN_92_TEST12B_OUT5 = 0x0B,
    _PIN_92_TEST12B_OUT6 = 0x0C,
    _PIN_92_TEST12B_OUT7 = 0x0D,
    _PIN_92_TEST12B_OUT8 = 0x0E,
    _PIN_92_TEST12B_OUT9 = 0x0F,
    _PIN_92_TEST12B_OUT10 = 0x10,
    _PIN_92_TEST12B_OUT11 = 0x11,
    _PIN_92_NC = _PIN_92_GPO_PP,
} EnumPinshareInfoPIN92;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102B
// MCU Ctrl : 0xFE1B at _PIN_93_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_93                                 (_PIN_93_NC)

typedef enum
{
    _PIN_93_GPI = 0x00,
    _PIN_93_GPO_PP = 0x01,
    _PIN_93_GPO_OD = 0x02,
    _PIN_93_PWM2_PP = 0x03,
    _PIN_93_PWM2_OD = 0x04,
    _PIN_93_TCON8 = 0x05,
    _PIN_93_TEST12B_OUT0 = 0x06,
    _PIN_93_TEST12B_OUT1 = 0x07,
    _PIN_93_TEST12B_OUT2 = 0x08,
    _PIN_93_TEST12B_OUT3 = 0x09,
    _PIN_93_TEST12B_OUT4 = 0x0A,
    _PIN_93_TEST12B_OUT5 = 0x0B,
    _PIN_93_TEST12B_OUT6 = 0x0C,
    _PIN_93_TEST12B_OUT7 = 0x0D,
    _PIN_93_TEST12B_OUT8 = 0x0E,
    _PIN_93_TEST12B_OUT9 = 0x0F,
    _PIN_93_TEST12B_OUT10 = 0x10,
    _PIN_93_TEST12B_OUT11 = 0x11,
    _PIN_93_NC = _PIN_93_GPO_PP,
} EnumPinshareInfoPIN93;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102C
// MCU Ctrl : 0xFE1C at _PIN_94_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_94                                 (_PIN_94_NC)

typedef enum
{
    _PIN_94_GPI = 0x00,
    _PIN_94_GPO_PP = 0x01,
    _PIN_94_GPO_OD = 0x02,
    _PIN_94_PWM1_PP = 0x03,
    _PIN_94_PWM1_OD = 0x04,
    _PIN_94_TCON9 = 0x05,
    _PIN_94_DCLK = 0x06,
    _PIN_94_TEST12B_OUT0 = 0x07,
    _PIN_94_TEST12B_OUT1 = 0x08,
    _PIN_94_TEST12B_OUT2 = 0x09,
    _PIN_94_TEST12B_OUT3 = 0x0A,
    _PIN_94_TEST12B_OUT4 = 0x0B,
    _PIN_94_TEST12B_OUT5 = 0x0C,
    _PIN_94_TEST12B_OUT6 = 0x0D,
    _PIN_94_TEST12B_OUT7 = 0x0E,
    _PIN_94_TEST12B_OUT8 = 0x0F,
    _PIN_94_TEST12B_OUT9 = 0x10,
    _PIN_94_TEST12B_OUT10 = 0x11,
    _PIN_94_TEST12B_OUT11 = 0x12,
    _PIN_94_NC = _PIN_94_GPO_PP,
} EnumPinshareInfoPIN94;

//---------------------------------------------------------------------------
// Function : FLASH_WP
// Pinshare : 0x102D
// MCU Ctrl : 0xFE1D at _PIN_96_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_96                                 (_PIN_96_GPO_PP)

typedef enum
{
    _PIN_96_GPI = 0x00,
    _PIN_96_GPO_PP = 0x01,
    _PIN_96_GPO_OD = 0x02,
    _PIN_96_M1_IDOMAIN_VS_OUT = 0x03,
    _PIN_96_TTL_DVS = 0x04,
    _PIN_96_CLKO = 0x05,
    _PIN_96_INT0_1 = 0x06,
    _PIN_96_TCON11 = 0x07,
    _PIN_96_TEST12B_OUT0 = 0x08,
    _PIN_96_TEST12B_OUT1 = 0x09,
    _PIN_96_TEST12B_OUT2 = 0x0A,
    _PIN_96_TEST12B_OUT3 = 0x0B,
    _PIN_96_TEST12B_OUT4 = 0x0C,
    _PIN_96_TEST12B_OUT5 = 0x0D,
    _PIN_96_TEST12B_OUT6 = 0x0E,
    _PIN_96_TEST12B_OUT7 = 0x0F,
    _PIN_96_TEST12B_OUT8 = 0x10,
    _PIN_96_TEST12B_OUT9 = 0x11,
    _PIN_96_TEST12B_OUT10 = 0x12,
    _PIN_96_TEST12B_OUT11 = 0x13,
    _PIN_96_NC = _PIN_96_GPO_PP,
} EnumPinshareInfoPIN96;

//---------------------------------------------------------------------------
// Function : Panel_ON
// Pinshare : 0x102E
// MCU Ctrl : 0xFE1E at _PIN_97_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_97                                 (_PIN_97_GPO_OD)

typedef enum
{
    _PIN_97_GPI = 0x00,
    _PIN_97_GPO_PP = 0x01,
    _PIN_97_GPO_OD = 0x02,
    _PIN_97_PWM2_PP = 0x03,
    _PIN_97_PWM2_OD = 0x04,
    _PIN_97_IICSCL_0_2 = 0x05,
    _PIN_97_UART_TX_0_3 = 0x06,
    _PIN_97_INT1_1 = 0x0A,
    _PIN_97_M1_IDOMAIN_VS_OUT = 0x0B,
    _PIN_97_TCON11 = 0x0C,
    _PIN_97_DCLK = 0x0D,
    _PIN_97_TTL_DHS = 0x0E,
    _PIN_97_TEST12B_OUT0 = 0x0F,
    _PIN_97_TEST12B_OUT1 = 0x10,
    _PIN_97_TEST12B_OUT2 = 0x11,
    _PIN_97_TEST12B_OUT3 = 0x12,
    _PIN_97_TEST12B_OUT4 = 0x13,
    _PIN_97_TEST12B_OUT5 = 0x14,
    _PIN_97_TEST12B_OUT6 = 0x15,
    _PIN_97_TEST12B_OUT7 = 0x16,
    _PIN_97_TEST12B_OUT8 = 0x17,
    _PIN_97_TEST12B_OUT9 = 0x18,
    _PIN_97_TEST12B_OUT10 = 0x19,
    _PIN_97_TEST12B_OUT11 = 0x1A,
    _PIN_97_NC = _PIN_97_GPO_PP,
} EnumPinshareInfoPIN97;

//---------------------------------------------------------------------------
// Function : TTS_FLASH_WP
// Pinshare : 0x102F
// MCU Ctrl : 0xFE1F at _PIN_98_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_98                                 (_PIN_98_GPO_OD)

typedef enum
{
    _PIN_98_GPI = 0x00,
    _PIN_98_GPO_PP = 0x01,
    _PIN_98_GPO_OD = 0x02,
    _PIN_98_PWM3_PP = 0x03,
    _PIN_98_PWM3_OD = 0x04,
    _PIN_98_IICSDA_0_2 = 0x05,
    _PIN_98_UART_RX_0_3 = 0x06,
    _PIN_98_T0 = 0x0A,
    _PIN_98_TTL_DEN = 0x0B,
    _PIN_98_TCON9 = 0x0C,
    _PIN_98_TEST12B_OUT0 = 0x0D,
    _PIN_98_TEST12B_OUT1 = 0x0E,
    _PIN_98_TEST12B_OUT2 = 0x0F,
    _PIN_98_TEST12B_OUT3 = 0x10,
    _PIN_98_TEST12B_OUT4 = 0x11,
    _PIN_98_TEST12B_OUT5 = 0x12,
    _PIN_98_TEST12B_OUT6 = 0x13,
    _PIN_98_TEST12B_OUT7 = 0x14,
    _PIN_98_TEST12B_OUT8 = 0x15,
    _PIN_98_TEST12B_OUT9 = 0x16,
    _PIN_98_TEST12B_OUT10 = 0x17,
    _PIN_98_TEST12B_OUT11 = 0x18,
    _PIN_98_NC = _PIN_98_GPO_PP,
} EnumPinshareInfoPIN98;

//---------------------------------------------------------------------------
// Function : HDMI_CABLE_DETECT_0
// Pinshare : 0x1030
// MCU Ctrl : 0xFE20 at _PIN_99_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_99                                 (_PIN_99_GPI)

typedef enum
{
    _PIN_99_GPI = 0x00,
    _PIN_99_GPO_PP = 0x01,
    _PIN_99_GPO_OD = 0x02,
    _PIN_99_PWM2_PP = 0x03,
    _PIN_99_PWM2_OD = 0x04,
    _PIN_99_PWM3_PP = 0x05,
    _PIN_99_PWM3_OD = 0x06,
    _PIN_99_T1 = 0x07,
    _PIN_99_M1_IDOMAIN_HS_OUT = 0x08,
    _PIN_99_TTL_DHS = 0x09,
    _PIN_99_TCON13 = 0x0A,
    _PIN_99_TEST12B_OUT0 = 0x0B,
    _PIN_99_TEST12B_OUT1 = 0x0C,
    _PIN_99_TEST12B_OUT2 = 0x0D,
    _PIN_99_TEST12B_OUT3 = 0x0E,
    _PIN_99_TEST12B_OUT4 = 0x0F,
    _PIN_99_TEST12B_OUT5 = 0x10,
    _PIN_99_TEST12B_OUT6 = 0x11,
    _PIN_99_TEST12B_OUT7 = 0x12,
    _PIN_99_TEST12B_OUT8 = 0x13,
    _PIN_99_TEST12B_OUT9 = 0x14,
    _PIN_99_TEST12B_OUT10 = 0x15,
    _PIN_99_TEST12B_OUT11 = 0x16,
    _PIN_99_MCK = 0x17,
    _PIN_99_NC = _PIN_99_GPO_PP,
} EnumPinshareInfoPIN99;

//---------------------------------------------------------------------------
// Function : DDCSCL_VGA
// Pinshare : 0x1031
// MCU Ctrl : 0xFE21 at _PIN_100_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_100                                (_PIN_100_DDCSCL_VGA_0_1)

typedef enum
{
    _PIN_100_GPI = 0x00,
    _PIN_100_GPO_PP = 0x01,
    _PIN_100_GPO_OD = 0x02,
    _PIN_100_DDCSCL_VGA_0_1 = 0x03,
    _PIN_100_PWM_IN_0_0 = 0x04,
    _PIN_100_AUX_D2 = 0x05,
    _PIN_100_DCLK = 0x06,
    _PIN_100_TCON8 = 0x07,
    _PIN_100_T2EX = 0x08,
    _PIN_100_TEST12B_OUT0 = 0x09,
    _PIN_100_TEST12B_OUT1 = 0x0A,
    _PIN_100_TEST12B_OUT2 = 0x0B,
    _PIN_100_TEST12B_OUT3 = 0x0C,
    _PIN_100_TEST12B_OUT4 = 0x0D,
    _PIN_100_TEST12B_OUT5 = 0x0E,
    _PIN_100_TEST12B_OUT6 = 0x0F,
    _PIN_100_TEST12B_OUT7 = 0x10,
    _PIN_100_TEST12B_OUT8 = 0x11,
    _PIN_100_TEST12B_OUT9 = 0x12,
    _PIN_100_TEST12B_OUT10 = 0x13,
    _PIN_100_TEST12B_OUT11 = 0x14,
    _PIN_100_NC = _PIN_100_GPO_PP,
} EnumPinshareInfoPIN100;

//---------------------------------------------------------------------------
// Function : DDCSDA_VGA
// Pinshare : 0x1032
// MCU Ctrl : 0xFE22 at _PIN_101_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_101                                (_PIN_101_DDCSDA_VGA_0_1)

typedef enum
{
    _PIN_101_GPI = 0x00,
    _PIN_101_GPO_PP = 0x01,
    _PIN_101_GPO_OD = 0x02,
    _PIN_101_DDCSDA_VGA_0_1 = 0x03,
    _PIN_101_PWM0_PP = 0x04,
    _PIN_101_PWM0_OD = 0x05,
    _PIN_101_PWM_OUT_0_0 = 0x06,
    _PIN_101_AUX_D1 = 0x07,
    _PIN_101_TTL_DVS = 0x08,
    _PIN_101_TCON7 = 0x09,
    _PIN_101_TEST12B_OUT0 = 0x0A,
    _PIN_101_TEST12B_OUT1 = 0x0B,
    _PIN_101_TEST12B_OUT2 = 0x0C,
    _PIN_101_TEST12B_OUT3 = 0x0D,
    _PIN_101_TEST12B_OUT4 = 0x0E,
    _PIN_101_TEST12B_OUT5 = 0x0F,
    _PIN_101_TEST12B_OUT6 = 0x10,
    _PIN_101_TEST12B_OUT7 = 0x11,
    _PIN_101_TEST12B_OUT8 = 0x12,
    _PIN_101_TEST12B_OUT9 = 0x13,
    _PIN_101_TEST12B_OUT10 = 0x14,
    _PIN_101_TEST12B_OUT11 = 0x15,
    _PIN_101_NC = _PIN_101_GPO_PP,
} EnumPinshareInfoPIN101;

//---------------------------------------------------------------------------
// Function : ADJBACKLITE
// Pinshare : 0x1033
// MCU Ctrl : 0xFE23 at _PIN_102_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_102                                (_PIN_102_PWM0_PP)

typedef enum
{
    _PIN_102_GPI = 0x00,
    _PIN_102_GPO_PP = 0x01,
    _PIN_102_GPO_OD = 0x02,
    _PIN_102_PWM0_PP = 0x03,
    _PIN_102_PWM0_OD = 0x04,
    _PIN_102_TCON12 = 0x05,
    _PIN_102_DCLK = 0x06,
    _PIN_102_TEST12B_OUT0 = 0x07,
    _PIN_102_TEST12B_OUT1 = 0x08,
    _PIN_102_TEST12B_OUT2 = 0x09,
    _PIN_102_TEST12B_OUT3 = 0x0A,
    _PIN_102_TEST12B_OUT4 = 0x0B,
    _PIN_102_TEST12B_OUT5 = 0x0C,
    _PIN_102_TEST12B_OUT6 = 0x0D,
    _PIN_102_TEST12B_OUT7 = 0x0E,
    _PIN_102_TEST12B_OUT8 = 0x0F,
    _PIN_102_TEST12B_OUT9 = 0x10,
    _PIN_102_TEST12B_OUT10 = 0x11,
    _PIN_102_TEST12B_OUT11 = 0x12,
    _PIN_102_NC = _PIN_102_GPO_PP,
} EnumPinshareInfoPIN102;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1034
// MCU Ctrl : 0xFE24 at _PIN_108_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_108                                (_PIN_108_NC)

typedef enum
{
    _PIN_108_GPI = 0x00,
    _PIN_108_GPO_PP = 0x01,
    _PIN_108_GPO_OD = 0x02,
    _PIN_108_PWM3_PP = 0x03,
    _PIN_108_PWM3_OD = 0x04,
    _PIN_108_PWM1_PP = 0x05,
    _PIN_108_PWM1_OD = 0x06,
    _PIN_108_TCON13 = 0x08,
    _PIN_108_TEST12B_OUT0 = 0x09,
    _PIN_108_TEST12B_OUT1 = 0x0A,
    _PIN_108_TEST12B_OUT2 = 0x0B,
    _PIN_108_TEST12B_OUT3 = 0x0C,
    _PIN_108_TEST12B_OUT4 = 0x0D,
    _PIN_108_TEST12B_OUT5 = 0x0E,
    _PIN_108_TEST12B_OUT6 = 0x0F,
    _PIN_108_TEST12B_OUT7 = 0x10,
    _PIN_108_TEST12B_OUT8 = 0x11,
    _PIN_108_TEST12B_OUT9 = 0x12,
    _PIN_108_TEST12B_OUT10 = 0x13,
    _PIN_108_TEST12B_OUT11 = 0x14,
    _PIN_108_NC = _PIN_108_GPO_PP,
} EnumPinshareInfoPIN108;

//---------------------------------------------------------------------------
// Function : DDCSCL_0
// Pinshare : 0x1035
// MCU Ctrl : 0xFE25 at _PIN_110_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_110                                (_PIN_110_DDCSCL_0)

typedef enum
{
    _PIN_110_GPI = 0x00,
    _PIN_110_GPO_PP = 0x01,
    _PIN_110_GPO_OD = 0x02,
    _PIN_110_DPRX_AUX_P_0 = 0x03,
    _PIN_110_DDCSCL_0 = 0x04,
    _PIN_110_TEST12B_OUT0 = 0x05,
    _PIN_110_TEST12B_OUT1 = 0x06,
    _PIN_110_TEST12B_OUT2 = 0x07,
    _PIN_110_TEST12B_OUT3 = 0x08,
    _PIN_110_TEST12B_OUT4 = 0x09,
    _PIN_110_TEST12B_OUT5 = 0x0A,
    _PIN_110_TEST12B_OUT6 = 0x0B,
    _PIN_110_TEST12B_OUT7 = 0x0C,
    _PIN_110_TEST12B_OUT8 = 0x0D,
    _PIN_110_TEST12B_OUT9 = 0x0E,
    _PIN_110_TEST12B_OUT10 = 0x0F,
    _PIN_110_TEST12B_OUT11 = 0x10,
    _PIN_110_NC = _PIN_110_GPO_PP,
} EnumPinshareInfoPIN110;

//---------------------------------------------------------------------------
// Function : DDCSDA_0
// Pinshare : 0x1036
// MCU Ctrl : 0xFE26 at _PIN_111_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_111                                (_PIN_111_DDCSDA_0)

typedef enum
{
    _PIN_111_GPI = 0x00,
    _PIN_111_GPO_PP = 0x01,
    _PIN_111_GPO_OD = 0x02,
    _PIN_111_DPRX_AUX_N_0 = 0x03,
    _PIN_111_DDCSDA_0 = 0x04,
    _PIN_111_TEST12B_OUT0 = 0x05,
    _PIN_111_TEST12B_OUT1 = 0x06,
    _PIN_111_TEST12B_OUT2 = 0x07,
    _PIN_111_TEST12B_OUT3 = 0x08,
    _PIN_111_TEST12B_OUT4 = 0x09,
    _PIN_111_TEST12B_OUT5 = 0x0A,
    _PIN_111_TEST12B_OUT6 = 0x0B,
    _PIN_111_TEST12B_OUT7 = 0x0C,
    _PIN_111_TEST12B_OUT8 = 0x0D,
    _PIN_111_TEST12B_OUT9 = 0x0E,
    _PIN_111_TEST12B_OUT10 = 0x0F,
    _PIN_111_TEST12B_OUT11 = 0x10,
    _PIN_111_NC = _PIN_111_GPO_PP,
} EnumPinshareInfoPIN111;

//---------------------------------------------------------------------------
// Function : AUX_CHP1
// Pinshare : 0x1037
// MCU Ctrl : 0xFE27 at _PIN_112_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_112                                (_PIN_112_DPRX_AUX_P_1)

typedef enum
{
    _PIN_112_GPI = 0x00,
    _PIN_112_GPO_PP = 0x01,
    _PIN_112_GPO_OD = 0x02,
    _PIN_112_DPRX_AUX_P_1 = 0x03,
    _PIN_112_DDCSCL_1 = 0x04,
    _PIN_112_TEST12B_OUT0 = 0x05,
    _PIN_112_TEST12B_OUT1 = 0x06,
    _PIN_112_TEST12B_OUT2 = 0x07,
    _PIN_112_TEST12B_OUT3 = 0x08,
    _PIN_112_TEST12B_OUT4 = 0x09,
    _PIN_112_TEST12B_OUT5 = 0x0A,
    _PIN_112_TEST12B_OUT6 = 0x0B,
    _PIN_112_TEST12B_OUT7 = 0x0C,
    _PIN_112_TEST12B_OUT8 = 0x0D,
    _PIN_112_TEST12B_OUT9 = 0x0E,
    _PIN_112_TEST12B_OUT10 = 0x0F,
    _PIN_112_TEST12B_OUT11 = 0x10,
    _PIN_112_NC = _PIN_112_GPO_PP,
} EnumPinshareInfoPIN112;

//---------------------------------------------------------------------------
// Function : AUX_CHN1
// Pinshare : 0x1038
// MCU Ctrl : 0xFE28 at _PIN_113_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_113                                (_PIN_113_DPRX_AUX_N_1)

typedef enum
{
    _PIN_113_GPI = 0x00,
    _PIN_113_GPO_PP = 0x01,
    _PIN_113_GPO_OD = 0x02,
    _PIN_113_DPRX_AUX_N_1 = 0x03,
    _PIN_113_DDCSDA_1 = 0x04,
    _PIN_113_TEST12B_OUT0 = 0x05,
    _PIN_113_TEST12B_OUT1 = 0x06,
    _PIN_113_TEST12B_OUT2 = 0x07,
    _PIN_113_TEST12B_OUT3 = 0x08,
    _PIN_113_TEST12B_OUT4 = 0x09,
    _PIN_113_TEST12B_OUT5 = 0x0A,
    _PIN_113_TEST12B_OUT6 = 0x0B,
    _PIN_113_TEST12B_OUT7 = 0x0C,
    _PIN_113_TEST12B_OUT8 = 0x0D,
    _PIN_113_TEST12B_OUT9 = 0x0E,
    _PIN_113_TEST12B_OUT10 = 0x0F,
    _PIN_113_TEST12B_OUT11 = 0x10,
    _PIN_113_NC = _PIN_113_GPO_PP,
} EnumPinshareInfoPIN113;

//---------------------------------------------------------------------------
// Function : KEYPAD_LED1
// Pinshare : 0x1039
// MCU Ctrl : 0xFE29 at _PIN_114_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_114                                (_PIN_114_GPO_PP)

typedef enum
{
    _PIN_114_GPI = 0x00,
    _PIN_114_GPO_PP = 0x01,
    _PIN_114_GPO_OD = 0x02,
    _PIN_114_PWM2_PP = 0x03,
    _PIN_114_PWM2_OD = 0x04,
    _PIN_114_TCON11 = 0x06,
    _PIN_114_TEST12B_OUT0 = 0x07,
    _PIN_114_TEST12B_OUT1 = 0x08,
    _PIN_114_TEST12B_OUT2 = 0x09,
    _PIN_114_TEST12B_OUT3 = 0x0A,
    _PIN_114_TEST12B_OUT4 = 0x0B,
    _PIN_114_TEST12B_OUT5 = 0x0C,
    _PIN_114_TEST12B_OUT6 = 0x0D,
    _PIN_114_TEST12B_OUT7 = 0x0E,
    _PIN_114_TEST12B_OUT8 = 0x0F,
    _PIN_114_TEST12B_OUT9 = 0x10,
    _PIN_114_TEST12B_OUT10 = 0x11,
    _PIN_114_TEST12B_OUT11 = 0x12,
    _PIN_114_NC = _PIN_114_GPO_PP,
} EnumPinshareInfoPIN114;

//---------------------------------------------------------------------------
// Function : KEYPAD_LED2
// Pinshare : 0x103A
// MCU Ctrl : 0xFE2A at _PIN_115_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_115                                (_PIN_115_GPO_PP)

typedef enum
{
    _PIN_115_GPI = 0x00,
    _PIN_115_GPO_PP = 0x01,
    _PIN_115_GPO_OD = 0x02,
    _PIN_115_PWM1_PP = 0x03,
    _PIN_115_PWM1_OD = 0x04,
    _PIN_115_IRQB = 0x05,
    _PIN_115_TCON12 = 0x06,
    _PIN_115_TEST12B_OUT0 = 0x07,
    _PIN_115_TEST12B_OUT1 = 0x08,
    _PIN_115_TEST12B_OUT2 = 0x09,
    _PIN_115_TEST12B_OUT3 = 0x0A,
    _PIN_115_TEST12B_OUT4 = 0x0B,
    _PIN_115_TEST12B_OUT5 = 0x0C,
    _PIN_115_TEST12B_OUT6 = 0x0D,
    _PIN_115_TEST12B_OUT7 = 0x0E,
    _PIN_115_TEST12B_OUT8 = 0x0F,
    _PIN_115_TEST12B_OUT9 = 0x10,
    _PIN_115_TEST12B_OUT10 = 0x11,
    _PIN_115_TEST12B_OUT11 = 0x12,
    _PIN_115_NC = _PIN_115_GPO_PP,
} EnumPinshareInfoPIN115;

//---------------------------------------------------------------------------
// Function : EDPTX_AUXN
// Pinshare : 0x103B
// MCU Ctrl : 0xFE2B at _PIN_120_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_120                                (_PIN_120_EDPTX_AUX_N_0)

typedef enum
{
    _PIN_120_GPI = 0x00,
    _PIN_120_GPO_PP = 0x01,
    _PIN_120_GPO_OD = 0x02,
    _PIN_120_EDPTX_AUX_N_0 = 0x03,
    _PIN_120_PWM2_PP = 0x04,
    _PIN_120_PWM2_OD = 0x05,
    _PIN_120_TTL_DEN = 0x06,
    _PIN_120_DCLK = 0x07,
    _PIN_120_TEST12B_OUT0 = 0x08,
    _PIN_120_TEST12B_OUT1 = 0x09,
    _PIN_120_TEST12B_OUT2 = 0x0A,
    _PIN_120_TEST12B_OUT3 = 0x0B,
    _PIN_120_TEST12B_OUT4 = 0x0C,
    _PIN_120_TEST12B_OUT5 = 0x0D,
    _PIN_120_TEST12B_OUT6 = 0x0E,
    _PIN_120_TEST12B_OUT7 = 0x0F,
    _PIN_120_TEST12B_OUT8 = 0x10,
    _PIN_120_TEST12B_OUT9 = 0x11,
    _PIN_120_TEST12B_OUT10 = 0x12,
    _PIN_120_TEST12B_OUT11 = 0x13,
    _PIN_120_NC = _PIN_120_GPO_PP,
} EnumPinshareInfoPIN120;

//---------------------------------------------------------------------------
// Function : EDPTX_AUXP
// Pinshare : 0x103C
// MCU Ctrl : 0xFE2C at _PIN_121_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_121                                (_PIN_121_EDPTX_AUX_P_0)

typedef enum
{
    _PIN_121_GPI = 0x00,
    _PIN_121_GPO_PP = 0x01,
    _PIN_121_GPO_OD = 0x02,
    _PIN_121_EDPTX_AUX_P_0 = 0x03,
    _PIN_121_PWM3_PP = 0x04,
    _PIN_121_PWM3_OD = 0x05,
    _PIN_121_M1_IDOMAIN_VS_OUT = 0x06,
    _PIN_121_TTL_DVS = 0x07,
    _PIN_121_DCLK = 0x08,
    _PIN_121_TEST12B_OUT0 = 0x09,
    _PIN_121_TEST12B_OUT1 = 0x0A,
    _PIN_121_TEST12B_OUT2 = 0x0B,
    _PIN_121_TEST12B_OUT3 = 0x0C,
    _PIN_121_TEST12B_OUT4 = 0x0D,
    _PIN_121_TEST12B_OUT5 = 0x0E,
    _PIN_121_TEST12B_OUT6 = 0x0F,
    _PIN_121_TEST12B_OUT7 = 0x10,
    _PIN_121_TEST12B_OUT8 = 0x11,
    _PIN_121_TEST12B_OUT9 = 0x12,
    _PIN_121_TEST12B_OUT10 = 0x13,
    _PIN_121_TEST12B_OUT11 = 0x14,
    _PIN_121_NC = _PIN_121_GPO_PP,
} EnumPinshareInfoPIN121;

//---------------------------------------------------------------------------
// Function : RX_ATL
// Pinshare : 0x103D
// MCU Ctrl : 0xFE2D at _PIN_122_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_122                                (_PIN_122_GPO_OD)

typedef enum
{
    _PIN_122_GPI = 0x00,
    _PIN_122_GPO_PP = 0x01,
    _PIN_122_GPO_OD = 0x02,
    _PIN_122_PWM1_PP = 0x03,
    _PIN_122_PWM1_OD = 0x04,
    _PIN_122_PWM0_PP = 0x05,
    _PIN_122_PWM0_OD = 0x06,
    _PIN_122_MCK = 0x07,
    _PIN_122_TCON7 = 0x08,
    _PIN_122_TCON13 = 0x09,
    _PIN_122_TEST12B_OUT0 = 0x0A,
    _PIN_122_TEST12B_OUT1 = 0x0B,
    _PIN_122_TEST12B_OUT2 = 0x0C,
    _PIN_122_TEST12B_OUT3 = 0x0D,
    _PIN_122_TEST12B_OUT4 = 0x0E,
    _PIN_122_TEST12B_OUT5 = 0x0F,
    _PIN_122_TEST12B_OUT6 = 0x10,
    _PIN_122_TEST12B_OUT7 = 0x11,
    _PIN_122_TEST12B_OUT8 = 0x12,
    _PIN_122_TEST12B_OUT9 = 0x13,
    _PIN_122_TEST12B_OUT10 = 0x14,
    _PIN_122_TEST12B_OUT11 = 0x15,
    _PIN_122_NC = _PIN_122_GPO_PP,
} EnumPinshareInfoPIN122;

//---------------------------------------------------------------------------
// Function : RX_CC_ATH
// Pinshare : 0x103E
// MCU Ctrl : 0xFE2E at _PIN_123_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_123                                (_PIN_123_GPO_OD)

typedef enum
{
    _PIN_123_GPI = 0x00,
    _PIN_123_GPO_PP = 0x01,
    _PIN_123_GPO_OD = 0x02,
    _PIN_123_PWM2_PP = 0x03,
    _PIN_123_PWM2_OD = 0x04,
    _PIN_123_PWM_OUT_0_2 = 0x05,
    _PIN_123_TCON8 = 0x06,
    _PIN_123_TEST12B_OUT0 = 0x07,
    _PIN_123_TEST12B_OUT1 = 0x08,
    _PIN_123_TEST12B_OUT2 = 0x09,
    _PIN_123_TEST12B_OUT3 = 0x0A,
    _PIN_123_TEST12B_OUT4 = 0x0B,
    _PIN_123_TEST12B_OUT5 = 0x0C,
    _PIN_123_TEST12B_OUT6 = 0x0D,
    _PIN_123_TEST12B_OUT7 = 0x0E,
    _PIN_123_TEST12B_OUT8 = 0x0F,
    _PIN_123_TEST12B_OUT9 = 0x10,
    _PIN_123_TEST12B_OUT10 = 0x11,
    _PIN_123_TEST12B_OUT11 = 0x12,
    _PIN_123_NC = _PIN_123_GPO_PP,
} EnumPinshareInfoPIN123;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x103F
// MCU Ctrl : 0xFE2F at _PIN_124_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_124                                (_PIN_124_NC)

typedef enum
{
    _PIN_124_GPI = 0x00,
    _PIN_124_GPO_PP = 0x01,
    _PIN_124_GPO_OD = 0x02,
    _PIN_124_PWM0_PP = 0x03,
    _PIN_124_PWM0_OD = 0x04,
    _PIN_124_PWM3_PP = 0x05,
    _PIN_124_PWM3_OD = 0x06,
    _PIN_124_PWM_IN_0_2 = 0x07,
    _PIN_124_TCON7 = 0x08,
    _PIN_124_TCON9 = 0x09,
    _PIN_124_TEST12B_OUT0 = 0x0A,
    _PIN_124_TEST12B_OUT1 = 0x0B,
    _PIN_124_TEST12B_OUT2 = 0x0C,
    _PIN_124_TEST12B_OUT3 = 0x0D,
    _PIN_124_TEST12B_OUT4 = 0x0E,
    _PIN_124_TEST12B_OUT5 = 0x0F,
    _PIN_124_TEST12B_OUT6 = 0x10,
    _PIN_124_TEST12B_OUT7 = 0x11,
    _PIN_124_TEST12B_OUT8 = 0x12,
    _PIN_124_TEST12B_OUT9 = 0x13,
    _PIN_124_TEST12B_OUT10 = 0x14,
    _PIN_124_TEST12B_OUT11 = 0x15,
    _PIN_124_NC = _PIN_124_GPO_PP,
} EnumPinshareInfoPIN124;
