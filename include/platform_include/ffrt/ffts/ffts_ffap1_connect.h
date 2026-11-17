/*
 * ffts_ffap1_connect.h
 *
 * ffts proc connect
 *
 * Copyright (c) 2024-2030 Huawei Technologies Co., Ltd.
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
#ifndef _FFTS_FFAP1_CONNECT_H_
#define _FFTS_FFAP1_CONNECT_H_

#include <linux/fs.h>
#include "ffts_types.h"

typedef struct{
	void (*connect_cb)(void);
	void (*disconnect_cb)(void);
} hw_ffap1_connect_cb;

void ffts_init_connect_cb_lock(void);
void ffts_destroy_connect_cb_lock(void);
int ffts_ffap1_cb_regist(void* connect_cb, void* disconnect_cb, ffts_hw_t hw_type);
int ffts_ffap1_cb_unregist(ffts_hw_t hw_type);
int ffts_udk_invoke_ffap1_connect_cb(void *rd, size_t rd_size);

#endif