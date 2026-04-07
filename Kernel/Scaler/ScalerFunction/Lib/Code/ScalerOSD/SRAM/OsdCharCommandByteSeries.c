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
// ID Code      : OsdCharCommandByteSeries.c
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
void ScalerOsdCharCommandByteSeries(WORD usCharAddr, EnumOsdWriteType enumOsdWriteType, BYTE ucData, WORD usLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Char Command Byte Series
// Input Value  : usCharAddr       -> SRAM address
//                enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2 or _OSD_BYTEALL
//                ucData           -> ucByteSelect' data
//                usLength         -> Length
// Output Value :
//--------------------------------------------------
void ScalerOsdCharCommandByteSeries(WORD usCharAddr, EnumOsdWriteType enumOsdWriteType, BYTE ucData, WORD usLength)
{
    ScalerOsdSramAddressSet(usCharAddr, enumOsdWriteType);

    do
    {
        ScalerSetByte(P0_92_OSD_DATA_PORT, ucData);
    }
    while(--usLength);
}
