/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:pcie_chip.h
 * Author: dpa drivers
 */

#ifndef PCIE_CHIP_H
#define PCIE_CHIP_H

#include "pcie_host.h"
#include "board_pm.h"

void oal_pcie_trigger_dfr(void);
int32_t oal_enable_pcie_irq(oal_pcie_res *pst_pci_lres);
int32_t oal_disable_pcie_irq(oal_pcie_res *pst_pci_lres);
int32_t oal_pcie_bus_init(powerup_res_sync_stru *powerup_res);
void oal_pcie_bus_deinit(void);
#endif
