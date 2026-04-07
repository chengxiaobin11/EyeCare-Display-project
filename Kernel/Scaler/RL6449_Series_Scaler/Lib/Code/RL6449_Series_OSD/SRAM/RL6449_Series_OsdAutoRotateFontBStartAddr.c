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
// ID Code      : RL6449_Series_OsdAutoRotateFontBStartAddr.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_OSDLibInternalInclude.h"

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
void ScalerOsdAutoRotateFontBStartAddr(BYTE ucStartAddr);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : FONT_B LUT SRAM Start Address
// Input Value  : ucStartAddr --> Font B start address
// Output Value :
//--------------------------------------------------
void ScalerOsdAutoRotateFontBStartAddr(BYTE ucStartAddr)
{
    ScalerSetByte(P3A_42_FRAME_CTRL_42, ucStartAddr);
}

