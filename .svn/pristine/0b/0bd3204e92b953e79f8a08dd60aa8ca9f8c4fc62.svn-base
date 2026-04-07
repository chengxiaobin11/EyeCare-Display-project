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
// ID Code      : _RL6463__128PIN__HKMRT2513E01__1A1H__LVDS.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6463__128PIN__HKMRT2513E05__1A1H__LVDS)


#define _PCB_DEBUG_DDC                         	_VGA_DDC//_VGA_DDC//_DDC1

//#define _BURNIN_STR_IC_NAME                	 	_H__,_K__,_DOT__,_M__,_DOT__,_R__,_T__,_2__,_5__,_1__,_3__,_E__,_0__,_5__
//#define _MAIN_PAGE_MODEL_NAME               	_M__,_o__,_d__,_e__,_l__,__,_COLON__,__,_R__,_T__,_D__,_2__,_5__,_1__,_3__,_A__,_R__
//#define _MAIN_PAGE_MODEL_NAME               	_M__,_o__,_d__,_e__,_l__,__,_COLON__,__,_M__,_N__,_T__

///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K


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
//#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
//#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
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
//#define _D1_PC99_EMBEDDED_EDID_TABLE            "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"

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
/*  DR
#if(_PANEL_TYPE==_INL_M280DGJ_L30_LVDS_FHD_60HZ)
#define _LVDS_PORT_AB_SWAP           _ENABLE    //       _DISABLE
#elif(_PANEL_TYPE==_BOE_HV320FHB_N00_LVDS_FHD)
#define _LVDS_PORT_AB_SWAP            _ENABLE   //       _DISABLE
#elif(_PANEL_TYPE==_AUO_T320HVN05_4_LVDS_FHD)
#define _LVDS_PORT_AB_SWAP            _ENABLE   //       _DISABLE
#elif(_PANEL_TYPE==_BOE_ST3151B01_1_LVDS_FHD_75HZ)
#define _LVDS_PORT_AB_SWAP            _ENABLE   //       _DISABLE
#else
#define _LVDS_PORT_AB_SWAP            _DISABLE   //       _DISABLE
#endif
*/

#define _LVDS_PORT_AB_SWAP            _DISABLE   //       _DISABLE


#define _LVDS_PN_SWAP                 _DISABLE//

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL             _LVDS_DRIV_CONTROL_3_0//    _LVDS_DRIV_CONTROL_3_0  //   _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL              _LVDS_VCM_NORMAL//_LVDS_VCM_LOW//  //   _LVDS_VCM_NORMAL//    _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL               _LVDS_SR_CONTROL_0//    _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL     _LVDS_PRE_EMPHASIS_0//       _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL      _DISABLE

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------

#define _LVDS_SPREAD_RANGE                       0//10//     0//5//10   20211221
#define _LVDS_SPREAD_SPEED                      _SPEED_33K



/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM0
#define _BACKLIGHT_PWM_INVERSE                 	_OFF//_ON// 
#define _AUDIO_VOLUMN_PWM					    _NO_PWM//	_PWM1
#define _AUDIO_VOLUMN_PWM_INVERSE				_OFF

#define _PWM0_EN                                _ON
#define _PWM1_EN                          		_OFF//      _ON//_OFF
#define _PWM2_EN                                _OFF//_OFF
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

#define _PWM0_RST_BY_DVS                        _OFF
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
#define _SW_IIC_SUPPORT                         _ON//_OFF
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _OFF
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _SW_IIC_PIN_GPIO//_HW_IIC_PIN_47_48


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
//#include "RL6463__128PIN__HKMRT2513E03__1A1H_PINSHARE.h"

///////////////
// PCB Mode  //
///////////////

//---------------------------------------------------------------------------
// PCB Rule Select
//---------------------------------------------------------------------------
#define _PCB_NEW_MODE_SUPPORT                   _ON

#define _RELEASE_KEY_MASK        				0x00

/////////////////////////////////
// RL6463 Series 128 Pin Share //
/////////////////////////////////

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1000
// MCU Ctrl : 0xFFE2[0] at _PIN_21_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_21                                 (_PIN_21_NC)

typedef enum
{
    _PIN_21_GPI = 0x00,
    _PIN_21_GPO_PP = 0x01,
    _PIN_21_GPO_OD = 0x02,
    _PIN_21_TEST4B_OUT0 = 0x0C,
    _PIN_21_TEST4B_OUT1 = 0x0D,
    _PIN_21_TEST4B_OUT2 = 0x0E,
    _PIN_21_TEST4B_OUT3 = 0x0F,
    _PIN_21_NC = _PIN_21_GPO_PP,
} EnumPinshareInfoPIN21;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1001
// MCU Ctrl : 0xFFE2[1] at _PIN_22_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_22                                 (_PIN_22_GPO_OD)

typedef enum
{
    _PIN_22_GPI = 0x00,
    _PIN_22_GPO_PP = 0x01,
    _PIN_22_GPO_OD = 0x02,
    _PIN_22_TEST4B_OUT0 = 0x0C,
    _PIN_22_TEST4B_OUT1 = 0x0D,
    _PIN_22_TEST4B_OUT2 = 0x0E,
    _PIN_22_TEST4B_OUT3 = 0x0F,
    _PIN_22_NC = _PIN_22_GPO_PP,
} EnumPinshareInfoPIN22;

//---------------------------------------------------------------------------
// Function : ADJBACKLITE
// Pinshare : 0x1002
// MCU Ctrl : 0xFFE2[2] at _PIN_34_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_34                                 (_PIN_34_PWM0_PP)

typedef enum
{
    _PIN_34_GPI = 0x00,
    _PIN_34_GPO_PP = 0x01,
    _PIN_34_GPO_OD = 0x02,
    _PIN_34_PWM0_PP = 0x03,
    _PIN_34_PWM0_OD = 0x04,
    _PIN_34_MCK = 0x05,
    _PIN_34_CLKO = 0x06,
    _PIN_34_TEST4B_OUT0 = 0x0C,
    _PIN_34_TEST4B_OUT1 = 0x0D,
    _PIN_34_TEST4B_OUT2 = 0x0E,
    _PIN_34_TEST4B_OUT3 = 0x0F,
    _PIN_34_NC = _PIN_34_GPO_PP,
} EnumPinshareInfoPIN34;

//---------------------------------------------------------------------------
// Function : onBACKLITE
// Pinshare : 0x1003
// MCU Ctrl : 0xFFE2[3] at _PIN_35_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_35                                 (_PIN_35_GPO_PP)

typedef enum
{
    _PIN_35_GPI = 0x00,
    _PIN_35_GPO_PP = 0x01,
    _PIN_35_GPO_OD = 0x02,
    _PIN_35_PWM1_PP = 0x03,
    _PIN_35_PWM1_OD = 0x04,
    _PIN_35_SCK = 0x05,
    _PIN_35_IRQB = 0x06,
    _PIN_35_TCON13 = 0x07,
    _PIN_35_TEST4B_OUT0 = 0x0C,
    _PIN_35_TEST4B_OUT1 = 0x0D,
    _PIN_35_TEST4B_OUT2 = 0x0E,
    _PIN_35_TEST4B_OUT3 = 0x0F,
    _PIN_35_NC = _PIN_35_GPO_PP,
} EnumPinshareInfoPIN35;

//---------------------------------------------------------------------------
// Function : VGA_CABLE_DET
// Pinshare : 0x1004
// MCU Ctrl : 0xFFE2[4] at _PIN_36_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_36                                 (_PIN_36_GPI)

typedef enum
{
    _PIN_36_GPI = 0x00,
    _PIN_36_GPO_PP = 0x01,
    _PIN_36_GPO_OD = 0x02,
    _PIN_36_PWM2_PP = 0x03,
    _PIN_36_PWM2_OD = 0x04,
    _PIN_36_WS = 0x05,
    _PIN_36_TCON13 = 0x06,
    _PIN_36_TEST4B_OUT0 = 0x0C,
    _PIN_36_TEST4B_OUT1 = 0x0D,
    _PIN_36_TEST4B_OUT2 = 0x0E,
    _PIN_36_TEST4B_OUT3 = 0x0F,
    _PIN_36_NC = _PIN_36_GPO_PP,
} EnumPinshareInfoPIN36;

//---------------------------------------------------------------------------
// Function : HDMI_HPD_0
// Pinshare : 0x1005
// MCU Ctrl : 0xFFE2[5] at _PIN_37_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_37                                 (_PIN_37_GPO_OD)

typedef enum
{
    _PIN_37_GPI = 0x00,
    _PIN_37_GPO_PP = 0x01,
    _PIN_37_GPO_OD = 0x02,
    _PIN_37_PWM3_PP = 0x03,
    _PIN_37_PWM3_OD = 0x04,
    _PIN_37_SD0 = 0x05,
    _PIN_37_SPDIF0 = 0x06,
    _PIN_37_TEST4B_OUT0 = 0x0C,
    _PIN_37_TEST4B_OUT1 = 0x0D,
    _PIN_37_TEST4B_OUT2 = 0x0E,
    _PIN_37_TEST4B_OUT3 = 0x0F,
    _PIN_37_IICSCL0 = 0x40,
    _PIN_37_RXD0 = 0x80,
    _PIN_37_NC = _PIN_37_GPO_PP,
} EnumPinshareInfoPIN37;

//---------------------------------------------------------------------------
// Function : EEP_WP
// Pinshare : 0x1006
// MCU Ctrl : 0xFFE2[6] at _PIN_38_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_38                                 (_PIN_38_GPO_OD)


typedef enum
{
    _PIN_38_GPI = 0x00,
    _PIN_38_GPO_PP = 0x01,
    _PIN_38_GPO_OD = 0x02,
    _PIN_38_TEST4B_OUT0 = 0x0C,
    _PIN_38_TEST4B_OUT1 = 0x0D,
    _PIN_38_TEST4B_OUT2 = 0x0E,
    _PIN_38_TEST4B_OUT3 = 0x0F,
    _PIN_38_IICSDA0 = 0x40,
    _PIN_38_TXD0 = 0x80,
    _PIN_38_NC = _PIN_38_GPO_PP,
} EnumPinshareInfoPIN38;

//---------------------------------------------------------------------------
// Function : AUDIO_SDA (NC)
// Pinshare : 0x1007
// MCU Ctrl : 0xFFE2[7] at _PIN_39_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_39                                 (_PIN_39_GPO_PP)

typedef enum
{
    _PIN_39_GPI = 0x00,
    _PIN_39_GPO_PP = 0x01,
    _PIN_39_GPO_OD = 0x02,
    _PIN_39_TEST4B_OUT0 = 0x0C,
    _PIN_39_TEST4B_OUT1 = 0x0D,
    _PIN_39_TEST4B_OUT2 = 0x0E,
    _PIN_39_TEST4B_OUT3 = 0x0F,
    _PIN_39_NC = _PIN_39_GPO_PP,
} EnumPinshareInfoPIN39;

//---------------------------------------------------------------------------
// Function : ADC_KEY1
// Pinshare : 0x1008
// MCU Ctrl : 0xFFE3[0] at _PIN_42_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_42                                 (_PIN_42_GPI)

typedef enum
{
    _PIN_42_GPI = 0x00,
    _PIN_42_GPO_PP = 0x01,
    _PIN_42_GPO_OD = 0x02,
    _PIN_42_A_ADC0 = 0x03,
    _PIN_42_TEST4B_OUT0 = 0x0C,
    _PIN_42_TEST4B_OUT1 = 0x0D,
    _PIN_42_TEST4B_OUT2 = 0x0E,
    _PIN_42_TEST4B_OUT3 = 0x0F,
    _PIN_42_NC = _PIN_42_GPO_PP,
} EnumPinshareInfoPIN42;

//---------------------------------------------------------------------------
// Function : ADC_KEY2
// Pinshare : 0x1009
// MCU Ctrl : 0xFFE3[1] at _PIN_43_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_43                                 (_PIN_43_GPI)

typedef enum
{
    _PIN_43_GPI = 0x00,
    _PIN_43_GPO_PP = 0x01,
    _PIN_43_GPO_OD = 0x02,
    _PIN_43_A_ADC1 = 0x03,
    _PIN_43_TEST4B_OUT0 = 0x0C,
    _PIN_43_TEST4B_OUT1 = 0x0D,
    _PIN_43_TEST4B_OUT2 = 0x0E,
    _PIN_43_TEST4B_OUT3 = 0x0F,
    _PIN_43_NC = _PIN_43_GPO_PP,
} EnumPinshareInfoPIN43;

//---------------------------------------------------------------------------
// Function : POWER_KEY
// Pinshare : 0x100A
// MCU Ctrl : 0xFFE3[2] at _PIN_44_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_44                                 (_PIN_44_GPI)

typedef enum
{
    _PIN_44_GPI = 0x00,
    _PIN_44_GPO_PP = 0x01,
    _PIN_44_GPO_OD = 0x02,
    _PIN_44_A_ADC2 = 0x03,
    _PIN_44_TEST4B_OUT0 = 0x0C,
    _PIN_44_TEST4B_OUT1 = 0x0D,
    _PIN_44_TEST4B_OUT2 = 0x0E,
    _PIN_44_TEST4B_OUT3 = 0x0F,
    _PIN_44_NC = _PIN_44_GPO_PP,
} EnumPinshareInfoPIN44;

//---------------------------------------------------------------------------
// Function : HDMI_CABLE_DETECT_0
// Pinshare : 0x100B
// MCU Ctrl : 0xFFE3[3] at _PIN_45_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_45                                 (_PIN_45_GPI)

typedef enum
{
    _PIN_45_GPI = 0x00,
    _PIN_45_GPO_PP = 0x01,
    _PIN_45_GPO_OD = 0x02,
    _PIN_45_A_ADC3 = 0x03,
    _PIN_45_TEST4B_OUT0 = 0x0C,
    _PIN_45_TEST4B_OUT1 = 0x0D,
    _PIN_45_TEST4B_OUT2 = 0x0E,
    _PIN_45_TEST4B_OUT3 = 0x0F,
    _PIN_45_NC = _PIN_45_GPO_PP,
} EnumPinshareInfoPIN45;

//---------------------------------------------------------------------------
// Function : EEPROM_WP
// Pinshare : 0x100C
// MCU Ctrl : 0xFFE3[4] at _PIN_46_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_46                                 (_PIN_46_GPO_OD)

typedef enum
{
    _PIN_46_GPI = 0x00,
    _PIN_46_GPO_PP = 0x01,
    _PIN_46_GPO_OD = 0x02,
    _PIN_46_PWM1_PP = 0x03,
    _PIN_46_PWM1_OD = 0x04,
    _PIN_46_TCON7 = 0x05,
    _PIN_46_TCON13 = 0x06,
    _PIN_46_TEST4B_OUT0 = 0x0C,
    _PIN_46_TEST4B_OUT1 = 0x0D,
    _PIN_46_TEST4B_OUT2 = 0x0E,
    _PIN_46_TEST4B_OUT3 = 0x0F,
    _PIN_46_NC = _PIN_46_GPO_PP,
} EnumPinshareInfoPIN46;

//---------------------------------------------------------------------------
// Function : EESCL
// Pinshare : 0x100D
// MCU Ctrl : 0xFFE3[5] at _PIN_47_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_47                                 (_PIN_47_GPI)   

typedef enum
{
    _PIN_47_GPI = 0x00,
    _PIN_47_GPO_PP = 0x01,
    _PIN_47_GPO_OD = 0x02,
    _PIN_47_TCON8 = 0x03,
    _PIN_47_TCON12 = 0x04,
    _PIN_47_TEST4B_OUT0 = 0x0C,
    _PIN_47_TEST4B_OUT1 = 0x0D,
    _PIN_47_TEST4B_OUT2 = 0x0E,
    _PIN_47_TEST4B_OUT3 = 0x0F,
    _PIN_47_IICSCL1 = 0x40,
    _PIN_47_IICSCL_AUX = 0x80,
    _PIN_47_NC = _PIN_47_GPO_PP,
} EnumPinshareInfoPIN47;

//---------------------------------------------------------------------------
// Function : EESDA
// Pinshare : 0x100E
// MCU Ctrl : 0xFFE3[6] at _PIN_48_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_48                                 (_PIN_48_GPI)

typedef enum
{
    _PIN_48_GPI = 0x00,
    _PIN_48_GPO_PP = 0x01,
    _PIN_48_GPO_OD = 0x02,
    _PIN_48_TEST4B_OUT0 = 0x0C,
    _PIN_48_TEST4B_OUT1 = 0x0D,
    _PIN_48_TEST4B_OUT2 = 0x0E,
    _PIN_48_TEST4B_OUT3 = 0x0F,
    _PIN_48_IICSDA1 = 0x40,
    _PIN_48_IICSDA_AUX = 0x80,
    _PIN_48_NC = _PIN_48_GPO_PP,
} EnumPinshareInfoPIN48;

//---------------------------------------------------------------------------
// Function : DP_SINK_ASS_N1
// Pinshare : 0x100F
// MCU Ctrl : 0xFFE3[7] at _PIN_49_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_49                                 (_PIN_49_GPI)

typedef enum
{
    _PIN_49_GPI = 0x40,
    _PIN_49_GPO_PP = 0x41,
    _PIN_49_GPO_OD = 0x42,
    _PIN_49_TEST4B_OUT0 = 0x4C,
    _PIN_49_TEST4B_OUT1 = 0x4D,
    _PIN_49_TEST4B_OUT2 = 0x4E,
    _PIN_49_TEST4B_OUT3 = 0x4F,
    _PIN_49_DDCSCLVGA0 = 0x00,
    _PIN_49_DDCCSL_MUX_SWAP_PIN_43 = 0x20,
    _PIN_49_RXD1 = 0x80,
    _PIN_49_NC = _PIN_49_GPO_PP,
} EnumPinshareInfoPIN49;

//---------------------------------------------------------------------------
// Function : DP_SINK_ASS_P1
// Pinshare : 0x1010
// MCU Ctrl : 0xFE00 at _PIN_50_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_50                                 (_PIN_50_GPI)

typedef enum
{
    _PIN_50_GPI = 0x00,
    _PIN_50_GPO_PP = 0x01,
    _PIN_50_GPO_OD = 0x02,
    _PIN_50_TCON11 = 0x03,
    _PIN_50_TCON13 = 0x04,
    _PIN_50_TEST4B_OUT0 = 0x0C,
    _PIN_50_TEST4B_OUT1 = 0x0D,
    _PIN_50_TEST4B_OUT2 = 0x0E,
    _PIN_50_TEST4B_OUT3 = 0x0F,
    _PIN_50_DDCSDAVGA0 = 0x00,
    _PIN_50_DDCSDA_MUX_SWAP_PIN_44 = 0x20,
    _PIN_50_TXD1 = 0x80,
    _PIN_50_NC = _PIN_50_GPO_PP,
} EnumPinshareInfoPIN50;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1011
// MCU Ctrl : 0xFE01 at _PIN_52_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_52                                 (_PIN_52_NC)

typedef enum
{
    _PIN_52_GPI = 0x00,
    _PIN_52_GPO_PP = 0x01,
    _PIN_52_GPO_OD = 0x02,
    _PIN_52_PWM0_PP = 0x03,
    _PIN_52_PWM0_OD = 0x04,
    _PIN_52_TEST4B_OUT0 = 0x0C,
    _PIN_52_TEST4B_OUT1 = 0x0D,
    _PIN_52_TEST4B_OUT2 = 0x0E,
    _PIN_52_TEST4B_OUT3 = 0x0F,
    _PIN_52_NC = _PIN_52_GPO_PP,
} EnumPinshareInfoPIN52;

//---------------------------------------------------------------------------
// Function : HP_DET
// Pinshare : 0x1012
// MCU Ctrl : 0xFE02 at _PIN_53_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_53                                 (_PIN_53_GPI)

typedef enum
{
    _PIN_53_GPI = 0x00,
    _PIN_53_GPO_PP = 0x01,
    _PIN_53_GPO_OD = 0x02,
    _PIN_53_PWM3_PP = 0x03,
    _PIN_53_PWM3_OD = 0x04,
    _PIN_53_TEST4B_OUT0 = 0x0C,
    _PIN_53_TEST4B_OUT1 = 0x0D,
    _PIN_53_TEST4B_OUT2 = 0x0E,
    _PIN_53_TEST4B_OUT3 = 0x0F,
    _PIN_53_NC = _PIN_53_GPO_PP,
} EnumPinshareInfoPIN53;

//---------------------------------------------------------------------------
// Function : LINE_INL
// Pinshare : 0x1013
// MCU Ctrl : 0xFE03 at _PIN_55_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_55                                 (_PIN_55_LINE_INL)

typedef enum
{
    _PIN_55_GPI = 0x00,
    _PIN_55_GPO_PP = 0x01,
    _PIN_55_GPO_OD = 0x02,
    _PIN_55_PWM0_PP = 0x03,
    _PIN_55_PWM0_OD = 0x04,
    _PIN_55_MCK = 0x05,
    _PIN_55_LINE_INL = 0x06,
    _PIN_55_TEST4B_OUT0 = 0x0C,
    _PIN_55_TEST4B_OUT1 = 0x0D,
    _PIN_55_TEST4B_OUT2 = 0x0E,
    _PIN_55_TEST4B_OUT3 = 0x0F,
    _PIN_55_NC = _PIN_55_GPO_PP,
} EnumPinshareInfoPIN55;

//---------------------------------------------------------------------------
// Function : LINE_INR
// Pinshare : 0x1014
// MCU Ctrl : 0xFE04 at _PIN_56_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_56                                 (_PIN_56_LINE_INR)

typedef enum
{
    _PIN_56_GPI = 0x00,
    _PIN_56_GPO_PP = 0x01,
    _PIN_56_GPO_OD = 0x02,
    _PIN_56_SCK = 0x03,
    _PIN_56_LINE_INR = 0x04,
    _PIN_56_TEST4B_OUT0 = 0x0C,
    _PIN_56_TEST4B_OUT1 = 0x0D,
    _PIN_56_TEST4B_OUT2 = 0x0E,
    _PIN_56_TEST4B_OUT3 = 0x0F,
    _PIN_56_NC = _PIN_56_GPO_PP,
} EnumPinshareInfoPIN56;

//---------------------------------------------------------------------------
// Function : AUDIO_ref
// Pinshare : 0x1015
// MCU Ctrl : 0xFE05 at _PIN_57_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_57                                 (_PIN_57_AUDIO_REF)

typedef enum
{
    _PIN_57_GPI = 0x00,
    _PIN_57_GPO_PP = 0x01,
    _PIN_57_GPO_OD = 0x02,
    _PIN_57_WS = 0x03,
    _PIN_57_AUDIO_REF = 0x04,
    _PIN_57_TCON13 = 0x05,
    _PIN_57_TEST4B_OUT0 = 0x0C,
    _PIN_57_TEST4B_OUT1 = 0x0D,
    _PIN_57_TEST4B_OUT2 = 0x0E,
    _PIN_57_TEST4B_OUT3 = 0x0F,
    _PIN_57_NC = _PIN_57_GPO_PP,
} EnumPinshareInfoPIN57;

//---------------------------------------------------------------------------
// Function : AUDIO_SOUTL
// Pinshare : 0x1016
// MCU Ctrl : 0xFE06 at _PIN_58_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_58                                 (_PIN_58_SOUTL)

typedef enum
{
    _PIN_58_GPI = 0x00,
    _PIN_58_GPO_PP = 0x01,
    _PIN_58_GPO_OD = 0x02,
    _PIN_58_SD0 = 0x03,
    _PIN_58_SPDIF0 = 0x04,
    _PIN_58_SOUTL = 0x05,
    _PIN_58_TEST4B_OUT0 = 0x0C,
    _PIN_58_TEST4B_OUT1 = 0x0D,
    _PIN_58_TEST4B_OUT2 = 0x0E,
    _PIN_58_TEST4B_OUT3 = 0x0F,
    _PIN_58_NC = _PIN_58_GPO_PP,
} EnumPinshareInfoPIN58;

//---------------------------------------------------------------------------
// Function : AUDIO_SOUTR
// Pinshare : 0x1017
// MCU Ctrl : 0xFE07 at _PIN_59_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_59                                 (_PIN_59_SOUTR)

typedef enum
{
    _PIN_59_GPI = 0x00,
    _PIN_59_GPO_PP = 0x01,
    _PIN_59_GPO_OD = 0x02,
    _PIN_59_SOUTR = 0x03,
    _PIN_59_TEST4B_OUT0 = 0x0C,
    _PIN_59_TEST4B_OUT1 = 0x0D,
    _PIN_59_TEST4B_OUT2 = 0x0E,
    _PIN_59_TEST4B_OUT3 = 0x0F,
    _PIN_59_NC = _PIN_59_GPO_PP,
} EnumPinshareInfoPIN59;

//---------------------------------------------------------------------------
// Function : AUDIO_HOUTL
// Pinshare : 0x1018
// MCU Ctrl : 0xFE08 at _PIN_60_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_60                                 (_PIN_60_HOUTL)

typedef enum
{
    _PIN_60_GPI = 0x00,
    _PIN_60_GPO_PP = 0x01,
    _PIN_60_GPO_OD = 0x02,
    _PIN_60_HOUTL = 0x03,
    _PIN_60_TEST4B_OUT0 = 0x0C,
    _PIN_60_TEST4B_OUT1 = 0x0D,
    _PIN_60_TEST4B_OUT2 = 0x0E,
    _PIN_60_TEST4B_OUT3 = 0x0F,
    _PIN_60_IICSCL2 = 0x40,
    _PIN_60_RXD2 = 0x80,
    _PIN_60_NC = _PIN_60_GPO_PP,
} EnumPinshareInfoPIN60;

//---------------------------------------------------------------------------
// Function : AUDIO_HOUTR
// Pinshare : 0x1019
// MCU Ctrl : 0xFE09 at _PIN_61_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_61                                 (_PIN_61_HOUTR)

typedef enum
{
    _PIN_61_GPI = 0x00,
    _PIN_61_GPO_PP = 0x01,
    _PIN_61_GPO_OD = 0x02,
    _PIN_61_HOUTR = 0x03,
    _PIN_61_TEST4B_OUT0 = 0x0C,
    _PIN_61_TEST4B_OUT1 = 0x0D,
    _PIN_61_TEST4B_OUT2 = 0x0E,
    _PIN_61_TEST4B_OUT3 = 0x0F,
    _PIN_61_IICSDA2 = 0x40,
    _PIN_61_TXD2 = 0x80,
    _PIN_61_NC = _PIN_61_GPO_PP,
} EnumPinshareInfoPIN61;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101A
// MCU Ctrl : 0xFE0A at _PIN_63_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_63                                 (_PIN_63_NC)

typedef enum
{
    _PIN_63_GPI = 0x00,
    _PIN_63_GPO_PP = 0x01,
    _PIN_63_GPO_OD = 0x02,
    _PIN_63_PWM0_PP = 0x03,
    _PIN_63_PWM0_OD = 0x04,
    _PIN_63_PWM3_PP = 0x05,
    _PIN_63_PWM3_OD = 0x06,
    _PIN_63_TCON7 = 0x07,
    _PIN_63_INT1 = 0x08,
    _PIN_63_T2 = 0x09,
    _PIN_63_IHS_AFTER_SCALING_DOWN = 0x0A,
    _PIN_63_TEST4B_OUT0 = 0x0C,
    _PIN_63_TEST4B_OUT1 = 0x0D,
    _PIN_63_TEST4B_OUT2 = 0x0E,
    _PIN_63_TEST4B_OUT3 = 0x0F,
    _PIN_63_NC = _PIN_63_GPO_PP,
} EnumPinshareInfoPIN63;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x101B
// MCU Ctrl : 0xFE0B at _PIN_64_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_64                                 (_PIN_64_NC)

typedef enum
{
    _PIN_64_GPI = 0x00,
    _PIN_64_GPO_PP = 0x01,
    _PIN_64_GPO_OD = 0x02,
    _PIN_64_PWM2_PP = 0x03,
    _PIN_64_PWM2_OD = 0x04,
    _PIN_64_TCON8 = 0x05,
    _PIN_64_INT0 = 0x06,
    _PIN_64_IENA_AFTER_SCALING_DOWN = 0x08,
    _PIN_64_CLKO = 0x09,
    _PIN_64_TEST4B_OUT0 = 0x0C,
    _PIN_64_TEST4B_OUT1 = 0x0D,
    _PIN_64_TEST4B_OUT2 = 0x0E,
    _PIN_64_TEST4B_OUT3 = 0x0F,
    _PIN_64_NC = _PIN_64_GPO_PP,
} EnumPinshareInfoPIN64;

//---------------------------------------------------------------------------
// Function : MUTE
// Pinshare : 0x101C
// MCU Ctrl : 0xFE0C at _PIN_65_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_65                                 (_PIN_65_GPO_PP)

typedef enum
{
    _PIN_65_GPI = 0x00,
    _PIN_65_GPO_PP = 0x01,
    _PIN_65_GPO_OD = 0x02,
    _PIN_65_TEST4B_OUT0 = 0x0C,
    _PIN_65_TEST4B_OUT1 = 0x0D,
    _PIN_65_TEST4B_OUT2 = 0x0E,
    _PIN_65_TEST4B_OUT3 = 0x0F,
    _PIN_65_NC = _PIN_65_GPO_PP,
} EnumPinshareInfoPIN65;

//---------------------------------------------------------------------------
// Function : TXD3P
// Pinshare : 0x101D
// MCU Ctrl : 0xFE0D at _PIN_67_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_67_OFF_REGION               (_PIN_67_TXO3P_8B)

typedef enum
{
    _PIN_67_HI_Z = 0x00,
    _PIN_67_GPI = 0x01,
    _PIN_67_GPO_PP = 0x02,
    _PIN_67_GPO_OD = 0x03,
    _PIN_67_TXO3P_8B = 0x04,
    _PIN_67_TEST4B_OUT0 = 0x0C,
    _PIN_67_TEST4B_OUT1 = 0x0D,
    _PIN_67_TEST4B_OUT2 = 0x0E,
    _PIN_67_TEST4B_OUT3 = 0x0F,
    _PIN_67_NC = _PIN_67_GPO_PP,
} EnumPinshareInfoPIN67;

//---------------------------------------------------------------------------
// Function : TXD3N
// Pinshare : 0x101E
// MCU Ctrl : 0xFE0E at _PIN_68_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_68_OFF_REGION                                 (_PIN_68_TXO3N_8B)

typedef enum
{
    _PIN_68_HI_Z = 0x00,
    _PIN_68_GPI = 0x01,
    _PIN_68_GPO_PP = 0x02,
    _PIN_68_GPO_OD = 0x03,
    _PIN_68_TXO3N_8B = 0x04,
    _PIN_68_TEST4B_OUT0 = 0x0C,
    _PIN_68_TEST4B_OUT1 = 0x0D,
    _PIN_68_TEST4B_OUT2 = 0x0E,
    _PIN_68_TEST4B_OUT3 = 0x0F,
    _PIN_68_NC = _PIN_68_GPO_PP,
} EnumPinshareInfoPIN68;

//---------------------------------------------------------------------------
// Function : TXD2P
// Pinshare : 0x101F
// MCU Ctrl : 0xFE0F at _PIN_69_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_69_OFF_REGION                                 (_PIN_69_TXO2P_8B)

typedef enum
{
    _PIN_69_HI_Z = 0x00,
    _PIN_69_GPI = 0x01,
    _PIN_69_GPO_PP = 0x02,
    _PIN_69_GPO_OD = 0x03,
    _PIN_69_TXO2P_8B = 0x04,
    _PIN_69_TEST4B_OUT0 = 0x0C,
    _PIN_69_TEST4B_OUT1 = 0x0D,
    _PIN_69_TEST4B_OUT2 = 0x0E,
    _PIN_69_TEST4B_OUT3 = 0x0F,
    _PIN_69_NC = _PIN_69_GPO_PP,
} EnumPinshareInfoPIN69;

//---------------------------------------------------------------------------
// Function : TXD2N
// Pinshare : 0x1020
// MCU Ctrl : 0xFE10 at _PIN_70_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_70_OFF_REGION                                 (_PIN_70_TXO2N_8B)

typedef enum
{
    _PIN_70_HI_Z = 0x00,
    _PIN_70_GPI = 0x01,
    _PIN_70_GPO_PP = 0x02,
    _PIN_70_GPO_OD = 0x03,
    _PIN_70_TXO2N_8B = 0x04,
    _PIN_70_TEST4B_OUT0 = 0x0C,
    _PIN_70_TEST4B_OUT1 = 0x0D,
    _PIN_70_TEST4B_OUT2 = 0x0E,
    _PIN_70_TEST4B_OUT3 = 0x0F,
    _PIN_70_NC = _PIN_70_GPO_PP,
} EnumPinshareInfoPIN70;

//---------------------------------------------------------------------------
// Function : TXD1P
// Pinshare : 0x1021
// MCU Ctrl : 0xFE11 at _PIN_71_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_71_OFF_REGION                                 (_PIN_71_TXO1P_8B)

typedef enum
{
    _PIN_71_HI_Z = 0x00,
    _PIN_71_GPI = 0x01,
    _PIN_71_GPO_PP = 0x02,
    _PIN_71_GPO_OD = 0x03,
    _PIN_71_TXO1P_8B = 0x04,
    _PIN_71_TEST4B_OUT0 = 0x0C,
    _PIN_71_TEST4B_OUT1 = 0x0D,
    _PIN_71_TEST4B_OUT2 = 0x0E,
    _PIN_71_TEST4B_OUT3 = 0x0F,
    _PIN_71_NC = _PIN_71_GPO_PP,
} EnumPinshareInfoPIN71;

//---------------------------------------------------------------------------
// Function : TXD1N
// Pinshare : 0x1022
// MCU Ctrl : 0xFE12 at _PIN_72_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_72_OFF_REGION                                 (_PIN_72_TXO1N_8B)

typedef enum
{
    _PIN_72_HI_Z = 0x00,
    _PIN_72_GPI = 0x01,
    _PIN_72_GPO_PP = 0x02,
    _PIN_72_GPO_OD = 0x03,
    _PIN_72_TXO1N_8B = 0x04,
    _PIN_72_TEST4B_OUT0 = 0x0C,
    _PIN_72_TEST4B_OUT1 = 0x0D,
    _PIN_72_TEST4B_OUT2 = 0x0E,
    _PIN_72_TEST4B_OUT3 = 0x0F,
    _PIN_72_NC = _PIN_72_GPO_PP,
} EnumPinshareInfoPIN72;

//---------------------------------------------------------------------------
// Function : TXD0P
// Pinshare : 0x1023
// MCU Ctrl : 0xFE13 at _PIN_73_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_73_OFF_REGION                                 (_PIN_73_TXO0P_8B)

typedef enum
{
    _PIN_73_HI_Z = 0x00,
    _PIN_73_GPI = 0x01,
    _PIN_73_GPO_PP = 0x02,
    _PIN_73_GPO_OD = 0x03,
    _PIN_73_TXO0P_8B = 0x04,
    _PIN_73_TEST4B_OUT0 = 0x0C,
    _PIN_73_TEST4B_OUT1 = 0x0D,
    _PIN_73_TEST4B_OUT2 = 0x0E,
    _PIN_73_TEST4B_OUT3 = 0x0F,
    _PIN_73_NC = _PIN_73_GPO_PP,
} EnumPinshareInfoPIN73;

//---------------------------------------------------------------------------
// Function : TXD0N
// Pinshare : 0x1024
// MCU Ctrl : 0xFE14 at _PIN_74_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_74_OFF_REGION                                 (_PIN_74_TXO0N_8B)

typedef enum
{
    _PIN_74_HI_Z = 0x00,
    _PIN_74_GPI = 0x01,
    _PIN_74_GPO_PP = 0x02,
    _PIN_74_GPO_OD = 0x03,
    _PIN_74_TXO0N_8B = 0x04,
    _PIN_74_TEST4B_OUT0 = 0x0C,
    _PIN_74_TEST4B_OUT1 = 0x0D,
    _PIN_74_TEST4B_OUT2 = 0x0E,
    _PIN_74_TEST4B_OUT3 = 0x0F,
    _PIN_74_NC = _PIN_74_GPO_PP,
} EnumPinshareInfoPIN74;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1025
// MCU Ctrl : 0xFE15 at _PIN_90_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_90                                 (_PIN_90_GPO_PP)

typedef enum
{
    _PIN_90_GPI = 0x00,
    _PIN_90_GPO_PP = 0x01,
    _PIN_90_GPO_OD = 0x02,
    _PIN_90_TEST4B_OUT0 = 0x0C,
    _PIN_90_TEST4B_OUT1 = 0x0D,
    _PIN_90_TEST4B_OUT2 = 0x0E,
    _PIN_90_TEST4B_OUT3 = 0x0F,
    _PIN_90_NC = _PIN_90_GPO_PP,
} EnumPinshareInfoPIN90;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1026
// MCU Ctrl : 0xFE16 at _PIN_91_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_91                                 (_PIN_91_GPO_PP)

typedef enum
{
    _PIN_91_GPI = 0x00,
    _PIN_91_GPO_PP = 0x01,
    _PIN_91_GPO_OD = 0x02,
    _PIN_91_TEST4B_OUT0 = 0x0C,
    _PIN_91_TEST4B_OUT1 = 0x0D,
    _PIN_91_TEST4B_OUT2 = 0x0E,
    _PIN_91_TEST4B_OUT3 = 0x0F,
    _PIN_91_NC = _PIN_91_GPO_PP,
} EnumPinshareInfoPIN91;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1027
// MCU Ctrl : 0xFE17 at _PIN_92_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_92                                 (_PIN_92_GPO_PP)

typedef enum
{
    _PIN_92_GPI = 0x00,
    _PIN_92_GPO_PP = 0x01,
    _PIN_92_GPO_OD = 0x02,
    _PIN_92_PWM3_PP = 0x03,
    _PIN_92_PWM3_OD = 0x04,
    _PIN_92_TEST4B_OUT0 = 0x0C,
    _PIN_92_TEST4B_OUT1 = 0x0D,
    _PIN_92_TEST4B_OUT2 = 0x0E,
    _PIN_92_TEST4B_OUT3 = 0x0F,
    _PIN_92_NC = _PIN_92_GPO_PP,
} EnumPinshareInfoPIN92;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1028
// MCU Ctrl : 0xFE18 at _PIN_93_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_93                                 (_PIN_93_GPO_PP)

typedef enum
{
    _PIN_93_GPI = 0x00,
    _PIN_93_GPO_PP = 0x01,
    _PIN_93_GPO_OD = 0x02,
    _PIN_93_PWM2_PP = 0x03,
    _PIN_93_PWM2_OD = 0x04,
    _PIN_93_TEST4B_OUT0 = 0x0C,
    _PIN_93_TEST4B_OUT1 = 0x0D,
    _PIN_93_TEST4B_OUT2 = 0x0E,
    _PIN_93_TEST4B_OUT3 = 0x0F,
    _PIN_93_NC = _PIN_93_GPO_PP,
} EnumPinshareInfoPIN93;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1029
// MCU Ctrl : 0xFE19 at _PIN_94_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_94                                 (_PIN_94_GPO_PP)

typedef enum
{
    _PIN_94_GPI = 0x00,
    _PIN_94_GPO_PP = 0x01,
    _PIN_94_GPO_OD = 0x02,
    _PIN_94_PWM1_PP = 0x03,
    _PIN_94_PWM1_OD = 0x04,
    _PIN_94_TEST4B_OUT0 = 0x0C,
    _PIN_94_TEST4B_OUT1 = 0x0D,
    _PIN_94_TEST4B_OUT2 = 0x0E,
    _PIN_94_TEST4B_OUT3 = 0x0F,
    _PIN_94_NC = _PIN_94_GPO_PP,
} EnumPinshareInfoPIN94;

//---------------------------------------------------------------------------
// Function : FLASH_WP
// Pinshare : 0x102A
// MCU Ctrl : 0xFE1A at _PIN_96_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_96                                 (_PIN_96_GPO_PP)

typedef enum
{
    _PIN_96_GPI = 0x00,
    _PIN_96_GPO_PP = 0x01,
    _PIN_96_GPO_OD = 0x02,
    _PIN_96_INT0 = 0x03,
    _PIN_96_TEST4B_OUT0 = 0x0C,
    _PIN_96_TEST4B_OUT1 = 0x0D,
    _PIN_96_TEST4B_OUT2 = 0x0E,
    _PIN_96_TEST4B_OUT3 = 0x0F,
    _PIN_96_NC = _PIN_96_GPO_PP,
} EnumPinshareInfoPIN96;

//---------------------------------------------------------------------------
// Function : Panel_ON
// Pinshare : 0x102B
// MCU Ctrl : 0xFE1B at _PIN_97_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_97                                 (_PIN_97_GPO_PP)

typedef enum
{
    _PIN_97_GPI = 0x00,
    _PIN_97_GPO_PP = 0x01,
    _PIN_97_GPO_OD = 0x02,
    _PIN_97_INT1 = 0x03,
    _PIN_97_TCON11 = 0x04,
    _PIN_97_IVS_AFTER_SCALING_DOWN = 0x06,
    _PIN_97_TEST4B_OUT0 = 0x0C,
    _PIN_97_TEST4B_OUT1 = 0x0D,
    _PIN_97_TEST4B_OUT2 = 0x0E,
    _PIN_97_TEST4B_OUT3 = 0x0F,
    _PIN_97_NC = _PIN_97_GPO_PP,
} EnumPinshareInfoPIN97;

//---------------------------------------------------------------------------
// Function : DP_HOT_PLUG
// Pinshare : 0x102C
// MCU Ctrl : 0xFE1C at _PIN_98_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_98                                 (_PIN_98_GPO_PP)

typedef enum
{
    _PIN_98_GPI = 0x00,
    _PIN_98_GPO_PP = 0x01,
    _PIN_98_GPO_OD = 0x02,
    _PIN_98_T0 = 0x03,
    _PIN_98_DENA = 0x04,
    _PIN_98_TCON9 = 0x05,
    _PIN_98_TEST4B_OUT0 = 0x0C,
    _PIN_98_TEST4B_OUT1 = 0x0D,
    _PIN_98_TEST4B_OUT2 = 0x0E,
    _PIN_98_TEST4B_OUT3 = 0x0F,
    _PIN_98_NC = _PIN_98_GPO_PP,
} EnumPinshareInfoPIN98;

//---------------------------------------------------------------------------
// Function : DP_CABLE_DET_1
// Pinshare : 0x102D
// MCU Ctrl : 0xFE1D at _PIN_99_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_99                                 (_PIN_99_GPI)

typedef enum
{
    _PIN_99_GPI = 0x00,
    _PIN_99_GPO_PP = 0x01,
    _PIN_99_GPO_OD = 0x02,
    _PIN_99_PWM2_PP = 0x03,
    _PIN_99_PWM2_OD = 0x04,
    _PIN_99_PWM3_PP= 0x05,
    _PIN_99_PWM3_OD= 0x06,
    _PIN_99_T1= 0x07,
    _PIN_99_DHS= 0x08,
    _PIN_99_TCON13= 0x09,
    _PIN_99_TEST4B_OUT0 = 0x0C,
    _PIN_99_TEST4B_OUT1 = 0x0D,
    _PIN_99_TEST4B_OUT2 = 0x0E,
    _PIN_99_TEST4B_OUT3 = 0x0F,
    _PIN_99_NC = _PIN_99_GPO_PP,
} EnumPinshareInfoPIN99;

//---------------------------------------------------------------------------
// Function : DDCSCL_VGA
// Pinshare : 0x102E
// MCU Ctrl : 0xFE1E at _PIN_100_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_100                                (_PIN_100_DDCSCLVGA1)

typedef enum
{
    _PIN_100_GPI = 0x80,
    _PIN_100_GPO_PP = 0x81,
    _PIN_100_GPO_OD = 0x82,
    _PIN_100_AUX_D2 = 0x83,
    _PIN_100_DCLK = 0x84,
    _PIN_100_TCON8= 0x85,
    _PIN_100_PWM_IN= 0x86,
    _PIN_100_T2EX= 0x87,
    _PIN_100_TEST4B_OUT0 = 0x8C,
    _PIN_100_TEST4B_OUT1 = 0x8D,
    _PIN_100_TEST4B_OUT2 = 0x8E,
    _PIN_100_TEST4B_OUT3 = 0x8F,
    _PIN_100_DDCSCLVGA1= 0x00,
    _PIN_100_NC = _PIN_100_GPO_PP,
} EnumPinshareInfoPIN100;

//---------------------------------------------------------------------------
// Function : DDCSDA_VGA
// Pinshare : 0x102F
// MCU Ctrl : 0xFE1F at _PIN_101_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_101                                (_PIN_101_DDCSDAVGA1)

typedef enum
{
    _PIN_101_GPI = 0x00,
    _PIN_101_GPO_PP = 0x01,
    _PIN_101_GPO_OD = 0x02,
    _PIN_101_AUX_D1 = 0x03,
    _PIN_101_DVS = 0x04,
    _PIN_101_TCON7= 0x05,
    _PIN_101_PWM_OUT= 0x06,
    _PIN_101_PWM1_PP = 0x07,
    _PIN_101_PWM1_OD = 0x08,
    _PIN_101_TEST4B_OUT0 = 0x0C,
    _PIN_101_TEST4B_OUT1 = 0x0D,
    _PIN_101_TEST4B_OUT2 = 0x0E,
    _PIN_101_TEST4B_OUT3 = 0x0F,
    _PIN_101_DDCSDAVGA1= 0x00,
    _PIN_101_NC = _PIN_101_GPO_PP,
} EnumPinshareInfoPIN101;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1030
// MCU Ctrl : 0xFE20 at _PIN_102_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_102                                (_PIN_102_NC)

typedef enum
{
    _PIN_102_GPI = 0x00,
    _PIN_102_GPO_PP = 0x01,
    _PIN_102_GPO_OD = 0x02,
    _PIN_102_TEST4B_OUT0 = 0x0C,
    _PIN_102_TEST4B_OUT1 = 0x0D,
    _PIN_102_TEST4B_OUT2 = 0x0E,
    _PIN_102_TEST4B_OUT3 = 0x0F,
    _PIN_102_NC = _PIN_102_GPO_PP,
} EnumPinshareInfoPIN102;

//---------------------------------------------------------------------------
// Function : NC
// Pinshare : 0x1031
// MCU Ctrl : 0xFE21 at _PIN_108_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_108                                (_PIN_108_NC)

typedef enum
{
    _PIN_108_GPI = 0x00,
    _PIN_108_GPO_PP = 0x01,
    _PIN_108_GPO_OD = 0x02,
    _PIN_108_PWM3_PP = 0x03,
    _PIN_108_PWM3_OD = 0x04,
    _PIN_108_TEST4B_OUT0 = 0x0C,
    _PIN_108_TEST4B_OUT1 = 0x0D,
    _PIN_108_TEST4B_OUT2 = 0x0E,
    _PIN_108_TEST4B_OUT3 = 0x0F,
    _PIN_108_NC = _PIN_108_GPO_PP,
} EnumPinshareInfoPIN108;

//---------------------------------------------------------------------------
// Function : DDCSCL_0
// Pinshare : 0x1032
// MCU Ctrl : 0xFE22 at _PIN_110_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_110                                (_PIN_110_DDCSCL0)

typedef enum
{
    _PIN_110_GPI = 0x80,
    _PIN_110_GPO_PP = 0x81,
    _PIN_110_GPO_OD = 0x82,
    _PIN_110_AUXP0 = 0x85,
    _PIN_110_TEST4B_OUT0 = 0x8C,
    _PIN_110_TEST4B_OUT1 = 0x8D,
    _PIN_110_TEST4B_OUT2 = 0x8E,
    _PIN_110_TEST4B_OUT3 = 0x8F,
    _PIN_110_DDCSCL0 = 0x00,
    _PIN_110_NC = _PIN_110_GPO_PP,
} EnumPinshareInfoPIN110;

//---------------------------------------------------------------------------
// Function : DDCSDA_0
// Pinshare : 0x1033
// MCU Ctrl : 0xFE23 at _PIN_111_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_111                                (_PIN_111_DDCSDA0)

typedef enum
{
    _PIN_111_GPI = 0x00,
    _PIN_111_GPO_PP = 0x01,
    _PIN_111_GPO_OD = 0x02,
    _PIN_111_AUXN0 = 0x05,
    _PIN_111_TEST4B_OUT0 = 0x0C,
    _PIN_111_TEST4B_OUT1 = 0x0D,
    _PIN_111_TEST4B_OUT2 = 0x0E,
    _PIN_111_TEST4B_OUT3 = 0x0F,
    _PIN_111_DDCSDA0 = 0x00,
    _PIN_111_NC = _PIN_111_GPO_PP,
} EnumPinshareInfoPIN111;

//---------------------------------------------------------------------------
// Function : AUX_CHP
// Pinshare : 0x1034
// MCU Ctrl : 0xFE24 at _PIN_112_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_112                                (_PIN_112_DDCSCL1)

typedef enum
{
    _PIN_112_GPI = 0x80,
    _PIN_112_GPO_PP = 0x81,
    _PIN_112_GPO_OD = 0x82,
    _PIN_112_AUXP1 = 0x83,
    _PIN_112_TEST4B_OUT0 = 0x8C,
    _PIN_112_TEST4B_OUT1 = 0x8D,
    _PIN_112_TEST4B_OUT2 = 0x8E,
    _PIN_112_TEST4B_OUT3 = 0x8F,
    _PIN_112_DDCSCL1= 0x00,
    _PIN_112_NC = _PIN_112_GPO_PP,
} EnumPinshareInfoPIN112;

//---------------------------------------------------------------------------
// Function : AUX_CHN
// Pinshare : 0x1035
// MCU Ctrl : 0xFE25 at _PIN_113_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_113                                (_PIN_113_DDCSDA1)

typedef enum
{
    _PIN_113_GPI = 0x00,
    _PIN_113_GPO_PP = 0x01,
    _PIN_113_GPO_OD = 0x02,
    _PIN_113_AUXN1 = 0x03,
    _PIN_113_TEST4B_OUT0 = 0x0C,
    _PIN_113_TEST4B_OUT1 = 0x0D,
    _PIN_113_TEST4B_OUT2 = 0x0E,
    _PIN_113_TEST4B_OUT3 = 0x0F,
    _PIN_113_DDCSDA1= 0x00,
    _PIN_113_NC = _PIN_113_GPO_PP,
} EnumPinshareInfoPIN113;

//---------------------------------------------------------------------------
// Function : KEYPAD_LED1
// Pinshare : 0x1036
// MCU Ctrl : 0xFE26 at _PIN_114_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_114                                (_PIN_114_GPO_PP)

typedef enum
{
    _PIN_114_GPI = 0x00,
    _PIN_114_GPO_PP = 0x01,
    _PIN_114_GPO_OD = 0x02,
    _PIN_114_PWM2_PP = 0x03,
    _PIN_114_PWM2_OD = 0x04,
    _PIN_114_TEST4B_OUT0 = 0x0C,
    _PIN_114_TEST4B_OUT1 = 0x0D,
    _PIN_114_TEST4B_OUT2 = 0x0E,
    _PIN_114_TEST4B_OUT3 = 0x0F,
    _PIN_114_NC = _PIN_114_GPO_PP,
} EnumPinshareInfoPIN114;

//---------------------------------------------------------------------------
// Function : KEYPAD_LED2
// Pinshare : 0x1037
// MCU Ctrl : 0xFE27 at _PIN_115_MCU_REG
//---------------------------------------------------------------------------
#define _PIN_115                                (_PIN_115_GPO_PP)

typedef enum
{
    _PIN_115_GPI = 0x00,
    _PIN_115_GPO_PP = 0x01,
    _PIN_115_GPO_OD = 0x02,
    _PIN_115_PWM1_PP = 0x03,
    _PIN_115_PWM1_OD = 0x04,
    _PIN_115_TEST4B_OUT0 = 0x0C,
    _PIN_115_TEST4B_OUT1 = 0x0D,
    _PIN_115_TEST4B_OUT2 = 0x0E,
    _PIN_115_TEST4B_OUT3 = 0x0F,
    _PIN_115_NC = _PIN_115_GPO_PP,
} EnumPinshareInfoPIN115;


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
			
#define bDDC1IICSCL 							(_PIN_112_MCU_REG)
#define bDDC1IICSDA 							(_PIN_113_MCU_REG)
			
#define bDDCVGAIICSCL                           (_PIN_100_MCU_REG)
#define bDDCVGAIICSDA                           (_PIN_101_MCU_REG)
		

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

#define PCB_ON_REGION_GPIO_SETTING_POWER_AC_ON(){\
                                                }

#define PCB_OFF_REGION_GPIO_SETTING_POWER_AC_PD_PS_ON()\
                                                {\
  													PCB_AMP_MUTE(_AMP_MUTE_ON);\
  							   }


#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
												}

#define PCB_GPIO_SETTING_POWER_SAVING()         {\
													PCB_AMP_MUTE(_AMP_MUTE_ON);\
}

#define PCB_GPIO_SETTING_POWER_DOWN()           {\
													PCB_AMP_MUTE(_AMP_MUTE_ON);\
 }



/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of Embedded LDO Support
//-----------------------------------------------
#define _EMBEDDED_LDO_OFF                       0
#define _EMBEDDED_LDO_ON                        1

#define PCB_EMBEDDED_LDO_DETECT()           (_EMBEDDED_LDO_OFF)//       (_EMBEDDED_LDO_ON)


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             _PIN_97_MCU_REG

#define _PANEL_CONTROL_ON                       1//0
#define _PANEL_CONTROL_OFF                      0//1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                        _PIN_35_MCU_REG

#define _LIGHT_CONTROL_ON                    1//   0
#define _LIGHT_CONTROL_OFF                  0//    1

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = (x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                         ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                         ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 25000);\
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
#define bFLASH_WRITE_PROTECT                    _PIN_96_MCU_REG

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
#define bEDID_WRITE_PROTECT                     (_PIN_38_MCU_REG)

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }


#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------

sbit bA0_CONNECT                              = P1 ^ 4;//_PIN_36_MCU_REG
#define bD1_CONNECT                             _PIN_45_MCU_REG

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD1_HPD                                 _PIN_37_MCU_REG


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
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM,25000);\
                                                }
#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)

#define PCB_AUDIO_PWM(x)                   {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM, (x));\
                                                }

#define PCB_GET_AUDIO_PWM()                 (MCU_GET_8BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM))

#elif(_PWM_DUT_RESOLUTION == _PWM_12BIT)

#define PCB_AUDIO_PWM(x)                    {\
                                                    MCU_ADJUST_12BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM, (x));\
                                                }

#define PCB_GET_AUDIO_PWM()                 (MCU_GET_12BIT_PWM_DUTY(_AUDIO_VOLUMN_PWM))

#endif


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


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   _PIN_114_MCU_REG
#define bLED2                                   _PIN_115_MCU_REG

#define _LED_ON                                 1
#define _LED_OFF                                0


#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE3()                         {\
                                                }

#define PCB_LED_TYPE4()                         {\
                                                }

#define PCB_LED_TYPE5()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
													bLED2 = ~bLED2;\
                                                }

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY0                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // Pin_42
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // Pin_43

#define PCB_ADKEY0()                            (AD_KEY0)
#define PCB_ADKEY1()                            (AD_KEY1)

#define  bPOWER_KEY                          (_PIN_44_MCU_REG)// Pin_71 P3.0
#define  b_KEY1                              (_PIN_43_MCU_REG)
#define  b_KEY2                              (_PIN_42_MCU_REG)
#define  b_KEY3                              (_PIN_47_MCU_REG)
#define  b_KEY4                              (_PIN_48_MCU_REG)




#define POWER_KEY								0x80
#define EXIT_KEY								0xA8
#define RIGHT_KEY  								0x00 
#define MENU_KEY 								0X80
#define LEFT_KEY 								0XD0 

#define POWER_REG								1
#define EXIT_REG								1
#define RIGHT_REG  								1
#define MENU_REG 								2
#define LEFT_REG 								1







//4   2  3 1

#if 1
// 27´ç
#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\       
																	if(!b_KEY1)\   
																	{\
																	(ucKeyState) |= _EXIT_KEY_MASK;\
																	}\
																	if(!b_KEY2)\
																	{\
																	(ucKeyState) |= _RIGHT_KEY_MASK;\
																	}\
															    	if(!b_KEY3)\
																	{\
																	(ucKeyState) |= _MENU_KEY_MASK;\
																	}\
																	if(!b_KEY4)\
																	{\
																	(ucKeyState) |= _LEFT_KEY_MASK;\
																	}\
																	if(!bPOWER_KEY)\
																	{\
																	(ucKeyState) |= _POWER_KEY_MASK;\
																	}\
																   }
#else

#define PCB_KEY_STATE(ucV0, ucV1, ucV2, ucV3, ucKeyState)   {\ 
	                                                        if(!bPOWER_KEY)\
																{\
																(ucKeyState) |= _POWER_KEY_MASK;\
																}\
	                                                        }



#endif


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
// Macro of Earphone Detect
//-----------------------------------------------
//UserInterfaceGetAudioDACOutput
#define bPCB_HP_SENSE_DETECT                   (_PIN_53_MCU_REG)     

#define _HP_CONNECTED            				1
#define _HP_DISCONNECTED         				0

#define PCB_EARPHONE_CONNECTED()      			(bPCB_HP_SENSE_DETECT == _HP_CONNECTED)
#define PCB_EARPHONE_DISCONNECTED()   			(bPCB_HP_SENSE_DETECT == _HP_DISCONNECTED)



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
#define bMPRT_CURRENT_CONTROL                            (_PIN_34_MCU_REG)	// Pin_21
													
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


/*
#define bMPRT_CONTROL                            (_PIN_35_MCU_REG)	// Pin_22
#define _MPRT_GPIO_ON                            1
#define _MPRT_GPIO_OFF                           0
#define PCB_MPRT_GPIO_CONTROL(x)                    {\
                                                                  bMPRT_CONTROL = (x);\
                                                }
*/
#endif



#endif // End of #if(_PCB_TYPE == _RL6463__128PIN__HKMRT2513E01__1A1H__LVDS)



