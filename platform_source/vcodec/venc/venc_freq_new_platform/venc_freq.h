/*
 * venc_freq.h
 *
 * This is venc freq.
 *
 * Copyright (c) 2025-2025 Huawei Technologies CO., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __VENC_FREQ_H__
#define __VENC_FREQ_H__

typedef enum {
	VENC_CLK_RATE_LOWER = VENC_CLK_RATE_LEVEL_MAX - 4,
	VENC_CLK_RATE_LOW,
	VENC_CLK_RATE_NORMAL,
	VENC_CLK_RATE_HIGH,
	VENC_CLK_BUTT,
} venc_clk_t;

#endif
