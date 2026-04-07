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
// ID Code      : RL6851_Series_GlobalInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#define _M2PLL_SYS_DIV                                  ((_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M) ? 7 : 8)
#define _M2PLL_MEASURE_DIV                              4
#define _SYS_USE_ISO_CLK                                ((bit)ScalerGetBit(P0_09_TOP_POWER_CTRL, _BIT3) ? _TRUE : _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerGlobalDoubleBufferEnable(bit bEn);
extern void ScalerGlobalIDDomainDBSetTriggerEvent(void);
extern void ScalerGlobalDoubleBufferConfigReset(void);
extern bit ScalerGlobalGetDBStatus(void);
extern void ScalerGlobalCrystalClkSel(EnumClkSel enumClkSel);
extern void ScalerGlobalWatchDog(bit bEnable);
extern void ScalerGlobalDisplayInitial(void);

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#if(_HW_M_DOMAIN_IMG_CMP_TYPE == _M_DOMAIN_IMG_CMP_GEN_1)
extern void ScalerGlobalEnableUnderflowMonitor(bit bEnable);
#endif
#endif

