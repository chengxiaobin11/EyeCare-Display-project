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
// ID Code      : RL6369_Series_ColorOutputGammaWriteTable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6369_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GAMMA_WRITE_TO_SRAM                    0
#define _GAMMA_WRITE_TO_LATCH                   1

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
void ScalerColorOutputGammaWriteTable(BYTE *pucGammaTableArray, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust output gamma by selecting Channel/Offset/Length
// Input Value  :
// Output Value : None
//--------------------------------------------------
void ScalerColorOutputGammaWriteTable(BYTE *pucGammaTableArray, EnumGammaChannel enumGammaChannel, BYTE ucOffset, WORD usDataLength)
{
    // Enable Gamma access
    ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~_BIT7, _BIT7);

    // Set Gamma Channel
    ScalerColorOutputGammaChannelCtrl(enumGammaChannel, ucOffset, _GAMMA_WRITE_TO_SRAM);

    // Write Gamma LUT
    ScalerWrite(P0_66_GAMMA_PORT_SETA, usDataLength, pucGammaTableArray, _NON_AUTOINC);

    // Disable Port Access
    ScalerSetBit(P0_67_GAMMA_CTRL_SETA, ~_BIT7, 0x00);
}
