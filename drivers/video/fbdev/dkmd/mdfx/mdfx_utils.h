/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
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

#ifndef MDFX_UTILS_H
#define MDFX_UTILS_H

#include <linux/time.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/rtc.h>
#include <linux/of.h>

#define PRIx64 "llx"
#define PRIu64 "llu"
#define PRId64 "lld"

#define log_and_return_if(cond, msg) \
	do { \
		if (cond) { \
			mdfx_pr_err(msg); \
			return; \
		} \
	} while(0)

struct mdfx_time {
	struct rtc_time tm_rtc;
	struct timespec64 tv;
};

struct mdfx_pri_data;

void mdfx_get_rtc_time(struct mdfx_time *dt);
void mdfx_sysfs_init(struct mdfx_pri_data *mdfx_data);
void mdfx_sysfs_append_attrs(struct mdfx_pri_data *mdfx_data, struct attribute *attr);
void mdfx_sysfs_create_attrs(struct platform_device *pdev);
void mdfx_sysfs_remove_attrs(struct platform_device *pdev);
uint32_t mdfx_get_bits(uint64_t value);
int mdfx_get_msg_header(char *buf, uint32_t buf_max_len);
int mdfx_get_file_name_timestamp(char *buf, uint32_t buf_max_len);
int mdfx_query_sysinfo(struct mdfx_pri_data *mdfx_data, void __user *argp);


#endif /* MDFXUTILS_H */
