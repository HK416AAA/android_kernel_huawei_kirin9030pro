/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2022-2022. All rights reserved.
 * This file is the dvfs implementation of the PM module.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <securec.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/barrier.h>
#include <linux/rcupdate.h>
#include <linux/statfs.h>
#include <linux/uaccess.h>

#include "hvgr_kmd_defs.h"
#include "hvgr_mem_opts.h"
#include "hvgr_log_api.h"
#include "hvgr_fcp.h"
#include "hvgr_dm_api.h"
#include "hvgr_pm_driver_base.h"
#include "hvgr_pm_power.h"
#include "hvgr_debugfs_api.h"
#include "hvgr_dm_ctx.h"
#include "hvgr_pm_api.h"
#include "hvgr_sch_api.h"
#include "hvgr_dm_comm_ctx.h"
#include "hvgr_mem_api.h"
#include "hvgr_pm_fast_power.h"

#define PWR_CMD_STATUE_ON_ING                   0x0
#define PWR_CMD_STATUE_ON_DONE                  0x1
#define PWR_CMD_STATUE_OFF_ING                  0x2
#define PWR_CMD_STATUE_OFF_DONE                 0x3
#define FAST_PWR_2MCU_FRIMWARE_NUM              0x4
#define FAST_PWR_1MCU_FRIMWARE_NUM              0x2

#if hvgr_version_ge(500)
/* Only one MCU For PCIE */
#define FAST_PWR_MCU_BOOT_EN_1_MCU                      (0x1 << 30)
#define FAST_PWR_FIRMWARE_LOAD_CNT_1_MCU                (0x2 << 25)
#define FAST_PWR_MCU_BOOT_EN_2_MCU                      (0x3 << 30)
#define FAST_PWR_FIRMWARE_LOAD_CNT_2_MCU                (0x4 << 25)
#else
#define FAST_PWR_MCU_BOOT_EN				(0x3 << 30)
#define FAST_PWR_FIRMWARE_LOAD_CNT			(0x4 << 25)
#endif
#define FAST_PWR_ON							(0x1 << 29)
#define FAST_PWR_OFF						(0x1 << 28)
#define fast_pwr_reg_cnt(x)					(((x) & 0xff) << 17)
#define FAST_PWR_CMD_START					((0x1 << 16) | 0x1 << 15)
#define fast_pwr_gpc_mask(x)				((x) << 7)
#define fast_pwr_data_addr_hi(x)			(((x) >> 32) & 0x7f)

#define fast_pwr_status_check_not_done(v, f)		(((v) & 0x7) != (f))
#define auto_gpc_status_check_not_on_ing(v, f)		(((v) & 0x7) != (f))

/* hw will add offset to dst_addr ref to mcu_id */
static void hvgr_pm_fast_pwr_tcm_set(struct hvgr_device * const gdev,
	struct hvgr_fcp_data *fcp_data, uint32_t mcu_id)
{
	const struct hvg_fcp_header *header = NULL;
	struct hvgr_pm_firmware_load_data *dst = NULL;
	uint64_t itcm_saddr;
	uint32_t itcm_size;
	uint64_t dtcm_saddr;
	uint32_t dtcm_size;
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	header = (const struct hvg_fcp_header *)fcp_data->kva;
	itcm_saddr = fcp_data->gva + (uint32_t)sizeof(*header);
	itcm_size = header->size_sub0;
	dtcm_saddr = itcm_saddr + itcm_size;
	dtcm_size = header->size_sub1;

	/* itcm */
	dst = (struct hvgr_pm_firmware_load_data *) u64_to_ptr(fast_pwr_data->firmware_kva +
		hvgr_fast_pwr_mcu_itcm_idx(mcu_id) * sizeof(struct hvgr_pm_firmware_load_data));
	dst->source_addr_l = itcm_saddr & 0xffffffffU;
	dst->source_addr_h = (itcm_saddr >> 32U) & 0xffffffffU;
	dst->dst_addr = FCP_ITCM0_START_ADDR;
	dst->size = itcm_size;
	dst->mcu_idx = mcu_id;

	/* dtcm */
	dst = (struct hvgr_pm_firmware_load_data *) u64_to_ptr(fast_pwr_data->firmware_kva +
		hvgr_fast_pwr_mcu_dtcm_idx(mcu_id) * sizeof(struct hvgr_pm_firmware_load_data));
	dst->source_addr_l = dtcm_saddr & 0xffffffffU;
	dst->source_addr_h = (dtcm_saddr >> 32U) & 0xffffffffU;
	dst->dst_addr = FCP_DTCM0_START_ADDR;
	dst->size = dtcm_size;
	dst->mcu_idx = mcu_id;
}

typedef bool (*hvgr_pm_fast_pwr_flag_check) (struct hvgr_device *gdev, bool enable);
typedef void (*hvgr_pm_fast_pwr_flag) (struct hvgr_device *gdev, bool enable);

int hvgr_pm_fast_pwr_malloc_buf(struct hvgr_device * const gdev)
{
	struct hvgr_mem_alloc_para para = {0};
	struct hvgr_mem_area *area = NULL;
	struct hvgr_pm_fast_pwr_data *fstpwr = &gdev->pm_dev.pm_pwr.fast_pwr_data;
	uint32_t buf_size;
	uint32_t firmware_size;

#if hvgr_version_ge(500)
	if (hvgr_dm_is_2mcu(gdev))
		firmware_size = sizeof(struct hvgr_pm_firmware_load_data) *
			FAST_PWR_2MCU_FRIMWARE_NUM;
	else
		firmware_size = sizeof(struct hvgr_pm_firmware_load_data) *
			FAST_PWR_1MCU_FRIMWARE_NUM;
#else
	firmware_size = sizeof(struct hvgr_pm_firmware_load_data) * FAST_PWR_2MCU_FRIMWARE_NUM;
#endif
	buf_size = firmware_size + sizeof(struct hvgr_pm_reg_config_data) * fast_pwr_regname(END);
	para.attribute = HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_KMD_ACCESS;
	para.pages = hvgr_page_nums(buf_size);
	para.max_pages = para.pages;
	para.va = COMMON_CTX_FAST_PWR_BUF_START;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_PM, "%s alloc area failed", __func__);
		return -1;
	}

	fstpwr->area = area;
	fstpwr->gva = area->gva;
	fstpwr->firmware_kva = area->kva;
	fstpwr->reg_kva = area->kva + firmware_size;

	hvgr_info(gdev, HVGR_PM, "%s alloc ok", __func__);

	return 0;
}

void hvgr_pm_fast_pwr_release_buf(struct hvgr_device *gdev)
{
	struct hvgr_pm_fast_pwr_data *fstpwr = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	if (fstpwr->area == NULL)
		return;

	hvgr_comm_ctx_free_area(gdev, fstpwr->area);
	fstpwr->area = NULL;
	fstpwr->gva = 0U;
	hvgr_info(gdev, HVGR_PM, "%s release ok", __func__);
}

void hvgr_pm_fast_pwr_set_mcu_info(struct hvgr_device *gdev)
{
	struct hvgr_fcp_data *fcp_data = gdev->dm_dev.fcp_data;

	if (fcp_data == NULL) {
		hvgr_err(gdev, HVGR_PM, "%s fcp_data is null", __func__);
		return;
	}

/* Only one MCU For PCIE */
#if hvgr_version_ge(500)
	hvgr_pm_fast_pwr_tcm_set(gdev, fcp_data, FAST_PWR_MCU_0);
	if (hvgr_dm_is_2mcu(gdev))
		hvgr_pm_fast_pwr_tcm_set(gdev, fcp_data, FAST_PWR_MCU_1);
#else
	hvgr_pm_fast_pwr_tcm_set(gdev, fcp_data, FAST_PWR_MCU_0);
	hvgr_pm_fast_pwr_tcm_set(gdev, fcp_data, FAST_PWR_MCU_1);
#endif

	hvgr_info(gdev, HVGR_PM, "%s set mcu info success.", __func__);
}

void hvgr_pm_fast_pwr_add_reg(struct hvgr_device * const gdev, uint32_t addr, uint32_t val)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;
	struct hvgr_pm_reg_config_data *reg = NULL;
	struct hvgr_pm_reg_config_data *reg_base = NULL;

	if (fast_pwr_data->reg_idx >= fast_pwr_regname(END)) {
		hvgr_err(gdev, HVGR_PM, "%s fast_pwr_data reg array is full", __func__);
		return;
	}
	reg_base = (struct hvgr_pm_reg_config_data *) u64_to_ptr(fast_pwr_data->reg_kva);
	reg = &reg_base[fast_pwr_data->reg_idx];
	reg->config_addr = addr;
	reg->config_data_mask = 0xffffffff;
	reg->config_data = val;
	fast_pwr_data->reg_idx++;
}

bool hvgr_pm_fast_pwr_is_enable(struct hvgr_device *gdev)
{
	return gdev->pm_dev.pm_pwr.fast_pwr_data.fast_pwr_en;
}

int32_t hvgr_pm_fast_pwr_wait_done(struct hvgr_device * const gdev, bool pwr_on)
{
	uint32_t timeout = HVGR_PM_CORE_TRANS_OUT_TIME;
	uint32_t i = 0;
	uint32_t val = 0;
	uint32_t flag = 0;

	if (pwr_on)
		flag = PWR_CMD_STATUE_ON_DONE;
	else
		flag = PWR_CMD_STATUE_OFF_DONE;

	do {
		val = hvgr_read_reg(gdev, misc_control_reg(gdev, PWR_CMD_STATUS));
		i++;
		udelay(1);
	} while ((i < timeout) && fast_pwr_status_check_not_done(val, flag));

	if (i == timeout) {
		hvgr_err(gdev, HVGR_PM, "%s time out, reg val is 0x%x", __func__, val);
		return -1;
	}

	hvgr_info(gdev, HVGR_PM, "%s success.", __func__);
	return 0;
}

int32_t hvgr_pm_auto_gpc_wait_pwr_on_done(struct hvgr_device * const gdev)
{
	uint32_t timeout = HVGR_PM_CORE_TRANS_OUT_TIME;
	uint32_t i = 0;
	uint32_t val = 0;
	uint32_t flag = PWR_CMD_STATUE_ON_ING;

	do {
		val = hvgr_read_reg(gdev, misc_control_reg(gdev, PWR_CMD_STATUS));
		if (auto_gpc_status_check_not_on_ing(val, flag))
			break;
		i++;
		udelay(1);
	} while (i < timeout);

	if (i == timeout) {
		hvgr_err(gdev, HVGR_PM, "%s time out, reg val is 0x%x", __func__, val);
		return -1;
	}

	hvgr_info(gdev, HVGR_PM, "%s success.", __func__);
	return 0;
}

int32_t hvgr_pm_fast_pwr_on(struct hvgr_device * const gdev, uint32_t desire_mask)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &pm_pwr->fast_pwr_data;
	uint32_t cores;
	uint32_t fcp_load_cnt = 0;
	uint32_t mcu_boot_num = 0;
	uint32_t reg_cnt = 0;
	uint32_t info1 = 0;

	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= desire_mask;

	if (!hvgr_fcp_is_load_needed(gdev)) {
		hvgr_info(gdev, HVGR_PM, "%s no need to load firmware", __func__);
		mcu_boot_num = 0;
		fcp_load_cnt = 0;
		reg_cnt = 0;
	} else {
#if hvgr_version_ge(500)
		if (hvgr_dm_is_2mcu(gdev)) {
			mcu_boot_num = FAST_PWR_MCU_BOOT_EN_2_MCU;
			fcp_load_cnt = FAST_PWR_FIRMWARE_LOAD_CNT_2_MCU;
		} else {
			mcu_boot_num = FAST_PWR_MCU_BOOT_EN_1_MCU;
			fcp_load_cnt = FAST_PWR_FIRMWARE_LOAD_CNT_1_MCU;
		}
#else
		mcu_boot_num = FAST_PWR_MCU_BOOT_EN;
		fcp_load_cnt = FAST_PWR_FIRMWARE_LOAD_CNT;
#endif
		reg_cnt = fast_pwr_data->reg_idx;
	}

#if hvgr_version_ge(600)
	hvgr_write_reg(gdev, misc_control_reg(gdev, PWR_DATA_ADDR_LO),
		fast_pwr_data->gva & 0xffffffff);
	hvgr_write_reg(gdev, misc_control_reg(gdev, PWR_DATA_ADDR_HI),
		fast_pwr_data_addr_hi(fast_pwr_data->gva));
	info1 = mcu_boot_num | FAST_PWR_ON | fcp_load_cnt |
		fast_pwr_reg_cnt(reg_cnt) | FAST_PWR_CMD_START |
		fast_pwr_gpc_mask(cores);
#else
	hvgr_write_reg(gdev, misc_control_reg(gdev, PWR_CMD_INFO0),
		fast_pwr_data->gva & 0xffffffff);

	info1 = mcu_boot_num | FAST_PWR_ON | fcp_load_cnt |
		fast_pwr_reg_cnt(reg_cnt) | FAST_PWR_CMD_START |
		fast_pwr_gpc_mask(cores) | fast_pwr_data_addr_hi(fast_pwr_data->gva);
#endif
	hvgr_info(gdev, HVGR_PM, "%s enter reg cnt %u, PWR_CMD_INFO1 is 0x%x",
		__func__, reg_cnt, info1);

	hvgr_write_reg(gdev, misc_control_reg(gdev, PWR_CMD_INFO1), info1);
	return 0;
}

int32_t hvgr_pm_fast_pwr_on_and_wait_done(struct hvgr_device * const gdev)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	if (hvgr_pm_fast_pwr_on(gdev, pm_pwr->core_mask_cur) != 0) {
		hvgr_err(gdev, HVGR_PM, "%s power on failed", __func__);
		return -1;
	}

	/*
	 * If auto gpc open, gpc will be power off by hw automatically.
	 * No need to read again.
	 */
	if (hvgr_pm_auto_gpc_is_enable(gdev))
		return hvgr_pm_auto_gpc_wait_pwr_on_done(gdev);

	return hvgr_pm_fast_pwr_wait_done(gdev, true);
}

void hvgr_pm_auto_gpc_switch(struct hvgr_device * const gdev, bool enable)
{
	if (enable) {
		hvgr_info(gdev, HVGR_PM, "%s enable %u", __func__, AUTO_GPC_TIMEOUT_ENABLE);
		hvgr_write_reg(gdev, cq_control_reg(gdev, GPC_PWR_TIMEOUT),
			AUTO_GPC_TIMEOUT_ENABLE);
	} else {
		hvgr_info(gdev, HVGR_PM, "%s disable %u", __func__, AUTO_GPC_TIMEOUT_DISABLE);
		hvgr_write_reg(gdev, cq_control_reg(gdev, GPC_PWR_TIMEOUT),
			AUTO_GPC_TIMEOUT_DISABLE);
	}
}

void hvgr_pm_fast_pwr_request(struct hvgr_device * const gdev)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;
	struct hvgr_pm_reg_config_data *reg = NULL;
	uint32_t reg_buf_size;

	fast_pwr_data->fast_pwr_en = fast_pwr_data->fast_pwr_en_tmp;
	fast_pwr_data->gpc_auto_en = fast_pwr_data->gpc_auto_en_tmp;

	hvgr_info(gdev, HVGR_PM, "%s enter %d, %d", __func__,
		fast_pwr_data->fast_pwr_en_tmp, fast_pwr_data->gpc_auto_en_tmp);

	if (!fast_pwr_data->fast_pwr_en)
		return;

	reg = (struct hvgr_pm_reg_config_data *) u64_to_ptr(fast_pwr_data->reg_kva);
	/* only reset reg info */
	reg_buf_size = sizeof(struct hvgr_pm_reg_config_data) * fast_pwr_regname(END);
	memset_s(reg, reg_buf_size, 0, reg_buf_size);
	fast_pwr_data->reg_idx = 0;
}

void hvgr_pm_fast_pwr_off(struct hvgr_device * const gdev)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;
	uint32_t cores;
	uint32_t reg_val = 0;

	if (!fast_pwr_data->fast_pwr_en)
		return;

	cores = pm_pwr->present_cores[HVGR_PM_CORE_GPC];
	cores &= pm_pwr->core_mask_cur;

	reg_val = FAST_PWR_OFF | FAST_PWR_CMD_START | fast_pwr_gpc_mask(cores);
	hvgr_info(gdev, HVGR_PM, "%s enter, PWR_CMD_INFO1 is 0x%x", __func__, reg_val);

	hvgr_write_reg(gdev, misc_control_reg(gdev, PWR_CMD_INFO1), reg_val);
}

bool hvgr_pm_auto_gpc_is_enable(struct hvgr_device * const gdev)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	if (!fast_pwr_data->fast_pwr_en)
		return false;
#if hvgr_version_lt(500)
	if (gdev->pm_dev.pm_pwr.tool_hwcnt)
		return false;
#endif
	if (hvgr_is_always_on(gdev))
		return false;

	return fast_pwr_data->gpc_auto_en;
}

void hvgr_pm_fast_pwr_update_cores(struct hvgr_device * const gdev, uint32_t desire_mask)
{
	(void)hvgr_pm_fast_pwr_on(gdev, desire_mask);
}

static bool hvgr_pm_fast_pwr_switch_check(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	return fast_pwr_data->fast_pwr_en_tmp != enable;
}

static void hvgr_pm_fast_pwr_switch_set_inner(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	fast_pwr_data->fast_pwr_en_tmp = enable;

	if (enable == false)
		fast_pwr_data->gpc_auto_en_tmp = enable;
}

static bool hvgr_pm_auto_gpc_switch_check(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	if (hvgr_is_always_on(gdev)) {
		hvgr_info(gdev, HVGR_PM, "always on enabled, auto gpc can not set");
		return false;
	}

	if (!fast_pwr_data->fast_pwr_en_tmp) {
		hvgr_info(gdev, HVGR_PM, "fast power not enabled, auto gpc can not set");
		return false;
	}

	return fast_pwr_data->gpc_auto_en_tmp != enable;
}

static void hvgr_pm_auto_gpc_switch_set(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_fast_pwr_data *fast_pwr_data = &gdev->pm_dev.pm_pwr.fast_pwr_data;

	fast_pwr_data->gpc_auto_en_tmp = enable;
}

ssize_t hvgr_pm_fast_pwr_switch_show(void *data, char * const buf)
{
	struct hvgr_device *gdev = (struct hvgr_device *)data;
	struct hvgr_pm_pwr *pm_pwr;
	bool enable1;
	bool enable2;

	pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_lock);
	enable1 = pm_pwr->fast_pwr_data.fast_pwr_en_tmp;
	enable2 = pm_pwr->fast_pwr_data.gpc_auto_en_tmp;
	mutex_unlock(&pm_pwr->power_lock);

	return (ssize_t)scnprintf(buf, PAGE_SIZE, "fast power : %s, auto gpc : %s\n",
		enable1 ? "enable" : "disable", enable2 ? "enable" : "disable");
}

static void hvgr_pm_fast_pwr_flag_set(struct hvgr_device *gdev, bool enable,
	hvgr_pm_fast_pwr_flag_check pcheck, hvgr_pm_fast_pwr_flag pfunc)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	mutex_lock(&pm_pwr->power_ctrl_lock);
	mutex_lock(&pm_pwr->power_lock);
	if (!pcheck(gdev, enable)) {
		hvgr_info(gdev, HVGR_PM, "%s no need set", __func__);
		goto out;
	}

	if (pm_pwr->cur_status == HVGR_PM_POWER_OFF) {
		hvgr_info(gdev, HVGR_PM, "%s power off direct set", __func__);
		pfunc(gdev, enable);
		goto out;
	}

	if (hvgr_is_always_on(gdev)) {
		hvgr_info(gdev, HVGR_PM, "%s always on policy direct set", __func__);
		pfunc(gdev, enable);
		goto out;
	}

	hvgr_info(gdev, HVGR_PM, "%s set flag %d", __func__, enable);
	pfunc(gdev, enable);
	mutex_unlock(&pm_pwr->power_lock);

	if (hvgr_pm_reboot_gpu(gdev) != 0)
		hvgr_err(gdev, HVGR_PM, "%s reboot timeout", __func__);

	mutex_unlock(&pm_pwr->power_ctrl_lock);
	return;

out:
	mutex_unlock(&pm_pwr->power_lock);
	mutex_unlock(&pm_pwr->power_ctrl_lock);
}

ssize_t hvgr_pm_fast_pwr_switch_set(void *data, char * const buf, size_t count)
{
	struct hvgr_device *gdev = (struct hvgr_device *)data;

	if (sysfs_streq("fast power enable", buf)) {
		hvgr_pm_fast_pwr_flag_set(gdev, true, hvgr_pm_fast_pwr_switch_check,
			hvgr_pm_fast_pwr_switch_set_inner);
		return (ssize_t)count;
	}

	if (sysfs_streq("fast power disable", buf)) {
		hvgr_pm_fast_pwr_flag_set(gdev, false, hvgr_pm_fast_pwr_switch_check,
			hvgr_pm_fast_pwr_switch_set_inner);
		return (ssize_t)count;
	}

	if (sysfs_streq("auto gpc enable", buf)) {
		hvgr_pm_fast_pwr_flag_set(gdev, true, hvgr_pm_auto_gpc_switch_check,
			hvgr_pm_auto_gpc_switch_set);
		return (ssize_t)count;
	}

	if (sysfs_streq("auto gpc disable", buf)) {
		hvgr_pm_fast_pwr_flag_set(gdev, false, hvgr_pm_auto_gpc_switch_check,
			hvgr_pm_auto_gpc_switch_set);
		return (ssize_t)count;
	}

	return -EINVAL;
}

hvgr_debugfs_read_write_declare(fops_pm_fast_pwr, hvgr_pm_fast_pwr_switch_show,
	hvgr_pm_fast_pwr_switch_set);

static void hvgr_pm_fast_pwr_dfx(struct hvgr_device *gdev)
{
	if (gdev->pm_dev.pm_dir == NULL)
		return;

}

#if hvgr_version_ge(500)
void hvgr_pm_hwcnt_en(struct hvgr_device *gdev, bool enable)
{
}
#else
static bool hvgr_pm_hwcnt_switch_check(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	return pm_pwr->tool_hwcnt_tmp != enable;
}

static void hvgr_pm_hwcnt_switch_set(struct hvgr_device *gdev, bool enable)
{
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	pm_pwr->tool_hwcnt_tmp = enable;
}

void hvgr_pm_hwcnt_en(struct hvgr_device *gdev, bool enable)
{
	hvgr_pm_fast_pwr_flag_set(gdev, enable, hvgr_pm_hwcnt_switch_check,
		hvgr_pm_hwcnt_switch_set);
}
#endif

void hvgr_pm_fast_pwr_init(struct hvgr_device * const gdev)
{
	gdev->pm_dev.pm_pwr.tool_hwcnt_tmp = false;
	gdev->pm_dev.pm_pwr.fast_pwr_data.fast_pwr_en_tmp = true;
	if (hvgr_is_always_on(gdev))
		gdev->pm_dev.pm_pwr.fast_pwr_data.gpc_auto_en_tmp = false;
	else
		gdev->pm_dev.pm_pwr.fast_pwr_data.gpc_auto_en_tmp = true;
	hvgr_pm_fast_pwr_dfx(gdev);
}
