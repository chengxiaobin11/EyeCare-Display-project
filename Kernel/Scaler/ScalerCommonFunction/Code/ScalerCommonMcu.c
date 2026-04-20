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
// ID Code      : ScalerCommonMcu.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_MCU__

#include "ScalerCommonFunctionInclude.h"
#if ((_AI_EYE_PROTECTION == _ON)||(_AI_LIGHT_ADAPTIVATION == _ON)||(_AI_LOW_POWER == _ON))
#include "RTD2014Include.h"
#endif

#if(_MT3212_CT_SUPPORT == _ON)
#include _OSD_INCLUDE
#endif

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions DDCCI Protocol Items
//--------------------------------------------------
#define _DDCCI_LENGTH                       1

//--------------------------------------------------
// Definitions of Hardware IIC
//--------------------------------------------------
#define _HW_IIC_BUFFER_SIZE                 24
#define _HW_IIC_DELAY_TIME                  5

//--------------------------------------------------
// Definitions of Software IIC
//--------------------------------------------------
#define _IIC_POLLING_TIME                   240

#if((_INSTANT_TIMER_EVENT_1 == _ON) && (_UART_SUPPORT == _ON))
#error "Instant Timer1 cannot be used when UART is supported"
#endif

//--------------------------------------------------
// Definitions DDCCI Protocol Items
//--------------------------------------------------
#define _DDCCI_BUFFER_SIZE                  32

// If User Don't Want to Save Tx Buf Size, Reduce the Available DDCCI Buf Size
#if(_DDCCI_TXBUF_LENGTH < _DDCCI_BUFFER_SIZE)
#undef _DDCCI_BUFFER_SIZE
#define _DDCCI_BUFFER_SIZE                  _DDCCI_TXBUF_LENGTH
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_HW_IIC_SUPPORT == _ON)
StructHwI2cSettingData code tHwI2cSetting[] =
{
    // KERNAL _HW_IIC_LOW_SPEED_100K PARAMETWRS
    {0x26, 0x22, 0x2F, 0x2F, 0x36, 0x47, 0x03, 0x01, 0x02,},
    // KERNAL _HW_IIC_HIGH_SPEED_400K PARAMETWRS
    {0x0C, 0x04, 0x0E, 0x06, 0x09, 0x23, 0x03, 0x01, 0x02,},

#if(_HW_IIC_PAR_BY_USER_SUPPORT == _ON)
// Incldue User Paramters Setting
#include _USER_HW_IIC_PAR_INCLUDE
#endif
};
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//sfr CKCON = 0x8E;

BYTE idata g_ucDdcciCountEXINT;

BYTE data g_ucDelay5usN_Base = 1;
BYTE data g_ucDelayXusN_Base = 1;
BYTE data g_ucDelay5usI = 1;
BYTE data g_ucDelay5usI_EXINT = 1;
BYTE data g_ucDelayXus_Counter = 1;
BYTE data g_ucDelayXus_Counter_EXINT = 1;

bit g_bRunDdcciCommand = _FAIL;
bit g_bSrcReadDdcciAlready = _FAIL;
#if(_DDCCI_AUTO_SWITCH_SUPPORT == _ON)
bit g_bReceiveDdcciCmdNotFinish = _FAIL;
#endif
EnumDdcciCmdSrc g_enumDdcciCommandSrc = _DDCCI_CMD_SRC_I2C;

BYTE g_pucDdcciRxBuf[_DDCCI_RXBUF_LENGTH];
BYTE g_pucDdcciTxBuf[_DDCCI_TXBUF_LENGTH];

BYTE g_pucDdcciRxBackBuf[16];

BYTE g_ucDdcciCmdLengthBack;

BYTE g_ucMcuDdcciRetry;

#if(_SW_IIC_SUPPORT == _ON)
BYTE idata g_ucSwIICStatus;
#endif

#if(_DUAL_BANK_SUPPORT == _ON)
BYTE data g_ucMcuBankOffset                               _at_     0x30;
#endif

#if(_HW_IIC_SUPPORT == _ON)
BYTE g_ucHwI2cSettingIndex = _HW_IIC_SPEED;
#endif
#if _EYE_VLI_SUPPORT
extern WORD g_ucTimerCount_EyeProtect;
#endif
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMcuCacheControl(bit bControl);
void ScalerMcuDdcciSendData(BYTE *pucWriteArray);

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
void ScalerMcuDdcciSetData(BYTE *pucReadArray, BYTE ucLength, EnumDdcciCmdSrc enumDdcciCmdSrc);
#endif

#if(_DDCCI_CODE_REDUCTION == _OFF)
BYTE ScalerMcuDdcciGetBufferSize(void);

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE ScalerMcuDdcciGetInputPort_EXINT1(void);
#endif
#endif
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
BYTE ScalerMcuDdcciIntGetData_EXINT1(BYTE *pucReadArray);
#endif

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv);
void ScalerMcuSwitchFlashMcuFastSpeed(bit bEnable);
#endif

#if(_SYSTEM_LOW_POWER_IDLE_SUPPORT == _ON)
void ScalerMcuIntoIdle(void);
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
void ScalerMcuSarAdcClkSel(EnumClkSel enumClock);
#endif

#if(_PWM_FUNCTION_SUPPORT == _ON)
void ScalerMcuPwmClockSel(EnumClkSel enumClock);
void ScalerMcuPwmAdjustResetByDvs(BYTE ucPwmType, bit bStatus);
bit ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency);
#endif

void ScalerMcu5usDelayCalc(EnumClkSel enumClock);

#if(_SW_IIC_SUPPORT == _ON)
BYTE ScalerMcuIICStart(BYTE ucSlaveAddr);
void ScalerMcuIICStop(void);
BYTE ScalerMcuIICGetAck(void);
void ScalerMcuIICSendAck(void);
void ScalerMcuIICSendNoAck(void);
BYTE ScalerMcuIICGetByte(void);
BYTE ScalerMcuIICSendByte(BYTE ucValue);
bit ScalerMcuIICWriteStart(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr);
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON || _HDMI_24C02_SUPPORT)
bit ScalerMcuIICWritePolling(BYTE ucSlaveAddr);
#endif
bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr, WORD usLength, BYTE *pucReadArray);
bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr, WORD usLength, BYTE *pucWriteArray);
#endif

#if(_HW_IIC_SUPPORT == _ON)
void ScalerMcuHwIICConfigSetting(EnumHWIICParType enumParType);
void ScalerMcuHwIICInitial(void);
void ScalerMcuHwIICSetFreqDiv(EnumClkSel enumClock);
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON || _HDMI_24C02_SUPPORT)
bit ScalerMcuHwIICWritePolling(BYTE ucSlaveAddr, BYTE ucSubAddrLength, BYTE ucHwIICPinNum);
#endif
bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucReadArray, BYTE ucHwIICPinNum);
bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucWriteArray, BYTE ucHwIICPinNum);
#endif

#if(_UART_SUPPORT == _ON)
bit ScalerMcuUartWrite(BYTE ucValue);
#endif

void ScalerMcuIspInitial(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Cache Control
// Input Value  : bControl
// Output Value : None
//--------------------------------------------------
void ScalerMcuCacheControl(bit bControl)
{
    if(bControl == _ENABLE)
    {
        // Enable Cache
        MCU_FDA0_CACHE_FUNCTION |= _BIT0;
    }
    else
    {
        // Disable Cache
        MCU_FDA0_CACHE_FUNCTION &= ~_BIT0;
    }
}

//--------------------------------------------------
// Description  : Send DDC Data
// Input Value  : pWriteArray --> Data to be sent
//                usTimeOutCnt --> Timeout
// Output Value : None
//--------------------------------------------------


void ScalerMcuDdcciSendData(BYTE *pucWriteArray)
{
    WORD usTimeOutCnt = _DDCCI_TIMEOUT_LIMIT;
    BYTE ucDdcciCount = 0;


    if((MCU_FF27_IIC_STATUS & _BIT0) == _BIT0)
    {
        g_bSrcReadDdcciAlready = _TRUE;

        // Clear Flag
        MCU_FF27_IIC_STATUS &= ~_BIT0;
    }

    // Enable mcu write
    MCU_FF2A_IIC_IRQ_CONTROL2 |= (_BIT6 | _BIT5);

#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
    if(GET_SMBUS_BLOCK_RW_STATUS() == _TRUE)
    {
        MCU_FF26_IIC_DATA_OUT = g_stSmbusBlockRWCmd.ucDataLen;
    }
#endif

    while(ucDdcciCount < ((pucWriteArray[_DDCCI_LENGTH] & 0x7F) + 3))
    {
        // Load data to DDC-CI buffer until buffer full
        if((MCU_FF29_IIC_STATUS2 & _BIT2) == 0)
        {
            MCU_FF26_IIC_DATA_OUT = pucWriteArray[ucDdcciCount++];

            usTimeOutCnt = _DDCCI_TIMEOUT_LIMIT;
        }
        else
        {
            ScalerTimerDelayXms(2);

            usTimeOutCnt--;
        }

        if(usTimeOutCnt == 0)
        {
            break;
        }
    }

    // Disable mcu write
    MCU_FF2A_IIC_IRQ_CONTROL2 &= ~_BIT5;
}

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Set DDC Data
// Input Value  : *pucReadArray, ucLength, enumDdcciCmdSrc
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcciSetData(BYTE *pucReadArray, BYTE ucLength, EnumDdcciCmdSrc enumDdcciCmdSrc)
{
    memcpy(g_pucDdcciRxBuf, pucReadArray, ucLength);

    SET_RUN_DDCCI_COMMAND(_SUCCESS);
    SET_RUN_DDCCI_COMMAND_SRC(enumDdcciCmdSrc);
}
#endif

#if(_DDCCI_CODE_REDUCTION == _OFF)
//--------------------------------------------------
// Description  : Get DDC Buffer Size
// Input Value  : None
// Output Value : DDCCI Buffer Size
//--------------------------------------------------
BYTE ScalerMcuDdcciGetBufferSize(void)
{
    return _DDCCI_BUFFER_SIZE;
}

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get InputPort by checking Active DDC Channel for Ddccci
// Input Value  : None
// Output Value : InputPort
//--------------------------------------------------
BYTE ScalerMcuDdcciGetInputPort_EXINT1(void) using 2
{
    BYTE ucInput = _NO_INPUT_PORT;

    switch(GET_DDC_CHANNEL())
    {
        case _VGA_DDC2:
        case _VGA_DDC:
            ucInput = _A0_INPUT_PORT;
            break;

        case _DDC0:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC0))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC0))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC0)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC0)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC0)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC0)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC0)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC0)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC0))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        case _DDC1:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC1))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC1))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC1)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC1)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC1)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC1)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC1)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC1)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC1))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        case _DDC2:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC2))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC2))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC2)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC2)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC2)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC2)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC2)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC2)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC2))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        case _DDC3:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC3))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC3))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC3)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC3)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC3)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC3)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC3)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC3)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC3))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        case _DDC4:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC4))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC4))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC4)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC4)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC4)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC4)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC4)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC4)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC4))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        case _DDC5:
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _DDC5))
            ucInput = _D0_INPUT_PORT;
#elif((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _DDC5))
            ucInput = _D1_INPUT_PORT;
#elif(((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _DDC5)) ||\
      ((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC5)))
            ucInput = _D2_INPUT_PORT;
#elif(((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _DDC5)) ||\
      ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC5)))
            ucInput = _D3_INPUT_PORT;
#elif(((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _DDC5)) ||\
      ((_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC5)))
            ucInput = _D4_INPUT_PORT;
#elif((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _DDC5))
            ucInput = _D5_INPUT_PORT;
#endif
            break;

        default:
            ucInput = _NO_INPUT_PORT;
            break;
    }

    return ucInput;
}
#endif
#endif
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Data in Interrupt Process
// Input Value  : pReadArray --> Data received
// Output Value : _SUCCESS or _FAIL
//--------------------------------------------------
BYTE ScalerMcuDdcciIntGetData_EXINT1(BYTE *pucReadArray) using 2
{
    BYTE ucDdcciCmdLength = 0;
#if(_DEF_DDCCI_WB_TOOL)
		BYTE checksum = 0XC1;
		BYTE i = 0;
#endif	

    // Get DDC-CI Source Address
    if((MCU_FF27_IIC_STATUS & _BIT1) == _BIT1)
    {
        g_ucDdcciCountEXINT = 0;

        // Save Address
        pucReadArray[g_ucDdcciCountEXINT++] = MCU_FF24_IIC_SUB_IN;

        // Clear Flag
        MCU_FF27_IIC_STATUS &= ~_BIT1;
    }

    if((MCU_FF27_IIC_STATUS & _BIT2) == _BIT2)
    {
        // Save received data until buffer empty
        while((MCU_FF29_IIC_STATUS2 & _BIT1) == 0)
        {
            if(g_ucDdcciCountEXINT >= _DDCCI_RXBUF_LENGTH)
            {
                // Reset data buffer
                MCU_FF2A_IIC_IRQ_CONTROL2 |= _BIT6;

                g_ucDdcciCountEXINT = 0;

                break;
            }

            pucReadArray[g_ucDdcciCountEXINT++] = MCU_FF25_IIC_DATA_IN;

#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
            // smbus
            // For Fixed SMBUS has byte count issue. Smbus Max Len 32
            if((g_ucDdcciCountEXINT == 2) && ((pucReadArray[_DDCCI_LENGTH] & (_BIT7 | _BIT6 | _BIT5)) == 0x00))
            {
                // Ignore SMBUS byte count.
                g_ucDdcciCountEXINT--;
            }
#endif

            ucDdcciCmdLength = (pucReadArray[_DDCCI_LENGTH] & 0x7F) + 3;

            // All data are received
            if(ucDdcciCmdLength == g_ucDdcciCountEXINT)
            {
                // Reset data buffer and Enable mcu write
                MCU_FF2A_IIC_IRQ_CONTROL2 |= (_BIT6 | _BIT5);

                g_ucDdcciCountEXINT = 0;

                if((g_bSrcReadDdcciAlready == _TRUE) && (ucDdcciCmdLength <= sizeof(g_pucDdcciRxBackBuf)) && (ucDdcciCmdLength == g_ucDdcciCmdLengthBack) && (memcmp(g_pucDdcciRxBackBuf, pucReadArray, ucDdcciCmdLength) == 0))
                {
                    BYTE ucPreTxLength = (g_pucDdcciTxBuf[_DDCCI_LENGTH] & 0x7F) + 3;

                    if(ucPreTxLength <= _DDCCI_TXBUF_LENGTH)
                    {
                        pData_EXINT[0] = 0;
                        while(pData_EXINT[0] < ucPreTxLength)
                        {
                            // Load data to DDC-CI buffer until buffer full
                            if((MCU_FF29_IIC_STATUS2 & _BIT2) == 0)
                            {
                                MCU_FF26_IIC_DATA_OUT = g_pucDdcciTxBuf[pData_EXINT[0]++];
                            }
                        }
                    }

                    // Retry case flag
                    g_ucMcuDdcciRetry = _TRUE;
                }
                else
                {
                    for(pData_EXINT[0] = 32; pData_EXINT[0] > 0; pData_EXINT[0] --)
                    {
                        MCU_FF26_IIC_DATA_OUT = 0;
                    }

                    if(ucDdcciCmdLength <= sizeof(g_pucDdcciRxBackBuf))
                    {
                        memcpy(g_pucDdcciRxBackBuf, pucReadArray, ucDdcciCmdLength);

                        g_ucDdcciCmdLengthBack = ucDdcciCmdLength;
                    }
                    else
                    {
                        g_ucDdcciCmdLengthBack = 0;
                    }

                    // Reset data buffer
                    MCU_FF2A_IIC_IRQ_CONTROL2 |= _BIT6;
                }

                // Clear Flag
                MCU_FF27_IIC_STATUS &= ~_BIT0;

                // Disable mcu write
                MCU_FF2A_IIC_IRQ_CONTROL2 &= ~_BIT5;

                g_bSrcReadDdcciAlready = _FALSE;

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
                if((pucReadArray[3] == _DDCCI_OPCODE_VCP_DISP_CALIBRATION) && (pucReadArray[2] == 0x03))
                {
                    // Hold Scl for Display Calibration Process
                    ScalerMcuDdcciHoldScl_EXINT1();
                }
#endif


#if(_DEF_DDCCI_WB_TOOL)
				if((pucReadArray[3] == 0x7B)&& (pucReadArray[2] == 0x03))
				{
				    ScalerMcuDdcciHoldScl_EXINT1();
				}


				// ��Ϊ����û�м��checksum������Ҫ��һ�����
				if((pucReadArray[3] == 0xfe))
				{
					checksum = checksum^pucReadArray[1];
					checksum = checksum^pucReadArray[2];

					for(i = 0;i<(ucDdcciCmdLength-1);i++)
					{
						checksum = checksum ^ pucReadArray[4+i];
					}

					if(checksum ==0)
					// Hold Scl for Display Calibration Process
						ScalerMcuDdcciHoldScl_EXINT1();
					else						
						return _FAIL;

				}

#endif


#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
                if(g_stSmbusBlockRWCmd.b1SmbusEnable == _TRUE)
                {
                    ScalerTimerCancelTimerEvent_EXINT1(_SCALER_TIMER_EVENT_SMBUS_BLOCK_READ_WRITE);
                }
#endif

                if(g_ucMcuDdcciRetry == _TRUE)
                {
                    return _FAIL;
                }
                else
                {
                    return _SUCCESS;
                }
            }
        }
    }

    return _FAIL;
}

#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _OFF)

#if(_FLASH_CLK_SPEED == _FLASH_LOW_SPEED)
//--------------------------------------------------
// Description  : Set Flash Clock Divider.
// Input Value  : ClkDiv --> Flash Clock Divider
// Output Value : None
//--------------------------------------------------
void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv)
{
    enumClkDiv &= 0x0F;
    enumClkDiv = (enumClkDiv << 2);
    enumClkDiv |= (MCU_FFED_MCU_CONTROL & 0xC3);
    MCU_FFED_MCU_CONTROL = enumClkDiv;
}

//--------------------------------------------------
// Description  : Set Flash & Mcu Divider when OSD is running.
// Input Value  : Fast or Low Speed
// Output Value : None
//--------------------------------------------------
void ScalerMcuSwitchFlashMcuFastSpeed(bit bEnable)
{
    // Only Take Effect when Flash Clk is From M2PLL
    if((MCU_FFED_MCU_CONTROL & _BIT1) == _BIT1)
    {
        if(bEnable == _ENABLE)
        {
            // Don't Switch Again If It's Already Using Fast Div
            if(((MCU_FFED_MCU_CONTROL & 0x3C) >> 2) != _FLASH_CLK_FAST_DIV)
            {
                // Switch Flash and MCU Clock to high speed
                ScalerMcuFlashClockDiv(_FLASH_CLK_FAST_DIV);

                // Reload Timer Count
                ScalerTimerSetTimerCount(_TIMER_OPERATION_OSD_MODE);
            }
        }
        else if(bEnable == _DISABLE)
        {
            // Don't Switch Again If It's Already Using Normal Div
            if(((MCU_FFED_MCU_CONTROL & 0x3C) >> 2) != _FLASH_CLK_DIV)
            {
                // Switch Flash and MCU Clock to low speed
                ScalerMcuFlashClockDiv(_FLASH_CLK_DIV);

                // Reload Timer Count
                ScalerTimerSetTimerCount(_TIMER_OPERATION_POWER_NORMAL_MODE);
            }
        }
    }
}
#endif

#if(_SYSTEM_LOW_POWER_IDLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable MCU Into Idle Mode
// Input Value  : None.
// Output Value : None
//--------------------------------------------------
void ScalerMcuIntoIdle(void)
{
    // Enable MCU into idle mode.
    PCON |= _BIT0;
}
#endif

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : SARADC Clock Select.
// Input Value  : enumClock --> _M2PLL_CLK/_IOSC_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuSarAdcClkSel(EnumClkSel enumClock)
{
    if(enumClock == _EXT_XTAL_CLK)
    {
        // ADC clk from external Xtal and div by 4 to obtain clk target 3MHz
        MCU_FF0D_ADC_CLK_DIV = 0x04;
    }
    else
    {
        // ADC clk from IOSC(27M) and div by 9 to obtain clk target 3MHz
        MCU_FF0D_ADC_CLK_DIV = 0x09;
    }
}

#endif  // End of #if(_LOW_SPEED_ADC_SUPPORT == _ON)

#if(_PWM_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : PWM Clock Switch.
// Input Value  : Clock --> _M2PLL_CLK/_EXT_XTAL_CLK(_IOSC_CLK)
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmClockSel(EnumClkSel enumClock)
{
    WORD usCLKDiv = 0;
    WORD usFrequency = 0;

    ////////////////////////////////
    // Adjust PWMx divider: M & N //
    ////////////////////////////////

#if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON) || (_PWM0_PDOW_EN == _ON))

    // Get PWM0 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3B_PWM03_M & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_FF3D_PWM01_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF3E_PWM0_N_LSB) + 1)
    usCLKDiv = (0x01 << (MCU_FF3B_PWM03_M & (_BIT1 | _BIT0))) * (((WORD)((MCU_FF3D_PWM01_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF3E_PWM0_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT0) == _BIT0)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT0;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT0;
    }

    ScalerMcuPwmAdjustFrequency(_PWM0, usFrequency);

#endif // End of #if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON) || (_PWM0_PDOW_EN == _ON))

#if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON) || (_PWM1_PDOW_EN == _ON))

    // Get PWM1 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3B_PWM03_M & (_BIT3 | _BIT2)))
    // N = (((WORD)((MCU_FF3D_PWM01_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 8) | MCU_FF3F_PWM1_N_LSB) + 1)
    usCLKDiv = (0x01 << ((MCU_FF3B_PWM03_M & (_BIT3 | _BIT2)) >> 2)) * (((WORD)((MCU_FF3D_PWM01_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_FF3F_PWM1_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT1) == _BIT1)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT1;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT1;
    }

    ScalerMcuPwmAdjustFrequency(_PWM1, usFrequency);

#endif // End of #if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON) || (_PWM1_PDOW_EN == _ON))

#if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON) || (_PWM2_PDOW_EN == _ON))

    // Get PWM2 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3B_PWM03_M & (_BIT5 | _BIT4)))
    // N = (((WORD)((MCU_FF40_PWM23_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF41_PWM2_N_LSB) + 1)
    usCLKDiv = (0x01 << ((MCU_FF3B_PWM03_M & (_BIT5 | _BIT4)) >> 4)) * (((WORD)((MCU_FF40_PWM23_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF41_PWM2_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT2) == _BIT2)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT2;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT2;
    }

    ScalerMcuPwmAdjustFrequency(_PWM2, usFrequency);

#endif // End of #if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON) || (_PWM2_PDOW_EN == _ON))

#if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON) || (_PWM3_PDOW_EN == _ON))

    // Get PWM3 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3B_PWM03_M & (_BIT7 | _BIT6)))
    // N = (((WORD)((MCU_FF40_PWM23_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_FF42_PWM3_N_LSB) + 1)
    usCLKDiv = (0x01 << ((MCU_FF3B_PWM03_M & (_BIT7 | _BIT6)) >> 6)) * (((WORD)((MCU_FF40_PWM23_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_FF42_PWM3_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT3) == _BIT3)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT3;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT3;
    }

    ScalerMcuPwmAdjustFrequency(_PWM3, usFrequency);

#endif // End of #if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON) || (_PWM3_PDOW_EN == _ON))

#if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON) || (_PWM4_PDOW_EN == _ON))

    // Get PWM4 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3C_PWM45_M & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_FF43_PWM45_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 8) | MCU_FF44_PWM4_N_LSB) + 1)
    usCLKDiv = (0x01 << (MCU_FF3C_PWM45_M & (_BIT1 | _BIT0))) * (((WORD)((MCU_FF43_PWM45_N_MSB & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | MCU_FF44_PWM4_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT4) == _BIT4)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT4;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT4;
    }

    ScalerMcuPwmAdjustFrequency(_PWM4, usFrequency);

#endif // End of #if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON) || (_PWM4_PDOW_EN == _ON))

#if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON) || (_PWM5_PDOW_EN == _ON))

    // Get PWM5 M and N Value
    // PWM CLK divider = 2^M * (N + 1)
    // M = (0x01 <<(MCU_FF3C_PWM45_M & (_BIT1 | _BIT0)))
    // N = (((WORD)((MCU_FF43_PWM45_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF44_PWM4_N_LSB) + 1)
    usCLKDiv = (0x01 << ((MCU_FF3C_PWM45_M & (_BIT3 | _BIT2)) >> 2)) * (((WORD)((MCU_FF43_PWM45_N_MSB & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | MCU_FF45_PWM5_N_LSB) + 1);

    if((MCU_FF3A_PWM_CK_SEL & _BIT5) == _BIT5)
    {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
        // Calculate N Divider for M2PLL / 2
        // HW Using M2Pll / 2 as PWM Reference Clock Source
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION / _DIV_2;
#else
        // Calculate N Divider for M2PLL
        usFrequency = ((DWORD)_M2PLL_CLK_KHZ * 1000) / usCLKDiv / _PWM_DUT_RESOLUTION;
#endif
    }
    else
    {
        usFrequency = (((DWORD)_INTERNAL_OSC_XTAL * 1000) / (0x01 << _IOSC_DIV)) / usCLKDiv / _PWM_DUT_RESOLUTION;
    }

    if(enumClock == _M2PLL_CLK)
    {
        // Switch Clock To M2PLL
        MCU_FF3A_PWM_CK_SEL |= _BIT5;
    }
    else
    {
        // Switch Clock To IOSC
        MCU_FF3A_PWM_CK_SEL &= ~_BIT5;
    }

    ScalerMcuPwmAdjustFrequency(_PWM5, usFrequency);

#endif // End of #if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON) || (_PWM5_PDOW_EN == _ON))
}

//--------------------------------------------------
// Description  : Adjust PWM reset by DVS
// Input Value  : ucPwmType --> _BACKLIGHT_PWM/_AUDIO_VOLUME...
//                bStatus --> _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmAdjustResetByDvs(BYTE ucPwmType, bit bStatus)
{
    BYTE ucMask = 0;

    switch(ucPwmType)
    {
        case _PWM0:
            ucMask = _BIT0;
            break;
        case _PWM1:
            ucMask = _BIT1;
            break;
        case _PWM2:
            ucMask = _BIT2;
            break;
        case _PWM3:
            ucMask = _BIT3;
            break;
        case _PWM4:
            ucMask = _BIT4;
            break;
        case _PWM5:
            ucMask = _BIT5;
            break;
        default:
            break;
    }

    if(ucMask != 0)
    {
        if(bStatus == _ENABLE)
        {
            MCU_FF47_PWM_VS_CTRL |= ucMask;
        }
        else
        {
            MCU_FF47_PWM_VS_CTRL &= ~ucMask;
        }
    }
}

//--------------------------------------------------
// Description  : PWM Clock Switch.
// Input Value  : ucPwmType --> _BACKLIGHT_PWM/_AUDIO_VOLUME...
//                ucFrequency --> Frequency
// Output Value : None
//--------------------------------------------------
bit ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency)
{
    BYTE ucPWM_M = 0;
    WORD usPWM_N = 0;
    bit bCheckResult = _FALSE;

    // Set limit for Pwm frequency
    if((MCU_FF3A_PWM_CK_SEL & ucPwmType) == ucPwmType)
    {
        // Set limit for Pwm frequency
        if(usFrequency < _PWM_ACT_MODE_FREQ_LOW_BOUND)
        {
            usFrequency = _PWM_ACT_MODE_FREQ_LOW_BOUND;
            bCheckResult = _FALSE;
        }
        else if(usFrequency > _PWM_ACT_MODE_FREQ_UPPER_BOUND)
        {
            usFrequency = _PWM_ACT_MODE_FREQ_UPPER_BOUND;
            bCheckResult = _FALSE;
        }
        else
        {
            bCheckResult = _TRUE;
        }
    }
    else
    {
        // Set limit for Pwm frequency
        if(usFrequency < _PWM_PSPD_MODE_FREQ_LOW_BOUND)
        {
            usFrequency = _PWM_PSPD_MODE_FREQ_LOW_BOUND;
            bCheckResult = _FALSE;
        }
        else if(usFrequency > _PWM_PSPD_MODE_FREQ_UPPER_BOUND)
        {
            usFrequency = _PWM_PSPD_MODE_FREQ_UPPER_BOUND;
            bCheckResult = _FALSE;
        }
        else
        {
            bCheckResult = _TRUE;
        }
    }

#if(_PWM_FREQ_DVSRST_CHECK == _ON)
    if(usFrequency >= _PWM_FREQ_DVSRST_BOUND)
    {
        // Disable PWM reset by DVS
#if(_BACKLIGHT_PWM == _PWM0)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT0;

#elif(_BACKLIGHT_PWM == _PWM1)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT1;

#elif(_BACKLIGHT_PWM == _PWM2)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT2;

#elif(_BACKLIGHT_PWM == _PWM3)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT3;

#elif(_BACKLIGHT_PWM == _PWM4)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT4;

#elif(_BACKLIGHT_PWM == _PWM5)
        MCU_FF47_PWM_VS_CTRL &= ~_BIT5;
#endif
    }
    else
    {
        // Enable PWM reset by DVS
#if(_BACKLIGHT_PWM == _PWM0)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM0_RST_EN);

#elif(_BACKLIGHT_PWM == _PWM1)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM1_RST_EN << 1);

#elif(_BACKLIGHT_PWM == _PWM2)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM2_RST_EN << 2);

#elif(_BACKLIGHT_PWM == _PWM3)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM3_RST_EN << 3);

#elif(_BACKLIGHT_PWM == _PWM4)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM4_RST_EN << 4);

#elif(_BACKLIGHT_PWM == _PWM5)
        MCU_FF47_PWM_VS_CTRL |= ((BYTE)_PWM5_RST_EN << 5);
#endif
    }
#endif

    // Check if PWM clk is M2PLL or IOSC
    if((MCU_FF3A_PWM_CK_SEL & ucPwmType) == ucPwmType)
    {
        for(ucPWM_M = 0; ucPWM_M < 4; ucPWM_M++)
        {
#if(_HW_MCU_PWM_HW_REF_HALF_OF_M2PLL == _ON)
            // Calculate N Divider for M2PLL / 2
            // HW Using M2Pll / 2 as PWM Reference Clock Source
            usPWM_N = ((DWORD)(((((DWORD)_M2PLL_CLK_KHZ * 1000) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) + 1) / 2) - 1);
#else
            // Calculate N Divider for Define [_M2PLL_CLK_KHZ]
            usPWM_N = ((DWORD)(((((DWORD)_M2PLL_CLK_KHZ * 1000 * 2) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) + 1) / 2) - 1);
#endif

            if(usPWM_N < 4096)
            {
                break;
            }
        }
    }
    else
    {
        for(ucPWM_M = 0; ucPWM_M < 4; ucPWM_M++)
        {
            // Calculate N Divider for IOSC clock
            usPWM_N = ((DWORD)(((((DWORD)_INTERNAL_OSC_XTAL * 1000 * 2) / ((DWORD)usFrequency * (0x01 << ucPWM_M) * _PWM_DUT_RESOLUTION)) + 1) / 2) - 1);

            if(usPWM_N < 4096)
            {
                break;
            }
        }
    }

    // Load M/N divider to corresponding register
    switch(ucPwmType)
    {
#if((_PWM0_EN == _ON) || (_PWM0_PSAV_EN == _ON) || (_PWM0_PDOW_EN == _ON))
        case _PWM0:

            MCU_FF3B_PWM03_M = (MCU_FF3B_PWM03_M & ~(_BIT1 | _BIT0)) | (ucPWM_M);
            MCU_FF3D_PWM01_N_MSB &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_FF3D_PWM01_N_MSB |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_FF3E_PWM0_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT0;

            break;
#endif

#if((_PWM1_EN == _ON) || (_PWM1_PSAV_EN == _ON) || (_PWM1_PDOW_EN == _ON))
        case _PWM1:

            MCU_FF3B_PWM03_M = (MCU_FF3B_PWM03_M & ~(_BIT3 | _BIT2)) | (ucPWM_M << 2);
            MCU_FF3D_PWM01_N_MSB &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_FF3D_PWM01_N_MSB |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_FF3F_PWM1_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT1;

            break;
#endif

#if((_PWM2_EN == _ON) || (_PWM2_PSAV_EN == _ON) || (_PWM2_PDOW_EN == _ON))
        case _PWM2:

            MCU_FF3B_PWM03_M = (MCU_FF3B_PWM03_M & ~(_BIT5 | _BIT4)) | (ucPWM_M << 4);
            MCU_FF40_PWM23_N_MSB &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_FF40_PWM23_N_MSB |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_FF41_PWM2_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT2;

            break;
#endif

#if((_PWM3_EN == _ON) || (_PWM3_PSAV_EN == _ON) || (_PWM3_PDOW_EN == _ON))
        case _PWM3:

            MCU_FF3B_PWM03_M = (MCU_FF3B_PWM03_M & ~(_BIT7 | _BIT6)) | (ucPWM_M << 6);
            MCU_FF40_PWM23_N_MSB &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_FF40_PWM23_N_MSB |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_FF42_PWM3_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT3;

            break;
#endif

#if((_PWM4_EN == _ON) || (_PWM4_PSAV_EN == _ON) || (_PWM4_PDOW_EN == _ON))
        case _PWM4:

            MCU_FF3C_PWM45_M = (MCU_FF3C_PWM45_M & ~(_BIT1 | _BIT0)) | (ucPWM_M);
            MCU_FF43_PWM45_N_MSB &= ~(_BIT7 | _BIT6 | _BIT5 | _BIT4);
            MCU_FF43_PWM45_N_MSB |= (BYTE)((usPWM_N >> 4) & (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            MCU_FF44_PWM4_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT4;

            break;
#endif

#if((_PWM5_EN == _ON) || (_PWM5_PSAV_EN == _ON) || (_PWM5_PDOW_EN == _ON))
        case _PWM5:

            MCU_FF3C_PWM45_M = (MCU_FF3C_PWM45_M & ~(_BIT3 | _BIT2)) | (ucPWM_M << 2);
            MCU_FF43_PWM45_N_MSB &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
            MCU_FF43_PWM45_N_MSB |= (BYTE)((usPWM_N >> 8) & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            MCU_FF45_PWM5_N_LSB = (BYTE)usPWM_N;
            MCU_FF49_PWM_CK |= _BIT5;

            break;
#endif
        default:

            break;
    }
    return bCheckResult;
}
#endif // End of #if(_PWM_FUNCTION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : 5us Delay Calculation
// Input Value  : Clock --> _M2PLL_CLK/_IOSC_CLK
// Output Value : ucValue --> N
//--------------------------------------------------
void ScalerMcu5usDelayCalc(EnumClkSel enumClock)
{
    BYTE ucMcuDiv = 0;

    ucMcuDiv = ((MCU_FFED_MCU_CONTROL & 0x3C) >> 2) * ((MCU_FFEE_MCU_CLOCK_CONTROL & 0x3C) >> 2);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Chart :                                                                                                      //
    //                                                                                                              //
    //  INOSC                                                                                                       //
    //    14.318MHz ---|   |      |IOSC|            |   |                                                           //
    //                 |Mux|------|DIV | -----------|   |                                                           //
    //    27MHz     ---|   |      |    |            |   |  EMCU Crystal |   |                                       //
    //                CR0B[0]   Page6 CRA0[1:0]     |Mux|---------------|   |                                       //
    //                                              |   |               |   |                                       //
    //                   external-crystal-----------|   |               |   |       |Flash|      |MCU|              //
    //                                              |   |               |Mux|-------|DIV  |------|DIV|------8051    //
    //                                             CR09[3]              |   |       |     |   |  |   |              //
    //                                                                  |   |     0xFFED[5:2] | 0xFFEE[5:2]         //
    //                                                M2PLL-------------|   |                 |                     //
    //                                                                  |   |                 |--|Flash|            //
    //                                                                0xFFED[1]                  |DIV2 |-----Flash  //
    //                                                                                          0xFFE9[3:0]         //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(enumClock == _M2PLL_CLK)
    {
        g_ucDelay5usN_Base = _M2PLL_DELAY6US_CNT;
        g_ucDelayXusN_Base = _M2PLL_DELAY4US_CNT;
    }
    else if(enumClock == _IOSC_CLK)
    {
        g_ucDelay5usN_Base = _IOSC_DELAY6US_CNT;
        g_ucDelayXusN_Base = _IOSC_DELAY4US_CNT;
    }
    else // For Xtal
    {
        g_ucDelay5usN_Base = _XTAL_DELAY6US_CNT;
        g_ucDelayXusN_Base = _XTAL_DELAY4US_CNT;
    }
}

#if(_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Software IIC Start
// Input Value  : ucSlaveAddr --> Slave Address
// Output Value : None
//--------------------------------------------------
BYTE ScalerMcuIICStart(BYTE ucSlaveAddr)
{
    BYTE ucTemp = 0;
    WORD usTimeOut = 6;

    PCB_SW_IIC_SCL_SET();
    PCB_SW_IIC_SDA_SET();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SCL_CHK(ucTemp);

    while(ucTemp == _LOW)
    {
        if(usTimeOut > 0)
        {
            usTimeOut--;
            SW_IIC_DELAY_TIME();
        }
        else
        {
            return _FAIL;
        }

        PCB_SW_IIC_SCL_CHK(ucTemp);
    }

    PCB_SW_IIC_SDA_CLR();

    SW_IIC_START_INTERVAL_DELAY();

    PCB_SW_IIC_SCL_CLR();

    SW_IIC_DELAY_TIME();

    return ScalerMcuIICSendByte(ucSlaveAddr);
}

//--------------------------------------------------
// Description  : Software IIC Stop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICStop(void)
{
    PCB_SW_IIC_SDA_CLR();
    PCB_SW_IIC_SCL_SET();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SDA_SET();
}

//--------------------------------------------------
// Description  : Software IIC Get Acknowledge
// Input Value  : None
// Output Value : ucAck --> 0: Ack / 1: Nack
//--------------------------------------------------
BYTE ScalerMcuIICGetAck(void)
{
    BYTE ucAck = 0;

    PCB_SW_IIC_SDA_SET();
    PCB_SW_IIC_SCL_SET();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SDA_CHK(ucAck);

    PCB_SW_IIC_SCL_CLR();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SDA_SET();

    return ucAck;
}

//--------------------------------------------------
// Description  : Software IIC Send Acknowledge
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICSendAck(void)
{
    PCB_SW_IIC_SDA_CLR();
    PCB_SW_IIC_SCL_SET();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SCL_CLR();

    SW_IIC_DELAY_TIME();
}

//--------------------------------------------------
// Description  : Software IIC Send No-Acknowledge
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIICSendNoAck(void)
{
    PCB_SW_IIC_SDA_SET();
    PCB_SW_IIC_SCL_SET();

    SW_IIC_DELAY_TIME();

    PCB_SW_IIC_SCL_CLR();

    SW_IIC_DELAY_TIME();
}

//--------------------------------------------------
// Description  : Software IIC Read 1 Byte
// Input Value  : None
// Output Value : ucValue --> Received Byte
//--------------------------------------------------
#pragma save
#pragma OT(8)
BYTE ScalerMcuIICGetByte(void)
{
    BYTE ucTemp = 0;
    BYTE ucCnt = 0;
    BYTE ucValue = 0;

    PCB_SW_IIC_SDA_SET();

    for(ucCnt = 0; ucCnt < 8; ucCnt++)
    {
        PCB_SW_IIC_SCL_SET();

        SW_IIC_DELAY_TIME();

        PCB_SW_IIC_SDA_CHK(ucTemp);

        ucValue = (ucValue << 1) | ucTemp;

        PCB_SW_IIC_SCL_CLR();

        SW_IIC_DELAY_TIME();
    }

    return ucValue;
}
#pragma restore

//--------------------------------------------------
// Description  : SoftWare IIC Write 1 Byte
// Input Value  : ucValue --> Data to be transmitted
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
BYTE ScalerMcuIICSendByte(BYTE ucValue)
{
    BYTE ucCnt = 0;

    for(ucCnt = 0; ucCnt < 8; ucCnt++)
    {
        if((bit)(ucValue & _BIT7) == _HIGH)
        {
            PCB_SW_IIC_SDA_SET();
        }
        else
        {
            PCB_SW_IIC_SDA_CLR();
        }

        PCB_SW_IIC_SCL_SET();

        SW_IIC_DELAY_TIME();

        PCB_SW_IIC_SCL_CLR();

        if((MCU_FFED_MCU_CONTROL & _BIT1) == _BIT1)
        {
            SW_IIC_DELAY_TIME();
        }

        ucValue = ucValue << 1;
    }

    if(ScalerMcuIICGetAck() == _HIGH)
    {
        ScalerMcuIICStop();

        return _FAIL;
    }

    return _SUCCESS;
}
#pragma restore

//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICWriteStart(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr)
{
    if(ScalerMcuIICStart(ucSlaveAddr | _WRITE) == _FAIL)
    {
        return _FAIL;
    }

    switch(ucSubAddrLength)
    {
        case 1:

            if(ScalerMcuIICSendByte((BYTE)(ulSubAddr)) == _FAIL)
            {
                return _FAIL;
            }

            break;

        case 2:

            if(ScalerMcuIICSendByte((BYTE)((ulSubAddr & 0xFF00) >> 8)) == _FAIL)
            {
                return _FAIL;
            }
            else
            {
                if(ScalerMcuIICSendByte((BYTE)(ulSubAddr)) == _FAIL)
                {
                    return _FAIL;
                }
            }

            break;

        case 4:

            if((ScalerMcuIICSendByte((BYTE)((ulSubAddr & 0xFF000000) >> 24)) == _FAIL) ||
               (ScalerMcuIICSendByte((BYTE)((ulSubAddr & 0xFF0000) >> 16)) == _FAIL) ||
               (ScalerMcuIICSendByte((BYTE)((ulSubAddr & 0xFF00) >> 8)) == _FAIL) ||
               (ScalerMcuIICSendByte((BYTE)(ulSubAddr)) == _FAIL))
            {
                return _FAIL;
            }

            break;

        default:

            break;
    }
    return _SUCCESS;
}

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON || _HDMI_24C02_SUPPORT)
//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICWritePolling(BYTE ucSlaveAddr)
{
    if(ScalerMcuIICStart(ucSlaveAddr | _WRITE) == _FAIL)
    {
        return _FAIL;
    }

    ScalerMcuIICStop();

    return _SUCCESS;
}
#endif

//--------------------------------------------------
// Description  : Read data from the selected device by Software IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                ucSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr, WORD usLength, BYTE *pucReadArray)
{
    if(usLength == 0)
    {
        return _FAIL;
    }

    if(ucSubAddrLength != 0)
    {
        // Write Slave address and Sub-address
        if(ScalerMcuIICWriteStart(ucSlaveAddr, ucSubAddrLength, ulSubAddr) == _FAIL)
        {
            return _FAIL;
        }
    }

    // Write Slave address to read
    if(ScalerMcuIICStart(ucSlaveAddr | _READ) == _FAIL)
    {
        return _FAIL;
    }

    // Save received data
    while(--usLength)
    {
        *pucReadArray++ = ScalerMcuIICGetByte();

        ScalerMcuIICSendAck();
    }

    *pucReadArray++ = ScalerMcuIICGetByte();

    ScalerMcuIICSendNoAck();

    ScalerMcuIICStop();

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the selected device by Software IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
#pragma save
#pragma OT(8)
bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, DWORD ulSubAddr, WORD usLength, BYTE *pucWriteArray)
{
    if(usLength == 0)
    {
        return _FAIL;
    }

    // Write Slave address and Sub-address
    if(ScalerMcuIICWriteStart(ucSlaveAddr, ucSubAddrLength, ulSubAddr) == _FAIL)
    {
        return _FAIL;
    }

    // Send data
    while(usLength--)
    {
        if(ScalerMcuIICSendByte(*pucWriteArray++) == _FAIL)
        {
            return _FAIL;
        }
    }

    ScalerMcuIICStop();

    return _SUCCESS;
}
#pragma restore

#endif    // End of #if(_SW_IIC_SUPPORT == _ON)

#if(_HW_IIC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Hardware IIC Parameters Alter Setting By Use Case
// Input Value  : enumParType --> HW IIC Parameter Type
// Output Value : None
//--------------------------------------------------
void ScalerMcuHwIICConfigSetting(EnumHWIICParType enumParType)
{
    g_ucHwI2cSettingIndex = enumParType;

    ScalerMcuHwIICInitial();

    if(GET_REG_XTAL_CLK_SEL() == _EXT_XTAL_CLK)
    {
        // Select at external Xtal.
        ScalerMcuHwIICSetFreqDiv(_EXT_XTAL_CLK);
    }
    else
    {
        // Select at internal Xtal.
        ScalerMcuHwIICSetFreqDiv(_IOSC_CLK);
    }
}

//--------------------------------------------------
// Description  : Hardware IIC Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuHwIICInitial(void)
{
    // Reset IIC module
    MCU_FF55_I2CM_CR0 &= ~_BIT7;

    // Enable IIC module and disable TOR
    MCU_FF55_I2CM_CR0 |= _BIT7;
    MCU_FF55_I2CM_CR0 &= ~_BIT0;

    // Set TOR: time-out = TOR x 2 x ((FD10+1)/input clk)
    MCU_FF56_I2CM_CR1 = _HW_IIC_TOR;

    // Disable burst mode
    MCU_FF57_I2CM_CR2 = 0x00;

    // Clear interrupts
    MCU_FF58_I2CM_CR3 = 0x00;

    // Set fall time period count
    MCU_FF59_I2CM_STR0 = _HW_IIC_FTPC;

    // Set STA setup time period count
    MCU_FF5A_I2CM_STR1 = _HW_IIC_STA_SUGPIO_C;

    // Set SCL high period count
    MCU_FF5B_I2CM_STR2 = _HW_IIC_SHPC_14318K;

    // Set SCL low period count
    MCU_FF5C_I2CM_STR3 = _HW_IIC_SLPC_14318K;

    // Set frequency divisor: ref = xtal/(FD10+1)
    MCU_FF5F_I2CM_CCR = _HW_IIC_FD10_14318K;
}

//--------------------------------------------------
// Description  : Hardware IIC Clock Select
// Input Value  : Clock --> _EXT_XTAL_CLK/_IOSC_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuHwIICSetFreqDiv(EnumClkSel enumClock)
{
    if(enumClock == _EXT_XTAL_CLK)
    {
        // Set freq. divisor: ref = XTAL/(FD10+1) = 7.16M(ref should be approx 10MHz)
        MCU_FF5F_I2CM_CCR = _HW_IIC_FD10_14318K;

        // Set STA setup time period count
        MCU_FF5A_I2CM_STR1 = _HW_IIC_STA_SUGPIO_C;

        // Set SCL high period count
        MCU_FF5B_I2CM_STR2 = _HW_IIC_SHPC_14318K;

        // Set SCL low period count
        MCU_FF5C_I2CM_STR3 = _HW_IIC_SLPC_14318K;
    }
    else
    {
        // Set freq. divisor: ref = IOSC/(FD10+1) = 9.3M(ref should be approx 10MHz)
        MCU_FF5F_I2CM_CCR = _HW_IIC_FD10_28000K;

        // Set STA setup time period count
        MCU_FF5A_I2CM_STR1 = _HW_IIC_STA_SUGPIO_C;

        // Set SCL high period count
        MCU_FF5B_I2CM_STR2 = _HW_IIC_SHPC_28000K;

        // Set SCL low period count
        MCU_FF5C_I2CM_STR3 = _HW_IIC_SLPC_28000K;
    }
}

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON || _HDMI_24C02_SUPPORT)
//--------------------------------------------------
// Description  : Polling internal write cycle finish
// Input Value  : ucSlaveAddr  --> Slave address
// Output Value : Polling result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuHwIICWritePolling(BYTE ucSlaveAddr, BYTE ucSubAddrLength, BYTE ucHwIICPinNum)
{
    BYTE ucSubAddress = 0x00;
    BYTE ucLength = 0;
    BYTE ucTimeOutCnt = _IIC_POLLING_TIME;

    ScalerPinshareHwIICPin(ucHwIICPinNum);

    // Reset(Block) IIC module
    MCU_FF55_I2CM_CR0 &= ~_BIT7;

    // Enable IIC module
    MCU_FF55_I2CM_CR0 |= _BIT7;

    // Set 1 byte for FRSIB
    MCU_FF57_I2CM_CR2 &= ~(_BIT1 | _BIT0);

    // Set no repeat start
    MCU_FF58_I2CM_CR3 &= ~(_BIT4 | _BIT3);

    // Wait I2C Fifo Clk Switch to Mcu Clk
    while((MCU_FF5D_I2CM_SR & _BIT5) != _BIT5)
    {
        if(ucTimeOutCnt == 0)
        {
            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
        else
        {
            ucTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Load Slave Address to IIC Buffer
    MCU_FF5E_I2CM_TD = ucSlaveAddr | _WRITE;

    MCU_FF55_I2CM_CR0 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);

    switch(ucSubAddrLength)
    {
        case 0:

            break;

        case 1:

            // Set data length
            MCU_FF55_I2CM_CR0 |= ucLength << 1;

            // Load Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)(ucSubAddress);

            break;

        case 2:

            // Set data length
            MCU_FF55_I2CM_CR0 |= (ucLength + 1) << 1;

            // Load First Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = ucSubAddress;

            // Load Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = ucSubAddress;

            break;

        default:

            break;
    }

    // IIC command Start
    MCU_FF55_I2CM_CR0 |= _BIT6;

    // Wait until Master Transmit Complete
    ucTimeOutCnt = _IIC_POLLING_TIME;

    while((MCU_FF5D_I2CM_SR & 0x01) != 0x01)
    {
        ucTimeOutCnt--;

        DELAY_5US();

        if(ucTimeOutCnt == 0x00)
        {
            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
    }

    // Clear all flags
    MCU_FF5D_I2CM_SR |= 0x07;

    return _SUCCESS;
}
#endif // End of #if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Read data from the selected device by IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                ucSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucReadArray, BYTE ucHwIICPinNum)
{
    BYTE ucI = 0;
    WORD usTimeOutCnt = 600;

    // Return fail if Data to be received is greater than IIC buffer size
    if(ucDataLength > _HW_IIC_BUFFER_SIZE)
    {
        return _FAIL;
    }

    ScalerPinshareHwIICPin(ucHwIICPinNum);

    // Reset(Block) IIC module
    MCU_FF55_I2CM_CR0 &= ~_BIT7;

    // Enable IIC module
    MCU_FF55_I2CM_CR0 |= _BIT7;

    // Wait I2C Fifo Clk Switch to Mcu Clk
    while((MCU_FF5D_I2CM_SR & _BIT5) != _BIT5)
    {
        if(usTimeOutCnt == 0)
        {
            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Load Slave Address to IIC Buffer
    switch(ucSubAddrLength)
    {
        case 0:

            // Set 1 byte for FRSIB
            MCU_FF57_I2CM_CR2 &= ~(_BIT1 | _BIT0);

            // Set no repeat start
            MCU_FF58_I2CM_CR3 &= ~(_BIT4 | _BIT3);

            // Load Slave Address to receive data
            MCU_FF5E_I2CM_TD = ucSlaveAddr | _READ;

            break;

        case 1:

            // Set 2 bytes for FRSIB
            MCU_FF57_I2CM_CR2 &= ~(_BIT1 | _BIT0);
            MCU_FF57_I2CM_CR2 |= _BIT0;

            // Set one repeat start
            MCU_FF58_I2CM_CR3 &= ~_BIT4;
            MCU_FF58_I2CM_CR3 |= _BIT3;

            // Load Slave Address to IIC Buffer
            MCU_FF5E_I2CM_TD = ucSlaveAddr | _WRITE;

            // Load Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)(usSubAddr);

            // Load Slave Address to receive data
            MCU_FF5E_I2CM_TD = ucSlaveAddr | _READ;

            break;

        case 2:

            // Set 3 bytes for FRSIB
            MCU_FF57_I2CM_CR2 &= ~(_BIT1 | _BIT0);
            MCU_FF57_I2CM_CR2 |= _BIT1;

            // Set one repeat start
            MCU_FF58_I2CM_CR3 &= ~_BIT4;
            MCU_FF58_I2CM_CR3 |= _BIT3;

            // Load Slave Address to IIC Buffer
            MCU_FF5E_I2CM_TD = ucSlaveAddr | _WRITE;

            // Load First Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)((usSubAddr & 0xFF00) >> 8);

            // Load Second Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)(usSubAddr);

            // Load Slave Address to receive data
            MCU_FF5E_I2CM_TD = ucSlaveAddr | _READ;

            break;

        default:

            break;
    }

    // Set data length
    MCU_FF55_I2CM_CR0 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);
    MCU_FF55_I2CM_CR0 |= (ucDataLength - 1) << 1;

    // IIC command Start
    MCU_FF55_I2CM_CR0 |= _BIT6;

    // Wait until Master Receive Complete
    usTimeOutCnt = 600;

    while((MCU_FF5D_I2CM_SR & 0x02) != 0x02)
    {
        if(usTimeOutCnt == 0)
        {
            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Wait I2C Fifo Clk Switch to Mcu Clk
    usTimeOutCnt = 600;

    while((MCU_FF5D_I2CM_SR & _BIT5) != _BIT5)
    {
        if(usTimeOutCnt == 0)
        {
            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Save received data
    for(ucI = 0; ucI < ucDataLength; ucI++)
    {
        *pucReadArray = MCU_FF5E_I2CM_TD;
        pucReadArray++;
    }

    // Clear all flags
    MCU_FF5D_I2CM_SR |= 0x07;

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the selected device by IIC
// Input Value  : ucSlaveAddr  --> Slave address
//                usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Write result (Fail/Success)
//--------------------------------------------------
#pragma save
#pragma OT(8)
bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucWriteArray, BYTE ucHwIICPinNum)
{
    BYTE ucI = 0;
    WORD usTimeOutCnt = 600;
    BYTE ucTempLength = 0;

    ScalerPinshareHwIICPin(ucHwIICPinNum);

    // Reset(Block) IIC module
    MCU_FF55_I2CM_CR0 &= ~_BIT7;

    // Enable IIC module
    MCU_FF55_I2CM_CR0 |= _BIT7;

    // Set 1 byte for FRSIB
    MCU_FF57_I2CM_CR2 &= ~(_BIT1 | _BIT0);

    // Set no repeat start
    MCU_FF58_I2CM_CR3 &= ~(_BIT4 | _BIT3);

    // Wait I2C Fifo Clk Switch to Mcu Clk
    while((MCU_FF5D_I2CM_SR & _BIT5) != _BIT5)
    {
        if(usTimeOutCnt == 0)
        {
            DebugMessageScaler("- IIC Write Time Out: FIFO Clock", 0xA1);

            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Load Slave Address to IIC Buffer
    MCU_FF5E_I2CM_TD = ucSlaveAddr | _WRITE;

    MCU_FF55_I2CM_CR0 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);

    if(ucDataLength > 16)
    {
        pData[0] = 16;
    }
    else
    {
        pData[0] = ucDataLength;
    }

    switch(ucSubAddrLength)
    {
        case 0:

            // Set data length
            ucTempLength = ((pData[0] - 1) << 1);

            break;

        case 1:

            // Load Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)(usSubAddr);

            // Set data length
            ucTempLength = (pData[0] << 1);

            break;

        case 2:

            // Load First Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)((usSubAddr & 0xFF00) >> 8);

            // Load Second Sub-Address to IIC Buffer
            MCU_FF5E_I2CM_TD = (BYTE)(usSubAddr);

            // Set data length
            ucTempLength = ((pData[0] + 1) << 1);

            break;

        default:

            break;
    }

    if(ucDataLength <= 16)
    {
        // Load data to IIC buffer for transmission
        for(ucI = 0; ucI < pData[0]; ucI++)
        {
            MCU_FF5E_I2CM_TD = *pucWriteArray;
            pucWriteArray++;
        }

        // Send IIC command Start
        MCU_FF55_I2CM_CR0 = 0xC0 + ucTempLength;
    }
    else
    {
        // Disable HW TOR
        MCU_FF55_I2CM_CR0 &= ~_BIT0;

        // Enable Burst Mode
        MCU_FF57_I2CM_CR2 |= _BIT6;

        // Calcualte Burst Command
        pData[1] = (ucDataLength / 16) + ((ucDataLength % 16) ? 1 : 0);

        for(pData[2] = 0; pData[2] < pData[1]; pData[2]++)
        {
            usTimeOutCnt = 600;

            // Wait I2C Fifo Clk Switch to Mcu Clk
            while((MCU_FF5D_I2CM_SR & _BIT5) != _BIT5)
            {
                if(usTimeOutCnt == 0)
                {
                    DebugMessageScaler("- IIC Write Time Out: FIFO Clock", 0xA2);

                    // Reset(Block) IIC module
                    MCU_FF55_I2CM_CR0 &= ~_BIT7;

                    // Enable IIC module
                    MCU_FF55_I2CM_CR0 |= _BIT7;

                    // Disable Burst Mode
                    MCU_FF57_I2CM_CR2 &= ~_BIT6;

                    return _FAIL;
                }
                else
                {
                    usTimeOutCnt--;

                    DELAY_5US();
                }
            }

            // Load data to IIC buffer for transmission
            for(ucI = 0; ucI < pData[0]; ucI++)
            {
                MCU_FF5E_I2CM_TD = *pucWriteArray;
                pucWriteArray++;
            }

            if(pData[2] != 0)
            {
                // Set data length
                ucTempLength = ((pData[0] - 1) << 1) & (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1);
            }

            // Set Length and First Burst Command Start, Must Keep FF55[6] = 1 until Burst Mode end
            MCU_FF55_I2CM_CR0 = 0xC0 + ucTempLength;

            // Update Remaider Data Length
            ucDataLength = ucDataLength - pData[0];

            if(ucDataLength > 16)
            {
                pData[0] = 16;
            }
            else
            {
                pData[0] = ucDataLength;
            }

            if(pData[2] == (pData[1] - 1))
            {
                // Disable Burst Write
                MCU_FF57_I2CM_CR2 &= ~_BIT6;

                // Burst write again
                MCU_FF5D_I2CM_SR |= (_BIT4 | _BIT3);

                break;
            }
            else if(pData[2] != 0)
            {
                // Burst write again
                MCU_FF5D_I2CM_SR |= (_BIT4 | _BIT3);
            }

            usTimeOutCnt = 600;

            // Wait into Burst Wait State
            while((MCU_FF5D_I2CM_SR & _BIT3) != _BIT3)
            {
                if(usTimeOutCnt == 0)
                {
                    DebugMessageScaler("- IIC Write Time Out: Burst Mode", 0xA3);

                    // Reset(Block) IIC module
                    MCU_FF55_I2CM_CR0 &= ~_BIT7;

                    // Enable IIC module
                    MCU_FF55_I2CM_CR0 |= _BIT7;

                    // Disable Burst Mode
                    MCU_FF57_I2CM_CR2 &= ~_BIT6;

                    return _FAIL;
                }
                else
                {
                    usTimeOutCnt--;

                    DELAY_5US();
                }
            }
        }
    }

    usTimeOutCnt = 600;

    // Wait until Master Transmit Complete
    while((MCU_FF5D_I2CM_SR & 0x01) != 0x01)
    {
        if(usTimeOutCnt == 0)
        {
            DebugMessageScaler("- IIC Write Time Out: Transmit", 0xA4);

            // Reset(Block) IIC module
            MCU_FF55_I2CM_CR0 &= ~_BIT7;

            // Enable IIC module
            MCU_FF55_I2CM_CR0 |= _BIT7;

            // Disable Burst Mode
            MCU_FF57_I2CM_CR2 &= ~_BIT6;

            return _FAIL;
        }
        else
        {
            usTimeOutCnt--;

            DELAY_5US();
        }
    }

    // Clear all flags
    MCU_FF5D_I2CM_SR |= 0x07;

    return _SUCCESS;
}
#pragma restore

#endif  // End of #if(_HW_IIC_SUPPORT == _ON)

#if(_UART_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Write data to the selected device by UART
// Input Value  : ucValue --> Data to be send
// Output Value : Write result (Fail/Success)
//--------------------------------------------------
bit ScalerMcuUartWrite(BYTE ucValue)
{
    // at most 40ms delay when baudrate 300 bps
    WORD usTimeOut = 8000;

    // Disable Serial Port IRQ
    ES = _DISABLE;

    // Clear Flag
    TI = 0;

    // Load Data to Serial Port Buffer
    SBUF = ucValue;

    do
    {
        DELAY_5US();
    }
    while((TI == 0) && (--usTimeOut != 0));

    // Enable Serial Port IRQ
    ES = _ENABLE;

    return ((TI != 0) && (usTimeOut != 0)) ? _TRUE : _FALSE;
}
#endif

//--------------------------------------------------
// Description  : ISP Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIspInitial(void)
{
    // Keep mcu peripheral(timer) running while mcu stopped by spi flash access
    MCU_FFEE_MCU_CLOCK_CONTROL |= _BIT6;
}

#if(_MT3212_CT_SUPPORT == _ON)
#define ADDR_MT3212_CT                                      0xBE
#define MT321X_MOD_CHANNEL_CTRL_REG                      	0x40 	//	Modulator channel control
#define MT321X_ENABLE_REG                                	0x80 	//	 Enables device states
#define MT321X_MEAS_MODE0_REG                            	0x81 	//	Measurement mode settings 0
#define MT321X_MEAS_MODE1_REG                            	0x82 	//	Measurement mode settings 1
#define MT321X_SAMPLE_TIME0_REG                          	0x83 	//	sample time settings 0 [7:0]
#define MT321X_SAMPLE_TIME1_REG                          	0x84 	//	sample time settings 1 [10:8]
#define MT321X_ALS_NR_SAMPLES0_REG                       	0x85 	//	ALS measurement time settings 0 [7:0]
#define MT321X_ALS_NR_SAMPLES1_REG                       	0x86 	//	ALS measurement time settings 1 [10:8]
#define MT321X_FD_NR_SAMPLES0_REG                        	0x87 	//	Flicker number of samples 0 [7:0]
#define MT321X_FD_NR_SAMPLES1_REG                        	0x88 	//	Flicker number of samples 1 [10:8]
#define MT321X_WTIME_REG                                 	0x89 	//	Wait time
#define MT321X_AILT0_REG                                 	0x8A 	//	 ALS Interrupt Low Threshold [7:0]
#define MT321X_AILT1_REG                                 	0x8B 	//	 ALS Interrupt Low Threshold [15:8]
#define MT321X_AILT2_REG                                 	0x8C 	//	 ALS Interrupt Low Threshold [23:16]
#define MT321X_AIHT0_REG                                 	0x8D	//	 ALS Interrupt High Threshold [7:0]
#define MT321X_AIHT1_REG                                 	0x8E 	//	 ALS Interrupt High Threshold [15:8]
#define MT321X_AIHT2_REG                                 	0x8F 	//	 ALS Interrupt High Threshold [23:16]
#define MT321X_STATUS_REG                                	0x93 	//	Device Status information 1
#define MT321X_ALS_STATUS_REG                            	0x94	//	ALS Status information 1
#define MT321X_ALS_DATA0_L_REG                           	0x95	//	ALS data channel 0 low byte [7:0]
#define MT321X_ALS_DATA0_H_REG                           	0x96	//	ALS data channel 0 high byte [15:8]
#define MT321X_ALS_DATA1_L_REG                           	0x97	//	ALS data channel 1 low byte [7:0]
#define MT321X_ALS_DATA1_H_REG                           	0x98	//	ALS data channel 1 high byte [15:8]
#define MT321X_ALS_DATA2_L_REG                           	0x99	//	ALS data channel 2 low byte [7:0]
#define MT321X_ALS_DATA2_H_REG                           	0x9A	//	ALS data channel 2 high byte [15:8]
#define MT321X_STATUS2_REG                               	0x9D	//	Device Status information 2
#define MT321X_STATUS3_REG                               	0x9E	//	Device Status information 3
#define MT321X_STATUS4_REG                               	0x9F	//	Device Status information 4
#define MT321X_STATUS5_REG                               	0xA0	//	Device Status information 5
#define MT321X_CFG0_REG                                  	0xA1 	//	Configuration 0
#define MT321X_CFG1_REG                                  	0xA2 	//	Configuration 1
#define MT321X_CFG2_REG                                  	0xA3	//	Configuration 2
#define MT321X_CFG3_REG                                  	0xA4	//	Configuration 3
#define MT321X_CFG4_REG                                  	0xA5	//	Configuration 4
#define MT321X_CFG5_REG                                  	0xA6	//	Configuration 5
#define MT321X_CFG8_REG                                  	0xA9 	//	Configuration 8
#define MT321X_ADC_RST_TIME_L_REG                        	0xAB	//	Number of reset time for ADC.
#define MT321X_AGC_NR_SAMPLES_L_REG                      	0xAC 	//	Number of samples for measurement with AGC low[7:0]
#define MT321X_AGC_NR_SAMPLES_H3_REG                     	0xAD	//	Number of samples for measurement with AGC high[10:8]
#define MT321X_TRIGGER_MODE_REG                          	0xAE	//	Wait Time Mode 
#define MT321X_CONTROL_REG                               	0xB1 	//	 Device control settings
#define MT321X_INTENAB_REG                               	0xBA 	//	Enable interrupts
#define MT321X_SIEN_REG                                  	0xBB 	//	Enable saturation interrupts
#define MT321X_MEAS_SEQR_FD_0_REG                        	0xCF	//	Flicker measurement with sequencer on modulator0
#define MT321X_MEAS_SEQR_ALS_FD_1_REG                    	0xD0	//	ALS measurement with sequencer on all modulators
#define MT321X_MEAS_SEQR_APERS_AND_VSYNC_WAIT_REG        	0xD1	//	Defines the measurement sequencer pattern
#define MT321X_MEAS_SEQR_RESIDUAL_1_AND_WAIT_REG         	0xD3	//	Residual measurement configuration with sequencer on modulator2 and wait time configuration for all sequencers
#define MT321X_MEAS_SEQR_STEP0_MOD_GAINX_L_REG           	0xD4 	//	Gain of modulator0 and modulator1 for sequencer step 0
#define MT321X_MEAS_SEQR_STEP0_MOD_GAINX_H_REG           	0xD5 	//	Gain of modulator2 for sequencer step 0
#define MT321X_MEAS_SEQR_STEP1_MOD_GAINX_L_REG           	0xD6 	//	Gain of modulator0 and modulator1 for sequencer step 1
#define MT321X_MEAS_SEQR_STEP1_MOD_GAINX_H_REG           	0xD7	//	Gain of modulator2 for sequencer step 1
#define MT321X_MEAS_SEQR_STEP2_MOD_GAINX_L_REG           	0xD8	//	Gain of modulator0 and modulator1 for sequencer step 2
#define MT321X_MEAS_SEQR_STEP2_MOD_GAINX_H_REG           	0xD9 	//	Gain of modulator2 for sequencer step 2
#define MT321X_MEAS_SEQR_STEP3_MOD_GAINX_L_REG           	0xDA	//	Gain of modulator0 and modulator1 for sequencer step 3
#define MT321X_MEAS_SEQR_STEP3_MOD_GAINX_H_REG           	0xDB	//	Gain of modulator2 for sequencer step 3
#define MT321X_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_L_REG       	0xDC	//	Photodiode 0-3 to modulator mapping through multiplexer for sequencer step 0
#define MT321X_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_H_REG       	0xDD	//	Photodiode 4-5 to modulator mapping through multiplexer for sequencer step 0
#define MT321X_MEAS_SEQR_STEP1_MOD_PHDX_SMUX_L_REG       	0xDE	//	Photodiode 0-3 to modulator mapping through multiplexer for sequencer step 1
#define MT321X_MEAS_SEQR_STEP1_MOD_PHDX_SMUX_H_REG       	0xDF	//	Photodiode 4-5 to modulator mapping through multiplexer for sequencer step 1
#define MT321X_MEAS_SEQR_STEP2_MOD_PHDX_SMUX_L_REG       	0xE0	//	Photodiode 0-3 to modulator mapping through multiplexer for sequencer step 2
#define MT321X_MEAS_SEQR_STEP2_MOD_PHDX_SMUX_H_REG       	0xE1	//	Photodiode 4-5 to modulator mapping through multiplexer for sequencer step 2
#define MT321X_MEAS_SEQR_STEP3_MOD_PHDX_SMUX_L_REG       	0xE2	//	Photodiode 0-3 to modulator mapping through multiplexer for sequencer step 3
#define MT321X_MEAS_SEQR_STEP3_MOD_PHDX_SMUX_H_REG       	0xE3	//	Photodiode 4-5 to modulator mapping through multiplexer for sequencer step 3
#define MT321X_MOD_CALIB_CFG0_REG                        	0xE4 	//	Modulator calibration config0
#define MT321X_MOD_CALIB_CFG2_REG                        	0xE6 	//	Modulator calibration config2
#define MT321X_VSYNC_PERIOD_L_REG                        	0xF2	//	Measured VSYNC period
#define MT321X_VSYNC_PERIOD_H_REG                        	0xF3	//	Read and clear measured VSYNC period
#define MT321X_VSYNC_PERIOD_TARGET_L_REG                 	0xF4	//	Targeted VSYNC period
#define MT321X_VSYNC_PERIOD_TARGET_H7_REG                	0xF5	//	Alternative target VSYNC period
#define MT321X_VSYNC_CONTROL_REG                         	0xF6	//	Control of VSYNC period
#define MT321X_VSYNC_CFG_REG                             	0xF7	//	Configuration of VSYNC input
#define MT321X_VSYNC_GPIO_INT_REG                        	0xF8	//	Configuration of GPIO pin
#define MT321X_MOD_FIFO_DATA_CFG0_REG                    	0xF9	//	Configuration of FIFO access for modulator 0
#define MT321X_MOD_FIFO_DATA_CFG1_REG                    	0xFA	//	Configuration of FIFO access for modulator 1
#define MT321X_MOD_FIFO_DATA_CFG2_REG                    	0xFB	//	Configuration of FIFO access for modulator 2
#define MT321X_FIFO_THR_REG                              	0xFC	//	Configuration of FIFO threshold interrupt
#define MT321X_FIFO_STATUS0_REG                          	0xFD	//	FIFO status information 0
#define MT321X_FIFO_STATUS1_REG                          	0xFE 	//	FIFO status information 1
#define MT321X_FIFO_DATA_REG                             	0xFF	//	FIFO readout

#define PON  		                                        (0x01 << 0)
#define AEN  		                                        (0x01 << 1)
#define FDEN    	                                        (0x01 << 6)
#define INIT_BUSY                                           (0x01 << 7)

//Addr: 0xBA INTENAB	
#define MIEN                                                (0x01 << 7)
#define AIEN                                                (0x01 << 3)
#define FIEN                                                (0x01 << 2)
#define SIEN                                                (0x01 << 0)

//0xF8 reg definition
#define INT_INVERT                                          (0x01 << 6)
#define INT_IN_EN	                                        (0x01 << 5)
#define INT_IN	                                            (0x01 << 4)
#define VSYNC_GPIO_INVERT                                   (0x01 << 3)
#define VSYNC_GPIO_IN_EN                                    (0x01 << 2)	
#define VSYNC_GPIO_OUT	                                    (0x01 << 1)
#define VSYNC_GPIO_IN                                       (0x01 << 0)

//0xB1 reg definition
#define SOFT_RESET                                          (0x01 << 3)
#define FIFO_RCLR	                                        (0x01 << 2)
#define FIFO_WCLR	                                        (0x01 << 1)
#define CLEAR_SAI_ACTIVE                                    (0x01 << 0)

#define ASTEP_US_PER_100                                    0x8B
#define ASTEP_US(us)                                        (WORD)(((DWORD)us*100 + (ASTEP_US_PER_100 >> 1)) / ASTEP_US_PER_100)
#define UNIT_MS_TO_NS                                       1000000
#define ALS_NR_TIME                                         50
#define ALS_SAMPLE_TIME                                     2000//500ms
#define I2C_FIFO_BUFFER_SIZE                                (256)

/* Default ALS/Color equation coefficients */
#define D_Factor                        	                3200  
#define Lux_Coef_H_F                                        30//单体
#define Lux_Coef_H_R                                        -40
#define Lux_Coef_H_G                                        107
#define Lux_Coef_H_B                                        46
#define Lux_Coef_H_IR                                       0

#define Lux_Coef_L_F                                        37
#define Lux_Coef_L_R                                        -22
#define Lux_Coef_L_G                                        28
#define Lux_Coef_L_B                                        34
#define Lux_Coef_L_IR                                       0 

#define CCT_Coef_H_BR                                        4570
#define CCT_Coef_H_BG                                        -3438
#define CCT_Coef_H_GR                                        6106
#define CCT_Coef_L_BR                                        2282
#define CCT_Coef_L_BG                                        -575
#define CCT_Coef_L_GR                                        4218

//reg 0xD4~0xDB reg definition
#define GAIN_SHIFT                                          0
#define GAIN_1X                                             (0x00 << GAIN_SHIFT)
#define GAIN_2X                                             (0x01 << GAIN_SHIFT)
#define GAIN_4X                                             (0x02 << GAIN_SHIFT)
#define GAIN_8X                                             (0x03 << GAIN_SHIFT)
#define GAIN_16X                                            (0x04 << GAIN_SHIFT)
#define GAIN_32X                                            (0x05 << GAIN_SHIFT)
#define GAIN_64X                                            (0x06 << GAIN_SHIFT)
#define GAIN_128X                                           (0x07 << GAIN_SHIFT)
#define GAIN_256X                                           (0x08 << GAIN_SHIFT)
#define GAIN_512X                                           (0x09 << GAIN_SHIFT)
#define GAIN_1024X                                          (0x0A << GAIN_SHIFT)
#define GAIN_2048X                                          (0x0B << GAIN_SHIFT)
#define GAIN_4096X                                          (0x0C << GAIN_SHIFT)
#define GAIN_8192X                                          (0x0D << GAIN_SHIFT)

typedef struct mt321x_rgb_raw_info
{
    DWORD ir_raw;
    DWORD red_raw;
    DWORD green_raw;
    DWORD blue_raw;
    DWORD flicker_raw;
    DWORD step;
    DWORD old_step;
    DWORD old_final_r;
    DWORD old_final_g;
    DWORD old_final_b;
    DWORD old_cct;
	
	SBYTE calc_ir;
	SBYTE ir_rate;
} mt321x_rgbc_raw_info;

typedef struct mt321x_rgb_info
{
	SBYTE dgf;
	SBYTE lux_coef_h_f;
	SBYTE lux_coef_h_r;
	SBYTE lux_coef_h_g;
	SBYTE lux_coef_h_b;
	SBYTE lux_coef_h_ir;
	
	SBYTE lux_coef_l_f;
	SBYTE lux_coef_l_r;
	SBYTE lux_coef_l_g;
	SBYTE lux_coef_l_b;
	SBYTE lux_coef_l_ir;
	
	SBYTE cct_coef_h_br;
	SBYTE cct_coef_h_bg;
	SBYTE cct_coef_h_gr;

	SBYTE cct_coef_l_br;
	SBYTE cct_coef_l_bg;
	SBYTE cct_coef_l_gr;

	SBYTE target_lux;
	SBYTE lux;
	SBYTE cct;
} mt321x_rgb_info;

struct mt321x_chip
{
	BYTE rgb_debounce_time;
	BYTE rgb_debounce_on; /* indicates if the debounce is on */
	BYTE bus_id;
	BYTE slave_addr;

    BYTE polling_timer_started_rgb;
    BYTE polling_mode_rgb;
	BYTE irq_enabled;
	BYTE rgb_enabled;

	DWORD fd_saturation_val;
	DWORD rgb_saturation_val;

	WORD rgb_gain;
	WORD fd_gain;

	DWORD sample_time_us;
	DWORD rgb_time_us;

	SDWORD history_values[5];
	SDWORD history_ages[5];
	/* Raw data of RGBC */
	mt321x_rgbc_raw_info rgbc_raw;

	/* Ambient light HW config details*/
	mt321x_rgb_info rgb_info;
	BYTE first_rgb;

	BYTE use_default_lux_params;
	BYTE fd_gain_adjusted;

	BYTE start_ts;
	BYTE end_ts;
	WORD flicker_data0;
	WORD flicker_data1;
	DWORD ir_r_revise_coeff;
	DWORD g_b_revise_coeff;
	WORD als_low_th;
	WORD als_high_th;
	BYTE eint_num;
};

typedef struct mt321x_reg_setting
{
	BYTE reg;
	BYTE value;
} mt321x_reg_setting;


static struct mt321x_chip mt321x_dev;

BYTE mt321x_soft_reset(void)
{
	BYTE P_ON[1] = PON;
    BYTE SOFTRESET[1] = SOFT_RESET;

    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_ENABLE_REG, 1, P_ON);
    ScalerTimerDelayXms(2);
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_CONTROL_REG, 1, SOFTRESET);
    ScalerTimerDelayXms(5);
	return 0;
}

void mt321x_device_set_default(void)
{
	BYTE i = 0;
	BYTE setting_num=0;

	mt321x_reg_setting default_setting[] = {
		// step1: default setting
		{0x20, 0x6c},
		{0xAB, 0x03},
		{0x25, 0x51},
		{0xE6, 0x00},
	
		// step2: modulator/step/pd mux control
		{0x40, 0x00},//open mod0/1/2
		{0x81, 0x00},//scale=0
        {0x83, 0x64},
        {0x85, 0xFF},
        {0x86, 0x01},
		{0xCF, 0x00},//FD step0 mod0
		{0xA9, 0xd0},
        {0xBA, 0x08},//ALS Interupt enable
		
		//step0 FIRR  step1 FGB
		{0xDC, 0x20},//step0 FD PD0->mod0 PD1->mod1 
		{0xDD, 0x0d},//step0 PD5->mod2  //0d
	
		{0xDE, 0x8f},//step1 FD PD0->mod0 PD3->mod1
		{0xDF, 0x01},//step1 PD4->mod2
		{0xE0, 0x00},
		{0xE1, 0x00},
		{0xE2, 0x00},
		{0xE3, 0x00},

		// step3: ALS/Flicker sample_time/nr_samples/waittime
		{0x83, 0xcf},
		{0x84, 0x02},
		{0x85, 0x31},
		{0x86, 0x00},
		{0x87, 0x32},
		{0x88, 0x00},
		{0xD0, 0x03},//open step0/1 mod0/1
		{0xD3, 0x00},//waittime=0
	};
	setting_num =(int)sizeof(default_setting)/sizeof(mt321x_reg_setting);
    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
	for (i = 0; i < setting_num; i++)
	{
        ScalerMcuIICWrite(ADDR_MT3212_CT, 1, default_setting[i].reg, 1, &(default_setting[i].value));
	}
	return;
}

BYTE mt321x_detect(void)
{
	BYTE part_id[1] = 0, manu_id[1] = 0;

    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
	mt321x_soft_reset();
	// check chip id
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_L_REG, 1, &part_id);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_H_REG, 1, &manu_id);

	if ((part_id[0] != 0x66) && (manu_id[0] != 0x19))
	{
        DebugMessageSystem("mt321x_detect------------------ng",1);
        return 1;
	}
	else
	{
        DebugMessageSystem("mt321x_detect------------------PASS",1);
        return 0;
	}
}

void mt321x_set_rgb_flicker_sample_time(DWORD sample_time_us)
{
	WORD sample_time_reg;
    BYTE Sample_Time[2] = {0, 0};
	sample_time_reg = ASTEP_US(sample_time_us) - 5; // adc reset time = 1

	if (sample_time_reg > 0x7ff)
	{
		sample_time_reg = 0x7ff;
	}
    mt321x_dev.fd_saturation_val = sample_time_reg + 4;
	mt321x_dev.sample_time_us = sample_time_us;
    Sample_Time[0] = mt321x_dev.fd_saturation_val;
    Sample_Time[1] = mt321x_dev.sample_time_us;
    
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_SAMPLE_TIME0_REG, 1, &(Sample_Time[0]));
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_SAMPLE_TIME1_REG, 1, &(Sample_Time[1]));
}

void mt321x_set_rgb_nr_samples(WORD rgb_nr_samples)
{
    BYTE Rgb_Time[2] = {0, 0};

	if (rgb_nr_samples > 0x7ff)
	{
		rgb_nr_samples = 0x7ff;
	}
    mt321x_dev.rgb_saturation_val = mt321x_dev.fd_saturation_val * rgb_nr_samples;
    Rgb_Time[0] = (BYTE)(rgb_nr_samples & 0xff);
    Rgb_Time[1] = (BYTE)(rgb_nr_samples >> 8);

    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_ALS_NR_SAMPLES0_REG, 1, &(Rgb_Time[0]));
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_ALS_NR_SAMPLES1_REG, 1, &(Rgb_Time[1]));
}

void maxic_i2c_modify(BYTE reg, BYTE mask, BYTE val)
{
	BYTE ret;
    BYTE part_id[1] = 0;
	BYTE temp;

    ScalerMcuIICRead(ADDR_MT3212_CT, 1, reg, 1, &part_id);
	ret = part_id[1];
	temp &= ~mask;
	temp |= val;
    part_id[0] = temp;
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, reg, 1, &(part_id[0]));
}

void mt321x_set_rgb_integration_time_us(DWORD rgb_time_us)
{
	DWORD rgb_nr_samples = 0;

	if (0 == mt321x_dev.sample_time_us)
	{
		return;
	}

    rgb_nr_samples = rgb_time_us / mt321x_dev.sample_time_us;
	mt321x_set_rgb_nr_samples(rgb_time_us / mt321x_dev.sample_time_us);
    mt321x_dev.rgb_time_us = rgb_time_us;
}

void mt321x_set_low_high_threshold( WORD low_th, WORD high_th)
{
	BYTE th[4];

    th[0] = low_th & 0xff;
    th[1] = (low_th >> 8) & 0xff;
    th[2] = high_th & 0xff;
    th[3] = (high_th >> 8) & 0xff;
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_AILT0_REG, 1, &(th[0]));
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_AILT1_REG, 1, &(th[1]));
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_AIHT0_REG, 1, &(th[2]));
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_AIHT1_REG, 1, &(th[3]));

	mt321x_dev.als_low_th = low_th;
	mt321x_dev.als_high_th = high_th;
}

void mt321x_clear_fifo(void)
{
    BYTE th[1] = {FIFO_RCLR | FIFO_WCLR};
    ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_CONTROL_REG, 1, &(th[0]));
	return;
}

void mt321x_set_rgb_flicker_gain( WORD gain)
{
	BYTE mod0_1_gain[1] = 0;
	BYTE mod2_gain[1] = 0;
	BYTE cfg1 = 0;
	BYTE i = 0;

	switch (gain)
	{
	case 1:
		cfg1 = GAIN_1X;
		break;
	case 2:
		cfg1 = GAIN_2X;
		break;
	case 4:
		cfg1 = GAIN_4X;
		break;
	case 8:
		cfg1 = GAIN_8X;
		break;
	case 16:
		cfg1 = GAIN_16X;
		break;
	case 32:
		cfg1 = GAIN_32X;
		break;
	case 64:
		cfg1 = GAIN_64X;
		break;
	case 128:
		cfg1 = GAIN_128X;
		break;
	case 256:
		cfg1 = GAIN_256X;
		break;
	case 512:
		cfg1 = GAIN_512X;
		break;
	case 1024:
		cfg1 = GAIN_1024X;
		break;
	case 2048:
		cfg1 = GAIN_2048X;
		break;
	case 4096:
		cfg1 = GAIN_4096X;
		break;
	case 8192:
		cfg1 = GAIN_8192X;
		break;
	default:
		break;
	}

	if (cfg1 == 0)
	{
		mod0_1_gain[0] = cfg1 << 4 | cfg1;
		mod2_gain[0] = cfg1;
	}
	else
	{
		mod0_1_gain[0] = cfg1 << 4 | (cfg1 - 1);
		mod2_gain[0] = cfg1;
	}

	for (i = 0xd4; i <= 0xdb; i += 2)
	{
        ScalerMcuIICWrite(ADDR_MT3212_CT, 1, i, 1, &(mod0_1_gain[0]));
        ScalerMcuIICWrite(ADDR_MT3212_CT, 1, i + 1, 1, &(mod2_gain[0]));
	}

	mt321x_dev.rgb_gain = gain;
	mt321x_dev.fd_gain = gain;
}

SDWORD mt321x_do_initialization(void)
{
	BYTE Val0[1] = {0x01};
    BYTE Val1[1] = {0x03};
    // do a power on reset
	mt321x_soft_reset();
	mt321x_device_set_default();

	mt321x_set_rgb_flicker_sample_time(ALS_SAMPLE_TIME);			   // set default sample time to 1000us
	mt321x_set_rgb_integration_time_us((ALS_NR_TIME-7) * ALS_SAMPLE_TIME); // set default als integration time 50ms

	// other parameter initial
	mt321x_dev.rgb_enabled = 0;
	mt321x_dev.polling_timer_started_rgb = 0;

	mt321x_dev.irq_enabled = 0;
	mt321x_dev.start_ts = 0;
	mt321x_dev.end_ts = 0;

	mt321x_dev.use_default_lux_params = 1;
	mt321x_dev.first_rgb = 1;

	if (mt321x_dev.use_default_lux_params == 1)
	{
		mt321x_dev.rgb_info.dgf = D_Factor;
		mt321x_dev.rgb_info.lux_coef_h_f = Lux_Coef_H_F;
		mt321x_dev.rgb_info.lux_coef_h_r = Lux_Coef_H_R;
		mt321x_dev.rgb_info.lux_coef_h_g = Lux_Coef_H_G;
		mt321x_dev.rgb_info.lux_coef_h_b = Lux_Coef_H_B;
		mt321x_dev.rgb_info.lux_coef_h_ir = Lux_Coef_H_IR;
		
		mt321x_dev.rgb_info.lux_coef_l_f = Lux_Coef_L_F;
		mt321x_dev.rgb_info.lux_coef_l_r = Lux_Coef_L_R;
		mt321x_dev.rgb_info.lux_coef_l_g = Lux_Coef_L_G;
		mt321x_dev.rgb_info.lux_coef_l_b = Lux_Coef_L_B;
		mt321x_dev.rgb_info.lux_coef_l_ir = Lux_Coef_L_IR;
		
		mt321x_dev.rgb_info.cct_coef_h_br = CCT_Coef_H_BR;
		mt321x_dev.rgb_info.cct_coef_h_bg = CCT_Coef_H_BG;
		mt321x_dev.rgb_info.cct_coef_h_gr = CCT_Coef_H_GR;

		mt321x_dev.rgb_info.cct_coef_l_br = CCT_Coef_L_BR;
		mt321x_dev.rgb_info.cct_coef_l_bg = CCT_Coef_L_BG;
		mt321x_dev.rgb_info.cct_coef_l_gr = CCT_Coef_L_GR;
	}

	if (mt321x_dev.polling_mode_rgb == 0) // interrupt mode
	{
		// enable AIEN
		maxic_i2c_modify(MT321X_INTENAB_REG, AIEN, AIEN);

		// mod0 high/low threshold setting
		mt321x_set_low_high_threshold(0, 0);

		// apers setting 0xA6[3:0]; default value is 0x00
        ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_CFG5_REG, 1, &Val0);

		// apers pattern setting 0xD1[3:0], default value is 0x01
        ScalerMcuIICWrite(ADDR_MT3212_CT, 1, MT321X_MEAS_SEQR_APERS_AND_VSYNC_WAIT_REG, 1, &Val1);
	}

	// int invert
	maxic_i2c_modify(MT321X_VSYNC_GPIO_INT_REG, INT_INVERT, INT_INVERT);

	return 0;
}

static SDWORD mt321x_rgb_enable(BYTE on)
{
	SDWORD ret = 0;
	BYTE i = 0;

	if (on)
	{
		mt321x_do_initialization();

		if (mt321x_dev.rgb_enabled == 0)
		{
			mt321x_dev.rgb_enabled = 1;
			mt321x_dev.first_rgb = 1;
			mt321x_dev.fd_gain_adjusted = 0;
			mt321x_dev.flicker_data0 = 0;
			mt321x_dev.flicker_data1 = 0;
			mt321x_dev.ir_r_revise_coeff = 0;
			mt321x_dev.g_b_revise_coeff = 0;
			// clear fifo
			mt321x_clear_fifo();
			mt321x_set_rgb_flicker_gain(4); // set default gain to 4x

			for (i = 0; i < 5; i++)
			{
				mt321x_dev.history_values[i] = 0;
				mt321x_dev.history_ages[i] = 0;
			}
			maxic_i2c_modify(MT321X_ENABLE_REG, AEN | PON, AEN  | PON);//open als
			mt321x_dev.rgb_debounce_on = 1;

			if ((mt321x_dev.polling_mode_rgb == 1) && (mt321x_dev.polling_timer_started_rgb == 0))
			{
				//GENERAL_TIM_Init();//定时器初始化 200ms
			}
			else if ((mt321x_dev.polling_mode_rgb == 0) && (mt321x_dev.irq_enabled == 0))
			{
				// register irq, no use currently
				mt321x_dev.irq_enabled = 1;
			}
		}
		else
		{
			ret = 1;
		}
	}
	else
	{
		if (mt321x_dev.rgb_enabled == 1)
		{
			mt321x_dev.rgb_enabled = 0;
			mt321x_dev.fd_gain_adjusted = 0;

			maxic_i2c_modify(MT321X_ENABLE_REG, AEN  | PON, PON);//close als

			if ((mt321x_dev.polling_mode_rgb == 1) && (mt321x_dev.polling_timer_started_rgb == 1))
			{
				mt321x_dev.polling_timer_started_rgb = 0;
			}
			else if (mt321x_dev.polling_mode_rgb == 0)
			{
				mt321x_dev.irq_enabled = 0;
			}
			memset(&mt321x_dev.rgbc_raw, 0, sizeof(mt321x_dev.rgbc_raw));
		}
		else
		{
			ret = -1;
		}
	}

	return ret;
}

int mt321x_enable(void)
{
	int ret = 0;
	
	ret = mt321x_rgb_enable(1);
    DebugMessageSystem("mt321x_enable------------------mt321x_enable",ret);
	return ret;
}

int mt321x_disable(void)
{
	int ret = 0;

	ret = mt321x_rgb_enable(0);
    DebugMessageSystem("mt321x_disable------------------mt321x_enable",ret);
	return ret;
}

void mt321x_swap(SDWORD *a, SDWORD *b)
{
	SDWORD temp = *a;
	*a = *b;
	*b = temp;
}

bit mt321x_auto_gain_adjust(WORD crgbf_max)
{
	bit again_adjusted = 1;
	DWORD saturation = mt321x_dev.rgb_saturation_val;
	DWORD insufficience = 0;
	WORD again = mt321x_dev.rgb_gain;

	insufficience = saturation * 1 / 10;
	saturation = saturation * 8 / 10;

	if (again == 1024 && crgbf_max < insufficience) // flicker_raw is more fixable than crgb, only used in mod0
	{
		mt321x_set_rgb_flicker_gain( 4096);

	}
	else if ((again == 4096 && (crgbf_max > saturation)) || (again == 256 && crgbf_max < insufficience))
	{
		mt321x_set_rgb_flicker_gain( 1024);

	}
	else if ((again == 1024 && (crgbf_max > saturation)) || (again == 64 && crgbf_max < insufficience))
	{
		mt321x_set_rgb_flicker_gain( 256);
		
	}
	else if ((again == 256 && (crgbf_max > saturation)) || (again == 16 && crgbf_max < insufficience))
	{
		mt321x_set_rgb_flicker_gain( 64);

	}
	else if ((again == 64 && (crgbf_max > saturation)) || (again == 4 && crgbf_max < insufficience))
	{
		mt321x_set_rgb_flicker_gain( 16);

	}
	else if ((again == 16 && (crgbf_max > saturation)) || (again == 1 && crgbf_max < insufficience))
	{
		mt321x_set_rgb_flicker_gain( 4);
	
	}
	else if (again == 4 && (crgbf_max > saturation))
	{
		mt321x_set_rgb_flicker_gain( 1);
	
	}
	else
	{
		again_adjusted = 0;
	}

	return again_adjusted;
}

BYTE ScalerMcuMt3212CtInit(void)
{
	BYTE ret = 0;

	ret = mt321x_detect();
	if (ret > 0)
		return ret;

    mt321x_enable();
	return 0;
}

void ScalerMcuGetMt3212CtData(void)
{
    BYTE R_H[1], R_L[1] = 0x00;
    BYTE G_H[1], G_L[1] = 0x00;
    BYTE B_H[1], B_L[1] = 0x00;
    BYTE ALS_Status[1] = 0;
    BYTE ALS_Vaild[1] = 0;
    WORD R = 0x0000;
    WORD G = 0x0000;
    WORD B = 0x0000;

    BYTE ColorTempR = 0x00;
    BYTE ColorTempG = 0x00;
    BYTE ColorTempB = 0x00;

    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_STATUS_REG, 1, &ALS_Status);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_STATUS2_REG, 1, &ALS_Vaild);
    if((ALS_Vaild[0] & 0x40) == 0)
    {
        return;
    }
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA0_H_REG, 1, &R_H);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA0_L_REG, 1, &R_L);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA1_H_REG, 1, &G_H);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA1_L_REG, 1, &G_L);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA2_H_REG, 1, &B_H);
    ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_DATA2_L_REG, 1, &B_L);

    R = (R_H[0] << 8) | R_L[0];
    G = (G_H[0] << 8) | G_L[0];
    B = (B_H[0] << 8) | B_L[0];
    R = (R >= 12000)?12000:R;
    R = (R < 1200)?1200:R;
    G = (G >= 12000)?12000:G;
    G = (G < 1200)?1200:G;
    B = (B >= 12000)?12000:B;
    B = (B < 1200)?1200:B;

    //CONVERT COLOR TEMP
    ColorTempR = (R/155) + 38;
    ColorTempG = (G/155) + 38;
    ColorTempB = (B/155) + 38;
    // SET_COLOR_TEMP_TYPE_USER_R(ColorTempR);
    // SET_COLOR_TEMP_TYPE_USER_G(ColorTempG);
    // SET_COLOR_TEMP_TYPE_USER_B(ColorTempB);
}

int mt321x_get_lux_cct(void)
{
	WORD again = mt321x_dev.rgb_gain;
	DWORD atime = mt321x_dev.rgb_time_us;

	int lux = 0;
	BYTE reg_val[7] = {0};
	DWORD als_data0_reg = 0;
	DWORD als_data1_reg = 0;
	DWORD als_data2_reg = 0;
	BYTE reg_val_sec[7] = {0};
	DWORD als_data0_reg_sec = 0;
	DWORD als_data1_reg_sec = 0;
	DWORD als_data2_reg_sec = 0;
	static BYTE temp_count = 0;
	SDWORD br_rate = 0;
	SDWORD bg_rate = 0;
	SDWORD gr_rate = 0;
	float r_k = 0;
	float g_k = 0;
	float b_k = 0;
    BYTE i;
	
	SDWORD cct = 0;
	SDWORD origin_ir_rate = 0;
	SDWORD origin_calc_ir = 0;

	bit again_adjusted = 0;
	WORD crgbf_raw_data[5] = {0};
	WORD crgbf_max = 0;

	DWORD little_val = mt321x_dev.rgb_saturation_val / 10;
	SDWORD final_ir = 0, final_r = 0, final_g = 0, final_b = 0, final_flicker = 0;

	// Read out ALS raw data
    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
    for(i = 0; i < 7; i++)
    {
        ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_STATUS_REG+i, 1, &(reg_val[i]));
    }

	als_data0_reg = (DWORD)((reg_val[2] << 8) | reg_val[1]);
	als_data1_reg = (DWORD)((reg_val[4] << 8) | reg_val[3]);
	als_data2_reg = (DWORD)((reg_val[6] << 8) | reg_val[5]);

	// Read out ALS raw data second
    for(i = 0; i < 7; i++)
    {
        ScalerMcuIICRead(ADDR_MT3212_CT, 1, MT321X_ALS_STATUS_REG+i, 1, &(reg_val_sec[i]));
    }
	als_data0_reg_sec = (DWORD)((reg_val_sec[2] << 8) | reg_val_sec[1]);
	als_data1_reg_sec = (DWORD)((reg_val_sec[4] << 8) | reg_val_sec[3]);
	als_data2_reg_sec = (DWORD)((reg_val_sec[6] << 8) | reg_val_sec[5]);

	if (((reg_val[0] & 0xC0) >> 6) == ((reg_val_sec[0] & 0xC0) >> 6))
	{
		if ((als_data0_reg_sec != als_data0_reg) && (als_data1_reg_sec != als_data1_reg) && (als_data2_reg_sec != als_data2_reg))
		{
			temp_count++;
			goto sample_exit;
		}
	}

	if ((als_data0_reg_sec == als_data0_reg) && (als_data1_reg_sec == als_data1_reg) && (als_data2_reg_sec == als_data2_reg))
	{
		if (((reg_val[0] & 0xC0) >> 6) != ((reg_val_sec[0] & 0xC0) >> 6))
		{
			temp_count++;
			goto sample_exit;
		}
	}

	if ((reg_val[0] & 0xC0) >> 6 == 1) // step1
	{

		mt321x_dev.rgbc_raw.flicker_raw = als_data0_reg;
		mt321x_dev.rgbc_raw.ir_raw = als_data1_reg;
		mt321x_dev.rgbc_raw.red_raw = als_data2_reg;
		mt321x_dev.flicker_data0 = mt321x_dev.rgbc_raw.flicker_raw;

		if (mt321x_dev.flicker_data1 != 0)
		{
			mt321x_dev.g_b_revise_coeff = mt321x_dev.flicker_data0 * 1000 / mt321x_dev.flicker_data1;
		}
		else
		{
			mt321x_dev.g_b_revise_coeff = 1000;
		}
	}
	else if ((reg_val[0] & 0xC0) >> 6 == 0) // step0
	{

		mt321x_dev.rgbc_raw.flicker_raw = als_data0_reg;
		mt321x_dev.rgbc_raw.green_raw = als_data1_reg;
		mt321x_dev.rgbc_raw.blue_raw = als_data2_reg;
		mt321x_dev.flicker_data1 = mt321x_dev.rgbc_raw.flicker_raw;

		if (mt321x_dev.flicker_data0 != 0)
		{
			mt321x_dev.ir_r_revise_coeff = mt321x_dev.flicker_data1 * 1000 / mt321x_dev.flicker_data0;
		}
		else
		{
			mt321x_dev.ir_r_revise_coeff = 1000;
		}
	}

	origin_calc_ir = (mt321x_dev.rgbc_raw.red_raw + mt321x_dev.rgbc_raw.green_raw + mt321x_dev.rgbc_raw.blue_raw - mt321x_dev.rgbc_raw.ir_raw) / 2;

	if (mt321x_dev.rgbc_raw.flicker_raw != 0)
	{
		origin_ir_rate = origin_calc_ir * 1000 / mt321x_dev.rgbc_raw.flicker_raw;
		if (origin_ir_rate < 0)
		{
			origin_ir_rate = 0;
		}
	}

	if (mt321x_dev.rgbc_raw.flicker_raw == 0)
	{
		lux = 0;
		cct = 0;
		goto sample_exit;
	}
	if ((reg_val[0] & 0xC0) >> 6 == 1) // step0
	{

		final_flicker = mt321x_dev.rgbc_raw.flicker_raw;
		final_ir = mt321x_dev.rgbc_raw.ir_raw;
		final_r =mt321x_dev.rgbc_raw.red_raw;
		final_g =mt321x_dev.rgbc_raw.green_raw *  mt321x_dev.g_b_revise_coeff / 1000;
		final_b =mt321x_dev.rgbc_raw.blue_raw *  mt321x_dev.g_b_revise_coeff / 1000;
	}
	else if ((reg_val[0] & 0xC0) >> 6 == 0) // step1
	{

		final_flicker =mt321x_dev.rgbc_raw.flicker_raw;
		final_ir =mt321x_dev.rgbc_raw.ir_raw *  mt321x_dev.ir_r_revise_coeff / 1000;
		final_g =mt321x_dev.rgbc_raw.green_raw;
		final_r =mt321x_dev.rgbc_raw.red_raw *  mt321x_dev.ir_r_revise_coeff / 1000;
		final_b =mt321x_dev.rgbc_raw.blue_raw;
	}
	crgbf_raw_data[0] = mt321x_dev.rgbc_raw.ir_raw;
	crgbf_raw_data[1] = mt321x_dev.rgbc_raw.red_raw;
	crgbf_raw_data[2] = mt321x_dev.rgbc_raw.green_raw;
	crgbf_raw_data[3] = mt321x_dev.rgbc_raw.blue_raw;
	crgbf_raw_data[4] = mt321x_dev.rgbc_raw.flicker_raw;
    DebugMessageSystem("ir_raw------------------",mt321x_dev.rgbc_raw.ir_raw);
    DebugMessageSystem("red_raw------------------",mt321x_dev.rgbc_raw.red_raw);
    DebugMessageSystem("green_raw------------------",mt321x_dev.rgbc_raw.green_raw);
    DebugMessageSystem("blue_raw------------------",mt321x_dev.rgbc_raw.blue_raw);
    DebugMessageSystem("flicker_raw------------------",mt321x_dev.rgbc_raw.flicker_raw);
    crgbf_max = crgbf_raw_data[0]; // 初始化最大值为第一个元素
    
    // 遍历数组其余元素
    for (i = 1; i < 5; i++) {
        if (crgbf_raw_data[i] > crgbf_max) {
            crgbf_max = crgbf_raw_data[i];
        }
    }

	if (mt321x_dev.first_rgb)
	{
		mt321x_dev.first_rgb = 0;
		// default sample time is 1ms, so saturation value is 720*50. 720*50*80% = 576 default gain is 8x
		if (crgbf_max <= 29)
		{
			mt321x_set_rgb_flicker_gain( 4096);
			again_adjusted = 1;
		}
		else if (crgbf_max <= 113)
		{
			mt321x_set_rgb_flicker_gain( 1024);
			again_adjusted = 1;
		}
		else if (crgbf_max <= 450)
		{
			mt321x_set_rgb_flicker_gain( 256);
			again_adjusted = 1;
		}
		else if (crgbf_max <= 1800)
		{
			mt321x_set_rgb_flicker_gain( 64);
		
			again_adjusted = 1;
		}
		else if (crgbf_max <= 7200)
		{
			mt321x_set_rgb_flicker_gain(16);
			
			again_adjusted = 1;
		}
		else if (crgbf_max <= 28800) // default fd gain is 4x
		{
			//nothing to do
		}
		else
		{
			mt321x_set_rgb_flicker_gain(1);
			again_adjusted = 1;
		}
	}
	else
	{
		again_adjusted = mt321x_auto_gain_adjust( crgbf_max);
	}


	if (again_adjusted)
	{
		goto sample_exit;
	}

	if (mt321x_dev.flicker_data0 == 65535 || mt321x_dev.flicker_data1 == 65535)
	{
		goto sample_exit; // this case, canno use g_b_revise_coeff or ir_r_revise_coeff, so exit.
	}

	mt321x_dev.rgbc_raw.calc_ir = (final_r + final_g + final_b - final_flicker) / 2;
	if (mt321x_dev.rgbc_raw.calc_ir < 0)
	{
		mt321x_dev.rgbc_raw.calc_ir = 0;
	}

	mt321x_dev.rgbc_raw.ir_rate = (final_ir * 1000) / final_g;

	if (mt321x_dev.rgbc_raw.ir_rate < 1000) 
	{
		lux = final_flicker * mt321x_dev.rgb_info.lux_coef_l_f + final_r * mt321x_dev.rgb_info.lux_coef_l_r +
			  final_g * mt321x_dev.rgb_info.lux_coef_l_g + final_b * mt321x_dev.rgb_info.lux_coef_l_b + final_ir * mt321x_dev.rgb_info.lux_coef_l_ir;
	}
	else
	{
		lux = final_flicker * mt321x_dev.rgb_info.lux_coef_h_f + final_r * mt321x_dev.rgb_info.lux_coef_h_r +
			  final_g * mt321x_dev.rgb_info.lux_coef_h_g + final_b * mt321x_dev.rgb_info.lux_coef_h_b+ final_ir * mt321x_dev.rgb_info.lux_coef_h_ir;
	}
    DebugMessageSystem("lux------------------",lux);
	if (lux < 0)
	{
		lux = 0;
	}

	atime /= 1000;
	if (lux > (int)(again * atime))
	{
		lux /= (atime * again);
		lux *= mt321x_dev.rgb_info.dgf;
	}
	else
	{
		lux *= mt321x_dev.rgb_info.dgf;
		lux /= (atime * again);
	}

	lux += 500;
	lux /= 1000;

	// calculate CCT
	br_rate = (final_b * 1000) / final_r;
	bg_rate = (final_b * 1000) / final_g;
	gr_rate = (final_g * 1000) / final_r;

	if (mt321x_dev.rgbc_raw.ir_rate < 1000)
	{
		cct = (mt321x_dev.rgb_info.cct_coef_l_br * br_rate + mt321x_dev.rgb_info.cct_coef_l_bg * bg_rate + mt321x_dev.rgb_info.cct_coef_l_gr * gr_rate) / 1000;
	}
	else
	{
		cct = (mt321x_dev.rgb_info.cct_coef_h_br * br_rate + mt321x_dev.rgb_info.cct_coef_h_bg * bg_rate + mt321x_dev.rgb_info.cct_coef_h_gr * gr_rate) / 1000;
	}
    DebugMessageSystem("cct------------------",cct);
	if (cct < 0)
	{
		cct = 0;
	}

	if ((reg_val[0] & 0xC0) >> 6 == 1) // step1
	{

		mt321x_dev.rgbc_raw.step = 1;
	}
	else if ((reg_val[0] & 0xC0) >> 6 == 0) // step0
	{
		mt321x_dev.rgbc_raw.step = 0;
	}
	
	r_k = (float)mt321x_dev.rgbc_raw.old_final_r/(float)final_r;
	g_k = (float)mt321x_dev.rgbc_raw.old_final_g/(float)final_g;
	b_k = (float)mt321x_dev.rgbc_raw.old_final_b/(float)final_b;
	
	if((r_k/b_k>1.2) || (r_k/b_k<0.8) || (r_k/g_k>1.2) || (r_k/g_k<0.8) || (g_k/b_k>1.2) || (g_k/b_k<0.8))
	{
		cct = mt321x_dev.rgbc_raw.old_cct;
	}

	mt321x_dev.rgbc_raw.old_cct = cct;
	mt321x_dev.rgbc_raw.old_final_r = final_r;
	mt321x_dev.rgbc_raw.old_final_g = final_g;
	mt321x_dev.rgbc_raw.old_final_b = final_b;
	mt321x_dev.rgbc_raw.old_step = mt321x_dev.rgbc_raw.step;

	// Reserve one digit after the decimal point
	mt321x_dev.rgb_info.lux = lux;
	mt321x_dev.rgb_info.cct = cct;
	return 0;

sample_exit:
	mt321x_dev.g_b_revise_coeff = 1000;
	mt321x_dev.ir_r_revise_coeff = 1000;
	if (temp_count == 1)
	{
		temp_count = 0;
		mt321x_set_rgb_flicker_gain(4);
		mt321x_set_rgb_integration_time_us((ALS_NR_TIME -7) * 2000); // set default als integration time 50ms
	}
	return 1;
}
#endif

#if _LS_PS_SUPPORT
typedef struct LS_PS_setting
{
	BYTE reg;
	BYTE value;
} LS_PS_setting;

#define ADDR_LS_PS                          0xA8
#define LS_SUB_ADDR_ENABLE                  0x00
#define LS_SUB_ADDR_CTRL                    0x01
#define LS_SUB_ADDR_RESET                   0x02
#define LS_SUB_ADDR_INT1                    0x04
#define LS_SUB_ADDR_READY                   0x2C
#define LS_SUB_ADDR_ALS_L                   0x2F
#define LS_SUB_ADDR_ALS_H                   0x30
#define LS_SUB_ADDR_PS_L                    0x35
#define LS_SUB_ADDR_PS_H                    0x36
//distance MAP
#define PS_MAX_VAL                          0x119
#define PS_CEN_VAL                          0x110
#define PS_MIN_VAL                          0x10A
//ALS MAP
#define ALS_MAX_VAL                         0x46DB
#define ALS_CEN_VAL                         0x2A00
#define ALS_MIN_VAL                         0x0382

void ScalerMcuLSPsReset(void)
{
    BYTE Data1[1] = 0x80;
    ScalerMcuIICWrite(ADDR_LS_PS, 1, LS_SUB_ADDR_RESET, 1, Data1);
    ScalerTimerDelayXms(20);
}

void ScalerMcuLSPsInit(void)
{
    BYTE Data1[1] = 0x67;
    int setting_num = 0;
    int i = 0;

    LS_PS_setting default_table[] = {
        {0x10, 0x23},
        {0x15, 0x01},
        {0x62, 0x0D},
        {0x63, 0x01},
        {0x29, 0x51},
        {0x19, 0x4C},
        {0x1B, 0x4A},
        {0x00, 0x00},
        {0x01, 0x05},
        {0x11, 0x32},
        {0x12, 0xFF},
        {0x13, 0x1F},
        {0x16, 0x77},
        {0x17, 0x66},
        {0x04, 0x0A},
        {0x05, 0xCC},
        {0x1D, 0x0F},
        {0x22, 0x56},
        {0x24, 0x03},
        {0x1E, 0x0F},
        {0x23, 0x3B},
        {0x1F, 0x06},
        {0x21, 0x07},
        {0x26, 0x00},
        {0x25, 0x00},
	};

    SET_SW_IIC_STATUS(_IIC_LS_PS);
    ScalerMcuLSPsReset();
    setting_num =(int)sizeof(default_table)/sizeof(LS_PS_setting);
    SET_SW_IIC_STATUS(_IIC_MT3212_CT);
	for (i = 0; i < setting_num; i++)
	{
        ScalerMcuIICWrite(ADDR_LS_PS, 1, default_table[i].reg, 1, &(default_table[i].value));
        ScalerTimerDelayXms(5);
	}
    ScalerMcuIICWrite(ADDR_LS_PS, 1, LS_SUB_ADDR_ENABLE, 1, Data1);
    DebugMessageSystem("ScalerMcuLSPsInit------------------",1);
}

BYTE ScalerMcuGetPSData(void)//distance
{
    WORD PS_H = 0, PS_L= 0, PS_STATUS[1] = 0x00;
    WORD PS = 0;
    BYTE ret = 0;

    SET_SW_IIC_STATUS(_IIC_LS_PS);
    ScalerMcuIICRead(ADDR_LS_PS, 1, LS_SUB_ADDR_READY, 1, &PS_STATUS);
    ScalerTimerDelayXms(150);
    ScalerMcuIICRead(ADDR_LS_PS, 1, LS_SUB_ADDR_PS_H, 1, &PS_H);
    ScalerTimerDelayXms(150);
    ScalerMcuIICRead(ADDR_LS_PS, 1, LS_SUB_ADDR_PS_L, 1, &PS_L);
    PS = (PS_H << 8 | PS_L) / 100;
    DebugMessageSystem("PS------------------",PS);
    if(PS >= PS_MAX_VAL)
    {
       ret = PS_MAX_DIS;
    }
    else if(PS <= PS_MIN_VAL)
    {
        ret = PS_MIN_DIS;
    }
    else if((PS >= PS_CEN_VAL)&&(PS < PS_MAX_VAL))
    {
        ret = PS_CEN_DIS - (((PS - PS_CEN_VAL)/(PS_MAX_VAL-PS_CEN_VAL))*(PS_CEN_DIS-PS_MIN_DIS));
    }
    else if((PS < PS_CEN_VAL)&&(PS > PS_MIN_VAL))
    {
        ret = PS_MAX_DIS - (((PS - PS_MIN_VAL)/(PS_CEN_VAL-PS_MIN_VAL))*(PS_MAX_DIS-PS_CEN_DIS));
    }
    return ret;
}

BYTE ScalerMcuALSDataHanlder(void)//lum
{
    BYTE ALS_H[1] = 0x00, ALS_L[1] = 0x00;
    WORD ALS = 0x0000;
    BYTE ret = 0;

    SET_SW_IIC_STATUS(_IIC_LS_PS);
    ScalerMcuIICRead(ADDR_LS_PS, 1, LS_SUB_ADDR_ALS_H, 1, &ALS_H);
    DebugMessageSystem("ALS_H0------------------",ALS_H[0]);
    DebugMessageSystem("ALS_H1------------------",ALS_H[1]);
    ScalerTimerDelayXms(5);
    ScalerMcuIICRead(ADDR_LS_PS, 1, LS_SUB_ADDR_ALS_L, 1, &ALS_L);
    DebugMessageSystem("ALS_L0------------------",ALS_L[0]);
    DebugMessageSystem("ALS_L1------------------",ALS_L[1]);
    ALS = (ALS_H[0] << 8) | ALS_L[0];
    DebugMessageSystem("ALS------------------",ALS);
    if(ALS >= ALS_MAX_VAL)
    {
       ret = ALS_MAX_BRI;
    }
    else if(ALS <= ALS_MIN_VAL)
    {
        ret = ALS_MIN_BRI;
    }
    else if((ALS >= ALS_CEN_VAL)&&(ALS < ALS_MAX_VAL))
    {
        ret = ALS_CEN_BRI + (((ALS - ALS_CEN_VAL)/(ALS_MAX_VAL-ALS_CEN_VAL))*(ALS_MAX_BRI-ALS_CEN_BRI));
    }
    else if((ALS < ALS_CEN_VAL)&&(ALS > ALS_MIN_VAL))
    {
        ret = ALS_MIN_BRI + (((ALS - ALS_MIN_VAL)/(ALS_CEN_VAL-ALS_MIN_VAL))*(ALS_CEN_BRI-ALS_MIN_BRI));
    }
    DebugMessageSystem("ScalerMcuALSDataHanlder------------------",ret);
    return ret;
}
#endif

#if _EYE_VLI_SUPPORT
#define _SENSOR_CENTER_VAL          ALS_CEN_VAL
BYTE ScalerCalVLI_LightTimeDistance(void)
{
    BYTE Distance = 0;
    BYTE MntTime = g_ucTimerCount_EyeProtect/60;
    BYTE MntLum,CurLum = 0;
    BYTE StandDis = 0;
    BYTE StandLum = 0;
    BYTE StandTime = 0;

    StandDis = ((Distance - 5)*(Distance - 5));//距离归一化数值计算
    // 屏幕亮度归一化数值计算
    CurLum = GET_OSD_BACKLIGHT();
    #if _LS_PS_SUPPORT
    if(CurLum > MntLum)
    {
        // 当前亮度大于环境亮度时
        StandLum = (CurLum - ALS_CEN_BRI)/15;
    }
    else
    {
        // 当前亮度小于等于环境亮度时
        StandLum = (ALS_CEN_BRI - CurLum)/10;
    }
    #endif
    // 使用时间归一化数值计算
    if(MntTime >= 20)
    {
        // 使用时间大于等于20分钟时
        StandTime = (MntTime - 20)/10;
    }
    else
    {
        // 使用时间小于20分钟时
        StandTime = (20 - MntTime)/15;
    }
    return (StandDis + StandLum + StandTime);
}


#endif
