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
#ifndef MDFX_VISITOR_H
#define MDFX_VISITOR_H

#include <linux/list.h>
#include <linux/semaphore.h>
#include <linux/types.h>
#include <linux/atomic.h>
#include "hisi_mdfx.h"
#include "mdfx_logger.h"
#include "mdfx_notifier.h"
#include "mdfx_tracing.h"

#define DEFAULT_MAX_TRACING_BUF_SIZE   	(128 * 1024)
#define INVALID_VISITOR_ID (-1)
#define VISITOR_ID_MIN (0)
#define GET_VISITOR_ID(atomic_id)    (atomic_read(&atomic_id))
#define CREATE_VISITOR_ID(atomic_id) (atomic_inc_return(&atomic_id))

struct mdfx_pri_data;
struct mdfx_visitor_node {
	struct list_head node;
	int64_t id;
	uint64_t type;
	int64_t pid;
	uint32_t ref_cnt;
	visitor_cb callback;
	void *callback_data;
	struct mdfx_notifier *notifier;
	struct mdfx_logger_t logger;
	struct mdfx_tracing_buf tracing[MDFX_TRACING_TYPE_MAX];
};

struct mdfx_visitors_t {
	struct list_head visitor_list;
	atomic_t id;
	struct semaphore visitors_sem;
};

int64_t mdfx_get_visitor_id(struct mdfx_visitors_t *visitors, uint64_t type);
struct mdfx_visitor_node* mdfx_get_visitor(struct mdfx_visitors_t *visitors, int64_t id);

// tracing
struct mdfx_tracing_buf* mdfx_visitor_get_tracing_buf(int64_t id, mdfx_traing_type_t tracing_type);
static inline uint32_t mdfx_visitor_get_max_tracing_buf_size(void)
{
	return DEFAULT_MAX_TRACING_BUF_SIZE;
}

int mdfx_add_visitor(struct mdfx_pri_data *mdfx_data, void __user *argp);
int mdfx_remove_visitor(struct mdfx_pri_data *mdfx_data, const void __user *argp);
void mdfx_visitors_init(struct mdfx_visitors_t *visitors);
void mdfx_visitors_deinit(struct mdfx_visitors_t *visitors);
struct mdfx_logger_t* mdfx_get_visitor_logger(int64_t id);


#endif
