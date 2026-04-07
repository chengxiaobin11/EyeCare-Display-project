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
// ID Code      : RL6851_Series_ScalerDebugTimerCursorMS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerCommonLibInternalInclude.h"

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
StructTimerSampleMS g_pstTimerCursorMS[_DEBUG_TIME_CURSOR_END];
BYTE g_ucTimerCursorUsedMS;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
WORD ScalerDebugGetTimerCursorMSDifference(EnumDebugTimeCursor enumIndex);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Time Cursor Difference for MS
// Input Value  : Debug Time Cursor
// Output Value : Time Difference for Ms
//--------------------------------------------------
WORD ScalerDebugGetTimerCursorMSDifference(EnumDebugTimeCursor enumIndex)
{
    // Check if cursor is used
    if(((g_ucTimerCursorUsedMS >> enumIndex) & _BIT0) == _DISABLE)
    {
        return 0xFFFF;
    }
    else
    {
        // Calculate counter difference
        if(g_pstTimerCursorMS[enumIndex].usCounter_Start <= g_pstTimerCursorMS[enumIndex].usCounter_End)
        {
            return g_pstTimerCursorMS[enumIndex].usCounter_End - g_pstTimerCursorMS[enumIndex].usCounter_Start;
        }
        else
        {
            return 0xFFFF - g_pstTimerCursorMS[enumIndex].usCounter_Start + g_pstTimerCursorMS[enumIndex].usCounter_End;
        }
    }
}

