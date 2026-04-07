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
// ID Code      : RL6492_Series_ColorPCMInputGammaEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_ColorLibInternalInclude.h"

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
void ScalerColorPCMInputGammaEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Input gamma
// Input Value  : _FUNCTION_ON / _FUNCTION_OFF /_FUNCTION_CLOCK_GATED
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGammaEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        // Disable Clock Gated
        ScalerSetBit(P1_C7_DCLK_GATED_CTRL1, ~_BIT2, _BIT2);

        ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT6, _BIT6);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT6, 0x00);
    }
    else // _FUNCTION_CLOCK_GATED
    {
        ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT6, 0x00);

        // Enable Clock Gated
        ScalerSetBit(P1_C7_DCLK_GATED_CTRL1, ~_BIT2, 0x00);
    }
}

