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
// ID Code      : RL6851_Series_OsdSetColorPalette.c
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
void ScalerOsdSetColorPalette(BYTE ucIndex, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Color Palette
// Input Value  : ucIndex  -> Which palette
//                ucColorR -> Palette red data   (0 ~ 255)
//                ucColorG -> Palette green data (0 ~ 255)
//                ucColorB -> Palette blue data  (0 ~ 255)
// Output Value :
//--------------------------------------------------
void ScalerOsdSetColorPalette(BYTE ucIndex, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB)
{
    ScalerSetByte(P0_6E_OVERLAY_LUT_ADDR, (_BIT7 | ucIndex));
    ScalerSetByte(P0_6F_COLOR_LUT_PORT, ucColorR);
    ScalerSetByte(P0_6F_COLOR_LUT_PORT, ucColorG);
    ScalerSetByte(P0_6F_COLOR_LUT_PORT, ucColorB);
    ScalerSetByte(P0_6E_OVERLAY_LUT_ADDR, 0x00);
}
