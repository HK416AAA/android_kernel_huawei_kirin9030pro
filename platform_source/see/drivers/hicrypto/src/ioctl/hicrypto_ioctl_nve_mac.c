/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: hardware crypto engine ioctl driver
 * Create: 2024/12/23
 */
#include <linux/fs.h>
#include <linux/compat.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#include "hicrypto_ioctl.h"
#include "hicrypto_utils.h"
#include "hicrypto_log.h"
#include "hicrypto_errno.h"
#include "hicrypto_macro.h"
#include "hicrypto_dft.h"
#include "hicrypto_inner_mac.h"

#include "platform_include/see/hicrypto_engine.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static int hicrypto_nve_param_check(struct hicrypto_nve_mac_info *info)
{
	if(pal_check(info->in == NULL || info->out == NULL || info->salt == NULL)) {
		pal_error("hicrypto_nve_param_check input is null.\n");
		return err_api(ERRCODE_NULL);
	}
	if (pal_check(info->in_len == 0 || info->out_len == 0 || info->salt_len == 0)) {
		pal_error("hicrypto_nve_param_check check len fail.\n");
		return err_api(ERRCODE_PARAMS);
	}
	if (pal_check(info->salt_len != HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);

	if (pal_check(info->out_len < HISI_SYMM_BLKLEN_AES))
		return err_api(ERRCODE_PARAMS);
	return BSP_RET_OK;
}

int hicrypto_ioctl_nve_mac(struct hicrypto_nve_mac_info *info)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	unsigned char *tmp_in = NULL;
	unsigned char *tmp_out = NULL;
	unsigned char *tmp_salt = NULL;
	struct hicrypto_nve_mac_info inner_info = {0};

	ret = hicrypto_nve_param_check(info);
	if (pal_check(ret != BSP_RET_OK))
		return err_api(ERRCODE_PARAMS);

	// kmalloc has a limit size when copy to kernel directly
	if (pal_check(info->in_len > MAX_OEM_MAC_APP_DIN_SIZE)) {
		pal_error("hicrypto_ioctl_nve_mac check len too big.\n");
		return err_api(ERRCODE_INVALID);
	}

	tmp_in = kzalloc(info->in_len, GFP_KERNEL);
	if (pal_check(tmp_in == NULL)) {
		pal_error("hicrypto_ioctl_nve_mac alloc in failed.\n");
		return err_api(ERRCODE_MEMORY);
	}

	tmp_out = kzalloc(info->out_len, GFP_KERNEL);
	if (pal_check(tmp_out == NULL)) {
		ret = err_api(ERRCODE_MEMORY);
		pal_error("hicrypto_ioctl_nve_mac alloc out failed.\n");
		goto end_handle;
	}

	tmp_salt = kzalloc(info->salt_len, GFP_KERNEL);
	if (pal_check(tmp_salt == NULL)) {
		ret = err_api(ERRCODE_MEMORY);
		pal_error("hicrypto_ioctl_nve_mac alloc salt failed.\n");
		goto end_handle;
	}

	ret = copy_from_user(tmp_in, (const void *)info->in, info->in_len);
	if (pal_check(ret != 0)) {
		pal_error("hicrypto_ioctl_nve_mac in copy_from_user 0x%x fail.\n", ret);
		goto end_handle;
	}
	ret = copy_from_user(tmp_out, (const void *)info->out, info->out_len);
	if (pal_check(ret != 0)) {
		pal_error("hicrypto_ioctl_nve_mac out copy_from_user 0x%x fail.\n", ret);
		goto end_handle;
	}

	ret = copy_from_user(tmp_salt, (const void *)info->salt, info->salt_len);
	if (pal_check(ret != 0)) {
		pal_error("hicrypto_ioctl_nve_mac out copy_from_user 0x%x fail.\n", ret);
		goto end_handle;
	}

	inner_info.salt = tmp_salt;
	inner_info.salt_len = info->salt_len;
	inner_info.in = tmp_in;
	inner_info.in_len = info->in_len;
	inner_info.out = tmp_out;
	inner_info.out_len = info->out_len;
	pal_hit_start("hicrypto_nve_mac");
	ret = hicrypto_nve_mac(&inner_info);
	if (pal_check(ret != 0)) {
		pal_error("hicrypto_ioctl_nve_mac ret 0x%x fail.\n", ret);
		goto end_handle;
	}
	pal_hit_end("hicrypto_nve_mac");
	info->out_len = inner_info.out_len;
	ret = copy_to_user(info->out, (const void *)tmp_out, info->out_len);
	if (pal_check(ret != 0)) {
		pal_error("hicrypto_ioctl_nve_mac out copy_to_user 0x%x fail.\n", ret);
		goto end_handle;
	}
end_handle:
	if (tmp_in != NULL) {
		kfree(tmp_in);
		tmp_in = NULL;
	}
	if (tmp_out != NULL) {
		kfree(tmp_out);
		tmp_out = NULL;
	}
	if (tmp_salt != NULL) {
		kfree(tmp_salt);
		tmp_salt = NULL;
	}
	return ret;
}