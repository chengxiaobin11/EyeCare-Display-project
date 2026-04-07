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
// ID Code      : ScalerLCTankInclude.h No.0000
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
#if(_LC_TANK_SUPPORT == _ON)
#if(_XTALESS_SUPPORT == _ON)
extern DWORD g_ulLCTankBaseCount;
extern DWORD g_ulLCTankActiveCount;
#endif
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_LC_TANK_SUPPORT == _ON)
#if(_XTALESS_SUPPORT == _ON)
extern void ScalerLCTankIOSCFromM2PLL(bit bOn);
extern void ScalerLCTankSystemClkFromM2PLLMcuDiv(bit bOn);
extern void ScalerLCTankDpllRegulationInitial(void);
#endif
#endif
