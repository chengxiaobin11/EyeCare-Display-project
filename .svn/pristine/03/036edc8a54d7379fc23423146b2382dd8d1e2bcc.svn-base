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
// ID Code      : RL6851_Series_OsdSramGetData.c
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
void ScalerOsdSramGetData(EnumOsdWriteType enumOsdWriteType, WORD usSramAddress, BYTE ucLength, BYTE *pucData);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get SRAM address value
// Input Value  : enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
//                ucLength -> Length
// Output Value : pucData -> Data
//--------------------------------------------------
void ScalerOsdSramGetData(EnumOsdWriteType enumOsdWriteType, WORD usSramAddress, BYTE ucLength, BYTE *pucData)
{
    BYTE ucLenIdx = 0;
    BYTE ucRdIdx = 0;
    BYTE ucByteSel = 0;
    bit bOSDEnableBackup = 0;

    bOSDEnableBackup = ScalerGetBit(P3A_02_FRAME_CTRL_02, _BIT0);

    ScalerOsdSramGetDataInit();

    ucByteSel = ((enumOsdWriteType == _OSD_BYTEALL) ? (3) : ((enumOsdWriteType == _OSD_BYTE0_BYTE1) ? 2 : ((enumOsdWriteType == _OSD_BYTE0_BYTE2) ? 2 : ((enumOsdWriteType == _OSD_BYTE1_BYTE2) ? 2 : 1))));

    for(ucLenIdx = 0; ucLenIdx < ucLength; ucLenIdx++)
    {
        ScalerOsdSramAddressSet(usSramAddress + ucLenIdx, enumOsdWriteType);

        for(ucRdIdx = 0; ucRdIdx < ucByteSel; ucRdIdx++)
        {
            pucData[(ucLenIdx * ucByteSel) + ucRdIdx] = ScalerGetByte(P0_92_OSD_DATA_PORT);
        }

        for(ucRdIdx = 0; ucRdIdx < ucByteSel; ucRdIdx++)
        {
            pucData[(ucLenIdx * ucByteSel) + ucRdIdx] = ScalerGetByte(P0_92_OSD_DATA_PORT);
        }
    }

    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~_BIT4, 0x00);
    ScalerOsdCircuitActivated(bOSDEnableBackup);
}


