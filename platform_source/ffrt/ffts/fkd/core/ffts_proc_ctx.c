/*
 * ffts_proc_ctx.c
 *
 * ffts device driver
 *
 * Copyright (c) 2012-2019 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "ffts_proc_ctx.h"

#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <platform_include/cee/linux/sched/ffrt/ffts_sched.h>

#include "ffts_log.h"
#include "ffts_resource.h"
#include "fpd_interface.h"
#include "ffts_tid.h"
#include "uniform_id.h"
#include "ffts_hw_config.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"
#include "ffts_proc_block.h"

static void ffts_proc_ctx_init(struct ffts_proc_ctx *proc_ctx)
{
	int mem_type;
	int ffts_hw_type; 

	cond_return_void(proc_ctx == NULL, "proc_ctx is null\n");
	INIT_LIST_HEAD(&proc_ctx->proc_ctx_list);

	mutex_init(&proc_ctx->ffts_map_mutex);
	
	for (mem_type = (int)FFTS_MEM_USER_REG; mem_type < (int)FFTS_MEM_MAX; mem_type++)
		INIT_LIST_HEAD(&proc_ctx->vma_list[mem_type]);

	for (ffts_hw_type = 0; ffts_hw_type < FFTS_HW_MAX; ffts_hw_type++) {
		proc_ctx->hw_rel_info[ffts_hw_type] = (struct hw_release_info) {
			.data = NULL,
            .tgid = 0,
            .callback_func = NULL,
		};
	}
	for (mem_type = (int)FFTS_MEM_USER_REG; mem_type < (int)FFTS_MEM_MAX; mem_type++) {
		proc_ctx->mmap_ref[mem_type] = false;
	}
}

static void ffts_proc_ctx_deinit(struct ffts_proc_ctx **proc_ctx_ptr)
{
	cond_return_void(proc_ctx_ptr == NULL, "proc_ctx_ptr is NULL\n");

	mutex_destroy(&((*proc_ctx_ptr)->ffts_map_mutex));

	kfree(*proc_ctx_ptr);
	*proc_ctx_ptr = NULL;
}

struct ffts_proc_ctx *ffts_get_proc_ctx(struct ffts_dev_ctx *dev_ctx, pid_t pid)
{
	struct ffts_proc_ctx *proc_ctx = NULL;

	if (list_empty_careful(&dev_ctx->proc_ctx_list_head) == 0) {
		list_for_each_entry(proc_ctx, &dev_ctx->proc_ctx_list_head, proc_ctx_list) {
			if (proc_ctx->pid == pid)
				return proc_ctx;
		}
	}
	return NULL;
}

static int ffts_set_hw_proc_ctx(u16 uid, phys_addr_t rtb_addr)
{
	struct fpd_registry* fpd = get_fpd();

	if (fpd->fpd_set_hw_proc_ctx != NULL)
		return fpd->fpd_set_hw_proc_ctx(uid, rtb_addr);
	return 0;
}

static int ffts_reset_hw_proc_ctx(u16 uid)
{
	struct fpd_registry* fpd = get_fpd();

	if (fpd->fpd_reset_hw_proc_ctx != NULL)
		return fpd->fpd_reset_hw_proc_ctx(uid);
	return 0;
}

static int ffts_set_hw_thread_ctx(u16 ffts_tid, struct ffts_mem_info *sq_des)
{
	struct fpd_registry* fpd = get_fpd();
	cond_return_error(fpd == NULL, -1, "fpd ptr is NULL\n");

	if (fpd->fpd_set_hw_thread_ctx != NULL)
		return fpd->fpd_set_hw_thread_ctx(ffts_tid, sq_des);
	return 0;
}

static int ffts_reset_hw_thread_ctx(u16 ffts_tid)
{
	struct fpd_registry* fpd = get_fpd();
	cond_return_error(fpd == NULL, -1, "fpd ptr is NULL\n");

	if (fpd->fpd_reset_hw_thread_ctx != NULL)
		return fpd->fpd_reset_hw_thread_ctx(ffts_tid);
	return 0;
}

static void ffts_proc_block_handle(struct ffts_dev_ctx *dev_ctx, struct ffts_proc_ctx *proc_ctx)
{
	struct fpd_registry* fpd = get_fpd();
	cond_return_void(fpd == NULL, "fpd ptr is NULL\n");

	if (fpd != NULL && fpd->fpd_proc_block_handle != NULL)
		fpd->fpd_proc_block_handle(dev_ctx, proc_ctx);
	return;
}

static int ffts_create_hw_proc_ctx(struct ffts_proc_ctx *proc_ctx)
{
    int ret = -1;
	u16 uid;
	unsigned int order_rtb;
	struct page *page_rtb = NULL;

	// Process resource: 1. uid alloc
    uid = ffrt_get_uniform_id(current->tgid);
	cond_return_error(uid == FFRT_INVALID_UNIFORM_ID, -1, "request uid fail\n");
	proc_ctx->uid = uid;
	proc_ctx->pid = current->tgid;

	// Process resource: 2. RTB memory alloc
	order_rtb = get_order(PAGE_ALIGN(FFTS_RTB_SIZE));
	page_rtb = alloc_pages(GFP_KERNEL | __GFP_ZERO, order_rtb);
	cond_return_error(page_rtb == NULL, -1, "no mem to alloc rtb\n");
	proc_ctx->rtb_des.size = FFTS_RTB_SIZE;
	proc_ctx->rtb_des.virt_addr = page_address(page_rtb);
	cond_goto_error(proc_ctx->rtb_des.virt_addr == 0, set_pro_ctx_page_address_fail, ret, -ENOMEM,
		"page_address return error\n");
	proc_ctx->rtb_des.phy_addr = virt_to_phys(proc_ctx->rtb_des.virt_addr);
	ffts_drv_debug("rtb va addr = %pK, rtb pa addr = %pK\n",
		proc_ctx->rtb_des.virt_addr, proc_ctx->rtb_des.phy_addr);

	// Process resource: 3. fill hw_proc_ctx node
	ret = ffts_set_hw_proc_ctx(uid, proc_ctx->rtb_des.phy_addr);
	cond_goto_error(ret != 0, set_hw_proc_ctx_fail, ret, -1, "set hw_proc_ctx fail\n");

	return ret;
	
set_pro_ctx_page_address_fail:
set_hw_proc_ctx_fail:
	__free_pages(page_rtb, order_rtb);
    return ret;
}

static int ffts_create_hw_thread_ctx(struct ffts_proc_ctx *proc_ctx)
{
	int ret = -1;
	uint16_t ffts_tid = 0;

	// Thread resource: 1. ffts_tid alloc
	ffts_tid = ffts_request_tid(current->tgid);
	cond_return_error(ffts_tid == FFTS_INVALID_TID, -1, "request tid fail\n");
	proc_ctx->ffts_tid = ffts_tid;

	// Thread resource: 2. fill hw_thread_ctx node and alloc SQ memory in some chip version
	ret = ffts_set_hw_thread_ctx(ffts_tid, &proc_ctx->sq_des);
	cond_goto_error(ret != 0, alloc_sq_pages_fail, ret, -1, "set hw_proc_ctx fail\n");

	ffts_sched_proc_init(ffts_tid, FFTS_QOS_NUM);

	return ret;
alloc_sq_pages_fail:
	ffts_release_tid(ffts_tid);
	return ret;
}

int ffts_create_proc_ctx(struct ffts_dev_ctx *dev_ctx, struct file *filep)
{
	int ret = -1;
    struct ffts_proc_ctx *proc_ctx = NULL;

    mutex_lock(&dev_ctx->proc_ctx_lock);

	proc_ctx = ffts_get_proc_ctx(dev_ctx, current->tgid);
	cond_goto_error(proc_ctx != NULL, proc_ctx_create_fail, ret, -EBUSY, "ffts process had been inited\n");

	proc_ctx = kzalloc(sizeof(struct ffts_proc_ctx), GFP_KERNEL);
	cond_goto_error(proc_ctx == NULL, proc_ctx_create_fail, ret, -ENOMEM, "alloc proc_ctx failed\n");

    filep->private_data = (void *)proc_ctx;

	ffts_proc_ctx_init(proc_ctx);

	proc_ctx->filep = filep;
	proc_ctx->release_status = false;

	ret = ffts_create_hw_proc_ctx(proc_ctx);
	cond_goto_error(ret != 0, hw_proc_ctx_create_fail, ret, -1, "init proc_ctx_proc_resource fail\n");

	ret = ffts_create_hw_thread_ctx(proc_ctx);
	cond_goto_error(ret != 0, hw_thread_ctx_create_fail, ret, -1, "init proc_ctx_proc_resource fail\n");

	list_add(&proc_ctx->proc_ctx_list, &dev_ctx->proc_ctx_list_head);

	mutex_unlock(&dev_ctx->proc_ctx_lock);

    return ret;

hw_thread_ctx_create_fail:
	free_pages(proc_ctx->rtb_des.virt_addr, get_order(PAGE_ALIGN(FFTS_RTB_SIZE)));
	(void)ffts_reset_hw_proc_ctx(proc_ctx->uid);
hw_proc_ctx_create_fail:
	filep->private_data = NULL;
	ffts_proc_ctx_deinit(&proc_ctx);
proc_ctx_create_fail:
	mutex_unlock(&dev_ctx->proc_ctx_lock);
	return ret;
}

int ffts_release_proc_ctx(struct ffts_dev_ctx *dev_ctx, struct file *filep)
{
	unsigned int order_rtb, order_sq;
	struct ffts_proc_ctx *proc_ctx = (struct ffts_proc_ctx *)filep->private_data;

	if (unlikely(proc_ctx == NULL || list_empty_careful(&proc_ctx->proc_ctx_list))) {
		ffts_drv_err("proc_ctx is NULL, tgid=%d.\n", current->tgid);
		return 0;
	}

		// Process resource: 1. block process and clean ffts resource cache
	if (!proc_ctx->release_status) {
		ffts_proc_block_handle(dev_ctx, proc_ctx);
		proc_ctx->release_status = true;
	}

	mutex_lock(&dev_ctx->proc_ctx_lock);

	// del proc_ctx node from dev_ctx proc_ctx_list
	list_del_init(&proc_ctx->proc_ctx_list);

	ffts_drv_warn("uid = %u, tgid = %d, ffts_tid = %hu, pid = %d.\n",
		proc_ctx->uid, current->tgid, proc_ctx->ffts_tid, current->pid);

	ffts_sched_proc_exit(proc_ctx->pid);

	// Thread resource: 1. clean hw_thread_ctx node
	(void)ffts_reset_hw_thread_ctx(proc_ctx->ffts_tid);
	// Thread resource: 2. free SQ memory
	if (proc_ctx->sq_des.virt_addr != 0) {
		order_sq = get_order(PAGE_ALIGN(FFTS_SQ_SIZE));
		free_pages(proc_ctx->sq_des.virt_addr, order_sq);
		proc_ctx->sq_des.virt_addr = 0;
		proc_ctx->sq_des.phy_addr = 0;
	}
	// Thread resource: 3. free ffts_tid
	(void)ffts_release_tid(proc_ctx->ffts_tid);

	// Process resource: 2. clean hw_proc_ctx node
	(void)ffts_reset_hw_proc_ctx(proc_ctx->uid);

	// Process resource: 3. free rtb memory
	if (proc_ctx->rtb_des.virt_addr != 0) {
		order_rtb = get_order(PAGE_ALIGN(FFTS_RTB_SIZE));
		free_pages(proc_ctx->rtb_des.virt_addr, order_rtb);
		proc_ctx->rtb_des.virt_addr = 0;
		proc_ctx->rtb_des.phy_addr = 0;
	}

	ffts_proc_ctx_deinit(&proc_ctx);

	mutex_unlock(&dev_ctx->proc_ctx_lock);
	return 0;
}

int ffts_proc_release_register(ffts_hw_t hw_type, void (*callback)(void *data, int32_t tgid), void *data, int32_t tgid)
{
	cond_return_error(callback == NULL || data == NULL, -1, "callback or data is null\n");
	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -1, "dev ctx is NUll\n");

	mutex_lock(&dev_ctx->proc_ctx_lock);
	struct ffts_proc_ctx * proc_ctx = ffts_get_proc_ctx(dev_ctx, current->tgid);
	mutex_unlock(&dev_ctx->proc_ctx_lock);
	cond_return_error(proc_ctx == NULL, -1, "proc ctx is NUll\n");

	ffts_drv_debug("ffts_proc_release_register proc_ctx->pid = %d, tgid = %d\n", proc_ctx->pid, tgid);
	cond_return_error(proc_ctx->pid != tgid, -1, "tgid is invalid\n");

	mutex_lock(&proc_ctx->proc_rel_lock);
	proc_ctx->hw_rel_info[hw_type].data = data;
	proc_ctx->hw_rel_info[hw_type].callback_func = callback;
	mutex_unlock(&proc_ctx->proc_rel_lock);
	return 0;
}
EXPORT_SYMBOL(ffts_proc_release_register);