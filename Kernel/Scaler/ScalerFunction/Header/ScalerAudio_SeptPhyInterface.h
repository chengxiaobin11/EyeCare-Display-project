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
// ID Code      : ScalerAudio_SeptPhyInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_AUDIO_SUPPORT == _ON)
extern bit ScalerAudioGetAudioInputPortChanged(EnumAudioInputSource enumAudioSource, BYTE ucInputPort);
extern void ScalerAudioSetUserDefineAudioFrequency(EnumAudioSamplingFreqType enumAudioFreq);
extern void ScalerAudioSyncUserDefineFrequency(void);

#if(_DP_SUPPORT == _ON)
extern bit ScalerAudioDPGetMuteProc(BYTE ucInputPort);
extern void ScalerAudioDpAudioEnable(bit bEnable, BYTE ucInputPort);
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
#if(_EMBEDDED_DAC_SUPPORT == _ON)
extern bit ScalerAudioGetDpStandaloneAudioStatus(BYTE ucInputPort);
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
#endif
#endif

#endif
