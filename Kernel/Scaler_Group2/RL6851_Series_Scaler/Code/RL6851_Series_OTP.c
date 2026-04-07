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
// ID Code      : RL6851_Series_OTP.c No.0000
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
StructOTPMapping g_pstOTPMappingData[] =
{
    {_OTPMEMORY_CHECK_EMPTY,              _HW_OTPFUSE_CHECK_EMPTY_STR,               _HW_OTPFUSE_CHECK_EMPTY_LEN},
    {_OTPMEMORY_HDCP14_RXKEYBKSV,         _HW_OTPFUSE_HDCP14_RXKEYBKSV_STR,          _HW_OTPFUSE_HDCP14_RXKEYBKSV_LEN},
    {_OTPMEMORY_HDCP14_RXKEY,             _HW_OTPFUSE_HDCP14_RXKEY_STR,              _HW_OTPFUSE_HDCP14_RXKEY_LEN},
    {_OTPMEMORY_LVDS_IBHN,                _HW_OTPFUSE_LVDS_IBHN_STR,                 _HW_OTPFUSE_LVDS_IBHN_LEN},
    {_OTPMEMORY_HVS,                      _HW_OTPFUSE_HVS_STR,                       _HW_OTPFUSE_HVS_LEN},
    {_OTPMEMORY_DP_AUX_RX_MODE,           _HW_OTPFUSE_DP_AUX_RX_MODE_STR,            _HW_OTPFUSE_DP_AUX_RX_MODE_LEN},
    {_OTPMEMORY_EDP_AUX_TX_MODE,          _HW_OTPFUSE_EDP_AUX_TX_MODE_STR,           _HW_OTPFUSE_EDP_AUX_TX_MODE_LEN},
    {_OTPMEMORY_VCCK_LDO,                 _HW_OTPFUSE_VCCK_LDO_STR,                  _HW_OTPFUSE_VCCK_LDO_LEN},
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOTPBankRead(BYTE ucOTPfuseBankBitMode, WORD usOTPfuseBankStrAddr, WORD usLength, BYTE *pucOTPfuseData);
void ScalerOTPGetData(WORD usStrAddr, WORD usLength, BYTE *pucOTPfuseData);
bit ScalerOTPFuseReadData(EnumOTPMemoryData enumOTPMemoryData, BYTE *pucOTPfuseGetData);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//----------------------------------------------------------------------------------------------------
// Description  :  ScalerOTPBankRead
// Input Value  :  ucOTPfuseBankBitMode, usOTPfuseBankStrAddr, usLength, *pucOTPfuseData
// Output Value  :  None
//----------------------------------------------------------------------------------------------------
void ScalerOTPBankRead(BYTE ucOTPfuseBankBitMode, WORD usOTPfuseBankStrAddr, WORD usLength, BYTE *pucOTPfuseData)
{
    WORD usOTPfuseAddraSet = 0;
    WORD usi = 0;

    // Debug
    DebugMessageDigital("8. ucOTPfuseBankBitMode", ucOTPfuseBankBitMode);
    DebugMessageDigital("8. usOTPfuseBankStrAddr", usOTPfuseBankStrAddr);
    DebugMessageDigital("8. usLength", usLength);

    // Turn on PLDO
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x14);
    // wait Tpls(10us)
    DELAY_15US();

    // Turn off Deep Standby
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x10);
    // Waiting Tsas(2us)
    DELAY_5US();

    // Turn on PTRIM
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x11);
    // Wait Ttas(50us)
    DELAY_XUS(50);

    // Enable Gated Clock & HW mode.
    ScalerSetByte(P24_A6_OTP_HW_CTRL_0, 0x02);

    // Waiting Tsas(2us)
    DELAY_5US();

    // Set READ mode
    ScalerSetByte(P24_A9_OTP_HW_CTRL_3, 0x00);

    // Disable Gated Clock & HW mode.
    ScalerSetByte(P24_A6_OTP_HW_CTRL_0, 0x00);

    // Waiting Tcs(10us)
    DELAY_15US();

    // Set Div28 for 1us counter (IOSC_28)(0991_IOSC_27)
    ScalerSetByte(P24_AC_OTP_CLK_CTRL, 0x1C);

    if(ucOTPfuseBankBitMode == _HW_OTPFUSE_8BIT)
    {
        DebugMessageDigital("8. OTP fuse 8b mode ***", _HW_OTPFUSE_8BIT);

        for(usi = 0; usi < usLength; usi++) // load one byte one time
        {
            usOTPfuseAddraSet = (usOTPfuseBankStrAddr + usi);

            // Set Read Addr_A
            ScalerSetByte(P24_A1_OTP_ADDR_INPUT_L, LOBYTE(usOTPfuseAddraSet));
            ScalerSetByte(P24_A2_OTP_ADDR_INPUT_H, HIBYTE(usOTPfuseAddraSet));

            // Read Enable
            ScalerSetBit(P24_A8_OTP_HW_CTRL_2, ~(_BIT0), _BIT0);

            // Wait more 111ns to avoid Tcsp violation
            pData[0] = 30;
            while((ScalerGetBit(P24_A8_OTP_HW_CTRL_2, _BIT0) != 0x00) && (pData[0] > 0))
            {
                DELAY_5US();
                pData[0] = pData[0] - 1;
            }

            pucOTPfuseData[usi] = ScalerGetByte (P24_A5_OTP_PDOUT);

            // Debug
            DebugMessageDigital("8. OTP fuse Addr_A lo Byte", ScalerGetByte(P24_A1_OTP_ADDR_INPUT_L));
            DebugMessageDigital("8. OTP fuse Addr_A hi Byte", ScalerGetByte(P24_A2_OTP_ADDR_INPUT_H));
            DebugMessageDigital("8. OTP fuse Byte", ScalerGetByte(P24_A5_OTP_PDOUT));
            DebugMessageDigital("8. OTP fuse Cnt usi = ", usi);
            DebugMessageDigital("8. pucOTPfuseData[usi]", pucOTPfuseData[usi]);
            DebugMessageDigital("8. *************", 0);
        }
    }
    else
    {
        // Debug
        DebugMessageDigital("8. OTP fuse other Bit mode ***", 0);
    }

    // Enable Gated Clock & HW mode.
    ScalerSetByte(P24_A6_OTP_HW_CTRL_0, 0x02);

    // Turn off PTRIM
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x10);
    // Wait Tash(10ns)
    DELAY_5US();

    // Turn on Deep Standby
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x14);

    // Turn off PLDO
    ScalerSetByte(P24_A7_OTP_HW_CTRL_1, 0x04);
}


//--------------------------------------------------
// Description  : ScalerOTPGetData
// Input Value  : usStrAddr, usLength, pucOTPfuseData
// Output Value : None
//--------------------------------------------------
void ScalerOTPGetData(WORD usStrAddr, WORD usLength, BYTE *pucOTPfuseData)
{
    WORD usOTPfuseBankRdStrAddr = 0;
    WORD usOTPfuseRdLength = 0;
    WORD usOTPfuseRdLengthAcc = 0;
    BYTE uci = 0;
    WORD usCurrStart = 0;
    WORD usCurrEnd = 0;

    BYTE code tOTPFUSE_BITMODE_OF_BANK[] =
    {
        _HW_OTPFUSE_8BIT,
    };

    WORD code tOTPFUSE_STRADDR_OF_BANK[] =
    {
        0,
    };

    WORD code tOTPFUSE_ENDADDR_OF_BANK[] =
    {
        4095,
    };


    if(usLength != 0x00)
    {
        for(uci = 0; uci < _HW_OTPFUSE_TOTAL_BANK_NUM; uci++)
        {
            usCurrStart = tOTPFUSE_STRADDR_OF_BANK[uci];
            usCurrEnd = tOTPFUSE_ENDADDR_OF_BANK[uci];

            if((usStrAddr <= usCurrStart) && ((usStrAddr + usLength - 1) >= usCurrStart)) // start adress is the start of a bank
            {
                usOTPfuseBankRdStrAddr = 0x00;
            }
            else if((usCurrStart < usStrAddr) && (usStrAddr <= usCurrEnd)) // start adress is within the bank
            {
                usOTPfuseBankRdStrAddr = (usStrAddr - usCurrStart);
            }
            else
            {
                usOTPfuseBankRdStrAddr = 0x00; // no need to read within this bank
            }

            if((usStrAddr <= usCurrEnd) && ((usStrAddr + usLength - 1) >= usCurrEnd)) // end adress is at the last of a bank
            {
                usOTPfuseRdLength = (usCurrEnd - usCurrStart - usOTPfuseBankRdStrAddr + 1);
            }
            else if((usCurrStart <= (usStrAddr + usLength - 1)) && ((usStrAddr + usLength - 1) < usCurrEnd))
            {
                usOTPfuseRdLength = ((usStrAddr + usLength - 1) - usCurrStart - usOTPfuseBankRdStrAddr + 1); // end adress is within the bank
            }
            else
            {
                usOTPfuseRdLength = 0x00; // no need to read within this bank
            }

            if(usOTPfuseRdLength != 0x00)
            {
                ScalerOTPBankRead(tOTPFUSE_BITMODE_OF_BANK[uci], usOTPfuseBankRdStrAddr, usOTPfuseRdLength, &pucOTPfuseData[usOTPfuseRdLengthAcc]);
            }

            usOTPfuseRdLengthAcc = usOTPfuseRdLengthAcc + usOTPfuseRdLength;

            if(usOTPfuseRdLengthAcc >= usLength)
            {
                break;
            }
        }
    }
}


//--------------------------------------------------
// Description  : ScalerOTPFuseReadData
// Input Value  : enumOTPMemoryData, pucOTPfuseData
// Output Value : _SUCCESS, _FAIL
//--------------------------------------------------
bit ScalerOTPFuseReadData(EnumOTPMemoryData enumOTPMemoryData, BYTE *pucOTPfuseGetData)
{
    WORD usIndex = 0;

    for(usIndex = 0; usIndex < (sizeof(g_pstOTPMappingData) / sizeof(StructOTPMapping)); ++usIndex)
    {
        if(g_pstOTPMappingData[usIndex].enumDataId == enumOTPMemoryData)
        {
            ScalerOTPGetData(g_pstOTPMappingData[usIndex].usAddress,
                             g_pstOTPMappingData[usIndex].usLength,
                             pucOTPfuseGetData);
            return _SUCCESS;
        }
    }
    return _FAIL;
}
