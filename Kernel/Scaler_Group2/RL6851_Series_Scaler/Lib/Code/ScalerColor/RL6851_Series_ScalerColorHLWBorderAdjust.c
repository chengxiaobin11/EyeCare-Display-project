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
// ID Code      : RL6851_Series_ScalerColorHLWBorderAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

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
void ScalerColorHLWBorderAdjust(BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust HLW Border Width and Color
// Input Value  : ucBorderWidth, ucRed, ucGreen, ucBlue, enumDBApply
// Output Value : none
//--------------------------------------------------
void ScalerColorHLWBorderAdjust(BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    // set HLW's Border
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_08_HLW_BORDER_WIDTH, (ucBorderWidth & 0x1F));

    // border color is 10bits,  here still use 8bits
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_09_HLW_BORDER_RED, (ucRed & 0xFF));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_0A_HLW_BORDER_GRN, (ucGreen & 0xFF));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_0B_HLW_BORDER_BLU, (ucBlue & 0xFF));

    ScalerGlobalDDomainDBApply(_DB_APPLY_NO_POLLING);
}
