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
// ID Code      : RL6851_Series_ScalerODInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_OD_SUPPORT == _ON)

#if(_FRC_SUPPORT == _ON)

#define GET_DYNAMIC_OD_STATUS()                 ((GET_MEMORY_DVF_SELECT() == _2_IVF) || (GET_MEMORY_DVF_SELECT() == _2_5_IVF) || (GET_MEMORY_DVF_SELECT() == _3_IVF))

#define GET_OD_CURR_DYNAMIC_STATUS()            (g_ucODCurrDynamicStatus)
#define SET_OD_CURR_DYNAMIC_STATUS(x)           (g_ucODCurrDynamicStatus = (x))

#endif

#define CHECK_OD_PARAM_AVAILABLE(x)             (\
                                                    ((x) == _OD_PARAM_7_5_BPP) ||\
                                                    ((x) == _OD_PARAM_6_0_BPP) ||\
                                                    ((x) == _OD_PARAM_4_5_BPP)\
                                                )
#endif
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_OD_SUPPORT == _ON)
#if(_FRC_SUPPORT == _ON)
extern BYTE g_ucODCurrDynamicStatus;
#endif
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_OD_SUPPORT == _ON)
extern EnumODParamIndex ScalerODGetParamSet(DWORD ulMemoryRemainSpace, WORD usMemoryRemainBW);
extern EnumFunctionOnOFF ScalerODGetStatus(void);
#endif
