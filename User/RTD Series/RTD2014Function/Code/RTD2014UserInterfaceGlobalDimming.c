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
// ID Code      : RTD2014UserInterfaceLocalDimming.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_INTERFACE_GLOBAL_DIMMING__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _REALTEK_2014_OSD) && (_GLOBAL_DIMMING_SUPPORT == _ON))

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
void UserInterfaceGlobalDimmingAdjustPWM(WORD usPWMValue);
void UserInterfaceGlobalDimmingAdjustPCM(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : 0~ 2048
// Output Value :
//--------------------------------------------------
void UserInterfaceGlobalDimmingAdjustPWM(WORD usPWMValue)
{
    WORD usNormPWM = 0;
#if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)
    usNormPWM = ((DWORD)usPWMValue * _DEVICE_LED_DRIVER_PWM_MAX) / _GD_PANEL_PWM_MAX;
    ExternalDeviceInterfaceLedDriverPwm(_PANEL_PWM_LOCAL_ALL, usNormPWM, _DEVICE_CALI_OFF);
#else
    usNormPWM = ((DWORD)usPWMValue * _BACKLIGHT_MAX) / _GD_PANEL_PWM_MAX;
    // Adjust backlight by changing PWM duty
    PCB_BACKLIGHT_PWM(usNormPWM);
#endif
}

//--------------------------------------------------
// Description  : Adjust PCM in Global Dimming Mode
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void UserInterfaceGlobalDimmingAdjustPCM(void)
{
#if(_SDR_TO_HDR_SUPPORT == _ON)

    UserAdjustSDRToHDR(GET_OSD_SDR_TO_HDR());

#else

#if(_PCM_FUNCTION == _ON)
    UserAdjustPCM(GET_OSD_PCM_STATUS());
#endif

#endif
}

//--------------------------------------------------
// Description  : Get Global Dimming OSD Status
// Input Value  : void
// Output Value : _GD_ENABLE or _GD_DISABLE
//--------------------------------------------------
EnumGDStatus UserInterfaceGetGlobalDimmingStatus(void)
{
    return _GD_ENABLE;
}
#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_Global_DIMMING_SUPPORT == _ON))

