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
// ID Code      : RL6463_Series_ColorLibInternalInclude.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerFunctionCommonInclude.h"
#include "ScalerColorLibInterface.h"
#include "ScalerCommonRegLibInclude.h"
#include "ScalerCommonNVRamLibInclude.h"
#include "ScalerColorLibInclude.h"

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6463_Series_ColorLibInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
// Output Gamma
extern void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, WORD usOffset, bit bLocation);
extern void ScalerColorOutputGammaEnable(EnumFunctionOnOFF enumOn);

extern void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMSRGBAdjust(EnumSrgbPrecision enumSrgbPrecision, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength);

// UltraVivid
extern bit ScalerColorUltraVividGetStatus(void);

// PCM
extern WORD ScalerColorPCMGetTableAddress(EnumPCMType enumPCMMode);
extern BYTE ScalerColorPCMGetTableBank(void);

// SRGB
extern bit ScalerColorSRGBAdjust(BYTE *pucSRGBArray, EnumSrgbPrecision enumPrecision);

// Color Conversion
extern void ScalerColorSpaceLoadYuv2RgbTable(EnumColorSpace enumColorSpace, bit bUltraVividSupport);
