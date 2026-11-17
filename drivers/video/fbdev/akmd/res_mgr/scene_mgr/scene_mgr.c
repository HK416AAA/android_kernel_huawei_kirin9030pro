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
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <securec.h>
#include <akmd_aae.h>
#include "aae_res_mgr.h"
#include "scene_mgr.h"

static struct aae_scene* find_scene(struct aae_scene_mgr *scene_mgr, uint32_t scene_id)
{
	uint32_t i;

	for (i = 0; i < AAE_SCENE_MAX_COUNT; i++) {
		if (scene_mgr->scenes[i].info.id == scene_id) {
			return &scene_mgr->scenes[i];
		}
	}

	return NULL;
}

///// ioctl /////
static int32_t scene_mgr_get_config(struct aae_scene_mgr *scene_mgr, void __user *argp)
{
	if (unlikely(scene_mgr == NULL)) {
		aae_pr_err("scene mgr is null");
		return -1;
	}

	if (copy_to_user(argp, &scene_mgr->config, sizeof(scene_mgr->config)) != 0) {
		aae_pr_err("copy to user fail");
		return -1;
	}

	return 0;
}

static int32_t scene_mgr_request_scene(struct aae_scene_mgr *scene_mgr, void __user *argp, int32_t tgid)
{
	struct res_scene_cmd request_cmd;
	struct aae_scene *scene = NULL;

	aae_pr_debug("tgid %d request scene", tgid);
	if (unlikely(scene_mgr == NULL) || unlikely(argp == NULL))
		return -1;

	if (copy_from_user(&request_cmd, argp, sizeof(request_cmd)) != 0) {
		aae_pr_err("tgid %d copy from user fail", tgid);
		return -1;
	}

	scene = find_scene(scene_mgr, request_cmd.scene_id);
	if (scene == NULL) {
		aae_pr_err("find scene id %d fail", request_cmd.scene_id);
		return -1;
	}

	if (unlikely(scene->request == NULL))
		return -2;

	return scene->request(scene, &request_cmd, tgid);
}

static int32_t scene_mgr_release_scene(struct aae_scene_mgr *scene_mgr, void __user *argp)
{
	struct res_scene_cmd release_cmd;
	struct aae_scene *scene = NULL;

	aae_pr_info("release scene");
	if (unlikely(scene_mgr == NULL) || unlikely(argp == NULL))
		return -1;

	if (copy_from_user(&release_cmd, argp, sizeof(release_cmd)) != 0) {
		aae_pr_err("copy from user fail");
		return -1;
	}

	scene = find_scene(scene_mgr, release_cmd.scene_id);
	if (scene == NULL) {
		aae_pr_err("find scene id %d fail", release_cmd.scene_id);
		return -1;
	}

	if (unlikely(scene->release == NULL))
		return -2;

	return scene->release(scene, &release_cmd);
}

///////register function////////
static void* scene_mgr_init(struct aae_res_data *rm_data)
{
	struct aae_scene_mgr *scene_mgr = NULL;
	struct res_scene_config *config = NULL;
	uint32_t i = 0;

	scene_mgr = kzalloc(sizeof(struct aae_scene_mgr), GFP_KERNEL);
	if (scene_mgr == NULL)
		return NULL;

	config = &scene_mgr->config;

	// TODO: get config from dts

	for (i = 0; i < config->count; i++) {
		(void)memcpy_s(&scene_mgr->scenes[i].info, sizeof(scene_mgr->scenes[i].info), \
					   &config->info, sizeof(config->info));
		aae_scene_init(&scene_mgr->scenes[i]);
	}

	return scene_mgr;
}

static void scene_mgr_deinit(void *data)
{
	struct aae_scene_mgr *scene_mgr = (struct aae_scene_mgr *)data;

	if (scene_mgr == NULL)
		return;

	kfree(scene_mgr);
	scene_mgr = NULL;
}

static void scene_mgr_release(void *data, int32_t tgid)
{
	struct aae_scene_mgr *scene_mgr = (struct aae_scene_mgr *)data;
	struct aae_scene *scene = NULL;
	uint32_t i = 0;

	aae_check_and_no_retval(!scene_mgr, err, "scene_mgr is nullptr!");

	for (i = 0; i < AAE_SCENE_MAX_COUNT; i++) {
		scene = &scene_mgr->scenes[i];

		if (scene->release_for_tgid == NULL) {
			aae_pr_err("release_for_tgid is null");
			continue;
		}

		if (scene->release_for_tgid(scene, tgid) != 0)
			aae_pr_err("release for tgid %d fail", tgid);
	}
}

static long scene_mgr_ioctl(struct aae_res_resouce_node *res_node, uint32_t cmd, void __user *argp)
{
	struct aae_scene_mgr *scene_mgr = NULL;

	if (unlikely(res_node == NULL) || unlikely(argp == NULL)) {
		aae_pr_err("scene mgr ioctl null ptr");
		return -EINVAL;
	}

	if (res_node->data == NULL) {
		aae_pr_err("data is nullptr");
		return -EINVAL;
	}
	scene_mgr = (struct aae_scene_mgr *)res_node->data;

	switch(cmd) {
	case RES_GET_SCENE_CONFIG:
		return scene_mgr_get_config(scene_mgr, argp);
	case RES_REQUEST_SCENE:
		return scene_mgr_request_scene(scene_mgr, argp, res_node->tgid);
	case RES_RELEASE_SCENE:
		return scene_mgr_release_scene(scene_mgr, argp);
	default:
		aae_pr_debug("scene_id mgr unsupport cmd, need processed by other module, cmd = 0x%x", cmd);
		return 1;
	}
	return 0;
}

#ifdef CONFIG_AKMD_DEBUG_ENABLE
static ssize_t scene_mgr_show(void *data, char *buf)
{
	struct aae_scene_mgr *scene_mgr = (struct aae_scene_mgr *)data;
	struct aae_scene *scene = NULL;
	ssize_t ret = 0;
	uint32_t i, j;

	if (unlikely(data == NULL || buf == NULL)) {
		aae_pr_err("data or buf is null");
		return -ENODEV;
	}

	for (i = 0; i < AAE_SCENE_MAX_COUNT; i++) {
		scene = &scene_mgr->scenes[i];
		ret += snprintf_s(buf + ret, PAGE_SIZE, PAGE_SIZE - 1, "scene id=%u, disable_mono=%u, status=%u, user_count=%u \n",
						  scene->info.id, scene->disable_mono, scene->status, scene->user_count);

		for (j = 0; j < AAE_SCENE_USER_MAX_COUNT; j++) {
			ret += snprintf_s(buf + ret, PAGE_SIZE, PAGE_SIZE - 1, "tgid=%d user: status=%u, type=%u, mode=%u, priority=%u \n",
							  scene->user_infos[j].tgid, scene->user_infos[j].status, scene->user_infos[j].user.val.user_type,
							  scene->user_infos[j].user.val.mode, scene->user_infos[j].user.val.priority);
		}
	}

	return ret;
}

static ssize_t scene_mgr_store(void *data, const char *buf, size_t count)
{
	struct aae_scene_mgr *scene_mgr = (struct aae_scene_mgr *)data;
	const char *str;
	uint32_t disable_mono;
	uint32_t i;

	str = strstr(buf, "disable_mono=");
	if (str == NULL) {
		return count;
	}

	if (kstrtouint(str, 10, &disable_mono) != 0) {
		aae_pr_err("str to uint32_t fail %s", str);
		return count;
	}

	for (i = 0; i < AAE_SCENE_MAX_COUNT; i++) {
		scene_mgr->scenes[i].disable_mono = !!disable_mono;
		aae_pr_warn("scene_id %d disable mono %d", i, !!disable_mono);
	}

	return count;
}
#endif

void aae_res_register_scene_mgr(struct list_head *resource_head)
{
	struct aae_res_resouce_node *res_node = NULL;
	if (!res_node)
		return;

	res_node = kzalloc(sizeof(struct aae_res_resouce_node), GFP_KERNEL);
	if (!res_node)
		return;

	res_node->res_type = RES_SCENE;

	res_node->init = scene_mgr_init;
	res_node->deinit = scene_mgr_deinit;
	res_node->release = scene_mgr_release;
	res_node->ioctl = scene_mgr_ioctl;
#ifdef CONFIG_AKMD_DEBUG_ENABLE
	res_node->show = scene_mgr_show;
	res_node->store = scene_mgr_store;
#endif

	list_add_tail(&res_node->list_node, resource_head);
	aae_pr_debug("aae_res_register_scene_mgr success!");
}