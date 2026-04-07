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
// ID Code      : RTD2014NVRamOsd.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_NVRAM_OSD__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)


void RTDFlashLoadSceneModeData(BYTE ucGameMode);


#if(_DEF_DDCCI_EDID_TOOL)
BYTE g_stSNData[_SN_NUMBER_AMOUNT+1] = {0};
#endif
//zheli
//BYTE xdata NavData[28] = {0};
//BYTE  NavData[28] = {0};

//--------------------------------------------------
// Version Code of NVRam
//--------------------------------------------------
#define _CHECKSUM                                   0x82
#define _VERSION_CODE                               _CHECKSUM

//--------------------------------------------------
// Brightness/Contrast Default Value
//--------------------------------------------------
#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
#define _CONTRAST_VGA                               0x800
#define _CONTRAST_DVI                               0x800
#define _CONTRAST_VIDEO8                            0x800
#define _CONTRAST_HDMI                              0x800
#define _CONTRAST_DP                                0x800
#else
#define _CONTRAST_VGA                               0x080
#define _CONTRAST_DVI                               0x080
#define _CONTRAST_VIDEO8                            0x080
#define _CONTRAST_HDMI                              0x080
#define _CONTRAST_DP                                0x080
#endif

#if(_BRI_TYPE == _BRI_GEN_1_10BIT)
#define _BRIGHTNESS_VGA                             0x1F8
#define _BRIGHTNESS_DVI                             0x200
#define _BRIGHTNESS_VIDEO8                          0x200
#define _BRIGHTNESS_HDMI                            0x200
#define _BRIGHTNESS_DP                              0x200
#else
#define _BRIGHTNESS_VGA                             0x07E
#define _BRIGHTNESS_DVI                             0x080
#define _BRIGHTNESS_VIDEO8                          0x080
#define _BRIGHTNESS_HDMI                            0x080
#define _BRIGHTNESS_DP                              0x080
#endif
//--------------------------------------------------
// Six Color Data Default Values
//--------------------------------------------------
#define _SIX_COLOR_HUE_R                            50
#define _SIX_COLOR_SATURATION_R                     100
#define _SIX_COLOR_SATURATION_R_MONO				0

#define _SIX_COLOR_HUE_Y                            50
#define _SIX_COLOR_SATURATION_Y                     100
#define _SIX_COLOR_SATURATION_Y_MONO				0

#define _SIX_COLOR_HUE_G                            50
#define _SIX_COLOR_SATURATION_G                     100
#define _SIX_COLOR_SATURATION_G_MONO				0

#define _SIX_COLOR_HUE_C                            50
#define _SIX_COLOR_SATURATION_C                     100
#define _SIX_COLOR_SATURATION_C_MONO				0

#define _SIX_COLOR_HUE_B                            50
#define _SIX_COLOR_SATURATION_B                     100
#define _SIX_COLOR_SATURATION_B_MONO				0

#define _SIX_COLOR_HUE_M                            50
#define _SIX_COLOR_SATURATION_M                     100
#define _SIX_COLOR_SATURATION_M_MONO				0

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of PageInfo Address
//--------------------------------------------------
#define _FLASH_FW_CHECKSUM_ADDR                     (_FLASH_PAGE_SIZE - 16)
#define _FLASH_FW_VERSIONCODE_ADDR                  (_FLASH_PAGE_SIZE - 15)
#define _PAGEINFO_CHECKSUM_ADDR                     (_FLASH_PAGE_SIZE - 5)
#define _PAGEINFO_PAGEID_ADDR                       (_FLASH_PAGE_SIZE - 4)
#define _PAGEINFO_MOVECOUNT_ADDR                    (_FLASH_PAGE_SIZE - 3)

// This value is used to indicate the EEPROM emulaiton FW version
#define _EEPROM_EMULATION_VERSION                   0x01
#endif

extern void RTDFlashRestoreViewModeParameters(void);


// Attention: it is necessary for sizeof(StructOsdUserDataType) < ((_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START) * (_DATA_ITEM_LENGTH - 2))
// Please check it when add items in StructOsdUserDataType
//---------------------------vsc user data ---------------------------------
code VSCStructOsdUserDataType g_vscstOsdUserDataDefault = _USER_DATA_DEFAULT;



code StructOsdUserDataType g_stOSDDefaultData =
{
	_OSD_BACKLIGHT_DEFAULE,			// usBackLight
		_SRGB_BACKLIGHT,		// 

    50,                       	// ucOsdHPos;
    50,                       	// ucOsdVPos;
    _TIMEOUT_DEFAULT,   		// ucOsdTimeout;
    _ASPECT_RATIO_DEFAULT,      // ucAspectOriginRatio
    0,                        	// ucTransparency;
//--------------------------------------------------------
    _LANGUAGE_DEFAULT,          // b5Language;
    _COLOREFFECT_STANDARD,    	// b4ColorEffect;
//--------------------------------------------------------
    _CT_7500,                 // b4ColorTempType;
    _COLOR_SPACE_RGB,         // b3VGARGBYUV;
#if(_DEF_VGA_TIMING_KEY_2_4)
	_M_1280x768_75, 		// b1Mode768_75 	// 1024x768@75 / 1280x768@75
#endif

    _COLOR_SPACE_RGB,         // b3DVIRGBYUV;
#if(_DEF_VGA_TIMING_KEY_2_4)
    _M_1280x768_50,         // b1Mode768_50		// 1024x768@50 / 1280x768@50
#endif
//--------------------------------------------------------
    2,                        // b3Sharpness;
#if(_DEF_VGA_TIMING_KEY_2_4)
	_M_1600x900_60_RB,		// b1Mode960_60 	// 1600x900@60_RB / 1280x960@60
#endif
    _OSD_ROTATE_DEGREE_0,     // b1OsdRotate;  		// liuxh b1OsdRotate
    _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO,     // b2DispRotationSizeType;
    _ON,                      // b1OverScan;
//--------------------------------------------------------
    _GAMMA_OFF,               // b3Gamma;
    _ASPECT_RATIO_DEFAULT,   // b3AspectRatio;
    _DEF_DDCCIStatus,                      // b1DDCCIStatus; 
#if(_AI_EYE_PROTECTION == _ON)
    _OFF,                         //b1AIEyeProtectionStatus;
#endif
#if(_AI_LIGHT_ADAPTIVATION == _ON)
	_OFF,						 //b1AILightAdaptivationStatus;
#endif
#if(_AI_LOW_POWER == _ON)
	_OFF,						 //b1AILowPowerStatus;
#endif
    _OFF,                     	// b1OsdDcrStatus;
#if(_DEF_VGA_TIMING_KEY_2_4)
	_M_1600x900_60, 		// b1Mode900_60 	// 1600x900 / 1440x900
	_M_1600x900_60_CVR, 	// b1Mode900_60R	// 1600x900@60_CVR / 1440x900@60_RB
	_M_1680x1050_60,		// b1Mode1050_60	// 1680x1050@60 / 1400x1050@60
#endif
//--------------------------------------------------------
    _OD_GAIN_CENTER,          	// ucODGain;
    _DEFAULT_HUE,             	// cHue;
    _DEFAULT_SATURATION,      	// ucSaturation;
    _HL_WIN_OFF,              	// ucHLWinType;
//--------------------------------------------------------
    _PCM_OSD_NATIVE,          	// b3PCMStatus : 3;
    _ULTRA_VIVID_OFF,         	// b2UltraVividStatus : 2;
    _OFF,                     	// b1VolumeMute : 1;
    _OFF,                     	// b1AudioStandAloneStatus : 1;
    0,                        	// b1AudioSourceStatus : 1;
//--------------------------------------------------------
    50,                       	// ucVolume;
//--------------------------------------------------------
    _OFF,                      	// b1ODStatus : 1;
    0x00,                      	// b33DConvergenceMode : 3;
    _AUTO_COLOR_TYPE_EXTERNAL, 	// b1FactoryAutoColorType : 1;
    _ON,                       	// BYTE b1PanelUniformity : 1;
    0,                         	// BYTE b1PCMSoftProftMode : 1;
//--------------------------------------------------------
    0,                         	// BYTE ucOsdInputPort;
#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    _TYPE_C_U3_OFF,            	// BYTE b1D0TypeCU3Mode;
    _TYPE_C_U3_OFF,            	// BYTE b1D1TypeCU3Mode;
    _TYPE_C_U3_OFF,            	// BYTE b1D2TypeCU3Mode;
    _TYPE_C_U3_OFF,            	// BYTE b1D6TypeCU3Mode;
#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
    _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON,            // BYTE b1D0TypeCPinAssignmentESupportSelect;
    _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON,            // BYTE b1D1TypeCPinAssignmentESupportSelect;
    _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON,            // BYTE b1D2TypeCPinAssignmentESupportSelect;
    _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON,            // BYTE b1D6TypeCPinAssignmentESupportSelect;
#endif
#endif
//--------------------------------------------------------
    _DP_VER_1_DOT_3,            // b1OsdDpD0PortVersion : 1;
    _DP_VER_1_DOT_3,            // b1OsdDpD1PortVersion : 1;
    0,                         	// b3OsdDispRotate : 3;
    0,                         	// b1OsdDpVersionHotKeyDisp : 1;
//--------------------------------------------------------
    0,                         	// b1PreShowDpHotKeyVersion : 1;
    0,                         	// b3PanelUniformityType : 3;
    0,                         	// b1OsdDpD6PortVersion : 2;
    0,                         	// b1OsdDpD2PortVersion : 2;
    DEF_FREESYNC_STATUS,                      	// b1FreeSyncStatus : 1;
    _OFF,                      	// b1DpAdaptiveSyncStatus : 1;
    _OFF,                      	// b1OsdDpVer11Status : 1;
    _OSD_CLONE_OFF,            	// b1CloneMode: 1;
//--------------------------------------------------------
    _LATENCY_L,                // b2LatencyStatus : 2
    _OFF,                      // BYTE b1OsdDoubleSize :1;

#if(_DEF_VGA_TIMING_KEY_2_4)
    _M_720x400_70,          // b2Mode400_70		// 720x400@70 / 640x400@70 / 640x350@70
#endif

	_OFF,						// b3OsdDpMST : 3;

#if(_DEF_VGA_TIMING_KEY_2_4)
    _M_1680x1050_60_RB,     // b1Mode1050_60R	// 1680x1050@60_RB / 1400x1050@60_RB
    _M_640x480_60,          // b2Mode480_60		// 640x480@60 / 640x400@60 / 720x400@70
    _M_1360x768_60,         // b2Mode768_60		// 1360x768 / 1280x768 / 1366x 768 / 1366x 768RB
#endif


#if(_HDR10_SUPPORT == _ON)
    _HDR10_MODE_AUTO,            // BYTE ucHdrMode;
    _OFF,                       // b1DarkEnhanceStatus : 1;
    _OFF,                       // b1HdrSharpness : 1;
    0,                          // BYTE ucHdrContrast;
    0,                          // BYTE ucHdrColorEnhance;
    0,                          // BYTE ucHdrLightEnhance;
#endif
#if(_OSD_LOCAL_DIMMING_SUPPORT == _ON)
    _OFF,                       // BYTE b1HdrLocalDimming : 1;
    50,                         // BYTE ucHdrLocalDimmingAdj;
#endif
#if (_SDR_TO_HDR_SUPPORT == _ON)
    _OFF,                       // b1Sdr2HdrStatus : 1;
#endif

// --------------------------------------------------------
#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
    _HDMI_1P4,                 // BYTE b2OsdHdmiD0PortVersion : 2;
    _HDMI_1P4,                 // BYTE b2OsdHdmiD1PortVersion : 2;
    _HDMI_1P4,                 // BYTE b2OsdHdmiD2PortVersion : 2;
    _HDMI_1P4,                 // BYTE b2OsdHdmiD3PortVersion : 2;
    _HDMI_1P4,                 // BYTE b2OsdHdmiD4PortVersion : 2;
    _HDMI_1P4,                 // BYTE b2OsdHdmiD5PortVersion : 2;
#endif

#if(_USB3_RETIMER_SUPPORT == _ON)
    _TRUE,                     // BYTE b1OsdUsb3RetimerPDWakeUp: 1;
    _TRUE,                     // BYTE b1OsdUsb3RetimerPSWakeUp: 1;
    _HUB_UFP_TYPE_C_INPUT_PORT, // EnumHubInputPort enumHubInputPortSwitchbyUser;
#endif
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    _OSD_MBR_USER_DISABLE,     // b2MbrStatus;
    _OSD_MBR_DUTY_DEFAULT,     // b7MbrDutys;
    _OSD_MBR_POS_DEFAULT,      // b7MbrPosition;
#endif
#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
    _ON,                       //BYTE b1TtsSupport: 1;
    80,                        //BYTE ucTtsTextVolume;
    20,                        //BYTE ucTtsAudioVolume;
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

	_GM_OFF,					// b4GameMode
#if(_MPRT_SUPPORT == _ON)
	_OFF,						// bMPRTStatus
#endif

#if(_DEF_VGA_TIMING_KEY_2_4)
	0,						// b1Mode900_75		// (1440x900@75 / 1152x870@75)
#endif

	_ECO_DEFAULT,           	// b2EcoMode
    _SleepPowerSaving_OFF,      //b3Sleep
    _OFF,                      	//b1AutoPowerOff     
  #if(_DEFAULT_OSD_STYLE  == _SUMA_OSD_STYLE||_DEFAULT_OSD_STYLE  == _TRG_OSD_STYLE)
    _OFF,                       	//b1ResolutionStatus
  #else
    _ON,                       	//b1ResolutionStatus
   #endif
    _ON,                        //b1PowerIndicator
    0,                          //b3OsdDcrStatus 
    0,                          //b4BlackStabilization
	_DEF_FACTORY_MODE,		   /* BYTE b1FACTORY_MODE:1 */
	_DEF_BURNING_MODE,		   /* BYTE b1BURNING_MODE: 1*/
    _DEF_DDCCIStatus,					// b1DDCStatus

//--------------------------------------------------------
    _SPACE_DEFAULT,       	// b2D0ColorSpace
    _RANGE_DEFAULT,			// b2D0ColorRange
    _SPACE_DEFAULT,       	// b2D1ColorSpace
    _RANGE_DEFAULT,			// b2D1ColorRange
//--------------------------------------------------------
	_SPACE_DEFAULT,			// b2D2ColorSpace
	_RANGE_DEFAULT,			// b2D2ColorRange
	_SPACE_DEFAULT,			// b2D3ColorSpace
	_RANGE_DEFAULT,			// b2D3ColorRange
//--------------------------------------------------------

	_OFF,//b1A0OverScan
	_OFF,//b1D0OverScan
	_OFF,//b1D1OverScan
	_OFF,//b1D2OverScan
	_OFF,//b1D3OverScan
//--------------------------------------------------------
	_OFF,//b2BackupODMode
    _VM_STANDARD,     		// b3ViewMode
	_OSD_HOTKEY_VIEWMODE,
	_ON,					/*����ѡ��*/
	_ON,					/*����ѡ��*/
	_DEF_REGION_InitData,	/*b4District */
	_ON,					/*BYTE b1PCHintStatus : 1;*/
//--------------------------------------------------------

	_OFF,					// mprt
    _OFF,                   // b1OsdLockStatus
    _OFF,					// b1PowerKeyLockStatus
	_ON,					/*BYTE b1OsdMessageEanble : 1;*/
	_OFF,					/*BYTE b2FrontSight : 2;*/
	_OFF,					/*BYTE b5Message : 5;*/
	
#if 1//(_DEF_OSD_GAMING == _ON)
	0,							/*BYTE b3Timer*/\
	0,							/*BYTE b4Crosshair*/\
	0, 
#endif

};

code StructBriConDataType tBriConDefaultData[] =
{
    {
        _BRIGHTNESS_DEFAULT,
        _CONTRAST_DEFAULT,
    },

    {
        _BRIGHTNESS_DEFAULT,
        _CONTRAST_DEFAULT,
    },

    {
        _BRIGHTNESS_DEFAULT,
        _CONTRAST_DEFAULT,
    },

    {
        _BRIGHTNESS_DEFAULT,
        _CONTRAST_DEFAULT,
    },

    {
        _BRIGHTNESS_DEFAULT,
        _CONTRAST_DEFAULT,
    },

};



code StructVscSceneModeDataType tVscSceneModeDefaultData[] =
{
#if(_ADVANCED_IMAGE_SUPPORT == _ON)
	{// FPS1
	    _BRIGHTNESS_DEFAULT,			// usBrightness
	    _CONTRAST_DEFAULT,				// usContrast
	    100,							// usBackLightNormal,
	    _SRGB_BACKLIGHT,          		// usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_24,						// b6GammaMode
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_SHARPNESS_DEFAULT,
		_BLK_STABLE_DEFAULT,
#else
	    _SHARPNESS_TABLE3,		// b4Sharpness
	    _BLKStable_Mode3,		// b4BlackStabilization
#endif
//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    			// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_ADVANCED,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_ADVANCED,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT, // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

		_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},
	
#if(_DEF_VIEWMODE_RTS == _ON)

	{// RTS
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
			100,//_BACKLIGHT_DEFAULT,
	       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_22,//_GAMMA_DEFAULT,			// b6GammaMode
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_SHARPNESS_DEFAULT,
		_BLK_STABLE_DEFAULT,
#else
	    _SHARPNESS_MAX,			// b4Sharpness
	    _BLKStable_Mode7,		// b4BlackStabilization
#endif
		//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_DCR_MIN,
#else
		RTS_DEF_DCR,

#endif
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_DCR_MIN,
#else
		_DCR_MAX,				// b3BackupAdvanceDCR
#endif
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif
		
		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif
		_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},
	
#endif

#if(_DEF_VIEWMODE_MOBA == _ON)

	{// MOBA
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
			100,//_BACKLIGHT_DEFAULT,
	       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_DEFAULT,			// b6GammaMode
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_SHARPNESS_DEFAULT,
		_BLK_STABLE_DEFAULT,
#else
	    _SHARPNESS_TABLE3,		// b4Sharpness
	    _BLKStable_Mode6,		// b4BlackStabilization
#endif
		//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_DCR_MIN,
#else
		MOBA_DEF_DCR,
#endif
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_ADVANCED,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_DCR_MIN,
#else
		#if _DEFAULT_OSD_STYLE == _TRG_OSD_STYLE
			_DCR_Level_0,
		#else
			_DCR_Level_3,			// b3BackupAdvanceDCR
		#endif
#endif
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_ADVANCED,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},

#endif

	{// Gamer1
		_BRIGHTNESS_DEFAULT,
		_CONTRAST_DEFAULT,
		100,//_BACKLIGHT_DEFAULT,
		_SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_DEFAULT, 		// b6GammaMode
		//--------------------------------------------------------
		_SHARPNESS_DEFAULT, 	// b4Sharpness
#if(_DEF_GAMMA_TOOL_TEST)
		_BLK_STABLE_DEFAULT,
#else
		_BLKStable_Mode4,	// b4BlackStabilization
#endif
		//--------------------------------------------------------
		_CT_USER,			 	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,		// b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT, 	// ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_ULTRA_FAST,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_ULTRA_FAST,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,	// b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif
		
		//--------------------------------------------------------
		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
		_SIX_COLOR_SATURATION_R,
		_SIX_COLOR_HUE_Y,
		_SIX_COLOR_SATURATION_Y,
		_SIX_COLOR_HUE_G,
		_SIX_COLOR_SATURATION_G,
		_SIX_COLOR_HUE_C,
		_SIX_COLOR_SATURATION_C,
		_SIX_COLOR_HUE_B,
		_SIX_COLOR_SATURATION_B,
		_SIX_COLOR_HUE_M,
		_SIX_COLOR_SATURATION_M,
		#endif

			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},

	{// Standard
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
	    _OSD_BACKLIGHT_DEFAULE,
	       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_DEFAULT,			// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
	    _BLK_STABLE_DEFAULT,	// b4BlackStabilization
		//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode

		_OD_DEFAULT,			// b2ODMode

		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode

		_OD_DEFAULT,			// b2ODMode

		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif
		_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},

	{// Movie
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
		100,//_BACKLIGHT_DEFAULT,
	    _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_24,				// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
	    _BLK_STABLE_DEFAULT,	// b4BlackStabilization
		//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

		_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},

	{// Web
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
			100,//_BACKLIGHT_DEFAULT,
	       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_28,				// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
	    _BLK_STABLE_DEFAULT,	// b4BlackStabilization
		//--------------------------------------------------------
		_COLORTEMP_DEFAULT,    	// b4ColorTemp
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},

	{// Text
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
	    _SRGB_BACKLIGHT,		//_DEF_OSD_VIE_TEXT_BACK,
	    _SRGB_BACKLIGHT,        // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_24,				// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
	    _BLK_STABLE_DEFAULT,	// b4BlackStabilization
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_CT_6500,				// b4ColorTemp
#else
		_OSD_CT_VIE_TEXT,//_CT_6500,    			// b4ColorTemp
#endif
		_OFF,					// b3Unused1
		_ENABLE,      // b1BlueLightStatus
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_BLUELIGHT_DEFAULT,
#else
		_BLUELIGHT_30,    	// ucBlueLightValue
#endif
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},
#if(_DEF_VIEWMODE_MAC)

	{// MAC
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
		100,//_BACKLIGHT_DEFAULT,
       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_DEFAULT,			// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
		_BLK_STABLE_DEFAULT,
		//--------------------------------------------------------
#if(_DEF_GAMMA_TOOL_TEST)
		_CT_6500,				// b4ColorTemp
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)
		_CT_6500,				// b4ColorTemp
#elif(_DEF_CT_SRGB_SUPPIRT)
		_CT_SRGB,    			// b4ColorTemp
#else
		_CT_6500,    			// b4ColorTemp
#endif
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif

		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M,
		#endif

			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},
	
#endif

	{// Mono
	    _BRIGHTNESS_DEFAULT,
	    _CONTRAST_DEFAULT,
			100,//_BACKLIGHT_DEFAULT,
	       _SRGB_BACKLIGHT,          // usBackLightSrgb
		//--------------------------------------------------------
		_GAMMA_28,				// b6GammaMode
		//--------------------------------------------------------
	    _SHARPNESS_DEFAULT,		// b4Sharpness
	    _BLK_STABLE_DEFAULT,	// b4BlackStabilization
		//--------------------------------------------------------
		#if _DEFAULT_OSD_STYLE==_TRG_OSD_STYLE
		_CT_9300,
		#else
		_CT_7500,    			// b4ColorTemp
		#endif
		_OFF,					// b3Unused1
		_BLUELIGHT_STATUS,      // b1BlueLightStatus
		//--------------------------------------------------------
		_BLUELIGHT_DEFAULT,     // ucBlueLightValue
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3AdvanceDCR
		_LATENCY_DEFAULT,		// b2LowLagMode
		_OD_DEFAULT,			// b2ODMode
		_OFF,					// b1SmartSync
		//--------------------------------------------------------
		_DCR_DEFAULT,			// b3BackupAdvanceDCR
		_LATENCY_DEFAULT,		// b2BackupLowLagMode
		_OD_DEFAULT,			// b2BackupODMode
		_OFF,					// b1BackupSmartSync
		//--------------------------------------------------------
		_ASPECT_RATIO_DEFAULT,  // b4AspectRatio
	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		_OFF,  // b1OverScan
	#endif
		#if(_SIX_COLOR_SUPPORT == _ON)
		_SIX_COLOR_HUE_R,
	    _SIX_COLOR_SATURATION_R_MONO,
	    _SIX_COLOR_HUE_Y,
	    _SIX_COLOR_SATURATION_Y_MONO,
	    _SIX_COLOR_HUE_G,
	    _SIX_COLOR_SATURATION_G_MONO,
	    _SIX_COLOR_HUE_C,
	    _SIX_COLOR_SATURATION_C_MONO,
	    _SIX_COLOR_HUE_B,
	    _SIX_COLOR_SATURATION_B_MONO,
	    _SIX_COLOR_HUE_M,
	    _SIX_COLOR_SATURATION_M_MONO,
		#endif
			_FREQUENCE_LIMIT_OFF,	// ucFrequenceLimit			

	},
#endif
};




code StructColorProcDataType tColorTempDefaultData[] =
{
#if(_DEF_CT_SRGB_SUPPIRT == _ON)
    {
        _CTSRGB_RED,
        _CTSRGB_GREEN,
        _CTSRGB_BLUE,
    },
#endif

    {
        _CT9300_RED,
        _CT9300_GREEN,
        _CT9300_BLUE,
    },

    {
        _CT7500_RED,
        _CT7500_GREEN,
        _CT7500_BLUE,
    },

    {
        _CT6500_RED,
        _CT6500_GREEN,
        _CT6500_BLUE,
    },
    
#if(_DEF_CT_5800_SUPPORT == _ON)
    {
        _CT5800_RED,
        _CT5800_GREEN,
        _CT5800_BLUE,
    },
#endif

    {
        _CTUSER_RED,
        _CTUSER_GREEN,
        _CTUSER_BLUE,
    },

#if (_BLUE_LIGHT_FILTER_SUPPORT == _ON)
	{
		_CT4500_RED,
		_CT4500_GREEN,
		_CT4500_BLUE,
	},
#endif

#if (_VIEWMODE_SUPPORT == _ON)
	{
		_CTGAME_RED,
		_CTGAME_GREEN,
		_CTGAME_BLUE,
	},

	{
		_CTMOVIE_RED,
		_CTMOVIE_GREEN,
		_CTMOVIE_BLUE,
	},

	{
		_CTWEB_RED,
		_CTWEB_GREEN,
		_CTWEB_BLUE,
	},

	{
		_CTTEXT_RED,
		_CTTEXT_GREEN,
		_CTTEXT_BLUE,
	},

	{
		_CTMAC_RED,
		_CTMAC_GREEN,
		_CTMAC_BLUE,
	},

	{
		_CTMONO_RED,
		_CTMONO_GREEN,
		_CTMONO_BLUE,
	},
#endif

		
};
/*
code StructSixColorDataType g_stSixColorDefaultData =
{
    _SIX_COLOR_HUE_R,
    _SIX_COLOR_SATURATION_R,
    _SIX_COLOR_HUE_Y,
    _SIX_COLOR_SATURATION_Y,
    _SIX_COLOR_HUE_G,
    _SIX_COLOR_SATURATION_G,
    _SIX_COLOR_HUE_C,
    _SIX_COLOR_SATURATION_C,
    _SIX_COLOR_HUE_B,
    _SIX_COLOR_SATURATION_B,
    _SIX_COLOR_HUE_M,
    _SIX_COLOR_SATURATION_M,
};*/

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
// StructOsdUserDataType g_stOsdUserData;
StructColorProcDataType g_stColorProcData;
// StructOsdInputPortDataType g_pstOsdInputPortData[10];
// StructOsdRegionDataType g_pstOsdRegionData[2];
// StructOsdDisplayModeDataType g_stOsdDisplayModeData;
// StructOsdItemDataType g_stOsdItemData;
//VSCStructOsdUserDataType g_vscstOSDUserData;

StructOsdUserDataType g_stOSDUserData;
StructVscSceneModeDataType g_stVscSceneModeData;
StructBriConDataType g_stBriConData;
//StructSixColorDataType g_stSixColorData;
StructTimeType g_stPanelTimeData;
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
DWORD g_ulFlashMoveCount;
BYTE g_ucFlashLastPage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
WORD g_pusFlashAddrArr[_END_OF_PAGEID - _START_OF_PAGEID + 1];
BYTE g_pucFlashPageArr[_END_OF_PAGEID - _START_OF_PAGEID + 1];
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
void RTDEepromStartup(void);
void RTDEepromWholeRestore(void);
void RTDEepromRestoreBacklight(void);
void RTDEepromLoadOSDData(void);
void RTDEepromSaveOSDData(void);
void RTDEepromRestoreOSDData(void);
void RTDEepromLoadBriCon(BYTE ucSource);
void RTDEepromSaveBriCon(BYTE ucSource);
void RTDEepromRestoreBriCon(void);
void RTDEepromLoadColorSetting(BYTE ucColorTempType);
void RTDEepromSaveColorSetting(BYTE ucColorTempType);
void RTDEepromRestoreColorSetting(void);
void RTDEepromRestoreUserColorSetting(void);
void RTDEepromLoadSixColorData(void);
void RTDEepromSaveSixColorData(void);
void RTDEepromRestoreSixColorData(void);
void RTDEepromLoadPanelUsedTimeData(void);
void RTDEepromSavePanelUsedTimeData(void);
void RTDEepromRestorePanelUsedTimeData(void);

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

BYTE RTDFlashGetFreePage(void);
bit RTDFlashIsPageInfoValid(BYTE ucPage);
void RTDFlashInitialDataPage(BYTE ucPageID);
WORD RTDFlashSearchPageAddr(BYTE ucPageID);
void RTDFlashInitialAddr(void);
void RTDFlashLoadChecksumVersioncode(BYTE *pucChecksum, BYTE *pucVersionCode);
void RTDFlashSaveChecksumVersionCode(BYTE ucChecksum, BYTE ucVersionCode);
bit RTDFlashMoveData(BYTE ucPageID, BYTE *pucData);

void RTDFlashStartup(void);
void RTDFlashWholeRestore(void);
void RTDFlashRestoreBacklight(void);
void RTDFlashLoadOSDData(void);
void RTDFlashSaveOSDData(void);
void RTDFlashRestoreOSDData(void);
void RTDFlashLoadBriCon(BYTE ucSource);
void RTDFlashSaveBriCon(BYTE ucSource);
void RTDFlashRestoreBriCon(void);
void RTDFlashLoadColorSetting(BYTE ucColorTempType);
void RTDFlashSaveColorSetting(BYTE ucColorTempType);
void RTDFlashRestoreColorSetting(void);
void RTDFlashRestoreUserColorSetting(void);
/*void RTDFlashLoadSixColorData(void);
void RTDFlashSaveSixColorData(void);
void RTDFlashRestoreSixColorData(void);*/
void RTDFlashLoadPanelUsedTimeData(void);
void RTDFlashSavePanelUsedTimeData(void);
void RTDFlashRestorePanelUsedTimeData(void);
#if(_PANEL_EXIST_MULTIPANEL == _ON)
void RTDFlashLoadPanelIndex(void);
void RTDFlashSavePanelIndex(void);
void RTDFlashRestorePanelIndex(void);
#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _ON)

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
BYTE RTDNVRamTransferOsdRegionType(BYTE ucDisplayMode, BYTE ucRegion);
BYTE RTDNVRamTransferOsdRegionIndex(BYTE ucDisplayMode, BYTE ucRegion);

#if 0//(_DEF_DDCCI_EDID_TOOL)
void RTDFlashGetSNData(void);
void RTDFlashSaveSNData(void);
#endif

#if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)
extern void UserCommonInterfaceNVRamRestoreEDID(void);
#endif



#if((_D1_INPUT_PORT_TYPE!=_D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
	((_D2_INPUT_PORT_TYPE!=_D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D3_INPUT_PORT_TYPE!=_D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D0_INPUT_PORT_TYPE!=_D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))
extern void UserCommonInterfaceNVRamSaveEDIDWhenProgramming(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Eeprom check at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromStartup(void)
{
    BYTE ucCnt = 0;

    // Check twice if VERSION CODE matches
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        pData[0] = _CHECKSUM ^ 0xFF;
        pData[1] = _VERSION_CODE ^ 0xFF;
        UserCommonEepromRead(_EEPROM_CHECKSUM_ADDRESS, 2, pData);

        if((pData[0] == _CHECKSUM) && (pData[1] == _VERSION_CODE))
        {
            break;
        }
    }

    if(pData[0] != _CHECKSUM)
    {
        BYTE pucData[3] = {0};

        // Load default value and save to EEPROM
        RTDEepromWholeRestore();

        // Save VERSION CODE to EEPROM
        pucData[0] = _CHECKSUM;
        pucData[1] = _VERSION_CODE;
        pucData[2] = 0; // _PANEL_INDEX_ADDRESS

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        SET_MDOMAIN_PANEL_INDEX(0);
#endif

        UserCommonEepromWrite(_EEPROM_CHECKSUM_ADDRESS, 2, pucData);
        UserCommonEepromWrite(_PANEL_INDEX_ADDRESS, 1, &pucData[2]);
    }
    else if(pData[1] != _VERSION_CODE)
    {
        g_stColorProcData = tColorTempDefaultData[_CT_USER];
        RTDEepromSaveColorSetting(_CT_USER);

        UserCommonEepromRestoreSystemData();
        RTDEepromRestoreOSDData();

#if(_VGA_SUPPORT == _ON)
        UserCommonEepromRestoreModeUserData();
#endif

        RTDEepromRestoreBriCon();
        RTDEepromRestoreSixColorData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        UserCommonEepromRead(_PANEL_INDEX_ADDRESS, 1, pData);
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
#endif

        pData[1] = _VERSION_CODE;
        UserCommonEepromWrite(_EEPROM_VERSION_CODE_ADDRESS, 1, &pData[1]);
    }
    else
    {
        UserCommonEepromLoadSystemData();
        RTDEepromLoadOSDData();
        RTDEepromLoadSixColorData();
        RTDEepromLoadPanelUsedTimeData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        UserCommonEepromRead(_PANEL_INDEX_ADDRESS, 1, pData);
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
#endif

        // Check PCM Flag
        if(GET_OSD_PCM_STATUS() > _PCM_OSD_AMOUNT)
        {
            SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
            RTDEepromSaveOSDData();
        }

#if(_OSD_3D_FUNCTION == _ON)
        if((GET_OSD_3DOSD_STATUS() == _ON) &&
           ((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
            (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)))
        {
            SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_0);
            RTDEepromSaveOSDData();
        }
#endif
    }

    // SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
    /*
    if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
    {
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
    }
    */

    RTDEepromLoadColorSetting(GET_COLOR_TEMP_TYPE());
}

//--------------------------------------------------
// Description  : Load default data and save to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromWholeRestore(void)
{
    UserCommonEepromRestoreSystemData();
    RTDEepromRestoreOSDData();

#if(_VGA_SUPPORT == _ON)
    UserCommonEepromRestoreModeUserData();
    UserCommonEepromRestoreADCSetting();
#endif

    RTDEepromRestoreBriCon();
    RTDEepromRestoreColorSetting();
    RTDEepromRestoreUserColorSetting();

    RTDEepromRestoreSixColorData();
    RTDEepromRestorePanelUsedTimeData();
}

//--------------------------------------------------
// Description  : Restore default backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreBacklight(void)
{
    SET_OSD_BACKLIGHT(g_stOSDDefaultData.usBackLight);
    RTDEepromSaveOSDData();
}

//--------------------------------------------------
// Description  : Load OSD data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadOSDData(void)
{
    UserCommonEepromRead(_OSD_DATA_ADDRESS, sizeof(StructOsdUserDataType), (BYTE *)(&g_stOSDUserData));

#if(_DP_MST_SUPPORT == _ON)
    if((GET_OSD_DP_MST() != _MST_OFF) &&
       (SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT))
    {
        SET_OSD_DP_MST(_MST_OFF);
    }
#endif
}

//--------------------------------------------------
// Description  : Save OSD data to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveOSDData(void)
{
    UserCommonEepromWrite(_OSD_DATA_ADDRESS, sizeof(StructOsdUserDataType), (BYTE *)(&g_stOSDUserData));
}

//--------------------------------------------------
// Description  : Restore default OSD data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreOSDData(void)
{
    g_stOSDUserData = g_stOSDDefaultData;
    RTDEepromSaveOSDData();
}

//--------------------------------------------------
// Description  : Load brightness/contrast from EEPROM
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadBriCon(BYTE ucSource)
{
    UserCommonEepromRead(_BRICON_DATA_ADDRESS + ucSource * sizeof(StructBriConDataType), sizeof(StructBriConDataType), (BYTE *)(&g_stBriConData));
}

//--------------------------------------------------
// Description  : Save brightness/contrast to EEPROM
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveBriCon(BYTE ucSource)
{
    UserCommonEepromWrite(_BRICON_DATA_ADDRESS + ucSource * sizeof(StructBriConDataType), sizeof(StructBriConDataType), (BYTE *)(&g_stBriConData));
}

//--------------------------------------------------
// Description  : Restore default brightness/contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreBriCon(void)
{
    BYTE ucTemp = 0;

    for(ucTemp = 0; ucTemp < _SOURCE_AMOUNT; ucTemp++)
    {
        g_stBriConData = tBriConDefaultData[ucTemp];
        RTDEepromSaveBriCon(ucTemp);
    }
}

//--------------------------------------------------
// Description  : Load color settings from EEPROM
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadColorSetting(BYTE ucColorTempType)
{
#if(_OGC_SUPPORT == _ON)
    if(GET_OSD_GAMMA() != _GAMMA_OFF)
    {
        UserCommonAdjustOGCColorTempGain(ucColorTempType, (GET_OSD_GAMMA() - 1), pData, _OGC_NORMAL_TYPE);

#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
        g_stColorProcData.usColorTempR = PDATA_WORD(0);
        g_stColorProcData.usColorTempG = PDATA_WORD(1);
        g_stColorProcData.usColorTempB = PDATA_WORD(2);
#elif(_CTS_TYPE == _CTS_GEN_0_8BIT)
        g_stColorProcData.usColorTempR = pData[0];
        g_stColorProcData.usColorTempG = pData[1];
        g_stColorProcData.usColorTempB = pData[2];
#endif
        return;
    }
#endif

#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
    if(GET_OSD_GAMMA() != _GAMMA_OFF)
    {
        g_stColorProcData.usColorTempR = 0x800;
        g_stColorProcData.usColorTempG = 0x800;
        g_stColorProcData.usColorTempB = 0x800;
        return;
    }
#endif

    UserCommonEepromRead(_COLORTEMP_DATA_ADDRESS + (ucColorTempType) * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&g_stColorProcData.usColorTempR));

    /*
    else
    {
        g_stColorProcData.usColorTempR = 0x800;
        g_stColorProcData.usColorTempG = 0x800;
        g_stColorProcData.usColorTempB = 0x800;
    }
    */
}

//--------------------------------------------------
// Description  : Save color settings to EEPROM
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveColorSetting(BYTE ucColorTempType)
{
    // if(ucColorTempType != _CT_OFF)
    {
        UserCommonEepromWrite(_COLORTEMP_DATA_ADDRESS + (ucColorTempType) * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&g_stColorProcData.usColorTempR));
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreColorSetting(void)
{
    BYTE ucTemp = 0;
    for(ucTemp = _CT_9300; ucTemp < _CT_USER; ucTemp++)
    {
        g_stColorProcData = tColorTempDefaultData[ucTemp];
        RTDEepromSaveColorSetting(ucTemp);
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreUserColorSetting(void)
{
    StructColorProcDataType stUserColorTemp;
    BYTE ucIndex = 0;

    for(ucIndex = _CT_9300; ucIndex <= _CT_USER; ++ucIndex)
    {
        stUserColorTemp = tColorTempDefaultData[ucIndex];
        UserCommonEepromWrite(_COLORTEMP_DATA_ADDRESS + (ucIndex) * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&stUserColorTemp));
    }
}

/*
//--------------------------------------------------
// Description  : Load six color data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadSixColorData(void)
{
    UserCommonEepromRead(_SIXCOLOR_DATA_ADDRESS, sizeof(StructSixColorDataType), (BYTE *)(&g_stSixColorData));
}

//--------------------------------------------------
// Description  : Save six color data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveSixColorData(void)
{
    UserCommonEepromWrite(_SIXCOLOR_DATA_ADDRESS, sizeof(StructSixColorDataType), (BYTE *)(&g_stSixColorData));
}

//--------------------------------------------------
// Description  : Restore default six color data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreSixColorData(void)
{
    g_stSixColorData = g_stSixColorDefaultData;
    RTDEepromSaveSixColorData();
}
*/
//--------------------------------------------------
// Description  : Load Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadPanelUsedTimeData(void)
{
    UserCommonEepromRead(_PANEL_TIME_DATA_ADDRESS, sizeof(StructTimeType), (BYTE *)(&g_stPanelTimeData));
}

//--------------------------------------------------
// Description  : Save Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSavePanelUsedTimeData(void)
{
    UserCommonEepromWrite(_PANEL_TIME_DATA_ADDRESS, sizeof(StructTimeType), (BYTE *)(&g_stPanelTimeData));
}

//--------------------------------------------------
// Description  : Restore Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestorePanelUsedTimeData(void)
{
    SET_PANEL_TIME_HOUR(0);
    SET_PANEL_TIME_MIN(0);

    SET_PANEL_BURN_TIME_HOUR(0);
    SET_PANEL_BURN_TIME_MIN(0);
    RTDEepromSavePanelUsedTimeData();
}

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

//--------------------------------------------------
// Description  : Get the free page number of flash
// Input Value  : None
// Output Value : Free page index
//--------------------------------------------------
BYTE RTDFlashGetFreePage(void)
{
    BYTE ucPageID = _START_OF_PAGEID;
    BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;

    // If the _END_PAGE page has the biggest move count, suppose first page is free page
    if(g_ulFlashMoveCount > 0)
    {
        if(g_ucFlashLastPage >= _SYSTEM_EEPROM_EMULATION_END_PAGE)
        {
            ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
        }
        else
        {
            ucFreePage = g_ucFlashLastPage + 1;
        }
    }

    // Check the supposed free page is actual free page which has not been used ever
    do
    {
        if(ucFreePage == g_pucFlashPageArr[ucPageID])
        {
            if(ucFreePage >= _SYSTEM_EEPROM_EMULATION_END_PAGE)
            {
                ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
            }
            else
            {
                ucFreePage += 1;
            }

            ucPageID = _START_OF_PAGEID;
        }
        else
        {
            ucPageID++;
        }
    }
    while(ucPageID <= _END_OF_PAGEID);

    return ucFreePage;
}

//--------------------------------------------------
// Description  : Check the page is vaild or not
// Input Value  : ucPage: The page to be check, must between 0 and (_END_PAGE - _START_PAGE)
// Output Value : _TRUE means the page is valid, _FLASE is invalid
//--------------------------------------------------
bit RTDFlashIsPageInfoValid(BYTE ucPage)
{
    WORD usPageInfoAddr = ucPage * _FLASH_PAGE_SIZE;
    BYTE ucPageInfoChecksum = 0;
    BYTE pucPageInfo[5] = {0};
    BYTE pucPageInfoTemp[4] = {0};

    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageInfoAddr + _PAGEINFO_CHECKSUM_ADDR, 5, pucPageInfo);
    pucPageInfoTemp[0] = pucPageInfo[1];
    pucPageInfoTemp[1] = pucPageInfo[2];
    pucPageInfoTemp[2] = pucPageInfo[3];
    pucPageInfoTemp[3] = pucPageInfo[4];
    ucPageInfoChecksum = UserCommonFlashCalculateCheckSumData(pucPageInfoTemp, 4);
    ucPageInfoChecksum = (ucPageInfoChecksum & 0x7F);

    if(ucPageInfoChecksum == pucPageInfo[0])
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Initial data page
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashInitialDataPage(BYTE ucPageID)
{
    WORD usAddr = _SYSTEM_EEPROM_EMULATION_START_PAGE * _FLASH_PAGE_SIZE;
    BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
   // BYTE ucVersionCode = 0;
   // BYTE ucChecksum = 0;

    ucFreePage = RTDFlashGetFreePage();
    // Initial page index
    g_pucFlashPageArr[ucPageID] = ucFreePage;
    // Initial address
    g_pusFlashAddrArr[ucPageID] = 0;
    // Initial move count
    if(g_ulFlashMoveCount == 0xFFFFFF)
    {
        g_ulFlashMoveCount = 0x01;
    }
    else
    {
        g_ulFlashMoveCount++;
    }

    g_ucFlashLastPage = ucFreePage;

    usAddr = g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;
    UserCommonFlashErasePage(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[ucPageID]);

    {
        BYTE pucBuffer[5] = {0};

        pucBuffer[0] = ucPageID;
        pucBuffer[1] = (BYTE)(g_ulFlashMoveCount >> 16);
        pucBuffer[2] = (BYTE)(g_ulFlashMoveCount >> 8);
        pucBuffer[3] = (BYTE)g_ulFlashMoveCount;
        pucBuffer[4] = UserCommonFlashCalculateCheckSumData(pucBuffer, 4);
        pucBuffer[4] = (pucBuffer[4] & 0x7F);

        //ucVersionCode = _VERSION_CODE;
        //ucChecksum = _CHECKSUM;

        //UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
        //UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr + _PAGEINFO_PAGEID_ADDR, 4, pucBuffer);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr + _PAGEINFO_CHECKSUM_ADDR, 1, &pucBuffer[4]);
    }
}

//--------------------------------------------------
// Description  : Search the last saved item address, and next new item position
// Input Value  :
// Output Value :
//--------------------------------------------------
WORD RTDFlashSearchPageAddr(BYTE ucPageID)
{
    WORD usItemAddr = 0;
    WORD usPageAddr = 0;

    usPageAddr = g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

    // Find the last data item address
    for(usItemAddr = ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH); usItemAddr > 0; usItemAddr--)
    {
        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + (usItemAddr - 1) * _DATA_ITEM_LENGTH, 1, pData);
        if(pData[0] != 0xFF)
        {
            return usItemAddr;
        }
    }

    return 0;
}

//--------------------------------------------------
// Description  : Flash address initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashInitialAddr(void)
{
    BYTE ucCnt = 0;
    WORD usAddr = 0;
    DWORD ulMoveCount = 0;
    BYTE ucPageID = 0;
    BYTE pucData[4] = {0};
    DWORD ulMoveCountTemp = 0;

    g_ulFlashMoveCount = 0;
    g_ucFlashLastPage = _SYSTEM_EEPROM_EMULATION_START_PAGE;

    for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
    {
        g_pucFlashPageArr[ucPageID] = 0xFF;
    }

    // Find the page whose move count is the biggest and get the max move count
    for(ucCnt = _SYSTEM_EEPROM_EMULATION_START_PAGE; ucCnt < (_SYSTEM_EEPROM_EMULATION_END_PAGE + 1); ucCnt++)
    {
        // Check the page is valid or not
        if(RTDFlashIsPageInfoValid(ucCnt) == _TRUE)
        {
            usAddr = ucCnt * _FLASH_PAGE_SIZE + _PAGEINFO_PAGEID_ADDR;

            // Get the move count of current page
            UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr, 4, pucData);
            ulMoveCount = ((DWORD)(pucData[1]) << 16) | ((DWORD)(pucData[2]) << 8) | ((DWORD)(pucData[3]));

            // Get the max move count and its page index, ulMoveCount Only 3 Bytes, extra Judge 0xFFFFFF < 0x000001 Case
            if(((ulMoveCount >= g_ulFlashMoveCount) && (!((ulMoveCount == 0xFFFFFF) && (g_ulFlashMoveCount == 0x01)))) ||\
               ((ulMoveCount < g_ulFlashMoveCount) && ((ulMoveCount == 0x01) && (g_ulFlashMoveCount == 0xFFFFFF))))
            {
                g_pucFlashPageArr[pucData[0]] = ucCnt;
                g_ulFlashMoveCount = ulMoveCount;
                g_ucFlashLastPage = ucCnt;
            }
            // Check Other vaild page index
            else
            {
                if(g_pucFlashPageArr[pucData[0]] == 0xFF)
                {
                    g_pucFlashPageArr[pucData[0]] = ucCnt;
                }
                else // Check which page have begger Movecount
                {
                    usAddr = g_pucFlashPageArr[pucData[0]] * _FLASH_PAGE_SIZE + _PAGEINFO_MOVECOUNT_ADDR;
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr, 3, &pucData[1]);
                    ulMoveCountTemp = (((DWORD)(pucData[1]) << 16) | ((DWORD)(pucData[2]) << 8) | ((DWORD)(pucData[3])));
                    if(((ulMoveCount >= ulMoveCountTemp) && (!((ulMoveCount == 0xFFFFFF) && (ulMoveCountTemp == 0x01)))) ||\
                       ((ulMoveCount < ulMoveCountTemp) && ((ulMoveCount == 0x01) && (ulMoveCountTemp == 0xFFFFFF))))
                    {
                        g_pucFlashPageArr[pucData[0]] = ucCnt;
                    }
                }
            }
        }
    }

    // If this page is missing, intial this single page
    for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
    {
        if(g_pucFlashPageArr[ucPageID] == 0xFF)
        {
            // This function will increase g_ulFlashMovePage,and now g_ucFlashLastPage is the page index which has the biggest move count value
            RTDFlashInitialDataPage(ucPageID);
            //RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
        }
        else
        {
            // Initial g_pusFlashAddrArr
            g_pusFlashAddrArr[ucPageID] = RTDFlashSearchPageAddr(ucPageID);
        }
    }
}

//--------------------------------------------------
// Description  : Get the checksum and version code from flash
// Input Value  : pucChecksum: the checksum get from flash
//                pucVersionCode: the version code get from flash
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadChecksumVersioncode(BYTE *pucChecksum, BYTE *pucVersionCode)
{
    // Get the checksum and version code
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, pucChecksum);
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, pucVersionCode);
}

#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
extern void UserCommonInterfaceNVRamRestoreHDCP(void);
#endif

//--------------------------------------------------
// Description  : Save the checksum & version code to flash
// Input Value  : ucChecksum, checksum value
//                ucVersionCode, version code value
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveChecksumVersionCode(BYTE ucChecksum, BYTE ucVersionCode)
{
    BYTE ucVersionCodeRead = 0;
    BYTE ucChecksumRead = 0;

#if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)
	UserCommonInterfaceNVRamRestoreEDID();
#endif

#if((_D1_INPUT_PORT_TYPE!=_D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
			((_D2_INPUT_PORT_TYPE!=_D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
				((_D3_INPUT_PORT_TYPE!=_D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
				((_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
				((_D0_INPUT_PORT_TYPE!=_D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))
				
				UserCommonInterfaceNVRamSaveEDIDWhenProgramming();
#endif

				// HDCP Initial
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
		//UserCommonInterfaceNVRamRestoreHDCP();
#endif // End of #if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
			


    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCodeRead);
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksumRead);

    // Do not need save checksum or version code
    if((ucVersionCode == ucVersionCodeRead) && (ucChecksum == ucChecksumRead))
    {
        return;
    }
    // Need to save version code and checksum in current page
    else if((ucVersionCode != ucVersionCodeRead) && (ucVersionCodeRead == 0xFF) && (ucChecksum != ucChecksumRead) && (ucChecksumRead == 0xFF))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }
    // Need to save version code in current page
    else if((ucVersionCode != ucVersionCodeRead) && (ucVersionCodeRead == 0xFF) && (ucChecksum == ucChecksumRead))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
    }
    // Need to save checksum in current page
    else if((ucChecksum != ucChecksumRead) && (ucChecksumRead == 0xFF) && (ucVersionCode == ucVersionCodeRead))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }
    // Need to save checksum and version code to free page
    else
    {
        memset(pData, 0xFF, _DATA_ITEM_LENGTH);
        RTDFlashMoveData(_CHECKSUM_VERSIONCODE_ID, pData);

        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }
}

//--------------------------------------------------
// Description  : Move data to another page of flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDFlashMoveData(BYTE ucPageID, BYTE *pucData)
{
    BYTE ucPrevPage = g_pucFlashPageArr[ucPageID];
    BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
    BYTE ucItemIndex = 0;
    WORD usAddrIndex = 0;
    WORD usMovedItemCount = 0;
    BYTE ucChecksum = 0xFF;
    BYTE ucVersioncode = 0xFF;

    // Load checksum and version code
    if(pucData[0] != 0xFF)
    {
        RTDFlashLoadChecksumVersioncode(&ucChecksum, &ucVersioncode);
    }

    // Get free page data will move to
    ucFreePage = RTDFlashGetFreePage();

    // First sector erase the free page specified by g_ucFlashFreePage
    if(UserCommonFlashErasePage(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, ucFreePage) == _FALSE)
    {
        return _FALSE;
    }

    // Save the latest data item to the new page if need, when save checksum and version, it is not necessary
    // We do not save the item id at last because page info has not been saved
    if(pucData[0] != 0xFF)
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, ucFreePage * _FLASH_PAGE_SIZE + ucItemIndex, _DATA_ITEM_LENGTH, pucData);

        // Clear Buffer
        memset(pucData, 0xFF, _DATA_ITEM_LENGTH);

        // And then load the latest data items which saved in the old full page to the new page from bottom to top
        usMovedItemCount = 1;
    }
    else
    {
        usMovedItemCount = 0;
    }

    // Update ucFlashPage
    g_pucFlashPageArr[ucPageID] = ucFreePage;
    // Update move count value
    if(g_ulFlashMoveCount == 0xFFFFFF)
    {
        g_ulFlashMoveCount = 0x01;
    }
    else
    {
        g_ulFlashMoveCount++;
    }

    g_ucFlashLastPage = ucFreePage;

    {
        WORD usPrevPageAddr = ucPrevPage * _FLASH_PAGE_SIZE;
        WORD usPageAddr = g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

        // Find the valid item and move to new free page
        for(usAddrIndex = ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH); usAddrIndex > 0; usAddrIndex--)
        {
            BYTE ucItemID = 0;

            UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH, 1, &ucItemID);

            if(ucItemID != 0xFF)
            {
                WORD usMovedAddrIndex = 0;

                // Check the item has been moved or not by item ID
                for(usMovedAddrIndex = 0; usMovedAddrIndex < usMovedItemCount; usMovedAddrIndex++)
                {
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usMovedAddrIndex * _DATA_ITEM_LENGTH, 1, pData);
                    if(pData[0] == ucItemID)
                    {
                        break;
                    }
                }

                if(usMovedAddrIndex >= usMovedItemCount)
                {
                    // The item has not been moved, then check the item is valid or not
                    pucData[15] = 0;
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH, _DATA_ITEM_LENGTH - 1, pData);
                    pucData[15] = UserCommonFlashCalculateCheckSumData(pData, (_DATA_ITEM_LENGTH - 1));
                    pucData[15] = (pucData[15] & 0x7F);

                    // Check the checksum
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + usAddrIndex * _DATA_ITEM_LENGTH - 1, 1, pData);
                    if(pucData[15] != pData[0])
                    {
                        // Checksum check fail, the item is invalid
                        continue;
                    }

                    // Move the item to new free page
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH + ucItemIndex, _DATA_ITEM_LENGTH, pData);
                    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usMovedItemCount * _DATA_ITEM_LENGTH + ucItemIndex, _DATA_ITEM_LENGTH, pData);

                    usMovedItemCount++;
                }
            }
        }
    }

    // Update the data item address in the new page
    g_pusFlashAddrArr[ucPageID] = usMovedItemCount;

    // Last update the new moved page info fields
    // Save checksum & version code
    if(ucPageID == _CHECKSUM_VERSIONCODE_ID)
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersioncode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }

    // Save page info
    {
        BYTE pucBuffer[5] = {0};

        pucBuffer[0] = ucPageID;
        pucBuffer[1] = (BYTE)(g_ulFlashMoveCount >> 16);
        pucBuffer[2] = (BYTE)(g_ulFlashMoveCount >> 8);
        pucBuffer[3] = (BYTE)g_ulFlashMoveCount;
        pucBuffer[4] = UserCommonFlashCalculateCheckSumData(pucBuffer, 4);
        pucBuffer[4] = (pucBuffer[4] & 0x7F);

        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _PAGEINFO_PAGEID_ADDR, 4, pucBuffer);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_pucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _PAGEINFO_CHECKSUM_ADDR, 1, &pucBuffer[4]);
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Flash check at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashStartup(void)
{
    BYTE ucChecksum = 0;
    BYTE ucVersionCode = 0;
    BYTE ucPageID = 0;

    RTDFlashInitialAddr();

    // Get FW checksum and version code
    RTDFlashLoadChecksumVersioncode(&ucChecksum, &ucVersionCode);

	//UserCommonInterfaceNVRamSaveEDIDWhenProgramming();

    if(ucChecksum != _CHECKSUM) // ����key������EDID�и�������û����
    {
        // Checksum is changed, load default value and save to flash
        for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
        {
            RTDFlashInitialDataPage(ucPageID);
        }

        RTDFlashWholeRestore();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashRestorePanelIndex();
#endif

        RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
    }
    else if(ucVersionCode != _VERSION_CODE)
    {
        // Restore CT User color setting
        g_stColorProcData = tColorTempDefaultData[_CT_USER];
        if(UserCommonFlashLoadItem(_FLASH_ITEMID_COLORPROC_START + _CT_USER, pData, 1) == _TRUE)
        {
            RTDFlashSaveColorSetting(_CT_USER);
        }

        UserCommonFlashRestoreSystemData();
        RTDFlashRestoreOSDData();

#if(_VGA_SUPPORT == _ON)
        UserCommonFlashRestoreModeUserData();
#endif

        RTDFlashRestoreBriCon();
        //RTDFlashRestoreSixColorData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashLoadPanelIndex();
#endif

        RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
    }
    else
    {
        UserCommonFlashLoadSystemData();
        RTDFlashLoadOSDData();
        //RTDFlashLoadSixColorData();
        RTDFlashLoadPanelUsedTimeData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashLoadPanelIndex();
#endif

        // Check PCM Flag
        if(GET_OSD_PCM_STATUS() > _PCM_OSD_AMOUNT)
        {
            SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
            RTDFlashSaveOSDData();
        }

#if(_OSD_3D_FUNCTION == _ON)
        if((GET_OSD_3DOSD_STATUS() == _ON) &&
           ((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
            (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)))
        {
            SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_0);
            RTDFlashSaveOSDData();
        }
#endif
    }
    TPVNVRamLoadFactoryDate();

	
	//SET_AUTO_SLEEP_STATUS(_SleepPowerSaving_OFF);


	RTDFlashLoadSceneModeData(GET_OSD_GAME_MODE());


    RTDFlashLoadColorSetting(GET_COLOR_TEMP_TYPE());

	#if 0//_GSYNC_TEST
		if(GET_OSD_FREE_SYNC_STATUS())
		    SET_OSD_PRE_GAME_FPS(_ON);
		else
			SET_OSD_PRE_GAME_FPS(_OFF);
	#endif
}

//--------------------------------------------------
// Description  : Load default data and save to Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashWholeRestore(void)
{

#if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)
		//UserCommonInterfaceNVRamRestoreEDID();
#endif

#if((_D1_INPUT_PORT_TYPE!=_D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
	((_D2_INPUT_PORT_TYPE!=_D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D3_INPUT_PORT_TYPE!=_D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D0_INPUT_PORT_TYPE!=_D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))

		//UserCommonInterfaceNVRamSaveEDIDWhenProgramming();
#endif
    UserCommonFlashRestoreSystemData();
    RTDFlashRestoreOSDData();


#if(_VGA_SUPPORT == _ON)
    UserCommonFlashRestoreModeUserData();
    UserCommonFlashRestoreADCSetting();
#endif

    RTDFlashRestoreBriCon();
    RTDFlashRestoreColorSetting();
    //RTDFlashRestoreSixColorData();
    RTDFlashRestorePanelUsedTimeData();

	
	//RTDFlashRestoreViewModeParameters();
}

//--------------------------------------------------
// Description  : Restore default backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreBacklight(void)
{
    BYTE ucItemOffset = 0;

    SET_OSD_BACKLIGHT(g_stOSDDefaultData.usBackLight);

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserCommonFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, 1) == _FALSE)
        {
            return;
        }
    }

    RTDFlashSaveOSDData();
}

//--------------------------------------------------
// Description  : Load OSD data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadOSDData(void)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructOsdUserDataType);

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserCommonFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, _DATA_ITEM_LENGTH - 2) == _FALSE)
        {
            g_stOSDUserData = g_stOSDDefaultData;
            return;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            memcpy((((BYTE *)(&g_stOSDUserData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, (_DATA_ITEM_LENGTH - 2));
            ucStructLen = ucStructLen - (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            memcpy((((BYTE *)(&g_stOSDUserData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, ucStructLen);
            break;
        }
    }

#if(_DP_MST_SUPPORT == _ON)
    if((GET_OSD_DP_MST() != _MST_OFF) && (SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT))
    {
        SET_OSD_DP_MST(_MST_OFF);
    }
#endif
}


//--------------------------------------------------
// Description  : Save OSD data to Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveOSDData(void)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructOsdUserDataType);

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            UserCommonFlashSaveItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), (((BYTE *)(&g_stOSDUserData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), _DATA_ITEM_LENGTH - 2);
            ucStructLen -= (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            UserCommonFlashSaveItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), (((BYTE *)(&g_stOSDUserData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), ucStructLen);
            break;
        }
    }
}

//--------------------------------------------------
// Description  : Restore default OSD data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreOSDData(void)
{
    BYTE ucItemOffset = 0;

    g_stOSDUserData = g_stOSDDefaultData;

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserCommonFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, 1) == _FALSE)
        {
            return;
        }
    }

    RTDFlashSaveOSDData();
}

//--------------------------------------------------
// Description  : Load brightness/contrast from Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadBriCon(BYTE ucSource)
{
    if(ucSource >= _SOURCE_AMOUNT)
    {
        return;
    }

    if(UserCommonFlashLoadItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSource, pData, sizeof(StructBriConDataType)) == _TRUE)
    {
        memcpy(&g_stBriConData, pData, sizeof(StructBriConDataType));
    }
    else
    {
        g_stBriConData = tBriConDefaultData[ucSource];
    }
}

//--------------------------------------------------
// Description  : Save brightness/contrast to Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveBriCon(BYTE ucSource)
{
    UserCommonFlashSaveItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSource, (BYTE *)(&g_stBriConData), sizeof(StructBriConDataType));
}

//--------------------------------------------------
// Description  : Restore default brightness/contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreBriCon(void)
{
    BYTE ucSourceIndex = 0;

    for(ucSourceIndex = 0; ucSourceIndex < _SOURCE_AMOUNT; ucSourceIndex++)
    {
        g_stBriConData = tBriConDefaultData[ucSourceIndex];

        if(UserCommonFlashLoadItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSourceIndex, pData, 1) == _TRUE)
        {
            RTDFlashSaveBriCon(ucSourceIndex);
        }
    }
}



//--------------------------------------------------
// Description  : Load SceneMode Data from Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadVMData(BYTE ucGameMode)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructVscSceneModeDataType);
	
    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructVscSceneModeDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_SCENEMODE0_END - _FLASH_ITEMID_SCENEMODE0_START + 1))
        {
            break;
        }

        if(UserCommonFlashLoadItem((_FLASH_ITEMID_SCENEMODE0_START + ((_FLASH_ITEMID_SCENEMODE0_END - _FLASH_ITEMID_SCENEMODE0_START + 1) * ucGameMode) + ucItemOffset), pData, _DATA_ITEM_LENGTH - 2) == _FALSE)
        {
            g_stVscSceneModeData = tVscSceneModeDefaultData[ucGameMode];//_GM_OFF];
            return;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            memcpy((((BYTE*)(&g_stVscSceneModeData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, (_DATA_ITEM_LENGTH - 2));
            ucStructLen = ucStructLen - (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            memcpy((((BYTE*)(&g_stVscSceneModeData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, ucStructLen);
            break;
        }
    }

}



//--------------------------------------------------
// Description  : Load SceneMode Data from Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadSceneModeData(BYTE ucGameMode)
{	
    if((ucGameMode == _GM_OFF) && (GET_OSD_VIEWMODE_TYPE() != _VM_STANDARD))
    {
        ucGameMode = _GM_OFF + (GET_OSD_VIEWMODE_TYPE() - 1);
    }
	//DebugMessageOsd("2.LOAD_ucGameMode",ucGameMode);

    RTDFlashLoadVMData(ucGameMode);
	
}


//--------------------------------------------------
// Description  : Save SceneMode Data to Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveVMData(BYTE ucGameMode)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructVscSceneModeDataType);
	//DebugMessageOsd("1.SAVE_ucGameMode",ucGameMode);
    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructVscSceneModeDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_SCENEMODE0_END - _FLASH_ITEMID_SCENEMODE0_START + 1))
        {
            break;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            UserCommonFlashSaveItem((_FLASH_ITEMID_SCENEMODE0_START + ((_FLASH_ITEMID_SCENEMODE0_END - _FLASH_ITEMID_SCENEMODE0_START + 1) * ucGameMode) + ucItemOffset), (((BYTE*)(&g_stVscSceneModeData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), _DATA_ITEM_LENGTH - 2);
            ucStructLen -= (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            UserCommonFlashSaveItem((_FLASH_ITEMID_SCENEMODE0_START + ((_FLASH_ITEMID_SCENEMODE0_END - _FLASH_ITEMID_SCENEMODE0_START + 1) * ucGameMode)+ ucItemOffset), (((BYTE*)(&g_stVscSceneModeData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), ucStructLen);
            break;
        }
    }
}



//--------------------------------------------------
// Description  : Save SceneMode Data to Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveSceneModeData(BYTE ucGameMode)
{

    if((ucGameMode == _GM_OFF) && (GET_OSD_VIEWMODE_TYPE() != _VM_STANDARD))
    {
        ucGameMode = _GM_OFF + (GET_OSD_VIEWMODE_TYPE() - 1);
    }

    RTDFlashSaveVMData(ucGameMode);
}

//--------------------------------------------------
// Description  : Restore default
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreViewModeParameters(void)
{	
#if 0
	g_stVscSceneModeData = tVscSceneModeDefaultData[GET_OSD_GAME_MODE()];
	RTDFlashSaveSceneModeData(GET_OSD_GAME_MODE());
#else
	BYTE ucViewMode;
	for(ucViewMode=0; ucViewMode < (_VIEWMODE_AMOUNT+3); ucViewMode++)
	{
		g_stVscSceneModeData = tVscSceneModeDefaultData[ucViewMode];
		//RTDFlashSaveSceneModeData(ucViewMode);

		g_stVscSceneModeData.usBackLightSrgb = GET_OSD_BACKLIGHT_SRGB();
        if(ucViewMode == _VM_TEXT + 3)
        {
			g_stVscSceneModeData.usBackLightNormal = GET_OSD_BACKLIGHT_SRGB();
        }

		RTDFlashSaveVMData(ucViewMode);

	}
	
	g_stVscSceneModeData = tVscSceneModeDefaultData[_GM_OFF];	//��ԭ�ɱ�׼ģʽ����ֵ	xwei_i
	g_stVscSceneModeData.usBackLightSrgb = GET_OSD_BACKLIGHT_SRGB();
#endif
}

void RTDFlashRestoreBriConOnly(void)
{
    BYTE ucGameMode = 0;
	ucGameMode = GET_OSD_GAME_MODE();
	
    if((ucGameMode == _GM_OFF) && (GET_OSD_VIEWMODE_TYPE() != _VM_STANDARD))
    {
        ucGameMode = _GM_OFF + (GET_OSD_VIEWMODE_TYPE() - 1);
    }

    g_stVscSceneModeData.usBackLightNormal = tVscSceneModeDefaultData[ucGameMode].usBackLightNormal;
    g_stVscSceneModeData.usContrast = tVscSceneModeDefaultData[ucGameMode].usContrast;
    g_stVscSceneModeData.usBackLightSrgb = tVscSceneModeDefaultData[ucGameMode].usBackLightSrgb;
}
//--------------------------------------------------
// Description  : Load color settings from Flash
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadColorSetting(BYTE ucColorTempType)
{
#if 0//(_OGC_SUPPORT == _ON)
    if(GET_OSD_GAMMA() != _GAMMA_OFF)
    {
        UserCommonAdjustOGCColorTempGain(ucColorTempType, (GET_OSD_GAMMA() - 1), pData, _OGC_NORMAL_TYPE);

#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
        g_stColorProcData.usColorTempR = PDATA_WORD(0);
        g_stColorProcData.usColorTempG = PDATA_WORD(1);
        g_stColorProcData.usColorTempB = PDATA_WORD(2);
#elif(_CTS_TYPE == _CTS_GEN_0_8BIT)
        g_stColorProcData.usColorTempR = pData[0];
        g_stColorProcData.usColorTempG = pData[1];
        g_stColorProcData.usColorTempB = pData[2];
#endif
        return;
    }
#endif

#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
    if(GET_OSD_GAMMA(ucRegion) != _GAMMA_OFF)
    {
        g_stColorProcData.usColorTempR = 0x800;
        g_stColorProcData.usColorTempG = 0x800;
        g_stColorProcData.usColorTempB = 0x800;
        return;
    }
#endif

	//DebugMessageOsd("1.ucColorTempType",ucColorTempType);
    if(UserCommonFlashLoadItem(_FLASH_ITEMID_COLORPROC_START + ucColorTempType, pData, sizeof(StructColorProcDataType)) == _TRUE)
    {
        memcpy(&g_stColorProcData, pData, sizeof(StructColorProcDataType));
    }
    else
    {
        g_stColorProcData = tColorTempDefaultData[ucColorTempType];
    }
}


//--------------------------------------------------
// Description  : Save color settings to Flash
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveColorSetting(BYTE ucColorTempType)
{
    //UserInterfaceGetNVRamDataStatus(_CHECK_USER_COLOR_DATA);
    UserCommonFlashSaveItem(_FLASH_ITEMID_COLORPROC_START + ucColorTempType, (BYTE *)(&g_stColorProcData), sizeof(StructColorProcDataType));
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreColorSetting(void)
{
    BYTE ucColorTempIndex = 0;

    for(ucColorTempIndex = 0; ucColorTempIndex < (_CT_COLORTEMP_AMOUNT+8); ucColorTempIndex++)
    {
        g_stColorProcData = tColorTempDefaultData[ucColorTempIndex];

        if(UserCommonFlashLoadItem(_FLASH_ITEMID_COLORPROC_START + ucColorTempIndex, pData, 1) == _TRUE)
        {
            RTDFlashSaveColorSetting(ucColorTempIndex);
        }
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreUserColorSetting(void)
{
	g_stColorProcData = tColorTempDefaultData[_CT_USER];
	RTDFlashSaveColorSetting(_CT_USER);

/*
    StructColorProcDataType stUserColorTemp = {0};

    if(UserCommonFlashLoadItem(_FLASH_ITEMID_COLORPROC5_USER, pData, 1) == _TRUE)
    {
        stUserColorTemp = g_stColorProcData;
        g_stColorProcData = tColorTempDefaultData[_CT_USER];
        RTDFlashSaveColorSetting(_CT_USER);
        g_stColorProcData = stUserColorTemp;
    }
    */
}
/*
//--------------------------------------------------
// Description  : Load six color data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadSixColorData(void)
{
    if(UserCommonFlashLoadItem(_FLASH_ITEMID_SIXCOLOR_DATA, pData, sizeof(StructSixColorDataType)) == _TRUE)
    {
        memcpy((BYTE *)(&g_stSixColorData), pData, sizeof(StructSixColorDataType));
    }
    else
    {
        g_stSixColorData = g_stSixColorDefaultData;
    }
}

//--------------------------------------------------
// Description  : Save six color data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveSixColorData(void)
{
    UserCommonFlashSaveItem(_FLASH_ITEMID_SIXCOLOR_DATA, (BYTE *)(&g_stSixColorData), sizeof(StructSixColorDataType));
}

//--------------------------------------------------
// Description  : Restore default six color data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreSixColorData(void)
{
    g_stSixColorData = g_stSixColorDefaultData;

    if(UserCommonFlashLoadItem(_FLASH_ITEMID_SIXCOLOR_DATA, pData, 1) == _TRUE)
    {
        RTDFlashSaveSixColorData();
    }
}*/


#if(_DEF_DDCCI_EDID_TOOL)
/*
void RTDFlashGetSNData(void)
{
#if(_PROJECT_ID==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD120_VA240A_H_20240812)
	BYTE g_FlashSNData[_SN_NUMBER_AMOUNT+1]="XZ0123456789";
#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD144_VA24G25_20241213)
	BYTE g_FlashSNData[_SN_NUMBER_AMOUNT+1]="XZ0123456789";
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223)
	BYTE g_FlashSNData[_SN_NUMBER_AMOUNT+1]="XLK230100001";
#else
	BYTE g_FlashSNData[_SN_NUMBER_AMOUNT+1]="XZ1123456789";
#endif
    BYTE ucItemOffset = 0;
	BYTE NavData[28] = {0};
    BYTE ucStructLen = sizeof(g_stSNData);


    for(ucItemOffset = 0; ucItemOffset < ((sizeof(g_stSNData) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_SN_1 - _FLASH_ITEMID_SN_0 + 1))
        {
            break;
        }

        if(UserCommonFlashLoadItem((_FLASH_ITEMID_SN_0 + ucItemOffset), NavData, _DATA_ITEM_LENGTH - 2) == _FALSE)
        {
            memcpy(g_stSNData, g_FlashSNData , _SN_NUMBER_AMOUNT); 
            return;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            memcpy((((BYTE *)(&g_stSNData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), NavData, (_DATA_ITEM_LENGTH - 2));
            ucStructLen = ucStructLen - (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            memcpy((((BYTE *)(&g_stSNData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), NavData, ucStructLen);
            break;
        }
    
	}
}

//--------------------------------------------------
// Description      : Write serial number
// Input Value      : None
// Output Value     : SN data address
//--------------------------------------------------
void RTDFlashSaveSNData(void)
{

    //UserCommonFlashSaveItem(_FLASH_ITEMID_SN, NavData, _SN_NUMBER_AMOUNT);
		BYTE ucItemOffset = 0;
		BYTE ucStructLen = sizeof(g_stSNData);
	
		for(ucItemOffset = 0; ucItemOffset < ((sizeof(g_stSNData) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
		{
			// Here we check the total item number, it could not be smaller than the osd structure
			if(ucItemOffset > (_FLASH_ITEMID_SN_1 - _FLASH_ITEMID_SN_0 + 1))
			{
				break;
			}
	
			if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
			{
				UserCommonFlashSaveItem((_FLASH_ITEMID_SN_0 + ucItemOffset), (((BYTE *)(&g_stSNData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), _DATA_ITEM_LENGTH - 2);
				ucStructLen -= (_DATA_ITEM_LENGTH - 2);
			}
			else
			{
				UserCommonFlashSaveItem((_FLASH_ITEMID_SN_0 + ucItemOffset), (((BYTE *)(&g_stSNData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), ucStructLen);
				break;
			}
		}

}
*/
#endif



//--------------------------------------------------
// Description  : Load Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadPanelUsedTimeData(void)
{
    if(UserCommonFlashLoadItem(_FLASH_ITEMID_PANEL_DATA, pData, sizeof(StructTimeType)) == _TRUE)
    {
        memcpy((BYTE *)(&g_stPanelTimeData), pData, sizeof(StructTimeType));
    }
    else
    {
        SET_PANEL_TIME_HOUR(0);
        SET_PANEL_TIME_MIN(0);

        SET_PANEL_BURN_TIME_HOUR(0);
        SET_PANEL_BURN_TIME_MIN(0);
    }
}

//--------------------------------------------------
// Description  : Save Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSavePanelUsedTimeData(void)
{
    UserCommonFlashSaveItem(_FLASH_ITEMID_PANEL_DATA, (BYTE *)(&g_stPanelTimeData), sizeof(StructTimeType));
}

//--------------------------------------------------
// Description  : Restore Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------



void RTDFlashRestorePanelUsedTimeData(void)
{
    SET_PANEL_TIME_HOUR(0);
    SET_PANEL_TIME_MIN(0);
    SET_PANEL_BURN_TIME_HOUR(0);
    SET_PANEL_BURN_TIME_MIN(0);

    if(UserCommonFlashLoadItem(_FLASH_ITEMID_PANEL_DATA, pData, 1) == _TRUE)
    {
        RTDFlashSavePanelUsedTimeData();
    }
}

#if(_PANEL_EXIST_MULTIPANEL == _ON)
//--------------------------------------------------
// Description  : Load panel index from flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadPanelIndex(void)
{
    if(UserCommonFlashLoadItem(_FLASH_ITEMID_PANEL_INDEX, pData, 1) == _TRUE)
    {
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
    }
    else
    {
        SET_MDOMAIN_PANEL_INDEX(0);
    }
}

//--------------------------------------------------
// Description  : Save panel index to flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSavePanelIndex(void)
{
    BYTE ucPanelIndex = 0;

    ucPanelIndex = GET_MDOMAIN_PANEL_INDEX();

    UserCommonFlashSaveItem(_FLASH_ITEMID_PANEL_INDEX, &ucPanelIndex, 1);
}

//--------------------------------------------------
// Description  : Restore panel index
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestorePanelIndex(void)
{
    SET_MDOMAIN_PANEL_INDEX(0);

    if(UserCommonFlashLoadItem(_FLASH_ITEMID_PANEL_INDEX, pData, 1) == _TRUE)
    {
        RTDFlashSavePanelIndex();
    }
}
#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _ON)

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
// //--------------------------------------------------
// // Description  : Transfer Osd Region Type
// // Input Value  : ucDisplayMode --> Display mode
// //                     ucRegion --> Display region
// // Output Value : _INSIDE / _OUTSIDE
// //--------------------------------------------------
// BYTE RTDNVRamTransferOsdRegionType(BYTE ucDisplayMode, BYTE ucRegion)
// {
//     BYTE ucType = 0;

//     if(GET_OSD_HLWIN_TYPE() != _HL_WIN_OFF)
//     {
//         ucType = ucRegion % 2;
//     }
//     else
//     {
//         switch(ucDisplayMode)
//         {
//             case _OSD_DM_1P:
//                 ucType = _INSIDE;
//                 break;

//             case _OSD_DM_2P_LR:
//                 if(ucRegion == _OSD_SR_2P_LR_R)
//                 {
//                     ucType = _INSIDE;
//                 }
//                 else
//                 {
//                     ucType = _OUTSIDE;
//                 }
//                 break;

//             case _OSD_DM_2P_TB:
//                 if(ucRegion == _OSD_SR_2P_TB_B)
//                 {
//                     ucType = _INSIDE;
//                 }
//                 else
//                 {
//                     ucType = _OUTSIDE;
//                 }
//                 break;

//             case _OSD_DM_2P_PIP:
//                 if(ucRegion == _OSD_SR_2P_PIP_SUB)
//                 {
//                     ucType = _INSIDE;
//                 }
//                 else
//                 {
//                     ucType = _OUTSIDE;
//                 }
//                 break;

//             case _OSD_DM_3P_FLAG:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_3P_FLAG_MAIN:
//                     case _OSD_SR_3P_FLAG_L:
//                     case _OSD_SR_3P_FLAG_R:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;

//             case _OSD_DM_3P_SKEW_L:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_3P_SKEW_L_MAIN:
//                     case _OSD_SR_3P_SKEW_L_UP:
//                     case _OSD_SR_3P_SKEW_L_DOWN:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;

//             case _OSD_DM_3P_SKEW_R:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_3P_SKEW_R_MAIN:
//                     case _OSD_SR_3P_SKEW_R_UP:
//                     case _OSD_SR_3P_SKEW_R_DOWN:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;
//             case _OSD_DM_3P_SKEW_T:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_3P_SKEW_T_MAIN:
//                     case _OSD_SR_3P_SKEW_T_LEFT:
//                     case _OSD_SR_3P_SKEW_T_RIGHT:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;
//             case _OSD_DM_3P_SKEW_B:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_3P_SKEW_B_MAIN:
//                     case _OSD_SR_3P_SKEW_B_LEFT:
//                     case _OSD_SR_3P_SKEW_B_RIGHT:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;
//             case _OSD_DM_4P:
//                 switch(ucRegion)
//                 {
//                     case _OSD_SR_4P_LT_INSIDE:
//                     case _OSD_SR_4P_LB_INSIDE:
//                     case _OSD_SR_4P_RT_INSIDE:
//                     case _OSD_SR_4P_RB_INSIDE:
//                         ucType = _INSIDE;
//                         break;

//                     default:
//                         ucType = _OUTSIDE;
//                         break;
//                 }
//                 break;

//             default:
//                 break;
//         }
//     }

//     return ucType;
// }

// //--------------------------------------------------
// // Description  : Transfer Osd Region index
// // Input Value  : ucDisplayMode --> Display mode
// //                     ucRegion --> Display region
// // Output Value : _INSIDE / _OUTSIDE
// //--------------------------------------------------
// BYTE RTDNVRamTransferOsdRegionIndex(BYTE ucDisplayMode, BYTE ucRegion)
// {
//     BYTE ucIndex = 0;

//     switch(ucDisplayMode)
//     {
//         case _OSD_DM_1P:
//             ucIndex = 0;
//             break;

//         case _OSD_DM_2P_LR:
//             if(ucRegion >= _OSD_SR_2P_LR_FULL)
//             {
//                 ucRegion = _OSD_SR_2P_LR_L;
//             }
//             ucIndex = 2 + ucRegion;
//             break;

//         case _OSD_DM_2P_TB:
//             if(ucRegion >= _OSD_SR_2P_TB_FULL)
//             {
//                 ucRegion = _OSD_SR_2P_TB_T;
//             }
//             ucIndex = 4 + ucRegion;
//             break;

//         case _OSD_DM_2P_PIP:
//             if(ucRegion >= _OSD_SR_2P_PIP_FULL)
//             {
//                 ucRegion = _OSD_SR_2P_PIP_MAIN;
//             }
//             ucIndex = 6 + ucRegion;
//             break;

//         case _OSD_DM_3P_FLAG:
//             if(ucRegion >= _OSD_SR_3P_FLAG_FULL)
//             {
//                 ucRegion = _OSD_SR_3P_FLAG_MAIN;
//             }
//             ucIndex = 8 + (ucRegion % 2);
//             break;

//         case _OSD_DM_3P_SKEW_L:
//             if(ucRegion >= _OSD_SR_3P_SKEW_L_FULL)
//             {
//                 ucRegion = _OSD_SR_3P_SKEW_L_MAIN;
//             }
//             ucIndex = 10 + (ucRegion % 2);
//             break;

//         case _OSD_DM_3P_SKEW_R:
//             if(ucRegion >= _OSD_SR_3P_SKEW_R_FULL)
//             {
//                 ucRegion = _OSD_SR_3P_SKEW_R_MAIN;
//             }
//             ucIndex = 12 + (ucRegion % 2);
//             break;
//         case _OSD_DM_3P_SKEW_T:
//             if(ucRegion >= _OSD_SR_3P_SKEW_T_FULL)
//             {
//                 ucRegion = _OSD_SR_3P_SKEW_T_MAIN;
//             }
//             ucIndex = 14 + (ucRegion % 2);
//             break;
//         case _OSD_DM_3P_SKEW_B:
//             if(ucRegion >= _OSD_SR_3P_SKEW_B_FULL)
//             {
//                 ucRegion = _OSD_SR_3P_SKEW_B_MAIN;
//             }
//             ucIndex = 16 + (ucRegion % 2);
//             break;
//         case _OSD_DM_4P:
//             if(ucRegion >= _OSD_SR_4P_FULL)
//             {
//                 ucRegion = _OSD_SR_4P_LT_OUTSIDE;
//             }
//             ucIndex = 18 + (ucRegion % 2);
//             break;

//         default:
//             break;
//     }

//     return ucIndex;
// }

#endif // #if(_OSD_TYPE == _REALTEK_2014_OSD)
