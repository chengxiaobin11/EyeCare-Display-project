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
// ID Code      : RL6851_Series_ScalerCommonFwUpdateForegroundInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_FW_UPDATE_FOREGROUND_SUPPORT == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define _FW_UPDATE_FOREGROUND_ISP_DATA_SUB_ADDRESS              0x34
#define _FW_UPDATE_FOREGROUND_EXIT_TIMER_COUNT                  60000
#define _FW_UPDATE_FOREGROUND_RESTORE_SCENE_MAX_ISP_LEN         32
#define _FW_UPDATE_FOREGROUND_RESET_MAX_ISP_LEN                 256

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern bit ScalerFwUpdateForegroundGetStatus(void);
#if(_FW_UPDATE_FOREGROUND_EXIT_TYPE == _FW_UPDATE_FOREGROUND_RESET)
extern void ScalerFwUpdateForegroundReset(void);
#endif

#if(_FW_UPDATE_FOREGROUND_EXIT_TYPE == _FW_UPDATE_FOREGROUND_RESTORE_SCENE)
extern void ScalerFwUpdateForegroundRestoreScene(void);
extern void ScalerFwUpdateForegroundSceneBackup(void);
#endif

#endif
