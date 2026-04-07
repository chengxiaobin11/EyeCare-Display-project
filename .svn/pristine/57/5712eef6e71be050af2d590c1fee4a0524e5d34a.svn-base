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
// ID Code      : RL6851_Series_ScalerColorDigitalFilterNRingAdjust.c
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
void ScalerColorDigitalFilterNRingAdjust(BYTE ucTHD, BYTE ucDIV);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//-------------------------------------------------
// Description  : Set NRing
// Input Value  : THD,Div
// Output Value : None
//-------------------------------------------------
void ScalerColorDigitalFilterNRingAdjust(BYTE ucTHD, BYTE ucDIV)
{
    // Set negative ring  parameter
    ScalerSetBit(P0_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), _BIT6);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT, ((ucTHD << 4) | (ucDIV << 2) | _BIT7));
}
