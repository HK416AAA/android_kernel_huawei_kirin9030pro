/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: indicator agent for indicator light display and interact
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "indicator_agent.h"
#include <linux/mutex.h>

static struct indicator_ctrl *g_indicator_ctrl = NULL;
static struct indicator_drv_t *g_indicator_drv = NULL;

static DEFINE_MUTEX(g_indicator_agent_lock);

static int check_data(struct indicator_ctrl *trans_ctrl)
{
	if (trans_ctrl == NULL) {
		tloge("get agent buffer failed\n");
		return -1;
	}

	if (trans_ctrl->magic != TEE_INDICATOR_AGENT_ID) {
		tloge("check magic error, now is 0x%x\n", trans_ctrl->magic);
		return -1;
	}

	return 0;
}

static void handle_cmd(void)
{
	switch (g_indicator_ctrl->cmd) {
	case LAYER_ADD:
		tlogd("adding indicator layer\n");
		g_indicator_ctrl->ret = g_indicator_drv->init_func(INDICATOR_SCENE);
		break;
	case LAYER_DEL:
		tlogd("deleting indicator layer\n");
		g_indicator_ctrl->ret = g_indicator_drv->init_func(INDICATOR_CLOSE);
		break;
	default:
		tloge("cmd not supported 0x%x\n", g_indicator_ctrl->cmd);
		g_indicator_ctrl->ret = -1;
		break;
	}
}

static int indicator_agent_work(struct tee_agent_kernel_ops *agent_instance)
{
	struct indicator_ctrl *trans_ctrl = NULL;

	if (agent_instance == NULL || agent_instance->agent_buff == NULL || agent_instance->agent_buff_size != PAGE_SIZE) {
		tloge("agent buff invalid\n");
		return -1;
	}

	mutex_lock(&g_indicator_agent_lock);
	trans_ctrl = (struct indicator_ctrl *)agent_instance->agent_buff;
	if (check_data(trans_ctrl) != 0) {
		trans_ctrl->ret = TEEC_ERROR_BAD_FORMAT;
		mutex_unlock(&g_indicator_agent_lock);
		return -1;
	}

	if (g_indicator_ctrl == NULL) {
		g_indicator_ctrl = kzalloc(agent_instance->agent_buff_size, GFP_KERNEL);
		if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)g_indicator_ctrl)) {
			tloge("memory alloc failed\n");
			g_indicator_ctrl = NULL;
			trans_ctrl->ret = TEEC_ERROR_OUT_OF_MEMORY;
			mutex_unlock(&g_indicator_agent_lock);
			return -ENOMEM;
		}
	}

	if (memcpy_s((void *)g_indicator_ctrl, agent_instance->agent_buff_size,
		(void *)trans_ctrl, sizeof(struct indicator_ctrl)) != EOK) {
		tloge("memcpy_s failed\n");
		goto free;
	}

	if (g_indicator_drv == NULL)
		goto free;
	if (g_indicator_drv->init_func == NULL)
		goto free;
	handle_cmd();

	/* trans ret to TEE */
	if (memcpy_s((void *)trans_ctrl, agent_instance->agent_buff_size,
		(void *)g_indicator_ctrl, sizeof(struct indicator_ctrl)) != EOK) {
		tloge("memcpy_s failed\n");
		goto free;
	}

	mutex_unlock(&g_indicator_agent_lock);
	return 0;
free:
	kfree(g_indicator_ctrl);
	g_indicator_ctrl = NULL;
	trans_ctrl->ret = TEEC_ERROR_GENERIC;
	mutex_unlock(&g_indicator_agent_lock);
	return -1;
}

static int indicator_agent_exit(struct tee_agent_kernel_ops *agent_instance)
{
	(void)agent_instance;
	tloge("indicator agent is exit is being invoked\n");

	mutex_lock(&g_indicator_agent_lock);
	if (g_indicator_ctrl != NULL) {
		kfree(g_indicator_ctrl);
		g_indicator_ctrl = NULL;
	}
	mutex_unlock(&g_indicator_agent_lock);

	return 0;
}

static int indicator_agent_crash_work(
	struct tee_agent_kernel_ops *agent_instance,
	struct tc_ns_client_context *context, unsigned int dev_file_id)
{
	(void)agent_instance;
	(void)context;
	(void)dev_file_id;

	mutex_lock(&g_indicator_agent_lock);
	if (g_indicator_ctrl != NULL) {
		kfree(g_indicator_ctrl);
		g_indicator_ctrl = NULL;
	}
	mutex_unlock(&g_indicator_agent_lock);
	return 0;
}

static struct tee_agent_kernel_ops g_indicator_agent_ops = {
	.agent_name = "indicator",
	.agent_id = TEE_INDICATOR_AGENT_ID,
	.tee_agent_init = NULL,
	.tee_agent_work = indicator_agent_work,
	.tee_agent_exit = indicator_agent_exit,
	.tee_agent_crash_work = indicator_agent_crash_work,
	.agent_buff_size = PAGE_SIZE,
	.list = LIST_HEAD_INIT(g_indicator_agent_ops.list)
};

int register_indicator_agent(void)
{
	tee_agent_kernel_register(&g_indicator_agent_ops);
	return 0;
}
EXPORT_SYMBOL(register_indicator_agent);

/* DSS driver call when screen on */
int register_indicator_driver(notify_dpu fun, void *pdata)
{
	(void)pdata;
	/* Return error if func is invalid */
	if (fun == NULL) {
		tloge("func is null");
		return -EINVAL;
	}

	mutex_lock(&g_indicator_agent_lock);
	/* Allocate memory for g_indicator_drv */
	if (g_indicator_drv == NULL) {
		g_indicator_drv = kzalloc(sizeof(struct indicator_drv_t), GFP_KERNEL);
		if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)g_indicator_drv)) {
			g_indicator_drv = NULL;
			tloge("memory alloc failed\n");
			mutex_unlock(&g_indicator_agent_lock);
			return -ENOMEM;
		}
	}

	if (memset_s(g_indicator_drv, sizeof(struct indicator_drv_t), 0, sizeof(struct indicator_drv_t)) != 0) {
		tloge("g_indicator_drv memset failed");
		kfree(g_indicator_drv);
		g_indicator_drv = NULL;
		mutex_unlock(&g_indicator_agent_lock);
		return -1;
	}
	/* Assign content for g_indicator_drv */
	g_indicator_drv->init_func = fun;
	mutex_unlock(&g_indicator_agent_lock);
	return 0;
}
EXPORT_SYMBOL(register_indicator_driver);

/* DSS driver call when screen off */
void unregister_indicator_driver(void)
{
	mutex_lock(&g_indicator_agent_lock);
	if (g_indicator_drv != NULL) {
		kfree(g_indicator_drv);
		g_indicator_drv = NULL;
	}
	mutex_unlock(&g_indicator_agent_lock);
}
EXPORT_SYMBOL(unregister_indicator_driver);