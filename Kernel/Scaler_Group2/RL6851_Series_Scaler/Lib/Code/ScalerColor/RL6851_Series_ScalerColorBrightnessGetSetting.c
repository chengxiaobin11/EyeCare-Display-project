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
// ID Code      : RL6851_Series_ScalerColorBrightnessGetSetting.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

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
void ScalerColorBrightnessGetSetting(EnumBriConCoefType enumBriConCoefType, WORD *pusData);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Brightness Setting
// Input Value  : EnumBriConCoefTypem, Coefficient
// Output Value : Brightness Setting
//--------------------------------------------------
void ScalerColorBrightnessGetSetting(EnumBriConCoefType enumBriConCoefType, WORD *pusData)
{
    BYTE ucTempH = 0;
#if(_BRI_TYPE == _BRI_GEN_1_10BIT)
    BYTE ucTempL = 0;
#endif

    switch(enumBriConCoefType)
    {
        case _BRIGHTNESS_COEF_A:
            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_00_BRI_RED_COE_SETA_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[0] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_20_BRI_COE_SETA_L, 1, &ucTempL, _NON_AUTOINC);
            pusData[0] = (((WORD)ucTempH) << 2) | ((ucTempL & 0xC0) >> 6);
#endif
            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_01_BRI_GRN_COE_SETA_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[1] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            pusData[1] = (((WORD)ucTempH) << 2) | ((ucTempL & 0x30) >> 4);
#endif

            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_02_BRI_BLU_COE_SETA_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[2] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            pusData[2] = (((WORD)ucTempH) << 2) | ((ucTempL & 0x0C) >> 2);
#endif
            break;

        case _BRIGHTNESS_COEF_B:
            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_06_BRI_RED_COE_SETB_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[0] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_23_BRI_COE_SETB_L, 1, &ucTempL, _NON_AUTOINC);
            pusData[0] = (((WORD)ucTempH) << 2) | ((ucTempL & 0xC0) >> 6);
#endif

            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_07_BRI_GRN_COE_SETB_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[1] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            pusData[1] = (((WORD)ucTempH) << 2) | ((ucTempL & 0x30) >> 4);
#endif

            ScalerGetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_08_BRI_BLU_COE_SETB_H, 1, &ucTempH, _NON_AUTOINC);
#if(_BRI_TYPE == _BRI_GEN_0_8BIT)
            pusData[2] = ucTempH;
#elif(_BRI_TYPE == _BRI_GEN_1_10BIT)
            pusData[2] = (((WORD)ucTempH) << 2) | ((ucTempL & 0x0C) >> 2);
#endif
            break;

        default:
            break;
    }
}

