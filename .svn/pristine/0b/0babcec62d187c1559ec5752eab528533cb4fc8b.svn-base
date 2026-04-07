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
// ID Code      : RL6449_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_AUDIO_SUPPORT == _ON)

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
#if(_D0_DP_EXIST == _ON)
StructAudioDigitalInfo g_stAudioD0DigtalInfo;
StructAudioFreqParameter g_stAudioD0FreqParameter;
StructAudioDpCodingType g_stDpAudioD0CodingType;
#endif

#if(_D1_DP_EXIST == _ON)
StructAudioDigitalInfo g_stAudioD1DigtalInfo;
StructAudioFreqParameter g_stAudioD1FreqParameter;
StructAudioDpCodingType g_stDpAudioD1CodingType;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
StructAudioDigitalInfo g_stAudioD2DigtalInfo;
StructAudioFreqParameter g_stAudioD2FreqParameter;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
StructAudioFwTrackingInfo g_stHDMID2AudioFwTrackingInfo;
#endif
#endif

#if(_D3_HDMI_SUPPORT == _ON)
StructAudioDigitalInfo g_stAudioD3DigtalInfo;
StructAudioFreqParameter g_stAudioD3FreqParameter;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
StructAudioFwTrackingInfo g_stHDMID3AudioFwTrackingInfo;
#endif
#endif

#if(_DP_SUPPORT == _ON)
StructAudioDpCapabilityInfo g_stAudioDpCapabilityInfo;
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
BYTE g_ucAudioGenInputPort;
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerAudioDigitalAudioInitial(void);
void ScalerAudioDisableAudioPLL(void);
void ScalerAudioDigitalDetect(void);
void ScalerAudioDigitalEnable(BYTE ucInputPort);
void ScalerAudioDigitalReset(BYTE ucInputPort);
bit ScalerAudioGetAudioDetected(BYTE ucInputPort);
EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
bit ScalerAudioSamplingFreqChange(void);
bit ScalerAudioLPCMCheckData(void);
bit ScalerAudioLPCMCheckChange(void);
void ScalerAudioLPCMDetectEnableProc(BYTE ucInputPort);
void ScalerAudioLPCMResetProc(BYTE ucInputPort);
void ScalerAudioDigitalOutputMute(bit bMute);
void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort);
void ScalerAudioHbrModeControl(bit bOn, BYTE ucInputPort);
void ScalerAudioLoadStableICodeEvent(EnumScalerTimerEventID enumEventID);
void ScalerAudioSourceInputSwitch(EnumAudioInputSource enumAudioSource, BYTE ucInputPort);
EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
void ScalerAudioFwTrackingHandler(void);
void ScalerAudioFwTrackingEventSet(EnumScalerTimerEventID enumEventID);
void ScalerAudioTimeoutEventSet(EnumScalerTimerEventID enumEventID);
#endif

#if((_D2_HDMI_SUPPORT == _ON) || ((_INTERNAL_AUDIO_TEST_SUPPORT == _ON) && ((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON))))
void ScalerAudioD2HDMIAudioInitial(void);
void ScalerAudioD2SetAudioPLL(void);
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_D2_HDMI_SUPPORT == _ON)
EnumAudioSamplingFreqType ScalerAudioD2SamplingFreqDetect(void);
#endif

void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
bit ScalerAudioLPCMCheckInfo(void);
EnumSourceTypeDef ScalerAudioDigitalAudioSourceType(void);
#endif

#if(_DP_SUPPORT == _ON)
void ScalerAudioDPDigitalOutputProc(bit bEnable, BYTE ucInputPort);
bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);

#if(_D0_DP_EXIST == _ON)
void ScalerAudioD0SetAudioPLL(void);
void ScalerAudioD0LoadInitialICode(void);
void ScalerAudioD0LoadStableICodeEvent(void);
void ScalerAudioD0DigitalDetectProc(void);
bit ScalerAudioD0GetAudioDetected(void);
EnumAudioSamplingFreqType ScalerAudioD0SamplingFreqDetect(void);
bit ScalerAudioD0SamplingFreqChange(void);
void ScalerAudioD0WatchDogProc(bit bOn);
void ScalerAudioD0HbrAudioDetect(void);
void ScalerAudioD0HbrModeControl(bit bEnable);
#endif

#if(_D1_DP_EXIST == _ON)
void ScalerAudioD1SetAudioPLL(void);
void ScalerAudioD1LoadInitialICode(void);
void ScalerAudioD1LoadStableICodeEvent(void);
void ScalerAudioD1DigitalDetectProc(void);
bit ScalerAudioD1GetAudioDetected(void);
EnumAudioSamplingFreqType ScalerAudioD1SamplingFreqDetect(void);
bit ScalerAudioD1SamplingFreqChange(void);
void ScalerAudioD1WatchDogProc(bit bOn);
void ScalerAudioD1HbrAudioDetect(void);
void ScalerAudioD1HbrModeControl(bit bEnable);
#endif

#endif

BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

#if(_LINE_IN_SUPPORT == _ON)
void ScalerAudioADCInitial(void);
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void ScalerAudioInternalAudioGenSwitch(bit bOn, BYTE ucInputPort, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
void ScalerAudioInternalAudioGenReset(BYTE ucInputPort);
void ScalerAudioSetInternalGenInputPort(BYTE ucInputPort);
BYTE ScalerAudioGetInternalGenInputPort(void);

#if((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON))
void ScalerAudioDpInternalAudioGenSwitch(bit bOn, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
bit ScalerAudioDpGetInternalAudioGenEnable(void);
#endif
#endif

#if(_DP_TX_SUPPORT == _ON)
StructAudioChannelInfo ScalerAudioGetRxChannelStatus(void);
#endif // End of #if(_DP_TX_SUPPORT == _ON)


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial HDMI/DP audio setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalAudioInitial(void)
{
#if(_D0_DP_EXIST == _ON)
    ScalerAudioD0DPAudioInitial();
#endif

#if(_D1_DP_EXIST == _ON)
    ScalerAudioD1DPAudioInitial();
#endif

#if((_D2_HDMI_SUPPORT == _ON) || ((_INTERNAL_AUDIO_TEST_SUPPORT == _ON) && ((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON))))
    ScalerAudioD2HDMIAudioInitial();
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    ScalerAudioD3HDMIAudioInitial();
#endif
}

//--------------------------------------------------
// Description  : Disable Auido PLL Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDisableAudioPLL(void)
{
#if(_LINE_IN_SUPPORT == _ON)
    // Power Down ADC PLL
    ScalerSetBit(PBF_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);
#endif

#if(_D0_DP_EXIST == _ON)
    // Power Down D0 DPLL
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);
#endif

#if(_D1_DP_EXIST == _ON)
    // Power Down D1 DPLL
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);
#endif

#if(_D2_HDMI_SUPPORT == _ON)
    // Power Down D2 DPLL
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT7, _BIT7);
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    // Power Down D3 DPLL
    ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_38_PORT_PAGE72_HDMI_DPCR0, ~_BIT7, _BIT7);
#endif
}

//--------------------------------------------------
// Description  : Detect digital audio for HDMI/DP interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalDetect(void)
{
#if(_D0_DP_EXIST == _ON)
    ScalerAudioD0DigitalDetectProc();
#endif

#if(_D1_DP_EXIST == _ON)
    ScalerAudioD1DigitalDetectProc();
#endif

#if(_D2_HDMI_SUPPORT == _ON)
    ScalerAudioD2DigitalDetectProc();
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    ScalerAudioD3DigitalDetectProc();
#endif
}

//--------------------------------------------------
// Description  : Enable Digital Audio Proc
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalEnable(BYTE ucInputPort)
{
    ScalerAudioLPCMDetectEnableProc(ucInputPort);

    ScalerAudioWatchDogProc(_ON, ucInputPort);
}

//--------------------------------------------------
// Description  : Reset Digital Audio Proc
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalReset(BYTE ucInputPort)
{
    ScalerAudioLPCMResetProc(ucInputPort);

    ScalerAudioWatchDogProc(_OFF, ucInputPort);

    ScalerAudioHbrModeControl(_OFF, ucInputPort);
}

//--------------------------------------------------
// Description  : Get Audio Detected
// Input Value  : None
// Output Value : TRUE => Audio Detected
//--------------------------------------------------
bit ScalerAudioGetAudioDetected(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
            return ScalerAudioD0GetAudioDetected();
#endif

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
            return ScalerAudioD1GetAudioDetected();
#endif

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            return ScalerAudioD2GetAudioDetected();
#endif

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            return ScalerAudioD3GetAudioDetected();
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Detect Audio Sampling Freq
// Input Value  : ucInputPort
// Output Value : Audio Sampling Freq
//--------------------------------------------------
EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort)
{
    EnumAudioSamplingFreqType enumSamplingFreqType = _AUDIO_FREQ_NO_AUDIO;

    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
            enumSamplingFreqType = ScalerAudioD0SamplingFreqDetect();
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
            enumSamplingFreqType = ScalerAudioD1SamplingFreqDetect();
#endif
            break;

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            enumSamplingFreqType = ScalerAudioD2SamplingFreqDetect();
#endif
            break;

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            enumSamplingFreqType = ScalerAudioD3SamplingFreqDetect();
#endif
            break;

        default:
            break;
    }

    return ScalerAudioGetSamplingFreqPacket(enumSamplingFreqType);
}

//--------------------------------------------------
// Description  : Check Audio Sampling Frequency Change or Not
// Input Value  : None
// Output Value : _TRUE => Change / _FALSE => Un-Change
//--------------------------------------------------
bit ScalerAudioSamplingFreqChange(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

#if(_D0_DP_EXIST == _ON)

            return ScalerAudioD0SamplingFreqChange();

#endif
            break;

        case _AUDIO_FROM_D1_PORT:

#if(_D1_DP_EXIST == _ON)

            return ScalerAudioD1SamplingFreqChange();

#endif
            break;

        case _AUDIO_FROM_D2_PORT:

            break;

        case _AUDIO_FROM_D3_PORT:

            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Audio whether Audio LPCM By Audio Data
// Input Value  : ucSourceType
// Output Value : _TRUE => LPCM
//--------------------------------------------------
bit ScalerAudioLPCMCheckData(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

#if(_D0_DP_EXIST == _ON)
            // Check Audio Packet
            if(ScalerAudioD0GetAudioDetected() == _FALSE)
            {
                // Reset Coding Type Detect
                SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_CODING_TYPE_NONE);

                return _FALSE;
            }

            // Check First Time Check or Coding Type Change before Playback
            if((GET_DP_D0_AUDIO_CODING_TYPE_FORMAT() == _AUDIO_CODING_TYPE_NONE) ||
               ((ScalerGetBit(PB6_3B_DP_IRQ_CTRL1, _BIT0) == 0x00) && (ScalerGetBit(PB6_36_DP_GLB_STATUS, _BIT2) == _BIT2)))
            {
                // =================================
                // Flag Reset
                // =================================

                // Disable Audio Coding Type Change INT
                ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT0, 0x00);

                // Clear Audio Coding Type Change Flag
                ScalerSetBit(PB6_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);


                // =================================
                // Detect Coding Type at First Time
                // =================================

                DebugMessageAudio("[Audio] Rx0 Coding Type First Time Detect", 0);


                // ---------------------------------
                // Valid_Bit Detect at First
                // ---------------------------------

                // Set Audio Coding Type Source to Valid_Bit
                ScalerSetBit(PB6_B0_DP_AUD_CTRL, ~_BIT5, _BIT5);

                // Update Detect Result
                if(ScalerGetBit(PB6_B0_DP_AUD_CTRL, _BIT4) == 0x00)
                {
                    DebugMessageAudio("[Audio] Rx0 initial at LPCM via Valid_Bit", 0);

                    SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_LPCM);
                }
                else
                {
                    WORD usDelayTime = 12;
                    EnumAudioSamplingFreqType enumAudioFreq = ScalerAudioD0SamplingFreqDetect();
                    EnumAudioSamplingFreqPacket enumAudioPacket = ScalerAudioGetSamplingFreqPacket(enumAudioFreq);

                    // -----------------------------
                    // Channel Status Detect Flow
                    // -----------------------------

                    // Set Audio Coding Type Source to Channel_Status
                    ScalerSetBit(PB6_B0_DP_AUD_CTRL, ~_BIT5, 0x00);

                    // Calculate Minimum Delay for Receiving 192*2 Audio Samples
                    // Avoid 0Hz Value
                    if(enumAudioPacket == _AUDIO_FREQ_PACKET_NO_AUDIO)
                    {
                        enumAudioPacket = _AUDIO_FREQ_PACKET_32K;
                    }

                    // (192Samples * 2) / AudioFreq
                    usDelayTime = (192 * 2) / enumAudioPacket;

                    // Delay with 2ms margin added
                    ScalerTimerDelayXms(usDelayTime + 2);

                    // Update Detect Result
                    if(ScalerGetBit(PB6_B0_DP_AUD_CTRL, _BIT4) == _BIT4)
                    {
                        DebugMessageAudio("[Audio] Rx0 initial at Non-LPCM via Channel_Status", 1);

                        SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_NON_LPCM);
                    }
                    else
                    {
                        DebugMessageAudio("[Audio] Rx0 initial at LPCM via Channel_Status", 0);

                        SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_LPCM);
                    }
                }
            }

            // =================================
            // Return Coding Type Status
            // =================================
            if(GET_DP_D0_AUDIO_CODING_TYPE_FORMAT() == _AUDIO_NON_LPCM)
            {
                return _FALSE;
            }

            return _TRUE;
#endif
            break;

        case _AUDIO_FROM_D1_PORT:

#if(_D1_DP_EXIST == _ON)
            // Check Audio Packet
            if(ScalerAudioD1GetAudioDetected() == _FALSE)
            {
                // Reset Coding Type Detect
                SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(_AUDIO_CODING_TYPE_NONE);

                return _FALSE;
            }

            // Check First Time Check or Coding Type Change before Playback
            if((GET_DP_D1_AUDIO_CODING_TYPE_FORMAT() == _AUDIO_CODING_TYPE_NONE) ||
               ((ScalerGetBit(PB9_3B_DP_IRQ_CTRL1, _BIT0) == 0x00) && (ScalerGetBit(PB9_36_DP_GLB_STATUS, _BIT2) == _BIT2)))
            {
                // =================================
                // Flag Reset
                // =================================

                // Disable Audio Coding Type Change INT
                ScalerSetBit(PB9_3B_DP_IRQ_CTRL1, ~_BIT0, 0x00);

                // Clear Audio Coding Type Change Flag
                ScalerSetBit(PB9_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);


                // =================================
                // Detect Coding Type at First Time
                // =================================

                DebugMessageAudio("[Audio] Rx1 Coding Type First Time Detect", 0);


                // ---------------------------------
                // Valid_Bit Detect at First
                // ---------------------------------

                // Set Audio Coding Type Source to Valid_Bit
                ScalerSetBit(PB9_B0_DP_AUD_CTRL, ~_BIT5, _BIT5);

                // Update Detect Result
                if(ScalerGetBit(PB9_B0_DP_AUD_CTRL, _BIT4) == 0x00)
                {
                    DebugMessageAudio("[Audio] Rx1 initial at LPCM via Valid_Bit", 0);

                    SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(_AUDIO_LPCM);
                }
                else
                {
                    WORD usDelayTime = 12;
                    EnumAudioSamplingFreqType enumAudioFreq = ScalerAudioD1SamplingFreqDetect();
                    EnumAudioSamplingFreqPacket enumAudioPacket = ScalerAudioGetSamplingFreqPacket(enumAudioFreq);

                    // -----------------------------
                    // Channel Status Detect Flow
                    // -----------------------------

                    // Set Audio Coding Type Source to Channel_Status
                    ScalerSetBit(PB9_B0_DP_AUD_CTRL, ~_BIT5, 0x00);

                    // Calculate Minimum Delay for Receiving 192*2 Audio Samples
                    // Avoid 0Hz Value
                    if(enumAudioPacket == _AUDIO_FREQ_PACKET_NO_AUDIO)
                    {
                        enumAudioPacket = _AUDIO_FREQ_PACKET_32K;
                    }

                    // (192Samples * 2) / AudioFreq
                    usDelayTime = (192 * 2) / enumAudioPacket;

                    // Delay with 2ms margin added
                    ScalerTimerDelayXms(usDelayTime + 2);

                    // Update Detect Result
                    if(ScalerGetBit(PB9_B0_DP_AUD_CTRL, _BIT4) == _BIT4)
                    {
                        DebugMessageAudio("[Audio] Rx1 initial at Non-LPCM via Channel_Status", 1);

                        SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(_AUDIO_NON_LPCM);
                    }
                    else
                    {
                        DebugMessageAudio("[Audio] Rx1 initial at LPCM via Channel_Status", 0);

                        SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(_AUDIO_LPCM);
                    }
                }
            }

            // =================================
            // Return Coding Type Status
            // =================================
            if(GET_DP_D1_AUDIO_CODING_TYPE_FORMAT() == _AUDIO_NON_LPCM)
            {
                return _FALSE;
            }

            return _TRUE;
#endif
            break;

        case _AUDIO_FROM_D2_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            if(ScalerGetBit(P71_CB_HDMI_SR, _BIT4) == 0x00)
            {
                return _TRUE;
            }
            else
            {
                return _FALSE;
            }
#endif
            break;

        case _AUDIO_FROM_D3_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            if(ScalerGetBit(P72_CB_HDMI_SR, _BIT4) == 0x00)
            {
                return _TRUE;
            }
            else
            {
                return _FALSE;
            }
#endif
            break;

        default:
            break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check Audio Coding Change or Not
// Input Value  : None
// Output Value : _TRUE => LPCM / _FALSE => Un-Change
//--------------------------------------------------
bit ScalerAudioLPCMCheckChange(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

#if(_D0_DP_EXIST == _ON)

            if(GET_DP_D0_AUDIO_CODING_TYPE_CHANGE() == _TRUE)
            {
                // Clear Change Flag
                CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE();

                return _TRUE;
            }

#endif
            break;

        case _AUDIO_FROM_D1_PORT:

#if(_D1_DP_EXIST == _ON)

            if(GET_DP_D1_AUDIO_CODING_TYPE_CHANGE() == _TRUE)
            {
                // Clear Change Flag
                CLR_DP_D1_AUDIO_CODING_TYPE_CHANGE();

                return _TRUE;
            }

#endif
            break;

        case _AUDIO_FROM_D2_PORT:

            break;

        case _AUDIO_FROM_D3_PORT:

            break;

        case _AUDIO_FROM_D4_PORT:

            break;

        case _AUDIO_FROM_D5_PORT:

            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Enable Audio Coding Type Detect INT
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioLPCMDetectEnableProc(BYTE ucInputPort)
{
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)

                // Clear Change Flag
                CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE();

                // Clear Audio Coding Type Change Flag
                ScalerSetBit(PB6_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

                // Enable Audio Coding Type Change INT
                ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT0, _BIT0);

#endif
                break;

            case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)

                // Clear Change Flag
                CLR_DP_D1_AUDIO_CODING_TYPE_CHANGE();

                // Clear Audio Coding Type Change Flag
                ScalerSetBit(PB9_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

                // Enable Audio Coding Type Change INT
                ScalerSetBit(PB9_3B_DP_IRQ_CTRL1, ~_BIT0, _BIT0);

#endif
                break;

            case _D2_INPUT_PORT:

                break;

            case _D3_INPUT_PORT:

                break;

            case _D4_INPUT_PORT:

                break;

            case _D5_INPUT_PORT:

                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Reset Audio Coding Type Detect INT
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioLPCMResetProc(BYTE ucInputPort)
{
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)

                // Disable Audio Coding Type Change INT
                ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT0, 0x00);

                // Reset Coding Type Detect
                SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_CODING_TYPE_NONE);

#endif
                break;

            case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)

                // Disable Audio Coding Type Change INT
                ScalerSetBit(PB9_3B_DP_IRQ_CTRL1, ~_BIT0, 0x00);

                // Reset Coding Type Detect
                SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(_AUDIO_CODING_TYPE_NONE);

#endif
                break;

            case _D2_INPUT_PORT:

                break;

            case _D3_INPUT_PORT:

                break;

            case _D4_INPUT_PORT:

                break;

            case _D5_INPUT_PORT:

                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Switch Digital Audio Output Mute
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalOutputMute(bit bMute)
{
    bMute = bMute;

    switch(ScalerAudioGetDigitalAudioPortMapping())
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
            if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
            {
                // HDMI MAC DVC Mute On/Off
                ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (((!bMute) == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
                ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_08_PORT_PAGE71_HDMI_MAG_L_FINAL, 0x00);
                ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_09_PORT_PAGE71_HDMI_MAG_R_FINAL, 0x00);
            }
            else
#endif
            {
                ScalerAudioDPDigitalOutputProc(~bMute, _D0_INPUT_PORT);
            }
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
            if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
            {
                // HDMI MAC DVC Mute On/Off
                ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (((!bMute) == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
                ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_08_PORT_PAGE71_HDMI_MAG_L_FINAL, 0x00);
                ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_09_PORT_PAGE71_HDMI_MAG_R_FINAL, 0x00);
            }
            else
#endif
            {
                ScalerAudioDPDigitalOutputProc(~bMute, _D1_INPUT_PORT);
            }
#endif
            break;

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (((!bMute) == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
            ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_08_PORT_PAGE71_HDMI_MAG_L_FINAL, 0x00);
            ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_09_PORT_PAGE71_HDMI_MAG_R_FINAL, 0x00);
#endif
            break;

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_07_PORT_PAGE72_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (((!bMute) == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
            ScalerSetDataPortByte(P72_C9_HDMI_AP, _P72_CA_PT_08_PORT_PAGE72_HDMI_MAG_L_FINAL, 0x00);
            ScalerSetDataPortByte(P72_C9_HDMI_AP, _P72_CA_PT_09_PORT_PAGE72_HDMI_MAG_R_FINAL, 0x00);
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Audio Watch Dog Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort)
{
    bOn = bOn;

#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
                ScalerAudioD0WatchDogProc(bOn);
                DebugMessageAudio("Audio D0: WatchDog", bOn);
#endif
                break;

            case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
                ScalerAudioD1WatchDogProc(bOn);
                DebugMessageAudio("Audio D1: WatchDog", bOn);
#endif
                break;

            case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
                ScalerAudioD2WatchDogProc(bOn);
                DebugMessageAudio("Audio D2: WatchDog", bOn);
#endif
                break;

            case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
                ScalerAudioD3WatchDogProc(bOn);
                DebugMessageAudio("Audio D3: WatchDog", bOn);
#endif
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Audio HBR Mode Control
// Input Value  : bOn
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioHbrModeControl(bit bOn, BYTE ucInputPort)
{
    bOn = bOn;

#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
                ScalerAudioD0HbrModeControl(bOn);
                DebugMessageAudio("Audio D0: HBR Mode Control", bOn);
#endif
                break;

            case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
                ScalerAudioD1HbrModeControl(bOn);
                DebugMessageAudio("Audio D1: HBR Mode Control", bOn);
#endif
                break;

            case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
                DebugMessageAudio("Audio D2: HBR Mode Control", bOn);
#endif
                break;

            case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
                DebugMessageAudio("Audio D3: HBR Mode Control", bOn);
#endif
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Timer Event to Load Stable I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioLoadStableICodeEvent(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D0_DP_EXIST == _ON)
        case _SCALER_TIMER_EVENT_AUDIO_D0_LOAD_STABLE_I_CODE:

            ScalerAudioD0LoadStableICodeEvent();
            break;
#endif

#if(_D1_DP_EXIST == _ON)
        case _SCALER_TIMER_EVENT_AUDIO_D1_LOAD_STABLE_I_CODE:

            ScalerAudioD1LoadStableICodeEvent();
            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_AUDIO_D2_LOAD_STABLE_I_CODE:

            ScalerAudioD2LoadStableICodeEvent();
            break;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_AUDIO_D3_LOAD_STABLE_I_CODE:

            ScalerAudioD3LoadStableICodeEvent();
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Switch audio Input (AIN / DAC)
// Input Value  : bAudioSource
// Output Value : None
//--------------------------------------------------
void ScalerAudioSourceInputSwitch(EnumAudioInputSource enumAudioSource, BYTE ucInputPort)
{
    if(enumAudioSource == _DIGITAL_AUDIO)
    {
        // Select DAC Mux to Digital input
        ScalerSetBit(P6_D1_DA_MUTE, ~_BIT3, 0x00);

#if(_LINE_IN_SUPPORT == _ON)
        // Power down Audio ADC PLL
        ScalerSetBit(PBF_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

#if(_LINE_IN_AA_PATH_SUPPORT == _ON)
        // Set DAC Path
        ScalerSetByte(P6_E0_REG_MUX_ANA_OUT, 0x00);
#endif
#endif
        if(ucInputPort == _D0_INPUT_PORT)
        {
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
            if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
            {
                ScalerAudioInputPortSwitch(_AUDIO_FROM_D2_PORT);
            }
            else
#endif
            {
                ScalerAudioInputPortSwitch(_AUDIO_FROM_D0_PORT);
            }
        }
        else if(ucInputPort == _D1_INPUT_PORT)
        {
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
            if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
            {
                ScalerAudioInputPortSwitch(_AUDIO_FROM_D2_PORT);
            }
            else
#endif
            {
                ScalerAudioInputPortSwitch(_AUDIO_FROM_D1_PORT);
            }
        }
        else if(ucInputPort == _D2_INPUT_PORT)
        {
            ScalerAudioInputPortSwitch(_AUDIO_FROM_D2_PORT);
        }
        else if(ucInputPort == _D3_INPUT_PORT)
        {
            ScalerAudioInputPortSwitch(_AUDIO_FROM_D3_PORT);
        }
        else if(ucInputPort == _D4_INPUT_PORT)
        {
            ScalerAudioInputPortSwitch(_AUDIO_FROM_D4_PORT);
        }
        else if(ucInputPort == _D5_INPUT_PORT)
        {
            ScalerAudioInputPortSwitch(_AUDIO_FROM_D5_PORT);
        }

        // Resolve Audio Phase Delay of L/R Channel
        ScalerAudioDVCResetProc();

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        // Set AOUT and HPOUT Gain After DAC Block
        ScalerAudioDACSetOutputGain(_AUDIO_DAC_OUTPUT_SPEAKER, _DIGITAL_DAC_AOUT_GAIN_DB);
        ScalerAudioDACSetOutputGain(_AUDIO_DAC_OUTPUT_HEADPHONE, _DIGITAL_DAC_HPOUT_GAIN_DB);
#endif

#if(_AUDIO_DVC_ADJUST_HARD_GAIN_SUPPORT == _ON)
        // Set Hard Gain for Digital Audio
        ScalerSetBit(P8_A9_DVC_GAIN_DONE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _DIGITAL_HARD_GAIN_VALUE);
#endif
    }
#if(_LINE_IN_SUPPORT == _ON)
    else if(enumAudioSource == _LINE_IN_AUDIO)
    {
        // Enable Audio ADC PLL
        ScalerAudioSetADCAudioPLL();

        // Select DAC Mux to ADC input
        ScalerSetBit(P6_D1_DA_MUTE, ~_BIT3, _BIT3);

        // Switch port to Audio ADC
        ScalerAudioInputPortSwitch(_AUDIO_FROM_ADC_PORT);

        // Resolve Audio Phase Delay of L/R Channel
        ScalerAudioDVCResetProc();

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        // Set AOUT and HPOUT Gain After DAC Block
        ScalerAudioDACSetOutputGain(_AUDIO_DAC_OUTPUT_SPEAKER, _LINE_IN_DAC_AOUT_GAIN_DB);
        ScalerAudioDACSetOutputGain(_AUDIO_DAC_OUTPUT_HEADPHONE, _LINE_IN_DAC_HPOUT_GAIN_DB);
#endif

#if(_LINE_IN_AA_PATH_SUPPORT == _ON)
        // Set A-A Path
        ScalerSetByte(P6_E0_REG_MUX_ANA_OUT, 0xAA);
#endif

#if(_AUDIO_DVC_ADJUST_HARD_GAIN_SUPPORT == _ON)
        // Set Hard Gain for Line in Audio
        ScalerSetBit(P8_A9_DVC_GAIN_DONE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _LINE_IN_HARD_GAIN_VALUE);
#endif
    }
#endif
}

//--------------------------------------------------
// Description  : Get Current Audio Port
// Input Value  : None
// Output Value : Input Port
//--------------------------------------------------
EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

            return _D0_INPUT_PORT;

        case _AUDIO_FROM_D1_PORT:

            return _D1_INPUT_PORT;

        case _AUDIO_FROM_D2_PORT:

            return _D2_INPUT_PORT;

        case _AUDIO_FROM_D3_PORT:

            return _D3_INPUT_PORT;

        case _AUDIO_FROM_D4_PORT:

            return _D4_INPUT_PORT;

        case _AUDIO_FROM_D5_PORT:

            return _D5_INPUT_PORT;

        default:
            break;
    }

    return _NO_INPUT_PORT;
}

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : FW tracking Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioFwTrackingHandler(void)
{
#if(_D2_HDMI_SUPPORT == _ON)
    if((GET_AUDIO_D2_FW_TRACKING_RESET() == _FALSE) && (GET_AUDIO_D2_SAMPLING_FREQ() <= _AUDIO_FREQ_48K))
    {
        // FW Tracking mode active only when fs <= 48kHz
        ScalerAudioD2FwTrackingHandler();
    }
    else // FW Tracking mode reset
    {
        // Audio Tracking Reset
        ScalerAudioD2FwTrackingReset();

        DebugMessageAudio("D2 Audio : FW Tracking End", GET_AUDIO_D2_SAMPLING_FREQ());
    }
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    if((GET_AUDIO_D3_FW_TRACKING_RESET() == _FALSE) && (GET_AUDIO_D3_SAMPLING_FREQ() <= _AUDIO_FREQ_48K))
    {
        // FW Tracking mode active only when fs <= 48kHz
        ScalerAudioD3FwTrackingHandler();
    }
    else // FW Tracking mode reset
    {
        // Audio Tracking Reset
        ScalerAudioD3FwTrackingReset();

        DebugMessageAudio("D3 Audio : FW Tracking End", GET_AUDIO_D3_SAMPLING_FREQ());
    }
#endif
}

//--------------------------------------------------
// Description  : Timer Event to FW Tracking event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioFwTrackingEventSet(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D2_HDMI_SUPPORT == _ON)

        case _SCALER_TIMER_EVENT_AUDIO_D2_FW_TRACKING_PREPARING:

            ScalerAudioD2FwTrackingEventSet();
            break;
#endif
#if(_D3_HDMI_SUPPORT == _ON)

        case _SCALER_TIMER_EVENT_AUDIO_D3_FW_TRACKING_PREPARING:

            ScalerAudioD3FwTrackingEventSet();
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Timer Event to 4s timeout event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTimeoutEventSet(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D2_HDMI_SUPPORT == _ON)

        case _SCALER_TIMER_EVENT_AUDIO_D2_FW_TRACKING_TIMEOUT:

            ScalerAudioD2TimeoutEventSet();
            break;
#endif
#if(_D3_HDMI_SUPPORT == _ON)

        case _SCALER_TIMER_EVENT_AUDIO_D3_FW_TRACKING_TIMEOUT:

            ScalerAudioD3TimeoutEventSet();
            break;
#endif

        default:
            break;
    }
}
#endif

#if((_D2_HDMI_SUPPORT == _ON) || ((_INTERNAL_AUDIO_TEST_SUPPORT == _ON) && ((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON))))
//--------------------------------------------------
// Description  : Initial 2 HDMI audio setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD2HDMIAudioInitial(void)
{
    ScalerAudioD2SetAudioPLL();

    // Disable sine wave generator
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, ~_BIT4, 0x00);

    // Disable AVMUTE function and enable Audio FIFO Tracking main control (I/P code)
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_31_PORT_PAGE71_HDMI_WDCR0, ~(_BIT7 | _BIT5), _BIT5);

    // Disable FIFO Boundary Tracking, Disable Trend Tracking
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_15_PORT_PAGE71_HDMI_PSCR, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5));

    // Enable SDM
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_2D_PORT_PAGE71_HDMI_AAPNR, ~_BIT1, _BIT1);

    // Set auto gain delay mode and final gain = full gain
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~_BIT3, 0x00);

    // Set wait time for load parameter
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_0A_PORT_PAGE71_AUDIO_LD_P_TIME_M, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_0B_PORT_PAGE71_AUDIO_LD_P_TIME_N, 0x10);

    // Set ZCD timeout
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_0D_PORT_PAGE71_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);

    // Set Boundary Address = 5 for Boundary Tracking
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_1B_PORT_PAGE71_HDMI_FBR, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // Set I code of trend
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_20_PORT_PAGE71_HDMI_ICTPSR0, 0x00);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_21_PORT_PAGE71_HDMI_ICTPSR1, 0x02);

    // Set P code of trend
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_22_PORT_PAGE71_HDMI_PCTPSR0, 0x7F);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_23_PORT_PAGE71_HDMI_PCTPSR1, 0xFF);

    // Set I code of boundary
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_24_PORT_PAGE71_HDMI_ICBPSR0, HIBYTE(_INITIAL_I_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_25_PORT_PAGE71_HDMI_ICBPSR1, LOBYTE(_INITIAL_I_CODE));

    // Set P code of boundary
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_26_PORT_PAGE71_HDMI_PCBPSR0, 0x7F);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_27_PORT_PAGE71_HDMI_PCBPSR1, 0xFF);

    // Audio Normal Output
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_30_PORT_PAGE71_HDMI_AVMCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Disable Audio Watchdog for FIFO Overflow/Underflow
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_31_PORT_PAGE71_HDMI_WDCR0, ~(_BIT2 | _BIT1), 0x00);

    // Set X Value
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_32_PORT_PAGE71_HDMI_WDCR1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Set Y Value
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_33_PORT_PAGE71_HDMI_WDCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Bit2: When no audio or changing sampling rate, AFSM load double buffer one more.
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_9F_PORT_PAGE71_PRESET_AFSM_MOD, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2));

    // Seperate the detected sampling frequency
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8B_PORT_PAGE71_AUDIO_FREQ_RESULT, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

    // Set 2ms for auto frequency detecttion
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8C_PORT_PAGE71_AUDIO_FREQ_RESULT_M, ~(_BIT6 | _BIT5), _BIT5);

    // Change audio clk divider according to SYSCLK = 27MHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_8E_PORT_PAGE71_XTAL_DIV, _AUTO_FREQ_DETECT_XTAL_DIV);

    // Set threshold to sepeerate sampling frequency
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_90_PORT_PAGE71_TH1, 0x00);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_91_PORT_PAGE71_TH2, 0x28);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_92_PORT_PAGE71_TH3, 0x4C);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_93_PORT_PAGE71_TH4, 0x5C);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_94_PORT_PAGE71_TH5, 0x70);

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _ON)

    // Disable Auto Load S Code
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8A_PORT_PAGE71_AUDIO_FREQDET, ~_BIT6, 0x00);

#if(_FIX_SAMPLING_FREQ_TYPE == _FIX_FREQ_32KHZ)

    // Set S code for 32kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_12_PORT_PAGE71_HDMI_SCAPR, _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE);

    // Set D code for 32kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_13_PORT_PAGE71_HDMI_DCAPR0, HIBYTE(_HDMI_SAMPLING_FREQ_32K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_14_PORT_PAGE71_HDMI_DCAPR1, LOBYTE(_HDMI_SAMPLING_FREQ_32K_GROUP_D_CODE));

#elif(_FIX_SAMPLING_FREQ_TYPE == _FIX_FREQ_44_1KHZ)

    // Set S code for 44.1kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_12_PORT_PAGE71_HDMI_SCAPR, _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE);

    // Set D code for 44.1kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_13_PORT_PAGE71_HDMI_DCAPR0, HIBYTE(_HDMI_SAMPLING_FREQ_44K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_14_PORT_PAGE71_HDMI_DCAPR1, LOBYTE(_HDMI_SAMPLING_FREQ_44K_GROUP_D_CODE));

#else // _FIX_SAMPLING_FREQ_TYPE == _FIX_FREQ_48KHZ

    // Set S code for 48kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_12_PORT_PAGE71_HDMI_SCAPR, _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE);

    // Set D code for 48kHz
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_13_PORT_PAGE71_HDMI_DCAPR0, HIBYTE(_HDMI_SAMPLING_FREQ_48K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_14_PORT_PAGE71_HDMI_DCAPR1, LOBYTE(_HDMI_SAMPLING_FREQ_48K_GROUP_D_CODE));

#endif

    // Set Double Buffer bit
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_10_PORT_PAGE71_HDMI_CMCR, ~_BIT4, _BIT4);

    // Load D code
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_31_PORT_PAGE71_HDMI_WDCR0, ~_BIT6, _BIT6);
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_31_PORT_PAGE71_HDMI_WDCR0, ~_BIT6, 0x00);

#else
    // Set S code for auto load mode
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_95_PORT_PAGE71_PRESET_S_CODE0, _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_96_PORT_PAGE71_PRESET_S_CODE1, _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE);
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_97_PORT_PAGE71_PRESET_S_CODE2, _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE);

    // Set D code for auto load mode
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_99_PORT_PAGE71_PRESET_D_CODE_0, HIBYTE(_HDMI_SAMPLING_FREQ_32K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_9A_PORT_PAGE71_PRESET_D_CODE_1, LOBYTE(_HDMI_SAMPLING_FREQ_32K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_9B_PORT_PAGE71_PRESET_D_CODE_2, HIBYTE(_HDMI_SAMPLING_FREQ_44K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_9C_PORT_PAGE71_PRESET_D_CODE_3, LOBYTE(_HDMI_SAMPLING_FREQ_44K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_9D_PORT_PAGE71_PRESET_D_CODE_4, HIBYTE(_HDMI_SAMPLING_FREQ_48K_GROUP_D_CODE));
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_9E_PORT_PAGE71_PRESET_D_CODE_5, LOBYTE(_HDMI_SAMPLING_FREQ_48K_GROUP_D_CODE));

    // Enable Auto Load S Code
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8A_PORT_PAGE71_AUDIO_FREQDET, ~_BIT6, _BIT6);

    // Set Double Buffer bit
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_10_PORT_PAGE71_HDMI_CMCR, ~_BIT4, _BIT4);

    // Set User Define Frequency When No Audio
    ScalerAudioD2AudioFrequencyMode(_AUDIO_TRACKING_MANNUAL_MODE);
#endif // End of #if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _ON)

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)

    // Audio Tracking Reset
    ScalerAudioD2FwTrackingReset();
#endif

    // Enable Audio Freq Detect, Disable Samping Freq. Change INT
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8A_PORT_PAGE71_AUDIO_FREQDET, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), _BIT7);

    // Enable SPDIF/I2S Output
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_62_PORT_PAGE71_HDMI_AOCR, 0xFF);

    // CLR PLL Autoload Status Flag
    CLR_AUDIO_D2_AUTO_LOAD_FREQ();

    CLR_AUDIO_D2_ICODE_RELOADED();
}

//--------------------------------------------------
// Description  : Initial 2 Auido PLL Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD2SetAudioPLL(void)
{
    // DPLL power down
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT7, _BIT7);

    // Set M code
    ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_11_PORT_PAGE71_HDMI_MCAPR, (_AUDIO_PLL_M - 2));

    // Set O code
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~(_BIT5 | _BIT4), 0x00);

    // Set K code and enable double buffer
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_10_PORT_PAGE71_HDMI_CMCR, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | ((_AUDIO_PLL_K - 2) & 0x0F)));

    // Initial VCO Band = 10
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3A_PORT_PAGE71_HDMI_DPCR2, ~(_BIT4 | _BIT3), _BIT4);

    // Set MN PLL Path1 => [2]: 1 = Path1, 0 = Path2
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3A_PORT_PAGE71_HDMI_DPCR2, ~(_BIT7 | _BIT2), _BIT2);

#if(_HW_PLL_EDGE_SELECT_TYPE == _PLL_EDGE_GEN_1_DEFAULT_POSITIVE)
    // Set PLL Edge = Negative
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3F_PORT_PAGE71_DPLL_LDO, ~_BIT1, _BIT1);
#endif

    // DPLL VCORSTB Set to Normal
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3B_PORT_PAGE71_HDMI_DPCR3, ~_BIT0, _DPLL_VCORSTB_NORMAL_VALUE);

    // DPLL power up
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT7, 0x00);

    // Delay 2000us
    ScalerTimerDelayXms(2);

    // DPLL CMP enable
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT0, _BIT0);

    // Delay 1000us
    ScalerTimerDelayXms(2);

    // DPLL latch calibration enable
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT1, _BIT1);

    // Delay 1000us
    ScalerTimerDelayXms(2);

    // DPLL calibration validated
    ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT2, _BIT2);
}
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_D2_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect D2 Audio Sampling Freq
// Input Value  : None
// Output Value : Audio Sampling Freq
//--------------------------------------------------
EnumAudioSamplingFreqType ScalerAudioD2SamplingFreqDetect(void)
{
    EnumAudioSamplingFreqType enumAudioFreq = _AUDIO_FREQ_NO_AUDIO;

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioD2GetInternalAudioGenEnable() == _ENABLE)
    {
        // For Audio test pattern
        SET_AUDIO_D2_SAMPLING_FREQ(_AUDIO_FREQ_48K);
        return _AUDIO_FREQ_48K;
    }
#endif

    enumAudioFreq = ScalerGetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8B_PORT_PAGE71_AUDIO_FREQ_RESULT, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(enumAudioFreq != GET_AUDIO_D2_SAMPLING_FREQ())
    {
        if(enumAudioFreq <= _AUDIO_FREQ_64K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), 0x00);
        }
        else if(enumAudioFreq <= _AUDIO_FREQ_128K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT6);
        }
        else
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT7);
        }
    }
#endif

    SET_AUDIO_D2_SAMPLING_FREQ(enumAudioFreq);

    return enumAudioFreq;
}
#endif

//--------------------------------------------------
// Description  : Audio SPDIF/IIS Output Select
// Input Value  : bOn
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort)
{
    enumAudioIisSpdifOutput = enumAudioIisSpdifOutput;

    switch(ucInputPort)
    {
        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            ScalerAudioD2I2sSpdifChannelOutputSelect(enumAudioIisSpdifOutput);
#endif
            break;

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            ScalerAudioD3I2sSpdifChannelOutputSelect(enumAudioIisSpdifOutput);
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check Audio whether Audio LPCM By Info Frame
// Input Value  : ucSourceType
// Output Value : _TRUE => LPCM
//--------------------------------------------------
bit ScalerAudioLPCMCheckInfo(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

            break;

        case _AUDIO_FROM_D1_PORT:

            break;

        case _AUDIO_FROM_D2_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            ScalerGetDataPortByte(P71_CD_HDMI_PSAP, 0x15, 1, pData, _NON_AUTOINC);

            if(((pData[0] & 0xF0) == 0x00) || ((pData[0] & 0xF0) == 0x10))
            {
                return _TRUE;
            }
#endif
            break;

        case _AUDIO_FROM_D3_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x15, 1, pData, _NON_AUTOINC);

            if(((pData[0] & 0xF0) == 0x00) || ((pData[0] & 0xF0) == 0x10))
            {
                return _TRUE;
            }
#endif
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Current Digital Audio Source type
// Input Value  : None
// Output Value : Digital Audio Source
//--------------------------------------------------
EnumSourceTypeDef ScalerAudioDigitalAudioSourceType(void)
{
    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT))
    {
#if(_D0_DP_EXIST == _ON)
        case _AUDIO_FROM_D0_PORT:

            return _SOURCE_DP;
#endif

#if(_D1_DP_EXIST == _ON)
        case _AUDIO_FROM_D1_PORT:

            return _SOURCE_DP;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _AUDIO_FROM_D2_PORT:

            return _SOURCE_HDMI;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _AUDIO_FROM_D3_PORT:

            return _SOURCE_HDMI;
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _AUDIO_FROM_D4_PORT:

            return _SOURCE_HDMI;
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _AUDIO_FROM_D5_PORT:

            return _SOURCE_HDMI;
#endif

        default:
            break;
    }

    return _SOURCE_NONE;
}
#endif

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Audio Digital Output Process
// Input Value  : Enable and Input port
// Output Value : None
//--------------------------------------------------
void ScalerAudioDPDigitalOutputProc(bit bEnable, BYTE ucInputPort)
{
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
                ScalerAudioD0DPDigitalOutputProc(bEnable);
#endif
                break;

            case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
                ScalerAudioD1DPDigitalOutputProc(bEnable);
#endif
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Get Dp Audio Capability Change
// Input Value  : Input Port
// Output Value : _TRUE => Change / _FALSE => Un-Change
//--------------------------------------------------
bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort)
{
    bit bResult = _FALSE;

    switch(ucInputPort)
    {
#if(_D0_DP_EXIST == _ON)
        case _D0_INPUT_PORT:

            bResult = GET_AUDIO_DP_D0_CAPABILITY_SWITCH();

            CLR_AUDIO_DP_D0_CAPABILITY_SWITCH();

            break;
#endif

#if(_D1_DP_EXIST == _ON)
        case _D1_INPUT_PORT:

            bResult = GET_AUDIO_DP_D1_CAPABILITY_SWITCH();

            CLR_AUDIO_DP_D1_CAPABILITY_SWITCH();

            break;
#endif

        default:

            break;
    }

    return bResult;
}

#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Dp Audio Capability State
// Input Value  : Input Port
// Input Value  : EnumAudioDpDpcdSupport
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport)
{
    switch(ucInputPort)
    {
#if(_D0_DP_EXIST == _ON)
        case _D0_INPUT_PORT:

            // Check Previous DP Capability
            if(GET_AUDIO_DP_D0_SUPPORT() != enumDpcdSupport)
            {
                // Set User Define DP Capability
                SET_AUDIO_DP_D0_SUPPORT(enumDpcdSupport);
                SET_AUDIO_DP_D0_CAPABILITY_SWITCH();

                // Change DPCD
                SET_DP_RX_CAPABILITY_SWITCHED();
            }

            break;
#endif

#if(_D1_DP_EXIST == _ON)
        case _D1_INPUT_PORT:

            // Check Previous DP Capability
            if(GET_AUDIO_DP_D1_SUPPORT() != enumDpcdSupport)
            {
                // Set User Define DP Capability
                SET_AUDIO_DP_D1_SUPPORT(enumDpcdSupport);
                SET_AUDIO_DP_D1_CAPABILITY_SWITCH();

                // Change DPCD
                SET_DP_RX_CAPABILITY_SWITCHED();
            }

            break;
#endif

        default:

            break;
    }
}
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Set Dp Audio Capability State
// Input Value  : Input Port
// Output Value : EnumAudioDpDpcdSupport
//--------------------------------------------------
EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_EXIST == _ON)
        case _D0_INPUT_PORT:

            // Get User Define DP Capability
            return GET_AUDIO_DP_D0_SUPPORT();

            break;
#endif

#if(_D1_DP_EXIST == _ON)
        case _D1_INPUT_PORT:

            // Get User Define DP Capability
            return GET_AUDIO_DP_D1_SUPPORT();

            break;
#endif

        default:

            break;
    }

    return _AUDIO_DP_DPCD_NOT_SUPPORT;
}

#if(_D0_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Initial D0 Auido PLL Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0SetAudioPLL(void)
{
    // DPLL power down
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set M code
    ScalerSetByte(PB6_D1_MN_SCLKG_DIVM, (_AUDIO_PLL_M - 2));

    // Set O code
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), 0x00);

    // Set N(K) code and enable double buffer
    ScalerSetByte(PB6_D2_MN_SCLKG_DIVN, (_AUDIO_PLL_K - 2));

    // Initial VCO Band = 10
    ScalerSetBit(PB6_D5_MN_SCLKG_PLL_WD, ~(_BIT4 | _BIT3), _BIT4);

    // Set MN PLL Path1 => [2]: 1 = Path1, 0 = Path2
    ScalerSetBit(PB6_D5_MN_SCLKG_PLL_WD, ~(_BIT7 | _BIT2), _BIT2);

#if(_HW_PLL_EDGE_SELECT_TYPE == _PLL_EDGE_GEN_1_DEFAULT_POSITIVE)
    // Set PLL Edge = Negative
    ScalerSetBit(PB6_D7_MN_SCLKG_PLL_RESERVE, ~_BIT1, _BIT1);
#endif

    // DPLL VCORSTB Set to Normal
    ScalerSetBit(PB6_D6_MN_SCLKG_PLL_INSEL, ~_BIT0, _DPLL_VCORSTB_NORMAL_VALUE);

    // DPLL power up
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT7, 0x00);

    // Delay 2000us
    ScalerTimerDelayXms(2);

    // DPLL CMP enable
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT2, _BIT2);

    // Delay at least 1000us
    ScalerTimerDelayXms(2);

    // DPLL latch calibration enable
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT3, _BIT3);

    // Delay at least 1000us
    ScalerTimerDelayXms(2);

    // DPLL calibration validated
    ScalerSetBit(PB6_D3_MN_SCLKG_PLL_PWR, ~_BIT4, _BIT4);
}

//--------------------------------------------------
// Description  : Load initial I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0LoadInitialICode(void)
{
    // Set high byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB6_83_AUD_BDRY_2, HIBYTE(_INITIAL_I_CODE));

    // Set low byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB6_84_AUD_BDRY_3, LOBYTE(_INITIAL_I_CODE));

    DebugMessageAudio("Load initial I code", _INITIAL_I_CODE);
}

//--------------------------------------------------
// Description  : Timer Event to Load Stable I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0LoadStableICodeEvent(void)
{
    // Set high byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB6_83_AUD_BDRY_2, HIBYTE(_STABLE_I_CODE));

    // Set low byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB6_84_AUD_BDRY_3, LOBYTE(_STABLE_I_CODE));

    DebugMessageAudio("Load stable I code", _STABLE_I_CODE);
}

//--------------------------------------------------
// Description  : Detect D0 digital audio for HDMI/DP interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0DigitalDetectProc(void)
{
    if(GET_DP_RX0_LINK_TRAINING_STATUS() != _DP_NORMAL_LINK_TRAINING_PASS)
    {
        if(ScalerGetBit(PB6_81_AUD_BDRY_0, _BIT7) == _BIT7)
        {
            // -----------------------------------------
            // Disable Tracking Function
            // -----------------------------------------

            // Disable INT for Auido Sampling Change
            ScalerSetBit(PB6_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), 0x00);

            // Disable Boundary Tracking Method
            ScalerSetBit(PB6_81_AUD_BDRY_0, ~_BIT7, 0x00);

            // Disable Trend Tracking Method
            ScalerSetBit(PB6_92_AUD_TRND_0, ~_BIT7, 0x00);

            // Reload D code
            ScalerSetBit(PB6_7C_AUD_FSM_CTRL_1, ~_BIT7, _BIT7);

            DebugMessageAudio("D0 Audio Tracking Disable", 0);
        }

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D0_AUTO_LOAD_FREQ() == _TRUE)
        {
            // -----------------------------------------
            // Set User Define Frequency When No Audio
            // -----------------------------------------
            ScalerAudioD0AudioFrequencyMode(_AUDIO_TRACKING_MANNUAL_MODE);

            // Clear Flag
            CLR_AUDIO_D0_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx0 Audio Mannual Mode", 0);
        }
#endif

        CLR_AUDIO_D0_PACKET_DETECT();
        SET_D0_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

        if(GET_AUDIO_D0_ICODE_RELOADED() == _TRUE)
        {
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_AUDIO_D0_LOAD_STABLE_I_CODE);

            ScalerAudioD0LoadInitialICode();

            CLR_AUDIO_D0_ICODE_RELOADED();
        }

        return;
    }

    if(ScalerAudioD0SamplingFreqDetect() != 0x00)
    {
#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D0_AUTO_LOAD_FREQ() == _FALSE)
        {
            // -----------------------------------------
            // Set HW Auto Load Frequency
            // -----------------------------------------
            ScalerAudioD0AudioFrequencyMode(_AUDIO_TRACKING_AUTO_LOAD_MODE);

            // Set Flag
            SET_AUDIO_D0_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx0 Audio Auto_Load Mode", 0);
        }
#endif

        if(ScalerGetBit(PB6_81_AUD_BDRY_0, _BIT7) == 0x00)
        {
#if(_DIGITAL_AUDIO_OUTPUT_FIX_I2S_PHASE_DELAY == _ON)
            if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) == _AUDIO_FROM_D0_PORT)
            {
                // Resolve Audio Phase Delay of L/R Channel
                ScalerAudioDVCResetProc();
            }
#endif
            // -----------------------------------------
            // Enable Tracking Function
            // -----------------------------------------

            // Enable Boundary Tracking Method
            ScalerSetBit(PB6_81_AUD_BDRY_0, ~_BIT7, _BIT7);

            // Enable Trend Tracking Method
            ScalerSetBit(PB6_92_AUD_TRND_0, ~_BIT7, _BIT7);

            // Clear Auido Sampling Change Flag
            ScalerSetBit(PB6_50_AUD_FREQUENY_DET_0, ~_BIT5, _BIT5);

            // Enable INT for Auido Sampling Change
            ScalerSetBit(PB6_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), _BIT6);

            DebugMessageAudio("D0 Audio Tracking Enable", 0);
        }

        if(ScalerGetBit(PB6_01_DP_VBID, _BIT4) == 0x00)
        {
            SET_AUDIO_D0_PACKET_DETECT();
            SET_D0_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_DP);

            // Set DP Receive Port1 In Sync
            ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_IN_SYNC);
        }
        else
        {
            CLR_AUDIO_D0_PACKET_DETECT();
            SET_D0_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

            // Set DP Receive Port1 Out Of Sync
            ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
        }

        if(GET_AUDIO_D0_ICODE_RELOADED() == _FALSE)
        {
            ScalerTimerReactiveTimerEvent(_AUDIO_DYNAMIC_I_CODE_TIMER_MS, _SCALER_TIMER_EVENT_AUDIO_D0_LOAD_STABLE_I_CODE);

            SET_AUDIO_D0_ICODE_RELOADED();
        }
    }
    else
    {
        if(ScalerGetBit(PB6_81_AUD_BDRY_0, _BIT7) == _BIT7)
        {
            // Disable INT for Auido Sampling Change
            ScalerSetBit(PB6_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), 0x00);

            // Disable Boundary Tracking Method
            ScalerSetBit(PB6_81_AUD_BDRY_0, ~_BIT7, 0x00);

            // Disable Trend Tracking Method
            ScalerSetBit(PB6_92_AUD_TRND_0, ~_BIT7, 0x00);

            // Reload D code
            ScalerSetBit(PB6_7C_AUD_FSM_CTRL_1, ~_BIT7, _BIT7);

            DebugMessageAudio("D0 Audio Tracking Disable", 0);
        }

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D0_AUTO_LOAD_FREQ() == _TRUE)
        {
            // -----------------------------------------
            // Set User Define Frequency When No Audio
            // -----------------------------------------
            ScalerAudioD0AudioFrequencyMode(_AUDIO_TRACKING_MANNUAL_MODE);

            // Clear Flag
            CLR_AUDIO_D0_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx0 Audio Mannual Mode", 0);
        }
#endif

        if(GET_D0_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
        {
            // Set DP Receive Port1 Out Of Sync
            ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
        }

        CLR_AUDIO_D0_PACKET_DETECT();
        SET_D0_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

        if(GET_AUDIO_D0_ICODE_RELOADED() == _TRUE)
        {
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_AUDIO_D0_LOAD_STABLE_I_CODE);

            ScalerAudioD0LoadInitialICode();

            CLR_AUDIO_D0_ICODE_RELOADED();
        }
    }
}

//--------------------------------------------------
// Description  : Get D0 Audio Detected
// Input Value  : None
// Output Value : TRUE => Audio Detected
//--------------------------------------------------
bit ScalerAudioD0GetAudioDetected(void)
{
    // Check audio packet
    if(GET_AUDIO_D0_PACKET_DETECT() == _FALSE)
    {
        DebugMessageAudio("False : D0 Audio Packet", 0);
        return _FALSE;
    }

    // Check Audio FSM
    if(ScalerGetBit(PB6_74_AUD_FSM_CTRL_0, _BIT7) == 0x00)
    {
        DebugMessageAudio("False : D0 DP Audio Fsm Disable", 0);

        return _FALSE;
    }

    // Check Audio Tracking
    if(ScalerGetBit(PB6_81_AUD_BDRY_0, _BIT7) == 0x00)
    {
        DebugMessageAudio("False : D0 DP Audio Tracking Disable", 0);

        return _FALSE;
    }

    // Check DP audio buffer overflow and underflow
    if(ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
    {
        DebugMessageAudio("False : D0 DP Audio Buffer", ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

        if(ScalerGetBit(PB6_39_DP_AWD_CTRL, (_BIT7 | _BIT6)) == 0x00)
        {
            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(PB6_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
            ScalerTimerDelayXms(3);

            if(ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageAudio("False : D0 DP Audio FSM Reset", ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

                // Reset Audio FSM
                ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, 0x00);

                // Clear audio FIFO overflow and underflow status
                ScalerSetBit(PB6_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

                // Enable Audio FSM
                ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, _BIT7);

                // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
                ScalerTimerDelayXms(3);
            }
        }

        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Detect D0 Audio Sampling Freq
// Input Value  : None
// Output Value : Audio Sampling Freq
//--------------------------------------------------
EnumAudioSamplingFreqType ScalerAudioD0SamplingFreqDetect(void)
{
    EnumAudioSamplingFreqType enumAudioFreq = _AUDIO_FREQ_NO_AUDIO;

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
    {
        // For Audio test pattern
        SET_AUDIO_D0_SAMPLING_FREQ(_AUDIO_FREQ_48K);
        return _AUDIO_FREQ_48K;
    }
#endif

    // HBR Audio Detect
    ScalerAudioD0HbrAudioDetect();

    // Get Audio Sample Count
    enumAudioFreq = (ScalerGetBit(PB6_61_AUD_SAMPLE_CNT_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4);

    if(enumAudioFreq != GET_AUDIO_D0_SAMPLING_FREQ())
    {
#if(_EMBEDDED_DAC_SUPPORT == _ON)
        if(enumAudioFreq <= _AUDIO_FREQ_64K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), 0x00);
        }
        else if(enumAudioFreq <= _AUDIO_FREQ_128K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT6);
        }
        else
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT7);
        }
#endif

        // Audio DVC Setting
        ScalerAudioD0DPSetDVCWindowSize(_DP_DVC_ADJUST_TYPE, ScalerAudioGetSamplingFreqPacket(enumAudioFreq));
    }

    SET_AUDIO_D0_SAMPLING_FREQ(enumAudioFreq);

    return enumAudioFreq;
}

//--------------------------------------------------
// Description  : Check Audio Sampling Frequency Ever Change
// Input Value  : None
// Output Value : _TRUE => Change / _FALSE => No Change
//--------------------------------------------------
bit ScalerAudioD0SamplingFreqChange(void)
{
    if(GET_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE() == _TRUE)
    {
        // Clear Change Flag when check
        CLR_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE();

        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : D0 Audio Watch Dog Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0WatchDogProc(bit bOn)
{
    if(bOn == _ON)
    {
        // Clear audio buffer overflow and underflow status
        ScalerSetBit(PB6_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Enable Audio Watch Dog for Buffer Overflow/Underflow
        ScalerSetBit(PB6_39_DP_AWD_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }
    else
    {
        // Disable Audio Watch Dog for Buffer Overflow/Underflow
        ScalerSetBit(PB6_39_DP_AWD_CTRL, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageAudio("WD : D0 DP Audio Over/Underflow", ScalerGetBit(PB6_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

            // Reset Audio FSM
            ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, 0x00);

            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(PB6_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Enable Audio FSM
            ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, _BIT7);

            // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
            ScalerTimerDelayXms(3);
        }
    }
}

//--------------------------------------------------
// Description  : D0 Audio HBR Packet Detect
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0HbrAudioDetect(void)
{
    // Check HBR Audio Receive
    if(ScalerGetBit(PB6_B0_DP_AUD_CTRL, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == _BIT0)
    {
        // Check Current Detect Mode
        if(ScalerGetBit(PB6_B0_DP_AUD_CTRL, _BIT6) != _BIT6)
        {
            // Enable Audio HBR Mode Detect
            ScalerAudioD0HbrModeControl(_ON);

            // Wait for New Audio Packet Recived via detect interval + 1ms
            ScalerTimerDelayXms((ScalerGetBit(PB6_50_AUD_FREQUENY_DET_0, (_BIT3 | _BIT2)) >> 2) + 1);

            DebugMessageAudio("Dp D0 HBR Mode Detect Enable", _ENABLE);
        }
    }
    else
    {
        // Check Current Detect Mode
        if(ScalerGetBit(PB6_B0_DP_AUD_CTRL, _BIT6) != 0x00)
        {
            // Disable Audio HBR Mode Detect
            ScalerAudioD0HbrModeControl(_OFF);

            // Wait for New Audio Packet Recived via detect interval + 1ms
            ScalerTimerDelayXms((ScalerGetBit(PB6_50_AUD_FREQUENY_DET_0, (_BIT3 | _BIT2)) >> 2) + 1);

            DebugMessageAudio("Dp D0 HBR Mode Detect Disable", _DISABLE);
        }
    }
}

//--------------------------------------------------
// Description  : D0 Audio HBR Mode Control
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioD0HbrModeControl(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable Dp Audio HBR Mode Detect via Channel Coding Type
        ScalerSetBit(PB6_B0_DP_AUD_CTRL, ~_BIT6, _BIT6);
    }
    else
    {
        // Disable Audio HBR Mode Detect
        ScalerSetBit(PB6_B0_DP_AUD_CTRL, ~_BIT6, 0x00);
    }
}
#endif // End Of #if(_D0_DP_EXIST == _ON)

#if(_D1_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Initial D1 Auido PLL Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1SetAudioPLL(void)
{
    // DPLL power down
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set M code
    ScalerSetByte(PB9_D1_MN_SCLKG_DIVM, (_AUDIO_PLL_M - 2));

    // Set O code
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), 0x00);

    // Set N(K) code and enable double buffer
    ScalerSetByte(PB9_D2_MN_SCLKG_DIVN, (_AUDIO_PLL_K - 2));

    // Initial VCO Band = 10
    ScalerSetBit(PB9_D5_MN_SCLKG_PLL_WD, ~(_BIT4 | _BIT3), _BIT4);

    // Set MN PLL Path1 => [2]: 1 = Path1, 0 = Path2
    ScalerSetBit(PB9_D5_MN_SCLKG_PLL_WD, ~(_BIT7 | _BIT2), _BIT2);

#if(_HW_PLL_EDGE_SELECT_TYPE == _PLL_EDGE_GEN_1_DEFAULT_POSITIVE)
    // Set PLL Edge = Negative
    ScalerSetBit(PB9_D7_MN_SCLKG_PLL_RESERVE, ~_BIT1, _BIT1);
#endif

    // DPLL VCORSTB Set to Normal
    ScalerSetBit(PB9_D6_MN_SCLKG_PLL_INSEL, ~_BIT0, _DPLL_VCORSTB_NORMAL_VALUE);

    // DPLL power up
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT7, 0x00);

    // Delay 2000us
    ScalerTimerDelayXms(2);

    // DPLL CMP enable
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT2, _BIT2);

    // Delay 1000us
    ScalerTimerDelayXms(2);

    // DPLL latch calibration enable
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT3, _BIT3);

    // Delay 1000us
    ScalerTimerDelayXms(2);

    // DPLL calibration validated
    ScalerSetBit(PB9_D3_MN_SCLKG_PLL_PWR, ~_BIT4, _BIT4);
}

//--------------------------------------------------
// Description  : Load initial I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1LoadInitialICode(void)
{
    // Set high byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB9_83_AUD_BDRY_2, HIBYTE(_INITIAL_I_CODE));

    // Set low byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB9_84_AUD_BDRY_3, LOBYTE(_INITIAL_I_CODE));

    DebugMessageAudio("Load initial I code", _INITIAL_I_CODE);
}

//--------------------------------------------------
// Description  : Timer Event to Load Stable I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1LoadStableICodeEvent(void)
{
    // Set high byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB9_83_AUD_BDRY_2, HIBYTE(_STABLE_I_CODE));

    // Set low byte of I code for boundary tracking for DP audio
    ScalerSetByte(PB9_84_AUD_BDRY_3, LOBYTE(_STABLE_I_CODE));

    DebugMessageAudio("Load stable I code", _STABLE_I_CODE);
}

//--------------------------------------------------
// Description  : Detect D1 digital audio for HDMI/DP interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1DigitalDetectProc(void)
{
    if(GET_DP_RX1_LINK_TRAINING_STATUS() != _DP_NORMAL_LINK_TRAINING_PASS)
    {
        if(ScalerGetBit(PB9_81_AUD_BDRY_0, _BIT7) == _BIT7)
        {
            // -----------------------------------------
            // Disable Tracking Function
            // -----------------------------------------

            // Disable INT for Auido Sampling Change
            ScalerSetBit(PB9_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), 0x00);

            // Disable Boundary Tracking Method
            ScalerSetBit(PB9_81_AUD_BDRY_0, ~_BIT7, 0x00);

            // Disable Trend Tracking Method
            ScalerSetBit(PB9_92_AUD_TRND_0, ~_BIT7, 0x00);

            // Reload D code
            ScalerSetBit(PB9_7C_AUD_FSM_CTRL_1, ~_BIT7, _BIT7);

            DebugMessageAudio("D1 Audio Tracking Disable", 0);
        }

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D1_AUTO_LOAD_FREQ() == _TRUE)
        {
            // -----------------------------------------
            // Set User Define Frequency When No Audio
            // -----------------------------------------
            ScalerAudioD1AudioFrequencyMode(_AUDIO_TRACKING_MANNUAL_MODE);

            // Clear Flag
            CLR_AUDIO_D1_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx1 Audio Mannual Mode", 0);
        }
#endif

        CLR_AUDIO_D1_PACKET_DETECT();
        SET_D1_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

        if(GET_AUDIO_D1_ICODE_RELOADED() == _TRUE)
        {
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_AUDIO_D1_LOAD_STABLE_I_CODE);

            ScalerAudioD1LoadInitialICode();

            CLR_AUDIO_D1_ICODE_RELOADED();
        }

        return;
    }

    if(ScalerAudioD1SamplingFreqDetect() != 0x00)
    {
#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D1_AUTO_LOAD_FREQ() == _FALSE)
        {
            // -----------------------------------------
            // Set HW Auto Load Frequency
            // -----------------------------------------
            ScalerAudioD1AudioFrequencyMode(_AUDIO_TRACKING_AUTO_LOAD_MODE);

            // Set Flag
            SET_AUDIO_D1_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx1 Audio Auto_Load Mode", 0);
        }
#endif

        if(ScalerGetBit(PB9_81_AUD_BDRY_0, _BIT7) == 0x00)
        {
#if(_DIGITAL_AUDIO_OUTPUT_FIX_I2S_PHASE_DELAY == _ON)
            if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) == _AUDIO_FROM_D1_PORT)
            {
                // Resolve Audio Phase Delay of L/R Channel
                ScalerAudioDVCResetProc();
            }
#endif
            // -----------------------------------------
            // Enable Tracking Function
            // -----------------------------------------

            // Enable Boundary Tracking Method
            ScalerSetBit(PB9_81_AUD_BDRY_0, ~_BIT7, _BIT7);

            // Enable Trend Tracking Method
            ScalerSetBit(PB9_92_AUD_TRND_0, ~_BIT7, _BIT7);

            // Clear Auido Sampling Change Flag
            ScalerSetBit(PB9_50_AUD_FREQUENY_DET_0, ~_BIT5, _BIT5);

            // Enable INT for Auido Sampling Change
            ScalerSetBit(PB9_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), _BIT6);

            DebugMessageAudio("D1 Audio Tracking Enable", 0);
        }

        if(ScalerGetBit(PB9_01_DP_VBID, _BIT4) == 0x00)
        {
            SET_AUDIO_D1_PACKET_DETECT();
            SET_D1_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_DP);

            // Set DP Receive Port1 In Sync
            ScalerDpRx1SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_IN_SYNC);
        }
        else
        {
            CLR_AUDIO_D1_PACKET_DETECT();
            SET_D1_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

            // Set DP Receive Port1 Out Of Sync
            ScalerDpRx1SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
        }

        if(GET_AUDIO_D1_ICODE_RELOADED() == _FALSE)
        {
            ScalerTimerReactiveTimerEvent(_AUDIO_DYNAMIC_I_CODE_TIMER_MS, _SCALER_TIMER_EVENT_AUDIO_D1_LOAD_STABLE_I_CODE);

            SET_AUDIO_D1_ICODE_RELOADED();
        }
    }
    else
    {
        if(ScalerGetBit(PB9_81_AUD_BDRY_0, _BIT7) == _BIT7)
        {
            // Disable INT for Auido Sampling Change
            ScalerSetBit(PB9_50_AUD_FREQUENY_DET_0, ~(_BIT6 | _BIT5), 0x00);

            // Disable Boundary Tracking Method
            ScalerSetBit(PB9_81_AUD_BDRY_0, ~_BIT7, 0x00);

            // Disable Trend Tracking Method
            ScalerSetBit(PB9_92_AUD_TRND_0, ~_BIT7, 0x00);

            // Reload D code
            ScalerSetBit(PB9_7C_AUD_FSM_CTRL_1, ~_BIT7, _BIT7);

            DebugMessageAudio("D1 Audio Tracking Disable", 0);
        }

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
        if(GET_AUDIO_D1_AUTO_LOAD_FREQ() == _TRUE)
        {
            // -----------------------------------------
            // Set User Define Frequency When No Audio
            // -----------------------------------------
            ScalerAudioD1AudioFrequencyMode(_AUDIO_TRACKING_MANNUAL_MODE);

            // Clear Flag
            CLR_AUDIO_D1_AUTO_LOAD_FREQ();

            DebugMessageAudio("Dp Rx1 Audio Mannual Mode", 0);
        }
#endif

        if(GET_D1_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
        {
            // Set DP Receive Port1 Out Of Sync
            ScalerDpRx1SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
        }

        CLR_AUDIO_D1_PACKET_DETECT();
        SET_D1_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

        if(GET_AUDIO_D1_ICODE_RELOADED() == _TRUE)
        {
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_AUDIO_D1_LOAD_STABLE_I_CODE);

            ScalerAudioD1LoadInitialICode();

            CLR_AUDIO_D1_ICODE_RELOADED();
        }
    }
}

//--------------------------------------------------
// Description  : Get D1 Audio Detected
// Input Value  : None
// Output Value : TRUE => Audio Detected
//--------------------------------------------------
bit ScalerAudioD1GetAudioDetected(void)
{
    // Check audio packet
    if(GET_AUDIO_D1_PACKET_DETECT() == _FALSE)
    {
        DebugMessageAudio("False : D1 Audio Packet", 0);
        return _FALSE;
    }

    // Check Audio FSM
    if(ScalerGetBit(PB9_74_AUD_FSM_CTRL_0, _BIT7) == 0x00)
    {
        DebugMessageAudio("False : D1 DP Audio Fsm Disable", 0);

        return _FALSE;
    }

    // Check Audio Tracking
    if(ScalerGetBit(PB9_81_AUD_BDRY_0, _BIT7) == 0x00)
    {
        DebugMessageAudio("False : D1 DP Audio Tracking Disable", 0);

        return _FALSE;
    }

    // Check DP audio buffer overflow and underflow
    if(ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
    {
        DebugMessageAudio("False : D1 DP Audio Buffer", ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

        if(ScalerGetBit(PB9_39_DP_AWD_CTRL, (_BIT7 | _BIT6)) == 0x00)
        {
            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(PB9_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
            ScalerTimerDelayXms(3);

            if(ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageAudio("False : D1 DP Audio FSM Reset", ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

                // Reset Audio FSM
                ScalerSetBit(PB9_74_AUD_FSM_CTRL_0, ~_BIT7, 0x00);

                // Clear audio FIFO overflow and underflow status
                ScalerSetBit(PB9_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

                // Enable Audio FSM
                ScalerSetBit(PB9_74_AUD_FSM_CTRL_0, ~_BIT7, _BIT7);

                // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
                ScalerTimerDelayXms(3);
            }
        }

        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Detect D1 Audio Sampling Freq
// Input Value  : None
// Output Value : Audio Sampling Freq
//--------------------------------------------------
EnumAudioSamplingFreqType ScalerAudioD1SamplingFreqDetect(void)
{
    EnumAudioSamplingFreqType enumAudioFreq = _AUDIO_FREQ_NO_AUDIO;

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioDpGetInternalAudioGenEnable() == _ENABLE)
    {
        // For Audio test pattern
        SET_AUDIO_D1_SAMPLING_FREQ(_AUDIO_FREQ_48K);
        return _AUDIO_FREQ_48K;
    }
#endif

    // HBR Audio Detect
    ScalerAudioD1HbrAudioDetect();

    // Get Audio Sample Count
    enumAudioFreq = (ScalerGetBit(PB9_61_AUD_SAMPLE_CNT_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4);

    if(enumAudioFreq != GET_AUDIO_D1_SAMPLING_FREQ())
    {
#if(_EMBEDDED_DAC_SUPPORT == _ON)
        if(enumAudioFreq <= _AUDIO_FREQ_64K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), 0x00);
        }
        else if(enumAudioFreq <= _AUDIO_FREQ_128K)
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT6);
        }
        else
        {
            ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT7 | _BIT6), _BIT7);
        }
#endif

        // Audio DVC Setting
        ScalerAudioD1DPSetDVCWindowSize(_DP_DVC_ADJUST_TYPE, ScalerAudioGetSamplingFreqPacket(enumAudioFreq));
    }

    SET_AUDIO_D1_SAMPLING_FREQ(enumAudioFreq);

    return enumAudioFreq;
}

//--------------------------------------------------
// Description  : Check Audio Sampling Frequency Ever Change
// Input Value  : None
// Output Value : _TRUE => Change / _FALSE => No Change
//--------------------------------------------------
bit ScalerAudioD1SamplingFreqChange(void)
{
    if(GET_DP_D1_AUDIO_SAMPLING_FREQ_CHANGE() == _TRUE)
    {
        // Clear Change Flag when check
        CLR_DP_D1_AUDIO_SAMPLING_FREQ_CHANGE();

        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : D1 Audio Watch Dog Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1WatchDogProc(bit bOn)
{
    if(bOn == _ON)
    {
        // Clear audio buffer overflow and underflow status
        ScalerSetBit(PB9_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Enable Audio Watch Dog for Buffer Overflow/Underflow
        ScalerSetBit(PB9_39_DP_AWD_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }
    else
    {
        // Disable Audio Watch Dog for Buffer Overflow/Underflow
        ScalerSetBit(PB9_39_DP_AWD_CTRL, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageAudio("WD : D1 DP Audio Over/Underflow", ScalerGetBit(PB9_70_AUD_BUFFER_CTRL_0, (_BIT1 | _BIT0)));

            // Reset Audio FSM
            ScalerSetBit(PB9_74_AUD_FSM_CTRL_0, ~_BIT7, 0x00);

            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(PB9_70_AUD_BUFFER_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Enable Audio FSM
            ScalerSetBit(PB9_74_AUD_FSM_CTRL_0, ~_BIT7, _BIT7);

            // Waiting for 2ms(Audio Freq. Detect || Audio FIFO Write (1/2 FIFO depth = 64 packet)) + 1ms(Audio Stable Time Count = 5 x 200us)
            ScalerTimerDelayXms(3);
        }
    }
}

//--------------------------------------------------
// Description  : D1 Audio HBR Packet Detect
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1HbrAudioDetect(void)
{
    // Check HBR Audio Receive
    if(ScalerGetBit(PB9_B0_DP_AUD_CTRL, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == _BIT0)
    {
        // Check Current Detect Mode
        if(ScalerGetBit(PB9_B0_DP_AUD_CTRL, _BIT6) != _BIT6)
        {
            // Enable Audio HBR Mode Detect
            ScalerAudioD1HbrModeControl(_ON);

            // Wait for New Audio Packet Recived via detect interval + 1ms
            ScalerTimerDelayXms((ScalerGetBit(PB9_50_AUD_FREQUENY_DET_0, (_BIT3 | _BIT2)) >> 2) + 1);

            DebugMessageAudio("Dp D1 HBR Mode Detect Enable", _ENABLE);
        }
    }
    else
    {
        // Check Current Detect Mode
        if(ScalerGetBit(PB9_B0_DP_AUD_CTRL, _BIT6) != 0x00)
        {
            // Disable Audio HBR Mode Detect
            ScalerAudioD1HbrModeControl(_OFF);

            // Wait for New Audio Packet Recived via detect interval + 1ms
            ScalerTimerDelayXms((ScalerGetBit(PB9_50_AUD_FREQUENY_DET_0, (_BIT3 | _BIT2)) >> 2) + 1);

            DebugMessageAudio("Dp D1 HBR Mode Detect Disable", _DISABLE);
        }
    }
}

//--------------------------------------------------
// Description  : D1 Audio HBR Mode Control
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioD1HbrModeControl(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable Dp Audio HBR Mode Detect via Channel Coding Type
        ScalerSetBit(PB9_B0_DP_AUD_CTRL, ~_BIT6, _BIT6);
    }
    else
    {
        // Disable Audio HBR Mode Detect
        ScalerSetBit(PB9_B0_DP_AUD_CTRL, ~_BIT6, 0x00);
    }
}
#endif // End Of #if(_D1_DP_EXIST == _ON)
#endif // End Of #if(_DP_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get Current Digital Audio Source
// Input Value  : None
// Output Value : Digital Audio Source
//--------------------------------------------------
BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
            return GET_D0_DIGITAL_AUDIO_SOURCE();
#endif

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
            return GET_D1_DIGITAL_AUDIO_SOURCE();
#endif

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            return GET_D2_DIGITAL_AUDIO_SOURCE();
#endif

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            return GET_D3_DIGITAL_AUDIO_SOURCE();
#endif

        default:
            break;
    }

    return _DIGITAL_AUDIO_SOURCE_NONE;
}

#if(_LINE_IN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Audio ADC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioADCInitial(void)
{
    // Enable ADDA Loop, High Pass Filter and Set ADC ZCD Type
    ScalerSetBit(P6_B4_AD_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2), (_BIT6 | _BIT3));

    // Power On ADC
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Power On Input Buffer and Mbias
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Adj ADC OP Noise Cancellation Clock and Enable ADC Op Offset Cancellation and Enable Dither
    ScalerSetBit(P6_B2_REG_ADC_CTRL, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT0));

    if(ScalerGlobalGetIDCode() == _RL6449_VER_A_ID_CODE)
    {
        // Set ADC Front End Gain(-7dB)
        ScalerSetByte(P6_B3_REG_AFE_GAIN, 0x44);
    }
    else
    {
        // Set ADC Front End Gain(-5dB)
        ScalerSetByte(P6_B3_REG_AFE_GAIN, 0x77);

        // Bypass Input Buffer
        ScalerSetBit(P6_B0_REG_ADC_POWER, ~_BIT0, _BIT0);
    }

    // ADC Unmute and Set Boost Gain
    ScalerSetByte(P6_B5_AD_MUTE, 0x00);

    // Set AD Gail of L Ch
    ScalerSetBit(P6_B6_AD_GAIN_L, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _LINE_IN_BOOST_GAIN_DB);

    // Set AD Gail of R Ch
    ScalerSetBit(P6_B7_AD_GAIN_R, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _LINE_IN_BOOST_GAIN_DB);

    // Set Double Buffer
    ScalerSetBit(P6_B6_AD_GAIN_L, ~_BIT7, _BIT7);

    // Set Sampling Frequency "48kHz" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_48KHZ);

    // Set Channel Count "2 ch" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E3_AD_SPDIF_CS_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Enable I2S Output for ADC In
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT7, _BIT7);
}
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Auido Speaker Testing Process
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
void ScalerAudioInternalAudioGenSwitch(bit bOn, BYTE ucInputPort, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
            ScalerAudioDpInternalAudioGenSwitch(bOn, enumAudioLeftRightChannelSelect);
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
            ScalerAudioDpInternalAudioGenSwitch(bOn, enumAudioLeftRightChannelSelect);
#endif
            break;

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            ScalerAudioD2InternalAudioGenSwitch(bOn, enumAudioLeftRightChannelSelect);
#endif
            break;

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            ScalerAudioD3InternalAudioGenSwitch(bOn, enumAudioLeftRightChannelSelect);
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Get Whether Internal Audio Pattern Gen is Enabled
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_EXIST == _ON)
            return ScalerAudioDpGetInternalAudioGenEnable();
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
            return ScalerAudioDpGetInternalAudioGenEnable();
#endif
            break;

        case _D2_INPUT_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            return ScalerAudioD2GetInternalAudioGenEnable();
#endif

        case _D3_INPUT_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            return ScalerAudioD3GetInternalAudioGenEnable();
#endif

        default:
            break;
    }

    return _DISABLE;
}

//--------------------------------------------------
// Description  : Reset Audio Module when Internal Audio Pattern Gen is Finished
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioInternalAudioGenReset(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

#if(_D0_DP_EXIST == _ON)
#if(_D2_HDMI_SUPPORT == _OFF)
            // Power Down D2 DPLL
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT7, _BIT7);
#endif
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_DP_EXIST == _ON)
#if(_D2_HDMI_SUPPORT == _OFF)
            // Power Down D2 DPLL
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_38_PORT_PAGE71_HDMI_DPCR0, ~_BIT7, _BIT7);
#endif
#endif
            break;

        case _D2_INPUT_PORT:
        case _D3_INPUT_PORT:
        case _D4_INPUT_PORT:
        case _D5_INPUT_PORT:
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Set Internal Audio Gen Input Port
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioSetInternalGenInputPort(BYTE ucInputPort)
{
    SET_AUDIO_INTERNAL_GEN_INPUT_PORT(ucInputPort);
}

//--------------------------------------------------
// Description  : Get Internal Audio Gen Input Port
// Input Value  : None
// Output Value : ucInputPort
//--------------------------------------------------
BYTE ScalerAudioGetInternalGenInputPort(void)
{
    return GET_AUDIO_INTERNAL_GEN_INPUT_PORT();
}

#if((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON))
//--------------------------------------------------
// Description  : D2 Auido Speaker Testing Process
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpInternalAudioGenSwitch(bit bOn, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect)
{
    enumAudioLeftRightChannelSelect = enumAudioLeftRightChannelSelect;

    if(bOn == _ON)
    {
        DebugMessageAudio("Dp Audio Test On", ScalerGetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, _BIT4));

#if(_D2_HDMI_SUPPORT == _OFF)
        // Initial D2 HDMI Audio
        ScalerAudioD2HDMIAudioInitial();
#endif

        // Disable audio FIFO and Enable audio internal generator
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, ~(_BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);

        // Disbale DPLL Freq. Tuning
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3A_PORT_PAGE71_HDMI_DPCR2, ~_BIT1, 0x00);

        // Audio Normal Output
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_30_PORT_PAGE71_HDMI_AVMCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

        // Set S code
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_12_PORT_PAGE71_HDMI_SCAPR, GET_AUDIO_GEN_FREQ_S_CODE());

        // Set D code
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_13_PORT_PAGE71_HDMI_DCAPR0, HIBYTE(GET_AUDIO_GEN_FREQ_D_CODE()));
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_14_PORT_PAGE71_HDMI_DCAPR1, LOBYTE(GET_AUDIO_GEN_FREQ_D_CODE()));

        // Disable sample freq. detection and auto load S code / D code
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8A_PORT_PAGE71_AUDIO_FREQDET, ~(_BIT7 | _BIT6), 0x00);

        // Enable double buffer
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_10_PORT_PAGE71_HDMI_CMCR, ~_BIT4, _BIT4);

        if(enumAudioLeftRightChannelSelect == _AUDIO_LEFT_CHANNEL)
        {
            // HDMI MAC DVC Mute Off Left channel
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (_BIT1));
        }
        else if(enumAudioLeftRightChannelSelect == _AUDIO_RIGHT_CHANNEL)
        {
            // HDMI MAC DVC Mute Off Right channel
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (_BIT0));
        }
        else
        {
            // HDMI MAC DVC Mute Off
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        }

        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_08_PORT_PAGE71_HDMI_MAG_L_FINAL, 0x00);
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_09_PORT_PAGE71_HDMI_MAG_R_FINAL, 0x00);
    }
    else
    {
        DebugMessageAudio("Dp Aduio Test Off", ScalerGetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, _BIT4));

        // HDMI MAC DVC Mute On
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_07_PORT_PAGE71_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_08_PORT_PAGE71_HDMI_MAG_L_FINAL, 0x00);
        ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_09_PORT_PAGE71_HDMI_MAG_R_FINAL, 0x00);

#if(_D2_HDMI_SUPPORT == _OFF)
        // Disable audio internal generator
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, ~_BIT4, 0x00);
#else
        // Enable sample freq. detection and auto load S code
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_8A_PORT_PAGE71_AUDIO_FREQDET, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

        // Enable double buffer
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_10_PORT_PAGE71_HDMI_CMCR, ~_BIT4, _BIT4);

        // Enable DPLL Freq. Tuning
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_3A_PORT_PAGE71_HDMI_DPCR2, ~_BIT1, _BIT1);

        // Enable audio FIFO and Disable audio internal generator
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, ~(_BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT2 | _BIT1));
#endif
    }
}

//--------------------------------------------------
// Description  : Get Whether Internal Audio Pattern Gen is Enabled
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit ScalerAudioDpGetInternalAudioGenEnable(void)
{
    if(ScalerGetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_03_PORT_PAGE71_HDMI_AFCR, _BIT4) == _BIT4)
    {
        return _ENABLE;
    }
    else
    {
        return _DISABLE;
    }
}
#endif // End of #if((_D0_DP_EXIST == _ON) || (_D1_DP_EXIST == _ON) || (_D1_HDMI_SUPPORT == _ON))
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Audio Channel Status of Rx Port
// Input Value  : None
// Output Value : Channel Status
//--------------------------------------------------
StructAudioChannelInfo ScalerAudioGetRxChannelStatus(void)
{
    StructAudioChannelInfo stAudioStatus = {0x00, 0x00, 0x00, 0x00, 0x00};
    BYTE ucTemp = 0;

    ucTemp = ucTemp;

    switch(ScalerAudioGetDigitalAudioPort(_AUDIO_DPTX_OUT))
    {
        case _AUDIO_FROM_D0_PORT:

#if(_D0_DP_EXIST == _ON)
            // Get Channel_Status[7:0]
            stAudioStatus.ucChannelStaus0 = ScalerGetByte(PB6_2A_DP_AUD_CH_STATUS4);

            // Get Channel_Status[15:8]
            stAudioStatus.ucChannelStaus1 = ScalerGetByte(PB6_29_DP_AUD_CH_STATUS3);

            // Get Channel_Status[23:16]
            stAudioStatus.ucChannelStaus2 = ScalerGetByte(PB6_28_DP_AUD_CH_STATUS2);

            // Get Channel_Status[31:24]
            stAudioStatus.ucChannelStaus3 = ScalerGetByte(PB6_27_DP_AUD_CH_STATUS1);

            // Get Channel_Status[39:32]
            stAudioStatus.ucChannelStaus4 = ScalerGetByte(PB6_26_DP_AUD_CH_STATUS0);
#endif
            break;

        case _AUDIO_FROM_D1_PORT:

#if(_D1_DP_EXIST == _ON)
            // Get Channel_Status[7:0]
            stAudioStatus.ucChannelStaus0 = ScalerGetByte(PB9_2A_DP_AUD_CH_STATUS4);

            // Get Channel_Status[15:8]
            stAudioStatus.ucChannelStaus1 = ScalerGetByte(PB9_29_DP_AUD_CH_STATUS3);

            // Get Channel_Status[23:16]
            stAudioStatus.ucChannelStaus2 = ScalerGetByte(PB9_28_DP_AUD_CH_STATUS2);

            // Get Channel_Status[31:24]
            stAudioStatus.ucChannelStaus3 = ScalerGetByte(PB9_27_DP_AUD_CH_STATUS1);

            // Get Channel_Status[39:32]
            stAudioStatus.ucChannelStaus4 = ScalerGetByte(PB9_26_DP_AUD_CH_STATUS0);
#endif
            break;

        case _AUDIO_FROM_D2_PORT:

#if(_D2_HDMI_SUPPORT == _ON)
            // Load Ch1 Channel_Status
            ucTemp = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR);
            ScalerSetDataPortByte(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ((ucTemp & 0xFC) | 0x01));

            // Get Channel_Status[7:0]
            stAudioStatus.ucChannelStaus0 = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_57_PORT_PAGE71_HDMI_ACS0);

            // Get Channel_Status[15:8]
            stAudioStatus.ucChannelStaus1 = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_58_PORT_PAGE71_HDMI_ACS1);

            // Get Channel_Status[23:16]
            stAudioStatus.ucChannelStaus2 = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_59_PORT_PAGE71_HDMI_ACS2);

            // Get Channel_Status[31:24]
            stAudioStatus.ucChannelStaus3 = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_5A_PORT_PAGE71_HDMI_ACS3);

            // Get Channel_Status[39:32]
            stAudioStatus.ucChannelStaus4 = ScalerGetDataPortSingleByte(P71_C9_HDMI_AP, _P71_CA_PT_5B_PORT_PAGE71_HDMI_ACS4);
#endif
            break;

        case _AUDIO_FROM_D3_PORT:

#if(_D3_HDMI_SUPPORT == _ON)
            // Load Ch1 Channel_Status
            ucTemp = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR);
            ScalerSetDataPortByte(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ((ucTemp & 0xFC) | 0x01));

            // Get Channel_Status[7:0]
            stAudioStatus.ucChannelStaus0 = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_57_PORT_PAGE72_HDMI_ACS0);

            // Get Channel_Status[15:8]
            stAudioStatus.ucChannelStaus1 = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_58_PORT_PAGE72_HDMI_ACS1);

            // Get Channel_Status[23:16]
            stAudioStatus.ucChannelStaus2 = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_59_PORT_PAGE72_HDMI_ACS2);

            // Get Channel_Status[31:24]
            stAudioStatus.ucChannelStaus3 = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_5A_PORT_PAGE72_HDMI_ACS3);

            // Get Channel_Status[39:32]
            stAudioStatus.ucChannelStaus4 = ScalerGetDataPortSingleByte(P72_C9_HDMI_AP, _P72_CA_PT_5B_PORT_PAGE72_HDMI_ACS4);
#endif
            break;

        case _AUDIO_FROM_ADC_PORT:

#if(_LINE_IN_SUPPORT == _ON)
            // Mode 0 channel status format for consumer use(IEC 60958)

            // [0] = 0, Consumer use;
            // [1] = 0, LPCM Audio;
            // [2] = 1, No Copyright;
            // [5:3] = 3'b000, 2-ch audio without pre-emphasis;
            // [7:6] = 2'b00, Mode 0.
            stAudioStatus.ucChannelStaus0 = 0x04;

            // [15:8] = 8'b10000000, Category code is not defined.
            stAudioStatus.ucChannelStaus1 = 0x80;

            // [19:16] = 4'b0000, Source number do not take into account;
            // [23:20] Set Dummy and Reference by AudioChannelNumStaus1 ~ 8.
            stAudioStatus.ucChannelStaus2 = 0x00;

            // [27:24] = 4'b0010, 48kHz;
            // [29:28] = 2'b00, Clock accuracy Level II.
            stAudioStatus.ucChannelStaus3 = 0x02;

            // [32] = 1, 24-bits Sample;
            // [35:33] = 3'b101;
            // [39:36] = 4'b0000, Original sampling frequency not indicated.
            stAudioStatus.ucChannelStaus4 = 0x0B;
#endif
            break;

        default:
            break;
    }

    return stAudioStatus;
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)
#endif // End Of #if(_AUDIO_SUPPORT == _ON)

