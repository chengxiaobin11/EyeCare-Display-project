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
// ID Code      : RL6851_Series_ScalerColorICMAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of ICM
//--------------------------------------------------


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
void ScalerColorICMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust ICM Function
// Input Value  : Adjust Option
// Output Value : None
//--------------------------------------------------
void ScalerColorICMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2)
{
    ScalerSetBit(P7_D0_ICM_CONTROL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0),
                 (((BYTE)((bit)(ucAdjustOption2 & _Y_CORRECTION_MODE)) << 6) |
                  ((BYTE)((bit)(ucAdjustOption2 & _UV_DELTA_RANGE)) << 5) |
                  ((BYTE)((bit)(ucAdjustOption2 & _CM0_ENABLE)) << 4) |
                  ((BYTE)((bit)(ucAdjustOption2 & _CM1_ENABLE)) << 3) |
                  ((BYTE)((bit)(ucAdjustOption2 & _CM2_ENABLE)) << 2) |
                  ((BYTE)((bit)(ucAdjustOption2 & _CM3_ENABLE)) << 1) |
                  ((BYTE)((bit)(ucAdjustOption2 & _CM4_ENABLE)))));

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), (((BYTE)((bit)(ucAdjustOption1 & _UV_DELTA_RANGE_EXTEND)) << 4) | ((BYTE)((bit)(ucAdjustOption2 & _CM5_ENABLE)) << 3)));

    // Enable ICM New Mode and UV Offset on Right/Left Buffer
    ScalerSetBit(P7_D4_ICM_SEL2, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
}

