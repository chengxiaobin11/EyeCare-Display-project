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
// ID Code      : RL6463_Series_AudioInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//----------------------------------------------------------------------------
// Definition of VCO Frequency of Audio PLL With Frequency Up
//----------------------------------------------------------------------------
#define _AUDIO_PLL_VCO                                378000 // 1KHz,

//----------------------------------------------------------------------------
// Definition of Offset of Audio PLL With Path1 and Frequency Up
//----------------------------------------------------------------------------
#define _HDMI_SAMPLING_FREQ_32K_GROUP_D_CODE          0xC868
#define _HDMI_SAMPLING_FREQ_44K_GROUP_D_CODE          0x1E48
#define _HDMI_SAMPLING_FREQ_48K_GROUP_D_CODE          0xC868

#define _DP_SAMPLING_FREQ_32K_GROUP_D_CODE            0x398A
#define _DP_SAMPLING_FREQ_44K_GROUP_D_CODE            0xE1AE
#define _DP_SAMPLING_FREQ_48K_GROUP_D_CODE            0x398A

#define GET_AUDIO_D0_ICODE_RELOADED()                 (bit)(g_stAudioD0DigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_D0_ICODE_RELOADED()                 (g_stAudioD0DigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_D0_ICODE_RELOADED()                 (g_stAudioD0DigtalInfo.b1AudioICodeReloaded = _FALSE)

#define GET_AUDIO_D0_SAMPLING_FREQ()                  (g_stAudioD0DigtalInfo.b4AudioSamplingFreq)
#define SET_AUDIO_D0_SAMPLING_FREQ(x)                 (g_stAudioD0DigtalInfo.b4AudioSamplingFreq = (x))

#define GET_AUDIO_D0_PACKET_DETECT()                  (bit)(g_stAudioD0DigtalInfo.b1AudioDetected)
#define SET_AUDIO_D0_PACKET_DETECT()                  (g_stAudioD0DigtalInfo.b1AudioDetected = _TRUE)
#define CLR_AUDIO_D0_PACKET_DETECT()                  (g_stAudioD0DigtalInfo.b1AudioDetected = _FALSE)

#define GET_D0_DIGITAL_AUDIO_SOURCE()                 (g_stAudioD0DigtalInfo.b2AudioDigitalSource)
#define SET_D0_DIGITAL_AUDIO_SOURCE(x)                (g_stAudioD0DigtalInfo.b2AudioDigitalSource = (x))

#define GET_REG_D0_MAC_SWITCH_TO_HDMI()               (ScalerGetBit(PB_00_HD_DP_SEL, _BIT0) == _BIT0)

#define GET_AUDIO_CURRENT_MAC_TYPE()                  (g_stAudioD0DigtalInfo.b1AudioCurrentMAC)
#define SET_AUDIO_CURRENT_MAC_TYPE(x)                 (g_stAudioD0DigtalInfo.b1AudioCurrentMAC = (x))

#define SET_AUDIO_PLL_SOURCE_MUX()                    {\
                                                          ScalerSetBit(P2_AB_TMDS_ACC2, ~_BIT0, ((GET_REG_D0_MAC_SWITCH_TO_HDMI() == _TRUE) ? _BIT0 : 0x00));\
                                                          if(ScalerGetBit(P2_AB_TMDS_ACC2, _BIT0) == _BIT0)\
                                                          {\
                                                              ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_10_PORT_PAGE2_HDMI_CMCR, ~_BIT4, _BIT4);\
                                                          }\
                                                          else\
                                                          {\
                                                              if(ScalerGetBit(PB6_74_AUD_FSM_CTRL_0, _BIT7) == _BIT7)\
                                                              {\
                                                                  ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, 0x00);\
                                                                  ScalerSetBit(PB6_74_AUD_FSM_CTRL_0, ~_BIT7, _BIT7);\
                                                              }\
                                                          }\
                                                      }

#define SET_AUDIO_HDMI_TRACKING_BOUNDARY_DISTANCE()   {\
                                                          ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_1B_PORT_PAGE2_HDMI_FBR, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));\
                                                      }

#define GET_AUDIO_D0_AUTO_LOAD_FREQ()                 (g_stAudioD0FreqParameter.b1AutoLoad)
#define SET_AUDIO_D0_AUTO_LOAD_FREQ()                 (g_stAudioD0FreqParameter.b1AutoLoad = _TRUE)
#define CLR_AUDIO_D0_AUTO_LOAD_FREQ()                 (g_stAudioD0FreqParameter.b1AutoLoad = _FALSE)

#define GET_D0_SAMPLING_FREQ_USER_DEFINE()            (g_stAudioD0FreqParameter.ucAudioFs)
#define SET_D0_SAMPLING_FREQ_USER_DEFINE(x)           (g_stAudioD0FreqParameter.ucAudioFs = (x))

#define GET_DP_D0_AUDIO_CODING_TYPE_FORMAT()          (g_stDpAudioD0CodingType.enumAudioCodingType)
#define SET_DP_D0_AUDIO_CODING_TYPE_FORMAT(x)         (g_stDpAudioD0CodingType.enumAudioCodingType = (x))

#define GET_DP_D0_AUDIO_CODING_TYPE_CHANGE()          (g_stDpAudioD0CodingType.b1AudioCodingTypeChange)
#define SET_DP_D0_AUDIO_CODING_TYPE_CHANGE()          (g_stDpAudioD0CodingType.b1AudioCodingTypeChange = _TRUE)
#define CLR_DP_D0_AUDIO_CODING_TYPE_CHANGE()          (g_stDpAudioD0CodingType.b1AudioCodingTypeChange = _FALSE)

#define GET_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()        (g_stAudioD0FreqParameter.b1SamplingFreqChange)
#define SET_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()        (g_stAudioD0FreqParameter.b1SamplingFreqChange = _TRUE)
#define CLR_DP_D0_AUDIO_SAMPLING_FREQ_CHANGE()        (g_stAudioD0FreqParameter.b1SamplingFreqChange = _FALSE)

//--------------------------------------------------
// Definitions of Audio DP Capability info
//--------------------------------------------------
#define GET_AUDIO_DP_D0_CAPABILITY_SWITCH()           (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch)
#define SET_AUDIO_DP_D0_CAPABILITY_SWITCH()           (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch = _TRUE)
#define CLR_AUDIO_DP_D0_CAPABILITY_SWITCH()           (g_stAudioDpCapabilityInfo.b1DpD0CapabilitySwitch = _FALSE)

#define GET_AUDIO_DP_D0_SUPPORT()                     (g_stAudioDpCapabilityInfo.b1DpD0Support)
#define SET_AUDIO_DP_D0_SUPPORT(x)                    (g_stAudioDpCapabilityInfo.b1DpD0Support = (x))

#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
#define GET_AUDIO_D0_FW_TRACKING_STATE()              (g_stHDMID0AudioFwTrackingInfo.b2AudioFwTrackState)
#define SET_AUDIO_D0_FW_TRACKING_STATE(x)             (g_stHDMID0AudioFwTrackingInfo.b2AudioFwTrackState = (x))

#define GET_AUDIO_D0_FW_TRACKING_EVENT()              (bit)(g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackEventStatus)
#define SET_AUDIO_D0_FW_TRACKING_EVENT()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _TRUE)
#define CLR_AUDIO_D0_FW_TRACKING_EVENT()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackEventStatus = _FALSE)

#define GET_AUDIO_D0_FW_TRACKING_TIMEOUT()            (bit)(g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent)
#define SET_AUDIO_D0_FW_TRACKING_TIMEOUT()            (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _TRUE)
#define CLR_AUDIO_D0_FW_TRACKING_TIMEOUT()            (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackTimeoutEvent = _FALSE)

#define GET_AUDIO_D0_FW_TRACKING_RESET()              (bit)(g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset)
#define SET_AUDIO_D0_FW_TRACKING_RESET()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset = _TRUE)
#define CLR_AUDIO_D0_FW_TRACKING_RESET()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset = _FALSE)

#define GET_AUDIO_D0_FW_TRACKING_RESET()              (bit)(g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset)
#define SET_AUDIO_D0_FW_TRACKING_RESET()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset = _TRUE)
#define CLR_AUDIO_D0_FW_TRACKING_RESET()              (g_stHDMID0AudioFwTrackingInfo.b1AudioFwTrackReset = _FALSE)

#define GET_AUDIO_D0_WL_TARGET_DIRECTION()            (g_stHDMID0AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection)
#define SET_AUDIO_D0_WL_TARGET_DIRECTION(x)           (g_stHDMID0AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = (x))
#define CLR_AUDIO_D0_WL_TARGET_DIRECTION()            (g_stHDMID0AudioFwTrackingInfo.b2AudioWaterLevelTargetDirection = _AUDIO_WL_GOES_UNKNOWN)
#endif

//--------------------------------------------------
// Macros of Audio Internal Gen
//--------------------------------------------------
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#define GET_AUDIO_INTERNAL_GEN_INPUT_PORT()           (BYTE)(g_ucAudioGenInputPort)
#define SET_AUDIO_INTERNAL_GEN_INPUT_PORT(x)          (g_ucAudioGenInputPort = (x))
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

    EnumAudioDpDpcdSupport b1DpD0Support : 1;
} StructAudioDpCapabilityInfo;
#endif // End of #if(_DP_SUPPORT == _ON)


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructAudioDigitalInfo g_stAudioD0DigtalInfo;
extern StructAudioFreqParameter g_stAudioD0FreqParameter;
extern StructAudioDpCodingType g_stDpAudioD0CodingType;

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern StructAudioFwTrackingInfo g_stHDMID0AudioFwTrackingInfo;
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
extern EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
extern bit ScalerAudioSamplingFreqChange(void);
extern void ScalerAudioLPCMDetectEnableProc(BYTE ucInputPort);
extern void ScalerAudioLPCMResetProc(BYTE ucInputPort);
extern void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort);
extern void ScalerAudioHbrModeControl(bit bOn, BYTE ucInputPort);
extern EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
#endif

#if(_DP_SUPPORT == _ON)
extern void ScalerAudioDPDigitalOutputProc(bit bEnable, BYTE ucInputPort);
extern void ScalerAudioDpAudioEnable(bit bEnable, BYTE ucInputPort);
extern void ScalerAudioDpAudioEnable_EXINT0(bit bEnable, BYTE ucInputPort);
extern bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);
#endif

extern BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
#endif
#endif // End of #if(_AUDIO_SUPPORT == _ON)

