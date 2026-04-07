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
// ID Code      : RL6369_Series_TconLibInterface.h No.0000
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
extern void ScalerTcon7Enable(bit bEnable);
extern void ScalerTcon7Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon8Enable(bit bEnable);
extern void ScalerTcon8Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon9Enable(bit bEnable);
extern void ScalerTcon9Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon11Enable(bit bEnable);
extern void ScalerTcon11Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon12Enable(bit bEnable);
extern void ScalerTcon12Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon13Enable(bit bEnable);
extern void ScalerTcon13Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);
extern void ScalerTcon7InvEnable(bit bEnable);
extern void ScalerTcon8InvEnable(bit bEnable);
extern void ScalerTcon9InvEnable(bit bEnable);
extern void ScalerTcon11InvEnable(bit bEnable);
extern void ScalerTcon12InvEnable(bit bEnable);
extern void ScalerTcon13InvEnable(bit bEnable);
