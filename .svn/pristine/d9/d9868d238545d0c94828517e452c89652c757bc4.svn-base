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
// ID Code      : RL6851_Series_DDomain.c No.0000
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

void ScalerDDomainBackgroundEnable(bit bEnable);
void ScalerDDomainBackgroundSetColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Display Force to Background Enable
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDDomainBackgroundEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable Force to Back Ground
        ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT5, _BIT5);
    }
    else
    {
        // Disable Force to Back Ground
        ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT5, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Display Background Color
// Input Value  : RGB Color
// Output Value : None
//--------------------------------------------------
void ScalerDDomainBackgroundSetColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    // Reset Port index
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT5, 0x00);
    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT5, _BIT5);

    // 8bits RGB color
    ScalerSetByte(P0_6D_BG_COLOR_DATA_PORT_M1, ucRed);
    ScalerSetByte(P0_6D_BG_COLOR_DATA_PORT_M1, ucGreen);
    ScalerSetByte(P0_6D_BG_COLOR_DATA_PORT_M1, ucBlue);

    ScalerSetBit(P0_6C_OVERLAY_CTRL, ~_BIT5, 0x00);
}

