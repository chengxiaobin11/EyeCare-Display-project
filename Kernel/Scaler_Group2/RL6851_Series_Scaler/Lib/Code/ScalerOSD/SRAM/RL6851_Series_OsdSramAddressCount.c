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
// ID Code      : RL6851_Series_OsdSramAddressCount.c
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
BYTE g_ucColAMax;
BYTE g_ucColBMax;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdSramAddressCount(BYTE ucRow, BYTE ucCol, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol.     -> Just that !!
//                enumOsdWriteType  -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
// Output Value :
//--------------------------------------------------
void ScalerOsdSramAddressCount(BYTE ucRow, BYTE ucCol, EnumOsdWriteType enumOsdWriteType)
{
    WORD usCharCommandStartAddress = 0;
    BYTE ucColSize = 0;
    BYTE ucByte0 = 0;
    BYTE ucByte1 = 0;
    BYTE ucByte2 = 0;

    if(ScalerGetBit(P3A_18_FRAME_CTRL_18, _BIT3) == _BIT3) // OSD 2 Font Function
    {
        ucByte0 = ScalerGetByte(P3A_1B_FRAME_CTRL_1B);
        ucByte1 = ScalerGetByte(P3A_1C_FRAME_CTRL_1C);
        ucByte2 = ScalerGetByte(P3A_1D_FRAME_CTRL_1D);

        if(ucRow >= _OSD_MAP_B_ROW_OFFSET)
        {
            ucRow -= _OSD_MAP_B_ROW_OFFSET;
            ucColSize = GET_OSD_MAPB_COL_MAX();
            // Font Select Base 1
            usCharCommandStartAddress = ((ucByte0 & 0x0F) << 8) | ucByte2;
        }
        else
        {
            ucColSize = GET_OSD_MAPA_COL_MAX();
            // Font Select Base 0
            usCharCommandStartAddress = ((ucByte0 & 0xF0) << 4) | ucByte1;
        }
    }
    else
    {
        ucByte0 = ScalerGetByte(P3A_0C_FRAME_CTRL_0C);
        ucByte1 = ScalerGetByte(P3A_0D_FRAME_CTRL_0D);
        ucByte2 = ScalerGetByte(P3A_0E_FRAME_CTRL_0E);

        ucColSize = GET_OSD_MAPA_COL_MAX();

        // Font Select Base Address
        usCharCommandStartAddress = ((ucByte1 & 0xF0) << 4) | ucByte0;
    }

    usCharCommandStartAddress = usCharCommandStartAddress + (ucRow * ucColSize) + ucCol;

    ScalerOsdAddrSet(_OSD_SRAM, enumOsdWriteType, usCharCommandStartAddress, _OSD_WITHOUT_DB);
}


