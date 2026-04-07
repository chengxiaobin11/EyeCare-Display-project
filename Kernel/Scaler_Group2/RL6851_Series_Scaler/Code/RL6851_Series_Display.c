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
// ID Code      : RL6851_Series_Display.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
typedef enum
{
    _LVDS_TYPE,
    _HIZ_TYPE,
} EnumLvdsPinshareType;
#endif
//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_LVDS)

void ScalerDisplayLvdsInitialTable(void);
void ScalerDisplayVcmControl(BYTE ucType);
void ScalerDisplayLvdsPower(bit bOn);
void ScalerDisplayLvdsClkInfoSelect(void);
void ScalerDisplayLvdsDrivingControl(BYTE ucDriv);
void ScalerDisplayLvdsPhaseConrol(void);
void ScalerDisplayLvdsSlewRateConrol(void);

void ScalerDisplayLvdsSetPhaseBand(BYTE ucPhaseBand);

bit ScalerDisplayGetLvdsPowerStatus(void);
void ScalerDisplayLvdsPLL(bit bOn);
void ScalerDisplayLvdsPadPower(bit bOn);
#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
void ScalerDisplayLvdsSettingControlByUser(void);
#endif

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
void ScalerDisplayLvdsPinshareSetting(EnumLvdsPinshareType enumLvdsPinshareType);
#endif
#endif // #if(_PANEL_STYLE == _PANEL_LVDS)

#if(_PANEL_STYLE == _PANEL_DPTX)
void ScalerDisplayUseLvdsPadPower(bit bOn);
#endif // #if(_PANEL_STYLE == _PANEL_DPTX)

void ScalerDisplaySetDspcLineLength(WORD usData);
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_PANEL_STYLE == _PANEL_LVDS)
//--------------------------------------------------
// Description  : Initial Settings for Display Interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsInitialTable(void)
{
#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
    // Set DISP mode is Hiz
    ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    ScalerDisplayLvdsPinshareSetting(_HIZ_TYPE);
#else
    // Set DISP mode is LVDS
    ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
#endif

    // Set Panel Display Type
    ScalerSetBit(P39_01_LVDS_DISPLAY_CONV_CTRL0, ~(_BIT7 | _BIT6 | _BIT0), ((_LVDS_OUTPUT_PORT << 6) | (_LVDS_TABLE_TYPE << 0)));

    // Display Resolution Control Settings
    ScalerSetBit(P39_01_LVDS_DISPLAY_CONV_CTRL0, ~(_BIT2 | _BIT1), (_PANEL_DISP_BIT_MODE << 1));

    // Set LVDS Interface Type
    ScalerSetByte(P39_06_LVDS_DISPLAY_CONV_CTRL5, ((_LVDS_RB_SWAP << 7) | (_LVDS_ML_SWAP << 6) | (_LVDS_PN_SWAP << 4) | (_BIT3) | (_LVDS_CLK_CHANNEL_SEL << 1) | (_LVDS_PAIR_MIRROR << 0)));

    // Set LVDS Display Content
    ScalerSetBit(P39_07_LVDS_DISPLAY_CONV_CTRL6, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((_LVDS_DVS_INVERT << 3) | (_LVDS_DHS_INVERT << 2) | (_LVDS_DEN_INVERT << 1) | (_BIT0)));

    // Set oclk_inv: Inverted(Falling Edge)
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_20_DISPLAY_CLOCK_FINE_TUNE, ~_BIT0, _BIT0);

    // Set LVDS ckpixel_inv Rising Edge(oclk_inv and ckpixel_inv edge should be opposite)
    ScalerSetBit(P55_03_LVDS_COMMON_AB_CTRL3, ~(_BIT4), _BIT4);

    // Set LVDS BW Parameter
    ScalerSetByte(P55_0D_LVDS_COMMON_AB_CTRL13, 0xE4);

    // Set LVDS common mode Voltage
    ScalerDisplayVcmControl(_LVDS_VCM_CONTROL);

    // Set LVDS Driving Double Current Disable
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_30_LVDS_PORTB_CTRL0, ~(_BIT4 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Set LVDS Output Termination Seletcion
    ScalerDisplayLvdsClkInfoSelect();

    // Set LVDS Driving Control
    ScalerDisplayLvdsDrivingControl(_LVDS_DRIV_CONTROL);

    // Set LVDS Phase Selection
    ScalerDisplayLvdsPhaseConrol();

    // Set LVDS data slew rate control
    ScalerDisplayLvdsSlewRateConrol();

    // Set LVDS TX output Data selection: Data / Termination
    ScalerDisplayLvdsTxDataSel();

    // Set LVDS TX Output Data Swap Selection
    ScalerDisplayLvdsTxPortSwap();

    // Disable LVDS CLK Signal, and Set To DC Level
    ScalerSetByte(P39_1D_LVDS_CLK_CTRL, 0x00);

#if(_LVDS_SHAPE_ADJUSTMENT == _LVDS_SHAPE_NONE)
    // Set LVDS Shape-adjustment with Default
    ScalerSetBit(P55_23_LVDS_PORTA_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerSetBit(P55_33_LVDS_PORTB_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

#elif(_LVDS_SHAPE_ADJUSTMENT == _LVDS_SHAPE_FAST_TO_SLOW)
    // Set LVDS Shape-adjustment Fast to Slow
    ScalerSetBit(P55_23_LVDS_PORTA_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT2 | _BIT0));
    ScalerSetBit(P55_33_LVDS_PORTB_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT3 | _BIT2 | _BIT0));

#elif(_LVDS_SHAPE_ADJUSTMENT == _LVDS_SHAPE_SLOW_TO_FAST)
    // Set LVDS Shape-adjustment Slow to Fast
    ScalerSetBit(P55_23_LVDS_PORTA_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2 | _BIT1));
    ScalerSetBit(P55_33_LVDS_PORTB_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2 | _BIT1));
#endif

    if(ScalerGlobalGetIDCode() == _RL6851_VER_A_ID_CODE)
    {
        // Set LVDS Shape-adjustment, A Version only LVDS can use Shape-adjustment, LVDS combo eDPTx cant use Shape-adjustment
        ScalerSetBit(P55_33_LVDS_PORTB_CTRL3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
    ScalerDisplayLvdsSettingControlByUser();
#endif
}

//--------------------------------------------------
// Description  : Set LVDS driving control
// Input Value  : VCM for Data and Clock pair
// Output Value : None
//--------------------------------------------------
void ScalerDisplayVcmControl(BYTE ucType)
{
    // Set LVDS common mode Voltage
    switch(ucType)
    {
        case _LVDS_VCM_LOW:

            // Vcm : 0.9V
            ScalerSetBit(P55_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT3));

            break;

        case _LVDS_VCM_NORMAL:

            // Vcm : 1.25V
            ScalerSetBit(P55_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1));

            break;

        case _LVDS_VCM_HIGH:

            // Vcm : 1.4V
            ScalerSetBit(P55_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1));

            break;

        case _LVDS_VCM_USER:

            ScalerSetBit(P55_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | (_LVDS_VCM_USER_LEVEL & 0x1F)));

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : LVDS Power Control
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPower(bit bOn)
{
    if(bOn == _ON)
    {
        // Enable LVDS Port CD IBGEN Power
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~_BIT7, _BIT7);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _OFF)
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
        // Set LVDS Port C Configuration: LVDS
        ScalerSetBit(P10_1E_PIN_SHARE_CTRL1E__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_1F_PIN_SHARE_CTRL1F__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_20_PIN_SHARE_CTRL20__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_21_PIN_SHARE_CTRL21__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_22_PIN_SHARE_CTRL22__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_23_PIN_SHARE_CTRL23__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_24_PIN_SHARE_CTRL24__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_25_PIN_SHARE_CTRL25__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_26_PIN_SHARE_CTRL26__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_27_PIN_SHARE_CTRL27__ON3, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
#endif
        // Disable Weakly Pull Down, Disable Strongly Pull Down
        ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), 0x00);
        ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), 0x00);
#endif
    }
    else
    {
        // Disable LVDS Port CD IBGEN Power
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~_BIT7, 0x00);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _OFF)
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
        // Set LVDS Port C Configuration: HiZ
        ScalerSetBit(P10_1E_PIN_SHARE_CTRL1E__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_1F_PIN_SHARE_CTRL1F__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_20_PIN_SHARE_CTRL20__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_21_PIN_SHARE_CTRL21__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_22_PIN_SHARE_CTRL22__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_23_PIN_SHARE_CTRL23__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_24_PIN_SHARE_CTRL24__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_25_PIN_SHARE_CTRL25__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_26_PIN_SHARE_CTRL26__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_27_PIN_SHARE_CTRL27__ON3, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif
#endif
    }
}

//--------------------------------------------------
// Description  : Set Dual Port LVDS Clk Infomation: CLK set 80ohm as Termination On / CLK set current 2x as Termination Off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsClkInfoSelect(void)
{
#if(_LVDS_TERMINATION_CONTROL == _ENABLE)
    // Set LVDS Output Termination 56ohm Initially
    ScalerSetByte(P55_27_LVDS_PORTA_CTRL7, 0xAA);
    ScalerSetByte(P55_28_LVDS_PORTA_CTRL8, 0xAA);
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_D) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerSetByte(P55_62_DPTX_Z0_TX_2, 0x33);
    ScalerSetByte(P55_63_DPTX_Z0_TX_3, 0x33);
#endif // End of #if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
#else
    // Set LVDS Output Termination Disable Initially
    ScalerSetByte(P55_27_LVDS_PORTA_CTRL7, 0x00);
    ScalerSetByte(P55_28_LVDS_PORTA_CTRL8, 0x00);
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_D) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P55_62_DPTX_Z0_TX_2, 0x00);
    ScalerSetByte(P55_63_DPTX_Z0_TX_3, 0x00);
#endif // End of #if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)
    // LVDS CLK(1 push 2): CLK set 72ohm as Termination on, parallel with 50 ohm(100 // 100), resistance = 41ohm
    // CLK set current 2x as Termination Off
#if(_LVDS_TERMINATION_CONTROL == _ENABLE)
#if(_LVDS_PAIR_MIRROR == _DISABLE)
#if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

    // Set LVDS TXCC Output Termination 72ohm
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT5 | _BIT4), _BIT4);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_1)

    // Set LVDS TXC1 Output Termination 72ohm
    ScalerSetBit(P55_27_LVDS_PORTA_CTRL7, ~(_BIT1 | _BIT0), _BIT0);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_2)

    // Set LVDS TXC2 Output Termination 72ohm
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT7 | _BIT6), _BIT6);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_3)

    // Set LVDS TXCC Output Termination 72ohm
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT5 | _BIT4), _BIT4);

#endif // End of #if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

#else // Else of #if(_LVDS_PAIR_MIRROR == _DISABLE)
#if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

    // Set LVDS TXC1 Output Termination 72ohm
    ScalerSetBit(P55_27_LVDS_PORTA_CTRL7, ~(_BIT1 | _BIT0), _BIT0);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_1)

    // Set LVDS TXCC Output Termination 72ohm
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT5 | _BIT4), _BIT4);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_2)

    // Set LVDS TXC2 Output Termination 72ohm
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT7 | _BIT6), _BIT6);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_3)

    // Set LVDS TXC1 Output Termination 72ohm
    ScalerSetBit(P55_27_LVDS_PORTA_CTRL7, ~(_BIT1 | _BIT0), _BIT0);

#endif // End of #if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)
#endif // End of #if(_LVDS_PAIR_MIRROR == _DISABLE)
#else // Else of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)
#if(_LVDS_PAIR_MIRROR == _DISABLE)
#if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

    // Set LVDS TXCC Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT3, _BIT3);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_1)

    // Set LVDS TXC1 Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT1, _BIT1);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_2)

    // Set LVDS TXC2 Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT2, _BIT2);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_3)

    // Set LVDS TXCC Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT3, _BIT3);

#endif // End of #if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

#else // Else of #if(_LVDS_PAIR_MIRROR == _DISABLE)
#if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)

    // Set LVDS TXC1 Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT1, _BIT1);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_1)

    // Set LVDS TXCC Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT3, _BIT3);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_2)

    // Set LVDS TXC2 Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT2, _BIT2);

#elif(_LVDS_CLK_CHANNEL_SEL == _MODE_3)

    // Set LVDS TXC1 Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT1, _BIT1);

#endif // End of #if(_LVDS_CLK_CHANNEL_SEL == _NORMAL_MODE)
#endif // End of #if(_LVDS_PAIR_MIRROR == _DISABLE)
#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#if(_LVDS_TERMINATION_CONTROL == _ENABLE)

    // Disable LVDS TXC Current 2x
    ScalerSetByte(P55_20_LVDS_PORTA_CTRL0, 0x00);

#endif // End of #if(_LVDS_TERMINATION_CONTROL == _DISABLE)
#endif // End of #if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)
}

//--------------------------------------------------
// Description  : Set LVDS driving control
// Input Value  : Driving current for Data and Clock pair
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsDrivingControl(BYTE ucDriv)
{
    BYTE ucEfuseDriv = 0;
    WORD usTempDriv = 0;

    // load LVDS driving from efuse
    ScalerEfuseGetData(_OTPMEMORY_LVDS_IBHN, 1, &ucEfuseDriv);

#if(_LVDS_TERMINATION_CONTROL == _ENABLE)
#if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-emphasis
    ScalerSetBit(P55_29_LVDS_PORTA_CTRL9, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_2A_LVDS_PORTA_CTRL10, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_50_DPTX_PREEM_TXA0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_51_DPTX_PREEM_TXA1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_52_DPTX_PREEM_TXB3, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_53_DPTX_PREEM_TXB4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 375 / 350) : 0x7F;

            break;

        case _LVDS_DRIV_CONTROL_2_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 450 / 350) : 0x99;

            break;

        case _LVDS_DRIV_CONTROL_3_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 575 / 350) : 0xC3;

            break;

        case _LVDS_DRIV_CONTROL_4_0:
        case _LVDS_DRIV_CONTROL_4_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 650 / 350) : 0xDD;

            break;

        case _LVDS_DRIV_CONTROL_1_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 275 / 350) : 0x5D;

            break;

        case _LVDS_DRIV_CONTROL_3_0:
        default:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 550 / 350) : 0xBB;

            break;
    }

#else // #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-emphasis
    ScalerSetBit(P55_29_LVDS_PORTA_CTRL9, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetBit(P55_2A_LVDS_PORTA_CTRL10, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT4 | _BIT2 | _BIT0));
    ScalerSetBit(P55_50_DPTX_PREEM_TXA0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_51_DPTX_PREEM_TXA1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_52_DPTX_PREEM_TXB3, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_53_DPTX_PREEM_TXB4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 425 / 350) : 0x90;

            break;

        case _LVDS_DRIV_CONTROL_2_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 500 / 350) : 0xAA;

            break;

        case _LVDS_DRIV_CONTROL_3_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 550 / 350) : 0xBB;

            break;

        case _LVDS_DRIV_CONTROL_4_0:
        case _LVDS_DRIV_CONTROL_4_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 575 / 350) : 0xC3;

            break;

        case _LVDS_DRIV_CONTROL_1_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 325 / 350) : 0x6E;

            break;

        case _LVDS_DRIV_CONTROL_3_0:
        default:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 525 / 350) : 0xB2;

            break;
    }
#endif // #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

#elif(_LVDS_TERMINATION_CONTROL == _DISABLE)
#if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-emphasis
    ScalerSetBit(P55_39_LVDS_PORTB_CTRL9, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_3A_LVDS_PORTB_CTRL10, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_50_DPTX_PREEM_TXA0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_51_DPTX_PREEM_TXA1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_52_DPTX_PREEM_TXB3, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P55_53_DPTX_PREEM_TXB4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 20 / 35) : 0x44;

            break;

        case _LVDS_DRIV_CONTROL_2_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 25 / 35) : 0x55;

            break;

        case _LVDS_DRIV_CONTROL_3_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? (ucEfuseDriv) : 0x77;

            break;

        case _LVDS_DRIV_CONTROL_4_0:
            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 40 / 35) : 0x88;

            break;

        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 45 / 35) : 0x99;

            break;

        case _LVDS_DRIV_CONTROL_1_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 15 / 35) : 0x33;

            break;

        case _LVDS_DRIV_CONTROL_3_0:
        default:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 30 / 35) : 0x66;

            break;
    }

#else

    // Set LVDS Pre-emphasis
    ScalerSetBit(P55_29_LVDS_PORTA_CTRL9, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetBit(P55_2A_LVDS_PORTA_CTRL10, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT4 | _BIT2 | _BIT0));
    ScalerSetBit(P55_50_DPTX_PREEM_TXA0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_51_DPTX_PREEM_TXA1, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_52_DPTX_PREEM_TXB3, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
    ScalerSetBit(P55_53_DPTX_PREEM_TXB4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 250 / 350) : 0x55;

            break;

        case _LVDS_DRIV_CONTROL_2_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 275 / 350) : 0x5D;

            break;

        case _LVDS_DRIV_CONTROL_3_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 325 / 350) : 0x6E;

            break;

        case _LVDS_DRIV_CONTROL_4_0:
        case _LVDS_DRIV_CONTROL_4_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ucEfuseDriv : 0x77;

            break;

        case _LVDS_DRIV_CONTROL_1_5:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 200 / 350) : 0x44;

            break;

        case _LVDS_DRIV_CONTROL_3_0:
        default:

            usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * 300 / 350) : 0x66;

            break;
    }
#endif // #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

    ScalerSetByte(P55_0C_LVDS_COMMON_AB_CTRL12, ((usTempDriv < 0xFF) ? usTempDriv : 0xFF));

    // Set LVDS TXD Driving Current
    ScalerSetByte(P55_57_DPTX_SWING_CURRENT_1, 0x77);
    ScalerSetByte(P55_58_DPTX_SWING_CURRENT_2, 0x77);

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
#if(_LVDS_TRIM_DRIV_CURRENT_BY_USER == _ENABLE)
    usTempDriv = ((ucEfuseDriv != 0) && (ucEfuseDriv != 0xFF)) ? ((DWORD)ucEfuseDriv * _LVDS_TRIM_DRIV_CURRENT_USER_ADUST / 3500) : ((DWORD)0x77 * _LVDS_TRIM_DRIV_CURRENT_USER_ADUST / 3500);

    ScalerSetByte(P55_0C_LVDS_COMMON_AB_CTRL12, ((usTempDriv < 0xFF) ? usTempDriv : 0xFF));
#else
    ScalerSetByte(P55_0C_LVDS_COMMON_AB_CTRL12, (_LVDS_DRIV_CURRENT_USER_ADUST & 0xFF));
#endif
#endif
}

//--------------------------------------------------
// Description  : LVDS Phase Selection Contorl
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPhaseConrol(void)
{
    BYTE ucLvdsPhaseSeedH = 0x03;
    BYTE ucLvdsPhaseSeedL = 0x0F;
    BYTE ucLvdsPhaseH = 0x00;
    BYTE ucLvdsPhaseL = 0x00;

    // ck7x inv = 0, PI Phase range 0~16
    ScalerSetBit(P55_21_LVDS_PORTA_CTRL1, ~_BIT7, 0x00);
    ScalerSetBit(P55_31_LVDS_PORTB_CTRL1, ~_BIT7, 0x00);

// PI_Phase_CD0 select
#if(_LVDS_PI_PHASE_CD0_SEL <= _LVDS_PHASE16)
    ucLvdsPhaseH = (ucLvdsPhaseSeedH << (_LVDS_PI_PHASE_CD0_SEL >> 2));
    ucLvdsPhaseL = (ucLvdsPhaseSeedL << (_LVDS_PI_PHASE_CD0_SEL % 8)) & 0xF0;

    ScalerSetBit(P55_04_LVDS_COMMON_AB_CTRL4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucLvdsPhaseH >> 4) & 0x0F));
    ScalerSetByte(P55_05_LVDS_COMMON_AB_CTRL5, (((ucLvdsPhaseH << 4) & 0xF0) | ((ucLvdsPhaseL >> 4) & 0x0F)));
#else
    ScalerSetBit(P55_04_LVDS_COMMON_AB_CTRL4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P55_05_LVDS_COMMON_AB_CTRL5, 0x30);
#endif

// PI_Phase_CD1 select
#if(_LVDS_PI_PHASE_CD1_SEL <= _LVDS_PHASE16)
    ucLvdsPhaseH = (ucLvdsPhaseSeedH << (_LVDS_PI_PHASE_CD1_SEL >> 2));
    ucLvdsPhaseL = (ucLvdsPhaseSeedL << (_LVDS_PI_PHASE_CD1_SEL % 8)) & 0xF0;

    ScalerSetBit(P55_06_LVDS_COMMON_AB_CTRL6, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucLvdsPhaseH >> 4) & 0x0F));
    ScalerSetByte(P55_07_LVDS_COMMON_AB_CTRL7, (((ucLvdsPhaseH << 4) & 0xF0) | ((ucLvdsPhaseL >> 4) & 0x0F)));
#else
    ScalerSetBit(P55_06_LVDS_COMMON_AB_CTRL6, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P55_07_LVDS_COMMON_AB_CTRL7, 0x30);
#endif

// PI_Phase_CD2 select
#if(_LVDS_PI_PHASE_CD2_SEL <= _LVDS_PHASE16)
    ucLvdsPhaseH = (ucLvdsPhaseSeedH << (_LVDS_PI_PHASE_CD2_SEL >> 2));
    ucLvdsPhaseL = (ucLvdsPhaseSeedL << (_LVDS_PI_PHASE_CD2_SEL % 8)) & 0xF0;

    ScalerSetBit(P55_08_LVDS_COMMON_AB_CTRL8, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucLvdsPhaseH >> 4) & 0x0F));
    ScalerSetByte(P55_09_LVDS_COMMON_AB_CTRL9, (((ucLvdsPhaseH << 4) & 0xF0) | ((ucLvdsPhaseL >> 4) & 0x0F)));
#else
    ScalerSetBit(P55_08_LVDS_COMMON_AB_CTRL8, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P55_09_LVDS_COMMON_AB_CTRL9, 0x30);
#endif

// PI_Phase_CD3 select
#if(_LVDS_PI_PHASE_CD3_SEL <= _LVDS_PHASE16)
    ucLvdsPhaseH = (ucLvdsPhaseSeedH << (_LVDS_PI_PHASE_CD3_SEL >> 2));
    ucLvdsPhaseL = (ucLvdsPhaseSeedL << (_LVDS_PI_PHASE_CD3_SEL % 8)) & 0xF0;

    ScalerSetBit(P55_0A_LVDS_COMMON_AB_CTRL10, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ucLvdsPhaseH >> 4) & 0x0F));
    ScalerSetByte(P55_0B_LVDS_COMMON_AB_CTRL11, (((ucLvdsPhaseH << 4) & 0xF0) | ((ucLvdsPhaseL >> 4) & 0x0F)));
#else
    ScalerSetBit(P55_0A_LVDS_COMMON_AB_CTRL10, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P55_0B_LVDS_COMMON_AB_CTRL11, 0x30);
#endif

    // Set Port C Phase selection (Analog Port A)
    ScalerSetBit(P55_24_LVDS_PORTA_CTRL4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((_LVDS_C0_PHASE << 2) | (_LVDS_C1_PHASE << 0)));
    ScalerSetByte(P55_25_LVDS_PORTA_CTRL5, ((_LVDS_C2_PHASE << 6) | (_LVDS_CC_PHASE << 4) | (_LVDS_C3_PHASE << 2) | (_LVDS_C4_PHASE << 0)));

    // Set Port D Phase selection (Analog Port B)
    ScalerSetBit(P55_34_LVDS_PORTB_CTRL4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((_LVDS_D0_PHASE << 2) | (_LVDS_D1_PHASE << 0)));
    ScalerSetByte(P55_35_LVDS_PORTB_CTRL5, ((_LVDS_D2_PHASE << 6) | (_LVDS_DC_PHASE << 4) | (_LVDS_D3_PHASE << 2) | (_LVDS_D4_PHASE << 0)));

    // Set LVDS PI Control Enable
    ScalerSetBit(P55_03_LVDS_COMMON_AB_CTRL3, ~(_BIT1 | _BIT0), _BIT0);
}

//--------------------------------------------------
// Description  : LVDS Slew rate Contorl
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsSlewRateConrol(void)
{
    ScalerSetBit(P55_22_LVDS_PORTA_CTRL2, ~(_BIT7 | _BIT6), (_LVDS_SR_CONTROL << 6));
    ScalerSetBit(P55_32_LVDS_PORTB_CTRL2, ~(_BIT7 | _BIT6), (_LVDS_SR_CONTROL << 6));
}

//--------------------------------------------------
// Description  : Set LVDS PI Operation band
// Input Value  : ucPhaseBand
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsSetPhaseBand(BYTE ucPhaseBand)
{
    ScalerSetBit(P55_03_LVDS_COMMON_AB_CTRL3, ~(_BIT6 | _BIT5), ucPhaseBand);
    ScalerSetBit(P55_04_LVDS_COMMON_AB_CTRL4, ~(_BIT6 | _BIT5), ucPhaseBand);
    ScalerSetBit(P55_06_LVDS_COMMON_AB_CTRL6, ~(_BIT6 | _BIT5), ucPhaseBand);
    ScalerSetBit(P55_08_LVDS_COMMON_AB_CTRL8, ~(_BIT6 | _BIT5), ucPhaseBand);
    ScalerSetBit(P55_0A_LVDS_COMMON_AB_CTRL10, ~(_BIT6 | _BIT5), ucPhaseBand);
}

//--------------------------------------------------
// Description  : Get LVDS Power Status
// Input Value  : None
// Output Value : _TRUE: Power On   _FALSE: Power Down
//--------------------------------------------------
bit ScalerDisplayGetLvdsPowerStatus(void)
{
    return (bit)(ScalerGetBit(P55_00_LVDS_COMMON_AB_CTRL0, _BIT3));
}

//--------------------------------------------------
// Description  : LVDS PLL(Data) Power Control
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPLL(bit bOn)
{
    if(bOn == _ON)
    {
        // Power Up LVDS Port CD PLL
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~_BIT3, _BIT3);

        // Wait for LVDS PLL stable
        ScalerTimerDelayXms(2);

        // Set LVDS CLK Signal
        ScalerSetByte(P39_1D_LVDS_CLK_CTRL, 0xE3);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
        // Set DISP mode is LVDS
        ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        // Set LVDS Pinshare is LVDS
        ScalerDisplayLvdsPinshareSetting(_LVDS_TYPE);

        // Disable Weakly Pull Down
        ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~_BIT7, 0x00);
        ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~_BIT7, 0x00);
#endif
    }
    else
    {
        // Power Down LVDS Port CD PLL
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~_BIT3, 0x00);

        // Disable LVDS CLK Signal, and Set To DC Level
        ScalerSetByte(P39_1D_LVDS_CLK_CTRL, 0x00);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
        // Set DISP mode is Hiz
        ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        // Set LVDS Pinshare is Hiz
        ScalerDisplayLvdsPinshareSetting(_HIZ_TYPE);

        // Enable Weakly Pull Down
        ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~_BIT7, _BIT7);
        ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~_BIT7, _BIT7);
#endif
    }
}

//--------------------------------------------------
// Description  : LVDS Pad Power Control --> LVDS, TTL, GPIO
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPadPower(bit bOn)
{
#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
    // Weakly/Strongly Pull Down Controlled By User
    ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), ((_LVDS_PORTA_WEAK_PULL_DOWN_USER_CTRL << 7) | (_LVDS_PORTA_STRONG_PULL_DOWN_USER_CTRL << 6)));
    ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), ((_LVDS_PORTB_WEAK_PULL_DOWN_USER_CTRL << 7) | (_LVDS_PORTB_STRONG_PULL_DOWN_USER_CTRL << 6)));
#else
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_C)
    // Enable Weakly Pull Down, Disable Strongly Pull Down
    ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
#elif(_LVDS_PORT_SEL == _LVDS_1_PORT_D)
    // Enable Weakly Pull Down, Disable Strongly Pull Down
    ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), 0x00);
#else
    // Enable Weakly Pull Down, Disable Strongly Pull Down
    ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
#endif
#endif

    if(bOn == _ON)
    {
        // Set LVDS Configuration: Hiz
        ScalerDisplayLvdsPower(_OFF);

        // Power Up Port CD LVDS Block
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
    }
    else
    {
        // Power Down Port CD LVDS Block
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), 0x00);
    }
}

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
//--------------------------------------------------
// Description  : LVDS Setting Control by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsSettingControlByUser(void)
{
    // Set LVDS TXB Current 2x
    ScalerSetBit(P55_30_LVDS_PORTB_CTRL0, ~_BIT4, (_LVDS_PORTA_DATA3_DRIV_2X_USER_CTRL) << 4);
    ScalerSetBit(P55_30_LVDS_PORTB_CTRL0, ~_BIT2, (_LVDS_PORTA_DATA2_DRIV_2X_USER_CTRL) << 2);
    ScalerSetBit(P55_30_LVDS_PORTB_CTRL0, ~_BIT1, (_LVDS_PORTA_DATA1_DRIV_2X_USER_CTRL) << 1);
    ScalerSetBit(P55_30_LVDS_PORTB_CTRL0, ~_BIT0, (_LVDS_PORTA_DATA0_DRIV_2X_USER_CTRL) << 0);

    // Set LVDS TXA Current 2x
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT4, (_LVDS_PORTB_DATA3_DRIV_2X_USER_CTRL) << 4);
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT3, (_LVDS_PORTB_CLK_DRIV_2X_USER_CTRL) << 3);
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT2, (_LVDS_PORTB_DATA2_DRIV_2X_USER_CTRL) << 2);
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT1, (_LVDS_PORTB_DATA1_DRIV_2X_USER_CTRL) << 1);
    ScalerSetBit(P55_20_LVDS_PORTA_CTRL0, ~_BIT0, (_LVDS_PORTB_DATA0_DRIV_2X_USER_CTRL) << 0);

    // Set LVDS TXB Output Termination
    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT1), (_LVDS_PORTA_DATA0_TERM_USER_ADJUST & 0x10) >> 3);
    ScalerSetBit(P55_63_DPTX_Z0_TX_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_LVDS_PORTA_DATA0_TERM_USER_ADJUST & 0x0F) << 4);

    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT0), (_LVDS_PORTA_DATA1_TERM_USER_ADJUST & 0x10) >> 4);
    ScalerSetBit(P55_63_DPTX_Z0_TX_3, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_LVDS_PORTA_DATA1_TERM_USER_ADJUST & 0x0F));

    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT3), (_LVDS_PORTA_DATA2_TERM_USER_ADJUST & 0x10) >> 1);
    ScalerSetBit(P55_62_DPTX_Z0_TX_2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_LVDS_PORTA_DATA2_TERM_USER_ADJUST & 0x0F) << 4);

    ScalerSetBit(P55_61_DPTX_Z0_TX_1, ~(_BIT2), (_LVDS_PORTA_DATA3_TERM_USER_ADJUST & 0x10) >> 2);
    ScalerSetBit(P55_62_DPTX_Z0_TX_2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_LVDS_PORTA_DATA3_TERM_USER_ADJUST & 0x0F));

    // Set LVDS TXA Output Termination
    ScalerSetBit(P55_27_LVDS_PORTA_CTRL7, ~(_BIT3 | _BIT2), (_LVDS_PORTB_DATA0_TERM_USER_ADJUST & 0x03) << 2);
    ScalerSetBit(P55_27_LVDS_PORTA_CTRL7, ~(_BIT1 | _BIT0), (_LVDS_PORTB_DATA1_TERM_USER_ADJUST & 0x03) << 0);

    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT7 | _BIT6), (_LVDS_PORTB_DATA2_TERM_USER_ADJUST & 0x03) << 6);
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT5 | _BIT4), (_LVDS_PORTB_CLK_TERM_USER_ADJUST & 0x03) << 4);
    ScalerSetBit(P55_28_LVDS_PORTA_CTRL8, ~(_BIT3 | _BIT2), (_LVDS_PORTB_DATA3_TERM_USER_ADJUST & 0x03) << 2);
}
#endif
#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
//--------------------------------------------------
// Description  : LVDS PinShare Setting
// Input Value  : _LVDS_TYPE or _HIZ_TYPE
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPinshareSetting(EnumLvdsPinshareType enumLvdsPinshareType)
{
    if(enumLvdsPinshareType == _LVDS_TYPE)
    {
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
        // TXA0P TXA0N ~ TXA3P TXA3N Pinshare
        ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON3, 0x04);
        ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON3, 0x04);
        ScalerSetByte(P10_20_PIN_SHARE_CTRL20__ON3, 0x04);
        ScalerSetByte(P10_21_PIN_SHARE_CTRL21__ON3, 0x04);
        ScalerSetByte(P10_22_PIN_SHARE_CTRL22__ON3, 0x04);
        ScalerSetByte(P10_23_PIN_SHARE_CTRL23__ON3, 0x04);
        ScalerSetByte(P10_24_PIN_SHARE_CTRL24__ON3, 0x04);
        ScalerSetByte(P10_25_PIN_SHARE_CTRL25__ON3, 0x04);
        ScalerSetByte(P10_26_PIN_SHARE_CTRL26__ON3, 0x04);
        ScalerSetByte(P10_27_PIN_SHARE_CTRL27__ON3, 0x04);
#endif
    }
    else if(enumLvdsPinshareType == _HIZ_TYPE)
    {
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_C) || (_LVDS_PORT_SEL == _LVDS_2_PORT_CD))
        // TXA0P TXA0N ~ TXA3P TXA3N Pinshare
        ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON3, 0x00);
        ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON3, 0x00);
        ScalerSetByte(P10_20_PIN_SHARE_CTRL20__ON3, 0x00);
        ScalerSetByte(P10_21_PIN_SHARE_CTRL21__ON3, 0x00);
        ScalerSetByte(P10_22_PIN_SHARE_CTRL22__ON3, 0x00);
        ScalerSetByte(P10_23_PIN_SHARE_CTRL23__ON3, 0x00);
        ScalerSetByte(P10_24_PIN_SHARE_CTRL24__ON3, 0x00);
        ScalerSetByte(P10_25_PIN_SHARE_CTRL25__ON3, 0x00);
        ScalerSetByte(P10_26_PIN_SHARE_CTRL26__ON3, 0x00);
        ScalerSetByte(P10_27_PIN_SHARE_CTRL27__ON3, 0x00);
#endif
    }
}
#endif
#endif // End of #if(_PANEL_STYLE == _PANEL_LVDS)

#if(_PANEL_STYLE == _PANEL_DPTX)
//--------------------------------------------------
// Description  : LVDS Pad Power Control --> eDP Panel
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayUseLvdsPadPower(bit bOn)
{
    // Disable Weakly / Strongly Pull Down
    ScalerSetBit(P55_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(P55_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), 0x00);

    if(bOn == _ON)
    {
        // Power Up Port CD LVDS Block
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
    }
    else
    {
        // Power Down Port CD LVDS Block
        ScalerSetBit(P55_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), 0x00);
    }
}
#endif

//--------------------------------------------------
// Description  : Set Display Conversion Line Length
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplaySetDspcLineLength(WORD usData)
{
    ScalerSetByte(P39_1B_DSPC_LINE_LENGTH_H, (HIBYTE(usData) & 0x3F));
    ScalerSetByte(P39_1C_BACK_DSPC_LINE_LENGTH_L, LOBYTE(usData));
}
