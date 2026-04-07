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
// ID Code      : ScalerCommonUSB3RetimerInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_USB3_RETIMER_SUPPORT == _ON)
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
extern void ScalerUSB3RetimerHandler(BYTE ucPowerStatus);
extern void ScalerUSB3RetimerIntHandler_EXINT3(void);
extern void ScalerUSB3RetimerSetPSStatus(EnumUSBPSSupportStatus enumUSBPSSupportStatus);
extern void ScalerUSB3RetimerSetPDStatus(EnumUSBPDSupportStatus enumUSBPDSupportStatus);
extern EnumUSBPSSupportStatus ScalerUSB3RetimerGetPSStatus(void);
extern EnumUSBPDSupportStatus ScalerUSB3RetimerGetPDStatus(void);
extern void ScalerUSB3RetimerHubUfpSwitchProc(EnumHubInputPort enumHubInputPort);
extern void ScalerUSB3RetimerPowerSwitch(EnumPowerAction enumPowerAction);
extern void ScalerUSB3RetimerSetHubUfpStatus(EnumHubInputPort enumHubInputPort);
extern EnumHubInputPort ScalerUSB3RetimerGetHubUfpStatus(void);
extern bit ScalerUSB3RetimerGetPdNoResponse(void);
#endif // End of #if(_USB3_RETIMER_SUPPORT == _ON)

