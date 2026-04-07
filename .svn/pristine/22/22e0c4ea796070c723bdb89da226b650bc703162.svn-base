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
// ID Code      : SysAudio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_AUDIO__

#include "SysInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_EMBEDDED_DAC_SUPPORT == _ON)
#define _DAC_VCM_INITIAL_TIME                       SEC(0.1)
#define _DAC_VCM_CHARGE_TIME                        SEC(0.5)
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructAudioInfoType g_stAudioInfo;
EnumAudioSamplingFreqPacket g_enumAudioFSBackup = _AUDIO_FREQ_PACKET_NO_AUDIO;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysAudioHandler(void);
EnumAudioState SysAudioGetAudioState(void);
EnumAudioSamplingFreqPacket SysAudioGetAudioBackupFreq(void);
void SysAudioPowerProc(EnumPowerAction enumSwitch);
void SysAudioMuteProc(bit bMute);

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void SysAudioFastMuteProc(bit bMute);
#endif

void SysAudioOutputProc(bit bEnable);

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void SysAudioFastOutputProc(bit bEnable);
#endif

void SysAudioAnalogAudioHandler(void);
void SysAudioDigitalAudioHandler(void);
void SysAudioChangeAudioState(EnumAudioState enumAudioState);
void SysAudioInitial(void);
void SysAudioSetUserDefineAudioFrequency(void);

#if(_DP_SUPPORT == _ON)
void SysAudioDpAudioSecDataResetProc(BYTE ucInputPort);
#endif

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
void SysAudioFwTrackingHandler(void);
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
void SysAudioSleepAudioHandler(void);

#if((_LINE_IN_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
bit SysAudioGetSleepAudioStatusForLineIn(void);
#endif
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void SysAudioInternalGenTestProc(bit bOn);
#endif

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
void SysAudioTtsCheckPlaybackAcitveEvent(void);
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Audio handler. Main audio control flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioHandler(void)
{
    SysAudioAnalogAudioHandler();

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable(SysSourceGetInputPort()) == _ENABLE)
    {
        return;
    }
#endif

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
    SysAudioFwTrackingHandler();
#endif

    SysAudioDigitalAudioHandler();

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
    // Check TTS Event Trigger or Not
    SysAudioTtsCheckPlaybackAcitveEvent();
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

    switch(GET_AUDIO_STATE())
    {
        case _AUDIO_STATUS_PREPARING:

            if(GET_AUDIO_STATE_CHANGE() == _TRUE)
            {
                CLR_AUDIO_STATE_CHANGE();
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(0x0F);
            }

            if(UserCommonInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
#if(_HDMI_SUPPORT == _ON)
                if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
                {
                    ScalerAudioHdmiI2sSpdifChannelOutputSelect(_AUDIO_SELECT_BY_CA_MODE, ScalerAudioGetDigitalAudioPortMapping());
                }
#endif

                ScalerAudioDigitalEnable(ScalerAudioGetDigitalAudioPortMapping());

                SysAudioChangeAudioState(_AUDIO_STATUS_PLAYBACK);

                DebugMessageAudio("Switch to Audio Playback", _AUDIO_STATUS_PLAYBACK);

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                // RX Digital Audio Output Control
                ScalerAudioDigitalOutputMute(_OFF);
                ScalerTimerDelayXms(3);
#endif
                // Normal Control DVC & Ext.Amp & Ext. DSP
                SysAudioOutputProc(_ENABLE);

                g_enumAudioFSBackup = ScalerAudioSamplingFreqDetect(SysSourceGetInputPort());

                // Update User Define Frequency When No Audio
                SysAudioSetUserDefineAudioFrequency();

                // Set User Define Frequency When No Audio except input port
                ScalerAudioSyncUserDefineFrequency();
            }

            break;

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)

        case _AUDIO_STATUS_PLAYBACK_CHECK:

            if(GET_AUDIO_STATE_CHANGE() == _TRUE)
            {
                CLR_AUDIO_STATE_CHANGE();
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(g_ucSearchIndex);
            }

            if(UserCommonInterfaceGetAudioReadyToPlayStatus() == _FALSE)
            {
                if(GET_MODE_STATE() != _MODE_STATUS_ACTIVE)
                {
                    SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);

                    DebugMessageAudio("Switch to Audio Preparing", _AUDIO_STATUS_PREPARING);

                    // Normal Control DVC & Ext.Amp & Ext. DSP
                    SysAudioOutputProc(_DISABLE);

                    ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    // RX Digital Audio Output Control
                    ScalerTimerDelayXms(3);
                    ScalerAudioDigitalOutputMute(_ON);
#endif

#if(_HDMI_SUPPORT == _ON)
                    if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
                    {
                        ScalerAudioHdmiI2sSpdifChannelOutputSelect(_AUDIO_DEFAULT_MODE, ScalerAudioGetDigitalAudioPortMapping());
                    }
#endif
                }
            }
            else
            {
                if(SysAudioGetAudioBackupFreq() == ScalerAudioSamplingFreqDetect(SysSourceGetInputPort()))
                {
#if(_HDMI_SUPPORT == _ON)
                    if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
                    {
                        ScalerAudioHdmiI2sSpdifChannelOutputSelect(_AUDIO_SELECT_BY_CA_MODE, ScalerAudioGetDigitalAudioPortMapping());
                    }
#endif
                    ScalerAudioDigitalEnable(ScalerAudioGetDigitalAudioPortMapping());

                    SysAudioChangeAudioState(_AUDIO_STATUS_PLAYBACK);

                    DebugMessageAudio("Switch to Audio Playback", _AUDIO_STATUS_PLAYBACK);

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    // RX Digital Audio Output Control
                    ScalerAudioDigitalOutputMute(_OFF);
                    ScalerTimerDelayXms(3);
#endif

                    // Fast Control DVC & Ext.Amp & Ext. DSP
                    SysAudioFastOutputProc(_ENABLE);

                    // Update User Define Frequency When No Audio
                    SysAudioSetUserDefineAudioFrequency();

                    // Set User Define Frequency When No Audio except input port
                    ScalerAudioSyncUserDefineFrequency();
                }
                else
                {
                    SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);

                    DebugMessageAudio("Switch to Audio Preparing", _AUDIO_STATUS_PREPARING);

                    // Normal Control DVC & Ext.Amp & Ext. DSP
                    SysAudioOutputProc(_DISABLE);
                    ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    ScalerTimerDelayXms(3);
                    // RX Digital Audio Output Control
                    ScalerAudioDigitalOutputMute(_ON);
#endif

#if(_HDMI_SUPPORT == _ON)
                    if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
                    {
                        ScalerAudioHdmiI2sSpdifChannelOutputSelect(_AUDIO_DEFAULT_MODE, ScalerAudioGetDigitalAudioPortMapping());
                    }
#endif
                }
            }

            break;

#endif // End of #if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)

        case _AUDIO_STATUS_PLAYBACK:

            if(GET_AUDIO_STATE_CHANGE() == _TRUE)
            {
                CLR_AUDIO_STATE_CHANGE();
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(g_ucSearchIndex);
            }

            if(UserCommonInterfaceGetAudioReadyToPlayStatus() == _FALSE)
            {
#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
                if(GET_MODE_STATE() == _MODE_STATUS_ACTIVE)
                {
                    SysAudioChangeAudioState(_AUDIO_STATUS_PLAYBACK_CHECK);
                    DebugMessageAudio("Switch to Audio PlaybackCheck", _AUDIO_STATUS_PLAYBACK_CHECK);

                    // Fast Control DVC & Ext.Amp & Ext. DSP
                    SysAudioFastOutputProc(_DISABLE);

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

                    ScalerTimerDelayXms(3);
                    // RX Digital Audio Output Control
                    ScalerAudioDigitalOutputMute(_ON);
#endif
                }
                else
#endif
                {
                    SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
                    DebugMessageAudio("Switch to Audio Preparing", _AUDIO_STATUS_PREPARING);

                    // Normal Control DVC & Ext.Amp & Ext. DSP
                    SysAudioOutputProc(_DISABLE);

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    ScalerTimerDelayXms(3);
                    // RX Digital Audio Output Control
                    ScalerAudioDigitalOutputMute(_ON);
#endif
                }

                ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_HDMI_SUPPORT == _ON)
                if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
                {
                    ScalerAudioHdmiI2sSpdifChannelOutputSelect(_AUDIO_DEFAULT_MODE, ScalerAudioGetDigitalAudioPortMapping());
                }
#endif
            }

            break;

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
        case _AUDIO_STATUS_TTS_PLAYBACK:

            // Check if TTS fail when in playback
            if(ScalerAudioTtsPlaybackStableCheck() == _TRUE)
            {
                // Recover TTS
                ScalerAudioTtsRecoverProc();

                // Reset TTS
                ScalerAudioTtsResetProc();

                // Digital Audio Output DVC & Ext.Amp & Ext. DSP Control
                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);

                DebugMessageAudio("TTS Fail and Back to Audio Preparing", _AUDIO_STATUS_PREPARING);

                // Normal Control DVC & Ext.Amp & Ext. DSP
                SysAudioOutputProc(_DISABLE);

                ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                ScalerTimerDelayXms(3);
                // RX Digital Audio Output Control
                ScalerAudioDigitalOutputMute(_ON);
#endif
                // Update User Define Frequency When No Audio
                SysAudioSetUserDefineAudioFrequency();

                // Set User Define Frequency When No Audio except input port
                ScalerAudioSyncUserDefineFrequency();
            }

            // Check if TTS play done
            if(ScalerAudioTtsGetPlayDoneStatus() == _TRUE)
            {
                // Recover TTS
                ScalerAudioTtsRecoverProc();

                // Reset TTS
                ScalerAudioTtsResetProc();

                // Check Previous Audio State
                if(UserCommonInterfaceGetAudioReadyToPlayStatus() == _TRUE)
                {
                    DebugMessageAudio("TTS End and Back to Audio Playback", _AUDIO_STATUS_PLAYBACK);
                    SysAudioChangeAudioState(_AUDIO_STATUS_PLAYBACK);
                }
                else
                {
                    // Digital Audio Output DVC & Ext.Amp & Ext. DSP Control
                    SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);

                    DebugMessageAudio("TTS End and Back to Audio Preparing", _AUDIO_STATUS_PREPARING);

                    // Normal Control DVC & Ext.Amp & Ext. DSP
                    SysAudioOutputProc(_DISABLE);

                    ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                    ScalerTimerDelayXms(3);
                    // RX Digital Audio Output Control
                    ScalerAudioDigitalOutputMute(_ON);
#endif
                    // Update User Define Frequency When No Audio
                    SysAudioSetUserDefineAudioFrequency();

                    // Set User Define Frequency When No Audio except input port
                    ScalerAudioSyncUserDefineFrequency();
                }
            }

            break;

#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

        case _AUDIO_STATUS_POWER_OFF:
        default:
            break;
    }

#if(_SLEEP_AUDIO_SUPPORT == _ON)
    SysAudioSleepAudioHandler();
#endif
}

//--------------------------------------------------
// Description  : Get Current Audio
// Input Value  : None
// Output Value : Node
//--------------------------------------------------
EnumAudioState SysAudioGetAudioState(void)
{
    return GET_AUDIO_STATE();
}

//--------------------------------------------------
// Description  : Get Current Audio Backup Freq
// Input Value  : None
// Output Value : Node
//--------------------------------------------------
EnumAudioSamplingFreqPacket SysAudioGetAudioBackupFreq(void)
{
    return g_enumAudioFSBackup;
}

//--------------------------------------------------
// Description  : Audio Power Process
// Input Value  : None
// Output Value : Node
//--------------------------------------------------
void SysAudioPowerProc(EnumPowerAction enumSwitch)
{
    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            // Update User Define Frequency When No Audio
            SysAudioSetUserDefineAudioFrequency();

            SysAudioInitial();

            // Add User interface function
            UserInterfaceAdjustAudioPowerProc(_POWER_STATUS_NORMAL);

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
            UserInterfaceSwapExternalAudioCodecInput(ScalerAudioGetI2sOutputNeedToSwap(UserInterfaceGetAudioSource()));
#endif
            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);

            break;

        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_NORMAL_TO_FAKE_OFF:

            // Normal Control DVC & Ext.Amp & Ext. DSP
            SysAudioOutputProc(_DISABLE);

            // Reset Digital Audio
            ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

            // Add User interface function
            UserInterfaceAdjustAudioPowerProc(_POWER_STATUS_OFF);

            // Disable Audio
            ScalerAudioDisable();

            SysAudioChangeAudioState(_AUDIO_STATUS_POWER_OFF);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:

            // Normal Control DVC & Ext.Amp & Ext. DSP
            SysAudioOutputProc(_DISABLE);

            // Reset Digital Audio
            ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

            // Add User interface function
            UserInterfaceAdjustAudioPowerProc(_POWER_STATUS_SAVING);

            // Disable Audio
            ScalerAudioDisable();

            SysAudioChangeAudioState(_AUDIO_STATUS_POWER_OFF);

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Audio Mute Process
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void SysAudioMuteProc(bit bMute)
{
	if(bMute == _ON)
	{
		UserInterfaceAdjustAudioAmpMuteProc(_ON);

		ScalerAudioMuteProc(_ON, UserInterfaceGetAudioVolume());
	}
	else
	{
		ScalerAudioMuteProc(_OFF, UserInterfaceGetAudioVolume());

		UserInterfaceAdjustAudioAmpMuteProc(_OFF);
	}
}



#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio Fast Mute Process
// Input Value  : _ON => Mute On / EnumAudioState
// Output Value : None
//--------------------------------------------------
void SysAudioFastMuteProc(bit bMute)
{
    if(ScalerAudioDVCGetVolumeMuteStatus() == _ON)
    {
        return;
    }

    if(bMute == _ON)
    {
        UserInterfaceAdjustAudioAmpFastMuteProc(_ON);

        ScalerAudioDVCVolumeFastMute(_ON, UserInterfaceGetAudioVolume());
    }
    else
    {
        ScalerAudioDVCVolumeFastMute(_OFF, UserInterfaceGetAudioVolume());

        UserInterfaceAdjustAudioAmpFastMuteProc(_OFF);
    }
}
#endif

//--------------------------------------------------
// Description  : Audio Mute Process (Control DVC & Ext.Amp & Ext. DSP)
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void SysAudioOutputProc(bit bEnable)
{
    if(bEnable == _DISABLE)
    {
        SysAudioMuteProc(_ON);

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
        UserInterfaceAudioExternalCodecProc(_DISABLE);
#endif
    }
    else
    {
#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
        UserInterfaceAudioExternalCodecProc(_ENABLE);
#endif

        SysAudioMuteProc(_OFF);
    }
}

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio Mute Process (Control DVC & Ext.Amp & Ext. DSP)
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void SysAudioFastOutputProc(bit bEnable)
{
    if(bEnable == _DISABLE)
    {
        SysAudioFastMuteProc(_ON);

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
        UserInterfaceAudioExternalCodecFastProc(_DISABLE);
#endif
    }
    else
    {
#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
        UserInterfaceAudioExternalCodecFastProc(_ENABLE);
#endif

        SysAudioFastMuteProc(_OFF);
    }
}
#endif

//--------------------------------------------------
// Description  : Audio Analog Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioAnalogAudioHandler(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)

    if((ScalerAudioDACGetState() != _AUDIO_DAC_OFF) && (ScalerAudioDACGetState() != _AUDIO_DAC_INITIAL) && (ScalerAudioDACGetState() != _AUDIO_DAC_CHARGE))
    {
        // User want to change DAC Input / Output
        if((ScalerAudioGetAudioInputPortChanged(UserInterfaceGetAudioSource(), SysSourceGetInputPort()) == _TRUE) ||
           (ScalerAudioDACGetOutput() != UserInterfaceGetAudioDACOutput()))
        {
#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_LINE_IN_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            if(SysAudioGetSleepAudioStatusForLineIn() == _FALSE)
#endif
            {
                // Normal Control DVC & Ext.Amp & Ext. DSP
                SysAudioOutputProc(_DISABLE);

                ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                ScalerTimerDelayXms(3);
                // RX Digital Audio Output Control
                ScalerAudioDigitalOutputMute(_ON);
#endif
                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
            }

            if(ScalerAudioDACGetOutput() != UserInterfaceGetAudioDACOutput())
            {
                DebugMessageAudio("Audio Dac Switch Output", ScalerAudioDACGetOutput());

                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                ScalerAudioDACNormalToDepop();

                ScalerAudioDACSetVcmReady(_OFF);
                ScalerAudioDACSetState(_AUDIO_DAC_CHARGE);
            }
            else
            {
#if(_LINE_IN_SUPPORT == _ON)
                DebugMessageAudio("Audio Switch Input", ScalerAudioGetInputSource());
#endif

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_LINE_IN_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
                if(SysAudioGetSleepAudioStatusForLineIn() == _TRUE)
                {
                    ScalerAudioSourceInputSwitch(UserInterfaceGetAudioSource(), SysSourceGetInputPort());
                }
                else
#endif
                {
#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
                    if((GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE) || (GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_FIXED_PORT) ||
                       ((UserInterfaceGetAudioStandAloneStatus() == _TRUE) &&
                        (UserInterfaceGetAudioSource() == _DIGITAL_AUDIO) &&
                        (ScalerAudioGetDpStandaloneAudioStatus(SysSourceGetInputPort()) == _TRUE)))
#elif((_SLEEP_AUDIO_SUPPORT == _ON) && (_LINE_IN_SUPPORT == _ON) && (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN) && (_SWITCH_TO_LINE_IN_AUDIO_IN_POWER_SAVING_MODE == _ON))
                    if((GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE) || (GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_FIXED_PORT) ||
                       ((UserInterfaceGetAudioStandAloneStatus() == _TRUE) &&
                        (UserInterfaceGetAudioSource() == _LINE_IN_AUDIO) &&
                        (GET_MODE_STATE() == _MODE_STATUS_POWER_SAVING)))
#else
                    if((GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE) || (GET_SOURCE_SCAN_TYPE() == _SOURCE_SWITCH_FIXED_PORT))
#endif
                    {
                        ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                        ScalerAudioDACNormalToDepop();

                        ScalerAudioSourceInputSwitch(UserInterfaceGetAudioSource(), SysSourceGetInputPort());

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
                        UserInterfaceSwapExternalAudioCodecInput(ScalerAudioGetI2sOutputNeedToSwap(UserInterfaceGetAudioSource()));
#endif
                    }
                }
            }
        }
    }

    switch(ScalerAudioDACGetState())
    {
        case _AUDIO_DAC_OFF:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                ScalerAudioDACClrStateChange();
            }

            break;

        case _AUDIO_DAC_INITIAL:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                ScalerAudioDACClrStateChange();

                DebugMessageAudio("Audio Dac Initial", _AUDIO_DAC_INITIAL);

                ScalerTimerActiveTimerEvent(_DAC_VCM_INITIAL_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_INITIAL);
            }

            break;

        case _AUDIO_DAC_CHARGE:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                ScalerAudioDACClrStateChange();

                DebugMessageAudio("Audio Dac Charge", _AUDIO_DAC_CHARGE);

                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                ScalerTimerCancelTimerEvent(_SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE);

                ScalerAudioDACOutputSwitch(UserInterfaceGetAudioDACOutput());
                ScalerAudioDACSetVcmReady(_ON);

                ScalerTimerActiveTimerEvent(_DAC_VCM_CHARGE_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_VCM_CHARGE);
            }

            break;

        case _AUDIO_DAC_DEPOP:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                DebugMessageAudio("Audio Dac Depop", _AUDIO_DAC_DEPOP);

                if(UserInterfaceGetAudioDACKeepDepopState() == _FALSE)
                {
                    ScalerAudioDACClrStateChange();

                    ScalerAudioDACOutputEnable();

                    ScalerTimerActiveTimerEvent(_DAC_DEPOP_TO_NORMAL_WAIT_TIME, _SYSTEM_TIMER_EVENT_AUDIO_DAC_WAIT_DEPOP_TO_NORMAL);
                }
            }

            break;

        case _AUDIO_DAC_READY:

            if(ScalerAudioDACGetStateChange() == _TRUE)
            {
                ScalerAudioDACClrStateChange();

                DebugMessageAudio("Audio Dac Ready", _AUDIO_DAC_READY);
            }
            break;

        default:
            break;
    }

#else

    // Change Audio Input Port
    if(ScalerAudioGetAudioInputPortChanged(UserInterfaceGetAudioSource(), SysSourceGetInputPort()) == _TRUE)
    {
        // Normal Control DVC & Ext.Amp & Ext. DSP
        SysAudioOutputProc(_DISABLE);

        ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
        ScalerTimerDelayXms(3);
        // RX Digital Audio Output Mute
        ScalerAudioDigitalOutputMute(_ON);
#endif
        if(GET_SOURCE_JUDGE(g_ucSearchIndex) == _TRUE)
        {
            ScalerAudioSourceInputSwitch(UserInterfaceGetAudioSource(), SysSourceGetInputPort());

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
            UserInterfaceSwapExternalAudioCodecInput(ScalerAudioGetI2sOutputNeedToSwap(UserInterfaceGetAudioSource()));
#endif
        }

        SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
    }

#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : Digital Audio Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioDigitalAudioHandler(void)
{
#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _OFF)
    if(UserInterfaceAudioGetOutputMuteStatus() == _AUDIO_MUTE_ON)
    {
        ScalerAudioDigitalOutputMute(_ON);
    }
    else
    {
        ScalerAudioDigitalOutputMute(_OFF);
    }
#endif

    ScalerAudioDigitalDetect();

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    ScalerAudioSpdifChannelStatusProc(UserInterfaceGetAudioSource(), SysSourceGetInputPort());
#endif
}

//--------------------------------------------------
// Description  : Change Audio State
// Input Value  : Target Audio State
// Output Value : None
//--------------------------------------------------
void SysAudioChangeAudioState(EnumAudioState enumAudioState)
{
    SET_AUDIO_STATE(enumAudioState);
    SET_AUDIO_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Audio Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioInitial(void)
{
    ScalerAudioInitial();

    ScalerAudioSourceInputSwitch(UserInterfaceGetAudioSource(), SysSourceGetInputPort());

#if(_EMBEDDED_DAC_SUPPORT == _ON)

    ScalerAudioDACSetVcmReady(_ON);

    ScalerAudioDACSetState(_AUDIO_DAC_INITIAL);
#endif
}

//--------------------------------------------------
// Description  : Audio Frequency Set By User Define
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioSetUserDefineAudioFrequency(void)
{
    // get freq from userinterface
    EnumAudioSamplingFreqType enumAudioFreq = UserCommonInterfaceAudioUpdateUserSamplingFreq();

    ScalerAudioSetUserDefineAudioFrequency(enumAudioFreq);
}

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Audio Secondary Data Reset Process
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void SysAudioDpAudioSecDataResetProc(BYTE ucInputPort)
{
    if(ScalerAudioDPGetMuteProc(ucInputPort) == _TRUE)
    {
        // Normal Control DVC & Ext.Amp & Ext. DSP
        SysAudioOutputProc(_DISABLE);

        ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
        ScalerTimerDelayXms(3);
        // RX Digital Audio Output Mute
        ScalerAudioDigitalOutputMute(_ON);
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        ScalerAudioDACNormalToDepop();
#endif

        SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
    }

    ScalerDpSecDataReset(ucInputPort);
}
#endif

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio Fw Tracking Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioFwTrackingHandler(void)
{
    ScalerAudioFwTrackingHandler();
}
#endif


#if(_SLEEP_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Sleep Audio Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioSleepAudioHandler(void)
{
    if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
    {
        if(GET_AUDIO_STATE() == _AUDIO_STATUS_PREPARING)
        {
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if((UserInterfaceGetAudioSource() == _DIGITAL_AUDIO) &&
               (ScalerAudioGetDigitalAudioSource(SysSourceGetInputPort()) == _DIGITAL_AUDIO_SOURCE_DP))
            {
                SET_AUDIO_PLAYBACK_SEARCH_INDEX(g_ucSearchIndex);

                ScalerAudioDpAudioEnable(_ENABLE, SysSourceGetInputPort());

                DebugMessageAudio("Sleep Audio Playback Index", GET_AUDIO_PLAYBACK_SEARCH_INDEX());
            }
#endif

#if((_LINE_IN_SUPPORT == _ON) && (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN) && (_SWITCH_TO_LINE_IN_AUDIO_IN_POWER_SAVING_MODE == _ON))
            SET_AUDIO_PLAYING_ALONE();

            return;
#endif
        }
        else if(GET_AUDIO_STATE() == _AUDIO_STATUS_PLAYBACK)
        {
#if((_LINE_IN_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            if(UserInterfaceGetAudioSource() == _LINE_IN_AUDIO)
            {
                SET_AUDIO_PLAYING_ALONE();

                return;
            }
#endif

#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if((UserInterfaceGetAudioSource() == _DIGITAL_AUDIO) && (ScalerAudioGetDigitalAudioSource(SysSourceGetInputPort()) == _DIGITAL_AUDIO_SOURCE_DP))
            {
                SET_AUDIO_PLAYING_ALONE();

                return;
            }
#endif
        }
    }

    CLR_AUDIO_PLAYING_ALONE();
}

#if((_LINE_IN_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
//--------------------------------------------------
// Description  : Get Sleep Audio Changed for Line in
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit SysAudioGetSleepAudioStatusForLineIn(void)
{
    return ((UserInterfaceGetAudioSource() == _LINE_IN_AUDIO) && (ScalerAudioGetInputSource() == _LINE_IN_AUDIO) && (GET_AUDIO_PLAYING_ALONE() == _TRUE));
}
#endif
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Internal Audio Gen Test Process
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void SysAudioInternalGenTestProc(bit bOn)
{
    EnumSourceSearchPort enumInputPort = SysSourceGetInputPort();

    // Normal Control DVC & Ext.Amp & Ext. DSP
    SysAudioOutputProc(_DISABLE);

    if(bOn == _ON)
    {
        ScalerAudioSetInternalGenInputPort(enumInputPort);

        ScalerAudioSetUserDefineAudioGenFrequency(UserCommonAudioUpdateUserDefineAudioGenFreq());

        ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

        ScalerAudioInternalAudioGenSwitch(_ON, enumInputPort, UserCommonAudioGetUserLeftRightChanelSelect());

        ScalerAudioSourceInputSwitch(_DIGITAL_AUDIO, enumInputPort);

        ScalerAudioDigitalVolumeMute(_OFF, UserInterfaceGetAudioVolume());
    }
    else
    {
        EnumSourceSearchPort enumGenPort = ScalerAudioGetInternalGenInputPort();

        ScalerAudioInternalAudioGenSwitch(_OFF, enumGenPort, _AUDIO_LEFT_RIGHT_CHANNEL);

        ScalerAudioSourceInputSwitch(_DIGITAL_AUDIO, enumInputPort);

        ScalerAudioInternalAudioGenReset(enumGenPort);

        SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
    }
}
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
//--------------------------------------------------
// Description  : Check TTS Playback Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAudioTtsCheckPlaybackAcitveEvent(void)
{
    // Check whether TTS Playback event happens
    if(ScalerAudioTtsGetPlaybackEvent() == _TRUE)
    {
        DebugMessageAudio("[TTS] Playback Event Active", 0x00);

        // TTS Config
        ScalerAudioTtsPlayConfig();

        // Clear Flag
        ScalerAudioTtsSetPlaybackEvent(_DISABLE);

        // Change Audio State
        SysAudioChangeAudioState(_AUDIO_STATUS_TTS_PLAYBACK);

        DebugMessageAudio("     -> Audio State swtich to TTS_Playback", 0x00);
    }
}
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#endif // End of #if(_AUDIO_SUPPORT == _ON)
