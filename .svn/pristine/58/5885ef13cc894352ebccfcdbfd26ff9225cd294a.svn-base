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
// ID Code      : RL6449_Series_ColorSCMAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

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
void ScalerColorSCMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust SCM Function
// Input Value  : Adjust Option
// Output Value : None
//--------------------------------------------------
void ScalerColorSCMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2)
{
    ScalerSetByte(P7_CC_SCM_BLOCK_ENABLE, (((BYTE)((bit)(ucAdjustOption2 & _SCM0_BLOCK0_ENABLE)) << 7) | ((BYTE)((bit)(ucAdjustOption2 & _SCM0_BLOCK1_ENABLE)) << 6) |
                                           ((BYTE)((bit)(ucAdjustOption2 & _SCM1_BLOCK0_ENABLE)) << 5) | ((BYTE)((bit)(ucAdjustOption2 & _SCM1_BLOCK1_ENABLE)) << 4) |
                                           ((BYTE)((bit)(ucAdjustOption2 & _SCM2_BLOCK0_ENABLE)) << 3) | ((BYTE)((bit)(ucAdjustOption2 & _SCM2_BLOCK1_ENABLE)) << 2) |
                                           ((BYTE)((bit)(ucAdjustOption2 & _SCM3_BLOCK0_ENABLE)) << 1) | ((BYTE)((bit)(ucAdjustOption2 & _SCM3_BLOCK1_ENABLE)))));

    ScalerSetBit(P7_CD_SCM_BLOCK_SELECT, ~_BIT4, (BYTE)((bit)(ucAdjustOption1 & _SCMN_SHARE_REG)) << 4);
}
