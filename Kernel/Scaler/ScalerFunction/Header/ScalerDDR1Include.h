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
// ID Code      : ScalerDDR1Include.h No.0000
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


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
extern void ScalerDDR1PowerControl(bit bOn);
extern void ScalerDDR1ControlReset(void);
#if((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON))
extern void ScalerDDR1SetFRCDisplayTokenRing(EnumFunctionOnOFF enumOn);
#endif
#endif

#if(_DDR1_PHASE_CALIBRATION == _ON)
extern void ScalerDDR1OnLinePhaseCntCheck(void);

#endif
