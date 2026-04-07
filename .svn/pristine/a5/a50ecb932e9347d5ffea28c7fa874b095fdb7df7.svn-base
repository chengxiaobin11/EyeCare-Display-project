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
// ID Code      : ExternalDeviceLedDriverInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
typedef enum
{
    _DEVICE_LED_DRIVER_PWM_1,
    _DEVICE_LED_DRIVER_PWM_2,
    _DEVICE_LED_DRIVER_PWM_3,
    _DEVICE_LED_DRIVER_PWM_4,
    _DEVICE_LED_DRIVER_PWM_5,
    _DEVICE_LED_DRIVER_PWM_6,
    _DEVICE_LED_DRIVER_PWM_7,
    _DEVICE_LED_DRIVER_PWM_8,
    _DEVICE_LED_DRIVER_PWM_9,
    _DEVICE_LED_DRIVER_PWM_10,
    _DEVICE_LED_DRIVER_PWM_11,
    _DEVICE_LED_DRIVER_PWM_12,
    _DEVICE_LED_DRIVER_PWM_13,
    _DEVICE_LED_DRIVER_PWM_14,
    _DEVICE_LED_DRIVER_PWM_15,
    _DEVICE_LED_DRIVER_PWM_16,
    _DEVICE_LED_DRIVER_PWM_ALL,
    _DEVICE_LED_DRIVER_PWM_NONE = 0xFF,
} EnumDeviceLedDriverPwm;

typedef enum
{
    _DEVICE_CALI_ON,
    _DEVICE_CALI_OFF,
} EnumDeviceLedCalibrationUse;

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_LD_HDR10_BOOST_SUPPORT == _ON)
extern bit g_bHdrBoost;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_DEBUG_IIC_BY_USERINTERFACE == _ON)
extern bit ExternalDeviceInterfaceLedDriverDebug(BYTE ucType, BYTE *pucDdcciArray, BYTE *pucReturnValue);
#endif
extern void ExternalDeviceInterfaceLedDriverInitial(void);
extern void ExternalDeviceInterfaceLedDriverPwmEnable(bit bEnable);
extern void ExternalDeviceInterfaceLedDriverPwm(EnumDeviceLedDriverPwm enumDeviceLedDriverPwm, WORD usValue, EnumDeviceLedCalibrationUse enumcaliUse);
extern void ExternalDeviceInterfaceLedDriverBacklight(WORD usBacklight);
#if(_LD_HDR10_BOOST_SUPPORT == _ON)
extern void ExternalDeviceInterfaceLedDriverPwmArrayBoostMode(WORD *pusValue, BYTE ucBoostGain);
#else
extern void ExternalDeviceInterfaceLedDriverPwmArray(WORD *pusValue);
#endif
#endif // End of #if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)

