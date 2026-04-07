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
// ID Code      : RL6851_Series_FRCInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
#define GET_FRC_BOTTOM_ADDR()                             (g_ulFRCBottom)
#define SET_FRC_BOTTOM_ADDR(x)                            (g_ulFRCBottom = (x))
#define GET_FRC_TOTAL_USE_ROW()                           (g_ulFRCUseRow)
#define SET_FRC_TOTAL_USE_ROW(x)                          (g_ulFRCUseRow = (x))
#define GET_ROW_PER_PATH()                                (g_ulFRCRowPerPath)
#define SET_ROW_PER_PATH(x)                               (g_ulFRCRowPerPath = (x))

#define _MEMORY_BOTTOM_ADDRESS                            ((DWORD)_MEMORY_ROW << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM) // 0x0200 0000

#define GET_FRC_MAIN_BW()                                 (g_ulFRCMainBW)
#define SET_FRC_MAIN_BW(x)                                (g_ulFRCMainBW = (x))
#endif // End of #if(_FRC_SUPPORT == _ON)

//--------------------------------------------------
// Deinfe FRC setting path
//--------------------------------------------------
#define _FRC_CAP_MAIN_1                                   (_BIT0)
#define _FRC_DISP_MAIN_1                                  (_BIT4)

#define _FRC_CAP_DISP_ALL                                 (_FRC_CAP_MAIN_1 | _FRC_DISP_MAIN_1)

//--------------------------------------------------
// Define ImgCmp
//--------------------------------------------------

#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#define _IMG_CMP_PARAM_LLB_8B_TYP                         _IMG_CMP_PARAM_LLB_8
#define _IMG_CMP_PARAM_LLB_8B_MIN                         _IMG_CMP_PARAM_LLB_6
#define _IMG_CMP_PARAM_LLB_10B_TYP                        _IMG_CMP_PARAM_LLB_10
#define _IMG_CMP_PARAM_LLB_10B_MAX                        _IMG_CMP_PARAM_LLB_12
#else
#define _IMG_CMP_PARAM_LLB_8B_TYP                         _IMG_CMP_PARAM_OFF
#endif

//--------------------------------------------------
// Deinfe for FRC auto 3 block toggle
//--------------------------------------------------
#define _FRC_R_1ST_BLOCK_STA_ADDR                         (0x00) // 0 row
#define _FRC_R_2ND_BLOCK_STA_ADDR                         ((DWORD)(_MEMORY_ROW / 3 * 2) << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM)
#define _FRC_R_3RD_BLOCK_STA_ADDR                         ((DWORD)(_MEMORY_ROW / 3) << _FW_MEM_ROW_ADDR_SHIFT_BIT_NUM)

//--------------------------------------------------
// Deinfe for one-frame FRC
//--------------------------------------------------
#define GET_DEFAULT_FRAME_USE_MEMORY_ROW(x)               ((DWORD)(x) / _FW_MEM_CLIENT_MEMORY_BIT_NUM / _MEMORY_COL_PER_BANK / _MEMORY_BANK) // memory row

#if(_FRC_SUPPORT == _ON)
#define _FRAME_SIZE_MARGIN                                (10) // memory row

// FRC Rate Ctrl Param
#define GET_IMG_CMP_PARAM()                               (ScalerFRCImgCmpGetPara())
#define GET_FRC_RCP_IMG_CMP_PARAM(x)                      (ScalerFRCGetRcpImcCmpParamFromIndex(x))
#define GET_FRC_RCP_IMG_CMP_EN(x)                         (GET_IMG_CMP_ENABLE(GET_FRC_RCP_IMG_CMP_PARAM(x)))
#define GET_FRC_RCP_IMG_CMP_LLB(x)                        (GET_IMG_CMP_PARAM_LLB(GET_FRC_RCP_IMG_CMP_PARAM(x)))
#define GET_FRC_RCP_FIFO_COLOR_DEPTH(x)                   (ScalerFRCGetRcpFifoColorDepthFromIndex(x))

#define GET_FRC_RCP_FIFO_BPP(x)                           (GET_FRC_RCP_FIFO_COLOR_DEPTH(x) * 3)
#define GET_FRC_RCP_HSD_EN(x)                             (ScalerFRCGetRcpHsdEnFromIndex(x))

#if(_OD_SUPPORT == _ON)
#define GET_FRC_RCP_OD_PARAM(x)                           (ScalerFRCGetRcpODParamFromIndex(x))
#else
#define GET_FRC_RCP_OD_PARAM(x)                           (_OD_PARAM_OFF)
#endif
#define GET_FRC_RCP_BPP(x)                                (GET_FRC_RCP_IMG_CMP_EN(x) ? GET_FRC_RCP_IMG_CMP_LLB(x) : GET_FRC_RCP_FIFO_BPP(x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Enumerations of FRC on/off
//--------------------------------------------------
typedef enum
{
    _IMG_CMP_PARAM_OFF = 0,
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
    _IMG_CMP_PARAM_LLB_12,
    _IMG_CMP_PARAM_LLB_11,
    _IMG_CMP_PARAM_LLB_10,
    _IMG_CMP_PARAM_LLB_9,
    _IMG_CMP_PARAM_LLB_8,
    _IMG_CMP_PARAM_LLB_7,
    _IMG_CMP_PARAM_LLB_6,
#endif
} EnumImgCmpParamIndex;

typedef enum
{
    _FRC_INPUT_SLOWER,
    _FRC_INPUT_FASTER,
} EnumFRCStyle;

//--------------------------------------------------
// Enumerations of FRC on/off
//--------------------------------------------------
typedef enum
{
    _FRC_1ST_BLOCK,
    _FRC_2ND_BLOCK,
    _FRC_3RD_BLOCK,
    _FRC_4TH_BLOCK,
} EnumFRCBlock;

typedef enum
{
    _FRC_BOUNDARY_DEFAULT,
    _FRC_BOUNDARY_NORMAL,
} EnumFRCBoundary;


#if((_FRC_SUPPORT == _ON) || (_OD_SUPPORT == _ON))

typedef struct
{
    BYTE ucFBCoopEn;
    WORD usIVTotal;
    WORD usIVFreq;
    WORD usDVTotal;
    WORD usDVFreq;
    EnumDVFSelect enumDVFSelect;
} StructMemoryBWUsageParam;
#endif

#if(_FRC_SUPPORT == _ON)
typedef struct
{
    BYTE ucImgCmpUsable;
    BYTE ucMDomainExt;
    WORD usInputHWidth;
    WORD usFifoHWidth;
    WORD usFifoVHeight;
    DWORD ulGrantBW;

    StructMemoryBWUsageParam stMemBWParam;
} StructFRCRateCtrlInfo;

//--------------------------------------------------
// Structure of PQC Data
//--------------------------------------------------
typedef struct
{
    BYTE b5FifoColorDepth : 5;
    BYTE b1AllowHSD : 1;
    EnumImgCmpParamIndex enumImgCmpParamIndex;
    EnumODParamIndex enumExpectODParamIndex;
} StructFRCRateCtrlParam;

#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_FRC_SUPPORT == _ON)
extern DWORD g_ulFRCRowPerPath;
extern DWORD g_ulFRCBottom;
extern DWORD g_ulFRCUseRow;
extern DWORD g_ulFRCMainBW;
#endif
//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
void ScalerFRCPowerOnInitial(void);
#endif

#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
extern void ScalerFRCInitial(void);
extern void ScalerFRCEn(BYTE ucSettingPath, bit bEn);
#endif

#if(_FRC_SUPPORT == _ON)
extern WORD ScalerFRCSetOneFrameDVTotal(void);
extern void ScalerFRCControl(const StructSDRAMDataInfo *pstFIFOSize);
extern bit ScalerFRCGetImgCmpHWUsability(void);
extern bit ScalerFRCGetImgCmpRunTimeUsability(WORD usWidth);
extern BYTE ScalerFRCGetMemRateCtrlParamIndex(StructFRCRateCtrlInfo *pstRateCtrlInfo);
extern void ScalerFRCApplyMemRateCtrlParam(BYTE ucRateCtrlParamIndex);
extern DWORD ScalerFRCGetLineSumBit(WORD usHorSize, BYTE ucFIFOMemBits, EnumImgCmpParamIndex enumImgCmpIndex);
extern void ScalerFRCSetMemoryBoundary(EnumFRCBoundary enumFRCBoundary);
extern EnumImgCmpParamIndex ScalerFRCGetRcpImcCmpParamFromIndex(BYTE ucIndex);
extern BYTE ScalerFRCGetRcpFifoColorDepthFromIndex(BYTE ucIndex);
extern DWORD ScalerFRCBWCalUsage(WORD usCaphwidth, WORD usDisphwidth, WORD usColorDepth, EnumImgCmpParamIndex enumLLB, DWORD ulPixelclk, bit bDefaultMode);
extern void ScalerFRCSpaceInitialAllocation(void);
extern void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);
extern EnumImgCmpParamIndex ScalerFRCImgCmpGetPara(void);
#endif


