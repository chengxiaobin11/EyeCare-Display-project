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
// ID Code      : ScalerCommonTMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_TMDS__

#include "ScalerCommonFunctionInclude.h"

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
#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_2_0_SUPPORT == _ON)
Struct5vPinDetect g_stTmdsMacRx5vPinDetect;
StructScdcInfoSet g_stTmdsMacRxScdcInfoSet;

#if(_HDMI_5V_DETECT_BY_USER == _ON)
StructTMDS5vStatusByUser g_stTmdsMacRx5vStatusByUser;
#endif
#endif
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent);
void ScalerTMDSSetPsWakeupHpdToggle(BYTE ucInputPort);

#if((_HDMI_2_0_SUPPORT == _ON) && (_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON))
void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable);
#endif


#if(_HDMI_MAC_PAGE2_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
void ScalerTMDSRx0GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
void ScalerTMDSRx0GetHDR10Data(BYTE *pucHDRData);
#endif

#endif

#if(_HDMI_MAC_PAGE71_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
void ScalerTMDSRx2GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
void ScalerTMDSRx2GetHDR10Data(BYTE *pucHDRData);
#endif

#endif

#if(_HDMI_MAC_PAGE72_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
void ScalerTMDSRx3GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
void ScalerTMDSRx3GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_MAC_PAGE73_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
void ScalerTMDSRx4GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
void ScalerTMDSRx4GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_MAC_PAGE74_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
void ScalerTMDSRx5GetFreeSyncIIData(BYTE *pucFreeSyncIIData);
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
void ScalerTMDSRx5GetHDR10Data(BYTE *pucHDRData);
#endif
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
bit ScalerTMDSRxGetCableStatus(BYTE ucInputPort);
void ScalerTMDSHdmiSetScdcInfo(BYTE ucInputPort);
void ScalerTMDSHdmiSetScdcInfoProc(BYTE ucInputPort);
void ScalerTMDSHdmiResetScdcInfo(BYTE ucInputPort);
void ScalerTMDSHdmiHpd5vPinCheckEvent(BYTE ucInputPort, bit bEnable);
void ScalerTMDSHdmiHpd5vPinCheckProc(BYTE ucInputPort);
void ScalerTMDSHdmiHpd5vPinCheck(BYTE ucInputPort);
EnumUserHdmi5vStatus ScalerTMDSHdmiHpd5vPinDetect(BYTE ucInputPort);
void ScalerTMDSHdmiSetHpd5vPinHighFlag(BYTE ucInputPort, bit bValue);
bit ScalerTMDSHdmiGetHpd5vPinHighFlag(BYTE ucInputPort);
BYTE ScalerTMDSHdmiGetHwVersion(void);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
EnumFreeSyncSupport ScalerTMDSHdmiGetFreeSyncSupport(BYTE ucInputPort);
void ScalerTMDSHdmiSetAmdAupiScdcInfo(BYTE ucInputPort, bit bEnable);
#endif
#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
void ScalerTMDSRxAllPortScdcEnableSetting(bit bEnable);
#endif
#endif
#endif // End of #if(_HDMI_SUPPORT == _ON)

#if(_DVI_SUPPORT == _ON)
void ScalerTMDSRxAcOnInitial(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent)
{
    ucInputPort = ucInputPort;

    switch(ucInputPort)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx1HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx2HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx3HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx4HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx5HdmiGetAVIInfo(enumContent);
#endif

#endif

        default:
            return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
void ScalerTMDSSetPsWakeupHpdToggle(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            SET_TMDS_RX0_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            SET_TMDS_RX1_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            SET_TMDS_RX2_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            SET_TMDS_RX3_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            SET_TMDS_RX4_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            SET_TMDS_RX5_PS_WAKEUP_HPD_TOGGLE();
            break;
#endif

        default:
            break;
    }
}

#if((_HDMI_2_0_SUPPORT == _ON) && (_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS HPD IRQ Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable)
{
    ucInputPort = ucInputPort;

    switch(ucInputPort)
    {
#if(_D0_HDMI_2_0_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx1HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx2HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx3HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx4HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx5HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

        default:
            break;
    }
}
#endif

#if(_HDMI_MAC_PAGE2_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS FreeSync II Data
// Input Value  : pucFreeSyncIIData --> FreeSync II data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx0GetFreeSyncIIData(BYTE *pucFreeSyncIIData)
{
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, _TMDS_INFO_RSV2_DB0, 11, &pucFreeSyncIIData[0], _AUTOINC);
}
#endif // End of #if(_HDMI_FREESYNC_II_SUPPORT == _ON)

#if(_HDMI_HDR10_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS HDR Data
// Input Value  : pucHDRData --> HDR data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx0GetHDR10Data(BYTE *pucHDRData)
{
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, _HDR10_INFO_HDMI_VERSION, 2, &pucHDRData[0], _AUTOINC);
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, _HDR10_INFO_HDMI_EOTF, 2, &pucHDRData[2], _AUTOINC);
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, _HDR10_INFO_HDMI_DISPLAY_PRIMARIES_X0_LSB, 24, &pucHDRData[4], _AUTOINC);
}
#endif // End of #if(_HDMI_HDR10_SUPPORT == _ON)

#endif

#if(_HDMI_MAC_PAGE71_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS FreeSync II Data
// Input Value  : pucFreeSyncIIData --> FreeSync II data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx2GetFreeSyncIIData(BYTE *pucFreeSyncIIData)
{
    ScalerGetDataPortByte(P71_CD_HDMI_PSAP, _TMDS_INFO_RSV2_DB0, 11, &pucFreeSyncIIData[0], _AUTOINC);
}
#endif // End of #if(_HDMI_FREESYNC_II_SUPPORT == _ON)

#if(_HDMI_HDR10_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS HDR Data
// Input Value  : pucHDRData --> HDR data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx2GetHDR10Data(BYTE *pucHDRData)
{
    ScalerGetDataPortByte(P71_CD_HDMI_PSAP, _HDR10_INFO_HDMI_VERSION, 2, &pucHDRData[0], _AUTOINC);
    ScalerGetDataPortByte(P71_CD_HDMI_PSAP, _HDR10_INFO_HDMI_EOTF, 2, &pucHDRData[2], _AUTOINC);
    ScalerGetDataPortByte(P71_CD_HDMI_PSAP, _HDR10_INFO_HDMI_DISPLAY_PRIMARIES_X0_LSB, 24, &pucHDRData[4], _AUTOINC);
}
#endif // End of #if(_HDMI_HDR10_SUPPORT == _ON)

#endif

#if(_HDMI_MAC_PAGE72_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS FreeSync II Data
// Input Value  : pucFreeSyncIIData --> FreeSync II data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3GetFreeSyncIIData(BYTE *pucFreeSyncIIData)
{
    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, _TMDS_INFO_RSV2_DB0, 11, &pucFreeSyncIIData[0], _AUTOINC);
}
#endif // End of #if(_HDMI_FREESYNC_II_SUPPORT == _ON)

#if(_HDMI_HDR10_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS HDR Data
// Input Value  : pucHDRData --> HDR data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3GetHDR10Data(BYTE *pucHDRData)
{
    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, _HDR10_INFO_HDMI_VERSION, 2, &pucHDRData[0], _AUTOINC);
    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, _HDR10_INFO_HDMI_EOTF, 2, &pucHDRData[2], _AUTOINC);
    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, _HDR10_INFO_HDMI_DISPLAY_PRIMARIES_X0_LSB, 24, &pucHDRData[4], _AUTOINC);
}
#endif // End of #if(_HDMI_HDR10_SUPPORT == _ON)

#endif

#if(_HDMI_MAC_PAGE73_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS FreeSync II Data
// Input Value  : pucFreeSyncIIData --> FreeSync II data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx4GetFreeSyncIIData(BYTE *pucFreeSyncIIData)
{
    ScalerGetDataPortByte(P73_CD_HDMI_PSAP, _TMDS_INFO_RSV2_DB0, 11, &pucFreeSyncIIData[0], _AUTOINC);
}
#endif // End of #if(_HDMI_FREESYNC_II_SUPPORT == _ON)

#if(_HDMI_HDR10_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS HDR Data
// Input Value  : pucHDRData --> HDR data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx4GetHDR10Data(BYTE *pucHDRData)
{
    ScalerGetDataPortByte(P73_CD_HDMI_PSAP, _HDR10_INFO_HDMI_VERSION, 2, &pucHDRData[0], _AUTOINC);
    ScalerGetDataPortByte(P73_CD_HDMI_PSAP, _HDR10_INFO_HDMI_EOTF, 2, &pucHDRData[2], _AUTOINC);
    ScalerGetDataPortByte(P73_CD_HDMI_PSAP, _HDR10_INFO_HDMI_DISPLAY_PRIMARIES_X0_LSB, 24, &pucHDRData[4], _AUTOINC);
}
#endif // End of #if(_HDMI_HDR10_SUPPORT == _ON)

#endif

#if(_HDMI_MAC_PAGE74_USE == _ON)

#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS FreeSync II Data
// Input Value  : pucFreeSyncIIData --> FreeSync II data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5GetFreeSyncIIData(BYTE *pucFreeSyncIIData)
{
    ScalerGetDataPortByte(P74_CD_HDMI_PSAP, _TMDS_INFO_RSV2_DB0, 11, &pucFreeSyncIIData[0], _AUTOINC);
}
#endif // End of #if(_HDMI_FREESYNC_II_SUPPORT == _ON)

#if(_HDMI_HDR10_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get TMDS HDR Data
// Input Value  : pucHDRData --> HDR data
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx5GetHDR10Data(BYTE *pucHDRData)
{
    ScalerGetDataPortByte(P74_CD_HDMI_PSAP, _HDR10_INFO_HDMI_VERSION, 2, &pucHDRData[0], _AUTOINC);
    ScalerGetDataPortByte(P74_CD_HDMI_PSAP, _HDR10_INFO_HDMI_EOTF, 2, &pucHDRData[2], _AUTOINC);
    ScalerGetDataPortByte(P74_CD_HDMI_PSAP, _HDR10_INFO_HDMI_DISPLAY_PRIMARIES_X0_LSB, 24, &pucHDRData[4], _AUTOINC);
}
#endif // End of #if(_HDMI_HDR10_SUPPORT == _ON)
#endif // End of #if(_HDMI_MAC_PAGE74_USE == _ON)

#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : SET RX port HPD
// Input Value  : RX Port
// Output Value : None
//--------------------------------------------------
bit ScalerTMDSRxGetCableStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_D0_CABLE_STATUS();
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_D1_CABLE_STATUS();
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_D2_CABLE_STATUS();
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            return GET_D3_CABLE_STATUS();
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            return GET_D4_CABLE_STATUS();
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            return GET_D5_CABLE_STATUS();
#endif
        default:
            return _FALSE;
    }
}

//--------------------------------------------------
// Description  : TMDS Set Scdc Info
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiSetScdcInfo(BYTE ucInputPort)
{
    ScalerTMDSHdmiSetScdcInfoProc(ucInputPort);
}

//--------------------------------------------------
// Description  : TMDS Set Scdc Info Proc
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiSetScdcInfoProc(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D0_PORT_PAGE02_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D1_PORT_PAGE02_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D2_PORT_PAGE02_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D3_PORT_PAGE02_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D4_PORT_PAGE02_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D5_PORT_PAGE02_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D6_PORT_PAGE02_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D7_PORT_PAGE02_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D8_PORT_PAGE02_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D9_PORT_PAGE02_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DA_PORT_PAGE02_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DB_PORT_PAGE02_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DC_PORT_PAGE02_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DD_PORT_PAGE02_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageScaler("RL6492 Set Rx0 SCDC Version Info", 0x00);
#else
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D0_PORT_PAGE71_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D1_PORT_PAGE71_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D2_PORT_PAGE71_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D3_PORT_PAGE71_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D4_PORT_PAGE71_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D5_PORT_PAGE71_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D6_PORT_PAGE71_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D7_PORT_PAGE71_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D8_PORT_PAGE71_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D9_PORT_PAGE71_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DA_PORT_PAGE71_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DB_PORT_PAGE71_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DC_PORT_PAGE71_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DD_PORT_PAGE71_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageRx1("Set Rx1 SCDC Version Info", 0x00);
#endif
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D0_PORT_PAGE02_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D1_PORT_PAGE02_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D2_PORT_PAGE02_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D3_PORT_PAGE02_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D4_PORT_PAGE02_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D5_PORT_PAGE02_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D6_PORT_PAGE02_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D7_PORT_PAGE02_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D8_PORT_PAGE02_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_D9_PORT_PAGE02_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DA_PORT_PAGE02_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DB_PORT_PAGE02_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DC_PORT_PAGE02_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_DD_PORT_PAGE02_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageScaler("RL6492 Set Rx SCDC Version Info", 0x00);
#else
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D0_PORT_PAGE71_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D1_PORT_PAGE71_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D2_PORT_PAGE71_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D3_PORT_PAGE71_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D4_PORT_PAGE71_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D5_PORT_PAGE71_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D6_PORT_PAGE71_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D7_PORT_PAGE71_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D8_PORT_PAGE71_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_D9_PORT_PAGE71_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DA_PORT_PAGE71_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DB_PORT_PAGE71_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DC_PORT_PAGE71_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_DD_PORT_PAGE71_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageRx2("Set Rx2 SCDC Version Info", 0x00);
#endif
            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:

            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D0_PORT_PAGE72_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D1_PORT_PAGE72_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D2_PORT_PAGE72_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D3_PORT_PAGE72_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D4_PORT_PAGE72_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D5_PORT_PAGE72_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D6_PORT_PAGE72_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D7_PORT_PAGE72_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D8_PORT_PAGE72_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_D9_PORT_PAGE72_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_DA_PORT_PAGE72_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_DB_PORT_PAGE72_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_DC_PORT_PAGE72_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_DD_PORT_PAGE72_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageRx3("Set Rx3 SCDC Version Info", 0x00);
            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:

            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D0_PORT_PAGE73_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D1_PORT_PAGE73_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D2_PORT_PAGE73_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D3_PORT_PAGE73_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D4_PORT_PAGE73_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D5_PORT_PAGE73_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D6_PORT_PAGE73_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D7_PORT_PAGE73_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D8_PORT_PAGE73_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_D9_PORT_PAGE73_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_DA_PORT_PAGE73_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_DB_PORT_PAGE73_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_DC_PORT_PAGE73_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_DD_PORT_PAGE73_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageRx4("Set Rx4 SCDC Version Info", 0x00);
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:

            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D0_PORT_PAGE74_HDMI_SCDC_D0, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D1_PORT_PAGE74_HDMI_SCDC_D1, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D2_PORT_PAGE74_HDMI_SCDC_D2, g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D3_PORT_PAGE74_HDMI_SCDC_D3, g_stTmdsMacRxScdcInfoSet.pucIdstring[0]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D4_PORT_PAGE74_HDMI_SCDC_D4, g_stTmdsMacRxScdcInfoSet.pucIdstring[1]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D5_PORT_PAGE74_HDMI_SCDC_D5, g_stTmdsMacRxScdcInfoSet.pucIdstring[2]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D6_PORT_PAGE74_HDMI_SCDC_D6, g_stTmdsMacRxScdcInfoSet.pucIdstring[3]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D7_PORT_PAGE74_HDMI_SCDC_D7, g_stTmdsMacRxScdcInfoSet.pucIdstring[4]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D8_PORT_PAGE74_HDMI_SCDC_D8, g_stTmdsMacRxScdcInfoSet.pucIdstring[5]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_D9_PORT_PAGE74_HDMI_SCDC_D9, g_stTmdsMacRxScdcInfoSet.pucIdstring[6]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_DA_PORT_PAGE74_HDMI_SCDC_DA, g_stTmdsMacRxScdcInfoSet.pucIdstring[7]);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_DB_PORT_PAGE74_HDMI_SCDC_DB, g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_DC_PORT_PAGE74_HDMI_SCDC_DC, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor);
            ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_DD_PORT_PAGE74_HDMI_SCDC_DD, g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor);

            DebugMessageRx5("Set Rx5 SCDC Version Info", 0x00);
            break;
#endif
        default:
            break;
    }
}
//--------------------------------------------------
// Description  : TMDS Reset Scdc Info
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiResetScdcInfo(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            // Disable CED Function
            ScalerSetBit(P2_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P2_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P2_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P2_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P2_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P2_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
#else
            // Disable CED Function
            ScalerSetBit(P71_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P71_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P71_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P71_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P71_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P71_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
#endif
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            // Disable CED Function
            ScalerSetBit(P2_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P2_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P2_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P2_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P2_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P2_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
#else
            // Disable CED Function
            ScalerSetBit(P71_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P71_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P71_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P71_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P71_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P71_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
#endif
            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            // Disable CED Function
            ScalerSetBit(P72_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P72_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P72_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P72_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P72_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P72_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            // Disable CED Function
            ScalerSetBit(P73_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P73_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P73_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P73_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P73_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P73_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            // Disable CED Function
            ScalerSetBit(P74_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            // Pop Up CED Error For Clear Error Counter
            ScalerSetBit(P74_0C_HDMI_CTRL_0C, ~_BIT7, _BIT7);

            // Disable CED Lock Transition IRQ & Flag
            ScalerSetBit(P74_17_HDMI_CTRL_17, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(P74_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            // Clear SCDC CED Counter
            ScalerSetBit(P74_28_HDMI_CTRL_28, ~(_BIT3 | _BIT1), _BIT1);

            // Reset SCDC
            ScalerSetBit(P74_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Check Hpd 5V Pin
// Input Value  : ucInputPort, enable/disable
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiHpd5vPinCheckEvent(BYTE ucInputPort, bit bEnable)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerTimerActiveTimerEvent(50, _SCALER_TIMER_EVENT_D1_TMDS_HDMI_HPD_5VPIN_CHECK);
            }
            else
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D1_TMDS_HDMI_HPD_5VPIN_CHECK);

                CLR_D1_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerTimerActiveTimerEvent(50, _SCALER_TIMER_EVENT_D2_TMDS_HDMI_HPD_5VPIN_CHECK);
            }
            else
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D2_TMDS_HDMI_HPD_5VPIN_CHECK);

                CLR_D2_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerTimerActiveTimerEvent(50, _SCALER_TIMER_EVENT_D3_TMDS_HDMI_HPD_5VPIN_CHECK);
            }
            else
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D3_TMDS_HDMI_HPD_5VPIN_CHECK);

#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
                if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)
                {
                    CLR_D3_HDMI_5V_PIN_HIGH();
                }
                else if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1)
                {
                    CLR_D12_HDMI_5V_PIN_HIGH();
                }
#else
                CLR_D3_HDMI_5V_PIN_HIGH();
#endif
            }
            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerTimerActiveTimerEvent(50, _SCALER_TIMER_EVENT_D4_TMDS_HDMI_HPD_5VPIN_CHECK);
            }
            else
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D4_TMDS_HDMI_HPD_5VPIN_CHECK);

                CLR_D4_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                ScalerTimerActiveTimerEvent(50, _SCALER_TIMER_EVENT_D5_TMDS_HDMI_HPD_5VPIN_CHECK);
            }
            else
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_D5_TMDS_HDMI_HPD_5VPIN_CHECK);

                CLR_D5_HDMI_5V_PIN_HIGH();
            }
            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Check Hpd 5V Pin Check Proc
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiHpd5vPinCheckProc(BYTE ucInputPort)
{
#if(_HDMI_5V_DETECT_BY_USER == _OFF)
    ScalerPinshareRxHpdPullDownSet(ucInputPort, _ENABLE);
#endif

    ScalerTMDSHdmiHpd5vPinCheck(ucInputPort);

#if(_HDMI_5V_DETECT_BY_USER == _OFF)
    ScalerPinshareRxHpdPullDownSet(ucInputPort, _DISABLE);
#endif
}

//--------------------------------------------------
// Description  : TMDS Check Hpd 5V Pin Check
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiHpd5vPinCheck(BYTE ucInputPort)
{
    DELAY_XUS(500);

    if((ScalerTMDSHdmiHpd5vPinDetect(ucInputPort) == _HDMI_5V_STATUS_HIGH) && (ScalerTMDSHdmiGetHpd5vPinHighFlag(ucInputPort) == _FALSE))
    {
        if(ScalerTMDSRxGetCableStatus(ucInputPort) == _TRUE)
        {
            ScalerTMDSHdmiSetScdcInfo(ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(ScalerTMDSHdmiGetFreeSyncSupport(ucInputPort) == _FREESYNC_SUPPORT_ON)
            {
                ScalerTMDSHdmiSetAmdAupiScdcInfo(ucInputPort, _ENABLE);
            }
            else
            {
                ScalerTMDSHdmiSetAmdAupiScdcInfo(ucInputPort, _DISABLE);
            }
#endif
        }

        ScalerTMDSHdmiSetHpd5vPinHighFlag(ucInputPort, _ON);
    }
    else if((ScalerTMDSHdmiHpd5vPinDetect(ucInputPort) == _HDMI_5V_STATUS_LOW) && (ScalerTMDSHdmiGetHpd5vPinHighFlag(ucInputPort) == _TRUE))
    {
        ScalerTMDSHdmiResetScdcInfo(ucInputPort);

        // 5V Low then Reset Scramble Status
        ScalerTMDSHdmiScrambleStatusReset(ucInputPort);

        ScalerTMDSHdmiSetScdcInfo(ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
        if(ScalerTMDSHdmiGetFreeSyncSupport(ucInputPort) == _FREESYNC_SUPPORT_ON)
        {
            ScalerTMDSHdmiSetAmdAupiScdcInfo(ucInputPort, _ENABLE);
        }
        else
        {
            ScalerTMDSHdmiSetAmdAupiScdcInfo(ucInputPort, _DISABLE);
        }
#endif

        ScalerTMDSHdmiSetHpd5vPinHighFlag(ucInputPort, _OFF);
    }

    ScalerTMDSHdmiHpd5vPinCheckEvent(ucInputPort, _ENABLE);
}

//--------------------------------------------------
// Description  : TMDS Detect HPD 5V Pin
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
EnumUserHdmi5vStatus ScalerTMDSHdmiHpd5vPinDetect(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:
#if(_HDMI_5V_DETECT_BY_USER == _ON)
            return g_stTmdsMacRx5vStatusByUser.b1D15vStatusByUser;
#else
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            // Check Hot Plug 5V
            if(ScalerGetBit(P2_23_HDMI_CTRL_23, _BIT0) == _BIT0)
#else
            if(ScalerGetBit(P71_23_HDMI_CTRL_23, _BIT0) == _BIT0)
#endif
            {
                return _HDMI_5V_STATUS_HIGH;
            }
            else
            {
                return _HDMI_5V_STATUS_LOW;
            }
#endif
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:
#if(_HDMI_5V_DETECT_BY_USER == _ON)
            return g_stTmdsMacRx5vStatusByUser.b1D25vStatusByUser;
#else
#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            // Check Hot Plug 5V
            if(ScalerGetBit(P2_23_HDMI_CTRL_23, _BIT0) == _BIT0)
#else
            if(ScalerGetBit(P71_23_HDMI_CTRL_23, _BIT0) == _BIT0)
#endif
            {
                return _HDMI_5V_STATUS_HIGH;
            }
            else
            {
                return _HDMI_5V_STATUS_LOW;
            }
#endif
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:
#if(_HDMI_5V_DETECT_BY_USER == _ON)
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
            if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)
            {
                return g_stTmdsMacRx5vStatusByUser.b1D35vStatusByUser;
            }
            else if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1)
            {
                return g_stTmdsMacRx5vStatusByUser.b1D125vStatusByUser;
            }
#else
            return g_stTmdsMacRx5vStatusByUser.b1D35vStatusByUser;
#endif
#else
            // Check Hot Plug 5V
            if(ScalerGetBit(P72_23_HDMI_CTRL_23, _BIT0) == _BIT0)
            {
                return _HDMI_5V_STATUS_HIGH;
            }
            else
            {
                return _HDMI_5V_STATUS_LOW;
            }
#endif
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:
#if(_HDMI_5V_DETECT_BY_USER == _ON)
            return g_stTmdsMacRx5vStatusByUser.b1D45vStatusByUser;
#else
            // Check Hot Plug 5V
            if(ScalerGetBit(P73_23_HDMI_CTRL_23, _BIT0) == _BIT0)
            {
                return _HDMI_5V_STATUS_HIGH;
            }
            else
            {
                return _HDMI_5V_STATUS_LOW;
            }
#endif
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:
#if(_HDMI_5V_DETECT_BY_USER == _ON)
            return g_stTmdsMacRx5vStatusByUser.b1D55vStatusByUser;
#else
            // Check Hot Plug 5V
            if(ScalerGetBit(P74_23_HDMI_CTRL_23, _BIT0) == _BIT0)
            {
                return _HDMI_5V_STATUS_HIGH;
            }
            else
            {
                return _HDMI_5V_STATUS_LOW;
            }
#endif
#endif
        default:
            return _HDMI_5V_STATUS_LOW;
    }
}

//--------------------------------------------------
// Description  : SET RX HPD 5V Pin Flag
// Input Value  : ucInputPort/_ON,_OFF
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiSetHpd5vPinHighFlag(BYTE ucInputPort, bit bValue)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bValue == _ON)
            {
                SET_D1_HDMI_5V_PIN_HIGH();
            }
            else
            {
                CLR_D1_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bValue == _ON)
            {
                SET_D2_HDMI_5V_PIN_HIGH();
            }
            else
            {
                CLR_D2_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            if(bValue == _ON)
            {
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
                if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)
                {
                    SET_D3_HDMI_5V_PIN_HIGH();
                }
                else if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1)
                {
                    SET_D12_HDMI_5V_PIN_HIGH();
                }
#else
                SET_D3_HDMI_5V_PIN_HIGH();
#endif
            }
            else
            {
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
                if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)
                {
                    CLR_D3_HDMI_5V_PIN_HIGH();
                }
                else if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1)
                {
                    CLR_D12_HDMI_5V_PIN_HIGH();
                }
#else
                CLR_D3_HDMI_5V_PIN_HIGH();
#endif
            }
            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            if(bValue == _ON)
            {
                SET_D4_HDMI_5V_PIN_HIGH();
            }
            else
            {
                CLR_D4_HDMI_5V_PIN_HIGH();
            }
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            if(bValue == _ON)
            {
                SET_D5_HDMI_5V_PIN_HIGH();
            }
            else
            {
                CLR_D5_HDMI_5V_PIN_HIGH();
            }
            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : GET RX HPD 5V Pin Flag
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
bit ScalerTMDSHdmiGetHpd5vPinHighFlag(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_D1_HDMI_5V_PIN_HIGH();
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_D2_HDMI_5V_PIN_HIGH();
            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
            if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3)
            {
                return GET_D3_HDMI_5V_PIN_HIGH();
            }
            else if(PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1)
            {
                return GET_D12_HDMI_5V_PIN_HIGH();
            }
#else
            return GET_D3_HDMI_5V_PIN_HIGH();
#endif
            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            return GET_D4_HDMI_5V_PIN_HIGH();
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            return GET_D5_HDMI_5V_PIN_HIGH();
            break;
#endif
        default:
            break;
    }
    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Version Scdc Info Hw Version
// Input Value  : None
// Output Value : HW Version
//--------------------------------------------------
BYTE ScalerTMDSHdmiGetHwVersion(void)
{
    BYTE ucHwVersionMajor = 0x00;
    BYTE ucHwVersionMinor = 0x00;
    BYTE ucHwVersion = 0x00;

    if(_HW_HDMI_2_0_SUPPORT_PORT != _HDMI_2_0_NONE)
    {
        ucHwVersionMajor = 0x01;
    }
    else
    {
        ucHwVersionMajor = 0x00;
    }

    ucHwVersion = (((ucHwVersionMajor & 0x0F) << 4) | (ucHwVersionMinor & 0x0F));

    return ucHwVersion;
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI FreeSync Support
// Input Value  : ucInputPort
// Output Value : _FREESYNC_SUPPORT_ON/ _FREESYNC_SUPPORT_OFF
//--------------------------------------------------
EnumFreeSyncSupport ScalerTMDSHdmiGetFreeSyncSupport(BYTE ucInputPort)
{
    EnumFreeSyncSupport enumFreeSyncSupport = _FREESYNC_SUPPORT_OFF;

    switch(ucInputPort)
    {
        case _D1_INPUT_PORT:
            enumFreeSyncSupport = GET_TMDS_RX1_FREESYNC_SUPPORT();
            break;

        case _D2_INPUT_PORT:
            enumFreeSyncSupport = GET_TMDS_RX2_FREESYNC_SUPPORT();
            break;

        case _D3_INPUT_PORT:
            enumFreeSyncSupport = GET_TMDS_RX3_FREESYNC_SUPPORT();
            break;

        case _D4_INPUT_PORT:
            enumFreeSyncSupport = GET_TMDS_RX4_FREESYNC_SUPPORT();
            break;

        case _D5_INPUT_PORT:
            enumFreeSyncSupport = GET_TMDS_RX5_FREESYNC_SUPPORT();
            break;

        default:
            break;
    }

    return enumFreeSyncSupport;
}

//--------------------------------------------------
// Description  : TMDS Set Amd Aupi Scdc Info
// Input Value  : enumInputPort
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiSetAmdAupiScdcInfo(BYTE ucInputPort, bit bEnable)
{
    bEnable = bEnable;

    if(GET_FREESYNC_HDMI_AUPI_INFO() != _TRUE)
    {
        return;
    }

    if(bEnable == _ENABLE)
    {
        switch(ucInputPort)
        {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
            case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E0_PORT_PAGE02_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E1_PORT_PAGE02_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E2_PORT_PAGE02_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E3_PORT_PAGE02_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E4_PORT_PAGE02_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E5_PORT_PAGE02_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E6_PORT_PAGE02_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E7_PORT_PAGE02_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx0 AMD AUPI SCDC Info", 0x00);
#else
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx1 AMD AUPI SCDC Info", 0x00);
#endif
                break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
            case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E0_PORT_PAGE02_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E1_PORT_PAGE02_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E2_PORT_PAGE02_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E3_PORT_PAGE02_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E4_PORT_PAGE02_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E5_PORT_PAGE02_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E6_PORT_PAGE02_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E7_PORT_PAGE02_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx0 AMD AUPI SCDC Info", 0x00);
#else
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx2 AMD AUPI SCDC Info", 0x00);
#endif
                break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
            case _D3_INPUT_PORT:
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E0_PORT_PAGE72_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E1_PORT_PAGE72_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E2_PORT_PAGE72_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E3_PORT_PAGE72_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E4_PORT_PAGE72_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E5_PORT_PAGE72_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E6_PORT_PAGE72_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E7_PORT_PAGE72_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx3 AMD AUPI SCDC Info", 0x00);
                break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
            case _D4_INPUT_PORT:
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E0_PORT_PAGE73_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E1_PORT_PAGE73_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E2_PORT_PAGE73_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E3_PORT_PAGE73_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E4_PORT_PAGE73_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E5_PORT_PAGE73_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E6_PORT_PAGE73_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E7_PORT_PAGE73_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx4 AMD AUPI SCDC Info", 0x00);
                break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
            case _D5_INPUT_PORT:
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E0_PORT_PAGE74_HDMI_SCDC_E0, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdL);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E1_PORT_PAGE74_HDMI_SCDC_E1, g_stDrrHdmiAmdAupiInfo.ucPanelManufactureIdM);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E2_PORT_PAGE74_HDMI_SCDC_E2, g_stDrrHdmiAmdAupiInfo.ucPanelIdL);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E3_PORT_PAGE74_HDMI_SCDC_E3, g_stDrrHdmiAmdAupiInfo.ucPanelIdM);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E4_PORT_PAGE74_HDMI_SCDC_E4, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumL);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E5_PORT_PAGE74_HDMI_SCDC_E5, g_stDrrHdmiAmdAupiInfo.ucFwCheckSumM);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E6_PORT_PAGE74_HDMI_SCDC_E6, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdL);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E7_PORT_PAGE74_HDMI_SCDC_E7, g_stDrrHdmiAmdAupiInfo.ucScalerDeviceIdM);

                DebugMessageScaler("Set Rx5 AMD AUPI SCDC Info", 0x00);
                break;
#endif
            default:
                break;
        }
    }
    else
    {
        switch(ucInputPort)
        {
#if(_D1_HDMI_2_0_SUPPORT == _ON)
            case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E0_PORT_PAGE02_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E1_PORT_PAGE02_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E2_PORT_PAGE02_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E3_PORT_PAGE02_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E4_PORT_PAGE02_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E5_PORT_PAGE02_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E6_PORT_PAGE02_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E7_PORT_PAGE02_HDMI_SCDC_E7, 0x00);
#else
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7, 0x00);
#endif
                break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
            case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E0_PORT_PAGE02_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E1_PORT_PAGE02_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E2_PORT_PAGE02_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E3_PORT_PAGE02_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E4_PORT_PAGE02_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E5_PORT_PAGE02_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E6_PORT_PAGE02_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P2_39_HDMI_CTRL_39, _P2_3A_PT_E7_PORT_PAGE02_HDMI_SCDC_E7, 0x00);
#else
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E0_PORT_PAGE71_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E1_PORT_PAGE71_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E2_PORT_PAGE71_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E3_PORT_PAGE71_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E4_PORT_PAGE71_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E5_PORT_PAGE71_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E6_PORT_PAGE71_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P71_39_HDMI_CTRL_39, _P71_3A_PT_E7_PORT_PAGE71_HDMI_SCDC_E7, 0x00);
#endif
                break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
            case _D3_INPUT_PORT:
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E0_PORT_PAGE72_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E1_PORT_PAGE72_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E2_PORT_PAGE72_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E3_PORT_PAGE72_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E4_PORT_PAGE72_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E5_PORT_PAGE72_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E6_PORT_PAGE72_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P72_39_HDMI_CTRL_39, _P72_3A_PT_E7_PORT_PAGE72_HDMI_SCDC_E7, 0x00);
                break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
            case _D4_INPUT_PORT:
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E0_PORT_PAGE73_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E1_PORT_PAGE73_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E2_PORT_PAGE73_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E3_PORT_PAGE73_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E4_PORT_PAGE73_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E5_PORT_PAGE73_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E6_PORT_PAGE73_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P73_39_HDMI_CTRL_39, _P73_3A_PT_E7_PORT_PAGE73_HDMI_SCDC_E7, 0x00);
                break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
            case _D5_INPUT_PORT:
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E0_PORT_PAGE74_HDMI_SCDC_E0, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E1_PORT_PAGE74_HDMI_SCDC_E1, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E2_PORT_PAGE74_HDMI_SCDC_E2, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E3_PORT_PAGE74_HDMI_SCDC_E3, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E4_PORT_PAGE74_HDMI_SCDC_E4, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E5_PORT_PAGE74_HDMI_SCDC_E5, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E6_PORT_PAGE74_HDMI_SCDC_E6, 0x00);
                ScalerSetDataPortByte(P74_39_HDMI_CTRL_39, _P74_3A_PT_E7_PORT_PAGE74_HDMI_SCDC_E7, 0x00);
                break;
#endif
            default:
                break;
        }
    }
}
#endif

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Mac Scdc Enable Setting
// Input Value  : _ENABLE/_DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRxAllPortScdcEnableSetting(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable HDMI 2.0 SCDC Function
#if(_D0_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#else
        ScalerSetBit(P71_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#else
        ScalerSetBit(P71_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P72_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P73_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P74_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
#endif
    }
    else
    {
        // Disable HDMI 2.0 SCDC Function
#if(_D0_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#else
        ScalerSetBit(P71_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
        ScalerSetBit(P2_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#else
        ScalerSetBit(P71_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P72_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P73_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        ScalerSetBit(P74_19_HDMI_CTRL_19, ~_BIT7, 0x00);
#endif
    }
}
#endif
#endif // End of #if(_HDMI_2_0_SUPPORT == _ON)
#endif // End of #if(_HDMI_SUPPORT == _ON)

#if(_DVI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Mac AC On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRxAcOnInitial(void)
{
    // On Measure Initial to prevent stable flag need twice the time
#if(_D0_TMDS_SUPPORT == _ON)
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX0_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif

#if(_D1_TMDS_SUPPORT == _ON)
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);
#else
    ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);
#endif

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX1_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif

#if(_D2_TMDS_SUPPORT == _ON)
#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);
#else
    ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);
#endif

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX2_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif

#if(_D3_TMDS_SUPPORT == _ON)
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX3_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif

#if(_D4_TMDS_SUPPORT == _ON)
    ScalerSetBit(P73_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX4_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif

#if(_D5_TMDS_SUPPORT == _ON)
    ScalerSetBit(P74_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT2), _BIT7);

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
    SET_TMDS_RX5_AC_ON_HPD_TOGGLE_EVENT();
#endif
#endif
}
#endif
