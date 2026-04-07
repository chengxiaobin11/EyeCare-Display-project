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
// ID Code      : RL6449_Series_PLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
// HW Fixed div 2 is disable (div2 of MPLL no control register)
#define _MPLL_FIXED_DIV                               _DIV_1// 1 -- > div2 is disable  2 --> div2 is enable

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_DPTX)
extern bit ScalerPLLGetDptxPowerStatus(void);
#endif
extern DWORD ScalerPLLGetDPLLRefClk(DWORD ulFreq);

#if((_PANEL_STYLE == _PANEL_VBO) || (_PANEL_STYLE == _PANEL_DPTX))
extern void ScalerPLLSetDPLLRefPLL(DWORD ulFreq);
extern void ScalerPLLDPTxPLLReset(void);
#endif
