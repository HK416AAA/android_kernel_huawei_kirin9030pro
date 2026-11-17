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
#include "aae_scene.h"

static int32_t insert_user(struct aae_scene *scene, union aae_scene_user user, int32_t tgid)
{
	if (unlikely(scene->user_count >= AAE_SCENE_USER_MAX_COUNT)) {
		aae_pr_err("scene user count is %hhu overflow", scene->user_count);
		return -1;
	}

	scene->user_infos[scene->user_count].user = user;
	scene->user_infos[scene->user_count].status = USER_STATUS_ACTIVED;
	scene->user_infos[scene->user_count].tgid = tgid;
	++scene->user_count;

	dump_scene_user(scene);
	return 0;
}

static void ban_user(struct aae_scene *scene, uint32_t max_priority, int32_t mode)
{
	uint32_t i;
	struct scene_user_info *user_info = NULL;

	for (i = 0; i < scene->user_count; i++) {
		user_info = &scene->user_infos[i];
		if (user_info->status != USER_STATUS_ACTIVED)
			continue;

		if ((mode > 0) && (user_info->user.val.mode != (uint64_t)mode))
			continue;

		// ban掉优先级比max_priority低的user
		if (user_info->user.val.priority >= max_priority)
			user_info->status = USER_STATUS_BANNED;
	}

	dump_scene_user(scene);
}

static void unban_user(struct aae_scene *scene, uint32_t max_priority)
{
	uint32_t i;
	struct scene_user_info *user_info = NULL;

	for (i = 0; i < scene->user_count; i++) {
		user_info = &scene->user_infos[i];
		if (user_info->status != USER_STATUS_BANNED)
			continue;

		// 解ban优先级比max_priority低的user
		if (user_info->user.val.priority >= max_priority)
			user_info->status = USER_STATUS_ACTIVED;
	}

	dump_scene_user(scene);
}

static struct scene_user_info* find_user(struct aae_scene *scene, union aae_scene_user user)
{
	struct scene_user_info *info = NULL;
	uint32_t i;

	for (i = 0; i < scene->user_count; i++) {
		info = &scene->user_infos[i];
		if (info->user.id == user.id)
			return info;
	}

	return NULL;
}

static struct scene_user_info* find_tgid_user(struct aae_scene *scene, int32_t tgid)
{
	struct scene_user_info *info = NULL;
	uint32_t i;

	for (i = 0; i < scene->user_count; i++) {
		info = &scene->user_infos[i];
		if (info->tgid == tgid && tgid > 0)
			return info;
	}

	return NULL;
}

static void reset_user_info(struct aae_scene *scene, struct scene_user_info *user_info)
{
	user_info->status = USER_STATUS_IDLE;
	user_info->user.id = 0;

	if (scene->user_count > 0)
		--scene->user_count;

	if (scene->user_count == 0) {
		scene->status = SCENE_STATUS_IDLE;
		return;
	}

	// 解ban低优先级的user
	unban_user(scene, user_info->user.val.priority);
}

static struct scene_user_info* find_max_priority_user(struct aae_scene *scene)
{
	struct scene_user_info *user_info = NULL;
	struct scene_user_info *result = NULL;
	uint32_t max_priority = AAE_TASK_PRI_MAX;
	uint32_t i;

	for (i = 0; i < scene->user_count; i++) {
		user_info = &scene->user_infos[i];

		if (user_info->status != USER_STATUS_ACTIVED)
			continue;

		if (user_info->user.val.priority < max_priority) {
			max_priority = user_info->user.val.priority;
			result = user_info;
		}
	}

	return result;
}

// 独占式user申请场景时，判断优先级
static int32_t update_user_for_mono(struct aae_scene *scene, union aae_scene_user user, int32_t mode, int32_t tgid)
{
	int32_t ret;
	struct scene_user_info *max_user_info = find_max_priority_user(scene);

	if (max_user_info == NULL)
		return insert_user(scene, user, tgid);

	if (max_user_info->user.val.priority < user.val.priority)
		return -1;

	ret = insert_user(scene, user, tgid);
	if (ret == 0)
		ban_user(scene, max_user_info->user.val.priority, -1); // ban all low priority user

	return ret;
}

// 如果scene里的user都是shared，就返回成功
// 如果scene里激活态user是mono, 比较优先级，如果shared的优先级低，返回失败，
// 如果优先级更高，ban掉mono，返回成功
static int32_t update_user_for_shared(struct aae_scene *scene, union aae_scene_user user, int32_t tgid)
{
	int32_t ret;
	struct scene_user_info *max_user_info = find_max_priority_user(scene);

	if (max_user_info == NULL)
		return insert_user(scene, user, tgid);

	switch (max_user_info->user.val.mode) {
	case AAE_SCENE_REQUEST_MODE_SHARED:
		return insert_user(scene, user, tgid);
	case AAE_SCENE_REQUEST_MODE_MONO:
		return update_user_for_mono(scene, user, AAE_SCENE_REQUEST_MODE_MONO, tgid);
	default:
		aae_pr_err("max_user_info mode is error %d", max_user_info->user.val.mode);
		return -1;
	}
}

static int32_t update_user(struct aae_scene *scene, union aae_scene_user user, int32_t tgid)
{
	switch (user.val.mode) {
	case AAE_SCENE_REQUEST_MODE_SHARED:
		return update_user_for_shared(scene, user, tgid);
	case AAE_SCENE_REQUEST_MODE_MONO:
		return update_user_for_mono(scene, user, -1, tgid);
	default:
		return -1;
	}
	return 0;
}
/*******************************************************************************
	函 数 名		:
	功能描述		: 都是共享模式，可以并发
					模式不同，看优先级，低优先级让位高优先级，
					都是独占模式，低优先级的通道被baned，高优先级返回成功
	输入参数		:  None
	输出参数		:  None
	返 回 值		:  0，表示申请成功，< 0，申请失败不可用，> 0: 被banned
*******************************************************************************/
static int32_t aae_scene_reqeust(struct aae_scene *scene, struct res_scene_cmd *cmd, int32_t tgid)
{
	int32_t ret;

	if (unlikely(scene == NULL || cmd == NULL))
		return -1;

	if (unlikely(cmd->scene_id != scene->info.id)) {
		aae_pr_err("request scene id %d is not eq scene_id %d", cmd->scene_id, scene->info.id);
		return -2;
	}

	down(&scene->sem);
	if (scene->status == SCENE_STATUS_IDLE) {
		insert_user(scene, cmd->user, tgid);
		scene->status = SCENE_STATUS_BUSY;
		up(&scene->sem);
		return 0;
	}

	// 独占模式被关闭
	if (scene->disable_mono > 0) {
		 ret = insert_user(scene, cmd->user, tgid);
		 up(&scene->sem);
		 return ret;
	}

	ret = update_user(scene, cmd->user, tgid);
	up(&scene->sem);
	return ret;
}

static int32_t aae_scene_release(struct aae_scene *scene, struct res_scene_cmd *cmd)
{
	struct scene_user_info* user_info = NULL;

	if (unlikely(scene == NULL || cmd == NULL))
		return -1;

	down(&scene->sem);

	user_info = find_user(scene, cmd->user);
	if (user_info == NULL) {
		aae_pr_info("find user fail, id %llu", cmd->user.id);
		up(&scene->sem);
		return -1;
	}

	aae_pr_info("release scene id %u user %llu user count %u",
				cmd->scene_id, cmd->user.id, scene->user_count);
	reset_user_info(scene, user_info);

	up(&scene->sem);
	return 0;
}

int32_t aae_scene_release_for_tgid(struct aae_scene *scene, int32_t tgid)
{
	struct scene_user_info* user_info = NULL;

	if (unlikely(scene == NULL))
		return -1;

	down(&scene->sem);

	user_info = find_tgid_user(scene, tgid);
	if (user_info == NULL) {
		aae_pr_info("find tgid %d user fail", tgid);
		up(&scene->sem);
		return -1;
	}
	reset_user_info(scene, user_info);

	up(&scene->sem);
	return 0;
}

void aae_scene_init(struct aae_scene *scene)
{
	if (unlikely(scene == NULL))
		return;

	sema_init(&scene->sem, 1);
	scene->request = aae_scene_reqeust;
	scene->release = aae_scene_release;
	scene->release_for_tgid = aae_scene_release_for_tgid;
}