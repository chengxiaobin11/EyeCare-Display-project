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
// ID Code      : RL6410_Series_DualLinkDVI.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

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
#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
bit ScalerDualLinkDVIRx4GetDualDVIMode(void);
BYTE ScalerDualLinkDVIRx4GetDualDVIMode_EXINT0(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : Get Whehter Current Mode is Dual DVI Mode
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDualLinkDVIRx4GetDualDVIMode(void)
{
    return (ScalerGetBit(P31_03_FC_DUAL_DVI_CTRL1, _BIT7) == _BIT7);
}

//--------------------------------------------------
// Description  : Get Whehter Current Mode is Dual DVI Mode in Interupt
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
BYTE ScalerDualLinkDVIRx4GetDualDVIMode_EXINT0(void) using 1
{
    return (ScalerGetBit_EXINT(P31_03_FC_DUAL_DVI_CTRL1, _BIT7) == _BIT7);
}
#endif
