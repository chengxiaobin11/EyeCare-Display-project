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
// ID Code      : RL6463_Series_Display.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_PANEL_STYLE == _PANEL_LVDS)
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_A) && (_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON))
#warning "NOTE: If LVDS Port Select _LVDS_1_PORT_A, LVDS No Vcm Level Before Data Cannot Support"
#endif
#endif

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
void ScalerDisplayLvdsPadPower(bit bOn);
void ScalerDisplayLvdsPower(bit bOn);
void ScalerDisplayLvdsClkInfoSelect(void);
void ScalerDisplayLvdsDrivingControl(BYTE ucDriv);
void ScalerDisplayLvdsPhaseConrol(void);
void ScalerDisplayLvdsSlewRateConrol(void);

bit ScalerDisplayGetLvdsPowerStatus(void);
void ScalerDisplayCtsFifoRstByTcon(bit bEnable);
void ScalerDisplayLvdsPLL(bit bOn);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
void ScalerDisplayLvdsPinshareSetting(EnumLvdsPinshareType enumLvdsPinshareType);
#endif
#endif // #if(_PANEL_STYLE == _PANEL_LVDS)

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
    ScalerSetBit(P39_06_LVDS_DISPLAY_CONV_CTRL5, ~0xFF, ((_LVDS_RB_SWAP << 7) | (_LVDS_ML_SWAP << 6) | (_LVDS_PN_SWAP << 4) | (_BIT3) | (_LVDS_PAIR_MIRROR << 0)));

    // Set LVDS Display Content
    ScalerSetBit(P39_07_LVDS_DISPLAY_CONV_CTRL6, ~(_BIT3 | _BIT2 | _BIT1), ((_LVDS_DVS_INVERT << 3) | (_LVDS_DHS_INVERT << 2) | (_LVDS_DEN_INVERT << 1)));

    // Set LVDS Rclk_inv: Enable
    ScalerSetBit(P15_12_LVDS_COMMON_AB_CTRL18, ~_BIT1, _BIT1);

    // Set OCLK: Non-inverted
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_20_DISPLAY_CLOCK_FINE_TUNE, ~_BIT0, 0x00);

    // Set LVDS common mode Voltage
    ScalerDisplayVcmControl(_LVDS_VCM_CONTROL);

    // Set LVDS Driving Double Current Disable
    ScalerSetBit(P15_20_LVDS_PORTA_CTRL0, ~(_BIT4 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

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

    // Set LVDS Shape-adjustment
    ScalerSetBit(P15_23_LVDS_PORTA_CTRL3, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
    ScalerSetBit(P15_33_LVDS_PORTB_CTRL3, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));

    // Set LVDS Pre-emphasis On
    ScalerSetBit(P15_23_LVDS_PORTA_CTRL3, ~(_BIT5 | _BIT2), (_BIT5 | _BIT2));
    ScalerSetBit(P15_33_LVDS_PORTB_CTRL3, ~(_BIT5 | _BIT2), (_BIT5 | _BIT2));
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

            ScalerSetBit(P15_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5));

            break;

        case _LVDS_VCM_NORMAL:

            ScalerSetBit(P15_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT0));

            break;

        case _LVDS_VCM_HIGH:

            ScalerSetBit(P15_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

            break;

        case _LVDS_VCM_USER:

            ScalerSetBit(P15_01_LVDS_COMMON_AB_CTRL1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT5 | (_LVDS_VCM_USER_LEVEL & 0x1F)));

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : LVDS Pad Power Control --> LVDS, TTL, GPIO
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPadPower(bit bOn)
{
    BYTE ucLvdsRstCount = 0;

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
    // Weakly/Strongly Pull Down Controlled By User
    ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), ((_LVDS_PORTA_WEAK_PULL_DOWN_USER_CTRL << 7) | (_LVDS_PORTA_STRONG_PULL_DOWN_USER_CTRL << 6)));
    ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), ((_LVDS_PORTB_WEAK_PULL_DOWN_USER_CTRL << 7) | (_LVDS_PORTB_STRONG_PULL_DOWN_USER_CTRL << 6)));
#else
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_A)
    // Enable Weakly Pull Down, Disable Strong Pull Down
    ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
#elif(_LVDS_PORT_SEL == _LVDS_1_PORT_B)
    // Enable Weakly Pull Down, Disable Strong Pull Down
    ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), 0x00);
#else
    // Enable Weakly Pull Down, Disable Strong Pull Down
    ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
#endif
#endif

    if(bOn == _ON)
    {
#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _OFF)
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_B) || (_LVDS_PORT_SEL == _LVDS_2_PORT_AB))
        // Set LVDS Port B Configuration: LVDS
        ScalerSetBit(P10_1D_PIN_SHARE_CTRL55___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_1E_PIN_SHARE_CTRL56___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_1F_PIN_SHARE_CTRL57___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_20_PIN_SHARE_CTRL60___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_21_PIN_SHARE_CTRL61___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_22_PIN_SHARE_CTRL62___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_23_PIN_SHARE_CTRL63___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P10_24_PIN_SHARE_CTRL64___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
#endif
#endif

        if(ScalerGlobalGetIDCode() == _RL6463_VER_A_ID_CODE)
        {
            // Set DPLL CMU Power Down
            ScalerPLLSetDPLLReset();
            ScalerTimerDelayXms(2);

            // Toggle LVDS Port Power To Sync Each LVDS Data Lane
            for(ucLvdsRstCount = 0; ucLvdsRstCount < 4; ucLvdsRstCount++)
            {
                // Power Up Port AB LVDS Block
                ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
                ScalerTimerDelayXms(2);

                // Power Down Port AB LVDS Block
                ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), 0x00);
                ScalerTimerDelayXms(2);
            }

            // Power Up Port AB LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
        }
        else
        {
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_A)
            // Power Up Port B (Odd port) LVDS Block for GPIO
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT6, _BIT6);
#endif
        }
    }
    else
    {
        // Power Down Port AB LVDS Block
        ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), 0x00);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _OFF)
#if((_LVDS_PORT_SEL == _LVDS_1_PORT_B) || (_LVDS_PORT_SEL == _LVDS_2_PORT_AB))
        // Set LVDS Port B Configuration: Hiz
        ScalerSetBit(P10_1D_PIN_SHARE_CTRL55___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_1E_PIN_SHARE_CTRL56___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_1F_PIN_SHARE_CTRL57___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_20_PIN_SHARE_CTRL60___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_21_PIN_SHARE_CTRL61___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_22_PIN_SHARE_CTRL62___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_23_PIN_SHARE_CTRL63___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P10_24_PIN_SHARE_CTRL64___LVDS, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif
#endif
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
        // Enable LVDS Port AB IBGEN Power
        ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT7, _BIT7);
    }
    else
    {
        // Disable LVDS Port AB IBGEN Power
        ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Dual Port LVDS Clk Infomation: CLK set 80ohm as Termination On / CLK set current 2x as Termination Off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsClkInfoSelect(void)
{
    // Set LVDS Output Termination 50ohm Initially
    ScalerSetByte(P15_27_LVDS_PORTA_CTRL7, 0xFF);
    ScalerSetByte(P15_28_LVDS_PORTA_CTRL8, 0xFF);
    ScalerSetByte(P15_37_LVDS_PORTB_CTRL7, 0xFF);
    ScalerSetByte(P15_38_LVDS_PORTB_CTRL8, 0xFF);

    // Dual Port LVDS: CLK set 80ohm as Termination on, CLK set current 2x as Termination Off
#if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)
#if(_LVDS_PAIR_MIRROR == _DISABLE)

    // Set LVDS TXBC Output Termination 80ohm
    ScalerSetBit(P15_38_LVDS_PORTB_CTRL8, ~(_BIT5 | _BIT4), 0x00);

    // Set LVDS TXBC Current 2x
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT3, _BIT3);

#else // Else of #if(_LVDS_PAIR_MIRROR == _DISABLE)

    // Set LVDS TXB1 Output Termination 80ohm
    ScalerSetBit(P15_37_LVDS_PORTB_CTRL7, ~(_BIT1 | _BIT0), 0x00);

    // Set LVDS TXB1 Current 2x
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT1, _BIT1);

#endif // End of #if(_LVDS_PAIR_MIRROR == _DISABLE)

#if(_LVDS_TERMINATION_CONTROL == _ENABLE)

    // Disable LVDS TXB Current 2x
    ScalerSetByte(P15_30_LVDS_PORTB_CTRL0, 0x00);

#endif // End of #if(_LVDS_TERMINATION_CONTROL == _DISABLE)
#endif // End of #if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)

    // Set LVDS TXA Current 2x
    ScalerSetBit(P15_20_LVDS_PORTA_CTRL0, ~_BIT4, (_LVDS_PORTA_DATA3_DRIV_2X_USER_CTRL) << 4);
    ScalerSetBit(P15_20_LVDS_PORTA_CTRL0, ~_BIT2, (_LVDS_PORTA_DATA2_DRIV_2X_USER_CTRL) << 2);
    ScalerSetBit(P15_20_LVDS_PORTA_CTRL0, ~_BIT1, (_LVDS_PORTA_DATA1_DRIV_2X_USER_CTRL) << 1);
    ScalerSetBit(P15_20_LVDS_PORTA_CTRL0, ~_BIT0, (_LVDS_PORTA_DATA0_DRIV_2X_USER_CTRL) << 0);

    // Set LVDS TXB Current 2x
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT4, (_LVDS_PORTB_DATA3_DRIV_2X_USER_CTRL) << 4);
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT3, (_LVDS_PORTB_CLK_DRIV_2X_USER_CTRL) << 3);
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT2, (_LVDS_PORTB_DATA2_DRIV_2X_USER_CTRL) << 2);
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT1, (_LVDS_PORTB_DATA1_DRIV_2X_USER_CTRL) << 1);
    ScalerSetBit(P15_30_LVDS_PORTB_CTRL0, ~_BIT0, (_LVDS_PORTB_DATA0_DRIV_2X_USER_CTRL) << 0);

    // Set LVDS TXA Output Termination
    ScalerSetBit(P15_27_LVDS_PORTA_CTRL7, ~(_BIT3 | _BIT2), (_LVDS_PORTA_DATA0_TERM_USER_ADJUST & 0x03) << 2);
    ScalerSetBit(P15_27_LVDS_PORTA_CTRL7, ~(_BIT1 | _BIT0), (_LVDS_PORTA_DATA1_TERM_USER_ADJUST & 0x03) << 0);

    ScalerSetBit(P15_28_LVDS_PORTA_CTRL8, ~(_BIT7 | _BIT6), (_LVDS_PORTA_DATA2_TERM_USER_ADJUST & 0x03) << 6);
    ScalerSetBit(P15_28_LVDS_PORTA_CTRL8, ~(_BIT3 | _BIT2), (_LVDS_PORTA_DATA3_TERM_USER_ADJUST & 0x03) << 2);

    // Set LVDS TXB Output Termination
    ScalerSetBit(P15_37_LVDS_PORTB_CTRL7, ~(_BIT3 | _BIT2), (_LVDS_PORTB_DATA0_TERM_USER_ADJUST & 0x03) << 2);
    ScalerSetBit(P15_37_LVDS_PORTB_CTRL7, ~(_BIT1 | _BIT0), (_LVDS_PORTB_DATA1_TERM_USER_ADJUST & 0x03) << 0);

    ScalerSetBit(P15_38_LVDS_PORTB_CTRL8, ~(_BIT7 | _BIT6), (_LVDS_PORTB_DATA2_TERM_USER_ADJUST & 0x03) << 6);
    ScalerSetBit(P15_38_LVDS_PORTB_CTRL8, ~(_BIT5 | _BIT4), (_LVDS_PORTB_CLK_TERM_USER_ADJUST & 0x03) << 4);
    ScalerSetBit(P15_38_LVDS_PORTB_CTRL8, ~(_BIT3 | _BIT2), (_LVDS_PORTB_DATA3_TERM_USER_ADJUST & 0x03) << 2);

#endif
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
    ScalerEfuseGetData(_EFUSE_LVDS_DRIV, 1, &ucEfuseDriv);

#if(_LVDS_TERMINATION_CONTROL == _ENABLE)
#if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-Emphasis0
    ScalerSetByte(P15_29_LVDS_PORTA_CTRL9, 0x00);
    ScalerSetByte(P15_2A_LVDS_PORTA_CTRL10, 0x00);
    ScalerSetByte(P15_39_LVDS_PORTB_CTRL9, 0x00);
    ScalerSetByte(P15_3A_LVDS_PORTB_CTRL10, 0x00);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 473 / 350) : 0x98;
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 563 / 350) : 0xB5;
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 630 / 350) : 0xCA;
            break;

        case _LVDS_DRIV_CONTROL_3_5:
        case _LVDS_DRIV_CONTROL_4_0:
        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 698 / 350) : 0xE0;
            break;

        default:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 338 / 350) : 0x6D;
            break;
    }

#else // Else of #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-Emphasis1
    ScalerSetByte(P15_29_LVDS_PORTA_CTRL9, 0x01);
    ScalerSetByte(P15_2A_LVDS_PORTA_CTRL10, 0x15);
    ScalerSetByte(P15_39_LVDS_PORTB_CTRL9, 0x01);
    ScalerSetByte(P15_3A_LVDS_PORTB_CTRL10, 0x55);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 536 / 350) : 0xAC;
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 589 / 350) : 0xBD;
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 643 / 350) : 0xCE;
            break;

        case _LVDS_DRIV_CONTROL_3_5:
        case _LVDS_DRIV_CONTROL_4_0:
        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 696 / 350) : 0xDF;
            break;

        default:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 402 / 350) : 0x81;
            break;
    }

#endif // End of #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

#else // Else of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)
#if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)

    // Set LVDS Pre-Emphasis0
    ScalerSetByte(P15_29_LVDS_PORTA_CTRL9, 0x00);
    ScalerSetByte(P15_2A_LVDS_PORTA_CTRL10, 0x00);
    ScalerSetByte(P15_39_LVDS_PORTB_CTRL9, 0x00);
    ScalerSetByte(P15_3A_LVDS_PORTB_CTRL10, 0x00);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 20 / 35) : 0x40;
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 25 / 35) : 0x50;
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 30 / 35) : 0x60;
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            usTempDriv = (ucEfuseDriv != 0) ? (ucEfuseDriv) : 0x70;
            break;

        case _LVDS_DRIV_CONTROL_4_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 39 / 35) : 0x60;
            break;

        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 43 / 35) : 0x60;
            break;

        default:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 15 / 35) : 0x30;
            break;
    }

#elif(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_1)

    // Set LVDS Pre-Emphasis1
    ScalerSetByte(P15_29_LVDS_PORTA_CTRL9, 0x01);
    ScalerSetByte(P15_2A_LVDS_PORTA_CTRL10, 0x15);
    ScalerSetByte(P15_39_LVDS_PORTB_CTRL9, 0x01);
    ScalerSetByte(P15_3A_LVDS_PORTB_CTRL10, 0x55);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 262 / 350) : 0x54;
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 298 / 350) : 0x60;
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 321 / 350) : 0x67;
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 345 / 350) : 0x6F;
            break;

        case _LVDS_DRIV_CONTROL_4_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 390 / 350) : 0x6F;
            break;

        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 430 / 350) : 0x6F;
            break;

        default:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 179 / 350) : 0x3A;
            break;
    }

#else

    // Set LVDS Pre-Emphasis2
    ScalerSetByte(P15_29_LVDS_PORTA_CTRL9, 0x02);
    ScalerSetByte(P15_2A_LVDS_PORTA_CTRL10, 0x2A);
    ScalerSetByte(P15_39_LVDS_PORTB_CTRL9, 0x02);
    ScalerSetByte(P15_3A_LVDS_PORTB_CTRL10, 0xAA);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 278 / 350) : 0x59;
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 292 / 350) : 0x5E;
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 319 / 350) : 0x67;
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 347 / 350) : 0x70;
            break;

        case _LVDS_DRIV_CONTROL_4_0:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 390 / 350) : 0x6F;
            break;

        case _LVDS_DRIV_CONTROL_4_5:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 430 / 350) : 0x6F;
            break;

        default:
            usTempDriv = (ucEfuseDriv != 0) ? ((DWORD)ucEfuseDriv * 208 / 350) : 0x43;
            break;
    }

#endif // End of #if(_LVDS_PRE_EMPHASIS_CONTROL == _LVDS_PRE_EMPHASIS_0)
#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

    // Set LVDS Driving Current Control
    ScalerSetByte(P15_02_LVDS_COMMON_AB_CTRL2, ((usTempDriv < 0xFF) ? usTempDriv : 0xFF));

#if(_LVDS_SETTING_CONTROL_BY_USER == _ENABLE)
    ScalerSetByte(P15_02_LVDS_COMMON_AB_CTRL2, (_LVDS_DRIV_CURRENT_USER_ADUST & 0xFF));
#endif
}

//--------------------------------------------------
// Description  : LVDS Phase Selection Contorl
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPhaseConrol(void)
{
    BYTE ucTxPhase = 0x00;

    // TXA0 Phase Select (Analog Port B)
    ucTxPhase = (_LVDS_A0_PHASE <= _LVDS_PHASE7) ? _LVDS_A0_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_07_LVDS_COMMON_AB_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));

    // TXA1 Phase Select (Analog Port B)
    ucTxPhase = (_LVDS_A1_PHASE <= _LVDS_PHASE7) ? _LVDS_A1_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_07_LVDS_COMMON_AB_CTRL7, ~(_BIT2 | _BIT1 | _BIT0), (ucTxPhase & 0x07));

    // TXA2 Phase Select (Analog Port B)
    ucTxPhase = (_LVDS_A2_PHASE <= _LVDS_PHASE7) ? _LVDS_A2_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_08_LVDS_COMMON_AB_CTRL8, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));

    // TXAC Phase Select (Analog Port B)
    ucTxPhase = (_LVDS_AC_PHASE <= _LVDS_PHASE7) ? _LVDS_AC_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_08_LVDS_COMMON_AB_CTRL8, ~(_BIT2 | _BIT1 | _BIT0), (ucTxPhase & 0x07));

    // TXA3 Phase Select (Analog Port B)
    ucTxPhase = (_LVDS_A3_PHASE <= _LVDS_PHASE7) ? _LVDS_A3_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_09_LVDS_COMMON_AB_CTRL9, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));

    // TXB0 Phase Select (Analog Port A)
    ucTxPhase = (_LVDS_B0_PHASE <= _LVDS_PHASE7) ? _LVDS_B0_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_04_LVDS_COMMON_AB_CTRL4, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));

    // TXB1 Phase Select (Analog Port A)
    ucTxPhase = (_LVDS_B1_PHASE <= _LVDS_PHASE7) ? _LVDS_B1_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_04_LVDS_COMMON_AB_CTRL4, ~(_BIT2 | _BIT1 | _BIT0), (ucTxPhase & 0x07));

    // TXB2 Phase Select (Analog Port A)
    ucTxPhase = (_LVDS_B2_PHASE <= _LVDS_PHASE7) ? _LVDS_B2_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_05_LVDS_COMMON_AB_CTRL5, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));

    // TXB3 Phase Select (Analog Port A)
    ucTxPhase = (_LVDS_B3_PHASE <= _LVDS_PHASE7) ? _LVDS_B3_PHASE : _LVDS_PHASE7;
    ScalerSetBit(P15_06_LVDS_COMMON_AB_CTRL6, ~(_BIT5 | _BIT4 | _BIT3), ((ucTxPhase & 0x07) << 3));
}

//--------------------------------------------------
// Description  : LVDS Slew rate Contorl
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsSlewRateConrol(void)
{
#if(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_0)

    ScalerSetBit(P15_22_LVDS_PORTA_CTRL2, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(P15_32_LVDS_PORTB_CTRL2, ~(_BIT7 | _BIT6), 0x00);

#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_1)

    ScalerSetBit(P15_22_LVDS_PORTA_CTRL2, ~(_BIT7 | _BIT6), _BIT6);
    ScalerSetBit(P15_32_LVDS_PORTB_CTRL2, ~(_BIT7 | _BIT6), _BIT6);

#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_2)

    ScalerSetBit(P15_22_LVDS_PORTA_CTRL2, ~(_BIT7 | _BIT6), _BIT7);
    ScalerSetBit(P15_32_LVDS_PORTB_CTRL2, ~(_BIT7 | _BIT6), _BIT7);

#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_3)

    ScalerSetBit(P15_22_LVDS_PORTA_CTRL2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerSetBit(P15_32_LVDS_PORTB_CTRL2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

#endif // #if(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_0)
}

//--------------------------------------------------
// Description  : Get LVDS Power Status
// Input Value  : None
// Output Value : _TRUE: Power On   _FALSE: Power Down
//--------------------------------------------------
bit ScalerDisplayGetLvdsPowerStatus(void)
{
    return (bit)(ScalerGetBit(P15_00_LVDS_COMMON_AB_CTRL0, _BIT4));
}

//--------------------------------------------------
// Description  : LVDS Cts Fifo Reset by Tcon
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDisplayCtsFifoRstByTcon(bit bEnable)
{
    WORD usTconDVStart = 0;
    WORD usTconDHStart = 0;

    if(bEnable == _ON)
    {
        // Disable TCON8
        ScalerTcon8Enable(_OFF);

        // Disable All TCON
        // ScalerTconGlobalEnable(_OFF);

        // Get DHTotal (12-bit)
        ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H, 2, pData, _AUTOINC);

        // Get DV_ACT_End (12-bit)
        ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_12_DISPLAY_VER_ACT_END_H, 2, &pData[2], _AUTOINC);

        // Get DV_BK_End (12-bit)
        ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_14_DISPLAY_VER_BG_END_H, 2, &pData[4], _AUTOINC);

        // Calculate the Tcon8_DVStart and Tcon8_DHStart
        usTconDVStart = MAXOF(PDATA_WORD(1), PDATA_WORD(2)) + 1;
        usTconDHStart = (PDATA_WORD(0) >> 1) + 2;

        // Set TCON8 V start & end to [max_DV + 1: max_DV + 2]
        // Set TCON8 H start & end to [DH_total/2 + 2:DH_total/2 + 12]
        ScalerTcon8Adjust(usTconDHStart, (usTconDHStart + 10), usTconDVStart, (usTconDVStart + 1));

        // Enable All TCON
        ScalerTconGlobalEnable(_ON);

        // Enable TCON8
        ScalerTcon8Enable(_ON);

        // ctsFIFO reset by TCON8
        ScalerSetBit(P15_14_LVDS_COMMON_AB_CTRL20, ~_BIT0, _BIT0);
    }
    else
    {
        // ctsFIFO reset by force_cts_fifo_rstn
        ScalerSetBit(P15_14_LVDS_COMMON_AB_CTRL20, ~_BIT0, 0x00);
    }
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
        if(ScalerGlobalGetIDCode() >= _RL6463_VER_B_ID_CODE)
        {
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_A)
            // Power Up Port A LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT5, _BIT5);
#elif(_LVDS_PORT_SEL == _LVDS_1_PORT_B)
            // Power Up Port B LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT6, _BIT6);
#elif(_LVDS_PORT_SEL == _LVDS_2_PORT_AB)
            // Power Up Port AB LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
#endif
        }

        // Enable LVDS Cts Fifo Reset by Tcon8
        ScalerDisplayCtsFifoRstByTcon(_ENABLE);

        // Power Up LVDS Port AB CK_LVDS Clk
        ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT4, _BIT4);

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
        // Set DISP mode is LVDS
        ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        // Set LVDS Pinshare is LVDS
        ScalerDisplayLvdsPinshareSetting(_LVDS_TYPE);

        // Disable Weakly Pull Down
        ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~_BIT7, 0x00);
        ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~_BIT7, 0x00);
#endif
    }
    else
    {
        // Power Down LVDS Port AB CK_LVDS Clk
        ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT4, 0x00);

        // Disable LVDS Cts Fifo Reset by Tcon8
        ScalerDisplayCtsFifoRstByTcon(_DISABLE);

        if(ScalerGlobalGetIDCode() >= _RL6463_VER_B_ID_CODE)
        {
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_A)
            // Power down Port A LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT5, 0x00);
#elif(_LVDS_PORT_SEL == _LVDS_1_PORT_B)
            // Power down Port B LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~_BIT6, 0x00);
#elif(_LVDS_PORT_SEL == _LVDS_2_PORT_AB)
            // Power down Port AB LVDS Block
            ScalerSetBit(P15_00_LVDS_COMMON_AB_CTRL0, ~(_BIT6 | _BIT5), 0x00);
#endif
        }
#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
        // Set DISP mode is Hiz
        ScalerSetBit(P39_00_LVDS_DISP_TYPE, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        // Set LVDS Pinshare is Hiz
        ScalerDisplayLvdsPinshareSetting(_HIZ_TYPE);

        // Enable Weakly Pull Down
        ScalerSetBit(P15_36_LVDS_PORTB_CTRL6, ~_BIT7, _BIT7);
        ScalerSetBit(P15_26_LVDS_PORTA_CTRL6, ~_BIT7, _BIT7);
#endif
    }
}

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
#if(_LVDS_PORT_SEL == _LVDS_2_PORT_AB)
        // TXAP TXA0N ~ TXA3P TXA3N and TXB0P TXB0N ~ TXB3P TXB3N Test Mode Disable
        ScalerSetDataPortByte(P0_8D_TEST_MODE_PORT_ADDR, _P0_8E_PT_00_TEST_MODE, 0x0F);
#endif

#if((_LVDS_PORT_SEL == _LVDS_1_PORT_B) || (_LVDS_PORT_SEL == _LVDS_2_PORT_AB))
        // TXB0P TXB0N ~ TXB3P TXB3N Pinshare
        ScalerSetByte(P10_1D_PIN_SHARE_CTRL55___LVDS, 0x04);
        ScalerSetByte(P10_1E_PIN_SHARE_CTRL56___LVDS, 0x04);
        ScalerSetByte(P10_1F_PIN_SHARE_CTRL57___LVDS, 0x04);
        ScalerSetByte(P10_20_PIN_SHARE_CTRL60___LVDS, 0x04);
        ScalerSetByte(P10_21_PIN_SHARE_CTRL61___LVDS, 0x04);
        ScalerSetByte(P10_22_PIN_SHARE_CTRL62___LVDS, 0x04);
        ScalerSetByte(P10_23_PIN_SHARE_CTRL63___LVDS, 0x04);
        ScalerSetByte(P10_24_PIN_SHARE_CTRL64___LVDS, 0x04);
#endif
    }
    else if(enumLvdsPinshareType == _HIZ_TYPE)
    {
#if(_LVDS_PORT_SEL == _LVDS_2_PORT_AB)
        // TXAP TXA0N ~ TXA3P TXA3N and TXB0P TXB0N ~ TXB3P TXB3N Test Mode Enable, Test Select Hiz
        ScalerSetDataPortByte(P0_8D_TEST_MODE_PORT_ADDR, _P0_8E_PT_00_TEST_MODE, 0x8F);
#endif

#if((_LVDS_PORT_SEL == _LVDS_1_PORT_B) || (_LVDS_PORT_SEL == _LVDS_2_PORT_AB))
        // TXB0P TXB0N ~ TXB3P TXB3N Pinshare
        ScalerSetByte(P10_1D_PIN_SHARE_CTRL55___LVDS, 0x00);
        ScalerSetByte(P10_1E_PIN_SHARE_CTRL56___LVDS, 0x00);
        ScalerSetByte(P10_1F_PIN_SHARE_CTRL57___LVDS, 0x00);
        ScalerSetByte(P10_20_PIN_SHARE_CTRL60___LVDS, 0x00);
        ScalerSetByte(P10_21_PIN_SHARE_CTRL61___LVDS, 0x00);
        ScalerSetByte(P10_22_PIN_SHARE_CTRL62___LVDS, 0x00);
        ScalerSetByte(P10_23_PIN_SHARE_CTRL63___LVDS, 0x00);
        ScalerSetByte(P10_24_PIN_SHARE_CTRL64___LVDS, 0x00);
#endif
    }
}
#endif
#endif // #if(_PANEL_STYLE == _PANEL_LVDS)
