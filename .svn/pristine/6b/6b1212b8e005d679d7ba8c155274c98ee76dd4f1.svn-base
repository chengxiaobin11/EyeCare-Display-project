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
// ID Code      : RL6463_Series_MeasureInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _INPUT_TIMING_HWIDTH_DELTA                      2
#define CHECK_MEASURE_FROM_VGA()                        (ScalerGetBit(P30_00_SYNC_SELECT, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == (_BIT3 | _BIT2 | _BIT0))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMeasureInterfaceInitial(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort *penumSourceSearchPort);
extern bit ScalerMeasureGetOfflineMeasureResult(StructMeasureSyncData *pstMeasureSyncHV, EnumSourceSearchPort enumSourceSearchPort);
extern void ScalerMeasureSetOfflineMeasure(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourcePort);
extern void ScalerMeasureAutoFuncVBoundInitial(WORD usVBoundStart, WORD usVBoundEnd);

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern bit ScalerMeasureFinalSetting(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort);
extern bit ScalerMeasureGetAutoResult(StructAutoActiveData *pstActiveRegion, bit bWait);
#endif

extern void ScalerMeasureUpdateInputTimingPolarity(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort, StructMeasureSyncData *pstMeasureSyncHV);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern bit ScalerMeasureCheckInterlaceVst(WORD usVstart, WORD usVend);
extern void ScalerMeasureCheckFirstLineShift(EnumSourceSearchPort enumSourceSearchPort, WORD usFrameHwidth);
extern bit ScalerMeasureCheckTmdsDeOnlyTiming(StructMeasureSyncData *pstMeasureSyncHV, WORD usIVFreq);
#endif

extern void ScalerMeasureInterlaceInitial(BYTE ucSourceType, EnumSourceSearchPort enumSourceSearchPort);
extern bit ScalerMeasureInterlaceCheck(BYTE ucSourceType, EnumSourceSearchPort enumSourceSearchPort);
