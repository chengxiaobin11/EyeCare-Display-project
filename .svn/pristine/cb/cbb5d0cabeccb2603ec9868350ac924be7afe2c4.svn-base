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
// ID Code      : ScalerDP_SeptPhyInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
extern BYTE ScalerDpRxGetDpcdBitInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRxGetDpcdInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpRxSetDpcdBitValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRxSetDpcdValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpEdidSwitch(BYTE ucInputPort);

extern EnumDpPowerState ScalerDpGetPowerStatus(BYTE ucInputPort);
extern EnumDpLaneCount ScalerDpGetLaneCount(BYTE ucInputPort);
extern EnumDpLinkRate ScalerDpGetLinkRate(BYTE ucInputPort);
extern EnumDpVoltageSwingLevel ScalerDpGetLaneVoltageSwingLv(BYTE ucInputPort, EnumDpLane enumDpLane);
extern EnumDpPreEmphasisLevel ScalerDpGetLanePreEmpLv(BYTE ucInputPort, EnumDpLane enumDpLane);
extern bit ScalerDpGetSrcMstEnable(BYTE ucInputPort);
extern void ScalerDpSetHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpHotPlugHandler(void);
extern void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction);
#if(_DP_HDCP14_REPEATER_BIT_DISABLE_FOR_TX_CLONE_OFF == _ON)
void ScalerDpRxHdcp14RepeaterCapabilityCheck(BYTE ucInputPort, EnumDPMSTPort enumDPMSTPort, bit bClone);
#endif

extern void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport, EnumAudioDpDpcdSupport enumAudioSupport);
extern void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount);
extern void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
extern void ScalerDpHDCPUnplugReset(BYTE ucInputPort);
extern void ScalerDpMainLinkQualityManagement(BYTE ucInputPort);
extern StructDpRxErrorCount ScalerDpRxGetErrorCount(BYTE ucInputPort);

#if(_DP_AUX_RX_DPCD_EXT_CAP_WILDCARD_SUPPORT == _ON)
extern void ScalerDpRxAuxTimer2PreIntHandler_EXINT(void);
#endif

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
extern void ScalerDpRestoreFakeLTLaneCount(EnumSourceSearchPort enumSourceSearchPort);
#endif

#if(_DP_MST_SUPPORT == _ON)
extern void ScalerDpMstFakeOffDoneProc(void);
extern void ScalerDpMstReset(EnumDPMSTPort enumRxMstPort);
#if(_DP_TX_SUPPORT == _ON)
extern void ScalerDpHDCPHandler(void);
#endif
#endif

extern void ScalerDpRxHpdIrqAssert(BYTE ucInputPort);
#endif

