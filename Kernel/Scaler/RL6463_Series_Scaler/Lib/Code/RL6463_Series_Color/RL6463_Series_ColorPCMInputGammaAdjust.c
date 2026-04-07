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
// ID Code      : RL6463_Series_ColorPCMInputGammaAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6463_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _PCM_INPUTGAMMA_TABLE_SIZE              99


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
void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Adjust Input gamma
// Input Value  : IG Gamma Table Bank and IG Gamma table and Table Length
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum)
{
    // Enable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, _BIT7);

    // Load Input Gamma Table
    ScalerBurstWrite(pucGammaTableArray, _PCM_INPUTGAMMA_TABLE_SIZE, ucBankNum, P9_A0_INPUT_GAMMA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load Threshold
    ScalerBurstWrite(pucGammaTableArray + _PCM_INPUTGAMMA_TABLE_SIZE, 1, ucBankNum, P9_A2_INPUT_GAMMA_LOW_THRE, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(pucGammaTableArray + _PCM_INPUTGAMMA_TABLE_SIZE + 1, 1, ucBankNum, P9_A3_INPUT_GAMMA_HIGH_THRE, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL, ~_BIT7, 0x00);
}

