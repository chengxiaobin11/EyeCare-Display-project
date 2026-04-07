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
// ID Code      : RL6851_Series_AudioInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern bit ScalerAudioGetAudioDetected(BYTE ucInputPort);
extern EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
extern bit ScalerAudioSamplingFreqChange(void);
extern bit ScalerAudioLPCMCheckData(void);
extern bit ScalerAudioLPCMCheckChange(void);
extern void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort);
extern EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
extern bit ScalerAudioLPCMCheckInfo(void);
extern EnumSourceTypeDef ScalerAudioDigitalAudioSourceType(void);
#endif

#if(_DP_SUPPORT == _ON)
extern bit ScalerAudioDPGetMuteProc(BYTE ucInputPort);
extern void ScalerAudioDpAudioEnable(bit bEnable, BYTE ucInputPort);
extern bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);
#endif

extern BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

#if(_SLEEP_AUDIO_SUPPORT == _ON)
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern bit ScalerAudioGetDpStandaloneAudioStatus(BYTE ucInputPort);
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
#endif
#endif

#if(_LINE_IN_SUPPORT == _ON)
extern void ScalerAudioADCInitial(void);
#endif

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern void ScalerAudioInternalAudioGenSwitch(bit bOn, BYTE ucInputPort, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
extern bit ScalerAudioGetInternalAudioGenEnable(BYTE ucInputPort);
extern void ScalerAudioInternalAudioGenReset(BYTE ucInputPort);
extern void ScalerAudioSetInternalGenInputPort(BYTE ucInputPort);
extern BYTE ScalerAudioGetInternalGenInputPort(void);
#endif

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
extern void ScalerAudioTtsResetProc(void);
extern void ScalerAudioTtsRecoverProc(void);
extern bit ScalerAudioTtsPlaybackStableCheck(void);
extern bit ScalerAudioTtsGetPlayDoneStatus(void);
extern void ScalerAudioTtsPlayConfig(void);
extern void ScalerAudioTtsDvcGainControl(WORD usTtsVolume, WORD usAudioVolume);
extern void ScalerAudioTtsSpicReset(void);
extern bit ScalerAudioTtsGetCommandData(StructAudioTtsSegment *pstAudioTtsSegment, BYTE ucSegmentSize);
extern void ScalerAudioTtsUpsamplingControl(bit bEn);
extern void ScalerAudioTtsUpsamplingSetFrequency(void);
extern void ScalerAudioTtsPlayDoneDetect(bit bEn);
extern void ScalerAudioTtsIntHandler_EXINT0(void);
extern bit ScalerAudioTtsGetPlaybackEvent(void);
extern void ScalerAudioTtsSetPlaybackEvent(bit bEn);
extern void ScalerAudioTtsSetTimerEvent(bit bEn);
extern void ScalerAudioTtsClearFlag(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

