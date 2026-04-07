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
// ID Code      : HK_OSD_UserInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_OSD_TYPE == _REALTEK_2014_OSD)
#include"LuoGang_OSD_UserInclude.h"
#include"HK_OSD_FuncDefine.h"

#if(_PCB_TYPE==_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)
#define _BURNIN_STR_IC_NAME                	_R__,_T__,_D__,_2__,_7__,_7__,_5__,_Q__,_T__
#elif(_PCB_TYPE==_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS)
#define _BURNIN_STR_IC_NAME                	_S__,_c__,_a__,_l__,_e__,_r__,__,_COLON__,__,_R__,_T__,_D__,_2__,_3__,_1__,_3__,_B__,_R__,_SLINE__,_E__,_S__,_SLINE__,_C__,_G__
#elif(_PCB_TYPE==_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS)
#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _BURNIN_STR_IC_NAME                	_R__,_T__,_D__,_2__,_5__,_1__,_3__  //_SLINE__,_E__,_0__,_5__,_A__,_R__
#else
#define _BURNIN_STR_IC_NAME                	_R__,_T__,_D__,_2__,_5__,_1__,_3__,_A__,_R__  //_SLINE__,_E__,_0__,_5__,_A__,_R__
#endif
#elif(_PCB_TYPE==_RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)
#define _BURNIN_STR_IC_NAME                	_R__,_T__,_D__,_2__,_3__,_1__,_3__,_A__,_R__ //_SLINE__,_E__,_0__,_5__,_A__,_R__

#endif


// liuxh ����
#define _MAIN_PAGE_MODEL                    _M__,_o__,_d__,_e__,_l__,__,_COLON__,__
#if(_PROJECT_ID==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD120_VA240A_H_20240812)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_9_,_7_,_1_
#define _MAIN_PAGE_MODEL_NAME               _V__,_A__,_2__,_4__,_0__,_A__,_SLINE__,_H__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_A__,_2__,_4__,_0__,_A__,__,_S__,_e__,_r__,_i__,_e__,_s__
#define _PANNEL_NAME                        _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_J__,_S__,_2__,_3__,_8__,_L__,_A__,_SLINE__,_0__,_1__,__,__,_B__,_2__,_DOT__,_3__
#define _FW_VERSION                         _V__,_E__,_R__,_S__,_I__,_O__,_N__,_COLON__,__,_2__,_0__,_2__,_4__,_1__,_1__,_0__,_1__,__,__,__,_V__,_1__,_DOT__,_0__
#elif(_PROJECT_ID==_ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_9_,_7_,_2_
#define _MAIN_PAGE_MODEL_NAME               _V__,_A__,_2__,_7__,_0__,_A__,_SLINE__,_H__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_A__,_2__,_7__,_0__,_A__,__,_S__,_e__,_r__,_i__,_e__,_s__
#define _PANNEL_NAME                        _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_J__,_S__,_2__,_7__,_0__,_L__,_A__,_SLINE__,_0__,_1__,__,__,_B__,_2__,_DOT__,_8__
#define _FW_VERSION                         _V__,_E__,_R__,_S__,_I__,_O__,_N__,_COLON__,__,_2__,_0__,_2__,_4__,_1__,_1__,_0__,_1__,__,__,__,_V__,_1__,_DOT__,_0__
#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD144_VA24G25_20241213)
#define _PROJECT_NAME                       _V_,_S_,_2_,_0_,_5_,_6_,_2_
#define _MAIN_PAGE_MODEL_NAME               _V__,_A__,_2__,_4__,_G__,_2__,_5__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_A__,_2__,_4__,_G__,_2__,_5__,__,_S__,_e__,_r__,_i__,_e__,_s__
#define _PANNEL_NAME                        _P__,_a__,_n__,_e__,_l__,__,_COLON__,__,_J__,_S__,_2__,_3__,_8__,_L__,_A__,_SLINE__,_0__,_1__,__,__,_B__,_2__,_DOT__,_3__
#define _FW_VERSION                         _V__,_E__,_R__,_S__,_I__,_O__,_N__,_COLON__,__,_2__,_0__,_2__,_4__,_1__,_2__,_1__,_3__,__,__,__,_V__,_1__,_DOT__,_0__

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__
#define _PANNEL_NAME                        _I__,_N__,_N__,_X__,__,_M__,_2__,_7__,_0__,_K__,_C__,_A__,_SLINE__,_D__,_8__,_B__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_4__,__,__,__,_V__,_0__,_0__,_3__,_DOT__,_1__,_2__
#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define _OSD_AMD_FREESYNC_VERSION           _ON

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 

#define _DEF_ECO_BACK_75					75//(0xFF-0x99)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0xFF-0x6C)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300


#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250103)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _PANNEL_NAME                        _I__,_N__,_N__,_X__,__,_M__,_2__,_7__,_0__,_K__,_C__,_A__,_SLINE__,_D__,_8__,_B__

#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define _OSD_AMD_FREESYNC_VERSION           _OFF

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 
#define _DEF_PIVOT_OPTION_ON_OFF                    		_ON  // ��ת270��

#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300
#define _18_LANGUAGE_SUPPORT				_ON // ������������������5�����ԣ���ȥ2�����ԣ�һ��18������



#define _GSYNC_TEST                         _ON


#if _GSYNC_TEST
#define DEF_FREESYNC_STATUS                 _ON
#define _DEF_OSD_Freesync_Info_Eanble       _ON
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_5__,_2__,_4__,__,__,__,_V__,_0__,_0__,_3__,_DOT__,_1__,_3__
#else
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_5__,_1__,_3__,__,__,__,_V__,_0__,_0__,_3__,_DOT__,_1__,_3__
#endif


#elif(_PROJECT_ID==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)

#if 1
#define EDID_SELECT  						EDID_MKF24F240//EDID_MKF27F240L//EDID_MKF27F240//
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_

#if EDID_SELECT == EDID_MKF27F240L
#define _MAIN_PAGE_MODEL_NAME               _M__,_K__,_F__,_2__,_7__,_F__,_2__,_4__,_0__,_L__
#define _MAIN_PAGE_MODEL_SERIES             _M__,_K__,_F__,_2__,_7__,_F__,_2__,_4__,_0__,_L__
#elif EDID_SELECT == EDID_MKF27F240
#define _MAIN_PAGE_MODEL_NAME               _M__,_K__,_F__,_2__,_7__,_F__,_2__,_4__,_0__
#define _MAIN_PAGE_MODEL_SERIES             _M__,_K__,_F__,_2__,_7__,_F__,_2__,_4__,_0__
#else
#define _MAIN_PAGE_MODEL_NAME               _M__,_K__,_F__,_2__,_4__,_F__,_2__,_4__,_0__
#define _MAIN_PAGE_MODEL_SERIES             _M__,_K__,_F__,_2__,_4__,_F__,_2__,_4__,_0__
#endif
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_8__,_1__,_8__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_1__
#define TEST_EDID_ISSUE                     0

#else
#define EDID_SELECT  						EDID_MKF27F240
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _M__,_K__,_F__,_2__,_7__,_0__,_F__,_2__,_4__,_0__
#define _MAIN_PAGE_MODEL_SERIES             _M__,_K__,_F__,_2__,_7__,_0__,_F__,_2__,_4__,_0__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_5__,_1__,_6__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_1__
#endif

#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 
#define _RESET_KEEP_LANGUAGE								_ON//��λ�Ƿ�ָ�����

#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300
#define _LANGUAGE_DEFAULT  					_RUSSIA //_CHINESE_S

#define _DEFAULT_OSD_STYLE                  _TRG_OSD_STYLE
#define _ORANGE_MAINFRAME_ENABLE            _ON

#define _LOGO_TYPE							_LOGO_MACHENIKE_2K
#define ENABLE_LANGUAGE_SELECT_OSD				_OFF		//����ѡ�񵯴�
#define _DEF_District_swtich_Message			_OFF		//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT			_OFF		//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	_OFF		//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_CT_5800_SUPPORT                    _OFF
#define _DEF_PCM_ADOBE_RGB						_OFF
#define _OD_TIME_OFF_OPTION                     _ON
#define _DEF_OSD_GAMING                         _ON 		// ����˵���Ϸģʽ
#define _DEF_VIEWMODE_MAC					    _OFF		//  MAC
#define _DEF_SWEDEN_TEXT                        _OFF        // �����  
#define _DEF_CZECH_TEXT                         _OFF        // �ݿ���  
#define _DEF_Vietnam_TEXT						_OFF		// Խ����
#elif(_PROJECT_ID ==_ID_JX_2557E02_MV238FHB_NF5_QHD144_EYEPROTECT_CLASSIC_R5KEY)
#define EDID_SELECT  						EDID_MKF24F240//EDID_MKF27F240L//EDID_MKF27F240//
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _M__,_K__,_F__,_2__,_4__,_F__,_2__,_4__,_0__
#define _MAIN_PAGE_MODEL_SERIES             _M__,_K__,_F__,_2__,_4__,_F__,_2__,_4__,_0__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_8__,_1__,_8__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_1__
#define TEST_EDID_ISSUE                     0

#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 
#define _RESET_KEEP_LANGUAGE								_ON//��λ�Ƿ�ָ�����

#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300
#define _LANGUAGE_DEFAULT  					_ENGLISH //_CHINESE_S

#define _DEFAULT_OSD_STYLE                  _TRG_OSD_STYLE
#define _ORANGE_MAINFRAME_ENABLE            _ON

#define _LOGO_TYPE							_LOGO_MACHENIKE_2K
#define ENABLE_LANGUAGE_SELECT_OSD				_OFF		//����ѡ�񵯴�
#define _DEF_District_swtich_Message			_OFF		//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT			_OFF		//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	_OFF		//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_CT_5800_SUPPORT                    _OFF
#define _DEF_PCM_ADOBE_RGB						_OFF
#define _OD_TIME_OFF_OPTION                     _ON
#define _DEF_OSD_GAMING                         _ON 		// ����˵���Ϸģʽ
#define _DEF_VIEWMODE_MAC					    _OFF		//  MAC
#define _DEF_SWEDEN_TEXT                        _OFF        // �����  
#define _DEF_CZECH_TEXT                         _OFF        // �ݿ���  
#define _DEF_Vietnam_TEXT						_OFF		// Խ����
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_E8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250228)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_X__,_2__,_7__,_5__,_8__,_A__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _PANNEL_NAME                        _I__,_N__,_N__,_X__,__,_M__,_2__,_7__,_0__,_K__,_C__,_A__,_SLINE__,_E__,_8__,_B__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_5__,__,__,__,_V__,_0__,_0__,_4__,_DOT__,_0__,_4__
#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define _OSD_AMD_FREESYNC_VERSION           _ON

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 
#define _DEF_PIVOT_OPTION_ON_OFF                    		_ON  // ��ת270��

#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115)
#define _PROJECT_NAME                       _V_,_S_,_2_,_0_,_5_,_9_,_3_
#define _MAIN_PAGE_MODEL_NAME               _V__,_X__,_2__,_7__,_5__,_6__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_X__,_2__,_7__,_5__,_6__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _PANNEL_NAME                        _I__,_N__,_N__,_X__,__,_M__,_2__,_7__,_0__,_K__,_C__,_A__,_SLINE__,_D__,_8__,_B__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_1__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_4__
#define _MENU_AUDIO_SUPPORT                 _ON

#define _OSD_FOR_HDR400                     _ON

#define _LANGUAGE_DEFAULT  					_CHINESE_S
#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 

#define ENABLE_LANGUAGE_SELECT_OSD				_OFF		//����ѡ�񵯴�
#define _DEF_District_swtich_Message			_OFF		//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT			_OFF		//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	_OFF		//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_Vietnam_TEXT						_OFF		// Խ����
#define _RESET_KEEP_LANGUAGE								_ON//��λ�Ƿ�ָ�����


#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)
#define _PROJECT_NAME                       _V_,_S_,_2_,_0_,_5_,_9_,_3_
#define _MAIN_PAGE_MODEL_NAME               _V__,_X__,_2__,_7__,_5__,_6__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _MAIN_PAGE_MODEL_SERIES             _V__,_X__,_2__,_7__,_5__,_6__,_SLINE__,_2__,_K__,_SLINE__,_P__,_R__,_O__,_SLINE__,_2__
#define _PANNEL_NAME                        _B__,_O__,_E__,__,_M__,_E__,_2__,_7__,_0__,_Q__,_H__,_B__,_SLINE__,_N__,_F__,_2__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_4__,_2__,_8__,__,__,__,_V__,_0__,_0__,_2__,_DOT__,_0__,_6__
#define _MENU_AUDIO_SUPPORT                 _ON

#define _OSD_FOR_HDR400                     _ON

#define _LANGUAGE_DEFAULT  					_CHINESE_S
#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 

#define ENABLE_LANGUAGE_SELECT_OSD				_OFF		//����ѡ�񵯴�
#define _DEF_District_swtich_Message			_OFF		//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT			_OFF		//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	_OFF		//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_Vietnam_TEXT						_OFF		// Խ����
#define _RESET_KEEP_LANGUAGE								_ON//��λ�Ƿ�ָ�����


#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300


#elif(_PROJECT_ID==_ID_ZQ_2775E15_BOE_DV245QHB_N20_8BIT_QHD180_ZQ25F180_20250110)
#define _PROJECT_NAME                       _V_,_S_,_1_,_9_,_7_,_5_,_7_
#define _MAIN_PAGE_MODEL_NAME               _Z__,_Q__,_2__,_5__,_F__,_1__,_8__,_0__
#define _MAIN_PAGE_MODEL_SERIES             _Z__,_Q__,_2__,_5__,_F__,_1__,_8__,_0__
#define _PANNEL_NAME                        _B__,_O__,_E__,__,_D__,_V__,_2__,_4__,_5__,_Q__,_H__,_B__,_SLINE__,_N__,_2__,_0__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_7__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_8__
#define _DEF_BURNING_PORTINFO_SUPPORT		_ON
#define _MENU_AUDIO_SUPPORT                 _ON

#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_OFF
#define	_OSD_SHOW_KEY_BORDER				_ON // ��ʾң�а����ױ߿� - �ô������
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_OFF//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_OFF//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_OFF			//OFF - ����LOGO��ݲ˵� 
#define _RESET_KEEP_LANGUAGE								_ON//��λ�Ƿ�ָ�����

#define _DEF_ECO_BACK_75					75//(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#define _DEF_ECO_BACK_50					50//(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#define _MPRT_OFFSET                        300
#define _LANGUAGE_DEFAULT  					_CHINESE_S
#define _DEFAULT_OSD_STYLE                  _TRG_OSD_STYLE
#define _LOGO_TYPE							_LOGO_THUNDEROBOT_2K
#define ENABLE_LANGUAGE_SELECT_OSD				_OFF		//����ѡ�񵯴�
#define _DEF_District_swtich_Message			_OFF		//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT			_OFF		//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	_OFF		//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_CT_5800_SUPPORT                    _OFF
#define _DEF_PCM_ADOBE_RGB						_OFF
#define _OD_TIME_OFF_OPTION                     _ON
#define _DEF_OSD_GAMING                         _ON 		// ����˵���Ϸģʽ
#define _DEF_VIEWMODE_MAC					    _OFF		//  MAC
#define _DEF_SWEDEN_TEXT                        _OFF        // �����  
#define _DEF_CZECH_TEXT                         _OFF        // �ݿ���  
#define _DEF_Vietnam_TEXT						_OFF		// Խ����


#elif(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)
#define _PROJECT_NAME                       _V_,_S_,_2_,_0_,_5_,_9_,_0_
#define _MAIN_PAGE_MODEL_NAME               _V__,_A__,_2__,_2__,_E__,_1__,_SLINE__,_H__
#define _MAIN_PAGE_MODEL_SERIES              _V__,_A__,_2__,_2__,_E__,_1__,_SLINE__,_H__
#define _PANNEL_NAME                        _L__,_C__,_2__,_1__,_5__,_D__,_T__,_B__,_A__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_4__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_1__,_6__
#define _MENU_AUDIO_SUPPORT                 _ON
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_ON
#define _DEF_VIEWMODE_MOBA					_ON		//  MOBA
#define _DEF_VIEWMODE_RTS					_ON		//  RTS


//#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_ON
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_ON//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_ON//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich		_OFF			//OFF - ����LOGO��ݲ˵� 
#define _DEF_FACTORY_MODE                     _ON

//2025.02.07  tx
#define _5KEY_MENU_STYLE                            _ON                  
#define _DEF_OSD_CURSOR_FLICKER_TIPS		        _ON//�˵������˸��ʾOSD��ʧ
#define _DEF_District_swtich_Message			    _ON
#define _POWER_CONSUMPTION_HINT_SUPPORT			    _ON
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	    _ON	//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_NO_CHECK_LANGUAGE_DISTRICT_MODE_SWTICH _ON
#define _POWER_CONSUMPTION_HINT_SUPPORT             _ON
#define  ENABLE_KEY_PRESS_HIGHLIGHT                 _ON
#define	_OSD_SHOW_KEY_BORDER						_ON // ��ʾ�����ױ߿� - �ô������
#define _KEY_DELAYED_TIME                            100   //�˵��У�����OSD�ر��ٶ�
#define _DEF_LONG_PRESS_POWER_OFF_3_SEC         	_OFF	//�رճ���3��ػ�
#define _DEF_HOTKEY_OPTION_FLICKER_TIPS             _ON     //�ȼ���˸��ʾ��ʧ

#elif(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
#define _PROJECT_NAME                       _V_,_S_,_2_,_0_,_6_,_9_,_4_
#define _MAIN_PAGE_MODEL_NAME               _V__,_A__,_3__,_2__,_0__,_9__,_SLINE__,_M__,_H__,_SLINE__,_2__
#define _MAIN_PAGE_MODEL_SERIES              _V__,_A__,_3__,_2__,_0__,_9__,_SLINE__,_M__,_H__,_SLINE__,_2__
#define _PANNEL_NAME                        _H__,_V__,_3__,_2__,_0__,_F__,_H__,_B__
#define _FW_VERSION                         _2__,_0__,_2__,_5__,_0__,_3__,_1__,_1__,__,__,__,_V__,_0__,_0__,_1__,_DOT__,_0__,_1__
#define _MENU_AUDIO_SUPPORT                 _ON
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_ON
#define _DEF_VIEWMODE_MOBA					_ON		//  MOBA
#define _DEF_VIEWMODE_RTS					_ON		//  RTS


//#define	_OSD_SHOW_VIEWMODE					_OFF // ��ʾ��ǰ VIEWMODE - �˵�ͼ�����ǰģʽ
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT	_ON
#define _DEF_INDICATO_LIGHT_Flick_EANBLE	_ON//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#define _DEF_OSD_CURSOR_FLICKER_TIPS		_ON//�˵������˸��ʾOSD��ʧ
#define _DEF_HotOSD_Logo_MessageEanble_swtich		_OFF			//OFF - ����LOGO��ݲ˵� 
#define _DEF_FACTORY_MODE                     _ON

//2025.02.07  tx
#define _5KEY_MENU_STYLE                            _ON                  
#define _DEF_OSD_CURSOR_FLICKER_TIPS		        _ON//�˵������˸��ʾOSD��ʧ
#define _DEF_District_swtich_Message			    _ON
#define _POWER_CONSUMPTION_HINT_SUPPORT			    _ON
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH	    _ON	//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_NO_CHECK_LANGUAGE_DISTRICT_MODE_SWTICH _ON
#define _POWER_CONSUMPTION_HINT_SUPPORT             _ON
#define  ENABLE_KEY_PRESS_HIGHLIGHT                 _ON
#define	_OSD_SHOW_KEY_BORDER						_ON // ��ʾ�����ױ߿� - �ô������
#define _KEY_DELAYED_TIME                            100   //�˵��У�����OSD�ر��ٶ�
#define _DEF_LONG_PRESS_POWER_OFF_3_SEC         	_OFF	//�رճ���3��ػ�
#define _DEF_HOTKEY_OPTION_FLICKER_TIPS             _ON     //�ȼ���˸��ʾ��ʧ

#elif(_PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)

#define _PROJECT_NAME                       		_V_,_S_,_2_,_0_,_5_,_9_,_0_
#define _MAIN_PAGE_MODEL_NAME              			_2__,_3__,_8__//_W__,_L__,_C__,_D__,_SLINE__,_2__,_4__,_F__,_H__,_2__,_5__
#define _MAIN_PAGE_MODEL_SERIES             		_2__,_3__,_8__//_W__,_L__,_C__,_D__,_SLINE__,_2__,_4__,_F__,_H__,_2__,_5__
#define _PANNEL_NAME                        		_M__,_V__,_2__,_3__,_8__,_F__,_H__,_B__,_SLINE__,_N__,_6__,_3__
#define _FW_VERSION                         		_2__,_0__,_2__,_5__,_0__,_3__,_1__,_1__,__,__,__,_V__,_0__,_0__,_2__,_DOT__,_0__,_1__
#define _MENU_AUDIO_SUPPORT                 		_ON
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT			_OFF
#define _DEF_VIEWMODE_MOBA							_OFF		//  MOBA
#define _DEF_VIEWMODE_RTS							_OFF		//  RTS
#define _LOGO_TYPE									_LOGO_Suma
#define _DEFAULT_OSD_STYLE                  		_SUMA_OSD_STYLE

#define _DEF_HotOSD_Logo_MessageEanble_swtich		_OFF			//OFF - ����LOGO��ݲ˵� 
#define _DEF_FACTORY_MODE                     		_ON
#define _LANGUAGE_DEFAULT  							_CHINESE_S
#define _DEF_OSD_CURSOR_FLICKER_TIPS		        _OFF	//�˵������˸��ʾOSD��ʧ
#define	_OSD_SHOW_VIEWMODE							_OFF 	//��ʾ��ǰ VIEWMODE
#define	_OSD_VIEWMODE_USER_GAME_MODE				_OFF//_ON 	//VIEWMODE ��׼��FPS�����Ӳ˵�ѡ��

#define ENABLE_LANGUAGE_SELECT_OSD					_OFF	//����ѡ�񵯴�
#define _DEF_District_swtich_Message				_OFF	//����ѡ�񵯴�
#define _POWER_CONSUMPTION_HINT_SUPPORT				_OFF	//�ܺ����ѵ���
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH		_OFF	//�ϵ�/�����������Ժ͵���ѡ��
#define _DEF_LONG_PRESS_POWER_OFF_3_SEC         	_OFF	//����3��ػ�
#define _DEF_INDICATO_LIGHT_Flick_EANBLE			_OFF	//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸

#define _DEF_NAVIGATION_OSD_ENABLE            		_ON 	//�����˵�        
#define	_OSD_SHOW_KEY_BORDER						_ON 	// ��ʾ�����ױ߿� - �ô������

#define _DEF_Vietnam_TEXT							_OFF
#define _DEF_SWEDEN_TEXT                        	_OFF    // �����  
#define _DEF_CZECH_TEXT                        		_OFF    // �ݿ���  

#endif


#define _GAMUT_POST_PROC							_ON   // ɫ���ɫ�²��ԣ�ǿ�и�ɫ��


#ifndef _18_LANGUAGE_SUPPORT  
#define _18_LANGUAGE_SUPPORT						_OFF
#endif


// ������������������5�����ԣ���ȥ2�����ԣ�һ��18������
#if(_18_LANGUAGE_SUPPORT)

#define _DEF_ENGLISH_TEXT                       	_ON        // Ӣ��  

#define _DEF_FRANCAIS_TEXT                       	_ON        // ����  

#define _DEF_DEUTSCH_TEXT                        	_ON        // ����  

#define _DEF_DUTH_TEXT								_ON		   // ������

#define _DEF_ESPANOL_TEXT                       	_ON        // ��������  

#define _DEF_ITALIANO_TEXT                       	_ON        // �������  
  
#define _DEF_SWEDEN_TEXT                        	_ON        // �����  

#define _DEF_RUSSIA_TEXT                        	_ON        // ����  

#define _DEF_TURKISH_TEXT                       	_ON        // ��������  

#define _DEF_POLISH_TEXT						    _ON		   // ������

#define _DEF_CZECH_TEXT                         	_ON        // �ݿ���  

#define _DEF_ROMANIAN_TEXT						    _ON	   	   // ����������

#define _DEF_THAI_TEXT								_ON	   	   // ̩��

#define _DEF_Vietnam_TEXT							_ON		   // Խ����

#define _DEF_INDONESIAN_TEXT						_ON		   // ӡ����

#define _DEF_JAPANESE_TEXT                       	_ON        // ����  

#define _DEF_TCHINESE_TEXT                      	_ON        // ��������  

#define _DEF_SCHINESE_TEXT                      	_ON        // ��������  

#define _DEF_SUOMI_TEXT                          	_OFF       // ������  

#define _DEF_KOREAN_TEXT                        	_OFF       // ����  

#endif


/////////////////////////////////////////////////////////////////////////////////////
// _DEF_KEY_ROCKER �� _DEF_NAVIGATION_OSD_ENABLEҪһ���ã��������ػ�������(û���ú�)����ֲ�������������ʱ������� ---- lxh
#if(_PROJECT == _RL6449_PROJECT)
#define _DEF_KEY_ROCKER                 			_ON //ң�а���    - Ҫ���ң�а���ʹ��      
#define _DEF_NAVIGATION_OSD_ENABLE                 	_ON //�����˵�        

#elif(_PROJECT == _RL6463_PROJECT)
#define _DEF_JS_KEY_ICON_5_KEY_MODE             	_ON	//��ͨ���         

#elif _PROJECT == _RL6432_PROJECT
#define _DEF_KEY_ROCKER                 			_ON //ң�а���    - Ҫ���ң�а���ʹ��      
#define _DEF_NAVIGATION_OSD_ENABLE                 	_ON //�����˵�   

#elif(_PROJECT == _RL6851_PROJECT || _PROJECT == _RL6432_PROJECT )
#define _DEF_JS_KEY_ICON_5_KEY_MODE             	_ON	//��ͨ���         

#endif


#ifndef _5KEY_MENU_STYLE  
#define _5KEY_MENU_STYLE                 _OFF         
#endif  



#ifndef _DEF_JS_KEY_ICON_5_KEY_MODE  
#define _DEF_JS_KEY_ICON_5_KEY_MODE                 _OFF         
#endif  

#ifndef _DEF_KEY_ROCKER  
#define _DEF_KEY_ROCKER                 			_OFF         
#endif  

#ifndef _DEF_NAVIGATION_OSD_ENABLE  
#define _DEF_NAVIGATION_OSD_ENABLE                 	_OFF         
#endif  

#ifndef _DEF_JS_KEY_WHITE_BORDER_MODE
#define _DEF_JS_KEY_WHITE_BORDER_MODE               _ON	//	����������ɫ�߿�
#endif

#ifndef _DEF_LONG_PRESS_POWER_OFF_3_SEC
#define _DEF_LONG_PRESS_POWER_OFF_3_SEC             _ON	//	����3��ػ�
#endif

#ifndef _DEF_HOTKEY_OPTION_FLICKER_TIPS
#define _DEF_HOTKEY_OPTION_FLICKER_TIPS             _OFF     //�ȼ���˸��ʾ��ʧ
#endif

#ifndef _DEF_VIEWMODE_MAC
#define _DEF_VIEWMODE_MAC					        _ON		//  MAC
#endif

#ifndef _DEF_VIEWMODE_RTS
#define _DEF_VIEWMODE_RTS					        _ON		//  RTS
#endif

#ifndef _DEF_VIEWMODE_MOBA
#define _DEF_VIEWMODE_MOBA					        _ON		//  MOBA
#endif

#ifndef _DEF_OSD_GAMING
#define _DEF_OSD_GAMING                             _OFF	// ����˵���Ϸģʽ
#endif

#ifndef _AI_EYE_PROTECTION
#define _AI_EYE_PROTECTION                             _OFF	// ����˵���Ϸģʽ
#endif
#ifndef _AI_LIGHT_ADAPTIVATION
#define _AI_LIGHT_ADAPTIVATION                             _OFF	// ����˵���Ϸģʽ
#endif
#ifndef _AI_LOW_POWER
#define _AI_LOW_POWER                             _OFF	// ����˵���Ϸģʽ
#endif
#ifndef _OSD_VIEWMODE_USER_GAME_MODE
#define	_OSD_VIEWMODE_USER_GAME_MODE				_OFF 	//VIEWMODE ��׼��FPS�����Ӳ˵�ѡ��
#endif

#ifndef _FRONT_SIGHT_FUNCTION
#define _FRONT_SIGHT_FUNCTION						_ON
#endif

#ifndef _DEF_CT_5800_SUPPORT
#define _DEF_CT_5800_SUPPORT                        _ON
#endif


#ifndef _DEF_ACON_AND_RESET_USER_MODE_SWTICH  
#define _DEF_ACON_AND_RESET_USER_MODE_SWTICH		_ON	//�ϵ�/�����������Ժ͵���ѡ��
#endif


#ifndef ENABLE_KEY_PRESS_HIGHLIGHT  
#define ENABLE_KEY_PRESS_HIGHLIGHT					_OFF // ����ͼ�����
#endif


#ifndef _DEF_PCM_ADOBE_RGB
#define _DEF_PCM_ADOBE_RGB							_ON	//ɫ���Adobe RGBģʽ
#endif

#ifndef _OD_TIME_OFF_OPTION
#define _OD_TIME_OFF_OPTION                         _OFF
#endif

// �˵����

#define _VSC_OSD_STYLE                          	0		// ����
#define _TRG_OSD_STYLE                          	1		// ����
#define _SUMA_OSD_STYLE                          	2		// Suma

#ifndef _DEFAULT_OSD_STYLE
#define _DEFAULT_OSD_STYLE                          _VSC_OSD_STYLE
#endif

#ifndef _LANGUAGE_DEFAULT
#define _LANGUAGE_DEFAULT  							_ENGLISH
#endif

#ifndef _OSD_AMD_FREESYNC_VERSION
#define _OSD_AMD_FREESYNC_VERSION                        		_OFF
#endif

#ifndef _OSD_FOR_HDR400
#define _OSD_FOR_HDR400                        		_OFF	// HDR�Ƿ�Ϊ400
#endif

#ifndef _DEF_ECO_BACK_NEW
#define _DEF_ECO_BACK_NEW							_OFF	//�½���ģʽ�㷨
#endif

#ifndef _DEF_ECO_BACK_NEW
#define _DEF_ECO_BACK_NEW							_OFF	//�½���ģʽ�㷨
#endif

#ifndef _DEF_ECO_BACK_75
#define _DEF_ECO_BACK_75							(0x5F)//(0x5F)	//75%ǿ�Ƚ���ģʽ	�������Ĵ���
#endif

#ifndef _DEF_ECO_BACK_50
#define _DEF_ECO_BACK_50							(0x2A)//(0x2A)	//50%ǿ�Ƚ���ģʽ  �������Ĵ���
#endif


#ifndef _DEF_PIVOT_OPTION_ON_OFF
#define _DEF_PIVOT_OPTION_ON_OFF                    		_OFF  // ��ת270��
#endif


#ifndef _OSD_SHOW_KEY_BORDER
#define	_OSD_SHOW_KEY_BORDER								_OFF // ��ʾң�а����ױ߿� - �ô������
#endif


#ifndef _OSD_SHOW_VIEWMODE
#define	_OSD_SHOW_VIEWMODE									_ON // ��ʾ��ǰ VIEWMODE
#endif

#ifndef _DEF_MAIN_MENU_MUTE_ICON_SUPPORT
#define _DEF_MAIN_MENU_MUTE_ICON_SUPPORT					_OFF
#endif

#ifndef _OSD_BLACK_WHITE_TYPE
#define	_OSD_BLACK_WHITE_TYPE								_OFF //�ڰ׺����ײ˵�ѡ��
#endif

#ifndef _OSD_GRAY_WHITE_TYPE
#define _OSD_GRAY_WHITE_TYPE								_OFF //�Ұ׺Ͱ�ɫ�˵�ѡ��
#endif

#ifndef _NAVIGAT_MENU_SURPPORT
#define _NAVIGAT_MENU_SURPPORT						  		_OFF  //�����˵�
#endif

#ifndef _SOURCE_AUTO_ON
#define _SOURCE_AUTO_ON								        _OFF //�ź��л��Ƿ��auto
#endif


#ifndef	_EOC_RTS_FPS_SUPPORT
#define _EOC_RTS_FPS_SUPPORT					     	    _OFF  //ECOģʽ�Ƿ�� RTS��FPS
#endif

#ifndef _CT_7500_5800_sRGB_SUPPRT
#define _CT_7500_5800_sRGB_SUPPRT							_OFF  //ɫ���Ƿ��7500.5800.sRGB
#endif

#ifndef _CT_7500_SUPPRT
#define _CT_7500_SUPPRT										_ON//FF  //ɫ���Ƿ��7500
#endif

#ifndef _CT_5800_sRGB_SUPPRT
#define _CT_5800_sRGB_SUPPRT							    _OFF  //ɫ���Ƿ��5800.sRGB
#endif


#ifndef _CT_sRGB_SUPPRT
#define _CT_sRGB_SUPPRT							    		_OFF  //ɫ���Ƿ��sRGB
#endif

#ifndef _RESET_KEEP_LANGUAGE
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#endif

#ifndef _DEF_RESET_FACTORY_OFF
#define _DEF_RESET_FACTORY_OFF								_OFF//�������ùر��ϻ�
#endif

#ifndef	_DEF_SCREEN_SWITCHING
#define _DEF_SCREEN_SWITCHING								_OFF	//�л�����������
#endif


#ifndef _OSD_RECALL_FUNC
#define _OSD_RECALL_FUNC									_OFF  //�˳��˵��Ƿ����ǰ���״̬
#endif

#ifndef _DCR_PANEL_ON_OFF
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#endif

#ifndef _ADJ_BACKLIGHT_BY_TABLE
#define _ADJ_BACKLIGHT_BY_TABLE								_OFF //������ڷ�ʽ 
#endif
//ʹ��TABLE��ʽʱ����ͬʱҲ����_BACKLIGHT_DEF_PWM  _BACKLIGHT_MIN _BACKLIGHT_MAX (for DCR Mode)

#ifndef _OSD_7_KEY_SUPPROT
#define _OSD_7_KEY_SUPPROT									_OFF // 7���Ŀ���
#endif

#ifndef _OSD_5_KEY_SUPPROT
#define _OSD_5_KEY_SUPPROT									_OFF // 5���Ŀ���
#endif

#ifndef _OSD_LZ_FACT_LED
#define _OSD_LZ_FACT_LED									_OFF	//��־����ģʽָʾ��Ҫ��
#endif

#ifndef _BOARD_LINE_IN
#define _BOARD_LINE_IN										_OFF // ��Ƶ����
#endif

#ifndef _DEF_AUDIO_SELECT
#define _DEF_AUDIO_SELECT									_OFF //�����豸ѡ��  ���Ȼ��Ƕ���   �ú�ֻ֧��2513�����İ���, �Ҳ�֧��VGA�ź���ʹ��
#endif

#ifndef _LONG_PRESS_POWER_DOWN
#define _LONG_PRESS_POWER_DOWN								_OFF	//�����ػ�
#endif


#ifndef _OD_WEAK_MID_HIGH
#define _OD_WEAK_MID_HIGH									_OFF // OD ǿ����
#endif

#ifndef _MPRT_WEAK_MID_HIGH
#define _MPRT_WEAK_MID_HIGH									_OFF //mprtǿ����
#endif

#ifndef _FLICK_FREE
#define _FLICK_FREE										    _OFF//�˵��ϴ�flick��־
#endif

#ifndef _OSD_POWER_SAVING_MODE
#define _OSD_POWER_SAVING_MODE								_OFF//ʡ��ģʽѡ��
#endif

#ifndef _DEF_VGA_HDRON
#define _DEF_VGA_HDRON										_OFF//HDRĬ��Ϊ��ʱ  VGA����
#endif

#ifndef	_DEF_VGA_HDR_COLOR
#define _DEF_VGA_HDR_COLOR									_OFF//HDR VGAɫ��Ч��
#endif

#ifndef _DEF_KEY_ICON
#define _DEF_KEY_ICON										_OFF//�˵���������	Ĭ�Ϲر�

#endif

#ifndef _DEF_KEY_ICON_NEW
#define _DEF_KEY_ICON_NEW									_OFF//���������ʾ   ��ס���
#endif

#ifndef _DEF_HUIXIONG_FMENU
#define _DEF_HUIXIONG_FMENU									_OFF//���ܹ����˵�����ͻ��ͺ�
#endif

#ifndef _LONG_PRESS_MENU_LOCK_OSD_ENABLE
#define _LONG_PRESS_MENU_LOCK_OSD_ENABLE  					_OFF	//�˵�������
#endif

#ifndef _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
#define _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE  			_OFF	//��Դ��������
#endif

#ifndef _DEF_VGA_EXIT_AUTO_ADJUST
#define _DEF_VGA_EXIT_AUTO_ADJUST							_OFF	//VGA�����˳���3����Զ�ͼ�����,OFFΪ�Զ�ͼ�����
#endif

#ifndef _ENABLE_ENERGE_NOTICE_MENU
#define _ENABLE_ENERGE_NOTICE_MENU         					_OFF	//�ܺ�����
#endif

#ifndef _DEF_PROGRESS_BAR_MINUS
#define _DEF_PROGRESS_BAR_MINUS 							_OFF //��������������
#endif

#ifndef _DEF_PS5_GAME_MODE
#define _DEF_PS5_GAME_MODE									_OFF //��Ϸ��ģʽ
#endif

#ifndef _DEF_LOEBLUE_ARROW
#define _DEF_LOEBLUE_ARROW									_OFF//������ѡ��ģʽ
#endif

#ifndef _DEF_PROGRESS_BAR_NEW
#define _DEF_PROGRESS_BAR_NEW								_ON//FF //�л��龰ģʽ��������ֵ����  ֻ����ǰ����ѡ����ȣ��Աȶȣ�����ƽ��(������DCC)
#endif

#ifndef _DEF_OVERCLOCK_INFO_PERPETUAL
#define _DEF_OVERCLOCK_INFO_PERPETUAL						_OFF //��Ƶ��Ϣ�󲻽���ʡ��ģʽ
#endif

#ifndef _DEF_RESET_SOURCE_AUTO
#define _DEF_RESET_SOURCE_AUTO								_OFF //���ú��źŻ�ԭ���Զ�
#endif

#ifndef _DEF_ASPECT_11
#define _DEF_ASPECT_11										_OFF //�����������1��1ѡ��
#endif

#ifndef _DEF_POWER_MENU_KEY_TO_F_MENU
#define _DEF_POWER_MENU_KEY_TO_F_MENU						_OFF//������ͻ���⴦��,���빤��ģʽ
#endif

#ifndef _DEF_LOW_BLUE_DATA
#define _DEF_LOW_BLUE_DATA									_OFF //�������Զ���ֵ

#endif

#ifndef _DEF_ECO_SET
#define _DEF_ECO_SET										_OFF //�ͻ�Ҫ���ECOģʽ���趨ֵ(����/����7������Ҫ�����)
#endif

#ifndef _DEF_DCR_RESTORE_ECO
#define _DEF_DCR_RESTORE_ECO								_OFF //����DCR��ԭ֮ǰ�龰ģʽ��ֵ
#endif

#ifndef _DEF_SOUND_SOURCE
#define _DEF_SOUND_SOURCE									_OFF //�˵���Ƶͨ��ѡ��֧��
#endif

#ifndef _DEF_DCR_ON_ECO_ADJUSTABLE
#define _DEF_DCR_ON_ECO_ADJUSTABLE							_OFF //DCR�򿪺�ECOģʽ�Կ��Ե���
#endif

#ifndef _DEF_FREESYNC_TIMING
#define _DEF_FREESYNC_TIMING								_OFF //����Freesync��,���е������ֱ��ʺ���ɵ�������BUG
#endif

#ifndef _DEF_LED_FLICKER
#define _DEF_LED_FLICKER									_OFF //LED����˸ģʽ
#endif

#ifndef _DEF_LANGUAGE_CHINESE_ENGLISH
#define _DEF_LANGUAGE_CHINESE_ENGLISH						_OFF //����ֻ��Ӣ�������
#endif

#ifndef _DEF_6463_XUANZHUAN
#define _DEF_6463_XUANZHUAN									_OFF //6463��ת����
#endif

#ifndef _DEF_OSD_LOGO
#define _DEF_OSD_LOGO										_OFF	//�˵�OSD LOGO
#endif

#ifndef _DEF_PANEL_IMPRINTING
#define _DEF_PANEL_IMPRINTING								_OFF	//ʮ�ֹ���
#endif

#ifndef _DEF_INPUT_VGA_TIMING_DETAILED
#define _DEF_INPUT_VGA_TIMING_DETAILED						_OFF	//VGA�źŷֱ���ץȡ��ǿ   ��Էֱ�����ʾ�����BUG
#endif

#ifndef _DEF_HHT_TABLE
#define _DEF_HHT_TABLE										_OFF	//���̩���﷭��
#endif

#ifndef _DEF_HDR_MASK
#define _DEF_HDR_MASK										_OFF//HDR�Զ�ģʽ���Ͼͽ��ù���
#endif

#ifndef _DEF_POWER_LED_FLICKER
#define _DEF_POWER_LED_FLICKER								_OFF	//������LED��ֻ�е�ɫ ʡ��ģʽ����˸
#endif

#ifndef _DEF_POWER_LED_ALTERNATE_FLICKER_INFACTORY
#define _DEF_POWER_LED_ALTERNATE_FLICKER_INFACTORY			_OFF	// �ڹ���ģʽ�£���Դָʾ�ƽ�����˸
#endif

#ifndef _OSD_LANGUAGE_ARABIC
#define _OSD_LANGUAGE_ARABIC								_OFF	//��������
#endif

#ifndef _OSD_JS_LANGUAGE
#define _OSD_JS_LANGUAGE									_OFF	//���� �˵���ʽ
#endif

#ifndef _OSD_JS_DH_LANGUAGE
#define _OSD_JS_DH_LANGUAGE									_OFF	//���� �󻪲˵���ʽ
#endif

#ifndef _OSD_ECO_PICTURE_MODE
#define _OSD_ECO_PICTURE_MODE								_OFF	//ͼƬģʽ
#endif

#ifndef _OSD_ASPECT_PICTURE_MODE
#define _OSD_ASPECT_PICTURE_MODE								_OFF	//ͼƬģʽ
#endif

#ifndef _OSD_LANGUAGE_SWTICH
#define _OSD_LANGUAGE_SWTICH								_OFF	//�����л�
#endif

#ifndef _OSD_LZ_MESSAGE_OSD
#define _OSD_LZ_MESSAGE_OSD									_OFF	//��־ 27��FHD MESSAGE���ڴ�С
#endif

#ifndef _OSD_CNETERE_MESSAGE_OSD
#define _OSD_CNETERE_MESSAGE_OSD							_OFF	//�ź���ʾ��ѡ�� ����
#endif

#ifndef _DEF_2556E01_PCB_HDMI_NUM
#define _DEF_2556E01_PCB_HDMI_NUM							_OFF	//2556E01 ѡ��HDMI 1,2  ����PCB��HDMI���к�
#endif

#ifndef _OSD_RESET_SIGNAL_SAV
#define _OSD_RESET_SIGNAL_SAV								_OFF		//���ñ����ź�ѡ��
#endif

#ifndef _OSD_TEXT_MPRT2
#define _OSD_TEXT_MPRT2										_OFF	//MPRT����ΪMPRT2
#endif

#ifndef _OSD_FACT_LOGO_SWTICH
#define _OSD_FACT_LOGO_SWTICH								_OFF	//�ϻ��˵�������LOGO����
#endif

#ifndef _OSD_FACT_CT_SWTICH
#define _OSD_FACT_CT_SWTICH									_OFF	//�ϻ��˵� ȥ�� 5800 sRGB User
#endif

#ifndef _OSD_ECO_SHARPNESS_AUJUST
#define _OSD_ECO_SHARPNESS_AUJUST									_OFF	//���� ECO��ʱ���Ƿ� ����������
#endif

#ifndef _OSD_HOTKEYDISABLE_IN_FACTORY
#define _OSD_HOTKEYDISABLE_IN_FACTORY						_ON		// ����ģʽ�¿�ݼ���������
#endif




#ifndef _OSD_SHOW_KEY_BORDER
#define	_OSD_SHOW_KEY_BORDER								_OFF // ��ʾң�а����ױ߿� - �ô������
#endif



#ifndef _OSD_BLACK_WHITE_TYPE
#define	_OSD_BLACK_WHITE_TYPE								_OFF //�ڰ׺����ײ˵�ѡ��
#endif

#ifndef _OSD_GRAY_WHITE_TYPE
#define _OSD_GRAY_WHITE_TYPE								_OFF //�Ұ׺Ͱ�ɫ�˵�ѡ��
#endif

#ifndef _NAVIGAT_MENU_SURPPORT
#define _NAVIGAT_MENU_SURPPORT						  		_OFF  //�����˵�
#endif

#ifndef _SOURCE_AUTO_ON
#define _SOURCE_AUTO_ON								        _OFF //�ź��л��Ƿ��auto
#endif


#ifndef	_EOC_RTS_FPS_SUPPORT
#define _EOC_RTS_FPS_SUPPORT					     	    _OFF  //ECOģʽ�Ƿ�� RTS��FPS
#endif

#ifndef _CT_7500_5800_sRGB_SUPPRT
#define _CT_7500_5800_sRGB_SUPPRT							_OFF  //ɫ���Ƿ��7500.5800.sRGB
#endif

#ifndef _CT_7500_SUPPRT
#define _CT_7500_SUPPRT										_ON//FF  //ɫ���Ƿ��7500
#endif

#ifndef _CT_5800_sRGB_SUPPRT
#define _CT_5800_sRGB_SUPPRT							    _OFF  //ɫ���Ƿ��5800.sRGB
#endif


#ifndef _CT_sRGB_SUPPRT
#define _CT_sRGB_SUPPRT							    		_OFF  //ɫ���Ƿ��sRGB
#endif

#ifndef _RESET_KEEP_LANGUAGE
#define _RESET_KEEP_LANGUAGE								_OFF //��λ�Ƿ�ָ�����
#endif

#ifndef _DEF_RESET_FACTORY_OFF
#define _DEF_RESET_FACTORY_OFF								_ON//�������ùر��ϻ�
#endif

#ifndef	_DEF_SCREEN_SWITCHING
#define _DEF_SCREEN_SWITCHING								_OFF	//�л�����������
#endif


#ifndef _OSD_RECALL_FUNC
#define _OSD_RECALL_FUNC									_OFF  //�˳��˵��Ƿ����ǰ���״̬
#endif

#ifndef _DCR_PANEL_ON_OFF
#define _DCR_PANEL_ON_OFF									_ON //DCR�򿪣��ڳ��Ƿ�ر���
#endif

#ifndef _ADJ_BACKLIGHT_BY_TABLE
#define _ADJ_BACKLIGHT_BY_TABLE								_OFF //������ڷ�ʽ 
#endif
//ʹ��TABLE��ʽʱ����ͬʱҲ����_BACKLIGHT_DEF_PWM  _BACKLIGHT_MIN _BACKLIGHT_MAX (for DCR Mode)

#ifndef _OSD_7_KEY_SUPPROT
#define _OSD_7_KEY_SUPPROT									_OFF // 7���Ŀ���
#endif

#ifndef _OSD_5_KEY_SUPPROT
#define _OSD_5_KEY_SUPPROT									_OFF // 5���Ŀ���
#endif

#ifndef _OSD_LZ_FACT_LED
#define _OSD_LZ_FACT_LED									_OFF	//��־����ģʽָʾ��Ҫ��
#endif

#ifndef _BOARD_LINE_IN
#define _BOARD_LINE_IN										_OFF // ��Ƶ����
#endif

#ifndef _DEF_AUDIO_SELECT
#define _DEF_AUDIO_SELECT									_OFF //�����豸ѡ��  ���Ȼ��Ƕ���   �ú�ֻ֧��2513�����İ���, �Ҳ�֧��VGA�ź���ʹ��
#endif

#ifndef _LONG_PRESS_POWER_DOWN
#define _LONG_PRESS_POWER_DOWN								_OFF	//�����ػ�
#endif

#ifndef _MPRT_WEAK_MID_HIGH
#define _MPRT_WEAK_MID_HIGH									_OFF //mprtǿ����
#endif

#ifndef _FLICK_FREE
#define _FLICK_FREE										    _OFF//�˵��ϴ�flick��־
#endif

#ifndef _OSD_POWER_SAVING_MODE
#define _OSD_POWER_SAVING_MODE								_OFF//ʡ��ģʽѡ��
#endif

#ifndef _DEF_VGA_HDRON
#define _DEF_VGA_HDRON										_OFF//HDRĬ��Ϊ��ʱ  VGA����
#endif

#ifndef	_DEF_VGA_HDR_COLOR
#define _DEF_VGA_HDR_COLOR									_OFF//HDR VGAɫ��Ч��
#endif

#ifndef _DEF_KEY_ICON
#define _DEF_KEY_ICON										_OFF//�˵���������	Ĭ�Ϲر�

#endif

#ifndef _DEF_KEY_ICON_NEW
#define _DEF_KEY_ICON_NEW									_OFF//���������ʾ   ��ס���
#endif

#ifndef _DEF_HUIXIONG_FMENU
#define _DEF_HUIXIONG_FMENU									_OFF//���ܹ����˵�����ͻ��ͺ�
#endif

#ifndef _LONG_PRESS_MENU_LOCK_OSD_ENABLE
#define _LONG_PRESS_MENU_LOCK_OSD_ENABLE  					_OFF	//�˵�������
#endif

#ifndef _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE
#define _LONG_PRESS_POWER_LOCK_POWER_KEY_ENABLE  			_OFF	//��Դ��������
#endif

#ifndef _DEF_VGA_EXIT_AUTO_ADJUST
#define _DEF_VGA_EXIT_AUTO_ADJUST							_OFF	//VGA�����˳���3����Զ�ͼ�����,OFFΪ�Զ�ͼ�����
#endif

#ifndef _ENABLE_ENERGE_NOTICE_MENU
#define _ENABLE_ENERGE_NOTICE_MENU         					_OFF	//�ܺ�����
#endif

#ifndef _DEF_PROGRESS_BAR_MINUS
#define _DEF_PROGRESS_BAR_MINUS 							_OFF //��������������
#endif

#ifndef _DEF_PS5_GAME_MODE
#define _DEF_PS5_GAME_MODE									_OFF //��Ϸ��ģʽ
#endif

#ifndef _DEF_LOEBLUE_ARROW
#define _DEF_LOEBLUE_ARROW									_OFF//������ѡ��ģʽ
#endif

#ifndef _DEF_PROGRESS_BAR_NEW
#define _DEF_PROGRESS_BAR_NEW								_ON//FF //�л��龰ģʽ��������ֵ����  ֻ����ǰ����ѡ����ȣ��Աȶȣ�����ƽ��(������DCC)
#endif

#ifndef _DEF_OVERCLOCK_INFO_PERPETUAL
#define _DEF_OVERCLOCK_INFO_PERPETUAL						_OFF //��Ƶ��Ϣ�󲻽���ʡ��ģʽ
#endif

#ifndef _DEF_RESET_SOURCE_AUTO
#define _DEF_RESET_SOURCE_AUTO								_OFF //���ú��źŻ�ԭ���Զ�
#endif

#ifndef _DEF_ASPECT_11
#define _DEF_ASPECT_11										_OFF //�����������1��1ѡ��
#endif

#ifndef _DEF_POWER_MENU_KEY_TO_F_MENU
#define _DEF_POWER_MENU_KEY_TO_F_MENU						_OFF//������ͻ���⴦��,���빤��ģʽ
#endif

#ifndef _DEF_LOW_BLUE_DATA
#define _DEF_LOW_BLUE_DATA									_OFF //�������Զ���ֵ

#endif

#ifndef _DEF_ECO_SET
#define _DEF_ECO_SET										_OFF //�ͻ�Ҫ���ECOģʽ���趨ֵ(����/����7������Ҫ�����)
#endif

#ifndef _DEF_DCR_RESTORE_ECO
#define _DEF_DCR_RESTORE_ECO								_OFF //����DCR��ԭ֮ǰ�龰ģʽ��ֵ
#endif

#ifndef _DEF_SOUND_SOURCE
#define _DEF_SOUND_SOURCE									_OFF //�˵���Ƶͨ��ѡ��֧��
#endif

#ifndef _DEF_DCR_ON_ECO_ADJUSTABLE
#define _DEF_DCR_ON_ECO_ADJUSTABLE							_OFF //DCR�򿪺�ECOģʽ�Կ��Ե���
#endif

#ifndef _DEF_FREESYNC_TIMING
#define _DEF_FREESYNC_TIMING								_OFF //����Freesync��,���е������ֱ��ʺ���ɵ�������BUG
#endif

#ifndef _DEF_LED_FLICKER
#define _DEF_LED_FLICKER									_OFF //LED����˸ģʽ
#endif

#ifndef _DEF_6463_XUANZHUAN
#define _DEF_6463_XUANZHUAN									_OFF //6463��ת����
#endif

#ifndef _DEF_OSD_LOGO
#define _DEF_OSD_LOGO										_OFF	//�˵�OSD LOGO
#endif

#ifndef _DEF_PANEL_IMPRINTING
#define _DEF_PANEL_IMPRINTING								_OFF	//ʮ�ֹ���
#endif

#ifndef _DEF_INPUT_VGA_TIMING_DETAILED
#define _DEF_INPUT_VGA_TIMING_DETAILED						_OFF	//VGA�źŷֱ���ץȡ��ǿ   ��Էֱ�����ʾ�����BUG
#endif

#ifndef _DEF_HHT_TABLE
#define _DEF_HHT_TABLE										_OFF	//���̩���﷭��
#endif

#ifndef _DEF_HDR_MASK
#define _DEF_HDR_MASK										_OFF//HDR�Զ�ģʽ���Ͼͽ��ù���
#endif

#ifndef _DEF_POWER_LED_FLICKER
#define _DEF_POWER_LED_FLICKER								_OFF	//������LED��ֻ�е�ɫ ʡ��ģʽ����˸
#endif

#ifndef _DEF_POWER_LED_ALTERNATE_FLICKER_INFACTORY
#define _DEF_POWER_LED_ALTERNATE_FLICKER_INFACTORY			_OFF	// �ڹ���ģʽ�£���Դָʾ�ƽ�����˸
#endif

#ifndef _OSD_LANGUAGE_ARABIC
#define _OSD_LANGUAGE_ARABIC								_OFF	//��������
#endif

#ifndef _OSD_JS_LANGUAGE
#define _OSD_JS_LANGUAGE									_OFF	//���� �˵���ʽ
#endif

#ifndef _OSD_JS_DH_LANGUAGE
#define _OSD_JS_DH_LANGUAGE									_OFF	//���� �󻪲˵���ʽ
#endif

#ifndef _OSD_ECO_PICTURE_MODE
#define _OSD_ECO_PICTURE_MODE								_OFF	//ͼƬģʽ
#endif

#ifndef _OSD_ASPECT_PICTURE_MODE
#define _OSD_ASPECT_PICTURE_MODE								_OFF	//ͼƬģʽ
#endif

#ifndef _OSD_LANGUAGE_SWTICH
#define _OSD_LANGUAGE_SWTICH								_OFF	//�����л�
#endif

#ifndef _OSD_LZ_MESSAGE_OSD
#define _OSD_LZ_MESSAGE_OSD									_OFF	//��־ 27��FHD MESSAGE���ڴ�С
#endif

#ifndef _OSD_CNETERE_MESSAGE_OSD
#define _OSD_CNETERE_MESSAGE_OSD							_OFF	//�ź���ʾ��ѡ�� ����
#endif

#ifndef _DEF_2556E01_PCB_HDMI_NUM
#define _DEF_2556E01_PCB_HDMI_NUM							_OFF	//2556E01 ѡ��HDMI 1,2  ����PCB��HDMI���к�
#endif

#ifndef _OSD_RESET_SIGNAL_SAV
#define _OSD_RESET_SIGNAL_SAV								_OFF		//���ñ����ź�ѡ��
#endif

#ifndef _OSD_TEXT_MPRT2
#define _OSD_TEXT_MPRT2										_OFF	//MPRT����ΪMPRT2
#endif

#ifndef _OSD_FACT_LOGO_SWTICH
#define _OSD_FACT_LOGO_SWTICH								_OFF	//�ϻ��˵�������LOGO����
#endif

#ifndef _OSD_FACT_CT_SWTICH
#define _OSD_FACT_CT_SWTICH									_OFF	//�ϻ��˵� ȥ�� 5800 sRGB User
#endif

#ifndef _OSD_ECO_SHARPNESS_AUJUST
#define _OSD_ECO_SHARPNESS_AUJUST									_OFF	//���� ECO��ʱ���Ƿ� ����������
#endif

#ifndef _OSD_HOTKEYDISABLE_IN_FACTORY
#define _OSD_HOTKEYDISABLE_IN_FACTORY						_ON		// ����ģʽ�¿�ݼ���������
#endif





// no use
#ifndef _DEF_FACTORY_MODE
#define _DEF_FACTORY_MODE								     _ON//_OFF  
#endif

#ifndef _DEF_BURNING_MODE
#define _DEF_BURNING_MODE								     _ON  //Ʈ��Ĭ�Ͽ���
#endif


#define _LOGO_NONE                                           0
#define _LOGO_TYPE_THREE_BIRDS                               1
#define _LOGO_THUNDEROBOT_2K                   			 	 2
#define _LOGO_Suma                   			 	 	     3
#define _LOGO_MACHENIKE_2K                                   4



#ifndef _LOGO_TYPE
#define _LOGO_TYPE								    		 _LOGO_TYPE_THREE_BIRDS//_LOGO_NONE
#endif

#ifndef _DEF_HotOSD_Logo_MessageEanble_swtich
#define _DEF_HotOSD_Logo_MessageEanble_swtich				_ON			//OFF - ����LOGO��ݲ˵� 
#endif

#ifndef _DEF_DIGITAL_VOL_MAX
#if 0//(_PCB_TYPE == _RL6449__216PIN__HKMRT2795E04__1USB1DP2H__eDPVB1)
#define _DEF_DIGITAL_VOL_MAX								 0x1429
#else
#define _DEF_DIGITAL_VOL_MAX								 0X2000
#endif
#endif

#ifndef ENABLE_LANGUAGE_SELECT_OSD
#define ENABLE_LANGUAGE_SELECT_OSD                  		_ON // ����ѡ�񵯴�
#endif



#ifndef _DEF_OSD_DOUBLE
#define _DEF_OSD_DOUBLE                 				    _OFF
#endif


#ifndef _BURNIN_MSG_MENU_SUPPORT
#define _BURNIN_MSG_MENU_SUPPORT                 		    _ON
#endif


#ifndef _DEF_DDCCIStatus
#define _DEF_DDCCIStatus									_ON	// liuxh DDCCI
#endif


#ifndef _DEF_GAME_MODE
#define _DEF_GAME_MODE								     	_OFF//DP,HDMI��Ϸģʽ
#endif

#ifndef _DEF_LOW_BLUE_DATA
#define _DEF_LOW_BLUE_DATA									_OFF //�������Զ���ֵ
#endif

#ifndef _DEF_OSD_DISP_NOSIGNAL_MSG_TIME
#define _DEF_OSD_DISP_NOSIGNAL_MSG_TIME                     3
#endif

#ifndef _DEF_FACTORY_EDIDINFO
#define _DEF_FACTORY_EDIDINFO                               _OFF
#endif


#ifndef _DEF_BURNING_TIME_ON
#define _DEF_BURNING_TIME_ON           					_ON//�ϻ�ģʽ�����ϻ�ʱ��
#endif

#ifndef _DEF_VOLUME_PWM
#define _DEF_VOLUME_PWM									80
#endif

#ifndef _DEF_BURNING_PORTINFO_SUPPORT
#define _DEF_BURNING_PORTINFO_SUPPORT					_OFF
#endif
#endif

#ifndef _MENU_AUDIO_SUPPORT
#define _MENU_AUDIO_SUPPORT                             _OFF
#endif

#ifndef _DEF_INDICATO_LIGHT_Flick_EANBLE
#define _DEF_INDICATO_LIGHT_Flick_EANBLE					_ON	//����ģʽ����ָʾ�Ƴ�����˸-����ģʽ����ָʾ�Ƴȵ���˸
#endif

#ifndef _OSD_Timing_Notice
#define _OSD_Timing_Notice									_ON//����Ƶ�ֱ����Ƽ���ʾ
#endif

#ifndef _OSD_LOCK_ON_PowerLock_AND_LogoLock_SUPPORT
#define _OSD_LOCK_ON_PowerLock_AND_LogoLock_SUPPORT    		_ON	// ON - ���˲˵�������LOGO��ϼ�����Դ��ϼ�
#endif

#ifndef _OSD_Sleep_PowenOff_Fun
#define _OSD_Sleep_PowenOff_Fun								_ON//˯���¼�ʱ�ػ�
#endif

#ifndef _OSD_PowerSaving_Fun
#define _OSD_PowerSaving_Fun								_ON//��ʱ����˯��
#endif

#ifndef _POWER_CONSUMPTION_HINT_SUPPORT
#define _POWER_CONSUMPTION_HINT_SUPPORT         			_ON	//�ܺ����ѵ���
#endif

#ifndef _DEF_District_swtich_Message
#define _DEF_District_swtich_Message						_ON //����ѡ�񵯴�
#endif

#ifndef _FACTORY_NAVIGATION_SUPPORT
#define _FACTORY_NAVIGATION_SUPPORT							_OFF	//�����˵���������
#endif

#ifndef _DEF_ZhongDong
#define _DEF_ZhongDong				                		_ON	//����ѡ�������ж�
#endif

#ifndef _DEF_REGION_InitData
#define _DEF_REGION_InitData								_DEF_REGION_OTHER	//����
#endif



#define _DEF_OSD_OVER_VFREQ									710	//��ɨ��Ĭ������Ƶ��	Ĭ�Ͽ���  ��������������(���ݴ����ж�)

#ifndef _DEF_NO_SIGNAL_SHOW_SOURCE_MENU
#define _DEF_NO_SIGNAL_SHOW_SOURCE_MENU						_ON		// ���ź��� - �ź�ѡ��
#endif




#ifndef _DEF_OSD_CURSOR_FLICKER_TIPS
#define _DEF_OSD_CURSOR_FLICKER_TIPS						_ON			//�˵������˸��ʾOSD��ʧ
#endif

#ifndef _DEF_NO_CHECK_LANGUAGE_DISTRICT_MODE_SWTICH  
#define _DEF_NO_CHECK_LANGUAGE_DISTRICT_MODE_SWTICH			_OFF	// ��� ���Ժ͵���ѡ��,�Ƿ��Զ�������ʾ���ѡ�������Ժ����������ѡ��
#endif

/*
#define _DEF_OSD_CURSOR_FLICKER_TIPS_TIMES					(6*2) 		//��˸6��
#define _DEF_OSD_MENU_FLICKER_TIPS_TIME						SEC(0.25)
#define _DEF_HOTOSD_FLICKER_TIPS_TIME						SEC(0.25)
*/
//2025.02.08 CZH
#define _DEF_OSD_CURSOR_FLICKER_TIPS_TIMES					(3*2) 		//��˸3��
#define _DEF_OSD_MENU_FLICKER_TIPS_TIME						SEC(0.5)
#define _DEF_HOTOSD_FLICKER_TIPS_TIME						SEC(0.5)


#define _DEF_DDC_COLOR_USER_4500							_ON	//��ƽ�� Userѡ�����4500ɫ��

#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
#define _OSD_BOTTOM_BUTTON_H_SPACE_SUPPORT                     _OFF
#else
#define _OSD_BOTTOM_BUTTON_H_SPACE_SUPPORT                     _ON
#endif

#define _DCR_TURNOFF_BACKLIGHT_SUPPORT						_ON





/****************************�˵�λ��*************************************/
#ifndef _OSD_KEY_FHD238
#define _OSD_KEY_FHD238										_OFF//��ͨ����Ϊ FHD-238�ļ���
#endif

#ifndef _OSD_KEY_FHD270
#define _OSD_KEY_FHD270										_OFF//��ͨ����Ϊ FHD-270�ļ���
#endif

#ifndef _OSD_KEY_QHD270_ROCKER
#define _OSD_KEY_QHD270_ROCKER								_OFF//ң�а���Ϊ QHD-270�ļ���
#endif

/*************************************************************************/







#ifndef _DEF_ENGLISH_TEXT  
#define _DEF_ENGLISH_TEXT                       	_ON        // Ӣ��  
#endif  

#ifndef _DEF_FRANCAIS_TEXT  
#define _DEF_FRANCAIS_TEXT                       	_ON        // ����  
#endif  

#ifndef _DEF_DEUTSCH_TEXT  
#define _DEF_DEUTSCH_TEXT                        	_ON        // ����  
#endif  

#ifndef _DEF_ESPANOL_TEXT  
#define _DEF_ESPANOL_TEXT                       	_ON        // ��������  
#endif  

#ifndef _DEF_ITALIANO_TEXT  
#define _DEF_ITALIANO_TEXT                       	_ON        // �������  
#endif  

#ifndef _DEF_SUOMI_TEXT  
#define _DEF_SUOMI_TEXT                          	_ON        // ������  
#endif  
  
#ifndef _DEF_SWEDEN_TEXT  
#define _DEF_SWEDEN_TEXT                        	_ON        // �����  
#endif  

#ifndef _DEF_RUSSIA_TEXT  
#define _DEF_RUSSIA_TEXT                        	_ON        // ����  
#endif  

#ifndef _DEF_TURKISH_TEXT  
#define _DEF_TURKISH_TEXT                       	_ON        // ��������  
#endif

#ifndef _DEF_CZECH_TEXT  
#define _DEF_CZECH_TEXT                         	_ON        // �ݿ���  
#endif

#ifndef _DEF_JAPANESE_TEXT  
#define _DEF_JAPANESE_TEXT                       	_ON        // ����  
#endif  

#ifndef _DEF_KOREAN_TEXT  
#define _DEF_KOREAN_TEXT                        	_ON        // ����  
#endif  

#ifndef _DEF_TCHINESE_TEXT  
#define _DEF_TCHINESE_TEXT                      	_ON        // ��������  
#endif  

#ifndef _DEF_SCHINESE_TEXT  
#define _DEF_SCHINESE_TEXT                      	_ON        // ��������  
#endif  

#ifndef _DEF_Vietnam_TEXT
#define _DEF_Vietnam_TEXT							_ON			//Խ����
#endif

// �����¼ӵ�����
#ifndef _DEF_DUTH_TEXT 
#define _DEF_DUTH_TEXT								_OFF			//������
#endif

#ifndef _DEF_POLISH_TEXT
#define _DEF_POLISH_TEXT						    _OFF			//������
#endif

#ifndef _DEF_ROMANIAN_TEXT
#define _DEF_ROMANIAN_TEXT						    _OFF			//����������
#endif

#ifndef _DEF_THAI_TEXT
#define _DEF_THAI_TEXT								_OFF			//̩��
#endif

#ifndef _DEF_INDONESIAN_TEXT
#define _DEF_INDONESIAN_TEXT						_OFF			//ӡ����
#endif


#ifndef _MPRT_BACKLIGHT_PWM_MAX
#define _MPRT_BACKLIGHT_PWM_MAX                    	(_BACKLIGHT_MAX_PWM)
#endif

#ifndef _MPRT_BACKLIGHT_PWM_MIN
#define _MPRT_BACKLIGHT_PWM_MIN                    	(_BACKLIGHT_MAX_PWM)
#endif


#if(_PANEL_TYPE==_BOE_DV245QHB_N20_EDP_QHD180HZ)

#define _GAMUT_POST_DCI_P3_R						(0x7B)//(0x77)
#define _GAMUT_POST_DCI_P3_G						(0x7D)
#define _GAMUT_POST_DCI_P3_B						(0x7D)//(0x77)

#define _GAMUT_POST_SRGB_R							(0x7E)
#define _GAMUT_POST_SRGB_G							(0x7D)
#define _GAMUT_POST_SRGB_B							(0x7D)//(0x78)

#elif(_PANEL_TYPE==_INNOLUX_MV270KCA_D8B_EDP_QHD180HZ)
#define _GAMUT_POST_ADOBE_RGB_R						(0x76)
#define _GAMUT_POST_ADOBE_RGB_G						(0x80)
#define _GAMUT_POST_ADOBE_RGB_B						(0x80)

#define _GAMUT_POST_DCI_P3_R						(0x7C)
#define _GAMUT_POST_DCI_P3_G						(0x78)
#define _GAMUT_POST_DCI_P3_B						(0x7E)

#define _GAMUT_POST_SRGB_R							(0x7D)
#define _GAMUT_POST_SRGB_G							(0x80)
#define _GAMUT_POST_SRGB_B							(0x7F)

#elif(_PANEL_TYPE==_INNOLUX_MV270KCA_E8B_EDP_QHD180HZ)
#define _GAMUT_POST_ADOBE_RGB_R						(0x76)
#define _GAMUT_POST_ADOBE_RGB_G						(0x7E)
#define _GAMUT_POST_ADOBE_RGB_B						(0x7E)//(0x80)

#define _GAMUT_POST_DCI_P3_R						(0x7C)
#define _GAMUT_POST_DCI_P3_G						(0x76)
#define _GAMUT_POST_DCI_P3_B						(0x7E)

#define _GAMUT_POST_SRGB_R							(0x7D)//(0x7D)
#define _GAMUT_POST_SRGB_G							(0x7D)//(0x7E)
#define _GAMUT_POST_SRGB_B							(0x7F)//(0x80)

#elif(_PANEL_TYPE==_CSOT_SG2701B084_LVDS_FHD200HZ)

#define _GAMUT_POST_DCI_P3_R						(0x7C)
#define _GAMUT_POST_DCI_P3_G						(0x80)
#define _GAMUT_POST_DCI_P3_B						(0x7E)


#elif(_PANEL_TYPE==_CSOT_SG2381B084_LVDS_FHD240HZ)

#define _GAMUT_POST_DCI_P3_R						(0x7C)
#define _GAMUT_POST_DCI_P3_G						(0x80)
#define _GAMUT_POST_DCI_P3_B						(0x7E)


#else

#define _GAMUT_POST_ADOBE_RGB_R						(0x76)
#define _GAMUT_POST_ADOBE_RGB_G						(0x80)
#define _GAMUT_POST_ADOBE_RGB_B						(0x80)

#define _GAMUT_POST_DCI_P3_R						(0x7C)
#define _GAMUT_POST_DCI_P3_G						(0x78)
#define _GAMUT_POST_DCI_P3_B						(0x7E)

#define _GAMUT_POST_SRGB_R							(0x7D)
#define _GAMUT_POST_SRGB_G							(0x80)
#define _GAMUT_POST_SRGB_B							(0x7F)

#endif

#ifndef _GAMUT_POST_SRGB_R
#define _GAMUT_POST_SRGB_R             128
#endif

#ifndef _GAMUT_POST_SRGB_G
#define _GAMUT_POST_SRGB_G             128
#endif

#ifndef _GAMUT_POST_SRGB_B
#define _GAMUT_POST_SRGB_B             128
#endif

#ifndef _GAMUT_POST_DCI_P3_R
#define _GAMUT_POST_DCI_P3_R             128
#endif

#ifndef _GAMUT_POST_DCI_P3_G
#define _GAMUT_POST_DCI_P3_G             128
#endif

#ifndef _GAMUT_POST_DCI_P3_B
#define _GAMUT_POST_DCI_P3_B             128
#endif

#ifndef _GAMUT_POST_ADOBE_RGB_R
#define _GAMUT_POST_ADOBE_RGB_R             128
#endif

#ifndef _GAMUT_POST_ADOBE_RGB_G
#define _GAMUT_POST_ADOBE_RGB_G             128
#endif

#ifndef _GAMUT_POST_ADOBE_RGB_B
#define _GAMUT_POST_ADOBE_RGB_B             128
#endif


#ifndef DEF_FREESYNC_STATUS
#define DEF_FREESYNC_STATUS     _OFF
#endif


