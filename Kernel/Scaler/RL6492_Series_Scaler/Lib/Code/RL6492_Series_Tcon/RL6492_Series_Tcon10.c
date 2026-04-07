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
// ID Code      : RL6492_Series_Tcon10.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_TconLibInternalInclude.h"

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
void ScalerTcon10Enable(bit bEnable);
void ScalerTcon10Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set Tcon10 local enable
// Input Value  : bEnable --> enable
// Output Value : None
//--------------------------------------------------
void ScalerTcon10Enable(bit bEnable)
{
    ScalerSetDataPortBit(P15_A3_TCON_ADDR, _P15_A4_PT_B8_TC10_CTRL, ~(_BIT7), ((BYTE)bEnable << 7));
}

//--------------------------------------------------
// Description  : Set Tcon10 Region
// Input Value  : usHstart --> Horizon start
//                usHend --> Horizon end
//                usVstart --> Vertical start
//                usVend --> Vertical end
// Output Value : None
//--------------------------------------------------
void ScalerTcon10Adjust(WORD usHstart, WORD usHend, WORD usVstart, WORD usVend)
{
    usVstart &= 0x1FFF;
    usVend &= 0x1FFF;

    usHstart &= 0x1FFF;
    usHend &= 0x1FFF;

    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B0_TC10_VS_MSB, HIBYTE(usVstart));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B1_TC10_VS_LSB, LOBYTE(usVstart));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B2_TC10_VE_MSB, HIBYTE(usVend));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B3_TC10_VE_LSB, LOBYTE(usVend));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B4_TC10_HS_MSB, HIBYTE(usHstart));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B5_TC10_HS_LSB, LOBYTE(usHstart));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B6_TC10_HE_MSB, HIBYTE(usHend));
    ScalerSetDataPortByte(P15_A3_TCON_ADDR, _P15_A4_PT_B7_TC10_HE_LSB, LOBYTE(usHend));
}

