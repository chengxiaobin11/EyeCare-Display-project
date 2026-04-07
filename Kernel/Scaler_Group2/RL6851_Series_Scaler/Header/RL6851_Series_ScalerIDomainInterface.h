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
// ID Code      : RL6851_Series_ScalerIDomainInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macro of underscan info
//--------------------------------------------------
#define GET_UNDERSCAN_VHEIGHT()                       (g_usUnderScanIVheight)
#define SET_UNDERSCAN_VHEIGHT(x)                      (g_usUnderScanIVheight = (x))

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_UNDERSCAN_SUPPORT == _ON)
extern WORD g_usUnderScanIVheight;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerIDomainVgipSetInputCapture(void);
extern WORD ScalerIDomainVgipIHCaptureMaxEstimate(WORD usHPosition);

#if(_UNDERSCAN_SUPPORT == _ON)
extern WORD ScalerIDomainVgipGetVCaptureStartMinValue(void);
#endif
