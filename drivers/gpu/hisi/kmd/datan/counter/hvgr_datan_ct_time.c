/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 */

#include "hvgr_datan_ct_time.h"

#include <hvgr_regmap.h>
#include <hvgr_kmd_defs.h>
#include <hvgr_dm_ctx.h>
#include <securec.h>

#include "hvgr_pm_api.h"
#include "hvgr_log_api.h"
#include "hvgr_mem_api.h"
#include "hvgr_dm_api.h"

#include "hvgr_asid_api.h"
#include "hvgr_cq_debug_switch.h"
#include "hvgr_ctx_sched.h"
#include "hvgr_datan_ct.h"

static int hvgr_ct_data_ready(const struct hvgr_ct_client *client)
{
	return (client->kmd_ctrl->wr != client->user_ctrl->rd);
}

static long hvgr_ct_set_interval(struct hvgr_ct_client *client, u32 interval)
{
	struct hvgr_ct_context *ct_ctx = client->ct_ctx;
	unsigned long flags;

	mutex_lock(&ct_ctx->lock);

	spin_lock_irqsave(&client->timer_lock, flags);
	client->dump_interval = interval;

	if (client->dump_interval > 0) {
		if (client->dump_interval < CT_DUMP_MIN_INTERVAL)
			client->dump_interval = CT_DUMP_MIN_INTERVAL;

		if (client->dump_interval > CT_DUMP_MAX_INTERVAL)
			client->dump_interval = CT_DUMP_MAX_INTERVAL;

		client->dump_time = hvgr_ct_get_dump_timestamp() + client->dump_interval;
	}
	spin_unlock_irqrestore(&client->timer_lock, flags);
	hvgr_ct_start_cycle_client_timer(client);
	mutex_unlock(&ct_ctx->lock);
	return 0;
}

long hvgr_ct_data_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct hvgr_ct_client *client = (struct hvgr_ct_client *)filp->private_data;

	if (cmd == HVGR_DATAN_CT_TIME_SET_INTERVAL)
		return hvgr_ct_set_interval(client, (u32)arg);

	hvgr_err(client->ctx->gdev, HVGR_DATAN, "%s invalid cmd.", __func__);
	return -EINVAL;
}

unsigned int hvgr_ct_data_poll(struct file *filp, poll_table *wait)
{
	struct hvgr_ct_client *client = (struct hvgr_ct_client *)filp->private_data;

	poll_wait(filp, &client->waitq, wait);
	if (hvgr_ct_data_ready(client))
		return POLLIN;
	return 0;
}

int hvgr_ct_data_release(struct inode *inode, struct file *filp)
{
	struct hvgr_ct_client *client = NULL;
	struct hvgr_ct_context *ct_ctx = NULL;
	struct hvgr_ctx *ctx = NULL;

	client = (struct hvgr_ct_client *)filp->private_data;
	if (client == NULL)
		return 0;

	ct_ctx = client->ct_ctx;
	if (ct_ctx == NULL)
		return 0;

	ctx = client->ctx;
	client->dump_interval = 0;

	hvgr_ct_detach_client(client);
	kref_put(&ctx->ctx_kref, hvgr_ctx_kref_release);
	return 0;
}