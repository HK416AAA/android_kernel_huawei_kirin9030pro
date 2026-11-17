/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
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

#ifndef __CPUFREQ_PERF_CTRL_H
#define __CPUFREQ_PERF_CTRL_H

struct cpu_busy_time {
	int cpu_count;
	u64 time_adj_freq[NR_CPUS];
};

#ifdef CONFIG_HUAWEI_FREQ_STATS_COUNTING_IDLE
extern int perf_ctrl_get_cpu_busy_time(void __user *uarg);
int perf_ctrl_get_cpu_busy_time(void __user *uarg);
#else
static inline int perf_ctrl_get_cpu_busy_time(void __user *uarg)
{
	return -ENODEV;
}
#endif

#endif
