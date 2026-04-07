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
// ID Code      : RL6463_Series_ColorSixColorInitialBriCompensate.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6463_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Six Color
//--------------------------------------------------
#define _SIX_COLOR_RIGHTBUFFER_BRI_COMPENSATE                    0
#define _SIX_COLOR_RIGHTWIDTH_BRI_COMPENSATE                     1
#define _SIX_COLOR_CENTER_BRI_COMPENSATE                         2
#define _SIX_COLOR_LEFTWIDTH_BRI_COMPENSATE                      3
#define _SIX_COLOR_LEFTBUFFER_BRI_COMPENSATE                     4


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Code Tables of SixColor
//--------------------------------------------------
SWORD code tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[][5] =
{
    {   0,    0,  722,  722,  722},
    { 722,    0,  604,  604,  604},
    {1326,    0,  722,  722,  722},
    {2048,    0,  722,  722,  722},
    {2770,    0,  604,  604,  604},
    {3374,    0,  722,  722,  722},
};

SWORD code tSIX_COLOR_U_MAX_BRI_COMPENSATE[][5] =
{
    {2047, 2047, 1024, 1024, 1024},
    {1024, 1024, 3072, 3072, 3072},
    {3072, 3072, 2048, 2048, 2048},
    {2048, 2048, 3072, 3072, 3072},
    {3072, 3072, 1024, 1024, 1024},
    {1024, 1024, 2047, 2047, 2047},
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerColorSixColorSetAngleRBBriCompensate(BYTE ucCMSel);
void ScalerColorSixColorInitialBriCompensate(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set range for one CM
// Input Value  : ucCMSel --> Color selected
//                shRBuffer --> Right buffer hue
//                shRWidth --> Right range
//                shAngle --> Master Range
//                shLWidth --> Left Range
//                shLBuffer --> Left Buffer Range
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorSetAngleRBBriCompensate(BYTE ucCMSel)
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_53_PORT_CMN_MST_UMAX_H);

    // Master Umax
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_CENTER_BRI_COMPENSATE]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_CENTER_BRI_COMPENSATE]) & 0xFF));

    // Rightwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTWIDTH_BRI_COMPENSATE]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTWIDTH_BRI_COMPENSATE]) & 0xFF));

    // Leftwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTWIDTH_BRI_COMPENSATE]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTWIDTH_BRI_COMPENSATE]) & 0xFF));

    // Rightbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTBUFFER_BRI_COMPENSATE]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTBUFFER_BRI_COMPENSATE]) & 0xFF));

    // Leftbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTBUFFER_BRI_COMPENSATE]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA, ((tSIX_COLOR_U_MAX_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTBUFFER_BRI_COMPENSATE]) & 0xFF));

    // Right Buffer Hue
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTBUFFER_BRI_COMPENSATE] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTBUFFER_BRI_COMPENSATE] & 0xFF);

    // Right Width Range
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTWIDTH_BRI_COMPENSATE] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_RIGHTWIDTH_BRI_COMPENSATE] & 0xFF);

    // Master Range
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_CENTER_BRI_COMPENSATE] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_CENTER_BRI_COMPENSATE] & 0xFF);

    // Left Width Range
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTWIDTH_BRI_COMPENSATE] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTWIDTH_BRI_COMPENSATE] & 0xFF);

    // Left Buffer Range
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTBUFFER_BRI_COMPENSATE] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA, tSIX_COLOR_DEFAULT_ANGLE_BRI_COMPENSATE[ucCMSel][_SIX_COLOR_LEFTBUFFER_BRI_COMPENSATE] & 0xFF);
}

//--------------------------------------------------
// Description  : Enable ICM function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorInitialBriCompensate(void)
{
    BYTE ucCmIndex = 0;

    // Enable ICM
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), _BIT4 | _BIT3);

    // Enable New ICM mode
    ScalerSetBit(P7_D4_ICM_SEL2, ~(_BIT2 | _BIT1), _BIT2 | _BIT1);

    // Enable ICM function
    ScalerSetByte(P7_D0_ICM_CONTROL, (_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Close ICM Brightness
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x01);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x02);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x03);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x04);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x05);
    ScalerSetByte(P7_D2_ICM_ADDR, _P7_D3_PT_67_PORT_CMN_BRI_RANGE);
    ScalerSetByte(P7_D3_ICM_DATA, 0xBF);
    ScalerSetByte(P7_D3_ICM_DATA, 0x0E);

    for(ucCmIndex = 0; ucCmIndex < 6; ucCmIndex++)
    {
        ScalerColorSixColorSetAngleRBBriCompensate(ucCmIndex);
    }
}
