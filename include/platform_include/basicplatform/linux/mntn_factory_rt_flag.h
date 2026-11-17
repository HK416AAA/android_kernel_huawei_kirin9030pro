/*
 * mntn_factory_rt_flag.h
 *
 * get factory rt_flag of mntn.
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
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

#ifndef __MNTN_FACTORY_RT_FLAG_H
#define __MNTN_FACTORY_RT_FLAG_H

#include <linux/types.h>

int get_rt_flag(const void *rdr_memory, size_t rdr_size, char *out_buf, size_t buf_size);

#endif
