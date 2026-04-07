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
// ID Code      : RL6851_Series_SyncInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of DP FreeSync AMD SPD Info
//--------------------------------------------------
#if(_DP_FREESYNC_SUPPORT == _ON)
#define GET_DPRX0_AMD_SPD_INFO(x)                           (ScalerFreeSyncDpRx0GetAmdSpdInfo(x))
#define GET_DPRX1_AMD_SPD_INFO(x)                           (ScalerFreeSyncDpRx0GetAmdSpdInfo(x))

#define GET_DPRX0_H_PERIOD()                                (ScalerFreeSyncDpRx0GetHPeriod())
#define GET_DPRX1_H_PERIOD()                                (ScalerFreeSyncDpRx0GetHPeriod())

#define GET_DPRX0_HSW()                                     (ScalerFreeSyncDpRx0GetHSW())
#define GET_DPRX1_HSW()                                     (ScalerFreeSyncDpRx0GetHSW())

#define GET_DPRX0_V_FREQ()                                  (ScalerFreeSyncDpRx0GetVFreq())
#define GET_DPRX1_V_FREQ()                                  (ScalerFreeSyncDpRx0GetVFreq())

#define GET_DPRX0_V_PERIOD()                                (ScalerFreeSyncDpRx0GetVPeriod())
#define GET_DPRX1_V_PERIOD()                                (ScalerFreeSyncDpRx0GetVPeriod())
#endif

//--------------------------------------------------
// Definitions of HDMI FreeSync AMD SPD Info
//--------------------------------------------------
#if(_HDMI_FREESYNC_SUPPORT == _ON)
#define GET_HDMIRX0_AMD_SPD_INFO(x)                         (ScalerFreeSyncHDMIRx0GetAmdSpdInfo(x))
#define GET_HDMIRX1_AMD_SPD_INFO(x)                         (ScalerFreeSyncHDMIRx0GetAmdSpdInfo(x))
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

