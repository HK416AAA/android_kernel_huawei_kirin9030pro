/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of hcc adapter
 * Author: dpa drivers
 */

#ifndef HCC_ADAPTER_H
#define HCC_ADAPTER_H

#include <stdint.h>

void hcc_enable(void);
void hcc_disable(void);
void hcc_exception(void);
void hcc_rx_action_init(void);
int32_t hcc_dev_init(void);
void hcc_dev_deinit(void);
#endif