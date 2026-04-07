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
// ID Code      : RL6463_Series_PLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
// HW Fixed div 2 is disable (div2 of MPLL no control register)
#define _MPLL_FIXED_DIV                               _DIV_2// 1 -- > div2 is disable  2 --> div2 is enable

#define _REG_DPLL_N_F_CODE_0                          (P1_C0_DPLL0)
#define _REG_DPLL_N_F_CODE_1                          (P1_C1_DPLL1)
#define _REG_DPLL_N_F_CODE_2                          (P1_C2_DPLL2)
#define _REG_DPLL_N_F_CODE_3                          (P1_C3_DPLL3)
#define _REG_DPLL_SSCG_0                              (P1_CA_SSCG_0)
#define _REG_DPLL_SSCG_1                              (P1_CB_SSCG_1)
#define _REG_DPLL_SSCG_2                              (P1_CC_SSCG_2)
#define _REG_DPLL_SSCG_3                              (P1_CD_SSCG_3)
#define _REG_DPLL_SSCG_4                              (P1_CE_SSCG_4)
#define _REG_DPLL_SSCG_5                              (P1_CF_SSCG_5)
#define _REG_DPLL_ANALOG_SETTING_0                    (P1_D0_LVDSPLL_0)

#define GET_N_F_PLL_PREDIVIDER()                      ((ScalerGetByte(P1_D0_LVDSPLL_0) & 0x03) + 2)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

