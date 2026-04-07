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
// ID Code      : RL6851_Series_ScalerCommonPLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_M2PLL_STRUCT_TYPE == _M2PLL_STRUCT_COMBO_SDRPLL)
//--------------------------------------------------
// Definitions of N.F M2PLL Clock Frequency Paramater
//--------------------------------------------------
#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_200M)
#define _M2PLL_CLK_KHZ                              200200
#define _M2PLL_CLK_MHZ                              200
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M)
#define _M2PLL_CLK_KHZ                              189000
#define _M2PLL_CLK_MHZ                              189
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_216M)
#define _M2PLL_CLK_KHZ                              216000
#define _M2PLL_CLK_MHZ                              216
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_220M)
#define _M2PLL_CLK_KHZ                              220000
#define _M2PLL_CLK_MHZ                              220
#endif
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
