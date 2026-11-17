/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
 * Author: liyue
 *
 * Util function of MinTP Tail Delay Latency Alg
 */

#ifndef UTILS_H
#define UTILS_H

#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/inetdevice.h>
#include <linux/printk.h>
#include <linux/swap.h>
#include <linux/slab.h>
#include <linux/sched/signal.h>
#include <linux/signal.h>

#define SCALE 20000LL
#define GRAD_SCALE 10000
#define ONE_HUNDRED 100

void calculate_cdf(u64 *data, int size, u64 *cdf);
u64 percentile(u64 *data, int size, u64 percent);
u64 *linspace(u64 start, u64 end, int num);
int remove_duplicates(u64 arr[], int n);
typedef struct {
	u64 *x;
	u64 *y;
	int n;
	u64 *xnew;
	u64 *ynew;
	int nnew;
} spline_interpolate_param;
void spline_interpolate(spline_interpolate_param spline_interpolate_p);
void compute_gradient(const u64 *y, const u64 *x, u64 *dy_dx, int n);
int find_max_index(u64 arr[], int size);

#endif  /* UTILS_H */
