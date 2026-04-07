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
// ID Code      : RL6851_Series_ScalerVGATopInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Enumerations of VGATOP Waiting Events (P30_E4)
//--------------------------------------------------

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_VGA_SUPPORT == _ON)

#if(_VGA_CAPTURE_SUPPORT == _ON)
extern void ScalerVgaTopInputInitial(void);
#endif


extern void ScalerVgaTopSetCapture(void);
extern bit ScalerVgaTopModifyVsLatchEdge(bit bWait);
extern void ScalerVgaTopAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd);
extern void ScalerVgaTopAutoFuncVBoundInitial(WORD usVBoundStart, WORD usVBoundEnd);
extern bit ScalerVgaTopHWAutoPhaseSearch(EnumAutoPhaseSearchStep enumPhaseStep, BYTE *pucPhaseResult, DWORD *pulSODMax, DWORD *pulSODMin, EnumAutoPhaseSearchSODMethod enumSODMethod, BYTE ucSODThreshold);
extern bit ScalerVgaTopAutoPhaseGetSOD(DWORD *pulSODValue);
extern bit ScalerVgaTopMeasureActiveRegion(EnumMeasureFieldSelect enumFieldSelect, EnumMeasureBoundType enumBoundType, WORD usHTotal);

extern void ScalerVgaTopDoubleBufferApply(void);
extern void ScalerVgaTopDoubleBufferEnable(bit bEn);
extern WORD ScalerVgaTopGetCaptureVStartPosition(void);
extern void ScalerVgaTopSetCaptureVStartPosition(WORD usIVstart);
extern WORD ScalerVgaTopGetCaptureVHeight(void);
extern void ScalerVgaTopSetCaptureVHeight(WORD usIVheight);
extern WORD ScalerVgaTopGetCaptureVDelay(void);
extern void ScalerVgaTopSetCaptureVDelay(WORD usIVSDelay);
extern WORD ScalerVgaTopGetCaptureHStartPosition(void);
extern void ScalerVgaTopSetCaptureHStartPosition(WORD usIHstart);
extern WORD ScalerVgaTopGetCaptureHWidth(void);
extern void ScalerVgaTopSetCaptureHWidth(WORD usIHwidth);
extern void ScalerVgaTopSetCaptureHDelay(WORD usIHSDelay);
extern WORD ScalerVgaTopGetCaptureHDelay(void);

extern void ScalerVgaTopModifyHsLatchEdgeDelay(void);
#endif

