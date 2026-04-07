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
// ID Code      : RL6851_Series_Audio.c No.0000
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
StructAudioDigitalInfo g_stAudioD0DigtalInfo;
StructAudioFreqParameter g_stAudioD0FreqParameter;
StructAudioDpCodingType g_stDpAudioD0CodingType;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
StructAudioFwTrackingInfo g_stHDMID0AudioFwTrackingInfo;
#endif

#if(_DP_SUPPORT == _ON)
StructAudioDpCapabilityInfo g_stAudioDpCapabilityInfo;
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
BYTE g_ucAudioGenInputPort;
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
StructAudioTtsInfo g_stAudioTtsInfo;
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
StructAudioGenFreqParameter g_stAudioGenFreq;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerAudioGetAudioDetected(BYTE ucInputPort);
EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
bit ScalerAudioSamplingFreqChange(void);
bit ScalerAudioLPCMCheckData(void);
bit ScalerAudioLPCMCheckChange(void);
void ScalerAudioLPCMDetectEnableProc(BYTE ucInputPort);
void ScalerAudioLPCMResetProc(BYTE ucInputPort);
void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort);
void ScalerAudioHbrModeControl(bit bOn, BYTE ucInputPort);
EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);
void ScalerAudioDACSoftReset(void);

#if(_HDMI_SUPPORT == _ON)
void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
bit ScalerAudioLPCMCheckInfo(void);
EnumSourceTypeDef ScalerAudioDigitalAudioSourceType(void);
#endif

#if(_DP_SUPPORT == _ON)
void ScalerAudioDPDigitalOutputProc(bit bEnable, BYTE ucInputPort);
bit ScalerAudioDPGetMuteProc(BYTE ucInputPort);
void ScalerAudioDpAudioEnable(bit bEnable, BYTE ucInputPort);
void ScalerAudioDpAudioEnable_EXINT0(bit bEnable, BYTE ucInputPort);
bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);
#endif

BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

#if(_SLEEP_AUDIO_SUPPORT == _ON)
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
#if(_EMBEDDED_DAC_SUPPORT == _ON)
bit ScalerAudioGetDpStandaloneAudioStatus(BYTE ucInputPort);
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
#endif
#endif

#if(_LINE_IN_SUPPORT == _ON)
void ScalerAudioADCInitial(void);
void ScalerAudioADCDACSoftReset(void);
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void ScalerAudioInternalAudioGenSwitch(bit bOn, BYTE ucInputPort, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
void ScalerAudioInternalAudioGenReset(BYTE ucInputPort);
void ScalerAudioSetInternalGenInputPort(BYTE ucInputPort);
BYTE ScalerAudioGetInternalGenInputPort(void);
#endif

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
void ScalerAudioTtsInitial(void);
void ScalerAudioTtsResetProc(void);
void ScalerAudioTtsRecoverProc(void);
bit ScalerAudioTtsPlaybackStableCheck(void);
bit ScalerAudioTtsGetPlayDoneStatus(void);
void ScalerAudioTtsPlayConfig(void);
void ScalerAudioTtsDvcGainControl(WORD usTtsVolume, WORD usAudioVolume);
void ScalerAudioTtsSpicReset(void);
void ScalerAudioTtsSpicReset_EXINT0(void);
void ScalerAudioTtsSpicReset_WDINT(void);
void ScalerAudioTtsSpicBlk0_EXINT0(void);
void ScalerAudioTtsSpicBlk1_EXINT0(void);
void ScalerAudioTtsBlk0BurstReadConfig_EXINT0(DWORD ulAddress, WORD usLength);
void ScalerAudioTtsBlk1BurstReadConfig_EXINT0(DWORD ulAddress, WORD usLength);
bit ScalerAudioTtsGetCommandData(StructAudioTtsSegment *pstAudioTtsSegment, BYTE ucSegmentSize);
void ScalerAudioTtsUpsamplingControl(bit bEn);
void ScalerAudioTtsUpsamplingControl_EXINT0(bit bEn);
void ScalerAudioTtsUpsamplingControl_WDINT(bit bEn);
void ScalerAudioTtsUpsamplingSetFrequency(void);
void ScalerAudioTtsPlayDone_EXINT0(void);
void ScalerAudioTtsSpicPingPong_EXINT0(void);
void ScalerAudioTtsPlayDoneDetect(bit bEn);
void ScalerAudioTtsPlayDoneDetect_EXINT0(bit bEn);
void ScalerAudioTtsDataPlay_WDINT(void);
void ScalerAudioTtsStartCommandData_WDINT(void);
void ScalerAudioTtsIntHandler_EXINT0(void);
void ScalerAudioTtsBurstReadStart_WDINT(void);
EnumAudioSpicStatus ScalerAudioTtsGetBurstStatus(void);
void ScalerAudioTtsBlk0BurstReadConfig_WDINT(DWORD ulAddress, WORD usLength);
void ScalerAudioTtsBlk1BurstReadConfig_WDINT(DWORD ulAddress, WORD usLength);
EnumAudioTtsDataWidth ScalerAudioTtsGetDataWidth(void);
bit ScalerAudioTtsGetPlaybackEvent(void);
void ScalerAudioTtsSetPlaybackEvent(bit bEn);
void ScalerAudioTtsSetTimerEvent(bit bEn);
void ScalerAudioTtsClearFlag(void);
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
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
        case _D1_INPUT_PORT:

            return ScalerAudioD0GetAudioDetected();

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
        case _D1_INPUT_PORT:

            enumSamplingFreqType = ScalerAudioD0SamplingFreqDetect();

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
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            return ScalerAudioD0SamplingFreqChange();

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
        case _AUDIO_FROM_D1_PORT:

            if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _TRUE)
            {
                if(ScalerGetBit(P2_CB_HDMI_SR, _BIT4) == 0x00)
                {
                    return _TRUE;
                }
                else
                {
                    return _FALSE;
                }
            }
            else
            {
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
            }

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
        case _AUDIO_FROM_D1_PORT:

            if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _FALSE)
            {
                if(GET_DP_D0_AUDIO_CODING_TYPE_CHANGE() == _TRUE)
                {
                    // Clear Change Flag
                    CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE();

                    return _TRUE;
                }
            }

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
            case _D1_INPUT_PORT:

                if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _FALSE)
                {
                    // Clear Change Flag
                    CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE();

                    // Clear Audio Coding Type Change Flag
                    ScalerSetBit(PB6_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

                    // Enable Audio Coding Type Change INT
                    ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT0, _BIT0);
                }

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
            case _D1_INPUT_PORT:

                if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _FALSE)
                {
                    // Disable Audio Coding Type Change INT
                    ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT0, 0x00);

                    // Reset Coding Type Detect
                    SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(_AUDIO_CODING_TYPE_NONE);
                }

                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Audio Watch Dog Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            ScalerAudioD0WatchDogProc(bOn);
            DebugMessageAudio("Audio D0: WatchDog", bOn);

            break;

        default:
            break;
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
            case _D1_INPUT_PORT:

                ScalerAudioD0HbrModeControl(bOn);
                DebugMessageAudio("Audio D0: HBR Mode Control", bOn);

                break;

            default:
                break;
        }
    }
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

        default:
            break;
    }

    return _NO_INPUT_PORT;
}

//--------------------------------------------------
// Description  : Audio Soft Reset for DAC Path
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSoftReset(void)
{
#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    // I2S/SPDIF DVC Soft Audio Enable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT3 | _BIT2), 0x00);
#endif

    // Soft Reset Enable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Mixer DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT7, _BIT7);

    // TTS DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT6, _BIT6);

    // Top DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT5, _BIT5);

    // DAC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT4, _BIT4);

    // DA Gain Double buffer
    ScalerSetBit(P6_D2_DA_GAIN_L, ~_BIT7, _BIT7);

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    // I2S/SPDIF DVC Soft Audio Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));
#endif
}
#if(_HDMI_SUPPORT == _ON)
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
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

#if(_HDMI_SUPPORT == _ON)
            ScalerAudioD0HdmiI2sSpdifChannelOutputSelect(enumAudioIisSpdifOutput);
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
        case _AUDIO_FROM_D1_PORT:

            ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x15, 1, pData, _NON_AUTOINC);

            if(((pData[0] & 0xF0) == 0x00) || ((pData[0] & 0xF0) == 0x10))
            {
                return _TRUE;
            }

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
        case _AUDIO_FROM_D0_PORT:
        case _AUDIO_FROM_D1_PORT:

            if(ScalerGetBit(PB_00_HD_DP_SEL, _BIT0) == _BIT0)
            {
                return _SOURCE_HDMI;
            }
            else
            {
                return _SOURCE_DP;
            }

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
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            ScalerAudioD0DPDigitalOutputProc(bEnable);
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check if Mute Audio
// Input Value  : ucInputPort
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerAudioDPGetMuteProc(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _FALSE)
            {
                return _TRUE;
            }

            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Enable DP audio FSM
// Input Value  : Enable or Disable, Input Port
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpAudioEnable(bit bEnable, BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, ((BYTE)bEnable) << 7);
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Enable DP audio FSM
// Input Value  : Enable or Disable, Input Port
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpAudioEnable_EXINT0(bit bEnable, BYTE ucInputPort) using 1
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:
        case _D2_INPUT_PORT:

            ScalerSetBit_EXINT(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, ((BYTE)bEnable) << 7);
            break;

        default:
            break;
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
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            bResult = GET_AUDIO_DP_D0_CAPABILITY_SWITCH();

            CLR_AUDIO_DP_D0_CAPABILITY_SWITCH();

            break;

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
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

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
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            // Get User Define DP Capability
            return GET_AUDIO_DP_D0_SUPPORT();

            break;

        default:

            break;
    }

    return _AUDIO_DP_DPCD_NOT_SUPPORT;
}
#endif

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
        case _D1_INPUT_PORT:

            return GET_D0_DIGITAL_AUDIO_SOURCE();

        default:
            break;
    }

    return _DIGITAL_AUDIO_SOURCE_NONE;
}

#if(_SLEEP_AUDIO_SUPPORT == _ON)
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Dp audio Status for Sleep Audio
// Input Value  : Input Port
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerAudioGetDpStandaloneAudioStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:

            return ((GET_REG_D0_MAC_SWITCH_TO_HDMI() == _FALSE) ? _TRUE : _FALSE);

        default:
            break;
    }

    return _FALSE;
}
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
#endif
#endif

#if(_LINE_IN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Audio ADC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioADCInitial(void)
{
    // Disable Clcok Gatting
    ScalerAudioClockGatting(_DISABLE);

    ////////// Digital //////////
    // Enable ADDA Loop, High Pass Filter and Set ADC ZCD Type
    ScalerSetBit(P6_B6_AD_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2), (_BIT6 | _BIT3));

    ////////// MBIAS //////////
    // Use RC Filter Bypass Mode & Enable Fast-Charge for Vref
    ScalerAudioFastChargeVref(_ON);

    // Power Enable MIBS/VREF/VRP/ADC/ADCFE Power
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

    ////////// ADC Line_in Mode //////////
    // ADCFE Un-mute for AIN
    ScalerSetBit(P6_B2_REG_ADC_CTRL2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

    ////////// Digital //////////
    // Digital Mute for ADC Un-mute / Set Boost Gain
    ScalerSetByte(P6_B7_AD_MUTE, 0x00);

    // Set AD Gail of L Ch
    ScalerSetBit(P6_B8_AD_GAIN_L, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _LINE_IN_BOOST_GAIN_DB);

    // Set AD Gail of R Ch
    ScalerSetBit(P6_B9_AD_GAIN_R, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _LINE_IN_BOOST_GAIN_DB);

    // Set Double Buffer
    ScalerSetBit(P6_B8_AD_GAIN_L, ~_BIT7, _BIT7);

    // Set Sampling Frequency "48kHz" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_48KHZ);

    // Set Channel Count "2 ch" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E3_AD_SPDIF_CS_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Enable I2S Output for ADC In
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Audio Soft Reset for ADC&DAC Path
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioADCDACSoftReset(void)
{
#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    // I2S/SPDIF DVC Soft Audio Enable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT3 | _BIT2), 0x00);
#else
    // I2S/SPDIF Audio Soft Audio Enable
    ScalerSetBit(P6_BB_SOFT_RESET_ADC, ~(_BIT6 | _BIT5), 0x00);
#endif

    // Soft Reset Enable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Soft Reset Enable
    ScalerSetBit(P6_BB_SOFT_RESET_ADC, ~_BIT7, 0x00);

    // ADC Soft Reset Disable
    ScalerSetBit(P6_BB_SOFT_RESET_ADC, ~_BIT7, _BIT7);

    // AD Gain / AD Mute Double buffer
    ScalerSetBit(P6_B8_AD_GAIN_L, ~_BIT7, _BIT7);

    // Mixer DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT7, _BIT7);

    // TTS DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT6, _BIT6);

    // Top DVC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT5, _BIT5);

    // DAC Soft Reset Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT4, _BIT4);

    // DA Gain Double buffer
    ScalerSetBit(P6_D2_DA_GAIN_L, ~_BIT7, _BIT7);

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    // I2S/SPDIF DVC Soft Audio Disable
    ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));
#else
    // I2S/SPDIF Audio Soft Audio Disable
    ScalerSetBit(P6_BB_SOFT_RESET_ADC, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
#endif
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
        case _D1_INPUT_PORT:

            ScalerAudioD0InternalAudioGenSwitch(bOn, enumAudioLeftRightChannelSelect);

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
        case _D1_INPUT_PORT:

            return ScalerAudioD0GetInternalAudioGenEnable();

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
        case _D1_INPUT_PORT:
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
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
//--------------------------------------------------
// Description  : TTS Initial Flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsInitial(void)
{
    // Disable Clcok Gatting
    ScalerAudioClockGatting(_DISABLE);

    // Disable Mixer INT & Clear Flag
    ScalerAudioTtsPlayDoneDetect(_DISABLE);

    // Soft Reset SPIC
    ScalerAudioTtsSpicReset();

    // Set Data Width
    ScalerSetBit(P8_61_BWR_CONTROL, ~_BIT7, ((BYTE)_AUDIO_TTS_CONTENT_BIT_FORMAT) << 7);

    // Enable Block 0/1 BW Int
    ScalerSetBit(P8_60_BWR_INT_CTRL, ~(_BIT2 | _BIT0), (_BIT2 | _BIT0));

    // Enable TTS Upsampling, Set PCM Generatoer, TTS FIFO Normal
    ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

#if(_AUDIO_TTS_CONTENT_BIT_FORMAT == _AUDIO_TTS_CONTENT_8_BIT)
    // Input Data 8 Bit Mode
    ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT3 | _BIT2 | _BIT1), 0x00);
#elif(_AUDIO_TTS_CONTENT_BIT_FORMAT == _AUDIO_TTS_CONTENT_16_BIT)
    // Input Data 16 Bit Mode
    ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT3 | _BIT2 | _BIT1), _BIT3);
#endif

    // PCM Gen Force Mode Enable(Force To 0)
    ScalerSetBit(P8_09_TTS_UP_SAMPLING_CTRL_5, ~(_BIT7 | _BIT6), _BIT7);

    // Other TTS Reset Flow To Add

    // =====================
    // Audio DVC Initial
    // =====================

    // Enable DVC function and counter
    ScalerSetBit(P8_90_DVC_EN, ~(_BIT7 | _BIT6), _BIT7);

    // Set DVC ZCD window size
    ScalerSetBit(P8_93_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));
    ScalerSetByte(P8_94_DVC_ZC_WIN_CTRL_1, LOBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));

    // Select value mode
    ScalerSetBit(P8_90_DVC_EN, ~_BIT4, _BIT4);

    // Set volume step size
    ScalerSetBit(P8_91_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_VOLUME_STEP_SIZE_VALUE));
    ScalerSetByte(P8_92_DVC_VA_LSB, LOBYTE(_VOLUME_STEP_SIZE_VALUE));


    // =====================
    // TTS DVC Initial
    // =====================

    // Enable DVC function and counter
    ScalerSetBit(P8_B0_DVC_EN, ~(_BIT7 | _BIT6), _BIT7);

    // Set DVC ZCD window size
    ScalerSetBit(P8_B3_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));
    ScalerSetByte(P8_B4_DVC_ZC_WIN_CTRL_1, LOBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));

    // Select value mode
    ScalerSetBit(P8_B0_DVC_EN, ~_BIT4, _BIT4);

    // Set volume step size
    ScalerSetBit(P8_B1_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_VOLUME_STEP_SIZE_VALUE));
    ScalerSetByte(P8_B2_DVC_VA_LSB, LOBYTE(_VOLUME_STEP_SIZE_VALUE));

    // Mute TTS Volume
    ScalerAudioTtsDvcGainControl(_DIGITAL_VOLUME_MIN, _DIGITAL_VOLUME_MAX);
}

//--------------------------------------------------
// Description  : TTS Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsResetProc(void)
{
    // =====================
    // Reset Audio DVC
    // =====================

    // Reset DVC Counter
    ScalerSetBit(P8_90_DVC_EN, ~_BIT6, _BIT6);

    // At Least Delay 2 Cycle of 1 / 256 * FS (= 32KHz)
    DELAY_5US();

    // Enable DVC Counter
    ScalerSetBit(P8_90_DVC_EN, ~_BIT6, 0x00);


    // =====================
    // Reset TTS DVC
    // =====================

    // Reset DVC Counter
    ScalerSetBit(P8_B0_DVC_EN, ~_BIT6, _BIT6);

    // At Least Delay 2 Cycle of 1 / 256 * FS (= 32KHz)
    DELAY_5US();

    // Enable DVC Counter
    ScalerSetBit(P8_B0_DVC_EN, ~_BIT6, 0x00);
}

//--------------------------------------------------
// Description  : TTS Recover Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsRecoverProc(void)
{
    // Volume Recover
    ScalerAudioTtsDvcGainControl(_DIGITAL_VOLUME_MIN, _DIGITAL_VOLUME_MAX);

    // Path Recover
    // Reserved for non-LPCM audio path
}

//--------------------------------------------------
// Description  : Check TTS FIFO Stable or Not
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerAudioTtsPlaybackStableCheck(void)
{
    // Check TTS Upsampling FIFO overflow and underflow
    if(ScalerGetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, (_BIT2 | _BIT1)) != 0x00)
    {
        DebugMessageAudio("False : TTS Audio FIFO", ScalerGetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, (_BIT2 | _BIT1)));

        // Clear TTS FIFO overflow and underflow status
        ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // Set Error Flag
        SET_TTS_PLAYBACK_ERROR();
    }

    return GET_TTS_PLAYBACK_ERROR();
}

//--------------------------------------------------
// Description  : Check TTS Play Done or Not
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerAudioTtsGetPlayDoneStatus(void)
{
    return GET_TTS_PLAY_DONE_FLAG();
}

//--------------------------------------------------
// Description  : TTS Config for Data Play
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsPlayConfig(void)
{
    // =================
    // Upsampling Config
    // =================

    // Set Upsampling Frequency
    ScalerAudioTtsUpsamplingSetFrequency();


    // =================
    // SPIC Config
    // =================

    // Config in WD Event


    // =================
    // Event Active
    // =================

    // Set WD Event
    ScalerAudioTtsSetTimerEvent(_ENABLE);
}

//--------------------------------------------------
// Description  : TTS DVC Gain Control
// Input Value  : usTtsVolume   --> 0x0000 ~ 0x3FFF
//                usAudioVolume --> 0x0000 ~ 0x3FFF
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsDvcGainControl(WORD usTtsVolume, WORD usAudioVolume)
{
    WORD usZCDtime = 0;
    DWORD ulZCDtime_temp = 0;
    EnumAudioSamplingFreqPacket enumSamplingFreqPacket = _AUDIO_FREQ_PACKET_NO_AUDIO;

    // =====================
    // Set Audio Frequency
    // =====================

    // Get Sampling Rate
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetInputSource() == _LINE_IN_AUDIO)
    {
        enumSamplingFreqPacket = _AUDIO_FREQ_PACKET_48K;
    }
    else
#endif
    {
        enumSamplingFreqPacket = ScalerAudioSamplingFreqDetect(ScalerAudioGetDigitalAudioPortMapping());
    }


    // =====================
    // Audio ZCD Timeout
    // =====================

    // Get Current Volume
    usZCDtime = ((WORD)(ScalerGetByte(P8_95_DVC_GAIN_MSB) & 0x3F) << 8) | ((WORD)ScalerGetByte(P8_96_DVC_GAIN_LSB));

    usZCDtime = (usZCDtime > usAudioVolume) ? (usZCDtime - usAudioVolume) : (usAudioVolume - usZCDtime);

    usZCDtime = usZCDtime / _VOLUME_STEP_SIZE_VALUE + 1;

    // Calculate samples of ZCD timeout
    ulZCDtime_temp = (DWORD)enumSamplingFreqPacket * _DVC_VOLUME_ADJUST_TIMER / usZCDtime;

    // Avoid Overflow
    if(ulZCDtime_temp > 0x0FFF)
    {
        usZCDtime = 0x0FFF;
    }
    else
    {
        usZCDtime = (WORD)ulZCDtime_temp;
    }

    // Set DVC ZCD window size
    ScalerSetBit(P8_93_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usZCDtime));
    ScalerSetByte(P8_94_DVC_ZC_WIN_CTRL_1, LOBYTE(usZCDtime));


    // =====================
    // Audio Volume Control
    // =====================

    // DVC gain MSB
    ScalerSetBit(P8_95_DVC_GAIN_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usAudioVolume));

    // DVC gain LSB  (double buffer)
    ScalerSetByte(P8_96_DVC_GAIN_LSB, LOBYTE(usAudioVolume));

    // Set Double Buffer
    ScalerSetBit(P8_97_DVC_GAIN_READ_MSB, ~_BIT6, _BIT6);


    // =====================
    // TTS ZCD Timeout
    // =====================

    // Get Current Volume
    usZCDtime = ((WORD)(ScalerGetByte(P8_B5_DVC_GAIN_MSB) & 0x3F) << 8) | ((WORD)ScalerGetByte(P8_B6_DVC_GAIN_LSB));

    usZCDtime = (usZCDtime > usTtsVolume) ? (usZCDtime - usTtsVolume) : (usTtsVolume - usZCDtime);

    usZCDtime = usZCDtime / _VOLUME_STEP_SIZE_VALUE + 1;

    // Calculate samples of ZCD timeout
    ulZCDtime_temp = (DWORD)enumSamplingFreqPacket * _DVC_VOLUME_ADJUST_TIMER / usZCDtime;

    // Avoid Overflow
    if(ulZCDtime_temp > 0x0FFF)
    {
        usZCDtime = 0x0FFF;
    }
    else
    {
        usZCDtime = (WORD)ulZCDtime_temp;
    }

    // Set DVC ZCD window size
    ScalerSetBit(P8_B3_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usZCDtime));
    ScalerSetByte(P8_B4_DVC_ZC_WIN_CTRL_1, LOBYTE(usZCDtime));


    // =====================
    // TTS Volume Control
    // =====================

    // DVC gain MSB
    ScalerSetBit(P8_B5_DVC_GAIN_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usTtsVolume));

    // DVC gain LSB  (double buffer)
    ScalerSetByte(P8_B6_DVC_GAIN_LSB, LOBYTE(usTtsVolume));

    // Set Double Buffer
    ScalerSetBit(P8_B7_DVC_GAIN_READ_MSB, ~_BIT6, _BIT6);
}

//--------------------------------------------------
// Description  : TTS SPIC Reset Flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicReset(void)
{
    // TTS SPIC Burst data reset
    ScalerSetBit(P8_60_BWR_INT_CTRL, ~_BIT7, _BIT7);

    // For Delay 100 us
    DELAY_XUS(100);

    // Clear to 0
    ScalerSetBit(P8_60_BWR_INT_CTRL, ~_BIT7, 0x00);

    // clr current segment data
    CLR_TTS_DATA_SEGMENT_CURRENT();
}

//--------------------------------------------------
// Description  : TTS SPIC Reset Flow for Int
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicReset_EXINT0(void) using 1
{
    // TTS SPIC Burst data reset
    ScalerSetBit_EXINT(P8_60_BWR_INT_CTRL, ~_BIT7, _BIT7);

    // For Delay 100 us
    DELAY_XUS_EXINT(100);

    // Clear to 0
    ScalerSetBit_EXINT(P8_60_BWR_INT_CTRL, ~_BIT7, 0x00);

    CLR_TTS_DATA_SEGMENT_CURRENT();
}

//--------------------------------------------------
// Description  : TTS SPIC Reset Flow for Int
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicReset_WDINT(void) using 3
{
    // TTS SPIC Burst data reset
    ScalerSetBit_EXINT(P8_60_BWR_INT_CTRL, ~_BIT7, _BIT7);

    // For Delay 100 us
    DELAY_XUS_EXINT(100);

    // Clear to 0
    ScalerSetBit_EXINT(P8_60_BWR_INT_CTRL, ~_BIT7, 0x00);

    CLR_TTS_DATA_SEGMENT_CURRENT();
}
//--------------------------------------------------
// Description  : Audio TTS SPIC blk0 Config for Int
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicBlk0_EXINT0(void) using 1
{
    // increase block 0 current segment data index
    INC_TTS_DATA_SEGMENT_CURRENT();

    ScalerAudioTtsBlk0BurstReadConfig_EXINT0(GET_TTS_DATA_SEGMENT_ADDRESS(GET_TTS_DATA_SEGMENT_CURRENT()), GET_TTS_DATA_SEGMENT_LENGTH(GET_TTS_DATA_SEGMENT_CURRENT()));
}
//--------------------------------------------------
// Description  : Audio TTS SPIC blk1 Config for Int
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicBlk1_EXINT0(void) using 1
{
    // increase block 0 current segment data index
    INC_TTS_DATA_SEGMENT_CURRENT();

    ScalerAudioTtsBlk1BurstReadConfig_EXINT0(GET_TTS_DATA_SEGMENT_ADDRESS(GET_TTS_DATA_SEGMENT_CURRENT()), GET_TTS_DATA_SEGMENT_LENGTH(GET_TTS_DATA_SEGMENT_CURRENT()));
}

//--------------------------------------------------
// Description  : Audio TTS SPIC blk0 read for Int
// Input Value  : ulAddress -- > Data Address
//                usLength -- > Data Length
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsBlk0BurstReadConfig_EXINT0(DWORD ulAddress, WORD usLength) using 1
{
    // Set BW Start Address
    ScalerSetByte_EXINT(P8_62_BLK0_BWR_ADR_4TH, HIBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_63_BLK0_BWR_ADR_H, LOBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_64_BLK0_BWR_ADR_M, HIBYTE(LOWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_65_BLK0_BWR_ADR_L, LOBYTE(LOWORD(ulAddress)));

    // Set BW Length
    ScalerSetByte_EXINT(P8_66_BLK0_BWR_COUNT_H, HIBYTE(usLength));
    ScalerSetByte_EXINT(P8_67_BLK0_BWR_COUNT_L, LOBYTE(usLength));

    // Start BW
    ScalerSetBit_EXINT(P8_61_BWR_CONTROL, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Audio TTS SPIC blk1 read for Int
// Input Value  : ulAddress -- > Data Address
//                usLength -- > Data Length
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsBlk1BurstReadConfig_EXINT0(DWORD ulAddress, WORD usLength) using 1
{
    // Set BW Start Address
    ScalerSetByte_EXINT(P8_68_BLK1_BWR_ADR_4TH, HIBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_69_BLK1_BWR_ADR_H, LOBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_6A_BLK1_BWR_ADR_M, HIBYTE(LOWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_6B_BLK1_BWR_ADR_L, LOBYTE(LOWORD(ulAddress)));

    // Set BW Length
    ScalerSetByte_EXINT(P8_6C_BLK1_BWR_COUNT_H, HIBYTE(usLength));
    ScalerSetByte_EXINT(P8_6D_BLK1_BWR_COUNT_L, LOBYTE(usLength));

    // Start BW
    ScalerSetBit_EXINT(P8_61_BWR_CONTROL, ~_BIT1, _BIT1);
}

//--------------------------------------------------
// Description  : TTS Upsampling Control
// Input Value  : *pstAudioTtsSegment
//                ucSegmentSize
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerAudioTtsGetCommandData(StructAudioTtsSegment *pstAudioTtsSegment, BYTE ucSegmentSize)
{
    BYTE ucCount = 0;

    DebugMessageAudio("[TTS] Set Command Data", ucSegmentSize);

    // Clip the max segment size
    ucSegmentSize = ((ucSegmentSize > _AUDIO_TTS_DATA_SEGMENT_SIZE) ? _AUDIO_TTS_DATA_SEGMENT_SIZE : ucSegmentSize);

    for(ucCount = 0; ((ucCount < ucSegmentSize) && (pstAudioTtsSegment->usDataLength != 0x000000)); ucCount++)
    {
        // Set TTS Data Address & Length
        SET_TTS_DATA_SEGMENT_ADDRESS(ucCount, pstAudioTtsSegment->ulDataAddress);
        SET_TTS_DATA_SEGMENT_LENGTH(ucCount, pstAudioTtsSegment->usDataLength);

        pstAudioTtsSegment++;

        DebugMessageAudio("--------------------------------", ucCount);
        DebugMessageAudio("    - Address", GET_TTS_DATA_SEGMENT_ADDRESS(ucCount));
        DebugMessageAudio("    - Length", GET_TTS_DATA_SEGMENT_LENGTH(ucCount));
    }

    // Set Max TTS Data Number
    SET_TTS_DATA_SEGMENT_TARGET(ucCount);
    CLR_TTS_DATA_SEGMENT_CURRENT();

    DebugMessageAudio("--------------------------------", ucCount);
    DebugMessageAudio("    => Total Data", GET_TTS_DATA_SEGMENT_TARGET());
    DebugMessageAudio("--------------------------------", ucCount);

    return _TRUE;
}

//--------------------------------------------------
// Description  : TTS Upsampling Control
// Input Value  : _ENABLE/_DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsUpsamplingControl(bit bEn)
{
    if(bEn == _ENABLE)
    {
        // Enable TTS Upsampling, Set PCM Generatoer, TTS FIFO Normal
        ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        // Enable TTS FIFO
        ScalerSetBit(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);
    }
    else
    {
        // Disable TTS FIFO, Prevent SPI Controller Write Data In.
        ScalerSetBit(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), 0x00);

        // Reset PCM Generatoer, TTS FIFO
        ScalerSetBit(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    }
}

//--------------------------------------------------
// Description  : TTS Upsampling Control
// Input Value  : _ENABLE/_DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsUpsamplingControl_EXINT0(bit bEn) using 1
{
    if(bEn == _ENABLE)
    {
        // Enable TTS Upsampling, Set PCM Generatoer, TTS FIFO Normal
        ScalerSetBit_EXINT(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        // Enable TTS FIFO
        ScalerSetBit_EXINT(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);
    }
    else
    {
        // Disable TTS FIFO, Prevent SPI Controller Write Data In.
        ScalerSetBit_EXINT(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), 0x00);

        // Reset PCM Generatoer, TTS FIFO
        ScalerSetBit_EXINT(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    }
}

//--------------------------------------------------
// Description  : TTS Upsampling Control
// Input Value  : _ENABLE/_DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsUpsamplingControl_WDINT(bit bEn) using 3
{
    if(bEn == _ENABLE)
    {
        // Enable TTS Upsampling, Set PCM Generatoer, TTS FIFO Normal
        ScalerSetBit_EXINT(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        // Enable TTS FIFO
        ScalerSetBit_EXINT(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), _BIT1);
    }
    else
    {
        // Disable TTS FIFO, Prevent SPI Controller Write Data In.
        ScalerSetBit_EXINT(P8_02_TTS_UP_SAMPLING_CTRL_3, ~(_BIT3 | _BIT2 | _BIT1), 0x00);

        // Reset PCM Generatoer, TTS FIFO
        ScalerSetBit_EXINT(P8_00_TTS_UP_SAMPLING_CTRL_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    }
}

//--------------------------------------------------
// Description  : Set TTS Upsampling Data Frequency
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsUpsamplingSetFrequency(void)
{
    EnumAudioSamplingFreqType enumAudioFreq = GET_AUDIO_D0_SAMPLING_FREQ();
    if(enumAudioFreq == _AUDIO_FREQ_NO_AUDIO)
    {
        enumAudioFreq = GET_D0_SAMPLING_FREQ_USER_DEFINE();
    }

    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x04);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x08);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x01);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0x3F);

            break;

        case _AUDIO_FREQ_44_1K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xE7);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x09);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x05);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xCE);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x13);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x01);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0x88);

            break;

        case _AUDIO_FREQ_48K:
        default:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xAA);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0xAA);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x05);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x55);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x55);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x01);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0xDF);

            break;

        case _AUDIO_FREQ_64K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x04);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x02);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0x7F);

            break;

        case _AUDIO_FREQ_88_2K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x01);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x73);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x84);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xE7);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x09);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x03);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0x71);

            break;

        case _AUDIO_FREQ_96K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x01);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x55);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x55);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xAA);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0xAA);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x03);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0xBF);

            break;

        case _AUDIO_FREQ_128K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x01);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x02);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x00);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x00);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x04);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0xFF);

            break;

        case _AUDIO_FREQ_176_4K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x00);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xB9);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0xC2);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x01);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x73);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x84);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x06);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0xE3);

            break;

        case _AUDIO_FREQ_192K:
            // Set TTS up sampling Factor By Frequency
#if(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_8_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x00);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0xAA);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0xAA);
#elif(_AUDIO_TTS_CONTENT_FREQUENCY == _AUDIO_TTS_CONTENT_16_KHZ)
            ScalerSetByte(P8_06_TTS_SCALE_FACTOR_1, 0x01);
            ScalerSetByte(P8_07_TTS_SCALE_FACTOR_2, 0x55);
            ScalerSetByte(P8_08_TTS_SCALE_FACTOR_3, 0x55);
#endif

            // Set PCM Force Gen Sample Counter By Frequency(100ms)
            ScalerSetByte(P8_0A_TTS_UP_SAMPLING_CTRL_6, 0x07);
            ScalerSetByte(P8_0B_TTS_UP_SAMPLING_CTRL_7, 0x7F);

            break;
    }
}

//--------------------------------------------------
// Description  : TTS Play Done INT Proccess
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsPlayDone_EXINT0(void) using 1
{
    // If TTS IRQ Trigger
    if((ScalerGetBit_EXINT(P8_F0_TTS_CTRL_1, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(P8_F0_TTS_CTRL_1, _BIT6) == _BIT6))
    {
        // Disable INT & Clear Flag
        ScalerAudioTtsPlayDoneDetect_EXINT0(_DISABLE);

        // Disable Upsampling
        ScalerAudioTtsUpsamplingControl_EXINT0(_OFF);

        // Reset SPIC
        ScalerAudioTtsSpicReset_EXINT0();

        // Set Play Done Flag
        SET_TTS_PLAY_DONE_FLAG();
    }
}

//--------------------------------------------------
// Description  : TTS SPIC Ping-Pong INT Proccess
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSpicPingPong_EXINT0(void) using 1
{
    // Last Segment Judgment
    if(GET_TTS_DATA_SEGMENT_CURRENT() >= GET_TTS_DATA_SEGMENT_TARGET())
    {
        // Enable TTS_Play_Done INT
        ScalerAudioTtsPlayDoneDetect_EXINT0(_ENABLE);
    }
    else
    {
        // Disable INT & Clear Flag
        ScalerAudioTtsPlayDoneDetect_EXINT0(_DISABLE);

        // Ping-Pong Operation
        if((ScalerGetBit_EXINT(P8_60_BWR_INT_CTRL, _BIT0) == _BIT0) && (ScalerGetBit_EXINT(P8_60_BWR_INT_CTRL, _BIT1) == _BIT1))
        {
            // clear Block 0 irq flag
            ScalerSetByte_EXINT(P8_60_BWR_INT_CTRL, 0x07);

            ScalerAudioTtsSpicBlk0_EXINT0();
        }

        if((ScalerGetBit_EXINT(P8_60_BWR_INT_CTRL, _BIT2) == _BIT2) && (ScalerGetBit_EXINT(P8_60_BWR_INT_CTRL, _BIT3) == _BIT3))
        {
            // clear Block 1 irq flag
            ScalerSetByte_EXINT(P8_60_BWR_INT_CTRL, 0x0D);

            ScalerAudioTtsSpicBlk1_EXINT0();
        }
    }
}

//--------------------------------------------------
// Description  : TTS Play Done Detect Control
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsPlayDoneDetect(bit bEn)
{
    if(bEn == _ENABLE)
    {
        // Enable INT
        ScalerSetBit(P8_F0_TTS_CTRL_1, ~(_BIT7 | _BIT6), _BIT7);
    }
    else
    {
        // Disable INT & Clear Flag
        ScalerSetBit(P8_F0_TTS_CTRL_1, ~(_BIT7 | _BIT6), _BIT6);
    }
}

//--------------------------------------------------
// Description  : TTS Play Done Detect Control
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsPlayDoneDetect_EXINT0(bit bEn) using 1
{
    if(bEn == _ENABLE)
    {
        // Enable INT
        ScalerSetBit_EXINT(P8_F0_TTS_CTRL_1, ~(_BIT7 | _BIT6), _BIT7);
    }
    else
    {
        // Disable INT & Clear Flag
        ScalerSetBit_EXINT(P8_F0_TTS_CTRL_1, ~(_BIT7 | _BIT6), _BIT6);
    }
}

//--------------------------------------------------
// Description  : TTS WD Event Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsDataPlay_WDINT(void) using 3
{
    // Enable Upsampling
    ScalerAudioTtsUpsamplingControl_WDINT(_ON);

    // Ready to Play Text
    ScalerAudioTtsStartCommandData_WDINT();
}

//--------------------------------------------------
// Description  : TTS Data Start to Play
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsStartCommandData_WDINT(void) using 3
{
    // SPIC get data & Enable ping-pong INT
    ScalerAudioTtsBurstReadStart_WDINT();
}

//--------------------------------------------------
// Description  : TTS INT Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsIntHandler_EXINT0(void) using 1
{
    ScalerAudioTtsPlayDone_EXINT0();

    ScalerAudioTtsSpicPingPong_EXINT0();
}

//--------------------------------------------------
// Description  : TTS SPIC burst read Start
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsBurstReadStart_WDINT(void) using 3
{
    // Get Total segment count
    BYTE ucSegmentCnt = GET_TTS_DATA_SEGMENT_TARGET();

    // reset SPIC
    ScalerAudioTtsSpicReset_WDINT();

    if(ucSegmentCnt < 2)
    {
        // use block 0
        ScalerAudioTtsBlk0BurstReadConfig_WDINT(GET_TTS_DATA_SEGMENT_ADDRESS(0), GET_TTS_DATA_SEGMENT_LENGTH(0));
    }
    else
    {
        // use block 0/1 ping pang
        ScalerAudioTtsBlk0BurstReadConfig_WDINT(GET_TTS_DATA_SEGMENT_ADDRESS(0), GET_TTS_DATA_SEGMENT_LENGTH(0));
        ScalerAudioTtsBlk1BurstReadConfig_WDINT(GET_TTS_DATA_SEGMENT_ADDRESS(1), GET_TTS_DATA_SEGMENT_LENGTH(1));
    }

    // increase block 0 current segment data index
    INC_TTS_DATA_SEGMENT_CURRENT();
}

//--------------------------------------------------
// Description  : Auido TTS Get burst status
// Input Value  : None
// Output Value : SPIC BW status
//--------------------------------------------------
EnumAudioSpicStatus ScalerAudioTtsGetBurstStatus(void)
{
    if((GET_TTS_DATA_SEGMENT_CURRENT() + 1) == GET_TTS_DATA_SEGMENT_TARGET())
    {
        return _AUDIO_TTS_SPIC_IDLE;
    }
    else
    {
        return _AUDIO_TTS_SPIC_BUSY;
    }
}

//--------------------------------------------------
// Description  : Audio TTS SPIC blk0 read
// Input Value  : ulAddress -- > Data Address
//                usLength -- > Data Length
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsBlk0BurstReadConfig_WDINT(DWORD ulAddress, WORD usLength) using 3
{
    // Set BW Start Address
    ScalerSetByte_EXINT(P8_62_BLK0_BWR_ADR_4TH, HIBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_63_BLK0_BWR_ADR_H, LOBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_64_BLK0_BWR_ADR_M, HIBYTE(LOWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_65_BLK0_BWR_ADR_L, LOBYTE(LOWORD(ulAddress)));

    // Set BW Length
    ScalerSetByte_EXINT(P8_66_BLK0_BWR_COUNT_H, HIBYTE(usLength));
    ScalerSetByte_EXINT(P8_67_BLK0_BWR_COUNT_L, LOBYTE(usLength));

    // Start BW
    ScalerSetBit_EXINT(P8_61_BWR_CONTROL, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Audio TTS SPIC blk1 read
// Input Value  : ulAddress -- > Data Address
//                usLength -- > Data Length
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsBlk1BurstReadConfig_WDINT(DWORD ulAddress, WORD usLength) using 3
{
    // Set BW Start Address
    ScalerSetByte_EXINT(P8_68_BLK1_BWR_ADR_4TH, HIBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_69_BLK1_BWR_ADR_H, LOBYTE(HIWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_6A_BLK1_BWR_ADR_M, HIBYTE(LOWORD(ulAddress)));
    ScalerSetByte_EXINT(P8_6B_BLK1_BWR_ADR_L, LOBYTE(LOWORD(ulAddress)));

    // Set BW Length
    ScalerSetByte_EXINT(P8_6C_BLK1_BWR_COUNT_H, HIBYTE(usLength));
    ScalerSetByte_EXINT(P8_6D_BLK1_BWR_COUNT_L, LOBYTE(usLength));

    // Start BW
    ScalerSetBit_EXINT(P8_61_BWR_CONTROL, ~_BIT1, _BIT1);
}

//--------------------------------------------------
// Description  : Get TTS SPIC Burst Data Width
// Input Value  : None
// Output Value : _TTS_DATA_8BIT / _TTS_DATA_16BIT
//--------------------------------------------------
EnumAudioTtsDataWidth ScalerAudioTtsGetDataWidth(void)
{
    // Get Data Width Info
    if(ScalerGetBit(P8_61_BWR_CONTROL, _BIT7) == _BIT7)
    {
        return _AUDIO_TTS_CONTENT_16_BIT;
    }
    else
    {
        return _AUDIO_TTS_CONTENT_8_BIT;
    }
}

//--------------------------------------------------
// Description  : Check Audio TTS Playback Event
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerAudioTtsGetPlaybackEvent(void)
{
    return GET_TTS_PLAYBACK_EVENT_ACTIVE();
}

//--------------------------------------------------
// Description  : Set Audio TTS Playback Event
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSetPlaybackEvent(bit bEn)
{
    if(bEn == _ENABLE)
    {
        SET_TTS_PLAYBACK_EVENT_ACTIVE();
    }
    else
    {
        CLR_TTS_PLAYBACK_EVENT_ACTIVE();
    }
}

//--------------------------------------------------
// Description  : Set Audio TTS Timer Event
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsSetTimerEvent(bit bEn)
{
    if(bEn == _ENABLE)
    {
        ScalerTimerWDActivateTimerEvent(10, _SCALER_WD_TIMER_EVENT_AUDIO_TTS_PLAYBACK_PROC);
    }
    else
    {
        ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_AUDIO_TTS_PLAYBACK_PROC);
    }
}

//--------------------------------------------------
// Description  : Set Audio TTS Timer Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioTtsClearFlag(void)
{
    // Clear TTS_Play_Done Flag
    CLR_TTS_PLAY_DONE_FLAG();

    // Clear Error Flag
    CLR_TTS_PLAYBACK_ERROR();
}
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#endif // End of #if(_AUDIO_SUPPORT == _ON)

