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
// ID Code      : RL6851_Series_ScalerAudio_ComboPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Audio ADC Frequency Paramater
//--------------------------------------------------
#define _AUDIO_PLL_IN_EXT_XTAL_CLK                  0x40

#define _AUDIO_PLL_OUT_DIV_1                        0
#define _AUDIO_PLL_OUT_DIV_2                        1
#define _AUDIO_PLL_OUT_DIV_4                        2
#define _AUDIO_PLL_OUT_DIV_6                        3
#define _AUDIO_PLL_OUT_DIV_8                        4
#define _AUDIO_PLL_OUT_DIV_10                       5
#define _AUDIO_PLL_OUT_DIV_12                       6
#define _AUDIO_PLL_OUT_DIV_14                       7

#define _AUDIO_PLL_O_DIV_1                          0
#define _AUDIO_PLL_O_DIV_2                          1
#define _AUDIO_PLL_O_DIV_4                          2
#define _AUDIO_PLL_O_DIV_8                          3

#define _AUDIO_PLL_OUT_DIV                          _AUDIO_PLL_OUT_DIV_8 // PageBF 0xA2[2:0]
#define _AUDIO_PLL_PREDIVIDER_BPN                   _ENABLE              // PageBF 0xA5[7]
#define _AUDIO_PLL_PREDIVIDER_N                     (0 + 2)              // PageBF 0xA4[7:0] default value = 0x00
#define _AUDIO_PLL_O_DIV                            _AUDIO_PLL_O_DIV_4   // PageBF 0xA5[1:0] default value = 0x00

#define _ADC_AUDIO_PLL_N                            0x19
#define _ADC_AUDIO_PLL_F                            0x768AA

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

#if((_HDMI_SUPPORT == _ON) || (_DP_SUPPORT == _ON))
extern bit ScalerAudioD0GetAudioDetected(void);
extern EnumAudioSamplingFreqType ScalerAudioD0SamplingFreqDetect(void);
extern bit ScalerAudioD0SamplingFreqChange(void);
extern void ScalerAudioD0WatchDogProc(bit bOn);
extern void ScalerAudioD0HbrModeControl(bit bEnable);
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

#if(_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioFwTrackingEventSet(EnumScalerTimerEventID enumEventID);
extern void ScalerAudioTimeoutEventSet(EnumScalerTimerEventID enumEventID);
#endif

#if(_HDMI_SUPPORT == _ON)
extern void ScalerAudioD0HdmiI2sSpdifChannelOutputSelect(EnumAudioIisSpdifOutput enumAudioIisSpdifOutput);

#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
extern void ScalerAudioD0FwTrackingEventSet(void);
extern void ScalerAudioD0TimeoutEventSet(void);
#endif
#endif
#endif

#if(_DP_SUPPORT == _ON)
extern void ScalerAudioD0DPDigitalOutputProc(bit bEnable);
extern void ScalerAudioD0DPSetDVCWindowSize(bit bAdjustType, EnumAudioSamplingFreqPacket enumSamplingFreqPacket);
#endif

#endif

