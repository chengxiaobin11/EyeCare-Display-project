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
// ID Code      : RL6851_Series_OsdAlignMark.c
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
void ScalerOsdAlignMark(bit bEnableDisable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : bEnableDisable -> _ENABLE or _DISABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdAlignMark(bit bEnableDisable)
{
#if(_OSD_ALIGN_SUPPORT == _ON)
    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~(_BIT6), ((BYTE)(~bEnableDisable) << 6));
#else
    bEnableDisable = bEnableDisable;
#endif
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdAlignMark(_ENABLE);
*/

