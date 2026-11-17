/*
 * ffts_ffap1_connect.c
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
#include "ffts_ffap1_connect.h"
#include "ffts_common.h"
#include "ffts_log.h"

hw_ffap1_connect_cb g_hw_ffap1_connect_cb[FFTS_HW_MAX];
 
int ffts_ffap1_cb_regist(void* connect_cb, void* disconnect_cb, ffts_hw_t hw_type)
{
	cond_return_error(hw_type >= FFTS_HW_MAX, -EINVAL, "hw type %d is invalid", hw_type);

	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev_ctx is null");

	dev_ctx->ffap1_register_status[hw_type] = true;
	g_hw_ffap1_connect_cb[hw_type].connect_cb = connect_cb;
	g_hw_ffap1_connect_cb[hw_type].disconnect_cb = disconnect_cb;

	ffts_drv_warn("register cb succ, hw_type = %d\n", hw_type);
	return 0;
}
EXPORT_SYMBOL(ffts_ffap1_cb_regist);
 
int ffts_ffap1_cb_unregist(ffts_hw_t hw_type)
{
	cond_return_error(hw_type >= FFTS_HW_MAX, -EINVAL, "hw type %d is invalid", hw_type);

	struct ffts_dev_ctx *dev_ctx = ffts_get_dev_ctx();
	cond_return_error(dev_ctx == NULL, -EINVAL, "dev_ctx is null");

	dev_ctx->ffap1_register_status[hw_type] = false;
	g_hw_ffap1_connect_cb[hw_type].connect_cb = NULL;
	g_hw_ffap1_connect_cb[hw_type].disconnect_cb = NULL;

	ffts_drv_warn("unregister cb succ, hw_type = %d\n", hw_type);
	return 0;
}
EXPORT_SYMBOL(ffts_ffap1_cb_unregist);