
/* Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "dpu_comp_mgr.h"
#include "tui.h"
#include "dpu_comp_tui.h"
#include "dkmd_tui_interface.h"
#include <linux/workqueue.h>
#include <linux/of_irq.h>

struct workqueue_struct *g_dpu_tui_wq;
struct work_struct g_dpu_tui_isr_work;

static void dpu_tui_notify_work_handler(struct work_struct *work)
{
	struct dpu_secure *secure_ctrl = NULL;
	struct dpu_composer *dpu_comp = NULL;

	dpu_comp = get_active_dpu_comp();
	if (unlikely(!dpu_comp)) {
		dpu_pr_err("dpu_comp is NULL");
		return;
	}

	secure_ctrl = &dpu_comp->secure_ctrl;

	dpu_tui_switch_event(&dpu_comp->comp, USER_EVENT_REFRESH);
	dpu_pr_info("tui_mode[%u]: secure_status = %d, secure_event = %d, tui_request = %d ---", secure_ctrl->tui_mode,
	    secure_ctrl->secure_status, secure_ctrl->secure_event, USER_EVENT_REFRESH);
	return;
}

static int32_t dpu_tui_workqueue_register(void)
{
	g_dpu_tui_wq = create_singlethread_workqueue("dpu_tui_wq");

	dpu_check_and_return(!g_dpu_tui_wq, -EINVAL, err, "g_dpu_tui_wq is NULL");
	INIT_WORK(&g_dpu_tui_isr_work, dpu_tui_notify_work_handler);
	return 0;
}
 
static irqreturn_t dpu_tui_schedule_wq(int32_t irq, void *dev_id)
{
	dpu_pr_info("dpu_secure_notify irq %d", irq);
	queue_work(g_dpu_tui_wq, &g_dpu_tui_isr_work);
	return IRQ_HANDLED;
}

int32_t dpu_tui_irq_register(struct platform_device *pdev)
{
	int32_t ret;
	uint32_t irq_num;

	if (pdev == NULL) {
		dpu_pr_err("dpu_tui_irq_register pdev error");
		return -1;
	}

	irq_num = irq_of_parse_and_map(pdev->dev.of_node, 2);
    if (irq_num == 0) {
        dpu_pr_err("dpu_tui_irq_register irq num %u", irq_num);
        return -1;
    }

	ret = devm_request_irq(&(pdev->dev), irq_num, dpu_tui_schedule_wq, IRQF_NO_SUSPEND, pdev->name, NULL);
	if (ret != 0) {
		dpu_pr_err("devm_request_irq error %u ret = %d", irq_num, ret);
		return -1;
	}

	return dpu_tui_workqueue_register();
}

void dpu_tui_set_allow_tee_rw_reg(bool allow)
{
	void_unused(allow);
}

void dpu_tui_set_power_mode(uint32_t power_type)
{
	void_unused(power_type);
}

void dpu_tui_frame_start_isr_handler(struct dpu_composer *dpu_comp)
{
    void_unused(dpu_comp);
}

bool dpu_tui_no_need_disable_ldi(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
	return true;
}

void dpu_tui_request_frame_update(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);	
}

void dpu_tui_set_lowpower_status(uint32_t user_state)
{
	void_unused(user_state);
}

int32_t dpu_get_tui_level1_layer_info(struct composer *comp, struct tui_level1_layer_info *info)
{
	void_unused(comp);
	void_unused(info);
	return 0;
}