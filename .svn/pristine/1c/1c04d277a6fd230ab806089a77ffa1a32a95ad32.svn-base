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
// ID Code      : RL6851_Series_OsdCircuitActivated.c
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
void ScalerOsdCircuitActivated(bit bEnable);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Activate OSD circuit enable disable
// Input Value  : bEnable      -> _ENABLE or _DISABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdCircuitActivated(bit bEnable)
{
    bit bBackup = _DISABLE;

    if(ScalerGetBit(P3A_02_FRAME_CTRL_02, _BIT0) == _BIT0)
    {
        if(bEnable == _ENABLE)
        {
            return;
        }
        bBackup = _ENABLE;
    }

    if(bEnable == _DISABLE)
    {
        // must be reset before disable osd circuit
        // [7:5] --> Set write byte : ALL
        // [3:2] --> Set address indicator : Window control register
        ScalerSetBit(P0_94_OSD_WRITE_OPTION, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), 0x00);
    }

    ScalerSetBit(P3A_02_FRAME_CTRL_02, ~(_BIT0), bEnable);

    if((bBackup == _DISABLE) && (bEnable == _ENABLE))
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
}
