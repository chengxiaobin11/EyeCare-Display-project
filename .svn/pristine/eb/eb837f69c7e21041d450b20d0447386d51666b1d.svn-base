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
// ID Code      : RL6851_Series_ScalerTMDS_ComboPhy.c No.0000
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
StructHdmiSpdInfo g_stTmdsMacRx0SpdInfo;
#endif

#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
#if(_HDMI21_VRR_SUPPORT == _ON)
StructHdmi21EdidVrrCap g_stTmdsMacHdmi21EdidVrrCap;
#endif
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
#if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))
void ScalerTMDSDviVideoSetting(BYTE ucInputPort);
void ScalerTMDSFreqDetectDisable(void);
void ScalerTMDSResetProc(void);
BYTE ScalerTMDSVideoDetect(bit bWait);
void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID);

#if(_HDMI_SUPPORT == _ON)
bit ScalerTMDSHdmiAviPixelRepInfoChanged(void);
bit ScalerTMDSHdmiDeepColorProc(WORD usTmdsClkCnt);
BYTE ScalerTMDSHdmiGetColorDepth(void);
void ScalerTMDSHdmiPacketDetect(bit bWait);
void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID);
bit ScalerTMDSHdmiSetDeepColorPll(WORD usTMDSClkCount, BYTE ucColorDepth);
void ScalerTMDSHdmiDPLLOffProc(WORD usVCOFreq, BYTE ucPreDiv, BYTE ucOutputDiv, BYTE ucNcode);
void ScalerTMDSHdmiDPLLOnProc(BYTE ucNcode);
bit ScalerTMDSHdmiWaitDeepColorPllLock(void);
void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable);
BYTE ScalerTMDSRx0HdmiGetAVIInfo(EnumAviInfoContent enumContent);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
void ScalerTMDSRx0SpdInfoPacketDetect(bit bWait);
void ScalerTMDSRx0HdmiGetSpdInfo(void);
StructHdmiSpdInfo ScalerTMDSHdmiGetSpdPdInfo(EnumSourceSearchPort enumInputPort);
#endif

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
#if(_HDMI21_FVA_SUPPORT == _ON)
bit ScalerTMDSGetHdmi21VtemReceived(void);
#endif

void ScalerTMDSClrHdmi21VtemReceived(void);
BYTE ScalerTMDSGetVicVfreqParameter(BYTE ucVicIndex);

#if(_HDMI21_VRR_SUPPORT == _ON)
bit ScalerTMDSMacRxGetHdmi21VrrStatus(void);
void ScalerTMDSMacRxSetEdidVrrCapability(BYTE ucInputPort, StructHdmi21EdidVrrCap stEdidVrrCap);
void ScalerTMDSMacRxClrEdidVrrCapability(BYTE ucInputPort);
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
BYTE ScalerTMDSMacRxHdmi21GetFvaFactor(void);
WORD ScalerTMDSMacRxCalFvaVfreqMax(StructFreeSyncEdidInfo *pstCatchEdidInfo, BYTE ucFavFactor);
#endif
#endif
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
void ScalerTMDSSetPorchColor(BYTE ucInputPort, EnumColorSpace enumColorFormat);
#endif

void ScalerTMDSHotPlugLowProc(BYTE ucPortSelect);
void ScalerTMDSHotPlugHighProc(BYTE ucPortSelect, WORD usHpdTime);
#endif // End of #if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTMDSDviVideoSetting(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    // Manual Set Color Space and disable pixel repetition
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable Down Sampling
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_50_PORT_PAGE2_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Waiting for Down Sampling Effect
    ScalerTimerDelayXms(20);

    SET_COLOR_SPACE(_COLOR_SPACE_RGB);
    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

    ScalerTMDSRx0SetPorchColor(GET_COLOR_SPACE());
}
//--------------------------------------------------
// Description  : TMDS Freq. Detection IRQ Disable and Clear Clock Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSFreqDetectDisable(void)
{
    // Disable TMDS Freq. Detect IRQ
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);
    ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~_BIT7, 0x00);

    // Clear TMDS Clk Count
    g_usTMDSClkCount = 0;

    // Clear PHY SET flag
    CLR_TMDS_PHY_SET();

    // Disable HDMI MAC Power
    ScalerSetBit(P2_A7_TMDS_PWDCTL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
}
//--------------------------------------------------
// Description  : TMDS Reset Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSResetProc(void)
{
#if(_DVI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX0_TMDS_VIDEO_DETECT);
#if(_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX0_TMDS_HDMI_PACKET_DETECT);
#endif

#endif
}
//--------------------------------------------------
// Description  : Detect TMDS video mode
// Input Value  : bWait => Whether to wait then read
// Output Value : TMDS video type
//--------------------------------------------------
BYTE ScalerTMDSVideoDetect(bit bWait)
{
    BYTE ucTemp = _TMDS_VIDEO_DATA_NONE;

    if(bWait == _WAIT)
    {
        // Wait at least 1 frame for HW auto update TMDS video RGBHV valid value
        ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);

        // Wait for HW update DE flag
        if(ScalerTimerPollingFlagProc(20, P2_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // H/Vsync received
            if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
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

        CLR_TMDS_RGBHV_DETECTING();

        return ucTemp;
    }
    else
    {
        // R/G/B data detected
        if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P2_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
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
        ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        SET_TMDS_RGBHV_DETECTING();

        // Activate TMDS video Detection Event
        ScalerTimerActiveTimerEvent(45, _SCALER_TIMER_EVENT_RX0_TMDS_VIDEO_DETECT);

        return ucTemp;
    }
}
//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID)
{
    enumEventID = enumEventID;

    CLR_TMDS_RGBHV_DETECTING();
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect HDMI AVI pixel repetition
// Input Value  : None
// Output Value : _TRUE => Current Info is different from previous setting
//--------------------------------------------------
bit ScalerTMDSHdmiAviPixelRepInfoChanged(void)
{
    // Check Tmds Pixel Repetition
    if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION) != GET_TMDS_RX0_AVI_PIXEL_REPETITION())
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
bit ScalerTMDSHdmiDeepColorProc(WORD usTmdsClkCnt)
{
    // Setting Deep Color PLL
    if(ScalerTMDSHdmiSetDeepColorPll(usTmdsClkCnt, GET_COLOR_DEPTH()) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for Phase lock
    if(ScalerTMDSHdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : Received Color Depth
//--------------------------------------------------
BYTE ScalerTMDSHdmiGetColorDepth(void)
{
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        return _COLOR_DEPTH_12_BITS;
    }

    if(GET_HDMI_GCP_RECEIVED() == _TRUE)
    {
        if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x05)
        {
            return _COLOR_DEPTH_10_BITS;
        }
        else if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x06)
        {
            return _COLOR_DEPTH_12_BITS;
        }
        else if(ScalerGetBit(P2_B4_TMDS_DPC0, 0x07) == 0x07)
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
void ScalerTMDSHdmiPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingFlagProc(130, P2_CC_HDMI_GPVS, (_BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // Both GCP & AVI infoframe packet have been received
            if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == (_BIT6 | _BIT5))
            {
                SET_HDMI_GCP_RECEIVED();

                SET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
            }
            // Only AVI infoframe packet have been received
            else if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT5)
            {
                SET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();

                // Polling more time to wait GCP when AVI IF has been received.
                if(ScalerTimerPollingFlagProc(180, P2_CC_HDMI_GPVS, _BIT6, _TRUE) == _TRUE)
                {
                    SET_HDMI_GCP_RECEIVED();
                }
                else
                {
                    CLR_HDMI_GCP_RECEIVED();
                }
            }
            // Only GCP Packet have been received
            else if(ScalerGetBit(P2_CC_HDMI_GPVS, (_BIT6 | _BIT5)) == _BIT6)
            {
                SET_HDMI_GCP_RECEIVED();

                // Polling more time to wait AVI IF when GCP has been received.
                if(ScalerTimerPollingFlagProc(180, P2_CC_HDMI_GPVS, _BIT5, _TRUE) == _TRUE)
                {
                    SET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
                }
                else
                {
                    CLR_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
                }
            }
        }
        // Neither AVI infoframe nor GCP packet received
        else
        {
            CLR_HDMI_GCP_RECEIVED();

            CLR_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
        }

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_II_SUPPORT == _OFF) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
        // Polling 3 frame for detect Packet signals
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7, _TRUE) == _TRUE))
#else
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
#endif
        {
            SET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
#endif

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
        ScalerTMDSRx0SpdInfoPacketDetect(_WAIT);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
        // Polling 3 frame for detect Packet signals
        if(ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT6, _TRUE) == _TRUE)
        {
            SET_HDMI_RX0_HDR10_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_HDMI_RX0_HDR10_INFO_FRAME_RECEIVED();
        }
#endif

        // Wait at least 3 frame for HW auto update color depth value
        ScalerTimerDelayXms(130);

        CLR_HDMI_PACKET_DETECTING();
    }
    else
    {
        if(ScalerGetBit(P2_CC_HDMI_GPVS, _BIT6) == _BIT6)
        {
            ScalerTMDSHdmiWatchDog(_HDMI_AV_MUTE_WD, _ENABLE);

            SET_HDMI_GCP_RECEIVED();
        }
        else
        {
            ScalerTMDSHdmiWatchDog(_HDMI_AV_MUTE_WD, _DISABLE);

            CLR_HDMI_GCP_RECEIVED();
        }

        if(ScalerGetBit(P2_CC_HDMI_GPVS, _BIT5) == _BIT5)
        {
            // Color Space Auto/ Pixel Repetition auto mode
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

            ScalerTMDSHdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _ENABLE);

            SET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
        }
        else
        {
            // Mannal Set Color Space and disable pixel  repetition
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Disable down sampling
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_50_PORT_PAGE2_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

            // Waiting for Down Sampling Effect
            ScalerTimerDelayXms(20);

            ScalerTMDSHdmiWatchDog(_HDMI_AVI_INFO_VARIATION_WD, _DISABLE);

            CLR_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();
        }

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_II_SUPPORT == _OFF) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
        if((GET_HDMI_FREESYNC_VCP() == 0x01) && (ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7) == _BIT7))
#else
        if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7) == _BIT7)
#endif
        {
            SET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_TMDS_RX0_SPD_INFO_FRAME_RECEIVED();
        }
#endif

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
        ScalerTMDSRx0SpdInfoPacketDetect(_NOT_WAIT);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
        if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT6) == _BIT6)
        {
            SET_HDMI_RX0_HDR10_INFO_FRAME_RECEIVED();
        }
        else
        {
            CLR_HDMI_RX0_HDR10_INFO_FRAME_RECEIVED();
        }
#endif

        // Clear Detection Flag
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT6, _BIT6);

        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT5, _BIT5);

        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT7);

        SET_HDMI_PACKET_DETECTING();

        // Activate Packet Detection Event
        ScalerTimerActiveTimerEvent(130, _SCALER_TIMER_EVENT_RX0_TMDS_HDMI_PACKET_DETECT);
    }
}
//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID)
{
    enumEventID = enumEventID;

    CLR_HDMI_PACKET_DETECTING();
}
//--------------------------------------------------
// Description  : Set Deep Color PLL
// Input Value  : usTMDSClkCount, ucColorDepth
// Output Value : None
//--------------------------------------------------
bit ScalerTMDSHdmiSetDeepColorPll(WORD usTMDSClkCount, BYTE ucColorDepth)
{
    DWORD ulTMDSClkValue = 0;
    WORD usVCOFreq = 0;
    BYTE ucPreDiv = 0;
    BYTE ucNcode = 0;
    BYTE ucOutputDiv = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Fin = TMDS_clk
    // Fref = Fin / Pre-Div
    // Fvco = Fin * N-code, F-code = 0
    // Freq = Fvco / Output-Div
    //
    // Restriction
    // A. 14.318MHz < Fin < 600MHz
    // B. 270MHz < Fvco < 660MHz
    // C. 14MHz < Fref < 28MHz
    // D. YCbCr 420, Ratio = 2, other case Ratio = 1
    ////////////////////////////////////////////////////////////////////////////////////////////////

    // Reset DP Stream Clock Block
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT2, _BIT2);
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT2, 0x00);

    // Set clk for deep color
    ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~_BIT6, _BIT6);

    // PLL Input Clock select to HDMI video Clock, Output Clock Select to PLL Clock
    ScalerSetBit(PB5_A3_PLL_IN_CONTROL, ~(_BIT7 | _BIT6), 0x00);

    // If Measure Divider = /2 then TMDS_CLK x 2, unit:kHz
    if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0, _BIT6) == _BIT6)
    {
        ulTMDSClkValue = (DWORD)_GDI_CLK_KHZ * 1024 * 2 / usTMDSClkCount;
    }
    else
    {
        ulTMDSClkValue = (DWORD)_GDI_CLK_KHZ * 1024 / usTMDSClkCount;
    }

    DebugMessageRx0("TMDS clk", ulTMDSClkValue);
    DebugMessageRx0("Color Depth", ucColorDepth);
    DebugMessageRx0("usTMDSClkCount", usTMDSClkCount);

    ///////////////////////////
    // Calculate Pre-Divider //
    // 10bit: div2,4,5,10,20 //
    // 12bit: div2,3,6,12,24 //
    // 16bit: div2,4,8,16,32 //
    ///////////////////////////

    // TMDS_CLK : 25~600MHz
    // 14MHz <= Fref = TMDS_CLK / Pre-Div <= 28MHz
    if((ucColorDepth == _COLOR_DEPTH_10_BITS) || (ucColorDepth == _COLOR_DEPTH_16_BITS))
    {
        if((ulTMDSClkValue / (ucColorDepth * 2)) > 14000)
        {
            ucPreDiv = ucColorDepth * 2;
        }
        else if((ulTMDSClkValue / ucColorDepth) > 14000)
        {
            ucPreDiv = ucColorDepth;
        }
        else if((ulTMDSClkValue / (ucColorDepth / 2)) > 14000)
        {
            ucPreDiv = ucColorDepth / 2;
        }
        else if((ulTMDSClkValue / 4) > 14000)
        {
            ucPreDiv = 4;
        }
        else if((ulTMDSClkValue / 2) > 14000)
        {
            ucPreDiv = 2;
        }
        else if(ulTMDSClkValue > 14000)
        {
            ucPreDiv = 1;
        }
    }
    else if(ucColorDepth == _COLOR_DEPTH_12_BITS)
    {
        if((ulTMDSClkValue / (ucColorDepth * 2)) > 14000)
        {
            ucPreDiv = ucColorDepth * 2;
        }
        else if((ulTMDSClkValue / ucColorDepth) > 14000)
        {
            ucPreDiv = ucColorDepth;
        }
        else if((ulTMDSClkValue / (ucColorDepth / 2)) > 14000)
        {
            ucPreDiv = ucColorDepth / 2;
        }
        else if((ulTMDSClkValue / 3) > 14000)
        {
            ucPreDiv = 3;
        }
        else if((ulTMDSClkValue / 2) > 14000)
        {
            ucPreDiv = 2;
        }
        else if(ulTMDSClkValue > 14000)
        {
            ucPreDiv = 1;
        }
    }

    DebugMessageRx0("Pre-Divider", ucPreDiv);

    if(ucPreDiv == 0)
    {
        return _FALSE;
    }

    //////////////////////
    // Calculate N Code //
    //////////////////////
    if((ulTMDSClkValue / ucPreDiv) >= 20000)
    {
        ucNcode = 16;

        // Set Clamp N Code
        // Max = 16 + 2 - 2(reg = actual Ncode - 2), Min = 16 - 2 - 2
        ScalerSetByte(PB5_B1_N_F_MAX, ((ucNcode - 2) + 2));
        ScalerSetByte(PB5_B2_N_F_MIN, ((ucNcode - 2) - 2));
    }
    else
    {
        ucNcode = 32;

        // Set Clamp N Code
        // Max = 16 + 2 - 2(reg = actual Ncode - 2), Min = 16 - 2 - 2
        ScalerSetByte(PB5_B1_N_F_MAX, ((ucNcode - 2) + 2));
        ScalerSetByte(PB5_B2_N_F_MIN, ((ucNcode - 2) - 2));
    }

    DebugMessageRx0("N code", ucNcode);


    //////////////////////////////
    // Calculate Output Divider //
    //////////////////////////////

    ucOutputDiv = ucNcode / 8 * ucColorDepth / ucPreDiv;

    DebugMessageRx0("Outpur Divider", ucOutputDiv);

    if(ucOutputDiv == 0)
    {
        return _FALSE;
    }

    //////////////
    // Set DPLL //
    //////////////
    // Interger PLL
    ScalerSetBit(PB5_A7_M2PLL_1, ~_BIT2, _BIT2);

    // Bypass PI
    ScalerSetBit(PB5_A7_M2PLL_1, ~_BIT7, _BIT7);

    usVCOFreq = (WORD)(ulTMDSClkValue / ucPreDiv * ucNcode / 100);

    ScalerTMDSHdmiDPLLOffProc(usVCOFreq, ucPreDiv, ucOutputDiv, ucNcode);

    ScalerTMDSHdmiDPLLOnProc(ucNcode);

    return _TRUE;
}

//--------------------------------------------------
// Description  : Deep Color PLL Off COntrol.
// Input Value  : usVCOFreq, ucPreDiv, ucOutputDiv
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiDPLLOffProc(WORD usVCOFreq, BYTE ucPreDiv, BYTE ucOutputDiv, BYTE ucNcode)
{
    // Power Off DPLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, _BIT0);

    // Disable PI Control
    ScalerSetBit(PB5_C5_TRACKING_5, ~(_BIT7 | _BIT6), 0x00);

    // Disable HS/VS Tracking Control
    ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), 0x00);

    // Set Rs[7:5] = 100 = 9k
    ScalerSetBit(PB5_A6_M2PLL_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);

    // Set Icp
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // Icp set 2.5uA, 3.3uA, 5uA, 10uA......                                                        //
    // Icp = N * 0.25                                                                               //
    //////////////////////////////////////////////////////////////////////////////////////////////////

    if(ucNcode == 16)
    {
        // Icp[2:0] = 5
        ScalerSetBit(PB5_A6_M2PLL_0, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
    }
    else
    {
        // Icp[2:0] = 7.5
        ScalerSetBit(PB5_A6_M2PLL_0, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
    }

    // Set IPI = 10uA
    if((6000 <= usVCOFreq) && (usVCOFreq < 7700))
    {
        ScalerSetBit(PB5_A7_M2PLL_1, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
    // Set IPI = 5uA
    else if((5000 <= usVCOFreq) && (usVCOFreq < 6000))
    {
        ScalerSetBit(PB5_A7_M2PLL_1, ~(_BIT1 | _BIT0), _BIT1);
    }
    // Set IPI = 3.3uA
    else if((4000 <= usVCOFreq) && (usVCOFreq < 5000))
    {
        ScalerSetBit(PB5_A7_M2PLL_1, ~(_BIT1 | _BIT0), _BIT0);
    }
    // Set IPI = 2.5uA
    else
    {
        ScalerSetBit(PB5_A7_M2PLL_1, ~(_BIT1 | _BIT0), 0x00);
    }

    // Enable Pre-Div
    if(ucPreDiv >= 2)
    {
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~_BIT7, 0x00);
        ScalerSetByte(PB5_A4_M2PLL_DIVIDER0, (ucPreDiv - 2));
    }
    else // Disable Pre-Div
    {
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~_BIT7, _BIT7);
        ScalerSetByte(PB5_A4_M2PLL_DIVIDER0, 0x00);
    }

    // Set Output-Div
    if(ucOutputDiv <= 8)
    {
        // analog div = 1
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~(_BIT1 | _BIT0), 0x00);

        // digital div = ucOutputDiv
        ScalerSetBit(P2_B1_TMDS_DBB1, ~(_BIT6 | _BIT5 | _BIT4), ((ucOutputDiv - 1) << 4));
    }
    else if((ucOutputDiv / 2) <= 8)
    {
        // analog div = 2
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~(_BIT1 | _BIT0), _BIT0);

        // digital div = (ucOutputDiv / 2) - 1
        ScalerSetBit(P2_B1_TMDS_DBB1, ~(_BIT6 | _BIT5 | _BIT4), (((ucOutputDiv / 2) - 1) << 4));
    }
    else if((ucOutputDiv / 4) <= 8)
    {
        // analog div = 4
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~(_BIT1 | _BIT0), _BIT1);

        // digital div = (ucOutputDiv / 4) - 1
        ScalerSetBit(P2_B1_TMDS_DBB1, ~(_BIT6 | _BIT5 | _BIT4), (((ucOutputDiv / 4) - 1) << 4));
    }
    else
    {
        // analog div = 8
        ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // digital div = (ucOutputDiv / 8) - 1
        ScalerSetBit(P2_B1_TMDS_DBB1, ~(_BIT6 | _BIT5 | _BIT4), (((ucOutputDiv / 8) - 1) << 4));
    }

    // Set CP Enable, close loop
    // Set Vc 0.5v
    // Set LPF Enable, VCO reset set to normal
    ScalerSetBit(PB5_AA_M2PLL_DUMMY, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT0));

    // Set VCO Mode
    ScalerSetBit(PB5_A7_M2PLL_1, ~_BIT7, _BIT7);

    // DPLL VCORSTB Set to Normal
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT1, 0x00);
}

//--------------------------------------------------
// Description  : Deep Color PLL On COntrol.
// Input Value  : ucNcode
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiDPLLOnProc(BYTE ucNcode)
{
    // Power On DPLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, 0x00);
    DELAY_XUS(200);

    // Set VCO/4 Enable
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT7, _BIT7);

    // Set N.F Code
    ScalerSetByte(PB5_AD_N_F_CODE_1, (ucNcode - 2));
    ScalerSetByte(PB5_AE_N_F_CODE_2, 0x00);
    ScalerSetByte(PB5_AF_N_F_CODE_3, 0x00);
    ScalerSetByte(PB5_B0_N_F_CODE_4, 0x00);

    // Wait for DPLL Stable (300us)
    DELAY_XUS(300);
}

//--------------------------------------------------
// Description  : Wait for Deep Color PLL Phase Lock
// Input Value  : None
// Output Value : _TRUE = > Phase Locked
//--------------------------------------------------
bit ScalerTMDSHdmiWaitDeepColorPllLock(void)
{
    BYTE ucTemp = 0;

    do
    {
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_82_PORT_PAGE2_HDMI_DPC_SET2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Delay for PLL Phase Lock
        ScalerTimerDelayXms(2);

        ucTemp++;
    }
    while((ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_82_PORT_PAGE2_HDMI_DPC_SET2, _BIT1) != 0) && (ucTemp <= 15));

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
void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if(((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD) && (GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE))
        {
            if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_41_PORT_PAGE2_HDMI_VWDSR, _BIT0) == 0x00)
            {
                // Clear AVI Info Frame Variation flag
                ScalerSetBit(P2_CC_HDMI_GPVS, ~(_BIT6 | _BIT5 | _BIT0), _BIT0);

                // Enable Color Space/ Colorimetry Change Detection
                ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_45_PORT_PAGE2_HDMI_PVGCR0, ~(_BIT3 | _BIT0), (_BIT3 | _BIT0));

                // Enable AVI Info Frame Variation Watch Dog
                ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_41_PORT_PAGE2_HDMI_VWDSR, ~_BIT0, _BIT0);
            }
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_31_PORT_PAGE2_HDMI_WDCR0, _BIT7) == 0x00)
            {
                // CLR AVMute Flag
                ScalerSetBit(P2_CB_HDMI_SR, ~_BIT7, _BIT7);

                // Enable AVMute WD
                ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_31_PORT_PAGE2_HDMI_WDCR0, ~_BIT7, _BIT7);
            }
        }

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
        if((ucWDType & _TMDS_NO_CLK_WD) == _TMDS_NO_CLK_WD)
        {
            // clr NO CLK Flag
            ScalerSetBit(P2_B6_TMDS_UDC1, ~_BIT3, _BIT3);

            // Enable NO CLK video/audio WD
            ScalerSetBit(P2_B2_TMDS_DBB2, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
        }
#endif
    }
    else
    {
        if((ucWDType & _HDMI_AVI_INFO_VARIATION_WD) == _HDMI_AVI_INFO_VARIATION_WD)
        {
            // Disable packet variation Watch Dog
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_41_PORT_PAGE2_HDMI_VWDSR, ~_BIT0, 0x00);

            ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_45_PORT_PAGE2_HDMI_PVGCR0, 0x00);

            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_46_PORT_PAGE2_HDMI_PVGCR1, ~_BIT0, 0x00);
        }

        if((ucWDType & _HDMI_AV_MUTE_WD) == _HDMI_AV_MUTE_WD)
        {
            // Disable AV Mute Watch Dog
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_31_PORT_PAGE2_HDMI_WDCR0, ~_BIT7, 0x00);
        }

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
        if((ucWDType & _TMDS_NO_CLK_WD) == _TMDS_NO_CLK_WD)
        {
            // Disable NO CLK video/audio WD
            ScalerSetBit(P2_B2_TMDS_DBB2, ~(_BIT5 | _BIT4), 0x00);
        }
#endif
    }
}
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSRx0HdmiGetAVIInfo(EnumAviInfoContent enumContent)
{
    if(GET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _AVI_INFO_COLOR_SPACE:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x04, (_BIT6 | _BIT5)) >> 5);

            case _AVI_INFO_COLORIMETRY:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x05, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_EXTENDED_COLORIMETRY:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, (_BIT6 | _BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_RGB_QUANTIZATION:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, (_BIT3 | _BIT2)) >> 2);

            case _AVI_INFO_YCC_QUANTIZATION:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x08, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_SCAN_INFO:

                return ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x04, (_BIT1 | _BIT0));

            case _AVI_INFO_IT_CONTENT:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x06, _BIT7) >> 7);

            case _AVI_INFO_PIXEL_REPETITION:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x08, (_BIT3 | _BIT2 | _BIT1 | _BIT0)));

            case _AVI_INFO_AR:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x05, (_BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_VIC:

                return (ScalerGetDataPortBit(P2_CD_HDMI_PSAP, 0x07, (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));

            default:

                break;
        }
    }

    return 0xFF;
}

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI SPD Info Frame Packet Detect
// Input Value  : bWait
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx0SpdInfoPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for RSV4 received check
        if(ScalerTimerPollingDataBitFlagProc(130, P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
        {
            ScalerTMDSRx0HdmiGetSpdInfo();
        }
    }
    else
    {
        // Check RSV4 received bit
        if(ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, _BIT7) == _BIT7)
        {
            ScalerTMDSRx0HdmiGetSpdInfo();
        }
    }
}

//--------------------------------------------------
// Description  : Get SPD Info Product Description
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx0HdmiGetSpdInfo(void)
{
    BYTE pucHdmiVenderName[4] = {0};

    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x90, 4, &pucHdmiVenderName[0], _AUTOINC);

    if(((pucHdmiVenderName[0] == 'M') || (pucHdmiVenderName[0] == 'S')) &&
       ((pucHdmiVenderName[1] == 'S') || (pucHdmiVenderName[1] == 'C')) &&
       ((pucHdmiVenderName[2] == 'F') || (pucHdmiVenderName[2] == 'E')) &&
       ((pucHdmiVenderName[3] == 'T') || (pucHdmiVenderName[3] == 'I')))
    {
        g_stTmdsMacRx0SpdInfo.b1StructValuable = 0x01;
        memcpy(&g_stTmdsMacRx0SpdInfo.pucHdmiVendorName[0], pucHdmiVenderName, 4);

        ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x98, 8, &g_stTmdsMacRx0SpdInfo.pucHdmiProductDescription[0], _AUTOINC);
    }
}

//--------------------------------------------------
// Description  : Get HDMI SPD Info Contents
// Input Value  : InputPort
// Output Value : Content Value
//--------------------------------------------------
StructHdmiSpdInfo ScalerTMDSHdmiGetSpdPdInfo(EnumSourceSearchPort enumInputPort)
{
    enumInputPort = enumInputPort;

    return g_stTmdsMacRx0SpdInfo;
}
#endif

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
#if(_HDMI21_FVA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI2.1 VTEM PKT Receive
// Input Value  : None
// Output Value : True  --> Enabled
//                False --> Disabled
//--------------------------------------------------
bit ScalerTMDSGetHdmi21VtemReceived(void)
{
    BYTE ucVtemReceived = 0x00;

    if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
    {
        ucVtemReceived |= _BIT3;
    }

    return ((ucVtemReceived != 0x00) ? _TRUE : _FALSE);
}
#endif

//--------------------------------------------------
// Description  : Clear HDMI2.1 VTEM PKT Receive
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSClrHdmi21VtemReceived(void)
{
    CLR_TMDS_HDMI21_VTEM_RECEIVED();
}

//--------------------------------------------------
// Description  : Get Vfreq from VIC Field of AVI IF
// Input Value  : Vic Index
// Output Value : Vfreq
//--------------------------------------------------
BYTE ScalerTMDSGetVicVfreqParameter(BYTE ucVicIndex)
{
    BYTE ucVicVfreq = 0x00;

    if(ucVicIndex != 0x00)
    {
        ucVicVfreq = tVIC_VFREQ_TABLE[ucVicIndex - 1];
    }

    return ucVicVfreq;
}

#if(_HDMI21_VRR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI2.1 VTEM's VRR feature (both VRR & VRR+FVA Case)
// Input Value  : None
// Output Value : True  --> Enabled
//                False --> Disabled
//--------------------------------------------------
bit ScalerTMDSMacRxGetHdmi21VrrStatus(void)
{
    if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Set EDID VRR Capability
// Input Value  : EnumInputPort, StructHdmi21EdidVrrCap
// Output Value : None
//--------------------------------------------------
void ScalerTMDSMacRxSetEdidVrrCapability(BYTE ucInputPort, StructHdmi21EdidVrrCap stEdidVrrCap)
{
    stEdidVrrCap = stEdidVrrCap;

    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
#if(_D0_HDMI_SUPPORT == _ON)
            memcpy(&g_stTmdsMacHdmi21EdidVrrCap, &stEdidVrrCap, sizeof(StructHdmi21EdidVrrCap));
#endif
            break;

        case _D1_INPUT_PORT:
#if(_D1_HDMI_SUPPORT == _ON)
            memcpy(&g_stTmdsMacHdmi21EdidVrrCap, &stEdidVrrCap, sizeof(StructHdmi21EdidVrrCap));
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Clr EDID VRR Capability
// Input Value  : EnumInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSMacRxClrEdidVrrCapability(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
#if(_D0_HDMI_SUPPORT == _ON)
            memset(&g_stTmdsMacHdmi21EdidVrrCap, 0, sizeof(StructHdmi21EdidVrrCap));
#endif
            break;

        case _D1_INPUT_PORT:
#if(_D1_HDMI_SUPPORT == _ON)
            memset(&g_stTmdsMacHdmi21EdidVrrCap, 0, sizeof(StructHdmi21EdidVrrCap));
#endif
            break;

        default:
            break;
    }
}
#endif
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI21 FVA Factor from VTEM
// Input Value  : enumInputPort
// Output Value : BYTE
//--------------------------------------------------
BYTE ScalerTMDSMacRxHdmi21GetFvaFactor(void)
{
    GET_TMDS_HDMI21_FVA_FACTOR();
}

//--------------------------------------------------
// Description  : Cal the Max IVf may sent
// Input Value  : pucReadArray: EDID address, usPixelClk: Input pixel clk(0.1M)
// Output Value : _TRUE: Get IVF, unit: 0.1Hz
//--------------------------------------------------
WORD ScalerTMDSMacRxCalFvaVfreqMax(StructFreeSyncEdidInfo *pstCatchEdidInfo, BYTE ucFavFactor)
{
    // ------------------------------------------------------------------------------------------------------
    // IVf_max = Pixel Rate * FVA_Factor / (Htotal * ((Vtotal * FVA_Factor) - Vactive * (FVA_Factor - 1)))
    // ------------------------------------------------------------------------------------------------------
    WORD usVfreq = 0x00;
    WORD usMinVtotal = (pstCatchEdidInfo->usVtotal * ucFavFactor) - (pstCatchEdidInfo->usVheight * (ucFavFactor - 1));

    usVfreq = ((GET_DWORD_MUL_DIV(pstCatchEdidInfo->usPixelClk, 1000000, usMinVtotal) + (pstCatchEdidInfo->usHtotal / 2)) / pstCatchEdidInfo->usHtotal);
    usVfreq *= ucFavFactor;

    return usVfreq;
}
#endif
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : InputPort and Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTMDSSetPorchColor(BYTE ucInputPort, EnumColorSpace enumColorFormat)
{
    ucInputPort = ucInputPort;

    ScalerTMDSRx0SetPorchColor(enumColorFormat);
}
#endif

//--------------------------------------------------
// Description  : TMDS Hot Plug Low Process
// Input Value  : ucPortSelect
// Output Value :
//--------------------------------------------------
void ScalerTMDSHotPlugLowProc(BYTE ucPortSelect)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_CABLE_STATUS() == _TRUE) && (GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D0_CABLE_STATUS() == _TRUE) && (GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_CABLE_STATUS() == _TRUE))
#else
            if(GET_D0_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
                if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() != _TMDS_HPD_EIZO_PS_WAKEUP)
#endif
                {
                    ScalerTMDSSwitchHdcpSlaveAddr(_D0_INPUT_PORT);
                }

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
                g_ucTmdsD0DdcramNackStatus = ScalerSyncGetDdcForceNackStatus(_D0_INPUT_PORT);

                if(g_ucTmdsD0DdcramNackStatus == _FALSE)
                {
                    // DDCRAM Force Nack
                    ScalerSyncSetDdcForceNack(_D0_INPUT_PORT, _ON);
                }

                // Set DDCCI Force Nack
                ScalerMcuDdcciEnable(_DISABLE, _D0_INPUT_PORT);
#endif
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE))
#else
            if(GET_D1_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
                if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() != _TMDS_HPD_EIZO_PS_WAKEUP)
#endif
                {
                    ScalerTMDSSwitchHdcpSlaveAddr(_D1_INPUT_PORT);
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

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _D2_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_CABLE_STATUS() == _TRUE) && (GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D2_CABLE_STATUS() == _TRUE) && (GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_CABLE_STATUS() == _TRUE))
#else
            if(GET_D2_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
                if(GET_TMDS_RX2_HPD_TRIGGER_EVENT() != _TMDS_HPD_EIZO_PS_WAKEUP)
#endif
                {
                    ScalerTMDSSwitchHdcpSlaveAddr(_D2_INPUT_PORT);
                }

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
                g_ucTmdsD2DdcramNackStatus = ScalerSyncGetDdcForceNackStatus(_D2_INPUT_PORT);

                if(g_ucTmdsD2DdcramNackStatus == _FALSE)
                {
                    // DDCRAM Force Nack
                    ScalerSyncSetDdcForceNack(_D2_INPUT_PORT, _ON);
                }

                // Set DDCCI Force Nack
                ScalerMcuDdcciEnable(_DISABLE, _D2_INPUT_PORT);
#endif
            }

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Hot Plug High Process
// Input Value  : ucPortSelect, usHpdTime
// Output Value :
//--------------------------------------------------
void ScalerTMDSHotPlugHighProc(BYTE ucPortSelect, WORD usHpdTime)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_CABLE_STATUS() == _TRUE) && (GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D0_CABLE_STATUS() == _TRUE) && (GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_CABLE_STATUS() == _TRUE))
#else
            if(GET_D0_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                ScalerTimerDelayXms(usHpdTime);

                PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D1_CABLE_STATUS() == _TRUE) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_CABLE_STATUS() == _TRUE))
#else
            if(GET_D1_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                ScalerTimerDelayXms(usHpdTime);

                PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
            }

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _D2_INPUT_PORT:

            // MHL mode of MHL_PORT can not pull HPD
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_CABLE_STATUS() == _TRUE) && (GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
            if((GET_D2_CABLE_STATUS() == _TRUE) && (GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE))
#endif
#else
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_CABLE_STATUS() == _TRUE))
#else
            if(GET_D2_CABLE_STATUS() == _TRUE)
#endif
#endif
            {
                ScalerTimerDelayXms(usHpdTime);

                PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
            }

            break;
#endif

        default:

            break;
    }
}
#endif // End of  #if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))
