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
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/topology.h>
#include <linux/cpu.h>
#include <linux/of.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/of_address.h>
#include <trace/events/power.h>
#include <linux/sched/cpufreq.h>
#include <linux/cpu_pm.h>
#include <securec.h>
#include <../../../kernel/sched/sched.h>
#include "mips_mem_core.h"

#define CREATE_TRACE_POINTS
#include <trace/events/mips_mem.h>

static struct kobject *g_mips_mem_global_kobject;
DEFINE_PER_CPU(struct mipsmem_cpu_info, cpu_info);
const char *g_dev_name[MIPS_MEM_DEV_MAX] = {"l3", "ddr"};
#ifdef CONFIG_CPU_MAX_PERF_REQ_LINK_MEM_TEMPORARY
/* This is temporary solution on single platform. So use magic num. */
const u32 g_dev_link_max_freq[MIPS_MEM_DEV_MAX] = { 1556, 4253 };
#endif

#define DEFAULT_TARGET_RATIO 600
#define DEFAULT_IPC_MIN_SAMPLE_TIME 4000000
#define DEFAULT_MEM_WINDOW_SIZE	4000000
static unsigned int default_target_ratios[] = {DEFAULT_TARGET_RATIO};
static unsigned int none_target_ratios[] = {0};
static unsigned int default_ipc_min_sample_time[] = {DEFAULT_IPC_MIN_SAMPLE_TIME};

void clock_set_rate_trace(const char *name, int freq, int cpu)
{
	trace_perf(clock_set_rate, name, freq, cpu);
}
 
void check_mips_mem_freq_change_trace(int cpu, const char *name, u64 inst, u64 cycle, u64 core_freq,
		 int refill, int ratio, int freq)
{
	trace_check_mips_mem_freq_change(cpu, name, inst, cycle, core_freq, refill, ratio, freq);
}

void hw_vote_write_reg(u32 value, void __iomem *reg)
{
	writel(value, reg);
}

static int get_mask_from_dev_handle(struct platform_device *pdev,
				    cpumask_t *mask)
{
	struct device_node *np = pdev->dev.of_node;
	struct device_node *cpu_np = NULL;
	struct device_node *mon_np = NULL;
	int i, cpu;

	cpumask_clear(mask);

	for_each_possible_cpu(cpu) {
		cpu_np = of_get_cpu_node(cpu, NULL);
		if (!cpu_np) {
			pr_err("%s: failed to get cpu%d node\n",
			       __func__, cpu);
			return -ENOENT;
		}

		/* Get mipsmem monitor descriptor node */
		for (i = 0; ; i++) {
			mon_np = of_parse_phandle(cpu_np, "mips-mem-monitors", i);
			if (!mon_np)
				break;

			/* CPUs are sharing mipsmem monitor node */
			if (np == mon_np) {
				cpumask_set_cpu(cpu, mask);
				of_node_put(mon_np);
				break;
			}
			of_node_put(mon_np);
		}

		of_node_put(cpu_np);
	}

	if (cpumask_empty(mask))
		return -ENOENT;

	return 0;
}

static int cmd_parse(char *para_cmd, char **argv, int max_args)
{
	int para_id = 0;

	while (*para_cmd != '\0') {
		if (para_id >= max_args)
			break;

		while (*para_cmd == ' ')
			para_cmd++;

		if (*para_cmd == '\0')
			break;

		argv[para_id] = para_cmd;
		para_id++;

		while ((*para_cmd != ' ') && (*para_cmd != '\0'))
			para_cmd++;

		if (*para_cmd == '\0')
			break;

		*para_cmd = '\0';
		para_cmd++;
	}

	return para_id;
}

#ifdef CONFIG_SOC_DFX
static ssize_t store_freq_map(struct dev_info *info, const char *buf, size_t count)
{
	char local_buf[PAGE_SIZE] = {0};
	unsigned int num = info->nlevel + 2; /* one for idx, one for core_freq */
	char **argv = NULL;
	int argc, ret;
	u32 core_freq, idx;
	u64 *target_freq = NULL;
	unsigned int level;
	struct core_dev_map *map = info->freq_map;

	argv = (char **)kzalloc(num * sizeof(char *), GFP_KERNEL);
	if (argv == NULL)
		return -ENOMEM;
	target_freq = (u64 *)kzalloc((info->nlevel) * sizeof(u64), GFP_KERNEL);
	if (target_freq == NULL) {
		kfree(argv);
		return -ENOMEM;
	}

	ret = strncpy_s(local_buf, PAGE_SIZE, buf,
			min_t(size_t, sizeof(local_buf) - 1, count));
	if (ret != EOK)
		goto out;
	argc = cmd_parse(local_buf, argv, num);
	if (argc != num) {
		pr_err("error, only surport %u para\n", num);
		ret = -EINVAL;
		goto out;
	}

	ret = sscanf_s(argv[0], "%u", &idx);
	if (ret != 1 || idx >= info->map_len) {
		ret = -EINVAL;
		goto out;
	}
	ret = sscanf_s(argv[1], "%u", &core_freq);
	if (ret != 1) {
		ret = -EINVAL;
		goto out;
	}
	for (level = 0; level < info->nlevel; level++) {
		ret = sscanf_s(argv[2 + level], "%llu", &target_freq[level]);
		if (ret != 1) {
			ret = -EINVAL;
			goto out;
		}
	}

	map = map + idx;
	map->core_mhz = core_freq;
	for (level = 0; level < info->nlevel; level++)
		map->target_freq[level] = target_freq[level];
	ret = count;

out:
	kfree(argv);
	kfree(target_freq);
	return ret;
}

static ssize_t show_freq_map(const struct dev_info *info, char *buf)
{
	struct core_dev_map *map = info->freq_map;
	unsigned int cnt = 0;
	unsigned int i;

	cnt += scnprintf(buf, PAGE_SIZE, "Core freq (MHz)\tDevice BW\n");

	while (map->core_mhz && cnt < PAGE_SIZE) {
		cnt += scnprintf(buf + cnt, PAGE_SIZE - cnt, "%15u\t",
				 map->core_mhz);
		for (i = 0; i < info->nlevel; i++)
			cnt += scnprintf(buf + cnt, PAGE_SIZE - cnt, "%10llu\t",
					 map->target_freq[i]);
		cnt += scnprintf(buf + cnt, PAGE_SIZE - cnt, "\n",
				 map->core_mhz);
		map++;
	}
	if (cnt < PAGE_SIZE)
		cnt += scnprintf(buf + cnt, PAGE_SIZE - cnt, "\n");

	return cnt;
}
#endif

static unsigned int *get_tokenized_data(const char *buf, int *num_tokens)
{
	const char *cp;
	unsigned int i;
	unsigned int ntokens = 1;
	unsigned int *tokenized_data = NULL;
	int err = -EINVAL;

	cp = buf;
	while ((cp = strpbrk(cp + 1, " :")))
		ntokens++;

	if (!(ntokens & 0x1))
		goto err;

	tokenized_data = kmalloc(ntokens * sizeof(unsigned int), GFP_KERNEL);
	if (tokenized_data == NULL) {
		err = -ENOMEM;
		goto err;
	}

	cp = buf;
	i = 0;
	while (i < ntokens) {
		if (sscanf_s(cp, "%u", &tokenized_data[i++]) != 1)
			goto err_kfree;

		cp = strpbrk(cp, " :");
		if (cp == NULL)
			break;
		cp++;
	}

	if (i != ntokens)
		goto err_kfree;

	*num_tokens = ntokens;
	return tokenized_data;

err_kfree:
	kfree(tokenized_data);
err:
	return ERR_PTR(err);
}

static struct target_ratio *parse_ratio_array(const char *buf, int buf_size, unsigned int nlevel)
{
	char *cp = NULL;
	unsigned int level = 0;
	unsigned int i;
	int ret = 0;
	char *token = NULL;
	char *next_token = NULL;
	struct target_ratio *arr = NULL;

	arr = (struct target_ratio *)kzalloc(sizeof(struct target_ratio) * nlevel, GFP_KERNEL);
	if (arr == NULL)
		goto error;
	cp = (char *)kzalloc(buf_size, GFP_KERNEL);
	if (cp == NULL)
		goto free_arr;
	ret = strcpy_s(cp, buf_size, buf);
	if (ret != 0)
		goto free_cp;
	token = strtok_s(cp, ",", &next_token);
	while (token != NULL) {
		arr[level].nratios = 0;
		arr[level].ratios = get_tokenized_data(token, &arr[level].nratios);
		if (IS_ERR_OR_NULL(arr[level].ratios))
			goto free_ratios;
		for (i = 0; i < arr[level].nratios; i++)
			if (i & 0x1)
				arr[level].ratios[i] /= KHZ_PER_MHZ;
		level++;
		if (level >= nlevel)
			break;
		token = strtok_s(NULL, ",", &next_token);
	}
	for (;level < nlevel; level++) {
		arr[level].nratios = ARRAY_SIZE(none_target_ratios);
		arr[level].ratios = none_target_ratios;
	}
	kfree(cp);
	return arr;
free_ratios:
	for (i = 0; i < level; i++)
		kfree(arr[i].ratios);
free_cp:
	kfree(cp);
free_arr:
	kfree(arr);
error:
	return NULL;
}

static ssize_t store_target_ratio(struct dev_info *info, const char *buf, size_t count)
{
	struct target_ratio *new_ratios = NULL;
	unsigned int i;
	unsigned long flags;

	new_ratios = parse_ratio_array(buf, count + 1, info->nlevel);
	if (IS_ERR_OR_NULL(new_ratios))
		return -EINVAL;

	spin_lock_irqsave(&state_lock, flags);
	for (i = 0; i < info->nlevel; i++) {
		if (info->ratio_array[i].ratios != default_target_ratios &&
		    info->ratio_array[i].ratios != none_target_ratios)
			kfree(info->ratio_array[i].ratios);
		info->ratio_array[i].nratios = new_ratios[i].nratios;
		info->ratio_array[i].ratios = new_ratios[i].ratios;
	}
	spin_unlock_irqrestore(&state_lock, flags);
	kfree(new_ratios);

	return count;
}

static ssize_t show_target_ratio(const struct dev_info *info, char *buf)
{
	unsigned int i, j;
	unsigned long flags;
	ssize_t ret = 0;

	spin_lock_irqsave(&state_lock, flags);
	for (j = 0; j < info->nlevel; j++) {
		for (i = 0; i < (unsigned int)(info->ratio_array[j].nratios); i++)
			ret += scnprintf(buf + ret, PAGE_SIZE - ret, "%u%s",
					(i & 0x1) ? (info->ratio_array[j].ratios[i] * KHZ_PER_MHZ)
						: info->ratio_array[j].ratios[i],
					(i & 0x1) ? ":" : " ");
		ret += scnprintf(buf + ret, PAGE_SIZE - ret, ",");
	}
	spin_unlock_irqrestore(&state_lock, flags);

	scnprintf(buf + ret - 1, PAGE_SIZE - ret + 1, "\n");
	return ret;
}

static ssize_t show_mipsmem_enable(const struct dev_info *info, char *buf)
{
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", info->enable);
}

#define TRANS_BASE	10
static ssize_t store_mipsmem_enable(struct dev_info *info, const char *buf, size_t count)
{
	int  val;
	unsigned long flags;

	if (kstrtouint(buf, TRANS_BASE, &val) != 0)
		return -EINVAL;
	spin_lock_irqsave(&state_lock, flags);
	info->enable = !!val;
	if (!info->enable)
		set_hw_vote(info, 0, 0);
	spin_unlock_irqrestore(&state_lock, flags);
	return count;
}

static ssize_t show_ipc_min_sample_time(const struct dev_info *info, char *buf)
{
	unsigned long flags;
	ssize_t ret = 0;
	int i;

	spin_lock_irqsave(&state_lock, flags);
	for (i = 0; i < info->nipc_min_sample_time; i++)
		ret += scnprintf(buf + ret, PAGE_SIZE - ret, "%u%s", info->ipc_min_sample_time_ns[i],
				 i & 0x1 ? ":" : " ");
	spin_unlock_irqrestore(&state_lock, flags);

	scnprintf(buf + ret - 1, PAGE_SIZE - ret + 1, "\n");
	return ret;
}

static ssize_t store_ipc_min_sample_time(struct dev_info *info, const char *buf, size_t count)
{
	unsigned long flags;
	unsigned int *new_ipc_min_sample_time;
	int ntokens;
	int i;

	new_ipc_min_sample_time = cpufreq_get_tokenized_data(buf, &ntokens);
	if (IS_ERR(new_ipc_min_sample_time))
		return PTR_ERR(new_ipc_min_sample_time);

	for (i = 0; i < ntokens; i++) {
		if (new_ipc_min_sample_time[i] == 0) {
			kfree(new_ipc_min_sample_time);
			return -EINVAL;
		}
	}

	spin_lock_irqsave(&state_lock, flags);
	if (info->ipc_min_sample_time_ns != default_ipc_min_sample_time)
		kfree(info->ipc_min_sample_time_ns);
	info->ipc_min_sample_time_ns = new_ipc_min_sample_time;
	info->nipc_min_sample_time = ntokens;
	spin_unlock_irqrestore(&state_lock, flags);

	return count;
}

static ssize_t show_window_size_ns(const struct dev_info *info, char *buf)
{
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", info->window_size_ns);
}

#define to_cluster_data(k) container_of(k, struct dev_info, kobj)
#define to_attr(a) container_of(a, struct mipsmem_attr, attr)
struct mipsmem_attr {
	struct attribute attr;
	ssize_t (*show)(const struct dev_info *, char *);
	ssize_t (*store)(struct dev_info *, const char *, size_t count);
};

#define mipsmem_attr_ro(_name)		\
	static struct mipsmem_attr _name = 	\
	__ATTR(_name, 0440, show_##_name, NULL)

#define mipsmem_attr_rw(_name)		\
	static struct mipsmem_attr _name = 		\
	__ATTR(_name, 0640, show_##_name, store_##_name)

#ifdef CONFIG_SOC_DFX
mipsmem_attr_rw(freq_map);
#endif
mipsmem_attr_rw(ipc_min_sample_time);
mipsmem_attr_rw(mipsmem_enable);
mipsmem_attr_rw(target_ratio);
mipsmem_attr_ro(window_size_ns);

static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
	struct dev_info *data = to_cluster_data(kobj);
	struct mipsmem_attr *mattr = to_attr(attr);
	ssize_t ret = -EIO;

	if (mattr->show != NULL)
		ret = mattr->show(data, buf);

	return ret;
}

static ssize_t store(struct kobject *kobj, struct attribute *attr,
		     const char *buf, size_t count)
{
	struct dev_info *data = to_cluster_data(kobj);
	struct mipsmem_attr *mattr = to_attr(attr);
	ssize_t ret = -EIO;

	if (mattr->store != NULL)
		ret = mattr->store(data, buf, count);

	return ret;
}

static struct attribute *mips_attrs[] = {
#ifdef CONFIG_SOC_DFX
	&freq_map.attr,
#endif
	&target_ratio.attr,
	&mipsmem_enable.attr,
	&ipc_min_sample_time.attr,
	&window_size_ns.attr,
	NULL,
};

static const struct sysfs_ops sysfs_ops = {
	.show   = show,
	.store  = store,
};

static struct kobj_type ktype_mips = {
	.sysfs_ops	= &sysfs_ops,
	.default_attrs  = mips_attrs,
};

static struct attribute *default_attrs[] = {
	NULL,
};

static struct kobj_type ktype_default = {
	.default_attrs  = default_attrs,
};

static void clear_mem_freq(struct mipsmem_cpu_info *mem_cpu)
{
	unsigned int i;

	for (i = 0; i < MIPS_MEM_DEV_MAX; i++) {
		mem_cpu->next_freq[i] = 0;
		mem_cpu->min_sample_time[i] = 0;
	}
}

static void mips_mem_idle_clear_freq(struct mipsmem_cpu_info *mem_cpu)
{
	unsigned long flags;

	spin_lock_irqsave(&state_lock, flags);
	if (!mem_cpu_enable(mem_cpu))
		goto unlock;

	clear_mem_freq(mem_cpu);
	change_mem_freq(mem_cpu);
unlock:
	spin_unlock_irqrestore(&state_lock, flags);
}

static void set_mips_info_state(struct dev_info *info, bool enabled)
{
	if (info) {
		info->enable = enabled;
		if (!enabled)
			set_hw_vote(info, 0, 0);
	}
}

void set_mips_mem_state(bool enabled)
{
	int cpu;
	unsigned long flags;
	struct dev_info *dev = NULL;
	unsigned int i;

	for_each_possible_cpu(cpu) {
		struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);

		if (!mem_cpu->policy)
			continue;

		if (cpu == cpumask_first(&mem_cpu->policy->cpu_mask)) {
			spin_lock_irqsave(&state_lock, flags);
			for (i = 0; i < MIPS_MEM_DEV_MAX; i++) {
				dev = mem_cpu->policy->mem_dev[i];
				set_mips_info_state(dev, enabled);
			}
			spin_unlock_irqrestore(&state_lock, flags);
		}
	}
}

static int mips_mem_idle_notif(struct notifier_block *nb, unsigned long action,
			       void *data __maybe_unused)
{
	int cpu = smp_processor_id();
	struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);

	switch (action) {
	case CPU_PM_ENTER:
		mips_mem_idle_clear_freq(mem_cpu);
		break;

	case CPU_PM_ENTER_FAILED:
		break;
	case CPU_PM_EXIT:
		break;
	default:
		break;
	}
	return NOTIFY_OK;
}

static void mem_cpu_policy_release(cpumask_t *cpus, struct device *dev)
{
	int cpu;
	unsigned int i;
	struct mipsmem_cpu_info *mem_cpu = NULL;
	struct mipsmem_cluster_policy *policy = NULL;
	struct device *cpu_dev = NULL;

	mem_cpu = &per_cpu(cpu_info, cpumask_first(cpus));
	if (mem_cpu->policy == NULL)
		return;

	/* if policy has any mem_dev, no need to free */
	for (i = 0; i < MIPS_MEM_DEV_MAX; i++) {
		if (mem_cpu->policy->mem_dev[i] != NULL)
			return;
	}

	policy = mem_cpu->policy;
	for_each_cpu(cpu, cpus) {
		cpu_dev = get_cpu_device(cpu);
		mem_cpu = &per_cpu(cpu_info, cpu);
		mem_cpu->policy = NULL;
		sysfs_delete_link(&cpu_dev->kobj, &policy->kobj, "mips_mem");
		pr_err("release cpu%d memcpu policy\n", cpu);
	}

	kobject_put(&policy->kobj);
	devm_kfree(dev, policy);
}

static struct mipsmem_cluster_policy *mipsmem_cluster_alloc_and_init(struct platform_device *pdev,
								     cpumask_t *cpus)
{
	int ret = 0;
	int cpu;
	struct device *dev = &pdev->dev;
	struct device *cpu_dev = NULL;
	struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpumask_first(cpus));
	struct mipsmem_cluster_policy *policy = NULL;

	policy = mem_cpu->policy;
	if (policy)
		return policy;
	policy = devm_kzalloc(dev, sizeof(*policy), GFP_KERNEL);
	if (IS_ERR_OR_NULL(policy)) {
		dev_err(dev, "mips mem alloc cluster err\n");
		return NULL;
	}

	ret = kobject_init_and_add(&policy->kobj, &ktype_default,
				   g_mips_mem_global_kobject, "cluster%u",
				   topology_physical_package_id(cpumask_first(cpus)));
	if (ret) {
		dev_err(dev, "mips: failed to init cluster->kobj: %d\n", ret);
		kobject_put(&policy->kobj);
		goto error;
	}
	cpumask_copy(&policy->cpu_mask, cpus);
	policy->window_size_ns = DEFAULT_MEM_WINDOW_SIZE;
	for_each_cpu(cpu, cpus) {
		mem_cpu = &per_cpu(cpu_info, cpu);
		mem_cpu->policy = policy;
		mem_cpu->cpu = cpu;
		mem_cpu->enable = true;
		mem_cpu->mips_cpu_idle_nb.notifier_call = mips_mem_idle_notif;
		cpu_pm_register_notifier(&mem_cpu->mips_cpu_idle_nb);

		cpu_dev = get_cpu_device(cpu);
		ret = sysfs_create_link(&cpu_dev->kobj, &policy->kobj, "mips_mem");
		if (ret) {
			dev_err(dev, "mips: symlink creation cpu%d failed%d\n", cpu, ret);
			/* policy and its kobj will free here */
			mem_cpu_policy_release(cpus, dev);
			return NULL;
		}
	}
	return policy;
error:
	devm_kfree(dev, policy);
	return NULL;
}

#define DEFAULT_LEVEL	1
static struct target_ratio *init_ratio_array(struct device *dev, unsigned int nlevel)
{
	struct target_ratio *arr = NULL;
	unsigned int i;

	arr = devm_kzalloc(dev, sizeof(struct target_ratio) * nlevel,
			   GFP_KERNEL);
	if (arr == NULL)
		return NULL;
	for (i = 0; i < nlevel; i++) {
		arr[i].nratios = ARRAY_SIZE(default_target_ratios);
		arr[i].ratios = default_target_ratios;
	}
	return arr;
}

static struct core_dev_map *init_core_dev_map(struct device *dev,
					      const char *prop_name, int *map_len,
					      unsigned int col)
{
	int len, nf, i, j;
	u32 data;
	struct core_dev_map *tbl = NULL;
	int ret;

	if (of_find_property(dev->of_node, prop_name, &len) == NULL)
		return NULL;

	len /= sizeof(data);

	if ((len % col) != 0 || len == 0 || col <= 1)
		return NULL;

	nf = len / col;

	tbl = devm_kzalloc(dev, (nf + 1) * sizeof(struct core_dev_map),
			   GFP_KERNEL);
	if (tbl == NULL)
		return NULL;

	for (i = 0; i < nf; i ++) {
		ret = of_property_read_u32_index(dev->of_node, prop_name, i * col,
						 &data);
		if (ret != 0)
			return NULL;
		tbl[i].core_mhz = data / KHZ_PER_MHZ;
		tbl[i].target_freq = devm_kzalloc(dev, sizeof(unsigned long) * (col - 1),
						  GFP_KERNEL);
		if (tbl[i].target_freq == NULL)
			return NULL;

		for (j = 0; j < col - 1; j++) {
			ret = of_property_read_u32_index(dev->of_node, prop_name, i * col + j + 1,
							 &data);
			if (ret != 0)
				return NULL;
			tbl[i].target_freq[j] = (u64)data * HZ_PER_MHZ;
		}
	}
	tbl[i].core_mhz = 0;
	*map_len = nf;

	return tbl;
}

#define VOTE_REG_NUM	2
#define MBITS_LEFT_SHIFT	16
static struct vote_reg *init_hw_vote(struct device *dev)
{
	void __iomem *reg_base = NULL;
	struct vote_reg *hw_vote = NULL;
	u32 temp[VOTE_REG_NUM] = {0};
	u32 reg_mask = 0;
	u32 reg_bit;

	reg_base = of_iomap(dev->of_node, 0);
	if (reg_base == NULL) {
		dev_err(dev, "fail to map io!\n");
		return NULL;
	}
	hw_vote = devm_kzalloc(dev, sizeof(*hw_vote), GFP_KERNEL);
	if (hw_vote == NULL) {
		dev_err(dev, "[%s] node %s doesn't have hw_vote alloc fail!\n",
			__func__, dev->of_node->name);
		goto numap_base;
	}
	if (of_property_read_u32_array(dev->of_node, "vote-reg",
				       &temp[0], VOTE_REG_NUM) != 0) {
		dev_err(dev, "[%s] node %s doesn't have vote-reg property!\n",
			__func__, dev->of_node->name);
		goto free_hw;
	}
	hw_vote->reg = reg_base + temp[0];

	if (of_property_read_u32(dev->of_node, "vote-reg-mask",
				 &reg_mask) != 0) {
		dev_err(dev, "[%s] node %s doesn't have vote-reg mask property!\n",
			__func__, dev->of_node->name);
		goto free_hw;
	}
	hw_vote->mask = reg_mask;

	if (of_property_read_u32(dev->of_node, "vote-reg-bit", &reg_bit) != 0) {
		dev_err(dev, "[%s] node %s doesn't have vote-reg bit property!\n",
			__func__, dev->of_node->name);
		goto free_hw;
	}
	hw_vote->bit = reg_bit;
	return hw_vote;
free_hw:
	devm_kfree(dev, hw_vote);
numap_base:
	iounmap(reg_base);
	return NULL;
}

static void init_table_level(struct device *dev, unsigned int *level)
{
	int ret;

	ret = of_property_read_u32(dev->of_node, "nr-level", level);
	if (ret != 0)
		*level = DEFAULT_LEVEL;
	dev_info(dev, "mips_mem:%s table_level = %d\n", dev->of_node->name, *level);
}

static int init_refill_event_id(struct device *dev, unsigned int *event_id)
{
	int ret;

	ret = of_property_read_u32(dev->of_node, "refill-event-id", event_id);
	if (ret != 0)
		dev_err(dev, "mips_mem: %s doesn't have refill-event-id property!\n",
			dev->of_node->name);
	dev_info(dev, "mips_mem:%s eventid = %d\n", dev->of_node->name, *event_id);
	return ret;
}

static void init_share_clock_cpu(struct device *dev, cpumask_t *mask)
{
	struct device_node *dev_np = dev->of_node;
	struct device_node *cpu_np = NULL;
	struct device_node *share_clk_np = NULL;
	int i, cpu;

	cpumask_clear(mask);
	for_each_possible_cpu(cpu) {
		cpu_np = of_get_cpu_node(cpu, NULL);
		if (!cpu_np) {
			pr_err("%s: failed to get cpu%d node\n",
			       __func__, cpu);
			continue;
		}
		for (i = 0; ; i++) {
			share_clk_np = of_parse_phandle(dev_np, "share-clock-cpu", i);
			if (!share_clk_np)
				break;
			if (share_clk_np == cpu_np) {
				pr_err("mips_mem share clk cpu %d\n", cpu);
				cpumask_set_cpu(cpu, mask);
			}
			of_node_put(share_clk_np);
		}
		of_node_put(cpu_np);
	}
}

static void init_vote_max_freq(struct dev_info *dev)
{
	unsigned long init_freq = dev->freq_map[dev->map_len - 1].target_freq[0] / HZ_PER_MHZ;

	set_hw_vote(dev, (int)init_freq, 0);
}

static int mipsmem_dev_alloc_and_init(struct platform_device *pdev,
				      struct mipsmem_cluster_policy *policy)
{
	struct dev_info *dev_info = NULL;
	struct device *dev = &pdev->dev;
	unsigned int dev_id;
	int ret = 0;

	for (dev_id = 0; dev_id < MIPS_MEM_DEV_MAX; dev_id++) {
		if (strstr(pdev->name, g_dev_name[dev_id]))
			break;
	}
	if (dev_id == MIPS_MEM_DEV_MAX) {
		dev_err(dev, "mips: no such dev %s\n", pdev->name);
		return -EINVAL;
	}

	dev_info = devm_kzalloc(dev, sizeof(*dev_info), GFP_KERNEL);
	if (!dev_info) {
		dev_err(dev, "[%s] node %s doesn't have dev_info alloc fail!\n",
			__func__, dev->of_node->name);
		return -ENOMEM;
	}

	ret = kobject_init_and_add(&dev_info->kobj, &ktype_mips,
				   &policy->kobj, "mips_%s", g_dev_name[dev_id]);
	if (ret) {
		dev_err(dev, "mips: failed to init dev_info->kobj: %d\n", ret);
		goto error;
	}

	dev_info->dev_id = dev_id;
	init_table_level(dev, &dev_info->nlevel);
	dev_info->ratio_array = init_ratio_array(dev, dev_info->nlevel);
	if (dev_info->ratio_array == NULL) {
		dev_err(dev, "fail to init ratio map\n");
		ret = -ENOMEM;
		goto error;
	}
	dev_info->freq_map = init_core_dev_map(dev, "core-dev-table",
					       &dev_info->map_len, dev_info->nlevel + 1);
	if (dev_info->freq_map == NULL) {
		dev_err(dev, "Couldn't find the freq map table!\n");
		ret = -EINVAL;
		goto error;
	}
	ret = init_refill_event_id(dev, &dev_info->refill_event_id);
	if (ret)
		goto error;

	init_share_clock_cpu(dev, &dev_info->share_clk_cpumask);
	dev_info->hw_vote = init_hw_vote(dev);
	if (dev_info->hw_vote == NULL) {
		dev_err(dev, "Couldn't find the hw_vote!\n");
		ret = -EINVAL;
		goto error;
	}

	dev_info->ipc_min_sample_time_ns = default_ipc_min_sample_time;
	dev_info->nipc_min_sample_time = ARRAY_SIZE(default_ipc_min_sample_time);
	dev_info->window_size_ns = policy->window_size_ns;
	init_vote_max_freq(dev_info);

	policy->mem_dev[dev_id] = dev_info;
	return 0;
error:
	kobject_put(&dev_info->kobj);
	devm_kfree(dev, dev_info);
	policy->mem_dev[dev_id] = NULL;
	return ret;
}

static int mips_driver_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	cpumask_t cpus;
	int ret;
	struct mipsmem_cluster_policy *policy = NULL;

	if (get_mask_from_dev_handle(pdev, &cpus) != 0) {
		dev_err(dev, "No CPU use this mon\n");
		return -ENODEV;
	}

	policy = mipsmem_cluster_alloc_and_init(pdev, &cpus);
	if (!policy) {
		dev_err(dev, "init cluster fail\n");
		return -ENOMEM;
	}

	ret = mipsmem_dev_alloc_and_init(pdev, policy);
	if (ret) {
		dev_err(dev, "init dev fail\n");
		mem_cpu_policy_release(&cpus, dev);
	}
	return ret;
}

static int __ref mips_mem_online(unsigned int cpu)
{
	unsigned long flags;
	struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);

	spin_lock_irqsave(&state_lock, flags);
	mem_cpu->enable = true;
	spin_unlock_irqrestore(&state_lock, flags);
	return 0;
}

static int __ref mips_mem_offline(unsigned int cpu)
{
	unsigned long flags;
	struct mipsmem_cpu_info *mem_cpu = &per_cpu(cpu_info, cpu);

	spin_lock_irqsave(&state_lock, flags);
	if (!mem_cpu_enable(mem_cpu))
		goto unlock;
	clear_mem_freq(mem_cpu);
	change_mem_freq(mem_cpu);
unlock:
	mem_cpu->enable = false;
	spin_unlock_irqrestore(&state_lock, flags);
	return 0;
}

static const struct of_device_id match_table[] = {
	{ .compatible = "mips-mem" },
	{}
};

static struct platform_driver mips_mem_mon_driver = {
	.probe = mips_driver_probe,
	.driver = {
		.name = "mips-mem",
		.of_match_table = match_table,
		.owner = THIS_MODULE,
	},
};

static int __init mips_mem_init(void)
{
	int ret;

	g_mips_mem_global_kobject = kobject_create_and_add("mips_mem", &cpu_subsys.dev_root->kobj);
	if (!g_mips_mem_global_kobject)
		return -ENOMEM;
	ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN, "mips-mem:online",
					mips_mem_online, mips_mem_offline);
	if (ret < 0) {
		pr_err("mips mem set hotplug state failed\n");
		return ret;
	}
	return platform_driver_register(&mips_mem_mon_driver);
}
module_init(mips_mem_init);
