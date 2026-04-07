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
// ID Code      : RTD2014Key.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_KEY__

#include "UserCommonInclude.h"

extern bit ddcci_reset;

#if(_OSD_TYPE == _REALTEK_2014_OSD)
/*
BYTE code KeyDefault[10] = 
{
	POWER_KEY,
	MENU_KEY,	
	EXIT_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	
	POWER_REG,
	MENU_REG,	
	EXIT_REG,
	RIGHT_REG,
	LEFT_REG,
};
*/
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Key Mask
//--------------------------------------------------
#define _RELEASE_KEY_MASK                           0x00
#define _POWER_KEY_MASK                             0x01
#define _MENU_KEY_MASK                              0x02
#define _RIGHT_KEY_MASK                             0x04
#define _LEFT_KEY_MASK                              0x08
#define _EXIT_KEY_MASK                              0x10
#define _MIDDLE_KEY_MASK                            0x20
#define _UP_KEY_MASK                                0x40
#define _DOWN_KEY_MASK                              0x80

#if(_5KEY_MENU_STYLE)   //2025.02.11 tx

#define _LOCK_KEY_MASK								(_LEFT_KEY_MASK | _RIGHT_KEY_MASK)

#define _POWER_LOCK_KEY_MASK						(_RIGHT_KEY_MASK | _MENU_KEY_MASK)
#define _LOGO_BOOTUP_KEY_MASK						(_MENU_KEY_MASK | _EXIT_KEY_MASK)
#if(_DEF_VGA_TIMING_KEY_2_4)
#define _SWITCH_MODE_KEY_MASK						(_LEFT_KEY_MASK | _EXIT_KEY_MASK)//(_4_KEY_MASK | _2_KEY_MASK)//0x20	//VGA Timing 切换
#endif

#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#define _LOCK_KEY_MASK								( _MENU_KEY_MASK| _RIGHT_KEY_MASK)

#define _POWER_LOCK_KEY_MASK						(_RIGHT_KEY_MASK | _EXIT_KEY_MASK)
#define _LOGO_BOOTUP_KEY_MASK						(_MENU_KEY_MASK | _EXIT_KEY_MASK)
#if(_DEF_VGA_TIMING_KEY_2_4)
#define _SWITCH_MODE_KEY_MASK						(_LEFT_KEY_MASK | _EXIT_KEY_MASK)//(_4_KEY_MASK | _2_KEY_MASK)//0x20	//VGA Timing 切换
#endif



#else
#define _LOCK_KEY_MASK								(_LEFT_KEY_MASK | _MENU_KEY_MASK)

#define _POWER_LOCK_KEY_MASK						(_RIGHT_KEY_MASK | _MENU_KEY_MASK)
#define _LOGO_BOOTUP_KEY_MASK						(_LEFT_KEY_MASK | _EXIT_KEY_MASK)

#if(_DEF_VGA_TIMING_KEY_2_4)
#define _SWITCH_MODE_KEY_MASK						(_RIGHT_KEY_MASK | _EXIT_KEY_MASK)//(_4_KEY_MASK | _2_KEY_MASK)//0x20	//VGA Timing 切换
#endif

#endif

#define _AUTO_COLOR_KEY_MASK		     			0x40//(_2_KEY_MASK | _3_KEY_MASK | _4_KEY_MASK)




#define _POWER_RIGHT_KEY_MASK                       (_POWER_KEY_MASK | _RIGHT_KEY_MASK)
#define _POWER_MENU_KEY_MASK                        (_POWER_KEY_MASK | _MENU_KEY_MASK)
#define _POWER_LEFT_RIGHT_KEY_MASK                  (_POWER_KEY_MASK | _LEFT_KEY_MASK | _RIGHT_KEY_MASK)

//--------------------------------------------------
// Definitions of IR Key Code
//--------------------------------------------------
#if(_IR_SUPPORT == _IR_HW_SUPPORT)
#if(_IR_PROTOCAL == _IR_NEC_DTV328)
#define _IR_CODE_KEY_POWER                          0x0408
#define _IR_CODE_KEY_MENU                           0x0443
#define _IR_CODE_KEY_RIGHT                          0x0406
#define _IR_CODE_KEY_LEFT                           0x0407
#define _IR_CODE_KEY_EXIT                           0x045B

#elif(_IR_PROTOCAL == _IR_SONY_B102P)
#define _IR_CODE_KEY_POWER                          0x0950
#define _IR_CODE_KEY_MENU                           0x0A50
#define _IR_CODE_KEY_RIGHT                          0x0920
#define _IR_CODE_KEY_LEFT                           0x0930
#define _IR_CODE_KEY_EXIT                           0x0940

#elif(_IR_PROTOCAL == _IR_PHILIPS_RC6)
#define _IR_CODE_KEY_POWER                          0x000C
#define _IR_CODE_KEY_MENU                           0x005C
#define _IR_CODE_KEY_RIGHT                          0x005B
#define _IR_CODE_KEY_LEFT                           0x005A
#define _IR_CODE_KEY_EXIT                           0x000A

#endif
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucKeyStatePrev;
BYTE g_ucKeyStateCurr;
BYTE g_ucKeyStateSkip;

#if(_AD_KEY_SUPPORT == _ON)
BYTE g_ucBackupKeyState = 0xFF;
#endif

BYTE g_usOsdKeyDirectionType = _LAYER_NONE;

extern void RTDKeyPressHightLight(BYTE KeyMask);

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserInterfaceKeyHandler(void);
void RTDKeyInitial(void);
bit RTDKeyScanReady(void);
BYTE RTDKeyScan(void);
bit RTDKeyPowerKeyProc(void);
void RTDKeyPowerKeyMix(void);
void RTDKeyMessageProc(void);
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg);

bit RTDKeySpecialProc(BYTE ucKeyMask);
void RTDKeyHoldKeyTimerCancel(void);
void RTDKeyHoldKeyCheck(void);
void KeyLedPowerIndicator(BYTE ucGetKey);
BYTE KeyMaskRotate(BYTE ucKeyMask);


#if(_IR_SUPPORT == _IR_HW_SUPPORT)
BYTE RTDIRKeyScan(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Key Handler, executed in the main loop.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyHandler(void)
{

#if(_DEF_KEY_ROCKER)

	BYTE ucKeyState = 0;
	BYTE ucVoltage0 = 0;
	BYTE ucVoltage1 = 0;
	BYTE ucVoltage2 = 0;
	BYTE ucVoltage3 = 0;

	ucVoltage0 = PCB_ADKEY0();
	ucVoltage1 = PCB_ADKEY1();
	ucVoltage2 = PCB_ADKEY2();
	ucVoltage3 = PCB_ADKEY3();
	
#endif

    // Skip key status update for tool
    if(g_ucKeyStateSkip != 0)
    {
        g_ucKeyStateSkip = 0;
        return;
    }

    // Clear the key message
    if(GET_KEYMESSAGE() != _HOLD_KEY_MESSAGE)
    {
        SET_KEYMESSAGE(_NONE_KEY_MESSAGE);
    }
	
#if(_DEF_KEY_ROCKER)
	if(( SysPowerGetPowerStatus() == _POWER_STATUS_AC_ON))	
		PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

	if((SysPowerGetPowerStatus() == _POWER_STATUS_AC_ON) && (KeyMaskRotate(ucKeyState) == _LEFT_KEY_MASK))
	{

		SET_FACTORY_MODE(_ON);
		SET_OSD_HOTKEY_BURNIN(_ON);
		TPVNVRamSaveFactoryDate();

		SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL); // 进入老化后立刻开机

	}
#endif

    if(RTDKeyScanReady() == _TRUE)
    {
        // Store previous key state
        g_ucKeyStatePrev = g_ucKeyStateCurr;

        // Get current key state
        g_ucKeyStateCurr = RTDKeyScan();

        // Power key process, return if power key is pressed
        if(RTDKeyPowerKeyProc() == _TRUE)
        {
            return;
        }


        // Convert key state to key message, store in (ucKeyNotify)
        RTDKeyMessageProc();
    }
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
void RTDKeyCheckRelease(BYTE ucKey)
{
	switch(ucKey)
	{
		case _LOCK_KEY_MASK:
		case _LOGO_BOOTUP_KEY_MASK:
		case _POWER_LOCK_KEY_MASK:
			SET_KEY_LONG_PRESSED(_TRUE);
			SET_KEY_COMBINE(_FALSE);
			//DebugMessageOsd("1.RTDKeyCheckRelease",ucKey);
			break;

		default:
		    SET_KEY_LONG_PRESSED(_FALSE);
			break;
	}
}


//--------------------------------------------------
// Description	:
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDisplayCombineKeyFunction(bit bKeyMode, BYTE ucValue)
{
    BYTE ucColnum = 0;

	if(GET_OSD_RESOLUTION_STATUS() == _TRUE)
	{
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_Timing_Notice);
	}
	
	//DebugMessageOsd("1.ucValue",ucValue);
	
#if(_DEF_KEY_ROCKER)
	if(ucValue>10)
		SET_KEY_COMBINE(_FALSE);
#endif

	if(GET_KEY_COMBINE() == _FALSE)
	{
		SET_KEY_COMBINE(_TRUE);
		ucValue = 0;
		CLR_KEY_TIME_FOR_SECOND();
		
#if(_INSTANT_TIMER_EVENT_0 == _ON)
		ScalerTimer0SetTimerCount(20); // this timer always counter
#endif

        if(bKeyMode ==_COMBINE_LOCK_OSD )//
		{
			OsdDispOsdMessage(_OSD_DISP_LOCKING_STATUS_MSG);
		}
		else//(ucKeyMode == _POWER_LOCK_KEY_MASK)
		{
			OsdDispOsdMessage(_OSD_DISP_POWER_LOCKING_STATUS_MSG);
		}
		OsdFuncEnableOsd();
	}
	

//	if((GET_AUTO_POWEROFF_STATUS() == _FALSE) ||
//	   ((GET_AUTO_POWEROFF_STATUS() == _TRUE) && (bKeyMode != _POWER_LOCK_KEY_MASK)))
	{
	    ucColnum = (_OSD_MSG_COL_NUM_23 - _SLIDER_BAR_LENGTH - 3) / 2 + 1;
		OsdDisplaySubSlider(ROW(_COMBINE_KEY_SLIDER_ROW), COL(ucColnum), ucValue, MAX(_LOCK_KEY_TIME), MIN(_SLIDER_MIN), _SLIDER_BAR_LENGTH,_OSD_NORMAL_TYPE);
		OsdPropShowNumber_1(ROW(_COMBINE_KEY_SLIDER_ROW), COL(ucColnum+_SLIDER_BAR_LENGTH+1), ucValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_1), _PFONT_PAGE_SLIDER, COLOR(_CP_WHITE, _CP_BG));
	}
}



//--------------------------------------------------
// Description  : Key intial.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyInitial(void)
{
    CLR_KEYSCANREADY();
    CLR_KEYSCANSTART();
}

//--------------------------------------------------
// Description  : Key scan ready process. We wait 0.02 sec in order to keep the keypad debounce
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDKeyScanReady(void)
{
    if((GET_KEYSCANSTART() == _TRUE) && (GET_KEYSCANREADY() == _TRUE) \
		|| (SysPowerGetPowerStatus()==_POWER_STATUS_AC_ON))
    {
        return _TRUE;
    }
    else if(GET_KEYSCANSTART() == _FALSE)
    {
        // Set Scan start flag.
        SET_KEYSCANSTART();

        // SET_KEYSCANREADY();
        // Wait 0.02 sec in order to keep the keypad debounce
		if((GetOsdShowType(GET_OSD_STATE()) != _TYPE_SLIDER  && (OSD_HOT_KEY_PAGE != _OSD_HOTKEY_CONBRI)) && (GET_KEYREPEATSTART() == _TRUE))
		{
			ScalerTimerReactiveTimerEvent(SEC(0.15), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}     
		else
		{
			ScalerTimerReactiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_KEY_SCAN_READY);
		}

		
        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get key status
// Input Value  : None
// Output Value : Return Key status
//--------------------------------------------------
BYTE RTDKeyScan(void)
{
    BYTE ucKeyState = 0;
    BYTE ucVoltage0 = 0;
    BYTE ucVoltage1 = 0;
    BYTE ucVoltage2 = 0;
    BYTE ucVoltage3 = 0;
#if(_AD_KEY_SUPPORT == _ON)
	BYTE i = 0;
	BYTE j = 0;
	BYTE ms_i = 0;
#endif
	bit bShowAutoIcon = 1;
	//bit bAutoKey = 0;

#if(_AD_KEY_SUPPORT == _ON)



    ucVoltage0 = PCB_ADKEY0();
    ucVoltage1 = PCB_ADKEY1();
    ucVoltage2 = PCB_ADKEY2();
    ucVoltage3 = PCB_ADKEY3();


#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	CLR_KEY_TIME_FOR_SECOND();
	i=3;
	if(GET_OSD_STATE() == _MENU_NONE)
	{
		ms_i = 10;	//多一些时间 让组合快捷键更容易按出 20--出菜单会太慢
	}
#if 0//(_AUDIO_SUPPORT == _ON)
	else if(GET_OSD_ADJUST() && GET_OSD_STATE() == _VOLUME_ADJUST)
	{
		ms_i = 1;
	}
	else if(GET_OSD_ADJUST())
//进度条
	{
		ms_i = _DEF_ADJ_Delay_Time;//0
	}
	
#endif
	else
	{
		ms_i = 1;
	}

	while(i)
	{
		ucVoltage0 = PCB_ADKEY0();
		ScalerTimerDelayXms(ms_i);
		j = PCB_ADKEY0();
		if(abs(ucVoltage0-j)<5)
			break;
		i--;
	}

	i=3;
	while(i)
	{
		ucVoltage1 = PCB_ADKEY1();
		ScalerTimerDelayXms(ms_i);
		j = PCB_ADKEY1();
		if(abs(ucVoltage1-j)<5)
			break;
		i--;
	}

	i=3;
	while(i)
	{
		ucVoltage2 = PCB_ADKEY2();
		ScalerTimerDelayXms(ms_i);
		j = PCB_ADKEY2();
		if(abs(ucVoltage2-j)<5)
			break;
		i--;
	}

	i=3;
	while(i)
	{
		ucVoltage3 = PCB_ADKEY3();
		ScalerTimerDelayXms(ms_i);
		j = PCB_ADKEY3();
		if(abs(ucVoltage3-j)<5)
			break;
		i--;
	}


    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

    if((g_ucBackupKeyState == ucKeyState) && (ucKeyState != 0))
    {
        if(GET_KEYREPEATENABLE() != _ON)
        {
            RTDKeyInitial();
        }

        //return g_ucBackupKeyState;
    }
    else
    {
        g_ucBackupKeyState = ucKeyState;
        ucKeyState = 0;
    }

#else
	//CLR_KEY_TIME_FOR_SECOND();

	PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);

	if((g_ucBackupKeyState == ucKeyState) && (ucKeyState != 0))
	{
		if(GET_KEYREPEATENABLE() != _ON)
		{
			RTDKeyInitial();
		}
		//return ucKeyState;
	}

	pData[0] = 0;
	do
	{
		ScalerTimerDelayXms(1);

		if((abs(PCB_ADKEY0() - ucVoltage0) < 2) && (abs(PCB_ADKEY1() - ucVoltage1) < 2) && (abs(PCB_ADKEY2() - ucVoltage2) < 2) && (abs(PCB_ADKEY3() - ucVoltage3) < 2))
		{
			break;
		}
		else

		{
			ucVoltage0 = PCB_ADKEY0();
			ucVoltage1 = PCB_ADKEY1();
			ucVoltage2 = PCB_ADKEY2();
			ucVoltage3 = PCB_ADKEY3();
		}

		pData[0]++;
	}
	while(pData[0] < 10);

	ucKeyState = 0;

	PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);
	g_ucBackupKeyState = ucKeyState;

#endif // 


#else
    PCB_KEY_STATE(ucVoltage0, ucVoltage1, ucVoltage2, ucVoltage3, ucKeyState);
#endif // End of #if(_AD_KEY_SUPPORT == _ON)

#if(_DEF_JS_KEY_ICON_5_KEY_MODE)


		if(ucKeyState != 0)
		{
			SET_KEY_PRESSED(_TRUE);

		}
		else
		{
		    SET_KEY_PRESSED(_FALSE);
		    SET_KEY_LONG_PRESSED(_FALSE);
	    }
		// 防止一直按组合键的时候重复秀组合键
		if((GET_KEY_PRESSED() == _TRUE)&&(GET_KEY_LONG_PRESSED() == _TRUE))
		{
			//KeyLongPressCondition = _FALSE;
			ucKeyState = 0;
		}


		KeyLedPowerIndicator(ucKeyState);




/*************************组合键开始*********************************/

	if((ucKeyState == _LOCK_KEY_MASK) && (GET_OSD_STATE() == _MENU_NONE) && SysModeGetModeState() == _MODE_STATUS_ACTIVE)
	{
		//while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME) && (abs(PCB_ADKEY1() - ucVoltage1) < _KEYPAD_DEBOUNCE) && (abs(PCB_ADKEY2() - ucVoltage2) < _KEYPAD_DEBOUNCE))
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
		while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME)&&((b_KEY4==0&&b_KEY2==0)) )   
#elif(_DEFAULT_OSD_STYLE==_SUMA_OSD_STYLE)
		while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME)&&((LEFT_KEY==1&&(abs(PCB_ADKEY2() - ucVoltage2) < _KEYPAD_DEBOUNCE))) )   
#endif
		{
			OsdDisplayCombineKeyFunction(_COMBINE_LOCK_OSD, GET_KEY_TIME_FOR_SECOND());
		}

		if(GET_KEY_TIME_FOR_SECOND() < _LOCK_KEY_TIME)
		{
			ucKeyState = 0;
		}
		
		RTDKeyCheckRelease(ucKeyState);
	}
	else if((GET_OSD_STATE() == _MENU_NONE) && (ucKeyState == _POWER_LOCK_KEY_MASK))
	{
#if(_OSD_LOCK_ON_PowerLock_AND_LogoLock_SUPPORT)
		if((GET_OSD_STATE() == _MENU_NONE) && SysModeGetModeState() == _MODE_STATUS_ACTIVE && !GET_OSD_LOCK_STATUS())
#else
		if((GET_OSD_STATE() == _MENU_NONE) && SysModeGetModeState() == _MODE_STATUS_ACTIVE)
#endif
		{
			if(GET_AUTO_POWEROFF_STATUS() == _FALSE)
			{
#if(_AD_KEY_SUPPORT == _ON)
				//while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME) && (abs(PCB_ADKEY1() - ucVoltage1) < _KEYPAD_DEBOUNCE) && (abs(PCB_ADKEY2() - ucVoltage2) < _KEYPAD_DEBOUNCE))
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
				while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME)&&((b_KEY2==0&&b_KEY3==0)) )   
#elif(_DEFAULT_OSD_STYLE==_SUMA_OSD_STYLE)
				while((GET_KEY_TIME_FOR_SECOND() <= _LOCK_KEY_TIME)&&((LEFT_KEY==1&&(abs(PCB_ADKEY2() - ucVoltage2) < _KEYPAD_DEBOUNCE))) )   
#endif
                {
					OsdDisplayCombineKeyFunction(_COMBINE_LOCK_POWERKEY, GET_KEY_TIME_FOR_SECOND());
				}
				if(GET_KEY_TIME_FOR_SECOND() < _LOCK_KEY_TIME)
				{
					ucKeyState = 0;
#if(_DEF_KEY_ROCKER)
					//g_ucKeyLongTimeFlag = g_ucKeyLongTimeFlag | _BIT2;			
#endif
					//ScalerTimerDelayXms(200); //结束长按避免弹出其它菜单
				}
#else
				//ucKeyState = KeyCheckKeyContinue(ucKeyState, ucVoltage1, SECOND(11));
#endif
			}
			RTDKeyCheckRelease(ucKeyState);
		}
		else
		{
			if(ScalerOsdGetOsdEnable() == _DISABLE && (GET_OSD_LOCK_STATUS()) && SysModeGetModeState() == _MODE_STATUS_ACTIVE)
			{
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_OSD_LOCK_MSG);
			}
		
		}

	}
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
	else if((ucKeyState == _MENU_KEY_MASK) && (GET_OSD_STATE() == _MENU_FUN_TEMP) )
	{
#if(_AD_KEY_SUPPORT == _ON)

#if(_INSTANT_TIMER_EVENT_0 == _ON)
		ScalerTimer0SetTimerCount(20); // this timer always counter
#endif


#if 0
		while((abs(PCB_ADKEY1() - ucVoltage1) < _KEYPAD_DEBOUNCE) && (abs(PCB_ADKEY2() - ucVoltage2) < _KEYPAD_DEBOUNCE))
		{
			ScalerTimerDelayXms(10);
			
           	if(GET_KEY_TIME_FOR_SECOND() >= 5)
			{
				if((bShowAutoIcon == 1) && (SysSourceGetSourceType() == _SOURCE_VGA))
				{
					bShowAutoIcon = 0;
#if 0//(_OSD_ROTATE_3_ORIENTATION_SUPPORT == _ON)
					if(GET_OSD_ROTATE_STATUS() != _OSD_ROTATE_DEGREE_0)
					{
#if(_OSD_BOTTOM_BUTTON_V_SPACE_SUPPORT == _OFF)
						OsdTableFuncPutIcon1BitAndColor((_OSD_MAP_B_ROW_OFFSET + 4), 1, _ICON_1BIT_AUTO_COLOR, _CP_WHITE, _CP_BG ,_FONT_PAGE1);
#else
						OsdTableFuncPutIcon1BitAndColor((_OSD_MAP_B_ROW_OFFSET + 6), 1, _ICON_1BIT_AUTO_COLOR, _CP_WHITE, _CP_DARKGRAY ,_FONT_PAGE1);
#endif
					}
					else
#endif
					{	
#if(_OSD_BOTTOM_BUTTON_H_SPACE_SUPPORT == _ON)
						//OsdTableFuncPutIcon1BitAndColor(_OSD_MAP_B_ROW_OFFSET, 11, _ICON_1BIT_AUTO_COLOR, _CP_WHITE, _CP_DARKGRAY ,_FONT_PAGE1);
#else
						//OsdTableFuncPutIcon1BitAndColor(_OSD_MAP_B_ROW_OFFSET, _OSD_MAP_B_COL_3, _ICON_1BIT_AUTO_COLOR, _CP_WHITE, _CP_DARKGRAY ,_FONT_PAGE1);
#endif				
					}
					ScalerTimerDelayXms(300);
					ucKeyState = _AUTO_COLOR_KEY_MASK;

				return ucKeyState;
				}

			//bAutoKey = 1;
			}
		}
#endif
#else
		//ucKeyState = KeyCheckKeyContinue(ucKeyState, ucVoltage1, SECOND(5));

#endif
	RTDKeyCheckRelease(ucKeyState);

	}
#endif

	if(GET_OSD_STATE() == _OSD_MSG_INPUT_SOURCE)
	{
		ucKeyState = 0; 
	}

/*************************组合键结束*********************************/
#endif




#if(_IR_SUPPORT == _IR_HW_SUPPORT)
    if(ucKeyState == 0x00)
    {
        ucKeyState = RTDIRKeyScan();
    }
#endif // End of #if(_IR_SUPPORT == _IR_HW_SUPPORT)

    if(ucKeyState != 0)
    {
        RTDKeyInitial();
    }

	if(ucKeyState != 0)
	{
		DebugMessageOsd("ucKeyState",ucKeyState);
	}

    return ucKeyState;
}

//--------------------------------------------------
// Description  : Power key process
// Input Value  : None
// Output Value : Return _TRUE if power key is pressed
//--------------------------------------------------
bit RTDKeyPowerKeyProc(void)
{
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)

    if((g_ucKeyStateCurr & _POWER_KEY_MASK) != 0)
    {
        if(((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & _POWER_KEY_MASK) != 0)
        {
	        if(GET_OSD_PWKEY_LOCK_STATUS() == _TRUE)
			{
				if((GET_OSD_LOGO_ON() == _OFF)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE) \
					&&(g_usOsdKeyDirectionType == _LAYER_NONE  \
					|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_LANGUAGE \
					|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_DISTRICT  \
					|| g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION )\
					)
				{
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_LOCK_MSG);
				}
				return _FALSE;
			}

#if(_DEF_LONG_PRESS_POWER_OFF_3_SEC)

		    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE) //(g_usOsdKeyDirectionType != _LAYER_NONE)
        	{
        		if(g_usOsdKeyDirectionType != _LAYER_HOTKEY_LANGUAGE 
					&& g_usOsdKeyDirectionType != _LAYER_HOTKEY_DISTRICT
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
					&& g_usOsdKeyDirectionType != _LAYER_POWER_CONSUMPTION
#endif
					)
                	return  _FALSE;
			}

#elif(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223|| _PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) && (!_DEF_LONG_PRESS_POWER_OFF_3_SEC)

		    if((SysModeGetModeState() == _MODE_STATUS_ACTIVE))// && (g_usOsdKeyDirectionType != _LAYER_NONE))
        	{
        		if(g_usOsdKeyDirectionType != _LAYER_HOTKEY_LANGUAGE 
					&& g_usOsdKeyDirectionType != _LAYER_HOTKEY_DISTRICT
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
					&& g_usOsdKeyDirectionType != _LAYER_POWER_CONSUMPTION
#endif
					&&(ScalerOsdGetOsdEnable())
					)
                	return  _FALSE;
			}

#endif
			
            RTDKeyPowerKeyMix();

#if(_MPRT_SUPPORT == _ON)
			UserAdjustMPRTFuntion(_OFF);
#endif

            if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
            {
                SET_OSD_STATE(_MENU_NONE);
                SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
            }
            else
            {
            
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
#endif
				//SET_AUTO_SLEEP_STATUS(_SleepPowerSaving_OFF);

				SET_FACTORY_MODE(_OFF);
				SET_FACTORY_BURNIN(_OFF);
			    Input_New_State=10;
                Input_Old_State=11;
				ddcci_reset=0;
				TPVNVRamSaveFactoryDate();
#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
                UserAdjustAudioTtsPlayEvent(_AUDIO_TTS_EVENT_POWER_OFF);
                ScalerTimerReactiveTimerEvent(SEC(2), _USER_TIMER_EVENT_AUDIO_TTS_POWER_OFF);
#else
                	
                #if(_5KEY_MENU_STYLE)  //2025.2.13  tx wan
				RTDKeyPressHightLight(_POWER_KEY_MASK);
			    ScalerTimerDelayXms(_KEY_DELAYED_TIME); 
                #endif
                SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
            }

            return _TRUE;
        }
    }

#elif(_DEF_KEY_ROCKER)

	if(((g_ucKeyStateCurr & _MIDDLE_KEY_MASK) != 0))
	{
		if(((g_ucKeyStatePrev ^ g_ucKeyStateCurr) & _MIDDLE_KEY_MASK) != 0)
		{
			//DebugMessageOsd("4.g_ucKeyStatePrev", g_ucKeyStatePrev);

			RTDKeyPowerKeyMix();

			if(SysPowerGetPowerStatus() == _POWER_STATUS_OFF)
			{
				SET_OSD_STATE(_MENU_NONE);
				SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
				SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
				return _TRUE;
			}
		}
	}

#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : We can add some settings here while combo key with power key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyPowerKeyMix(void)
{
    switch(g_ucKeyStateCurr)
    {

        case _POWER_RIGHT_KEY_MASK:
            break;



        case _POWER_MENU_KEY_MASK:
#if(!_DEF_KEY_ROCKER)

			SET_FACTORY_MODE(_ON);
			SET_OSD_HOTKEY_BURNIN(_ON);
			TPVNVRamSaveFactoryDate();

#if(_VIEWMODE_SUPPORT == _ON)
            SET_OSD_VIEWMODE_TYPE(_VIEWMODE_DEFAULT);
#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)// 2025.0306 lj 工厂恢复默认值
			UserAdjustViewModeType(GET_OSD_VIEWMODE_TYPE());
			
			UserCommonNVRamRestoreSystemData();
			RTDNVRamRestoreOSDData();
			RTDNVRamRestoreUserColorSetting();
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			RTDNVRamRestoreViewModeParameters(); //还原情景模式结构体
			RTDNVRamRestoreBriCon();
			RTDNVRamRestoreBacklight();
#if(_DEF_VIEW_SONIC_DCR)//UserInterfaceAdjustColorProc
#if(_DCR_SUPPORT)
			UserAdjustDCRControl(GET_OSD_DCR_STATUS());
#endif	
#endif
		
#endif	
#endif
#if(_OSD_GAME_SUPPORT == _ON)
            SET_OSD_GAME_MODE(_GM_OFF);
#endif

#endif

            break;

        case _POWER_LEFT_RIGHT_KEY_MASK:
            break;

        default:
            break;
    }
}


//--------------------------------------------------
// Description  : Convert keypad status into key message, stores in ucKeyNotify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#define _NAVIGATION_KEY_PRESS_WIN						_OSD_WINDOW_4_2
#define _NAVIGATION_KEY_SELECT_FONT_COLOR				_CP_WHITE
#define _NAVIGATION_KEY_SELECT_BG_COLORT				_CP_BLUE
#ifndef ENABLE_KEY_PRESS_HIGHLIGHT
#define ENABLE_KEY_PRESS_HIGHLIGHT						_OFF
#endif

void RTDKeyPressHightLight(BYTE KeyMask)
{

#if(ENABLE_KEY_PRESS_HIGHLIGHT == _OFF)

		if(GET_POWER_INDICATOR() == _OFF)
		{
			KeyLedPowerIndicator(KeyMask);
		}

		return;
#endif

	if(g_usOsdKeyDirectionType == _LAYER_NONE || g_usOsdKeyDirectionType == _LAYER_Timing_Tips)
		return ;
	
	SET_OSD_WINDOW_REFERENCE_DELAY(1);	// Map B
	
	switch(KeyMask)
	{
	
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)

		case _LEFT_KEY_MASK:
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
			{
#if(_5KEY_MENU_STYLE)
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) ,	PIXELROW(_KEY_INDEX_ROW), 
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3)-12 ,	PIXELROW(_KEY_INDEX_ROW + 2),
							_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

#else
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3-_KEY_ICON_WIDTH_OFFSET*3) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
#endif

			}
			else
#endif
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 1-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;
		
		case _RIGHT_KEY_MASK:
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
			{
#if(_5KEY_MENU_STYLE)
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) ,	PIXELROW(_KEY_INDEX_ROW), 
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3)-12 ,	PIXELROW(_KEY_INDEX_ROW + 2),
							_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

#else
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3-_KEY_ICON_WIDTH_OFFSET*3) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
#endif

			}
			else
#endif
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 1) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 1,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 2-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 1,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;
		
		case _MENU_KEY_MASK:
			
			//DebugMessageOsd("2.g_usOsdKeyDirectionType",g_usOsdKeyDirectionType);
			if(g_usOsdKeyDirectionType == _LAYER4_ADJ || (OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur]==_MENU_FUN_INFORMATION))
				;
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			else if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
			{
#if(_5KEY_MENU_STYLE)
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) ,	PIXELROW(_KEY_INDEX_ROW), 
							PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3)-12 ,	PIXELROW(_KEY_INDEX_ROW + 2),
							_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

#else
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 0) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3-_KEY_ICON_WIDTH_OFFSET*3) + _KEY_INDEX_OFFSET,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
#endif

			}
#endif
			else
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 2) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 2,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 2,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;

		case _EXIT_KEY_MASK:	
			
			if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_LANGUAGE_SELECT || OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT) // 退出键不能高亮
				;
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			else if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP_POWER * 1,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 4-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP_POWER * 1,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
#endif
			else
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 3) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 3,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 4-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 3,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;

		case _POWER_KEY_MASK:
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 4) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 2,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 5-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 2,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
			else
#endif
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 4) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 4,	PIXELROW(_KEY_INDEX_ROW), 
											PIXELCOL(_KEY_INDEX_COL + (_KEY_ICON_WIDTH) * 5-_KEY_ICON_WIDTH_OFFSET) + _KEY_INDEX_OFFSET + _KEY_INDEX_GAP * 4,	PIXELROW(_KEY_INDEX_ROW + 2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;

/**************************************_DEF_KEY_ROCKER********************************************/
#elif(_DEF_KEY_ROCKER)


		case _MIDDLE_KEY_MASK:
			OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
										PIXELCOL(_KEY_5_ICON_COL),	PIXELROW(_KEY_5_ICON_ROW), 
										PIXELCOL(_KEY_5_ICON_COL+4),PIXELROW(_KEY_5_ICON_ROW+2),
										_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

		break;

		case _UP_KEY_MASK:
			OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
										PIXELCOL(_KEY_3_ICON_COL),	PIXELROW(_KEY_3_ICON_ROW), 
										PIXELCOL(_KEY_3_ICON_COL+4),PIXELROW(_KEY_3_ICON_ROW+2),
										_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

		break;

		case _DOWN_KEY_MASK:
			OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
										PIXELCOL(_KEY_4_ICON_COL),	PIXELROW(_KEY_4_ICON_ROW), 
										PIXELCOL(_KEY_4_ICON_COL+4),PIXELROW(_KEY_4_ICON_ROW+2),
										_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);

		break;

		case _LEFT_KEY_MASK:
			if(g_usOsdKeyDirectionType == _LAYER_Timing_Tips)
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(0)+1,	PIXELROW(_KEY_1_ICON_ROW), 
											PIXELCOL(6),PIXELROW(_KEY_1_ICON_ROW+2),
											_NAVIGATION_KEY_SELECT_BG_COLORT, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
			else
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_1_ICON_COL),	PIXELROW(_KEY_1_ICON_ROW), 
											PIXELCOL(_KEY_1_ICON_COL+4),PIXELROW(_KEY_1_ICON_ROW+2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
		break;

		case _RIGHT_KEY_MASK:
			if(g_usOsdKeyDirectionType == _LAYER_Timing_Tips)
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_2_ICON_COL),	PIXELROW(_KEY_2_ICON_ROW), 
											PIXELCOL(_KEY_2_ICON_COL+6),PIXELROW(_KEY_2_ICON_ROW+2),
											_NAVIGATION_KEY_SELECT_BG_COLORT, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}
			else
			{
				OsdWindowDrawingHighlight(WINNO(_NAVIGATION_KEY_PRESS_WIN),
											PIXELCOL(_KEY_2_ICON_COL),	PIXELROW(_KEY_2_ICON_ROW), 
											PIXELCOL(_KEY_2_ICON_COL+4),PIXELROW(_KEY_2_ICON_ROW+2),
											_CP_BG, _NAVIGATION_KEY_SELECT_FONT_COLOR, _NAVIGATION_KEY_SELECT_BG_COLORT);
			}

		break;

#endif
		case _RELEASE_KEY_MASK:
		default:
			ScalerOsdWindowDisable(_NAVIGATION_KEY_PRESS_WIN);
			break;
	}
	SET_OSD_WINDOW_REFERENCE_DELAY(0);	// Map A
}




//--------------------------------------------------
// Description  : Convert keypad status into key message, stores in ucKeyNotify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageProc(void)
{
	
    switch(g_ucKeyStateCurr)
    {
    
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)

        case _MENU_KEY_MASK:
            CLR_KEYREPEATENABLE();
			if(g_usOsdKeyDirectionType == _LAYER4_ADJ || (g_usOsdKeyDirectionType == _LAYER2 && OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur] == _MENU_FUN_INFORMATION))
			{
				RTDKeyMessageConvert(_MENU_KEY_MASK, _NONE_KEY_MESSAGE);
			}
			else
			{
				RTDKeyPressHightLight(_MENU_KEY_MASK);
				RTDKeyMessageConvert(_MENU_KEY_MASK, _MENU_KEY_MESSAGE);

			}

            break;

        case _RIGHT_KEY_MASK:
			RTDKeyPressHightLight(_RIGHT_KEY_MASK);
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
				RTDKeyMessageConvert(_RIGHT_KEY_MASK, _MENU_KEY_MESSAGE);
			else
#endif
            RTDKeyMessageConvert(_RIGHT_KEY_MASK, _RIGHT_KEY_MESSAGE);
            break;

        case _LEFT_KEY_MASK:
			RTDKeyPressHightLight(_LEFT_KEY_MASK);
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
			if(g_usOsdKeyDirectionType == _LAYER_POWER_CONSUMPTION)
				RTDKeyMessageConvert(_LEFT_KEY_MASK, _MENU_KEY_MESSAGE);
			else
#endif
            RTDKeyMessageConvert(_LEFT_KEY_MASK, _LEFT_KEY_MESSAGE);
            break;

        case _EXIT_KEY_MASK:
            CLR_KEYREPEATENABLE();
			RTDKeyPressHightLight(_EXIT_KEY_MASK);
            RTDKeyMessageConvert(_EXIT_KEY_MASK, _EXIT_KEY_MESSAGE);
            break;

#if(_DEF_VGA_TIMING_KEY_2_4)
		case _SWITCH_MODE_KEY_MASK:
			 DebugMessageOsd("use_vga_t",1138);
			if((GET_OSD_STATE() == _MENU_NONE) && ( SysSourceGetSourceType() == _SOURCE_VGA) && (SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL))
			{
			    DebugMessageOsd("use_vga_t",1141);
				CLR_KEYREPEATENABLE();
				RTDKeyMessageConvert(_SWITCH_MODE_KEY_MASK, _SWITCH_MODE_KEY_MESSAGE);
			}
			break;
#endif		

/*********************************_DEF_KEY_ROCKER***********************************/
#elif(_DEF_KEY_ROCKER)

		

		case _MIDDLE_KEY_MASK:
			RTDKeyPressHightLight(_MIDDLE_KEY_MASK);
			if(g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT_NOSIGNAL)
			{
				//OsdDispDisableOsd();
				ScalerTimerReactiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
			}
			else
				RTDKeyMessageConvert(_MIDDLE_KEY_MASK, _MIDDLE_KEY_MESSAGE);
			/*if((g_usOsdKeyDirectionType != _LAYER_NONE) && (g_usOsdKeyDirectionType != _LAYER_Timing_Tips) && !((g_usOsdKeyDirectionType >= _LAYER_HOTKEY_VIEWMODE) && (g_usOsdKeyDirectionType <= _LAYER_HOTKEY_INPUT)))
			{
				OsdDispDisableOsd();
				RTDKeyHoldKeyTimerCancel();
			}
			else if(g_usOsdKeyDirectionType >= _LAYER_HOTKEY_VIEWMODE && g_usOsdKeyDirectionType <= _LAYER_HOTKEY_INPUT)
			{
				RTDKeyHoldKeyTimerCancel();
			}*/

			break;

		case _UP_KEY_MASK:
		case _DOWN_KEY_MASK:
		case _LEFT_KEY_MASK:
		case _RIGHT_KEY_MASK:

			if(KeyMaskRotate(g_ucKeyStateCurr) == _UP_KEY_MASK)
			{
				RTDKeyPressHightLight(g_ucKeyStateCurr);
				if( g_usOsdKeyDirectionType == _LAYER_SLIDER_ADJUST 
					|| g_usOsdKeyDirectionType == _LAYER4_ADJ 
					|| g_usOsdKeyDirectionType == _LAYER_VOLUME_ADJUST 
					|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_CONBRI
					|| (g_usOsdKeyDirectionType == _LAYER2 && GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
					)
					RTDKeyMessageConvert(g_ucKeyStateCurr, _EXIT_KEY_MESSAGE);
				else
					RTDKeyMessageConvert(g_ucKeyStateCurr, _UP_KEY_MESSAGE);

			}
			else if(KeyMaskRotate(g_ucKeyStateCurr) == _DOWN_KEY_MASK)
			{
				
				RTDKeyPressHightLight(g_ucKeyStateCurr);
				if(g_usOsdKeyDirectionType == _LAYER1 || g_usOsdKeyDirectionType == _LAYER_HOTKEY_CONBRI)
					RTDKeyMessageConvert(g_ucKeyStateCurr, _MENU_KEY_MESSAGE);
				else if(g_usOsdKeyDirectionType == _LAYER_SLIDER_ADJUST 
					|| g_usOsdKeyDirectionType == _LAYER4_ADJ 
					|| g_usOsdKeyDirectionType == _LAYER_VOLUME_ADJUST
					|| (g_usOsdKeyDirectionType == _LAYER2 && GetOsdShowType(GET_OSD_STATE()) == _TYPE_SLIDER)
					)
					RTDKeyMessageConvert(g_ucKeyStateCurr, _NONE_KEY_MESSAGE);
				else
					RTDKeyMessageConvert(g_ucKeyStateCurr, _DOWN_KEY_MESSAGE);

			}
			else if(KeyMaskRotate(g_ucKeyStateCurr) == _LEFT_KEY_MASK)
			{
	
				if(GET_KEY_LONG_PRESSED() == _TRUE)
				{	
					if(GET_KEY_TIME_FOR_SECOND() >= (_LOCK_KEY_TIME+1))
					{  
						SET_KEY_LONG_PRESSED(_FALSE);
						CLR_KEY_HOLD();
						CLR_KEYREPEATENABLE();
						RTDKeyMessageConvert(g_ucKeyStateCurr, _LOCK_KEY_MESSAGE);
						SET_OSD_LOCK_STATUS(!GET_OSD_LOCK_STATUS());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_OSD_LOCK_MSG);
						RTDNVRamSaveOSDData();
					}
				}
				else
				{
					RTDKeyPressHightLight(g_ucKeyStateCurr);				
	
					if(g_usOsdKeyDirectionType == _LAYER_HOTKEY_LANGUAGE || g_usOsdKeyDirectionType == _LAYER_HOTKEY_DISTRICT)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _NONE_KEY_MESSAGE);
#if(_DEF_KEY_ROCKER)				
					else if(g_usOsdKeyDirectionType == _LAYER2 && GetOsdShowType(GET_OSD_STATE())==_TYPE_SLIDER)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _LEFT_KEY_MESSAGE);
#endif
					else if(g_usOsdKeyDirectionType == _LAYER2|| g_usOsdKeyDirectionType == _LAYER3 || g_usOsdKeyDirectionType == _LAYER_HOTKEY_VIEWMODE \
						|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT || g_usOsdKeyDirectionType == _LAYER_NoFun || g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT_NOSIGNAL)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _EXIT_KEY_MESSAGE);
					else
						RTDKeyMessageConvert(g_ucKeyStateCurr, _LEFT_KEY_MESSAGE);


					DebugMessageOsd("8.GET_KEYMESSAGE", GET_KEYMESSAGE());
				}

			}
			else if(KeyMaskRotate(g_ucKeyStateCurr) == _RIGHT_KEY_MASK)
			{
				if(GET_KEY_LONG_PRESSED() == _TRUE)
				{
					if(GET_KEY_TIME_FOR_SECOND() >= (_LOCK_KEY_TIME+1))
					{
						SET_KEY_LONG_PRESSED(_FALSE);
						CLR_KEY_HOLD();
						CLR_KEYREPEATENABLE();
						RTDKeyMessageConvert(g_ucKeyStateCurr, _POWER_LOCK_KEY_MESSAGE);
						OsdFuncPowerKeyProc(!GET_OSD_PWKEY_LOCK_STATUS());
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_LOCK_MSG);
						RTDNVRamSaveOSDData();
					}
				}
				else
				{
					RTDKeyPressHightLight(g_ucKeyStateCurr);
	
					if(g_usOsdKeyDirectionType == _LAYER_NoFun)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _NONE_KEY_MESSAGE);
#if(_DEF_KEY_ROCKER)				
					else if(g_usOsdKeyDirectionType == _LAYER2 && GetOsdShowType(GET_OSD_STATE())==_TYPE_SLIDER)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _RIGHT_KEY_MESSAGE);
#endif
					else if(g_usOsdKeyDirectionType == _LAYER2 || g_usOsdKeyDirectionType == _LAYER3 
						|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_VIEWMODE || g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT || g_usOsdKeyDirectionType == _LAYER_HOTKEY_LANGUAGE \
						|| g_usOsdKeyDirectionType == _LAYER_HOTKEY_DISTRICT || g_usOsdKeyDirectionType == _LAYER_HOTKEY_INPUT_NOSIGNAL)
						RTDKeyMessageConvert(g_ucKeyStateCurr, _MENU_KEY_MESSAGE);
					
	
					else
						RTDKeyMessageConvert(g_ucKeyStateCurr, _RIGHT_KEY_MESSAGE);
				}

			}

			break;




#endif



#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
		case _AUTO_COLOR_KEY_MASK:
			//if(GET_OSD_STATE() == _MENU_NONE)
			if(GET_KEY_TIME_FOR_SECOND() >= 5)
			{
				CLR_KEYREPEATENABLE(); 
				OsdFontPut1BitTable(_OSD_MAP_B_ROW_OFFSET+_KEY_INDEX_ROW, _KEY_INDEX_COL + 1 + (_KEY_ICON_WIDTH + 1) * 2, tiOSD_OSDKEY_WBALANCE_ICON, COLOR(_CP_WHITE, _CP_DARKGRAY));
				//OsdDisplayKeyIndex(_LAYER1);
				ScalerTimerDelayXms(500);
				RTDKeyMessageConvert(_AUTO_COLOR_KEY_MASK, _AUTO_COLOR_KEY_MESSAGE);
			}
			break;
#endif


        case _POWER_KEY_MASK:
            CLR_KEYREPEATENABLE();
			RTDKeyPressHightLight(_POWER_KEY_MASK);
            RTDKeyMessageConvert(_POWER_KEY_MASK, _NONE_KEY_MESSAGE);
			if(g_usOsdKeyDirectionType != _LAYER_NONE)
        	{
#if(_5KEY_MENU_STYLE)  //2025.2.13  tx wan
			    ScalerTimerDelayXms(_KEY_DELAYED_TIME); 
#endif
				OsdDispDisableOsd();
			}
#if(_5KEY_MENU_STYLE)  
			else if(ScalerOsdGetOsdEnable())
			{
				OsdDispDisableOsd();
			}
			else if(GET_OSD_STATE() == _OSD_MSG_INPUT_SOURCE)
			{
				OsdDispDisableOsd();
			}
#endif
            break;

		case _LOCK_KEY_MASK:

            if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
            {
			    if(GET_KEY_TIME_FOR_SECOND() >= _LOCK_KEY_TIME)
    			{
                	CLR_KEYREPEATENABLE();
                	RTDKeyMessageConvert(_LOCK_KEY_MASK, _LOCK_KEY_MESSAGE);
                }
            }
			break;
		
		case _POWER_LOCK_KEY_MASK:
			
			if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
			{
				if((GET_OSD_STATE() == _MENU_NONE) && (GET_AUTO_POWEROFF_STATUS() == _TRUE))
				{
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_AUTO_POWER_OFF_MSG);
				}
				
				if(GET_AUTO_POWEROFF_STATUS() == _FALSE)
				{
					if(GET_KEY_TIME_FOR_SECOND() >= _LOCK_KEY_TIME)
					{
						CLR_KEYREPEATENABLE();
						RTDKeyMessageConvert(_POWER_LOCK_KEY_MASK, _POWER_LOCK_KEY_MESSAGE);
					}
				}
			}
			break;
		
		case _LOGO_BOOTUP_KEY_MASK:
			if((GET_OSD_STATE() == _MENU_NONE) && SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
			{
				SET_KEYREPEATENABLE();
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_LOGOBOOTUP_MSG);
				//SET_OSD_STATE(_OSD_HOTKEY_BLUELIGHT); 	//_OSD_HOTKEY_BLUELIGHT 没用到,暂时用一下
#else
				SET_FACTORY_FORCE_LOGO_OFF(!GET_FACTORY_FORCE_LOGO_OFF());
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_LOGOBOOTUP_MSG);
				TPVNVRamSaveFactoryDate();
#endif
				RTDKeyMessageConvert(_LOGO_BOOTUP_KEY_MASK, _LOGO_BOOTUP_KEY_MESSAGE);
			}
			break;


        default:
            if((g_ucKeyStateCurr == _RELEASE_KEY_MASK) &&
               (g_ucKeyStatePrev != _RELEASE_KEY_MASK))
            {
                RTDKeyHoldKeyCheck(); // Check key release
                RTDKeyPressHightLight(_RELEASE_KEY_MASK);
            }

            CLR_KEYREPEATSTART();
            CLR_KEYREPEATENABLE();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
			if(GET_KEY_COMBINE() == _TRUE)
            {
            	SET_KEY_COMBINE(_FALSE);
            	OsdDispDisableOsd();
            }
#endif
            break;
    }
}



//--------------------------------------------------
// Description  : Hot Key message execute
// Input Value  : ucKeyMsg      --> Key message

// Output Value : None
//--------------------------------------------------
void RTDKeyMessageExecute(BYTE ucKeyMsg)
{
	switch(ucKeyMsg)
	{
		case _LOCK_KEY_MESSAGE:
			SET_OSD_LOCK_STATUS(!GET_OSD_LOCK_STATUS());
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_OSD_LOCK_MSG);
			RTDNVRamSaveOSDData();
			break;

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
		case _AUTO_COLOR_KEY_MESSAGE:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_COLOR_MSG);
			break;
#endif


		case _POWER_LOCK_KEY_MESSAGE:
#if 0//(_AUTO_SLEEP_SUPPORT == _ON)
			if(GET_AUTO_SLEEP_STATUS() != _SLEEP_OFF)
			{
				OsdSleepFunOffSet();
			}
#endif

			SET_OSD_PWKEY_LOCK_STATUS(!GET_OSD_PWKEY_LOCK_STATUS());
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_LOCK_MSG);
			RTDNVRamSaveOSDData();
			break;

		//case _SWITCH_MODE_KEY_MESSAGE:
			//SET_OSD_EVENT_MESSAGE(_OSDEVENT_SWITCHMODE_MSG);
			//break;

#if(_DEF_VGA_TIMING_KEY_2_4)
		case _SWITCH_MODE_KEY_MESSAGE:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SWITCHMODE_MSG);
			break;
#endif


#if(0)

		#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
		case _AUTO_COLOR_KEY_MESSAGE:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_COLOR_MSG);
			break;
		#endif

		case _LOGO_BOOTUP_KEY_MESSAGE:
#if(_DEF_HotOSD_Logo_MessageEanble_swtich)
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_LOGOBOOTUP_MSG);
			//SET_OSD_STATE(_OSD_HOTKEY_BLUELIGHT);		//_OSD_HOTKEY_BLUELIGHT 没用到,暂时用一下
#else
			SET_FACTORY_FORCE_LOGO_OFF(!GET_FACTORY_FORCE_LOGO_OFF());
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_LOGOBOOTUP_MSG);
			TPVNVRamSaveFactoryDate();
#endif
			break;
/*
		case _DDCCI_KEY_MESSAGE:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG);
			break;

		case _RECALL_DEFAULT_KEY_MESSAGE:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_RECALL_MODE_MSG);
			break;
*/


		case _FACTORY_BRIGHTNESS_HOTKEY_MESSAGE:
			if(usCurrentContrast != _CONTRAST_MAX)
			{
			    UserAdjustBacklight(_BACKLIGHT_MAX);
                         UserAdjustContrast(_CONTRAST_MAX);
			}
			else
			{
			    UserAdjustBacklight(_OSD_BACKLIGHT_DEFAULE);
                         UserAdjustContrast(_CONTRAST_DEFAULT);
			}
			
			break;
/*
		case _FACTORY_VOLUME_HOTKEY_MESSAGE:
			if(ucCurrentVolume != _OSD_VOLUME_MAX)
			{
                         UserAdjustAudioVolume(_OSD_VOLUME_MAX);
			}
			else
			{
                         UserAdjustAudioVolume(_VOLUME_DEFAULT);
			}
			
			break;
*/
	
#endif
		default:
			SET_KEYMESSAGE(ucKeyMsg);
			break;
	}

	
}


//--------------------------------------------------
// Description  : Key message translation
// Input Value  : ucKeyMask     --> Key mask
//                ucKeyMsg      --> Key message
// Output Value : None
//--------------------------------------------------
void RTDKeyMessageConvert(BYTE ucKeyMask, BYTE ucKeyMsg)
{

    // Key different
    if((g_ucKeyStatePrev != g_ucKeyStateCurr) && (ucKeyMask == g_ucKeyStateCurr))
    {
        // KeyLock function
        if (RTDKeySpecialProc(ucKeyMask) == _FALSE)
        {
            //SET_KEYMESSAGE(ucKeyMsg);
			
			RTDKeyMessageExecute(ucKeyMsg);
            RTDKeyHoldKeyTimerCancel();

			
#if(_DEF_OSD_CURSOR_FLICKER_TIPS)
			if(g_OsdCursorFlickerTips_Num)
			{
				g_OsdCursorFlickerTips_Num = 0x60;
				OsdDisplayCursorFlickerTipFun();
				g_OsdCursorFlickerTips_Num = 0;
			}
#endif

        }
    }
    else // Key the same
    {
        if(GET_KEYREPEATENABLE() == _TRUE)
        {
            if(GET_KEYREPEATSTART() == _TRUE)
            {
                SET_KEYMESSAGE(ucKeyMsg);
            }
            else
            {
                // Set repeat key after 500ms.
                ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_KEY_REPEAT_ENABLE);
            }
        }
    }
}



//--------------------------------------------------
// Description  :  for special key check
// Input Value  : scan Key data
// Output Value : None
//--------------------------------------------------
bit RTDKeySpecialProc(BYTE ucKeyMask)
{

#if(_DEF_KEY_ROCKER)
	if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING) && (ucKeyMask == _MIDDLE_KEY_MASK))
	{
		if(GET_OSD_PWKEY_LOCK_STATUS() == _TRUE)
		{
			if((GET_OSD_LOGO_ON() == _OFF)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE) )
			{
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_LOCK_MSG);
			}
		}
		else
		{
			SET_FACTORY_MODE(_OFF);
			SET_FACTORY_BURNIN(_OFF);
			TPVNVRamSaveFactoryDate();

			//if(GET_AUTO_SLEEP_STATUS() != _SleepPowerSaving_OFF)
			{
				//SET_AUTO_SLEEP_STATUS(_SleepPowerSaving_OFF);
				//RTDNVRamSaveOSDData();
			}
			
			SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
		}
		return _TRUE;

	}

	if((SysPowerGetPowerStatus() != _POWER_STATUS_OFF) && (ucKeyMask == _MIDDLE_KEY_MASK))
	{
		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_POWER_DOWN);
		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE();
		return _TRUE;
	}



	if((SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL) && (KeyMaskRotate(ucKeyMask) == _LEFT_KEY_MASK) && (GET_OSD_STATE() == _MENU_NONE) && (OsdDisplayCheckkeyValid() == _TRUE))
	{
		ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_SHOW_OSD_LOCKING_STATUS_MSG);
		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE();
		
		return _TRUE;
	}
	

	if((SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL) && (KeyMaskRotate(ucKeyMask) == _RIGHT_KEY_MASK) && (GET_OSD_STATE() == _MENU_NONE) && (OsdDisplayCheckkeyValid() == _TRUE) && (!GET_OSD_LOCK_STATUS()))
	{
		ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG);
		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE();
		
		return _TRUE;
	}

	if((SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL) && (KeyMaskRotate(ucKeyMask) == _UP_KEY_MASK) && (GET_OSD_STATE() == _MENU_NONE) && (OsdDisplayCheckkeyValid() == _TRUE) && (!GET_OSD_LOCK_STATUS()))
	{
		ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_LOGO_BOOTUP_STATUS_MSG);
		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE();
		
		return _TRUE;
	}
#elif(_DEF_JS_KEY_ICON_5_KEY_MODE)

#if(_DEF_LONG_PRESS_POWER_OFF_3_SEC)

  	if((SysPowerGetPowerStatus() != _POWER_STATUS_OFF) && (ucKeyMask == _POWER_KEY_MASK))
	{ 
	
		ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_POWER_DOWN);
		SET_KEY_HOLD();
		CLR_KEYREPEATENABLE();
		return _TRUE;
	}	
#endif

#endif

/*
    if((GET_OSD_STATE() == _MENU_NONE) && (ucKeyMask == _LEFT_KEY_MASK))
    {
#if(_DP_SUPPORT == _ON)
        ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT);
        SET_KEY_HOLD();
        CLR_KEYREPEATENABLE();
        return _TRUE;
#endif
    }
*/

#if(_VGA_SUPPORT == _ON)
    // Press Exit key for 3 sec to do Auto color

   //else if????
   if((GET_OSD_STATE() == _MENU_NONE) && (SysSourceGetSourceType() == _SOURCE_VGA))
    {
        if (ucKeyMask == _MENU_KEY_MASK)
        {
            ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_DO_AUTO_COLOR);
            SET_KEY_HOLD();
            CLR_KEYREPEATENABLE();
            return _TRUE;
        }
    }
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyHoldKeyTimerCancel(void)
{
    if(GET_KEY_HOLD() == _TRUE)
    {
        CLR_KEY_HOLD();

        // list all off hold key timer event here!!!
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN);
#if(_DP_SUPPORT == _ON)
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT);
#endif
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_OSD_LOCKING_STATUS_MSG);
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG);
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_LOGO_BOOTUP_STATUS_MSG);
        SET_KEY_LONG_PRESSED(_FALSE);
    }
}

//--------------------------------------------------
// Description  : Hold Key check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDKeyHoldKeyCheck(void)
{
    if(GET_KEY_HOLD() == _TRUE)
    {
        switch(KeyMaskRotate(g_ucKeyStatePrev))
        {
            case _EXIT_KEY_MASK:
                SET_KEYMESSAGE(_EXIT_KEY_MESSAGE);
                break;
				
#if(_DEF_JS_KEY_ICON_5_KEY_MODE)            
			case _MENU_KEY_MASK:
                SET_KEYMESSAGE(_MENU_KEY_MESSAGE);
                break;
#elif(_DEF_KEY_ROCKER)
			case _MIDDLE_KEY_MASK:
			case _MENU_KEY_MASK:
				//if(!(g_usOsdKeyDirectionType >= _LAYER_HOTKEY_VIEWMODE && g_usOsdKeyDirectionType <= _LAYER_HOTKEY_INPUT))
					//SET_KEYMESSAGE(_MENU_KEY_MESSAGE); //_MIDDLE_KEY_MESSAGE
					
				if(g_usOsdKeyDirectionType >= _LAYER_HOTKEY_VIEWMODE && g_usOsdKeyDirectionType <= _LAYER_HOTKEY_INPUT)
				{
					SET_KEYMESSAGE(_NONE_KEY_MESSAGE); 
				}				
				else if(g_usOsdKeyDirectionType == _LAYER_HOTKEY_LANGUAGE || g_usOsdKeyDirectionType == _LAYER_HOTKEY_DISTRICT)
				{
					SET_KEYMESSAGE(_EXIT_KEY_MESSAGE); 
				}
				else if(g_usOsdKeyDirectionType > _LAYER_NONE && g_usOsdKeyDirectionType < _LAYER_HOTKEY_VIEWMODE  \
					|| g_usOsdKeyDirectionType ==_LAYER_VOLUME_ADJUST || g_usOsdKeyDirectionType ==  _LAYER_NoFun)
				{
					 OsdDispDisableOsd();
				}
				else if(g_usOsdKeyDirectionType == _LAYER_NONE)
				{
					 SET_KEYMESSAGE(_MENU_KEY_MESSAGE); 
				}
				break;

#endif

            case _RIGHT_KEY_MASK:
                SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);
                break;
            case _LEFT_KEY_MASK:
                SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);
                break;			
			case _UP_KEY_MASK:
                SET_KEYMESSAGE(_UP_KEY_MESSAGE);
                break;
            case _DOWN_KEY_MASK:
                SET_KEYMESSAGE(_DOWN_KEY_MESSAGE);
                break;

           // case _POWER_KEY_MASK:
               // SET_KEYMESSAGE(_POWER_KEY_MESSAGE);
               // break;
            default:
                break;
        }
#if(_DEF_KEY_ROCKER)
		SET_KEY_COMBINE(_FALSE);
#endif
        RTDKeyHoldKeyTimerCancel();
    }
}


#if(_IR_SUPPORT == _IR_HW_SUPPORT)
//--------------------------------------------------
// Description  : IR Key Scan
// Input Value  : None
// Output Value : Key Mask
//--------------------------------------------------
BYTE RTDIRKeyScan(void)
{
    BYTE pucIRCodeBuffer[8] = {0};
    WORD usKeyCode = 0;
    BYTE ucKeyState = 0;

    if(ScalerIRHWModeGetData(pucIRCodeBuffer) == _TRUE)
    {
#if(_IR_PROTOCAL == _IR_NEC_DTV328)
        if((pucIRCodeBuffer[0] == ~(pucIRCodeBuffer[1])) && (pucIRCodeBuffer[2] == ~(pucIRCodeBuffer[3])))
        {
            usKeyCode = (((WORD)pucIRCodeBuffer[3]) << 8) + pucIRCodeBuffer[1];
        }

#elif(_IR_PROTOCAL == _IR_SONY_B102P)
        usKeyCode = (((WORD)pucIRCodeBuffer[0]) << 8) + pucIRCodeBuffer[1];

#elif(_IR_PROTOCAL == _IR_PHILIPS_RC6)
        usKeyCode = (((WORD)pucIRCodeBuffer[2]) << 8) + pucIRCodeBuffer[3];

#endif // End of #if(_IR_PROTOCAL == _IR_NEC_DTV328)

        switch(usKeyCode)
        {
            case _IR_CODE_KEY_POWER:
                ucKeyState = _POWER_KEY_MASK;
                break;

            case _IR_CODE_KEY_MENU:
                ucKeyState = _MENU_KEY_MASK;
                break;

            case _IR_CODE_KEY_RIGHT:
                ucKeyState = _RIGHT_KEY_MASK;
                break;

            case _IR_CODE_KEY_LEFT:
                ucKeyState = _LEFT_KEY_MASK;
                break;

            case _IR_CODE_KEY_EXIT:
                ucKeyState = _EXIT_KEY_MASK;
                break;

            default:
                ucKeyState = 0x00;
                break;
        }
    }

    return ucKeyState;
}
#endif // End of #if(_IR_SUPPORT == _IR_HW_SUPPORT)


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void KeyLedPowerIndicator(BYTE ucGetKey)
{
	if((SysModeGetModeState() != _MODE_STATUS_ACTIVE)
	|| (GET_FACTORY_MODE() == _TRUE)
	#if 0//(_FACTORY_MODE_OWNER == _OWNER_TPV)
	|| ((TPVDFMModeFlag() == _TRUE)
		#if(_AMBIGLOW_TYPE == _ENE_SOLUTION)
		&& (SysModeGetModeState() != _MODE_STATUS_ACTIVE)
		#endif
		)
	#endif
	)
	{
		return;
	}

#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	if((GET_POWER_INDICATOR() == _OFF) && (ucGetKey != 0))
	{  
		UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);

		ScalerTimerActiveTimerEvent(SEC(0.3), _USER_TIMER_EVENT_POWER_INDICATOR);
	}
#elif(_DEF_KEY_ROCKER)
	if(ucGetKey != _RELEASE_KEY_MASK)
	{  
		UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
	}
	else
	{
		UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
	}
#endif

}


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
BYTE KeyMaskRotate(BYTE ucKeyMask)
{
	switch (GET_OSD_ROTATE_STATUS())
	{
		case _OSD_ROTATE_DEGREE_90:
		switch (ucKeyMask)
		{
			case _UP_KEY_MASK:
				ucKeyMask = _LEFT_KEY_MASK;
				break;
			case _DOWN_KEY_MASK:
				ucKeyMask = _RIGHT_KEY_MASK;
				break;
			case _LEFT_KEY_MASK:
				ucKeyMask = _DOWN_KEY_MASK;
				break;
			case _RIGHT_KEY_MASK:
				ucKeyMask = _UP_KEY_MASK;
				break;
			default:
				break;
		}
		break;
		
		case _OSD_ROTATE_DEGREE_270:
		switch (ucKeyMask)
		{
			case _UP_KEY_MASK:
				ucKeyMask = _RIGHT_KEY_MASK;
				break;
			case _DOWN_KEY_MASK:
				ucKeyMask = _LEFT_KEY_MASK;
				break;
			case _LEFT_KEY_MASK:
				ucKeyMask = _UP_KEY_MASK;
				break;
			case _RIGHT_KEY_MASK:
				ucKeyMask = _DOWN_KEY_MASK;
				break;
			default:
				break;
		}
		break;
		
	case _OSD_ROTATE_DEGREE_180:
		switch (ucKeyMask)
		{
			case _UP_KEY_MASK:
				ucKeyMask = _DOWN_KEY_MASK;
				break;
			case _DOWN_KEY_MASK:
				ucKeyMask = _UP_KEY_MASK;
				break;
			case _LEFT_KEY_MASK:
				ucKeyMask = _RIGHT_KEY_MASK;
				break;
			case _RIGHT_KEY_MASK:
				ucKeyMask = _LEFT_KEY_MASK;
				break;
			default:
				break;
		}
		break;
		
	default:
		break;
	}

	return ucKeyMask;
}



#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
