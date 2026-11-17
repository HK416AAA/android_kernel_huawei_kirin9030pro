#define pr_fmt(fmt) "amuv1: " fmt
#include <asm/sysreg.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/cpu.h>
#include <linux/cpu_pm.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/arm-smccc.h>
#include <platform_include/see/bl31_smc.h>

#include "amuv1.h"

#define reg_case(n, reg) \
	case n: val = read_sysreg_s(SYS_AMEV##reg##_EL0(n)); break;

#define READ_AMU_FUNC(name, reg) \
u64 read_amu_##name(u32 idx) \
{ \
	u64 val = 0; \
	switch(idx) { \
	reg_case(0, reg) \
	reg_case(1, reg) \
	reg_case(2, reg) \
	reg_case(3, reg) \
	reg_case(4, reg) \
	reg_case(5, reg) \
	reg_case(6, reg) \
	reg_case(7, reg) \
	reg_case(8, reg) \
	reg_case(9, reg) \
	reg_case(10, reg) \
	reg_case(11, reg) \
	reg_case(12, reg) \
	reg_case(13, reg) \
	reg_case(14, reg) \
	reg_case(15, reg) \
	default: \
		printk_deferred(KERN_DEBUG "Invalid amu index\n"); \
		break; \
	} \
	return val; \
}

READ_AMU_FUNC(group0_evt_cnt, CNTR0);
READ_AMU_FUNC(group0_evt_type, TYPER0);
READ_AMU_FUNC(group1_evt_cnt, CNTR1);
READ_AMU_FUNC(group1_evt_type, TYPER1);

u32 fixed_counters[FIXED_COUNTERS] = {
	FIXED_COUNTER_CPU_CYCLES,
	FIXED_COUNTER_CNT_CYCLES,
	FIXED_COUNTER_INST_RETIRED,
	FIXED_COUNTER_STALL_BACKEND_MEM
};

static DEFINE_PER_CPU(u32 *, auxilaury_events);
static DEFINE_PER_CPU(u64 *, evt_counters);

static void enable_amu_aux_evt(int index, u32 event)
{
	struct arm_smccc_res res = {0};
	arm_smccc_1_1_smc(FID_AMU_CTRL_CFG,
			  AMU_ENABLE_CMD, index, event, &res);
	if (res.a0 != 0)
		pr_err("amu smc enable failed\n");
}

static void disable_amu_aux_evt(int index)
{
	struct arm_smccc_res res = {0};
	arm_smccc_1_1_smc(FID_AMU_CTRL_CFG,
			  AMU_DISABLE_CMD, index, &res);
	if (res.a0 != 0)
		pr_err("amu smc disable failed\n");
}

static void write_amu_counter(int group, int index, u64 val)
{
	struct arm_smccc_res res = {0};
	int cmd = group ? AMU_WRITE_AUX_CMD : AMU_WRITE_FIX_CMD;
	arm_smccc_1_1_smc(FID_AMU_CTRL_CFG,
			  cmd, index, val, &res);
	if (res.a0 != 0)
		pr_err("amu smc write failed\n");
}

static int check_fixed(u32 event, int *index)
{
	int i;
	for (i = 0; i < FIXED_COUNTERS; i++) {
		if (event == fixed_counters[i]) {
			*index = i;
			return 0;
		}
	}
	return -1;
}

static int check_aux(u32 event, int *index)
{
	int i;
	int cpu = smp_processor_id();
	u32 *aux_counters = per_cpu(auxilaury_events, cpu);

	for (i = 0; i < AUX_COUNTERS; i++) {
		if (aux_counters[i] == event) {
			*index = i;
			return 0;
		}
	}
	return -1;
}

static int find_aux(u32 event, int *index)
{
	int i;
	int cpu = smp_processor_id();
	u32 *aux_counters = per_cpu(auxilaury_events, cpu);

	*index = -1;
	for (i = 0; i < AUX_COUNTERS; i++) {
		if (aux_counters[i] == event) {
			*index = i;
			return 0;
		}
		if (aux_counters[i] == 0 && *index == -1)
			*index = i;
	}
	if (*index != -1)
		return 0;
	return -1;
}

int amu_counter_enable(u32 event)
{
	int index;
	int ret = -1;
	int cpu = smp_processor_id();
	u32 *aux_counters = per_cpu(auxilaury_events, cpu);

	if (!event)
		return ret;

	if (!check_fixed(event, &index) || !check_aux(event, &index)) {
		ret = 0;
	} else {
		if (!find_aux(event, &index)) {
			enable_amu_aux_evt(index, event);
			aux_counters[index] = event;
			ret = 0;
		} else {
			pr_err("AMU event: %x enable failed, no more valid counters\n", event);
		}
	}
	return ret;
}

int amu_counter_disable(u32 event)
{
	int index;
	int ret = -1;
	int cpu = smp_processor_id();
	u32 *aux_counters = per_cpu(auxilaury_events, cpu);

	if (!event)
		return ret;

	if (!check_fixed(event, &index)) {
		ret = 0;
	} else {
		if (!check_aux(event, &index)) {
			disable_amu_aux_evt(index);
			aux_counters[index] = 0;
			ret = 0;
		} else {
			pr_err("AMU event: %x disable failed, haven`t set\n", event);
		}
	}
	return ret;
}

u64 amu_read_counter(u32 event)
{
	int event_idx = 0;
	if (!event)
		return 0;
	if (!check_fixed(event, &event_idx)) {
		return read_amu_group0_evt_cnt(event_idx);
	} else {
		if (!check_aux(event, &event_idx)) {
			return read_amu_group1_evt_cnt(event_idx);
		} else {
			printk_deferred(KERN_DEBUG "AMU event: %x read failed, haven`t set\n", event);
		}
	}
	return 0;
}

static int __ref amu_online(unsigned int cpu)
{
	int i;
	u32 *aux_counters = per_cpu(auxilaury_events, cpu);

	for (i = 0; i < AUX_COUNTERS; i++) {
		if (aux_counters[i])
			enable_amu_aux_evt(i, aux_counters[i]);
	}
	return 0;
}

static int __ref amu_offline(unsigned int cpu)
{
	return 0;
}

static void amu_pm_save(int cpu)
{
	int i;
	u64 *counters = per_cpu(evt_counters, cpu);

	for (i = 0; i < AUX_COUNTERS + FIXED_COUNTERS; i++) {
		if (i < FIXED_COUNTERS)
			counters[i] = read_amu_group0_evt_cnt(i);
		else
			counters[i] = read_amu_group1_evt_cnt(i - FIXED_COUNTERS);
	}
}

static void amu_pm_restore(int cpu)
{
	int i;
	u32 *aux_evts = per_cpu(auxilaury_events, cpu);
	u64 *counters = per_cpu(evt_counters, cpu);

	for (i = 0; i < FIXED_COUNTERS; i++)
		write_amu_counter(0, i, counters[i]);

	for (i = 0; i < AUX_COUNTERS; i++) {
		if (aux_evts[i]) {
			write_amu_counter(1, i, counters[i + FIXED_COUNTERS]);
			enable_amu_aux_evt(i, aux_evts[i]);
		}
	}
}

static int amu_cpu_pm_notify(struct notifier_block *nb, unsigned long cmd, void *v)
{
	unsigned int cpu = smp_processor_id();

	switch (cmd) {
	case CPU_PM_ENTER:
		amu_pm_save(cpu);
		break;
	case CPU_PM_EXIT:
	case CPU_PM_ENTER_FAILED:
		amu_pm_restore(cpu);
		break;
	default:
		return NOTIFY_DONE;
	}

	return NOTIFY_OK;
}

static struct notifier_block amu_cpu_pm_nb = {
	.notifier_call = amu_cpu_pm_notify,
};

static int __init amu_init(void)
{
	int ret;
	unsigned int cpu;

	for_each_possible_cpu(cpu) {
		per_cpu(auxilaury_events, cpu) = (u32 *)kzalloc(sizeof(u32) * AUX_COUNTERS, GFP_KERNEL);
		per_cpu(evt_counters, cpu) = (u64 *)kzalloc(sizeof(u64) * \
						(AUX_COUNTERS + FIXED_COUNTERS), GFP_KERNEL);
	}

	ret = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN, "amuv1:online",
					amu_online, amu_offline);
	if (ret < 0) {
		pr_err("amu set hotplug state failed\n");
		return ret;
	}
	ret = cpu_pm_register_notifier(&amu_cpu_pm_nb);
	if (ret < 0) {
		pr_err("amu set pm state failed\n");
		return ret;
	}
	return 0;
}

static void __exit amu_exit(void)
{
	cpu_pm_unregister_notifier(&amu_cpu_pm_nb);
	cpuhp_remove_state_nocalls(CPUHP_AP_ONLINE_DYN);
}

module_init(amu_init);
module_exit(amu_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("HISI amu driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
