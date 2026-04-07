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
// ID Code      : RL6851_Series_OsdCompressionCtrl.c
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
void ScalerOsdCompressionCtrl(EnumOsdDecodeCompressionType enumDecodeCompression, bit bCompressionEnable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set decode compression data or not, Compression enable/disable
// Input Value  : enumDecodeCompression -> _OSD_DECODE_COMPRESSED or _OSD_DECODE_NON_COMPRESSED
// Input Value  : ucConpressionEn -> _OSD_COMPRESSION_DISABLE or _OSD_COMPRESSION_ENABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdCompressionCtrl(EnumOsdDecodeCompressionType enumDecodeCompression, bit bCompressionEnable)
{
    ScalerSetBit(P3A_17_FRAME_CTRL_17, ~(_BIT1), enumDecodeCompression);
    ScalerSetBit(P3A_17_FRAME_CTRL_17, ~(_BIT0), bCompressionEnable);
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdCompressionCtrl(_OSD_DECODE_NON_COMPRESSED, _OSD_COMPRESSION_ENABLE);
*/


