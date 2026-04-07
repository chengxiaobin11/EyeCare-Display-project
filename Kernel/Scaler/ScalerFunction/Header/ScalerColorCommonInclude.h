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
// ID Code      : ScalerColorCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macro of DCC Ready Flag
//--------------------------------------------------
#define GET_DCC_READY_STATUS()                      (g_bDCCReadyStatus)
#define SET_DCC_READY_STATUS()                      (g_bDCCReadyStatus = _TRUE)
#define CLR_DCC_READY_STATUS()                      (g_bDCCReadyStatus = _FALSE)

//--------------------------------------------------
// Macro of DCR Ready Flag
//--------------------------------------------------
#define GET_DCR_READY_STATUS()                      (g_bDCRReadyStatus)
#define SET_DCR_READY_STATUS()                      (g_bDCRReadyStatus = _TRUE)
#define CLR_DCR_READY_STATUS()                      (g_bDCRReadyStatus = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bDCCReadyStatus;
extern bit g_bDCRReadyStatus;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight, EnumDBApply enumDBApply);
