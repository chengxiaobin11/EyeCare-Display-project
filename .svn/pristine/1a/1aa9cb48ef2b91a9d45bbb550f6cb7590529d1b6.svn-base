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
// ID Code      : ScalerDP_ComboPhyInterface.h No.0000
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
extern void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport, EnumAudioDpDpcdSupport enumAudioSupport);
extern void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction);
extern void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount);
extern bit ScalerDpNormalPreDetect(BYTE ucInputPort);
extern bit ScalerDpPSPreDetect(BYTE ucInputPort);
extern void ScalerDpScanInitial(BYTE ucInputPort);
extern BYTE ScalerDpScanInputPort(BYTE ucInputPort);
extern bit ScalerDpStableDetect(BYTE ucInputPort);
extern void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
extern void ScalerDpHDCPUnplugReset(BYTE ucInputPort);
extern void ScalerDpMainLinkQualityManagement(BYTE ucInputPort);
extern StructDpRxErrorCount ScalerDpRxGetErrorCount(BYTE ucInputPort);

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
extern void ScalerDpRestoreFakeLTLaneCount(EnumSourceSearchPort enumSourceSearchPort);
#endif

extern void ScalerDpRxHpdIrqAssert(BYTE ucInputPort);

#endif
