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
// ID Code      : RL6851_Series_OsdHorizontalDelayStep.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerOSDLibInternalInclude.h"

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
void ScalerOsdHorizontalDelayStep(EnumOsdHorizontalDelayStepType enumOsdHorizontalDelayStepType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set osd position
// Input Value  : enumOsdHorizontalDelayStepType -> _OSD_HORIZONTAL_DELAY_STEP_4_PIXEL or _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL
// Output Value :
//--------------------------------------------------
void ScalerOsdHorizontalDelayStep(EnumOsdHorizontalDelayStepType enumOsdHorizontalDelayStepType)
{
    ScalerSetBit(P3A_06_FRAME_CTRL_06, ~_BIT4, (enumOsdHorizontalDelayStepType << 4));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdHorizontalDelayStep(_OSD_HORIZONTAL_DELAY_STRP_1_PIXEL);
*/
