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
// ID Code      : ExternalDeviceTypeCPmicInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of PMIC DEBUG FUNCTION
//--------------------------------------------------
#define _TYPE_C_PMIC_DEBUG                      _OFF

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ExternalDeviceInterfaceTypeCPmicACOnInitial(void);
extern void ExternalDeviceInterfaceTypeCPmicUnattachReset(void);
extern void ExternalDeviceInterfaceTypeCPmicUnattachReset_EXINT0(void);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff(void);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_EXINT0(void);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_WDINT(void);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge(EnumTypeCPmicDischarge enumEn);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_EXINT0(EnumTypeCPmicDischarge enumEn);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(EnumTypeCPmicDischarge enumEn);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_EXINT0(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_WDINT(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
extern EnumTypeCPmicOperationMode ExternalDeviceInterfaceTypeCPmicReadPpsOperationModeStatus_EXINT0(void);
#endif // End of #if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
#if(_TYPE_C_PMIC_DEBUG == _ON)
extern EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicDebugCheckStatus(void);
#endif // End of #if(_TYPE_C_PMIC_DEBUG == _ON)
#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)
extern WORD ExternalDeviceInterfaceTypeCPmicReadPmicAdcCurrentValue(void);
#endif // End of #if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
extern BYTE ExternalDeviceInterfaceTypeCPmicAttachProc(EnumTypeCPowerRole enumPowerRole);
extern BYTE ExternalDeviceInterfaceTypeCPmicAttachProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc(EnumTypeCPowerRole enumPowerRole);
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern BYTE ExternalDeviceInterfaceTypeCPmicTransitionStartProc_EXINT0(WORD usVoltage, WORD usCurrent, WORD *pusSrcAdjustPowerTime);
extern BYTE ExternalDeviceInterfaceTypeCPmicTransitionReadyProc_WDINT(void);
extern BYTE ExternalDeviceInterfaceTypeCPmicPRSwapStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern BYTE ExternalDeviceInterfaceTypeCPmicPRSwapToSrcProc_WDINT(void);
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc(EnumTypeCPowerRole enumPowerRole);
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_WDINT(EnumTypeCPowerRole enumPowerRole);
extern BYTE ExternalDeviceInterfaceTypeCPmicHardRstVbusOffProc(void);
#if(((_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC) && (_TYPE_C_PMIC_SAFETY_PROTECT_SUPPORT == _ON)) ||\
    (_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC) ||\
    (_TYPE_C_PMIC_INT_PIN_CHECK_METHOD == _TYPE_C_PMIC_INT_PIN_CHECK_BY_POLLING))
extern BYTE ExternalDeviceInterfaceTypeCPmicOcpProc(void);
#endif
#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC)
extern BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_EXINT0(void);
extern BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_WDINT(void);
#endif
#if(_TYPE_C_PMIC_FW_OVP_UVP_SUPPORT == _ON)
extern BYTE ExternalDeviceInterfaceTypeCPmicOvpProc_EXINT0(void);
#endif
extern EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicVbus5VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern BYTE ExternalDeviceInterfaceTypeCPmicVbus0VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
#endif // End of #if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
#endif // End of #if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
