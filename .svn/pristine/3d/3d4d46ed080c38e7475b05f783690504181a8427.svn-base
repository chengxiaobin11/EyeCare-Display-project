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
// ID Code      : RL6851_Series_ColorLibInclude.h No.0000
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

// IDother
extern void ScalerColorIDitherResetFrameCnt(void);

// PCM
extern void ScalerColorPCMInputGammaAdjust(BYTE *pucGammaTableArray, BYTE ucBankNum);
extern WORD ScalerColorPCMGetTableAddress(EnumPCMType enumPCMMode);
extern BYTE ScalerColorPCMGetTableBank(void);

// Ypeaking
extern void ScalerColorYpeaking(bit bOn);

