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
// ID Code      : RL6851_Series_OsdRoundedWindowPattern32x32.c
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
void ScalerOsdRoundedWindowPattern32x32(BYTE ucIdx, BYTE ucType);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Window Rounded Pattern 32x32
// Input Value  : ucIdx -> Pattern Index 0~31
// Input Value  : ucType -> Pattern Type
// Output Value :
//--------------------------------------------------
void ScalerOsdRoundedWindowPattern32x32(BYTE ucIdx, BYTE ucType)
{
    WORD usAddr = P3A_6C_FRAME_CTRL_6C;

    usAddr += ucIdx;
    ScalerSetBit(usAddr, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucType & 0x1F));
}
