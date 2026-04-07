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
// ID Code      : RL6449_Series_DpGetVideoStream.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_DPLibInternalInclude.h"

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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerDpGetVideoStream(BYTE ucInputPort);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Check Dp Video Straam VBID
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True --> Get Video Stream
//--------------------------------------------------
bit ScalerDpGetVideoStream(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

            if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
            {
                return (ScalerGetBit(PB6_01_DP_VBID, _BIT3) == 0x00);
            }

            break;

        case _D1_INPUT_PORT:

            if(GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
            {
                return (ScalerGetBit(PB9_01_DP_VBID, _BIT3) == 0x00);
            }

            break;

        default:

            break;
    }

    return _FALSE;
}
