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
// ID Code      : RL6449_Series_OsdSetTransparency_Timer.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_OSDLibInternalInclude.h"

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
void ScalerOsdSetTransparency_EXINT(BYTE ucTransparency);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Transparency for Timer Interrupt
// Input Value  : ucTransparency -> 0 ~ 255
// Output Value :
//--------------------------------------------------
void ScalerOsdSetTransparency_EXINT(BYTE ucTransparency)
{
    // alpha_blending_level[7:5]
    ScalerSetBit_EXINT(P0_6C_OVERLAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), ((ucTransparency & 0xE0) >> 3));

    // alpha_blending_level[4:0]
    ScalerSetBit_EXINT(P0_8F_OVERLAY_CTRL1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), ((ucTransparency & 0x1F) << 3));
}

