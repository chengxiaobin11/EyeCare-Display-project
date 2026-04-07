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
// ID Code      : RL6851_Series_OsdSetTransparencyType.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerOSDLibInternalInclude.h"

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
void ScalerOsdSetTransparencyType(EnumOsdTransparencyType enumOsdTransparencyType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Osd transparency type
// Input Value  : enumOsdTransparencyType -> _OSD_TRANSPARENCY_DISABLE or _OSD_TRANSPARENCY_ONLY_WINDOW                      or
//                                           _OSD_TRANSPARENCY_ALL     or _OSD_TRANSPARENCY_WINDOW_AND_CHARACTER_BACKGROUND
// Output Value :
//--------------------------------------------------
void ScalerOsdSetTransparencyType(EnumOsdTransparencyType enumOsdTransparencyType)
{
    ScalerSetBit(P3A_0A_FRAME_CTRL_0A, ~(_BIT3 | _BIT2), enumOsdTransparencyType);
}


