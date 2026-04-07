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
// ID Code      : OsdRoundedWindowPattern8x8.c
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
void ScalerOsdRoundedWindowPattern8x8(BYTE ucIdx, BYTE ucType);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Window Rounded Pattern 8x8
// Input Value  : ucIdx -> Pattern Index 0~7
// Input Value  : ucType -> Pattern Type
// Output Value :
//--------------------------------------------------
void ScalerOsdRoundedWindowPattern8x8(BYTE ucIdx, BYTE ucType)
{
    WORD usAddr = P3A_60_FRAME_CTRL_60;

    usAddr += (ucIdx / 2);

    if((ucIdx % 2) == 0)
    {
        ScalerSetBit(usAddr, ~(_BIT2 | _BIT1 | _BIT0), (ucType & 0x07));
    }
    else
    {
        ScalerSetBit(usAddr, ~(_BIT6 | _BIT5 | _BIT4), ((ucType & 0x07) << 4));
    }
}
