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
// ID Code      : OsdGlobalDoubleBuffer.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerOSDLibInternalInclude.h"

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
void ScalerOsdGlobalDoubleBuffer(bit bEnableDisable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : bEnableDisable -> _ENABLE or _DISABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdGlobalDoubleBuffer(bit bEnableDisable)
{
    ScalerSetBit(P0_93_OSD_MISC_PORT, ~(_BIT7), ((BYTE)(bEnableDisable) << 7));
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdGlobalDoubleBuffer(_ENABLE);
*/

