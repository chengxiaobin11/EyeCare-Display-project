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
// ID Code      : RL6851_Series_ScalerCommonRegCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of  Control Register Address
//--------------------------------------------------

//--------------------------------------------------
// Macros of controlling the scaler registers
//--------------------------------------------------
#define ScalerSetBit(usAddr, ucAnd, ucOr)           (*((volatile BYTE xdata *)(usAddr)) = (*((volatile BYTE xdata *)(usAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit(usAddr, ucAnd)                 (*((volatile BYTE xdata *)(usAddr)) & (ucAnd))
#define ScalerGetByte(usAddr)                       (*((volatile BYTE xdata *)(usAddr)))
#define ScalerSetByte(usAddr, ucValue)              (*((volatile BYTE xdata *)(usAddr)) = (ucValue))
#define ScalerGetWord(usAddr)                       (*((volatile WORD xdata *)(usAddr)))
#define ScalerSetWord(usAddr, usValue)              (*((volatile WORD xdata *)(usAddr)) = (usValue))
#define ScalerGetDWord(usAddr)                      (*((volatile DWORD xdata *)(usAddr)))
#define ScalerSetDWord(usAddr, ulValue)             (*((volatile DWORD xdata *)(usAddr)) = (ulValue))
#define ScalerMaskSetDWord(usAddr, ulMask, ulValue) (*((volatile DWORD xdata *)(usAddr)) = (((DWORD)(ulMask)) & ScalerGetDWord(usAddr)) | ((~((DWORD)(ulMask))) & (ulValue)))

//--------------------------------------------------
// Macros of controlling the scaler registers for EXINT1
//--------------------------------------------------
#define ScalerSetBit_EXINT(usAddr, ucAnd, ucOr)     (*((volatile BYTE xdata *)(usAddr)) = (*((volatile BYTE xdata *)(usAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit_EXINT(usAddr, ucAnd)           (*((volatile BYTE xdata *)(usAddr)) & (ucAnd))
#define ScalerGetByte_EXINT(usAddr)                 (*((volatile BYTE xdata *)(usAddr)))
#define ScalerSetByte_EXINT(usAddr, ucValue)        (*((volatile BYTE xdata *)(usAddr)) = (ucValue))
#define ScalerGetWord_EXINT(usAddr)                 (*((volatile WORD xdata *)(usAddr)))
#define ScalerSetWord_EXINT(usAddr, usValue)        (*((volatile WORD xdata *)(usAddr)) = (usValue))

//--------------------------------------------------
// Macros of controlling the scaler registers for EXINT3
//--------------------------------------------------
#define ScalerSetBit_EXINT3(usAddr, ucAnd, ucOr)    (*((volatile BYTE xdata *)(usAddr)) = (*((volatile BYTE xdata *)(usAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit_EXINT3(usAddr, ucAnd)          (*((volatile BYTE xdata *)(usAddr)) & (ucAnd))
#define ScalerGetByte_EXINT3(usAddr)                (*((volatile BYTE xdata *)(usAddr)))
#define ScalerSetByte_EXINT3(usAddr, ucValue)       (*((volatile BYTE xdata *)(usAddr)) = (ucValue))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

