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
// ID Code      : ScalerCommonUSB3RetimerInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_USB3_RETIMER_SUPPORT == _ON)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerUSB3RetimerInitial(void);
extern void ScalerUSB3RetimerStartup(bit bEnable);
extern void ScalerUSB3RetimerUfpPhyConfig(void);
extern void ScalerUSB3RetimerUfpIrqEnable(bit bEnable);
// extern void ScalerUSB3RetimerUfpIrqEnable_EXINT3(bit bEnable);
// extern void ScalerUSB3RetimerUfpPhyConfig_EXINT3(void);
extern void ScalerUSB3RetimerDfpEnable(bit bControl);
// extern void ScalerUSB3RetimerDfpEnable_EXINT3(bit bControl);
#endif // End of #if(_USB3_RETIMER_SUPPORT == _ON)


