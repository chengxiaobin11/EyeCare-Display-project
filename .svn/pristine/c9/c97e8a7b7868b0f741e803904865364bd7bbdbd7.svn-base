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
// ID Code      : RL6851_Series_ScalerColorInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_COLOR_IP_DCC_HISTOGRAM == _ON)
#define GET_DCC_READY_STATUS()                      (g_bDCCReadyStatus)
#define SET_DCC_READY_STATUS()                      (g_bDCCReadyStatus = _TRUE)
#define CLR_DCC_READY_STATUS()                      (g_bDCCReadyStatus = _FALSE)
#endif

//--------------------------------------------------
// Macro of DCR Ready Flag
//--------------------------------------------------
#if(_COLOR_IP_DCR == _ON)
#define GET_DCR_READY_STATUS()                      (g_bDCRReadyStatus)
#define SET_DCR_READY_STATUS()                      (g_bDCRReadyStatus = _TRUE)
#define CLR_DCR_READY_STATUS()                      (g_bDCRReadyStatus = _FALSE)
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_COLOR_IP_DCC_HISTOGRAM == _ON)
extern bit g_bDCCReadyStatus;
#endif

#if(_COLOR_IP_DCR == _ON)
extern bit g_bDCRReadyStatus;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
// Digital Filter
#if(_VGA_SUPPORT == _ON)
#if(_DIGITAL_FILTER_SUPPORT == _ON)
extern void ScalerColorDigitalFilterAdjust(void);
#endif
#endif

// Highlight Window
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight, EnumDBApply enumDBApply);
extern void ScalerColorHLWEnable(EnumFunctionOnOFF enumOn, EnumDBApply enumDBApply);
#endif

// IDither
#if(_I_DITHER_SUPPORT == _ON)
extern void ScalerColorIDitherAdjust(BYTE code *pucDitherTable, BYTE code *pucSeqTable, BYTE code *pucTempoTable, BYTE ucBankAddress);
#endif

#if(_D_DITHER_SUPPORT == _ON)
extern void ScalerColorDDitherEnable(EnumFunctionOnOFF enumOn);
#endif

// DCR
#if((_DCR_SUPPORT == _ON) || (_IAPS_SUPPORT == _ON))
extern void ScalerColorDCRSetSource(void);
#endif

// ICM
#if(_ICM_SUPPORT == _ON)
extern void ScalerColorICMLoadTable(BYTE code *pucICMTable, BYTE ucBankNum);
#endif

// Six Color ICM
#if(_SIX_COLOR_SUPPORT == _ON)
extern void ScalerColorSixColorInitial(void);
extern void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);
#endif

// Y-Peaking
#if(_YPEAKING_SUPPORT == _ON)
extern void ScalerColorYpeakingAdjust(EnumYpeakingMode enumYPeakMode, BYTE ucGain, EnumYpeakingCoeffResolution enumResolution, BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum);
#endif

#if((_HDR10_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
extern void ScalerColorHDR10SupportSwitch(EnumSourceSearchPort enumSourcePort, EnumHDR10ModeDef enumSupport);
#endif

