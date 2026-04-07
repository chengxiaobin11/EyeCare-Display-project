/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/
//----------------------------------------------------------------------------------------------------
// ID Code      : RL6463__76PIN__HKMRT2313E01__1A1H__LVDS.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------



#if(_PCB_TYPE == _RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)
	
	
///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------


#define _EXT_XTAL                               _XTAL14318K
	
#define   _PCB_DEBUG_DDC  						_DDC1



///////////////////////
// Input Port Config //
///////////////////////
	
	
//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
	
#if (_HDMI_24C02_SUPPORT)
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#else
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _A0_EMBEDDED_DDCRAM_MAX_SIZE                _EDID_SIZE_128
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE//_EDID_TABLE_LOCATION_PC99
#define _A0_PC99_EMBEDDED_EDID_TABLE            "./EDID/EdidVga/EDID_VGA_1920x1200@60.h"
#endif
	
//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#if 0//(_HDMI_24C02_SUPPORT)
#define _D0_INPUT_PORT_TYPE                     _D0_HDMI_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE           _EDID_SIZE_NONE// _EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION           _EDID_TABLE_LOCATION_USER// _EDID_TABLE_LOCATION_CODE
	
#else
	
#define _D0_INPUT_PORT_TYPE                     _D0_NO_PORT//_D0_DP_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0//_DDC1
#define _D0_EMBEDDED_DDCRAM_MAX_SIZE                _EDID_SIZE_NONE//_EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
//#define _D0_DP_LINK_CLK_RATE					  _DP_HIGH_SPEED_270MHZ
//#define _D0_DP_MAIN_LINK_LANES				  _DP_FOUR_LANE
#endif
//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#if (_HDMI_24C02_SUPPORT)
#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE           _EDID_SIZE_NONE// _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION           _EDID_TABLE_LOCATION_USER// _EDID_TABLE_LOCATION_CODE
	
#else
	
#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_MAX_SIZE            _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
	//#define _D1_PC99_EMBEDDED_EDID_TABLE			  "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
	
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
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_AB
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
	
	//--------------------------------------------------
	// LVDS Driving Config
	//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE
	
	//--------------------------------------------------
	// LVDS SSC Config
	//--------------------------------------------------
#define _LVDS_SPREAD_RANGE                      10
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
#define _AUDIO_VOLUMN_PWM					    _NO_PWM//	_PWM1
#define _AUDIO_VOLUMN_PWM_INVERSE				_OFF
	
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
	
#define _PWM0_RST_BY_DVS                        _ON
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF
#define _PWM_RST_BY_TCON                        _OFF
	
	
	/////////////////
	// SW & HW IIC //
	/////////////////
	
	//--------------------------------------------------
	// Sofware and Hardware IIC Option
	//--------------------------------------------------
#if(_HDMI_24C02_SUPPORT)
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _OFF
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K
#else
#define _SW_IIC_SUPPORT                         _OFF
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K
#endif

	
	
	///////////////////
	// System Eeprom //
	///////////////////
	
	//--------------------------------------------------
	// Eeprom System Data Storage Option
	//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#if(_HDMI_24C02_SUPPORT)
#define _PCB_SYS_EEPROM_IIC                  	_SW_IIC_PIN_GPIO//_NO_IIC_PIN//   _HW_IIC_76PIN_31_32
#else
#define _PCB_SYS_EEPROM_IIC                  	_HW_IIC_76PIN_31_32
#endif

	
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


#define _RELEASE_KEY_MASK        	0x00

	
	//////////////////////
	// Series Pin Share //
	//////////////////////
//#include "RL6463__76PIN__HKMRT2313E01__1A1H_PINSHARE.h"
//---------------------------------------------------------------------------
// PCB Rule Select
//---------------------------------------------------------------------------
#define _PCB_NEW_MODE_SUPPORT                   _ON


////////////////////////////////
// RL6463 Series 76 Pin Share //
////////////////////////////////

//---------------------------------------------------------------------------
// Function : ADJBACKLITE
// Pinshare : 0x1002
// MCU Ctrl : 0xFFE2[2] at _76PIN_PIN_21_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_21                           (_76PIN_PIN_21_PWM0_PP)

typedef enum
{
    _76PIN_PIN_21_GPI = 0x00,
    _76PIN_PIN_21_GPO_PP = 0x01,
    _76PIN_PIN_21_GPO_OD = 0x02,
    _76PIN_PIN_21_PWM0_PP = 0x03,
    _76PIN_PIN_21_PWM0_OD = 0x04,
    _76PIN_PIN_21_MCK = 0x05,
    _76PIN_PIN_21_CLKO = 0x06,
    _76PIN_PIN_21_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_21_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_21_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_21_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_21_NC = _76PIN_PIN_21_GPO_PP,
} EnumPinshareInfo76PIN_PIN_21;

//---------------------------------------------------------------------------
// Function : onBACKLITE
// Pinshare : 0x1003
// MCU Ctrl : 0xFFE2[3] at _76PIN_PIN_22_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_22                         (_76PIN_PIN_22_GPO_PP) // (_76PIN_PIN_22_GPO_OD)

typedef enum
{
    _76PIN_PIN_22_GPI = 0x00,
    _76PIN_PIN_22_GPO_PP = 0x01,
    _76PIN_PIN_22_GPO_OD = 0x02,
    _76PIN_PIN_22_PWM1_PP = 0x03,
    _76PIN_PIN_22_PWM1_OD = 0x04,
    _76PIN_PIN_22_SCK = 0x05,
    _76PIN_PIN_22_IRQB = 0x06,
    _76PIN_PIN_22_TCON13 = 0x07,
    _76PIN_PIN_22_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_22_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_22_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_22_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_22_NC = _76PIN_PIN_22_GPO_PP,
} EnumPinshareInfo76PIN_PIN_22;

//---------------------------------------------------------------------------
// Function : VGA_CABLE_DET
// Pinshare : 0x1004
// MCU Ctrl : 0xFFE2[4] at _76PIN_PIN_23_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_23                           (_76PIN_PIN_23_GPI)

typedef enum
{
    _76PIN_PIN_23_GPI = 0x00,
    _76PIN_PIN_23_GPO_PP = 0x01,
    _76PIN_PIN_23_GPO_OD = 0x02,
    _76PIN_PIN_23_PWM2_PP = 0x03,
    _76PIN_PIN_23_PWM2_OD = 0x04,
    _76PIN_PIN_23_WS = 0x05,
    _76PIN_PIN_23_TCON13 = 0x06,
    _76PIN_PIN_23_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_23_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_23_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_23_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_23_NC = _76PIN_PIN_23_GPO_PP,
} EnumPinshareInfo76PIN_PIN_23;

//---------------------------------------------------------------------------
// Function : HDMI_CABLE_DET
// Pinshare : 0x1005
// MCU Ctrl : 0xFFE2[5] at _76PIN_PIN_24_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_24                           (_76PIN_PIN_24_GPI)

typedef enum
{
    _76PIN_PIN_24_GPI = 0x00,
    _76PIN_PIN_24_GPO_PP = 0x01,
    _76PIN_PIN_24_GPO_OD = 0x02,
    _76PIN_PIN_24_PWM3_PP = 0x03,
    _76PIN_PIN_24_PWM3_OD = 0x04,
    _76PIN_PIN_24_SD0 = 0x05,
    _76PIN_PIN_24_SPDIF0 = 0x06,
    _76PIN_PIN_24_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_24_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_24_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_24_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_24_IICSCL0 = 0x40,
    _76PIN_PIN_24_RXD0 = 0x80,
    _76PIN_PIN_24_NC = _76PIN_PIN_24_GPO_PP,
} EnumPinshareInfo76PIN_PIN_24;

//---------------------------------------------------------------------------
// Function : ADC_KEY1
// Pinshare : 0x1008
// MCU Ctrl : 0xFFE3[0] at _76PIN_PIN_27_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_27                           (_76PIN_PIN_27_A_ADC0)

typedef enum
{
    _76PIN_PIN_27_GPI = 0x00,
    _76PIN_PIN_27_GPO_PP = 0x01,
    _76PIN_PIN_27_GPO_OD = 0x02,
    _76PIN_PIN_27_A_ADC0 = 0x03,
    _76PIN_PIN_27_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_27_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_27_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_27_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_27_NC = _76PIN_PIN_27_GPO_PP,
} EnumPinshareInfo76PIN_PIN_27;

//---------------------------------------------------------------------------
// Function : ADC_KEY2
// Pinshare : 0x1009
// MCU Ctrl : 0xFFE3[1] at _76PIN_PIN_28_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_28                           (_76PIN_PIN_28_A_ADC1)

typedef enum
{
    _76PIN_PIN_28_GPI = 0x00,
    _76PIN_PIN_28_GPO_PP = 0x01,
    _76PIN_PIN_28_GPO_OD = 0x02,
    _76PIN_PIN_28_A_ADC1 = 0x03,
    _76PIN_PIN_28_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_28_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_28_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_28_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_28_NC = _76PIN_PIN_28_GPO_PP,
} EnumPinshareInfo76PIN_PIN_28;

//---------------------------------------------------------------------------
// Function : EDID_WP
// Pinshare : 0x100A
// MCU Ctrl : 0xFFE3[2] at _76PIN_PIN_29_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_29                           (_76PIN_PIN_29_GPO_OD)

typedef enum
{
    _76PIN_PIN_29_GPI = 0x00,
    _76PIN_PIN_29_GPO_PP = 0x01,
    _76PIN_PIN_29_GPO_OD = 0x02,
    _76PIN_PIN_29_A_ADC2 = 0x03,
    _76PIN_PIN_29_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_29_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_29_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_29_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_29_NC = _76PIN_PIN_29_GPO_PP,
} EnumPinshareInfo76PIN_PIN_29;

//---------------------------------------------------------------------------
// Function : EEPROM_WP
// Pinshare : 0x100C
// MCU Ctrl : 0xFFE3[4] at _76PIN_PIN_30_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_30                           (_76PIN_PIN_30_GPO_OD)//  (_76PIN_PIN_30_GPO_OD)

typedef enum
{
    _76PIN_PIN_30_GPI = 0x00,
    _76PIN_PIN_30_GPO_PP = 0x01,
    _76PIN_PIN_30_GPO_OD = 0x02,
    _76PIN_PIN_30_PWM1_PP = 0x03,
    _76PIN_PIN_30_PWM1_OD = 0x04,
    _76PIN_PIN_30_TCON7 = 0x05,
    _76PIN_PIN_30_TCON13 = 0x06,
    _76PIN_PIN_30_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_30_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_30_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_30_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_30_NC = _76PIN_PIN_30_GPO_PP,
} EnumPinshareInfo76PIN_PIN_30;

//---------------------------------------------------------------------------
// Function : UPP
// Pinshare : 0x100D
// MCU Ctrl : 0xFFE3[5] at _76PIN_PIN_31_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_31                           (_76PIN_PIN_31_GPI)

typedef enum
{
    _76PIN_PIN_31_GPI = 0x00,
    _76PIN_PIN_31_GPO_PP = 0x01,
    _76PIN_PIN_31_GPO_OD = 0x02,
    _76PIN_PIN_31_TCON8 = 0x03,
    _76PIN_PIN_31_TCON12 = 0x04,
    _76PIN_PIN_31_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_31_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_31_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_31_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_31_IICSCL1 = 0x40,
    _76PIN_PIN_31_IICSCL_AUX = 0x80,
    _76PIN_PIN_31_NC = _76PIN_PIN_31_GPO_PP,
} EnumPinshareInfo76PIN_PIN_31;

//---------------------------------------------------------------------------
// Function : MENUU
// Pinshare : 0x100E
// MCU Ctrl : 0xFFE3[6] at _76PIN_PIN_32_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_32                           (_76PIN_PIN_32_GPI)

typedef enum
{
    _76PIN_PIN_32_GPI = 0x00,
    _76PIN_PIN_32_GPO_PP = 0x01,
    _76PIN_PIN_32_GPO_OD = 0x02,
    _76PIN_PIN_32_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_32_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_32_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_32_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_32_IICSDA1 = 0x40,
    _76PIN_PIN_32_IICSDA_AUX = 0x80,
    _76PIN_PIN_32_NC = _76PIN_PIN_32_GPO_PP,
} EnumPinshareInfo76PIN_PIN_32;

//---------------------------------------------------------------------------
// Function : --
// Pinshare : 0x100F
// MCU Ctrl : 0xFFE3[7] at _76PIN_PIN_33_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_33                           (_76PIN_PIN_33_GPI)

typedef enum
{
    _76PIN_PIN_33_GPI = 0x40,
    _76PIN_PIN_33_GPO_PP = 0x41,
    _76PIN_PIN_33_GPO_OD = 0x42,
    _76PIN_PIN_33_TEST4B_OUT0 = 0x4C,
    _76PIN_PIN_33_TEST4B_OUT1 = 0x4D,
    _76PIN_PIN_33_TEST4B_OUT2 = 0x4E,
    _76PIN_PIN_33_TEST4B_OUT3 = 0x4F,
    _76PIN_PIN_33_DDCSCLVGA0 = 0x00,
    _76PIN_PIN_33_DDCCSL_MUX_SWAP_PIN_43 = 0x20,
    _76PIN_PIN_33_RXD1 = 0x80,
    _76PIN_PIN_33_NC = _76PIN_PIN_33_GPO_PP,
} EnumPinshareInfo76PIN_PIN_33;

//---------------------------------------------------------------------------
// Function : ++
// Pinshare : 0x1010
// MCU Ctrl : 0xFE00 at _76PIN_PIN_34_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_34                           (_76PIN_PIN_34_GPI)

typedef enum
{
    _76PIN_PIN_34_GPI = 0x00,
    _76PIN_PIN_34_GPO_PP = 0x01,
    _76PIN_PIN_34_GPO_OD = 0x02,
    _76PIN_PIN_34_TCON11 = 0x03,
    _76PIN_PIN_34_TCON13 = 0x04,
    _76PIN_PIN_34_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_34_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_34_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_34_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_34_DDCSDAVGA0 = 0x00,
    _76PIN_PIN_34_DDCSDA_MUX_SWAP_PIN_44 = 0x20,
    _76PIN_PIN_34_TXD1 = 0x80,
    _76PIN_PIN_34_NC = _76PIN_PIN_34_GPO_PP,
} EnumPinshareInfo76PIN_PIN_34;

//---------------------------------------------------------------------------
// Function : HDMI_HPD_0
// Pinshare : 0x1012
// MCU Ctrl : 0xFE02 at _76PIN_PIN_36_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_36                           (_76PIN_PIN_36_GPO_OD)

typedef enum
{
    _76PIN_PIN_36_GPI = 0x00,
    _76PIN_PIN_36_GPO_PP = 0x01,
    _76PIN_PIN_36_GPO_OD = 0x02,
    _76PIN_PIN_36_PWM3_PP = 0x03,
    _76PIN_PIN_36_PWM3_OD = 0x04,
    _76PIN_PIN_36_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_36_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_36_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_36_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_36_NC = _76PIN_PIN_36_GPO_PP,
} EnumPinshareInfo76PIN_PIN_36;

//---------------------------------------------------------------------------
// Function : LED_G
// Pinshare : 0x101A
// MCU Ctrl : 0xFE0A at _76PIN_PIN_37_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_37                           (_76PIN_PIN_37_NC)

typedef enum
{
    _76PIN_PIN_37_GPI = 0x00,
    _76PIN_PIN_37_GPO_PP = 0x01,
    _76PIN_PIN_37_GPO_OD = 0x02,
    _76PIN_PIN_37_PWM0_PP = 0x03,
    _76PIN_PIN_37_PWM0_OD = 0x04,
    _76PIN_PIN_37_PWM3_PP = 0x05,
    _76PIN_PIN_37_PWM3_OD = 0x06,
    _76PIN_PIN_37_TCON7 = 0x07,
    _76PIN_PIN_37_INT1 = 0x08,
    _76PIN_PIN_37_T2 = 0x09,
    _76PIN_PIN_37_IHS_AFTER_SCALING_DOWN = 0x0A,
    _76PIN_PIN_37_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_37_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_37_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_37_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_37_NC = _76PIN_PIN_37_GPO_PP,
} EnumPinshareInfo76PIN_PIN_37;

//---------------------------------------------------------------------------
// Function : LED_B
// Pinshare : 0x101B
// MCU Ctrl : 0xFE0B at _76PIN_PIN_38_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_38                           (_76PIN_PIN_38_GPO_PP)

typedef enum
{
    _76PIN_PIN_38_GPI = 0x00,
    _76PIN_PIN_38_GPO_PP = 0x01,
    _76PIN_PIN_38_GPO_OD = 0x02,
    _76PIN_PIN_38_PWM2_PP = 0x03,
    _76PIN_PIN_38_PWM2_OD = 0x04,
    _76PIN_PIN_38_TCON8 = 0x05,
    _76PIN_PIN_38_INT0 = 0x06,
    _76PIN_PIN_38_IENA_AFTER_SCALING_DOWN = 0x08,
    _76PIN_PIN_38_CLKO = 0x09,
    _76PIN_PIN_38_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_38_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_38_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_38_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_38_NC = _76PIN_PIN_38_GPO_PP,
} EnumPinshareInfo76PIN_PIN_38;

//---------------------------------------------------------------------------
// Function : TXD3P
// Pinshare : 0x101D
// MCU Ctrl : 0xFE0D at _76PIN_PIN_39_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_39_OFF_REGION                (_76PIN_PIN_39_TXO3P_8B)

typedef enum
{
    _76PIN_PIN_39_HI_Z = 0x00,
    _76PIN_PIN_39_GPI = 0x01,
    _76PIN_PIN_39_GPO_PP = 0x02,
    _76PIN_PIN_39_GPO_OD = 0x03,
    _76PIN_PIN_39_TXO3P_8B = 0x04,
    _76PIN_PIN_39_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_39_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_39_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_39_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_39_NC = _76PIN_PIN_39_GPO_PP,
} EnumPinshareInfo76PIN_PIN_39;

//---------------------------------------------------------------------------
// Function : TXD3N
// Pinshare : 0x101E
// MCU Ctrl : 0xFE0E at _76PIN_PIN_40_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_40_OFF_REGION                (_76PIN_PIN_40_TXO3N_8B)

typedef enum
{
    _76PIN_PIN_40_HI_Z = 0x00,
    _76PIN_PIN_40_GPI = 0x01,
    _76PIN_PIN_40_GPO_PP = 0x02,
    _76PIN_PIN_40_GPO_OD = 0x03,
    _76PIN_PIN_40_TXO3N_8B = 0x04,
    _76PIN_PIN_40_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_40_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_40_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_40_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_40_NC = _76PIN_PIN_40_GPO_PP,
} EnumPinshareInfo76PIN_PIN_40;

//---------------------------------------------------------------------------
// Function : TXD2P
// Pinshare : 0x101F
// MCU Ctrl : 0xFE0F at _76PIN_PIN_41_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_41_OFF_REGION                (_76PIN_PIN_41_TXO2P_8B)

typedef enum
{
    _76PIN_PIN_41_HI_Z = 0x00,
    _76PIN_PIN_41_GPI = 0x01,
    _76PIN_PIN_41_GPO_PP = 0x02,
    _76PIN_PIN_41_GPO_OD = 0x03,
    _76PIN_PIN_41_TXO2P_8B = 0x04,
    _76PIN_PIN_41_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_41_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_41_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_41_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_41_NC = _76PIN_PIN_41_GPO_PP,
} EnumPinshareInfo76PIN_PIN_41;

//---------------------------------------------------------------------------
// Function : TXD2N
// Pinshare : 0x1020
// MCU Ctrl : 0xFE10 at _76PIN_PIN_42_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_42_OFF_REGION                (_76PIN_PIN_42_TXO2N_8B)

typedef enum
{
    _76PIN_PIN_42_HI_Z = 0x00,
    _76PIN_PIN_42_GPI = 0x01,
    _76PIN_PIN_42_GPO_PP = 0x02,
    _76PIN_PIN_42_GPO_OD = 0x03,
    _76PIN_PIN_42_TXO2N_8B = 0x04,
    _76PIN_PIN_42_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_42_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_42_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_42_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_42_NC = _76PIN_PIN_42_GPO_PP,
} EnumPinshareInfo76PIN_PIN_42;

//---------------------------------------------------------------------------
// Function : TXD1P
// Pinshare : 0x1021
// MCU Ctrl : 0xFE11 at _76PIN_PIN_43_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_43_OFF_REGION                (_76PIN_PIN_43_TXO1P_8B)

typedef enum
{
    _76PIN_PIN_43_HI_Z = 0x00,
    _76PIN_PIN_43_GPI = 0x01,
    _76PIN_PIN_43_GPO_PP = 0x02,
    _76PIN_PIN_43_GPO_OD = 0x03,
    _76PIN_PIN_43_TXO1P_8B = 0x04,
    _76PIN_PIN_43_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_43_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_43_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_43_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_43_NC = _76PIN_PIN_43_GPO_PP,
} EnumPinshareInfo76PIN_PIN_43;

//---------------------------------------------------------------------------
// Function : TXD1N
// Pinshare : 0x1022
// MCU Ctrl : 0xFE12 at _76PIN_PIN_44_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_44_OFF_REGION                (_76PIN_PIN_44_TXO1N_8B)

typedef enum
{
    _76PIN_PIN_44_HI_Z = 0x00,
    _76PIN_PIN_44_GPI = 0x01,
    _76PIN_PIN_44_GPO_PP = 0x02,
    _76PIN_PIN_44_GPO_OD = 0x03,
    _76PIN_PIN_44_TXO1N_8B = 0x04,
    _76PIN_PIN_44_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_44_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_44_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_44_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_44_NC = _76PIN_PIN_44_GPO_PP,
} EnumPinshareInfo76PIN_PIN_44;

//---------------------------------------------------------------------------
// Function : TXD0P
// Pinshare : 0x1023
// MCU Ctrl : 0xFE13 at _76PIN_PIN_45_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_45_OFF_REGION                (_76PIN_PIN_45_TXO0P_8B)

typedef enum
{
    _76PIN_PIN_45_HI_Z = 0x00,
    _76PIN_PIN_45_GPI = 0x01,
    _76PIN_PIN_45_GPO_PP = 0x02,
    _76PIN_PIN_45_GPO_OD = 0x03,
    _76PIN_PIN_45_TXO0P_8B = 0x04,
    _76PIN_PIN_45_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_45_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_45_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_45_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_45_NC = _76PIN_PIN_45_GPO_PP,
} EnumPinshareInfo76PIN_PIN_45;

//---------------------------------------------------------------------------
// Function : TXD0N
// Pinshare : 0x1024
// MCU Ctrl : 0xFE14 at _76PIN_PIN_46_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_46_OFF_REGION                (_76PIN_PIN_46_TXO0N_8B)

typedef enum
{
    _76PIN_PIN_46_HI_Z = 0x00,
    _76PIN_PIN_46_GPI = 0x01,
    _76PIN_PIN_46_GPO_PP = 0x02,
    _76PIN_PIN_46_GPO_OD = 0x03,
    _76PIN_PIN_46_TXO0N_8B = 0x04,
    _76PIN_PIN_46_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_46_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_46_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_46_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_46_NC = _76PIN_PIN_46_GPO_PP,
} EnumPinshareInfo76PIN_PIN_46;

//---------------------------------------------------------------------------
// Function : FLASH_WP
// Pinshare : 0x102A
// MCU Ctrl : 0xFE1A at _76PIN_PIN_58_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_58                           (_76PIN_PIN_58_GPO_PP)

typedef enum
{
    _76PIN_PIN_58_GPI = 0x00,
    _76PIN_PIN_58_GPO_PP = 0x01,
    _76PIN_PIN_58_GPO_OD = 0x02,
    _76PIN_PIN_58_INT0 = 0x03,
    _76PIN_PIN_58_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_58_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_58_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_58_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_58_NC = _76PIN_PIN_58_GPO_PP,
} EnumPinshareInfo76PIN_PIN_58;

//---------------------------------------------------------------------------
// Function : Panel_ON
// Pinshare : 0x102B
// MCU Ctrl : 0xFE1B at _76PIN_PIN_59_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_59                           (_76PIN_PIN_59_GPO_PP)

typedef enum
{
    _76PIN_PIN_59_GPI = 0x00,
    _76PIN_PIN_59_GPO_PP = 0x01,
    _76PIN_PIN_59_GPO_OD = 0x02,
    _76PIN_PIN_59_INT1 = 0x03,
    _76PIN_PIN_59_TCON11 = 0x04,
    _76PIN_PIN_59_IVS_AFTER_SCALING_DOWN = 0x06,
    _76PIN_PIN_59_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_59_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_59_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_59_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_59_NC = _76PIN_PIN_59_GPO_PP,
} EnumPinshareInfo76PIN_PIN_59;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102C
// MCU Ctrl : 0xFE1C at _76PIN_PIN_60_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_60                 (_76PIN_PIN_60_GPO_PP)

typedef enum
{
    _76PIN_PIN_60_GPI = 0x00,
    _76PIN_PIN_60_GPO_PP = 0x01,
    _76PIN_PIN_60_GPO_OD = 0x02,
    _76PIN_PIN_60_T0 = 0x03,
    _76PIN_PIN_60_DENA = 0x04,
    _76PIN_PIN_60_TCON9 = 0x05,
    _76PIN_PIN_60_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_60_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_60_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_60_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_60_NC = _76PIN_PIN_60_GPO_PP,
} EnumPinshareInfo76PIN_PIN_60;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x102D
// MCU Ctrl : 0xFE1D at _76PIN_PIN_61_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_61                         (_76PIN_PIN_61_GPO_PP)

typedef enum
{
    _76PIN_PIN_61_GPI = 0x00,
    _76PIN_PIN_61_GPO_PP = 0x01,
    _76PIN_PIN_61_GPO_OD = 0x02,
    _76PIN_PIN_61_PWM2_PP = 0x03,
    _76PIN_PIN_61_PWM2_OD = 0x04,
    _76PIN_PIN_61_PWM3_PP = 0x05,
    _76PIN_PIN_61_PWM3_OD = 0x06,
    _76PIN_PIN_61_T1 = 0x07,
    _76PIN_PIN_61_DHS = 0x08,
    _76PIN_PIN_61_TCON13 = 0x09,
    _76PIN_PIN_61_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_61_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_61_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_61_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_61_NC = _76PIN_PIN_61_GPO_PP,
} EnumPinshareInfo76PIN_PIN_61;

//---------------------------------------------------------------------------
// Function : DDCSCL_VGA
// Pinshare : 0x102E
// MCU Ctrl : 0xFE1E at _76PIN_PIN_62_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_62                           (_76PIN_PIN_62_DDCSCLVGA1)

typedef enum
{
    _76PIN_PIN_62_GPI = 0x80,
    _76PIN_PIN_62_GPO_PP = 0x81,
    _76PIN_PIN_62_GPO_OD = 0x82,
    _76PIN_PIN_62_AUX_D2 = 0x83,
    _76PIN_PIN_62_DCLK = 0x84,
    _76PIN_PIN_62_TCON8 = 0x85,
    _76PIN_PIN_62_PWM_IN = 0x86,
    _76PIN_PIN_62_T2EX = 0x87,
    _76PIN_PIN_62_TEST4B_OUT0 = 0x8C,
    _76PIN_PIN_62_TEST4B_OUT1 = 0x8D,
    _76PIN_PIN_62_TEST4B_OUT2 = 0x8E,
    _76PIN_PIN_62_TEST4B_OUT3 = 0x8F,
    _76PIN_PIN_62_DDCSCLVGA1 = 0x00,
    _76PIN_PIN_62_NC = _76PIN_PIN_62_GPO_PP,
} EnumPinshareInfo76PIN_PIN_62;

//---------------------------------------------------------------------------
// Function : DDCSDA_VGA
// Pinshare : 0x102F
// MCU Ctrl : 0xFE1F at _76PIN_PIN_63_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_63                           (_76PIN_PIN_63_DDCSDAVGA1)

typedef enum
{
    _76PIN_PIN_63_GPI = 0x00,
    _76PIN_PIN_63_GPO_PP = 0x01,
    _76PIN_PIN_63_GPO_OD = 0x02,
    _76PIN_PIN_63_AUX_D1 = 0x03,
    _76PIN_PIN_63_DVS = 0x04,
    _76PIN_PIN_63_TCON7 = 0x05,
    _76PIN_PIN_63_PWM_OUT = 0x06,
    _76PIN_PIN_63_PWM1_PP = 0x07,
    _76PIN_PIN_63_PWM1_OD = 0x08,
    _76PIN_PIN_63_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_63_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_63_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_63_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_63_DDCSDAVGA1 = 0x00,
    _76PIN_PIN_63_NC = _76PIN_PIN_63_GPO_PP,
} EnumPinshareInfo76PIN_PIN_63;

//---------------------------------------------------------------------------
// Function : DDCSCL_1
// Pinshare : 0x1034
// MCU Ctrl : 0xFE24 at _76PIN_PIN_70_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_70                           (_76PIN_PIN_70_DDCSCL1)

typedef enum
{
    _76PIN_PIN_70_GPI = 0x80,
    _76PIN_PIN_70_GPO_PP = 0x81,
    _76PIN_PIN_70_GPO_OD = 0x82,
    _76PIN_PIN_70_AUXP1 = 0x83,
    _76PIN_PIN_70_TEST4B_OUT0 = 0x8C,
    _76PIN_PIN_70_TEST4B_OUT1 = 0x8D,
    _76PIN_PIN_70_TEST4B_OUT2 = 0x8E,
    _76PIN_PIN_70_TEST4B_OUT3 = 0x8F,
    _76PIN_PIN_70_DDCSCL1 = 0x00,
    _76PIN_PIN_70_NC = _76PIN_PIN_70_GPO_PP,
} EnumPinshareInfo76PIN_PIN_70;

//---------------------------------------------------------------------------
// Function : DDCSDA_1
// Pinshare : 0x1035
// MCU Ctrl : 0xFE25 at _76PIN_PIN_71_MCU_REG
//---------------------------------------------------------------------------
#define _76PIN_PIN_71                           (_76PIN_PIN_71_DDCSDA1)

typedef enum
{
    _76PIN_PIN_71_GPI = 0x00,
    _76PIN_PIN_71_GPO_PP = 0x01,
    _76PIN_PIN_71_GPO_OD = 0x02,
    _76PIN_PIN_71_AUXN1 = 0x03,
    _76PIN_PIN_71_TEST4B_OUT0 = 0x0C,
    _76PIN_PIN_71_TEST4B_OUT1 = 0x0D,
    _76PIN_PIN_71_TEST4B_OUT2 = 0x0E,
    _76PIN_PIN_71_TEST4B_OUT3 = 0x0F,
    _76PIN_PIN_71_DDCSDA1 = 0x00,
    _76PIN_PIN_71_NC = _76PIN_PIN_71_GPO_PP,
} EnumPinshareInfo76PIN_PIN_71;

	
#if(_HDMI_24C02_SUPPORT)
				
		
				
				//HDMI1
			//sbit bDDC1IICSCL							_76PIN_PIN_70;//  =P3^2; // _76PIN_PIN_70, //	  =P3^2; // _156PIN_PIN_137, 
			//sbit bDDC1IICSDA							_76PIN_PIN_71;//=P3^3; // _76PIN_PIN_71,//	=P3^3; // _156PIN_PIN_138,
		//	#define bDDC1IICSCL 						_76PIN_PIN_70;			//	=P3^2; // _76PIN_PIN_70, //   =P3^2; // _156PIN_PIN_137, 
		//	#define bDDC1IICSDA 						_76PIN_PIN_71;		//=P3^3; // _76PIN_PIN_71,//  =P3^3; // _156PIN_PIN_138,
				
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
			
#define bPANELI2CSDA                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bPANELI2CSCL                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
			
#define bDDC1IICSCL 							(_76PIN_PIN_70_MCU_REG)
#define bDDC1IICSDA 							(_76PIN_PIN_71_MCU_REG)
			
#define bDDCVGAIICSCL                           (_76PIN_PIN_62_MCU_REG)
#define bDDCVGAIICSDA                           (_76PIN_PIN_63_MCU_REG)
		
				
				
#define PCB_SW_IIC_SDA_SET()                    {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																bDDCVGAIICSDA = _TRUE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																bDDC1IICSDA = _TRUE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																bPANELI2CSDA = _TRUE;						\
															}												\
														}
#define PCB_SW_IIC_SDA_CLR()                    {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																bDDCVGAIICSDA = _FALSE; 					\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																bDDC1IICSDA = _FALSE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																bPANELI2CSDA = _FALSE;						\
															}												\
														}
#define PCB_SW_IIC_SDA_CHK(x)                   {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																(x) = bDDCVGAIICSDA;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																(x) = bDDC1IICSDA;							\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																(x) = bPANELI2CSDA; 						\
															}												\
														}
#define PCB_SW_IIC_SCL_SET()                    {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																bDDCVGAIICSCL = _TRUE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																bDDC1IICSCL = _TRUE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																bPANELI2CSCL = _TRUE;						\
															}												\
														}
#define PCB_SW_IIC_SCL_CLR()                    {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																bDDCVGAIICSCL = _FALSE; 					\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																bDDC1IICSCL = _FALSE;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																bPANELI2CSCL = _FALSE;						\
															}												\
														}
#define PCB_SW_IIC_SCL_CHK(x)                   {\
															if(GET_SW_IIC_STATUS() == _IIC_VGA_DDC) 		\
															{												\
																(x) = bDDCVGAIICSCL;						\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_DDC1)	\
															{												\
																(x) = bDDC1IICSCL;							\
															}												\
															else if(GET_SW_IIC_STATUS() == _IIC_FOR_VCOM)	\
															{												\
																(x) = bPANELI2CSCL; 						\
															}												\
														}
		
				
				
#endif
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
	
#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_ON)
	
	
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
	
#define PCB_BACKLIGHT_POWER_PIN(x)              {\
														bBACKLIGHTPOWER = (x);\
													}
	
#define PCB_BACKLIGHT_POWER(x)                  {\
														if((x) == _LIGHT_CONTROL_ON)\
														{\
															ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
															ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM,25000 );\	
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
	
	//-----------------------------------------------
	// Macro of Input Cable Connect
	//-----------------------------------------------
#define bA0_CONNECT                             (_76PIN_PIN_23_MCU_REG)
#define bD1_CONNECT                             (_76PIN_PIN_24_MCU_REG)
	
#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
	
	//-----------------------------------------------
	// Macro of DP Source Power
	//-----------------------------------------------
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)
	
	
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


#define bPCB_HP_SENSE_DETECT                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)//(_PIN_52_MCU_REG)     
	
#define _HP_CONNECTED            				0//1
#define _HP_DISCONNECTED         				1//0
	
#define PCB_EARPHONE_CONNECTED()      			(bPCB_HP_SENSE_DETECT == _HP_CONNECTED)
#define PCB_EARPHONE_DISCONNECTED()   			(bPCB_HP_SENSE_DETECT == _HP_DISCONNECTED)

	
	///////////////
	// LED Macro //
	///////////////
	
	//--------------------------------------------------
	// Macro of LED On/Off
	//--------------------------------------------------
#define bLED1                                   (_76PIN_PIN_37_MCU_REG)//FE0A 0 - Orange 
#define bLED2                                   (_76PIN_PIN_38_MCU_REG)//FE0B 0 - blue


#define _LED_ON                                 0
#define _LED_OFF                                1


#define PCB_LED_AC_ON_INITIAL()                 {\
														bLED1 = _LED_OFF;\
														bLED2 = _LED_ON;\
													}
	
#define PCB_LED_ACTIVE()                        {\
														bLED1 = _LED_OFF;\
														bLED2 = _LED_ON;\
													}
	
#define PCB_LED_IDLE()                          {\
														bLED1 = _LED_OFF;\
														bLED2 = _LED_ON;\
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
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT)
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT)
	
#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)
	

#define  bPOWER_KEY                          (_76PIN_PIN_29_MCU_REG)
#define  MENU_KEY                            (_76PIN_PIN_31_MCU_REG)
#define  LEFT_KEY                            (_76PIN_PIN_32_MCU_REG)






#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\       
																	if(((0x00) <= (ucV2)) && ((ucV2) < (0x10)))\
																	{\
																		(ucKeyState) |= _EXIT_KEY_MASK;\
																	}\
																	if(((0x00) <= (ucV1)) && ((ucV1) < (0x10)))\
																	{\
																		(ucKeyState) |= _RIGHT_KEY_MASK;\
																	}\
															    	if(!MENU_KEY)\
																	{\
																		(ucKeyState) |= _MENU_KEY_MASK;\
																	}\
																	if(!LEFT_KEY)\
																	{\
																		(ucKeyState) |= _LEFT_KEY_MASK;\
																	}\
																	if(!bPOWER_KEY)\
																	{\
																		(ucKeyState) |= _POWER_KEY_MASK;\
																	}\
															}




// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio Connect
//-----------------------------------------------
#define bAUDIODETECT                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
//WZP¼ÓµÄ
#define _AUDIO_CONNECT                          0
#define _AUDIO_DISCONNECT                       1

#define PCB_AUDIO_DETECT()                      (bAUDIODETECT)

#define bHeadphoneDetect                        (_PIN_53_MCU_REG)

#define _HEADPHONE_CONNECT                      1
#define _HEADPHONE_DISCONNECT                   0


#define PCB_HEADPHONE_DETECT()                  (bHeadphoneDetect) 



//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#define bPCBAMPMUTECONTROL                      (_PIN_65_MCU_REG)

#define _AMP_MUTE_ON                            1
#define _AMP_MUTE_OFF                           0

#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = (x);\
                                                }


#define _VOLUME_MAX                             255
#define _VOLUME_MIN                             0
#define _AUDIO_VOLUME_PWM_INVERSE				_OFF


#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)

#define PCB_AUDIO_VOLUME_PWM(x)                 {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM, (x));\
                                                }

#define PCB_GET_AUDIO_VOLUME_PWM()              (MCU_GET_8BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM))

#endif


#if(_MPRT_SUPPORT == _ON)
//-----------------------------------------------
// Macro of MPRT CONTROL
//-----------------------------------------------
#define bMPRT_CURRENT_CONTROL                            (_76PIN_PIN_21_MCU_REG)	// Pin_21
													
#define _MPRT_CURRENT_SWITCH_ON                            1
#define _MPRT_CURRENT_SWITCH_OFF                           0

#define PCB_MPRT_CURRENT_CONTROL(x)                    {\
                                                                  bMPRT_CURRENT_CONTROL = (x);\
                                                }


#define PCB_MPRT_TCON_PIN_SHARE_CONFIG(x)       {\
													if(x == _ON)\
													{\
														ScalerSetByte(0x1003, (BYTE)(7));\
													}\
													else\
													{\
														ScalerSetByte(0X1003, (BYTE)(1));\
													}\
												}

#define PCB_MPRT_TCON_ENABLE(x)                 {\
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
													ScalerSetDataPortBit(0x15A3,  0xe8, ~(_BIT6), _BIT6  );\
												}


#define PCB_MPRT_TCON_PWM_ADJUST()              {\
                                                 	ScalerTcon13Adjust(0x00, 0x1FFF, ( g_MPRTValue), GET_MDOMAIN_OUTPUT_VTOTAL());\
												}


#define bMPRT_CONTROL                            (_76PIN_PIN_22_MCU_REG)	// Pin_22
#define _MPRT_GPIO_ON                            1
#define _MPRT_GPIO_OFF                           0
#define PCB_MPRT_GPIO_CONTROL(x)                    {\
                                                                  bMPRT_CONTROL = (x);\
                                                }
                                                



#endif



#endif

