//////////////////////// ���� //////////////////////////////////
#define _ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD120_VA240A_H_20240812        	       					0x01	
#define _ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812        	       					0x02	

#define _ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD144_VA24G25_20241213        	       					0x03	


//////////////////////// ��ǿ //////////////////////////////////
// ����
#define _ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223        	       			0x100	
#define _ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250103        	       		0x101	
#define _ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115        	       		0x102	
#define _ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224        	       			0x103	
#define _ID_ZQ_2775E15_INNOLUX_MV270KCA_E8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250228        	       		0x104	

#define _ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223                                     0x105
#define _ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301                                    0x106


// ����
#define _ID_ZQ_2775E15_BOE_DV245QHB_N20_8BIT_QHD180_ZQ25F180_20250110                       			0x200

// Suma
#define _ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207                       			0x300


#define _DEF_GAMMA_TOOL_TEST					_OFF		// GammaУ׼ �龰ģʽĬ��ֵ�޸�
#define _ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515                                           0x400
#define _ID_JX_2557E02_MV238FHB_NF5_QHD144_EYEPROTECT_CLASSIC_R5KEY                                     0x401


// HDR �ļ�
#define _PROJECT_ID      		           		_ID_JX_2557E02_MV238FHB_NF5_QHD144_EYEPROTECT_CLASSIC_R5KEY


#if(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD120_VA240A_H_20240812)
#define _PANEL_TYPE                     		_BOE_MV238FHB_NY1_LVDS
#define _PCB_TYPE 			       				_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS
#define _OSD_KEY_FHD238							_ON//����Ϊ FHD-238�ļ���

#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812)
#define _PANEL_TYPE                     		_BOE_MV270FHB_NY0_LVDS
#define _PCB_TYPE 			       				_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS
#define _OSD_KEY_FHD270							_ON//����Ϊ FHD-270�ļ���

#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD144_VA24G25_20241213)
#define _PANEL_TYPE                     		_BOE_MV238FHB_NY1_LVDS
#define _PCB_TYPE 			       				_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS
#define _OSD_KEY_FHD238							_ON//����Ϊ FHD-238�ļ���

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223)
#define _PANEL_TYPE                     		_INNOLUX_MV270KCA_D8B_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_MENU_OSD_SixColor					_ON		//���˵�������ɫ��
//#define _HDR10_LIGHT_ENHANCE_SUPPORT            _ON

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250103)
#define _PANEL_TYPE                     		_INNOLUX_MV270KCA_D8B_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_MENU_OSD_SixColor					_ON		//���˵�������ɫ��
#define _RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER				_OFF	

#elif(_PROJECT_ID==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
#define EDID_MKF27F240L                         0
#define EDID_MKF27F240                          1
#define EDID_MKF24F240                          2
#define _PANEL_TYPE                     		_BOE_MV238FHB_NF1_LVDS_FHD180//_CSOT_SG2381B084_LVDS_FHD240HZ//_CSOT_SG2701B084_LVDS_FHD200HZ 
#define _PCB_TYPE 			       				_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_VGA_TIMING_KEY_2_4					_OFF		// VGA 2+4 Timing��������

#define _IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT    _ON
#define _OSD_KEY_FHD270_ROCKER                  _ON
#elif(_PROJECT_ID==_ID_JX_2557E02_MV238FHB_NF5_QHD144_EYEPROTECT_CLASSIC_R5KEY)
#define _PANEL_TYPE                     		_BOE_MV270QH7B00_LVDS_QHD144HZ//_BOE_MV238FHB_NF1_LVDS_FHD180//_CSOT_SG2381B084_LVDS_FHD240HZ//_CSOT_SG2701B084_LVDS_FHD200HZ 
#define _PCB_TYPE 			       				_RL6432_156PIN_HKMRT2557E02_1H1DP_LVDS
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_VGA_TIMING_KEY_2_4					_OFF		// VGA 2+4 Timing��������

#define _IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT    _ON
#define _OSD_KEY_FHD270_ROCKER                  _OFF
#define _SW_IIC_SUPPORT                         _ON
#define _MT3212_CT_SUPPORT                      _OFF
#define _LS_PS_SUPPORT                          _ON
#define _EYE_VLI_SUPPORT                        _ON
#define _AI_EYE_PROTECTION                      _ON//OSD EYE PROTECT FUNCTION  //AI EYE PROTECTION
#define _AI_LIGHT_ADAPTIVATION                  _ON//OSD LOW BRI/CT FUNCTION  //AI PQ ENGINE
#define _AI_LOW_POWER                           _ON//OSD LOW POWER FUNCTION   //AI LOW POWER
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_E8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250228)
#define _PANEL_TYPE                     		_INNOLUX_MV270KCA_E8B_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_MENU_OSD_SixColor					_ON		//���˵�������ɫ��

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115)
#define _PANEL_TYPE                     		_INNOLUX_MV270KCA_D8B_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_MENU_OSD_SixColor							_ON		//���˵�������ɫ��
#define _RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER							_OFF		

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)
#define _PANEL_TYPE                     		_BOE_ME270QHB_NF2_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_MENU_OSD_SixColor							_ON		//���˵�������ɫ��
#define _RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER							_OFF		

#elif(_PROJECT_ID==_ID_ZQ_2775E15_BOE_DV245QHB_N20_8BIT_QHD180_ZQ25F180_20250110)
#define _PANEL_TYPE                     		_BOE_DV245QHB_N20_EDP_QHD180HZ 
#define _PCB_TYPE 			       				_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1
#define _OSD_KEY_QHD270_ROCKER					_ON		//ң�а���Ϊ QHD-270�ļ���
#define _LOCAL_DEVLOP							_ON
#define _DEF_CT_SRGB_SUPPIRT					_OFF	// ɫ���Ƿ�֧��sRGB
#define _DEF_MENU_OSD_No_EDIDName_Mode			_ON		// ���˵�EDID������
#define _CTX_TPV                                _ON
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _DEF_VGA_TIMING_KEY_2_4					_OFF		// VGA 2+4 Timing��������
//#define	_OCC_GAMUT_NO_COMPRESSION_SUPPORT		_ON
//#define	_OCC_USER_DEFINE_SHIFT_1_BIT_SUPPORT	_ON
//#define _OCC_DISPLAY_P3_GAMMA_22_SUPPORT                        _ON

#elif(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)
#define _PANEL_TYPE                     		_PANDA_LC215DTBA_LVDS_FHD75HZ
#define _PCB_TYPE 			       				_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS
#define _OSD_KEY_FHD238							_ON//����Ϊ FHD-238�ļ���
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _CTX_TPV                                _ON
#define  _ECO_POWET_EXCHANGE                    _OFF//_ON
#define _DEF_MENU_OSD_No_EDIDName_Mode          _OFF
#define _ZHONGQIANG_LANGUAGE                    _ON
#define _LANGUAGE_CHANGE                        _ON
#define _KEY_BLACK                              _ON
#define _VIEWMODE_ADJUST_BLACK                  _OFF
#define _FPS_GAME_CHANGE                        _OFF
#define  _DEF_BURNIN_CHECK                     _ON

#elif(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _PANEL_TYPE                     		_BOE_HV320FHB_F4A_LVDS_FHD75HZ
#define _PCB_TYPE 			       				_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS
#define _OSD_KEY_FHD238							_ON//����Ϊ FHD-238�ļ���
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _CTX_TPV                                _ON
#define  _ECO_POWET_EXCHANGE                    _OFF//_ON
#define _DEF_MENU_OSD_No_EDIDName_Mode          _OFF
#define _ZHONGQIANG_LANGUAGE                    _ON
#define _LANGUAGE_CHANGE                        _ON
#define _KEY_BLACK                              _ON
#define _VIEWMODE_ADJUST_BLACK                  _OFF
#define _FPS_GAME_CHANGE                        _OFF
#define  _DEF_BURNIN_CHECK                     _ON

#elif(_PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)
#define _PANEL_TYPE                     		_BOE_MV238FHB_N63_LVDS_FHD100HZ
#define _PCB_TYPE 			       				_RL6463__76PIN__HKMRT2313E01__1A1H__LVDS
#define _OSD_KEY_FHD238							_ON//����Ϊ FHD-238�ļ���
#define _ENABLE_WRITE_EDID_CTX                  _ON
#define _CTX_TPV                                _ON
#define  _ECO_POWET_EXCHANGE                    _ON
#define _DEF_MENU_OSD_No_EDIDName_Mode          _OFF
#define _ZHONGQIANG_LANGUAGE                    _ON
#define _LANGUAGE_CHANGE                        _ON
#define _FPS_GAME_CHANGE                        _ON
#define _DEF_BURNIN_CHECK                       _ON

#else

#define _PANEL_TYPE                     		_BOE_MV238FHB_NY1_LVDS
#define _PCB_TYPE 			       				_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS

#endif

#ifndef  _DEF_BURNIN_CHECK       
#define  _DEF_BURNIN_CHECK                        _OFF     //���������źţ��ر�Ʈ��               
#endif

#ifndef _DEF_CT_SRGB_SUPPIRT
#define _DEF_CT_SRGB_SUPPIRT						_ON	// ɫ���Ƿ�֧��sRGB
#endif


#ifndef _FPS_GAME_CHANGE                     
#define _FPS_GAME_CHANGE                            _OFF
#endif

#ifndef _VIEWMODE_ADJUST_BLACK                                   //VIEWMODE �л�ʱ�ر���
#define _VIEWMODE_ADJUST_BLACK                       _ON                 
#endif
 
#ifndef _KEY_BLACK                                               //��ݼ���ͼ��Ϊ��ɫ
#define _KEY_BLACK                                   _OFF
#endif


#ifndef _LANGUAGE_CHANGE                                 
#define _LANGUAGE_CHANGE                                _ON
#endif

#ifndef _ZHONGQIANG_LANGUAGE       
#define _ZHONGQIANG_LANGUAGE                             _ON
#endif

#ifndef _V22E1_H_LANGUAGE       
#define _V22E1_H_LANGUAGE                             _ON //
#endif

#ifndef  _ECO_POWET_EXCHANGE              
#define  _ECO_POWET_EXCHANGE                             _OFF
#endif

#ifndef _CTX_TPV
#define _CTX_TPV							             _OFF	
#endif
#ifndef _ENABLE_WRITE_EDID_CTX
#define _ENABLE_WRITE_EDID_CTX							  _OFF	
#endif

#ifndef _DEF_MENU_OSD_No_EDIDName_Mode
#define _DEF_MENU_OSD_No_EDIDName_Mode							_OFF		//���˵�EDID������
#endif

#ifndef _DEF_MENU_OSD_SixColor
#define _DEF_MENU_OSD_SixColor							_OFF		//���˵�������ɫ��
#endif

#ifndef _DEF_OSD_Freesync_Info_Eanble
#define _DEF_OSD_Freesync_Info_Eanble							_ON	//Freesyncʵʱˢ��	������������һ�����õ�.	//_USER_TIMER_EVENT_OSD_SHOW_DRR_VFREQ
#endif	

#ifndef _LOCAL_DEVLOP
#define _LOCAL_DEVLOP											_OFF	
#endif	


#ifndef _OSD_GAME_SUPPORT
#define _OSD_GAME_SUPPORT                         				_ON	//OFF - �龰ģʽ���ܴ�  Game
#endif

#ifndef _DEF_JS_OSD_FPS_forbidden_ASP
#define _DEF_JS_OSD_FPS_forbidden_ASP							_ON	//�龰ģʽFPS ���� �������
#endif

#ifndef _ADVANCED_IMAGE_SUPPORT
#define _ADVANCED_IMAGE_SUPPORT									_ON
#endif

#define _USER_LATENCY_ADJUST_SUPPORT							_OFF
#define _OD_MODE_2_SUPPORT                                      _OFF



#ifndef _DEF_OSD_FUN_USB_POWER
#define _DEF_OSD_FUN_USB_POWER									_OFF	//�˵��Ƿ������USB��Դ����
#endif

#ifndef _OVERSCAN_SAVE_BY_INPUTPORT
#define _OVERSCAN_SAVE_BY_INPUTPORT									_OFF	// OVERSCAN �Ƿ�����ͨ������
#endif

#if(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115 || _PROJECT_ID ==_ID_ZQ_2775E15_BOE_DV245QHB_N20_8BIT_QHD180_ZQ25F180_20250110 || _PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224 ||  _PROJECT_ID ==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
#define _MPRT_SUPPORT                                         	_OFF
#elif(_PROJECT_ID==_ID_JX_2557E02_MV238FHB_NF5_QHD144_EYEPROTECT_CLASSIC_R5KEY)
#define _MPRT_SUPPORT                                         	_OFF
#else
#define _MPRT_SUPPORT                                         	_ON
#endif

#define _DEF_JS_POWER_ECO_DATA									25	//ʡ��ģʽĬ��ǿ��  50% 75%



#define _VIEWMODE_SUPPORT                       				_ON
#define _BLUE_LIGHT_FILTER_SUPPORT              				_ON

#ifndef _DEF_DDCCI_WB_TOOL
#define _DEF_DDCCI_WB_TOOL										_ON  // �Զ���ƽ��
#endif

#ifndef _DEF_DDCCI_EDID_TOOL
#define _DEF_DDCCI_EDID_TOOL									_ON  // ����edid
#endif	

//--------------------------------------------------
//support Latency 3 Level
//--------------------------------------------------
#ifndef _LATENCY_3_LEVEL_SUPPORT
#define _LATENCY_3_LEVEL_SUPPORT								_OFF
#endif

#ifndef _DEF_COLOR_TEMP_SRGB_EANBLE
#define _DEF_COLOR_TEMP_SRGB_EANBLE								_ON //����SRGBɫ��
#endif

#ifndef _sRGB_ADJ_BRIGHTNESS
#define _sRGB_ADJ_BRIGHTNESS                    				_ON
#endif

#ifndef _DEF_VIEW_SONIC_DCR
#define _DEF_VIEW_SONIC_DCR										_ON		//DCR
#endif

#ifndef _DEF_VGA_TIMING_KEY_2_4
#define _DEF_VGA_TIMING_KEY_2_4									_ON		// VGA 2+4 Timing��������
#endif

#ifndef _OSD_KEY_FHD270_ROCKER 
#define _OSD_KEY_FHD270_ROCKER                  _OFF
#endif

#ifndef _GSYNC_TEST
#define _GSYNC_TEST                    	        _OFF
#endif


