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
// ID Code      : ScalerPowerInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define POLLING_VCCK_OFF_STATUS(timeout)                {\
                                                            BYTE ucLocalTimeOut = (timeout);\
                                                            ScalerSetByte(_POLLING_VCCK_ADDR, _POLLING_VCCK_VALUE);\
                                                            while((ScalerGetByte(_POLLING_VCCK_ADDR) != _POLLING_VCCK_VALUE) && ((ucLocalTimeOut)-- != 0))\
                                                            {\
                                                                ScalerSetByte(_POLLING_VCCK_ADDR, _POLLING_VCCK_VALUE);\
                                                                ScalerTimerDelayXms(1);\
                                                            }\
                                                            ScalerTimerDelayXms(10);\
                                                        }

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

