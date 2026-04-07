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
// ID Code      : RL6851_Series_OsdVerticalStartSelect.c
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
void ScalerOsdVerticalStartSelect(EnumOsdVsyncSelectType enumOsdVsyncSelectType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Osd vertical start input signal source select
// Input Value  : enumOsdVsyncSelectType ->  _OSD_VSYNC_SELECT_DVS or _OSD_VSYNC_SELECT_ENA
// Output Value :
//--------------------------------------------------
void ScalerOsdVerticalStartSelect(EnumOsdVsyncSelectType enumOsdVsyncSelectType)
{
    ScalerSetBit(P3A_09_FRAME_CTRL_09, ~_BIT4, (enumOsdVsyncSelectType << 4));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_ENA);
*/
