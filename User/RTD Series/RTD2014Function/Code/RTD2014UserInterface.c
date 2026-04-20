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
// ID Code      : RTD2014UserInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_INTERFACE__

#include "UserCommonInclude.h"
#include "RTD2014UserHDMIEdid.h"
#include "RTD2014UserDPEdid.h"

#if(_AI_LIGHT_ADAPTIVATION == _ON)
#include "ScalerCommonMcuInclude.h"
#define PS_TIMER_THRE                           360//no user timeout threshold(20s)
#define ALS_VAL_THRE                            5
#endif

#if _EYE_VLI_SUPPORT
WORD g_ucTimerCount_EyeProtect = 0;
#endif
#if(_AI_LOW_POWER == _ON)
WORD g_ucTimer_Distance = 0;
BYTE bAI_LowPower_Status = 0;
#endif

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _USER_SHOW_LOGO_STEP                    18 // frames

#define _EDID_VENDOR_SPEC_0                     160
#define _EDID_CHKSUM                            255

#if(_MPRT_SUPPORT == _ON)
WORD g_MPRTValue;
#endif
bit g_bflagSecondON = _FALSE;
extern void OsdFunDpVersion(void);

//-------------------------------------------------------
//  Definitions of RCP Key Codes
//-------------------------------------------------------
#define _MHL_RCP_VOLUME_UP                      0x41
#define _MHL_RCP_VOLUME_DOWN                    0x42
#define _MHL_RCP_MUTE                           0x43
#define _MHL_RCP_MUTE_FUNCTION                  0x65
#define _MHL_RCP_RESTORE_VOLUME_FUNCTION        0x66

#if(_DRR_SUPPORT == _ON)
#define _USER_DRR_CLK_MARGIN                    (1)
#define _USER_DRR_HTOTAL_MARGIN                 (2)

#if(_DP_FREESYNC_SUPPORT == _ON)
#define GET_DP_FREESYNC_IHWIDTH(x)              (tDrrFreeSyncDpTimingInfo[(x)].usIHwidth)
#define GET_DP_FREESYNC_IVHEIGHT(x)             (tDrrFreeSyncDpTimingInfo[(x)].usIVheight)
#define GET_DP_FREESYNC_IHTOTAL(x)              (tDrrFreeSyncDpTimingInfo[(x)].usIHtotal)
#define GET_DP_FREESYNC_ICLK(x)                 (tDrrFreeSyncDpTimingInfo[(x)].usPixelClk)
#define GET_DP_FREESYNC_IVFREQ(x)               (tDrrFreeSyncDpTimingInfo[(x)].usIVfreq)
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
#define GET_HDMI_FREESYNC_IHWIDTH(x)            (tDrrFreeSyncHdmiTimingInfo[(x)].usIHwidth)
#define GET_HDMI_FREESYNC_IVHEIGHT(x)           (tDrrFreeSyncHdmiTimingInfo[(x)].usIVheight)
#define GET_HDMI_FREESYNC_IHTOTAL(x)            (tDrrFreeSyncHdmiTimingInfo[(x)].usIHtotal)
#define GET_HDMI_FREESYNC_ICLK(x)               (tDrrFreeSyncHdmiTimingInfo[(x)].usPixelClk)
#define GET_HDMI_FREESYNC_IVFREQ(x)             (tDrrFreeSyncHdmiTimingInfo[(x)].usIVfreq)
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
#define GET_HDMI_VRR_IHWIDTH(x)                 (tDrrVrrHdmiTimingInfo[(x)].usIHwidth)
#define GET_HDMI_VRR_IVHEIGHT(x)                (tDrrVrrHdmiTimingInfo[(x)].usIVheight)
#define GET_HDMI_VRR_IHTOTAL(x)                 (tDrrVrrHdmiTimingInfo[(x)].usIHtotal)
#define GET_HDMI_VRR_ICLK(x)                    (tDrrVrrHdmiTimingInfo[(x)].usPixelClk)
#define GET_HDMI_VRR_IVFREQ(x)                  (tDrrVrrHdmiTimingInfo[(x)].usIVfreq)
#endif
#endif
extern bit ddcci_reset;

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)
void IndicatoLlghtFlickerEvent(void);
#endif

#if(_OVERSCAN_SUPPORT == _ON)
bit g_bOverScanFlag = _FALSE;
#endif

extern BYTE g_usPowerOffCount;

extern BYTE  Input_New_State;
extern BYTE  Input_Old_State;

extern BYTE Language_District_flang;  //2025.02.07
#if _EYE_VLI_SUPPORT
extern WORD g_ucTimerCount_EyeProtect;
void ScalerEyeProtectEventProc(void);
#endif
#if(_OD_SUPPORT == _ON)
extern void UserAdjustOverDrive(void);
#endif
extern bit SysJudgeStateChangeEvent(EnumModeStatus enumModeState);
extern void OsdDisplayCombineKeyFunction(bit bKeyMode, BYTE ucValue);

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_DP_FREESYNC_SUPPORT == _ON)
StructDrrFreeSyncTimingInfo code tDrrFreeSyncDpTimingInfo[] =
{
    // Hwidth, Vheight, Htotal, Pixel clk (0.1M), Vfreq (0.1Hz)
    {1920, 1080, 2200, 1485, 600},
    {2560, 1440, 2720, 2415, 600},

    // Established Timing Info
    {720,  400,  888,  283,  702},//720 x 400 at 70Hz - IBM VGA
    {720,  400,  907,  355,  882},//720 x 400 at 88Hz - IBM XGA2
    {640,  480,  800,  251,  600},//640 x 480 at 60Hz - IBM VGA
    {640,  480,  864,  302,  667},//640 x 480 at 67Hz - Mac II
    {640,  480,  832,  315,  728},//640 x 480 at 72Hz - VESA
    {640,  480,  840,  315,  750},//640 x 480 at 75Hz - VESA
    {800,  600,  1024, 360,  562},//800 x 600 at 56Hz - VESA
    {800,  600,  1056, 400,  603},//800 x 600 at 60Hz - VESA
    {800,  600,  1040, 500,  722},//800 x 600 at 72Hz - VESA
    {800,  600,  1056, 495,  750},//800 x 600 at 75Hz - VESA
    {832,  624,  1152, 572,  745},//832 x 624 at 75Hz - Mac II
    {1024, 768,  1264, 898,  870},//1024 x 768 at 43Hz - IBM 8514a
    {1024, 768,  1344, 650,  600},//1024 x 768 at 60Hz - VESA
    {1024, 768,  1328, 750,  700},//1024 x 768 at 70Hz - VESA
    {1024, 768,  1312, 787,  750},//1024 x 768 at 75Hz - VESA
    {1280, 1024, 1688, 1350, 750},//1280 x 1024 at 75Hz - VESA
    {1152, 870,  1456, 1000, 750},//1152 x 870 at 75Hz - Mac II
};
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
StructDrrFreeSyncTimingInfo code tDrrFreeSyncHdmiTimingInfo[] =
{
    // Hwidth, Vheight, Htotal, Pixel clk (0.1M), Vfreq (0.1Hz)
    {1920, 1080, 2200, 1485, 600},
    {2560, 1440, 2720, 2415, 600},

    // Established Timing Info
    {720,  400,  888,  283,  702},// 720 x 400 at 70Hz - IBM VGA
    {720,  400,  907,  355,  882},// 720 x 400 at 88Hz - IBM XGA2
    {640,  480,  800,  251,  600},// 640 x 480 at 60Hz - IBM VGA
    {640,  480,  864,  302,  667},// 640 x 480 at 67Hz - Mac II
    {640,  480,  832,  315,  728},// 640 x 480 at 72Hz - VESA
    {640,  480,  840,  315,  750},// 640 x 480 at 75Hz - VESA
    {800,  600,  1024, 360,  562},// 800 x 600 at 56Hz - VESA
    {800,  600,  1056, 400,  603},// 800 x 600 at 60Hz - VESA
    {800,  600,  1040, 500,  722},// 800 x 600 at 72Hz - VESA
    {800,  600,  1056, 495,  750},// 800 x 600 at 75Hz - VESA
    {832,  624,  1152, 572,  745},// 832 x 624 at 75Hz - Mac II
    {1024, 768,  1264, 898,  870},// 1024 x 768 at 43Hz - IBM 8514a
    {1024, 768,  1344, 650,  600},// 1024 x 768 at 60Hz - VESA
    {1024, 768,  1328, 750,  700},// 1024 x 768 at 70Hz - VESA
    {1024, 768,  1312, 787,  750},// 1024 x 768 at 75Hz - VESA
    {1280, 1024, 1688, 1350, 750},// 1280 x 1024 at 75Hz - VESA
    {1152, 870,  1456, 1000, 750},// 1152 x 870 at 75Hz - Mac II
};
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
StructDrrFreeSyncTimingInfo code tDrrVrrHdmiTimingInfo[] =
{
    // Hwidth, Vheight, Htotal, Pixel clk (0.1M), Vfreq (0.1Hz)
    {1920, 1080, 2200, 1485, 600},
    {2560, 1440, 2720, 2415, 600},
};
#endif

//----------------------------------------------------------------------------------------------------
// Filter Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
#if(_SHARPNESS_SUPPORT == _ON)
#if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_128_TAPS_0[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable0.h"
};

BYTE code tSU_COEF_128_TAPS_1[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable1.h"
};

BYTE code tSU_COEF_128_TAPS_2[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable2.h"
};

BYTE code tSU_COEF_128_TAPS_3[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable2.h"
};

BYTE code tSU_COEF_128_TAPS_4[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable4.h"
};

BYTE code tSU_COEF_128_TAPS_6[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable6.h"
};

BYTE code tSU_COEF_128_TAPS_8[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable8.h"
};

BYTE code tSU_COEF_128_TAPS_10[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable10.h"
};

code BYTE *tSCALE_128TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_128_TAPS_0,        tSU_COEF_128_TAPS_2,        tSU_COEF_128_TAPS_4,        tSU_COEF_128_TAPS_6,        tSU_COEF_128_TAPS_8,
};
#endif // End of #if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))

#if(_HSU_128TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_128_TAPS_0[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_1[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table1.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_2[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_3[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table3.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_4[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_6[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_8[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table8.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_10[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table10.h"
};

code BYTE *tSCALE_128TAPS_1to1_COEF_TABLE[] =
{
    tSU_1to1_COEF_128_TAPS_0,        tSU_1to1_COEF_128_TAPS_2,        tSU_1to1_COEF_128_TAPS_4,        tSU_1to1_COEF_128_TAPS_6,        tSU_1to1_COEF_128_TAPS_8,
};
#endif // End of #if(_HSU_128TAPS_SUPPORT == _ON)

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_96_TAPS_0[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable0.h"
};

BYTE code tSU_COEF_96_TAPS_2[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable2.h"
};

BYTE code tSU_COEF_96_TAPS_4[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable4.h"
};

BYTE code tSU_COEF_96_TAPS_6[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable6.h"
};

BYTE code tSU_COEF_96_TAPS_8[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable8.h"
};

code BYTE *tSCALE_96TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_96_TAPS_0,        tSU_COEF_96_TAPS_2,        tSU_COEF_96_TAPS_4,        tSU_COEF_96_TAPS_6,        tSU_COEF_96_TAPS_8,
};
#endif // End of #if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))

#if(_HSU_96TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_96_TAPS_0[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_2[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_4[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_6[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_8[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table8.h"
};

code BYTE *tSCALE_96TAPS_1to1_COEF_TABLE[] =
{
    tSU_1to1_COEF_96_TAPS_0,        tSU_1to1_COEF_96_TAPS_2,        tSU_1to1_COEF_96_TAPS_4,        tSU_1to1_COEF_96_TAPS_6,        tSU_1to1_COEF_96_TAPS_8,
};
#endif // End of #if(_HSU_96TAPS_SUPPORT == _ON)
#endif // End of #if(_SHARPNESS_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE
//----------------------------------------------------------------------------------------------------
BYTE code tCOLOR_ULTRAVIVID_SETTING_L[] =
{
#include "./UltraVivid/UltraVividTableL.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M[] =
{
#include "./UltraVivid/UltraVividTableM.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_H[] =
{
#include "./UltraVivid/UltraVividTableH.h"
};

code BYTE *tCOLOR_ULTRAVIVID_SETTING_TABLE[] =
{
    tCOLOR_ULTRAVIVID_SETTING_L,
    tCOLOR_ULTRAVIVID_SETTING_M,
    tCOLOR_ULTRAVIVID_SETTING_H,
};

#if(_HDR10_SUPPORT == _ON)
BYTE code tCOLOR_ULTRAVIVID_SETTING_HDR[] =
{
#include "./UltraVivid/UltraVividTableHDR.h"
};
#endif
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// Ypeaking Coefficient Table
//----------------------------------------------------------------------------------------------------
#include "YPeakingTable.h"

code BYTE *tYPEAKING_TABLE[] =
{
    tYPK_COEF_1,
};
#endif // End of #if(_YPEAKING_SUPPORT == _ON)


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_UART_SUPPORT == _ON)
BYTE g_pucUartData[5];
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID);

//-------------------------------------------------------
// for RTD Tool IIC Debug
//-------------------------------------------------------
#if(_DEBUG_IIC_BY_USERINTERFACE == _ON)
bit UserInterfaceDebugIIC(BYTE ucType, BYTE *pucDdcciArray, BYTE *pucReturnValue);
#endif

//-------------------------------------------------------
// INT
//-------------------------------------------------------
#if(_INSTANT_TIMER_EVENT_0 == _ON)
void UserInterfaceTimer0InstantAccess_EXINT(void);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
void UserInterfaceTimer1InstantAccess_EXINT(void);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
void UserInterfaceTimer2InstantAccess_EXINT(void);
#endif

#if(_UART_SUPPORT == _ON)
void UserInterfaceUartIntHandler_SERIALPORT(void);
#endif

#if(_EXT_INT1_SUPPORT == _ON)
void UserInterfaceEXTINT1Handler_EXINT1(void);
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
BYTE UserInterfaceGetDdcciStatus_EXINT1(void);
BYTE UserInterfaceGetFactoryCommand_EXINT1(void);
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void);
#endif
#endif

//-------------------------------------------------------
// EDID & HDCP
//-------------------------------------------------------
#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
EnumHdmiEdidLocation UserInterfaceGetMultiHdmiEdidLocated(BYTE ucInputport, BYTE ucEdidIndex);
EnumEdidSelection UserInterfaceGetMultiHdmiEdidIndex(BYTE ucInputPort);
#endif

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
void UserInterfaceGetEmbeddedEDIDData(EnumInputPortEdid enumInputPort);
#endif

#if(_USB3_RETIMER_SUPPORT == _ON)
extern EnumUSBPDSupportStatus UserInterfaceGetUSBPDSupportStatus(void);
extern EnumUSBPSSupportStatus UserInterfaceGetUSBPSSupportStatus(void);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);

#if(_DP_TX_SUPPORT == _ON)
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
#endif

#if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
void UserInterfaceGetDpTxHdcp2RRMODNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetDpTxHdcp2DcpLlcNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetDpTxHdcp2EKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetDpTxHdcp2NPinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
#endif
#endif


//-------------------------------------------------------
// Wait for Panel Power Sequence Delay
//-------------------------------------------------------
#if(_PANEL_POWER_SEQUENCE_CONTROL_BY_USER == _ON)
void UserInterfacePanelPowerAction(BYTE ucEvent);
#endif

void UserInterfaceAdjustWaitPanelT1(void);
void UserInterfaceAdjustWaitPanelT2(void);
void UserInterfaceAdjustWaitPanelT3(void);
void UserInterfaceAdjustWaitPanelT4(void);
void UserInterfaceAdjustWaitPanelT5(void);

//-------------------------------------------------------
//
//-------------------------------------------------------
void UserInterfaceUncallFunction(void);
void UserInterfaceInitial(void);

void UserInterfacePowerSwitch(EnumPowerAction enumSwitch);
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed);

//-------------------------------------------------------
// User Information
//-------------------------------------------------------
EnumSourceDetectionInfo UserInterfaceSourceBypassDetection(void);
bit UserInterfaceGetLogoStatus(void);
bit UserInterfaceGetdNoSupportStatus(void);
bit UserInterfaceGetDclkNoSupportStatus(void);
bit UserInterfaceGetActiveByPassStatus(void);
bit UserInterfaceGetCableResetStatus(void);
bit UserInterfaceGetForcePSStatus(void);

#if(_HDMI_SUPPORT == _ON)
EnumUserForcePSTmdsHpdToggle UserInterfaceForcePSWakeupTmdsHpdToggle(void);
#endif

#if((_HDMI_2_0_SUPPORT == _ON) && (_HDMI_5V_DETECT_BY_USER == _ON))
EnumUserHdmi5vStatus UserInterfaceTmds5vPinDetect(EnumSourceSearchPort enumInputPort);
#endif

#if(_DVI_SUPPORT == _ON)
EnumTmdsHdcpType UserInterfaceTmdsAcOnGetHdcpCap(void);
#endif

bit UserInterfaceGetIntoPSStatus(void);
EnumUserForceFakePS UserInterfaceGetFakePSStatus(void);
EnumUserForceFakePowerOff UserInterfaceGetFakePowerOffStatus(void);
bit UserInterfaceGetNVRamDataStatus(EnumNvramCheckType enumNvramCheckType);
bit UserInterfaceGetDisplaySettingBacklightAction(void);

EnumColorSpace UserInterfaceGetColorFormat(void);

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
BYTE UserInterfaceGetHpSourceSwitchOsdEventTime(BYTE ucSourceScanType);
#endif

#if(_OVERSCAN_SUPPORT == _ON)
bit UserInterfaceGetOverScanStatus(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
EnumAspectRatioType UserInterfaceGetAspectRatioType(void);
void UserInterfaceGetAspectRatio(WORD *pusHRatio, WORD *pusVRatio);
void UserInterfaceAdjustAspectRatio(void);
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
WORD UserInterfaceGetAspectRatioMinDVHeight(void);
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
BYTE UserInterfaceGetAspectRatioOriginalRatio(void);
BYTE UserInterfaceGetAspectRatioOriginalRatioSmall(void);
#endif

#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
EnumRotationType UserInterfaceGetRotationDegree(void);
EnumRotationDisplayType UserInterfaceGetRotationDisplayType(void);
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
BYTE UserInterfaceGetDisplayLatencyRatio(void);
#endif

#if(_FRC_SUPPORT == _ON)
void UserInterfaceGetDVMaxMinFreq(StructDVCustomizedFreq *pstDVCustomizedFreq);
#endif

void UserInterfaceDisplaySelectMDomainSettingForMain(StructCustomizedMdomain *pstCustomizedMdomain);

#if(_OD_SUPPORT == _ON)
EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void);
#endif

#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && (_DDR3_MULTIPHASE_EXIST == _ON))
void UserInterfaceUpdateDDR3PhaseData(void);
#endif

#if(_USER_SYSTEM_EEPROM_CUSTOMIZATION == _ON)
bit UserInterfaceSystemEepromReadCustomProc(DWORD ulSubAddr, WORD usLength, BYTE *pucReadArray);
bit UserInterfaceSystemEepromWriteCustomProc(DWORD ulSubAddr, WORD usLength, BYTE *pucWriteArray);
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
void UserInterfaceMbrBacklightAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl, WORD usDVTotal);
void UserInterfaceMbrAdimAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl);
EnumMbrPDimCtrl UserInterfaceMbrGetPdimControl(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl);
void UserInterfaceMbrPdimAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl);
EnumMbrBacklightMode UserInterfaceMbrGetBacklightMode(void);
#if((_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON) || (_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
BYTE UserInterfaceMbrGetBacklightDuty(void);
BYTE UserInterfaceMbrGetBacklightPos(void);
#endif
EnumMbrBacklightSeq UserInterfaceMbrGetBacklightSequence(bit bLightCtrl);
WORD UserInterfaceMbrGetBacklightSequenceDelay(bit bLightCtrl);
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
EnumRtkAdvMbrUserStatus UserInterfaceGetRtkAdvMbrSetting(void);
#endif
#endif

WORD UserInterfaceDisplayGetExtendedActiveWaitTime(void);

//-------------------------------------------------------
// Display Timing
//-------------------------------------------------------
void UserInterfaceDisplayInitialization(void);
void UserInterfaceAdjustInputTiming(void);

#if(_UNDERSCAN_SUPPORT == _ON)
bit UserInterfaceAdjustUnderScan(void);
#endif

void UserInterfaceAdjustDisplayTiming(void);

//-------------------------------------------------------
// Color
//-------------------------------------------------------
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) && (_RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER == _ON))
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceGetYCCQuantizationFullRangeStatus(EnumColorYCCQuantization enumColorYCCQuantization);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
EnumFunctionOnOFF UserInterfaceGetDemoModeType(void);
#endif

void UserInterfaceAdjustActiveByPassColorProc(void);
void UserInterfaceAdjustColorProc(void);



#if(_ULTRA_VIVID_SUPPORT == _ON)
void UserInterfaceAdjustUltraVivid(void);
void UserInterfaceAdjustUltraVividProc(EnumDBApply enumDBApply);
#endif

#if(_SHARPNESS_SUPPORT == _ON)
code BYTE *UserInterfaceGetSharpnessCoef(EnumSUCoefType enumSUCoefType, EnumSourceSearchPort enumSourceSearchPort);
BYTE UserInterfaceGetSharpnessCoefBankNum(void);
bit UserInterfaceSharpnessBypassCheck(void);
#endif

#if(_DCR_SUPPORT == _ON)
void UserInterfaceAdjustDCRHandler(void);
#endif

#if(_DCC_HISTOGRM_INFO == _ON)
void UserInterfaceDCCHistogramHandler(void);
#endif

#if(_IAPS_SUPPORT == _ON)
void UserInterfaceAdjustIAPSHandler(void);
#endif

//-------------------------------------------------------
// Osd
//-------------------------------------------------------
void UserInterfaceAdjustOsdPowerOnInitial(void);
void UserInterfaceAdjustOsdActiveProc(void);
void UserInterfaceAdjustOsdResetProc(void);

//-------------------------------------------------------
// Interfaces
//-------------------------------------------------------
#if(_VGA_SUPPORT == _ON)
BYTE UserInterfaceGetVGAConfuseMode(BYTE ucModeIndex);
bit UserInterfaceGetLoadModeTableDefaultStatus(void);
bit UserInterfaceGetFirstAutoConfigStatus(void);
void UserInterfaceGetAutoConfigPercentage(BYTE ucAutoPercentage);

#if(_VGA_FORCE_DISPLAY == _ON)
BYTE UserInterfaceModeSearchModeVGA(void);
#endif

bit UserInterfaceSkipAutoVpos(void);
bit UserInterfaceSkipAutoHpos(void);
#endif

#if(_MHL_SUPPORT == _ON)
bit UserInterfaceAdjustMHLMscRCPProc(BYTE ucKeyCode);
#endif

EnumFreeSyncSupport UserInterfaceGetFreeSyncEnable(EnumSourceSearchPort enumSourcePort);
EnumDpAdaptiveSyncSupport UserInterfaceGetDpAdaptiveSyncEnable(EnumSourceSearchPort enumSourcePort);

#if(_DP_SUPPORT == _ON)
EnumDpVersionType UserInterfaceGetDPVersion(BYTE ucInputPort);
EnumDpLaneCount UserInterfaceGetDpLaneCount(BYTE ucInputPort);
EnumDPMSTPort UserInterfaceGetDpMSTCapablePort(void);

#if(_DP_MST_CAP_ON_INACTIVE_PORT_HPD_LOW == _ON)
EnumDPMSTPort UserInterfaceGetDpMstTargetPort(void);
#endif

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
bit UserInterfaceGetDpCloneOutputStatus(void);
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) || (_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP))
BYTE UserInterfaceGetDpSwitchSelectPort(void);
#endif

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
void UserInterfaceEmbeddedDpSwitch(void);
#endif

#if(_DP_DC_ON_HPD_CONTROL_BY_USER_SUPPORT == _ON)
EnumDpHpdToggleMode UserInterfaceGetDpDcOnHpdMode(void);
#endif

#endif // End of #if(_DP_SUPPORT == _ON)

#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
EnumSourceSearchPort UserInterfaceHdmiExternalSwitchDefaultPort(void);
#endif

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
bit UserInterfaceGetHdmi5VStatus(BYTE ucInputPort);
#endif

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_EIZO_STYLE)
bit UserInterfaceAdjustOsdCheckTotalSearchFinish(void);
void UserInterfaceAdjustSourceSearchTime(void);
WORD UserInterfaceAdjustSourceReactiveSearchTime(EnumSourceAdjustReactiveTimePortType enumSourceAdjustReactiveTimePortType);
WORD UserInterfaceGetEizoSearchFinishTime(void);
#endif

//-------------------------------------------------------
// AUDIO
//-------------------------------------------------------
#if(_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioReadyToPlayStatus(void);
EnumAudioInputSource UserInterfaceGetAudioSource(void);
bit UserInterfaceGetAudioMuteStatus(void);
EnumAudioCodingType UserInterfaceGetAudioNonLPCMStatus(void);
EnumAudioMuteStatus UserInterfaceAudioGetOutputMuteStatus(void);
WORD UserInterfaceGetAudioVolume(void);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void);
bit UserInterfaceGetAudioDACKeepDepopState(void);
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioStandAloneStatus(void);
#endif

void UserInterfaceAdjustAudioResetProc(void);
void UserInterfaceAdjustAudioPowerProc(EnumPowerStatus enumPowStatus);
void UserInterfaceAdjustAudioAmpMuteProc(bit bMute);
EnumAudioSamplingFreqType UserInterfaceAudioGetUserSamplingFreq(void);

#if(_DP_SUPPORT == _ON)
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
EnumAudioDpDpcdSupport UserInterfaceAudioDpGetCapabilityInitialState(BYTE ucInputPort);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void UserInterfaceAdjustAudioAmpFastMuteProc(bit bMute);
#endif

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
void UserInterfaceAudioExternalCodecProc(bit bEnable);
#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
void UserInterfaceAudioExternalCodecFastProc(bit bEnable);
#endif
#endif

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
void UserInterfaceSwapExternalAudioCodecInput(bit bSwap);
#endif

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
bit UserInterfaceAudioGetTtsSupport(void);
BYTE UserInterfaceAudioGetTtsPlayAudioVolume(void);
BYTE UserInterfaceAudioGetTtsPlayTextVolume(void);
bit UserInterfaceAudioGetTtsAudioReady(void);
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#if(_INTERNAL_AUDIO_CHANNEL_CONFIG_BY_USER_SUPPORT == _ON)
EnumAudioInternalGenFreq UserInterfaceAudioGetUserDefineAudioGenFreq(void);
EnumAudioLeftRightChannelSelect UserInterfaceAudioGetUserLeftRightChanelSelect(void);
#endif
#endif
#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON) || (_UNIFORMITY_SUPPORT == _ON))
void UserInterfaceAdjustBeforeDisplayCalibration(EnumCaliType enumMode);
void UserInterfaceAdjustAfterDisplayCalibration(EnumCaliType enumMode);
void UserInterfaceAdjustBacklight(BYTE ucBacklight);
#endif

#if(_BACKLIGHT_DIMMING_SUPPORT == _ON)
void UserInterfaceAdjustBeforeDimmingCalibration(void);
void UserInterfaceAdjustAfterDimmingCalibration(void);
#endif

#if(_LD_HDR10_BOOST_SUPPORT == _ON)
void UserInterfaceAdjustLDBoostCalibration(bit bBoost);
#endif

#if(_YPEAKING_SUPPORT == _ON)
void UserInterfaceAdjustYpeaking(void);
#endif

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
EnumDDCCIDebugMode UserInterfaceGetDdcciMode(void);
EnumDataExchangeRepeaterPowerState UserInterfaceGetRepeaterIntoPowerOff(void);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
EnumDrrFreeSyncDpGetIVF UserInterfaceDisplayDpFreeSyncGetIVFmaxFromLut(WORD *pusVfreqMax);
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
EnumDrrFreeSyncHdmiGetIVF UserInterfaceDisplayHdmiFreeSyncGetIVFmaxFromLut(WORD *pusVfreqMax);
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
EnumDrrVrrHdmiGetIVF UserInterfaceDisplayHdmiVrrGetIVFmaxFromLut(WORD *pusVfreqMax);
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
#if(_HDMI_FREESYNC_SUPPORT == _ON)
void UserInterfaceFreeSyncGetHdmiAupiPanelInfo(StructDrrAmdAupiInfo *pstDrrHdmiAmdAupiInfo);
#endif
#endif

#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT)
void UserAdjustPwmDcr();
BYTE UserAdjustDCRCalPwm(BYTE ucRGBValValue);
BYTE UserAdjustDCRGetPwm(void);
void UserAdjustDCRControl(bit bEn);
void UserInterfaceAdjustDCR(void);

BYTE g_ucDCR_15SEC_OffBLFlag = _FALSE;
BYTE g_ucDCR_TUNE_1STEP_Flag = _FALSE;
extern void UserAdjustDCRBacklight(WORD uSDcrBacklight);

#endif
#endif

#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT)

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CDcrReset(void)
{
    CLR_Y_MAX_UNDER_LABEL_STATUS();
    CLR_HIGH_DCR_STATUS();

    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_SLOW_ADJUST);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_BACKLIGHT_OFF);
    CLR_L4_PATTEN_TIMER();
    SET_DCR_HOLD_STATUS(_FALSE);
}

#if(_DCR_TURNOFF_BACKLIGHT_SUPPORT == _ON)
void CDcrL4PattenDetectStatus(void)
{
    SET_Y_MAX_UNDER_LABEL_STATUS();
}
#endif

extern void OsdDisplayUpdatePowerBar(BYTE ucPreload); //���¹��Ľ�����

//--------------------------------------------------
// Description  : Step by step adjust the backlight
//                by control PWM
// Input Value  : ucValue
// Output Value : None
// Return Value : None
//--------------------------------------------------
#define _DEF_DCR_BACK_TIME_ON 					(1)
#define _DCR_ACTIVE_VALUE_MIN                   4
#define _DCR_ACTIVE_VALUE_MAX                   254//255

#if(_DCR_BIT_MODE == _DCR_GEN_1_0_10BIT)
#define _DCR_LEVEL_LOW                          18//(8 * 4)
#else
#define _DCR_LEVEL_LOW                          8
#endif
#define _BACKLIGHT_MIN_HIGH_DCR                 0

void CDcrSlowAdjust(void)
{

	static BYTE ucECOBackup = _ECO_DEFAULT;
	static BYTE ucCount = 0;

	if(GET_OSD_DCR_STATUS() == 0)
		return;

#if(_MPRT_SUPPORT == _ON)
	if(GET_OSD_MPRT() != _OFF /*&& ucVFreq > _DEF_OSD_OVER_VFREQ*/)
		return;
#endif

	ucCount++;


	if(GET_OSD_DCR_STATUS() == _DCR_Level_1)
	{
		if(ucCount>2)
			ucCount = 1;
		if(ucCount ==1)
		return;
	}
	else if(GET_OSD_DCR_STATUS() == _DCR_Level_2)
	{
		if(ucCount>5)
			ucCount = 1;
		if(ucCount ==2||ucCount ==4)
		return;
	}
	else if(GET_OSD_DCR_STATUS() == _DCR_Level_3)
	{
		if(ucCount>4)
			ucCount = 1;
		if(ucCount ==4)
		return;
	}
	else if(GET_OSD_DCR_STATUS() == _DCR_Level_4)
	{

	}


    if(GET_DCR_HOLD_STATUS() == _TRUE)
	{
		if((abs(GET_DCR_PreRGB_INFORMATION() - GET_DCR_RGB_INFORMATION()) > 10)&&(ScalerOsdGetOsdEnable() == 0x00)) // original range is 20
		{
			SET_DCR_HOLD_STATUS(_FALSE);
		}
	}
	else
    {
        //DebugMessageOsd("####9.GET_DCR_RGB_INFORMATION  ######",  GET_DCR_RGB_INFORMATION() );

		if(GET_DCR_RGB_INFORMATION() >= 254)	//ȫ�׳�+��� = 254  xwei
		{
            SET_DCR_TARGET_VALUE(100);
		}
        else if((GET_DCR_RGB_INFORMATION() >= _DCR_ACTIVE_VALUE_MIN) && (GET_DCR_RGB_INFORMATION() <= _DCR_ACTIVE_VALUE_MAX))
        {
            SET_DCR_TARGET_VALUE((WORD)GET_DCR_RGB_INFORMATION() * 100 / _DCR_ACTIVE_VALUE_MAX);
        }
        else if((GET_DCR_RGB_INFORMATION() < _DCR_ACTIVE_VALUE_MIN) && (!GET_Y_MAX_UNDER_LABEL_STATUS()))
        {
            if(ScalerOsdGetOsdEnable())
            {
                if(GET_DCR_RGB_INFORMATION() < _DCR_ACTIVE_VALUE_MIN)
                {
                    GET_DCR_RGB_INFORMATION() = _DCR_ACTIVE_VALUE_MIN;
                }

                g_stDcrInfo.ucRGBInfo -= _DCR_ACTIVE_VALUE_MIN;
                SET_DCR_TARGET_VALUE((WORD)GET_DCR_RGB_INFORMATION() * 100 / (_DCR_ACTIVE_VALUE_MAX - _DCR_ACTIVE_VALUE_MIN));

    		    CLR_L4_PATTEN_TIMER();
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_BACKLIGHT_OFF);
            }
            else
            {
                SET_DCR_TARGET_VALUE(0);

                if(GET_PANELPOWERSTATUS() == _PANEL_BACKLIGHT_OFF)
                {
                    //UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
                     ScalerTimerActiveTimerEvent(SEC(_DEF_DCR_BACK_TIME_ON), _USER_TIMER_EVENT_DCR_BACKLIGHT_ON);
                }
            }
        }
        else if(GET_Y_MAX_UNDER_LABEL_STATUS())
        {
            if(!ScalerOsdGetOsdEnable())
            {
                if(GET_HIGH_DCR_STATUS())
                {
                    SET_DCR_TARGET_VALUE(0);
                    CLR_HIGH_DCR_STATUS();
                    CLR_Y_MAX_UNDER_LABEL_STATUS();
					CLR_L4_PATTEN_TIMER();
                }
                else
                {
//                    PCB_BACKLIGHT_PWM(_BACKLIGHT_MIN_HIGH_DCR);
                    #if(_BACKLIGHT_PWM_INVERSE == _ON)
					PCB_BACKLIGHT_PWM(0xff - _BACKLIGHT_MIN);
                    //PCB_BACKLIGHT_PWM(UserGetBacklightRealValue(255 - _BACKLIGHT_MIN));
                    #else
					PCB_BACKLIGHT_PWM(_BACKLIGHT_MIN);
                    //PCB_BACKLIGHT_PWM(UserGetBacklightRealValue(_BACKLIGHT_MIN));
                    #endif	

                    PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

                    if(GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE)
        			{
                        SET_PANELPOWERSTATUS(_PANEL_BACKLIGHT_OFF);
                    }

                    SET_DCR_ADJUST_VALUE(1);
                    return;
                }
            }
            else
            {
                SET_DCR_TARGET_VALUE(GET_OSD_BACKLIGHT());

                
				//UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				 ScalerTimerActiveTimerEvent(SEC(_DEF_DCR_BACK_TIME_ON), _USER_TIMER_EVENT_DCR_BACKLIGHT_ON);
                

                SET_HIGH_DCR_STATUS();
            }
        }
		else
		{
	    	SET_DCR_TARGET_VALUE(100);
		}

        if(GET_DCR_ADJUST_VALUE() != GET_DCR_TARGET_VALUE() || (GET_OSD_ECO_STATUS() != ucECOBackup))
        {

		    if(GET_OSD_ECO_STATUS() != ucECOBackup)
    		{
    			ucECOBackup = GET_OSD_ECO_STATUS();
    		}
					
            if(GET_DCR_ADJUST_VALUE() > GET_DCR_TARGET_VALUE())
            {
                g_stDcrInfo.ucDcrAdjustValue --;
            }
            else if(GET_DCR_ADJUST_VALUE() <GET_DCR_TARGET_VALUE())
			{
               	g_stDcrInfo.ucDcrAdjustValue ++;
		
                if(GET_PANELPOWERSTATUS() != _BACKLIGHT_ON_ALREADY)
                {
                    
                    //UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
                     ScalerTimerActiveTimerEvent(SEC(_DEF_DCR_BACK_TIME_ON), _USER_TIMER_EVENT_DCR_BACKLIGHT_ON);
                    
                }
            }
#if 0//(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)			
			SET_DCR_ADJUST_VALUE(GET_DCR_TARGET_VALUE());      //tianxiao add
#endif			
			UserAdjustDCRBacklight(GET_DCR_ADJUST_VALUE());
			OsdDisplayUpdatePowerBar(_TRUE);
        }
		else{
				UserAdjustDCRBacklight(GET_DCR_ADJUST_VALUE());
				OsdDisplayUpdatePowerBar(_TRUE);
			}
    }
}

#endif
#endif
extern BYTE g_ucKeyStateCurr;

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : User timer event process
// Input Value  : Event ID
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID)
{

#if(_DEF_OSD_GAMING == _ON)
	WORD TEMP = 0;
#endif

    switch(enumEventID)
    {
        case _USER_TIMER_EVENT_KEY_REPEAT_ENABLE:
            SET_KEYREPEATSTART();
            break;

        case _USER_TIMER_EVENT_KEY_SCAN_READY:
            SET_KEYSCANREADY();
            break;

        case _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO:
            OsdDispDisableOsd();
            SET_OSD_LOGO_ON(_OFF);

#if(_INSTANT_TIMER_EVENT_0 == _ON)
            //ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif

#if(_PANEL_POW_SEQ_FAST_MODE == _ON)
            
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
#else
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);
#endif
            ScalerDDomainBackgroundEnable(_ENABLE);
            ScalerDDomainPatternGenEnable(_DISABLE);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOCABLE_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL:
			
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSIGNAL_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG);
            break;

        case _USER_TIMER_EVENT_GO_TO_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_DISABLE:
			//DebugMessageOsd("1._USER_TIMER_EVENT_OSD_DISABLE",GET_OSD_STATE());

			//DebugMessageOsd("2.g_OsdCursorFlickerTips_Num",g_OsdCursorFlickerTips_Num);

			if(Language_District_flang) //2025.02.07  tx
			Language_District_flang=0;
			
#if(_DEF_OSD_CURSOR_FLICKER_TIPS == _ON)
			if(g_OsdCursorFlickerTips_Num < _DEF_OSD_CURSOR_FLICKER_TIPS_TIMES) 
			{
				if(GET_OSD_STATE() == _OSD_HOTKEY_FUNC)   //���Ե�����˸
				{
					g_OsdCursorFlickerTips_Num++;
					OsdDisplayCursorFlickerTipFun();	  //��˸
					ScalerTimerActiveTimerEvent(_DEF_HOTOSD_FLICKER_TIPS_TIME, _USER_TIMER_EVENT_OSD_DISABLE);
					break;
				}
				else if(GET_OSD_STATE() > _MENU_NONE && GET_OSD_STATE() <= _MENU_NULL)//�˵���˸
				{
					g_OsdCursorFlickerTips_Num++;
					OsdDisplayCursorFlickerTipFun();	  //��˸
					ScalerTimerActiveTimerEvent(_DEF_OSD_MENU_FLICKER_TIPS_TIME, _USER_TIMER_EVENT_OSD_DISABLE);
					break;
				}
			}
#endif
			// 
#if(_5KEY_MENU_STYLE)  //2025.02.07 tx			
			if(GET_OSD_STATE() == _OSD_HOTKEY_FUNC)
			{
				if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_LANGUAGE_SELECT)
				{
					SET_OSD_LANGUAGE_HK_STATUS(_OFF);
					SET_OSD_LANGUAGE(OSD_SubMenuCur);
					OsdDispDrawHotKeyWindow(_OSD_HOTKEY_DISTRICT_SELECT);
#if(_DEF_OSD_CURSOR_FLICKER_TIPS == _ON)
					g_OsdCursorFlickerTips_Num=0;
#endif
					ScalerTimerActiveTimerEvent(SEC(OsdDisplayTimeOut(GET_OSD_TIME_OUT())-3), _USER_TIMER_EVENT_OSD_DISABLE);
					break;
				}				
				else if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT)
				{
					HotKeyFUNAdjust();

				}

				if(OSD_HOT_KEY_PAGE == _OSD_HOTKEY_DISTRICT_SELECT)
				{
					SET_OSD_DISTRICT_SWTICH_STATE(_OFF);
				}
				
			}
#endif
            #if(_AI_LOW_POWER == _ON)
            if(GET_OSD_AI_LOW_POWER_STATUS())
            {
                if(GET_OSD_STATE() == _OSD_MESSAGE_MENU_AI_LOW_POWER)
                {
                    UserAdjustBacklight(15);
                    bAI_LowPower_Status = 1;
                }
            }
            #endif
            OsdDispDisableOsd();
			DebugMessageOsd("0.EVENT_OSD_DISABLE",GET_OSD_STATE());
			
#if(_DEF_OSD_GAMING == _ON)
			ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_GAME_HOTKEY);
#endif

            break;

        case _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON:
            SET_PANELPOWERSTATUS(_READY_FOR_BACKLIGHT);
            break;

#if(_DEF_OSD_Freesync_Info_Eanble)
		case _USER_TIMER_EVENT_FREESYNC_OSD_EANBLE: //Freesync	�˵�ʵʱˢ��Ƶ��
			OsdFreesyncOsdTimingRefresh();
			break;
#endif

		case _USER_TIMER_EVENT_SAVE_OSD_DATE:
			RTDNVRamSaveOSDData();
			break;

		case _USER_TIMER_EVENT_SAVE_SCENEMODE_DATA:
            RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
			break;

		case _USER_TIMER_EVENT_SIX_COLOR_DATA:
			//RTDNVRamSaveSixColorData();
			break;
		
		case _USER_TIMER_EVENT_COLOR_SETTING_DATA:
            RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
			break;


        case _USER_TIMER_EVENT_POWER_INDICATOR:
			UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_INDICATOR);
            break;

        case _USER_TIMER_EVENT_PANEL_POWER_OFF:
            //SET_FACTORY_MODE(_OFF);
            //SET_FACTORY_BURNIN(_OFF);
            //RTDNVRamSaveOSDData();
            SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
            break;

#if(_VGA_SUPPORT == _ON)
        case _USER_TIMER_EVENT_DO_AUTO_COLOR:
            CLR_KEY_HOLD();
            OsdDisplayAutoBalanceProc();
            break;
#endif
		case _USER_TIMER_EVENT_UPDATE_VFREQ:
			
			#if _GSYNC_TEST
			if(GET_OSD_STATE() == _OSD_HOTKEY_VFREQ && GET_OSD_FREE_SYNC_STATUS())
			{
				DrawRefreshNum();
				ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_UPDATE_VFREQ);
			}
			#endif
			break;

        case _USER_TIMER_EVENT_PANEL_USED_TIMER:
            RTDFactoryPanelUsedTimer();
            break;

		case _USER_TIMER_EVENT_BUININ_MSG:
			
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_BUININ_MSG);
			break;

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
        case _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE:
            UserAdjustHLWinType5Move();
            break;
#endif



        case _USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT:
            CLR_KEY_HOLD();

            if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
            {
                SET_OSD_POWER_SAVING_SHOW_DP_OPTION(_TRUE);
                ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
            }
            else
            {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_DP_VERSIOM_MSG);
            }

            break;

#if(_HDMI_CEC_SUPPORT == _ON)
        case _USER_TIMER_EVENT_CEC_LA_POLLING:

            g_bCecLaPollingStart = 1;
            g_ucCecLaCnt = 0;
            break;
#endif


#if 0//(_FREESYNC_SUPPORT == _ON)
        case _USER_TIMER_EVENT_OSD_SHOW_FREESYNC_VFREQ:
            if((GET_OSD_STATE() == _MENU_INFORMATION) && (ScalerSyncGetFREESYNCEnable() == _TRUE))
            {
                g_usFontPointer1 = GET_FREESYNC_OSD_ADDRESS();
                //OsdPropPutString(ROW(14 + 1), COL(16), _PFONT_PAGE_1, _STRING_NOW_RESOLUTION, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);
                ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_SHOW_FREESYNC_VFREQ);
            }
            break;
#endif

#if(_FREEZE_SUPPORT == _ON)
        case _USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG:
            OsdFuncDisableOsd();
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_OSD_STATE() != _MENU_NONE))
            {
#if(_URGENT_EVENT_CHECK_MODE == _OFF)
                SET_FREEZE_DISABLE_MSG_STATE(_OFF);
#endif
            }
            break;
#endif

#if(_LD_HDR10_BOOST_SUPPORT == _ON)
        case _USER_TIMER_EVENT_HDR_BOOST:
            g_bHdrBoost = _FALSE;
            break;

        case _USER_TIMER_EVENT_HDR_COOL:
            g_bHdrBoost = _TRUE;
            break;
#endif


#if(_DEF_DDCCI_EDID_TOOL || _DEF_DDCCI_WB_TOOL)
		case _USER_TIMER_EVENT_BURN_IN_DDCTOOL: 	
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BUININ_MSG); 
				RTDBurnInMenu();	  
				UserAdjustContrast(100);
				UserAdjustBacklight(100);
				UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
						
		   	break;
#endif				

		case _USER_TIMER_EVENT_BURN_IN:
			//TPVFactFuncBurnInPattern();
			break;
			
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)

		case _USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER:
			
			IndicatoLlghtFlickerEvent();
		break;

#endif



#if(_AUDIO_SUPPORT == _ON)
#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

        case _USER_TIMER_EVENT_AUDIO_TTS_SHOW_LOGO:

            if(UserInterfaceAudioGetTtsAudioReady() != _TRUE)
            {
                ScalerTimerReactiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUDIO_TTS_SHOW_LOGO);
            }
            else
            {
                UserAdjustAudioTtsPlayEvent(_AUDIO_TTS_EVENT_OSD_LOGO_SHOW);

                ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
            }
            break;

        case _USER_TIMER_EVENT_AUDIO_TTS_POWER_OFF:
            SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
            break;



			
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
#endif // End of #if(_AUDIO_SUPPORT == _ON)


#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT == _ON)
		case _USER_TIMER_EVENT_DCR_CAL_TIME:
			g_ucDCR_15SEC_OffBLFlag = _TRUE;
			break;
			
		case _USER_TIMER_EVENT_DCR_TUNE_PWM_TIMER:
			g_ucDCR_TUNE_1STEP_Flag = _TRUE;
			break;
#endif
#endif


#if(_MPRT_SUPPORT == _ON)
				
		case _USER_TIMER_EVENT_MPRT:

			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_MPRT);
			
			PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
			/*
			if(GET_OSD_MPRT())
			{
			}
			else
			{
				PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
			}	*/
			
			break;	
#endif

		case _USER_TIMER_EVENT_BACKLIGHT_POWER_ON:

			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BACKLIGHT_POWER_ON);
			
			PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

			break;	

		case _USER_TIMER_EVENT_RESET_TO_SEARCH:
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_RESET_TO_SEARCH);

			OsdFunDpVersion();
			SET_OSD_STATE(_MENU_NONE);
			
			OsdFuncDisableOsd();
			OsdFuncCloseWindow(_OSD_WINDOW_ALL);

			break;	

		case _USER_TIMER_EVENT_RESET_TO_DISPLAY_SETTING:
			
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_RESET_TO_DISPLAY_SETTING);
		
			SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
			
			SET_OSD_STATE(_MENU_NONE);
			OsdFuncDisableOsd();
			OsdFuncCloseWindow(_OSD_WINDOW_ALL);

			break;	


#if _OSD_Sleep_PowenOff_Fun
		
		case _USER_TIMER_EVENT_AUTO_POWER_DOWN:
			
			g_usPowerOffCount-=1;
			ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_AUTO_POWER_DOWN); 
			
			if(g_usPowerOffCount== 0)
			{	
				

				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_DOWN); 
				//SET_OSD_Sleep_PowerOff(_OFF);
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
#endif
				//PCB_LED_OFF();
				UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
#if(_MPRT_SUPPORT == _ON)
				UserAdjustMPRTFuntion(_OFF);
#endif

				SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
			}
			break;
#endif

#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT== _ON)
			case _USER_TIMER_EVENT_DCR_SLOW_ADJUST:
				//DebugMessageOsd("5.Slow Adjust", 273);
				CDcrSlowAdjust();
				break;

			case _USER_TIMER_EVENT_DCR_BACKLIGHT_OFF:
#if(_DCR_TURNOFF_BACKLIGHT_SUPPORT == _ON)
				CDcrL4PattenDetectStatus();
#endif
				break;
#endif
#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT == _ON)

			case _USER_TIMER_EVENT_DCR_BACKLIGHT_ON:
				UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
				break;
#endif
#endif

#endif

			case _USER_TIMER_EVENT_OSD_SHOW_Front_Sight:
				
#if(_FRONT_SIGHT_FUNCTION == _ON)
				OsdDispFrontSight();
#endif
				break;

			
			case _USER_TIMER_EVENT_OSD_SHOW_Timing_Notice:
				
#if _OSD_Timing_Notice
				if(SysModeGetModeState() != _MODE_STATUS_ACTIVE)
				{
					g_usShowTimingNotice=0;
				}
				else if((GET_OSD_STATE()==_MENU_NONE) && !GET_FACTORY_MODE())
				{
					if(g_usShowTimingNotice==1 && GET_OSD_RESOLUTION_STATUS()==_ON)
					{
						OsdDispOsdMessage(_OSD_DISP_Timing_Notice);
						//ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
						g_usShowTimingNotice=0;
					}
				}
#endif
				break;

		
			case _USER_TIMER_EVENT_AUTO_POWER_Saving:
#if _OSD_PowerSaving_Fun
				DebugMessageOsd("1.g_usPowerSavingCount",g_usPowerSavingCount);

				g_usPowerSavingCount--;
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUTO_POWER_Saving); 
				if(g_usPowerSavingCount <= (_OSD_TIME_AUTO_DOWN_COUNT+1) && GET_AUTO_SLEEP_STATUS()!=_SleepPowerSaving_OFF)
				{	
						
					if(g_usPowerSavingCount == (_OSD_TIME_AUTO_DOWN_COUNT+1))
						OsdDispOsdMessage(_OSD_DISP_SLEEP_MSG);
					else if(g_usPowerSavingCount == 0)
					{
						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUTO_POWER_Saving); 
						
						UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER); 
						SET_AUTO_SLEEP_STATUS(_SleepPowerSaving_OFF);
						SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
						SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF); 	
					}
					else
						OsdPropShowNumber(ROW(_OSD_POWER_DOWN_ROW_START+3), COL(_MSG_TITLE_STRING_COL + (_OSD_MSG_COL_NUM_23 / 2)), g_usPowerSavingCount-1 , (_ALIGN_LEFT| _FORCE_SHOW_NUMBER_OFF | _SHOW_2), _PFONT_PAGE_1,VSC_MAIN_FONT_COLOR1);
		
				}
#endif
				break;

			case _USER_TIMER_EVENT_POWER_DOWN:
				
				if(SysPowerGetPowerStatus() != _POWER_STATUS_OFF)
				{
					if(GET_OSD_PWKEY_LOCK_STATUS() == _TRUE)
					{
						if((GET_OSD_LOGO_ON() == _OFF)&&(SysModeGetModeState() == _MODE_STATUS_ACTIVE))
						{
							SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_LOCK_MSG);
						}
					}
					else
					{
	      #if(_DEF_INDICATO_LIGHT_Flick_EANBLE)       //tanxiao add
						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
			            if(GET_FACTORY_MODE())
			            {
			              UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
						}
          #endif				
					    DebugMessageOsd("POWER_OFF",1467);
						SET_FACTORY_MODE(_OFF);
						SET_FACTORY_BURNIN(_OFF);
						Input_New_State=10;
						ddcci_reset=0;
						TPVNVRamSaveFactoryDate();
#if(_PROJECT_ID ==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)
						if(GET_AUTO_SLEEP_STATUS() != _SleepPowerSaving_OFF)
						{
							SET_AUTO_SLEEP_STATUS(GET_AUTO_SLEEP_STATUS());
							RTDNVRamSaveOSDData();
						}
#endif
						SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
					}
				}
				break;

	
			case _USER_TIMER_EVENT_OSD_SHOW_OSD_LOCKING_STATUS_MSG:
				SET_KEY_LONG_PRESSED(_TRUE);
				OsdDisplayCombineKeyFunction(_COMBINE_LOCK_OSD, GET_KEY_TIME_FOR_SECOND());
				ADD_KEY_TIME_FOR_SECOND();
				ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_SHOW_OSD_LOCKING_STATUS_MSG);
				break;
	
			case _USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG:
				if(GET_AUTO_POWEROFF_STATUS() == _ON)
				{
					SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_AUTO_POWER_OFF_MSG);
				}
				else
				{
					SET_KEY_LONG_PRESSED(_TRUE);
					OsdDisplayCombineKeyFunction(_COMBINE_LOCK_POWERKEY, GET_KEY_TIME_FOR_SECOND());
					ADD_KEY_TIME_FOR_SECOND();
					ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG);
				}
				break;
	
			case _USER_TIMER_EVENT_OSD_SHOW_LOGO_BOOTUP_STATUS_MSG:
#if(_DEF_HotOSD_Logo_MessageEanble_swtich == _OFF)
				SET_FACTORY_FORCE_LOGO_OFF(!GET_FACTORY_FORCE_LOGO_OFF());
#endif
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_LOGOBOOTUP_MSG);
				TPVNVRamSaveFactoryDate();

				break;


#if(_DEF_OSD_GAMING == _ON)

			case _USER_TIMER_EVENT_GAME_HOTKEY:
				
				DebugMessageOsd("0._USER_TIMER_EVENT_GAME_HOTKEY",GET_OSD_STATE());
				
				if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) /*&& (GAME_FLAG > 0XF0 || ScalerOsdGetOsdEnable() == _DISABLE)*/ && GET_OSD_STATE() == _MENU_NONE)
				{
					if (GET_OSD_PRE_GAME_FPS())
					{
						TEMP = GET_INPUT_TIMING_VFREQ();
						
						DebugMessageOsd("0.4444444",GAME_FLAG);
						ScalerTimerActiveTimerEvent(SEC(0.3), _USER_TIMER_EVENT_GAME_HOTKEY);
						
						if(TEMP % 10 >= 8)
						{
							TEMP = (TEMP / 10 + 1) * 10;
						}

						if (GAME_FLAG != 0xf1)
						{
							//OsdDispDisableOsd();
							SET_OSD_STATE(_MENU_NONE);
						    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
						    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
						    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
						    OsdFuncDisableOsd();
						    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
							OsdFuncApplyMap(WIDTH(9), HEIGHT(3), COLOR(_CP_WHITE, _CP_BG));
							OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

							OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY_GAME);

							SET_OSD_STATE(_MENU_NONE);
							OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 99, 1);
						}

						if (TEMP > 9999)
							TEMP = 9999;

						GAME_FLAG = TEMP / 1000;

						if (GAME_FLAG == 0)
						{
							GAME_FLAG = 11;
						}
						

						OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = (TEMP % 1000) / 100;
						OsdFontPut1BitTable(ROW(0), COL(3), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = (TEMP % 100) / 10;
						OsdFontPut1BitTable(ROW(0), COL(6), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = 0xf1;
						
						OsdFuncEnableOsd();
						

						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
					}

					else if (GET_OSD_PRE_GAME_TIME())
					{
					
						ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_GAME_HOTKEY);
						
						if (TIME_COUNT == 0)
						{
							SET_OSD_PRE_GAME_TIME(0);

							ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
							OsdDispDisableOsd();
							return;
						}
						
						DebugMessageOsd("0.555555",GET_OSD_STATE());

						TIME_COUNT--;

						if(GAME_FLAG != 0xf2)
						{
							//OsdDispDisableOsd();
							SET_OSD_STATE(_MENU_NONE);
						    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
						    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
						    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
						    OsdFuncDisableOsd();
						    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
							OsdFuncApplyMap(WIDTH(14), HEIGHT(3), COLOR(_CP_WHITE, _CP_BG));
							OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

							OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY_GAME);

							SET_OSD_STATE(_MENU_NONE);
						}


						GAME_FLAG = TIME_COUNT / 60 / 10;

						OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = (TIME_COUNT / 60) % 10;

						OsdFontPut1BitTable(ROW(0), COL(3), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = 10;

						OsdFontPut1BitTable(ROW(0), COL(6), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = (TIME_COUNT % 60) / 10;

						OsdFontPut1BitTable(ROW(0), COL(8), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = (TIME_COUNT % 60) % 10;

						OsdFontPut1BitTable(ROW(0), COL(11), tiOSD_1BIT_GAME_FPS[GAME_FLAG], COLOR(_CP_WHITE, _CP_BG));

						GAME_FLAG = 0xf2;
						
						OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 1, 1);
						
						OsdFuncEnableOsd();
						

						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
					}

					else if (GET_OSD_PRE_GAME_CROSS())
					{
						ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_GAME_HOTKEY);

						if (GAME_FLAG != 0xf0)
						{
							//OsdDispDisableOsd();
							SET_OSD_STATE(_MENU_NONE);
						    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
						    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
						    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
						    OsdFuncDisableOsd();
						    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
							OsdFuncApplyMap(WIDTH(2), HEIGHT(1), COLOR(_CP_WHITE, _CP_BG));
							OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

							OsdFontVLCLoadFont(_FONT_1BIT_HOTKEY_GAME);

							SET_OSD_STATE(_MENU_NONE);
						}
						
						ScalerOsd2FontFunction(_DISABLE);

						if(GET_OSD_PRE_GAME_CROSS() > 6)
						{
							OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_CROSS[GET_OSD_PRE_GAME_CROSS() - 4], COLOR(_CP_BLUE_1, _CP_BG));
						}
						else if (GET_OSD_PRE_GAME_CROSS() > 3)
						{
							OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_CROSS[GET_OSD_PRE_GAME_CROSS() - 4], COLOR(_CP_GREEN, _CP_BG));
						}
						else
						{
							OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_1BIT_GAME_CROSS[GET_OSD_PRE_GAME_CROSS() - 1], COLOR(_CP_RED, _CP_BG));
						}

						OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
						
						GAME_FLAG = 0xf0;

						OsdFuncEnableOsd();


						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
					}
					else
					{
						ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
					}
				}
				else
				{
					ScalerTimerReactiveTimerEvent(SEC(6), _USER_TIMER_EVENT_GAME_HOTKEY);
				}

			break;
#endif
        #if _EYE_VLI_SUPPORT
        case _USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT:
            {
                bit bAllAIFeaturesEnabled = _TRUE;
                
                #if(_AI_EYE_PROTECTION == _ON)
                if(GET_OSD_AI_EYE_PROTECTION_STATUS() == _FALSE)
                {
                    bAllAIFeaturesEnabled = _FALSE;
                }
                #endif
                
                #if(_AI_LIGHT_ADAPTIVATION == _ON)
                if(GET_OSD_AI_LIGHT_ADAPTIVATION_STATUS() == _FALSE)
                {
                    bAllAIFeaturesEnabled = _FALSE;
                }
                #endif
                
                #if(_AI_LOW_POWER == _ON)
                if(GET_OSD_AI_LOW_POWER_STATUS() == _FALSE)
                {
                    bAllAIFeaturesEnabled = _FALSE;
                }
                #endif
                
                if(bAllAIFeaturesEnabled)
                {
                    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
                }
                ScalerEyeProtectEventProc();
                ScalerTimerReactiveTimerEvent(500, _USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
            }
            break;
        #endif

        default:
            break;
    }
}

#if(_DEBUG_IIC_BY_USERINTERFACE == _ON)
//--------------------------------------------------
// Description  : User Debug Tool Page IIC
// Input Value  : Event ID
// Output Value : None
//--------------------------------------------------
bit UserInterfaceDebugIIC(BYTE ucType, BYTE *pucDdcciArray, BYTE *pucReturnValue)
{
    bit bDebugMode = _FALSE;

    pucDdcciArray = pucDdcciArray;
    pucReturnValue = pucReturnValue;

#if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)
    if(bDebugMode == _FALSE)
    {
        bDebugMode = ExternalDeviceInterfaceLedDriverDebug(ucType, pucDdcciArray, pucReturnValue);
    }
#endif

    return bDebugMode;
}
#endif

#if(_INSTANT_TIMER_EVENT_0 == _ON)
//--------------------------------------------------
// Description  : Action in Timer0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer0InstantAccess_EXINT(void)
{

    g_bflagSecondON = _FALSE;

    GET_OSD_TIME_FOR_INTCOUNT()++;

    // one second count
    if(GET_OSD_TIME_FOR_INTCOUNT() >= 50)
    {
        SET_OSD_TIME_FOR_INTCOUNT(0);
        GET_OSD_TIME_FOR_SECOND()++;
        g_bflagSecondON = _TRUE;
    }

	if((g_bflagSecondON == _TRUE) && (GET_KEY_PRESSED() == _TRUE))
	{
		GET_KEY_TIME_FOR_SECOND()++;
	}


/*
    if(GET_OSD_LOGO_ON() == _ON)
    {
        if(g_ucLogoTimerCounter != 0xFF)
        {
            g_ucLogoTimerCounter++;
        }

        switch(g_ucLogoTimerCounter)
        {
            case _USER_SHOW_LOGO_STEP:
            case (_USER_SHOW_LOGO_STEP * 2):
            case (_USER_SHOW_LOGO_STEP * 3):
            case (_USER_SHOW_LOGO_STEP * 4):
            case (_USER_SHOW_LOGO_STEP * 5):
            case (_USER_SHOW_LOGO_STEP * 6):
            case (_USER_SHOW_LOGO_STEP * 7):

                ScalerOsdSetTransparency_EXINT(0xFF - (g_ucLogoTimerCounter / _USER_SHOW_LOGO_STEP) * 36);

                break;

            default:

                break;
        }
    }
    */
    
}
#pragma restore
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
//--------------------------------------------------
// Description  : Action in Timer1 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer1InstantAccess_EXINT(void)
{
}
#pragma restore
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
//--------------------------------------------------
// Description  : Action in Timer2 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer2InstantAccess_EXINT(void)
{
}
#pragma restore
#endif

#if(_UART_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Action in Serial Port0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUartIntHandler_SERIALPORT(void)
{
    if(GET_UART_RECEIVE_STATUS() == _TRUE)
    {
        g_pucUartData[0] = GET_UART_DATA();

        CLR_UART_RECEIVE_STATUS();
    }
}
#endif

#if(_EXT_INT1_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Action in EXT_INT1 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceEXTINT1Handler_EXINT1(void) using 2
{
    //USER To Do
}
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Status for Int1
// Input Value  : ucDataType --> Data Type in StructSystemData
// Output Value : ucValue --> Value of the Input Data Type
//--------------------------------------------------
BYTE UserInterfaceGetDdcciStatus_EXINT1(void) using 2
{
    return GET_OSD_DDCCI_STATUS();
}

//--------------------------------------------------
// Description  : Get Data from DDCCI Buffer defined by user
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetFactoryCommand_EXINT1(void) using 2
{
    return _FALSE;
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get Source Opcode is HDMI freesync
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void) using 2
{
    if(g_pucDdcciRxBuf[_DDCCI_SOURCE_OPCODE] == _HDMI_FREESYNC_MCCS_VCP)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif // #if(_HDMI_FREESYNC_SUPPORT == _ON)

#endif

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get the HDMI Port Edid location
// Input Value  : EDID Index
// Output Value : External/ Embedded Edid
//--------------------------------------------------
EnumHdmiEdidLocation UserInterfaceGetMultiHdmiEdidLocated(BYTE ucInputport, BYTE ucEdidIndex)
{
    return tEdidMultiLocatedTable[ucInputport][ucEdidIndex];
}

//--------------------------------------------------
// Description  : Get the Mapping of Edid index of Function Application
// Input Value  : ucInputPort
// Output Value : Edid Index Enum
//--------------------------------------------------
EnumEdidSelection UserInterfaceGetMultiHdmiEdidIndex(BYTE ucInputPort)
{
    EnumEdidSelection enumIndex = _EDID_INDEX_0;
    BYTE ucHdmiVer = OsdFuncGetHdmiPortVersion(ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
    if((GET_OSD_FREE_SYNC_STATUS() == _ON))
    {
        enumIndex += ((_HDMI_HDR10_SUPPORT == _ON) ? 0x06 : 0x03);
    }
#endif

#if(_HDMI_HDR10_SUPPORT == _ON)
    if((UserInterfaceHDRGetHDR10ModeStatus(ucInputPort) != _HDR10_MODE_OFF))
    {
        enumIndex += 0x03;
    }
#endif

    switch(ucHdmiVer)
    {
        case _HDMI_1P4:
            break;

        case _HDMI_2P0:
            enumIndex += 0x01;
            break;

        case _HDMI_2P1:
            enumIndex += 0x02;
            break;

        default:
            break;
    }
    return enumIndex;
}
#endif

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Set Embedded EDID Data
// Input Value  : Input Port EDID Select
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetEmbeddedEDIDData(EnumInputPortEdid enumInputPort)
{
    switch(enumInputPort)
    {
        case _A0_INPUT_PORT_EDID:
            break;

#if(_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D0_INPUT_PORT_EDID:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D0, tDP_EDID_TABLE[UserAdjustGetDpEdidIndex(_D0_INPUT_PORT)], _D0_EMBEDDED_DDCRAM_MAX_SIZE);

#elif(_D0_HDMI_SUPPORT == _ON)

#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D0_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D0, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT)], _D0_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D0, tHDMI_EDID_FHD_TABLE, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
#endif

#endif
            break;
#endif // #if(_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D1_INPUT_PORT_EDID:

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            memset(MCU_DDCRAM_D1, 0, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D1, tDP_EDID_TABLE[UserAdjustGetDpEdidIndex(_D1_INPUT_PORT)], _D1_EMBEDDED_DDCRAM_MAX_SIZE);

#elif(_D1_HDMI_SUPPORT == _ON)

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D1_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D1, 0, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D1, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT)], _D1_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D1, 0, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D1, tHDMI_EDID_FHD_TABLE, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
#endif

#endif
            break;
#endif // #if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D2_INPUT_PORT_EDID:

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            memset(MCU_DDCRAM_D2, 0, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D2, tDP_EDID_TABLE[UserAdjustGetDpEdidIndex(_D2_INPUT_PORT)], _D2_EMBEDDED_DDCRAM_MAX_SIZE);

#elif(_D2_HDMI_SUPPORT == _ON)

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D2_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D2, 0, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D2, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT)], _D2_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D2, 0, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D2, tHDMI_EDID_FHD_TABLE, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
#endif

#endif
            break;
#endif // #if(_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D3_INPUT_PORT_EDID:

#if(_D3_HDMI_SUPPORT == _ON)

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D3_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D3, 0, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D3, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT)], _D3_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D3, 0, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D3, tHDMI_EDID_FHD_TABLE, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
#endif

#endif
            break;
#endif // #if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D4_INPUT_PORT_EDID:

#if(_D4_HDMI_SUPPORT == _ON)

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D4_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D4, 0, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D4, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT)], _D4_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D4, 0, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D4, tHDMI_EDID_FHD_TABLE, _D4_EMBEDDED_DDCRAM_MAX_SIZE);

#endif

#endif
            break;
#endif // #if(_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D5_INPUT_PORT_EDID:

#if(_D5_HDMI_SUPPORT == _ON)

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D5_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
            {
                memset(MCU_DDCRAM_D5, 0, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
                memcpy(MCU_DDCRAM_D5, tHDMI_EDID_TABLE[UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT)], _D5_EMBEDDED_DDCRAM_MAX_SIZE);
            }
#else
            memset(MCU_DDCRAM_D5, 0, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D5, tHDMI_EDID_FHD_TABLE, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
#endif

#endif
            break;
#endif // #if(_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

#if(_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D6_INPUT_PORT_EDID:

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)

            memset(MCU_DDCRAM_D6, 0, _D6_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D6, tDP_EDID_TABLE[UserAdjustGetDpEdidIndex(_D6_INPUT_PORT)], _D6_EMBEDDED_DDCRAM_MAX_SIZE);

#endif
            break;
#endif // #if(_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)

        case _D0_INPUT_PORT_MHL_EDID:
            break;

        case _D1_INPUT_PORT_MHL_EDID:
            break;

        case _D2_INPUT_PORT_MHL_EDID:
            break;

        case _D3_INPUT_PORT_MHL_EDID:
            break;

        case _D4_INPUT_PORT_MHL_EDID:
            break;

        case _D5_INPUT_PORT_MHL_EDID:
            break;

        default:
            break;
    }
}
#endif // End of #if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))

#if(_USB3_RETIMER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get USB3 Retimer PD Support Status
// Input Value  : void
// Output Value : EnumUSBPDSupportStatus
//--------------------------------------------------
EnumUSBPDSupportStatus UserInterfaceGetUSBPDSupportStatus(void)
{
    EnumUSBPDSupportStatus enumUSBPDSupportStatus = _USB_PD_DISABLE;

    if(GET_OSD_USB3_RETIMER_PD_WAKEUP() == _TRUE)
    {
        enumUSBPDSupportStatus = _USB3_PD_ENABLE;
    }
    else
    {
        enumUSBPDSupportStatus = _USB_PD_DISABLE;
    }

    return enumUSBPDSupportStatus;
}

//--------------------------------------------------
// Description  : Get USB3 Retimer PS Support Status
// Input Value  : void
// Output Value : EnumUSBPSSupportStatus
//--------------------------------------------------
EnumUSBPSSupportStatus UserInterfaceGetUSBPSSupportStatus(void)
{
    EnumUSBPSSupportStatus enumUSBPSSupportStatus = _USB_PS_DISABLE;

    if(GET_OSD_USB3_RETIMER_PS_WAKEUP() == _TRUE)
    {
        enumUSBPSSupportStatus = _USB3_PS_ENABLE;
    }
    else
    {
        enumUSBPSSupportStatus = _USB_PS_DISABLE;
    }

    return enumUSBPSSupportStatus;
}
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
//--------------------------------------------------
// Description  : Get HDCP Bksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
    ucSubAddr = ucSubAddr;
    ucLength = ucLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Tx HDCP Aksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
    ucSubAddr = ucSubAddr;
    ucLength = ucLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)
#endif // End of #if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)

#if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

#if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- RRMODN
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetDpTxHdcp2RRMODNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- RRMODN
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetDpTxHdcp2DcpLlcNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- RRMODN
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetDpTxHdcp2EKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- RRMODN
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetDpTxHdcp2NPinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
}
#endif // End of #if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
#endif // End of #if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_PANEL_POWER_SEQUENCE_CONTROL_BY_USER == _ON)
//--------------------------------------------------
// Description  : Power Power On/Off Sequence
// Input Value  : ucEvent --> _PANEL_ON
//                            _PANEL_OFF
//                            _BACKLIGHT_ON
//                            _BACKLIGHT_OFF
// Output Value : None
//--------------------------------------------------
void UserInterfacePanelPowerAction(BYTE ucEvent)
{
    ucEvent = ucEvent;
}
#endif

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT1(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_ON_T1);
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT2(void)
{
#if(_PANEL_STYLE == _PANEL_LVDS)

    ScalerTimerDelayXms(_PANEL_POWER_ON_T2);

#elif(_PANEL_STYLE == _PANEL_VBO)

    ScalerDisplayVboPollingHotPlug(_PANEL_POWER_ON_T2);

#elif(_PANEL_STYLE == _PANEL_DPTX)

    ScalerDisplayDPTxPollingHotPlug(_PANEL_POWER_ON_T2);

#endif
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T3
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT3(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_ON_T3);
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT4(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_OFF_T4);
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT5(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_OFF_T5);
}

//--------------------------------------------------
// Description  : Uncall Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUncallFunction(void)
{
    bit bUncall = _FALSE;

    if(bUncall == _TRUE)
    {
        UserInterfaceGetDisplaySettingBacklightAction();

#if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)
        ExternalDeviceInterfaceLedDriverPwm(_DEVICE_LED_DRIVER_PWM_ALL, 0, _DEVICE_CALI_OFF);
#if(_LD_HDR10_BOOST_SUPPORT == _ON)
        ExternalDeviceInterfaceLedDriverPwmArrayBoostMode(0, 100);
#else
        ExternalDeviceInterfaceLedDriverPwmArray(0);
#endif
        ExternalDeviceInterfaceLedDriverPwmEnable(_ENABLE);
        ExternalDeviceInterfaceLedDriverBacklight(0);
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
        // TypeC Connect On, Port Ctrl Off UserInterface Functions
        UserInterfaceTypeCGetOsdU3ModeSelection(_D0_INPUT_PORT);
#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
        UserInterfaceTypeCGetOsdPinAssignmentESupportSelection(_D0_INPUT_PORT);
#endif
#endif

#if(_DP_SUPPORT == _ON)
        UserCommonInterfaceDpGetEdidNativeTimingBw(_NO_PORT_EDID);
#endif

#if(_DVI_SUPPORT == _ON)
        UserCommonInterfaceTmdsGetZ0Status(_D0_INPUT_PORT);
        UserCommonInterfacePowerCheckFakeOff();
        UserCommonInterfaceTmdsHotPlugDdcConfig(_NO_INPUT_PORT, _ENABLE);
        UserCommonInterfaceTmdsHdcpVersionCapabilitySwitch(_NO_INPUT_PORT, _HDCP_BY_PROJECT_DEFINE);

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
        UserInterfaceTmdsAcOnGetHdcpCap();
#endif
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
        UserCommonInterfaceForceUsingDDomainDB();
#endif
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
        UserCommonInterfaceMbrGetCurrentBacklightMode();
#endif

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
        UserAdjustGetDpEdidIndex(_D0_INPUT_PORT);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
        UserInterfaceGetDemoModeType();
#endif

#if(_AUDIO_SUPPORT == _ON)
        SysAudioGetAudioBackupFreq();
        ScalerAudioGetDigitalAudioSource(_NO_INPUT_PORT);
#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_DP_SUPPORT == _ON)
        UserAdjustDpVersionForceUpdate(_NO_INPUT_PORT, _DISABLE, _DP_VERSION_1_0);
#endif

#if(_UART_SUPPORT == _ON)
        ScalerMcuUartWrite(0);
#endif
    }
}

//--------------------------------------------------
// Description  : User Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceInitial(void)
{
    PCB_PWM_SETTING();
    RTDNVRamStartup();

    UserCommonInterfaceDdcciSwitch(GET_OSD_DDCCI_STATUS(), UserCommonNVRamGetSystemData(_SEARCH_PORT));
    RTDKeyInitial();
    SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _OFF)
    // Adjust Backlight
    UserAdjustBacklight(GET_OSD_BACKLIGHT());
#endif

    // Adjust IR Decode
#if(_IR_SUPPORT == _IR_HW_SUPPORT)
    UserAdjusIR();
#endif
    SET_OSD_DOUBLE_SIZE(_OFF);//SET_OSD_DOUBLE_SIZE(GET_OSD_NVRAM_DOUBLE_SIZE());

#if 1//(_FACTORY_MODE_OWNER == _OWNER_TPV)
	TPVDFMInitial();
#endif



#if(_USB3_RETIMER_SUPPORT == _ON)

    // Initilize PSPD USB Function marco
    SET_OSD_USB3_RETIMER_PD_WAKEUP(_TRUE);
    SET_OSD_USB3_RETIMER_PS_WAKEUP(_TRUE);

    // Initilize Hub Input Port
    // If we realize the Hub UFP Switch with OSD Button, we shold set initial value to NVRam
    SET_USER_USB_HUB_UFP_SWITCH(_HUB_UFP_TYPE_C_INPUT_PORT);
    SysTypeCSetCapabilityChangeFlag(_D0_INPUT_PORT, _TYPE_C_HUB_INPUT_SWITCH_CHG);
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    UserCommonInterfaceTmdsSetHdmiZ0HpdType(_HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME, 0, 0);
#endif
}

#if(_DEF_OSD_GAMING == _ON)
extern WORD TIME_COUNT ;
#endif
//--------------------------------------------------
// Description  : User Power Switch
// Input Value  : ucSwitch --> Power Action
// Output Value : None
//--------------------------------------------------
void UserInterfacePowerSwitch(EnumPowerAction enumSwitch)
{
    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif

#if(_DEF_OSD_GAMING == _ON)
			if((SysPowerGetPowerStatus() == _POWER_STATUS_AC_ON)&&(GET_OSD_PRE_GAME_TIME()!=_OFF))   
			{    
				TIME_COUNT = 15*60*GET_OSD_PRE_GAME_TIME();
				if(GET_OSD_PRE_GAME_TIME() == 5)
				{
					TIME_COUNT= 60*90;
				}
			}
#endif
#if(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)||(_PROJECT_ID==_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301) //20250306 lj ����ģʽ�»ָ�����
#if(_VIEWMODE_SUPPORT == _ON)
				if(GET_FACTORY_MODE() == _ON)
				{
					SET_OSD_VIEWMODE_TYPE(_VIEWMODE_DEFAULT);
					UserAdjustViewModeType(GET_OSD_VIEWMODE_TYPE());
                    UserCommonNVRamRestoreSystemData();
                    RTDNVRamRestoreOSDData();
                    RTDNVRamRestoreUserColorSetting();
                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                    RTDNVRamRestoreViewModeParameters(); //��ԭ�龰ģʽ�ṹ��
                    RTDNVRamRestoreBriCon();
                    RTDNVRamRestoreBacklight();
#if(_DEF_VIEW_SONIC_DCR)//UserInterfaceAdjustColorProc
#if(_DCR_SUPPORT)
                    UserAdjustDCRControl(GET_OSD_DCR_STATUS());
#endif	
#endif
                
				}
#endif
#endif
            // Update LED Status
              UserInterfaceKeyPadLedControl(_LED_POWER_ON);
            break;

        case _POWER_ACTION_PS_TO_NORMAL:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif
        #if(_DEF_OSD_GAMING == _ON)
        if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING)&&(GET_OSD_PRE_GAME_TIME()!=_OFF))   
        {    
            TIME_COUNT = 15*60*GET_OSD_PRE_GAME_TIME();
            if(GET_OSD_PRE_GAME_TIME() == 5)
            {
                TIME_COUNT= 60*90;
            }
        }
        #endif

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif
            #if(_DEF_OSD_GAMING == _ON)
            if((SysPowerGetPowerStatus() == _POWER_STATUS_OFF)&&(GET_OSD_PRE_GAME_TIME()!=_OFF))   
            {    
                TIME_COUNT = 15*60*GET_OSD_PRE_GAME_TIME();
                if(GET_OSD_PRE_GAME_TIME() == 5)
                {
                    TIME_COUNT= 60*90;
                }
            }
            #endif

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_ON);

            // Set Monitor Power On Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _ON);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_AC_ON_TO_OFF:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif
               
            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_PS_TO_OFF:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_NORMAL_TO_PS:

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && ((_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON) || (_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)))
#if(_TWO_CHIP_DATA_EXCHANGE_MODE == _DATA_EXCHANGE_MODE_NONE)
            // Port Controller Power Control
            UserAjustTypeCPowerControl(enumSwitch);
#endif
#endif
            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        default:

            break;
    }

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    //ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif
}

//--------------------------------------------------
// Description  : Keypad Led Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed)
{
	DebugMessageOsd("2.ucKeyPadLed",ucKeyPadLed);
/*
	if(GET_POWER_INDICATOR() == _OFF)
	{
		PCB_LED_OFF();
		return ;
	}
		*/
		
    switch(ucKeyPadLed)
    {
        case _LED_POWER_ON:
	     #if 1//(_PROJECT_ID==_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223)  
          if(GET_FACTORY_MODE()) 
          	{
           PCB_LED_POWER_SAVING();
          	}
		  else
		 #endif
		 	{
            PCB_LED_ON();
		 	}
            break;

        case _LED_POWER_ACTIVE:
	
			{
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)
			if(!GET_FACTORY_MODE() && !GET_FACTORY_BURNIN())
				{
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
                 PCB_LED_ACTIVE();
				}
#else

			if(GET_FACTORY_MODE() || GET_FACTORY_BURNIN() || GET_OSD_HOTKEY_BURNIN())
			{   
			   DebugMessageOsd("My_LED",63);
				PCB_LED_POWER_SAVING();
			}
			else
			{
				PCB_LED_ACTIVE();
			}

#endif
			}
            break;

        case _LED_POWER_SEARCH:
			
#if(_DEF_INDICATO_LIGHT_Flick_EANBLE)


			if(GET_FACTORY_MODE() || GET_FACTORY_BURNIN())
				ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
			else
			{
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
				PCB_LED_ACTIVE();

			}
#else
			if(GET_FACTORY_MODE() || GET_FACTORY_BURNIN() || GET_OSD_HOTKEY_BURNIN())
			{
				PCB_LED_POWER_SAVING();
			}
			else
			{
				PCB_LED_ACTIVE();
			}
#endif
            break;

        case _LED_POWER_SAVING:
			
#if (_DEF_INDICATO_LIGHT_Flick_EANBLE)  //tanxiao add
           if(GET_FACTORY_MODE()!=_ON)
		     ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_INDICATO_LIGHT_FACTORY_FLICKER);
#else
            PCB_LED_POWER_SAVING();
#endif
            break;

        case _LED_POWER_NOSUPPORT:
            PCB_LED_ACTIVE();
            break;

        case _LED_POWER_NOSUPPORT_SAVING:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_OFF:
            PCB_LED_OFF();
            break;

        case _LED_ALL_OFF:
            PCB_LED_OFF();
            break;

        case _LED_TYPE_1:
            PCB_LED_TYPE1();
            break;

        case _LED_TYPE_2:
            PCB_LED_TYPE2();
            break;

        case _LED_TYPE_3:
            PCB_LED_TYPE3();
            break;

        case _LED_TYPE_4:
            PCB_LED_TYPE4();
            break;

        case _LED_TYPE_5:
            PCB_LED_TYPE5();
            break;

        case _LED_TYPE_FLASH:
            PCB_LED_TYPE_FLASH();
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : User decide bypass Source Handler
// Input Value  : None
// Output Value : _SOURCE_DETECTION_NORMAL/_SOURCE_DETECTION_BYPASS
//--------------------------------------------------
EnumSourceDetectionInfo UserInterfaceSourceBypassDetection(void)
{
    return _SOURCE_DETECTION_NORMAL;
}

//--------------------------------------------------
// Description  : User OSD Get LogoOn
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetLogoStatus(void)
{
    return (GET_OSD_LOGO_ON());
}

//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserInterfaceGetdNoSupportStatus(void)
{
    // Add User No Support Check
    return _FALSE;
}

//--------------------------------------------------
// Description  : For User to Check Whether to Support Current DCLK
// Input Value  : None
// Output Value : _TRUE => No Support
//--------------------------------------------------
bit UserInterfaceGetDclkNoSupportStatus(void)
{
    if((GET_D_MAX_CLK_FREQ() > ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ)) ||
       (GET_D_MIN_CLK_FREQ() < ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ)))
    {
        DebugMessageScaler("D Clock Exceed Panel Supported Range", GET_D_CLK_FREQ());
        return _TRUE;
    }

#if((_FRC_SUPPORT == _ON) && (_HW_FRC_DOSMODE_ONLY_SUPPORT == _ON))
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _OFF) // Compatible to RL6463
    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        if((GET_INPUT_TIMING_HWIDTH() > 800) ||
           (GET_INPUT_TIMING_VHEIGHT() > 600))
        {
            DebugMessageScaler("FRC only supports dos-mode timing", 0);
            return _TRUE;
        }
    }
#else
    // RL6851 Support IMC, FRC is not limit to DOS-Mode only
#endif
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get whether to by pass normal active process
// Input Value  : None
// Output Value : _TRUE => By pass normal active process
//--------------------------------------------------
bit UserInterfaceGetActiveByPassStatus(void)
{
	if(GET_OSD_STATE() != _MENU_NONE)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : User Define Whether Cable Status Should Reset
// Input Value  : None
// Output Value : _TRUE => Reset
//--------------------------------------------------
bit UserInterfaceGetCableResetStatus(void)
{
    if((SysSourceGetCableStatusChange(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE) &&
       ((!(SysModeGetModeState() == _MODE_STATUS_SEARCH)) || (SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE)))
    {
        SET_FORCE_POW_SAV_STATUS(_FALSE);

        if(SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT)
        {
            SysSourceSwitchInputPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        }

        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Forced Power Saving Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetForcePSStatus(void)
{
    return (GET_FORCE_POW_SAV_STATUS());
}

#if(_SOURCE_CUSTOM_POLLING_REACTIVE_TIME_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get reactive time in polling time
// Input Value  :
// Output Value : polling time
//--------------------------------------------------
WORD UserInterfaceSourceGetPollingReactiveTime(BYTE ucInputPort, BYTE ucPortType)
{
    ucInputPort = ucInputPort;
    ucPortType = ucPortType;

    return SEC(0);
}
#endif

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Force HPD Toggle when Power Saving Wakeup
// Input Value  : None
// Output Value : _USER_FORCE_PS_TMDS_HPD_TOGGLE->User Want to Toggle HPD When Wakeup
//--------------------------------------------------
EnumUserForcePSTmdsHpdToggle UserInterfaceForcePSWakeupTmdsHpdToggle(void)
{
    return _USER_FORCE_PS_TMDS_HPD_NOT_TOGGLE;
}
#endif

#if((_HDMI_2_0_SUPPORT == _ON) && (_HDMI_5V_DETECT_BY_USER == _ON))
//--------------------------------------------------
// Description  : HDMI 5V Detect by user
// Input Value  : enumInputPort
// Output Value : EnumUserHdmi5vStatus
//--------------------------------------------------
EnumUserHdmi5vStatus UserInterfaceTmds5vPinDetect(EnumSourceSearchPort enumInputPort)
{
    enumInputPort = enumInputPort;
    return _HDMI_5V_STATUS_LOW;
}
#endif

#if(_DVI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Decide HDCP Capibility
// Input Value  : None
// Output Value : HDCP Version
//--------------------------------------------------
EnumTmdsHdcpType UserInterfaceTmdsAcOnGetHdcpCap(void)
{
    return _HDCP_BY_PROJECT_DEFINE;
}
#endif

//--------------------------------------------------
// Description  : User Check Into Power Saving
// Input Value  : None
// Output Value : True --> User Check Ready to Power Saving
//--------------------------------------------------
bit UserInterfaceGetIntoPSStatus(void)
{
    if(ScalerOsdGetOsdEnable() == _TRUE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : User Setting Fake Power Saving
// Input Value  : None
// Output Value : _USER_FORCE_FAKE_PS --> User Set Power Status into Fake Power Saving
//                _USER_FORCE_POWER_SAVING    --> User Set Power Status into Power saving
//--------------------------------------------------
EnumUserForceFakePS UserInterfaceGetFakePSStatus(void)
{
    return _USER_FORCE_POWER_SAVING;
}

//--------------------------------------------------
// Description  : User Setting Fake Power Status
// Input Value  : None
// Output Value : _USER_FORCE_FAKE_POWER_OFF ==> Fake Power Off
//                _USER_FORCE_POWER_OFF ==> Power off
//--------------------------------------------------
EnumUserForceFakePowerOff UserInterfaceGetFakePowerOffStatus(void)
{
    return _USER_FORCE_POWER_OFF;
}

//--------------------------------------------------
// Description  : Check Whther ADC Data is Reasonable
// Input Value  : LOAD or SAVE
// Output Value : _TRUE => Reasonable
//--------------------------------------------------
bit UserInterfaceGetNVRamDataStatus(EnumNvramCheckType enumNvramCheckType)
{
    switch(enumNvramCheckType)
    {
#if(_VGA_SUPPORT == _ON)
        case _CHECK_ADC_LOAD:

            if(g_stAdcData.ucAdcPGA >= 0xF0)
            {
                // Assign Prefered Value
                g_stAdcData.ucAdcPGA = 8;
            }

            break;

        case _CHECK_ADC_SAVE:

            if(g_stAdcData.ucAdcPGA >= 0xF0)
            {
                return _FAIL;
            }
            break;
#endif

        case _CHECK_SYSTEM_DATA_LOAD:
        case _CHECK_SYSTEM_DATA_SAVE:
        case _CHECK_MODE_USER_DATA_LOAD:
        case _CHECK_MODE_USER_DATA_SAVE:

            break;

#if(_DEF_VGA_TIMING_KEY_2_4)
		//Duncan 130422 add start
        case _CHECK_OSD_DATA_RANGE:
			if((GET_Mode400at70_Switch() > _Max_400_70) || (GET_Mode400at70_Switch() < 0))
			{
				SET_Mode400at70_Switch(0);
			}

			if((GET_Mode480at60_Switch() > _Max_480_60) || (GET_Mode480at60_Switch() < 0))
			{
				SET_Mode480at60_Switch(0);
			}
            break;

#endif
        default:
            break;
    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Get backlight staus when performing display setting
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit UserInterfaceGetDisplaySettingBacklightAction(void)
{
#if((_PANEL_STYLE == _PANEL_DPTX) ||\
    (_PANEL_STYLE == _PANEL_VBO))

    return _DISABLE;

#else

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    if((GET_ROT_TYPE() != UserInterfaceGetRotationDegree()) ||
       (GET_ROT_DISP_SIZE() != UserInterfaceGetRotationDisplayType()))
    {
        return _DISABLE;
    }
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    if(GET_ROT_TYPE() != _ROT_DISABLE)
#endif
    {
        if(GET_DISP_LATENCY_RATIO() != UserInterfaceGetDisplayLatencyRatio())
        {
            return _DISABLE;
        }
    }
#endif

    return _ENABLE;

#endif
}

//--------------------------------------------------
// Description  : Get OSD Color Format
// Input Value  : None
// Output Value : Color Format
//--------------------------------------------------
EnumColorSpace UserInterfaceGetColorFormat(void)
{
    EnumColorSpace enumColorSpace = OsdDisplayGetColorSpaceType();
	
#if 1

	switch(enumColorSpace)
	{
		case _SPACE_AUTO :
			SET_OSD_COLOR_FORMAT(ScalerColorGetColorSpace());
			break;
		case _SPACE_RGB:
			
			SET_OSD_COLOR_FORMAT(_COLOR_SPACE_RGB);
			//if(ScalerColorGetColorSpaceRGB(enumColorSpace) == _TRUE)
				//SET_OSD_COLOR_FORMAT(_COLOR_SPACE_RGB);
			//else
				//SET_OSD_COLOR_FORMAT(_COLOR_SPACE_YPBPR);
			break;
			
		case _SPACE_YUV:
			SET_OSD_COLOR_FORMAT(_COLOR_SPACE_YCBCR422);
			break;
		default:
			break;
	}
	//DebugMessageOsd("1.GET_OSD_COLOR_FORMAT",GET_OSD_COLOR_FORMAT());
	//DebugMessageOsd("1.OsdDisplayGetColorRangeType",OsdDisplayGetColorRangeType());

	switch(OsdDisplayGetColorRangeType())
	{
		case _RANGE_AUTO:
			if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
			{

#if(_RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER == _ON)
				if(UserInterfaceGetRGBQuantizationLimitRangeStatus(ScalerColorGetRGBQuantizationRange()) == _TRUE)
#else
				if(UserCommonInterfaceGetRGBQuantizationLimitRangeStatus(ScalerColorGetRGBQuantizationRange()) == _TRUE)
#endif
				{
					ScalerColorSetRGBLimitRange(_ENABLE);
				}
				else
				{
					ScalerColorSetRGBLimitRange(_DISABLE);
				}
			}
			else
			{
				if(UserInterfaceGetYCCQuantizationFullRangeStatus(ScalerColorGetYCCQuantizationRange()) == _TRUE)
				{
					ScalerColorSetYCCFullRange(_ENABLE);
				}
				else
				{
					ScalerColorSetYCCFullRange(_DISABLE);
				}
			}
			break;

		case _RANGE_FULL:
			if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
			{
				ScalerColorSetRGBLimitRange(_DISABLE);
			}
			else
			{
				ScalerColorSetYCCFullRange(_ENABLE);
			}
			break;

		case _RANGE_LIMITED:
			if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
			{
				ScalerColorSetRGBLimitRange(_ENABLE);
			}
			else
			{
				ScalerColorSetYCCFullRange(_DISABLE);
			}
			break;

		default:break;
	}

	
	return GET_OSD_COLOR_FORMAT();
	
#else	

#if(_COLOR_FORMAT_CONVERT == _ON)
    switch(SysSourceGetSourceType())
    {
        case _SOURCE_VGA:
        case _SOURCE_DVI:
            enumColorSpace = GET_OSD_COLOR_FORMAT();
            break;

        default:
            break;
    }
#endif

    if(ScalerColorGetColorSpaceRGB(enumColorSpace) == _TRUE)
    {
        return _COLOR_SPACE_RGB;
    }
    else
    {
        return _COLOR_SPACE_YPBPR;
    }
    
#endif

}

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HP Source Switch Event Time
// Input Value  : Source Scan Type
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetHpSourceSwitchOsdEventTime(BYTE ucSourceScanType)
{
    ucSourceScanType = ucSourceScanType;
    return 0;
}
#endif

#if(_OVERSCAN_SUPPORT == _ON)


extern bit UserAdjustGetOverScanStatus(void);

//--------------------------------------------------
// Description  : Check OOR for timing After Overscan
// Input Value  :
// Output Value : _TURE => OOR
//--------------------------------------------------
bit UserAdjustCheckOverScanOOR(void)
{
	BYTE ucDelta = 0;

	if(g_bOverScanFlag == _FALSE)
	{
		ucDelta = (BYTE)((DWORD)GET_MDOMAIN_INPUT_VHEIGHT() * _OVERSCAN_V_RATIO / 1000);
	}

	PDATA_DWORD(0) = (DWORD)((DWORD)(GET_MDOMAIN_OUTPUT_HTOTAL()) * (DWORD)(GET_MDOMAIN_OUTPUT_VHEIGHT())/10) *(DWORD)(GET_MDOMAIN_INPUT_HFREQ())/ (GET_MDOMAIN_INPUT_VHEIGHT() - (2*ucDelta));
	if(PDATA_DWORD(0) > ((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000))
	{
		return _TRUE;
	}
	return _FALSE;
}

//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
bit UserInterfaceGetOverScanStatus(void)
{
    bit bDoOverScan = _FALSE;

	bDoOverScan = UserAdjustGetOverScanStatus();
	
	if(bDoOverScan == _TRUE)
	{
		if(UserAdjustCheckOverScanOOR() == _TRUE)
		{
			bDoOverScan = _FALSE;
		}
	}

	g_bOverScanFlag = bDoOverScan;

	return bDoOverScan;

/*
	
    BYTE ucTemp = 0;
    WORD code tusOverscanEnTable[][3] =
    {
        // VFreq, HWidth, VHeight,
        {600,  640,  480},    // 480p
        {600,  720,  480},    // 480p
        {600,  960,  480},    // 480p
        {600, 1440,  480},    // 480p

        {500,  720,  576},    // 576p
        {500,  768,  576},    // 576p
        {500,  960,  576},    // 576p
        {500, 1280,  576},    // 576p
        {500, 1440,  576},    // 576p
        {500, 1280,  720},    // 720p
        {600, 1280,  720},    // 720p
        {500, 1920,  1080},   // 1080p
        {600, 1920,  1080},   // 1080p

        // Don't delete it, and place it at last.
        {  0,    0,    0},
    };

    if(GET_OSD_OVERSCAN_STATUS() == _OFF)
    {
        return _FALSE;
    }

    // Decide whether to do over scan
    switch(SysSourceGetSourceType())
    {
#if(_OVERSCAN_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(GET_VGA_COLOR_FORMAT_STATUS() == _COLOR_SPACE_RGB)
            {
                break;
            }

            while(tusOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tusOverscanEnTable[ucTemp][0]) < 10) &&
                   (abs(GET_INPUT_TIMING_HWIDTH() - tusOverscanEnTable[ucTemp][1]) < 2) &&
                   (GET_INPUT_TIMING_VHEIGHT() == tusOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif // End of #if(_OVERSCAN_VGA_SUPPORT == _ON)

#if(_OVERSCAN_DVI_SUPPORT != _ON)
        case _SOURCE_DVI:
            break;
#endif

#if(_OVERSCAN_HDMI_SUPPORT != _ON)
        case _SOURCE_HDMI:
            break;
#endif

#if(_OVERSCAN_DP_SUPPORT != _ON)
        case _SOURCE_DP:
            break;
#endif

        default:
#if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(ScalerColorGetColorSpaceRGB(ScalerColorGetColorSpace()) == _TRUE)
            {
                break;
            }

            while(tusOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tusOverscanEnTable[ucTemp][0]) < 10) &&
                   (abs(GET_INPUT_TIMING_HWIDTH() - tusOverscanEnTable[ucTemp][1]) < 2) &&
                   (GET_INPUT_TIMING_VHEIGHT() == tusOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }
#endif // End of #if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
            break;
    }

    return bDoOverScan;

    */
}
#endif // End of #if(_OVERSCAN_SUPPORT == _ON)

#if(_ASPECT_RATIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Aspect Ratio
// Input Value  : None
// Output Value : aspect ration type
//--------------------------------------------------
EnumAspectRatioType UserInterfaceGetAspectRatioType(void)
{
    switch(GET_OSD_ASPECT_RATIO_TYPE())
    {
        case _OSD_ASPECT_RATIO_16_BY_9:
		case _OSD_ASPECT_RATIO_16_BY_10:
        case _OSD_ASPECT_RATIO_4_BY_3:
        case _OSD_ASPECT_RATIO_5_BY_4:

            return _ASPECT_RATIO_FIXED;

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        case _OSD_ASPECT_RATIO_ORIGIN:

            return _ASPECT_RATIO_ORIGIN;
        case _OSD_ASPECT_RATIO_USER:
            return _ASPECT_RATIO_ORIGIN;
#endif

        default:
        case _OSD_ASPECT_RATIO_FULL:

            return _ASPECT_RATIO_FULL;
    }
}

//--------------------------------------------------
// Description  : Get user H/V aspect ratio values
// Input Value  : enumSelRegion --> select region
//                usHRatio, usVRatio --> aspect ratio
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetAspectRatio(WORD *pusHRatio, WORD *pusVRatio)
{
    switch(GET_OSD_ASPECT_RATIO_TYPE())
    {

		case _OSD_ASPECT_RATIO_16_BY_10:
			*pusHRatio = 16;
			*pusVRatio = 10;
			break;

        case _OSD_ASPECT_RATIO_16_BY_9:
            *pusHRatio = 16;
            *pusVRatio = 9;
            break;

        case _OSD_ASPECT_RATIO_4_BY_3:
            *pusHRatio = 4;
            *pusVRatio = 3;
            break;

        case _OSD_ASPECT_RATIO_5_BY_4:
            *pusHRatio = 5;
            *pusVRatio = 4;
            break;

		default:            
			*pusHRatio = 16;
            *pusVRatio = 9;
            break;
    }
}

//--------------------------------------------------
// Description  : User defined aspect ratio process
// Input Value  : select region
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAspectRatio(void)
{
}

#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
//--------------------------------------------------
// Description  : User defined minimum dvheight for aspect ratio
//                use 1:1 for example
// Input Value  : None
// Output Value : usMinDvheight
//--------------------------------------------------
WORD UserInterfaceGetAspectRatioMinDVHeight(void)
{
    WORD usMinDvheight = (GET_INPUT_TIMING_VHEIGHT() < GET_MDOMAIN_OUTPUT_VHEIGHT()) ? GET_INPUT_TIMING_VHEIGHT() : GET_MDOMAIN_OUTPUT_VHEIGHT();
    // return 0 if disable the function
    return usMinDvheight;
}
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get aspect original mode ratio
// Input Value  : select region
// Output Value : Retion display ratio in aspect ratio original mode (0x00 ~ 0xFF)
//--------------------------------------------------
BYTE UserInterfaceGetAspectRatioOriginalRatio(void)
{
    return 0xFF;
}

//--------------------------------------------------
// Description  : Get reduced aspect ratio in original mode
// Input Value  : select region
// Output Value : Retion display ratio in aspect ratio original mode (0x00 ~ 0xFF)
//--------------------------------------------------
BYTE UserInterfaceGetAspectRatioOriginalRatioSmall(void)
{
    if(GET_OSD_ASPECT_RATIO_TYPE() == _OSD_ASPECT_RATIO_USER)
    {
        return 0xCC;
    }
    else
    {
        return 0xFF;
    }
}
#endif
#endif // End of #if(_ASPECT_RATIO_SUPPORT == _ON)

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get current rotation degree
// Input Value  : None
// Output Value : rotation degree
//--------------------------------------------------
EnumRotationType UserInterfaceGetRotationDegree(void)
{
    switch(GET_OSD_DISP_ROTATE())
    {
        default:
        case _DISP_ROTATE_0:
            return _ROT_DISABLE;

#if (_DISPLAY_ROTATION_90_SUPPORT == _ON)
        case _DISP_ROTATE_90:
            return _ROT_CW90;
#endif
#if (_DISPLAY_ROTATION_180_SUPPORT == _ON)
        case _DISP_ROTATE_180:
            return _ROT_CW180;
#endif
#if (_DISPLAY_ROTATION_270_SUPPORT == _ON)
        case _DISP_ROTATE_270:
            return _ROT_CW270;
#endif
#if (_DISPLAY_HOR_MIRROR_SUPPORT == _ON)
        case _DISP_ROTATE_HOR_MIRROR:
            return _ROT_HOR_MIRROR;
#endif
#if (_DISPLAY_VER_MIRROR_SUPPORT == _ON)
        case _DISP_ROTATE_VER_MIRROR:
            return _ROT_VER_MIRROR;
#endif
    }
}

//--------------------------------------------------
// Description  : Get current rotation type
// Input Value  : None
// Output Value : rotation type
//--------------------------------------------------
EnumRotationDisplayType UserInterfaceGetRotationDisplayType(void)
{
    switch(GET_OSD_DISP_ROTATION_SIZE_TYPE())
    {
        default:
        case _OSD_ROTATE_DISPLAY_FULL:
            return _ROT_FULL;

        case _OSD_ROTATE_DISPLAY_PIXEL_BY_PIXEL:
            return _ROT_PIXEL_BY_PIXEL;

        case _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO:
            return _ROT_KEEP_SRC_ASPECT_RATIO;
    }
}
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Display Latency Ratio
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetDisplayLatencyRatio(void)
{
    switch(GET_OSD_LATENCY())
    {
        default:
            break;

        case _LATENCY_L:
            return 0;   // 0%
#if(_LATENCY_3_LEVEL_SUPPORT == _ON)
        case _LATENCY_M:
            return 50;  // 50%
#endif
        case _LATENCY_H:
            return 100; // 100%
    }

    return 0;
}
#endif

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Max/Min Freq according to latency
// Input Value  : None
// Output Value : max/min freq
//--------------------------------------------------
void UserInterfaceGetDVMaxMinFreq(StructDVCustomizedFreq *pstDVCustomizedFreq)
{
    pstDVCustomizedFreq = pstDVCustomizedFreq;

#if(_MN_FINE_TUNE_LASTLINE_SUPPORT == _ON)
    if((SysSourceGetInputPort() == _A0_INPUT_PORT) ||
       (GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE))
    {
        pstDVCustomizedFreq->b1FORCETOFREERUN = _ENABLE;
    }
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
    switch (GET_OSD_LATENCY())
    {
        default:
        case _LATENCY_H:
        case _LATENCY_M:
        case _LATENCY_L:

            pstDVCustomizedFreq->usMaxFreq = _PANEL_MAX_FRAME_RATE;
            pstDVCustomizedFreq->usTypFreq = _PANEL_TYP_FRAME_RATE;
            pstDVCustomizedFreq->usMinFreq = _PANEL_MIN_FRAME_RATE;
            break;
    }
#endif
}
#endif

//--------------------------------------------------
// Description  : Adjust Main Memory Data Bit, including line buffer and frame buffer
// Input Value  : pstCustomizedMdomain
// Output Value : None
//--------------------------------------------------
void UserInterfaceDisplaySelectMDomainSettingForMain(StructCustomizedMdomain *pstCustomizedMdomain)
{
    pstCustomizedMdomain->enumMemoryBitSelect = _MEMORY_REF_SOURCE_BIT;
}

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OD enable status
// Input Value  : None
// Output Value : function enable status
//--------------------------------------------------
EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void)
{
    return GET_OSD_OD_STATUS();
}
#endif

#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && (_DDR3_MULTIPHASE_EXIST == _ON))
//--------------------------------------------------
// Description  : Get DDR3 Phase From GPIO or DDCCI command
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUpdateDDR3PhaseData(void)
{
    StructDDR3PhaseInfo stUserVedorDdr3PhaseData = {_DDR3_PLL_INITIAL_PHASE_0, _DDR3_PLL_INITIAL_PHASE_1, _DDR3_READ_DQ_DLYN_TAP};
    ScalerPLLGetDDR3PhaseData(&stUserVedorDdr3PhaseData);
}
#endif

#if(_USER_SYSTEM_EEPROM_CUSTOMIZATION == _ON)
//--------------------------------------------------
// Description  : User Custom Check Proc when System Eeprom Read
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserInterfaceSystemEepromReadCustomProc(DWORD ulSubAddr, WORD usLength, BYTE *pucReadArray)
{
    ulSubAddr = ulSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
    return _SUCCESS;
}

//--------------------------------------------------
// Description  : User Custom Check Proc when System Eeprom Write
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to write
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserInterfaceSystemEepromWriteCustomProc(DWORD ulSubAddr, WORD usLength, BYTE *pucWriteArray)
{
    ulSubAddr = ulSubAddr;
    usLength = usLength;
    pucWriteArray = pucWriteArray;
    return _SUCCESS;
}
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust backlight setting
// Input Value  : Backlight Mode, Backlight On/Off
// Output Value : None
//--------------------------------------------------
void UserInterfaceMbrBacklightAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl, WORD usDVTotal)
{
    BYTE ucBacklightDuty = 0; // Backlight ON percentage
    BYTE ucBacklightPos = 0; // Backlight Position percentage
    WORD usStrobeVWidth = 0; // Backlight ON lines
    WORD usStrobeVPos = 0; // Backlight ON Position (lines)

    DebugMessageScaler("MBR: bLightCtrl", bLightCtrl);
    DebugMessageScaler("MBR: VTotal", usDVTotal);
    DebugMessageScaler("MBR: ucBacklightDuty", GET_OSD_MBR_DUTY());
    DebugMessageScaler("MBR: ucBacklightPos", GET_OSD_MBR_POSITION());

    switch(enumBacklightMode)
    {
        //=================================================================
        // User customized motion blur reduction mode
        //=================================================================
        case _BACKLIGHT_MODE_STROBE_USER_CUSTOMIZE_MBR:
            /*
             Strobe Backlight Position
               _____       ________________________     _____
              |     |     |                        |   |     |
              |VSync|_____|         Duty           |___|VSync|___
                         Pos                   Pos + Duty

               _____                        ________________________
              |     |                      |                        |
              |VSync|______________________|         Duty           |___
                                          Pos                  Pos + Duty
            */

            if(bLightCtrl == _LIGHT_CONTROL_ON)
            {
                // Backlight strobe ctrl (Tcon local enable...)
                ucBacklightDuty = GET_OSD_MBR_DUTY();
                ucBacklightPos = GET_OSD_MBR_POSITION();
                usStrobeVPos = (WORD)((DWORD)ucBacklightPos * usDVTotal / 100L);
                usStrobeVWidth = (WORD)((DWORD)ucBacklightDuty * usDVTotal / 100L);
                if(ucBacklightDuty == 100)
                {
                    ScalerTconAdjustByIndex(_PCB_MBR_TCON_PIN, 0x0000, 0x1FFF, 0x0000, 0x3FFF);
                }
                else
                {
                    ScalerTconAdjustByIndex(_PCB_MBR_TCON_PIN, 0x0000, 0x1FFF, usStrobeVPos, (usStrobeVPos + usStrobeVWidth) % usDVTotal);
                }
                ScalerTconEnableByIndex(_PCB_MBR_TCON_PIN, _ENABLE);
            }
            else
            {
                // Setting in _LIGHT_CONTROL_OFF case
                ScalerTconEnableByIndex(_PCB_MBR_TCON_PIN, _DISABLE);
            }
            break;

        //=================================================================
        // Constant backlight mode
        //=================================================================
        default:
        case _BACKLIGHT_MODE_CONSTANT:
            if(bLightCtrl == _LIGHT_CONTROL_ON)
            {
                // Backlight Ctrl
                // Set TCON to always ON and/or disable strobe ctrl pins...
                ScalerTconAdjustByIndex(_PCB_MBR_TCON_PIN, 0x0000, 0x1FFF, 0x0000, 0x3FFF);

                ScalerTconEnableByIndex(_PCB_MBR_TCON_PIN, _ENABLE);
            }
            else
            {
                // Setting in _LIGHT_CONTROL_OFF case
                ScalerTconEnableByIndex(_PCB_MBR_TCON_PIN, _DISABLE);
            }
            break;
    }
}

//--------------------------------------------------
// Description  : Adjust Backlight ADIM (normally controled by scaler PWM)
// Input Value  : Current backlight mode and backlight on/off status
// Output Value : None
//--------------------------------------------------
void UserInterfaceMbrAdimAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl)
{
    if(bLightCtrl == _LIGHT_CONTROL_ON)
    {
        switch(enumBacklightMode)
        {
            // In strobe backlight case, set scaler PWM to full duty
            case _BACKLIGHT_MODE_STROBE_USER_CUSTOMIZE_MBR:
            case _BACKLIGHT_MODE_STROBE_DRR_MBR:
            case _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR:
                PCB_PWM_SETTING();
                PCB_BACKLIGHT_PWM(0xFF);
                break;

            // In constant backlight case, set scaler PWM according to user setting
            case _BACKLIGHT_MODE_CONSTANT:
            default:
                PCB_PWM_SETTING();
                UserAdjustBacklight(GET_OSD_BACKLIGHT());
                break;
        }
    }
    else
    {
        PCB_BACKLIGHT_PWM(0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust Backlight PDIM
// Input Value  : Current backlight mode and backlight on/off status
// Output Value : None
//--------------------------------------------------
void UserInterfaceMbrPdimAdjust(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl)
{
    enumBacklightMode = enumBacklightMode;
    bLightCtrl = bLightCtrl;

    // User can modify PDIM control setting here
    // e.g.
    // when using AS3824, MBR P-dimming setting may not required to be controled by TCON in Constant Mode
    // User can place additional setting here(switch Pinshare, Send I2C Command to driver...etc.)
    // ---
    // For TCON enable setting, kernel set accrording to the result of UserInterfaceDisplayMbrGetPdimControl()
}

//--------------------------------------------------
// Description  : Get backlight PDIM control method
// Input Value  : Current backlight mode and backlight on/off status
// Output Value : PDIM control method
//--------------------------------------------------
EnumMbrPDimCtrl UserInterfaceMbrGetPdimControl(EnumMbrBacklightMode enumBacklightMode, bit bLightCtrl)
{
    enumBacklightMode = enumBacklightMode;
    bLightCtrl = bLightCtrl;

    // User can specify PDIM control method here
    // e.g.
    // when using AS3824, MBR P-dimming setting may not required to be controled by TCON in Constant Mode
    // User can return _BACKLIGHT_PDIM_CTRL_BY_USER and place additional setting in UserInterfaceDisplayMbrPdimAdjust()
    // ---
    // _BACKLIGHT_PDIM_CTRL_BY_TCON => kernel WILL enable/disable TCON at current status
    // _BACKLIGHT_PDIM_CTRL_BY_USER => kernel WILL NOT enable/disable TCON at current status

    return _BACKLIGHT_PDIM_CTRL_BY_TCON;
}

//--------------------------------------------------
// Description  : Judge MBR Backlight Mode
// Input Value  : None
// Output Value : Backlight Mode
//--------------------------------------------------
EnumMbrBacklightMode UserInterfaceMbrGetBacklightMode(void)
{
    if(GET_OSD_MBR_STATUS() == _OSD_MBR_USER_DISABLE) // Constant backlight
    {
        return _BACKLIGHT_MODE_CONSTANT;
    }
    else if(GET_OSD_MBR_STATUS() == _OSD_MBR_USER_ENABLE) // User want to control backlight
    {
        return _BACKLIGHT_MODE_STROBE_USER_CUSTOMIZE_MBR;
    }
    else if(GET_OSD_MBR_STATUS() == _OSD_RTK_ADV_MBR_USER_ENABLE)
    {
#if((_FREESYNC_SUPPORT == _ON) && (_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
        if((ScalerSyncGetFREESYNCEnable() == _TRUE) && (UserCommonInterfaceMbrDrrGetHWSupport() == _TRUE))
        {
            return _BACKLIGHT_MODE_STROBE_DRR_MBR;
        }
#endif
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
        if(ScalerMbrGetAdvMbrStatus() == _ENABLE)
        {
            return _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR;
        }
#endif
        return _BACKLIGHT_MODE_CONSTANT;
    }

    return _BACKLIGHT_MODE_CONSTANT;
}

#if((_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON) || (_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get User MBR Backlight Duty
// Input Value  : None
// Output Value : Backlight Duty
//--------------------------------------------------
BYTE UserInterfaceMbrGetBacklightDuty(void)
{
    return (BYTE)GET_OSD_MBR_DUTY();
}

//--------------------------------------------------
// Description  : Get User MBR Backlight Position
// Input Value  : None
// Output Value : Backlight Position
//--------------------------------------------------
BYTE UserInterfaceMbrGetBacklightPos(void)
{
    return (BYTE)GET_OSD_MBR_POSITION();
}
#endif

//--------------------------------------------------
// Description  : Get backlight off PDIM/ADIM sequence
// Input Value  : None
// Output Value : Backlight adjust sequence
//--------------------------------------------------
EnumMbrBacklightSeq UserInterfaceMbrGetBacklightSequence(bit bLightCtrl)
{
    if(bLightCtrl == _LIGHT_CONTROL_ON)
    {
        if(UserCommonInterfaceMbrGetCurrentBacklightMode() == _BACKLIGHT_MODE_CONSTANT)
        {
            return _BACKLIGHT_SEQ_ADIM_PDIM;
        }
        else
        {
            return _BACKLIGHT_SEQ_PDIM_ADIM;
        }
    }
    else
    {
        return _BACKLIGHT_SEQ_PDIM_ADIM;
    }
}

//--------------------------------------------------
// Description  : Get backlight off PDIM/ADIM delay
// Input Value  : None
// Output Value : xx ms delay between PDIM/ADIM
//--------------------------------------------------
WORD UserInterfaceMbrGetBacklightSequenceDelay(bit bLightCtrl)
{
    if(bLightCtrl == _LIGHT_CONTROL_ON)
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Motion Blur Reduction Function
//                Accroding to User Selection
// Input Value  : None
// Output Value : _RTK_ADV_MBR_USER_DISABLE/_RTK_ADV_MBR_USER_ENABLE
//--------------------------------------------------
EnumRtkAdvMbrUserStatus UserInterfaceGetRtkAdvMbrSetting(void)
{
    if((GET_OSD_MBR_STATUS() == _OSD_RTK_ADV_MBR_USER_ENABLE) && (GET_INPUT_TIMING_VFREQ() >= _RTK_ADV_MBR_MIN_ENABLE_IVF))
    {
        return _RTK_ADV_MBR_USER_ENABLE;
    }

    return _RTK_ADV_MBR_USER_DISABLE;
}
#endif // End of #if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
#endif // End of #if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get extended wait time to active state from user
// Input Value  : None
// Output Value : Extended wait time (ms)
//--------------------------------------------------
WORD UserInterfaceDisplayGetExtendedActiveWaitTime(void)
{
    return 0;
}

//--------------------------------------------------
// Description  : Modify display Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceDisplayInitialization(void)
{
}

//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustInputTiming(void)
{
}

#if(_UNDERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceAdjustUnderScan(void)
{
    if((GET_INPUT_TIMING_HWIDTH() == 640) && (GET_INPUT_TIMING_VHEIGHT() == 350))
    {
#if(_FREESYNC_SUPPORT == _ON)
        if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
        {
            SET_UNDERSCAN_VHEIGHT(400);
            return _TRUE;
        }
    }

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Modify Display Timing Based on User Requirement
// Input Value  : Current Display Timing Info
// Output Value : Modified Display Timing
//--------------------------------------------------
void UserInterfaceAdjustDisplayTiming(void)
{
#if(_PANEL_STYLE == _PANEL_LVDS)
    // Check display format resolution according to LVDS port count
    SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() + (GET_MDOMAIN_OUTPUT_HSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_OUTPUT_HWIDTH() - (GET_MDOMAIN_OUTPUT_HWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBSTART(GET_MDOMAIN_OUTPUT_HBSTART() + (GET_MDOMAIN_OUTPUT_HBSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBWIDTH(GET_MDOMAIN_OUTPUT_HBWIDTH() - (GET_MDOMAIN_OUTPUT_HBWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
#endif
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) && (_RGB_QUANTIZATION_DEFAULT_RANGE_JUDGE_BY_USER == _ON))
//--------------------------------------------------
// Description  : User Judge if Quantization Range is Full or Limited
// Input Value  : EnumDisplayRegion --> display region
//                ucQuanRange --> quantization status
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization)
{
#if((_HDR10_SUPPORT == _ON)&&((_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2756_2K_PRO_2_20250115)||(_PROJECT_ID ==_ID_ZQ_2775E15_BOE_ME270QHB_NF2_8BIT_QHD180_VX2756_2K_PRO_2_20250224) \
	||(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_20241223)||(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_D8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250103)||(_PROJECT_ID ==_ID_ZQ_2775E15_INNOLUX_MV270KCA_E8B_8BIT_QHD180_VX2758A_2K_PRO_2_20250228))) //add HDR 1.a Brightness
    if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
    {
        switch(enumColorRGBQuantization)
        {
            case _RGB_QUANTIZATION_FULL_RANGE:
            case _RGB_QUANTIZATION_DEFAULT_RANGE:
            case _RGB_QUANTIZATION_RESERVED:
            case _RGB_QUANTIZATION_LIMIT_RANGE:

                return _TRUE;
        }
    }
    else
#endif
    {
        switch(enumColorRGBQuantization)
        {
            case _RGB_QUANTIZATION_FULL_RANGE:
            case _RGB_QUANTIZATION_DEFAULT_RANGE:
            case _RGB_QUANTIZATION_RESERVED:
            default:

                return _FALSE;

            case _RGB_QUANTIZATION_LIMIT_RANGE:

                return _TRUE;
        }
    }
}
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if YCC Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetYCCQuantizationFullRangeStatus(EnumColorYCCQuantization enumColorYCCQuantization)
{
    switch(enumColorYCCQuantization)
    {
        case _YCC_QUANTIZATION_FULL_RANGE:
        case _YCC_QUANTIZATION_RESERVED:
        default:

            return _TRUE;

        case _YCC_QUANTIZATION_LIMIT_RANGE:

            return _FALSE;
    }
}
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check whether Demo mode is on or not
// Input Value  : None
// Output Value : ON or OFF
//--------------------------------------------------
EnumFunctionOnOFF UserInterfaceGetDemoModeType(void)
{
    if(GET_OSD_HLWIN_TYPE() != _HL_WIN_OFF)
    {
        return _FUNCTION_ON;
    }
    else
    {
        return _FUNCTION_OFF;
    }
}
#endif

//--------------------------------------------------
// Description  : Set Color in pass normal active process
// Input Value  : None
// Output Value : void
//--------------------------------------------------
void UserInterfaceAdjustActiveByPassColorProc(void)
{
    return;
}

//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustColorProc(void)
{
	#if(_HDR10_SUPPORT == _ON)
       if((GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)&&(g_stHDR10SaticMetadata.ucEOTF !=0)&&(OsdDisplayGetColorSpaceType() != _SPACE_AUTO))
		{
			switch(SysSourceGetInputPort())
			{
				#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
				case _D0_INPUT_PORT:
					SET_OSD_D0_COLORSPACE_TYPE(_SPACE_AUTO);
					break;
				#endif

				#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
				case _D1_INPUT_PORT:
					SET_OSD_D1_COLORSPACE_TYPE(_SPACE_AUTO);
					break;
				#endif

				#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
				case _D2_INPUT_PORT:
					SET_OSD_D2_COLORSPACE_TYPE(_SPACE_AUTO);
					break;
				#endif

				#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
				case _D3_INPUT_PORT:
					SET_OSD_D3_COLORSPACE_TYPE(_SPACE_AUTO);
					break;
				#endif

				default:
		          	break;
		    }	
			RTDNVRamSaveOSDData();
		}
	#endif

	UserInterfaceColorFormatConvert();

#if(_BLUE_LIGHT_FILTER_SUPPORT == _ON)
		RTDNVRamLoadColorSetting(_CT_4500);
		g_uc4500KColorTempR = g_stColorProcData.usColorTempR;
		g_uc4500KColorTempG = g_stColorProcData.usColorTempG;
		g_uc4500KColorTempB = g_stColorProcData.usColorTempB;
#endif

    RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE());
	RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

	

#if(_DCR_SUPPORT == _ON)
	if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
	SET_DCR_ADJUST_VALUE(GET_OSD_BACKLIGHT());
#endif


    // Adjust UltraVivid
#if(_ULTRA_VIVID_SUPPORT == _ON)
    //UserInterfaceAdjustUltraVividProc(_DB_APPLY_NO_POLLING);
    //UserAdjustUltraVivid();
    
#if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_DEF_VIEWMODE_MAC)
	if((GET_OSD_DCR_STATUS() == _OFF) && (GET_OSD_VIEWMODE_TYPE() != _VM_MAC))
#else
	if((GET_OSD_DCR_STATUS() == _OFF) )
#endif
    {
        UserCommonAdjustUltraVivid(_FUNCTION_OFF, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
    }
    else
    {
#if(_FREESYNC_SUPPORT == _ON)
       if(GET_OSD_FREE_SYNC_STATUS() == _ON)
       {
	       UserCommonAdjustUltraVivid(_FUNCTION_OFF, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
	}
	else
#endif
	{
	       UserCommonAdjustUltraVivid(_FUNCTION_ON, UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
	}
    }
#endif
#else

    // Adjust Y-Peaking
#if(_YPEAKING_SUPPORT == _ON)
    UserInterfaceAdjustYpeaking();
#endif

#endif

    // Adjust Sharpness
#if(_SHARPNESS_SUPPORT == _ON)
    UserCommonAdjustSharpness(SysSourceGetInputPort());
#endif

    // Adjust Backlight
    UserAdjustBacklight(GET_OSD_BACKLIGHT());

    // Adjust Brightness & Contrast
    RTDNVRamLoadBriCon(SysSourceGetSourceType());

    // Adjust Transparency
    ScalerOsdSetTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // User Adjust Background Color
    ScalerDDomainBackgroundSetColor(0, 0, 0);

#if(_PCM_FUNCTION == _ON)
#if(_HDR10_SUPPORT == _ON)
    if((GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE) || (GET_OSD_HDR_MODE() == _HDR10_MODE_FORCE_2084))
#else
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
#endif
    {
#if(_BRIGHTNESS_SUPPORT == _ON)
        ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if(_CONTRAST_SUPPORT == _ON)
        ScalerColorContrastEnable(_FUNCTION_OFF);
#endif
        UserCommonAdjustGammaRegionEnable(_FUNCTION_ON);
        ScalerColorSRGBEnable(_FUNCTION_ON);
        ScalerColorPCMInputGammaEnable(_FUNCTION_ON);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_ON);
        }
        else
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);
        }
#endif  // End of #if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))

#if((_GLOBAL_HUE_SATURATION == _ON) && (_GLOBAL_COLOR_CONVERT_HUE_SATURATION_FUNCTION == _ON))
        // Use Color Convert to Adjust Hue & Saturation
        if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID)
        {
            UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), 140);
        }
        else
        {
            UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
        }
#endif  // End of #if((_GLOBAL_HUE_SATURATION == _ON) && (_GLOBAL_COLOR_CONVERT_HUE_SATURATION_FUNCTION == _ON))

    }
    else
#endif  // End of #if(_PCM_FUNCTION == _ON)
    {

#if(_PCM_FUNCTION == _ON)
        ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
#endif

        // Adjust Gamma On/Off
#if(_GAMMA_FUNCTION == _ON)
        if(GET_OSD_GAMMA() == _GAMMA_OFF)
        {
            UserCommonAdjustGammaRegionEnable(_FUNCTION_OFF);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif
        }
        else
        {
            UserCommonAdjustGammaRegionEnable(_FUNCTION_ON); 

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif
        }
#endif  // End of #if(_GAMMA_FUNCTION == _ON)

        // Adjust Hue & Saturation
#if(_GLOBAL_HUE_SATURATION == _ON)
        if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID)
        {
            UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), 140);
        }
        else
        {
            UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
        }
#endif  // End of #if(_GLOBAL_HUE_SATURATION == _ON)

        // Adjuset Brightness & Contrast
#if(_BRIGHTNESS_SUPPORT == _ON)
        UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#endif

#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif
    }

    // Adjust ICM On/Off
#if(_ICM_SUPPORT == _ON)
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD)
    {
        ScalerColorICMEnable(_FUNCTION_OFF);
    }
    else
    {
        ScalerColorICMEnable(_FUNCTION_ON);
    }
#endif

    // Adjust DCC On/Off
#if(_DCC_FUNCTION == _ON)
    if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD) || (GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
    {
        ScalerColorDCCEnable(_FUNCTION_OFF);
    }
    else
    {
        ScalerColorDCCEnable(_FUNCTION_ON);
    }
#endif

#if(_OD_SUPPORT == _ON)
	UserAdjustOverDrive();
    //ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());
    //ScalerODEnable(GET_OSD_OD_STATUS());
#endif

    // Adjust DCC Table
#if(_DCC_FUNCTION == _ON)
    UserAdjustDCC(GET_OSD_COLOR_EFFECT());
#endif


#if(_UNIFORMITY_SUPPORT == _ON)
    if(GET_OSD_PANEL_UNIFORMITY() == _OFF)
    {
        ScalerColorPanelUniformityEnable(_FUNCTION_OFF);
    }
    else
    {
        ScalerColorPanelUniformityEnable(_FUNCTION_ON);
    }
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    // Adjust Highlight Window Effect Space
    UserAdjustHighLightWindowEffectSpace();

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if(GET_OSD_ASPECT_RATIO_TYPE() != _OSD_ASPECT_RATIO_ORIGIN)
#endif
    {
        if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
        {
            ScalerColorHLWEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
        }
        else
        {
            UserAdjustHLWinType(GET_OSD_HLWIN_TYPE());
            ScalerColorHLWEnable(_FUNCTION_ON, _DB_APPLY_NONE);
        }
    }
#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_DEF_VIEW_SONIC_DCR)
#if(_DCR_SUPPORT)
   UserAdjustDCRControl(GET_OSD_DCR_STATUS());
#endif
#endif


}


#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set UltraVivid Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustUltraVivid(void)
{
    BYTE ucUltraVividStatus = GET_OSD_ULTRA_VIVID_STATUS();

    // Wait for D-domain DB apply ready
    ScalerColorWaitDDomainDBApply();
#if(_HDR10_SUPPORT == _ON)
    if((UserCommonHDRGetHDR10Status() == _HDR10_ON) && (GET_OSD_HDR_SHARPNESS() == _ON))
    {
        ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_HDR, GET_CURRENT_BANK_NUMBER());
    }
    else
#endif
    {
        if(ucUltraVividStatus != _ULTRA_VIVID_OFF)
        {
            ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[ucUltraVividStatus - 1], GET_CURRENT_BANK_NUMBER());
        }
        else
        {
            ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
        }
    }
}

//--------------------------------------------------
// Description  : UltraVivid Proccess
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustUltraVividProc(EnumDBApply enumDBApply)
{
#if(_HDR10_SUPPORT == _ON)
    if((UserCommonHDRGetHDR10Status() == _HDR10_ON) && (GET_OSD_HDR_SHARPNESS() == _ON))
    {
        UserCommonAdjustUltraVivid(_FUNCTION_ON, UserCommonInterfaceGetColorFormat(), enumDBApply);
    }
    else
#endif
    {
        if(GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_OFF)
        {
            UserCommonAdjustUltraVivid(_FUNCTION_OFF, UserCommonInterfaceGetColorFormat(), enumDBApply);
        }
        else
        {
            UserCommonAdjustUltraVivid(_FUNCTION_ON, UserCommonInterfaceGetColorFormat(), enumDBApply);
        }
    }
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_SHARPNESS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Sharpness Coef
// Input Value  : SU Coef Type
// Output Value : SU Coef
//--------------------------------------------------
code BYTE *UserInterfaceGetSharpnessCoef(EnumSUCoefType enumSUCoefType, EnumSourceSearchPort enumSourceSearchPort)
{
    enumSourceSearchPort = enumSourceSearchPort;
	DebugMessageOsd("3.GET_OSD_SHARPNESS",GET_OSD_SHARPNESS());
	DebugMessageOsd("3.enumSUCoefType",enumSUCoefType);
    switch(enumSUCoefType)
    {
#if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))
        case _H_V_SU_128TAPS_NORMAL:
            return tSCALE_128TAPS_NORMAL_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
        case _H_V_SU_96TAPS_NORMAL:
            return tSCALE_96TAPS_NORMAL_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if(_HSU_128TAPS_SUPPORT == _ON)
        case _H_SU_128TAPS_1_TO_1:
            return tSCALE_128TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if(_HSU_96TAPS_SUPPORT == _ON)
        case _H_SU_96TAPS_1_TO_1:
            return tSCALE_96TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif
        default:
            return _NULL_POINTER;
    }
}

//--------------------------------------------------
// Description  : Get Sharpness Coef BankNum
// Input Value  : None
// Output Value : BankNum
//--------------------------------------------------
BYTE UserInterfaceGetSharpnessCoefBankNum(void)
{
    return GET_CURRENT_BANK_NUMBER();
}

//--------------------------------------------------
// Description  : User Bypass Check
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSharpnessBypassCheck(void)
{
    return _FALSE;
}
#endif

#if(_DCR_SUPPORT == _ON)

#if(_DEF_VIEW_SONIC_DCR)
#if (_DCR_SUPPORT == _ON)


//--------------------------------------------------
// Description  : Check Y Max Level
// Input Value  : None
// Output Value : None
// Return Value : None
//--------------------------------------------------
void CDcrCheckYMaxLevel(void)
{

//DebugMessageSystem("####1.CDcrCheckYMaxLevel  ######", (ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_R) + ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_G) + ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_B)) / 3  );
    if((ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_R) + ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_G) + ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_B)) / 3 <= _DCR_LEVEL_LOW)
    {

	   //DebugMessageSystem("####2.GET_Y_MAX_UNDER_LABEL_STATUS  ######", GET_Y_MAX_UNDER_LABEL_STATUS()  );
	   //DebugMessageSystem("####3.GET_L4_PATTEN_TIMER  ######", GET_L4_PATTEN_TIMER()  );

        if(!GET_Y_MAX_UNDER_LABEL_STATUS() && !GET_L4_PATTEN_TIMER())
        {
		if((GET_OSD_DCR_STATUS() != _DCR_Level_0)
				&& (GET_COLOR_TEMP_TYPE() == _CT_USER)
				&& (GET_COLOR_TEMP_TYPE_USER_R() == _USER_RGB_MAX)
				&& (GET_COLOR_TEMP_TYPE_USER_G() == _USER_RGB_MAX)
				&& (GET_COLOR_TEMP_TYPE_USER_B() == _USER_RGB_MAX))
			{
           			SET_L4_PATTEN_TIMER();
				#if(_DCR_TURNOFF_BACKLIGHT_SUPPORT == _ON)
				ScalerTimerActiveTimerEvent(SEC(25), _USER_TIMER_EVENT_DCR_BACKLIGHT_OFF);
				#endif
			}
        }
    }
    else
    {
        CLR_HIGH_DCR_STATUS();
        CLR_Y_MAX_UNDER_LABEL_STATUS();
	    CLR_L4_PATTEN_TIMER();
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_BACKLIGHT_OFF);
    }
}


void UserInterfaceAdjustDCR(void)
{
    //UserAdjustPwmDcr();


	if(1)//(GET_DCR_READY_STATUS() == _TRUE)
	{

#if(_DCR_BIT_MODE == _DCR_GEN_1_0_10BIT)
        SET_DCR_RGB_INFORMATION(ScalerColorDCRGetAverage(_DCR_ABOVE_TH1_VAL_TOTAL,(DWORD)GET_MDOMAIN_OUTPUT_HWIDTH() * GET_MDOMAIN_OUTPUT_VHEIGHT() * 3)/4);
#else//_DCR_8BIT
        SET_DCR_RGB_INFORMATION(ScalerColorDCRGetAverage(_DCR_ABOVE_TH1_VAL_TOTAL,(DWORD)GET_MDOMAIN_OUTPUT_HWIDTH() * GET_MDOMAIN_OUTPUT_VHEIGHT() * 3));
#endif

		CDcrCheckYMaxLevel();
	}
}


//--------------------------------------------------
// Description  : DCR Measure
// Input Value  : None
// Output Value : DCR target
//--------------------------------------------------
BYTE UserAdjustDCRCalPwm(BYTE ucRGBValValue)
{
	BYTE i=0;
	BYTE ucPwm=0;
	BYTE tRGBValValue[5] = {0,55,110,165,233};//{0,50,75,175,255};
	BYTE tBacklightPwm[5] = 0;

#if 0	//MPRT��DCR����
	if((GET_OSD_MPRT()!=_OFF)&&(SysModeGetModeState() ==_MODE_STATUS_ACTIVE)&&(GET_INPUT_TIMING_VFREQ()> _MPRT_MIN_FRAME_RATE)&&(GET_OSD_FREE_SYNC_STATUS() == _OFF))
	{
		tBacklightPwm[0] = MPRTBacklightDefault[0];
		tBacklightPwm[1] = (MPRTBacklightDefault[1]-MPRTBacklightDefault[0])/2+MPRTBacklightDefault[0];
		tBacklightPwm[2] = MPRTBacklightDefault[1];
		tBacklightPwm[3] = (MPRTBacklightDefault[2]-MPRTBacklightDefault[1])/2+MPRTBacklightDefault[1];
		tBacklightPwm[4] = MPRTBacklightDefault[2];

	}
	else
#endif
	{

		tBacklightPwm[0] = BacklightDefault[0];
		tBacklightPwm[1] = (BacklightDefault[1]-BacklightDefault[0])/2+BacklightDefault[0];
		tBacklightPwm[2] = BacklightDefault[1];
		tBacklightPwm[3] = (BacklightDefault[2]-BacklightDefault[1])/2+BacklightDefault[1];
		tBacklightPwm[4] = BacklightDefault[2];

	}
	
	for(i=0;i < 4;i++)
	{
		if((tRGBValValue[i] <= ucRGBValValue) && (ucRGBValValue < tRGBValValue[i+1]))
		{
			break;
		}
	}
	
	if(ucRGBValValue>=233)
		i=4;
	
	ucPwm =tBacklightPwm[i] +(WORD)(ucRGBValValue-tRGBValValue[i])*(tBacklightPwm[i+1] - tBacklightPwm[i])/(tRGBValValue[i+1] -tRGBValValue[i]);

	return ucPwm;
}


//extern void USER_XW_TEST_VALE(ucMeasureValueAvg);
/*when use UserAdjustDCRGetPwm fun,must set _RGB_QUANTIZATION_RANGE_SUPPORT _ON, _YCC_QUANTIZATION_RANGE_SUPPORT _ON, if IC support ,must set to on*/
BYTE UserAdjustDCRGetPwm(void)
{
	//ucOffblvalue: off backlight val value,when ucMeasureValueAvg <ucOffblvalue, turn off backlight,when ucOnblvalue >ucMeasureValueAvg,turn on backlight
    BYTE ucPWM =0;
	WORD ucOffblvalue=0,ucOnblvalue=0,ucMeasureValueAvg=0;
	BYTE ucMeasureHighR=0,ucMeasureHighG=0,ucMeasureHighB=0;
	BYTE ucOffblvalueH=35;   //20;
	DWORD dwTotalPixel = ((DWORD)GET_MDOMAIN_OUTPUT_HWIDTH()*GET_MDOMAIN_OUTPUT_VHEIGHT()*3);

	//DebugMessageOsd("1.dwTotalPixel",dwTotalPixel);
	// Get val value (R+G+B)/3  of  pixel value above thershold1 value,ucMeasureValueAvg range(0-255 for 8bit dcr;0-1023 for 10 bit dcr)
	ucMeasureValueAvg = ScalerColorDCRGetAverage(_DCR_ABOVE_TH1_VAL_TOTAL, dwTotalPixel);
#if(_DCR_BIT_MODE == _DCR_GEN_0_1_8BIT ||_DCR_BIT_MODE == _DCR_GEN_0_0_8BIT)

	//get high level data of R,G,B
	ucMeasureHighR	  = ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_R);
	ucMeasureHighG	  = ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_G);
	ucMeasureHighB	  = ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_B);


#else
	ucMeasureValueAvg = ucMeasureValueAvg>>2;// change to 8bit dcr
	//get high level data of R,G,B
	ucMeasureHighR	  = (ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_R))>>2;
	ucMeasureHighG	  = (ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_G))>>2;
	ucMeasureHighB	  = (ScalerColorDCRReadResult(_DCR_HIGH_LV_VAL_B))>>2;

#endif




	//analog source
	if(SysSourceGetSourceType() == _SOURCE_VGA)
	{
		ucOffblvalue =8;
		ucOnblvalue  =10;
	}
	else//digitial source
	{
		//_YCC_QUANTIZATION_RANGE_SUPPORT,_RGB_QUANTIZATION_RANGE_SUPPORT must set to on if support
		//full range use
		ucOffblvalue =2;
		ucOnblvalue  =4;
	}

	ucPWM =UserAdjustDCRCalPwm(ucMeasureValueAvg);

#if 0	//��ֵ��ӡ
	USER_XW_TEST_VALE(ucPWM);
#endif


#if 0//(_DEF_HSBL)
	if(ucMeasureValueAvg <= 5)
	{
		ucMeasureHighR = 0;
		ucMeasureHighG = 0;
		ucMeasureHighB = 0;
	}
#endif


	if(bBACKLIGHTPOWER == _LIGHT_CONTROL_ON)
	{
		if((ucMeasureValueAvg <=ucOffblvalue) && (ucMeasureHighR <=ucOffblvalueH)&&(ucMeasureHighG <=ucOffblvalueH)&&(ucMeasureHighB <=ucOffblvalueH))
		{
#if(_DCR_PANEL_ON_OFF)	//15s��ر���
			ScalerTimerActiveTimerEvent(SEC(30),_USER_TIMER_EVENT_DCR_CAL_TIME);
#else
			ScalerTimerActiveTimerEvent(SEC(0.1),_USER_TIMER_EVENT_DCR_CAL_TIME);
#endif
		}
		else
		{
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_CAL_TIME);
		}
		if((g_ucDCR_15SEC_OffBLFlag == _TRUE) &&(ScalerOsdGetOsdEnable() == _DISABLE))// after 15s,we  turn off backlight
		{
			ucPWM =0;
			g_ucDCR_15SEC_OffBLFlag =_FALSE;
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_CAL_TIME);
#if(_DCR_PANEL_ON_OFF == _ON)
			PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
#endif
		}
	}
	else if(bBACKLIGHTPOWER == _LIGHT_CONTROL_OFF)
	{
		if((ucMeasureValueAvg > ucOnblvalue) || (ucMeasureHighR > ucOffblvalueH) || (ucMeasureHighG > ucOffblvalueH) || (ucMeasureHighB > ucOffblvalueH))
		{
#if(_DCR_PANEL_ON_OFF == _ON)
	    	PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
#endif
		}

	}

	//check OSD if is on, turn on backlight
	if(ScalerOsdGetOsdEnable() == _ENABLE)
	{
#if(_DCR_PANEL_ON_OFF == _ON)
	    PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
#endif
	}

#if(_BACKLIGHT_PWM_INVERSE == _ON)
	ucPWM = 0xFF - ucPWM;
 #endif

	
	return ucPWM;
}

extern void OsdDisplayUpdatePowerBar(BYTE ucPreload); //���¹��Ľ�����


void UserAdjustPwmDcr()
{
	BYTE ucPrePwm=0,uctargetPwm=0,ucDevPwm=0;
	BYTE ucdet=0;
	ucPrePwm =PCB_GET_BACKLIGHT_PWM();
	uctargetPwm =UserAdjustDCRGetPwm();
	ucDevPwm =abs(uctargetPwm -ucPrePwm);

	if(ucDevPwm == 0)
	{
		g_ucDCR_TUNE_1STEP_Flag =_FALSE;
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_TUNE_PWM_TIMER);
	}
	else
	{
//		ScalerTimerActiveTimerEvent(SEC(_DCR_TUNE_PWM_1STEP_TIME),_USER_TIMER_EVENT_DCR_TUNE_PWM_TIMER);
		ScalerTimerActiveTimerEvent(SEC(0.01),_USER_TIMER_EVENT_DCR_TUNE_PWM_TIMER);
	}
#if 0
	if(ScalerOsdGetOsdEnable() == _ENABLE)
	{
		PCB_BACKLIGHT_PWM(uctargetPwm);
	}
	else 
#endif
	if(g_ucDCR_TUNE_1STEP_Flag == _TRUE)
	{
		g_ucDCR_TUNE_1STEP_Flag =_FALSE;

		if(ucDevPwm > 150)
		{
			ucdet =3;
		}
		else if(ucDevPwm > 50)
		{
			ucdet =2;
		}
		else
		{
			ucdet=1;
		}
		if(uctargetPwm > ucPrePwm)
		{
			PCB_BACKLIGHT_PWM(ucPrePwm + ucdet);
			OsdDisplayUpdatePowerBar(_FALSE);
		}
		else
		{
			PCB_BACKLIGHT_PWM(ucPrePwm - ucdet);
			OsdDisplayUpdatePowerBar(_FALSE);
		}
	}
	//DebugMessageOsd("1.dcrpwm",PCB_GET_BACKLIGHT_PWM());
}


void UserAdjustDCRControl(bit bEn)
{

	g_ucDCR_15SEC_OffBLFlag =_FALSE;
	g_ucDCR_TUNE_1STEP_Flag =_FALSE;
	if(bEn == _ON)
	{

	}
	else
	{
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_CAL_TIME);
		ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_TUNE_PWM_TIMER);
		UserAdjustBacklight(GET_OSD_BACKLIGHT());
	}
}



#endif
#endif



//--------------------------------------------------
// Description  : User Adjust DCR
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustDCRHandler(void)
{
    if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
    {
#if(_DEF_VIEW_SONIC_DCR)
		// Read DCR Result
		UserInterfaceAdjustDCR();
#endif

#if(_LOCAL_DIMMING_SUPPORT == _ON)
        if(UserInterfaceGetLocalDimmingStatus() == _LD_ENABLE)
        {
            BYTE pucDCRResult[_TOTAL_REGION];
            memset(pucDCRResult, 255UL, _TOTAL_REGION);
            ScalerColorDCRLocalDimmingReadResult(pucDCRResult);
        }
        else
#endif
        {
            PDATA_DWORD(0) = ScalerColorDCRReadResult(_DCR_ABOVE_TH1_NUM);
        }
    }
}
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
//--------------------------------------------------
// Description  : User Adjust DCC Histogram
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceDCCHistogramHandler(void)
{
}
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if(_IAPS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Adjust IAPS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustIAPSHandler(void)
{
}
#endif // End of #if(_IAPS_SUPPORT == _ON)

//--------------------------------------------------
// Description  : OSD Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdPowerOnInitial(void)
{
#if(_SIX_COLOR_SUPPORT == _ON)
    BYTE ucIndex = 0;
#endif

#if(_UNIFORMITY_SUPPORT == _ON)
    // Uniformity parameters setting
    ScalerColorPanelUniformityInitial();

    if(GET_OSD_PANEL_UNIFORMITY() == _ON)
    {
        UserAdjustPanelUniformityMode(_UNIFORMITY_OSD_TYPE1);
    }
#endif

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        UserAdjustPCM(GET_OSD_PCM_STATUS());
    }
    else
#endif
    {
#if(_GAMMA_FUNCTION == _ON)
        // Adjust Gamma Table
        UserAdjustGamma(GET_OSD_GAMMA());                    
#endif
    }
#if(_GAMMA_FUNCTION == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            UserCommonAdjustGammaRegionEnable(_FUNCTION_ON);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif
        }
#endif

#if(_RGB_3D_GAMMA == _ON)
    UserAdjust3DGamma(GET_OSD_PCM_SOFT_PROFT_MODE());
#endif

// Adjust SCM Table, Should before ICM Adjust
#if(_SCM_SUPPORT == _ON)
    UserAdjustSCM(GET_OSD_COLOR_EFFECT());
#endif

    // Adjust ICM Table
#if(_ICM_SUPPORT == _ON)
    UserAdjustICM(GET_OSD_COLOR_EFFECT());
#endif

    // Adjust DCR Threshold & Source
#if(_DCR_SUPPORT == _ON)

#if(_DCR_BIT_MODE == _DCR_GEN_1_0_10BIT)
    ScalerColorDCRAdjust(_DCR_THESHOLD1, _DCR_THESHOLD2, _MEASURE_AVERAGE);
#elif((_DCR_BIT_MODE == _DCR_GEN_0_0_8BIT) || (_DCR_BIT_MODE == _DCR_GEN_0_1_8BIT))
    ScalerColorDCRAdjust((_DCR_THESHOLD1 >> 2), (_DCR_THESHOLD2 >> 2), _MEASURE_AVERAGE);
#endif

#endif

    // Adjust Six Color Hue / Saturation
#if(_SIX_COLOR_SUPPORT == _ON)
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER)
    {
        for(ucIndex = 0; ucIndex < 6; ucIndex++)
        {
            SET_OSD_SIX_COLOR(ucIndex);
            OsdDisplaySixColorGetOneColor(ucIndex);
            ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
        }

        ScalerColorSixColorInitial();
    }
#endif

#if(_OD_SUPPORT == _ON)
    //UserAdjustOD();
#endif

    // Adjust Highlight Window Border
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWBorderAdjust(_HL_WIN_BORDER_SIZE, 255, 0, 0);

    ScalerColorHLWBorderEnable(_ON, _ON, _ON, _ON);
#endif

#if(_SDR_TO_HDR_SUPPORT == _ON)
    UserAdjustSDRToHDR(GET_OSD_SDR_TO_HDR());
#endif
}


//--------------------------------------------------
// Description  : OSD Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdActiveProc(void)
{
#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        if((SysSourceGetInputPort() == _D3_INPUT_PORT) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1))
        {
            UserCommonNVRamSetSystemData(_SEARCH_PORT, _D12_INPUT_PORT);
        }
        else
        {
            UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        }

        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        UserCommonNVRamSaveSystemData();
    }
    else if(UserCommonNVRamGetSystemData(_SEARCH_PORT) == SysSourceGetInputPort())
    {
        if((SysSourceGetInputPort() == _D3_INPUT_PORT) && (PCB_GET_HDMI_SW_SELECT() == _SW_SEL_HDMI3_1))
        {
            UserCommonNVRamSetSystemData(_SEARCH_PORT, _D12_INPUT_PORT);
            UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
            UserCommonNVRamSaveSystemData();
        }
    }
#else
    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        UserCommonNVRamSaveSystemData();
    }
#endif

    if(UserInterfaceGetActiveByPassStatus() == _FALSE)
    {
        // DDCCI switch to active port
        UserCommonInterfaceDdcciSwitch(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());

        if(GET_FAIL_SAFE_MODE() == _TRUE)
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG);
        }
        else
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_ACTIVE_DO_ONE_TIME_MSG);
        }
    }

#if((_OD_SUPPORT == _ON) && (_FREESYNC_SUPPORT == _ON))
    //UserAdjustOD();
#endif

#if(_FREEZE_SUPPORT == _ON)
    UserCommonAdjustDisplayFreeze(GET_OSD_FREEZE_STATUS());
#endif

    ScalerDDomainBackgroundEnable(_DISABLE);
}

//--------------------------------------------------
// Description  : OSD Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdResetProc(void)
{
    // Disable OSD
    if(GET_OSD_LOGO_ON() == _OFF)
    {
        OsdDispDisableOsd();
    }

    SET_OSD_LOGO_ON(_OFF);

    // Cancel Timer Events
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_POWER_DOWN);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);

	//ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_UPDATE_MAINMENU_VFREQ);
#if (_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);
#endif
#if(_DCR_SUPPORT== _ON)
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DCR_SLOW_ADJUST); // yongle 20130710
#endif
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_OSD_LOCKING_STATUS_MSG);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_LOCKING_STATUS_MSG);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_LOGO_BOOTUP_STATUS_MSG);

    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_Timing_Notice);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_Front_Sight);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GAME_HOTKEY);
    #if _EYE_VLI_SUPPORT
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EVENT_EYE_PROTECT_EVENT);
	#endif
	//ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_SAVE_OSD_DATE);
	//ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
	//ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_SIX_COLOR_DATA);



	
}


#if(_VGA_SUPPORT == _ON)

#if(_DEF_VGA_TIMING_KEY_2_4)
//--------------------------------------------------
// Description	:
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetModeSwitch(BYTE modetemp)
{
    if((modetemp == _MODE_720x400_70HZ)||(modetemp == _MODE_640x400_70HZ)||(modetemp == _MODE_640x350_70HZ))
    {
#if 1 // EasonLee 20140116 for VSC SPEC timing item4
        if(abs(GET_INPUT_TIMING_HFREQ() - 303) < 2)
        {
            modetemp = _MODE_640x400_70HZ;
        }
        else
#endif
        {
        	switch(GET_Mode400at70_Switch())
        	{
        		case _M_720x400_70:
        			modetemp = _MODE_720x400_70HZ;
        			break;
        		case _M_640x350_70:
        			modetemp = _MODE_640x350_70HZ;
        			break;
        		case _M_640x400_70:
        			modetemp = _MODE_640x400_70HZ;
        			break;
        	}
        }
    }

    else if((modetemp == _MODE_720x480_60HZ)||(modetemp == _MODE_640x400_60HZ)||(modetemp == _MODE_640x480_60HZ)||(modetemp == _MODE_720x480_60HZ_GTF)||(modetemp == _MODE_720x480p_60HZ))
    {
        switch(GET_Mode480at60_Switch())
        {
            case _M_720x480_60:
                if(abs(GET_INPUT_TIMING_VTOTAL() - 497) < 2)
                {
                    modetemp = _MODE_720x480_60HZ;
                }
                else
                {
                    modetemp = _MODE_720x480p_60HZ;
                }
                break;
            case _M_640x400_60:
                modetemp = _MODE_640x400_60HZ;
    			break;
    		case _M_640x480_60:
    			//Duncan 131211 fix MAC 640x480@67hz -2khz incorrect start
				if(abs(GET_INPUT_TIMING_HSYNCWIDTH() - 60) < 2)
				{
					modetemp = _MODE_640x480_66HZ;
				}
				else
				//Duncan 131211 end
				{
    				modetemp = _MODE_640x480_60HZ;
				}
    			break;
    	}
    }

    else if((modetemp ==_MODE_1024x768_50HZ)||(modetemp ==_MODE_1280x768_50HZ))
    {
        if(GET_Mode768at50_Switch() == _M_1024x768_50)
        {
            modetemp = _MODE_1024x768_50HZ;
        }
        else
        {
            modetemp = _MODE_1280x768_50HZ;
        }
    }

    else if((modetemp ==_MODE_1024x768_75HZ_MAC)||(modetemp ==_MODE_1024x768_75HZ)||(modetemp ==_MODE_1280x768_75HZ))
    {
        if(GET_Mode768at75_Switch() == _M_1024x768_75)
        {
            if(abs(GET_INPUT_TIMING_VTOTAL() -800) < 2)
            {
                modetemp = _MODE_1024x768_75HZ;
            }
            else
            {
                modetemp = _MODE_1024x768_75HZ_MAC;
            }
        }
        else
        {
            modetemp = _MODE_1280x768_75HZ;
        }
    }

    else if((modetemp ==_MODE_1360x768_60HZ)||(modetemp ==_MODE_1280x768_60HZ)||(modetemp==_MODE_1366x768_60HZ))
    {
    	switch(GET_Mode768at60_Switch())
    	{
    		case _M_1360x768_60:
    			modetemp = _MODE_1360x768_60HZ;
    			break;
    		case _M_1280x768_60:
    			modetemp = _MODE_1280x768_60HZ;
    			break;
    		case _M_1366x768_60:
    			modetemp = _MODE_1366x768_60HZ;
    			break;
    		//case _M_1366x768_60_RB:
    		//	modetemp = _MODE_1366x768_60HZ_RB;
    		//	break;
    	}
    }

    else if((modetemp == _MODE_1280x960_60HZ)||(modetemp == _MODE_1600x900_60HZ_RB))
    {
    

        if(GET_Mode960at60_Switch() == _M_1280x960_60 )
        //if(modetemp == _MODE_1280x960_60HZ)
        {
            modetemp = _MODE_1280x960_60HZ;
        }
        else
        {
            modetemp = _MODE_1600x900_60HZ_RB;
        }
    }

    else if((modetemp ==_MODE_1600x900_60HZ)||(modetemp ==_MODE_1440x900_60HZ))
    {
        if(GET_Mode900at60_Switch() == _M_1440x900_60)
        {
            modetemp = _MODE_1440x900_60HZ;
        }
        else
        {
            modetemp = _MODE_1600x900_60HZ;
        }
    }

    else if((modetemp ==_MODE_1600x900_60HZ_CVR)||(modetemp ==_MODE_1440x900_60HZ_RB))
    {
        if(GET_Mode900RBat60_Switch() == _M_1440x900_60_RB)
        {
            modetemp = _MODE_1440x900_60HZ_RB;
        }
        else
        {
            modetemp = _MODE_1600x900_60HZ_CVR;
        }
    }

    else if((modetemp == _MODE_1400x1050_60HZ)||(modetemp == _MODE_1680x1050_60HZ))
    {
        if(GET_Mode1050at60_Switch() == _M_1400x1050_60)
        {
            modetemp = _MODE_1400x1050_60HZ;
        }
        else
        {
            modetemp = _MODE_1680x1050_60HZ;
        }
    }

    else if((modetemp == _MODE_1400x1050_60HZ_RB)||(modetemp == _MODE_1680x1050_60HZ_RB))
    {
        if(GET_Mode1050RBat60_Switch() == _M_1400x1050_60_RB)
        {
            modetemp = _MODE_1400x1050_60HZ_RB;
        }
        else
        {
            modetemp = _MODE_1680x1050_60HZ_RB;
        }
    }
#if(_PROJECT_ID !=_ID_ZQ_2513E05_PANDA_LC215DTBA_8BIT_FHD75_VA2271_H_20241223) && (_PROJECT_ID !=_ID_ZQ_2513E05_BOE_HV320FHB_F4A_8BIT_FHD75_VA2271_H_20250301)
    else if((modetemp == _MODE_1440x900_75HZ)||(modetemp == _MODE_1152x870_75HZ))
    {
        if(GET_Mode900at75_Switch() == _M_1440x900_75)
        {
            modetemp = _MODE_1440x900_75HZ;
        }
        else
        {
            modetemp = _MODE_1152x870_75HZ;
        }
    }
#endif
    return modetemp;
}




#endif

//--------------------------------------------------
// Description  : Check ModeIndex
// Input Value  : System ModeIndex
// Output Value : ModeIndex
//--------------------------------------------------
BYTE UserInterfaceGetVGAConfuseMode(BYTE ucModeIndex)
{
#if 0//(_DEF_INPUT_VGA_TIMING_DETAILED)
	if(GET_INPUT_TIMING_VHEIGHT()+GET_INPUT_TIMING_VSTART() < 20 && g_UserInputVgaTimingDetailed < 10)
	{
		g_UserInputVgaTimingDetailed++;
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
		//DebugMessageOsd("0.old_data",g_UserInputVgaTimingDetailed);
		return ucModeIndex;
	}

	g_UserInputVgaTimingDetailed = 0;

	//DebugMessageOsd("0.data",g_UserInputVgaTimingDetailed);
#endif

	//DebugMessageOsd("0.ucModeIndex",ucModeIndex);

#if(_DEF_VGA_TIMING_KEY_2_4)
	if(ucModeIndex == _MODE_1360x768_75HZ || ucModeIndex == _MODE_1280x768_75HZ || ucModeIndex == _MODE_1024x768_75HZ_MAC)
	{
		if(GET_INPUT_TIMING_HSYNCWIDTH()!=33&&GET_INPUT_TIMING_HSYNCWIDTH()!=37)
		{
			if(GET_INPUT_TIMING_VSYNCWIDTH() == 4)
			{
				ucModeIndex = _MODE_1280x768_75HZ;
			}
			else
			{
				ucModeIndex = _MODE_1024x768_75HZ_MAC;
			}
		}
		else
		{
			ucModeIndex = _MODE_1360x768_75HZ;
		}
	}

	ucModeIndex = UserInterfaceGetModeSwitch(ucModeIndex);




    if((ucModeIndex == _MODE_1920x1200_60HZ) || (ucModeIndex == _MODE_1920x1200_60HZ_RB) || (g_stVGAModeUserData.ucModeNumber == _MODE_1920x1200_50HZ_RB))
    {
		SET_OSD_ACTIVE_STATE_MESSAGE(_TRUE);
    }

#else

	if((ucModeIndex == _MODE_720x350_50HZ) || (ucModeIndex == _MODE_720x400_50HZ_VG849A))
	{
		if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
			ucModeIndex = _MODE_720x350_50HZ;
		else
			ucModeIndex = _MODE_720x400_50HZ_VG849A;
	}
	
	if((ucModeIndex == _MODE_720x350_50HZ) || (ucModeIndex == _MODE_640x350_50HZ_VG849A))
	{
		if(GET_INPUT_TIMING_VSTART() > 135) //V Back Porch
		{
			ucModeIndex = _MODE_640x350_50HZ_VG849A;
		}
		else
		{
			ucModeIndex = _MODE_720x350_50HZ;
		}
	}
	
	if((ucModeIndex == _MODE_720x350_60HZ) || (ucModeIndex == _MODE_640x350_60HZ_VG849A))
	{
		if(GET_INPUT_TIMING_VSTART() > 85)	//V Back Porch
		{
			ucModeIndex = _MODE_640x350_60HZ_VG849A;
		}
		else
		{
			ucModeIndex = _MODE_720x350_60HZ;
		}
	}

	if((ucModeIndex == _MODE_826x416_70HZ)||(ucModeIndex == _MODE_720x400_70HZ_VG849A)||(ucModeIndex == _MODE_720x350_70HZ)||(ucModeIndex == _MODE_640x350_70HZ_QD))
	{
		if(GET_INPUT_TIMING_VSTART() > 50)	//V Back Porch
		{
			ucModeIndex = _MODE_640x350_70HZ_QD;
		}
		else
		{
			if(GET_INPUT_TIMING_VHEIGHT() < 380)	// V Active Video
			{
				ucModeIndex = _MODE_720x350_70HZ;
			}
			else if(GET_INPUT_TIMING_VHEIGHT() < 406)
			{
				ucModeIndex = _MODE_720x400_70HZ_VG849A;
			}
			else
			{
				ucModeIndex = _MODE_826x416_70HZ;
			}
		}
	}



	if((ucModeIndex == _MODE_1400x1050_50HZ) || (ucModeIndex == _MODE_1680x1050_50HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() > 5)
		{
			ucModeIndex = _MODE_1680x1050_50HZ;
		}
		else
		{
			ucModeIndex = _MODE_1400x1050_50HZ;
		}
	}

	if(ucModeIndex == _MODE_1920x1200_50HZ_VG849A)
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() < 5)
		{
			ucModeIndex = _MODE_1600x1200_50HZ_VG849A;
		}
	}

	if(ucModeIndex == _MODE_720x400_50HZ_VG849A)
	{
		if(GET_INPUT_TIMING_HTOTAL() == 3199)
		{
			ucModeIndex = _MODE_640x400_50HZ_VG849A;
		}
	}

	if(ucModeIndex == _MODE_640x350_70HZ_QD || ucModeIndex == _MODE_640x400_60HZ)
	{
		if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
		{
			ucModeIndex = _MODE_640x350_70HZ_QD;
		}
		else
		{
			ucModeIndex = _MODE_640x400_60HZ;
		}
	}

	if(ucModeIndex ==_MODE_720x576p_50HZ)
	{
		ucModeIndex = _MODE_720x576_50HZ_VG849A;
	}

	
	if((ucModeIndex == _MODE_720x400_70HZ_VG849A) )
	{
		ucModeIndex = _MODE_720x400_70HZ_VG849A;
	}
	if((ucModeIndex == _MODE_640x400_60HZ))
	{

		ucModeIndex = _MODE_640x400_60HZ;
	}

	if(ucModeIndex == _MODE_1280x768_75HZ_VG849A || ucModeIndex == _MODE_1024x768_75HZ_QD)
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() < 5)
		{
			ucModeIndex = _MODE_1024x768_75HZ_QD;
		}
		else
		{
			ucModeIndex = _MODE_1280x768_75HZ_VG849A;
		}
	}

	if(ucModeIndex == _MODE_1600x1200_75HZ || ucModeIndex == _MODE_1920x1200_75HZ_VG849A)
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() < 5)
		{
			ucModeIndex = _MODE_1600x1200_75HZ;
		}
		else
		{
			ucModeIndex = _MODE_1920x1200_75HZ_VG849A;
		}
	}

	
#if 0
	DebugMessageOsd("0.I",ucModeIndex);
	DebugMessageOsd("0.HTOTAL",GET_INPUT_TIMING_HTOTAL());
	DebugMessageOsd("0.0",GET_INPUT_TIMING_HWIDTH());
	DebugMessageOsd("0.1",GET_INPUT_TIMING_HSYNCWIDTH());
	DebugMessageOsd("0.2",GET_INPUT_TIMING_VFREQ());
	DebugMessageOsd("0.3",GET_INPUT_TIMING_VTOTAL());
	DebugMessageOsd("0.4",GET_INPUT_TIMING_VHEIGHT());
	DebugMessageOsd("0.5",GET_INPUT_TIMING_VSTART());
	DebugMessageOsd("0.6",GET_INPUT_TIMING_VSYNCWIDTH());
	
	DebugMessageOsd("0.7",GET_INPUT_TIMING_HFREQ());
	DebugMessageOsd("0.8",GET_INPUT_TIMING_INTERLACE_FLG());
	DebugMessageOsd("0.9",GET_INPUT_TIMING_V_POLARITY());
	DebugMessageOsd("0.10",GET_INPUT_TIMING_H_POLARITY());
#endif


		
	if((ucModeIndex == _MODE_640x480_70HZ) || (ucModeIndex == _MODE_848x480_70HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() <= 3)
			ucModeIndex = _MODE_640x480_70HZ;
		else
			ucModeIndex = _MODE_848x480_70HZ;
	}
	
	if((ucModeIndex == _MODE_1024x768_50HZ) || (ucModeIndex == _MODE_1280x768_50HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4)
			ucModeIndex = _MODE_1024x768_50HZ;
		else
			ucModeIndex = _MODE_1280x768_50HZ;
	}

	if((ucModeIndex == _MODE_1024x768_75HZ_MAC) || (ucModeIndex == _MODE_1366x768_75HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4)
			ucModeIndex = _MODE_1024x768_75HZ_MAC;
		else
			ucModeIndex = _MODE_1366x768_75HZ;
	}

	if((ucModeIndex == _MODE_1280x960_75HZ_VG849A) || (ucModeIndex == _MODE_1280x960_75HZ) || (ucModeIndex == _MODE_1600x900_75HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4)
			ucModeIndex = _MODE_1280x960_75HZ_VG849A;
		else
			ucModeIndex = _MODE_1600x900_75HZ;
	}
	// DVD
	if((ucModeIndex == _MODE_640x480_60HZ) || (ucModeIndex == _MODE_720x480_60HZ_GTF) || (ucModeIndex == _MODE_720x480p_60HZ))
	{
		if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4 && GET_INPUT_TIMING_VSTART()!=35)// 35-_MODE_720x480_60HZ_GTF
		{
			ucModeIndex = _MODE_640x480_60HZ;

			DebugMessageAnalog("Detected by Special Case to 640x480-60", _MODE_640x480_60HZ);
		}
		else if((GET_INPUT_TIMING_H_POLARITY() == _FALSE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE) && GET_INPUT_TIMING_HSYNCWIDTH()!=71)
		{
			ucModeIndex = _MODE_720x480_60HZ_GTF;

			DebugMessageAnalog("Detected by Special Case to 720x480-60_GTF", _MODE_720x480_60HZ_GTF);
		}
		else
		{
			ucModeIndex = _MODE_720x480_60HZ_GTF;

			DebugMessageAnalog("Detected by Special Case to 720x480-60", _MODE_720x480_60HZ_GTF);
		}
		

	}

	if((ucModeIndex == _MODE_720x400_70HZ) || (ucModeIndex == _MODE_640x400_70HZ))
	{
		if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
		{
			ucModeIndex = _MODE_640x350_70HZ;

			DebugMessageAnalog("Detected by Special Case to _MODE_640x350_70HZ", _MODE_640x350_70HZ);
		}
	}

	if((ucModeIndex == _MODE_720x400_70HZ_VGA) )
	{
		if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
		{
			ucModeIndex = _MODE_720x400_70HZ_VGA;

			DebugMessageAnalog("Detected by Special Case to _MODE_720x400_70HZ_VGA", _MODE_720x400_70HZ_VGA);
		}
	}

	if((ucModeIndex == _MODE_1680x1050_75HZ) && GET_INPUT_TIMING_VHEIGHT()==1080)
    {
        if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_1920x1080_75HZ;
        }

		DebugMessageAnalog("Detected by Special Case to _MODE_1920x1080_75HZ", _MODE_1920x1080_75HZ);

    }

	if((ucModeIndex == _MODE_640x400_85HZ) || (ucModeIndex == _MODE_720x400_85HZ))
	{
		if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
		{
			ucModeIndex = _MODE_640x350_85HZ;
		}

		DebugMessageAnalog("Detected by Special Case to _MODE_640x350_85HZ", _MODE_640x350_85HZ);
	}

#if 0//(Project_ID == ID_HUIXIONG_HK2513E02_HKC_PN238CT02_14_FHD75HZ_EDID_NEWSYNC_P240F_20211203) || (Project_ID
	if(ucModeIndex == _MODE_640x480_75HZ)
	{
		ucModeIndex = _MODE_640x480_75HZ;
		DebugMessageAnalog("Detected by Special Case to _MODE_640x480_75HZ", _MODE_640x480_75HZ);
	}
	DebugMessageOsd("1.NOW",ucModeIndex);
	DebugMessageOsd("1._MODE_640x480_75HZ",_MODE_640x480_75HZ);
	DebugMessageOsd("1._MODE_800x600_60HZ",_MODE_800x600_60HZ);
	DebugMessageOsd("1._MODE_800x600_75HZ",_MODE_800x600_75HZ);
#endif


#endif
	//DebugMessageOsd("0.ucModeIndex111", ucModeIndex);
	return ucModeIndex;
}


//--------------------------------------------------
// Description  : Check Load Mode Table Value
// Input Value  : None
// Output Value : _TURE -> Force Load Mode Table Value
//--------------------------------------------------
bit UserInterfaceGetLoadModeTableDefaultStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check VGA First Auto Config
// Input Value  : None
// Output Value : _TRUE => Do Auto Config
//--------------------------------------------------
bit UserInterfaceGetFirstAutoConfigStatus(void)
{
    if((GET_VGA_MODE_DO_FIRST_AUTO() == _TRUE) &&
       (GET_INPUT_TIMING_HWIDTH() > 600))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Percentage of AutoConfig
// Input Value  : Percentage
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetAutoConfigPercentage(BYTE ucAutoPercentage)
{
    ucAutoPercentage = ucAutoPercentage;
    g_usAdjustValue = ucAutoPercentage;
}

#if(_VGA_FORCE_DISPLAY == _ON)
//--------------------------------------------------
// Description  : VGA Mode Search User Flow
// Input Value  : None
// Output Value : Mode Number
//--------------------------------------------------
BYTE UserInterfaceModeSearchModeVGA(void)
{
    return 0;
}
#endif

//--------------------------------------------------
// Description  : VGA Auto Config Flow control for V position
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSkipAutoVpos(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : VGA Auto Config Flow control for H position
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSkipAutoHpos(void)
{
    return _FALSE;
}
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_MHL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User RCP Handler
// Input Value  : RCP Key Code
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceAdjustMHLMscRCPProc(BYTE ucKeyCode)
{
    // Check RCP Key Code
    switch(ucKeyCode)
    {
#if(_AUDIO_SUPPORT == _ON)
        case _MHL_RCP_VOLUME_UP:

            if(GET_OSD_VOLUME() < 100)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() + 1);
            }

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_VOLUME_DOWN:

            if(GET_OSD_VOLUME() > 0)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() - 1);
            }

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_MUTE:
        case _MHL_RCP_MUTE_FUNCTION:

            SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE());

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioMuteSwitch();
            }
            break;

        case _MHL_RCP_RESTORE_VOLUME_FUNCTION:

            SET_OSD_VOLUME(50);

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;
#endif

        default:
            return _FALSE;
    }

    return _TRUE;
}
#endif // End of #if(_MHL_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Decide whether to Enable FREESYNC Function
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
EnumFreeSyncSupport UserInterfaceGetFreeSyncEnable(EnumSourceSearchPort enumSourcePort)
{
    enumSourcePort = enumSourcePort;

#if((_FREESYNC_SUPPORT == _ON) || (_FREESYNC_II_SUPPORT == _ON))
    if(GET_OSD_FREE_SYNC_STATUS() == _TRUE)
    {
        return _FREESYNC_SUPPORT_ON;
    }
#endif
    return _FREESYNC_SUPPORT_OFF;
}

//--------------------------------------------------
// Description  : Decide whether to Enable ADAPTIVESYNC Function
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
EnumDpAdaptiveSyncSupport UserInterfaceGetDpAdaptiveSyncEnable(EnumSourceSearchPort enumSourcePort)
{
    enumSourcePort = enumSourcePort;

#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
    // if(GET_OSD_DP_ADAPTIVE_SYNC_STATUS() == _TRUE)
    {
        return _DP_ADAPTIVESYNC_SUPPORT_ON;
    }
#endif
    return _DP_ADAPTIVESYNC_SUPPORT_OFF;
}

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DP Version
// Input Value  : RCP Key Code
// Output Value : DP_VERSION_1_1 or DP_VERSION_1_2
//--------------------------------------------------
EnumDpVersionType UserInterfaceGetDPVersion(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D0)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_2)
            {
                return _DP_VERSION_1_2;
            }
            else if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_3)
            {
                return _DP_VERSION_1_4;
            }
            break;

#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D1)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_2)
            {
                return _DP_VERSION_1_2;
            }
            else if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_3)
            {
                return _DP_VERSION_1_4;
            }
            break;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            if(GET_OSD_DP_D2_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D1)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else if(GET_OSD_DP_D2_VERSION() == _DP_VER_1_DOT_2)
            {
                return _DP_VERSION_1_2;
            }
            else if(GET_OSD_DP_D2_VERSION() == _DP_VER_1_DOT_3)
            {
                return _DP_VERSION_1_4;
            }
            break;
#endif


#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:

            if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D6)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_2)
            {
                return _DP_VERSION_1_2;
            }
            else if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_3)
            {
                return _DP_VERSION_1_4;
            }
            break;
#endif
        default:

            break;
    }

    return _DP_VERSION_1_1;
}

//--------------------------------------------------
// Description  : Get DP Lane Count
// Input Value  : InputPort
// Output Value : DP Lane Count
//--------------------------------------------------
EnumDpLaneCount UserInterfaceGetDpLaneCount(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            return UserCommonNVRamGetSystemData(_DP_D0_LANES);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            return UserCommonNVRamGetSystemData(_DP_D1_LANES);
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:
            return UserCommonNVRamGetSystemData(_DP_D2_LANES);
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:
            return UserCommonNVRamGetSystemData(_DP_D6_LANES);
#endif

        default:
            break;
    }

    return _DP_LINK_4_LANE;
}

//--------------------------------------------------
// Description  : Get Dp MST Capable Port
// Input Value  : None
// Output Value : _DP_MST_RX0 or _DP_MST_RX1
//--------------------------------------------------
EnumDPMSTPort UserInterfaceGetDpMSTCapablePort(void)
{
#if(_DP_MST_SUPPORT == _OFF)

    return _DP_MST_NO_PORT;

#endif

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _OFF)
    if((SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT) && (GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())) == _PORT_DP))
#endif
    {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_MST_PORT_SUPPORT == _ON))
        if((GET_OSD_DP_MST() == _MST_D0) && (SysSourceGetInputPort() == _D0_INPUT_PORT))
        {
            if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX0_PORT;
            }
        }
        else
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_MST_PORT_SUPPORT == _ON))
        if((GET_OSD_DP_MST() == _MST_D1) && (SysSourceGetInputPort() == _D1_INPUT_PORT))
        {
            if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX1_PORT;
            }
        }
        else
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) &&\
    ((_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) && (_D0_DP_MST_PORT_SUPPORT == _ON)))
        if((GET_OSD_DP_MST() == _MST_D6) && (SysSourceGetInputPort() == _D6_INPUT_PORT))
        {
            if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX6_PORT;
            }
        }
        else
#endif

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
        if(GET_OSD_DP_MST() == _MST_AUTO)
        {
            return _DP_MST_AUTO_PORT;
        }
        else
#endif
        {
            return _DP_MST_NO_PORT;
        }
    }

    return _DP_MST_NO_PORT;
}

#if(_DP_MST_CAP_ON_INACTIVE_PORT_HPD_LOW == _ON)
//--------------------------------------------------
// Description  : Get Dp MST Target Port
// Input Value  : None
// Output Value : _DP_MST_RX0 or _DP_MST_RX1
//--------------------------------------------------
EnumDPMSTPort UserInterfaceGetDpMstTargetPort(void)
{
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_MST_PORT_SUPPORT == _ON))
    if(GET_OSD_DP_MST() == _MST_D0)
    {
        if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1)
        {
            return _DP_MST_NO_PORT;
        }
        else
        {
            return _DP_MST_RX0_PORT;
        }
    }
    else
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_MST_PORT_SUPPORT == _ON))
    if(GET_OSD_DP_MST() == _MST_D1)
    {
        if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1)
        {
            return _DP_MST_NO_PORT;
        }
        else
        {
            return _DP_MST_RX1_PORT;
        }
    }
    else
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) &&\
((_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) && (_D0_DP_MST_PORT_SUPPORT == _ON)))
    if(GET_OSD_DP_MST() == _MST_D6)
    {
        if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1)
        {
            return _DP_MST_NO_PORT;
        }
        else
        {
            return _DP_MST_RX6_PORT;
        }
    }
    else
#endif
    {
        return _DP_MST_NO_PORT;
    }

    return _DP_MST_NO_PORT;
}
#endif

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Decide whether to Clone output to DP Tx
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetDpCloneOutputStatus(void)
{
    if(GET_OSD_CLONE_MODE() == _OFF)
    {
        return _FALSE;
    }

    return _TRUE;
}
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) || (_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP))
//--------------------------------------------------
// Description  : User Select Externel DP Switch
// Input Value  : None
// Output Value : Only Return _Dx_INPUT_PORT Defined as DP Port
//--------------------------------------------------
BYTE UserInterfaceGetDpSwitchSelectPort(void)
{
    return _D0_INPUT_PORT;
}
#endif

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
//--------------------------------------------------
// Description  : User flow for embedded DP switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceEmbeddedDpSwitch(void)
{
    UserAdjustEmbeddedDpSwitch();
}
#endif

#if(_DP_DC_ON_HPD_CONTROL_BY_USER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DC On DP HPD Toggle Mode Control By User
// Input Value  : None
// Output Value : EnumDpHpdToggleMode
//--------------------------------------------------
EnumDpHpdToggleMode UserInterfaceGetDpDcOnHpdMode(void)
{
    return _DP_HPD_TOGGLE_NORMAL;
}
#endif

#endif // End of #if(_DP_SUPPORT == _ON)

#if((_D12_INPUT_PORT_TYPE == _D12_HDMI_PORT) && (_D12_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D3))
//--------------------------------------------------
// Description  : User Select Default Externel HDMI Switch Port
// Input Value  : None
// Output Value : Only Return _D3_INPUT_PORT or _D12_INPUT_PORT
//--------------------------------------------------
EnumSourceSearchPort UserInterfaceHdmiExternalSwitchDefaultPort(void)
{
    return _D3_INPUT_PORT;
}
#endif

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
//--------------------------------------------------
// Description  : User Report HDMI +5V Status
// Input Value  : D0/D1/D2 Port
// Output Value : _TURE --> +5V exist
//--------------------------------------------------
bit UserInterfaceGetHdmi5VStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _TRUE;
        case _D1_INPUT_PORT:
            return _TRUE;
        case _D2_INPUT_PORT:
            return _TRUE;
        case _D3_INPUT_PORT:
            return _TRUE;
        default:
            return _TRUE;
    }
}
#endif

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_EIZO_STYLE)
//--------------------------------------------------
// Description  : User check search is finish or not
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
bit UserInterfaceAdjustOsdCheckTotalSearchFinish(void)
{
    return _TRUE;
}

//--------------------------------------------------
// Description  : Determine the search time of each source
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustSourceSearchTime(void)
{
}

//--------------------------------------------------
// Description  : Determine the search time of each source
// Input Value  : Input Port Type
// Output Value : Search Reative Time
//--------------------------------------------------
WORD UserInterfaceAdjustSourceReactiveSearchTime(EnumSourceAdjustReactiveTimePortType enumSourceAdjustReactiveTimePortType)
{
    switch(enumSourceAdjustReactiveTimePortType)
    {
        case _ADJUST_PORT_VGA:

            return SEC(2);

        case _ADJUST_PORT_TMDS:

            return SEC(4.5);

        case _ADJUST_PORT_MHL:

            return SEC(6);

        case _ADJUST_PORT_DP:

            return SEC(4);

        default:

            return 0;
    }
}

//--------------------------------------------------
// Description  : User Report Eizo Search Finish Time
// Input Value  : None
// Output Value : Search Finish Time
//--------------------------------------------------
WORD UserInterfaceGetEizoSearchFinishTime(void)
{
    return 0;
}
#endif

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Determine whether to User is Ready to play audio
// Input Value  : None
// Output Value : _TRUE => Free to Play
//--------------------------------------------------
bit UserInterfaceGetAudioReadyToPlayStatus(void)
{
#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT != _ON)
    if(UserInterfaceGetAudioMuteStatus() != _ON)
#endif
    {
#if(_EMBEDDED_DAC_SUPPORT == _ON)
        if(ScalerAudioDACGetState() == _AUDIO_DAC_READY)
#endif
        {
#if(_LINE_IN_SUPPORT == _ON)
            if(UserInterfaceGetAudioSource() == _LINE_IN_AUDIO)
            {
#if(_SLEEP_AUDIO_SUPPORT == _ON)
                if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
                {
#if((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN))
                    return _TRUE;
#endif
                }
#endif
                if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
                   ((SysModeGetModeState() == _MODE_STATUS_DISPLAY_SETTING) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)))
                {
                    return _TRUE;
                }
            }
            else
#endif
            {
                if(UserInterfaceGetAudioSource() == _DIGITAL_AUDIO)
                {
                    if(ScalerAudioGetAudioDetected(SysSourceGetInputPort()) == _TRUE)
                    {
#if(_SLEEP_AUDIO_SUPPORT == _ON)
                        if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
                        {
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
                            if(ScalerAudioGetDigitalAudioSource(SysSourceGetInputPort()) == _DIGITAL_AUDIO_SOURCE_DP)
                            {
                                // When Fixed Port, should not play DP Audio at different port
                                if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetAudioPlaybackPort() == SysSourceGetInputPort()))
                                {
                                    return _TRUE;
                                }
                            }
#endif
                        }
#endif
                        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) || (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK))
                        {
                            return _TRUE;
                        }
                    }
                }
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : User OSD Get Audio Source
// Input Value  : None
// Output Value : _DIGITAL_AUDIO or _LINE_IN_AUDIO
//--------------------------------------------------
EnumAudioInputSource UserInterfaceGetAudioSource(void)
{
	return _DIGITAL_AUDIO; // liuxh  _DIGITAL_AUDIO

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable(SysSourceGetInputPort()) == _ENABLE)
    {
        return _DIGITAL_AUDIO;
    }
#endif

#if((_SLEEP_AUDIO_SUPPORT == _ON) && (_LINE_IN_SUPPORT == _ON) && (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN) && (_SWITCH_TO_LINE_IN_AUDIO_IN_POWER_SAVING_MODE == _ON))
    if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
    {
        return _LINE_IN_AUDIO;
    }
#endif

    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
        case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
        case _D1_INPUT_PORT:
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
        case _D2_INPUT_PORT:
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
        case _D3_INPUT_PORT:
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
        case _D4_INPUT_PORT:
#endif

#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
        case _D5_INPUT_PORT:
#endif

#if(_LINE_IN_SUPPORT == _ON)
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            if(UserInterfaceGetAudioStandAloneStatus() == _FALSE)
#endif
            {
                // Don't switch audio source if input source is not found
                if(SysSourceGetSourceType() == _SOURCE_NONE)
                {
                    return ScalerAudioGetInputSource();
                }
            }

            return _LINE_IN_AUDIO;
#else
            return _NO_AUDIO_SOURCE;
#endif // End of #if(_LINE_IN_SUPPORT == _ON)

        default:

#if(_LINE_IN_SUPPORT == _ON)
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            // Don't Switch Audio Source if Line In is Currently Playing unless Digital Source is found
            if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
            {
                if((SysSourceGetSourceType() == _SOURCE_NONE) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (ScalerAudioGetInputSource() == _LINE_IN_AUDIO))
                {
                    return _LINE_IN_AUDIO;
                }
            }
#endif
            return GET_OSD_AUDIO_SOURCE();
#else
            return _DIGITAL_AUDIO;
#endif // End of #if(_LINE_IN_SUPPORT == _ON)
    }
}

//--------------------------------------------------
// Description  : Get Current Audio Mute Status
// Input Value  : Node
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioMuteStatus(void)
{
    return GET_OSD_VOLUME_MUTE();
}

//--------------------------------------------------
// Description  : User Decide whether to play non-LPCM Audio
// Input Value  : None
// Output Value : _ON => Mute Audio
//--------------------------------------------------
EnumAudioCodingType UserInterfaceGetAudioNonLPCMStatus(void)
{
    if(ScalerAudioLPCMCheckData() == _TRUE)
    {
#if(_HDMI_SUPPORT == _ON)
        if(ScalerAudioDigitalAudioSourceType() == _SOURCE_HDMI)
        {
            if(ScalerAudioLPCMCheckInfo() == _TRUE)
            {
                return _AUDIO_LPCM;
            }
            else
            {
                return _AUDIO_NON_LPCM;
            }
        }
#endif
        return _AUDIO_LPCM;
    }

    return _AUDIO_NON_LPCM;
}

//--------------------------------------------------
// Description  : User Decide whether to Mute Audio
// Input Value  : None
// Output Value : _AUDIO_NON_LPCM => Mute Audio
//--------------------------------------------------
EnumAudioMuteStatus UserInterfaceAudioGetOutputMuteStatus(void)
{
    if(UserInterfaceGetAudioNonLPCMStatus() == _AUDIO_NON_LPCM)
    {
        return _AUDIO_MUTE_ON;
    }
    else
    {
        return _AUDIO_MUTE_OFF;
    }
}

//--------------------------------------------------
// Description  : Get Current Audio Volume
// Input Value  : None
// Output Value : Current Volume
//--------------------------------------------------
WORD UserInterfaceGetAudioVolume(void)
{
    return UserAdjustAudioVolumeMapping(GET_OSD_VOLUME());
}

//--------------------------------------------------
// Description  : Get User Define Audio Sampling Freq when no Audio
// Input Value  : None
// Output Value : EnumAudioSamplingFreqType
//--------------------------------------------------
EnumAudioSamplingFreqType UserInterfaceAudioGetUserSamplingFreq(void)
{
    return _AUDIO_FREQ_48K;
}

#if(_DP_SUPPORT == _ON)
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get User Define Dp Audio Capability Initial State
// Input Value  : Input Port
// Output Value : EnumAudioDpDpcdSupport
//--------------------------------------------------
EnumAudioDpDpcdSupport UserInterfaceAudioDpGetCapabilityInitialState(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
            return _AUDIO_DP_DPCD_SUPPORT;

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return _AUDIO_DP_DPCD_SUPPORT;

            break;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            return _AUDIO_DP_DPCD_SUPPORT;

            break;
#endif

        default:

            break;
    }

    return _AUDIO_DP_DPCD_SUPPORT;
}
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DAC Output Switch
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void)
{
	//BYTE i = 0;
	//i = PCB_HEADPHONE_DETECT();

#if(_BOARD_LINE_IN == _ON)
		return _AUDIO_DAC_OUTPUT_SPEAKER;	
#endif

return _AUDIO_DAC_OUTPUT_HEADPHONE; 

#if 0//(_DEF_AUDIO_SELECT)
		if(GET_OSD_AUDIO_SELECT() == _OFF)	//�����豸ѡ������
		{
			return _AUDIO_DAC_OUTPUT_SPEAKER;	
		}
		else	//�����豸ѡ�����
		{
			return _AUDIO_DAC_OUTPUT_HEADPHONE; 
		}
#endif

		if(PCB_HEADPHONE_DETECT() == _HEADPHONE_DISCONNECT)
		{
			return _AUDIO_DAC_OUTPUT_SPEAKER;	
		}
		else if(PCB_HEADPHONE_DETECT() == _HEADPHONE_CONNECT)
		{
			return _AUDIO_DAC_OUTPUT_HEADPHONE; 
		}
		
			return _AUDIO_DAC_OUTPUT_HEADPHONE;	
}


//--------------------------------------------------
// Description  : Get if Keep Audio Depop State
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceGetAudioDACKeepDepopState(void)
{
    return _FALSE;
}
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Current Audio Stand Alone Status
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioStandAloneStatus(void)
{
    return GET_OSD_AUDIO_STAND_ALONE();
}
#endif

//--------------------------------------------------
// Description  : User Audio Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAudioResetProc(void)
{
#if(_SLEEP_AUDIO_SUPPORT == _ON)
    if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
    {
        // if Currently playing digital audio
        if((SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (UserInterfaceGetAudioSource() == _DIGITAL_AUDIO))
        {
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if(SysSourceGetAudioPlaybackPort() != SysSourceGetInputPort())
#endif
            {
                DebugMessageAudio("User Audio Reset Process", 0x00);

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
                SysAudioOutputProc(_DISABLE);
#else
                SysAudioMuteProc(_ON);
#endif
                ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
                ScalerTimerDelayXms(3);
                // RX Digital Audio Output Control
                ScalerAudioDigitalOutputMute(_ON);
#endif

                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
            }
        }
    }
    else
#endif
    {
        if(SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)
        {
            DebugMessageAudio("User Audio Reset Process", 0x00);

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
            SysAudioOutputProc(_DISABLE);
#else
            SysAudioMuteProc(_ON);
#endif
            ScalerAudioDigitalReset(ScalerAudioGetDigitalAudioPortMapping());

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
            ScalerTimerDelayXms(3);
            // RX Digital Audio Output Control
            ScalerAudioDigitalOutputMute(_ON);
#endif
            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
        }
    }
}

//--------------------------------------------------
// Description  : Audio Power Process
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
void UserInterfaceAdjustAudioPowerProc(EnumPowerStatus enumPowStatus)
{
    if(enumPowStatus == _POWER_STATUS_NORMAL)
    {
        // Add User interface function

    }
    else if(enumPowStatus == _POWER_STATUS_SAVING)
    {
        // Add User interface function
    }
    else
    {
        // Add User interface function
    }
}

//--------------------------------------------------
// Description  : Control User Audio Mute Process
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAudioAmpMuteProc(bit bMute)
{
	if(bMute)
		bMute = _AMP_MUTE_ON;
	else
		bMute = _AMP_MUTE_OFF;	

#if(_EMBEDDED_DAC_SUPPORT == _ON)
	if((UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_BOTH) || (UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_SPEAKER))
	{
		PCB_AMP_MUTE(bMute);
	}
#endif
}


#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Control User Audio Fast Mute Process
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAudioAmpFastMuteProc(bit bMute)
{
    bMute = bMute;

#if(_EMBEDDED_DAC_SUPPORT == _ON)
#if((_DAC_SPEAKER_OUTPUT_SUPPORT == _ON) && (_DAC_HP_OUTPUT_SUPPORT == _ON))
    if(UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_BOTH)
#elif(_DAC_SPEAKER_OUTPUT_SUPPORT == _ON)
    if(UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_SPEAKER)
#elif(_DAC_HP_OUTPUT_SUPPORT == _ON)
    if(UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_HEADPHONE)
#endif
    {
        // External Amp Fast Mute
        PCB_AMP_MUTE((bMute == _ON) ? _AMP_MUTE_ON : _AMP_MUTE_OFF);
        DebugMessageAudio("[Ext.Amp]FastMuteProc", bMute);
    }
#endif
}
#endif

#if(_AUDIO_OSD_MUTE_SEPARATE_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Control User Audio Mute DSP Process
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void UserInterfaceAudioExternalCodecProc(bit bEnable)
{
    if(bEnable == _DISABLE)
    {
        // Mute On External DSP
    }
    else
    {
        // Mute Off External DSP
    }
    DebugMessageAudio("[Ext.Codec]NormalProc", bEnable);
}

#if(_AUDIO_DVC_FAST_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Control User Audio Mute DSP Fast Process
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void UserInterfaceAudioExternalCodecFastProc(bit bEnable)
{
    if(bEnable == _DISABLE)
    {
        // Mute On External DSP
    }
    else
    {
        // Mute Off External DSP
    }
    DebugMessageAudio("[Ext.Codec]FastProc", bEnable);
}
#endif
#endif

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
//--------------------------------------------------
// Description  : Swap External Audio Codec Input for Line in
// Input Value  : _TRUE or _FALSE
// Output Value : None
//--------------------------------------------------
void UserInterfaceSwapExternalAudioCodecInput(bit bSwap)
{
    if(bSwap == _TRUE)
    {
        // Swap External Audio Codec Input(L/R)
    }
    else
    {
        // No Swap External Audio Codec Input(L/R)
    }
}
#endif

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
//--------------------------------------------------
// Description  : Determine TTS is support or not
// Input Value  : None
// Output Value : _TRUE => TTS Support
//--------------------------------------------------
bit UserInterfaceAudioGetTtsSupport(void)
{
    return GET_OSD_AUDIO_TTS_SUPPORT();
}

//--------------------------------------------------
// Description  : Determine Audio Volume when TTS is play
// Input Value  : None
// Output Value : ucAudioVolume
//--------------------------------------------------
BYTE UserInterfaceAudioGetTtsPlayAudioVolume(void)
{
    return GET_OSD_AUDIO_TTS_AUDIO_VOLUME();
}

//--------------------------------------------------
// Description  : Determine TTS Volume when TTS is play
// Input Value  : None
// Output Value : ucAudioVolume
//--------------------------------------------------
BYTE UserInterfaceAudioGetTtsPlayTextVolume(void)
{
    return GET_OSD_AUDIO_TTS_TEXT_VOLUME();
}

//--------------------------------------------------
// Description  : Determine TTS is Ready for Play or not
// Input Value  : None
// Output Value : _TRUE => TTS Play Ready
//--------------------------------------------------
bit UserInterfaceAudioGetTtsAudioReady(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(ScalerAudioDACGetState() != _AUDIO_DAC_READY)
    {
        return _FALSE;
    }
#endif

    return _TRUE;
}
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#if(_INTERNAL_AUDIO_CHANNEL_CONFIG_BY_USER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get User Define Audio Gen Freq
// Input Value  : None
// Output Value : 500 ~ 3000Hz
//--------------------------------------------------
EnumAudioInternalGenFreq UserInterfaceAudioGetUserDefineAudioGenFreq(void)
{
    // 1000Hz
    return _AUDIO_GEN_FREQ_1000HZ;
}

//--------------------------------------------------
// Description  : Get User Select R/L Channel
// Input Value  : None
// Output Value : 500 ~ 3000Hz
//--------------------------------------------------
EnumAudioLeftRightChannelSelect UserInterfaceAudioGetUserLeftRightChanelSelect(void)
{
    return _AUDIO_LEFT_RIGHT_CHANNEL;
}
#endif
#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON) || (_UNIFORMITY_SUPPORT == _ON))
//--------------------------------------------------
// Description  : User function Before Calibration Start
// Input Value  : EnumCaliType
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustBeforeDisplayCalibration(EnumCaliType enumMode)
{
    if(enumMode == _UNIFORMITY_CAL)// for Uniformity
    {
        UserAdjustBacklight(GET_OSD_BACKLIGHT());
    }
    else // OGC/OCC/DICOM
    {
    }
}

//--------------------------------------------------
// Description  : User function After Calibration Start
// Input Value  : EnumCaliType
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAfterDisplayCalibration(EnumCaliType enumMode)
{
    if(enumMode == _UNIFORMITY_CAL)// for Uniformity
    {
        UserAdjustBacklight(GET_OSD_BACKLIGHT());
    }
    else // OGC/OCC/DICOM
    {
    }
}
//--------------------------------------------------
// Description  : User function Backlight Adjust for Calibration
// Input Value  : 0(Min Backlight) ~ 255(Max Backlight)
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustBacklight(BYTE ucBacklight)
{
#if(_BACKLIGHT_PWM_INVERSE == _ON)
	//ucBacklight = 255 - ucBacklight;
#endif
	ucBacklight=ucBacklight;

	//UserAdjustBacklight(_BACKLIGHT_MAX_HDR);

	UserAdjustBacklight(GET_OSD_BACKLIGHT());

    //UserAdjustBacklight(_BACKLIGHT_MIN + ((DWORD)(_BACKLIGHT_MAX - _BACKLIGHT_MIN) * ucBacklight) / 255);
}
#endif

#if(_BACKLIGHT_DIMMING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User function Before Calibration Start
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustBeforeDimmingCalibration(void)
{
}

//--------------------------------------------------
// Description  : User function After Calibration Start
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAfterDimmingCalibration(void)
{
}
#endif

#if(_LD_HDR10_BOOST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User function For LD Boost White Pattern
// Input Value  : _ON/_OFF
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustLDBoostCalibration(bit bBoost)
{
    BYTE ucBoostGain = (DWORD)_LOCAL_DIMMING_MAXCLL * 100 / _LOCAL_DIMMING_MAXFALL;
    WORD usBoostPWM = (DWORD)_DEVICE_LED_DRIVER_PWM_MAX * ucBoostGain / 100;

    if(bBoost == _ON) // turn on boost
    {
        ExternalDeviceInterfaceLedDriverPwm(_DEVICE_LED_DRIVER_PWM_ALL, usBoostPWM, _DEVICE_CALI_ON);
    }
    else // turn off boost
    {
        ExternalDeviceInterfaceLedDriverPwm(_DEVICE_LED_DRIVER_PWM_ALL, _DEVICE_LED_DRIVER_PWM_MAX, _DEVICE_CALI_ON);
    }
}
#endif

#if(_YPEAKING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Ypeaking Table
// Input Value  : Request Ypeaking Table
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustYpeaking(void)
{
#if(_ULTRA_VIVID_SUPPORT == _ON)
    switch(GET_OSD_ULTRA_VIVID_STATUS())
    {
        case _ULTRA_VIVID_L:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x0E, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;

        case _ULTRA_VIVID_M:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x41, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;

        case _ULTRA_VIVID_H:
        default:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x7E, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;
    }
#else
    // ScalerColorYpeakingAdjust(_YPEAKING_TABLE_MODE, 0x00, _YPEAKING_NO_DIV, tYPEAKING_TABLE[0], _YPEAKING_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
    ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x41, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
#endif
}
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
//--------------------------------------------------
// Description  : Get DDC-CI Mode
// Input Value  : None
// Output Value : EnumDDCCIDebugMode:_DEBUG_MODE / _DDCCI_MODE
//--------------------------------------------------
EnumDDCCIDebugMode UserInterfaceGetDdcciMode(void)
{
    return GET_OSD_DDCCI_STATUS();
}

//--------------------------------------------------
// Description  : Get Repeater Into Power Off Status
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
EnumDataExchangeRepeaterPowerState UserInterfaceGetRepeaterIntoPowerOff(void)
{
    return _DATA_EXCHANGE_REPEATER_POWER_NORMAL;
}
#endif

#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
//--------------------------------------------------
// Description  : GET AIO Modern Standby Mode Status
// Input Value  : None
// Output Value : EnumDDCCIDebugMode:_DEBUG_MODE / _DDCCI_MODE
//--------------------------------------------------
EnumAIOModernStandbyMode UserInterfaceGetAIOModernStandbyMode(void)
{
    return _AIO_MODERN_STANDBY_MODE_DISABLE;
}
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp FreeSync Get IVFmax From Look Up Table
// Input Value  : IVF(unit: 0.1Hz)
// Output Value : _DP_FREESYNC_WITH_IVF_MAX: Get IVF
//--------------------------------------------------
EnumDrrFreeSyncDpGetIVF UserInterfaceDisplayDpFreeSyncGetIVFmaxFromLut(WORD *pusVfreqMax)
{
    BYTE ucIndex = 0;
    WORD usPixelClk = ScalerSyncGetInputPixelClk();
    WORD usRefHtotalHBound = 0;
    WORD usRefHtotalLBound = 0;
    WORD usPixelClkHBound = usPixelClk;
    WORD usPixelClkLBound = usPixelClk;

    // Htotal margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_HTOTAL_MARGIN * GET_INPUT_TIMING_HTOTAL() / 100);
    usRefHtotalHBound = (GET_INPUT_TIMING_HTOTAL() + PDATA_WORD(0));
    usRefHtotalLBound = (GET_INPUT_TIMING_HTOTAL() - PDATA_WORD(0));

    // Pixel clk margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_CLK_MARGIN * usPixelClk / 100);
    usPixelClkHBound += PDATA_WORD(0);
    usPixelClkLBound -= PDATA_WORD(0);

    for(ucIndex = 0; ucIndex < (sizeof(tDrrFreeSyncDpTimingInfo) / sizeof(tDrrFreeSyncDpTimingInfo[0])); ucIndex++)
    {
        if((GET_DP_FREESYNC_IHWIDTH(ucIndex) == GET_INPUT_TIMING_HWIDTH()) && (GET_DP_FREESYNC_IVHEIGHT(ucIndex) == GET_INPUT_TIMING_VHEIGHT()) &&
           ((GET_DP_FREESYNC_IHTOTAL(ucIndex) <= usRefHtotalHBound) && (GET_DP_FREESYNC_IHTOTAL(ucIndex) >= usRefHtotalLBound)) &&
           ((GET_DP_FREESYNC_ICLK(ucIndex) <= usPixelClkHBound) && (GET_DP_FREESYNC_ICLK(ucIndex) >= usPixelClkLBound)))
        {
            *pusVfreqMax = GET_DP_FREESYNC_IVFREQ(ucIndex);

            DebugMessageScaler("ucIndex if Drr user define timing ", ucIndex);
            return _DP_FREESYNC_WITH_IVF_MAX;
        }
    }

    *pusVfreqMax = 0;
    return _DP_FREESYNC_WITHOUT_IVF_MAX;
}
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI FreeSync Get IVFmax From Look Up Table
// Input Value  : IVF(unit: 0.1Hz)
// Output Value : _HDMI_FREESYNC_WITH_IVF_MAX: Get IVF
//--------------------------------------------------
EnumDrrFreeSyncHdmiGetIVF UserInterfaceDisplayHdmiFreeSyncGetIVFmaxFromLut(WORD *pusVfreqMax)
{
    BYTE ucIndex = 0;
    WORD usPixelClk = ScalerSyncGetInputPixelClk();
    WORD usRefHtotalHBound = 0;
    WORD usRefHtotalLBound = 0;
    WORD usPixelClkHBound = usPixelClk;
    WORD usPixelClkLBound = usPixelClk;

    // Htotal margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_HTOTAL_MARGIN * GET_INPUT_TIMING_HTOTAL() / 100);
    usRefHtotalHBound = (GET_INPUT_TIMING_HTOTAL() + PDATA_WORD(0));
    usRefHtotalLBound = (GET_INPUT_TIMING_HTOTAL() - PDATA_WORD(0));

    // Pixel clk margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_CLK_MARGIN * usPixelClk / 100);
    usPixelClkHBound += PDATA_WORD(0);
    usPixelClkLBound -= PDATA_WORD(0);

    for(ucIndex = 0; ucIndex < (sizeof(tDrrFreeSyncHdmiTimingInfo) / sizeof(tDrrFreeSyncHdmiTimingInfo[0])); ucIndex++)
    {
        if((GET_HDMI_FREESYNC_IHWIDTH(ucIndex) == GET_INPUT_TIMING_HWIDTH()) && (GET_HDMI_FREESYNC_IVHEIGHT(ucIndex) == GET_INPUT_TIMING_VHEIGHT()) &&
           ((GET_HDMI_FREESYNC_IHTOTAL(ucIndex) <= usRefHtotalHBound) && (GET_HDMI_FREESYNC_IHTOTAL(ucIndex) >= usRefHtotalLBound)) &&
           ((GET_HDMI_FREESYNC_ICLK(ucIndex) <= usPixelClkHBound) && (GET_HDMI_FREESYNC_ICLK(ucIndex) >= usPixelClkLBound)))
        {
            *pusVfreqMax = GET_HDMI_FREESYNC_IVFREQ(ucIndex);

            DebugMessageScaler("ucIndex if Drr user define timing ", ucIndex);
            return _HDMI_FREESYNC_WITH_IVF_MAX;
        }
    }

    *pusVfreqMax = 0;
    return _HDMI_FREESYNC_WITHOUT_IVF_MAX;
}
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI VRR Get IVFmax From Look Up Table
// Input Value  : IVF(unit: 0.1Hz)
// Output Value : _HDMI_VRR_WITH_IVF_MAX: Get IVF
//--------------------------------------------------
EnumDrrVrrHdmiGetIVF UserInterfaceDisplayHdmiVrrGetIVFmaxFromLut(WORD *pusVfreqMax)
{
    BYTE ucIndex = 0;
    WORD usPixelClk = ScalerSyncGetInputPixelClk();
    WORD usRefHtotalHBound = 0;
    WORD usRefHtotalLBound = 0;
    WORD usPixelClkHBound = usPixelClk;
    WORD usPixelClkLBound = usPixelClk;

    // Htotal margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_HTOTAL_MARGIN * GET_INPUT_TIMING_HTOTAL() / 100);
    usRefHtotalHBound = (GET_INPUT_TIMING_HTOTAL() + PDATA_WORD(0));
    usRefHtotalLBound = (GET_INPUT_TIMING_HTOTAL() - PDATA_WORD(0));

    // Pixel clk margin
    PDATA_WORD(0) = ((DWORD)_USER_DRR_CLK_MARGIN * usPixelClk / 100);
    usPixelClkHBound += PDATA_WORD(0);
    usPixelClkLBound -= PDATA_WORD(0);

    for(ucIndex = 0; ucIndex < (sizeof(tDrrVrrHdmiTimingInfo) / sizeof(tDrrVrrHdmiTimingInfo[0])); ucIndex++)
    {
        if((GET_HDMI_VRR_IHWIDTH(ucIndex) == GET_INPUT_TIMING_HWIDTH()) && (GET_HDMI_VRR_IVHEIGHT(ucIndex) == GET_INPUT_TIMING_VHEIGHT()) &&
           ((GET_HDMI_VRR_IHTOTAL(ucIndex) <= usRefHtotalHBound) && (GET_HDMI_VRR_IHTOTAL(ucIndex) >= usRefHtotalLBound)) &&
           ((GET_HDMI_VRR_ICLK(ucIndex) <= usPixelClkHBound) && (GET_HDMI_VRR_ICLK(ucIndex) >= usPixelClkLBound)))
        {
            *pusVfreqMax = GET_HDMI_VRR_IVFREQ(ucIndex);

            DebugMessageScaler("ucIndex if Drr user define timing ", ucIndex);
            return _HDMI21_VRR_WITH_IVF_MAX;
        }
    }

    *pusVfreqMax = 0;
    return _HDMI21_VRR_WITHOUT_IVF_MAX;
}
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Hdmi Panel Index
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceFreeSyncGetHdmiAupiPanelInfo(StructDrrAmdAupiInfo *pstDrrHdmiAmdAupiInfo)
{
    pstDrrHdmiAmdAupiInfo->ucPanelManufactureIdL = 0x00;
    pstDrrHdmiAmdAupiInfo->ucPanelManufactureIdM = 0x00;
    pstDrrHdmiAmdAupiInfo->ucPanelIdL = 0x00;
    pstDrrHdmiAmdAupiInfo->ucPanelIdM = 0x00;
    pstDrrHdmiAmdAupiInfo->ucFwCheckSumL = 0x00;
    pstDrrHdmiAmdAupiInfo->ucFwCheckSumM = 0x00;
    pstDrrHdmiAmdAupiInfo->ucScalerDeviceIdL = 0x00;
    pstDrrHdmiAmdAupiInfo->ucScalerDeviceIdM = 0x00;
}
#endif
#endif


//--------------------------------------------------
// Description  : Color Format Convert for RGB/YUV
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceColorFormatConvert(void)
{
	UserInterfaceGetColorFormat();

#if(_COLOR_FORMAT_CONVERT == _ON)
#if((_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_0) || (_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_1) || (_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_2))
	ScalerColorSpaceConvertLoadTable();
#endif
#endif

	// Color Sampling
    //ScalerColor422To444();

	SysModeColorSpaceConvert(UserCommonInterfaceGetColorFormat(), _DB_APPLY_POLLING);
}

#if(_MPRT_SUPPORT == _ON)
#define _MPRT_ADJUST_LEVEL                                    	40
extern void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
extern void ScalerTconGlobalEnable(bit bEnable);
extern void UserAdjustOverDrive1ms(void);

void UserAdjustMPRTFuntion(bit bStatus) 
{	
   WORD usTemp = 0;
   
   if(GET_OSD_LOGO_ON() == _ON)
   {
	   bStatus = _OFF;
   }

#if(_HDR10_SUPPORT == _ON)
//	 if(GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)
	 if(UserCommonHDRGetHDR10Status() == _HDR10_ON)

   {
		  bStatus = _OFF;
   }
#endif

   if((bStatus == _ON) && (SysModeGetModeState() ==_MODE_STATUS_ACTIVE)&&(GET_INPUT_TIMING_VFREQ()> _MPRT_MIN_FRAME_RATE) && (GET_OSD_FREE_SYNC_STATUS() == _OFF))
   {	

		  UserAdjustBacklight(GET_OSD_BACKLIGHT());

		  // set GPIO pin = TCON output
		  PCB_MPRT_TCON_PIN_SHARE_CONFIG(_ON);  //��������?

		  // Set TCON on
		  ScalerTconGlobalEnable(_ON);
		  
		  PCB_MPRT_TCON_ENABLE(_ON);

		  // Set TCON Inverted output
		  PCB_MPRT_TCON_INVERTED_OUTPUT();

		  // Set TCON PWM		 

#if(_PCB_TYPE==_RL6449_216PIN_HK_M_RTD2775E15_1DP2H_eDPVB1)
			g_MPRTValue = (DWORD)GET_MDOMAIN_OUTPUT_VTOTAL()*_MPRT_ADJUST_LEVEL/100;

			ScalerTimerWaitForEvent(_EVENT_DVS);

			PCB_MPRT_TCON_PWM_ADJUST(0+_MPRT_OFFSET, g_MPRTValue+_MPRT_OFFSET);

#else
			g_MPRTValue = (DWORD)(GET_MDOMAIN_OUTPUT_VBSTART() + GET_MDOMAIN_OUTPUT_VBHEIGHT())*_MPRT_ADJUST_LEVEL/100;

			ScalerTimerWaitForEvent(_EVENT_DVS);

			PCB_MPRT_TCON_PWM_ADJUST();

#endif



		 // PCB_MPRT_CURRENT_CONTROL(_MPRT_CURRENT_SWITCH_ON);
   }
   else
   {

#if 0//(_OD_SUPPORT == _ON)
		   if(GET_OSD_OD_MODE() != _OFF)
		   {
			   SET_OSD_OD_MODE(_OFF);
			   UserAdjustOverDrive();
		   }
#endif
   
		 // PCB_MPRT_CURRENT_CONTROL(_MPRT_CURRENT_SWITCH_OFF);
		  
		  // Set TCON off
		  PCB_MPRT_TCON_ENABLE(_OFF);
		  ScalerTconGlobalEnable(_OFF);

		  // set GPIO pin = PP output
		  PCB_MPRT_TCON_PIN_SHARE_CONFIG(_OFF);

#if 0//(_DEF_Panel_Back_Bug)
		  // set GPIO output level = Hi
		  PCB_MPRT_GPIO_CONTROL(_MPRT_GPIO_ON);
#endif
		  UserAdjustBacklight(GET_OSD_BACKLIGHT());
   }

#if(_OD_SUPPORT == _ON)
	UserAdjustOverDrive1ms();
#endif

   
}

#endif

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
// void UserAdjustMPRTStatus(void)
// {
// 	BYTE tempItem = g_usAdjustValue;

// 	if(g_usBackupValue != tempItem)
// 	{
// 		//OsdDisplaySelectedItem(_OFF);
// 		SET_OSD_MPRT_STATUS(tempItem);
// 		g_usBackupValue = GET_OSD_MPRT_STATUS();

// 		if(GET_OSD_MPRT_STATUS())
// 		{
// 			SET_OSD_ECO_STATUS(_ECO_STANDARD);	//����ģʽ�ָ���׼

// 			//DDCCI����
// 			SET_OSD_DDCCI_STATUS(_OFF);
// #if(_FREESYNC_SUPPORT == _ON)			
// 			if((GET_OSD_DDCCI_STATUS() == _OFF) && (SysSourceGetSourceType() == _SOURCE_HDMI) && (GET_OSD_FREE_SYNC_STATUS() == _ON))
// 			{
// 				SET_OSD_FREE_SYNC_STATUS(_OFF);
// 				UserCommonInterfaceFreeSyncSupportSwitch();
// 			}
// #endif

// #if(_OD_SUPPORT == _ON)
// 		   if(GET_OSD_OD_STATUS() != _OD_ADVANCED)
// 		   {
// 			   SET_OSD_OD_STATUS(_OD_ADVANCED);
// 			   UserAdjustOverDrive();
// 		   }
// #endif

// 		}
// 		else
// 		{
// 			SET_OSD_DDCCI_STATUS(_ON);

			
// #if(_OD_SUPPORT == _ON)
// 		   if(GET_OSD_OD_STATUS() != _OFF)
// 		   {
// 			   SET_OSD_OD_STATUS(_OFF);
// 			   UserAdjustOverDrive();
// 		   }
// #endif

// 		}
// 		ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());



// 		if(GET_OSD_DCR_STATUS() != _DCR_Level_0)
// 		{
// 			SET_OSD_DCR_STATUS(_OFF);
// 			//UserAdjustUltraVivid();
// 			//RTDNVRamSaveSceneModeData(GET_OSD_GAME_MODE());
// 		}


// 		UserAdjustMPRTFuntion(GET_OSD_MPRT_STATUS());

		
// 		if(GET_OSD_MPRT_STATUS() == _OFF)
// 		{
// 			UserAdjustBacklight(GET_OSD_BACKLIGHT());	//���Ȼָ�
// 		}

// 		//OsdFunRestrictRefresh();	//���ù���ˢ��
// 		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
//     }
// }
// #endif


#if(_HDR10_SUPPORT == _ON)
extern void UserAdjustUltraVivid(void);

void OsdHDRFunOnRestrict(void)
{
	BYTE save_i_num = 0;
	BYTE save_Vie_i_num = 0;

	if(GET_OSD_D0_COLORSPACE_TYPE())
	{
		SET_OSD_D0_COLORSPACE_TYPE(_SPACE_AUTO);
		UserInterfaceColorFormatConvert();
		save_i_num = 1; 
	}
	
	if(GET_OSD_VIEWMODE_TYPE() == _VM_STANDARD)
	{
		if(GET_COLOR_TEMP_TYPE() != _COLORTEMP_DEFAULT)
		{
			SET_COLOR_TEMP_TYPE(_COLORTEMP_DEFAULT);
			save_Vie_i_num = 1;
		}
	}

	if(GET_OSD_ECO_STATUS() != _ECO_DEFAULT)
	{
		SET_OSD_ECO_STATUS(_ECO_DEFAULT);
		UserAdjustBacklight(GET_OSD_BACKLIGHT());
	}

	if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
	{
		SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
		save_i_num = 1;
	}

	if(GET_OSD_SHARPNESS() != _SHARPNESS_DEFAULT)	
	{
		SET_OSD_SHARPNESS(_SHARPNESS_DEFAULT);
		UserCommonAdjustSharpness(SysSourceGetInputPort());
		save_i_num = 1;
	}

#if 0
	if(GET_OSD_OD_MODE() != _OD_DEFAULT)	
	{
		SET_OSD_OD_MODE(_OD_DEFAULT);
		SET_BACKUP_OD_MODE(GET_OSD_OD_MODE());
		UserAdjustOverDrive();
		save_i_num = 1;
	}
#endif
	
	if(GET_OSD_VIEWMODE_TYPE() != _VM_STANDARD)	
	{
		SET_OSD_GAME_MODE(_GM_OFF);
		SET_OSD_VIEWMODE_TYPE(_VM_STANDARD);
		save_i_num = 1;
	}

#if 0
	if(GET_OSD_VIEWMODE_TYPE() != _VM_STANDARD)
	{
		SET_OSD_GAME_MODE(_GM_OFF);
		SET_OSD_VIEWMODE_TYPE(_VM_STANDARD);
		UserAdjustViewModeFun();
		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	}
#endif

#if(_MPRT_SUPPORT)
	if(GET_OSD_MPRT_STATUS())
	{
		SET_OSD_MPRT_STATUS(_OFF);
		UserAdjustMPRTFuntion(GET_OSD_MPRT_STATUS());
		save_i_num = 1; 
	}
#endif

	if(GET_OSD_VIEWMODE_TYPE()!=_VM_STANDARD )
	{
		SET_OSD_VIEWMODE_TYPE(_VM_STANDARD);
		SET_OSD_GAME_MODE(_GM_OFF);
		//RTDNVRamLoadSceneModeData(GET_OSD_GAME_MODE()); //���¶�Ӧ�ṹ��
		//RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());	//����ɫ��
		save_i_num = 1; 
	}

	if(GET_OSD_DCR_STATUS() > _DCR_MIN)
	{
		SET_OSD_DCR_STATUS(_DCR_MIN);
		UserAdjustUltraVivid();
		
		UserAdjustBacklight(100);	
		save_Vie_i_num = 1;
	}
	

	if(save_i_num)
	{
		ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_OSD_DATE);
		save_i_num = 0;
	}
	
	if(save_Vie_i_num)
	{
		ScalerTimerReactiveTimerEvent(SEC(1),_USER_TIMER_EVENT_SAVE_SCENEMODE_DATA);
		save_Vie_i_num = 0;
	}

	return;
}

#endif

#if _EYE_VLI_SUPPORT
void ScalerEyeProtectEventProc(void)
{
    BYTE ret = 0;
    WORD lum = 0;
    g_ucTimerCount_EyeProtect++;

    #if(_SW_IIC_SUPPORT == _ON)
    #if (_LS_PS_SUPPORT == _ON)
    if(GET_OSD_AI_EYE_PROTECTION_STATUS()||GET_OSD_AI_LOW_POWER_STATUS())
    {
        ret = ScalerMcuGetPSData();
        DebugMessageSystem("distance------------------",ret);
    }
    if(GET_OSD_AI_EYE_PROTECTION_STATUS()||GET_OSD_AI_LIGHT_ADAPTIVATION_STATUS())
    {
        lum = ScalerMcuALSDataHanlder();
        DebugMessageSystem("Auto light",lum);
    }
    #endif
    #endif

    #if(_AI_LOW_POWER == _ON)
    if(GET_OSD_AI_LOW_POWER_STATUS())
    {
        if(ret >= PS_MAX_DIS)//distance is over(no user)
        {
            g_ucTimer_Distance++;
        }
        else
        {
            if(bAI_LowPower_Status)
            {
                UserAdjustBacklight(GET_OSD_BACKLIGHT());
                bAI_LowPower_Status = 0;
            }
            if(g_ucTimer_Distance > 0)
            {
                g_ucTimer_Distance = 0;
            }
        }
        //no user and timeout,show low power osd
        if(g_ucTimer_Distance >= PS_TIMER_THRE)
        {
            if((GET_OSD_STATE()==_MENU_NONE) && (!GET_FACTORY_MODE()) && (!bAI_LowPower_Status))
            {
                OsdDispOsdMessage(_OSD_DISP_LOW_POWER_MSG);
                g_ucTimer_Distance = 0;
            }
        }
    }
    else if(g_ucTimer_Distance > 0)
    {
        g_ucTimer_Distance = 0;
    }
    #endif
    #if (_AI_EYE_PROTECTION == _ON)
    if(GET_OSD_AI_EYE_PROTECTION_STATUS())
    {
        if(ret <= PS_MIN_DIS)//Distance is close
        {
            //show distance osd
            if((GET_OSD_STATE()==_MENU_NONE) && (!GET_FACTORY_MODE()))
            {
                OsdDispOsdMessage(_OSD_DISP_DISTANCE_WARNING_MSG);
            }
        }
        else
        {
            if((GET_OSD_STATE()==_MENU_FUN_AI_EYE_PROTECTION) && !GET_FACTORY_MODE())
            {
                OsdFuncDisableOsd();
            }
        }
    }
    #endif

    #if(_AI_LIGHT_ADAPTIVATION == _ON)
    if(GET_OSD_AI_LIGHT_ADAPTIVATION_STATUS())
    {
        if(abs(lum - GET_OSD_BACKLIGHT()) >= ALS_VAL_THRE)
        {
            SET_OSD_BACKLIGHT(lum);
            UserAdjustBacklight(lum);
        }
        if(lum <= ALS_CEN_BRI/2)
        {
            if(GET_COLOR_TEMP_TYPE() != _CT_6500)
            {
                //WARM
                SET_COLOR_TEMP_TYPE(_CT_6500);
                RTDNVRamSaveOSDData();
                RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
            }
        }
        else
        {
            if(GET_COLOR_TEMP_TYPE() != _CT_7500)
            {
                //COOL
                SET_COLOR_TEMP_TYPE(_CT_7500);
                RTDNVRamSaveOSDData();
                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
            }
        }
    }
    #endif
}
#endif

#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)
