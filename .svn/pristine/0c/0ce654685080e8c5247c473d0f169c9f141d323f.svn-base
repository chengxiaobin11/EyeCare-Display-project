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
// ID Code      : RL6449_Series_ColorRGBOutputGammaAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GAMMA_TABLE_SIZE                       2052
#define _GAMMA_WRITE_TO_SRAM                    0

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
void ScalerColorRGBOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust output gamma
// Input Value  : SelRegion ans Gamma Table and Gamma Table Banks and Table Length
// Output Value : None
//--------------------------------------------------
void ScalerColorRGBOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum)
{
    if(ScalerGetBit(P9_D0_RGB_GAMMA_CTRL_M1, _BIT0) == _BIT0) // RGB Gamma On
    {
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);

        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT1, _BIT1); // Write RGB Gamma

        // Load gamma table of R Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_RED_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray, _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Load gamma table of G Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_GREEN_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray + _GAMMA_TABLE_SIZE, _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Load gamma table of B Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_BLUE_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray + (_GAMMA_TABLE_SIZE * 2), _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Disable Port Access
        ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~_BIT7, 0x00);

        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT1, 0x00); // Disable Write RGB Gamma

        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
    }
    else
    {
        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT1, _BIT1); // Write RGB Gamma

        // Load gamma table of R Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_RED_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray, _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Load gamma table of G Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_GREEN_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray + _GAMMA_TABLE_SIZE, _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Load gamma table of B Channel
        ScalerColorOutputGammaChannelCtrl(_GAMMA_BLUE_CHANNEL, 0x0000, _GAMMA_WRITE_TO_SRAM);
        ScalerBurstWrite(pucGammaTableArray + (_GAMMA_TABLE_SIZE * 2), _GAMMA_TABLE_SIZE, ucBankNum, P0_66_GAMMA_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

        // Disable Port Access
        ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~_BIT7, 0x00);

        ScalerSetBit(P9_D0_RGB_GAMMA_CTRL_M1, ~_BIT1, 0x00); // Disable Write RGB Gamma
    }
}
