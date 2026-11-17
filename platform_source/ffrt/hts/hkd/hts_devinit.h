/*
 * hts_devinit.h
 *
 * hts decive init head file
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

#ifndef __HTS_DEVINIT_H_
#define __HTS_DEVINIT_H_

#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/types.h>
#include "hts_common.h"

#define HTS_DEV_NUM  1

#define unused(expr) do { \
		(void)(expr); \
	} while (0)

int hts_dev_init(struct module *owner, uint8_t dev_id);
void hts_dev_exit(void);
#endif