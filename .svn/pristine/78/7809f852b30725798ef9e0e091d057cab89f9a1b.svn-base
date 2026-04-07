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
// ID Code      : RL6851_Series_MDomainInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _MEMORY_ACCESS_TYPE                         (_FRAME_MODE)

#define _FRC_WRITE_BW_MULTIPLE                      (1)

#define _DIS_TIMING_GEN_HTOTAL_BIT                  (_13_BIT)

#define _DIS_TIMING_GEN_H_ACTIVE_BIT                (_13_BIT)
#define _DIS_TIMING_GEN_V_ACTIVE_BIT                (_13_BIT)

#define GET_DVTOTAL_LASTLINE_RAW(usBackup)          {\
                                                        (usBackup) = ((((WORD)(ScalerGetByte(P0_46_LAST_LINE_H1) & 0x01) << 13) |\
                                                                       ((WORD)(ScalerGetByte(P0_44_LAST_LINE_H) & 0x1F) << 8) |\
                                                                               ScalerGetByte(P0_45_LAST_LINE_L)) & 0x3FFF);\
                                                    }

#define GET_DVTOTAL_LASTLINE(usBackup)              {\
                                                        ScalerTimerClrEventStatus(_EVENT_DVS);\
                                                        GET_DVTOTAL_LASTLINE_RAW(usBackup);\
                                                        if(ScalerTimerGetEventStatus(_EVENT_DVS) == _EVENT_DVS)\
                                                        {\
                                                            GET_DVTOTAL_LASTLINE_RAW(usBackup);\
                                                        }\
                                                    }

#define GET_SAFE_DVTOTAL_LASTLINE(usBackup)         {\
                                                        WORD usLocalBackup = 0;\
                                                        ScalerTimerClrEventStatus(_EVENT_DVS);\
                                                        GET_DVTOTAL_LASTLINE_RAW(usLocalBackup);\
                                                        if(ScalerTimerGetEventStatus(_EVENT_DVS) != _EVENT_DVS)\
                                                        {\
                                                            (usBackup) = usLocalBackup;\
                                                        }\
                                                    }

#define SET_D_DOMAIN_V_ACT_END(usBackup)            {\
                                                        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_12_DISPLAY_VER_ACT_END_H);\
                                                        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usBackup) & 0x0F));\
                                                        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usBackup));\
                                                    }
#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Macros of FRC Style
//--------------------------------------------------
#define GET_MDOMAIN_FRC_STYLE()                     (g_stMDomainFRCInfo.b1PreFRCStyle)
#define SET_MDOMAIN_FRC_STYLE(x)                    (g_stMDomainFRCInfo.b1PreFRCStyle = (x))
#endif // End of #if(_FRC_SUPPORT == _ON)

//--------------------------------------------------
// Macros of DVFreq. Info.
//--------------------------------------------------
#define GET_OUTPUT_VFREQ()                          (g_usMDomainDVFreq)// Freesync Line Buffer Priority
//--------------------------------------------------
#define _FREESYNC_LINEBUFFER_PRIORITY               _ON

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Macros of Memory Bandwidth
//--------------------------------------------------
#define GET_MEMORY_BW()                             (g_stMDomainFRCInfo.usUseMemoryBW)
#define SET_MEMORY_BW(x)                            (g_stMDomainFRCInfo.usUseMemoryBW = (x))
#define CLR_MEMORY_BW()                             (g_stMDomainFRCInfo.usUseMemoryBW = 0)

//--------------------------------------------------
// Macros of FRC Control Param Index
//--------------------------------------------------
#define GET_MDOMAIN_FRC_CTRL_PARAM_INDEX()          (g_stMDomainBackupInfo.ucFRCCtrlParamIndex)
#define SET_MDOMAIN_FRC_CTRL_PARAM_INDEX(x)         (g_stMDomainBackupInfo.ucFRCCtrlParamIndex = (x))
#define CLR_MDOMAIN_FRC_CTRL_PARAM_INDEX()          (g_stMDomainBackupInfo.ucFRCCtrlParamIndex = 0)
#endif // End of #if(_FRC_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
#define GET_MEMORY_REMAIN_BW()                      (g_ulMDomainFRCMemoryRemainBW)
#define SET_MEMORY_REMAIN_BW(x)                     (g_ulMDomainFRCMemoryRemainBW = (x))
#else
#define GET_MEMORY_REMAIN_BW()                      (GET_MEMORY_TOTAL_BW())
#endif
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
typedef struct
{
    BYTE b1PreFRCStyle : 1;
    WORD usUseMemoryBW;
    WORD usFIFOHwidth;
}StructFRCInfo;
#endif // End of #if(_FRC_SUPPORT == _ON)

//--------------------------------------------------
// Structure of MDomain Backup
//--------------------------------------------------
typedef struct
{
    BYTE ucFRCCtrlParamIndex;
}StructMDomainBackupInfo;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructMDomainBackupInfo g_stMDomainBackupInfo;
extern WORD g_usMDomainDVFreq;

#if(_FRC_SUPPORT == _ON)
extern StructFRCInfo g_stMDomainFRCInfo;
#endif

#if((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON))
extern DWORD g_ulMDomainFRCMemoryRemainBW;
#endif
//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMDomainControlDBApply(void);
extern bit ScalerMDomainMemoryCheck(void);
extern void ScalerMDomainDisplayTimingGenDBApply(EnumDBApply enumDBApply);

