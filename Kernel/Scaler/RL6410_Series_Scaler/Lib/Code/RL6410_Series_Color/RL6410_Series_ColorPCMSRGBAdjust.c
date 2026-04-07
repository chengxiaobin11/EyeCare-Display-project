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
// ID Code      : RL6410_Series_ColorPCMSRGBAdjust.c
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
void ScalerColorPCMSRGBAdjust(EnumSrgbPrecision enumSrgbPrecision, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Write Color Matrix
// Input Value  : bIsAdobe: 1 = AdobeRGB, 0- sRGB, Table Length
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMSRGBAdjust(EnumSrgbPrecision enumSrgbPrecision, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength)
{
    if(usLength == 312)
    {
        ScalerSetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_26_CTS_BRI_SWAP, ~_BIT4, _BIT4);
    }
    else
    {
        ScalerSetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_26_CTS_BRI_SWAP, ~_BIT4, 0x00);
    }

    // Clear Waiting flag
    ScalerSetBit(P0_62_SRGB_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(P0_62_SRGB_CTRL, ~_BIT6, _BIT6); // Reset Port

    ScalerTimerPollingFlagProc(2, P0_62_SRGB_CTRL, _BIT6, 0); // pollling till Reset port address finished

    ScalerSetBit(P0_62_SRGB_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00); // Write sequence

    ScalerBurstWrite(pucColorMatrixArray, usLength, ucBankNum, P0_63_SRGB_ACCESS_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    if(usLength != 312)
    {
        memset(pData, 0, 6);
        ScalerWrite(P0_63_SRGB_ACCESS_PORT_SETA, 6, pData, _NON_AUTOINC);
    }
    // ScalerBurstWrite(pData, 6, 0, P0_63_SRGB_ACCESS_PORT_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_XRAM);

    ScalerSetBit(P0_68_GAMMA_BIST_DITHER_SETA, ~(_BIT6 | _BIT5), (enumSrgbPrecision << 5)); // Precision

    ScalerSetBit(P0_62_SRGB_CTRL, ~_BIT7, _BIT7);   // no apply none, always effective on dvs
}

