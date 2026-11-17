/* SPDX-License-Identifier: GPL-2.0 */
/*
 * teardown_detect.h
 *
 * teardown detect header
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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

#ifndef _TEARDOWN_DETECT_H_
#define _TEARDOWN_DETECT_H_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <chipset_common/hwpower/common_module/power_algorithm.h>
#include <linux/mutex.h>

#define MAX_TEARDOWN_BATTERY_DEV_TOTAL      20
#define DELAY_TEARDOWN_DETECT_WORK          10000 /* 10s */
#define TEARDOWN_DETECT_EVENT_MAX_NUM       12

/* bit define */
#define TEARDOWN_EVENT_BATTERY_MASK         BIT(0)
#define TEARDOWN_EVENT_COVER_MASK           BIT(1)
#define TEARDOWN_EVENT_TIMECALI_MASK        BIT(6)
#define TEARDOWN_EVENT_AFTERSALE_MASK       BIT(7)

/* time define */
#define YEAR_SAVE_OFFSET                    1900
#define YEAR_SAVE_CALI_BENCHMARK            2025
#define MOUTH_SAVE_OFFSET                   1
#define YEAR_CAL_OFFSET                     1000000
#define MOUTH_CAL_OFFSET                    10000
#define DAY_CAL_OFFSET                      100

#define EVENT_SAVE_SOC_TH                   10

enum event_nv_type {
	EVENT_WRITE = 0,
	EVENT_AFTERSALE_MARK,
	EVENT_TIME_REFRESH,
	EVENT_NV_TYPE_END,
};
struct event_time {
	int8_t year;
	int8_t month;
	int8_t day;
	int8_t hour;
};

/* reserver byte use for event flag, do not change */
struct teardown_detect_event {
	uint8_t event_info;
	int8_t reserver0;
	int8_t reserver1;
	int8_t reserver2;
	struct event_time time;
};

/* reserver byte use for nv flag, do not change */
struct teardown_event_nv_data {
	struct teardown_detect_event event[TEARDOWN_DETECT_EVENT_MAX_NUM];
	int8_t reserver0;
	int8_t reserver1;
	int8_t reserver2;
	int8_t reserver3;
	int8_t reserver4;
	int8_t reserver5;
	int8_t reserver6;
	int8_t reserver7;
};

struct teardown_battery_info_data {
	struct list_head info_node;
	const char *dev_name;
	int8_t poweroff_flag;
};

struct teardown_detect_dev {
	struct device *dev;
	struct delayed_work monitor_work;
	int8_t init_reset_en;
	int8_t aftersale_en;
	int aftersale_time;
	int8_t newboard_clear_en;
	int8_t refresh_flag;
	struct mutex nv_write_lock;
	struct notifier_block cover_notify;
};

typedef int (*event_nv_info)(int info_in, struct teardown_event_nv_data *event_nv_read,
	struct teardown_event_nv_data *event_nv_save);

#ifdef CONFIG_HUAWEI_TEARDOWN_DETECT
int teardown_battery_device_info_register(const char *dev_name, int poweroff_flag);
#else
static inline int teardown_battery_device_info_register(const char *dev_name, int poweroff_flag)
{
	return -EINVAL;
}
#endif

#endif /* _TEARDOWN_DETECT_H_ */
