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
#ifndef SCENE_MGR_H
#define SCENE_MGR_H

#include <akmd_aae.h>
#include "aae_scene.h"

struct aae_scene_mgr {
	struct res_scene_config config;
	struct aae_scene scenes[AAE_SCENE_MAX_COUNT];
};

void aae_res_register_scene_mgr(struct list_head *resource_head);

#endif