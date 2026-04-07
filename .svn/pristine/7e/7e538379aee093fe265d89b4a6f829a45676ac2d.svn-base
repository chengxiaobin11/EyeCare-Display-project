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
// ID Code      : ScalerColorHLWDCCAdjust.c
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
void ScalerColorHLWDCCAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust DCC Highlight Window Active Region
// Input Value  : Highlight Window Actvie Region Option
//                EnumDBApply
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWDCCAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply)
{
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
    ScalerColorDCCSetMeasureRegion(enumHLWActive);
    ScalerGlobalDDomainDBApply(enumDBApply);
}
