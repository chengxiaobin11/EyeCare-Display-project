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
// ID Code      : RL6851_Series_OsdWriteAllByte.c
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
void ScalerOsdWriteAllByte(BYTE ucIndicateAndDbuf, WORD usAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Write All Byte
// Input Value  : ucIndicateAndDbuf -> CM_90_OSD_ADDR_MSB Hight Byte
//                usAddr            -> SRAM address
//                ucByte0           -> Byte0 Data
//                ucByte1           -> Byte1 Data
//                ucByte2           -> Byte2 Data
// Output Value :
//--------------------------------------------------
void ScalerOsdWriteAllByte(BYTE ucIndicateAndDbuf, WORD usAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2)
{
    ScalerOsdWriteByte((ucIndicateAndDbuf | _OSD_BYTEALL), _OSD_WITHOUT_DB, usAddr, ucByte0);
    ScalerSetByte(P0_92_OSD_DATA_PORT, ucByte1);
    ScalerSetByte(P0_92_OSD_DATA_PORT, ucByte2);
}
