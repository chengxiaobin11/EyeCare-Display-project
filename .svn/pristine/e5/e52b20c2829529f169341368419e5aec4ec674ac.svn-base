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
// ID Code      : RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS)


///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K

//--------------------------------------------------
// Debug DDC Channel
//--------------------------------------------------
#define _PCB_DEBUG_DDC                          _VGA_DDC//_DDC1//_VGA_DDC

///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#if(_HDMI_24C02_SUPPORT)
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER

#else
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_128
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE



#endif

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------

#if(_HDMI_24C02_SUPPORT)
#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _D1_EMBEDDED_DDCRAM_LOCATION           _EDID_TABLE_LOCATION_USER//_EDID_TABLE_LOCATION_CODE// _EDID_TABLE_LOCATION_CODE

#else

#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE           _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

#endif

/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D1_INPUT_PORT


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

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_5
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------
#define _LVDS_SPREAD_RANGE                      5
#define _LVDS_SPREAD_SPEED                      _SPEED_33K


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM0
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM0_EN                                _ON
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

#define _PWM0_RST_EN                            _ON
#define _PWM1_RST_EN                            _OFF
#define _PWM2_RST_EN                            _OFF
#define _PWM3_RST_EN                            _OFF
#define _PWM4_RST_EN                            _OFF
#define _PWM5_RST_EN                            _OFF
#define _PWM_RST_SIGNAL_SEL                     _DVS


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#if(_HDMI_24C02_SUPPORT)
#define _SW_IIC_SUPPORT                         _ON
#else
#define _SW_IIC_SUPPORT                         _OFF
#endif
#define _SW_IIC_CLK_DIV                         _DIV_1
	
#define _HW_IIC_SUPPORT                          _OFF// _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K
	


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0

#define _PCB_SYS_EEPROM_IIC                     _NO_IIC_PIN



//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#define _AD_KEY_SUPPORT                         _ON

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON


//////////////////////
// Series Pin Share //
//////////////////////
#include "RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS_PINSHARE.h"


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO ON/OFF Region Initial Setting
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
#define _EMBEDDED_LDO_OFF                       0
#define _EMBEDDED_LDO_ON                        1

#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_OFF)


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (_76PIN_PIN_59_MCU_REG)

#define _PANEL_CONTROL_ON                       1
#define _PANEL_CONTROL_OFF                      0

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (_76PIN_PIN_22_MCU_REG)

#define _LIGHT_CONTROL_ON                       1
#define _LIGHT_CONTROL_OFF                      0

#if(_MPRT_SUPPORT)
#define PCB_BACKLIGHT_POWER_PIN(x)              {\	 
                                                    bBACKLIGHTPOWER = (x);\
													if(x == _LIGHT_CONTROL_OFF)\
													PCB_MPRT_TCON_PIN_SHARE_CONFIG(_OFF);\
                                                }

#else

#define PCB_BACKLIGHT_POWER_PIN(x)              {\	   
                                                    bBACKLIGHTPOWER = (x);\
                                                }


#endif


#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, _BACKLIGHT_PWM_FREQUENCY);\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    PCB_BACKLIGHT_POWER_PIN(x)\
                                                }


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (_76PIN_PIN_58_MCU_REG)

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
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
#define bEDID_WRITE_PROTECT                  (_76PIN_PIN_30_MCU_REG)//   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)//
	
#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0
	
#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
														bEDID_WRITE_PROTECT = (x);\
													}
	
#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
														bEDID_WRITE_PROTECT = (x);\
													}


////////////////////////
// Cable Status Macro //
////////////////////////

#define _BACKLIGHT_PWM_FREQUENCY                25000

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------

#define bA0_CONNECT                             (_76PIN_PIN_23_MCU_REG)
#define bD1_CONNECT                             (_76PIN_PIN_24_MCU_REG)

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD1_HPD                                 (_76PIN_PIN_36_MCU_REG)

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }


#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)


///////////////
// PWM Macro //
///////////////

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, _BACKLIGHT_PWM_FREQUENCY);\
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
//HDMI DDC1


#define bSWIIC_SYS_EEPROM_SCL                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bPANELI2CSDA                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bPANELI2CSCL                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bDDC1IICSCL 							(_76PIN_PIN_70_MCU_REG)
#define bDDC1IICSDA 							(_76PIN_PIN_71_MCU_REG)

#define bDDCVGAIICSCL                           (_76PIN_PIN_62_MCU_REG)
#define bDDCVGAIICSDA                           (_76PIN_PIN_63_MCU_REG)


	
#define PCB_SW_IIC_SDA_SET()                    {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															bDDC1IICSDA = _TRUE;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															bDDCVGAIICSDA = _TRUE;						\
														}\
													}
	
#define PCB_SW_IIC_SDA_CLR()                    {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															bDDC1IICSDA = _FALSE;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															bDDCVGAIICSDA = _FALSE; 					\
														}\
													}
	
#define PCB_SW_IIC_SDA_CHK(x)                   {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															x = bDDC1IICSDA;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															x = bDDCVGAIICSDA;						\
														}\
													}
	
#define PCB_SW_IIC_SCL_SET()                    {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															bDDC1IICSCL = _TRUE;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															bDDCVGAIICSCL = _TRUE;						\
														}\
													}
#define PCB_SW_IIC_SCL_CLR()                    {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															bDDC1IICSCL = _FALSE;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															bDDCVGAIICSCL = _FALSE; 					\
														}\
													}
#define PCB_SW_IIC_SCL_CHK(x)                   {\
														if(GET_SW_IIC_STATUS() ==_IIC_FOR_DDC1)\
														{\
															x = bDDC1IICSCL;\
														}\
														else if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC)			\
														{												\
															x = bDDCVGAIICSCL;						\
														}\
													}




///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED2                                   (_76PIN_PIN_60_MCU_REG)
#define bLED1                                   (_76PIN_PIN_61_MCU_REG)

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }

	//-----------------------------------------------
	// Macro of Keypad Setting
	//-----------------------------------------------
// #define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // Pin_27
// #define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // Pin_28


// #define PCB_ADKEY1()                            (AD_KEY1)
// #define PCB_ADKEY2()                            (AD_KEY2)
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT)
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT)
#define AD_KEY3                                 (MCU_FF0B_ADC_A2_CONVERT_RESULT)
	
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
#define PCB_ADKEY3()                            (AD_KEY3)


#define bPOWER_KEY                                (_76PIN_PIN_29_MCU_REG)	

// 客户按键  左-右-确认-退出-电源
#if(1)

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)	{\
																if(((0x9D) <= (ucV2)) && ((ucV2) < (0xBD)))\
																{\
																	ucKeyState |= _EXIT_KEY_MASK;\
																}\
																if(((0x6F) <= (ucV1)) && ((ucV1) < (0x8F)))\
																{\
																	ucKeyState |= _RIGHT_KEY_MASK;\
																}\
																if(((0x6F) <= (ucV2)) && ((ucV2) < (0x8F)))\
																{\
																	ucKeyState |= _MENU_KEY_MASK ;\
																}\
																if(((0x9D) <= (ucV1)) && ((ucV1) < (0xBD)))\
																{\
																	ucKeyState |=_LEFT_KEY_MASK ;\
																}\
																if(!bPOWER_KEY)\
																{\
																	ucKeyState |=_POWER_KEY_MASK ;\
																}\
															}

#else

// press: xB E8;	up: xB 78;	down: xB A8;	left: x9 80;	right: x9 A8;
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\
                                                        if(((0X00) <= (ucV1)) && ((ucV1) < (0X00+8)))\
                                                        {\
                                                            ucKeyState |= _MENU_KEY_MASK; \
                                                        }\
                                                        if(((0x00) <= (ucV2)) && ((ucV2) < 0x00+8))\
                                                        {\
                                                            (ucKeyState) |= _EXIT_KEY_MASK;\
                                                        }\
                                                        if(((0x80-8) <= (ucV1)) && ((ucV1) < (0x80+8)))\
                                                        {\
                                                            (ucKeyState) |= _LEFT_KEY_MASK;\
                                                        }\
                                                        if(((0xA8-8) <= (ucV1)) && ((ucV1) <= (0xA8+8)))\
                                                        {\
                                                            (ucKeyState) |= _RIGHT_KEY_MASK;\
                                                        }\
                                                        if(!bPOWER_KEY)\
                                                        {\
                                                            (ucKeyState) |= _POWER_KEY_MASK;\
                                                        }\
                                                    }

#endif



#if(_MPRT_SUPPORT == _ON)


	//////////////////
	// MPRT Macro //
	//////////////////
	
#define bMPRT_BOOST_PIN                  (MCU_EMPTY_PIN_ASSIGN_ADDRESS)//     (MCU_FE23_PORT83_PIN_REG) // Pin_200
#define PCB_BL_BOOST(x) 				{\
											bMPRT_BOOST_PIN = (x);\
										}
	
#define _MPRT_MBR_PWM                       0
#define _MPRT_MBR_TCON                      1
	
#define PCB_MPRT_TCON_PIN_SHARE_CONFIG(x){\
											if(x == _ON)\
											{\
												ScalerSetByte(0x1003, (BYTE)(8));\
											}\
											else\
											{\
												ScalerSetByte(0x1003, (BYTE)(1));\
											}\
										}

#define PCB_MPRT_TCON_ENABLE(x)             {\
												if(x == _ON)\
												{\
													ScalerTcon13Enable(_ENABLE);\
												}\
												else\
												{\
													ScalerTcon13Enable(_DISABLE);\
												}\
											}


#define PCB_MPRT_TCON_INVERTED_OUTPUT()         {\
													ScalerSetDataPortBit(0x15A3,  0x88, ~(_BIT6), _BIT6  );\
												}

#define PCB_MPRT_TCON_PWM_ADJUST()              {\
                                                 	ScalerTcon13Adjust(0x00, 0x1FFF, ( g_MPRTValue), GET_MDOMAIN_OUTPUT_VTOTAL());\
												}


                                                
#endif // End of #if(_PCB_TYPE == _RL6851_QA_76PIN_1A1DP)
#endif // End of #if(_PCB_TYPE == _RL6851_QA_76PIN_1A1DP)
