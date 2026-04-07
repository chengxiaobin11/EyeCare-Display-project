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
// ID Code      : RL6851_Series_ScalerAudioInterface.h No.0000
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
extern void ScalerAudioInitial(void);
extern void ScalerAudioDigitalAdjustVolume(WORD usVolume);
extern void ScalerAudioMuteProc(bit bMute, WORD usVolume);
extern void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume);
extern void ScalerAudioDisable(void);
extern BYTE ScalerAudioGetDigitalAudioPort(EnumAudioOutputType enumAudioOutput);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern void ScalerAudioSetUserDefineAudioGenFrequency(EnumAudioSamplingFreqType enumAudioFreq);
#endif

#if(_LINE_IN_SUPPORT == _ON)
extern EnumAudioInputSource ScalerAudioGetInputSource(void);
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern void ScalerAudioDACInitial(void);
extern void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput);
extern void ScalerAudioDACSetState(EnumAudioDACState enumTargetState);
extern EnumAudioDACState ScalerAudioDACGetState(void);
extern bit ScalerAudioDACGetStateChange(void);
extern void ScalerAudioDACClrStateChange(void);
extern void ScalerAudioDACSetVcmReady(bit bReady);
extern void ScalerAudioDACNormalToDepop(void);
extern void ScalerAudioDACDepopToNormal(void);
extern void ScalerAudioDACOutputEnable(void);
extern EnumAudioDACOutput ScalerAudioDACGetOutput(void);
#endif

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDVCVolumeFastMute(bit bMute, WORD usVolume);
#endif

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
extern void ScalerAudioDVCAdjustVolume(WORD usVolume);
#endif

extern void ScalerAudioDVCSetVolumeMuteStatus(bit bMute);
extern bit ScalerAudioDVCGetVolumeMuteStatus(void);

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
void ScalerAudioSpdifChannelStatusProc(EnumAudioInputSource enumAudioSource, BYTE ucInputPort);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)
