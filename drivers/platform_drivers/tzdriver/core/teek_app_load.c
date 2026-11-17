/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
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

#include "teek_app_load.h"
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/kthread.h>
#include <securec.h>
#include "session_manager.h"
#include "ko_adapt.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"

void teek_free_app(bool load_app_flag, char **file_buf)
{
	if (load_app_flag && file_buf != NULL && *file_buf != NULL) {
		vfree(*file_buf);
		*file_buf = NULL;
	}
}

int32_t teek_get_app(const char *ta_path, char **file_buf, uint32_t *file_len)
{
	int32_t ret = teek_read_app(ta_path, file_buf, file_len);
	if (ret != TEEC_SUCCESS)
		tloge("teec load app error %d\n", ret);

	return ret;
}

bool load_ta_from_default_path(struct tc_ns_client_context *context, bool *is_kernal_load)
{
	(void)context;
	*is_kernal_load = false;
	return false;
}
