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
// ID Code      : RL6851_Series_OsdReference4BitBackground.c
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
void ScalerReference4BitBackground(EnumOsd4BitBackgroundType enumOsd4BitBackgroundType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : EnumOsd4BitBackgroundType -> _OSD_4BIT_BACKGROUND_TO_BYTE2 or _OSD_4BIT_BACKGROUND_TO_BYTE0
// Output Value :
//--------------------------------------------------
void ScalerReference4BitBackground(EnumOsd4BitBackgroundType enumOsd4BitBackgroundType)
{
    ScalerSetBit(P3A_07_FRAME_CTRL_07, ~_BIT2, (enumOsd4BitBackgroundType << 2));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerReference4BitBackground(_OSD_4BIT_BACKGROUND_TO_BYTE0);
*/


