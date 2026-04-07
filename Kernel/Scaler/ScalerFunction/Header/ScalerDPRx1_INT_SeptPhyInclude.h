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
// ID Code      : ScalerDPRx1_INT_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
extern BYTE ScalerDpRx1GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx1GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpRx1SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx1SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx1SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern BYTE ScalerDpRx1TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx1TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern void ScalerDpRx1TrainingPatternEnd_EXINT0(void);

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
extern void ScalerDpRx1HDCPResetDpcdInfo_EXINT0(void);
extern void ScalerDpRx1HDCPResetKsvFifoToFirst_EXINT0(void);
extern void ScalerDpRx1HDCPSetKsvFifo_EXINT0(void);
#endif

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern BYTE ScalerDpRx1GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern BYTE ScalerDpRx1GetDpcdBitInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern void ScalerDpRx1SetDpcdValue_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
#endif
#endif

extern void ScalerDpRx1AdjustLaneFLDBand_EXINT0(BYTE ucDpRx1LaneNumber, WORD usVCOBandDiff);
extern void ScalerDpRx1IntHandler_EXINT0(void);
extern void ScalerDpRx1SetDFEInitial_EXINT0(void);

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
extern void ScalerDpRx1MstAutoSwitch_EXINT0(void);
#if(_D0_DP_EXIST == _ON)
extern void ScalerDpRx1SetHotPlugEvent_EXINT0(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx1SetBranchDeviceSpecificField_EXINT0(EnumDpVersionType enumDpVersion);
extern void ScalerDpRx1ClearBranchDeviceSpecificField_EXINT0(void);
#endif
#endif
#endif // End of #if(_D1_DP_EXIST == _ON)

