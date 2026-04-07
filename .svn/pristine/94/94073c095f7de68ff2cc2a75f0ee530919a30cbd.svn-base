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

//-------------------------------------------------------------------------------------//
// ID Code      : RL6851_Series_ColorGlobalHueSatEnable.c
// Update Note  :
//-------------------------------------------------------------------------------------//
#include "RL6851_Series_ColorLibInternalInclude.h"

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
void ScalerColorSRGBEnable(EnumFunctionOnOFF enumOn);



//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable SRGB function
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//--------------------------------------------------
void ScalerColorSRGBEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P0_62_SRGB_CTRL, ~_BIT2, _BIT2);
    }
    else
    {
        ScalerSetBit(P0_62_SRGB_CTRL, ~_BIT2, 0x00);
    }
}



