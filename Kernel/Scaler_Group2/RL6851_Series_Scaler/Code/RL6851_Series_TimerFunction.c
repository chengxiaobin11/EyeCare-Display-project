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
// ID Code      : RL6851_Series_TimerFunction.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

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
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent);
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Clear Event Status
// Input Value  : enumEvent   --> Specified event
// Output Value : None
//--------------------------------------------------
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent)
{
    ScalerSetByte(P0_03_STATUS1, enumEvent);
}

//--------------------------------------------------
// Description  : Hold until the specified event occurs
// Input Value  : enumEvent   --> Specified event
// Output Value : Return _TRUE if event occurs
//--------------------------------------------------
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent)
{
    return (ScalerGetByte(P0_03_STATUS1) & enumEvent);
}

