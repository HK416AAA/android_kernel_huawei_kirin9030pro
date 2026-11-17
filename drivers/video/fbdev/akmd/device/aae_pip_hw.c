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

#include <linux/of_irq.h>
#include <aae/soc_dpu_define.h>
#include <aae/soc_aae_interface.h>
#include <aae/soc_aae_define.h>
#include <ukmd_cmdlist.h>
#include "aae_pip_hw.h"
#include "aae_cmdlist.h"
#include "aae_manager.h"
#include "aae_isr.h"
#include "aae_dev_config.h"
#include "akmd_log.h"
#include "ukmd_utils.h"
#include "cmdlist_interface.h"
#include "aae_cmdlist_cfg_prepare.h"
#include "aae_res_mgr.h"
#include "aae_exp.h"

static int32_t aae_pip_isr_notify(struct notifier_block *self, unsigned long action, void *data)
{
	struct ukmd_listener_data *listener_data = (struct ukmd_listener_data *)data;
	struct aae_pipeline_sw *pip_sw = (struct aae_pipeline_sw *)(listener_data->data);

	if ((action & WCH_FRM_END_INTS) == WCH_FRM_END_INTS) {
		if (pip_sw->wb_committed == 1) {
			pip_sw->wb_done = 1;
			wake_up_interruptible_all(&pip_sw->wb_wq);
		}
	}

	return 0;
}

static void enable_aae_dacc_isr(struct aae_pipeline_sw *pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	struct ukmd_isr *isr_ctrl = &pip->isr_ctrl;

	/* enable irq */
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_ENABLE);
}

static void disable_aae_dacc_isr(struct aae_pipeline_sw *pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	struct ukmd_isr *isr_ctrl = &pip->isr_ctrl;
	/* disable irq */
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_DISABLE);
}

static void aae_hw_exp_handler(struct work_struct *work)
{
	struct aae_pipeline_sw *pip_sw = NULL;
	pip_sw = container_of(work, struct aae_pipeline_sw, aae_exp_work);
	aae_check_and_no_retval(!pip_sw, err, "pip_sw is null!");
	aae_exp_handle(pip_sw->aae_mgr);
}

static void aae_exp_wq_handler(struct aae_pipeline_sw *pip_sw, bool setup)
{
	if (setup) {
		pip_sw->aae_exp_wq = create_singlethread_workqueue("aae_exp_wq");
		if (pip_sw->aae_exp_wq  == NULL) {
			aae_pr_err("create aae_exp_wq failed");
			return;
		}
		INIT_WORK(&pip_sw->aae_exp_work, aae_hw_exp_handler);
	} else {
		if (pip_sw->aae_exp_wq != NULL) {
			destroy_workqueue(pip_sw->aae_exp_wq);
			pip_sw->aae_exp_wq = NULL;
		}
	}
}

static struct notifier_block aae_pip_isr_notifier = {
	.notifier_call = aae_pip_isr_notify,
};

void aae_pip_isr_enable(struct aae_pipeline_sw *pip_sw)
{
	uint32_t mask = ~0;
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	struct ukmd_isr *isr_ctrl = &pip->isr_ctrl;
	char __iomem *aae_base = pip_sw->aae_mgr->aae_base;

	/* 1. interrupt mask */
	set_reg(aae_base + 0x40104 + pip_sw->index * 0x8, 1, 1, 2); // AAE_NS_OFFLINE0_TO_GIC_MSK
	outp32(aae_base + 0x40214 + pip_sw->index * 0x8, mask); // rot_wdma_ns_int_o_mask

	/* 2. enable irq */
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_ENABLE);

	/* 3. interrupt clear */
	outp32(aae_base + 0x40100 + pip_sw->index * 0x8, AAE_ROT_WDMA_NS_INT); // AAE_NS_OFFLINE0_TO_GIC_O
	outp32(aae_base + 0x40210 + pip_sw->index * 0x8, mask); // rot_wdma_ns_int_o

	/* 4. interrupt umask */
	set_reg(aae_base + 0x40104 + pip_sw->index * 0x8, 0, 1, 2); // AAE_NS_OFFLINE0_TO_GIC_MSK
	outp32(aae_base + 0x40214 + pip_sw->index * 0x8, ~(WCH_FRM_END_INTS));
}

void aae_pip_isr_disable(struct aae_pipeline_sw *pip_sw)
{
	uint32_t mask = ~0;
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	struct ukmd_isr *isr_ctrl = &pip->isr_ctrl;
	char __iomem *aae_base = pip_sw->aae_mgr->aae_base;

	/* 1. interrupt mask */
	set_reg(aae_base + 0x40104 + pip_sw->index * 0x8, 1, 1, 2); // AAE_NS_OFFLINE0_TO_GIC_MSK
	outp32(aae_base + 0x40214 + pip_sw->index * 0x8, mask); // rot_wdma_ns_int_o_mask

	/* 2. disable irq */
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_DISABLE);
}

static irqreturn_t aae_pip_isr(int32_t irq, void *ptr)
{
	uint32_t isr1_offline_glb_state = 0;
	uint32_t isr2_offline_state = 0;
	struct ukmd_isr *isr_ctrl = (struct ukmd_isr *)ptr;
	struct aae_pipeline_sw *pip_sw = NULL;
	char __iomem *aae_base;

	aae_check_and_return(!isr_ctrl, IRQ_NONE, err, "isr_ctrl is null!");

	pip_sw = (struct aae_pipeline_sw *)isr_ctrl->parent;
	aae_check_and_return(!pip_sw, IRQ_NONE, err, "pip_sw is null!");
	aae_check_and_return(!(pip_sw->aae_mgr), IRQ_NONE, err, "aae_mgr is null!");
	aae_base = pip_sw->aae_mgr->aae_base;
	aae_check_and_return(!aae_base, IRQ_NONE, err, "aae_base is null!");
	/**
	 * @brief What scene decided to read the information according to the configuration of offline compose
	 *
	 */
	isr1_offline_glb_state = inp32(aae_base + 0x40100 + pip_sw->index * 0x8); // AAE_NS_OFFLINE0_TO_GIC_O
	if ((isr1_offline_glb_state & AAE_ROT_WDMA_NS_INT) == AAE_ROT_WDMA_NS_INT) {
		// ROT_WDMA_NS_INT_O
		isr2_offline_state = inp32(aae_base + 0x40210);
		outp32(aae_base + 0x40210, isr2_offline_state);

		if ((isr2_offline_state & WCH_BLK_END_INTS) == WCH_BLK_END_INTS)
			ukmd_isr_notify_listener(isr_ctrl, WCH_BLK_END_INTS);
	}

	outp32(aae_base + 0x40100 + pip_sw->index * 0x8, isr1_offline_glb_state);
	aae_pr_info("isr1_offline_glb_state=%#x isr2_offline_state=%#x", isr1_offline_glb_state, isr2_offline_state);
	if ((isr2_offline_state & WCH_FRM_END_INTS) == WCH_FRM_END_INTS)
		ukmd_isr_notify_listener(isr_ctrl, WCH_FRM_END_INTS);

	if ((isr1_offline_glb_state & AAE_DACC_NS_INT) == AAE_DACC_NS_INT) {
		// DACC_NS_INT_O
		isr2_offline_state = inp32(AAE_GLB_PART0_DACC_NS_INT_O_ADDR(aae_base + AAE_GLB0_OFFSET));
		aae_pr_info("dacc isr handle, isr2_offline_state=%#x!", isr2_offline_state);
		outp32(AAE_GLB_PART0_DACC_NS_INT_O_ADDR(aae_base + AAE_GLB0_OFFSET), isr2_offline_state);
		if ((isr2_offline_state & (WDT_RST_NS_INTS)) == WDT_RST_NS_INTS) {
			aae_pr_err("wdt isr occurs, aae exception handle!");
			mask_aae_dacc_isr(aae_base);
			if (pip_sw->aae_exp_wq != NULL)
				queue_work(pip_sw->aae_exp_wq, &(pip_sw->aae_exp_work));
		}
	}

	return IRQ_HANDLED;
}

static uint32_t aae_pip_isr_get_unmask(void)
{
	return ~(AAE_ROT_WDMA_NS_INT | AAE_DACC_NS_INT);
}

void aae_pip_isr_setup(struct aae_pipeline_sw *pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	
	aae_pr_debug("+");
	aae_isr_init((void *)pip_sw, &pip->isr_ctrl,
		pip->pip_irq, "aae_pip_irq", aae_pip_isr_get_unmask(), aae_pip_isr);
	list_add_tail(&pip->isr_ctrl.list_node, &pip_sw->aae_mgr->isr_list);
	ukmd_isr_register_listener(&pip->isr_ctrl, &aae_pip_isr_notifier, WCH_FRM_END_INTS, pip);
	ukmd_isr_register_listener(&pip->isr_ctrl, &aae_pip_isr_notifier, WCH_BLK_END_INTS, pip);
	aae_exp_wq_handler(pip_sw, true);
	enable_aae_dacc_isr(pip_sw);
	aae_pr_debug("-");
}

void aae_pip_isr_release(struct aae_pipeline_sw *pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	disable_aae_dacc_isr(pip_sw);
	aae_exp_wq_handler(pip_sw, false);
	aae_pip_isr_disable(pip_sw);
	ukmd_isr_unregister_listener(&pip->isr_ctrl, &aae_pip_isr_notifier, WCH_FRM_END_INTS);
	ukmd_isr_unregister_listener(&pip->isr_ctrl, &aae_pip_isr_notifier, WCH_BLK_END_INTS);
	list_del(&pip->isr_ctrl.list_node);
	pip->isr_ctrl.handle_func(&pip->isr_ctrl, UKMD_ISR_RELEASE);
}

void aae_pip_hw_setup(struct aae_pipeline_sw *pip_sw)
{
	uint32_t cmdlist_dev_id;
	struct aae_pipeline *pip;

	aae_assert(!pip_sw);
	aae_assert(!pip_sw->aae_mgr);

	pip = (struct aae_pipeline *)pip_sw;
	cmdlist_dev_id = CMDLIST_DEV_ID_AAE;

	if (pip->init_cmdlist_id == INVALID_CMDLIST_ID) {
		/* 1. request initialize cmdlist scene id */
		pip->init_cmdlist_id = build_ch7_cmdlist();
	} else {
		cmdlist_flush_client(cmdlist_dev_id, DPU_SCENE_INITAIL, pip->init_cmdlist_id);
	}

	aae_cmdlist_init_commit(pip_sw->aae_mgr->aae_base,
		ukmd_cmdlist_get_dma_addr(cmdlist_dev_id, DPU_SCENE_INITAIL, pip->init_cmdlist_id));
	aae_sdma_load_balance_config(pip_sw->aae_mgr->aae_base);
}

int32_t aae_pip_hw_parse_dt(struct aae_pipeline_sw *pip_sw, struct device_node *np)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	aae_assert(!pip);

	pip->pip_irq = of_irq_get(np, 0);
	aae_pr_info("pip_irq=%d", pip->pip_irq);
	return 0;
}

int32_t aae_pip_hw_init(struct aae_pipeline_sw **pip_sw)
{
	struct aae_pipeline *pip = kzalloc(sizeof(*pip), GFP_KERNEL);
	if (unlikely(!pip)) {
		aae_pr_err("alloc aae_pipeline fail");
		return -ENOMEM;
	}

	pip->init_cmdlist_id = INVALID_CMDLIST_ID;
	*pip_sw = &pip->pip_sw;
	
	return 0;
}

void aae_pip_hw_deinit(struct aae_pipeline_sw **pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)(*pip_sw);
	if (unlikely(!pip)) {
		aae_pr_err("aae_pipeline is NULL");
		return;
	}

	kfree(pip);
	*pip_sw = NULL;
}

void aae_pip_hw_close(struct aae_pipeline_sw *pip_sw)
{
	struct aae_pipeline *pip = (struct aae_pipeline *)pip_sw;
	aae_assert(!pip);

	ukmd_cmdlist_release_locked(CMDLIST_DEV_ID_AAE, DPU_SCENE_INITAIL, pip->init_cmdlist_id);
	pip->init_cmdlist_id = INVALID_CMDLIST_ID;
}