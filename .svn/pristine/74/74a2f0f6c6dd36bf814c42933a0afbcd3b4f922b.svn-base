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
// ID Code      : RL6851_PCB_EXAMPLE_128_PIN.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6851_PCB_EXAMPLE_128_PIN)


///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// FW Support Xtal-less
//--------------------------------------------------
#define _XTALESS_SUPPORT                        _OFF

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K


///////////////
// Debug DDC //
///////////////

//--------------------------------------------------
// Debug DDC Channel
//--------------------------------------------------
#define _PCB_DEBUG_DDC                          _VGA_DDC


///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#define _A0_INPUT_PORT_TYPE                     _A0_NO_PORT
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _A0_CODE_DIGITAL_SIGNATURE_ISP_EN       _DISABLE
#define _A0_PC99_EMBEDDED_EDID_CODE_TABLE       "./EDID/EdidTableDummy128.h"

//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_NO_PORT
#define _D0_DDC_CHANNEL_SEL                     _NO_DDC
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D0_CODE_DIGITAL_SIGNATURE_ISP_EN       _DISABLE
#define _D0_PC99_EMBEDDED_EDID_CODE_TABLE       "./EDID/EdidTableDummy256.h"

// For HDMI MultiEdid
#define _D0_MAX_HDMI_EDID_COUNT                 1
#define _D0_HDMI_CEC_PIN                        _HDMI_CEC_NONE

// For DP
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D0_DP_TYPE_C_PORT_CTRL_TYPE            _PORT_CONTROLLER_RTS5400_SERIES
#define _D0_DP_TYPE_C_USB_HUB_TYPE              _USB_HUB_RTS5411_SERIES
#define _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D0_DP_TYPE_C_HUB_SLAVE_ADDR            0x00
#define _D0_DP_TYPE_C_RTK_PC_SMBUS_IIC          _HW_IIC_PIN_37_38_0_0
#define _D0_DP_TYPE_C_PIN_E_AUXPN_SWAP          _SWAP_BY_PORT_CONTROLLER
#define _D0_DP_TYPE_C_EXT_LANE_SWAP_FOR_PIN_E   _SWAP_BY_SCALER
#define _D0_DP_TYPE_C_EXT_PORT_CTRL_LANE_SWAP   _SWAP_BY_PORT_CONTROLLER

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_NO_PORT
#define _D1_DDC_CHANNEL_SEL                     _NO_DDC
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D1_CODE_DIGITAL_SIGNATURE_ISP_EN       _DISABLE
#define _D1_PC99_EMBEDDED_EDID_CODE_TABLE       "./EDID/EdidTableDummy256.h"

// For HDMI MultiEdid
#define _D1_MAX_HDMI_EDID_COUNT                 1
#define _D1_HDMI_CEC_PIN                        _HDMI_CEC_NONE

// For DP
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D1_DP_TYPE_C_PORT_CTRL_TYPE            _PORT_CONTROLLER_RTS5400_SERIES
#define _D1_DP_TYPE_C_USB_HUB_TYPE              _USB_HUB_RTS5411_SERIES
#define _D1_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D1_DP_TYPE_C_HUB_SLAVE_ADDR            0x00
#define _D1_DP_TYPE_C_RTK_PC_SMBUS_IIC          _HW_IIC_PIN_37_38_0_0
#define _D1_DP_TYPE_C_PIN_E_AUXPN_SWAP          _SWAP_BY_PORT_CONTROLLER
#define _D1_DP_TYPE_C_EXT_LANE_SWAP_FOR_PIN_E   _SWAP_BY_SCALER
#define _D1_DP_TYPE_C_EXT_PORT_CTRL_LANE_SWAP   _SWAP_BY_PORT_CONTROLLER

//--------------------------------------------------
// Digital Signature DDC Channel for HUB ISP
//--------------------------------------------------
#define _CODE_DIGITAL_SIGNATURE_HUB_DDC_SEL     _VGA_DDC


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _NO_INPUT_PORT


//////////////
// VGA Port //
//////////////

//--------------------------------------------------
// Analog Signal Swap Options
//--------------------------------------------------
#define _VGA_INPUT_SWAP_RG                      _OFF
#define _VGA_INPUT_SWAP_RB                      _OFF
#define _VGA_INPUT_SWAP_GB                      _OFF

//--------------------------------------------------
// Analog Hsync Schmitt Trigger Control
//--------------------------------------------------
#define _VGA_HS_SCHMITT_TRIGGER_POLARITY_SEL    _POSITIVE
#define _VGA_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE   _DISABLE
#define _VGA_HS_SCHMITT_TRIGGER_POSITIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_10
#define _VGA_HS_SCHMITT_TRIGGER_NEGATIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_01


///////////////
// TMDS Port //
///////////////

//--------------------------------------------------
// TMDS Signal Swap Options
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
#define _D0_TMDS_BR_SWAP                        _ON
#define _D0_TMDS_PN_SWAP                        _ON
#else
#define _D0_TMDS_BR_SWAP                        _OFF
#define _D0_TMDS_PN_SWAP                        _OFF
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
#define _D1_TMDS_BR_SWAP                        _ON
#define _D1_TMDS_PN_SWAP                        _ON
#else
#define _D1_TMDS_BR_SWAP                        _OFF
#define _D1_TMDS_PN_SWAP                        _OFF
#endif


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_CD
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#define _LVDS_RB_SWAP                           _DISABLE
#define _LVDS_ML_SWAP                           _DISABLE
#define _LVDS_DVS_INVERT                        _DISABLE
#define _LVDS_DHS_INVERT                        _DISABLE
#define _LVDS_DEN_INVERT                        _DISABLE
#define _LVDS_PAIR_MIRROR                       _DISABLE

//--------------------------------------------------
// LVDS Port AB Phase Selection
//--------------------------------------------------
#define _LVDS_A0_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A1_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A2_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_AC_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A3_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B0_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B1_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B2_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B3_PHASE                          _LVDS_PI_PHASE_AB0

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE
#define _LVDS_SHAPE_ADJUSTMENT                  _LVDS_SHAPE_NONE
#define _LVDS_VCM_USER_LEVEL                    0x0C
#define _LVDS_TRIM_DRIV_CURRENT_BY_USER         _DISABLE
#define _LVDS_TRIM_DRIV_CURRENT_USER_ADUST      3500 // Unit in uA

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------
#define _LVDS_SPREAD_RANGE                      10
#define _LVDS_SPREAD_SPEED                      _SPEED_33K

//-------------------------------------------------
// LVDS User Mode Setting Control
//-------------------------------------------------
#define _LVDS_SETTING_CONTROL_BY_USER           _DISABLE
#define _LVDS_DRIV_CURRENT_USER_ADUST           0x70
#define _LVDS_PORTA_DATA0_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTA_DATA1_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTA_DATA2_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTA_DATA3_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTA_DATA4_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTB_DATA0_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTB_DATA1_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTB_DATA2_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTB_CLK_DRIV_2X_USER_CTRL       _DISABLE
#define _LVDS_PORTB_DATA3_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTB_DATA4_DRIV_2X_USER_CTRL     _DISABLE
#define _LVDS_PORTA_DATA0_TERM_USER_ADJUST      0x00
#define _LVDS_PORTA_DATA1_TERM_USER_ADJUST      0x00
#define _LVDS_PORTA_DATA2_TERM_USER_ADJUST      0x00
#define _LVDS_PORTA_DATA3_TERM_USER_ADJUST      0x00
#define _LVDS_PORTA_DATA4_TERM_USER_ADJUST      0x00
#define _LVDS_PORTB_DATA0_TERM_USER_ADJUST      0x00
#define _LVDS_PORTB_DATA1_TERM_USER_ADJUST      0x00
#define _LVDS_PORTB_DATA2_TERM_USER_ADJUST      0x00
#define _LVDS_PORTB_CLK_TERM_USER_ADJUST        0x00
#define _LVDS_PORTB_DATA3_TERM_USER_ADJUST      0x00
#define _LVDS_PORTB_DATA4_TERM_USER_ADJUST      0x00
#define _LVDS_PORTA_WEAK_PULL_DOWN_USER_CTRL    _DISABLE
#define _LVDS_PORTA_STRONG_PULL_DOWN_USER_CTRL  _DISABLE
#define _LVDS_PORTB_WEAK_PULL_DOWN_USER_CTRL    _DISABLE
#define _LVDS_PORTB_STRONG_PULL_DOWN_USER_CTRL  _DISABLE


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_LANE_SWAP               _DISABLE               // Lane Port Swap
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _ENABLE                // Lane PN Swap
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV       // Swing Level = 400,600,800,1200mV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB   // Preemphasis Level = 0,3.5,6,9.5dB

//--------------------------------------------------
// eDPTx 1.1 HBR SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            5                      // 0~15, 0 ~ disable, 15 ~ 0.98%
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K             // _SPEED_30K or _SPEED_33K


////////////////////////////
// eDPTx Panel AUX Config //
////////////////////////////

//--------------------------------------------------
// eDPTx AUX Swing Level
//--------------------------------------------------
#define _PANEL_DPTX_AUX_SWING_LEVEL             _DP_AUX_SWING_1100_MV


/////////////
// DP Port //
/////////////

//--------------------------------------------------
// DP Lane & PN Swap Option
//--------------------------------------------------
#define _D0_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#define _D0_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#define _D0_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#define _D0_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#define _D0_DP_PCB_LANE0_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE1_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE2_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE3_PN_SWAP                _OFF

#define _D1_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#define _D1_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#define _D1_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#define _D1_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#define _D1_DP_PCB_LANE0_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE1_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE2_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE3_PN_SWAP                _OFF

//--------------------------------------------------
// DP Rx AUX Reply Swing Level
//--------------------------------------------------
#define _DP_RX_AUX_REPLY_SWING_LEVEL            _DP_AUX_SWING_900_MV


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _NO_PWM
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_PDOW_EN                           _OFF
#define _PWM1_PDOW_EN                           _OFF
#define _PWM2_PDOW_EN                           _OFF
#define _PWM3_PDOW_EN                           _OFF
#define _PWM4_PDOW_EN                           _OFF
#define _PWM5_PDOW_EN                           _OFF

#define _PWM0_RST_EN                            _OFF
#define _PWM1_RST_EN                            _OFF
#define _PWM2_RST_EN                            _OFF
#define _PWM3_RST_EN                            _OFF
#define _PWM4_RST_EN                            _OFF
#define _PWM5_RST_EN                            _OFF
#define _PWM_RST_SIGNAL_SEL                     _DVS

#define _PWM_FREQ_DVSRST_CHECK                  _ON


//////////
// TCON //
//////////

//--------------------------------------------------
// MBR TCON Pin Setting
//--------------------------------------------------
#define _PCB_MBR_TCON_PIN                       _TCON_NONE


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#define _SW_IIC_SUPPORT                         _OFF
#define _SW_IIC_CLK_DIV                         _DIV_1
#define SW_IIC_START_INTERVAL_DELAY()           {SW_IIC_DELAY_TIME();}

#define _HW_IIC_SUPPORT                         _OFF
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K
#define _HW_IIC_PAR_BY_USER_SUPPORT             _OFF


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _NO_IIC_PIN


////////////////////////////
// Second External Eeprom //
////////////////////////////

//--------------------------------------------------
// Second External Eeprom Data Storage Option
//--------------------------------------------------
#define _SEC_EEPROM_TYPE                        _EEPROM_CAT24M01
#define _SEC_EEPROM_SLAVE_ADDRESS               0xA0
#define _PCB_SEC_EEPROM_IIC                     _NO_IIC_PIN


//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#define _AD_KEY_SUPPORT                         _OFF

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _OFF

//--------------------------------------------------
// FLASH SPI Control Option
//--------------------------------------------------
#define _FLASH_CLK_DRIVE_CURRENT                _SPI_DRIVE_4_0MA
#define _FLASH_SI_SO_CEB_DRIVE_CURRENT          _SPI_DRIVE_4_0MA
#define _FLASH_CLK_SLEW_RATE_CONTROL            _SPI_FAST_SLEW_RATE
#define _FLASH_SI_SO_CEB_SLEW_RATE_CONTROL      _SPI_FAST_SLEW_RATE


//////////////////////
// Series Pin Share //
//////////////////////
#include "RL6851_PCB_EXAMPLE_128_PIN_PINSHARE.h"


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO ON/OFF Region Initial Setting
// PIN67-74
//-----------------------------------------------
#define PCB_ON_REGION_GPIO_SETTING_POWER_AC_ON(){\
                                                }

#define PCB_OFF_REGION_GPIO_SETTING_POWER_AC_PD_PS_ON()\
                                                {\
                                                }

#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                }

#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                }

#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                }


/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of Embedded LDO Support
//-----------------------------------------------
#define bEMBEDDEDLDO                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EMBEDDED_LDO_OFF                       0
#define _EMBEDDED_LDO_ON                        1

#define PCB_EMBEDDED_LDO_DETECT()               (bEMBEDDEDLDO)

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Low
//-----------------------------------------------
#define bPOWERBOARDPOWER                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LOW_POWER_ON                           1
#define _LOW_POWER_OFF                          0

#define PCB_POWERBOARD_LOWPOWER(x)              {\
                                                    bPOWERBOARDPOWER = (x);\
                                                }


////////////////////
// DP Power Macro //
////////////////////

//-----------------------------------------------
// Macro of MyDP Power Control
//-----------------------------------------------
#define bD0_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _MYDP_5V_POWER_ON                       1
#define _MYDP_5V_POWER_OFF                      0

#define PCB_D0_MYDP_POWER(x)                    {\
                                                    bD0_MYDP_POWER = (x);\
                                                }

#define PCB_D1_MYDP_POWER(x)                    {\
                                                    bD1_MYDP_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of DP1.2 Power Control
//-----------------------------------------------
#define bD0_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DP12_33V_POWER_ON                      1
#define _DP12_33V_POWER_OFF                     0

#define PCB_D0_DP12_POWER(x)                    {\
                                                    bD0_DP12_POWER = (x);\
                                                }

#define PCB_D1_DP12_POWER(x)                    {\
                                                    bD1_DP12_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of MyDP & DP1.2 Power Select
//-----------------------------------------------
#define bD0_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DP12_33V_POWER                         0
#define _MYDP_5V_POWER                          1

#define PCB_D0_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD0_D12_MYDP_SEL = (x);\
                                                }

#define PCB_D1_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD1_D12_MYDP_SEL = (x);\
                                                }


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LIGHT_CONTROL_ON                       0
#define _LIGHT_CONTROL_OFF                      1

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = (x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (((DWORD)_PANEL_TYP_FRAME_RATE * 60) / 100));\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    PCB_BACKLIGHT_POWER_PIN(x)\
                                                }


//////////////////////////////////////
// eDPTx Panel Power Sequence Macro //
//////////////////////////////////////

//--------------------------------------------------
// eDPTx 1.1 Panel Power Sequence Macro
//--------------------------------------------------
#define PCB_DPTX1_POWER_SEQUENCE(x)             {\
                                                }


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of TTS Flash write protect pin
//-----------------------------------------------
#define bTTS_FLASH_WRITE_PROTECT                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _TTS_FLASH_WRITE_PROTECT_ENABLE         0
#define _TTS_FLASH_WRITE_PROTECT_DISABLE        1

#define PCB_TTS_FLASH_WRITE_PROTECT(x)          {\
                                                    bTTS_FLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of HDMI External EDID Switch : #if (_HDMI_MULTI_EDID_SUPPORT == _ON)
//-----------------------------------------------
#define bD0_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_EDID_ENABLE                     0
#define _EEPROM_EDID_DISABLE                    1

#define PCB_MULTI_EDID_ALL_SWITCH_OFF(port)     {\
                                                }

#define PCB_MULTI_EDID_SWITCH(port, index)      {\
                                                }

#define PCB_MULTI_EDID_SWITCH_POWER_AC_ON()     {\
                                                }


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#define bD0_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD1_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

// For DP Type-C
#define bD0_USB_TYPE_C_AUXP_CONNECT             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_USB_TYPE_C_AUXN_CONNECT             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD1_USB_TYPE_C_AUXP_CONNECT             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_USB_TYPE_C_AUXN_CONNECT             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bA0_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_CONNECT                             (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))

// For DP Type-C
#define bD0_CONNECT                             (((bit)bD0_USB_TYPE_C_AUXP_CONNECT == _TRUE) && ((bit)bD0_USB_TYPE_C_AUXN_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_USB_TYPE_C_AUXP_CONNECT == _TRUE) && ((bit)bD1_USB_TYPE_C_AUXN_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)

// For DP Type-C
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_USB_TYPE_C_AUXN_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_USB_TYPE_C_AUXN_CONNECT)

// For DP Source Power When under Pin E Type and Aux PN Swap
#define GET_PCB_D0_DP_SOURCE_POWER_PN_SWAP()    (bD0_USB_TYPE_C_AUXP_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER_PN_SWAP()    (bD1_USB_TYPE_C_AUXP_CONNECT)

//-----------------------------------------------
// Aux PN 1M Pull High / low Swap Control
//-----------------------------------------------
#define bD0_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN      (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN      (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AUX_PN_1M_PULL_HI_LOW_SWAP_ON          1
#define _AUX_PN_1M_PULL_HI_LOW_SWAP_OFF         0

#define PCB_D0_AUX_PN_1M_PULL_H_L_SWAP(x)       {\
                                                    bD0_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN = (x);\
                                                }

#define PCB_D1_AUX_PN_1M_PULL_H_L_SWAP(x)       {\
                                                    bD1_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN = (x);\
                                                }

#define PCB_GET_D0_AUX_PN_1M_PULL_H_L_SWAP()    (bD0_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN)
#define PCB_GET_D1_AUX_PN_1M_PULL_H_L_SWAP()    (bD1_AUX_PN_1M_PULL_HI_LOW_SWAP_PIN)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _D0_HOT_PLUG_HIGH                       1
#define _D0_HOT_PLUG_LOW                        0

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = (x);\
                                                }

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }

#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)


///////////////////
// Display Macro //
///////////////////

//--------------------------------------------------
// Macro of LVDS eDP Panel and eQC model Switch Control
//--------------------------------------------------
#define bLVDSDPTX_GPU_SWICH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LVDS_PANEL_OUTPUT                      0
#define _DPTX_PANEL_OUTPUT                      1

#define PCB_SET_LVDS_DPTX_SWITCH(x)             {\
                                                    if((x) == _LVDS_PANEL_OUTPUT)\
                                                    {\
                                                        bLVDSDPTX_GPU_SWICH = (x);\
                                                    }\
                                                    else if((x) == _DPTX_PANEL_OUTPUT)\
                                                    {\
                                                        bLVDSDPTX_GPU_SWICH = (x);\
                                                    }\
                                                    else if((x) == _EQC_FUNTION_OUTPUT)\
                                                    {\
                                                        bLVDSDPTX_GPU_SWICH = (0);\
                                                    }\
                                                }


///////////////
// PWM Macro //
///////////////

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240);\
                                                }

#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_8BIT_PWM_DUTY(_BACKLIGHT_PWM))

#elif(_PWM_DUT_RESOLUTION == _PWM_12BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_12BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_12BIT_PWM_DUTY(_BACKLIGHT_PWM))

#endif


//////////////////
// SW IIC Macro //
//////////////////

//--------------------------------------------------
// Macro of IIC : (_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        (x) = bSWIIC_SYS_EEPROM_SDA;\
                                                    }\
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        (x) = bSWIIC_SYS_EEPROM_SCL;\
                                                    }\
                                                }


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bLED2                                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                }

#define PCB_LED_IDLE()                          {\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                }

#define PCB_LED_ON()                            {\
                                                }

#define PCB_LED_OFF()                           {\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                }

#define PCB_LED_TYPE3()                         {\
                                                }

#define PCB_LED_TYPE4()                         {\
                                                }

#define PCB_LED_TYPE5()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY0                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY1                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY2                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY3                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (_FALSE)
#define PCB_ADKEY2()                            (_FALSE)
#define PCB_ADKEY3()                            (_FALSE)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }


////////////////////
// GPIO Key Macro //
////////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define bPOWER_KEY                              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bMENU_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bEXIT_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bLEFT_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bRIGHT_KEY                              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }


/////////////////
// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio Connect
//-----------------------------------------------
#define bAUDIODETECT                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AUDIO_CONNECT                          0
#define _AUDIO_DISCONNECT                       1

#define PCB_AUDIO_DETECT()                      (bAUDIODETECT)

//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#define bPCBAMPMUTECONTROL                      (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AMP_MUTE_ON                            0
#define _AMP_MUTE_OFF                           1

#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = (x);\
                                                }
#endif // End of #if(_PCB_TYPE == _RL6851_PCB_EXAMPLE_128_PIN)
