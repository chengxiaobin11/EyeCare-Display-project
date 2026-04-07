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
// ID Code      : RL6851_Series_ScalerCommonLibInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define GET_DWORD_MUL_DIV(x, y, z)                        (ScalerComputeDwordMulDiv((x), (y), (z)))

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
extern StructTimerSampleMS g_pstTimerCursorMS[];
extern StructTimerSampleUS g_pstTimerCursorUS[];

extern BYTE g_ucTimerCursorUsedMS;
extern BYTE g_ucTimerCursorUsedUS;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern DWORD ScalerComputeDwordMulDiv(DWORD ulA, DWORD ulB, DWORD ulC);

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
extern WORD ScalerDebugGetTimerCursorMSDifference(EnumDebugTimeCursor enumIndex);
extern WORD ScalerDebugGetTimerCursorUSDifference(EnumDebugTimeCursor enumIndex);
#endif

