/*
 * ffts_common.c
 *
 * ffts device driver
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

#include "ffts_common.h"

#include <linux/uaccess.h>

#include "ffts_log.h"

static struct ffts_dev_ctx *g_ffts_dev_ctx = NULL;

void ffts_set_dev_ctx(struct ffts_dev_ctx *dev_ctx)
{
	g_ffts_dev_ctx = dev_ctx;
}

struct ffts_dev_ctx *ffts_get_dev_ctx(void)
{
	return g_ffts_dev_ctx;
}

int ffts_copy_from_user_safe(void *to, const void __user *from, unsigned long len)
{
	if (from == NULL || len == 0) {
		ffts_drv_err("user pointer is NULL\n");
		return -EINVAL;
	}

	if (copy_from_user(to, from, len) != 0)
		return -ENODEV;
	return 0;
}

int ffts_copy_to_user_safe(void __user *to, const void *from, unsigned long len)
{
	if (to == NULL || len == 0) {
		ffts_drv_err("user pointer is NULL or len(%lu) is 0\n", len);
		return -EINVAL;
	}

	if (copy_to_user(to, from, len) != 0)
		return -ENODEV;
	return 0;
}
