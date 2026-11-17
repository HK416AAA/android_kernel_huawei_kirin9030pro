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
 * MinTP Tail Delay Latency Alg
 */

#ifndef TAIL_DELAY_H
#define TAIL_DELAY_H

#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/inetdevice.h>
#include <linux/printk.h>
#include <linux/swap.h>
#include <linux/slab.h>
#include <linux/sched/signal.h>
#include <linux/signal.h>

#define CHANNEL_COUNT 2
#define MAX_DELAY_LENGTH 15000
#define MIN_DELAY_LENGTH 1000
#define HISTORY_LENGTH 20

#define RATE_LOW_THRES 2 /* 0.02*100 */
#define RATE_HIGH_THRES 10 /* 0.1*100 */
#define MAX_DELAY 50000 /* us */
#define MIN_DELAY 20000 /* us */
#define TUNE_COEF 1000

enum Channel { BE = 0, VI = 1 };

typedef struct {
    u64 *delay_be;
    u64 *delay_vi;
    int arr_idx[CHANNEL_COUNT];
    int full_flag[CHANNEL_COUNT];

    u64 curr_rate;
    u64 history_p90[HISTORY_LENGTH];
    u64 history_p95[HISTORY_LENGTH];
    u64 history_p99[HISTORY_LENGTH];
    int history_count;

    int new_data_count;
    int update_flag;
    u64 last_retx_time;
    u64 new_retx_time;
} delay_tune_alg;

delay_tune_alg *init_alg(u64 re_tx_time);      /* 算法实例初始化 */
void de_init_alg(delay_tune_alg *implement);  /* 释放实例 */

void save_data(delay_tune_alg *implement, u64 delay, enum Channel chan);  /* 保存尾时延数据 */
void save_rate(delay_tune_alg *implement, u64 rate);                      /* 保存重传率 */
void run_alg(delay_tune_alg *implement);                                  /* 运行算法 */
u64 get_retry_rtt(delay_tune_alg *implement);  /* 返回重传时间门限（需要run_alg后再执行） */

#endif  /* TAIL_DELAY_H */