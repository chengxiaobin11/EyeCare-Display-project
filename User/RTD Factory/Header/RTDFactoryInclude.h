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

//****************************************************************************
// LAYER DEFINITIONS / MACROS of FactoryMode.c
//****************************************************************************

#if (_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _FACTORY_OSD_ROW                            24
#define _FACTORY_OSD_COL                            26
#else
#define _FACTORY_OSD_ROW                            26

#define _FACTORY_OSD_COL                            34
#endif
#define _FACTORY_OSD_WIDTH                          (_FACTORY_OSD_COL * 12)

#define _FACTORY_OSD_WINDOW_SIZE_X                  (_FACTORY_OSD_COL * 12 )
#define _FACTORY_OSD_WINDOW_SIZE_Y                  (_FACTORY_OSD_ROW * 18)
#define _ROTATE_FACTORY_OSD_WINDOW_OFFSET           7

#define _FACTORY_OSD                                0
//--------------------------------------------------
// Definitions of OSD H Position Range
//--------------------------------------------------
#define _FACTORY_OSD_H_POS_MAX                      200
#define _FACTORY_OSD_H_POS_MIN                      0
#define _FACTORY_OSD_H_POS_CENTER                   (((_FACTORY_OSD_H_POS_MAX - _FACTORY_OSD_H_POS_MIN) / 2) + _FACTORY_OSD_H_POS_MIN)
//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _FACTORY_OSD_V_POS_MAX                      200
#define _FACTORY_OSD_V_POS_MIN                      0
#define _FACTORY_OSD_V_POS_CENTER                   (((_FACTORY_OSD_V_POS_MAX - _FACTORY_OSD_V_POS_CENTER) / 2) + _FACTORY_OSD_V_POS_MIN)

//--------------------------------------------------
// Definitions of OSD Font Pointer
//--------------------------------------------------
#define _PFONT_FACTORY_PAGE_0                       0
#define _PFONT_FACTORY_PAGE_1                       1

#define _PFONT_FACTORY_PAGE_ITEM_1                  2
#define _PFONT_FACTORY_PAGE_ITEM_2                  3
#define _PFONT_FACTORY_PAGE_ITEM_3                  4
#define _PFONT_FACTORY_PAGE_ITEM_4                  5
#define _PFONT_FACTORY_PAGE_ITEM_5                  6
#define _PFONT_FACTORY_PAGE_ITEM_6                  7
#define _PFONT_FACTORY_PAGE_ITEM_7                  8
#define _PFONT_FACTORY_PAGE_ITEM_8                  9
#define _PFONT_FACTORY_PAGE_ITEM_9                  10
#define _PFONT_FACTORY_PAGE_ITEM_10                 11

#define _PFONT_FACTORY_PAGE_ITEM_11                 12
#define _PFONT_FACTORY_PAGE_ITEM_12                 13
#define _PFONT_FACTORY_PAGE_ITEM_13                 14
#define _PFONT_FACTORY_PAGE_ITEM_14                 15
#define _PFONT_FACTORY_PAGE_ITEM_15                 16
#define _PFONT_FACTORY_PAGE_ITEM_16                 17
#define _PFONT_FACTORY_PAGE_ITEM_17                 18
#define _PFONT_FACTORY_PAGE_ITEM_18                 19
#define _PFONT_FACTORY_PAGE_ITEM_19                 20
#define _PFONT_FACTORY_PAGE_ITEM_20                 21

#define _PFONT_FACTORY_PAGE_ITEM_21                 22
#define _PFONT_FACTORY_PAGE_ITEM_22                 23
#define _PFONT_FACTORY_PAGE_ITEM_23                 24
#define _PFONT_FACTORY_PAGE_ITEM_24                 25
#define _PFONT_FACTORY_PAGE_ITEM_25                 26
#define _PFONT_FACTORY_PAGE_ITEM_26                 27
#define _PFONT_FACTORY_PAGE_ITEM_27                 28
#define _PFONT_FACTORY_PAGE_ITEM_28                 29
#define _PFONT_FACTORY_PAGE_ITEM_29                 30
#define _PFONT_FACTORY_PAGE_ITEM_30                 31
#define _PFONT_FACTORY_PAGE_ITEM_31                 32
#define _PFONT_FACTORY_PAGE_ITEM_32                 33
#define _PFONT_FACTORY_PAGE_ITEM_33                 34
#define _PFONT_FACTORY_PAGE_ITEM_34                 35
#define _PFONT_FACTORY_PAGE_ITEM_35                 36
#define _PFONT_FACTORY_PAGE_ITEM_END                37

#define _PFONT_FACTORY_AUTO_COLOR                   _PFONT_FACTORY_PAGE_ITEM_1
#define _PFONT_FACTORY_BURNIN                       _PFONT_FACTORY_PAGE_ITEM_2

#define _PFONT_FACTORY_BURNIN_TIME_HOUR             _PFONT_FACTORY_PAGE_ITEM_3
#define _PFONT_FACTORY_BURNIN_TIME_MIN              _PFONT_FACTORY_PAGE_ITEM_4

#define _PFONT_FACTORY_DFM                          _PFONT_FACTORY_PAGE_ITEM_3
#define _PFONT_FACTORY_TD_RESECT                    _PFONT_FACTORY_PAGE_ITEM_4

#define _PFONT_FACTORY_PANEL_TIME_HOUR              _PFONT_FACTORY_PAGE_ITEM_5
#define _PFONT_FACTORY_PANEL_TIME_MIN               _PFONT_FACTORY_PAGE_ITEM_6
#define _PFONT_FACTORY_COLORTEMP1_R                 _PFONT_FACTORY_PAGE_ITEM_7
#define _PFONT_FACTORY_COLORTEMP1_G                 _PFONT_FACTORY_PAGE_ITEM_8
#define _PFONT_FACTORY_COLORTEMP1_B                 _PFONT_FACTORY_PAGE_ITEM_9
#define _PFONT_FACTORY_COLORTEMP2_R                 _PFONT_FACTORY_PAGE_ITEM_10
#define _PFONT_FACTORY_COLORTEMP2_G                 _PFONT_FACTORY_PAGE_ITEM_11
#define _PFONT_FACTORY_COLORTEMP2_B                 _PFONT_FACTORY_PAGE_ITEM_12
#define _PFONT_FACTORY_COLORTEMP3_R                 _PFONT_FACTORY_PAGE_ITEM_13
#define _PFONT_FACTORY_COLORTEMP3_G                 _PFONT_FACTORY_PAGE_ITEM_14
#define _PFONT_FACTORY_COLORTEMP3_B                 _PFONT_FACTORY_PAGE_ITEM_15
#define _PFONT_FACTORY_COLORTEMP4_R                 _PFONT_FACTORY_PAGE_ITEM_16
#define _PFONT_FACTORY_COLORTEMP4_G                 _PFONT_FACTORY_PAGE_ITEM_17
#define _PFONT_FACTORY_COLORTEMP4_B                 _PFONT_FACTORY_PAGE_ITEM_18
#define _PFONT_FACTORY_COLORTEMP5_R                 _PFONT_FACTORY_PAGE_ITEM_19
#define _PFONT_FACTORY_COLORTEMP5_G                 _PFONT_FACTORY_PAGE_ITEM_20
#define _PFONT_FACTORY_COLORTEMP5_B                 _PFONT_FACTORY_PAGE_ITEM_21
#define _PFONT_FACTORY_COLORTEMP6_R                 _PFONT_FACTORY_PAGE_ITEM_22
#define _PFONT_FACTORY_COLORTEMP6_G                 _PFONT_FACTORY_PAGE_ITEM_23
#define _PFONT_FACTORY_COLORTEMP6_B                 _PFONT_FACTORY_PAGE_ITEM_24
#define _PFONT_FACTORY_ADC_GAIN_R                   _PFONT_FACTORY_PAGE_ITEM_25
#define _PFONT_FACTORY_ADC_GAIN_G                   _PFONT_FACTORY_PAGE_ITEM_26
#define _PFONT_FACTORY_ADC_GAIN_B                   _PFONT_FACTORY_PAGE_ITEM_28
#define _PFONT_FACTORY_ADC_OFFSET_R                 _PFONT_FACTORY_PAGE_ITEM_29
#define _PFONT_FACTORY_ADC_OFFSET_G                 _PFONT_FACTORY_PAGE_ITEM_30
#define _PFONT_FACTORY_ADC_OFFSET_B                 _PFONT_FACTORY_PAGE_ITEM_31

#define _PFONT_FACTORY_LOGO                         _PFONT_FACTORY_PAGE_ITEM_32

#define _PFONT_FACTORY_OSD_PAGE                     _PFONT_FACTORY_PAGE_ITEM_32
#define _PFONT_FACTORY_AUTO_COLOR_TYPE              _PFONT_FACTORY_PAGE_ITEM_33

#define _PFONT_FACTORY_BACKGROUND_ON_OFF            _PFONT_FACTORY_PAGE_ITEM_1
#define _PFONT_FACTORY_BACKGROUND_COLOR_R           _PFONT_FACTORY_PAGE_ITEM_2
#define _PFONT_FACTORY_BACKGROUND_COLOR_G           _PFONT_FACTORY_PAGE_ITEM_3
#define _PFONT_FACTORY_BACKGROUND_COLOR_B           _PFONT_FACTORY_PAGE_ITEM_4
#define _PFONT_FACTORY_LVDS_CLOCK                   _PFONT_FACTORY_PAGE_ITEM_5

#define _PFONT_FACTORY_SSC                          _PFONT_FACTORY_PAGE_ITEM_33

#define _PFONT_FACTORY_LVDS_DATA                    _PFONT_FACTORY_PAGE_ITEM_7
#define _PFONT_FACTORY_PATTERN                      _PFONT_FACTORY_PAGE_ITEM_8
#define _PFONT_FACTORY_HOT_PLUG_DP_DC_OFF_HIGH      _PFONT_FACTORY_PAGE_ITEM_9
#define _PFONT_FACTORY_HOT_PLUG_HDMI_SUPPORT        _PFONT_FACTORY_PAGE_ITEM_10
#define _PFONT_FACTORY_HOT_PLUG_HDMI_TIME           _PFONT_FACTORY_PAGE_ITEM_11
#define _PFONT_FACTORY_DP_AUX_MODE_SEL              _PFONT_FACTORY_PAGE_ITEM_12
#define _PFONT_FACTORY_COLORIMETRY_SEAMLESS         _PFONT_FACTORY_PAGE_ITEM_13
#define _PFONT_FACTORY_OSD_DOUBLE_ON_OFF            _PFONT_FACTORY_PAGE_ITEM_14
#define _PFONT_FACTORY_DP_AUX_ADJR                  _PFONT_FACTORY_PAGE_ITEM_15
#define _PFONT_FACTORY_DP_IRQ_ADJ                   _PFONT_FACTORY_PAGE_ITEM_16

#define _FACTORY_PAGE_0_START                       0x01
#define _FACTORY_PAGE_0_END                         0xA0

#define _FACTORY_PAGE_1_START                       (_FACTORY_PAGE_0_END+1)
#define _FACTORY_PAGE_1_END                         0xFB
#define _FACTORY_PAGE_2_START                       0x00 // 256-511 font

#define _FACTORY_ITEM_1_START                       (_FACTORY_PAGE_2_START) // 256~511 font
#define _FACTORY_ITEM_1_END                         (_FACTORY_ITEM_1_START + 5)
#define _FACTORY_ITEM_2_START                       (_FACTORY_ITEM_1_END)
#define _FACTORY_ITEM_2_END                         (_FACTORY_ITEM_2_START + 5)
#define _FACTORY_ITEM_3_START                       (_FACTORY_ITEM_2_END)
#define _FACTORY_ITEM_3_END                         (_FACTORY_ITEM_3_START + 5)
#define _FACTORY_ITEM_4_START                       (_FACTORY_ITEM_3_END)
#define _FACTORY_ITEM_4_END                         (_FACTORY_ITEM_4_START + 5)
#define _FACTORY_ITEM_5_START                       (_FACTORY_ITEM_4_END)
#define _FACTORY_ITEM_5_END                         (_FACTORY_ITEM_5_START + 4)
#define _FACTORY_ITEM_6_START                       (_FACTORY_ITEM_5_END)
#define _FACTORY_ITEM_6_END                         (_FACTORY_ITEM_6_START + 5)
#define _FACTORY_ITEM_7_START                       (_FACTORY_ITEM_6_END)
#define _FACTORY_ITEM_7_END                         (_FACTORY_ITEM_7_START + 5)
#define _FACTORY_ITEM_8_START                       (_FACTORY_ITEM_7_END)
#define _FACTORY_ITEM_8_END                         (_FACTORY_ITEM_8_START + 5)
#define _FACTORY_ITEM_9_START                       (_FACTORY_ITEM_8_END)
#define _FACTORY_ITEM_9_END                         (_FACTORY_ITEM_9_START + 5)
#define _FACTORY_ITEM_10_START                      (_FACTORY_ITEM_9_END)
#define _FACTORY_ITEM_10_END                        (_FACTORY_ITEM_10_START + 5)

#define _FACTORY_ITEM_11_START                      (_FACTORY_ITEM_10_END)
#define _FACTORY_ITEM_11_END                        (_FACTORY_ITEM_11_START + 5)
#define _FACTORY_ITEM_12_START                      (_FACTORY_ITEM_11_END)
#define _FACTORY_ITEM_12_END                        (_FACTORY_ITEM_12_START + 5)
#define _FACTORY_ITEM_13_START                      (_FACTORY_ITEM_12_END)
#define _FACTORY_ITEM_13_END                        (_FACTORY_ITEM_13_START + 5)
#define _FACTORY_ITEM_14_START                      (_FACTORY_ITEM_13_END)
#define _FACTORY_ITEM_14_END                        (_FACTORY_ITEM_14_START + 5)
#define _FACTORY_ITEM_15_START                      (_FACTORY_ITEM_14_END)
#define _FACTORY_ITEM_15_END                        (_FACTORY_ITEM_15_START + 5)
#define _FACTORY_ITEM_16_START                      (_FACTORY_ITEM_15_END)
#define _FACTORY_ITEM_16_END                        (_FACTORY_ITEM_16_START + 5)
#define _FACTORY_ITEM_17_START                      (_FACTORY_ITEM_16_END)
#define _FACTORY_ITEM_17_END                        (_FACTORY_ITEM_17_START + 5)
#define _FACTORY_ITEM_18_START                      (_FACTORY_ITEM_17_END)
#define _FACTORY_ITEM_18_END                        (_FACTORY_ITEM_18_START + 5)
#define _FACTORY_ITEM_19_START                      (_FACTORY_ITEM_18_END)
#define _FACTORY_ITEM_19_END                        (_FACTORY_ITEM_19_START + 5)
#define _FACTORY_ITEM_20_START                      (_FACTORY_ITEM_19_END)
#define _FACTORY_ITEM_20_END                        (_FACTORY_ITEM_20_START + 5)

#define _FACTORY_ITEM_21_START                      (_FACTORY_ITEM_20_END)
#define _FACTORY_ITEM_21_END                        (_FACTORY_ITEM_21_START + 5)
#define _FACTORY_ITEM_22_START                      (_FACTORY_ITEM_21_END)
#define _FACTORY_ITEM_22_END                        (_FACTORY_ITEM_22_START + 5)
#define _FACTORY_ITEM_23_START                      (_FACTORY_ITEM_22_END)
#define _FACTORY_ITEM_23_END                        (_FACTORY_ITEM_23_START + 5)
#define _FACTORY_ITEM_24_START                      (_FACTORY_ITEM_23_END)
#define _FACTORY_ITEM_24_END                        (_FACTORY_ITEM_24_START + 5)
#define _FACTORY_ITEM_25_START                      (_FACTORY_ITEM_24_END)
#define _FACTORY_ITEM_25_END                        (_FACTORY_ITEM_25_START + 5)
#define _FACTORY_ITEM_26_START                      (_FACTORY_ITEM_25_END)
#define _FACTORY_ITEM_26_END                        (_FACTORY_ITEM_26_START + 5)
#define _FACTORY_ITEM_27_START                      (_FACTORY_ITEM_26_END)
#define _FACTORY_ITEM_27_END                        (_FACTORY_ITEM_27_START + 5)
#define _FACTORY_ITEM_28_START                      (_FACTORY_ITEM_27_END)
#define _FACTORY_ITEM_28_END                        (_FACTORY_ITEM_28_START + 5)
#define _FACTORY_ITEM_29_START                      (_FACTORY_ITEM_28_END)
#define _FACTORY_ITEM_29_END                        (_FACTORY_ITEM_29_START + 5)
#define _FACTORY_ITEM_30_START                      (_FACTORY_ITEM_29_END)
#define _FACTORY_ITEM_30_END                        (_FACTORY_ITEM_30_START + 5)
#define _FACTORY_ITEM_31_START                      (_FACTORY_ITEM_30_END)
#define _FACTORY_ITEM_31_END                        (_FACTORY_ITEM_31_START + 5)
#define _FACTORY_ITEM_32_START                      (_FACTORY_ITEM_31_END)
#define _FACTORY_ITEM_32_END                        (_FACTORY_ITEM_32_START + 5)
#define _FACTORY_ITEM_33_START                      (_FACTORY_ITEM_32_END)
#define _FACTORY_ITEM_33_END                        (_FACTORY_ITEM_33_START + 5)
#define _FACTORY_ITEM_34_START                      (_FACTORY_ITEM_33_END)
#define _FACTORY_ITEM_34_END                        (_FACTORY_ITEM_34_START + 5)
#define _FACTORY_ITEM_35_START                      (_FACTORY_ITEM_34_END)
#define _FACTORY_ITEM_35_END                        (_FACTORY_ITEM_35_START + 5)

#define _FACTORY_MODEL_NAME_ROW                     1
#define _FACTORY_SCALER_ROW                         2

#if((_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)||(_PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207))
#define _FACTORY_PANEL_NAME_ROW                     2
#define _FACTORY_PANEL_NAME_COL                     14
#define _FACTORY_FW_VERSION_ROW                     1
#define _FACTORY_FW_VERSION_COL                     14
#define _FACTORY_EXIT_ROW                           4
#define _FACTORY_AUTOCOLOR_ROW                      5//3
#define _FACTORY_BURNIN_ROW                        6
#define _FACTORY_RESET_ROW                         7

#define _FACTORY_CON_ROW                           (_FACTORY_COLORTEMP2_ROW-_FACTORY_COLORTEMP__ROW_OFFSET-1)



#define _FACTORY_ADC_GAIN_ROW                      9
#define _FACTORY_ADC_OFFSET_ROW                    10

#define _FACTORY_COLORTEMP1_ROW                    11
#define _FACTORY_COLORTEMP2_ROW                    12
#define _FACTORY_COLORTEMP3_ROW                    13
#define _FACTORY_COLORTEMP4_ROW                    14
#define _FACTORY_COLORTEMP5_ROW                    15
#define _FACTORY_COLORTEMP6_ROW                    16


#define _FACTORY_SSC_COL                            1//13
#define _FACTORY_SSC_NUMBER_COL                     12//13
#define _FACTORY_SSC_ROW                            21
#define _FACTORY_AUDIO_ROW                          20
#define _FACTORY_BRI_ROW                            19
#define _FACTORY_COLORTEMP__ROW_OFFSET              0

#else
#define _FACTORY_PANEL_NAME_ROW                     3
#define _FACTORY_FW_VERSION_ROW                     5
#define _FACTORY_EXIT_ROW                           24
#define _FACTORY_AUTOCOLOR_ROW                      6//3
#define _FACTORY_BURNIN_ROW                         21
#if(_DEF_CT_SRGB_SUPPIRT)
#define _FACTORY_CON_ROW                           (_FACTORY_COLORTEMP1_ROW-_FACTORY_COLORTEMP__ROW_OFFSET-1) //11
#define _FACTORY_BRI_ROW                           (_FACTORY_CON_ROW-1)

#else
#define _FACTORY_CON_ROW                           (_FACTORY_COLORTEMP2_ROW-_FACTORY_COLORTEMP__ROW_OFFSET-1) //11
#define _FACTORY_BRI_ROW                           (_FACTORY_CON_ROW-1)

#endif
#define _FACTORY_ADC_GAIN_ROW                       10
#define _FACTORY_ADC_OFFSET_ROW                     11 
#define _FACTORY_COLORTEMP_ROW                      12
#define _FACTORY_COLORTEMP1_ROW                     13
#define _FACTORY_COLORTEMP2_ROW                     14
#define _FACTORY_COLORTEMP3_ROW                     15
#define _FACTORY_COLORTEMP4_ROW                     16
#if(_DEF_CT_5800_SUPPORT == _ON)
#define _FACTORY_COLORTEMP5_ROW                     17
#define _FACTORY_COLORTEMP6_ROW                     18
#else
#define _FACTORY_COLORTEMP5_ROW                     17
#define _FACTORY_COLORTEMP6_ROW                     17
#endif
#define _FACTORY_RESET_ROW                         (_FACTORY_BRI_ROW-1)    
#define _FACTORY_SSC_COL                            15//13
#define _FACTORY_SSC_NUMBER_COL                     20//13
#define _FACTORY_SSC_ROW                            19

#define _FACTORY_COLORTEMP__ROW_OFFSET              2

#define _FACTORY_AUDIO_ROW                          20


#endif



#define _FACTORY_RESET_BURNIN_TIME_ROW              6

#define _FACTORY_AUTOCOLOR_TYPE_ROW                 6
#define _FACTORY_BURNIN_TIME_ROW                    22

#define _FACTORY_RESET_PANEL_TIME_ROW               8







#define _FACTORY_EEP_ROW                            8


#define _FACTORY_DFM_ROW                            20
#define _FACTORY_TD_RESET_ROW                       21
#define _FACTORY_LOGO_ROW                           21




                
 


#define _FACTORY_OSD_PAGE_ROW                       19
#define _FACTORY_PANEL_TIME_ROW                     22
#define _FACTORY_BACKLIST_ROW                       22

#define _FACTORY_BG_ROW                             1
#define _FACTORY_BG_COLOR_ROW                       2
//#define _FACTORY_DRIVING_CONTROL_ROW              4
#define _FACTORY_LVDS_CLOCK_ROW                     4
#define _FACTORY_LVDS_DATA_ROW                      5
//#define _FACTORY_IPG_ROW                          7
//#define _FACTORY_PATTERN_ROW                      8

//#define _FACTORY_HOT_PLUG_OPTION_ROW              9
#define _FACTORY_HOT_PLUG_DP_DC_OFF_HIGH_ROW        6
#define _FACTORY_HOT_PLUG_HDMI_SUPPORT_ROW          7
#define _FACTORY_HOT_PLUG_HDMI_SUPPORT_TIME_ROW     8
#define _FACTORY_DP_AUX_MODE_ROW                    9
#define _FACTORY_OSD_DOUBLE_ROW                     10
#define _FACTORY_COLORIMETRY_SEAMLESS_ROW           11
#define _FACTORY_DP_AUX_ADJR_ROW                    12
#define _FACTORY_DP_IRQ_ROW                         13

#define _FACTORY_OSD_PAGE_1_ROW                     19
#define _FACTORY_EXIT_1_ROW                         20

#define _FACTORY_FUNCTION_COL                       1
#define _FACTORY_ON_OFF_COL                         13
#define _FACTORY_R_COL                              9
#define _FACTORY_G_COL                              15
#define _FACTORY_B_COL                              21
#define _FACTORY_R_NUMBER_COL                       13
#define _FACTORY_G_NUMBER_COL                       19
#define _FACTORY_B_NUMBER_COL                       25

#define _FACTORY_TIME_HOUR_COL                      17
#define _FACTORY_TIME_MIN_COL                       23
#define _FACTORY_BURNIN_TIME_HOUR_NUMBER_COL        13
#define _FACTORY_BURNIN_TIME_MIN_NUMBER_COL         20
#define _FACTORY_PANEL_TIME_HOUR_NUMBER_COL         13
#define _FACTORY_PANEL_TIME_MIN_NUMBER_COL          20
#define _FACTORY_OSD_PAGE_NUMBER_COL                20//13

#define _FACTORY_DFM_COL                            1//13

#define _FACTORY_TD_RESET_COL                       1//13
#define _FACTORY_LOGO_COL                           15//13

#define _FACTORY_DFM_NUMBER_COL                     12

#define _FACTORY_TD_RESET_NUMBER_COL                12//13
#define _FACTORY_LOGO_NUMBER_COL                    20//13

#define _FACTORY_LVDS_NUMBER_COL                    20//13
#define _FACTORY_PATTERN_NUMBER_COL                 20//13

#define _FACTORY_HOT_PLUG_OPTION_VALUE_COL          20//13
#define _FACTORY_VALUE_NUMBER_COL                   20//13

#define _MAIN_MENU_STATE_END                        _MENU_END


//#define _FACTORY_COLORTEMP_ITEM1            _CT_9300
//#define _FACTORY_COLORTEMP_ITEM2            _CT_7500
//#define _FACTORY_COLORTEMP_ITEM3            _CT_6500
//#define _FACTORY_COLORTEMP_ITEM4            _CT_5000
//#define _FACTORY_COLORTEMP_ITEM5            _CT_SRGB
#if(_BLUE_LIGHT_FILTER_SUPPORT)
#define _FACTORY_COLORTEMP_ITEM6            _CT_4500 //_CT_USER
#else
#define _FACTORY_COLORTEMP_ITEM6            _CT_USER //_CT_USER
#endif

#if(_DEF_DDCCI_EDID_TOOL)
typedef struct
{
	BYTE b1OsdFactory : 1;			
    BYTE b1BurnIn : 1;				//burnIn mode on/off
	BYTE b1OsdHotKeyBurnIn : 1;
	BYTE b1LogoOff :1;				//Force Logo on/off
	BYTE b1InternalAutoColor :1;	//Internal Auto Color mode Pass/Fail //DFM rev05 patch note 2
	BYTE b1EnegyLogo :1;			//China enegy Logo on/off
	BYTE b1AutoSource :1;           //Auto Source on/off

	BYTE b1Resetoff :1;           //b1Resetoff
	
    BYTE ucsRGBBacklight;			//sRGB backligh value
	BYTE ucVcomValue;				//Panel Vcom value
	WORD usDFMProductMode;			//DFM product Code  _PRODUCT_ON:0x55AA; _PRODUCT_OFF:0xAA55
	BYTE ucLanguage;				//recall language in Factory Mode
	BYTE ucDummy1;					//reserve
	BYTE ucDummy2;					//reserve
	//total 8bytes =4bit+(3bit)+5bytes+2 dummy bytes = 8 bytes

}StructFactoryType;
#endif



//--------------------------------------------------
// MACRO for Logo Off Mode //set on mean turn off logo
//--------------------------------------------------
#define GET_FACTORY_FORCE_LOGO_OFF()			(g_stFactoryData.b1LogoOff)
#define SET_FACTORY_FORCE_LOGO_OFF(x)      		(g_stFactoryData.b1LogoOff = (x))


//--------------------------------------------------
// MACRO for DFM status
//--------------------------------------------------
#define GET_FACTORY_DFM_MODE()					(g_stFactoryData.usDFMProductMode)
#define SET_FACTORY_DFM_MODE(x)            		(g_stFactoryData.usDFMProductMode = (x))



#define GET_FACTORY_RESET_OFF()					(g_stFactoryData.b1Resetoff)
#define SET_FACTORY_RESET_OFF(x)      			(g_stFactoryData.b1Resetoff = (x))


//--------------------------------------------------
// Definitions of EDID index
//--------------------------------------------------
#define _EDID_MAN_NAME_INDEX0						0x08	
#define _EDID_MAN_NAME_INDEX1						0x09			
#define GetManufactNameC1(x)						((x==0)?(_X__):((((x)&0x7C00)>>10)+_A__-1))//BYTE8 bit6~bit2
#define GetManufactNameC2(x)						((x==0)?(_X__):((((x)&0x03E0)>>5)+_A__-1))//BYTE8 bit1~bit0 BYTE9 bit7~bit5
#define GetManufactNameC3(x)						((x==0)?(_X__):(((x)&0x001F)+_A__-1))//BYTE9 bit4~bit0


#define _EDID_WEEK_INDEX							0x10	
#define GetEDIDWeek0(x)								(((x)/10)+_0__)
#define GetEDIDWeek1(x)								(((x)%10)+_0__)


#define _EDID_YEAR_INDEX							0x11	
#define GetEDIDYear0(x)								(((1990+(x))/1000)+_0__)
#define GetEDIDYear1(x)								((((1990+(x))/100)%10)+_0__)
#define GetEDIDYear2(x)								((((1990+(x))/10)%10)+_0__)
#define GetEDIDYear3(x)								(((1990+(x))%10)+_0__)


#define _EDID_MAN_SN_INDEX0             	    0x4D	
#define _EDID_MAN_SN_INDEX1             	    0x4E	
#define _EDID_MAN_SN_INDEX2                     0x4F  
#define _EDID_MAN_SN_INDEX3                     0x50  
#define _EDID_MAN_SN_INDEX4                     0x51  
#define _EDID_MAN_SN_INDEX5                     0x52  
#define _EDID_MAN_SN_INDEX6                     0x53  
#define _EDID_MAN_SN_INDEX7                     0x54  
#define _EDID_MAN_SN_INDEX8                     0x55  
#define _EDID_MAN_SN_INDEX9                     0x56 
#define _EDID_MAN_SN_INDEX10                    0X57  
#define _EDID_MAN_SN_INDEX11                    0x58  
#define _EDID_MAN_SN_INDEX12                    0x59
#define GetEDIDSN0(x)							(x == 0x0A)?(_END_):((x < 0x40)?((x - 0x30)+_0__):(x - 0x41+_A__))
//#define GetEDIDSN0(x)								(x < 0x40)?((x - 0x30)+1):(x - 0x36)


#define EDID_ROW_NUM							6
//--------------------------------------------------
// BurnIn Menu 
//--------------------------------------------------

enum EDIDPortIndex
{
#if(((_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)))
		_PORT_A0,
#elif(_HDMI_24C02_SUPPORT)&&(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT && _A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE &&  _A0_EMBEDDED_DDCRAM_LOCATION==_EDID_TABLE_LOCATION_USER)
		_PORT_A0,
#endif

#if(((_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)))
		_PORT_D0,
#elif(_HDMI_24C02_SUPPORT) && (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT && _D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE &&  _D0_EMBEDDED_DDCRAM_LOCATION==_EDID_TABLE_LOCATION_USER)
		_PORT_D0,
#endif
#if(((_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
		_PORT_D1,
#elif(_HDMI_24C02_SUPPORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT && _D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE &&  _D1_EMBEDDED_DDCRAM_LOCATION==_EDID_TABLE_LOCATION_USER)
		_PORT_D1,
#endif
#if(((_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
		_PORT_D2,
#elif(_HDMI_24C02_SUPPORT) && (_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT && _D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE &&  _D2_EMBEDDED_DDCRAM_LOCATION==_EDID_TABLE_LOCATION_USER)
		_PORT_D2,
#endif
#if(((_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
		_PORT_D3,
#elif(_HDMI_24C02_SUPPORT) && (_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT && _D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE &&  _D3_EMBEDDED_DDCRAM_LOCATION==_EDID_TABLE_LOCATION_USER)
		_PORT_D3,
#endif
		_EDID_PORT_NUM,

};
//--------------------------------------------------
// Definitions of BurnIn Menu Position
//--------------------------------------------------
#define BURNIN_POS_X1			20
#define BURNIN_POS_Y1			20

#define _BURNIN_MSG_COL                       	1
#define _BURNIN_FW_DATE_COL                     11//8
#define _BURNIN_EDID0_PORT_STA_COL              8
#define _BURNIN_EDID0_PORT_COL                  1

#define _BURNIN_EDID_YEAR_COL                   5
#define _BURNIN_EDID_WEEK_COL                   14


#define _BURNIN_MODEL_NAME_ROW                  0
#define _BURNIN_IC_NAME_ROW                     1
#define _BURNIN_FW_VERSION_ROW                  2
#define _BURNIN_FW_DATE_ROW                     2
#if((_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)||(_PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207))
#define _BURNIN_FW_CSK_ROW                  	3

#else
#define _BURNIN_FW_CSK_ROW                  	6
#endif
#define _BURNIN_PANEL_NAME_ROW                  4

//EDID0
#define _BURNIN_EDID0_PORT_ROW                  _BURNIN_PANEL_NAME_ROW+2
#define _BURNIN_EDID0_MODE_ROW                  _BURNIN_EDID0_PORT_ROW+1
#define _BURNIN_EDID0_SN_ROW               		_BURNIN_EDID0_MODE_ROW+1
#define _BURNIN_EDID0_ID_NAME_ROW               _BURNIN_EDID0_SN_ROW+1

#define _BURNIN_EDID0_CSK_ROW               	_BURNIN_EDID0_ID_NAME_ROW+1

//--------------------------------------------------
// Definitions of BurnIn Menu Size
//--------------------------------------------------
//#if(_DEF_BURNING_PORTINFO_SUPPORT == _ON)
//#define _BURNIN_OSD_ROW                            ((_BURNIN_PANEL_NAME_ROW)+((_EDID_PORT_NUM)*(EDID_ROW_NUM))+2)
//#else
#define _BURNIN_OSD_ROW                            6
//#endif

#define _BURNIN_OSD_COL                            28//32

#define _BURNIN_OSD_WINDOW_SIZE_X                  ((_BURNIN_OSD_COL) * 12 +11)
#define _BURNIN_OSD_WINDOW_SIZE_Y                  ((_BURNIN_OSD_ROW) * 18)

#if(((_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
#define _DDCRAM_VGA				MCU_DDCRAM_A0
#define _ManValue_VGA			((WORD)((_DDCRAM_VGA[_EDID_MAN_NAME_INDEX0]<<8)|_DDCRAM_VGA[_EDID_MAN_NAME_INDEX1]))
#endif
#if(((_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
#define _DDCRAM_D0			MCU_DDCRAM_D0
#define _ManValue_D0		((WORD)((_DDCRAM_D0[_EDID_MAN_NAME_INDEX0]<<8)|_DDCRAM_D0[_EDID_MAN_NAME_INDEX1]))
#endif
#if(((_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
#define _DDCRAM_D1		MCU_DDCRAM_D1
#define _ManValue_D1		((WORD)((_DDCRAM_D1[_EDID_MAN_NAME_INDEX0]<<8)|_DDCRAM_D1[_EDID_MAN_NAME_INDEX1]))

#endif
#if(((_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) ))
#define _DDCRAM_D2		MCU_DDCRAM_D2
#define _ManValue_D2	((WORD)((_DDCRAM_D2[_EDID_MAN_NAME_INDEX0]<<8)|_DDCRAM_D2[_EDID_MAN_NAME_INDEX1]))
#endif

#if(((_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)))
#define _DDCRAM_D3		MCU_DDCRAM_D3
#define _ManValue_D3		((WORD)((_DDCRAM_D3[_EDID_MAN_NAME_INDEX0]<<8)|_DDCRAM_D3[_EDID_MAN_NAME_INDEX1]))
#endif

enum OsdBurnInStrIndex
{
   	_BURNIN_IC_NAME,
   	_BURNIN_VERSION,
	_BURNIN_DATE,
	_BURNIN_PANNEL_NAME,
	_FACTORY_CHKSUM,
};
//--------------------------------------------------
// Definitions of Factory OSD Flow
//--------------------------------------------------
typedef enum
{
//-------------------------------------------------------------------------------------------------------------------------------------------------
//  Factory State
//-------------------------------------------------------------------------------------------------------------------------------------------------

    _MENU_FACTORY_AUTOCOLOR = _MAIN_MENU_STATE_END,
    _MENU_FACTORY_AUTOCOLOR_TYPE,
    _MENU_FACTORY_BURNIN,
    _MENU_FACTORY_RESET_BURNIN_TIME,
    _MENU_FACTORY_RESET_PANEL_TIME,

    _MENU_FACTORY_CT1_RED,          _MENU_FACTORY_CT1_GREEN,        _MENU_FACTORY_CT1_BLUE,
    _MENU_FACTORY_CT2_RED,          _MENU_FACTORY_CT2_GREEN,        _MENU_FACTORY_CT2_BLUE,
    _MENU_FACTORY_CT3_RED,          _MENU_FACTORY_CT3_GREEN,        _MENU_FACTORY_CT3_BLUE,
    _MENU_FACTORY_CT4_RED,          _MENU_FACTORY_CT4_GREEN,        _MENU_FACTORY_CT4_BLUE,
    _MENU_FACTORY_CT5_RED,          _MENU_FACTORY_CT5_GREEN,        _MENU_FACTORY_CT5_BLUE,
    _MENU_FACTORY_CT6_RED,          _MENU_FACTORY_CT6_GREEN,        _MENU_FACTORY_CT6_BLUE,

    _MENU_FACTORY_BACKLIGHT,        _MENU_FACTORY_CONTRAST,         _MENU_FACTORT_AUDIO, 
    _MENU_FACTORY_GAIN_RED,         _MENU_FACTORY_GAIN_GREEN,       _MENU_FACTORY_GAIN_BLUE,
    _MENU_FACTORY_OFFSET_RED,       _MENU_FACTORY_OFFSET_GREEN,     _MENU_FACTORY_OFFSET_BLUE,
    _MENU_FACTORY_OSD_PAGE,         _MENU_FACTORY_DFM,              _MENU_FACTORY_SSC,
    _MENU_FACTORY_TD_RESET,         _MENU_FACTORY_LOGO, 
    _MENU_FACTORY_EXIT,

    _MENU_FACTORY_AUTO_COLOR_TYPE,
    _MENU_FACTORY_BURNIN_ON_OFF,
    _MENU_FACTORY_CT1_RED_ADJ,          _MENU_FACTORY_CT1_GREEN_ADJ,        _MENU_FACTORY_CT1_BLUE_ADJ,
    _MENU_FACTORY_CT2_RED_ADJ,          _MENU_FACTORY_CT2_GREEN_ADJ,        _MENU_FACTORY_CT2_BLUE_ADJ,
    _MENU_FACTORY_CT3_RED_ADJ,          _MENU_FACTORY_CT3_GREEN_ADJ,        _MENU_FACTORY_CT3_BLUE_ADJ,
    _MENU_FACTORY_CT4_RED_ADJ,          _MENU_FACTORY_CT4_GREEN_ADJ,        _MENU_FACTORY_CT4_BLUE_ADJ,
    _MENU_FACTORY_CT5_RED_ADJ,          _MENU_FACTORY_CT5_GREEN_ADJ,        _MENU_FACTORY_CT5_BLUE_ADJ,
    _MENU_FACTORY_CT6_RED_ADJ,          _MENU_FACTORY_CT6_GREEN_ADJ,        _MENU_FACTORY_CT6_BLUE_ADJ,

    _MENU_FACTORY_BACKLIGHT_ADJ,         _MENU_FACTORY_CONTRAST_ADJ,        _MENU_FACTORY_AUDIO_ADJ,
    _MENU_FACTORY_GAIN_RED_ADJ,         _MENU_FACTORY_GAIN_GREEN_ADJ,       _MENU_FACTORY_GAIN_BLUE_ADJ,
    _MENU_FACTORY_OFFSET_RED_ADJ,       _MENU_FACTORY_OFFSET_GREEN_ADJ,     _MENU_FACTORY_OFFSET_BLUE_ADJ,
    _MENU_FACTORY_OSD_PAGE_ADJ,         _MENU_FACTORY_DFM_ADJ,              _MENU_FACTORY_SSC_ADJ,
    _MENU_FACTORY_TD_RESET_ADJ,
    _MENU_FACTORY_LOGO_ADJ,

    //Factory Menu Page1
    _MENU_FACTORY_BG,
    _MENU_FACTORY_BG_RED,
    _MENU_FACTORY_BG_GREEN,
    _MENU_FACTORY_BG_BLUE,
    
    _MENU_FACTORY_LVDS_CLOCK,
    _MENU_FACTORY_LVDS_DATA,
    _MENU_FACTORY_HOT_PLUG_DP_DC_OFF_HIGH,
    _MENU_FACTORY_HOT_PLUG_HDMI_SUPPORT,
    _MENU_FACTORY_HOT_PLUG_HDMI_SUPPORT_TIME,
    _MENU_FACTORY_DP_AUX_MODE,
    _MENU_FACTORY_OSD_DOUBLE_SIZE,
    _MENU_FACTORY_COLORIMETRY_SEAMLESS,
    _MENU_FACTORY_DP_AUX_SETTING,
    _MENU_FACTORY_DP_IRQ_TIME,
    _MENU_FACTORY_OSD_PAGE_1,
    _MENU_FACTORY_EXIT1,

    _MENU_FACTORY_BG_ON_OFF,
    _MENU_FACTORY_BG_RED_ADJ,
    _MENU_FACTORY_BG_GREEN_ADJ,
    _MENU_FACTORY_BG_BLUE_ADJ,

    
    _MENU_FACTORY_LVDS_CLOCK_CURRENT_ADJ,
    _MENU_FACTORY_LVDS_DATA_CURRENT_ADJ,
    _MENU_FACTORY_HOT_PLUG_DP_DC_OFF_HIGH_ON_OFF,
    _MENU_FACTORY_HOT_PLUG_HDMI_SUPPORT_ON_OFF,
    _MENU_FACTORY_HOT_PLUG_HDMI_SUPPORT_TIME_ADJ,
    _MENU_FACTORY_DP_AUX_MODE_ON_OFF,
    _MENU_FACTORY_OSD_DOUBLE_SIZE_ON_OFF,
    _MENU_FACTORY_COLORIMETRY_SEAMLESS_ON_OFF,
    _MENU_FACTORY_DP_AUX_SETTING_ADJR,
    _MENU_FACTORY_DP_IRQ_TIME_ADJ,
    _MENU_FACTORY_OSD_PAGE_1_ADJ,
    _MENU_FACTORY_OSD_END,
}EnumOsdFactoryMenuPtr;


typedef enum
{
	_FACTORY_DATA_FW_CHECKSUM,
	_FACTORY_DATA_EDID_PANELSIZE,
	_FACTORY_DATA_EDID_RESOLUTION,
	_FACTORY_DATA_EDID_CHECKSUM,
	_FACTORY_DATA_EDID_RESULT,
	_FACTORY_DATA_EDID_WEEK,
	_FACTORY_DATA_EDID_YEAR,
	_FACTORY_DATA_EDID_SN,
	_FACTORY_DATA_EDID_MANUFACTNAME,
	_FACTORY_DATA_EDID_PRODUCTNAME,
}enumFactoryData;


extern void TPVNVRamSaveFactoryDate(void);
//****************************************************************************
// EXTEND VARIABLE DECLARATIONS of FactoryMode.c
//****************************************************************************
extern code BYTE *tOSD_FACTORY_PAGE_TABLE[];
extern code BYTE *tOSD_BURNIN_PAGE_TABLE[];
extern code BYTE *tOSD_FACTORY_PAGE_1_TABLE[];
extern code BYTE *tOSD_FACTORY_RGB_TABLE[];
extern BYTE code tFONT_FACTORY_EUROPE[];
extern BYTE code tOSD_FACTORY_CHARWIDTH_EUROPE[][2];
extern BYTE code tOSD_FACTORY_WIN0[];
extern BYTE code tFONT_FACTORY_GLOBAL[];
extern code BYTE *tOSD_FACTORY_ON_OFF_TABLE[];
extern code BYTE *tOSD_FACTORY_PASS_FAIL_TABLE[];
extern code BYTE *tOSD_FACTORY_HOUR_MIN_TABLE[];
extern code BYTE *tOSD_FACTORY_AUTO_COLOR_TYPE_TABLE[];
//extern BYTE code _FACTORY_PAGE_ROW_COL_TABLE[][2];
//extern BYTE code tFACTORY_PAGE_SELECT_ITEM_TABLE[][2];

//****************************************************************************
// FUNCTION EXTERN of FactoryMode.c
//****************************************************************************
extern BYTE g_ucFactoryPage;
extern BYTE g_ucBgColorR;
extern BYTE g_ucBgColorG;
extern BYTE g_ucBgColorB;
extern BYTE g_ucAutoColotTypeFontPointer;

//----------------------------------------------------------------------------------------
// Extern functions from FactoryMode.c
//----------------------------------------------------------------------------------------
// __FACTORY_MODE__
extern void RTDFactoryMenuOperation(void);
extern code void (*OperationFactoryTable[][4])(void);
extern void RTDFactoryMainMenu(void);
extern void RTDFactoryMainMenu1(void);
//============= Auto Color =======================
extern void RTDFactoryAutoColorEnter(void);
extern void RTDFactoryAutoColorLeft(void);
extern void RTDFactoryAutoColorRight(void);
extern void RTDFactoryAutoColorExit(void);
//============= Burnin =======================
extern void RTDFactoryBurninEnter(void);
extern void RTDFactoryBurninLeft(void);
extern void RTDFactoryBurninRight(void);
extern void RTDFactoryBurninExit(void);
//============= Reset Burnin Time =======================
extern void RTDFactoryResetBurninTimeEnter(void);
extern void RTDFactoryResetBurninTimeLeft(void);
extern void RTDFactoryResetBurninTimeRight(void);
extern void RTDFactoryResetBurninTimeExit(void);
//============= Reset Panel Time =======================
extern void RTDFactoryResetPanelTimeEnter(void);
extern void RTDFactoryResetPanelTimeLeft(void);
extern void RTDFactoryResetPanelTimeRight(void);
extern void RTDFactoryResetPanelTimeExit(void);
//============= Colortemp 1 R=======================
extern void RTDFactoryColortemp1REnter(void);
extern void RTDFactoryColortemp1RLeft(void);
extern void RTDFactoryColortemp1RRight(void);
extern void RTDFactoryColortemp1RExit(void);
//============= Colortemp 1 G=======================
extern void RTDFactoryColortemp1GEnter(void);
extern void RTDFactoryColortemp1GLeft(void);
extern void RTDFactoryColortemp1GRight(void);
extern void RTDFactoryColortemp1GExit(void);
//============= Colortemp 1 B=======================
extern void RTDFactoryColortemp1BEnter(void);
extern void RTDFactoryColortemp1BLeft(void);
extern void RTDFactoryColortemp1BRight(void);
extern void RTDFactoryColortemp1BExit(void);
//============= Colortemp 2 R=======================
extern void RTDFactoryColortemp2REnter(void);
extern void RTDFactoryColortemp2RLeft(void);
extern void RTDFactoryColortemp2RRight(void);
extern void RTDFactoryColortemp2RExit(void);
//============= Colortemp 2 G=======================
extern void RTDFactoryColortemp2GEnter(void);
extern void RTDFactoryColortemp2GLeft(void);
extern void RTDFactoryColortemp2GRight(void);
extern void RTDFactoryColortemp2GExit(void);
//============= Colortemp 2 B=======================
extern void RTDFactoryColortemp2BEnter(void);
extern void RTDFactoryColortemp2BLeft(void);
extern void RTDFactoryColortemp2BRight(void);
extern void RTDFactoryColortemp2BExit(void);
//============= Colortemp 3 R=======================
extern void RTDFactoryColortemp3REnter(void);
extern void RTDFactoryColortemp3RLeft(void);
extern void RTDFactoryColortemp3RRight(void);
extern void RTDFactoryColortemp3RExit(void);
//============= Colortemp 3 G=======================
extern void RTDFactoryColortemp3GEnter(void);
extern void RTDFactoryColortemp3GLeft(void);
extern void RTDFactoryColortemp3GRight(void);
extern void RTDFactoryColortemp3GExit(void);
//============= Colortemp 3 B=======================
extern void RTDFactoryColortemp3BEnter(void);
extern void RTDFactoryColortemp3BLeft(void);
extern void RTDFactoryColortemp3BRight(void);
extern void RTDFactoryColortemp3BExit(void);
//============= Colortemp 4 R=======================
extern void RTDFactoryColortemp4REnter(void);
extern void RTDFactoryColortemp4RLeft(void);
extern void RTDFactoryColortemp4RRight(void);
extern void RTDFactoryColortemp4RExit(void);
//============= Colortemp 4 G=======================
extern void RTDFactoryColortemp4GEnter(void);
extern void RTDFactoryColortemp4GLeft(void);
extern void RTDFactoryColortemp4GRight(void);
extern void RTDFactoryColortemp4GExit(void);
//============= Colortemp 4 B=======================
extern void RTDFactoryColortemp4BEnter(void);
extern void RTDFactoryColortemp4BLeft(void);
extern void RTDFactoryColortemp4BRight(void);
extern void RTDFactoryColortemp4BExit(void);
//============= Colortemp 5 R=======================
extern void RTDFactoryColortemp5REnter(void);
extern void RTDFactoryColortemp5RLeft(void);
extern void RTDFactoryColortemp5RRight(void);
extern void RTDFactoryColortemp5RExit(void);
//============= Colortemp 5 G=======================
extern void RTDFactoryColortemp5GEnter(void);
extern void RTDFactoryColortemp5GLeft(void);
extern void RTDFactoryColortemp5GRight(void);
extern void RTDFactoryColortemp5GExit(void);
//============= Colortemp 5 B=======================
extern void RTDFactoryColortemp5BEnter(void);
extern void RTDFactoryColortemp5BLeft(void);
extern void RTDFactoryColortemp5BRight(void);
extern void RTDFactoryColortemp5BExit(void);
//============= Colortemp 6 R=======================
extern void RTDFactoryColortemp6REnter(void);
extern void RTDFactoryColortemp6RLeft(void);
extern void RTDFactoryColortemp6RRight(void);
extern void RTDFactoryColortemp6RExit(void);
//============= Colortemp 6 G=======================
extern void RTDFactoryColortemp6GEnter(void);
extern void RTDFactoryColortemp6GLeft(void);
extern void RTDFactoryColortemp6GRight(void);
extern void RTDFactoryColortemp6GExit(void);
//============= Colortemp 6 B=======================
extern void RTDFactoryColortemp6BEnter(void);
extern void RTDFactoryColortemp6BLeft(void);
extern void RTDFactoryColortemp6BRight(void);
extern void RTDFactoryColortemp6BExit(void);
//============= Adc Gain R=======================
extern void RTDFactoryAdcGainREnter(void);
extern void RTDFactoryAdcGainRLeft(void);
extern void RTDFactoryAdcGainRRight(void);
extern void RTDFactoryAdcGainRExit(void);
//============= Adc Gain G=======================
extern void RTDFactoryAdcGainGEnter(void);
extern void RTDFactoryAdcGainGLeft(void);
extern void RTDFactoryAdcGainGRight(void);
extern void RTDFactoryAdcGainGExit(void);
//============= Adc Gain B=======================
extern void RTDFactoryAdcGainBEnter(void);
extern void RTDFactoryAdcGainBLeft(void);
extern void RTDFactoryAdcGainBRight(void);
extern void RTDFactoryAdcGainBExit(void);
//============= Adc Offset R=======================
extern void RTDFactoryAdcOffsetREnter(void);
extern void RTDFactoryAdcOffsetRLeft(void);
extern void RTDFactoryAdcOffsetRRight(void);
extern void RTDFactoryAdcOffsetRExit(void);
//============= Adc Offset G=======================
extern void RTDFactoryAdcOffsetGEnter(void);
extern void RTDFactoryAdcOffsetGLeft(void);
extern void RTDFactoryAdcOffsetGRight(void);
extern void RTDFactoryAdcOffsetGExit(void);
//============= Adc Offset B=======================
extern void RTDFactoryAdcOffsetBEnter(void);
extern void RTDFactoryAdcOffsetBLeft(void);
extern void RTDFactoryAdcOffsetBRight(void);
extern void RTDFactoryAdcOffsetBExit(void);


extern void RTDFactoryBRIEnter(void);
extern void RTDFactoryBRILeft(void);
extern void RTDFactoryBRIRight(void);
extern void RTDFactoryBRIExit(void);


extern void RTDFactoryCONEnter(void);
extern void RTDFactoryCONLeft(void);
extern void RTDFactoryCONRight(void);
extern void RTDFactoryCONExit(void);


extern void RTDFactoryAUDIOEnter(void);
extern void RTDFactoryAUDIOLeft(void);
extern void RTDFactoryAUDIORight(void);
extern void RTDFactoryAUDIOExit(void);

//============= Osd Page=======================
extern void RTDFactoryOsdPageEnter(void);
extern void RTDFactoryOsdPageLeft(void);
extern void RTDFactoryOsdPageRight(void);
extern void RTDFactoryOsdPageExit(void);
//============= Exit=======================
extern void RTDFactoryExitEnter(void);
extern void RTDFactoryExitLeft(void);
extern void RTDFactoryExitRight(void);
extern void RTDFactoryExitExit(void);

//============= Burnin On Off=======================
extern void RTDFactoryBurninOnOffEnter(void);
extern void RTDFactoryBurninOnOffLeft(void);
extern void RTDFactoryBurninOnOffRight(void);
extern void RTDFactoryBurninOnOffExit(void);
//============= Colortemp 1 R Adjust=======================
extern void RTDFactoryColortemp1RAdjustEnter(void);
extern void RTDFactoryColortemp1RAdjustLeft(void);
extern void RTDFactoryColortemp1RAdjustRight(void);
extern void RTDFactoryColortemp1RAdjustExit(void);
//============= Colortemp 1 G Adjust=======================
extern void RTDFactoryColortemp1GAdjustEnter(void);
extern void RTDFactoryColortemp1GAdjustLeft(void);
extern void RTDFactoryColortemp1GAdjustRight(void);
extern void RTDFactoryColortemp1GAdjustExit(void);
//============= Colortemp 1 B Adjust=======================
extern void RTDFactoryColortemp1BAdjustEnter(void);
extern void RTDFactoryColortemp1BAdjustLeft(void);
extern void RTDFactoryColortemp1BAdjustRight(void);
extern void RTDFactoryColortemp1BAdjustExit(void);
//============= Colortemp 2 R Adjust=======================
extern void RTDFactoryColortemp2RAdjustEnter(void);
extern void RTDFactoryColortemp2RAdjustLeft(void);
extern void RTDFactoryColortemp2RAdjustRight(void);
extern void RTDFactoryColortemp2RAdjustExit(void);
//============= Colortemp 2 G Adjust=======================
extern void RTDFactoryColortemp2GAdjustEnter(void);
extern void RTDFactoryColortemp2GAdjustLeft(void);
extern void RTDFactoryColortemp2GAdjustRight(void);
extern void RTDFactoryColortemp2GAdjustExit(void);
//============= Colortemp 2 B Adjust=======================
extern void RTDFactoryColortemp2BAdjustEnter(void);
extern void RTDFactoryColortemp2BAdjustLeft(void);
extern void RTDFactoryColortemp2BAdjustRight(void);
extern void RTDFactoryColortemp2BAdjustExit(void);
//============= Colortemp 3 R Adjust=======================
extern void RTDFactoryColortemp3RAdjustEnter(void);
extern void RTDFactoryColortemp3RAdjustLeft(void);
extern void RTDFactoryColortemp3RAdjustRight(void);
extern void RTDFactoryColortemp3RAdjustExit(void);
//============= Colortemp 3 G Adjust=======================
extern void RTDFactoryColortemp3GAdjustEnter(void);
extern void RTDFactoryColortemp3GAdjustLeft(void);
extern void RTDFactoryColortemp3GAdjustRight(void);
extern void RTDFactoryColortemp3GAdjustExit(void);
//============= Colortemp 3 B Adjust=======================
extern void RTDFactoryColortemp3BAdjustEnter(void);
extern void RTDFactoryColortemp3BAdjustLeft(void);
extern void RTDFactoryColortemp3BAdjustRight(void);
extern void RTDFactoryColortemp3BAdjustExit(void);
//============= Colortemp 4 R Adjust=======================
extern void RTDFactoryColortemp4RAdjustEnter(void);
extern void RTDFactoryColortemp4RAdjustLeft(void);
extern void RTDFactoryColortemp4RAdjustRight(void);
extern void RTDFactoryColortemp4RAdjustExit(void);
//============= Colortemp 4 G Adjust=======================
extern void RTDFactoryColortemp4GAdjustEnter(void);
extern void RTDFactoryColortemp4GAdjustLeft(void);
extern void RTDFactoryColortemp4GAdjustRight(void);
extern void RTDFactoryColortemp4GAdjustExit(void);
//============= Colortemp 4 B Adjust=======================
extern void RTDFactoryColortemp4BAdjustEnter(void);
extern void RTDFactoryColortemp4BAdjustLeft(void);
extern void RTDFactoryColortemp4BAdjustRight(void);
extern void RTDFactoryColortemp4BAdjustExit(void);
//============= Colortemp 5 R Adjust=======================
extern void RTDFactoryColortemp5RAdjustEnter(void);
extern void RTDFactoryColortemp5RAdjustLeft(void);
extern void RTDFactoryColortemp5RAdjustRight(void);
extern void RTDFactoryColortemp5RAdjustExit(void);
//============= Colortemp 5 G Adjust=======================
extern void RTDFactoryColortemp5GAdjustEnter(void);
extern void RTDFactoryColortemp5GAdjustLeft(void);
extern void RTDFactoryColortemp5GAdjustRight(void);
extern void RTDFactoryColortemp5GAdjustExit(void);
//============= Colortemp 5 B Adjust=======================
extern void RTDFactoryColortemp5BAdjustEnter(void);
extern void RTDFactoryColortemp5BAdjustLeft(void);
extern void RTDFactoryColortemp5BAdjustRight(void);
extern void RTDFactoryColortemp5BAdjustExit(void);
//============= Colortemp 6 R Adjust=======================
extern void RTDFactoryColortemp6RAdjustEnter(void);
extern void RTDFactoryColortemp6RAdjustLeft(void);
extern void RTDFactoryColortemp6RAdjustRight(void);
extern void RTDFactoryColortemp6RAdjustExit(void);
//============= Colortemp 6 G Adjust=======================
extern void RTDFactoryColortemp6GAdjustEnter(void);
extern void RTDFactoryColortemp6GAdjustLeft(void);
extern void RTDFactoryColortemp6GAdjustRight(void);
extern void RTDFactoryColortemp6GAdjustExit(void);
//============= Colortemp 6 B Adjust=======================
extern void RTDFactoryColortemp6BAdjustEnter(void);
extern void RTDFactoryColortemp6BAdjustLeft(void);
extern void RTDFactoryColortemp6BAdjustRight(void);
extern void RTDFactoryColortemp6BAdjustExit(void);



//============= BRI CON  Adjust=======================


extern void RTDFactoryBRIAdjustEnter(void);
extern void RTDFactoryBRIAdjustLeft(void);
extern void RTDFactoryBRIAdjustRight(void);
extern void RTDFactoryBRIAdjustExit(void);


extern void RTDFactoryCONAdjustEnter(void);
extern void RTDFactoryCONAdjustLeft(void);
extern void RTDFactoryCONAdjustRight(void);
extern void RTDFactoryCONAdjustExit(void);

extern void RTDFactoryAUDIOAdjustEnter(void);
extern void RTDFactoryAUDIOdjustLeft(void);
extern void RTDFactoryAUDIOAdjustRight(void);
extern void RTDFactoryAUDIOAdjustExit(void);

//============= Adc Gain R Adjust=======================
extern void RTDFactoryAdcGainRAdjustEnter(void);
extern void RTDFactoryAdcGainRAdjustLeft(void);
extern void RTDFactoryAdcGainRAdjustRight(void);
extern void RTDFactoryAdcGainRAdjustExit(void);
//============= Adc Gain G Adjust=======================
extern void RTDFactoryAdcGainGAdjustEnter(void);
extern void RTDFactoryAdcGainGAdjustLeft(void);
extern void RTDFactoryAdcGainGAdjustRight(void);
extern void RTDFactoryAdcGainGAdjustExit(void);
//============= Adc Gain B Adjust=======================
extern void RTDFactoryAdcGainBAdjustEnter(void);
extern void RTDFactoryAdcGainBAdjustLeft(void);
extern void RTDFactoryAdcGainBAdjustRight(void);
extern void RTDFactoryAdcGainBAdjustExit(void);
//============= Adc Offset R Adjust=======================
extern void RTDFactoryAdcOffsetRAdjustEnter(void);
extern void RTDFactoryAdcOffsetRAdjustLeft(void);
extern void RTDFactoryAdcOffsetRAdjustRight(void);
extern void RTDFactoryAdcOffsetRAdjustExit(void);
//============= Adc Offset G Adjust=======================
extern void RTDFactoryAdcOffsetGAdjustEnter(void);
extern void RTDFactoryAdcOffsetGAdjustLeft(void);
extern void RTDFactoryAdcOffsetGAdjustRight(void);
extern void RTDFactoryAdcOffsetGAdjustExit(void);
//============= Adc Offset B Adjust=======================
extern void RTDFactoryAdcOffsetBAdjustEnter(void);
extern void RTDFactoryAdcOffsetBAdjustLeft(void);
extern void RTDFactoryAdcOffsetBAdjustRight(void);
extern void RTDFactoryAdcOffsetBAdjustExit(void);
//============= Osd Page Adjust=======================
extern void RTDFactoryOsdPageAdjustEnter(void);
extern void RTDFactoryOsdPageAdjustLeft(void);
extern void RTDFactoryOsdPageAdjustRight(void);
extern void RTDFactoryOsdPageAdjustExit(void);
//============= Background on off=======================
extern void RTDFactoryBgOnOffEnter(void);
extern void RTDFactoryBgOnOffLeft(void);
extern void RTDFactoryBgOnOffRight(void);
extern void RTDFactoryBgOnOffExit(void);
//============= Background R=======================
extern void RTDFactoryBgREnter(void);
extern void RTDFactoryBgRLeft(void);
extern void RTDFactoryBgRRight(void);
extern void RTDFactoryBgRExit(void);
//============= Background G=======================
extern void RTDFactoryBgGEnter(void);
extern void RTDFactoryBgGLeft(void);
extern void RTDFactoryBgGRight(void);
extern void RTDFactoryBgGExit(void);
//============= Background B=======================
extern void RTDFactoryBgBEnter(void);
extern void RTDFactoryBgBLeft(void);
extern void RTDFactoryBgBRight(void);
extern void RTDFactoryBgBExit(void);
//============= SSC=======================
extern void RTDFactorySSCEnter(void);
extern void RTDFactorySSCLeft(void);
extern void RTDFactorySSCRight(void);
extern void RTDFactorySSCExit(void);
//============= LVDS=======================
extern void RTDFactoryLVDSClockEnter(void);
extern void RTDFactoryLVDSClockLeft(void);
extern void RTDFactoryLVDSClockRight(void);
extern void RTDFactoryLVDSClockExit(void);
//============= LVDS Data=======================
extern void RTDFactoryLVDSDataEnter(void);
extern void RTDFactoryLVDSDataLeft(void);
extern void RTDFactoryLVDSDataRight(void);
extern void RTDFactoryLVDSDataExit(void);
//============= Pattern =======================
extern void RTDFactoryPatternEnter(void);
extern void RTDFactoryPatternLeft(void);
extern void RTDFactoryPatternRight(void);
extern void RTDFactoryPatternExit(void);
//============= Osd Page 1=======================
extern void RTDFactoryOsdPage1Enter(void);
extern void RTDFactoryOsdPage1Left(void);
extern void RTDFactoryOsdPage1Right(void);
extern void RTDFactoryOsdPage1Exit(void);
//============= Exit 1=======================
extern void RTDFactoryExit1Enter(void);
extern void RTDFactoryExit1Left(void);
extern void RTDFactoryExit1Right(void);
extern void RTDFactoryExit1Exit(void);
//============= BG On Off=======================
extern void RTDFactoryBgOnOffEnter(void);
extern void RTDFactoryBgOnOffLeft(void);
extern void RTDFactoryBgOnOffRight(void);
extern void RTDFactoryBgOnOffExit(void);
//============= BG R Adjust=======================
extern void RTDFactoryBgRAdjustEnter(void);
extern void RTDFactoryBgRAdjustLeft(void);
extern void RTDFactoryBgRAdjustRight(void);
extern void RTDFactoryBgRAdjustExit(void);
//============= BG G Adjust=======================
extern void RTDFactoryBgGAdjustEnter(void);
extern void RTDFactoryBgGAdjustLeft(void);
extern void RTDFactoryBgGAdjustRight(void);
extern void RTDFactoryBgGAdjustExit(void);
//============= Adc Gain B Adjust=======================
extern void RTDFactoryBgBAdjustEnter(void);
extern void RTDFactoryBgBAdjustLeft(void);
extern void RTDFactoryBgBAdjustRight(void);
extern void RTDFactoryBgBAdjustExit(void);
//============= SSC Adjust=======================
extern void RTDFactorySSCAdjustEnter(void);
extern void RTDFactorySSCAdjustLeft(void);
extern void RTDFactorySSCAdjustRight(void);
extern void RTDFactorySSCAdjustExit(void);
//============= LVDS Clock Current Adjust=======================
extern void RTDFactoryLVDSClockCurrentAdjustEnter(void);
extern void RTDFactoryLVDSClockCurrentAdjustLeft(void);
extern void RTDFactoryLVDSClockCurrentAdjustRight(void);
extern void RTDFactoryLVDSClockCurrentAdjustExit(void);
//============= LVDS Data Current Adjust=======================
extern void RTDFactoryLVDSDataCurrentAdjustEnter(void);
extern void RTDFactoryLVDSDataCurrentAdjustLeft(void);
extern void RTDFactoryLVDSDataCurrentAdjustRight(void);
extern void RTDFactoryLVDSDataCurrentAdjustExit(void);
//============= Pattern Adjust=======================
//extern void RTDFactoryPatternAdjustEnter(void);
//extern void RTDFactoryPatternAdjustLeft(void);
//extern void RTDFactoryPatternAdjustRight(void);
//extern void RTDFactoryPatternAdjustExit(void);
//============= Osd Page 1 Adjust=======================
extern void RTDFactoryOsdPage1AdjustEnter(void);
extern void RTDFactoryOsdPage1AdjustLeft(void);
extern void RTDFactoryOsdPage1AdjustRight(void);
extern void RTDFactoryOsdPage1AdjustExit(void);

//----------------------------------------------------------------------------------------
// Extern functions from FactoryFunction.c
//----------------------------------------------------------------------------------------
// __FACTORY_FUNCTION__
extern void RTDFactoryOsdFuncDisableOsd(void);
extern void RTDFactoryOsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
//extern void RTDFactoryOsdLoadHardwareVLCFont(BYTE *pucArray, WORD usOffset, WORD usFontTableStart, bit bOsdRotate);
extern void RTDFactoryOsdFuncClearOsdFont(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucChar);
extern void RTDFactoryOsdFuncClearOsdFontAll(void);

extern void RTDFactoryOsdFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE *pucFontTable, BYTE *pucArray, BYTE ucLanguage);
extern void RTDFactoryOsdFuncDrawWindow(BYTE *pucArray, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void RTDFactoryOsdFuncEnableOsd(void);
extern void RTDFactoryOsdFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint);
extern void RTDFactoryOsdFuncSelectItem(WORD usOsdState);
extern void RTDFactoryOsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void RTDFactoryOsdDispNumber(WORD usOsdState, WORD usValue);
extern void RTDFactoryOsdFuncSetPosition(BYTE ucType, WORD usX, WORD usY);
extern void RTDFactoryOsdChangColorTemp(BYTE ucColorTemp);
extern void RTDFactoryPanelUsedTimer(void);
extern void TPVNVRamLoadFactoryDate(void);

#if(_FACTORY_ONE_PIECE_MARK_SUPPORT == _ON)
extern void RTDFactoryOnePieceMark(void);
#endif
extern void RTDFactoryOsdFuncShowChecksum(BYTE ucRow, BYTE ucCol, BYTE ucPar ,BYTE ucFontPoint);
extern void RTDFlashRestorePanelUsedTimeData(void);
extern void RTDBurnInMenu(void);
extern StructFactoryType g_stFactoryData;

//DFM mode
extern void TPVDFMSet( bit bOnOff);

extern bit TPVFCmdFactoryCommand(void);
extern void TPVDFMInitial(void);
extern bit TPVDFMModeFlag(void);
//extern bit TPVDFMCableWPCheck(void);//DFM rev02 patch note 7
//extern void TPVDFMFactoryReset(void);
//extern void TPVDFMPowerRecall(void);
//extern bit TPVDFMLogoOnCheck(void);
