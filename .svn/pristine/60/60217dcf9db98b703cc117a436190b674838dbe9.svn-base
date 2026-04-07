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
// ID Code      : RL6432_Series_AutoMeasureColorValue.c
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
EnumAutoResult ScalerAutoMeasureColorValue(BYTE ucColor, bit bSelectMax, BYTE *pucResult);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Measure color min/max from specific channel
// Input Value  : ucColor --> R/G/B
//                pucResult --> memory to store measure result
// Output Value : _AUTO_FAIL or _AUTO_SUCCESS
//--------------------------------------------------
EnumAutoResult ScalerAutoMeasureColorValue(BYTE ucColor, bit bSelectMax, BYTE *pucResult)
{
    // Disable 121-LPF; Set to R channel for auto-balance new mode
    ScalerSetBit(P30_CA_VGATOP_AUTO_ADJ_CTRL0, ~(_BIT5 | _BIT1 | _BIT0), _BIT1);

    // Enable image auto-balance new mode
    ScalerSetBit(P30_C6_VGATOP_RED_NOISE_MARGIN, ~_BIT0, _BIT0);

    // Start Measure
    if(ScalerAutoCompareMeasure((bSelectMax == _TRUE) ? _MEASURE_MAX : _MEASURE_RGB_MIN) == _AUTO_FAIL)
    {
        return _AUTO_FAIL;
    }

    switch(ucColor)
    {
        case _AUTO_RED_CHANNEL:
            *pucResult = ScalerGetByte(P30_D4_VGATOP_AUTO_PHASE_3);
            break;

        case _AUTO_GREEN_CHANNEL:
            *pucResult = ScalerGetByte(P30_D5_VGATOP_AUTO_PHASE_2);
            break;

        case _AUTO_BLUE_CHANNEL:
            *pucResult = ScalerGetByte(P30_D6_VGATOP_AUTO_PHASE_1);
            break;

        default:
            return _AUTO_FAIL;
    }

    return _AUTO_SUCCESS;
}

