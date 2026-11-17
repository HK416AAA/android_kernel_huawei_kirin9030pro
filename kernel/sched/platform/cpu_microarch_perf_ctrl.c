// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Tuning cpu microarchitecture features for better perf/power user experience.
 */
#ifdef CONFIG_MPAM
#include <platform_include/cee/linux/mpam_sched.h>
#endif
#include "sched.h"
#include <securec.h>
#include <platform_include/cee/linux/mips_mem.h>
#ifdef CONFIG_BIG_MODEL_MONITOR_CPU
#include <platform_include/cee/linux/bmm.h>
#endif

#define KEY_THREAD_HIST_SIZE 3
struct cpu_key_thread_lt {
	bool curr_state;
	u64 last_update;
	u64 key_thread_last_update;
	u64 cum_key_thread_time;
	u64 last_cum;
	u64 last_rollover;
	u16 hist[KEY_THREAD_HIST_SIZE];
};
static DEFINE_PER_CPU(struct cpu_key_thread_lt, key_thread_lt);

static bool cpus_too_heavy_loaded(void)
{
	struct sched_nr_stat stat;
	cpumask_t cpus;

	cpumask_andnot(&cpus, cpu_online_mask, cpu_isolated_mask);

	sched_get_cpus_running_avg(&cpus, &stat);

	return stat.avg > cpumask_weight(&cpus) * NR_AVG_AMP * 8 / 10;
}

/* Open when each of recent 3 windows has >50% load of key thread. */
#define DEFAULT_OPEN_WINDOWS	3
/* Close when each of recent 2 windows has <50% load of key thread. */
#define DEFAULT_CLOSE_WINDOWS	2
#define ENABLE_THRESHOLD (SCHED_CAPACITY_SCALE / 2)

static void update_mips_mem_shoot_max(u32 *hist, int hist_size)
{
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
	int i;
	bool open = true, close = true;

	for (i = 0; i < hist_size; i++) {
		if (i < DEFAULT_OPEN_WINDOWS)
			open = open && (hist[i] > ENABLE_THRESHOLD);
		if (i < DEFAULT_CLOSE_WINDOWS)
			close = close && (hist[i] < ENABLE_THRESHOLD);
	}

	if (close)
		set_mips_mem_shoot_max(false);
	else if (open)
		set_mips_mem_shoot_max(true);
#endif
}

static void stop_mips_mem_shoot_max(void)
{
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
	set_mips_mem_shoot_max(false);
#endif
}

#ifdef CONFIG_MPAM
static void update_mpam_speedup_policy(u32 *hist, int hist_size)
{
	int i;
	bool open = true, close = true;

	/*
	 * It's dangrous to use MPAM when all cpus are very heavy loaded:
	 * 1. Higher possibility of priority inversion. 2. More loss of
	 * of throuhput. 3. Measurable power consumption at appstart.
	 * We give up small benifit to get rid of big risks.
	 */
	if (cpus_too_heavy_loaded()) {
		update_mpam_speedup(MPAM_SPEEDUP_STOP);
		return;
	}

	for (i = 0; i < hist_size; i++) {
		if (i < DEFAULT_OPEN_WINDOWS)
			open = open && (hist[i] > ENABLE_THRESHOLD);
		if (i < DEFAULT_CLOSE_WINDOWS)
			close = close && (hist[i] < ENABLE_THRESHOLD);
	}

	if (close)
		update_mpam_speedup(MPAM_SPEEDUP_STOP);
	else if (open)
		update_mpam_speedup(MPAM_SPEEDUP_START);
	else
		update_mpam_speedup(MPAM_SPEEDUP_KEEP);
}

static void stop_mpam_speedup_policy(void)
{
	update_mpam_speedup(MPAM_SPEEDUP_STOP);
}
#endif

#define BIGMODEL_KEYTHREAD_ACTIVE_US	200000L /* 200ms */
static void update_bigmodel_cpuperf_protect(s64 recent_keythread_active)
{
#ifdef CONFIG_BIG_MODEL_MONITOR_CPU
	bmm_set_cpu_perf_protect(ktime_to_us(recent_keythread_active) < BIGMODEL_KEYTHREAD_ACTIVE_US);
#endif
}

static void stop_bigmodel_cpuperf_protect(void)
{
#ifdef CONFIG_BIG_MODEL_MONITOR_CPU
	bmm_set_cpu_perf_protect(0);
#endif
}

#define CAP_REQUIRE	900UL
static void update_cpu_microarch_speedup(u64 now)
{
	int cpu, i;
	u32 max_hist[KEY_THREAD_HIST_SIZE] = {0};
	u64 key_thread_last_update;

	/* High cpufreq as a common necessary condition. */
	if (capacity_curr_of(cpumask_first(&max_cap_cluster()->cpus))
	    < CAP_REQUIRE) {
		stop_mips_mem_shoot_max();
#ifdef CONFIG_MPAM
		stop_mpam_speedup_policy();
#endif
		stop_bigmodel_cpuperf_protect();
		return;
	}

	key_thread_last_update = 0;
	for_each_cpu(cpu, &max_cap_cluster()->cpus) {
		struct cpu_key_thread_lt *lt = &per_cpu(key_thread_lt, cpu);
		for (i = 0; i < KEY_THREAD_HIST_SIZE; i++)
			max_hist[i] = max(max_hist[i], lt->hist[i]);
		key_thread_last_update = max(key_thread_last_update, lt->key_thread_last_update);
	}

	update_bigmodel_cpuperf_protect(now - key_thread_last_update);
	update_mips_mem_shoot_max(max_hist, KEY_THREAD_HIST_SIZE);
#ifdef CONFIG_MPAM
	update_mpam_speedup_policy(max_hist, KEY_THREAD_HIST_SIZE);
#endif
}

static bool test_key_thread(struct task_struct *p)
{
	if (render_rt_inited())
		return false;

	return test_task_vip(p) || (p->rt_priority > 1);
}

#define IOWAIT_BIAS (1 * NSEC_PER_MSEC)
static void cpu_key_thread_update(int cpu, struct task_struct *next, u64 now)
{
	struct cpu_key_thread_lt *lt = &per_cpu(key_thread_lt, cpu);
	s64 delta = now - lt->last_update;

	if (lt->curr_state) {
		lt->cum_key_thread_time += delta;
		lt->key_thread_last_update = now;
	} else if (next->in_iowait) {
		lt->cum_key_thread_time += min(IOWAIT_BIAS, delta);
	}

	lt->curr_state = test_key_thread(next);
	lt->last_update = now;
}

static void update_history(struct cpu_key_thread_lt *lt, long load)
{
	int i;

	for (i = KEY_THREAD_HIST_SIZE - 1; i > 0; i--)
		lt->hist[i] = lt->hist[i-1];
	lt->hist[0] = clamp(load, 0L, SCHED_CAPACITY_SCALE);
}

static void cpu_key_thread_window_rollover(int cpu, u64 now)
{
	struct cpu_key_thread_lt *lt = &per_cpu(key_thread_lt, cpu);
	s64 delta_key_thread, delta_window, load;

	delta_key_thread = lt->cum_key_thread_time - lt->last_cum;
	delta_window = now - lt->last_rollover;
	lt->last_cum = lt->cum_key_thread_time;
	lt->last_rollover = now;

	/*
	 * Load for this window = integral_key_thread_time / window_time.
	 * Unit in 1024 to represent decimal.
	 */
	load = (delta_key_thread << SCHED_CAPACITY_SHIFT) / delta_window;
	update_history(lt, load);
}

void cpu_key_thread_tick(u64 now)
{
	int cpu;

	/*
	 * Check if the largest cluster are running key threads in most of
	 * recent time to see if it worth some cpu microarchitecture speedup.
	 * If not running key threads, we'd better be conservative.
	 */
	for_each_cpu_and(cpu, &max_cap_cluster()->cpus, cpu_online_mask) {
		struct rq *rq = cpu_rq(cpu);
		struct rq_flags rf;

		/* Need rq lock to serialize with sched_switch. */
		rq_lock(rq, &rf);
		cpu_key_thread_update(cpu, rq->curr, now);
		cpu_key_thread_window_rollover(cpu, now);
		rq_unlock(rq, &rf);
	}

	update_cpu_microarch_speedup(now);
}

#ifdef CONFIG_MPAM
static void mpam_update_partid(struct task_struct *p)
{
	if (test_key_thread(p))
		p->partid = MPAM_PARTID_VIPTASK;
	else if (p->partid == MPAM_PARTID_VIPTASK)
		p->partid = MPAM_PARTID_BASE;
}
#endif

void cpu_perf_ctrl_sched_switch(int cpu, struct task_struct *prev,
				struct task_struct *next, u64 now)
{
#ifdef CONFIG_MPAM
	mpam_update_partid(next);
#endif
	cpu_key_thread_update(cpu, next, now);
}

void cpu_perf_ctrl_do_timer_cpu_tick(u64 now)
{
	cpu_key_thread_tick(now);
}
