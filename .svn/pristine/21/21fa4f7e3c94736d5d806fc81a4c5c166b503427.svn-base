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
// ID Code      : RL6851_Series_OsdRoundedWindowPattern16x16.c
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
void ScalerOsdRoundedWindowPattern16x16(BYTE ucIdx, BYTE ucType);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Window Rounded Pattern 16x16
// Input Value  : ucIdx -> Pattern Index 0~15
// Input Value  : ucType -> Pattern Type
// Output Value :
//--------------------------------------------------
void ScalerOsdRoundedWindowPattern16x16(BYTE ucIdx, BYTE ucType)
{
    WORD usAddr = P3A_64_FRAME_CTRL_64;

    usAddr += (ucIdx / 2);
    if((ucIdx % 2) == 0)
    {
        ScalerSetBit(usAddr, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucType & 0x0F));
    }
    else
    {
        ScalerSetBit(usAddr, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((ucType & 0x0F) << 4));
    }
}
