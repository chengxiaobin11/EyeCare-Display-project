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
// ID Code      : RL6432_Series_SyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of DP Mac Info
//--------------------------------------------------
#if(_D0_DP_EXIST == _ON)
#define GET_DPRX0_BS_TO_HS_DELAY(x)                         (ScalerDpRx0GetBStoHSDelay(x))
#endif

#if(_D1_DP_EXIST == _ON)
#define GET_DPRX1_BS_TO_HS_DELAY(x)                         (ScalerDpRx1GetBStoHSDelay(x))
#endif

//--------------------------------------------------
// Definitions of DP FreeSync AMD SPD Info
//--------------------------------------------------
#if(_DP_FREESYNC_SUPPORT == _ON)
#define GET_DPRX0_AMD_SPD_INFO(x)                           (ScalerFreeSyncDpRx0GetAmdSpdInfo(x))
#define GET_DPRX1_AMD_SPD_INFO(x)                           (ScalerFreeSyncDpRx1GetAmdSpdInfo(x))

#define GET_DPRX0_H_PERIOD()                                (ScalerFreeSyncDpRx0GetHPeriod())
#define GET_DPRX1_H_PERIOD()                                (ScalerFreeSyncDpRx1GetHPeriod())

#define GET_DPRX0_HSW()                                     (ScalerFreeSyncDpRx0GetHSW())
#define GET_DPRX1_HSW()                                     (ScalerFreeSyncDpRx1GetHSW())

#define GET_DPRX0_V_FREQ()                                  (ScalerFreeSyncDpRx0GetVFreq())
#define GET_DPRX1_V_FREQ()                                  (ScalerFreeSyncDpRx1GetVFreq())

#define GET_DPRX0_V_PERIOD()                                (ScalerFreeSyncDpRx0GetVPeriod())
#define GET_DPRX1_V_PERIOD()                                (ScalerFreeSyncDpRx1GetVPeriod())
#endif

//--------------------------------------------------
// Definitions of HDMI FreeSync AMD SPD Info
//--------------------------------------------------
#if(_HDMI_FREESYNC_SUPPORT == _ON)
#define GET_HDMIRX1_AMD_SPD_INFO(x)                         (ScalerFreeSyncHDMIRx2GetAmdSpdInfo((x), (_ON)))
#define GET_HDMIRX2_AMD_SPD_INFO(x)                         (ScalerFreeSyncHDMIRx2GetAmdSpdInfo((x), (_OFF)))
#define GET_HDMIRX3_AMD_SPD_INFO(x)                         (ScalerFreeSyncHDMIRx3GetAmdSpdInfo(x))
#endif

//--------------------------------------------------
// Definitions of Get HDR10 Data
//--------------------------------------------------
#if(_HDMI_HDR10_SUPPORT == _ON)
#define GET_TMDSRX1_HDR10_DATA(x)                           (ScalerTMDSRx2GetHDR10Data(x))
#define GET_TMDSRX2_HDR10_DATA(x)                           (ScalerTMDSRx2GetHDR10Data(x))
#define GET_TMDSRX3_HDR10_DATA(x)                           (ScalerTMDSRx3GetHDR10Data(x))
#endif

//--------------------------------------------------
// Definitions of Get FreeSyncII Data
//--------------------------------------------------
#if(_HDMI_FREESYNC_II_SUPPORT == _ON)
#define GET_TMDSRX1_FREESYNCII_DATA(x)                      (ScalerTMDSRx2GetFreeSyncIIData(x))
#define GET_TMDSRX2_FREESYNCII_DATA(x)                      (ScalerTMDSRx2GetFreeSyncIIData(x))
#define GET_TMDSRX3_FREESYNCII_DATA(x)                      (ScalerTMDSRx3GetFreeSyncIIData(x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_DIGITAL_PORT_SUPPORT == _ON)
extern BYTE idata g_pucHdcpBksvBackup[5];
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern WORD ScalerSyncGetInputPixelClk(void);

#if(_FREESYNC_SUPPORT == _ON)
extern void ScalerSyncFREESYNCTestPinEnable(void);
#endif

