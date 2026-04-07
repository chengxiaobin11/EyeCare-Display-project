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
// ID Code      : OsdChange2BitColor16_31.c
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
void ScalerOsdChange2BitColor16_31(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol. ucLength. ucHeight.       -> Just that !!
//                ucColor0. ucColor1. ucColor2. ucColor3  -> Color number
// Output Value :
//--------------------------------------------------
void ScalerOsdChange2BitColor16_31(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{
    BYTE ucRowCmdByte0 = _BIT7;
    bit bOSDOn = _OFF;
    BYTE ucTemp = 0;

    // Get OSD Status
    bOSDOn = ScalerGetBit(P3A_02_FRAME_CTRL_02, _BIT0);

    // Set OSD Circuit Enable for Write-Protection Function effective in OSD enable.
    ScalerSetBit(P3A_02_FRAME_CTRL_02, ~(_BIT0), _ON);

    // Check Global Double Buffer
    if(bOSDOn == _OFF)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    if(((ucColor0 >= 16) && (ucColor1 >= 16) && (ucColor2 >= 16) && (ucColor3 >= 16)))
    {
        ucRowCmdByte0 |= _BIT6;
        ucColor0 -= 16;
        ucColor1 -= 16;
        ucColor2 -= 16;
        ucColor3 -= 16;
    }


    if(ScalerGetBit(P3A_18_FRAME_CTRL_18, _BIT3) == _BIT3) // OSD 2 font function
    {
        if(ucRow >= _OSD_MAP_B_ROW_OFFSET)
        {
            ScalerOsdSramAddressSet((ScalerGetByte(P3A_1A_FRAME_CTRL_1A) + (ucRow - _OSD_MAP_B_ROW_OFFSET)), _OSD_BYTE0);
        }
        else
        {
            ScalerOsdSramAddressSet((ScalerGetByte(P3A_19_FRAME_CTRL_19) + ucRow), _OSD_BYTE0);
        }
    }
    else
    {
        ScalerOsdSramAddressSet((0 + ucRow), _OSD_BYTE0);
    }

    for(ucTemp = 0; ucTemp < ucHeight; ucTemp++)
    {
        ScalerOsdDataPort(ucRowCmdByte0);
    }

    ScalerOsdChange2BitColor(ucRow, ucCol, ucLength, ucHeight, ucColor0, ucColor1, ucColor2, ucColor3);

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
    ScalerOsdChange2BitColor(ROW(0), COL(0), LENGTH(1), HEIGHT(1), COLOR00(0), COLOR01(1), COLOR10(2), COLOR11(3));
*/


