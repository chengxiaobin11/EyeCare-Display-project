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
// ID Code      : ScalerDPRx0_INT_SeptPhyInclude.h No.0000
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
#if(_D0_DP_EXIST == _ON)
extern BYTE ScalerDpRx0GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx0GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpRx0SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx0SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx0SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern BYTE ScalerDpRx0TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx0TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern void ScalerDpRx0TrainingPatternEnd_EXINT0(void);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
extern void ScalerDpRx0HDCPResetDpcdInfo_EXINT0(void);
extern void ScalerDpRx0HDCPResetKsvFifoToFirst_EXINT0(void);
extern void ScalerDpRx0HDCPSetKsvFifo_EXINT0(void);
#endif // End of #if(_DP_MST_SUPPORT == _ON)

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern BYTE ScalerDpRx0GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern BYTE ScalerDpRx0GetDpcdBitInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern void ScalerDpRx0SetDpcdValue_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
#endif
#endif

extern void ScalerDpRx0AdjustLaneFLDBand_EXINT0(BYTE ucDpRx0LaneNumber, WORD usVCOBandDiff);
extern BYTE ScalerDpRx0DFECheck_EXINT0(void);
extern void ScalerDpRx0SetDFEInitial_EXINT0(void);

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
extern void ScalerDpRx0MstAutoSwitch_EXINT0(void);
#if(_D1_DP_EXIST == _ON)
extern void ScalerDpRx0SetHotPlugEvent_EXINT0(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx0SetBranchDeviceSpecificField_EXINT0(EnumDpVersionType enumDpVersion);
extern void ScalerDpRx0ClearBranchDeviceSpecificField_EXINT0(void);
#endif
#endif
#endif // End of #if(_D0_DP_EXIST == _ON)

