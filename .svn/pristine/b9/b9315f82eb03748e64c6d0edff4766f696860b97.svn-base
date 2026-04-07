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
// ID Code      : RL6410_Series_ColorRGB3DGammaEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Table Length
//--------------------------------------------------



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
void ScalerColorRGB3DGammaEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable 3D Gamma
// Input Value  : _FUNCTION_ON / _FUNCTION_OFF/_FUNCTION_CLOCK_GATED
// Output Value : None
//--------------------------------------------------
void ScalerColorRGB3DGammaEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P1_DB_DCLK_GATED_CTRL1, ~_BIT3, _BIT3);
        ScalerSetBit(P9_B0_RGB_3D_GAMMA_CTRL, ~_BIT7, _BIT7);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P9_B0_RGB_3D_GAMMA_CTRL, ~_BIT7, 0x00);
    }
    else // _FUNCTION_CLOCK_GATED
    {
        ScalerSetBit(P9_B0_RGB_3D_GAMMA_CTRL, ~_BIT7, 0x00);
        ScalerSetBit(P1_DB_DCLK_GATED_CTRL1, ~_BIT3, 0x00);
    }
}

