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
// ID Code      : ScalerCommonTypeCPowerInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
#define GET_RX0_OUTPUT_VOL()            (g_stTpcRx0PowerInfo.usRx0OutputVol)
#define GET_RX0_OUTPUT_CUR()            ((WORD)(g_stTpcRx0PowerInfo.b10Rx0OutputCur))
#endif // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern StructTypeCPowerInfo g_stTpcRx0PowerInfo;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerTypeCPowerClkSel(BYTE ucClockSel);
extern void ScalerTypeCPowerAdcInitial(void);
extern EnumTypeCLocalPowerExist ScalerTypeCPowerGetLocPowExist(void);
extern void ScalerTypeCPowerCheckLocPowExist(void);
extern WORD ScalerTypeCPowerGetAdcOutput(EnumTypeCAdcChannel enumChannel);

#endif // End of #if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))

