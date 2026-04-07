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
// ID Code      : RL6410_Series_ColorLibInternalInclude.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerFunctionCommonInclude.h"
#include "ScalerColorLibInterface.h"
#include "ScalerCommonRegLibInclude.h"
#include "ScalerCommonNVRamLibInclude.h"
#include "ScalerColorLibInclude.h"
#include "ScalerTconLibInclude.h"
#include "RL6410_Series_TconLibInclude.h"

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    DWORD ulDCR_LD_ABOVE_TH1_NUM;
    DWORD ulDCR_LD_ABOVE_TH2_NUM;
    BYTE pucWinMaxRGB[16];
} StructDCRStoreInfo;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructDCRStoreInfo g_stDCRStoreInfo;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
// Output Gamma
extern void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, WORD usOffset, bit bLocation);
extern void ScalerColorOutputGammaEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorRGBOutputGammaEnable(EnumFunctionOnOFF enumOn);

extern void ScalerColorRGB3DGammaEnable(EnumFunctionOnOFF enumOn);

extern void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMSRGBAdjust(EnumSrgbPrecision enumSrgbPrecision, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength);

//SRGB
extern void ScalerColorSRGBSwap(EnumsRGBSwap enumsRGBSwap);
extern bit ScalerColorSRGBAdjust(BYTE *pucSRGBArray, EnumSrgbPrecision enumPrecision);
extern EnumSrgbPrecision ScalerColorSRGBGetPrecision(void);

// Global Hue/Sat
extern SWORD ScalerColorSRGBCosine(SWORD shDegree);
extern SWORD ScalerColorSRGBSine(SWORD shDegree);
extern void ScalerColorSRGBMatrixMultiply(SWORD(*ppshArrayA)[3], SWORD(*ppshArrayB)[3], SWORD(*ppshArrayC)[3]);


// UltraVivid
extern bit ScalerColorUltraVividGetStatus(void);

// ICM
extern void ScalerColorSCMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2);

// PCM
extern WORD ScalerColorPCMGetTableAddress(EnumPCMType enumPCMMode);
extern BYTE ScalerColorPCMGetTableBank(void);
extern WORD ScalerColorOCCPCMGammaGetTableAddress(EnumOCCPCMGammaType enumOCCPCMGammaType);
extern BYTE ScalerColorOCCPCMGammaGetTableBank(void);

extern bit ScalerFmtCnvGetHalfDataPathEvenOddModeStatus(void);
extern bit ScalerColorSRGBAdjust(BYTE *pucSRGBArray, EnumSrgbPrecision enumPrecision);

extern void ScalerColorDDomainDBApply(EnumDBApply enumDBApply);

// Color Conversion
extern void ScalerColorSpaceLoadYuv2RgbTable(EnumColorSpace enumColorSpace, bit bUltraVividSupport);
