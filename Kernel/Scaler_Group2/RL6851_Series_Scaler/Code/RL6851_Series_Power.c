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
// ID Code      : RL6851_Series_Power.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Power Control Macro
//--------------------------------------------------
#define _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE    1
#define _POWER_DOMAIN_PROJECT_SUPPORT_DISABLE   0


//--------------------------------------------------
// Power Cut Group
//--------------------------------------------------
#define _POWER_CUT_ON_GROUP_DPMAC               0
#define _POWER_CUT_ON_GROUP_VCCK_ON             1
#define _POWER_CUT_ON_GROUP_VCCK_OFF            2
#define _POWER_CUT_ON_GROUP_PHY                 3
#define _POWER_CUT_ON_GROUP_TOPOFF              4


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Data Recover from Power Cut State
//--------------------------------------------------
typedef enum
{
    _POWER_RESET_ENABLE = 0x00,
    _POWER_RESET_DISABLE,
} EnumPowerReset;

//--------------------------------------------------
// Power Domain PS/PD Mode
//--------------------------------------------------
typedef enum
{
    _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL = 0x00,
    _POWER_DOMAIN_PSPD_MODE_KEEP_POWER_ON,
    _POWER_DOMAIN_PSPD_MODE_USER_CONTROL,
} EnumPowerPsPdMode;

//--------------------------------------------------
// Power Domain Related Structure
//--------------------------------------------------
typedef struct
{
    EnumPowerGroup enumPowerGroup;
    EnumPowerPsPdMode b2PsPdModeOperation : 2;
    BYTE b1ProjectSupport : 1;
} StructPowerCutGroup;

//--------------------------------------------------
// Power Domain Grouping Structure
//--------------------------------------------------
typedef struct
{
    StructPowerCutGroup *pstPowerCutGroup;
    BYTE ucMaxSize;
} StructPowerFlow;


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Power Group
//--------------------------------------------------
StructPowerCutGroup code tGroupPcbVcckOn[] =
{
    {_POWER_CUT_GROUP_005_IMC_ENC_M1,               _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  (_M_DOMAIN_IMG_CMP_SUPPORT == _ON)},
    {_POWER_CUT_GROUP_006_IMC_DEC_M1,               _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  (_M_DOMAIN_IMG_CMP_SUPPORT == _ON)},
    {_POWER_CUT_GROUP_007_AUDIO,                    _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  (_AUDIO_SUPPORT == _ON)},
    {_POWER_CUT_GROUP_008_SDR,                      _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE},
};

StructPowerCutGroup code tGroupPcbVcckOnMac[] =
{
    {_POWER_CUT_GROUP_003_RX0_DP11_HDMI14_MAC,      _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE},
};

StructPowerCutGroup code tGroupPcbVcckOnAPHY[] =
{
    {_POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY,     _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE},
};

StructPowerCutGroup code tGroupPcbVcckOnDPHY[] =
{
    {_POWER_CUT_GROUP_002_RX0_DP11_HDMI14_DPHY,     _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE},
};

StructPowerCutGroup code tGroupVcckOnTop[] =
{
    {_POWER_CUT_GROUP_004_TOP,                      _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL,  _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE},
};


//--------------------------------------------------
// Power ON/OFF Flow
//--------------------------------------------------
StructPowerFlow code tGroupPowerCutOn[] =
{
    {tGroupPcbVcckOnMac,        (sizeof(tGroupPcbVcckOnMac) / sizeof(tGroupPcbVcckOnMac[0]))},
    {tGroupPcbVcckOn,           (sizeof(tGroupPcbVcckOn) / sizeof(tGroupPcbVcckOn[0]))},
    {tGroupPcbVcckOnDPHY,       (sizeof(tGroupPcbVcckOnDPHY) / sizeof(tGroupPcbVcckOnDPHY[0]))},
    {tGroupPcbVcckOnAPHY,       (sizeof(tGroupPcbVcckOnAPHY) / sizeof(tGroupPcbVcckOnAPHY[0]))},
    {tGroupVcckOnTop,           (sizeof(tGroupVcckOnTop) / sizeof(tGroupVcckOnTop[0]))},
};

StructPowerFlow code tGroupPowerCutOff[] =
{
    {tGroupVcckOnTop,           (sizeof(tGroupVcckOnTop) / sizeof(tGroupVcckOnTop[0]))},
    {tGroupPcbVcckOnAPHY,       (sizeof(tGroupPcbVcckOnAPHY) / sizeof(tGroupPcbVcckOnAPHY[0]))},
    {tGroupPcbVcckOnDPHY,       (sizeof(tGroupPcbVcckOnDPHY) / sizeof(tGroupPcbVcckOnDPHY[0]))},
    {tGroupPcbVcckOnMac,        (sizeof(tGroupPcbVcckOnMac) / sizeof(tGroupPcbVcckOnMac[0]))},
    {tGroupPcbVcckOn,           (sizeof(tGroupPcbVcckOn) / sizeof(tGroupPcbVcckOn[0]))},
};


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerPowerDomainEnableStatus(void);
BYTE ScalerPowerIsolation(EnumPowerAction enumSwitch);
void ScalerPowerGroupPowerCut(EnumPowerGroup enumPowerGroup, EnumPowerCut enumPowerCut, EnumPowerReset enumPowerReset);
void ScalerPowerRecoverAGroupIsolationData(void);
void ScalerPowerRecoverBGroupIsolationData(void);
void ScalerPowerRecoverCGroupIsolationData(void);
void ScalerPowerRecoverDGroupIsolationData(void);
void ScalerPowerRecoverEGroupIsolationData(void);
void ScalerPowerRecoverTopGroupIsolationData(void);
void ScalerPowerRecoverAudioGroupIsolationData(void);
void ScalerPowerRecoverGDIGroupIsolationData(void);
void ScalerPowerGroupPowerACOnSetting(void);
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
EnumPowerCut ScalerPowerGroupGetPowerCutStatus(EnumPowerGroup enumPowerGroup);
BYTE ScalerPowerDomainEnableControl(EnumPowerGroup enumPowerGroup, EnumPowerCut enumPowerCut);
#endif // End of #if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Power Domain Enable
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerPowerDomainEnableStatus(void)
{
    return (_FACTORY_RTD_QC_SUPPORT == _ON);
}

//--------------------------------------------------
// Description  : Power cut block flow
// Input Value  : enumSwitch    --> Power action description.
// Output Value : return power group enter isolation area
//--------------------------------------------------
BYTE ScalerPowerIsolation(EnumPowerAction enumSwitch)
{
    BYTE ucPowerIsoFlg = 0x00;
    BYTE ucIndex = 0x00;
    BYTE ucPowerGroup = 0x00;
    EnumPowerReset enumPowerReset = _POWER_RESET_DISABLE;

    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_INITIAL:

            // Enable LVDS combo eDP Power
            ScalerPowerGroupPowerCut(_POWER_CUT_GROUP_004_TOP, _POWER_CUT_OFF, _POWER_RESET_ENABLE);

#if(_PANEL_STYLE == _PANEL_LVDS)
            // LVDS Pad Power Off
            ScalerDisplayLvdsPadPower(_OFF);
#elif(_PANEL_STYLE == _PANEL_DPTX)
            // LVDS Pad Power Off for eDP
            ScalerDisplayUseLvdsPadPower(_OFF);
#endif

            // Initial power group
            ScalerPowerGroupPowerACOnSetting();

            // Set Isolation Recovery Flag

            // Group Top block isolation control
            ucPowerIsoFlg |= _BIT0;

            // Group Audio block isolation control
            ucPowerIsoFlg |= _BIT1;

            // Group GDI & GDI PHY block isolation control
            ucPowerIsoFlg |= _BIT3;

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:

#if(_PANEL_STYLE == _PANEL_LVDS)
            // LVDS Pad Power Off
            ScalerDisplayLvdsPadPower(_OFF);
#elif(_PANEL_STYLE == _PANEL_DPTX)
            // LVDS Pad Power Off for eDP
            ScalerDisplayUseLvdsPadPower(_OFF);
#endif

            // Start Power Cut
            for(ucPowerGroup = 0; ucPowerGroup < (sizeof(tGroupPowerCutOn) / sizeof(tGroupPowerCutOn[0])); ucPowerGroup++)
            {
                for(ucIndex = 0; ucIndex < tGroupPowerCutOn[ucPowerGroup].ucMaxSize; ucIndex++)
                {
                    // Unused power domain judgment
                    if((ScalerPowerDomainEnableStatus() == _TRUE) ||
                       ((tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].b1ProjectSupport == _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE) &&
                        (tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].b2PsPdModeOperation == _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL)))
                    {
                        ScalerPowerGroupPowerCut(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup, _POWER_CUT_ON, _POWER_RESET_DISABLE);
                    }
                }
            }

            // Set Isolation Recovery Flag

            // Group Top block isolation control
            ucPowerIsoFlg |= _BIT0;

            // Group Audio block isolation control
            ucPowerIsoFlg |= _BIT1;

            // Group GDI & GDI PHY block isolation control
            ucPowerIsoFlg |= _BIT3;

            break;

        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            // Reset Judgment
            if(enumSwitch == _POWER_ACTION_AC_ON_TO_NORMAL)
            {
                enumPowerReset = _POWER_RESET_DISABLE;
            }
            else
            {
                enumPowerReset = _POWER_RESET_ENABLE;
            }

            // Start Power Up
            for(ucPowerGroup = 0; ucPowerGroup < (sizeof(tGroupPowerCutOff) / sizeof(tGroupPowerCutOff[0])); ucPowerGroup++)
            {
                for(ucIndex = 0; ucIndex < tGroupPowerCutOff[ucPowerGroup].ucMaxSize; ucIndex++)
                {
                    EnumPowerCut enumGroupPowerCut = _POWER_CUT_OFF;
                    EnumPowerReset enumGroupPowerReset = _POWER_RESET_ENABLE;

                    // Power domain ON/OFF judgment
                    if(ScalerPowerDomainEnableStatus() == _TRUE)
                    {
                        enumGroupPowerCut = _POWER_CUT_OFF;
                        enumGroupPowerReset = enumPowerReset;
                    }
                    else if(tGroupPowerCutOff[ucPowerGroup].pstPowerCutGroup[ucIndex].b1ProjectSupport == _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE)
                    {
                        enumGroupPowerCut = _POWER_CUT_OFF;
                        enumGroupPowerReset = enumPowerReset;

                        // Special Power Operation Mode Judgment
                        switch(tGroupPowerCutOff[ucPowerGroup].pstPowerCutGroup[ucIndex].b2PsPdModeOperation)
                        {
                            case _POWER_DOMAIN_PSPD_MODE_KEEP_POWER_ON:

                                enumGroupPowerReset = _POWER_RESET_DISABLE;

                                break;

                            case _POWER_DOMAIN_PSPD_MODE_USER_CONTROL:

                                if(enumSwitch != _POWER_ACTION_AC_ON_TO_NORMAL)
                                {
                                    // No operation
                                    continue;
                                }

                                break;

                            case _POWER_DOMAIN_PSPD_MODE_ACTION_NORMAL:
                            default:
                                break;
                        }
                    }
                    else
                    {
                        enumGroupPowerCut = _POWER_CUT_ON;
                        enumGroupPowerReset = _POWER_RESET_DISABLE;
                    }

                    // Power Domain Final Control
                    ScalerPowerGroupPowerCut(tGroupPowerCutOff[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup, enumGroupPowerCut, enumGroupPowerReset);
                }
            }

#if(_PANEL_STYLE == _PANEL_LVDS)
            // LVDS Pad Power On
            ScalerDisplayLvdsPadPower(_ON);
#elif(_PANEL_STYLE == _PANEL_DPTX)
            // LVDS Pad Power On for eDP
            ScalerDisplayUseLvdsPadPower(_ON);
#endif

            break;

        case _POWER_ACTION_NORMAL_TO_FAKE_PS:
        case _POWER_ACTION_PS_TO_OFF:

            break;

        default:
            break;
    }

    return ucPowerIsoFlg;
}

//--------------------------------------------------
// Description  : Group Power on/off
// Input Value  : enumPowerGroup : _POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY ~ _POWER_CUT_GROUP_008_SDR
// Input Value  : ucOn: ON(Low Power) / OFF(Normal Operation)
// Output Value : None
//--------------------------------------------------
void ScalerPowerGroupPowerCut(EnumPowerGroup enumPowerGroup, EnumPowerCut enumPowerCut, EnumPowerReset enumPowerReset)
{
    BYTE ucCounter = 0;

    switch(enumPowerGroup)
    {
        case _POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Analog isolation on
                ScalerSetBit(P0_E1_VCCKOFF_CONTROL2, ~_BIT0, 0x00);

                // DVDD Power off
                ScalerSetBit(PB_B0_CLK_DET, ~_BIT0, 0x00);

                // AVDD Power off
                ScalerSetBit(PB_B0_CLK_DET, ~_BIT1, 0x00);
            }
            else
            {
                // AVDD Power on
                ScalerSetBit(PB_B0_CLK_DET, ~_BIT1, _BIT1);

                // DVDD Power on
                ScalerSetBit(PB_B0_CLK_DET, ~_BIT0, _BIT0);

                // Analog isolation off
                ScalerSetBit(P0_E1_VCCKOFF_CONTROL2, ~_BIT0, _BIT0);
            }

            break;

        case _POWER_CUT_GROUP_002_RX0_DP11_HDMI14_DPHY:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Digital isolation on
                ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT1, _BIT1);

                // Digital power off
                ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_62_PD2_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT1, 0x00);

                // Power Cut block Relase
                ScalerSetBit(P6F_62_PD2_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        case _POWER_CUT_GROUP_003_RX0_DP11_HDMI14_MAC:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Digital isolation on
                ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT1, _BIT1);

                // Digital power off
                ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_63_PD3_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT1, 0x00);

                // Power Cut block Relase
                ScalerSetBit(P6F_63_PD3_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        case _POWER_CUT_GROUP_004_TOP:

#if(_PANEL_STYLE == _PANEL_DPTX)

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // =====================
                // Isolation Control
                // =====================

                // [3] = 0, VCCKOFFB_D10V: Isolation Mode
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT3, 0x00);

                // VCCK_OFF: Isolation ON
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT1, _BIT1);

                // VCCKOFFB_TOP: Isolation ON
                ScalerSetBit(P0_F1_VCCKOFF_CONTROL1, ~_BIT0, 0x00);


                // =====================
                // LVDS combo eDP Control
                // =====================

                // [7] = 1, POWER_CUT_AVDDCMU_TO_AVDD: Power OFF;
                // [6] = 1, POWER_CUT_AVDDCMU_TO_DVDD: Power Cut;
                // [5] = 1, POWER_CUT_AVDD_DPTX: Power OFF
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // [4] = 1, POWER_CUT_DVDD: Power Cut
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT4, _BIT4);

                // [0] = 0, POWER_CUT_VCCK_TO_AVDD: Power Cut
                ScalerSetBit(P6F_80_ADI_POWER_CTRL, ~_BIT0, 0x00);


                // =====================
                // TOP Control
                // =====================

                // Digital power off
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_64_PD4_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }


                // =====================
                // LVDS combo eDP Control
                // =====================

                // [0] = 0, POWER_CUT_VCCK_TO_AVDD: Power Cut
                ScalerSetBit(P6F_80_ADI_POWER_CTRL, ~_BIT0, 0x00);

                // [4] = 0, POWER_CUT_DVDD: Power ON
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT4, 0x00);

                // [0] = 1, CMU Mode: eDP
                ScalerSetBit(P55_73_DPTX_CMU3, ~_BIT0, _BIT0);

                // [7] = 0, POWER_CUT_AVDDCMU_TO_AVDD: Power ON;
                // [6] = 1, POWER_CUT_AVDDCMU_TO_DVDD: Power Cut;
                // [5] = 0, POWER_CUT_AVDD_DPTX: Power ON
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);


                // =====================
                // Isolation Control
                // =====================

                // VCCKOFFB_TOP: Isolation OFF
                ScalerSetBit(P0_F1_VCCKOFF_CONTROL1, ~_BIT0, _BIT0);

                // [3] = 1, VCCKOFFB_D10V: Normal Mode
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT3, _BIT3);

                // Digital isolation off
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT1, 0x00); // Check

                // Power Cut block Relase
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT0, 0x00);
            }

#elif(_PANEL_STYLE == _PANEL_LVDS)

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // =====================
                // Isolation Control
                // =====================

                // [3] = 0, VCCKOFFB_D10V: Isolation Mode
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT3, 0x00);

                // VCCK_OFF: Isolation ON
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT1, _BIT1);

                // VCCKOFFB_TOP: Isolation ON
                ScalerSetBit(P0_F1_VCCKOFF_CONTROL1, ~_BIT0, 0x00);


                // =====================
                // LVDS combo eDP Control
                // =====================

                // [7] = 1, POWER_CUT_AVDDCMU_TO_AVDD: Power OFF;
                // [6] = 1, POWER_CUT_AVDDCMU_TO_DVDD: Power Cut;
                // [5] = 1, POWER_CUT_AVDD_DPTX: Power OFF
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // [4] = 1, POWER_CUT_DVDD: Power Cut
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT4, _BIT4);

                // [0] = 0, POWER_CUT_VCCK_TO_AVDD: Power Cut
                ScalerSetBit(P6F_80_ADI_POWER_CTRL, ~_BIT0, 0x00);


                // =====================
                // TOP Control
                // =====================

                // Digital power off
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_64_PD4_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }


                // =====================
                // LVDS combo eDP Control
                // =====================

                // [0] = 1, POWER_CUT_VCCK_TO_AVDD: Power ON
                ScalerSetBit(P6F_80_ADI_POWER_CTRL, ~_BIT0, _BIT0);

                // [4] = 0, POWER_CUT_DVDD: Power ON
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT4, 0x00);

                // [0] = 0, CMU Mode: LVDS
                ScalerSetBit(P55_73_DPTX_CMU3, ~_BIT0, 0x00);

                // [7] = 0, POWER_CUT_AVDDCMU_TO_AVDD: Power ON;
                // [6] = 0, POWER_CUT_AVDDCMU_TO_DVDD: Power ON;
                // [5] = 0, POWER_CUT_AVDD_DPTX: Power ON
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~(_BIT7 | _BIT6 | _BIT5), 0x00);


                // =====================
                // Isolation Control
                // =====================

                // VCCKOFFB_TOP: Isolation OFF
                ScalerSetBit(P0_F1_VCCKOFF_CONTROL1, ~_BIT0, _BIT0);

                // [3] = 0, VCCKOFFB_D10V: Isolation Mode
                ScalerSetBit(P6F_69_PD9_POWER_CTRL, ~_BIT3, 0x00);

                // Digital isolation off
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT1, 0x00); // Check

                // Power Cut block Relase
                ScalerSetBit(P6F_64_PD4_POWER_CTRL, ~_BIT0, 0x00);
            }
#endif // End of #if(_PANEL_STYLE == _PANEL_DPTX)

            break;

        case _POWER_CUT_GROUP_005_IMC_ENC_M1:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Digital isolation on
                ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT1, _BIT1);

                // Digital power off
                ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_65_PD5_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT1, 0x00);

                // Power Cut block Relase
                ScalerSetBit(P6F_65_PD5_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        case _POWER_CUT_GROUP_006_IMC_DEC_M1:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Digital isolation on
                ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT1, _BIT1);

                // Digital power off
                ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_66_PD6_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT1, 0x00);

                // Power Cut block Relase
                ScalerSetBit(P6F_66_PD6_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        case _POWER_CUT_GROUP_007_AUDIO:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // ID Code Check
                if(ScalerGlobalGetIDCode() == _RL6851_VER_A_ID_CODE)
                {
                    // Ver. A

#if(_AUDIO_SUPPORT == _ON)
                    // Audio Mute Control
                    ScalerAudioPowerSavingMuteControl();
#endif // End of #if(_AUDIO_SUPPORT == _ON)
                }
                else
                {
                    // Ver. B ~ Other

                    // Digital isolation on
                    ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT1, _BIT1);

                    // Digital power off
                    ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT5, _BIT5);
                }
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_67_PD7_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT1, 0x00);

                // Power Cut block Relase
                ScalerSetBit(P6F_67_PD7_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        case _POWER_CUT_GROUP_008_SDR:

            if(enumPowerCut == _POWER_CUT_ON)
            {
                // Analog isolation on for SDR IO PADs
                ScalerSetBit(P0_F0_VCCKOFF_CONTROL0, ~_BIT0, 0x00);

                // Analog isolation on for SDR PLL
                ScalerSetBit(P0_F3_POWER_ON_RESET, ~_BIT1, 0x00);

                // Digital isolation on
                ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT1, _BIT1);

                // Digital power off
                ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT5, _BIT5);
            }
            else
            {
                if(enumPowerReset == _POWER_RESET_ENABLE)
                {
                    // Power Cut block Reset
                    ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT0, _BIT0);
                }

                // Digital power on
                ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT5, 0x00);

                // Wait for digital power on flag
                ucCounter = 50;

                while((ScalerGetBit(P6F_68_PD8_POWER_CTRL, _BIT4) != 0x00) && (ucCounter-- > 0))
                {
                    DELAY_5US();
                }

                // Digital isolation off
                ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT1, 0x00);

                // Analog isolation off for SDR PLL
                ScalerSetBit(P0_F3_POWER_ON_RESET, ~_BIT1, _BIT1);

                // Analog isolation off for SDR IO PADs
                ScalerSetBit(P0_F0_VCCKOFF_CONTROL0, ~_BIT0, _BIT0);

                // Power Cut block Relase
                ScalerSetBit(P6F_68_PD8_POWER_CTRL, ~_BIT0, 0x00);
            }

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Recover A Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverAGroupIsolationData(void)
{
    ScalerPowerRecoverTopGroupIsolationData();
}

//--------------------------------------------------
// Description  : Recover B Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverBGroupIsolationData(void)
{
    ScalerPowerRecoverAudioGroupIsolationData();
}

//--------------------------------------------------
// Description  : Recover C Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverCGroupIsolationData(void)
{
}

//--------------------------------------------------
// Description  : Recover D Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverDGroupIsolationData(void)
{
    // Recover GDI Group Power Cut Area
    ScalerPowerRecoverGDIGroupIsolationData();
}

//--------------------------------------------------
// Description  : Recover E Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverEGroupIsolationData(void)
{
}

//--------------------------------------------------
// Description  : Recover Top Power Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverTopGroupIsolationData(void)
{
    //////////////////////// Pin Share Start /////////////////////////////////////

    PCB_OFF_REGION_GPIO_SETTING_POWER_AC_PD_PS_ON();

    ScalerPinsharePowerOnReset();

    //////////////////////// Pin Share End /////////////////////////////////////

    //////////////////////// LVDS + LVDSPLL and VBO block start //////////////////

#if(_PANEL_STYLE == _PANEL_LVDS)
    // LVDS Port Power On recover
    ScalerDisplayLvdsInitialTable();
#elif(_PANEL_STYLE == _PANEL_DPTX)
    // Initial DPTx1
    ScalerDisplayDPTx1Initial();
#endif

    //////////////////////// LVDS + LVDSPLL and VBO block End ////////////////////


    //////////////////////// DPLL/MPLL/DDR PLL block start ///////////////////////

    // DPLL power up
    ScalerPLLSetDPLLReset();

    //////////////////////// DPLL/MPLL/DDR PLL  block End ////////////////////////


    //////////////////////// DDR DLL + DDR Delaychain start //////////////////////

    //////////////////////// DDR DLL + DDR Delaychain End ////////////////////////
}

//--------------------------------------------------
// Description  : Recover Audio Power Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverAudioGroupIsolationData(void)
{
}

//--------------------------------------------------
// Description  : Recover GDI Group Power Cut Area.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerRecoverGDIGroupIsolationData(void)
{
    // There is no action on RL6369 IC (For Tx Block) //C Group

    //////////////////////// GDI power cut block start ///////////////////////////////
#if(_DP_SUPPORT == _ON)

    // Set R0' Available HW Mode
    ScalerSetBit(PB_1A_HDCP_IRQ, ~(_BIT5 | _BIT4), _BIT5);

    // Enable DP Link Integrity Enable
    ScalerSetBit(PB_1B_HDCP_INTGT_VRF, ~_BIT7, _BIT7);

    // DP Mac Clock Select to Xtal Clock
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, _BIT6);

    if(ScalerGetBit(PB_20_HDCP_DEBUG, _BIT7) == _BIT7)
    {
        // HDCP R0 Calculate
        ScalerSetBit(PB_63_DUMMY2, ~_BIT7, _BIT7);
        ScalerSetBit(PB_63_DUMMY2, ~_BIT7, 0x00);
    }
#endif
    //////////////////////// GDI power cut block End /////////////////////////////////

    //////////////////////// GDI_2(CBUS/ECBUS) power cut block start ///////////////////////////////

    //////////////////////// GDI_2(CBUS/ECBUS) power cut block End /////////////////////////////////

    //////////////////////// HDCP 2.2 start //////////////////////

#if(_HDCP_2_2_SUPPORT == _ON)
    ScalerHdcp2Initial();
#endif

    //////////////////////// HDCP 2.2 End ////////////////////////

    // There is no action on RL6369 IC (For high speed port Block) //E Group
}

//--------------------------------------------------
// Description  : Group Power Setting when AC ON
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerPowerGroupPowerACOnSetting(void)
{
    BYTE ucIndex = 0x00;
    BYTE ucPowerGroup = 0x00;

    // Return when power domain force enable
    if(ScalerPowerDomainEnableStatus() == _TRUE)
    {
        return;
    }

    // Scanning all power domain
    for(ucPowerGroup = 0; ucPowerGroup < (sizeof(tGroupPowerCutOn) / sizeof(tGroupPowerCutOn[0])); ucPowerGroup++)
    {
        for(ucIndex = 0; ucIndex < tGroupPowerCutOn[ucPowerGroup].ucMaxSize; ucIndex++)
        {
            // Unused power domain judgment
            if(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].b1ProjectSupport == _POWER_DOMAIN_PROJECT_SUPPORT_DISABLE)
            {
                ScalerPowerGroupPowerCut(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup, _POWER_CUT_ON, _POWER_RESET_DISABLE);
            }
        }
    }
}

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Group Power on/off
// Input Value  : enumPowerGroup : _POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY ~ _POWER_CUT_GROUP_008_SDR
// Output Value : _POWER_CUT_ON / _POWER_CUT_OFF
//--------------------------------------------------
EnumPowerCut ScalerPowerGroupGetPowerCutStatus(EnumPowerGroup enumPowerGroup)
{
    switch(enumPowerGroup)
    {
        case _POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY:

            if((ScalerGetBit(PB_B0_CLK_DET, (_BIT1 | _BIT0)) == 0x00) &&
               (ScalerGetBit(P0_E1_VCCKOFF_CONTROL2, _BIT0) == 0x00))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_002_RX0_DP11_HDMI14_DPHY:

            if(ScalerGetBit(P6F_62_PD2_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_003_RX0_DP11_HDMI14_MAC:

            if(ScalerGetBit(P6F_63_PD3_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_004_TOP:

            if((ScalerGetBit(P6F_64_PD4_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1)) &&
               (ScalerGetBit(P6F_69_PD9_POWER_CTRL, (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) &&
               (ScalerGetBit(P0_F1_VCCKOFF_CONTROL1, _BIT0) == 0x00))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_005_IMC_ENC_M1:

            if(ScalerGetBit(P6F_65_PD5_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_006_IMC_DEC_M1:

            if(ScalerGetBit(P6F_66_PD6_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_007_AUDIO:

            if(ScalerGetBit(P6F_67_PD7_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        case _POWER_CUT_GROUP_008_SDR:

            if((ScalerGetBit(P6F_68_PD8_POWER_CTRL, (_BIT5 | _BIT4 | _BIT1)) == (_BIT5 | _BIT4 | _BIT1)) &&
               (ScalerGetBit(P0_F0_VCCKOFF_CONTROL0, _BIT0) == 0x00) &&
               (ScalerGetBit(P0_F3_POWER_ON_RESET, _BIT1) == 0x00))
            {
                return _POWER_CUT_ON;
            }
            else
            {
                return _POWER_CUT_OFF;
            }

            break;

        default:
            break;
    }

    return _POWER_CUT_ON;
}

//--------------------------------------------------
// Description  : Group Power on/off for other IP
// Input Value  : enumPowerGroup : _POWER_CUT_GROUP_001_RX0_DP11_HDMI14_APHY ~ _POWER_CUT_GROUP_008_SDR
// Input Value  : ucOn: ON(Low Power) / OFF(Normal Operation)
// Output Value : _SUCCESS / _FAIL
//--------------------------------------------------
BYTE ScalerPowerDomainEnableControl(EnumPowerGroup enumPowerGroup, EnumPowerCut enumPowerCut)
{
    BYTE ucIndex = 0x00;
    BYTE ucPowerGroup = 0x00;
    EnumPowerReset enumPowerReset = _POWER_RESET_ENABLE;

    // Scanning all power domain
    for(ucPowerGroup = 0; ucPowerGroup < (sizeof(tGroupPowerCutOn) / sizeof(tGroupPowerCutOn[0])); ucPowerGroup++)
    {
        for(ucIndex = 0; ucIndex < tGroupPowerCutOn[ucPowerGroup].ucMaxSize; ucIndex++)
        {
            // If power domain matches
            if(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup == enumPowerGroup)
            {
                // Unused power domain judgment
                if(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].b1ProjectSupport == _POWER_DOMAIN_PROJECT_SUPPORT_ENABLE)
                {
                    // Check Power Status
                    if(ScalerPowerGroupGetPowerCutStatus(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup) == enumPowerCut)
                    {
                        return _SUCCESS;
                    }

                    // Return when power domain force enable
                    if(ScalerPowerDomainEnableStatus() == _TRUE)
                    {
                        return _FAIL;
                    }

                    // Reset control
                    if(enumPowerCut == _POWER_CUT_OFF)
                    {
                        enumPowerReset = _POWER_RESET_ENABLE;
                    }
                    else
                    {
                        enumPowerReset = _POWER_RESET_DISABLE;
                    }

                    // Power Control
                    ScalerPowerGroupPowerCut(tGroupPowerCutOn[ucPowerGroup].pstPowerCutGroup[ucIndex].enumPowerGroup, enumPowerCut, enumPowerReset);

                    if(enumPowerCut == _POWER_CUT_OFF)
                    {
                        // Delay after power-cut disabled to allow full recovery
                        ScalerTimerDelayXms(5);
                    }

                    return _SUCCESS;
                }

                return _FAIL;
            }
        }
    }

    return _FAIL;
}
#endif // End of #if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)

