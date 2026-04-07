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
// ID Code      : ScalerColorIDitherEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorIDitherEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Idither function
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P0_1F_M1_ICLK_GATED_CTRL1, ~_BIT5, _BIT5);
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~_BIT5, _BIT5);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~_BIT5, 0x00);
    }
    else // GATED
    {
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~_BIT5, 0x00);
        ScalerTimerDelayXms(2);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerSetBit(P0_1F_M1_ICLK_GATED_CTRL1, ~_BIT5, 0x00);
    }
}
