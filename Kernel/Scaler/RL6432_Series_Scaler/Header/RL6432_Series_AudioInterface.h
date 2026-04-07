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
// ID Code      : RL6432_Series_AudioInterface.h No.0000
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
extern void ScalerAudioDigitalDetect(void);
extern void ScalerAudioDigitalEnable(BYTE ucInputPort);
extern void ScalerAudioDigitalReset(BYTE ucInputPort);
extern bit ScalerAudioGetAudioDetected(BYTE ucInputPort);
extern EnumAudioSamplingFreqPacket ScalerAudioSamplingFreqDetect(BYTE ucInputPort);
extern bit ScalerAudioSamplingFreqChange(void);
extern bit ScalerAudioLPCMCheckData(void);
extern bit ScalerAudioLPCMCheckChange(void);
extern void ScalerAudioDigitalOutputMute(bit bMute);
extern void ScalerAudioSourceInputSwitch(EnumAudioInputSource enumAudioSource, BYTE ucInputPort);
extern EnumSourceSearchPort ScalerAudioGetDigitalAudioPortMapping(void);

#if(_DP_SUPPORT == _ON)
extern bit ScalerAudioDpGetCapabilityChange(BYTE ucInputPort);
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
extern EnumAudioDpDpcdSupport ScalerAudioDpGetCapabilityState(BYTE ucInputPort);
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioFwTrackingHandler(void);
#endif

#if(_HDMI_SUPPORT == _ON)
extern void ScalerAudioHdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput, BYTE ucInputPort);
extern bit ScalerAudioLPCMCheckInfo(void);
extern EnumSourceTypeDef ScalerAudioDigitalAudioSourceType(void);
#endif

extern BYTE ScalerAudioGetDigitalAudioSource(BYTE ucInputPort);

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

#endif // End of #if(_AUDIO_SUPPORT == _ON)
