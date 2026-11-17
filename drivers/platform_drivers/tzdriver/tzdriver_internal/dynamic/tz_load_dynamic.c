/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: Enable to load dynamic driver and server
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

#include "tz_load_dynamic.h"
#include <linux/fs.h>
#include <securec.h>
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "teek_app_load.h"
#include "tc_ns_client.h"
#include "session_manager.h"


#if defined(DYNAMIC_DRV_DIR) || defined(DYNAMIC_CRYPTO_DRV_DIR) || defined(DYNAMIC_SRV_DIR)
#define MAX_FILE_NAME_LEN 128
#define MAX_SEC_NAME_LEN  40
#define SEC_NAME_LEN      4

static struct teec_context *g_context = NULL;
static const char *g_dyn_dir = NULL;
static uint32_t g_load_type = 0;

static int32_t tz_load_dyn_app(struct teec_context *context, const char *ta_path, uint32_t load_type)
{
	char *file_buf = NULL;
	uint32_t file_size;
	bool load_app_flag = false;
	struct load_secfile_ioctl_struct secfile_arg = { {0}, {0}, {NULL} };

	int32_t ret = teek_get_app(ta_path, &file_buf, &file_size);
	if (ret != 0) {
		tloge("teek load app failed, ret %d\n", ret);
		goto clean;
	}
	load_app_flag = true;

	secfile_arg.sec_file_info.secfile_type = load_type;
	secfile_arg.sec_file_info.file_size = file_size;
	secfile_arg.file_buffer = file_buf;

	ret = tc_ns_load_secfile((struct tc_ns_dev_file *)context->dev, NULL, &secfile_arg, false);
	if (ret != 0)
		tloge("load secfile failed, ret %d\n", ret);

clean:
	teek_free_app(load_app_flag, &file_buf);
	return ret;
}

static int32_t load_one_file(struct teec_context *context, const char *dyn_dir, const char *secfile_name,
	uint32_t load_type)
{
	char ta_path[MAX_FILE_NAME_LEN];
	int32_t ret;
	int len = (int)strnlen(secfile_name, MAX_SEC_NAME_LEN);

	if (strcmp(secfile_name, ".") == 0 || strcmp(secfile_name, "..") == 0) {
		tlogd("no need to load\n");
		return 0;
	}

	if (len >= MAX_SEC_NAME_LEN || len <= SEC_NAME_LEN || strcmp(&secfile_name[len - SEC_NAME_LEN], ".sec") != 0) {
		tlogw("only support sec file\n");
		return 0;
	}

	if (memset_s(ta_path, sizeof(ta_path), 0, sizeof(ta_path)) != 0) {
		tloge("memset failed, size: %u\n", (uint32_t)sizeof(ta_path));
		return -1;
	}
	if (strcat_s(ta_path, MAX_FILE_NAME_LEN, dyn_dir) != 0) {
		tloge("dir name too long: %s\n", dyn_dir);
		return -1;
	}
	if (strcat_s(ta_path, MAX_FILE_NAME_LEN, secfile_name) != 0) {
		tloge("drv name too long: %s\n", secfile_name);
		return -1;
	}

	ret = tz_load_dyn_app(context, ta_path, load_type);
	if (ret != 0) {
		tloge("load app failed, ret %d\n", ret);
		return ret;
	}

	return 0;
}

static int tz_filldir(struct dir_context *ctx, const char *name, int name_len,
	loff_t offset, u64 ino, unsigned int d_type)
{
	int ret = 0;
	if (name_len > 0) {
		ret = load_one_file(g_context, g_dyn_dir, name, g_load_type);
		if (ret != 0)
			tloge("load one file failed, name %s, ret %d\n", name, ret);
	}
	return 0;
}

static void load_one_dynamic_dir(struct teec_context *context, const char *dyn_dir, uint32_t load_type)
{
	int ret;
	struct file *dir_file = NULL;
	struct dir_context dir_ctx = {
		.actor = tz_filldir
	};

	uint32_t dyn_dir_len = strnlen(dyn_dir, MAX_FILE_NAME_LEN);
	if (dyn_dir_len == 0 || dyn_dir_len >= MAX_FILE_NAME_LEN) {
		tloge("invalid dyn_dir\n");
		return;
	}

	if (load_type != LOAD_DYNAMIC_DRV && load_type != LOAD_SERVICE) {
		tloge("invalid load type, type %u\n", load_type);
		return;
	}

	dir_file = filp_open(dyn_dir, O_RDONLY, 0);
	if (!dir_file || IS_ERR(dir_file)) {
		tloge("open dyn dir failed\n");
		return;
	}

	g_context = context;
	g_dyn_dir = dyn_dir;
	g_load_type = load_type;
	ret = iterate_dir(dir_file, &dir_ctx);
	if (ret != 0) {
		tloge("iterate dynamic dir failed, ret %d\n", ret);
		goto clean;
	}

clean:
	if (dir_file != NULL) {
		filp_close(dir_file, 0);
		dir_file = NULL;
	}

	return;
}

#if defined(DYNAMIC_DIR_CONFIGURABLE)
#if defined(DYNAMIC_DRV_DIR) || defined(DYNAMIC_CRYPTO_DRV_DIR) || defined(DYNAMIC_SRV_DIR)
static void load_dynamic_by_splic_path(struct teec_context *context, const char *dyn_dir_path_base,
				    const char *dyn_dir_path_add, uint32_t load_type)
{
	int ret = EOK;
	char dyn_dir[MAX_FILE_NAME_LEN] = {0};
	ret = strcpy_s(dyn_dir, MAX_FILE_NAME_LEN, dyn_dir_path_base);
	if (ret != EOK) {
		tloge("Load dynamic failed: strcpy_s failed!\n");
		return;
	}
	if (dyn_dir_path_add != NULL) {
		if (strstr(dyn_dir_path_add, "..") != NULL) {
			tloge("only support single-layer path\n");
			return;
		}
		ret = strcat_s(dyn_dir, MAX_FILE_NAME_LEN, dyn_dir_path_add);
		if (ret != EOK) {
			tloge("strcat_s failed! Failed to load dynamic dir, please check \
			       whether the absolute path of the driver exceeds %d.\n", MAX_FILE_NAME_LEN);
			return;
		}
	}
	load_one_dynamic_dir(context, dyn_dir, load_type);
}
#endif
#endif

#if defined(DYNAMIC_DIR_CONFIGURABLE)
void tz_load_dynamic_dir(const char *dyn_drv_dir_add, const char *dyn_srv_dir_add, const char *dyn_crypto_dir_add)
#else
void tz_load_dynamic_dir(void)
#endif
{
	struct teec_context context;
	int32_t ret = (int32_t)teek_initialize_context(NULL, &context);
	if (ret != TEEC_SUCCESS) {
		tloge("teek init context failed, ret %d\n", ret);
		return;
	}

	tlogd("tz load dynamic dir\n");
#ifdef DYNAMIC_DIR_CONFIGURABLE
#ifdef DYNAMIC_CRYPTO_DRV_DIR
	load_dynamic_by_splic_path(&context, DYNAMIC_CRYPTO_DRV_DIR, dyn_crypto_dir_add, LOAD_DYNAMIC_DRV);
#endif
#ifdef DYNAMIC_DRV_DIR
	load_dynamic_by_splic_path(&context, DYNAMIC_DRV_DIR, dyn_drv_dir_add, LOAD_DYNAMIC_DRV);
#endif
#ifdef DYNAMIC_SRV_DIR
	load_dynamic_by_splic_path(&context, DYNAMIC_SRV_DIR, dyn_srv_dir_add, LOAD_SERVICE);
#endif
#else /* DYNAMIC_DIR_CONFIGURABLE */
#ifdef DYNAMIC_CRYPTO_DRV_DIR
	load_one_dynamic_dir(&context, DYNAMIC_CRYPTO_DRV_DIR, LOAD_DYNAMIC_DRV);
#endif
#ifdef DYNAMIC_DRV_DIR
	load_one_dynamic_dir(&context, DYNAMIC_DRV_DIR, LOAD_DYNAMIC_DRV);
#endif
#ifdef DYNAMIC_SRV_DIR
	load_one_dynamic_dir(&context, DYNAMIC_SRV_DIR, LOAD_SERVICE);
#endif
#endif /* DYNAMIC_DIR_CONFIGURABLE */
	teek_finalize_context(&context);
}

#endif
