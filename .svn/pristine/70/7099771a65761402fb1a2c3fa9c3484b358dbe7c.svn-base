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
// ID Code      : RL6851_Series_OsdFrameControlByteGet.c
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
BYTE ScalerOsdFrameControlByteGet(WORD usAddr, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get OSD Frame Control Byte
// Input Value  : usAddr           -> WindowControl address
//                enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
// Output Value : FrameControl Value
//--------------------------------------------------
BYTE ScalerOsdFrameControlByteGet(WORD usAddr, EnumOsdWriteType enumOsdWriteType)
{
    ScalerSetBit(P0_94_OSD_WRITE_OPTION, ~(_BIT7 | _BIT6 | _BIT5), enumOsdWriteType);
    ScalerSetBit(P0_94_OSD_WRITE_OPTION, ~(_BIT3 | _BIT2), _OSD_WIN_CONTROL);

    ScalerSetByte(P0_90_OSD_ADR_PORT_MSB, (HIBYTE(usAddr) & 0x7F));
    ScalerSetByte(P0_91_OSD_ADR_PORT_LSB, LOBYTE(usAddr));

    return ScalerGetByte(P0_92_OSD_DATA_PORT);
}
