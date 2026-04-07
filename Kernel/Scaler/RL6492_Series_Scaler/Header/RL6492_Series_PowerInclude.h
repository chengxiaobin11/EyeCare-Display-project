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
// ID Code      : RL6492_Series_PowerInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _POLLING_VCCK_ADDR                          (P39_00_LVDS_DISP_TYPE)
#define _POLLING_VCCK_VALUE                         (0x01)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerPowerGroupU3RetimerIsolation(BYTE ucOn);
extern void ScalerPowerGroupTPCUFPIsolation(BYTE ucOn);
extern void ScalerPowerGroupU3RetimerPowerCut(BYTE ucOn);
extern void ScalerPowerGroupTPCUFPPowerCut(BYTE ucOn);

