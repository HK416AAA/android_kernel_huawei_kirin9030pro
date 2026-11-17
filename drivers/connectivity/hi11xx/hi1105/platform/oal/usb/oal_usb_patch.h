/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:oal_usb_patch.c header file
 * Author: platform drivers
 */

#include "oal_usb_host_if.h"

#ifndef OAL_USB_PATCH_H
#define OAL_USB_PATCH_H

int32_t oal_usb_patch_write(hcc_bus *bus, uint8_t *buff, int32_t len, uint32_t file_flag);
int32_t oal_usb_patch_read(hcc_bus *bus, uint8_t *buff, int32_t len, uint32_t timeout, uint32_t file_flag);

#endif
