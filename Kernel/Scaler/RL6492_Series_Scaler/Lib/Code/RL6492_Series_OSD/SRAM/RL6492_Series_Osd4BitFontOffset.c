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
// ID Code      : RL6492_Series_Osd4BitFontOffset.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_OSDLibInternalInclude.h"

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
void ScalerOsd4BitFontOffset(WORD usOffset);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD 4 bit font offset
// Input Value  : ucOffset -> 0 ~ 511
// Output Value :
//--------------------------------------------------
void ScalerOsd4BitFontOffset(WORD usOffset)
{
    ScalerSetBit(P3A_21_FRAME_CTRL_21, ~(_BIT0), ((usOffset & 0x100) >> 8));
    ScalerSetByte(P3A_23_FRAME_CTRL_23, (BYTE)usOffset);
}

