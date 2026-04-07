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
// ID Code      : ScalerTMDSRx5_SeptPhy.c No.0000
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
StructHdmiSpdInfo g_stTmdsMacRx5SpdInfo;
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
#if(_D5_TMDS_SUPPORT == _ON)
void ScalerTMDSRx5DviVideoSetting(void);
void ScalerTMDSRx5FirstActiveProc(BYTE ucSourceType);
void ScalerTMDSRx5SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
EnumDeOnlyConfig ScalerTMDSRx5GetDeOnlyModeConfig(void);
void ScalerTMDSRx5PowerOffProc(void);
void ScalerTMDSRx5SetPorchColor(EnumColorSpace enumColorFormat);
BYTE ScalerTMDSRx5TMDSVideoDetect(bit bWait);
void ScalerTMDSRx5TMDSVideoDetectEvent(void);

#if(_D5_HDMI_SUPPORT == _ON)
bit ScalerTMDSRx5HdmiAviPixelRepInfoChanged(void);
bit ScalerTMDSRx5HdmiDeepColorProc(WORD usTmdsClkCnt);
BYTE ScalerTMDSRx5HdmiGetAVIInfo(EnumAviInfoContent enumContent);
BYTE ScalerTMDSRx5HdmiGetColorDepth(void);
void ScalerTMDSRx5HdmiPacketDetect(bit bWait);
void ScalerTMDSRx5HdmiPacketDetectEvent(void);
bit ScalerTMDSRx5HdmiWaitDeepColorPllLock(void);
void ScalerTMDSRx5HdmiWatchDog(BYTE ucWDType, bit bEnable);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
void ScalerTMDSRx5SpdInfoPacketDetect(bit bWait);
void ScalerTMDSRx5HdmiGetSpdInfo(void);
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
void ScalerTMDSRx5ScrambleStatusReset(void);
void ScalerTMDSRx5ScrambleDetectTimeoutTimerEvent(void);
void ScalerTMDSRx5ScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
void ScalerTMDSRx5SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
void ScalerTMDSRx5SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
#endif
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
bit ScalerTMDSRx5TMDSNormalPreDetect(void);
bit ScalerTMDSRx5TMDSPSPreDetect(void);
#endif

void ScalerTMDSRx5HotPlugLowProc(void);
void ScalerTMDSRx5HotPlugHighProc(WORD usHpdTime);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D5_TMDS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5DviVideoSetting(void)
{
    // Manual Set Color Space and disable pixel repetition
    ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable Down Sampling
    ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_50_PORT_PAGE74_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Waiting for Down Sampling Effect
    ScalerTimerDelayXms(20);

    SET_COLOR_SPACE(_COLOR_SPACE_RGB);
    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

    ScalerTMDSRx5SetPorchColor(GET_COLOR_SPACE());
}
//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5FirstActiveProc(BYTE ucSourceType)
{
    ucSourceType = ucSourceType;
}

//--------------------------------------------------
// Description  : Set Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : enumInputPort, enumDeonlyConfig
//--------------------------------------------------
void ScalerTMDSRx5SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig)
{
    // De only enable?
    if((enumDeonlyConfig & _DE_ONLY_DISABLE) == _DE_ONLY_DISABLE)
    {
        ScalerSetBit(P74_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
    }
    else if((enumDeonlyConfig & _DE_ONLY_ENABLE) == _DE_ONLY_ENABLE)
    {
        ScalerSetBit(P74_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
    }

    // Set HS
    if((enumDeonlyConfig & _DE_ONLY_HS_8T) == _DE_ONLY_HS_8T)
    {
        ScalerSetBit(P74_AB_TMDS_ACC2, ~_BIT7, _BIT7);
    }
    else if((enumDeonlyConfig & _DE_ONLY_HS_72T) == _DE_ONLY_HS_72T)
    {
        ScalerSetBit(P74_AB_TMDS_ACC2, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Get Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : EnumDeOnlyConfig
//--------------------------------------------------
EnumDeOnlyConfig ScalerTMDSRx5GetDeOnlyModeConfig(void)
{
    EnumDeOnlyConfig enumDeConfig = _DE_NO_INDICATED;

    if(ScalerGetBit(P74_A7_TMDS_PWDCTL, _BIT7) == _BIT7)
    {
        enumDeConfig = _DE_ONLY_ENABLE;
    }
    else
    {
        enumDeConfig = _DE_ONLY_DISABLE;
    }

    if(ScalerGetBit(P74_AB_TMDS_ACC2, _BIT7) == _BIT7)
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
void ScalerTMDSRx5PowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_FE84_DDC5_EDID_IRQ = ((MCU_FE84_DDC5_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));

    ScalerTMDSRx5FreqDetectDisable();

#if(_D5_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx5ScrambleDetectDisable();
#endif
}
//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5SetPorchColor(EnumColorSpace enumColorFormat)
{
    // Manual Set Background Color Enable
    ScalerSetBit(P74_B9_TMDS_OUT_CTRL, ~_BIT7, 0x00);

    if((enumColorFormat == _COLOR_SPACE_YCBCR444) || (enumColorFormat == _COLOR_SPACE_YCBCR422))
    {
        ScalerSetByte(P74_BA_TMDS_ROUT_HIGH_BYTE, 0x80);
        ScalerSetByte(P74_BB_TMDS_ROUT_LOW_BYTE, 0x00);
        ScalerSetByte(P74_BC_TMDS_GOUT_HIGH_BYTE, 0x10);
        ScalerSetByte(P74_BD_TMDS_GOUT_LOW_BYTE, 0x00);
        ScalerSetByte(P74_BE_TMDS_BOUT_HIGH_BYTE, 0x80);
        ScalerSetByte(P74_BF_TMDS_BOUT_LOW_BYTE, 0x00);
    }
    else
    {
        ScalerSetByte(P74_BA_TMDS_ROUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P74_BB_TMDS_ROUT_LOW_BYTE, 0x00);
        ScalerSetByte(P74_BC_TMDS_GOUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P74_BD_TMDS_GOUT_LOW_BYTE, 0x00);
        ScalerSetByte(P74_BE_TMDS_BOUT_HIGH_BYTE, 0x00);
        ScalerSetByte(P74_BF_TMDS_BOUT_LOW_BYTE, 0x00);
    }
}
//--------------------------------------------------
// Description  : Detect TMDS video mode
// Input Value  : bWait => Whether to wait then read
// Output Value : TMDS video type
//--------------------------------------------------
BYTE ScalerTMDSRx5TMDSVideoDetect(bit bWait)
{
    BYTE ucTemp = _TMDS_VIDEO_DATA_NONE;

    if(bWait == _WAIT)
    {
        // Wait at least 1 frame for HW auto update TMDS video RGBHV valid value
        ScalerTimerPollingFlagProc(45, P74_A4_TMDS_CTRL, _BIT3, _TRUE);

        // Wait for HW update DE flag
        if(ScalerTimerPollingFlagProc(20, P74_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // H/Vsync received
            if(ScalerGetBit(P74_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }

        CLR_TMDS_RX5_RGBHV_DETECTING();

        return ucTemp;
    }
    else
    {
        // R/G/B data detected
        if(ScalerGetBit(P74_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P74_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }

        // Clear video Detection Flag
        ScalerSetBit(P74_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        SET_TMDS_RX5_RGBHV_DETECTING();

        // Activate TMDS video Detection Event
        ScalerTimerActiveTimerEvent(45, _SCALER_TIMER_EVENT_RX5_TMDS_VIDEO_DETECT);

        return ucTemp;
    }
}
//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5TMDSVideoDetectEvent(void)
{
    CLR_TMDS_RX5_RGBHV_DETECTING();
}

#if(_D5_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect HDMI AVI pixel repetition
// Input Value  : None
// Output Value : _TRUE => Current Info is different from previous setting
//--------------------------------------------------
bit ScalerTMDSRx5HdmiAviPixelRepInfoChanged(void)
{
    // Check Tmds Pixel Repetition
    if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION) != GET_TMDS_RX5_AVI_PIXEL_REPETITION())
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
bit ScalerTMDSRx5HdmiDeepColorProc(WORD usTmdsClkCnt)
{
    // Setting Deep Color PLL
    if(ScalerTMDSRx5HdmiSetDeepColorPll(usTmdsClkCnt, GET_COLOR_DEPTH()) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for Phase lock
    if(ScalerTMDSRx5HdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSRx5HdmiGetAVIInfo(EnumAviInfoContent enumContent)
{
    if(GET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _AVI_INFO_COLOR_SPACE:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x04, (_BIT6 | _BIT5)) >> 5);

            case _AVI_INFO_COLORIMETRY:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x05, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_EXTENDED_COLORIMETRY:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x06, (_BIT6 | _BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_RGB_QUANTIZATION:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x06, (_BIT3 | _BIT2)) >> 2);

            case _AVI_INFO_YCC_QUANTIZATION:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x08, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_SCAN_INFO:

                return ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x04, (_BIT1 | _BIT0));

            case _AVI_INFO_IT_CONTENT:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x06, _BIT7) >> 7);

            case _AVI_INFO_PIXEL_REPETITION:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x08, (_BIT3 | _BIT2 | _BIT1 | _BIT0)));

            case _AVI_INFO_AR:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x05, (_BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_VIC:

                return (ScalerGetDataPortBit(P74_CD_HDMI_PSAP, 0x07, (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));

            default:

                break;
        }
    }

    return 0xFF;
}
//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : Received Color Depth
//--------------------------------------------------
BYTE ScalerTMDSRx5HdmiGetColorDepth(void)
{
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        return _COLOR_DEPTH_12_BITS;
    }

    if(GET_HDMI_RX5_GCP_RECEIVED() == _TRUE)
    {
        if(ScalerGetBit(P74_B4_TMDS_DPC0, 0x07) == 0x05)
        {
            return _COLOR_DEPTH_10_BITS;
        }
        else if(ScalerGetBit(P74_B4_TMDS_DPC0, 0x07) == 0x06)
        {
            return _COLOR_DEPTH_12_BITS;
        }
        else if(ScalerGetBit(P74_B4_TMDS_DPC0, 0x07) == 0x07)
        {
            return _COLOR_DEPTH_16_BITS;
        }
    }

    return _COLOR_DEPTH_8_BITS;
}
//--------------------------------------------------
// Description  : Detect HDMI Info Frame
// Input Value  : bWait => Whether to wait then read
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5HdmiPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingFlagProc(130, P74_CC_HDMI_GPVS, (_BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // Both GCP & AVI infoframe packet have been received
            if(ScalerGetBit(P74_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == (_BIT6 | _BIT5))
            {
                SET_HDMI_RX5_GCP_RECEIVED();

                SET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();
            }
            // Only AVI infoframe packet have been received
            else if(ScalerGetBit(P74_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT5)
            {
                SET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();

                // Polling more time to wait GCP when AVI IF has been received.
                if(ScalerTimerPollingFlagProc(180, P74_CC_HDMI_GPVS, _BIT6, _TRUE) == _TRUE)
                {
                    SET_HDMI_RX5_GCP_RECEIVED();
                }
                else
                {
                    CLR_HDMI_RX5_GCP_RECEIVED();
                }
            }
            // Only GCP Packet have been received
            else if(ScalerGetBit(P74_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT6)
            {
                SET_HDMI_RX5_GCP_RECEIVED();

                // Polling more time to wait AVI IF when GCP has been received.
                if(ScalerTimerPollingFlagProc(180, P74_CC_HDMI_GPVS, _BIT5, _TRUE) == _TRUE)
                {
                    SET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();
                }
                else
                {
                    CLR_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();
                }
            }
        }
        // Neither AVI infoframe nor GCP packet received
        else
        {
            CLR_HDMI_RX5_GCP_RECEIVED();

            CLR_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();
        }

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_II_SUPPORT == _OFF) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
        // Polling 3 frame for detect Packet signals
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerTimerPollingDataBitFlagProc(130, P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7, _TRUE) == _TRUE))
#else
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingDataBitFlagProc(130, P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
#endif
        {
            SET_TMDS_RX5_SPD_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_TMDS_RX5_SPD_INFO_FRAME_RECEIVED();
        }
#endif

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
        ScalerTMDSRx5SpdInfoPacketDetect(_WAIT);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingDataBitFlagProc(130, P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT6, _TRUE) == _TRUE)
        {
            SET_HDMI_RX5_HDR10_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_HDMI_RX5_HDR10_INFO_FRAME_RECEIVED();
        }
#endif

        // Wait at least 3 frame for HW auto update color depth value
        ScalerTimerDelayXms(130);

        CLR_HDMI_RX5_PACKET_DETECTING();
    }
    else
    {
        if(ScalerGetBit(P74_CC_HDMI_GPVS, _BIT6) == _BIT6)
        {
            ScalerTMDSRx5HdmiWatchDog(_HDMI_AV_MUTE_WD, _ENABLE);

            SET_HDMI_RX5_GCP_RECEIVED();

            // Clear Detection Flag
            ScalerSetBit(P74_CC_HDMI_GPVS, ~(_BIT6 | _BIT5), _BIT6);
        }
        else
        {
            ScalerTMDSRx5HdmiWatchDog(_HDMI_AV_MUTE_WD, _DISABLE);

            CLR_HDMI_RX5_GCP_RECEIVED();
        }

        if(ScalerGetBit(P74_CC_HDMI_GPVS, _BIT5) == _BIT5)
        {
            // Color Space Auto/ Pixel Repetition auto mode
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

            ScalerTMDSRx5HdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _ENABLE);

            SET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();

            // Clear Detection Flag
            ScalerSetBit(P74_CC_HDMI_GPVS, ~(_BIT6 | _BIT5), _BIT5);
        }
        else
        {
            // Mannal Set Color Space and disable pixel  repetition
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Disable down sampling
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_50_PORT_PAGE74_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Waiting for Down Sampling Effect
            ScalerTimerDelayXms(20);

            ScalerTMDSRx5HdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _DISABLE);

            CLR_HDMI_RX5_AVI_INFO_FRAME_RECEIVED();
        }

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_II_SUPPORT == _OFF) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7) == _BIT7))
#else
        if(ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7) == _BIT7)
#endif
        {
            SET_TMDS_RX5_SPD_INFO_FRAME_RECEIVED();

            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT7);
        }
        else
        {
            CLR_TMDS_RX5_SPD_INFO_FRAME_RECEIVED();
        }
#endif

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
        ScalerTMDSRx5SpdInfoPacketDetect(_NOT_WAIT);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
        if(ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT6) == _BIT6)
        {
            SET_HDMI_RX5_HDR10_INFO_FRAME_RECEIVED();

            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT6);
        }
        else
        {
            CLR_HDMI_RX5_HDR10_INFO_FRAME_RECEIVED();
        }
#endif

        SET_HDMI_RX5_PACKET_DETECTING();

        // Activate Packet Detection Event
        ScalerTimerActiveTimerEvent(130, _SCALER_TIMER_EVENT_RX5_TMDS_HDMI_PACKET_DETECT);
    }
}
//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5HdmiPacketDetectEvent(void)
{
    CLR_HDMI_RX5_PACKET_DETECTING();
}
//--------------------------------------------------
// Description  : Wait for Deep Color PLL Phase Lock
// Input Value  : None
// Output Value : _TRUE = > Phase Locked
//--------------------------------------------------
bit ScalerTMDSRx5HdmiWaitDeepColorPllLock(void)
{
    BYTE ucTemp = 0;

    do
    {
        ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_82_PORT_PAGE74_HDMI_DPC_SET2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Delay for PLL Phase Lock
        ScalerTimerDelayXms(2);

        ucTemp++;
    }
    while((ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_82_PORT_PAGE74_HDMI_DPC_SET2, _BIT1) != 0) && (ucTemp <= 15));

    if(ucTemp > 15)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Hdmi Enable Watch Dog
// Input Value  : ucWDType => Watch Dog type, bEnable => Enable watch dog flag
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5HdmiWatchDog(BYTE ucWDType, bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if(((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD) && (GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE))
        {
            if(ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_41_PORT_PAGE74_HDMI_VWDSR, _BIT0) == 0x00)
            {
                // Clear AVI Info Frame Variation flag
                ScalerSetBit(P74_CC_HDMI_GPVS, ~(_BIT6 | _BIT5 | _BIT0), _BIT0);

                // Enable Color Space/ Colorimetry Change Detection
                ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_45_PORT_PAGE74_HDMI_PVGCR0, ~(_BIT3 | _BIT0), (_BIT3 | _BIT0));

                // Enable AVI Info Frame Variation Watch Dog
                ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_41_PORT_PAGE74_HDMI_VWDSR, ~_BIT0, _BIT0);
            }
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            if(ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_31_PORT_PAGE74_HDMI_WDCR0, _BIT7) == 0x00)
            {
                // CLR AVMute Flag
                ScalerSetBit(P74_CB_HDMI_SR, ~_BIT7, _BIT7);

                // Enable AVMute WD
                ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_31_PORT_PAGE74_HDMI_WDCR0, ~_BIT7, _BIT7);
            }
        }
    }
    else
    {
        if((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD)
        {
            // Disable packet variation Watch Dog
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_41_PORT_PAGE74_HDMI_VWDSR, ~_BIT0, 0x00);

            ScalerSetDataPortByte(P74_C9_HDMI_AP, _P74_CA_PT_45_PORT_PAGE74_HDMI_PVGCR0, 0x00);

            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_46_PORT_PAGE74_HDMI_PVGCR1, ~_BIT0, 0x00);
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            // Disable AV Mute Watch Dog
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_31_PORT_PAGE74_HDMI_WDCR0, ~_BIT7, 0x00);
        }
    }
}

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI SPD Info Frame Packet Detect
// Input Value  : bWait
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5SpdInfoPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for RSV4 received check
        if(ScalerTimerPollingDataBitFlagProc(130, P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
        {
            ScalerTMDSRx5HdmiGetSpdInfo();
        }
    }
    else
    {
        // Check RSV4 received bit
        if(ScalerGetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_00_PORT_PAGE74_HDMI_SCR, _BIT7) == _BIT7)
        {
            ScalerTMDSRx5HdmiGetSpdInfo();
        }
    }
}

//--------------------------------------------------
// Description  : Get SPD Info Product Description
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5HdmiGetSpdInfo(void)
{
    BYTE pucHdmiVenderName[4] = {0};

    ScalerGetDataPortByte(P74_CD_HDMI_PSAP, 0x90, 4, &pucHdmiVenderName[0], _AUTOINC);

    if(((pucHdmiVenderName[0] == 'M') || (pucHdmiVenderName[0] == 'S')) &&
       ((pucHdmiVenderName[1] == 'S') || (pucHdmiVenderName[1] == 'C')) &&
       ((pucHdmiVenderName[2] == 'F') || (pucHdmiVenderName[2] == 'E')) &&
       ((pucHdmiVenderName[3] == 'T') || (pucHdmiVenderName[3] == 'I')))
    {
        g_stTmdsMacRx5SpdInfo.b1StructValuable = 0x01;
        memcpy(&g_stTmdsMacRx5SpdInfo.pucHdmiVendorName[0], pucHdmiVenderName, 4);

        ScalerGetDataPortByte(P74_CD_HDMI_PSAP, 0x98, 8, &g_stTmdsMacRx5SpdInfo.pucHdmiProductDescription[0], _AUTOINC);
    }
}
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Scramble Status Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5ScrambleStatusReset(void)
{
    // Set Scramble Detect Manual Mode
    ScalerSetBit(P74_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), 0x00);

    // Disable Scrambling Status
    ScalerSetDataPortBit(P74_39_HDMI_CTRL_39, _P74_3A_PT_21_PORT_PAGE74_HDMI_SCDC_21, ~_BIT0, 0x00);

    // Clear Scrambling Detection Flag
    ScalerSetBit(P74_01_HDMI_CTRL_01, ~_BIT3, _BIT3);

    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX5_HDMI2_SCRAMBLE_DETECT_TIMEOUT);
}

//--------------------------------------------------
// Description  : Scramble Detect timeout event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5ScrambleDetectTimeoutTimerEvent(void)
{
    // Set Scramble Detect Auto Mode
    ScalerSetBit(P74_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), _BIT4);

    ScalerTMDSRx5ScrambleDetectDisable();
}

//--------------------------------------------------
// Description  : TMDS Scramble Detection IRQ Disable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5ScrambleDetectDisable(void)
{
    // Disable SCDC 0x20 Change IRQ
    ScalerSetBit(P74_26_HDMI_CTRL_26, ~_BIT4, 0x00);
}

#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Set SCDC Info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5SetScdcInfo_EXINT0(void) using 1
{
    // Set SCDC Info
    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D0_PORT_PAGE74_HDMI_SCDC_D0);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D1_PORT_PAGE74_HDMI_SCDC_D1);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D2_PORT_PAGE74_HDMI_SCDC_D2);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D3_PORT_PAGE74_HDMI_SCDC_D3);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D4_PORT_PAGE74_HDMI_SCDC_D4);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D5_PORT_PAGE74_HDMI_SCDC_D5);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D6_PORT_PAGE74_HDMI_SCDC_D6);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D7_PORT_PAGE74_HDMI_SCDC_D7);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D8_PORT_PAGE74_HDMI_SCDC_D8);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_D9_PORT_PAGE74_HDMI_SCDC_D9);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_DA_PORT_PAGE74_HDMI_SCDC_DA);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_DB_PORT_PAGE74_HDMI_SCDC_DB);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_DC_PORT_PAGE74_HDMI_SCDC_DC);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);

    ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_DD_PORT_PAGE74_HDMI_SCDC_DD);
    ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Set AMD AUPI SCDC Info
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5SetAmdAupiScdcInfo_EXINT0(bit bEnable) using 1
{
    if(GET_FREESYNC_HDMI_AUPI_INFO() != _TRUE)
    {
        return;
    }

    if(bEnable == _ENABLE)
    {
        // Set SCDC Info
        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E0_PORT_PAGE74_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E1_PORT_PAGE74_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E2_PORT_PAGE74_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E3_PORT_PAGE74_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E4_PORT_PAGE74_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E5_PORT_PAGE74_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E6_PORT_PAGE74_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E7_PORT_PAGE74_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);
    }
    else
    {
        // Set SCDC Info
        // Set SCDC Info
        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E0_PORT_PAGE74_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E1_PORT_PAGE74_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E2_PORT_PAGE74_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E3_PORT_PAGE74_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E4_PORT_PAGE74_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E5_PORT_PAGE74_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E6_PORT_PAGE74_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P74_39_HDMI_CTRL_39, _P74_3A_PT_E7_PORT_PAGE74_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P74_3A_HDMI_CTRL_3A, 0x00);
    }
}
#endif
#endif
#endif
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSRx5TMDSNormalPreDetect(void)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(_D5_INPUT_PORT) == _FALSE)
#endif
    {
        // DDC handshake Detected
        if(GET_TMDS_RX5_DDC_DETECTED() == _TRUE)
        {
            DebugMessageRx5("7. Normal D5 DDC", 0);

            CLR_TMDS_RX5_DDC_DETECTED();

            return _TRUE;
        }
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE84_DDC5_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX5_DDC_DETECTED() != _TRUE))
    {
        MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
        MCU_FE84_DDC5_EDID_IRQ |= _BIT3;

        CLR_TMDS_RX5_DDC_DETECTED();
    }

    ScalerTimerDelayXms(6);

    if(GET_TMDS_RX5_PHY_SET() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Signal Detection for TMDS(Power Saving)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSRx5TMDSPSPreDetect(void)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(_D5_INPUT_PORT) == _FALSE)
#endif
    {
        // DDC handshake Detected
        if(GET_TMDS_RX5_DDC_DETECTED() == _TRUE)
        {
            DebugMessageRx5("7. PowerSaving D5 DDC", 0);

            CLR_TMDS_RX5_DDC_DETECTED();

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            SET_TMDS_RX5_TOGGLE_Z0();
#endif
            return _TRUE;
        }
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE84_DDC5_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX5_DDC_DETECTED() != _TRUE))
    {
        MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
        MCU_FE84_DDC5_EDID_IRQ |= _BIT3;
    }

    // Reset Freq. Detect Counter(Toggle) & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P74_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(P74_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

    // Clear Freq. Stable Flag
    ScalerSetBit(P74_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P74_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

    // Delay enough time for freq. measure (calculated for measure 5 times)
    ScalerTimerDelayXms(5);

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P74_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P74_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
        SET_TMDS_RX5_TOGGLE_Z0();
#endif
        return _TRUE;
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P74_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

        return _FALSE;
    }

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : HPD Low Process
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx5HotPlugLowProc(void)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D5_CABLE_STATUS() == _TRUE) && (GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D5_CABLE_STATUS() == _TRUE))
#endif
    {
        PCB_D5_HOTPLUG(_D5_HOT_PLUG_LOW);

        ScalerTMDSRx5SwitchHdcpSlaveAddr();

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
        g_ucTmdsD5DdcramNackStatus = ScalerSyncGetDdcForceNackStatus(_D5_INPUT_PORT);

        if(g_ucTmdsD5DdcramNackStatus == _FALSE)
        {
            // DDCRAM Force Nack
            ScalerSyncSetDdcForceNack(_D5_INPUT_PORT, _ON);
        }

        // Set DDCCI Force Nack
        ScalerMcuDdcciEnable(_DISABLE, _D5_INPUT_PORT);
#endif
    }
}

//--------------------------------------------------
// Description  : HPD High Process
// Input Value  : usHpdTime
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx5HotPlugHighProc(WORD usHpdTime)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D5_CABLE_STATUS() == _TRUE) && (GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D5_CABLE_STATUS() == _TRUE))
#endif
    {
        ScalerTimerDelayXms(usHpdTime);

        PCB_D5_HOTPLUG(_D5_HOT_PLUG_HIGH);
    }
}
#endif
