/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <asm/barrier.h>
#include <linux/bitmap.h>

#include <securec.h>
#include "hvgr_log_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_mmu_driver.h"
#include "hvgr_dm_api.h"
#include "hvgr_mmu_struct.h"
#include "hvgr_mmu_entry.h"
#include "hvgr_mmu_base.h"
#include "hvgr_fcp.h"
#include "hvgr_datan_api.h"
#include "hvgr_mem_debug_switch.h"

enum mmu_buffer_type {
	MMU_BUFFER_CD,
	MMU_BUFFER_CMDQ,
	MMU_BUFFER_EVENTQ,
};

static void hvgr_mmu_buffer_free(struct hvgr_mmu_buf *buf)
{
	if (buf->kva != NULL) {
		vunmap(buf->kva);
		buf->kva = NULL;
	}

	if (buf->buf_page != NULL) {
		__free_pages(buf->buf_page, buf->page_order);
		buf->buf_page = NULL;
	}
}

#define MMU_INIT_ALLOC_PAGES_TRY_MAX_TIMES  (3u)
#define MMU_INIT_VMAP_TRY_MAX_TIMES         (3u)
#define MMU_CMDQ_MAX_WAIT_TIMES             (3u)

#define mmu_cr1_set_queue_pbha(x)           ((u32)(x) << 12)
#define mmu_cr1_set_queue_sh(x)             ((u32)(x) << 8)
#define mmu_cr1_set_queue_memattr(x)        ((u32)(x))

#define mmu_cd_set_pbha(x)                  ((u32)(x) << 12)
#define mmu_cd_set_sh(x)                    ((u32)(x) << 8)
#define mmu_cd_set_memattr(x)               ((u32)(x))

#define mmu_set_base_l(x)                   ((u32)(x) & 0xffffffe0)
#define mmu_set_log2size(x)                 ((u32)(x))
#define mmu_set_base_h(x)                   ((u32)(((x) >> 32) & 0xfff))

#define mmu_cr0_set_memattr_bitmap(x)       ((u32)(x) << 8)
#define MMU_CR0_EVENT_GRANULE_PAGE          ((u32)0 << 3)
#define MMU_CR0_EVENT_GRANULE_ASID          ((u32)1 << 3)
#define MMU_CR0_STE_INVALID                 ((u32)0 << 0)
#define MMU_CR0_STE_VALID                   ((u32)1 << 0)

#define MMU_IRQ_MASK_CMD_SYNC               ((u32)1 << 2)
#define MMU_IRQ_MASK_EVENTQ_ERR             ((u32)1 << 1)
#define MMU_IRQ_MASK_CMDQ_ERR               ((u32)1 << 0)

#define MMU_SSID_MAX                        (4096U)

static int hvgr_mmu_buffer_init(struct hvgr_device * const gdev, struct hvgr_mmu_buf *buf,
	enum mmu_buffer_type type)
{
	struct page *page = NULL;
	struct page *page_array[MMU_CD_PAGES_CNT];
	uint32_t idx;
	uint32_t order;
	uint32_t page_nums;
	void *addr;
	gfp_t gfp = GFP_KERNEL | __GFP_ZERO | __GFP_NOWARN;
	pgprot_t prot = PAGE_KERNEL;
	uint32_t try_times = MMU_INIT_ALLOC_PAGES_TRY_MAX_TIMES;

	if (type == MMU_BUFFER_CD)
		order = MMU_CD_ORDER;
	else
		order = 0;

	page_nums = 1 << order;

	while (try_times > 0) {
		page = alloc_pages(gfp, order);
		if (page != NULL)
			break;
		hvgr_err(gdev, HVGR_MEM, "mmu buf alloc pages failed cnt %u", try_times);
		udelay(1);
		try_times--;
	}
	if (try_times == 0)
		return -1;

	for (idx = 0; idx < page_nums; idx++)
		page_array[idx] = &page[idx];

	prot = pgprot_writecombine(prot);

	try_times = MMU_INIT_VMAP_TRY_MAX_TIMES;
	while (try_times > 0) {
		addr = vmap(page_array, page_nums, VM_MAP, prot);
		if (addr != NULL)
			break;
		hvgr_err(gdev, HVGR_MEM, "mmu buf vmap failed cnt %u", try_times);
		udelay(1);
		try_times--;
	}
	if (try_times == 0) {
		__free_pages(page, page_nums);
		return -1;
	}

	buf->page_nums = page_nums;
	buf->buf_page = page;
	buf->page_order = order;
	buf->kva = addr;

	hvgr_info(gdev, HVGR_MEM, "mmu buf type %u init %pK", type, addr);

	return 0;
}

int hvgr_mmu_wait_cmdq_cons(struct hvgr_device * const gdev,
	uint32_t target_idx, uint32_t prod_wrap)
{
	uint32_t max_loops = 100000;
	uint32_t cmdq_cons;
	uint32_t cur_idx;
	uint32_t cons_wrap;

	cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
	cur_idx = mmu_cmdq_get_idx(cmdq_cons);
	cons_wrap = mmu_cmdq_get_wrap(cmdq_cons);

	while (--max_loops) {
		if ((prod_wrap == cons_wrap) && (cur_idx >= target_idx))
			break;
		if ((prod_wrap != cons_wrap) && (cur_idx < target_idx))
			break;
		cmdq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS));
		cur_idx = mmu_cmdq_get_idx(cmdq_cons);
		cons_wrap = mmu_cmdq_get_wrap(cmdq_cons);
	}
	if (max_loops == 0)
		return -1;

	return 0;
}

static int hvgr_mmu_wait_cmdq_mode(struct hvgr_device *gdev, uint32_t wrap,
	struct hvgr_wait_cmdq_info *wait_cmdq_idx, uint32_t wr_idx)
{
	uint32_t i;
	unsigned long flags;

	/* sync wait for cmdq consume done */
	if (wait_cmdq_idx->wait_mode_flag || !gdev->cq_dev.hw_cfg.cq_mmu_invalid_parellel)
		return hvgr_mmu_wait_cmdq_cons(gdev, wr_idx, wrap);

	/* record wr_idx and wrap for async */
	for (i = 0; i < MMU_CMDQ_MAX_WAIT_TIMES; i++) {
		if (!test_bit(wr_idx, gdev->mem_dev.cmdq_bitmap))
			break;

		udelay(1);
	}
	if (i == MMU_CMDQ_MAX_WAIT_TIMES)
		return -1;

	spin_lock_irqsave(&gdev->mem_dev.cmdq_bitmap_lock, flags);
	bitmap_set(gdev->mem_dev.cmdq_bitmap, wr_idx, 1);
	spin_unlock_irqrestore(&gdev->mem_dev.cmdq_bitmap_lock, flags);
	wait_cmdq_idx->wait_wr_idx = wr_idx;
	wait_cmdq_idx->wait_wrap = wrap;

	return 0;
}

static int hvgr_mmu_cmdq_prod(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev, 
	struct hvgr_mmu_cmd_info *cmd, struct hvgr_wait_cmdq_info *wait_cmdq_idx)
{
	struct hvgr_mmu_buf *cmdq_buf = &gdev->mem_dev.cmdq_buf;
	struct hvgr_mmu_cmd_info *cmdq_info = NULL;
	uint32_t cmdq_prod;
	uint32_t wrap;
	uint32_t wr_idx;
	int ret = 0;
	unsigned long flags;
	uint64_t dfx_time;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	dfx_time = hvgr_mmu_dfx_get_curtime(gdev);

	cmdq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD));
	wr_idx = mmu_cmdq_get_idx(cmdq_prod);
	wrap = mmu_cmdq_get_wrap(cmdq_prod);
	cmdq_info = cmdq_buf->kva;

	if (wr_idx >= MMU_CMDQ_MAX_CNT) {
		hvgr_err(gdev, HVGR_MEM, "cmdq prod wr_idx is invalid %u", wr_idx);
		spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
		return -1;
	}

	(void)memcpy_s(&cmdq_info[wr_idx], MMU_CMDQ_INFO_SIZE, cmd, MMU_CMDQ_INFO_SIZE);
	if (likely(wr_idx < (MMU_CMDQ_MAX_CNT - 1U))) {
		wr_idx = wr_idx + 1U;
	} else {
		wr_idx = 0U;
		wrap = mmu_wrap(wrap);
	}

	smp_mb();
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD),
		mmu_cmdq_set_wrap(wrap) | wr_idx);
	ret = hvgr_mmu_wait_cmdq_mode(gdev, wrap, wait_cmdq_idx, wr_idx);
	if (ret != 0)
		goto out;

	datan_jobtrace_cmdq_dump_wrapper(ctx, gdev, 1U);

out:
	hvgr_mmu_dfx_cmdq_statis(gdev, cmd->opcode, dfx_time);
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);

	return ret;
}

int hvgr_mmu_cmdq_tlb_invalid_asid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t asid)
{
	struct hvgr_mmu_cmd_info cmd = {0};
	struct hvgr_wait_cmdq_info wait_cmdq_idx = {0};

	wait_cmdq_idx.wait_mode_flag = true;
	cmd.opcode = MMU_CMD_TLBI_NH_ASID;
	cmd.op_data.tlbi_asid.asid = asid;
	hvgr_info(gdev, HVGR_MEM, "cmdq tlb invalid asid: %u", asid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, &wait_cmdq_idx);
}

int hvgr_mmu_cmdq_cd_invalid(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t ssid)
{
	struct hvgr_mmu_cmd_info cmd = {0};
	struct hvgr_wait_cmdq_info wait_cmdq_idx = {0};

	wait_cmdq_idx.wait_mode_flag = true;
	cmd.opcode = MMU_CMD_CFGI_CD;
	cmd.op_data.cdi.ssid = ssid;
	hvgr_info(gdev, HVGR_MEM, "cmdq cd invalid ssid: %u", ssid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, &wait_cmdq_idx);
}

int hvgr_mmu_cmdq_resume(struct hvgr_ctx * const ctx, struct hvgr_device * const gdev,
	uint32_t asid, uint64_t stag)
{
	struct hvgr_mmu_cmd_info cmd = {0};
	struct hvgr_wait_cmdq_info wait_cmdq_idx = {0};

	wait_cmdq_idx.wait_mode_flag = true;
	cmd.opcode = MMU_CMD_RESUME;
	cmd.op_data.resume.asid = asid;
	cmd.op_data.resume.stag = stag;
	hvgr_info(gdev, HVGR_MEM, "cmdq resume asid: %u", asid);

	return hvgr_mmu_cmdq_prod(ctx, gdev, &cmd, &wait_cmdq_idx);
}

int hvgr_mmu_cmdq_tlb_invalid_va(struct hvgr_ctx * const ctx, uint64_t gva,
	uint32_t pages, struct hvgr_wait_cmdq_info *wait_cmdq_idx, uint32_t level)
{
	struct hvgr_mmu_cmd_info cmd = {0};
	uint32_t gva_start, gva_end;

	gva_start = (uint32_t)(gva >> 12U);
	gva_end = gva_start + pages;

	if (gva_end < gva_start) {
		hvgr_err(ctx->gdev, HVGR_MEM, "ctx_%u asid %u cmdq tlb invalid gva: 0x%x:0x%x invalid",
			ctx->id, ctx->asid, gva_start, gva_end);
		return -1;
	}

	cmd.opcode = MMU_CMD_TLBI_NH_VA;
	cmd.op_data.tlbi_va.asid = ctx->asid;
	cmd.op_data.tlbi_va.va_start = gva_start;
	cmd.op_data.tlbi_va.va_end = gva_end;
	cmd.op_data.tlbi_va.granule = MMU_ADRMODE_4K;
	cmd.op_data.tlbi_va.level = level;
	hvgr_info(ctx->gdev, HVGR_MEM, "ctx_%u cmdq tlb invalid asid: %u, gva: 0x%x:0x%x",
		ctx->id, ctx->asid, gva_start, gva_end);

	return hvgr_mmu_cmdq_prod(ctx, ctx->gdev, &cmd, wait_cmdq_idx);
}

struct hvgr_mmu_event_info *hvgr_mmu_get_event(struct hvgr_device * const gdev)
{
	uint32_t eventq_cons;
	uint32_t eventq_prod;
	uint32_t r_wrap;
	uint32_t w_wrap;
	uint32_t rd_idx;
	uint32_t wr_idx;
	struct hvgr_mmu_buf *eventq_buf = &gdev->mem_dev.eventq_buf;
	struct hvgr_mmu_event_info *event = NULL;
	struct hvgr_mmu_event_info *event_array = NULL;

	eventq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_PROD));
	eventq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS));
	rd_idx = mmu_eventq_get_idx(eventq_cons);
	r_wrap = mmu_eventq_get_wrap(eventq_cons);
	wr_idx = mmu_eventq_get_idx(eventq_prod);
	w_wrap = mmu_eventq_get_wrap(eventq_prod);

	if (rd_idx >= MMU_EVENTQ_MAX_CNT || wr_idx >= MMU_EVENTQ_MAX_CNT) {
		hvgr_err(gdev, HVGR_MEM, "invalid evtq idx %u %u", rd_idx, wr_idx);
		return NULL;
	}

	if ((r_wrap == w_wrap) && (rd_idx >= wr_idx)) {
		hvgr_info(gdev, HVGR_MEM, "eventq read empty %u:%u", wr_idx, rd_idx);
		return NULL;
	}

	event_array = eventq_buf->kva;
	event = &event_array[rd_idx];

	if (rd_idx < MMU_EVENTQ_MAX_CNT - 1U) {
		rd_idx = rd_idx + 1U;
	} else {
		rd_idx = 0U;
		r_wrap = mmu_wrap(r_wrap);
	}
	eventq_buf->idx = rd_idx;
	eventq_buf->wrap = r_wrap;

	return event;
}

void hvgr_mmu_event_done(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_buf *eventq_buf = &gdev->mem_dev.eventq_buf;

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS),
		mmu_eventq_set_wrap(eventq_buf->wrap) | eventq_buf->idx);
}

int hvgr_mmu_init_cd(struct hvgr_ctx *ctx)
{
	struct hvgr_device *gdev = ctx->gdev;
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *desc_array = NULL;
	union hvgr_mmu_context_descriptor *desc = NULL;
	uint64_t pgd = ctx->mem_ctx.pgd_pa;

	if (ctx->ssid >= MMU_SSID_MAX) {
		hvgr_err(gdev, HVGR_MEM, "init cd invalid ssid %u", ctx->ssid);
		return -1;
	}

	desc_array = cd->kva;
	desc = &desc_array[ctx->ssid];
	(void)memset_s(desc, MMU_CD_INFO_SIZE, 0U, MMU_CD_INFO_SIZE);
	desc->st.asid = ctx->asid;
	desc->st.memattr = AS_MEMATTR_AARCH64;

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	pgd |= (((uint64_t)(ctx->mem_ctx.sc_data.pgd_mem_gid & 0xF0u)) << 36u);
#endif

	desc->st.ttb0_l = (pgd >> MMU_TTB0_PA_OFFSET_L) & MMU_TTB0_PA_MASK_L;
	desc->st.ttb0_h = (pgd >> MMU_TTB0_PA_OFFSET_H) & MMU_TTB0_PA_MASK_H;
	desc->st.asid = ctx->asid;

	if (hvgr_mmu_is_cpu_coherent(gdev))
		desc->st.ptw_sh = MMU_PTW_MEMATTR_OUT_SHAREABLE;

	desc->st.adrmode = MMU_ADRMODE_4K;
	desc->st.ptw_memattr = MMU_PTW_MEMATTR_NON_CACHEABLE;
	desc->st.write_execute_never = 0U;
	desc->st.affd = 1U;
	desc->st.ptw_pbha = 0U;

#ifdef HVGR_FEATURE_SYSTEM_CACHE
	if (ctx->mem_ctx.sc_data.pgd_mem_gid != 0U)
		desc->st.ptw_pbha = ctx->mem_ctx.sc_data.pgd_mem_gid & 0xFU;

	if (ctx->mem_ctx.sc_data.pgd_cache_enable != 0U)
		desc->st.ptw_memattr = MMU_PTW_MEMATTR_WRITE_BACK;
	else
		desc->st.ptw_memattr = MMU_PTW_MEMATTR_NON_CACHEABLE;
#endif
#if defined(HVGR_STATE_BUNDLE2) && HVGR_STATE_BUNDLE2 > 0
#if hvgr_version_eq(600)
	desc->st.normal_ctx_addr = ctx->ctx_cq.mem_ctx_addr;
	datan_jobtrace_dump_memctx_addr(ctx);
#endif
#endif
	hvgr_info(gdev, HVGR_MEM, "mmu init cd ok");
	return 0;
}

void hvgr_mmu_set_cd_valid(struct hvgr_ctx *ctx, bool valid)
{
	struct hvgr_device *gdev = ctx->gdev;
	uint32_t idx = ctx->ssid;
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *desc_array = cd->kva;

	if (idx >= MMU_SSID_MAX) {
		hvgr_err(gdev, HVGR_MEM, "set cd vld invalid ssid %u", idx);
		return;
	}

	desc_array[idx].st.valid = valid ? 1U : 0U;

	hvgr_info(gdev, HVGR_MEM, "set cd valid %u", desc_array[idx].st.valid);
	hvgr_datan_jobtrace(ctx, JOBTRACE_TYPE_OBJ, KDATAN_JD_DUMP_CD, ctx);
}

void hvgr_mmu_cd_show_fault_info(struct hvgr_device * const gdev, uint32_t ssid)
{
	struct hvgr_mmu_buf *cd = &gdev->mem_dev.cd_buf;
	union hvgr_mmu_context_descriptor *desc_array = cd->kva;
	union hvgr_mmu_context_descriptor *desc = NULL;

	if (ssid >= MMU_SSID_MAX) {
		hvgr_err(gdev, HVGR_MEM, "invalid ssid %u", ssid);
		return;
	}

	desc = &desc_array[ssid];
	hvgr_err(gdev, HVGR_MEM,
		"Bad CD: %u\n"
		"CD val0: 0x%x\n"
		"CD val1: 0x%x\n"
		"CD val2: 0x%x\n"
		"CD val3: 0x%x\n"
		"CD val4: 0x%x\n"
		"CD val5: 0x%x\n", ssid, desc->value[0U], desc->value[1U], desc->value[2U],
			desc->value[3U], desc->value[4U], desc->value[5U]);
}

static uint32_t hvgr_mmu_buffer_get_last_idx(uint32_t cur_idx, enum mmu_buffer_type type)
{
	uint32_t max_idx;

	if (type == MMU_BUFFER_CMDQ)
		max_idx = MMU_CMDQ_MAX_CNT - 1U;
	else if(type == MMU_BUFFER_EVENTQ)
		max_idx = MMU_EVENTQ_MAX_CNT - 1U;
	else
		return 0U;

	if (cur_idx == 0U)
		return max_idx;
	else
		return --cur_idx;
}

void hvgr_mmu_cmdq_print(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_buf *cmdq_buf = &gdev->mem_dev.cmdq_buf;
	struct hvgr_mmu_cmd_info *cmdq_info = NULL;
	uint32_t *data = NULL;
	unsigned long flags;
	uint32_t cmdq_prod;
	uint32_t wr_idx;
	uint32_t i;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	cmdq_info = cmdq_buf->kva;
	cmdq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD));
	wr_idx = mmu_cmdq_get_idx(cmdq_prod);

	hvgr_debug(gdev, HVGR_MEM, "dump cmdq MMU_CMDQ_PROD: 0x%08x", cmdq_prod);
	hvgr_debug(gdev, HVGR_MEM, "dump cmdq MMU_CMDQ_CONS: 0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS)));

	/* cur pointor no need print */
	for (i = 0U; i < MMU_CMDQ_BUFFER_PRINT_CNT; i++) {
		wr_idx = hvgr_mmu_buffer_get_last_idx(wr_idx, MMU_BUFFER_CMDQ);
		data = (uint32_t *)&cmdq_info[wr_idx];
		hvgr_debug(gdev, HVGR_MEM, "dump cmdq %03u: %08x %08x %08x %08x",
			wr_idx, data[0U], data[1U], data[2U], data[3U]);
	}
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
}

void hvgr_mmu_eventq_print(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_buf *eventq_buf = &gdev->mem_dev.eventq_buf;
	struct hvgr_mmu_event_info *event_array = NULL;
	uint32_t *data = NULL;
	unsigned long flags;
	uint32_t eventq_cons;
	uint32_t rd_idx;
	uint32_t i;

	spin_lock_irqsave(&gdev->mem_dev.mmu_hw_lock, flags);
	event_array = eventq_buf->kva;
	eventq_cons = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS));
	rd_idx = mmu_eventq_get_idx(eventq_cons);

	hvgr_debug(gdev, HVGR_MEM, "dump eventq MMU_EVENTQ_PROD: 0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_PROD)));
	hvgr_debug(gdev, HVGR_MEM, "dump eventq MMU_EVENTQ_CONS: 0x%08x", eventq_cons);

	/* cur pointor no need print */
	for (i = 0U; i < MMU_EVENTQ_BUFFER_PRINT_CNT; i++) {
		rd_idx = hvgr_mmu_buffer_get_last_idx(rd_idx, MMU_BUFFER_EVENTQ);
		data = (uint32_t *)&event_array[rd_idx];
		hvgr_debug(gdev, HVGR_MEM, "dump eventq %03u: %08x %08x %08x %08x %08x %08x %08x %08x",
			rd_idx, data[0U], data[1U], data[2U], data[3U], data[4U], data[5U], data[6U], data[7U]);
	}
	spin_unlock_irqrestore(&gdev->mem_dev.mmu_hw_lock, flags);
}

bool hvgr_mmu_buffer_is_need_print(struct hvgr_device * const gdev)
{
	uint32_t eventq_prod;
	uint32_t wr_idx;
	uint32_t w_wrap;

	eventq_prod = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_PROD));
	wr_idx = mmu_eventq_get_idx(eventq_prod);
	w_wrap = mmu_eventq_get_wrap(eventq_prod);
	if (wr_idx > 0U || w_wrap != 0U)
		return true;

	hvgr_debug(gdev, HVGR_MEM, "no need dump cmdq and eventq");
	hvgr_debug(gdev, HVGR_MEM, "dump cmdq MMU_CMDQ_PROD: 0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_PROD)));
	hvgr_debug(gdev, HVGR_MEM, "dump cmdq MMU_CMDQ_CONS: 0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_CONS)));
	hvgr_debug(gdev, HVGR_MEM, "dump eventq MMU_EVENTQ_PROD: 0x%08x", eventq_prod);
	hvgr_debug(gdev, HVGR_MEM, "dump eventq MMU_EVENTQ_CONS: 0x%08x",
		hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_CONS)));

	return false;
}

int hvgr_mmu_init(struct hvgr_device * const gdev)
{
	int ret;

	spin_lock_init(&gdev->mem_dev.cmdq_bitmap_lock);
	bitmap_zero(gdev->mem_dev.cmdq_bitmap, MMU_CMDQ_MAX_CNT);
	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.cd_buf, MMU_BUFFER_CD);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cd init failed");
		return ret;
	}

	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.cmdq_buf, MMU_BUFFER_CMDQ);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cmdq init failed");
		hvgr_mmu_buffer_free(&gdev->mem_dev.cd_buf);
		return ret;
	}

	ret = hvgr_mmu_buffer_init(gdev, &gdev->mem_dev.eventq_buf, MMU_BUFFER_EVENTQ);
	if (ret != 0) {
		hvgr_err(gdev, HVGR_MEM, "mmu cmdq eventq failed");
		hvgr_mmu_buffer_free(&gdev->mem_dev.cd_buf);
		hvgr_mmu_buffer_free(&gdev->mem_dev.cmdq_buf);
		return ret;
	}

	hvgr_info(gdev, HVGR_MEM, "mmu init ok");

	return 0;
}

void hvgr_mmu_term(struct hvgr_device * const gdev)
{
	struct hvgr_mmu_fault_worker *mmu_as = NULL;
	uint32_t i;

	for (i = 0; i < MMU_ADDR_SPACE_MAX; i++) {
		mmu_as = &gdev->mem_dev.mmu_as[i];
		if (unlikely(!mmu_as->fault_wq)) {
			hvgr_err(gdev, HVGR_MEM, "mmu_as:%u faultq is null", i);
			continue;
		}
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0))
		destroy_workqueue(mmu_as->fault_wq);
#else
		kthread_destroy_worker(mmu_as->fault_wq);
#endif
		mmu_as->fault_wq = NULL;
	}

	hvgr_mmu_buffer_free(&gdev->mem_dev.cd_buf);
	hvgr_mmu_buffer_free(&gdev->mem_dev.cmdq_buf);
	hvgr_mmu_buffer_free(&gdev->mem_dev.eventq_buf);

	hvgr_info(gdev, HVGR_MEM, "mmu term ok");
	return;
}

int hvgr_mmu_global_reg_init(struct hvgr_device * const gdev)
{
	uint64_t phys_cd, phys_cmdq, phys_eventq;
	uint32_t mmu_sh = 0;
	uint32_t mmu_pbha = 0;
	uint32_t mmu_attr = 0;
	struct page *page;
	uint32_t mmu_cr0;

	/* non cacheable */
	mmu_attr = 0xcc;

	/* refer to v300, only set in HVGR_FEATURE_SYSTEM_CACHE */
	mmu_pbha = 0;

	/* cd global reg */
	page = gdev->mem_dev.cd_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_cd = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_CFG),
		mmu_cd_set_memattr(mmu_attr) | mmu_cd_set_sh(mmu_sh) | mmu_cd_set_pbha(mmu_pbha));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_BASE_L),
		mmu_set_base_l(phys_cd) | mmu_set_log2size(MMU_CD_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CD_BASE_H),
		mmu_set_base_h(phys_cd));

	/* cmdq global reg */
	page = gdev->mem_dev.cmdq_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_cmdq = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_BASE_L),
		mmu_set_base_l(phys_cmdq) | mmu_set_log2size(MMU_CMDQ_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CMDQ_BASE_H),
		mmu_set_base_h(phys_cmdq));

	/* eventq global reg */
	page = gdev->mem_dev.eventq_buf.buf_page;
	if (page == NULL)
		return -1;

	phys_eventq = page_to_phys(page);
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_BASE_L),
		mmu_set_base_l(phys_eventq) | mmu_set_log2size(MMU_EVENTQ_LOG2SIZE));

	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_EVENTQ_BASE_H),
		mmu_set_base_h(phys_eventq));

	/* CR1 */
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CR1),
		mmu_cr1_set_queue_pbha(mmu_pbha) | mmu_cr1_set_queue_sh(mmu_sh) | mmu_cr1_set_queue_memattr(mmu_attr));

	/* CR0 */
	mmu_cr0 = hvgr_read_reg(gdev, mmu_control_reg(gdev, MMU_CR0));
	mmu_cr0 |= mmu_cr0_set_memattr_bitmap(0xff) | MMU_CR0_EVENT_GRANULE_ASID
		| MMU_CR0_STE_VALID;
	hvgr_write_reg(gdev, mmu_control_reg(gdev, MMU_CR0), mmu_cr0);

	return 0;
}

void hvgr_mmu_fault_clear_as(struct hvgr_device * const gdev, uint32_t asid)
{
	(void)hvgr_mmu_cmdq_tlb_invalid_asid(NULL, gdev, asid);
}
