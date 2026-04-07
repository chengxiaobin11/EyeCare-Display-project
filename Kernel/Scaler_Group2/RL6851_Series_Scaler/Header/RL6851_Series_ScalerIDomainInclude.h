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
// ID Code      : RL6851_Series_ScalerIDomainInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_VGIP_INITIAL_VDELAY()                   (g_usVgipVDelayInitial)
#define SET_VGIP_INITIAL_VDELAY(x)                  (g_usVgipVDelayInitial = (x))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern WORD g_usVgipVDelayInitial;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern WORD ScalerIDomainVgipIHCaptureMaxEstimate(WORD usHPosition);
extern void ScalerIDomainVgipAdjustIHVDelay(void);
extern void ScalerIDomainFineTuneHCaptureStart(WORD usDeltaIHCapture);
extern void ScalerIDomainScalingDownInitial(void);

