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
// ID Code      : RL6492_Series_ColorHLWUltraVividAdjust.c
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
            ScalerSetBit(P11_DC_I_DLTI_HLW_CTRL_M1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0D_HLW_CONTROL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
            break;

        case _HLW_INSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_LSR_HLW, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetBit(P11_DC_I_DLTI_HLW_CTRL_M1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0D_HLW_CONTROL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
            break;

        case _HLW_OUTSIDE_WINDOW:
            ScalerSetBit(P11_B9_SCALER_LSR_HLW, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);
            ScalerSetBit(P11_DC_I_DLTI_HLW_CTRL_M1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
            ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0D_HLW_CONTROL1, ~(_BIT1 | _BIT0), (enumHLWActive & 0x03));
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

