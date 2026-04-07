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
// ID Code      : RL6449_Series_ColorHLWBRICTS.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

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
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT7 | _BIT6), ((enumHLWActive & 0x03) << 6));
    ScalerGlobalDDomainDBApply(enumDBApply);
}

