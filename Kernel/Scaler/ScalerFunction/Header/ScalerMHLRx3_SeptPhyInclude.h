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
// ID Code      : ScalerMHLRx3_SeptPhyInclude.h No.0000
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
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
extern void ScalerMHLRx3DataPortInitial(void);
extern void ScalerMHLRx3DataPortInitial_EXINT0(void);
extern bit ScalerMHLRx3MscRCPGetCommand(BYTE *pucKeyCode);
extern void ScalerMHLRx3SetDevCapReg(void);
extern void ScalerMHLRx3SetTimingRelateSetting(void);
extern void ScalerMHLRx3TimerEventProc(EnumScalerTimerEventID enumEventID);

#endif
