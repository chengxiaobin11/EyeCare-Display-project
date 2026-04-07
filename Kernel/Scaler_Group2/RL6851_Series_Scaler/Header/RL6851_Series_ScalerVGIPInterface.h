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
// ID Code      : RL6851_Series_ScalerVGIPInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern WORD ScalerVgipGetCaptureVStartPosition(void);
extern WORD ScalerVgipGetCaptureVHeight(void);
extern WORD ScalerVgipGetCaptureVDelay(void);
extern void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);
extern WORD ScalerVgipGetCaptureHStartPosition(void);

#if(_OVERSCAN_SUPPORT == _ON)
extern WORD ScalerVgipGetCaptureHWidth(void);
#endif

extern WORD ScalerVgipGetCaptureHDelay(void);
extern void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);

extern bit ScalerVgipGetDigitalCaptureStatus(void);



