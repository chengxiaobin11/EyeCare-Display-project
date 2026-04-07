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
// ID Code      : UserCommonPortControllerUser.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_PORTCONTROLLERUSER__

#include "UserCommonInclude.h"

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D0_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
EnumTypeCAttachStatus UserCommonPortControllerGetD0CcAttachByI2C(void);
EnumTypeCAltModeStatus UserCommonPortControllerGetD0AltModeReadyByI2C(void);
#endif
#endif

#if(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D1_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
EnumTypeCAttachStatus UserCommonPortControllerGetD1CcAttachByI2C(void);
EnumTypeCAltModeStatus UserCommonPortControllerGetD1AltModeReadyByI2C(void);
#endif
#endif

#if(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D6_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
EnumTypeCAttachStatus UserCommonPortControllerGetD6CcAttachByI2C(void);
EnumTypeCAltModeStatus UserCommonPortControllerGetD6AltModeReadyByI2C(void);
#endif
#endif

#if(_EXT_PORT_CTRL_LANE_SWAP_BY_SCALER_SUPPORT == _ON)
EnumTypeCOrientation UserCommonPortControllerGetUserOrientation(BYTE ucInputPort);
#endif
bit UserCommonPortControllerGetUserPinAssignment(BYTE ucInputPort, EnumTypeCPinCfgType *penumPinAssignment);
void UserCommonPortControllerUserCcFunctionControl(BYTE ucInputPort, EnumTypeCCcFunction enumCcFunction);
EnumTypeCPowerRole UserCommonPortControllerGetUserPowerRole(BYTE ucInputPort);
EnumTypeCDataRole UserCommonPortControllerGetUserDataRole(BYTE ucInputPort);
void UserCommonPortControllerSetUserPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoCnt);
void UserCommonPortControllerSetUserPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, StructTypeCUserPDO stTypeCUserPdo);
void UserCommonPortControllerSetUserRdo(BYTE ucInputPort, StructTypeCUserRDO stTypeCUserRdo);
EnumTypeCPdoNumber UserCommonPortControllerGetUserPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole);
StructTypeCUserPDO UserCommonPortControllerGetUserPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
EnumTypeCPdoNumber UserCommonPortControllerGetUserPartnerPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole);
StructTypeCUserPDO UserCommonPortControllerGetUserPartnerPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
void UserCommonPortControllerGetUserPdoStatus(BYTE ucInputPort, WORD *pusVoltage, WORD *pusCurrent);
StructTypeCUserPDO UserCommonPortControllerGetUserRequestedSrcPdo(BYTE ucInputPort);
bit UserCommonPortControllerUserReconnect(BYTE ucInputPort);
bit UserCommonPortControllerGetUserFwVersion(BYTE ucInputPort, StructTypeCPortCtrlFwVersion *pstTypeCFwVersion);
StructTypeCCableInfoForDpcd UserCommonPortControllerGetUserCableInfoForDpcd(BYTE ucInputPort);
bit UserCommonPortControllerConfigUserPinAssignment(BYTE ucInputPort, EnumTypeCPinCfgCapType enumPinAssignment);
bit UserCommonPortControllerConfigUserMultiFunction(BYTE ucInputPort, EnumTypeCMultiFuncStatus enumMultiFunction);

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
EnumTypeCLenovoAltModeStatus UserCommonPortControllerGetUserLenovoAltModeReady(BYTE ucInputPort);
EnumTypeCLenovoDeviceType UserCommonPortControllerGetUserLenovoDeviceType(BYTE ucInputPort);
void UserCommonPortControllerSetUserLenovoDockingEvent(BYTE ucInputPort, StructTypeCLenovoDockEvent stLenovoDockEvent);
StructTypeCLenovoSysEvent UserCommonPortControllerGetUserLenovoSystemEvent(BYTE ucInputPort);
bit UserCommonPortControllerCheckUserLenovoDockingEventBusy(BYTE ucInputPort);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D0_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
//--------------------------------------------------
// Description  : Get D0 CC Attached Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAttachStatus UserCommonPortControllerGetD0CcAttachByI2C(void)
{
    return _TYPE_C_UNATTACH;
}

//--------------------------------------------------
// Description  : Get D0 Alt Mode Ready Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAltModeStatus UserCommonPortControllerGetD0AltModeReadyByI2C(void)
{
    return _TYPE_C_ALT_MODE_NOT_READY;
}

#endif  // End of #if(_D0_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)

#if(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D1_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
//--------------------------------------------------
// Description  : Get D1 CC Attached Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAttachStatus UserCommonPortControllerGetD1CcAttachByI2C(void)
{
    return _TYPE_C_UNATTACH;
}

//--------------------------------------------------
// Description  : Get D1 Alt Mode Ready Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAltModeStatus UserCommonPortControllerGetD1AltModeReadyByI2C(void)
{
    return _TYPE_C_ALT_MODE_NOT_READY;
}
#endif  // End of #if(_D1_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
#endif  // End of #if(_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)

#if(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)
#if(_D6_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
//--------------------------------------------------
// Description  : Get D6 CC Attached Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAttachStatus UserCommonPortControllerGetD6CcAttachByI2C(void)
{
    return _TYPE_C_UNATTACH;
}

//--------------------------------------------------
// Description  : Get D6 Alt Mode Ready Info Through I2C
// Input Value  : None
// Output Value : CC Attach (_TRUE / _FALSE)
//--------------------------------------------------
EnumTypeCAltModeStatus UserCommonPortControllerGetD6AltModeReadyByI2C(void)
{
    return _TYPE_C_ALT_MODE_NOT_READY;
}
#endif  // End of #if(_D6_DP_TYPE_C_DISCRETE_PORT_CTRL_LINK == _DISCRETE_PORT_CTRL_USE_SMBUS)
#endif  // End of #if(_D6_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_USER)

#if(_EXT_PORT_CTRL_LANE_SWAP_BY_SCALER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Orientation Status
// Input Value  : ucInputPort --> Inputput
// Output Value : Orientation (_TYPE_C_ORIENTATION_UNFLIP / _TYPE_C_ORIENTATION_FLIP)
//--------------------------------------------------
EnumTypeCOrientation UserCommonPortControllerGetUserOrientation(BYTE ucInputPort)
{
    return UserInterfaceTypeCGetPortControllerOrientation(ucInputPort);
}
#endif

//--------------------------------------------------
// Description  : Return Port Controller Alt Mode Pin Assignment to SysTypeC
// Input Value  : None
// Output Value : _SUCCESS / _FAIL
//--------------------------------------------------
bit UserCommonPortControllerGetUserPinAssignment(BYTE ucInputPort, EnumTypeCPinCfgType *penumPinAssignment)
{
    EnumTypeCPinCfgType enumPinCfgtype = _TYPE_C_PIN_ASSIGNMENT_C;

    // Read User Port Controller Alt Mode Pin Assignment Info
    if(UserInterfaceTypeCGetPinCfgType(ucInputPort, &enumPinCfgtype) == _TYPE_C_USER_PORT_CTRL_COMMUNICATION_FAIL)
    {
        DebugMessageSystem("8. Get User Port Controller Pin Assignment Type Fail", 0);

        return _FAIL;
    }

    *penumPinAssignment = enumPinCfgtype;

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Update CC Function Control to User Port Ctrl (Connect / Disconnect)
// Input Value  : ucInputPort, enumCcFunction
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerUserCcFunctionControl(BYTE ucInputPort, EnumTypeCCcFunction enumCcFunction)
{
    UserInterfaceTypeCPortControllerUserCcFunctionControl(ucInputPort, enumCcFunction);
}

//--------------------------------------------------
// Description  : Get User Port Controller Power Role
// Input Value  : ucInputPort --> Inputput
// Output Value : EnumTypeCPowerRole (_TYPE_C_POWER_ROLE_NONE / _TYPE_C_POWER_SNK / _TYPE_C_POWER_SRC)
//--------------------------------------------------
EnumTypeCPowerRole UserCommonPortControllerGetUserPowerRole(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerGetUserPowerRole(ucInputPort);
}

//--------------------------------------------------
// Description  : Get User Port Controller Data Role and Return Result
// Input Value  : ucInputPort
// Output Value : EnumTypeCDataRole (_TYPE_C_DATA_ROLE_NONE / _TYPE_C_UFP_U / _TYPE_C_DFP_U)
//--------------------------------------------------
EnumTypeCDataRole UserCommonPortControllerGetUserDataRole(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerGetUserDataRole(ucInputPort);
}

//--------------------------------------------------
// Description  : Set User-Defined Number of PDOs to User Port Ctrl
// Input Value  : ucInputPort, enumPowerRole(Src/Snk PDO), Number of PDO Counts (1~7)
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetUserPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoCnt)
{
    UserInterfaceTypeCPortControllerSetUserPdoCnt(ucInputPort, enumPowerRole, ucPdoCnt);
}

//--------------------------------------------------
// Description  : Set User-Defined Fix Supply/ PPS PDOs to User Port Ctrl
// Input Value  : ucInputPort, enumPowerRole(Src/Snk PDO), ucPdoIndex, stTypeCUserPdo
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetUserPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, StructTypeCUserPDO stTypeCUserPdo)
{
    UserInterfaceTypeCPortControllerSetUserPdo(ucInputPort, enumPowerRole, ucPdoIndex, stTypeCUserPdo);
}

//--------------------------------------------------
// Description  : Set User-Defined RDO to User Port Ctrl
// Input Value  : ucInputPort, stTypeCUserRdo
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetUserRdo(BYTE ucInputPort, StructTypeCUserRDO stTypeCUserRdo)
{
    UserInterfaceTypeCPortControllerSetUserRdo(ucInputPort, stTypeCUserRdo);
}

//--------------------------------------------------
// Description  : Get User Port Controller Number of Src/Snk PDOs
// Input Value  : ucInputPort, enumPowerRole (Src/Snk PDO)
// Output Value : Number of PDO Counts (1~7)
//--------------------------------------------------
EnumTypeCPdoNumber UserCommonPortControllerGetUserPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole)
{
    return UserInterfaceTypeCPortControllerGetUserPdoCnt(ucInputPort, enumPowerRole);
}

//--------------------------------------------------
// Description  : Get User Port Controller Source/Sink PDO Info
// Input Value  : ucInputPort, enumPowerRole (Src/Snk PDO), ucPdoIndex : 1~7
// Output Value : StructTypeCUserPDO (Voltage Unit = 100mV / Current = 10mA)
//--------------------------------------------------
StructTypeCUserPDO UserCommonPortControllerGetUserPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex)
{
    StructTypeCUserPDO stTypeCPdo = {_PD_FIX_SUPPLY_PDO, _PD_PEAK_CUR_NONE, 0x00, 0x00, 0x00};

    UserInterfaceTypeCPortControllerGetUserPdo(ucInputPort, enumPowerRole, ucPdoIndex, &stTypeCPdo);

    return stTypeCPdo;
}

//--------------------------------------------------
// Description  : Get User Port Controller Number of Partner Src/Snk PDOs
// Input Value  : ucInputPort, enumPowerRole (Src/Snk PDO)
// Output Value : Number of PDO Counts (1~7)
//--------------------------------------------------
EnumTypeCPdoNumber UserCommonPortControllerGetUserPartnerPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole)
{
    return UserInterfaceTypeCPortControllerGetUserPartnerPdoCnt(ucInputPort, enumPowerRole);
}

//--------------------------------------------------
// Description  : Get User Port Controller Partner Source/Sink PDO Info
// Input Value  : ucInputPort, enumPowerRole (Src/Snk PDO), ucPdoIndex : 1~7
// Output Value : StructTypeCUserPDO (Voltage Unit = 100mV / Current = 10mA)
//--------------------------------------------------
StructTypeCUserPDO UserCommonPortControllerGetUserPartnerPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex)
{
    StructTypeCUserPDO stTypeCPartnerPdo = {_PD_FIX_SUPPLY_PDO, _PD_PEAK_CUR_NONE, 0x00, 0x00, 0x00};

    UserInterfaceTypeCPortControllerGetUserPartnerPdo(ucInputPort, enumPowerRole, ucPdoIndex, &stTypeCPartnerPdo);

    return stTypeCPartnerPdo;
}

//--------------------------------------------------
// Description  : Get User Port Controller PDO Status
// Input Value  : ucInputPort, *pusVoltage (Unit: 10mV), *pusCurrent (Unit: 10mA)
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerGetUserPdoStatus(BYTE ucInputPort, WORD *pusVoltage, WORD *pusCurrent)
{
    UserInterfaceTypeCPortControllerGetUserPdoStatus(ucInputPort, pusVoltage, pusCurrent);
}

//--------------------------------------------------
// Description  : Get User Port Controller Current Source PDO that Sink Request
// Input Value  : ucInputPort --> Input Port
// Output Value : StructTypeCUserPDO (Voltage Unit = 100mV / Current = 10mA)
//--------------------------------------------------
StructTypeCUserPDO UserCommonPortControllerGetUserRequestedSrcPdo(BYTE ucInputPort)
{
    StructTypeCUserPDO stTypeCSrcPdo = {_PD_FIX_SUPPLY_PDO, _PD_PEAK_CUR_NONE, 0x00, 0x00, 0x00};

    UserInterfaceTypeCPortControllerGetUserRequestedSrcPdo(ucInputPort, &stTypeCSrcPdo);

    return stTypeCSrcPdo;
}

//--------------------------------------------------
// Description  : Ask User Port Controller to Reconnect
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerUserReconnect(BYTE ucInputPort)
{
    if(UserInterfaceTypeCPortControllerReconnect(ucInputPort) == _TYPE_C_USER_PORT_CTRL_COMMUNICATION_SUCCESS)
    {
        return _SUCCESS;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Get User Port Ctrl FW Version and Return Result
// Input Value  : enumTypeCPcbPort --> _D0_TYPE_C_PORT / _D1_TYPE_C_PORT...
//                *pstTypeCFwVersion --> TypeC FW Version
// Output Value : _SUCCESS / _FAIL
//--------------------------------------------------
bit UserCommonPortControllerGetUserFwVersion(BYTE ucInputPort, StructTypeCPortCtrlFwVersion *pstTypeCFwVersion)
{
    if(UserInterfaceTypeCPortControllerGetUserFwVersion(ucInputPort, pstTypeCFwVersion) == _TYPE_C_USER_PORT_CTRL_COMMUNICATION_SUCCESS)
    {
        return _SUCCESS;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Get User Port Ctrl Cable Info for DPCD
// Input Value  : enumTypeCPcbPort --> _D0_TYPE_C_PORT / _D1_TYPE_C_PORT...
// Output Value : Actvie/Passive Cable, DP Max Rate, UHBR13.5 Support
//--------------------------------------------------
StructTypeCCableInfoForDpcd UserCommonPortControllerGetUserCableInfoForDpcd(BYTE ucInputPort)
{
    StructTypeCCableInfoForDpcd stTypeCCableInfoForDpcd = {_PD_CBL_COMPONENT_PASSIVE, _PD_CBL_MAX_DP_RATE_UNCONFIRMED, _FALSE};

    UserInterfaceTypeCPortControllerGetUserCableInfoForDpcd(ucInputPort, &stTypeCCableInfoForDpcd);

    return stTypeCCableInfoForDpcd;
}

//--------------------------------------------------
// Description  : Config Pin Assignment to User Port Controller
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfigUserPinAssignment(BYTE ucInputPort, EnumTypeCPinCfgCapType enumPinAssignment)
{
    if(UserInterfaceTypeCPortControllerConfigUserPinAssignment(ucInputPort, enumPinAssignment) == _TYPE_C_USER_PORT_CTRL_COMMUNICATION_SUCCESS)
    {
        return _SUCCESS;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Config Multi-Function Bit to User Port Controller
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfigUserMultiFunction(BYTE ucInputPort, EnumTypeCMultiFuncStatus enumMultiFunction)
{
    if(UserInterfaceTypeCPortControllerConfigUserMultiFunction(ucInputPort, enumMultiFunction) == _TYPE_C_USER_PORT_CTRL_COMMUNICATION_SUCCESS)
    {
        return _SUCCESS;
    }

    return _FAIL;
}

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
//--------------------------------------------------
// Description  : Get User Port Controller Lenovo Alt Mode Ready Info
// Input Value  : ucInputPort --> Inputput
// Output Value : Lenovo Alt Mode Ready Status (_TYPE_C_LENOVO_ALT_MODE_READY / _TYPE_C_LENOVO_ALT_MODE_NOT_READY)
//--------------------------------------------------
EnumTypeCLenovoAltModeStatus UserCommonPortControllerGetUserLenovoAltModeReady(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerGetUserLenovoAltModeReady(ucInputPort);
}

//--------------------------------------------------
// Description  : Get Port Partner Lenovo Device Type from User Port Controller
// Input Value  : ucInputPort --> Inputput
// Output Value : Lenovo Device Type
//--------------------------------------------------
EnumTypeCLenovoDeviceType UserCommonPortControllerGetUserLenovoDeviceType(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerGetUserLenovoDeviceType(ucInputPort);
}

//--------------------------------------------------
// Description  : Type C Lenovo Alt Mode Set Docking Event
// Input Value  : ucInputPort, stLenovoDockEvent
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetUserLenovoDockingEvent(BYTE ucInputPort, StructTypeCLenovoDockEvent stLenovoDockEvent)
{
    UserInterfaceTypeCPortControllerSetUserLenovoDockingEvent(ucInputPort, stLenovoDockEvent);
}

//--------------------------------------------------
// Description  : Type C Lenovo Alt Mode Get System Event (Including System Acknowledge)
// Input Value  : ucInputPort
// Output Value : StructTypeCLenovoSysEvent
//--------------------------------------------------
StructTypeCLenovoSysEvent UserCommonPortControllerGetUserLenovoSystemEvent(BYTE ucInputPort)
{
    StructTypeCLenovoSysEvent stLenovoSysEvent = {_TYPE_C_LENOVO_SYS_DC_MODE, _TYPE_C_LENOVO_SYS_STATE_NONE, _FALSE, 0x00, 0x00};

    stLenovoSysEvent = UserInterfaceTypeCPortControllerGetUserLenovoSystemEvent(ucInputPort);

    return stLenovoSysEvent;
}

//--------------------------------------------------
// Description  : Type C Lenovo Alt Mode Check if Last Docking Event has been Sent
// Input Value  : ucInputPort
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserCommonPortControllerCheckUserLenovoDockingEventBusy(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerCheckUserLenovoDockingEventBusy(ucInputPort);
}
#endif // End of #if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
#endif // End of #if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
