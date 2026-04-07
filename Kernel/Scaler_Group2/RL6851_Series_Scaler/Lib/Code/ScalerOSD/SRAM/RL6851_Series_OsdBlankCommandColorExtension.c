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
// ID Code      : RL6851_Series_OsdBlankCommandColorExtension.c
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
void ScalerOsdBlankCommandColorExtension(bit bEnable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD blank command color extension enable/disable
// Input Value  : bEnable   -> _ENABLE or _DISABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdBlankCommandColorExtension(bit bEnable)
{
    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~(_BIT5), ((BYTE)(~bEnable) << 5));
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdBlankCommandColorExtension(_ENABLE);
    ScalerOsdBlankFont(ROW(0), COL(0), LENGTH(1), HEIGHT(1), VALUES(72), BGCOLOR(17), _OSD_BLINKING_EFFECT_DISABLE);

*/
