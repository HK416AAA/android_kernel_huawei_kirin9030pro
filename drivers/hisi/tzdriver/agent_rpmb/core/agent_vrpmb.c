/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: function for rpmb
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
#include <securec.h>
#include <linux/fs.h>
#include <linux/mmc/ioctl.h> /* for struct mmc_ioc_rpmb */
#include <linux/mmc/card.h>  /* for struct mmc_card */
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/delay.h>
#ifdef CONFIG_CONFIDENTIAL_CONTAINER
#include <linux/proc_ns.h>
#endif
#include <linux/mutex.h>

#include "agent_rpmb.h"
#include "teek_client_constants.h"
#include "agent.h"
#include "tc_ns_log.h"
#include "smc_smp.h"
#include "rpmb_driver.h"
#include "teek_ns_client.h"

static uint8_t *m_rpmb_ctrl = NULL;

static int vrpmb_agent_work(struct tee_agent_kernel_ops *agent_instance)
{
	int ret;

	if (agent_instance == NULL || agent_instance->agent_buff == NULL) {
		tloge("agent buff invalid\n");
		return -1;
	}

	if (m_rpmb_ctrl == NULL) {
		m_rpmb_ctrl = kzalloc(agent_instance->agent_buff_size,
			GFP_KERNEL);
		if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)m_rpmb_ctrl)) {
			tloge("memory alloc failed\n");
			return -1;
		}
	}
	(void)memcpy_s((void *)m_rpmb_ctrl,
		agent_instance->agent_buff_size, (void *)agent_instance->agent_buff,
		agent_instance->agent_buff_size);

	ret = vrpmb_ioctl_cmd((uint8_t *)m_rpmb_ctrl, agent_instance->agent_buff_size);

	(void)memcpy_s((void *)agent_instance->agent_buff,
		agent_instance->agent_buff_size, (void *)m_rpmb_ctrl,
		agent_instance->agent_buff_size);

	return ret;
}

static int rpmb_agent_exit(struct tee_agent_kernel_ops *agent_instance)
{
	(void)agent_instance;
	if (m_rpmb_ctrl != NULL) {
		kfree(m_rpmb_ctrl);
		m_rpmb_ctrl = NULL;
	}
	tloge("rpmb agent is exit is being invoked\n");
	return 0;
}

static int rpmb_agent_crash_work(
	struct tee_agent_kernel_ops *agent_instance,
	struct tc_ns_client_context *context, unsigned int dev_file_id)
{
	(void)agent_instance;
	(void)context;
	if (m_rpmb_ctrl != NULL) {
		kfree(m_rpmb_ctrl);
		m_rpmb_ctrl = NULL;
	}
	tlogd("check free lock or not, dev_id=%d\n", dev_file_id);
	return 0;
}

static struct tee_agent_kernel_ops rpmb_agent_ops = {
	.agent_name = "vrpmb",
	.agent_id = TEE_RPMB_AGENT_ID,
	.tee_agent_init = NULL,
	.tee_agent_work = vrpmb_agent_work,
	.tee_agent_exit = rpmb_agent_exit,
	.tee_agent_crash_work = rpmb_agent_crash_work,
	.agent_buff_size = 8 * PAGE_SIZE,
	.list = LIST_HEAD_INIT(rpmb_agent_ops.list)
};

int rpmb_agent_register(void)
{
	tee_agent_kernel_register(&rpmb_agent_ops);
	return 0;
}
EXPORT_SYMBOL_TZ(rpmb_agent_register);
