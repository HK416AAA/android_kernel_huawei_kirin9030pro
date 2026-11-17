/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine dev ops
 * Create: 2024/04/18
 */
#ifndef __HICRYPTO_DEV_CONFIG_H__
#define __HICRYPTO_DEV_CONFIG_H__
#include "hicrypto_driver.h"

/**
 * @brief      : config gate clock on or off
 * @param[in]  : mid    module id
 * @param[in]  : ip_idx ip index
 * @param[in]  : onoff  ::SEC_ON is module clock on; other is off
 */
int engctrl_reg_gtclk_cfg(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff);

int drv_power_config(struct hicrypto_device *hdev, unsigned int mid, unsigned int ip_idx, unsigned int onoff);

void hisi_reg_cfg_init(struct hicrypto_device *hdev);

void hisi_reg_cfg_deinit(struct hicrypto_device *hdev);
#endif