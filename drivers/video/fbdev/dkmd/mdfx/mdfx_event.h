/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
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
#ifndef MDFX_EVENT_MANAGER_H
#define MDFX_EVENT_MANAGER_H

#include <linux/list.h>
#include <linux/semaphore.h>
#include <linux/workqueue.h>
#include <linux/wait.h>
#include "hisi_mdfx.h"

#define MDFX_EVENT_NAME_PREFIX "event["
#define MDFX_NORMAL_NAME_PREFIX "normal"

#define MDFX_REPORT_EVENT_INTERVAL_SEC  5

struct mdfx_pri_data;

typedef int (*listener_act_func)(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *value);

struct mdfx_event_listener {
	struct list_head node;

	uint32_t actor_type;
	listener_act_func handle;
};

struct mdfx_event_node {
	struct list_head node;

	uint32_t event_type;
	struct timespec64 time;
};

struct mdfx_event_manager_t {
	spinlock_t event_lock;
	struct mdfx_event report_to_user_event;
	wait_queue_head_t event_wait;
	uint32_t need_report_event;

	struct list_head event_list;
	struct list_head listener_list;
	struct mdfx_event_desc default_event[MDFX_EVENT_MAX];
};

void mdfx_event_deinit(struct mdfx_event_manager_t *event_manager);
void mdfx_event_init(struct mdfx_pri_data *mdfx_data);
int mdfx_event_register_listener(struct mdfx_pri_data *mdfx_data, uint32_t actor_type, listener_act_func cb);
int mdfx_deliver_event(struct mdfx_pri_data *mdfx_data, const void __user *argp);
int mdfx_event_check_parameter(struct mdfx_event *event);

#endif
