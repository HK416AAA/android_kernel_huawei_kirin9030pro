/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: hipcie test code.
 *
 * This software is distributed under the terms of the GNU General
 * Public License ("GPL") as published by the Free Software Foundation,
 * either version 2 of that License or (at your option) any later version.
 */
#ifndef HI_PCIE_TEST_H
#define HI_PCIE_TEST_H

#include "../ctrl/hi_pcie_ctrl_common.h"
#include "../ctrl/hi_pcie_ctrl_regs.h"
#include "../hi_pcie_external_api.h"
#include "../hi_pcie_internal_api.h"
#include "../ctrl/hi_pcie_ctrl_dfx.h"

enum {
	HIPCIE_FAULT_INIT_TYPE_NONE = 0,
	HIPCIE_FAULT_INIT_TYPE_FNPLL_CFG,
	HIPCIE_FAULT_INIT_TYPE_PHY_INIT,
	HIPCIE_FAULT_INIT_TYPE_PERST,
	HIPCIE_FAULT_EXIT_TYPE_PERST,
	HIPCIE_FAULT_INIT_TYPE_PIPECLK,
	HIPCIE_FAULT_INIT_TYPE_TCU,
	HIPCIE_FAULT_EXIT_TYPE_TCU,
	HIPCIE_FAULT_INIT_TYPE_TBU,
	HIPCIE_FAULT_EXIT_TYPE_TBU,
	HIPCIE_FAULT_INIT_TYPE_LTSSM,
	HIPCIE_FAULT_TYPE_MAX,
};

int hi_pcie_dump_ltssm_trace(u32 cdx, u32 pdx, u32 reset);
int hi_pcie_dump_tlpm_trace(u32 cdx, u32 pdx);
int hi_pcie_dump_port_info(u32 cdx, u32 pdx, u32 type);
int hi_pcie_dump_ctrl_info(u32 cdx, u32 type);
int hi_pcie_show_link_state(u32 cdx, u32 pdx);
u32 hi_pcie_get_link_state(u32 cdx, u32 pdx);
int hi_pcie_enter_loopback(u32 cdx, u32 pdx, u32 type);
int hi_pcie_exit_loopback(u32 cdx, u32 pdx, u32 type);
u32 hi_pcie_read_local_config(u32 cdx, u32 pdx, u32 offset);
int hi_pcie_write_local_config(u32 cdx, u32 pdx, u32 offset, u32 val);
int hi_pcie_reset_port(u32 cdx, u32 pdx);
int hi_pcie_unreset_port(u32 cdx, u32 pdx);
int hi_pcie_change_speed(u32 cdx, u32 pdx, u32 speed);
int hi_pcie_change_lane(u32 cdx, u32 pdx, u32 lane);
int hi_pcie_enter_l2(u32 cdx, u32 pdx);
int hi_pcie_exit_l2(u32 cdx, u32 pdx);
int hi_pcie_init_atu(u32 cdx, u32 pdx);
u32 hi_pcie_read_remote_config(u32 cdx, u32 pdx, u32 offset);
int hi_pcie_write_remote_config(u32 cdx, u32 pdx, u32 offset, u32 val);
int hi_pcie_dma_transfer_test(u32 cdx, u32 pdx, u32 times);
int hi_pcie_cpu_transfer_test(u32 cdx, u32 pdx, u32 times);
int hi_pcie_init_transfer_buffer(u32 length, u64 remote_addr);
int hi_pcie_dma_test(u32 cdx, u32 pdx, u32 threads, u32 rounds, u32 length, u32 type);
int hi_pcie_find_local_capability(u32 cdx, u32 pdx, int capability, u32 ext);
int hi_pcie_find_remote_capability(u32 cdx, u32 pdx, int capability, u32 ext);
int hi_pcie_read_local_pcie_config(u32 cdx, u32 pdx, u32 pos);
int hi_pcie_wt_local_pcie_conf(u32 cdx, u32 pdx, u32 pos, u32 size, u32 val);
int hi_pcie_read_remote_pcie_config(u32 cdx, u32 pdx, u32 pos);
int hi_pcie_wt_remote_pcie_conf(u32 cdx, u32 pdx, u32 pos, u32 size, u32 val);
int hi_pcie_axi_timeout(u32 cdx, u32 pdx);
int hi_pcie_read_config_pressure(u32 cdx, u32 pdx, u32 times);
int hi_pcie_get_mps(u32 cdx, u32 pdx);
int hi_pcie_set_mps(u32 cdx, u32 pdx, int mps);
int hi_pcie_has_flr(u32 cdx, u32 pdx);
int hi_pcie_local_flr(u32 cdx, u32 pdx);
int hi_pcie_remote_flr(u32 cdx, u32 pdx);
int hi_pcie_shutdown(u32 cdx);
int hi_pcie_probe(u32 cdx);
int hi_pcie_cfg_ecam_atu(u32 cdx, u32 pdx);
int hi_pcie_change_mode(u32 cdx, u32 mode);
int hi_pcie_change_lpbk_type(u32 cdx, u32 type);
int loopback_shutdown(void *data);
int loopback_startup(void *data);
int stub_hi_pcie_fault_injection(u32 type);
#endif
