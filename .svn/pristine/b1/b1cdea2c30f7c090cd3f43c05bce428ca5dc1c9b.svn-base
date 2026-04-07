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
// ID Code      : RL6492_Series_Pinshare.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6492_SERIES_PINSHARE__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GPIO_OPEN_DRAIN                        2

#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
#define _ADC_OUTPUT_MAX_TIME                    2
#endif // #if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
WORD g_usSlop;
BYTE g_ucoffset;
bit g_bsign;
#endif // #if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)

#if((_HDMI_SUPPORT == _ON) && (_HDMI_2_0_SUPPORT == _ON) && (_HDMI_5V_DETECT_BY_USER == _OFF))
BYTE g_ucHpdPinStatus;
#endif


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

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
void ScalerPinshareTYCPinResistorTrimmingControl(void);
#endif

#if(_D0_DP_EXIST == _ON)
void ScalerPinshareRx0TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation);
#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
void ScalerPinshareRx0TypeCPinAssert_EXINT0(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation);
#endif
#endif

#if(_D1_DP_EXIST == _ON)
void ScalerPinshareRx1TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation);
#endif

#if(_AUDIO_SUPPORT == _ON)
void ScalerPinshareAudioPinGPIOCheck(void);
#endif

#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
void ScalerPinshareTypeCAdcInitial(void);
WORD ScalerPinshareTypeCAdcGetAdcIdealData(EnumTypeCAdcChannel enumChannel);
#endif

#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_2_0_SUPPORT == _ON)
#if(_HDMI_5V_DETECT_BY_USER == _OFF)
void ScalerPinshareRxHpdPullDownSet(BYTE ucInputPort, bit bEnable);
#endif
#endif
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

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE != _PORT_CONTROLLER_EMBEDDED)
    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON1, (BYTE)_PIN_7);
    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON1, (BYTE)_PIN_8);
#else
    // TC Config Port Need Input Mode for PIN7/8
    ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON1, _PIN_7_GPI);
    ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON1, _PIN_7_GPI);
#endif
    ScalerSetByte(P10_02_PIN_SHARE_CTRL02__ON1, (BYTE)_PIN_9);
    ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON1, (BYTE)_PIN_10);
    ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON1, (BYTE)_PIN_11);
    ScalerSetByte(P10_06_PIN_SHARE_CTRL06__ON1, (BYTE)_PIN_14);
    ScalerSetByte(P10_07_PIN_SHARE_CTRL07__ON1, (BYTE)_PIN_15);
    ScalerSetByte(P10_08_PIN_SHARE_CTRL08__ON1, (BYTE)_PIN_16);
    ScalerSetByte(P10_09_PIN_SHARE_CTRL09__ON1, (BYTE)_PIN_17);
    ScalerSetByte(P10_0A_PIN_SHARE_CTRL0A__ON1, (BYTE)_PIN_18);
    ScalerSetByte(P10_0B_PIN_SHARE_CTRL0B__ON1, (BYTE)_PIN_19);
    ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON1, (BYTE)_PIN_20);
    ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON1, (BYTE)_PIN_21);
    ScalerSetByte(P10_0E_PIN_SHARE_CTRL0E__ON1, (BYTE)_PIN_22);
    ScalerSetByte(P10_0F_PIN_SHARE_CTRL0F__ON1, (BYTE)_PIN_23);
    ScalerSetByte(P10_10_PIN_SHARE_CTRL10__ON1, (BYTE)_PIN_24);
    ScalerSetByte(P10_12_PIN_SHARE_CTRL12__ON1, (BYTE)_PIN_29);
    ScalerSetByte(P10_13_PIN_SHARE_CTRL13__ON1, (BYTE)_PIN_30);
    ScalerSetByte(P10_14_PIN_SHARE_CTRL14__ON1, (BYTE)_PIN_32);
    ScalerSetByte(P10_15_PIN_SHARE_CTRL15__ON1, (BYTE)_PIN_33);
    ScalerSetByte(P10_16_PIN_SHARE_CTRL16__ON1, (BYTE)_PIN_37);
    ScalerSetByte(P10_17_PIN_SHARE_CTRL17__ON1, (BYTE)_PIN_38);
    ScalerSetByte(P10_18_PIN_SHARE_CTRL18__ON1, (BYTE)_PIN_39);
    ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON1, (BYTE)_PIN_40);
    ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON1, (BYTE)_PIN_41);
    ScalerSetByte(P10_1B_PIN_SHARE_CTRL1B__ON1, (BYTE)_PIN_42);
    ScalerSetByte(P10_1C_PIN_SHARE_CTRL1C__ON1, (BYTE)_PIN_43);
    ScalerSetByte(P10_1D_PIN_SHARE_CTRL1D__ON1, (BYTE)_PIN_44);
    ScalerSetByte(P10_1E_PIN_SHARE_CTRL1E__ON1, (BYTE)_PIN_45);
    ScalerSetByte(P10_1F_PIN_SHARE_CTRL1F__ON1, (BYTE)_PIN_46);
    ScalerSetByte(P10_20_PIN_SHARE_CTRL20__OFF1, (BYTE)_PIN_58_OFF_REGION);
    ScalerSetByte(P10_21_PIN_SHARE_CTRL21__OFF1, (BYTE)_PIN_59_OFF_REGION);
    ScalerSetByte(P10_22_PIN_SHARE_CTRL22__OFF1, (BYTE)_PIN_60_OFF_REGION);
    ScalerSetByte(P10_23_PIN_SHARE_CTRL23__OFF1, (BYTE)_PIN_61_OFF_REGION);
    ScalerSetByte(P10_24_PIN_SHARE_CTRL24__OFF1, (BYTE)_PIN_62_OFF_REGION);
    ScalerSetByte(P10_25_PIN_SHARE_CTRL25__OFF1, (BYTE)_PIN_63_OFF_REGION);
    ScalerSetByte(P10_26_PIN_SHARE_CTRL26__OFF1, (BYTE)_PIN_64_OFF_REGION);
    ScalerSetByte(P10_27_PIN_SHARE_CTRL27__OFF1, (BYTE)_PIN_65_OFF_REGION);
    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__OFF1, (BYTE)_PIN_66_OFF_REGION);
    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__OFF1, (BYTE)_PIN_67_OFF_REGION);
    ScalerSetByte(P10_2A_PIN_SHARE_CTRL2A__ON1, (BYTE)_PIN_69);
    ScalerSetByte(P10_2B_PIN_SHARE_CTRL2B__ON1, (BYTE)_PIN_70);
    ScalerSetByte(P10_2C_PIN_SHARE_CTRL2C__ON1, (BYTE)_PIN_71);
    ScalerSetByte(P10_2D_PIN_SHARE_CTRL2D__ON1, (BYTE)_PIN_72);
    ScalerSetByte(P10_2E_PIN_SHARE_CTRL2E__ON1, (BYTE)_PIN_73);
    ScalerSetByte(P10_2F_PIN_SHARE_CTRL2F__ON1, (BYTE)_PIN_74);
    ScalerSetByte(P10_30_PIN_SHARE_CTRL30__ON1, (BYTE)_PIN_75);
    ScalerSetByte(P10_31_PIN_SHARE_CTRL31__ON1, (BYTE)_PIN_78);
    ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, (BYTE)_PIN_80);
    ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, (BYTE)_PIN_79);
    ScalerSetByte(P10_34_PIN_SHARE_CTRL34__ON1, (BYTE)_PIN_81);
    ScalerSetByte(P10_35_PIN_SHARE_CTRL35__ON1, (BYTE)_PIN_82);
    ScalerSetByte(P10_36_PIN_SHARE_CTRL36__ON1, (BYTE)_PIN_83);
    ScalerSetByte(P10_37_PIN_SHARE_CTRL37__ON1, (BYTE)_PIN_84);
    ScalerSetByte(P10_38_PIN_SHARE_CTRL38__ON1, (BYTE)_PIN_85);
    ScalerSetByte(P10_39_PIN_SHARE_CTRL39__ON1, (BYTE)_PIN_91);
    ScalerSetByte(P10_3A_PIN_SHARE_CTRL3A__ON1, (BYTE)_PIN_86);
    ScalerSetByte(P10_3B_PIN_SHARE_CTRL3B__ON1, (BYTE)_PIN_87);
    ScalerSetByte(P10_3C_PIN_SHARE_CTRL3C__ON1, (BYTE)_PIN_88);
    ScalerSetByte(P10_3D_PIN_SHARE_CTRL3D__ON1, (BYTE)_PIN_89);
    ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, (BYTE)_PIN_97);
    ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, (BYTE)_PIN_98);
    ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, (BYTE)_PIN_99);
    ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, (BYTE)_PIN_100);

    // Set Pin configure to AC ON
    ScalerPinshareConfig(_POWER_STATUS_AC_ON);

    // Pin Config adjust sample (this is a ineffective configuration example aviod uncall worning)
    ScalerPinshareAdjustConfig(_CONFIG_PIN_START, _GPI);
    ScalerPinshareGpioDdcPinSwitch(0xFF);

    // Set Bounding Option Pin12/36 Initial Push-Pull Mode
    ScalerSetByte(P10_05_PIN_SHARE_CTRL05__ON1, 0x01);
    ScalerSetByte(P10_11_PIN_SHARE_CTRL11__ON1, 0x01);

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
    ScalerPinshareTYCPinResistorTrimmingControl();
#endif

#ifdef _PINSHARE_IO_TOGGLE_SUPPORT
    ScalerPinshareIOToggle();
#endif

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
    ScalerSetByte(P10_20_PIN_SHARE_CTRL20__OFF1, (BYTE)_PIN_58_OFF_REGION);
    ScalerSetByte(P10_21_PIN_SHARE_CTRL21__OFF1, (BYTE)_PIN_59_OFF_REGION);
    ScalerSetByte(P10_22_PIN_SHARE_CTRL22__OFF1, (BYTE)_PIN_60_OFF_REGION);
    ScalerSetByte(P10_23_PIN_SHARE_CTRL23__OFF1, (BYTE)_PIN_61_OFF_REGION);
    ScalerSetByte(P10_24_PIN_SHARE_CTRL24__OFF1, (BYTE)_PIN_62_OFF_REGION);
    ScalerSetByte(P10_25_PIN_SHARE_CTRL25__OFF1, (BYTE)_PIN_63_OFF_REGION);
    ScalerSetByte(P10_26_PIN_SHARE_CTRL26__OFF1, (BYTE)_PIN_64_OFF_REGION);
    ScalerSetByte(P10_27_PIN_SHARE_CTRL27__OFF1, (BYTE)_PIN_65_OFF_REGION);
    ScalerSetByte(P10_28_PIN_SHARE_CTRL28__OFF1, (BYTE)_PIN_66_OFF_REGION);
    ScalerSetByte(P10_29_PIN_SHARE_CTRL29__OFF1, (BYTE)_PIN_67_OFF_REGION);
}

#if(_HW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set HW IIC Pin Out
// Input Value  : ucHwIICPinNum --> Pin26_27/39_40/52_53/60_61/62_63
// Output Value : None
//--------------------------------------------------
void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum)
{
    // Set the selected HwIICPinNum to IIC output
    // Set the others as GPI
    switch(ucHwIICPinNum)
    {
        case _HW_IIC_PIN_20_21:

            if((_PIN_20 == _PIN_20_IICSCL2) && (_PIN_21 == _PIN_21_IICSDA2))
            {
                ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON1, _PIN_20_IICSCL2);
            }
            if((_PIN_40 == _PIN_40_EEIICSCL) && (_PIN_41 == _PIN_41_EEIICSDA))
            {
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON1, _PIN_40_GPI);
                ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON1, _PIN_41_GPI);
            }
            if((_PIN_80 == _PIN_80_IICSCL1) && (_PIN_79 == _PIN_79_IICSDA1))
            {
                ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_80_GPI);
                ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_79_GPI);
            }
            break;

        case _HW_IIC_PIN_40_41:

            if((_PIN_40 == _PIN_40_EEIICSCL) && (_PIN_41 == _PIN_41_EEIICSDA))
            {
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON1, _PIN_40_EEIICSCL);
            }
            if((_PIN_20 == _PIN_20_IICSCL2) && (_PIN_21 == _PIN_21_IICSDA2))
            {
                ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON1, _PIN_20_GPI);
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON1, _PIN_21_GPI);
            }
            if((_PIN_80 == _PIN_80_IICSCL1) && (_PIN_79 == _PIN_79_IICSDA1))
            {
                ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_80_GPI);
                ScalerSetByte(P10_33_PIN_SHARE_CTRL33__ON1, _PIN_79_GPI);
            }
            break;

        case _HW_IIC_PIN_80_79:

            if((_PIN_80 == _PIN_80_IICSCL1) && (_PIN_79 == _PIN_79_IICSDA1))
            {
                ScalerSetByte(P10_32_PIN_SHARE_CTRL32__ON1, _PIN_80_IICSCL1);
            }
            if((_PIN_20 == _PIN_20_IICSCL2) && (_PIN_21 == _PIN_21_IICSDA2))
            {
                ScalerSetByte(P10_0C_PIN_SHARE_CTRL0C__ON1, _PIN_20_GPI);
                ScalerSetByte(P10_0D_PIN_SHARE_CTRL0D__ON1, _PIN_21_GPI);
            }
            if((_PIN_40 == _PIN_40_EEIICSCL) && (_PIN_41 == _PIN_41_EEIICSDA))
            {
                ScalerSetByte(P10_19_PIN_SHARE_CTRL19__ON1, _PIN_40_GPI);
                ScalerSetByte(P10_1A_PIN_SHARE_CTRL1A__ON1, _PIN_41_GPI);
            }
            break;

        default:
            break;
    }
}
#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Switch DDC pin to GPIO or viceversa
// Input Value  : ucPinType --> _PIN_58/59-121/122-123/124_GPIO/DDC
// Output Value : None
//--------------------------------------------------
void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType)
{
    switch(ucPinType)
    {
        case _DDC_VGA_SWITCH_GPIO:
            ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON1, _PIN_10_GPO_OD);
            ScalerSetByte(P10_04_PIN_SHARE_CTRL04__ON1, _PIN_11_GPO_OD);
            break;

        case _DDC_VGA_SWITCH_DDC:
            ScalerSetByte(P10_03_PIN_SHARE_CTRL03__ON1, _PIN_10_DDCSCLVGA);
            break;

        case _DDC2_SWITCH_GPIO:
            ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_97_GPO_OD);
            ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_98_GPO_OD);
            break;

        case _DDC2_SWITCH_DDC:
            ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_97_DDCSCL2);
            break;

        case _DDC2_SWITCH_GPI:
            ScalerSetByte(P10_3E_PIN_SHARE_CTRL3E__ON1, _PIN_97_GPI);
            ScalerSetByte(P10_3F_PIN_SHARE_CTRL3F__ON1, _PIN_98_GPI);
            break;

        case _DDC1_SWITCH_GPIO:
            ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_GPO_OD);
            ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, _PIN_100_GPO_OD);
            break;

        case _DDC1_SWITCH_DDC:
            ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_DDCSCL1);
            break;

        case _DDC1_SWITCH_GPI:
            ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_GPI);
            ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, _PIN_100_GPI);
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Adjust pin share config
// Input Value  : enumConfigPin  --> Pin num
//                enumConfigTyte --> Pin type(GPIO/PWM..Etc.)
// Output Value : None
//--------------------------------------------------
void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigType enumConfigType)
{
    enumConfigPin = enumConfigPin;
    enumConfigType = enumConfigType;
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
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
                    break;

                case _SPI_DRIVE_3_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT4 | _BIT3);
                    break;

                case _SPI_DRIVE_4_0MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
                    break;

                case _SPI_DRIVE_4_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT3);
                    break;

                case _SPI_DRIVE_5_0MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
                    break;

                case _SPI_DRIVE_5_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3);
                    break;

                default:
                    break;
            }

            break;

        case _CONFIG_PIN_SPI_SI_SO_CEB:

            switch(enumFlashDriveConfig)
            {
                case _SPI_DRIVE_3_0MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                    break;

                case _SPI_DRIVE_3_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1 | _BIT0);
                    break;

                case _SPI_DRIVE_4_0MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                    break;

                case _SPI_DRIVE_4_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT0);
                    break;

                case _SPI_DRIVE_5_0MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
                    break;

                case _SPI_DRIVE_5_5MA:
                    ScalerSetBit(P10_C0_PIN_DRIVING_CTRL00__ON1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
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
    ScalerSetBit(P10_80_PIN_SLEW_RATE_CTRL00__ON1, ~(_BIT7), (_FLASH_CLK_SLEW_RATE_CONTROL & 0x01) << 7);

    // Setting Flash SPI SI/SO/CEB Pin Slew-Rate Control
    ScalerSetBit(P10_80_PIN_SLEW_RATE_CTRL00__ON1, ~(_BIT6), (_FLASH_SI_SO_CEB_SLEW_RATE_CONTROL & 0x01) << 6);
}

//--------------------------------------------------
// Description  : Reset MHL setting when MHL nonsupport
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareCBUSPinInitialReset(void)
{
    return;
}

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Pinshare TYPE C 1M ohm Trimming control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareTYCPinResistorTrimmingControl(void)
{
    BYTE ucEfuseDriv = 0;

    // load TYPEC Pin 1M Ohm Trimming
    ScalerEfuseGetData(_EFUSE_TYPE_C_1M_OHM_RESISTOR, 1, &ucEfuseDriv);
    ScalerSetByte(P10_46_1M_TRIM_CTRL0__ON1, ucEfuseDriv);
}
#endif

#if(_D0_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Aux Pin-Share and Aux PN Pull High/Low Setting
// Input Value  : TypeC Pin Assigment, TypeC Orientation
// Output Value : None
//--------------------------------------------------
void ScalerPinshareRx0TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation)
{
    enumTypeCOrientation = enumTypeCOrientation;

    // Aux Pin-Share Setting
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 7 Pinshare Config : Input Mode
        ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON1, _PIN_7_GPI);

        // Pin 8 Pinshare Config : Input Mode
        ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON1, _PIN_8_GPI);
    }
    else
    {
        // Pin 7 Pinshare Config : AUX Mode
        ScalerSetByte(P10_00_PIN_SHARE_CTRL00__ON1, _PIN_7_AUXP0);

        // Pin 8 Pinshare Config : AUX Mode
        ScalerSetByte(P10_01_PIN_SHARE_CTRL01__ON1, _PIN_8_AUXN0);
    }

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
    // Aux PN Pull High/Low Setting
    switch(enumTypeCPinCfgType)
    {
        case _TYPE_C_PIN_ASSIGNMENT_C:
        case _TYPE_C_PIN_ASSIGNMENT_D:

            if(enumTypeCOrientation == _TYPE_C_ORIENTATION_UNFLIP)
            {
                // Pin 16 AUX-P Pull High
                ScalerSetBit(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT6);

                // Pin 15 AUX-N Pull Low
                ScalerSetBit(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT1);
            }
            else
            {
                // Pin 16 AUX-P Pull Low
                ScalerSetBit(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT7);

                // Pin 15 AUX-N Pull High
                ScalerSetBit(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT0);
            }

            break;

        case _TYPE_C_PIN_ASSIGNMENT_E:

            if(enumTypeCOrientation == _TYPE_C_ORIENTATION_UNFLIP)
            {
                // Pin 16 AUX-P Pull Low
                ScalerSetBit(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT7);

                // Pin 15 AUX-N Pull High
                ScalerSetBit(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT0);
            }
            else
            {
                // Pin 16 AUX-P Pull High
                ScalerSetBit(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT6);

                // Pin 15 AUX-N Pull Low
                ScalerSetBit(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT1);
            }

            break;

        case _TYPE_C_PIN_ASSIGNMENT_NONE:

            // Pin 16 AUX-P Pull/Down Disable
            ScalerSetBit(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), 0x00);

            // Pin 15 AUX-N Pull/Down Disable
            ScalerSetBit(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), 0x00);

            break;

        default:
            break;
    }
#endif
}

#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
//--------------------------------------------------
// Description  : Aux Pin-Share and Aux PN Pull High/Low Setting
// Input Value  : TypeC Pin Assigment, TypeC Orientation
// Output Value : None
//--------------------------------------------------
void ScalerPinshareRx0TypeCPinAssert_EXINT0(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation) using 1
{
    enumTypeCOrientation = enumTypeCOrientation;

    // Aux Pin-Share Setting
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 7 Pinshare Config : Input Mode
        ScalerSetByte_EXINT(P10_00_PIN_SHARE_CTRL00__ON1, _PIN_7_GPI);

        // Pin 8 Pinshare Config : Input Mode
        ScalerSetByte_EXINT(P10_01_PIN_SHARE_CTRL01__ON1, _PIN_8_GPI);
    }
    else
    {
        // Pin 7 Pinshare Config : AUX Mode
        ScalerSetByte_EXINT(P10_00_PIN_SHARE_CTRL00__ON1, _PIN_7_AUXP0);

        // Pin 8 Pinshare Config : AUX Mode
        ScalerSetByte_EXINT(P10_01_PIN_SHARE_CTRL01__ON1, _PIN_8_AUXN0);
    }

    // Aux PN Pull High/Low Setting
    switch(enumTypeCPinCfgType)
    {
        case _TYPE_C_PIN_ASSIGNMENT_C:
        case _TYPE_C_PIN_ASSIGNMENT_D:

            if(enumTypeCOrientation == _TYPE_C_ORIENTATION_UNFLIP)
            {
                // Pin 16 AUX-P Pull High
                ScalerSetBit_EXINT(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT6);

                // Pin 15 AUX-N Pull Low
                ScalerSetBit_EXINT(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT1);
            }
            else
            {
                // Pin 16 AUX-P Pull Low
                ScalerSetBit_EXINT(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT7);

                // Pin 15 AUX-N Pull High
                ScalerSetBit_EXINT(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT0);
            }

            break;

        case _TYPE_C_PIN_ASSIGNMENT_E:

            if(enumTypeCOrientation == _TYPE_C_ORIENTATION_UNFLIP)
            {
                // Pin 16 AUX-P Pull Low
                ScalerSetBit_EXINT(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT7);

                // Pin 15 AUX-N Pull High
                ScalerSetBit_EXINT(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT0);
            }
            else
            {
                // Pin 16 AUX-P Pull High
                ScalerSetBit_EXINT(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), _BIT6);

                // Pin 15 AUX-N Pull Low
                ScalerSetBit_EXINT(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), _BIT1);
            }

            break;

        case _TYPE_C_PIN_ASSIGNMENT_NONE:

            // Pin 16 AUX-P Pull/Down Disable
            ScalerSetBit_EXINT(P10_A2_PIN_PULLUP_CTRL02__ON1, ~(_BIT7 | _BIT6), 0x00);

            // Pin 15 AUX-N Pull/Down Disable
            ScalerSetBit_EXINT(P10_A1_PIN_PULLUP_CTRL01__ON1, ~(_BIT1 | _BIT0), 0x00);

            break;

        default:
            break;
    }
}
#endif  // End of #if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
#endif  // End of #if(_D0_DP_EXIST == _ON)

#if(_D1_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Aux Pin-Share and Aux PN Pull High/Low Setting
// Input Value  : TypeC Pin Assigment, TypeC Orientation
// Output Value : None
//--------------------------------------------------
void ScalerPinshareRx1TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation)
{
    enumTypeCPinCfgType = enumTypeCPinCfgType;
    enumTypeCOrientation = enumTypeCOrientation;

#if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
    // Aux Pin-Share Setting
    if(enumTypeCPinCfgType == _TYPE_C_PIN_ASSIGNMENT_NONE)
    {
        // Pin 99 Pinshare Config : Input Mode
        ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_GPI);

        // Pin 100 Pinshare Config : Input Mode
        ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, _PIN_100_GPI);
    }
    else
    {
#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
        {
            // Pin 99 Pinshare Config : AUX Mode
            ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_AUXP1);

            // Pin 100 Pinshare Config : AUX Mode
            ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, _PIN_100_AUXN1);
        }
#else
        // Pin 99 Pinshare Config : AUX Mode
        ScalerSetByte(P10_40_PIN_SHARE_CTRL40__ON1, _PIN_99_AUXP1);

        // Pin 100 Pinshare Config : AUX Mode
        ScalerSetByte(P10_41_PIN_SHARE_CTRL41__ON1, _PIN_100_AUXN1);
#endif
    }
#endif
}
#endif  // End of #if(_D1_DP_EXIST == _ON)

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
    CHECK_PIN_CONDITION((_PIN_74 == _PIN_74_AUDIO_HOUTL) && (_PIN_75 == _PIN_75_AUDIO_HOUTR));
#else
    // Pinshare Setting Should Not be Set to Audio HPOUT R/L When _DAC_HP_OUTPUT_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_74 != _PIN_74_AUDIO_HOUTL) && (_PIN_75 != _PIN_75_AUDIO_HOUTR));
#endif

#if(_LINE_IN_SUPPORT == _ON)
    // Pinshare Setting Should be Set to Audio LINE_IN R/L When _LINE_IN_SUPPORT  Support _ON
    CHECK_PIN_CONDITION((_PIN_69 == _PIN_69_LINE_INL) && (_PIN_70 == _PIN_70_LINE_INR));
#else
    // Pinshare Setting Should Not be Set to Audio LINE_IN R/L When _LINE_IN_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_69 != _PIN_69_LINE_INL) && (_PIN_70 != _PIN_70_LINE_INR));
#endif

#if(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    // Pinshare Setting Should be Set to Audio SPEAKER_OUTPUT R/L When _DAC_SPEAKER_OUTPUT_SUPPORT  Support _ON
    CHECK_PIN_CONDITION((_PIN_72 == _PIN_72_AUDIO_SOUTL) && (_PIN_73 == _PIN_73_AUDIO_SOUTR));
#else
    // Pinshare Setting Should Not be Set to Audio SPEAKER_OUTPUT R/L When _DAC_SPEAKER_OUTPUT_SUPPORT  Support _OFF
    CHECK_PIN_CONDITION((_PIN_72 != _PIN_72_AUDIO_SOUTL) && (_PIN_73 != _PIN_73_AUDIO_SOUTR));
#endif
}
#endif

#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TypeC ADC Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPinshareTypeCAdcInitial(void)
{
    BYTE pucEfuseValueTemp[3] = {0};

    // -------------------- ADC AIF Setting ---------------------

    // [0x7F55] LDO Setting : [5] reg_sar_ckout_sel = Reserve ckout / [4] reg_ldo_trim = LDO Normal Mode / [0] reg_pow_ldo = _ENABLE
    ScalerSetBit(P7F_55_10B_ADC_LDO_CTRL, ~(_BIT5 | _BIT4 | _BIT0), (_BIT5 | _BIT0));

    // [0x7F59] Low Pass Filter Setting
    ScalerSetBit(P7F_59_ADC_LPF, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

    // -------------------- ADC Output Setting ---------------------

    // [0x7F01] ADC Output Channel Disable
    ScalerSetBit(P7F_01_10B_ADC_CH_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);

    // [0x7F05] [2:0]ADC Number of Outputs Averaged (1/2/4/8/16/32) = 4
    ScalerSetBit(P7F_05_10B_ADC_AVE_CTRL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    // [0x7F07-08] ADC Switch Time (#ADC_CLK Cycles) = 8 * 12 clk cycles
    ScalerSetBit(P7F_07_10B_ADC_SW_TM0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P7F_08_10B_ADC_SW_TM1, 0x60);

    // [0x7F09-0A] ADC Idle Time (#ADC_CLK Cycles) = 0 clk cycle
    ScalerSetBit(P7F_09_10B_ADC_IDLE_TM0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P7F_0A_10B_ADC_IDLE_TM1, 0x00);

    // [0x7F00] ADC Mode Setting : [7] Normal Mode / [6] Auto Mode = Enable / [5] ADC En = Enable
    ScalerSetBit(P7F_00_10B_ADC_CTL, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

    // [4:3] Channel2/1/0 (LOC_PW/UFP_VOMN/IMON)
    ScalerSetBit(P7F_01_10B_ADC_CH_EN, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));

    // -------------------- ADC Load Trimming ---------------------

    // Read Check Bit
    ScalerEfuseGetData(_EFUSE_CHECK_BIT, 1, &pucEfuseValueTemp[0]);

    if((pucEfuseValueTemp[0] & 0xE0) != 0x00)
    {
        // Read CC Resistance
        ScalerEfuseGetData(_EFUSE_CC_RESISTANCE, 8, &pucEfuseValueTemp[0]);

        // SARSDC LDO
        ScalerSetBit(P7F_55_10B_ADC_LDO_CTRL, ~(_BIT3 | _BIT2 | _BIT1), ((pucEfuseValueTemp[2] & 0xE0) >> 4));

        // VBus Comparator
        ScalerEfuseGetData(_EFUSE_VBUS_COMPARATOR, 1, &pucEfuseValueTemp[0]);

        // [0x7F56] Fast Role Swap Comparator Setting ([5:0] Vth = 250 ~ 565 mV, Delta = 5mV)
        ScalerSetBit(P7F_56_FRS_VBUS_COMP0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (pucEfuseValueTemp[0] & 0x3F));

        // ADC slop and offset
        ScalerEfuseGetData(_EFUSE_ADC_SLOP_OFFSET, 3, &pucEfuseValueTemp[0]);

        // slop*1000
        g_usSlop = (pucEfuseValueTemp[0] * 256 + pucEfuseValueTemp[1]);

        // offset
        g_ucoffset = (pucEfuseValueTemp[2] & 0x7F);
        g_bsign = ((pucEfuseValueTemp[2] & 0x80) >> 7);

        // Avoid Unreasonable Gain/Offset
        if((g_usSlop > 3000) || (g_usSlop < 1000) || (g_ucoffset > 200))
        {
            // Ideal slop*1000 = (2000 / 1024) * 1000 = 1953.125
            g_usSlop = 1953;

            // Ideal Offset
            g_ucoffset = 0;
        }
    }
    else
    {
        // Vbus 6-bit Comparator Vth: 0.360V
        // [0x7F56] Fast Role Swap Comparator Setting ([5:0] Vth = 250 ~ 565 mV, Delta = 5mV)
        ScalerSetBit(P7F_56_FRS_VBUS_COMP0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x16);

        // ideal slop*1000 = (2000 / 1024) * 1000 = 1953.125
        g_usSlop = 1953;

        // offset
        g_ucoffset = 0;
    }

    // ADC Clk Setting (Always Use IOSC = 28MHz)
    // [0x7F03] [7:6] Clk Sel = IOSC (b'00) / [5:0] adc_clk_div = b'0004
    ScalerSetByte(P7F_03_10B_ADC_CLK_CLRT, 0x05);
}

//--------------------------------------------------
// Description  : Get ADC Channel Output Value with Correction
// Input Value  : enumChannel : 0/1 (_TYPE_C_UFP_VMON/IMON) / 2 (_TYPE_C_LOC_PW) / 3/4 (_TYPE_C_DFP_VMON/IMON)
// Output Value : None
//--------------------------------------------------
WORD ScalerPinshareTypeCAdcGetAdcIdealData(EnumTypeCAdcChannel enumChannel)
{
    DWORD ulResult = 0;
    DWORD ulAx = 0;
    DWORD ulB = 0;

    // =================
    // Get ADC Output
    // =================

    // [0x7F02] [4:0] Write Valid Output Bit to Get New Value From ADC
    ScalerSetBit(P7F_02_10B_ADC_OUTPUT, ~(_BIT0 << enumChannel), (_BIT0 << enumChannel));

    // Polling Valid Output Bit (will be 1 when the New Output is Put into Register [0x7F10-19])
    if(ScalerTimerPollingFlagProc(_ADC_OUTPUT_MAX_TIME, P7F_02_10B_ADC_OUTPUT, (_BIT0 << enumChannel), (_BIT0 << enumChannel)) == _TRUE)
    {
        BYTE ucResult_h = (ScalerGetByte(P7F_10_10B_ADC_A0_RSLT_H + (enumChannel * 2)));
        BYTE ucResult_l = (ScalerGetByte(P7F_11_10B_ADC_A0_RSLT_L + (enumChannel * 2))) & (_BIT1 | _BIT0);

        // usResult [9:0] = {RSLT_H[7:0] | RSLT[1:0]}
        ulResult = ((ucResult_h << 2) | (ucResult_l));
    }

    // =================
    // Start Correction
    // =================

    ulAx = (DWORD)(g_usSlop) * ulResult / 1000;
    ulB = g_ucoffset;

    // check offset is positive or negative
    if(g_bsign == 0x01)
    {
        if(ulAx > ulB)
        {
            ulResult = ((ulAx - ulB) * 512 / 1000);
        }
        else
        {
            ulResult = 0;
        }
    }
    else
    {
        ulResult = ((ulAx + ulB) * 512 / 1000);
    }

    // =================
    // Overflow Check
    // =================
    if(ulResult > 1023)
    {
        return 1023;
    }

    return (WORD)ulResult;
}
#endif // End of #if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)

#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_2_0_SUPPORT == _ON)
#if(_HDMI_5V_DETECT_BY_USER == _OFF)
//--------------------------------------------------
// Description  : Pinshare Hpd Pull Down Setting
// Input Value  : enumInputPort, bEnable
// Output Value : None
//--------------------------------------------------
void ScalerPinshareRxHpdPullDownSet(BYTE ucInputPort, bit bEnable)
{
    bEnable = bEnable;

    switch(ucInputPort)
    {
#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerSetBit(P10_A3_PIN_PULLUP_CTRL03__ON1, ~(_BIT7 | _BIT6), _BIT7);

                g_ucHpdPinStatus = ScalerGetByte(P10_45_HDMI_HPD_INT_SEL__ON1);
                // Set HPD INT from D1 HPD pin
                ScalerSetBit(P10_45_HDMI_HPD_INT_SEL__ON1, ~_BIT0, 0x00);
            }
            else
            {
                ScalerSetByte(P10_45_HDMI_HPD_INT_SEL__ON1, g_ucHpdPinStatus);
                ScalerSetBit(P10_A3_PIN_PULLUP_CTRL03__ON1, ~(_BIT7 | _BIT6), 0x00);
            }
            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerSetBit(P10_A9_PIN_PULLUP_CTRL09__ON1, ~(_BIT7 | _BIT6), _BIT7);

                g_ucHpdPinStatus = ScalerGetByte(P10_45_HDMI_HPD_INT_SEL__ON1);
                // Set HPD INT from D2 HPD pin
                ScalerSetBit(P10_45_HDMI_HPD_INT_SEL__ON1, ~_BIT0, _BIT0);
            }
            else
            {
                ScalerSetByte(P10_45_HDMI_HPD_INT_SEL__ON1, g_ucHpdPinStatus);
                ScalerSetBit(P10_A9_PIN_PULLUP_CTRL09__ON1, ~(_BIT7 | _BIT6), 0x00);
            }
            break;
#endif
        default:
            break;
    }
}
#endif
#endif
#endif

