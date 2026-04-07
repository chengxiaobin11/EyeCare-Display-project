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
// ID Code      : ScalerCommonColorCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macro of Color Space
//--------------------------------------------------
#define GET_COLOR_SPACE()                           (g_pstColorInfoPointer->b3ColorSpace)
#define SET_COLOR_SPACE(x)                          (g_pstColorInfoPointer->b3ColorSpace = (x))
#define CLR_COLOR_SPACE()                           (g_pstColorInfoPointer->b3ColorSpace = 0)
#define GET_COLOR_SPACE_RGB(x)                      (((x) == _COLOR_SPACE_RGB) || ((x) == _COLOR_SPACE_Y_ONLY) || ((x) == _COLOR_SPACE_RAW))

//--------------------------------------------------
// Macro of Colorimetry Data
//--------------------------------------------------
#define GET_COLORIMETRY()                           (g_pstColorInfoPointer->b4Colorimetry)
#define SET_COLORIMETRY(x)                          (g_pstColorInfoPointer->b4Colorimetry = (x))
#define CLR_COLORIMETRY()                           (g_pstColorInfoPointer->b4Colorimetry = 0)

//--------------------------------------------------
// Macro of Extended Colorimetry
//--------------------------------------------------
#define GET_EXT_COLORIMETRY()                       (g_pstColorInfoPointer->b5ExtColorimetry)
#define SET_EXT_COLORIMETRY(x)                      (g_pstColorInfoPointer->b5ExtColorimetry = (x))
#define CLR_EXT_COLORIMETRY()                       (g_pstColorInfoPointer->b5ExtColorimetry = 0)

//--------------------------------------------------
// Macro of Color Depth
//--------------------------------------------------
#define GET_COLOR_DEPTH()                           (g_pstColorInfoPointer->b5ColorDepth)
#define SET_COLOR_DEPTH(x)                          (g_pstColorInfoPointer->b5ColorDepth = (x))
#define CLR_COLOR_DEPTH()                           (g_pstColorInfoPointer->b5ColorDepth = 0)

//--------------------------------------------------
// Macro of RGB Quantization Range
//--------------------------------------------------
#define GET_COLOR_RGB_QUANTIZATION_RANGE()          (g_pstColorInfoPointer->b2RgbQuantizationRange)
#define SET_COLOR_RGB_QUANTIZATION_RANGE(x)         (g_pstColorInfoPointer->b2RgbQuantizationRange = (x))

//--------------------------------------------------
// Macro of RGB Limit Range User
//--------------------------------------------------
#define GET_COLOR_RGB_LIMIT_RANGE_USER()            (g_pstColorInfoPointer->b1RgbLimitRangeUser)
#define SET_COLOR_RGB_LIMIT_RANGE_USER(x)           (g_pstColorInfoPointer->b1RgbLimitRangeUser = (x))

//--------------------------------------------------
// Macro of YCC Quantization Range
//--------------------------------------------------
#define GET_COLOR_YCC_QUANTIZATION_RANGE()          (g_pstColorInfoPointer->b2YccQuantizationRange)
#define SET_COLOR_YCC_QUANTIZATION_RANGE(x)         (g_pstColorInfoPointer->b2YccQuantizationRange = (x))

//--------------------------------------------------
// Macro of YCC Full Range User
//--------------------------------------------------
#define GET_COLOR_YCC_FULL_RANGE_USER()             (g_pstColorInfoPointer->b1YccFullRangeUser)
#define SET_COLOR_YCC_FULL_RANGE_USER(x)            (g_pstColorInfoPointer->b1YccFullRangeUser = (x))

#if(_FW_COLOR_254_LIMIT_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Macro of RGB 254 Limit Range User
//--------------------------------------------------
#define GET_COLOR_RGB_254LIMIT_RANGE_USER()         (g_pstColorInfoPointer->b1Rgb254LimitRangeUser)
#define SET_COLOR_RGB_254LIMIT_RANGE_USER(x)        (g_pstColorInfoPointer->b1Rgb254LimitRangeUser = (x))

//--------------------------------------------------
// Macro of YCC 254 Limit Range User
//--------------------------------------------------
#define GET_COLOR_YCC_254LIMIT_RANGE_USER()         (g_pstColorInfoPointer->b1Ycc254LimitRangeUser)
#define SET_COLOR_YCC_254LIMIT_RANGE_USER(x)        (g_pstColorInfoPointer->b1Ycc254LimitRangeUser = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b3ColorSpace : 3;
    BYTE b5ColorDepth : 5;
    BYTE b5ExtColorimetry : 5;
    BYTE b2RgbQuantizationRange : 2;
    BYTE b1RgbLimitRangeUser : 1;
    BYTE b2YccQuantizationRange : 2;
    BYTE b1YccFullRangeUser : 1;
    BYTE b4Colorimetry : 4;
#if(_FW_COLOR_254_LIMIT_RANGE_SUPPORT == _ON)
    BYTE b1Rgb254LimitRangeUser : 1;
    BYTE b1Ycc254LimitRangeUser : 1;
#endif
} StructColorInfo;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructColorInfo g_pstColorInfo[];
extern StructColorInfo *g_pstColorInfoPointer;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

