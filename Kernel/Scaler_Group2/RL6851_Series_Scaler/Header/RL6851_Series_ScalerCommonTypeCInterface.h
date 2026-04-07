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
// ID Code      : RL6851_Series_ScalerCommonTypeCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
extern void ScalerTypeCSetAltModeReady(BYTE ucInputPort, EnumTypeCAltModeStatus enumAltModeStatus);
extern EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort);
extern void ScalerTypeCSetExplicitContract(BYTE ucInputPort, bit bGetExplicitContract);
extern bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort);
extern EnumTypeCPortCtrlType ScalerTypeCGetPortCtrlType(BYTE ucInputPort);
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
