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
// ID Code      : RL6410_Series_ColorPanelUniformityOffsetAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

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
void ScalerColorPanelUniformityOffsetAdjust(BYTE *pucUNILUT, WORD usUNILUTSize, BYTE ucBankNum);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Load Panel Uniformity LUT
// Input Value  : LUT, Bank number, EnumUniformityModeSelect
// Output Value : None
//--------------------------------------------------
void ScalerColorPanelUniformityOffsetAdjust(BYTE *pucUNILUT, WORD usUNILUTSize, BYTE ucBankNum)
{
    // Enable uniformity access
    ScalerSetBit(P34_00_UN_GLOBAL_CTRL, ~_BIT2, _BIT2);

    // Load uniformity offset LUT
    ScalerBurstWrite(pucUNILUT, usUNILUTSize, ucBankNum, P34_0F_UN_OFFSET_LUT_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable uniformity access
    ScalerSetBit(P34_00_UN_GLOBAL_CTRL, ~_BIT2, 0x00);
}

