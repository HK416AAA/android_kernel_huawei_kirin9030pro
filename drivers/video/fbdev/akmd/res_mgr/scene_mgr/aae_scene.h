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
#ifndef AAE_SCENE_H
#define AAE_SCENE_H

#include <linux/semaphore.h>
#include <akmd_aae.h>
#include "akmd_log.h"

#define AAE_SCENE_USER_MAX_COUNT 4

enum aae_scene_status {
	SCENE_STATUS_IDLE = 0,
	SCENE_STATUS_BUSY,
	SCENE_STATUS_MAX
};

enum scene_user_status {
	USER_STATUS_IDLE = 0,
	USER_STATUS_ACTIVED = 1,
	USER_STATUS_BANNED,
	USER_STATUS_MAX,
};

struct scene_user_info {
	union aae_scene_user user;
	int32_t tgid;
	uint8_t status;   // enum scene_user_status
	uint8_t reserved[3];
};

struct aae_scene {
	struct res_scene_info info;
	struct semaphore sem;

	uint8_t reserved;
	uint8_t disable_mono;  // 去使能独占模式，都是共享的，都可以共享aae的场景
	uint8_t status;        // 0: idle, 1: busy

	uint8_t user_count;
	struct scene_user_info user_infos[AAE_SCENE_USER_MAX_COUNT];

	int32_t (*request)(struct aae_scene *scene, struct res_scene_cmd *cmd, int32_t tgid);
	int32_t (*release)(struct aae_scene *scene, struct res_scene_cmd *cmd);
	int32_t (*release_for_tgid)(struct aae_scene *scene, int32_t tgid);
};

static inline void dump_scene_user(const struct aae_scene *scene)
{
	uint8_t i;

	for (i = 0; i < scene->user_count; i++) {
		aae_pr_info("user status %u, type %u, mode %u, priority %u", scene->user_infos[i].status,
					scene->user_infos[i].user.val.user_type, scene->user_infos[i].user.val.mode,
					scene->user_infos[i].user.val.priority);
	}
}

void aae_scene_init(struct aae_scene *scene);

#endif