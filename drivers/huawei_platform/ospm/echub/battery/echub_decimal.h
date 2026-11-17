/*
 * echub_decimal.h
 *
 * driver for echub_decimal
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#ifndef _LINUX_ECHUB_DECIMAL_H
#define _LINUX_ECHUB_DECIMAL_H

#define DECIMAL_PARA_LEVEL         8
#define DECIMAL_WINDOW_LEN         20

enum echub_decimal_para_item {
	DECIMAL_ITEM_TYPE = 0,
	DECIMAL_ITEM_MIN_PWR,
	DECIMAL_ITEM_MAX_PWR,
	DECIMAL_ITEM_BASE,
	DECIMAL_ITEM_SAMPLES,
	DECIMAL_ITEM_INTERVAL,
	DECIMAL_ITEM_NUM,
};

struct echub_decimal_para {
	u32 type;
	u32 min_pwr;
	u32 max_pwr;
	u32 base;
	u32 samples;
	u32 interval;
};

struct echub_decimal_fifo_data {
	u32 filter[DECIMAL_WINDOW_LEN];
	u32 sum; /* sum of filter data */
	u32 index; /* index of filter data */
	u32 curr_samples;
	u32 init_soc;
};

struct echub_decimal_calc {
	int base;
	int samples;
	int curr_samples;
	int init_soc;
	int curr_soc;
	int rep_soc;
	int round_soc;
	int remain_soc;
};

struct echub_decimal_info {
	bool start;
	u32 soc;
	int level;
	struct echub_decimal_fifo_data fifo;
	struct echub_decimal_para para;
};

struct echub_decimal_dev {
	struct device *dev;
	struct notifier_block nb;
	struct notifier_block soc_nb;
	struct hrtimer timer;
	struct work_struct echub_decimal_timer_work;
	int para_level;
	struct echub_decimal_para para[DECIMAL_PARA_LEVEL];
	struct echub_decimal_info info;
};

struct echub_decimal_dev *echub_decimal_get_dev(void);
#endif