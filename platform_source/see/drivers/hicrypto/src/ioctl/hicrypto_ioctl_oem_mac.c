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
#include "hicrypto_alg_oeminfo_mac.h"
#include "hicrypto_inner_mac.h"

#define BSP_THIS_MODULE BSP_MODULE_SCE

static int hicrypto_oem_param_check(struct hicrypto_oem_mac_info *info)
{
	if(pal_check(info == NULL)) {
		pal_error("hicrypto_oem_param_check info is null.\n");
		return err_api(ERRCODE_NULL);
	}
	if(pal_check(info->in == NULL || info->out == NULL || info->salt == NULL)) {
		pal_error("hicrypto_oem_param_check info content is null.\n");
		return err_api(ERRCODE_NULL);
	}
	return BSP_RET_OK;
}

int hicrypto_ioctl_oeminfo_mac(struct hicrypto_oem_mac_info *info)
{
	int ret = err_api(ERRCODE_UNKNOWN);
	struct hicrypto_oem_mac_info inner_info = {0};

	ret = hicrypto_oem_param_check(info);
	if (pal_check(ret != BSP_RET_OK))
		return err_api(ERRCODE_PARAMS);

	inner_info.salt = info->salt;
	inner_info.salt_len = info->salt_len;
	inner_info.in = info->in;
	inner_info.in_len = info->in_len;
	inner_info.out = info->out;
	inner_info.out_len = info->out_len;
	pal_hit_start("oeminfo_mac");
	ret = hicrypto_oeminfo_mac(&inner_info);
	pal_hit_end("oeminfo_mac");
	if (pal_check(ret != BSP_RET_OK)) {
		pal_error("hicrypto_ioctl_oeminfo_mac ret 0x%x fail.\n", ret);
		return ret;
	}
	info->out_len = inner_info.out_len;
	return 0;
}