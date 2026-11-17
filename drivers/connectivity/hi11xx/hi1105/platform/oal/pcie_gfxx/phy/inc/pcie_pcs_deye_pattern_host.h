/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:External Interfaces of the pciee phy electronic eye diagram
 * Author: platform drivers
 */

#ifndef PCIE_PCS_DEYE_PATTERN_HOST_H
#define PCIE_PCS_DEYE_PATTERN_HOST_H

#include "oal_types.h"
#include "pcie_pcs_regs.h"

#define PCIE_PCS_DEYE_PARTTERN_SIZE 8192

/* 开始PHY电子眼图测试 */
int32_t pcie_pcs_deye_pattern_host_test(uintptr_t base_addr, uint32_t lane, uint32_t dump_type);
#endif
