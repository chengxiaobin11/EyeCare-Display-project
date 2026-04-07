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
// ID Code      : ScalerCommonUSB3RetimerCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_USB3_RETIMER_INITIAL()               (g_b1Usb3SetInitial)
#define SET_USB3_RETIMER_INITIAL()               (g_b1Usb3SetInitial = _TRUE)
#define CLR_USB3_RETIMER_INITIAL()               (g_b1Usb3SetInitial = _FALSE)
#define GET_USB3_RETIMER_ENABLE()                (g_b1Usb3SetEnable)
#define SET_USB3_RETIMER_ENABLE()                (g_b1Usb3SetEnable = _TRUE)
#define CLR_USB3_RETIMER_ENABLE()                (g_b1Usb3SetEnable = _FALSE)
#define GET_USB3_DISABLE_BY_PINASS_C_E()         (g_b1Usb3DisableByPinAssCE)
#define SET_USB3_DISABLE_BY_PINASS_C_E()         (g_b1Usb3DisableByPinAssCE = _TRUE)
#define CLR_USB3_DISABLE_BY_PINASS_C_E()         (g_b1Usb3DisableByPinAssCE = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_b1Usb3SetInitial;
extern bit g_b1Usb3SetEnable;
extern bit g_b1Usb3DisableByPinAssCE;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerUSB3RetimerDisable_EXINT0(void);
extern void ScalerUSB3RetimerSetPdNoResponse(void);
extern void ScalerUSB3RetimerSetPdNoResponse_EXINT0(void);