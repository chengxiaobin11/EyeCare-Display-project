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
// ID Code      : RL6851_Series_OsdEnableDisable.c
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
void ScalerOsdEnableOsd(void);
void ScalerOsdDisableOsd(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable Display OSD
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerOsdEnableOsd(void)
{
    ScalerOsdCircuitActivated(_ENABLE);

    // OSD Overlay Port Enable
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Disable Display OSD
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerOsdDisableOsd(void)
{
    // OSD Overlay Port Enable
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT0, 0x00);
}

