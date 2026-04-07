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
// ID Code      : RL6492_Series_DPRx1_INTInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D1_DP_EXIST == _ON)

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
extern void ScalerDpRx1IntHandler_EXINT0(void);
extern void ScalerDpRx1Tp1SetPhy_EXINT0(EnumDpNFCodeRef enumDpNFCodeRef);
extern void ScalerDpRx1Tp2SetPhy_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpRx1RebuildPhy_WDINT(BYTE ucDpLinkRate, BYTE ucDpcdLane);
#endif

extern BYTE ScalerDpRx1GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx1GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern void ScalerDpRx1SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx1SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx1SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern BYTE ScalerDpRx1TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx1TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern void ScalerDpRx1TrainingPatternEnd_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern BYTE ScalerDpRx1GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern BYTE ScalerDpRx1GetDpcdBitInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern void ScalerDpRx1SetDpcdValue_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
#endif
#endif

extern BYTE ScalerDpRx1Tp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern BYTE ScalerDpRx1Tp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);

#endif // End of #if(_D1_DP_EXIST == _ON)
