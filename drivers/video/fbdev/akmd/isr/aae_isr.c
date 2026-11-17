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

#include <securec.h>
#include <platform_include/see/ffa/ffa_msg_id.h>
#include <platform_include/see/ffa/ffa_plat_drv.h>
#include "aae_isr.h"
#include "aae_manager.h"
#include "akmd_log.h"
#include "aae_xpu_isr.h"

struct case_xpu_message {
    int32_t msg_type;
    const char *message;
};

static struct case_xpu_message xpu_message_info[] = {
    {MSG_AAE_INIT_SUCCUSS, "aae init succuss"},
    {MSG_AAE_INIT_FAILED, "aae init failed"},
    {MSG_AAE_DEINIT_SUCCESS, "aae deinit succuss"},
    {MSG_AAE_DEINIT_FAILED, "aae deinit failed"},
    {MSG_AAE_DACC_LOAD_FAILED, "dacc load failed"},
    {MSG_AAE_RISCV_START_FAILED, "riscv start failed"},
    {MSG_AAE_TBU_CONNECT_FAILED, "tbu connect failed"},
    {MSG_AAE_TBU_DISCONNECT_FAILED, "tbu disconnect failed"},
    {MSG_AAE_FFTS_DISCONNECT_FAILED, "ffts disconnect failed"},
    {MSG_AAE_CMDLIST_CH7_LOAD_FAILED, "aae cmdlist ch7 load failed"},
    {MSG_NONE, "no msg from xpu"}
};

static int32_t aae_handle_xpu_msg(void)
{
	int32_t ret = -1;
	uint32_t msg_type = 0;
    uint32_t i;
	struct ffa_send_direct_data args = {0};

	args.data0 = FID_BL31_DISPLAY_XPU_AAE_MSG_HANDLE;
	ret = ffa_platdrv_send_msg(&args);
	if (ret) {
		aae_pr_err("send msg to tzsp failed: 0x%x", ret);
		return ret;
	}

	msg_type = args.data1;
	for (i = 0; i < MSG_AAE_MAX_NUM && xpu_message_info[i].msg_type != MSG_NONE; ++i) {
        if (msg_type == xpu_message_info[i].msg_type) {
            aae_pr_info("%s", xpu_message_info[i].message);
            return msg_type;
        }
    }

    aae_pr_err("invalid msg tpye: 0x%x", msg_type);
	return msg_type;
}

void aae_isr_init(void *parent, struct ukmd_isr *isr_ctrl,
	int32_t irq_no, char *irq_name, uint32_t unmask, irqreturn_t (*isr_fnc)(int32_t, void *))
{
	int32_t ret;
	aae_assert(!parent);
	aae_assert(!isr_ctrl);
	aae_assert(!irq_name);
	aae_assert(!isr_fnc);

	ret = snprintf_s(isr_ctrl->irq_name, sizeof(isr_ctrl->irq_name),
		sizeof(isr_ctrl->irq_name) - 1, "%s", irq_name);
	if (ret < 0)
		aae_pr_err("irq_name=%s format string failed", irq_name);

	isr_ctrl->irq_no = irq_no;
	isr_ctrl->isr_fnc = isr_fnc;
	isr_ctrl->parent = parent;
	isr_ctrl->unmask = unmask;
	ukmd_isr_setup(isr_ctrl);
	isr_ctrl->handle_func(isr_ctrl, UKMD_ISR_REQUEST);
}

uint32_t aae_glb_isr_get_unmask(void)
{
	return ~(0);
}

uint32_t aae_xpu_isr_get_unmask(void)
{
	return ~(XPU_AAE_MSG_INTR_UMASK);
}

irqreturn_t aae_glb_isr(int32_t irq, void *ptr)
{
	struct ukmd_isr *isr_ctrl = (struct ukmd_isr *)ptr;
	struct aae_manager *aae_mgr = isr_ctrl->parent;

	aae_check_and_return(!aae_mgr, IRQ_NONE, err, "aae_mgr is null!");

	return IRQ_HANDLED;
}

irqreturn_t aae_xpu_isr(int32_t irq, void *ptr)
{
	int32_t ret = -1;
    struct ukmd_isr *isr_ctrl = (struct ukmd_isr *)ptr;
	struct aae_manager *aae_mgr = isr_ctrl->parent;

	aae_pr_info("+");
	ret = aae_handle_xpu_msg();
	/* udpate xpu aae power status */
	if (ret == MSG_AAE_INIT_SUCCUSS) {
		atomic_inc(&aae_mgr->xpu_aae_power_status);
		aae_pr_info("xpu aae has power on");
	}

	if (ret == MSG_AAE_DEINIT_SUCCESS)
		if (atomic_sub_and_test(1, &aae_mgr->xpu_aae_power_status))
			aae_pr_info("xpu aae has power off");

	if (ret == -1)
		return IRQ_NONE;

	aae_pr_info("-");
	return IRQ_HANDLED;
}

void aae_glb_isr_enable(struct aae_manager *aae_mgr)
{
	struct ukmd_isr *isr_ctrl = &aae_mgr->isr_ctrl;

	aae_pr_info("+");

	aae_assert(!aae_mgr);

	if (unlikely(!isr_ctrl->handle_func)) {
		aae_pr_err("isr_ctrl->handle_func is null ptr");
		return;
	}

	aae_pr_info("-");
}

void aae_glb_isr_disable(struct aae_manager *aae_mgr)
{
	struct ukmd_isr *isr_ctrl = &aae_mgr->isr_ctrl;

	aae_pr_info("+");

	aae_assert(!aae_mgr);

	if (unlikely(!isr_ctrl->handle_func)) {
		aae_pr_err("isr_ctrl->handle_func is null ptr");
		return;
	}

	aae_pr_info("-");
}