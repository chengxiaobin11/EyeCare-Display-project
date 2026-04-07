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
// ID Code      : RL6432_Series_ColorIAPSGainValueAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6432_Series_ColorLibInternalInclude.h"

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
void ScalerColorIAPSGainValueAdjust(WORD usGainValue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust IAPS Gain Value
// Input Value  : usGainValue
// Output Value : None
//--------------------------------------------------
void ScalerColorIAPSGainValueAdjust(WORD usGainValue)
{
    ScalerSetByte(P7_E1_GAIN_VALUE1_M1, (BYTE)(usGainValue >> 7));
    ScalerSetByte(P7_E2_GAIN_VALUE0_M1, (BYTE)(usGainValue & 0x007F) << 1);

    // Set DoubleBuffer Not Ready
    ScalerSetBit(P7_E4_IAPS_GAIN_DB_CTRL_M1, ~_BIT1, _BIT1);
}
