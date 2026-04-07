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

#define __RTD2011_ALIGN__

#include "UserCommonInclude.h"


extern void OsdDispOsdReset(void);
bit ddcci_reset=0;

#if(_CTX_TPV==_OFF)

#if(_DEF_DDCCI_WB_TOOL)

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

bit ubAutoAlign=_FALSE;

void RTDDdcciAutoAlignPro(void);
extern void RTDDdccireply(BYTE Flag);
//*****************************************************

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CAlignSendAckCmd(BYTE Status)
{

	if(Status == _SUCCESS)
	{
		g_pucDdcciTxBuf[0] = 0x6E;
		g_pucDdcciTxBuf[1] = 0x82;	
		g_pucDdcciTxBuf[2] = 0x00;	
		g_pucDdcciTxBuf[3] = 0x4f;
		g_pucDdcciTxBuf[4] =0xF3;
	}
	else
	{
		g_pucDdcciTxBuf[0] = 0x6E;
		g_pucDdcciTxBuf[1] = 0x82;	
		g_pucDdcciTxBuf[2] = 0x03;	
		g_pucDdcciTxBuf[3] = 0x58;
		g_pucDdcciTxBuf[4] =0xE7;

	}



    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
	ScalerMcuDdcciReleaseScl();

}




bit IS_OSD_RESET(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x01));
}

bit IS_AUTO_COLOR(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x02));
}
/********************************************************************/
bit IS_TEST_LIGHTMAX(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x03));
}

bit IS_LOAD_RGB(void)
{
	return ((g_pucDdcciRxBuf[4]==0xff)&&(g_pucDdcciRxBuf[5]==0x04));
}
bit IS_ALIGN_FINISH(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x05));
}

bit IS_TIME_CLEAR(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x06));
}

bit IS_CHANGE_LANGUAGE(void)
{
	return ((g_pucDdcciRxBuf[4]==0xFF)&&(g_pucDdcciRxBuf[5]==0x07));
}
	


bit IS_START(void)
{
	return ((g_pucDdcciRxBuf[4]==0xff)&&(g_pucDdcciRxBuf[5]==0xFF));
}

/*******************************************************************/

bit IS_RGB_ADJ(void)
{
	return ((g_pucDdcciRxBuf[4]==0x20)&&(g_pucDdcciRxBuf[5]==0x01));
}

/*******************************************************************/
bit IS_SAVE_9300(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x00));
}

bit IS_SAVE_7500(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x01));
}

bit IS_SAVE_6500(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x02));
}

bit IS_SAVE_5800(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x03));
}

bit IS_SAVE_sRGB(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x04));
}

bit IS_SAVE_USER(void)
{
	return ((g_pucDdcciRxBuf[4]==0x30)&&(g_pucDdcciRxBuf[5]==0x05));
}


//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDDdcciAutoAlignPro(void)
{  
	
	BYTE uctempData,ucR_Gain,ucG_Gain,ucB_Gain;

/************************FUNC***********************************/
	if(IS_TIME_CLEAR())//清除时间
	{
		SET_PANEL_TIME_HOUR(0);
		SET_PANEL_TIME_MIN(0);
		CAlignSendAckCmd(_SUCCESS); 
	}
	else if(IS_CHANGE_LANGUAGE())
	{
		SET_OSD_LANGUAGE(g_pucDdcciRxBuf[6]);
		//SET_OSD_LANGUAGE_INIT(g_pucDdcciRxBuf[6]);
		RTDNVRamSaveOSDData();
		RTDDdccireply(_TRUE);
	}

	else if(IS_OSD_RESET())
	{
		OsdDispOsdReset();
		RTDDdccireply(_TRUE);
	}
	else if(IS_AUTO_COLOR())
	{

#if(_VGA_SUPPORT != _ON)
		RTDDdccireply(0X02);
		return;
#endif
		if(SysSourceGetSourceType() != _SOURCE_VGA)
		{	
			RTDDdccireply(_FALSE);
		}
		else
		{

#if(_VGA_SUPPORT == _ON)
			//OsdDisplayAutoBalanceProc();
			OsdDisplayAutoBalanceProc_DDCCI();

			RTDDdccireply(_TRUE);
#endif
		}
	}

/****************************CT**********************************/
	else  if(IS_TEST_LIGHTMAX())
	{

	   if(ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_BUININ_MSG) == _TRUE)
	   {
		   ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BUININ_MSG);
		   OsdFuncDisableOsd();
		   ScalerDDomainPatternGenAdjustColor(255,255,255);
		   ScalerDDomainPatternGenEnable(_ENABLE);
		   ScalerDDomainBackgroundEnable(_DISABLE);
	   
	   }
	   else
	   {
		   OsdFuncDisableOsd();
	   }			   
	   SET_COLOR_TEMP_TYPE_USER_R(128);
	   SET_COLOR_TEMP_TYPE_USER_G(128);
	   SET_COLOR_TEMP_TYPE_USER_B(128);
	   UserAdjustContrast(_CONTRAST_DEFAULT);
	   UserAdjustBacklight(100);
	   RTDDdccireply(_TRUE);
	}
	else  if(IS_START())
	{
	   
	   RTDNVRamRestoreBriCon();

	   UserAdjustBacklight(GET_OSD_BACKLIGHT());
		//UserAdjustBrightness(GET_OSD_BRIGHTNESS());	   
	   RTDDdccireply(_TRUE);
	   
	}
	else  if(IS_LOAD_RGB())
	{

	   SET_COLOR_TEMP_TYPE_USER_R(g_pucDdcciRxBuf[6]);
	   SET_COLOR_TEMP_TYPE_USER_G(g_pucDdcciRxBuf[7]);
	   SET_COLOR_TEMP_TYPE_USER_B(g_pucDdcciRxBuf[8]); 
	   UserAdjustContrast(GET_OSD_CONTRAST());
	   RTDDdccireply(_TRUE);
	}
/************************************R G B**************************/	 
	else if(IS_RGB_ADJ())
	{

		SET_COLOR_TEMP_TYPE_USER_R(g_pucDdcciRxBuf[6]);
		SET_COLOR_TEMP_TYPE_USER_G(g_pucDdcciRxBuf[7]);
		SET_COLOR_TEMP_TYPE_USER_B(g_pucDdcciRxBuf[8]); 

		UserAdjustContrast(GET_OSD_CONTRAST());
		RTDDdccireply(_TRUE);
	}
/***********************************SAVE****************************/
	else  if(IS_SAVE_9300())
	{

		SET_COLOR_TEMP_TYPE(_CT_9300);
		RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
		RTDDdccireply(_TRUE);
	}
	else  if(IS_SAVE_7500())
	{

		SET_COLOR_TEMP_TYPE(_CT_7500);
		RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
		RTDDdccireply(_TRUE);
	}
	else  if(IS_SAVE_6500())
	{
		RTDDdccireply(_TRUE);
		 SET_COLOR_TEMP_TYPE(_CT_6500);
		 RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
		 
	 }
	 else  if(IS_SAVE_5800())
	 {

		SET_COLOR_TEMP_TYPE(_CT_5000);
		RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
#if(_DEF_COLOR_TEMP_SRGB_EANBLE)
		UserAdjustBacklight(_SRGB_BACKLIGHT);//?SRGB??
#endif
		RTDDdccireply(_TRUE);
	}
#if(_DEF_CT_SRGB_SUPPIRT == _ON)
	else  if(IS_SAVE_sRGB())
	{
		SET_COLOR_TEMP_TYPE(_CT_SRGB);
		RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
#if(_DEF_COLOR_TEMP_SRGB_EANBLE)
		UserAdjustBacklight(_OSD_BACKLIGHT_DEFAULE);//????
#endif
		RTDDdccireply(_TRUE);
	}
#endif
	else  if(IS_SAVE_USER())
	{
#if(_DEF_DDC_COLOR_USER_4500)
		SET_COLOR_TEMP_TYPE(_CT_4500);
#else
		SET_COLOR_TEMP_TYPE(_CT_USER);
#endif
		RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
		 if(DFM_BURN_IN())
		 {
			 //ScalerTimerActiveTimerEvent(SEC(0.01),_USER_TIMER_EVENT_BUININ_MSG);
			 //OsdFuncEnableOsd();
			 SET_FACTORY_BURNIN(_OFF);
			 SET_FACTORY_MODE(_OFF);
			 TPVNVRamSaveFactoryDate();
		 }
		RTDDdccireply(_TRUE);
	}
	else  if(IS_ALIGN_FINISH())
	{

		SET_COLOR_TEMP_TYPE(_COLORTEMP_DEFAULT);	// 20211019
		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
		UserAdjustContrast(_CONTRAST_DEFAULT);
		//if(DFM_BURN_IN() && SysModeGetModeState() == _MODE_STATUS_NOSIGNAL)
		if(GET_FACTORY_BURNIN() && SysModeGetModeState() == _MODE_STATUS_ACTIVE)					
		{
			//ScalerTimerActiveTimerEvent(SEC(0.01),_USER_TIMER_EVENT_BUININ_MSG);
			//OsdFuncEnableOsd();
			OsdFuncDisableOsd();
			SET_FACTORY_MODE(_OFF);
			SET_FACTORY_BURNIN(_OFF);
			 TPVNVRamSaveFactoryDate();
			UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
		}
		else if((SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) && (GET_FACTORY_BURNIN() == _ON))
		{
			ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BURN_IN_DDCTOOL);
				
    	}
		RTDNVRamSaveOSDData();
		RTDDdccireply(_TRUE);
	}
	else if(IS_TIME_CLEAR())
	{
	
		RTDDdccireply(_TRUE);
	}

	else if(IS_CHANGE_LANGUAGE())
	{

		RTDDdccireply(_TRUE);
	}
//*******************************JRY Command**********************// 
	else
	{
		//DDcciOsdDispOsdMessage();
		if(ubAutoAlign==0)
		{
			if((g_pucDdcciRxBuf[4]==0x35)&&(g_pucDdcciRxBuf[5]==0x1f)&&(g_pucDdcciRxBuf[6]==0))//enter align mode
			{

			    ubAutoAlign=1;
			    CAlignSendAckCmd(_SUCCESS);

		  			return ;
			}
			else
			{
				//OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);
				return ;
			}
		 }

		//OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);

		if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x13)&&(g_pucDdcciRxBuf[6]==0))//auto color
		{
#if(_VGA_SUPPORT == _ON)

			if(SysSourceGetSourceType() == _SOURCE_VGA)
			{
		        if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) != _AUTO_SUCCESS)       
				{
				
					CAlignSendAckCmd(_FAIL);
				}
				else
				{
	    
					
	            ScalerAutoGetAutoColorResult(&g_stAdcData);
	  
	            //If you want add ADC offset , please refer _PANEL_ADC_OFFSET_BIAS

	            // Adjust ADC gain for user define
	            // ===============================================================
	            g_stAdcData.pucAdcGainMSB[0] = g_stAdcData.pucAdcGainMSB[0];
	            g_stAdcData.pucAdcGainMSB[1] = g_stAdcData.pucAdcGainMSB[1];
	            g_stAdcData.pucAdcGainMSB[2] = g_stAdcData.pucAdcGainMSB[2];
				
	            // Adjust ADC OFFSET for user define
	            // ===============================================================
	            g_stAdcData.pucAdcOffsetMSB[0] = g_stAdcData.pucAdcOffsetMSB[0];
	            g_stAdcData.pucAdcOffsetMSB[1] = g_stAdcData.pucAdcOffsetMSB[1];
	            g_stAdcData.pucAdcOffsetMSB[2] = g_stAdcData.pucAdcOffsetMSB[2];
				
	           UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
				
					CAlignSendAckCmd(_SUCCESS);
				}
			}
#endif
		        
		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==0))//set CT
		{

			SET_COLOR_TEMP_TYPE(_CT_9300);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==1))//set CT
		{

			SET_COLOR_TEMP_TYPE(_CT_6500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			CAlignSendAckCmd(_SUCCESS);

		}
#if  1//Adj_5400K_Temp	
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==2))//set CT
		{

			SET_COLOR_TEMP_TYPE(_CT_5000);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			CAlignSendAckCmd(_SUCCESS);

		}
#endif

#if 1//Adj_7500K_Temp	
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==3))//set CT
		{
				
			SET_COLOR_TEMP_TYPE(_CT_7500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
	        CAlignSendAckCmd(_SUCCESS);

		}
#endif
#if(_DEF_CT_SRGB_SUPPIRT == _ON)
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==4))//set CT
		{
				
			SET_COLOR_TEMP_TYPE(_CT_SRGB);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			//UserAdjustBacklight(GET_OSD_BRIGHTNESS());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
	        CAlignSendAckCmd(_SUCCESS);

		}
#endif
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x14)&&(g_pucDdcciRxBuf[6]==5))//set CT
		{
#if(_DEF_DDC_COLOR_USER_4500)
			SET_COLOR_TEMP_TYPE(_CT_4500);
#else
			SET_COLOR_TEMP_TYPE(_CT_USER);
#endif
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		     CAlignSendAckCmd(_SUCCESS);
		}
		else if((g_pucDdcciRxBuf[4]==0x32)&&(g_pucDdcciRxBuf[5]==0x15))//read R gain
		{

			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1] = 0x82;
			g_pucDdcciTxBuf[2] = 0x00;	
			g_pucDdcciTxBuf[3] = GET_COLOR_TEMP_TYPE_USER_R();
			g_pucDdcciTxBuf[4] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			
		}
		else if((g_pucDdcciRxBuf[4]==0x32)&&(g_pucDdcciRxBuf[5]==0x16))//read G gain
		{

			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1] = 0x82;
			g_pucDdcciTxBuf[2] = 0x00;	
			g_pucDdcciTxBuf[3] = GET_COLOR_TEMP_TYPE_USER_G();
			g_pucDdcciTxBuf[4] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if((g_pucDdcciRxBuf[4]==0x32)&&(g_pucDdcciRxBuf[5]==0x17))//read B gain
		{

			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1] = 0x82;
			g_pucDdcciTxBuf[2] = 0x00;	
			g_pucDdcciTxBuf[3] = GET_COLOR_TEMP_TYPE_USER_B();
			g_pucDdcciTxBuf[4] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x15))//write R gain
		{

			ucR_Gain=g_pucDdcciRxBuf[6];
			if((ucR_Gain >= 0) && (ucR_Gain <= 255))
			{

			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
				CAlignSendAckCmd(_SUCCESS);
			    SET_COLOR_TEMP_TYPE_USER_R(ucR_Gain);
				UserAdjustContrast(GET_OSD_CONTRAST());

			}
			else
			{
				CAlignSendAckCmd(_FAIL);
			}
					
		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x16))//write G gain
		{

			ucG_Gain=g_pucDdcciRxBuf[6];
			if((ucG_Gain >= 0) && (ucG_Gain <= 255))
			{
			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
				CAlignSendAckCmd(_SUCCESS);
				SET_COLOR_TEMP_TYPE_USER_G(ucG_Gain);
				UserAdjustContrast(GET_OSD_CONTRAST());

			}
			else
			{
				CAlignSendAckCmd(_FAIL);
			}	

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x17))//write B gain
		{

			ucB_Gain=g_pucDdcciRxBuf[6];
			if((ucB_Gain >= 0) && (ucB_Gain <= 255))
			{

			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
				CAlignSendAckCmd(_SUCCESS);
		        SET_COLOR_TEMP_TYPE_USER_B(ucB_Gain);
				UserAdjustContrast(GET_OSD_CONTRAST());

			}
			else
			{
				CAlignSendAckCmd(_FAIL);
			}
		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==0))//save CT
		{

			RTDNVRamSaveColorSetting(_CT_9300);
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==1))//save CT
		{

			RTDNVRamSaveColorSetting(_CT_6500);//GET_COLOR_TEMP_TYPE(GET_OSD_SELECT_REGION())
			CAlignSendAckCmd(_SUCCESS);

		}
#if 1
		//Adj_5000K_Temp	
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==2))//save CT
		{

			RTDNVRamSaveColorSetting(_CT_5000);//GET_COLOR_TEMP_TYPE(GET_OSD_SELECT_REGION())
			CAlignSendAckCmd(_SUCCESS);

		}
#endif

#if  1//Adj_7500K_Temp	
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==3))//save CT
		{

			RTDNVRamSaveColorSetting(_CT_7500);//GET_COLOR_TEMP_TYPE(GET_OSD_SELECT_REGION())
		    CAlignSendAckCmd(_SUCCESS);

		}
#endif
#if(_DEF_CT_SRGB_SUPPIRT == _ON)
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==4))//save CT
		{

			RTDNVRamSaveColorSetting(_CT_SRGB);//GET_COLOR_TEMP_TYPE(GET_OSD_SELECT_REGION())
			CAlignSendAckCmd(_SUCCESS);

		}
#endif

		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x18)&&(g_pucDdcciRxBuf[6]==5))//save CT
		{

		    RTDNVRamSaveColorSetting(_CT_4500);
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x19)&&(g_pucDdcciRxBuf[6]==0))//set brightness and contrast default
		{

			RTDNVRamRestoreBriCon();
			//UserAdjustBlackLevel();
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			CAlignSendAckCmd(_SUCCESS);
		}
		else if((g_pucDdcciRxBuf[4]==0x32)&&(g_pucDdcciRxBuf[5]==0x1A))//read adjust brightness 
		{

			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1] = 0x82;
			g_pucDdcciTxBuf[2] = 0x00;	
			g_pucDdcciTxBuf[3] = GET_OSD_BACKLIGHT();
		    g_pucDdcciTxBuf[4] = UserCommonDdcciCalCheckSum();
		    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

			//_CHECK_CT_DATA_RANGE

			//g_stColorTempDefaultData

		}
		else if((g_pucDdcciRxBuf[4]==0x32)&&(g_pucDdcciRxBuf[5]==0x1B))//read adjust contrast
		{
		
			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1] = 0x82;
			g_pucDdcciTxBuf[2] = 0x00;	
			g_pucDdcciTxBuf[3] = GET_OSD_CONTRAST();
		    g_pucDdcciTxBuf[4] = UserCommonDdcciCalCheckSum();
		    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x1A))//write adjust brightness 
		{

			uctempData=g_pucDdcciRxBuf[6];
			if((uctempData >= 0) && (uctempData <= 100))
			{
				CAlignSendAckCmd(_SUCCESS);
				SET_OSD_BACKLIGHT(uctempData);
				UserAdjustBacklight(GET_OSD_BACKLIGHT());
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_EEPROM_BRICON_MSG);

			}
			else
			{
			/*
            	   if(GET_COLOR_TEMP_TYPE() == _CT_SRGB)
			       {
						SET_OSD_BACKLIGHT(_SRGB_BACKLIGHT);
						RTDNVRamSaveSrgbBrightness(GET_OSD_GAME_MODE());
						SET_OSD_BACKUP_SRGB_BRI(_SRGB_BACKLIGHT);
						RTDNVRamSaveOSDData();
			       }
*/
				CAlignSendAckCmd(_FAIL);
			}			

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x1B))//write adjust contrast
		{

			uctempData=g_pucDdcciRxBuf[6];
			if((uctempData >= 0) && (uctempData <= 100))
			{
			
			      CAlignSendAckCmd(_SUCCESS);
		          SET_OSD_CONTRAST(uctempData);
				  UserAdjustContrast(GET_OSD_CONTRAST());


			}
			else
			{

				CAlignSendAckCmd(_FAIL);
			}			

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_EEPROM_BRICON_MSG);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x1C))//set default language or select reset language
		{
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x1D)&&(g_pucDdcciRxBuf[6]==0))//enter burn mode
		{
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x1D)&&(g_pucDdcciRxBuf[6]==1))//exit burn mode
		{

			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x35)&&(g_pucDdcciRxBuf[5]==0x1F)&&(g_pucDdcciRxBuf[6]==0))//enter align mode
		{
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x21)&&(g_pucDdcciRxBuf[6]==0))//factory mode on
		{

			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x21)&&(g_pucDdcciRxBuf[6]==1))//factory mode off
		{

		    ubAutoAlign=0;
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x23)&&(g_pucDdcciRxBuf[6]==0))//change source vga
		{
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x39)&&(g_pucDdcciRxBuf[5]==0x23)&&(g_pucDdcciRxBuf[6]==1))//change source dvi
		{
			CAlignSendAckCmd(_SUCCESS);

		}
		else if((g_pucDdcciRxBuf[4]==0x35)&&(g_pucDdcciRxBuf[5]==0x1F)&&(g_pucDdcciRxBuf[6]==1))//exit align mode
		//else if((g_pucDdcciRxBuf[4]==0x00)&&(g_pucDdcciRxBuf[5]==0x01)&&(g_pucDdcciRxBuf[6]==1))//exit align mode
		{

			ubAutoAlign=0;
			
			if((SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) && (GET_FACTORY_BURNIN() == _ON))
			{
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BURN_IN_DDCTOOL);
			
			}
		    else if((SysModeGetModeState() == _MODE_STATUS_ACTIVE)&& (GET_FACTORY_BURNIN() == _ON))
		    {

				SET_FACTORY_MODE(_OFF);
				SET_FACTORY_BURNIN(_OFF);
				TPVNVRamSaveFactoryDate();
				UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
				SET_COLOR_TEMP_TYPE(_COLORTEMP_DEFAULT);	// 20211019
				RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
				UserAdjustContrast(_CONTRAST_DEFAULT);
		    }


		    CAlignSendAckCmd(_SUCCESS);

		}
		else
		{

			CAlignSendAckCmd(_FAIL);

		}

	}
}

#endif //end of #if(_OSD_TYPE == _HKC_OSD)

#endif

#else
#if(_OSD_TYPE == _REALTEK_2014_OSD)
BYTE Ct4500Flag = 0;

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
//ENABLE_CTX_ALIGN_CONTROL

void CTXAlignControl(void);


bit FC_READ_R_GAIN()
{
    return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x02);
}

bit FC_READ_G_GAIN()
{
    return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x03);
}

bit FC_READ_B_GAIN()
{
    return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x04);
}

bit FC_READ_CONTRAST()
{
    return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x0e);
}

bit FC_READ_BRIGHTNESS()
{
    return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x0d);
}

bit FC_ADJUST_R_GAIN()
{
    return (g_pucDdcciRxBuf[3]==0x40&&g_pucDdcciRxBuf[4]==0x02);
}

bit FC_ADJUST_G_GAIN()
{
	return (g_pucDdcciRxBuf[3]==0x40&&g_pucDdcciRxBuf[4]==0x03);
}

bit FC_ADJUST_B_GAIN()
{
	return (g_pucDdcciRxBuf[3]==0x40&&g_pucDdcciRxBuf[4]==0x04);
}

bit FC_ADJUST_CONTRAST()
{
	return (g_pucDdcciRxBuf[3]==0x40&&g_pucDdcciRxBuf[4]==0x01);
}

bit FC_ADJUST_BRIGHTNESS()
{
	return (g_pucDdcciRxBuf[3]==0x40&&g_pucDdcciRxBuf[4]==0x00);
}
/*
bit FC_ADJUST_LANGUAGE(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x36);
}
*/
bit FC_AUTO_COLOR()
{
	return (g_pucDdcciRxBuf[3]==0x0d&&g_pucDdcciRxBuf[4]==0x01);
}
/*
bit FC_CHANGE_TO_9300(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x21&&g_pucMcuDdcciRxBuf[5]==0x00);
}

bit FC_CHANGE_TO_6500(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x21&&g_pucMcuDdcciRxBuf[5]==0x01);
}

bit FC_CHANGE_TO_5800(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x21&&g_pucMcuDdcciRxBuf[5]==0x02);
}
////////
bit FC_CHANGE_TO_7500(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x21&&g_pucMcuDdcciRxBuf[5]==0x03);
}

bit FC_INIT_EEPROM(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x34&&g_pucMcuDdcciRxBuf[5]==0x00);
}
*/
bit FC_SAVE_9300()
{
	return (g_pucDdcciRxBuf[3]==0x19&&g_pucDdcciRxBuf[4]==0x13);
}

bit FC_SAVE_6500()
{
	return (g_pucDdcciRxBuf[3]==0x16&&g_pucDdcciRxBuf[4]==0x15);
}
bit FC_SAVE_USER()
{
	return (g_pucDdcciRxBuf[3]==0x11&&g_pucDdcciRxBuf[4]==0x10);
}
bit FC_SAVE_7500()
{
	return (g_pucDdcciRxBuf[3]==0x17&&g_pucDdcciRxBuf[4]==0x15);
}
bit FC_SAVE_5000()
{
	return (g_pucDdcciRxBuf[3]==0x15&&g_pucDdcciRxBuf[4]==0x15);
}
bit FC_SAVE_4500()
{
	return (g_pucDdcciRxBuf[3]==0x14&&g_pucDdcciRxBuf[4]==0x15);
}

bit FC_SAVE_sRGB()
{
	return (g_pucDdcciRxBuf[3]==0x11&&g_pucDdcciRxBuf[4]==0x11);
}

bit FC_SAVE_8200()
{
	return (g_pucDdcciRxBuf[3]==0x18&&g_pucDdcciRxBuf[4]==0x12);
}

bit FC_SAVE_11500()
{
	return (g_pucDdcciRxBuf[3]==0x1B&&g_pucDdcciRxBuf[4]==0x15);
}



/*
bit FC_BRICONT_DEFAULT(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x18&&g_pucMcuDdcciRxBuf[5]==0x00);
}
*/
bit FC_ENTER_BURNIN()
{
	return (g_pucDdcciRxBuf[3]==0x0d&&g_pucDdcciRxBuf[4]==0x04);
}

bit FC_EXIT_BURNIN()
{
	return (g_pucDdcciRxBuf[3]==0x0d&&g_pucDdcciRxBuf[4]==0x05);
}

bit FC_ENTER_FACTORY()
{
	return (g_pucDdcciRxBuf[3]==0x00&&g_pucDdcciRxBuf[4]==0x00);
}

bit FC_EXIT_FACTORY()
{
	return (g_pucDdcciRxBuf[3]==0x00&&g_pucDdcciRxBuf[4]==0x01);
}
/*
bit FC_ENTER_AUTOALIGN(BYTE )
{
	return (g_pucMcuDdcciRxBuf[2]==0x00&&g_pucMcuDdcciRxBuf[3]==0x00);
}

bit FC_EXIT_AUTOALIGN(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x55&&g_pucMcuDdcciRxBuf[4]==0x84&&g_pucMcuDdcciRxBuf[5]==0x01);
}

bit FC_DVIFUNC_ON(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x37&&g_pucMcuDdcciRxBuf[5]==0x00);
}

bit FC_DVIFUNC_OFF(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x37&&g_pucMcuDdcciRxBuf[5]==0x01);
}

bit FC_AUDIOFUNC_ON(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x38&&g_pucMcuDdcciRxBuf[5]==0x00);
}

bit FC_AUDIOFUNC_OFF(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x38&&g_pucMcuDdcciRxBuf[5]==0x01);
}

bit FC_DCRFUNC_ON(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x39&&g_pucMcuDdcciRxBuf[5]==0x00);
}

bit FC_DCRFUNC_OFF(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x39&&g_pucMcuDdcciRxBuf[5]==0x01);
}

bit FC_SOURCE_VGA(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x3A&&g_pucMcuDdcciRxBuf[5]==0x00);
}

bit FC_SOURCE_DVI(BYTE )
{
	return ((g_pucMcuDdcciRxBuf[3]==0x57&&g_pucMcuDdcciRxBuf[4]==0x3A&&g_pucMcuDdcciRxBuf[5]==0x01);
}
*/
bit FC_SET_6500K()
{
	return (g_pucDdcciRxBuf[3]== 0x06&& g_pucDdcciRxBuf[4] == 0x05);
}
bit FC_SET_7500K()
{
	return (g_pucDdcciRxBuf[3] == 0x07&& g_pucDdcciRxBuf[4] == 0x05);	
}
bit FC_SET_9300K()
{
	return (g_pucDdcciRxBuf[3] == 0x09&& g_pucDdcciRxBuf[4] == 0x03);
}
bit FC_SET_USER()
{
	return (g_pucDdcciRxBuf[3] == 0x01&& g_pucDdcciRxBuf[4] == 0x00);
}
bit FC_SET_5000K()
{
	return (g_pucDdcciRxBuf[3] == 0x05&& g_pucDdcciRxBuf[4] == 0x05);
}

bit FC_SET_sRGB()
{
	return (g_pucDdcciRxBuf[3] == 0x01&& g_pucDdcciRxBuf[4] == 0x01);
}

bit FC_Set_ColorMode_sRGB()
{
	return (g_pucDdcciRxBuf[3] == 0x20 && g_pucDdcciRxBuf[4] == 0x01);
}

bit FC_Set_ColorMode_Normal()
{
	return (g_pucDdcciRxBuf[3] == 0x20 && g_pucDdcciRxBuf[4] == 0x00);
}

bit FC_SET_4500()
{
	return (g_pucDdcciRxBuf[3] == 0x04&& g_pucDdcciRxBuf[4] == 0x05);
}

bit FC_SET_8200()
{
	return (g_pucDdcciRxBuf[3] == 0x08&& g_pucDdcciRxBuf[4] == 0x02);
}

bit FC_SET_11500()
{
	return (g_pucDdcciRxBuf[3] == 0x0B&& g_pucDdcciRxBuf[4] == 0x05);
}

/*
bit FC_SET_COLOR_TEMP()
{
	return (g_pucMcuDdcciRxBuf[2]& 0xF0 == 0) && g_pucMcuDdcciRxBuf[3]&0xF0 == 0);
}
bit FC_SAVE_COLOR_TEMP()
{
	return (g_pucMcuDdcciRxBuf[2]&0xf0 == 0x10) && g_pucMcuDdcciRxBuf[3]&0xF0 == 0x10);
}
*/
bit FC_GET_ADC_RGAIN()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x12);
}
bit FC_GET_ADC_GGAIN()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x13);
}
bit FC_GET_ADC_BGAIN()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x14);
}

bit FC_GET_ADC_ROFFSET()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x15);
}
bit FC_GET_ADC_GOFFSET()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x16);
}
bit FC_GET_ADC_BOFFSET()
{
	return (g_pucDdcciRxBuf[3]==0x50&&g_pucDdcciRxBuf[4]==0x17);
}



bit FC_RESET_CMD()
{
	return (g_pucDdcciRxBuf[3]==0x0E&&g_pucDdcciRxBuf[4]==0x00);
}

void CAlignSendAckCmd(BYTE Status)
{
	g_pucDdcciRxBuf[0]=0x6E;
    g_pucDdcciTxBuf[1]=0x83;
	if(Status == _TRUE)
	{
		g_pucDdcciTxBuf[2] = 'e';
		g_pucDdcciTxBuf[3] = 'n';
		g_pucDdcciTxBuf[4] = 'a';

	}
	else
	{
		g_pucDdcciTxBuf[2] = 'e';
		g_pucDdcciTxBuf[3] = 'x'; 
		g_pucDdcciTxBuf[4] = 'a';
	}

	g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
	ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
	
}


void CTXAlignControl(void)
{
    BYTE value = 0;
	BYTE ucR_Gain,ucG_Gain,ucB_Gain;

    if(FC_READ_R_GAIN())
	{
	
	    g_pucDdcciTxBuf[0] = 0x6E;
		g_pucDdcciTxBuf[1]=0x83;
		g_pucDdcciTxBuf[2] = GET_COLOR_TEMP_TYPE_USER_R();
		g_pucDdcciTxBuf[3]=' ';//0x4F;
		g_pucDdcciTxBuf[4]=' ';//0x4F;
		g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		

	}
	else if(FC_READ_G_GAIN())
	{
	    g_pucDdcciTxBuf[0] = 0x6E;
		g_pucDdcciTxBuf[1]=0x83;
		g_pucDdcciTxBuf[2] = GET_COLOR_TEMP_TYPE_USER_G();
		g_pucDdcciTxBuf[3]=' ';//0x4F;
		g_pucDdcciTxBuf[4]=' ';//0x4F;
		g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		ScalerMcuDdcciSendData(g_pucDdcciTxBuf);


	}
	else if(FC_READ_B_GAIN())
	{
	    g_pucDdcciTxBuf[0] = 0x6E;
		g_pucDdcciTxBuf[1]=0x83;
		g_pucDdcciTxBuf[2] = GET_COLOR_TEMP_TYPE_USER_B();
		g_pucDdcciTxBuf[3]=' ';//0x4F;
		g_pucDdcciTxBuf[4]=' ';//0x4F;
		g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
        ScalerMcuDdcciSendData(g_pucDdcciTxBuf);


	}
		else if(FC_READ_CONTRAST())
		{
		   g_pucDdcciTxBuf[0] = 0x6E;
		   g_pucDdcciTxBuf[1]=0x83;
           g_pucDdcciTxBuf[2]  =GET_OSD_CONTRAST();
           g_pucDdcciTxBuf[3]=' ';//0x4F;
		   g_pucDdcciTxBuf[4]=' ';//0x4F;
		   g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		   ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		   
		}
		else if(FC_READ_BRIGHTNESS())
		{
			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1]=0x83;
			g_pucDdcciTxBuf[2]  =GET_OSD_BACKLIGHT();
			g_pucDdcciTxBuf[3]=' ';//0x4F;
			g_pucDdcciTxBuf[4]=' ';//0x4F;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_ADJUST_R_GAIN())
		{
         	ucR_Gain=g_pucDdcciRxBuf[5];
       		
			if((ucR_Gain >= 0) && (ucR_Gain <= 255))
			{

			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
				CAlignSendAckCmd(_SUCCESS);
			    SET_COLOR_TEMP_TYPE_USER_R(ucR_Gain);
			    UserAdjustContrast(GET_OSD_CONTRAST());


			}

       			/*g_pucMcuDdcciTxBuf[ 0 ]  = 0x84;		 
                g_pucMcuDdcciTxBuf[ 1 ]  = ' ';			
                g_pucMcuDdcciTxBuf[ 2 ]  = 'w';
                g_pucMcuDdcciTxBuf[ 3 ]  = 'r';
                g_pucMcuDdcciTxBuf[ 4 ]  = 'r';*/

			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1]=0x83;
            g_pucDdcciTxBuf[ 2 ]  = 'w';
            g_pucDdcciTxBuf[ 3 ]  = 'r';
            g_pucDdcciTxBuf[ 4 ]  = 'g';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
       	       		
			
		}
		else if(FC_ADJUST_G_GAIN())
		{
       		ucG_Gain=g_pucDdcciRxBuf[5];
       		
			if((ucG_Gain >= 0) && (ucG_Gain <= 255))
			{
			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
			      CAlignSendAckCmd(_SUCCESS);
			     SET_COLOR_TEMP_TYPE_USER_G(ucG_Gain);
			     UserAdjustContrast(GET_OSD_CONTRAST());


			}


			g_pucDdcciTxBuf[0] = 0x6E;
			g_pucDdcciTxBuf[1]=0x83;
            g_pucDdcciTxBuf[ 2 ]  = 'w';
            g_pucDdcciTxBuf[ 3 ]  = 'g';
            g_pucDdcciTxBuf[ 4 ]  = 'g';
       		g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_ADJUST_B_GAIN())
		{
		    ucB_Gain=g_pucDdcciRxBuf[5];
       		
			if((ucB_Gain >= 0) && (ucB_Gain <= 255))
			{

			//需注意COLOR_TEMP接收的数值范围
			//长城code的接收范围是0-100
			//(x > 50) ? (DWORD)(x*0xFF)/100 : (x + 78)---input--0:78;50:128;100:256
			//switch 0-255--->0-100------0:0;128:50;255:100
			   SET_COLOR_TEMP_TYPE_USER_B(ucB_Gain);
			    UserAdjustContrast(GET_OSD_CONTRAST());


            }


       			/*g_pucMcuDdcciTxBuf[ 0 ]  = 0x84;		 
                g_pucMcuDdcciTxBuf[ 1 ]  = ' ';			
                g_pucMcuDdcciTxBuf[ 2 ]  = 'w';
                g_pucMcuDdcciTxBuf[ 3 ]  = 'r';
                g_pucMcuDdcciTxBuf[ 4 ]  = 'b';*/

				g_pucDdcciTxBuf[0] = 0x6E;
				g_pucDdcciTxBuf[1]=0x83;
            g_pucDdcciTxBuf[ 2 ]  = 'w';
            g_pucDdcciTxBuf[ 3 ]  = 'b';
            g_pucDdcciTxBuf[ 4 ]  = 'g';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
       			    
		}
		else if(FC_ADJUST_CONTRAST())
		{
		    BYTE uctempData;
			uctempData=g_pucDdcciRxBuf[5];
       		if((uctempData <= 100))
			{
				SET_OSD_CONTRAST(uctempData);
				UserAdjustContrast(GET_OSD_CONTRAST());
				
				g_pucDdcciTxBuf[2]='w';
				g_pucDdcciTxBuf[3]='c';
				g_pucDdcciTxBuf[4]='o';
			}
			else
			{
				g_pucDdcciTxBuf[2]='C';
				g_pucDdcciTxBuf[3]='O';
				g_pucDdcciTxBuf[4]='X';
			}
			g_pucDdcciTxBuf[1]=0x83;
			g_pucDdcciTxBuf[0]=0x6E;
			
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_ADJUST_BRIGHTNESS())
		{
            BYTE uctempData;
       		uctempData=g_pucDdcciRxBuf[5];
       		if(uctempData <= 100)
			{
                SET_OSD_BACKLIGHT(uctempData);
				UserAdjustBacklight(GET_OSD_BACKLIGHT());
				g_pucDdcciTxBuf[2]='w';
				g_pucDdcciTxBuf[3]='b';
				g_pucDdcciTxBuf[4]='r';
			}
			else
			{
				g_pucDdcciTxBuf[2]='B';
				g_pucDdcciTxBuf[3]='R';
				g_pucDdcciTxBuf[4]='X';
			}
			g_pucDdcciTxBuf[1]=0x83;
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_AUTO_COLOR())
		{
			if(	(SysSourceGetInputPort() != _A0_INPUT_PORT)
#if(_VGA_SUPPORT == _ON)
				|| (ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS) 
#endif
				)                
			{
#if(_VGA_SUPPORT == _ON)
			    ScalerAutoGetAutoColorResult(&g_stAdcData);
              	UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
#endif

				g_pucDdcciTxBuf[2] = 'a';//0;	
				g_pucDdcciTxBuf[3] = 'c';//0x4f;
				g_pucDdcciTxBuf[4] = 'o';//UserCommonDdcciCalCheckSum();   

			}
			else
			{
				g_pucDdcciTxBuf[2] = 'A';//0;	
				g_pucDdcciTxBuf[3] = 'C';//0x4f;
				g_pucDdcciTxBuf[4] = 'X';//UserCommonDdcciCalCheckSum();   
			}
		    	 g_pucDdcciTxBuf[0]=0x6E;
           		 g_pucDdcciTxBuf[ 1 ]  = 0x83;
		
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_ENTER_BURNIN())
		{ 
		    SET_FACTORY_MODE(_ON);
            SET_FACTORY_BURNIN(_ON);
			TPVNVRamSaveFactoryDate();
			UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 'b';
            g_pucDdcciTxBuf[ 3 ]  = 'o';
            g_pucDdcciTxBuf[ 4 ]  = 'n';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);


		}
		else if(FC_EXIT_BURNIN())
		{
		    SET_FACTORY_MODE(_OFF);
           	SET_FACTORY_BURNIN(_OFF);
			TPVNVRamSaveFactoryDate();
			UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
			SET_COLOR_TEMP_TYPE( _COLORTEMP_DEFAULT);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 'b';
            g_pucDdcciTxBuf[ 3 ]  = 'o';
            g_pucDdcciTxBuf[ 4 ]  = 'f';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_ENTER_FACTORY())
		{
		     //ubAutoAlign = 1;
	        CAlignSendAckCmd(_TRUE);
		    SET_FACTORY_MODE(_ON);
           	SET_FACTORY_BURNIN(_ON);
			TPVNVRamSaveFactoryDate();
			UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);
			SET_COLOR_TEMP_TYPE( _COLORTEMP_DEFAULT);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}
		else if(FC_EXIT_FACTORY())
		{ 
			//SaveFactorySetting();
			CAlignSendAckCmd(_TRUE);
		    SET_FACTORY_MODE(_OFF);
            SET_FACTORY_BURNIN(_OFF);
			TPVNVRamSaveFactoryDate();				
			UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
			//ubAutoAlign = 0;
			SET_COLOR_TEMP_TYPE( _COLORTEMP_DEFAULT);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			if(Ct4500Flag==1)
			{
				Ct4500Flag=0;
				//SET_CT4500_STATUS(_ON);
			}
			else
			{
				//SET_CT4500_STATUS(_OFF);   
			}
			RTDNVRamSaveOSDData();


        
		}
		else if(FC_SET_6500K())
		{
			SET_COLOR_TEMP_TYPE( _CT_6500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());

   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '6';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '6';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_SET_7500K())
		{   
			SET_COLOR_TEMP_TYPE( _CT_7500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '7';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';	*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '7';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);


		}
		else if(FC_SET_9300K())
		{
			SET_COLOR_TEMP_TYPE( _CT_9300);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '9';
            g_pucMcuDdcciRxBuf[ 4 ]  = '3';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '9';
            g_pucDdcciTxBuf[ 4]  = '3';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_SET_5000K())
		{
			SET_COLOR_TEMP_TYPE( _CT_5000);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '5';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '5';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}	
		else if(FC_SET_8200())
		{
			//SET_COLOR_TEMP_TYPE( _CT_8200);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '4';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '8';
            g_pucDdcciTxBuf[ 4 ]  = '2';
            
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_SET_11500())
		{
			//SET_COLOR_TEMP_TYPE( _CT_11500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '4';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = 'B';
            g_pucDdcciTxBuf[ 4 ]  = '5';
            
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_SET_sRGB())
		{
			SET_COLOR_TEMP_TYPE( _CT_SRGB);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '4';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '1';
            g_pucDdcciTxBuf[ 4 ]  = '1';
            
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}	

		else if(FC_Set_ColorMode_sRGB())
		{
			SET_OSD_PCM_STATUS( _PCM_OSD_SRGB);
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			
			g_pucDdcciTxBuf[2]=0x73;
			g_pucDdcciTxBuf[3]=0x6f;
			g_pucDdcciTxBuf[4]=0x31;

			g_pucDdcciTxBuf[1]=0x83;
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_Set_ColorMode_Normal())
		{
			SET_OSD_PCM_STATUS( _PCM_OSD_NATIVE);
			SET_OSD_BACKLIGHT_SRGB(g_stVscSceneModeData.usBackLightSrgb);
			RTDNVRamSaveOSDData();
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			OsdFuncColorPcmAdjust();
			RTDFlashRestoreViewModeParameters();
			
			g_pucDdcciTxBuf[2]=0x73;
			g_pucDdcciTxBuf[3]=0x6f;
			g_pucDdcciTxBuf[4]=0x30;
			
			g_pucDdcciTxBuf[1]=0x83;
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}

		else if(FC_SET_4500())
		{
		
			SET_COLOR_TEMP_TYPE( _CT_4500);
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
   			/*g_pucMcuDdcciRxBuf[ 0 ]  = 0x84;   
            g_pucMcuDdcciRxBuf[ 1 ]  = ' ';			
            g_pucMcuDdcciRxBuf[ 2 ]  = 't';
            g_pucMcuDdcciRxBuf[ 3 ]  = '4';
            g_pucMcuDdcciRxBuf[ 4 ]  = '5';*/
			g_pucDdcciTxBuf[0]=0x6E;
			g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 't';
            g_pucDdcciTxBuf[ 3 ]  = '4';
            g_pucDdcciTxBuf[ 4 ]  = '5';
            
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}	


		
        else if(FC_SET_USER())
		{

		}
		else if(FC_SAVE_6500())
		{

			RTDNVRamSaveColorSetting(_CT_6500);
			
#if(_DEF_CT_5800_SUPPORT == _OFF)
			SET_COLOR_TEMP_TYPE_USER_B(GET_COLOR_TEMP_TYPE_USER_B()-35);	
			RTDNVRamSaveColorSetting(_CT_4500);
#endif

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '6';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

		}
		else if(FC_SAVE_7500())
		{

			RTDNVRamSaveColorSetting(_CT_7500);

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '7';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
				

		}
		else if(FC_SAVE_9300())
		{

			RTDNVRamSaveColorSetting(_CT_9300);

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '9';
            g_pucDdcciTxBuf[ 4 ]  = '3';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
				
		}
		else if(FC_SAVE_5000())
		{

			RTDNVRamSaveColorSetting(_CT_5000);
#if(_DEF_CT_5800_SUPPORT == _ON)
			g_stColorProcData.usColorTempB =g_stColorProcData.usColorTempB - 15;
			SET_COLOR_TEMP_TYPE( _CT_4500);
			RTDNVRamSaveOSDData();
			RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
#endif
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '5';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			
		}
		else if(FC_SAVE_8200())
		{
		//	RTDNVRamSaveColorSetting(_CT_8200);

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '8';
            g_pucDdcciTxBuf[ 4 ]  = '2';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			
			
		}
		else if(FC_SAVE_11500())
		{
		//	RTDNVRamSaveColorSetting(_CT_11500);

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = 'B';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
			
		}
		//RTDFlashRestoreViewModeParameters
		else if(FC_SAVE_sRGB())
		{
			BYTE ucViewMode;

			RTDNVRamSaveColorSetting(_CT_SRGB);
			SET_OSD_BACKLIGHT_SRGB(g_stVscSceneModeData.usBackLightSrgb);
			RTDNVRamSaveOSDData();

			for(ucViewMode=_VIEWMODE_AMOUNT+2; ucViewMode >= _GM_OFF; ucViewMode--)
			{
				RTDFlashLoadVMData(ucViewMode);
				if(ucViewMode == _VM_TEXT + 3)
				{
					g_stVscSceneModeData.usBackLightNormal = GET_OSD_BACKLIGHT_SRGB();
				}
				else
				{
					g_stVscSceneModeData.usBackLightSrgb = GET_OSD_BACKLIGHT_SRGB();
				}
				RTDFlashSaveVMData(ucViewMode);
			}

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '1';
            g_pucDdcciTxBuf[ 4 ]  = '1';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}

		else if(FC_SAVE_4500())
		{
			RTDNVRamSaveColorSetting(_CT_4500);
		    Ct4500Flag=1;

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = '4';
            g_pucDdcciTxBuf[ 4 ]  = '5';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}

		
        else if(FC_SAVE_USER())
		{
			RTDNVRamSaveColorSetting(_CT_USER);

		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ]  = 's';
            g_pucDdcciTxBuf[ 3 ]  = 'u';
            g_pucDdcciTxBuf[ 4 ]  = 's';
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}		
		else if(FC_GET_ADC_RGAIN())
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
             g_pucDdcciTxBuf[ 2 ] =99;//UserPrefAdcRedGain;

			 g_pucDdcciTxBuf[3]=' ';//0x4F;
		     g_pucDdcciTxBuf[4]=' ';//0x4F;
			 g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			 ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_GET_ADC_GGAIN())
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
             g_pucDdcciTxBuf[ 2 ] =103;//UserPrefAdcGreenGain;

			 g_pucDdcciTxBuf[3]=' ';//0x4F;
		     g_pucDdcciTxBuf[4]=' ';//0x4F;
			 g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			 ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_GET_ADC_BGAIN())
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ] = 105;//UserPrefAdcBlueGain;

			g_pucDdcciTxBuf[3]=' ';//0x4F;
		    g_pucDdcciTxBuf[4]=' ';//0x4F;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_GET_ADC_ROFFSET())
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ] =99;// UserPrefAdcRedOffset;

			g_pucDdcciTxBuf[3]=' ';//0x4F;
		    g_pucDdcciTxBuf[4]=' ';//0x4F;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_GET_ADC_GOFFSET())
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ] =103;//UserPrefAdcGreenGain;

			g_pucDdcciTxBuf[3]=' ';//0x4F;
		    g_pucDdcciTxBuf[4]=' ';//0x4F;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}
		else if(FC_GET_ADC_BOFFSET())	
		{
		    g_pucDdcciTxBuf[0]=0x6E;
            g_pucDdcciTxBuf[ 1 ]  = 0x83;
            g_pucDdcciTxBuf[ 2 ] =  105;//UserPrefAdcBlueGain;

			g_pucDdcciTxBuf[3]=' ';//0x4F;
		    g_pucDdcciTxBuf[4]=' ';//0x4F;
			g_pucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();
		    ScalerMcuDdcciSendData(g_pucDdcciTxBuf);
		}

	    else if(FC_RESET_CMD())	
		{
            ddcci_reset=1;
		    OsdDispOsdReset();
		    g_pucDdcciTxBuf[0]=0x83;
            g_pucDdcciTxBuf[1]= 0x00;
            g_pucDdcciTxBuf[2] =0x00;
			g_pucDdcciTxBuf[3]=0x00;
			//return 1;
		
		}
}
#endif





#endif //end of #if(_OSD_TYPE == _HKC_OSD)

