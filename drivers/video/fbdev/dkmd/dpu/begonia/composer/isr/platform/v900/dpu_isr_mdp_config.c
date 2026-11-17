/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/ktime.h>
#include <linux/of_irq.h>
#include <linux/kernel.h>
#include <dpu/soc_dpu_define.h>
#include "ukmd_listener.h"
#include "dpu_comp_mgr.h"
#include "dpu_isr.h"
#include "dpu_isr_mdp.h"
#include "effect/dpu_effect_init.h"
#include "dpu_mntn.h"
#include "dpu_dacc_log_read.h"

static void dpu_update_dfr_base_timestamp(char __iomem *dpu_base, uint64_t current_time, uint32_t isr2_state)
{
	bool is_mismatch = false;
	uint32_t base_timestamp_low;
	uint32_t base_timestamp_high;
 
	base_timestamp_high = (current_time >> 32) & (0xFFFFFFFF);
	base_timestamp_low = current_time & (0xFFFFFFFF);
	outp32(DFR_BASE_TIMESTAMP_LOW32(dpu_base), base_timestamp_low);
	outp32(DFR_BASE_TIMESTAMP_HIGH32(dpu_base), base_timestamp_high);
	if (isr2_state & MISMATCH_TE)
		is_mismatch = true;
	dpu_pr_debug("frmId=%u misFLag=%u, update base timestamp=%llu, low_32=%u ,vsync_high=%u ",
		((inp32(DFR_MISMATCHED_FRAME_INFO_DISPLAYED(dpu_base))& 0xFFFFFFFC) >> 2) , is_mismatch,
		current_time, base_timestamp_low, base_timestamp_high);
 
	/* bit0-bit1: timestamp type(0: disable  1:absolute time 2:relative Time);
	bit2-bit31: displayed frm idx corresponding expected timestamp */
	outp32(DFR_MISMATCHED_FRAME_INFO_DISPLAYED(dpu_base), 0);
}

void dpu_mdp_ddic_isr_handler(char __iomem *dpu_base, struct composer_manager *comp_mgr)
{
	uint32_t ddic_isr;
	struct dpu_composer *dpu_comp = comp_mgr->dpu_comps[DEVICE_COMP_PRIMARY_ID];
	if (!dpu_comp)
		return;

	ddic_isr = inp32(DPU_GLB_DDIC_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET));
	outp32(DPU_GLB_DDIC_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET), ddic_isr);
	dpu_pr_debug("isr1 intr:%#x", ddic_isr);
	if (ddic_isr & DDIC_IRC_INT) {
		mdfx_trace_point("dpu_irq", "DDIC_IRC_INT");
		kthread_queue_work(&dpu_comp->effect_worker, &dpu_comp->ddic_work);
	}
}

static void dpu_mdp_dacc_async_tx_isr_handler(struct composer_manager *comp_mgr)
{
	uint32_t comp_idx = 0;
	struct dpu_composer *dpu_comp = NULL;

	comp_idx = read_reg_with_retry(DPU_ASYNC_TX_REL_SCENE_ADDR(comp_mgr->dpu_base));
	if (likely(comp_idx <= DEVICE_COMP_BUILTIN_ID)) {
		dpu_comp = comp_mgr->dpu_comps[comp_idx];

		if (unlikely(dpu_comp == NULL)) {
			dpu_pr_err("comp_idx %u corrsponding to dpu_comp is NULL", comp_idx);
             return;
        }

		if (unlikely(dpu_comp->conn_info == NULL)) {
			dpu_pr_err("comp_idx %u corrsponding to conn_info is NULL", comp_idx);
             return;
        }

		dpu_pr_debug("dacc report comp_idx %u have finshed async tx task", comp_idx);
		pipeline_next_ops_handle(dpu_comp->conn_info->conn_device, dpu_comp->conn_info, CMDS_ASYNC_TX_DONE, NULL);
	} else {
		dpu_pr_err("dacc report comp_idx %u in invalid for async tx", comp_idx);
	}
}

static bool has_vsync_registered(struct composer_manager *comp_mgr)
{
	if (unlikely(!comp_mgr)) {
		dpu_pr_warn("not exist comp_mgr");
		return false;
	}

	if (comp_mgr->dpu_comps[DEVICE_COMP_BUILTIN_ID] == NULL ||
		!composer_manager_get_scene_switch(comp_mgr->dpu_comps[DEVICE_COMP_BUILTIN_ID]))
		return true;

	/* Check whether the vsync listener has been registered. */
	if (comp_mgr->dpu_comps[DEVICE_COMP_BUILTIN_ID]->comp_scene_id == DPU_SCENE_ONLINE_1)
		return comp_mgr->dpu_comps[DEVICE_COMP_PRIMARY_ID]->has_dfr_related_listener_registered;
	else
		return comp_mgr->dpu_comps[DEVICE_COMP_PRIMARY_ID]->has_dfr_related_listener_registered ||
			comp_mgr->dpu_comps[DEVICE_COMP_BUILTIN_ID]->has_dfr_related_listener_registered;
}

void dpu_mdp_dacc_isr_handler(char __iomem *dpu_base, struct ukmd_isr *isr_ctrl)
{
	uint64_t current_time;
	struct composer_manager *comp_mgr = NULL;
	uint8_t power_status = 0;
	uint32_t isr2_state = inp32(DPU_GLB_DACC_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET));
#ifdef CONFIG_DKMD_DPU_TUNNEL_DEVICE_PRESENT
	if (((isr2_state & (VALID_VSYNC | COUNT_VSYNC)) != 0)) {
		dpu_pr_debug("report tunnel vsync");
		ukmd_isr_notify_listener(isr_ctrl, NOTIFY_TUNNEL_VSYNC);
	}
#endif
	outp32(DPU_GLB_DACC_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET), isr2_state);
	dpu_check_and_no_retval(!isr_ctrl, err, "isr ctrl is null");

	current_time = (uint64_t)ktime_to_ns(ktime_get());
	dpu_pr_debug("isr2 intr:%#x, cur_time = %llu ns", isr2_state, current_time);
	/**
     * isr intr:
     * 0x2: valid vsync, need to report vsync and count fps
     * 0x8: count vysnc, need to report vsync
     * 0x10: self refresh, need to count fps
     * 0x20: only dimming done, need to update dimming done flag
     * 0x18: vsync and self refresh, need to report vsync and count fps
     * 0x28: vsync and dimming done, need to report vsync and update dimming done flag
     * 0x38: vsync and self refresh, dimming done, need to report vsync and update dimming done flag
     * 0x400: dacc send ppc cmdlist done
	 * 0x2000: async tx done, report mipi dsi async cmdlist task have finished
	 * 0x4000: dacc log
     **/
	if (isr2_state & (ISR_PPC_DONE)) {
		dpu_pr_info("ppc done");
		ukmd_isr_notify_listener(isr_ctrl, NOTIFY_PPC_DONE);
	}
	if (isr2_state & (VALID_VSYNC | COUNT_VSYNC) && has_vsync_registered(isr_ctrl->parent)) {
		dpu_pr_debug("report vsync, cur_time = %lld ms", ktime_to_ms(ktime_get()));
		ukmd_isr_notify_listener(isr_ctrl, NOTIFY_BOTH_VSYNC_TIMELINE);
	}
	if (isr2_state & (VALID_VSYNC | SELF_REFRESH) && has_vsync_registered(isr_ctrl->parent)) {
		dpu_pr_debug("%s, cur_time = %lld ms", (isr2_state & VALID_VSYNC) == VALID_VSYNC ? "send frame" : "self refresh",
			ktime_to_ms(ktime_get()));
		/* fps count only for LTPO screen */
		ukmd_isr_notify_listener(isr_ctrl, NOTIFY_REFRESH);
		dpu_update_dfr_base_timestamp(dpu_base, current_time, isr2_state);
	}
	if (isr2_state & (DIMMING_DONE)) {
		comp_mgr = isr_ctrl->parent;
		if (likely(comp_mgr))
			power_status = comp_mgr->power_status.refcount.value[DEVICE_COMP_PRIMARY_ID]
				| comp_mgr->power_status.refcount.value[DEVICE_COMP_BUILTIN_ID];
		if (unlikely(power_status == 0)) {
			dpu_pr_info("already power off");
			return;
		}
		dpu_pr_info("frm rate dimming done, cur_time = %lld ms", ktime_to_ms(ktime_get()));
		ukmd_isr_notify_listener(isr_ctrl, NOTIFY_DIMMING_DONE);
	}
	if (isr2_state & LTM_IHIST_DONE) {
		dpu_pr_debug("riscv have already finished read ihist");
		ukmd_isr_notify_listener(isr_ctrl, LTM_IHIST_DONE);
	}
	if (isr2_state & ASYNC_TX_DONE)
		dpu_mdp_dacc_async_tx_isr_handler(isr_ctrl->parent);

#ifdef CONFIG_DACC_LOG_KMD
	if (isr2_state & (DPU_DACC_LOG_BUF_FULL)) {
		dpu_pr_debug("dacc log irq");
		comp_mgr = isr_ctrl->parent;
		dpu_mdp_dacc_log_isr_handler(comp_mgr); // dacc log
	}
#endif
}

void dpu_mdp_lbuf_isr_handler(char __iomem *dpu_base)
{
	uint32_t isr2_state = inp32(DPU_GLB_LBUF_CMN_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET));
	outp32(DPU_GLB_LBUF_CMN_NS_INT_O_ADDR(dpu_base + DPU_GLB0_OFFSET), isr2_state);

	if (g_debug_dvfs_auto_test_enable == 1) {
		if (isr2_state & BIT(0)) {
			mdfx_trace_point("dpu_irq", "dbuf0 LBUF_CMN_NS_INT");
			dpu_pr_debug("dbuf0 trigger fluex_req, state=0x%x, ctrl=0x%x, fluex_req_bef=0x%x, fluex_req_aft=0x%x",
				inp32(DPU_LBUF_DBUF0_STATE_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF0_CTRL_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_BEF_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF0_THD_FLUX_REQ_AFT_ADDR(dpu_base + DPU_LBUF_OFFSET)));
		}
		if (isr2_state & BIT(1)) {
			mdfx_trace_point("dpu_irq", "dbuf1 LBUF_CMN_NS_INT");
			dpu_pr_debug("dbuf1 trigger fluex_req, state=0x%x, ctrl=0x%x, fluex_req_bef=0x%x, fluex_req_aft=0x%x",
				inp32(DPU_LBUF_DBUF1_STATE_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF1_CTRL_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF1_THD_FLUX_REQ_BEF_ADDR(dpu_base + DPU_LBUF_OFFSET)),
				inp32(DPU_LBUF_DBUF1_THD_FLUX_REQ_AFT_ADDR(dpu_base + DPU_LBUF_OFFSET)));
		}
	}
}

void dkmd_mdp_isr_enable(struct composer_manager *comp_mgr)
{
	uint32_t mask = ~0;
	struct ukmd_isr *isr_ctrl = &comp_mgr->mdp_isr_ctrl;
	char __iomem *dpu_base = comp_mgr->dpu_base;
	uint32_t unmask = ~(DEFAULT_TE | VALID_VSYNC | NORMAL_TE | COUNT_VSYNC | SELF_REFRESH |
		DIMMING_DONE | MISMATCH_TE | LTM_IHIST_DONE | ISR_PPC_DONE | ASYNC_TX_DONE);

	dpu_pr_info("+");

	if (unlikely(!isr_ctrl)) {
		dpu_pr_err("isr_ctrl is null ptr");
		return;
	}

	if (unlikely(!isr_ctrl->handle_func)) {
		dpu_pr_err("isr_ctrl->handle_func is null ptr");
		return;
	}

	/* 1. interrupt mask */
	outp32(DPU_GLB_NS_MDP_TO_GIC_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), mask);
	outp32(DPU_GLB_WCH0_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), mask);

	/* 2. enable irq */
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_ENABLE);

	/* 3. interrupt clear */
	outp32(DPU_GLB_NS_MDP_TO_GIC_O_ADDR(dpu_base + DPU_GLB0_OFFSET), mask);

	/* 4. interrupt umask */
	dpu_pr_info("unmask 0x%x", isr_ctrl->unmask);
	outp32(DPU_GLB_NS_MDP_TO_GIC_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), isr_ctrl->unmask);
	outp32(DPU_GLB_DACC_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), unmask);

	set_reg(DPU_GLB_DDIC_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), 0x1, 2, 0);
	outp32(DPU_GLB_WCH0_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), ~(WCH_FRM_END_INTS));
	outp32(DPU_GLB_LBUF_CMN_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), 0);
#ifdef CONFIG_DACC_LOG_KMD
	set_reg(DPU_GLB_DACC_NS_INT_MSK_ADDR(dpu_base + DPU_GLB0_OFFSET), 0x0, 1,
			DPU_DACC_LOG_ISR_AP_READ); // unmask dacc log irq
#endif

	dpu_pr_info("-");
}
