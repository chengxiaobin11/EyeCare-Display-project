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
// ID Code      : OsdCommandAllByte.c
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
void ScalerOsdCommandAllByte(WORD usCharAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Command All Byte
// Input Value  : usCharAddr   -> SRAM address
//                ucByte0      -> Byte0 data
//                ucByte1      -> Byte1 data
//                ucByte2      -> Byte2 data
// Output Value :
//--------------------------------------------------
void ScalerOsdCommandAllByte(WORD usCharAddr, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2)
{
    ScalerOsdWriteAllByte(_OSD_SRAM, usCharAddr, ucByte0, ucByte1, ucByte2);
}
