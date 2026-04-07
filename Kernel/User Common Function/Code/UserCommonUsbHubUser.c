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
// ID Code      : UserCommonUsbHubUser.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_USBUSER__

#include "UserCommonInclude.h"

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if(_USB_HUB_USERDECITION_SUPPORT == _ON)
#if(_DP_TYPE_C_HUB_COMMUNICATION_SUPPORT == _ON)

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
bit UserCommonUsbHubSetSSMode(BYTE ucInputPort, bit bEn);
EnumHubDspDetectStatus UserCommonUsbHubDetectDFPStatus(BYTE ucInputPort);
WORD UserCommonUsbHubSetPollingStep(BYTE ucInputPort);

#if(_BILLBOARD_HUB_SUPPORT == _ON)
void UserCommonUsbHubBillboardControl(BYTE ucInputPort, EnumBillboardCtrl enumAtion);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set 5411 into SS Mode
// Input Value  : None
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonUsbHubSetSSMode(BYTE ucInputPort, bit bEn)
{
    return UserInterfaceTypeCUsbHubSetSSMode(ucInputPort, bEn);
}

//--------------------------------------------------
// Description  : Detect 5411 SS Device Plug In
// Input Value  : ucInputPort --> Input Port
// Output Value : Return SS Device Info.
//--------------------------------------------------
EnumHubDspDetectStatus UserCommonUsbHubDetectDFPStatus(BYTE ucInputPort)
{
    return UserInterfaceTypeCUsbHubDetectDFPStatus(ucInputPort);
}

//--------------------------------------------------
// Description  : User Set Usb Hub Polling SS Device Step
// Input Value  : ucInputPort --> Input Port
// Output Value : Usb Hub Polling Step Par.
//--------------------------------------------------
WORD UserCommonUsbHubSetPollingStep(BYTE ucInputPort)
{
    return UserInterfaceTypeCUsbHubSetPollingStep(ucInputPort);
}

#if(_BILLBOARD_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : For User Hub to Control Billboard
// Input Value  : enumAtion : _TYPE_C_BB_DISABLE / _TYPE_C_BB_ENABLE
// Output Value : None
//--------------------------------------------------
void UserCommonUsbHubBillboardControl(BYTE ucInputPort, EnumBillboardCtrl enumAtion)
{
    // Call User Function for User to Enable / Disable Hub Billboard
    UserInterfaceTypeCUsbHubBillboardControl(ucInputPort, enumAtion);
}
#endif // End of #if(_BILLBOARD_HUB_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_HUB_COMMUNICATION_SUPPORT == _ON)
#endif // End of #if(_USB_HUB_USERDECITION_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
