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
// ID Code      : UserCommonCec.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_CEC__

#include "UserCommonInclude.h"

#if(_HDMI_CEC_SUPPORT == _ON)

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
void UserCommonCecReceiveNotify(void);
void UserCommonCecTransmitInfoPrepare(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Received CEC RX INFO bypass to User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonCecReceiveNotify(void)
{
    if(GET_CEC_RX_READ_DONE() == _TRUE)
    {
        StructCecRxReceivedInfo stCecRxInfo;
        memcpy(&stCecRxInfo, &g_stCecRxReceivedInfo, sizeof(StructCecRxReceivedInfo));

        DebugMessageCEC("CEC RX Read: HB ", g_stCecRxReceivedInfo.ucReceivedHb);
        for(pData[0] = 0; pData[0] < g_stCecRxReceivedInfo.ucDbLength; pData[0]++)
        {
            DebugMessageCEC("CEC RX Read: DB ", g_stCecRxReceivedInfo.pucReceivedDb[pData[0]]);
        }

        // Pass Cec Rx Info to User
        UserInterfaceCecReceivedNotify(&stCecRxInfo);

        SET_CEC_RX_MSG_ANALYZING();

        CLR_CEC_RX_READ_DONE();

        // reset Cec rx struct
        memset(&g_stCecRxReceivedInfo, 0, sizeof(g_stCecRxReceivedInfo));
    }
}

//--------------------------------------------------
// Description  : Catch Cec Tx
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonCecTransmitInfoPrepare(void)
{
    if(ScalerCecGetTxState() == _CEC_TX_IDLE_STATE)
    {
        StructCecTxTransmitInfo stCecTxInfo;
        memset(&stCecTxInfo, 0, sizeof(StructCecTxTransmitInfo));

        if(UserInterfaceCecTransmitInfoPrepare(&stCecTxInfo) == _TRUE)
        {
            memcpy(&g_stCecTxTransmitInfo, &stCecTxInfo, sizeof(StructCecTxTransmitInfo));

            SET_CEC_TX_START();
        }
    }
}
#endif
