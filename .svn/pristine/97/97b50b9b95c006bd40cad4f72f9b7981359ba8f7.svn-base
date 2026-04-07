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
// ID Code      : RL6463_Series_OsdSetTransparency.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6463_Series_OSDLibInternalInclude.h"

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
void ScalerOsdSetTransparency(BYTE ucTransparency);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Transparency
// Input Value  : ucTransparency[7:5] --> Blending level 0 ~ 7, ucTransparency[4:0] --> dummy
// Output Value :
//--------------------------------------------------
void ScalerOsdSetTransparency(BYTE ucTransparency)
{
    // alpha_blending_level[2:0]
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), ((ucTransparency & 0xE0) >> 3));
}

