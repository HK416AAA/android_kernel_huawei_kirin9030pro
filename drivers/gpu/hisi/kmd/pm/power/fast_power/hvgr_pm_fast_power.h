/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#ifndef HVGR_PM_FAST_POWER_H
#define HVGR_PM_FAST_POWER_H

struct hvgr_device;
struct hvgr_ctx;
struct hvgr_mem_area;

#define AUTO_GPC_TIMEOUT_DISABLE       0
#define AUTO_GPC_TIMEOUT_ENABLE        700 /* 1~2us */

struct hvgr_pm_firmware_load_data {
	uint32_t source_addr_l;
	uint32_t source_addr_h;
	uint32_t dst_addr;
	uint32_t size : 16;
	uint32_t mcu_idx : 1;
	uint32_t rsvd : 15;
};

struct hvgr_pm_reg_config_data {
	uint32_t config_addr;
	uint32_t config_data_mask;
	uint32_t config_data;
	uint32_t rsvd;
};

typedef enum {
	FAST_PWR_MCU_0 = 0,
	FAST_PWR_MCU_1,
	FAST_PWR_MCU_END,
} fast_pwr_mcu;

#define fast_pwr_regname(reg)                   FAST_PWR_REG_##reg

#define hvgr_fast_pwr_mcu_itcm_idx(x)           ((x) << 1)
#define hvgr_fast_pwr_mcu_dtcm_idx(x)           (((x) << 1) + 1)

/* fast pwr reg can not be FCM_CONFIG_3 or FCP_DMA_XXX_MASKINT */
typedef enum {
	fast_pwr_regname(CQ_BIND_CONFIG_0_0) = 0,
	fast_pwr_regname(CQ_BIND_CONFIG_0_1),
	fast_pwr_regname(CQ_BIND_CONFIG_0_2),
	fast_pwr_regname(CQ_BIND_CONFIG_0_3),
	fast_pwr_regname(CQ_BIND_CONFIG_0_4),
	fast_pwr_regname(CQ_BIND_CONFIG_1_0),
	fast_pwr_regname(CQ_BIND_CONFIG_1_1),
	fast_pwr_regname(CQ_BIND_CONFIG_1_2),
	fast_pwr_regname(CQ_BIND_CONFIG_1_3),
	fast_pwr_regname(CQ_BIND_CONFIG_1_4),
	fast_pwr_regname(CQ_BIND_CONFIG_2_0),
	fast_pwr_regname(CQ_BIND_CONFIG_2_1),
	fast_pwr_regname(CQ_BIND_CONFIG_2_2),
	fast_pwr_regname(CQ_BIND_CONFIG_2_3),
	fast_pwr_regname(CQ_BIND_CONFIG_2_4),
	fast_pwr_regname(CQ_BIND_CONFIG_3_0),
	fast_pwr_regname(CQ_BIND_CONFIG_3_1),
	fast_pwr_regname(CQ_BIND_CONFIG_3_2),
	fast_pwr_regname(CQ_BIND_CONFIG_3_3),
	fast_pwr_regname(CQ_BIND_CONFIG_3_4),
	fast_pwr_regname(CQ_BIND_WAITCYCLE_0),
	fast_pwr_regname(CQ_BIND_WAITCYCLE_1),
	fast_pwr_regname(CQ_BIND_WAITCYCLE_2),
	fast_pwr_regname(CQ_BIND_WAITCYCLE_3),
	fast_pwr_regname(CQ_BIND_ENTRY_EXE_EMPTY_TIMEOUT_0),
	fast_pwr_regname(CQ_BIND_ENTRY_EXE_EMPTY_TIMEOUT_1),
	fast_pwr_regname(CQ_BIND_ENTRY_EXE_EMPTY_TIMEOUT_2),
	fast_pwr_regname(CQ_BIND_ENTRY_EXE_EMPTY_TIMEOUT_3),
	fast_pwr_regname(CQ_BIND_WAIT_TIMEOUT_0),
	fast_pwr_regname(CQ_BIND_WAIT_TIMEOUT_1),
	fast_pwr_regname(CQ_BIND_WAIT_TIMEOUT_2),
	fast_pwr_regname(CQ_BIND_WAIT_TIMEOUT_3),
	fast_pwr_regname(CQ_DBG_EN),
	fast_pwr_regname(CQ_ENTRYS_WEIGHT),
	fast_pwr_regname(CQ_ENTRYS_REALTIME),
	fast_pwr_regname(CQ_SEM_WAIT_POLLING_MODE),
	fast_pwr_regname(CQ_ENTRYS_OS),
	fast_pwr_regname(CQ_BINNING_RAM_SIZE),
	fast_pwr_regname(CQ_RENDER_RAM_SIZE),
	fast_pwr_regname(CQ_COMPUTE_RAM_SIZE),
	fast_pwr_regname(CQ_BVH_RAM_SIZE),
	fast_pwr_regname(CQ_RT_RAM_SIZE),
	fast_pwr_regname(CQ_MAX_RMU_COUNT),
	fast_pwr_regname(CQ_MAX_RMU_SLICE_COUNT),
	fast_pwr_regname(CQ_MAX_VB_SHARP_COUNT),
	fast_pwr_regname(CQ_RENDER_NODE_STYPE),
	fast_pwr_regname(CQ_MESH_NODE_STYPE),
	fast_pwr_regname(CQ_INTERNAL_UNIFORM_SIZE),
	fast_pwr_regname(CQ_IRQ_CLEAR_0),
	fast_pwr_regname(CQ_IRQ_CLEAR_1),
	fast_pwr_regname(CQ_IRQ_CLEAR_2),
	fast_pwr_regname(CQ_IRQ_CLEAR_3),
	fast_pwr_regname(CQ_IRQ_MASK_0),
	fast_pwr_regname(CQ_IRQ_MASK_1),
	fast_pwr_regname(CQ_IRQ_MASK_2),
	fast_pwr_regname(CQ_IRQ_MASK_3),
	fast_pwr_regname(CQ_DFX_CONFIG),
	/* msic ctrl */
	fast_pwr_regname(CCE_CBI_CBIT),
	fast_pwr_regname(GPC_CONFIG_2),
	fast_pwr_regname(GPC_CONFIG_3),
	fast_pwr_regname(GPC_CONFIG_4),
	fast_pwr_regname(BTC_CONFIG_4_2),
	fast_pwr_regname(GPC_CONFIG_6),
	fast_pwr_regname(FCM_CONFIG_2),
	fast_pwr_regname(END),
} fast_pwr_reg;

struct hvgr_pm_fast_pwr_data {
	struct hvgr_mem_area *area;
	uint64_t gva;
	uint64_t firmware_kva;
	uint64_t reg_kva;
	uint32_t reg_idx;
	/* when fast_pwr_en on, gpc_auto_en can be off */
	bool fast_pwr_en;
	/* when gpc_auto_en on, fast_pwr_en must be on */
	bool gpc_auto_en;
	/*
	 * The purpose of adding tmp flag is that,
	 * to make the control flag only vailed, when next boot time.
	 */
	bool fast_pwr_en_tmp;
	bool gpc_auto_en_tmp;
};

int hvgr_pm_fast_pwr_malloc_buf(struct hvgr_device * const gdev);

void hvgr_pm_fast_pwr_release_buf(struct hvgr_device *gdev);

void hvgr_pm_fast_pwr_set_mcu_info(struct hvgr_device *gdev);

void hvgr_pm_fast_pwr_init(struct hvgr_device * const gdev);

/* all fast power func call below should be under mutex pm_pwr->power_lock */
/* fast power apis */
void hvgr_pm_fast_pwr_add_reg(struct hvgr_device * const gdev,
	uint32_t addr, uint32_t val);

void hvgr_pm_fast_pwr_request(struct hvgr_device * const gdev);

bool hvgr_pm_fast_pwr_is_enable(struct hvgr_device *gdev);

int32_t hvgr_pm_fast_pwr_on_and_wait_done(struct hvgr_device * const gdev);

void hvgr_pm_fast_pwr_off(struct hvgr_device * const gdev);

int32_t hvgr_pm_fast_pwr_wait_done(struct hvgr_device * const gdev, bool pwr_on);

void hvgr_pm_fast_pwr_update_cores(struct hvgr_device * const gdev, uint32_t desire_mask);

/* auto gpc apis */
void hvgr_pm_auto_gpc_switch(struct hvgr_device * const gdev, bool enable);

bool hvgr_pm_auto_gpc_is_enable(struct hvgr_device * const gdev);

int32_t hvgr_pm_auto_gpc_wait_pwr_on_done(struct hvgr_device * const gdev);

#endif
