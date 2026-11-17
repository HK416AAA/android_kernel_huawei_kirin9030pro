/*
 * SPDX-License-Identifier: GPL-2.0
 *
 * mips.c
 *
 * for hisilicon efficinecy control algorithm mips load tracking.
 *
 * Copyright (c) 2023-2024 Huawei Technologies Co., Ltd.
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
#include <platform_include/cee/linux/mips_mem.h>
#include <platform_include/cee/linux/mips.h>
#include <asm/phase_perf.h>
#include <linux/topology.h>
#include <linux/cpu.h>
#include <linux/of.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/sched/cpufreq.h>
#include <linux/cpufreq.h>
#include <linux/cpu_pm.h>
#include <../../../kernel/sched/sched.h>
#include <securec.h>
#include "mips_mem_core.h"

const char *g_dev_trace[MIPS_MEM_DEV_MAX] = { "mipsl3cfreq", "mipsddrfreq" };
DEFINE_SPINLOCK(state_lock);

static u32 core_to_dev_freq(struct dev_info *info, u16 coref, u32 level)
{
	struct core_dev_map *map = info->freq_map;
	unsigned long freq = 0;

	if (unlikely(map == NULL))
		goto out;

	while (map->core_mhz && map->core_mhz < coref)
		map++;

	if (map->core_mhz == 0)
		map--;

	freq = map->target_freq[level] / HZ_PER_MHZ;

out:
	return freq;
}

static DEFINE_PER_CPU(unsigned long, share_clk_freq_scale) = 0;
static void mips_mem_set_freq_sacle(struct dev_info *dev, unsigned int freq)
{
	unsigned long scale;
	int i;
	struct cpufreq_policy *policy = NULL;

	if (!dev)
		return;
	for_each_cpu(i, &dev->share_clk_cpumask) {
		policy = cpufreq_cpu_get_raw(i);
		if (!policy)
			continue;
		scale = ((freq * KHZ_PER_MHZ) << SCHED_CAPACITY_SHIFT) / policy->cpuinfo.max_freq;
		per_cpu(share_clk_freq_scale, i) = scale;
	}
}

unsigned long mips_mem_get_freq_scale(int cpu)
{
	return per_cpu(share_clk_freq_scale, cpu);
}

static bool mem_dev_enable(struct dev_info *info)
{
	return info == NULL ? false : info->enable;
}

bool mem_cpu_enable(struct mipsmem_cpu_info *mem_cpu)
{
	if (!mips_enable)
		return false;
	if (!mem_cpu->policy)
		return false;
	return mem_cpu->enable;
}

#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
static bool g_mips_mem_shoot_max;
#endif

static void print_mem_freq(struct dev_info *info)
{
	int cpu;
	unsigned int max_freq = 0;
	int cpu_id = 0;
	unsigned int dev_id = info->dev_id;
	struct mipsmem_cpu_info *mem_cpu = NULL;
	struct dev_info *dev_cpu = NULL;

	for_each_online_cpu(cpu) {
		mem_cpu = &per_cpu(cpu_info, cpu);
		if (!mem_cpu->policy)
			continue;
		dev_cpu = mem_cpu->policy->mem_dev[dev_id];
		if (!dev_cpu || !dev_cpu->enable)
			continue;
		if (mem_cpu->next_freq[dev_id] >= max_freq) {
			max_freq = mem_cpu->next_freq[dev_id];
			cpu_id = cpu;
		}
	}
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
	if (g_mips_mem_shoot_max)
		max_freq = max(max_freq, g_dev_link_max_freq[dev_id]);
#endif
	clock_set_rate_trace(g_dev_trace[dev_id], max_freq, cpu_id);
}

void set_hw_vote(struct dev_info *info, int max_freq, u64 min_sample_time)
{
	u32 value;
	u64 now;

	now = sched_ktime_clock();
	if (max_freq != info->cur_freq && now - info->update_time > min_sample_time) {
		info->cur_freq = max_freq;
		value = (max_freq << info->hw_vote->bit) | info->hw_vote->mask;
		info->update_time = now;
		hw_vote_write_reg(value, info->hw_vote->reg);
		mips_mem_set_freq_sacle(info, max_freq);
		print_mem_freq(info);
	}
}

void change_mem_freq(struct mipsmem_cpu_info *mem_cpu)
{
	unsigned int max_freq;
	int cpu;
	unsigned int i;
	struct dev_info *dev = NULL;

	if (!mem_cpu->policy)
		return;

	for (i = 0; i < MIPS_MEM_DEV_MAX; i++) {
		dev = mem_cpu->policy->mem_dev[i];
		if (!mem_dev_enable(dev))
			continue;
		max_freq = 0;
		for_each_cpu(cpu, &mem_cpu->policy->cpu_mask)
			max_freq = max(max_freq, (&per_cpu(cpu_info, cpu))->next_freq[i]);
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
		if (g_mips_mem_shoot_max)
			max_freq = max(max_freq, g_dev_link_max_freq[i]);
#endif
		set_hw_vote(dev, max_freq, mem_cpu->min_sample_time[i]);
	}
}

#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
static void change_mem_freq_all(void)
{
	unsigned long flags;
	int cpu;

	spin_lock_irqsave(&state_lock, flags);

	if (!mips_enable)
		goto unlock;

	for_each_possible_cpu(cpu) {
		struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);

		if (mem_cpu->policy &&
		    cpu == cpumask_first(&mem_cpu->policy->cpu_mask))
			change_mem_freq(mem_cpu);
	}

unlock:
	spin_unlock_irqrestore(&state_lock, flags);
}

void set_mips_mem_shoot_max(bool shoot_max)
{
	bool old = g_mips_mem_shoot_max;

	g_mips_mem_shoot_max = shoot_max;

	/*
	 * Trigger freq change immediately, otherwise we may not have the
	 * opportunity of mip-mem update (when cpub isolated and cpuidle
	 * disabled).
	 */
	if (old != g_mips_mem_shoot_max)
		change_mem_freq_all();
}
#endif

static u32 freq_to_targetratio(u32 freq, u32 *ratios, int len)
{
	int i;

	for (i = 0; i < len - 1 && freq >= ratios[i + 1]; i += 2)
		;
	return ratios[i];
}

static u32 get_max_possible_freq(struct dev_info *dev, u32 ratio, u32 freq, u32 level)
{
	int i;
	u32 next_freq;
	u32 max_possible_freq = 0;
	int index = -1;
	struct core_dev_map *map = dev->freq_map;

	for (i = dev->ratio_array[level].nratios - 1; i >= 0; i -= 2) {
		if (ratio <= dev->ratio_array[level].ratios[i]) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		index++;
		if (index >= dev->ratio_array[level].nratios)
			return 0;
		next_freq = dev->ratio_array[level].ratios[index];
		if (next_freq <= freq) {
			while (map->core_mhz && map->core_mhz < next_freq) {
				max_possible_freq = map->core_mhz;
				map++;
			}
			return max_possible_freq;
		}
	}
	return 0;
}

static u64 ipc_to_min_sample_time(struct dev_info *dev, unsigned int ipc)
{
	unsigned int ret;
	int i;

	for (i = 0; i < dev->nipc_min_sample_time - 1 &&
	     ipc >= dev->ipc_min_sample_time_ns[i + 1]; i += 2)
		;

	ret = dev->ipc_min_sample_time_ns[i];

	return ret;
}

static u32 mips_mem_get_freq(struct dev_info *info, u32 ratio, u32 core_freq)
{
	u32 target_ratio_ceil;
	u32 mem_freq = 0;
	u32 freq;
	u32 level;

	if (info == NULL || !info->enable)
		return 0;

	for (level = 0; level < info->nlevel; level++) {
		target_ratio_ceil = freq_to_targetratio(core_freq, info->ratio_array[level].ratios,
							info->ratio_array[level].nratios);
		if (ratio <= target_ratio_ceil) {
			freq = core_freq;
		} else {
			freq = get_max_possible_freq(info, ratio, core_freq, level);
		}
		mem_freq = max(mem_freq, core_to_dev_freq(info, freq, level));
	}
	return mem_freq;
}

void check_mem_freq_change(int cpu)
{
	struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);
	struct dev_info *dev = NULL;
	struct phase_event_pcount pcount;
	unsigned int ratio, ipc;
	int i, nr_window, nr_mem_load_window;
	unsigned long flags;
	u64 refill, mem_window_size;
	u64 now = sched_ktime_clock();

	spin_lock_irqsave(&state_lock, flags);

	if (!mem_cpu_enable(mem_cpu))
		goto unlock;

	mem_window_size = mem_cpu->policy->window_size_ns;
	nr_window = update_mips_window_start(&mem_cpu->window_start,
						 mem_window_size, now, false);
	if (!nr_window)
		goto unlock;

	nr_mem_load_window = mem_window_size / mips_window_size;
	get_mips_mem_info(cpu, &pcount, nr_mem_load_window);
	mem_cpu->counts.inst = phase_data_of_pevent(&pcount, INST_RETIRED);
	mem_cpu->counts.cycle = phase_data_of_pevent(&pcount, CYCLES);
	mem_cpu->counts.freq = mem_cpu->counts.cycle / (nr_mem_load_window * mips_window_size / NSEC_PER_MSEC) / KHZ_PER_MHZ;
	ipc = div_u64_protected(mem_cpu->counts.inst * 100, mem_cpu->counts.cycle);

	for (i = 0; i < MIPS_MEM_DEV_MAX; i++) {
		dev = mem_cpu->policy->mem_dev[i];
		if (!mem_dev_enable(dev))
			continue;

		refill = phase_data_of_pevent(&pcount, dev->refill_event_id);
		ratio = (refill != 0) ? mem_cpu->counts.inst / refill : UINT_MAX;
		mem_cpu->next_freq[i] = mips_mem_get_freq(dev, ratio, mem_cpu->counts.freq);
		mem_cpu->min_sample_time[i] = ipc_to_min_sample_time(dev, ipc);
		check_mips_mem_freq_change_trace(cpu, g_dev_trace[i], mem_cpu->counts.inst, mem_cpu->counts.cycle,
						                 mem_cpu->counts.freq, refill, ratio, mem_cpu->next_freq[i]);
	}
	change_mem_freq(mem_cpu);

unlock:
	spin_unlock_irqrestore(&state_lock, flags);
}