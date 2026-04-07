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
// ID Code      : UserCommonInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_INTERFACE__

#include "UserCommonInclude.h"

#if(_PANEL_DPTX_FORCE_SSCG_SUPPORT == _ON)
#warning "NOTE: Please Confirm Panel Vendor Support SSCG When _PANEL_DPTX_FORCE_SSCG_SUPPORT Set On"
#endif

#if(_PANEL_EXIST_MULTIPANEL == _OFF)
#if(_PANEL_STYLE == _PANEL_LVDS)
#if(_LVDS_ULTRA_HIGH_SPEED_SUPPORT == _OFF)
#if(((_LVDS_OUTPUT_PORT == _LVDS_4_PORT) && ((_PANEL_PIXEL_CLOCK_MAX_KHZ / 4) > 93000)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_2_PORT) && ((_PANEL_PIXEL_CLOCK_MAX_KHZ / 2) > 93000)) ||\
    ((_LVDS_OUTPUT_PORT == _LVDS_1_PORT) && ((_PANEL_PIXEL_CLOCK_MAX_KHZ) > 93000)))
#warning "NOTE: Please Use BW Web Tool Calculate 1 Port LVDS Max Clk"
#endif
#endif

#if(_LVDS_SETTING_CONTROL_BY_USER == _ON)
#if((_HW_LVDS_DRIVE_TRIMMING_SUPPORT == _ON) && (_LVDS_TRIM_DRIV_CURRENT_BY_USER == _OFF))
#warning "NOTE: If Use LVDS User Mode, Driving Current didnt trimming, There will be 12 percent variation"
#endif
#endif
#endif
#endif

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// EDID DATA TABLE
//--------------------------------------------------
#include "./EDID/EdidTableList.h"

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
#include "./EDID/EdidTableA0.h"
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
#include "./EDID/EdidTableD0.h"
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
#include "./EDID/EdidTableD1.h"
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
#include "./EDID/EdidTableD2.h"
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
#include "./EDID/EdidTableD3.h"
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
#include "./EDID/EdidTableD4.h"
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
#include "./EDID/EdidTableD5.h"
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
#include "./EDID/EdidTableD6.h"
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#include "./EDID/EdidTableMhlD0.h"
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#include "./EDID/EdidTableMhlD1.h"
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#include "./EDID/EdidTableMhlD2.h"
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
#include "./EDID/EdidTableMhlD3.h"
#endif

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#include "./EDID/EdidTableMhlD4.h"
#endif

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
#include "./EDID/EdidTableMhlD5.h"
#endif

//--------------------------------------------------
// HDCP KEY TABLE
//--------------------------------------------------
#if((_DIGITAL_PORT_SUPPORT == _ON) && ((_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) ||\
    ((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_CODE) || ((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)))))

#include "HdcpRxKey.h"

#if(_DP_TX_SUPPORT == _ON)
#include "HdcpTxKey.h"
#endif

#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucDigitalHPosition;
BYTE g_ucDigitalVPosition;
StructPanelPowerInfo g_stPanelPowerInfo;
bit g_bFailSafeMode = 0;

#if(_VGA_SUPPORT == _ON)
BYTE g_ucVgaCheckCounter;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonInterfaceUncallFunction(void);
void UserCommonInterfaceOsdPowerOnInitial(void);
bit UserCommonInterfaceGetDisplaySettingBacklightAction(void);
void UserCommonInterfacePanelPowerAction(BYTE ucEvent);

#if(_TRANSLATOR_SUPPORT == _OFF)
void UserCommonInterfaceAdjustActiveByPassColorProc(void);
void UserCommonInterfaceAdjustColorProc(void);
#endif
void UserCommonInterfaceOsdActiveProc(void);
void UserCommonInterfaceOsdResetProc(void);
void UserCommonDisplayGetMDomainCustomInfo(StructDisplayCustomizedData *pstDisplayCustomizedData);

#if(_TRANSLATOR_SUPPORT == _OFF)
void UserCommonInterfaceAdjustInputTiming(void);
void UserCommonInterfaceAdjustDisplayTiming(void);
bit UserCommonInterfaceReadyForActive(void);
#endif

#if(_VGA_SUPPORT == _ON)
void UserCommonInterfaceAdjustADCData(void);

#if(_YPBPR_SUPPORT == _ON)
bit UserCommonInterfaceCheckHDTVMode(BYTE ucModeNumber);
#endif
#endif

bit UserCommonInterfaceCheckResolutionNoSupport(void);
bit UserCommonInterfaceCheckNoSupport(void);
bit UserCommonInterfaceCheckFakeSaving(void);

#if((_FREESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
void UserCommonInterfaceFreeSyncSupportSwitch(void);
void UserCommonInterfaceFreeSyncSetInputPortSupport(EnumSourceSearchPort enumSourcePort, EnumFreeSyncSupport enumSupport);
#endif

#if((_DP_ADAPTIVESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
void UserCommonInterfaceDpAdaptiveSyncSupportSwitch(void);
EnumDpAdaptiveSyncSupport UserCommonInterfaceDpAdaptiveSyncGetSupport(BYTE ucInputPort);
void UserCommonInterfaceDpAdaptiveSyncSetInputPortSupport(EnumSourceSearchPort enumSourcePort, EnumDpAdaptiveSyncSupport enumSupport);
#endif

#if((_DRR_SUPPORT == _ON) || (_EMBEDDED_EDID_SUPPORT == _ON))
BYTE *UserCommonInterfaceEdidGetDDCRamAddress(EnumSourceSearchPort enumSearchPort);
#endif

#if(_DDCCI_CODE_REDUCTION == _OFF)
#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
void UserCommonInterfaceDdcciIntGetData_EXINT1(void);
BYTE UserCommonInterfaceGetDdcciStatus_EXINT1(void);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1(void);
#endif
#endif
#endif

#if(_SYSTEM_LOW_POWER_IDLE_SUPPORT == _ON)
bit UserCommonInterfaceGetRunDdcciCommand(void);
#endif

// EDID
#if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)
void UserCommonInterfaceNVRamRestoreEDID(void);
#endif

#if(_EMBEDDED_EDID_SUPPORT == _ON)
void UserCommonInterfaceEdidEmbeddedInfoParser(BYTE ucInputport);
void UserCommonInterfaceLoadEmbeddedEdidData(void);
void UserCommonInterfaceLoadEmbeddedEdidDataByPort(EnumInputPortEdid enumInputPort);
#if(_DP_SUPPORT == _ON)
void UserCommonInterfaceDPSwitchEdid(BYTE ucSelectedPort);
void UserCommonInterfaceDPSwitchAllPortEdid(void);
#endif
#endif

#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HW_PC99_SUPPORT == _ON))
void UserCommonInterfacePC99EDIDWriteCommandData(void);
#endif

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
void UserCommonInterfaceHDMISwitchEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection);
#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_HDR10_SUPPORT == _ON))
void UserCommonInterfaceHDMISwitchAllPortEdid(void);
#endif
EnumHdmiEdidLocation UserCommonInterfaceHDMIGetMultiEdidLocated(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection);
#if((_TMDS_FS_ON_ONLY_TARGETPORT_HPD_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
void UserCommonInterfaceHdmiSwitchAllPortEdidToggleTargetPortHpd(void);
#endif
BYTE UserCommonInterfaceGetHdmiEdidCount(BYTE ucInputport);
bit UserCommonInterfaceCheckMultiEdidSupport(BYTE ucInputport);
#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
void UserCommonInterfaceHDMIReloadEdid(BYTE ucInputport);
#endif
void UserCommonInterfaceHDMIBeforeReloadEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection);
void UserCommonInterfaceHDMIAfterReloadEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection);
void UserCommonInterfaceHDMIMultiEdidInitial(void);
void UserCommonInterfaceHDMISwitchMultiEeprom(BYTE ucInputPort, EnumEdidSelection enumHDMIEDIDSelection);
#endif

#if(_HDMI_SUPPORT == _ON)
void UserCommonInterfaceHdmiAllPortExternalEdidParser(void);
void UserCommonInterfaceHdmiExternalInfoParser(BYTE ucInputport);

#if(_HDMI_2_0_SUPPORT == _ON)
void UserCommonInterfaceTmdsGetVersionScdcInfo(void);
#endif
#endif

// HDCP
#if(_DIGITAL_PORT_SUPPORT == _ON)
void UserCommonInterfaceGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserCommonInterfaceGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);

#if(_HDCP_2_2_SUPPORT == _ON)
void UserCommonInterfaceGetHdcp2Certrx(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetHdcp2RSADkey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetHdcp2RSARRModN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
void UserCommonInterfaceGetHdcp2KpubKm(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
void UserCommonInterfaceGetHdcp2RSAKPriv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetHdcp2RSANpinv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetHdcp2LCKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
void UserCommonInterfaceGetDpTxHdcp2RRMODN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetDpTxHdcp2DcpLlcN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetDpTxHdcp2EKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserCommonInterfaceGetDpTxHdcp2NPinv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
#endif

#if(_DP_TX_SUPPORT == _ON)
void UserCommonInterfaceGetTxHDCPKeyAKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserCommonInterfaceGetTxHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif

#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
void UserCommonInterfaceNVRamRestoreHDCP(void);
#endif

#if(_DP_SUPPORT == _ON)
BYTE UserCommonInterfaceDpRxGetDpcdBitInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
BYTE UserCommonInterfaceDpRxGetDpcdInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
void UserCommonInterfaceDpRxSetDpcdBitValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
void UserCommonInterfaceDpRxSetDpcdValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
EnumAudioDpDpcdSupport UserCommonAudioDpGetCapabilityInitialState(BYTE ucInputPort);
void UserCommonInterfaceDpAuxSet(void);
void UserCommonInterfaceDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
void UserCommonInterfaceDPSwitchAllPortDpVersion(void);
StructDpRxErrorCount UserCommonInterfaceDpRxGetErrorCount(BYTE ucInputPort);
EnumDPMSTPort UserCommonInterfaceGetDpMstCapablePort(void);
WORD UserCommonInterfaceDpGetEdidNativeTimingBw(EnumDpEdidPort enumDpEdidPort);
EnumDpAuxStatus UserCommonInterfaceDpTxAuxI2COverWrite(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray);
EnumDpAuxStatus UserCommonInterfaceDpTxAuxI2COverRead(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray);
EnumUserDpLTStatus UserCommonInterfaceDpGetLinkTrainingStatus(EnumSourceSearchPort enumInputPort);

#if(_DP_LONG_HPD_ALLOWED_BY_USER_SUPPORT == _ON)
void UserCommonInterfaceDpLongHpdSetAllowed(EnumSourceSearchPort enumInputPort, bit bAllowed);
#endif

void UserCommonInterfaceDpRxHpdIrqAssert(BYTE ucInputPort);
#endif

#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
EnumDPTxInputSource UserCommonInterfaceDpTxGetStreamSource(void);
#endif

#if(_PANEL_STYLE == _PANEL_DPTX)
EnumDpAuxStatus UserCommonInterfaceDisplayDPTxAuxI2COverWrite(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray);
EnumDpAuxStatus UserCommonInterfaceDisplayDPTxAuxI2COverRead(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray);
#endif

#if(_DP_TX_BLOCK_CONTROL_BEFORE_STREAM_OUTPUT == _ON)
void UserCommonInterfaceCloneModeSwitch(bit bClone);
#endif

void UserCommonInterfaceOsdHandler(void);
void UserCommonInterfaceInitial(void);

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserCommonInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization);
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
EnumColorSpace UserCommonInterfaceGetColorFormat(void);
#endif

#if(_DP_MST_SUPPORT == _ON)
void UserCommonInterfaceMstRx0Rx1switch(EnumDPMSTPort enumMstCapablePort);
#if(_DP_MST_TX_INTERCEPT_DDCCI_MSG_SUPPORT == _ON)
void UserCommonInterfaceDpMstTxInterceptDdcciMsgSetting(bit bStatus);
#endif
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
void UserCommonInterfaceTypeCU3ModeSwitch(BYTE ucInputPort);
void UserCommonInterfaceTypeCU3ModeAllPortCapabilitySwitch(void);
#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
void UserCommonInterfaceTypeCPinAssignmentESupportSwitch(BYTE ucInputPort);
#endif // End of #if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
void UserCommonInterfaceTypeCPinAssignSuccessProc(BYTE ucInputPort, EnumTypeCPinCfgType enumPinAssignment);
#if(_TYPE_C_EIZO_CUSTOMIZED_DP_LANE_CNT_SUPPORT == _ON)
EnumDpLaneCount UserCommonInterfaceTypeCGetAltModeLaneCnt(BYTE ucInputPort, EnumTypeCPinCfgType enumPinAssignment);
#endif
#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE)
EnumTypeCLenovoCheckDeviceTypeResult UserCommonInterfaceTypeCCheckLenovoDeviceTypeValid(BYTE ucInputPort, EnumTypeCLenovoDeviceType enumLenovoDeviceType);
void UserCommonInterfaceTypeCGetLenovoDockingEvent(BYTE ucInputPort, StructTypeCLenovoDockEvent *pstLenovoDockEvent);
void UserCommonInterfaceTypeCLenovoAltModeHandler(BYTE ucInputPort, StructTypeCLenovoSysEvent stLenovoSysEvent);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_ACER_ALT_MODE)
void UserCommonInterfaceTypeCGetAcerUserEvent(BYTE ucInputPort, StructTypeCAcerUserEvent *pstAcerUserEvent);
void UserCommonInterfaceTypeCAcerAltModeHandler(BYTE ucInputPort, StructTypeCAcerSysEvent stAcerSysEvent);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_HP_ALT_MODE)
void UserCommonInterfaceTypeCGetHpUserEvent(BYTE ucInputPort, StructTypeCHpUserEvent *pstHpUserEvent);
void UserCommonInterfaceTypeCHpAltModeHandler(BYTE ucInputPort, StructTypeCHpSysEvent stHpSysEvent);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE)
EnumTypeCDellInitCompleteStatus UserCommonInterfaceTypeCGetDellAltModeInitComplete(BYTE ucInputPort);
void UserCommonInterfaceTypeCDellAltModeHandler(BYTE ucInputPort, StructTypeCDellSysEvent stDellSysEvent);
void UserCommonInterfaceTypeCGetDellUserEvent(BYTE ucInputPort, StructTypeCDellUserEvent *pstDellUserEvent);
#endif
#endif  // End of #if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
void UserCommonInterfaceTypeCGetProtectInfo(BYTE ucInputPort, BYTE ucPdoIndex, StructTypeCUserProtectInfo *pstTypeCUserProtectInfo);
#endif // End of #if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
#endif // End of #if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)

void UserCommonInterfaceDdcciSwitch(EnumDDCCIDebugMode enumMode, BYTE ucInputPort);

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
void UserCommonInterfaceDataExchangeAllDataReset(void);
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
void UserCommonInterfaceMbrStrobeBacklightCtrl(bit bLightCtrl);
void UserCommonInterfaceMbrStrobeBacklightEnableSeq(bit bLightCtrl);
EnumMbrBacklightMode UserCommonInterfaceMbrGetBacklightMode(void);
EnumMbrBacklightMode UserCommonInterfaceMbrGetCurrentBacklightMode(void);
#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
void UserCommonInterfaceMbrDrrHandler(void);
bit UserCommonInterfaceMbrDrrCheckHW(void);
bit UserCommonInterfaceMbrDrrGetHWSupport(void);
#endif
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
void UserCommonInterfaceAdjustRtkAdvMbr(void);
#endif
#if((_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON) || (_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
void UserCommonInterfaceMbrAdvAdjust(BYTE ucBacklightDuty, BYTE ucBacklightPos, bit bLightCtrl);
#endif
#endif

#if(_DRR_SUPPORT == _ON)
EnumGetIVFFromTableSearch UserCommonInterfaceFreeSyncGetIVFmax(WORD *pusVfreqMax, EnumSourceSearchPort enumInputPort);
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
void UserCommonInterfaceForceUsingDDomainDB(void);
#endif
#endif

void UserCommonInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID);

#if(_AUDIO_SUPPORT == _ON)
EnumAudioSamplingFreqType UserCommonInterfaceAudioUpdateUserSamplingFreq(void);
bit UserCommonInterfaceGetAudioReadyToPlayStatus(void);

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
bit UserCommonAudioGetAdjustVolumeThroughDVC(void);
#endif

#if(_DP_SUPPORT == _ON)
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
void UserCommonAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
void UserCommonAudioTtsSetPlaybackActiveEvent(StructAudioTtsSegment *pstAudioTtsSegment, BYTE ucSegmentSize, BYTE ucTtsVolume, BYTE ucAudioVolume);
EnumAudioTtsPlayStatus UserCommonAudioTtsGetPlaybackStatus(void);
BYTE UserCommonAudioTtsGetErrorSegment(void);
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
EnumAudioSamplingFreqType UserCommonAudioUpdateUserDefineAudioGenFreq(void);
EnumAudioLeftRightChannelSelect UserCommonAudioGetUserLeftRightChanelSelect(void);
#endif
#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
void UserCommonInterfaceTmdsSetHdmiZ0HpdType(EnumHdmiZ0HpdType enumHdmiZ0HpdType, WORD usZ0LowPeriod, WORD usZ0HpdInterval);
EnumHdmiZ0Status UserCommonInterfaceTmdsGetZ0Status(BYTE ucInputPort);

#if((_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON) && (_HDMI_SUPPORT == _ON))
StructHdmiSpdInfo UserCommonInterfaceTmdsGetSpdInfo(EnumSourceSearchPort enumInputPort);
EnumHdmiSpdProuductlInfo UserCommonInterfaceTmdsGetSpdPdInfo(EnumSourceSearchPort enumInputPort);
#endif
#endif

#if(_DVI_SUPPORT == _ON)
bit UserCommonInterfacePowerCheckFakeOff(void);
void UserCommonInterfaceTmdsHotPlugDdcConfig(BYTE ucInputPort, bit bEnable);
void UserCommonInterfaceTmdsHdcpVersionCapabilitySwitch(EnumSourceSearchPort enumInputPort, EnumTmdsHdcpType enumTmdsHdcpType);
#endif

#if(_COLORIMETRY_SEAMLESS_CHANGE_SUPPORT == _ON)
bit UserCommonInterfaceColorimetrySeamlessChangeCheckBypass(EnumSourceSearchPort enumInputPort);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Uncall Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceUncallFunction(void)
{
    bit bUncall = _FALSE;

    if(bUncall == _TRUE)
    {
        BYTE ucData = 0;
        StructTypeCPortCtrlFwVersion stTypeCFwVersion = {0x00, 0x00, 0x00};

        ucData = ucData;
        stTypeCFwVersion = stTypeCFwVersion;

        SysStartUpCheck();

        UserCommonAdjust10bitPanelCompensate(0);

        ScalerSyncSetDdcForceNack(_D2_INPUT_PORT, _OFF);

        ScalerSyncGetDdcForceNackStatus(_D2_INPUT_PORT);

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
        UserCommonInterfaceHDMISwitchEdid(_D2_INPUT_PORT, _EDID_INDEX_0);
#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_HDR10_SUPPORT == _ON))
        UserCommonInterfaceHDMISwitchAllPortEdid();
#endif
#endif

#if(_EMBEDDED_EDID_SUPPORT == _ON)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D0_INPUT_PORT);
#endif

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_DP_SUPPORT == _ON))
        UserCommonInterfaceDPSwitchEdid(_D0_INPUT_PORT);
        UserCommonInterfaceDPSwitchAllPortEdid();
#if((_DP_FREESYNC_SUPPORT == _ON) || (_DP_HDR10_SUPPORT == _ON))
        UserCommonInterfaceDPSwitchAllPortEdid();
#endif
#endif

#if(_FLASH_WRITE_FUNCTION_SUPPORT == _ON)
#if(_HW_PC99_SUPPORT == _ON)
        UserCommonInterfacePC99EDIDWriteCommandData();
#endif
        UserCommonFlashErasePage(0x00, 0x00);
        UserCommonFlashWrite(0x00, 0x00, 1, &ucData);
#endif

#if((_DUAL_BANK_SUPPORT == _ON) &&\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _OFF) ||\
   ((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) && (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL == _DUAL_BANK_FLASH_PARTITION_USER))))
        SysMainStartUserCode(0);
#endif

        SysModeSetResetTarget(_MODE_ACTION_NONE);
        SysSourceSwitchInputPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        SysSourceSetScanType(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE));
        SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        SysSourceGetJudge(_D0_INPUT_PORT);
        SysSourceGetPreDetect(_D0_INPUT_PORT);

        ScalerTimerSearchActiveTimerEvent(0);
        UserCommonInterfaceGetDisplaySettingBacklightAction();

#if(_HDMI_SUPPORT == _ON)
        ScalerTMDSHdmiGetAVIInfo(UserCommonNVRamGetSystemData(_SEARCH_PORT), _AVI_INFO_COLOR_SPACE);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
        ScalerSyncHdcpCheckEnabled(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        ScalerSyncDigitalGetColorimetryChanged(_D0_INPUT_PORT);
        ScalerSyncDigitalGetColorimetryExtChanged(_D0_INPUT_PORT);
        ScalerSyncDigitalGetQuantizationChanged(_D0_INPUT_PORT);
        ScalerSyncDigitalClrColorimetryChanged(_D0_INPUT_PORT);
        ScalerSyncDigitalClrColorimetryExtChanged(_D0_INPUT_PORT);
        ScalerSyncDigitalClrQuantizationChanged(_D0_INPUT_PORT);
#endif

#if(_VGA_SUPPORT == _ON)
        ScalerSyncProcGetSyncPad();
#endif

        UserCommonAdjustRealValueToPercent(0, 0, 0, 0);
        UserCommonAdjustPercentToRealValue(0, 0, 0, 0);

#if(_AUDIO_SUPPORT == _ON)
        SysAudioGetAudioBackupFreq();
        ScalerAudioSamplingFreqDetect(_D0_INPUT_PORT);

#if(_DP_SUPPORT == _ON)
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
        UserCommonAudioDpSetCapabilityState(_NO_INPUT_PORT, _AUDIO_DP_DPCD_NOT_SUPPORT);
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)
#endif

#if(_DP_SUPPORT == _ON)
        ScalerDpVersionSwitch(_D0_INPUT_PORT, _DP_VERSION_1_1, _DP_MST_NO_PORT);
        ScalerDpLaneCountSwitch(_D0_INPUT_PORT, _DP_LINK_4_LANE);
        ScalerDpEdidSwitch(_D0_INPUT_PORT);
        ScalerDpGetPowerStatus(_D0_INPUT_PORT);
        ScalerDpGetLaneCount(_D0_INPUT_PORT);
        ScalerDpGetLinkRate(_D0_INPUT_PORT);
        ScalerDpGetLaneVoltageSwingLv(_D0_INPUT_PORT, _DP_LANE_0);
        ScalerDpGetLanePreEmpLv(_D0_INPUT_PORT, _DP_LANE_0);
        ScalerDpGetSrcMstEnable(_D0_INPUT_PORT);
        ScalerDpAuxChPowerStatusCheck(_NO_INPUT_PORT, _FALSE);
        UserCommonInterfaceDpRxGetDpcdBitInfo(_D0_INPUT_PORT, 0x00, 0x00, 0x00, _BIT0);
        UserCommonInterfaceDpRxGetDpcdInfo(_D0_INPUT_PORT, 0x00, 0x00, 0x00);
        UserCommonInterfaceDpRxSetDpcdBitValue(_NO_INPUT_PORT, 0x00, 0x00, 0x00, ~_BIT0, 0x00);
        UserCommonInterfaceDpRxSetDpcdValue(_NO_INPUT_PORT, 0x00, 0x00, 0x00, 0x00);
        UserCommonInterfaceDpVersionSwitch(_D0_INPUT_PORT, _DP_VERSION_1_1, _DP_MST_NO_PORT);
        UserCommonInterfaceDpRxGetErrorCount(_D0_INPUT_PORT);
        UserCommonInterfaceDPSwitchAllPortDpVersion();
        UserCommonInterfaceDpTxAuxI2COverWrite(0x50, 16, &ucData);
        UserCommonInterfaceDpTxAuxI2COverRead(0x50, 16, &ucData);
        UserCommonInterfaceDpRxHpdIrqAssert(_NO_INPUT_PORT);
        UserCommonInterfaceDpGetLinkTrainingStatus(_D0_INPUT_PORT);

#if(_DP_MST_SUPPORT == _ON)
        UserCommonInterfaceMstRx0Rx1switch(_DP_MST_NO_PORT);

#if(_DP_MST_TX_INTERCEPT_DDCCI_MSG_SUPPORT == _ON)
        UserCommonInterfaceDpMstTxInterceptDdcciMsgSetting(_OFF);
#endif
#endif

#if(_DP_LONG_HPD_ALLOWED_BY_USER_SUPPORT == _ON)
        UserCommonInterfaceDpLongHpdSetAllowed(_D0_INPUT_PORT, _TRUE);
#endif

#endif

#if(_PANEL_STYLE == _PANEL_DPTX)
        UserCommonInterfaceDisplayDPTxAuxI2COverWrite(_DISPLAY_DP_TX_1, 0x50, 16, &ucData);
        UserCommonInterfaceDisplayDPTxAuxI2COverRead(_DISPLAY_DP_TX_1, 0x50, 16, &ucData);
#endif

#if(_DP_TX_SUPPORT == _ON)
        ScalerDpTxGetDownstreamHPDStatus();
        UserCommonInterfaceDpTxGetStreamSource();
#endif

#if(_FREESYNC_SUPPORT == _ON)
        UserCommonInterfaceFreeSyncSupportSwitch();
        ScalerSyncGetAmdVsdbVer(_D2_INPUT_PORT);
        UserCommonInterfaceFreeSyncSetInputPortSupport(_D0_INPUT_PORT, _FREESYNC_SUPPORT_OFF);
#endif

#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
        UserCommonInterfaceDpAdaptiveSyncSupportSwitch();
        UserCommonInterfaceDpAdaptiveSyncGetSupport(_D0_INPUT_PORT);
        UserCommonInterfaceDpAdaptiveSyncSetInputPortSupport(_D0_INPUT_PORT, _DP_ADAPTIVESYNC_SUPPORT_OFF);
#endif
        UserCommonInterfaceDdcciSwitch(_DDCCI_MODE, _D0_INPUT_PORT);

        SysSourceGetSourceType();

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
        UserInterfaceGetEmbeddedEDIDData(_A0_INPUT_PORT_EDID);
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
        ScalerDDomainPatternGenEnable(_DISABLE);
        ScalerDDomainPatternGenAdjustColor(0x00, 0x00, 0x00);

#if(_AUDIO_SUPPORT == _ON)
        UserInterfaceGetAudioMuteStatus();
#endif

#if(_OD_SUPPORT == _ON)
        ScalerODGetStatus();
        ScalerODGetDeltaGain();
        ScalerODGetSupportStatus();
#endif

#if(_FRC_SUPPORT == _OFF)
        ScalerGlobalGetDBStatus();
#endif

#if(((_DDR3_PHASE_CALIBRATION == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_FRC_MODE)) && (_DDR3_PHASE_CHECK == _ON))
        ScalerDDR3PhaseCalibrationFRCMode();
#endif

        UserCommonAdjustHPosition(0);
        UserCommonAdjustVPosition(0);

        ScalerOsdDoubleFunction(0, 0);
        ScalerOsdMapRotation(0, 0, 0, 0, 0, 0);
        ScalerOsdPositionCorrectSupport();

        UserCommonInterfaceAdjustActiveByPassColorProc();
#endif // End of #if(_TRANSLATOR_SUPPORT == _OFF)

#if(_DP_SUPPORT == _ON)
        UserCommonInterfaceDpAuxSet();
#endif

#if(_D0_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D0_INPUT_PORT);
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D1_INPUT_PORT);
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D2_INPUT_PORT);
#endif

#if(_D3_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D3_INPUT_PORT);
#endif

#if(_D4_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D4_INPUT_PORT);
#endif

#if(_D5_TMDS_SUPPORT == _ON)
        ScalerTMDSHotPlugEvent(_D5_INPUT_PORT);
#endif

#if(_D0_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D0_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D0_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D1_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D1_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D2_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D2_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D3_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D3_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D4_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D4_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        ScalerSyncTMDSEdidSwitch(_D5_INPUT_PORT);
        ScalerSyncHDMIDdcCheckBusy(_D5_INPUT_PORT, _DELAY_30US_TIMESCALE, 1, 1500);
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
        UserCommonInterfaceTypeCU3ModeSwitch(_D0_INPUT_PORT);
        UserCommonInterfaceTypeCU3ModeAllPortCapabilitySwitch();
#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
        UserCommonInterfaceTypeCPinAssignmentESupportSwitch(_D0_INPUT_PORT);
#endif
#endif

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
        SysTypeCGetLocPowExist();
        SysTypeCSetPortCtrlRequest(_D0_INPUT_PORT);
        SysTypeCGetPartnerStatusInfo(_D0_INPUT_PORT);
        SysTypeCGetPartnerAlertInfo(_D0_INPUT_PORT);
        SysTypeCGetPortCtrlEvent(_D0_INPUT_PORT);
        SysTypeCClrPortCtrlEvent(_D0_INPUT_PORT, _PD_PORT_CTRL_EVENT_NONE);
        SysTypeCGetCcAttach(_D0_INPUT_PORT);
        SysTypeCGetAltModeReady(_D0_INPUT_PORT);
        SysTypeCGetPinAssignment(_D0_INPUT_PORT);
        SysTypeCGetOrientation(_D0_INPUT_PORT);
        SysTypeCGetDataRole(_D0_INPUT_PORT);
        SysTypeCGetPowerRole(_D0_INPUT_PORT);
        SysTypeCGetPortPartnerFlag(_D0_INPUT_PORT);
        SysTypeCGetPdoCnt(_D0_INPUT_PORT, _TYPE_C_POWER_ROLE_NONE);
        SysTypeCGetPdo(_D0_INPUT_PORT, _TYPE_C_POWER_ROLE_NONE, 0);
        SysTypeCGetPartnerPdoCnt(_D0_INPUT_PORT, _TYPE_C_POWER_ROLE_NONE);
        SysTypeCGetPartnerPdo(_D0_INPUT_PORT, _TYPE_C_POWER_ROLE_NONE, 0);
        SysTypeCGetPdoStatus(_D0_INPUT_PORT, ((WORD *)pData), ((WORD *)pData));
        SysTypeCGetRequestedSrcPdo(_D0_INPUT_PORT);
        SysTypeCGetUFPProductType(_D0_INPUT_PORT);
        SysTypeCGetDFPProductType(_D0_INPUT_PORT);
        SysTypeCGetFwVersion(_D0_INPUT_PORT, &stTypeCFwVersion);
        SysTypeCGetPortOperationMode(_D0_INPUT_PORT);
        SysTypeCSetUserEventFlag(_D0_INPUT_PORT, _TYPE_C_USER_EVENT_NONE);
        SysTypeCGetDpStatusInfo(_D0_INPUT_PORT);
        UserCommonPortControllerGetUnconstrainedPow(_D0_INPUT_PORT);
        ScalerTypeCRxGetAltModeReady(_D0_INPUT_PORT);
        ScalerTypeCRxGetExplicitContract(_D0_INPUT_PORT);

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
        ScalerTypeCRx0PdGetDataRole();
        ScalerTypeCRx0PdGetPowerRoleSwapProcessing();
#endif

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
        SysTypeCGetLenovoAltModeReady(_D0_INPUT_PORT);
        SysTypeCGetLenovoDeviceType(_D0_INPUT_PORT);
#endif

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_ACER_ALT_MODE))
        SysTypeCGetAcerAltModeReady(_D0_INPUT_PORT);
#endif

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_HP_ALT_MODE))
        SysTypeCGetHpAltModeReady(_D0_INPUT_PORT);
#endif

#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE))
        SysTypeCGetDellAltModeReady(_D0_INPUT_PORT);
        SysTypeCGetEnterDellAltModeTimeOut(_D0_INPUT_PORT);
#endif

#if((_USB_HUB_RTS5411_SERIES_SUPPORT == _ON) && (_DP_TYPE_C_HUB_COMMUNICATION_SUPPORT == _ON))
        UserCommonUsbHubGetDspInfo(_HUB_DSP0);
#endif

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_USB3_RETIMER_SUPPORT == _ON))
        SysTypeCHubC2ACableAttachStatus(_D0_INPUT_PORT);
#endif

#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
        UserCommonPortControllerGet5400I2CPinNum(_D0_INPUT_PORT);
#endif
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)
        SysTypeCGetCcPinStatus(_TYPE_C_CC1);
#endif

#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
        ScalerPinshareTypeCAdcGetAdcIdealData(_TYPE_C_UFP_VMON);
#endif // End of #if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)

#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
        ScalerTypeCPmicIICRead(0, 0, 0, 0, pData);
#endif

#if((_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS) || (_FW_UPDATE_FOREGROUND_BACKUP_VGA_EDID_SUPPORT == _ON))
        ScalerSyncVGAUseEmbeddedEDID();
        ScalerSyncVGADdcCheckBusyAndForceNack();
#endif

#if(_EFUSE_SUPPORT == _ON)
        ScalerEfuseGetData(_EFUSE_NONE, 1, &pData[0]);
#endif

#if(_HW_IIC_SUPPORT == _ON)
        ScalerMcuHwIICConfigSetting(_HW_IIC_SPEED);
#endif

#if(_PWM_FUNCTION_SUPPORT == _ON)
        ScalerMcuPwmAdjustResetByDvs(_PWM0, _DISABLE);
#endif

        UserInterfaceGetFreeSyncEnable(_D0_INPUT_PORT);
        UserInterfaceGetDpAdaptiveSyncEnable(_D0_INPUT_PORT);

#if(_FREESYNC_II_SUPPORT == _ON)
        UserCommonHDRGetFreesynIIStatus();
        UserCommonHDRGetFreeSyncIILDDisable();
        UserCommonHDRGetFreeSyncIIEOTFType();
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        UserCommonInterfaceGetRGBQuantizationLimitRangeStatus(_RGB_QUANTIZATION_FULL_RANGE);
#endif

#if(_TRANSLATOR_SUPPORT == _ON)
#if(_FREESYNC_SUPPORT == _ON)
        ScalerFreeSyncGetFreeSyncInfo(_D0_INPUT_PORT, _SPD_INFO_FREESYNC_ENABLE);
#endif
#endif

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
        UserCommonDataExchangeReadReply(pData, 0);
        UserCommonInterfaceDataExchangeAllDataReset();
        UserCommonDataExchangeSendDataUser(_DATA_EXCHAGNE_CMD_NONE, pData, 0);
        UserCommonDataExchangeGetDataUser(_DATA_EXCHAGNE_CMD_NONE, pData, 0);
        UserCommonDataExchangeGetDataKernel(_DATA_EXCHAGNE_CMD_NONE, pData, 0);
        UserCommonDataExchangeInit();
        UserCommonDataExchangeGetEvent();
#endif

#if(_GLOBAL_DIMMING_SUPPORT == _ON)
        UserCommonGlobalDimmingEnable(_DISABLE);
#endif

#if(_FLASH_READ_FUNCTION_SUPPORT == _ON)
        UserCommonFlashRead(0x00, 0x00, 1, pData);
#endif

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON || _HDMI_24C02_SUPPORT)
        UserCommonEepromIICRead(0x00, 0x0000, 4, 16, pData, 0, 0);
        UserCommonEepromIICWrite(0x00, 0x0000, 4, 16, pData, 0, 0, 16);
#endif

#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
        SysSourceBgGetInputPort();
        SysSourceBgGetJudge();
        SysSourceBgDetectReset();
        SysSourceBgSetInputPort(_D0_INPUT_PORT);
        SysSourceBgSetScanType(_SOURCE_BG_SWITCH_AUTO_WITHOUT_GROUP);
        SysSourceBgGetScanType();
        SysSourceBgGetStableCheckEnable();
        SysSourceBgSetStableCheckEnable();
        SysSourceBgClrStableCheckEnable();

#if(_SOURCE_BACKGROUND_DETECT_ENABLE_CONTROL_BY_USER == _ON)
        SysSourceBgDetectEnable();
        SysSourceBgDetectDisable();
#endif
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
        UserCommonInterfaceMbrStrobeBacklightCtrl(_LIGHT_CONTROL_OFF);
        ScalerTconLogicalOpEnable(_TCON13_LOGICAL_OP, _TCON_LOGICAL_OP_AND, _DISABLE);

#if(_HW_PWM_RST_BY_TCON_SELECT == _TCON4)
        ScalerTcon4Adjust(0x0000, 0x0000, 0x0000, 0x0000);
#elif(_HW_PWM_RST_BY_TCON_SELECT == _TCON7)
        ScalerTcon7Adjust(0x0000, 0x0000, 0x0000, 0x0000);
#elif(_HW_PWM_RST_BY_TCON_SELECT == _TCON8)
        ScalerTcon8Adjust(0x0000, 0x0000, 0x0000, 0x0000);
#endif
#endif
        ScalerMcuDdcISPChannelCtrl(_NO_DDC, _DISABLE);

#if(_HP_SOURCE_SCAN_SUPPORT == _ON)
        SysSourceHpGetSourceJudge();
        SysSourceHpGetTargetSourceType(0x00);
        SysSourceHpGetTargetSearchTimes();
        SysSourceHpGetSwitchPortNoCable();
        SysSourceHpGetTargetPortNoSignal();
#endif

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_EIZO_STYLE)
        SysSourceEizoSetPowerSavingSupport(_ON);
        SysSourceGetSourceSwitchFinish();
#endif

#if((_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
        UserCommonAdjustOGCBank((_OGC_TOTAL_GAMMA * _OGC_SUPPORT), _OGC_MAX_BACKLIGHT_TYPE);
        UserCommonAdjustOGCAddr((_OGC_TOTAL_GAMMA * _OGC_SUPPORT), _OGC_MAX_BACKLIGHT_TYPE);
#endif

#if(_IR_SUPPORT == _IR_HW_SUPPORT)
        ScalerIRHWModeGetNECIRStatus();
#endif
#if(_GLOBAL_DIMMING_PATTERN_ESTIMATE == _ON)
        UserCommonGlobalDimmingPatternEstimate(_GD_PATTERN_NONE);
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
        UserCommonInterfaceTmdsSetHdmiZ0HpdType(_HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME, 0, 0);

#if((_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON) && (_HDMI_SUPPORT == _ON))
        UserCommonInterfaceTmdsGetSpdPdInfo(_D0_INPUT_PORT);
#endif
#endif

#if(_PWM_RST_SIGNAL_SEL == _TCON)
        ScalerTconAdjust(0);
#endif

#if((_DUAL_BANK_DEBUG_SUPPORT == _ON) && (_ISP_CHANNEL_PROTECT_SUPPORT == _ON))
        UserCommonDualBankUserSetISPChannel(0xFFFF);
        UserCommonDualBankUserSetISPSlaveAddr(_ISP_SLAVE_ENABLE);
#endif

#if(_DYNAMIC_COLOR_AUTO_MEASURE == _ON)
        UserCommonAdjustColorSetDynamicColorInitialBoundary(0x0000, 0x0000, 0x0000, 0x0000);
        UserCommonAdjustColorSetAutoMeasure(0);
        UserCommonAdjustColorGetDynamicColorMeasureResult(0, 0);
#endif
    }
}

//--------------------------------------------------
// Description  : User initial LUT/Latch/SRAM tabled ata
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdPowerOnInitial(void)
{
    // User Power On Initial
    UserInterfaceAdjustOsdPowerOnInitial();

#if((_DCR_SUPPORT == _ON) || (_IAPS_SUPPORT == _ON))
    ScalerColorDCRSetSource();
#endif

    // Adjust DCC Histogram Settings
#if(_DCC_HISTOGRM_INFO == _ON)
    ScalerColorDCCHistoSetting();
#endif

    // Adjust IAPSGain Histogram Settings
#if(_IAPS_SUPPORT == _ON)
#if(_IAPS_GAIN_COMPENSATION_TYPE == _IAPS_GAIN_COMPENSATION_GEN_0)
// DCC Manual mode Initial
#elif(_IAPS_GAIN_COMPENSATION_TYPE == _IAPS_GAIN_COMPENSATION_GEN_1)
    ScalerColorIAPSGainSoftClampAdjust(_IAPS_GAIN_CLAMP_FACTOR);
    ScalerColorIAPSGainValueAdjust(_IAPS_CONTRAST_TARGET);
#endif
#endif

#if(_HDR10_LIGHT_ENHANCE_SUPPORT == _ON)
    ScalerColorIAPSGainSoftClampAdjust(_IAPS_GAIN_CLAMP_FACTOR);
    ScalerColorIAPSGainValueAdjust(_IAPS_CONTRAST_TARGET);
#endif

    // Adjust D Dither Table
#if(_D_DITHER_SUPPORT == _ON)
    UserCommonAdjustDDither();
#endif

#if(_SCALING_DOWN_TYPE == _SD_GEN_1)
    ScalerScalingSetScalingDownCoef();
#endif

#if((_ULTRA_VIVID_SUPPORT == _ON) && (_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_3))
    ScalerColorUltraVividInitial();
#endif
}

//--------------------------------------------------
// Description  : Get backlight staus when performing display setting
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit UserCommonInterfaceGetDisplaySettingBacklightAction(void)
{
#if(_PANEL_STYLE == _PANEL_VBO)

#if(_VBO_BACKLIGHT_BY_USER == _ENABLE)
    return UserInterfaceGetDisplaySettingBacklightAction();
#else
    return _DISABLE;
#endif

#else

    return UserInterfaceGetDisplaySettingBacklightAction();

#endif
}
#if(_HDR10_SUPPORT == _ON)
extern void OsdHDRFunOnRestrict(void);
#endif

//--------------------------------------------------
// Description  : Power Power On/Off Sequence
// Input Value  : ucEvent --> _PANEL_ON
//                            _PANEL_OFF
//                            _BACKLIGHT_ON
//                            _BACKLIGHT_OFF
// Output Value : None
//--------------------------------------------------
void UserCommonInterfacePanelPowerAction(BYTE ucEvent)
{



DebugMessageOsd("#****1.ucEvent234555",ucEvent);

    
#if(_PANEL_POWER_SEQUENCE_CONTROL_BY_USER == _ON)

    UserInterfacePanelPowerAction(ucEvent);

#else

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
    SET_PANELPOWERACTION(ucEvent);
#endif


#if(_HDR10_SUPPORT == _ON)
	if(ucEvent == _PANEL_ON || ucEvent == _BACKLIGHT_ON)
	{
		if(UserCommonHDRGetHDR10Status() == _HDR10_ON)
		{
			OsdHDRFunOnRestrict();		
		}
	}	
#endif

    switch(ucEvent)
    {
        case _PANEL_ON:

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
            if(GET_PANELPOWERSTATUS() == _WAITING_FOR_PANEL_OFF)
            {
                return;
            }
#endif

            if(GET_PANELPOWERSTATUS() == _PANEL_POWER_OFF_STATE)
            {
#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _OFF)
                // Check T6
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_POWER_OFF);
#endif

                // LCD Power on
                PCB_PANEL_POWER(_PANEL_CONTROL_ON);

                UserInterfaceAdjustWaitPanelT1();

#if(_PANEL_STYLE == _PANEL_VBO)

                // Set Vby1 PHY
                ScalerDisplayVboAnalogPhyConrol(_ENABLE);

                // Set HTPDN control by H/W
                ScalerDisplayVboHtpdnSetFwControl(_DISABLE);

                UserInterfaceAdjustWaitPanelT2();

                ScalerDisplayVboHtpdnHandler();

#elif(_PANEL_STYLE == _PANEL_DPTX)

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_PANEL_ON);

                // Set Dptx PHY
                ScalerDisplayDPTxPhyInitial();

                UserInterfaceAdjustWaitPanelT2();

                if(ScalerDisplayDPTxLinkSequence() == _FAIL)
                {
#if(_PANEL_DPTX_FORCE_OUTPUT_SUPPORT == _ON)
                    ScalerDisplayDPTxLinkSignalForceOutput();
#endif
                }
#endif
            }

            if(GET_PANELPOWERSTATUS() != _BACKLIGHT_ON_ALREADY)
            {
#if(_PANEL_STYLE == _PANEL_LVDS)

                // LVDS Power On
                ScalerDisplayLvdsPower(_ON);

                UserInterfaceAdjustWaitPanelT2();

                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON);

                // Wait Event for Backlight On
                ScalerTimerActiveTimerEvent(_PANEL_POWER_ON_T3, _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_WAITING_FOR_BACKLIGHT);

#elif(_PANEL_STYLE == _PANEL_TTL)

                UserInterfaceAdjustWaitPanelT2();

                // TTL Power On
                ScalerDisplayTtlPower(_ON);

                // Wait Event for Backlight On
                ScalerTimerActiveTimerEvent(_PANEL_POWER_ON_T3, _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_WAITING_FOR_BACKLIGHT);

#elif(_PANEL_STYLE == _PANEL_VBO)

#if(_PANEL_VBO_CHANGE_CLK_RESET_TYPE == _VBO_CHANGE_CLK_RESET_BY_RE_LINK_TRAIN)
                if(GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE)
                {
                    ScalerDisplayVboForceLinkTraining(_DISABLE);
                }
#endif

                // Set Panel Fast Off Enable
                ScalerDisplayVboPanelSetFastOff(_ENABLE);

                // Wait Event for Backlight On
                ScalerTimerActiveTimerEvent(_PANEL_POWER_ON_T3, _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_WAITING_FOR_BACKLIGHT);

#elif(_PANEL_STYLE == _PANEL_DPTX)

                ScalerDisplayDPTxStreamHanlder(_ENABLE);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_PANEL_ON);

                // Wait Event for Backlight On
                ScalerTimerActiveTimerEvent(_PANEL_POWER_ON_T3, _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_WAITING_FOR_BACKLIGHT);

#endif  // #if(_PANEL_STYLE == _PANEL_LVDS)
            }

            break;

        case _PANEL_OFF:

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
            if((GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE) &&
               (GET_PANELPOWERSTATUS() != _WAITING_FOR_PANEL_OFF))
#else
            if(GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE)
#endif
            {
#if(_PANEL_STYLE == _PANEL_LVDS)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

                UserInterfaceAdjustWaitPanelT4();

#if(_LVDS_NO_VCM_LEVEL_BEFORE_DATA == _ON)
                ScalerDisplayLvdsPower(_OFF);

                ScalerDisplayLvdsPLL(_OFF);
#else
                ScalerDisplayLvdsPLL(_OFF);

                ScalerDisplayLvdsPower(_OFF);
#endif
                UserInterfaceAdjustWaitPanelT5();

#elif(_PANEL_STYLE == _PANEL_TTL)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

                UserInterfaceAdjustWaitPanelT4();

                ScalerDisplayTtlPower(_OFF);

                UserInterfaceAdjustWaitPanelT5();

#elif(_PANEL_STYLE == _PANEL_VBO)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

                // HTDPN fail before CDR lock, or CDR fail during ALN training, then set panel fast off
                if(ScalerDisplayVboPanelFastOffCheck() != _ENABLE)
                {
                    UserInterfaceAdjustWaitPanelT4();
                }

                // Force disable video output
                ScalerDisplayVboForceVideoOutput(_DISABLE);

                // Vby1 Phy Disable
                ScalerDisplayVboAnalogPhyConrol(_DISABLE);

                // Set HTPDN control by F/W, pull high
                ScalerDisplayVboHtpdnSetFwControl(_ENABLE);

                UserInterfaceAdjustWaitPanelT5();

#elif(_PANEL_STYLE == _PANEL_DPTX)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_BACKLIGHT_OFF);

                UserInterfaceAdjustWaitPanelT4();

                // Set IDLE Pattern
                ScalerDisplayDPTxStreamHanlder(_DISABLE);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_IDLE_PATTERN);

                // Disable DPTx Spread Spectrum
                ScalerDisplayDPTxSSCSet(_DISABLE);

                ScalerDisplayDPTxAnalogPhyConrol(_DISABLE);

                UserInterfaceAdjustWaitPanelT5();

#endif // #if(_PANEL_STYLE == _PANEL_LVDS)

                PCB_PANEL_POWER(_PANEL_CONTROL_OFF);

                ScalerTimerActiveTimerEvent(_PANEL_POWER_OFF_T6, _USER_TIMER_EVENT_PANEL_POWER_OFF);

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
                SET_PANELPOWERSTATUS(_WAITING_FOR_PANEL_OFF);
#else
                SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
#endif
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);
            }

            break;

        case _BACKLIGHT_ON:

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
            if(GET_PANELPOWERSTATUS() == _WAITING_FOR_PANEL_OFF)
            {
                return;
            }
#endif




            if(GET_PANELPOWERSTATUS() == _PANEL_POWER_OFF_STATE)
            {
#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _OFF)
                // Check T6
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_POWER_OFF);
#endif

                // LCD Power on
                PCB_PANEL_POWER(_PANEL_CONTROL_ON);

                UserInterfaceAdjustWaitPanelT1();

#if(_PANEL_STYLE == _PANEL_LVDS)

                // LVDS Power On
                ScalerDisplayLvdsPower(_ON);

                UserInterfaceAdjustWaitPanelT2();

                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON);

                // Wait Delay for Backlight On
                UserInterfaceAdjustWaitPanelT3();
                 
                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#elif(_PANEL_STYLE == _PANEL_TTL)

                UserInterfaceAdjustWaitPanelT2();

                // TTL Power On
                ScalerDisplayTtlPower(_ON);

                // Wait Delay for Backlight On
                UserInterfaceAdjustWaitPanelT3();

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#elif(_PANEL_STYLE == _PANEL_VBO)

                // Set Vby1 PHY
                ScalerDisplayVboAnalogPhyConrol(_ENABLE);

                // Set HTPDN control by H/W
                ScalerDisplayVboHtpdnSetFwControl(_DISABLE);

                UserInterfaceAdjustWaitPanelT2();

                ScalerDisplayVboHtpdnHandler();

                UserInterfaceAdjustWaitPanelT3();

                ScalerDisplayVboLocknHandler();

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

                // Set Panel Fast Off Disable
                ScalerDisplayVboPanelSetFastOff(_DISABLE);

#elif(_PANEL_STYLE == _PANEL_DPTX)

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_PANEL_ON);

                // Set Dptx PHY
                ScalerDisplayDPTxPhyInitial();

                UserInterfaceAdjustWaitPanelT2();

                if(ScalerDisplayDPTxLinkSequence() == _FAIL)
                {
#if(_PANEL_DPTX_FORCE_OUTPUT_SUPPORT == _ON)
                    ScalerDisplayDPTxLinkSignalForceOutput();
#endif
                }

                // Set Video Stream parameter
                ScalerDisplayDPTxStreamHanlder(_ENABLE);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_VIDEO_PATTERN);

                // Wait Delay for Backlight On
                UserInterfaceAdjustWaitPanelT3();

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#endif // #if(_PANEL_STYLE == _PANEL_LVDS)
            }
            else if(GET_PANELPOWERSTATUS() == _PANEL_BACKLIGHT_OFF)
            {
#if(_PANEL_STYLE == _PANEL_LVDS)

                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON);

#elif(_PANEL_STYLE == _PANEL_TTL)

                // TTL Power On
                ScalerDisplayTtlPower(_ON);

#elif(_PANEL_STYLE == _PANEL_VBO)

#if(_PANEL_VBO_CHANGE_CLK_RESET_TYPE == _VBO_CHANGE_CLK_RESET_BY_RE_LINK_TRAIN)
                ScalerDisplayVboForceLinkTraining(_DISABLE);

                ScalerDisplayVboLocknHandler();

                // Set Panel Fast Off Disable
                ScalerDisplayVboPanelSetFastOff(_DISABLE);
#endif

#elif(_PANEL_STYLE == _PANEL_DPTX)

#if(_PANEL_DPTX_HPD_DETECT == _ON)
                if(GET_DISPLAY_DP_TX_FORCE_TO_LT() == _TRUE)
                {
                    if(ScalerDisplayDPTxLinkSequence() == _FAIL)
                    {
#if(_PANEL_DPTX_FORCE_OUTPUT_SUPPORT == _ON)
                        ScalerDisplayDPTxLinkSignalForceOutput();
#endif
                    }
                }
#endif
                ScalerDisplayDPTxStreamHanlder(_ENABLE);

#endif // #if(_PANEL_STYLE == _PANEL_LVDS)

                // Wait Delay for Backlight On
                UserInterfaceAdjustWaitPanelT3();

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);
            }
            else
            {
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

#if(_PANEL_STYLE == _PANEL_LVDS)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#elif(_PANEL_STYLE == _PANEL_TTL)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#elif(_PANEL_STYLE == _PANEL_VBO)

                ScalerDisplayVboLocknHandler();

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

                // Set Panel Fast Off Disable
                ScalerDisplayVboPanelSetFastOff(_DISABLE);

#elif(_PANEL_STYLE == _PANEL_DPTX)

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

                // Panel DPTx Power Sequence Check Point
                ScalerDisplayDPTxPowerSequenceProc(_DPTX_POWER_SEQUENCE_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);

#endif // #if(_PANEL_STYLE == _PANEL_LVDS)
            }

#if(_DEF_OSD_GAMING == _ON)
			GAME_FLAG = 0;
			ScalerTimerActiveTimerEvent(SEC(0.1), _USER_TIMER_EVENT_GAME_HOTKEY);
#endif
            break;

        case _BACKLIGHT_OFF:

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
            if((GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE) &&
               (GET_PANELPOWERSTATUS() != _PANEL_BACKLIGHT_OFF) &&
               (GET_PANELPOWERSTATUS() != _WAITING_FOR_PANEL_OFF))
#else
            if((GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE) &&
               (GET_PANELPOWERSTATUS() != _PANEL_BACKLIGHT_OFF))
#endif
            {
                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

#if(_PANEL_STYLE == _PANEL_LVDS)

                UserInterfaceAdjustWaitPanelT4();

                ScalerDisplayLvdsPLL(_OFF);

#elif(_PANEL_STYLE == _PANEL_TTL)

                UserInterfaceAdjustWaitPanelT4();

                ScalerDisplayTtlPower(_OFF);

#elif(_PANEL_STYLE == _PANEL_VBO)

#if(_PANEL_VBO_CHANGE_CLK_RESET_TYPE == _VBO_CHANGE_CLK_RESET_BY_RE_LINK_TRAIN)
                UserInterfaceAdjustWaitPanelT4();

                ScalerDisplayVboForceLinkTraining(_ENABLE);
#endif

#elif(_PANEL_STYLE == _PANEL_DPTX)

                UserInterfaceAdjustWaitPanelT4();

                ScalerDisplayDPTxStreamHanlder(_DISABLE);

#endif // #if(_PANEL_STYLE == _PANEL_LVDS)

                SET_PANELPOWERSTATUS(_PANEL_BACKLIGHT_OFF);
            }


            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

            break;

        default:

            break;
    }
#endif
}

#if(_TRANSLATOR_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Set color in bypass normal active process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustActiveByPassColorProc(void)
{
#if(_I_DITHER_SUPPORT == _ON)
    // Adjust I Dithering
    UserCommonAdjustIDither();

    ScalerColorIDitherEnable(_FUNCTION_ON);
#endif

#if(_OD_SUPPORT == _ON)
    ScalerODEnable(UserInterfaceGetODEnableStatus());
#endif

#if(_SHARPNESS_SUPPORT == _ON)
    UserCommonAdjustSharpness(SysSourceGetInputPort());
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
    UserInterfaceAdjustUltraVividProc(_DB_APPLY_NO_POLLING);
#endif

#if(_LOCAL_DIMMING_SUPPORT == _ON)
#if((_ASPECT_RATIO_SUPPORT == _ON) || (_ASPECT_ORIGINAL_MODE_SUPPORT == _ON))
    if(UserInterfaceGetLocalDimmingStatus() == _LD_ENABLE)
    {
        UserCommonLocalDimmingAspectRatioAdjust();
    }
#endif
#endif

    UserInterfaceAdjustActiveByPassColorProc();
}

//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustColorProc(void)
{
#if(_COLOR_PROCESS_CONTROL_BY_USER == _ON)

    UserInterfaceAdjustColorProc();

#else

#if(_COLORIMETRY_SEAMLESS_CHANGE_SUPPORT == _ON)
#if(_FREESYNC_SUPPORT == _ON)
    if(UserCommonInterfaceColorimetrySeamlessChangeCheckBypass(SysSourceGetInputPort()) == _FALSE)
    {
        if(ScalerFreeSyncGetFreeSyncInfo(SysSourceGetInputPort(), _SPD_INFO_FREESYNC_SUPPORT) == _OFF)
        {
            SET_DIGITAL_COLOR_INFO_CHANGE_RESET();
        }
    }
#endif

    UserCommonSeamlessChgAdjust(_SEAMLESS_BACKUP_SETTING);
#endif

    if(UserInterfaceGetActiveByPassStatus() == _TRUE)
    {
        UserCommonInterfaceAdjustActiveByPassColorProc();

        return;
    }

    if(ScalerTimerWaitForEvent(_EVENT_DEN_STOP) == _FALSE)
    {
        return;
    }

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    UserCommonAdjustRGBQuantizationRange();
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(UserInterfaceGetYCCQuantizationFullRangeStatus(ScalerColorGetYCCQuantizationRange()) == _TRUE)
    {
        ScalerColorSetYCCFullRange(_TRUE);
    }
    else
    {
        ScalerColorSetYCCFullRange(_FALSE);
    }
#endif

#if(_COLOR_IP_COLOR_CONVERT == _ON)
#if((_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_0) || (_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_1) || (_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_2))
    ScalerColorSpaceConvertLoadTable();
#endif
#endif

#if(_COLOR_IP_DCR == _ON)
    // Enable DCR
    ScalerColorDCREnable(_FUNCTION_ON);
#endif

    // Adjust Digital Filter
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
#if(_DIGITAL_FILTER_SUPPORT == _ON)
        ScalerColorDigitalFilterAdjust();
        ScalerColorDigitalFilterEnable(_FUNCTION_ON);
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
        UserCommonAdjustRingingFilter();
#endif

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
        UserCommonAdjustDigitalFilterEnhancePhase();
#endif
    }
    else
    {
#if(_RINGING_FILTER_SUPPORT == _ON)
        ScalerColorRingingFilterOff();
#endif

        ScalerColorDigitalFilterEnable(_FUNCTION_OFF);
    }
#endif  // End of #if(_VGA_SUPPORT == _ON)

    // Color Sampling
    ScalerColor422To444();



    UserInterfaceAdjustColorProc();

#if(_SHARPNESS_SUPPORT == _OFF)
    ScalerScalingSetScalingUpCoef();
#endif

    // Adjust Normalize Factor, should after HLW setting
#if(_DCC_FUNCTION == _ON)
    ScalerColorDCCNormalizeFactorAdjust();
#endif

    // Adjust IAPSGain
#if(_IAPS_SUPPORT == _ON)
#if(_IAPS_GAIN_COMPENSATION_TYPE == _IAPS_GAIN_COMPENSATION_GEN_0)
    ScalerColorDCCEnable(_FUNCTION_ON);
#elif(_IAPS_GAIN_COMPENSATION_TYPE == _IAPS_GAIN_COMPENSATION_GEN_1)
    ScalerColorIAPSGainEnable(_FUNCTION_ON);
#endif
#endif

#if(_HDR10_LIGHT_ENHANCE_SUPPORT == _ON)
    ScalerColorIAPSGainEnable(_FUNCTION_ON);
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
    ScalerColorSRGBEnable(_FUNCTION_ON);
#endif

#if(_I_DITHER_SUPPORT == _ON)
    // Adjust I Dithering
    UserCommonAdjustIDither();

    ScalerColorIDitherEnable(_FUNCTION_ON);
#endif

#if(_D_DITHER_SUPPORT == _ON)
#if(_D_DITHER_FREERUNEN_SUPPORT == _DISABLE)
    ScalerColorDDitherEnable(_FUNCTION_ON);
#endif
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_ULTRA_HDR_SUPPORT == _ON)
    UserCommonHDRAdjust(_HDR_FLOW_COLOR_PROC_INITIAL);
#endif

#if(_LOCAL_DIMMING_SUPPORT == _ON)
    if(UserInterfaceGetLocalDimmingStatus() == _LD_ENABLE)
    {
        UserCommonLocalDimmingInitialSetting(_ENABLE);

        if(UserCommonLocalDimmingGetEnableStatus() == _LD_ENABLE)
        {
            ScalerColorPanelUniformityEnable(_FUNCTION_ON);
            SET_LD_ACTION_MODE_STATUS(_LD_ACTION_MODE_DIMMING);
        }
        else
        {
            SET_LD_ACTION_MODE_STATUS(_LD_ACTION_MODE_NORNAL);
        }
    }
    else
    {
        UserCommonLocalDimmingInitialSetting(_DISABLE);
        SET_LD_ACTION_MODE_STATUS(_LD_ACTION_MODE_NORNAL);
    }
#endif

#if((_LOCAL_DIMMING_SUPPORT == _ON) && (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
    // D domain DB be effective
    if(ScalerGlobalGetDDomainDBStatus() == _ENABLE)
    {
        ScalerColorDDomainDBApply(_DB_APPLY_POLLING);
    }
#endif

#if(_SIX_COLOR_SUPPORT == _ON)
#if(_HDR10_SUPPORT == _ON)
       if(!((GET_OSD_HDR_MODE() != _HDR10_MODE_OFF)&&(g_stHDR10SaticMetadata.ucEOTF !=0)))
#endif
       	{
			OsdFuncSixColorAdjust();
			ScalerColorSixColorInitial();
       	}
#endif

#if(_GLOBAL_DIMMING_SUPPORT == _ON)
    if(UserCommonGlobalDimmingGetEnableStatus() == _GD_ENABLE)
    {
        UserCommonGlobalDimmingInitialSetting(_ENABLE);
    }
#endif
#endif
}
#endif

//--------------------------------------------------
// Description  : OSD Fix Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdActiveProc(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());
        UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());
        UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());
        UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());
    }
#endif

#if(_FRC_SUPPORT == _ON)
    ScalerFRCWaitWriteFrameBufFinish();
#endif

    UserInterfaceAdjustOsdActiveProc();
}

//--------------------------------------------------
// Description  : OSD Fix Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdResetProc(void)
{
    // Turn off backlight
    if(UserInterfaceGetLogoStatus() == _OFF)
    {
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)

        UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
#else
        UserCommonInterfacePanelPowerAction(_PANEL_OFF);
#endif
    }

#if(_AUDIO_SUPPORT == _ON)
    UserInterfaceAdjustAudioResetProc();
#endif

    UserInterfaceAdjustOsdResetProc();

	
#if(_VGA_SUPPORT == _ON)
    g_ucVgaCheckCounter = 30;
#endif

// Turn Off Color Functions
#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
    ScalerColorOutputGammaEnable(_FUNCTION_OFF);
#endif

#if(_RGB_GAMMA_FUNCTION == _ON)
    ScalerColorRGBOutputGammaInitial();
    ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
    ScalerColorSRGBEnable(_FUNCTION_OFF);
#endif

#if(_PCM_FUNCTION == _ON)
    ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
#endif

#if(_RGB_3D_GAMMA == _ON)
    ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);
#endif

#if(_ICM_SUPPORT == _ON)
    ScalerColorICMEnable(_FUNCTION_OFF);
#endif

#if(_COLOR_IP_DCC == _ON)
    ScalerColorDCCEnable(_FUNCTION_OFF);
#endif

#if(_YPEAKING_SUPPORT == _ON)
    ScalerColorYpeaking(_OFF);
#endif

#if(_VGA_SUPPORT == _ON)
    ScalerColorDigitalFilterEnable(_FUNCTION_OFF);

#if(_RINGING_FILTER_SUPPORT == _ON)
    ScalerColorRingingFilterOff();
#endif

#endif

#if(_COLOR_IP_DCR == _ON)
    ScalerColorDCREnable(_FUNCTION_OFF);
#endif

#if(_IAPS_SUPPORT == _ON)
#if(_IAPS_GAIN_COMPENSATION_TYPE == _IAPS_GAIN_COMPENSATION_GEN_1)
    ScalerColorIAPSGainEnable(_FUNCTION_OFF);
#endif
#endif

#if(_HDR10_LIGHT_ENHANCE_SUPPORT == _ON)
    ScalerColorIAPSGainEnable(_FUNCTION_OFF);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWEnable(_FUNCTION_OFF, _DB_APPLY_NO_POLLING);
#endif

#if(_BRIGHTNESS_SUPPORT == _ON)
    ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if(_CONTRAST_SUPPORT == _ON)
    ScalerColorContrastEnable(_FUNCTION_OFF);
#endif

#if(_I_DITHER_SUPPORT == _ON)
    ScalerColorIDitherEnable(_FUNCTION_OFF);
#endif

#if(_D_DITHER_SUPPORT == _ON)
#if(_D_DITHER_FREERUNEN_SUPPORT == _DISABLE)
    ScalerColorDDitherEnable(_FUNCTION_OFF);
#endif
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
    ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_POLLING);
#endif

#if(_COLOR_IP_COLOR_CONVERT == _ON)
    ScalerColorSpaceConvertIDomainEnable(_OFF);
    ScalerColorSpaceConvertDDomainEnable(_OFF);
#endif

#if(_UNIFORMITY_SUPPORT == _ON)
    ScalerColorPanelUniformityEnable(_FUNCTION_OFF);
#endif

#if(_LOCAL_DIMMING_SUPPORT == _ON)
    UserCommonLocalDimmingInitialSetting(_DISABLE);
#endif

#if(_GLOBAL_DIMMING_SUPPORT == _ON)
    UserCommonGlobalDimmingInitialSetting(_DISABLE);
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    // Clear MBR mode
    ScalerMbrClearRtkAdvMbrMode();
#endif
#endif


}

//--------------------------------------------------
// Description  : Adjust Max/Min Freq according to latency
// Input Value  : None
// Output Value : MaxMin Freq
//--------------------------------------------------
void UserCommonDisplayGetMDomainCustomInfo(StructDisplayCustomizedData *pstDisplayCustomizedData)
{
    StructDisplayCustomizedData stUserSetting;
    memset(&stUserSetting, 0, sizeof(stUserSetting));

    pstDisplayCustomizedData->stCustomizedMdomain.enumMemoryBitSelect = _MEMORY_REF_SOURCE_BIT;

#if(_FRC_SUPPORT == _ON)
    pstDisplayCustomizedData->stDVCustomizedFreq.b1FORCETOFREERUN = _DISABLE;
    pstDisplayCustomizedData->stDVCustomizedFreq.b1DecideMemoryConfig = _MEMORY_CONFIG_AUTO_MODE;
    pstDisplayCustomizedData->stDVCustomizedFreq.usMaxFreq = _PANEL_MAX_FRAME_RATE;
    pstDisplayCustomizedData->stDVCustomizedFreq.usTypFreq = _PANEL_TYP_FRAME_RATE;
    pstDisplayCustomizedData->stDVCustomizedFreq.usMinFreq = _PANEL_MIN_FRAME_RATE;
#endif

    memcpy(&stUserSetting, pstDisplayCustomizedData, sizeof(stUserSetting));

    UserInterfaceDisplaySelectMDomainSettingForMain(&stUserSetting.stCustomizedMdomain);

    pstDisplayCustomizedData->stCustomizedMdomain.enumMemoryBitSelect = stUserSetting.stCustomizedMdomain.enumMemoryBitSelect;

#if(_FRC_SUPPORT == _ON)
    UserInterfaceGetDVMaxMinFreq(&stUserSetting.stDVCustomizedFreq);

    pstDisplayCustomizedData->stDVCustomizedFreq.b1DecideMemoryConfig = stUserSetting.stDVCustomizedFreq.b1DecideMemoryConfig;
    pstDisplayCustomizedData->stDVCustomizedFreq.usMaxFreq = stUserSetting.stDVCustomizedFreq.usMaxFreq;
    pstDisplayCustomizedData->stDVCustomizedFreq.usTypFreq = stUserSetting.stDVCustomizedFreq.usTypFreq;
    pstDisplayCustomizedData->stDVCustomizedFreq.usMinFreq = stUserSetting.stDVCustomizedFreq.usMinFreq;

#if(_FORCE_TO_FREE_RUN_SUPPORT == _ON)
    pstDisplayCustomizedData->stDVCustomizedFreq.b1FORCETOFREERUN = _ENABLE;
#else
    pstDisplayCustomizedData->stDVCustomizedFreq.b1FORCETOFREERUN = stUserSetting.stDVCustomizedFreq.b1FORCETOFREERUN;
#endif
#endif
}

#if(_TRANSLATOR_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : Current Input Timing Info
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserCommonInterfaceAdjustInputTiming(void)
{
    UserInterfaceAdjustInputTiming();

#if(_UNDERSCAN_SUPPORT == _ON)
    UserCommonAdjustUnderScan();
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    UserCommonAdjustRotationInputSize();
#endif

#if(_OVERSCAN_SUPPORT == _ON)
    UserCommonAdjustOverScan();
#endif
}

//--------------------------------------------------
// Description  : Modify Display Timing Based on User Requirement
// Input Value  : Display region
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustDisplayTiming(void)
{
#if(_ASPECT_RATIO_SUPPORT == _ON)
    UserCommonAdjustAspectRatio();
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    UserCommonAdjustRotationDisplaySize();
#endif

    UserInterfaceAdjustDisplayTiming();
}

//--------------------------------------------------
// Description  : User Judge Ready to Active
// Input Value  : None
// Output Value : True --> Ready to Active
//                False --> Not Ready to Active
//--------------------------------------------------
bit UserCommonInterfaceReadyForActive(void)
{
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)
    if((GET_PANELPOWERSTATUS() != _READY_FOR_BACKLIGHT) && (GET_PANELPOWERSTATUS() != _BACKLIGHT_ON_ALREADY))
    {
        return _FALSE;
    }
#endif

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(UserInterfaceGetFirstAutoConfigStatus() == _TRUE)
        {
            if((g_ucVgaCheckCounter > 0) && (UserCommonAutoMeasureMultiTimes() == _FALSE))
            {
                g_ucVgaCheckCounter--;

                return _FALSE;
            }
        }
    }
#endif

    return _TRUE;
}
#endif

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : ADC Parameters Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustADCData(void)
{
    // Adjust Gain
    ScalerADCGainAdjust(g_stAdcData.pucAdcGainMSB, g_stAdcData.pucAdcGainLSB);

    // Adjust Offset
    ScalerADCOffsetAdjust(g_stAdcData.pucAdcOffsetMSB, g_stAdcData.pucAdcOffsetLSB);
}

#if(_YPBPR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get color rimetry
// Input Value  : ucModeNumber --> Target Mode Number
// Output Value : _TRUE --> current mode is HD TV Mode
//--------------------------------------------------
bit UserCommonInterfaceCheckHDTVMode(BYTE ucModeNumber)
{
    switch(ucModeNumber)
    {
        case _MODE_720x480p_60HZ:
        case _MODE_1440x480i_60HZ:
        case _MODE_720x576p_50HZ:
        case _MODE_1440x576i_50HZ:

            return _FALSE;

        case _MODE_1280x720p_60HZ:
        case _MODE_1920x1080i_50HZ:
        case _MODE_1920x1080i_60HZ:
        case _MODE_1920x1080p_50HZ:
        case _MODE_1920x1080p_60HZ:
        case _MODE_1920x1080i_50HZ_2:
        case _MODE_1280x720p_50HZ:

            return _TRUE;

        default:

            return _FALSE;
    }
}
#endif // End of #if(_YPBPR_SUPPORT == _ON)
#endif
// liuxh NoSupport
//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserCommonInterfaceCheckResolutionNoSupport(void)
{
    SET_FAIL_SAFE_MODE(_FALSE);
	
    if((GET_INPUT_TIMING_HWIDTH() == 0x00) || (GET_INPUT_TIMING_VHEIGHT() == 0x00))
    {
        return _TRUE;
    }

    if((GET_INPUT_TIMING_HFREQ() < _OOR_H_FREQ_LOWER_BOUND) || (GET_INPUT_TIMING_HFREQ() > _OOR_H_FREQ_UPPER_BOUND) ||
       (GET_INPUT_TIMING_VFREQ() > _OOR_V_FREQ_UPPER_BOUND) ||
       (GET_INPUT_TIMING_VHEIGHT() < _OOR_V_HEIGHT_LOWER_BOUND) || (GET_INPUT_TIMING_HWIDTH() > _OOR_H_WIDTH_UPPER_BOUND))
    {
        return _FALSE;
    }

    // Fail Save Mode
    if((GET_INPUT_TIMING_HFREQ() < _FAIL_SAVE_H_FREQ_LOWER_BOUND) || (GET_INPUT_TIMING_HFREQ() > _FAIL_SAVE_H_FREQ_UPPER_BOUND) ||
       (GET_INPUT_TIMING_VFREQ() > _FAIL_SAVE_V_FREQ_UPPER_BOUND))
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    }

    if(GET_INPUT_TIMING_VFREQ() < _OOR_V_FREQ_LOWER_BOUND)
    {
        return _TRUE;
    }

    if(GET_INPUT_TIMING_VFREQ() < _FAIL_SAVE_V_FREQ_LOWER_BOUND)
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserCommonInterfaceCheckNoSupport(void)
{

    if(UserCommonInterfaceCheckResolutionNoSupport() == _TRUE)
    {
        return _TRUE;
    }

    switch(SysSourceGetSourceType())
    {
#if(_VGA_SUPPORT == _ON)

        case _SOURCE_VGA:

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_VGA)
            {
                return _TRUE;
            }

            break;

#endif

#if(_DVI_SUPPORT == _ON)

        case _SOURCE_DVI:

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_DVI)
            {
                return _TRUE;
            }

            break;
#endif

#if(_HDMI_SUPPORT == _ON)

        case _SOURCE_HDMI:

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_HDMI)
            {
                return _TRUE;
            }

            if(ScalerTMDSYUV420SupportCheck(SysSourceGetInputPort()) == _FALSE)
            {
                return _TRUE;
            }

            break;

#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

#if(_DP_DYNAMIC_ADJUST_LINK_RATE_SUPPORT == _ON)
#if(_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
            if(SysSourceGetInputPort() == _D0_INPUT_PORT)
            {
                if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_USBC)
                {
                    return _TRUE;
                }

                break;
            }
#endif

#if(_D1_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
            if(SysSourceGetInputPort() == _D1_INPUT_PORT)
            {
                if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_USBC)
                {
                    return _TRUE;
                }

                break;
            }
#endif
#endif

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_DP)
            {
                return _TRUE;
            }

            break;
#endif

        default:
            break;
    }

    return (UserInterfaceGetdNoSupportStatus());
}

//--------------------------------------------------
// Description  : Check Fake Saving Status
// Input Value  : None
// Output Value : _TRUE ==> POWER STATUS FAKE SAVING, _FALSE ==> POWER STATUS SAVING
//--------------------------------------------------
bit UserCommonInterfaceCheckFakeSaving(void)
{
    if(SysPowerCheckFakeSaving() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}

#if((_FREESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
//--------------------------------------------------
// Description  : FreeSync Support Switch
// Input Value  : Check Status
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceFreeSyncSupportSwitch(void)
{
#if(((_D0_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON)) ||\
    ((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_DP_FREESYNC_SUPPORT == _ON)))
    ScalerFreeSyncSupportSwitch(_D0_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D0_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if(((_D1_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON)) ||\
    ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_DP_FREESYNC_SUPPORT == _ON)))
    ScalerFreeSyncSupportSwitch(_D1_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D1_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if(((_D2_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON)) ||\
    ((_D2_INPUT_PORT_TYPE == _D2_DP_PORT) && (_DP_FREESYNC_SUPPORT == _ON)))
    ScalerFreeSyncSupportSwitch(_D2_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D2_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if((_D3_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
    ScalerFreeSyncSupportSwitch(_D3_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D3_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if((_D4_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
    ScalerFreeSyncSupportSwitch(_D4_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D4_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if((_D5_HDMI_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
    ScalerFreeSyncSupportSwitch(_D5_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D5_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_DP_FREESYNC_SUPPORT == _ON))
    ScalerFreeSyncSupportSwitch(_D6_INPUT_PORT, UserInterfaceGetFreeSyncEnable(_D6_INPUT_PORT), SysSourceGetFreesyncInputPort());
#endif

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
#if(_DP_FREESYNC_SUPPORT == _ON)
    if(UserInterfaceGetFreeSyncEnable(_D0_INPUT_PORT) == _FREESYNC_SUPPORT_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stDpFreeSync.enumFreeSyncOnOff = _DATA_EXCHANGE_DP_FREESYNC_SUPPORT_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stDpFreeSync.enumFreeSyncOnOff = _DATA_EXCHANGE_DP_FREESYNC_SUPPORT_OFF;
    }

    SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_DP_FREESYNC_STATUS);
#endif
#endif
}

//--------------------------------------------------
// Description  : Set FreeSync Support By Port
// Input Value  : enumInputPort, enumSupport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceFreeSyncSetInputPortSupport(EnumSourceSearchPort enumSourcePort, EnumFreeSyncSupport enumSupport)
{
    ScalerFreeSyncSupportSwitch(enumSourcePort, enumSupport, SysSourceGetFreesyncInputPort());
}
#endif

#if((_DP_ADAPTIVESYNC_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
//--------------------------------------------------
// Description  : Dp AdaptiveSync Support Switch
// Input Value  : Check Status
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpAdaptiveSyncSupportSwitch(void)
{
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_DP_ADAPTIVESYNC_SUPPORT == _ON))
    ScalerDpAdaptiveSyncSupportSwitch(_D0_INPUT_PORT, UserInterfaceGetDpAdaptiveSyncEnable(_D0_INPUT_PORT));
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_DP_ADAPTIVESYNC_SUPPORT == _ON))
    ScalerDpAdaptiveSyncSupportSwitch(_D1_INPUT_PORT, UserInterfaceGetDpAdaptiveSyncEnable(_D1_INPUT_PORT));
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DP_PORT) && (_DP_ADAPTIVESYNC_SUPPORT == _ON))
    ScalerDpAdaptiveSyncSupportSwitch(_D2_INPUT_PORT, UserInterfaceGetDpAdaptiveSyncEnable(_D2_INPUT_PORT));
#endif

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
    if(UserInterfaceGetDpAdaptiveSyncEnable(_D0_INPUT_PORT) == _DP_ADAPTIVESYNC_SUPPORT_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stDpAdaptiveSync.enumDpAdaptiveSyncOnOff = _DATA_EXCHANGE_DP_ADAPTIVESYNC_SUPPORT_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stDpAdaptiveSync.enumDpAdaptiveSyncOnOff = _DATA_EXCHANGE_DP_ADAPTIVESYNC_SUPPORT_OFF;
    }

    SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_DP_ADAPTIVESYNC_STATUS);
#endif
#endif
}

//--------------------------------------------------
// Description  : Get AdaptiveSync Support
// Input Value  : ucInputPort
// Output Value : enumDpAdaptiveSyncSupport
//--------------------------------------------------
EnumDpAdaptiveSyncSupport UserCommonInterfaceDpAdaptiveSyncGetSupport(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            return GET_DP_RX0_ADAPTIVESYNC_SUPPORT();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return GET_DP_RX1_ADAPTIVESYNC_SUPPORT();
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            return GET_DP_RX2_ADAPTIVESYNC_SUPPORT();
#endif

        default:
            break;
    }

    return _DP_ADAPTIVESYNC_SUPPORT_OFF;
}

//--------------------------------------------------
// Description  : Set AdaptiveSync Support By Port
// Input Value  : enumInputPort, enumSupport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpAdaptiveSyncSetInputPortSupport(EnumSourceSearchPort enumSourcePort, EnumDpAdaptiveSyncSupport enumSupport)
{
    ScalerDpAdaptiveSyncSupportSwitch(enumSourcePort, enumSupport);
}
#endif

#if((_DRR_SUPPORT == _ON) || (_EMBEDDED_EDID_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get EDID DDC Ram Address
// Input Value  : None
// Output Value : _TRUE: Disale Global Global Double Buffer
//--------------------------------------------------
BYTE *UserCommonInterfaceEdidGetDDCRamAddress(EnumSourceSearchPort enumSearchPort)
{
    switch(enumSearchPort)
    {
#if(_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D0_INPUT_PORT:

            return MCU_DDCRAM_D0;
#endif

#if(_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D1_INPUT_PORT:
            return MCU_DDCRAM_D1;
#endif

#if(_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D2_INPUT_PORT:
            return MCU_DDCRAM_D2;
#endif

#if(_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D3_INPUT_PORT:
            return MCU_DDCRAM_D3;
#endif

#if(_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D4_INPUT_PORT:
            return MCU_DDCRAM_D4;
#endif

#if(_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE)
        case _D5_INPUT_PORT:
            return MCU_DDCRAM_D5;
#endif
        default:
            return _NULL_POINTER;
    }

    return _NULL_POINTER;
}
#endif

#if(_DDCCI_CODE_REDUCTION == _OFF)
#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Data in Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDdcciIntGetData_EXINT1(void) using 2
{
    BYTE ucTemp = 0;

    // Clear Unused DDCCI IRQ Flag
    SET_DDCCI_STATUS2(GET_DDCCI_STATUS2() & ~(_BIT5 | _BIT4));

    if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
    {
        // Clear Flags
        if((GET_DDCCI_STATUS1() & _BIT0) == _BIT0)
        {
            CLR_DDCCI_STATUS1(_BIT0);
        }

        if((GET_DDCCI_STATUS1() & _BIT1) == _BIT1)
        {
            CLR_DDCCI_STATUS1(_BIT1);
        }

        if((GET_DDCCI_STATUS1() & _BIT2) == _BIT2)
        {
            ucTemp = GET_DDCCI_DATA_IN();
            // For HP case, return Null Msg if Command isn't finish
#if(_HW_DDCCI_BUFFER_EMPTY_REPLY_NULL_MSG_SUPPORT == _ON)
            MCU_FF2A_IIC_IRQ_CONTROL2 |= _BIT6;
#endif
        }
    }
    else
    {
        SET_RUN_DDCCI_COMMAND_SRC(_DDCCI_CMD_SRC_I2C);

        if(GET_DDCCI_SLAVE_ADDRESS() == _DDCCI_DEST_ADDRESS)
        {
            SET_RUN_DDCCI_COMMAND((bit)ScalerMcuDdcciIntGetData_EXINT1(g_pucDdcciRxBuf));

#if(_DDCCI_AUTO_SWITCH_SUPPORT == _ON)
            if(GET_DDCCI_AUTO_SWITCH() == _FALSE)
            {
                ScalerMcuDdcciAutoSwitchInactiveChannel_EXINT1(_DISABLE);
            }

            if((GET_RUN_DDCCI_COMMAND() == _FAIL) && (g_ucMcuDdcciRetry == _FALSE))
            {
                if(GET_RECEIVE_DDCCI_CMD_NOT_FINISH() == _FALSE)
                {
                    SET_RECEIVE_DDCCI_CMD_NOT_FINISH();
                }
            }
            else
            {
                if(GET_RECEIVE_DDCCI_CMD_NOT_FINISH() == _TRUE)
                {
                    CLR_RECEIVE_DDCCI_CMD_NOT_FINISH();

                    ScalerTimerCancelTimerEvent_EXINT1(_SYSTEM_TIMER_EVENT_CLR_DDCCI_RECEIVE_COMMAND_NOT_FINISH);
                }
            }
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
            if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
            {
                if(UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1() == _TRUE)
                {
                    SET_RUN_DDCCI_COMMAND(_FAIL);
                }
            }
#endif

            g_ucMcuDdcciRetry = _FALSE;
        }
        else
        {
            SET_RUN_DDCCI_COMMAND((bit)UserInterfaceGetFactoryCommand_EXINT1());
        }
    }
}

//--------------------------------------------------
// Description  : Get DDC-CI Status in Interrupt Process
// Input Value  : None
// Output Value : _TURE or _False
//--------------------------------------------------
BYTE UserCommonInterfaceGetDdcciStatus_EXINT1(void) using 2
{
#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)
    if(ScalerDebugGetDdcciSwitchState_EXINT1() == _TRUE)
    {
        return _FALSE;
    }
#endif
    if((bit)UserInterfaceGetDdcciStatus_EXINT1() == _ON)
    {
        return _TRUE;
    }

    return _FALSE;
}


#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get HDMI Freesync support
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1(void) using 2
{
    BYTE ucDdcciCount = 0;

    if(UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1() == _TRUE)
    {
        if(g_pucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_SET_VCP_FEATURE)
        {
            ScalerSyncSetHDMIFREESYNCVcp_EXINT1(g_pucDdcciRxBuf[_DDCCI_SET_HIGH_BYTE]);
        }

        if(g_pucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_GET_VCP_FEATURE)
        {
            g_pucDdcciTxBuf[_DDCCI_SOURCE] = 0x6E;
            g_pucDdcciTxBuf[_DDCCI_LENGTH] = 0x88;
            g_pucDdcciTxBuf[_DDCCI_COMMAND] = 0x02;
            g_pucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
            g_pucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_pucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];
            g_pucDdcciTxBuf[_DDCCI_TYPE_CODE] = 0x00;
            g_pucDdcciTxBuf[_DDCCI_MAX_HIGH_BYTE] = 0x00;
            g_pucDdcciTxBuf[_DDCCI_MAX_LOW_BYTE] = 0x00;
            g_pucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE] = ScalerSyncGetHDMIFREESYNCVcp_EXINT1();
            g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE] = ScalerFreeSyncHDMIGetFreeSyncSupport_EXINT1(ScalerMcuDdcciGetInputPort_EXINT1());

            g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = (((0xB4 ^ g_pucDdcciTxBuf[_DDCCI_SINK_OPCODE]) ^ g_pucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE]) ^ g_pucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE]);

            // Enable mcu write
            MCU_FF2A_IIC_IRQ_CONTROL2 |= (_BIT6 | _BIT5);

            while(ucDdcciCount < 11)
            {
                // Load data to DDC-CI buffer
                MCU_FF26_IIC_DATA_OUT = g_pucDdcciTxBuf[ucDdcciCount++];
            }

            // Disable mcu write
            MCU_FF2A_IIC_IRQ_CONTROL2 &= ~_BIT5;

            // Clear buffer for new message
            memset(g_pucDdcciRxBuf, 0, _DDCCI_RXBUF_LENGTH);
        }

        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif

#endif
#endif

#if(_SYSTEM_LOW_POWER_IDLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Run DDCCI command
// Input Value  : None
// Output Value : _ON => DDCCI Support ON
//--------------------------------------------------
bit UserCommonInterfaceGetRunDdcciCommand(void)
{
#if(_DDCCI_CODE_REDUCTION == _OFF)
    return GET_RUN_DDCCI_COMMAND();
#else
    return _FALSE;
#endif
}
#endif


#if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)

BYTE DefaultSNStartAddr = 0;

#if 0//_OVERCLOCK_SUPPORT && ENABLE_OVERCLOCK_DEF_ON
#define  SN_BASE_EDID_ADDR        _EDID_D1_ADDRESS_FLASH_OVERCLOCK
#else
#if _PROJECT == _RL6463_PROJECT
#define  SN_BASE_EDID_ADDR        _EDID_A0_ADDRESS_FLASH
#else

#endif
#endif

#define _EDID_SN_LENTH                         18 

BYTE CHAGEEDID(BYTE *pucEdidAddr,BYTE enumInputPort)
{
	BYTE j = 0;
	BYTE addr = 0;
    BYTE ucCount = 0;
	
#ifndef _SN_ADDR
	static BYTE EDID_RAED[128];


	enumInputPort = enumInputPort ;

	if(!DefaultSNStartAddr)
	{
		UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_D1_ADDRESS_FLASH, 128, EDID_RAED);

		for(j = 0x36;j <= 0x6C;j = j+18)
		{
			if(EDID_RAED[j+0] == 0 && EDID_RAED[j+1] == 0 && EDID_RAED[j+2] == 0 && EDID_RAED[j+3] == 0xFF && EDID_RAED[j+4] == 0)
			{
	           DefaultSNStartAddr = j;	
			   
			   memcpy(g_stSNData, &EDID_RAED[j+5], _EDID_SN_LENTH - 5);
			   break;
			}
		}
	}

	#if 0// _PROJECT == _RL6463_PROJECT
		return 0;
	#endif

	if(DefaultSNStartAddr == 0)
		return 0;
		
	addr = 0;
	for(j = 0x36;j <= 0x6C;j = j+18)
	{
		if(pucEdidAddr[j] == 0 && pucEdidAddr[j+1] == 0 && pucEdidAddr[j+2] == 0 && pucEdidAddr[j+3] == 0xFF && pucEdidAddr[j+4] == 0)
		{
			addr = j;
		   break;
		}
	}
	if(addr == 0)
		return 0;
	
	memcpy(&pucEdidAddr[0X10],&EDID_RAED[0X10],2);

	memcpy(&pucEdidAddr[addr+5],&EDID_RAED[DefaultSNStartAddr+5],13);

	j=0;
	for(ucCount = 0; ucCount < 127; ucCount++)
	j += pucEdidAddr[ucCount];

	pucEdidAddr[0x7f]=0x100-j;


#else

	static BYTE EDID_RAED[15];
#if 0//(_D0_INPUT_PORT_TYPE  != _D0_NO_PORT)
	if(enumInputPort == _D0_INPUT_PORT_EDID)
	{
		UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_D0_ADDRESS_FLASH+0x10, 2, &EDID_RAED[13]);
		UserCommonFlashRead(_EDID_FLASH_BANK,_EDID_D0_ADDRESS_FLASH+_SN_ADDR, 13, EDID_RAED);

	}
#else
	//if(enumInputPort == _D1_INPUT_PORT_EDID)
	{
		UserCommonFlashRead(_EDID_FLASH_BANK,SN_BASE_EDID_ADDR+0x10, 2, &EDID_RAED[13]);
		UserCommonFlashRead(_EDID_FLASH_BANK,SN_BASE_EDID_ADDR+_SN_ADDR, 13, EDID_RAED);
	}
#endif

		memcpy(&pucEdidAddr[0X10],&EDID_RAED[13],2);
		memcpy(&pucEdidAddr[_SN_ADDR],&EDID_RAED[0],13);

		memcpy(g_stSNData, &EDID_RAED[0], 13);
		
		j=0;
		for(ucCount = 0; ucCount < 127; ucCount++)
		j += pucEdidAddr[ucCount];
		
		pucEdidAddr[0x7f]=0x100-j;



#if(_DSC_DECODER_SUPPORT == _ON)

	if(UserInterfaceDscDecoderGetEnable(_D3_INPUT_PORT_EDID) == _DSC_DECODER_SUPPORT_OFF)
	{

		addr = 0;
		if(enumInputPort == _D3_INPUT_PORT_EDID   ||  enumInputPort == _D4_INPUT_PORT_EDID  )
		{
			
			for(j = 128;j < 250;j++)
			{
				if(pucEdidAddr[j+1] == 0xD8 && pucEdidAddr[j+2] == 0x5D && pucEdidAddr[j+3] == 0xC4  &&pucEdidAddr[j]>0x6C)
				{
					addr = j;
				   break;
				}
			}


			if(addr!=0)
			{

				j= pucEdidAddr[addr+12];
				
				pucEdidAddr[addr+12] = 0x00;
				pucEdidAddr[255] +=j;		
				
			}
					
		}

	}
	

	
#endif





#endif
	return _TRUE;
}

//--------------------------------------------------
// Description  : Restore default EDID
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceNVRamRestoreEDID(void)
{
    BYTE ucCount = 0;
    BYTE pucBuffer[16] = {0};

    // prevent unreferenced warning
    ucCount = pucBuffer[0];

#if(_EDID_TABLE_LOCATED_IN_FLASH == _ON)
	#if _A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
    UserCommonFlashErasePage(_EDID_FLASH_BANK, _EDID_A0_ADDRESS_FLASH/_FLASH_PAGE_SIZE);
	#endif
    #if _D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
    UserCommonFlashErasePage(_EDID_FLASH_BANK, _EDID_D0_ADDRESS_FLASH/_FLASH_PAGE_SIZE);
	#endif
	#if _D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
    UserCommonFlashErasePage(_EDID_FLASH_BANK, _EDID_D1_ADDRESS_FLASH/_FLASH_PAGE_SIZE);
	#endif
	#if _D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
    UserCommonFlashErasePage(_EDID_FLASH_BANK, _EDID_D2_ADDRESS_FLASH/_FLASH_PAGE_SIZE);
	#endif
	#if _D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE
    UserCommonFlashErasePage(_EDID_FLASH_BANK, _EDID_D3_ADDRESS_FLASH/_FLASH_PAGE_SIZE);
	#endif
#endif

// A0 EDID-----------------------------------------------------------------------------------------------------------
#if((_A0_INPUT_PORT_TYPE != _A0_NO_PORT) && (_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_A0_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_A0 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_A0_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_A0_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D0 EDID-----------------------------------------------------------------------------------------------------------
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D0_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D0 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D0_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D0_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D1 EDID-----------------------------------------------------------------------------------------------------------
#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D1_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D1 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D1_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D1_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D2 EDID-----------------------------------------------------------------------------------------------------------
#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D2_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D2 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D2_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D2_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D3 EDID-----------------------------------------------------------------------------------------------------------
#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D3_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D3 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D3_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D3_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D4 EDID-----------------------------------------------------------------------------------------------------------
#if((_D4_INPUT_PORT_TYPE == _D4_NO_PORT) && (_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D4_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D4 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D4_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D4_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D5 EDID-----------------------------------------------------------------------------------------------------------
#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D5_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D5 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D5_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D5_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D6 EDID-----------------------------------------------------------------------------------------------------------
#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE) && ((_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D6_EMBEDDED_DDCRAM_MAX_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D6 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D6_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D6_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D0 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D0_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D0_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D0_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D0_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D1 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D1_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D1_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D1_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D1_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D2 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D2_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D2_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D2_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D2_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D3 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D3_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D3_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D3_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D3_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D4 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D4_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D4_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D4_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D4_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif

// D5 MHL EDID-------------------------------------------------------------------------------------------------------
#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && ((_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM) || (_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)))
    for(ucCount = 0; ucCount < (_D5_MHL_EMBEDDED_DDCRAM_SIZE / sizeof(pucBuffer)); ucCount++)
    {
        memcpy(pucBuffer, tEDID_TABLE_D5_MHL + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
#if(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonEepromRestoreEDID(_EDID_D5_MHL_ADDRESS_EEPROM + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#elif(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
        UserCommonFlashRestoreEDID(_EDID_D5_MHL_ADDRESS_FLASH + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
#endif
    }
#endif
}
#endif // End of #if(_WRITE_EDID_TO_SYSTEM_EEPROM == _ON)

#if(_EMBEDDED_EDID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Edid Info Parse
// Input Value  : ucInputport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceEdidEmbeddedInfoParser(BYTE ucInputport)
{
    WORD pusCtaDataBlockAddr[_CTA_TOTAL_DB] = {0};
    WORD pusDidDataBlockAddr[_DID_TOTAL_DB] = {0};

    BYTE *pucEdidAddr = UserCommonInterfaceEdidGetDDCRamAddress(ucInputport);

#if(_FREESYNC_SUPPORT == _ON)
    EnumAmdVsdbVer enumAmdVer = _AMD_VER_NONE;
#endif

    // Scan & Get the DB Start Addr form Raw Edid
    ScalerSyncGetCtaExtDbAddress(pusCtaDataBlockAddr, pucEdidAddr);
    ScalerSyncGetDidExtDbAddress(pusDidDataBlockAddr, pucEdidAddr);

#if(_FREESYNC_SUPPORT == _ON)
    if(pusCtaDataBlockAddr[_CTA_FS_DB] != 0)
    {
        WORD usAmdVsdbStartAddr = pusCtaDataBlockAddr[_CTA_FS_DB];
        enumAmdVer = (pucEdidAddr[usAmdVsdbStartAddr + 4]);
    }

    ScalerSyncSetAmdVsdbVer(ucInputport, enumAmdVer);
#endif

#if(_HDMI21_VRR_SUPPORT == _ON)
    // reset EDID info for all HDMI Rx
    ScalerTMDSMacRxClrEdidVrrCapability(ucInputport);

    if(pusCtaDataBlockAddr[_CTA_HF_VSDB] != 0)
    {
        WORD usHfVsdbStartAddr = pusCtaDataBlockAddr[_CTA_HF_VSDB];

        StructHdmi21EdidVrrCap stHdmi21EdidVrr;
        memset(&stHdmi21EdidVrr, 0, sizeof(stHdmi21EdidVrr));

        if((pucEdidAddr[usHfVsdbStartAddr] & (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 8)
        {
            stHdmi21EdidVrr.b1EdidQms = ((pucEdidAddr[usHfVsdbStartAddr + 8] & _BIT6) >> 6);

            if((pucEdidAddr[usHfVsdbStartAddr] & (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 10)
            {
                stHdmi21EdidVrr.ucEdidVrrMin = (pucEdidAddr[usHfVsdbStartAddr + 9] & (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
                stHdmi21EdidVrr.usEdidVrrMax = (((pucEdidAddr[usHfVsdbStartAddr + 9] & (_BIT7 | _BIT6)) << 2) | (pucEdidAddr[usHfVsdbStartAddr + 10]));

                if((pucEdidAddr[usHfVsdbStartAddr] & (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) >= 11)
                {
                    stHdmi21EdidVrr.b1EdidQmsTfrMin = ((pucEdidAddr[usHfVsdbStartAddr + 11] & _BIT4) >> 4);
                    stHdmi21EdidVrr.b1EdidQmsTfrMax = ((pucEdidAddr[usHfVsdbStartAddr + 11] & _BIT5) >> 5);
                }
            }
        }

        ScalerTMDSMacRxSetEdidVrrCapability(ucInputport, stHdmi21EdidVrr);
    }
#endif
}

//--------------------------------------------------
// Description  : Set Embedded EDID Data of AC ON
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceLoadEmbeddedEdidData(void)
{
// A0 EDID-----------------------------------------------------------------------------------------------------------
#if((_A0_INPUT_PORT_TYPE != _A0_NO_PORT) && (_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_A0_INPUT_PORT_EDID);

    // DDC Force Nack Off
    ScalerSyncSetDdcForceNack(_A0_INPUT_PORT, _OFF);

#endif // End of #if((_A0_INPUT_PORT_TYPE != _A0_NO_PORT) && (_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D6 EDID-----------------------------------------------------------------------------------------------------------
#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D6_INPUT_PORT_EDID);

#endif // End of #if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D0 EDID-----------------------------------------------------------------------------------------------------------
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D0_INPUT_PORT_EDID);

#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D0_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D0_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D0_INPUT_PORT);
    }

#endif // End of #if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D1 EDID-----------------------------------------------------------------------------------------------------------
#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D1_INPUT_PORT_EDID);

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D1_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D1_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D1_INPUT_PORT);
    }

#endif // End of #if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D2 EDID-----------------------------------------------------------------------------------------------------------
#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D2_INPUT_PORT_EDID);

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D2_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D2_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D2_INPUT_PORT);
    }

#endif // End of #if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D3 EDID-----------------------------------------------------------------------------------------------------------
#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D3_INPUT_PORT_EDID);

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D3_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D3_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D3_INPUT_PORT);
    }

#endif // End of #if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D4 EDID-----------------------------------------------------------------------------------------------------------
#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D4_INPUT_PORT_EDID);

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D4_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D4_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D4_INPUT_PORT);
    }

#endif // End of #if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D5 EDID-----------------------------------------------------------------------------------------------------------
#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D5_INPUT_PORT_EDID);

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(UserCommonInterfaceHDMIGetMultiEdidLocated(_D5_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT)) != _HDMI_EDID_EXTERNAL)
#endif
    {
        // DDC Force Nack Off
        ScalerSyncSetDdcForceNack(_D5_INPUT_PORT, _OFF);

        // Edid Parse Info (from DDCRAM only)
        UserCommonInterfaceEdidEmbeddedInfoParser(_D5_INPUT_PORT);
    }

#endif // End of #if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))

// D0 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D0_INPUT_PORT_MHL_EDID);
#endif

// D1 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D1_INPUT_PORT_MHL_EDID);
#endif

// D2 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D2_INPUT_PORT_MHL_EDID);
#endif

// D3 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D3_INPUT_PORT_MHL_EDID);
#endif

// D4 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D4_INPUT_PORT_MHL_EDID);
#endif

// D5 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
    UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D5_INPUT_PORT_MHL_EDID);
#endif
}

//--------------------------------------------------
// Description  : Set Embedded EDID Data for Input Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceLoadEmbeddedEdidDataByPort(EnumInputPortEdid enumInputPort)
{
    BYTE *pucEdidAddr = _NULL_POINTER;
    switch(enumInputPort)
    {
// A0 EDID-----------------------------------------------------------------------------------------------------------
#if((_A0_INPUT_PORT_TYPE != _A0_NO_PORT) && (_A0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _A0_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_A0;
#if(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_A0, 0, _A0_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_A0, tEDID_TABLE_A0, _A0_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_A0_ADDRESS_EEPROM, _A0_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_A0);
#elif(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_A0_ADDRESS_FLASH), _A0_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_A0);
#elif(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_A0_INPUT_PORT_EDID);
#endif

            break;
#endif

// D0 EDID-----------------------------------------------------------------------------------------------------------
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D0_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D0;
#if(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)

			if (GET_OSD_DP_VERSION_11_STATUS())
			{
	            memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
	            memcpy(MCU_DDCRAM_D0, tEDID_TABLE_D1_1, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
			}
			else
			{
				memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
	            memcpy(MCU_DDCRAM_D0, tEDID_TABLE_D0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
			}
			
#elif(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D0_ADDRESS_EEPROM, _D0_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D0);
#elif(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D0_ADDRESS_FLASH), _D0_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D0);
            memset(MCU_DDCRAM_D0, 0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D0, tEDID_TABLE_D0, _D0_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D0_INPUT_PORT_EDID);
#endif

            break;
#endif

// D1 EDID-----------------------------------------------------------------------------------------------------------
#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D1_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D1;
#if(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D1, 0, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D1, tEDID_TABLE_D1, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D1_ADDRESS_EEPROM, _D1_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D1);
#elif(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D1_ADDRESS_FLASH), _D1_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D1);
            if (GET_OSD_DP_VERSION_11_STATUS())
           	{
            	memset(MCU_DDCRAM_D1, 0, 256);
            	memcpy(MCU_DDCRAM_D1, tEDID_TABLE_D1_1, 256);
           	}
		    else
		    {
            	memset(MCU_DDCRAM_D1, 0, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
            	memcpy(MCU_DDCRAM_D1, tEDID_TABLE_D1, _D1_EMBEDDED_DDCRAM_MAX_SIZE);
			}
#elif(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D1_INPUT_PORT_EDID);
#endif

            break;
#endif

// D2 EDID-----------------------------------------------------------------------------------------------------------
#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D2_INPUT_PORT_EDID:
            pucEdidAddr = MCU_DDCRAM_D2;
#if(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D2, 0, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D2, tEDID_TABLE_D2, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D2_ADDRESS_EEPROM, _D2_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D2);
#elif(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D2_ADDRESS_FLASH), _D2_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D2);
            memset(MCU_DDCRAM_D2, 0, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D2, tEDID_TABLE_D2, _D2_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D2_INPUT_PORT_EDID);
#endif

            break;
#endif

// D3 EDID-----------------------------------------------------------------------------------------------------------
#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D3_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D3;
#if(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D3, 0, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D3, tEDID_TABLE_D3, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D3_ADDRESS_EEPROM, _D3_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D3);
#elif(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D3_ADDRESS_FLASH), _D3_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D3);
            memset(MCU_DDCRAM_D3, 0, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D3, tEDID_TABLE_D3, _D3_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D3_INPUT_PORT_EDID);
#endif

            break;
#endif

// D4 EDID-----------------------------------------------------------------------------------------------------------
#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D4_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D4;
#if(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D4, 0, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D4, tEDID_TABLE_D4, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D4_ADDRESS_EEPROM, _D4_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D4);
#elif(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D4_ADDRESS_FLASH), _D4_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D4);
            memset(MCU_DDCRAM_D4, 0, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D4, tEDID_TABLE_D4, _D4_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D4_INPUT_PORT_EDID);
#endif

            break;
#endif

// D5 EDID-----------------------------------------------------------------------------------------------------------
#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D5_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D5;
#if(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D5, 0, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D5, tEDID_TABLE_D5, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D5_ADDRESS_EEPROM, _D5_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D5);
#elif(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D5_ADDRESS_FLASH), _D5_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D5);
            memset(MCU_DDCRAM_D5, 0, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D5, tEDID_TABLE_D5, _D5_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D5_INPUT_PORT_EDID);
#endif

            break;
#endif

// D6 EDID-----------------------------------------------------------------------------------------------------------
#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D6_INPUT_PORT_EDID:
			pucEdidAddr = MCU_DDCRAM_D6;
#if(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memset(MCU_DDCRAM_D6, 0, _D6_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D6, tEDID_TABLE_D6, _D6_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D6_ADDRESS_EEPROM, _D6_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D6);
#elif(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            //UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D6_ADDRESS_FLASH), _D6_EMBEDDED_DDCRAM_MAX_SIZE, MCU_DDCRAM_D6);
            memset(MCU_DDCRAM_D6, 0, _D6_EMBEDDED_DDCRAM_MAX_SIZE);
            memcpy(MCU_DDCRAM_D6, tEDID_TABLE_D6, _D6_EMBEDDED_DDCRAM_MAX_SIZE);
#elif(_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D6_INPUT_PORT_EDID);
#endif

            break;
#endif

// D0 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#if(_D0_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D0_INPUT_PORT_MHL_EDID:

#if(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D0, tEDID_TABLE_D0_MHL, _D0_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D0_MHL_ADDRESS_EEPROM, _D0_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D0);
#elif(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D0_MHL_ADDRESS_FLASH), _D0_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D0);
#elif(_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D0_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

// D1 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#if(_D1_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D1_INPUT_PORT_MHL_EDID:

#if(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D1, tEDID_TABLE_D1_MHL, _D1_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D1_MHL_ADDRESS_EEPROM, _D1_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D1);
#elif(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D1_MHL_ADDRESS_FLASH), _D1_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D1);
#elif(_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D1_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

// D2 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#if(_D2_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D2_INPUT_PORT_MHL_EDID:

#if(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D2, tEDID_TABLE_D2_MHL, _D2_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D2_MHL_ADDRESS_EEPROM, _D2_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D2);
#elif(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D2_MHL_ADDRESS_FLASH), _D2_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D2);
#elif(_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D2_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

// D3 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
#if(_D3_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D3_INPUT_PORT_MHL_EDID:

#if(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D3, tEDID_TABLE_D3_MHL, _D3_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D3_MHL_ADDRESS_EEPROM, _D3_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D3);
#elif(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D3_MHL_ADDRESS_FLASH), _D3_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D3);
#elif(_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D3_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

// D4 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#if(_D4_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D4_INPUT_PORT_MHL_EDID:

#if(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D4, tEDID_TABLE_D4_MHL, _D4_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D4_MHL_ADDRESS_EEPROM, _D4_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D4);
#elif(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D4_MHL_ADDRESS_FLASH), _D4_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D4);
#elif(_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D4_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

// D5 MHL EDID--------------------------------------------------------------------------------------------------------
#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
#if(_D5_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
        case _D5_INPUT_PORT_MHL_EDID:

#if(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)
            memcpy(MCU_DDCRAM_MHL_D5, tEDID_TABLE_D5_MHL, _D5_MHL_EMBEDDED_DDCRAM_SIZE);
#elif(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
            UserCommonNVRamRead(_EDID_D5_MHL_ADDRESS_EEPROM, _D5_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D5);
#elif(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_FLASH)
            UserCommonFlashRead(_EDID_FLASH_BANK, (_EDID_D5_MHL_ADDRESS_FLASH), _D5_MHL_EMBEDDED_DDCRAM_SIZE, MCU_DDCRAM_MHL_D5);
#elif(_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER)
            UserInterfaceGetEmbeddedEDIDData(_D5_INPUT_PORT_MHL_EDID);
#endif

            break;
#endif
#endif

        default:
            break;
    }

	#if 0//_PROJECT == _RL6463_PROJECT

	#else
	 	CHAGEEDID(pucEdidAddr,enumInputPort);
	#endif
	
}


#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set DP Embedded EDID Data
// Input Value  : ucSelectedPort
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDPSwitchEdid(BYTE ucSelectedPort)
{
    switch(ucSelectedPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

            UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D0_INPUT_PORT_EDID);
            ScalerDpEdidSwitch(_D0_INPUT_PORT);

            // Edid Parse Info (from DDCRAM only)
            UserCommonInterfaceEdidEmbeddedInfoParser(_D0_INPUT_PORT);

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D1_INPUT_PORT_EDID);
            ScalerDpEdidSwitch(_D1_INPUT_PORT);

            // Edid Parse Info (from DDCRAM only)
            UserCommonInterfaceEdidEmbeddedInfoParser(_D1_INPUT_PORT);

            break;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)

        case _D2_INPUT_PORT:

            UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D2_INPUT_PORT_EDID);
            ScalerDpEdidSwitch(_D2_INPUT_PORT);

            // Edid Parse Info (from DDCRAM only)
            UserCommonInterfaceEdidEmbeddedInfoParser(_D2_INPUT_PORT);

            break;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)

        case _D6_INPUT_PORT:

            UserCommonInterfaceLoadEmbeddedEdidDataByPort(_D6_INPUT_PORT_EDID);
            ScalerDpEdidSwitch(_D6_INPUT_PORT);

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Switch DP ports Embedded EDID Data
// Input Value  : void
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDPSwitchAllPortEdid(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    UserCommonInterfaceDPSwitchEdid(_D0_INPUT_PORT);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    UserCommonInterfaceDPSwitchEdid(_D1_INPUT_PORT);
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    UserCommonInterfaceDPSwitchEdid(_D2_INPUT_PORT);
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
    UserCommonInterfaceDPSwitchEdid(_D6_INPUT_PORT);
#endif
}
#endif // End of #if(_DP_SUPPORT == _ON)

#endif // End of #if(_EMBEDDED_EDID_SUPPORT == _ON)

#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HW_PC99_SUPPORT == _ON))
//--------------------------------------------------
// Description  : PC99 EDID Write Command Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfacePC99EDIDWriteCommandData(void)
{
    BYTE pucPC99CommandData[] =
    {
        #include "./Pc99CommandTable.h"
    };

    UserCommonFlashWrite(_HW_PC99_WRITE_EDID_COMMAND_BANK_INDEX, _HW_PC99_WRITE_EDID_COMMAND_ADDR_START, sizeof(pucPC99CommandData), pucPC99CommandData);
}
#endif // End of #if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HW_PC99_SUPPORT == _ON))

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Switch HDMI EDID from user OSD
// Input Value  : ucInputport
//                enumHDMIEDIDSelection --> Edid Index
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMISwitchEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection)
{
    if(UserCommonInterfaceCheckMultiEdidSupport(ucInputport) == _TRUE)
    {
        // Before Reload Edid Process
        UserCommonInterfaceHDMIBeforeReloadEdid(ucInputport, enumHDMIEDIDSelection);

        // Reload Edid Process
#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
        UserCommonInterfaceHDMIReloadEdid(ucInputport);
#endif

        // After Reload Edid Process
        UserCommonInterfaceHDMIAfterReloadEdid(ucInputport, enumHDMIEDIDSelection);

        // Edid Parser for New Edid
#if(_EMBEDDED_EDID_SUPPORT == _ON)
        if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputport, enumHDMIEDIDSelection) == _HDMI_EDID_EMBEDDED)
        {
            // Edid Parse Info (from DDCRAM only)
            UserCommonInterfaceEdidEmbeddedInfoParser(ucInputport);
        }
        else
#endif
        {
            // Edid Parse don't support External
            UserCommonInterfaceHdmiExternalInfoParser(ucInputport);
        }

        // HPD Trigger Event Set
        ScalerSyncTMDSEdidSwitch(ucInputport);
    }
    else
    {
        DebugMessageSystem("Current InputPort Not Support Multi-Edid Switch", ucInputport);
    }
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_HDR10_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Switch HDMI EDID from user OSD
// Input Value  : ucInputport
//                enumHDMIEDIDSelection --> Edid Index
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMISwitchAllPortEdid(void)
{
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D0_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT));
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D1_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT));
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D2_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT));
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D3_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT));
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D4_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT));
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D5_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT));
#endif
}
#endif

//--------------------------------------------------
// Description  : Get the HDMI Port Edid location
// Input Value  : ucInputport
// Output Value : location of the Edid index
//--------------------------------------------------
EnumHdmiEdidLocation UserCommonInterfaceHDMIGetMultiEdidLocated(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection)
{
    ucInputport -= _D0_INPUT_PORT;

    if(enumHDMIEDIDSelection < _HDMI_EXT_EDID_MAX_CNT)
    {
        return UserInterfaceGetMultiHdmiEdidLocated(ucInputport, enumHDMIEDIDSelection);
    }
    else
    {
        return _HDMI_EDID_EMBEDDED;
    }
}

#if((_TMDS_FS_ON_ONLY_TARGETPORT_HPD_SUPPORT == _ON) && (_HDMI_FREESYNC_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Switch HDMI EDID from user OSD
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHdmiSwitchAllPortEdidToggleTargetPortHpd(void)
{
    EnumSourceSearchPort enumFreesyncTargetPort = SysSourceGetFreesyncInputPort();

#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D0_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT));

    if(enumFreesyncTargetPort != _D0_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D0_INPUT_PORT);
    }
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D1_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT));

    if(enumFreesyncTargetPort != _D1_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D1_INPUT_PORT);
    }
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D2_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT));

    if(enumFreesyncTargetPort != _D2_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D2_INPUT_PORT);
    }
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D3_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT));

    if(enumFreesyncTargetPort != _D3_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D3_INPUT_PORT);
    }
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D4_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT));

    if(enumFreesyncTargetPort != _D4_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D4_INPUT_PORT);
    }
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
    UserCommonInterfaceHDMISwitchEdid(_D5_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT));

    if(enumFreesyncTargetPort != _D5_INPUT_PORT)
    {
        ScalerSyncTMDSClrHPDTriggerEvent(_D5_INPUT_PORT);
    }
#endif
}
#endif

//--------------------------------------------------
// Description  : Get the HDMI Port Edid Max Count
// Input Value  : ucInputport
// Output Value : Max Cnt of the Port
//--------------------------------------------------
BYTE UserCommonInterfaceGetHdmiEdidCount(BYTE ucInputport)
{
    switch(ucInputport)
    {
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return _D0_MAX_HDMI_EDID_COUNT;
            break;
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return _D1_MAX_HDMI_EDID_COUNT;
            break;
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return _D2_MAX_HDMI_EDID_COUNT;
            break;
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            return _D3_MAX_HDMI_EDID_COUNT;
            break;
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            return _D4_MAX_HDMI_EDID_COUNT;
            break;
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            return _D5_MAX_HDMI_EDID_COUNT;
            break;
#endif

        default:
            return 1;
            break;
    }
    return 0;
}

//--------------------------------------------------
// Description  : Check Multi EDID Support
// Input Value  : enumInputPort
// Output Value : True/False
//--------------------------------------------------
bit UserCommonInterfaceCheckMultiEdidSupport(BYTE ucInputport)
{
    switch(ucInputport)
    {
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return _TRUE;
            break;
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return _TRUE;
            break;
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return _TRUE;
            break;
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            return _TRUE;
            break;
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            return _TRUE;
            break;
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            return _TRUE;
            break;
#endif

        default:
            return _FALSE;
            break;
    }
    return _FALSE;
}

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Switch HDMI EDID process -- Reload Edid
// Input Value  : enumHDMIEDIDSelection --> Edid Index
//                ucInputport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMIReloadEdid(BYTE ucInputport)
{
    switch(ucInputport)
    {
#if((_D0_HDMI_SUPPORT == _ON) &&\
    (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D0_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D0_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D0_INPUT_PORT_EDID);
            break;
#endif

#if((_D1_HDMI_SUPPORT == _ON) &&\
    (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D1_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D1_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D1_INPUT_PORT_EDID);


            break;
#endif

#if((_D2_HDMI_SUPPORT == _ON) &&\
    (_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D2_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D2_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D2_INPUT_PORT_EDID);

            break;
#endif

#if((_D3_HDMI_SUPPORT == _ON) &&\
    (_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D3_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D3_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D3_INPUT_PORT_EDID);

            break;
#endif

#if((_D4_HDMI_SUPPORT == _ON) &&\
    (_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D4_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D4_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D4_INPUT_PORT_EDID);

            break;
#endif

#if((_D5_HDMI_SUPPORT == _ON) &&\
    (_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER) &&\
    (_D5_EMBEDDED_DDCRAM_MAX_SIZE != _EDID_SIZE_NONE))
        case _D5_INPUT_PORT:

            UserInterfaceGetEmbeddedEDIDData(_D5_INPUT_PORT_EDID);

            break;
#endif

        default:

            break;
    }
}
#endif

//--------------------------------------------------
// Description  : Switch HDMI EDID process before reload Edid
// Input Value  : enumHDMIEDIDSelection --> Edid Index
//                ucInputport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMIBeforeReloadEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection)
{
    bit b1DdcStatus = 0;

    b1DdcStatus = ScalerSyncGetDdcForceNackStatus(ucInputport);

    // Check for Ddc Busy
    ScalerSyncHDMIDdcCheckBusy(ucInputport, _DELAY_30US_TIMESCALE, 1, 1500);

    // Force nack Ddc Channel
    ScalerSyncSetDdcForceNack(ucInputport, _ON);

    if(b1DdcStatus == _FALSE)
    {
        BYTE ucEdidCount = UserCommonInterfaceGetHdmiEdidCount(ucInputport);

        if(ucEdidCount > 1)
        {
            if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputport, enumHDMIEDIDSelection) != _HDMI_EDID_EXTERNAL)
            {
                BYTE ucTempEEPROM = 0;
                BYTE ucLoopStop = MINOF(ucEdidCount, _HDMI_EXT_EDID_MAX_CNT);

                for(ucTempEEPROM; ucTempEEPROM < ucLoopStop; ++ucTempEEPROM)
                {
                    if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputport, ucTempEEPROM) == _HDMI_EDID_EXTERNAL)
                    {
                        UserCommonInterfaceHDMISwitchMultiEeprom(ucInputport, ucTempEEPROM);
                        break;
                    }
                }
            }
        }
    }
}

//--------------------------------------------------
// Description  : Switch HDMI EDID process after reload Edid
// Input Value  : enumHDMIEDIDSelection --> Edid Index
//                ucInputport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMIAfterReloadEdid(BYTE ucInputport, EnumEdidSelection enumHDMIEDIDSelection)
{
    BYTE ucEdidCount = UserCommonInterfaceGetHdmiEdidCount(ucInputport);

    // If Target Edid: External--> Open the Target Eeprom
    UserCommonInterfaceHDMISwitchMultiEeprom(ucInputport, enumHDMIEDIDSelection);

    if(ucEdidCount > 1)
    {
        if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputport, enumHDMIEDIDSelection) != _HDMI_EDID_EXTERNAL)
        {
            ScalerSyncSetDdcForceNack(ucInputport, _OFF);
        }
    }
}

//--------------------------------------------------
// Description  : All port external EDID switch turn on/off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMIMultiEdidInitial(void)
{
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D0 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D0_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D0_INPUT_PORT));
#endif

#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D1 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D1_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D1_INPUT_PORT));
#endif

#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D2 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D2_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D2_INPUT_PORT));
#endif

#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D3 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D3_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D3_INPUT_PORT));
#endif

#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D4 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D4_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D4_INPUT_PORT));
#endif

#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
    // D5 External Edid Config Setting
    UserCommonInterfaceHDMISwitchMultiEeprom(_D5_INPUT_PORT, UserInterfaceGetMultiHdmiEdidIndex(_D5_INPUT_PORT));
#endif
}

//--------------------------------------------------
// Description  : Multi Edid switch
// Input Value  : Input TMDS Port
//                enumHDMIEDIDSelection --> Edid Index
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHDMISwitchMultiEeprom(BYTE ucInputPort, EnumEdidSelection enumHDMIEDIDSelection)
{
    BYTE ucEdidCount = UserCommonInterfaceGetHdmiEdidCount(ucInputPort);

    if(ucEdidCount > 1)
    {
        PCB_MULTI_EDID_SWITCH(ucInputPort, enumHDMIEDIDSelection);

        if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputPort, enumHDMIEDIDSelection) != _HDMI_EDID_EXTERNAL)
        {
            // Turn off All External Edid's GPO
            PCB_MULTI_EDID_ALL_SWITCH_OFF(ucInputPort);
        }
    }
}

#endif // End of #if(_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : All port external EDID Parser
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHdmiAllPortExternalEdidParser(void)
{
#if(_D0_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D0_INPUT_PORT);
#endif
#if(_D1_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D1_INPUT_PORT);
#endif
#if(_D2_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D2_INPUT_PORT);
#endif
#if(_D3_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D3_INPUT_PORT);
#endif
#if(_D4_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D4_INPUT_PORT);
#endif
#if(_D5_HDMI_SUPPORT == _ON)
    UserCommonInterfaceHdmiExternalInfoParser(_D5_INPUT_PORT);
#endif
}

//--------------------------------------------------
// Description  : External EDID Parser
// Input Value  : ucInputport
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceHdmiExternalInfoParser(BYTE ucInputport)
{
    // 0x02: multiEdid; 0x01: only 1 external edid
    BYTE ucflow = 0x00;

    // flow setting
    switch(ucInputport)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:
#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:
#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:
#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:
#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D4_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:
#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)
            ucflow = 0x02;
#elif(_D5_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE)
            ucflow = 0x01;
#endif
            break;
#endif
        default:
            ucflow = 0x00;
            break;
    }

#if(_HDMI_MULTI_EDID_SUPPORT == _ON)
    if(ucflow == 0x02)
    {
        // MultiEdid & Current index is External
        if(UserCommonInterfaceHDMIGetMultiEdidLocated(ucInputport, UserInterfaceGetMultiHdmiEdidIndex(ucInputport)) == _HDMI_EDID_EXTERNAL)
        {
#if(_FREESYNC_SUPPORT == _ON)
            // Force AMD Ver = NA when External Edid
            ScalerSyncSetAmdVsdbVer(ucInputport, _AMD_VER_NONE);
#endif
        }
    }
#endif

    // Only 1 Edid & is External
    if(ucflow == 0x01)
    {
#if(_FREESYNC_SUPPORT == _ON)
        // Force AMD Ver = NA when External Edid
        ScalerSyncSetAmdVsdbVer(ucInputport, _AMD_VER_NONE);
#endif
    }
}

#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Version Scdc Info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTmdsGetVersionScdcInfo(void)
{
    BYTE pucRtkIdstring[8] = {'R', 'T', 'D', ' ', ' ', ' ', ' ', ' '};
    WORD usIdString = (_HDMI_SINK_RTK_ID_STRING_H << 8 | _HDMI_SINK_RTK_ID_STRING_L);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
    StructDrrAmdAupiInfo stDrrHdmiAmdAupiInfo = {0};
    StructDrrAmdAupiInfo stCheck = {0};

    UserInterfaceFreeSyncGetHdmiAupiPanelInfo(&stDrrHdmiAmdAupiInfo);
    CLR_FREESYNC_HDMI_AUPI_INFO();

    // check if stDrrAmdAupiInfo is all zero
    if(memcmp(&stDrrHdmiAmdAupiInfo, &stCheck, sizeof(stDrrHdmiAmdAupiInfo)) != 0)
    {
        g_stDrrHdmiAmdAupiInfo = stDrrHdmiAmdAupiInfo;
        SET_FREESYNC_HDMI_AUPI_INFO();
    }
#endif

    // Get ID String
    for(pData[0] = 0; pData[0] < 4; pData[0]++)
    {
        switch((usIdString >> (pData[0] * 4)) & 0x0F)
        {
            case 0x00:
                pucRtkIdstring[6 - pData[0]] = '0';
                break;

            case 0x01:
                pucRtkIdstring[6 - pData[0]] = '1';
                break;

            case 0x02:
                pucRtkIdstring[6 - pData[0]] = '2';
                break;

            case 0x03:
                pucRtkIdstring[6 - pData[0]] = '3';
                break;

            case 0x04:
                pucRtkIdstring[6 - pData[0]] = '4';
                break;

            case 0x05:
                pucRtkIdstring[6 - pData[0]] = '5';
                break;

            case 0x06:
                pucRtkIdstring[6 - pData[0]] = '6';
                break;

            case 0x07:
                pucRtkIdstring[6 - pData[0]] = '7';
                break;

            case 0x08:
                pucRtkIdstring[6 - pData[0]] = '8';
                break;

            case 0x09:
                pucRtkIdstring[6 - pData[0]] = '9';
                break;

            default:
                break;
        }
    }

    memcpy(&g_stTmdsMacRxScdcInfoSet.pucIdstring[0], pucRtkIdstring, 8);

    // Get Manufacture Oui
    g_stTmdsMacRxScdcInfoSet.ucManufactureOuiH = _HDMI_SINK_MANUFACTURE_OUI_H;
    g_stTmdsMacRxScdcInfoSet.ucManufactureOuiM = _HDMI_SINK_MANUFACTURE_OUI_M;
    g_stTmdsMacRxScdcInfoSet.ucManufactureOuiL = _HDMI_SINK_MANUFACTURE_OUI_L;

    // Get HW/FW Version
    g_stTmdsMacRxScdcInfoSet.ucHdmiHwVersion = ScalerTMDSHdmiGetHwVersion();
    g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMajor = 0x04;
    g_stTmdsMacRxScdcInfoSet.ucHdmiFwVersionMinor = 0x00;
}
#endif
#endif // End of #if(_HDMI_SUPPORT == _ON)

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
    ucSubAddr = ucSubAddr;
    ucLength = ucLength;
    pucReadArray = pucReadArray;

#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP_KEY_BKSV + ucSubAddr, ucLength);
#elif((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHDCPKeyBKsv(ucSubAddr, ucLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHDCPKeyBksvByUser(ucSubAddr, ucLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_EFUSE)
    ScalerSyncGetEfuseHDCPKeyBKsv(ucSubAddr, ucLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP_KEY_TABLE + usSubAddr, usLength);
#elif((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHDCPKey(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHDCPKeyByUser(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_EFUSE)
    ScalerSyncGetEfuseHDCPKey(usSubAddr, usLength, pucReadArray);
#endif
}

#if(_HDCP_2_2_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2Certrx(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_Certrx + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2Certrx(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2CertrxByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2RSADkey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_DKey + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2RSADkey(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2RSADkeyByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2RSARRModN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_RRMODN + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2RSARRModN(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2RSARRModNByUser(usSubAddr, usLength, pucReadArray);
#endif
}

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDCP KpubKm for Verify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2KpubKm(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_KpubKm + usSubAddr, usLength);
#endif
}
#endif

//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2RSAKPriv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_KPriv + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2RSAKPriv(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2RSAKPrivByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2RSANpinv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_NPINV + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2RSANpinv(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2RSANpinvByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetHdcp2LCKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tHDCP2_LCKey + usSubAddr, usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetHdcp2LCKey(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetHdcp2LCKeyByUser(usSubAddr, usLength, pucReadArray);
#endif
}

#if((_DP_HDCP_2_2_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- RRMODN
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetDpTxHdcp2RRMODN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, (tTX_HDCP2_RRMODN + (usSubAddr)), usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHdcp2RRMODN(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetDpTxHdcp2RRMODNByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- DCP_LLC_N
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetDpTxHdcp2DcpLlcN(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, (tTX_HDCP2_DCP_LLC_N + (usSubAddr)), usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHdcp2DcpLlcN(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetDpTxHdcp2DcpLlcNByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- E_Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetDpTxHdcp2EKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, (tTX_HDCP2_EKEY + (usSubAddr)), usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHdcp2EKey(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetDpTxHdcp2EKeyByUser(usSubAddr, usLength, pucReadArray);
#endif
}

//--------------------------------------------------
// Description  : Get HDCP2.2 TX KEY -- NP_INV
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetDpTxHdcp2NPinv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, (tTX_HDCP2_NPINV + (usSubAddr)), usLength);
#elif((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHdcp2NPinv(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetDpTxHdcp2NPinvByUser(usSubAddr, usLength, pucReadArray);
#endif
}
#endif
#endif

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDCP Aksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetTxHDCPKeyAKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
    ucSubAddr = ucSubAddr;
    ucLength = ucLength;
    pucReadArray = pucReadArray;

#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tTX_HDCP_KEY_AKSV + ucSubAddr, ucLength);
#elif((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHDCPKeyAKsv(ucSubAddr, ucLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetTxHDCPKeyAksvByUser(ucSubAddr, ucLength, pucReadArray);
#endif
}
//--------------------------------------------------
// Description  : Get HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceGetTxHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;

#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pucReadArray, tTX_HDCP_KEY_TABLE + usSubAddr, usLength);
#elif((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    UserCommonNVRamGetTxHDCPKey(usSubAddr, usLength, pucReadArray);
#elif(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
    UserInterfaceGetTxHDCPKeyByUser(usSubAddr, usLength, pucReadArray);
#endif
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)

#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
//--------------------------------------------------
// Description  : Restore default HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceNVRamRestoreHDCP(void)
{
    BYTE ucCount = 0;
    BYTE pucBuffer[16] = {0};

#if((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    if((_RX_HDCP_1_4_KEY_FLASH_BANK != _EDID_FLASH_BANK) || (_RX_HDCP_1_4_TABLE_FLASH_PAGE != _EDID_TABLE_FLASH_PAGE))
    {
        UserCommonFlashErasePage(_RX_HDCP_1_4_KEY_FLASH_BANK, _RX_HDCP_1_4_TABLE_FLASH_PAGE);
    }
#endif

    // Dump BKSV into NVRAM
    memcpy(pucBuffer, tHDCP_KEY_BKSV, sizeof(tHDCP_KEY_BKSV));
    UserCommonNVRamRestoreHDCP1P4(0, sizeof(tHDCP_KEY_BKSV), pucBuffer);

    // Dump HDCP Key into NVRAM
    for(ucCount = 0; ucCount < 20; ucCount++)
    {
        memcpy(pucBuffer, tHDCP_KEY_TABLE + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));

        UserCommonNVRamRestoreHDCP1P4(5 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }
#endif // End of #if((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))

#if((_HDCP_2_2_SUPPORT == _ON) && ((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)))
#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    if((_RX_HDCP_2_2_KEY_FLASH_BANK != _EDID_FLASH_BANK) || (_RX_HDCP_2_2_TABLE_FLASH_PAGE != _EDID_TABLE_FLASH_PAGE))
    {
        UserCommonFlashErasePage(_RX_HDCP_2_2_KEY_FLASH_BANK, _RX_HDCP_2_2_TABLE_FLASH_PAGE);
    }
#endif

    // Restore Certrx to NVRAM
    for(ucCount = 0; ucCount < 33; ucCount++)
    {
        if(ucCount < 32)
        {
            memcpy(pucBuffer, tHDCP2_Certrx + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
            UserCommonNVRamRestoreHDCP2(ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
        }
        else
        {
            memcpy(pucBuffer, tHDCP2_Certrx + ucCount * sizeof(pucBuffer), 10);
            UserCommonNVRamRestoreHDCP2(512, 10, pucBuffer);
        }
    }

    // Restore Kpriv to NVRAM
    for(ucCount = 0; ucCount < 20; ucCount++)
    {
        memcpy(pucBuffer, tHDCP2_KPriv + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreHDCP2(522 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore RRMODN to NVRAM
    for(ucCount = 0; ucCount < 8; ucCount++)
    {
        memcpy(pucBuffer, tHDCP2_RRMODN + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreHDCP2(842 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore Npinv to NVRAM
    memcpy(pucBuffer, tHDCP2_NPINV, sizeof(tHDCP2_NPINV));
    UserCommonNVRamRestoreHDCP2(970, sizeof(tHDCP2_NPINV), pucBuffer);

    // Restore RSA D key to NVRAM
    for(ucCount = 0; ucCount < 8; ucCount++)
    {
        memcpy(pucBuffer, tHDCP2_DKey + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreHDCP2(974 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore LC key to NVRAM
    memcpy(pucBuffer, tHDCP2_LCKey, sizeof(tHDCP2_LCKey));
    UserCommonNVRamRestoreHDCP2(1102, sizeof(tHDCP2_LCKey), pucBuffer);

#endif // End of #if((_HDCP_2_2_SUPPORT == _ON) && ((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)))

#if(_DP_TX_SUPPORT == _ON)

#if((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    if(((_TX_HDCP_1_4_KEY_FLASH_BANK != _EDID_FLASH_BANK) || (_TX_HDCP_1_4_TABLE_FLASH_PAGE != _EDID_TABLE_FLASH_PAGE)) &&
       ((_TX_HDCP_1_4_KEY_FLASH_BANK != _RX_HDCP_1_4_KEY_FLASH_BANK) || (_TX_HDCP_1_4_TABLE_FLASH_PAGE != _RX_HDCP_1_4_TABLE_FLASH_PAGE)))
    {
        UserCommonFlashErasePage(_TX_HDCP_1_4_KEY_FLASH_BANK, _TX_HDCP_1_4_TABLE_FLASH_PAGE);
    }
#endif

    // Dump BKSV into NVRam
    memcpy(pucBuffer, tTX_HDCP_KEY_AKSV, sizeof(tTX_HDCP_KEY_AKSV));
    UserCommonNVRamRestoreTxHDCP1P4(0, sizeof(tTX_HDCP_KEY_AKSV), pucBuffer);

    // Dump HDCP Key into NVRam
    for(ucCount = 0; ucCount < 20; ucCount++)
    {
        memcpy(pucBuffer, tTX_HDCP_KEY_TABLE + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreTxHDCP1P4(5 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }
#endif // End of #if((_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))

#if((_HDCP_2_2_SUPPORT == _ON) && ((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)))
#if((_FLASH_WRITE_FUNCTION_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH))
    if(((_TX_HDCP_2_2_KEY_FLASH_BANK != _EDID_FLASH_BANK) || (_TX_HDCP_2_2_TABLE_FLASH_PAGE != _EDID_TABLE_FLASH_PAGE)) &&
       ((_TX_HDCP_2_2_KEY_FLASH_BANK != _RX_HDCP_2_2_KEY_FLASH_BANK) || (_TX_HDCP_2_2_TABLE_FLASH_PAGE != _RX_HDCP_2_2_TABLE_FLASH_PAGE)))
    {
        UserCommonFlashErasePage(_TX_HDCP_2_2_KEY_FLASH_BANK, _TX_HDCP_2_2_TABLE_FLASH_PAGE);
    }
#endif

    // Restore RRMODN to NVRAM (384-Bytes)
    for(ucCount = 0; ucCount < 24; ucCount++)
    {
        memcpy(pucBuffer, tTX_HDCP2_RRMODN + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreTxHDCP2(ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore DCPLLCN to NVRAM (384-Bytes)
    for(ucCount = 0; ucCount < 24; ucCount++)
    {
        memcpy(pucBuffer, tTX_HDCP2_DCP_LLC_N + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreTxHDCP2(384 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore EKEY to NVRAM (128-Bytes)
    for(ucCount = 0; ucCount < 8; ucCount++)
    {
        memcpy(pucBuffer, tTX_HDCP2_EKEY + ucCount * sizeof(pucBuffer), sizeof(pucBuffer));
        UserCommonNVRamRestoreTxHDCP2(772 + ucCount * sizeof(pucBuffer), sizeof(pucBuffer), pucBuffer);
    }

    // Restore Npinv to NVRAM (4-Bytes)
    memcpy(pucBuffer, tTX_HDCP2_NPINV, sizeof(tTX_HDCP2_NPINV));
    UserCommonNVRamRestoreTxHDCP2(768, sizeof(tTX_HDCP2_NPINV), pucBuffer);

#endif // End of #if((_HDCP_2_2_SUPPORT == _ON) && ((_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_FLASH) || (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)))

#endif // End of #if(_DP_TX_SUPPORT == _ON)
}
#endif // End of #if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE UserCommonInterfaceDpRxGetDpcdBitInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit)
{
    return ScalerDpRxGetDpcdBitInfo(ucInputPort, ucDpcdAccessPortH, ucDpcdAccessPortM, ucDpcdAccessPortL, ucDpcdBit);
}

//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE UserCommonInterfaceDpRxGetDpcdInfo(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL)
{
    return ScalerDpRxGetDpcdInfo(ucInputPort, ucDpcdAccessPortH, ucDpcdAccessPortM, ucDpcdAccessPortL);
}

//--------------------------------------------------
// Description  : Set DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpRxSetDpcdBitValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit)
{
    ScalerDpRxSetDpcdBitValue(ucInputPort, ucDpcdAccessPortH, ucDpcdAccessPortM, ucDpcdAccessPortL, ucNotDpcdBit, ucDpcdBit);
}

//--------------------------------------------------
// Description  : Set DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpRxSetDpcdValue(BYTE ucInputPort, BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue)
{
    ScalerDpRxSetDpcdValue(ucInputPort, ucDpcdAccessPortH, ucDpcdAccessPortM, ucDpcdAccessPortL, ucDpcdValue);
}

//--------------------------------------------------
// Description  : Get Dp Audio Capability Initial State
// Input Value  : Input Port
// Output Value : EnumAudioDpDpcdSupport
//--------------------------------------------------
EnumAudioDpDpcdSupport UserCommonAudioDpGetCapabilityInitialState(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

#if(_AUDIO_SUPPORT == _ON)

#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
    return UserInterfaceAudioDpGetCapabilityInitialState(ucInputPort);
#else
    return _AUDIO_DP_DPCD_SUPPORT;
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)

#else
    return _AUDIO_DP_DPCD_NOT_SUPPORT;
#endif // End of #if(_AUDIO_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : Set Dp Aux Diff Mode or single-ended mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpAuxSet(void)
{
#if(_D0_DP_EXIST == _ON)
    ScalerDpRx0AuxSet();
#endif

#if(_D1_DP_EXIST == _ON)
    ScalerDpRx1AuxSet();
#endif
}

//--------------------------------------------------
// Description  : Dp Version Switch
// Input Value  : DP input port, _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort)
{
    DebugMessageSystem("DP Version", enumDpVersion);

    ScalerDpVersionSwitch(ucInputPort, enumDpVersion, enumDpRxMstPort);

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            switch(enumDpVersion)
            {
                case _DP_VERSION_1_0:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_0;
                    break;

                case _DP_VERSION_1_1:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_1;
                    break;

                case _DP_VERSION_1_2:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_2;
                    break;

                case _DP_VERSION_1_4:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_4;
                    break;

                default:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_1;
                    break;
            }

#if(_DP_MST_SUPPORT == _ON)
            switch(UserInterfaceGetDpMSTCapablePort())
            {
                case _DP_MST_RX0_PORT:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;

                    break;

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
                case _DP_MST_AUTO_PORT:

                    if(enumDpVersion >= _DP_VERSION_1_2)
                    {
                        g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;
                    }
                    else
                    {
                        g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;
                    }

                    break;
#endif

                default:
                    g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;

                    break;
            }
#else
            g_stD0DataExchange.unionDataExchangeItem.stDpVersion.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;
#endif

            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_DP_VERSION);

            break;

        default:
        case _D1_INPUT_PORT:
        case _D6_INPUT_PORT:
            break;
    }
#endif
}
//--------------------------------------------------
// Description  : Switch all DP ports Dp Version
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDPSwitchAllPortDpVersion(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    UserCommonInterfaceDpVersionSwitch(_D0_INPUT_PORT, UserInterfaceGetDPVersion(_D0_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    UserCommonInterfaceDpVersionSwitch(_D1_INPUT_PORT, UserInterfaceGetDPVersion(_D1_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    UserCommonInterfaceDpVersionSwitch(_D2_INPUT_PORT, UserInterfaceGetDPVersion(_D2_INPUT_PORT), UserInterfaceGetDpMSTCapablePort());
#endif
}
//--------------------------------------------------
// Description  : Read DP Rx Error Count
// Input Value  : DP Input Port
// Output Value : DP 4 Lane Error Count & Valid Flag
//--------------------------------------------------
StructDpRxErrorCount UserCommonInterfaceDpRxGetErrorCount(BYTE ucInputPort)
{
    return ScalerDpRxGetErrorCount(ucInputPort);
}

//--------------------------------------------------
// Description  : Get MST capable port
// Input Value  : None
// Output Value : EnumDPMSTPort
//--------------------------------------------------
EnumDPMSTPort UserCommonInterfaceGetDpMstCapablePort(void)
{
    EnumDPMSTPort enumMstTargetPort = UserInterfaceGetDpMSTCapablePort();

    if(enumMstTargetPort == _DP_MST_AUTO_PORT)
    {
        enumMstTargetPort = _DP_MST_NO_PORT;

        switch(SysSourceGetInputPort())
        {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_MST_PORT_SUPPORT == _ON))
            case _D0_INPUT_PORT:

                if(UserInterfaceGetDPVersion(_D0_INPUT_PORT) >= _DP_VERSION_1_2)
                {
                    enumMstTargetPort = _DP_MST_RX0_PORT;
                }

                break;
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_MST_PORT_SUPPORT == _ON))
            case _D1_INPUT_PORT:

                if(UserInterfaceGetDPVersion(_D1_INPUT_PORT) >= _DP_VERSION_1_2)
                {
                    enumMstTargetPort = _DP_MST_RX1_PORT;
                }

                break;
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) &&\
    ((_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0) && (_D0_DP_MST_PORT_SUPPORT == _ON)))
            case _D6_INPUT_PORT:

                if(UserInterfaceGetDPVersion(_D6_INPUT_PORT) >= _DP_VERSION_1_2)
                {
                    enumMstTargetPort = _DP_MST_RX6_PORT;
                }

                break;
#endif

            default:

                break;
        }
    }

    if(SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT)
    {
        if(GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())) == _PORT_DP)
        {
            return enumMstTargetPort;
        }
    }
#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
    else
    {
        return enumMstTargetPort;
    }
#endif

    return _DP_MST_NO_PORT;
}

//--------------------------------------------------
// Description  : Get Dp Port Edid Native Timing BW
// Input Value  : enumDpEdidPort --> Dp Edid Port
// Output Value : Bw, Unit: 0.01M
//--------------------------------------------------
WORD UserCommonInterfaceDpGetEdidNativeTimingBw(EnumDpEdidPort enumDpEdidPort)
{
    switch(enumDpEdidPort)
    {
        case _D0_DP_EDID:
        case _D1_DP_EDID:

            return ScalerSyncGetDpRxPortEdidBw(enumDpEdidPort);

        case _DP_TX_EDID:

#if(_DP_TX_SUPPORT == _ON)
            return ScalerDpTxGetDownStreamEdidBw();
#endif

        default:

            break;
    }

    return 0;
}

//--------------------------------------------------
// Description  : DP Tx I2CoverAux Write
// Input Value  : ucSlaveAddress --> SlaveAddress of I2CoverAux Write
//                ucLength --> Length of I2CoverAux Write
//                pWriteArray --> Data of I2CoverAux Write
// Output Value : EnumDpAuxStatus --> Native Aux Write Sucessful
//--------------------------------------------------
EnumDpAuxStatus UserCommonInterfaceDpTxAuxI2COverWrite(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray)
{
    ucSlaveAddress = ucSlaveAddress;
    ucLength = ucLength;
    pucDataArray = pucDataArray;

#if(_DP_TX_SUPPORT == _ON)
    while(ucLength > 16)
    {
        ucLength = ucLength - 16;

        if(ScalerDpTxAuxI2CoverWrite(ucSlaveAddress, 16, pucDataArray, 1) == _FALSE)
        {
            return _DP_AUX_FAIL;
        }
        else
        {
            pucDataArray = pucDataArray + 16;
        }
    }

    if(ScalerDpTxAuxI2CoverWrite(ucSlaveAddress, ucLength, pucDataArray, 0) == _FALSE)
    {
        return _DP_AUX_FAIL;
    }

    return _DP_AUX_PASS;
#else
    return _DP_AUX_FAIL;
#endif
}

//--------------------------------------------------
// Description  : DP Tx I2CoverAux Read
// Input Value  : ucSlaveAddress --> SlaveAddress of I2CoverAux Read
//                ucLength --> Length of I2CoverAux Read
//                pWriteArray --> Data of I2CoverAux Read
// Output Value : EnumDpAuxStatus --> Native Aux Write Sucessful
//--------------------------------------------------
EnumDpAuxStatus UserCommonInterfaceDpTxAuxI2COverRead(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray)
{
    ucSlaveAddress = ucSlaveAddress;
    ucLength = ucLength;
    pucDataArray = pucDataArray;

#if(_DP_TX_SUPPORT == _ON)
    while(ucLength > 16)
    {
        ucLength = ucLength - 16;

        if(ScalerDpTxAuxI2CoverRead(ucSlaveAddress, 16, pucDataArray, 1) == _FALSE)
        {
            return _DP_AUX_FAIL;
        }
        else
        {
            pucDataArray = pucDataArray + 16;
        }
    }

    if(ScalerDpTxAuxI2CoverRead(ucSlaveAddress, ucLength, pucDataArray, 0) == _FALSE)
    {
        return _DP_AUX_FAIL;
    }

    return _DP_AUX_PASS;
#else
    return _DP_AUX_FAIL;
#endif
}

//--------------------------------------------------
// Description  : Get Link Training Pass
// Input Value  : enumInputPort
// Output Value : _TRUE: pass, _FALSE: fail
//--------------------------------------------------
EnumUserDpLTStatus UserCommonInterfaceDpGetLinkTrainingStatus(EnumSourceSearchPort enumInputPort)
{
    return (EnumUserDpLTStatus)ScalerSyncDpGetLinkTrainingPass(enumInputPort);
}

#if(_DP_LONG_HPD_ALLOWED_BY_USER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Dp Long HPD Allowed or Not
// Input Value  : ucInputPort, bAllowed = _TRUE/_FALSE
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpLongHpdSetAllowed(EnumSourceSearchPort enumInputPort, bit bAllowed)
{
    ScalerSyncDpLongHpdSetAllowed(enumInputPort, bAllowed);
}
#endif

//--------------------------------------------------
// Description  : Dp IRQ Assert Proc
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpRxHpdIrqAssert(BYTE ucInputPort)
{
    ScalerDpRxHpdIrqAssert(ucInputPort);
}

#endif // End of #if(_DP_SUPPORT == _ON)
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Tx Get Stream Source
// Input Value  : None
// Output Value : GET_DP_TX_STREAM_SOURCE
//--------------------------------------------------
EnumDPTxInputSource UserCommonInterfaceDpTxGetStreamSource(void)
{
    return ScalerDpTxGetStreamSource();
}
#endif

#if(_PANEL_STYLE == _PANEL_DPTX)
//--------------------------------------------------
// Description  : DP Tx I2CoverAux Write
// Input Value  : ucSlaveAddress --> SlaveAddress of I2CoverAux Write
//                ucLength --> Length of I2CoverAux Write
//                pWriteArray --> Data of I2CoverAux Write
// Output Value : EnumDpAuxStatus --> Native Aux Write Sucessful
//--------------------------------------------------
EnumDpAuxStatus UserCommonInterfaceDisplayDPTxAuxI2COverWrite(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray)
{
    while(ucLength > 16)
    {
        ucLength = ucLength - 16;

        if(ScalerDisplayDPTxAuxI2CoverWrite(enumDisplayDpTxOutputPort, ucSlaveAddress, 16, pucDataArray, 1) == _FALSE)
        {
            return _DP_AUX_FAIL;
        }
        else
        {
            pucDataArray = pucDataArray + 16;
        }
    }

    if(ScalerDisplayDPTxAuxI2CoverWrite(enumDisplayDpTxOutputPort, ucSlaveAddress, ucLength, pucDataArray, 0) == _FALSE)
    {
        return _DP_AUX_FAIL;
    }

    return _DP_AUX_PASS;
}

//--------------------------------------------------
// Description  : DP Tx I2CoverAux Read
// Input Value  : ucSlaveAddress --> SlaveAddress of I2CoverAux Read
//                ucLength --> Length of I2CoverAux Read
//                pWriteArray --> Data of I2CoverAux Read
// Output Value : EnumDpAuxStatus --> Native Aux Write Sucessful
//--------------------------------------------------
EnumDpAuxStatus UserCommonInterfaceDisplayDPTxAuxI2COverRead(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray)
{
    while(ucLength > 16)
    {
        ucLength = ucLength - 16;

        if(ScalerDisplayDPTxAuxI2CoverRead(enumDisplayDpTxOutputPort, ucSlaveAddress, 16, pucDataArray, 1) == _FALSE)
        {
            return _DP_AUX_FAIL;
        }
        else
        {
            pucDataArray = pucDataArray + 16;
        }
    }

    if(ScalerDisplayDPTxAuxI2CoverRead(enumDisplayDpTxOutputPort, ucSlaveAddress, ucLength, pucDataArray, 0) == _FALSE)
    {
        return _DP_AUX_FAIL;
    }

    return _DP_AUX_PASS;
}
#endif

#if(_DP_TX_BLOCK_CONTROL_BEFORE_STREAM_OUTPUT == _ON)
//--------------------------------------------------
// Description  : OSD Clone Mode Switch
// Input Value  : Clone Mode on/off
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceCloneModeSwitch(bit bClone)
{
    DebugMessageSystem("DP Clone Mode Switch", bClone);

    ScalerDpTxCloneModeSwitch(bClone);
}
#endif

//--------------------------------------------------
// Description  : OSD Handler, executed in the main loop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdHandler(void)
{
#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if(ScalerSyncCheckUrgentEvent() == _FALSE)
#endif
    {
#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
        UserCommonDataExchangeHandler();
#endif
        UserOsdHandler();
        SysModeClrModeStateChange();

#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_DP_TYPE_C_HUB_COMMUNICATION_SUPPORT == _ON))
        SysTypeCOsdHubProc();
#endif
    }

#if(_HDMI_CEC_SUPPORT == _ON)
    UserInterfaceCecHighLevelFlow();
#endif

#if(_PANEL_STYLE == _PANEL_VBO)
    ScalerDisplayVboPanelBacklightReTurnOn();
#endif

#if(_FW_UPDATE_PROCESS_SUPPORT == _ON)
    UserCommonFwUpdateHandler();
#endif
}

//--------------------------------------------------
// Description  : User related operation
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceInitial(void)
{
    // Call Uncalled Function for Compile Warning
    UserCommonInterfaceUncallFunction();
    UserInterfaceUncallFunction();

    // Flash write protect
#if(_FLASH_WR_PROTECT == _ON)
    UserCommonFlashWRProtect();
#endif

#if(_DEVICE_LED_DRIVER_TYPE != _DEVICE_LED_DRIVER_NONE)
    ExternalDeviceInterfaceLedDriverInitial();
#endif

    UserInterfaceInitial();

#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && (_DDR3_MULTIPHASE_EXIST == _ON))
    // Update DDR3 phase data from user
    UserInterfaceUpdateDDR3PhaseData();
#endif
}

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Quantization Range at HDR support
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserCommonInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization)
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
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Return Color Format by User or Not
// Input Value  : None
// Output Value : Color Format
//--------------------------------------------------
EnumColorSpace UserCommonInterfaceGetColorFormat(void)
{
    EnumColorSpace enumColorSpace = ScalerColorGetColorSpace();

    if(ScalerColorGetColorSpaceRGB(UserInterfaceGetColorFormat()) ==
       ScalerColorGetColorSpaceRGB(enumColorSpace))
    {
        return enumColorSpace;
    }

    return UserInterfaceGetColorFormat();
}
#endif

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Mst Rx0 Rx1 Capable Port
// Input Value  : _DP_MST_RX0_PORT or _DP_MST_RX1_PORT
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceMstRx0Rx1switch(EnumDPMSTPort enumMstCapablePort)
{
    enumMstCapablePort = enumMstCapablePort;
    DebugMessageMst("MST Rx0 Rx1 Switch to", enumMstCapablePort);

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _OFF)
    ScalerDpRxMstRx0Rx1switch(enumMstCapablePort);
#endif

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
#if(_DP_MST_SUPPORT == _ON)
    switch(UserInterfaceGetDpMSTCapablePort())
    {
        case _DP_MST_RX0_PORT:
            g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;
            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_MST_ON_OFF);

            DebugMessageSystem("OSD -- MST On/Off Switch", g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort);

            break;

        default:
        case _DP_MST_RX1_PORT:
        case _DP_MST_RX6_PORT:
            g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;
            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_MST_ON_OFF);

            DebugMessageSystem("OSD -- MST On/Off Switch", g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort);

            break;

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
        case _DP_MST_AUTO_PORT:

            if(UserInterfaceGetDPVersion(_D0_INPUT_PORT) >= _DP_VERSION_1_2)
            {
                g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;
            }
            else
            {
                g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;
            }

            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_MST_ON_OFF);

            DebugMessageSystem("OSD -- MST On/Off Switch", g_stD0DataExchange.unionDataExchangeItem.stMstOnOff.enumMstPort);

            break;
#endif
    }
#endif
#endif
}

#if(_DP_MST_TX_INTERCEPT_DDCCI_MSG_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Mst Tx Intercept Ddcci Msg Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDpMstTxInterceptDdcciMsgSetting(bit bStatus)
{
    bStatus = bStatus;

    ScalerDpTxMstInterceptDdcciMsgSetting(bStatus);
}
#endif
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TypeC U3 Mode Switch
// Input Value  : ucInputPort --> Inputput
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCU3ModeSwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
    SysTypeCSetCapabilityChangeFlag(ucInputPort, _TYPE_C_PIN_ASSIGNMENT_CAP_CHG);
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
#if(_D0_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
            if(UserInterfaceTypeCGetOsdU3ModeSelection(_D0_INPUT_PORT) == _TYPE_C_U3_ON)
            {
                g_stD0DataExchange.unionDataExchangeItem.stU3Mode.enumTypeCU3OnOff = _DATA_EXCHANGE_U3_ON;
            }
            else
            {
                g_stD0DataExchange.unionDataExchangeItem.stU3Mode.enumTypeCU3OnOff = _DATA_EXCHANGE_U3_OFF;
            }

            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_U3_ON_OFF);

            DebugMessageSystem("OSD -- U3 On/Off Switch", g_stD0DataExchange.unionDataExchangeItem.stU3Mode.enumTypeCU3OnOff);
#endif

            break;

        default:
        case _D1_INPUT_PORT:
        case _D6_INPUT_PORT:
            break;
    }
#endif // #if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
}

//--------------------------------------------------
// Description  : All Port TypeC U3 Mode Capability Switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCU3ModeAllPortCapabilitySwitch(void)
{
#if(_D0_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    UserCommonInterfaceTypeCU3ModeSwitch(_D0_INPUT_PORT);
#endif

#if(_D1_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    UserCommonInterfaceTypeCU3ModeSwitch(_D1_INPUT_PORT);
#endif

#if(_D6_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    UserCommonInterfaceTypeCU3ModeSwitch(_D6_INPUT_PORT);
#endif
}

#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TypeC Pin Assignment E Support Switch
// Input Value  : ucInputPort --> Inputput
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCPinAssignmentESupportSwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
    SysTypeCSetCapabilityChangeFlag(ucInputPort, _TYPE_C_PIN_ASSIGNMENT_CAP_CHG);
#endif // End of #if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
            if(UserInterfaceTypeCGetOsdPinAssignmentESupportSelection(_D0_INPUT_PORT) == _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON)
            {
                g_stD0DataExchange.unionDataExchangeItem.stPinAssignmentESupportOnOff.enumPinAssignmentESupportOnOff = _DATA_EXCHANGE_PIN_ASSIGNMENT_E_SUPPORT_ON;
            }
            else
            {
                g_stD0DataExchange.unionDataExchangeItem.stPinAssignmentESupportOnOff.enumPinAssignmentESupportOnOff = _DATA_EXCHANGE_PIN_ASSIGNMENT_E_SUPPORT_OFF;
            }

            SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_PIN_ASSIGNMENT_E_SUPPORT_ON_OFF);

            DebugMessageSystem("OSD -- Pin Assignment E Support On/Off Switch", g_stD0DataExchange.unionDataExchangeItem.stPinAssignmentESupportOnOff.enumPinAssignmentESupportOnOff);
#endif

            break;

        default:
        case _D1_INPUT_PORT:
        case _D6_INPUT_PORT:
            break;
    }
#endif // End of #if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
}
#endif

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Switch DP EDID According to Alt. Mode Pin Assignment
// Input Value  : ucInputPort --> Inputput, enumPinAssignment Pin Assignment
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCPinAssignSuccessProc(BYTE ucInputPort, EnumTypeCPinCfgType enumPinAssignment)
{
    UserInterfaceTypeCPinAssignSuccessProc(ucInputPort, enumPinAssignment);
}

#if(_TYPE_C_EIZO_CUSTOMIZED_DP_LANE_CNT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : For User to Translate Alt. Mode Pin Assignment to DP Lane Count
// Input Value  : ucInputPort --> Input Port, enumPinAssignment : _TYPE_C_PIN_ASSIGNMENT_C / _TYPE_C_PIN_ASSIGNMENT_D / _TYPE_C_PIN_ASSIGNMENT_E
// Output Value : EnumDpLaneCount -> _DP_LINK_1_LANE / _DP_LINK_2_LANE / _DP_LINK_4_LANE
//--------------------------------------------------
EnumDpLaneCount UserCommonInterfaceTypeCGetAltModeLaneCnt(BYTE ucInputPort, EnumTypeCPinCfgType enumPinAssignment)
{
    // For User to Translate Alt. Mode Pin Assignment to DP Lane Count
    return UserInterfaceTypeCGetAltModeLaneCnt(ucInputPort, enumPinAssignment);
}
#endif

#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE)
//--------------------------------------------------
// Description  : TypeC Lenovo Alt Mode Check Lenovo Device Type Valid
// Input Value  : ucInputPort --> Input Port
//                enumLenovoDeviceType --> Lenovo Device Type
// Output Value : Lenovo Device Type Check Result (_TYPE_C_LENOVO_DEVICE_TYPE_INVALID / _TYPE_C_LENOVO_DEVICE_TYPE_VALID)
//--------------------------------------------------
EnumTypeCLenovoCheckDeviceTypeResult UserCommonInterfaceTypeCCheckLenovoDeviceTypeValid(BYTE ucInputPort, EnumTypeCLenovoDeviceType enumLenovoDeviceType)
{
    return UserInterfaceTypeCCheckLenovoDeviceTypeValid(ucInputPort, enumLenovoDeviceType);
}

//--------------------------------------------------
// Description  : TypeC Lenovo Alt Mode Get Docking Event
// Input Value  : ucInputPort --> Input Port
//                stLenovoDockEvent --> Lenovo Docking Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCGetLenovoDockingEvent(BYTE ucInputPort, StructTypeCLenovoDockEvent *pstLenovoDockEvent)
{
    StructTypeCLenovoDockEvent stLenovoDockEvent = {_TYPE_C_LENOVO_DOCK_POWER_SWITCH_NONE, _FALSE, _FALSE, 0x00};

    UserInterfaceTypeCGetLenovoDockingEvent(ucInputPort, &stLenovoDockEvent);

    *pstLenovoDockEvent = stLenovoDockEvent;
}

//--------------------------------------------------
// Description  : TypeC Lenovo Alt Mode System Event or System Acknowledge Handler Process
// Input Value  : ucInputPort --> Input Port
//                stLenovoSysEvent --> Lenovo System Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCLenovoAltModeHandler(BYTE ucInputPort, StructTypeCLenovoSysEvent stLenovoSysEvent)
{
    UserInterfaceTypeCLenovoAltModeHandler(ucInputPort, stLenovoSysEvent);
}
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_ACER_ALT_MODE)
//--------------------------------------------------
// Description  : TypeC Acer Alt Mode Get User Event
// Input Value  : ucInputPort --> Input Port
//                stAcerUserEvent --> Acer User Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCGetAcerUserEvent(BYTE ucInputPort, StructTypeCAcerUserEvent *pstAcerUserEvent)
{
    StructTypeCAcerUserEvent stAcerUserEvent = {_TYPE_C_ACER_USER_EVENT_NONE, {0x00}, 0x00};

    UserInterfaceTypeCGetAcerUserEvent(ucInputPort, &stAcerUserEvent);

    *pstAcerUserEvent = stAcerUserEvent;
}

//--------------------------------------------------
// Description  : TypeC Acer Alt Mode System Event Process
// Input Value  : ucInputPort --> Input Port
//                stAcerSysEvent --> Acer System Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCAcerAltModeHandler(BYTE ucInputPort, StructTypeCAcerSysEvent stAcerSysEvent)
{
    UserInterfaceTypeCAcerAltModeHandler(ucInputPort, stAcerSysEvent);
}
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_HP_ALT_MODE)
//--------------------------------------------------
// Description  : TypeC Hp Alt Mode Get User Event
// Input Value  : ucInputPort --> Input Port
//                stHpUserEvent --> Hp User Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCGetHpUserEvent(BYTE ucInputPort, StructTypeCHpUserEvent *pstHpUserEvent)
{
    StructTypeCHpUserEvent stHpUserEvent = {_TYPE_C_HP_USER_EVENT_NONE, {0x00}, 0x00};

    UserInterfaceTypeCGetHpUserEvent(ucInputPort, &stHpUserEvent);

    *pstHpUserEvent = stHpUserEvent;
}

//--------------------------------------------------
// Description  : TypeC Hp Alt Mode System Event Process
// Input Value  : ucInputPort --> Input Port
//                stHpSysEvent --> Hp System Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCHpAltModeHandler(BYTE ucInputPort, StructTypeCHpSysEvent stHpSysEvent)
{
    UserInterfaceTypeCHpAltModeHandler(ucInputPort, stHpSysEvent);
}
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE)
//--------------------------------------------------
// Description  : TypeC Get Dell Alt Mode Initial Complete Status
// Input Value  : ucInputPort
// Output Value : Dell Alt Mode Initial Complete (_TYPE_C_DELL_INIT_COMPLETE / _TYPE_C_DELL_INIT_NOT_COMPLETE)
//--------------------------------------------------
EnumTypeCDellInitCompleteStatus UserCommonInterfaceTypeCGetDellAltModeInitComplete(BYTE ucInputPort)
{
    return UserInterfaceTypeCGetDellAltModeInitComplete(ucInputPort);
}

//--------------------------------------------------
// Description  : TypeC Dell Alt Mode System Event Process
// Input Value  : ucInputPort
//                stDellSysEvent --> Dell System Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCDellAltModeHandler(BYTE ucInputPort, StructTypeCDellSysEvent stDellSysEvent)
{
    UserInterfaceTypeCDellAltModeHandler(ucInputPort, stDellSysEvent);
}

//--------------------------------------------------
// Description  : TypeC Dell Alt Mode Get User Event
// Input Value  : ucInputPort
//                stDellUserEvent --> Dell User Event
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCGetDellUserEvent(BYTE ucInputPort, StructTypeCDellUserEvent *pstDellUserEvent)
{
    StructTypeCDellUserEvent stDellUserEvent = {_TYPE_C_DELL_USER_EVENT_NONE, {0x00}, 0x00};

    UserInterfaceTypeCGetDellUserEvent(ucInputPort, &stDellUserEvent);

    *pstDellUserEvent = stDellUserEvent;
}
#endif
#endif  // End of #if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)

#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
//--------------------------------------------------
// Description  : Get TypeC PDO Info Defined By User
// Input Value  : ucInputPort --> Inputput
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTypeCGetProtectInfo(BYTE ucInputPort, BYTE ucPdoIndex, StructTypeCUserProtectInfo *pstTypeCUserProtectInfo)
{
    StructTypeCUserProtectInfo stTypeCUserProtectInfo = {100, 0, 0, 0, 0};

    // Get User Setting By Different PDO
    UserInterfaceTypeCGetProtectInfo(ucInputPort, ucPdoIndex, &stTypeCUserProtectInfo);

    // OCP ration should not less than 100%
    stTypeCUserProtectInfo.ucOcpCurRatio = ((stTypeCUserProtectInfo.ucOcpCurRatio < 100) ? 100 : stTypeCUserProtectInfo.ucOcpCurRatio);

    // Clip Portect Debounce to 0 ~ 5
    stTypeCUserProtectInfo.ucOvpDebounce = ((stTypeCUserProtectInfo.ucOvpDebounce > 5) ? 5 : stTypeCUserProtectInfo.ucOvpDebounce);
    stTypeCUserProtectInfo.ucUvpDebounce = ((stTypeCUserProtectInfo.ucUvpDebounce > 5) ? 5 : stTypeCUserProtectInfo.ucUvpDebounce);
    stTypeCUserProtectInfo.ucOcpDebounce = ((stTypeCUserProtectInfo.ucOcpDebounce > 5) ? 5 : stTypeCUserProtectInfo.ucOcpDebounce);

    stTypeCUserProtectInfo.enumPeakCurrentProtect = _TYPE_C_PEAK_CURRENT_PROTECT_ENABLE;

    *pstTypeCUserProtectInfo = stTypeCUserProtectInfo;
}
#endif // End of #if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
#endif // End of #if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)

//--------------------------------------------------
// Description  : DDC-CI Switch
// Input Value  : bOn --> _ON / _OFF
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDdcciSwitch(EnumDDCCIDebugMode enumMode, BYTE ucInputPort)
{
#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)

#if((_FW_UPDATE_PROCESS_SUPPORT == _ON) && (_FW_UPDATE_DDCCI_SEL == _FW_UPDATE_SEL_DDCCI0))
    if((ScalerFwUpdateGetState() == _FALSE) && (ScalerDebugGetDdcciSwitchState() == _FALSE))
#else
    if(ScalerDebugGetDdcciSwitchState() == _FALSE)
#endif
    {
        ScalerMcuDdcciSwitchPort(enumMode, ucInputPort);
    }
#else
    ScalerMcuDdcciSwitchPort(enumMode, ucInputPort);
#endif

#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    g_stD0DataExchange.unionDataExchangeItem.stDdcciMode.b1DdcciStatus = (enumMode == _DDCCI_MODE ? _ON : _OFF);
    SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_DDC_CI_MODE);
    DebugMessageSystem("OSD -- DDC-CI Switch", g_stD0DataExchange.unionDataExchangeItem.stDdcciMode.b1DdcciStatus);
#endif
}

#if(_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
//--------------------------------------------------
// Description  : All Data Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDataExchangeAllDataReset(void)
{
#if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)
    g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDdcciStatus.b1DdcciStatus = (UserInterfaceGetDdcciMode() == _DDCCI_MODE ? _ON : _OFF);
    g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDcoffHpdMode.b1DPHotPlugDCOffHigh = UserCommonNVRamGetSystemData(_DP_HOT_PLUG_DC_OFF_HIGH);
    g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stAuxDiffMode.b1DPAuxDiffMode = UserCommonNVRamGetSystemData(_DP_AUX_DIFF_MODE);
    g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stAuxAdjr.b4DPAuxAdjrSetting = UserCommonNVRamGetSystemData(_DP_AUX_ADJR_SETTING);
    g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stIrqTime.ucDpIrqTime_10us = UserCommonNVRamGetSystemData(_DP_IRQ_TIME);

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
    if(UserInterfaceTypeCGetOsdU3ModeSelection(_D0_INPUT_PORT) == _TYPE_C_U3_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stU3Mode.enumTypeCU3OnOff = _DATA_EXCHANGE_U3_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stU3Mode.enumTypeCU3OnOff = _DATA_EXCHANGE_U3_OFF;
    }
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(UserInterfaceGetFreeSyncEnable(_D0_INPUT_PORT) == _FREESYNC_SUPPORT_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpFreeSync.enumFreeSyncOnOff = _DATA_EXCHANGE_DP_FREESYNC_SUPPORT_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpFreeSync.enumFreeSyncOnOff = _DATA_EXCHANGE_DP_FREESYNC_SUPPORT_OFF;
    }
#endif

#if(_DP_ADAPTIVESYNC_SUPPORT == _ON)
    if(UserInterfaceGetDpAdaptiveSyncEnable(_D0_INPUT_PORT) == _DP_ADAPTIVESYNC_SUPPORT_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpAdaptiveSync.enumDpAdaptiveSyncOnOff = _DATA_EXCHANGE_DP_ADAPTIVESYNC_SUPPORT_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpAdaptiveSync.enumDpAdaptiveSyncOnOff = _DATA_EXCHANGE_DP_ADAPTIVESYNC_SUPPORT_OFF;
    }
#endif

    switch(UserInterfaceGetDPVersion(_D0_INPUT_PORT))
    {
        case _DP_VERSION_1_0:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_0;
            break;

        case _DP_VERSION_1_1:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_1;
            break;

        case _DP_VERSION_1_2:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_2;
            break;

        case _DP_VERSION_1_4:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_4;
            break;

        default:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stDpVersion.enumVersion = _DATA_EXCHANGE_DP_VERSION_1_1;
            break;
    }

#if(_DP_MST_SUPPORT == _ON)
    switch(UserInterfaceGetDpMSTCapablePort())
    {
        case _DP_MST_RX0_PORT:

            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;

            break;

        default:
        case _DP_MST_RX1_PORT:
        case _DP_MST_RX6_PORT:
            g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;

            break;

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
        case _DP_MST_AUTO_PORT:

            if(UserInterfaceGetDPVersion(_D0_INPUT_PORT) >= _DP_VERSION_1_2)
            {
                g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_RX0_PORT;
            }
            else
            {
                g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stMstOnOff.enumMstPort = _DATA_EXCHANGE_DP_MST_NO_PORT;
            }

            break;
#endif
    }
#endif

#if(_DP_TYPE_C_CONNECTOR_SUPPORT == _ON)
#if(_TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_SWITCH_SUPPORT == _ON)
    if(UserInterfaceTypeCGetOsdPinAssignmentESupportSelection(_D0_INPUT_PORT) == _TYPE_C_PIN_ASSIGNMENT_E_SUPPORT_ON)
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stPinAssignmentESupportOnOff.enumPinAssignmentESupportOnOff = _DATA_EXCHANGE_PIN_ASSIGNMENT_E_SUPPORT_ON;
    }
    else
    {
        g_stD0DataExchange.unionDataExchangeItem.stOsdReset.stPinAssignmentESupportOnOff.enumPinAssignmentESupportOnOff = _DATA_EXCHANGE_PIN_ASSIGNMENT_E_SUPPORT_OFF;
    }
#endif
#endif

    SET_DATA_EXCHANGE_EVENT_MESSAGE(_DATA_EXCHAGNE_CMD_ALL_DATA_RESET);

#endif // End of #if(_D0_TWO_CHIP_DATA_EXCHANGE_MODE != _DATA_EXCHANGE_MODE_NONE)

    DebugMessageSystem("OSD -- Reset", 1);
}
#endif

#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Motion Blur Reduction Backlight Ctrl
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceMbrStrobeBacklightCtrl(bit bLightCtrl)
{
    EnumMbrBacklightMode enumBacklightMode = _BACKLIGHT_MODE_CONSTANT;
    bit bTurnOffBacklight = _FALSE;
#if((_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON) || (_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
    EnumMbrBacklightMode enumBacklightMode_Prev = GET_MBR_BACKLIGHT_MODE();
    BYTE ucBacklightDuty = UserInterfaceMbrGetBacklightDuty();
    BYTE ucBacklightPos = UserInterfaceMbrGetBacklightPos();
#endif

    DebugMessageScaler("MBR: Backlight Control Start", 0);

    // ********************************************
    // 1. Check if backlight needs to be turn off first
    // ********************************************
    if((GET_PANELPOWERSTATUS() != _PANEL_BACKLIGHT_OFF) && (GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE))
    {
        if(bLightCtrl == _LIGHT_CONTROL_OFF)
        {
            bTurnOffBacklight = _TRUE;
        }
        else
        {
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
            if((GET_MBR_BACKLIGHT_MODE() == _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR) && (ScalerMbrCheckAdvMbrSequenceCtrl() == _TRUE))
            {
                bTurnOffBacklight = _TRUE; // turn off TCON(backlight) before adjust setting
            }
            else
#endif
            {
                bTurnOffBacklight = (_MOTION_BLUR_REDUCTION_MODE_SWITCH_NO_MUTE_SUPPORT == _OFF);
            }
        }
    }

    DebugMessageScaler("MBR: bTurnOffBacklight", bTurnOffBacklight);

    // ********************************************
    // 2. Turn off backlight
    // ********************************************
    if(bTurnOffBacklight == _TRUE)
    {
        UserCommonInterfaceMbrStrobeBacklightEnableSeq(_LIGHT_CONTROL_OFF);
    }

    // ********************************************
    // 3. Adjust PDIM (TCON) Setting
    // ********************************************

    // Check if current status allows to apply user(OSD) selected backlight mode
    // if not, remain constant backlight
    if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) || (SysModeGetModeState() == _MODE_STATUS_DISPLAY_SETTING))
    {
        enumBacklightMode = UserCommonInterfaceMbrGetBacklightMode();
    }
    SET_MBR_BACKLIGHT_MODE(enumBacklightMode);

    DebugMessageScaler("MBR: DVTotal", GET_MBR_DVTOTAL());


    // Clear TCON Setting in case different mode conflict
#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    if((enumBacklightMode_Prev != GET_MBR_BACKLIGHT_MODE()) && (enumBacklightMode_Prev == _BACKLIGHT_MODE_STROBE_DRR_MBR))
    {
        ScalerMbrDrrClearSetting(_PCB_MBR_TCON_PIN);
    }
#endif
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    if((enumBacklightMode_Prev != GET_MBR_BACKLIGHT_MODE()) && (enumBacklightMode_Prev == _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR))
    {
        ScalerMbrRtkAdvMbrClearUnusedSetting(_PCB_MBR_TCON_PIN);
    }
#endif

    switch(GET_MBR_BACKLIGHT_MODE())
    {
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
        case _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR:
            ScalerMbrRtkAdvMbrCtrl(_PCB_MBR_TCON_PIN, ucBacklightDuty, ucBacklightPos, bLightCtrl);
            break;
#endif
#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
        case _BACKLIGHT_MODE_STROBE_DRR_MBR:
            ScalerMbrDrrCtrl(_PCB_MBR_TCON_PIN, ucBacklightDuty, ucBacklightPos, bLightCtrl);
            ScalerMbrSetIntEnable(_IRQ_DVS, (bLightCtrl == _LIGHT_CONTROL_ON));
            break;
#endif
        case _BACKLIGHT_MODE_STROBE_USER_CUSTOMIZE_MBR:
        case _BACKLIGHT_MODE_CONSTANT:
        default:
            UserInterfaceMbrBacklightAdjust(GET_MBR_BACKLIGHT_MODE(), bLightCtrl, GET_MBR_DVTOTAL());
            break;
    }
    // ********************************************
    // 4. Turn on backlight
    // ********************************************
    if(bLightCtrl == _LIGHT_CONTROL_ON)
    {
        UserCommonInterfaceMbrStrobeBacklightEnableSeq(_LIGHT_CONTROL_ON);
    }
}

//--------------------------------------------------
// Description  : Turn on/off strobe backlight sequence control
// Input Value  : Light Control ON/OFF
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceMbrStrobeBacklightEnableSeq(bit bLightCtrl)
{
    BYTE ucIndex = 0;
    WORD usDelay = 0;
    EnumMbrBacklightSeqEvent penumAction[] = {_BACKLIGHT_SEQ_PDIM, _BACKLIGHT_SEQ_DELAY, _BACKLIGHT_SEQ_ADIM};
    EnumMbrPDimCtrl enumPDimCtrl = _BACKLIGHT_PDIM_CTRL_BY_TCON;

    usDelay = UserInterfaceMbrGetBacklightSequenceDelay(bLightCtrl);
    enumPDimCtrl = UserInterfaceMbrGetPdimControl(GET_MBR_BACKLIGHT_MODE(), bLightCtrl);

#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    if(GET_MBR_BACKLIGHT_MODE() == _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR)
    {
        enumPDimCtrl = _BACKLIGHT_PDIM_CTRL_BY_TCON;
    }
#endif

    if(UserInterfaceMbrGetBacklightSequence(bLightCtrl) == _BACKLIGHT_SEQ_ADIM_PDIM)
    {
        penumAction[0] = _BACKLIGHT_SEQ_ADIM;
        penumAction[2] = _BACKLIGHT_SEQ_PDIM;
    }

    for(ucIndex = 0; ucIndex < sizeof(penumAction) / sizeof(EnumMbrBacklightSeqEvent); ++ucIndex)
    {
        switch(penumAction[ucIndex])
        {
            case _BACKLIGHT_SEQ_PDIM:
                if(bLightCtrl == _LIGHT_CONTROL_OFF)
                {
                    if(enumPDimCtrl == _BACKLIGHT_PDIM_CTRL_BY_TCON)
                    {
                        ScalerTconEnable(_OFF);
                        ScalerTimerWaitForEvent(_EVENT_DVS);
                    }
                    UserInterfaceMbrPdimAdjust(GET_MBR_BACKLIGHT_MODE(), bLightCtrl);
                }
                else
                {
                    UserInterfaceMbrPdimAdjust(GET_MBR_BACKLIGHT_MODE(), bLightCtrl);
                    // TCON Global Enable Control
                    if(enumPDimCtrl == _BACKLIGHT_PDIM_CTRL_BY_TCON)
                    {
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
                        if(ScalerMbrCheckAdvMbrSequenceCtrl() == _TRUE)
                        {
                            DebugMessageScaler("MBR: Sequence Ctrl Enable", 1);
                            ScalerMbrRtkAdvMbrSequenceCtrlEnable(bLightCtrl == _LIGHT_CONTROL_ON);
                        }
                        else
#endif
                        {
                            ScalerTconEnable(_ON);
                            ScalerTimerWaitForEvent(_EVENT_DVS);
                        }
                    }
                }
                DebugMessageScaler("MBR: Adjust PDIM", bLightCtrl);
                break;

            case _BACKLIGHT_SEQ_ADIM:
                UserInterfaceMbrAdimAdjust(GET_MBR_BACKLIGHT_MODE(), bLightCtrl);
                DebugMessageScaler("MBR: Adjust ADIM", bLightCtrl);
                break;

            case _BACKLIGHT_SEQ_DELAY:
                ScalerTimerDelayXms(usDelay);
                break;
            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Get user backlight mode & judge by kernel
// Input Value  : None
// Output Value : current backlight mode
//--------------------------------------------------
EnumMbrBacklightMode UserCommonInterfaceMbrGetBacklightMode(void)
{
    EnumMbrBacklightMode enumBacklightMode = _BACKLIGHT_MODE_CONSTANT;

#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    SET_MBR_DRR_HW_SUPPORT(UserCommonInterfaceMbrDrrCheckHW());
#endif
    // Get backlight mode from user
    enumBacklightMode = UserInterfaceMbrGetBacklightMode();
    DebugMessageScaler("MBR: User Backlight Mode", enumBacklightMode);

    // Kernel check capability again
    enumBacklightMode = ScalerMbrCheckBacklightMode(enumBacklightMode);
    DebugMessageScaler("MBR: Kernel Adjusted Backlight Mode", enumBacklightMode);

    return enumBacklightMode;
}

//--------------------------------------------------
// Description  : Return current backlight mode
// Input Value  : None
// Output Value : current backlight mode
//--------------------------------------------------
EnumMbrBacklightMode UserCommonInterfaceMbrGetCurrentBacklightMode(void)
{
    return GET_MBR_BACKLIGHT_MODE();
}


#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : In active mode, decide whether to change backlight mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceMbrDrrHandler(void)
{
    // if transition using IRQ is not finished, no further changes needed
    if(GET_MBR_DRR_EVENT_NEXT() != _MBR_DRR_EVENT_NONE)
    {
        return;
    }

    if((GET_MBR_BACKLIGHT_MODE() == _BACKLIGHT_MODE_STROBE_DRR_MBR) && (GET_MBR_DRR_BACKLIGHT_MODE() != _MBR_DRR_MODE_OFF))
    {
        // Judge Framerate
        if(GET_MBR_DRR_BACKLIGHT_MODE() == _MBR_DRR_MODE_STROBE)
        {
            if(GET_MBR_DRR_VFREQ_AVG() < _DRR_MOTION_BLUR_REDUCTION_FLICKER_IVF_LO)
            {
                SET_MBR_DRR_BACKLIGHT_MODE(_MBR_DRR_MODE_STROBE_TO_CONSTANT);
                SET_MBR_DRR_STEP_CHG_CNT(1);
                DebugMessageScaler("MBR: Strobe to Constant", GET_MBR_DRR_VFREQ_AVG());
            }
            else
            {
                ScalerMbrSetIntEnable(_IRQ_DEN_STOP, _DISABLE);
            }
        }
        else if(GET_MBR_DRR_BACKLIGHT_MODE() == _MBR_DRR_MODE_CONSTANT)
        {
            if((GET_MBR_DRR_VFREQ_AVG() >= _DRR_MOTION_BLUR_REDUCTION_FLICKER_IVF_HI) && (GET_MBR_DRR_SAFE_CNT() > _MBR_DRR_SWITCH_FRAME_COUNT))
            {
                SET_MBR_DRR_BACKLIGHT_MODE(_MBR_DRR_MODE_CONSTANT_TO_STROBE);
                SET_MBR_DRR_STEP_CHG_CNT(1);
                DebugMessageScaler("MBR: Constant to Strobe", GET_MBR_DRR_VFREQ_AVG());
            }
            else
            {
                ScalerMbrSetIntEnable(_IRQ_DEN_STOP, _DISABLE);
            }
        }

        // Check Transition
        if((GET_MBR_DRR_BACKLIGHT_MODE() == _MBR_DRR_MODE_STROBE_TO_CONSTANT) || (GET_MBR_DRR_BACKLIGHT_MODE() == _MBR_DRR_MODE_CONSTANT_TO_STROBE))
        {
            WORD usStrobePeriod = 0;
            WORD usStrobePeriod_prev = 0;
            if(GET_MBR_DRR_BACKLIGHT_MODE() == _MBR_DRR_MODE_STROBE_TO_CONSTANT)
            {
                usStrobePeriod = (GET_MBR_DVTOTAL() + 1) * (_MBR_DRR_TRANSITION_FRAME_CNT_LO - GET_MBR_DRR_STEP_CHG_CNT()) / _MBR_DRR_TRANSITION_FRAME_CNT_LO;
                usStrobePeriod_prev = (GET_MBR_DVTOTAL() + 1) * (_MBR_DRR_TRANSITION_FRAME_CNT_LO - GET_MBR_DRR_STEP_CHG_CNT() + 1) / _MBR_DRR_TRANSITION_FRAME_CNT_LO;
            }
            else
            {
                usStrobePeriod = (GET_MBR_DVTOTAL() + 1) * GET_MBR_DRR_STEP_CHG_CNT() / _MBR_DRR_TRANSITION_FRAME_CNT_HI;
                usStrobePeriod_prev = (GET_MBR_DVTOTAL() + 1) * (GET_MBR_DRR_STEP_CHG_CNT() - 1) / _MBR_DRR_TRANSITION_FRAME_CNT_HI;
            }
            DebugMessageScaler("MBR: Transition", GET_MBR_DRR_BACKLIGHT_MODE());
            DebugMessageScaler("MBR: Step Change Count", GET_MBR_DRR_STEP_CHG_CNT());
            ScalerMbrDrrStepChange(_PCB_MBR_TCON_PIN, usStrobePeriod, usStrobePeriod_prev, UserInterfaceMbrGetBacklightDuty(), UserInterfaceMbrGetBacklightPos());
        }
    }
}

//--------------------------------------------------
// Description  : Check TCON Toggle Time for Division of Frequency is Available
// Input Value  : None
// Output Value : whether HW is supported at current timing
//--------------------------------------------------
bit UserCommonInterfaceMbrDrrCheckHW(void)
{
    WORD usHFreq = 0;
    BYTE ucToggleTimeTotal = 0;

    usHFreq = ScalerMbrGetDHFreq();
    while(usHFreq > _PCB_MBR_DRIVER_IC_MAX_FREQ)
    {
        ucToggleTimeTotal++;
        usHFreq /= 2;
    }

    DebugMessageScaler("MBR: ucToggleTimeTotal", ucToggleTimeTotal);

    if((_TCON2 + ucToggleTimeTotal + 2) <= _PCB_MBR_TCON_PIN)
    {
        SET_MBR_DRR_TCON_TOGGLE_TIME(ucToggleTimeTotal);
        return _TRUE;
    }
    else
    {
        SET_MBR_DRR_TCON_TOGGLE_TIME(0);
        DebugMessageScaler("MBR: Not Enough TCON for Toggle", 0);
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Return DRR MBR HW Support Status
// Input Value  : None
// Output Value : whether HW is supported at current timing
//--------------------------------------------------
bit UserCommonInterfaceMbrDrrGetHWSupport(void)
{
    return GET_MBR_DRR_HW_SUPPORT();
}
#endif

#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Motion Blur Reduction
//                Function According to User Selection
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustRtkAdvMbr(void)
{
    // Reset RTK ADV MBR mode
    ScalerMbrClearRtkAdvMbrMode();

    // Get User/OSD MBR enable and set to MBR global variable
    ScalerMbrSetRtkAdvMbrUserStatus(UserInterfaceGetRtkAdvMbrSetting());
}

#endif // end of #if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)

#if((_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON) || (_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Adjust DRR MBR/RTK Adv Mbr Parameters
// Input Value  : ucBacklightDuty - User OSD Backlight Duty Setting
//                ucBacklightPos - User OSD Backlight Position Setting
//                bLightCtrl - Backlight ON/OFF
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceMbrAdvAdjust(BYTE ucBacklightDuty, BYTE ucBacklightPos, bit bLightCtrl)
{
#if(_DRR_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    if(GET_MBR_BACKLIGHT_MODE() == _BACKLIGHT_MODE_STROBE_DRR_MBR)
    {
        ScalerMbrDrrAdjust(_PCB_MBR_TCON_PIN, ucBacklightDuty, ucBacklightPos, bLightCtrl);
    }
#endif
#if(_RTK_ADVANCED_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
    if(GET_MBR_BACKLIGHT_MODE() == _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR)
    {
        ScalerMbrRtkAdvMbrCtrl(_PCB_MBR_TCON_PIN, ucBacklightDuty, ucBacklightPos, bLightCtrl);
    }
#endif
}
#endif
#endif // end of #if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)

#if(_DRR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : FreeSync Get IVFmax
// Input Value  : enumInputPort
// Output Value : _TABLE_SEARCHING_WITH_IVF_MAX: Get IVF, unit: 0.1Hz
//--------------------------------------------------
EnumGetIVFFromTableSearch UserCommonInterfaceFreeSyncGetIVFmax(WORD *pusVfreqMax, EnumSourceSearchPort enumInputPort)
{
    WORD usVfreqMax = 0;

    switch(GET_PORT_TYPE(SysSourceGetInputPortType(enumInputPort)))
    {
#if(_DP_FREESYNC_SUPPORT == _ON)
        case _PORT_DP:

            if(UserInterfaceDisplayDpFreeSyncGetIVFmaxFromLut(&usVfreqMax) == _DP_FREESYNC_WITH_IVF_MAX)
            {
                *pusVfreqMax = usVfreqMax;
                return _TABLE_SEARCHING_WITH_IVF_MAX;
            }
            break;
#endif

        case _PORT_HDMI:
        case _PORT_DVI:

#if(_HDMI21_VRR_SUPPORT == _ON)
            if(ScalerDrrGetType() == _DRR_HDMI21_VRR_TYPE)
            {
                if(UserInterfaceDisplayHdmiVrrGetIVFmaxFromLut(&usVfreqMax) == _HDMI21_VRR_WITH_IVF_MAX)
                {
                    *pusVfreqMax = usVfreqMax;
                    return _TABLE_SEARCHING_WITH_IVF_MAX;
                }
            }
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(UserInterfaceDisplayHdmiFreeSyncGetIVFmaxFromLut(&usVfreqMax) == _HDMI_FREESYNC_WITH_IVF_MAX)
            {
                *pusVfreqMax = usVfreqMax;
                return _TABLE_SEARCHING_WITH_IVF_MAX;
            }
#endif
            break;

        default:
            break;
    }

    return _TABLE_SEARCHING_WITHOUT_IVF_MAX;
}
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
//--------------------------------------------------
// Description  : Force Using D domain DB
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceForceUsingDDomainDB(void)
{
    if(ScalerGlobalGetDBStatus() == _ENABLE)
    {
        // IMD Double Buffer Disalbe
        ScalerGlobalDoubleBufferEnable(_DISABLE);

#if(_LOCAL_DIMMING_SUPPORT == _ON)
        SET_D_DOMAIN_DB_STATUS(ScalerGlobalGetDDomainDBStatus());
#endif

        // D Domain Double Buffer Enable
        ScalerGlobalForceDDomainDBEnable(_ENABLE);

        SET_FORCE_D_DOMAIN_DB(_TRUE);
    }
}
#endif
#endif

//--------------------------------------------------
// Description  : UserCommon timer event process
// Input Value  : Event ID
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID)
{
    UserInterfaceTimerEventProc(enumEventID);

    switch(enumEventID)
    {
        case _USER_TIMER_EVENT_PANEL_POWER_OFF:
            SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);

#if(_PANEL_POW_SEQ_T6_TIMER_EVENT_MODE == _ON)
            if((GET_PANELPOWERACTION() == _PANEL_ON) ||
               (GET_PANELPOWERACTION() == _BACKLIGHT_ON))
            {
                UserCommonInterfacePanelPowerAction(GET_PANELPOWERACTION());
            }
#endif
            break;

        default:
            break;
    }
}

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Update User Define Audio Sampling Freq
// Input Value  : None
// Output Value : EnumAudioSamplingFreqType
//--------------------------------------------------
EnumAudioSamplingFreqType UserCommonInterfaceAudioUpdateUserSamplingFreq(void)
{
    EnumAudioSamplingFreqType enumAudioFreq = UserInterfaceAudioGetUserSamplingFreq();

    if(enumAudioFreq == _AUDIO_FREQ_NO_AUDIO)
    {
        enumAudioFreq = _AUDIO_FREQ_48K;
    }

    return enumAudioFreq;
}

//--------------------------------------------------
// Description  : User Common Ready to play audio
// Input Value  : None
// Output Value : _TRUE => Free to Play
//--------------------------------------------------
bit UserCommonInterfaceGetAudioReadyToPlayStatus(void)
{
    if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
    {
        bit bAudioStatus = _TRUE;

        if(UserInterfaceGetAudioSource() == _DIGITAL_AUDIO)
        {
            // Sampling Frequency Check
            if(ScalerAudioSamplingFreqChange() == _TRUE)
            {
                DebugMessageAudio("Audio Ready False: Sampling Frequency Change", 0);

                bAudioStatus = _FALSE;
            }

#if(_DP_SUPPORT == _ON)
            // DP Audio Capability Status Check
            if((GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())) == _PORT_DP) &&
               (ScalerAudioDpGetCapabilityState(ScalerAudioGetDigitalAudioPortMapping()) == _AUDIO_DP_DPCD_NOT_SUPPORT))
            {
                DebugMessageAudio("Audio Ready False : DP Audio Capability Not Support", 0);

                bAudioStatus = _FALSE;
            }
#endif // End of #if(_DP_SUPPORT == _ON)

            // Playback Status Check
            if(SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)
            {
                if(ScalerAudioLPCMCheckChange() == _TRUE)
                {
                    DebugMessageAudio("Audio Ready False : LPCM Status Change", 0);

                    bAudioStatus = _FALSE;
                }
            }

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
            // Audio Format Check Non-LPCM
            if(UserInterfaceAudioGetOutputMuteStatus() == _AUDIO_MUTE_ON)
            {
                bAudioStatus = _FALSE;
            }
#endif
        }

        return bAudioStatus;
    }

    return _FALSE;
}

#if(_DIGITAL_AUDIO_OUTPUT_MUTE_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : UserCommonAudioGetAdjustVolumeThroughDVC
// Input Value  :
// Output Value : _TRUE(Through DVC Control) ; _FALSE(By-Pass DVC Control)
//--------------------------------------------------
bit UserCommonAudioGetAdjustVolumeThroughDVC(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)

    EnumAudioDACOutput enumAudioDACOutput = UserInterfaceGetAudioDACOutput();

    if(enumAudioDACOutput != _AUDIO_DAC_OUTPUT_NONE)
    {
        // Through DVC Control
        return _TRUE;
    }
#endif

#if(_DIGITAL_AUDIO_OUTPUT_ADJUST_VOLUME_SUPPORT == _ON)
    // Through DVC Control
    return _TRUE;
#endif

    // By-Pass DVC Control
    return _FALSE;
}
#endif

#if(_DP_SUPPORT == _ON)
#if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Dp Audio Capability State
// Input Value  : Input Port
// Input Value  : EnumAudioDpDpcdSupport
// Output Value : None
//--------------------------------------------------
void UserCommonAudioDpSetCapabilityState(BYTE ucInputPort, EnumAudioDpDpcdSupport enumDpcdSupport)
{
    ScalerAudioDpSetCapabilityState(ucInputPort, enumDpcdSupport);
}
#endif // End of #if(_DP_DPCD_AUDIO_CAPABILITY_USER_CONTROL_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
//--------------------------------------------------
// Description  : Set TTS Play Event
// Input Value  : *pstAudioTtsSegment
//                ucSegmentSize
//                ucTtsVolume --> 0 ~ 100
//                ucAudioVolume --> 0 ~ 100
// Output Value : None
//--------------------------------------------------
void UserCommonAudioTtsSetPlaybackActiveEvent(StructAudioTtsSegment *pstAudioTtsSegment, BYTE ucSegmentSize, BYTE ucTtsVolume, BYTE ucAudioVolume)
{
    EnumAudioState enumAudioState = _AUDIO_STATUS_PREPARING;

    // =================
    // Support Check
    // =================

    // Check TTS Support or not
    if(UserInterfaceAudioGetTtsSupport() == _FALSE)
    {
        DebugMessageAudio("[TTS] OSD set to Not Support!", 0x00);

        return;
    }

    DebugMessageAudio("[TTS] Playback Event pre-setting", 0x00);


    // =================
    // Reset Flow
    // =================

    // Disable Play_Done_INT
    ScalerAudioTtsPlayDoneDetect(_DISABLE);

    // Clear TTS Related Flag
    ScalerAudioTtsClearFlag();

    // Reset SPIC
    ScalerAudioTtsSpicReset();

    // Turn-off Upsampling
    ScalerAudioTtsUpsamplingControl(_DISABLE);

    // Cancel Previous WD Event
    ScalerAudioTtsSetTimerEvent(_DISABLE);


    // =================
    // Prepare Flow
    // =================

    // Check Previous Audio State for volume setting
    enumAudioState = SysAudioGetAudioState();

    if(enumAudioState == _AUDIO_STATUS_PREPARING)
    {
        DebugMessageAudio("     -> Audio State From Preparing", 0x00);

        // Set TTS Volume to 100%
        ScalerAudioTtsDvcGainControl(UserAdjustAudioVolumeMapping(100), UserAdjustAudioVolumeMapping(0));

        // Set Main Volume to OSD Config
        UserAdjustAudioVolume(GET_OSD_VOLUME());
    }
    else if(enumAudioState == _AUDIO_STATUS_PLAYBACK)
    {
        DebugMessageAudio("     -> Audio State From Playback", 0x00);

        // Set TTS Volume to User Config
        ScalerAudioTtsDvcGainControl(UserAdjustAudioVolumeMapping(ucTtsVolume), UserAdjustAudioVolumeMapping(ucAudioVolume));
    }

    // Record TTS Segment data
    ScalerAudioTtsGetCommandData(pstAudioTtsSegment, ucSegmentSize);


    // =================
    // Active Event
    // =================

    // Set TTS Event Active for SysAudioHandler trigger
    ScalerAudioTtsSetPlaybackEvent(_ENABLE);
}

//--------------------------------------------------
// Description  : Get TTS Play Status
// Input Value  : None
// Output Value : _NO_PROCESSING / _PROCESSING / _PLAY_ERROR
//--------------------------------------------------
EnumAudioTtsPlayStatus UserCommonAudioTtsGetPlaybackStatus(void)
{
    return _TTS_NO_PROCESSING;
}

//--------------------------------------------------
// Description  : Get TTS Error Segment Play Fail
// Input Value  : None
// Output Value : ucErrorSegment
//--------------------------------------------------
BYTE UserCommonAudioTtsGetErrorSegment(void)
{
    BYTE ucErrorSegment = 0x00;

    return ucErrorSegment;
}
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get User Define Audio Gen Freq
// Input Value  : None
// Output Value : EnumAudioSamplingFreqType
//--------------------------------------------------
EnumAudioSamplingFreqType UserCommonAudioUpdateUserDefineAudioGenFreq(void)
{
#if(_INTERNAL_AUDIO_CHANNEL_CONFIG_BY_USER_SUPPORT == _ON)
    // Return Frequency
    switch(UserInterfaceAudioGetUserDefineAudioGenFreq())
    {
        case _AUDIO_GEN_FREQ_500HZ:

            return _AUDIO_FREQ_32K;

            break;

        case _AUDIO_GEN_FREQ_750HZ:

            return _AUDIO_FREQ_48K;

            break;

        case _AUDIO_GEN_FREQ_1000HZ:

            return _AUDIO_FREQ_64K;

            break;

        case _AUDIO_GEN_FREQ_1500HZ:

            return _AUDIO_FREQ_96K;

            break;

        case _AUDIO_GEN_FREQ_2000HZ:

            return _AUDIO_FREQ_128K;

            break;

        case _AUDIO_GEN_FREQ_3000HZ:

            return _AUDIO_FREQ_192K;

            break;

        default:

            return _AUDIO_FREQ_64K;
            break;
    }
#else
    return _AUDIO_FREQ_64K;
#endif
}

//--------------------------------------------------
// Description  : Get User Define Audio Gen Freq
// Input Value  : None
// Output Value : EnumAudioSamplingFreqType
//--------------------------------------------------
EnumAudioLeftRightChannelSelect UserCommonAudioGetUserLeftRightChanelSelect(void)
{
#if(_INTERNAL_AUDIO_CHANNEL_CONFIG_BY_USER_SUPPORT == _ON)
    return UserInterfaceAudioGetUserLeftRightChanelSelect();
#else
    return _AUDIO_LEFT_RIGHT_CHANNEL;
#endif
}
#endif
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Set Z0 HPD Type
// Input Value  : Z0/HPD type, Z0LowPeriod(ms), usHpdLowPeriod(ms), usZ0HpdInterval(ms)
// Output Value : None
// --|______________|----------------|______________|-----
//    usZ0LowPeriod  usZ0HpdInterval  usHpdLowPeriod
//--------------------------------------------------
void UserCommonInterfaceTmdsSetHdmiZ0HpdType(EnumHdmiZ0HpdType enumHdmiZ0HpdType, WORD usZ0LowPeriod, WORD usZ0HpdInterval)
{
    ScalerSyncTMDSSetHdmiZ0HpdType(enumHdmiZ0HpdType, usZ0LowPeriod, usZ0HpdInterval);
}

//--------------------------------------------------
// Description  : Get HDMI Z0 Status (when High, Kernel has been toggle HPD)
// Input Value  : InputPort
// Output Value : EnumHdmiZ0Status
//--------------------------------------------------
EnumHdmiZ0Status UserCommonInterfaceTmdsGetZ0Status(BYTE ucInputPort)
{
    if(ScalerSyncTmdsGetDigitalPort(ucInputPort) == _TRUE)
    {
        return _HDMI_Z0_HIGH;
    }
    else
    {
        return _HDMI_Z0_LOW;
    }
}

#if((_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON) && (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get HDMI SPD Product Description Info Contents
// Input Value  : InputPort
// Output Value : EnumHdmiSpdProuductlInfo
//--------------------------------------------------
StructHdmiSpdInfo UserCommonInterfaceTmdsGetSpdInfo(EnumSourceSearchPort enumInputPort)
{
    return ScalerTMDSHdmiGetSpdPdInfo(enumInputPort);
}

//--------------------------------------------------
// Description  : Get HDMI SPD Product Description Info Contents
// Input Value  : InputPort
// Output Value : EnumHdmiSpdProuductlInfo
//--------------------------------------------------
EnumHdmiSpdProuductlInfo UserCommonInterfaceTmdsGetSpdPdInfo(EnumSourceSearchPort enumInputPort)
{
    StructHdmiSpdInfo stSpdInfo;
    memset(&stSpdInfo, 0, sizeof(stSpdInfo));

    stSpdInfo = UserCommonInterfaceTmdsGetSpdInfo(enumInputPort);

    if(stSpdInfo.b1StructValuable == 0x01)
    {
        if(memcmp(stSpdInfo.pucHdmiProductDescription, "PS4", 3) == 0)
        {
            return _PRODUCT_DESCRIPTION_PS4;
        }

        if(memcmp(stSpdInfo.pucHdmiProductDescription, "PS5", 3) == 0)
        {
            return _PRODUCT_DESCRIPTION_PS5;
        }

        if(memcmp(stSpdInfo.pucHdmiProductDescription, "Xbox One", 8) == 0)
        {
            return _PRODUCT_DESCRIPTION_XBOX_ONE;
        }

        if(memcmp(stSpdInfo.pucHdmiProductDescription, "Xbox", 4) == 0)
        {
            return _PRODUCT_DESCRIPTION_XBOX;
        }
    }

    return _PRODUCT_DESCRIPTION_NONE;
}
#endif
#endif

#if(_DVI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check Fake Off Status
// Input Value  : None
// Output Value : _TRUE ==> POWER STATUS is Fake OFF
//--------------------------------------------------
bit UserCommonInterfacePowerCheckFakeOff(void)
{
    if(SysPowerCheckFakeOff() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : HDMI HPD/ DDC Config
// Input Value  : enumInputPort
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTmdsHotPlugDdcConfig(BYTE ucInputPort, bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // When Enable, HPD set H & Ddc pinshare switch to correct(ie.DDC Normal work)
        switch(ucInputPort)
        {
#if(_D0_TMDS_SUPPORT == _ON)
            case _D0_INPUT_PORT:
                PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC0))
                ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_DDC);
#endif
                break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
            case _D1_INPUT_PORT:
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC1))
                ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#endif
                break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
            case _D2_INPUT_PORT:
                PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC2))
                ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#endif
                break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
            case _D3_INPUT_PORT:
                PCB_D3_HOTPLUG(_D3_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC3))
                ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif
                break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
            case _D4_INPUT_PORT:
                PCB_D4_HOTPLUG(_D4_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC4))
                ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_DDC);
#endif
                break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
            case _D5_INPUT_PORT:
                PCB_D5_HOTPLUG(_D5_HOT_PLUG_HIGH);
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC4))
                ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_DDC);
#endif
                break;
#endif
            default:
                break;
        }
    }
    else
    {
        // When Disable, HPD set Low & Ddc pinshare switch to GPI(ie. DDC force Nack)
        switch(ucInputPort)
        {
#if(_D0_TMDS_SUPPORT == _ON)
            case _D0_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC0))
                ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_GPI);
#endif
                PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
            case _D1_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC1))
                ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPI);
#endif
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
            case _D2_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC2))
                ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPI);
#endif
                PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
            case _D3_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC3))
                ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPI);
#endif
                PCB_D3_HOTPLUG(_D3_HOT_PLUG_LOW);
                break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
            case _D4_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC4))
                ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_GPI);
#endif
                PCB_D4_HOTPLUG(_D4_HOT_PLUG_LOW);
                break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
            case _D5_INPUT_PORT:
#if((_DEBUG_MESSAGE_SUPPORT == _OFF) || (_PCB_DEBUG_DDC != _DDC4))
                ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_GPI);
#endif
                PCB_D5_HOTPLUG(_D5_HOT_PLUG_LOW);
                break;
#endif
            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Switch HDCP Version Capbility
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceTmdsHdcpVersionCapabilitySwitch(EnumSourceSearchPort enumInputPort, EnumTmdsHdcpType enumTmdsHdcpType)
{
    ScalerTMDSRxHdcpVersionCapabilitySwitch(enumInputPort, enumTmdsHdcpType);
}
#endif

#if(_COLORIMETRY_SEAMLESS_CHANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Decide Input Port Digitial Color Info Change Check
// Input Value  : None
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
bit UserCommonInterfaceColorimetrySeamlessChangeCheckBypass(EnumSourceSearchPort enumInputPort)
{
    enumInputPort = enumInputPort;

#if(_DP_SUPPORT == _ON)
#if(_DP_COLORIMTRY_SEAMLESS_COLOR_INFO_CHECK_BYPASS == _ON)
    if((GET_PORT_TYPE(SysSourceGetInputPortType(enumInputPort))) == _PORT_DP)
    {
        return _TRUE;
    }
#endif
#endif

    return _FALSE;
}
#endif
//_HDMI_24C02_SUPPORT
#if((_D1_INPUT_PORT_TYPE!=_D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
	((_D2_INPUT_PORT_TYPE!=_D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D3_INPUT_PORT_TYPE!=_D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))||\
		((_D0_INPUT_PORT_TYPE!=_D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))

//--------------------------------------------------
// Description  : Restore default EDID
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//烧完软件第一次往24C02里面写EDID
#define  		_EXTRNAL_BURN_IN_COUNT          				16  //256 分多少次写入 写2为一次写128 4为一次写64 必现能被256整除


void UserCommonInterfaceNVRamSaveEDIDWhenProgramming(void)
{	
	BYTE count= 10;
	BYTE i = 0;
   	BYTE xdata pucBuffer[256/_EXTRNAL_BURN_IN_COUNT] = {0};
   	//BYTE SN[14] = {_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_,_END_};

#if((_A0_INPUT_PORT_TYPE!=_A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_A0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))

	PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);
	ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_GPIO);

	ScalerTimerDelayXms(10); 
	
	for(i=0; i<_EXTRNAL_BURN_IN_COUNT; i++)
	{
		memcpy(pucBuffer, tEDID_TABLE_A0+(i*256/_EXTRNAL_BURN_IN_COUNT), 256/_EXTRNAL_BURN_IN_COUNT);
		if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_VGA_DDC, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8)==_FAIL)
		{
			ScalerTimerDelayXms(100); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_VGA_DDC, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		}		
	}
	

	ScalerPinshareGpioDdcPinSwitch(_DDC_VGA_SWITCH_DDC);

	ScalerTimerDelayXms(10);

	PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);


#endif


#if((_D0_INPUT_PORT_TYPE!=_D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D0_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))

	PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);

	ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_GPIO);

	ScalerTimerDelayXms(10); 

	for(i=0; i<_EXTRNAL_BURN_IN_COUNT; i++)
	{
		memcpy(pucBuffer, tEDID_TABLE_D0+(i*256/_EXTRNAL_BURN_IN_COUNT), 256/_EXTRNAL_BURN_IN_COUNT);
		if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC0, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8)==_FAIL)
		{
			ScalerTimerDelayXms(100); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC0, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		}		
	}
	
		
	ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_DDC);

	ScalerTimerDelayXms(10);

	PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);


#endif


#if ((_D1_INPUT_PORT_TYPE!=_D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D1_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))


	PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);

	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);

	ScalerTimerDelayXms(10); 
	
	for(i=0; i<_EXTRNAL_BURN_IN_COUNT; i++)
	{
		memcpy(pucBuffer, tEDID_TABLE_D1+(i*256/_EXTRNAL_BURN_IN_COUNT), 256/_EXTRNAL_BURN_IN_COUNT);
		if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8)==_FAIL)
		{
			ScalerTimerDelayXms(100); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		}		
	}

	
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
	
	ScalerTimerDelayXms(10);

	PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);


#endif

#if ((_D2_INPUT_PORT_TYPE!=_D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D2_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))


	PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);

	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);

	ScalerTimerDelayXms(10); 
	
	for(i=0; i<_EXTRNAL_BURN_IN_COUNT; i++)
	{
		memcpy(pucBuffer, tEDID_TABLE_D2+(i*256/_EXTRNAL_BURN_IN_COUNT), 256/_EXTRNAL_BURN_IN_COUNT);
		if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8)==_FAIL)
		{
			ScalerTimerDelayXms(100); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		}		
	}

	
	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
	
	ScalerTimerDelayXms(10);

	PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);


#endif


#if ((_D3_INPUT_PORT_TYPE!=_D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION ==_EDID_TABLE_LOCATION_USER)&&(_D3_EMBEDDED_DDCRAM_MAX_SIZE == _EDID_SIZE_NONE))


	PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_DISABLE);

	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);

	ScalerTimerDelayXms(10); 
	
	for(i=0; i<_EXTRNAL_BURN_IN_COUNT; i++)
	{
		memcpy(pucBuffer, tEDID_TABLE_D3+(i*256/_EXTRNAL_BURN_IN_COUNT), 256/_EXTRNAL_BURN_IN_COUNT);
		if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8)==_FAIL)
		{
			ScalerTimerDelayXms(100); 
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00+(i*256/_EXTRNAL_BURN_IN_COUNT), 1, 256/_EXTRNAL_BURN_IN_COUNT, pucBuffer, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
		}		
	}

	
	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
	
	ScalerTimerDelayXms(10);

	PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EDID_EEPROM_WP_ENABLE);


#endif


}


#endif
