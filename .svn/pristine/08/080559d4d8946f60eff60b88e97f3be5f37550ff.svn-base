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
// ID Code      : TPVFactoryCommand.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


#define __FACTORY_COMMAND__

#include "UserCommonInclude.h"
extern BYTE g_pucDdcciRxBuf[_DDCCI_RXBUF_LENGTH];
extern BYTE g_pucDdcciTxBuf[_DDCCI_TXBUF_LENGTH];


#if(_DEF_DDCCI_EDID_TOOL)

bit bProductModeFlag = _OFF;


//BYTE Visonic_Sn[19];

#ifndef _ENE_LED_CONTROL
#define _ENE_LED_CONTROL		                    _OFF
#endif



#ifdef _ENE_LED_CONTROL
#if (_ENE_LED_CONTROL != _OFF)
#include "ENE_LED_CONTROL.h" // Led test
#endif
#endif

#if 1//(_FACTORY_MODE_OWNER == _OWNER_TPV)

#ifndef _TPV_FACTORY_SELECT
#define _TPV_FACTORY_SELECT					_TPV_FQ_FACTORY
#endif
#ifndef _PANEL_VCOM_ADJUST_FUNCTION
#define _PANEL_VCOM_ADJUST_FUNCTION			_OFF
#endif
//--------------------------------------------------
// Definitions of Panel VCOM Function
//--------------------------------------------------
#define _PANEL_VCOM_I2C_ADDRESS                 0x50
#define _PANEL_VCOM_DAC_ADDRESS                 0x80
#define _PANEL_VCOM_OTP_ADDRESS                 0x00

//-----------------------------------------------------
//DFM MODE
//-----------------------------------------------------

#define _TPV_FQ_FACTORY								1
#define _TPV_LT_FACTORY								2
#define _TPV_WH_FACTORY								3
#define _TPV_BJ_FACTORY								4

#define _PRODUCT_ON                             0x55aa
#define _PRODUCT_OFF                            0xaa55
#define _FORCE_LOGO_OFF                                 _OFF

//-----------------------------------------------------
#define _DDC_SOURCE								0
#define _DDC_LENGTH								1
#define _FC_BYTE2								2
#define _FC_BYTE3                              	3
#define _FC_BYTE4								4
#define _FC_BYTE5								5
#define _FC_BYTE6								6
#define _FC_BYTE7								7
#define _FC_BYTE8								8
//===========================================
// Definitions of Factory Command
//===========================================
#define CMD_FC_TPVFactory						0xFE
//===========AOC  Factory Command===============
#define VCP_FC_ADJUST_R_GAIN					0x16
//===========================================
#define VCP_FC_ADJUST_G_GAIN					0x18
//===========================================
#define VCP_FC_ADJUST_B_GAIN					0x1a
//===========================================
#define VCP_FC_ADJUST_CONTRAST      			0x12
//===========================================
#define VCP_FC_ADJUST_BL_BRIGHTNESS	    		0x10
//===========================================
#define VCP_FC_SAVE_COLORTEMP                   0x14
//===========================================
#define VCP_FC_RANGE_GAIN                       0x16

#define VCP_FC_FACTORY_CEC_MODE_RESET			0x08//Add CEC Command Function

//-----Sub Item of VCP_FC_SAVE_COLORTEMP (_FC_BYTE5)
#if (_TPV_FACTORY_SELECT == _TPV_WH_FACTORY)
#define SUB_VCP_FC_SAVE_COLORTEMP_All   		0x81
#else
#define SUB_VCP_FC_SAVE_COLORTEMP_All           0x00
#endif
#define SUB_VCP_FC_SAVE_COLORTEMP_sRGB  		0x01
#define SUB_VCP_FC_SAVE_COLORTEMP_Native    	0x02
#define SUB_VCP_FC_SAVE_COLORTEMP_4000  		0x03
#define SUB_VCP_FC_SAVE_COLORTEMP_5000  		0x04
#define SUB_VCP_FC_SAVE_COLORTEMP_6500  		0x05
#define SUB_VCP_FC_SAVE_COLORTEMP_7300  		0x06
#define SUB_VCP_FC_SAVE_COLORTEMP_8200  		0x07
#define SUB_VCP_FC_SAVE_COLORTEMP_9300  		0x08
#define SUB_VCP_FC_SAVE_COLORTEMP_10000 		0x09
#define SUB_VCP_FC_SAVE_COLORTEMP_11500 		0x0a
#define SUB_VCP_FC_SAVE_COLORTEMP_User  		0x0b
#define SUB_VCP_FC_SAVE__ECO_TEXT_MODE			0x10//DELL only

//===========================================   _FC_BYTE4
#define VCP_FC_AUTO_ADJUST						0x1E
//===========================================
#define VCP_FC_AUTO_LEVEL						0x1F
//===========================================
#define VCP_FC_RESET                            0x04
//-----------------------------------------------------
#define VCP_FC_SET_LANGUAGE                     0xCC
//===========================================
#define VCP_FC_SET_SOURCE                       0x60
//===========================================
#define VCP_FC_ENTER_POWERSAVING				0xD6
//===========================================
#define VCP_FC_DC_FUNC                     		0xDC
//===========================================
#define VCP_FC_Code01                           0xe1

//-----------------------------------------------------(_FC_BYTE5)
#define SUB_VCP_FC_FACTORY_MODE_A0      		0xa0
#define SUB1_VCP_FC_ENTER_FACTORY_MODE          0x01
#define SUB1_VCP_FC_EXIT_FACTORY_MODE        	0x00
//-----------------------------------------------------
#define SUB_VCP_FC_NVRAW_RESTORE_A1      		0xa1
#if 1//(ENABLE_OTA_FUNCTION == _ON)
#define VCP_FC_FACTORY_DUAL_BANK_START          0x01
#endif
#define SUB1_VCP_FC_NVRAW_RESTORE_A1_ON         0x00
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A2      		0xa2
#define SUB1_VCP_FC_SET_BURNIN_OFF              0x00
#define SUB1_VCP_FC_SET_BURNIN_ON               0x01
#define SUB1_VCP_FC_SET_WR_START				0x01
#define SUB1_VCP_FC_SET_WR_END		    		0x00
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A3      		0xa3
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A4      		0xa4//for WH MANUFACTORY only
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A5      		0xa5
#define SUB1_VCP_FC_ENTER_DFM                   0x01
#define SUB1_VCP_FC_EXIT_DFM                    0x00
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A6      		0xa6
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A7      		0xa7
#define VCP_FC_FACTORY_LOGO_OFF       			0x06
#define VCP_FC_FACTORY_LOGO_OFF_ENABLE        	0x00
#define VCP_FC_FACTORY_LOGO_OFF_DISABLE         0x01
#define VCP_FC_FACTORY_DCR_MODE       			0x03  // DCR Mode
#define VCP_FC_FACTORY_DCR_OFF         			0x00
#define VCP_FC_FACTORY_DCR_ON          			0x01
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A9				0xa9
//-----------------------------------------------------
#define SUB_VCP_FC_SET_HDCP_WRITE_START         0xe0
//-----------------------------------------------------
#define SUB_VCP_FC_SET_HDCP_TX_WRITE_START      0xe1
//-----------------------------------------------------
#define SUB_VCP_FC_READ_HDCP_CRC				0xe2
//-----------------------------------------------------
#define SUB_VCP_FC_READ_DEVICE_ID				0xe6
#define SUB_VCP_FC_READ_SCALER_ID               0xe8
#if 1//(ENABLE_OTA_FUNCTION == _ON)
#define VCP_FC_FACTORY_FW_SCALER_TYPE           0x00
#define VCP_FC_FACTORY_FW_VERSION               0x06
#define VCP_FC_FACTORY_FW_BOM_STRING            0x1D
#endif
//===========================================
#define VCP_FC_Code02                           0xe2
#define SUB_VCP_FC_ADJUST_ADC_R_GAIN        	0x01
#define SUB_VCP_FC_ADJUST_ADC_G_GAIN        	0x02
#define SUB_VCP_FC_ADJUST_ADC_B_GAIN        	0x03
#define SUB_VCP_FC_ADJUST_ADC_R_OFFSET  		0x04
#define SUB_VCP_FC_ADJUST_ADC_G_OFFSET  		0x05
#define SUB_VCP_FC_ADJUST_ADC_B_OFFSET  		0x06
#define SUB_VCP_FC_COLORTMP_GAIN_MAX			0x02
//===========================================
#define VCP_FC_Code04                           0xe4
#define SUB_VCP_FC_VIRTUAL_KEY                  0x01
//===========================================
#define VCP_FC_Code09							0xe9
//===========================================
#define VCP_FC_Code0A							0xea
//===========================================
#define VCP_FC_Code0F                   		0xef
#define SUB_VCP_FC_VGA1_EDID         			0x00
#define SUB_VCP_FC_DVI1_EDID         			0x01
#define SUB_VCP_FC_HDMI1_EDID        			0x02
#define SUB_VCP_FC_DP1_EDID          			0x03
#define SUB_VCP_FC_VGA2_EDID         			0x04
#define SUB_VCP_FC_DVI2_EDID         			0x05
#define SUB_VCP_FC_HDMI2_EDID        			0x06
#define SUB_VCP_FC_DP2_EDID          			0x07
#define SUB_VCP_FC_HDMI3_EDID        			0x08
#define SUB_VCP_FC_HDMI4_EDID        			0x09
#define SUB_VCP_FC_MHL1_EDID        			0x0A
#define SUB_VCP_FC_MHL2_EDID        			0x0B
#define SUB_VCP_FC_MHL3_EDID        			0x0C
#define SUB_VCP_FC_MHL4_EDID        			0x0D
#define SUB_VCP_FC_EEPROM           			0x10
#define SUB_VCP_FC_HDCP1            			0x11
#define SUB_VCP_FC_HDCP2            			0x12
#define SUB_VCP_FC_OSDSN            			0x13
#define SUB_VCP_FC_OSDMODELNAME     			0x14

#define SUB_VCP_FC_HDMI20_HDMI1_EDID			0x40
#define SUB_VCP_FC_HDMI20_HDMI2_EDID			0x41
#define SUB_VCP_FC_HDMI20_HDMI3_EDID			0x42
#define SUB_VCP_FC_HDMI20_HDMI4_EDID			0x43
#define SUB_VCP_FC_DP3_EDID						0x44
//===========================================
#define VCP_FC_Code13							0xF3
//===========================================
//===========================================
#define _AWB_COMMAND_LEN_CRC            		4
#define _REPLY_RESULT_00                		0x00
#define _REPLY_RESULT_02                		0x02//PASS
#define _REPLY_RESULT_04                		0x04//Fail
#define SUB_VCP_FC_PWM_MIN                      0x00
#define SUB_VCP_FC_PWM_DEF                      0x01
#define SUB_VCP_FC_PWM_MAX                      0x02

//-----------------------------------------------------
//HDCP Key Writeing Size one Times
//-----------------------------------------------------
#define _HDCP_BLOCK_SIZE                		20
#define _HDCP_2_2_BLOCK_SIZE                    32



#if(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)

#define _DFM_DP1_PORT                           _D1_INPUT_PORT
#define _DFM_DP2_PORT							_NO_INPUT_PORT
#define _DFM_HDMI1_PORT                         _D2_INPUT_PORT
#define _DFM_HDMI2_PORT							_D3_INPUT_PORT
#else
#define _DFM_HDMI1_PORT                         _D1_INPUT_PORT
#define _DFM_HDMI2_PORT							_NO_INPUT_PORT
#define _DFM_DP1_PORT                           _NO_INPUT_PORT
#define _DFM_DP2_PORT							_NO_INPUT_PORT

#endif
#define _DFM_VGA_PORT							_A0_INPUT_PORT
#define _DFM_DVI1_PORT							_NO_INPUT_PORT
#define _DFM_DVI2_PORT							_NO_INPUT_PORT

#define _DFM_HDMI3_PORT							_NO_INPUT_PORT
#define _DFM_HDMI4_PORT							_NO_INPUT_PORT

#define _DFM_MHL1_PORT							_NO_INPUT_PORT
#define _DFM_MHL2_PORT							_NO_INPUT_PORT
#define _DFM_MHL3_PORT							_NO_INPUT_PORT
#define _DFM_MHL4_PORT							_NO_INPUT_PORT
	//-------------------------------------------------------------
	//define HDMI2.0 Port
	//-------------------------------------------------------------
#define _DFM_HDMI20_HDMI1_PORT                  _NO_INPUT_PORT
#define _DFM_HDMI20_HDMI2_PORT                  _NO_INPUT_PORT
#define _DFM_HDMI20_HDMI3_PORT					_NO_INPUT_PORT
#define _DFM_HDMI20_HDMI4_PORT					_NO_INPUT_PORT
#define _DFM_DP3_PORT							_NO_INPUT_PORT

#define _DEF_OSD_FACTORY						_ON	//工厂	// liuxh b1OsdFactory

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
#define _DEF_OSD_BURNIN							_ON
#else
#define _DEF_OSD_BURNIN							_OFF
#endif

StructFactoryType g_stFactoryData;
// 20111109 by jerry,  for TPV factory data

code StructFactoryType g_stFactoryDataDefault=
{
	_DEF_OSD_FACTORY,           // b1OsdFactory		
    _DEF_OSD_BURNIN,//_ON,		// b1BurnIn : 1;		//老化
	_OFF,			// b1OsdHotKeyBurnIn : 1;
	_ON,//_FORCE_LOGO_OFF,// b1LogoOff :1;	//DFM rev04 patch note 2
	_FAIL,			// b1InternalAutoColor :1;//DFM rev05 patch note 2
	_OFF,			// b1EnergyLogo :1;
	_ON,            // b1AutoSource :1;		//自动信号检测
	_OFF,   		// b1Resetoff:1;
    100,			// ucsRGBBacklight;
    64,				// ucVcomValue
	_PRODUCT_OFF,	// usDFMProductMode;
	_ENGLISH,
	0xFF,//dummy1
	0xFF,//dummy2
};

void TPVNVRamSaveFactoryDate(void)
{
	#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    UserCommonEepromWrite(_TPV_FACTORY_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));

	#else
	UserCommonFlashSaveItem(_FLASH_ITEMID_FACTORY_DATA, (BYTE *)(&g_stFactoryData), sizeof(StructFactoryType));
	#endif
}

void TPVNVRamLoadFactoryDate(void)
{
	//DebugMessageOsd("1.LoadFactoryDate",1);
	#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    UserCommonEepromRead(_TPV_FACTORY_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
	//UserNVRamCheckRange(g_stFactoryData);

	#else
	if(UserCommonFlashLoadItem(_FLASH_ITEMID_FACTORY_DATA, pData, sizeof(StructFactoryType)) == _TRUE)
	{
		memcpy(&g_stFactoryData, pData, sizeof(StructFactoryType));
	}
	else
	{
		g_stFactoryData = g_stFactoryDataDefault;
	}
	#endif
}
/*
void TPVNVRamRestoreFactoryDate(void)
{
	g_stFactoryData = g_stFactoryDataDefault;

	#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
	UserCommonEepromWrite(_TPV_FACTORY_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));

	#else
	if(UserCommonFlashLoadItem(_FLASH_ITEMID_FACTORY_DATA, pData, 1) == _TRUE)
	{
		TPVNVRamSaveFactoryDate();
	}
	#endif
}
*/


#define BurnIn_On()				{\
							    SET_FACTORY_BURNIN(_ON);\
							    TPVNVRamSaveFactoryDate();\
								}
//--------------------------------------------------
#define BurnIn_Off()			{\
								SET_FACTORY_BURNIN(_OFF);\
								TPVNVRamSaveFactoryDate();\
								}


#define IIC_VGA_DDC_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, ((g_pucDdcciRxBuf[_DDC_LENGTH]-0x86)), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_VGA_DDC, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_DDC);\
								}

#define IIC_VGA_DDC_READ()		{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_VGA_DDC, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_DDC);\
                                }

#define IIC_DDC0_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC0, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_DDC);\
								}

#define IIC_DDC0_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC0, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_DDC);\
                                }

#define IIC_DDC1_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);\
								}

#define IIC_DDC1_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);\
                                }
#define IIC_DDC2_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);\
								}

#define IIC_DDC2_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);\
                                }
#define IIC_DDC3_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);\
								}

#define IIC_DDC3_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);\
                                }
#define IIC_DDC4_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC4, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_DDC);\
								}

#define IIC_DDC4_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC4, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_DDC);\
                                }
#define IIC_DDC5_WRITE()		{\
								ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_GPIO);\
								UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86), &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC5, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);\
								ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_DDC);\
								}

#define IIC_DDC5_READ()			{\
                                ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_GPIO);\
                                UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_pucDdcciRxBuf[_FC_BYTE6]+g_pucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC5, _SW_IIC_PIN_GPIO);\
                                ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_DDC);\
                                }



#define _EDID_ADDRESS_DP1   			_EDID_D1_ADDRESS_FLASH//_EDID_D0_ADDRESS_FLASH//0xA000
#define _EDID_ADDRESS_DP2   			_EDID_D1_ADDRESS_FLASH//0xB000

#define _EDID_ADDRESS_HDMI1             _EDID_D2_ADDRESS_FLASH
#define _EDID_ADDRESS_HDMI2             _EDID_D3_ADDRESS_FLASH

#ifndef _EDID_ADDRESS_DP3
#define _EDID_ADDRESS_DP3				_EDID_D6_ADDRESS_FLASH
#endif

#define _EDID_ADDRESS_MHL1				0xC000
#define _EDID_ADDRESS_MHL2				0xD000

#ifndef _EDID_ADDRESS_MHL3
#define _EDID_ADDRESS_MHL3				_EDID_D2_MHL_ADDRESS_FLASH
#endif
#ifndef _EDID_ADDRESS_MHL4
#define _EDID_ADDRESS_MHL4				_EDID_D3_MHL_ADDRESS_FLASH
#endif
#ifndef _EDID_ADDRESS_MHL5
#define _EDID_ADDRESS_MHL5				_EDID_D4_MHL_ADDRESS_FLASH
#endif
#ifndef _EDID_ADDRESS_MHL6
#define _EDID_ADDRESS_MHL6				_EDID_D5_MHL_ADDRESS_FLASH
#endif



#define DP_EDID_WT_ADR_DP1(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define DP_EDID_WT_ADR_DP2(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_DP2+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define DP_EDID_WT_ADR_DP3(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_DP3+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL1(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL1+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL2(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL2+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL3(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL3+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL4(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL4+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL5(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL5+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
#define MHL_EDID_WT_ADR_MHL6(ucDDCRam)	{\
											UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL6+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciRxBuf[_FC_BYTE8]);\
											memcpy(ucDDCRam+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), &g_pucDdcciRxBuf[_FC_BYTE8], (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86));\
										}
//3 GET EMBEDED EDID SELECT

#define DP_EDID_RDF_ADR_DP1()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define DP_EDID_RDF_ADR_DP2()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_DP2+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define DP_EDID_RDF_ADR_DP3()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_DP3+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL1()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL1+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL2()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL2+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL3()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL3+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL4()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL4+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL5()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL5+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}
#define MHL_EDID_RDF_ADR_MHL6()			{\
											UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_MHL6+((g_pucDdcciRxBuf[_FC_BYTE6]*0x100)+g_pucDdcciRxBuf[_FC_BYTE7]), 32, &g_pucDdcciTxBuf[_FC_BYTE2]);\
										}



//3  VGA Port (write to external EEPROM through DDC chanel)
//--------------------------------------------------
#define VGA_EDID_WRITE()		IIC_VGA_DDC_WRITE()
#define VGA_EDID_READ()		    IIC_VGA_DDC_READ()
//--------------------------------------------------//
//3 DVI Port (write to external EEPROM through DDC chanel)
//--------------------------------------------------//
#define DVI1_EDID_WRITE()		{}
#define DVI1_EDID_READ()		{}

#define DVI2_EDID_WRITE()		{}
#define DVI2_EDID_READ()		{}

//--------------------------------------------------//
//3 HDMI Port (write to external EEPROM through DDC chanel)
//--------------------------------------------------//
#if(_HDMI_24C02_SUPPORT)

#if(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)
#define HDMI1_EDID_WRITE()		IIC_DDC2_WRITE()
#define HDMI1_EDID_READ()		IIC_DDC2_READ()
#else
#define HDMI1_EDID_WRITE()		IIC_DDC1_WRITE()
#define HDMI1_EDID_READ()		IIC_DDC1_READ()
#endif


#else
#define HDMI1_EDID_WRITE()		{}
#define HDMI1_EDID_READ()		{}
#endif

#if(_HDMI_24C02_SUPPORT)
#if(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)
#define HDMI2_EDID_WRITE()		IIC_DDC3_WRITE()
#define HDMI2_EDID_READ()		IIC_DDC3_READ()
#else
#define HDMI2_EDID_WRITE()		{}
#define HDMI2_EDID_READ()		{}
#endif


#else
#define HDMI2_EDID_WRITE()		{}
#define HDMI2_EDID_READ()		{}

#endif



#define HDMI3_EDID_WRITE()		{}
#define HDMI3_EDID_READ()		{}

#define HDMI4_EDID_WRITE()		{}
#define HDMI4_EDID_READ()		{}
//--------------------------------------------------//
//3 DP Port (write to Flash and internel DDCRAM)
//--------------------------------------------------//
#if(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)
#define DP1_EDID_WRITE()		DP_EDID_WT_ADR_DP1(MCU_DDCRAM_D1)
#define DP1_EDID_READ()			DP_EDID_RDF_ADR_DP1()

#else
#define DP1_EDID_WRITE()		{}//DP_EDID_WT_ADR_DP1(MCU_DDCRAM_D1)
#define DP1_EDID_READ()			{}//DP_EDID_RDF_ADR_DP1()

#endif


#define DP2_EDID_WRITE()		{}//DP_EDID_WT_ADR_DP2()
#define DP2_EDID_READ()			{}//DP_EDID_RDF_ADR_DP2()

#define DP3_EDID_WRITE()		{}
#define DP3_EDID_READ()			{}

//--------------------------------------------------//
//3 MHL Port (write to Flash and internel DDCRAM)
//--------------------------------------------------//

#if(_D1_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)

///#define MHL1_EDID_WRITE()		MHL_EDID_WT_ADR_MHL1(MCU_DDCRAM_MHL_D2)
//#define MHL1_EDID_READ()		MHL_EDID_RDF_ADR_MHL1()
#endif

#if(_D2_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)

//#define MHL2_EDID_WRITE()		MHL_EDID_WT_ADR_MHL2(MCU_DDCRAM_MHL_D3)
//#define MHL2_EDID_READ()		MHL_EDID_RDF_ADR_MHL2()
#endif

#if(_D3_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)

//#define MHL3_EDID_WRITE()		{}
//#define MHL3_EDID_READ()		{}

#endif

#define MHL4_EDID_WRITE()		{}
#define MHL4_EDID_READ()		{}
//--------------------------------------------------//
//3 HDMI2.0 Port (write to external EEPROM through DDC chanel)
//--------------------------------------------------//
#define HDMI20_HDMI1_EDID_WRITE()		{}
#define HDMI20_HDMI1_EDID_READ()		{}

#define HDMI20_HDMI2_EDID_WRITE()		{}
#define HDMI20_HDMI2_EDID_READ()		{}

#define HDMI20_HDMI3_EDID_WRITE()		{}
#define HDMI20_HDMI3_EDID_READ()		{}

#define HDMI20_HDMI4_EDID_WRITE()		{}
#define HDMI20_HDMI4_EDID_READ()		{}



//----------------------------------------------------------------------------------------------------
// OSD Factory Data Function
//----------------------------------------------------------------------------------------------------
void TPVFCReplyEDIDPortData(void);
void TPVFCEDIDWriteData(void);
void TPVFCEDIDReadData(void);
void TPVFCReplyEDIDStatus(void);
WORD TPVFCCrc16(BYTE nData, WORD CRC);
void TPVFCReplyCommand(BYTE ucResult, BYTE ucLength);

//--------------------------------------------------
// Description  : Save factory data
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : TPV Factory Command DDCCI process
// Input Value  : None
// Output Value : TRUE: do Factory Command, FALSE: do nothing
//--------------------------------------------------

#define FC_EDID_EEPROM_WP_ENABLE()	{\
										PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);\
										PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);\
									}
#define FC_EDID_EEPROM_WP_DISABLE()	{\
										PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);\
										PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);\
									}

BYTE ucChkSumCalibration = 0xff;



#define FC_EDID_ERASE()			{\
								UserCommonFlashErasePage(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1/_FLASH_PAGE_SIZE);\
								}



#define _EDID_SN_LENTH                         13       
#define _EDID_SN_START_ADDRESS                 0x4d       

/*
extern void CobyHdmiEdidToDp(void);

void CobyHdmiEdidToDp(void)
{

	BYTE ucCount = 0;
	BYTE pucBuffer[16] = {0};
	BYTE EDID_DATA[16];
	BYTE j = 0;

    //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D0_ADDRESS_FLASH), _D0_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D1);

	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
	ScalerTimerDelayXms(1);	
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x10, 1, 2, EDID_DATA, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
	ScalerTimerDelayXms(1);	
	
    for(ucCount = 0; ucCount < 2; ucCount++)
         MCU_DDCRAM_D1[0x10+ucCount] = EDID_DATA[ucCount];// year week

	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
	ScalerTimerDelayXms(1);	
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, _EDID_SN_START_ADDRESS, 1, _EDID_SN_LENTH, EDID_DATA, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
	ScalerTimerDelayXms(1);	
	
   for(ucCount = 0; ucCount <_EDID_SN_LENTH; ucCount++)
         MCU_DDCRAM_D1[_EDID_SN_START_ADDRESS+ucCount] = EDID_DATA[ucCount];// sn

      j = 0;
				
     for(ucCount = 0; ucCount < 127; ucCount++)
	   j += MCU_DDCRAM_D1[ucCount];
			
      MCU_DDCRAM_D1[0x7f]=0x100-j;

#if 1//((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D1_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, MCU_DDCRAM_D1 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D0_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D0_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif
    
}
*/


//--------------------------------------------------
//DFM Mode
//--------------------------------------------------
//--------------------------------------------------
// Description  : DFM mode switch
//add to OSD OperationTable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMSet( bit bOnOff)
{
	if(bOnOff == _OFF)
	{
		SET_FACTORY_DFM_MODE(_PRODUCT_OFF);
		bProductModeFlag = _OFF;
	}
	else
	{
		SET_FACTORY_DFM_MODE(_PRODUCT_ON);
		bProductModeFlag = _ON;
	}
	TPVNVRamSaveFactoryDate();
}


//--------------------------------------------------
// Description  : DFM mode Initial
//                add to last line of UserInterfaceInitial(), just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMInitial(void)
{
	if(GET_FACTORY_DFM_MODE() == _PRODUCT_ON)
	{
		bProductModeFlag = _ON;
		FC_DFM_INITIAL();

		#if(_AUDIO_SUPPORT == _ON)
		FC_AUDIO_VOLUMN();
		#endif
	}
	else
	{
		bProductModeFlag = _OFF;
	}
	//AC ON Factory have to turn OFF//DFM rev02 patch note 2
//	SET_FACTORY_MODE(_OFF);
}

//--------------------------------------------------
// Description  : DFM mode reset to off
//add to bottom line of Factory Reset process ,just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if 0
void TPVDFMFactoryReset(void)
{
//DFM rev02 patch note 9>>
    if((TPVDFMModeFlag()==_ON) || (GET_FACTORY_BURNIN() == _ON))
    {
/*		if(bProductModeFlag == _ON)//Duncan 141111 reset by DFM mode
		{
			BACKLIGHTTIME_INITIAL();//(DFM rev6 patch note 6)
		}
*/
//        SET_FACTORY_BURNIN(_OFF);//by jerry DFM rev02 patch note 3
		TPVDFMSet(_OFF);
		//NVRamRestorePanelUsedTimeData();
	}
//DFM rev02 patch note 9<<
}
#endif
//--------------------------------------------------
// Description  : DFM mode flag Check
//for check DFM status check , Call many times depend on project
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMModeFlag(void)
{
	return bProductModeFlag;
}

#if 0
	
bit TPVDFMCableWPCheck(void)
{
	BYTE ucCable_Status = 0x00;


#if(_MIRACAST_SUPPORT == _ON)
	//ucCable_Status = PCB_GET_WITHOUT_MIRACAST_CABLE_STATUS();
#else
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_A0_INPUT_PORT);
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D0_INPUT_PORT);
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D1_INPUT_PORT);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D2_INPUT_PORT);
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D3_INPUT_PORT);
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D4_INPUT_PORT);
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D5_INPUT_PORT);
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D6_INPUT_PORT);
#endif
#endif//#if(_MIRACAST_SUPPORT == _ON)

	if(1)//(ucCable_Status == 0)//all cable disconnect
	{
#if 0
		ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());

//else
		
	#if(DFM_DDC_WRITE_PORT == _DFM_D0_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_D0_INPUT_PORT);
#elif(DFM_DDC_WRITE_PORT == _DFM_D1_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_D1_INPUT_PORT);
#elif(DFM_DDC_WRITE_PORT == _DFM_D2_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_D2_INPUT_PORT);
#elif(DFM_DDC_WRITE_PORT == _DFM_A0_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_A0_INPUT_PORT);
	#endif
#endif


#if 0//((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
		if(TPVDFMModeFlag()== _ON)
		{
			if((TPVDFMModeFlag()== _ON)&&((GET_VGA_EDID_CHECK()==_TRUE)||(GET_DVI_EDID_CHECK()==_TRUE)||(GET_HDMI_EDID_CHECK()==_TRUE))&&(bEDID2EEPROM_OVERWRITE==_FALSE))
			{
				CTPVFCReloadEdid();
			}
			FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		}
		else
#endif
		{
//			FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		}
//DFM rev03 patch note 3<<
//DFM rev02 patch note 7>>
		if(DFM_BURN_IN() == _ON)
		{
			ScalerDDomainBackgroundEnable(_ENABLE);
			ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

		 if(ScalerOsdGetOsdEnable()==_DISABLE)
		 {
			 RTDBurnInMenu();
		 }	 
			  
		FactoryBurnInEvent();
		
#if(_MPRT_SUPPORT == _ON)
#if(_BACKLIGHT_PWM_INVERSE == _ON)
			PCB_BACKLIGHT_PWM(255 - _MPRT_BACKLIGHT_PWM_MAX);
#else
			PCB_BACKLIGHT_PWM(_MPRT_BACKLIGHT_PWM_MAX);
#endif
#else
			UserAdjustBacklight(_BACKLIGHT_MAX);
#endif
			UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
			UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);//Duncan 140120 fix burn in LED
			return _TRUE;
		}
		if((bProductModeFlag == _ON)&&(DFM_BURN_IN() == _OFF))
		{
			TIMER_NOCABLE();
			return _TRUE;
		}
//DFM rev02 patch note 7<<
	}
	else //anyone connected
	{
	//	FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
	}

	//fast enter Powersaving
	if(bProductModeFlag == _ON)
	{
#if(_MIRACAST_SUPPORT == _ON)
		if((SysSourceGetInputPort() == _MIRACAST_DONGLE_PORT))
		{
			return _FALSE;		// Eason 20130903 for Miracast don't go to power saving
		}
		else
		{
			TIMER_SAVING();
			return _TRUE;
		}

#else
		//TIMER_NOSIGNAL();
		TIMER_SAVING();
		return _TRUE;
#endif
	}
	else
	{
		return _FALSE;
	}

	return _FALSE;//DFM rev02 patch note 7
}


#endif

// Delay 50~1000 us
#define DELAY_XUS(N)                        {\
                                                g_ucDelayXus_Counter = (N) >> 2;\
                                                do\
                                                {\
                                                    DELAY_XUS_BASE();\
                                                }\
                                                while(--g_ucDelayXus_Counter);\
                                            }

bit TPVFCmdFactoryCommand(void)
	{
	#if 0//(_TC_ENABLE_TRUECOLOR == _ON)
			BYTE ucSNLength = 0;
			BYTE TempCount0 = 0;
			BYTE Temp0 = 0;
	#endif
		
			if(g_pucDdcciRxBuf[_FC_BYTE3] != CMD_FC_TPVFactory)
			{
				return _FALSE;
			}
		ScalerMcuDdcciReleaseScl();
    #if 0//(_THEFT_MODE == _ON)
			if((g_pucDdcciRxBuf[_FC_BYTE3] == CMD_FC_TPVFactory)&&(g_pucDdcciRxBuf[_DDC_LENGTH] <= 0x82)&&((g_pucDdcciRxBuf[_FC_BYTE2] == _DDCCI_CMD_GET_VCP_FEATURE)))
			{
				return _FALSE;
			}
   	#endif
		
		// TPV	factory command
			if(g_pucDdcciRxBuf[_FC_BYTE2] == _DDCCI_CMD_SET_VCP_FEATURE)
			{
				switch(g_pucDdcciRxBuf[_FC_BYTE4])
				{
		//--------0x14
					case VCP_FC_SAVE_COLORTEMP:
						break;
			#if 1//((_TC_ENABLE_TRUECOLOR == _OFF) && (_OGC_SUPPORT == _OFF))//disable when fga or ogc support for TPV reauest.
		//--------0x16
					case VCP_FC_ADJUST_R_GAIN:
						break;
		//--------0x18
					case VCP_FC_ADJUST_G_GAIN:
						break;
		//--------0x1A
					case VCP_FC_ADJUST_B_GAIN:
						break;
			#endif
		//--------0x12
					case VCP_FC_ADJUST_CONTRAST:
						break;
		//--------0x10
					case VCP_FC_ADJUST_BL_BRIGHTNESS:
						break;
		//--------0xDC
		//--------0x04
					case VCP_FC_RESET:
						
						break;
		//--------0x1F
					case VCP_FC_AUTO_LEVEL:
		
						break;
		//--------0x1E
					case VCP_FC_AUTO_ADJUST:
		
		
						break;
		//--------0xCC
					case VCP_FC_SET_LANGUAGE:
		
						break;
		//--------0x60
					case VCP_FC_SET_SOURCE:
		
		
						break;
		//--------0xD6
					case VCP_FC_ENTER_POWERSAVING:
						break;
		//--------0xE2
					case VCP_FC_Code02://ADC gain/offset
						break;
		//--------0xE1
					case VCP_FC_Code01:
						switch(g_pucDdcciRxBuf[_FC_BYTE5])
						{
		//--------0xE1-[0xA0]
							case SUB_VCP_FC_FACTORY_MODE_A0:
								
								if(g_pucDdcciRxBuf[_FC_BYTE6]==0x00)
								{
									if(g_pucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_EXIT_FACTORY_MODE)
									{
												SET_FACTORY_MODE(_OFF);
												TPVNVRamSaveFactoryDate();
									}
									else if(g_pucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_ENTER_FACTORY_MODE)
									{
												SET_FACTORY_MODE(_OFF);
												TPVNVRamSaveFactoryDate();



												RTDNVRamSaveOSDData();
									}
										
										TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);
								}
								
								break;
		
		//DFM rev05 patch note 5>>
		//--------0xE1-[0xA1]
							case SUB_VCP_FC_NVRAW_RESTORE_A1:
		
								break;
		//DFM rev05 patch note 5>>
		
		//--------0xE1-[0xA2]
							case SUB_VCP_FC_FACTORY_MODE_A2://4
								if(g_pucDdcciRxBuf[_FC_BYTE6] == 0x00)
								{
									if (g_pucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_SET_BURNIN_OFF)
									{
										BurnIn_Off();
									}
									else if(g_pucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_SET_BURNIN_ON)
									{
										BurnIn_On();
									}
		
									TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);
								}
								else if(g_pucDdcciRxBuf[_FC_BYTE6] == 0x01)
								{
									if(g_pucDdcciRxBuf[_FC_BYTE7] == SUB1_VCP_FC_SET_WR_END)//	edid  操作完成
									{
		
		//DFM rev02 patch note 8>>
										FC_EDID_EEPROM_WP_ENABLE();
													  ucChkSumCalibration |= _BIT0;
													  
								//		if (DFM_BURN_IN() == _ON)
								//		{
									ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BURN_IN_DDCTOOL);
		
								//		}
		
													 //  if((SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) && (DFM_BURN_IN() == _ON))
										//{
										//ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BURN_IN);
		
										//	}
		
										//if(SysModeGetModeState() != _MODE_STATUS_DISPLAY_CHECK)
										//{
											//SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
											//SET_FORCE_POW_SAV_STATUS(_FALSE);
										//}
		//DFM rev02 patch note 8<<
									}
									else if(g_pucDdcciRxBuf[_FC_BYTE7] == SUB1_VCP_FC_SET_WR_START)//  开始准备写EDID
									{
		
								#if ((_DP_SUPPORT == _ON) || (_MHL_SUPPORT == _ON))
																  FC_EDID_ERASE();
								#endif
		//DFM rev02 patch note 8>>
										FC_EDID_EEPROM_WP_DISABLE();
		
										//		  if(DFM_BURN_IN() == _ON)
										//			   {
										 // 		  ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BURN_IN);
										   ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BURN_IN_DDCTOOL);
											
										 // 		}
		
										
		//DFM rev06 patch note 1 >> turn on Power when	writing EDID through DDC channel
									//	if(SysPowerGetPowerStatus() == _POWER_STATUS_SAVING)
										//	SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
		//DFM rev06 patch note 1<<
										//if(SysModeGetModeState() != _MODE_STATUS_DISPLAY_CHECK)
										//{
											//SysModeSetResetTarget(_MODE_ACTION_RESET_TO_FACTORY_MODE);
											//SET_FORCE_POW_SAV_STATUS(_TRUE);
										//}
		//DFM rev02 patch note 8<<
									}
		
									TPVFCReplyEDIDPortData();
								}
#if 0//((_TMDS_HDCP_2_2_SUPPORT == _ON) || (_DP_HDCP_2_2_SUPPORT == _ON))
								else if(g_pucDdcciRxBuf[_FC_BYTE6] == 0x02)
								{
									if(g_pucDdcciRxBuf[_FC_BYTE7] == 0x01)//_ON
									{
										bAocFactoryHdcp22WriteStart = _TRUE;
										HDCP22_START();
									}
									else//if(g_pucDdcciRxBuf[_FC_BYTE7]== 0x00)_OFF
									{
										bAocFactoryHdcp22WriteStart = _FALSE;
									}
								}
#endif
								break;

		
		//--------0xE1-[0xA3]
							case SUB_VCP_FC_FACTORY_MODE_A3:
						//		BACKLIGHTTIME_INITIAL();
								TPVFCReplyCommand(_REPLY_RESULT_02,_AWB_COMMAND_LEN_CRC);
								break;
		//--------0xE1-[0xA4]
							case SUB_VCP_FC_FACTORY_MODE_A4:
								break;
		
		//--------0xE1-[0xA5]
							case SUB_VCP_FC_FACTORY_MODE_A5:
								
								break;
		//--------0xE1-[0xA6]
							case SUB_VCP_FC_FACTORY_MODE_A6:
								//reserve for IIC switch
								break;
		//--------0xE1-[0xA7]
							case SUB_VCP_FC_FACTORY_MODE_A7:
		
								break;
#if 0//(_PANEL_VCOM_ADJUST_FUNCTION == _ON)
		//--------0xE1-[0xA9]
							case SUB_VCP_FC_FACTORY_MODE_A9:
								if(g_pucDdcciRxBuf[_FC_BYTE6]==0x00)
								{
									SET_FACTORY_VCOM(g_pucDdcciRxBuf[_FC_BYTE7]);
									SET_SW_IIC_STATUS(_I2C_LINE_PANEL);
		
							#if((_PANEL_VCOM_TYPE == _PANEL_VCOM_TYPE_2)||(_PANEL_VCOM_TYPE == _PANEL_VCOM_TYPE_3))
									PDATA_WORD(0) = GET_FACTORY_VCOM() + _PANEL_VCOM_OFFSET;
									ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS,1,_PANEL_VCOMREF_SUB_ADDRESS,2,pData);
		
							#else
									pData[0] = 0x00;
									ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x02, 1, &pData[0]);
									pData[0] = GET_FACTORY_VCOM();
									ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x00, 1, &pData[0]);
							#endif
		
									SET_SW_IIC_STATUS(_I2C_LINE_NVRAM);
									TPVNVRamSaveFactoryDate();
								}
								break;
#endif
		//--------0xE1-[0xE0]
						//	case SUB_VCP_FC_SET_HDCP_WRITE_START_RX:
						//		break;
		//--------0xE1-[0xE1]
						//	case SUB_VCP_FC_SET_HDCP_WRITE_START_TX:
						//		break;
						}
						break;
		
		//--------0xE8 FOR WUHAN FGA TOOL WRITE SN by 3 times
#if 0//(_TC_ENABLE_TRUECOLOR == _ON)
					case VCP_FC_Code08:
						ucSNLength = (g_pucDdcciRxBuf[_DDC_LENGTH]-0x84);
						Temp0 = (g_pucDdcciRxBuf[5]&0x03)*6;
						for(TempCount0=0; TempCount0<ucSNLength; TempCount0++)
						{
							pData[TempCount0+Temp0] = g_pucDdcciRxBuf[ 6 + TempCount0 ];
						}
		
						if(g_pucDdcciRxBuf[5] == 0x02)
						{
							for(TempCount0=13; TempCount0>3; TempCount0--)
							{
								pData[TempCount0] = pData[TempCount0-1];
							}
							pData[TempCount0] = 0x41;
							RTDNVRamSaveSNData();
						}
						break;
#endif
		
		//--------0xEA
					case VCP_FC_Code0A:
						break;
		//--------0xEA
					case VCP_FC_Code13:
						break;
		//--------0xEF
					case VCP_FC_Code0F://写EDID
					
						
						TPVFCEDIDWriteData();
		
						break;
		
			#if 0//(_TC_ENABLE_TRUECOLOR == _ON)
					case VCP_FC_FGA_PATTERN_OUT:
						DdcciFGAPatternOutput();
		
						break;
			#endif
		
					default:
						break;
				}
			}
			else if((g_pucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_GET_VCP_FEATURE))
			{
				if((g_pucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code01)&&(g_pucDdcciRxBuf[_FC_BYTE5]== SUB_VCP_FC_READ_HDCP_CRC))
				{
					//TPVFCHdcpCrcCheck();
					//SysPowerRecoverHDCPKey();//need to confirm
				}
#if 0//(_PANEL_VCOM_ADJUST_FUNCTION == _ON)
				else if((g_pucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code01)&&(g_pucDdcciRxBuf[_FC_BYTE5]== SUB_VCP_FC_FACTORY_MODE_A9))
				{
					g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
					g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
					g_pucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
					g_pucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
					g_pucDdcciTxBuf[_DDCCI_SINK_OPCODE] = CMD_FC_TPVFactory;
					UserCommonDdcciSetVCPReplyValue(0x01, GET_FACTORY_VCOM(), 0);
					g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
				}
#endif
				else if(g_pucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code0F)
				{
					TPVFCEDIDReadData();
				}
		#if 0//(_TPV_FACTORY_SENSOR_TEST_SUPPORT == _ON)
				else if(g_pucDdcciRxBuf[_FC_BYTE4]== VCP_FC_ADJUST_BL_BRIGHTNESS)
				{
					g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
					g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
					g_pucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
					g_pucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
					g_pucDdcciTxBuf[_DDCCI_SINK_OPCODE] = CMD_FC_TPVFactory;
					g_usBackupValue=UserCommonAdjustRealValueToPercent(PCB_GET_BACKLIGHT_PWM(), MAX(_BACKLIGHT_MAX_PWM), MIN(_BACKLIGHT_MIN_PWM), CENTER(_BACKLIGHT_MIN_PWM+(_BACKLIGHT_MAX_PWM-_BACKLIGHT_MIN_PWM)/2));
					UserCommonDdcciSetVCPReplyValue(0x01, _BACKLIGHT_MAX, g_usBackupValue);
					g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
				}
		#endif
			}
			else if((g_pucDdcciRxBuf[_FC_BYTE4]== 'R')&&(g_pucDdcciRxBuf[_FC_BYTE5]== 'E')\
			&&(g_pucDdcciRxBuf[_FC_BYTE6]== 'D')&&(g_pucDdcciRxBuf[_FC_BYTE7]== 'I')&&(g_pucDdcciRxBuf[_FC_BYTE8]== 'D'))
			{
				TPVFCReplyEDIDStatus();
			}
		
			return _TRUE;
		}


//--------------------------------------------------
// Description  : TPV Factory Command save Color Temp.
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : TPV Factory Command set language
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////
//- 0x00 = Reserved, must be ignored
//- 0x01 = Chinese (traditional / Hantai)    - 0x02 = English    	- 0x03 = French 	- 0x04 = German
//- 0x05 = Italian                     	- 0x06 = Japanese   		- 0x07 = Korean 	- 0x08 = Portuguese (Portugal)
//- 0x09 = Russian						- 0x0A = Spanish (Espanol)  - 0x0B = Swedish	- 0x0C = Turkish
//- 0x0D = Chinese (simplified / Kantai)      - 0x0E = Portuguese (Brazil)    - 0x0F = Arabic           - 0x10 = Bulgarian
//- 0x11 = Croatian                 	- 0x12 = Czech  			- 0x13 = Danish 	- 0x14 = Dutch (Netherlands)
//- 0x15 = Estonian                 	- 0x16 = Finnish    		- 0x17 = Greek  	- 0x18 = Hebrew
//- 0x19 = Hindi                    	- 0x1A = Hungarian  		- 0x1B = Latvian    - 0x1C = Lithuanian
//- 0x1D = Norwegian                    - 0x1E = Polish 			- 0x1F = Romanian	- 0x20 = Serbian
//- 0x21 = Slovak                       - 0x22 = Slovenian			- 0x23 = Thai     	- 0x24 = Ukrainian
//- 0x25 = Vietnamese
/////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------
// Description  : TPV Factory Command enter power saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description  : TPV Factory Command reply EDID port
// 				AOC Factory tool will detect this return value to determind EDID write procedure
//				VCP TPVPORT1: {VGA1=BIT7,VGA2=BIT6,DVI1=BIT5,DVI2=BIT4,HDMI1=BIT3,HDMI2=BIT2,DP1=BIT1,DP2=BIT0}
//				VCP TPVPORT2: {HDMI3=BIT7,HDMI4/Option Port=BIT6,MHL_HDMI=BIT5,MHL_HMDI2=BIT4,MHL_HDMI3=BIT3,MHL_HDMI4=BIT2,BIT1:0-Write Disable,1-Write Enable,BIT0:0-EDID in EEPROM,1-EDID in FLASH}
//				VCP TPVPORT3: {HDMI2.0_HDMI1=BIT7,HDMI2.0_HDMI2=BIT6,HDMI2.0_HDMI3=BIT5,HDMI2.0_HDMI4=BIT4,DP3=BIT3}
//				Sample(_HDMI_SUPPORT == _ON):g_pucDdcciTxBuf[3] = (_BIT7 |_BIT5 |_BIT3);	 // VGA1 DVI1 HDMI1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCReplyEDIDPortData(void)
{
	g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
	g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x04;
	g_pucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
	g_pucDdcciTxBuf[3] = 0x00; //VCP TPVPORT1
	g_pucDdcciTxBuf[4] = 0x00; //VCP TPVPORT 2
	g_pucDdcciTxBuf[5] = 0x00; //VCP TPVPORT 3

	if(_DFM_VGA_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT7);    // VGA1

	if(_DFM_DVI1_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT5);    //  DVI1

	if(_DFM_DVI2_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT4);    //  DVI2

	if(_DFM_HDMI1_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT3);    //  HDMI1

	if(_DFM_HDMI2_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT2);    //  HDMI2

	if(_DFM_DP1_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT1);    //DP

#if 0//(_DP_MULTI_EDID_SUPPORT == _ON)
	if((_DFM_DP2_PORT != _NO_INPUT_PORT)||(_DP_FREESYNC_SUPPORT == _ON))
		g_pucDdcciTxBuf[3] |= (_BIT0);    //DP2 and free sync
#else
	if(_DFM_DP2_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT0);    //DP2
#endif

//-------------------------------------------------------------
	if(_DFM_HDMI3_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[4] |= (_BIT7);	 //HDMI3

	if(_DFM_HDMI4_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[4] |= (_BIT6);	 //HDMI4

	if(_DFM_MHL1_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[4] |= (_BIT5);	 //MHL1

	if(_DFM_MHL2_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[4] |= (_BIT4);	 //MHL2

	if(_DFM_MHL3_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT3);    //MHL3

	if(_DFM_MHL4_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[3] |= (_BIT2);    //MHL4

//-------------------------------------------------------------
	if(_DFM_HDMI20_HDMI1_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[5] |= (_BIT7);    //HDMI20 HDMI1

	if(_DFM_HDMI20_HDMI2_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[5] |= (_BIT6);    //HDMI20 HDMI2

	if(_DFM_HDMI20_HDMI3_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[5] |= (_BIT5);    //HDMI20 HDMI3

	if(_DFM_HDMI20_HDMI4_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[5] |= (_BIT4);    //HDMI20 HDMI4

	if(_DFM_DP3_PORT != _NO_INPUT_PORT)
		g_pucDdcciTxBuf[5] |= (_BIT3);    //DP3

	g_pucDdcciTxBuf[4] |= ((g_pucDdcciRxBuf[_FC_BYTE7]==_ON) ? _BIT1 : 0x00 );//Status {BIT0 (0:EEPROM;1:FLASH)  BIT1(0:Disable;1:Enable)  BIT2~BIT7=>(reversed)}
    g_pucDdcciTxBuf[6] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
}





//--------------------------------------------------
// Description  : TPV Factory Command HDCP data write
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_CTX_TPV==_OFF)
void TPVFCEDIDWriteData(void)
{
	BYTE ucEdidLength = (g_pucDdcciRxBuf[_DDC_LENGTH]-0x86);//32;///DFM rev03 patch note 1

    switch(g_pucDdcciRxBuf[_FC_BYTE5])
    {
		case SUB_VCP_FC_VGA1_EDID:
			VGA_EDID_WRITE();
			break;

        case SUB_VCP_FC_DVI1_EDID:
			DVI1_EDID_WRITE();
	        break;

        case SUB_VCP_FC_DVI2_EDID:
			DVI2_EDID_WRITE();
	        break;

        case SUB_VCP_FC_HDMI1_EDID:
			HDMI1_EDID_WRITE();

			
	        break;

        case SUB_VCP_FC_HDMI2_EDID:
			HDMI2_EDID_WRITE();
	        break;

        case SUB_VCP_FC_HDMI3_EDID:
			HDMI3_EDID_WRITE();
	        break;

        case SUB_VCP_FC_HDMI4_EDID:
			HDMI4_EDID_WRITE();
	        break;

        case SUB_VCP_FC_DP1_EDID:

		DP1_EDID_WRITE();
	        break;

        case SUB_VCP_FC_DP2_EDID:
			DP2_EDID_WRITE();
	        break;

		case SUB_VCP_FC_DP3_EDID:
			DP3_EDID_WRITE();
			break;

		case SUB_VCP_FC_MHL1_EDID:
	//		MHL1_EDID_WRITE();
	        break;

		case SUB_VCP_FC_MHL2_EDID:
	//		MHL2_EDID_WRITE();
	        break;

		case SUB_VCP_FC_MHL3_EDID:
		//	MHL3_EDID_WRITE();
	        break;

		case SUB_VCP_FC_MHL4_EDID:
			MHL4_EDID_WRITE();
	        break;

		case SUB_VCP_FC_HDMI20_HDMI1_EDID:
			HDMI20_HDMI1_EDID_WRITE();
			break;

		case SUB_VCP_FC_HDMI20_HDMI2_EDID:
			HDMI20_HDMI2_EDID_WRITE();
			break;

		case SUB_VCP_FC_HDMI20_HDMI3_EDID:
			HDMI20_HDMI3_EDID_WRITE();
			break;

		case SUB_VCP_FC_HDMI20_HDMI4_EDID:
			HDMI20_HDMI4_EDID_WRITE();
			break;

		case SUB_VCP_FC_VGA2_EDID:
			break;

		case SUB_VCP_FC_EEPROM:
			break;

		case SUB_VCP_FC_HDCP1:
			break;

		case SUB_VCP_FC_HDCP2:
#if 0//((_TMDS_HDCP_2_2_SUPPORT == _ON) ||(_DP_HDCP_2_2_SUPPORT == _ON))
			HDCP22_WRITE();
#endif
		    break;

		case SUB_VCP_FC_OSDSN:

			//memcpy(&Visonic_Sn,&g_pucDdcciRxBuf[_FC_BYTE8],_SN_NUMBER_AMOUNT);

			memcpy(&g_stSNData,&g_pucDdcciRxBuf[_FC_BYTE8],_SN_NUMBER_AMOUNT);

			//RTDNVRamSaveSNData();
			
		    break;
		case SUB_VCP_FC_OSDMODELNAME:

        default:
	        break;
    }
    g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x03;
    g_pucDdcciTxBuf[2] = g_pucDdcciRxBuf[_FC_BYTE6];
    g_pucDdcciTxBuf[3] = g_pucDdcciRxBuf[_FC_BYTE7];
    g_pucDdcciTxBuf[4] = ucEdidLength;//DFM rev03 patch note 1
    g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : TPV Factory Command EDID Read
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCEDIDReadData(void)
{

    switch(g_pucDdcciRxBuf[_FC_BYTE5])
    {
		case SUB_VCP_FC_VGA1_EDID:
			VGA_EDID_READ();
            break;

        case SUB_VCP_FC_DVI1_EDID:
			DVI1_EDID_READ();
            break;

        case SUB_VCP_FC_DVI2_EDID:
			DVI2_EDID_READ();
            break;

        case SUB_VCP_FC_HDMI1_EDID:
			HDMI1_EDID_READ();
            break;

		case SUB_VCP_FC_HDMI2_EDID:
			HDMI2_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI3_EDID:
			HDMI3_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI4_EDID:
			HDMI4_EDID_READ();
			break;

        case SUB_VCP_FC_DP1_EDID:
			DP1_EDID_READ();
            break;

        case SUB_VCP_FC_DP2_EDID:
			DP2_EDID_READ();
            break;

		case SUB_VCP_FC_DP3_EDID:
			DP3_EDID_READ();
            break;

		case SUB_VCP_FC_MHL1_EDID:
		//	MHL1_EDID_READ();
			break;

		case SUB_VCP_FC_MHL2_EDID:
		//	MHL2_EDID_READ();
			break;

		case SUB_VCP_FC_MHL3_EDID:
		//	MHL3_EDID_READ();
			break;

		case SUB_VCP_FC_MHL4_EDID:
			MHL4_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI20_HDMI1_EDID:
			HDMI20_HDMI1_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI20_HDMI2_EDID:
			HDMI20_HDMI2_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI20_HDMI3_EDID:
			HDMI20_HDMI3_EDID_READ();
			break;

		case SUB_VCP_FC_HDMI20_HDMI4_EDID:
			HDMI20_HDMI4_EDID_READ();
			break;

        case SUB_VCP_FC_OSDSN:

			//memcpy(&g_pucDdcciTxBuf[_FC_BYTE2],&Visonic_Sn,_SN_NUMBER_AMOUNT);
			memcpy(&g_pucDdcciTxBuf[_FC_BYTE2],&g_stSNData,_SN_NUMBER_AMOUNT);
            break;

        default:
            break;
    }

    g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;

	if((g_pucDdcciRxBuf[_FC_BYTE5]) == SUB_VCP_FC_OSDSN)
		g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | _SN_NUMBER_AMOUNT;//12 Cytes
	else
    	g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x20;//32 bytes
    g_pucDdcciTxBuf[(g_pucDdcciTxBuf[_DDC_LENGTH] & 0x7f) + 2] = UserCommonDdcciCalCheckSum();
    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

}
#endif

// 20111220 by jerry, <<
//===================================
//REDIDWAY = 52 45 44 49 44 57 41 59
//Sending Command is REDIDWAY "51 8A 01 FE 52 45 44 49 44 57 41 59"
//IDFLH = 49 44 46 4C 48
//Received data is IDFLH "6E 88 02 00 FE 49 44 46 4C 48 05"
//IDXPP = 49 44 58 50 50
//Received data is IDXPP "6E 88 02 00 FE 49 44 58 50 50 1F"
//===================================
void TPVFCReplyEDIDStatus(void)
{
	g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
	g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
	g_pucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
	g_pucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
	g_pucDdcciTxBuf[_DDCCI_SINK_OPCODE] = CMD_FC_TPVFactory;
#if 1
	g_pucDdcciTxBuf[5]='I';
	g_pucDdcciTxBuf[6]='D';
	g_pucDdcciTxBuf[7]='X';
	g_pucDdcciTxBuf[8]='P';
	g_pucDdcciTxBuf[9]='P';
#else
	g_pucDdcciTxBuf[5]='I';
	g_pucDdcciTxBuf[6]='D';
	g_pucDdcciTxBuf[7]='F';
	g_pucDdcciTxBuf[8]='L';
	g_pucDdcciTxBuf[9]='H';
#endif
	g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
	ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : TPV Factory Command CRC calculation for HDCP
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : TPV Factory Command CRC calculation
// Input Value  : None
// Output Value : CRC
//--------------------------------------------------
WORD TPVFCCrc16(BYTE nData, WORD nCRC)
{
    BYTE nMask;
    bit fFeedback;
    for (nMask= 0x80; nMask; nMask >>= 1)
    {
        fFeedback= (bit)(((nCRC & 0x8000) ? 1 : 0) ^ ((nMask & nData) ? 1 : 0));
        nCRC <<= 1;
        if (fFeedback)
        {
            nCRC ^= 0x1021;
        }
    }

    return nCRC;
}

//--------------------------------------------------
// Description  : TPV Factory Command Tx command
// Input Value  : None
// Output Value : checksum
//--------------------------------------------------
void TPVFCReplyCommand(BYTE ucResult, BYTE ucLength)
{
    WORD usCRC = 0;
    BYTE i = 0;

    for(i = 0; i < ucLength; i++ )
    {
        usCRC = TPVFCCrc16(g_pucDdcciRxBuf[_FC_BYTE4 + i], usCRC);
    }

    g_pucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_pucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x03;
    g_pucDdcciTxBuf[_DDCCI_COMMAND] = ucResult;
    g_pucDdcciTxBuf[3] = (BYTE)((usCRC&0xff00)>>8);
    g_pucDdcciTxBuf[4] = (BYTE)(usCRC&0x00ff);
    g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
}



#if(_CTX_TPV)

#if (_ENABLE_WRITE_EDID_CTX==_ON)

typedef enum
{
    FCMD_VGA1_EDID = _BIT7,
    FCMD_DVI1_EDID = _BIT6,
    FCMD_HDMI1_EDID = _BIT5,
    FCMD_DP1_EDID = _BIT4,
    FCMD_VGA2_EDID = _BIT3,
    FCMD_DVI2_EDID = _BIT2,
    FCMD_HDMI2_EDID = _BIT1,
    FCMD_DP2_EDID = _BIT0,
    FCMD_HDMI3_EDID = _BIT7,
    FCMD_HDMI4_EDID = _BIT6,
    FCMD_HDMI1_14_EDID = _BIT5,
    FCMD_HDMI1_20_EDID = _BIT4,
    FCMD_TYPE_C1_EDID = _BIT3,
    FCMD_TYPE_C2_EDID = _BIT7,
} drvFactoryInputPortEDID;



typedef enum
{
    DEVICE_VGA = 0,    // 0
    DEVICE_DVI1,        // 1
    DEVICE_HDMI1,   // 2
    DEVICE_DP1,         // 3
    DEVICE_VGA2,        // 4
    DEVICE_DVI2,        // 5
    DEVICE_HDMI2,   // 6
    DEVICE_DP2,         // 7
    DEVICE_HDMI3,   // 8
    DEVICE_HDMI4,   //9
    DEVICE_MHL,         // A
    DEVICE_MHL2,        // B

    DEVICE_EEPROM = 0x10,
    DEVICE_HDCP1,
    DEVICE_HDCP2,
    DEVICE_OSDSN,
    DEVICE_OSDMODELNAME,

    DEVICE_HDMI1_HDMI20=0x40,
    DEVICE_HDMI2_HDMI20=0x41,
    DEVICE_HDMI3_HDMI20=0x42,

    DEVICE_NUMS = 0xFF
} drvFactoryDeviceType;


 //BYTE xdata DDC1[384];

#if _HDMI_24C02_SUPPORT == _OFF
#error "Please check _EDID_ADDRESS_HDMI2,_EDID_ADDRESS_HDMI2 and _EDID_ADDRESS_HDMI3 and _EDID_ADDRESS_DP1 must not be same flash page!!"
#endif 

void TPVFCEDIDWriteData()
{
		 BYTE ucEdidLength = (g_pucDdcciRxBuf[1]-0x86);//32;///DFM rev03 patch note 1
		 WORD Index;
		 Index = g_pucDdcciRxBuf[6]*256 + g_pucDdcciRxBuf[7];

		 switch(g_pucDdcciRxBuf[5])
		 {

			 case DEVICE_VGA:
#if 	_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
			 UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_A0_ADDRESS_FLASH+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
#else
            PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
			ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_GPIO);
			ScalerTimerDelayXms(10); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_VGA_DDC, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
			ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_DDC);
			PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
#endif

              break;
			 case DEVICE_HDMI2:
#if _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
		#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
	            memcpy(MCU_DDCRAM_D1+ Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
		#else
				PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
				PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
		#endif
#else
	#if(_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
        UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI2+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
        memcpy(MCU_DDCRAM_D3+ Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
	#else
		PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
		ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
		ScalerTimerDelayXms(10); 
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
		ScalerTimerDelayXms(10);
		PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
	#endif
#endif
				   break;

			 case DEVICE_HDMI1:

#if(_PCB_TYPE==_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS || _PCB_TYPE == _RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)

#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
	            memcpy(MCU_DDCRAM_D1+ Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#else
				PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
				PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
#endif


#elif _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
	#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
	            memcpy(MCU_DDCRAM_D3+ Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
	#else
				PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
				PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
	#endif
#else

#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, ucEdidLength,  &g_pucDdcciRxBuf[8]);
	            memcpy(MCU_DDCRAM_D3+ Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#else
				PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, Index, 1, ucEdidLength, &g_pucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
				PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);
#endif

#endif
				
				   break;

			 case DEVICE_DP1:
#if _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
	#if(_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)	 
			UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+Index, ucEdidLength, &g_pucDdcciRxBuf[8]);
			memcpy(MCU_DDCRAM_D0+Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
	#endif	 
#else
	#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)	 
				UserCommonFlashWrite(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+Index, ucEdidLength, &g_pucDdcciRxBuf[8]);
				memcpy(MCU_DDCRAM_D1+Index, &g_pucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
	#endif	 
#endif
	 			break;
			 case 0xA0:
				
				 break;
				 
			 case 0x14:
			 default:
				 break;
		 }
		 
		 g_pucDdcciTxBuf[0] = 0x6E;
		 g_pucDdcciTxBuf[1] = 0x80 | 0x03;
		 g_pucDdcciTxBuf[2] = g_pucDdcciRxBuf[6];
		 g_pucDdcciTxBuf[3] = g_pucDdcciRxBuf[7];
		 g_pucDdcciTxBuf[4] = (ucEdidLength);//DFM rev03 patch note 1
		 g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		 ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

 }


void TPVFCEDIDReadData()
{
		 WORD Index;
		 Index = g_pucDdcciRxBuf[6]*256 + g_pucDdcciRxBuf[7];

		 switch(g_pucDdcciRxBuf[5])
		 {
			case DEVICE_VGA:
#if 	_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
			UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_A0_ADDRESS_FLASH+Index, 0x20,  &g_pucDdcciTxBuf[2]);
#else
			ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_GPIO);
			ScalerTimerDelayXms(10); 
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_VGA_DDC, _SW_IIC_PIN_GPIO);
			ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_DDC);
#endif	
             break;
			 case DEVICE_HDMI2:
#if _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
	#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, 0x20,  &g_pucDdcciTxBuf[2]);
	#else
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);
				ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
	#endif
#else
	#if(_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		    UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI2+Index, 0x20,  &g_pucDdcciTxBuf[2]);
	#else
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			ScalerTimerDelayXms(10); 
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
	#endif
#endif
				   break;

			 case DEVICE_HDMI1:

#if(_PCB_TYPE==_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS || _PCB_TYPE == _RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)

	#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI2+Index, 0x20,  &g_pucDdcciTxBuf[2]);
	#else
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
	#endif

#elif _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
	#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, 0x20,  &g_pucDdcciTxBuf[2]);
	#else
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
	#endif
#else
	#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)		
		        UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_HDMI1+Index, 0x20,  &g_pucDdcciTxBuf[2]);
	#else
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
				ScalerTimerDelayXms(10); 
				UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, Index, 1, 0x20, &g_pucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
				ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
	#endif
#endif
				   break;

			 case DEVICE_DP1:
#if _PCB_TYPE==_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
	#if(_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)	 
				UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+Index, 0x20, &g_pucDdcciTxBuf[2]);
	#endif
#else
	#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)	 
				UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_ADDRESS_DP1+Index, 0x20, &g_pucDdcciTxBuf[2]);
	#endif	 
#endif
	 		  break;

			 case 0xA0:
				
				 break;
				 
			 case 0x14:
			 default:
				 break;
		 }
		 
		 g_pucDdcciTxBuf[0] = 0x6E;
		 g_pucDdcciTxBuf[1] = 0x80 | 0x20;//32 bytes
		 g_pucDdcciTxBuf[(g_pucDdcciTxBuf[1] & 0x7f) + 2] = UserCommonDdcciCalCheckSum();
		 ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
}





WORD GetAllWriteEdidPort(BYTE Flag)
{
    BYTE xdata  ucInputEDID_High = 0;
	BYTE xdata  ucInputEDID_Low = 0;
#if _A0_INPUT_PORT_TYPE == _A0_VGA_PORT
        ucInputEDID_High |= FCMD_VGA1_EDID;
#endif

#if 0//ENABLE_DVI_INPUT
        ucInputEDID_High |= FCMD_DVI1_EDID;
#endif

#if 1//ENABLE_HDMI_INPUT
        ucInputEDID_High |= FCMD_HDMI1_EDID;
#endif

#if 1//ENABLE_HDMI2ND_INPUT
        ucInputEDID_High |= FCMD_HDMI2_EDID;
#endif

#if 0//ENABLE_HDMI3ND_INPUT
        ucInputEDID_Low |= FCMD_HDMI3_EDID;
#endif

#if 1//ENABLE_DP_INPUT
        ucInputEDID_High |= FCMD_DP1_EDID;
#endif

#if 0//ENABLE_DP2ND_INPUT
        ucInputEDID_High |= FCMD_DP2_EDID;
#endif
#if 0//ENABLE_MHL        
        ucInputEDID_Low |= MHL2_EDID; //20141205 chang
        ucInputEDID_Low |= MHL_EDID; //20141205 chang
#endif
		//BIT0=0,EDID Saved in EEPRom;BIT0=1,EDID Saved in Flash
		//BIT1:(0:Write Disable;1:Write Enable)
		if ( Flag == 0x01 )
		{
		//SET_FACTORY_MODE_FLAG();
		//FC_EDID_EEPROM_WP_DISABLE();
		FC_EDID_ERASE();
		ucInputEDID_Low = ucInputEDID_Low | _BIT1;
		}
		else
		{
        //CLR_FACTORY_MODE_FLAG();
        //FC_EDID_EEPROM_WP_ENABLE();
		ucInputEDID_Low = ucInputEDID_Low & ~ ( _BIT1 );
		}
    return ( ( WORD ) ucInputEDID_High << 8 | ucInputEDID_Low );
}

void CTXWriteEdid( void)
{
     BYTE value = 0;
     BYTE VcpCode = g_pucDdcciRxBuf[3];
	 BYTE VcpCmd =  g_pucDdcciRxBuf[4];
	 BYTE ValueH =  g_pucDdcciRxBuf[5];
	 BYTE ValueM =  g_pucDdcciRxBuf[6];
	 BYTE ValueL =  g_pucDdcciRxBuf[7];
	 WORD EdidPortValue = 0;

	//if(GET_FACTORY_MODE() == _OFF)
	//{
	//	return;
	//}
	

	 
     if(( g_pucDdcciRxBuf[2] == CMD_SET_FACTORY_FEATURE) && (VcpCode == VCP_BOE_FACTORY_ALIGNMENT) 
     && (g_pucDdcciRxBuf[4] == 0xF0) && (g_pucDdcciRxBuf[5] == 0xF1) && (g_pucDdcciRxBuf[6] == 0x03) && (g_pucDdcciRxBuf[7] == 0x01))
     {	
       
#if _A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE
  
        PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
#endif
		g_pucDdcciTxBuf[0] =0x6E;
		g_pucDdcciTxBuf[1] =0x84;
    	g_pucDdcciTxBuf[2] = 0x02;
    	g_pucDdcciTxBuf[3] = 0xF0;
    	g_pucDdcciTxBuf[4] = 0xF1;
        g_pucDdcciTxBuf[5] = 0x03;
		g_pucDdcciTxBuf[6] = UserCommonDdcciCalCheckSum();
		ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
	 }
	 else if(g_pucDdcciRxBuf[2] ==_DDCCI_CMD_SET_VCP_FEATURE)
	 {
        switch(VcpCmd)//DDCBuffer[4]
	 	{
        case 0xF0 :	
			if(ValueH == 0xF1)
			{
			   if(ValueM == 0x01)
			   {
			        EdidPortValue = GetAllWriteEdidPort(ValueL);
					g_pucDdcciTxBuf[0]=0x6E;
					g_pucDdcciTxBuf[1]  = 0x83;
			    	g_pucDdcciTxBuf[2] = 0x02;
			    	g_pucDdcciTxBuf[3] = EdidPortValue>>8;
			    	g_pucDdcciTxBuf[4] = EdidPortValue&0xff;
					g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			   }
			   else if(ValueM == 0x02)
			   {
			   /*
		        	if(ValueL)
		        		{
                    FC_EDID_EEPROM_WP_DISABLE();
		        		}
                    else
                    	{
                    FC_EDID_EEPROM_WP_ENABLE();
                    	}
               */
					g_pucDdcciTxBuf[0]=0x6E;
					g_pucDdcciTxBuf[1]  = 0x84;
			    	g_pucDdcciTxBuf[2] = 0x02;
			    	g_pucDdcciTxBuf[3] = 0xF0;
			    	g_pucDdcciTxBuf[4] = 0xF1;
			        g_pucDdcciTxBuf[5] = 0x03;
					g_pucDdcciTxBuf[6] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			   }
			}
			
			
			break;
	    case 0xF8:
            TPVFCEDIDWriteData(); 
			break;
	 	};


	 }
	 else if(g_pucDdcciRxBuf[2] == _DDCCI_CMD_GET_VCP_FEATURE)
	 {
        switch(VcpCmd)//DDCBuffer[4]
	 	{
        case 0xF0 :	
			if(ValueH == 0xF1)
			{
			   if(ValueM == 0x01)
			   {
			        EdidPortValue = GetAllWriteEdidPort(ValueL);
					g_pucDdcciTxBuf[0]=0x6E;
					g_pucDdcciTxBuf[1]  = 0x83;
			    	g_pucDdcciTxBuf[2] = 0x02;
			    	g_pucDdcciTxBuf[3] = EdidPortValue>>8;
			    	g_pucDdcciTxBuf[4] = EdidPortValue&0xff;
					g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

			   }
			   else if(ValueM == 0x02)
			   {
			   /*
		        	if(ValueL)
		        		{
                    FC_EDID_EEPROM_WP_DISABLE();
		        		}
                    else
                    	{
                    FC_EDID_EEPROM_WP_ENABLE();
                    	}
              */
					g_pucDdcciTxBuf[0]=0x6E;
					g_pucDdcciTxBuf[1]  = 0x84;
			    	g_pucDdcciTxBuf[2] = 0x02;
			    	g_pucDdcciTxBuf[3] = 0xF0;
			    	g_pucDdcciTxBuf[4] = 0xF1;
			        g_pucDdcciTxBuf[5] = 0x03;
					g_pucDdcciTxBuf[6] = UserCommonDdcciCalCheckSum();
					ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			   }
			}
			break;
	    case 0xF8:
            TPVFCEDIDReadData();
			break;
	 	};
	 }
	 
}

#endif
#endif

#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223 || _PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301 || _PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)

void Edid_SN_READ(void)
{  
    BYTE DATA[13]={0};
    BYTE i=0;

	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
	ScalerTimerDelayXms(10); 
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x4D, 1,13 ,DATA,_IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);

    memcpy(g_stSNData, DATA,13);
   	
}
#endif
//--------------------------------------------------
//DFM Mode
//--------------------------------------------------
//--------------------------------------------------
// Description  : DFM mode Initial
//                add to last line of UserInterfaceInitial(), just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description  : DFM mode reset to off
//add to bottom line of Factory Reset process ,just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : DFM mode flag Check
//for check DFM status check , Call many times depend on project
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description	: WP check depend on Cable &DFM mode
//add to _MODE_STATUS_NOSIGNAL status of AOC2011OsdSystemFlowProc()  and when SysModeGetModeStateChange()==High
//just call once
// Input Value	: None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : DC power ON DFM mode clear
//add to _MODE_STATUS_INITIAL case of  AOC2011OsdSystemFlowProc() ,just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : DFM mode Logo On Check
//add before Show Logo , just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description  : DFM mode Led indication
//				   add before Keypad Led just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  : DFM mode switch
//add to OSD OperationTable
// Input Value  : None
// Output Value : None
//--------------------------------------------------

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//DFM rev02 patch note 7<<

//DFM rev04 patch note 1>>
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------

//DFM rev04 patch note 1<<

//DFM rev05 patch note 2>>
//DFM rev05 patch note 2<<

#endif //end of #if ((_FACTORY_MODE_OWNER == _OWNER_TPV))
#endif // (_DEF_DDCCI_EDID_TOOL)
