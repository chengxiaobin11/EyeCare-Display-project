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
// ID Code      : SysInt.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __SYSTEM_INT__

#include "SysInclude.h"

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
// Backup for Burst Write Bug
BYTE g_ucBackup_EXINT0;
BYTE g_ucBackup_EXINT1;
BYTE g_ucBackup_SERIAL;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysEXINT0(void);
void SysEXINT1(void);
#if(_USB3_RETIMER_SUPPORT == _ON)
void SysEXINT3(void);
#endif
void SysUartSerialPortIntProc(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Interrupt 0 Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysEXINT0(void)    interrupt 0 using 1
{
    // Backup for Burst Write Bug
    g_ucBackup_EXINT0 = MCU_FFF4_SCA_INF_ADDR;

#if(_DP_SUPPORT == _ON)
    if(ScalerDpAuxJudgeHandler_EXINT0() == _TRUE)
    {
        // Reload Backup for Burst Write Bug
        MCU_FFF4_SCA_INF_ADDR = g_ucBackup_EXINT0;

        return;
    }
#endif

#if(_DP_SUPPORT == _ON)
    ScalerDpIntHandler_EXINT0();
#endif

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
    ScalerGlobalPreventGarbageByBacklight_EXINT0();
#endif

#if((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON))
    // DEN_Start
    ScalerODIntHandler_EXINT0();
#endif

#if((_MOTION_BLUR_REDUCTION_SUPPORT == _ON) && (_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
    // DEN_Stop
    ScalerMbrIntHandlerDENStop_EXINT0();
    // DVS
    ScalerMbrIntHandlerDVS_EXINT0();
#endif

#if(_MHL_SUPPORT == _ON)
    ScalerMHLIntHandler_EXINT0();
#endif

#if(_HDCP_2_2_SUPPORT == _ON)
    ScalerHdcp2IntHandler_EXINT0();
#endif

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
    ScalerTypeCIntHandler_EXINT0();
#endif

#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_HDMI_CEC_SUPPORT == _ON)
    ScalerCecIntHandler_EXINT0();
#endif

    if((GET_POWER_STATUS() != _POWER_STATUS_SAVING) && (GET_POWER_STATUS() != _POWER_STATUS_OFF))
    {
        ScalerTMDSIntHandler_EXINT0();
    }
    else
    {
        ScalerTMDSPSIntHandler_EXINT0();
    }

#endif

#if(_PANEL_STYLE == _PANEL_VBO)
    ScalerDisplayVboIntHandler_EXINT0();
#elif(_PANEL_STYLE == _PANEL_DPTX)
#if((_PANEL_DPTX_HPD_DETECT == _ON) && (_PANEL_DPTX_IRQ_HPD_DETECT == _ON))
    ScalerDisplayDPTxIrqIntHandler_EXINT0();
#endif
#endif

#if(_DP_TX_SUPPORT == _ON)
    ScalerDpTxIntHandle_EXINT0();
#endif

#if(_EMBEDDED_DP_TX_SUPPORT == _ON)
    ScalerEmbeddedDpTxIntHandle_EXINT0();
#endif

#if(_IR_SUPPORT == _IR_HW_SUPPORT)
    ScalerIRHWModeIntHandler_EXINT0();
#endif

#if(_LC_TANK_SUPPORT == _ON)
#if(_XTALESS_SUPPORT == _ON)
    ScalerLCTankDpllRegulation_EXINT0();
#endif
#endif

#if(_AUDIO_SUPPORT == _ON)
#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
    ScalerAudioTtsIntHandler_EXINT0();
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
#endif

#if(_DP_SUPPORT == _ON)
    ScalerDpExitIntSetting_EXINT0();
#endif

    // Reload Backup for Burst Write Bug
    MCU_FFF4_SCA_INF_ADDR = g_ucBackup_EXINT0;
}

//--------------------------------------------------
// Description  : Interrupt 1 Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysEXINT1(void)    interrupt 2 using 2
{
    // Backup for Burst Write Bug
    g_ucBackup_EXINT1 = MCU_FFF4_SCA_INF_ADDR;

    // User Case for adding EXT_INT1 function
#if(_EXT_INT1_SUPPORT == _ON)
    if((MCU_FFB9_EXT_INT1_CONTROL & _BIT3) == _BIT3)
    {
        // Clear int1_status flag
        MCU_FFB9_EXT_INT1_CONTROL |= _BIT3;
        UserInterfaceEXTINT1Handler_EXINT1();
    }
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    ScalerSyncDdcDetect_EXINT1();
#endif

#if(_FW_UPDATE_PROCESS_SUPPORT == _ON)
    if((bit)UserCommonFwUpdateGetStatus_EXINT1() == _TRUE)
    {
        UserCommonFwUpdateIntProc_EXINT1();
    }
#if(_FW_UPDATE_DDCCI_SEL == _FW_UPDATE_SEL_DDCCI0)
    else
#endif
#endif
    {
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
        ScalerDebugIntProc_EXINT1();
#else

#if(_DDCCI_CODE_REDUCTION == _OFF)
        if((bit)UserCommonInterfaceGetDdcciStatus_EXINT1() == _TRUE)
        {
            UserCommonInterfaceDdcciIntGetData_EXINT1();
        }
        else
#endif
        {
            ScalerDebugIntProc_EXINT1();
        }
#endif
    }

#if(_AUTO_TEST_SUPPORT == _ON)
    SysAutotestIntProc_EXINT1();
#endif

    // Reload Backup for Burst Write Bug
    MCU_FFF4_SCA_INF_ADDR = g_ucBackup_EXINT1;
}

#if(_USB3_RETIMER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Interrupt 3 Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysEXINT3(void)    interrupt 9
{
    ScalerUSB3RetimerIntHandler_EXINT3();

    EXIF &= ~_BIT5;

    MCU_FFC2_IRQ_PRIORITY_1 = ((MCU_FFC2_IRQ_PRIORITY_1 & ~(_BIT7 | _BIT6)) | 0x00);
    MCU_FFC2_IRQ_PRIORITY_1 = ((MCU_FFC2_IRQ_PRIORITY_1 & ~(_BIT7 | _BIT6)) | _BIT7);
}
#endif

//--------------------------------------------------
// Description  : Serial Port0 Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysUartSerialPortIntProc(void)    interrupt 4
{
    // Backup for Burst Write Bug
    g_ucBackup_SERIAL = MCU_FFF4_SCA_INF_ADDR;

#if(_UART_SUPPORT == _ON)
    if(GET_UART_TRANSMIT_STATUS() == _TRUE)
    {
        CLR_UART_TRANSMIT_STATUS();
    }

    UserInterfaceUartIntHandler_SERIALPORT();
#endif

    // Reload Backup for Burst Write Bug
    MCU_FFF4_SCA_INF_ADDR = g_ucBackup_SERIAL;
}

