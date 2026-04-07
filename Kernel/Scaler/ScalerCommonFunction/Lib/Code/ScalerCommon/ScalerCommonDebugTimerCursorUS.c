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

#include "ScalerCommonLibInternalInclude.h"

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerCommonDebugTimerCursorUS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructTimerSampleUS g_pstTimerCursorUS[_DEBUG_TIME_CURSOR_END];
BYTE g_ucTimerCursorUsedUS;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
WORD ScalerDebugGetTimerCursorUSDifference(EnumDebugTimeCursor enumIndex);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Time Cursor Difference for US
// Input Value  : Debug Time Cursor
// Output Value : Time Difference for Us
//--------------------------------------------------
WORD ScalerDebugGetTimerCursorUSDifference(EnumDebugTimeCursor enumIndex)
{
    // Check if cursor is used
    if(((g_ucTimerCursorUsedUS >> enumIndex) & _BIT0) == _DISABLE)
    {
        return 0xFFFF;
    }
    else
    {
        // Calculate timter counter difference
        WORD usStartTimeUS = g_pstTimerCursorUS[enumIndex].ucTH_Start * 0x100 + g_pstTimerCursorUS[enumIndex].ucTL_Start;
        WORD usEndTimeUS = g_pstTimerCursorUS[enumIndex].ucTH_End * 0x100 + g_pstTimerCursorUS[enumIndex].ucTL_End;

        if(usStartTimeUS <= usEndTimeUS)
        {
            // Convert to us
            WORD usRCAP2 = g_pstTimerCursorUS[enumIndex].ucRCAP2H * 0x100 + g_pstTimerCursorUS[enumIndex].ucRCAP2L;
            return (WORD)((DWORD)(usEndTimeUS - usStartTimeUS) * 1000 / (0xFFFF - usRCAP2));
        }
        else
        {
            return 0xFFFF;
        }
    }
}

