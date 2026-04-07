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
// ID Code      : RL6492_Series_DP_INTInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_SUPPORT == _ON)

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
#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID);
extern void ScalerDpRxDpcdPortAccessBackup_WDINT(void);
extern void ScalerDpRxDpcdPortAccessBackupRestore_WDINT(void);
#endif

#endif
