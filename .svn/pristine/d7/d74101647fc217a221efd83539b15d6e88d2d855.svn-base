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
// ID Code      : RL6851_Series_ScalerDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DISPLAY__

#include "ScalerFunctionInclude.h"

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
StructDisplayCustomizedData g_stDisplayCustomizedData;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_LVDS)
void ScalerDisplayLvdsTxDataSel(void);
void ScalerDisplayLvdsTxPortSwap(void);
#endif

BYTE ScalerDisplaySelectDVFMode(void);
void ScalerDisplaySetDVFreq(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_PANEL_STYLE == _PANEL_LVDS)
//--------------------------------------------------
// Description  : LVDS TX Port output Data Selection
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsTxDataSel(void)
{
#if(_LVDS_PORT_SEL == _LVDS_1_PORT_C)

    ScalerSetByte(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, 0x00);

#elif(_LVDS_PORT_SEL == _LVDS_1_PORT_D)

    ScalerSetByte(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, 0x00);

#elif(_LVDS_PORT_SEL == _LVDS_2_PORT_CD)

    ScalerSetByte(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, ((_LVDS_PORT_MIRROR == _DISABLE) ? 0x01 : 0x10));

#endif // #if(_LVDS_PORT_SEL == _LVDS_1_PORT_C)
}

//--------------------------------------------------
// Description  : LVDS TX Port output Data Swap Selection
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsTxPortSwap(void)
{
    BYTE ucLvdsPortSwapIndex = 0;

    // Port CD Swap
    ucLvdsPortSwapIndex = ((_LVDS_PORT_CD_SWAP == _DISABLE) ? 0 : 4);

    ScalerSetByte(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, (((ScalerGetBit(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, (_BIT7 | _BIT6 | _BIT5 | _BIT4))) >> ucLvdsPortSwapIndex) | ((ScalerGetBit(_LVDS_TXCD_OUTPUT_DATA_PORT_ADDR, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) << ucLvdsPortSwapIndex)));
}
#endif // End of #if(_PANEL_STYLE == _PANEL_LVDS)

//--------------------------------------------------
// Description  : Set display DVF mode by V freq.
// Input Value  : stDVCustomizedFreq --> custim V freq. range
// Output Value : None
//--------------------------------------------------
BYTE ScalerDisplaySelectDVFMode(void)
{
#if(_FRC_SUPPORT == _ON)
#if(_DRR_FREE_RUN_DISPLAY_SUPPORT == _OFF)
#if(_DRR_SUPPORT == _ON)
    if(ScalerDrrGetType() != _DRR_NONE_TYPE)
    {
        return _1_IVF;
    }
    else
#endif
#endif
    {
        if(g_stDisplayCustomizedData.stDVCustomizedFreq.b1FORCETOFREERUN == _ENABLE)
        {
            return _PANEL_TYP_FRAME_RATE_FREE_RUN;
        }
        else
        {
            WORD usMaxFreqMargin = g_stDisplayCustomizedData.stDVCustomizedFreq.usMaxFreq + _FRAME_SYNC_MARGIN;
            WORD usMinFreqMargin = g_stDisplayCustomizedData.stDVCustomizedFreq.usMinFreq - _FRAME_SYNC_MARGIN;

            if((g_stMDomainInputData.usVFreq <= usMaxFreqMargin) &&
               (g_stMDomainInputData.usVFreq >= usMinFreqMargin))
            {
                return _1_IVF;
            }
            else
            {
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if((_DISPLAY_ROTATION_TYPE == _DISPLAY_ROTATION_GEN_II) && (_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON))
                if(ScalerRotationCheckStatus() == _TRUE)
                {
#if(_MN_FRAME_TRACKING_SUPPORT == _ON)
#if(_MN_FRAMESYNC_FORCE_TO_FREERUN == _OFF)
                    if((g_stMDomainInputData.usVFreq <= (usMaxFreqMargin * 5 / 4)) &&
                       (g_stMDomainInputData.usVFreq >= (usMinFreqMargin * 5 / 4))) // DVF = 5 * IVF / 4
                    {
                        return _5_4_IVF;
                    }
                    else if((g_stMDomainInputData.usVFreq <= (usMaxFreqMargin * 6 / 5)) &&
                            (g_stMDomainInputData.usVFreq >= (usMinFreqMargin * 6 / 5))) // DVF = 6 * IVF / 5
                    {
                        return _6_5_IVF;
                    }
                    else
#endif
#endif
                    {
                        return _PANEL_TYP_FRAME_RATE_FREE_RUN;
                    }
                }
                else
#endif
#endif
                {
#if(_MN_FRAME_TRACKING_SUPPORT == _ON)
#if(_MN_FRAMESYNC_FORCE_TO_FREERUN == _OFF)
                    if((g_stMDomainInputData.usVFreq <= (usMaxFreqMargin / 2)) &&
                       (g_stMDomainInputData.usVFreq >= (usMinFreqMargin / 2))) // DVF = 2 * IVF
                    {
                        // For 1080p_30
                        return _2_IVF;
                    }
                    else if((g_stMDomainInputData.usVFreq <= (usMaxFreqMargin * 2 / 5)) &&
                            (g_stMDomainInputData.usVFreq >= (usMinFreqMargin * 2 / 5))) // DVF = 2.5 * IVF
                    {
                        // For 1080p_25, 1080p_24
                        return _2_5_IVF;
                    }
                    else if((g_stMDomainInputData.usVFreq <= (usMaxFreqMargin / 3)) &&
                            (g_stMDomainInputData.usVFreq >= (usMinFreqMargin / 3))) // DVF = 3 * IVF
                    {
                        return _3_IVF;
                    }
                    else
#endif
#endif
                    {
                        return _PANEL_TYP_FRAME_RATE_FREE_RUN;
                    }
                }
            }
        }
    }
#else // else of #if(_FRC_SUPPORT == _ON)

    return _1_IVF;

#endif // End of #if(_FRC_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : Set DVfreq.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplaySetDVFreq(void)
{
    switch(GET_MEMORY_DVF_SELECT())
    {
        case _1_IVF:
            g_usDVFreq = g_stMDomainInputData.usVFreq;
            break;

#if(_FRC_SUPPORT == _ON)
        case _2_IVF:
            g_usDVFreq = 2 * g_stMDomainInputData.usVFreq;
            break;

        case _3_IVF:
            g_usDVFreq = 3 * g_stMDomainInputData.usVFreq;
            break;

        case _5_4_IVF:
            g_usDVFreq = 4 * g_stMDomainInputData.usVFreq / 5;
            break;

        case _6_5_IVF:
            g_usDVFreq = 5 * g_stMDomainInputData.usVFreq / 6;
            break;

        case _2_5_IVF:
            g_usDVFreq = 5 * g_stMDomainInputData.usVFreq / 2;
            break;

        case _PANEL_TYP_FRAME_RATE_FREE_RUN:
            g_usDVFreq = g_stDisplayCustomizedData.stDVCustomizedFreq.usTypFreq;
            break;
#endif
        default:
            g_usDVFreq = g_stMDomainInputData.usVFreq;
            break;
    }
}

