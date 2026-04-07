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
// ID Code      : RL6369_Series_ColorLibInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
// Color Conversion
extern void ScalerColorSpaceConvert(EnumColorSpace enumColorSpace, EnumDBApply enumDBApply);
extern void ScalerColorSpaceConvertUltraVividSupport(EnumColorSpace enumColorSpace, EnumDBApply enumDBApply);
extern void ScalerColorMdomainForceYUV(EnumColorSpace enumColorSpace, EnumDBApply enumDBApply);

// DCC
extern void ScalerColorDCCEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorDCCNormalizeFactorAdjust(void);
extern void ScalerColorDCCAdjust(BYTE code *pucDccTable, BYTE ucBankAddress);
extern void ScalerColorDCCHistoSetting(void);
extern void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray);

// DCR
extern void ScalerColorDCRAdjust(WORD usThreshold1, WORD usThreshold2, EnumDCRMeasureSel enumDCRMeasureSel);
extern DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumDCRReadOption);
extern WORD ScalerColorDCRGetAverage(EnumDCRAverageOption enumDCRAverageOption, DWORD ulDivider);

// HLW
extern void ScalerColorHLWUltraVividAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);
extern void ScalerColorHLWYpeakingAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);
extern void ScalerColorHLWPCMAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);
extern void ScalerColorHLWIAPSGainAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);

// ICM
extern void ScalerColorICMEnable(EnumFunctionOnOFF enumOn);

// Output Gamma
extern void ScalerColorOutputGammaEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorOutputGammaWriteTable(BYTE *pucGammaTableArray, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength);

// PCM
extern void ScalerColorPCMInputGammaEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);

extern void ScalerColorPCMLoadTable(EnumPCMType enumPCMMode, BYTE *pucIGammaTableArray, BYTE *pucOGammaTableArray, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength, BYTE ucGammaBankNum);
extern void ScalerColorPCMOutputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern void ScalerColorPCMSRGBAdjust(EnumSrgbPrecision enumSrgbPrecision, BYTE *pucColorMatrixArray, BYTE ucBankNum, WORD usLength);

// ScaleDown
extern void ScalerColorSetScalingDownMaskLSB(void);

// SRGB
extern void ScalerColorSRGBEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorSetSRGBGlobalHueSat(SWORD shDeltaHue, WORD usDeltaSat);
extern void ScalerColorSRGBSwap(EnumsRGBSwap enumsRGBSwap);
extern bit ScalerColorSRGBAdjust(BYTE *pucSRGBArray, EnumSrgbPrecision enumPrecision);

// UltraVivid
extern void ScalerColorUltraVividAdjust(BYTE code *pucUltraVividSetting, BYTE ucBankNum);
extern void ScalerColorUltraVividEnable(EnumFunctionOnOFF enumFunctionOnOff, EnumDBApply enumDBApply);
extern  bit ScalerColorUltraVividSetDisable(void);

// Ypeaking
extern void ScalerColorYpeaking(bit bOn);

// Highlight Window
extern void ScalerColorHLWBRICTSAdjust(EnumBriConHLWType enumHLWActive, EnumDBApply enumDBApply);

// Contrast
extern void ScalerColorContrastAdjust(EnumBriConCoefType enumBriConCoefType, WORD *pusData);

// Brightness
extern void ScalerColorBrightnessAdjust(EnumBriConCoefType enumBriConCoefType, WORD *pusData);

// Ringing Filter
extern void ScalerColorRingingFilterAdjust(BYTE *pucOffsetCoef);
