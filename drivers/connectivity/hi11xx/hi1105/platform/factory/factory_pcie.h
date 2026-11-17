/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description: factory_pcie.c header file
 * Author: platform drivers
 */

#ifndef FACTORY_PCIE_H
#define FACTORY_PCIE_H

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include <linux/types.h>
#endif

/* 其他头文件包含 */
int32_t pcie_chip_rc_slt_register(void);
int32_t pcie_chip_rc_slt_unregister(void);
int32_t factory_pcie_ip_test(int32_t test_count);

#endif
