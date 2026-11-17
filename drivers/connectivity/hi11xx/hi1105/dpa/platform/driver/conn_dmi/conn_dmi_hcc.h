/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: 短距dmi hcc层对外接口
 * Author: dpa drivers
 */

#ifndef CONN_DMI_HCC_H
#define CONN_DMI_HCC_H

#include <stdint.h>

// dmi hcc消息初始化
int32_t dmi_hcc_transfer_init(void);
// dmi hcc消息去初始化
void dmi_hcc_transfer_deinit(void);

#endif // CONN_DMI_HCC_H