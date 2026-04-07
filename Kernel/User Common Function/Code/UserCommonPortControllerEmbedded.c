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
// ID Code      : UserCommonPortControllerEmbedded.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_PORTCONTROLLEREMBEDDED__

#include "UserCommonInclude.h"

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)

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
#if(_USB3_RETIMER_SUPPORT == _ON)
EnumUSBPSSupportStatus UserCommonPortControllerGetUsbPSStatus(void);
EnumUSBPDSupportStatus UserCommonPortControllerGetUsbPDStatus(void);
#endif
#if(_DP_USB_HUB_SUPPORT == _ON)
EnumHubInputPort UserCommonPortControllerGetHubInputPort(BYTE ucInputPort);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_USB3_RETIMER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get USB3 Retimer PS Support Status
// Input Value  : void
// Output Value : EnumUSBPDSupportStatus
//--------------------------------------------------
EnumUSBPSSupportStatus UserCommonPortControllerGetUsbPSStatus(void)
{
    // Set USB Power Saving Status for Retimer Power Switch Use
    ScalerUSB3RetimerSetPSStatus(UserInterfaceGetUSBPSSupportStatus());

    return ScalerUSB3RetimerGetPSStatus();
}

//--------------------------------------------------
// Description  : Get USB3 Retimer PS Support Status
// Input Value  : void
// Output Value : EnumUSBPDSupportStatus
//--------------------------------------------------
EnumUSBPDSupportStatus UserCommonPortControllerGetUsbPDStatus(void)
{
    // Set USB Power Off Status for Retimer Power Switch Use
    ScalerUSB3RetimerSetPDStatus(UserInterfaceGetUSBPDSupportStatus());

    return ScalerUSB3RetimerGetPDStatus();
}
#endif

#if(_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Return Hub Input Port to Kernel
// Input Value  : ucInputPort
// Output Value : EnumHubInputPort
//--------------------------------------------------
EnumHubInputPort UserCommonPortControllerGetHubInputPort(BYTE ucInputPort)
{
    EnumHubInputPort enumHubInputPort = _HUB_UFP_TYPE_C_INPUT_PORT;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_USB_HUB_TYPE != _USB_HUB_NONE)
        case _D0_INPUT_PORT:

            enumHubInputPort = UserInterfaceTypeCHubInputPort(_D0_INPUT_PORT);

            break;
#endif

        default:

            break;
    }

    return enumHubInputPort;
}
#endif
#endif // End of #if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
