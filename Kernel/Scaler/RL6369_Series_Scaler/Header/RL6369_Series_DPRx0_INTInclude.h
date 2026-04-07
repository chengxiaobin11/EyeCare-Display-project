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
// ID Code      : RL6369_Series_DPRx0_INTInclude.h No.0000
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
extern void ScalerDpRx0IntHandler_EXINT0(void);
extern void ScalerDpRx0Tp1SetPhy_EXINT0(EnumDpNFCodeRef enumDpNFCodeRef);
extern void ScalerDpRx0Tp2SetPhy_EXINT0(void);
extern BYTE ScalerDpRx0Tp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpRx0RebuildPhy_WDINT(BYTE ucDpLinkRate, BYTE ucDpcdLane);
#endif
