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
// ID Code      : ScalerTMDSRx3_SeptPhy.c No.0000
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
StructHdmiSpdInfo g_stTmdsMacRx3SpdInfo;
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
#if(_D3_TMDS_SUPPORT == _ON)
void ScalerTMDSRx3DviVideoSetting(void);
void ScalerTMDSRx3FirstActiveProc(BYTE ucSourceType);
void ScalerTMDSRx3SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
EnumDeOnlyConfig ScalerTMDSRx3GetDeOnlyModeConfig(void);
void ScalerTMDSRx3PowerOffProc(void);
BYTE ScalerTMDSRx3TMDSVideoDetect(bit bWait);
void ScalerTMDSRx3TMDSVideoDetectEvent(void);
void ScalerTMDSRx3PSIntHandler_EXINT0(void);

#if(_D3_HDMI_SUPPORT == _ON)
bit ScalerTMDSRx3HdmiAviPixelRepInfoChanged(void);
BYTE ScalerTMDSRx3HdmiGetAVIInfo(EnumAviInfoContent enumContent);
BYTE ScalerTMDSRx3HdmiGetColorDepth(void);
void ScalerTMDSRx3HdmiPacketDetectEvent(void);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
void ScalerTMDSRx3SpdInfoPacketDetect(bit bWait);
void ScalerTMDSRx3HdmiGetSpdInfo(void);
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
void ScalerTMDSRx3HDMI2HPDRRIRQEnable(bit bEnable);
void ScalerTMDSRx3SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
void ScalerTMDSRx3SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
void ScalerTMDSRx3ScrambleStatusReset(void);
void ScalerTMDSRx3ScrambleDetectTimeoutTimerEvent(void);
void ScalerTMDSRx3ScrambleDetectDisable(void);
void ScalerTMDSRx3Hdmi2FormatResetEvent(void);
void ScalerTMDSRx3ReadRequestProc_EXINT0(BYTE ucRROutCome);
void ScalerTMDSRx3ReadRequestTimerEventEnable_WDINT(bit bEnable);
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
bit ScalerTMDSRx3HdmiDeepColorProc(WORD usTmdsClkCnt);
bit ScalerTMDSRx3HdmiWaitDeepColorPllLock(void);
#endif

#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
bit ScalerTMDSRx3TMDSNormalPreDetect(void);
bit ScalerTMDSRx3TMDSPSPreDetect(void);
#endif

#endif

void ScalerTMDSRx3HotPlugLowProc(void);
void ScalerTMDSRx3HotPlugHighProc(WORD usHpdTime);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D3_TMDS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3DviVideoSetting(void)
{
    // Manual Set Color Space and disable pixel repetition
    ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable Down Sampling
    ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_50_PORT_PAGE72_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Waiting for Down Sampling Effect
    ScalerTimerDelayXms(20);

    SET_COLOR_SPACE(_COLOR_SPACE_RGB);
    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

    ScalerTMDSRx3SetPorchColor(GET_COLOR_SPACE());
}
//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3FirstActiveProc(BYTE ucSourceType)
{
    ucSourceType = ucSourceType;
}

//--------------------------------------------------
// Description  : Set Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : enumInputPort, enumDeonlyConfig
//--------------------------------------------------
void ScalerTMDSRx3SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig)
{
    // De only enable?
    if((enumDeonlyConfig & _DE_ONLY_DISABLE) == _DE_ONLY_DISABLE)
    {
        ScalerSetBit(P72_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
    }
    else if((enumDeonlyConfig & _DE_ONLY_ENABLE) == _DE_ONLY_ENABLE)
    {
        ScalerSetBit(P72_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
    }

    // Set HS
    if((enumDeonlyConfig & _DE_ONLY_HS_8T) == _DE_ONLY_HS_8T)
    {
        ScalerSetBit(P72_AB_TMDS_ACC2, ~_BIT7, _BIT7);
    }
    else if((enumDeonlyConfig & _DE_ONLY_HS_72T) == _DE_ONLY_HS_72T)
    {
        ScalerSetBit(P72_AB_TMDS_ACC2, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Get Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : EnumDeOnlyConfig
//--------------------------------------------------
EnumDeOnlyConfig ScalerTMDSRx3GetDeOnlyModeConfig(void)
{
    EnumDeOnlyConfig enumDeConfig = _DE_NO_INDICATED;

    if(ScalerGetBit(P72_A7_TMDS_PWDCTL, _BIT7) == _BIT7)
    {
        enumDeConfig = _DE_ONLY_ENABLE;
    }
    else
    {
        enumDeConfig = _DE_ONLY_DISABLE;
    }

    if(ScalerGetBit(P72_AB_TMDS_ACC2, _BIT7) == _BIT7)
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
void ScalerTMDSRx3PowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_FE72_DDC3_EDID_IRQ = ((MCU_FE72_DDC3_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));

    ScalerTMDSRx3FreqDetectDisable();

#if(_D3_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx3ScrambleDetectDisable();
#endif
}
//--------------------------------------------------
// Description  : Detect TMDS video mode
// Input Value  : bWait => Whether to wait then read
// Output Value : TMDS video type
//--------------------------------------------------
BYTE ScalerTMDSRx3TMDSVideoDetect(bit bWait)
{
    BYTE ucTemp = _TMDS_VIDEO_DATA_NONE;

    if(bWait == _WAIT)
    {
        // Wait at least 1 frame for HW auto update TMDS video RGBHV valid value
        ScalerTimerPollingFlagProc(45, P72_A4_TMDS_CTRL, _BIT3, _TRUE);

        // Wait for HW update DE flag
        if(ScalerTimerPollingFlagProc(20, P72_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // H/Vsync received
            if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
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

        CLR_TMDS_RX3_RGBHV_DETECTING();

        return ucTemp;
    }
    else
    {
        // R/G/B data detected
        if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
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
        ScalerSetBit(P72_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        SET_TMDS_RX3_RGBHV_DETECTING();

        // Activate TMDS video Detection Event
        ScalerTimerActiveTimerEvent(45, _SCALER_TIMER_EVENT_RX3_TMDS_VIDEO_DETECT);

        return ucTemp;
    }
}
//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3TMDSVideoDetectEvent(void)
{
    CLR_TMDS_RX3_RGBHV_DETECTING();
}

//--------------------------------------------------
// Description  : TMDS Interrupt Process In PS/PD State(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3PSIntHandler_EXINT0(void) using 1
{
#if(_D3_HDMI_2_0_SUPPORT == _ON)
    BYTE pucBackUp[6];
#else
    BYTE pucBackUp[4];
#endif

    pucBackUp[0] = ScalerGetByte_EXINT(P72_C9_HDMI_AP);
    pucBackUp[1] = (ScalerGetByte_EXINT(P72_C8_HDMI_APC) & 0x01);

    // Set CA Port non-auto increase
    ScalerSetBit_EXINT(P72_C8_HDMI_APC, ~_BIT0, 0x00);

    pucBackUp[2] = ScalerGetByte_EXINT(P72_C3_HDCP_AP);
    pucBackUp[3] = (ScalerGetByte_EXINT(P72_C2_HDCP_PCR) & 0x01);

    // Set C4 Port non-auto increase
    ScalerSetBit_EXINT(P72_C2_HDCP_PCR, ~(_BIT4 | _BIT0), _BIT0);

#if(_D3_HDMI_2_0_SUPPORT == _ON)
    pucBackUp[4] = ScalerGetByte_EXINT(P72_39_HDMI_CTRL_39);
    pucBackUp[5] = (ScalerGetByte_EXINT(P72_38_HDMI_CTRL_38) & 0x01);

    // Set 3A Port non-auto increase
    ScalerSetBit_EXINT(P72_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif

    // HDCP 1.4 Write Aksv IRQ have been Received
    if((ScalerGetBit_EXINT(P72_A9_TMDS_ABC0, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(P72_AA_TMDS_ABC1, _BIT4) == _BIT4))
    {
        // clear AKSV & Ri flag
        ScalerSetBit_EXINT(P72_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT7 | _BIT6));

        // SET KEY ready bit 1
        ScalerSetBit_EXINT(P72_AE_TMDS_RPS, ~_BIT1, _BIT1);

#if(_TMDS_HDCP_2_2_SUPPORT == _ON)
        // Enable HDCP 1.4 Module
        ScalerSetBit_EXINT(P72_C0_HDCP_CR, ~(_BIT7 | _BIT0), (_BIT7 | _BIT0));

        // Disable HDCP 2 Function
        ScalerSetBit_EXINT(P2E_26_HDCP_I2C_CTRL_0, ~_BIT7, 0x00);
#endif
    }

#if(_D3_HDMI_2_0_SUPPORT == _ON)
    // Detect Source Write Read Request Enable Flag
    if((ScalerGetBit_EXINT(P72_25_HDMI_CTRL_25, _BIT3) == _BIT3) && (ScalerGetBit_EXINT(P72_26_HDMI_CTRL_26, _BIT3) == _BIT3))
    {
        // Clear Read Request Flag
        ScalerSetBit_EXINT(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Set Read Request Enable
        SET_HDMI_2_0_RX3_RR_ENABLE();

        // Enable Test Read Request HW Auto Mode
        ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT1, _BIT1);

        // Enable CED Update Read Request Auto Mode
        ScalerSetBit_EXINT(P72_24_HDMI_CTRL_24, ~_BIT0, _BIT0);

        // Enable Read Request Done IRQ
        ScalerSetBit_EXINT(P72_1F_HDMI_CTRL_1F, ~_BIT3, _BIT3);
    }

    // Read Request Done into IRQ
    if((ScalerGetBit_EXINT(P72_1F_HDMI_CTRL_1F, _BIT3) == _BIT3) && (ScalerGetBit_EXINT(P72_1C_HDMI_CTRL_1C, _BIT7) == _BIT7))
    {
        // Clear Read Request Done Flag
        ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT7, _BIT7);

        // Read Request Outcome Processing
        ScalerTMDSRx3ReadRequestProc_EXINT0(ScalerGetByte_EXINT(P72_1C_HDMI_CTRL_1C) & 0x70);
    }

    // Detect HDMI HPD Rising to Falling into IRQ
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
    if(ScalerGetBit_EXINT(P72_23_HDMI_CTRL_23, (_BIT6 | _BIT1)) == (_BIT6 | _BIT1))
    {
        // Clear HPD IRQ Flag
        ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT1, _BIT1);

        if(ScalerGetBit_EXINT(P72_23_HDMI_CTRL_23, (_BIT2 | _BIT0)) == 0x00)
        {
            // Clear All Source Write SCDC Port Register
            ScalerSetBit_EXINT(P72_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

            ScalerTMDSHdmiSetScdcInfo_EXINT0(_D3_INPUT_PORT);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(ScalerTMDSHdmiGetFreeSyncSupport_EXINT0(_D3_INPUT_PORT) == _FREESYNC_SUPPORT_ON)
            {
                ScalerTMDSHdmiSetAmdAupiScdcInfo_EXINT0(_D3_INPUT_PORT, _ENABLE);
            }
            else
            {
                ScalerTMDSHdmiSetAmdAupiScdcInfo_EXINT0(_D3_INPUT_PORT, _DISABLE);
            }
#endif
            // Clear HDMI 2.0 Read Request Enable
            CLR_HDMI_2_0_RX3_RR_ENABLE();

            // Disable Rising to Falling IRQ, Set IRQ Status Falling to Rising edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

            // Enable Falling to Rising edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);

            /*
            // Disable Test Read Request HW Auto Mode
            ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT1, 0x00);

            // Disable CED Update Read Request Auto Mode
            ScalerSetBit_EXINT(P72_24_HDMI_CTRL_24, ~_BIT0, 0x00);

            // Disable Character Error Detection Function
            ScalerSetBit_EXINT(P72_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

            // Disable Lock Transition IRQ
            ScalerSetBit_EXINT(P72_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            ScalerSetBit_EXINT(P72_17_HDMI_CTRL_17, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // Detect 3 Channel CDR Stable
            if((bit)ScalerTMDSRx3CheckCDRStable_EXINT(g_usTMDSRx3ClkCount) == _TRUE)
            {
                // Disable Rising to Falling IRQ, Set IRQ Status Falling to Rising edge IRQ
                ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

                // Enable Falling to Rising edge IRQ
                ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);
            }
            */
        }
        else
        {
            /*
            // Enable CED Function
            ScalerSetBit_EXINT(P72_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));

            // Enable CED Lock Transition IRQ
            ScalerSetBit_EXINT(P72_17_HDMI_CTRL_17, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            ScalerSetBit_EXINT(P72_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // Enable SCDC Module
            ScalerSetBit_EXINT(P72_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
            */

            // Disable Falling to Rising IRQ, Set IRQ Status Rising to Falling edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), _BIT1);

            // Enable Rising to Falling edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);
        }
    }
#endif // End of #if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
#endif // End of #if(_D3_HDMI_2_0_SUPPORT == _ON)

    // Clear IRQ Pending Flag
    ScalerSetByte_EXINT(P72_C9_HDMI_AP, _P72_CA_PT_60_PORT_PAGE72_HDMI_INTCR);
    ScalerSetBit_EXINT(P72_CA_HDMI_DP, ~_BIT7, _BIT7);

    ScalerSetBit_EXINT(P72_C8_HDMI_APC, ~_BIT0, pucBackUp[1]);
    ScalerSetByte_EXINT(P72_C9_HDMI_AP, pucBackUp[0]);

    ScalerSetBit_EXINT(P72_C2_HDCP_PCR, ~(_BIT4 | _BIT0), pucBackUp[3]);
    ScalerSetByte_EXINT(P72_C3_HDCP_AP, pucBackUp[2]);

#if(_D3_HDMI_2_0_SUPPORT == _ON)
    ScalerSetBit_EXINT(P72_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1 | _BIT0), pucBackUp[5]);
    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, pucBackUp[4]);
#endif
}

#if(_D3_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect HDMI AVI pixel repetition
// Input Value  : None
// Output Value : _TRUE => Current Info is different from previous setting
//--------------------------------------------------
bit ScalerTMDSRx3HdmiAviPixelRepInfoChanged(void)
{
    // Check Tmds Pixel Repetition
    if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION) != GET_TMDS_RX3_AVI_PIXEL_REPETITION())
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSRx3HdmiGetAVIInfo(EnumAviInfoContent enumContent)
{
    if(GET_HDMI_RX3_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _AVI_INFO_COLOR_SPACE:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x04, (_BIT6 | _BIT5)) >> 5);

            case _AVI_INFO_COLORIMETRY:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x05, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_EXTENDED_COLORIMETRY:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, (_BIT6 | _BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_RGB_QUANTIZATION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, (_BIT3 | _BIT2)) >> 2);

            case _AVI_INFO_YCC_QUANTIZATION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x08, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_SCAN_INFO:

                return ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x04, (_BIT1 | _BIT0));

            case _AVI_INFO_IT_CONTENT:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, _BIT7) >> 7);

            case _AVI_INFO_PIXEL_REPETITION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x08, (_BIT3 | _BIT2 | _BIT1 | _BIT0)));

            case _AVI_INFO_AR:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x05, (_BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_VIC:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x07, (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));

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
BYTE ScalerTMDSRx3HdmiGetColorDepth(void)
{
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        return _COLOR_DEPTH_12_BITS;
    }

    if(GET_HDMI_RX3_GCP_RECEIVED() == _TRUE)
    {
        if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x05)
        {
            return _COLOR_DEPTH_10_BITS;
        }
        else if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x06)
        {
            return _COLOR_DEPTH_12_BITS;
        }
        else if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x07)
        {
            return _COLOR_DEPTH_16_BITS;
        }
    }

    return _COLOR_DEPTH_8_BITS;
}
//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3HdmiPacketDetectEvent(void)
{
    CLR_HDMI_RX3_PACKET_DETECTING();
}

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI SPD Info Frame Packet Detect
// Input Value  : bWait
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3SpdInfoPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
        // Polling 3 frame for RSV4 received check
        if(ScalerTimerPollingDataBitFlagProc(130, P72_C9_HDMI_AP, _P72_CA_PT_00_PORT_PAGE72_HDMI_SCR, _BIT7, _TRUE) == _TRUE)
        {
            ScalerTMDSRx3HdmiGetSpdInfo();
        }
    }
    else
    {
        // Check RSV4 received bit
        if(ScalerGetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_00_PORT_PAGE72_HDMI_SCR, _BIT7) == _BIT7)
        {
            ScalerTMDSRx3HdmiGetSpdInfo();
        }
    }
}

//--------------------------------------------------
// Description  : Get SPD Info Product Description
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3HdmiGetSpdInfo(void)
{
    BYTE pucHdmiVenderName[4] = {0};

    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x90, 4, &pucHdmiVenderName[0], _AUTOINC);

    if(((pucHdmiVenderName[0] == 'M') || (pucHdmiVenderName[0] == 'S')) &&
       ((pucHdmiVenderName[1] == 'S') || (pucHdmiVenderName[1] == 'C')) &&
       ((pucHdmiVenderName[2] == 'F') || (pucHdmiVenderName[2] == 'E')) &&
       ((pucHdmiVenderName[3] == 'T') || (pucHdmiVenderName[3] == 'I')))
    {
        g_stTmdsMacRx3SpdInfo.b1StructValuable = 0x01;
        memcpy(&g_stTmdsMacRx3SpdInfo.pucHdmiVendorName[0], pucHdmiVenderName, 4);

        ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x98, 8, &g_stTmdsMacRx3SpdInfo.pucHdmiProductDescription[0], _AUTOINC);
    }
}
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS HPD IRQ Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3HDMI2HPDRRIRQEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Set HPD Debounce = 700 Clock Cycle
        // Set HPD IRQ Detect Rising to Falling Edge IRQ
        ScalerSetBit(P72_23_HDMI_CTRL_23, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT5 | _BIT4 | _BIT3 | _BIT1));

        // Enable HDMI HPD IRQ Enable
        ScalerSetBit(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);

        // Write 1 Clear Read Request
        ScalerSetBit(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Enable HDMI 2.0 SCDC IIC Module
        ScalerSetBit(P72_19_HDMI_CTRL_19, ~_BIT7, _BIT7);

        // Clear HDMI 2.0 Read Request Enable
        CLR_HDMI_2_0_RX3_RR_ENABLE();

        // Enable HDMI 2.0 Read Request Enable Detect IRQ
        ScalerSetBit(P72_26_HDMI_CTRL_26, ~_BIT3, _BIT3);
    }
    else
    {
        // Write 1 Clear Read Request
        ScalerSetBit(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Clear HDMI 2.0 Read Request Enable
        CLR_HDMI_2_0_RX3_RR_ENABLE();

        // Disable HDMI 2.0 Read Request Enable Detect IRQ
        ScalerSetBit(P72_26_HDMI_CTRL_26, ~_BIT3, 0x00);
    }
}

//--------------------------------------------------
// Description  : TMDS Set SCDC Info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3SetScdcInfo_EXINT0(void) using 1
{
    // Set SCDC Info
    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D0_PORT_PAGE72_HDMI_SCDC_D0);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D1_PORT_PAGE72_HDMI_SCDC_D1);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D2_PORT_PAGE72_HDMI_SCDC_D2);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D3_PORT_PAGE72_HDMI_SCDC_D3);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D4_PORT_PAGE72_HDMI_SCDC_D4);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D5_PORT_PAGE72_HDMI_SCDC_D5);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D6_PORT_PAGE72_HDMI_SCDC_D6);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D7_PORT_PAGE72_HDMI_SCDC_D7);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D8_PORT_PAGE72_HDMI_SCDC_D8);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_D9_PORT_PAGE72_HDMI_SCDC_D9);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_DA_PORT_PAGE72_HDMI_SCDC_DA);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_DB_PORT_PAGE72_HDMI_SCDC_DB);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_DC_PORT_PAGE72_HDMI_SCDC_DC);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);

    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_DD_PORT_PAGE72_HDMI_SCDC_DD);
    ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Set AMD AUPI SCDC Info
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3SetAmdAupiScdcInfo_EXINT0(bit bEnable) using 1
{
    if(GET_FREESYNC_HDMI_AUPI_INFO() != _TRUE)
    {
        return;
    }

    if(bEnable == _ENABLE)
    {
        // Set SCDC Info
        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E0_PORT_PAGE72_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E1_PORT_PAGE72_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E2_PORT_PAGE72_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E3_PORT_PAGE72_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E4_PORT_PAGE72_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E5_PORT_PAGE72_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E6_PORT_PAGE72_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E7_PORT_PAGE72_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);
    }
    else
    {
        // Set SCDC Info
        // Set SCDC Info
        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E0_PORT_PAGE72_HDMI_SCDC_E0);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E1_PORT_PAGE72_HDMI_SCDC_E1);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E2_PORT_PAGE72_HDMI_SCDC_E2);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E3_PORT_PAGE72_HDMI_SCDC_E3);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E4_PORT_PAGE72_HDMI_SCDC_E4);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E5_PORT_PAGE72_HDMI_SCDC_E5);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E6_PORT_PAGE72_HDMI_SCDC_E6);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);

        ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, _P72_3A_PT_E7_PORT_PAGE72_HDMI_SCDC_E7);
        ScalerSetByte_EXINT(P72_3A_HDMI_CTRL_3A, 0x00);
    }
}
#endif
#endif

//--------------------------------------------------
// Description  : Scramble Status Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ScrambleStatusReset(void)
{
    // Set Scramble Detect Manual Mode
    ScalerSetBit(P72_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), 0x00);

    // Disable Scrambling Status
    ScalerSetDataPortBit(P72_39_HDMI_CTRL_39, _P72_3A_PT_21_PORT_PAGE72_HDMI_SCDC_21, ~_BIT0, 0x00);

    // Clear Scrambling Detection Flag
    ScalerSetBit(P72_01_HDMI_CTRL_01, ~_BIT3, _BIT3);

    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX3_HDMI2_SCRAMBLE_DETECT_TIMEOUT);
}

//--------------------------------------------------
// Description  : Scramble Detect timeout event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ScrambleDetectTimeoutTimerEvent(void)
{
    // Set Scramble Detect Auto Mode
    ScalerSetBit(P72_38_HDMI_CTRL_38, ~(_BIT4 | _BIT2 | _BIT1), _BIT4);

    ScalerTMDSRx3ScrambleDetectDisable();
}

//--------------------------------------------------
// Description  : TMDS Scramble Detection IRQ Disable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ScrambleDetectDisable(void)
{
    // Disable SCDC 0x20 Change IRQ
    ScalerSetBit(P72_26_HDMI_CTRL_26, ~_BIT4, 0x00);
}

//--------------------------------------------------
// Description  : TMDS Format Reset Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3Hdmi2FormatResetEvent(void)
{
    CLR_TMDS_RX3_HDMI_2_0_FORMAT_RESET_WAITING();
}
//--------------------------------------------------
// Description  : TMDS Read Request Outcome Case Processing(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ReadRequestProc_EXINT0(BYTE ucRROutCome) using 1
{
    // Get Read Request Outcome Case
    switch(ucRROutCome)
    {
        case _HDMI_2_0_READ_REQUEST_ACK_DONE:
        case _HDMI_2_0_READ_REQUEST_ACK_STOP:

            break;

        case _HDMI_2_0_READ_REQUEST_NACK1:

            if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
            {
                // FW Manual Enable Read Request
                ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, _BIT7);
            }

            break;

        case _HDMI_2_0_READ_REQUEST_NACK2:

#if(_WD_TIMER_INT_SUPPORT == _ON)
            if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
            {
                // Enable Read Request Retry
                ScalerTimerWDActivateTimerEvent_EXINT0(10, _SCALER_WD_TIMER_EVENT_RX3_HDMI_RR_RETRY);
            }
#endif

            break;

        default:

            break;
    }
}
//--------------------------------------------------
// Description  : TMDS Read Request Timer Event Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ReadRequestTimerEventEnable_WDINT(bit bEnable) using 3
{
    if(bEnable == _ENABLE)
    {
        if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
        {
            // FW Manual Enable Read Request
            ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, _BIT7);
        }
    }
    else
    {
        // Disable Read Request Enable
        ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, 0x00);
    }
}
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : HDMI Deep Color Proc
// Input Value  : void
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerTMDSRx3HdmiDeepColorProc(WORD usTmdsClkCnt)
{
    // Setting Deep Color PLL
    if(ScalerTMDSRx3HdmiSetDeepColorPll(usTmdsClkCnt, GET_COLOR_DEPTH()) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for Phase lock
    if(ScalerTMDSRx3HdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Wait for Deep Color PLL Phase Lock
// Input Value  : None
// Output Value : _TRUE = > Phase Locked
//--------------------------------------------------
bit ScalerTMDSRx3HdmiWaitDeepColorPllLock(void)
{
    BYTE ucTemp = 0;

    do
    {
        ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_82_PORT_PAGE72_HDMI_DPC_SET2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Delay for PLL Phase Lock
        ScalerTimerDelayXms(2);

        ucTemp++;
    }
    while((ScalerGetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_82_PORT_PAGE72_HDMI_DPC_SET2, _BIT1) != 0) && (ucTemp <= 15));

    if(ucTemp > 15)
    {
        return _FALSE;
    }

    return _TRUE;
}
#endif
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSRx3TMDSNormalPreDetect(void)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(_D3_INPUT_PORT) == _FALSE)
#endif
    {
        // DDC handshake Detected
        if(GET_TMDS_RX3_DDC_DETECTED() == _TRUE)
        {
            DebugMessageRx3("7. Normal D3 DDC", 0);

            CLR_TMDS_RX3_DDC_DETECTED();

            return _TRUE;
        }
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE72_DDC3_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX3_DDC_DETECTED() != _TRUE))
    {
        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
        MCU_FE72_DDC3_EDID_IRQ |= _BIT3;

        CLR_TMDS_RX3_DDC_DETECTED();
    }

    ScalerTimerDelayXms(6);

    if(GET_TMDS_RX3_PHY_SET() == _TRUE)
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
bit ScalerTMDSRx3TMDSPSPreDetect(void)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(_D3_INPUT_PORT) == _FALSE)
#endif
    {
        // DDC handshake Detected
        if(GET_TMDS_RX3_DDC_DETECTED() == _TRUE)
        {
            DebugMessageRx3("7. PowerSaving D3 DDC", 0);

            CLR_TMDS_RX3_DDC_DETECTED();

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
            SET_D3_HDMI_PS_WAKEUP();
#endif

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            SET_TMDS_RX3_TOGGLE_Z0();
#endif
            return _TRUE;
        }
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE72_DDC3_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX3_DDC_DETECTED() != _TRUE))
    {
        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
        MCU_FE72_DDC3_EDID_IRQ |= _BIT3;
    }

    // Reset Freq. Detect Counter(Toggle) & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

    // Clear Freq. Stable Flag
    ScalerSetBit(P72_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

    // Delay enough time for freq. measure (calculated for measure 5 times)
    ScalerTimerDelayXms(5);

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P72_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P72_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
        SET_D3_HDMI_PS_WAKEUP();
#endif

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
        SET_TMDS_RX3_TOGGLE_Z0();
#endif
        return _TRUE;
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

        return _FALSE;
    }

    return _FALSE;
}
#endif

#endif

//--------------------------------------------------
// Description  : HPD Low Process
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx3HotPlugLowProc(void)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D3_CABLE_STATUS() == _TRUE) && (GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) &&
       (((GET_D3_CABLE_STATUS() == _TRUE) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)) ||
        ((GET_D12_CABLE_STATUS() == _TRUE) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1))))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D3_CABLE_STATUS() == _TRUE))
#endif
#endif
    {
        PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
        if(GET_TMDS_RX3_HPD_TRIGGER_EVENT() != _TMDS_HPD_EIZO_PS_WAKEUP)
#endif
        {
            ScalerTMDSRx3SwitchHdcpSlaveAddr();
        }

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
        g_ucTmdsD3DdcramNackStatus = ScalerSyncGetDdcForceNackStatus(_D3_INPUT_PORT);

        if(g_ucTmdsD3DdcramNackStatus == _FALSE)
        {
            // DDCRAM Force Nack
            ScalerSyncSetDdcForceNack(_D3_INPUT_PORT, _ON);
        }

        // Set DDCCI Force Nack
        ScalerMcuDdcciEnable(_DISABLE, _D3_INPUT_PORT);
#endif
    }
}

//--------------------------------------------------
// Description  : HPD High Process
// Input Value  : usHpdTime
// Output Value :
//--------------------------------------------------
void ScalerTMDSRx3HotPlugHighProc(WORD usHpdTime)
{
    // MHL mode of MHL PORT can not pull HPD
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D3_CABLE_STATUS() == _TRUE) && (GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE))
#else
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) &&
       (((GET_D3_CABLE_STATUS() == _TRUE) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)) ||
        ((GET_D12_CABLE_STATUS() == _TRUE) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1))))
#else
    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D3_CABLE_STATUS() == _TRUE))
#endif
#endif
    {
        ScalerTimerDelayXms(usHpdTime);

        PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
    }
}
#endif
