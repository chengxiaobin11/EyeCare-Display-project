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
// ID Code      : ScalerODLibInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _OD_PIXEL_PER_COMP                          4 // Number of pixels processed per compression
#define CEILING(x, y)                               (((x) % (y)) ? ((((x) / (y)) + 1) * (y)) : (x))
#define CEILING_OF_INT_DIVISION(x, y)               (((x) % (y)) ? (((x) / (y)) + 1) : ((x) / (y)))

#define GET_OD_USE_BIT()                            (g_ucMemoryODUseBit)
#define SET_OD_USE_BIT(x)                           (g_ucMemoryODUseBit = (x))
#define CLR_OD_USE_BIT()                            (g_ucMemoryODUseBit = 0)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucMemoryODUseBit;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerODCompressionSetting(void);
