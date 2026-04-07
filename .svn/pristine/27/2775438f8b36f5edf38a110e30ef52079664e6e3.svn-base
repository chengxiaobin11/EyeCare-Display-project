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
// ID Code      : RL6851_Series_OsdWindowColorOffset.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_OSDLibInternalInclude.h"

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
void ScalerOsdWinodwColorOffset(EnumOsdWinColorOffsetType enumOffset);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Window Color Index offset
// Input Value  : enumOffset -> _OSD_WIN_COLOR_PALETTE_0_15 or _OSD_WIN_COLOR_PALETTE_16_31 ro _OSD_WIN_COLOR_PALETTE_32_41 or _OSD_WIN_COLOR_PALETTE_42_63
// Output Value :
//--------------------------------------------------
void ScalerOsdWinodwColorOffset(EnumOsdWinColorOffsetType enumOffset)
{
    ScalerSetBit(P3A_8F_FRAME_CTRL_8F_DUMMY, ~(_BIT1 | _BIT0), enumOffset);
}

