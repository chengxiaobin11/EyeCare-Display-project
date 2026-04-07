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
// ID Code      : RL6410_Series_ColorHLWBRICTS.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

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
void ScalerColorHLWBRICTSAdjust(EnumBriConHLWType enumHLWActive, EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Contrast function
// Input Value  : enumHLWActive: HLW type
//                EnumDBApply
// Output Value : None
//--------------------------------------------------

void ScalerColorHLWBRICTSAdjust(EnumBriConHLWType enumHLWActive, EnumDBApply enumDBApply)
{
    if(enumHLWActive == _BRI_CON_B_ON_INSIDE_WINDOW)
    {
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT7 | _BIT6), _BIT6);
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_11_HLW_SETSEL0, ~(_BIT3 | _BIT2), _BIT3);
    }
    else if(enumHLWActive == _BRI_CON_A_ON_HLW_OUTSIDE_WINDOW)
    {
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT7 | _BIT6), _BIT7);
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_11_HLW_SETSEL0, ~(_BIT3 | _BIT2), _BIT3);
    }
    else if(enumHLWActive == _BRI_CON_B_ON_INSIDE_A_ON_HLW_OUTSIDE_WINDOW)
    {
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT7 | _BIT6), 0x00);
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_11_HLW_SETSEL0, ~(_BIT3 | _BIT2), _BIT3);
    }
    else
    {
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT7 | _BIT6), 0x00);
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_11_HLW_SETSEL0, ~(_BIT3 | _BIT2), 0x00);
    }

    ScalerGlobalDDomainDBApply(enumDBApply);
}

