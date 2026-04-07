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
// ID Code      : RL6851_Series_ScalerCommonMeasure.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_MEASURE__

#include "ScalerCommonFunctionInclude.h"

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
#if(_DIGITAL_PORT_SUPPORT == _ON)
void ScalerMeasureAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial H Boundary for Auto Function Measure
// Input Value  : H Boundary Start/End
// Output Value : None
//--------------------------------------------------
void ScalerMeasureAutoFuncHBoundInitial(WORD usHBoundStart, WORD usHBoundEnd)
{
    // Set H boundary
    ScalerSetByte(P0_70_H_BOUNDARY_H, (((HIBYTE(usHBoundStart) & 0x0F) << 4) | (HIBYTE(usHBoundEnd) & 0x0F)));
    ScalerSetByte(P0_71_H_BOUNDARY_STA_L, LOBYTE(usHBoundStart));
    ScalerSetByte(P0_72_H_BOUNDARY_END_L, LOBYTE(usHBoundEnd));

    ScalerSetBit(P0_77_GRN_NOISE_MARGIN, ~_BIT1, ((HIBYTE(usHBoundStart) >> 3) & _BIT1));
    ScalerSetBit(P0_77_GRN_NOISE_MARGIN, ~_BIT0, ((HIBYTE(usHBoundEnd) >> 4) & _BIT0));
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

