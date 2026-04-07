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
// ID Code      : RTD2014OsdFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFUNC__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)
#define _CLEAR_DATA                                     0x4C, 0x00, 0x00
extern void ScalerOsdBurstWriteDataPort(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, BYTE ucTableType, bit bTableLocation);
#if(_VIEWMODE_SUPPORT == _ON)
void UserAdjustViewModeType(BYTE ucViewModeType);
#endif
#if(_COLOR_IP_DCR == _ON)
extern void SysColorDCRHandler(void);
#endif

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
WORD g_usFontSelectStart;
WORD g_usFontTableStart;
BYTE g_ucOsdWidth;
BYTE g_ucOsdHeight;
BYTE g_ucOsdWidthB;
BYTE g_ucOsdHeightB;


WORD g_usFontPointer0 = _OSD_PAGE_0_START;
WORD g_usFontPointer1 = _OSD_PAGE_1_START;
WORD g_usFontPointer2 = _OSD_PAGE_2_START;
WORD g_usFontPointer3 = _OSD_PAGE_3_START;
WORD g_usFontPointerSlider = _OSD_PAGE_SLIDER_START;
WORD g_usFontPointerPower = _OSD_PAGE_POWER_START;
WORD g_usFontPointerRate = _OSD_PAGE_RATE_START;
WORD g_usFontPointerView = _OSD_PAGE_VIEW_START;
WORD g_usFontPointerTitle = _OSD_PAGE_TITLE_START;
WORD g_usFontPointerHDR = _OSD_PAGE_HDR_START;
WORD g_usFontPointerSN = _OSD_PAGE_SN_START;
WORD g_usFontPointerINF_RATE = _OSD_PAGE_INF_RATE_START;

bit bFreeSyncPreStatus = _OFF;
BYTE pageflag = 0;



//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);
void OsdFuncTransparency(BYTE ucTrans);
void OsdFuncBlending(BYTE ucType);



void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex);
void OsdFuncDisableOsd(void);
void OsdFuncEnableOsd(void);
void OsdFuncChangeIconColor1Bit(BYTE ucRow, BYTE ucItem, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom);
void OsdFuncSet2BitIconOffset(WORD ucOffset);
void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight);
#if(_SIX_COLOR_SUPPORT == _ON)
void OsdFuncSixColorAdjust(void);
#endif
void OsdFuncColorPcmAdjust(void);
void OsdFuncSetOsdItemFlag(void);

#if(_FREEZE_SUPPORT == _ON)
bit OsdFuncCheckFreezeDisable(void);
#endif

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
BYTE OsdFuncGetHdmiPortVersion(EnumSourceSearchPort enumSearchPort);
void OsdFuncSetHdmiPortVersion(EnumSourceSearchPort enumSearchPort,BYTE ucValue);
#endif

void OsdFuncAdj(void);
void SpecialFuncAdj(void);
void OsdInterfaceAdjust(void);



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncApplyMapOsdAB(BYTE ucWidthA, BYTE ucHeightA, BYTE ucColorA, BYTE ucWidthB, BYTE ucHeightB, BYTE ucColorB)
{
    BYTE ucI = 0;
    BYTE ucTmp = 17; // Row Height = 18
   // BYTE ucMapBRowCommandBaseAddr = (ucHeightA + 1);

////////// OSD A Row command
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucI = ucWidthA;
        ucWidthA = ucHeightA;
        ucHeightA = ucI;
        ucTmp = 11;  // Row Height = 12
    }
#endif
    // Row Command
    for(ucI = 0; ucI < ucHeightA; ucI++)
    {
        ScalerOsdCommandAllByte(ucI, 0x80, ucTmp, ucWidthA);
    }


    // Row Command end
    ScalerOsdCommandByte(ucHeightA, _OSD_BYTE0, 0x00);


////////// OSD B Row command
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucI = ucWidthB;
        ucWidthB = ucHeightB;
        ucHeightB = ucI;
        ucTmp = 11;  // Row Height = 12
    }
#endif

    // Row Command
    // MapB Row Command address must be multiple of 4
	for(ucI = (ucHeightA + 1); ucI < (ucHeightA + 1 + ucHeightB); ucI++)
	{
		ScalerOsdCommandAllByte(ucI, 0x80, ucTmp, ucWidthB);	// 0x80 Ĭ��page0/1 0xA0 page2
	}

	
	// Row Command end
	ScalerOsdCommandByte((ucHeightA + 1 + ucHeightB), _OSD_BYTE0, 0x00);


	// Frame Control (set font start address)
	g_usFontSelectStart = (ucHeightA + 1 + ucHeightB) + 1;
	g_usFontTableStart = g_usFontSelectStart + (WORD)(ucWidthA * ucHeightA) + (WORD)(ucWidthB * ucHeightB);
	ScalerOsdSramBaseAddressSet(_OSD_A, 0, g_usFontSelectStart, g_usFontTableStart);
	//ScalerOsdReferenceDelay(_OSD_B, _OSD_FIRST_DELAY);
    //ScalerOsd2FontFunction(_ON);
	ScalerOsdSramBaseAddressSet(_OSD_B, (ucHeightA + 1), (g_usFontSelectStart + (WORD)(ucWidthA * ucHeightA)), g_usFontTableStart);

    // Character Command initial
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucTmp = 0x4E;  // 18 Pixel
    }
    else
#endif
    {
        ucTmp = 0x4C;  // 12 Pixel
    }
	

    ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, ucTmp, 0, ucColorA, (WORD)ucWidthA * ucHeightA);
    ScalerOsdCharCommandAllByteSeries((g_usFontSelectStart + (WORD)(ucWidthA * ucHeightA)), ucTmp, 0, ucColorB, (WORD)ucWidthB * ucHeightB);

    g_ucOsdWidth = ucWidthA;
    g_ucOsdHeight = ucHeightA;
    g_ucOsdWidthB = ucWidthB;
    g_ucOsdHeightB = ucHeightB;
    SET_OSD_MAPA_COL_MAX(WIDTH(g_ucOsdWidth));
    SET_OSD_MAPB_COL_MAX(WIDTH(g_ucOsdWidthB));

    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdDoubleFunction(GET_OSD_DOUBLE_SIZE(), GET_OSD_DOUBLE_SIZE());


}

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    BYTE ucI = 0;
    BYTE ucTmp = 17; // Row Height = 18

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucI = ucWidth;
        ucWidth = ucHeight;
        ucHeight = ucI;
        ucTmp = 11;  // Row Height = 12
    }
#endif

    // Row Command
    for(ucI = 0; ucI < ucHeight; ucI++)
    {
        ScalerOsdCommandAllByte(ucI, 0x80, ucTmp, ucWidth);
    }

    // Row Command end
    ScalerOsdCommandByte(ucHeight, _OSD_BYTE0, 0x00);

    // Frame Control (set font start address)
    g_usFontSelectStart = ucHeight + 1;
    g_usFontTableStart = g_usFontSelectStart + (WORD)(ucWidth * ucHeight);
    ScalerOsdSramBaseAddressSet(_OSD_A, 0, g_usFontSelectStart, g_usFontTableStart);

    // Character Command initial
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucTmp = 0x4E;  // 18 Pixel
    }
    else
#endif
    {
        ucTmp = 0x4C;  // 12 Pixel
    }
    ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, ucTmp, 0, ucColor, (WORD)ucWidth * ucHeight);
/*
    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE0, ucTmp, (WORD)ucWidth * ucHeight);
    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE1, 0, (WORD)ucWidth * ucHeight);
    ScalerOsdCharCommandByteSeries(g_usFontSelectStart, _OSD_BYTE2, ucColor, (WORD)ucWidth * ucHeight);
*/
    g_ucOsdWidth = ucWidth; // for calculation (unit: word count)
    g_ucOsdHeight = ucHeight;


    SET_OSD_MAPA_COL_MAX(WIDTH(g_ucOsdWidth));

    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdDoubleFunction(GET_OSD_DOUBLE_SIZE(), GET_OSD_DOUBLE_SIZE());
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY)
{
#if(_D_DOMAIN_PATH == _D_DOMAIN_4_PATH)
    WORD usShiftValue = 0;
    BYTE ucXdouble = 1;
    WORD usTemp = 0;

    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        ucXdouble = 2;
    }

    if(ScalerOsdGetHorizontalDelayStep() == _OSD_HORIZONTAL_DELAY_STEP_4_PIXEL)
    {
        // change horizontal delay step to 1 pixel for FB shift
        ScalerOsdHorizontalDelayStep(_OSD_HORIZONTAL_DELAY_STEP_1_PIXEL);
        usX *= 4;
    }

#if(_OSD_POSITION_OFFSET_CORRECTION == _ON)
    usY = (usY >= GET_OSD_POSITION_V_OFFSET_CORRECT_COMPENSATION()) ? (usY - GET_OSD_POSITION_V_OFFSET_CORRECT_COMPENSATION()) : (usY);
#endif

    if(enumOsdPositionType == _OSD_POSITION_GLOBAL_A)
    {
        if((usX * ucXdouble) <= 100)
        {
//            ScalerOsdPosition(enumOsdPositionType, (usX * ucXdouble), usY);
            ScalerOsdPosition(enumOsdPositionType, (usX), usY);
            ScalerOsdFBShiftValue(_OSD_FRONT_BACK_SHIFT_OUTSIDE, 0);
        }
        else if((usX * ucXdouble) <= (4094 + 100))
        {
            ScalerOsdPosition(enumOsdPositionType, 100 / ucXdouble, usY);
            ScalerOsdFBShiftValue(_OSD_FRONT_BACK_SHIFT_OUTSIDE, (usX * ucXdouble) - 100);
        }
        else // > 4095+100
        {
            ScalerOsdPosition(enumOsdPositionType, ((usX * ucXdouble) - 4094) / ucXdouble, usY);
            ScalerOsdFBShiftValue(_OSD_FRONT_BACK_SHIFT_OUTSIDE, 4094);
        }

        ScalerOsdFBShiftValue(_OSD_FRONT_BACK_SHIFT_INSIDE, 0x00);
        ScalerOsdFBShiftBoundarySize(0x00, 0x00);
        ScalerOsdFBShiftEn(_ENABLE);
    }
    else if(enumOsdPositionType == _OSD_POSITION_GLOBAL_B)
    {
        usShiftValue = ScalerOsdGetFBShiftValue(_OSD_FRONT_BACK_SHIFT_OUTSIDE);

        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_0) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180))
        {
            usTemp = g_ucOsdWidthB * 12;
        }
        else
        {
            usTemp = g_ucOsdHeightB * 18;
        }

        // if HPOS over halt of Panel width + shift value, adjust to adaptable HPOS
        if((usX * ucXdouble) > ((_PANEL_DH_WIDTH / 2 + usShiftValue) - (usTemp * ucXdouble)))
        {
            ScalerOsdPosition(enumOsdPositionType, (((_PANEL_DH_WIDTH / 2 + usShiftValue) - (usTemp * ucXdouble)) / ucXdouble), usY);
        }
        else
        {
            ScalerOsdPosition(enumOsdPositionType, ((usX * ucXdouble) - usShiftValue) / ucXdouble, usY);
        }
    }
#else

#if(_OSD_POSITION_OFFSET_CORRECTION == _ON)
    usY = (usY >= GET_OSD_POSITION_V_OFFSET_CORRECT_COMPENSATION()) ? (usY - GET_OSD_POSITION_V_OFFSET_CORRECT_COMPENSATION()) : (usY);
#endif

    ScalerOsdPosition(enumOsdPositionType, usX, usY);
#endif

    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncTransparency(BYTE ucTrans)
{
	if(ucTrans == _ON)
		ScalerOsdSetTransparency(0x20);
	else
		ScalerOsdSetTransparency(0x00);

    //ScalerOsdSetTransparency(ucTrans);
}

//--------------------------------------------------
// Description  :
// Input Value  : Blending type1:Only windows blending.
//                Blending type2:All blending.
//                Blending type3:Windows & Character background blending.
// Output Value : None
//--------------------------------------------------
void OsdFuncBlending(BYTE ucType)
{
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdWindow7SpecialFunction(_OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL);
    ScalerOsdSetTransparencyType(ucType);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex)
{

    // ScalerSetByte(0x3A57, 0x00);//WIN0-7
    // ScalerSetByte(0x3A59, 0x00);//WIN4-1~4-8
    // ScalerSetByte(0x3A5A, 0x00);//WIN5-1~5-8

    // ScalerOsdWindowDisable(enumWinIndex);
    WORD usWinTemp = 0;

    if(enumWinIndex == _OSD_WINDOW_ALL)
    {
        for(usWinTemp = 0; usWinTemp < 10; usWinTemp++)
        {
            // Window 0~9
            ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE2), _OSD_WITHOUT_DB, ((0x1030 >> 4) + usWinTemp * 4), 0x00);

            if(usWinTemp < 8)
            {
                // Window 4-1~4-8
                ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE2), _OSD_WITHOUT_DB, ((0x2030 >> 4) + usWinTemp * 4), 0x00);  // _OSD_WINDOW_4_1 ~ _OSD_WINDOW_4_8

#if(_OSD_WINDOW_5_1_5_8_SUPPORT == _ON)
                // Window 5-1~5-8
                ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE2), _OSD_WITHOUT_DB, ((0x2230 >> 4) + usWinTemp * 4), 0x00);  // _OSD_WINDOW_5_1 ~ _OSD_WINDOW_5_8
#endif
            }
        }
    }
    else
    {
#if(_OSD_WINDOW_5_1_5_8_SUPPORT == _ON)
        if((enumWinIndex >= _OSD_WINDOW_5_1) && (enumWinIndex <= _OSD_WINDOW_5_8))
        {
            usWinTemp = (0x2230 >> 4) + ((enumWinIndex - _OSD_WINDOW_5_1) * 4);
        }
        else
#endif
        {
            if((enumWinIndex >= _OSD_WINDOW_4_1) && (enumWinIndex <= _OSD_WINDOW_4_8))
            {
                 usWinTemp = (0x2230 >> 4) + ((enumWinIndex - _OSD_WINDOW_4_1) * 4);
            }
            else if(enumWinIndex <= _OSD_WINDOW_9)
            {
                usWinTemp = (0x1030 >> 4) + (enumWinIndex * 4);
            }
        }

        ScalerOsdWriteByte((_OSD_WIN_CONTROL | _OSD_BYTE2), _OSD_WITHOUT_DB, usWinTemp, 0x00);
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncDisableOsd(void)
{

    ScalerOsdDisableOsd();
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable(SysSourceGetInputPort()) == _ENABLE)
    {
        SysAudioInternalGenTestProc(_OFF);
    }
#endif
}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncEnableOsd(void)
{
    ScalerOsdEnableOsd();
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncChangeIconColor1Bit(BYTE ucRow, BYTE ucItem, BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    // BYTE ucRow;
    BYTE ucCol = 3;

    if((ucRow == 18) || (ucRow == 8))
    {
        OsdFuncChangeColor1Bit(ucRow, ucCol, 8, ucHeight, (ucColor << 4) & 0xF0, _FONTFROM_256_512);
    }
    else
    {
        ucCol = COL(4) + ((ucItem % 4) * 10) - 2;
        OsdFuncChangeColor1Bit(ucRow, ucCol, ucWidth, ucHeight, (ucColor << 4) & 0xF0, _FONTFROM_0_255);
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    BYTE ucWidthCount = 0;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdWidth - ucRow - ucHeight) + g_ucOsdWidth * (ucCol + ucWidthCount) + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, (0x4E | ucFontSelectFrom), ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucHeight);
        }
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, (0x4E | ucFontSelectFrom), ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucHeight);
        }
    }
    else
#endif
    {
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, (0x4C | ucFontSelectFrom), ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSet2BitIconOffset(WORD ucOffset)
{
    ScalerOsd2BitFontOffset(ucOffset);
}


void UserCommonOsdBlankFont(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucHeight, BYTE ucPixelLength, BYTE ucBackgroundColor, EnumOsdBlankType enumOsdBlankingType)
{
    ScalerOsdBlankFont(ucRow, ucCol, ucLength, ucHeight, ucPixelLength, ucBackgroundColor, enumOsdBlankingType);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
 void OsdFuncClearOsd_1(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight)
 {
     WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
     BYTE ucHeightCount = 0;

 #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
     BYTE ucWidthCount = 0;

     if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
     {
         for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
         {
             usOsdAddr = (WORD)(g_ucOsdWidth - ucRow - ucHeight) + g_ucOsdWidth * (ucCol + ucWidthCount) + g_usFontSelectStart;
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4E, ucHeight);
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucHeight);
         }
     }
     else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
     {
         for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
         {
             usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4E, ucHeight);
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucHeight);
         }
     }
     else
 #endif
     {
         for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
         {
             // 1 Bit Font
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4C, ucWidth);
             ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucWidth);
             usOsdAddr += g_ucOsdWidth;
         }
    }
}
*/
void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight)
{
    BYTE ucHeightCount = 0;
    BYTE code tucClearTableData[] =
    {
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA, _CLEAR_DATA,
    };

    for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
    {
        ScalerOsdSramAddressCount(ucRow + ucHeightCount, ucCol, _OSD_BYTEALL);
        ScalerOsdBurstWriteDataPort(tucClearTableData, (ucWidth * 3), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    }
}

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSixColorAdjust(void)
{
	//ScalerColorSixColorAdjust(GET_OSD_SIX_COLOR(), GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());

	BYTE ucIndex = 0;
/*

	switch(GET_OSD_VIEWMODE_TYPE())
	{
		case _VM_MOVIE:
		case _VM_WEB:
		case _VM_TEXT:
		case _VM_MAC:
		case _VM_MONO:
			ScalerColorICMEnable(_FUNCTION_OFF);
			return;
			break;
		default:
			ScalerColorICMEnable(_FUNCTION_ON);
			break;
	}
    */

	for(ucIndex = 0; ucIndex < 6; ucIndex++)
    {
        SET_OSD_SIX_COLOR(ucIndex);
        OsdDisplaySixColorGetOneColor(ucIndex);
        ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
    }
}
#endif

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
void OsdFuncColorPcmAdjust(void)
{
#if(_PCM_FUNCTION == _ON)
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    UserCommonAdjustGammaRegionEnable(_FUNCTION_OFF);
    ScalerColorSRGBEnable(_FUNCTION_OFF);
    ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
    ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);
#endif


	RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��

	if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
	{
#if(_HDR10_SUPPORT == _ON)
		SET_OSD_HDR_MODE(_OFF);
#endif

	}
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE && (GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD))
    {
#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            UserAdjust3DGamma(GET_OSD_PCM_SOFT_PROFT_MODE());
        }
#endif


#if(_CONTRAST_SUPPORT == _ON)
		UserAdjustContrast(GET_OSD_CONTRAST());
#endif

        UserAdjustPCM(GET_OSD_PCM_STATUS());
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_BRIGHTNESS_SUPPORT == _ON)
        ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if 0//(_CONTRAST_SUPPORT == _ON)
        ScalerColorContrastEnable(_FUNCTION_OFF);
#endif



#if((_GLOBAL_HUE_SATURATION == _ON) && (_GLOBAL_COLOR_CONVERT_HUE_SATURATION_FUNCTION == _ON))
        UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif

        UserCommonAdjustGammaRegionEnable(_FUNCTION_ON);
        ScalerColorSRGBEnable(_FUNCTION_ON);
        ScalerColorPCMInputGammaEnable(_FUNCTION_ON);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_ON);
        }
#endif
    }
    else
    {
#if(_GAMMA_FUNCTION == _ON)
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
        UserAdjustPCM(GET_OSD_PCM_STATUS());
#else
        UserAdjustGamma(GET_OSD_GAMMA());                    
#endif
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif

#if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_GAMMA_FUNCTION == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            UserCommonAdjustGammaRegionEnable(_FUNCTION_ON);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif
        }
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        ScalerColorSRGBEnable(_FUNCTION_ON);
#endif

#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
#if(_BRIGHTNESS_SUPPORT == _ON)
        ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if(_CONTRAST_SUPPORT == _ON)
        ScalerColorContrastEnable(_FUNCTION_OFF);
#endif

#else
#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif

#if(_BRIGHTNESS_SUPPORT == _ON)
        UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#endif
#endif

	UserAdjustBacklight(GET_OSD_BACKLIGHT());    

#endif  // End of #if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))

    }
#endif  // End of #if(_PCM_FUNCTION == _ON)
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSetOsdItemFlag(void)
{
    // input port
#if(_SOURCE_AUTO_ON)
    if(SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP)
    {
        SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_AUTO);
    }
    else
#endif
    {
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
#endif
                break;

            case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D0);
#endif
                break;

            case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D1);
#endif
                break;

            case _D2_INPUT_PORT:
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D2);
#endif
                break;

            case _D3_INPUT_PORT:
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D3);
#endif
                break;

            case _D4_INPUT_PORT:
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D4);
#endif
                break;

            case _D5_INPUT_PORT:
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D5);
#endif
                break;

            case _D6_INPUT_PORT:
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D6);
#endif
                break;

            default:
                break;
        }
    }
}

#if(_FREEZE_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit OsdFuncCheckFreezeDisable(void)
{

}


#endif

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE OsdFuncGetHdmiPortVersion(EnumSourceSearchPort enumSearchPort)
{
    switch(enumSearchPort)
    {
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return (GET_OSD_D0_HDMI_VER());
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return (GET_OSD_D1_HDMI_VER());
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return (GET_OSD_D2_HDMI_VER());
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            return (GET_OSD_D3_HDMI_VER());
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            return (GET_OSD_D4_HDMI_VER());
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            return (GET_OSD_D5_HDMI_VER());
#endif

        default:
            return 0;
    }
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSetHdmiPortVersion(EnumSourceSearchPort enumSearchPort,BYTE ucValue)
{
    ucValue = ucValue;

    switch(enumSearchPort)
    {
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            SET_OSD_D0_HDMI_VER(ucValue);
            break;
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            SET_OSD_D1_HDMI_VER(ucValue);
            break;
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            SET_OSD_D2_HDMI_VER(ucValue);
            break;
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            SET_OSD_D3_HDMI_VER(ucValue);
            break;
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            SET_OSD_D4_HDMI_VER(ucValue);
            break;
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            SET_OSD_D5_HDMI_VER(ucValue);
            break;
#endif
        default:
            break;
    }
}
#endif

#if(_DCR_SUPPORT == _ON)
BYTE OsdGetEcoBacklightValue(void)
{
    BYTE ucPwm = 0;
    ucPwm = PCB_GET_BACKLIGHT_PWM();
#if(_BACKLIGHT_PWM_INVERSE == _ON)
    ucPwm = 0xff - ucPwm;
#endif

	switch(GET_OSD_ECO_STATUS())
	{
		case _ECO_OPTIMIZE:
		case _ECO_CONSERVE:
			
#if 1//(Project_ID == _ID_JS_HK2313E01_MV238FHB_N51_LVDS__EDID_VA240_H_2_FHD75HZ_20240801)
			return UserCommonAdjustRealValueToPercent(ucPwm, MAX(_BACKLIGHT_MAX_PWM), MIN(_BACKLIGHT_MIN_PWM), CENTER(_BACKLIGHT_PWM_CENTER));
#else
			return UserCommonAdjustRealValueToPercent_BACK(PCB_GET_BACKLIGHT_PWM(), MAX(_BACKLIGHT_MAX_PWM), MIN(_BACKLIGHT_MIN_PWM), CENTER(_BACKLIGHT_PWM_CENTER));
#endif

			break;

		default:
			if(GET_OSD_DCR_STATUS() > _DCR_MIN)
			{
#if 1//(Project_ID == _ID_JS_HK2313E01_MV238FHB_N51_LVDS__EDID_VA240_H_2_FHD75HZ_20240801)
				return UserCommonAdjustRealValueToPercent(ucPwm, MAX(_BACKLIGHT_MAX_PWM), MIN(_BACKLIGHT_MIN_PWM), CENTER(_BACKLIGHT_PWM_CENTER));
#else
				return UserCommonAdjustRealValueToPercent_BACK(PCB_GET_BACKLIGHT_PWM(), MAX(_BACKLIGHT_MAX_PWM), MIN(_BACKLIGHT_MIN_PWM), CENTER(_BACKLIGHT_PWM_CENTER));
#endif
			}

			return GET_OSD_BACKLIGHT();
			break;
	}
}

//--------------------------------------------------
// Description  : Temporary turn on function when DFM mode is on
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustDCR(void)
{
#if(_HDR10_SUPPORT == _ON)
  //     if(GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
	   if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
       {

       }
	else
#endif
	{
		if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
		{
			//if(g_usBackupValue == _OFF && GET_OSD_DCR_STATUS() == 1)
			{
				//SET_DCR_ADJUST_VALUE(OsdGetEcoBacklightValue());
				SET_DCR_ADJUST_VALUE(GET_OSD_BACKLIGHT());
			}

			SysColorDCRHandler();
			ScalerTimerActiveTimerEvent(SEC(0.01), _USER_TIMER_EVENT_DCR_SLOW_ADJUST);
/*
			if(GET_OSD_ECO_STATUS() != _ECO_DEFAULT)
			{
				SET_OSD_ECO_STATUS(_ECO_DEFAULT);
				RTDNVRamSaveOSDData();
				
               //g_stVscSceneModeData.usBackLightSrgb = GET_OSD_BACKUP_SRGB_BRI();
		       //RTDNVRamSaveSrgbBrightness(GET_OSD_GAME_MODE());
			}
*/
		}
		else if((GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD)||(GET_OSD_VIEWMODE_TYPE() == _VM_GAME))
		{
			CDcrReset();
			SET_DCR_ADJUST_VALUE(GET_OSD_BACKLIGHT());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}
	}
}
#endif






#if(_OD_SUPPORT == _ON)


extern void UserAdjustLoadODTable(void);

#if(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD120_VA240A_H_20240812)
#define _OD_GAIN_ADVANCED				0x13 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x3E 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x78  //�û�
#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812)
#define _OD_GAIN_ADVANCED				0x1C //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x34 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x80  //�û�
#elif(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV238FHB_NY1_8BIT_FHD144_VA24G25_20241213)
#define _OD_GAIN_ADVANCED				0x13 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x3E 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x78  //�û�
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223)
#define _OD_GAIN_ADVANCED				0x10 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x30 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x60  //�û�
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250103 || _PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_E8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250228)
#define _OD_GAIN_ADVANCED				0x10 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x30 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x60  //�û�
#elif(_PROJECT_ID==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
#define _OD_GAIN_STANDARD				0x00//  6.8 ��׼
#define _OD_GAIN_ADVANCED				0x10 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x30 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x60  //�û�

#elif(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115)
#define _OD_GAIN_ADVANCED				0x10 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x30 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x60  //�û�
#elif(_PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224)
#define _OD_GAIN_ADVANCED				0x10 //.8 //�߼�
#define _OD_GAIN_ULTRA_FAST 			0x30 	//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x60  //�û�

#else
#define _OD_GAIN_STANDARD				0x00//  6.8 ��׼
#define _OD_GAIN_ADVANCED				0x1C//  6.8 �߼�
#define _OD_GAIN_ULTRA_FAST 			0x35//
#define _OD_GAIN_USERCOLOR_ULTRA_FAST	0x50   //�û�

#endif


#define _OD_GAIN_1MS					0x28  


//--------------------------------------------------
// Description  : GET OD Gain for difference Panel
// Input Value  : None
// Output Value : None  ScalerMDomainODConfig
//--------------------------------------------------
BYTE UserAdjustGetODGain(BYTE ucOdMode)
{
	switch(ucOdMode)
	{
		case _OD_ADVANCED:
			return _OD_GAIN_ADVANCED;
			break;

	//	case _OD_FASTER:
		//	return _OD_GAIN_FASTER;
		//	break;
				
		case _OD_ULTRA_FAST:
#if(_OD_MODE_2_SUPPORT == _OFF)
			if(GET_COLOR_TEMP_TYPE() != _CT_USER)
			{
				return _OD_GAIN_ULTRA_FAST;
			}
			else
#endif
			{
				return _OD_GAIN_USERCOLOR_ULTRA_FAST;
			}
			break;
/*
		case _OD_FASTEST:
			if(GET_COLOR_TEMP_TYPE() != _CT_USER)
			{
				return _OD_GAIN_FASTEST;
			}
			else
			{
				return _OD_GAIN_USERCOLOR_ULTRA_FAST;
			}
			break;


			*/
#if 0//(Project_ID == _ID_JS_HK2313E01_SG2151B06_1_LVDS__EDID_VA220_H_FHD100HZ_20231219)
		case _OD_MPRT:
			return 0x20;
			break;
#endif		
		default:
			return 0x00;
			break;
	}
}

#if(_PANEL_TYPE==_BOE_DV245QHB_N20_EDP_QHD180HZ || _PANEL_TYPE==_BOE_ME270QHB_NF2_EDP_QHD180HZ)

#if(_PANEL_TYPE==_BOE_DV245QHB_N20_EDP_QHD180HZ)
BYTE code ODValue[][4] = 
{
    {0, 8, 8, 8},//480
    {0, 10, 11, 13},//600
    {0, 14, 15, 17},//800
    {0, 17, 19, 22},//1000
    {0, 22, 24, 28},//1200
    {0, 30, 32, 36},//1440
    {0, 35, 48, 50},//1650
    {0, 40, 50, 55},//1800
};

#elif(_PANEL_TYPE==_BOE_ME270QHB_NF2_EDP_QHD180HZ)
BYTE code ODValue[][4] = 
{
    {0, 1, 1, 1},//480
    {0, 3, 5, 8},//600
    {0, 8, 9, 17},//800
    {0, 13, 15, 24},//1000
    {0, 17, 21, 34},//1200
    {0, 21, 26, 41},//1440
    {0, 29, 39, 56},//1650
    {0, 37, 70, 120},//1800
};
#endif


BYTE GetDynamicODValue(BYTE ucOdMode)
{
        BYTE *odgain = ODValue[0];
        if(GET_INPUT_TIMING_VFREQ() >= 1790)
		{
			odgain = ODValue[7];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 1640)
		{
			odgain = ODValue[6];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 1430)
		{
			odgain = ODValue[5];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 1190)
		{
			odgain = ODValue[4];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 990)
		{
			odgain = ODValue[3];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 790)
		{
			odgain = ODValue[2];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 590)
		{
			odgain = ODValue[1];
		}
		else if(GET_INPUT_TIMING_VFREQ() >= 470)
		{
			odgain = ODValue[0];
		}
		return odgain[ucOdMode];
}
#endif

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

#if(_PROJECT_ID ==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
BYTE GetOdGain(void)
{

BYTE cmd_gain;

		switch(GET_OSD_OD_STATUS())
		{		
		
			case _OD_STANDARD:


			{
				if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<800))
					cmd_gain = 5;

				else if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<1000))
					cmd_gain = 8;

				else if((g_stInputTimingData.usVFreq>=1000)&&(g_stInputTimingData.usVFreq<1200))
					cmd_gain = 12;

				else if((g_stInputTimingData.usVFreq>=1200)&&(g_stInputTimingData.usVFreq<1440))
					cmd_gain = 15;

				else if((g_stInputTimingData.usVFreq>=1440)&&(g_stInputTimingData.usVFreq<1650))
					cmd_gain = 18;

				else if((g_stInputTimingData.usVFreq>=1650)&&(g_stInputTimingData.usVFreq<1800))
					cmd_gain = 20;

				else if((g_stInputTimingData.usVFreq>=1800)&&(g_stInputTimingData.usVFreq<2000))
					cmd_gain = 24;
				
				else if((g_stInputTimingData.usVFreq>=2000)&&(g_stInputTimingData.usVFreq<2200))
					cmd_gain = 27;

				else if((g_stInputTimingData.usVFreq>=2200)&&(g_stInputTimingData.usVFreq<2400))
					cmd_gain = 30;

				else if((g_stInputTimingData.usVFreq>=2400)&&(g_stInputTimingData.usVFreq<2500))
					cmd_gain = 34;
				else
					cmd_gain = 2;





			}






			

			break;
			
			case _OD_ADVANCED:

			
		{
				if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<800))
					cmd_gain = 6;

				else if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<1000))
					cmd_gain = 9;

				else if((g_stInputTimingData.usVFreq>=1000)&&(g_stInputTimingData.usVFreq<1200))
					cmd_gain = 14;

				else if((g_stInputTimingData.usVFreq>=1200)&&(g_stInputTimingData.usVFreq<1440))
					cmd_gain = 18;

				else if((g_stInputTimingData.usVFreq>=1440)&&(g_stInputTimingData.usVFreq<1650))
					cmd_gain = 20;

				else if((g_stInputTimingData.usVFreq>=1650)&&(g_stInputTimingData.usVFreq<1800))
					cmd_gain = 24;

				else if((g_stInputTimingData.usVFreq>=1800)&&(g_stInputTimingData.usVFreq<2000))
					cmd_gain = 27;
				
				else if((g_stInputTimingData.usVFreq>=2000)&&(g_stInputTimingData.usVFreq<2200))
					cmd_gain = 30;

				else if((g_stInputTimingData.usVFreq>=2200)&&(g_stInputTimingData.usVFreq<2400))
					cmd_gain = 34;

				else if((g_stInputTimingData.usVFreq>=2400)&&(g_stInputTimingData.usVFreq<2500))
					cmd_gain = 45;
				else
					cmd_gain = 2;





			}

			break;
			
			case _OD_ULTRA_FAST:

				{
				if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<800))
					cmd_gain = 7;

				else if((g_stInputTimingData.usVFreq>=600)&&(g_stInputTimingData.usVFreq<1000))
					cmd_gain = 10;

				else if((g_stInputTimingData.usVFreq>=1000)&&(g_stInputTimingData.usVFreq<1200))
					cmd_gain = 16;

				else if((g_stInputTimingData.usVFreq>=1200)&&(g_stInputTimingData.usVFreq<1440))
					cmd_gain = 20;

				else if((g_stInputTimingData.usVFreq>=1440)&&(g_stInputTimingData.usVFreq<1650))
					cmd_gain = 24;

				else if((g_stInputTimingData.usVFreq>=1650)&&(g_stInputTimingData.usVFreq<1800))
					cmd_gain = 27;

				else if((g_stInputTimingData.usVFreq>=1800)&&(g_stInputTimingData.usVFreq<2000))
					cmd_gain = 32;

				else if((g_stInputTimingData.usVFreq>=2000)&&(g_stInputTimingData.usVFreq<2200))
					cmd_gain = 36;

				else if((g_stInputTimingData.usVFreq>=2200)&&(g_stInputTimingData.usVFreq<2400))
					cmd_gain = 40;

				else if((g_stInputTimingData.usVFreq>=2400)&&(g_stInputTimingData.usVFreq<2500))
					cmd_gain = 50;
				else
					cmd_gain = 2;





				}

			break;
			

		}


return cmd_gain;
}


#endif
void UserAdjustOverDrive(void)
{
	EnumFunctionOnOFF bODStatus = _OFF;
	BYTE ucODGain = 0x00;
	BYTE ucODSTATUS = 0x00;

	DWORD usMaxVFreq = _PANEL_MAX_FRAME_RATE;
	DWORD usMinVFreq = _PANEL_MIN_FRAME_RATE;
	DWORD usCurVFreq = 0;
	BYTE ucValue = 0;

	WORD OD_MAX_Gain = 0x40;
	WORD OD_MIN_Gain = 0X05;


	usCurVFreq = GET_INPUT_TIMING_VFREQ();

	if(usCurVFreq > usMaxVFreq)
		usCurVFreq = usMaxVFreq;
	else if(usCurVFreq < usMinVFreq)
		usCurVFreq = usMinVFreq;

    if((SysModeGetModeState() != _MODE_STATUS_ACTIVE) && (SysModeGetModeState() != _MODE_STATUS_DISPLAY_SETTING))
    {
	    ScalerODEnable(_OFF);
	    return;
    }

    if(GET_OSD_OD_STATUS() == _OFF)
    {
        bODStatus = _OFF;
		ScalerODEnable(bODStatus);
		return;
    }
    else
    {
        bODStatus = _ON;
    }
    
    UserAdjustLoadODTable();

#if(_PANEL_TYPE==_BOE_DV245QHB_N20_EDP_QHD180HZ)
       
    ucValue = GetDynamicODValue(GET_OSD_OD_STATUS()); 

#elif(_PANEL_TYPE==_BOE_ME270QHB_NF2_EDP_QHD180HZ)

	if(GET_COLOR_TEMP_TYPE()==_CT_USER && GET_OSD_OD_STATUS()==_OD_ULTRA_FAST)
		ucODSTATUS = (GET_OSD_OD_STATUS()+1);
	else
		ucODSTATUS = GET_OSD_OD_STATUS();
	ucValue = GetDynamicODValue(ucODSTATUS); 

#else
	switch(GET_OSD_OD_STATUS())
	{		
	
#if(_OD_TIME_OFF_OPTION == _ON)
		case _OD_STANDARD:
			OD_MAX_Gain = _OD_GAIN_STANDARD; 
			OD_MIN_Gain = 0X08;
		break;
#endif
		case _OD_ADVANCED:
			OD_MAX_Gain = _OD_GAIN_ADVANCED; 
			OD_MIN_Gain = 0X08;
		break;
		
		case _OD_ULTRA_FAST:
			if(GET_COLOR_TEMP_TYPE() != _CT_USER)
				OD_MAX_Gain = _OD_GAIN_ULTRA_FAST; 
			else
				OD_MAX_Gain = _OD_GAIN_USERCOLOR_ULTRA_FAST; 

			OD_MIN_Gain = 0X08;
		break;
		
		
		default :			
			OD_MAX_Gain = 0X00; 
			OD_MIN_Gain = 0X00;
			break;
	}
#if(_PROJECT_ID ==_ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)

	ucValue = GetOdGain();
#else
	ucValue = (BYTE)((DWORD)(( OD_MAX_Gain - OD_MIN_Gain) * (usCurVFreq - usMinVFreq)) / (usMaxVFreq - usMinVFreq)) + OD_MIN_Gain;
#endif
#endif

	
	DebugMessageOsd("0.OD ucValue",ucValue);


    ScalerODEnable(bODStatus);
    ScalerODAdjustDeltaGain(ucValue);
}



void UserAdjustOverDrive1ms(void)
{
	EnumFunctionOnOFF bODStatus = _OFF;
	BYTE ucODGain = 0x00;

	DWORD usMaxVFreq = _PANEL_MAX_FRAME_RATE;
	DWORD usMinVFreq = _PANEL_MIN_FRAME_RATE;
	DWORD usCurVFreq = 0;
	BYTE ucValue = 0;

	WORD OD_MAX_Gain = 0x40;
	WORD OD_MIN_Gain = 0X05;


	usCurVFreq = GET_INPUT_TIMING_VFREQ();

	if(usCurVFreq > usMaxVFreq)
		usCurVFreq = usMaxVFreq;
	else if(usCurVFreq < usMinVFreq)
		usCurVFreq = usMinVFreq;

    if((SysModeGetModeState() != _MODE_STATUS_ACTIVE) && (SysModeGetModeState() != _MODE_STATUS_DISPLAY_SETTING))
    {
	    ScalerODEnable(_OFF);
	    return;
    }

    if(GET_OSD_MPRT() == _OFF)
    {
        bODStatus = _OFF;
		ScalerODEnable(bODStatus);
		return;
    }
    else
    {
        bODStatus = _ON;
    }
    
    UserAdjustLoadODTable();

	if(GET_OSD_MPRT())
	{
		OD_MAX_Gain = _OD_GAIN_1MS; 
		OD_MIN_Gain = 0X08;
	}


	ucValue = (BYTE)((DWORD)(( OD_MAX_Gain - OD_MIN_Gain) * (usCurVFreq - usMinVFreq)) / (usMaxVFreq - usMinVFreq)) + OD_MIN_Gain;
	DebugMessageOsd("0.1ms ucValue",ucValue);


    ScalerODEnable(bODStatus);
    ScalerODAdjustDeltaGain(ucValue);
}

#endif//#if(_OD_SUPPORT == _ON)



//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustForceExecuteSmartSync(void)
{
	#if 0//(_SMARTSYNC_SUPPORT == _ON)
	if((GET_OSD_SMARTSYNC() == _ON) && ((GET_INPUT_TIMING_VFREQ() >= 850) || (GET_OSD_FREESYNC() == _ON)))
	{
		SET_OSD_LOW_LAG_STATUS(_LATENCY_H);
		SET_OSD_OD_MODE(_OD_ULTRA_FAST);
		SET_OSD_DCR_STATUS(_DCR_MAX);
         DebugMessageSystem("###666GET_OSD_LOW_LAG_STATUS###",GET_OSD_LOW_LAG_STATUS());

		RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
	}
	else
	{
		SET_OSD_LOW_LAG_STATUS(GET_BACKUP_LOW_LAG_STATUS());
		SET_OSD_OD_MODE(GET_BACKUP_OD_MODE());
		SET_OSD_DCR_STATUS(GET_BACKUP_DCR_STATUS());
         DebugMessageSystem("###555GET_OSD_LOW_LAG_STATUS###",GET_OSD_LOW_LAG_STATUS());

		RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
	}

	#endif

	#if(_OD_SUPPORT == _ON)
    UserAdjustOverDrive();
	#endif

	#if(_ULTRA_VIVID_SUPPORT == _ON)
	UserInterfaceAdjustUltraVivid();
	#endif

	#if(_SIX_COLOR_SUPPORT == _ON)
	OsdFuncSixColorAdjust();
	#endif

	// for latency setting
#if(_USER_LATENCY_ADJUST_SUPPORT == _ON)
	SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
#endif
}



//--------------------------------------------------
// Description  : Temporary turn on function when DFM mode is on
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustViewMode(void)
{
	BYTE tempItem ;
	bit tempOriginMode = _FALSE;
	BYTE tempAspectMode = GET_OSD_ASPECT_RATIO_TYPE();
    #if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
	BYTE tempOverScan = UserAdjustGetOverScanStatus();
    #endif
#if(_DEF_JS_OSD_FPS_forbidden_ASP)
	BYTE tempViemOldMode = GET_OSD_GAME_MODE();
#endif

	BYTE ucIndex = 0;

#if(_DEFAULT_OSD_STYLE==_TRG_OSD_STYLE)
	if(GET_OSD_STATE()==_OSD_HOTKEY_FUNC && OSD_HOT_KEY_PAGE==_OSD_HOTKEY_VIEWMODE )
		tempItem = OSD_SubMenuCur;
	else
		tempItem = OSD_SubMenuCur+g_usOsdMenu2Page*_OSD_ITEM_LENGTH;
#else
	tempItem = OSD_SubMenuCur;
#endif

	
	
	//DebugMessageOsd("1.00",GET_COLOR_TEMP_TYPE());
	if(tempItem != GetOsdValue(_MENU_VIEWMODE))
	{

		if((GET_COLOR_TEMP_TYPE() == _CT_USER)
		&& ((GET_COLOR_TEMP_TYPE_USER_R() != _USER_RGB_MAX)
		|| (GET_COLOR_TEMP_TYPE_USER_G() != _USER_RGB_MAX)
		|| (GET_COLOR_TEMP_TYPE_USER_B() != _USER_RGB_MAX)))
		{
		
			SET_COLOR_TEMP_TYPE_USER_R(_USER_RGB_MAX);
			SET_COLOR_TEMP_TYPE_USER_G(_USER_RGB_MAX);
			SET_COLOR_TEMP_TYPE_USER_B(_USER_RGB_MAX);
			RTDNVRamSaveColorSetting(_CT_USER);

		}
		
#if(_OSD_GAME_SUPPORT == _ON)	

		if(tempItem >= 1 && tempItem <= (_GAMEMODE_AMOUNT-1))
		{
			SET_OSD_GAME_MODE(tempItem - 1);
			SET_OSD_VIEWMODE_TYPE(_VM_GAME);
		}
		else if(tempItem > (_GAMEMODE_AMOUNT-1))
		{
			SET_OSD_GAME_MODE(_GM_OFF);
			SET_OSD_VIEWMODE_TYPE(tempItem - (_GAMEMODE_AMOUNT-2));
		}
		else
		{
			SET_OSD_GAME_MODE(_GM_OFF);
			SET_OSD_VIEWMODE_TYPE(tempItem);
		}

		g_usBackupValue = tempItem;
#else
		if(tempItem == _VM_GAME)
		{
			SET_OSD_GAME_MODE(_GM_OFF);
		}
		else if(g_usBackupValue == _VM_GAME)
		{
			SET_OSD_GAME_MODE(_GM_OFF);
		}
		SET_OSD_VIEWMODE_TYPE(tempItem);

		g_usBackupValue = GET_OSD_VIEWMODE_TYPE();

#endif
		RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE()); //���¶�Ӧ�ṹ��
		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��

		if(GET_OSD_GAME_MODE() == _GM_FPS1)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(3);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OD_ADVANCED);

		}
#if(_DEF_VIEWMODE_RTS == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_RTS)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(7);
			if(GET_OSD_MPRT())
				SET_OSD_DCR_STATUS(_DCR_Level_0);
			else 
				SET_OSD_DCR_STATUS(RTS_DEF_DCR);
			SET_OSD_OD_STATUS(_OFF);
			RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE()); // ����:�ڿ���MPRT������£�����DCRΪ0�����ܺ���MPRT����DCR��Ҫ������

		}
#endif
#if(_DEF_VIEWMODE_MOBA == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_MOBA)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(6);			
			if(GET_OSD_MPRT())
				SET_OSD_DCR_STATUS(_DCR_Level_0);
			else 
				SET_OSD_DCR_STATUS(MOBA_DEF_DCR);
			SET_OSD_OD_STATUS(_OD_ADVANCED);
			RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE()); // ����:�ڿ���MPRT������£�����DCRΪ0�����ܺ���MPRT����DCR��Ҫ������

		}	
#endif
		else if(
				GET_OSD_VIEWMODE_TYPE() == _VM_MOVIE || 
#if(_DEF_VIEWMODE_MAC)
			 	 GET_OSD_VIEWMODE_TYPE() == _VM_MAC ||
#endif
				 GET_OSD_VIEWMODE_TYPE() == _VM_WEB 
			 	 )
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);

		}	
		else if(GET_OSD_VIEWMODE_TYPE() == _VM_MONO)
		{			
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);
#if(_HDR10_SUPPORT == _ON)
			SET_OSD_HDR_MODE(_OFF);
#endif

		}
		else if(GET_OSD_VIEWMODE_TYPE() == _VM_TEXT )
		{
			SET_OSD_LOW_BLUE(30);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);
            SET_COLOR_TEMP_TYPE(_CT_6500); // Ԥ��

		}	


		bFreeSyncPreStatus = GET_OSD_FREE_SYNC_STATUS();
		
		RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE()); //���¶�Ӧ�ṹ��
/*
		if(GET_OSD_DCR_STATUS())
		{
			SET_BACKUP_DCR_STATUS(GET_OSD_DCR_STATUS());
			SET_OSD_DCR_STATUS(_OFF);
			ScalerTimerActiveTimerEvent(SEC(0.8), _USER_TIMER_EVENT_DCR_FUN_ON); //�ӳ�2S�ٿ�DCR
		}
		*/
		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��
#if(_VIEWMODE_ADJUST_BLACK)	

		ScalerDDomainPatternGenAdjustColor(0, 0, 0);//�ر���Ĺ������������ƻ���һЩ���߰���Ļ���
		ScalerDDomainBackgroundSetColor(0, 0, 0);
		ScalerDDomainBackgroundEnable(_ENABLE);
#endif

#if(_DEF_JS_OSD_FPS_forbidden_ASP)
		 if(GET_OSD_GAME_MODE() == _GM_FPS1 && tempAspectMode != _OSD_ASPECT_RATIO_16_BY_9 )
		{
			tempOriginMode = _TRUE;
		}
		else
#endif
		{		    
 #if(_VIEWMODE_ADJUST_BLACK)	            
			UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);   
#endif 
		}

    #if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		 if(tempOverScan != UserAdjustGetOverScanStatus() )
		{
			tempOriginMode = _TRUE;
		}
    #endif

		
#if(_VIEWMODE_SUPPORT == _ON)
		UserAdjustViewModeType(GET_OSD_VIEWMODE_TYPE());	//����Ч������
#endif

		if(GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD)
		{
			if(GET_COLOR_TEMP_TYPE() != _CT_SRGB)
			{
				UserAdjustContrast(GET_OSD_CONTRAST());
			}
			else
			{
				UserAdjustContrast(_SRGB_CONTRAST);
			}
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}
		else
		{
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}

	#if(_DCC_FUNCTION == _ON)
		UserAdjustColorEffectMode();
	#endif

		UserAdjustForceExecuteSmartSync();

		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		
#if(_DCR_SUPPORT ==_ON)
		if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
		SET_DCR_ADJUST_VALUE(OsdGetEcoBacklightValue());	//DCR���䱣��������ֵ
#endif

		if(GET_OSD_STATE()==_OSD_HOTKEY_FUNC && OSD_HOT_KEY_PAGE==_OSD_HOTKEY_VIEWMODE && GET_KEYMESSAGE()==_MENU_KEY_MESSAGE)
		{
			OsdHotKeyString();		// ѡ�����壬�ı���ɫ
		}


#if(_ADVANCED_IMAGE_SUPPORT == _ON)
#if(_DEF_JS_OSD_FPS_forbidden_ASP)
		if(tempOriginMode == _TRUE)
		{
			SET_OSD_ASPECT_RATIO_TYPE(_OSD_ASPECT_RATIO_16_BY_9);
			tempAspectMode = _OSD_ASPECT_RATIO_16_BY_9;
			SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
		}
		else
#endif
#endif
		{
    	#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
			 if((tempOverScan != UserAdjustGetOverScanStatus())||(tempAspectMode != GET_OSD_ASPECT_RATIO_TYPE()))
		#else		
			if(tempAspectMode != GET_OSD_ASPECT_RATIO_TYPE())
		#endif
			{
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
			}
			else
			{
#if(_VIEWMODE_ADJUST_BLACK)			
				UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				ScalerDDomainBackgroundEnable(_DISABLE);
#endif				
			}

		}

#if(_MPRT_SUPPORT == _ON)
#if(_DEF_VIEWMODE_MAC)
		if(GET_OSD_VIEWMODE_TYPE() == _VM_MAC && GET_OSD_MPRT())
		{
			SET_OSD_MPRT(_OFF);
			UserAdjustMPRTFuntion(GET_OSD_MPRT());
		}
		else
#endif
		{
			UserAdjustMPRTFuntion(GET_OSD_MPRT());
		}

#endif



#if 0//(_DEF_VIE_ASP_accord)	//���ֻ����������
		if(tempAspectMode != GET_OSD_ASPECT_RATIO_TYPE())
		{
			SET_OSD_ASPECT_RATIO_TYPE(tempAspectMode);
			RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
		}
#endif

	}
}


#if(_OSD_VIEWMODE_USER_GAME_MODE)

void UserAdjustGameMode(void)
{
	bit tempOriginMode = _FALSE;
	BYTE tempAspectMode = GET_OSD_ASPECT_RATIO_TYPE();
    #if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
	BYTE tempOverScan = UserAdjustGetOverScanStatus();
    #endif
#if(_DEF_JS_OSD_FPS_forbidden_ASP)
	BYTE tempViemOldMode = GET_OSD_GAME_MODE();
#endif
	BYTE tempItem = OSD_SubMenuCur;

	BYTE ucIndex = 0;
	
	DebugMessageOsd("2.UserAdjustViewMode",tempAspectMode);
	
	//if(tempItem != GetOsdValue(_MENU_VIEWMODE))
	{
		


		if((tempItem >= 1) && (tempItem <= 3))
		{
			SET_OSD_GAME_MODE(tempItem - 1);
			SET_OSD_VIEWMODE_TYPE(_VM_GAME);
		}
		else if(tempItem > 3)
		{
			SET_OSD_GAME_MODE(_GM_OFF);
			SET_OSD_VIEWMODE_TYPE(tempItem);

		}
		else
		{
			SET_OSD_GAME_MODE(_GM_OFF);
			SET_OSD_VIEWMODE_TYPE(tempItem);
		}


		g_usBackupValue = tempItem;

		RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE()); //���¶�Ӧ�ṹ��
		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��

		if(GET_OSD_GAME_MODE() == _GM_FPS1)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(3);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OD_ADVANCED);

		}
#if(_DEF_VIEWMODE_RTS == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_RTS)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(7);
			if(GET_OSD_MPRT())
				SET_OSD_DCR_STATUS(_DCR_Level_0);
			else 
				SET_OSD_DCR_STATUS(_DCR_Level_4);
			SET_OSD_OD_STATUS(_OFF);
			RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE()); // ����:�ڿ���MPRT������£�����DCRΪ0�����ܺ���MPRT����DCR��Ҫ������

		}
#endif

#if(_DEF_VIEWMODE_MOBA == _ON)
		else if(GET_OSD_GAME_MODE() == _GM_MOBA)
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(6);			
			if(GET_OSD_MPRT())
				SET_OSD_DCR_STATUS(_DCR_Level_0);
			else 
				SET_OSD_DCR_STATUS(_DCR_Level_3);
			SET_OSD_OD_STATUS(_OD_ADVANCED);
			RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE()); // ����:�ڿ���MPRT������£�����DCRΪ0�����ܺ���MPRT����DCR��Ҫ������

		}	
#endif
		else if(
				GET_OSD_VIEWMODE_TYPE() == _VM_MOVIE || 
#if(_DEF_VIEWMODE_MAC)
			 	 GET_OSD_VIEWMODE_TYPE() == _VM_MAC ||
#endif
				 GET_OSD_VIEWMODE_TYPE() == _VM_WEB 
			 	 )
		{
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);

		}	
		else if(GET_OSD_VIEWMODE_TYPE() == _VM_MONO)
		{			
			SET_OSD_LOW_BLUE(0);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);
#if(_HDR10_SUPPORT == _ON)
			SET_OSD_HDR_MODE(_OFF);
#endif

		}
		else if(GET_OSD_VIEWMODE_TYPE() == _VM_TEXT )
		{
			SET_OSD_LOW_BLUE(30);
			SET_OSD_BLACKSTABLE(5);
			SET_OSD_DCR_STATUS(_DCR_Level_0);
			SET_OSD_OD_STATUS(_OFF);
            SET_COLOR_TEMP_TYPE(_CT_6500); // Ԥ��

		}	


		bFreeSyncPreStatus = GET_OSD_FREE_SYNC_STATUS();
		
		RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE()); //���¶�Ӧ�ṹ��

		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��
#if(_VIEWMODE_ADJUST_BLACK)	

		ScalerDDomainPatternGenAdjustColor(0, 0, 0);//�ر���Ĺ������������ƻ���һЩ���߰���Ļ���
		ScalerDDomainBackgroundSetColor(0, 0, 0);
		ScalerDDomainBackgroundEnable(_ENABLE);
#endif

#if(_DEF_JS_OSD_FPS_forbidden_ASP)
		 if(GET_OSD_GAME_MODE() == _GM_FPS1 && tempAspectMode != _OSD_ASPECT_RATIO_16_BY_9 )
		{
			tempOriginMode = _TRUE;
		}
		else
#endif
		{		    
 #if(_VIEWMODE_ADJUST_BLACK)	            
			UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);   
#endif 
		}

    #if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
		 if(tempOverScan != UserAdjustGetOverScanStatus() )
		{
			tempOriginMode = _TRUE;
		}
    #endif

		
#if(_VIEWMODE_SUPPORT == _ON)
		UserAdjustViewModeType(GET_OSD_VIEWMODE_TYPE());	//����Ч������
#endif

		if(GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD)
		{
			if(GET_COLOR_TEMP_TYPE() != _CT_SRGB)
			{
				UserAdjustContrast(GET_OSD_CONTRAST());
			}
			else
			{
				UserAdjustContrast(_SRGB_CONTRAST);
			}
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}
		else
		{
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
		}

	#if(_DCC_FUNCTION == _ON)
		UserAdjustColorEffectMode();
	#endif

		UserAdjustForceExecuteSmartSync();

		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
#if(_DCR_SUPPORT ==_ON)
		if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
		SET_DCR_ADJUST_VALUE(OsdGetEcoBacklightValue());	//DCR���䱣��������ֵ
#endif
		if(GET_OSD_STATE()==_OSD_HOTKEY_FUNC && OSD_HOT_KEY_PAGE==_OSD_HOTKEY_VIEWMODE && GET_KEYMESSAGE()==_MENU_KEY_MESSAGE)
		{
			OsdHotKeyString();		// ѡ�����壬�ı���ɫ
		}


#if(_ADVANCED_IMAGE_SUPPORT == _ON)
#if(_DEF_JS_OSD_FPS_forbidden_ASP)
		if(tempOriginMode == _TRUE)
		{
			SET_OSD_ASPECT_RATIO_TYPE(_OSD_ASPECT_RATIO_16_BY_9);
			tempAspectMode = _OSD_ASPECT_RATIO_16_BY_9;
			SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
		}
		else
#endif
#endif
		{
    		#if(_OVERSCAN_SAVE_BY_INPUTPORT == _OFF)
			 if((tempOverScan != UserAdjustGetOverScanStatus())||(tempAspectMode != GET_OSD_ASPECT_RATIO_TYPE()))
		#else		
			if(tempAspectMode != GET_OSD_ASPECT_RATIO_TYPE())
		#endif
			{
				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
			}
			else
			{
#if(_VIEWMODE_ADJUST_BLACK)			
				UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				ScalerDDomainBackgroundEnable(_DISABLE);
#endif				
			}

		}

#if 0//(_MPRT_SUPPORT == _ON)
#if(_DEF_VIEWMODE_MAC)
		if(GET_OSD_VIEWMODE_TYPE() == _VM_MAC && GET_OSD_MPRT())
		{
			SET_OSD_MPRT(_OFF);
			UserAdjustMPRTFuntion(GET_OSD_MPRT());
		}
		else
#endif
		{
			UserAdjustMPRTFuntion(GET_OSD_MPRT());
		}

#endif




	}
}

#endif


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncAdj(void)
{
    BYTE ucStateIndex = OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur];
	
	DebugMessageOsd("1.OsdFuncAdj_State",ucStateIndex);

#if(_OSD_VIEWMODE_USER_GAME_MODE)
	if(GET_OSD_STATE()==_MENU_FUN_RESPONSE_TIME)
		ucStateIndex=GET_OSD_STATE();
#endif

	
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
     OsdDisplayClearSelectedCursor(3, GetOsdCurItem(ucStateIndex));
#endif

    switch(ucStateIndex)
    {
        case _MENU_FUN_MUTE:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;
        case _MENU_FUN_GAMUT:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _PCM_OSD_AMOUNT, 0, _ON);
            break;
         case _MENU_FUN_HDR:
             g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _HDR10_AMOUNT, 0, _ON);
             break;
        case _MENU_FUN_OVERSCAN:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;
        case _MENU_FUN_FREESYNC:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;   
#if(_MPRT_SUPPORT == _ON)
		case _MENU_FUN_MPRT:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;
#endif
        case _MENU_FUN_DDCCI:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;
#if(_AI_EYE_PROTECTION == _ON)			
        case _MENU_FUN_AI_EYE_PROTECTION:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;	
#endif
#if(_AI_LIGHT_ADAPTIVATION == _ON)
		case _MENU_FUN_AI_LIGHT_ADAPTIVATION:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
			break;	
#endif
#if(_AI_LOW_POWER == _ON)
		case _MENU_FUN_AI_LOW_POWER:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
			break;	
#endif

        case _MENU_FUN_TEMP:
			
			//DebugMessageOsd("1.GET_OSD_GAME_MODE",GET_OSD_GAME_MODE());
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _CT_COLORTEMP_AMOUNT, 0, _ON);
			
			if((GET_OSD_GAME_MODE() == _GM_FPS1 || 
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
				GET_OSD_MPRT()) && g_usAdjustValue == _CT_SRGB)
				g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _CT_COLORTEMP_AMOUNT, 0, _ON);
				
            break;       
			
		case _MENU_FUN_DP_VERSION:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
			break;

        case _MENU_FUN_ASPECT:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _OSD_ASPECT_RATIO_AMOUNT, 0, _ON);
            //SET_OSD_ASPECT_RATIO_TYPE(g_usAdjustValue);
			//SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
            break;
		case _MENU_FUN_RESPONSE_TIME:
            // SET_OSD_OD_STATUS(_ON);
#if(_OD_WEAK_MID_HIGH)
			g_usAdjustValue = (BYTE)(OsdDisplayDetOverRange(g_usAdjustValue , _OD_AMOUNT-1, _OFF, _ON));
#else
			g_usAdjustValue = (BYTE)(OsdDisplayDetOverRange(g_usAdjustValue , _ON, _OFF, _ON));
#endif	


			break;
         case _MENU_FUN_SLEEP:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 4, _OFF, _ON);
            break;
        case _MENU_FUN_NOTICE:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;         
        case _MENU_FUN_POWER_INDICATOR:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break; 
		 case _MENU_FUN_SEARCH:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
			break;
        case _MENU_FUN_SPACE:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 2, _OFF, _ON);
            break;   
        case _MENU_FUN_RANGE:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 2, _OFF, _ON);
            break;   
        case _MENU_FUN_OSD_BACKGROUND:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;

        case _MENU_FUN_ECO:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ECO_AMOUNT-1, _ECO_STANDARD, _ON);
            break;
		case _MENU_FUN_OSD_PIVOT:
#if(_DEF_PIVOT_OPTION_ON_OFF)
            g_usAdjustValue = g_usAdjustValue == _OSD_ROTATE_DEGREE_0 ? _OFF : _ON;   // ��y?Y��a??
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            g_usAdjustValue = g_usAdjustValue == _ON ? _OSD_ROTATE_DEGREE_270 : _OSD_ROTATE_DEGREE_0;   // Dy��a1|?��?a??��������???a270?��

#else
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 2, 0, _ON);
#endif
			break;	
        case _MENU_FUN_AUTO_POWEROFF:
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
            break;
			
		case _MENU_FUN_LANGUAGE:
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)			
			if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				g_usAdjustValue = GET_OSD_LANGUAGE();
			g_usBackupValue = g_usAdjustValue;
#endif
			g_usAdjustValue = (BYTE)(OsdDisplayDetOverRange(g_usAdjustValue , _LANGUAGE_AMOUNT-1, 0, _ON));
            //SET_OSD_LANGUAGE(g_usAdjustValue);
			//g_usOsdMenu3Page=pageflag;

			break;

#if(_OSD_VIEWMODE_USER_GAME_MODE)
		case _MENU_FUN_VIEWMODE_STANDARD:
			DebugMessageOsd("1.g_usAdjustValue222",g_usAdjustValue);
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _STANDARD_AMOUNT, _OFF, _ON);
            break;

		case _MENU_FUN_VIEWMODE_FPS:
            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _GAME_AMOUNT, _OFF, _ON);
            break;
#endif

			
        default:
            break;
    }

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	 g_usOsdMenu3Page = g_usAdjustValue/_OSD_3RD_ITEM_LENGTH;
     OsdDisplayDrawSelectedCursor(3, GetOsdCurItem(ucStateIndex));
	 
#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)

#if(_OSD_VIEWMODE_USER_GAME_MODE)
	if(ucStateIndex==_MENU_FUN_RESPONSE_TIME)
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);
	else
#endif
		OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);


#else


	
    if(g_usAdjustValue > (_OSD_3RD_ITEM_LENGTH-1) && ucStateIndex == _MENU_FUN_LANGUAGE)
	{
        pageflag = 1;
    }
	else
    {
        pageflag = 0;
    }
	
	//DebugMessageOsd("2.1_MENU_FUN_LANGUAGE",pageflag);
	
	if((GET_KEYMESSAGE()==_RIGHT_KEY_MESSAGE || GET_KEYMESSAGE()==_DOWN_KEY_MESSAGE) && ucStateIndex==_MENU_FUN_LANGUAGE && g_usAdjustValue==0 \
		|| (GET_KEYMESSAGE()==_LEFT_KEY_MESSAGE || GET_KEYMESSAGE()==_UP_KEY_MESSAGE) && ucStateIndex==_MENU_FUN_LANGUAGE && g_usAdjustValue==10)
	{
		ScalerOsdWindowDisable(_MAIN_WIN_3RD_CURSOR);
	}
	else 
	{
	    if(pageflag == 1)
		{
	        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex)-(ucStateIndex == _MENU_FUN_LANGUAGE ? _MAIN_LANGUAE_GAP : 11))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex)- (ucStateIndex == _MENU_FUN_LANGUAGE ? _MAIN_LANGUAE_GAP : 11))),_CP_BLUE, _CP_WHITE, _CP_BG);
	    }
		else
	    {
	        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);
	    }

	}

#endif
	

}

void SpecialFuncAdj(void)
{
    BYTE i,j;
    BYTE ucStateIndex;
	
	DebugMessageOsd("4.SpecialFuncAdj",OSD_SubMenuCur);
	DebugMessageOsd("4.SpecialFuncAdj",OSD_MAIN_MENU_ITEM);

    if(_OSD_SUB_START <= GET_OSD_STATE() && GET_OSD_STATE() <= _OSD_SUB_END)
    {
        switch(OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur])
        {
			
            case _MENU_FUN_INPUT_0:
			case _MENU_FUN_INPUT_1: 
			case _MENU_FUN_INPUT_2: 
            case _MENU_FUN_INPUT_3: 
				
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE && GetOsdValue(_MENU_INPUT)!=OSD_SubMenuCur )
				{
				
					Input_New_State = 10; // ֻҪ���źž��㵱ǰͨ������
					SET_FORCE_POW_SAV_STATUS(_FALSE);
					SET_OSD_STATE(_MENU_NONE);

					ScalerDDomainPatternGenAdjustColor(0, 0, 0);//�ر���Ĺ������������ƻ���һЩ���߰���Ļ���
					ScalerDDomainBackgroundSetColor(0, 0, 0);
		    		ScalerDDomainBackgroundEnable(_ENABLE);

					SysSourceSwitchInputPort(InputSourceConvert(OSD_SubMenuCur));



			 		#if(_MPRT_SUPPORT)	
					if(GET_OSD_MPRT())
					{
						SET_OSD_MPRT(_OFF);
						UserAdjustMPRTFuntion(GET_OSD_MPRT());
					}
					#endif

					if((SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP) )
					{
						SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
				
						if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
						{
							UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
							SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
						}
				
					}
					else //(SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT)
					{
						SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
				
						if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
						   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
						{
							UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
							UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
							SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				
						}
				
					}
				
					SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
				}
                
                break;
#if(!_OSD_VIEWMODE_USER_GAME_MODE)
			case _MENU_FUN_VIEWMODE_STANDARD:
#endif
				
#if(_OSD_GAME_SUPPORT == _ON)	

	#if(!_OSD_VIEWMODE_USER_GAME_MODE)
			case _MENU_FUN_VIEWMODE_FPS:		// liuxh FPS
	#endif
			case _MENU_FUN_VIEWMODE_RTS:
			case _MENU_FUN_VIEWMODE_MOBA:
#else
			//case _VIEWMODE_GAME:
#endif
			case _MENU_FUN_VIEWMODE_MOVIE:
			case _MENU_FUN_VIEWMODE_WEB:
			case _MENU_FUN_VIEWMODE_TEXT:
			case _MENU_FUN_VIEWMODE_MAC:
			case _MENU_FUN_VIEWMODE_MONO:
			case _OSD_HOTKEY_VIEWMODE:
				
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
					UserAdjustViewMode();
					UpdateMaskValue();

				}



				break;
				
#if(ENABLE_LANGUAGE_SELECT_OSD)			
            case _OSD_HOTKEY_LANGUAGE_SELECT:
				
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
                    SET_OSD_LANGUAGE(g_usAdjustValue);
                }
				
                if(GET_OSD_LANGUAGE() > (_OSD_3RD_ITEM_LENGTH-1))
                {
                    pageflag = 1;
                }
				else
				{
                    pageflag = 0;
                }
				break;
#endif

            case _MENU_FUN_RECALL:
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
                    OsdDispOsdReset();
                }
			break;

            case _MENU_FUN_CONTRAST_BRIGHTNESS:
				
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
					//DebugMessageOsd("4.234",GET_OSD_STATE());

                	if(OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST))
						g_usAdjustValue = 1;
					else
                    	g_usAdjustValue = 0;

					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(3, g_usAdjustValue);
                	#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_usAdjustValue)),_CP_BLUE, _CP_WHITE, _CP_BG);
                	#endif
					
                    OsdDisplaySliderAndNumber((g_usAdjustValue==1)?(_MENU_FUN_BACKLIGHT):(_MENU_FUN_CONTRAST), GetOsdValue((g_usAdjustValue==1)?(_MENU_FUN_BACKLIGHT):(_MENU_FUN_CONTRAST)),_SLIDER_PAGE4);
                }
            break;


#if(_OSD_VIEWMODE_USER_GAME_MODE)
			
			case _MENU_FUN_VIEWMODE_STANDARD:
				
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
					DebugMessageOsd("4.234",GET_OSD_STATE());

					g_usAdjustValue=0;
					
					UserAdjustViewMode();
					UpdateMaskValue();
						
                    SET_OSD_STATE(_MENU_FUN_VIEWMODE_STANDARD);

					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_usAdjustValue)),_CP_BLUE, _CP_WHITE, _CP_BG);
					
					OsdDisplaySliderAndNumber(_MENU_FUN_BLK_STABLE, GetOsdValue(_MENU_FUN_BLK_STABLE),_SLIDER_PAGE4);
				}
			break;

			case _MENU_FUN_VIEWMODE_FPS:
				
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
					//DebugMessageOsd("4.234",GET_OSD_STATE());

					g_usAdjustValue=0;
                    SET_OSD_STATE(_MENU_FUN_VIEWMODE_FPS);

					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_usAdjustValue)),_CP_BLUE, _CP_WHITE, _CP_BG);

					for(i=0; i<5; i++)
						OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_STANDARD_SUB, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				}
			break;		// liuxh FPS


#endif



            case _MENU_FUN_SIX_AXIS:
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
                	if(OSD_ITEM_MASK_GET(_MENU_FUN_HUE))
						g_usAdjustValue = 1;
					else
                    	g_usAdjustValue = 0;

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(3, g_usAdjustValue);
#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_usAdjustValue)),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif
					
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(_OSD_3RD_ITEM_LENGTH-1)),_CP_GRAY, _CP_GRAY, _CP_GRAY);

					for(i = 0; i < 6; i++)
                    {                    
						#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                    	#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
                    	#endif
					}
					
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                }/*
                {
                    g_usAdjustValue = 0;
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
                    for(i = 0; i < 6; i++)
                    {
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
                    }
                }*/
                break;

#if(_VGA_SUPPORT == _ON)
			case _MENU_FUN_AUTO_IMAGE_ADJ:
				
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
					if((SysModeGetModeState() == _MODE_STATUS_ACTIVE)&& (SysSourceGetSourceType() == _SOURCE_VGA))
					{
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_CONFIG_MSG);
					}
				}
				break;
			
            case _MENU_FUN_VGA_POSTION:
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    g_usAdjustValue = 0;
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
                    OsdDisplaySliderAndNumber(_MENU_FUN_VGA_HPOSITON, GetOsdValue(_MENU_FUN_VGA_HPOSITON),_SLIDER_PAGE4);
                }
                break;

#endif

#if(_DEF_OSD_GAMING == _ON)
            case _MENU_FUN_GAMING:
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    g_us3rdItemNum = 0;
                    g_usAdjustValue = GetOsdValue(_MENU_FUN_TIMER);
					
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(3, 0);
					#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif

                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdCurItem(_MENU_FUN_TIMER))), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdCurItem(_MENU_FUN_TIMER))),_CP_GRAY, _CP_YELLOW, _CP_BG);
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(_OSD_ITEM_LENGTH - 1)),_CP_GRAY, _CP_GRAY, _CP_GRAY);

					for(i = 0; i < 6; i++)
                    {
						#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_2, _STRING_TIMER_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_2, _STRING_TIMER_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						#endif
                    }
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                }
				break;
#endif

            case _MENU_FUN_TEMP:
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    if(g_usAdjustValue == _CT_USER)
                    {
                    	//PageInit();
                        for(i = 0; i < 3; i++)
                        {                        
							#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                            OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        	#else
                            OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                            OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
							#endif
						}
                    }
                }
                break;
        }
    }
    else
    {
        switch(GET_OSD_STATE())
        {
            case _MENU_FUN_CONTRAST_BRIGHTNESS:
				
				//DebugMessageOsd("4.123",GET_OSD_STATE());
				if(!(OSD_ITEM_MASK_GET(_MENU_FUN_CONTRAST) || OSD_ITEM_MASK_GET(_MENU_FUN_BACKLIGHT)) && GET_KEYMESSAGE() != _MENU_KEY_MESSAGE)
				{
				
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
#endif
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 1, 0, _ON);

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif

				}

				
                if(g_usAdjustValue == 0)
                {
                    ucStateIndex = _MENU_FUN_CONTRAST;
                }
                else if(g_usAdjustValue == 1)
                {
                    ucStateIndex = _MENU_FUN_BACKLIGHT;
                }
                OsdDisplaySliderAndNumber(ucStateIndex, GetOsdValue(ucStateIndex),_SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    SET_OSD_STATE(ucStateIndex);
                    OsdDisplayKeyIndex(_LAYER4_ADJ);
                    OsdDisplaySliderAndNumber(ucStateIndex, GetOsdValue(ucStateIndex),_SLIDER_PAGE4);
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                	#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif
				}
                break;
            case _MENU_FUN_CONTRAST:
                OsdDisplaySliderAndNumber(_MENU_FUN_CONTRAST, GetOsdValue(_MENU_FUN_CONTRAST), _SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_CONTRAST_BRIGHTNESS);
                    OsdDisplayKeyIndex(_LAYER3);
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplaySliderAndNumber(_MENU_FUN_CONTRAST, GetOsdValue(_MENU_FUN_CONTRAST),_SLIDER_PAGE4);
                }
                break;
            case _MENU_FUN_BRIGHTNESS:
                OsdDisplaySliderAndNumber(_MENU_FUN_BRIGHTNESS, GetOsdValue(_MENU_FUN_BRIGHTNESS), _SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_CONTRAST_BRIGHTNESS);
                    OsdDisplayKeyIndex(_LAYER3);
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplaySliderAndNumber(_MENU_FUN_BRIGHTNESS, GetOsdValue(_MENU_FUN_BRIGHTNESS),_SLIDER_PAGE4);
                }
                break;

			case _MENU_FUN_BACKLIGHT:
                OsdDisplaySliderAndNumber(_MENU_FUN_BACKLIGHT, GetOsdValue(_MENU_FUN_BACKLIGHT), _SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_CONTRAST_BRIGHTNESS);
                    OsdDisplayKeyIndex(_LAYER3);
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplaySliderAndNumber(_MENU_FUN_BACKLIGHT, GetOsdValue(_MENU_FUN_BACKLIGHT),_SLIDER_PAGE4);
                }
                break;
				
#if(_VGA_SUPPORT == _ON)
            case _MENU_FUN_VGA_POSTION:
                g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 1, 0, _ON);
                OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
                if(g_usAdjustValue == 0)
                {
                    ucStateIndex = _MENU_FUN_VGA_HPOSITON;
                }
                else if(g_usAdjustValue == 1)
                {
                    ucStateIndex = _MENU_FUN_VGA_VPOSITON;
                }
                OsdDisplaySliderAndNumber(ucStateIndex, GetOsdValue(ucStateIndex),_SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    SET_OSD_STATE(ucStateIndex);
                    OsdDisplayKeyIndex(_LAYER3);
                    OsdDisplaySliderAndNumber(ucStateIndex, GetOsdValue(ucStateIndex),_SLIDER_PAGE4);
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
                }
                break;
				
            case _MENU_FUN_VGA_HPOSITON:
                OsdDisplaySliderAndNumber(_MENU_FUN_VGA_HPOSITON, GetOsdValue(_MENU_FUN_VGA_HPOSITON), _SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_VGA_POSTION);
                    OsdDisplayKeyIndex(_LAYER3);
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplaySliderAndNumber(_MENU_FUN_VGA_HPOSITON, GetOsdValue(_MENU_FUN_VGA_HPOSITON),_SLIDER_PAGE4);
                }
                break;
				
            case _MENU_FUN_VGA_VPOSITON:
                OsdDisplaySliderAndNumber(_MENU_FUN_VGA_VPOSITON, GetOsdValue(_MENU_FUN_VGA_VPOSITON), _SLIDER_PAGE4);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_VGA_POSTION);
                    OsdDisplayKeyIndex(_LAYER3);
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplaySliderAndNumber(_MENU_FUN_VGA_VPOSITON, GetOsdValue(_MENU_FUN_VGA_VPOSITON),_SLIDER_PAGE4);
                }
                break;
#endif
				
            case _MENU_FUN_SIX_AXIS:
				if(!(OSD_ITEM_MASK_GET(_MENU_FUN_HUE) || OSD_ITEM_MASK_GET(_MENU_FUN_SATURATION)) && GET_KEYMESSAGE() != _MENU_KEY_MESSAGE)
				{
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayClearSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
                	#endif
		            g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 1, 0, _ON);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif
				}
				
				if(g_usAdjustValue == 0)
	            {
	                ucStateIndex = _MENU_FUN_HUE;
	            }
	            else if(g_usAdjustValue == 1)
	            {
	                ucStateIndex = _MENU_FUN_SATURATION;
	            }
				
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    g_us4thItemNum = 0;
                    SET_OSD_STATE(ucStateIndex);                
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(4, 0);
                	#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif
				}
                

                break;

				
            case _MENU_FUN_HUE:
				
				{                
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
                	#endif
					g_us4thItemNum = (BYTE)OsdDisplayDetOverRange(g_us4thItemNum, 5, 0, _ON);

					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
                	#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif
				}
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    OsdDisplay5thMenu();                
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + 1), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
               	 	#else
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());
					#endif
					SET_OSD_STATE(_MENU_FUN_HUE_ADJUST);
                    OsdDisplayKeyIndex(_LAYER4_ADJ);
                    OsdDisplaySliderAndNumber(_MENU_FUN_HUE_ADJUST, GetOsdValue(_MENU_FUN_HUE_ADJUST),_SLIDER_PAGE5);
                }
                else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_SIX_AXIS);                
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
                	#endif
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                }
                break;
            case _MENU_FUN_SATURATION:

				#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
                #endif
                g_us4thItemNum = (BYTE)OsdDisplayDetOverRange(g_us4thItemNum, 5, 0, _ON);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
#else
				OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif
                if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    OsdDisplay5thMenu();                
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + 1), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                	#else
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());
					#endif
					SET_OSD_STATE(_MENU_FUN_SATURATION_ADJUST);
                    OsdDisplayKeyIndex(_LAYER4_ADJ);
                    OsdDisplaySliderAndNumber(_MENU_FUN_SATURATION_ADJUST, GetOsdValue(_MENU_FUN_SATURATION_ADJUST),_SLIDER_PAGE5);
                }
                else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_SIX_AXIS);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
#endif
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                }
                break;
            case _MENU_FUN_HUE_ADJUST:
                OsdDisplaySliderAndNumber(_MENU_FUN_HUE_ADJUST, GetOsdValue(_MENU_FUN_HUE_ADJUST),_SLIDER_PAGE5);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_HUE);
                    OsdDisplayKeyIndex(_LAYER3);
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                	#else
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplayBlackWindow(_OFF);
					#endif
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                    for(i = 0; i < 6; i++)
                    {                    
						#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                    	#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
						#endif
					}
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
                	#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif
				}
                break;
            case _MENU_FUN_SATURATION_ADJUST:
                OsdDisplaySliderAndNumber(_MENU_FUN_SATURATION_ADJUST, GetOsdValue(_MENU_FUN_SATURATION_ADJUST),_SLIDER_PAGE5);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_SATURATION);
                    OsdDisplayKeyIndex(_LAYER3);
					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                	#else
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);//UserCommonOsdWindowDisable
                    OsdDisplayBlackWindow(_OFF);
					#endif
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                    for(i = 0; i < 6; i++)
                    {
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
						OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_SIX_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
#endif
					}

					#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
                	#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
					#endif
				}
                break;
            case _MENU_FUN_TEMP:
                if(g_usAdjustValue == _CT_USER)
                {
                	//PageInit();
					//DebugMessageOsd("1.333",_OSD_PAGE_RATE_END);
                    for(i = 0; i < 3; i++)
                    {                    
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
                        OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
#endif
					}
                }
                else
                {
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                }
                break;
            case _MENU_FUN_USER_COLOR:

				#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
                #endif
                g_us4thItemNum = (BYTE)OsdDisplayDetOverRange(g_us4thItemNum, 2, 0, _ON);

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
#else
				OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
                {
                    OsdDisplay5thMenu();
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + 1), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
#else
                    OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START + 1), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, g_us4thItemNum, COLOR(_CP_BLUE, _CP_BG), GET_OSD_LANGUAGE());
#endif
					SET_OSD_STATE(_MENU_FUN_USER_COLOR_ADJUST);
                    OsdDisplayKeyIndex(_LAYER4_ADJ);
                    OsdDisplaySliderAndNumber(_MENU_FUN_USER_COLOR_ADJUST, GetOsdValue(_MENU_FUN_USER_COLOR_ADJUST),_SLIDER_PAGE5);
                }
                else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_TEMP);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, g_us4thItemNum);
#endif
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                }
                break;

			case _MENU_GAME1:
                g_us4thItemNum = (BYTE)OsdDisplayDetOverRange(g_us4thItemNum, 5, 0, _ON);
                break;

            case _MENU_FUN_USER_COLOR_ADJUST:
                OsdDisplaySliderAndNumber(_MENU_FUN_USER_COLOR_ADJUST, GetOsdValue(_MENU_FUN_USER_COLOR_ADJUST),_SLIDER_PAGE5);
                if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    SET_OSD_STATE(_MENU_FUN_USER_COLOR);
                    OsdDisplayKeyIndex(_LAYER3);                
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
#else
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                    OsdDisplayBlackWindow(_OFF);
#endif
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                    for(i = 0; i < 3; i++)
                    {
						//DebugMessageOsd("1.111",1);                    
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
#else
                        OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_USER_COLOR_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						OsdFontPut1BitTable(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START + _COL_1ST_TEXT_SPACE), tiOSD_1BIT_ARROW_RIGHT, COLOR(_CP_WHITE, _CP_BG));
#endif
                    }
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
                    OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
#else
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
#endif
				}
                break;
            case _MENU_FUN_FREESYNC:
                if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
                {
                    #if(_FREESYNC_SUPPORT == _ON)
                        //UserCommonInterfaceFreeSyncSupportSwitch();
                    #endif	

                }
                else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
                {			
                    OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                    SET_OSD_FREE_SYNC_STATUS(g_usBackupValue);
					#if 0//_GSYNC_TEST
					SET_OSD_PRE_GAME_FPS(g_usBackupValue);
					#endif
					
                }
				
				break;
				
            case _MENU_FUN_LANGUAGE:
				
			{
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
				BYTE ucCount = (_LANGUAGE_AMOUNT<=_OSD_3RD_ITEM_LENGTH)?(_LANGUAGE_AMOUNT):((g_usOsdMenu3Page>0)?(_LANGUAGE_AMOUNT-g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH):(_OSD_3RD_ITEM_LENGTH));
#endif
				
                if((GET_KEYMESSAGE() == _MENU_KEY_MESSAGE) && (g_usBackupValue != g_usAdjustValue))
                {					


                    UserAdjustLanguage();

#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					for(i=0;i<ucCount;i++)
					{
						OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH, ((GET_OSD_LANGUAGE()/_OSD_3RD_ITEM_LENGTH == g_usOsdMenu3Page) && (GET_OSD_LANGUAGE() == i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH))?((COLOR(_CP_YELLOW, _CP_BG))):(COLOR(_CP_WHITE, _CP_BG)), _ENGLISH);
					}
					OsdFuncEnableOsd();
#endif
                }
                else if((GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE))
                {
#if(_DEFAULT_OSD_STYLE != _TRG_OSD_STYLE && _DEFAULT_OSD_STYLE != _SUMA_OSD_STYLE)
                    SET_OSD_LANGUAGE(g_usBackupValue);
					if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_UP)
					{
						OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));
					}
					else if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] == _MENU_ARROW_DOWN)
					{
						OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_1ST_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));
					}
#endif
                }
				
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)

				else if(g_usBackupValue/_OSD_3RD_ITEM_LENGTH != g_usOsdMenu3Page)
				{
					OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));

					for(i=0;i<ucCount;i++)
					{
						OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + i * 2 + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH, ((GET_OSD_LANGUAGE()/_OSD_3RD_ITEM_LENGTH == g_usOsdMenu3Page) && (GET_OSD_LANGUAGE() == i+g_usOsdMenu3Page*_OSD_3RD_ITEM_LENGTH))?((COLOR(_CP_YELLOW, _CP_BG))):(COLOR(_CP_WHITE, _CP_BG)), _ENGLISH);
					}

                    OsdDisplayDrawSelectedCursor(3, GetOsdCurItem(_MENU_FUN_LANGUAGE));

				}


#elif(_DEFAULT_OSD_STYLE == _SUMA_OSD_STYLE)
				//else if(GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE || GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)
				{
					//OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);
					//OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(g_usAdjustValue)), _CP_GRAY, _CP_YELLOW, _CP_BG);
				}
#else


                if(GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE)
                {
                    if(g_usAdjustValue == _OSD_3RD_ITEM_LENGTH)
                    {
                        j = 0;
                        OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);

                        for(i = _OSD_3RD_ITEM_LENGTH; i < _LANGUAGE_AMOUNT; i++)
                        {                        	
                            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + j + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
							j++;
                        }
						
						OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));

						if(g_usBackupValue > (_OSD_3RD_ITEM_LENGTH-1) )
						{
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(g_usBackupValue-_MAIN_LANGUAE_GAP)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(g_usBackupValue-_MAIN_LANGUAE_GAP)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
                        else
                        {
                            ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
                        }
						
                    }
                    else if(g_usAdjustValue == 0)
                    {
                        j = 0;
                        OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);

                        for(i = 0; i < _OSD_3RD_ITEM_LENGTH; i++)
                        {                        	
                            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + j ), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
							j++;
                        }
						
						OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));

						// ��ѡ�п� 
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);

						if(g_usBackupValue <= (_OSD_3RD_ITEM_LENGTH-1) )
						{
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(g_usBackupValue)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(g_usBackupValue)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
                        else
                        {
                            ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
                        }

						
                    }
                }
                else if(GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE || GET_KEYMESSAGE() == _UP_KEY_MESSAGE )
                {
                    if(g_usAdjustValue == 10)
                    {
                        j = 0;
                        OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);


                        for(i = 0; i < _OSD_3RD_ITEM_LENGTH; i++)
                        {                            
                            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + j), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
							j++;
                        }
						
						OsdFontPut1BitTable(ROW(_ROW_1ST_TEXT_START + _COL_1ST_TEXT_HIGHT ), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_DOWN, COLOR(_CP_WHITE, _CP_GRAY));
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(ucStateIndex))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(ucStateIndex))),_CP_BLUE, _CP_WHITE, _CP_BG);

						if(g_usBackupValue <= (_OSD_3RD_ITEM_LENGTH-1) )
						{
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(g_usBackupValue)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(g_usBackupValue)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
                        else
                        {
                            ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED); 
                        }
						// ��ѡ�п�

						
                    }
                    else if(g_usAdjustValue == _LANGUAGE_AMOUNT-1)
                    {
                        j = 0;
                        OsdFuncClearOsd(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(_OSD_3RD_ITEM_LENGTH)), _CP_GRAY, _CP_GRAY, _CP_GRAY);

                        for(i = _OSD_3RD_ITEM_LENGTH; i < _LANGUAGE_AMOUNT; i++)
                        {
                            OsdPropPutStringCenter(ROW(_ROW_2ND_TEXT_START + j + 1), COL(_COL_2ND_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_2, _STRING_LANGUAGE_ITEM, i, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
							j++;
                        }

						OsdFontPut1BitTable(ROW(_ROW_2ND_TEXT_START), COL(_COL_2ND_TEXT_START + (_COL_1ST_TEXT_SPACE / 2)), tiOSD_1BIT_ARROW_UP, COLOR(_CP_WHITE, _CP_GRAY));

						if(g_usBackupValue > (_OSD_3RD_ITEM_LENGTH-1) )
						{
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_SELECTED),XSTART(_MAIN_WIN_3RD_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(g_usBackupValue-_MAIN_LANGUAE_GAP)), XEND(_MAIN_WIN_3RD_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(g_usBackupValue-_MAIN_LANGUAE_GAP)), _CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
                        else
                        {
                            ScalerOsdWindowDisable(_MAIN_WIN_3RD_SELECTED);
                        }
						
                    }
                }

#endif
			}
            break;

#if(_OSD_VIEWMODE_USER_GAME_MODE)
			
			case _MENU_FUN_VIEWMODE_STANDARD:
			if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)// 3->4
			{
				
				DebugMessageOsd("1.1234",GET_OSD_OD_STATUS());
				switch(g_usAdjustValue)
				{
					case _STANDARD_BLACK_STABILIZATION:
						SET_OSD_STATE(_MENU_FUN_BLK_STABLE);
						OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()),_SLIDER_PAGE4);
						OsdDisplayKeyIndex(_LAYER4_ADJ);
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
						break;
						
					case _STANDARD_ADCANCED_DCR:
						SET_OSD_STATE(_MENU_FUN_ADV_DCR);
						OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()),_SLIDER_PAGE4);
						OsdDisplayKeyIndex(_LAYER4_ADJ);
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
						break;
						
					case _STANDARD_BLUE_LIGHT_FITER:
						SET_OSD_STATE(_MENU_FUN_BLUELIGHT);
						OsdDisplaySliderAndNumber(GET_OSD_STATE(), GetOsdValue(GET_OSD_STATE()),_SLIDER_PAGE4);
						OsdDisplayKeyIndex(_LAYER4_ADJ);
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);
						break;
						
					case _STANDARD_RESPONSE_TIME:					
						SET_OSD_STATE(_MENU_FUN_RESPONSE_TIME);
						g_usAdjustValue=GET_OSD_OD_STATUS();
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GET_OSD_OD_STATUS())), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GET_OSD_OD_STATUS())),_CP_BLUE, _CP_WHITE, _CP_BG);
						break;
						
					case _STANDARD_RECALL:
						SET_OSD_LOW_BLUE(0);
						SET_OSD_BLACKSTABLE(5);
						SET_OSD_DCR_STATUS(_DCR_Level_0);
						SET_OSD_OD_STATUS(_OD_DEFAULT);
						RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
						UserAdjustGameMode();
						UpdateMaskValue();
						break;
				
					default:
					break;
				}

			}
			else // 3th MOVE
			{
				
				//OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_usAdjustValue)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_usAdjustValue)),_CP_BLUE, _CP_WHITE, _CP_BG);
				OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
				
				switch(g_usAdjustValue)
				{
					case _STANDARD_BLACK_STABILIZATION:
						OsdDisplaySliderAndNumber(_MENU_FUN_BLK_STABLE, GetOsdValue(_MENU_FUN_BLK_STABLE),_SLIDER_PAGE4);
						break;
						
					case _STANDARD_ADCANCED_DCR:
						OsdDisplaySliderAndNumber(_MENU_FUN_ADV_DCR, GetOsdValue(_MENU_FUN_ADV_DCR),_SLIDER_PAGE4);
						break;
						
					case _STANDARD_BLUE_LIGHT_FITER:
						OsdDisplaySliderAndNumber(_MENU_FUN_BLUELIGHT, GetOsdValue(_MENU_FUN_BLUELIGHT),_SLIDER_PAGE4);
						break;
						
					case _STANDARD_RESPONSE_TIME:					
						for(i=0; i<_OD_AMOUNT; i++)
							OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_RESPONSE_TIME_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_3RD_SELECTED_Y_START(GET_OSD_OD_STATUS())), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_3RD_SELECTED_Y_END(GET_OSD_OD_STATUS())),_CP_GRAY, _CP_YELLOW, _CP_BG);
						break;
						
					case _STANDARD_RECALL:
						break;
				
					default:
					break;
				}

			}

				

				
			break;

			case _MENU_FUN_VIEWMODE_FPS:
				
				OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));

				switch(g_usAdjustValue)
				{
					case _GAME_GAMER1:
					if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)// 3->4
					{
						SET_OSD_STATE(_MENU_GAME1);
					}
					case _GAME_GAMER2:
					case _GAME_GAMER3:
						for(i=0; i<6; i++)
							OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i), COL(_COL_3RD_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_3, _STRING_FPS_ITEM_SUB, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(0)),_CP_BLUE, _CP_WHITE, _CP_BG);

						break;
						
					case _GAME_FPS1:
					case _GAME_FPS2:
					case _GAME_RTS:
					case _GAME_MOBA:
						break;

					default:
                    break;
				}
			break;

			case _MENU_FUN_BLK_STABLE:
			case _MENU_FUN_ADV_DCR:
			case _MENU_FUN_BLUELIGHT:
			case _MENU_FUN_RESPONSE_TIME:

			    if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
                {
                    ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
					switch(GET_OSD_STATE())
					{
						case _MENU_FUN_BLK_STABLE:
							g_usAdjustValue = _STANDARD_BLACK_STABILIZATION;
							break;
							
						case _MENU_FUN_ADV_DCR:
							g_usAdjustValue = _STANDARD_ADCANCED_DCR;
							break;
							
						case _MENU_FUN_BLUELIGHT:
							g_usAdjustValue = _STANDARD_BLUE_LIGHT_FITER;
							break;	
							
						case _MENU_FUN_RESPONSE_TIME:
							g_usAdjustValue = _STANDARD_RESPONSE_TIME;
							break;
							
						default:
							break;
					}
                    SET_OSD_STATE(_MENU_FUN_VIEWMODE_STANDARD);
                }


			break;

						
#endif


	
			case _MENU_FUN_MPRT:
#if(_MPRT_SUPPORT == _ON)
				if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE && GET_OSD_MPRT()!=g_usAdjustValue)
				{
		
					SET_OSD_MPRT(g_usAdjustValue);
					PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
					if(GET_OSD_MPRT())
					{

						SET_OSD_ECO_STATUS(_ECO_STANDARD);
					    SET_OSD_DCR_STATUS(_DCR_Level_0);
#if(_DCR_SUPPORT == _ON)						
						UserAdjustDCR();
#endif						
					
						UserAdjustMPRTFuntion(GET_OSD_MPRT()); 

					}
					else
					{
#if(_OD_SUPPORT == _ON)
						ScalerODEnable(_OFF);
						ScalerODAdjustDeltaGain(0x00);
#endif
						UserAdjustMPRTFuntion(GET_OSD_MPRT());
						//ScalerTimerActiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_MPRT);
					}
			

				}
				
#if(_OCC_SUPPORT == _ON)
				 if(GET_OSD_PCM_STATUS() == _PCM_OSD_SRGB)
				 {
					 SET_OSD_PCM_STATUS( _PCM_OSD_NATIVE);
					 OsdFuncColorPcmAdjust();
				 }
#endif

				if(UserAdjustGetOverScanStatus())
				{
					UserAdjustSetOverScanStatus(_OFF);
					UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
					SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
					#if(_OVERSCAN_SAVE_BY_INPUTPORT == _ON)
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
					#else
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
					#endif
				}
				
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_MPRT);
								
				 RTDNVRamSaveOSDData();
				 RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());

#endif
				break;	

#if(_DEF_OSD_GAMING == _ON)
			case _MENU_FUN_GAMING:

				if(GET_KEYMESSAGE() == _UP_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE)
				{
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(3, g_us3rdItemNum);
        			#endif
					g_us3rdItemNum = (BYTE)OsdDisplayDetOverRange(g_us3rdItemNum, 2, 0, _ON);
        			#if (_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(3, g_us3rdItemNum);
        			#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(g_us3rdItemNum)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(g_us3rdItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
        			#endif

					ucStateIndex = _MENU_FUN_TIMER + g_us3rdItemNum;
                    g_usAdjustValue = GetOsdValue(ucStateIndex);
                    g_usOsdMenu4Page = g_usAdjustValue / _OSD_ITEM_LENGTH;
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_SELECTED);
					OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(_OSD_ITEM_LENGTH - 1)),_CP_GRAY, _CP_GRAY, _CP_GRAY);

					if(g_us3rdItemNum == 0)
					{
						for(i = 0; i < 6; i++)
						{
							OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_3, _STRING_TIMER_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						}
					}
					else if(g_us3rdItemNum == 1)
					{
                        OsdDisplayCrosshairItem();
					}
					else if(g_us3rdItemNum == 2)
					{
						for(i = 0; i < 2; i++)
						{
							OsdPropPutStringCenter(ROW(_ROW_3RD_TEXT_START + i * 2 + 1), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE), _PFONT_PAGE_3, _STRING_FPSCOUNTER_ITEM, i, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						}
					}
                    OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdCurItem(ucStateIndex) % _OSD_ITEM_LENGTH)), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdCurItem(ucStateIndex) % _OSD_ITEM_LENGTH)),_CP_GRAY, _CP_YELLOW, _CP_BG);
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
				}
				else if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
				
					ucStateIndex = _MENU_FUN_TIMER + g_us3rdItemNum;
					g_usAdjustValue = GetOsdValue(ucStateIndex);
					g_us4thItemNum = GetOsdCurItem(ucStateIndex);
					SET_OSD_STATE(ucStateIndex);
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(4, g_us4thItemNum);
        			#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(g_us4thItemNum)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(g_us4thItemNum)),_CP_BLUE, _CP_WHITE, _CP_BG);
        			#endif
				}
				break;
			case _MENU_FUN_TIMER:
				if(GET_KEYMESSAGE() == _UP_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE)
				{
        			#if (_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 5, 0, _ON);
        			#if (_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
        			#endif
				}
				else if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
					SetOsdValue(GET_OSD_STATE(), g_usAdjustValue);
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_GRAY, _CP_YELLOW, _CP_BG);
				}
				else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
				{
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
					SET_OSD_STATE(_MENU_FUN_GAMING);
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
				}
				break;
			case _MENU_FUN_CROSSHAIR:
				if(GET_KEYMESSAGE() == _UP_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE)
				{
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
                    g_usBackupValue = g_usAdjustValue;
						#if (_PROJECT_ID == _ID_ZQ_2557E02_SG2701B08_4_FHD200_MKF27F240L_20250515)
							g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 6, 0, _ON);
						#else
	                    	g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 9, 0, _ON);
						#endif
                    g_usOsdMenu4Page = g_usAdjustValue / _OSD_ITEM_LENGTH;
					if(g_usOsdMenu4Page != g_usBackupValue / _OSD_ITEM_LENGTH)
                    {
                        ScalerOsdWindowDisable(_MAIN_WIN_4TH_SELECTED);
                        OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(_OSD_ITEM_LENGTH - 1)),_CP_GRAY, _CP_GRAY, _CP_GRAY);
                        
                        OsdDisplayCrosshairItem();
                        if(GetOsdValue(_MENU_FUN_CROSSHAIR) / _OSD_ITEM_LENGTH == g_usOsdMenu4Page)
                        {
                            OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdValue(_MENU_FUN_CROSSHAIR) % _OSD_ITEM_LENGTH)), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdValue(_MENU_FUN_CROSSHAIR) % _OSD_ITEM_LENGTH)),_CP_GRAY, _CP_YELLOW, _CP_BG);
                        }
                        ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                    }
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
        			#endif
				}
				else if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
                    g_usBackupValue = g_usAdjustValue;
					SetOsdValue(GET_OSD_STATE(), g_usAdjustValue);
					//OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_GRAY, _CP_YELLOW, _CP_BG);
				}
				else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
				{
				    if(g_usOsdMenu4Page != GetOsdValue(_MENU_FUN_CROSSHAIR) / _OSD_ITEM_LENGTH)
                    {
                        g_usOsdMenu4Page = GetOsdValue(_MENU_FUN_CROSSHAIR) / _OSD_ITEM_LENGTH;
                        
                        ScalerOsdWindowDisable(_MAIN_WIN_4TH_SELECTED);
                        OsdFuncClearOsd(ROW(_ROW_3RD_TEXT_START), COL(_COL_3RD_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT));
                        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_CURSOR),XSTART(_MAIN_WIN_4TH_CURSOR_X_START), YSTART(_MAIN_WIN_4TH_CURSOR_Y_START(0)), XEND(_MAIN_WIN_4TH_CURSOR_X_END), YEND(_MAIN_WIN_4TH_CURSOR_Y_END(_OSD_ITEM_LENGTH - 1)),_CP_GRAY, _CP_GRAY, _CP_GRAY);
                        
                        OsdDisplayCrosshairItem();

                        OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdValue(_MENU_FUN_CROSSHAIR) % _OSD_ITEM_LENGTH)), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdValue(_MENU_FUN_CROSSHAIR) % _OSD_ITEM_LENGTH)),_CP_GRAY, _CP_YELLOW, _CP_BG);
                        ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
                    }
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
					SET_OSD_STATE(_MENU_FUN_GAMING);
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
				}
				break;
				
			case _MENU_FUN_FPS_COUNTER:
				if(GET_KEYMESSAGE() == _UP_KEY_MESSAGE || GET_KEYMESSAGE() == _DOWN_KEY_MESSAGE)
				{
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, _ON, _OFF, _ON);
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayDrawSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#else
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_BLUE, _CP_WHITE, _CP_BG);
        			#endif
				}
				else if(GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)
				{
					SetOsdValue(GET_OSD_STATE(), g_usAdjustValue);
					OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_4TH_SELECTED),XSTART(_MAIN_WIN_4TH_SELECTED_X_START), YSTART(_MAIN_WIN_4TH_SELECTED_Y_START(GetOsdCurItem(GET_OSD_STATE()))), XEND(_MAIN_WIN_4TH_SELECTED_X_END), YEND(_MAIN_WIN_4TH_SELECTED_Y_END(GetOsdCurItem(GET_OSD_STATE()))),_CP_GRAY, _CP_YELLOW, _CP_BG);
				}
				else if(GET_KEYMESSAGE() == _EXIT_KEY_MESSAGE)
				{
        			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
					OsdDisplayClearSelectedCursor(4, GetOsdCurItem(GET_OSD_STATE()));
        			#endif
					SET_OSD_STATE(_MENU_FUN_GAMING);
					ScalerOsdWindowDisable(_MAIN_WIN_4TH_CURSOR);
				}
				break;
#endif




        }
    }

	//UpdateMaskValue();

	
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdInterfaceAdjust(void)
{
    BYTE ucStateIndex = OsdStateDefine[OSD_MAIN_MENU_ITEM][OSD_SubMenuCur];

#if(_OSD_VIEWMODE_USER_GAME_MODE)
	if(GetOsdGameModeState(GET_OSD_STATE()))
		ucStateIndex=GET_OSD_STATE();
#endif
	
	DebugMessageOsd("4.OsdInterfaceAdjust",GetOsdShowType(ucStateIndex));
	switch(GetOsdShowType(ucStateIndex))
	{ 
		case _TYPE_SLIDER: 
			#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE )
        	#else
#if(_OSD_VIEWMODE_USER_GAME_MODE)
			if(GetOsdGameModeState(GET_OSD_STATE()))
				;
			else
#endif
            	OsdWindowDrawingHighlight(WINNO(_MAIN_WIN_3RD_CURSOR),XSTART(_MAIN_WIN_3RD_CURSOR_X_START), YSTART(_MAIN_WIN_3RD_CURSOR_Y_START(0)), XEND(_MAIN_WIN_3RD_CURSOR_X_END), YEND(_MAIN_WIN_3RD_CURSOR_Y_END(0)), _CP_BLUE, _CP_WHITE, _CP_BG);
			#endif
			g_usAdjustValue = GetOsdValue(ucStateIndex);
            OsdDisplaySliderAndNumber(ucStateIndex, g_usAdjustValue,_SLIDER_PAGE3);
			break;

        case _TYPE_ITEM:
			OsdFuncAdj();
			break;

		case _TYPE_SUBMENU:
			

            break;

		default:
			break;
	}
	
}

#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserAdjustSetOverScanStatus(bit tempOverScan)
{
#if(_OVERSCAN_SAVE_BY_INPUTPORT == _ON)
	switch(SysSourceGetInputPort())
	{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
		case _A0_INPUT_PORT :
			SET_OSD_A0OVERSCAN_STATUS(tempOverScan);
			break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT :
        	SET_OSD_D0OVERSCAN_STATUS(tempOverScan);
        	break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT :
        	SET_OSD_D1OVERSCAN_STATUS(tempOverScan);
        	break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT :
        	SET_OSD_D2OVERSCAN_STATUS(tempOverScan);
        	break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT :
        	SET_OSD_D3OVERSCAN_STATUS(tempOverScan);
        	break;
#endif
        default:
            break;
	}
#else
		SET_OSD_OVERSCAN_STATUS(tempOverScan);
#endif	
}



//----------------------------------------------------------------------------------------------------
// Overscan Table
//----------------------------------------------------------------------------------------------------
WORD code tOverScanDOSDisableTable[][3] =
{
	// VFreq, HWidth, VHeight,
	{700, 640, 350},	// _MODE_640x350_70HZ
	{560, 640, 400},	// _MODE_640x400_56HZ
	{700, 720, 400},	// _MODE_720x400_70HZ
	{700, 640, 400},	// _MODE_640x400_70HZ
	{600, 640, 400},	// _MODE_640x400_60HZ

	// Don't delete it, and place it at last.
    {  0,    0,    0},
};

//--------------------------------------------------
// Description  : Check Timing For Overscan
// Input Value  :
// Output Value : _TURE => DOS timing
//--------------------------------------------------
bit UserAdjustCheckDOSModeTiming(void)
{
	BYTE ucTemp = 0;

	while(tOverScanDOSDisableTable[ucTemp][0] != 0)
	{
		if((abs(GET_INPUT_TIMING_VFREQ() - tOverScanDOSDisableTable[ucTemp][0]) < 10) && \
			(abs(GET_INPUT_TIMING_HWIDTH() - tOverScanDOSDisableTable[ucTemp][1]) < 2) && \
			(GET_INPUT_TIMING_VHEIGHT() == tOverScanDOSDisableTable[ucTemp][2]))
		{
			return _TRUE;
		}

		ucTemp++;
	}

	return _FALSE;
}

//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
bit UserAdjustGetOverScanStatus(void)
{
	bit tempOverScan = 0;

    if((GET_INPUT_TIMING_VFREQ() < _DEF_OSD_OVER_VFREQ) && (UserAdjustCheckDOSModeTiming() == _FALSE))
    {
    #if(_OVERSCAN_SAVE_BY_INPUTPORT == _ON)
    	switch(SysSourceGetInputPort())
    	{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    		case _A0_INPUT_PORT :
    			tempOverScan = GET_OSD_A0OVERSCAN_STATUS();
    			break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D0_INPUT_PORT :
            	tempOverScan = GET_OSD_D0OVERSCAN_STATUS();
            	break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D1_INPUT_PORT :
            	tempOverScan = GET_OSD_D1OVERSCAN_STATUS();
            	break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            case _D2_INPUT_PORT :
            	tempOverScan = GET_OSD_D2OVERSCAN_STATUS();
            	break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
            case _D3_INPUT_PORT :
            	tempOverScan = GET_OSD_D3OVERSCAN_STATUS();
            	break;
#endif

            default:
            	tempOverScan = 0;
                break;
    	}
      #else
    			tempOverScan = GET_OSD_OVERSCAN_STATUS();
	#endif
    }


	return tempOverScan;
}




void UserAdjustOverScan(BYTE Value)
{
	//if(g_usAdjustValue != UserAdjustGetOverScanStatus())
	{
		KeyActionFlag=_ON;
		
#if(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812)
		ScalerDDomainBackgroundSetColor(0, 0, 0);//�ر���Ĺ������������ƻ���һЩ���߰���Ļ���
		ScalerDDomainBackgroundEnable(_ENABLE);
#endif	
		UserAdjustSetOverScanStatus(Value);
		//g_usBackupValue = UserAdjustGetOverScanStatus();
		
		UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
		
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
		#if(_OVERSCAN_SAVE_BY_INPUTPORT == _ON)
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		#else
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
		#endif
#if(_PROJECT_ID ==_ID_JS_2313E01BR_BOE_MV270FHB_NY0_8BIT_FHD120_VA270A_H_20240812)
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		ScalerDDomainBackgroundEnable(_DISABLE);
#endif	

	}

	
}
#endif

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

void UserAdjustLanguage(void)
{
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)
	BYTE i, ucColor;
#endif

	OsdFuncDisableOsd();
	
	OsdFuncClearOsd(ROW(_ROW_MAIN_TEXT_START0), COL(2), WIDTH(_COL_MAIN_TEXT_SPACE), HEIGHT(_MAIN_TEXT_HIGHT));
	OsdFuncClearOsd(ROW(_ROW_1ST_TEXT_START), COL(_COL_1ST_TEXT_START), WIDTH(_COL_1ST_TEXT_SPACE + 1), HEIGHT(_COL_1ST_TEXT_HIGHT+1));

	SET_OSD_LANGUAGE(g_usAdjustValue);
#if(_DEFAULT_OSD_STYLE == _TRG_OSD_STYLE)		
	OsdDisplayDrawMainString(); 
		
    for(i=0;i<_OSD_ITEM_LENGTH;i++)
    {
        if(OsdStateDefine[OSD_MAIN_MENU_ITEM][i] != _MENU_NULL)
        {
			ucColor = OSD_ITEM_MASK_GET(OsdStateDefine[OSD_MAIN_MENU_ITEM][i]) ? _CP_BLOCK : _CP_WHITE;    
        	OsdPropPutStringCenter(ROW(_ROW_1ST_TEXT_START + i * 2 + 1), COL(_COL_1ST_TEXT_START), _COL_1ST_TEXT_SPACE, _PFONT_PAGE_1, _STRING_ITEM, OsdStateDefine[OSD_MAIN_MENU_ITEM][i]-_OSD_FUN_START, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
          
        }
    }	
	
	OsdDisplayDrawSelectedCursor(2, OSD_SubMenuCur);
	OsdDisplayDrawSelectedCursor(3, GetOsdCurItem(GET_OSD_STATE()));
#else
	OsdDisplayReDrawMainWindow(_ENABLE);
	OsdFuncEnableOsd();
#endif
	
	SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
}




void OsdFunInputAuto(BYTE value)
{
	if(value)
		SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
	else
		SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
	{
		UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
	}
	

}


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

void OsdFuncShowSourceMenuCheck(void)
{
	//DebugMessageOsd("1.SysModeGetModeState",SysModeGetModeState());
	if(SysModeGetModeState() != _MODE_STATUS_ACTIVE && GET_FACTORY_BURNIN()==_OFF  \
		&& ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL) \
		&& GET_KEYMESSAGE() != _EXIT_KEY_MESSAGE)
	{
		ScalerTimerReactiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
		//ScalerDDomainBackgroundSetColor(0, 0, 0);
		//ScalerDDomainBackgroundEnable(_ENABLE);
		//OsdDispHotKeySourceMenu(_OSD_HOTKEY_INPUT); // ����ѡ��
		//UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);

	}
}



//--------------------------------------------------
// Description  : Temporary turn on function when DFM mode is on
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustUltraVivid(void)
{
/*
	BYTE TempSpace = OsdDisplayGetColorSpaceType();

	switch(TempSpace)
	{
		case _SPACE_RGB:
			TempSpace = _COLOR_SPACE_RGB;
			break;
		case _SPACE_YUV:
			TempSpace = _COLOR_SPACE_YPBPR;
			break;
		case _SPACE_AUTO:
			TempSpace = ScalerColorGetColorSpace();
			break;
		default:break;
	}
*/
#if(_ULTRA_VIVID_SUPPORT == _ON)

	#if(_DEF_VIEWMODE_MAC)
	if((GET_OSD_DCR_STATUS() == _OFF) && (GET_OSD_VIEWMODE_TYPE() != _VM_MAC))
	#else
	if((GET_OSD_DCR_STATUS() == _OFF) )
	#endif
    {
        UserCommonAdjustUltraVivid(_FUNCTION_OFF, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
    }
    else
    {
		#if(_FREESYNC_SUPPORT == _ON)
       	if(GET_OSD_FREE_SYNC_STATUS() == _ON)
		{
		   UserCommonAdjustUltraVivid(_FUNCTION_OFF, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
		}
		else
		#endif
		{
	       UserCommonAdjustUltraVivid(_FUNCTION_ON, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
		}
    }
#endif
	    #if(_DEF_CT_SRGB_SUPPIRT == _ON)
	   if((GET_COLOR_TEMP_TYPE() == _CT_SRGB)&&(GET_OSD_DCR_STATUS() != _OFF))
	   	{
			SET_COLOR_TEMP_TYPE(_COLORTEMP_DEFAULT);
			RTDNVRamSaveOSDData();
			RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			UserAdjustContrast(GET_OSD_CONTRAST());
			UserAdjustBacklight(GET_OSD_BACKLIGHT());
	   	}
	#endif

#if(_DCR_SUPPORT == _ON)

	UserAdjustDCR();
#endif
}



void OsdFuncPowerKeyProc(BYTE ucValue)
{
	SET_OSD_PWKEY_LOCK_STATUS(ucValue);

	if(ucValue == _ON)
	{
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)
		SET_AUTO_SLEEP_STATUS(GET_AUTO_SLEEP_STATUS());
#else
		SET_AUTO_SLEEP_STATUS(_SleepPowerSaving_OFF);
#endif
		//g_usPowerSavingCount = 120*_OSD_TIME_AUTO_DOWN;
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_Saving); 
		
		SET_AUTO_POWEROFF_STATUS(_OFF);
		g_usPowerOffCount = 0;
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN);

	}

}



#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)

