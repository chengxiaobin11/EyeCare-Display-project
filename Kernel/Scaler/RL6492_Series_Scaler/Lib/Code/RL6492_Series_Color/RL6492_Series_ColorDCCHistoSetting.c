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
// ID Code      : RL6492_Series_ColorDCCHistoSetting.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of DCC Histogram
//--------------------------------------------------
#define _DCC_HISTO_YMAX_LB                    0x00
#define _DCC_HISTO_YMIN_HB                    0x3FF

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
void ScalerColorDCCHistoSetting(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Y_MAX_LB, Y_MIN_HB
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCHistoSetting(void)
{
    // Set Y max lower bound and Y min higher bound
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_07_PORT_PAGE0_Y_MAX_LB_H);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, (BYTE)(_DCC_HISTO_YMAX_LB >> 2));
    ScalerSetByte(P7_CA_DCC_DATA_PORT, (BYTE)(_DCC_HISTO_YMIN_HB >> 2));
    ScalerSetByte(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_1A_PORT_PAGE0_Y_MAX_LB_L);
    ScalerSetByte(P7_CA_DCC_DATA_PORT, (BYTE)(_DCC_HISTO_YMAX_LB & (_BIT1 | _BIT0)));
    ScalerSetByte(P7_CA_DCC_DATA_PORT, (BYTE)(_DCC_HISTO_YMIN_HB & (_BIT1 | _BIT0)));

    // Enable DCC
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~_BIT7, _BIT7);
}
