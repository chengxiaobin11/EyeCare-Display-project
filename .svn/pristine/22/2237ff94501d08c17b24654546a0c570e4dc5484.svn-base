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
// ID Code      : RL6851_Series_ScalerAudio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_AUDIO__

#include "ScalerFunctionInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if((_DAC_SPEAKER_OUTPUT_SUPPORT == _ON) && (_DAC_HP_OUTPUT_SUPPORT == _ON))
#if(((_DAC_SPEAKER_OUTPUT_SWAP == _OFF) && (_DAC_HP_OUTPUT_SWAP == _ON)) || ((_DAC_SPEAKER_OUTPUT_SWAP == _ON) && (_DAC_HP_OUTPUT_SWAP == _OFF)))
#warning "NOTE: When headphone and speaker need to output at the same time, not support L/R channel swap separately for either output port!!!"
#endif
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Audio Mute Table
//--------------------------------------------------
BYTE code tADDA_ALL_MUTE[] =
{
    4, _NON_AUTOINC, 0x9F, 0x06,
    19, _AUTOINC, 0xB0, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    19, _AUTOINC, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x7E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    19, _AUTOINC, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    19, _AUTOINC, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

#if(_EMBEDDED_DAC_SUPPORT == _ON)
StructAudioDACInfo g_stAudioDACInfo;
#endif

bit g_bAudioDVCMuteCtrlStatus;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerAudioInitial(void);
void ScalerAudioClockGatting(bit bEnable);
void ScalerAudioDigitalAdjustVolume(WORD usVolume);
void ScalerAudioMuteProc(bit bMute, WORD usVolume);
void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume);
void ScalerAudioDisable(void);
void ScalerAudioInputPortSwitch(EnumAudioInputPort enumAudioInput);
BYTE ScalerAudioGetDigitalAudioPort(EnumAudioOutputType enumAudioOutput);
EnumAudioSamplingFreqPacket ScalerAudioGetSamplingFreqPacket(EnumAudioSamplingFreqType enumSamplingFreqType);
DWORD ScalerAudioGetUserSamplingFreqNFCode(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq);
BYTE ScalerAudioGetUserSamplingFreqSCode(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq);
DWORD ScalerAudioGetUserSamplingFreqNFCode_EXINT0(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq);
BYTE ScalerAudioGetUserSamplingFreqSCode_EXINT0(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq);

#if((_EMBEDDED_DAC_SUPPORT == _ON) || (_LINE_IN_SUPPORT == _ON))
void ScalerAudioFastChargeVref(bit bReady);
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void ScalerAudioSetUserDefineAudioGenFrequency(EnumAudioSamplingFreqType enumAudioFreq);
#endif

#if(_HDMI_SUPPORT == _ON)
BYTE ScalerAudioChannelOutputSel(BYTE ucCa);
#endif

#if(_LINE_IN_SUPPORT == _ON)
#if(_HW_DIGITAL_PORT_COMBO_PHY_TYPE != _DIGITAL_PORT_COMBO_PHY_NONE)

EnumAudioInputSource ScalerAudioGetInputSource_EXINT0(void);
#endif

EnumAudioInputSource ScalerAudioGetInputSource(void);
void ScalerAudioSetADCAudioPLL(void);
void ScalerAudioSetAudioADCPLLOffProc(void);
void ScalerAudioSetAudioADCPLLOnProc(void);
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
void ScalerAudioDACInitial(void);
void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput);
void ScalerAudioDACSetState(EnumAudioDACState enumTargetState);
EnumAudioDACState ScalerAudioDACGetState(void);
bit ScalerAudioDACGetStateChange(void);
void ScalerAudioDACClrStateChange(void);
void ScalerAudioDACSetVcmReady(bit bReady);
void ScalerAudioDACNormalToDepop(void);
void ScalerAudioDACDepopToNormal(void);
void ScalerAudioDACOutputEnable(void);
EnumAudioDACOutput ScalerAudioDACGetOutput(void);
void ScalerAudioDACSetOutputGain(EnumAudioDACOutput enumOutputType, EnumAudioDacOutputGain enumOutputGain);
#endif

void ScalerAudioDVCInitial(void);
void ScalerAudioDVCVolumeAdjustType(bit bAdjustType);

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void ScalerAudioDVCVolumeFastAdjustType(bit bAdjustType);
#endif

void ScalerAudioDVCAdjustVolume(WORD usVolume);
void ScalerAudioDVCVolumeMute(bit bMute, WORD usVolume);

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void ScalerAudioDVCVolumeFastMute(bit bMute, WORD usVolume);
#endif

void ScalerAudioDVCSetMuteZCDTimeout(bit bMute, WORD usVolume, bit bAdjustType, WORD usTimeout);
void ScalerAudioDVCSetVolumeZCDTimeout(WORD usVolume);
void ScalerAudioDVCSetVolumeMuteStatus(bit bMute);
bit ScalerAudioDVCGetVolumeMuteStatus(void);
void ScalerAudioDVCResetProc(void);

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
void ScalerAudioSpdifChannelStatusProc(EnumAudioInputSource enumAudioSource, BYTE ucInputPort);
void ScalerAudioSpdifCheckIfSamplingFrequencyChange(BYTE ucInputPort);
#endif

void ScalerAudioPowerSavingMuteControl(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Audio Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioInitial(void)
{
    ScalerAudioDigitalAudioInitial();

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
    ScalerAudioTtsInitial();
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

    ScalerAudioDVCInitial();
}

//--------------------------------------------------
// Description  : Audio Clcok Gatting Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioClockGatting(bit bEnable)
{
    if(bEnable == _DISABLE)
    {
        if(ScalerGetBit(P6_D5_SOFT_RESET_DAC, _BIT0) == 0x00)
        {
            // Disable Clcok Gatting
            ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT0, _BIT0);
        }
    }
    else
    {
        if(ScalerGetBit(P6_D5_SOFT_RESET_DAC, _BIT0) == _BIT0)
        {
            // Enable Clcok Gatting
            ScalerSetBit(P6_D5_SOFT_RESET_DAC, ~_BIT0, 0x00);
        }
    }
}

//--------------------------------------------------
// Description  : Adjust Digital volume
// Input Value  : ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalAdjustVolume(WORD usVolume)
{
    ScalerAudioDVCSetVolumeZCDTimeout(usVolume);

    ScalerAudioDVCAdjustVolume(usVolume);
}

//--------------------------------------------------
// Description  : Audio Mute proc
// Input Value  : bMute, usVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioMuteProc(bit bMute, WORD usVolume)
{
    ScalerAudioDigitalVolumeMute(bMute, usVolume);
}

//--------------------------------------------------
// Description  : Smooth adjust digital volume for mute/unmute
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume)
{
    ScalerAudioDVCVolumeMute(bMute, usVolume);
}

//--------------------------------------------------
// Description  : Transfer depop mode to Normal mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDisable(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)

    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_INITIAL);
    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
    ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE);

    ScalerAudioDACNormalToDepop();

    ScalerAudioDACSetVcmReady(_OFF);

    // Power Down For Depop CLK
    ScalerSetBit(P6_D4_DA_CLK_CTRL, ~_BIT4, 0x00);

    // Power Disable For MIBS/VREF/VRP
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Use RC Filter Mode
    ScalerSetBit(P6_CA_REG_ANA_RESERVE0, ~_BIT4, _BIT4);

    // Power Disable For DAC
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT6, 0x00);

    SET_AUDIO_DAC_STATE(_AUDIO_DAC_OFF);

#endif

#if(_LINE_IN_SUPPORT == _ON)

    // Power Disable For ADC/ADCFE
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT4 | _BIT3), 0x00);

    // Use RC Filter Mode
    ScalerSetBit(P6_CA_REG_ANA_RESERVE0, ~_BIT4, _BIT4);

#endif

    // Disable DVC counter for power saving
    ScalerSetBit(P8_A0_DVC_EN, ~_BIT6, _BIT6);

    // Power Down DPLL
    ScalerAudioDisableAudioPLL();
}

//--------------------------------------------------
// Description  : Switch Audio Input Port For Each Audio Output
// Input Value  : ucAudioOutput, ucAudioInput
// Output Value : None
//--------------------------------------------------
void ScalerAudioInputPortSwitch(EnumAudioInputPort enumAudioInput)
{
    // Set DAC Input
    ScalerSetBit(P6F_01_MUX_DA_DVC_IN, ~(_BIT2 | _BIT1 | _BIT0), enumAudioInput);

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _OFF)
    // Set IIS Input
    ScalerSetBit(P6F_00_MUX_DIG_OUT, ~(_BIT6 | _BIT5 | _BIT4), (enumAudioInput << 4));

    // Set SPDIF Input
    ScalerSetBit(P6F_00_MUX_DIG_OUT, ~(_BIT2 | _BIT1 | _BIT0), enumAudioInput);
#endif

#if(_DP_TX_SUPPORT == _ON)
#if(_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _ON)
    // Set DP Tx Input
    ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), enumAudioInput);
#endif
#endif
}

//--------------------------------------------------
// Description  : Get Current Audio Port For Output Type
// Input Value  : None
// Output Value : audio port
//--------------------------------------------------
BYTE ScalerAudioGetDigitalAudioPort(EnumAudioOutputType enumAudioOutput)
{
    switch(enumAudioOutput)
    {
        case _AUDIO_DAC_OUT:

            return (ScalerGetBit(P6F_01_MUX_DA_DVC_IN, (_BIT2 | _BIT1 | _BIT0)));

        case _AUDIO_I2S_OUT:

            return (ScalerGetBit(P6F_00_MUX_DIG_OUT, (_BIT6 | _BIT5 | _BIT4)) >> 4);

        case _AUDIO_SPDIF_OUT:

            return (ScalerGetBit(P6F_00_MUX_DIG_OUT, (_BIT2 | _BIT1 | _BIT0)));

#if(_DP_TX_SUPPORT == _ON)
        case _AUDIO_DPTX_OUT:

            return (ScalerGetBit(P6F_02_MUX_DP_I2S_IN, (_BIT2 | _BIT1 | _BIT0)));
#endif

        default:
            break;
    }

    return _AUDIO_FROM_D0_PORT;
}

//--------------------------------------------------
// Description  : Get Audio Sampling Freq Packet
// Input Value  : EnumAudioSamplingFreqType
// Output Value : EnumAudioSamplingFreqPacket
//--------------------------------------------------
EnumAudioSamplingFreqPacket ScalerAudioGetSamplingFreqPacket(EnumAudioSamplingFreqType enumSamplingFreqType)
{
    switch(enumSamplingFreqType)
    {
        case _AUDIO_FREQ_32K:
            return _AUDIO_FREQ_PACKET_32K;

        case _AUDIO_FREQ_44_1K:
            return _AUDIO_FREQ_PACKET_44_1K;

        case _AUDIO_FREQ_48K:
            return _AUDIO_FREQ_PACKET_48K;

        case _AUDIO_FREQ_64K:
            return _AUDIO_FREQ_PACKET_64K;

        case _AUDIO_FREQ_88_2K:
            return _AUDIO_FREQ_PACKET_88_2K;

        case _AUDIO_FREQ_96K:
            return _AUDIO_FREQ_PACKET_96K;

        case _AUDIO_FREQ_128K:
            return _AUDIO_FREQ_PACKET_128K;

#if(_HW_HDMI_AUDIO_AFD_MODE_FOR_176P4_192 == _AUDIO_AFD_FW_MODE)
        case _AUDIO_FREQ_176_4K:
        case _AUDIO_FREQ_192K:

            if(GET_REG_D0_MAC_SWITCH_TO_HDMI() == _TRUE)
            {
                ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_8C_PORT_PAGE2_AUDIO_FREQ_RESULT_M, ~_BIT4, _BIT4);

                ScalerGetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_8C_PORT_PAGE2_AUDIO_FREQ_RESULT_M, 2, &pData[2], _AUTOINC);

                if((PDATA_WORD(1) & 0xFFF) < 0x171)
                {
                    DebugMessageAudio("Fs = 176.4kHz", (PDATA_WORD(1) & 0xFFF));
                    return _AUDIO_FREQ_PACKET_176_4K;
                }
                else
                {
                    DebugMessageAudio("Fs = 192kHz", (PDATA_WORD(1) & 0xFFF));
                    return _AUDIO_FREQ_PACKET_192K;
                }
            }
            else
            {
                if(enumSamplingFreqType == _AUDIO_FREQ_176_4K)
                {
                    return _AUDIO_FREQ_PACKET_176_4K;
                }
                else
                {
                    return _AUDIO_FREQ_PACKET_192K;
                }
            }
#else
        case _AUDIO_FREQ_176_4K:
            return _AUDIO_FREQ_PACKET_176_4K;

        case _AUDIO_FREQ_192K:
            return _AUDIO_FREQ_PACKET_192K;
#endif

        default:
            break;
    }

    return _AUDIO_FREQ_PACKET_NO_AUDIO;
}

//--------------------------------------------------
// Description  : Get User Define NF Code of Audio Sampling Freq
// Input Value  : EnumPortType
// Input Value  : EnumAudioSamplingFreqType
// Output Value : NF Code
//--------------------------------------------------
DWORD ScalerAudioGetUserSamplingFreqNFCode(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq)
{
    DWORD ulNFCode = 0x00;

    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:
        case _AUDIO_FREQ_64K:
        case _AUDIO_FREQ_128K:
        case _AUDIO_FREQ_256K:
        case _AUDIO_FREQ_512K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_32K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_32K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_32K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_44_1K:
        case _AUDIO_FREQ_88_2K:
        case _AUDIO_FREQ_176_4K:
        case _AUDIO_FREQ_352_8K:
        case _AUDIO_FREQ_705_6K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_44K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_44K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_44K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_48K:
        case _AUDIO_FREQ_96K:
        case _AUDIO_FREQ_192K:
        case _AUDIO_FREQ_384K:
        case _AUDIO_FREQ_768K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_48K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_48K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_48K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_NO_AUDIO:
        default:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_48K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_48K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_48K_GROUP_F_CODE);
            }

            break;
    }

    return ulNFCode;
}

//--------------------------------------------------
// Description  : Get User Define S Code of Audio Sampling Freq
// Input Value  : EnumPortType
// Input Value  : EnumAudioSamplingFreqType
// Output Value : NF Code
//--------------------------------------------------
BYTE ScalerAudioGetUserSamplingFreqSCode(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq)
{
    BYTE ucSCode = 0x01;

    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE;
            }

            break;

        case _AUDIO_FREQ_44_1K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE;
            }
            break;

        case _AUDIO_FREQ_48K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }

            break;

        case _AUDIO_FREQ_64K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_88_2K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_96K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_128K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_176_4K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_192K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_256K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_352_8K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_384K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_512K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_705_6K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_768K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_NO_AUDIO:
        default:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }

            break;
    }

    return ucSCode;
}

//--------------------------------------------------
// Description  : Get User Define NF Code of Audio Sampling Freq
// Input Value  : EnumPortType
// Input Value  : EnumAudioSamplingFreqType
// Output Value : NF Code
//--------------------------------------------------
DWORD ScalerAudioGetUserSamplingFreqNFCode_EXINT0(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq) using 1
{
    DWORD ulNFCode = 0x00;

    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:
        case _AUDIO_FREQ_64K:
        case _AUDIO_FREQ_128K:
        case _AUDIO_FREQ_256K:
        case _AUDIO_FREQ_512K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_32K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_32K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_32K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_44_1K:
        case _AUDIO_FREQ_88_2K:
        case _AUDIO_FREQ_176_4K:
        case _AUDIO_FREQ_352_8K:
        case _AUDIO_FREQ_705_6K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_44K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_44K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_44K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_48K:
        case _AUDIO_FREQ_96K:
        case _AUDIO_FREQ_192K:
        case _AUDIO_FREQ_384K:
        case _AUDIO_FREQ_768K:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_48K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_48K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_48K_GROUP_F_CODE);
            }

            break;

        case _AUDIO_FREQ_NO_AUDIO:
        default:

            if(enumPortType == _PORT_DP)
            {
                ulNFCode = _DP_SAMPLING_FREQ_48K_GROUP_NF_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ulNFCode = (((DWORD)_HDMI_SAMPLING_FREQ_48K_GROUP_N_CODE << 16) | _HDMI_SAMPLING_FREQ_48K_GROUP_F_CODE);
            }

            break;
    }

    return ulNFCode;
}

//--------------------------------------------------
// Description  : Get User Define S Code of Audio Sampling Freq
// Input Value  : EnumPortType
// Input Value  : EnumAudioSamplingFreqType
// Output Value : NF Code
//--------------------------------------------------
BYTE ScalerAudioGetUserSamplingFreqSCode_EXINT0(EnumInputPortType enumPortType, EnumAudioSamplingFreqType enumAudioFreq) using 1
{
    BYTE ucSCode = 0x01;

    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE;
            }

            break;

        case _AUDIO_FREQ_44_1K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE;
            }
            break;

        case _AUDIO_FREQ_48K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }

            break;

        case _AUDIO_FREQ_64K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_88_2K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_96K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 1;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 1;
            }

            break;

        case _AUDIO_FREQ_128K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_176_4K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_192K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 2;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 2;
            }

            break;

        case _AUDIO_FREQ_256K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_352_8K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_384K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 3;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 3;
            }

            break;

        case _AUDIO_FREQ_512K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_32K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_705_6K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_44K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_44K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_768K:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE >> 4;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE >> 4;
            }

            break;

        case _AUDIO_FREQ_NO_AUDIO:
        default:

            if(enumPortType == _PORT_DP)
            {
                ucSCode = _DP_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }
            else if(enumPortType == _PORT_HDMI)
            {
                ucSCode = _HDMI_SAMPLING_FREQ_48K_GROUP_S_CODE;
            }

            break;
    }

    return ucSCode;
}

#if((_EMBEDDED_DAC_SUPPORT == _ON) || (_LINE_IN_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Charge Audio Vref to AVDD/2
// Input Value  : bReady
// Output Value : None
//--------------------------------------------------
void ScalerAudioFastChargeVref(bit bReady)
{
    // Use RC Filter Mode
    ScalerSetBit(P6_CA_REG_ANA_RESERVE0, ~_BIT4, ((BYTE)bReady << 4));

    // Fast-Charge for Vref
    ScalerSetBit(P6_C8_REG_DAC_CUR6, ~_BIT4, ((BYTE)bReady << 4));
}
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio Frequency Set By User Define
// Input Value  : EnumAudioSamplingFreqType
// Output Value : None
//--------------------------------------------------
void ScalerAudioSetUserDefineAudioGenFrequency(EnumAudioSamplingFreqType enumAudioFreq)
{
    BYTE ucSCode = ScalerAudioGetSamplingFreqPacket(enumAudioFreq);

    // Avoid Divider to be 0
    ucSCode = ScalerAudioGetUserSamplingFreqSCode(_PORT_HDMI, enumAudioFreq);

    // Update Audio Frequency
    SET_AUDIO_GEN_FREQ_MAPPING(enumAudioFreq);

    // Set Frequency Parameters
    switch(enumAudioFreq)
    {
        case _AUDIO_FREQ_32K:
        case _AUDIO_FREQ_64K:
        case _AUDIO_FREQ_128K:
        case _AUDIO_FREQ_256K:
        case _AUDIO_FREQ_512K:

            SET_AUDIO_GEN_FREQ_S_CODE(ucSCode);
            SET_AUDIO_GEN_FREQ_N_CODE(_HDMI_SAMPLING_FREQ_32K_GROUP_N_CODE);
            SET_AUDIO_GEN_FREQ_F_CODE(_HDMI_SAMPLING_FREQ_32K_GROUP_F_CODE);

            break;

        case _AUDIO_FREQ_44_1K:
        case _AUDIO_FREQ_88_2K:
        case _AUDIO_FREQ_176_4K:
        case _AUDIO_FREQ_352_8K:
        case _AUDIO_FREQ_705_6K:

            SET_AUDIO_GEN_FREQ_S_CODE(ucSCode);
            SET_AUDIO_GEN_FREQ_N_CODE(_HDMI_SAMPLING_FREQ_44K_GROUP_N_CODE);
            SET_AUDIO_GEN_FREQ_F_CODE(_HDMI_SAMPLING_FREQ_44K_GROUP_F_CODE);

            break;

        case _AUDIO_FREQ_48K:
        case _AUDIO_FREQ_96K:
        case _AUDIO_FREQ_192K:
        case _AUDIO_FREQ_384K:
        case _AUDIO_FREQ_768K:

            SET_AUDIO_GEN_FREQ_S_CODE(ucSCode);
            SET_AUDIO_GEN_FREQ_N_CODE(_HDMI_SAMPLING_FREQ_48K_GROUP_N_CODE);
            SET_AUDIO_GEN_FREQ_F_CODE(_HDMI_SAMPLING_FREQ_48K_GROUP_F_CODE);

            break;

        default:

            // Set Frequency Parameters to 500Hz
            SET_AUDIO_GEN_FREQ_S_CODE(_HDMI_SAMPLING_FREQ_32K_GROUP_S_CODE);
            SET_AUDIO_GEN_FREQ_N_CODE(_HDMI_SAMPLING_FREQ_32K_GROUP_N_CODE);
            SET_AUDIO_GEN_FREQ_F_CODE(_HDMI_SAMPLING_FREQ_32K_GROUP_F_CODE);

            break;
    }
}
#endif

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : SPDIF/IIS Output By Channel Allocation
// Input Value  : Channel Allocation
// Output Value : Which channel need active
//--------------------------------------------------
BYTE ScalerAudioChannelOutputSel(BYTE ucCa)
{
    // ucRseult[0/1/2/3] = SPDIF/IIS Lane 4/3/2/1
    BYTE ucResult = 0x0F;

    switch(ucCa)
    {
        case 0x01:
        case 0x02:
        case 0x03:

            // Lane1,2
            ucResult = 0x03;
            break;

        case 0x04:
        case 0x08:

            // Lane1,3
            ucResult = 0x05;
            break;

        case 0x05:
        case 0x06:
        case 0x07:
        case 0x09:
        case 0x0A:
        case 0x0B:

            // Lane1,2,3
            ucResult = 0x07;
            break;

        case 0x14:

            // Lane1,4
            ucResult = 0x09;
            break;

        case 0x15:
        case 0x16:
        case 0x17:

            // Lane1,2,4
            ucResult = 0x0B;
            break;

        case 0x0C:
        case 0x10:
        case 0x18:
        case 0x1C:
        case 0x24:
        case 0x26:

            // Lane1,3,4
            ucResult = 0x0D;
            break;

        case 0x0D:
        case 0x0E:
        case 0x0F:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x25:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:

            // Lane1,2,3,4
            ucResult = 0x0F;
            break;

        default:
            break;
    }

    return ucResult;
}
#endif

#if(_LINE_IN_SUPPORT == _ON)
#if(_HW_DIGITAL_PORT_COMBO_PHY_TYPE != _DIGITAL_PORT_COMBO_PHY_NONE)
//--------------------------------------------------
// Description  : Get Current DAC Input Source
// Input Value  : None
// Output Value : _LINE_IN_AUDIO/ _DIGITAL_AUDIO
//--------------------------------------------------
EnumAudioInputSource ScalerAudioGetInputSource_EXINT0(void) using 1
{
    return ((ScalerGetBit_EXINT(P6_D1_DA_MUTE, _BIT3) == 0x00) ? _DIGITAL_AUDIO : _LINE_IN_AUDIO);
}
#endif

//--------------------------------------------------
// Description  : Get Current DAC Input Source
// Input Value  : None
// Output Value : _LINE_IN_AUDIO/ _DIGITAL_AUDIO
//--------------------------------------------------
EnumAudioInputSource ScalerAudioGetInputSource(void)
{
    return ((ScalerGetBit(P6_D1_DA_MUTE, _BIT3) == 0x00) ? _DIGITAL_AUDIO : _LINE_IN_AUDIO);
}

//--------------------------------------------------
// Description  : Initial ADC Auido PLL Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioSetADCAudioPLL(void)
{
    ScalerAudioSetAudioADCPLLOffProc();
    ScalerAudioSetAudioADCPLLOnProc();
}

//--------------------------------------------------
// Description  : Set Audio ADC PLL Off Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioSetAudioADCPLLOffProc(void)
{
    // Audio PLL Power Down
    ScalerSetBit(PBF_A8_AUDIO_PLL_CONTROL, ~_BIT0, _BIT0);

    // Set Output Divider = 6 (Digital)
    ScalerSetBit(PBF_A2_PLL_OUT_CONTROL, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);

    // Set O code = 4
    ScalerSetBit(PBF_A5_AUDIO_PLL_DIVIDER1, ~(_BIT1 | _BIT0), _BIT1);

    //**********************************************************************
    // Audio PLL Parameters Setting
    // Fref = Xtal = 14.318MHz
    // Target Clock = 393.216MHz => N = 27, F = 0.463053191
    // N = 25 + 2 => 0x19    // F = 0.463053191 x 2^16 = 0x768AA
    // VCO band = 2b'00 (400MHz less) => Kvco = NA
    // Icp = (N code)x0.25uA = 25x0.25uA = 6.25uA
    // Icp = 6.25uA/2.5uA --> 7.5uA(3'b010)
    //**********************************************************************

    // Set Icp = 7.5uA
    ScalerSetBit(PBF_A6_AUDIO_PLL_0, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    // Initial VCO Band = 10, PI current = 2.5uA
    ScalerSetBit(PBF_A7_AUDIO_PLL_1, ~(_BIT5 | _BIT4 | _BIT1 | _BIT0), 0x00);
}

//--------------------------------------------------
// Description  : Set Audio ADC PLL On Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioSetAudioADCPLLOnProc(void)
{
    // Power On Audio PLL
    ScalerSetBit(PBF_A8_AUDIO_PLL_CONTROL, ~_BIT0, 0x00);

#if(_EXT_XTAL == _XTAL14318K)
    // Set Xtal as Audio PLL Input clock
    ScalerSetBit(PBF_A3_PLL_IN_CONTROL, ~(_BIT7 | _BIT6), _AUDIO_PLL_IN_EXT_XTAL_CLK);
#endif

    // Set N-code of NF PLL ref Xtal 14.318M
    // Set Audio PLL Analog Divider, need double buffer
    // Set Audio PLL Predivider
    ScalerSetByte(PBF_A4_M2PLL_DIVIDER0, (_AUDIO_PLL_PREDIVIDER_N - 2));

    // Set Audio PLL Output Divider (Analog)
    ScalerSetBit(PBF_A5_AUDIO_PLL_DIVIDER1, ~(_BIT7 | _BIT1 | _BIT0), (((BYTE)_AUDIO_PLL_PREDIVIDER_BPN << 7) | _AUDIO_PLL_O_DIV));

    ScalerSetByte(PBF_AD_N_F_CODE_1, _ADC_AUDIO_PLL_N);

    // Set F-code of NF PLL
    ScalerSetBit(PBF_AE_N_F_CODE_2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIWORD(_ADC_AUDIO_PLL_F) & 0x0F));
    ScalerSetByte(PBF_AF_N_F_CODE_3, HIBYTE(LOWORD(_ADC_AUDIO_PLL_F)));
    ScalerSetByte(PBF_B0_N_F_CODE_4, LOBYTE(LOWORD(_ADC_AUDIO_PLL_F)));

    // Dobule Buffer
    ScalerSetByte(PBF_AC_N_F_CODE_0, _BIT0);

    // Power On Audio PLL
    ScalerSetBit(PBF_A8_AUDIO_PLL_CONTROL, ~_BIT0, 0x00);
}
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Audio DAC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACInitial(void)
{
    // Disable Clcok Gatting
    ScalerAudioClockGatting(_DISABLE);

    // AIO DF2SE Input MUX Switch All-Mute Path
    ScalerSetBit(P6_C5_REG_DAC_CUR3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

    // HPO DF2SE Input MUX Switch All-Mute Path
    ScalerSetBit(P6_C7_REG_DAC_CUR5, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1));

#if(_LINE_IN_SUPPORT == _OFF)
    ////////// MBIAS //////////
    // Use RC Filter Bypass Mode & Enable Fast-Charge for Vref
    ScalerAudioFastChargeVref(_ON);

    // Power Enable MIBS/VREF/VRP
    ScalerSetBit(P6_B0_REG_ADC_POWER, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Enable AIO Depop Mode / AIO Control Depop Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT3 | _BIT2), _BIT2);
#else
    // Disable AIO Depop Mode / AIO Control Normal Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT3 | _BIT2), _BIT3);
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Enable HPO Depop Mode / HPO Control Depop Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT1 | _BIT0), _BIT0);
#else
    // Disable HPO Depop Mode / HPO Control Normal Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT1 | _BIT0), _BIT1);
#endif

    ////////// AIO&HPO Output //////////
#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Set AOUT Gain Enable
    ScalerSetBit(P6_C4_REG_DAC_CUR2, ~(_BIT5 | _BIT4), _BIT5 | _BIT4);
#else
    // Set AOUT Gain Disable
    ScalerSetBit(P6_C4_REG_DAC_CUR2, ~(_BIT5 | _BIT4), 0x00);
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Set HPOUT Gain Enable
    ScalerSetBit(P6_C6_REG_DAC_CUR4, ~(_BIT5 | _BIT4), _BIT5 | _BIT4);
#else
    // Set HPOUT Gain Disable
    ScalerSetBit(P6_C6_REG_DAC_CUR4, ~(_BIT5 | _BIT4), 0x00);
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Power On for AIO Power
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT5, _BIT5);
#else
    // Power OFF for AIO Power
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT5, 0x00);
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Power On for HPO  Power
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT4, _BIT4);
#else
    // Power OFF for HPO Power
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT4, 0x00);
#endif

    // Depop Clock Setting 55.75KHz
    ScalerSetBit(P6_D4_DA_CLK_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);

    // Enable Depop Clock
    ScalerSetBit(P6_D4_DA_CLK_CTRL, ~_BIT4, _BIT4);

    ////////// DAC Flow //////////
    // Enable DAC LDO Power & Use DAC LDO
    ScalerSetBit(P6_CA_REG_ANA_RESERVE0, ~(_BIT3 | _BIT2), _BIT2);

    // Enable DAC Power
    ScalerSetBit(P6_C0_REG_DAC_POWER0, ~_BIT6, _BIT6);

    ////////// Digital //////////
    // Set DAC Dither Function
    ScalerSetBit(P6_D0_DA_CTRL, ~(_BIT5 | _BIT4), (_DAC_DITHER_FUNCTION_LEVEL << 4));

    // Mute DAC and Set DAC Clock Source
    ScalerSetBit(P6_D1_DA_MUTE, ~(_BIT7 | _BIT6 | _BIT3), 0x00);

    // Set DAC Volume Of L Ch
    ScalerSetByte(P6_D2_DA_GAIN_L, 0x57);

    // Set DAC Volume Of R Ch
    ScalerSetByte(P6_D3_DA_GAIN_R, 0x57);

    // Set Double Buffer
    ScalerSetBit(P6_D2_DA_GAIN_L, ~_BIT7, _BIT7);

    // Set DC off set 375uV for Right channel
    ScalerSetByte(P6_C9_REG_DAC_DUMMY1, 0x00);
    ScalerSetByte(P6_D6_DA_DUMMY_1, 0xC5);

    // Set DC off set 375uV for Left channel
    ScalerSetByte(P6_E6_AD_SPDIF_CS_4, 0x00);
    ScalerSetByte(P6_EF_AUD_DUMMY_1, 0xC5);
}

//--------------------------------------------------
// Description  : Switch audio output (AOUT / HPOut)
// Input Value  : enumDACOutput
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput)
{
    switch(enumDACOutput)
    {
#if((_DAC_SPEAKER_OUTPUT_SUPPORT == _ON) && (_DAC_HP_OUTPUT_SUPPORT == _ON))
        case _AUDIO_DAC_OUTPUT_BOTH:

#if((_DAC_SPEAKER_OUTPUT_SWAP == _ON) && (_DAC_HP_OUTPUT_SWAP == _ON))
            // Enable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
#else
            // Disable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), 0x00);
#endif
            ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
            break;
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
        case _AUDIO_DAC_OUTPUT_SPEAKER:

#if (_DAC_SPEAKER_OUTPUT_SWAP == _ON)
            // Enable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
#else
            // Disable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), 0x00);
#endif
            ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT5 | _BIT4), _BIT5);
            break;
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
        case _AUDIO_DAC_OUTPUT_HEADPHONE:

#if (_DAC_HP_OUTPUT_SWAP == _ON)
            // Enable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
#else
            // Disable Swap DAC L/R Channel
            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), 0x00);
#endif
            ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT5 | _BIT4), _BIT4);
            break;
#endif

        default:

            ScalerSetBit(P6_EE_REG_MUX_ANA_OUT2, ~(_BIT1 | _BIT0), 0x00);

            ScalerSetBit(P6_C0_REG_DAC_POWER0, ~(_BIT5 | _BIT4), 0x00);

            break;
    }
}

//--------------------------------------------------
// Description  : Change Auido DAC State
// Input Value  : Target Audio DAC State
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSetState(EnumAudioDACState enumTargetState)
{
    SET_AUDIO_DAC_STATE(enumTargetState);
    SET_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Get Curretn DAC State
// Input Value  : None
// Output Value : Current DAC State
//--------------------------------------------------
EnumAudioDACState ScalerAudioDACGetState(void)
{
    return GET_AUDIO_DAC_STATE();
}

//--------------------------------------------------
// Description  : Get Curretn DAC State Change
// Input Value  : None
// Output Value : TRUE => State Changed
//--------------------------------------------------
bit ScalerAudioDACGetStateChange(void)
{
    return GET_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Clear DAC State Change
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACClrStateChange(void)
{
    CLR_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : When Vcm already charge to AVDD/2, Vo(Output Voltage) should charge as Vcm
// Input Value  : bReady
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSetVcmReady(bit bReady)
{
    if(bReady == _ON)
    {
        ////////// MBIAS //////////
        // Use RC Filter Mode & Disable Fast-Charge for Vref
        ScalerAudioFastChargeVref(_OFF);

        // Enable Power for DPRAMP
        ScalerSetBit(P6_C3_REG_DAC_CUR1, ~_BIT7, _BIT7);

        DELAY_5US();

        // Enable Power for RAMPGEN
        ScalerSetBit(P6_C3_REG_DAC_CUR1, ~_BIT6, _BIT6);
    }
    else
    {
        // Enable Power for DPRAMP
        ScalerSetBit(P6_C3_REG_DAC_CUR1, ~_BIT7, 0x00);

        DELAY_5US();

        // Enable Power for RAMPGEN
        ScalerSetBit(P6_C3_REG_DAC_CUR1, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Transfer depop mode to Normal mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACNormalToDepop(void)
{
    // Disable VCM Charge
    ScalerAudioDACSetVcmReady(_OFF);

    // Enable Depop Clock
    ScalerSetBit(P6_D4_DA_CLK_CTRL, ~_BIT4, _BIT4);

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // HPO Output Select Loading 10Kohm Mode
    ScalerSetBit(P6_C2_REG_DAC_CUR0, ~_BIT0, 0x00);
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Enable AIO Depop Mode / AIO Control Depop Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT3 | _BIT2), _BIT2);
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Enable HPO Depop Mode / HPO Control Depop Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT1 | _BIT0), _BIT0);
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // AIO DF2SE Input MUX Switch All-Mute Path
    ScalerSetBit(P6_C5_REG_DAC_CUR3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // HPO DF2SE Input MUX Switch All-Mute Path
    ScalerSetBit(P6_C7_REG_DAC_CUR5, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1));
#endif

    // Enable VCM Charge
    ScalerAudioDACSetVcmReady(_ON);

    ScalerAudioDACSetState(_AUDIO_DAC_DEPOP);
}

//--------------------------------------------------
// Description  : Transfer depop mode to normal mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACDepopToNormal(void)
{
#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Disable AIO Depop Mode / AIO Control Normal Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT3 | _BIT2), _BIT3);
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Disable HPO Depop Mode / HPO Control Normal Mode
    ScalerSetBit(P6_C3_REG_DAC_CUR1, ~(_BIT1 | _BIT0), _BIT1);
#endif

    ////////// VCM //////////
    ScalerAudioDACSetVcmReady(_OFF);

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // HPO Output Select Loading 32ohm Mode
    ScalerSetBit(P6_C2_REG_DAC_CUR0, ~_BIT0, _BIT0);
#endif

    // Disable Depop Clock
    ScalerSetBit(P6_D4_DA_CLK_CTRL, ~_BIT4, 0x00);

    ScalerAudioDACSetState(_AUDIO_DAC_READY);
}

//--------------------------------------------------
// Description  : Switch AOUT/HPOUT to Normal Output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACOutputEnable(void)
{
    // Disable VCM Charge
    ScalerAudioDACSetVcmReady(_OFF);

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    if(ScalerGetBit(P6_C0_REG_DAC_POWER0, _BIT5) == _BIT5)
    {
        // AIO DF2SE Input MUX Switch DAC Path
        ScalerSetBit(P6_C5_REG_DAC_CUR3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2 | _BIT1));
    }
#endif

#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    if(ScalerGetBit(P6_C0_REG_DAC_POWER0, _BIT4) == _BIT4)
    {
        // HPO DF2SE Input MUX Switch DAC Path
        ScalerSetBit(P6_C7_REG_DAC_CUR5, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT5 | _BIT3 | _BIT2));
    }
#endif

    // Enable VCM Charge
    ScalerAudioDACSetVcmReady(_ON);
}

//--------------------------------------------------
// Description  : Get Current DAC Output Channel
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput ScalerAudioDACGetOutput(void)
{
    if(ScalerGetBit(P6_C0_REG_DAC_POWER0, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4))
    {
        return _AUDIO_DAC_OUTPUT_BOTH;
    }
    else if(ScalerGetBit(P6_C0_REG_DAC_POWER0, (_BIT5 | _BIT4)) == _BIT5)
    {
        return _AUDIO_DAC_OUTPUT_SPEAKER;
    }
    else if(ScalerGetBit(P6_C0_REG_DAC_POWER0, (_BIT5 | _BIT4)) == _BIT4)
    {
        return _AUDIO_DAC_OUTPUT_HEADPHONE;
    }

    return _AUDIO_DAC_OUTPUT_NONE;
}

//--------------------------------------------------
// Description  : Set DAC Output Gain
// Input Value  : EnumAudioDACOutput, ucOutputGain
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSetOutputGain(EnumAudioDACOutput enumOutputType, EnumAudioDacOutputGain enumOutputGain)
{
    if(enumOutputType == _AUDIO_DAC_OUTPUT_SPEAKER)
    {
        // Set AOUT Gain After DAC Block
        ScalerSetBit(P6_C4_REG_DAC_CUR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), enumOutputGain);
    }
    else if(enumOutputType == _AUDIO_DAC_OUTPUT_HEADPHONE)
    {
        // Set HPOUT Gain After DAC Block
        ScalerSetBit(P6_C6_REG_DAC_CUR4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), enumOutputGain);
    }
    else if(enumOutputType == _AUDIO_DAC_OUTPUT_BOTH)
    {
        // Set AOUT Gain After DAC Block
        ScalerSetBit(P6_C4_REG_DAC_CUR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), enumOutputGain);

        // Set HPOUT Gain After DAC Block
        ScalerSetBit(P6_C6_REG_DAC_CUR4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), enumOutputGain);
    }
}
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Initial DVC Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCInitial(void)
{
    // Disable Clcok Gatting
    ScalerAudioClockGatting(_DISABLE);

    // Enable DVC function and counter
    ScalerSetBit(P8_A0_DVC_EN, ~(_BIT7 | _BIT6), _BIT7);

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));
    ScalerSetByte(P8_A4_DVC_ZC_WIN_CTRL_1, LOBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));

    // Select DVC Volume Adjust Type
    ScalerAudioDVCVolumeAdjustType(_DVC_ADJUST_TYPE);

    // Initial DVC gain = 0
    ScalerAudioDVCAdjustVolume(0x00);

    // Initial DVC Mute Control Status
    SET_AUDIO_DVC_MUTE_CTRL_STATUS(_ON);

#if((_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON) || (_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE))
#if(_LINE_IN_SUPPORT == _OFF)
    // Set Sampling Frequency "48kHz" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_48KHZ);

    // Set Channel Count "2 ch" For S/PDIF Output From ADC In
    ScalerSetBit(P6_E3_AD_SPDIF_CS_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Enable I2S Output for ADC In
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT7, _BIT7);
#endif

    // Select SPDIF from DVC path
    ScalerSetBit(P6_E1_AD_SPDIF_CTRL, ~_BIT4, _BIT4);

    // Select I2S from DVC path
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT5, _BIT5);

    // Set I2S and SPDIF From DVC path
    ScalerSetBit(P6F_00_MUX_DIG_OUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_AUDIO_FROM_ADC_PORT << 4) | _AUDIO_FROM_ADC_PORT);

#endif // End of #if((_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON) || (_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE))
}

//--------------------------------------------------
// Description  : Select DVC Volume Adjust Type
// Input Value  : _DB_GAIN, _VOLUME_STEP_SIZE
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeAdjustType(bit bAdjustType)
{
    if(bAdjustType == _DB_GAIN)
    {
        // Select value mode and set DB gain setp
        ScalerSetBit(P8_A0_DVC_EN, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_DB_GAIN_DOWN_VALUE << 2) | _DB_GAIN_UP_VALUE));

        // Initial volume step size for DB gain mode
        ScalerSetBit(P8_A1_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetByte(P8_A2_DVC_VA_LSB, 0x01);
    }
    else // _VOLUME_STEP_SIZE
    {
        // Select value mode
        ScalerSetBit(P8_A0_DVC_EN, ~(_BIT4), _BIT4);

        // Set volume step size
        ScalerSetBit(P8_A1_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_VOLUME_STEP_SIZE_VALUE));
        ScalerSetByte(P8_A2_DVC_VA_LSB, LOBYTE(_VOLUME_STEP_SIZE_VALUE));
    }
}

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Select DVC Volume Fast Adjust Type
// Input Value  : _DB_GAIN, _VOLUME_STEP_SIZE
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeFastAdjustType(bit bAdjustType)
{
    if(bAdjustType == _DB_GAIN)
    {
        // Select value mode and set DB gain setp
        ScalerSetBit(P8_A0_DVC_EN, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_DB_GAIN_FAST_DOWN_VALUE << 2) | _DB_GAIN_FAST_UP_VALUE));

        // Initial volume step size for DB gain mode
        ScalerSetBit(P8_A1_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetByte(P8_A2_DVC_VA_LSB, 0x01);
    }
    else // _VOLUME_STEP_SIZE
    {
        // Select value mode
        ScalerSetBit(P8_A0_DVC_EN, ~(_BIT4), _BIT4);

        // Set volume step size
        ScalerSetBit(P8_A1_DVC_VA_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_VOLUME_STEP_SIZE_VALUE));
        ScalerSetByte(P8_A2_DVC_VA_LSB, LOBYTE(_VOLUME_STEP_SIZE_VALUE));
    }
}
#endif

//--------------------------------------------------
// Description  : Adjust digital volume for DVC function
// Input Value  : ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCAdjustVolume(WORD usVolume)
{
    // DVC gain MSB
    ScalerSetBit(P8_A5_DVC_GAIN_MSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usVolume));

    // DVC gain LSB  (double buffer)
    ScalerSetByte(P8_A6_DVC_GAIN_LSB, LOBYTE(usVolume));

    // Set Double Buffer
    ScalerSetBit(P8_A7_DVC_GAIN_READ_MSB, ~_BIT6, _BIT6);
}

//--------------------------------------------------
// Description  : Mute/Unmute for DVC function
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeMute(bit bMute, WORD usVolume)
{
    ScalerAudioDVCVolumeAdjustType(_DVC_ADJUST_TYPE);

    ScalerAudioDVCSetMuteZCDTimeout(bMute, usVolume, _DVC_ADJUST_TYPE, _DVC_VOLUME_MUTE_TIMER);

    PDATA_WORD(0) = (((WORD) ScalerGetByte(P8_A7_DVC_GAIN_READ_MSB) << 8) | ScalerGetByte(P8_A8_DVC_GAIN_READ_LSB));

    if(bMute == _ON)
    {
        if(PDATA_WORD(0) != 0)
        {
            ScalerAudioDVCAdjustVolume(0);

            PDATA_WORD(1) = 0;

            do
            {
                ScalerTimerDelayXms(1);
                PDATA_WORD(1)++;
            }
            while((ScalerGetBit(P8_A9_DVC_GAIN_DONE, _BIT7) != _BIT7) && (PDATA_WORD(1) < _DVC_VOLUME_MUTE_TIMER));
        }
    }
    else // Unmute
    {
        if(PDATA_WORD(0) != usVolume)
        {
            ScalerAudioDVCAdjustVolume(usVolume);
        }
    }
}

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Fast Mute/Unmute for DVC function
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeFastMute(bit bMute, WORD usVolume)
{
    ScalerAudioDVCVolumeFastAdjustType(_DVC_ADJUST_TYPE);

    if(bMute == _ON)
    {
        ScalerAudioDVCSetMuteZCDTimeout(bMute, usVolume, _DVC_ADJUST_TYPE, _DVC_FAST_VOLUME_MUTE_TIMER);
    }
    else
    {
        ScalerAudioDVCSetMuteZCDTimeout(bMute, usVolume, _DVC_ADJUST_TYPE, _DVC_FAST_VOLUME_UNMUTE_TIMER);
    }

    PDATA_WORD(0) = (((WORD) ScalerGetByte(P8_A7_DVC_GAIN_READ_MSB) << 8) | ScalerGetByte(P8_A8_DVC_GAIN_READ_LSB));

    if(bMute == _ON)
    {
        if(PDATA_WORD(0) != 0)
        {
            ScalerAudioDVCAdjustVolume(0);

            PDATA_WORD(1) = 0;

            do
            {
                ScalerTimerDelayXms(1);
                PDATA_WORD(1)++;
            }
            while((ScalerGetBit(P8_A9_DVC_GAIN_DONE, _BIT7) != _BIT7) && (PDATA_WORD(1) < _DVC_FAST_VOLUME_MUTE_TIMER));
        }
    }
    else // Unmute
    {
        if(PDATA_WORD(0) != usVolume)
        {
            ScalerAudioDVCAdjustVolume(usVolume);
        }
    }
}
#endif

//--------------------------------------------------
// Description  : Set ZCD Timeout
// Input Value  : bMute, usVolume, bAdjustType
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCSetMuteZCDTimeout(bit bMute, WORD usVolume, bit bAdjustType, WORD usTimeout)
{
    EnumAudioSamplingFreqPacket enumSamplingFreqPacket = _AUDIO_FREQ_PACKET_NO_AUDIO;

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

    if(bAdjustType == _DB_GAIN)
    {
        // Get down or up step
        pData[0] = (bMute == _ON) ? (ScalerGetBit(P8_A0_DVC_EN, (_BIT3 | _BIT2)) >> 2) : ScalerGetBit(P8_A0_DVC_EN, (_BIT1 | _BIT0));

        // Get numbers of the volume step for mute or unmute
        PDATA_WORD(0) = _DVC_DB_STEP_NUMBER << pData[0];
    }
    else
    {
        PDATA_WORD(0) = usVolume / _VOLUME_STEP_SIZE_VALUE + 1;
    }

    // Calculate samples of ZCD timeout
    PDATA_DWORD(1) = (DWORD)enumSamplingFreqPacket * usTimeout / PDATA_WORD(0);

    // Avoid Overflow
    if(PDATA_DWORD(1) > 0x0FFF)
    {
        PDATA_WORD(0) = 0x0FFF;
    }
    else
    {
        PDATA_WORD(0) = (WORD)PDATA_DWORD(1);
    }

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(PDATA_WORD(0)));
    ScalerSetByte(P8_A4_DVC_ZC_WIN_CTRL_1, LOBYTE(PDATA_WORD(0)));
}

//--------------------------------------------------
// Description  : Set ZCD Timeout, only use the type "_VOLUME_STEP_SIZE"
// Input Value  : usVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCSetVolumeZCDTimeout(WORD usVolume)
{
    EnumAudioSamplingFreqPacket enumSamplingFreqPacket = _AUDIO_FREQ_PACKET_NO_AUDIO;

    ScalerAudioDVCVolumeAdjustType(_VOLUME_STEP_SIZE);

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

    // Get Current Volume
    PDATA_WORD(0) = ((WORD)(ScalerGetByte(P8_A5_DVC_GAIN_MSB) & 0x3F) << 8) | ((WORD)ScalerGetByte(P8_A6_DVC_GAIN_LSB));

    PDATA_WORD(0) = (PDATA_WORD(0) > usVolume) ? (PDATA_WORD(0) - usVolume) : (usVolume - PDATA_WORD(0));

    PDATA_WORD(0) = PDATA_WORD(0) / _VOLUME_STEP_SIZE_VALUE + 1;

    // Calculate samples of ZCD timeout
    PDATA_DWORD(1) = (DWORD)enumSamplingFreqPacket * _DVC_VOLUME_ADJUST_TIMER / PDATA_WORD(0);

    // Avoid Overflow
    if(PDATA_DWORD(1) > 0x0FFF)
    {
        PDATA_WORD(0) = 0x0FFF;
    }
    else
    {
        PDATA_WORD(0) = (WORD)PDATA_DWORD(1);
    }

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_ZC_WIN_CTRL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(PDATA_WORD(0)));
    ScalerSetByte(P8_A4_DVC_ZC_WIN_CTRL_1, LOBYTE(PDATA_WORD(0)));
}

//--------------------------------------------------
// Description  : Set DVC Mute Status
// Input Value  : None
// Output Value : _ON or _OFF
//--------------------------------------------------
void ScalerAudioDVCSetVolumeMuteStatus(bit bMute)
{
    SET_AUDIO_DVC_MUTE_CTRL_STATUS(bMute);
}

//--------------------------------------------------
// Description  : Get DVC Mute Status
// Input Value  : None
// Output Value : _ON or _OFF
//--------------------------------------------------
bit ScalerAudioDVCGetVolumeMuteStatus(void)
{
    return GET_AUDIO_DVC_MUTE_CTRL_STATUS();
}

//--------------------------------------------------
// Description  : DVC Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCResetProc(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(ScalerAudioDACGetState() == _AUDIO_DAC_READY)
    {
        // Switch Audio DAC State to _AUDIO_DAC_DEPOP
        ScalerAudioDACNormalToDepop();
    }
#endif

    // Reset DVC Counter
    ScalerSetBit(P8_A0_DVC_EN, ~_BIT6, _BIT6);

    // At Least Delay 2 Cycle of 1 / 256 * FS (= 32KHz)
    DELAY_5US();

    // Enable DVC Counter
    ScalerSetBit(P8_A0_DVC_EN, ~_BIT6, 0x00);

#if(_DIGITAL_AUDIO_OUTPUT_FIX_I2S_PHASE_DELAY == _ON)
    // Disable I2S Block
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT7, 0x00);

    // At Least Delay 2 Cycle of 1 / FS (= 32KHz)
    DELAY_XUS(70);

    // Enable I2S Block
    ScalerSetBit(P6_E7_AD_I2S_CTRL, ~_BIT7, _BIT7);
#endif
}

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Handle Smapling Frequency Infomation in SPDIF format
// Input Value  : enumAudioSource, ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioSpdifChannelStatusProc(EnumAudioInputSource enumAudioSource, BYTE ucInputPort)
{
    if(enumAudioSource == _DIGITAL_AUDIO)
    {
        ScalerAudioSpdifCheckIfSamplingFrequencyChange(ucInputPort);
    }
    else if(enumAudioSource == _LINE_IN_AUDIO)
    {
        ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_48KHZ);
    }
}

//--------------------------------------------------
// Description  : Detect and Change Smapling Frequency Infomation in SPDIF format
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerAudioSpdifCheckIfSamplingFrequencyChange(BYTE ucInputPort)
{
    switch(ScalerAudioSamplingFreqDetect(ucInputPort))
    {
        case _AUDIO_FREQ_PACKET_32K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_32KHZ);

            break;

        case _AUDIO_FREQ_PACKET_44_1K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_44_1KHZ);

            break;

        case _AUDIO_FREQ_PACKET_48K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_48KHZ);

            break;

        case _AUDIO_FREQ_PACKET_88_2K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_88_2KHZ);

            break;

        case _AUDIO_FREQ_PACKET_96K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_96KHZ);

            break;

        case _AUDIO_FREQ_PACKET_176_4K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_176_4KHZ);

            break;

        case _AUDIO_FREQ_PACKET_192K:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_192KHZ);

            break;

        default:

            ScalerSetBit(P6_E2_AD_SPDIF_CS_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _AUDIO_SPDIF_FS_NOT_INDICATED);

            break;
    }
}
#endif

//--------------------------------------------------
// Description  : Audio ADC/DAC All Mute
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioPowerSavingMuteControl(void)
{
    // Write Audio Mute Table
    ScalerBurstWrite(tADDA_ALL_MUTE, sizeof(tADDA_ALL_MUTE), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
}
#endif // End of #if(_AUDIO_SUPPORT == _ON)

