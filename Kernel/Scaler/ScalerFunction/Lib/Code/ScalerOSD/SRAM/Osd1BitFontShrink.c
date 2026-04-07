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
// ID Code      : Osd1BitFontShrink.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerOSDLibInternalInclude.h"

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
void ScalerOsd1BitFontShrink(EnumOsd1BitShrinkType enumOsd1BitShrinkType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : enumOsd1BitShrinkType -> _OSD_1BIT_SHRINK_BY_MIDDLE or _OSD_1BIT_SHRINK_BY_LEFT or _OSD_1BIT_SHRINK_BY_RIGHT
// Output Value :
//--------------------------------------------------
void ScalerOsd1BitFontShrink(EnumOsd1BitShrinkType enumOsd1BitShrinkType)
{
    ScalerSetBit(P3A_02_FRAME_CTRL_02, ~(_BIT2 | _BIT1), (enumOsd1BitShrinkType << 1));
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsd1BitFontShrink(_OSD_1BIT_SHRINK_BY_LEFT);
*/

