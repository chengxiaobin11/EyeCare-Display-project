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
// ID Code      : RL6851_Series_ColorLibInternalInclude.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerFunctionCommonInclude.h"
#include "RL6851_Series_ScalerColorLibInterface.h"
#include "RL6851_Series_ScalerCommonRegLibInclude.h"
#include "RL6851_Series_ScalerCommonNVRamLibInclude.h"
#include "RL6851_Series_ScalerColorLibInclude.h"

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6851_Series_ColorLibInterface.h No.0000
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
