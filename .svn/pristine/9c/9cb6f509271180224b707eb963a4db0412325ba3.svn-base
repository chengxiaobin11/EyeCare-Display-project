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
// ID Code      : RL6851_Series_ScalerDisplayDPTxInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PANEL_STYLE == _PANEL_DPTX)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_DISPLAY_DP_TX_PORT_1 == _ON)
#if(_PANEL_DPTX_HPD_DETECT == _ON)
#define GET_DISPLAY_DP_TX1_FORCE_TO_LT()                            (g_bDisplayDpTx1ForceLT)
#define SET_DISPLAY_DP_TX1_FORCE_TO_LT()                            (g_bDisplayDpTx1ForceLT = _TRUE)
#define CLR_DISPLAY_DP_TX1_FORCE_TO_LT()                            (g_bDisplayDpTx1ForceLT = _FALSE)
#endif
#endif

#if(_PANEL_DPTX_HPD_DETECT == _ON)
#if(_DISPLAY_DP_TX_PORT_1 == _ON)
#define GET_DISPLAY_DP_TX_FORCE_TO_LT()                             (GET_DISPLAY_DP_TX1_FORCE_TO_LT() == _TRUE)
#define CLR_DISPLAY_DP_TX_FORCE_TO_LT()                             {\
                                                                        CLR_DISPLAY_DP_TX1_FORCE_TO_LT();\
                                                                    }
#endif
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DISPLAY_DP_TX_PORT_1 == _ON)
#if(_PANEL_DPTX_HPD_DETECT == _ON)
extern volatile bit g_bDisplayDpTx1ForceLT;
#endif
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDisplayDPTxAnalogPhyConrol(bit bEnable);

#if(_PANEL_DPTX_HPD_DETECT == _ON)
extern bit ScalerDisplayDPTxStableDetect(void);
#if(_PANEL_DPTX_IRQ_HPD_DETECT == _ON)
void ScalerDisplayDPTxIrqIntHandler_EXINT0(void);
#endif
#endif

extern bit ScalerDisplayDPTxAuxI2CoverWrite(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray, bit bMOT);
extern bit ScalerDisplayDPTxAuxI2CoverRead(EnumDisplayDpTxOutputPort enumDisplayDpTxOutputPort, BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray, bit bMOT);
#endif


