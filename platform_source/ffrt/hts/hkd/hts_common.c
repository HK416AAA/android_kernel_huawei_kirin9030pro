/*
 * hts_common.c
 *
 * hts device driver
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "hts_common.h"

#include <linux/uaccess.h>

#include "hts_kernel_log.h"

static struct hts_dev_ctx g_hts_dev_ctx = {0};

struct hts_dev_ctx *hts_get_dev_ctx(void)
{
	return &g_hts_dev_ctx;
}

int hts_copy_from_user_safe(void *to, const void __user *from, unsigned long len)
{
	if (from == NULL || len == 0) {
		hts_drv_err("user pointer is NULL\n");
		return -EINVAL;
	}

	if (copy_from_user(to, from, len) != 0)
		return -ENODEV;
	return 0;
}

int hts_copy_to_user_safe(void __user *to, const void *from, unsigned long len)
{
	if (to == NULL || len == 0) {
		hts_drv_err("user pointer is NULL or len(%lu) is 0\n", len);
		return -EINVAL;
	}

	if (copy_to_user(to, from, len) != 0)
		return -ENODEV;
	return 0;
}
