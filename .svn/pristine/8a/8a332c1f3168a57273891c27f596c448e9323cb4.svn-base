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
// ID Code      : RL6492_Series_OsdFont24x36OnOff.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_OSDLibInternalInclude.h"

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
void ScalerOsdFont24x36OnOff(bit bOnOff);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Font 24x36 mode
// Input Value  : ucRowStart
// Input Value  : ucRowEnd
// Input Value  : ucColumnStart
// Input Value  : ucColumnEnd
// Output Value :
//--------------------------------------------------
void ScalerOsdFont24x36OnOff(bit bOnOff)
{
    ScalerSetBit(P3A_43_FRAME_CTRL_43, ~_BIT6, ((BYTE)bOnOff << 6));
}


