/*
 * ffts_devinit.h
 *
 * ffts device head file
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

#ifndef _FFTS_DEVINIT_H_
#define _FFTS_DEVINIT_H_

#include <linux/types.h>
#include <linux/atomic.h>

int ffts_dev_register(void);
void ffts_dev_unregister(void);

#endif