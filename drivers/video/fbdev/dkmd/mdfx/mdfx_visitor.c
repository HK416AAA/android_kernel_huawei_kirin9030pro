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
#include <linux/slab.h>
#include "mdfx_visitor.h"
#include "mdfx_tracing.h"
#include "mdfx_priv.h"

static void mdfx_init_visitor(struct mdfx_visitor_node *visitor, bool need_logger)
{
	uint32_t i;

	if (need_logger)
		mdfx_logger_init(&visitor->logger, visitor->id);

	for (i = 0; i < (uint32_t)MDFX_TRACING_TYPE_MAX; i++)
		mdfx_tracing_init(&visitor->tracing[i]);

	visitor->notifier = mdfx_get_notifier(visitor->type);
}

static void mdfx_deinit_visitor(struct mdfx_visitor_node *visitor)
{
	uint32_t i;

	if (IS_ERR_OR_NULL(visitor))
		return;

	for (i = 0; i < (uint32_t)MDFX_TRACING_TYPE_MAX; i++)
		mdfx_tracing_deinit(&visitor->tracing[i]);

	mdfx_logger_deinit(&visitor->logger);

	list_del(&visitor->node);
	kfree(visitor);
	visitor = NULL;
}

static struct mdfx_visitor_node *mdfx_visitor_create(struct mdfx_visitors_t *visitors,
	struct mdfx_visitor_desc *desc, visitor_cb callback, void *data, bool need_logger)
{
	struct mdfx_visitor_node *node = (struct mdfx_visitor_node *)kzalloc(sizeof(*node), GFP_KERNEL);
	if (node == NULL) {
		mdfx_pr_err("kzalloc fail");
		return NULL;
	}

	mdfx_pr_info("enter mdfx_visitor_create, need_logger:%d", need_logger == true ? 1 : 0);
	node->id = CREATE_VISITOR_ID(visitors->id);
	node->type = desc->type;
	node->pid = desc->pid;
	node->callback = callback;
	node->callback_data = data;

	mdfx_init_visitor(node, need_logger);
	list_add_tail(&node->node, &visitors->visitor_list);

	mdfx_pr_info("new visitor, desc->id=%lld, desc->type=%llu, node->id=%lld, node->pid=%lld",
		desc->id, desc->type, node->id, node->pid);
	return node;
}

struct mdfx_visitor_node* mdfx_get_visitor(struct mdfx_visitors_t *visitors, int64_t id)
{
	struct mdfx_visitor_node* _node_ = NULL;
	struct mdfx_visitor_node* visitor_node = NULL;

	list_for_each_entry_safe(visitor_node, _node_, &(visitors->visitor_list), node) {
		if (visitor_node->id == id)
			return visitor_node;
	}

	return NULL;
}

static struct mdfx_visitor_node* mdfx_get_visitor_with_type(struct mdfx_visitors_t *visitors, uint64_t type)
{
	struct mdfx_visitor_node* _node_ = NULL;
	struct mdfx_visitor_node* visitor_node = NULL;

	list_for_each_entry_safe(visitor_node, _node_, &(visitors->visitor_list), node) {
		if (visitor_node->type == type)
			return visitor_node;
	}

	return NULL;
}

int64_t mdfx_get_visitor_id(struct mdfx_visitors_t *visitors, uint64_t type)
{
	struct mdfx_visitor_node* visitor = NULL;

	visitor = mdfx_get_visitor_with_type(visitors, type);
	if (IS_ERR_OR_NULL(visitor)) {
		mdfx_pr_err("mdfx_get_visitor_with_type fail, visitor type:%llu", type);
		return INVALID_VISITOR_ID;
	}

	return visitor->id;
}

static int64_t mdfx_get_or_create_visitor(struct mdfx_visitors_t *visitors,
	struct mdfx_visitor_desc *desc, visitor_cb callback, void *data, bool need_logger)
{
	struct mdfx_visitor_node *visitor = NULL;

	mdfx_pr_info("enter mdfx_get_or_create_visitor desc->type=%llu", desc->type);
	down(&visitors->visitors_sem);

	/* if find the visitor, return; else create a new visitor */
	visitor = mdfx_get_visitor_with_type(visitors, desc->type);
	if (visitor == NULL) {
		visitor = mdfx_visitor_create(visitors, desc, callback, data, need_logger);
		if (visitor == NULL) {
			mdfx_pr_err("mdfx_visitor_create fail, visitor type:%llu", desc->type);
			up(&visitors->visitors_sem);
			return INVALID_VISITOR_ID;
		}
	}

	visitor->pid = desc->pid;
	visitor->ref_cnt++;

	up(&visitors->visitors_sem);
	mdfx_pr_info("visitor_id:%lld, ref_cnt:%u", visitor->id, visitor->ref_cnt);
	return visitor->id;
}

struct mdfx_tracing_buf* mdfx_visitor_get_tracing_buf(int64_t id, mdfx_traing_type_t tracing_type)
{
	struct mdfx_visitor_node *visitor = NULL;

	if (IS_ERR_OR_NULL(g_mdfx_data) || (tracing_type >= MDFX_TRACING_TYPE_MAX)) {
		mdfx_pr_info("get tracing buf fail, id=%lld, tracing_type=%d", id, tracing_type);
		return NULL;
	}

	visitor = mdfx_get_visitor(&g_mdfx_data->visitors, id);
	if (IS_ERR_OR_NULL(visitor)) {
		mdfx_pr_info("get tracing buf fail, id=%lld", id);
		return NULL;
	}

	return &visitor->tracing[tracing_type];
}

struct mdfx_logger_t* mdfx_get_visitor_logger(int64_t id)
{
	struct mdfx_visitor_node* visitor = NULL;

	if (IS_ERR_OR_NULL(g_mdfx_data)) {
		mdfx_pr_err("g_mdfx_data fail");
		return NULL;
	}

	visitor = mdfx_get_visitor(&g_mdfx_data->visitors, id);
	if (IS_ERR_OR_NULL(visitor)) {
		mdfx_pr_err("mdfx_get_visitor fail! visitor id = %lld", id);
		return NULL;
	}

	return &visitor->logger;
}

int mdfx_add_visitor(struct mdfx_pri_data *mdfx_data, void __user *argp)
{
	struct mdfx_visitor_desc desc;
	struct mdfx_visitors_t *visitors = NULL;
	int32_t visitor_id;

	if ((mdfx_data == NULL) || (argp == NULL)){
		mdfx_pr_err("Invalid argument\n");
		return -EINVAL;
	}

	if (copy_from_user(&desc, argp, sizeof(desc))) {
		mdfx_pr_err("copy from user fail");
		return -1;
	}

	mdfx_pr_info("enter mdfx_add_visitor");
	visitors = &mdfx_data->visitors;
	visitor_id = mdfx_get_or_create_visitor(visitors, &desc, NULL, NULL, false);
	if (visitor_id == INVALID_VISITOR_ID)
		mdfx_pr_err("add visitor fail, id=-1, type=%llu, pid=%lld", desc.type, desc.pid);

	desc.id = visitor_id;
	if (copy_to_user(argp, &desc, sizeof(desc)))
		return -1;

	return 0;
}

int mdfx_remove_visitor(struct mdfx_pri_data *mdfx_data, const void __user *argp)
{
	int64_t visitor_id;
	struct mdfx_visitors_t *visitors = NULL;
	struct mdfx_visitor_node *visitor = NULL;

	if ((mdfx_data == NULL) || (argp == NULL)){
		mdfx_pr_err("Invalid argument\n");
		return -EINVAL;
	}

	if (copy_from_user(&visitor_id, argp, sizeof(visitor_id))) {
		mdfx_pr_err("copy from user fail");
		return -1;
	}

	visitors = &mdfx_data->visitors;
	down(&visitors->visitors_sem);
	visitor = mdfx_get_visitor(visitors, visitor_id);
	if (IS_ERR_OR_NULL(visitor)) {
		mdfx_pr_err("mdfx_get_visitor fail");
		up(&visitors->visitors_sem);
		return -1;
	}
	mdfx_pr_info("visitor_id: %lld, ref_cnt: %u\n", visitor_id, visitor->ref_cnt);
	visitor->ref_cnt--;
	if (visitor->ref_cnt == 0)
		mdfx_deinit_visitor(visitor);
	up(&visitors->visitors_sem);

	return 0;
}

void mdfx_visitors_init(struct mdfx_visitors_t *visitors)
{
	sema_init(&visitors->visitors_sem, 1);
	INIT_LIST_HEAD(&visitors->visitor_list);
	atomic_set(&visitors->id, 0);
}

void mdfx_visitors_deinit(struct mdfx_visitors_t *visitors)
{
	struct mdfx_visitor_node* _node_ = NULL;
	struct mdfx_visitor_node* visitor_node = NULL;

	down(&visitors->visitors_sem);
	list_for_each_entry_safe(visitor_node, _node_, &(visitors->visitor_list), node) {
		mdfx_deinit_visitor(visitor_node);
	}
	up(&visitors->visitors_sem);
}

/* kernel caller create visitor,
 * if success, return visitor id,
 * else return -1
 * kernel caller not need pid, so use -1
 */
int64_t mdfx_create_visitor(uint64_t type, visitor_cb callback, void *data)
{
	struct mdfx_visitors_t *visitors = NULL;
	struct mdfx_visitor_desc desc;

	if (IS_ERR_OR_NULL(g_mdfx_data)) {
		mdfx_pr_err("g_mdfx_data fail");
		return INVALID_VISITOR_ID;
	}

	mdfx_pr_info("enter mdfx_create_visitor");
	visitors = &g_mdfx_data->visitors;
	desc.id = -1;
	desc.type = type;
	desc.pid = -1;
	return mdfx_get_or_create_visitor(visitors, &desc, callback, data, true);
}
EXPORT_SYMBOL(mdfx_create_visitor); //lint !e580

/*
 * remove kernel caller visitor, id must be bigger than -1
 */
void mdfx_destroy_visitor(int64_t id)
{
	struct mdfx_visitors_t *visitors = NULL;
	struct mdfx_visitor_node *visitor = NULL;

	if (IS_ERR_OR_NULL(g_mdfx_data)) {
		mdfx_pr_err("g_mdfx_data fail");
		return;
	}

	visitors = &g_mdfx_data->visitors;
	down(&visitors->visitors_sem);
	visitor = mdfx_get_visitor(visitors, id);
	mdfx_deinit_visitor(visitor);
	up(&visitors->visitors_sem);
}
EXPORT_SYMBOL(mdfx_destroy_visitor); //lint !e580
