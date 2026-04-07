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
// ID Code      : TypeC_Pmic_VISHAY_SIC437A.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "UserCommonInclude.h"

#if(_TYPE_C_PMIC_TYPE == _PMIC_VISHAY_SIC437A)

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ExternalDeviceInterfaceTypeCPmicACOnInitial(void);
void ExternalDeviceInterfaceTypeCPmicUnattachReset(void);
void ExternalDeviceInterfaceTypeCPmicUnattachReset_EXINT0(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_EXINT0(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_WDINT(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_EXINT0(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_EXINT0(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_WDINT(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicOperationMode ExternalDeviceInterfaceTypeCPmicReadPpsOperationModeStatus_EXINT0(void);
#endif
#if(_TYPE_C_PMIC_DEBUG == _ON)
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicDebugCheckStatus(void);
#endif
#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)
WORD ExternalDeviceInterfaceTypeCPmicReadPmicAdcCurrentValue(void);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
BYTE ExternalDeviceInterfaceTypeCPmicAttachProc(EnumTypeCPowerRole enumPowerRole);
BYTE ExternalDeviceInterfaceTypeCPmicAttachProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc(EnumTypeCPowerRole enumPowerRole);
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
BYTE ExternalDeviceInterfaceTypeCPmicTransitionStartProc_EXINT0(WORD usVoltage, WORD usCurrent, WORD *pusSrcAdjustPowerTime);
BYTE ExternalDeviceInterfaceTypeCPmicTransitionReadyProc_WDINT(void);
BYTE ExternalDeviceInterfaceTypeCPmicPRSwapStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
BYTE ExternalDeviceInterfaceTypeCPmicPRSwapToSrcProc_WDINT(void);
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc(EnumTypeCPowerRole enumPowerRole);
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_WDINT(EnumTypeCPowerRole enumPowerRole);
BYTE ExternalDeviceInterfaceTypeCPmicHardRstVbusOffProc(void);
#if(((_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC) && (_TYPE_C_PMIC_SAFETY_PROTECT_SUPPORT == _ON)) ||\
    (_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC) ||\
    (_TYPE_C_PMIC_INT_PIN_CHECK_METHOD == _TYPE_C_PMIC_INT_PIN_CHECK_BY_POLLING))
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc(void);
#endif
#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC)
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_EXINT0(void);
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_WDINT(void);
#endif
#if(_TYPE_C_PMIC_FW_OVP_UVP_SUPPORT == _ON)
BYTE ExternalDeviceInterfaceTypeCPmicOvpProc_EXINT0(void);
#endif
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicVbus5VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
BYTE ExternalDeviceInterfaceTypeCPmicVbus0VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
#endif // End of #if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : PMIC Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicACOnInitial(void)
{
}

//--------------------------------------------------
// Description  : PMIC Reset Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicUnattachReset(void)
{
}

//--------------------------------------------------
// Description  : PMIC Reset Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicUnattachReset_EXINT0(void)
{
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent)
{
    enumPowerDirection = enumPowerDirection;
    usVoltage = usVoltage;
    usCurrent = usCurrent;

#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, 0, 0, 0, 0);
#endif

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent) using 1
{
    enumPowerDirection = enumPowerDirection;
    usVoltage = usVoltage;
    usCurrent = usCurrent;

#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, 0, 0, 0, 0);
#endif

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent) using 3
{
    enumPowerDirection = enumPowerDirection;
    usVoltage = usVoltage;
    usCurrent = usCurrent;

#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
    ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, 0, 0, 0, 0);
#endif

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff(void)
{
    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_EXINT0(void) using 1
{
    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_WDINT(void) using 3
{
    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge(EnumTypeCPmicDischarge enumEn)
{
    enumEn = enumEn;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_EXINT0(EnumTypeCPmicDischarge enumEn) using 1
{
    enumEn = enumEn;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(EnumTypeCPmicDischarge enumEn) using 3
{
    enumEn = enumEn;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection)
{
    enumSwitchControl = enumSwitchControl;
    enumPowerDirection = enumPowerDirection;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_EXINT0(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection) using 1
{
    enumSwitchControl = enumSwitchControl;
    enumPowerDirection = enumPowerDirection;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_WDINT(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection) using 3
{
    enumSwitchControl = enumSwitchControl;
    enumPowerDirection = enumPowerDirection;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumPowerDirection : _SRC / _SNK
//                enumOutputPdoType : PDO Type
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType)
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumPowerDirection : _SRC / _SNK
//                enumOutputPdoType : PDO Type
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType) using 1
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumPowerDirection : _SRC / _SNK
//                enumOutputPdoType : PDO Type
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType) using 3
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Read Output Status
// Input Value  : None
// Output Value : Output Mode (Fixed Voltage/PPS)
//--------------------------------------------------
EnumTypeCPmicOperationMode ExternalDeviceInterfaceTypeCPmicReadPpsOperationModeStatus_EXINT0(void) using 1
{
    return _TYPE_C_PMIC_NONE_MODE_OPERATION;
}
#endif // End of #if(_PORT_CTRL_EMB_PD3_PPS_SUPPORT == _ON)

#if(_TYPE_C_PMIC_DEBUG == _ON)
//--------------------------------------------------
// Description  : PMIC Status
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicDebugCheckStatus(void)
{
    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif // End of #if(_EMB_TYPE_C_PMIC_DEBUG == _ON)

#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)
//--------------------------------------------------
// Description  : PMIC VBUS Current Reading
// Input Value  : None
// Output Value : usCurrent : 0 ~ 500 (Unit = 10mA)
//--------------------------------------------------
WORD ExternalDeviceInterfaceTypeCPmicReadPmicAdcCurrentValue(void)
{
    return 0;
}
#endif // End of #if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)


/////////////////////////////////////
// EIZO PMIC SIC437A CUSTOMIZED FW //
/////////////////////////////////////
#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Type-C Attached Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicAttachProc(EnumTypeCPowerRole enumPowerRole)
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Attach Power Flow
    // Kernel Call This Funciton When TypeC CC Attach as SRC/SNK

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Attached Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicAttachProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Attach Power Flow
    // Kernel Call This Funciton When TypeC CC Attach as SRC/SNK

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Unattached Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc(EnumTypeCPowerRole enumPowerRole)
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Unattach Power Flow
    // Kernel Call This Funciton When TypeC CC Unattach from SRC/SNK

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C Unattached Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicUnattachProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Unattach Power Flow
    // Kernel Call This Funciton When TypeC CC Unattach from SRC/SNK

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C Power Transition Start Control Flow
// Input Value  : usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
//                pusSrcAdjustPowerTime : 25 ~ 35 (Unit = ms)
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicTransitionStartProc_EXINT0(WORD usVoltage, WORD usCurrent, WORD *pusSrcAdjustPowerTime) using 1
{
    usVoltage = usVoltage;
    usCurrent = usCurrent;
    pusSrcAdjustPowerTime = pusSrcAdjustPowerTime;

    // For Eizo Implement Customized Power Transition Flow
    // Kernel Call This Funciton When TypeC PD as SRC and has Sent Accept to SNK During Power Contract

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Power Transition Ready Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicTransitionReadyProc_WDINT(void) using 3
{
    // For Eizo Implement Customized Power Transition Flow
    // Kernel Call This Funciton When TypeC PD as SRC and Vbus is Ready During Power Transition

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Power Role Swap Start Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicPRSwapStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized PR Swap Flow
    // Kernel Call This Funciton When TypeC PD Recive/Send Accept During PR Swap
    // enumPowerRole = _TYPE_C_POWER_SNK means PD Controller as Sink Receive/Send Accept to PR Swap

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Power Role Swap Inital Sink Rcv. PS_RDY Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicPRSwapToSrcProc_WDINT(void) using 3
{
    // For Eizo Implement Customized PR Swap Flow
    // Kernel Call This Funciton When TypeC PD as SNK and Receive PS_RDY from SRC During PR Swap

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Send/Receive Hard Reset Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc(EnumTypeCPowerRole enumPowerRole)
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Hard Reset Flow
    // Kernel Call This Funciton When TypeC PD Send/Receive Hard Reset
    // Use enumPowerRole to Get PD Contrller is SRC or SNK When Hard Reset Happens

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C Send/Receive Hard Reset Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Hard Reset Flow
    // Kernel Call This Funciton When TypeC PD Send/Receive Hard Reset
    // Use enumPowerRole to Get PD Contrller is SRC or SNK When Hard Reset Happens

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C Send/Receive Hard Reset Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicHardRstStartProc_WDINT(EnumTypeCPowerRole enumPowerRole) using 3
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Hard Reset Flow
    // Kernel Call This Funciton When TypeC PD Send/Receive Hard Reset
    // Use enumPowerRole to Get PD Contrller is SRC or SNK When Hard Reset Happens

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C as SRC and Vbus Has Turned Off During Hard Reset Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicHardRstVbusOffProc(void)
{
    // For Eizo Implement Customized Hard Reset Flow
    // Kernel Call This Funciton When TypeC PD as SRC and Vbus Has Turned Off During Hard Reset
    // User Need to Wait 660~1000mS then Turn On Vbus

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

#if(((_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC) && (_TYPE_C_PMIC_SAFETY_PROTECT_SUPPORT == _ON)) ||\
    (_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC) ||\
    (_TYPE_C_PMIC_INT_PIN_CHECK_METHOD == _TYPE_C_PMIC_INT_PIN_CHECK_BY_POLLING))
//--------------------------------------------------
// Description  : Type-C Detect OCP Event Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc(void)
{
    // For Eizo Implement Customized OCP Flow
    // Kernel Call This Funciton When TypeC PD Detect OCP Event

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif

#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC)
//--------------------------------------------------
// Description  : Type-C Detect OCP Event Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_EXINT0(void) using 1
{
    // For Eizo Implement Customized OCP Flow
    // Kernel Call This Funciton When TypeC PD Detect OCP Event

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Type-C Detect OCP Event Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicOcpProc_WDINT(void) using 3
{
    // For Eizo Implement Customized OCP Flow
    // Kernel Call This Funciton When TypeC PD Detect OCP Event

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif

#if(_TYPE_C_PMIC_FW_OVP_UVP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Type-C Detect OVP Event Control Flow
// Input Value  : None
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicOvpProc_EXINT0(void) using 1
{
    // For Eizo Implement Customized OVP Flow
    // Kernel Call This Funciton When TypeC PD Detect OVP Event

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif

//--------------------------------------------------
// Description  : Type-C Vbus 5V Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Vbus Check Type : _TYPE_C_VBUS_CHECK_0V / _TYPE_C_VBUS_CHECK_5V
//--------------------------------------------------
EnumTypeCVbusCheckType ExternalDeviceInterfaceTypeCPmicVbus5VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Vbus 5V Power Flow
    // Kernel Call This Funciton When TypeC Detect Vbus 5V
    // Use enumPowerRole to Get PD Contrller is SRC or SNK When Vbus 5V Detected

    return _TYPE_C_VBUS_CHECK_NONE;
}

//--------------------------------------------------
// Description  : Type-C Vbus 0V Power Control Flow
// Input Value  : enumPowerRole : _TYPE_C_POWER_SRC / _TYPE_C_POWER_SNK
// Output Value : Control Result : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ExternalDeviceInterfaceTypeCPmicVbus0VReadyProc_EXINT0(EnumTypeCPowerRole enumPowerRole) using 1
{
    enumPowerRole = enumPowerRole;

    // For Eizo Implement Customized Vbus 0V Power Flow
    // Kernel Call This Funciton When TypeC Detect Vbus 0V
    // Use enumPowerRole to Get PD Contrller is SRC or SNK When Vbus 0V Detected

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif // End of #if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
#endif // End of #if(_TYPE_C_PMIC_TYPE == _PMIC_VISHAY_SIC437A)

