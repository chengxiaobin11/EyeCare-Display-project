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
// ID Code      : ScalerAudio_ComboPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_AUDIO_SUPPORT == _ON)
extern void ScalerAudioDigitalAudioInitial(void);
extern void ScalerAudioDisableAudioPLL(void);
extern void ScalerAudioDigitalReset(BYTE ucInputPort);
extern void ScalerAudioLoadStableICodeEvent(EnumScalerTimerEventID enumEventID);

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioFwTrackingEventSet(EnumScalerTimerEventID enumEventID);
extern void ScalerAudioTimeoutEventSet(EnumScalerTimerEventID enumEventID);
#endif

#if((_HDMI_SUPPORT == _ON) || (_DP_SUPPORT == _ON))
extern bit ScalerAudioD0GetAudioDetected(void);
extern EnumAudioSamplingFreqType ScalerAudioD0SamplingFreqDetect(void);
extern bit ScalerAudioD0SamplingFreqChange(void);
extern void ScalerAudioD0WatchDogProc(bit bOn);
void ScalerAudioD0HbrModeControl(bit bEnable);

#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
extern void ScalerAudioD0AudioFrequencyMode(EnumAudioFreqTrackingMode enumAudioFreqTrackingMode);
#if(_DP_SUPPORT == _ON)
extern void ScalerAudioD0AudioFrequencyMode_EXINT0(EnumAudioFreqTrackingMode enumAudioFreqTrackingMode);
#if(_D1_DP_EXIST == _ON)
extern void ScalerAudioD1AudioFrequencyMode_EXINT0(EnumAudioFreqTrackingMode enumAudioFreqTrackingMode);
#endif // End of #if(_D1_DP_EXIST == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)
#endif // End of #if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
extern bit ScalerAudioD0GetInternalAudioGenEnable(void);
extern void ScalerAudioD0InternalAudioGenSwitch(bit bOn, EnumAudioLeftRightChannelSelect enumAudioLeftRightChannelSelect);
#endif
#endif

#if(_DP_SUPPORT == _ON)
extern void ScalerAudioD0DPDigitalOutputProc(bit bEnable);
extern void ScalerAudioD0DPSetDVCWindowSize(bit bAdjustType, EnumAudioSamplingFreqPacket enumSamplingFreqPacket);
#endif

#if(_HDMI_SUPPORT == _ON)
extern void ScalerAudioD0HdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput);

#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioD0FwTrackingEventSet(void);
extern void ScalerAudioD0TimeoutEventSet(void);
#endif
#endif
#endif

