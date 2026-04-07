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
// ID Code      : ScalerCommonPLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_M2PLL_STRUCT_TYPE == _M2PLL_STRUCT_M_N)
//--------------------------------------------------
// Definitions of MN M2PLL Clock Frequency Paramater
//--------------------------------------------------
#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_243M)

#if(_EXT_XTAL == _XTAL14318K)
#define _M2PLL_PLL_M                                (66 + 2) // Page1 0xE0[7:0] default value = 0x42
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#elif(_EXT_XTAL == _XTAL27000K)
#define _M2PLL_PLL_M                                (38 + 2) // Page1 0xE0[7:0] default value = 0x42
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#endif

#define _M2PLL_PLL_O                                2        // Page1 0xE1[5:4] default value = 0x1
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_351M) // Else of #if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_243M)

#if(_EXT_XTAL == _XTAL14318K)
#define _M2PLL_PLL_M                                (47 + 2) // Page1 0xE0[7:0] default value = 0x2F
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#elif(_EXT_XTAL == _XTAL27000K)
#define _M2PLL_PLL_M                                (24 + 2) // Page1 0xE0[7:0] default value = 0x18
#define _M2PLL_PLL_N                                (0 + 2)  // Page1 0xE1[3:0] default value = 0x0
#endif

#define _M2PLL_PLL_O                                1        // Page1 0xE1[5:4] default value = 0x0
#endif // End of #if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_243M)

#define _DWORD_DIMENSION                            1UL
#define _M2PLL_CLK_KHZ                              (((_DWORD_DIMENSION * _EXT_XTAL * _M2PLL_PLL_M) + ((_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O) / 2)) / (_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O))
#define _M2PLL_CLK_MHZ                              (((_DWORD_DIMENSION * _EXT_XTAL * _M2PLL_PLL_M) + ((_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O * 1000) / 2)) / (_DWORD_DIMENSION * _M2PLL_PLL_N * _M2PLL_PLL_O * 1000))

#elif(_M2PLL_STRUCT_TYPE == _M2PLL_STRUCT_N_F)
//--------------------------------------------------
// Definitions of N.F M2PLL Clock Frequency Paramater
//--------------------------------------------------
#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_372M)
#define _M2PLL_CLK_KHZ                              372268
#define _M2PLL_CLK_MHZ                              372
#endif

#endif
//--------------------------------------------------
// Definitions of PLL VCO BAND
//--------------------------------------------------
#define _PLL_VCO_BAND_00                            (778)
#define _PLL_VCO_BAND_01                            (1340)
#define _PLL_VCO_BAND_10                            (1880)
#define _PLL_VCO_BAND_11                            (2340)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
