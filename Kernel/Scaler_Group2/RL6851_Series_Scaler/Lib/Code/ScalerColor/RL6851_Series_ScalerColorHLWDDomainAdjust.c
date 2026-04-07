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
// ID Code      : RL6851_Series_ScalerColorHLWDDomainAdjust.c
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
void ScalerColorHLWDDomainAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust highlight window region
// Input Value  : usHPos, usHWidth, usVPos, usVHeight
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWDDomainAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight)
{
    if((usHWidth == 0) || (usVHeight == 0))
    {
        return;
    }

    // HLW Without Double Buffer, Wait for DEN Stop
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_00_HLW_HOR_START_H, (BYTE)((usHPos >> 8) & 0x1F));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_01_HLW_HOR_START_L, (BYTE)(usHPos & 0xFF));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_02_HLW_HOR_END_H, (BYTE)(((usHPos + usHWidth) >> 8) & 0x1F));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_03_HLW_HOR_END_L, (BYTE)((usHPos + usHWidth) & 0xFF));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_04_HLW_VER_START_H, (BYTE)((usVPos >> 8) & 0x1F));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_05_HLW_VER_START_L, (BYTE)(usVPos & 0xFF));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_06_HLW_VER_END_H, (BYTE)(((usVPos + usVHeight) >> 8) & 0x1F));
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_07_HLW_VER_END_L, (BYTE)((usVPos + usVHeight) & 0xFF));
}
