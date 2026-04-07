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
// ID Code      : RL6410_Series_MDomainLibInterface.h No.0000
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
#if(_PIXEL_SHIFT_SUPPORT == _ON)
extern void ScalerMDomainSetDisplayTimingGenBackgroundVStart(BYTE ucBGVStart_H, BYTE ucBGVStart_L, EnumDBApply enumDBApply);
extern WORD ScalerMDomainGetDisplayTimingGenBackgroundVStart(void);
extern void ScalerMDomainSetDisplayTimingGenBackgroundVEnd(BYTE ucBGVEnd_H, BYTE ucBGVEnd_L, EnumDBApply enumDBApply);
extern WORD ScalerMDomainGetDisplayTimingGenBackgroundVEnd(void);
extern void ScalerMDomainSetDisplayTimingGenActiveRegionHStart(BYTE ucActHStart_H, BYTE ucActHStart_L, EnumDBApply enumDBApply);
extern WORD ScalerMDomainGetDisplayTimingGenActiveRegionHStart(void);
extern WORD ScalerMDomainGetDisplayTimingGenActiveRegionHEnd(void);
extern void ScalerMDomainSetDisplayTimingGenActiveRegionVStart(BYTE ucActHStart_H, BYTE ucActHStart_L, EnumDBApply enumDBApply);
extern WORD ScalerMDomainGetDisplayTimingGenActiveRegionVStart(void);
extern WORD ScalerMDomainGetDisplayTimingGenActiveRegionVEnd(void);
extern void ScalerMDomainSetCaptureWindowEnable(bit bCapWinEnable);
extern void ScalerMDomainSetCaptureWindowHStart(BYTE ucCapWinHStart_H, BYTE ucCapWinHStart_L);
extern WORD ScalerMDomainGetCaptureWindowHStart(void);
extern void ScalerMDomainSetCaptureWindowHEnd(BYTE ucCapWinHEnd_H, BYTE ucCapWinHEnd_L);
extern WORD ScalerMDomainGetCaptureWindowHEnd(void);
extern void ScalerMDomainSetCaptureWindowVStart(BYTE ucCapWinVStart_H, BYTE ucCapWinVStart_L);
extern WORD ScalerMDomainGetCaptureWindowVStart(void);
extern void ScalerMDomainSetCaptureWindowVEnd(BYTE ucCapWinVEnd_H, BYTE ucCapWinVEnd_L);
#endif

