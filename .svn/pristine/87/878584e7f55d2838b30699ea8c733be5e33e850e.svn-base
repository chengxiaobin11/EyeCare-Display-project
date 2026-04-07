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
// ID Code      : RL6463_Project.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PROJECT == _RL6463_PROJECT)

#include "Project_ID.h"



//--------------------------------------------------
// Pcb Option
//--------------------------------------------------
//#define _PCB_TYPE                                               _RL6463_DEMO_128PIN_1A1H1DP_PC99

//--------------------------------------------------
// Panel Option
//--------------------------------------------------
//#define _PANEL_TYPE                                             _AU_LVDS_21_5_WUXGA
#define _PANEL_POW_SEQ_FAST_MODE                                _OFF
#define _HDMI_24C02_SUPPORT                    					_ON
#define _WRITE_EDID_TO_SYSTEM_EEPROM                            _ON

//--------------------------------------------------
// Osd Option
//--------------------------------------------------
#define _OSD_TYPE                                               _REALTEK_2014_OSD

#define _OSD_INCLUDE                                            "RTD2014Include.h"
#define _USER_FUNCTION_INCLUDE                                  "RTD2014UserInclude.h"
#define _USER_TIMER_INCLUDE                                     "RTD2014TimerInclude.h"
#define _FACTORY_INCLUDE                                        "RTDFactoryInclude.h"
#define _USER_HWIIC_INCLUDE                                     "RTD2014HWIICInclude.h"

//--------------------------------------------------
// OSD Window & Font Align to DEN Option
//--------------------------------------------------
#define _OSD_POSITION_OFFSET_CORRECTION                         _ON

//--------------------------------------------------
// OSD Position Align Option
//--------------------------------------------------
#define _OSD_POSITION_SELF_ALIGNMENT                            _ON


///////////
// DDCCI //
///////////

//-------------------------------------------------
// DDCCI Option
//-------------------------------------------------
#define _DDCCI_RXBUF_LENGTH                                     41
#define _DDCCI_TXBUF_LENGTH                                     41
#define _DDCCI_TIMEOUT_LIMIT                                    100 // 0~65535ms

#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) || (_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _CAPABILITIES_STRING_VGA                                "(prot(monitor)type(LCD)model(VA2271-H)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 0E 10 12 14(01 08 06 05 04 0B) 16 18 1A 1E 1F 20 30 3E  52 60(01 11) 87 AC AE B2 B6 C6 C8 CA CC(02 03 04 0A 05 16 0B 09 0C 12 25 06 07 01 0d) D6(01 04 05) DF FD FF)mswhql(1)asset_eep (40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_DVI                                "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 04 05 06 08 0B) 16 18 1A 52 60(01 11) 62 87 AC AE B2 B6 8D C6 C8 CA CC(02 03 04 0a 05 16 09 0C 06 07 01 0d ) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_HDMI                               "(prot(monitor)type(lcd)model(VA2271-H)cmds(01 02 03 07 0c e3 f3)vcp(02 04 05 06 08 0b 0c 10 12 14(01 08 06 05 04 0b) 16 18 1a 52 60(01 11) 62 64 87 ac ae b2 b6 c6 c8 ca cc(02 03 04 0a 05 16 0b 09 0c 12 25 06 07 01 0d 25) d6(01 04 05) df fd ff)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_DP                                 "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 08 0B 0C 10 12 14(01 04 05 06 08 0B)  16 18 1A 21(01 02 03 04 05) 25(01 02 03) 27 2B 31 33 52 60(11 17) 61 62 64 6C 6E 70 72 87 8D AC AE B2 B6 C0 C6 C8 C9 CA CC(03 04 0a 0c 05 01 06 07 16 09 02 0b 0d 12) D6(01 04 05) DA(01 02) DB(01 02 03 04) DC(00 03 04 30 32 33 34 35 36 3E) DF E0 E1(00 19 32 4B 64) E2 E3(00 01 02) E6 E7(00 1E 2D 3C 78) F0(01 02))mswhql(1)asset_eep(40)mccs_ver(2.2))"

#else
#define _CAPABILITIES_STRING_VGA                                "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 0E 10 12 14(01 02 04 05 06 08 0B) 16 18 1A 1E 1F 20 30 3E 52 60(01 03 04 0F 10 11 12) 87 AC AE B2 B6 C6 C8 CA CC(01 02 03 04 06 0A 0D) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_DVI                                "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 02 04 05 06 08 0B) 16 18 1A 52 60(01 03 04 0F 10 11 12) 87 AC AE B2 B6 C6 C8 CA CC(01 02 03 04 06 0A 0D) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_HDMI                               "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 02 04 05 06 08 0B) 16 18 1A 52 60(01 03 04 0F 10 11 12) 87 AC AE B2 B6 C6 C8 CA CC(01 02 03 04 06 0A 0D) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#define _CAPABILITIES_STRING_DP                                 "(prot(monitor)type(LCD)model(RTK)cmds(01 02 03 07 0C E3 F3)vcp(02 04 05 06 08 0B 0C 10 12 14(01 02 04 05 06 08 0B) 16 18 1A 52 60(01 03 04 0F 10 11 12) 87 AC AE B2 B6 C6 C8 CA CC(01 02 03 04 06 0A 0D) D6(01 04 05) DF FD FF)mswhql(1)asset_eep(40)mccs_ver(2.2))"
#endif
//-------------------------------------------------
// DDCCI Auto Switch Option
//-------------------------------------------------
#define _DDCCI_AUTO_SWITCH_SUPPORT                              _ON


/////////////////////
// Display Setting //
/////////////////////

//-------------------------------------------------
// Embedded Memory Size Option
//-------------------------------------------------
#define _EMBEDDED_MEMORY_SIZE_CONFIG                            _1M_16BIT_SDRAM

//-------------------------------------------------
// OD Option
//-------------------------------------------------

#if(_PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)
#define _OD_SUPPORT                                             _ON
#define _OD_WEAK_MID_HIGH                                       _ON

#else
#define _OD_SUPPORT                                             _OFF
#define _OD_WEAK_MID_HIGH                                       _OFF

#endif



//-------------------------------------------------
// FRC Option
//-------------------------------------------------
#define _FRC_SUPPORT                                            _OFF

//--------------------------------------------------
// Aspect Ratio Option
//--------------------------------------------------
#define _ASPECT_RATIO_SUPPORT                                   _ON

//--------------------------------------------------
// Overscan Option
//--------------------------------------------------
#define _OVERSCAN_VGA_SUPPORT                                   _ON
#define _OVERSCAN_DVI_SUPPORT                                   _ON
#define _OVERSCAN_HDMI_SUPPORT                                  _ON
#define _OVERSCAN_DP_SUPPORT                                    _ON

#define _OVERSCAN_H_RATIO                                       30
#define _OVERSCAN_V_RATIO                                       30

//-------------------------------------------------
// Adjust H & V Position Max Range Option
//-------------------------------------------------
#define _MAX_H_POSITION_RANGE                                   100 // Pixel
#define _MAX_V_POSITION_RANGE                                   100 // Line


////////////////////
// Color Function //
////////////////////

//--------------------------------------------------
// Digital Functional Option
//--------------------------------------------------
#define _I_DITHER_SUPPORT                                       _ON
#define _D_DITHER_SUPPORT                                       _ON
#define _GAMMA_FUNCTION                                         _ON
#define _COLOR_FORMAT_CONVERT                                   _ON
#define _RGB_QUANTIZATION_RANGE_SUPPORT                         _ON
#define _YCC_QUANTIZATION_RANGE_SUPPORT                         _ON
#define _ULTRA_VIVID_SUPPORT                                    _ON
#define _DCR_SUPPORT                                            _ON
#define _DCC_FUNCTION                                           _ON
#define _DCC_HISTOGRM_INFO                                      _OFF
#define _ICM_SUPPORT                                            _ON
#define _ICM_BRI_SUPPORT                                        _OFF
#define _SIX_COLOR_SUPPORT                                      _ON
#define _HIGHLIGHT_WINDOW_SUPPORT                               _ON
#define _RINGING_FILTER_SUPPORT                                 _ON
#define _SHARPNESS_SUPPORT                                      _ON
#define _CONTRAST_SUPPORT                                       _ON
#define _CONTRAST_BY_SRGB_SUPPORT                               _OFF
#define _BRIGHTNESS_SUPPORT                                     _ON

//--------------------------------------------------
// Y Peaking Option
//--------------------------------------------------
#define _YPEAKING_SUPPORT                                       _ON

#define _YPEAKING_CORING_MIN                                    3     // effective:0~31
#define _YPEAKING_MAX_POS                                       20    // effective:0~255
#define _YPEAKING_MAX_NEG                                       (-40) // effective:-128~127

//-------------------------------------------------
// Hue and Saturation Option
//-------------------------------------------------
#define _GLOBAL_HUE_SATURATION                                  _ON

#define _HUE_MAX                                                230
#define _HUE_MIN                                                30
#define _SATURATION_MAX                                         200
#define _SATURATION_MIN                                         0


////////////////////////////////////////
// Off-Line Display Color Calibration //
////////////////////////////////////////

//-------------------------------------------------
// PCM (Load Code Table) Option
//-------------------------------------------------
#define _PCM_FUNCTION                                           _ON

//-------------------------------------------------
// 3D Gamma (Load Code Table) Option
//-------------------------------------------------
#define _RGB_3D_GAMMA                                           _OFF

//-------------------------------------------------
// RGB Gamma (Load Code Table) Option
//-------------------------------------------------
#define _RGB_GAMMA_FUNCTION                                     _OFF


////////////////////////////////////////
// On-Line Display Color Calibration //
////////////////////////////////////////

//-------------------------------------------------
// OGC and OCC (On-Line Calibration) Option
//-------------------------------------------------
#define _OCC_SUPPORT                                            _OFF
#define _OGC_SUPPORT                                            _OFF
#define _OGC_DICOM_SUPPORT                                      _OFF

#define _OGC_TOTAL_GAMMA                                        5 // 1/2/3/4/5
#define _OGC_TOTAL_CT                                           6
#define _OGC_FLASH_BANK                                         7
#define _OGC_FLASH_PAGE                                         0


////////////
// Eeprom //
////////////


//-------------------------------------------------
// Eeprom Access Function Option
//-------------------------------------------------
#define _EEPROM_ACCESS_FUNCTION_SUPPORT                         _OFF

//-------------------------------------------------
// System Eeprom Start Address for Kernel Data Option
//-------------------------------------------------
#define _EEPROM_KERNEL_START_ADDRESS                            (_EEPROM_PAGE0_BANK0)


///////////
// Flash //
///////////

//-------------------------------------------------
// Flash Clock Option
//-------------------------------------------------
#define _FLASH_CLK_SPEED                                        _FLASH_FAST_SPEED

//-------------------------------------------------
// Flash Access Function Option
//-------------------------------------------------
#define _FLASH_WRITE_FUNCTION_SUPPORT                           _ON
#define _FLASH_READ_FUNCTION_SUPPORT                            _ON

#define _FLASH_TYPE_W25X20A_OR_W25X21CL                         _FLASH_W25X20A
#define _FLASH_TYPE_W25X40CL_OR_W25X41CL                        _FLASH_W25X40CL
#define _FLASH_TYPE_GD25Q16C_OR_GD25Q16                         _FLASH_GD25Q16C
#define _FLASH_TYPE_MX25L3206E_OR_MX25L3233F_OR_KH25L3236F      _FLASH_MX25L3233F
#define _FLASH_TYPE_GD25Q40B_OR_GD25Q41B                        _FLASH_GD25Q41B
#define _FLASH_TYPE_W25Q16DV_OR_W25Q16JVSIQ                     _FLASH_W25Q16JVSIQ
#define _FLASH_TYPE_FM25Q08_OR_FM25Q08A_OR_FM25Q08B             _FLASH_FM25Q08A
#define _FLASH_TYPE_BY25D40C_OR_BY25D40ASTIG                    _FLASH_BY25D40C
#define _FLASH_TYPE_W25Q32F_OR_W25Q32JVSSIQ                     _FLASH_W25Q32F
#define _FLASH_TYPE_BY25D80ASTIG_OR_BY25Q80BSTIG                _FLASH_BY25D80ASTIG
#define _FLASH_TYPE_AT25SF041_OR_AT25SF041B                     _FLASH_AT25SF041
#define _FLASH_TYPE_AT25SF321_OR_AT25SF321B                     _FLASH_AT25SF321
#define _FLASH_TYPE_EN25QH32A_OR_EN25QH32B                      _FLASH_EN25QH32A
#define _FLASH_TYPE_IS25LQ040B_OR_IS25LP040E                    _FLASH_IS25LQ040B
#define _FLASH_TYPE_P25Q16H_OR_P25Q16SH                         _FLASH_P25Q16H
#define _FLASH_TYPE_EN25Q80_OR_EN25Q80C                         _FLASH_EN25Q80
#define _FLASH_TYPE_EN25Q40A_OR_EN25Q40B                        _FLASH_EN25Q40A
#define _FLASH_TYPE_W25Q80BV_OR_W25Q80RVSNIQ                    _FLASH_W25Q80BV

#define _FLASH_EWSR_FUNCTION_SUPPORT                            _OFF

//-------------------------------------------------
// EEPROM Emulation Option
//-------------------------------------------------
#define _SYSTEM_EEPROM_EMULATION_SUPPORT                        _ON

#define _SYSTEM_EEPROM_EMULATION_FLASH_BANK                     15//10
#define _SYSTEM_EEPROM_EMULATION_START_PAGE                     11
#define _SYSTEM_EEPROM_EMULATION_END_PAGE                       12
#define _START_OF_PAGEID                                        _PAGEID_0
#define _END_OF_PAGEID                                          _PAGEID_0
#define _CHECKSUM_VERSIONCODE_ID                                _PAGEID_0




#define _HW_DISPLAY_ROTATION_90_SUPPORT                         _OFF
#define _HW_DISPLAY_ROTATION_180_SUPPORT                        _ON
#define _HW_DISPLAY_ROTATION_270_SUPPORT                        _OFF

//////////
// EDID //
//////////

//-------------------------------------------------
// EDID Location Option
//-------------------------------------------------
#define _EDID_ADDRESS_EEPROM                                    (_EEPROM_PAGE7_BANK0)
#define _EDID_ADDRESS_FLASH                                     0
#define _EDID_FLASH_BANK                                        13
#define _EDID_HDR10_AUTO_SWITCH                                 _OFF


//////////////
// HDCP Key //
//////////////

//-------------------------------------------------
// HDCP Key Location Option
//-------------------------------------------------
#define _HDCP_1_4_KEY_LOCATION                                  _TABLE_LOCATION_FLASH

//-------------------------------------------------
// For HDCP 1.4 Rx Key (FW Size : 325 Bytes ; Tool Size : 376 Bytes)
//-------------------------------------------------
#define _RX_HDCP_1_4_KEY_ADDRESS_EEPROM                         (_EEPROM_PAGE2_BANK1)
#define _RX_HDCP_1_4_KEY_ADDRESS_FLASH                          0xF000
#define _RX_HDCP_1_4_KEY_FLASH_BANK                             31


///////////////////
// System Source //
///////////////////

//-------------------------------------------------
// System Auto Search Style Option
//-------------------------------------------------
#define _SOURCE_AUTO_SEARCH_STYLE                               _SOURCE_POLLING_IN_SEARCH_STATE

//-------------------------------------------------
// System Source Search Time Option
//-------------------------------------------------
#define _SOURCE_DEFAULT_SEARCH_TIME_VGA                         SEC(1.8)
#define _SOURCE_DEFAULT_SEARCH_TIME_HDMI                        SEC(2)
#define _SOURCE_DEFAULT_SEARCH_TIME_DVI                         SEC(2)
#define _SOURCE_DEFAULT_SEARCH_TIME_DP                          SEC(3)
#define _SOURCE_DEFAULT_SEARCH_TIME_TYPE_C                      SEC(4.5)


//////////////////
// System Judge //
//////////////////

//-------------------------------------------------
// System Display Setting Check Time Option
//-------------------------------------------------
#if(_PROJECT_ID == _ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID == _ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _WAIT_TIME_TO_ACTIVE_VGA                                SEC(1.1)
#define _WAIT_TIME_TO_ACTIVE_DVI                                SEC(1.1)
#define _WAIT_TIME_TO_ACTIVE_HDMI                               SEC(1.1)
#define _WAIT_TIME_TO_ACTIVE_DP                                 SEC(1.1)
#else
#define _WAIT_TIME_TO_ACTIVE_VGA                                SEC(0.05)
#define _WAIT_TIME_TO_ACTIVE_DVI                                SEC(0.1)
#define _WAIT_TIME_TO_ACTIVE_HDMI                               SEC(0.1)
#define _WAIT_TIME_TO_ACTIVE_DP                                 SEC(0.1)
#endif
//--------------------------------------------------
// System Support Timing Option
//--------------------------------------------------
#define _OOR_H_FREQ_UPPER_BOUND                                 1100 // Unit in 0.1 kHZ
#define _OOR_H_FREQ_LOWER_BOUND                                 100  // Unit in 0.1 kHZ
#define _OOR_V_FREQ_UPPER_BOUND                                 845  // Unit in 0.1 HZ
#define _OOR_V_FREQ_LOWER_BOUND                                 450  // Unit in 0.1 HZ
#define _OOR_H_WIDTH_UPPER_BOUND                                2048 // Unit in pixel
#define _OOR_V_HEIGHT_LOWER_BOUND                               240  // Unit in line

#define _FAIL_SAVE_H_FREQ_UPPER_BOUND                           1000 // Unit in 0.1 kHZ
#define _FAIL_SAVE_H_FREQ_LOWER_BOUND                           110  // Unit in 0.1 kHZ
#define _FAIL_SAVE_V_FREQ_UPPER_BOUND                           760  // Unit in 0.1 HZ
#define _FAIL_SAVE_V_FREQ_LOWER_BOUND                           495  // Unit in 0.1 HZ

#define _INPUTCLOCK_RANG_VGA                                    2100 // Unit in 0.1 MHz
#define _INPUTCLOCK_RANG_DVI                                    2250 // Unit in 0.1 MHz, Max 3000 (297MHz + 3MHz margin) for (_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == ON)
#define _INPUTCLOCK_RANG_HDMI                                   3000 // Unit in 0.1 MHz, Max 3000 (297MHz + 3MHz margin) for (_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == ON)
#define _INPUTCLOCK_RANG_DP                                     3000 // Unit in 0.1 MHz, Max 2350 (230MHz + 5MHz margin) for (_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == ON)




//-------------------------------------------------
// Uniformity (On Line Calibration) Option
//-------------------------------------------------
#define _UNIFORMITY_SUPPORT                                     _OFF

#define _UNIFORMITY_FLASH_BANK0                                 14
#define  _UNIFORMITY_1ST_TABLE_LEVEL                           _UNIFORMITY_NONE
#define  _UNIFORMITY_2ND_TABLE_LEVEL                           _UNIFORMITY_NONE
#define  _UNIFORMITY_3RD_TABLE_LEVEL                           _UNIFORMITY_NONE
#define  _UNIFORMITY_4TH_TABLE_LEVEL                           _UNIFORMITY_NONE
#define  _UNIFORMITY_5TH_TABLE_LEVEL                           _UNIFORMITY_NONE
#define  _UNIFORMITY_6TH_TABLE_LEVEL                           _UNIFORMITY_NONE


//--------------------------------------------------
// VGA YPBPR Option
//--------------------------------------------------
#define _YPBPR_SUPPORT                                          _ON
#define _SOG_SUPPORT                                            _ON
#define _VGA_COMPOSITE_SUPPORT                                  _ON

//--------------------------------------------------
// VGA Mode Search condition reference by picture width Option
//--------------------------------------------------
#define _MODE_SEARCH_BY_ACTIVE_MEASURE_SUPPORT                  _ON

//--------------------------------------------------
// VGA Auto Adjust Clock Setup Option
//--------------------------------------------------
#define _AUTO_CLOCK_STEP                                        2  // 1 or 2
#define _AUTO_CLOCK_RANGE                                       95 // Set Clock Non-adjusting Range (%) by the active region
#define _AUTO_TOLERANCE_PIXEL                                   2  // Definitions Of tolerance pixel for Auto Clock
#define _AUTO_CLOCK_SAVE_VALUE_OPTION                           _CLOCK_SAVE_PERCENT_VALUE

//--------------------------------------------------
// VGA Gain & Offset Defualt Option
//--------------------------------------------------
#define _ADC_RGB_DEFAULT_RED_GAIN                               128
#define _ADC_RGB_DEFAULT_GREEN_GAIN                             128
#define _ADC_RGB_DEFAULT_BLUE_GAIN                              128
#define _ADC_RGB_DEFAULT_RED_OFFSET                             128
#define _ADC_RGB_DEFAULT_GREEN_OFFSET                           128
#define _ADC_RGB_DEFAULT_BLUE_OFFSET                            128

#define _ADC_YPBPR_DEFAULT_Y_GAIN                               159
#define _ADC_YPBPR_DEFAULT_PB_GAIN                              154
#define _ADC_YPBPR_DEFAULT_PR_GAIN                              154
#define _ADC_YPBPR_DEFAULT_Y_OFFSET                             112
#define _ADC_YPBPR_DEFAULT_PB_OFFSET                            128
#define _ADC_YPBPR_DEFAULT_PR_OFFSET                            128

//--------------------------------------------------
// VGA Self-Calibration Option
//--------------------------------------------------
#define _ADC_SELF_CALIBRATION                                   _ON

#define _CALIBRATION_R_GAIN_BIAS                                (0)  // Needs modification for EVERY single source
#define _CALIBRATION_G_GAIN_BIAS                                (0)  // Needs modification for EVERY single source
#define _CALIBRATION_B_GAIN_BIAS                                (0)  // Needs modification for EVERY single source
#define _CALIBRATION_R_OFFSET_BIAS                              (-3) // Needs modification for EVERY single source
#define _CALIBRATION_G_OFFSET_BIAS                              (-3) // Needs modification for EVERY single source
#define _CALIBRATION_B_OFFSET_BIAS                              (-3) // Needs modification for EVERY single source

//--------------------------------------------------
// VGA YPBPR Auto Color Method Option
//--------------------------------------------------
#define _YPBPR_AUTO_METHOD                                      _YPBPR_AUTO_BY_SOURCE

#define _AUTO_PB_GAIN_BIAS                                      (5)
#define _AUTO_PR_GAIN_BIAS                                      (5)
#define _AUTO_Y_GAIN_BIAS                                       (0)
#define _AUTO_PB_OFFSET_BIAS                                    (-8)
#define _AUTO_PR_OFFSET_BIAS                                    (-8)
#define _AUTO_Y_OFFSET_BIAS                                     (-16)

//--------------------------------------------------
// VGA Digital Filter Option
//--------------------------------------------------
#define _DIG_FILTER_NSMEAR_ENABLE                               _ENABLE
#define _DIG_FILTER_PSMEAR_ENABLE                               _ENABLE
#define _DIG_FILTER_NRING_ENABLE                                _ENABLE
#define _DIG_FILTER_PRING_ENABLE                                _ENABLE
#define _DIG_FILTER_EXTENSION_ENABLE                            _ENABLE
#define _DIG_FILTER_ENHANCE_PHASE_ENABLE                        _ENABLE


////////////////
// DVI & HDMI //
////////////////

//--------------------------------------------------
// DVI & HDMI Option
//--------------------------------------------------
#define _DVI_DE_ONLY_SUPPORT                                    _ON
#define _HDMI_FROM_DVI_CONNECT                                  _ON
#define _HDMI_FREESYNC_SUPPORT                                  _ON
#define _TMDS_HDCP_2_2_SUPPORT                                  _OFF

//--------------------------------------------------
// HDMI CTS Option
//--------------------------------------------------
#define _TMDS_HDCP_FEATURE                                      _HDCP_FEATURE_BY_INPUT
#define _TMDS_Z0_POWER_SAVING_OPTION                            _ALL_CHANNEL_CONNECTED_FOR_CTS


////////
// DP //
////////
//-------------------------------------------------
// DP Capability Option
//-------------------------------------------------
#define _DP_MST_SUPPORT                                         _OFF
#define _DP_TX_SUPPORT                                          _OFF
#define _DP_FREESYNC_SUPPORT                                    _OFF


///////////
// Audio //
///////////

//-------------------------------------------------
// Audio Option
//-------------------------------------------------
#define _AUDIO_SUPPORT                                          _ON

#define _AUDIO_DVC_FAST_CONTROL_SUPPORT                         _OFF // To Resolve Short Audio Issue

//-------------------------------------------------
// Audio DAC Option
//-------------------------------------------------
#define _EMBEDDED_DAC_SUPPORT                                   _ON

//-------------------------------------------------
// Audio Line In Option
//-------------------------------------------------
#define _LINE_IN_SUPPORT                                        _ON

#define _LINE_IN_DAC_AOUT_GAIN_DB                               _AUDIO_DAC_OUTPUT_GAIN_0_DB // 0dB, 0.5dB for each step, Max Gain: 'b111(3.5dB)
#define _LINE_IN_DAC_HPOUT_GAIN_DB                              _AUDIO_DAC_OUTPUT_GAIN_0_DB // 0dB, 0.5dB for each step, Max Gain: 'b111(3.5dB)
#define _LINE_IN_BOOST_GAIN_DB                                  0x17                        // 0dB, 1.5dB for each step, Max Gain: 0x3F(30dB)
#define _LINE_IN_VOLUME_MAX                                     0x3FFF                      // MAX: 0x3FFF
#define _LINE_IN_VOLUME_MIN                                     0x0000

//-------------------------------------------------
// Audio Digital Option
//-------------------------------------------------
#define _DIGITAL_DAC_AOUT_GAIN_DB                               _AUDIO_DAC_OUTPUT_GAIN_0_DB // 0dB, 0.5dB for each step, Max Gain: 'b111(3.5dB)
#define _DIGITAL_DAC_HPOUT_GAIN_DB                              _AUDIO_DAC_OUTPUT_GAIN_0_DB // 0dB, 0.5dB for each step, Max Gain: 'b111(3.5dB)
#define _DIGITAL_VOLUME_MAX                                     0x3FFF                      // MAX: 0x3FFF
#define _DIGITAL_VOLUME_MIN                                     0x0000

//-------------------------------------------------
// Audio PS Option
//-------------------------------------------------
#define _SLEEP_AUDIO_SUPPORT                                    _OFF

#define _PS_AUDIO_INPUT                                         _PS_AUDIO_LINE_IN


#define _IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT                   _ON


//-------------------------------------------------
// Instant Timer Events Option
//-------------------------------------------------
#define _INSTANT_TIMER_EVENT_0                                  _ON
#define _INSTANT_TIMER_EVENT_1                                  _OFF



#endif // End of #if(_PROJECT == _RL6410_PROJECT)
