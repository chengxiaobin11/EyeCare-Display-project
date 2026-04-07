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
// ID Code      : RL6410_Series_ColorLibInclude.h No.0000
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
// Color Sampling
extern void ScalerColor420To422D2Enable(EnumFunctionOnOFF enumFunctionOnOFF);
extern void ScalerColor420To422D3Enable(EnumFunctionOnOFF enumFunctionOnOFF);

// IDither
extern void ScalerColorIDitherResetFrameCnt(void);

// DDither
extern void ScalerColorDDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress);
extern void ScalerColorDDitherLoadTempoTable(BYTE code *pucTempoTable, BYTE ucBankAddress);
extern void ScalerColorDDitherLoadSetting(DWORD ulSettingOption);

// HLW
extern void ScalerColorHLWIDLTILSRAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
extern void ScalerColorHLWIDLTILSREnable(EnumFunctionOnOFF enumOn);

// ICM
extern void ScalerColorICMUVOffsetLoadTable(BYTE code *pucICMTable, BYTE ucBankNum);
extern void ScalerColorICMBRILoadTable(BYTE code *pucICMTable, BYTE ucBankNum);

// Six Color ICM
extern void ScalerColorSixColorInitialNormal(void);
extern void ScalerColorSixColorAdjustNormal(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);
extern void ScalerColorSixColorInitialBriCompensate(void);
extern void ScalerColorSixColorAdjustBriCompensate(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);

// PCM
extern void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern WORD ScalerColorPCMGetTableAddress(EnumPCMType enumPCMMode);
extern BYTE ScalerColorPCMGetTableBank(void);
extern WORD ScalerColorOCCPCMGammaGetTableAddress(EnumOCCPCMGammaType enumOCCPCMGammaType);
extern BYTE ScalerColorOCCPCMGammaGetTableBank(void);

extern bit ScalerFmtCnvGetHalfDataPathEvenOddModeStatus(void);
extern bit ScalerColorSRGBAdjust(BYTE *pucSRGBArray, EnumSrgbPrecision enumPrecision);

// D domain double buffer
extern void ScalerColorDDomainDBEnable(bit bEn);
extern bit ScalerColorDDomainDBStatus(void);
extern void ScalerColorDDomainDBTriggerEvent(EnumDBTriggerEvent enumDBTriggerEvent);
extern void ScalerColorDDomainDBApply(EnumDBApply enumDBApply);

// Global D domain double buffer
extern bit ScalerColorGlobalDBStatus(void);
