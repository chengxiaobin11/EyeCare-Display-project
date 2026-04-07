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
// ID Code      : ScalerCommonRegInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if((_DEBUG_MESSAGE_SUPPORT == _ON) || (_FACTORY_DEBUG_SUPPORT == _ON))
#define ScalerSetBit(usAddr, ucAnd, ucOr)           (*((volatile BYTE xdata *)(usAddr)) = (*((volatile BYTE xdata *)(usAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit(usAddr, ucAnd)                 (*((volatile BYTE xdata *)(usAddr)) & (ucAnd))
#define ScalerGetByte(usAddr)                       (*((volatile BYTE xdata *)(usAddr)))
#define ScalerSetByte(usAddr, ucValue)              (*((volatile BYTE xdata *)(usAddr)) = (ucValue))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************

