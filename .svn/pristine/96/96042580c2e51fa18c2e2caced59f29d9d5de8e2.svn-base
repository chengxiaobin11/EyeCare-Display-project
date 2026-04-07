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
// ID Code      : OsdCharCommandAllByteSeries.c
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
void ScalerOsdCharCommandAllByteSeries(WORD usCharAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2, WORD usLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Char Command All Byte Series
// Input Value  : usCharAddr -> SRAM address
//                ucByte0      -> Byte0 data
//                ucByte1      -> Byte1 data
//                ucByte2      -> Byte2 data
//                usLength     -> Length
// Output Value :
//--------------------------------------------------
void ScalerOsdCharCommandAllByteSeries(WORD usCharAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2, WORD usLength)
{
    ScalerOsdSramAddressSet(usCharAddr, _OSD_BYTEALL);

    do
    {
        ScalerSetByte(P0_92_OSD_DATA_PORT, ucByte0);
        ScalerSetByte(P0_92_OSD_DATA_PORT, ucByte1);
        ScalerSetByte(P0_92_OSD_DATA_PORT, ucByte2);
    }
    while(--usLength);
}
