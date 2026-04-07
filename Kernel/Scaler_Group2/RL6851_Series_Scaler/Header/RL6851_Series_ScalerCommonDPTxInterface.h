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
// ID Code      : RL6851_Series_ScalerCommonDPTxInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_DP_TX_SUPPORT == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

#if(_DP_TX_CONFIG_BY_USER_SUPPORT == _ON)
//--------------------------------------------------
// Macros of DP Tx Link Config Set by User
//--------------------------------------------------
#define GET_DP_TX_CONFIG_SETTING()                           (g_ucDpTxConfigSetting)
#define SET_DP_TX_CONFIG_SETTING(x)                          (g_ucDpTxConfigSetting = (x))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DP_TX_CONFIG_BY_USER_SUPPORT == _ON)
extern BYTE g_ucDpTxConfigSetting;
#endif


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDpTxJudgeHandler(void);
extern void ScalerDpTxModeHandler(void);
extern void ScalerDpTxAuxTimeoutInitial(void);
extern void ScalerDpTxIntHandle_EXINT0(void);
extern void ScalerDpTxHPDProc(void);
extern void ScalerDpTxCloneOutputProc(BYTE ucInputPort, BYTE ucPortType, bit bClone);
#if(_DP_TX_BLOCK_CONTROL_BEFORE_STREAM_OUTPUT == _ON)
extern void ScalerDpTxCloneModeSwitch(bit bClone);
extern bit ScalerDpTxBlockStatusCheck(EnumSourceSearchPort enumInputPort);
#endif
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_DP) || (_PS_AUDIO_INPUT == _PS_AUDIO_BOTH)))
extern void ScalerDpTxAudioSetSleepAudioState(bit bAudioStandAloneStatus);
#endif
extern bit ScalerDpTxGetDownstreamHPDStatus(void);
extern WORD ScalerDpTxGetDownStreamEdidBw(void);
#endif // End of #if(_DP_TX_SUPPORT == _ON)

