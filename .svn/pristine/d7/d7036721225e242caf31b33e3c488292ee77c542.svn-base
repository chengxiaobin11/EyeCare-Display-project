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
// ID Code      : RL6369_Series_ColorOutputGammaChannelCtrl.c
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
void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, WORD usOffset, bit bLocation);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Switch Gamma Channel
// Input Value  : ucColorChannel: 0- Red, 1- Green, 2- Blue;
//                ucOffset: Offset
//                bLocation: 0-Write to SDRAM, 1- Write to LATCH
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGammaChannelCtrl(BYTE ucColorChannel, WORD usOffset, bit bLocation)
{
    // Select Channel
    ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~(_BIT7 | _BIT5 | _BIT4 | _BIT2), ((ucColorChannel << 4) | ((BYTE)bLocation << 2)));

    // Specify address
    ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~_BIT3, _BIT3);
    ScalerSetByte(P0_66_GAMMA_PORT_SETA, LOBYTE(usOffset));
    ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~(_BIT7 | _BIT3), _BIT7);
}

