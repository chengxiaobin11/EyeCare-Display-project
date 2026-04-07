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
// ID Code      : RL6410_Series_GlobalCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//****************************************************************************
// Definitions of RL6410 ID Code
//****************************************************************************
#define _RL6410_VER_A_ID_CODE                           0x10
#define _RL6410_VER_B_ID_CODE                           0x11
#define _RL6410_VER_C_ID_CODE                           0x12
#define _RL6410_VER_E_ID_CODE                           0x14


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerGlobalDDomainDBApply(EnumDBApply enumDBApply);
extern void ScalerGlobalIDomainDBApply(EnumDBApply enumDBApply);
extern void ScalerGlobalIDDomainDBApply(EnumDBApply enumDBApply);
extern bit ScalerGlobalGetHLWDBStatus(void);
