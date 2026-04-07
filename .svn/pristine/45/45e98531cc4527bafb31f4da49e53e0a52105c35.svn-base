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
// ID Code      : RL6492_Series_DPRx0_INTInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D0_DP_EXIST == _ON)

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
extern void ScalerDpRx0IntHandler_EXINT0(void);
#if(_USB3_RETIMER_SUPPORT == _ON)
// extern void ScalerDpRx0PhyInitial_EXINT0(void);
#endif
extern void ScalerDpRx0Tp1SetPhy_EXINT0(EnumDpNFCodeRef enumDpNFCodeRef);
extern void ScalerDpRx0Tp2SetPhy_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpRx0RebuildPhy_WDINT(BYTE ucDpLinkRate, BYTE ucDpcdLane);
#endif

extern BYTE ScalerDpRx0GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx0GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpRx0SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx0SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx0SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern BYTE ScalerDpRx0TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx0TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern void ScalerDpRx0TrainingPatternEnd_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern BYTE ScalerDpRx0GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern BYTE ScalerDpRx0GetDpcdBitInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern void ScalerDpRx0SetDpcdValue_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
#endif
#endif

extern BYTE ScalerDpRx0Tp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx0Tp1SignalDetectCheck_EXINT0(BYTE ucDpLaneSel);
extern BYTE ScalerDpRx0Tp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);

#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
extern void ScalerDpRx0SetDpAltModeLaneMapping_EXINT0(EnumTypeCPinCfgType enumPinAssignment, EnumTypeCOrientation enumOrientation);
extern void ScalerDpRx0HpdToggleAuxPhyResetProc_EXINT0(bit bHpdHighLow);
#endif

#endif // End of #if(_D0_DP_EXIST == _ON)
