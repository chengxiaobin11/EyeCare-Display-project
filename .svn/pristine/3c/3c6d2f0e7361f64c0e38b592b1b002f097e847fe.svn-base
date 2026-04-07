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
// ID Code      : RL6851_Series_ColorHLWYpeaking.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of ICM
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
void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Ypeaking HLW.
// Input Value  : Ypeaking table
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply)
{
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT1 | _BIT0), enumHLWActive);

    ScalerGlobalDDomainDBApply(enumDBApply);
}

