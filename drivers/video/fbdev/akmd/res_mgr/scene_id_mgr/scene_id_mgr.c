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

#include "scene_id_mgr.h"
#include <securec.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include "aae_res_mgr.h"
#include "akmd_log.h"
#include "aae_config_utils.h"

#define DISP_LOG_TAG "RES_MGR"
const uint32_t g_user_type_priority[SCENE_USER_MAX] = {
	AAE_SCENE_USER_PRIORITY_NULL,
	AAE_SCENE_USER_PIRORITY_2,
	AAE_SCENE_USER_PIRORITY_6,
	AAE_SCENE_USER_PIRORITY_2,
	AAE_SCENE_USER_PIRORITY_3,
	AAE_SCENE_USER_PIRORITY_4,
	AAE_SCENE_USER_PIRORITY_1,
	AAE_SCENE_USER_PIRORITY_5,
};

static struct scene_id_node* find_scene_id_node(struct list_head *scene_id_list, int32_t scene_id)
{
	struct scene_id_node *node = NULL;
	struct scene_id_node *_node_ = NULL;

	list_for_each_entry_safe(node, _node_, scene_id_list, list_node) {
		if (!node)
			continue;

		if (node->scene_id == scene_id)
			return node;
	}

	return NULL;
}

static void free_scene_id_list(struct list_head *scene_id_list)
{
	struct scene_id_node *scene_id_node = NULL;
	struct scene_id_node *_node_ = NULL;

	list_for_each_entry_safe(scene_id_node, _node_, scene_id_list, list_node) {
		if (!scene_id_node)
			continue;

		list_del(&scene_id_node->list_node);
		kfree(scene_id_node);
		scene_id_node = NULL;
	}
}

static int find_user_info(struct scene_id_node *node, int32_t tgid, enum scene_user_type user_type)
{
	struct aae_scene_user_info *curr_user_type_info = NULL;
	curr_user_type_info = node->user_info;
	uint32_t index = 0;

	if (unlikely(tgid <= 0 || user_type == SCENE_USER_NONE)) {
		aae_pr_err("find tgid and user_type is invalid.");
		return -1;
	}

	for (; index < SCENE_ID_CURRENT_USER_MAX; index++) {
		if (curr_user_type_info[index].user_type == user_type && curr_user_type_info[index].tgid == tgid) {
			return index;
		}
	}
	return -1;
}

static int insert_user_info(struct scene_id_node *node, int32_t tgid, enum scene_user_type user_type)
{
	struct aae_scene_user_info *curr_user_type_info = NULL;
	curr_user_type_info = node->user_info;
	int32_t user_index = -1;
	uint32_t i;

	for (i = 0; i < SCENE_ID_CURRENT_USER_MAX; i++) {
		if (curr_user_type_info[i].user_type == user_type && curr_user_type_info[i].tgid == tgid) {
			curr_user_type_info[i].ref += 1;
			++node->current_user_cnt;
			return 0;
		}

		if (curr_user_type_info[i].user_type == SCENE_USER_NONE && (user_index < 0)) {
			user_index = (int32_t)i;
		}
	}

	if (user_index >= 0) {
		curr_user_type_info[user_index].user_type = user_type;
		curr_user_type_info[user_index].tgid = tgid;
		curr_user_type_info[user_index].priority = g_user_type_priority[user_type];
		curr_user_type_info[user_index].ref = 1;
		++node->current_user_cnt;
		return 0;
	}

	aae_pr_err("insert user index fail, user type=%d, tgid=%d.", user_type, tgid);
	return -1;
}

static void remove_user_by_index(struct scene_id_node *node, uint32_t index)
{
	struct aae_scene_user_info *curr_user_type_info = NULL;
	curr_user_type_info = node->user_info;

	if (curr_user_type_info[index].ref > 1) {
		curr_user_type_info[index].ref -= 1;
		--node->current_user_cnt;
		return;
	}

	curr_user_type_info[index].user_type = SCENE_USER_NONE;
	curr_user_type_info[index].tgid = 0;
	curr_user_type_info[index].priority = AAE_SCENE_USER_PRIORITY_NULL;
	curr_user_type_info[index].ref = 0;
	--node->current_user_cnt;
	return;
}

static bool remove_user_by_tgid(struct scene_id_node *node, int32_t tgid)
{
	int32_t index = 0;
	uint32_t remove_cnt = 0;

	for (; index < SCENE_ID_CURRENT_USER_MAX; index++) {
		if (node->user_info[index].tgid == tgid) {
			node->user_info[index].tgid = 0;
			node->user_info[index].user_type = SCENE_USER_NONE;
			node->user_info[index].priority = AAE_SCENE_USER_PRIORITY_NULL;
			node->current_user_cnt -= node->user_info[index].ref;
			remove_cnt += node->user_info[index].ref;
			node->user_info[index].ref = 0;
			aae_pr_info("remove tgid %d at index %d", tgid, index);
		}
	}

	if (remove_cnt != 0) {
		aae_pr_info("remove user cnt:%d,user cnt:%d", remove_cnt, node->current_user_cnt);
		return true;
	}
	return false;
}

static struct scene_id_node* init_scene_id_node(uint32_t scene_id, int32_t scene_type)
{
	struct scene_id_node *node = NULL;

	aae_assert(scene_type < 0);

	node = kzalloc(sizeof(struct scene_id_node), GFP_KERNEL);
	if (!node) {
		aae_pr_err("kzalloc scene id node fail");
		return NULL;
	}

	node->scene_id = (int32_t)scene_id;
	return node;
}

static bool has_emergency_channel(enum scene_user_type user_type) {
	if (user_type == SCENE_USER_CAMERA) {
		aae_pr_info("userType %d have not guarantee mechanism.", user_type);
		return false;
	}

	return true;
}

static enum aae_scene_user_priority get_max_user_priority(struct scene_id_node *node) {
	enum aae_scene_user_priority max_priority = AAE_SCENE_USER_PRIORITY_NULL;
	struct aae_scene_user_info *curr_user_type_info = NULL;
	curr_user_type_info = node->user_info;
	int32_t i = 0;

	for (; i < SCENE_ID_CURRENT_USER_MAX; i++) {
		if (curr_user_type_info[i].priority > max_priority) {
			max_priority = curr_user_type_info[i].priority;
		}
	}
	aae_pr_debug("user max priority %d", max_priority);

	return max_priority;
}

static int check_resource_conflict(struct aae_scene_id_mgr *scene_id_mgr, void __user *argp) {
	struct scene_id_info id_info = {0};
	struct scene_id_node *scene_id_node = NULL;
	enum scene_user_type req_user_type = SCENE_USER_NONE;
	aae_pr_info("resource check.");

	if (copy_from_user(&id_info, argp, sizeof(id_info)) != 0) {
		aae_pr_err("copy from user fail");
		return -1;
	}
	req_user_type = id_info.user.user_type;
	id_info.result = -1;

	if (unlikely(req_user_type >= SCENE_USER_MAX || req_user_type <= SCENE_USER_NONE)) {
		aae_pr_err("userType %d is invalid", req_user_type);
        goto OUT;
	}

	down(&scene_id_mgr->sem);
	scene_id_node = find_scene_id_node(&scene_id_mgr->scene_id_list, id_info.scene_id);
	if (!scene_id_node) {
		aae_pr_err("user %d find scene id %d node fail", id_info.user.user_type, id_info.scene_id);
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	// hiof do not request scene_id, so do not check tgid.
	if ((find_user_info(scene_id_node, current->tgid, req_user_type) < 0) && req_user_type != SCENE_USER_GPU_HIOF) {
		aae_pr_err("find tgid id %d and user type %d fail", req_user_type, current->tgid);
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	if (g_user_type_priority[req_user_type] < get_max_user_priority(scene_id_node)) {
		aae_pr_info("requst user type is conflict with current user type, check fail.");
		up(&scene_id_mgr->sem);
		goto OUT;
	}
	up(&scene_id_mgr->sem);
	id_info.result = 0;

OUT:
	if (copy_to_user(argp, &id_info, sizeof(id_info)) != 0) {
		aae_pr_err("copy to user fail, user=%d, id=%d", id_info.user.user_type, id_info.scene_id);
		return -1;
	}
	return 0;
}

static int scene_id_mgr_request_scene_id(struct aae_scene_id_mgr *scene_id_mgr, void __user *argp)
{
	struct scene_id_info id_info = {0};
	struct scene_id_node *scene_id_node = NULL;
	struct scene_id_user *user = NULL;
	enum scene_user_type req_user_type = SCENE_USER_NONE;
	aae_pr_info("mdc request");

	if (copy_from_user(&id_info, argp, sizeof(id_info)) != 0) {
		aae_pr_err("copy from user fail");
		return -1;
	}

	req_user_type = id_info.user.user_type;
	id_info.result = -1;

	if (unlikely(req_user_type >= SCENE_USER_MAX || req_user_type <= SCENE_USER_NONE)) {
		aae_pr_err("userType %d is invalid", req_user_type);
        goto OUT;
	}

	down(&scene_id_mgr->sem);
	scene_id_node = find_scene_id_node(&scene_id_mgr->scene_id_list, id_info.scene_id);
	if (!scene_id_node) {
		aae_pr_err("user %d find scene id %d node fail", req_user_type, id_info.scene_id);
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	// 1, effect(HDR2SDR) and mdc(camera) user can use the offline scene_id at sametime
	// 2, HDM(display) can't be in conflict with effect and mdc
	// 3, MDC > VIDEO > PIC >EFFECT == HDM

	if (g_user_type_priority[req_user_type] <= get_max_user_priority(scene_id_node) && (has_emergency_channel(req_user_type))) {
		aae_pr_info("request user type priority is lower than current max user_priority, should use emergency channel, request copybit channel fail.");
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	if (insert_user_info(scene_id_node, current->tgid, req_user_type) != 0) {
		up(&scene_id_mgr->sem);
		goto OUT;
	}
	aae_pr_info("user->user_type = %d current_user_cnt = %d, priority = %d", req_user_type, scene_id_node->current_user_cnt, g_user_type_priority[req_user_type]);

	up(&scene_id_mgr->sem);
	id_info.result = 0;

OUT:
	if (copy_to_user(argp, &id_info, sizeof(id_info)) != 0) {
		aae_pr_err("copy to user fail, user=%d, id=%d", id_info.user.user_type, id_info.scene_id);
		return -1;
	}
	if (scene_id_node != NULL) {
		aae_pr_info("user->user_type = %d current_user_cnt = %d", req_user_type, scene_id_node->current_user_cnt);
	}
	return 0;
}

static int scene_id_mgr_release_scene_id(struct aae_scene_id_mgr *scene_id_mgr, void __user *argp)
{
	struct scene_id_info id_info;
	struct scene_id_node *scene_id_node = NULL;
	struct scene_id_user *user = NULL;
	enum scene_user_type rel_user_type = SCENE_USER_NONE;
	int32_t index = 0;
	aae_pr_info("mdc release");

	if (copy_from_user(&id_info, argp, sizeof(id_info)) != 0) {
		aae_pr_err("copy from user fail");
		return -1;
	}

	rel_user_type = id_info.user.user_type;
	if (unlikely(rel_user_type >= SCENE_USER_MAX || rel_user_type <= SCENE_USER_NONE)) {
		aae_pr_err("userType %d is invalid", rel_user_type);
        goto OUT;
	}

	down(&scene_id_mgr->sem);
	scene_id_node = find_scene_id_node(&scene_id_mgr->scene_id_list, id_info.scene_id);
	if (!scene_id_node) {
		aae_pr_err("user %d find scene id %d node fail", id_info.user.user_type, id_info.scene_id);
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	index = find_user_info(scene_id_node, current->tgid, rel_user_type);
	if (index < 0) {
		aae_pr_err("find tgid id %d and user type %d fail", rel_user_type, current->tgid);
		up(&scene_id_mgr->sem);
		goto OUT;
	}

	remove_user_by_index(scene_id_node, (uint32_t)index);
	aae_pr_info("user->user_type = %d current_user_cnt = %d", rel_user_type, scene_id_node->current_user_cnt);

	up(&scene_id_mgr->sem);
OUT:
	if (copy_to_user(argp, &id_info, sizeof(id_info)) != 0) {
		aae_pr_err("copy to user fail, user=%d, id=%d", id_info.user.user_type, id_info.scene_id);
		return -1;
	}
	if (scene_id_node != NULL) {
		aae_pr_info("user->user_type = %d current_user_cnt = %d", rel_user_type, scene_id_node->current_user_cnt);
	}
	return 0;
}

static long scene_id_mgr_ioctl(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp)
{
	struct aae_scene_id_mgr *scene_id_mgr = NULL;

	if (!res_node || !res_node->data || !argp) {
		aae_pr_err("res_node or node data or argp is NULL");
		return -EINVAL;
	}

	scene_id_mgr = (struct aae_scene_id_mgr*)res_node->data;
	switch (cmd) {
	case RES_REQUEST_SCENE_ID:
		return scene_id_mgr_request_scene_id(scene_id_mgr, argp);
	case RES_RELEASE_SCENE_ID:
		return scene_id_mgr_release_scene_id(scene_id_mgr, argp);
	case RES_CHECK_RES_CONFLICT:
		return check_resource_conflict(scene_id_mgr, argp);
	default:
		aae_pr_debug("scene_id mgr unsupport cmd, need processed by other module, cmd = 0x%x", cmd);
		return 1;
	}

	return 0;
}

static void* scene_id_mgr_init(struct aae_res_data *rm_data)
{
	uint32_t i;
	struct scene_id_node *scene_id_node = NULL;
	struct aae_scene_id_mgr *scene_id_mgr = kzalloc(sizeof(struct aae_scene_id_mgr), GFP_KERNEL);
	if (!scene_id_mgr)
		return NULL;

	sema_init(&scene_id_mgr->sem, 1);
	INIT_LIST_HEAD(&scene_id_mgr->scene_id_list);

	aae_assert(rm_data->offline_scene_id_count > DTS_OFFLINE_SCENE_ID_MAX);

	for (i = 0; i < rm_data->offline_scene_id_count; i++) {
		scene_id_node = init_scene_id_node(rm_data->offline_scene_ids[i], SCENE_TYPE_OFFLINE);
		if (unlikely(!scene_id_node)) {
			aae_pr_err("init scene id node fail, i = %u, scene_id = %u", i, rm_data->offline_scene_ids[i]);
			continue;
		}

		list_add_tail(&scene_id_node->list_node, &scene_id_mgr->scene_id_list);
	}

	return scene_id_mgr;
}

static void scene_id_mgr_deinit(void *data)
{
	struct aae_scene_id_mgr *scene_id_mgr = (struct aae_scene_id_mgr *)data;

	if (!scene_id_mgr)
		return;

	down(&scene_id_mgr->sem);
	free_scene_id_list(&(scene_id_mgr->scene_id_list));
	up(&scene_id_mgr->sem);

	kfree(scene_id_mgr);
	scene_id_mgr = NULL;
}

static void scene_id_mgr_release(void *data, int32_t tgid)
{
	struct aae_scene_id_mgr *scene_id_mgr = NULL;
	struct scene_id_node *scene_id_node = NULL;
	struct scene_id_node *_node_ = NULL;
	struct scene_id_info *id_info = NULL;

	scene_id_mgr = (struct aae_scene_id_mgr *)data;
	if (!scene_id_mgr)
		return;

	down(&scene_id_mgr->sem);
	list_for_each_entry_safe(scene_id_node, _node_, &scene_id_mgr->scene_id_list, list_node) {
		if (!scene_id_node)
			continue;

		if (!remove_user_by_tgid(scene_id_node, tgid)) {
			continue;
		}
	}

	up(&scene_id_mgr->sem);
}

void aae_res_register_scene_id_mgr(struct list_head *resource_head)
{
	struct aae_res_resouce_node *scene_mgr_node = NULL;
	if (!resource_head) {
		return;
	}

	scene_mgr_node = kzalloc(sizeof(struct aae_res_resouce_node), GFP_KERNEL);
	if (!scene_mgr_node) {
		return;
	}

	scene_mgr_node->res_type = RES_SCENE_ID;

	scene_mgr_node->init = scene_id_mgr_init;
	scene_mgr_node->deinit = scene_id_mgr_deinit;
	scene_mgr_node->ioctl = scene_id_mgr_ioctl;
	scene_mgr_node->release = scene_id_mgr_release;

	list_add_tail(&scene_mgr_node->list_node, resource_head);
	aae_pr_debug("aae_res_register_opr_mgr success!");
}