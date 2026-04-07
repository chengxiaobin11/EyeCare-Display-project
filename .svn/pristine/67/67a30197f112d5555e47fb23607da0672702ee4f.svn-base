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
// ID Code      : ScalerColorLibInclude.h No.0000
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
// Color Conversion
extern EnumColorSpace ScalerColorGetColorSpace(void);
extern bit ScalerColorGetColorSpaceRGB(EnumColorSpace enumColorSpace);

// IDither
extern void ScalerColorIDitherEnable(EnumFunctionOnOFF enumOn);

// DDither
extern void ScalerColorDDitherEnable(EnumFunctionOnOFF enumOn);
extern void ScalerColorDDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress);

// Digital Filter
extern void ScalerColorDigitalFilterNSmearAdjust(BYTE ucTHD, BYTE ucDIV);
extern void ScalerColorDigitalFilterNRDisableAdjust(void);
extern void ScalerColorDigitalFilterPSmearAdjust(BYTE ucTHD, BYTE ucDIV);
extern void ScalerColorDigitalFilterNRingAdjust(BYTE ucTHD, BYTE ucDIV);
extern void ScalerColorDigitalFilterPRingAdjust(BYTE ucTHD, BYTE ucDIV);
extern void ScalerColorDigitalFilterExtensionAdjust(void);

// Highlight Window
extern void ScalerColorHLWDDomainAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
extern void ScalerColorHLWDDomainEnable(EnumFunctionOnOFF enumOn);

// IDither
extern void ScalerColorIDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress);
extern void ScalerColorIDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress);
extern void ScalerColorIDitherLoadTemporalTable(BYTE code *pucTempoTable, BYTE ucBankAddress);
extern void ScalerColorIDitherLoadSetting(WORD usAdjustOption);

// DCC
extern void ScalerColorDCCSetMeasureRegion(EnumHLWType enumHLWType);

// ICM
extern void ScalerColorICMAdjust(BYTE ucAdjustOption1, BYTE ucAdjustOption2);

// Other
extern BYTE ScalerColorGetColorDepth(void);
extern BYTE ScalerColorSpaceConvertIDomainWaitEventForAutoBlockToggle(void);
extern void ScalerColorSpaceConvertDDomainWaitEventForAutoBlockToggle(BYTE ucDVSCnt);

