/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_dm_driver_base.h"

#include <linux/io.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <securec.h>

#include "hvgr_pm_api.h"
#include "hvgr_gpu_id.h"
#include "hvgr_regmap.h"
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_sch_api.h"
#include "hvgr_hts_api.h"
#include "hvgr_register_cfg.h"
#include "hvgr_fcp.h"
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#include "hvgr_mcu_common.h"
#endif
#if hvgr_fe_enabled(HVGR_FE_FFTS)
#include "hvgr_ffts_api.h"
#endif

#define THREAD_FEATURES_MAX_REGISTERS_MASK                0xFFFFF
#define THREAD_FEATURES_MAX_TASKQUEUE_MASK                0xFFF00000
#define GPU_VERSION_EU_NUMBER_MASK                        0XF


static char *hvgr_irq_name[] = {
	"JOB",
	"MMU",
	"GPU",
	"FCP",
	"CQ",
	"CC",
};

char *hvgr_get_irq_name(int i)
{
	return hvgr_irq_name[i];
}

uint32_t hvgr_get_chipid_reg(void)
{
	return COM_CONTROL_BASE;
}

void hvgr_get_info_from_reg(struct hvgr_device *gdev)
{
	struct hvgr_reg_info *reg_val = &gdev->dm_dev.dev_reg;

	reg_val->gpu_version = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPU_VERSION));
	reg_val->gpc_present = hvgr_read_reg(gdev, gpu_control_reg(gdev, GPC_PRESENT));
	reg_val->l2_features = hvgr_read_reg(gdev, gpu_control_reg(gdev, L2RW_FEATURES));
	reg_val->mmu_features = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_FEATURES));
	reg_val->thread_features = hvgr_read_reg(gdev, misc_control_reg(gdev, MAX_FEATURES));
	reg_val->gpc_cores = reg_val->gpc_present;
#if hvgr_version_ge(350)
	/*
	 * for v350, MAX_FEATURES.max_registers is per EU size.
	 * to make it uniform, we change this to per GPC size.
	 */
	reg_val->thread_features = (reg_val->thread_features & THREAD_FEATURES_MAX_TASKQUEUE_MASK) |
		((reg_val->thread_features & THREAD_FEATURES_MAX_REGISTERS_MASK) *
		(reg_val->gpu_version & GPU_VERSION_EU_NUMBER_MASK));
#endif
	reg_val->thread_max_workgroup_size =
		hvgr_read_reg(gdev, misc_control_reg(gdev, MAX_WORKGROUP_SIZE));
	if (gdev->pm_dev.pm_pwr.gpc_present_mask != 0)
		reg_val->gpc_present &= gdev->pm_dev.pm_pwr.gpc_present_mask;
	reg_val->rtu_present = gdev->pm_dev.pm_pwr.rtu_present;
}

#if hvgr_version_eq(350)
static void hvgr_dm_show_mmu_irq_status(struct hvgr_device *gdev)
{
	uint32_t irq_raw;

	irq_raw = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_RAWSTAT));
	if (irq_raw == 0U)
		return;

	hvgr_err(gdev, HVGR_DM, "mmu irq status err 0x%08x 0x%08x 0x%08x", irq_raw,
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK)),
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_RPT)));
}
#endif

void hvgr_disable_interrupts(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_MASK), 0);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_CLEAR), CC_IRQ_REG_ALL);

	hvgr_write_reg(gdev, misc_control_reg(gdev, GPU_IRQ_MASK), 0);
	hvgr_write_reg(gdev, misc_control_reg(gdev, GPU_IRQ_CLEAR), 0xFFFFFFFFU);

#if hvgr_version_eq(350)
	hvgr_dm_show_mmu_irq_status(gdev);
#endif
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), MMU_IRQ_MASK_DISABLE_ALL);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_CLEAR), 0xFFFFFFFFU);
	hvgr_sch_intr_switch(gdev, HVGR_SCH_INTRDISABLE);
	hvgr_hts_no_consumer_irq_disable(gdev);
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	hvgr_mcu_lowpa_irq_disable(gdev);
#endif
#if hvgr_version_ge(500)
	hvgr_mcu_lowva_irq_disable(gdev);
#endif
}

void hvgr_enable_interrupts(struct hvgr_device *gdev)
{
	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_CLEAR), CC_IRQ_REG_ALL);
	hvgr_write_reg(gdev, gpu_control_reg(gdev, CC_IRQ_MASK), CC_IRQ_REG_ALL);

	hvgr_write_reg(gdev, misc_control_reg(gdev, GPU_IRQ_CLEAR), 0xFFFFFFFFU);
	hvgr_write_reg(gdev, misc_control_reg(gdev, GPU_IRQ_MASK), GPU_IRQ_MASK_CONFIG);

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_CLEAR), 0xFFFFFFFFU);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_IRQ_MASK), MMU_IRQ_MASK_ENABLE_ALL);
	hvgr_sch_intr_switch(gdev, HVGR_SCH_INTRENABLE);

	hvgr_hts_no_consumer_irq_enable(gdev);
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
	hvgr_mcu_lowpa_irq_enable(gdev);
#endif
#if hvgr_version_ge(500)
	hvgr_mcu_lowva_irq_enable(gdev);
#endif
}

uint32_t hvgr_get_core_nums(struct hvgr_device *gdev)
{
	return hweight32(gdev->dm_dev.dev_reg.gpc_present);
}

uint32_t hvgr_get_cores(struct hvgr_device *gdev)
{
	return gdev->dm_dev.dev_reg.gpc_cores;
}

void hvgr_dm_get_core_mask_by_sid(struct hvgr_device *gdev, uint32_t sid, uint32_t *core_mask)
{
	uint32_t gpc_nums;

	if (unlikely(gdev == NULL || core_mask == NULL))
		return;

	*core_mask = 0U;
	gpc_nums = hweight32(gdev->dm_dev.dev_reg.gpc_cores);
	if ((sid >= HVGR_MMU_SID_START_OFFSET) &&
		(sid <= (HVGR_MMU_SID_START_OFFSET + gpc_nums - 1U)))
		*core_mask = 1U << (sid - HVGR_MMU_SID_START_OFFSET);
}

uint32_t hvgr_get_gpu_id(struct hvgr_device *gdev)
{
	return hvgr_read_reg(gdev, gpu_control_reg(gdev, hvgr_get_chipid_reg()));
}

uint32_t hvgr_read_reg(struct hvgr_device * const gdev, uint64_t addr)
{
	return readl((void *)addr);
}

void hvgr_write_reg(struct hvgr_device * const gdev, uint64_t addr, uint32_t value)
{
	writel(value, (void *)addr);
}

void hvgr_fast_pwr_write_reg(struct hvgr_device * const gdev, uint64_t addr, uint32_t value)
{
#if hvgr_version_ge(350)
	uint64_t offset;

	offset = addr - (uint64_t)(uintptr_t)((gdev)->dm_dev.dev_reg.reg_base[2]) + HVGR_REG_BASE2_LEN;
	if (hvgr_pm_fast_pwr_is_enable(gdev) && gdev->pm_dev.pm_pwr.entire_booting)
		hvgr_pm_fast_pwr_add_reg(gdev, (uint32_t)offset, value);
	else
		hvgr_write_reg(gdev, addr, value);
#else
	hvgr_write_reg(gdev, addr, value);
#endif
}

static void hvgr_set_control_baseaddr(struct hvgr_device * const gdev,
	struct hvgr_reg_base_cfg const * const cfg)
{
	gdev->dm_dev.reg_base.gpu_reg_base = cfg->reg_base.gpu_reg_base;
	gdev->dm_dev.reg_base.job_reg_base = cfg->reg_base.job_reg_base;
	gdev->dm_dev.reg_base.mmu_stage1_reg_base = cfg->reg_base.mmu_stage1_reg_base;
	gdev->dm_dev.reg_base.cq_reg_base = cfg->reg_base.cq_reg_base;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_base = cfg->reg_base.fcp_base.fcp_reg_base;
	gdev->dm_dev.reg_base.fcp_base.fcp_itcm_offset = cfg->reg_base.fcp_base.fcp_itcm_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_dtcm_offset = cfg->reg_base.fcp_base.fcp_dtcm_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_itcm_cq_offset =
		cfg->reg_base.fcp_base.fcp_itcm_cq_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_dtcm0_cq_offset =
		cfg->reg_base.fcp_base.fcp_dtcm0_cq_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_dtcm1_cq_offset =
		cfg->reg_base.fcp_base.fcp_dtcm1_cq_offset;

#if hvgr_version_ge(500)
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb0_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb0_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb1_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb1_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb2d_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb2d_offset;
#elif hvgr_version_eq(350)
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb0_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb0_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb1_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb1_offset;
#else
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_mb_offset =
		cfg->reg_base.fcp_base.fcp_reg_mb_offset;
#endif
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_dma_offset =
		cfg->reg_base.fcp_base.fcp_reg_dma_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_timer_offset =
		cfg->reg_base.fcp_base.fcp_reg_timer_offset;
	gdev->dm_dev.reg_base.fcp_base.fcp_reg_uart_offset =
		cfg->reg_base.fcp_base.fcp_reg_uart_offset;
}

int hvgr_init_control_baseaddr(struct hvgr_device * const gdev)
{
	struct hvgr_reg_info * const reg_info = &gdev->dm_dev.dev_reg;
	uint32_t idx;
	uint32_t gpu_id;

	if (reg_info->reg_base[0] == NULL ||
		reg_info->reg_base[1] == NULL ||
		reg_info->reg_base[2] == NULL) {
		hvgr_err(gdev, HVGR_DM, "%s reg_base is NULL.", __func__);
		return -1;
	}

	gdev->dm_dev.dev_reg.gpu_id = hvgr_get_gpu_id(gdev);
	gpu_id = HVGR_GET_GPU_DRV_VER(gdev->dm_dev.dev_reg.gpu_id);
	for (idx = 0; idx < ARRAY_SIZE(product_reg_cfg); idx++) {
		if (gpu_id == product_reg_cfg[idx].gpu_id) {
			hvgr_set_control_baseaddr(gdev, &product_reg_cfg[idx]);
			return 0;
		}
	}
	hvgr_err(gdev, HVGR_DM, "%s not match cfg.", __func__);
	return -1;
}

irqreturn_t hvgr_gpu_irq(int irq, void *data)
{
	struct hvgr_device *gdev = data;
	u32 val;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF) {
		hvgr_info(gdev, HVGR_DM, "gpu pm status 0x%x.", hvgr_pm_get_gpu_status(gdev));
		return IRQ_NONE;
	}

	val = hvgr_read_reg(gdev, misc_control_reg(gdev, GPU_IRQ_STATUS));
	hvgr_info(gdev, HVGR_DM, "GPU_IRQ_STATUS 0x%x.", val);
	if (val == 0)
		return IRQ_NONE;

	if (val & GPU_FAULT_SET)
		hvgr_gpu_fault_proc(gdev, val);

	hvgr_write_reg(gdev, misc_control_reg(gdev, GPU_IRQ_CLEAR), val);
	return IRQ_HANDLED;
}

uint64_t hvgr_dm_get_soc_timestamp(struct hvgr_device * const gdev)
{
	uint64_t soc_cnt = 0;
	uint32_t hi1, hi2;

	/* Read hi, lo, hi to ensure that overflow from lo to hi is handled correctly */
	do {
		hi1 = hvgr_read_reg(gdev, misc_control_reg(gdev, SYSCNT_HI));
		soc_cnt = hvgr_read_reg(gdev, misc_control_reg(gdev, SYSCNT_LO));
		hi2 = hvgr_read_reg(gdev, misc_control_reg(gdev, SYSCNT_HI));
		soc_cnt |= (((uint64_t)hi1) << 32);
	} while (hi1 != hi2);
	return soc_cnt;
}

bool hvgr_is_fpga(struct hvgr_device * const gdev)
{
	unsigned long gpu_version = gdev->dm_dev.dev_reg.gpu_version;

	/* bit5 is fpga flag. */
	return test_bit(5, &gpu_version);
}
#if hvgr_version_ge(600)
bool hvgr_dm_is_2mcu(struct hvgr_device * const gdev)
{
	uint32_t value;
	bool result = false;

	value = hvgr_read_reg(gdev, misc_control_reg(gdev, FCM_MCU_NUM));
	if (value == 2U)
		result = true;

	if (result)
		hvgr_debug(gdev, HVGR_DM, "%s val=%u boot 2mcu", __func__, value);
	else
		hvgr_debug(gdev, HVGR_DM, "%s val=%u boot 1mcu", __func__, value);
	return result;
}
#endif

#if hvgr_version_ge(500) && hvgr_version_lt(600)
bool hvgr_dm_is_2mcu(struct hvgr_device * const gdev)
{
	bool result = true;
	unsigned long gpu_version = gdev->dm_dev.dev_reg.gpu_version;

	if (hvgr_is_fpga(gdev)) {
		/* pcie */
		if (test_bit(6, &gpu_version) == 0) {
			/* rt: 1mcu */
			if (test_bit(7, &gpu_version) == 1)
				result = false;
		} else {
			/* normal: 1mcu */
			result = false;
		}
	}
	if (result)
		hvgr_debug(gdev, HVGR_DM, "%s boot 2mcu", __func__);
	else
		hvgr_debug(gdev, HVGR_DM, "%s boot 1mcu", __func__);
	return result;
}
#endif

bool hvgr_rt_is_enable(struct hvgr_device * const gdev)
{
	unsigned long gpu_version = gdev->dm_dev.dev_reg.gpu_version;

	/* bit7 is rt flag. */
	return test_bit(7, &gpu_version);
}

static bool hvgr_is_fake_hang(struct hvgr_device * const gdev)
{
	uint32_t index;
	bool is_idle = true;

	if (gdev->datan_dev.gpu_fault_msg.gpu_fault_id != DMD_JOB_HANG)
		return false;

	for (index = 0; index < CQ_CHANNEL_NUM; index++) {
		if (hvgr_read_reg(gdev, cq_control_reg(gdev, cq_bind_subchn_os(index))) != 0) {
			is_idle = false;
			break;
		}
	}

#if hvgr_fe_enabled(HVGR_FE_FFTS)
	is_idle = is_idle && hvgr_issueq_is_idle(gdev);
#endif

	return is_idle;
}

bool hvgr_is_report_dmd(struct hvgr_device * const gdev)
{
	if (hvgr_is_fake_hang(gdev)) {
		hvgr_debug(gdev, HVGR_DM, "Fake hang detected.");
		return false;
	}

	if (hvgr_is_fpga(gdev))
		return true;

	if (gdev->datan_dev.gpu_fault_msg.gpu_fault_id == DMD_ENTRY_TIMEOUT)
		return false;

	return true;
}

void hvgr_get_process_info(char *buffer, int len, struct hvgr_ctx *ctx)
{
	int ret = snprintf_s(buffer, len, len - 1, "pid:%d tgid:%d tsk_name:%s group_name:%s",
		(int)ctx->pid, (int)ctx->tgid, ctx->process_name, ctx->group_name);
	if (ret < 0)
		hvgr_err(ctx->gdev, HVGR_DM, "%s buffer len %d not enough", __func__, len);
}
