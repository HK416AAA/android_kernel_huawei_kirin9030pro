/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_MISC_CTRL_H
#define HVGR_REGMAP_MISC_CTRL_H

/* register address */
#define MISC_CONTROL_BASE       0x2000
#define misc_control_offset(r)  (MISC_CONTROL_BASE + (r))
#define GPU_IRQ_RAWSTAT         misc_control_offset(0x000)
#define GPU_IRQ_CLEAR           misc_control_offset(0x004)
#define GPU_IRQ_MASK            misc_control_offset(0x008)
#define GPU_IRQ_STATUS          misc_control_offset(0x00C)
#define GPU_FAULTSTATUS         misc_control_offset(0x010)
#define GPU_FAULTDATA0          misc_control_offset(0x014)
#define GPU_FAULTDATA1          misc_control_offset(0x018)
#define GPU_FAULTDATA2          misc_control_offset(0x01C)
#define GPU_FAULTDATA3          misc_control_offset(0x020)
#define FCM_SLOT_PRESENT        misc_control_offset(0x110)
#define MAX_WORKGROUP_SIZE      misc_control_offset(0x124)
#define MAX_FEATURES            misc_control_offset(0x12C)

#define GPU_COMMAND             misc_control_offset(0x160)
#define PWR_CMD_INFO0           misc_control_offset(0x164)
#define PWR_CMD_INFO1           misc_control_offset(0x168)
#define PWR_CMD_STATUS          misc_control_offset(0x16C)
#define PRFCNT_BASE_LO          misc_control_offset(0x170)
#define PRFCNT_BASE_HI          misc_control_offset(0x174)
#define PRFCNT_CONFIG           misc_control_offset(0x178)
#define PRFCNT_FCM_EN           misc_control_offset(0x17C)
#define PRFCNT_GPC_EN           misc_control_offset(0x180)
#define PRFCNT_BTC_EN           misc_control_offset(0x184)
#define PRFCNT_BVH_EN           misc_control_offset(0x188)
#define PRFCNT_MMU_L2_EN        misc_control_offset(0x18C)
#define SYSCNT_LO               misc_control_offset(0x1A8)
#define SYSCNT_HI               misc_control_offset(0x1AC)

#define FCM_CONFIG_0            misc_control_offset(0x200)
#define FCM_CONFIG_2            misc_control_offset(0x208)

#define GPC_PARA_NUM            misc_control_offset(0x210)

#define PMU_JOBS_JS0            misc_control_offset(0x220)
#define PMU_GPU_ACTIVE          misc_control_offset(0x22C)
#define PMU_JS0_ACTIVE          misc_control_offset(0x230)
#define PMU_JS1_ACTIVE          misc_control_offset(0x234)

/* CBIT REG */
/* (RW) Configuration of the L2 cache and MMU */
#define L2RO_CONFIG             misc_control_offset(0x400)
/* (RW) BTC core configuration settings */
#define BTC_CONFIG_0            misc_control_offset(0x420)
#define BTC_CONFIG_3            misc_control_offset(0x42C)
#define BTC_CONFIG_4            misc_control_offset(0x430)
#define BTC_CONFIG_7            misc_control_offset(0x43C)
/* (RW) BVH core configuration settings */
#define BVH_CONFIG_1            misc_control_offset(0x444)
/* (RW) RTU core configuration settings */
#define RTU_CONFIG_0            misc_control_offset(0x460)
/* (RW) GPC configuration settings */
#define GPC_CONFIG_0            misc_control_offset(0x480)
#define GPC_CONFIG_2            misc_control_offset(0x488)
#define GPC_CONFIG_3            misc_control_offset(0x48C)
#define GPC_CONFIG_4            misc_control_offset(0x490)
#define GPC_CONFIG_5            misc_control_offset(0x494)
#define GPC_CONFIG_6            misc_control_offset(0x498)
#define GPC_CONFIG_7            misc_control_offset(0x49C)
/* (RW) FF TU core configuration settings */
#define FF_CONFIG_0             misc_control_offset(0x4B0)
#define FF_CONFIG_6             misc_control_offset(0x4C8)
#define TU_CONFIG_0             misc_control_offset(0x4D0)
/* (RW) XBI configuration settings */
#define CCE_CBI_CBIT            misc_control_offset(0x4E0)

/* register vaulues */
/* GPU IRQ flags */
#define JOB_FAULT               ((u32)1 << 0)
#define CQ_FAULT                ((u32)1 << 1)
#define JMCP_FAULT              ((u32)1 << 2)
#define JMCP_CTRL_FAULT         ((u32)1 << 3)
#define MISC_CTRL_FAULT         ((u32)1 << 4)
#define CYCLECOUNT_DONE         ((u32)1 << 5)
#define PRFCNT_SAMPLE_COMPLETED ((u32)1 << 6)
#define CLEAN_CACHES_COMPLETED  ((u32)1 << 7)

#define GPU_FAULT               (JOB_FAULT | \
	CQ_FAULT | JMCP_FAULT | JMCP_CTRL_FAULT | MISC_CTRL_FAULT)

#define GPU_IRQ_MASK_CONFIG (JOB_FAULT | CQ_FAULT | JMCP_FAULT | JMCP_CTRL_FAULT | \
	MISC_CTRL_FAULT | CLEAN_CACHES_COMPLETED)

#define GPU_FAULT_SET (GPU_FAULT)
#define GPU_FAULT_REG_STRIDE 0x20

/* GPU_COMMAND values */
#define GPU_COMMAND_CYCLE_COUNT_START  0x01
#define GPU_COMMAND_CYCLE_COUNT_STOP   0x02
#define GPU_COMMAND_PRFCNT_CONFIG      0x03
#define GPU_COMMAND_PRFCNT_SAMPLE      0x05
#define GPU_COMMAND_CLEAN_CACHES       0x06

/* PRFCNT_CONFIG register values */
#define PRFCNT_CONFIG_MODE_SHIFT       0
#define PRFCNT_CONFIG_AS_SHIFT         4
#define PRFCNT_CONFIG_SETSELECT_SHIFT  8
#define PRFCNT_CONFIG_MAXSET_NUM       18
#define PRFCNT_CONFIG_MODE_MANUAL      1

/* CBIT REG */
/* CONFIG register values */
#define BTC_CFG4_TOP_MUX_SEL_2V                 ((u32)1 << 24)
#define GPC_CFG6_LSC_NONGPC_STORE_MASK_DISABLE  ((u32)1 << 5)
#define GPC_CFG6_LSC_PUSH_VTC_GTC_PROP          ((u32)7 << 15)
#define FCM_CFG0_CALL_EN                        ((u32)1 << 17)
#define RTU_CFG0_ASC_FORCE_TO_CACHE             ((u32)1 << 1)
#define TU_CFG0_HEBC_FAULT_HANG_EN              ((u32)1 << 5)

/* only v210/v211 effective */
#define GPC_CONFIG_0_ICG        0
#define GPC_CONFIG_2_ICG        0
#define GPC_CONFIG_5_ICG        0

/* cahce bypass bit */
#define FCM_CONFIG_0_CACHE_BYPASS     0xFF80U
#define BTC_CONFIG_3_CACHE_BYPASS     0xCU
#define BTC_CONFIG_7_CACHE_BYPASS     0x6U
#define BVH_CONFIG_1_CACHE_BYPASS     0x1U
#define GPC_CONFIG_0_CACHE_BYPASS     0x2800U
#define GPC_CONFIG_2_CACHE_BYPASS     0x20U
#define GPC_CONFIG_5_CACHE_BYPASS     0x800U
#define GPC_CONFIG_6_CACHE_BYPASS     0x10U
#define GPC_CONFIG_7_CACHE_BYPASS     0x200000U
#define TU_CONFIG_0_CACHE_BYPASS      0x1U
#define FF_CONFIG_0_CACHE_BYPASS      0xE000U
#define CCE_CBI_CBIT_CACHE_BYPASS     0x6U

#endif /* HVGR_REGMAP_MISC_CTRL_H */
