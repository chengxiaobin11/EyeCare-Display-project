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
// ID Code      : RL6851_Series_ScalerSyncProcInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_VGA_SUPPORT == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Definitions of ADC Clock Limit
//--------------------------------------------------
#define GET_ADC_LIMIT_CLOCK()                          (g_usAdcClockLimit)


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern WORD g_usAdcClockLimit;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerSyncProcScanInitial(void);
extern bit ScalerSyncProcPreDetect(BYTE ucInputPort);
extern bit ScalerSyncProcStableDetect(void);
extern bit ScalerSyncProcGetSyncPad(void);
extern bit ScalerSyncProcIsSeparate(void);
extern BYTE ScalerSyncProcTypeAutoRun(void);
extern bit ScalerSyncProcAdcClkInitial(void);
extern bit ScalerSyncProcAdcClkSetting(void);
extern void ScalerSyncProcClampPosCheck(BYTE ucVideoModeFlg);
extern void ScalerSyncProcClearSyncChangeStatus(void);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
extern void ScalerSyncProcSetPorchVoltage(void);
#endif

extern DWORD ScalerSyncProcGetCurrentClockFreq(void);

#endif // #if(_VGA_SUPPORT == _ON)

