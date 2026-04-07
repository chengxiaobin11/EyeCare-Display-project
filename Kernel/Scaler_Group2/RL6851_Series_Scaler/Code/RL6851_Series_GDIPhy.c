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
// ID Code      : RL6851_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6851_SERIES_GDIPHY__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _GDI_PHY_POWER_PROC_DEBUG_MESSAGE       _OFF

#define _MHL_1K                                 7
#define _MHL_100K                               8

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
void ScalerGDIPhyBandgap(bit bSelect);

#if(_DIGITAL_PORT_SUPPORT == _ON)
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect);
void ScalerGDIPhyPowerProc(BYTE ucPortSelect, EnumPowerAction enumPowerAction);
void ScalerGDIPhyDigitalPhySwitch(BYTE ucInputPort);
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect);
void ScalerGDIPhyPower(BYTE ucPortSelect, EnumPowerAction enumPowerAction);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyBandgap(bit bSelect)
{
    if(bSelect == _ON)
    {
        // [5] en_clkdetect = 0 --> from hysteresis
        // [4] EN_ENHANCE_BIAS = 1 --> Enhance Clock Lane Input Buffer Bias Current
        ScalerSetBit(PB_B0_CLK_DET, ~(_BIT5 | _BIT4), _BIT4);

        // HDMI Clock Gating to Measure Block
        ScalerSetBit(P2_E1_AUX_PS_REPLY, ~_BIT7, _BIT7);

        // [2] reg_vco_lpf_force_en = 1'b0 --> Disable Force VCO LPF
        ScalerSetBit(PB_CF_ANA_CDR_00, ~_BIT2, 0x00);

        // [7] reg_en_vco_lpf = 1'b1 --> Enable VCO LPF (Disable when CP = 1 During FLD Calibration)
        // [5:4] en_vcm_tune = 2'b01 --> Vc = 0.5V
        ScalerSetBit(PB_D0_ANA_CDR_01, ~(_BIT7 | _BIT5 | _BIT4), (_BIT7 | _BIT4));

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && ((_D0_DP_CONNECTOR_TYPE == _DP_CONNECTOR_TYPE_C) || (_D0_DP_Z0_IMPEDANCE_OPTION == _U3_90_OHM)))

        // [3:0] Z0_ADJR = 6 --> Z0 Differential Impedance = level 6
        ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));

#elif(_D0_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)

        // [3:0] Z0_ADJR = 5 --> Z0 Differential Impedance = level 5
        ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
#else
        // [3:0] Z0_ADJR = 8 --> Z0 Differential Impedance = level 8
        ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        // [0] Port0 Termination to GND
        ScalerSetBit(PB_B1_PORT_SEL, ~_BIT0, _BIT0);
#else
        // [0] Port0 Termination to VDD
        ScalerSetBit(PB_B1_PORT_SEL, ~_BIT0, 0x00);
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        // Enable Z0
        ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && ((_D1_DP_CONNECTOR_TYPE == _DP_CONNECTOR_TYPE_C) || (_D1_DP_Z0_IMPEDANCE_OPTION == _U3_90_OHM)))

        // [3:0] Z0_ADJR = 6 --> Z0 Differential Impedance = level 6
        ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));

#elif(_D1_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)

        // [3:0] Z0_ADJR = 5 --> Z0 Differential Impedance = level 5
        ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
#else
        // [3:0] Z0_ADJR = 8 --> Z0 Differential Impedance = level 8
        ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        // [1] Port1 Termination to GND
        ScalerSetBit(PB_B1_PORT_SEL, ~_BIT1, _BIT1);
#else
        // [1] Port1 Termination to VDD
        ScalerSetBit(PB_B1_PORT_SEL, ~_BIT1, 0x00);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        // Enable Z0
        ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
#endif
    }
}

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D0/D1 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect)
{
    switch(ucPortSelect)
    {
        case _D0_INPUT_PORT:

            if(bSelect == _ON)
            {
#if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)
                DebugMessageDigital("!!! D0 Z0 Switch ON -Flag-", 0x00);
#endif
                SET_DIGITAL_PORT_SWITCH_TO_D0();
            }
            else
            {
#if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)
                DebugMessageDigital("!!! D0 Z0 Switch OFF -Flag-", 0x00);
#endif
                CLR_DIGITAL_PORT_SWITCH_TO_D0();
            }

            if(bSelect == _ON)
            {
                if(ScalerGetBit(PB_B3_IMPEDANCE_00, _BIT3) == 0x00)
                {
#if(_D0_TMDS_SUPPORT == _ON)

                    SET_TMDS_Z0_ASSERTED();

                    // Clear HDCP Flag
                    ScalerSetBit(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT6 | _BIT5));

                    // Initialize DDC Detection Process
                    CLR_TMDS_RX0_DDC_DETECTED();

                    // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;
#endif

#endif // End of #if(_D0_TMDS_SUPPORT == _ON)

                    // Enable Z0
                    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
                }
            }
            else
            {
#if(_D0_TMDS_SUPPORT == _ON)

                // Disable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT3 | _BIT1);

#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                MCU_FFE5_DDC1_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif

                // Disable Z0
                ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

#endif
            }

            break;

        case _D1_INPUT_PORT:

            if(bSelect == _ON)
            {
#if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)
                DebugMessageDigital("!!! D1 Z0 Switch ON -Flag-", 0x00);
#endif
                SET_DIGITAL_PORT_SWITCH_TO_D1();
            }
            else
            {
#if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)
                DebugMessageDigital("!!! D1 Z0 Switch OFF -Flag-", 0x00);
#endif
                CLR_DIGITAL_PORT_SWITCH_TO_D1();
            }

            if(bSelect == _ON)
            {
                if(ScalerGetBit(PB_B4_IMPEDANCE_01, _BIT3) == 0x00)
                {
#if(_D1_TMDS_SUPPORT == _ON)

                    SET_TMDS_Z0_ASSERTED();

                    // Clear HDCP Flag
                    ScalerSetBit(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT6 | _BIT5));

                    // Initialize DDC Detection Process
                    CLR_TMDS_RX1_DDC_DETECTED();

                    // Enable DDC Toggle IRQ
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;
#endif

#endif // End of #if(_D1_TMDS_SUPPORT == _ON)

                    // Enable Z0
                    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
                }
            }
            else
            {
#if(_D1_TMDS_SUPPORT == _ON)

                // Disable DDC Toggle IRQ
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT3 | _BIT1);

#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                MCU_FFE5_DDC1_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif

                // Disable Z0
                ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

#endif
            }

            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Rx0 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerProc(BYTE ucPortSelect, EnumPowerAction enumPowerAction)
{
#if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)
    switch(enumPowerAction)
    {
        case _POWER_ACTION_OFF_TO_NORMAL:
            DebugMessageDigital("!!! GDI PHY Power Proc OFF_TO_NORMAL", ucPortSelect);
            break;

        case _POWER_ACTION_PS_TO_NORMAL:
            DebugMessageDigital("!!! GDI PHY Power Proc PS_TO_NORMAL", ucPortSelect);
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
            DebugMessageDigital("!!! GDI PHY Power Proc NORMAL_TO_OFF", ucPortSelect);
            break;

        case _POWER_ACTION_NORMAL_TO_PS:
            DebugMessageDigital("!!! GDI PHY Power Proc NORMAL_TO_PS", ucPortSelect);
            break;

        default:
            DebugMessageDigital("!!! GDI PHY Power Proc Other", enumPowerAction);
            break;
    }
#endif  // End of #if(_GDI_PHY_POWER_PROC_DEBUG_MESSAGE == _ON)

    ScalerGDIPhyPower(ucPortSelect, enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            switch(ucPortSelect)
            {
                case _D0_INPUT_PORT:

                    if(ScalerGetBit(PB_B3_IMPEDANCE_00, _BIT3) == _BIT3)
                    {
                        // Enable RGB Z0
                        ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
                    }

                    break;

                case _D1_INPUT_PORT:

                    if(ScalerGetBit(PB_B4_IMPEDANCE_01, _BIT3) == _BIT3)
                    {
                        // Enable RGB Z0
                        ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
                    }

                    break;

                default:
                    break;
            }

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

            switch(ucPortSelect)
            {
                case _D0_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _ON);

                    break;

                case _D1_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON);

                    break;

                default:

                    break;
            }

            break;

        case _POWER_ACTION_NORMAL_TO_PS:

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:

            switch(ucPortSelect)
            {
                case _D0_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);

#if((_D0_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
                    CLR_TMDS_RX0_TOGGLE_Z0();
                    CLR_TMDS_RX0_TOGGLE_Z0_EVENT();
#endif
                    break;

                case _D1_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);

#if((_D1_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
                    CLR_TMDS_RX1_TOGGLE_Z0();
                    CLR_TMDS_RX1_TOGGLE_Z0_EVENT();
#endif
                    break;

                default:
                    break;
            }

            break;

        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:

            switch(ucPortSelect)
            {
                case _D0_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);

                    break;

                case _D1_INPUT_PORT:

                    ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);

                    break;

                default:
                    break;
            }

            break;

        default:

            break;
    }
}


//-------------------------------------------------------------
// Description  : GDI Digital PHY Switch (DP to TMDS; HDMI/MHL)
// Input Value  : InputPortType
// Output Value : None
//-------------------------------------------------------------
void ScalerGDIPhyDigitalPhySwitch(BYTE ucInputPort)
{
    ScalerGDIPhy2DSwitch(ucInputPort);
/*
    // remove Z0 always enable due to version-C solve interference
    if(ScalerGlobalGetIDCode() < _RL6851_VER_C_ID_CODE)
    {
        // RL6851 DP/HDMI has interference issue, need turn on another port's Z0.
        switch(ucInputPort)
        {
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D0_INPUT_PORT:

                // Enable Port 1 Z0
                ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D1_INPUT_PORT:
                // Enable Port 0 Z0
                ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
                break;
#endif

            default:
                break;
        }
    }
*/

    /////////////////
    // DP --> TMDS //
    /////////////////

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    if(((_D0_INPUT_PORT_TYPE != _D0_DP_PORT) && (ucInputPort == _D0_INPUT_PORT)) ||
       ((_D1_INPUT_PORT_TYPE != _D1_DP_PORT) && (ucInputPort == _D1_INPUT_PORT)))
    {
        // Current SI at DP
        if(ScalerGetBit(PB_B1_PORT_SEL, _BIT5) != 0x00)
        {
            // Disable Rx_En and CMU_En
            ScalerSetByte(PB_B2_ENABLE, 0x00);

            // Disable CMU PLL
            ScalerSetBit(PB_B0_CLK_DET, ~_BIT2, 0x00);

            // Disable Auto K-offset
            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), 0x00);

            switch(ucInputPort)
            {
                case _D0_INPUT_PORT:

                    CLR_DIGITAL_PORT_SWITCH_TO_D0();

                    // Disable Port 0 Z0
                    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                    break;

                case _D1_INPUT_PORT:

                    CLR_DIGITAL_PORT_SWITCH_TO_D1();

                    // Disable Port 1 Z0
                    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                    break;

                default:

                    break;
            }

            // Analog Select to HDMI
            ScalerSetBit(PB_B1_PORT_SEL, ~_BIT5, 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB_A5_DIG_05, ~_BIT7, _BIT7);
            ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, _BIT0);
        }

        // [3] PSM = 1'b1 --> Enable HDMI Clock Switch
        ScalerSetBit(PB_B0_CLK_DET, ~_BIT3, _BIT3);

        // Enable Clock Lane Rx_En
        ScalerSetBit(PB_B2_ENABLE, ~_BIT7, _BIT7);

        // dp_bbpd_sel[5:4] --> ACDR BBPD UP/DN from MAC Lane0
        ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), 0x00);
    }
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
}


//--------------------------------------------------
// Description  : GDI 2D Switch
// Input Value  : D0/D1 Port Select
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect)
{
    switch(ucPortSelect)
    {
        case _D0_INPUT_PORT:

            if(ScalerGetBit(PB_B1_PORT_SEL, _BIT7) != 0x00)
            {
                // Switch to Port 0
                ScalerSetBit(PB_B1_PORT_SEL, ~_BIT7, 0x00);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
                CLR_TMDS_PHY_SET();

                g_usTMDSClkCount = 0;

                // SET KEY ready bit 0
                ScalerSetBit(P2_AE_TMDS_RPS, ~(_BIT1), 0x00);
#endif
            }

            break;

        case _D1_INPUT_PORT:

            if(ScalerGetBit(PB_B1_PORT_SEL, _BIT7) != _BIT7)
            {
                // Switch to Port 1
                ScalerSetBit(PB_B1_PORT_SEL, ~_BIT7, _BIT7);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
                CLR_TMDS_PHY_SET();

                g_usTMDSClkCount = 0;

                // SET KEY ready bit 0
                ScalerSetBit(P2_AE_TMDS_RPS, ~(_BIT1), 0x00);
#endif
            }

            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Power On/Off
// Input Value  : PowerAction (Normal/PS/OFF)
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPower(BYTE ucPortSelect, EnumPowerAction enumPowerAction)
{
    ucPortSelect = ucPortSelect;

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ///////////////////////
            ///Offset Calibration//
            ///////////////////////

            // [7] EN_FORE_OFFSET = 1'b0 --> Disable K-offset
            // [6] Disable Auto K-offset Auto Mode
            ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), 0x00);

            // [7:6] offcal_range = 2'b11 --> 75uA
            ScalerSetBit(PB_C7_KOFFSET_00, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            // [7:5] tap_en = 3'b111 --> Eable Passive EQ
            ScalerSetBit(PB_CB_KOFFSET_04, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // [7] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [6] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB_B0_CLK_DET, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));


            /////////////
            //Reset PHY//
            /////////////

            // [3:0] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB_A0_DIG_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

            // [1] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_AB_SDM_04, ~_BIT1, _BIT1);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_AD_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_AE_DATA_TIMER, ~_BIT1, _BIT1);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            ScalerTMDSPowerSavingProc(ucPortSelect);
#endif

#if(_HDMI_SUPPORT == _ON)
            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB_B2_ENABLE, 0x80);
#else
            // Disable All RX_EN and CDR_EN
            ScalerSetByte(PB_B2_ENABLE, 0x00);
#endif
            // Disable Auto k-offset
            // Disable Auto k-offset auto mode
            ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), 0x00);

            // [2] cmu_en = 1'b0 --> Disable CMU PLL
            ScalerSetBit(PB_B0_CLK_DET, ~_BIT2, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

            switch(ucPortSelect)
            {
                default:
                case _D0_INPUT_PORT:

#if(_D0_TMDS_SUPPORT == _ON)
                    // Disable RGB Z0
                    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif

                    break;

                case _D1_INPUT_PORT:

#if(_D1_TMDS_SUPPORT == _ON)
                    // Disable RGB Z0
                    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#endif

                    break;
            }
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            ScalerTMDSPowerOffProc();
#endif

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB_B2_ENABLE, 0x00);

            // Disable Auto k-offset
            // Disable Auto k-offset auto mode
            ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), 0x00);

            // [2] cmu_en = 1'b0 --> Disable CMU PLL
            ScalerSetBit(PB_B0_CLK_DET, ~_BIT2, 0x00);

            // [7] n_channel_en = 0 --> Switch n Channel 50ohm Z0
            // [6] p_channel_en = 0 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB_B0_CLK_DET, ~(_BIT7 | _BIT6), 0x00);

            // [3] PSM = 1'b0 --> Disable HDMI Clock Switch
            ScalerSetBit(PB_B0_CLK_DET, ~_BIT3, 0x00);

            break;

        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        default:

            break;
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
