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
// ID Code      : RL6851_Series_ScalerCommonDPTxHDCP2Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define GET_DP_TX_HDCP2_LOAD_KEY_EN()                          (bit)(g_ucDpTxHdcp2LoadKey & _BIT7)
#define SET_DP_TX_HDCP2_LOAD_KEY_EN()                          (g_ucDpTxHdcp2LoadKey |= _BIT7)
#define CLR_DP_TX_HDCP2_LOAD_KEY_EN()                          (g_ucDpTxHdcp2LoadKey &= ~_BIT7)

#define GET_DP_TX_HDCP2_LOAD_KEY_FINISH()                      (bit)(g_ucDpTxHdcp2LoadKey & _BIT6)
#define SET_DP_TX_HDCP2_LOAD_KEY_FINISH()                      (g_ucDpTxHdcp2LoadKey |= _BIT6)
#define CLR_DP_TX_HDCP2_LOAD_KEY_FINISH()                      (g_ucDpTxHdcp2LoadKey &= ~_BIT6)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern BYTE g_ucDpTxHdcp2LoadKey;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDpTxHdcp2DcpLlcRsaInit(void);
extern void ScalerDpTxHdcp2LoadKeyProc(BYTE ucLoadKeyType, BYTE *pucDpTxHdcp2Key);
#endif // End of #if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))

