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
// ID Code      : RL6463_Series_GlobalInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#define _M2PLL_SYS_DIV                                  13
#define _M2PLL_MEASURE_DIV                              9
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
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
extern bit ScalerGlobalGetHLWDBStatus(void);
#endif
extern void ScalerGlobalCrystalClkSel(EnumClkSel enumClkSel);
extern void ScalerGlobalWatchDog(bit bEnable);


