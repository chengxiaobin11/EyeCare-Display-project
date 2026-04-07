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

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerCommonTypeCInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_TYPE_C_ALT_MODE_READY(x)                        (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].enumAltModeStatus)
#define SET_TYPE_C_ALT_MODE_READY(x, y)                     (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].enumAltModeStatus = (y))

#define GET_TYPE_C_EXPLICIT_CONTRACT(x)                     (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].b1PowerContract)
#define SET_TYPE_C_EXPLICIT_CONTRACT(x, y)                  (g_pstTypeCInfo[ScalerTypeCGetTypeCIndex(x)].b1PowerContract = (y))

#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
#define GET_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent)
#define SET_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent = _TRUE)
#define CLR_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent = _FALSE)
#endif
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Structure of Type-C Related Structs
//--------------------------------------------------
typedef struct
{
    EnumTypeCAltModeStatus enumAltModeStatus;
    // -----------------------------
    BYTE b1PowerContract : 1;
} StructTypeCInfo;


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
extern bit g_bTypeC5400LenovoAltModeUrgentEvent;
#endif
#endif

extern StructTypeCInfo g_pstTypeCInfo[_TYPE_C_PORT_VALID];
extern StructTypeCCableInfoForDpcd g_pstTypeCCableInfoForDpcd[_INPUT_PORT_VALID];


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort);
extern bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort);

#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
extern EnumTypeCAttachStatus ScalerTypeCGetCcAttach(BYTE ucInputPort);
extern bit ScalerTypeCGetExplicitContract(BYTE ucInputPort);

#if(_BILLBOARD_SCALER_SUPPORT == _ON)
extern void ScalerTypeCGetAltModeBillboardInfo(BYTE ucInputPort, BYTE *pucBillboardAltModeInfo);
#endif

#endif // End of #if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

