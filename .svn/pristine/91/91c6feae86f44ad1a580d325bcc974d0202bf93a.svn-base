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
// ID Code      : RL6851_Series_OsdPopOn.c
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
void ScalerOsdPopOn(bit bEnable, EnumOsdMapType enumOsdMapType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set 2 font OSD pop on function
// Input Value  : bEnable        -> _ENABLE or _DISABLE
//                enumOsdMapType -> _OSD_A or _OSD_B
// Output Value :
//--------------------------------------------------
void ScalerOsdPopOn(bit bEnable, EnumOsdMapType enumOsdMapType)
{
    ScalerSetBit(P3A_18_FRAME_CTRL_18, ~(_BIT7 | _BIT6 | _BIT0), (((BYTE)bEnable << 7) | _BIT6 | ((BYTE)enumOsdMapType)));
}

