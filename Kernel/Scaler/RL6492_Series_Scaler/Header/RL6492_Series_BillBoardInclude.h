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
// ID Code      : RL6492_Series_BillBoardInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _USB_EP0_DATA_BUF_SIZE                           0x40

#define _USB_31_SS_SUPPORT                               _OFF

#define _USB_HUB_SS_PID_H_                               0x04
#define _USB_HUB_SS_PID_L_                               0x00
#define _USB_HUB_HS_PID_H_                               0x54
#define _USB_HUB_HS_PID_L_                               0x00

#define _USB_FW_MAIN_VER_                                0x01
#define _USB_FW_SUB_VER_                                 0x06

#define _USB_DESC_SIZE_DEV                               0x12
#define _USB_DESC_SIZE_CONF                              0x09
#define _USB_DESC_SIZE_INTF                              0x09
#define _USB_DESC_SIZE_EP                                0x07
#define _USB_DESC_SIZE_EP_COMPANION                      0x06
#define _USB_DESC_SIZE_CPLS                              0x04
#define _USB_DESC_SIZE_BOS                               0x05
#define _USB_DESC_SIZE_USB2_EXTENSION                    0x07

#if(_USB_31_SS_SUPPORT == _ON)
#define _USB_DESC_SIZE_SUPERSPEED_USB                    0x0A
#define _USB_BOS_DEVICEACPS_NUM                          0x04
#define _USB_BB_CAP_LEN_OFFSEET_IN_BOS                   0x2A
#define _USB_BB_CAP_ALTMODE_NUM_OFFSET_IN_BOS            0x2E
#define _USB_BB_CAP_ALTMODE_STATUS_OFFSET_IN_BOS_1_4     0x32
#define _USB_BB_CAP_ALTMODE_STATUS_OFFSET_IN_BOS_5_8     0x33
#else
#define _USB_DESC_SIZE_SUPERSPEED_USB                    0x00
#define _USB_BOS_DEVICEACPS_NUM                          0x03
#define _USB_BB_CAP_LEN_OFFSEET_IN_BOS                   0x20 // 0x2A - 0x0A(_USB_DESC_SIZE_SUPERSPEED_USB)
#define _USB_BB_CAP_ALTMODE_NUM_OFFSET_IN_BOS            0x24 // 0x2e - 0x0A(_USB_DESC_SIZE_SUPERSPEED_USB)
#define _USB_BB_CAP_ALTMODE_STATUS_OFFSET_IN_BOS_1_4     0x28 // 0x32 - 0x0A(_USB_DESC_SIZE_SUPERSPEED_USB)
#define _USB_BB_CAP_ALTMODE_STATUS_OFFSET_IN_BOS_5_8     0x29 // 0x33 - 0x0A(_USB_DESC_SIZE_SUPERSPEED_USB)
#endif

#define _USB_DESC_SIZE_CONTAINER_ID                      0x14
#define _USB_DESC_SIZE_BILLBOARD_CAP                     0x2C
#define _USB_DESC_SIZE_ALTERNATE_MODE                    0x04
#define _USB_DESC_SIZE_BILLBOARD_ALTMODE_CAP             0x08

#define _USB_CTRL_XFER_NO_DATA                           0x00
#define _USB_CTRL_XFER_READ                              0x01
#define _USB_CTRL_XFER_WRITE_DATA_STAGE                  0x02
#define _USB_CTRL_XFER_WRITE_STATUS_STAGE                0x03

// Standard Request based on the USB 1.0 specification
#define _USB_REQUEST_GET_STATUS                          0x00
#define _USB_REQUEST_CLEAR_FEATURE                       0x01
#define _USB_REQUEST_SET_FEATURE                         0x03
#define _USB_REQUEST_SET_ADDRESS                         0x05
#define _USB_REQUEST_GET_DESCRIPTOR                      0x06
#define _USB_REQUEST_SET_DESCRIPTOR                      0x07
#define _USB_REQUEST_GET_CONFIGURATION                   0x08
#define _USB_REQUEST_SET_CONFIGURATION                   0x09
#define _USB_REQUEST_GET_INTERFACE                       0x0A
#define _USB_REQUEST_SET_INTERFACE                       0x0B
#define _USB_REQUEST_SYNC_FRAME                          0x0C
#define _USB_REQUEST_SET_SEL                             0x30
#define _USB_REQUEST_ISOCH_DELAY                         0x31

// Define the 8-bytes Data location of Setup Packet
#define _USB_REQUEST_TYPE_MASK                           0x60
#define _USB_STANDARD_REQUEST                            0x00
#define _USB_CLASS_REQUEST                               0x20
#define _USB_VENDOR_REQUEST                              0x40
#define _USB_REQUEST_RECIPIENT_MASK                      0x1F
#define _USB_REQUEST_RECIPIENT_DEVICE                    0x00
#define _USB_REQUEST_RECIPIENT_INTERFACE                 0x01
#define _USB_REQUEST_RECIPIENT_ENDPOINT                  0x02
#define _USB_REQUEST_RECIPIENT_PORT                      0x03

#define _USB_REQUESET_RECIPIENT_ENDPOINT_ZERO_IN         0x80
#define _USB_REQUESET_RECIPIENT_ENDPOINT_ZERO_OUT        0x00
#define _USB_REQUESET_RECIPIENT_ENDPOINT_ONE_IN          0x81

// standard feature selectors
#define _USB_ENDPOINT_HALT                               0x00   // endpoint
#define _USB_DEVICE_REMOTE_WAKEUP                        0x01   // device
#define _USB_TEST_STATE                                  0x02   // device

// HS_EP0_CTRL          --  0x9804
#define _USB_EP0_AUTO_TX_STATUS_HS                       0x10
#define _USB_EP0_REC_PKT_EN                              0x08
#define _USB_EP0_SEND_PKT_EN                             0x04
#define _USB_EP0_STALL                                   0x02
#define _USB_EP0_STATUS_HS_EN                            0x01

// HS_USP_STS           --  0x6404
#define _USB_HS_USP_SPEED                                0x01
#define _USB_HS_USP_SUSPEND                              0x02
#define _USB_HS_USP_RESUME                               0x04
#define _USB_HS_USP_CONFIG                               0x08

// HS_DEV_STATUS        --  0x6452
#define _USB_DEV_REMOTE_WAKEUP_EN                        0x01
#define _USB_DEV_EPB_STALL                               0x02
#define _USB_DEV_SELF_POWER                              0x04

// HS_USP_TEST          --  0x6453
#define _USB_TEST_J                                      0x01
#define _USB_TEST_K                                      0x02
#define _USB_TEST_PACKET                                 0x04
#define _USB_TEST_SE0_NAK                                0x08
#define _USB_TEST_MODE                                   0x10

// HS_DEV_ADDR          --  0x6454
#define _USB_DEV_ADDR_VALID                              0x80
#define _USB_DEV_ADDR_MASK                               0x7F

// Standard Descriptor Type (Table 9-5)
#define _USB_DEVICE_DESCRIPTOR_TYPE                      0x01
#define _USB_CONFIGURATION_DESCRIPTOR_TYPE               0x02
#define _USB_STRING_DESCRIPTOR_TYPE                      0x03
#define _USB_INTERFACE_DESCRIPTOR_TYPE                   0x04
#define _USB_ENDPOINT_DESCRIPTOR_TYPE                    0x05
#define _USB_INTERFACE_POWER_DESCRIPTOR_TYPE             0x08
#define _USB_OTG_DESCRIPTOR_TYPE                         0x09
#define _USB_DEBUG_DESCRIPTOR_TYPE                       0x0A
#define _USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE       0x0B
#define _USB_BOS_DESCRIPTOR_TYPE                         0x0F
#define _USB_DEVICE_CAPABILITY_DESCRIPTOR_TYPE           0x10
#define _USB_EP_COMPANION_DESCRIPTOR_TYPE                0x30


#define _USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE            0x06
#define _USB_OTHER_SPEED_CONFIGURATION_TYPE              0x07
#define _USB_POWER_DESCRIPTOR_TYPE                       0x08

// Device Capability Type defintion for BOS Descriptor
#define _USB_EXTENSION_TYPE                              0x02
#define _USB_SUPERSPEED_USB_TYPE                         0x03
#define _USB_CONTAINER_ID_TYPE                           0x04
#define _USB_BILLBOARD_TYPE                              0x0D
#define _USB_BILLBOARDALTERNATE_MODE_TYPE                0x0F

// string descriptor index
#define _USB_INDEX0                                      0x00

#define _USB_BB_INDEX0                                   0x10
#define _USB_BB_INDEX1                                   0x11
#define _USB_BB_INDEX2                                   0x12
#define _USB_BB_INDEX3                                   0x13

#define _USB_INDEX1                                      0x21
#define _USB_INDEX2                                      0x22
#define _USB_INDEX3                                      0x23
#define _USB_INDEX4                                      0x24
#define _USB_INDEX5                                      0x25

#define _USB_RT_HUB_STRING_INDEX0                        0x34   // "R"
#define _USB_RT_HUB_STRING_INDEX1                        0x36   // "T"

#define _TYPE_C_BILLBOARD_URL_INDEX_IADDTIONALINFO       0x40

// Device status
#define _USB_DEV_STATUS_BUS_POWERED                      0x00
#define _USB_DEV_STATUS_SELF_POWERED                     0x01
#define _USB_DEV_STATUS_REMOTE_WAKEUP                    0x02
#define _USB_DEV_STATUS_U1_EN                            0x04
#define _USB_DEV_STATUS_U2_EN                            0x08
#define _USB_DEV_STATUS_LTM_EN                           0x10


#define _USB_31_SS_BOS                                   _OFF
#define _USB_31_BILLBOARD_ALTMODE_BOS                    _ON

// Could Support (Dp AltMode + Lenovo AltMode) so far
#define _USB_MAX_ALTERNATE_MODE_NUM                      ((_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON) +\
                                                          (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
#define _USB_BB_BOS_DESC_FIRST_PART_LEN                  (_USB_DESC_SIZE_BOS + _USB_DESC_SIZE_USB2_EXTENSION + _USB_DESC_SIZE_SUPERSPEED_USB + _USB_DESC_SIZE_CONTAINER_ID + _USB_DESC_SIZE_BILLBOARD_CAP)
#define _USB_BB_BOS_DESC_TOTAL_LEN_INIT                  (_USB_BB_BOS_DESC_FIRST_PART_LEN + _USB_MAX_ALTERNATE_MODE_NUM * (_USB_DESC_SIZE_ALTERNATE_MODE + _USB_DESC_SIZE_BILLBOARD_ALTMODE_CAP))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//-----------------------     Device Descriptor      -----------------------//
typedef struct
{
    BYTE ucLength;                  // bLength
    BYTE ucDescriptorType;          // bDescriptorType (Device Desc 0x01)
    BYTE ucBcdUSB_Lo;               // bcdUSB LSB
    BYTE ucBcdUSB_Hi;               // bcdUSB MSB
    BYTE ucDeviceClass;             // bDeviceClass (0xFF = Vendor Specific)
    BYTE ucDeviceSubClass;          // bDeviceSubClass
    BYTE ucDeviceProtocol;          // bDeviceProtocol
    BYTE ucEP0MaxSize;              // bMaxPacketSize0
    BYTE ucVID_Lo;                  // VID LSB
    BYTE ucVID_Hi;                  // VID MSB
    BYTE ucPID_Lo;                  // PID LSB
    BYTE ucPID_Hi;                  // PID MSB
    BYTE ucFWSubVer;                // F/W sub  Version
    BYTE ucFWMainVer;               // F/W Main Version
    BYTE ucIdxManufactStr;          // iManufacturer - idx of Manf Str Desc.
    BYTE ucIdxProductStr;           // iProduct - idx of Prod String Descriptor
    BYTE ucIdxSerialNumStr;         // iSerialNumber - Idx of Serial Num String
    BYTE ucConfigurationNum;        // bNumConfigurations
} StructUsbDeviceDescriptor;

//--------------------     Configuration Descriptor     --------------------//
typedef struct
{
    BYTE ucLength;                   // bLength
    BYTE ucDescriptorType;           // bDescriptorType
    BYTE ucTotalLength_Lo;           // wTotalLength LSB
    BYTE ucTotalLength_Hi;           // wTotalLength MSB
    BYTE ucInterfaceNum;             // bNumInterfaces
    BYTE ucConfigurationVal;         // bConfigurationValue
    BYTE ucIdxConfigurationStr;      // iConfiguration
    BYTE ucAttribute;                // bmAttributes    default not support remote wakeup
    BYTE ucMaxPower;                 // MaxPower (x2 mA)
} StructUsbConfigDescriptor;

//--------------------     Interface Descriptor    -------------------------//
typedef struct
{
    BYTE ucLength;                  // bLength
    BYTE ucDescriptorType;          // bDescriptorType
    BYTE ucInterfaceNum;            // bInterfaceNumber
    BYTE ucAlternateSetting;        // bAlternateSetting
    BYTE ucEndpointNum;             // bNumEndpoints (num eps used w/o EP0)
    BYTE ucInterfaceClass;          // bInterfaceClass
    BYTE ucInterfaceSubClass;       // bInterfaceSubClass
    BYTE ucInterfaceProtocol;       // bInterfaceProtocol
    BYTE ucIdxInterfaceStr;         // ilInterface (Idx of this intf str desc.)
} StructUsbInterfaceDescriptor;

//-------------------     String Descriptor     ----------------------------//
typedef struct
{
    BYTE ucLength;                  // bLength
    BYTE ucDescriptorType;          // bDescriptorType
    BYTE ucLangID0_Lo;              // LangID[0] LSB
    BYTE ucLangID0_Hi;              // LangID[0] MSB
} StructUsbStringDescriptor;


typedef struct
{
    BYTE ucLength;                  // bLength
    BYTE ucDescriptorType;          // bDescriptorType
    BYTE ucDevCapabilityType;       // bDevCapabilityType
    BYTE ucIndex;                   // bIndex
    BYTE pucAltModeVdo[4];          // dwAlternateModeVdo
} StructUsbDevCapBBAltModeCapDescriptor;

typedef struct
{
    BYTE ucAltModeStauts;
    BYTE ucSVID_LO;
    BYTE ucSVID_HI;
    BYTE ucMode;
    BYTE ucStringIndex;
    BYTE ucdwAlternateModeVdo_Byte0;
    BYTE ucdwAlternateModeVdo_Byte1;
    BYTE ucdwAlternateModeVdo_Byte2;
    BYTE ucdwAlternateModeVdo_Byte3;
    BYTE ucCurAltModeActive;
} StructTypeCBillboardInfo;

//====================     USB Complete Descriptor     =====================//
typedef struct
{
    StructUsbConfigDescriptor       stUsbConfigureDescriptor;
    StructUsbInterfaceDescriptor    stUsbInterfaceDescriptor;
} StructUsbBBConfigDescriptor;
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

