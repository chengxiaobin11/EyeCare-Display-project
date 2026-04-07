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
// ID Code      : RL6410_Series_ColorPCMRGBInputGammaAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _PCM_INPUTGAMMA_TABLE_SIZE              195
#define _PCM_R_CHANNEL_IG_START                 0
#define _PCM_G_CHANNEL_IG_START                 (_PCM_R_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE + 2)
#define _PCM_B_CHANNEL_IG_START                 (_PCM_G_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE + 2)


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
void ScalerColorPCMRGBInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Adjust Input gamma
// Input Value  : IG Gamma Table Bank and IG Gamma table and Table Length
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMRGBInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum)
{
    // Set Input Gamma to New Mode (Three Channel)
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT0, _BIT0);

    // Enable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT7, _BIT7);

    // Enable R Channel Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~(_BIT2 | _BIT1), (_GAMMA_RED_CHANNEL << 1));

    // Load Input Gamma Table
    ScalerBurstWrite(pucGammaTableArray, _PCM_INPUTGAMMA_TABLE_SIZE, ucBankNum, P9_A0_INPUT_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load Threshold
    ScalerBurstWrite(pucGammaTableArray + _PCM_INPUTGAMMA_TABLE_SIZE, 1, ucBankNum, P9_A2_INPUT_GAMMA_LOW_THRE_R, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(pucGammaTableArray + _PCM_INPUTGAMMA_TABLE_SIZE + 1, 1, ucBankNum, P9_A3_INPUT_GAMMA_HIGH_THRE_R, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Enable G Channel Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~(_BIT2 | _BIT1), (_GAMMA_GREEN_CHANNEL << 1));

    // Load Input Gamma Table
    ScalerBurstWrite(pucGammaTableArray + _PCM_G_CHANNEL_IG_START, _PCM_INPUTGAMMA_TABLE_SIZE, ucBankNum, P9_A0_INPUT_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load Threshold
    ScalerBurstWrite(pucGammaTableArray + _PCM_G_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE, 1, ucBankNum, P9_A4_INPUT_GAMMA_LOW_THRE_G, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(pucGammaTableArray + _PCM_G_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE + 1, 1, ucBankNum, P9_A5_INPUT_GAMMA_HIGH_THRE_G, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Enable B Channel Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~(_BIT2 | _BIT1), (_GAMMA_BLUE_CHANNEL << 1));

    // Load Input Gamma Table
    ScalerBurstWrite(pucGammaTableArray + _PCM_B_CHANNEL_IG_START, _PCM_INPUTGAMMA_TABLE_SIZE, ucBankNum, P9_A0_INPUT_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Load Threshold
    ScalerBurstWrite(pucGammaTableArray + _PCM_B_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE, 1, ucBankNum, P9_A6_INPUT_GAMMA_LOW_THRE_B, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(pucGammaTableArray + _PCM_B_CHANNEL_IG_START + _PCM_INPUTGAMMA_TABLE_SIZE + 1, 1, ucBankNum, P9_A7_INPUT_GAMMA_HIGH_THRE_B, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable Input Gamma Port Access
    ScalerSetBit(P9_A1_INPUT_GAMMA_CTRL_SETA, ~_BIT7, 0x00);
}

