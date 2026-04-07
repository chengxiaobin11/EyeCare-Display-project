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
// ID Code      : RL6851_Series_OsdChange1BitColor.c
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
void ScalerOsdChange1BitColor(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucForegroundColor, BYTE ucBackgroundColor);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol. ucLength. ucHeight.     -> Just that !!
//                ucForegroundColor. ucBackgroundColor  -> Color number
// Output Value :
//--------------------------------------------------
void ScalerOsdChange1BitColor(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    BYTE ucTemp = 0;

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        ScalerOsdSramDataValue(ucRow + ucTemp, ucCol, ucLength, ((ucForegroundColor << 4) | ucBackgroundColor), _OSD_BYTE2);
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdChange1BitColor(ROW(0), COL(0), LENGTH(1), HEIGHT(1), FGCOLOR(3), BGCOLOR(4));
*/

