/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_REGMAP_H
#define HVGR_REGMAP_H

#include <linux/types.h>

#include "hvgr_regmap_fcp.h"
#include "hvgr_regmap_cq.h"
#include "hvgr_regmap_misc_ctrl.h"

/* register address */
/* COM_CTRL */
#define COM_CONTROL_BASE        0x0

#define GPU_ID                  0x000
#define GPU_VERSION             0x004
#define L2RW_FEATURES           0x008
#define GPU_STATUS              0x010
#define GPU_PROT_MODE           0x014
#define CC_IRQ_CLEAR            0x01C
#define CC_IRQ_MASK             0x020
#define CC_IRQ_STATUS           0x024
#define GPC_PRESENT             0x400
#define BL_PRESENT              0x404
#define GPC_PWR_STATUS          0x408
#define BL_PWR_STATUS           0x40C
#define GPC_PWRON_CMD           0x410
#define BL_PWRON_CMD            0x414
#define GPC_PWROFF_CMD          0x418
#define BL_PWROFF_CMD           0x41C
#define SOFT_RESET_CMD          0x420

#define PWR_KEY                 0x600
#define PWR_CTRL0               0x604
#define PWR_CTRL1               0x608

#define GPU_DBG_CFG             0x810
#define GPU_DBG_STATUS          0x814
#define GPU_DBG_RDATA           0x818

/* FCM_JOB */
#define JOB_CONTROL_BASE        0x4000

#define FCM_SLOT_IRQ_STATUS     0x000

#define job_slot_x_reg(p, x, r) \
	((uint64_t)((p)->dm_dev.dev_reg.reg_base[2]) + JOB_CONTROL_BASE - HVGR_REG_BASE2_LEN + \
	((x) << 5) + (r))
#define JSX_IRQ_RAWSTAT         0x004
#define JSX_IRQ_MASK            0x008
#define JSX_IRQ_CLEAR           0x00C
#define JSX_IRQ_STATUS          0x010
#define JSX_STOP_COMMAND        0x014
#define JSX_STATUS              0x018

#define job_jc_y_reg(p, y, r) \
	((uint64_t)((p)->dm_dev.dev_reg.reg_base[2]) + JOB_CONTROL_BASE - HVGR_REG_BASE2_LEN + \
	((y) << 5) + ((y) << 4) + (r))
#define JSX_JCY_HEAD_LO         0x200
#define JSX_JCY_HEAD_HI         0x204
#define JSX_JCY_AFFINITY        0x208
#define JSX_JCY_CONFIG          0x20C
#define JSX_JCY_COMMAND         0x210
#define JSX_JCY_JCD_LO          0x214
#define JSX_JCY_JCD_HI          0x218
#define JSX_JCY_JD_MSB          0x21C
#define JSX_JCY_WAIT_CYCLE      0x220

#define JOB_RJD_OS_CONFIG         0xF00
#define JOB_RT_PARALLEL           0xF04
#define JOB_BC_PARALLEL           0xF08
#define JOB_R_CONTEXT_SWITCH_ACC  0xF0C

/* MMU */
#define MMU_BASE  0x1000

#define MMU_IDR0                0x00
#define MMU_CR0                 0x04
#define MMU_CR1                 0x08
#define MMU_IRQ_MASK            0x0c
#define MMU_IRQ_RAWSTAT         0x10
#define MMU_IRQ_RPT             0x14
#define MMU_IRQ_CLEAR           0x18
#define MMU_CMDQ_BASE_L         0x1c
#define MMU_CMDQ_BASE_H         0x20
#define MMU_CMDQ_PROD           0x24
#define MMU_CMDQ_CONS           0x28
#define MMU_EVENTQ_BASE_L       0x2C
#define MMU_EVENTQ_BASE_H       0x30
#define MMU_EVENTQ_PROD         0x34
#define MMU_EVENTQ_CONS         0x38
#define MMU_CD_BASE_L           0x3c
#define MMU_CD_BASE_H           0x40
#define MMU_CD_CFG              0x44

#define MMU_FEATURES            MMU_IDR0

/* FCP_2D */
#define FCP_2D_MB_REG_BASE 0x10000

/* register vaulues */
/* COM_CTRL */
/* GPU_STATUS values */
#define GPU_STATUS_CQ_ACTIVE               ((u32)1 << 2)

/* GPU_PROT_MODE values */
#define GPU_COMMAND_SET_PROTECTED_MODE 0x01

/* CC IRQ flags */
#define RESET_COMPLETED         ((u32)1 << 19)
#define CC_IRQ_REG_ALL          (RESET_COMPLETED)

/* SOFT_RESET_CMD values */
#define GPU_COMMAND_SOFT_RESET         0x01

/* Bits 11 of PWR_CTRL0 are bvh clk gate enable, so the power trans number value is 0x800. */
#define HVGR_PWR_TRANS_NUM_VALUE 0x800

#define HVGR_PWR_KEY_VALUE             0x2968a819
#define HVGR_ICG_CLK_ON                0x1000

/* FCM_JOB */
#define MAX_JOB_SLOT_NR              8
#define MAX_JOB_SLOT_CHAIN_NR        4

#define JS_JC_COMMAND_START        0x01
#define JS_JC_CONFIG_BARRIER                        (1u << 4)
#define JS_JC_CONFIG_END_FLUSH_L2_CLEAN_INVALIDATE  (3u << 8)
#define JS_JC_CONFIG_END_FLUSH_L1_CLEAN_INVALIDATE  (3u << 14)
#define JS_JC_CONFIG_END_FLUSH_BINNING              (1u << 10)
#define JS_JC_CONFIG_END_FLUSH_RENDERING            (1u << 11)
#define JS_JC_CONFIG_END_FLUSH_COMPUTE              (1u << 12)
#define JS_JC_CONFIG_END_FLUSH_RAYTRACING           (1u << 13)
#define JS_JC_CONFIG_END_FLUSH_NO_OPERATION         0u
#define JS_JC_CONFIG_END_FLUSH_ALL                  (0xFu << 10)

/* MMU */
/* MMU FAULT access type */
#define MMU_ACCESS_TYPE_ATOMIC               0
#define MMU_ACCESS_TYPE_EXECUTE              1
#define MMU_ACCESS_TYPE_READ                 2
#define MMU_ACCESS_TYPE_WRITE                3

/* MMU AXI protocol val */
/* PTW AxCACHE */
#define MMU_PTW_MEMATTR_NON_CACHEABLE               ((u32)0xCC)
#define MMU_PTW_MEMATTR_WRITE_BACK                  ((u32)0xC7)

/* PTW AxDOMAIN */
#define MMU_PTW_MEMATTR_OUT_SHAREABLE               ((u32)2)

/* AS<n>_MEMATTR values */
/* 7:RW allocate; 6:R allocate W not allocate; 5: R not allocate W allocate 0:RW not allocate */
#define AS_MEMATTR_AARCH64                    ((u64)0xFCECDCCCC7CCCCCC)

#define MMU_IRQ_CMD_SYNC_MASK           0x4U
#define MMU_IRQ_EVENTQ_ERR_MASK         0x2U
#define MMU_IRQ_CMDQ_ERR_MASK           0x1U

#define MMU_ADRMODE_4K                  0x0
#define MMU_ADRMODE_16K                 0x1
#define MMU_ADRMODE_64K                 0x2

/* others */
static inline bool hvgr_is_job_slot_support(void)
{
	return false;
}

#define HVGR_MMU_SID_START_OFFSET 0

#define HVGR_REG_BASE_SIZE 3
#define HVGR_REG_BASE1_LEN  0x1000
#define HVGR_REG_BASE2_LEN  0x2000
#define HVGR_REG_MMU_INDEX 1
#define HVGR_REG_COM_CTRL_INDEX 0

struct hvgr_wait_entry_info {
	uint32_t resv0 : 15;
	uint32_t hts_en : 1;
	uint32_t event_id : 10;
	uint32_t resv1 : 6;
	uint32_t resv2[4];
	uint32_t entry_id : 14;
	uint32_t resv3 : 18;
	uint32_t resv4[2];
};

#endif /* HVGR_REGMAP_H */
