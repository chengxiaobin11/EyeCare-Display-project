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
// ID Code      : ScalerCommonTypeCPmicInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON) && (_TYPE_C_PMIC_TYPE != _PMIC_NONE))
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
extern bit ScalerTypeCPmicIICRead(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucReadArray);
#if(((_TYPE_C_PMIC_TYPE == _PMIC_RAA489800) && (_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)) || (_TYPE_C_PMIC_TYPE == _PMIC_SY8665) || (_TYPE_C_PMIC_TYPE == _PMIC_SY9228) || (_TYPE_C_PMIC_TYPE == _PMIC_SY9329))
extern BYTE ScalerTypeCPmicIICRead_EXINT0(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucReadArray);
#endif
extern bit ScalerTypeCPmicIICWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucWriteArray);
extern BYTE ScalerTypeCPmicIICWrite_EXINT0(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucWriteArray);
extern BYTE ScalerTypeCPmicIICWrite_WDINT(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucWriteArray);
#endif // End of #if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
extern EnumTypeCPmicOperationMode ScalerTypeCPmicRx0ReadPpsOperationModeStatus_EXINT0(void);
#endif // End of #if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
#endif // End of #if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON) && (_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON))
