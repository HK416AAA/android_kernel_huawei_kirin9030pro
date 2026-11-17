// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Thermal intelligent cpufreq ctrl.
 */
#include "sched.h"
#include <linux/cpufreq.h>
#include <trace/events/power.h>

unsigned int thermal_intelligent_ctrl;
#define DISABLE_HEAVY_LOAD_DETECT (1 << 0)

#define NR_RUN_HIST_SIZE 10 /* 20ms window * 10 = 200ms */
static unsigned int nr_run_hist[NR_RUN_HIST_SIZE];
static unsigned int nr_run_hist_idx;

static unsigned int nr_run_hist_avg(unsigned int windows)
{
	unsigned int sum = 0;
	unsigned int i = nr_run_hist_idx;
	int cnt;

	for (cnt = 0; cnt < windows; cnt++) {
		if (i >= NR_RUN_HIST_SIZE)
			i = 0;
		sum += nr_run_hist[i];
		i++;
	}
	return sum / windows;
}

#define HEAVY_LOAD_PCT 90
static bool nr_run_test_heavy_loaded(void)
{
	unsigned int avg = max(nr_run_hist_avg(NR_RUN_HIST_SIZE),
				nr_run_hist_avg(NR_RUN_HIST_SIZE / 2));
	return avg * 100 > num_online_cpus() * NR_AVG_AMP * HEAVY_LOAD_PCT;
}

static bool recent_is_heavy_loaded;
static void nr_run_update_history(unsigned int nr_run)
{
	nr_run_hist_idx++;
	if (nr_run_hist_idx >= NR_RUN_HIST_SIZE)
		nr_run_hist_idx = 0;
	nr_run_hist[nr_run_hist_idx] = nr_run;

	recent_is_heavy_loaded = nr_run_test_heavy_loaded();
}

static bool recent_heavy_loaded(void)
{
	if (thermal_intelligent_ctrl & DISABLE_HEAVY_LOAD_DETECT)
		return false;
	return recent_is_heavy_loaded;
}

void thermal_intelligent_update_busy(void)
{
	struct sched_nr_stat stat;
	cpumask_t cpus;
	unsigned int nr_run = 0;

	get_slow_cpus(&cpus);
	sched_get_cpus_running_avg(&cpus, &stat);
	nr_run += min(stat.avg, cpumask_weight(&cpus) + 1);

	get_fast_cpus(&cpus);
	sched_get_cpus_running_avg(&cpus, &stat);
	nr_run += stat.avg;

	nr_run_update_history(nr_run);
}

static atomic_t g_doframe_cnt;
static unsigned long g_doframe_start_ts;
void update_doframe_status(bool begin)
{
	if (begin) {
		int prev = atomic_fetch_inc(&g_doframe_cnt);
		if (prev == 0)
			g_doframe_start_ts = jiffies;
	} else {
		atomic_dec_if_positive(&g_doframe_cnt);
	}
	trace_perf(update_doframe_status, begin, atomic_read(&g_doframe_cnt));
}

#define DOFRAME_TIMEOUT HZ
static bool in_doframe(void)
{
	bool ret = false;
	if (atomic_read(&g_doframe_cnt) > 0) {
		if (time_after(jiffies, g_doframe_start_ts + DOFRAME_TIMEOUT))
			atomic_set(&g_doframe_cnt, 0);
		else
			ret = true;
	}
	return ret;
}

static atomic_t g_gc_wait_cnt;
static unsigned long g_gc_wait_start_ts;
void handle_art_gc_wait(bool begin)
{
	if (begin) {
		int prev = atomic_fetch_inc(&g_gc_wait_cnt);
		if (prev == 0)
			g_gc_wait_start_ts = jiffies;
	} else {
		atomic_dec_if_positive(&g_gc_wait_cnt);
	}
	trace_perf(handle_art_gc_wait, begin, atomic_read(&g_gc_wait_cnt));
}

#define GC_WAIT_TIMEOUT (2 * HZ)
static bool blocking_gc(void)
{
	bool ret = false;
	if (atomic_read(&g_gc_wait_cnt) > 0) {
		if (unlikely(time_after(jiffies, g_gc_wait_start_ts + GC_WAIT_TIMEOUT))) {
			/* In case of attack, cure itself. */
			atomic_set(&g_gc_wait_cnt, 0);
		} else {
			ret = true;
		}
	}
	return ret;
}

unsigned long last_vip_cgrp_active;
static DEFINE_PER_CPU(bool, is_vip_cgrp_thread);
static atomic_t g_nr_vip_cgrp_thread;
/* TODO rename to cpu_update_frame_vip_thread and use is_frame_vip(). */
static void cpu_update_vip_cgrp_thread(int cpu, struct task_struct *next)
{
	bool is_vip_cgrp = uclamp_cgrp_is_frame_vip(next);
	if (is_vip_cgrp)
		last_vip_cgrp_active = jiffies;

	if (per_cpu(is_vip_cgrp_thread, cpu) == is_vip_cgrp)
		return;
	per_cpu(is_vip_cgrp_thread, cpu) = is_vip_cgrp;

	if (is_vip_cgrp)
		atomic_inc(&g_nr_vip_cgrp_thread);
	else
		atomic_dec(&g_nr_vip_cgrp_thread);
}

/*
 * Note that binders are not accounted here. Maybe we can fix it
 * later. Seems not a big problem?
 * And note that we can't use test_vip_thread(). Better less than
 * more so the priority inversion issue can be solved.
 */
static int nr_running_frame_task(void)
{
	return atomic_read(&g_nr_vip_cgrp_thread);
}

#define TYPICAL_FRAME_SIZE msecs_to_jiffies(16)
static bool recent_running_frame_task(void)
{
	return time_after(jiffies, last_vip_cgrp_active + TYPICAL_FRAME_SIZE);
}

/* TODO better limited to app, at least for douyin's pool-* and Thread-*. */
static const char * const may_block_key_thread_startwith[] = {
	/* wechat */
	"[GT]ColdPool",
	"[GT]HotPool",
	"Metric_Kit",
	"tencent.mm:push",
	"wc_srvinit",
	"X2C_LAYOUT_THRE",
	"queued-work-loo",
	"MMCrashANRThrea",
	"matrix_li",
	"[D]#worker",
	/* douyin */
	"play_thread",
	"LegoHandler",
	"lynx_report_thr",
	"Lynx_JS",
	"pool-3",
	"pool-2",
	"AsyncInflateHan",
	"#RxComputationT",
	"#Account-ApiDis",
	"DefaultDispatch",
	"VE-GLGraph-0x76",
	"Thread-5",
	"Thread-7", /* TODO */
	/* toutiao */
	"platform_defaul",
	"platform_io_thr",
	"platform-io-thr",
	"ThreadPoolForeg",
	/* common */
	"SharedPreferenc",
	/* alipay */
	"queued-work-loo",
	"antsp-load-1-th",
	/* tecent video */
	"StartupPool",
	"Idle thread",
	/* meituan */
	"J#",
};

static bool check_may_block_key_thread(struct task_struct *p)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(may_block_key_thread_startwith); i++) {
		if (strncmp(p->comm, may_block_key_thread_startwith[i],
			strlen(may_block_key_thread_startwith[i])) == 0)
			return true;
	}
	return false;
}

static const char * const longterm_key_thread[] = {
	/* common */
	"CrRendererMain",
	"CrGpuMain",
	"Chrome_IOThread",
	"Chrome_InProcGp",
	"JNISurfaceTextu",
	/* pinduoduo */
	"RV#HT",
	/* zhihu */
	"ZH_RxCachedThre",
};

/* Support only '?' now. '?' for any single char. */
static const char * const longterm_key_thread_wildcard[] = {
	"?.ui",
	"?.raster",
};

static bool match_wildcard(const char *str, const char *pattern)
{
	while (*str && *pattern) {
		if (*str == *pattern || *pattern == '?') {
			str++;
			pattern++;
		} else {
			/* We can support '*' here, but it's inefficient. */
			return false;
		}
	}
	return *str == '\0' && *pattern == '\0';
}

static bool check_longterm_key_thread(struct task_struct *p)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(longterm_key_thread); i++) {
		if (strcmp(p->comm, longterm_key_thread[i]) == 0)
			return true;
	}

	for (i = 0; i < ARRAY_SIZE(longterm_key_thread_wildcard); i++) {
		if (match_wildcard(p->comm, longterm_key_thread_wildcard[i]))
			return true;
	}

	return false;
}

void thermal_intelligent_whitelist_update(struct task_struct *p)
{
	if (check_longterm_key_thread(p))
		p->whitelist_properties |= THERMAL_INTE_LONGTERM_KEYTHREAD;
	else
		p->whitelist_properties &= ~THERMAL_INTE_LONGTERM_KEYTHREAD;

	if (check_may_block_key_thread(p))
		p->whitelist_properties |= THERMAL_INTE_MAY_BLOCK_KEYTHREAD;
	else
		p->whitelist_properties &= ~THERMAL_INTE_MAY_BLOCK_KEYTHREAD;
}

static bool is_whitelist_keythread(struct task_struct *p)
{
	if (p->whitelist_properties & THERMAL_INTE_LONGTERM_KEYTHREAD)
		return true;

	if (p->whitelist_properties & THERMAL_INTE_MAY_BLOCK_KEYTHREAD)
		if (!nr_running_frame_task())
			return true;

	return false;
}

static bool test_key_thread(struct task_struct *p)
{
	return	(is_heavy_rt(p) && p->rt_priority > VIP_PRIO_WIDTH) ||
		get_max_vip_prio_except(p, VIP_BOOST_CGROUP) > 0 ||
		test_task_vip(p) ||
		is_whitelist_keythread(p) ||
		((p->flags & PF_KSWAPD) && !recent_running_frame_task());
}

static DEFINE_PER_CPU(bool, is_keythread);
static bool cpu_update_keythread(int cpu, struct task_struct *next)
{
	bool is_key;

	is_key = test_key_thread(next);
	if (per_cpu(is_keythread, cpu) == is_key)
		return false;

	if (nr_iowait_cpu(cpu) && per_cpu(is_keythread, cpu))
		return false;

	per_cpu(is_keythread, cpu) = is_key;
	return true;
}

static bool cpufreq_policy_update_keythread(struct cpufreq_policy *policy)
{
	int i;
	bool has_keythread = false;

	for_each_cpu(i, policy->cpus) {
		if (per_cpu(is_keythread, i)) {
			has_keythread = true;
			break;
		}
	}

	if (policy->has_keythread == has_keythread)
		return false;

	policy->has_keythread = has_keythread;
	return true;
}

static const char *thermal_dev_name[] = {
	"thermal_inte0",
	"thermal_inte1",
	"thermal_inte2"
};

static const char *trace_name(int cpu)
{
	unsigned int cluster_id = cpu_rq(cpu)->cluster->id;
	if (cluster_id >= ARRAY_SIZE(thermal_dev_name))
		cluster_id = 0;
	return thermal_dev_name[cluster_id];
}

unsigned int thermal_freq_ctrl_enable = 0;

static bool may_priority_inversion(void)
{
	return (in_doframe() && !nr_running_frame_task()) ||
		recent_heavy_loaded() ||
		blocking_gc();
}

static bool thermal_intelligent_should_apply_limit(struct cpufreq_policy *policy)
{
	return thermal_freq_ctrl_enable &&
		!policy->has_keythread &&
		!render_rt_inited() &&
		!may_priority_inversion();
}

static bool frame_rtg_task(struct task_struct *p)
{
	return p->prio == 87;
}

static void check_cpufreq_update(int cpu, struct cpufreq_policy *policy,
				 struct task_struct *next)
{
	bool should_limit = thermal_intelligent_should_apply_limit(policy);
	unsigned int curr_freq = policy->cur;
	unsigned int max_freq = policy->max;
	unsigned int limit_freq = policy->thermal_intelligent_freq_limit;
	unsigned int flags = 0;

	if (should_limit && curr_freq > limit_freq) {
		flags = THERMAL_INTELLIIGENT_LIMIT | FORCE_UPDATE;
	} else if (!should_limit && curr_freq == limit_freq && curr_freq < max_freq) {
		flags = THERMAL_INTELLIIGENT_LIMIT;
		if (frame_rtg_task(next) || per_cpu(is_vip_cgrp_thread, cpu))
			flags |= FORCE_UPDATE;
	}

	if (flags)
		sugov_mark_util_change(cpu, flags);

	trace_perf(thermal_intelligent_cpu_update, cpu, should_limit,
		policy->has_keythread, may_priority_inversion());
	trace_perf(clock_set_rate, trace_name(cpu),
		should_limit ? policy->thermal_intelligent_freq_limit
		: policy->cpuinfo.max_freq, cpu);
}

void thermal_intelligent_update(int cpu, struct task_struct *next)
{
	struct cpufreq_policy *policy = cpufreq_cpu_get_raw(cpu);

	cpu_update_vip_cgrp_thread(cpu, next);

	if (test_slow_cpu(cpu) || !policy)
		return;

	if (!cpu_update_keythread(cpu, next))
		return;
	if (!cpufreq_policy_update_keythread(policy))
		return;

	check_cpufreq_update(cpu, policy, next);
}

unsigned int thermal_intelligent_freq_limit(struct cpufreq_policy *policy)
{
	if (policy && thermal_intelligent_should_apply_limit(policy))
		return policy->thermal_intelligent_freq_limit;

	return UINT_MAX;
}
