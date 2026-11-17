/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_datan_ct.h"

#include <securec.h>
#include <linux/mm.h>
#include <linux/hrtimer.h>
#include <linux/jiffies.h>
#include <linux/kthread.h>
#include <linux/preempt.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/anon_inodes.h>

#include "hvgr_regmap.h"
#include "hvgr_kmd_defs.h"
#include "hvgr_dm_ctx.h"
#include "hvgr_pm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_asid_api.h"
#include "hvgr_cq_debug_switch.h"
#include "hvgr_ctx_sched.h"
#include "hvgr_dm_api.h"
#include "hvgr_datan_ct_time.h"
#include "hvgr_datan_ct_inner.h"
#include "hvgr_protect_mode.h"
#include "hvgr_dm_comm_ctx.h"
#include "hvgr_datan_api.h"

static const struct file_operations hvgr_ct_client_fops = {
	.poll = hvgr_ct_data_poll,
	.release = hvgr_ct_data_release,
	.unlocked_ioctl = hvgr_ct_data_ioctl,
	.compat_ioctl = hvgr_ct_data_ioctl,
};

static int hvgr_ct_enable_go_on_without_block(struct hvgr_device *gdev)
{
	struct hvgr_ct_context *ct_ctx = gdev->ct_dev.ct_ctx;
	struct hvgr_ctx *ctx = ct_ctx->ctx;
	struct hvgr_ct_setup setup;

	hvgr_info(gdev, HVGR_DATAN, "%s enter.", __func__);

	setup.dump_buffer = ct_ctx->gpu_va;
	setup.fcm_bm = ct_ctx->bitmap[CT_FCM_INDEX];
	setup.mmu_l2_bm = ct_ctx->bitmap[CT_MMU_INDEX];
	setup.btc_bm = ct_ctx->bitmap[CT_BTC_INDEX];
	setup.bvh_bm = ct_ctx->bitmap[CT_BVH_INDEX];
	setup.gpc_bm = ct_ctx->bitmap[CT_GPC_INDEX];
	setup.set_id = ct_ctx->set_id;

	return hvgr_datan_ct_enable_inner(gdev, ctx, &setup);
}

int hvgr_api_ct_enable_and_go_on(struct hvgr_device *gdev)
{
	int ret = 0;

	if (!gdev->datan_dev.datan_ct_dev.ct_config)
		return -ENOMEM;
	hvgr_info(gdev, HVGR_DATAN, "%s enter.", __func__);

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY &&
		(gdev->datan_dev.datan_ct_dev.ct_closed)) {
		ret = hvgr_ct_enable_go_on_without_block(gdev);
		if (ret != 0)
			return ret;
		gdev->datan_dev.datan_ct_dev.ct_closed = false;
	}
	return ret;
}

static int hvgr_ct_enable_logic(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_ctx *ctx = ct_ctx->ctx;
	struct hvgr_device *gdev = ctx->gdev;
	int ret = 0;

	hvgr_info(gdev, HVGR_DATAN, "%s enter.", __func__);

	mutex_lock(&gdev->pm_dev.pm_pwr.power_lock);
	gdev->datan_dev.datan_ct_dev.ct_config = true;
	ret = hvgr_api_ct_enable_and_go_on(gdev);
	if (ret != 0) {
		hvgr_err(ct_ctx->gdev, HVGR_DATAN, "%s error enter.", __func__);
		gdev->datan_dev.datan_ct_dev.ct_config = false;
	}
	mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);

	return ret;
}

static void hvgr_ct_disable_logic(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_ctx *ctx = ct_ctx->ctx;
	struct hvgr_device *gdev = ctx->gdev;
	int ret = 0;

	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);

	mutex_lock(&gdev->pm_dev.pm_pwr.power_lock);
	gdev->datan_dev.datan_ct_dev.ct_config = false;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY &&
		(!gdev->datan_dev.datan_ct_dev.ct_closed)) {
		hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s if enter.", __func__);
		ret = hvgr_datan_ct_disable_inner(ctx);
		if (ret != 0) {
			mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);
			return;
		}
		gdev->datan_dev.datan_ct_dev.ct_closed = true;
	}
	mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);
}

static int hvgr_ct_reset_logic(struct hvgr_ct_context *ct_ctx)
{
	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	hvgr_ct_disable_logic(ct_ctx);
	return hvgr_ct_enable_logic(ct_ctx);
}

static void hvgr_ct_set_bitmap(u32 dst[CT_MAX_COUNT], u32 dst_size,
	const u32 src[CT_MAX_COUNT], u32 src_size)
{
	datan_unused(dst_size);
	datan_unused(src_size);

	dst[CT_FCM_INDEX] = src[CT_FCM_INDEX];
	dst[CT_MMU_INDEX] = src[CT_MMU_INDEX];
	dst[CT_BTC_INDEX] = src[CT_BTC_INDEX];
	dst[CT_BVH_INDEX] = src[CT_BVH_INDEX];
	dst[CT_GPC_INDEX] = src[CT_GPC_INDEX];
}

static void hvgr_ct_union_bitmap(u32 dst[CT_MAX_COUNT], u32 dst_size,
	const u32 src[CT_MAX_COUNT], u32 src_size)
{
	datan_unused(dst_size);
	datan_unused(src_size);

	dst[CT_FCM_INDEX] |= src[CT_FCM_INDEX];
	dst[CT_MMU_INDEX] |= src[CT_MMU_INDEX];
	dst[CT_BTC_INDEX] |= src[CT_BTC_INDEX];
	dst[CT_BVH_INDEX] |= src[CT_BVH_INDEX];
	dst[CT_GPC_INDEX] |= src[CT_GPC_INDEX];
}

static uint32_t hvgr_ct_get_dump_size(void)
{
	uint32_t result;
	uint32_t core_nums;

	struct hvgr_device *gdev = hvgr_get_device();

	core_nums = hweight32(hvgr_get_cores(gdev));
	result = (core_nums + CT_OTHER_GROUP_NUMS) * GROUP_SIZE_BY_BYTES;
	return result;
}

uint32_t hvgr_api_ct_get_dump_size(void)
{
	return hvgr_ct_get_dump_size();
}

#if hvgr_version_ge(350)
static int hvgr_ct_map_kernel_dump_buffer(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_mem_alloc_para para = {0};
	uint32_t dump_size;
	uint64_t page_num;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_ctx *ctx = ct_ctx->ctx;
	struct hvgr_device *gdev = ctx->gdev;

	dump_size = hvgr_ct_get_dump_size();
	ct_ctx->dump_size = dump_size;
	page_num = (uint32_t)hvgr_page_nums(dump_size);

	para.attribute = HVGR_MEM_ATTR_GPU_WR | HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_KMD_ACCESS;
	/* one is global dump buffer, other is global accumulate buffer */
	para.pages = page_num + page_num;
	para.max_pages = para.pages;
	para.va = COMMON_CTX_PERF_BUF_START;
	para.property = HVGR_MEM_COMM_CTX_DEFAULT;
	area = hvgr_comm_ctx_alloc_area(gdev, &para);
	if (area == NULL) {
		hvgr_err(gdev, HVGR_DATAN, "%s alloc area failed", __func__);
		return -ENOMEM;
	}

	ct_ctx->area = area;
	ct_ctx->cpu_va = u64_to_ptr(area->kva);
	ct_ctx->gpu_va = area->gva;
	ct_ctx->accu_cpu_va = ct_ctx->cpu_va + page_num * HVGR_MEM_PAGE_SIZE;
	return 0;
}

static void hvgr_ct_unmap_kernel_dump_buffer(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_ctx *ctx = NULL;
	struct hvgr_device *gdev = NULL;

	if (ct_ctx == NULL)
		return;
	ctx = ct_ctx->ctx;
    if (ctx == NULL)
		return;
	gdev = ctx->gdev;
	if (gdev == NULL)
		return;

	if (ct_ctx->area != NULL)
		hvgr_comm_ctx_free_area(gdev, ct_ctx->area);

	ct_ctx->area = NULL;
	ct_ctx->cpu_va = NULL;
	ct_ctx->gpu_va = 0;
	ct_ctx->dump_size = 0;
}

#else

static int hvgr_ct_map_kernel_dump_buffer(struct hvgr_ct_context *ct_ctx)
{
	long ret;
	uint32_t dump_size;
	uint64_t page_num;
	struct hvgr_mem_area *area = NULL;
	struct hvgr_mmu_setup_paras mmu_para = {0};
	struct hvgr_ctx *ctx = ct_ctx->ctx;
	uint32_t level = 0;

	area = kzalloc(sizeof(*area), GFP_KERNEL);
	if (area == NULL)
		return -ENOMEM;

	dump_size = hvgr_ct_get_dump_size();

	ct_ctx->dump_size = dump_size;
	page_num = (uint32_t)hvgr_page_nums(dump_size);

	ctx->mem_ctx.zones[0].pmem = &ctx->mem_ctx;
	area->zone = &ctx->mem_ctx.zones[0];
	/* one is global dump buffer, other is global accumulate buffer */
	area->pages = page_num + page_num;;
	area->max_pages = area->pages;
	kref_init(&area->kref);

	if (hvgr_mem_alloc_pages(area) != 0) {
		kfree(area);
		return -ENOMEM;
	}
	area->attribute = HVGR_MEM_ATTR_GPU_WR | HVGR_MEM_ATTR_GPU_RD | HVGR_MEM_ATTR_KMD_ACCESS;

	if (!hvgr_mem_map_kva(area)) {
		(void)hvgr_mem_free_pages(area);
		kfree(area);
		return -ENOMEM;
	}

	area->gva = area->kva;
	hvgr_mem_attr2flag(area);

	mmu_para.gva = area->gva;
	mmu_para.page_array = area->page_array;
	mmu_para.pages = area->pages;
	mmu_para.mmu_flag = area->mmu_flag;
	mmu_para.flags = area->flags;

	ret = hvgr_mmu_set_up(ctx, &mmu_para, &level, area);
	if (ret != 0) {
		hvgr_mem_unmap_kva(area);
		(void)hvgr_mem_free_pages(area);
		kfree(area);
		return -ENOMEM;
	}

	ct_ctx->area = area;
	ct_ctx->cpu_va = u64_to_ptr(area->kva);
	ct_ctx->gpu_va = area->gva;
	ct_ctx->accu_cpu_va = ct_ctx->cpu_va + page_num * HVGR_MEM_PAGE_SIZE;
	return 0;
}

static void hvgr_ct_unmap_kernel_dump_buffer(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_mmu_takedown_paras paras;

	if (ct_ctx == NULL || ct_ctx->ctx == NULL)
		return;

	if (ct_ctx->area != NULL) {
		paras.va = ct_ctx->area->gva;
		paras.pages = ct_ctx->area->pages;
		paras.bitmap = 0U;
		INIT_LIST_HEAD(&paras.free_list);

		(void)hvgr_mmu_take_down(ct_ctx->ctx, &paras, ct_ctx->area);
		hvgr_mmu_free_pt_pages(ct_ctx->ctx, &paras.free_list);
		hvgr_mem_unmap_kva(ct_ctx->area);
		(void)hvgr_mem_free_pages(ct_ctx->area);
		kfree(ct_ctx->area);
	}

	ct_ctx->area = NULL;
	ct_ctx->cpu_va = NULL;
	ct_ctx->gpu_va = 0;
	ct_ctx->dump_size = 0;
}

#endif

static int hvgr_ct_create_ctx(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_device *gdev = ct_ctx->gdev;
	int ret = 0;

	hvgr_info(gdev, HVGR_DATAN, "%s enter.", __func__);

#if hvgr_version_lt(350)
	/* create ctx */
	ct_ctx->ctx = vmalloc(sizeof(*ct_ctx->ctx));
	if (ct_ctx->ctx == NULL) {
		hvgr_err(gdev, HVGR_DATAN, "ct_ctx->ctx create fail");
		return -ENOMEM;
	}
	(void)memset_s(ct_ctx->ctx, sizeof(*ct_ctx->ctx), 0, sizeof(*ct_ctx->ctx));
	ct_ctx->ctx->asid = ct_ctx->as_id;
	ct_ctx->ctx->gdev = gdev;
	ct_ctx->ctx->gdev->as_to_ctx[ct_ctx->as_id] = ct_ctx->ctx;
	if (hvgr_mem_init_proc(ct_ctx->ctx) != 0)
		goto failed_init_mem_proc;
#else
	ct_ctx->ctx = gdev->com_ctx.ctx;
	if (ct_ctx->ctx == NULL) {
		hvgr_err(gdev, HVGR_DATAN, "ct get common ctx create fail");
		return -ENOMEM;
	}
#endif

	ret = hvgr_ct_map_kernel_dump_buffer(ct_ctx);
	if (ret != 0)
		goto failed_map;

	ret = hvgr_ct_enable_logic(ct_ctx);
	if (ret != 0)
		goto failed_enable;

	ct_ctx->wq = alloc_workqueue("gpu-ct", WQ_HIGHPRI | WQ_UNBOUND, 1);
	if (ct_ctx->wq == NULL) {
		hvgr_err(gdev, HVGR_DATAN, "alloc workqueue gpu-ct fail.");
		goto failed_alloc_wq;
	}
	return 0;

failed_alloc_wq:
	hvgr_ct_disable_logic(ct_ctx);
failed_enable:
	hvgr_ct_unmap_kernel_dump_buffer(ct_ctx);
failed_map:
#if hvgr_version_lt(350)
	ct_ctx->ctx->gdev->as_to_ctx[ct_ctx->as_id] = NULL;
	hvgr_mem_term_proc(ct_ctx->ctx);
failed_init_mem_proc:
	vfree(ct_ctx->ctx);
#endif
	ct_ctx->ctx = NULL;
	hvgr_err(gdev, HVGR_DATAN, "%s failed.", __func__);
	return ret;
}

static void hvgr_ct_destroy_ct_ctx(struct hvgr_ct_context *ct_ctx)
{
	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	if (ct_ctx->wq != NULL) {
		destroy_workqueue(ct_ctx->wq);
	}
	ct_ctx->wq = NULL;
	hvgr_ct_disable_logic(ct_ctx);
	hvgr_ct_unmap_kernel_dump_buffer(ct_ctx);
#if hvgr_version_lt(350)
	ct_ctx->ctx->gdev->as_to_ctx[ct_ctx->as_id] = NULL;
	hvgr_mem_term_proc(ct_ctx->ctx);
	vfree(ct_ctx->ctx);
#endif
	ct_ctx->ctx = NULL;
}

static struct hvgr_ct_client *hvgr_ct_create_client(struct hvgr_ct_context *ct_ctx,
	struct hvgr_ctx *ctx, const struct hvgr_ct_cfg *ct_cfg, u32 ring_num)
{
	struct hvgr_ct_client *client = NULL;

	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	client = kzalloc(sizeof(*client), GFP_KERNEL);
	if (client == NULL)
		return NULL;

	client->ct_ctx = ct_ctx;
	client->ring_num = ring_num;
	client->is_config_valid = false;
	client->qwork_allow = true;

	hvgr_ct_set_bitmap(client->bitmap, ARRAY_SIZE(client->bitmap),
		ct_cfg->bitmap, ARRAY_SIZE(ct_cfg->bitmap));
	client->set_id = ct_cfg->set_id;
	client->ctx = ctx;
	spin_lock_init(&client->timer_lock);
	spin_lock_init(&client->qwork_lock);
	spin_lock_init(&client->flag_lock);

	return client;
}

static struct hvgr_mem_area *hvgr_ct_mem_allocate(struct hvgr_ctx *ctx,
	uint64_t attribute, uint64_t bytes)
{
	struct hvgr_mem_alloc_para para = {0};

	para.property = HVGR_MEM_PROPERTY_DRIVER;
	para.attribute = attribute;
	para.pages = (uint32_t)hvgr_page_nums(bytes);
	para.max_pages = para.pages;

	return hvgr_mem_allocate(ctx, &para, NULL, false);
}

static int hvgr_ct_ring_buffer_allocate(struct hvgr_ct_client *client, uint64_t *ctrl_addr)
{
	struct hvgr_mem_area *kmd_ctrl_area = NULL;
	struct hvgr_mem_area *user_ctrl_area = NULL;
	struct hvgr_mem_area *data_ctrl_area = NULL;
	struct hvgr_ctx *ctx = NULL;
	uint32_t data_size;
	uint32_t single_size;

	data_size = client->dump_size;
	single_size = data_size + HVGR_CT_QUEUE_DATA_CTRL_HEAD_SIZE;
	ctx = client->ctx;
	/* 1. alloc raw data ctrl mem. */
	data_ctrl_area = hvgr_ct_mem_allocate(ctx,
		HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR | HVGR_MEM_ATTR_KMD_ACCESS,
		client->ring_num * single_size);
	if (data_ctrl_area == NULL)
		return -1;

	/* 2. alloc read index mem. */
	user_ctrl_area = hvgr_ct_mem_allocate(ctx,
		HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_CPU_WR | HVGR_MEM_ATTR_KMD_ACCESS,
		sizeof(struct hvgr_ct_queue_user_ctrl));
	if (user_ctrl_area == NULL) {
		hvgr_mem_free_kernel_area(ctx, data_ctrl_area);
		return -1;
	}

	/* 3. alloc kmd ctrl mem. */
	kmd_ctrl_area = hvgr_ct_mem_allocate(ctx,
		HVGR_MEM_ATTR_CPU_RD | HVGR_MEM_ATTR_KMD_ACCESS, sizeof(struct hvgr_ct_queue_ctrl));
	if (kmd_ctrl_area == NULL) {
		hvgr_mem_free_kernel_area(ctx, user_ctrl_area);
		hvgr_mem_free_kernel_area(ctx, data_ctrl_area);
		return -1;
	}

	client->data_ctrl_area = data_ctrl_area;
	client->data_ctrl = (struct hvgr_ct_queue_data_ctrl *)u64_to_ptr(data_ctrl_area->kva);

	client->user_ctrl_area = user_ctrl_area;
	client->user_ctrl = (struct hvgr_ct_queue_user_ctrl *)u64_to_ptr(user_ctrl_area->kva);
	client->user_ctrl->rd = 0;

	client->kmd_ctrl_area = kmd_ctrl_area;
	client->kmd_ctrl = (struct hvgr_ct_queue_ctrl *)u64_to_ptr(kmd_ctrl_area->kva);
	client->kmd_ctrl->wr = 0;
	client->kmd_ctrl->user_ctrl_addr = user_ctrl_area->gva;
	client->kmd_ctrl->ct_raw_base = data_ctrl_area->gva;

	/* 4.Transport to the up user. */
	*ctrl_addr = kmd_ctrl_area->gva;
	return 0;
}

static int hvgr_ct_init_client_buffer(struct hvgr_ct_context *ct_ctx,
	struct hvgr_ct_client *client, void *argp, uint64_t *ctrl_addr)
{
	int ret;

	client->dump_size = ct_ctx->dump_size;
	client->old_buffer = kzalloc(client->dump_size, GFP_KERNEL);
	if (client->old_buffer == NULL)
		return -EINVAL;
	client->new_buffer = kzalloc(client->dump_size, GFP_KERNEL);
	if (client->new_buffer == NULL)
		goto fail_alloc_buffer;

	ret = memcpy_s(client->old_buffer, client->dump_size, ct_ctx->accu_cpu_va, client->dump_size);
	if (ret != 0)
		goto fail_init_client_buffer;
	ret = memset_s(client->new_buffer, client->dump_size, 0, client->dump_size);
	if (ret != 0)
		goto fail_init_client_buffer;

	if (client->ring_num > 0 && ctrl_addr != NULL) {
		int *fd = (int *)argp;

		if (hvgr_ct_ring_buffer_allocate(client, ctrl_addr) != 0)
			goto fail_init_client_buffer;

		kref_get(&client->ctx->ctx_kref);
		*fd = anon_inode_getfd("[hvgr_ct_desc]",
			&hvgr_ct_client_fops, client, O_RDONLY | O_CLOEXEC);
		if (*fd < 0) {
			kref_put(&client->ctx->ctx_kref, hvgr_ctx_kref_release);
			goto fail_init_client_buffer;
		}
	} else {
		client->legacy_buffer = (void __user *)argp;
	}

	init_waitqueue_head(&client->waitq);
	return 0;

fail_init_client_buffer:
	kfree(client->new_buffer);
fail_alloc_buffer:
	kfree(client->old_buffer);

	return -EINVAL;
}

static struct hvgr_ct_client *hvgr_ct_attach_client(struct hvgr_ct_context *ct_ctx,
	struct hvgr_ctx *ctx, const struct hvgr_ct_cfg *ct_cfg, void *argp, uint64_t *ctrl_addr)
{
	struct hvgr_ct_client *client = NULL;
	u32 ring_num = ct_cfg->ring_num;

	if (ring_num > RING_BUFFER_MAX_SIZE) {
		hvgr_err(ct_ctx->gdev, HVGR_DATAN, "ring_num=%u", ring_num);
		return NULL;
	}

	client = hvgr_ct_create_client(ct_ctx, ctx, ct_cfg, ring_num);
	if (client == NULL) {
		hvgr_err(ct_ctx->gdev, HVGR_DATAN, "client is null");
		return NULL;
	}

	mutex_lock(&ct_ctx->lock);

#if hvgr_version_eq(350)
	if (ct_ctx->client_num == 0) {
		hvgr_pm_hwcnt_en(ctx->gdev, true);
		hvgr_info(ct_ctx->gdev, HVGR_DATAN, "enable hwcnt");
	}
#endif

	if (ctrl_addr != NULL) {
		if (atomic_read(&ct_ctx->pm_ref_cnt) == 0)
			(void)hvgr_pm_request_gpu(ctx->gdev, false);

		atomic_inc(&ct_ctx->pm_ref_cnt);
	}

	hvgr_ct_union_bitmap(ct_ctx->bitmap, ARRAY_SIZE(ct_ctx->bitmap),
		client->bitmap, ARRAY_SIZE(client->bitmap));
	ct_ctx->set_id = client->set_id;
	ct_ctx->is_need_update_config = true;

	if (ct_ctx->client_num == 0) {
		hvgr_ct_set_bitmap(ct_ctx->bitmap, ARRAY_SIZE(ct_ctx->bitmap),
			client->bitmap, ARRAY_SIZE(client->bitmap));
		if (hvgr_ct_create_ctx(ct_ctx) < 0) {
			hvgr_err(ct_ctx->gdev, HVGR_DATAN, "hvgr_ct_create_ctx fail");
			goto error;
		}
		ct_ctx->is_need_update_config = false;
		client->is_config_valid = true;
	}
	ct_ctx->client_num++;
	list_add(&client->list, &ct_ctx->work_clients);

	if (hvgr_ct_init_client_buffer(ct_ctx, client, argp, ctrl_addr) != 0) {
		hvgr_err(ct_ctx->gdev, HVGR_DATAN, "hvgr_ct_init_client_buffer fail");
		goto error_init_client;
	}
	mutex_unlock(&ct_ctx->lock);

	return client;

error_init_client:
	ct_ctx->client_num--;
	list_del(&client->list);

error:
	if (ctrl_addr != NULL) {
		if (atomic_dec_and_test(&ct_ctx->pm_ref_cnt))
			hvgr_pm_release_gpu(ct_ctx->gdev);
	}

	if (ct_ctx->client_num == 0) {
#if hvgr_version_eq(350)
		hvgr_pm_hwcnt_en(ctx->gdev, false);
#endif
		if (ct_ctx->ctx != NULL)
			hvgr_ct_destroy_ct_ctx(ct_ctx);
	}
	kfree(client);
	mutex_unlock(&ct_ctx->lock);
	return NULL;
}

static void hvgr_ct_rebuild_ctx_bitmap(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_ct_client *iter = NULL;
	u32 zerobitmap[CT_MAX_COUNT] = {0};

	hvgr_ct_set_bitmap(ct_ctx->bitmap, ARRAY_SIZE(ct_ctx->bitmap),
		zerobitmap, ARRAY_SIZE(zerobitmap));
	list_for_each_entry(iter, &ct_ctx->work_clients, list)
		hvgr_ct_union_bitmap(ct_ctx->bitmap, ARRAY_SIZE(ct_ctx->bitmap),
			iter->bitmap, ARRAY_SIZE(iter->bitmap));
}

void hvgr_ct_detach_client(struct hvgr_ct_client *client)
{
	struct hvgr_ct_context *ct_ctx = NULL;
	struct hvgr_ct_client *iter = NULL;
	struct hvgr_ct_client *tmp = NULL;
	int cli_found = 0;
	unsigned long flags;

	ct_ctx = client->ct_ctx;

	spin_lock_irqsave(&client->qwork_lock, flags);
	client->qwork_allow = false;
	spin_unlock_irqrestore(&client->qwork_lock, flags);
	flush_workqueue(ct_ctx->wq);

	mutex_lock(&ct_ctx->lock);

	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);

	list_for_each_entry_safe(iter, tmp, &ct_ctx->work_clients, list) {
		if (iter == client) {
			ct_ctx->is_need_update_config = true;
			cli_found = 1;
			list_del(&iter->list);
			break;
		}
	}
	if (cli_found == 1 && client->ring_num > 0)
		hvgr_ct_start_cycle_client_timer(client);

	if (client->data_ctrl_area != NULL && client->ctx != NULL) {
		if (atomic_dec_and_test(&ct_ctx->pm_ref_cnt)) {
			hvgr_pm_release_gpu(ct_ctx->gdev);
		}

		hvgr_mem_free_kernel_area(client->ctx, client->data_ctrl_area);
		client->data_ctrl_area = NULL;
		client->data_ctrl = NULL;
	}

	if (client->user_ctrl_area != NULL && client->ctx != NULL) {
		hvgr_mem_free_kernel_area(client->ctx, client->user_ctrl_area);
		client->user_ctrl_area = NULL;
		client->user_ctrl = NULL;
	}

	if (client->kmd_ctrl_area != NULL && client->ctx != NULL) {
		hvgr_mem_free_kernel_area(client->ctx, client->kmd_ctrl_area);
		client->kmd_ctrl_area = NULL;
		client->kmd_ctrl = NULL;
	}

	if (client->old_buffer != NULL) {
		kfree(client->old_buffer);
		client->old_buffer = NULL;
	}

	if (client->new_buffer != NULL) {
		kfree(client->new_buffer);
		client->new_buffer = NULL;
	}

	kfree(client);

	ct_ctx->client_num--;
	if (ct_ctx->client_num == 0) {
#if hvgr_version_eq(350)
		hvgr_pm_hwcnt_en(ct_ctx->gdev, false);
		hvgr_info(ct_ctx->gdev, HVGR_DATAN, "disable hwcnt");
#endif
		hvgr_ct_destroy_ct_ctx(ct_ctx);
	}

	hvgr_ct_rebuild_ctx_bitmap(ct_ctx);

	mutex_unlock(&ct_ctx->lock);
}

static void hvgr_ct_accum_dump_buffer(void *dst, const void *src, size_t src_size, size_t dst_size)
{
	u32 *d = dst;
	const u32 *s = src;
	size_t group_num = CT_OTHER_GROUP_NUMS;
	struct hvgr_device *gdev = hvgr_get_device();
	size_t i;
	size_t j;
	size_t body_size = hweight32(s[CT_HEADER_MASK]) * GROUPS_PER_MASK_BIT;

	group_num += hweight32(hvgr_get_cores(gdev));
	for (i = 0; i < group_num; i++) {
		for (j = 0; j < body_size; j++) {
			if (j < HEADER_SIZE_BY_UINT)
				d[j] = s[j];
			else if (U32_MAX - d[j] < s[j])
				d[j] = s[j] - (U32_MAX - d[j]);
			else
				d[j] += s[j];
		}
		d += GROUP_SIZE_BY_UINT;
		s += GROUP_SIZE_BY_UINT;
	}
}

static void hvgr_ct_dump_buffer_head_update(struct hvgr_ct_context *ct_ctx, struct hvgr_ct_client *client)
{
	u32 i;
	u32 nr_l2;
	int ret;
	u64 core_mask;
	u32 *mask = NULL;
	u8 *dst = client->old_buffer;
	u8 *src = ct_ctx->accu_cpu_va;
	u8 *cur = client->new_buffer;
	struct hvgr_device *gdev = hvgr_get_device();

	core_mask = hvgr_get_cores(gdev);

	/* copy and patch job manager header */
	ret = memcpy_s(dst, HEADER_SIZE_BY_BYTES, src, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy jm fail");

	mask = (u32 *)&dst[BITMASK_OFFSET_IN_HEADER];
	*mask &= client->bitmap[CT_FCM_INDEX];
	ret = memcpy_s(cur, HEADER_SIZE_BY_BYTES, dst, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy jm fail");
	dst += GROUP_SIZE_BY_BYTES;
	src += GROUP_SIZE_BY_BYTES;
	cur += GROUP_SIZE_BY_BYTES;

	/* copy and patch hvgr MMU/L2C headers */
	nr_l2 = 1;
	for (i = 0; i < nr_l2; i++) {
		ret = memcpy_s(dst, HEADER_SIZE_BY_BYTES, src, HEADER_SIZE_BY_BYTES);
		if (ret != EOK)
			pr_err("memcpy MMU/L2C fail");

		mask = (u32 *)&dst[BITMASK_OFFSET_IN_HEADER];
		*mask &= client->bitmap[CT_MMU_INDEX];
		ret = memcpy_s(cur, HEADER_SIZE_BY_BYTES, dst, HEADER_SIZE_BY_BYTES);
		if (ret != EOK)
			pr_err("memcpy jm fail");
		dst += GROUP_SIZE_BY_BYTES;
		src += GROUP_SIZE_BY_BYTES;
		cur += GROUP_SIZE_BY_BYTES;
	}

	/* copy and patch tiler header */
	ret = memcpy_s(dst, HEADER_SIZE_BY_BYTES, src, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy tiler fail");

	mask = (u32 *)&dst[BITMASK_OFFSET_IN_HEADER];
	*mask &= client->bitmap[CT_BTC_INDEX];
	ret = memcpy_s(cur, HEADER_SIZE_BY_BYTES, dst, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy jm fail");
	dst += GROUP_SIZE_BY_BYTES;
	src += GROUP_SIZE_BY_BYTES;
	cur += GROUP_SIZE_BY_BYTES;

	/* copy and patch bvh header */
	ret = memcpy_s(dst, HEADER_SIZE_BY_BYTES, src, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy bvh fail");

	mask = (u32 *)&dst[BITMASK_OFFSET_IN_HEADER];
	*mask &= client->bitmap[CT_BVH_INDEX];
	ret = memcpy_s(cur, HEADER_SIZE_BY_BYTES, dst, HEADER_SIZE_BY_BYTES);
	if (ret != EOK)
		pr_err("memcpy jm fail");
	dst += GROUP_SIZE_BY_BYTES;
	src += GROUP_SIZE_BY_BYTES;
	cur += GROUP_SIZE_BY_BYTES;

	/* copy and patch shader core headers */
	while (core_mask != 0ULL) {
		ret = memcpy_s(dst, HEADER_SIZE_BY_BYTES, src, HEADER_SIZE_BY_BYTES);
		if (ret != EOK)
			pr_err("memcpy shader core fail");

		if ((core_mask & 1ULL) != 0ULL) {
			/* if block is not reserved update header */
			mask = (u32 *)&dst[BITMASK_OFFSET_IN_HEADER];
			*mask &= client->bitmap[CT_GPC_INDEX];
			ret = memcpy_s(cur, HEADER_SIZE_BY_BYTES, dst, HEADER_SIZE_BY_BYTES);
			if (ret != EOK)
				pr_err("memcpy jm fail");
		}
		dst += GROUP_SIZE_BY_BYTES;
		src += GROUP_SIZE_BY_BYTES;
		cur += GROUP_SIZE_BY_BYTES;

		core_mask >>= 1;
	}
}

static int hvgr_ct_update_client_buffer(struct hvgr_ct_context *ct_ctx, struct hvgr_ct_client *client)
{
	u32 *accu_date = ct_ctx->accu_cpu_va;
	u32 *old_date = client->old_buffer;
	u32 *cur_date = client->new_buffer;
	size_t group_num = CT_OTHER_GROUP_NUMS;
	struct hvgr_device *gdev = hvgr_get_device();
	size_t i;
	size_t j;

	group_num += hweight32(hvgr_get_cores(gdev));
	for (i = 0; i < group_num; i++) {
		size_t body_size = hweight32(old_date[CT_HEADER_MASK]) * GROUPS_PER_MASK_BIT;

		/* skip index 0~3 */
		for (j = HEADER_SIZE_BY_UINT; j < body_size; j++) {
			if (accu_date[j] < old_date[j]) {
				/* reverse */
				cur_date[j] = (U32_MAX - old_date[j]) + (accu_date[j] - 0);
			} else {
				cur_date[j] = accu_date[j] - old_date[j];
			}
			old_date[j] = accu_date[j];
		}

		accu_date += GROUP_SIZE_BY_UINT;
		old_date += GROUP_SIZE_BY_UINT;
		cur_date += GROUP_SIZE_BY_UINT;
	}
	return 0;
}

static void hvgr_ct_accum_clients(struct hvgr_ct_client *client)
{
	struct hvgr_ct_context *ct_ctx = NULL;
	if (client == NULL)
		return;

	ct_ctx = client->ct_ctx;
	if (ct_ctx == NULL)
		return;

	/* The header must be updated before the data. The data depends on the header mask. */
	hvgr_ct_dump_buffer_head_update(ct_ctx, client);
	hvgr_ct_update_client_buffer(ct_ctx, client);
}

u64 hvgr_ct_get_dump_timestamp(void)
{
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
	struct timespec ts;

	getrawmonotonic(&ts);
#else
	struct timespec64 ts;

	ktime_get_raw_ts64(&ts);
#endif
	return (u64)ts.tv_sec * CT_DUMP_BY_NS + (u64)ts.tv_nsec;
}

/* collect include:
 * dump counter into global rawdata buffer
 * accumalute rawdata into global accu buffer
 */
static int hvgr_ct_collect(struct hvgr_ct_context *ct_ctx, u64 *timestamp)
{
	int ret;
	unsigned long flags;
	struct hvgr_device *gdev = NULL;
	struct hvgr_cq_dev *gcqctx = NULL;

	if (unlikely(ct_ctx == NULL))
		return -EINVAL;

	gdev = ct_ctx->gdev;
	gcqctx = &gdev->cq_dev;
	if (gdev->datan_dev.datan_ct_dev.ct_closed)
		return 0;

	if (hvgr_get_prot_enhance(gdev)) {
		spin_lock_irqsave(&gcqctx->protect_mode_switch, flags);
		hvgr_info(gdev, HVGR_DATAN, "prot mode lock in.");
		if (gcqctx->protect_mode_info.protected_mode ||
			gcqctx->protect_mode_info.protected_mode_transition) {
			hvgr_info(gdev, HVGR_DATAN, "prot mode lock1 out.");
			spin_unlock_irqrestore(&gcqctx->protect_mode_switch, flags);
			return 0;
		}
	} else {
		hvgr_info(gdev, HVGR_DATAN, "disable preempt.");
		preempt_disable();
	}

	*timestamp = hvgr_ct_get_dump_timestamp();
	ret = hvgr_datan_ct_dump_inner(ct_ctx->ctx);
	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s, config dump reg ret=%d.", __func__, ret);
	if (!hvgr_get_prot_enhance(gdev)) {
		hvgr_info(gdev, HVGR_DATAN, "enable preempt.");
		preempt_enable();
	}
	if (ret == 0)
		ret = hvgr_datan_ct_wait_for_dump_inner(ct_ctx->ctx);
	WARN_ON(ret);

	if (hvgr_get_prot_enhance(gdev)) {
		hvgr_info(gdev, HVGR_DATAN, "prot mode lock2 out.");
		spin_unlock_irqrestore(&gcqctx->protect_mode_switch, flags);
	}

	if (ret == 0) {
		hvgr_ct_accum_dump_buffer(ct_ctx->accu_cpu_va, ct_ctx->cpu_va, ct_ctx->dump_size, ct_ctx->dump_size);
		ct_ctx->last_dump_time = *timestamp;
	}

	return ret;
}

static int hvgr_ct_collect_and_accumulate(struct hvgr_ct_client *client, u64 *timestamp)
{
	int ret;
	struct hvgr_ct_context *ct_ctx = client->ct_ctx;

	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	ret = hvgr_ct_collect(ct_ctx, timestamp);
	if (ret == 0)
		hvgr_ct_accum_clients(client);

	return ret;
}

static void hvgr_ct_collect_and_disable(struct hvgr_device *gdev, bool dump_ct)
{
	int ret;
	struct hvgr_ct_context *ct_ctx = gdev->ct_dev.ct_ctx;
	u64 unused;

	if (dump_ct) {
		ret = hvgr_ct_collect(ct_ctx, &unused);
		if (ret != 0) {
			hvgr_err(gdev, HVGR_DATAN, "%s Dump Failed.", __func__);
			return;
		}
	}

	ret = hvgr_datan_ct_disable_inner(ct_ctx->ctx);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_DATAN, "%s Disable Failed.", __func__);
		return;
	}
}

#if hvgr_version_eq(350)
static void hvgr_pmu_collect(struct hvgr_device *gdev)
{
	struct hvgr_datan_ct_dev *datan_ct_dev = &gdev->datan_dev.datan_ct_dev;

	datan_ct_dev->pmu_counter[0] += hvgr_read_reg(gdev, misc_control_reg(gdev, PMU_GPU_ACTIVE));
	datan_ct_dev->pmu_counter[1] += hvgr_read_reg(gdev, misc_control_reg(gdev, PMU_JOBS_JS0));
	datan_ct_dev->pmu_counter[2] += hvgr_read_reg(gdev, misc_control_reg(gdev, PMU_JS0_ACTIVE));
	datan_ct_dev->pmu_counter[3] += hvgr_read_reg(gdev, misc_control_reg(gdev, PMU_JS1_ACTIVE));
}
#endif

/* the caller should hold power_lock */
void hvgr_api_ct_collect_and_disable(struct hvgr_device *gdev, bool dump_ct)
{
	hvgr_info(gdev, HVGR_DATAN, "%s config=%d, closed=%d enter.", __func__,
		gdev->datan_dev.datan_ct_dev.ct_config,
		gdev->datan_dev.datan_ct_dev.ct_closed);

#if hvgr_version_eq(350)
	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY)
		hvgr_pmu_collect(gdev);
#endif

	if (!gdev->datan_dev.datan_ct_dev.ct_config)
		return;

	if (gdev->datan_dev.datan_ct_dev.ct_closed)
		return;

	if (hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY)
		hvgr_ct_collect_and_disable(gdev, dump_ct);
	gdev->datan_dev.datan_ct_dev.ct_closed = true;
}

static int hvgr_ct_update_fixed_time_buffer(struct hvgr_ct_client *client, u64 timestamp)
{
	struct hvgr_ct_queue_ctrl *kmd_ctrl = NULL;
	struct hvgr_ct_queue_data_ctrl *buffer = NULL;
	char *buffer_base = NULL;
	uint32_t rd = 0;
	uint32_t wr = 0;
	uint32_t offset;
	int ret;
	struct hvgr_device *gdev = hvgr_get_device();

	if (client == NULL || client->kmd_ctrl == NULL || gdev == NULL
		|| client->user_ctrl == NULL || client->data_ctrl == NULL)
		return -EINVAL;

	offset = hvgr_ct_get_dump_size() + HVGR_CT_QUEUE_DATA_CTRL_HEAD_SIZE;

	kmd_ctrl = client->kmd_ctrl;
	rd = client->user_ctrl->rd;
	wr = kmd_ctrl->wr;

	if (((wr + 1u) & (client->ring_num - 1u)) == rd) {
		hvgr_err(gdev, HVGR_DATAN, "ring full: [wr:%u] [rd:%u].", wr, rd);
		return -EINVAL;
	}
	hvgr_info(gdev, HVGR_DATAN, "current [wr:%u] [rd:%u].", wr, rd);
	buffer_base = (char *)client->data_ctrl;
	buffer = (struct hvgr_ct_queue_data_ctrl *)(buffer_base + offset * wr);
	buffer->timestamp = timestamp;
	buffer->event_id = 1llu;
	ret = memcpy_s(buffer->data, client->dump_size,
		client->new_buffer, client->dump_size);
	kmd_ctrl->wr = ((wr + 1u) & (client->ring_num - 1u));
	if (ret != EOK)
		return -EINVAL;
	return ret;
}

static int hvgr_ct_fill_dump_buffer_legacy(struct hvgr_ct_client *client)
{
	void __user  *buffer = client->legacy_buffer;

#if hvgr_version_eq(350)
	u32 *tmp = (u32 *)client->new_buffer;
	u64 active = (u64)tmp[13];
	u64 js0 = (u64)tmp[20];
	u64 js1 = (u64)tmp[23];
	tmp[13] = (u32)(active * 6 / 5);
	tmp[20] = (u32)(js0 * 6 / 5);
    tmp[23] = (u32)(js1 * 6 / 5);
#endif

	if (copy_to_user(buffer, client->new_buffer, client->dump_size) != 0) {
		pr_warn("error while copying buffer to user\n");
		return -EFAULT;
	}
	return 0;
}

static void hvgr_ct_reprogram(struct hvgr_ct_context *ct_ctx)
{
	struct hvgr_ct_client *iter = NULL;

	if (!ct_ctx->is_need_update_config)
		return;

	if (hvgr_ct_reset_logic(ct_ctx) == 0) {
		ct_ctx->is_need_update_config = false;
		list_for_each_entry(iter, &ct_ctx->work_clients, list)
			iter->is_config_valid = true;
	}
}

static int hvgr_ct_update_client(struct hvgr_ct_client *client, u64 timestamp)
{
	int ret;

	if (client->ring_num > 0)
		ret = hvgr_ct_update_fixed_time_buffer(client, timestamp);
	else
		ret = hvgr_ct_fill_dump_buffer_legacy(client);

	if (ret != 0)
		goto exit;

	/* Notify client. Make sure all changes to memory are visible. */
	wmb();
	wake_up_interruptible(&client->waitq);

	(void)memset_s(client->new_buffer, client->dump_size, 0, client->dump_size);
exit:
	return ret;
}

static int hvgr_ct_single_dump_setup(struct hvgr_ct_context *ct_ctx, struct hvgr_ctx *ctx,
	struct hvgr_ct_client  **client, struct hvgr_ct_setup *setup)
{
	hvgr_info(ct_ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	if (setup->dump_buffer != 0) {
		struct hvgr_ct_cfg ct_cfg;

		ct_cfg.bitmap[CT_FCM_INDEX] = setup->fcm_bm;
		ct_cfg.bitmap[CT_MMU_INDEX] = setup->mmu_l2_bm;
		ct_cfg.bitmap[CT_BTC_INDEX] = setup->btc_bm;
		ct_cfg.bitmap[CT_BVH_INDEX] = setup->bvh_bm;
		ct_cfg.bitmap[CT_GPC_INDEX] = setup->gpc_bm;
		ct_cfg.set_id = setup->set_id;
		ct_cfg.ring_num = 0;

		if ((*client) != NULL)
			return -EBUSY;
		*client = hvgr_ct_attach_client(ct_ctx, ctx, &ct_cfg,
			(void *)((uintptr_t)(setup->dump_buffer)), NULL);
		if ((*client) == NULL)
			return -ENOMEM;
	} else {
		if ((*client) == NULL)
			return -EINVAL;

		hvgr_ct_detach_client(*client);
		*client = NULL;
	}

	return 0;
}

void hvgr_api_ct_probe(struct hvgr_device *const gdev)
{
	struct hvgr_ct_context *ct_ctx = NULL;

	hvgr_datan_ct_init_status_inner(gdev);
	ct_ctx = kzalloc(sizeof(*ct_ctx), GFP_KERNEL);
	if (ct_ctx == NULL)
		return;
	INIT_LIST_HEAD(&ct_ctx->work_clients);
	mutex_init(&ct_ctx->lock);
	ct_ctx->gdev = gdev;
	ct_ctx->as_id = DATAN_CT_DUMP_ASID;

	atomic_set(&ct_ctx->pm_ref_cnt, 0);

	gdev->ct_dev.ct_ctx = ct_ctx;
	spin_lock_init(&gdev->datan_dev.datan_ct_dev.ct_lock);

#if hvgr_version_ge(350)
	mutex_init(&gdev->datan_dev.datan_ct_dev.pmu_lock);
	gdev->datan_dev.datan_ct_dev.pmu_ctx_id = 0;
	(void)memset_s(gdev->datan_dev.datan_ct_dev.pmu_counter,
		PMU_MAX_SIZE * sizeof(uint32_t), 0, PMU_MAX_SIZE * sizeof(uint32_t));
#endif
}

void hvgr_api_ct_term(struct hvgr_device *const gdev)
{
	struct hvgr_ct_client *client = NULL;
	struct hvgr_ct_context *ct_ctx = gdev->ct_dev.ct_ctx;

	if (ct_ctx == NULL)
		return;

	while (1) {
		struct list_head *list = &ct_ctx->work_clients;

		if (list_empty(list))
			break;
		client = list_first_entry(list, struct hvgr_ct_client, list);
		list_del(&client->list);

		if (client->old_buffer != NULL) {
			kfree(client->old_buffer);
			client->old_buffer = NULL;
		}
		if (client->new_buffer != NULL) {
			kfree(client->new_buffer);
			client->new_buffer = NULL;
		}

		kfree(client);
		client = NULL;
		ct_ctx->client_num--;
	}
	if (ct_ctx->ctx != NULL)
		hvgr_ct_destroy_ct_ctx(ct_ctx);
	kfree(ct_ctx);
	gdev->ct_dev.ct_ctx = NULL;
}

long hvgr_api_ct_alloc(struct hvgr_ctx *ctx, union hvgr_ioctl_ct_alloc *const para)
{
	struct hvgr_ct_client *client = NULL;
	struct hvgr_ct_cfg ct_cfg;

	if (ctx == NULL || para == NULL) {
		hvgr_err(hvgr_get_device(), HVGR_DATAN, "%s invalid para.", __func__);
		return -1;
	}
	hvgr_info(ctx->gdev, HVGR_DATAN, "%s in.", __func__);

	ct_cfg.bitmap[CT_FCM_INDEX] = para->in.fcm_bm;
	ct_cfg.bitmap[CT_MMU_INDEX] = para->in.mmu_l2_bm;
	ct_cfg.bitmap[CT_BTC_INDEX] = para->in.btc_bm;
	ct_cfg.bitmap[CT_BVH_INDEX] = para->in.bvh_bm;
	ct_cfg.bitmap[CT_GPC_INDEX] = para->in.gpc_bm;
	ct_cfg.set_id = para->in.set_id;
	ct_cfg.ring_num = para->in.ring_num;

	client = hvgr_ct_attach_client(ctx->gdev->ct_dev.ct_ctx, ctx, &ct_cfg, &para->out.fd,
		&para->out.ctrl_addr);
	if (client == NULL)
		return -ENOMEM;

	hvgr_info(ctx->gdev, HVGR_DATAN, "%s success.", __func__);
	return 0;
}

int hvgr_api_ct_enable(struct hvgr_ctx *ctx, struct hvgr_ioctl_ct_single_dump_enable *enable)
{
	int ret;
	struct hvgr_ct_setup setup = {
		.dump_buffer = enable->dump_buffer,
		.fcm_bm = enable->fcm_bm,
		.mmu_l2_bm = enable->mmu_l2_bm,
		.btc_bm = enable->btc_bm,
		.bvh_bm = enable->bvh_bm,
		.gpc_bm = enable->gpc_bm,
		.set_id = enable->set_id
	};

	hvgr_info(ctx->gdev, HVGR_DATAN, "%s enter.", __func__);

	mutex_lock(&ctx->counter_ctx.ct_client_lock);
	ret = hvgr_ct_single_dump_setup(ctx->gdev->ct_dev.ct_ctx, ctx,
		&ctx->counter_ctx.single_dump_client, &setup);
	mutex_unlock(&ctx->counter_ctx.ct_client_lock);

	hvgr_info(ctx->gdev, HVGR_DATAN, "%s exit.", __func__);

	return ret;
}

int hvgr_api_ct_close_ctx(struct hvgr_ctx *ctx)
{
	int ret = 0;

	mutex_lock(&ctx->counter_ctx.ct_client_lock);

	hvgr_info(ctx->gdev, HVGR_DATAN, "%s enter.", __func__);

	if (ctx->gdev->ct_dev.ct_ctx != NULL) {
		struct hvgr_ct_setup setup;

		setup.dump_buffer = 0;
		ret = hvgr_ct_single_dump_setup(ctx->gdev->ct_dev.ct_ctx, ctx,
			&ctx->counter_ctx.single_dump_client, &setup);
	}
	mutex_unlock(&ctx->counter_ctx.ct_client_lock);

#if hvgr_version_ge(350)
	mutex_lock(&ctx->gdev->datan_dev.datan_ct_dev.pmu_lock);
	if (ctx->id == ctx->gdev->datan_dev.datan_ct_dev.pmu_ctx_id)
		ctx->gdev->datan_dev.datan_ct_dev.pmu_ctx_id = 0;
	mutex_unlock(&ctx->gdev->datan_dev.datan_ct_dev.pmu_lock);
#endif
	hvgr_info(ctx->gdev, HVGR_DATAN, "%s exit.", __func__);
	return ret;
}

void hvgr_api_ct_open_ctx(struct hvgr_ctx *ctx)
{
	hvgr_info(ctx->gdev, HVGR_DATAN, "%s enter.", __func__);
	mutex_init(&ctx->counter_ctx.ct_client_lock);
}

static int hvgr_ct_dump(struct hvgr_ct_client *client)
{
	int ret = 0;
	u64 timestamp;
	struct hvgr_ct_context *ct_ctx = NULL;
	struct hvgr_device *gdev = NULL;

	if (client == NULL)
		return -EINVAL;

	ct_ctx = client->ct_ctx;
	if (ct_ctx == NULL)
		return -EINVAL;

	gdev = ct_ctx->gdev;
	if (gdev == NULL)
		return -EINVAL;

	timestamp = hvgr_ct_get_dump_timestamp();
	client->dump_time = timestamp;

	hvgr_info(gdev, HVGR_DATAN, "%s enter.", __func__);
	mutex_lock(&ct_ctx->lock);
	mutex_lock(&gdev->pm_dev.pm_pwr.power_lock);
	if ((hvgr_pm_get_gpu_status(gdev) == HVGR_PM_GPU_READY) &&
		gdev->datan_dev.datan_ct_dev.ct_config &&
		!gdev->datan_dev.datan_ct_dev.ct_closed) {
		ret = hvgr_ct_collect(ct_ctx, &timestamp);
		if (ret != 0) {
			mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);
			hvgr_err(ct_ctx->gdev, HVGR_DATAN, "%s, Dump Failed", __func__);
			goto exit;
		}
	}
	hvgr_ct_accum_clients(client);
	mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);

	if (hvgr_ct_update_client(client, timestamp) != 0)
		goto exit;
	hvgr_ct_reprogram(ct_ctx);
exit:
	mutex_unlock(&ct_ctx->lock);
	return ret;
}

int hvgr_api_ct_dump(struct hvgr_ctx *ctx)
{
	int ret;

	hvgr_info(ctx->gdev, HVGR_DATAN, "%s enter.", __func__);

	mutex_lock(&ctx->counter_ctx.ct_client_lock);
	ret = hvgr_ct_dump(ctx->counter_ctx.single_dump_client);
	mutex_unlock(&ctx->counter_ctx.ct_client_lock);

	return ret;
}

int hvgr_api_dump_reg(struct hvgr_ctx *ctx, struct hvgr_ioctl_dump_reg *reg_dump)
{
#if hvgr_version_eq(350)
	struct hvgr_datan_ct_dev *datan_ct_dev = &ctx->gdev->datan_dev.datan_ct_dev;
	void __user *dump_buffer;
	uint32_t tmp_counter[DUMP_REG_SIZE_V350];
	uint32_t size;
	uint32_t i;

	if (reg_dump == NULL) {
		hvgr_err(ctx->gdev, HVGR_DATAN, "[%s] arg is invaild.", __func__);
		return -EFAULT;
	}
	dump_buffer = u64_to_ptr(reg_dump->dump_buffer);
	size = reg_dump->size;

	mutex_lock(&datan_ct_dev->pmu_lock);
	if (datan_ct_dev->pmu_ctx_id == 0)
		datan_ct_dev->pmu_ctx_id = ctx->id;

	if (ctx->id == datan_ct_dev->pmu_ctx_id) {
		if (reg_dump->dump_buffer == 0 ||  reg_dump->size == 0) {
			ctx->gdev->datan_dev.datan_ct_dev.pmu_ctx_id = 0;
			mutex_unlock(&datan_ct_dev->pmu_lock);
			return 0;
		}
	} else {
		hvgr_err(ctx->gdev, HVGR_DATAN, "current ctx_id does not match with previous ctx_id.");
		mutex_unlock(&datan_ct_dev->pmu_lock);
		return -EFAULT;
	}
	mutex_unlock(&datan_ct_dev->pmu_lock);

	if (size != DUMP_REG_SIZE_V350) {
		hvgr_err(ctx->gdev, HVGR_DATAN, "[%s] buffer size is invaild.", __func__);
		return -EFAULT;
	}

	mutex_lock(&ctx->gdev->pm_dev.pm_pwr.power_lock);
	if (hvgr_pm_get_gpu_status(ctx->gdev) == HVGR_PM_GPU_READY)
		hvgr_pmu_collect(ctx->gdev);

	memcpy_s(tmp_counter, size * sizeof(uint32_t), datan_ct_dev->pmu_counter, size * sizeof(uint32_t));
	(void)memset_s(datan_ct_dev->pmu_counter, size * sizeof(uint32_t), 0, size * sizeof(uint32_t));
	mutex_unlock(&ctx->gdev->pm_dev.pm_pwr.power_lock);

	for (i = 0; i < size; i++) {
		if (i == 1)
			continue;
		u64 tmp = (u64)tmp_counter[i];
		tmp_counter[i] = (u32)(tmp * 6 / 5);
	}

	if (copy_to_user(dump_buffer, tmp_counter, size * sizeof(uint32_t)) != 0) {
		hvgr_err(ctx->gdev, HVGR_DATAN, "[%s] error while copying buffer to user\n", __func__);
		return -EFAULT;
	}
#endif

	return 0;
}

static void hvgr_ct_workqueue_handle(struct work_struct *data)
{
	int ret = -1;
	u64 timestamp = 0;
	struct hvgr_ct_client *ct_client = NULL;
	struct hvgr_ct_context *ct_ctx = NULL;
	struct hvgr_device *gdev = NULL;

	if (data == NULL)
		return;

	ct_client = container_of(data, struct hvgr_ct_client, ct_worker);
	ct_ctx = ct_client->ct_ctx;
	gdev = ct_ctx->gdev;
	if (gdev == NULL)
		return;

	mutex_lock(&ct_ctx->lock);
	if (abs(ct_client->dump_time - ct_ctx->last_dump_time) < MIN_VALID_INTERVAl) {
		ret = hvgr_ct_update_client_buffer(ct_ctx, ct_client);
		timestamp = ct_ctx->last_dump_time;
	} else {
		mutex_lock(&gdev->pm_dev.pm_pwr.power_lock);
		ret = hvgr_ct_collect_and_accumulate(ct_client, &timestamp);
		mutex_unlock(&gdev->pm_dev.pm_pwr.power_lock);
	}
	if (ret != 0)
		goto exit;

	ct_client->dump_time = ct_ctx->last_dump_time + ct_client->dump_interval;
	if (hvgr_ct_update_client(ct_client, timestamp) != 0)
		goto exit;

	hvgr_ct_reprogram(ct_ctx);

exit:
	mutex_unlock(&ct_ctx->lock);
}

static void hvgr_ct_check_running_counter(struct hvgr_ct_client *client, struct hrtimer *hrtimer, uint32_t interval)
{
	if (client->timer_should_run) {
		client->timer_running_flag = true;
		hrtimer_start(hrtimer, ns_to_ktime(interval), HRTIMER_MODE_REL);
	} else {
		client->timer_running_flag = false;
	}
}

static enum hrtimer_restart hvgr_ct_hrtimer_running(struct hrtimer *hrtimer)
{
	struct hvgr_device *gdev = NULL;
	struct hvgr_ct_client *client = NULL;
	struct hvgr_ct_context *ct_ctx = NULL;
	unsigned long flags;
	unsigned long flag;
	uint32_t interval = 0;

	gdev = hvgr_get_device();
	client = container_of(hrtimer, struct hvgr_ct_client, client_hrtimer);

	if (unlikely(client == NULL)) {
		hvgr_err(gdev, HVGR_DATAN, "%s null param: client == NULL\n", __func__);
		return HRTIMER_NORESTART;
	}
	ct_ctx = client->ct_ctx;
	if (unlikely(ct_ctx == NULL)) {
		hvgr_err(gdev, HVGR_DATAN, "%s null param: ct_ctx == NULL\n", __func__);
		client->timer_running_flag = false;
		return HRTIMER_NORESTART;
	}

	if (!client->timer_should_run) {
		client->timer_running_flag = false;
		return HRTIMER_NORESTART;
	}

	if (ct_ctx->wq == NULL) {
		hvgr_err(gdev, HVGR_DATAN, "%s null param: wq = NULL\n", __func__);
		return HRTIMER_NORESTART;
	}
	spin_lock_irqsave(&client->qwork_lock, flags);
	if (client->qwork_allow) {
		queue_work(ct_ctx->wq, &client->ct_worker);
	}
	spin_unlock_irqrestore(&client->qwork_lock, flags);

	spin_lock_irqsave(&client->timer_lock, flags);
	interval = client->dump_interval;

	spin_lock_irqsave(&client->flag_lock, flag);
	hvgr_ct_check_running_counter(client, hrtimer, interval);
	spin_unlock_irqrestore(&client->flag_lock, flag);

	spin_unlock_irqrestore(&client->timer_lock, flags);

	return HRTIMER_NORESTART;
}

void hvgr_ct_start_cycle_client_timer(struct hvgr_ct_client *client)
{
	struct hrtimer *hrtimer = NULL;
	struct hvgr_ct_context *ct_ctx = NULL;
	unsigned long flag;

	if (client == NULL)
		return;

	hrtimer = &client->client_hrtimer;
	ct_ctx = client->ct_ctx;
	if (ct_ctx == NULL)
		return;

	hvgr_info(client->ctx->gdev, HVGR_DATAN, "%s in.", __func__);
	if (client->dump_interval > 0) {
		hvgr_info(client->ctx->gdev, HVGR_DATAN, "%s dump_interval :%u.", __func__, client->dump_interval);
		if (client->timer_should_run) {
			hvgr_info(client->ctx->gdev, HVGR_DATAN, "input is invalid.");
			return;
		} else {
			hrtimer_init(hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
			hrtimer->function = hvgr_ct_hrtimer_running;
			client->timer_running_flag = true;
			client->timer_should_run = true;
			INIT_WORK(&client->ct_worker, hvgr_ct_workqueue_handle);
			hrtimer_start(hrtimer, ns_to_ktime(client->dump_interval), HRTIMER_MODE_REL);
		}
	} else {
		hvgr_info(client->ctx->gdev, HVGR_DATAN, "%s try to cancel timer", __func__);
		if (client->timer_running_flag) {
			spin_lock_irqsave(&client->flag_lock, flag);
			client->timer_should_run = false;
			spin_unlock_irqrestore(&client->flag_lock, flag);
			(void)hrtimer_cancel(hrtimer);
		}
	}
}
