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
// ID Code      : RL6492_Series_Audio.c No.0000
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
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void ScalerAudioInternalAudioGenSwitch(bit bOn, BYTE ucInputPort, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
void ScalerAudioInternalAudioGenReset(BYTE ucInputPort);
void ScalerAudioSetInternalGenInputPort(BYTE ucInputPort);
BYTE ScalerAudioGetInternalGenInputPort(void);
#endif

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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
        case _AUDIO_FROM_D2_PORT:

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
        case _AUDIO_FROM_D2_PORT:

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
            case _D2_INPUT_PORT:

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
            case _D2_INPUT_PORT:

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
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) != _AUDIO_FROM_ADC_PORT)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:
            case _D1_INPUT_PORT:
            case _D2_INPUT_PORT:

                ScalerAudioD0WatchDogProc(bOn);
                DebugMessageAudio("Audio D0: WatchDog", bOn);

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
            case _D1_INPUT_PORT:
            case _D2_INPUT_PORT:

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

        case _AUDIO_FROM_D2_PORT:

            return _D2_INPUT_PORT;

        default:
            break;
    }

    return _NO_INPUT_PORT;
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
        case _D2_INPUT_PORT:

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
        case _AUDIO_FROM_D2_PORT:

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
        case _AUDIO_FROM_D2_PORT:

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
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) != _AUDIO_FROM_ADC_PORT)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:
            case _D1_INPUT_PORT:
            case _D2_INPUT_PORT:

                ScalerAudioD0DPDigitalOutputProc(bEnable);
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Check if Mute Audio
// Input Value  : ucInputPort
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerAudioDPGetMuteProc(BYTE ucInputPort)
{
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) == _AUDIO_FROM_ADC_PORT)
    {
        return _FALSE;
    }
#endif

    if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _TRUE)
    {
        return _FALSE;
    }

    switch(ucInputPort)
    {
#if(_D0_DP_EXIST == _ON)
        case _D0_INPUT_PORT:

            if(GET_REG_DP_RX0_MAC_ASSIGNED() == _TRUE)
            {
                return _TRUE;
            }

            break;
#endif

#if(_D1_DP_EXIST == _ON)
        case _D1_INPUT_PORT:
        case _D2_INPUT_PORT:

            if(GET_REG_DP_RX1_MAC_ASSIGNED() == _TRUE)
            {
                return _TRUE;
            }

            break;
#endif

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
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetDigitalAudioPort(_AUDIO_DAC_OUT) != _AUDIO_FROM_ADC_PORT)
#endif
    {
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:
            case _D1_INPUT_PORT:
            case _D2_INPUT_PORT:

                ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, ((BYTE)bEnable) << 7);
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Enable DP audio FSM
// Input Value  : Enable or Disable, Input Port
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpAudioEnable_EXINT0(bit bEnable, BYTE ucInputPort) using 1
{
#if(_LINE_IN_SUPPORT == _ON)
    if(ScalerAudioGetDigitalAudioPort_EXINT0(_AUDIO_DAC_OUT) != _AUDIO_FROM_ADC_PORT)
#endif
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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
    // Enable ADDA Loop, High Pass Filter and Set ADC ZCD Type
    ScalerSetBit(P6_B4_AD_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2), (_BIT6 | _BIT3));

    // Power On ADC
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Power On Mbias
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_LINE_IN_AA_PATH_SUPPORT == _ON)
    // Power On Input Buffer
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT2, _BIT2);
#endif

    // Adj ADC OP Noise Cancellation Clock and Enable ADC Op Offset Cancellation
    ScalerSetBit(P6_B2_REG_ADC_CTRL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));

    // Set ADC Front End Gain(-5dB)
    ScalerSetByte(P6_B3_REG_AFE_GAIN, 0x77);

    // Bypass Input Buffer
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~_BIT0, _BIT0);

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
        case _D1_INPUT_PORT:
        case _D2_INPUT_PORT:

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
        case _D2_INPUT_PORT:

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
#endif // End of #if(_AUDIO_SUPPORT == _ON)

