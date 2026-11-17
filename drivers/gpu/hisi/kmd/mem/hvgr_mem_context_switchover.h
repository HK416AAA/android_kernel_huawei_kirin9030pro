/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2021-2022. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#ifndef HVGR_MEM_CONTEXT_SWITCHOVER_H
#define HVGR_MEM_CONTEXT_SWITCHOVER_H

#define HVGR_CTX_SW_TO_FRONT        0
#define HVGR_CTX_SW_TO_BACKGROUND   1
#define HVGR_CTX_SW_INIT_GPU_SIZE   2
#define HVGR_CTX_SW_CLEAR_POOLS     3

#define HVGR_SW_OPER_SUCCESS                  0
#define HVGR_SW_OPER_FAILED                  (-1)
#define HVGR_SW_OPER_FAILED_NEED_CLOSE_CTX   (-2)
#define HVGR_SW_IN_ALLOC_SW_FAIL             (-3)
#define HVGR_SW_IN_ALLOC_PAGES_FAIL          (-4)
#define HVGR_SW_IN_PAGE_UNMATCH_FAIL         (-5)
#define HVGR_SW_IN_ALLOC_PAGE_UNMAP          (-6)
#define HVGR_SW_IN_PAGE_FAIL                 (-7)
#define HVGR_SW_IN_MMU_SETUP_FAIL            (-8)

#define HVGR_SWAP_FRONT_CPU                  "CPU_PAGE_FAULT"
#define HVGR_SWAP_FRONT_GPU                  "GPU_PAGE_FAULT"
#define HVGR_SWAP_FRONT_MMAP                 "MMAP"
#define HVGR_SWAP_FRONT_IOCTL                "IOCTL"

#define BATCH_SWAP_SIZE                     (8192U)
#define GPU_SWAP_MAX_PAGE                   (0x4000U)
#define BATCH_SWAP_MAX_PAGE                 (GPU_SWAP_MAX_PAGE >> 1U)

#include "hvgr_defs.h"

#ifdef CONFIG_LIBLINUX
long hvgr_switch_to_frontground(struct hvgr_ctx * const ctx, pid_t tgid);
long hvgr_switch_to_background(struct hvgr_ctx * const ctx,
	hvgr_ioctl_para_ctx_sw * const para);
void hvgr_switch_close_ctx(struct hvgr_ctx * const sw_ctx);
uint32_t hvgr_switch_get_ctx_pages(struct hvgr_ctx *ctx);
void hvgr_switch_free_swapped_area(struct hvgr_mem_area * const area);
enum context_swtich_status hvgr_switch_get_status(struct hvgr_ctx *ctx);
long hvgr_switch_clear_pools(struct hvgr_ctx * const ctx, pid_t tgid);
long hvgr_switch_try_to_foreground(struct hvgr_ctx * const ctx, pid_t tgid, char *caller_api);
#ifdef HVGR_FEATURE_SWAP_PF
long hvgr_switch_area_swap_in(struct hvgr_ctx *ctx, struct hvgr_mem_area *area, bool need_flush);
#endif
#endif
#endif
