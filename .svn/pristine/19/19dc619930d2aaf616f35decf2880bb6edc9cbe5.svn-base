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
// ID Code      : RL6449_Series_ColorSRGBGetPrecision.c
// Update Note  :
//-------------------------------------------------------------------------------------//
#include "RL6449_Series_ColorLibInternalInclude.h"

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
EnumSrgbPrecision ScalerColorSRGBGetPrecision(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Get SRGB precision
// Input Value  :
// Output Value : SRGB Precision Enum
//--------------------------------------------------
EnumSrgbPrecision ScalerColorSRGBGetPrecision(void)
{
    EnumSrgbPrecision enumPrecision = _SRGB_1_BIT_SHIFT_LEFT;
    enumPrecision = ScalerGetBit((P0_68_GAMMA_BIST_DITHER_SETA), (_BIT6 | _BIT5)) >> 5;
    return enumPrecision;
}


