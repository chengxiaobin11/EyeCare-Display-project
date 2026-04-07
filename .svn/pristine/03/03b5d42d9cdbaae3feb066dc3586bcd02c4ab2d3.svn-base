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
// ID Code      : SysMain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __MAIN__

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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void main(void);
void SysMainSystemInitial(void);
bit SysMainSytemPowerDetect(void);

#if((_DUAL_BANK_SUPPORT == _ON) &&\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _OFF) ||\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) && (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_USER))))
void SysMainStartUserCode(BYTE ucBankAddress);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : The main function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void main(void)
{
    do
    {
        SysMainSystemInitial();

        while(SysMainSytemPowerDetect() == _TRUE)
        {
            UserInterfaceKeyHandler();
            SysPowerHandler();
            SysJudgeHandler();

#if(_AUDIO_SUPPORT == _ON)
            SysAudioHandler();
#endif
            SysTimerHandler();
            SysSourceHandler();
            SysModeHandler();

#if(_MHL_SUPPORT == _ON)
            SysMHLMscHandler();
#endif

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
            SysTypeCHandler();

#endif

#if(_DP_SUPPORT == _ON)
            SysDpRxHandler();
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            SysTMDSRxHandler();

#if(_HDMI_CEC_SUPPORT == _ON)
            SysCecHandler();
#endif
#endif

#if(_DP_TX_SUPPORT == _ON)
            SysDpTxHandler();
#endif

#if(_EMBEDDED_DP_TX_SUPPORT == _ON)
            SysDpEmbeddedTxHandler();
#endif

#if(_DP_MST_SUPPORT == _ON)
            SysDpMstHandler();
#endif

#if(_HDMI_TX_SUPPORT == _ON)
            SysHdmiTxHandler();
#endif

#if(_HDCP_2_2_SUPPORT == _ON)
            ScalerHdcp2Handler();
#endif

#if(_BILLBOARD_SCALER_SUPPORT == _ON)
            ScalerBBHandler();
#endif

#if(_AUTO_TEST_SUPPORT == _ON)
            SysAutotestHandler();
#endif

            UserCommonInterfaceOsdHandler();

#if(_DDCCI_CODE_REDUCTION == _OFF)
            UserCommonDdcciHandler();
#endif
            SysColorHandler();
            ScalerDebug();

#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)
            UserCommonDualBankUserDebug();
#endif
        }
    }
    while(_TRUE);
}

//--------------------------------------------------
// Description  : System AC on initial flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysMainSystemInitial(void)
{
    ScalerMcuInitial();

    ScalerPinshareInitial();
#if((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) &&\
    ((_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_BOOT) ||\
    (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_BOTH)))
#if(_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_BOTH)
    if(GET_CURRENT_BANK_NUMBER() == 0x00)
#endif
    {
        UserCommonDualBankProcess();
    }
#endif
    ScalerTimerInitialTimerEvent();

    UserCommonInterfaceInitial();

    ScalerMcuDdcRamEnable();

    SysSourceInitial();

    SysPowerInitial();

#if(_IR_SUPPORT == _IR_HW_SUPPORT)
    ScalerIRHWModeInitial();
#endif

    SET_POWER_STATUS(_POWER_STATUS_AC_ON);

    if(UserCommonNVRamGetSystemData(_MONITOR_POWER_STATUS) == _ON)
    {
        SET_TARGET_POWER_STATUS(_POWER_STATUS_NORMAL);
    }
    else
    {
        SET_TARGET_POWER_STATUS(_POWER_STATUS_OFF);
    }
    // while (1);

     SET_MODE_STATE(_MODE_STATUS_POWER_OFF);
        // ScalerTimerDelayXms(1000);

}

//--------------------------------------------------
// Description  : System power detect
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit SysMainSytemPowerDetect(void)
{
    return PCB_POWER_5V_DETECT();
}
#if((_DUAL_BANK_SUPPORT == _ON) &&\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _OFF) ||\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) && (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_USER))))
//--------------------------------------------------
// Description  : Switch bank and jump to user code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysMainStartUserCode(BYTE ucBankAddress)
{
#if(_DUAL_BANK_COMPATIBLE_WITH_OLD_BOOT_SUPPORT == _OFF)
    // Set bank offset for user code
    SET_BANK_SWITCH_OFFSET(ucBankAddress);

    // Disable Global INT
    EA = _DISABLE;
#endif

    // Switch current bank
    MCU_FFFF_PBANK_SWITCH = ucBankAddress;

    // The below code is used here to ignore the pre-read code of mcu
    _nop_();
    _nop_();
    _nop_();
    _nop_();

#if((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) && (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_BOTH))
    if(GET_CURRENT_BANK_NUMBER() != 0x00)
#endif
    {
        // Reset FW after switched to user code
        ((void (*)(void))0x0000)();
    }
}
#endif

