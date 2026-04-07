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
// ID Code      : RL6410_Series_ColorColorConversion.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

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
void ScalerColorSpaceConvert(EnumColorSpace enumColorSpace, EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Color Space Conversion function On/Off
// Input Value  : Input Color Space, EnumDBApply
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvert(EnumColorSpace enumColorSpace, EnumDBApply enumDBApply)
{
    //////////////////////////////
    // I-Domain Color Conversion//
    //////////////////////////////
    if(GET_COLOR_SPACE_RGB(enumColorSpace) == _TRUE)
    {
        if(GET_INTERLACED_MODE() == _TRUE)
        {
            // Enable I-Domain RGB2YUV
            ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~(_BIT4 | _BIT0), (_BIT4 | _BIT0));
        }
        else
        {
            // Disable I-Domain RGB2YUV
            ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~(_BIT4 | _BIT0), 0x00);
        }
    }
    else
    {
        // Disable I-Domain RGB2YUV
        ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~(_BIT4 | _BIT0), 0x00);
    }

    //////////////////////////////
    // D-Domain Color Conversion//
    //////////////////////////////

    // Load D-Domain YUV2RGB Table
    ScalerColorSpaceLoadYuv2RgbTable(enumColorSpace, _OFF);

    if(GET_COLOR_SPACE_RGB(enumColorSpace) == _TRUE)
    {
        if(GET_INTERLACED_MODE() == _TRUE)
        {
            // Enable D-Domain YUV2RGB
            ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT5 | _BIT4 | _BIT0), _BIT0);
        }
        else
        {
            if(GET_COLOR_RGB_LIMIT_RANGE_USER() == _TRUE)
            {
                // Enable D-Domain YUV2RGB & Identity_Matrix
                ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT5 | _BIT4 | _BIT0), (_BIT4 | _BIT0));
            }
            else
            {
                // Disable D-Domain YUV2RGB Identity_Matrix
                ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT5 | _BIT4 | _BIT0), 0x00);
            }
        }
    }
    else
    {
        ScalerSetBit(P14_A1_SR_YCC2RGB_CTRL, ~(_BIT5 | _BIT4 | _BIT0), _BIT0);
    }

    if(GET_INTERLACED_MODE() == _TRUE)
    {
        ScalerGlobalIDomainDBApply(enumDBApply);
        ScalerGlobalDDomainDBApply(enumDBApply);
    }
    else
    {
        if(enumDBApply == _DB_APPLY_NO_POLLING)
        {
            enumDBApply = _DB_APPLY_POLLING;
        }

        ScalerGlobalIDDomainDBApply(enumDBApply);
    }
}

