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
// ID Code      : RTD2014OsdDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDDISPLAY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

bit HDR_OFF_FLAG = _OFF;	// ��¼û��HDRǰ�Ƿ�����˶Աȶ�
bit Aspect_Dcr_BacklightFlag = _OFF; // ��¼DCR������������߱Ȼ��������󱳹���

bit ucViewmodenotDrawosdflag = 0;


extern BYTE pageflag;
extern BYTE OsdDisplayGetPowerBarValue(void);
extern BYTE   Language_District_flang;   //2025.02.07  tx


void PageInit();

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_DEF_OSD_CURSOR_FLICKER_TIPS == _ON)
BYTE g_OsdCursorFlickerTips_Num = 0;		//0x60	----- �а������� �ָ�����Է�����
#endif
#if _OSD_Timing_Notice
BYTE g_usShowTimingNotice = 0;
#endif
//WORD BackUpTempVFreq = 0;	//��Freesync Ƶ�ʴ������

#if(_DEF_NAVIGATION_OSD_ENABLE)
//WORD SetCurrentMenuWidthHeightpos(BYTE currentOsdState,BYTE Offset,BYTE WH_select,BYTE PercentDirectSlect);
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _VGA_A0 = 0x01,
} EnumOsdSourceTypeVga;

typedef enum
{
    _DVI = 0x02,
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    _DVI_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    _DVI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    _DVI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    _DVI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    _DVI_D4,
#endif
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
    _DVI_D5,
#endif

    _HDMI = 0x10,
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
    _HDMI_D0,
#endif
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    _HDMI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
    _HDMI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
    _HDMI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
    _HDMI_D4,
#endif
#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
    _HDMI_D5,
#endif
}EnumOsdSourceTypeTMDS;

typedef enum
{
    _DP = 0x0E,
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    _DP_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    _DP_D1,
#endif
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    _DP_D2,
#endif
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
    _DP_D6,
#endif
} EnumOsdSourceTypeDP;

#define _FACTORY_WIN_5_8_BORDER_PIXEL          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _FACTORY_WIN_5_8_BORDER_COLOR          ((_CP_WHITE << 4) | _CP_WHITE)
#define _FACTORY_WIN_5_8_FUNC_CONTROL          (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_ENABLE | _3D_BUTTON_1)
#define _FACTORY_WIN_5_8_GRADIENT_CONTROL0     (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC)
#define _FACTORY_WIN_5_8_GRADIENT_CONTROL1     _3_LEVEL_RER_GRADIENT




#if(_LOGO_TYPE == _LOGO_THUNDEROBOT_2K)	
#define _LOGO_FG_COLOR							 	_LOGO_CP_WHITE
#define _LOGO_BG_COLOR								_LOGO_CP_BG  

#define _LOGO_FG_COLOR1 							_LOGO_CP_WHITE				
#define _LOGO_BG_COLOR1 							_LOGO_CP_BG	

#define _LOGO_COL_SIZE								(38)
#define _LOGO_ROW_SIZE								(14)

#define _LOGO_BG_RED								0
#define _LOGO_BG_GREEN								0
#define _LOGO_BG_BLUE								0					

#define _LOGO_ROW_START1							0  //���Ƿ�2���ص�logo����Ҫ����
#define _LOGO_COL_START1							28 //���Ƿ�2���ص�logo����Ҫ����

#elif(_LOGO_TYPE == _LOGO_MACHENIKE_2K)	
#define _LOGO_FG_COLOR							 	_LOGO_CP_BLUE
#define _LOGO_BG_COLOR								_LOGO_CP_WHITE

#define _LOGO_FG_COLOR1							 	_LOGO_CP_WHITE
#define _LOGO_BG_COLOR1								_LOGO_CP_BG

#define _LOGO_COL_SIZE								(22)
#define _LOGO_ROW_SIZE								(10)

#define _LOGO_BG_RED								0
#define _LOGO_BG_GREEN								96
#define _LOGO_BG_BLUE								255	

#define _LOGO_ROW_START1							0  //���Ƿ�2���ص�logo����Ҫ����
#define _LOGO_COL_START1							28 //���Ƿ�2���ص�logo����Ҫ����


#elif(_LOGO_TYPE == _LOGO_Suma)	
#define _LOGO_FG_COLOR							 	_LOGO_CP_RED_1
#define _LOGO_BG_COLOR								_LOGO_CP_BG  

#define _LOGO_FG_COLOR1 							_LOGO_CP_RED_1				
#define _LOGO_BG_COLOR1 							_LOGO_CP_BG	

#define _LOGO_COL_SIZE								(56)
#define _LOGO_ROW_SIZE								(9)

#define _LOGO_BG_RED								255
#define _LOGO_BG_GREEN								255
#define _LOGO_BG_BLUE								255

#define _LOGO_ROW_START1							0  //���Ƿ�2���ص�logo����Ҫ����
#define _LOGO_COL_START1							28 //���Ƿ�2���ص�logo����Ҫ����

#else
#define _LOGO_FG_COLOR							 	_LOGO_CP_BG
#define _LOGO_BG_COLOR								_LOGO_CP_WHITE  

#define _LOGO_FG_COLOR1 							_LOGO_CP_WHITE				
#define _LOGO_BG_COLOR1 							_LOGO_CP_BG	

#define _LOGO_COL_SIZE								(38)
#define _LOGO_ROW_SIZE								(14)


#define _LOGO_BG_RED								255
#define _LOGO_BG_GREEN								255
#define _LOGO_BG_BLUE								255					

#define _LOGO_ROW_START1							0  //���Ƿ�2���ص�logo����Ҫ����
#define _LOGO_COL_START1							28 //���Ƿ�2���ص�logo����Ҫ����

#endif


// WORD OsdDispDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
BYTE OsdDispJudgeSourceType(void);
void OsdDispDisableOsd(void);
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos);

// #if(_VGA_SUPPORT == _ON)
// void OsdDispMainSubString(BYTE ucState);
// #endif

// void OsdDispClearArrow(BYTE ucUpDown);
// void OsdDispMainMenuSubSelect(BYTE ucItem, WORD usOsdState, WORD usOsdStatePrevious);
// void OsdDispMainMenuCursor(WORD usOsdState, WORD usOsdStatePrevious, bit bInSubsidiary);
void OsdDispMainMenu(void);
void OsdDisplayDrawMainFrame(void);
void OsdDisplayDrawMainIcon(void);
void OsdDisplayDrawMainString(void);
void OsdDisplayKeyIndex(BYTE ucLayer);

void OsdDisplayReDrawMainWindow(bit Type);

void UpdateOSDSubMenu(BYTE subpage);
void UpdateMaskItem(void);
void UpdateMaskValue(void);

void UpdateOSDMainInterface(BYTE ucState);
void OsdDisplay2ndMenu(void);
void OsdDisplay3rdMenu(void);

void OsdDisplayMainCursor(BYTE ucType);
void OsdDisplaySliderAndNumber(BYTE ucOsdState, WORD usValue, BYTE ucType);

// void OsdDispSliderAndNumber(WORD usOsdState, WORD usValue);
void OsdDisplaySubSlider(BYTE ucRow, BYTE ucCol, WORD usValue, WORD usMax, WORD usMin, BYTE ucSliderLen,BYTE bSliderPage);

void OsdDisplaySubMenuItem(void);

WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);

void OsdDisplayBlackWindow(bit type);
void OsdDisplay5thMenu(void);

void OsdDisplaySixColorGetOneColor(BYTE ucColor);
void OsdDispHotKeySourceMenu(BYTE Type);
void OsdDispOsdMessage(EnumOSDDispMsg enumMessage);

#if(_VGA_SUPPORT == _ON)
void OsdDispAutoConfigProc(void);
void OsdDisplayAutoBalanceProc(void);
#endif

void OsdDispOsdReset(void);

#if(_DP_SUPPORT == _ON)
void OsdDispResetDpCapabilitySwitch(void);
#endif

void OsdDispShowLogo(void);

#if(_DEF_VGA_TIMING_KEY_2_4)
#if(_VGA_SUPPORT == _ON)
bit OsdDispModeSwitchReset(void);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
// BYTE OsdDisplayGetSourcePortString(void)
// {
//     switch(SysSourceGetInputPort())
//     {
// #if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
//         case _A0_INPUT_PORT:
//             return _STRING_A0_PORT;
// #endif
// #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
//         case _D0_INPUT_PORT:
//             return _STRING_D0_PORT;
// #endif
// #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
//         case _D1_INPUT_PORT:
//             return _STRING_D1_PORT;
// #endif
// #if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
//         case _D2_INPUT_PORT:
//             return _STRING_D2_PORT;
// #endif
// #if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
//         case _D3_INPUT_PORT:
//             return _STRING_D3_PORT;
// #endif
// #if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
//         case _D4_INPUT_PORT:
//             return _STRING_D4_PORT;
// #endif
// #if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
//         case _D5_INPUT_PORT:
//             return _STRING_D5_PORT;
// #endif
// #if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
//         case _D6_INPUT_PORT:
//             return _STRING_D6_PORT;
// #endif
//         default:
//             return _STRING_A0_PORT;
//     }
// }

// #if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description :
// Input Value :
// Output Value :
//--------------------------------------------------
// BYTE OsdDisplayGetVGAModeString(bit bUserMode)
// {
//     if(bUserMode == _USER_MODE_TYPE)
//     {
//         return _STRING_VGA_USER_MODE;
//     }
//     else
//     {
//         return _STRING_VGA_PRESET_MODE;
//     }
// }
// #endif

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
// WORD OsdDispDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
// {
//     usValue = usValue;
//     usMax = usMax;
//     usMin = usMin;
//     bCycle = bCycle;
//     return 0;
// }


// _OSD_ITEM_LENGTH
BYTE code OsdStateDefineDefault[_OSD_MAIN_LENGTH][12]={     

	{// 1
		_DEF_INPUT_P0_ITEM0,
		_DEF_INPUT_P0_ITEM1,
		_DEF_INPUT_P0_ITEM2,
		_DEF_INPUT_P0_ITEM3,
		_DEF_INPUT_P0_ITEM4,
		_DEF_INPUT_P0_ITEM5,
        _DEF_INPUT_P0_ITEM6,
		_DEF_INPUT_P0_ITEM7,
		_DEF_INPUT_P0_ITEM8,
		_DEF_INPUT_P0_ITEM9,
		_DEF_INPUT_P0_ITEM10,
		_DEF_INPUT_P0_ITEM11,
	},
#if (_MENU_AUDIO_SUPPORT)
	{// 2
		_DEF_AUDIO_P0_ITEM0,
		_DEF_AUDIO_P0_ITEM1,
		_DEF_AUDIO_P0_ITEM2,
		_DEF_AUDIO_P0_ITEM3,
		_DEF_AUDIO_P0_ITEM4,
		_DEF_AUDIO_P0_ITEM5,
        _DEF_AUDIO_P0_ITEM6,
		_DEF_AUDIO_P0_ITEM7,
		_DEF_AUDIO_P0_ITEM8,
		_DEF_AUDIO_P0_ITEM9,
		_DEF_AUDIO_P0_ITEM10,
		_DEF_AUDIO_P0_ITEM11,
	},
#endif
	{// 3
		_DEF_VIEWMODE_P0_ITEM0,
		_DEF_VIEWMODE_P0_ITEM1,
		_DEF_VIEWMODE_P0_ITEM2,
		_DEF_VIEWMODE_P0_ITEM3,
		_DEF_VIEWMODE_P0_ITEM4,
		_DEF_VIEWMODE_P0_ITEM5,
		_DEF_VIEWMODE_P0_ITEM6,
        _DEF_VIEWMODE_P0_ITEM7,
		_DEF_VIEWMODE_P0_ITEM8,
		_DEF_VIEWMODE_P0_ITEM9,
		_DEF_VIEWMODE_P0_ITEM10,
		_DEF_VIEWMODE_P0_ITEM11,
	},
	
	{// 4
		_DEF_COLOR_P0_ITEM0,
		_DEF_COLOR_P0_ITEM1,
		_DEF_COLOR_P0_ITEM2,
		_DEF_COLOR_P0_ITEM3,
		_DEF_COLOR_P0_ITEM4,
		_DEF_COLOR_P0_ITEM5,
        _DEF_COLOR_P0_ITEM6,
		_DEF_COLOR_P0_ITEM7,
		_DEF_COLOR_P0_ITEM8,
		_DEF_COLOR_P0_ITEM9,
		_DEF_COLOR_P0_ITEM10,
		_DEF_COLOR_P0_ITEM11,
	},


	{// 5
		_DEF_MANUAL_IMAGE_P0_ITEM0,
		_DEF_MANUAL_IMAGE_P0_ITEM1,
		_DEF_MANUAL_IMAGE_P0_ITEM2,
		_DEF_MANUAL_IMAGE_P0_ITEM3,
		_DEF_MANUAL_IMAGE_P0_ITEM4,
		_DEF_MANUAL_IMAGE_P0_ITEM5,
        _DEF_MANUAL_IMAGE_P0_ITEM6,
		_DEF_MANUAL_IMAGE_P0_ITEM7,
		_DEF_MANUAL_IMAGE_P0_ITEM8,
		_DEF_MANUAL_IMAGE_P0_ITEM9,
		_DEF_MANUAL_IMAGE_P0_ITEM10,
		_DEF_MANUAL_IMAGE_P0_ITEM11,
	},

	{// 6
		_DEF_SETUP_P0_ITEM0,
		_DEF_SETUP_P0_ITEM1,
		_DEF_SETUP_P0_ITEM2,
		_DEF_SETUP_P0_ITEM3,
		_DEF_SETUP_P0_ITEM4,
		_DEF_SETUP_P0_ITEM5,
        _DEF_SETUP_P0_ITEM6,
		_DEF_SETUP_P0_ITEM7,
		_DEF_SETUP_P0_ITEM8,
		_DEF_SETUP_P0_ITEM9,
		_DEF_SETUP_P0_ITEM10,
		_DEF_SETUP_P0_ITEM11,
	},


};



BYTE code OsdStateDefineDefault1[_OSD_MAIN_LENGTH][12]={     

	{// 1
		_DEF_INPUT_P1_ITEM0,
		_DEF_INPUT_P1_ITEM1,
		_DEF_INPUT_P1_ITEM2,
		_DEF_INPUT_P1_ITEM3,
		_DEF_INPUT_P1_ITEM4,
		_DEF_INPUT_P1_ITEM5,
        _DEF_INPUT_P1_ITEM6,
		_DEF_INPUT_P1_ITEM7,
		_DEF_INPUT_P1_ITEM8,
		_DEF_INPUT_P1_ITEM9,
		_DEF_INPUT_P1_ITEM10,
		_DEF_INPUT_P1_ITEM11,
	},

#if (_MENU_AUDIO_SUPPORT)
	{// 2
		_DEF_AUDIO_P1_ITEM0,
		_DEF_AUDIO_P1_ITEM1,
		_DEF_AUDIO_P1_ITEM2,
		_DEF_AUDIO_P1_ITEM3,
		_DEF_AUDIO_P1_ITEM4,
		_DEF_AUDIO_P1_ITEM5,
        _DEF_AUDIO_P1_ITEM6,
		_DEF_AUDIO_P1_ITEM7,
		_DEF_AUDIO_P1_ITEM8,
		_DEF_AUDIO_P1_ITEM9,
		_DEF_AUDIO_P1_ITEM10,
		_DEF_AUDIO_P1_ITEM11,
	},
#endif
	{// 3
		_DEF_VIEWMODE_P1_ITEM0,
		_DEF_VIEWMODE_P1_ITEM1,
		_DEF_VIEWMODE_P1_ITEM2,
		_DEF_VIEWMODE_P1_ITEM3,
		_DEF_VIEWMODE_P1_ITEM4,
		_DEF_VIEWMODE_P1_ITEM5,
		_DEF_VIEWMODE_P1_ITEM6,
        _DEF_VIEWMODE_P1_ITEM7,
		_DEF_VIEWMODE_P1_ITEM8,
		_DEF_VIEWMODE_P1_ITEM9,
		_DEF_VIEWMODE_P1_ITEM10,
		_DEF_VIEWMODE_P1_ITEM11,
	},
	
	{// 4
		_DEF_COLOR_P1_ITEM0,
		_DEF_COLOR_P1_ITEM1,
		_DEF_COLOR_P1_ITEM2,
		_DEF_COLOR_P1_ITEM3,
		_DEF_COLOR_P1_ITEM4,
		_DEF_COLOR_P1_ITEM5,
        _DEF_COLOR_P1_ITEM6,
		_DEF_COLOR_P1_ITEM7,
		_DEF_COLOR_P1_ITEM8,
		_DEF_COLOR_P1_ITEM9,
		_DEF_COLOR_P1_ITEM10,
		_DEF_COLOR_P1_ITEM11,
	},

	{// 5
		_DEF_MANUAL_IMAGE_P1_ITEM0,
		_DEF_MANUAL_IMAGE_P1_ITEM1,
		_DEF_MANUAL_IMAGE_P1_ITEM2,
		_DEF_MANUAL_IMAGE_P1_ITEM3,
		_DEF_MANUAL_IMAGE_P1_ITEM4,
		_DEF_MANUAL_IMAGE_P1_ITEM5,
        _DEF_MANUAL_IMAGE_P1_ITEM6,
		_DEF_MANUAL_IMAGE_P1_ITEM7,
		_DEF_MANUAL_IMAGE_P1_ITEM8,
		_DEF_MANUAL_IMAGE_P1_ITEM9,
		_DEF_MANUAL_IMAGE_P1_ITEM10,
		_DEF_MANUAL_IMAGE_P1_ITEM11,
	},

	{// 6
		_DEF_SETUP_P1_ITEM0,
		_DEF_SETUP_P1_ITEM1,
		_DEF_SETUP_P1_ITEM2,
		_DEF_SETUP_P1_ITEM3,
		_DEF_SETUP_P1_ITEM4,
		_DEF_SETUP_P1_ITEM5,
        _DEF_SETUP_P1_ITEM6,
		_DEF_SETUP_P1_ITEM7,
		_DEF_SETUP_P1_ITEM8,
		_DEF_SETUP_P1_ITEM9,
		_DEF_SETUP_P1_ITEM10,
		_DEF_SETUP_P1_ITEM11,
	},

};


#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)

BYTE code OsdStateDefineDefault2[6][12]={     

	{// 1
		_DEF_INPUT_P2_ITEM0,
		_DEF_INPUT_P2_ITEM1,
		_DEF_INPUT_P2_ITEM2,
		_DEF_INPUT_P2_ITEM3,
		_DEF_INPUT_P2_ITEM4,
		_DEF_INPUT_P2_ITEM5,
		_DEF_INPUT_P2_ITEM6,
		_DEF_INPUT_P2_ITEM7,
		_DEF_INPUT_P2_ITEM8,
		_DEF_INPUT_P2_ITEM9,
		_DEF_INPUT_P2_ITEM10,
		_DEF_INPUT_P2_ITEM11,
	},

	{// 2
		_DEF_AUDIO_P2_ITEM0,
		_DEF_AUDIO_P2_ITEM1,
		_DEF_AUDIO_P2_ITEM2,
		_DEF_AUDIO_P2_ITEM3,
		_DEF_AUDIO_P2_ITEM4,
		_DEF_AUDIO_P2_ITEM5,
		_DEF_AUDIO_P2_ITEM6,
		_DEF_AUDIO_P2_ITEM7,
		_DEF_AUDIO_P2_ITEM8,
		_DEF_AUDIO_P2_ITEM9,
		_DEF_AUDIO_P2_ITEM10,
		_DEF_AUDIO_P2_ITEM11,
	},

	{// 3
		_DEF_VIEWMODE_P2_ITEM0,
		_DEF_VIEWMODE_P2_ITEM1,
		_DEF_VIEWMODE_P2_ITEM2,
		_DEF_VIEWMODE_P2_ITEM3,
		_DEF_VIEWMODE_P2_ITEM4,
		_DEF_VIEWMODE_P2_ITEM5,
		_DEF_VIEWMODE_P2_ITEM6,
		_DEF_VIEWMODE_P2_ITEM7,
		_DEF_VIEWMODE_P2_ITEM8,
		_DEF_VIEWMODE_P2_ITEM9,
		_DEF_VIEWMODE_P2_ITEM10,
		_DEF_VIEWMODE_P2_ITEM11,
	},


	{// 4
		_DEF_COLOR_P2_ITEM0,
		_DEF_COLOR_P2_ITEM1,
		_DEF_COLOR_P2_ITEM2,
		_DEF_COLOR_P2_ITEM3,
		_DEF_COLOR_P2_ITEM4,
		_DEF_COLOR_P2_ITEM5,
		_DEF_COLOR_P2_ITEM6,
		_DEF_COLOR_P2_ITEM7,
		_DEF_COLOR_P2_ITEM8,
		_DEF_COLOR_P2_ITEM9,
		_DEF_COLOR_P2_ITEM10,
		_DEF_COLOR_P2_ITEM11,
	},

	{// 5
		_DEF_MANUAL_IMAGE_P2_ITEM0,
		_DEF_MANUAL_IMAGE_P2_ITEM1,
		_DEF_MANUAL_IMAGE_P2_ITEM2,
		_DEF_MANUAL_IMAGE_P2_ITEM3,
		_DEF_MANUAL_IMAGE_P2_ITEM4,
		_DEF_MANUAL_IMAGE_P2_ITEM5,
		_DEF_MANUAL_IMAGE_P2_ITEM6,
		_DEF_MANUAL_IMAGE_P2_ITEM7,
		_DEF_MANUAL_IMAGE_P2_ITEM8,
		_DEF_MANUAL_IMAGE_P2_ITEM9,
		_DEF_MANUAL_IMAGE_P2_ITEM10,
		_DEF_MANUAL_IMAGE_P2_ITEM11,
	},

	{// 6
		_DEF_SETUP_P2_ITEM0,
		_DEF_SETUP_P2_ITEM1,
		_DEF_SETUP_P2_ITEM2,
		_DEF_SETUP_P2_ITEM3,
		_DEF_SETUP_P2_ITEM4,
		_DEF_SETUP_P2_ITEM5,
		_DEF_SETUP_P2_ITEM6,
		_DEF_SETUP_P2_ITEM7,
		_DEF_SETUP_P2_ITEM8,
		_DEF_SETUP_P2_ITEM9,
		_DEF_SETUP_P2_ITEM10,
		_DEF_SETUP_P2_ITEM11,
	},


};

#endif

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : Source Port Number
//--------------------------------------------------
BYTE OsdDispJudgeSourceType(void)
{
    BYTE ucOsdSourcePort = _VGA_A0;

    switch(SysSourceGetInputPort())
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            ucOsdSourcePort = _VGA_A0;
            return ucOsdSourcePort;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            ucOsdSourcePort = _DVI_D0;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            ucOsdSourcePort = _HDMI_D0;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ucOsdSourcePort = _DP_D0;
#endif
            return ucOsdSourcePort;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            ucOsdSourcePort = _DVI_D1;
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            ucOsdSourcePort = _HDMI_D1;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ucOsdSourcePort = _DP_D1;
#endif
            return ucOsdSourcePort;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
            if(_DVI_D2 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D2;
            }
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if(_HDMI_D2 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D2;
            }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(_DP_D2 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D2;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
            if(_DVI_D3 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D3;
            }
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if(_HDMI_D3 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D3;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
            if(_DVI_D4 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D4;
            }
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            if(_HDMI_D4 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D4;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
            if(_DVI_D5 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D5;
            }
#endif

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            if(_HDMI_D5 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D5;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
            if(_DP_D6 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D6;
            }
#endif
            return ucOsdSourcePort;
#endif

        default:
            return ucOsdSourcePort;
    }
}

#if(_DEF_OSD_Freesync_Info_Eanble)





void OsdFreesyncOsdTimingRefresh(void)//Freesync	�˵�ʵʱˢ��Ƶ��
{
	WORD ucTempVfreq = GET_INPUT_TIMING_VFREQ();
	static WORD BackUpTempVFreq = 0;

	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_FREESYNC_OSD_EANBLE);
	if(GET_OSD_FREE_SYNC_STATUS() == _OFF)
	{
		return;
	}

	if(GET_OSD_STATE() == _MENU_NONE || GET_OSD_STATE() >= _MENU_NULL)
	{
		return;
	}

	if(GET_FACTORY_MODE() == _ON)
	{
		return;
	}
	
	if(BackUpTempVFreq == ucTempVfreq)
	{
		ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_FREESYNC_OSD_EANBLE);
		return;
	}

    g_usFontPointerRate = _OSD_PAGE_RATE_START;
	g_usFontPointerINF_RATE = _OSD_PAGE_INF_RATE_START;
	
    ScalerTimerWaitForEvent(_EVENT_DVS);

	if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_INFORMATION && GET_OSD_STATE()==_MENU_MISC_TATE4)
	{
		OsdPropPutStringPage0(ROW(_ROW_2ND_TEXT_START+2), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_INF_RATE, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_VFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	}

	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE || _DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#else
	OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE), _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION, _ON, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
#endif

	BackUpTempVFreq = ucTempVfreq;

	ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_FREESYNC_OSD_EANBLE);
}
#endif

#if _GSYNC_TEST
		void DrawRefreshNum(void)
		{
			 WORD g_u16TempVFreq = GET_INPUT_TIMING_VFREQ();
			 
			 g_u16TempVFreq = (g_u16TempVFreq+5)/10;
			
			if(g_u16TempVFreq<100)
				OsdFontPut1BitTable(0, 0, NumTable[11], COLOR(_CP_YELLOW, _CP_BG));
			else
				OsdFontPut1BitTable(0, 0, NumTable[g_u16TempVFreq/100], COLOR(_CP_YELLOW, _CP_BG));
		
			g_u16TempVFreq = g_u16TempVFreq%100;
		
			OsdFontPut1BitTable(0, 3, NumTable[g_u16TempVFreq/10], COLOR(_CP_YELLOW, _CP_BG));
			OsdFontPut1BitTable(0, 6, NumTable[g_u16TempVFreq%10], COLOR(_CP_YELLOW, _CP_BG));
		} 
		
	void OsdShowVFreq(void)
	{
		SET_OSD_STATE(_MENU_NONE);
		OsdFuncDisableOsd();
		g_ucOsdWidth = 0;
		g_ucOsdHeight = 0;
		g_ucOsdWidthB = 0;
		g_ucOsdHeightB = 0;
	
		OSD_SubMenuCur = 0;
		g_usOsdKeyDirectionType = _LAYER_NONE;
	
		SET_OSD_STATE(_OSD_HOTKEY_VFREQ);
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncApplyMap(WIDTH(9), HEIGHT(3), COLOR(_CP_YELLOW, _CP_BG)); 
	
		OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
		OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

		OsdFontVLCLoadFont(_FONT1_GLOBAL);
		OsdFontVLCLoadFont(_FONT1_VFREQ_NUMBER);
	
		DrawRefreshNum();
	
		// Adjust Color Palette
		OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
		//OsdFontPut2BitTable(ROW(0), COL(0), tiOSD_OSD_FRONT_SIGHT, COLOR0(_CP_BG) ,COLOR1(_CP_WHITE) ,COLOR2(_CP_DARKGRAY) ,COLOR3(_CP_RED));
	
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 2);
		OsdFuncEnableOsd();
	
		ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_UPDATE_VFREQ);
	
		//SET_OSD_FRONT_SIGHT(_ON);
		//RTDNVRamSaveOsdUserData();
	}
		
#endif



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispDisableOsd(void)
{
    SET_OSD_STATE(_MENU_NONE);
    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
    g_ucOsdWidth = 0;
    g_ucOsdHeight = 0;
    g_ucOsdWidthB = 0;
    g_ucOsdHeightB = 0;
	
	g_usOsdKeyDirectionType = _LAYER_NONE;
	

#if(_FRONT_SIGHT_FUNCTION == _ON)
	if((GET_OSD_FRONT_SIGHT() != _OFF) && (GET_OSD_EVENT_MESSAGE() == _OSDEVENT_NONE_MSG) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE))
	{
		ScalerTimerActiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_OSD_SHOW_Front_Sight);
	}
	else
#endif
#if _GSYNC_TEST
	if(GET_OSD_FREE_SYNC_STATUS() && GET_OSD_EVENT_MESSAGE()==_OSDEVENT_NONE_MSG && (SysModeGetModeState() ==_MODE_STATUS_ACTIVE) && (ucDsiableShowVFreqFlag == 0))
	{
		OsdShowVFreq();
	}
	else
#endif
	{
		#if _GSYNC_TEST
		if(ucDsiableShowVFreqFlag)
			ucDsiableShowVFreqFlag = 0;
		#endif
	}

#if 0//_OSD_Timing_Notice
	if(g_usShowTimingNotice==1&&GET_OSD_RESOLUTION_STATUS()==_ON&&!GET_FACTORY_MODE())
	{
		ScalerTimerActiveTimerEvent(SEC(30), _USER_TIMER_EVENT_OSD_SHOW_Timing_Notice);
	}
#endif

#if(_DEF_OSD_Freesync_Info_Eanble)	
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_FREESYNC_OSD_EANBLE);
#endif

#if(_HDR10_SUPPORT == _ON)
	if(GET_OSD_CONTRAST()!=_CONTRAST_DEFAULT && (UserCommonHDRGetHDR10Status() == _HDR10_ON) && HDR_OFF_FLAG)
	{
		HDR_OFF_FLAG=_OFF;
		SET_OSD_CONTRAST(_CONTRAST_DEFAULT);
		ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
	}	

#endif

#if(_DEF_OSD_GAMING == _ON)
	GAME_FLAG = 0;
	

	if((GET_OSD_PRE_GAME_TIME()!=_OFF || GET_OSD_PRE_GAME_CROSS()!=_OFF || GET_OSD_PRE_GAME_FPS()!=_OFF) \
		&& GET_OSD_EVENT_MESSAGE()==_OSDEVENT_NONE_MSG )
	{
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
		ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_GAME_HOTKEY);
	}

#endif

	DebugMessageOsd("0.OsdDispDisableOsd",GET_OSD_STATE());

}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos)
{
    WORD usX  = 0;
    WORD usY = 0;
    BYTE ucFonWidth = 12;
    BYTE ucFonHeight = 18;
    BYTE ucHorizontalDelayStep = 4;
    BYTE ucTempWidth = g_ucOsdWidth;
    BYTE ucTempHeight = g_ucOsdHeight;

    if((enumOsdPositionType == _OSD_POSITION_GLOBAL_B) ||
       (enumOsdPositionType == _OSD_POSITION_FONT_B))
    {
        ucTempWidth = g_ucOsdWidthB;
        ucTempHeight = g_ucOsdHeightB;
    }

    if(ScalerOsdGetHorizontalDelayStep() == _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL)
    {
        ucHorizontalDelayStep = 1;
    }

    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        ucFonWidth *= 2;
        ucFonHeight *= 2;
    }

    if(ucType == _POS_PERCENT)
    {
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
        }
#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempHeight * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempWidth * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
        }
#else
        usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
        usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
#endif
    }    
	else if(ucType == _OSD_HOTKEY_VIEWMODE)
    {
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usX = _KEY_VIEWMODE_POSION_H_ROTATE_270;
			usY = _KEY_VIEWMODE_POSION_V_ROTATE_270;
		}
		else
		{
			usX = _KEY_VIEWMODE_POSION_H;
			usY = _KEY_VIEWMODE_POSION_V;
		}

	} 
    else if(ucType == _OSD_HOTKEY_CONBRI)
    {		
    	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usX = _KEY_BRI_CON_POSION_H_ROTATE_270;
			usY = _KEY_BRI_CON_POSION_V_ROTATE_270;
		}
		else
		{		
			usX = _KEY_BRI_CON_POSION_H;
			usY = _KEY_BRI_CON_POSION_V;
		}

	}    
	else if(ucType == _OSD_HOTKEY_INPUT)
    {
        if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usX = _KEY_INPUT_POSION_H_ROTATE_270;
			usY = _KEY_INPUT_POSION_V_ROTATE_270;
		}
		else
		{
			usX = _KEY_INPUT_POSION_H;
			usY = _KEY_INPUT_POSION_V;
		}

	}	
#if(ENABLE_LANGUAGE_SELECT_OSD)			
	else if(ucType == _OSD_HOTKEY_LANGUAGE_SELECT)
    {
        if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usX = _KEY_MAIN_MENU_LANGUAGE_POSION_H_ROTATE_270;
			usY = _KEY_MAIN_MENU_LANGUAGE_POSION_V_ROTATE_270;
		}
		else
		{
			usX = _KEY_LANGUAGE_POSION_H;
			usY = _KEY_LANGUAGE_POSION_V;
		}
	}	
#endif
#if(_DEF_District_swtich_Message == _ON)
	else if(ucType == _OSD_HOTKEY_DISTRICT_SELECT)
    {
        if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usX = _KEY_DISTRICT_POSION_H_ROTATE_270;
			usY = _KEY_DISTRICT_POSION_V_ROTATE_270;
		}
		else
		{
			usX = _KEY_DISTRICT_POSION_H;
			usY = _KEY_DISTRICT_POSION_V;
		}
	}
#endif
    else
    {
        // Notice!!! if osd set double size need to check real position
        switch(GET_OSD_ROTATE_STATUS())
        {
            case _OSD_ROTATE_DEGREE_270:
		        usX = usHPos;
                usY = usVPos;		
               // usX = usHPos;
               // usY = _PANEL_DV_HEIGHT - usVPos - (DWORD)ucTempWidth * ucFonWidth;
                break;
            case _OSD_ROTATE_DEGREE_90:
                usX = _PANEL_DH_WIDTH - usHPos - (DWORD)ucTempHeight * ucFonHeight;
                usY = usVPos;
                break;
            default:
                usX = usHPos;
                usY = usVPos;
                break;
        }

    }
    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        usX = usX / 2;
        usY = usY / 2;
    }

	// �����˵�λ��-
	
#if(_OSD_KEY_FHD238) //
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT && GET_OSD_PC_HINT_STATUS() == _ON && GET_OSD_STATE()==_OSD_HOTKEY_FUNC)
		usX=usX+1;
	else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
#else
	if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
#endif
		usX=usX+1;
	else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_A)
		usX=usX-2;

#elif(_OSD_KEY_FHD270) //
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT && GET_OSD_PC_HINT_STATUS() == _ON && GET_OSD_STATE()==_OSD_HOTKEY_FUNC)
		usX=usX+4;
	else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
#else
	if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
#endif
		usX=usX+3;
	else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_A)
		usX=usX-1;

	
#endif
	
	DebugMessageOsd("2.ucType",ucType);
	DebugMessageOsd("2.usY",usY);
	
    OsdFuncSetPosition(enumOsdPositionType, usX, usY);
}


extern void OsdFuncSet4BitIconOffset(WORD ucOffset);

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------

void OsdDispMainMenu(void)
{


	#if _GSYNC_TEST
    ucDsiableShowVFreqFlag = 1;
	#endif
	OsdDispDisableOsd();
    OSD_SubMenuCur=0;  
	


	if(OSD_MAIN_MENU_ITEM == (_MENU_VIEWMODE - _OSD_MAIN_START))
	{
		if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))
			OSD_MAIN_MENU_ITEM = (_MENU_COLOR - _OSD_MAIN_START);
	}
	#if(_MENU_AUDIO_SUPPORT)
	else if((SysSourceGetSourceType()==_SOURCE_VGA) &&(OSD_MAIN_MENU_ITEM == (_MENU_AUDIO - _OSD_MAIN_START)))
		{
			OSD_MAIN_MENU_ITEM = (_MENU_VIEWMODE - _OSD_MAIN_START);
		}
	#endif
	
	PageInit();
	
	UpdateMaskValue();
	
	
	ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
	ScalerOsd2FontFunction(_ENABLE);
    //OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
	OsdFuncApplyMapOsdAB(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
						 WIDTH(_MAIN_B_OSD_WIDTH), HEIGHT(_MAIN_B_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
        
 #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
 	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,WIDTH(_OSD_MAIN_MENU_HEIGHT), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(_MAIN_B_OSD_HEIGHT),_OSD_FONT_LIB_ROTATION_ENABLE);
    // OsdFuncMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _OSD_MAP_B_REMAPPING_DISABLE, 0, _OSD_FONT_LIB_ROTATION_ENABLE);
 #endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // set 2bit Font offset
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
    
    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
	OsdFontVLCLoadFont(_FONT_1BIT_MAINMENUICON);
    OsdFontVLCLoadFont(_FONT_2BIT_GLOBAL);
	#if _GSYNC_TEST
	OsdFontVLCLoadFont(_FONT_1BIT_GSYNC);
	#endif
	

	
    OsdDisplayDrawMainFrame();

    OsdDisplayDrawMainIcon();

    OsdDisplayDrawMainString();
	
	DebugMessageOsd("1._OSD_PAGE_SN_END",_OSD_PAGE_SN_END);

	UpdateOSDMainInterface(OSD_MAIN_MENU_ITEM+_OSD_MAIN_START);

    OsdDisplayKeyIndex(_LAYER1);



#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_MAIN_MENU_POSION_H, _KEY_MAIN_MENU_POSION_V);

#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_MENU_POSION_H, _KEY_NAVIGATION_MENU_POSION_V);
#else
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#endif

#elif(_DEF_KEY_ROCKER)


	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
	{    
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A,_KEY_MAIN_MENU_POSION_H_ROTATE_270,_KEY_MAIN_MENU_POSION_V_ROTATE_270);   //0x203  0x198
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B,_KEY_NAVIGATION_POSION_H_ROTATE_270,_KEY_NAVIGATION_POSION_V_ROTATE_270);//0x24b  0x410
	}

	else
	{
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_MAIN_MENU_POSION_H, _KEY_MAIN_MENU_POSION_V);
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
	}

	//OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);

#endif

    // Osd Enable
    OsdFuncEnableOsd();

	
#if(_DEF_OSD_Freesync_Info_Eanble)
	ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_FREESYNC_OSD_EANBLE);
#endif
}


#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdDisplayDrawMainFrame(void)
{
    OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START + _FONT_WIDTH), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START), XEND(_MAIN_WIN_MAIN_FRAME_X_END - _FONT_WIDTH * 2), YEND(_MAIN_WIN_MAIN_FRAME_Y_END),COLOR0(_CP_DARKGRAY));
    OsdWindowDrawing(WINNO(_MAIN_WIN_FUN_FRAME),XSTART(_MAIN_WIN_FUN_FRAME_X_START + _FONT_WIDTH), YSTART(_MAIN_WIN_FUN_FRAME_Y_START), XEND(_MAIN_WIN_FUN_FRAME_X_END - _FONT_WIDTH), YEND(_MAIN_WIN_FUN_FRAME_Y_END),COLOR0(_CP_GRAY));

    // for Title
    OsdFontPut2BitTable(ROW(0), COL(0), tiOSD_2BIT_MAIN_TITLE, _CP_BG, _CP_BLUE, _CP_BLUE, _CP_DARKGRAY);
    OsdFontPut2BitTable(ROW(1), COL(_MAIN_OSD_WIDTH - 4), tiOSD_2BIT_MAIN_TITLE_PATCH_1, _CP_BG, _CP_BLUE, _CP_BLUE, _CP_DARKGRAY);
    OsdFontPut2BitTable(ROW(2), COL(_MAIN_OSD_WIDTH - 2), tiOSD_2BIT_MAIN_TITLE_PATCH_2, _CP_BG, _CP_BLUE, _CP_BLUE, _CP_DARKGRAY);
    OsdFontPut1BitTable(ROW(0), COL(_MAIN_OSD_WIDTH - 3), tiOSD_1BIT_MAIN_TITLE_PATCH_1, COLOR(_CP_BLUE, _CP_BG));
    OsdFontPut1BitTable(ROW(1), COL(_MAIN_OSD_WIDTH - 1), tiOSD_1BIT_MAIN_TITLE_PATCH_2, COLOR(_CP_BLUE, _CP_BG));
    OsdFontPut1BitTable(ROW(1), COL(1), tiOSD_1BIT_MAIN_TITLE_PATCH_3, COLOR(_CP_DARKGRAY, _CP_DARKGRAY));
    OsdFontPut1BitTable(ROW(3), COL(_MAIN_OSD_WIDTH - 2), tiOSD_1BIT_MAIN_TITLE_PATCH_4, COLOR(_CP_DARKGRAY, _CP_DARKGRAY));

    // for Left
    OsdFontPut2BitTable(ROW(1), COL(0), tiOSD_2BIT_MAIN_LEFT, _CP_BG, _CP_BLUE, _CP_BLUE, _CP_DARKGRAY);
    
    // for Right
    OsdFontPut2BitTable(ROW(3), COL(_MAIN_OSD_WIDTH - 1), tiOSD_2BIT_MAIN_RIGHT, _CP_BG, _CP_BLUE, _CP_BLUE, _CP_DARKGRAY);
    
    // for Bottom
    OsdFontPut1BitTable(ROW(_MAIN_OSD_HEIGHT - 1), COL(1), tiOSD_1BIT_MAIN_BOTTOM, COLOR(_CP_BLUE, _CP_DARKGRAY));

    // for Inside Board
    OsdFontPut1BitTable(ROW(9), COL(1), tiOSD_1BIT_MAIN_INSIDE_BOARD,COLOR(_CP_DARKGRAY, _CP_GRAY));
    OsdFontPut1BitTable(ROW(10), COL(17), tiOSD_1BIT_MAIN_SPLIT_LINE, COLOR(_CP_BLUE, _CP_GRAY));
    OsdFontPut1BitTable(ROW(10), COL(33), tiOSD_1BIT_MAIN_SPLIT_LINE, COLOR(_CP_BLUE, _CP_GRAY));
}
#else

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdDisplayDrawMainFrame(void)
{
    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
	{
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START-3), XEND(_MAIN_WIN_MAIN_FRAME_X_END), YEND(_MAIN_WIN_MAIN_FRAME_Y_END+2-18),COLOR0(_CP_DARKGRAY));
#else
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START-3), XEND(_MAIN_WIN_MAIN_FRAME_X_END), YEND(_MAIN_WIN_MAIN_FRAME_Y_END+2),COLOR0(_CP_DARKGRAY));
#endif
		OsdWindowDrawing(WINNO(_MAIN_WIN_FUN_FRAME),XSTART(_MAIN_WIN_FUN_FRAME_X_START), YSTART(_MAIN_WIN_FUN_FRAME_Y_START-3), XEND(_MAIN_WIN_FUN_FRAME_X_END), YEND(_MAIN_WIN_FUN_FRAME_Y_END+2),COLOR0(_CP_GRAY));
	}
	else
	{
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START), XEND(_MAIN_WIN_MAIN_FRAME_X_END), YEND(_MAIN_WIN_MAIN_FRAME_Y_END+2-18),COLOR0(_CP_DARKGRAY));
#else
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START), XEND(_MAIN_WIN_MAIN_FRAME_X_END), YEND(_MAIN_WIN_MAIN_FRAME_Y_END+2),COLOR0(_CP_DARKGRAY));
#endif
		OsdWindowDrawing(WINNO(_MAIN_WIN_FUN_FRAME),XSTART(_MAIN_WIN_FUN_FRAME_X_START), YSTART(_MAIN_WIN_FUN_FRAME_Y_START), XEND(_MAIN_WIN_FUN_FRAME_X_END), YEND(_MAIN_WIN_FUN_FRAME_Y_END+2),COLOR0(_CP_GRAY));
	}

    // vertical line
	OsdWindowDrawing(WINNO(_MAIN_WIN_V_DIVIDER1),XSTART(_MAIN_WIN_V_DIVIDER1_X_START), YSTART(_MAIN_WIN_V_DIVIDER1_Y_START), XEND(_MAIN_WIN_V_DIVIDER1_X_END), YEND(_MAIN_WIN_V_DIVIDER1_Y_END),COLOR0(_CP_DARKGRAY));
	OsdWindowDrawing(WINNO(_MAIN_WIN_V_DIVIDER2), XSTART(_MAIN_WIN_V_DIVIDER2_X_START), YSTART(_MAIN_WIN_V_DIVIDER2_Y_START), XEND(_MAIN_WIN_V_DIVIDER2_X_END), YEND(_MAIN_WIN_V_DIVIDER2_Y_END), COLOR0(_CP_DARKGRAY));
	
    // Main Frame
    OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_T), COL(_COL_MAIN_FRAME_ARC_L), tiOSD_1BIT_MAIN_FRAME_ARC_UL, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_T), COL(_COL_MAIN_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_B), COL(_COL_MAIN_FRAME_ARC_L), tiOSD_1BIT_MAIN_FRAME_ARC_DL, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_B), COL(_COL_MAIN_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(_CP_DARKGRAY, _CP_BG));
    // Sub Frame
    OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(_COL_SUB_FRAME_ARC_L), tiOSD_1BIT_MAIN_FRAME_ARC_UL, COLOR(_CP_GRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(_COL_SUB_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(_CP_GRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(_COL_SUB_FRAME_ARC_L), tiOSD_1BIT_MAIN_FRAME_ARC_DL, COLOR(_CP_GRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(_COL_SUB_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(_CP_GRAY, _CP_BG));


    //Draw arc font
    // for Title
    
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE || _DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#else

    //Draw Brand String
	OsdFontPut1BitTable(ROW(_ROW_TITLE_ARC), COL(_COL_TITLE), tiOSD_1BIT_MAIN_TITLE, COLOR(_CP_WHITE, _CP_DARKGRAY));
#if(_DEF_MENU_OSD_No_EDIDName_Mode)
	OsdPropPutStringPage0(ROW(_ROW_TITLE_ARC), COL(_COL_TITLE+9), _PFONT_PAGE_TITLE, _STRING_MODEL_NAME, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), _ENGLISH);
#endif
	OsdFontPut1BitTable(ROW(_ROW_TITLE_ARC), COL(_COL_TITLE_ARC_L), tiOSD_1BIT_MAIN_TITLE_ARC_L, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(_ROW_TITLE_ARC), COL(_COL_TITLE_ARC_R), tiOSD_1BIT_MAIN_TITLE_ARC_R, COLOR(_CP_DARKGRAY, _CP_BG));

#endif

    //Draw frame patch font
	OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_T), COL(1), tiOSD_1BIT_MAIN_WIN0_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(_ROW_MAIN_FRAME_ARC_B), COL(1), tiOSD_1BIT_MAIN_WIN0_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(2), tiOSD_1BIT_MAIN_WIN1_PATCH, COLOR(_CP_WHITE, _CP_GRAY));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(2), tiOSD_1BIT_MAIN_WIN1_PATCH, COLOR(_CP_WHITE, _CP_GRAY));



#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE || _DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#else

    // For bottom OSD(power and resolution)
    //border
	OsdFontPut1BitTable(ROW(22), COL(1), tiOSD_1BIT_MAIN_BOTTOM_T_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(24), COL(3), tiOSD_1BIT_MAIN_BOTTOM_B_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));

	OsdFontPut1BitTable(ROW(23), COL(1), tiOSD_1BIT_MAIN_BOTTOM_ML_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(23), COL(23), tiOSD_1BIT_MAIN_BOTTOM_MM_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(23), COL(47), tiOSD_1BIT_MAIN_BOTTOM_MR_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	
#if(_ECO_POWET_EXCHANGE)
    OsdFontPut1BitTable(ROW(_ROW_POWER_BAR), COL(_COL_POWER_BAR_ICON+1), tiOSD_1BIT_MAIN_ECO, COLOR(_CP_EN_BLUE, _CP_DARKGRAY));
#else
    // power icon
	OsdFontPut1BitTable(ROW(_ROW_POWER_BAR), COL(_COL_POWER_BAR_ICON), tiOSD_1BIT_MAIN_POWER, COLOR(_CP_WHITE, _CP_DARKGRAY));
#endif
    //power slider
    //OsdDisplaySliderAndNumber(_MENU_NONE, OsdDisplayGetPowerBarValue(), _SLIDER_POWER);
	OsdDisplaySubSlider(ROW(_ROW_POWER_BAR), COL(_COL_POWER_BAR), OsdDisplayGetPowerBarValue(), _SLIDER_MAX, _SLIDER_MIN, _SLIDER_BAR_LENGTH, _OSD_POWER_BAR_TYPE);
	OsdPropShowNumber(ROW(_ROW_POWER_BAR), COL(_COL_POWER_BAR_VALUE), OsdDisplayGetPowerBarValue(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_4), _PFONT_PAGE_POWER, COLOR(_CP_WHITE, _CP_BG));

    // resolution icon
	OsdFontPut1BitTable(ROW(_ROW_RESOLUTION_BAR), COL(_COL_RESOLUTION_ICON), tiOSD_1BIT_MAIN_INFORMATION, COLOR(_CP_WHITE, _CP_DARKGRAY));

	//OsdPropPutStringCenter(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE), 15, _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION, _ON, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);

#if(_5KEY_MENU_STYLE)  //2025.02.11 tx
	if(GET_INPUT_TIMING_HWIDTH()==1920&&GET_INPUT_TIMING_VHEIGHT()==1080)//&&((GET_INPUT_TIMING_VFREQ()>=580&&GET_INPUT_TIMING_VFREQ()<=610)||(GET_INPUT_TIMING_VFREQ()>=740&&GET_INPUT_TIMING_VFREQ()<=760)))
    	OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE), _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION, _ON, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	else
	{
		OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE), _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION_WARNING, _ON, COLOR(_CP_YELLOW, _CP_BG), _ENGLISH);//timing�����־ lj 0228
		OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE+1), _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION, _ON, COLOR(_CP_RED, _CP_BG), _ENGLISH);
	}
#else
	OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_RESOLUTION_VALUE), _PFONT_PAGE_RATE, _STRING_2ND_NOW_RESOLUTION, _ON, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	
	#if _GSYNC_TEST
		//ScalerTimerActiveTimerEvent(SEC(0.5),_USER_TIMER_EVENT_UPDATE_MAINMENU_VFREQ);
	#endif
	
#endif		

#if(_HDR10_SUPPORT == _ON)
	if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
	{
		OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_SDR_HDR_STATUS), _PFONT_PAGE_HDR, _STRING_HDR, 0, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	}
#endif

#endif


}

#endif


//--------------------------------------------------
// Description      : Draw Main Menu icon and color
// Input Value      : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplayDrawMainIcon(void)
{
	BYTE i=0;
	BYTE Color = _CP_WHITE;
	
	for(i=0;i<_OSD_MAIN_LENGTH;i++)
	{
		OsdFontPut1BitTable(ROW(2), COL(2+(i*8)), tiOSD_1BIT_MAIN_ICON_T_PATCH, COLOR(_CP_DARKGRAY, _CP_BG));
		
		if(i == _MENU_VIEWMODE - _OSD_MAIN_START && OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))
			Color = _CP_BLOCK;
		else
			Color = _CP_WHITE;

#if(_DEF_JS_KEY_ICON_5_KEY_MODE)	

	#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
		if(i==1)
			Color = _CP_BLOCK;
		if(i==1||i==3)
        	OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], _CP_BG, Color, _CP_GRAY, _CP_GRAY);
        else
			OsdFontPut1BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], COLOR(_CP_WHITE, _CP_BG));	 

	#else


		if(i==3||i==4)
        	OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], _CP_BG, Color, _CP_GRAY, _CP_GRAY);
        else
        {    
		#if(_5KEY_MENU_STYLE)           
        if((i==1&&GET_OSD_VOLUME_MUTE()==_ON)&&(SysSourceGetSourceType() != _SOURCE_VGA))   //2025.2.11 tx
	    {
		 	OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[6], _CP_BG, Color,(OSD_MAIN_MENU_ITEM==1?_CP_BLUE : _CP_DARKGRAY), _CP_RED);	
		}
		else if(SysSourceGetSourceType()==_SOURCE_VGA &&i==1)
		{
			OsdFontPut1BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], COLOR( _CP_GRAY, _CP_BG));	 
		}
		else
		#endif	
	       {       //  2025.2.11  tx  (SysSourceGetSourceType()==_SOURCE_VGA ? _CP_GRAY:
	        
			OsdFontPut1BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], COLOR( _CP_WHITE, _CP_BG));	 
	       }
		}
		
	#endif


#else
        OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(i*8)), tiOSD_2BIT_MAIN_ICON[i], _CP_BG, Color, _CP_GRAY, _CP_GRAY);
#endif
		OsdFontPut1BitTable(ROW(7), COL(2+(i*8)), tiOSD_1BIT_MAIN_ICON_B_PATCH, COLOR(_CP_DARKGRAY, _CP_BG));
	}
	

}

//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     :
//--------------------------------------------------
void OsdDisplayDrawMainString(void)
{
	BYTE i = 0;

	for(i=0;i<_OSD_MAIN_LENGTH;i++)
	{
		if(i == _MENU_VIEWMODE - _OSD_MAIN_START)
		{
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START0), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM0, i, COLOR((OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))? _CP_BLOCK : _CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START1), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM1, i, COLOR((OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))? _CP_BLOCK : _CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

		}
		else
		{
		
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
		#if(_MENU_AUDIO_SUPPORT)
		if(i == _MENU_AUDIO - _OSD_MAIN_START)
		{
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START0), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM0, i, COLOR(_CP_BLOCK, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START1), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM1, i, COLOR(_CP_BLOCK, _CP_BG), GET_OSD_LANGUAGE());
		}
		else
		#endif
		{
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START0), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM0, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START1), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM1, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		}

#else			

#if(_5KEY_MENU_STYLE)           
		    if(SysSourceGetSourceType() == _SOURCE_VGA&&i==1)   //2025.2.11 tx
		    {		
		     
			 OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START0), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM0, i, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
			 OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START1), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM1, i, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
		    }
			else
#endif	
			{
				OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START0), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM0, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				OsdPropPutStringCenter(ROW(_ROW_MAIN_TEXT_START1), COL(_COL_MAIN_TEXT_START(i)), 7, _PFONT_PAGE_0, _STRING_TITLE_ITEM1, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			}
#endif


		}

	}

}

bit OsdDisplayCheckkeyValid(void)
{
	if(ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_BUININ_MSG) == _TRUE)
		return _FALSE;

	// ���������ø� �� ����ز���Ч
	if(KeyActionFlag && bBACKLIGHTPOWER==0)
	{
		return _FALSE;
	}
	
	DebugMessageOsd("1.CheckkeyValid_OSD_STATE",GET_OSD_STATE());
		
	switch(GET_OSD_STATE())
	{
		case _OSD_MSG_NOTHING:
			
			return _FALSE;


		default:
			break;
	}
	return _TRUE;
}

//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     :
//--------------------------------------------------
void OsdDisplayKeyIndex(BYTE ucLayer)
{
// 	WORD WindowRotateOffset = 0;
//     bit  flag=0;
// 	BYTE ColOffset = 0;

// 	if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
// 	{
// 		if(ucLayer == _LAYER_POWER_CONSUMPTION )
// 			WindowRotateOffset = 37;
// 		else if(ucLayer == _LAYER_Timing_Tips )
// 			WindowRotateOffset = 13;		
// 		else if(ucLayer == _LAYER1 || ucLayer == _LAYER2 || ucLayer == _LAYER_VOLUME_ADJUST || ucLayer == _LAYER4_ADJ || ucLayer == _LAYER3)
// 			WindowRotateOffset = (12*32+1);
// 		else
// 			WindowRotateOffset = 11;

// 	}

		
// 	g_usOsdKeyDirectionType = ucLayer;
	
// 	DebugMessageOsd("1.ucLayer",ucLayer);
	
// #if(_DEF_JS_KEY_ICON_5_KEY_MODE)
// 	//DebugMessageOsd("1.OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]",OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
// 	// key icon
// 	if(ucLayer == _LAYER1)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 	}
// 	else if(ucLayer==_LAYER_VOLUME_ADJUST )
// 	{

// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		//OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

  
			 
//       // OsdDisplayMainCursor

// 	    if(GET_OSD_VOLUME_MUTE()==_ON)                  //2025.02.08 tx                                           
// 	   {
// #if(_5KEY_MENU_STYLE)  
//         if(SysSourceGetSourceType()!=_SOURCE_VGA)           //2025.02.11 tx   
// 	     OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(1*8)), tiOSD_2BIT_MAIN_ICON[6], _CP_BG, _CP_WHITE, (OSD_MAIN_MENU_ITEM==1? _CP_BLUE : _CP_DARKGRAY), _CP_RED);
// #endif
//          OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));	
// 		// OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL+ (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BLUE_EG), COLOR1(_CP_WHITE), COLOR2(_CP_WHITE), COLOR3(_CP_RED));
         
// 		}
// 		else
// 	   {
// #if(_5KEY_MENU_STYLE)   	   
// 	     OsdFontPut1BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(1*8)), tiOSD_2BIT_MAIN_ICON[1], COLOR((SysSourceGetSourceType()==_SOURCE_VGA ? _CP_GRAY: _CP_WHITE), _CP_BG));  //2025.02.11 tx
// #endif
// 		 //OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
//           OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL+ (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BLUE_EG), COLOR1(_CP_WHITE), COLOR2(_CP_WHITE), COLOR3(_CP_RED));
         
// 	   }
// }

	
// 	else if(ucLayer == _LAYER_FACTORY)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

// 	}	
// 	else if(ucLayer == _LAYER_FACTORY_ADJ)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_None_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X_FACTORY, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

// 	}

// 	else if((ucLayer == _LAYER2) || (ucLayer == _LAYER3))
// 	{
	
// 		if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER )
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		}
// 		else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_INFORMATION)
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE,   (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		}
// 		else
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP,   COLOR(_CP_WHITE,   (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes,  COLOR(_CP_WHITE,  (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		}
		

// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back,  COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X,     COLOR(_CP_WHITE,    (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

// 	}
// 	else if(ucLayer == _LAYER4_ADJ)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT,  COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_None,  COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Back,  COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X,     COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 	}
// #if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
// 	else if(ucLayer == _LAYER_POWER_CONSUMPTION)
// 	{
//         OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL+ (_KEY_ICON_WIDTH) * 0, tiOSD_OSDKEY_ICON_POWER_CONSUMPTION_YES, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH) * 3 , tiOSD_OSDKEY_ICON_X,                 COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH) * 4 , tiOSD_OSDKEY_ICON_Power,             COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 	}
// #endif

// 	else if(ucLayer == _LAYER_Timing_Tips)
// 	{  
// 		// ���˵�ʹ�ܸô��ڵ���ɫ��Ҫ����
//     	ScalerOsdWindowHighlightFunction(_DISABLE, _OSD_WINDOW_4_1, _CP_WHITE, _CP_DARKGRAY, _CP_BG);
//     	ScalerOsdWindowHighlightFunction(_DISABLE, _OSD_WINDOW_4_2, _CP_WHITE, _CP_DARKGRAY, _CP_BG);

// 	    OsdWindowDrawing(_OSD_WINDOW_4_1,0, 17, 12*7, 18*3+1, COLOR0(_KEY_BLACK== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1), COL(1+_KEY_INDEX_COL), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 0, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1+1), COL(1+_KEY_INDEX_COL), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 1, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
	
// 	    OsdWindowDrawing(_OSD_WINDOW_4_2,9*12,17,12*16,18*3+1 ,COLOR0(_KEY_BLACK== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1), COL(1+_KEY_INDEX_COL+9), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_2, (_STRING_NOTICE_KEY_DESCRIBE), 6,	COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1+1), COL(1+_KEY_INDEX_COL+9), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_2, (_STRING_NOTICE_KEY_DESCRIBE), 7, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());

// 		SET_OSD_WINDOW_REFERENCE_DELAY(0);
		



// 	/*
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL, tiOSD_OSDKEY_ICON_NOTICE, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW), COL(2+_KEY_INDEX_COL), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 0, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1), COL(2+_KEY_INDEX_COL), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 1, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());

// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL+9, tiOSD_OSDKEY_ICON_NOTICE1, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW), COL(1+_KEY_INDEX_COL+9), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_2, (_STRING_NOTICE_KEY_DESCRIBE), 6,	COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW+1), COL(1+_KEY_INDEX_COL+9), _MAIN_B_BEST_ICON_WIDTH, _PFONT_PAGE_2, (_STRING_NOTICE_KEY_DESCRIBE), 7, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY), GET_OSD_LANGUAGE());
//    */
   
		
// 	}

// 	else if(ucLayer == _LAYER_HOTKEY)
// 	{
// 		switch (OSD_HOT_KEY_PAGE)
// 		{
// #if(ENABLE_LANGUAGE_SELECT_OSD)			
// 			case _OSD_HOTKEY_LANGUAGE_SELECT:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_LANGUAGE;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_Power, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				break;
// #endif
// #if(_DEF_District_swtich_Message == _ON)
// 			case _OSD_HOTKEY_DISTRICT_SELECT:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_DISTRICT;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_Power, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				break;
// #endif
// 			case _OSD_HOTKEY_VIEWMODE:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_VIEWMODE;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, (_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// #if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_X_1, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

// #else

// 				#if(_MENU_AUDIO_SUPPORT)
// #if(_5KEY_MENU_STYLE)    //2025.02.11 tx
// 				if(SysSourceGetSourceType() == _SOURCE_VGA)
//                 OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
//                 else
// #endif
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				#else
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				#endif
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));

// #endif

// 				break;	
// #if(_MENU_AUDIO_SUPPORT)
// 			case _OSD_HOTKEY_VOLUME:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_VOLUME;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
//                 flag=1;
// 				break;
// #endif
// 			case _OSD_HOTKEY_CONBRI:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_CONBRI;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_UpDown, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				break;
// 			case _OSD_HOTKEY_INPUT:
// 				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE && GET_FACTORY_BURNIN()==_OFF  \
// 		&& ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL))
// 					g_usOsdKeyDirectionType = _LAYER_HOTKEY_INPUT_NOSIGNAL;
// 				else
// 					g_usOsdKeyDirectionType = _LAYER_HOTKEY_INPUT;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_X_1, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				#else
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				#endif
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
// 				break;

// 			default:
// 				break;
// 		}
		
// 	}
// #if(_DEF_NAVIGATION_OSD_ENABLE)
// #if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
// 	else if(ucLayer == _LAYER_NAVIGAT)
// 	{
// 		OsdFontPut1BitTable( _KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable( _KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable( _KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Menu, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable( _KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_X_1, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));

// 	}
// #endif	
// #endif	



// 	if(g_usOsdKeyDirectionType == _LAYER_Timing_Tips)
// 	{

// 	}
// #if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
// 	else if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
// 	{
	
// 	}
// #endif
// 	else
// 	{
	
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 0, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_OFFSET), _CP_BG, _OSD_BLANK_ALIGN);
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 1, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_GAP), _CP_BG, _OSD_BLANK_ALIGN);
// #if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_GAP), _CP_BG, _OSD_BLANK_ALIGN);
// #else
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2-1, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_GAP), _CP_BG, _OSD_BLANK_ALIGN);
// #endif
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 3, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_GAP), _CP_BG, _OSD_BLANK_ALIGN);
// 		UserCommonOsdBlankFont(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 4, LENGTH(1), HEIGHT(_KEY_ICON_HEIGHT), LENGTH(_KEY_INDEX_GAP), _CP_BG, _OSD_BLANK_ALIGN);
		
// 		if (GET_OSD_VOLUME_MUTE() == _OFF&&flag==1)
// 		{
// 		  OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_KONG, COLOR(_CP_BG,_CP_BG));	
// 		  OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL+ (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BLUE_EG), COLOR1(_CP_WHITE), COLOR2(_CP_WHITE), COLOR3(_CP_RED));
// 		}
// 		flag=0;

// 	}

	

// /*******************************************_DEF_KEY_ROCKER************************************************/
// #elif(_DEF_KEY_ROCKER)
		
// 	// key icon
// 	if(0);
// #if(_DEF_NAVIGATION_OSD_ENABLE)
// 	else if(ucLayer == _LAYER_NAVIGAT)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_Menu, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));

// 	}
// #endif	
// 	else if(ucLayer == _LAYER1)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_Info, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 	}
// 	else if(ucLayer == _LAYER_NoFun)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 	}
// 	else if(ucLayer == _LAYER_VOLUME_ADJUST)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 	}
// 	else if((ucLayer == _LAYER2)||(ucLayer == _LAYER3))
// 	{
	
// 		if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		}
// 		else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_INFORMATION)
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		}
// 		else
// 		{
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 			OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		}


// 	}
// 	else if(ucLayer == _LAYER4_ADJ || ucLayer == _LAYER_SLIDER_ADJUST)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 	}
// 	else if(ucLayer == _LAYER_FACTORY || ucLayer == _LAYER_FACTORY_ADJ)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_Back, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 	}	
// 	else if(ucLayer == _LAYER_Timing_Tips)
// 	{
// 		if(1)//(GET_OSD_LANGUAGE() == _RUSSIA)
// 			ColOffset = 1;
		
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL+1+ColOffset, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		//OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL+1+ColOffset, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		//OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL+1+ColOffset, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW), COL(1), 6, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 0, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW+1), COL(1), 6, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 1, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW), COL(_KEY_2_ICON_COL+3), 6, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 6, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW+1), COL(_KEY_2_ICON_COL+3), 6, _PFONT_PAGE_1, (_STRING_NOTICE_KEY_DESCRIBE), 7, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());

// 	}
// #if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
// 	else if(ucLayer == _LAYER_POWER_CONSUMPTION)
// 	{
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		//OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		//OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_None_Tis, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW), COL(0), 6, _PFONT_PAGE_1, (_STRING_POWER_CONSUMPTION_HINT), 5, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());
// 		OsdPropPutStringCenter(ROW(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW), COL(_KEY_2_ICON_COL+2), 6, _PFONT_PAGE_1, (_STRING_POWER_CONSUMPTION_HINT), 6, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR), GET_OSD_LANGUAGE());

// 	}
// #endif
// 	else if(ucLayer == _LAYER_HOTKEY)
// 	{
// 		switch (OSD_HOT_KEY_PAGE)
// 		{
// #if(ENABLE_LANGUAGE_SELECT_OSD)			
// 			case _OSD_HOTKEY_LANGUAGE_SELECT:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_LANGUAGE;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// #endif
// #if(_DEF_District_swtich_Message == _ON)
// 			case _OSD_HOTKEY_DISTRICT_SELECT:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_DISTRICT;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_None, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// #endif
// 			case _OSD_HOTKEY_VIEWMODE:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_VIEWMODE;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// 			case _OSD_HOTKEY_VOLUME:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_VOLUME;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 0, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 1, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				// OsdFontPut1BitTable((2 * HotKeyPageIndex + 7), 10, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 3, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 4, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// 			case _OSD_HOTKEY_CONBRI:
// 				g_usOsdKeyDirectionType = _LAYER_HOTKEY_CONBRI;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_LEFT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_ConBri, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_RIGHT, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_UpDown, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// 			case _OSD_HOTKEY_INPUT:
				
// 				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE && GET_FACTORY_BURNIN()==_OFF )
// 					g_usOsdKeyDirectionType = _LAYER_HOTKEY_INPUT_NOSIGNAL;
// 				else
// 					g_usOsdKeyDirectionType = _LAYER_HOTKEY_INPUT;
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_3_ICON_ROW, _KEY_3_ICON_COL, tiOSD_OSDKEY_ICON_UP, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_1_ICON_ROW, _KEY_1_ICON_COL, tiOSD_OSDKEY_ICON_X, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_5_ICON_ROW, _KEY_5_ICON_COL, tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_2_ICON_ROW, _KEY_2_ICON_COL, tiOSD_OSDKEY_ICON_Yes, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET + _KEY_4_ICON_ROW, _KEY_4_ICON_COL, tiOSD_OSDKEY_ICON_DOWN, COLOR(_CP_WHITE, _KEY_ICON_BG_COLOR));
// 				break;
// 			default:
// 				break;
// 		}
		
// 	}


// #if(_OSD_SHOW_KEY_BORDER)


// 		if((ucLayer == _LAYER_POWER_CONSUMPTION))
// 		{
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_1), PIXELCOL(_KEY_5_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_5_ICON_COL+6)+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_2), PIXELCOL(_KEY_3_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_3_ICON_COL+6)+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_3), PIXELCOL(_KEY_4_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_4_ICON_COL+6)+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_4), 2+WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW)-1, 
// 											PIXELCOL(6)-2+WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_5), PIXELCOL(_KEY_2_ICON_COL+2)+WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_2_ICON_COL+8)-2+WindowRotateOffset,PIXELROW(_KEY_2_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 		}		
// 		else if(ucLayer == _LAYER_Timing_Tips )
// 		{
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_1), PIXELCOL(_KEY_5_ICON_COL+1)-1+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_5_ICON_COL+_KEY_WINDOW_COL+3+ColOffset)+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_2), PIXELCOL(_KEY_3_ICON_COL+1)-1+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_3_ICON_COL+_KEY_WINDOW_COL+3+ColOffset)+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_3), PIXELCOL(_KEY_4_ICON_COL+1)-1+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_4_ICON_COL+_KEY_WINDOW_COL+3+ColOffset)+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_4), 12+WindowRotateOffset-1,	PIXELROW(_KEY_1_ICON_ROW)-1, 
// 											PIXELCOL(+_KEY_WINDOW_COL+3+ColOffset)+WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_5), PIXELCOL(_KEY_2_ICON_COL+3)-1+WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_2_ICON_COL+_KEY_WINDOW_COL+5+ColOffset)+WindowRotateOffset,PIXELROW(_KEY_2_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 		}		
// 		else if((ucLayer == _LAYER1 || ucLayer == _LAYER2 || ucLayer == _LAYER_VOLUME_ADJUST || ucLayer == _LAYER4_ADJ || ucLayer == _LAYER3) && GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270 )
// 		{
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_1), PIXELCOL(_KEY_5_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_5_ICON_COL+_KEY_WINDOW_COL)+WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_2), PIXELCOL(_KEY_3_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_3_ICON_COL+_KEY_WINDOW_COL)+WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�
											
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_3), PIXELCOL(_KEY_4_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_4_ICON_COL+_KEY_WINDOW_COL)+WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_4), PIXELCOL(_KEY_1_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_1_ICON_COL+_KEY_WINDOW_COL)+WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_5), PIXELCOL(_KEY_2_ICON_COL)-1+WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_2_ICON_COL+_KEY_WINDOW_COL)+WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 		}
// 		else
// 		{
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_1), PIXELCOL(_KEY_5_ICON_COL)-1-WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_5_ICON_COL+_KEY_WINDOW_COL)-WindowRotateOffset,	PIXELROW(_KEY_5_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_2), PIXELCOL(_KEY_3_ICON_COL)-1-WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_3_ICON_COL+_KEY_WINDOW_COL)-WindowRotateOffset,	PIXELROW(_KEY_3_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�
											
// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_3), PIXELCOL(_KEY_4_ICON_COL)-1-WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW)-1, 
// 											PIXELCOL(_KEY_4_ICON_COL+_KEY_WINDOW_COL)-WindowRotateOffset,	PIXELROW(_KEY_4_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_4), PIXELCOL(_KEY_1_ICON_COL)-1-WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_1_ICON_COL+_KEY_WINDOW_COL)-WindowRotateOffset,	PIXELROW(_KEY_1_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 			OsdWindowDrawing(WINNO(_OSD_WINDOW_5_5), PIXELCOL(_KEY_2_ICON_COL)-1-WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW)-1, 
// 												PIXELCOL(_KEY_2_ICON_COL+_KEY_WINDOW_COL)-WindowRotateOffset,	PIXELROW(_KEY_2_ICON_ROW+2),COLOR0(_KEY_ICON_BG_COLOR));	//�׵ױ߿�

// 		}
		
// 		SET_OSD_WINDOW_REFERENCE_DELAY(0);

// #endif // END - _OSD_SHOW_KEY_BORDER



		
// #endif



}



// �����û�
void UpdataOSDChangeColor()
{
	
	BYTE j= 0;
	BYTE ucOsdState = 0;

	if(GET_OSD_STATE() != _OSD_HOTKEY_FUNC)
	{
		for(j=0;j<_OSD_ITEM_LENGTH;j++)
		{
			ucOsdState=OsdStateDefine[OSD_MAIN_MENU_ITEM][j];
			if(OsdStateDefine[OSD_MAIN_MENU_ITEM][j]== _MENU_NULL)
				break;
			
			//if(OSD_SubMenuCur== j)
				//break;
		
			
			switch(GetOsdShowType(ucOsdState))
			{ 
			/*
				case _TYPE_SLIDER:
					if(OSD_ITEM(ucOsdState)>>4 == OSD_MAIN_MENU_ITEM)
					{
						if(OSD_ITEM_MASK_GET(ucOsdState))
							ScalerOsdChange1BitColor(ROW(_OSD_SUB_ITEM0_ROW+j*_OSD_SUB_ITEM_ROW_CHANGE), COL(_OSD_SUB_ITEM0_COL), LENGTH(_OSD_CENTER_LINE_COL1-_OSD_SUB_ITEM0_COL), HEIGHT(1), FG_COLOR(_COLOR_BG_5), BG_COLOR(_COLOR_BG_1));
						else						
							ScalerOsdChange1BitColor(ROW(_OSD_SUB_ITEM0_ROW+j*_OSD_SUB_ITEM_ROW_CHANGE), COL(_OSD_SUB_ITEM0_COL), LENGTH(_OSD_CENTER_LINE_COL1-_OSD_SUB_ITEM0_COL), HEIGHT(1), FG_COLOR(_COLOR_BG_2), BG_COLOR(_COLOR_BG_1));
	
						if(OSD_ITEM_MASK_GET(ucOsdState))
							ScalerOsdChange1BitColor(ROW(_OSD_OPTIONS_ITEM0_ROW+j*_OSD_OPTIONS_ITEM_ROW_CHANGE), COL(_OSD_OPTIONS_ITEM0_COL), LENGTH(_OSD_OPTIONS_ARROW2_FONT_LEN), HEIGHT(1), FG_COLOR(_COLOR_BG_5), BG_COLOR(_COLOR_BG_1));
						else						
							ScalerOsdChange1BitColor(ROW(_OSD_OPTIONS_ITEM0_ROW+j*_OSD_OPTIONS_ITEM_ROW_CHANGE), COL(_OSD_OPTIONS_ITEM0_COL), LENGTH(_OSD_OPTIONS_ARROW2_FONT_LEN), HEIGHT(1), FG_COLOR(_COLOR_BG_2), BG_COLOR(_COLOR_BG_1));
						
					}
					break;
*/
				case _TYPE_ITEM:
					

					if(OSD_ITEM(ucOsdState)>>4 == OSD_MAIN_MENU_ITEM)
					{
					
						//DebugMessageOsd("4.1111",OSD_ITEM_MASK_GET(ucOsdState));
						if(OSD_ITEM_MASK_GET(ucOsdState))
							ScalerOsdChange1BitColor(ROW(_ROW_1ST_TEXT_START+j), COL(_COL_1ST_TEXT_START), LENGTH(_COL_1ST_TEXT_SPACE+2), HEIGHT(1), FG_COLOR(_CP_BLOCK), BG_COLOR(_CP_BG));
						else						
							ScalerOsdChange1BitColor(ROW(_ROW_1ST_TEXT_START+j), COL(_COL_1ST_TEXT_START), LENGTH(_COL_1ST_TEXT_SPACE+2), HEIGHT(1), FG_COLOR(_CP_WHITE), BG_COLOR(_CP_BG));
	
						//if(OSD_ITEM_MASK_GET(ucOsdState))
							//ScalerOsdChange1BitColor(ROW(_OSD_OPTIONS_ITEM0_ROW+j*_OSD_OPTIONS_ITEM_ROW_CHANGE), COL(_OSD_OPTIONS_ITEM0_COL), LENGTH(_OSD_OPTIONS_ARROW2_FONT_LEN), HEIGHT(1), FG_COLOR(_COLOR_BG_5), BG_COLOR(_COLOR_BG_1));
						//else						
							//ScalerOsdChange1BitColor(ROW(_OSD_OPTIONS_ITEM0_ROW+j*_OSD_OPTIONS_ITEM_ROW_CHANGE), COL(_OSD_OPTIONS_ITEM0_COL), LENGTH(_OSD_OPTIONS_ARROW2_FONT_LEN), HEIGHT(1), FG_COLOR(_COLOR_BG_2), BG_COLOR(_COLOR_BG_1));
	
					}
					break;
					/*
				case _TYPE_NONE:
				case _TYPE_SUBMENU:
					if(OSD_ITEM(ucOsdState)>>4 == OSD_MAIN_MENU_ITEM)
					{
					
						if(OSD_ITEM_MASK_GET(ucOsdState))
							ScalerOsdChange1BitColor(ROW(_OSD_SUB_ITEM0_ROW+j*_OSD_SUB_ITEM_ROW_CHANGE), COL(_OSD_SUB_ITEM0_COL), LENGTH(_OSD_CENTER_LINE_COL1-_OSD_SUB_ITEM0_COL), HEIGHT(1), FG_COLOR(_COLOR_BG_5), BG_COLOR(_COLOR_BG_1));
						else						
							ScalerOsdChange1BitColor(ROW(_OSD_SUB_ITEM0_ROW+j*_OSD_SUB_ITEM_ROW_CHANGE), COL(_OSD_SUB_ITEM0_COL), LENGTH(_OSD_CENTER_LINE_COL1-_OSD_SUB_ITEM0_COL), HEIGHT(1), FG_COLOR(_COLOR_BG_2), BG_COLOR(_COLOR_BG_1));
					}
					break;
						*/		
				default :
					break;
			}
		}
		}
}


//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     :
//--------------------------------------------------
void OsdDisplayReDrawMainWindow(bit Type)
{
        BYTE i, ucColor;
		Type=Type;
		// һ���˵�
		OsdWindowDrawingHighlight(WINNO(_OSD_WINDOW_4_5),XSTART(_COL_MAIN_TEXT_START(0)*12), YSTART(_ROW_MAIN_TEXT_START0*18), XEND(_COL_MAIN_TEXT_START(6)*12), YEND((_ROW_MAIN_TEXT_START0+2)*18), _CP_DARKGRAY, _CP_DARKGRAY, _CP_DARKGRAY);
		// һ���˵� ѡ�д��ڳ���
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_MAIN_CURSOR_CYAN_X_START(OSD_MAIN_MENU_ITEM)), YSTART(_ROW_MAIN_TEXT_START0*18), XEND(_MAIN_WIN_MAIN_CURSOR_CYAN_X_END(OSD_MAIN_MENU_ITEM)), YEND((_ROW_MAIN_TEXT_START0+2)*18), _CP_BLUE, _CP_BLUE, _CP_BLUE);
		// �����˵�
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR),XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(0)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);

		if(GET_OSD_LANGUAGE() < 11 )
		{
			OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))), _CP_GRAY, _CP_YELLOW, _CP_BG);
		}
		else
		{
			OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()) - _MAIN_LANGUAE_GAP)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()) - _MAIN_LANGUAE_GAP)), _CP_GRAY, _CP_YELLOW, _CP_BG);
		}

		
		OsdDisplayDrawMainString(); 
		
        for(i=0;i<_OSD_ITEM_LENGTH;i++)
        {
            if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_UP)
            {        	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	            if(_COL_1ST_TEXT_SPACE%2 == 0)
	        	{
					OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2-1)), tiOSD_1BIT_ARROW_UP_2ICON, COLOR(_CP_WHITE, _CP_GRAY));
	        	}
				else
#endif
                	OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));
            }
            else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_DOWN)
            {        	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	            if(_COL_1ST_TEXT_SPACE%2 == 0)
	        	{
	        		OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2-1)), tiOSD_1BIT_ARROW_DOWN_2ICON, COLOR(_CP_WHITE, _CP_GRAY));
	        	}
				else
#endif
                	OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));
            }
            else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] != _MENU_NULL)
            {
				ucColor = OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ? _CP_BLOCK : _CP_WHITE;    
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
            	OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i * 2 + 1), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
#else
                OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
				
				if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) != _TYPE_NONE)
				{
					OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + i), COL(_COL_1ST_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(ucColor, _CP_BG));

				}
#endif                
            }
        }		

		

		ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
		//ScalerOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(OSD_SubMenuCur)), _CP_BLUE, _CP_WHITE, _CP_BG);


}

void OsdDisplayInformationPage(void)
{

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE )	
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+1), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+2), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_HFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+3), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_VFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+4), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_PIXEL_CLOCK, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+1), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_HFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+2), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_VFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+3), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_PIXEL_CLOCK, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

#else	
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+0), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+1), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_HFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+2), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_VFREQ, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+3), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_PIXEL_CLOCK, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+4), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_3, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_MODEL_NUMBER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+5), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_2, _STRING_INFORMATION_ITEM_SN, 0, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdPropPutStringPage0(ROW(_ROW_2ND_TEXT_START+6), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_SN, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_SN, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	//OsdPropPutString(ROW(_ROW_2ND_TEXT_START+6), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_3, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_SN, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	OsdPropPutString(ROW(_ROW_2ND_TEXT_START+7), COL(_COL_2ND_TEXT_START), _PFONT_PAGE_3, _STRING_INFORMATION_ITEMS, _OSD_INFORMATION_ITEM_URL, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
#endif

}




//--------------------------------------------------
// Description      : Draw 2nd Menu 
// Input Value      : ucMode : _TRUE:��ʼ��ģʽ��_FALSE�ûҸ���ģʽ
// Output Value     : None

//--------------------------------------------------
void OsdDisplay2ndMenu(void)
{
    BYTE i = 0;
    BYTE ucColor;
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
	BYTE ucColor1;
#endif	
	PageInit();

    OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));

	// ʹ�ò˵��ַ�ͬʱ����
	OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(0)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(_OSD_ITEM_LENGTH - 1)), _CP_GRAY, _CP_GRAY, _CP_GRAY);
    
	DebugMessageOsd("1.2ndMenu",OSD_SubMenuCur);

	
    for(i=0;i<_OSD_ITEM_LENGTH;i++)
    {
        if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_UP)
        {        	
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
        	if(_COL_1ST_TEXT_SPACE%2 == 0)
        	{
        		OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2-1)), tiOSD_1BIT_ARROW_UP_2ICON, COLOR(_CP_WHITE, _CP_GRAY));
        	}
			else
#endif
			{
				OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));
			}
        }
        else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_DOWN)
        {
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
            if(_COL_1ST_TEXT_SPACE%2 == 0)
        	{
				OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2 - 1)), tiOSD_1BIT_ARROW_DOWN_2ICON, COLOR(_CP_WHITE, _CP_GRAY));
        	}
			else
#endif
			{
				OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));
			}
        }
        else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] != _MENU_NULL)
        {  
            ucColor = OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ? _CP_BLOCK : _CP_WHITE;
#if (_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
			if(OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_VIEWMODE)
			{
				if(GET_OSD_VIEWMODE_TYPE() == _VM_MONO && GET_OSD_STATE()==_MENU_VIEWMODE)
				{
					g_usOsdMenu2Page = 1;
					memcpy(OsdStateDefine[OSD_MAIN_MENU_ITEM],OsdStateDefineDefault1[OSD_MAIN_MENU_ITEM],sizeof(OsdStateDefineDefault1[OSD_MAIN_MENU_ITEM]));
					OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + 0 * 2 + 1), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][0]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
				}
				else
					OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i * 2 + 1), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
			}
			else
				OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i * 2 + 1), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
#else

			OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());

			if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) != _TYPE_NONE)
			{
				OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + i), COL(_COL_1ST_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(ucColor, _CP_BG));
			}

#endif

        }
    }

	if(OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_INPUT)
	{
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(GetOsdValue(_MENU_INPUT))), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(GetOsdValue(_MENU_INPUT))), _CP_GRAY, _CP_YELLOW, _CP_BG);
	}
	else if(OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_VIEWMODE)
	{
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
		if((GET_OSD_VIEWMODE_TYPE() == _VM_MONO && OSD_SubMenuCur==7)  \
			|| (GET_OSD_VIEWMODE_TYPE() == _VM_MONO && OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_VIEWMODE_STANDARD && OSD_SubMenuCur==0))
			ucColor1 = _CP_WHITE;
		else
			ucColor1 = _CP_YELLOW;

			OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(GetOsdValue(_MENU_VIEWMODE)-((GET_OSD_VIEWMODE_TYPE() == _VM_MONO) ? (_OSD_ITEM_LENGTH) : 0))), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(GetOsdValue(_MENU_VIEWMODE)-((GET_OSD_VIEWMODE_TYPE() == _VM_MONO) ? (_OSD_ITEM_LENGTH) : 0))), _CP_GRAY, ucColor1, _CP_BG);
#else
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(GetOsdValue(_MENU_VIEWMODE))), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(GetOsdValue(_MENU_VIEWMODE))), _CP_GRAY, _CP_YELLOW, _CP_BG);
#endif
	}
	else
	{
		ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
	}


}

//--------------------------------------------------
// Description      : Draw 3rd Menu 
// Input Value      : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplay3rdMenu(void)
{
    BYTE i = 0;
    BYTE ucOsdState = OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur];

	DebugMessageOsd("4.3rdMenu_ShowType",GetOsdShowType(ucOsdState));

    switch(GetOsdShowType(ucOsdState))
    {
        case _TYPE_SLIDER:
            OsdDisplaySliderAndNumber(ucOsdState, GetOsdValue(ucOsdState), _SLIDER_PAGE3);
            break;
			
        case _TYPE_SUBMENU:
            OsdDisplaySubMenuItem();
            break;
			
        case _TYPE_ITEM:
			
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
			g_usOsdMenu3Page = GetOsdValue(ucOsdState)/_OSD_3RD_ITEM_LENGTH;
#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#else

			if(GET_OSD_LANGUAGE() > 10)
			{
				pageflag = 1;
			}
			else
			{
				pageflag = 0;
			}

#endif


			OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_ITEM_LENGTH - 1)), _CP_GRAY, _CP_GRAY, _CP_GRAY);

			OsdDisplaySubMenuItem();		
			
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)			
			if(ucOsdState == _MENU_FUN_LANGUAGE)
            {
				ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
            }
            else
#else

			if((pageflag == 1) && ucOsdState == _MENU_FUN_LANGUAGE)
			{
				if(GET_OSD_LANGUAGE() < _OSD_3RD_ITEM_LENGTH )
				{
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(ucOsdState))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(ucOsdState))), _CP_GRAY, _CP_YELLOW, _CP_BG);
				}
				else
				{
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(ucOsdState) - _MAIN_LANGUAE_GAP)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(ucOsdState) - _MAIN_LANGUAE_GAP)), _CP_GRAY, _CP_YELLOW, _CP_BG);
				}
			}
            else

#endif

			#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
			{ 
				if(ucOsdState == _MENU_FUN_VIEWMODE_STANDARD )
                	OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(ucOsdState))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(ucOsdState))), _CP_GRAY, _CP_WHITE, _CP_BG);
				else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(ucOsdState))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(ucOsdState))), _CP_GRAY, _CP_YELLOW, _CP_BG);
            }
			#else
			{
                OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(ucOsdState))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(ucOsdState))), _CP_GRAY, _CP_YELLOW, _CP_BG);
            }
			#endif

            


            break;

			case _TYPE_NONE:

			if(ucOsdState == _MENU_FUN_INFORMATION)
			{
				OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_ITEM_LENGTH - 1)), _CP_GRAY, _CP_GRAY, _CP_GRAY);
				OsdDisplayInformationPage();
				ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);

				#if _GSYNC_TEST
					OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START+2), COL(_COL_3RD_TEXT_START), tiOSD_1BIT_GSYNC_ICON, COLOR(_CP_WHITE,_CP_BG));
					OsdFontPut2BitTable(ROW(_ROW_3RD_TEXT_START+1), COL(_COL_3RD_TEXT_START), tiOSD_2BIT_GSYNC_ICON, _CP_BG, _CP_WHITE, _CP_EN_BLUE, _CP_GRAY);
					OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START+1), COL(_COL_3RD_TEXT_START+8), tiOSD_1BIT_GSYNC_R_ICON, COLOR(_CP_WHITE,_CP_BG));
				#endif
			}

            break;

			
			default:
            break;
    }
}

//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     :
//--------------------------------------------------
void OsdDisplayMainCursor(BYTE ucType)
{

	if(ucType == _ON)
	{
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY),XSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_X_START(OSD_MAIN_MENU_ITEM)), YSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_START), XEND(_MAIN_WIN_MAIN_CURSOR_GRAY_X_END(OSD_MAIN_MENU_ITEM)), YEND(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_END), _CP_BLUE, _CP_YELLOW, _CP_BG);
#else
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY),XSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_X_START(OSD_MAIN_MENU_ITEM)), YSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_START), XEND(_MAIN_WIN_MAIN_CURSOR_GRAY_X_END(OSD_MAIN_MENU_ITEM)), YEND(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_END),COLOR0(_CP_GRAY));
#endif
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_CURSOR_CYAN),XSTART(_MAIN_WIN_MAIN_CURSOR_CYAN_X_START(OSD_MAIN_MENU_ITEM)), YSTART(_MAIN_WIN_MAIN_CURSOR_CYAN_Y_START), XEND(_MAIN_WIN_MAIN_CURSOR_CYAN_X_END(OSD_MAIN_MENU_ITEM)), YEND(_MAIN_WIN_MAIN_CURSOR_CYAN_Y_END),COLOR0(_CP_BLUE));

#if(_5KEY_MENU_STYLE)      
	  if(GET_OSD_VOLUME_MUTE()==_ON&&(SysSourceGetSourceType()!=_SOURCE_VGA))    //2025.02.11 tx
	   OsdFontPut2BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(1*8)), tiOSD_2BIT_MAIN_ICON[6], _CP_BG, _CP_WHITE, (OSD_MAIN_MENU_ITEM==1? _CP_BLUE : _CP_DARKGRAY), _CP_RED);
	  else
	   OsdFontPut1BitTable(ROW(_MAIN_ICON_ROW_), COL(_MAIN_ICON_COL_+(1*8)), tiOSD_2BIT_MAIN_ICON[1], COLOR((SysSourceGetSourceType()==_SOURCE_VGA ? _CP_GRAY: _CP_WHITE), _CP_BG));
#endif	  
	}
	else if(ucType == _OFF)
	{
		OsdFuncCloseWindow(WINNO(_MAIN_WIN_MAIN_CURSOR_CYAN));
		OsdFuncCloseWindow(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY));
	}
	else if(ucType == _RECALL_ON)
	{
		ScalerOsdWindowOnOFF(WINNO(_MAIN_WIN_MAIN_CURSOR_CYAN), _ON);
		ScalerOsdWindowOnOFF(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY), _ON);
	}
	else if(ucType == _RECALL_OFF)
	{
		ScalerOsdWindowOnOFF(WINNO(_MAIN_WIN_MAIN_CURSOR_CYAN), _OFF);
		ScalerOsdWindowOnOFF(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY), _OFF);
	}


}

void UpdateOSDSubMenu(BYTE subpage)
{

	if(subpage==0)
		memcpy(OsdStateDefine[OSD_MAIN_MENU_ITEM],OsdStateDefineDefault[OSD_MAIN_MENU_ITEM],sizeof(OsdStateDefineDefault[OSD_MAIN_MENU_ITEM]));
	else if(subpage==1)
		memcpy(OsdStateDefine[OSD_MAIN_MENU_ITEM],OsdStateDefineDefault1[OSD_MAIN_MENU_ITEM],sizeof(OsdStateDefineDefault1[OSD_MAIN_MENU_ITEM]));
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
	else if(subpage==2)
		memcpy(OsdStateDefine[OSD_MAIN_MENU_ITEM],OsdStateDefineDefault2[OSD_MAIN_MENU_ITEM],sizeof(OsdStateDefineDefault2[OSD_MAIN_MENU_ITEM]));
#endif
	UpdateMaskItem();
	UpdateMaskValue();

}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OSDSubMenuMove(void)
{

    BYTE i = OSD_SubMenuCur + g_usOsdMenu2Page * _OSD_ITEM_LENGTH;
    BYTE count = _OSD_ITEM_LENGTH * _OSD_ITEM_PAGE;
    // BYTE osdstate;
    BYTE preosdstate = GET_OSD_STATE();
    BYTE subpage = g_usOsdMenu2Page;

	DebugMessageOsd("My_Move",GET_OSD_STATE());
	DebugMessageOsd("g_usOsdMenu2Page",g_usOsdMenu2Page);

	#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
			#if _OSD_VIEWMODE_USER_GAME_MODE
				#error "Please Check!!!!"
			#else
				if((GET_OSD_STATE() >= _OSD_SUB_START + (_MENU_VIEWMODE - _MENU_INPUT)*_OSD_ITEM_LENGTH) && (GET_OSD_STATE() < _OSD_SUB_START + (_MENU_VIEWMODE - _MENU_INPUT+1)*_OSD_ITEM_LENGTH))
				{
					if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
					{
						if(i == GetOsdValue(_MENU_VIEWMODE))
							return;
						else
						{
							OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR), XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(OSD_SubMenuCur)), _CP_GRAY, _CP_YELLOW, _CP_BG);
							SpecialFuncAdj();
							return;
						}
					}
				}
			#endif
	#endif
	
	//DebugMessageOsd("1.00",GET_COLOR_TEMP_TYPE());
	//if(tempItem != GetOsdValue(_MENU_VIEWMODE))

	// ������ȷ�Ϻ��е����ģ�ִ�к��������
	if(_OSD_SUB_START <= GET_OSD_STATE() && GET_OSD_STATE() <= _OSD_SUB_END && OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_RECALL && GET_KEYMESSAGE() == _MENU_KEY_MESSAGE )
	{
    	SpecialFuncAdj();
		return;
	}
	else
	{
    	SpecialFuncAdj();

	}
	
#if(0)//(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)

	if((GET_KEYMESSAGE() == _UP_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE) && GET_OSD_STATE()==29)
	{
		
		if(GET_OSD_VIEWMODE_TYPE() == _VM_MONO && GetOsdValue(_MENU_VIEWMODE)==7)
		{
			subpage = 1;
			g_usOsdMenu2Page=1;
		}
	}

#endif

    while (count--)
    {
        if ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
			||(GET_KEYMESSAGE() == _UP_KEY_MESSAGE))
        {
            if(i == 0) 
            {
                i = (_OSD_ITEM_LENGTH * _OSD_ITEM_PAGE - 1);
            }
            else
            {
                i--;
            }

            if(subpage != i / _OSD_ITEM_LENGTH)
            {
                subpage = i / _OSD_ITEM_LENGTH;
                UpdateOSDSubMenu(subpage);
            }
			
            if(!OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i % _OSD_ITEM_LENGTH]))
            {
				//DebugMessageOsd("2.subpage",subpage);
				//DebugMessageOsd("2.g_usOsdMenu2Page",g_usOsdMenu2Page);
                if(subpage != g_usOsdMenu2Page)
                {
                    ScalerOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);//UserCommonOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);
                    OsdDisplay2ndMenu();
                }
                OSD_SubMenuPer = OSD_SubMenuCur;
                OSD_SubMenuCur = i % _OSD_ITEM_LENGTH;
                SET_OSD_STATE(_OSD_SUB_START + (OSD_MAIN_MENU_ITEM)*_OSD_ITEM_LENGTH + OSD_SubMenuCur);
                break;
            }
			
        }
        else if ((GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)
			||(GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE))
        {
            if (i == (_OSD_ITEM_LENGTH * _OSD_ITEM_PAGE - 1))
            {
                i = 0;
            }
            else
            {
                i++;
            }

            if (subpage != i / _OSD_ITEM_LENGTH)
            {
                subpage = i / _OSD_ITEM_LENGTH;
                UpdateOSDSubMenu(subpage);
            }

            if (!OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i % _OSD_ITEM_LENGTH]))
            {
                if (subpage != g_usOsdMenu2Page)
                {
                    ScalerOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);//UserCommonOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);;
                    OsdDisplay2ndMenu();
                }
                OSD_SubMenuPer = OSD_SubMenuCur;
                OSD_SubMenuCur = i % _OSD_ITEM_LENGTH;
				//DebugMessageOsd("OSD_SubMenuCur2",OSD_SubMenuCur);
                SET_OSD_STATE(_OSD_SUB_START + (OSD_MAIN_MENU_ITEM)*_OSD_ITEM_LENGTH + OSD_SubMenuCur);
                break;
            }
			
        }
        else if (GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
        {
            if (!OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i % _OSD_ITEM_LENGTH]))
            {
                OSD_SubMenuCur = i % _OSD_ITEM_LENGTH;
			
				DebugMessageOsd("OSD_SubMenuCur",OSD_SubMenuCur);


                if ((_OSD_SUB_START <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_SUB_END))
                {
                    if (OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_INPUT)
                    {
                        SetOsdValue(_MENU_INPUT, OSD_SubMenuCur);
                        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(OSD_SubMenuCur)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                    }
                    else if (OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_VIEWMODE)
                    {
                        SetOsdValue(_MENU_VIEWMODE, OSD_SubMenuCur);
                        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR), XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(OSD_SubMenuCur)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                    } 					
					else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_INFORMATION)
					{
						return;
					}
                    else
                    {
                        SET_OSD_STATE(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
						//DebugMessageOsd("4.88",GET_OSD_STATE());
                        if(GET_OSD_STATE() == _MENU_FUN_VOLUME)
                    	{
							OsdDisplayKeyIndex(_LAYER_VOLUME_ADJUST);
						}
						else
							OsdDisplayKeyIndex(_LAYER2);
                        OsdInterfaceAdjust();
                    }
                }
                else if ((_OSD_FUN_START <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_FUN_END))
                {
                
					DebugMessageOsd("4.55",GET_OSD_STATE());	

                    if (GetOsdShowType(GET_OSD_STATE()) == _TYPE_ITEM)
                    {
                        SetOsdValue(GET_OSD_STATE(), g_usAdjustValue);
						
#if(_DEFAULT_OSD_STYLE ==_TRG_OSD_STYLE)                        
						if(GET_OSD_STATE() == _MENU_FUN_LANGUAGE)
                        {
							//ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
                        }
#else                        
						if((pageflag == 1) && GET_OSD_STATE() == _MENU_FUN_LANGUAGE)
                        {
                            if(GET_OSD_LANGUAGE() < _OSD_3RD_ITEM_LENGTH )
                            {
                                OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))), _CP_GRAY, _CP_YELLOW, _CP_BG);
                            }
                            else
                            {
                                OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()) - _MAIN_LANGUAE_GAP)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()) - _MAIN_LANGUAE_GAP)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                            }
                        }
#endif

						else if(GET_OSD_STATE() == _OSD_MSG_NOTHING )
							;
#if(_OSD_VIEWMODE_USER_GAME_MODE)
						else if(GET_OSD_STATE() == _MENU_FUN_VIEWMODE_STANDARD) // 2���˵���� 
						{
						//sdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR), XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(OSD_SubMenuCur)), _CP_GRAY, _CP_YELLOW, _CP_BG);

						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR), XSTART(_MAIN_WIN_2ND_SELECTED_X_START), YSTART(_MAIN_WIN_2ND_SELECTED_Y_START(GET_OSD_VIEWMODE_TYPE())), XEND(_MAIN_WIN_2ND_SELECTED_X_END), YEND(_MAIN_WIN_2ND_SELECTED_Y_END(GET_OSD_VIEWMODE_TYPE())), _CP_GRAY, _CP_YELLOW, _CP_BG);

						}
#endif
                        else
                        {
							DebugMessageOsd("4.66",GET_OSD_STATE());						

                        	if(0);
#if(_DEF_OSD_GAMING == _ON)
                            else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i % _OSD_ITEM_LENGTH] == _MENU_FUN_GAMING)
								;
#endif

#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
							else if(GET_OSD_STATE() == _MENU_FUN_RESPONSE_TIME)
							{
								OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_GRAY, _CP_YELLOW, _CP_BG);
							}
#endif
							else
                            	OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED), XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))), _CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
						
                        if(GET_OSD_STATE() == _MENU_FUN_TEMP && g_usAdjustValue == _CT_USER)
                        {
                            g_us4thItemNum = 0;
                            SET_OSD_STATE(_MENU_FUN_USER_COLOR);
							OsdDisplayKeyIndex(_LAYER2);
							#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                            OsdDisplayDrawSelectedCursor(4, 0);
                        	#else
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
							#endif
						}
						
                        g_usBackupValue = g_usAdjustValue;
#if(_DEFAULT_OSD_STYLE != _TRG_OSD_STYLE)
						// �����û�
						UpdateMaskValue();

						if(GET_OSD_STATE() != _OSD_MSG_NOTHING )
							UpdataOSDChangeColor(); 
#endif
                    }

					if(GET_OSD_STATE()==_MENU_FUN_VOLUME)
					{
                     	SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE() );
				        UserAdjustAudioMuteSwitch();
						RTDNVRamSaveOSDData();
						OsdDisplayKeyIndex(_LAYER_VOLUME_ADJUST);
					}
					
                }
                else
                {
                    if (OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_INPUT)
                    {
                        OSD_SubMenuCur = GetOsdValue(_MENU_INPUT);
                    }
                    else if (OSD_MAIN_MENU_ITEM + _OSD_MAIN_START == _MENU_VIEWMODE)
                    {
                        OSD_SubMenuCur = GetOsdValue(_MENU_VIEWMODE);

						OSD_SubMenuCur = OSD_SubMenuCur%_OSD_ITEM_LENGTH;
                    }

                    SET_OSD_STATE(_OSD_SUB_START + OSD_MAIN_MENU_ITEM * _OSD_ITEM_LENGTH + OSD_SubMenuCur);
					OsdDisplayKeyIndex(_LAYER2);
                }

                break;
            }

            if (i == (_OSD_ITEM_LENGTH * _OSD_ITEM_PAGE - 1))
            {
                i = 0;
            }
            else
            {
                i++;
            }
			
            if (subpage != i / _OSD_ITEM_LENGTH)
            {
                subpage = i / _OSD_ITEM_LENGTH;
                UpdateOSDSubMenu(subpage);
            }
			
        }
        else if (GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
        {
        
			DebugMessageOsd("4.MOVE_EXIT",GET_OSD_STATE());
            if ((_OSD_SUB_START <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_SUB_END))
            {
                OsdDisplayMainCursor(_ON);
				
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                OsdDisplayClearSelectedCursor(2, OSD_SubMenuCur);
#endif
                ScalerOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);//UserCommonOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);
                OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
                SET_OSD_STATE(_OSD_MAIN_START + OSD_MAIN_MENU_ITEM); // 2th -> 1th
                OSD_SubMenuCur = 0;
				OsdDisplayKeyIndex(_LAYER1);
                i = 0;
#if(_DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)
                if (subpage != i / _OSD_ITEM_LENGTH)
                {
                    subpage = i / _OSD_ITEM_LENGTH;
                    UpdateOSDSubMenu(subpage);
                    OsdDisplay2ndMenu();
                }
#endif
            }
            else
            {
				DebugMessageOsd("4.10",preosdstate);

				
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
				if(GetOsdGameModeState(preosdstate))
				{
					if(GetOsdShowType(preosdstate) == _TYPE_SLIDER)
					{
						OsdDisplaySliderAndNumber(preosdstate, GetOsdValue(preosdstate), _SLIDER_PAGE4);
						OsdDisplayKeyIndex(_LAYER3);
					}

				}
				else
#endif
				{
					g_usAdjustValue = g_usBackupValue;

					OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
					SET_OSD_STATE(_OSD_SUB_START + OSD_MAIN_MENU_ITEM * _OSD_ITEM_LENGTH + OSD_SubMenuCur);
					if(GetOsdShowType(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]) == _TYPE_SLIDER)
						OsdDisplayKeyIndex(_LAYER2);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
#else
					ScalerOsdWindowDisable(_MAIN_WIN_3RD_CURSOR);
#endif

				}




            }
            break;
        }
    }

    if ((g_usOsdMenu2Page != subpage))
    {
        g_usOsdMenu2Page = subpage;
    }


    /////////////////////////   ////////////////////////////////////////////////////
    if ((_OSD_SUB_START <= GET_OSD_STATE()) && (GET_OSD_STATE() <= _OSD_SUB_END))
    {
    
		DebugMessageOsd("4.MOVE_preosdstate",g_usOsdMenu2Page);
		
        if (preosdstate <= _OSD_SUB_END)
        {            
			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_MAIN_CURSOR_GRAY),XSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_X_START(OSD_MAIN_MENU_ITEM)), YSTART(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_START), XEND(_MAIN_WIN_MAIN_CURSOR_GRAY_X_END(OSD_MAIN_MENU_ITEM)), YEND(_MAIN_WIN_MAIN_CURSOR_GRAY_Y_END), _CP_BLUE, _CP_YELLOW, _CP_BG);
	            ScalerOsdWindowDisable(_MAIN_WIN_2ND_CURSOR);
				OsdDisplayClearSelectedCursor(2, OSD_SubMenuPer);
				OsdDisplayDrawSelectedCursor(2, OSD_SubMenuCur);
            #else
	            ScalerOsdWindowDisable(_MAIN_WIN_MAIN_CURSOR_GRAY);//UserCommonOsdWindowDisable(_MAIN_WIN_MAIN_CURSOR_GRAY);
	            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(OSD_SubMenuCur)), _CP_BLUE, _CP_WHITE, _CP_BG);
            #endif
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
			if(GET_KEYMESSAGE() != _EXIT_KEY_MESSAGE)
				OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1)); // 1
#else
			OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1)); // 1
#endif
            g_usAdjustValue = GetOsdValue(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]);
            g_usBackupValue = g_usAdjustValue;
            ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);//UserCommonOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
            
			if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]>=(_MENU_FUN_INFORMATION-1) && OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]<=(_MENU_FUN_INFORMATION+1))
				OsdDisplayKeyIndex(_LAYER2);
        }
        else
        {

        }
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
		if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE && preosdstate==_MENU_FUN_VIEWMODE_STANDARD)
			;
		else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE && preosdstate==_MENU_FUN_VIEWMODE_FPS)
			;
		else
#endif
			OsdDisplay3rdMenu();
			#if _GSYNC_TEST
				if(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuPer] == _MENU_FUN_INFORMATION)
				{
					OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), HEIGHT(4));
				}
			#endif
    }
    // SpecialFuncAdj();
    // OsdDisplayKeyIndex();
    
	DebugMessageOsd("4.11",OSD_SubMenuCur);
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UpdateMaskItem(void)
{
	BYTE i,j;
	
	memset(OSD_ITEM_BASE, 0xff, sizeof(OSD_ITEM_BASE));
	
	for(i=0; i<_OSD_MAIN_LENGTH; i++)
	{
		for(j=0; j<_OSD_ITEM_LENGTH; j++)
		{
			if(OsdStateDefine[i][j] != _MENU_NULL)
			{
				OSD_ITEM(OsdStateDefine[i][j]) = ((i<<4) | j);								
			}
			else
			{
				OSD_ITEM_MASK_SET(_MENU_NULL);
			}
		}
	}
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UpdateMaskValue(void)
{
		BYTE i = 0;

		//��ʼ��
		memset(&OSD_ITEM_MASK,0,sizeof(OSD_ITEM_MASK));
		OSD_ITEM_MASK_SET(_MENU_NULL); 
		
		OSD_ITEM_MASK_SET(_MENU_ARROW_UP);
    	OSD_ITEM_MASK_SET(_MENU_ARROW_DOWN);

		OSD_ITEM_MASK_CLR(_MENU_FUN_SHARPNESS);
		OSD_ITEM_MASK_CLR(_MENU_FUN_BLUELIGHT);
		OSD_ITEM_MASK_CLR(_MENU_FUN_ASPECT);
		OSD_ITEM_MASK_CLR(_MENU_FUN_OVERSCAN);
        OSD_ITEM_MASK_CLR(_MENU_FUN_BLK_STABLE);
        OSD_ITEM_MASK_CLR(_MENU_FUN_ADV_DCR);
        OSD_ITEM_MASK_CLR(_MENU_FUN_RESPONSE_TIME);
		
        OSD_ITEM_MASK_CLR(_MENU_FUN_HDR);
        OSD_ITEM_MASK_CLR(_MENU_FUN_FREESYNC);
#if(_MPRT_SUPPORT == _ON)
        OSD_ITEM_MASK_CLR(_MENU_FUN_MPRT);
#endif
        OSD_ITEM_MASK_CLR(_MENU_FUN_SLEEP);
        OSD_ITEM_MASK_CLR(_MENU_FUN_ECO);
		
        OSD_ITEM_MASK_CLR(_MENU_FUN_CONTRAST);
        OSD_ITEM_MASK_CLR(_MENU_FUN_BRIGHTNESS);
		OSD_ITEM_MASK_CLR(_MENU_FUN_SIX_AXIS);
		OSD_ITEM_MASK_CLR(_OSD_HOTKEY_VIEWMODE);
		OSD_ITEM_MASK_CLR(_MENU_FUN_TEMP);
		OSD_ITEM_MASK_CLR(_MENU_FUN_GAMUT);
		OSD_ITEM_MASK_CLR(_MENU_FUN_DP_VERSION);

#if(_HDR10_SUPPORT == _ON)
	
	if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
	{
		OSD_ITEM_MASK_SET(_OSD_HOTKEY_VIEWMODE);


		#if(_OSD_FOR_HDR400 == _ON)
		OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS); 
		OSD_ITEM_MASK_SET(_MENU_FUN_BACKLIGHT); 
		OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);	
		OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONBRI);
		OSD_ITEM_MASK_SET(_MENU_FUN_ECO);
#if(_MPRT_SUPPORT == _ON)
		OSD_ITEM_MASK_SET(_MENU_FUN_MPRT);	
#endif
		#endif
		OSD_ITEM_MASK_SET(_MENU_FUN_BRIGHTNESS); 

		OSD_ITEM_MASK_SET(_MENU_FUN_SATURATION);		
		OSD_ITEM_MASK_SET(_MENU_FUN_HUE);
		OSD_ITEM_MASK_SET(_MENU_FUN_SIX_AXIS);
		//OSD_ITEM_MASK_SET(_MENU_FUN_RANGE);

		OSD_ITEM_MASK_SET(_MENU_FUN_TEMP);
		OSD_ITEM_MASK_SET(_MENU_FUN_GAMUT);
		OSD_ITEM_MASK_SET(_MENU_FUN_SPACE);
		OSD_ITEM_MASK_SET(_MENU_FUN_SHARPNESS);
		OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT); 
		OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);			
		OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
		
		OSD_ITEM_MASK_SET(_MENU_FUN_DP_VERSION);

#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
		OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS); 
		OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST); 
		OSD_ITEM_MASK_SET(_MENU_FUN_BACKLIGHT); 
		OSD_ITEM_MASK_SET(_MENU_FUN_ECO);
#endif
		
		//OSD_ITEM_MASK_SET(_MENU_FUN_GAMMA);		
	}
#endif
#if(_HDR10_SUPPORT == _ON)

		if(SysSourceGetSourceType() != _SOURCE_DP || GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_DP_VERSION);
		}
#endif
		if(GET_OSD_VIEWMODE_TYPE() == _VM_MONO)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_SIX_AXIS);
			OSD_ITEM_MASK_SET(_MENU_FUN_HDR);
		}


	
#if(_MPRT_SUPPORT == _ON)
		if(GET_OSD_FREE_SYNC_STATUS()!= _OFF||(GET_INPUT_TIMING_VFREQ()<= _MPRT_MIN_FRAME_RATE))
		{		
			OSD_ITEM_MASK_SET(_MENU_FUN_MPRT);
		}
#endif
		if(GET_OSD_FREE_SYNC_STATUS()!= _OFF)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_ASPECT);
		}
		
		if(SysSourceGetSourceType() != _SOURCE_VGA)
		{
	        //OSD_ITEM_MASK_CLR(_MENU_FUN_SPACE);
	        //OSD_ITEM_MASK_CLR(_MENU_FUN_RANGE);
	        //OSD_ITEM_MASK_CLR(_MENU_FUN_OVERSCAN);
	        OSD_ITEM_MASK_CLR(_MENU_FUN_SLEEP);
#if(_VGA_SUPPORT == _ON)
	        OSD_ITEM_MASK_SET(_MENU_FUN_AUTO_IMAGE_ADJ);
	        OSD_ITEM_MASK_SET(_MENU_FUN_HORIZONTAL_SIZE);
	        OSD_ITEM_MASK_SET(_MENU_FUN_VGA_POSTION);
	        OSD_ITEM_MASK_SET(_MENU_FUN_FINE_TUNE);
#endif
    	}
		
#if 0//(_COLOR_FORMAT_CONVERT == _ON)
		if(OsdDisplayGetColorSpaceType())
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);
			OSD_ITEM_MASK_SET(_MENU_FUN_TEMP);
			OSD_ITEM_MASK_SET(_MENU_FUN_HDR);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);

		}
#endif
		if(GET_OSD_PCM_STATUS()!=_PCM_OSD_NATIVE )
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);		
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_TEMP);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_HDR);
		}
		




#if(_VGA_SUPPORT == _ON)
		if((SysSourceGetSourceType() != _SOURCE_HDMI)&&(SysSourceGetSourceType() != _SOURCE_DP))
		{
	        OSD_ITEM_MASK_CLR(_MENU_FUN_AUTO_IMAGE_ADJ);
	        OSD_ITEM_MASK_CLR(_MENU_FUN_HORIZONTAL_SIZE);
	        OSD_ITEM_MASK_CLR(_MENU_FUN_VGA_POSTION);
	        OSD_ITEM_MASK_CLR(_MENU_FUN_FINE_TUNE);
	        
	        OSD_ITEM_MASK_SET(_MENU_FUN_SPACE);
	        OSD_ITEM_MASK_SET(_MENU_FUN_RANGE);
	        OSD_ITEM_MASK_SET(_MENU_FUN_OVERSCAN);
	        OSD_ITEM_MASK_SET(_MENU_FUN_SLEEP);
	        OSD_ITEM_MASK_SET(_MENU_FUN_FREESYNC);
		}
#endif




		if(GET_OSD_GAME_MODE() == _GM_FPS1)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_ASPECT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			OSD_ITEM_MASK_SET(_MENU_FUN_RESPONSE_TIME);

		}
		
#if(_DEF_VIEWMODE_RTS == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_RTS)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS);
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONBRI);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			OSD_ITEM_MASK_SET(_MENU_FUN_RESPONSE_TIME);
		}
#endif

#if(_DEF_VIEWMODE_MOBA == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_MOBA)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS);
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONBRI);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			OSD_ITEM_MASK_SET(_MENU_FUN_RESPONSE_TIME);
		}	
#endif
		else if(
			GET_OSD_VIEWMODE_TYPE() == _VM_MOVIE || 
			GET_OSD_VIEWMODE_TYPE() == _VM_WEB || 
			GET_OSD_VIEWMODE_TYPE() == _VM_MONO || 
#if(_DEF_VIEWMODE_MAC)
			GET_OSD_VIEWMODE_TYPE() == _VM_MAC || 
#endif
			GET_OSD_VIEWMODE_TYPE() == _VM_TEXT
			)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			OSD_ITEM_MASK_SET(_MENU_FUN_RESPONSE_TIME);

		}


		if(GET_OSD_MPRT())
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_BACKLIGHT);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			//OSD_ITEM_MASK_SET(_MENU_FUN_RESPONSE_TIME);
			OSD_ITEM_MASK_SET(_MENU_FUN_ECO);
			//OSD_ITEM_MASK_SET(_MENU_FUN_HDR);
			OSD_ITEM_MASK_SET(_MENU_FUN_FREESYNC);
		}

		if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST);
#if(_PROJECT == _RL6463_PROJECT)
			OSD_ITEM_MASK_SET(_MENU_FUN_BLK_STABLE);
			OSD_ITEM_MASK_SET(_MENU_FUN_ADV_DCR);
			OSD_ITEM_MASK_SET(_MENU_FUN_BLUELIGHT);
#endif

#if(_MPRT_SUPPORT == _ON)
			OSD_ITEM_MASK_SET(_MENU_FUN_MPRT);
#endif
		}

		if(GET_OSD_DCR_STATUS()!=_DCR_Level_0)
		{
			//DebugMessageOsd("2.GET_OSD_DCR_STATUS",GET_OSD_DCR_STATUS());
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS);
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONBRI);
		}

		if(GET_OSD_PWKEY_LOCK_STATUS() == _ON)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_AUTO_POWEROFF);
			OSD_ITEM_MASK_SET(_MENU_FUN_SLEEP);
		}

		if(OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT))
		{
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_BACKLIGHT);
		}

		if(OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST))
		{
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONTRAST);
		}

		if(OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST) && OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT))
		{
			OSD_ITEM_MASK_SET(_OSD_HOTKEY_CONBRI);
			OSD_ITEM_MASK_SET(_MENU_FUN_CONTRAST_BRIGHTNESS);
		}

		if(SysSourceGetSourceType() == _SOURCE_VGA || GET_INPUT_TIMING_VFREQ() > _DEF_OSD_OVER_VFREQ)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_OVERSCAN);		
		}
			
#if(_PCB_TYPE == _RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS||_5KEY_MENU_STYLE)    //2025.2.13  tx
		// HDMIͨ��
		if(SysSourceGetCableDetect(_D1_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_INPUT_2);
		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_INPUT_2);
		}

		// VGAͨ��
		if(SysSourceGetCableDetect(_A0_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_INPUT_0);
		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_INPUT_0);
		}		
		
		if(SysSourceGetInputPort()!=_D1_INPUT_PORT || GET_INPUT_TIMING_VFREQ() > _DEF_OSD_OVER_VFREQ)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_OVERSCAN);		
			//OSD_ITEM_MASK_SET(_MENU_VIDEO_LEVEL);		
		}
#elif(_PCB_TYPE == _RL6463__128PIN__HKMRT2513E05__1A1H__LVDS || _PCB_TYPE == _RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)
		if(SysSourceGetInputPort()!=_D1_INPUT_PORT || GET_INPUT_TIMING_VFREQ() > _DEF_OSD_OVER_VFREQ)
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_OVERSCAN);		
		}
#elif(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)

// �ûҺ󲻿�ѡ��
#if(_PROJECT_ID==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115 || _PROJECT_ID==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)
		// DP
		if(SysSourceGetCableDetect(_D1_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_INPUT_2);
		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_INPUT_2);
		}
		// HDMI2
		if(SysSourceGetCableDetect(_D2_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_INPUT_1);
		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_INPUT_1);
		}
		// HDMI1
		if(SysSourceGetCableDetect(_D3_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_INPUT_0);
		}
		else
		{
			OSD_ITEM_MASK_CLR(_MENU_FUN_INPUT_0);
		}	
#endif

		if(GET_INPUT_TIMING_VFREQ() > _DEF_OSD_OVER_VFREQ) //SysSourceGetInputPort()==_D1_INPUT_PORT || 
		{
			OSD_ITEM_MASK_SET(_MENU_FUN_OVERSCAN);		
			//OSD_ITEM_MASK_SET(_MENU_VIDEO_LEVEL);		
		}
#endif


}

void PageInit()
{

    g_usFontPointer0 = _OSD_PAGE_0_START;
    g_usFontPointer1 = _OSD_PAGE_1_START;
    g_usFontPointer2 = _OSD_PAGE_2_START;
    g_usFontPointer3 = _OSD_PAGE_3_START;
    g_usFontPointerSlider = _OSD_PAGE_SLIDER_START;
    g_usFontPointerPower = _OSD_PAGE_POWER_START;
    g_usFontPointerRate = _OSD_PAGE_RATE_START;
    g_usFontPointerView = _OSD_PAGE_VIEW_START;
    g_usFontPointerTitle = _OSD_PAGE_TITLE_START;

}

//--------------------------------------------------
// Description      : 
// Input Value      : None
// Output Value     : None
//--------------------------------------------------
void UpdateOSDMainInterface(BYTE ucState)
{

	BYTE i = 0;
	
	PageInit();
	
	g_usOsdMenu2Page = 0;

	SET_OSD_STATE(ucState);
	OSD_MAIN_MENU_ITEM = ucState - _OSD_MAIN_START;
    UpdateOSDSubMenu(g_usOsdMenu2Page);
    OsdDisplayMainCursor(_ON);
	OsdDisplay2ndMenu();
#if(_OSD_SHOW_VIEWMODE)
	if(OSD_MAIN_MENU_ITEM+_OSD_MAIN_START==_MENU_COLOR || OSD_MAIN_MENU_ITEM+_OSD_MAIN_START==_MENU_IMAGE )
	{
		OsdFontPut1BitTable(ROW(_ROW_VIEW_MODE), COL(_COL_VIEW_MODE), tiOSD_1BIT_MAIN_VIEWMODE, _COLOR_MENU_FONT);
		OsdPropPutStringPage0(ROW(_ROW_VIEW_MODE), COL(_COL_VIEW_MODE+3), _PFONT_PAGE_VIEW, _STRING_HOT_KEY_VIEWMODE, GetOsdValue(_MENU_VIEWMODE), COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	}
	else
#endif
	{
		OsdFuncClearOsd(ROW(_ROW_VIEW_MODE), COL(_COL_VIEW_MODE), WIDTH(_WIDTH_VIEW_MODE_CLEAR), HEIGHT(1));
	}


	//UpdateMaskValue();

}


//--------------------------------------------------
// Description  : Check OSD time out
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdDisplayTimeOut(BYTE ucTime)
{
	switch(ucTime)
	{
		case _OSD_TIMEOUT_5S:
			return 5;
			break;

		case _OSD_TIMEOUT_30S:
			return 30;
			break;

		case _OSD_TIMEOUT_60S:
			return 60;
			break;

		default:
			return 15;
			break;
	}
}



//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
void OsdDisplaySliderAndNumber(BYTE ucOsdState, WORD usValue, BYTE ucType)
{
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	BYTE ucItemRow = _ROW_1ST_TEXT_START + 1;
#else
	BYTE ucItemRow = _ROW_1ST_TEXT_START;
#endif
    BYTE ucMaxRange = _SLIDER_MAX;
    BYTE ucSliderCol = _SLIDER_PAGE3_COL;
    BYTE ucValueCol = _VALUE_PAGE3_COL;
    BYTE bSliderPage = _OSD_NORMAL_TYPE;
    BYTE ucFontPage = _PFONT_PAGE_2;
	BYTE ucTypeTemp = ucType;
	BYTE ucColor = _CP_WHITE;
	WORD ucValuePre = usValue;
    BYTE i = 0;
	
#if(_OSD_VIEWMODE_USER_GAME_MODE)
		if(GetOsdGameModeState(GET_OSD_STATE()))
			ucType=_SLIDER_PAGE4;
#endif
		
	DebugMessageOsd("2.ucSliderAndNumber",ucType);

    switch(ucType)
    {
    
		case _SLIDER_PAGE4_FLASH_ON:
			bSliderPage = _OSD_ADJUST_TYPE;
		case _SLIDER_PAGE4_FLASH_OFF:
        case _SLIDER_PAGE4:
            ucSliderCol = _SLIDER_PAGE4_COL;
            ucValueCol = _VALUE_PAGE4_COL;
            ucFontPage = _PFONT_PAGE_3;
            break;
			
		case _SLIDER_PAGE5_FLASH_ON:
			bSliderPage = _OSD_ADJUST_TYPE;
		case _SLIDER_PAGE5_FLASH_OFF:
        case _SLIDER_PAGE5:
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
			ucItemRow = _ROW_5TH_TEXT_START + 1;
#else
			ucItemRow = _ROW_5TH_TEXT_START;
#endif
            ucSliderCol = _SLIDER_PAGE5_COL;
            ucValueCol = _VALUE_PAGE5_COL;
            ucFontPage = _PFONT_PAGE_SLIDER;
            break;

            // case _SLIDER_PAGE6:
            // 	ucItemRow = _SLIDER_PAGE6_ROW;
            // 	ucSliderCol = _SLIDER_PAGE5_COL;
            // 	ucValueCol = _VALUE_PAGE5_COL;
            // 	break;

        case _SLIDER_POWER:
            ucItemRow = _ROW_POWER_BAR;
            ucSliderCol = _COL_POWER_BAR;
            ucValueCol = _COL_POWER_BAR_VALUE;
            bSliderPage = _OSD_POWER_BAR_TYPE;
            ucFontPage = _PFONT_PAGE_POWER;
            break;

        case _SLIDER_HOTKEY:

            if ((ucOsdState == _OSD_HOTKEY_CONTRAST)) //| (ucOsdState == _BRIGHTNESS_ADJUST))
            {
                ucItemRow = _ROW_HOTKEY_BAR - 1;
                ucSliderCol = _COL_HOTKEY_BAR + 1 + 3;
                ucValueCol = _COL_HOTKEY_BAR_VALUE + 4;
                bSliderPage = _OSD_NORMAL_TYPE;
                ucFontPage = _PFONT_PAGE_1;
            }
            else if ((ucOsdState == _OSD_HOTKEY_BACKLIGHT))
            {
                ucItemRow = _ROW_HOTKEY_BAR - 1 + 2;
                ucSliderCol = _COL_HOTKEY_BAR + 1 + 3;
                ucValueCol = _COL_HOTKEY_BAR_VALUE + 4;
                bSliderPage = _OSD_NORMAL_TYPE;
                ucFontPage = _PFONT_PAGE_2;
            }
#if(_MENU_AUDIO_SUPPORT)
            else if ((ucOsdState == _OSD_HOTKEY_VOLUME)) //|| (ucOsdState == _OSD_HOTKEY_CONBRI))
            {
                ucItemRow = _ROW_HOTKEY_BAR; //+ 1;
                ucSliderCol = _COL_HOTKEY_BAR + 1 + 3;
                ucValueCol = _COL_HOTKEY_BAR_VALUE + 4;
                bSliderPage = _OSD_ADJUST_TYPE;
                ucFontPage = _PFONT_PAGE_3;
            }
#endif
            else
            {
                ucItemRow = _ROW_HOTKEY_BAR + 1;
                ucSliderCol = _COL_HOTKEY_BAR;
                ucValueCol = _COL_HOTKEY_BAR_VALUE;
            }
            break;
			
		case _SLIDER_PAGE3_FLASH_ON:
			bSliderPage = _OSD_ADJUST_TYPE;
        case _SLIDER_PAGE3:
        default:
            break;
    }
	
	//DebugMessageOsd("1.ScalerOsdGetOsdEnable",ScalerOsdGetOsdEnable());

    switch (ucOsdState)
    {
    
#if(_MENU_AUDIO_SUPPORT)
        case _MENU_FUN_VOLUME:
        //case _OSD_HOTKEY_VOLUME:
            if(!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
#endif
        case _MENU_FUN_SHARPNESS:
            if(!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SHARPNESS_MAX, _SHARPNESS_MIN, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            usValue *= 25;
            break;
        case _MENU_FUN_BLUELIGHT:
            if(!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _LOW_BLUE_MAX, _LOW_BLUE_MIN, _OFF);    
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
        case _MENU_FUN_OSD_TIMEOUT:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, (_OSD_TIMEOUT_AMOUNT-1), _OSD_TIMEOUT_5S, _OFF);
				SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
			usValue = OsdDisplayTimeOut(usValue);
            ucMaxRange = 60;
            break;
        case _MENU_FUN_CONTRAST:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& GET_OSD_STATE() == ucOsdState)
            {
				usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;

        case _OSD_HOTKEY_VOLUME:
            if(!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF)&& ScalerOsdGetOsdEnable())
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
        case _OSD_HOTKEY_CONTRAST:
			
            if(!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && ScalerOsdGetOsdEnable())
            {
				// �����߼�������ֵ��Ӧ�÷�����ģ�֮ǰ��������������ScalerOsdGetOsdEnable����
				usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
	
            }
			if(GET_OSD_STATE()==_OSD_HOTKEY_FUNC)
			{

				bSliderPage =  (ScalerOsdGetOsdEnable()==_ON && GET_KEYMESSAGE()!=_MENU_KEY_MESSAGE) ? _OSD_ADJUST_TYPE : OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST) ? _OSD_DISABLE_TYPE :	_OSD_NORMAL_TYPE;
				//bSliderPage = OSD_SubMenuCur==0 ? _OSD_ADJUST_TYPE : OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST) ? _OSD_DISABLE_TYPE :	_OSD_NORMAL_TYPE;
				if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST))
					ucColor=_CP_BLOCK;
			
			}
			else
				bSliderPage =_OSD_ADJUST_TYPE;		

            break;
        case _MENU_FUN_BRIGHTNESS:
            usValue = UserCommonAdjustRealValueToPercent(usValue, _BRIGHTNESS_MAX, _BRIGHTNESS_MIN, _BRIGHTNESS_CENTER);
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
                SetOsdValue(ucOsdState, UserCommonAdjustPercentToRealValue(usValue, _BRIGHTNESS_MAX, _BRIGHTNESS_MIN, _BRIGHTNESS_CENTER));
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
			
        case _OSD_HOTKEY_BACKLIGHT:
			
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && ScalerOsdGetOsdEnable())
            {
				usValue = OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);

            }	            
			if(GET_OSD_STATE()==_OSD_HOTKEY_FUNC)
			{
				
				bSliderPage =  (ScalerOsdGetOsdEnable()==_ON && GET_KEYMESSAGE()!=_MENU_KEY_MESSAGE) ? _OSD_ADJUST_TYPE : OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT) ? _OSD_DISABLE_TYPE :	_OSD_NORMAL_TYPE;
			    //bSliderPage = OSD_SubMenuCur==1 ? _OSD_ADJUST_TYPE : OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT) ? _OSD_DISABLE_TYPE :	_OSD_NORMAL_TYPE;
				if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT))
					ucColor=_CP_BLOCK;
			
			}
			else
				bSliderPage =_OSD_ADJUST_TYPE;		
            break;
	
		case _MENU_FUN_BACKLIGHT:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
				usValue = OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
			
        case _MENU_FUN_HUE_ADJUST:
            usValue = UserCommonAdjustRealValueToPercent(usValue, _SIX_COLOR_HUE_MAX, _SIX_COLOR_HUE_MIN, _SIX_COLOR_HUE_CENTER);
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
		        if (GET_OSD_STATE() == ucOsdState)
		        {
					usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
					SetOsdValue(ucOsdState, UserCommonAdjustPercentToRealValue(usValue, _SIX_COLOR_HUE_MAX, _SIX_COLOR_HUE_MIN, _SIX_COLOR_HUE_CENTER));
				}
				bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
        case _MENU_FUN_SATURATION_ADJUST:
            usValue = UserCommonAdjustRealValueToPercent(usValue, _SIX_COLOR_SATURATION_MAX, _SIX_COLOR_SATURATION_MIN, _SIX_COLOR_SATURATION_CENTER);
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
		        if (GET_OSD_STATE() == ucOsdState)
		        {
		            usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
		            SetOsdValue(ucOsdState, UserCommonAdjustPercentToRealValue(usValue, _SIX_COLOR_SATURATION_MAX, _SIX_COLOR_SATURATION_MIN, _SIX_COLOR_SATURATION_CENTER));
		        }
		        bSliderPage = _OSD_ADJUST_TYPE;
			}
            break;
        case _MENU_FUN_USER_COLOR_ADJUST:
            usValue = UserCommonAdjustRealValueToPercent(usValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _SLIDER_MAX, _SLIDER_MIN, _OFF);
                SetOsdValue(ucOsdState, UserCommonAdjustPercentToRealValue(usValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
            }
            bSliderPage = _OSD_ADJUST_TYPE;
            break;
		case _MENU_FUN_ADV_DCR:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _DCR_MAX, _DCR_MIN, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            usValue *= 25;
			break;
        case _MENU_FUN_BLK_STABLE:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, _BLK_STABLE_MAX, _BLK_STABLE_MIN, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            usValue *= 10;
            break;
#if(_VGA_SUPPORT == _ON)
		case _MENU_FUN_HORIZONTAL_SIZE:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;

		case _MENU_FUN_FINE_TUNE:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;
			
		case _MENU_FUN_VGA_HPOSITON:
			if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
			{
				usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
				SetOsdValue(ucOsdState, usValue);
				bSliderPage = _OSD_ADJUST_TYPE;
			}
			break;

		case _MENU_FUN_VGA_VPOSITON:
            if (!(ucTypeTemp>=_SLIDER_PAGE3_FLASH_ON && ucTypeTemp<=_SLIDER_PAGE5_FLASH_OFF) && GET_OSD_STATE() == ucOsdState)
            {
                usValue = (BYTE)OsdDisplayDetOverRange(usValue, 100, 0, _OFF);
                SetOsdValue(ucOsdState, usValue);
                bSliderPage = _OSD_ADJUST_TYPE;
            }
            break;	
#endif
			
        default:
            break;
    }
	
	//DebugMessageOsd("1.usValue",usValue);
	//DebugMessageOsd("1.bSliderPage",bSliderPage);
	//DebugMessageOsd("1.ucValuePre",ucValuePre);
    OsdDisplaySubSlider(ROW(ucItemRow), COL(ucSliderCol), usValue, ucMaxRange, _SLIDER_MIN, _SLIDER_BAR_LENGTH, bSliderPage);
	if((GET_OSD_STATE()==_OSD_HOTKEY_FUNC && GET_KEYMESSAGE()==_MENU_KEY_MESSAGE)  \
		|| (ucValuePre==usValue && (bSliderPage==_OSD_ADJUST_TYPE) && ScalerOsdGetOsdEnable() && ucOsdState!=_MENU_FUN_HUE_ADJUST && ucOsdState!=_MENU_FUN_SATURATION_ADJUST))
		;
	else
    	OsdPropShowNumber(ROW(ucItemRow), COL(ucValueCol), usValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), ucFontPage, COLOR(ucColor, _CP_BG));
}


//--------------------------------------------------
// Description	    : for adjust mode use
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplaySubSlider(BYTE ucRow, BYTE ucCol, WORD usValue, WORD usMax, WORD usMin, BYTE ucSliderLen,BYTE bSliderPage)
{
	BYTE i = 0;
	BYTE ucOsdWidth = 0;
	BYTE ucCount = 0;
	BYTE ucHTemp = ucCol;
	BYTE *pArray = 0;
	BYTE ucColor0 = _CP_WHITE;
	BYTE ucColor1 = _CP_WHITE;
	BYTE ucColor2 = _CP_WHITE;
	BYTE ucColor3 = _CP_WHITE;
	BYTE ucpData[_SLIDER_BAR_LENGTH] ={0};

	usValue = MINOF(usValue,usMax);
	usValue = MAXOF(usValue,usMin);
	usValue = usValue - usMin;
	
	//DebugMessageOsd("1.bSliderPage",bSliderPage);

	switch(bSliderPage)
	{
		case _OSD_ADJUST_TYPE:
			ucColor0 = _CP_BG;
        	ucColor1 = _CP_WHITE;
        	ucColor2 = _CP_WHITE;
        	ucColor3 = _CP_BLUE;
			break;
		case _OSD_DISABLE_TYPE:
			ucColor0 = _CP_BG;
        	ucColor1 = _CP_GRAY;
        	ucColor2 = _CP_GRAY;
        	ucColor3 = _CP_GRAY;
			break;
		case _OSD_PAGE4_TYPE:
			ucColor0 = _CP_BLACK;
        	ucColor1 = _CP_WHITE;
        	ucColor2 = _CP_BLUE;
        	ucColor3 = _CP_BLACK;
			break;
		case _OSD_POWER_BAR_TYPE:
			ucColor0 = _CP_BG;
        	ucColor1 = _CP_WHITE;
        	ucColor2 = _CP_BLUE;//_CP_WHITE;
        	ucColor3 = _CP_BLUE;
			break;
		case _OSD_NORMAL_TYPE:
		default:
			ucColor0 = _CP_BG;
       	 	ucColor1 = _CP_WHITE;
        	ucColor2 = _CP_WHITE;
        	ucColor3 = _CP_WHITE;
			break;
	}

	ucpData[ucCount] = _SLIDER_L_0;
	for(ucCount = 1; ucCount < (_SLIDER_BAR_LENGTH - 1); ucCount++)
	{
		ucpData[ucCount] = _SLIDER_M_0;
 	}
	ucpData[_SLIDER_BAR_LENGTH - 1] = _SLIDER_R_0;
	ucpData[_SLIDER_BAR_LENGTH] = _END_;

	// ------------------------------------------------------------------------
	// Draw BAR
	// ------------------------------------------------------------------------
	usValue = ((WORD)(usValue - usMin) * 100) / (usMax - usMin);
	if(usValue <= 8)
	{
        ucpData[0] = _SLIDER_L_1 + usValue;

        if(usValue >= 3)
        {
            usValue = usValue - 2;
            for(i = 1; i < _SLIDER_BAR_LENGTH; i++)
            {
                if(usValue >= 12)
                {
                    usValue = usValue - 12;
                    if(usValue >= 7)
                    {
                        ucpData[i] = _SLIDER_M_19;
                    }
                    else
                    {
                        ucpData[i] = _SLIDER_M_12 + usValue;
                    }
                }
                else
                {
                    ucpData[i] = _SLIDER_M_0 + usValue;
                    break;
                }
            }
        }
    }
    else if((usValue >= 9) && (usValue <= 97))
    {
        if(bSliderPage != _OSD_ADJUST_TYPE)
        {        	
            ucpData[0] = _SLIDER_L_9;
        }
        else
        {   
			ucpData[0] = _SLIDER_L_0_NEW;
        }

        usValue = usValue - 2;
        for(i = 1; i < _SLIDER_BAR_LENGTH; i++)
        {
            if(usValue >= 12)
            {
                usValue = usValue - 12;
                if(usValue >= 7)
                {
                    ucpData[i] = _SLIDER_M_19;
                }
                else
                {
                    ucpData[i] = _SLIDER_M_12 + usValue;
                }
            }
            else
            {
                ucpData[i] = _SLIDER_M_0 + usValue;
                break;
            }
        }
    }
    else if(usValue >= 98)
    {
        if(bSliderPage != _OSD_ADJUST_TYPE)
        {        	
            ucpData[0] = _SLIDER_L_9;
        }
        else
        {
			ucpData[0] = _SLIDER_L_0_NEW;
        }
        ucpData[1] = _SLIDER_M_19;
        ucpData[2] = _SLIDER_M_19;
        ucpData[3] = _SLIDER_M_19;
        ucpData[4] = _SLIDER_M_19;
        ucpData[5] = _SLIDER_M_19;
        ucpData[6] = _SLIDER_M_19;
        ucpData[7] = _SLIDER_M_19;
        ucpData[8] = _SLIDER_R_0 + (usValue - 98) - 8;
        ucpData[9] = _SLIDER_R_0 + (usValue - 98);
    }

	ucpData[ucSliderLen] = _END_;
	pArray = ucpData;


	#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
	if(GET_OSD_ROTATE_STATUS() != _OSD_ROTATE_DEGREE_0)
	{
		ucOsdWidth = g_ucOsdHeight;
	}
	else
	#endif
	{
		ucOsdWidth = g_ucOsdWidth;
	}

#if(_OSD_ROTATE_FUNCTION != _OSD_ROTATE_OFF)
// #if(_OSD_ROTATE_3_ORIENTATION_SUPPORT == _ON)
       if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
       {
                ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
       }
// #endif
#endif
	while(*pArray != _END_)
	{
		if(*pArray == _NEXT_)
		{
			ucRow++;
			ucHTemp = ucCol;
			pArray++;
		}
		else if(*pArray == _SPACE_)
		{
			ucHTemp++;
			pArray++;
		}
		else if(*pArray == _REPEAT_)
		{
			ucCount =*(pArray + 1 )- 1;

			while(ucCount > 0)
			{
				if(*(pArray - 1) != _SPACE_)
				{
					OsdFontPut2Bit(ucRow, ucHTemp, *(pArray - 1), ucColor0, ucColor1, ucColor2, ucColor3);
				}

				ucHTemp++;

				if(ucHTemp == ucOsdWidth && (*(pArray + 1) != _NEXT_))
				{
					ucRow++;
					ucHTemp =ucCol;
				}
				ucCount--;
			}
			pArray += 2;
		}
		else
		{
			OsdFontPut2Bit(ucRow, ucHTemp, *pArray, ucColor0, ucColor1, ucColor2, ucColor3);
			ucHTemp++;

			if((ucHTemp == ucOsdWidth) && (*(pArray + 1) != _NEXT_))
			{
				ucRow++;
				ucHTemp = ucCol;
			}
			pArray++;
		}

	}
}

//--------------------------------------------------
// Description  : �����˵�
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplaySubMenuItem(void)
{
    BYTE i, count, ucString;
    BYTE ucStateIndex = OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur];
	BYTE Color = _CP_WHITE;
	BYTE ucSubMenuColor = 0;
    switch(ucStateIndex)
    {
        case _MENU_FUN_MUTE:
            count = 2;
            ucString = _STRING_MUTE_ITEM;
            break;
        case _MENU_FUN_CONTRAST_BRIGHTNESS:
            count = 2;
            ucString = _STRING_CONTRAST_BRIGHTNESS_ITEM;
            break;
        case _MENU_FUN_SIX_AXIS:
            count = 2;
            ucString = _STRING_SIX_AXIS_ITEM;
            break;
        case _MENU_FUN_TEMP:
            count = _CT_COLORTEMP_AMOUNT+1;
            ucString = _STRING_TEMP_ITEM;
            break;
        case _MENU_FUN_GAMUT:
            count = _PCM_OSD_AMOUNT+1;
            ucString = _STRING_MODE_ITEM;
            break;
        case _MENU_FUN_SPACE:
            count = 3;
            ucString = _STRING_SPACE_ITEM;
            break;
        case _MENU_FUN_RANGE:
            count = 3;
            ucString = _STRING_RANGE_ITEM;
            break;
        case _MENU_FUN_HDR:
            count = 2;
            ucString = _STRING_HDR_ITEM;
            break;
        case _MENU_FUN_ASPECT:
            count = 4;
            ucString = _STRING_ASPECT_ITEM;
            break;
        case _MENU_FUN_OVERSCAN:
            count = 2;
            ucString = _STRING_OVERSCAN_ITEM;
            break;
        case _MENU_FUN_RESPONSE_TIME:
            count = _OD_AMOUNT;
            ucString = _STRING_RESPONSE_TIME_ITEM;
            break;
        case _MENU_FUN_LANGUAGE:
#if(_DEFAULT_OSD_STYLE ==_TRG_OSD_STYLE)
			g_usOsdMenu3Page = GET_OSD_LANGUAGE()/_OSD_3RD_ITEM_LENGTH;
			count = ((_LANGUAGE_AMOUNT-g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH > _OSD_3RD_ITEM_LENGTH)  ? _OSD_3RD_ITEM_LENGTH : (_LANGUAGE_AMOUNT-g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH));
			//count = (_LANGUAGE_AMOUNT<=_OSD_3RD_ITEM_LENGTH)?(_LANGUAGE_AMOUNT):((g_usOsdMenu3Page>0)?(_LANGUAGE_AMOUNT-g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH):(_OSD_3RD_ITEM_LENGTH));
#else
			count = (_LANGUAGE_AMOUNT<=11) ? (_LANGUAGE_AMOUNT) : 11;
#endif
            ucString = _STRING_LANGUAGE_ITEM;
            break;
        case _MENU_FUN_FREESYNC:
            count = 2;
            ucString = _STRING_FREESYNC_ITEM;
            break;    
			
#if(_MPRT_SUPPORT == _ON)
		case _MENU_FUN_MPRT:
            count = 2;
            ucString = _STRING_MPRT_ITEM;
            break;
#endif

        case _MENU_FUN_NOTICE:
            count = 2;
            ucString = _STRING_NOTICE_ITEM;
            break;
#if(_DEF_OSD_DOUBLE)
        case _MENU_FUN_OSD_SIZE:
            count = 2;
            ucString = _STRING_OSD_SIZE_ITEM;
            break;
#endif
        case _MENU_FUN_OSD_BACKGROUND:
            count = 2;
            ucString = _STRING_OSD_BACKGROUND_ITEM;
            break;
        case _MENU_FUN_OSD_PIVOT:
#if(_DEF_PIVOT_OPTION_ON_OFF)
			count = 2;
#else
			count = 3;
#endif
            ucString = _STRING_OSD_PIVOT_ITEM;
            break;
        case _MENU_FUN_POWER_INDICATOR:
            count = 2;
            ucString = _STRING_POWER_INDICATOR_ITEM;
            break;
        case _MENU_FUN_AUTO_POWEROFF:
            count = 2;
            ucString = _STRING_AUTO_POWEROFF_ITEM;
            break;
        case _MENU_FUN_SLEEP:
            count = 5;
            ucString = _STRING_SLEEP_ITEM;
            break;
        case _MENU_FUN_ECO:
            count = 3;
            ucString = _STRING_ECO_ITEM;
            break;
        case _MENU_FUN_SEARCH:
            count = 2;
            ucString = _STRING_SEARCH_ITEM;
            break;
        case _MENU_FUN_DDCCI:
            count = 2;
            ucString = _STRING_DDCCI_ITEM;
            break;	
#if(_AI_EYE_PROTECTION == _ON)
        case _MENU_FUN_AI_EYE_PROTECTION:
            count = 2;
            ucString = _STRING_AI_EYE_PROTECTION_ITEM;
            break;	
#endif
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:
			count = 2;
			ucString = _STRING_AI_LIGHT_ADAPTIVATION_ITEM;
			break;	
#endif
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:
			count = 2;
			ucString = _STRING_AI_LOW_POWER_ITEM;
			break;	
#endif


		case _MENU_FUN_DP_VERSION:
			count = 2;
			ucString = _STRING_DP_VERSION_ITEM;
			break;
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_VGA_POSTION:
            count = 2;
            ucString = _STRING_POSTION;
            break;
#endif
#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_GAMING:
			count = 3;
			ucString = _STRING_GAMING_ITEM;
			break;
#endif

#if(_OSD_VIEWMODE_USER_GAME_MODE)		
		case _MENU_FUN_VIEWMODE_STANDARD:
			count = 5;
			ucString = _STRING_STANDARD_SUB;
			break;		

		case _MENU_FUN_VIEWMODE_FPS:
			count = 7;
			ucString = _STRING_FPS_ITEM;
			break;
#endif

        default:
            break;
    }

	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	
		OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
	
		if(ucString == _STRING_LANGUAGE_ITEM)
		{
			for(i=0;i<count;i++)
			{
				OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH, ((GET_OSD_LANGUAGE()/_OSD_3RD_ITEM_LENGTH == g_usOsdMenu3Page) && (GET_OSD_LANGUAGE() == i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH))?((COLOR(_CP_YELLOW, _CP_BG))):(COLOR(_CP_WHITE, _CP_BG)), _ENGLISH);
			}
		}
		else if(ucString == _STRING_CONTRAST_BRIGHTNESS_ITEM)
		{
			i = 0;
			OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, (OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST))?(COLOR(_CP_BLOCK, _CP_BG)):(COLOR(_CP_WHITE, _CP_BG)), GET_OSD_LANGUAGE());
	
			i = 1;
			OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, (OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT))?(COLOR(_CP_BLOCK, _CP_BG)):(COLOR(_CP_WHITE, _CP_BG)), GET_OSD_LANGUAGE());
		}
		else if(ucString == _STRING_SIX_AXIS_ITEM)
		{
			i = 0;
			OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, (OSD_ITEM_MASK_GET(_MENU_FUN_HUE))?(COLOR(_CP_BLOCK, _CP_BG)):(COLOR(_CP_WHITE, _CP_BG)), GET_OSD_LANGUAGE());
	
			
			i = 1;
			OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, (OSD_ITEM_MASK_GET(_MENU_FUN_SATURATION))?(COLOR(_CP_BLOCK, _CP_BG)):(COLOR(_CP_WHITE, _CP_BG)), GET_OSD_LANGUAGE());
		}
		else
		{
			for(i=0;i<count;i++)
			{
				ucSubMenuColor = COLOR(_CP_WHITE, _CP_BG);
				
				OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, ucSubMenuColor, GET_OSD_LANGUAGE());
			}
		}
		
#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

	OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));

	if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_LANGUAGE))
	{

		for(i=0;i<=count;i++)
		{
			OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
		}

    }
    else
    {
        for(i=0;i<count;i++)
        {		
#if(_ADVANCED_IMAGE_SUPPORT == _ON)
        	if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE0 && OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST))
        	{
				Color= (OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST) && i == 0) ? _CP_BLOCK : _CP_WHITE ;
				DebugMessageOsd("2.GET_OSD_STATE11",Color);

			}        	
			else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE0 && OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT))
        	{
				Color= (OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT) && i == 1) ? _CP_BLOCK : _CP_WHITE ;

			}
	 	#if(_DEF_MENU_OSD_SixColor == _ON)
        	else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE2) // ����SRGB
	 	#else
        	else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE1) // ����SRGB
        #endif
        	{
				Color= (
					(GET_OSD_GAME_MODE() == _GM_FPS1 || 
#if(_DEF_VIEWMODE_RTS == _ON)
					GET_OSD_GAME_MODE() == _GM_RTS || 
#endif
#if(_DEF_VIEWMODE_MOBA == _ON)
					GET_OSD_GAME_MODE() == _GM_MOBA || 
#endif
					GET_OSD_LOW_BLUE()!=0 || 
					GET_OSD_DCR_STATUS()!=_DCR_Level_0 || 
					GET_OSD_BLACKSTABLE()!=5 || 
					GET_OSD_VIEWMODE_TYPE() == _VM_MONO || 
					GET_OSD_VIEWMODE_TYPE() == _VM_TEXT || 
					GET_OSD_MPRT() )  \
				&& i == _CT_SRGB ) ? _CP_BLOCK : _CP_WHITE ;

			}

#endif

            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, COLOR(Color, _CP_BG), (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_LANGUAGE) ? _ENGLISH: GET_OSD_LANGUAGE());
			if(GetOsdShowType(ucStateIndex) == _TYPE_SUBMENU || (ucStateIndex == _MENU_FUN_TEMP && i == _CT_USER) 
#if(_OSD_VIEWMODE_USER_GAME_MODE)		
				|| ((ucStateIndex == _MENU_FUN_VIEWMODE_STANDARD ||ucStateIndex == _MENU_FUN_VIEWMODE_FPS) && i != _STANDARD_RECALL)
#endif
				)
			{
				OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(Color, _CP_BG));
			}

        }
    }

#else

	
    if(GET_OSD_LANGUAGE() > (_OSD_3RD_ITEM_LENGTH-1))
	{
        pageflag = 1;
    }
	else
	{
        pageflag = 0;
    }
	
    OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
	//DebugMessageOsd("1.pageflag",pageflag);
    if((OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_LANGUAGE))
	{

		if(pageflag == 1)
		{
	        for(i=count;i<_LANGUAGE_AMOUNT;i++)
	        {
	            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i - 10 ), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	        }
			OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));
		}
		else
		{
			for(i=0;i<count;i++)
			{
				OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
			}
			OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));
		}

    }
    else
    {
        for(i=0;i<count;i++)
        {		
#if(_ADVANCED_IMAGE_SUPPORT == _ON)
        	if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE0 && OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST))
        	{
				Color= (OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST) && i == 0) ? _CP_BLOCK : _CP_WHITE ;
				DebugMessageOsd("2.GET_OSD_STATE11",Color);

			}        	
			else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE0 && OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT))
        	{
				Color= (OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT) && i == 1) ? _CP_BLOCK : _CP_WHITE ;

			}
	 	#if(_DEF_MENU_OSD_SixColor == _ON)
        	else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE2) // ����SRGB
	 	#else
        	else if(GET_OSD_STATE()==_MENU_OSDSETTING_TATE1) // ����SRGB
        #endif
        	{
				Color= (
					(GET_OSD_GAME_MODE() == _GM_FPS1 || 
#if(_DEF_VIEWMODE_RTS == _ON)
					GET_OSD_GAME_MODE() == _GM_RTS || 
#endif
#if(_DEF_VIEWMODE_MOBA == _ON)
					GET_OSD_GAME_MODE() == _GM_MOBA || 
#endif
					GET_OSD_LOW_BLUE()!=0 || 
					GET_OSD_DCR_STATUS()!=_DCR_Level_0 || 
					GET_OSD_BLACKSTABLE()!=5 || 
					GET_OSD_VIEWMODE_TYPE() == _VM_MONO || 
					GET_OSD_VIEWMODE_TYPE() == _VM_TEXT || 
					GET_OSD_MPRT() )  \
				&& i == _CT_SRGB ) ? _CP_BLOCK : _CP_WHITE ;

			}

#endif

            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, ucString, i, COLOR(Color, _CP_BG), (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_LANGUAGE) ? _ENGLISH: GET_OSD_LANGUAGE());
            if(GetOsdShowType(ucStateIndex) == _TYPE_SUBMENU || (ucStateIndex == _MENU_FUN_TEMP && i == _CT_USER))
            {
                OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START + i), COL(_COL_2ND_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(Color, _CP_BG));
            }
        }
    }

#endif

	
}

//--------------------------------------------------
// Description  :
// Input Value  :  
// Output Value : None
//--------------------------------------------------
void OsdDisplayBlackWindow(bit type)
{
	BYTE ucColor = _CP_GRAY;
	
 	// _MAIN_WIN_BLACK_FRAME _OSD_WINDOW_8
	if(type == _ON)
	{
		ucColor = _CP_BLACK;
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_BLACK_FRAME),XSTART(_MAIN_WIN_BLACK_FRAME_X_START), YSTART(_MAIN_WIN_BLACK_FRAME_Y_START), XEND(_MAIN_WIN_BLACK_FRAME_X_END), YEND(_MAIN_WIN_BLACK_FRAME_Y_END),_CP_BG, _CP_BLUE, _CP_BG);
		//OsdWindowDrawing(WINNO(_OSD_WINDOW_6),XSTART(_MAIN_WIN_BLACK_FRAME_X_START), YSTART(_MAIN_WIN_BLACK_FRAME_Y_START), XEND(_MAIN_WIN_BLACK_FRAME_X_END), YEND(_MAIN_WIN_BLACK_FRAME_Y_END),COLOR0(_CP_BLACK));
		OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + 1), COL(_COL_BLACK_FRAME_ARC_START + (_COL_5TH_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BLACK));
#if(_5KEY_MENU_STYLE)
		//LJ 0228 �龰ģʽͼ���ɫ
		OsdWindowDrawingHighlight(WINNO(_OSD_WINDOW_4_4),XSTART(_MAIN_WIN_BLACK_FRAME_X_START), YSTART(_MAIN_WIN_BLACK_FRAME_Y_START), XEND(_MAIN_WIN_BLACK_FRAME_X_END), YEND(_MAIN_WIN_BLACK_FRAME_Y_END),_CP_BG, _CP_WHITE, _CP_BG);
#endif
	}
	else
	{
		ScalerOsdWindowDisable(_MAIN_WIN_BLACK_FRAME);
#if(_5KEY_MENU_STYLE)
		ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
#endif
	}
	
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(_COL_BLACK_FRAME_ARC_START), tiOSD_1BIT_BLK_FRAME_TOP_ARC, COLOR(ucColor, _CP_GRAY));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(_COL_BLACK_FRAME_ARC_START+1), tiOSD_1BIT_BLK_FRAME_PATCH, COLOR(ucColor, ucColor));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_T), COL(_COL_SUB_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(ucColor, _CP_DARKGRAY));

	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(_COL_BLACK_FRAME_ARC_START), tiOSD_1BIT_BLK_FRAME_BOTTOM_ARC, COLOR(ucColor, _CP_GRAY));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(_COL_BLACK_FRAME_ARC_START+1), tiOSD_1BIT_BLK_FRAME_PATCH, COLOR(ucColor, ucColor));
	OsdFontPut1BitTable(ROW(_ROW_SUB_FRAME_ARC_B), COL(_COL_SUB_FRAME_ARC_R), tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(ucColor, _CP_DARKGRAY));

}


//--------------------------------------------------
// Description      : Draw 5rh Menu 
// Input Value      : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplay5thMenu(void)
{
    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
	#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
    #else
	ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(2)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(2)),_CP_BLUE, _CP_WHITE, _CP_BG);
    OsdDisplayBlackWindow(_ON);
	#endif
}
//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{
//if(_OSD_FUN_START<=GET_OSD_STATE() && GET_OSD_STATE()< _OSD_FUN_END)
{
    switch(GET_KEYMESSAGE())
    {
        case _RIGHT_KEY_MESSAGE:
		case _DOWN_KEY_MESSAGE:
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _LEFT_KEY_MESSAGE:
		case _UP_KEY_MESSAGE:
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}
    return usValue;
}

//--------------------------------------------------
// Description  : Six Color Get One Color
// Input Value  : SixColor
// Output Value : None
//--------------------------------------------------
void OsdDisplaySixColorGetOneColor(BYTE ucColor)
{
    switch(ucColor)
    {
        case _SIXCOLOR_R:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueR);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationR);
            break;

        case _SIXCOLOR_Y:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueY);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationY);
            break;

        case _SIXCOLOR_G:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueG);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationG);
            break;

        case _SIXCOLOR_C:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueC);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationC);
            break;

        case _SIXCOLOR_B:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueB);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationB);
            break;

        case _SIXCOLOR_M:
            SET_OSD_SIX_COLOR_HUE(g_stVscSceneModeData.ucSixColorHueM);
            SET_OSD_SIX_COLOR_SATURATION(g_stVscSceneModeData.ucSixColorSaturationM);
            break;

        default:
            break;
    }
}





//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
void OsdDispHotKeySourceMenu(BYTE Type)
{
	OsdDispDisableOsd();
	PageInit();
	//DebugMessageOsd("2.GET_OSD_HOTKEY_LEFT",GET_OSD_HOTKEY_LEFT());
	SET_OSD_STATE(_OSD_HOTKEY_FUNC);
	if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI)&&GET_OSD_HOTKEY_LEFT()==_OSD_HOTKEY_CONBRI)
		Type=_OSD_HOTKEY_VIEWMODE;

	{
		OsdDispDrawHotKeyWindow(Type);
	}
}
#elif(_DEF_KEY_ROCKER)
void OsdDispHotKeySourceMenu(BYTE Type)
{
	
#if _GSYNC_TEST
    ucDsiableShowVFreqFlag = 1;
#endif
	OsdDispDisableOsd();
	
	SET_OSD_STATE(_OSD_HOTKEY_FUNC);
	
	g_usBackupValue = GetOsdValue(Type);

	OsdDispDrawHotKeyWindow(Type);
}
#endif



//����
void OsdDisplayUpdateVolumeMuteIcon(void)
{
#if 1//(_DEF_KEYPAD_TYPE == _KEYPAD_NORMAL_5KEY)
    if (GET_OSD_VOLUME_MUTE() == _OFF)
    {

   #if(_DEF_JS_KEY_ICON_5_KEY_MODE)  //2025.02.07 tx
       // OsdFontPut1BitTable((2 * HotKeyPageIndex + 1), _COL_HOTKEY_TEXT_START + 1, tiOSD_OSDKEY_ICON_VOLUME, COLOR(_CP_WHITE, _CP_BG));
       // OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL+ (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BLUE_EG), COLOR1(_CP_WHITE), COLOR2(_CP_WHITE), COLOR3(_CP_RED));
 	   
       OsdFontPut1BitTable((2 * HotKeyPageIndex + 1), _COL_HOTKEY_TEXT_START + 1, tiOSD_OSDKEY_ICON_VOLUME, COLOR(_CP_WHITE, _CP_BG));
	   OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL+ (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BLUE_EG), COLOR1(_CP_WHITE), COLOR2(_CP_WHITE), COLOR3(_CP_RED));
	   
   #else
       OsdFontPut2BitTable((2 * HotKeyPageIndex + 1), _COL_HOTKEY_TEXT_START + 1, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_RED), COLOR3(_CP_RED));
	   OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
   #endif

      // OsdFontPut2BitTable((_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW,_KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_RED), COLOR3(_CP_RED));
    }
    else if (GET_OSD_VOLUME_MUTE() == _ON)
    {
    	OsdFontPut2BitTable((2 * HotKeyPageIndex + 1), _COL_HOTKEY_TEXT_START + 1, tiOSD_OSDKEY_2BIT_ICON_VOLUME_NEW, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_BG), COLOR3(_CP_RED));
        

	   #if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	    OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + (_KEY_ICON_WIDTH + 1) * 2+1, tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE,(_KEY_BLACK)== 1?_CP_BLACK : _CP_DARKGRAY));
		
	   #else
		OsdFontPut2BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_DARKGRAY), COLOR1(_CP_WHITE), COLOR2(_CP_RED), COLOR3(_CP_RED));
       #endif
	}
#endif
}

void OsdHotKeyMainInterface(void)
{

	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_CONBRI) // CONBRI�����������������
	{
		OsdDisplaySliderAndNumber(_OSD_HOTKEY_CONTRAST, GetOsdValue(_OSD_HOTKEY_CONTRAST), _SLIDER_HOTKEY);
		OsdDisplaySliderAndNumber(_OSD_HOTKEY_BACKLIGHT, GetOsdValue(_OSD_HOTKEY_BACKLIGHT), _SLIDER_HOTKEY);
	}
	// �ײ�ͼ��
	else
	{
#if(_MENU_AUDIO_SUPPORT)
		if (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_VOLUME) // VOLUME��������Ⱥͽ�������
		{
			//OsdFontPut2BitTable((2 * HotKeyPageIndex + 1), 4, tiOSD_OSDKEY_ICON_NO_VOLUME, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_RED), COLOR3(_CP_RED));
			OsdDisplaySliderAndNumber(_OSD_HOTKEY_VOLUME, GetOsdValue(_OSD_HOTKEY_VOLUME), _SLIDER_HOTKEY);
			OsdDisplayUpdateVolumeMuteIcon();
		}
#endif
	}

}


void OsdHotKeyString(void)
{
    BYTE i;
    BYTE ucColor;
    for (i = 0; i < OsdHotPageSize[HotKeyPageIndex]; i++)
        switch (OSD_HOT_KEY_PAGE)
        {
#if(_DEF_NAVIGATION_OSD_ENABLE)
            case _OSD_START_UP:
                OsdPropPutString(ROW(2 + 3 * i), COL(_COL_HOTKEY_TEXT_START + 4), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                break;
#endif
            case _OSD_HOTKEY_VIEWMODE:
#if(_DEF_NAVIGATION_OSD_ENABLE == _OFF)
                if (i == 0)
                {
                    OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_TITLE_START), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_VIEWMODE_SELECT, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                }
#endif
                OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_VIEWMODE, i, COLOR(GetOsdValue(_MENU_VIEWMODE)==i ? _CP_YELLOW : _CP_WHITE, _CP_BG) , GET_OSD_LANGUAGE());
                break;
				
#if(_MENU_AUDIO_SUPPORT)
            case _OSD_HOTKEY_VOLUME:
                OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i) - 2), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_VOLUME, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                break;
#endif
            case _OSD_HOTKEY_CONBRI:
				ucColor = (((OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST))&&i==0) || ((OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT))&&i==1)) ? _CP_BLOCK : _CP_WHITE ;
                OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i) - 2), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_CONBRI, i, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
                break;
				
            case _OSD_HOTKEY_INPUT: 
#if(_DEF_NAVIGATION_OSD_ENABLE == _OFF)
                if (i == 0)
                {
                    OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_TITLE_START), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_INPUT_SELECT, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                }				
				ucColor = (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP) ? SysSourceGetCableDetect(InputSourceConvert(i)) == _FALSE ? _CP_BLOCK : (GetOsdValue(_MENU_INPUT) == i ? _CP_YELLOW : _CP_WHITE)  : (GetOsdValue(_MENU_INPUT) == i ? _CP_YELLOW : _CP_WHITE) ;
				OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_INPUT, i, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
#else		

	#if(_PROJECT_ID==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115 || _PROJECT_ID==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)				
				ucColor = (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP) ? SysSourceGetCableDetect(InputSourceConvert(i)) == _FALSE ? _CP_BLOCK : (GetOsdValue(_MENU_INPUT) == i ? _CP_YELLOW : _CP_WHITE)  : (GetOsdValue(_MENU_INPUT) == i ? _CP_YELLOW : _CP_WHITE) ;
				OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_INPUT, i, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
	#else
				OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_INPUT, i, COLOR((GetOsdValue(_MENU_INPUT) == i ? _CP_YELLOW : _CP_WHITE),_CP_BG), GET_OSD_LANGUAGE());
	#endif

#endif

            	break;
				
#if(ENABLE_LANGUAGE_SELECT_OSD)			
            case _OSD_HOTKEY_LANGUAGE_SELECT:
                if (i == 0)
                {
                    OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_TITLE_START), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_1, _STRING_HOT_KEY_LANGUAGE_SELECT, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
                }
                OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_1, _STRING_HOT_KEY_LANGUAGE, i, COLOR(GET_OSD_LANGUAGE()==i ? _CP_YELLOW : _CP_WHITE, _CP_BG), _ENGLISH);
                break;
#endif
#if(_DEF_District_swtich_Message == _ON)
            case _OSD_HOTKEY_DISTRICT_SELECT:
                if (i == 0)
                {
                    OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_TITLE_START), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_DISTRICT_SELECT, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                }
                OsdPropPutStringCenter(ROW(_ROW_HOTKEY_TEXT_START(i)), COL(_COL_HOTKEY_TEXT_START), _HOTKEY_FRAME_WIDTH, _PFONT_PAGE_0, _STRING_HOT_KEY_DISTRICT, i, COLOR(_DEF_REGION_InitData==i ? _CP_YELLOW : _CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                break;
#endif
			default:
                break;
        }
}

// �ȼ�
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
void OsdDispDrawHotKeyWindow(BYTE ucState)
{
	BYTE i = 0;

	BYTE MapAWidth, MapAHight;
	BYTE MapBWidth, MapBHight;
	BYTE HeightAmount = 0;
	
	OSD_HOT_KEY_PAGE = ucState; 											   // �ȼ�ҳ��ѡ��

	HotKeyPageIndex = OSD_HOT_KEY_PAGE - _OSD_HOTKEY_VIEWMODE;

	if(0);
#if(_DEF_District_swtich_Message == _ON)
	else if(ucState==_OSD_HOTKEY_DISTRICT_SELECT)
		OSD_SubMenuCur = _DEF_REGION_InitData; //Ĭ��ֵ��ֵ	
#endif
	else if(ucState==_OSD_HOTKEY_INPUT)
		OSD_SubMenuCur = GetOsdValue(_MENU_INPUT); 
	else
		OSD_SubMenuCur = 0;
	
	/*
	OsdFuncDisableOsd();
	// ��ս��棬�������
	osdHotKeyClearWindow();
	*/

	//OsdDispDisableOsd();
	OsdFuncDisableOsd();
	UpdateMaskValue();

	//SET_OSD_STATE(ucState);

	HeightAmount = OsdHotPageSize[HotKeyPageIndex];//GetHotKeyFunctionAmount();  // ��ȡÿһҳ������

	switch(ucState)
	{
		// With Title
		case _OSD_HOTKEY_VIEWMODE:
#if(_MENU_AUDIO_SUPPORT)
		case _OSD_HOTKEY_VOLUME:
#endif
		case _OSD_HOTKEY_INPUT:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = ((HeightAmount) * 2 + 2 + 4);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;

		// Without Title
		case _OSD_HOTKEY_CONBRI:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = (HeightAmount * 2 + 4 + 1);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;

		// Without Bottom
		case _OSD_HOTKEY_LANGUAGE_SELECT:
#if(_DEF_District_swtich_Message == _ON)
		case _OSD_HOTKEY_DISTRICT_SELECT:
#endif
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = (HeightAmount * 2 + 2 + 2);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;
			
		case _OSD_START_UP:

		default:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = ((HeightAmount) * 2 + 2 + 4);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;
	}

	ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
	ScalerOsd2FontFunction(_ENABLE);
    //OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
	OsdFuncApplyMapOsdAB(WIDTH(MapAWidth), HEIGHT(MapAHight), COLOR(_CP_WHITE, _CP_BG),
						 WIDTH(MapBWidth), HEIGHT(MapBHight), COLOR(_CP_WHITE, _CP_BG));
    //OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

	// Adjust Color Palette
	OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

	// set 2bit Font offest
	OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
	OsdFontVLCLoadFont(_FONT1_GLOBAL);
	
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
	OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY);
#endif
	OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
	OsdFontVLCLoadFont(_FONT_2BIT_HOTKEY);

	// �����͵ײ�Բ��
	OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_ICON_NAV_TL_CORNER, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(MapAHight-1), COL(0), tiOSD_ICON_NAV_BL_CORNER, COLOR(_CP_DARKGRAY, _CP_BG));
	
	OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),	PIXELCOL(0),			PIXELROW(1), 
											PIXELCOL(MapAWidth),	PIXELROW(MapAHight-1),
											COLOR0(_CP_DARKGRAY));
	
#if(_DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)

	switch(ucState)
	{
		// �Ϸֽ���
		case _OSD_HOTKEY_LANGUAGE_SELECT:
		#if(_DEF_District_swtich_Message == _ON)
		case _OSD_HOTKEY_DISTRICT_SELECT:
		#endif
			ScalerOsdWindowDisable(_OSD_WINDOW_8);
			OsdWindowDrawing(WINNO(_OSD_WINDOW_9),XSTART(_MAINMENU_WIN9_H_X_START),YSTART(_MAINMENU_WIN9_H_Y_START),XEND(_MAINMENU_WIN9_H_X_END),YEND(_MAINMENU_WIN9_H_Y_END), _CP_WHITE);
			break;

		case _OSD_HOTKEY_CONBRI:
			// �·ֽ���
			ScalerOsdWindowDisable(_OSD_WINDOW_9);
			OsdWindowDrawing(WINNO(_OSD_WINDOW_8),XSTART(_MAINMENU_WIN8_H_X_START),YSTART(_MAINMENU_WIN8_H_Y_START(MapAHight)),XEND(_MAINMENU_WIN8_H_X_END), YEND(_MAINMENU_WIN8_H_Y_END(MapAHight)), _CP_WHITE);
			break;

		// �Ϸֽ��� - �·ֽ���
		case _OSD_HOTKEY_VIEWMODE:
		case _OSD_HOTKEY_INPUT:
		#if(_MENU_AUDIO_SUPPORT)
		case _OSD_HOTKEY_VOLUME:
		#endif
			OsdWindowDrawing(WINNO(_OSD_WINDOW_9),XSTART(_MAINMENU_WIN9_H_X_START),YSTART(_MAINMENU_WIN9_H_Y_START),XEND(_MAINMENU_WIN9_H_X_END),YEND(_MAINMENU_WIN9_H_Y_END), _CP_WHITE);
			OsdWindowDrawing(WINNO(_OSD_WINDOW_8),XSTART(_MAINMENU_WIN8_H_X_START),YSTART(_MAINMENU_WIN8_H_Y_START(MapAHight)),XEND(_MAINMENU_WIN8_H_X_END), YEND(_MAINMENU_WIN8_H_Y_END(MapAHight)), _CP_WHITE);
			break;


			
		default:
			break;
	}

#endif

	// ��ݼ���Ҫҳ��
	OsdHotKeyMainInterface();
	
	// ����
	OsdHotKeyString();
	
	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_VIEWMODE )
	{
		OSD_SubMenuCur=GetOsdValue(_MENU_VIEWMODE); 				
		
		OsdWindowDrawing(_HOT_KEY_SELECT_WIN, PIXELCOL(0),					PIXELROW(3+GetOsdValue(_MENU_VIEWMODE)*2)-9, 
								 PIXELCOL(_HOTKEY_FRAME_WIDTH), PIXELROW(3+GetOsdValue(_MENU_VIEWMODE)*2+2)-9,
								_CP_BLUE);

	}

	else
		osdDispDrawHotKeyCursor();


	// ��ݼ��ײ��ļ���ͼ��
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
	OsdFontPut2BitTable(ROW(MapAHight-1), COL(0), tiOSD_2BIT_HOT_FOLDER_DOWN, _CP_BG, _CP_BLUE, _CP_DARKGRAY, _CP_DARKGRAY);
#endif

	
	// ICON
#if(_DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)
	if(ucState >= _OSD_HOTKEY_VIEWMODE && ucState <= _OSD_HOTKEY_INPUT)
	{
		ScalerOsdWindowHighlightFunction(_ENABLE, _HOT_KEY_SELECT_WIN, _CP_WHITE, _CP_BG, _CP_BG);
#if(_MENU_AUDIO_SUPPORT)
#if (_DEF_JS_KEY_ICON_5_KEY_MODE)   //2025.02.07  tx

#if(_5KEY_MENU_STYLE)
         OsdFontPut2BitTable(ROW(MapAHight-3), COL(1), tiOSD_OSDKEY_2BIT_ICON_VOLUME, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_DARKGRAY), COLOR3(_CP_BG));
        //2025.02.11 tx
		if(SysSourceGetSourceType() == _SOURCE_VGA)
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(5), tiOSD_OSDKEY_2BIT_ICON_AUDIO, COLOR0(_CP_BG), COLOR1(_CP_GRAY), COLOR2 (_CP_DARKGRAY), COLOR3(_CP_BG));			
        else
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(5), tiOSD_OSDKEY_2BIT_ICON_AUDIO, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2 (_CP_DARKGRAY), COLOR3(_CP_BG));
	  if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI))
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(9), tiOSD_OSDKEY_2BIT_ICON_CORBRI, COLOR0(_CP_BG), COLOR1(_CP_GRAY), COLOR2(_CP_DARKGRAY), COLOR3(_CP_BG));
	  else
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(9), tiOSD_OSDKEY_2BIT_ICON_CORBRI, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_DARKGRAY), COLOR3(_CP_BG));
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(13), tiOSD_OSDKEY_2BIT_ICON_INPUT, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(_CP_DARKGRAY), COLOR3(_CP_BG));
		 OsdFontPut1BitTable(ROW(MapAHight-1), COL(1 + (4 * HotKeyPageIndex)), tiOSD_OSDKEY_ICON_PLACE, COLOR(_CP_BLUE, _CP_DARKGRAY));
#else
         OsdFontPut2BitTable(ROW(MapAHight-3), COL(1), tiOSD_OSDKEY_2BIT_ICON_VOLUME, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(ucState==_OSD_HOTKEY_VIEWMODE ?_CP_BLUE : _CP_DARKGRAY), COLOR3(_CP_BG));
         OsdFontPut2BitTable(ROW(MapAHight-3), COL(5), tiOSD_OSDKEY_2BIT_ICON_AUDIO, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2 (ucState==_OSD_HOTKEY_VOLUME ?_CP_BLUE : _CP_DARKGRAY), COLOR3(_CP_BG));
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(9), tiOSD_OSDKEY_2BIT_ICON_CORBRI, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(ucState==_OSD_HOTKEY_CONBRI ?_CP_BLUE : _CP_DARKGRAY), COLOR3(_CP_BG));
		 OsdFontPut2BitTable(ROW(MapAHight-3), COL(13), tiOSD_OSDKEY_2BIT_ICON_INPUT, COLOR0(_CP_BG), COLOR1(_CP_WHITE), COLOR2(ucState==_OSD_HOTKEY_INPUT ?_CP_BLUE : _CP_DARKGRAY), COLOR3(_CP_BG));
		 //OsdFontPut1BitTable(ROW(MapAHight-1), COL(1 + (4 * HotKeyPageIndex)), tiOSD_OSDKEY_ICON_PLACE, COLOR(_CP_BLUE, _CP_DARKGRAY));



#endif

#else
		OsdFontPut1BitTable(ROW(MapAHight-3), COL(1), tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE, _CP_BG));
		OsdFontPut1BitTable(ROW(MapAHight-3), COL(5), tiOSD_OSDKEY_ICON_Audio, COLOR(_CP_WHITE, _CP_BG));
		OsdFontPut1BitTable(ROW(MapAHight-3), COL(9), tiOSD_OSDKEY_ICON_ConBri, COLOR((OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI) ? _CP_BLOCK : _CP_WHITE), _CP_BG));
		OsdFontPut1BitTable(ROW(MapAHight-3), COL(13), tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE, _CP_BG));	
#endif
		// �ײ���ͷ
		//OsdFontPut1BitTable(ROW(MapAHight-1), COL(1 + (4 * HotKeyPageIndex)), tiOSD_OSDKEY_ICON_PLACE, COLOR(_CP_BLUE, _CP_DARKGRAY));
#else		
		OsdFontPut1BitTable(ROW(MapAHight-2), COL(1), tiOSD_OSDKEY_ICON_View, COLOR(_CP_WHITE, _CP_BG));
		OsdFontPut1BitTable(ROW(MapAHight-2), COL(7), tiOSD_OSDKEY_ICON_ConBri, COLOR((OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI) ? _CP_BLOCK : _CP_WHITE), _CP_BG));
		OsdFontPut1BitTable(ROW(MapAHight-2), COL(13), tiOSD_OSDKEY_ICON_Input, COLOR(_CP_WHITE, _CP_BG));		
		// �ײ���ͷ
		//OsdFontPut1BitTable(ROW(MapAHight-1), COL(1 + (6 * HotKeyPageIndex)), tiOSD_OSDKEY_ICON_PLACE, COLOR(_CP_BLUE, _CP_DARKGRAY));
#endif

	}
#endif

	// ��������
	OsdDisplayKeyIndex(_LAYER_HOTKEY);

	if(OSD_HOT_KEY_PAGE <= _OSD_HOTKEY_DISTRICT_SELECT && OSD_HOT_KEY_PAGE >= _OSD_HOTKEY_VIEWMODE )
	{
		if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_VIEWMODE)	//�˵��밴�������
		 	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 100-OsdHotPageSize[HotKeyPageIndex]-1);
#if(_MENU_AUDIO_SUPPORT)
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_VOLUME)
		 	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 100-OsdHotPageSize[HotKeyPageIndex]-5);
#endif
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_CONBRI)
		 	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 100-OsdHotPageSize[HotKeyPageIndex]-4);
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_INPUT)
		 	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 100-OsdHotPageSize[HotKeyPageIndex]-4);
#if(_DEF_District_swtich_Message == _ON)
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_DISTRICT_SELECT)
		 	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 100-OsdHotPageSize[HotKeyPageIndex]);
#endif
		else
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H-3, 90);
	}

	else
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_MAIN_MENU_POSION_H, _KEY_MAIN_MENU_POSION_V);
	
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_MENU_POSION_H, _KEY_NAVIGATION_MENU_POSION_V);
#else
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#endif

	OsdFuncEnableOsd();
}

#elif(_DEF_KEY_ROCKER)
// �ȼ�
//--------------------------------------------------
// Description  : Draw the menu of hot key
// Input Value  : eg _OSD_HOTKEY_VIEWMODE ... _OSD_HOTKEY_BRIGHTNESS
// Output Value : None
//--------------------------------------------------
void OsdDispDrawHotKeyWindow(BYTE ucState)
{
	BYTE i = 0;

	BYTE MapAWidth, MapAHight;
	BYTE MapBWidth, MapBHight;
	BYTE HeightAmount = 0;
	
	OSD_HOT_KEY_PAGE = ucState; 											   // �ȼ�ҳ��ѡ��

	HotKeyPageIndex = OSD_HOT_KEY_PAGE - _OSD_HOTKEY_VIEWMODE;
	
	if(0);
#if(_DEF_District_swtich_Message == _ON)
	else if(ucState==_OSD_HOTKEY_DISTRICT_SELECT)
		OSD_SubMenuCur = _DEF_REGION_InitData; //Ĭ��ֵ��ֵ 
#endif
#if(ENABLE_LANGUAGE_SELECT_OSD == _ON)
	else if(ucState==_OSD_HOTKEY_LANGUAGE_SELECT)
		OSD_SubMenuCur = GetOsdValue(_MENU_FUN_LANGUAGE);
#endif
	else if(ucState==_OSD_HOTKEY_INPUT)
		OSD_SubMenuCur = GetOsdValue(_MENU_INPUT); 
	else
		OSD_SubMenuCur = 0;
	
	/*
	OsdFuncDisableOsd();
	// ��ս��棬�������
	osdHotKeyClearWindow();
	*/

	//OsdDispDisableOsd();
	OsdFuncDisableOsd();
	UpdateMaskValue();

	//SET_OSD_STATE(ucState);

	HeightAmount = OsdHotPageSize[HotKeyPageIndex];//GetHotKeyFunctionAmount();  // ��ȡÿһҳ������

	switch(ucState)
	{
		// With Title
		case _OSD_HOTKEY_VIEWMODE:
		case _OSD_HOTKEY_INPUT:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = (HeightAmount * 2 + 4);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;

		// Without Title
#if(_MENU_AUDIO_SUPPORT)
		case _OSD_HOTKEY_VOLUME:
#endif
		case _OSD_HOTKEY_CONBRI:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = (HeightAmount * 2 + 2);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;

		// Without Bottom
		case _OSD_HOTKEY_LANGUAGE_SELECT:
#if(_DEF_District_swtich_Message == _ON)
		case _OSD_HOTKEY_DISTRICT_SELECT:
#endif
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = (HeightAmount * 2 + 2 + 2);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;
			
		default:
			MapAWidth = _HOTKEY_FRAME_WIDTH;
			MapAHight = ((HeightAmount) * 2 + 2 + 4);
			MapBWidth = _MAIN_B_OSD_WIDTH;
			MapBHight = _MAIN_B_OSD_HEIGHT;
			break;
	}

	ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
	ScalerOsd2FontFunction(_ENABLE);
	OsdFuncApplyMapOsdAB(WIDTH(MapAWidth), HEIGHT(MapAHight+1), COLOR(_CP_WHITE, _CP_BG),
						 WIDTH(MapBWidth), HEIGHT(MapBHight), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,HEIGHT(MapAHight+1), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(MapBHight),_OSD_FONT_LIB_ROTATION_ENABLE);
 #endif	

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

	// Adjust Color Palette
	OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

	// set 2bit Font offest
	OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
	OsdFontVLCLoadFont(_FONT1_GLOBAL);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY);
#endif
	OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
	OsdFontVLCLoadFont(_FONT_2BIT_HOTKEY);
	

	// �ײ�Բ��
	OsdFontPut1BitTable(ROW(MapAHight-1), COL(0), tiOSD_ICON_NAV_BL_CORNER, COLOR(_CP_DARKGRAY, _CP_BG));


	if(ucState==_OSD_HOTKEY_VIEWMODE || ucState==_OSD_HOTKEY_INPUT)
	{
		// ����Բ��
		OsdFontPut1BitTable(ROW(1), COL(0), tiOSD_ICON_NAV_TL_CORNER, COLOR(_CP_DARKGRAY, _CP_BG));
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),	PIXELCOL(0),			PIXELROW(1)+9, 
												PIXELCOL(MapAWidth),	PIXELROW(MapAHight-1),
												COLOR0(_CP_DARKGRAY));

	}
	else
	{
		// ����Բ��
		OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_ICON_NAV_TL_CORNER, COLOR(_CP_DARKGRAY, _CP_BG));
		OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),	PIXELCOL(0),			PIXELROW(1), 
												PIXELCOL(MapAWidth),	PIXELROW(MapAHight-1),
												COLOR0(_CP_DARKGRAY));

	}
	

	// ��ݼ��ײ��ļ���ͼ��
	OsdFontPut2BitTable(ROW(MapAHight-1), COL(0), tiOSD_2BIT_HOT_FOLDER_DOWN, _CP_BG, _CP_BLUE, _CP_DARKGRAY, _CP_DARKGRAY);



	switch(ucState)
	{
		// �Ϸֽ���
		case _OSD_HOTKEY_LANGUAGE_SELECT:
#if(_DEF_District_swtich_Message == _ON)
		case _OSD_HOTKEY_DISTRICT_SELECT:
#endif
			ScalerOsdWindowDisable(_OSD_WINDOW_8);
			OsdWindowDrawing(WINNO(_OSD_WINDOW_9),XSTART(_MAINMENU_WIN9_H_X_START),YSTART(_MAINMENU_WIN9_H_Y_START),XEND(_MAINMENU_WIN9_H_X_END),YEND(_MAINMENU_WIN9_H_Y_END), _CP_WHITE);
			break;
			
		default:
			break;
	}

	// ��ݼ���Ҫҳ��
	//OsdHotKeyMainInterface();
	
	// ����
	OsdHotKeyString();
	
	if(GetOsdShowType(OSD_HOT_KEY_PAGE) == _TYPE_ITEM)
		OSD_SubMenuCur = GetOsdValue(OSD_HOT_KEY_PAGE);

	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_VIEWMODE )
	{
		OSD_SubMenuCur=GetOsdValue(_MENU_VIEWMODE); 				   
		OsdWindowDrawing(_HOT_KEY_SELECT_WIN, PIXELCOL(0),					PIXELROW(3+GetOsdValue(_MENU_VIEWMODE)*2)-9, 
								 PIXELCOL(_HOTKEY_FRAME_WIDTH), PIXELROW(3+GetOsdValue(_MENU_VIEWMODE)*2+2)-9,
								_CP_BLUE);

	}
	else

		osdDispDrawHotKeyCursor();

	// ��������
    OsdDisplayKeyIndex(_LAYER_HOTKEY);
	

	if(OSD_HOT_KEY_PAGE <= _OSD_HOTKEY_DISTRICT_SELECT && OSD_HOT_KEY_PAGE >= _OSD_HOTKEY_START )
		 OsdDispSetPosition(OSD_HOT_KEY_PAGE, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_POSION_H, _KEY_MAIN_MENU_POSION_V);
	else
		 OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_MAIN_MENU_POSION_H, _KEY_MAIN_MENU_POSION_V);

#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#elif(_DEF_KEY_ROCKER)
	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#endif
	OsdFuncEnableOsd();

}


#endif

void osdDispDrawHotKeyCursor(void)
{
		
	//BYTE count = OsdHotPageSize[_OSD_HOTKEY_INPUT - _OSD_HOTKEY_VIEWMODE]-1;
	//BYTE Color = _CP_WHITE;
	//DebugMessageOsd("0.OSD_SubMenuCur",OSD_SubMenuCur);
	
    if (OSD_SubMenuCur > OsdHotPageSize[OSD_HOT_KEY_PAGE - _OSD_HOTKEY_VIEWMODE] - 1 && OSD_SubMenuCur < 0XFF)
    {
        OSD_SubMenuCur = 0;
    }
    else if (OSD_SubMenuCur > 0xfe) // �޸�����ʽ��
    {
        OSD_SubMenuCur = OsdHotPageSize[OSD_HOT_KEY_PAGE - _OSD_HOTKEY_VIEWMODE] - 1;

    }
  
#if(_PCB_TYPE ==_RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS )
	  if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_INPUT && SysSourceGetCableDetect(_A0_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		  OSD_SubMenuCur = _D1_PORT;  
	  else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_INPUT && SysSourceGetCableDetect(_D1_INPUT_PORT) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		  OSD_SubMenuCur = _A0_PORT;
	  
#elif(_PCB_TYPE ==_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1 )	
/*
		if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_INPUT && SysSourceGetCableDetect(InputSourceConvert(OSD_SubMenuCur)) == _FALSE && (SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP))
		{
			while(count--)
			{
				if (GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
				{
					if (OSD_SubMenuCur == 0) 
					{
						OSD_SubMenuCur = (OsdHotPageSize[_OSD_HOTKEY_INPUT - _OSD_HOTKEY_VIEWMODE] -1);
					}
					else
					{
						OSD_SubMenuCur--;
					}


				}
				else if(GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)
				{
					if (OSD_SubMenuCur == OsdHotPageSize[_OSD_HOTKEY_INPUT - _OSD_HOTKEY_VIEWMODE]) 
					{
						OSD_SubMenuCur = 0;
					}
					else
					{
						OSD_SubMenuCur++;
					}


				}

				if(SysSourceGetCableDetect(InputSourceConvert(OSD_SubMenuCur)))
					break;
			}

		}
		*/
#endif
//OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_0) 

  	DebugMessageOsd("1.OSD_SubMenuCur",OSD_SubMenuCur);
  	DebugMessageOsd("1.OSD_HOT_KEY_PAGE",OSD_HOT_KEY_PAGE);

    if (OSD_HOT_KEY_PAGE != _OSD_HOTKEY_CONBRI && OSD_HOT_KEY_PAGE != _OSD_START_UP )
    {

		if(0);
#if(ENABLE_LANGUAGE_SELECT_OSD)			
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_LANGUAGE_SELECT )
		{
			//Color = GET_OSD_LANGUAGE()==OSD_SubMenuCur  ? _CP_WHITE : _CP_YELLOW;
			OsdWindowDrawingHighlight(_HOT_KEY_SELECT_WIN, PIXELCOL(0), 					PIXELROW(3+OSD_SubMenuCur*2)-9, 
															PIXELCOL(_HOTKEY_FRAME_WIDTH),	PIXELROW(3+OSD_SubMenuCur*2+2)-9,
										_CP_BLUE, _CP_WHITE, _CP_BG);

		}
#endif
#if(_DEF_District_swtich_Message == _ON)
		else if(OSD_HOT_KEY_PAGE==_OSD_HOTKEY_DISTRICT_SELECT )
		{
			//Color = _DEF_REGION_InitData==OSD_SubMenuCur ? _CP_WHITE : _CP_YELLOW;
			OsdWindowDrawingHighlight(_HOT_KEY_SELECT_WIN, PIXELCOL(0), 					PIXELROW(3+OSD_SubMenuCur*2)-9, 
															PIXELCOL(_HOTKEY_FRAME_WIDTH),	PIXELROW(3+OSD_SubMenuCur*2+2)-9,
										_CP_BLUE, _CP_WHITE, _CP_BG);

		}
#endif
		else
		{
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
		    OsdWindowDrawingHighlight(_HOT_KEY_SELECT_WIN, PIXELCOL(0), 		PIXELROW(_ROW_HOTKEY_TEXT_START(OSD_SubMenuCur))-9, 
							 			PIXELCOL(_HOTKEY_FRAME_WIDTH), PIXELROW(_ROW_HOTKEY_TEXT_START(OSD_SubMenuCur)+2)-9,
										_CP_BLUE, _CP_WHITE, _CP_BLUE);
#else
			OsdWindowDrawing(_HOT_KEY_SELECT_WIN, PIXELCOL(0),					PIXELROW(3+OSD_SubMenuCur*2)-9, 
											 PIXELCOL(_HOTKEY_FRAME_WIDTH), PIXELROW(3+OSD_SubMenuCur*2+2)-9,
											_CP_BLUE);
#endif
		}
		
    }
    else if (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_CONBRI)
    {
    	if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST))
			OSD_SubMenuCur=1;
		else if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT))
			OSD_SubMenuCur=0;
		
        OsdWindowDrawing(_HOT_KEY_SELECT_WIN, PIXELCOL(0), 					PIXELROW(1+OSD_SubMenuCur*2), 
										 PIXELCOL(_HOTKEY_FRAME_WIDTH), PIXELROW(1+OSD_SubMenuCur*2+2),
										_CP_BLUE);
		
        OsdDisplaySliderAndNumber(_OSD_HOTKEY_CONTRAST, GetOsdValue(_OSD_HOTKEY_CONTRAST), _SLIDER_HOTKEY);
        OsdDisplaySliderAndNumber(_OSD_HOTKEY_BACKLIGHT, GetOsdValue(_OSD_HOTKEY_BACKLIGHT), _SLIDER_HOTKEY);
    }
}




//--------------------------------------------------
// Description	:
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdDispDrawMessageWindow(BYTE ucWidth, BYTE ucHeight)
{
	OsdWindowDrawing(WINNO(_MAIN_WIN_FUN_FRAME), XSTART(_MSG_WIN1_X_START), YSTART(_MSG_WIN1_Y_START), XEND(_MSG_WIN1_X_END(ucWidth)), YEND(_MSG_WIN1_Y_END(ucHeight)+2), COLOR0(_CP_DARKGRAY));

	//Draw arc font
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	OsdFontPut1BitTable(ROW(0), COL(0), 				 tiOSD_1BIT_MSG_ARC_UL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(0), COL(ucWidth-1), 		 tiOSD_1BIT_MSG_ARC_UR, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(ucHeight-1), COL(0), 		 tiOSD_1BIT_MSG_ARC_DL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(ucHeight-1), COL(ucWidth-1), tiOSD_1BIT_MSG_ARC_DR, COLOR(_CP_DARKGRAY, _CP_BG));
#else
	OsdFontPut1BitTable(ROW(0), COL(0), 				tiOSD_1BIT_MAIN_FRAME_ARC_UL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(0), COL(ucWidth-1), 		tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(ucHeight-1), COL(0),		tiOSD_1BIT_MAIN_FRAME_ARC_DL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(ucHeight-1), COL(ucWidth-1), tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(_CP_DARKGRAY, _CP_BG));
#endif

	//Draw patch font
	OsdFontPut1BitTable(ROW(0), COL(1), tiOSD_1BIT_MSG_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(ucHeight-1), COL(1), tiOSD_1BIT_MSG_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
}



//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplayResolutionNote(void)
{
	#define _TEXT_MAX_ROW_NUM 4

	BYTE ucTemp = 0;

	// Show Title
	OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_NOTICE_TITLE), 0, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());

	// Show Down Arrow
	OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

	// Draw Text
	for(ucTemp = 0; ucTemp < _TEXT_MAX_ROW_NUM; ucTemp++)
	{
		OsdPropPutStringCenter(ROW(_2ND_TOP_LINE_ROW + 1 + ucTemp), COL(0),COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_NOTICE), ucTemp,  COLOR(_CP_WHITE, _CP_BG),GET_OSD_LANGUAGE());
	}

	OsdDisplayKeyIndex(_LAYER_Timing_Tips);

	ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
}

#if (_AI_EYE_PROTECTION == _ON)
//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplayAIDistanceNote(void)
{
	#define _TEXT_MAX_ROW_NUM 4

	BYTE ucTemp = 0;

	// Show Title
	OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_AI_DISTANCE_TITLE), 0, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());

	// Show Down Arrow
	OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

	// Draw Text
	for(ucTemp = 0; ucTemp < _TEXT_MAX_ROW_NUM; ucTemp++)
	{
		OsdPropPutStringCenter(ROW(_2ND_TOP_LINE_ROW + 1 + ucTemp), COL(0),COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_AI_DISTANCE), ucTemp,  COLOR(_CP_WHITE, _CP_BG),GET_OSD_LANGUAGE());
	}

	OsdDisplayKeyIndex(_LAYER_Timing_Tips);

	ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
}

//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplayAIEyeCareNote(void)
{
	#define _TEXT_MAX_ROW_NUM 4

	BYTE ucTemp = 0;

	// Show Title
	OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_AI_EYE_CARE_TITLE), 0, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());

	// Show Down Arrow
	OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

	// Draw Text
	for(ucTemp = 0; ucTemp < _TEXT_MAX_ROW_NUM; ucTemp++)
	{
		OsdPropPutStringCenter(ROW(_2ND_TOP_LINE_ROW + 1 + ucTemp), COL(0),COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_AI_EYE_CARE), ucTemp,  COLOR(_CP_WHITE, _CP_BG),GET_OSD_LANGUAGE());
	}

	OsdDisplayKeyIndex(_LAYER_Timing_Tips);

	ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
}

//--------------------------------------------------
// Description	    :
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdDisplayAILowPowerNote(void)
{
	#define _TEXT_MAX_ROW_NUM 4

	BYTE ucTemp = 0;

	// Show Title
	OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_LOW_POWER_TITLE), 0, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());

	// Show Down Arrow
	OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

	// Draw Text
	for(ucTemp = 0; ucTemp < _TEXT_MAX_ROW_NUM; ucTemp++)
	{
		OsdPropPutStringCenter(ROW(_2ND_TOP_LINE_ROW + 1 + ucTemp), COL(0),COL(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, STRING(_OSD_STR_LOW_POWER), ucTemp,  COLOR(_CP_WHITE, _CP_BG),GET_OSD_LANGUAGE());
	}

	OsdDisplayKeyIndex(_LAYER_Timing_Tips);

	ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
}
#endif
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdDispOsdMessage(EnumOSDDispMsg enumMessage)
{
	
#if _GSYNC_TEST
    ucDsiableShowVFreqFlag = 1;
#endif
    OsdDispDisableOsd();

	PageInit();

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	
	//ScalerOsdReferenceDelay(_OSD_A, _OSD_FIRST_DELAY);
	ScalerOsd2FontFunction(_DISABLE);

#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
	if(GET_OSD_Message_Info_Eanble() == _OFF)
	{
		if(enumMessage == _OSD_DISP_INPUT_SIGNAL_MSG || ((enumMessage == _OSD_DISP_NOSUPPORT_MSG) || (enumMessage == _OSD_DISP_NOSIGNAL_MSG)|| (enumMessage == _OSD_DISP_NOCABLE_MSG)))
		{
			return;
		}
	}
#endif


	DebugMessageOsd("1.MY_enumMessage",enumMessage);

    // Background window Modify
	switch(enumMessage)
	{
		case _OSD_DISP_NOSIGNAL_MSG:
		case _OSD_DISP_NOCABLE_MSG:
		case _OSD_DISP_NOSUPPORT_MSG:
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT));
			break;

		case _OSD_DISP_LOGO_BOOTUP_STATUS_MSG:
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
			SET_OSD_STATE(_OSD_MESSAGE_MENU_BOOT_UP);
			ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
			ScalerOsd2FontFunction(_ENABLE);
			OsdFuncApplyMapOsdAB(WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(_OSD_MSG_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
								 WIDTH(_MAIN_B_OSD_WIDTH), HEIGHT(_MAIN_B_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG));

			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(_OSD_MSG_MENU_HEIGHT));
			OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
#else
			//SET_OSD_STATE(_OSD_MSG_NOTHING);
			OsdFuncApplyMap(WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(_OSD_MSG_ROW_NUM_11), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON);
#endif

			break;

		case _OSD_DISP_Timing_Notice:
			
			SET_OSD_STATE(_OSD_MESSAGE_MENU_RESOLUTION_NOTICE);
			ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
			ScalerOsd2FontFunction(_ENABLE);
			
			//OsdFuncApplyMap(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			OsdFuncApplyMapOsdAB(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
								 WIDTH(_MAIN_B_OSD_WIDTH+3), HEIGHT(_MAIN_B_OSD_HEIGHT+1), COLOR(_CP_WHITE, _CP_BG));

	
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON2);
			OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
			break;

		case _OSD_DISP_LOCK_STATUS_MSG:
		case _OSD_DISP_LOCKING_STATUS_MSG:
		case _OSD_DISP_POWER_LOCK_STATUS_MSG:
		case _OSD_DISP_POWER_LOCKING_STATUS_MSG:
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_2BIT_GLOBAL);
			break;

		case _OSD_DISP_MEMORY_RECALL_MSG:
		case _OSD_DISP_AUTO_CONFIG_MSG:
			
			OSD_MAIN_MENU_ITEM = 0;
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			break;

		case _OSD_DISP_AUTO_POWER_OFF_MSG:
			
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			break;
			
		case _OSD_DISP_AUTO_COLOR_MSG:
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			break;

		case _OSD_DISP_INPUT_SIGNAL_MSG:
#if(_DEF_OSD_GAMING == _ON)
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
#endif
			OsdFuncApplyMap(WIDTH(_OSD_MSG_INPUT_WIDTH), HEIGHT(_OSD_MSG_INPUT_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_INPUT_WIDTH), HEIGHT(_OSD_MSG_INPUT_HEIGHT));
           	break;

		case _OSD_DISP_SLEEP_MSG:
			
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT-1));
			break;
			
		case _OSD_DISP_SLEEP_MSG_ADJ:
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT-1));
			break;
#if(_AI_EYE_PROTECTION)
		case _OSD_DISP_DISTANCE_WARNING_MSG:
			SET_OSD_STATE(_OSD_MESSAGE_MENU_AI_EYE_PROTECTION);
			ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
			ScalerOsd2FontFunction(_ENABLE);
			
			//OsdFuncApplyMap(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			OsdFuncApplyMapOsdAB(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
								 WIDTH(_MAIN_B_OSD_WIDTH+3), HEIGHT(_MAIN_B_OSD_HEIGHT+1), COLOR(_CP_WHITE, _CP_BG));

	
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON2);
			OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
			break;
		case _OSD_DISP_EYE_CARE_MSG:
			SET_OSD_STATE(_OSD_MESSAGE_MENU_AI_EYE_PROTECTION);
			ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
			ScalerOsd2FontFunction(_ENABLE);
			
			//OsdFuncApplyMap(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			OsdFuncApplyMapOsdAB(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
								 WIDTH(_MAIN_B_OSD_WIDTH+3), HEIGHT(_MAIN_B_OSD_HEIGHT+1), COLOR(_CP_WHITE, _CP_BG));
		
		
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON2);
			OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
			break;
#endif
#if(_AI_LOW_POWER == _ON)
		case _OSD_DISP_LOW_POWER_MSG:
			SET_OSD_STATE(_OSD_MESSAGE_MENU_AI_LOW_POWER);
			ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
			ScalerOsd2FontFunction(_ENABLE);
			
			//OsdFuncApplyMap(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			OsdFuncApplyMapOsdAB(WIDTH(_OSD_MSG_BEST_RESOLUTION_WIDTH), HEIGHT(_OSD_MSG_BEST_RESOLUTION_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
								 WIDTH(_MAIN_B_OSD_WIDTH+3), HEIGHT(_MAIN_B_OSD_HEIGHT+1), COLOR(_CP_WHITE, _CP_BG));
		
		
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_ROW_NUM_11));
			OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON2);
			OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
			break;
#endif
		default:
			OsdFuncApplyMap(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT), COLOR(_CP_WHITE, _CP_BG));
			RTDOsdDispDrawMessageWindow(WIDTH(_OSD_MSG_MENU_WIDTH), HEIGHT(_OSD_MSG_MENU_HEIGHT));
			break;		
	}

	
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)

	// ��ת����
	switch(enumMessage)
	{
		case _OSD_DISP_LOCK_STATUS_MSG:
		case _OSD_DISP_LOCKING_STATUS_MSG:
		case _OSD_DISP_POWER_LOCK_STATUS_MSG:
		case _OSD_DISP_POWER_LOCKING_STATUS_MSG:		
		case _OSD_DISP_MEMORY_RECALL_MSG:
		case _OSD_DISP_AUTO_CONFIG_MSG:
		case _OSD_DISP_AUTO_POWER_OFF_MSG:
		case _OSD_DISP_AUTO_COLOR_MSG:
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_ROW_NUM_11), _DISABLE, 0, _ENABLE);
			break;
			
		case _OSD_DISP_Timing_Notice:					
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,HEIGHT(_OSD_MSG_ROW_NUM_11), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(_MAIN_B_OSD_HEIGHT),_OSD_FONT_LIB_ROTATION_ENABLE);
			break;
#if(_AI_EYE_PROTECTION)
		case _OSD_DISP_DISTANCE_WARNING_MSG:					
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_ROW_NUM_11), _DISABLE, 0, _ENABLE);
			break;
		case _OSD_DISP_EYE_CARE_MSG:					
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_ROW_NUM_11), _DISABLE, 0, _ENABLE);
			break;
#endif
#if(_AI_LOW_POWER == _ON)
		case _OSD_DISP_LOW_POWER_MSG:					
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_ROW_NUM_11), _DISABLE, 0, _ENABLE);
			break;
#endif			
		case _OSD_DISP_LOGO_BOOTUP_STATUS_MSG:
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)		
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#else		
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_ROW_NUM_11), _DISABLE, 0, _ENABLE);
#endif
			break;

		case _OSD_DISP_INPUT_SIGNAL_MSG:
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_INPUT_HEIGHT), _DISABLE, 0, _ENABLE);
			break;

		default:
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MSG_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
			break;		

	}
	
#endif

		
	OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFontVLCLoadFont(_FONT_1BIT_MAINMENUICON);
	OsdFontVLCLoadFont(_FONT_1BIT_MESSAGEICON);


	// Load Font & Icon
	OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());


    //==== Show page item =======
    switch(enumMessage)
    {
        case _OSD_DISP_NOSIGNAL_MSG:
		case _OSD_DISP_NOCABLE_MSG:
			ScalerDDomainBackgroundSetColor(0,0,0);
			 ScalerDDomainBackgroundEnable(_ENABLE);//ʹ��ڵ�
			 Input_New_State=10;
            OsdFontPut1BitTable(ROW(_OSD_MSG_ICON_START_ROW), COL(_OSD_MSG_ICON_START_COL+1), tiOSD_1BIT_MSG_WARRING_ICON, COLOR(_CP_WHITE, _CP_DARKGRAY));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH+1), _PFONT_PAGE_1, _STRING_NO_SIGNAL, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);  
            break;


        case _OSD_DISP_NOSUPPORT_MSG:
			
            OsdFontPut1BitTable(ROW(_OSD_MSG_ICON_START_ROW), COL(_OSD_MSG_ICON_START_COL+1), tiOSD_1BIT_MSG_WARRING_ICON, COLOR(_CP_WHITE, _CP_DARKGRAY));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _STRING_NO_SUPPORT, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
            break;

        case _OSD_DISP_FAIL_SAFE_MODE_MSG:
            //OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_0, _STRING_NO_SUPPORT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
            break;

#if(_VGA_SUPPORT == _ON)

        case _OSD_DISP_AUTO_CONFIG_MSG:
			
            OsdFontPut1BitTable(ROW(_OSD_MSG_AUTO_ICON_START_ROW), COL(_OSD_MSG_AUTO_ICON_START_COL), tiOSD_1BIT_MSG_AUTOCONFIG_ICON, COLOR(_CP_WHITE, _CP_DARKGRAY));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5 + 2), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _STRING_AUTO_ADJUST, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
            break;

        case _OSD_DISP_AUTO_COLOR_MSG:
			
			OsdFontPut1BitTable(ROW(_OSD_MSG_AUTO_ICON_START_ROW + 1), COL(_OSD_MSG_ICON_START_COL + 2), tiOSD_1BIT_MSG_WBALANCE_ICON, COLOR(_CP_WHITE, _CP_DARKGRAY));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5 + 2), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _STRING_AUTO_COLOR, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
            break;

#endif

        case _OSD_DISP_INPUT_SIGNAL_MSG:
			//DebugMessageOsd("1.222",GET_OSD_LANGUAGE_HK_STATUS());
			//SET_OSD_STATE(_OSD_MSG_INPUT_SOURCE);
			Language_District_flang=1;  //2025.02.07  tx
			OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(0), WIDTH(_OSD_MSG_INPUT_WIDTH), _PFONT_PAGE_1, _STRING_INPUT_PORT_MSG_TITLE, 0, COLOR(_CP_BLUE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			// Show Down Arrow
			OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_INPUT_WIDTH / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW), COL(0), WIDTH(_OSD_MSG_INPUT_WIDTH), _PFONT_PAGE_1, _STRING_HOT_KEY_INPUT,GetOsdValue(_MENU_INPUT), COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());


			if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
            	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H_ROTATE_270, _KEY_INPUT_MENU_POSION_V_ROTATE_270);
			else
            	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H, 1);
			



#if(_DEF_ACON_AND_RESET_USER_MODE_SWTICH)
			//ѡ��������ûѡ�������,��������Ĺػ���ϵ磬����Ҫ����ѡ������(����������һ��)
			//��������ûѡ����,��������Ĺػ���ϵ磬����Ҫ����ѡ������(����������һ��)
			if((GET_OSD_DISTRICT_SWTICH_STATE() && GET_OSD_LANGUAGE_HK_STATUS() == _OFF) \
				|| (GET_OSD_DISTRICT_SWTICH_STATE() && GET_OSD_LANGUAGE_HK_STATUS()))
			{
			    //2025.02.07 tx
				SET_OSD_LANGUAGE_HK_STATUS(_ON);	//���Ա�־λ
				SET_OSD_ACTIVE_STATE_MESSAGE(_TRUE);
			}
#endif
#if(_DEF_BURNIN_CHECK)
			if((GET_OSD_HOTKEY_BURNIN() == _OFF)&& (GET_FACTORY_MODE() == _ON))
			{
			SET_FACTORY_BURNIN(_OFF);
			SET_OSD_HOTKEY_BURNIN(_OFF);
			TPVNVRamSaveFactoryDate();
		    }
#endif			
			break;

        case _OSD_DISP_POWER_SAVING_MSG:
            // title
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_POWER_SAVING);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
            // icon
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_1, _ICON_POWER_SAVING_TEXT_0);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(14), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_2, _ICON_POWER_SAVING_TEXT_1);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(14 + 6), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_3, _ICON_POWER_SAVING_TEXT_2);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(14 + 6 + 6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);
            break;
        case _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG:
            // title
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_TRUN_OFF_PANEL_UNI_TEXT0);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_1, _ICON_TRUN_OFF_PANEL_UNI_TEXT1);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(3 + 6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_2, _ICON_YES);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(18), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_3, _ICON_NO);
            //OsdFontPut1BitMainMenuIcon(ROW(2), COL(27), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);

            break;


		case _OSD_DISP_LOCK_STATUS_MSG:
		case _OSD_DISP_LOCKING_STATUS_MSG:
			
			SET_OSD_MESSAGE(enumMessage);
			SET_OSD_STATE(_OSD_MSG_NOTHING1);
			OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(0), WIDTH(_OSD_MSG_INPUT_WIDTH), _PFONT_PAGE_1, _OSD_STR_OSD_LOCK_TITLE, 0, COLOR(_CP_BLUE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			// Show Down Arrow
			OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_INPUT_WIDTH / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));


			if(enumMessage == _OSD_DISP_LOCKING_STATUS_MSG)
			{
				OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKING_STATUS, GET_OSD_LOCK_STATUS(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

				//Draw H Line font
				OsdFontPut1BitTable(ROW(_OSD_MSG_MENU_HEIGHT), COL(1), tiOSD_1BIT_MSG_H_LINE, COLOR(_CP_GRAY, _CP_DARKGRAY));

				// Show Hint
				//OsdFuncChangeColor1Bit(ROW(_OSD_MSG_HLINE_ROW + 1), COL(ucCol), WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(2), COLOR(_CP_GRAY, _CP_BG));

				OsdPropPutStringCenter(ROW(_OSD_MSG_MENU_HEIGHT+1), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKING_HINT, GET_OSD_LOCK_STATUS(), COLOR(_CP_GRAY, _CP_DARKGRAY), GET_OSD_LANGUAGE());
				OsdPropPutStringCenter(ROW(_OSD_MSG_MENU_HEIGHT+2), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKING_HINT, GET_OSD_LOCK_STATUS()+2, COLOR(_CP_GRAY, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			}
			else
			{
				OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKED_STATUS, GET_OSD_LOCK_STATUS(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			}
			
            OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			break;


		case _OSD_DISP_POWER_LOCKING_STATUS_MSG:
		case _OSD_DISP_POWER_LOCK_STATUS_MSG:
			SET_OSD_STATE(_OSD_MSG_NOTHING1);
			SET_OSD_MESSAGE(enumMessage);

			// Show Title
			OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(0), WIDTH(_OSD_MSG_INPUT_WIDTH), _PFONT_PAGE_1, _OSD_STR_POWER_LOCK_TITLE, 0, COLOR(_CP_BLUE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			// Show Down Arrow
			OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_INPUT_WIDTH / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

			if(enumMessage == _OSD_DISP_POWER_LOCKING_STATUS_MSG)
			{
				OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKING_PWKEY_STATUS, GET_OSD_PWKEY_LOCK_STATUS(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

				//Draw H Line font
				OsdFontPut1BitTable(ROW(_OSD_MSG_MENU_HEIGHT), COL(1), tiOSD_1BIT_MSG_H_LINE, COLOR(_CP_GRAY, _CP_DARKGRAY));

				// Show Hint
				//OsdFuncChangeColor1Bit(ROW(_OSD_MSG_HLINE_ROW + 1), COL(ucCol), WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(2), COLOR(_CP_GRAY, _CP_BG));

				OsdPropPutStringCenter(ROW(_OSD_MSG_MENU_HEIGHT+1), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_POWER_LOCKING_HINT, GET_OSD_PWKEY_LOCK_STATUS(), COLOR(_CP_GRAY, _CP_DARKGRAY), GET_OSD_LANGUAGE());
				OsdPropPutStringCenter(ROW(_OSD_MSG_MENU_HEIGHT+2), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_POWER_LOCKING_HINT, GET_OSD_PWKEY_LOCK_STATUS()+2, COLOR(_CP_GRAY, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			}
			else
			{   
				//SET_OSD_MESSAGE(_OSD_DISP_POWER_LOCK_STATUS_MSG);
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG);
				OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_LOCKED_PWKEY_STATUS, GET_OSD_PWKEY_LOCK_STATUS(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			}
            OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			break;
			
		case _OSD_DISP_AUTO_POWER_OFF_MSG:
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_INPUT_WIDTH), _PFONT_PAGE_1, _OSD_STR_AUTO_POWER_OFF, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
            OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			break;

			

#if(_OSD_Timing_Notice)
		case _OSD_DISP_Timing_Notice:
			
			OsdDisplayResolutionNote();
			//fDisableOsd = _FALSE;
			//OsdDispSetPosition(_OSD_POSITION_MSG_CENTER3, _OSD_POSITION_GLOBAL_A, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
			OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_MENU_POSION_H-0x02, _KEY_NAVIGATION_MENU_POSION_V-0x13);
#elif(_DEF_KEY_ROCKER)
			OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H-0x12, _KEY_NAVIGATION_POSION_V);
#endif
			break;
#endif
#if(_AI_EYE_PROTECTION)
		case _OSD_DISP_DISTANCE_WARNING_MSG:
			OsdDisplayAIDistanceNote();
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H-0x12, _KEY_NAVIGATION_POSION_V);
			break;
		case _OSD_DISP_EYE_CARE_MSG:
			OsdDisplayAIEyeCareNote();
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H-0x12, _KEY_NAVIGATION_POSION_V);
			break;
#endif

#if(_AI_LOW_POWER)
		case _OSD_DISP_LOW_POWER_MSG:
			OsdDisplayAILowPowerNote();
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H-0x12, _KEY_NAVIGATION_POSION_V);
			break;
#endif



        case _OSD_DISP_SLEEP_MSG:
			
			OsdPropPutStringCenter(ROW(_OSD_POWER_DOWN_ROW_START), COL(0),  LENGTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_0, _OSD_STR_SLEEP_TITLE, 0,COLOR(_CP_BLUE, _CP_BG),GET_OSD_LANGUAGE());
			OsdFontPut1BitTable(ROW(_OSD_POWER_DOWN_ROW_START+1),COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)),tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));
			OsdPropShowNumber(ROW(_OSD_POWER_DOWN_ROW_START+3), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), g_usPowerSavingCount-1 , (_ALIGN_LEFT| _FORCE_SHOW_NUMBER_OFF | _SHOW_2), _PFONT_PAGE_1,VSC_MAIN_FONT_COLOR1);
			SET_OSD_STATE(_MENU_NULL);
			if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
            	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H_ROTATE_270, _KEY_INPUT_MENU_POSION_V_ROTATE_270);
			else
            	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H, 1);
            break;

        case _OSD_DISP_SLEEP_MSG_ADJ:
			
			OsdPropPutStringCenter(ROW(_OSD_POWER_DOWN_ROW_START), COL(0),  LENGTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_0, _OSD_STR_SLEEP_TITLE, 0,COLOR(_CP_BLUE, _CP_BG),GET_OSD_LANGUAGE());
			OsdFontPut1BitTable(ROW(_OSD_POWER_DOWN_ROW_START+1),COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)),tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW), COL(0),  LENGTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_0, _OSD_STR_SLEEP_TIME, GET_AUTO_SLEEP_STATUS(),_COLOR_MENU_FONT,GET_OSD_LANGUAGE());
			SET_OSD_STATE(_OSD_MSG_NOTHING);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
			ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
			if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
            	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H_ROTATE_270, _KEY_INPUT_MENU_POSION_V_ROTATE_270);
			else
            	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _KEY_INPUT_MENU_POSION_H, 1);
            break;

		case _OSD_DISP_MEMORY_RECALL_MSG:
			//ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
			SET_OSD_STATE(_OSD_MSG_NOTHING);
			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW_5), COL(0), WIDTH(_OSD_MSG_MENU_WIDTH), _PFONT_PAGE_1, _OSD_STR_MEMORY_RECALL, 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
			break;

		

		case _OSD_DISP_LOGO_BOOTUP_STATUS_MSG:
			SET_OSD_STATE(_OSD_MSG_NOTHING1);
			SET_OSD_MESSAGE(enumMessage);
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
			//��������
			OsdPropPutString(ROW(2), COL(4), _PFONT_PAGE_1, STRING(_OSD_STR_LOGO_BOOTUP), 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			//��Ϣ����	 _OSD_STR_LOGO_BOOTUP_HINT�������һ������ʹ��	str_BOOT_UP_HINT_OFF
			OsdPropPutString(ROW(4), COL(4), _PFONT_PAGE_1, STRING(_OSD_STR_LOGO_BOOTUP_HINT), 0, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

			OsdPropPutString(ROW(2), COL(19), _PFONT_PAGE_2, STRING(_STRING_ON_OFF), GET_FACTORY_FORCE_LOGO_OFF(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			OsdPropPutString(ROW(4), COL(19), _PFONT_PAGE_2, STRING(_STRING_ON_OFF), GET_OSD_Message_Info_Eanble(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

			OSD_SubMenuCur = 0;
			OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR), XSTART(0), YSTART(2*18+(OSD_SubMenuCur*2)), XEND(_OSD_MSG_COL_NUM_23*12), YEND(3*18+(OSD_SubMenuCur*2)),	_CP_BLUE, _CP_WHITE, _CP_BLUE);
			OsdDisplayKeyIndex(_LAYER2);
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#else
			// Show Title
			//OsdFuncChangeColor1Bit(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(1), COLOR(_CP_BLUE, _CP_BG), _FONTFROM_0_255);
			OsdPropPutStringCenter(ROW(_MSG_TITLE_STRING_ROW), COL(_MSG_TITLE_STRING_COL), WIDTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_1, STRING(_OSD_STR_LOGO_BOOTUP), 0, COLOR(_CP_BLUE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			// Show Down Arrow
			OsdFontPut1BitTable(ROW(_MSG_TITLE_STRING_ROW + 1), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_BLUE, _CP_BG));

			OsdPropPutStringCenter(ROW(_STRING_MESSAGE_ROW), COL(0), WIDTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_1, STRING(_STRING_ON_OFF), GET_FACTORY_FORCE_LOGO_OFF(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

			//Draw H Line font
			OsdFontPut1BitTable(ROW(_OSD_MSG_HLINE_ROW), COL(1), tiOSD_1BIT_MSG_H_LINE, COLOR(_CP_GRAY, _CP_DARKGRAY));

			// Show Hint
			OsdFuncChangeColor1Bit(ROW(_OSD_MSG_HLINE_ROW + 1), COL(0), WIDTH(_OSD_MSG_COL_NUM_23), HEIGHT(1), COLOR(_CP_GRAY, _CP_BG), _FONTFROM_0_255);
			OsdPropPutStringCenter(ROW(_OSD_MSG_HLINE_ROW + 1), COL(0), WIDTH(_OSD_MSG_COL_NUM_23), _PFONT_PAGE_1, STRING(_OSD_STR_LOGO_BOOTUP_HINT), !GET_FACTORY_FORCE_LOGO_OFF(), COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
			ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);

			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
#endif
			break;


        default:
            break;
    }

	DebugMessageOsd("1.MY_GET_OSD_STATE",GET_OSD_STATE());

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispAutoConfigProc(void)
{
    OsdDispOsdMessage(_OSD_DISP_AUTO_CONFIG_MSG);
	//ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);
	//ScalerDDomainBackgroundEnable(_ENABLE);
    UserCommonAutoConfig();
    OsdDispDisableOsd();
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoBalanceProc(void)
{
	
#if _GSYNC_TEST
    ucDsiableShowVFreqFlag = 1;
#endif
    OsdDispDisableOsd();
    OsdDispOsdMessage(_OSD_DISP_AUTO_COLOR_MSG);

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            // Perform auto-color for RGB
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA))
                // Calculate YPbPr gain/offset using formula
                g_stAdcData = ScalerAutoBalanceYPbPrFromFormula(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);

                // Restore RGB gain/offset
                ScalerAutoGetAutoColorResult(&g_stAdcData);
#endif
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        else
        {
            // Perform auto-color for YPbPr
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_YPBPR) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#endif
    }

    OsdDispDisableOsd();
    // SET_KEYMESSAGE(_HOLD_KEY_MESSAGE);
}



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoBalanceProc_DDCCI(void)
{
    OsdDispDisableOsd();

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            // Perform auto-color for RGB
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)
            {

				ScalerAutoGetAutoColorResult(&g_stAdcData);
				
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA))
                // Calculate YPbPr gain/offset using formula
                g_stAdcData = ScalerAutoBalanceYPbPrFromFormula(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);

                // Restore RGB gain/offset
                ScalerAutoGetAutoColorResult(&g_stAdcData);
#endif
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        else
        {
            // Perform auto-color for YPbPr
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_YPBPR) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#endif
    }

    OsdDispDisableOsd();
    // SET_KEYMESSAGE(_HOLD_KEY_MESSAGE);
}

#endif // End of #if(_VGA_SUPPORT == _ON)


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispOsdReset(void)
{
#if(_RESET_KEEP_LANGUAGE)
    BYTE ucIndex = GET_OSD_LANGUAGE();
#endif
	BYTE ucPrePowerLock = GET_OSD_PWKEY_LOCK_STATUS();
	
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
	BYTE ucMessageInfo_i = GET_OSD_Message_Info_Eanble();
#endif
	BYTE ucLogoEanble_i = GET_FACTORY_FORCE_LOGO_OFF();
	BYTE ucResetToStatuc = _OFF;	//_DEF_VGA_TIMING_KEY_2_4
	BYTE ucResetDpVersion = GET_OSD_DP_VERSION_11_STATUS();	

	BYTE ucPreFactoryMode = GET_FACTORY_MODE();
	BYTE ucSrgb_Backlight = GET_OSD_BACKLIGHT_SRGB();
	
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWDDomainEnable(_FUNCTION_OFF);
#endif
	
    //OsdDispDisableOsd();

	//Duncan 130916 add for force to background start
	ScalerDDomainBackgroundSetColor(0, 0, 0);
	ScalerDDomainPatternGenAdjustColor(0x00, 0x00, 0x00);
	ScalerDDomainBackgroundEnable(_ENABLE);
	ScalerDDomainPatternGenEnable(_ENABLE);

#if _DEFAULT_OSD_STYLE == _TRG_OSD_STYLE
	SET_OSD_CONTRAST(_CONTRAST_DEFAULT);
	SET_OSD_BACKLIGHT(100);
	UserAdjustContrast(_CONTRAST_DEFAULT);
	UserAdjustBacklight(100);

#endif
	OsdDispOsdMessage(_OSD_DISP_MEMORY_RECALL_MSG);

	ScalerTimerDelayXms(1200);
	
#if _GSYNC_TEST
	ucDsiableShowVFreqFlag = 1;
#endif
	OsdDispDisableOsd();
	UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);


    UserCommonNVRamRestoreSystemData();
    RTDNVRamRestoreOSDData();
	SET_OSD_BACKLIGHT_SRGB(ucSrgb_Backlight);

    RTDNVRamRestoreUserColorSetting();
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
	
#if(_SIX_COLOR_SUPPORT == _ON)
    //RTDNVRamRestoreSixColorData();
#endif

	RTDNVRamRestoreViewModeParameters(); //��ԭ�龰ģʽ�ṹ��

    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();
	
#if(_DEF_VIEW_SONIC_DCR)//UserInterfaceAdjustColorProc
#if(_DCR_SUPPORT)
	UserAdjustDCRControl(GET_OSD_DCR_STATUS());
#endif	
#endif


#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        SET_VGA_MODE_DO_FIRST_AUTO(_TRUE);
        UserCommonModeSearchInitalUserAndCenterData(g_stVGAModeUserData.ucModeNumber);
        UserCommonNVRamSaveModeUserData();
    }
#endif

#if(_DP_SUPPORT == _ON)
    // Set Aux Diff mode & Resistance Setting
    SET_DP_AUX_DIFF_MODE();

    SET_DP_AUX_ADJR_SETTING(UserCommonNVRamGetSystemData(_DP_AUX_ADJR_SETTING));

    UserCommonInterfaceDpAuxSet();
#endif

#if(_DP_SUPPORT == _ON)
    //OsdDispResetDpCapabilitySwitch();
#endif

#if((_FREESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
    // Switch Free Sync Capability
    UserCommonInterfaceFreeSyncSupportSwitch();
#endif

#if((_DP_ADAPTIVESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
    // Switch Adaptive Sync Capability
    UserCommonInterfaceDpAdaptiveSyncSupportSwitch();
#endif

#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
	if(ucMessageInfo_i != GET_OSD_Message_Info_Eanble())
	{
	   SET_OSD_Message_Info_Eanble(ucMessageInfo_i);
	}
#endif
	if(ucLogoEanble_i != GET_FACTORY_FORCE_LOGO_OFF())
	{
		SET_FACTORY_FORCE_LOGO_OFF(ucLogoEanble_i);
	}

	if(ucPrePowerLock != GET_OSD_PWKEY_LOCK_STATUS())
	{
		SET_OSD_PWKEY_LOCK_STATUS(ucPrePowerLock);
	}
	 
    if(ucPreFactoryMode!= GET_FACTORY_MODE())
	{
		SET_FACTORY_MODE(ucPreFactoryMode);
	}
	
#if(_DEF_RESET_FACTORY_OFF)
	SET_FACTORY_MODE(_OFF);
	SET_FACTORY_BURNIN(_OFF);
	TPVNVRamSaveFactoryDate();
#endif


#if(_RESET_KEEP_LANGUAGE)
    if(ucIndex != GET_OSD_LANGUAGE())
    {
        SET_OSD_LANGUAGE(ucIndex);
    }
#endif

#if(_DEF_VGA_TIMING_KEY_2_4)
#if(_VGA_SUPPORT == _ON)
	if(SysSourceGetInputPort() == _A0_INPUT_PORT)
	{
		if(OsdDispModeSwitchReset() == _TRUE)
		{
			ucResetToStatuc = _ON;
		}
	}
#endif
#endif


	// ��λ���źŴ�
	Input_New_State = 10;

    OsdFuncSetOsdItemFlag();
	SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);


	
#if(_DEF_ACON_AND_RESET_USER_MODE_SWTICH)
	SET_OSD_ACTIVE_STATE_MESSAGE(_TRUE);
#endif

	UserAdjustAudioVolume(GET_OSD_VOLUME());


#if(_SIX_COLOR_SUPPORT == _ON)
	OsdFuncSixColorAdjust();
#endif

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    UserCommonInterfaceDataExchangeAllDataReset();
#endif

// ��λMPRT
#if(_MPRT_SUPPORT == _ON)
	UserAdjustMPRTFuntion(GET_OSD_MPRT());
#endif

	//_DEF_VGA_TIMING_KEY_2_4
#if(_DEF_VGA_TIMING_KEY_2_4)
#if(_VGA_SUPPORT == _ON)
	if(ucResetToStatuc == _ON)
	{
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
	}
	else
#endif
#endif



#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT || _D1_INPUT_PORT_TYPE == _D1_DP_PORT)
	if(ucResetDpVersion == _ON && (SysSourceGetInputPort() == _D0_INPUT_PORT || SysSourceGetInputPort() == _D1_INPUT_PORT))
		ScalerTimerReactiveTimerEvent(SEC(1.5), _USER_TIMER_EVENT_RESET_TO_SEARCH);
	else
#endif
	{
		//ScalerTimerReactiveTimerEvent(SEC(1.5), _USER_TIMER_EVENT_RESET_TO_DISPLAY_SETTING);
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
	}


	RTDNVRamSaveOSDData();
	RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());


	ScalerDDomainPatternGenEnable(_DISABLE);

}

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Osd Display Reset Dp Capability Switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispResetDpCapabilitySwitch(void)
{
    // Set Aux Diff mode & Resistance Setting
    SET_DP_AUX_DIFF_MODE();

    SET_DP_AUX_ADJR_SETTING(UserCommonNVRamGetSystemData(_DP_AUX_ADJR_SETTING));

    UserCommonInterfaceDpAuxSet();

    // Switch All DP Port Dp Version
    UserCommonInterfaceDPSwitchAllPortDpVersion();

#if(_EMBEDDED_EDID_SUPPORT == _ON)
    // Switch All DP Port Dp Edid
    UserCommonInterfaceDPSwitchAllPortEdid();
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    // Switch All DP Port Dp Lane Count Capability
    UserCommonInterfaceTypeCU3ModeAllPortCapabilitySwitch();
#endif

#if(_DP_MST_SUPPORT == _ON)
    // Switch DP Mst Capability
    UserCommonInterfaceMstRx0Rx1switch(UserCommonInterfaceGetDpMstCapablePort());
#endif
}
#endif

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_LOGO_TYPE == _LOGO_TYPE_THREE_BIRDS)
void OsdDispShowLogo(void)
{
    OsdFuncDisableOsd();
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
	ScalerDDomainBackgroundSetColor(0, 0, 0);
	
    ScalerDDomainPatternGenEnable(_DISABLE);
    ScalerDDomainBackgroundEnable(_ENABLE);

	
    SET_OSD_LOGO_ON(_ON);


    OsdFuncApplyMap(WIDTH(_LOGO_THREE_BIRDS_WIDTH), HEIGHT(_LOGO_THREE_BIRDS_HEIGHT), COLOR(1, 0));

		   
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	   ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,WIDTH(_LOGO_THREE_BIRDS_HEIGHT), _OSD_MAP_B_REMAPPING_DISABLE,HEIGHT(0),_OSD_FONT_LIB_ROTATION_ENABLE);
	   // OsdFuncMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _OSD_MAP_B_REMAPPING_DISABLE, 0, _OSD_FONT_LIB_ROTATION_ENABLE);
#endif

    OsdFuncSet2BitIconOffset(_LOGO_2BIT_OFFSET);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_LOGO_3NIRD);
    OsdTableFuncSetColorPalette(_PALETTE_INDEX1, _PALETTE_LOGO_3NIRD);


    OsdFontVLCLoadFont(_LOGO_THREE_BIRDS_1BIT_CHAR);
    OsdFontVLCLoadFont(_LOGO_THREE_BIRDS_1BIT);
    OsdFontVLCLoadFont(_LOGO_THREE_BIRDS_2BIT);
    OsdFontVLCLoadFont(_LOGO_THREE_BIRDS_4BIT);
	
    OsdFontPut1BitTable(ROW(12), COL(0), tiOSD_THREE_BIRDS_1BIT_CHAR,COLOR(3,0));
    // OsdFuncChangeColor1Bit(ROW(12), COL(0), WIDTH(30), HEIGHT(4), 0, 3);

    OsdTableFuncPutIcon1BitLogo(ROW(0), COL(0), tiOSD_THREE_BIRDS_1BIT);
    OsdTableFuncPutIcon2BitLogo(ROW(0), COL(0), tiOSD_THREE_BIRDS_2BIT);
    OsdTableFuncPutIcon4BitLogo(ROW(0), COL(0), tiOSD_THREE_BIRDS_4BIT);

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_0)
    {
#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
		ScalerOsdPosition(_OSD_POSITION_GLOBAL_A, _LOGO_THREE_BIRDS_X, _LOGO_THREE_BIRDS_Y);
#else
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
#endif
    }
	else if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
        OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, 0x11C, 0x21E);

    ScalerTimerWaitForEvent(_EVENT_DVS);

#if(_BACKLIGHT_PWM_INVERSE == _ON)
	UserAdjustBacklight(100);
#else
    PCB_BACKLIGHT_PWM(_BACKLIGHT_MAX_PWM);
#endif
    UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);// for show logo turn on BL first then show os
    OsdFuncEnableOsd();
}
#else
void OsdDispShowLogo(void)
{
    OsdFuncDisableOsd();
	

#if(_LOGO_TYPE == _LOGO_Suma)
	ScalerDDomainBackgroundSetColor(_LOGO_BG_RED,_LOGO_BG_GREEN,_LOGO_BG_BLUE);
	ScalerDDomainPatternGenEnable(_DISABLE);
	ScalerDDomainBackgroundEnable(_ENABLE);

#elif (_LOGO_TYPE == _LOGO_MACHENIKE_2K)
	ScalerDDomainBackgroundSetColor(_LOGO_BG_RED,_LOGO_BG_GREEN,_LOGO_BG_BLUE);
	ScalerDDomainPatternGenEnable(_DISABLE);
	ScalerDDomainBackgroundEnable(_ENABLE);
	UserAdjustBacklight(100);
	
#else
	ScalerDDomainBackgroundSetColor(_LOGO_BG_RED,_LOGO_BG_GREEN,_LOGO_BG_BLUE);
	ScalerDDomainPatternGenEnable(_DISABLE);
	ScalerDDomainBackgroundEnable(_ENABLE);
	//ScalerDDomainPatternGenAdjustColor(_LOGO_BG_RED, _LOGO_BG_GREEN, _LOGO_BG_BLUE);
	//ScalerDDomainPatternGenEnable(_ENABLE);
	//ScalerDDomainBackgroundEnable(_DISABLE);
#endif

	
    SET_OSD_LOGO_ON(_ON);

    OsdFuncApplyMap(WIDTH(_LOGO_COL_SIZE), HEIGHT(_LOGO_ROW_SIZE), COLOR(_LOGO_CP_BG, _LOGO_CP_BG));
	OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);
	OsdFontVLCLoadFont(_FONT_1BIT_LOGO);

	OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_LOGO0, COLOR(_LOGO_FG_COLOR, _LOGO_BG_COLOR));


    //if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_0)
    {
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
    }

    ScalerTimerWaitForEvent(_EVENT_DVS);

    //UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);// for show logo turn on BL first then show os
    OsdFuncEnableOsd();
}
#endif
//--------------------------------------------------
// Description  : OSD information function
// Input Value  : None
// Output Value : None
//--------------------------------------------------








BYTE code OsdHotViewMode[] =
{

    _OSD_HOTKEY_STANDATD,
    _OSD_HOTKEY_FRS,
#if(_DEF_VIEWMODE_RTS == _ON)
    _OSD_HOTKEY_RTS,
#endif
#if(_DEF_VIEWMODE_MOBA == _ON)
    _OSD_HOTKEY_MOBA,
#endif
    _OSD_HOTKEY_MOVIE,
    _OSD_HOTKEY_WED,
    _OSD_HOTKEY_TEXT,
#if(_DEF_VIEWMODE_MAC == _ON)
    _OSD_HOTKEY_MAC,
#endif
    _OSD_HOTKEY_MONO,
    
};
BYTE code OsdHotVolume[] =
{
    _MENU_FUN_VOLUME,
};

BYTE code OsdHotConbri[] =
{
    _OSD_HOTKEY_CONTRAST,
    _OSD_HOTKEY_BACKLIGHT,
};
BYTE code OsdHotInput[] =
{
#if(_PCB_TYPE == _RL6851__76PIN__HKMRT2313BRE01__1A1H__LVDS||_PCB_TYPE==_RL6463__128PIN__HKMRT2513E05__1A1H__LVDS || _PCB_TYPE == _RL6463__76PIN__HKMRT2313E01__1A1H__LVDS)
    _MENU_FUN_INPUT_0,
    // _MENU_FUN_INPUT_1,
    _MENU_FUN_INPUT_2,
#elif(_PCB_TYPE == _RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)	
	_MENU_FUN_INPUT_0,
	_MENU_FUN_INPUT_1,
	_MENU_FUN_INPUT_2,
#else
	_MENU_FUN_INPUT_0,
	_MENU_FUN_INPUT_1,
	_MENU_FUN_INPUT_2,
#endif
};

BYTE code OsdHotLanguageSelect[] = 
{

#if(_DEF_ENGLISH_TEXT)
	_ENGLISH,
#endif
#if(_DEF_FRANCAIS_TEXT)
	_FRENCH,
#endif
#if(_DEF_DEUTSCH_TEXT)
	_GERMAN,
#endif
#if(_DEF_DUTH_TEXT)
	_DUTH,
#endif
#if(_DEF_ESPANOL_TEXT)
	_SPANISH,
#endif
#if(_DEF_ITALIANO_TEXT)
	_ITALIAN,
#endif
#if(_DEF_SUOMI_TEXT)
	_FINNISH,
#endif
#if(_DEF_SWEDEN_TEXT)
	_SWEDEN,
#endif
#if(_DEF_RUSSIA_TEXT)
	_RUSSIA,
#endif
#if(_DEF_TURKISH_TEXT)
	_TURKISH,	
#endif
#if(_DEF_POLISH_TEXT)
	_POLISH,	
#endif
#if(_DEF_CZECH_TEXT)
	_CZECH, 			   
#endif
#if(_DEF_ROMANIAN_TEXT)
    _ROMANIAN,
#endif
#if(_DEF_THAI_TEXT)
    _THAI,
#endif
#if(_DEF_Vietnam_TEXT)
	_Vietnam,	//????��?
#endif
#if(_DEF_INDONESIAN_TEXT)
    _INDONESIAN,
#endif
#if(_DEF_JAPANESE_TEXT)
	_JAPANESE,
#endif
#if(_DEF_KOREAN_TEXT)
	_KOREAN,
#endif
#if(_DEF_TCHINESE_TEXT)
	_CHINESE_T,
#endif
#if(_DEF_SCHINESE_TEXT)
	_CHINESE_S,
#endif




};

BYTE code OsdHotDistrictSelect[] = // ???????
{
    _DEF_REGION_AFRICA,
    _DEF_REGION_AMERICAS,
    _DEF_REGION_ASIA,
    _DEF_REGION_EUROPE,
#if(_DEF_ZhongDong)
	_DEF_REGION_MIDDLE_EAST,// ------- �ж�
#endif
	_DEF_REGION_OCEANIA,
	_DEF_REGION_OTHER,

};

BYTE code OsdHotState[] =
{
    _OSD_HOTKEY_VIEWMODE,
#if(_MENU_AUDIO_SUPPORT)
    _OSD_HOTKEY_VOLUME,
#endif
    _OSD_HOTKEY_CONBRI,
    _OSD_HOTKEY_INPUT,
    _OSD_HOTKEY_LANGUAGE_SELECT,
    _OSD_HOTKEY_DISTRICT_SELECT,
};


BYTE code *OsdHotKeyItem[]=
{
    OsdHotViewMode,
#if(_MENU_AUDIO_SUPPORT)
    OsdHotVolume,
#endif
    OsdHotConbri,
    OsdHotInput,
    OsdHotLanguageSelect,
    OsdHotDistrictSelect,
};

BYTE code OsdHotPageSize[] =
{
    sizeof(OsdHotViewMode),
#if(_MENU_AUDIO_SUPPORT)
    sizeof(OsdHotVolume),
#endif
    sizeof(OsdHotConbri),
    sizeof(OsdHotInput),
    sizeof(OsdHotLanguageSelect),
    sizeof(OsdHotDistrictSelect),
    5,
};



#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
void OsdDisplayPowerConsumptionHint(void)
{
	BYTE ucTemp = 0;
	
#if _GSYNC_TEST
	ucDsiableShowVFreqFlag = 1;
#endif
	OsdDispDisableOsd();

	SET_OSD_STATE(_OSD_HOTKEY_FUNC);
	OSD_HOT_KEY_PAGE = _OSD_HOTKEY_POWER_CONSUMPTION_HINT;
	
	ScalerTimerDelayXms(20); //��ʱ�ȴ�һ������ѡ�������

	ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
	ScalerOsd2FontFunction(_ENABLE);
	OsdFuncApplyMapOsdAB(WIDTH(_PC_HINT_OSD_WIDTH), HEIGHT(_PC_HINT_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
						 WIDTH(_MAIN_B_OSD_WIDTH+2), HEIGHT(_MAIN_B_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,HEIGHT(_PC_HINT_OSD_HEIGHT), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(_MAIN_B_OSD_HEIGHT),_OSD_FONT_LIB_ROTATION_ENABLE);
#endif	
	
	// set 2bit Font offest
	OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFontVLCLoadFont(_FONT_1BIT_MAINMENUICON);
	OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);

	// Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
	
	OsdWindowDrawing(WINNO(_MAIN_WIN_FUN_FRAME), XSTART(_MSG_WIN1_X_START), YSTART(_MSG_WIN1_Y_START), XEND(_MSG_WIN1_X_END(_PC_HINT_OSD_WIDTH)), YEND(_MSG_WIN1_Y_END(_PC_HINT_OSD_HEIGHT)+2), COLOR0(_CP_DARKGRAY));

	//Draw arc font
	OsdFontPut1BitTable(ROW(0), COL(0), 										tiOSD_1BIT_MAIN_FRAME_ARC_UL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(0), COL(_PC_HINT_OSD_WIDTH-1), 						tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(_PC_HINT_OSD_HEIGHT-1), COL(0), 					tiOSD_1BIT_MAIN_FRAME_ARC_DL, COLOR(_CP_DARKGRAY, _CP_BG));
	OsdFontPut1BitTable(ROW(_PC_HINT_OSD_HEIGHT-1), COL(_PC_HINT_OSD_WIDTH-1), 	tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(_CP_DARKGRAY, _CP_BG));

	//Draw patch font
	OsdFontPut1BitTable(ROW(0), COL(1), 					tiOSD_1BIT_MSG_POWER_CONSUMPTION_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(ROW(_PC_HINT_OSD_HEIGHT-1), COL(1), tiOSD_1BIT_MSG_POWER_CONSUMPTION_PATCH, COLOR(_CP_WHITE, _CP_DARKGRAY));

	for(ucTemp = 0; ucTemp < 5; ucTemp++)
	{
		OsdPropPutStringCenter(ROW(3+ucTemp), COL(0), WIDTH(_PC_HINT_OSD_WIDTH), _PFONT_PAGE_0 , _STRING_POWER_CONSUMPTION_HINT, ucTemp, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
	}
	
	OsdDisplayKeyIndex(_LAYER_POWER_CONSUMPTION);
	
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, _OSD_H_POS_CENTER, _OSD_V_POS_CENTER);
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H+2, _KEY_NAVIGATION_POSION_V);
#elif(_DEF_KEY_ROCKER)
	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_POWER_CONSUMPTION_HINT_POSION_H, _KEY_POWER_CONSUMPTION_HINT_POSION_V);
#endif
	
	OsdFuncEnableOsd();
}
#endif

#if(_DEF_OSD_CURSOR_FLICKER_TIPS == _ON)
void OsdDisplayCursorFlickerTipFun(void)
{
	static bit OsdCursorFlicker_Eanble = _TRUE;	//Ĭ�Ϲ�괦�ڳ���״̬
	//OsdCursorFlicker_Eanble
	//_TRUE			��
	//_FALSE		��
	
	WORD ucOsdState_CurFlick_i = GET_OSD_STATE(); 
		

	if(OsdCursorFlicker_Eanble && g_OsdCursorFlickerTips_Num == 0x60)	//0x60	----- �а������� �ָ�����Է�����
	{				
		if(GET_OSD_STATE() == _OSD_HOTKEY_FUNC)
		{
			if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_LANGUAGE_SELECT || OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT)
			{
				ScalerOsdWindowHighlightFunction(_ENABLE, _HOT_KEY_SELECT_WIN, _CP_WHITE, _CP_BG, _CP_BG);
			}
		}
		else
		{
			ScalerOsdWindowHighlightFunction(_ENABLE, _MAIN_WIN_2ND_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
			ScalerOsdWindowHighlightFunction(_ENABLE, _MAIN_WIN_3RD_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
			ScalerOsdWindowHighlightFunction(_ENABLE, _MAIN_WIN_4TH_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
		}

		//��괦�ڳ���״̬ ����ָ�
		return;
	}
	//DebugMessageOsd("1.GET_OSD_STATE",GET_OSD_STATE());
	// ��˸��ʱ��Ӧ���ǻ�ɫ����
	//ScalerSetBit(0x3A51, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);
	//ScalerSetBit(0x3A53, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);
	//ScalerSetBit(0x3A55, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);

	if(GET_OSD_STATE() == _OSD_HOTKEY_FUNC) // ��ݼ�
	{
	
#if(!_DEF_HOTKEY_OPTION_FLICKER_TIPS)
		if(!(OSD_HOT_KEY_PAGE >= _OSD_HOTKEY_VIEWMODE && OSD_HOT_KEY_PAGE <= _OSD_HOTKEY_INPUT))
#endif	
		{
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if( OSD_HOT_KEY_PAGE != _OSD_HOTKEY_POWER_CONSUMPTION_HINT )
#endif
			{
			
				ScalerOsdWindowHighlightFunction(_DISABLE, _HOT_KEY_SELECT_WIN, _CP_WHITE, _CP_BG, _CP_BG);
				if(OsdCursorFlicker_Eanble) //��ʧ
				{
					ScalerOsdWindowOnOFF(_HOT_KEY_SELECT_WIN, _OFF);
				}
				else
				{
					ScalerOsdWindowOnOFF(_HOT_KEY_SELECT_WIN, _ON); //�����ʾ
				}


			}

		}
	}
	else if(GET_OSD_STATE() >= _OSD_MAIN_START && GET_OSD_STATE() <= _OSD_MAIN_END)	//1���˵�
	{
		if(OsdCursorFlicker_Eanble) //��ʧ
		{
			OsdDisplayMainCursor(_RECALL_OFF);

		}
		else
		{
			OsdDisplayMainCursor(_RECALL_ON);	//һ���˵������ʾ	
		}
	}
	else if(GET_OSD_STATE() >= _OSD_SUB_START && GET_OSD_STATE() <= _OSD_SUB_END)	//2���˵�
	{
		ScalerOsdWindowHighlightFunction(_DISABLE, _MAIN_WIN_2ND_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
		
		// _OSD_WINDOW_4_8 - ��˸��ʱ��Ӧ���ǻ�ɫ������ǰ����ǰ��ɫ����ɫ
		//ScalerSetBit(0x3A55, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);
		//DebugMessageOsd("1.222",ScalerGetByte(0x3A55));
		if(OsdCursorFlicker_Eanble) //��ʧ
		{
			ScalerOsdWindowOnOFF(_MAIN_WIN_2ND_CURSOR, _OFF);
		}
		else
		{    
		
			//OsdWindowDrawing(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(OSD_SubMenuCur)), _CP_BLUE);
            //OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(OSD_SubMenuCur)), _CP_BLUE, _CP_YELLOW, _CP_BG);

			ScalerOsdWindowOnOFF(_MAIN_WIN_2ND_CURSOR, _ON); //���ǰ��ɫ��Ĭ����֮ǰ����ɫ��֮ǰ�ǰ�ɫ���ͻ���ֻ�-�׽�����
		}
	}
	else if(GET_OSD_STATE() >= _OSD_FUN_START && GET_OSD_STATE() <= _MENU_FUN_RECALL)	//3���˵�
	{

		ScalerOsdWindowHighlightFunction(_DISABLE, _MAIN_WIN_3RD_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
		
		// _OSD_WINDOW_4_7 - ��˸��ʱ��Ӧ���ǻ�ɫ������ǰ����ǰ��ɫ����ɫ
		//ScalerSetBit(0x3A53, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);
		if(OsdCursorFlicker_Eanble) //��ʧ
		{
			if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
			{
#if(_5KEY_MENU_STYLE)

			   if(GET_OSD_STATE()==_MENU_FUN_VGA_HPOSITON||GET_OSD_STATE()==_MENU_FUN_VGA_VPOSITON)
			   	{
                    OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE4_FLASH_OFF);
					ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _OFF);
			   	}
			   else
#endif			   	
			   	{
				OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE3_FLASH_OFF);
				//OsdDisplaySubSlider(ROW(_ROW_1ST_TEXT_START), COL(_SLIDER_PAGE3_COL), g_usAdjustValue, _SLIDER_MAX, _SLIDER_MIN, _SLIDER_BAR_LENGTH, _OSD_NORMAL_TYPE);
				ScalerOsdWindowOnOFF(_MAIN_WIN_3RD_CURSOR, _OFF);
			   	}
			}
			else
			{
				ScalerOsdWindowOnOFF(_MAIN_WIN_3RD_CURSOR, _OFF);
			}
		}
		else
		{
			if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
			{
#if(_5KEY_MENU_STYLE)   //2025.2.13
			   if(GET_OSD_STATE()==_MENU_FUN_VGA_HPOSITON||GET_OSD_STATE()==_MENU_FUN_VGA_VPOSITON)
			   	{
				   OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE4_FLASH_ON);
				   ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _ON);

			   	}
			   else
#endif			   	
			   	{
				OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE3_FLASH_ON);
				//OsdDisplaySubSlider(ROW(_ROW_1ST_TEXT_START), COL(_SLIDER_PAGE3_COL), g_usAdjustValue, _SLIDER_MAX, _SLIDER_MIN, _SLIDER_BAR_LENGTH, _OSD_ADJUST_TYPE);
				ScalerOsdWindowOnOFF(_MAIN_WIN_3RD_CURSOR, _ON);
			   	}
			}
			else
			{
				ScalerOsdWindowOnOFF(_MAIN_WIN_3RD_CURSOR, _ON);
			}			
		}
	}
	else if(GET_OSD_STATE() >= _MENU_FUN_CONTRAST && GET_OSD_STATE() < _MENU_NULL)	//4���˵�����
	{
		ScalerOsdWindowHighlightFunction(_DISABLE, _MAIN_WIN_4TH_CURSOR, _CP_WHITE, _CP_BG, _CP_BG);
		
		// _OSD_WINDOW_4_6 - ��˸��ʱ��Ӧ���ǻ�ɫ������ǰ����ǰ��ɫ����ɫ
		//ScalerSetBit(0x3A51, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _CP_YELLOW);
		if(OsdCursorFlicker_Eanble) //��ʧ
		{
			if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
			{
				if((GET_OSD_STATE() == _MENU_FUN_HUE_ADJUST)
					||(GET_OSD_STATE() == _MENU_FUN_SATURATION_ADJUST)
					||(GET_OSD_STATE() == _MENU_FUN_USER_COLOR_ADJUST)
				)
				{
					//OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE5_FLASH_OFF);
					ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _OFF);
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) 
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(2)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(2)),_CP_BLACK, _CP_WHITE, _CP_BG);// lj 20250228  
#endif
				}
				else
				{
					//OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE4_FLASH_OFF);
					ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _OFF);
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) 
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(2)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(2)),_CP_BLACK, _CP_WHITE, _CP_BG);// lj 20250228 
#endif

				}
			}
			else
			{
				ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _OFF);
			}		
		}
		else
		{
			if(GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
			{
				if((GET_OSD_STATE() == _MENU_FUN_HUE_ADJUST)
					||(GET_OSD_STATE() == _MENU_FUN_SATURATION_ADJUST)
					||(GET_OSD_STATE() == _MENU_FUN_USER_COLOR_ADJUST)
				)
				{
					OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE5_FLASH_ON);
					ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _ON);
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) ||(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) 
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(2)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(2)),_CP_BLUE, _CP_WHITE, _CP_BG);// lj 20250228 
#endif
				}
				else
				{
					OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()), _SLIDER_PAGE4_FLASH_ON);
					ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _ON);
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) 
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(2)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(2)),_CP_BLUE, _CP_WHITE, _CP_BG);// lj 20250228 
#endif

				}
			}
			else
			{
				ScalerOsdWindowOnOFF(_MAIN_WIN_4TH_CURSOR, _ON);
			}
		}
	}
	


	if(OsdCursorFlicker_Eanble)
	{
		OsdCursorFlicker_Eanble = _FALSE;
	}
	else
	{
		OsdCursorFlicker_Eanble = _TRUE;
	}

}

#endif

#if(_DEF_NO_CHECK_LANGUAGE_DISTRICT_MODE_SWTICH)
void OsdDisplayActiveStateCheck(void)
{

    if(GET_OSD_STATE() != _MENU_NONE)
    {
        return;
   	}

	if(GET_OSD_ACTIVE_STATE_MESSAGE() == _TRUE&&Language_District_flang==0)  //2025.02.07 tx
	{

			
#if(_DEF_ACON_AND_RESET_USER_MODE_SWTICH)
		if(GET_OSD_STATE() != _OSD_MSG_INPUT_SOURCE \
			&& !(GET_OSD_EVENT_MESSAGE()==_OSDEVENT_ACTIVE_DO_ONE_TIME_MSG)\
            && GET_FACTORY_MODE() == _OFF)	//�ȵ�������
		{
			if(GET_OSD_LANGUAGE_HK_STATUS() == _ON)
			{
				//SET_OSD_STATE(_OSD_HOTKEY_LANGUAGE_SELECT);
				OsdDispHotKeySourceMenu(_OSD_HOTKEY_LANGUAGE_SELECT);
				ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
			}
#if(_DEF_District_swtich_Message)	//����ѡ��
			else if(GET_OSD_STATE() != _OSD_HOTKEY_LANGUAGE_SELECT && GET_OSD_DISTRICT_SWTICH_STATE())
			{
				//���������ѡ��� ����ʾ����ѡ���
				//OsdDisplayDisableOsd();
				//ScalerTimerDelayXms(200);

				OsdDispHotKeySourceMenu(_OSD_HOTKEY_DISTRICT_SELECT); // ����ѡ��
				ScalerTimerActiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);
			}
#endif
			// Because only do one time so must clear
			SET_OSD_ACTIVE_STATE_MESSAGE(_FALSE);
		}
#endif

	}

}
#endif



#if(_DEF_VGA_TIMING_KEY_2_4)

//--------------------------------------------------
// Description	:
// Input Value	: None
// Output Value : None
//--------------------------------------------------
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
void OsdDispModeSwitch(void)
{
	BYTE modechange=0;

    if(((g_stVGAModeUserData.ucModeNumber == _MODE_720x400_70HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_640x400_70HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_640x350_70HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
#if 1 // EasonLee 20140116 for VSC SPEC timing item4
        if(abs(GET_INPUT_TIMING_HFREQ() - 303) < 2)
        {
            ; // no thing
        }
        else
#endif
        {
            if(GET_Mode400at70_Switch() == _M_720x400_70)
        {
            SET_Mode400at70_Switch(_M_640x350_70);
        }
            else if(GET_Mode400at70_Switch() == _M_640x350_70)
        {
            SET_Mode400at70_Switch(_M_640x400_70);
        }
            else
        {
            SET_Mode400at70_Switch(_M_720x400_70);
        }
            modechange = 1;
        }
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_720x480_60HZ)||(g_stVGAModeUserData.ucModeNumber ==_MODE_640x400_60HZ)
           ||(g_stVGAModeUserData.ucModeNumber ==_MODE_640x480_60HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_720x480_60HZ_GTF)
           ||(g_stVGAModeUserData.ucModeNumber == _MODE_720x480p_60HZ)) && (GET_OSD_STATE()== _MENU_NONE))//Lynn 20121008 640x480 toggle function
    {
        if(GET_Mode480at60_Switch() == _M_640x400_60)
        {
            SET_Mode480at60_Switch(_M_720x480_60);
        }
        else if(GET_Mode480at60_Switch() == _M_720x480_60)
        {
            SET_Mode480at60_Switch(_M_640x480_60);
        }
        else
        {
            SET_Mode480at60_Switch(_M_640x400_60);
        }
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_1024x768_50HZ)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1280x768_50HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode768at50_Switch(!GET_Mode768at50_Switch());
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_1024x768_75HZ_MAC)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1024x768_75HZ)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1280x768_75HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode768at75_Switch(!GET_Mode768at75_Switch());
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_1360x768_60HZ)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1280x768_60HZ)||(g_stVGAModeUserData.ucModeNumber==_MODE_1366x768_60HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        if(GET_Mode768at60_Switch() == _M_1360x768_60)
        {
            SET_Mode768at60_Switch(_M_1366x768_60);
        }
        else if(GET_Mode768at60_Switch() == _M_1366x768_60)
        {
            SET_Mode768at60_Switch(_M_1280x768_60);
        }
        else
        {
            SET_Mode768at60_Switch(_M_1360x768_60);
        }
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber == _MODE_1280x960_60HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_1600x900_60HZ_RB)) && (GET_OSD_STATE()== _MENU_NONE))
    {	
        SET_Mode960at60_Switch(!GET_Mode960at60_Switch());
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_1600x900_60HZ)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1440x900_60HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode900at60_Switch(!GET_Mode900at60_Switch());
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber ==_MODE_1600x900_60HZ_CVR)||(g_stVGAModeUserData.ucModeNumber ==_MODE_1440x900_60HZ_RB)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode900RBat60_Switch(!GET_Mode900RBat60_Switch());
        modechange = 1;
    }

    else if(((g_stVGAModeUserData.ucModeNumber == _MODE_1400x1050_60HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_1680x1050_60HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode1050at60_Switch(!GET_Mode1050at60_Switch());
        modechange = 1;
    }
    else if(((g_stVGAModeUserData.ucModeNumber == _MODE_1400x1050_60HZ_RB)||(g_stVGAModeUserData.ucModeNumber == _MODE_1680x1050_60HZ_RB)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode1050RBat60_Switch(!GET_Mode1050RBat60_Switch());
        modechange = 1;
    }
#if(_PROJECT_ID !=_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) && (_PROJECT_ID !=_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
    else if(((g_stVGAModeUserData.ucModeNumber == _MODE_1440x900_75HZ)||(g_stVGAModeUserData.ucModeNumber == _MODE_1152x870_75HZ)) && (GET_OSD_STATE()== _MENU_NONE))
    {
        SET_Mode900at75_Switch(!GET_Mode900at75_Switch());
        modechange = 1;
    }
#endif
	else
	{
		return;
	}

	ScalerDDomainPatternGenAdjustColor(0, 0, 0);//�ر���Ĺ������������ƻ���һЩ���߰���Ļ���
	ScalerDDomainBackgroundSetColor(0, 0, 0);
	ScalerDDomainBackgroundEnable(_ENABLE);

    if(modechange)
    {
        RTDNVRamSaveOSDData();
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
    }
}


//--------------------------------------------------
// Description	: for Recall function used
// Input Value	: None
// Output Value : None
//--------------------------------------------------
bit OsdDispModeSwitchReset(void)
{
	BYTE modechange=0;

    switch(g_stVGAModeUserData.ucModeNumber)
    {
///////
        case _MODE_720x400_70HZ:
            if(GET_Mode400at70_Switch() != _M_720x400_70)
            {
                modechange = 1;
            }
            break;

        case _MODE_640x350_70HZ:
            if(GET_Mode400at70_Switch() != _M_640x350_70)
            {
                modechange = 1;
            }
            break;

        case _MODE_640x400_70HZ:
            if(GET_Mode400at70_Switch() != _M_640x400_70)
            {
                modechange = 1;
            }
            break;
///////
        case _MODE_720x480_60HZ:
            if(GET_Mode480at60_Switch() != _M_720x480_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_640x400_60HZ:
            if(GET_Mode480at60_Switch() != _M_640x400_70)
            {
                modechange = 1;
            }
            break;
        case _MODE_640x480_60HZ:
            if(GET_Mode480at60_Switch() != _M_640x480_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_720x480_60HZ_GTF:
            if(GET_Mode480at60_Switch() != _M_720x480_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_720x480p_60HZ:
            if(GET_Mode480at60_Switch() != _M_720x480_60)
            {
                modechange = 1;
            }
            break;

///////////
        case _MODE_1024x768_50HZ:
            if(GET_Mode768at50_Switch() != _M_1024x768_50)
            {
                modechange = 1;
            }
            break;
        case _MODE_1280x768_50HZ:
            if(GET_Mode768at50_Switch() != _MODE_1280x768_50HZ)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1024x768_75HZ_MAC:
            if(GET_Mode768at75_Switch() != _M_1024x768_75)
            {
                modechange = 1;
            }
            break;
        case _MODE_1024x768_75HZ:
            if(GET_Mode768at75_Switch() != _M_1024x768_75)
            {
                modechange = 1;
            }
            break;
        case _MODE_1280x768_75HZ:
            if(GET_Mode768at50_Switch() != _M_1280x768_75)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1360x768_60HZ:
            if(GET_Mode768at60_Switch() != _M_1360x768_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_1280x768_60HZ:
            if(GET_Mode768at60_Switch() != _M_1280x768_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_1366x768_60HZ:
            if(GET_Mode768at60_Switch() != _M_1366x768_60)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1280x960_60HZ:
            if(GET_Mode960at60_Switch() != _M_1280x960_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_1600x900_60HZ_RB:
            if(GET_Mode960at60_Switch() != _M_1600x900_60_RB)
            {
                modechange = 1;
            }
            break;

//////////
        case _MODE_1600x900_60HZ:
            if(GET_Mode900at60_Switch() != _M_1600x900_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_1440x900_60HZ:
            if(GET_Mode900at60_Switch() != _M_1440x900_60)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1600x900_60HZ_CVR:
            if(GET_Mode900RBat60_Switch() != _M_1600x900_60_CVR)
            {
                modechange = 1;
            }
            break;
        case _MODE_1440x900_60HZ_RB:
            if(GET_Mode900RBat60_Switch() != _M_1440x900_60_RB)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1400x1050_60HZ:
            if(GET_Mode1050at60_Switch() != _M_1400x1050_60)
            {
                modechange = 1;
            }
            break;
        case _MODE_1680x1050_60HZ:
            if(GET_Mode1050at60_Switch() != _M_1680x1050_60)
            {
                modechange = 1;
            }
            break;

//////////
        case _MODE_1400x1050_60HZ_RB:
            if(GET_Mode1050RBat60_Switch() != _M_1400x1050_60_RB)
            {
                modechange = 1;
            }
            break;
        case _MODE_1680x1050_60HZ_RB:
            if(GET_Mode1050RBat60_Switch() != _M_1680x1050_60_RB)
            {
                modechange = 1;
            }
            break;
//////////
        case _MODE_1440x900_75HZ:
            if(GET_Mode900at75_Switch() != _M_1440x900_75)
            {
                modechange = 1;
            }
            break;
        case _MODE_1152x870_75HZ:
            if(GET_Mode900at75_Switch() != _M_1152x870_75)
            {
                modechange = 1;
            }
            break;



        default:
            break;
    }
//////////

    return modechange;

}


#endif



#endif


#if(_DEF_NAVIGATION_OSD_ENABLE)

//--------------------------------------------------
// Description  : ҡ�˰��������˵�ҳ
// Input Value  :
// Output Value :
//--------------------------------------------------
/*
WORD SetCurrentMenuWidthHeightpos(BYTE currentOsdState,BYTE Offset,BYTE WH_select,BYTE PercentDirectSlect)
{
	 BYTE currentOsdWidth;
	 BYTE currentOsdHeight;
	 DWORD targetOsdStart = 0;
	 WORD lineOffset = WH_select?12:18;

	 BYTE HeightAmount = OsdHotPageSize[currentOsdState - _OSD_HOTKEY_VIEWMODE];

     DebugMessageOsd("HeightAmount ",HeightAmount);
	 	
	 if(currentOsdState == _MENU_NAVIGAT)
	 {
		currentOsdWidth = _NAVIGAT_FRAME_WIDTH;
		currentOsdHeight = _NAVIGAT_FRAME_HEIGHT-4;
	 }
	 else if(currentOsdState == _OSD_HOTKEY_CONBRI ||currentOsdState == _OSD_HOTKEY_VOLUME )
	 {
		currentOsdWidth = _HOTKEY_FRAME_WIDTH;
		currentOsdHeight = (HeightAmount * 2 +3);
	 }
	 else if(currentOsdState == _OSD_HOTKEY_VIEWMODE)
	 {
		currentOsdWidth = _HOTKEY_FRAME_WIDTH;
		currentOsdHeight = (HeightAmount * 2-3);
	 }
	 else if(currentOsdState == _OSD_HOTKEY_INPUT)
	 {
		currentOsdWidth = _HOTKEY_FRAME_WIDTH;
		currentOsdHeight = (HeightAmount * 2 + 3);
	 }	 
	 else if(currentOsdState == _OSD_HOTKEY_LANGUAGE_SELECT || currentOsdState == _OSD_HOTKEY_DISTRICT_SELECT)
	 {
		currentOsdWidth = _HOTKEY_FRAME_WIDTH;
		currentOsdHeight = (HeightAmount * 2 + 2 + 2);
	 }
	 else
	 {
		currentOsdWidth = _HOTKEY_FRAME_WIDTH;
		currentOsdHeight = ((HeightAmount) * 2 + 2 + 6);
	 }

	 if(PercentDirectSlect == _POS_PERCENT)
	 {
		if(WH_select)
		{
			targetOsdStart = (_PANEL_DH_WIDTH - _MAIN_B_OSD_WIDTH*lineOffset);
			targetOsdStart = targetOsdStart*_KEY_NAVIGATION_POSION_H/100;
			targetOsdStart = targetOsdStart - Offset - currentOsdWidth * lineOffset;
		}
		else
		{
			targetOsdStart = (_PANEL_DV_HEIGHT - _MAIN_B_OSD_HEIGHT*lineOffset);//1440 - 11*18 = 1242
			targetOsdStart = targetOsdStart*_KEY_NAVIGATION_POSION_V/100; //1055
			targetOsdStart = targetOsdStart + (_MAIN_B_OSD_HEIGHT-2)*lineOffset - Offset - currentOsdHeight * lineOffset;
		}
	 }

	 
     DebugMessageOsd("targetOsdStart ",targetOsdStart);
	 return targetOsdStart;
}
*/

#define _NAVIGATION_ICON_ROW_START				6
extern BYTE g_ucFactoryPage;
void OsdDisplayUserKeyPage(void)
{
#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

	OsdDispDisableOsd();
	SET_OSD_STATE(_MENU_NAVIGAT);
	UpdateMaskValue();
	OsdFuncApplyMap(WIDTH(_MAIN_B_OSD_WIDTH), HEIGHT(_MAIN_B_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE, HEIGHT(_NAVIGAT_FRAME_HEIGHT), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(_MAIN_B_OSD_HEIGHT), _OSD_FONT_LIB_ROTATION_ENABLE);
#endif

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

	// Adjust Color Palette
	OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);



	OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);

	OsdDisplayKeyIndex(_LAYER_NAVIGAT);

	OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_MENU_POSION_H, _KEY_NAVIGATION_MENU_POSION_V);
	// Osd Enable
    OsdFuncEnableOsd();


/*******************************************************************************************/
#else


	BYTE i = 0; 
	
#if _GSYNC_TEST
	ucDsiableShowVFreqFlag = 1;
#endif
	OsdDispDisableOsd();
	DebugMessageOsd("2.UserKeyPage",1);
	SET_OSD_STATE(_MENU_NAVIGAT);

	UpdateMaskValue();
	
	ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
	ScalerOsd2FontFunction(_ENABLE);

	OsdFuncApplyMapOsdAB(WIDTH(_NAVIGAT_FRAME_WIDTH), HEIGHT(_NAVIGAT_FRAME_HEIGHT), COLOR(_CP_WHITE, _CP_BG),
						 WIDTH(_MAIN_B_OSD_WIDTH), HEIGHT(_MAIN_B_OSD_HEIGHT), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE, HEIGHT(_NAVIGAT_FRAME_HEIGHT), _OSD_MAP_B_REMAPPING_ENABLE,HEIGHT(_MAIN_B_OSD_HEIGHT), _OSD_FONT_LIB_ROTATION_ENABLE);
#endif

	OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

	// Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

	// set 2bit Font offset
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

	OsdFontVLCLoadFont(_FONT1_GLOBAL);
    OsdFontVLCLoadFont(_FONT_1BIT_KEYINDEXICON);
    OsdFontVLCLoadFont(_FONT_1BIT_MAINMENUICON);
    OsdFontVLCLoadFont(_FONT_2BIT_GLOBAL);
	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)

	SET_OSD_WINDOW_BUTTON_TYPE(_OSD_WINDOW_BUTTON_TYPE_BORDER);
	SET_OSD_WINDOW_COLOR_BORDER(_CP_WHITE);
	SET_OSD_WINDOW_SHADOW_BORDER_PIXEL_WIDTH(0);
	SET_OSD_WINDOW_SHADOW_BORDER_PIXEL_HEIGHT(0);
	SET_OSD_WINDOW_BUTTON_ENABLE(_ENABLE);

	OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(2), YSTART(6*18 - 20), XEND(_NAVIGAT_FRAME_WIDTH*12), YEND((_NAVIGAT_FRAME_HEIGHT)*18),COLOR0(_CP_DARKGRAY));
#else
	// Backgrond
	//OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(_MAIN_WIN_MAIN_FRAME_X_START), YSTART(_MAIN_WIN_MAIN_FRAME_Y_START), XEND(_MAIN_WIN_MAIN_FRAME_X_END), YEND(_MAIN_WIN_MAIN_FRAME_Y_END+2),COLOR0(_CP_DARKGRAY));
	OsdWindowDrawing(WINNO(_MAIN_WIN_MAIN_FRAME),XSTART(0), YSTART(6*18), XEND(_NAVIGAT_FRAME_WIDTH*12), YEND((_NAVIGAT_FRAME_HEIGHT - 1)*18),COLOR0(_CP_DARKGRAY));
#endif

#if(_DEFAULT_OSD_STYLE != _TRG_OSD_STYLE)
	OsdWindowDrawing(WINNO(_OSD_WINDOW_1),XSTART(1*12), YSTART(5*18), XEND((_NAVIGAT_FRAME_WIDTH - 1)*12), YEND((_NAVIGAT_FRAME_HEIGHT)*18),COLOR0(_CP_DARKGRAY));
	// Main Frame
    OsdFontPut1BitTable(ROW(5), 						COL(0), tiOSD_1BIT_MAIN_FRAME_ARC_UL, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(5), 						COL(_NAVIGAT_FRAME_WIDTH-1), tiOSD_1BIT_MAIN_FRAME_ARC_UR, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_NAVIGAT_FRAME_HEIGHT-1), 	COL(0), tiOSD_1BIT_MAIN_FRAME_ARC_DL, COLOR(_CP_DARKGRAY, _CP_BG));
    OsdFontPut1BitTable(ROW(_NAVIGAT_FRAME_HEIGHT-1), 	COL(_NAVIGAT_FRAME_WIDTH-1), tiOSD_1BIT_MAIN_FRAME_ARC_DR, COLOR(_CP_DARKGRAY, _CP_BG));
#endif


#if(_DEF_KEY_ROCKER)
	OsdFontPut1BitTable(_NAVIGATION_ICON_ROW_START, 1, tiOSD_OSD_NAVIGATION_ICON_View, (OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))?(COLOR(_CP_BLOCK, _CP_DARKGRAY)):(COLOR(_CP_WHITE, _CP_DARKGRAY)));
	OsdFontPut1BitTable(_NAVIGATION_ICON_ROW_START+3, 1, tiOSD_OSD_NAVIGATION_ICON_ConBri, (OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI))?(COLOR(_CP_BLOCK, _CP_DARKGRAY)):(COLOR(_CP_WHITE, _CP_DARKGRAY)));
	OsdFontPut1BitTable(_NAVIGATION_ICON_ROW_START+6, 1, tiOSD_OSD_NAVIGATION_ICON_Input, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(_NAVIGATION_ICON_ROW_START+9, 1, tiOSD_OSD_NAVIGATION_ICON_Menu, COLOR(_CP_WHITE, _CP_DARKGRAY));
	OsdFontPut1BitTable(_NAVIGATION_ICON_ROW_START+12, 1, tiOSD_OSD_NAVIGATION_ICON_X, COLOR(_CP_WHITE, _CP_DARKGRAY));
#endif

	//��ʾ��һ�ΰ��°���������
	// ViewMode
	OsdPropPutString(ROW(6 + 0 * 3), COL(5), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, 0, (OSD_ITEM_MASK_GET(_OSD_HOTKEY_VIEWMODE))?(COLOR(_CP_BLOCK, _CP_DARKGRAY)):(COLOR(_CP_WHITE, _CP_DARKGRAY)), GET_OSD_LANGUAGE());
	// ConBri
	OsdPropPutString(ROW(6 + 1 * 3), COL(5), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, 1, (OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI))?(COLOR(_CP_BLOCK, _CP_DARKGRAY)):(COLOR(_CP_WHITE, _CP_DARKGRAY)), GET_OSD_LANGUAGE());
	// Input
	OsdPropPutString(ROW(6 + 2 * 3), COL(5), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, 2, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
	// MainMenu
	OsdPropPutString(ROW(6 + 3 * 3), COL(5), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, 3, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());
	// Exit
	OsdPropPutString(ROW(6 + 4 * 3), COL(5), _PFONT_PAGE_0, _STRING_HOT_KEY_NAVIGATION, 4, COLOR(_CP_WHITE, _CP_DARKGRAY), GET_OSD_LANGUAGE());

	OsdDisplayKeyIndex(_LAYER_NAVIGAT);

	if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 98, 70);
	else
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_A, _KEY_NAVIGATION_MENU_POSION_H, _KEY_NAVIGATION_MENU_POSION_V);



#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#elif(_DEF_KEY_ROCKER)
	if(GET_OSD_ROTATE_STATUS()==_OSD_ROTATE_DEGREE_270)
    	OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_B, 98, 90);
	else
		OsdDispSetPosition(_POS_DIRECT, _OSD_POSITION_GLOBAL_B, _KEY_NAVIGATION_POSION_H, _KEY_NAVIGATION_POSION_V);
#endif

	// Osd Enable
    OsdFuncEnableOsd();


#endif


}
#endif

#if(_FRONT_SIGHT_FUNCTION == _ON)
void OsdDispFrontSight(void)
{
	SET_OSD_STATE(_MENU_NONE);
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	//OsdDispDisableOsd();    
	OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
	g_ucOsdWidth = 0;
	g_ucOsdHeight = 0;
	g_ucOsdWidthB = 0;
	g_ucOsdHeightB = 0;

	OSD_SubMenuCur = 0;
	g_usOsdKeyDirectionType = _LAYER_NONE;
	ScalerOsd2FontFunction(_DISABLE);
    SET_OSD_STATE(_OSD_HOTKEY_FRONT_SIGHT);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	OsdFuncApplyMap(WIDTH(2), HEIGHT(1), COLOR(_CP_WHITE, _CP_BG)); 
#else
	OsdFuncApplyMap(WIDTH(6), HEIGHT(4), COLOR(_CP_WHITE, _CP_BG)); 
#endif

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
 	ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _OSD_MAP_A_REMAPPING_ENABLE,HEIGHT(4), _OSD_MAP_B_REMAPPING_DISABLE,HEIGHT(0),_OSD_FONT_LIB_ROTATION_ENABLE);
#endif	
    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(0xFF);
    //OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY_GAME);
	OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_CROSS[3], COLOR(_CP_BLUE_1, _CP_BG));
#else	
	OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFontVLCLoadFont(_FONT_2BIT_FRONT_SIGHT);

	// Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_FRONT_SIGHT);
	OsdFontPut2BitTable(ROW(0), COL(0), tiOSD_OSD_FRONT_SIGHT, COLOR0(_CP_BG) ,COLOR1(_CP_WHITE) ,COLOR2(_CP_DARKGRAY) ,COLOR3(_CP_RED));
#endif	


	DebugMessageOsd("0.OsdDispFrontSight",111);

    OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);

	SET_OSD_FRONT_SIGHT(_ON);
	RTDNVRamSaveOSDData();
}

#endif


#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
//--------------------------------------------------
// Description	    :
// Input Value	    : 
// Output Value     :
//--------------------------------------------------
void OsdDisplayDrawSelectedCursor(BYTE ucPage, BYTE ucItem)
{
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    DebugMessageOsd("Draw cursor ucPage:", ucPage);
    DebugMessageOsd("Draw cursor ucItem:", ucItem);

	switch(ucPage)
	{
		case 2:
            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START + _FONT_WIDTH), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(ucItem % _OSD_3RD_ITEM_LENGTH)), XEND(_MAIN_WIN_2ND_CURSOR_X_END - _FONT_WIDTH), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(ucItem % _OSD_3RD_ITEM_LENGTH)), _CP_BLUE, _CP_WHITE, _CP_BG);
			OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(2), tiOSD_1BIT_FUNCTION_CURSOR, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(16), tiOSD_1BIT_FUNCTION_CURSOR_R, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut2BitTable(ROW(_ROW_1ST_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(2), tiOSD_2BIT_FUNCTION_UL, _CP_GRAY, _CP_GRAY, _CP_BLUE, _CP_YELLOW);
			break;
		case 3:
			OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(18), tiOSD_1BIT_VALUE_CURSOR_1, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(32), tiOSD_1BIT_VALUE_CURSOR_R, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut2BitTable(ROW(_ROW_2ND_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(18), tiOSD_2BIT_VALUE_UL, _CP_GRAY, _CP_GRAY, _CP_BLUE, _CP_YELLOW);
			break;
		case 4:
			OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(34), tiOSD_1BIT_VALUE_CURSOR_2, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(47), tiOSD_1BIT_VALUE_CURSOR_R, COLOR(_CP_GRAY, _CP_BLUE));
			OsdFontPut2BitTable(ROW(_ROW_3RD_TEXT_START + (ucItem  % _OSD_3RD_ITEM_LENGTH) * 2), COL(34), tiOSD_2BIT_VALUE_UL, _CP_GRAY, _CP_GRAY, _CP_BLUE, _CP_YELLOW);
			break;
		default:
			break;
			
	}
}

//--------------------------------------------------
// Description	    :
// Input Value	    : 
// Output Value     :
//--------------------------------------------------
void OsdDisplayClearSelectedCursor(BYTE ucPage, BYTE ucItem)
{
    DebugMessageOsd("clear cursor ucPage:", ucPage);
    DebugMessageOsd("clear cursor ucItem:", ucItem);
	switch(ucPage)
	{
		case 2:
			OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2), COL(2), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(2), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(16), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 2), COL(2), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(1));
			break;
		case 3:
			OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2), COL(18), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(18), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(32), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 2), COL(18), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(1));
			break;
		case 4:
			OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2), COL(34), WIDTH(_COL_1ST_TEXT_SPACE), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(34), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 1), COL(47), WIDTH(1), HEIGHT(1));
			OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START + (ucItem % _OSD_3RD_ITEM_LENGTH) * 2 + 2), COL(34), WIDTH(_COL_1ST_TEXT_SPACE), HEIGHT(1));
			break;
		default:
			break;
	}
}



#endif




#if(_DEF_OSD_GAMING == _ON)

void OsdDisplayCrosshairItem()
{
    BYTE i = 0;

    if(g_usOsdMenu4Page == 0)
    {
        for(i = 0; i < 1; i++)
        {
		#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
            OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_3, _STRING_CROSSHAIR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        #else
            OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_3, _STRING_CROSSHAIR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        #endif
        }
        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + 3), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE / 2 - 1), tiOSD_1BIT_CROSSHAIR, COLOR(_CP_RED,_CP_BG));
        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + 9), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE / 2 - 1), tiOSD_1BIT_CROSSHAIR, COLOR(_CP_GREEN,_CP_BG));
    }
    else
    {
        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + 1), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE / 2 - 1), tiOSD_1BIT_CROSSHAIR1, COLOR(_CP_BLUE_1,_CP_BG));
    }
}

#endif


#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
void HotKeyFun(void)
{
     //DebugMessageOsd("HotKey1",1606);
    switch (GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            switch (OSD_HOT_KEY_PAGE)
            {
#if(_DEF_NAVIGATION_OSD_ENABLE)
                case _OSD_START_UP:
                    OsdDispMainMenu();
                    break;
#endif
                case _OSD_HOTKEY_CONBRI:
                    OSD_SubMenuCur++;
                    osdDispDrawHotKeyCursor();
                    break;
#if(_MENU_AUDIO_SUPPORT)
                case _OSD_HOTKEY_VOLUME:
                    SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE());
                    OsdDisplayUpdateVolumeMuteIcon();
                    break;
#endif
                default:
                    //DebugMessageOsd("HotKey2",1629);
                    HotKeyFUNAdjust();
                    break;
            }
            break;
        case _LEFT_KEY_MESSAGE:
            switch (OSD_HOT_KEY_PAGE)
            {
#if(_DEF_NAVIGATION_OSD_ENABLE)
                case _OSD_START_UP:
                    OsdDispDrawHotKeyWindow(_OSD_HOTKEY_INPUT);
                    break;
#endif
                case _OSD_HOTKEY_CONBRI:
#if(_MENU_AUDIO_SUPPORT)
                case _OSD_HOTKEY_VOLUME:
#endif
                    HotKeyFUNAdjust();
                    break;
#if(_5KEY_MENU_STYLE)					
				case _OSD_HOTKEY_INPUT :
				if(OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_2)==0&&OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_0)==0)
					{
                     OSD_SubMenuCur--;
                     osdDispDrawHotKeyCursor();
					}
					 break;
#endif					
                default:
                    OSD_SubMenuCur--;
                    osdDispDrawHotKeyCursor();
                    break;
            }
            break;

        case _RIGHT_KEY_MESSAGE:
            switch (OSD_HOT_KEY_PAGE)
            {
#if(_DEF_NAVIGATION_OSD_ENABLE)
                case _OSD_START_UP:
                    OsdDispDrawHotKeyWindow(_OSD_HOTKEY_CONBRI);
                    break;
#endif
                case _OSD_HOTKEY_CONBRI:
#if(_MENU_AUDIO_SUPPORT)
                case _OSD_HOTKEY_VOLUME:
#endif
                    HotKeyFUNAdjust();
                    break;
#if(_5KEY_MENU_STYLE)
                case _OSD_HOTKEY_INPUT	:
					if(OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_2)==0&&OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_0)==0)
					{
                     OSD_SubMenuCur++;
                     osdDispDrawHotKeyCursor();
					}
					 break;
#endif					 
                default:
                    OSD_SubMenuCur++;
                    osdDispDrawHotKeyCursor();
                    break;
            }
            break;
        case _EXIT_KEY_MESSAGE:

			if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_LANGUAGE_SELECT || OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT)
			{
				break;
			}
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			else if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT)
			{
				OsdDispDisableOsd();
			}
#endif
			else
			{
#if(_5KEY_MENU_STYLE)   //2025.2.11 tx
			if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
#endif				
			{
#if(_DEF_NAVIGATION_OSD_ENABLE)
				if (OSD_HOT_KEY_PAGE == _OSD_START_UP)
				{
					OsdDispDrawHotKeyWindow(_OSD_HOTKEY_VIEWMODE);
				}
				else
				{
				   OsdDispDisableOsd();
				}
#else
				OSD_HOT_KEY_PAGE++;
#if(_5KEY_MENU_STYLE)  //   2025.2.11 tx
#if(_MENU_AUDIO_SUPPORT)
			    if(SysSourceGetSourceType() == _SOURCE_VGA&&GET_OSD_HOTKEY_LEFT()==_OSD_HOTKEY_VIEWMODE)
			  	{
			     OSD_HOT_KEY_PAGE++;
			  	} 
#endif
#endif				
#if(_5KEY_MENU_STYLE)   //2025.2.14 tx
#if(_MENU_AUDIO_SUPPORT)
				
				if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI)&&(GET_OSD_HOTKEY_LEFT()==_OSD_HOTKEY_VOLUME||(SysSourceGetSourceType() == _SOURCE_VGA&&GET_OSD_HOTKEY_LEFT()==_OSD_HOTKEY_VIEWMODE)))
					OSD_HOT_KEY_PAGE++;
				
#endif				
#else
				if(OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONBRI))
					OSD_HOT_KEY_PAGE++;
#endif


				if (OSD_HOT_KEY_PAGE > _OSD_HOTKEY_INPUT)
					OSD_HOT_KEY_PAGE = _OSD_HOTKEY_VIEWMODE;
				 SET_OSD_HOTKEY_LEFT(OsdHotState[OSD_HOT_KEY_PAGE - _OSD_HOTKEY_VIEWMODE]);
				OsdDispDrawHotKeyWindow(GET_OSD_HOTKEY_LEFT());
#endif
			}
			}
             // }
             break;

        default:
            break;
    }
}

#elif(_DEF_KEY_ROCKER)


void HotKeyFun(void)
{
	DebugMessageOsd("1.HotKeyFun",g_usOsdKeyDirectionType);
	
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
	if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT)
	{
		switch (GET_KEYMESSAGE())
		{
			case _LEFT_KEY_MESSAGE: 
                HotKeyFUNAdjust();
				break;
				
			case _RIGHT_KEY_MESSAGE: 
				OsdDispDisableOsd();
				break;

			default:
				break;
		}
	}
	else
#endif
	{

		switch (GET_KEYMESSAGE())
		{
		    case _MENU_KEY_MESSAGE: // _MIDDLE_KEY_MESSAGE
		        switch (OSD_HOT_KEY_PAGE)
		        {
		            case _OSD_HOTKEY_CONBRI:
						if(!(OSD_ITEM_MASK_GET(_OSD_HOTKEY_BACKLIGHT) || OSD_ITEM_MASK_GET(_OSD_HOTKEY_CONTRAST)))
		                	OSD_SubMenuCur++;
						
		                osdDispDrawHotKeyCursor();
		                break;
		            case _OSD_HOTKEY_VOLUME:
		                SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE());
		                OsdDisplayUpdateVolumeMuteIcon();
		                break;
		            default:
		                HotKeyFUNAdjust();
		                break;
		        }
		        break;
		    case _LEFT_KEY_MESSAGE:
			case _UP_KEY_MESSAGE:
		        switch (OSD_HOT_KEY_PAGE)
		        {
		            case _OSD_HOTKEY_CONBRI:
		            case _OSD_HOTKEY_VOLUME:
		                HotKeyFUNAdjust();
		                break;

					case _OSD_HOTKEY_INPUT:
						{
							BYTE count = _OSD_SOURCE_AMOUNT;
							BYTE i = OSD_SubMenuCur;

							while(count--)
							{
								if (i == 0)
					            {
					                i = _OSD_SOURCE_AMOUNT-1;
					            }
					            else
					            {
					                i--;
					            }

								if(!OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_0 + i))
								{
									OSD_SubMenuCur = i % _OSD_SOURCE_AMOUNT;
									osdDispDrawHotKeyCursor();
									break;
								}
							}
						}
						break;
						
		            default:
		                OSD_SubMenuCur--;
		                osdDispDrawHotKeyCursor();
		                break;
		        }
		        break;

		    case _RIGHT_KEY_MESSAGE:
			case _DOWN_KEY_MESSAGE:
		        switch (OSD_HOT_KEY_PAGE)
		        {
		            case _OSD_HOTKEY_CONBRI:
		            case _OSD_HOTKEY_VOLUME:
		                HotKeyFUNAdjust();
		                break;

					case _OSD_HOTKEY_INPUT:
						{
							BYTE count = _OSD_SOURCE_AMOUNT;
							BYTE i = OSD_SubMenuCur;

							while(count--)
							{
								if(i == _OSD_SOURCE_AMOUNT-1)
					            {
					                i = 0;
					            }
					            else
					            {
					                i++;
					            }

								if(!OSD_ITEM_MASK_GET(_MENU_FUN_INPUT_0 + i))
								{
									OSD_SubMenuCur = i % _OSD_SOURCE_AMOUNT;
									osdDispDrawHotKeyCursor();
									break;
								}
							}
						}
						break;
		            default:
		                OSD_SubMenuCur++;
		                osdDispDrawHotKeyCursor();
		                break;
		        }
		        break;
				
		    case _EXIT_KEY_MESSAGE:
				{
#if(_DEF_NAVIGATION_OSD_ENABLE)

					if(g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT_NOSIGNAL &&  SysModeGetModeState() != _MODE_STATUS_ACTIVE )
					{
						if(GET_FACTORY_MODE())
							{
								OsdDispDisableOsd();

								
							}

						ScalerTimerReactiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
					}
					else
					{
						switch (OSD_HOT_KEY_PAGE)
						{
							case _OSD_HOTKEY_LANGUAGE_SELECT:
#if(_DEF_District_swtich_Message == _ON)
							case _OSD_HOTKEY_DISTRICT_SELECT:
#endif
								HotKeyFUNAdjust();
								break;
						
							default:


								OsdDispDisableOsd();

									
								break;
						}

					}



#else
					if(g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT_NOSIGNAL)
					{
					}
					else
					{
						do
						{
		            		OSD_HOT_KEY_PAGE++;
							if(OSD_HOT_KEY_PAGE > _OSD_HOTKEY_END)
								OSD_HOT_KEY_PAGE = _OSD_HOTKEY_START;
							
						}while(OSD_ITEM_MASK_GET(OSD_HOT_KEY_PAGE));
							
			            SET_OSD_HOTKEY_LEFT(OsdHotState[OSD_HOT_KEY_PAGE - _OSD_HOTKEY_START]);
			            OsdDispDrawHotKeyWindow(GET_OSD_HOTKEY_LEFT());
					}
#endif
				}
		        break;

		    default:
		        break;
		}
	}
}

#endif


#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
