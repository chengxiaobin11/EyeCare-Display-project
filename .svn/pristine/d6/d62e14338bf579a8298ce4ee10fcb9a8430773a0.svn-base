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
// ID Code      : RL6851_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __RL6851_SERIES_PINSHARE__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GPIO_OPEN_DRAIN                        2

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
void ScalerPinshareInitial(void);
void ScalerPinsharePowerOnReset(void);

#if(_HW_IIC_SUPPORT == _ON)
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum);
#endif

void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType);
void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigType enumConfigType);
void ScalerPinshareAdjustFlashDrive(EnumConfigSPIPinType enumConfigFlashDrive, EnumFlashDriveConfigType enumFlashDriveConfig);
void ScalerPinshareAdjustFlashSlewRate(void);
void ScalerPinshareCBUSPinInitialReset(void);

#if(_D0_DP_EXIST == _ON)
void ScalerPinshareRx0TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation);
#endif

#if(_AUDIO_SUPPORT == _ON)
void ScalerPinshareAudioPinGPIOCheck(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Pinshare Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareInitial(void)
{
#if(_PANEL_STYLE == _PANEL_LVDS)
    // LVDS Pad Power On
    ScalerDisplayLvdsPadPower(_ON);
#elif(_PANEL_STYLE == _PANEL_DPTX)
    // LVDS Pad Power On for eDP
    ScalerDisplayUseLvdsPadPower(_ON);
#endif

    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON2, _PIN_21);
    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON2, _PIN_22);
    ScalerSetByte(P10_02_PIN_SHARE_CTRL02__ON2, _PIN_34);
    ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35);
    ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36);
    ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37);
    ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38);
    ScalerSetByte(P10_07_PIN_SHARE_CTRL07__ON2, _PIN_39);
    ScalerSetByte(P10_08_PIN_SHARE_CTRL08__ON2, _PIN_42);
    ScalerSetByte(P10_09_PIN_SHARE_CTRL09__ON2, _PIN_43);
    ScalerSetByte(P10_0A_PIN_SHARE_CTRL0A__ON2, _PIN_44);
    ScalerSetByte(P10_0B_PIN_SHARE_CTRL0B__ON2, _PIN_45);
    ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON2, _PIN_46);
    ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47);
    ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48);
    ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49);
    ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50);
    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52);
    ScalerSetByte(P10_12_PIN_SHARE_CTRL12__ON2, _PIN_53);
    ScalerSetByte(P10_13_PIN_SHARE_CTRL13__ON2, _PIN_55);
    ScalerSetByte(P10_14_PIN_SHARE_CTRL14__ON2, _PIN_56);
    ScalerSetByte(P10_15_PIN_SHARE_CTRL15__ON2, _PIN_57);
    ScalerSetByte(P10_16_PIN_SHARE_CTRL16__ON2, _PIN_58);
    ScalerSetByte(P10_17_PIN_SHARE_CTRL17__ON2, _PIN_59);
    ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60);
    ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61);
    ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON2, _PIN_63);
    ScalerSetByte(P10_1B_PIN_SHARE_CTRL1B__ON2, _PIN_64);
    ScalerSetByte(P10_1C_PIN_SHARE_CTRL1C__ON2, _PIN_65);
    ScalerSetByte(P10_1D_PIN_SHARE_CTRL1D__ON2, _PIN_66);
    ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON3, _PIN_79);
    ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON3, _PIN_80);
    ScalerSetByte(P10_20_PIN_SHARE_CTRL20__ON3, _PIN_81);
    ScalerSetByte(P10_21_PIN_SHARE_CTRL21__ON3, _PIN_82);
    ScalerSetByte(P10_22_PIN_SHARE_CTRL22__ON3, _PIN_83);
    ScalerSetByte(P10_23_PIN_SHARE_CTRL23__ON3, _PIN_84);
    ScalerSetByte(P10_24_PIN_SHARE_CTRL24__ON3, _PIN_85);
    ScalerSetByte(P10_25_PIN_SHARE_CTRL25__ON3, _PIN_86);
    ScalerSetByte(P10_26_PIN_SHARE_CTRL26__ON3, _PIN_87);
    ScalerSetByte(P10_27_PIN_SHARE_CTRL27__ON3, _PIN_88);
    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__ON1, _PIN_90);
    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__ON1, _PIN_91);
    ScalerSetByte(P10_2A_PIN_SHARE_CTRL2A__ON1, _PIN_92);
    ScalerSetByte(P10_2B_PIN_SHARE_CTRL2B__ON1, _PIN_93);
    ScalerSetByte(P10_2C_PIN_SHARE_CTRL2C__ON1, _PIN_94);
    ScalerSetByte(P10_2D_PIN_SHARE_CTRL2D__ON1, _PIN_96);
    ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97);
    ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98);
    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99);
    ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100);
    ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101);
    ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_102);
    ScalerSetByte(P10_34_PIN_SHARE_CTRL34__ON1, _PIN_108);
    ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110);
    ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111);
    ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112);
    ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113);
    ScalerSetByte(P10_39_PIN_SHARE_CTRL39__ON1, _PIN_114);
    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115);
    ScalerSetByte(P10_3B_PIN_SHARE_CTRL3B__ON1, _PIN_120);
    ScalerSetByte(P10_3C_PIN_SHARE_CTRL3C__ON1, _PIN_121);
    ScalerSetByte(P10_3D_PIN_SHARE_CTRL3D__ON1, _PIN_122);
    ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_123);
    ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_124);

    // Set Pin configure to AC ON
    ScalerPinshareConfig(_POWER_STATUS_AC_ON);

    // Pin Config adjust sample (this is a ineffective configuration example aviod uncall worning)
    ScalerPinshareAdjustConfig(_CONFIG_PIN_START, _GPI);
    ScalerPinshareGpioDdcPinSwitch(0xFF);

#if(_AUDIO_SUPPORT == _ON)
    // Audio Pinshare check
    ScalerPinshareAudioPinGPIOCheck();
#endif
}

//--------------------------------------------------
// Description  : Pinshare Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinsharePowerOnReset(void)
{
    ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON3, _PIN_79);
    ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON3, _PIN_80);
    ScalerSetByte(P10_20_PIN_SHARE_CTRL20__ON3, _PIN_81);
    ScalerSetByte(P10_21_PIN_SHARE_CTRL21__ON3, _PIN_82);
    ScalerSetByte(P10_22_PIN_SHARE_CTRL22__ON3, _PIN_83);
    ScalerSetByte(P10_23_PIN_SHARE_CTRL23__ON3, _PIN_84);
    ScalerSetByte(P10_24_PIN_SHARE_CTRL24__ON3, _PIN_85);
    ScalerSetByte(P10_25_PIN_SHARE_CTRL25__ON3, _PIN_86);
    ScalerSetByte(P10_26_PIN_SHARE_CTRL26__ON3, _PIN_87);
    ScalerSetByte(P10_27_PIN_SHARE_CTRL27__ON3, _PIN_88);
}

#if(_HW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set HW IIC Pin Out
// Input Value  : ucHwIICPinNum --> Pin35_36/37_38/60_61/47_48/47_48/97_98
// Output Value : None
//--------------------------------------------------
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum)
{
    // Set the selected HwIICPinNum to IIC output
    // Set the others as GPI
    switch(ucHwIICPinNum)
    {
        case _HW_IIC_PIN_35_36_0_3:

            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_IICSCL_0_3);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_IICSDA_0_3);
            }
            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
            }
            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
            }
            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
            }
            break;

        case _HW_IIC_PIN_37_38_0_0:

            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_IICSCL_0_0);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_IICSDA_0_0);
            }
            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
            }
            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
            }
            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
            }
            break;

        case _HW_IIC_PIN_60_61_0_1:

            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_IICSCL_0_1);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_IICSDA_0_1);
            }
            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
            }
            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
            }
            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
            }
            break;

        case _HW_IIC_PIN_47_48_AUX:

            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_IICSCL_AUX);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_IICSDA_AUX);
            }
            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
            }
            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
            }
            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
            }
            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
            }
            break;

        case _HW_IIC_PIN_47_48:

            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_EEIICSCL);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_EEIICSDA);
            }
            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
            }
            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
            }
            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
            }
            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
            }
            break;

        case _HW_IIC_PIN_97_98_0_2:

            if((_PIN_97 == _PIN_97_IICSCL_0_2) && (_PIN_98 == _PIN_98_IICSDA_0_2))
            {
                ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_IICSCL_0_2);
                ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_IICSDA_0_2);
            }
            if((_PIN_35 == _PIN_35_IICSCL_0_3) && (_PIN_36 == _PIN_36_IICSDA_0_3))
            {
                ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
            }
            if((_PIN_37 == _PIN_37_IICSCL_0_0) && (_PIN_38 == _PIN_38_IICSDA_0_0))
            {
                ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
            }
            if((_PIN_60 == _PIN_60_IICSCL_0_1) && (_PIN_61 == _PIN_61_IICSDA_0_1))
            {
                ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
            }
            if((_PIN_47 == _PIN_47_IICSCL_AUX) && (_PIN_48 == _PIN_48_IICSDA_AUX))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            if((_PIN_47 == _PIN_47_EEIICSCL) && (_PIN_48 == _PIN_48_EEIICSDA))
            {
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
            }
            break;

        default:
            break;
    }
}
#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Switch DDC pin to GPIO or viceversa
// Input Value  : ucPinType --> Pin49_49/110_101/112_111
// Output Value : None
//--------------------------------------------------
void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType)
{
    switch(ucPinType)
    {
        case _DDC_VGA_SWITCH_GPIO:
            if(GET_A0_DDC_PINSHARE_PIN() == _VGA_DDC2)
            {
                ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100_GPO_OD);
                ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101_GPO_OD);
            }
            else
            {
                ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_GPO_OD);
                ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_GPO_OD);
            }
            break;

        case _DDC_VGA_SWITCH_DDC:
            if(GET_A0_DDC_PINSHARE_PIN() == _VGA_DDC2)
            {
                ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100_DDCSCL_VGA_0_1);
                ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101_DDCSDA_VGA_0_1);
            }
            else
            {
                ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_DDCSCL_VGA_0_0);
                ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_DDCSDA_VGA_0_0);
            }
            break;

        case _DDC_ISP_SWITCH_GPIO:
            ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_GPO_OD);
            ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_GPO_OD);
            break;

        case _DDC_ISP_SWITCH_DDC:
            ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_DDCSCL_ISP);
            ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_DDCSDA_ISP);
            break;

        case _DDC0_SWITCH_GPIO:
            ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPO_OD);
            ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPO_OD);
            break;

        case _DDC0_SWITCH_DDC:
            ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_DDCSCL_0);
            ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_DDCSDA_0);
            break;

        case _DDC0_SWITCH_GPI:
            ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPI);
            ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPI);
            break;

        case _DDC1_SWITCH_GPIO:
            ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPO_OD);
            ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPO_OD);
            break;

        case _DDC1_SWITCH_DDC:
            ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_DDCSCL_1);
            ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_DDCSDA_1);
            break;

        case _DDC1_SWITCH_GPI:
            ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPI);
            ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPI);
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Adjust pin share config
// Input Value  : enumConfigPin  --> Pin num
//                enumConfigType --> Pin type(GPIO/PWM..Etc.)
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigType enumConfigType)
{
    switch(enumConfigPin)
    {
        case _CONFIG_PIN_21:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON2, _PIN_21_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON2, _PIN_21_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON2, _PIN_21_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_22:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON2, _PIN_22_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON2, _PIN_22_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON2, _PIN_22_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_34:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_02_PIN_SHARE_CTRL02__ON2, _PIN_34_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_02_PIN_SHARE_CTRL02__ON2, _PIN_34_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_02_PIN_SHARE_CTRL02__ON2, _PIN_34_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_35:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON2, _PIN_35_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_36:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON2, _PIN_36_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_37:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON2, _PIN_37_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_38:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON2, _PIN_38_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_39:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_07_PIN_SHARE_CTRL07__ON2, _PIN_39_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_07_PIN_SHARE_CTRL07__ON2, _PIN_39_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_07_PIN_SHARE_CTRL07__ON2, _PIN_39_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_42:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_08_PIN_SHARE_CTRL08__ON2, _PIN_42_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_08_PIN_SHARE_CTRL08__ON2, _PIN_42_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_08_PIN_SHARE_CTRL08__ON2, _PIN_42_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_43:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_09_PIN_SHARE_CTRL09__ON2, _PIN_43_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_09_PIN_SHARE_CTRL09__ON2, _PIN_43_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_09_PIN_SHARE_CTRL09__ON2, _PIN_43_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_44:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0A_PIN_SHARE_CTRL0A__ON2, _PIN_44_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0A_PIN_SHARE_CTRL0A__ON2, _PIN_44_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0A_PIN_SHARE_CTRL0A__ON2, _PIN_44_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_45:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0B_PIN_SHARE_CTRL0B__ON2, _PIN_45_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0B_PIN_SHARE_CTRL0B__ON2, _PIN_45_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0B_PIN_SHARE_CTRL0B__ON2, _PIN_45_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_46:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON2, _PIN_46_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON2, _PIN_46_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON2, _PIN_46_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_47:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON2, _PIN_47_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_48:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON2, _PIN_48_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_49:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON2, _PIN_49_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_50:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON2, _PIN_50_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_52:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52_GPO_OD);
                    break;

                case _PWM0_PP:
                    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52_PWM0_PP);
                    break;

                case _PWM0_OD:
                    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON2, _PIN_52_PWM0_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_53:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_12_PIN_SHARE_CTRL12__ON2, _PIN_53_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_12_PIN_SHARE_CTRL12__ON2, _PIN_53_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_12_PIN_SHARE_CTRL12__ON2, _PIN_53_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_55:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_13_PIN_SHARE_CTRL13__ON2, _PIN_55_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_13_PIN_SHARE_CTRL13__ON2, _PIN_55_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_13_PIN_SHARE_CTRL13__ON2, _PIN_55_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_56:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_14_PIN_SHARE_CTRL14__ON2, _PIN_56_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_14_PIN_SHARE_CTRL14__ON2, _PIN_56_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_14_PIN_SHARE_CTRL14__ON2, _PIN_56_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_57:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_15_PIN_SHARE_CTRL15__ON2, _PIN_57_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_15_PIN_SHARE_CTRL15__ON2, _PIN_57_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_15_PIN_SHARE_CTRL15__ON2, _PIN_57_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_58:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_16_PIN_SHARE_CTRL16__ON2, _PIN_58_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_16_PIN_SHARE_CTRL16__ON2, _PIN_58_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_16_PIN_SHARE_CTRL16__ON2, _PIN_58_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_59:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_17_PIN_SHARE_CTRL17__ON2, _PIN_59_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_17_PIN_SHARE_CTRL17__ON2, _PIN_59_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_17_PIN_SHARE_CTRL17__ON2, _PIN_59_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_60:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON2, _PIN_60_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_61:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON2, _PIN_61_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_63:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON2, _PIN_63_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON2, _PIN_63_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON2, _PIN_63_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_64:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1B_PIN_SHARE_CTRL1B__ON2, _PIN_64_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_1B_PIN_SHARE_CTRL1B__ON2, _PIN_64_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_1B_PIN_SHARE_CTRL1B__ON2, _PIN_64_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_65:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1C_PIN_SHARE_CTRL1C__ON2, _PIN_65_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_1C_PIN_SHARE_CTRL1C__ON2, _PIN_65_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_1C_PIN_SHARE_CTRL1C__ON2, _PIN_65_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_66:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1D_PIN_SHARE_CTRL1D__ON2, _PIN_66_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_1D_PIN_SHARE_CTRL1D__ON2, _PIN_66_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_1D_PIN_SHARE_CTRL1D__ON2, _PIN_66_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_79:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON3, _PIN_79_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_80:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON3, _PIN_80_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_81:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_20_PIN_SHARE_CTRL20__ON3, _PIN_81_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_82:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_21_PIN_SHARE_CTRL21__ON3, _PIN_82_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_83:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_22_PIN_SHARE_CTRL22__ON3, _PIN_83_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_84:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_23_PIN_SHARE_CTRL23__ON3, _PIN_84_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_85:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_24_PIN_SHARE_CTRL24__ON3, _PIN_85_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_86:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_25_PIN_SHARE_CTRL25__ON3, _PIN_86_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_87:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_26_PIN_SHARE_CTRL26__ON3, _PIN_87_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_88:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_27_PIN_SHARE_CTRL27__ON3, _PIN_88_GPI);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_90:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__ON1, _PIN_90_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__ON1, _PIN_90_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__ON1, _PIN_90_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_91:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__ON1, _PIN_91_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__ON1, _PIN_91_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__ON1, _PIN_91_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_92:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2A_PIN_SHARE_CTRL2A__ON1, _PIN_92_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2A_PIN_SHARE_CTRL2A__ON1, _PIN_92_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2A_PIN_SHARE_CTRL2A__ON1, _PIN_92_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_93:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2B_PIN_SHARE_CTRL2B__ON1, _PIN_93_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2B_PIN_SHARE_CTRL2B__ON1, _PIN_93_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2B_PIN_SHARE_CTRL2B__ON1, _PIN_93_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_94:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2C_PIN_SHARE_CTRL2C__ON1, _PIN_94_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2C_PIN_SHARE_CTRL2C__ON1, _PIN_94_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2C_PIN_SHARE_CTRL2C__ON1, _PIN_94_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_96:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2D_PIN_SHARE_CTRL2D__ON1, _PIN_96_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2D_PIN_SHARE_CTRL2D__ON1, _PIN_96_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2D_PIN_SHARE_CTRL2D__ON1, _PIN_96_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_97:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, _PIN_97_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_98:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, _PIN_98_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_99:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_GPO_OD);
                    break;

                case _PWM2_PP:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_PWM2_PP);
                    break;

                case _PWM2_OD:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_PWM2_OD);
                    break;

                case _PWM3_PP:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_PWM3_PP);
                    break;

                case _PWM3_OD:
                    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, _PIN_99_PWM3_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_100:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, _PIN_100_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_101:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_101_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_102:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_102_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_102_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_102_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_108:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_34_PIN_SHARE_CTRL34__ON1, _PIN_108_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_34_PIN_SHARE_CTRL34__ON1, _PIN_108_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_34_PIN_SHARE_CTRL34__ON1, _PIN_108_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_110:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_111:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_112:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_113:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_114:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_39_PIN_SHARE_CTRL39__ON1, _PIN_114_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_39_PIN_SHARE_CTRL39__ON1, _PIN_114_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_39_PIN_SHARE_CTRL39__ON1, _PIN_114_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_115:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115_GPO_OD);
                    break;

                case _PWM1_PP:
                    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115_PWM1_PP);
                    break;

                case _PWM1_OD:
                    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, _PIN_115_PWM1_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_120:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3B_PIN_SHARE_CTRL3B__ON1, _PIN_120_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3B_PIN_SHARE_CTRL3B__ON1, _PIN_120_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3B_PIN_SHARE_CTRL3B__ON1, _PIN_120_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_121:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3C_PIN_SHARE_CTRL3C__ON1, _PIN_121_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3C_PIN_SHARE_CTRL3C__ON1, _PIN_121_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3C_PIN_SHARE_CTRL3C__ON1, _PIN_121_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_122:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3D_PIN_SHARE_CTRL3D__ON1, _PIN_122_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3D_PIN_SHARE_CTRL3D__ON1, _PIN_122_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3D_PIN_SHARE_CTRL3D__ON1, _PIN_122_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_123:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_123_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_123_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_123_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_124:

            switch(enumConfigType)
            {
                case _GPI:
                    ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_124_GPI);
                    break;

                case _GPO_PP:
                    ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_124_GPO_PP);
                    break;

                case _GPO_OD:
                    ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_124_GPO_OD);
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Adjust Flash SPI Drive config
// Input Value  : enumConfigPin  --> Pin num
//                enumConfigFlashDrive --> Drine Current
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAdjustFlashDrive(EnumConfigSPIPinType enumConfigFlashDrive, EnumFlashDriveConfigType enumFlashDriveConfig)
{
    switch(enumConfigFlashDrive)
    {
        case _CONFIG_PIN_SPI_CLK:

            switch(enumFlashDriveConfig)
            {
                case _SPI_DRIVE_3_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _SPI_DRIVE_3_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT4 | _BIT3);
                    break;

                case _SPI_DRIVE_4_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
                    break;

                case _SPI_DRIVE_4_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT3);
                    break;

                case _SPI_DRIVE_5_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
                    break;

                case _SPI_DRIVE_5_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_SPI_SI_SO_CEB:

            switch(enumFlashDriveConfig)
            {
                case _SPI_DRIVE_3_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _SPI_DRIVE_3_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1 | _BIT0);
                    break;

                case _SPI_DRIVE_4_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _SPI_DRIVE_4_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT0);
                    break;

                case _SPI_DRIVE_5_0MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
                    break;

                case _SPI_DRIVE_5_5MA:
                    ScalerSetBit(P10_E9_PIN_DRIVING_CTRL01__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Adjust Flash SPI Slew-Rate Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAdjustFlashSlewRate(void)
{
    // Setting Flash SPI Clk Pin Slew-Rate Control
    ScalerSetBit(P10_AF_PIN_SLEW_RATE_CTRL00__ON1, ~(_BIT7), (_FLASH_CLK_SLEW_RATE_CONTROL & 0x01) << 7);

    // Setting Flash SPI SI/SO/CEB Pin Slew-Rate Control
    ScalerSetBit(P10_AF_PIN_SLEW_RATE_CTRL00__ON1, ~(_BIT6), (_FLASH_SI_SO_CEB_SLEW_RATE_CONTROL & 0x01) << 6);
}

//--------------------------------------------------
// Description  : Reset MHL setting when MHL nonsupport
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareCBUSPinInitialReset(void)
{
}

#if(_D0_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Aux Pin-Share Setting
// Input Value  : TypeC Pin Assigment, TypeC Orientation
// Output Value : None
//--------------------------------------------------
void ScalerPinshareRx0TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation)
{
    enumTypeCPinCfgType = enumTypeCPinCfgType;
    enumTypeCOrientation = enumTypeCOrientation;

#if(_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 110 Pinshare Config : GPI Mode
        ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPI);

        // Pin 111 Pinshare Config : GPI Mode
        ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPI);
    }
    else
    {
#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
            // Pin 110 Pinshare Config : AUX_P Mode
            ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_DPRX_AUX_P_0);

            // Pin 111 Pinshare Config : AUX_N Mode
            ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_DPRX_AUX_N_0);
        }
#else
        // Pin 110 Pinshare Config : AUX_P Mode
        ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_DPRX_AUX_P_0);

        // Pin 111 Pinshare Config : AUX_N Mode
        ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_DPRX_AUX_N_0);
#endif
    }

#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 112 Pinshare Config : GPI Mode
        ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPI);

        // Pin 113 Pinshare Config : GPI Mode
        ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPI);
    }
    else
    {
#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
            // Pin 112 Pinshare Config : AUX_P Mode
            ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_DPRX_AUX_P_1);

            // Pin 113 Pinshare Config : AUX_N Mode
            ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_DPRX_AUX_N_1);
        }
#else
        // Pin 112 Pinshare Config : AUX_P Mode
        ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_DPRX_AUX_P_1);

        // Pin 113 Pinshare Config : AUX_N Mode
        ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_DPRX_AUX_N_1);
#endif
    }
#endif
#endif

#if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 110 Pinshare Config : GPI Mode
        ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_GPI);

        // Pin 111 Pinshare Config : GPI Mode
        ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_GPI);
    }
    else
    {
#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
        {
            // Pin 110 Pinshare Config : AUX_P Mode
            ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_DPRX_AUX_P_0);

            // Pin 111 Pinshare Config : AUX_N Mode
            ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_DPRX_AUX_N_0);
        }
#else
        // Pin 110 Pinshare Config : AUX_P Mode
        ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, _PIN_110_DPRX_AUX_P_0);

        // Pin 111 Pinshare Config : AUX_N Mode
        ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, _PIN_111_DPRX_AUX_N_0);
#endif
    }

#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 112 Pinshare Config : GPI Mode
        ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_GPI);

        // Pin 113 Pinshare Config : GPI Mode
        ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_GPI);
    }
    else
    {
#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
        {
            // Pin 112 Pinshare Config : AUX_P Mode
            ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_DPRX_AUX_P_1);

            // Pin 113 Pinshare Config : AUX_N Mode
            ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_DPRX_AUX_N_1);
        }
#else
        // Pin 112 Pinshare Config : AUX_P Mode
        ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, _PIN_112_DPRX_AUX_P_1);

        // Pin 113 Pinshare Config : AUX_N Mode
        ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, _PIN_113_DPRX_AUX_N_1);
#endif
    }
#endif
#endif
}
#endif  // End of #if(_D0_DP_EXIST == _ON)

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Audio Pin GPIO Pinshare Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAudioPinGPIOCheck(void)
{
#if(_DAC_HP_OUTPUT_SUPPORT == _ON)
    // Pinshare Setting Should be Set to Audio HPOUT R/L When _DAC_HP_OUTPUT_SUPPORT  Support _ON
    CHECK_PIN_CONDITION((_PIN_60 == _PIN_60_AUDIO_HOUTL) && (_PIN_61 == _PIN_61_AUDIO_HOUTR));
#else
    // Pinshare Setting Should Not be Set to Audio HPOUT R/L When _DAC_HP_OUTPUT_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_60 != _PIN_60_AUDIO_HOUTL) && (_PIN_61 != _PIN_61_AUDIO_HOUTR));
#endif

#if(_LINE_IN_SUPPORT == _ON)
    // Pinshare Setting Should be Set to Audio LINE_IN R/L When _LINE_IN_SUPPORT  Support _ON
    CHECK_PIN_CONDITION((_PIN_55 == _PIN_55_LINE_INL) && (_PIN_56 == _PIN_56_LINE_INR));
#else
    // Pinshare Setting Should Not be Set to Audio LINE_IN R/L When _LINE_IN_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_55 != _PIN_55_LINE_INL) && (_PIN_56 != _PIN_56_LINE_INR));
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Pinshare Setting Should be Set to Audio SPEAKER_OUTPUT R/L When _DAC_SPEAKER_OUTPUT_SUPPORT  Support _ON
    CHECK_PIN_CONDITION((_PIN_58 == _PIN_58_AUDIO_SOUTL) && (_PIN_59 == _PIN_59_AUDIO_SOUTR));
#else
    // Pinshare Setting Should Not be Set to Audio SPEAKER_OUTPUT R/L When _DAC_SPEAKER_OUTPUT_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_58 != _PIN_58_AUDIO_SOUTL) && (_PIN_59 != _PIN_59_AUDIO_SOUTR));
#endif
}
#endif
