/* Copyright (c) 2023-2023, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include "dpu_effect_hdr.h"

/* hdr10 or HLG need get hdr_mean value to calc tone mapping curve */
struct dkmd_hdr_ctrl {
	uint32_t hdr_mean;
	spinlock_t hdr_mean_lock;
	char __iomem *hdr_base;
};

void dpu_effect_hdr_set_mean(struct dpu_composer *dpu_comp, uint32_t hdr_mean)
{
	struct dkmd_hdr_ctrl *hdr_ctrl = NULL;
	unsigned long flags = 0;
	dpu_check_and_no_retval(!dpu_comp, err, "dpu_comp is NULL");

	hdr_ctrl = (struct dkmd_hdr_ctrl *)dpu_comp->hdr_ctrl;
	dpu_check_and_no_retval(!hdr_ctrl, err, "hdr_ctrl is NULL");

	spin_lock_irqsave(&hdr_ctrl->hdr_mean_lock, flags);
	hdr_ctrl->hdr_mean = hdr_mean;
	spin_unlock_irqrestore(&hdr_ctrl->hdr_mean_lock, flags);
}

int dpu_effect_hdr_get_mean(struct composer *comp, uint32_t *hdr_mean)
{
	struct dpu_composer *dpu_comp = NULL;
	unsigned long flags = 0;
	struct dkmd_hdr_ctrl *hdr_ctrl = NULL;
	dpu_check_and_return(!comp, -1, err, "comp is null pointer");

	dpu_comp = to_dpu_composer(comp);
	hdr_ctrl = (struct dkmd_hdr_ctrl *)dpu_comp->hdr_ctrl;
	dpu_check_and_return(!hdr_ctrl, -1, err, "hdr_ctrl is null pointer");

	spin_lock_irqsave(&hdr_ctrl->hdr_mean_lock, flags);
	*hdr_mean = hdr_ctrl->hdr_mean;
	spin_unlock_irqrestore(&hdr_ctrl->hdr_mean_lock, flags);

	return 0;
}

int dpu_effect_hdr_get_statistic(struct composer *comp, void __user* argp)
{
	void_unused(comp);
	void_unused(argp);
	return 0;
}

void dpu_effect_hdr_init(struct dpu_composer *dpu_comp, uint32_t hdr_offset)
{
	struct dkmd_hdr_ctrl *hdr_ctrl = NULL;
	char __iomem *dpu_base = NULL;
	dpu_check_and_no_retval(!dpu_comp, err, "dpu_comp is NULL");

	dpu_comp->hdr_ctrl = kzalloc(sizeof(struct dkmd_hdr_ctrl), GFP_KERNEL);
	dpu_check_and_no_retval(!dpu_comp->hdr_ctrl, err, "hdr_ctrl is NULL");

	hdr_ctrl = dpu_comp->hdr_ctrl;
	dpu_base = dpu_comp->comp_mgr->dpu_base;
	hdr_ctrl->hdr_base = dpu_base + hdr_offset;

	spin_lock_init(&hdr_ctrl->hdr_mean_lock);
	hdr_ctrl->hdr_mean = 0;
}

void dpu_effect_hdr_deinit(struct dpu_composer *dpu_comp)
{
	dpu_check_and_no_retval(!dpu_comp, err, "dpu_comp is NULL");
	dpu_check_and_no_retval(!dpu_comp->hdr_ctrl, err, "hdr_ctrl is NULL");

	kfree(dpu_comp->hdr_ctrl);
	dpu_comp->hdr_ctrl = NULL;
}

void dpu_effect_hdr_gtm_queue_work(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}

void dpu_effect_hdr_ltm_queue_work(struct dpu_composer *dpu_comp)
{
	void_unused(dpu_comp);
}