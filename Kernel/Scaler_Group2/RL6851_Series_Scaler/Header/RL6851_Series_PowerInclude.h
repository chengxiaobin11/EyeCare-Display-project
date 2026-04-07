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
// ID Code      : RL6851_Series_PowerInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _POLLING_VCCK_ADDR                          (P39_00_LVDS_DISP_TYPE)
#define _POLLING_VCCK_VALUE                         (0x01) // DISP_TYPE = LVDS


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern BYTE ScalerPowerIsolation(EnumPowerAction enumSwitch);
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
extern BYTE ScalerPowerDomainEnableControl(EnumPowerGroup enumPowerGroup, EnumPowerCut enumPowerCut);
#endif // End of #if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)

