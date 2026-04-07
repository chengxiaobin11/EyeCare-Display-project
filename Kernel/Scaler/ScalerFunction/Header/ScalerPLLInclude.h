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
// ID Code      : ScalerPLLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
#define _DDRPLL_VCO_CLK_1X                          0
#define _DDRPLL_VCO_CLK_2X                          1
#define _DDRPLL_CLK_SOURCE                          _DDRPLL_VCO_CLK_2X
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
extern void ScalerPLLM2PLLPower(BYTE ucOn);
extern void ScalerM2PLLDiv(BYTE ucDiv);
extern void ScalerPLLSetDPLLReset(void);
extern void ScalerPLLSetDPLLSSC(BYTE ucDclkSpreadSpeed, BYTE ucSpreadRange);
extern void ScalerPLLSetDPLLFreq(DWORD ulFreq);
extern void ScalerDPLLFineTuneFrameSyncLineBuffer(void);

#if(_FRC_SUPPORT == _ON)
extern void ScalerDPLLFineTuneFrameSyncFrameBuffer(void);
#endif

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
#if(_MPLL_STRUCT_TYPE != _MPLL_STRUCT_COMBO_M2PLL)
extern void ScalerPLLSetMPLLFreq(DWORD ulFreq);
#endif
#endif

#if(_VGA_SUPPORT == _ON)
extern bit ScalerAPLLAdjust(WORD usCurrHTotal, WORD usCurrHFreq);
extern WORD ScalerAPLLGetIHTotal(void);
#endif

#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR2)
extern void ScalerPLLDDR2PLLCtrl(bit bEnable);
extern void ScalerPLLDDR2PLLOutputCtrl(bit bEnable);
extern void ScalerPLLSetDDR2PLLFreq(DWORD ulFreq);
#endif

#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)
extern void ScalerPLLSetDDRPLLFreq(DWORD ulFreq);
#endif

