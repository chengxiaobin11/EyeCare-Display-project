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
// ID Code      : RL6463_Series_Efuse.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _EFUSE_INITIAL_ADDRESS                 (0xA6)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerEfuseGetData(EnumEfuseDataState enumEfuseDataState, BYTE ucEfuseLength, BYTE *pucEfuseData);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : M2PLL Power COntrol.
// Input Value  : enumEfuseDataState, pucEfuseData
// Output Value : None
//--------------------------------------------------
void ScalerEfuseGetData(EnumEfuseDataState enumEfuseDataState, BYTE ucEfuseLength, BYTE *pucEfuseData)
{
    BYTE ucEfuseAddress = 0;

    switch(enumEfuseDataState)
    {
        case _EFUSE_LC_TANK_CURRENT:
            ucEfuseAddress = 0xA6;
            break;

        case _EFUSE_M2PLL_N_F_CODE:
            ucEfuseAddress = 0xA7;
            break;

        case _EFUSE_THERMAL_SENSOR:
            ucEfuseAddress = 0xAB;
            break;

        case _EFUSE_LVDS_DRIV:
            ucEfuseAddress = 0xAF;
            break;

        case _EFUSE_LC_TANK_FREQ_FOR_APLL:
            ucEfuseAddress = 0xB0;
            break;

        case _EFUSE_CP_WAFER_INFO:
            ucEfuseAddress = 0xB3;
            break;

        default:
            return;
    }

    // Enable eFuse Module Clk
    ScalerSetBit(P24_A3_EFUSE_CTRL_0, ~_BIT0, 0x00);

    // Set eFuse Read Start Address
    ScalerSetByte(P24_A1_EFUSE_BURN_IN_1, (ucEfuseAddress - _EFUSE_INITIAL_ADDRESS));

    // Enable Read eFuse
    ScalerSetBit(P24_A3_EFUSE_CTRL_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

    // Delay Time us [10,x] for eFuse ready
    DELAY_10US();

    // Load eFuse data
    memcpy(pucEfuseData, (volatile BYTE xdata *)P24_A6_EFUSE_DATA0, ucEfuseLength);

    // Disable eFuse Module Clk
    ScalerSetBit(P24_A3_EFUSE_CTRL_0, ~_BIT0, _BIT0);
}

