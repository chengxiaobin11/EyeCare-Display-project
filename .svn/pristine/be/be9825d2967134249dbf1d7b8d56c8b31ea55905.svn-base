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
// ID Code      : RL6851_Series_ScalerColorColorSampling.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

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
void ScalerColor422To444(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 420To422 parameter setting for D1 source
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColor422To444(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420))
    {
        // Enable YUV 422 to 444 function
        ScalerSetBit(P31_40_YUV422_TO_444_PATH0, ~(_BIT3 | _BIT2 | _BIT1), _BIT3);
    }
    else
    {
        // Disable YUV 422 to 444 function
        ScalerSetBit(P31_40_YUV422_TO_444_PATH0, ~_BIT3, 0x00);
    }
}
