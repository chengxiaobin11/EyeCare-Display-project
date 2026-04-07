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
// ID Code      : ScalerCommonTimerPollingDataBitFlagProc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerCommonLibInternalInclude.h"

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
bit ScalerTimerPollingDataBitFlagProc(WORD usTimeout, WORD usRegister, BYTE ucValue, BYTE ucBit, bit bSuccess);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//----------------------------------------------------------------------
// Description  : Polling Scaler Flag Process
// Input Value  : ucTimeout --> Timeout number (Max: 255 ms)
//                ucRegister--> Current Register
//                ucBit     --> Polling Bit
//                bSuccess  --> 1 or 0 when finished for Polling Bit
// Output Value : Return _TRUE while polling success, _FALSE for timeout
//----------------------------------------------------------------------
bit ScalerTimerPollingDataBitFlagProc(WORD usTimeout, WORD usRegister, BYTE ucValue, BYTE ucBit, bit bSuccess)
{
    WORD usTimeElapsed = 0;
    WORD usPreviousTime = 0;

    usPreviousTime = g_usTimerCounter;

    do
    {
        if(((bit)ScalerGetDataPortBit(usRegister, ucValue, ucBit) ^ bSuccess) == _FALSE)
        {
            return _TRUE;
        }

        if(usPreviousTime != g_usTimerCounter)
        {
            usTimeElapsed++;
            usPreviousTime = g_usTimerCounter;
        }
    }
    while(usTimeElapsed <= usTimeout);

    return _FALSE;
}

