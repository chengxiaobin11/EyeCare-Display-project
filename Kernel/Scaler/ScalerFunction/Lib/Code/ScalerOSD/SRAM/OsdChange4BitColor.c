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
// ID Code      : OsdChange4BitColor.c
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
void ScalerOsdChange4BitColor(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucBackgroundColor, BYTE ucColorPaletteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol. ucLength. ucHeight.  -> Just that !!
//                ucBackgroundColor                  -> Color number
//                ucColorPaletteType                 -> _OSD_4BIT_PALETTE_00_01_02_03 | _OSD_4BIT_PALETTE_04_05_06_07 | _OSD_4BIT_PALETTE_08_09_10_11 | _OSD_4BIT_PALETTE_12_13_14_15
//                                                     (_OSD_4BIT_PALETTE_16_17_18_19   _OSD_4BIT_PALETTE_20_21_22_23   _OSD_4BIT_PALETTE_24_25_26_27   _OSD_4BIT_PALETTE_28_29_30_31)
//                                                     (_OSD_4BIT_PALETTE_32_33_34_35   _OSD_4BIT_PALETTE_36_37_38_39   _OSD_4BIT_PALETTE_40_41_42_43   _OSD_4BIT_PALETTE_44_45_46_47)
//                                                     (_OSD_4BIT_PALETTE_48_49_50_51   _OSD_4BIT_PALETTE_52_53_54_55   _OSD_4BIT_PALETTE_56_57_58_59   _OSD_4BIT_PALETTE_50_61_62_63)
// Output Value :
//--------------------------------------------------
void ScalerOsdChange4BitColor(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucBackgroundColor, BYTE ucColorPaletteType)
{
    BYTE ucTemp = 0;

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        ScalerOsdSramDataValue2Byte(ucRow + ucTemp, ucCol, ucLength, (0xC0 | ucBackgroundColor), ucColorPaletteType, _OSD_BYTE0_BYTE2);
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdChange4BitColor(ROW(0), COL(0), LENGTH(1), HEIGHT(1), BGCOLOR(0), (_OSD_4BIT_PALETTE_00_01_02_03 | _OSD_4BIT_PALETTE_04_05_06_07 | _OSD_4BIT_PALETTE_08_09_10_11 | _OSD_4BIT_PALETTE_12_13_14_15));
*/


