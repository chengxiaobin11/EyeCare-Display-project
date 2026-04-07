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
// ID Code      : RL6851_Series_ScalerDPTxInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_TX_SUPPORT == _ON)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_DP_TX_DOWNSTREAM_MAIN_LINK_POWER_STATUS()       (ScalerGetBit(PBC_A1_DPTX_PHY_CTRL1, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != (_BIT3 | _BIT2 | _BIT1 | _BIT0))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpTxInitialReset(void);
extern void ScalerDpTxSSTDisplayFormatSetting(void);
extern BYTE ScalerDpTxSetTPSxPattern(void);
extern bit ScalerDpTxLinkRateReduce(EnumDPTxLTResult enumDPTxLTResult);
extern bit ScalerDpTxLaneCountReduce(EnumDPTxLTResult enumDPTxLTResult);
extern void ScalerDpTxAuxPowerOffProc(void);
extern void ScalerDpTxAuxSwingSetting(void);
extern void ScalerDpTxSignalInitialSetting(void);
extern bit ScalerDpTxMeasureGetMeasureResult(StructMeasureSyncData *pstMeasureSyncHV);
extern bit ScalerDpTxMeasureInputInfo(void);
extern bit ScalerDpTxInputMSAInfo(void);
extern bit ScalerDpTxCloneCheckMSAInfo(BYTE ucInputPort);
extern bit ScalerDpTxCloneCheckInterlaceVtotal(void);
extern void ScalerDpTxCloneSwitchFormatConversionMux(BYTE ucInputPort);
extern bit ScalerDpTxLinkStatusCheck(void);

#endif // End of #if(_DP_TX_SUPPORT == _ON)
