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
// ID Code      : RL6851_Series_ColorPCM.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ColorLibInternalInclude.h"

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
void ScalerColorPCMLoadTable(EnumPCMType enumPCMMode, BYTE *pucIGammaTableArray, BYTE *pucOGammaTableArray, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength, BYTE ucGammaBankNum);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set PCM(Input Gamma, Output Gamma, Color Matrix)
// Input Value  : PCM Type --> sRGB / AdobeRGB
//                Input Gamma Table  & its bank number
//                Output Gamma Table & its bank number
//                Color Matrix       & its bank number
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMLoadTable(EnumPCMType enumPCMMode, BYTE *pucIGammaTableArray, BYTE *pucOGammaTableArray, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength, BYTE ucGammaBankNum)
{
    // Set InputGamma LUT
    if(enumPCMMode == _PCM_USER_MODE)
    {
        ScalerColorPCMInputGammaAdjust(pucIGammaTableArray, ucBankNum);
    }
    else
    {
        ScalerColorPCMInputGammaAdjust((BYTE *)ScalerColorPCMGetTableAddress(enumPCMMode), ScalerColorPCMGetTableBank());
    }

    // Load Gamma table
    ScalerColorPCMOutputGammaAdjust(pucOGammaTableArray, ucGammaBankNum);

    // Set color Matrix
    ScalerColorPCMSRGBAdjust(_SRGB_0_BIT_SHIFT_LEFT, pucColorMatrixArray, ucBankNum, usLength);
}

