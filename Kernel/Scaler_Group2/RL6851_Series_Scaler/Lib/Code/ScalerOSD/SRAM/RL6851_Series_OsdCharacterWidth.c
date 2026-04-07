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
// ID Code      : RL6851_Series_OsdCharacterWidth.c
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
void ScalerOsdCharacterWidth(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : ucRow, ucCol -> 1-bit font position
//                ucWidth      -> font width
//                ucLength     -> number of 1-bit font to be changed
// Output Value :
//--------------------------------------------------
void ScalerOsdCharacterWidth(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucLength)
{
    BYTE ucIdx = 0;
    bit bOSDOn = _OFF;

    // Get OSD Status for Write-Protection Function setting OSD circuit enable.
    bOSDOn = ScalerGetBit(P3A_02_FRAME_CTRL_02, _BIT0);

    ScalerOsdWriteProtection(_ENABLE, _OSD_BYTE0, (_BIT7 | _BIT6 | _BIT5));
    ScalerOsdSramAddressCount(ucRow, ucCol, _OSD_BYTE0);

    for(ucIdx = 0; ucIdx < ucLength; ucIdx++)
    {
        ScalerOsdDataPort(ucWidth);
    }

    ScalerOsdWriteProtection(_DISABLE, _OSD_BYTE0, (_BIT7 | _BIT6 | _BIT5));

    // Recovery OSD Status
    if(bOSDOn == _OFF)
    {
        ScalerOsdCircuitActivated(bOSDOn);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdCharacterWidth(ROW_MAPA(0), COL(0), WIDTH(4), LENGTH(1));
*/

