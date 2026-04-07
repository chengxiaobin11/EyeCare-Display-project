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
// ID Code      : OsdBlankFont.c
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
void ScalerOsdBlankFont(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucPixelLength, BYTE ucBackgroundColor, EnumOsdBlankType enumOsdBlankingType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol. ucLength. ucHeight. -> Just that !!
//                ucPixelLength                     -> BLANK_FONT : 4 ~ 255 other 0 ~ 255
//                ucBackgroundColor                 -> Color number
//                enumOsdBlinkingType               -> _OSD_BLANK_FONT or _OSD_BLANK_ALIGN
// Output Value :
//--------------------------------------------------
void ScalerOsdBlankFont(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucPixelLength, BYTE ucBackgroundColor, EnumOsdBlankType enumOsdBlankingType)
{
    BYTE ucTemp = 0;

    enumOsdBlankingType = (enumOsdBlankingType & 0x03);

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, enumOsdBlankingType, _OSD_BYTE0);
        ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, (ucPixelLength & 0xFF), _OSD_BYTE1);
        ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, (ucBackgroundColor & 0x3F), _OSD_BYTE2);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdBlankFont(ROW(0), COL(1), LENGTH(1), HEIGHT(1), VALUES(4), BGCOLOR(0), _OSD_BLINKING_EFFECT_DISABLE);
*/

