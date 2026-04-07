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
// ID Code      : RTD2014OsdFontProp.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFONTPROP__

#include "UserCommonInclude.h"
#include "RTD2014OsdTextTableBody.h"
#include "RTDOsdTableDefine.h"


#if(_OSD_TYPE == _REALTEK_2014_OSD)
#define P3A_1B_FRAME_CTRL_1B                                        0x3A1B
#define P3A_1C_FRAME_CTRL_1C                                        0x3A1C
#define P3A_1D_FRAME_CTRL_1D                                        0x3A1D
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#ifndef _OSD_FONT_MODE_FORCE_256_511
#define _OSD_FONT_MODE_FORCE_256_511                _ON
#endif
#define GET_OSD_INFO_MAP_FONT_BASE_ADDRESS()        g_usFontTableStart

#define GET_OSD_INFO_FONT_POINTER_0()               g_usFontPointer0
#define GET_OSD_INFO_FONT_POINTER_1()               g_usFontPointer1
#define GET_OSD_INFO_FONT_POINTER_2()               g_usFontPointer2
#define GET_OSD_INFO_FONT_POINTER_3()               g_usFontPointer3

#define SET_OSD_INFO_FONT_POINTER_0(x)              g_usFontPointer0 = (x)
#define SET_OSD_INFO_FONT_POINTER_1(x)              g_usFontPointer1 = (x)
#define SET_OSD_INFO_FONT_POINTER_2(x)              g_usFontPointer2 = (x)
#define SET_OSD_INFO_FONT_POINTER_3(x)              g_usFontPointer3 = (x)

#define GET_OSD_INFO_FONT_POINTER_SLIDER()          (g_usFontPointerSlider)
#define SET_OSD_INFO_FONT_POINTER_SLIDER(x)         (g_usFontPointerSlider = (x))

#define GET_OSD_INFO_FONT_POINTER_POWER()           (g_usFontPointerPower)
#define SET_OSD_INFO_FONT_POINTER_POWER(x)          (g_usFontPointerPower = (x))

#define GET_OSD_INFO_FONT_POINTER_RATE()           (g_usFontPointerRate)
#define SET_OSD_INFO_FONT_POINTER_RATE(x)          (g_usFontPointerRate = (x))

#define GET_OSD_INFO_FONT_POINTER_VIEW()           (g_usFontPointerView)
#define SET_OSD_INFO_FONT_POINTER_VIEW(x)          (g_usFontPointerView = (x))

#define GET_OSD_INFO_FONT_POINTER_TITLE()           (g_usFontPointerTitle)
#define SET_OSD_INFO_FONT_POINTER_TITLE(x)          (g_usFontPointerTitle = (x))

#define GET_OSD_INFO_FONT_POINTER_HDR()           	(g_usFontPointerHDR)
#define SET_OSD_INFO_FONT_POINTER_HDR(x)          	(g_usFontPointerHDR = (x))

#define GET_OSD_INFO_FONT_POINTER_SN()           	(g_usFontPointerSN)
#define SET_OSD_INFO_FONT_POINTER_SN(x)          	(g_usFontPointerSN = (x))

#define GET_OSD_INFO_FONT_POINTER_INF_RATE()        (g_usFontPointerINF_RATE)
#define SET_OSD_INFO_FONT_POINTER_INF_RATE(x)       (g_usFontPointerINF_RATE = (x))



#if(_OSD_REG_MAPPING_GEN == _USER_OSD_GEN_1)
#define _OSD_MODE_BYTE0                             0x8C
#define _OSD_MODE_BYTE0_256_511                     0x2C
#elif(_OSD_REG_MAPPING_GEN == _USER_OSD_GEN_2)
#define _OSD_MODE_BYTE0                             0x4C
#define _OSD_MODE_BYTE0_256_511                     0x6C
#endif // End of #if(_OSD_REG_MAPPING_GEN == _USER_OSD_GEN_1)
#define _DEFAULT_WIDTH                              12

extern bit Aspect_Dcr_BacklightFlag ; // ��¼DCR������������߱Ȼ��������󱳹���
extern bit HDR_OFF_FLAG ;	// ��¼û��HDRǰ�Ƿ�����˶Աȶ�


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
WORD code tSTRING_RESOLUTION_TABLE[][6]=
{
    {   _,   _,   _,   _,   _,   _},
    { 240, _4_, _8_, _0_, _i_,   _},
    { 480, _4_, _8_, _0_, _p_,   _},
    { 288, _5_, _7_, _6_, _i_,   _},
    { 576, _5_, _7_, _6_, _p_,   _},
    { 720, _7_, _2_, _0_, _p_,   _},
    { 540, _1_, _0_, _8_, _0_, _i_},
    {1080, _1_, _0_, _8_, _0_, _p_},
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE *g_pucShowNumberAddress;
BYTE g_pucModeInfoData[40];
WORD g_usPowerSavingCount;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************



void OsdPropGetShowResolutionStringAddress(void);
#if(_DP_DEBUG_MSG == _ON)
void OsdPropGetShowDpInfoStringAddress(BYTE Index);
#endif

BYTE OsdPropGetFontPointer(BYTE ucPointerSelect);
BYTE OsdPropVideoResolution(void);
BYTE OsdPropSetFontPointer(BYTE ucPointerSelect, BYTE ucPointer);
void OsdPropFontDataToSram(BYTE ucFptsSelect, BYTE *ucpArray, BYTE ucRotateType);

void OsdPropPutString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, WORD usString, BYTE ucIndex, BYTE ucColor, BYTE ucLanguage);
void OsdPropPutStringCenter(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucFptsSelect, WORD usString, BYTE ucIndex, BYTE ucColor, BYTE ucLanguage);
void OsdPropShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint, BYTE ucColor);
BYTE *OsdPropGetStringTableAddress(WORD usString, BYTE ucIndex, BYTE *ucLanguage);

BYTE GetOsdShowType(BYTE ucStateIndex);
BYTE GetOsdCurItem(BYTE ucStateIndex);

extern void UserAdjustColorTemp(void);
extern void OsdFunInputAuto(BYTE value);

#if(_SIX_COLOR_SUPPORT == _ON)
extern void ScalerColorSixColorInitial(void);
extern void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);
#endif


#if(_DEF_MAIN_MENU_MUTE_ICON_SUPPORT == _ON)
extern void OsdDisplayVolumeAdjustUpdateIcon(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************




/*
void GetOSDFlashSN(void)
{
		
		BYTE ucTemp = 0;
		WORD ucValue = _0_;
	//	BYTE Has_W=0;
		RTDNVRamGetSNData();//flash read //MCU_DDCRAM_D1;//EDID read
	
		memcpy(g_pucModeInfoData, _0_, sizeof(g_pucModeInfoData));
		
		
		g_pucModeInfoData[_SN_NUMBER_AMOUNT] = _END_;
		
		if(g_stSNData == NULL)
			return ;
	
		//Flash Read
		memcpy(g_pucModeInfoData, g_stSNData, _SN_NUMBER_AMOUNT);
	
		for(ucTemp = 0; ucTemp < _SN_NUMBER_AMOUNT; ucTemp++)
		{
			if((g_pucModeInfoData[ucTemp] >= 0x61) && (g_pucModeInfoData[ucTemp] <= 0x7a))
			{
				ucValue = g_pucModeInfoData[ucTemp] - 0x61 + _a_;
			}
			else if((g_pucModeInfoData[ucTemp] >= 0x41) && (g_pucModeInfoData[ucTemp] <= 0x5a))
			{
				ucValue = g_pucModeInfoData[ucTemp] - 0x41 + _A_;
				//	if(ucValue==_W_)
				//		Has_W=1;

			}
			else if((g_pucModeInfoData[ucTemp] >= 0x30) && (g_pucModeInfoData[ucTemp] <= 0x39))
			{
				ucValue = g_pucModeInfoData[ucTemp] - 0x30 + _0_;
			}
			else
			{
				ucValue = _;
			}
			
		g_pucModeInfoData[ucTemp] = ucValue;

		}



		g_pucModeInfoData[_SN_NUMBER_AMOUNT] = _END_;

}
*/


#if(_DEFAULT_OSD_STYLE != _TRG_OSD_STYLE && _DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropGetShowResolutionStringAddress(void)
{
    WORD usTemp = 0;
    BYTE ucI = OsdPropVideoResolution();

    if(ucI != 0)
    {
        g_pucModeInfoData[0] = tSTRING_RESOLUTION_TABLE[ucI][1];
        g_pucModeInfoData[1] = tSTRING_RESOLUTION_TABLE[ucI][2];
        g_pucModeInfoData[2] = tSTRING_RESOLUTION_TABLE[ucI][3];
        g_pucModeInfoData[3] = tSTRING_RESOLUTION_TABLE[ucI][4];
        g_pucModeInfoData[4] = tSTRING_RESOLUTION_TABLE[ucI][5];
        // g_pucModeInfoData[5] = _END_;

        g_pucModeInfoData[5] = _AT_0_;

        usTemp = GET_INPUT_TIMING_VFREQ();
        ucI = 7;
        g_pucModeInfoData[8] = _DOT_;
        g_pucModeInfoData[9] = usTemp % 10 + _0_;
        g_pucModeInfoData[10] = _H_;
        g_pucModeInfoData[11] = _z_;
        g_pucModeInfoData[12] = _END_;

        usTemp /= 10;

        while(_TRUE)
        {
            g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;

            if(usTemp <= 0)
            {
                break;
            }
            ucI--;
        }
    }
    else
    {
        if(GET_INPUT_TIMING_HWIDTH() >= 1000)
        {
            ucI = 3;
        }
        else
        {
            ucI = 2;
        }

        usTemp = GET_INPUT_TIMING_HWIDTH();
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) || (_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
        if((GET_INPUT_TIMING_VHEIGHT() <= 660) && (GET_INPUT_TIMING_HWIDTH() >= 620))//  lj 20250307
            usTemp = 640;
#endif       
        while(_TRUE)
        {
            g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;

            if(usTemp <= 0)
            {
                break;
            }
            ucI--;
        }

        if(GET_INPUT_TIMING_HWIDTH() >= 1000)
        {
            g_pucModeInfoData[4] = _x_;
        }
        else
        {
            g_pucModeInfoData[3] = _x_;
        }

        usTemp = GET_INPUT_TIMING_VHEIGHT();
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) || (_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
        if((GET_INPUT_TIMING_HWIDTH() == 1152) && (GET_INPUT_TIMING_VHEIGHT() == 870))//1152x872hz  lj 20250307
            usTemp = 872;
        if((GET_INPUT_TIMING_VHEIGHT() <= 500) && (GET_INPUT_TIMING_VHEIGHT() >= 460))//  lj 20250307
            usTemp = 480;
#endif
        if((GET_INPUT_TIMING_HWIDTH() >= 1000) && (GET_INPUT_TIMING_VHEIGHT() >= 1000))
        {
            ucI = 8;
            g_pucModeInfoData[9] = _AT_0_;

        }
        else if((GET_INPUT_TIMING_HWIDTH() < 1000) && (GET_INPUT_TIMING_VHEIGHT() < 1000))
        {
            ucI = 6;
            g_pucModeInfoData[7] = _AT_0_;
        }
        else
        {
            ucI = 7;
            g_pucModeInfoData[8] = _AT_0_;
        }

        while(_TRUE)
        {
            g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;

            if(usTemp <= 0)
            {
                break;
            }
            ucI--;
        }

		if(GET_INPUT_TIMING_VFREQ()>1194 && GET_INPUT_TIMING_VFREQ()<1205)
        	usTemp = 1200;
        else if(GET_INPUT_TIMING_VFREQ()>740 && GET_INPUT_TIMING_VFREQ()<760)
        	usTemp = 750;   
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) || (_PROJECT_ID ==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
        else if(GET_INPUT_TIMING_VFREQ() <= 670 && GET_INPUT_TIMING_VFREQ() >= 650)//  640 X480 66hz lj 20250307
            usTemp = 660;  
#endif 
		else
        	usTemp = GET_INPUT_TIMING_VFREQ();
		
		//DebugMessageOsd("1.11_usTemp",usTemp);

        if((GET_INPUT_TIMING_HWIDTH() >= 1000) && (GET_INPUT_TIMING_VHEIGHT() >= 1000))
        {
            ucI = 11;
        }
        else if((GET_INPUT_TIMING_HWIDTH() < 1000) && (GET_INPUT_TIMING_VHEIGHT() < 1000))
        {
            ucI = 9;
        }
        else
        {
            ucI = 10;
        }

        // Modify V freq. string position for V freq. > 100Hz
        if(usTemp >= 1000)
        {
            ++ucI;
        }
		//С����
        //g_pucModeInfoData[ucI + 1] = _DOT_;
        //g_pucModeInfoData[ucI + 2] = (usTemp % 10) + _0_;
        g_pucModeInfoData[ucI + 1] = _H_;
        g_pucModeInfoData[ucI + 2] = _z_;
        g_pucModeInfoData[ucI + 3] = _END_;

        usTemp /= 10;

        while(_TRUE)
        {
            g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;

            if(usTemp <= 0)
            {
                break;
            }
            ucI--;
        }
    }

    //return g_pucModeInfoData;
}
#endif


#if(_DP_DEBUG_MSG == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropGetShowDpInfoStringAddress(BYTE Index)
{
    BYTE ucI = 0;
    BYTE ucIndex = 0;
    EnumSourceSearchPort ucPortSel = SysSourceGetInputPort();
    if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
    {
        ucPortSel = GET_OSD_POWER_SAVING_SHOW_DP_INFO_PORT();

        if(Index == _STRING_DP_INFO)
        {
            g_pucModeInfoData[ucIndex++] = _P_;
            g_pucModeInfoData[ucIndex++] = _W_0;
            g_pucModeInfoData[ucIndex++] = _W_1;
            g_pucModeInfoData[ucIndex++] = _COLON_;
            g_pucModeInfoData[ucIndex++] = _0_ + ScalerDpGetPowerStatus(ucPortSel);
            g_pucModeInfoData[ucIndex++] = _COMMA_;
        }
    }

    if(Index == _STRING_DP_INFO)
    {
        switch(ScalerDpGetLaneCount(ucPortSel))
        {
            case _DP_LINK_1_LANE:
                g_pucModeInfoData[ucIndex++] = _1_;
                break;
            case _DP_LINK_2_LANE:
                g_pucModeInfoData[ucIndex++] = _2_;
                break;
            case _DP_LINK_4_LANE:
                g_pucModeInfoData[ucIndex++] = _4_;
                break;
            default:
                g_pucModeInfoData[ucIndex++] = _0_;
                break;
        }
        g_pucModeInfoData[ucIndex++] = _L_;
        g_pucModeInfoData[ucIndex++] = _a_;
        g_pucModeInfoData[ucIndex++] = _n_;
        g_pucModeInfoData[ucIndex++] = _e_;
        switch(ScalerDpGetLinkRate(ucPortSel))
        {
            case _DP_LINK_RBR:
                g_pucModeInfoData[ucIndex++] = _R_;
                g_pucModeInfoData[ucIndex++] = _B_;
                g_pucModeInfoData[ucIndex++] = _R_;
                break;
            case _DP_LINK_HBR:
                g_pucModeInfoData[ucIndex++] = _H_;
                g_pucModeInfoData[ucIndex++] = _B_;
                g_pucModeInfoData[ucIndex++] = _R_;
                break;
            case _DP_LINK_HBR2:
                g_pucModeInfoData[ucIndex++] = _H_;
                g_pucModeInfoData[ucIndex++] = _B_;
                g_pucModeInfoData[ucIndex++] = _R_;
                g_pucModeInfoData[ucIndex++] = _2_;
                break;
            default:
                g_pucModeInfoData[ucIndex++] = _X_;
                g_pucModeInfoData[ucIndex++] = _X_;
                g_pucModeInfoData[ucIndex++] = _X_;
                g_pucModeInfoData[ucIndex++] = _X_;
                break;
        }

        g_pucModeInfoData[ucIndex++] = _COMMA_;
    }
    else if(Index == _STRING_DP_INFO_2)
    {
        g_pucModeInfoData[ucIndex++] = _S_;
        g_pucModeInfoData[ucIndex++] = _w_0;
        g_pucModeInfoData[ucIndex++] = _w_1;
        g_pucModeInfoData[ucIndex++] = _i_;
        g_pucModeInfoData[ucIndex++] = _n_;
        g_pucModeInfoData[ucIndex++] = _g_;
        g_pucModeInfoData[ucIndex++] = _;
        for(ucI=_DP_LANE_0 ; ucI<=_DP_LANE_3 ;ucI++)
        {
            g_pucModeInfoData[ucIndex++] = _LEFT_BRACE_;
            switch(ScalerDpGetLaneVoltageSwingLv(ucPortSel,ucI))
            {
                case _DP_LINK_VOLTAGE_SWING_LEVEL_0:
                    g_pucModeInfoData[ucIndex++] = _0_+0;
                    break;
                case _DP_LINK_VOLTAGE_SWING_LEVEL_1:
                    g_pucModeInfoData[ucIndex++] = _0_+1;
                    break;
                case _DP_LINK_VOLTAGE_SWING_LEVEL_2:
                    g_pucModeInfoData[ucIndex++] = _0_+2;
                    break;
                case _DP_LINK_VOLTAGE_SWING_LEVEL_3:
                    g_pucModeInfoData[ucIndex++] = _0_+3;
                    break;
                default:
                    break;
            }
            g_pucModeInfoData[ucIndex++] = _COMMA_;
            switch(ScalerDpGetLanePreEmpLv(ucPortSel,ucI))
            {
                case _DP_LINK_PREEMPHASIS_LEVEL_0:
                    g_pucModeInfoData[ucIndex++] = _0_+0;
                    break;
                case _DP_LINK_PREEMPHASIS_LEVEL_1:
                    g_pucModeInfoData[ucIndex++] = _0_+1;
                    break;
                case _DP_LINK_PREEMPHASIS_LEVEL_2:
                    g_pucModeInfoData[ucIndex++] = _0_+2;
                    break;
                case _DP_LINK_PREEMPHASIS_LEVEL_3:
                    g_pucModeInfoData[ucIndex++] = _0_+2;
                    break;
                default:
                    break;
            }
            g_pucModeInfoData[ucIndex++] = _RIGHT_BRACE_;
        }
    }

    g_pucModeInfoData[ucIndex++] = _END_;

    //return g_pucModeInfoData;
}
#endif


#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223 || _PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301 || _PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)
	extern void Edid_SN_READ(void);
#endif

void OsdPropGetShowInformationStringAddress(BYTE ucInformaitonItem, BYTE *ucLanguage)
{
	BYTE ucResolutionIndex = OsdPropVideoResolution();
	BYTE ucDest = 0;
	BYTE ucDest2 = 0;
	BYTE ucSrc = 0;
	BYTE *pucArray;
	//EnumDisplayRegion enumRegion = SysRegionGetDisplayRegion(_DISPLAY_RGN_1P);
	//StructTimingInfo stTimingInfo;

	//memset(&stTimingInfo, 0x00, sizeof(StructTimingInfo));
	

	// Read timing info
	//SysRegionGetMeasureResultByRegion(enumRegion, &stTimingInfo);

	switch(ucInformaitonItem)
	{
		case _OSD_INFORMATION_ITEM_RESOLUTION:
			pucArray = str_RESOLUTION;
			break;
		case _OSD_INFORMATION_ITEM_HFREQ:
			pucArray = str_HFREQ;
			break;
		case _OSD_INFORMATION_ITEM_VFREQ:
			pucArray = str_VFREQ;
			break;
		case _OSD_INFORMATION_ITEM_PIXEL_CLOCK:
			pucArray = str_PIXEL;
			break;
		case _OSD_INFORMATION_ITEM_MODEL_NUMBER:
			pucArray = str_MODEL_NO;
			break;
		case _OSD_INFORMATION_ITEM_SN:
			pucArray = str_NULL;
			//pucArray = str_SERIAL_NO;
			break;
		case _OSD_INFORMATION_ITEM_URL:
			pucArray = str_WEBSITE;
			break;
	}



	if(*ucLanguage != 0)
    {
        BYTE ucLanguageIndex = *ucLanguage;

        while(ucLanguageIndex != 0)
        {
            if(pucArray[0] == _END_)
            {
                ucLanguageIndex--;
				g_pucModeInfoData[ucDest++] = _END_;
            }
            pucArray++;
        }
    }

	while(pucArray[ucDest2] != _END_)
	{
		g_pucModeInfoData[ucDest++] = pucArray[ucDest2++];
		
		if(ucDest >= sizeof(g_pucModeInfoData))
			break;
	}


	switch(ucInformaitonItem)
	{
		case _OSD_INFORMATION_ITEM_RESOLUTION:
		{
    		BYTE ucI = OsdPropVideoResolution();
			if(ucI!=0)
			{
			    g_pucModeInfoData[ucDest++] = tSTRING_RESOLUTION_TABLE[ucI][1];
			    g_pucModeInfoData[ucDest++] = tSTRING_RESOLUTION_TABLE[ucI][2];
			    g_pucModeInfoData[ucDest++] = tSTRING_RESOLUTION_TABLE[ucI][3];
			    g_pucModeInfoData[ucDest++] = tSTRING_RESOLUTION_TABLE[ucI][4];
			    g_pucModeInfoData[ucDest++] = tSTRING_RESOLUTION_TABLE[ucI][5];
			    g_pucModeInfoData[ucDest++] = _END_;
			}
			else
			{
				// print H width (ex: "1920")
				if(g_stInputTimingData.usHWidth >= 1000)
				{
					g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usHWidth / 1000) % 10);
				}
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usHWidth / 100) % 10);
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usHWidth / 10) % 10);
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usHWidth / 1) % 10);
				
				// print "x"
				g_pucModeInfoData[ucDest++] = _x_;
				
				// print V height (ex: "1080")
				if(g_stInputTimingData.usVHeight >= 1000)
				{
					g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usVHeight / 1000) % 10);
				}
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usVHeight / 100) % 10);
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usVHeight / 10) % 10);
				g_pucModeInfoData[ucDest++] = _0_ + ((g_stInputTimingData.usVHeight / 1) % 10);

			}
		}
			break;
		case _OSD_INFORMATION_ITEM_HFREQ:
			// print H freq in "xxx.x" format
			g_pucModeInfoData[ucDest++] = (g_stInputTimingData.usHFreq < 1000) ? _ :
			                  				(_0_ + ((g_stInputTimingData.usHFreq / 1000) % 10));
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usHFreq / 100) % 10));
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usHFreq / 10) % 10));
			g_pucModeInfoData[ucDest++] = _DOT_;
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usHFreq / 1) % 10));

			g_pucModeInfoData[ucDest++] = _K_;
			g_pucModeInfoData[ucDest++] = _H_;
			g_pucModeInfoData[ucDest++] = _z_;
			break;
			
		case _OSD_INFORMATION_ITEM_VFREQ:
			// print V freq in "xxx.x" format
			g_pucModeInfoData[ucDest++] = (g_stInputTimingData.usVFreq < 1000) ? _ :
			                  				(_0_ + ((g_stInputTimingData.usVFreq / 1000) % 10));
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usVFreq / 100) % 10));
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usVFreq / 10) % 10));
			g_pucModeInfoData[ucDest++] = _DOT_;
			g_pucModeInfoData[ucDest++] = (_0_ + ((g_stInputTimingData.usVFreq / 1) % 10));

			g_pucModeInfoData[ucDest++] = _H_;
			g_pucModeInfoData[ucDest++] = _z_;
			break;
			
		case _OSD_INFORMATION_ITEM_PIXEL_CLOCK:
			//if(1)
			{
				WORD usPixelClk = ScalerSyncGetInputPixelClk();
				// print pixel clock in in "xxxx.x" format
				g_pucModeInfoData[ucDest++] = (usPixelClk < 10000) ? _ :
				                      (_0_ + ((usPixelClk / 10000) % 10));
				g_pucModeInfoData[ucDest++] = (usPixelClk < 1000) ? _ :
				                      (_0_ + ((usPixelClk / 1000) % 10));
				g_pucModeInfoData[ucDest++] = (_0_ + ((usPixelClk / 100) % 10));
				g_pucModeInfoData[ucDest++] = (_0_ + ((usPixelClk / 10) % 10));
				g_pucModeInfoData[ucDest++] = _DOT_;
				g_pucModeInfoData[ucDest++] = (_0_ + ((usPixelClk / 1) % 10));

				g_pucModeInfoData[ucDest++] = _M_;
				g_pucModeInfoData[ucDest++] = _H_;
				g_pucModeInfoData[ucDest++] = _z_;
			}
			break;
			
		case _OSD_INFORMATION_ITEM_MODEL_NUMBER:
			
			{
				BYTE code pcuModelName[] = {_PROJECT_NAME};

				for(ucDest2=0; ucDest2<sizeof(pcuModelName); ucDest2++)
				{
					g_pucModeInfoData[ucDest++] = pcuModelName[ucDest2];
				}
			}
			
			break;
			
		case _OSD_INFORMATION_ITEM_SN:
			{
				BYTE i=0;
				//RTDFlashGetSNData();
#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223 || _PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301 || _PROJECT_ID==_ID_ZQ_2313E01_BOE_MV238FHB_N63_8BIT_FHD100_WLCD_24FH25_20250207)				
				Edid_SN_READ();
#endif
				while(g_stSNData[i] != 0x0A && i<13)
				{
					g_pucModeInfoData[ucDest++] = (g_stSNData[i] < 0x40)?((g_stSNData[i] - 0x30)+_0_):(g_stSNData[i] - 0x41+_A_);
					i++;
				}
			}
			break;
		case _OSD_INFORMATION_ITEM_URL:
			break;
	}

	g_pucModeInfoData[ucDest++] = _END_;
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdPropGetFontPointer(BYTE ucPointerSelect)
{
    switch(ucPointerSelect)
    {
        default:
        case _PFONT_PAGE_0:
        {
            return GET_OSD_INFO_FONT_POINTER_0();
        }
        case _PFONT_PAGE_1:
        {
            return GET_OSD_INFO_FONT_POINTER_1();
        }
        case _PFONT_PAGE_2:
        {
            return GET_OSD_INFO_FONT_POINTER_2();
        }
        case _PFONT_PAGE_3:
            return GET_OSD_INFO_FONT_POINTER_3();

        case _PFONT_PAGE_SLIDER:
            return GET_OSD_INFO_FONT_POINTER_SLIDER();


		case _PFONT_PAGE_RATE:
		{
			return GET_OSD_INFO_FONT_POINTER_RATE();

		}

			
		case _PFONT_PAGE_POWER:
		{
			return GET_OSD_INFO_FONT_POINTER_POWER();

		}
		
		case _PFONT_PAGE_VIEW:
		{
			return GET_OSD_INFO_FONT_POINTER_VIEW();

		}

		case _PFONT_PAGE_TITLE:
		{
			return GET_OSD_INFO_FONT_POINTER_TITLE();
		
		}
		
		case _PFONT_PAGE_HDR:
		{
			return GET_OSD_INFO_FONT_POINTER_HDR();
		}

		case _PFONT_PAGE_SN:
		{
			return GET_OSD_INFO_FONT_POINTER_SN();
		}

		case _PFONT_PAGE_INF_RATE:
		{
			return GET_OSD_INFO_FONT_POINTER_INF_RATE();
		}
		
    }
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdPropVideoResolution(void)
{
    bit bVideoTiming = _FALSE;
    BYTE ucI = 0;

    if(GET_INPUT_TIMING_VFREQ() > 620)
    {
        return _FALSE;
    }

    if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
    {
        bVideoTiming = _TRUE;
    }
#if(_VGA_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_VGA_COLOR_FORMAT_STATUS() == _COLOR_SPACE_YPBPR)
        {
            //bVideoTiming = _TRUE; // ���·ֱ���Ϊ1080P
        }
    }
#endif
#if(_DVI_SUPPORT == _ON)
    else if((SysSourceGetSourceType() == _SOURCE_DVI))
    {
#if(_DIGITAL_PORT_SUPPORT == _ON)
        if(ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort()) == _HDCP_NONE)
        {
            bVideoTiming = _FALSE;
        }
        else
        {
            bVideoTiming = _TRUE;
        }
#endif
    }
#endif
#if(_HDMI_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_HDMI)
    {
        if(ScalerColorGetColorSpaceRGB(ScalerColorGetColorSpace()) == _FALSE)
        {
            //bVideoTiming = _TRUE; // ���·ֱ���Ϊ1080P
        }
    }
#endif
#if(_DP_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_DP)
    {
        if(ScalerColorGetColorSpaceRGB(ScalerColorGetColorSpace()) == _FALSE)
        {
            bVideoTiming = _TRUE;
        }
    }
#endif

    if(bVideoTiming == _TRUE)
    {
        for(ucI = 1; ucI < 8; ucI++)
        {
            if(GET_INPUT_TIMING_VHEIGHT() == tSTRING_RESOLUTION_TABLE[ucI][0])
            {
                if((tSTRING_RESOLUTION_TABLE[ucI][0] == 480) && (GET_INPUT_TIMING_HWIDTH() == 848))
                {
                    return _FALSE;
                }

                if(((tSTRING_RESOLUTION_TABLE[ucI][0] == 240) ||
                    (tSTRING_RESOLUTION_TABLE[ucI][0] == 288) ||
                    (tSTRING_RESOLUTION_TABLE[ucI][0] == 540)) &&
                   (GET_INPUT_TIMING_INTERLACE_FLG() == _FALSE))
                {
                    return _FALSE;
                }

                return ucI;
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdPropSetFontPointer(BYTE ucPointerSelect, BYTE ucPointer)
{
    ucPointer++;

    switch(ucPointerSelect)
    {
        case _PFONT_PAGE_0:
        {
            if(ucPointer > _OSD_PAGE_0_END)
            {
                ucPointer = _OSD_PAGE_0_START;
            }
            break;
        }
        case _PFONT_PAGE_1:
        {
			if(ucPointer > _OSD_PAGE_1_END)
			{
				ucPointer = _OSD_PAGE_1_START;
			}
            break;
        }
        case _PFONT_PAGE_2:
        {
            if(ucPointer > _OSD_PAGE_2_END)
            {
                ucPointer = _OSD_PAGE_2_START;
            }
            break;
        }
        case _PFONT_PAGE_3:
            if(ucPointer > _OSD_PAGE_3_END)
            {
                ucPointer = _OSD_PAGE_3_START;
            }
            break;
        case _PFONT_PAGE_SLIDER:
            if(ucPointer > _OSD_PAGE_SLIDER_END)
            {
                ucPointer = _OSD_PAGE_SLIDER_START;
            }
            break;

		
        case _PFONT_PAGE_RATE:
            if(ucPointer > _OSD_PAGE_RATE_END)
            {
                ucPointer = _OSD_PAGE_RATE_START;
            }
            break;
			
		case _PFONT_PAGE_POWER:
			if(ucPointer > _OSD_PAGE_POWER_END)
			{
				ucPointer = _OSD_PAGE_POWER_START;
			}
			break;

        case _PFONT_PAGE_VIEW:
            if(ucPointer > _OSD_PAGE_VIEW_END)
            {
                ucPointer = _OSD_PAGE_VIEW_START;
            }
            break;

	    case _PFONT_PAGE_TITLE:
            if(ucPointer > _OSD_PAGE_TITLE_END)
            {
                ucPointer = _OSD_PAGE_TITLE_START;
            }
            break;	

		case _PFONT_PAGE_HDR:
            if(ucPointer > _OSD_PAGE_HDR_END)
            {
                ucPointer = _OSD_PAGE_HDR_START;
            }
            break;

		case _PFONT_PAGE_SN:
            if(ucPointer > _OSD_PAGE_SN_END)
            {
                ucPointer = _OSD_PAGE_SN_START;
            }
            break;

		case _PFONT_PAGE_INF_RATE:
            if(ucPointer > _OSD_PAGE_INF_RATE_END)
            {
                ucPointer = _OSD_PAGE_INF_RATE_START;
            }
            break;
			

        default:
            break;
    }

    return ucPointer;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropFontDataToSram(BYTE ucFptsSelect, BYTE *ucpArray, BYTE ucRotateType)
{

	
    switch(ucFptsSelect)
    {
        case _PFONT_PAGE_0:
        {
// #if(_FW_OSD_HARDWARECOMPRESSION_ROTATE_DEGREE_0_NO_DELAY == _ON)
//             ScalerOsdHardwareCompressionNoDelay(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_0() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #else
            ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_0() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #endif

            if(GET_OSD_INFO_FONT_POINTER_0() >= _OSD_PAGE_0_END)
            {
                SET_OSD_INFO_FONT_POINTER_0(_OSD_PAGE_0_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_0(GET_OSD_INFO_FONT_POINTER_0() + 1);
            }
            break;
        }
        case _PFONT_PAGE_1:
        {
// #if(_FW_OSD_HARDWARECOMPRESSION_ROTATE_DEGREE_0_NO_DELAY == _ON)
//             ScalerOsdHardwareCompressionNoDelay(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_1() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #else
            ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_1() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #endif

            if(GET_OSD_INFO_FONT_POINTER_1() >= _OSD_PAGE_1_END)
            {
                SET_OSD_INFO_FONT_POINTER_1(_OSD_PAGE_1_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_1(GET_OSD_INFO_FONT_POINTER_1() + 1);
            }
            break;
        }
        case _PFONT_PAGE_2:
        {
// #if(_FW_OSD_HARDWARECOMPRESSION_ROTATE_DEGREE_0_NO_DELAY == _ON)
//             ScalerOsdHardwareCompressionNoDelay(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_2() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #else
            ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_2() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
// #endif

            if(GET_OSD_INFO_FONT_POINTER_2() >= _OSD_PAGE_2_END)
            {
                SET_OSD_INFO_FONT_POINTER_2(_OSD_PAGE_2_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_2(GET_OSD_INFO_FONT_POINTER_2() + 1);
				//DebugMessageOsd("2.GET_OSD_INFO_FONT_POINTER_2",GET_OSD_INFO_FONT_POINTER_2());
            }
            break;
        }
        case _PFONT_PAGE_3:
        {
            ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_3() + 256 * _OSD_FONT_MODE_FORCE_256_511) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);

            if(GET_OSD_INFO_FONT_POINTER_3() >= _OSD_PAGE_3_END)
            {
                SET_OSD_INFO_FONT_POINTER_3(_OSD_PAGE_3_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_3(GET_OSD_INFO_FONT_POINTER_3() + 1);
            }
            break;
        }
        case _PFONT_PAGE_SLIDER:
        {

			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_SLIDER() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

            if(GET_OSD_INFO_FONT_POINTER_SLIDER() >= _OSD_PAGE_SLIDER_END)
            {
                SET_OSD_INFO_FONT_POINTER_SLIDER(_OSD_PAGE_SLIDER_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_SLIDER(GET_OSD_INFO_FONT_POINTER_SLIDER() + 1);
            }
            break;
        }
        case _PFONT_PAGE_POWER:
        {
			

			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_POWER() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

            if(GET_OSD_INFO_FONT_POINTER_POWER() >= _OSD_PAGE_POWER_END)
            {
                SET_OSD_INFO_FONT_POINTER_POWER(_OSD_PAGE_POWER_START);
            }
            else
            {
                SET_OSD_INFO_FONT_POINTER_POWER(GET_OSD_INFO_FONT_POINTER_POWER() + 1);
            }
            break;
        }
        case _PFONT_PAGE_RATE:
		{
			

			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_RATE()  + 256 * 0), GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}
	
			if(GET_OSD_INFO_FONT_POINTER_RATE() >= _OSD_PAGE_RATE_END)
			{
				SET_OSD_INFO_FONT_POINTER_RATE(_OSD_PAGE_RATE_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_RATE(GET_OSD_INFO_FONT_POINTER_RATE() + 1);
			}
            break;
		}

		case _PFONT_PAGE_VIEW:
		{
			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_VIEW() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

			if(GET_OSD_INFO_FONT_POINTER_VIEW() >= _OSD_PAGE_VIEW_END)
			{
				SET_OSD_INFO_FONT_POINTER_VIEW(_OSD_PAGE_VIEW_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_VIEW(GET_OSD_INFO_FONT_POINTER_VIEW() + 1);
			}
			break;
		}

		case _PFONT_PAGE_TITLE:
		{
			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_TITLE() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

			if(GET_OSD_INFO_FONT_POINTER_TITLE() >= _OSD_PAGE_TITLE_END)
			{
				SET_OSD_INFO_FONT_POINTER_TITLE(_OSD_PAGE_TITLE_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_TITLE(GET_OSD_INFO_FONT_POINTER_TITLE() + 1);
				DebugMessageOsd("2.GET_OSD_INFO_FONT_POINTER_TITLE",GET_OSD_INFO_FONT_POINTER_TITLE());
			}
			break;
		}

		case _PFONT_PAGE_HDR:
		{
			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_HDR() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

			if(GET_OSD_INFO_FONT_POINTER_HDR() >= _OSD_PAGE_HDR_END)
			{
				SET_OSD_INFO_FONT_POINTER_HDR(_OSD_PAGE_HDR_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_HDR(GET_OSD_INFO_FONT_POINTER_HDR() + 1);
			}
			break;
		}

		case _PFONT_PAGE_SN:
		{
			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_SN() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

			if(GET_OSD_INFO_FONT_POINTER_SN() >= _OSD_PAGE_SN_END)
			{
				SET_OSD_INFO_FONT_POINTER_SN(_OSD_PAGE_SN_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_SN(GET_OSD_INFO_FONT_POINTER_SN() + 1);
			}
			break;
		}

		case _PFONT_PAGE_INF_RATE:
		{
			{
				ScalerOsdHardwareCompression(ucpArray, 27, GET_CURRENT_BANK_NUMBER(), (GET_OSD_INFO_FONT_POINTER_INF_RATE() + 256 * 0) , GET_OSD_INFO_MAP_FONT_BASE_ADDRESS(), ucRotateType, _BURSTWRITE_FROM_XRAM);
			}

			if(GET_OSD_INFO_FONT_POINTER_INF_RATE() >= _OSD_PAGE_INF_RATE_END)
			{
				SET_OSD_INFO_FONT_POINTER_INF_RATE(_OSD_PAGE_INF_RATE_START);
			}
			else
			{
				SET_OSD_INFO_FONT_POINTER_INF_RATE(GET_OSD_INFO_FONT_POINTER_INF_RATE() + 1);
			}
			break;
		}


        default:
            break;
    }
}

extern BYTE GetStringPropExtend_English(WORD index);
#if(_DEF_Vietnam_TEXT)
extern BYTE GetStringPropExtend_Vietnam(WORD index);
#endif
#if(_DEF_THAI_TEXT)
extern BYTE GetStringPropExtend_Thai(WORD index);
#endif
extern BYTE GetStringPropExtend_Japanese(WORD index);
#if(_DEF_KOREAN_TEXT)
extern BYTE GetStringPropExtend_Korean(WORD index);
#endif
extern BYTE GetStringPropExtend_ChineseT(WORD index);
extern BYTE GetStringPropExtend_ChineseS(WORD index);

extern BYTE GetStringPropExtend_PC_Japanese(WORD index);
#if(_DEF_KOREAN_TEXT)
extern BYTE GetStringPropExtend_PC_Korean(WORD index);
#endif
extern BYTE GetStringPropExtend_PC_TChinese(WORD index);
extern BYTE GetStringPropExtend_PC_SChinese(WORD index);

//--------------------------------------------------1
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdPutStringPropFontTable(BYTE ucLanguage, WORD ucFontPoint)
{
	BYTE Temp;

#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON || _DEF_District_swtich_Message)
	BYTE LangugeData_i = 0;

#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
	if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT))
    {
		LangugeData_i = 1;
    }
    else if(GET_OSD_STATE() != _OSD_HOTKEY_FUNC)   
    {
        LangugeData_i = 0;
    }
#endif 
#if(_DEF_District_swtich_Message)
	if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT))
	{
		LangugeData_i = 1;
	}
    else if(GET_OSD_STATE() != _OSD_HOTKEY_FUNC)   
    {
        LangugeData_i = 0;
    }
#endif
#endif
	 //DebugMessageOsd("1.LangugeData_i",LangugeData_i);
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON || _DEF_District_swtich_Message )
    if(LangugeData_i)
	{
		if(ucLanguage == _JAPANESE)
		{
			return GetStringPropExtend_PC_Japanese(ucFontPoint);
		}
#if(_DEF_KOREAN_TEXT)
		else if(ucLanguage == _KOREAN)
		{
			return GetStringPropExtend_PC_Korean(ucFontPoint);
		}
#endif
		else if(ucLanguage == _CHINESE_T)
		{
			return GetStringPropExtend_PC_TChinese(ucFontPoint);
		}
		else if(ucLanguage == _CHINESE_S)
		{
			return GetStringPropExtend_PC_SChinese(ucFontPoint);
		}
	}
#endif
	//DebugMessageOsd("1.ucLanguage",ucLanguage);
	switch(ucLanguage)
	{
		case _ENGLISH:
			Temp = GetStringPropExtend_English(ucFontPoint);
			break;
#if(_DEF_Vietnam_TEXT)			
		case _Vietnam:
			Temp = GetStringPropExtend_Vietnam(ucFontPoint);
			break;
#endif
#if(_DEF_THAI_TEXT)
        case _THAI:
            Temp = GetStringPropExtend_Thai(ucFontPoint);
            break;
#endif
		case _JAPANESE:
			Temp = GetStringPropExtend_Japanese(ucFontPoint);	
			break;
			
#if(_DEF_KOREAN_TEXT)
		case _KOREAN:
			Temp = GetStringPropExtend_Korean(ucFontPoint);	
			break;
#endif
			
		case _CHINESE_T:
			Temp = GetStringPropExtend_ChineseT(ucFontPoint);	
			break;
			
		case _CHINESE_S:
			Temp = GetStringPropExtend_ChineseS(ucFontPoint);	
			break;
			
			
		default:
			Temp = GetStringPropExtend_English(ucFontPoint);
			break;
				
	}
	return Temp;




}



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropPutString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, WORD usString, BYTE ucIndex, BYTE ucColor, BYTE ucLanguage)
{
    BYTE *pucArray = OsdPropGetStringTableAddress(usString,ucIndex,&ucLanguage);
	
    bit bCenterFlag = _FALSE;
    bit bNextLineFlag = _FALSE;
    BYTE pucpTemp[27] = {0};
    BYTE ucElementCount = 0;
    BYTE ucColBackup = ucCol;


    pData[0] = ucLanguage;

    while(pData[0] != _ENGLISH)
    {
        if(pucArray[0] == _END_)
        {
            pData[0]--;
        }
        pucArray++;
    }

    do
    {
        bNextLineFlag = _FALSE;
        memset(pData, 0x00, _DATA_ITEM_LENGTH);
        ucElementCount = 0;

        PDATA_WORD(5) = OsdPropGetFontPointer(ucFptsSelect);

        if(GET_OSD_INFO_STRING_MODE_LENGTH() != 0)
        {
            while((*(pucArray + ucElementCount) != _END_) &&
                  (*(pucArray + ucElementCount) != _NEXT_LINE))// calculate totwl string width
            {
                pData[2] = *(pucArray + ucElementCount);

                switch(pData[2])
                {
                    default:
                        PDATA_WORD(6) = 0;
                        break;

                    case _FONT_SELECT_EXT1:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET1;
                        break;

                    case _FONT_SELECT_EXT2:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET2;
                        break;

                        //if _FONT_SELECT_EXT"N" is defined in XXXOsdTextTableDefine.h, new case should be added, for example
                        /*case _FONT_SELECT_EXT3:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET3;
                        break;*/
                }

                if(PDATA_WORD(6) != 0)
                {
                    ucElementCount++;
                    pData[2] = *(pucArray + ucElementCount);
                }

                if((PDATA_WORD(6) + pData[2]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                {
                    PDATA_WORD(7) += tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];
                }
                else
                {
                    PDATA_WORD(7) += 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];
                }

                ucElementCount++;
            }

            // String col size
            pData[0] = (PDATA_WORD(7) / 12) + (((PDATA_WORD(7) % 12) > 0) ? 1 : 0); // total pixels / 12 (round up)

            if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_CENTER)// center-aligned
            {
                // add one font if centered width and actual sting width is not both even or both odd
                if((((GET_OSD_INFO_STRING_MODE_LENGTH() % 2) == 0) && ((pData[0] % 2) == 1)) ||
                   (((GET_OSD_INFO_STRING_MODE_LENGTH() % 2) == 1) && ((pData[0] % 2) == 0)))
                {
                    pData[0]++;
                }

                pData[9] = ((pData[0] * 12) - PDATA_WORD(7)) / 2;// total center-aligned pixels - total string pixels / 2
            }
            else if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_RIGHT)// right aligned
            {
                pData[9] = (pData[0] * 12) - PDATA_WORD(7);// count right-aligned pixels
            }

            if(pData[9] != 0)// left-aligned
            {
                bCenterFlag = _TRUE;
            }
        }
        ucElementCount = pData[0] = 0;

        // reorder
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT6);
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~(_BIT7 | _BIT5)));

        while((*(pucArray + ucElementCount) != _END_) &&
              (*(pucArray + ucElementCount) != _NEXT_LINE))
        {
            switch(*(pucArray + ucElementCount))
            {
                case _END_:
                    break;

                default:
                    if(pData[5] == 0)// pixel count = 0 ????
                    {
                        pData[2] = *(pucArray + ucElementCount);

                        if(pData[2] == _FONT_BLANK_PIXEL)
                        {
                            pData[5] = *(pucArray + ucElementCount + 1);

                            pData[2] = _;
                        }

                        if(bCenterFlag == _TRUE)
                        {
                            pData[2] = _;
                        }
                    }
                    else
                    {
                        pData[2] = _;
                    }

                    switch(pData[2])
                    {
                        default:
                            PDATA_WORD(6) = 0;
                            break;

                        case _FONT_SELECT_EXT1:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET1;
                            break;

                        case _FONT_SELECT_EXT2:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET2;
                            break;

                            //if _FONT_SELECT_EXT"N" is defined in XXXOsdTextTableDefine.h, new case should be added, for example
                            /*case _FONT_SELECT_EXT3:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET3;
                            break;*/
                    }

                    if(PDATA_WORD(6) != 0)
                    {
                        ucElementCount++;
                        pData[2] = *(pucArray + ucElementCount);
                    }

                    if((PDATA_WORD(6) + pData[2]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];

                            if(bCenterFlag == _TRUE)
                            {
                                pData[3] = pData[9];
                            }
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                            pData[5] -= pData[3];
                        }
                    }
                    else
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];

                            if(bCenterFlag == _TRUE)
                            {
                                pData[3] = pData[9];
                            }
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                            pData[5] -= pData[3];
                        }
                    }
#if(_POWER_CONSUMPTION_HINT_SUPPORT  || _DEF_District_swtich_Message)

#if(_DEF_JAPANESE_TEXT)
                if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
                if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_S)
#endif
				{
					#if(_DEF_Vietnam_TEXT)
					if(ucLanguage != _Vietnam )
					#endif
					{

						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT))
						{
							pData[3] = 12;
						}
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT))
						{
							pData[3] = 12;
						}
#endif

					}

				}
#endif
                    if(pData[5] == 0)
                    {
                        if((*(pucArray + ucElementCount) != _FONT_BLANK_PIXEL))
                        {
                            ucElementCount++;

                            if(bCenterFlag == _TRUE)
                            {
                                ucElementCount = 0;
                            }
                        }
                        else
                        {
                            ucElementCount += 2;
                        }
                    }
                    break;
            }

            if(pData[6] == 0)
            {
                pData[6] = pData[3];
            }


            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT3);    // first bits shift direction: left shift
            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~_BIT2)); // left bits shift direction: rigth shift
            SCALEROSD_FONT_ROTATE_1_2_BITS_SHIFT_SET(((pData[3] - pData[6]) << 4) | pData[6]); // first bits shift and second bits shift

            pData[8] = ucElementCount;
            pData[7] = pData[6];

            for(pData[0] = 0; pData[0] < 9; pData[0]++)
            {
                SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT0); // restart from last three bytes

#if(_DEF_JAPANESE_TEXT)
                if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
                if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_S)
#endif
                {
                //     if(pData[2] >= _GLOBAL_FONT_END)
                //     {
                //         DebugMessageOsd("pData",pData[2]);
                //         DebugMessageOsd("ucLanguage",ucLanguage);

                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }
                //     else
                //     {
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutS2tringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                //     }
                // }
                // else if(PDATA_WORD(6) > _GLOBAL_FONT_END_OFFSET)
                // {
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                // }
#if(_DEF_THAI_TEXT)
                else  if(ucLanguage == _THAI)  
                {        
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }
#endif
#if(_DEF_Vietnam_TEXT)
                else  if(ucLanguage == _Vietnam)  
                {        
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }
#endif
                else// if(ucOffset[0] < _GLOBAL_FONT_END_OFFSET)
                {
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }

                ucElementCount = pData[8];
                pData[6] = pData[7];

                if((pData[6] == 12) || (*(pucArray + ucElementCount) == _END_)) //|| (*(pucArray + ucElementCount) == _NEXT_LINE))
                {
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                }

                while((pData[6] < 12) &&
                      (*(pucArray + ucElementCount) != _END_) &&
                      (*(pucArray + ucElementCount) != _NEXT_LINE))
                {
                    SCALEROSD_FONT_ROTATE_3_L_BITS_SHIFT_SET((pData[6] << 4) | pData[6]); // third bits shift and left bits shift

                    if(pData[5] == 0)
                    {
                        pData[1] = *(pucArray + ucElementCount);

                        if(pData[1] == _FONT_BLANK_PIXEL)
                        {
                            pData[5] = *(pucArray + ucElementCount + 1);

                            pData[1] = _;
                        }
                    }
                    else
                    {
                        pData[1] = _;
                    }

                    if((pData[1] == _FONT_SELECT_EXT1) ||
                       (pData[1] == _FONT_SELECT_EXT2))
                    {
                        PDATA_WORD(7) = (pData[1] == _FONT_SELECT_EXT1) ? _FONT_SELECT_OFFSET1 : _FONT_SELECT_OFFSET2;
                        ucElementCount++;
                        pData[1] = *(pucArray + ucElementCount);
                    }
                    else
                    {
                        PDATA_WORD(7) = 0;
                    }

                    if((PDATA_WORD(7) + pData[1]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                    {

                        if(pData[5] == 0)
                        {
                            pData[3] = tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[1] + PDATA_WORD(7)];
                        }

                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                        }
                    }
                    else
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[1] + PDATA_WORD(7)];
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                        }
                    }
#if(_POWER_CONSUMPTION_HINT_SUPPORT  || _DEF_District_swtich_Message)

#if(_DEF_JAPANESE_TEXT)
                if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
                if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_S)
#endif
				{
					#if(_DEF_Vietnam_TEXT)
					if(ucLanguage != _Vietnam )
                    #elif (_DEF_THAI_TEXT)
                    if(ucLanguage != _THAI )
					#endif
					{
		                if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT))
						{
	                        pData[3] = 12;
	                    }
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
		                if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT))
						{
	                        pData[3] = 12;
	                    }
#endif
					}
				}
#endif
                    ucElementCount ++;
                    pData[6] += pData[3];
#if(_DEF_JAPANESE_TEXT)
					if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
					if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
					if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
					if(ucLanguage >= _CHINESE_S)
#endif
                    {
                    //     if(pData[1] >= _GLOBAL_FONT_END)
                    //     {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
                    //     else
                    //     {
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    //     }
                    // }
                    // else if(PDATA_WORD(7) > _GLOBAL_FONT_END_OFFSET)
                    // {
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    // }
#if(_DEF_THAI_TEXT)
                    else  if(ucLanguage == _THAI)  
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
#endif   
#if(_DEF_Vietnam_TEXT)
                    else  if(ucLanguage == _Vietnam)  
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
#endif
                    else// if(ucOffset[1] < _GLOBAL_FONT_END_OFFSET)
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
                }

                pucpTemp[pData[0] * 3 + 2] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
                pucpTemp[pData[0] * 3 + 1] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
                pucpTemp[pData[0] * 3] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            }

            if(pData[6] <= 12)
            {
                pData[6] = 0;
            }
            else
            {
                pData[6] = pData[6] - 12;

                if(ucElementCount >= 1)
                {
                    ucElementCount--;
                }
                if(ucElementCount != 0)
                {
                    pData[1] = *(pucArray + ucElementCount - 1);

                    if((pData[1] == _FONT_SELECT_EXT1) ||
                       (pData[1] == _FONT_SELECT_EXT2))
                    {
                        ucElementCount--;
                    }
                }
            }

            // Write the pro font data to sram
            OsdPropFontDataToSram(ucFptsSelect, pucpTemp, GET_OSD_ROTATE_STATUS());

            // Record the length (coloumn) of prop string
            pData[4]++;

            // Only shift for the first word
            bCenterFlag = _FALSE;

        }// End of while(*(pArray + stringcnt) != _END_)

        if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_CENTER)
        {
            ucCol = ucColBackup  + ((((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) / 2) < 0) ? 0 : ((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) / 2));
        }
        else if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_RIGHT)
        {
            ucCol = ucColBackup  + (((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) < 0) ? 0 : (GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]));
        }

        ScalerOsdSramAddressCount(ucRow, ucCol, _OSD_BYTEALL);
        for(pData[0] = 0; pData[0] < pData[4]; pData[0]++)
        {
#if(_OSD_FONT_MODE_FORCE_256_511 == _ON)
            ScalerOsdDataPort(_OSD_MODE_BYTE0_256_511);
#else
            ScalerOsdDataPort((PDATA_WORD(5) < 256) ? _OSD_MODE_BYTE0 : _OSD_MODE_BYTE0_256_511);
#endif // End of #if(_OSD_FONT_MODE_FORCE_256_511 == _ON)
            ScalerOsdDataPort(PDATA_WORD(5) & 0xFF);
            ScalerOsdDataPort(ucColor);

            PDATA_WORD(5) = OsdPropSetFontPointer(ucFptsSelect, PDATA_WORD(5));
        }

        if(*(pucArray + ucElementCount) == _NEXT_LINE)
        {
            // Start the next line from pArray
            pucArray += ucElementCount + 1;
            ucRow++;

            bNextLineFlag = _TRUE;
        }

    }while(bNextLineFlag == _TRUE);

    CLR_OSD_INFO_STRING_MODE();
    CLR_OSD_INFO_STRING_MODE_LENGTH();
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
// 0-255�ռ�
void OsdPropPutStringPage0(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, WORD usString, BYTE ucIndex, BYTE ucColor, BYTE ucLanguage)
{
    BYTE *pucArray = OsdPropGetStringTableAddress(usString,ucIndex,&ucLanguage);
    bit bCenterFlag = _FALSE;
    bit bNextLineFlag = _FALSE;
    BYTE pucpTemp[27] = {0};
    BYTE ucElementCount = 0;
    BYTE ucColBackup = ucCol;




    pData[0] = ucLanguage;

    while(pData[0] != _ENGLISH)
    {
        if(pucArray[0] == _END_)
        {
            pData[0]--;
        }
        pucArray++;
    }

    do
    {
        bNextLineFlag = _FALSE;
        memset(pData, 0x00, _DATA_ITEM_LENGTH);
        ucElementCount = 0;

        PDATA_WORD(5) = OsdPropGetFontPointer(ucFptsSelect);

        if(GET_OSD_INFO_STRING_MODE_LENGTH() != 0)
        {
            while((*(pucArray + ucElementCount) != _END_) &&
                  (*(pucArray + ucElementCount) != _NEXT_LINE))// calculate totwl string width
            {
                pData[2] = *(pucArray + ucElementCount);

                switch(pData[2])
                {
                    default:
                        PDATA_WORD(6) = 0;
                        break;

                    case _FONT_SELECT_EXT1:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET1;
                        break;

                    case _FONT_SELECT_EXT2:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET2;
                        break;

                        //if _FONT_SELECT_EXT"N" is defined in XXXOsdTextTableDefine.h, new case should be added, for example
                        /*case _FONT_SELECT_EXT3:
                        PDATA_WORD(6) = _FONT_SELECT_OFFSET3;
                        break;*/
                }

                if(PDATA_WORD(6) != 0)
                {
                    ucElementCount++;
                    pData[2] = *(pucArray + ucElementCount);
                }

                if((PDATA_WORD(6) + pData[2]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                {
                    PDATA_WORD(7) += tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];
                }
                else
                {
                    PDATA_WORD(7) += 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];
                }

                ucElementCount++;
            }

            // String col size
            pData[0] = (PDATA_WORD(7) / 12) + (((PDATA_WORD(7) % 12) > 0) ? 1 : 0); // total pixels / 12 (round up)

            if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_CENTER)// center-aligned
            {
                // add one font if centered width and actual sting width is not both even or both odd
                if((((GET_OSD_INFO_STRING_MODE_LENGTH() % 2) == 0) && ((pData[0] % 2) == 1)) ||
                   (((GET_OSD_INFO_STRING_MODE_LENGTH() % 2) == 1) && ((pData[0] % 2) == 0)))
                {
                    pData[0]++;
                }

                pData[9] = ((pData[0] * 12) - PDATA_WORD(7)) / 2;// total center-aligned pixels - total string pixels / 2
            }
            else if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_RIGHT)// right aligned
            {
                pData[9] = (pData[0] * 12) - PDATA_WORD(7);// count right-aligned pixels
            }

            if(pData[9] != 0)// left-aligned
            {
                bCenterFlag = _TRUE;
            }
        }
        ucElementCount = pData[0] = 0;

        // reorder
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT6);
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~(_BIT7 | _BIT5)));

        while((*(pucArray + ucElementCount) != _END_) &&
              (*(pucArray + ucElementCount) != _NEXT_LINE))
        {
            switch(*(pucArray + ucElementCount))
            {
                case _END_:
                    break;

                default:
                    if(pData[5] == 0)// pixel count = 0 ????
                    {
                        pData[2] = *(pucArray + ucElementCount);

                        if(pData[2] == _FONT_BLANK_PIXEL)
                        {
                            pData[5] = *(pucArray + ucElementCount + 1);

                            pData[2] = _;
                        }

                        if(bCenterFlag == _TRUE)
                        {
                            pData[2] = _;
                        }
                    }
                    else
                    {
                        pData[2] = _;
                    }

                    switch(pData[2])
                    {
                        default:
                            PDATA_WORD(6) = 0;
                            break;

                        case _FONT_SELECT_EXT1:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET1;
                            break;

                        case _FONT_SELECT_EXT2:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET2;
                            break;

                            //if _FONT_SELECT_EXT"N" is defined in XXXOsdTextTableDefine.h, new case should be added, for example
                            /*case _FONT_SELECT_EXT3:
                            PDATA_WORD(6) = _FONT_SELECT_OFFSET3;
                            break;*/
                    }

                    if(PDATA_WORD(6) != 0)
                    {
                        ucElementCount++;
                        pData[2] = *(pucArray + ucElementCount);
                    }

                    if((PDATA_WORD(6) + pData[2]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];

                            if(bCenterFlag == _TRUE)
                            {
                                pData[3] = pData[9];
                            }
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                            pData[5] -= pData[3];
                        }
                    }
                    else
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[2] + PDATA_WORD(6)];

                            if(bCenterFlag == _TRUE)
                            {
                                pData[3] = pData[9];
                            }
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                            pData[5] -= pData[3];
                        }
                    }
#if(_POWER_CONSUMPTION_HINT_SUPPORT  || _DEF_District_swtich_Message)

#if(_DEF_JAPANESE_TEXT)
                if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
                if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_S)
#endif
				{
					#if(_DEF_Vietnam_TEXT)
					if(ucLanguage != _Vietnam)
					#endif
					{
						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT))
						{
							pData[3] = 12;
						}
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT))
						{
							pData[3] = 12;
						}
#endif

					}

				}
#endif
                    if(pData[5] == 0)
                    {
                        if((*(pucArray + ucElementCount) != _FONT_BLANK_PIXEL))
                        {
                            ucElementCount++;

                            if(bCenterFlag == _TRUE)
                            {
                                ucElementCount = 0;
                            }
                        }
                        else
                        {
                            ucElementCount += 2;
                        }
                    }
                    break;
            }

            if(pData[6] == 0)
            {
                pData[6] = pData[3];
            }


            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT3);    // first bits shift direction: left shift
            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~_BIT2)); // left bits shift direction: rigth shift
            SCALEROSD_FONT_ROTATE_1_2_BITS_SHIFT_SET(((pData[3] - pData[6]) << 4) | pData[6]); // first bits shift and second bits shift

            pData[8] = ucElementCount;
            pData[7] = pData[6];

            for(pData[0] = 0; pData[0] < 9; pData[0]++)
            {
                SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT0); // restart from last three bytes
#if(_DEF_JAPANESE_TEXT)
				if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
				if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
				if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
				if(ucLanguage >= _CHINESE_S)
#endif
                {
                //     if(pData[2] >= _GLOBAL_FONT_END)
                //     {
                //         DebugMessageOsd("pData",pData[2]);
                //         DebugMessageOsd("ucLanguage",ucLanguage);

                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }
                //     else
                //     {
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutS2tringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                //     }
                // }
                // else if(PDATA_WORD(6) > _GLOBAL_FONT_END_OFFSET)
                // {
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                // }
#if(_DEF_THAI_TEXT)
                    else  if(ucLanguage == _THAI)  
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                    }
#endif   
#if(_DEF_Vietnam_TEXT)
                else  if(ucLanguage == _Vietnam)  
                {
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage), (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }
#endif
                else// if(ucOffset[0] < _GLOBAL_FONT_END_OFFSET)
                {
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3))));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 1)));
                    SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[2] + PDATA_WORD(6)) * 27) + (pData[0] * 3) + 2)));
                }

                ucElementCount = pData[8];
                pData[6] = pData[7];

                if((pData[6] == 12) || (*(pucArray + ucElementCount) == _END_)) //|| (*(pucArray + ucElementCount) == _NEXT_LINE))
                {
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                    SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                }

                while((pData[6] < 12) &&
                      (*(pucArray + ucElementCount) != _END_) &&
                      (*(pucArray + ucElementCount) != _NEXT_LINE))
                {
                    SCALEROSD_FONT_ROTATE_3_L_BITS_SHIFT_SET((pData[6] << 4) | pData[6]); // third bits shift and left bits shift

                    if(pData[5] == 0)
                    {
                        pData[1] = *(pucArray + ucElementCount);

                        if(pData[1] == _FONT_BLANK_PIXEL)
                        {
                            pData[5] = *(pucArray + ucElementCount + 1);

                            pData[1] = _;
                        }
                    }
                    else
                    {
                        pData[1] = _;
                    }

                    if((pData[1] == _FONT_SELECT_EXT1) ||
                       (pData[1] == _FONT_SELECT_EXT2))
                    {
                        PDATA_WORD(7) = (pData[1] == _FONT_SELECT_EXT1) ? _FONT_SELECT_OFFSET1 : _FONT_SELECT_OFFSET2;
                        ucElementCount++;
                        pData[1] = *(pucArray + ucElementCount);
                    }
                    else
                    {
                        PDATA_WORD(7) = 0;
                    }

                    if((PDATA_WORD(7) + pData[1]) < (_GLOBAL_FONT_END_OFFSET + _EUROPE_END))
                    {

                        if(pData[5] == 0)
                        {
                            pData[3] = tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[1] + PDATA_WORD(7)];
                        }

                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                        }
                    }
                    else
                    {
                        if(pData[5] == 0)
                        {
                            pData[3] = 12;//tOSD_TABLE_LANGUAGE_FONT_WIDTH[ucLanguage][pData[1] + PDATA_WORD(7)];
                        }
                        else
                        {
                            pData[3] = (pData[5] > 12) ? 12 : pData[5];
                        }
                    }
#if(_POWER_CONSUMPTION_HINT_SUPPORT  || _DEF_District_swtich_Message)

#if(_DEF_JAPANESE_TEXT)
                if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
                if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
                if(ucLanguage >= _CHINESE_S)
#endif
				{
					#if(_DEF_Vietnam_TEXT)
					if(ucLanguage != _Vietnam)
                    #elif (_DEF_THAI_TEXT)
                    if(ucLanguage != _THAI)
					#endif
					{
						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT))
						{
							pData[3] = 12;
						}
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
						if((GET_OSD_STATE() == _OSD_HOTKEY_FUNC) && (OSD_HOT_KEY_PAGE == _OSD_HOTKEY_POWER_CONSUMPTION_HINT))
						{
							pData[3] = 12;
						}
#endif

					}

				}
#endif
                    ucElementCount ++;
                    pData[6] += pData[3];
#if(_DEF_JAPANESE_TEXT)
					if(ucLanguage >= _JAPANESE)
#elif(_DEF_KOREAN_TEXT)
					if(ucLanguage >= _KOREAN)
#elif(_DEF_TCHINESE_TEXT)
					if(ucLanguage >= _CHINESE_T)
#elif(_DEF_SCHINESE_TEXT)
					if(ucLanguage >= _CHINESE_S)
#endif
                    {
                    //     if(pData[1] >= _GLOBAL_FONT_END)
                    //     {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
                    //     else
                    //     {
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                    //         SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    //     }
                    // }
                    // else if(PDATA_WORD(7) > _GLOBAL_FONT_END_OFFSET)
                    // {
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                    //     SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage + 1), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    // }
#if(_DEF_THAI_TEXT)
                    else  if(ucLanguage == _THAI)  
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
#endif      
#if(_DEF_Vietnam_TEXT)
                    else  if(ucLanguage == _Vietnam)  
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable((ucLanguage ), (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
#endif
                    else// if(ucOffset[1] < _GLOBAL_FONT_END_OFFSET)
                    {
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3))));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 1)));
                        SCALEROSD_FONT_ROTATE_INPUT_SET(OsdPutStringPropFontTable(0, (((pData[1] + PDATA_WORD(7)) * 27) + (pData[0] * 3) + 2)));
                    }
                }

                pucpTemp[pData[0] * 3 + 2] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
                pucpTemp[pData[0] * 3 + 1] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
                pucpTemp[pData[0] * 3] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            }

            if(pData[6] <= 12)
            {
                pData[6] = 0;
            }
            else
            {
                pData[6] = pData[6] - 12;

                if(ucElementCount >= 1)
                {
                    ucElementCount--;
                }
                if(ucElementCount != 0)
                {
                    pData[1] = *(pucArray + ucElementCount - 1);

                    if((pData[1] == _FONT_SELECT_EXT1) ||
                       (pData[1] == _FONT_SELECT_EXT2))
                    {
                        ucElementCount--;
                    }
                }
            }

            // Write the pro font data to sram
            OsdPropFontDataToSram(ucFptsSelect, pucpTemp, GET_OSD_ROTATE_STATUS());

            // Record the length (coloumn) of prop string
            pData[4]++;

            // Only shift for the first word
            bCenterFlag = _FALSE;

        }// End of while(*(pArray + stringcnt) != _END_)

        if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_CENTER)
        {
            ucCol = ucColBackup  + ((((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) / 2) < 0) ? 0 : ((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) / 2));
        }
        else if(GET_OSD_INFO_STRING_MODE() == _PUT_STRING_RIGHT)
        {
            ucCol = ucColBackup  + (((GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]) < 0) ? 0 : (GET_OSD_INFO_STRING_MODE_LENGTH() - pData[4]));
        }

        ScalerOsdSramAddressCount(ucRow, ucCol, _OSD_BYTEALL);
        for(pData[0] = 0; pData[0] < pData[4]; pData[0]++)
        {
            ScalerOsdDataPort(_OSD_MODE_BYTE0);

            ScalerOsdDataPort(PDATA_WORD(5) & 0xFF);
            ScalerOsdDataPort(ucColor);

            PDATA_WORD(5) = OsdPropSetFontPointer(ucFptsSelect, PDATA_WORD(5));
        }

        if(*(pucArray + ucElementCount) == _NEXT_LINE)
        {
            // Start the next line from pArray
            pucArray += ucElementCount + 1;
            ucRow++;

            bNextLineFlag = _TRUE;
        }

    }while(bNextLineFlag == _TRUE);

    CLR_OSD_INFO_STRING_MODE();
    CLR_OSD_INFO_STRING_MODE_LENGTH();
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropGetShowVFreqStringAddress(void)
{
    WORD usTemp = 0;
    BYTE ucI = 0;
    BYTE i = 0;

    usTemp = GET_INPUT_TIMING_VFREQ();

	if(GET_INPUT_TIMING_VFREQ() >= 1000)
	{
		ucI = 4;
		i = 3;
	}
	else
	{
		ucI = 3;
		i = 2;
	}
	
    g_pucModeInfoData[ucI+1] = _H_;
    g_pucModeInfoData[ucI+2] = _z_;
    g_pucModeInfoData[ucI+3] = _END_;


    while(_TRUE)
    {
        if(ucI == i)
        {
            g_pucModeInfoData[ucI] = _DOT_;
        }
        else
        {
            g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;
        }

        if(usTemp <= 0)
        {
            break;
        }
        ucI--;
    }

}

void OsdPropGetShowResolutionHWidthVHeight(void)
{
	
    WORD usTemp = 0;
    BYTE usCount = 0;
    BYTE ucI = 0; //OsdPropVideoResolution(); 
    BYTE ucJ = 0;
	if(GET_INPUT_TIMING_HWIDTH() >= 1000)
	{
		ucI = 3;
	}
	else
	{
		ucI = 2;
	}
	
	usTemp = GET_INPUT_TIMING_HWIDTH();
	
	
	while(_TRUE)
	{
		g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
		usTemp /= 10;
	
		if(usTemp <= 0)
		{
			break;
		}
		ucI--;
		usCount++;
	}

	if(GET_INPUT_TIMING_HWIDTH() >= 1000)
	{
		g_pucModeInfoData[4] = _x_;
		usCount++;
	}
	else
	{
		g_pucModeInfoData[3] = _x_;
		usCount++;
	}
	

	if(GET_INPUT_TIMING_VHEIGHT() >= 1000)
	{
		ucI = 3;
	}
	else
	{
		ucI = 2;
	}
	
	usTemp = GET_INPUT_TIMING_VHEIGHT();

	ucJ = (usCount+1);


	while(_TRUE)
	{
		g_pucModeInfoData[ucI+ucJ] = usTemp % 10 + _0_;
		usTemp /= 10;

		if(usTemp <= 0)
		{
			break;
		}
		ucI--;
		usCount++;
	}
	
	g_pucModeInfoData[usCount+2] = _END_;



}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropGetShowHFreqPClkStringAddress(BYTE SELECT)
{
    BYTE ucI = 0;
    BYTE ucJ = 0;
    WORD usFreq = ScalerSyncGetInputPixelClk();
    WORD usTemp = GET_INPUT_TIMING_HFREQ();

	if(SELECT==0)
	{
		
		ucI = 4;
		
		while(_TRUE)
		{
			if(ucI == 3)
			{
				g_pucModeInfoData[ucI] = _DOT_;
			}
			else
			{
				g_pucModeInfoData[ucI] = usTemp % 10 + _0_;
				usTemp /= 10;
			}
		
			if(usTemp <= 0)
			{
				break;
			}
			ucI--;
		}


	    g_pucModeInfoData[5] = _K_;
	    g_pucModeInfoData[6] = _H_;
	    g_pucModeInfoData[7] = _z_;
		g_pucModeInfoData[8] = _END_;

	}
	else
	{
		
		ucJ = 4;
		
		while(_TRUE)
		{
			if(ucJ == 3)
			{
				g_pucModeInfoData[ucJ] = _DOT_;
			}
			else
			{
				g_pucModeInfoData[ucJ] = usFreq % 10 + _0_;
				usFreq /= 10;
			}
		
			if(usFreq <= 0)
			{
				break;
			}
			ucJ--;
		}
		
		g_pucModeInfoData[5] = _M_;
		g_pucModeInfoData[6] = _H_;
		g_pucModeInfoData[7] = _z_;
		g_pucModeInfoData[8] = _END_;

	}


    //return g_pucModeInfoData;
}



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropPutStringCenter(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucFptsSelect, WORD usString, BYTE ucIndex, BYTE ucColor, BYTE ucLanguage)
{
    SET_OSD_INFO_STRING_MODE(_PUT_STRING_CENTER);
    SET_OSD_INFO_STRING_MODE_LENGTH(ucWidth);
	
	if(ucFptsSelect==_PFONT_PAGE_RATE) // ��page0 (0-255�ռ�)
    	OsdPropPutStringPage0(ucRow, ucCol, ucFptsSelect, usString, ucIndex, ucColor, ucLanguage);
	else
    	OsdPropPutString(ucRow, ucCol, ucFptsSelect, usString, ucIndex, ucColor, ucLanguage);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint, BYTE ucColor)
{
/*
    BYTE ucIndex = 0;
    BYTE ucTemp = 0;
    BYTE pucDataSN[7] = {0};
    bit bShowNuberOn = (ucPar & _BIT1) >> 1;
    bit bAlignLeftOrRight = ((ucPar & _BIT0) == 0) ? (_ALIGN_LEFT) : (_ALIGN_RIGHT);
    BYTE ucNumberCount = (ucPar & (_BIT6 | _BIT5 | _BIT4)) >> 4;
    BYTE ucTemp2 = 0;


    pucDataSN[0] = (_0_ + (ulValue / 100000));
    pucDataSN[1] = (_0_ + (ulValue % 100000 / 10000));
    pucDataSN[2] = (_0_ + (ulValue % 10000) / 1000);
    pucDataSN[3] = (_0_ + (ulValue % 1000) / 100);
    pucDataSN[4] = (_0_ + (ulValue % 100) / 10);
    pucDataSN[5] = (_0_ + (ulValue % 10));

    for(ucIndex = 0; ucIndex < 6; ucIndex++)
    {
        if(pucDataSN[ucIndex] != _0_)
        {
            ucIndex = 6 - ucIndex;
            break;
        }
    }

    if((ulValue == 0) && (bShowNuberOn == _FALSE))
    {
        ucIndex = 1; // just show "0"
    }

    ucTemp = ucNumberCount;
    if((bShowNuberOn != _TRUE) && (ucTemp < ucIndex))
    {
        ucTemp = ucIndex; // replace the number to real
    }

    for(ucTemp2 = 0; ucTemp2 < ucTemp; ucTemp2++)
    {
        if(ucIndex > ucTemp2)
        {
            pucDataSN[ucTemp2] = pucDataSN[(6 - ucIndex) + ucTemp2];
        }
        else
        {
            pucDataSN[ucTemp2] = _; // Space
        }
    }
	
	if(ucFontPoint==_PFONT_PAGE_POWER)
	{
		pucDataSN[ucTemp2] = _PERCENT_;
		pucDataSN[ucTemp2+1] = _END_;
	}
	else
	    pucDataSN[ucTemp2] = _END_;

	
    g_pucShowNumberAddress = &pucDataSN[0];
*/



    BYTE ucIndex = 0;
    BYTE ucTemp = 0;
    BYTE ucI = 0;
    BYTE pucDataSN[16] = {0};

    pucDataSN[5] = (_0_ + (ulValue / 100000));
    pucDataSN[4] = (_0_ + (ulValue % 100000 / 10000));
    pucDataSN[3] = (_0_ + (ulValue % 10000) / 1000);
    pucDataSN[2] = (_0_ + (ulValue % 1000) / 100);
    pucDataSN[1] = (_0_ + (ulValue % 100) / 10);
    pucDataSN[0] = (_0_ + (ulValue % 10));

    for(ucIndex = 0; ucIndex < 6; ucIndex++)
    {
        if(pucDataSN[5 - ucIndex] != ((bit)(ucPar & _BIT1) ? _ : _0_))
        {
            ucIndex = 5 - ucIndex;
            break;
        }
    }

    if((ulValue == 0) && ((bit)(ucPar & 0x02) == 0))
    {
        ucIndex = 0;
    }

    if((bit)(ucPar & _BIT1) != 0)
    {
        ucTemp = (ucPar & 0x70) >> 4;
        ucIndex = (ucPar & 0x70) >> 4;
    }
    else
    {
        ucTemp = (ucPar & 0x70) >> 4;

        if(ucTemp < ucIndex)
        {
            ucTemp = ucIndex;
        }
    }

    for(ucI = 0; ucI <= ucTemp; ucI++)
    {
        if(ucIndex >= ucTemp)
        {
            pucDataSN[ucI + 8] = pucDataSN[ucIndex - ucI];
        }
        else
        {
            if(ucI < (ucTemp - ucIndex))
            {
                pucDataSN[ucI + 8] = 0x00;
            }
            else
            {
                pucDataSN[ucI + 8] = pucDataSN[ucIndex - (ucI - (ucTemp - ucIndex))];
            }
        }
    }
    if((ucPar & 0x01) == _ALIGN_LEFT) // Align Right
    {
		if(ucFontPoint==_PFONT_PAGE_POWER)
		{

			{
				pucDataSN[8 + ucTemp + 1] = _PERCENT_; 
				pucDataSN[8 + ucTemp + 2] = _END_;

			}

		}
		else
		{
			pucDataSN[8 + ucTemp + 1] = _; // clear
			//pucDataSN[8 + ucTemp + 2] = _; // clear
			pucDataSN[8 + ucTemp + 2] = _END_;

		}

    }
    else
    {
        pucDataSN[8 + ucTemp + 1] = _END_;
    }

    g_pucShowNumberAddress = &pucDataSN[8];


    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    if((ucPar & 0x01) == _ALIGN_RIGHT) // Align Right
    {
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), 0x4C, _OSD_BYTE0);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), 0x00, _OSD_BYTE1);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), ((FG_COLOR(ucColor & 0x0F) << 4) | BG_COLOR(ucColor & 0x0F)), _OSD_BYTE2);
        //ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdPropPutString(ucRow, (ucCol - ulValue), ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH); // (ucCol - ulValue)?���һֱ�ڱ�
    }
    else
    {
	    if(0)//(ucFontPoint==_PFONT_PAGE_POWER)
	    {
	        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), 0x4C, _OSD_BYTE0);
	        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), 0x00, _OSD_BYTE1);
	        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), ((FG_COLOR(ucColor & 0x0F) << 4) | BG_COLOR(ucColor & 0x0F)), _OSD_BYTE2);
	        //ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		}

		if(ucFontPoint==_PFONT_PAGE_POWER || ucFontPoint==_PFONT_PAGE_SLIDER)
			OsdPropPutStringPage0(ucRow, ucCol, ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH);
		else
        	OsdPropPutString(ucRow, ucCol, ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH);
    }
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdPropShowNumber_1(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint, BYTE ucColor)
{
    BYTE ucIndex = 0;
    BYTE ucTemp = 0;
    BYTE pucDataSN[7] = {0};
    bit bShowNuberOn = (ucPar & _BIT1) >> 1;
    bit bAlignLeftOrRight = ((ucPar & _BIT0) == 0) ? (_ALIGN_LEFT) : (_ALIGN_RIGHT);
    BYTE ucNumberCount = (ucPar & (_BIT6 | _BIT5 | _BIT4)) >> 4;
    BYTE ucTemp2 = 0;


    pucDataSN[0] = (_0_ + (ulValue / 100000));
    pucDataSN[1] = (_0_ + (ulValue % 100000 / 10000));
    pucDataSN[2] = (_0_ + (ulValue % 10000) / 1000);
    pucDataSN[3] = (_0_ + (ulValue % 1000) / 100);
    pucDataSN[4] = (_0_ + (ulValue % 100) / 10);
    pucDataSN[5] = (_0_ + (ulValue % 10));

    for(ucIndex = 0; ucIndex < 6; ucIndex++)
    {
        if(pucDataSN[ucIndex] != _0_)
        {
            ucIndex = 6 - ucIndex;
            break;
        }
    }

    if((ulValue == 0) && (bShowNuberOn == _FALSE))
    {
        ucIndex = 1; // just show "0"
    }

    ucTemp = ucNumberCount;
    if((bShowNuberOn != _TRUE) && (ucTemp < ucIndex))
    {
        ucTemp = ucIndex; // replace the number to real
    }

    for(ucTemp2 = 0; ucTemp2 < ucTemp; ucTemp2++)
    {
        if(ucIndex > ucTemp2)
        {
            pucDataSN[ucTemp2] = pucDataSN[(6 - ucIndex) + ucTemp2];
        }
        else
        {
            pucDataSN[ucTemp2] = _; // Space
        }
    }
	
	if(ucFontPoint==_PFONT_PAGE_POWER)
	{
		pucDataSN[ucTemp2] = _PERCENT_;
		pucDataSN[ucTemp2+1] = _END_;
	}
	else
	    pucDataSN[ucTemp2] = _END_;
    g_pucShowNumberAddress = &pucDataSN[0];

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    if(bAlignLeftOrRight == _ALIGN_RIGHT) // Align Right
    {
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), 0x4C, _OSD_BYTE0);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), 0x00, _OSD_BYTE1);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol - ucTemp), LENGTH(ucNumberCount + 1), ((FG_COLOR(ucColor & 0x0F) << 4) | BG_COLOR(ucColor & 0x0F)), _OSD_BYTE2);
        //ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        OsdPropPutString(ucRow, (ucCol - ulValue), ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH); // (ucCol - ulValue)?���һֱ�ڱ�
    }
    else
    {
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), 0x4C, _OSD_BYTE0);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), 0x00, _OSD_BYTE1);
        //ScalerOsdSramDataValue(ROW(ucRow), COL(ucCol), LENGTH(ucNumberCount + 1), ((FG_COLOR(ucColor & 0x0F) << 4) | BG_COLOR(ucColor & 0x0F)), _OSD_BYTE2);
        //ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		if(ucFontPoint==_PFONT_PAGE_POWER || ucFontPoint==_PFONT_PAGE_SLIDER)
			OsdPropPutStringPage0(ucRow, ucCol, ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH);
		else
        	OsdPropPutString(ucRow, ucCol, ucFontPoint, _STRING_SHOW_NUMBER, 0, ucColor, _ENGLISH);
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE *OsdPropGetStringTableAddress(WORD usString, BYTE ucIndex, BYTE *ucLanguage)
{
    BYTE *pucArray = tsOsdNull;
    BYTE  tempdata[16] = {0};
	BYTE i = 0;

	//DebugMessageOsd("0.ucLanguage",*ucLanguage);

    switch(usString)
    {
        case _STRING_TITLE_ITEM0:
            pucArray = tsOSD_MAIN_ITEM0[ucIndex];
            break;
        case _STRING_TITLE_ITEM1:
            pucArray = tsOSD_MAIN_ITEM1[ucIndex];
            break;
        case _STRING_ITEM:
			if(ucIndex==(_MENU_FUN_INPUT_0-_OSD_FUN_START) || ucIndex==(_MENU_FUN_INPUT_1-_OSD_FUN_START)  \
				|| ucIndex==(_MENU_FUN_INPUT_2-_OSD_FUN_START) || ucIndex==(_MENU_FUN_INPUT_3-_OSD_FUN_START))
				*ucLanguage = _ENGLISH; 
            pucArray = tsOSD_STRING_ITEM_TABLE[ucIndex];
            break;
        case _STRING_MUTE_ITEM:
            pucArray = tsOSD_STRING_MUTE_ITEM[ucIndex];
            break;
        case _STRING_CONTRAST_BRIGHTNESS_ITEM:
            pucArray = tsOSD_STRING_CONTRAST_BRIGHTNESS_ITEM[ucIndex];
            break;
        case _STRING_SIX_AXIS_ITEM:
            pucArray = tsOSD_STRING_SIX_AXIS_COLOR_ITEM[ucIndex];
            break;
        case _STRING_TEMP_ITEM:
            pucArray = tsOSD_STRING_COLOR_TEMP_ITEM[ucIndex];
            break;
        case _STRING_MODE_ITEM:
            pucArray = tsOSD_STRING_COLOR_MODE_ITEM[ucIndex];
            break;
        case _STRING_SPACE_ITEM:
            pucArray = tsOSD_STRING_COLOR_SPACE_ITEM[ucIndex];
            break;
        case _STRING_RANGE_ITEM:
            pucArray = tsOSD_STRING_COLOR_RANGE_ITEM[ucIndex];
            break;
        case _STRING_HDR_ITEM:
            pucArray = tsOSD_STRING_HDR_ITEM[ucIndex];
            break;
        case _STRING_ASPECT_ITEM:
            pucArray = tsOSD_STRING_ASPECT_RATIO_ITEM[ucIndex];
            break;
        case _STRING_OVERSCAN_ITEM:
            pucArray = tsOSD_STRING_OVERSCAN_ITEM[ucIndex];
            break;
        case _STRING_RESPONSE_TIME_ITEM:
            pucArray = tsOSD_STRING_RESPONSE_TIME_ITEM[ucIndex];
            break;
        case _STRING_LANGUAGE_ITEM:
            pucArray = tsOSD_STRING_LANGUAGE_ITEM[ucIndex];
            break;
        case _STRING_FREESYNC_ITEM:
            pucArray = tsOSD_STRING_FREESYNC_ITEM[ucIndex];
            break;
        case _STRING_MPRT_ITEM:
            pucArray = tsOSD_STRING_FREESYNC_ITEM[ucIndex];
            break;
        case _STRING_NOTICE_ITEM:
            pucArray = tsOSD_STRING_NOTICE_ITEM[ucIndex];
            break;
        case _STRING_OSD_SIZE_ITEM:
            pucArray = tsOSD_STRING_SIX_OSDSIZE_ITEM[ucIndex];
            break;
        case _STRING_OSD_BACKGROUND_ITEM:
            pucArray = tsOSD_STRING_BACKGROUND_ITEM[ucIndex];
            break;
        case _STRING_OSD_PIVOT_ITEM:
            pucArray = tsOSD_STRING_PIVOT_ITEM[ucIndex];
            break;
        case _STRING_POWER_INDICATOR_ITEM:
            pucArray = tsOSD_STRING_POWER_INDICATOR_ITEM[ucIndex];
            break;
        case _STRING_AUTO_POWEROFF_ITEM:
            pucArray = tsOSD_STRING_POWER_OFF_ITEM[ucIndex];
            break;
        case _STRING_SLEEP_ITEM:
            pucArray = tsOSD_STRING_SLEEP_ITEM[ucIndex];
            break;
		case _STRING_NO_SIGNAL :	  
		case _STRING_NO_CABLE :	  
			pucArray = str_NO_SIGNAL;
			break;		
		case _STRING_NO_SUPPORT :	  
			pucArray = str_OOR;
			break;		
		case _STRING_AUTO_ADJUST :	  
			pucArray = str_auto_image;//str_AUTO_ADJUSTING;
			break;		
		case _STRING_AUTO_COLOR :
            *ucLanguage = _ENGLISH; 	  
			pucArray = str_AUTO_COLOR;
			break;
#if(_POWER_CONSUMPTION_HINT_SUPPORT == _ON)
		case _STRING_POWER_CONSUMPTION_HINT:
			pucArray = tOSD_PC_HINT_TABLE[ucIndex];
			break;
#endif
		case _OSD_STR_2ND_INFO:
			pucArray = tOSD_2ND_INFOR_TABLE[ucIndex];
			break;

		case _OSD_STR_AUTO_POWER_OFF:
            pucArray = str_POWER_OFF;
            break;
			
		case _OSD_STR_SLEEP_TITLE:
			pucArray = str_SLEEP;
			break;

		case _OSD_STR_SLEEP_TIME:
			pucArray = tOSD_3RD_SLEEP_TABLE[ucIndex];
			break;

		case _OSD_STR_NOTICE_TITLE:
			pucArray = str_NOTICE;
			break;

		case _OSD_STR_NOTICE:
			pucArray = tOSD_NOTICE_TABLE[ucIndex];
			break;
#if (_AI_EYE_PROTECTION == _ON)
		case _OSD_STR_AI_DISTANCE_TITLE:
			pucArray = str_DISTANCE_WARNING;
			break;
		case _OSD_STR_AI_DISTANCE:
			pucArray = tOSD_AI_DISTANCE_TABLE[ucIndex];
			break;
		case _OSD_STR_AI_EYE_CARE_TITLE:
			pucArray = str_EYE_CARE;
			break;
		case _OSD_STR_AI_EYE_CARE:
			pucArray = tOSD_AI_EYE_CARE_TABLE[ucIndex];
			break;
		case _OSD_STR_LOW_POWER_TITLE:
			pucArray = str_LOW_POWER;
			break;
		case _OSD_STR_LOW_POWER:
			pucArray = tOSD_AI_LOW_POWER_TABLE[ucIndex];
			break;
#endif			
		case _STRING_NOTICE_KEY_DESCRIBE:
			pucArray = tOSD_NOTICE_KEY_DESCRIBE_TABLE[ucIndex];
			break;

		// information
		 case _STRING_HFREQPCLK:
			  OsdPropGetShowHFreqPClkStringAddress(ucIndex);
			  pucArray = g_pucModeInfoData;
			  break;
		
		 case _STRING_VFREQUENCY:
			  OsdPropGetShowVFreqStringAddress();
			  pucArray = g_pucModeInfoData;
			  break;

		case _STRING_HFREQUENCY:
			 OsdPropGetShowResolutionHWidthVHeight();
			 pucArray = g_pucModeInfoData;
			 break;

		case _STRING_INFORMATION_ITEMS:
			OsdPropGetShowInformationStringAddress(ucIndex, ucLanguage);
			pucArray = g_pucModeInfoData;
			break;

		case _STRING_INFORMATION_ITEM_SN:
			pucArray = str_SERIAL_NO;
			break;

        case _OSD_STRING_SHOW_SN:

            //GetOSDFlashSN();
            // for(i = 0; i <= _SN_NUMBER_AMOUNT; i++)
            // {
            //     tempdata[i] = g_pucModeInfoData[i];//pData[i];
            // }
            pucArray = g_pucModeInfoData;//tempdata;
            break;
			
		case _STRING_MODEL_NAME:
			pucArray = tOSD_MODEL_NAME;
			break;

		case _STRING_HDR:
			pucArray = tsOsdStrHDR;
			break;

		case _OSD_STR_2ND_MODEL_NAME:
			pucArray = str_PROJECT_NAME;
			break;

        case _STRING_ECO_ITEM:
            pucArray = tsOSD_STRING_ECO_ITEM[ucIndex];
            break;
        case _STRING_SEARCH_ITEM:
            pucArray = tsOSD_STRING_SEARCH_ITEM[ucIndex];
            break;
        case _STRING_DDCCI_ITEM:
            pucArray = tsOSD_STRING_DDCCI_ITEM[ucIndex];
            break;
#if(_AI_EYE_PROTECTION == _ON)
        case _STRING_AI_EYE_PROTECTION_ITEM:
            pucArray = tsOSD_STRING_AI_EYE_PROTECTION_ITEM[ucIndex];
            break;
#endif
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _STRING_AI_LIGHT_ADAPTIVATION_ITEM:
			pucArray = tsOSD_STRING_AI_LIGHT_ADAPTIVATION_ITEM[ucIndex];
			break;
#endif
#if(_AI_LOW_POWER == _ON)
		case _STRING_AI_LOW_POWER_ITEM:
			pucArray = tsOSD_STRING_AI_LOW_POWER_ITEM[ucIndex];
			break;
#endif

        case _STRING_SIX_COLOR_ITEM:
            pucArray = tsOSD_STRING_SIX_COLOR_ITEM[ucIndex];
            break;
        case _STRING_USER_COLOR_ITEM:
            pucArray = tsOSD_STRING_USER_COLOR_ITEM[ucIndex];
            break;		
		case _STRING_DP_VERSION_ITEM:
			pucArray = tsOSD_STRING_DP_VERSION_ITEM[ucIndex];
			break;
#if(_DEF_OSD_GAMING == _ON)
		case _STRING_GAMING_ITEM:
			pucArray = tsOSD_STRING_GAMING_ITEM[ucIndex];
			break;
		case _STRING_TIMER_ITEM:
			if(ucIndex!=0)
				*ucLanguage = _ENGLISH; 
			pucArray = tsOSD_STRING_TIMER_ITEM[ucIndex];
			break;
		case _STRING_CROSSHAIR_ITEM:
			pucArray = tsOSD_STRING_CROSSHAIR_ITEM[ucIndex];
			break;
		case _STRING_FPSCOUNTER_ITEM:
			pucArray = tsOSD_STRING_FPSCOUNTER_ITEM[ucIndex];
			break;
#endif

#if(_OSD_VIEWMODE_USER_GAME_MODE)			
		case _STRING_STANDARD_SUB :	   
			pucArray = tsOSD_STRING_VIEW_MODE_STANDARD_ITEM[ucIndex];;
			break;		
			
		case _STRING_FPS_ITEM :				
			if(ucIndex!=5 || ucIndex!=6)
				*ucLanguage = _ENGLISH;    
			pucArray = tsOSD_STRING_VIEW_MODE_FPS_ITEM[ucIndex];;
			break;	

		case _STRING_FPS_ITEM_SUB :				
			pucArray = tsOSD_STRING_VIEW_MODE_FPS_ITEM_SUB[ucIndex];;
			break;
#endif

		case _STRING_HOT_KEY_VIEWMODE_SELECT :	   //�ȼ�	
			pucArray = str_ViewMode;
			break;
		case _STRING_HOT_KEY_INPUT_SELECT : 	//�ȼ�	
			pucArray = str_InputSelect;
			break;
		case _STRING_HOT_KEY_LANGUAGE_SELECT:
			pucArray = str_LanguageSelect;
			break;
		case _STRING_HOT_KEY_DISTRICT_SELECT:
			pucArray = str_DistrictSelect;
			break;
		case _STRING_HOT_KEY_VIEWMODE : 	//�ȼ�	
			pucArray = tsOSD_HOT_KEY_VIEWMODE[ucIndex];
			break;		
		case _STRING_HOT_KEY_VOLUME :	   //�ȼ�	
			pucArray = tsOSD_HOT_KEY_VOLUME[ucIndex];
			break;
		case _STRING_HOT_KEY_CONBRI :	  //�ȼ�	
			pucArray = tsOSD_HOT_KEY_CONBRI[ucIndex];
			break;
		case _STRING_HOT_KEY_INPUT :	  //�ȼ�	
			*ucLanguage = _ENGLISH; 
			pucArray = tsOSD_HOT_KEY_INPUT[ucIndex];
			break;
		case _STRING_HOT_KEY_LANGUAGE :   //�ȼ�	
			pucArray = tsOSD_HOT_KEY_LANGUAGE[ucIndex];
			break;
		case _STRING_HOT_KEY_DISTRICT:
			pucArray = tsOSD_HOT_KEY_DISTRICT[ucIndex];
			break;
#if(_DEF_NAVIGATION_OSD_ENABLE)
        case _STRING_HOT_KEY_NAVIGATION:
            pucArray = tsOSD_HOT_KEY_NAVIGATION[ucIndex];
            break;
#endif
        case _STRING_SHOW_NUMBER:
            pucArray = g_pucShowNumberAddress;
            break;

        case _STRING_POSTION:
            pucArray = tsOSD_STRING_PSOTION[ucIndex];
            break;
			
		case _STRING_INPUT_PORT_MSG_TITLE:
			pucArray = str_INPUT_PORT_TITLE;
			break;
			
		case _OSD_STR_OSD_LOCK_TITLE:
			pucArray = str_OSD_LOCK_TITLE;
			break;
		
		case _OSD_STR_LOCKED_STATUS:
			pucArray = tOSD_LOCKED_STATUS_TABLE[ucIndex];
			break;
		
		case _OSD_STR_LOCKING_STATUS:
			pucArray = tOSD_LOCKING_STATUS_TABLE[ucIndex];
			break;
			
		case _OSD_STR_LOCKING_HINT:
			pucArray = tOSD_LOCKING_HINT_TABLE[ucIndex];
			break;


		case _OSD_STR_POWER_LOCK_TITLE:
			pucArray = str_POWER_LOCK_TITLE;
            break;

        case _OSD_STR_LOCKED_PWKEY_STATUS:
            pucArray = tOSD_LOCKED_PWKEY_STATUS_TABLE[ucIndex];
            break;

        case _OSD_STR_LOCKING_PWKEY_STATUS:
            pucArray = tOSD_LOCKING_PWKEY_STATUS_TABLE[ucIndex];
            break;

		case _OSD_STR_POWER_LOCKING_HINT:
			pucArray = tOSD_POWER_LOCKING_HINT_TABLE[ucIndex];
			break;

		case _OSD_STR_LOGO_BOOTUP:
			pucArray = str_LOGO_BOOT_UP;
			break;
		
		case _OSD_STR_LOGO_BOOTUP_HINT:
			pucArray = tOSD_BOOT_UP_HINT_TABLE[ucIndex];
			break;

#if(_DEFAULT_OSD_STYLE != _TRG_OSD_STYLE && _DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)
		case _STRING_2ND_NOW_RESOLUTION:
            OsdPropGetShowResolutionStringAddress();
			pucArray = g_pucModeInfoData;
            break;	
#endif

        case _OSD_STR_MEMORY_RECALL:
            pucArray = str_MEMORY_RECALL;
            break;

		case _STRING_ON_OFF:
			pucArray = tsOSD_STRING_ON_OFF_TABLE[ucIndex];
			break;	

        case _STRING_2ND_NOW_RESOLUTION_WARNING:
			pucArray = str_WARNING;
            break;	
        default:
            break;
    }

    return pucArray;
}

void OsdFunDpVersion(void)
{

	if(GET_OSD_DP_VERSION_11_STATUS() == _ON)
	{
		SET_OSD_DP_D0_VERSION(_DP_VER_1_DOT_1);
		SET_OSD_DP_D1_VERSION(_DP_VER_1_DOT_1);
	}
	else
	{
		SET_OSD_DP_D0_VERSION(_DP_VER_1_DOT_3);
		SET_OSD_DP_D1_VERSION(_DP_VER_1_DOT_3);
	}
	// Switch DP D0 Port Edid
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
	//if(SysSourceGetInputPort() == _D0_INPUT_PORT)
	{
		UserCommonInterfaceDPSwitchEdid(_D0_INPUT_PORT); // ����EDID
	}
	ScalerDpVersionSwitch(_D0_INPUT_PORT, UserInterfaceGetDPVersion(_D0_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());
	if(SysSourceGetInputPort() == _D0_INPUT_PORT)
	{
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
	}
#endif

	// Switch DP D1 Port Edid
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
	//if(SysSourceGetInputPort() == _D1_INPUT_PORT)
	{
		UserCommonInterfaceDPSwitchEdid(_D1_INPUT_PORT); // ����EDID
	}				
	ScalerDpVersionSwitch(_D1_INPUT_PORT, UserInterfaceGetDPVersion(_D1_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());
	if(SysSourceGetInputPort() == _D1_INPUT_PORT)
	{
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
	}
#endif

	RTDNVRamSaveOSDData();

}

#if(_HDR10_SUPPORT == _ON)

void OsdFunHDR(void)
{
	
	UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
	OsdDispDisableOsd();
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	UserCommonHDRAdjust(_HDR_FLOW_OSD_MODE_CHANGE); 
	UserCommonHDR10SupportSwitch(); 

	if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
	{
		OsdPropPutStringPage0(ROW(_ROW_RATE_ROW), COL(_COL_SDR_HDR_STATUS), _PFONT_PAGE_HDR, _STRING_HDR, 0, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
#if(_COLOR_FORMAT_CONVERT == _ON)
		if(OsdDisplayGetColorSpaceType()!=_SPACE_AUTO && GET_OSD_HDR_MODE())
		{
			OsdDisplaySetColorSpaceType();
			UserInterfaceColorFormatConvert();
		}
#endif

	}
	else
	{
		OsdFuncClearOsd(ROW(_ROW_RATE_ROW), COL(_COL_SDR_HDR_STATUS), WIDTH(3), HEIGHT(1));
	}
	
	if(!(GET_OSD_HDR_MODE() && GET_OSD_DP_VERSION_11_STATUS()==_ON && SysSourceGetSourceType() == _SOURCE_DP))
		UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
	
	
	if(GET_OSD_HDR_MODE() && GET_OSD_DP_VERSION_11_STATUS()==_ON )
	{
		SET_OSD_DP_VERSION_11_STATUS(_OFF);
		OsdFunDpVersion();
	}
	
	
	RTDNVRamSaveOSDData();

}

#endif
//--------------------------------------------------
// Description  :	
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void SetOsdValue(BYTE ucStateIndex, WORD ucValue)
{  
    bit BLK_flang=0;
    switch(ucStateIndex)
	{
        case _MENU_INPUT:

                // OsdDispMainMenuCursor(GET_OSD_STATE(), GET_OSD_STATE_PREVIOUS(), _INSUBSET);
                // OsdDispMainMenuOptionSetting(_OPTION_INPUT_SOURCE_TYPE, _SELECT, SysSourceGetScanType());

            break;
        case _MENU_VIEWMODE:
            //SET_OSD_COLOR_EFFECT(ucValue);
            break;
#if(_MENU_AUDIO_SUPPORT)
        case _MENU_FUN_VOLUME:
		case _OSD_HOTKEY_VOLUME:
			if(ucValue != GET_OSD_VOLUME())
			{
				SET_OSD_VOLUME(ucValue);
				UserAdjustAudioVolume(GET_OSD_VOLUME());
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
				//RTDNVRamSaveOSDData();
			}

            break;
#endif
		case _MENU_FUN_MUTE:
			if(ucValue != GET_OSD_VOLUME_MUTE())
			{
				SET_OSD_VOLUME_MUTE(ucValue);
				UserAdjustAudioMuteSwitch();
				RTDNVRamSaveOSDData();
				#if(_DEF_MAIN_MENU_MUTE_ICON_SUPPORT == _ON)
				#if(_PROJECT_ID!=_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)
				OsdDisplayVolumeAdjustUpdateIcon();
				#endif
				#endif

			}

            break;
			
        case _MENU_FUN_GAMUT:
			
			if(ucValue != GET_OSD_PCM_STATUS())
			{
				PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
				SET_OSD_PCM_STATUS(ucValue);
				OsdFuncColorPcmAdjust();
				UserAdjustBacklight(GET_OSD_BACKLIGHT());
				UpdateMaskValue();
				OsdDisplay2ndMenu();
#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
				OsdDisplayClearSelectedCursor(2, OSD_SubMenuPer);
				OsdDisplayDrawSelectedCursor(2, OSD_SubMenuCur);
#endif
				RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE()); //��������
				RTDNVRamSaveOSDData();
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BACKLIGHT_POWER_ON);
			}

            break;
			
        case _MENU_FUN_HDR:
			
#if(_HDR10_SUPPORT == _ON)
			if(ucValue != GET_OSD_HDR_MODE())
			{			
		        SET_OSD_HDR_MODE(ucValue);
				OsdFunHDR();
			}
#endif
            break;
			
        case _MENU_FUN_SHARPNESS:
			
            SET_OSD_SHARPNESS(ucValue);
#if(_SHARPNESS_SUPPORT == _ON)
			UserCommonAdjustSharpness(SysSourceGetInputPort());
#endif
            //RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
            // UserCommonColorSharpnessAdjust();
            // RTDNVRamSaveOsdInputPortData();
            break;
			
        case _MENU_FUN_BLUELIGHT:
            SET_OSD_LOW_BLUE(ucValue);
            UserAdjustContrast(GET_OSD_CONTRAST());
            //RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
            break;
			
        case _MENU_FUN_ASPECT:
			if(ucValue != GET_OSD_ASPECT_RATIO_TYPE())
			{
				if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
					Aspect_Dcr_BacklightFlag = _ON;
				
	            SET_OSD_ASPECT_RATIO_TYPE(ucValue);
	            //UserCommonAdjustAspectRatio();
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
	            RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
	    	}
            break;
			
        case _MENU_FUN_OVERSCAN:
			
            //SET_OSD_OVERSCAN_STATUS(ucValue);
#if(_OVERSCAN_SUPPORT == _ON)
			//if(UserAdjustCheckOverScanOOR()!=_TRUE && UserAdjustCheckDOSModeTiming()!=_TRUE&&(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE))
			if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE && (ucValue != UserAdjustGetOverScanStatus()))
			{
				UserAdjustOverScan(ucValue);
			}

#endif
			break;

        case _MENU_FUN_FREESYNC:

			if(ucValue != GET_OSD_FREE_SYNC_STATUS())
			{
				
				SET_OSD_FREE_SYNC_STATUS(ucValue);

				#if 0//_GSYNC_TEST
					SET_OSD_PRE_GAME_FPS(ucValue);
				#endif
				
				PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
				
#if(_FREESYNC_SUPPORT == _ON)
				UserCommonInterfaceFreeSyncSupportSwitch();
#endif
	
#if(_MPRT_SUPPORT == _ON)
				if(GET_OSD_FREE_SYNC_STATUS() && GET_OSD_MPRT())
				{
					SET_OSD_MPRT(_OFF);
					UserAdjustMPRTFuntion(GET_OSD_MPRT());
				}
#endif
	
				if(GET_OSD_FREE_SYNC_STATUS())
				{
					SET_OSD_LATENCY(_ON);
					//SET_OSD_ASPECT_RATIO_TYPE(_OSD_ASPECT_RATIO_FULL);
					SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_DEFAULT); // �ָ���16 : 9
				}
				
				RTDNVRamSaveOSDData();
				RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
				//ScalerTimerReactiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BACKLIGHT_POWER_ON);
				//ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
				//ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);

			}
            break;
         
        case _MENU_FUN_OSD_TIMEOUT:
            SET_OSD_TIME_OUT(ucValue);
            RTDNVRamSaveOSDData();
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
            break;
			
        case _MENU_FUN_AUTO_POWEROFF:
            SET_AUTO_POWEROFF_STATUS(ucValue);
			
#if _OSD_Sleep_PowenOff_Fun
			if(!GET_AUTO_POWEROFF_STATUS())
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
#endif
            RTDNVRamSaveOSDData();
            break;
			
        case _MENU_FUN_DDCCI:
            SET_OSD_DDCCI_STATUS(ucValue);
			ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());
			RTDNVRamSaveOSDData();
            break;
#if(_AI_EYE_PROTECTION == _ON)
        case _MENU_FUN_AI_EYE_PROTECTION:
            SET_OSD_AI_EYE_PROTECTION_STATUS(ucValue);
			RTDNVRamSaveOSDData();
            if(ucValue && (!ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT)))
            {
                ScalerTimerActiveTimerEvent(500, _USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
            }
            break;
#endif		
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:
			SET_OSD_AI_LIGHT_ADAPTIVATION_STATUS(ucValue);
			RTDNVRamSaveOSDData();
            if(ucValue && (!ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT)))
            {
                ScalerTimerActiveTimerEvent(500, _USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
            }
			break;
#endif
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:
			SET_OSD_AI_LOW_POWER_STATUS(ucValue);
			RTDNVRamSaveOSDData();
            if(ucValue && (!ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT)))
            {
                ScalerTimerActiveTimerEvent(500, _USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
            }
			break;
#endif

        case _MENU_FUN_CONTRAST:
		case _OSD_HOTKEY_CONTRAST:
            SET_OSD_CONTRAST(ucValue);
            UserAdjustContrast(GET_OSD_CONTRAST());
#if(_HDR10_SUPPORT == _ON)			
			if(UserCommonHDRGetHDR10Status() == _HDR10_OFF) 
				HDR_OFF_FLAG=_ON;
#endif			
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
            //RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
            break;
			
        case _MENU_FUN_BRIGHTNESS:
            SET_OSD_BRIGHTNESS(ucValue);
            UserAdjustBrightness(GET_OSD_BRIGHTNESS());
            // UserCommonColorBrightnessAdjust();
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
            //RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
            break;

		case _MENU_FUN_BACKLIGHT:
		case _OSD_HOTKEY_BACKLIGHT:
            SET_OSD_BACKLIGHT(ucValue);
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
            //RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
            break;
			
		case _MENU_FUN_ECO:
			
			SET_OSD_ECO_STATUS(ucValue);
			if(GET_OSD_ECO_STATUS() == _ECO_STANDARD)
			{
				//SET_OSD_BACKLIGHT(100);
			}
			else if(GET_OSD_ECO_STATUS() == _ECO_OPTIMIZE)
			{
				//SET_OSD_BACKLIGHT(75);
			}
			else
			{
				//SET_OSD_BACKLIGHT(50);
			}
#if 1//(_5KEY_MENU_STYLE)			
			if(GET_OSD_DCR_STATUS()==0)                     //����DCR�󣬿�ECO���ȱ仯ͻأ
#endif				
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
			RTDNVRamSaveOSDData();
			break;

			
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_VGA_HPOSITON:
			
			SET_VGA_MODE_ADJUST_H_POSITION(ucValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
	        UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());        
            break;
			
        case _MENU_FUN_VGA_VPOSITON:
			
			SET_VGA_MODE_ADJUST_V_POSITION(ucValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
	        UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());    
            break;

        case _MENU_FUN_HORIZONTAL_SIZE:
			SET_VGA_MODE_ADJUST_CLOCK(ucValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());			
            break;
			
        case _MENU_FUN_FINE_TUNE:
			SET_VGA_MODE_ADJUST_PHASE(ucValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG);
			UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());			
            break;
#endif
			
        case _MENU_FUN_TEMP:
            //SET_COLOR_TEMP_TYPE(ucValue);
            //RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            //UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustColorTemp();

            RTDNVRamSaveOSDData();
            break;
        case _MENU_FUN_HUE_ADJUST:
			if(ucValue != GET_OSD_SIX_COLOR_HUE())
			{
				SET_OSD_SIX_COLOR_HUE(ucValue);
						
		        switch (GET_OSD_SIX_COLOR())
			    {		
			        case _SIXCOLOR_Y:
			            g_stVscSceneModeData.ucSixColorHueY = ucValue;
			            break;

			        case _SIXCOLOR_G:
			            g_stVscSceneModeData.ucSixColorHueG = ucValue;
			            break;

			        case _SIXCOLOR_C:
			            g_stVscSceneModeData.ucSixColorHueC = ucValue;
			            break;

			        case _SIXCOLOR_B:
			            g_stVscSceneModeData.ucSixColorHueB = ucValue;
			            break;

			        case _SIXCOLOR_M:
			            g_stVscSceneModeData.ucSixColorHueM = ucValue;
			            break;

			        case _SIXCOLOR_R:
			        default:
			            //g_stSixColorData.ucSixColorHueR = ucValue;
			            g_stVscSceneModeData.ucSixColorHueR = ucValue;
			            break;			

		        }
#if(_SIX_COLOR_SUPPORT == _ON)
				ScalerColorSixColorInitial();
				OsdFuncSixColorAdjust();
#endif
			}
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
			//ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SIX_COLOR_DATA);
			//RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			//RTDNVRamSaveSixColorData();

            break;
			
        case _MENU_FUN_SATURATION_ADJUST:
			if(ucValue != GET_OSD_SIX_COLOR_SATURATION())
			{

				SET_OSD_SIX_COLOR_SATURATION(ucValue);
				
				switch (GET_OSD_SIX_COLOR())
				{
					case _SIXCOLOR_Y:
						g_stVscSceneModeData.ucSixColorSaturationY = ucValue;
						break;
					
					case _SIXCOLOR_G:
						g_stVscSceneModeData.ucSixColorSaturationG = ucValue;
						break;
					
					case _SIXCOLOR_C:
						g_stVscSceneModeData.ucSixColorSaturationC = ucValue;
						break;
					
					case _SIXCOLOR_B:
						g_stVscSceneModeData.ucSixColorSaturationB = ucValue;
						break;
					
					case _SIXCOLOR_M:
						g_stVscSceneModeData.ucSixColorSaturationM = ucValue;
						break;
					
					case _SIXCOLOR_R:
					default:
						g_stVscSceneModeData.ucSixColorSaturationR = ucValue;
						break;
				
				}
				//SET_OSD_SIX_COLOR_SATURATION(GET_OSD_SIX_COLOR());
        		//OsdDisplaySixColorGetOneColor(GET_OSD_SIX_COLOR());
#if(_SIX_COLOR_SUPPORT == _ON)
				ScalerColorSixColorInitial();
				OsdFuncSixColorAdjust();
#endif
			}
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
			//ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SIX_COLOR_DATA);
			//RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			//RTDNVRamSaveSixColorData();

            break;
			
        case _MENU_FUN_USER_COLOR_ADJUST:
            switch(g_us4thItemNum)
            {
                case 0:
                    SET_COLOR_TEMP_TYPE_USER_R(ucValue);
                    break;
                case 1:
                    SET_COLOR_TEMP_TYPE_USER_G(ucValue);
                    break;
                case 2:
                    SET_COLOR_TEMP_TYPE_USER_B(ucValue);
                    break;
            }
			ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_COLOR_SETTING_DATA);
            //RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
            UserAdjustContrast(GET_OSD_CONTRAST());
            break;
			
        case _MENU_FUN_ADV_DCR:
			
            SET_OSD_DCR_STATUS(ucValue);
			
			if(g_usBackupValue != GET_OSD_DCR_STATUS())
			{
				#if(_ULTRA_VIVID_SUPPORT == _ON)
				UserAdjustUltraVivid();
				#endif
				//UserAdjustDCR();
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
				//RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());

			}
			//else if(GET_OSD_DCR_STATUS() == _DCR_Level_0)
			if(GET_OSD_DCR_STATUS() == _DCR_Level_0)
			{
#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT)			
				CDcrReset();
				UserAdjustBacklight(GET_OSD_BACKLIGHT());
#endif
#endif
			}

            break;
			
        case _MENU_FUN_BLK_STABLE:

			if(ucValue==0 && GET_OSD_BLACKSTABLE()==0 || ucValue==10 && GET_OSD_BLACKSTABLE()==10)
			{
            	BLK_flang=1;
			}
			else
				BLK_flang=0;
			
			if(BLK_flang==0)
			{
	            SET_OSD_BLACKSTABLE(ucValue);
				UserAdjustColorEffectMode();
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
				//RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			}


            break;
			
        case _MENU_FUN_OSD_BACKGROUND:
			
            SET_OSD_TRANSPARENCY_STATUS(ucValue);
			OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
            RTDNVRamSaveOSDData();
            break;
		
		case _MENU_FUN_OSD_PIVOT:
			
			if(ucValue != GET_OSD_ROTATE_STATUS())
			{
				SET_OSD_ROTATE_STATUS(ucValue);
				
				// redraw menu
				OsdDispDisableOsd();
				OsdDispMainMenu();
				OsdDisplayKeyIndex(_LAYER3);
				SET_OSD_STATE(_MENU_FUN_OSD_PIVOT);
				OSD_SubMenuCur = _PIVOT_INDEX;
				OsdDisplaySubMenuItem();            
				#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                OsdDisplayDrawSelectedCursor(2, OSD_SubMenuCur);
                OsdDisplayDrawSelectedCursor(3, ucStateIndex);
            	#else
				OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_2ND_CURSOR), XSTART(_MAIN_WIN_2ND_CURSOR_X_START), YSTART(_MAIN_WIN_2ND_CURSOR_Y_START(OSD_SubMenuCur)), XEND(_MAIN_WIN_2ND_CURSOR_X_END), YEND(_MAIN_WIN_2ND_CURSOR_Y_END(OSD_SubMenuCur)), _CP_BLUE, _CP_WHITE, _CP_BG);
				OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR), XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);
				#endif
				RTDNVRamSaveOSDData();
				
			}
			break;


		case _MENU_FUN_DP_VERSION:
			
			if(ucValue != GET_OSD_DP_VERSION_11_STATUS())
			{
				SET_OSD_DP_VERSION_11_STATUS(ucValue);

				OsdFunDpVersion();

			}
			break;


		case _MENU_FUN_RESPONSE_TIME:
			
			if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
			{
#if(_OD_SUPPORT == _ON)
				UserAdjustOD();
#endif	
			}
			break;

			
        case _MENU_FUN_SLEEP:
			
            SET_AUTO_SLEEP_STATUS(ucValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SLEEP_TIME_ADJ_MSG);

			//OsdDispOsdMessage(_OSD_DISP_SLEEP_MSG_ADJ);

			if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
			{
#if _OSD_PowerSaving_Fun
				if(GET_AUTO_SLEEP_STATUS() == _SleepPowerSaving_30)
				{
					g_usPowerSavingCount = 30*_OSD_TIME_AUTO_DOWN;
					ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUTO_POWER_Saving); 
			
				}
				else if(GET_AUTO_SLEEP_STATUS() == _SleepPowerSaving_45)
				{
					g_usPowerSavingCount = 45*_OSD_TIME_AUTO_DOWN;
					ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUTO_POWER_Saving); 
			
				}
				else if(GET_AUTO_SLEEP_STATUS() == _SleepPowerSaving_60)
				{
					g_usPowerSavingCount = 60*_OSD_TIME_AUTO_DOWN;
					ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUTO_POWER_Saving); 
			
				}
				else if(GET_AUTO_SLEEP_STATUS() == _SleepPowerSaving_120)
				{
					g_usPowerSavingCount = 120*_OSD_TIME_AUTO_DOWN;
					ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUTO_POWER_Saving); 
			
				}
				else if(GET_AUTO_SLEEP_STATUS() == _SleepPowerSaving_OFF)
				{
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_Saving); 
			
				}
#endif
			}
			RTDNVRamSaveOSDData();
            break;
        case _MENU_FUN_NOTICE:
            SET_OSD_RESOLUTION_STATUS(ucValue);
            RTDNVRamSaveOSDData();
            break;
        case _MENU_FUN_POWER_INDICATOR:
			
            SET_POWER_INDICATOR(ucValue);
		    if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) )
            {
				if(GET_POWER_INDICATOR() == _ON)
				{
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_INDICATOR);
					UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
				}
				else
				{
					ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_INDICATOR);
					UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
				}

			}
            RTDNVRamSaveOSDData();
            break;
        case _MENU_FUN_SEARCH:
			//DebugMessageOsd("1.g_usAdjustValue",g_usAdjustValue);
		    if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				OsdFunInputAuto(g_usAdjustValue);
            break;    
        case _MENU_FUN_SPACE:
			
#if(_COLOR_FORMAT_CONVERT == _ON)
			UserAdjustColorSpace();
#endif
            break;   
        case _MENU_FUN_RANGE:
#if(_COLOR_FORMAT_CONVERT == _ON)
			UserAdjustColorRange();
#endif
            break;   

#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_TIMER:
			if(ucValue != GET_OSD_PRE_GAME_TIME())
			{
				SET_OSD_PRE_GAME_TIME(ucValue);
				OsdDispDisableOsd(); 
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
				if(ucValue!= 0)
				{
					SET_OSD_PRE_GAME_FPS(0);
					SET_OSD_PRE_GAME_TIME(ucValue);
					SET_OSD_PRE_GAME_CROSS(0);
					TIME_COUNT = 15*60*GET_OSD_PRE_GAME_TIME();

					if(GET_OSD_PRE_GAME_TIME() == 5)
					{
						TIME_COUNT= 60*90;
					}
					
					ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_GAME_HOTKEY);
				}
				else
				{
					SET_OSD_PRE_GAME_FPS(0);
					SET_OSD_PRE_GAME_TIME(0);
					SET_OSD_PRE_GAME_CROSS(0);
				}
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
			}
			break;
			
		case _MENU_FUN_CROSSHAIR:
			if(ucValue != GET_OSD_PRE_GAME_CROSS())
			{
				SET_OSD_PRE_GAME_CROSS(ucValue);
				OsdDispDisableOsd(); 
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
				if(ucValue!= 0)
				{
					SET_OSD_PRE_GAME_FPS(0);
					SET_OSD_PRE_GAME_TIME(0);
					SET_OSD_PRE_GAME_CROSS(ucValue);
					ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_GAME_HOTKEY);
				}
				else
				{
				
					SET_OSD_PRE_GAME_FPS(0);
					SET_OSD_PRE_GAME_TIME(0);
					SET_OSD_PRE_GAME_CROSS(0);
				}
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
			}
			break;

		case _MENU_FUN_FPS_COUNTER:
			if(ucValue != GET_OSD_PRE_GAME_FPS())
			{
				SET_OSD_PRE_GAME_FPS(ucValue);
				OsdDispDisableOsd(); 
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
				if(ucValue== 0)
				{
					SET_OSD_PRE_GAME_FPS(0);
					SET_OSD_PRE_GAME_TIME(0);
					SET_OSD_PRE_GAME_CROSS(0);
					
				}
				else
				{
					SET_OSD_PRE_GAME_FPS(1);
					SET_OSD_PRE_GAME_TIME(0);
					SET_OSD_PRE_GAME_CROSS(0);
				
					ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_GAME_HOTKEY);
				}
				ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
			}
			break;
#endif


        default:
            break;
    }
}


//--------------------------------------------------
// Description	:
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdDisplayJudgeSourceType(void)
{
	switch(SysSourceGetInputPort())
	{

	#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            return _OSD_INPUT_A0;
            break;
	#endif

	#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
             return _OSD_INPUT_D0;
            break;
	#endif

	#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
            return _OSD_INPUT_D1;
            break;
	#endif

	#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
            return _OSD_INPUT_D2;
            break;
	#endif

	#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
            return _OSD_INPUT_D3;
            break;
	#endif


	#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
            return _OSD_INPUT_D4;
            break;
	#endif

		default:
			return 0;
			
	}
}


//--------------------------------------------------
// Description  :	
// Input Value  : 
// Output Value : 
//--------------------------------------------------
WORD GetOsdValue(BYTE ucStateIndex)
{
    WORD ucValue = 0;
	switch(ucStateIndex)
	{
        case _MENU_INPUT:
			
			ucValue = OsdDisplayJudgeSourceType();
        break;
			
        case _MENU_VIEWMODE:
		case _OSD_HOTKEY_VIEWMODE:
			
			if(GET_OSD_VIEWMODE_TYPE() == _VM_GAME)
				ucValue = GET_OSD_GAME_MODE()+1; // FPS��RTS��MOBA
			else if(GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD)
				ucValue = _VM_STANDARD;
			else
				ucValue = GET_OSD_GAME_MODE()+GET_OSD_VIEWMODE_TYPE()-(_GAMEMODE_AMOUNT-2); // MOVIE��WEB��TEXT��MAC��MONO
			
			DebugMessageOsd("1.VIEWMODE_ucValue",ucValue);
            break;
#if(_MENU_AUDIO_SUPPORT)
		case _MENU_FUN_VOLUME:
		case _OSD_HOTKEY_VOLUME:
            ucValue = GET_OSD_VOLUME();
            break;
#endif
		case _MENU_FUN_MUTE:
            ucValue = GET_OSD_VOLUME_MUTE();
            break;
        case _MENU_FUN_GAMUT:
            ucValue = GET_OSD_PCM_STATUS();
            break;
        case _MENU_FUN_HDR:
#if(_HDR10_SUPPORT == _ON)
             ucValue = GET_OSD_HDR_MODE();
#endif
            break;
        case _MENU_FUN_SHARPNESS:
            ucValue = GET_OSD_SHARPNESS();
            break;
        case _MENU_FUN_BLUELIGHT:
            ucValue = GET_OSD_LOW_BLUE();
            break;
        case _MENU_FUN_ASPECT:
            ucValue = GET_OSD_ASPECT_RATIO_TYPE();
            break;
        case _MENU_FUN_OVERSCAN:
#if(_OVERSCAN_SUPPORT == _ON)
            ucValue = UserAdjustGetOverScanStatus();
#endif
            break;
        case _MENU_FUN_FREESYNC:
            ucValue = GET_OSD_FREE_SYNC_STATUS();
            break;
        case _MENU_FUN_LANGUAGE:
            ucValue = GET_OSD_LANGUAGE();
            break;
			
		case _MENU_FUN_DP_VERSION:
			ucValue = GET_OSD_DP_VERSION_11_STATUS();
			break;
#if(_MPRT_SUPPORT == _ON)
		case _MENU_FUN_MPRT:
			ucValue = GET_OSD_MPRT();		
			break;	
#endif
		case _MENU_FUN_SIX_AXIS:
			if(OSD_ITEM_MASK_GET(_MENU_FUN_HUE))
				ucValue = 1;
			else
            	ucValue = 0;
			break;
			
        case _MENU_FUN_OSD_TIMEOUT:
            ucValue = GET_OSD_TIME_OUT();//OsdDisplayTimeOut(GET_OSD_TIME_OUT());
            break;
        case _MENU_FUN_DDCCI:
            ucValue = GET_OSD_DDCCI_STATUS();
            break;
#if(_AI_EYE_PROTECTION == _ON)
        case _MENU_FUN_AI_EYE_PROTECTION:
            ucValue = GET_OSD_AI_EYE_PROTECTION_STATUS();
            break;
#endif	
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:
			ucValue = GET_OSD_AI_LIGHT_ADAPTIVATION_STATUS();
			break;
#endif	
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:
			ucValue = GET_OSD_AI_LOW_POWER_STATUS();
			break;
#endif	


        case _MENU_FUN_CONTRAST:
		case _OSD_HOTKEY_CONTRAST:
            ucValue = GET_OSD_CONTRAST();
            break;
			
        case _MENU_FUN_BRIGHTNESS:
            ucValue = GET_OSD_BRIGHTNESS();
            break;
			
	    case _MENU_FUN_BACKLIGHT:
		case _OSD_HOTKEY_BACKLIGHT:
            ucValue = GET_OSD_BACKLIGHT();
            break;
			
#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_GAMING:
			ucValue = 0;
			break;

		case _MENU_FUN_TIMER:
			ucValue = GET_OSD_PRE_GAME_TIME();
			break;

		case _MENU_FUN_CROSSHAIR:
			ucValue = GET_OSD_PRE_GAME_CROSS();
			break;

		case _MENU_FUN_FPS_COUNTER:
			ucValue = GET_OSD_PRE_GAME_FPS();
			break;
#endif

			
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_VGA_HPOSITON:
            ucValue = GET_VGA_MODE_ADJUST_H_POSITION();
            break;
			
        case _MENU_FUN_VGA_VPOSITON:
            ucValue = GET_VGA_MODE_ADJUST_V_POSITION();
            break;
			
        case _MENU_FUN_HORIZONTAL_SIZE:
			 ucValue = GET_VGA_MODE_ADJUST_CLOCK();
            break;
			
        case _MENU_FUN_FINE_TUNE:
			 ucValue = GET_VGA_MODE_ADJUST_PHASE();
            break;
#endif
			
        case _MENU_FUN_TEMP:
            ucValue = GET_COLOR_TEMP_TYPE();
            break;
        case _MENU_FUN_HUE_ADJUST:
			if(g_us4thItemNum == 0)
	            SET_OSD_SIX_COLOR(_SIXCOLOR_R);
			else if(g_us4thItemNum == 1)
				SET_OSD_SIX_COLOR(_SIXCOLOR_G);
			else if(g_us4thItemNum == 2)
				SET_OSD_SIX_COLOR(_SIXCOLOR_B);
			else if(g_us4thItemNum == 3)
				SET_OSD_SIX_COLOR(_SIXCOLOR_C);
			else if(g_us4thItemNum == 4)
				SET_OSD_SIX_COLOR(_SIXCOLOR_M);
			else if(g_us4thItemNum == 5)
				SET_OSD_SIX_COLOR(_SIXCOLOR_Y);
            OsdDisplaySixColorGetOneColor(GET_OSD_SIX_COLOR());
            ucValue = GET_OSD_SIX_COLOR_HUE();
            break;
        case _MENU_FUN_SATURATION_ADJUST:
			if(g_us4thItemNum == 0)
	            SET_OSD_SIX_COLOR(_SIXCOLOR_R);
			else if(g_us4thItemNum == 1)
				SET_OSD_SIX_COLOR(_SIXCOLOR_G);
			else if(g_us4thItemNum == 2)
				SET_OSD_SIX_COLOR(_SIXCOLOR_B);
			else if(g_us4thItemNum == 3)
				SET_OSD_SIX_COLOR(_SIXCOLOR_C);
			else if(g_us4thItemNum == 4)
				SET_OSD_SIX_COLOR(_SIXCOLOR_M);
			else if(g_us4thItemNum == 5)
				SET_OSD_SIX_COLOR(_SIXCOLOR_Y);
            OsdDisplaySixColorGetOneColor(GET_OSD_SIX_COLOR());
            ucValue = GET_OSD_SIX_COLOR_SATURATION();
            break;
        case _MENU_FUN_USER_COLOR_ADJUST:
            switch(g_us4thItemNum)
            {
                case 0:
                    ucValue = GET_COLOR_TEMP_TYPE_USER_R();
                    break;
                case 1:
                    ucValue = GET_COLOR_TEMP_TYPE_USER_G();
                    break;
                case 2:
                    ucValue = GET_COLOR_TEMP_TYPE_USER_B();
                    break;
            }
            break;
         case _MENU_FUN_ECO:
            ucValue = GET_OSD_ECO_STATUS();
            break;
        case _MENU_FUN_ADV_DCR:
            ucValue = GET_OSD_DCR_STATUS();
            break;
        case _MENU_FUN_BLK_STABLE:
            ucValue = GET_OSD_BLACKSTABLE();
            break;
		case _MENU_FUN_RESPONSE_TIME: 
			ucValue = GET_OSD_OD_STATUS();
            break;
		case _MENU_FUN_OSD_BACKGROUND: 
			ucValue = GET_OSD_TRANSPARENCY_STATUS();
            break;
		case _MENU_FUN_SLEEP: 
			ucValue = GET_AUTO_SLEEP_STATUS();
            break;		
		case _MENU_FUN_OSD_PIVOT: 
            ucValue = GET_OSD_ROTATE_STATUS();
            break;
			
		case _MENU_FUN_VIEWMODE_STANDARD: 
		case _MENU_FUN_VIEWMODE_FPS: 
		case _MENU_FUN_VIEWMODE_RTS: 
		case _MENU_FUN_VIEWMODE_MOBA: 
		case _MENU_FUN_VIEWMODE_MOVIE: 
		case _MENU_FUN_VIEWMODE_WEB: 
		case _MENU_FUN_VIEWMODE_TEXT: 
		case _MENU_FUN_VIEWMODE_MAC: 
		case _MENU_FUN_VIEWMODE_MONO: 
			
			ucValue = GET_OSD_VIEWMODE_TYPE();
			break;

		case _MENU_FUN_NOTICE: 
			ucValue = GET_OSD_RESOLUTION_STATUS();
            break;
        case _MENU_FUN_POWER_INDICATOR:
            ucValue = GET_POWER_INDICATOR();
            break;        
		case _MENU_FUN_AUTO_POWEROFF:
            ucValue = GET_AUTO_POWEROFF_STATUS();
            break;
			
        case _MENU_FUN_SEARCH:
			ucValue = (SysSourceGetScanType()==(_SOURCE_SWITCH_AUTO_IN_GROUP));	
            break;  
        case _MENU_FUN_SPACE:
			
#if(_COLOR_FORMAT_CONVERT == _ON)
            ucValue = OsdDisplayGetColorSpaceType();
#endif
            break;   
        case _MENU_FUN_RANGE:
			
#if(_COLOR_FORMAT_CONVERT == _ON)
            ucValue = OsdDisplayGetColorRangeType();
#endif
            break;   

        default:
            break;
	}

    return ucValue;
}



//--------------------------------------------------
// Description  :	
// Input Value  : 
// Output Value : 
//--------------------------------------------------
BYTE GetOsdShowType(BYTE ucStateIndex)
{
	switch(ucStateIndex)
	{

		case _MENU_FUN_VOLUME:
		case _MENU_FUN_SHARPNESS:
		case _MENU_FUN_BLUELIGHT:
		case _MENU_FUN_BLK_STABLE:
		case _MENU_FUN_ADV_DCR:
		case _MENU_FUN_CONTRAST:
		case _MENU_FUN_BRIGHTNESS:
		case _MENU_FUN_BACKLIGHT:
		case _MENU_FUN_HUE_ADJUST:
		case _MENU_FUN_SATURATION_ADJUST:
		case _MENU_FUN_USER_COLOR_ADJUST:
        case _MENU_FUN_OSD_TIMEOUT:
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_HORIZONTAL_SIZE:
        case _MENU_FUN_FINE_TUNE:
        case _MENU_FUN_VGA_HPOSITON: 
	    case _MENU_FUN_VGA_VPOSITON:
#endif
            return _TYPE_SLIDER;
            break;

		case _MENU_FUN_MUTE:
		case _MENU_FUN_TEMP:
		case _MENU_FUN_GAMUT:
		case _MENU_FUN_SPACE:
		case _MENU_FUN_RANGE:
		case _MENU_FUN_HDR:
		case _MENU_FUN_ASPECT:
		case _MENU_FUN_OVERSCAN:
        case _MENU_FUN_RESPONSE_TIME:
        case _MENU_FUN_LANGUAGE:
        case _MENU_FUN_FREESYNC:
#if(_MPRT_SUPPORT == _ON)
        case _MENU_FUN_MPRT:
#endif
        case _MENU_FUN_NOTICE:
#if(_DEF_OSD_DOUBLE)
        case _MENU_FUN_OSD_SIZE:
#endif
        case _MENU_FUN_OSD_BACKGROUND:
        case _MENU_FUN_OSD_PIVOT:
        case _MENU_FUN_POWER_INDICATOR:
        case _MENU_FUN_AUTO_POWEROFF:
        case _MENU_FUN_SLEEP:
        case _MENU_FUN_ECO:
        case _MENU_FUN_DP_VERSION:
        case _MENU_FUN_SEARCH:
        case _MENU_FUN_DDCCI:			
#if(_AI_EYE_PROTECTION == _ON)
		case _MENU_FUN_AI_EYE_PROTECTION:			
#endif
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:			
#endif
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:			
#endif

#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_TIMER:
		case _MENU_FUN_CROSSHAIR:
		case _MENU_FUN_FPS_COUNTER:
#endif

#if(_OSD_VIEWMODE_USER_GAME_MODE)
		case _MENU_FUN_VIEWMODE_STANDARD:
		case _MENU_FUN_VIEWMODE_FPS:		// liuxh FPS
#endif

            return _TYPE_ITEM;
            break;

		case _MENU_FUN_CONTRAST_BRIGHTNESS:
		case _MENU_FUN_SIX_AXIS:
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_VGA_POSTION:
#endif
#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_GAMING:
#endif
            return _TYPE_SUBMENU;
            break;

        case _MENU_FUN_INPUT_0:
		case _MENU_FUN_INPUT_1:
		case _MENU_FUN_INPUT_2:
		case _MENU_FUN_INPUT_3:
#if(!_OSD_VIEWMODE_USER_GAME_MODE)
		case _MENU_FUN_VIEWMODE_STANDARD:
		case _MENU_FUN_VIEWMODE_FPS:		// liuxh FPS
#endif
		case _MENU_FUN_VIEWMODE_RTS:
		case _MENU_FUN_VIEWMODE_MOBA:
		case _MENU_FUN_VIEWMODE_MOVIE:
		case _MENU_FUN_VIEWMODE_WEB:
		case _MENU_FUN_VIEWMODE_TEXT:
		case _MENU_FUN_VIEWMODE_MAC:
		case _MENU_FUN_VIEWMODE_MONO:

        case _MENU_FUN_INFORMATION:
        case _MENU_FUN_RECALL:
#if(_VGA_SUPPORT == _ON)
        case _MENU_FUN_AUTO_IMAGE_ADJ:
#endif
            return _TYPE_NONE;
            break;

		default:
            return _TYPE_NONE;
			break;


	}
}
BYTE GetOsdCurItem(BYTE ucStateIndex)
{
    BYTE ucCurItem = 0;
    switch(ucStateIndex)
    {
        case _MENU_FUN_MUTE:
		case _MENU_FUN_HDR:
        case _MENU_FUN_OVERSCAN:
        case _MENU_FUN_FREESYNC:
#if(_MPRT_SUPPORT == _ON)
		case _MENU_FUN_MPRT:
#endif
        case _MENU_FUN_NOTICE:
        case _MENU_FUN_POWER_INDICATOR:
        case _MENU_FUN_AUTO_POWEROFF:
        case _MENU_FUN_SEARCH:
        case _MENU_FUN_DDCCI:
#if(_AI_EYE_PROTECTION == _ON)
		case _MENU_FUN_AI_EYE_PROTECTION:			
#endif	
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:			
#endif	
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:			
#endif	

		case _MENU_FUN_DP_VERSION:
#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_FPS_COUNTER:
#endif
            ucCurItem = 1 - g_usAdjustValue;
            break;

#if(_DEF_PIVOT_OPTION_ON_OFF)
		case _MENU_FUN_OSD_PIVOT:
			ucCurItem = g_usAdjustValue == _OSD_ROTATE_DEGREE_0 ? 1 : 0;
			break;
#endif

#if(_DEF_OSD_GAMING == _ON)
		case _MENU_FUN_GAMING:
			ucCurItem = g_us3rdItemNum;
			break;
#endif

        default:
            ucCurItem = g_usAdjustValue;
            break;
    }
	DebugMessageOsd("1.ucCurItem",ucCurItem);
    return ucCurItem;
}

#if(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

bit GetOsdGameModeState(BYTE ucStateIndex)
{

	BYTE ucCurItem = 0;
	switch(ucStateIndex)
	{
		case _MENU_FUN_BLK_STABLE:
		case _MENU_FUN_ADV_DCR:
		case _MENU_FUN_BLUELIGHT:
		case _MENU_FUN_RESPONSE_TIME:

			ucCurItem = _ON;
			break;

		default:
			ucCurItem = _OFF;
			break;
	}

	return ucCurItem;

}

#endif



#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)

