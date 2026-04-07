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
// ID Code      : RL6410_Series_DDR3.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
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
void ScalerDDR3SystemBridgeInitial(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : System Bridge initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDDR3SystemBridgeInitial(void)
{
    // Set IP arbitration enable
    // ------- Set PA4_03_SB_ARB_CR03 - _BIT6~_Bit0 -----
    // _BIT6: enable Main2 OD rd (R)
    // _BIT5: enable Main1 OD rd (R)
    // _BIT4: enable Sub2 Capture (W)
    // _BIT3: enable Rotate2 (W)
    // _BIT2: enable Main2 OD wr (W)
    // _BIT1: enable Sub1 Capture (W)
    // _BIT0: enable Sub2 Display (R)
    ScalerSetByte(PA4_03_SB_ARB_CR03, 0x7F);

    // ------- Set PA4_04_SB_ARB_CR04 -----
    // _BIT7: enable Sub1 Display (R)
    // _BIT6: enable Reserved_c6
    // _BIT5: enable Main2 Display (R)
    // _BIT4: enable Main1 Display (R)
    // _BIT3: enable Main1 OD wr (W)
    // _BIT2: enable Main2 Capture (W)
    // _BIT1: enable Main1 Capture (W)
    // _BIT0: enable Rotate1 (W)
    ScalerSetByte(PA4_04_SB_ARB_CR04, 0xFF);

    // ------- Set PA4_05_SB_ARB_CR05 - _BIT3~_Bit0 -----
    // _BIT3: enable Sub2 OD rd (R)
    // _BIT2: enable Sub2 OD wr (W)
    // _BIT1: enable Sub1 OD rd (R)
    // _BIT0: enable Sub1 OD wr (W)
    ScalerSetByte(PA4_05_SB_ARB_CR05, 0x0F);
}

#endif // End of #if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
