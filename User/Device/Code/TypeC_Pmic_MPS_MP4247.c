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
// ID Code      : TypeC_Pmic_MPS_MP4247.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "UserCommonInclude.h"

#if(_TYPE_C_PMIC_TYPE == _PMIC_MP4247)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Register Addresss
//--------------------------------------------------
#define _MP4247_OPEARTION                           0x01
#define _MP4247_CLEAR_FAULTS                        0x03
#define _MP4247_VOUT_COMMAND                        0x21
#define _MP4247_STATUS_WORD                         0x79
#define _MP4247_STATUS_TEMPERATURE                  0x7D
#define _MP4247_MFR_CTRL1                           0xD0
#define _MP4247_MFR_CURRENT_LIMIT                   0xD1
#define _MP4247_MFR_CTRL2                           0xD2
#define _MP4247_MFR_CTRL3                           0xD3
#define _MP4247_MFR_CTRL4                           0xD4
#define _MP4247_MFR_STATUS_MASK                     0xD8
#define _MP4247_MFR_OTP_CONFIGURATION_CODE          0xD9
#define _MP4247_MFR_OTP_REVISION_NUMBER             0xDA
#define _MP4247_REGISTER_END                        0xFF

//--------------------------------------------------
// Register Addresss
//--------------------------------------------------
#define _MP4247_SUBADDR_LENGTH                      0x01
#define _MP4247_DATA_LENGTH_1                       0x01
#define _MP4247_DATA_LENGTH_2                       0x02

//--------------------------------------------------
// Definitions of Voltage(250mV)
//--------------------------------------------------
#define _MP4247_OUTPUT_VOL_0V                       0x0000
#define _MP4247_OUTPUT_VOL_3V                       0x000C
#define _MP4247_OUTPUT_VOL_5V                       0x0014
#define _MP4247_OUTPUT_VOL_7V                       0x001C
#define _MP4247_OUTPUT_VOL_9V                       0x0024
#define _MP4247_OUTPUT_VOL_12V                      0x0030
#define _MP4247_OUTPUT_VOL_15V                      0x003C
#define _MP4247_OUTPUT_VOL_20V                      0x0050

//--------------------------------------------------
// Definitions of Current(Rsense 10m ohm)
//--------------------------------------------------
#define _MP4247_OUTPUT_CURRENT_LIMIT_1_0A           0x14
#define _MP4247_OUTPUT_CURRENT_LIMIT_1_5A           0x1E
#define _MP4247_OUTPUT_CURRENT_LIMIT_2_0A           0x28
#define _MP4247_OUTPUT_CURRENT_LIMIT_2_5A           0x32
#define _MP4247_OUTPUT_CURRENT_LIMIT_3_0A           0x3C
#define _MP4247_OUTPUT_CURRENT_LIMIT_3_25A          0x41
#define _MP4247_OUTPUT_CURRENT_LIMIT_3_5A           0x46
#define _MP4247_OUTPUT_CURRENT_LIMIT_4_0A           0x50
#define _MP4247_OUTPUT_CURRENT_LIMIT_4_5A           0x5A
#define _MP4247_OUTPUT_CURRENT_LIMIT_5_0A           0x64

//--------------------------------------------------
// Definitions of Operation Mode
//--------------------------------------------------
#define _MP4247_MODE_OFF                            0x00
#define _MP4247_MODE_ON                             0x80

//--------------------------------------------------
// Definitions of Discharge Control
//--------------------------------------------------
#define _MP4247_DISCHANGE_DISABLE                   0x00
#define _MP4247_DISCHANGE_ENABLE                    0x01

//--------------------------------------------------
// Macros of PMIC Default STATUS
//--------------------------------------------------
#define _MP4247_OPEARTION_DEFAULT                   0x00
#define _MP4247_VOUT_COMMAND_DEFAULT                _MP4247_OUTPUT_VOL_5V
#define _MP4247_MFR_CTRL1_DEFAULT                   0x2F
#define _MP4247_MFR_CURRENT_LIMIT_DEFAULT           0x3C
#define _MP4247_MFR_CTRL2_DEFAULT                   0x00
#define _MP4247_MFR_CTRL3_DEFAULT                   0x84 // Select the Rsens resistor value: 0: 5mo, Default; 1: 10mo
#define _MP4247_MFR_CTRL4_DEFAULT                   0x27
#define _MP4247_MFR_STATUS_MASK_DEFAULT             0xBF


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE ucOperation; // 0x01 OPERATION  0x00 OFF , 0x80 ON
    WORD usVoutCommand; // 0x21 VOUT_COMMAND
    BYTE ucMfrCtrl1; // 0xD0 MFR_CTRL1
    BYTE ucMfrCurrentLimit; // 0xD1 MFR_CURRENT_LIMIT
    BYTE ucMfrCtrl2; // 0xD2 MFR_CTRL2
    BYTE ucMfrCtrl3; // 0xD3 MFR_CTRL3
    BYTE ucMfrCtrl4; // 0xD4 MFR_CTRL4
    BYTE ucMfrStatusMask; // 0xD8 MFR_STATUS_MASK
} StructMP4247RegisterMap;


//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tPMIC_MP4247_ADDRESS_TABLE[][2] =
{
    {_MP4247_OPEARTION,                 _MP4247_DATA_LENGTH_1},
    {_MP4247_VOUT_COMMAND,              _MP4247_DATA_LENGTH_2},
    {_MP4247_MFR_CTRL1,                 _MP4247_DATA_LENGTH_1},
    {_MP4247_MFR_CURRENT_LIMIT,         _MP4247_DATA_LENGTH_1},
    {_MP4247_MFR_CTRL2,                 _MP4247_DATA_LENGTH_1},
    {_MP4247_MFR_CTRL3,                 _MP4247_DATA_LENGTH_1},
    {_MP4247_MFR_CTRL4,                 _MP4247_DATA_LENGTH_1},
    {_MP4247_MFR_STATUS_MASK,           _MP4247_DATA_LENGTH_1},
    {_MP4247_REGISTER_END,              0x00},
};

StructMP4247RegisterMap code tPMIC_MP4247_INITIAL_TABLE =
{
    _MP4247_OPEARTION_DEFAULT,
    _MP4247_VOUT_COMMAND_DEFAULT,
    _MP4247_MFR_CTRL1_DEFAULT,
    _MP4247_MFR_CURRENT_LIMIT_DEFAULT,
    _MP4247_MFR_CTRL2_DEFAULT,
    _MP4247_MFR_CTRL3_DEFAULT,
    _MP4247_MFR_CTRL4_DEFAULT,
    _MP4247_MFR_STATUS_MASK_DEFAULT,
};


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructMP4247RegisterMap g_pstPmicMp4247Data;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ExternalDeviceInterfaceTypeCPmicACOnInitial(void);
void ExternalDeviceInterfaceTypeCPmicUnattachReset(void);
void ExternalDeviceInterfaceTypeCPmicUnattachReset_EXINT0(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_EXINT0(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_WDINT(void);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_EXINT0(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(EnumTypeCPmicDischarge enumEn);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_EXINT0(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_WDINT(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType);
EnumTypeCPmicOperationMode ExternalDeviceInterfaceTypeCPmicReadPpsOperationModeStatus_EXINT0(void);
#endif
#if(_TYPE_C_PMIC_DEBUG == _ON)
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicDebugCheckStatus(void);
#endif
#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)
WORD ExternalDeviceInterfaceTypeCPmicReadPmicAdcCurrentValue(void);
#endif


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : PMIC Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicACOnInitial(void)
{
    // Enable Pin Control
    PCB_PMIC_POWER(_POWER_ON);

    g_pstPmicMp4247Data = tPMIC_MP4247_INITIAL_TABLE;

    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL2, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl2));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL3, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl3));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL4, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl4));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_STATUS_MASK, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrStatusMask));
}

//--------------------------------------------------
// Description  : PMIC Reset Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicUnattachReset(void)
{
    // Set PMIC Data initial value
    g_pstPmicMp4247Data = tPMIC_MP4247_INITIAL_TABLE;

    // Initial Pmic Value
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL2, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl2));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL3, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl3));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL4, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl4));
    ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_STATUS_MASK, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrStatusMask));
}

//--------------------------------------------------
// Description  : PMIC Reset Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ExternalDeviceInterfaceTypeCPmicUnattachReset_EXINT0(void) using 1
{
    // Set PMIC Data initial value
    g_pstPmicMp4247Data = tPMIC_MP4247_INITIAL_TABLE;

    // Initial Pmic Value
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL2, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl2));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL3, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl3));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL4, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl4));
    ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_STATUS_MASK, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrStatusMask));
}


//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent)
{
    if(usVoltage > 2000) // maximum 20V
    {
        usVoltage = 2000;
    }

    // -------------------------
    // Operation Mode Setting
    // -------------------------
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_ON;

    if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
    {
        // ---------------------
        // Voltage Setting
        // ---------------------

        if(usVoltage <= (300))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;
        }
        else if(usVoltage <= (500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;
        }
        else if(usVoltage <= (900))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_9V;
        }
        else if(usVoltage <= (1200))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_12V;
        }
        else if(usVoltage <= (1500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_15V;
        }
        else if(usVoltage <= (2000))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_20V;
        }

        if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }

        // ---------------------
        // Current Setting
        // ---------------------

        if(usCurrent <= 100) // < 1A (unit: 10mA)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_0A);
        }
        else if(usCurrent <= 150)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_5A);
        }
        else if(usCurrent <= 200)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_0A);
        }
        else if(usCurrent <= 250)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_5A);
        }
        else if(usCurrent <= 300)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_0A);
        }
        else if(usCurrent <= 325)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_25A);
        }
        else if(usCurrent <= 350)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_5A);
        }
        else if(usCurrent <= 400)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_0A);
        }
        else if(usCurrent <= 450)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_5A);
        }
        else
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A);
        }

        g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A); // fix 50MV

        if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent) using 1
{
    if(usVoltage > 2000) // maximum 20V
    {
        usVoltage = 2000;
    }

    // -------------------------
    // Operation Mode Setting
    // -------------------------
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_ON;

    if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
    {
        // ---------------------
        // Voltage Setting
        // ---------------------

        if(usVoltage <= (300))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_3V;
        }
        else if(usVoltage <= (500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;
        }
        else if(usVoltage <= (900))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_9V;
        }
        else if(usVoltage <= (1200))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_12V;
        }
        else if(usVoltage <= (1500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_15V;
        }
        else if(usVoltage <= (2000))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_20V;
        }

        if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }

        // ---------------------
        // Current Setting
        // ---------------------

        if(usCurrent <= 100) // < 1A (unit: 10mA)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_0A);
        }
        else if(usCurrent <= 150)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_5A);
        }
        else if(usCurrent <= 200)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_0A);
        }
        else if(usCurrent <= 250)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_5A);
        }
        else if(usCurrent <= 300)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_0A);
        }
        else if(usCurrent <= 325)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_25A);
        }
        else if(usCurrent <= 350)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_5A);
        }
        else if(usCurrent <= 400)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_0A);
        }
        else if(usCurrent <= 450)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_5A);
        }
        else
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A);
        }

        g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A); // fix 50MV

        if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Control PMIC to Directed Voltage
// Input Value  : bPowerDirection : _PD_POWER_SNK / _PD_POWER_SRC
//                usVoltage : 300 ~ 2100 (Unit = 10mV)
//                usCurrent : 0 ~ 500 (Unit = 10mA)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVoltageCurrentSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, WORD usVoltage, WORD usCurrent) using 3
{
    if(usVoltage > 2000) // maximum 20V
    {
        usVoltage = 2000;
    }

    // -------------------------
    // Operation Mode Setting
    // -------------------------
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_ON;

    if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
    {
        // ---------------------
        // Voltage Setting
        // ---------------------

        if(usVoltage <= (300))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_3V;
        }
        else if(usVoltage <= (500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;
        }
        else if(usVoltage <= (900))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_9V;
        }
        else if(usVoltage <= (1200))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_12V;
        }
        else if(usVoltage <= (1500))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_15V;
        }
        else if(usVoltage <= (2000))
        {
            g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_20V;
        }

        if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }

        // ---------------------
        // Current Setting
        // ---------------------

        if(usCurrent <= 100) // < 1A (unit: 10mA)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_0A);
        }
        else if(usCurrent <= 150)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_1_5A);
        }
        else if(usCurrent <= 200)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_0A);
        }
        else if(usCurrent <= 250)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_2_5A);
        }
        else if(usCurrent <= 300)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_0A);
        }
        else if(usCurrent <= 325)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_25A);
        }
        else if(usCurrent <= 350)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_3_5A);
        }
        else if(usCurrent <= 400)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_0A);
        }
        else if(usCurrent <= 450)
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_4_5A);
        }
        else
        {
            g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A);
        }

        g_pstPmicMp4247Data.ucMfrCurrentLimit = ((g_pstPmicMp4247Data.ucMfrCurrentLimit & _BIT7) | _MP4247_OUTPUT_CURRENT_LIMIT_5_0A); // fix 50MV

        if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CURRENT_LIMIT, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCurrentLimit)) == _FAIL)
        {
            return _TYPE_C_PMIC_CONTROL_FAIL;
        }
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff(void)
{
    // Set operation mode
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_OFF;

    if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    // Set PMIC output 5V, avoid Hard Reset Peak Voltage
    g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;

    if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_EXINT0(void) using 1
{
    // Set operation mode
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_OFF;

    if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    // Set PMIC output 5V, avoid Hard Reset Peak Voltage
    g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;

    if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : Turn off PMIC
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicTurnOff_WDINT(void) using 3
{
    // Set operation mode
    g_pstPmicMp4247Data.ucOperation = _MP4247_MODE_OFF;

    if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_OPEARTION, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucOperation)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    // Set PMIC output 5V, avoid Hard Reset Peak Voltage
    g_pstPmicMp4247Data.usVoutCommand = _MP4247_OUTPUT_VOL_5V;

    if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_VOUT_COMMAND, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_2, (BYTE *)(&g_pstPmicMp4247Data.usVoutCommand)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge(EnumTypeCPmicDischarge enumEn)
{
    // Set PMIC VBUS Discharge status
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_ENABLE << 1));
    }
    else
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_DISABLE << 1));
    }

    // PCB Control
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_ON);
    }
    else
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_OFF);
    }

    // Disable Pmic VBUS Discharge
    if(ScalerTypeCPmicIICWrite(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_EXINT0(EnumTypeCPmicDischarge enumEn) using 1
{
    // Set PMIC VBUS Discharge status
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_ENABLE << 1));
    }
    else
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_DISABLE << 1));
    }

    // PCB Control
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_ON);
    }
    else
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_OFF);
    }

    // Disable Pmic VBUS Discharge
    if(ScalerTypeCPmicIICWrite_EXINT0(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC VBUS Discharge Control
// Input Value  : enumEn : _ENABLE / _DISABLE
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicVbusDischarge_WDINT(EnumTypeCPmicDischarge enumEn) using 3
{
    // Set PMIC VBUS Discharge status
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_ENABLE << 1));
    }
    else
    {
        g_pstPmicMp4247Data.ucMfrCtrl1 = ((g_pstPmicMp4247Data.ucMfrCtrl1 & ~(_BIT1)) | (_MP4247_DISCHANGE_DISABLE << 1));
    }

    // PCB Control
    if(enumEn == _TYPE_C_PMIC_DISCHARGE_ENABLE)
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_ON);
    }
    else
    {
        PCB_VBUS_DISCHARGE_CONTROL(_VBUS_DISCHARGE_OFF);
    }

    // Disable Pmic VBUS Discharge
    if(ScalerTypeCPmicIICWrite_WDINT(_TYPE_C_RX0_PMIC_SLAVE_ADDRESS, _MP4247_MFR_CTRL1, _MP4247_SUBADDR_LENGTH, _MP4247_DATA_LENGTH_1, (BYTE *)(&g_pstPmicMp4247Data.ucMfrCtrl1)) == _FAIL)
    {
        return _TYPE_C_PMIC_CONTROL_FAIL;
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection)
{
    // PCB Control
    if(enumSwitchControl == _TYPE_C_PMIC_SWITCH_CONTROL_ENABLE)
    {
        if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
        {
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
        }
    }
    else
    {
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_EXINT0(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection) using 1
{
    // PCB Control
    if(enumSwitchControl == _TYPE_C_PMIC_SWITCH_CONTROL_ENABLE)
    {
        if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
        {
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
        }
    }
    else
    {
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Switch Control
// Input Value  : enumSwitchControl : _ENABLE / _DISABLE
//                enumPowerDirection : _SRC / _SNK
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicSwitchControl_WDINT(EnumTypeCPmicSwitchControl enumSwitchControl, EnumTypeCPmicDirection enumPowerDirection) using 3
{
    // PCB Control
    if(enumSwitchControl == _TYPE_C_PMIC_SWITCH_CONTROL_ENABLE)
    {
        if(enumPowerDirection == _TYPE_C_PMIC_DIRECTION_SRC)
        {
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_OFF);
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_ON);
        }
        else
        {
            PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
            PCB_PMIC_VBUS_SINK_CONTROL(_VBUS_SINK_SWITCH_ON);
        }
    }
    else
    {
        PCB_PMIC_VBUS_SOURCE_CONTROL(_VBUS_SOURCE_SWITCH_OFF);
    }

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumOutputMode : Output Mode (Fixed Voltage/PPS)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType)
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumOutputMode : Output Mode (Fixed Voltage/PPS)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_EXINT0(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType) using 1
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Output Mode Setting
// Input Value  : enumOutputMode : Output Mode (Fixed Voltage/PPS)
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicPpsOutputModeSetting_WDINT(EnumTypeCPmicDirection enumPowerDirection, EnumPDPdoType enumOutputPdoType) using 3
{
    enumPowerDirection = enumPowerDirection;
    enumOutputPdoType = enumOutputPdoType;

    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}

//--------------------------------------------------
// Description  : PMIC Read Output Status
// Input Value  : None
// Output Value : Output Mode (Fixed Voltage/PPS)
//--------------------------------------------------
EnumTypeCPmicOperationMode ExternalDeviceInterfaceTypeCPmicReadPpsOperationModeStatus_EXINT0(void) using 1
{
    return _TYPE_C_PMIC_NONE_MODE_OPERATION;
}
#endif // End of #if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)

#if(_TYPE_C_PMIC_DEBUG == _ON)
//--------------------------------------------------
// Description  : PMIC Status
// Input Value  : None
// Output Value : Control result (Fail/Success)
//--------------------------------------------------
EnumTypeCPmicControlResult ExternalDeviceInterfaceTypeCPmicDebugCheckStatus(void)
{
    return _TYPE_C_PMIC_CONTROL_SUCCESS;
}
#endif // End of #if(_TYPE_C_PMIC_DEBUG == _ON)

#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)
//--------------------------------------------------
// Description  : PMIC VBUS Current Reading
// Input Value  : None
// Output Value : usCurrent : 0 ~ 500 (Unit = 10mA)
//--------------------------------------------------
WORD ExternalDeviceInterfaceTypeCPmicReadPmicAdcCurrentValue(void)
{
    return 0;
}
#endif // End of #if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_POLLING_PMIC)

#endif // End of #if(_TYPE_C_PMIC_TYPE == _PMIC_MP4247)

