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
// ID Code      : RL6369_Series_ColorHLWUltraVividAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6369_Series_ColorLibInternalInclude.h"

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
void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set ultravivid Highlight Window
// Input Value  : Highlight Window Active Region
//                EnumDBApply
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply)
{
    switch(enumHLWActive)
    {
        case _HLW_FULL_WINDOW:
            ScalerSetBit(P11_B9_SCALER_LSR_HLW, ~(_BIT7 | _BIT6), 0x00);
            break;

        case _HLW_INSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_LSR_HLW, ~(_BIT7 | _BIT6), _BIT7);
            break;

        case _HLW_OUTSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_LSR_HLW, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
            break;

        default:
            break;
    }

    if(GET_INTERLACED_MODE() == _TRUE)
    {
        ScalerGlobalIDomainDBApply(enumDBApply);
        ScalerGlobalDDomainDBApply(enumDBApply);
    }
    else
    {
        ScalerGlobalIDDomainDBApply(enumDBApply);
    }
}


