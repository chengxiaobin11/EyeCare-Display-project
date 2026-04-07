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
// ID Code      : RL6851_Series_OsdFrameControlAllByte.c
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
void ScalerOsdFrameControlAllByte(WORD usAddr, EnumOsdDBufType enumDoubleBuffer, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD Frame Control All Byte
// Input Value  : usAddr         -> WindowControl address
//                ucDoubleBuffer -> _OSD_WITHOUT_DB or _OSD_WITH_DB
//                ucByte0        -> Byte0 Data
//                ucByte1        -> Byte1 Data
//                ucByte2        -> Byte2 Data
// Output Value :
//--------------------------------------------------
void ScalerOsdFrameControlAllByte(WORD usAddr, EnumOsdDBufType enumDoubleBuffer, BYTE ucByte0, BYTE ucByte1, BYTE ucByte2)
{
    enumDoubleBuffer = enumDoubleBuffer;
    ScalerOsdWriteAllByte(_OSD_WIN_CONTROL, usAddr, ucByte0, ucByte1, ucByte2);
}

