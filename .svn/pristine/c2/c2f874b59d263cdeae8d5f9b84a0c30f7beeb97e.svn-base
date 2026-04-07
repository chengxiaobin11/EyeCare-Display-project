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
// ID Code      : RL6851_Series_GlobalInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerGlobalDoubleBufferEnable(bit bEn);
extern void ScalerGlobalIDomainDBApply(EnumDBApply enumDBApply);
extern bit ScalerGlobalGetDBStatus(void);
extern void ScalerGlobalCrystalClkSel(EnumClkSel enumClkSel);
extern void ScalerGlobalWatchDog(bit bEnable);

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
extern void ScalerGlobalPreventGarbageByBacklight_EXINT0(void);
#endif

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
extern void ScalerGlobalEnableUnderflowMonitor(bit bEnable);
#endif
#endif
