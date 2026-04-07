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
// ID Code      : ScalerTMDSRx1_SeptPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
StructHdmiSpdInfo g_stTmdsMacRx1SpdInfo;
#endif

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D1_TMDS_SUPPORT == _ON)
void ScalerTMDSRx1FirstActiveProc(BYTE ucSourceType);
void ScalerTMDSRx1SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
EnumDeOnlyConfig ScalerTMDSRx1GetDeOnlyModeConfig(void);
void ScalerTMDSRx1PowerOffProc(void);
void ScalerTMDSRx1TMDSVideoDetectEvent(void);

#if(_D1_HDMI_SUPPORT == _ON)
bit ScalerTMDSRx1HdmiAviPixelRepInfoChanged(void);
bit ScalerTMDSRx1HdmiDeepColorProc(WORD usTmdsClkCnt);
void ScalerTMDSRx1HdmiPacketDetectEvent(void);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
void ScalerTMDSRx1SpdInfoPacketDetect(bit bWait);
void ScalerTMDSRx1HdmiGetSpdInfo(void);
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
void ScalerTMDSRx1Hdmi2FormatResetEvent(void);
void ScalerTMDSRx1ScrambleStatusReset(void);
void ScalerTMDSRx1ScrambleDetectTimeoutTimerEvent(void);
void ScalerTMDSRx1ScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
void ScalerTMDSRx1SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
void ScalerTMDSRx1SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
#endif

#endif

void ScalerTMDSRx1HotPlugLowProc(void);
void ScalerTMDSRx1HotPlugHighProc(WORD usHpdTime);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D1_TMDS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1FirstActiveProc(BYTE ucSourceType)
{
    ucSourceType = ucSourceType;
}

//--------------------------------------------------
// Description  : Set Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : enumInputPort, enumDeonlyConfig
//--------------------------------------------------
void ScalerTMDSRx1SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig)
{
    // De only enable?
    if((enumDeonlyConfig & _DE_ONLY_DISABLE) == _DE_ONLY_DISABLE)
    {
        ScalerSetBit(P71_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
    }
    else if((enumDeonlyConfig & _DE_ONLY_ENABLE) == _DE_ONLY_ENABLE)
    {
        ScalerSetBit(P71_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
    }

    // Set HS
    if((enumDeonlyConfig & _DE_ONLY_HS_8T) == _DE_ONLY_HS_8T)
    {
        ScalerSetBit(P71_AB_TMDS_ACC2, ~_BIT7, _BIT7);
    }
    else if((enumDeonlyConfig & _DE_ONLY_HS_72T) == _DE_ONLY_HS_72T)
    {
        ScalerSetBit(P71_AB_TMDS_ACC2, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Get Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : EnumDeOnlyConfig
//--------------------------------------------------
EnumDeOnlyConfig ScalerTMDSRx1GetDeOnlyModeConfig(void)
{
    EnumDeOnlyConfig enumDeConfig = _DE_NO_INDICATED;

    if(ScalerGetBit(P71_A7_TMDS_PWDCTL, _BIT7) == _BIT7)
    {
        enumDeConfig = _DE_ONLY_ENABLE;
    }
    else
    {
        enumDeConfig = _DE_ONLY_DISABLE;
    }

    if(ScalerGetBit(P71_AB_TMDS_ACC2, _BIT7) == _BIT7)
    {
        enumDeConfig |= _DE_ONLY_HS_8T;
    }
    else
    {
        enumDeConfig |= _DE_ONLY_HS_72T;
    }

    return enumDeConfig;
}

//--------------------------------------------------
// Description  : TMDS Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1PowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_FFE5_DDC1_EDID_IRQ = ((MCU_FFE5_DDC1_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));

    ScalerTMDSRx1FreqDetectDisable();

#if(_D1_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx1ScrambleDetectDisable();
#endif
}
//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1TMDSVideoDetectEvent(void)
{
    CLR_TMDS_RX1_RGBHV_DETECTING();
}

#if(_D1_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect HDMI AVI pixel repetition
// Input Value  : None
// Output Value : _TRUE => Current Info is different from previous setting
//--------------------------------------------------
bit ScalerTMDSRx1HdmiAviPixelRepInfoChanged(void)
{
    // Check Tmds Pixel Repetition
    if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION) != GET_TMDS_RX1_AVI_PIXEL_REPETITION())
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : HDMI Deep Color Proc
// Input Value  : void
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerTMDSRx1HdmiDeepColorProc(WORD usTmdsClkCnt)
{
    // Setting Deep Color PLL
    if(ScalerTMDSRx1HdmiSetDeepColorPll(usTmdsClkCnt, GET_COLOR_DEPTH()) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for Phase lock
    if(ScalerTMDSRx1HdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1HdmiPacketDetectEvent(void)
{
    CLR_HDMI_RX1_PACKET_DETECTING();
}

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI SPD Info Frame Packet Detect
// Input Value  : bWait
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1SpdInfoPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for RSV4 received check
        if(ScalerTimerPollingDataBitFlagProc(130, P71_C9_HDMI_AP, _P71_CA_PT_00_PORT_PAGE71_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
        {
            ScalerTMDSRx1HdmiGetSpdInfo();
        }
    }
    else
    {
        // Check RSV4 received bit
        if(ScalerGetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_00_PORT_PAGE71_HDMI_SCR, _BIT7) == _BIT7)
        {
            ScalerTMDSRx1HdmiGetSpdInfo();
        }
    }
}

//--------------------------------------------------
// Description  : Get SPD Info Product Description
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1HdmiGetSpdInfo(void)
{
    BYTE pucHdmiVenderName[4] = {0};

    ScalerGetDataPortByte(P71_CD_HDMI_PSAP, 0x90, 4, &pucHdmiVenderName[0], _AUTOINC);

    if(((pucHdmiVenderName[0] == 'M') || (pucHdmiVenderName[0] == 'S')) &&
       ((pucHdmiVenderName[1] == 'S') || (pucHdmiVenderName[1] == 'C')) &&
       ((pucHdmiVenderName[2] == 'F') || (pucHdmiVenderName[2] == 'E')) &&
       ((pucHdmiVenderName[3] == 'T') || (pucHdmiVenderName[3] == 'I')))
    {
        g_stTmdsMacRx1SpdInfo.b1StructValuable = 0x01;
        memcpy(&g_stTmdsMacRx1SpdInfo.pucHdmiVendorName[0], pucHdmiVenderName, 4);

        ScalerGetDataPortByte(P71_CD_HDMI_PSAP, 0x98, 8, &g_stTmdsMacRx1SpdInfo.pucHdmiProductDescription[0], _AUTOINC);
    }
}
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Format Reset Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1Hdmi2FormatResetEvent(void)
{
    CLR_TMDS_RX1_HDMI_2_0_FORMAT_RESET_WAITING();
}

//--------------------------------------------------
// Description  : Scramble Status Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1ScrambleStatusReset(void)
{
    // Set Scramble Detect Manual Mode
    ScalerSetBit(P71_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), 0x00);

    // Disable Scrambling Status
    ScalerSetDataPortBit(P71_39_HDMI_CTRL_39, _P71_3A_PT_21_PORT_PAGE71_HDMI_SCDC_21, ~_BIT0, 0x00);

    // Clear Scrambling Detection Flag
    ScalerSetBit(P71_01_HDMI_CTRL_01, ~_BIT3, _BIT3);

    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX1_HDMI2_SCRAMBLE_DETECT_TIMEOUT);
}

//--------------------------------------------------
// Description  : Scramble Detect timeout event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1ScrambleDetectTimeoutTimerEvent(void)
{
    // Set Scramble Detect Auto Mode
    ScalerSetBit(P71_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), _BIT4);

    ScalerTMDSRx1ScrambleDetectDisable();
}

//--------------------------------------------------
// Description  : TMDS Scramble Detection IRQ Disable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1ScrambleDetectDisable(void)
{
    // Disable SCDC 0x20 Change IRQ
    ScalerSetBit(P71_26_HDMI_CTRL_26, ~_BIT4, 0x00);
}

#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Set SCDC Info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1SetScdcInfo_EXINT0(void) using 1
{
    // Set SCDC Info
    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D0_PORT_PAGE71_HDMI_SCDC_D0);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D1_PORT_PAGE71_HDMI_SCDC_D1);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D2_PORT_PAGE71_HDMI_SCDC_D2);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D3_PORT_PAGE71_HDMI_SCDC_D3);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D4_PORT_PAGE71_HDMI_SCDC_D4);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D5_PORT_PAGE71_HDMI_SCDC_D5);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D6_PORT_PAGE71_HDMI_SCDC_D6);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D7_PORT_PAGE71_HDMI_SCDC_D7);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D8_PORT_PAGE71_HDMI_SCDC_D8);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_D9_PORT_PAGE71_HDMI_SCDC_D9);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_DA_PORT_PAGE71_HDMI_SCDC_DA);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_DB_PORT_PAGE71_HDMI_SCDC_DB);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_DC_PORT_PAGE71_HDMI_SCDC_DC);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);

    ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_DD_PORT_PAGE71_HDMI_SCDC_DD);
    ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Set AMD AUPI SCDC Info
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx1SetAmdAupiScdcInfo_EXINT0(bit bEnable) using 1
{
    if(GET_FREESYNC_HDMI_AUPI_INFO() != _TRUE)
    {
        return;
    }

    if(bEnable == _ENABLE)
    {
        // Set SCDC Info
        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);
    }
    else
    {
        // Set SCDC Info
        // Set SCDC Info
        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P71_3A_HDMI_CTRL_3A, 0x00);
    }
}
#endif
#endif
#endif
#endif

//--------------------------------------------------
// Description  : HPD Low Process
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx1HotPlugLowProc(void)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE))
#endif
    {
        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
        if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() != _TMDS_HPD_EIZO_PS_WAKEUP)
#endif
        {
            ScalerTMDSRx1SwitchHdcpSlaveAddr();
        }

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
        g_ucTmdsD1DdcramNackStatus = ScalerSyncGetDdcForceNackStatus(_D1_INPUT_PORT);

        if(g_ucTmdsD1DdcramNackStatus == _FALSE)
        {
            // DDCRAM Force Nack
            ScalerSyncSetDdcForceNack(_D1_INPUT_PORT, _ON);
        }

        // Set DDCCI Force Nack
        ScalerMcuDdcciEnable(_DISABLE, _D1_INPUT_PORT);
#endif
    }
}

//--------------------------------------------------
// Description  : HPD High Process
// Input Value  : usHpdTime
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx1HotPlugHighProc(WORD usHpdTime)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE))
#endif
    {
        ScalerTimerDelayXms(usHpdTime);

        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
    }
}
#endif
