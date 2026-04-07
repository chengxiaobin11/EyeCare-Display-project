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
// ID Code      : RL6449_Series_AudioInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
#define GET_AUDIO_D0_ICODE_RELOADED()               (bit)(g_stAudioD0DigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_D0_ICODE_RELOADED()               (g_stAudioD0DigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_D0_ICODE_RELOADED()               (g_stAudioD0DigtalInfo.b1AudioICodeReloaded = _FALSE)

#define GET_AUDIO_D0_SAMPLING_FREQ()                (g_stAudioD0DigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_D0_SAMPLING_FREQ(x)               (g_stAudioD0DigtalInfo.b4AudioSamplingFreq = (x))

#define GET_AUDIO_D0_PACKET_DETECT()                (bit)(g_stAudioD0DigtalInfo.b1AudioDetected)
#define SET_AUDIO_D0_PACKET_DETECT()                (g_stAudioD0DigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_D0_PACKET_DETECT()                (g_stAudioD0DigtalInfo.b1AudioDetected = _FALSE)

#define GET_D0_DIGITAL_AUDIO_SOURCE()               (g_stAudioD0DigtalInfo.b2AudioDigitalSource)
#define SET_D0_DIGITAL_AUDIO_SOURCE(x)              (g_stAudioD0DigtalInfo.b2AudioDigitalSource = (x))

#define GET_AUDIO_D0_AUTO_LOAD_FREQ()               (g_stAudioD0FreqParameter.b1AutoLoad)
#define SET_AUDIO_D0_AUTO_LOAD_FREQ()               (g_stAudioD0FreqParameter.b1AutoLoad = _TRUE)
#define CLR_AUDIO_D0_AUTO_LOAD_FREQ()               (g_stAudioD0FreqParameter.b1AutoLoad = _FALSE)

#define GET_D0_SAMPLING_FREQ_USER_DEFINE()          (g_stAudioD0FreqParameter.ucAudioFs)
#define SET_D0_SAMPLING_FREQ_USER_DEFINE(x)         (g_stAudioD0FreqParameter.ucAudioFs = (x))

#define GET_DP_D0_AUDIO_CODING_TYPE_FORMAT()        (g_stDpAudioD0CodingType.enumAudioCodingType)
#define SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(x)       (g_stDpAudioD0CodingType.enumAudioCodingType = (x))

#define GET_DP_D0_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD0CodingType.b1AudioCodingTypeChange)
#define SET_DP_D0_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD0CodingType.b1AudioCodingTypeChange = _TRUE)
#define CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD0CodingType.b1AudioCodingTypeChange = _FALSE)

#define GET_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD0FreqParameter.b1SamplingFreqChange)
#define SET_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD0FreqParameter.b1SamplingFreqChange = _TRUE)
#define CLR_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD0FreqParameter.b1SamplingFreqChange = _FALSE)

//--------------------------------------------------
// Definitions of Audio DP Capability info
//--------------------------------------------------
#define GET_AUDIO_DP_D0_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch)
#define SET_AUDIO_DP_D0_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch = _TRUE)
#define CLR_AUDIO_DP_D0_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch = _FALSE)

#define GET_AUDIO_DP_D0_SUPPORT()                   (g_stAudioDpCapabilityInfo.b1DpD0Support)
#define SET_AUDIO_DP_D0_SUPPORT(x)                  (g_stAudioDpCapabilityInfo.b1DpD0Support = (x))
#endif

#if(_D1_DP_EXIST == _ON)
#define GET_AUDIO_D1_ICODE_RELOADED()               (bit)(g_stAudioD1DigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_D1_ICODE_RELOADED()               (g_stAudioD1DigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_D1_ICODE_RELOADED()               (g_stAudioD1DigtalInfo.b1AudioICodeReloaded = _FALSE)

#define GET_AUDIO_D1_SAMPLING_FREQ()                (g_stAudioD1DigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_D1_SAMPLING_FREQ(x)               (g_stAudioD1DigtalInfo.b4AudioSamplingFreq = (x))

#define GET_AUDIO_D1_PACKET_DETECT()                (bit)(g_stAudioD1DigtalInfo.b1AudioDetected)
#define SET_AUDIO_D1_PACKET_DETECT()                (g_stAudioD1DigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_D1_PACKET_DETECT()                (g_stAudioD1DigtalInfo.b1AudioDetected = _FALSE)

#define GET_D1_DIGITAL_AUDIO_SOURCE()               (g_stAudioD1DigtalInfo.b2AudioDigitalSource)
#define SET_D1_DIGITAL_AUDIO_SOURCE(x)              (g_stAudioD1DigtalInfo.b2AudioDigitalSource = (x))

#define GET_AUDIO_D1_AUTO_LOAD_FREQ()               (g_stAudioD1FreqParameter.b1AutoLoad)
#define SET_AUDIO_D1_AUTO_LOAD_FREQ()               (g_stAudioD1FreqParameter.b1AutoLoad = _TRUE)
#define CLR_AUDIO_D1_AUTO_LOAD_FREQ()               (g_stAudioD1FreqParameter.b1AutoLoad = _FALSE)

#define GET_D1_SAMPLING_FREQ_USER_DEFINE()          (g_stAudioD1FreqParameter.ucAudioFs)
#define SET_D1_SAMPLING_FREQ_USER_DEFINE(x)         (g_stAudioD1FreqParameter.ucAudioFs = (x))

#define GET_DP_D1_AUDIO_CODING_TYPE_FORMAT()        (g_stDpAudioD1CodingType.enumAudioCodingType)
#define SET_DP_D1_AUDIO_CODING_TYPE_FORMAT(x)       (g_stDpAudioD1CodingType.enumAudioCodingType = (x))

#define GET_DP_D1_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD1CodingType.b1AudioCodingTypeChange)
#define SET_DP_D1_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD1CodingType.b1AudioCodingTypeChange = _TRUE)
#define CLR_DP_D1_AUDIO_CODING_TYPE_CHANGE()        (g_stDpAudioD1CodingType.b1AudioCodingTypeChange = _FALSE)

#define GET_DP_D1_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD1FreqParameter.b1SamplingFreqChange)
#define SET_DP_D1_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD1FreqParameter.b1SamplingFreqChange = _TRUE)
#define CLR_DP_D1_AUDIO_SAMPLING_FREQ_CHANGE()      (g_stAudioD1FreqParameter.b1SamplingFreqChange = _FALSE)

//--------------------------------------------------
// Definitions of Audio DP Capability info
//--------------------------------------------------
#define GET_AUDIO_DP_D1_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD1CapabilitySwitch)
#define SET_AUDIO_DP_D1_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD1CapabilitySwitch = _TRUE)
#define CLR_AUDIO_DP_D1_CAPABILITY_SWITCH()         (g_stAudioDpCapabilityInfo.b1DpD1CapabilitySwitch = _FALSE)

#define GET_AUDIO_DP_D1_SUPPORT()                   (g_stAudioDpCapabilityInfo.b1DpD1Support)
#define SET_AUDIO_DP_D1_SUPPORT(x)                  (g_stAudioDpCapabilityInfo.b1DpD1Support = (x))
#endif

#if(_D2_HDMI_SUPPORT == _ON)
#define GET_AUDIO_D2_ICODE_RELOADED()               (bit)(g_stAudioD2DigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_D2_ICODE_RELOADED()               (g_stAudioD2DigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_D2_ICODE_RELOADED()               (g_stAudioD2DigtalInfo.b1AudioICodeReloaded = _FALSE)

#define GET_AUDIO_D2_SAMPLING_FREQ()                (g_stAudioD2DigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_D2_SAMPLING_FREQ(x)               (g_stAudioD2DigtalInfo.b4AudioSamplingFreq = (x))

#define GET_AUDIO_D2_PACKET_DETECT()                (bit)(g_stAudioD2DigtalInfo.b1AudioDetected)
#define SET_AUDIO_D2_PACKET_DETECT()                (g_stAudioD2DigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_D2_PACKET_DETECT()                (g_stAudioD2DigtalInfo.b1AudioDetected = _FALSE)

#define GET_D2_DIGITAL_AUDIO_SOURCE()               (g_stAudioD2DigtalInfo.b2AudioDigitalSource)
#define SET_D2_DIGITAL_AUDIO_SOURCE(x)              (g_stAudioD2DigtalInfo.b2AudioDigitalSource = (x))

#define GET_AUDIO_D2_AUTO_LOAD_FREQ()               (g_stAudioD2FreqParameter.b1AutoLoad)
#define SET_AUDIO_D2_AUTO_LOAD_FREQ()               (g_stAudioD2FreqParameter.b1AutoLoad = _TRUE)
#define CLR_AUDIO_D2_AUTO_LOAD_FREQ()               (g_stAudioD2FreqParameter.b1AutoLoad = _FALSE)

#define GET_D2_SAMPLING_FREQ_USER_DEFINE()          (g_stAudioD2FreqParameter.ucAudioFs)
#define SET_D2_SAMPLING_FREQ_USER_DEFINE(x)         (g_stAudioD2FreqParameter.ucAudioFs = (x))

#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
#define GET_AUDIO_D2_FW_TRACKING_STATE()            (g_stHDMID2AudioFwTrackingInfo.b2AudioFwTrackState)
#define SET_AUDIO_D2_FW_TRACKING_STATE(x)           (g_stHDMID2AudioFwTrackingInfo.b2AudioFwTrackState = (x))

#define GET_AUDIO_D2_FW_TRACKING_EVENT()            (bit)(g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackEventStatus)
#define SET_AUDIO_D2_FW_TRACKING_EVENT()            (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _TRUE)
#define CLR_AUDIO_D2_FW_TRACKING_EVENT()            (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _FALSE)

#define GET_AUDIO_D2_FW_TRACKING_TIMEOUT()          (bit)(g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent)
#define SET_AUDIO_D2_FW_TRACKING_TIMEOUT()          (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _TRUE)
#define CLR_AUDIO_D2_FW_TRACKING_TIMEOUT()          (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _FALSE)

#define GET_AUDIO_D2_FW_TRACKING_RESET()            (bit)(g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackReset)
#define SET_AUDIO_D2_FW_TRACKING_RESET()            (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackReset = _TRUE)
#define CLR_AUDIO_D2_FW_TRACKING_RESET()            (g_stHDMID2AudioFwTrackingInfo.b1AudioFwTrackReset = _FALSE)

#define GET_AUDIO_D2_WL_TARGET_DIRECTION()          (g_stHDMID2AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection)
#define SET_AUDIO_D2_WL_TARGET_DIRECTION(x)         (g_stHDMID2AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = (x))
#define CLR_AUDIO_D2_WL_TARGET_DIRECTION()          (g_stHDMID2AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = _AUDIO_WL_GOES_UNKNOWN)
#endif
#endif

#if(_D3_HDMI_SUPPORT == _ON)
#define GET_AUDIO_D3_ICODE_RELOADED()               (bit)(g_stAudioD3DigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_D3_ICODE_RELOADED()               (g_stAudioD3DigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_D3_ICODE_RELOADED()               (g_stAudioD3DigtalInfo.b1AudioICodeReloaded = _FALSE)

#define GET_AUDIO_D3_SAMPLING_FREQ()                (g_stAudioD3DigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_D3_SAMPLING_FREQ(x)               (g_stAudioD3DigtalInfo.b4AudioSamplingFreq = (x))

#define GET_AUDIO_D3_PACKET_DETECT()                (bit)(g_stAudioD3DigtalInfo.b1AudioDetected)
#define SET_AUDIO_D3_PACKET_DETECT()                (g_stAudioD3DigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_D3_PACKET_DETECT()                (g_stAudioD3DigtalInfo.b1AudioDetected = _FALSE)

#define GET_D3_DIGITAL_AUDIO_SOURCE()               (g_stAudioD3DigtalInfo.b2AudioDigitalSource)
#define SET_D3_DIGITAL_AUDIO_SOURCE(x)              (g_stAudioD3DigtalInfo.b2AudioDigitalSource = (x))

#define GET_AUDIO_D3_AUTO_LOAD_FREQ()               (g_stAudioD3FreqParameter.b1AutoLoad)
#define SET_AUDIO_D3_AUTO_LOAD_FREQ()               (g_stAudioD3FreqParameter.b1AutoLoad = _TRUE)
#define CLR_AUDIO_D3_AUTO_LOAD_FREQ()               (g_stAudioD3FreqParameter.b1AutoLoad = _FALSE)

#define GET_D3_SAMPLING_FREQ_USER_DEFINE()          (g_stAudioD3FreqParameter.ucAudioFs)
#define SET_D3_SAMPLING_FREQ_USER_DEFINE(x)         (g_stAudioD3FreqParameter.ucAudioFs = (x))

#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
#define GET_AUDIO_D3_FW_TRACKING_STATE()            (g_stHDMID3AudioFwTrackingInfo.b2AudioFwTrackState)
#define SET_AUDIO_D3_FW_TRACKING_STATE(x)           (g_stHDMID3AudioFwTrackingInfo.b2AudioFwTrackState = (x))

#define GET_AUDIO_D3_FW_TRACKING_EVENT()            (bit)(g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackEventStatus)
#define SET_AUDIO_D3_FW_TRACKING_EVENT()            (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _TRUE)
#define CLR_AUDIO_D3_FW_TRACKING_EVENT()            (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _FALSE)

#define GET_AUDIO_D3_FW_TRACKING_TIMEOUT()          (bit)(g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent)
#define SET_AUDIO_D3_FW_TRACKING_TIMEOUT()          (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _TRUE)
#define CLR_AUDIO_D3_FW_TRACKING_TIMEOUT()          (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _FALSE)

#define GET_AUDIO_D3_FW_TRACKING_RESET()            (bit)(g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackReset)
#define SET_AUDIO_D3_FW_TRACKING_RESET()            (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackReset = _TRUE)
#define CLR_AUDIO_D3_FW_TRACKING_RESET()            (g_stHDMID3AudioFwTrackingInfo.b1AudioFwTrackReset = _FALSE)

#define GET_AUDIO_D3_WL_TARGET_DIRECTION()          (g_stHDMID3AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection)
#define SET_AUDIO_D3_WL_TARGET_DIRECTION(x)         (g_stHDMID3AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = (x))
#define CLR_AUDIO_D3_WL_TARGET_DIRECTION()          (g_stHDMID3AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = _AUDIO_WL_GOES_UNKNOWN)
#endif
#endif

//--------------------------------------------------
// Macros of Audio Internal Gen
//--------------------------------------------------
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#define GET_AUDIO_INTERNAL_GEN_INPUT_PORT()         (BYTE)(g_ucAudioGenInputPort)
#define SET_AUDIO_INTERNAL_GEN_INPUT_PORT(x)        (g_ucAudioGenInputPort = (x))
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Struct for DP Audio Support
//--------------------------------------------------
typedef struct
{
    BYTE b1DpD0CapabilitySwitch : 1;
    BYTE b1DpD1CapabilitySwitch : 1;

    EnumAudioDpDpcdSupport b1DpD0Support : 1;
    EnumAudioDpDpcdSupport b1DpD1Support : 1;
} StructAudioDpCapabilityInfo;
#endif // End of #if(_DP_SUPPORT == _ON)


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
extern StructAudioDigitalInfo g_stAudioD0DigtalInfo;
extern StructAudioFreqParameter g_stAudioD0FreqParameter;
extern StructAudioDpCodingType g_stDpAudioD0CodingType;
#endif

#if(_D1_DP_EXIST == _ON)
extern StructAudioDigitalInfo g_stAudioD1DigtalInfo;
extern StructAudioFreqParameter g_stAudioD1FreqParameter;
extern StructAudioDpCodingType g_stDpAudioD1CodingType;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
extern StructAudioDigitalInfo g_stAudioD2DigtalInfo;
extern StructAudioFreqParameter g_stAudioD2FreqParameter;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern StructAudioFwTrackingInfo g_stHDMID2AudioFwTrackingInfo;
#endif
#endif

#if(_D3_HDMI_SUPPORT == _ON)
extern StructAudioDigitalInfo g_stAudioD3DigtalInfo;
extern StructAudioFreqParameter g_stAudioD3FreqParameter;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern StructAudioFwTrackingInfo g_stHDMID3AudioFwTrackingInfo;
#endif
#endif

#if(_DP_SUPPORT == _ON)
extern StructAudioDpCapabilityInfo g_stAudioDpCapabilityInfo;
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern BYTE g_ucAudioGenInputPort;
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerAudioDigitalAudioInitial(void);
extern void ScalerAudioDisableAudioPLL(void);
extern void ScalerAudioDigitalReset(BYTE ucInputPort);
extern EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
extern bit ScalerAudioSamplingFreqChange(void);
extern void ScalerAudioDigitalOutputMute(bit bMute);
extern void ScalerAudioLoadStableICodeEvent(EnumScalerTimerEventID enumEventID);
extern EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioFwTrackingEventSet(EnumScalerTimerEventID enumEventID);
extern void ScalerAudioTimeoutEventSet(EnumScalerTimerEventID enumEventID);
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_D2_HDMI_SUPPORT == _ON)
extern EnumAudioSamplingFreqType ScalerAudioD2SamplingFreqDetect(void);
#endif

extern void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
#endif

#if(_DP_SUPPORT == _ON)
extern bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);

#if(_D0_DP_EXIST == _ON)
extern void ScalerAudioD0SetAudioPLL(void);
#endif

#if(_D1_DP_EXIST == _ON)
extern void ScalerAudioD1SetAudioPLL(void);
#endif
#endif

extern BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

#if(_DP_TX_SUPPORT == _ON)
extern StructAudioChannelInfo ScalerAudioGetRxChannelStatus(void);
#endif // End of #if(_DP_TX_SUPPORT == _ON)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
#endif
#endif // End of #if(_AUDIO_SUPPORT == _ON)
