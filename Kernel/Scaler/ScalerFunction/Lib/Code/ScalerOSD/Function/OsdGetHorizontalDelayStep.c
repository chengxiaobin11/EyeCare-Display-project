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
// ID Code      : OsdGetHorizontalDelayStep.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerOSDLibInternalInclude.h"

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
EnumOsdHorizontalDelayStepType ScalerOsdGetHorizontalDelayStep(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get OSD Horizontal Delay Step unit
// Input Value  :
// Output Value : _OSD_HORIZONTAL_DELAY_STEP_4_PIXEL or _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL
//--------------------------------------------------
EnumOsdHorizontalDelayStepType ScalerOsdGetHorizontalDelayStep(void)
{
    if(ScalerGetBit(P3A_06_FRAME_CTRL_06, _BIT4) == 0x00)
    {
        return _OSD_HORIZONTAL_DELAY_STEP_4_PIXEL;
    }
    else
    {
        return _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL;
    }
}

