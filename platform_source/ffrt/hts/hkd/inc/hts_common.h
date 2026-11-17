/*
 * hts_common.h
 *
 * hts device context head file
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

#ifndef __HTS_COMMON_H_
#define __HTS_COMMON_H_

#include <linux/types.h>
#include <linux/mutex.h>
#include <linux/cdev.h>
#include <linux/atomic.h>
#include <linux/bitmap.h>
#include "hts_common_resource.h"
#include "ffrt_configs.h"

#define HTS_BUF_LEN_MAX 256

struct hts_dev_resource {
	uint16_t rule_num;
	uint16_t event_num[MAX_ALLOC_TYPE];
	DECLARE_BITMAP(event_bitmap, HTS_MAX_EVENT_NUM + 1);
	DECLARE_BITMAP(rule_bitmap, HTS_MAX_RULE_NUM + 1);
};

struct hts_dev_ctx {
	struct cdev hts_cdev;
	struct device *hts_dev;
	struct mutex mtx;
	atomic_t dev_power_status[SOC_IPMAX];
	struct hts_dev_resource res;
};

struct hts_dev_ctx *hts_get_dev_ctx(void);
int hts_copy_from_user_safe(void *to, const void __user *from, unsigned long len);
int hts_copy_to_user_safe(void __user *to, const void *from, unsigned long len);

#endif /* __HTS_COMMON_H_ */
