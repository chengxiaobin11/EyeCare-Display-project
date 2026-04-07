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
// ID Code      : RL6432_Series_ColorRGBOutputGammaEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6432_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


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
void ScalerColorRGBOutputGammaEnable(EnumFunctionOnOFF enumOn);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Output Gamma
// Input Value  : _FUNCTION_ON / _FUNCTION_OFF
// Output Value : None
//--------------------------------------------------
void ScalerColorRGBOutputGammaEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        // Disable Clock Gated
        ScalerSetBit(P1_DC_DCLK_GATED_CTRL2, ~_BIT6, _BIT6);

        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT0, _BIT0);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT0, 0x00);
    }
    else // _FUNCTION_CLOCK_GATED
    {
        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT0, 0x00);

        // Enable Clock Gated
        ScalerSetBit(P1_DC_DCLK_GATED_CTRL2, ~_BIT6, 0x00);
    }
}

