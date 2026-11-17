/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2021. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */
#include "hvgr_sc_api.h"

#include <linux/kernel.h>
#include <linux/slab.h>
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
#include <linux/hisi/mm_lb.h>
#else
#include <linux/mm_lb/mm_lb.h>
#endif

#include "hvgr_defs.h"
#include "hvgr_regmap.h"
#include "hvgr_ioctl_mem.h"
#include "hvgr_dm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_pm_api.h"

#define SC_PGID_NUM 64u
#define SC_VGID_NUM 256u

static uint32_t pgids[] = {PID_GPU_VERTEX, PID_GPU_DESC, PID_GPU_HEBC, PID_GPU_RSV0, PID_GPU_RSV1,
		PID_GPU_TXT, PID_GPU_FBO, PID_GPU_FBO_START, PID_GPU_FBO_START + 1,
		PID_GPU_FBO_START + 2, PID_GPU_FBO_START + 3, PID_GPU_FBO_START + 4,
		PID_GPU_FBO_START + 5, PID_GPU_FBO_START + 6, PID_GPU_FBO_START + 7,
		PID_GPU_FBO_START + 8, PID_GPU_FBO_START + 9, PID_GPU_FBO_START + 10,
		PID_GPU_FBO_START + 11, PID_GPU_FBO_START + 12, PID_GPU_FBO_START + 13,
		PID_GPU_FBO_START + 14, PID_GPU_FBO_END};

static uint32_t cgids[] = {4, 5, 7, 13, 14};

static uint32_t pool_ids[] = {
	0, 0, 0, 0, 4, 5, 0, 7, 0, 0, 0, 0, 0, 13, 14, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 14, 4, 14, 14,
	14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14};


int hvgr_sc_init_policy_list(struct hvgr_device * const gdev, struct list_head *head)
{
	uint32_t i;
	struct hvgr_sc_policy_info *info = NULL;

	for (i = 0; i < ARRAY_SIZE(pgids); i++) {
		info = kzalloc(sizeof(*info), GFP_KERNEL);
		if (info == NULL)
			goto failed;
		INIT_LIST_HEAD(&info->node);

		info->policy_id = pgids[i];
		hvgr_debug(gdev, HVGR_MEM, "sc policy_id %u", info->policy_id);

		list_add(&info->node, head);
	}

	return 0;
failed:
	hvgr_err(gdev, HVGR_MEM, "init policy list fail");
	return -EINVAL;
}

uint32_t hvgr_sc_id_to_policy_id(uint32_t idx)
{
	/* v300 only ptw gid come here, ptw vgid and pgid is same value */
	return idx;
}

uint32_t hvgr_get_policy_id(uint64_t attr)
{
	return (uint32_t)hvgr_mem_get_sc_pgid(attr);
}

static void hvgr_sc_update_hard_map_table(struct hvgr_device *gdev, uint32_t vgid, uint32_t pgid)
{
	uint32_t reg_addr;
	uint32_t reg_val;
	uint32_t v2p_offset;
	uint32_t v2p_pgid;
	struct hvgr_scs_resource *scs_reg = &gdev->dm_dev.scs_reg;

	if (scs_reg->reg_base == NULL)
		return;

	reg_addr = (vgid >> 2u) * sizeof(uint32_t); /* every reg has 4 v2p map */
	v2p_offset = (vgid & 0x3u) << 3u; /* every v2p uses 8 bit, so left shift 3 */

	reg_val = readl(scs_reg->reg_base + reg_addr);
	v2p_pgid = (reg_val >> v2p_offset) & 0x3Fu; /* every pgid uses 6 bit, so & 0x3F */

	if (v2p_pgid != pgid) {
		reg_val &= ~(0x3Fu << v2p_offset);
		reg_val |= (pgid << v2p_offset);
		writel(reg_val, (scs_reg->reg_base + reg_addr));
	}
}

static void hvgr_sc_update_soft_map_table(struct hvgr_device *gdev, uint32_t vgid, uint32_t pgid)
{
	uint32_t reg_addr;
	uint32_t reg_val;
	uint32_t v2p_offset;
	uint32_t v2p_pgid;

	reg_addr = (vgid >> 2u) * sizeof(uint32_t); /* every reg has 4 v2p map */
	v2p_offset = (vgid & 0x3u) << 3u; /* every v2p uses 8 bit, so left shift 3 */

	reg_val = gdev->mem_dev.sc_data.remap_regs[reg_addr >> 2u];
	v2p_pgid = (reg_val >> v2p_offset) & 0x3Fu; /* every pgid uses 6 bit, so & 0x3F */

	if (v2p_pgid != pgid) {
		reg_val &= ~(0x3Fu << v2p_offset);
		reg_val |= (pgid << v2p_offset);
		gdev->mem_dev.sc_data.remap_regs[reg_addr >> 2u] = reg_val;
	}
}

void hvgr_sc_update_map_table(uint64_t attr)
{
	uint32_t vgid = (uint32_t)hvgr_mem_get_sc_id(attr);
	uint32_t pgid = (uint32_t)hvgr_mem_get_sc_pgid(attr);

	struct hvgr_device *gdev = hvgr_get_device();
	struct hvgr_pm_pwr *pm_pwr = &gdev->pm_dev.pm_pwr;

	if (vgid == 0u || pgid == 0u || vgid >= SC_VGID_NUM || pgid >= SC_PGID_NUM)
		return;

	mutex_lock(&pm_pwr->power_lock);

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_POWER_OFF)
		hvgr_sc_update_soft_map_table(gdev, vgid, pgid);
	else
		hvgr_sc_update_hard_map_table(gdev, vgid, pgid);

	mutex_unlock(&pm_pwr->power_lock);
}

long hvgr_sc_set_gid_policy(uint32_t gid, uint32_t attr)
{
	uint32_t i;
	struct hvgr_device *gdev = hvgr_get_device();

	for (i = 0; i < ARRAY_SIZE(pgids); i++) {
		if (gid == pgids[i])
			break;
	}

	if (i == ARRAY_SIZE(pgids)) {
		hvgr_err(gdev, HVGR_MEM, "error gid %u", gid);
		return -1;
	}

	set_pgid_rd_policy(gid, hvgr_mem_get_sc_rd_policy(attr), false);
	set_pgid_wr_policy(gid, hvgr_mem_get_sc_wr_policy(attr), false);
	pgid_validate(gid);

	return 0;
}

void hvgr_sc_enable_gids(struct hvgr_device * const gdev)
{
	uint32_t i;
	int ret;

	for (i = 0; i < ARRAY_SIZE(pgids); i++) {
		ret = lb_gid_enable(pgids[i]);
		if (ret != 0)
			hvgr_err(gdev, HVGR_MEM, "sc enable gid_%u fail %d", pgids[i], ret);
		else
			hvgr_debug(gdev, HVGR_MEM, "sc enable gid_%u succ", pgids[i]);
	}
}

void hvgr_v_sc_set_page_osh(struct page *page, uint32_t osh)
{
	 lb_pages_set_osh(page, 1u, osh);
}

void hvgr_sc_flush_all_gids(void)
{
}

uint32_t hvgr_sc_id_to_pool_id(uint32_t idx)
{
	/* v300 and beyond only ptw gid come here, ptw vgid and pgid is same value */
	return hvgr_sc_id_to_policy_id(idx);
}

uint32_t hvgr_policy_id_to_pool_id(uint32_t policy_id)
{
	if (policy_id >= ARRAY_SIZE(pool_ids))
		return 0;

	return pool_ids[policy_id];
}

