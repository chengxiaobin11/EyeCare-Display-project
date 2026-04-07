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
// ID Code      : RL6369_Series_MDomainInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _MEMORY_ACCESS_TYPE                         (_FRAME_MODE)

#define _FRC_WRITE_BW_MULTIPLE                      (1)

#define _DIS_TIMING_GEN_HTOTAL_BIT                  (_12_BIT)

#define _DIS_TIMING_GEN_H_ACTIVE_BIT                (_12_BIT)
#define _DIS_TIMING_GEN_V_ACTIVE_BIT                (_12_BIT)

#define GET_DVTOTAL_LASTLINE_RAW(usBackup)          {\
                                                        (usBackup) = ((((WORD)(ScalerGetByte(P0_44_LAST_LINE_H) & 0x1F) << 8) |\
                                                                               ScalerGetByte(P0_45_LAST_LINE_L)) & 0x1FFF);\
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

//--------------------------------------------------
// Freesync Line Buffer Priority
//--------------------------------------------------
#define _FREESYNC_LINEBUFFER_PRIORITY               _ON

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMDomainControlDBApply(void);
extern bit ScalerMDomainMemoryCheck(void);
extern void ScalerMDomainDisplayTimingGenDBApply(EnumDBApply enumDBApply);

