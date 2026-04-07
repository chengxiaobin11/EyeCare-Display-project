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
// ID Code      : RL6369_Series_ColorDCRAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6369_Series_ColorLibInternalInclude.h"

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
void ScalerColorDCRAdjust(WORD usThreshold1, WORD usThreshold2, EnumDCRMeasureSel enumDCRMeasureSel);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set DCR TH1 & TH2
// Input Value  : TH1 & TH2, EnumDCRMeasureSel, bDCRSource
// Output Value : None
//--------------------------------------------------
void ScalerColorDCRAdjust(WORD usThreshold1, WORD usThreshold2, EnumDCRMeasureSel enumDCRMeasureSel)
{
    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_00_DCR_THESHOLD1_1 << 2) | _BIT0);
    ScalerSetByte(P7_D9_DCR_DATA_PORT, (BYTE)(usThreshold1 & 0xFF));
    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_01_DCR_THESHOLD2_1 << 2) | _BIT0);
    ScalerSetByte(P7_D9_DCR_DATA_PORT, (BYTE)(usThreshold2 & 0xFF));

    ScalerSetBit(P7_DA_DCR_CTRL, ~(_BIT3 | _BIT2 | _BIT1), (enumDCRMeasureSel << 1));
}

