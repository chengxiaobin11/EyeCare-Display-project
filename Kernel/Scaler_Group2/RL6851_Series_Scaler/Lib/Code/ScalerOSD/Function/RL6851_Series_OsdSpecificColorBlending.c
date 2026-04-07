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
// ID Code      : RL6851_Series_OsdSpecificColorBlending.c
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
void ScalerOsdSpecificColorBlending(bit bEnable, BYTE ucIndex);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set specific color blending
// Input Value  :     bEnable -> _ENABLE or _DISABLE
//                    ucIndex -> BlendingColor LUT index (0~63)
// Output Value :
//--------------------------------------------------
void ScalerOsdSpecificColorBlending(bit bEnable, BYTE ucIndex)
{
    // Set Match blending type 2 color bit[5:0]
    ScalerSetBit(P3A_08_FRAME_CTRL_08, ~(_BIT4), (_BIT4));

    // Set Specific Color Blending (blending Type 2) Enable/Disable
    ScalerSetBit(P3A_09_FRAME_CTRL_09, ~_BIT7, ((BYTE)bEnable << 7));

    // Set Blending Color from 64-color LUT [5:0] (blending Type 2)
    ScalerSetBit(P3A_08_FRAME_CTRL_08, ~(_BIT3 | _BIT2), ((ucIndex & (_BIT5 | _BIT4)) >> 2));
    ScalerSetBit(P3A_09_FRAME_CTRL_09, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIndex & 0x0F));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdSpecificColorBlending(_ENABLE,15);
*/
