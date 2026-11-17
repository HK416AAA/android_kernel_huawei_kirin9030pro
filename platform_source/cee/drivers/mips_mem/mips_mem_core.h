#ifndef __MIPS_MEM_CORE_H__
#define __MIPS_MEM_CORE_H__

#define KHZ_PER_MHZ 1000
#define HZ_PER_MHZ 1000000
#define MIPS_MEM_DEV_MAX	2

struct core_dev_map {
	unsigned int core_mhz;
	unsigned long *target_freq;
};

struct target_ratio {
	u32 *ratios;
	int nratios;
};

struct vote_reg {
	void __iomem *reg; /* dev frequency vote register */
	u32 mask;
	u8 bit;
};

struct dev_info {
	unsigned int nlevel;
	struct target_ratio *ratio_array;
	unsigned int *ipc_min_sample_time_ns;
	int nipc_min_sample_time;
	u64 min_sample_time;
	int cur_freq;
	unsigned int refill_event_id;
	u64 update_time;
	unsigned int window_size_ns;
	struct vote_reg *hw_vote;
	struct core_dev_map *freq_map;
	unsigned int map_len;
	bool enable;
	struct kobject kobj;
	unsigned int dev_id;
	cpumask_t share_clk_cpumask;
};

struct mipsmem_cluster_policy {
	struct dev_info *mem_dev[MIPS_MEM_DEV_MAX];
	struct kobject kobj;
	unsigned int window_size_ns;
	cpumask_t cpu_mask;
};

struct mips_counts {
	u64 inst;
	u64 cycle;
	u64 cache_refill[MIPS_MEM_DEV_MAX];
	int freq;
};

struct mipsmem_cpu_info {
	int cpu;
	bool enable;
	struct mipsmem_cluster_policy *policy;
	struct notifier_block mips_cpu_idle_nb;
	struct mips_counts counts;
	u32 next_freq[MIPS_MEM_DEV_MAX];
	u64 min_sample_time[MIPS_MEM_DEV_MAX];
	u64 window_start;
};

extern spinlock_t state_lock;
DECLARE_PER_CPU(struct mipsmem_cpu_info, cpu_info);
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
extern const u32 g_dev_link_max_freq[MIPS_MEM_DEV_MAX];
#endif

void hw_vote_write_reg(u32 value, void __iomem *reg);
void set_hw_vote(struct dev_info *info, int max_freq, u64 min_sample_time);
bool mem_cpu_enable(struct mipsmem_cpu_info *mem_cpu);
void change_mem_freq(struct mipsmem_cpu_info *mem_cpu);
void clock_set_rate_trace(const char *name, int freq, int cpu);
void check_mips_mem_freq_change_trace(int cpu, const char *name, u64 inst, u64 cycle, u64 core_freq,
		 int refill, int ratio, int freq);
#endif