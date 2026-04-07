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
// ID Code      : RTD2014OsdWindow.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDWINDOW__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
void OsdWindowDrawingHighlight(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor);
void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow1, BYTE ucCol1, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor);
void OsdWindowSliderDisable(void);

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor)
{
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    WORD xdata usTemp = 0;
    WORD xdata usTemp1 = 0;
    WORD xdata usTemp2 = 0;
    usTemp  = usXEnd - usXStart;
    usTemp1 = usYEnd - usYStart;
    usTemp2 = usXStart;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usXEnd = (g_ucOsdWidth * 18 - usYStart);
        usXStart = usXEnd - usTemp1;
        usYStart = usTemp2;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usXStart = usYStart;
        usYStart = (g_ucOsdHeight * 12) - usXEnd;
        usXEnd = usXStart + usTemp1;
        usYEnd = usYStart + usTemp;
    }
    else
    {
    }

#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    WORD xdata usTemp = 0;
    WORD xdata usTemp1 = 0;
    WORD xdata usTemp2 = 0;
	
    usTemp  = usXEnd - usXStart;
    usTemp1 = usYEnd - usYStart;
    usTemp2 = usXStart;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usXEnd = (g_ucOsdHeight * 18 - usYStart);
        usXStart = usXEnd - usTemp1;
        usYStart = usTemp2;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usXStart = usYStart;
        usYStart = (g_ucOsdWidth * 12) - usXEnd ;
        usXEnd = usXStart + usTemp1;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
    {
        usXStart = (g_ucOsdWidth * 12) - usTemp - usXStart;
        usXEnd = usXStart + usTemp;
        usYStart = (g_ucOsdHeight * 18) - usTemp1 - usYStart;
        usYEnd = usYStart + usTemp1;
    }
    else
    {
    }

#else // #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)


#endif

#if(_OSD_SHOW_KEY_BORDER)

	#if(_DEF_JS_KEY_ICON_5_KEY_MODE)
	if((ucWindow==_OSD_WINDOW_4_1 || ucWindow==_OSD_WINDOW_4_2 ) && g_usOsdKeyDirectionType == _LAYER_Timing_Tips)	

	#else
	if(ucWindow==_OSD_WINDOW_5_1 || ucWindow==_OSD_WINDOW_5_2 || ucWindow==_OSD_WINDOW_5_3 \
		|| ucWindow==_OSD_WINDOW_5_4 || ucWindow==_OSD_WINDOW_5_5)	

	#endif
	{
		SET_OSD_WINDOW_REFERENCE_DELAY(1);	// Map B
		SET_OSD_WINDOW_BUTTON_TYPE(_OSD_WINDOW_BUTTON_TYPE_BORDER);
		SET_OSD_WINDOW_COLOR_BORDER(_CP_WHITE);
		SET_OSD_WINDOW_SHADOW_BORDER_PIXEL_WIDTH(0);
		SET_OSD_WINDOW_SHADOW_BORDER_PIXEL_HEIGHT(0);
		SET_OSD_WINDOW_BUTTON_ENABLE(_ENABLE);
	}
	
#endif






    SET_OSD_WINDOW_NUMBER(ucWindow);
    SET_OSD_WINDOW_COLOR(ucColor);

    SET_OSD_WINDOW_BLEND_ENABLE(_ENABLE);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerOsdDrawWindow(usXStart, usYStart, usXEnd, usYEnd);
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawingHighlight(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    OsdWindowDrawing(ucWindow, usXStart, usYStart, usXEnd, usYEnd, ucColor);
    ScalerOsdWindowHighlightFunction(_ENABLE, ucWindow, ucForegroundColor, ucBackgroundColor, _CP_BG);
	//DebugMessageOsd("2.ucWindow",ucWindow);
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    WORD usHstart = 0;
    WORD usHend = 0;
    WORD usVstart = 0;
    WORD usVend = 0;

    usHstart = ((WORD)ucCol * 12);
    usHend = usHstart + ((WORD)ucWidth * 12);

    if(ucRow > 0)
    {
        usVstart = (ucRow * 18);
    }
    usVend = usVstart + (18 * ucHeight);

    OsdWindowDrawing(ucWindow, usHstart, usVstart, usHend, usVend, ucColor);
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow1, BYTE ucCol1, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    WORD usHstart = 0;
    WORD usHend = 0;
    WORD usVstart = 0;
    WORD usVend = 0;

    usHstart = ((WORD)ucCol1 * 12);
    usHend = usHstart + ((WORD)ucWidth * 12);

    if(ucRow1 > 0)
    {
        usVstart = (ucRow1 * 18);
    }
    usVend = usVstart + (18 * ucHeight);

    OsdWindowDrawing(ucWindow, usHstart, usVstart, usHend, usVend, ucColor);

    ScalerOsdWindowHighlightFunction(_ENABLE, ucWindow, ucForegroundColor, ucBackgroundColor, _CP_BG);
}



//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowSliderDisable(void)
{
    ScalerOsdWindowDisable(_SLIDER_0_BAR_WINDOW);
    ScalerOsdWindowDisable(_SLIDER_0_BORDER_WINDOW);
    ScalerOsdWindowDisable(_SLIDER_0_BG_WINDOW);
    ScalerOsdWindowDisable(_SLIDER_1_BAR_WINDOW);
    ScalerOsdWindowDisable(_SLIDER_1_BORDER_WINDOW);
    ScalerOsdWindowDisable(_SLIDER_1_BG_WINDOW);
}

extern void ScalerBurstWrite(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, WORD usHostAddr, BYTE ucTableType, bit bTableLocation);



/*

//--------------------------------------------------
// Description  : window number mapping to register address
// Input Value  : enumOsdWindowsTyp
// Output Value :
//--------------------------------------------------
WORD ScalerOsdWindowRegisterMapping(EnumOsdWindowsType enumOsdWindowsType)
{
    WORD usWin = 0;

    usWin = enumOsdWindowsType / 10 * 16;
    usWin += (enumOsdWindowsType % 10);
    return (usWin << 8);
}


//--------------------------------------------------
// Description  : OSD Window Addr
// Input Value  : ucValue
// Output Value :
//--------------------------------------------------
void ScalerOsdSetAddrWindow(WORD usValue)
{
    ScalerSetByte(0x0090, ((usValue >> 8) & 0xFF));
    ScalerSetByte(0x0091, (usValue & 0xFF));
}



//--------------------------------------------------
// Description  : Osd Burst Write to Window (P3A_F6_FRAME_CTRL_F_OSD_WIN_DATA_PORT)
// Input Value  : Burst Write Pointer, Length, Bank, Table Type, Location
// Output Value : None
//--------------------------------------------------
void ScalerOsdBurstWriteDataPortWindow(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, BYTE ucTableType, bit bTableLocation)
{
    ScalerBurstWrite(pucAddress, usWriteLength, ucBankNum, 0x0092, ucTableType, bTableLocation);
}


//--------------------------------------------------
// Description  : Change window color
// Input Value  : 
// Output Value :
//--------------------------------------------------
void ScalerOsdChangeWindowColor(void)
{
    BYTE pucpTemp[15] = {0};
    WORD usWinTemp = 0;

    usWinTemp = ScalerOsdWindowRegisterMapping(GET_OSD_WINDOW_NUMBER());

	pucpTemp[2] = (GET_OSD_WINDOW_COLOR() & 0x3F);

	if(GET_OSD_WINDOW_WAIT_DEN_STOP() == _ENABLE)
    {
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    }
	
    ScalerOsdBurstWriteDataPort(pucpTemp, 12, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_XRAM);
	usWinTemp = 0x177 + (GET_OSD_WINDOW_NUMBER() * 7);


    pucpTemp[0] = ScalerOsdFrameControlByteGet(usWinTemp, _OSD_BYTE0);
    pucpTemp[0] = ((pucpTemp[0] & ~_BIT0) | (BYTE)GET_OSD_WINDOW_ROTATION_FUNCTION_ENABLE());
    ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE0), _OSD_WITHOUT_DB, usWinTemp, pucpTemp[0]);


    //ScalerOsdSetAddrWindow(usWinTemp + 2);
    //ScalerOsdBurstWriteDataPortWindow(&pucpTemp[2], 1, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_XRAM);
	memset(&g_stOsdWindow, 0x00, sizeof(g_stOsdWindow));
}

*/


//--------------------------------------------------
// Description  : Change window color
// Input Value  : 
// Output Value :
//--------------------------------------------------
void ScalerOsdChangeWindowColor(void)
{
    WORD usWinTemp = 0;

	EnumOsdWindowsType enumOsdWindowsType = GET_OSD_WINDOW_NUMBER();

	{
#if 0//(_OSD_WINDOW_5_1_5_8_SUPPORT == _ON)
		if((enumOsdWindowsType >= _OSD_WINDOW_5_1) && (enumOsdWindowsType <= _OSD_WINDOW_5_8))
		{
			usWinTemp = (_P0_92_PT_223_WIN5_1_ADR3_LSB >> 4) + ((enumOsdWindowsType - _OSD_WINDOW_5_1) * 4);
		}
		else
#endif
		{
			if((enumOsdWindowsType >= _OSD_WINDOW_4_1) && (enumOsdWindowsType <= _OSD_WINDOW_4_8))
			{
				//usWinTemp = (_P0_92_PT_203_WIN4_1_ADR3_MSB >> 4) + ((enumOsdWindowsType - _OSD_WINDOW_4_1) * 4);
				usWinTemp = (0x2031 >> 4) + ((enumOsdWindowsType - _OSD_WINDOW_4_1) * 4);
			}
			else if(enumOsdWindowsType <= _OSD_WINDOW_9)
			{
				//usWinTemp = (_P0_92_PT_103_WIN0_ADR3_MSB >> 4) + (enumOsdWindowsType * 4);
				usWinTemp = (0x1031 >> 4) + (enumOsdWindowsType * 4);
			}
		}

		ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE1), _OSD_WITHOUT_DB, usWinTemp, GET_OSD_WINDOW_COLOR() & 0x0F);
	}


	memset(&g_stOsdWindow, 0x00, sizeof(g_stOsdWindow));
}




#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)

