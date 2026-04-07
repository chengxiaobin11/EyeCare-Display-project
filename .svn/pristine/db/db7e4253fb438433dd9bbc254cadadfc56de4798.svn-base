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
// ID Code      : RL6851_Series_OsdFontMaskOnOff.c
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
void ScalerOsdFontMaskOnOff(EnumOsdMapType enumOsdMapType, bit bOnOff);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : MASK Specific Region of Font A/B Enable/Disable
// Input Value  : bOnOff
// Output Value :
//--------------------------------------------------
void ScalerOsdFontMaskOnOff(EnumOsdMapType enumOsdMapType, bit bOnOff)
{
    if(enumOsdMapType == _OSD_A)
    {
        ScalerSetBit(P3A_45_FRAME_CTRL_45, ~_BIT7, ((BYTE)bOnOff << 7));
    }
    else
    {
        ScalerSetBit(P3A_47_FRAME_CTRL_47, ~_BIT7, ((BYTE)bOnOff << 7));
    }
}

