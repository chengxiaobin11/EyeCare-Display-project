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
// ID Code      : RL6432_Series_DPTxMST.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_DP_TX_SUPPORT == _ON)
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
#if(_DP_MST_SUPPORT == _ON)
void ScalerDpTxMstLinkClockEn(bit bEn);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP MST Link Clock Enable or Disable
// Input Value  : bEn  --> _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpTxMstLinkClockEn(bit bEn)
{
    if(bEn == _ENABLE)
    {
        // Enable DP Tx Link Clock
        ScalerSetBit(PA_81_MST2SST_CLK_GATE, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
    }
    else
    {
        // Disable DP Tx Link Clock for Power Saving Mode
        ScalerSetBit(PA_81_MST2SST_CLK_GATE, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    }
}
#endif

#endif
