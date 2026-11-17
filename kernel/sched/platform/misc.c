// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Miscellaneous little independent features, which don't worth a single file.
 */
#include "sched.h"
#include <linux/cpu_pm.h>
#include <linux/notifier.h>
#include <linux/smp.h>
#include <linux/delay.h>

#ifdef CONFIG_GICD_MISS_PPI_WAKE_REQ_WORKAROUND
struct cpumask __cpu_powerdown_mask;
#define cpu_powerdown_mask (&__cpu_powerdown_mask)

static DEFINE_SPINLOCK(cpu_pm_lock);
static DEFINE_PER_CPU(ktime_t, last_ipi_pending);
static DEFINE_PER_CPU(ktime_t, last_ipi_sent);

static int cpu_pm_notifier(struct notifier_block *nb, unsigned long action,
			void *data)
{
	int cpu = smp_processor_id();
	unsigned long flags;

	switch (action) {
	case CPU_PM_ENTER:
		spin_lock_irqsave(&cpu_pm_lock, flags);
		cpumask_set_cpu(cpu, cpu_powerdown_mask);
		per_cpu(last_ipi_pending, cpu) = 0;
		per_cpu(last_ipi_sent, cpu) = 0;
		spin_unlock_irqrestore(&cpu_pm_lock, flags);
		break;
	case CPU_PM_ENTER_FAILED:
	case CPU_PM_EXIT:
		spin_lock_irqsave(&cpu_pm_lock, flags);
		cpumask_clear_cpu(cpu, cpu_powerdown_mask);
		per_cpu(last_ipi_pending, cpu) = 0;
		per_cpu(last_ipi_sent, cpu) = 0;
		spin_unlock_irqrestore(&cpu_pm_lock, flags);
		break;
	default:
		break;
	}

	return NOTIFY_OK;
}

static struct notifier_block cpu_pm_notifier_block = {
	.notifier_call = cpu_pm_notifier,
};

static int __init cpu_pm_notifier_init(void)
{
	if (cpu_pm_register_notifier(&cpu_pm_notifier_block))
		pr_err("%s/%s: error\n", __FILE__, __func__);
	return 0;
}
late_initcall(cpu_pm_notifier_init);

static bool ipi_resched_pending(int cpu)
{
	return test_tsk_need_resched(cpu_rq(cpu)->curr);
}

#define RESEND_IPI_INTERVAL ns_to_ktime(1 * NSEC_PER_SEC) /* 1s */
static void send_ipi_wakeup(int cpu, ktime_t now)
{
	ktime_t last_sent = per_cpu(last_ipi_sent, cpu); /* since pm enter */

	if (last_sent == 0 || now > last_sent + RESEND_IPI_INTERVAL) {
		if (last_sent != 0) {
			pr_err("cpu %d unable to power up\n", cpu);
			/* Or unlikely miss IPI twice at the same time. */
		}

		smp_send_reschedule(cpu);
		per_cpu(last_ipi_sent, cpu) = now;
	}
}

/*
 * For user performance experience, we'd like to resend ipi wakeup as soon
 * as possible when the prev wakeup seems missed. So we chose 3.5ms.
 * However on FPGA or similar devices the usual latency can be large (at
 * max 8ms observed). Since it's hard to distinguish, we need to make it
 * work best on ASIC and bring little harm or confusion on FPGA. So we don't
 * print anything when suspect ipi miss by larger than 3.5ms latency and
 * just send an extra IPI, which must be acceptable.
 */
#define CPU_PM_EXIT_UNUSUAL_LATENCY \
	ns_to_ktime(3500 * NSEC_PER_USEC) /* 3.5ms */
static void suspect_ipi_miss(int cpu)
{
	ktime_t now = ktime_get();
	ktime_t last = per_cpu(last_ipi_pending, cpu); /* since pm enter */

	if (last > 0 && now > last + CPU_PM_EXIT_UNUSUAL_LATENCY)
		send_ipi_wakeup(cpu, now);

	per_cpu(last_ipi_pending, cpu) = now;
}

/*
 * Arm errata 1717652: Wake_request may not be delivered if multiple
 * cores are woken by PPIs at the same time. (Note: 1. SGIs are also
 * affected, though arm's description is confusing. 2. Cores in WFI
 * are not affected.)
 * Since IPI_FUNCTION_CALL and IPI_RESCHEDULE only send ipi for the
 * first time and omit future ipis until cpu response and clear some
 * software flags. We must detect ipi pending for unusual time on
 * powered down cpu and send a new ipi to wakeup it as a workaround.
 */
void check_gic_missed_wakeup(void)
{
	int cpu;
	unsigned long flags;

	spin_lock_irqsave(&cpu_pm_lock, flags);
	for_each_cpu_and(cpu, cpu_powerdown_mask, cpu_online_mask) {
		if (ipi_resched_pending(cpu) ||
		    ipi_function_call_pending(cpu))
			suspect_ipi_miss(cpu);
	}
	spin_unlock_irqrestore(&cpu_pm_lock, flags);
}
#endif /* CONFIG_GICD_MISS_PPI_WAKE_REQ_WORKAROUND */

#ifdef CONFIG_SCHED_DFX
/*
 * Default a conservative threshold.
 * Unit: jiffies. To be replaced by hres_jiffies in the future.
 */
unsigned int __read_mostly sched_dfx_report_preempt_off =
			DIV_ROUND_UP(10 * NSEC_PER_MSEC, TICK_NSEC);

/*
 * Default print warning to kmsg at most once a minute.
 * It can be manually set to 0 if needed.
 */
unsigned int sched_dfx_report_period = 60 * HZ; /* 1min */

static bool sched_dfx_report_rate_limited(void)
{
	static unsigned long last = INITIAL_JIFFIES;
	long delta = jiffies - last;

	if (delta < sched_dfx_report_period)
		return true; /* rate limited */

	last = jiffies;
	return false; /* go ahead */
}

void sched_dfx_report_long_preempt_off(long delta)
{
#ifdef CONFIG_RT_LONG_PREEMPT_OPTIMIZATION
	if (test_thread_flag(TIF_LONG_NONPREEMPTIBLE))
		return;
#endif

	if (sched_dfx_report_rate_limited())
		return;

	pr_warn("Warning: detect long preempt off for %ld jiffies\n", delta);
	dump_stack();
}

#ifdef CONFIG_DFX_DEBUG_FS
void test_long_preempt_off(void)
{
	preempt_disable();
	mdelay(20);
	preempt_enable();
}
#endif
#endif

#ifdef CONFIG_SCHED_SETSCHEDULER_EXTEND_CUSTOM_EVENT
/*
 * ATTENTION: these are userspace interfaces, WITHOUT permission requirement.
 * For the cases we want thirdparty app to make direct syscall.
 * The implementations must be resistant to attacks or wrong use.
 */
#define EXT_EVENT_MIN			0x1000
#define EXT_EVENT_DO_FRAME_BEGIN	0x1001
#define EXT_EVENT_DO_FRAME_END		0x1000
#define EXT_EVENT_GC_WAIT_BEGIN		0x1003
#define EXT_EVENT_GC_WAIT_END		0x1004
#define EXT_EVENT_MAX			0x1004 /* Don't forget to update it. */

#define IS_EXT_EVENT(event) (EXT_EVENT_MIN <= event && event <= EXT_EVENT_MAX)

/*
 * For userspace compatibility.
 * 1. On unsupported platforms we don't need to do invalid syscall every time.
 * 2. For art we need to know the seccomp filter is skipped.
 */
unsigned int sysctl_sched_setscheduler_ext_supported = 1;

/*
 * For art code in webview sandbox with seccomp filter limit, similar to
 * hw_futex_pi. Otherwise we risk our calling in art aborting the process.
 */
bool sched_setscheduler_ext_skip_seccomp_filter(int this_syscall)
{
	int nr_sched_setscheduler = is_compat_task() ? 156 : 119;
	int policy;

	if (unlikely(READ_ONCE(current->seccomp.filter) == NULL))
		return false;

	if (this_syscall != nr_sched_setscheduler)
		return false;

	policy = task_pt_regs(current)->regs[1];
	return IS_EXT_EVENT(policy);
}

/* Return handled or not. If handled, caller will return with ret. */
bool sched_setscheduler_handle_extended_user_event(int event, int *ret)
{
	*ret = 0;
	switch (event) {
#ifdef CONFIG_THERMAL_INTELLIGENT_FREQ_CTRL
	case EXT_EVENT_DO_FRAME_BEGIN:
		update_doframe_status(true);
		return true;
	case EXT_EVENT_DO_FRAME_END:
		update_doframe_status(false);
		return true;
	case EXT_EVENT_GC_WAIT_BEGIN:
		handle_art_gc_wait(true);
		return true;
	case EXT_EVENT_GC_WAIT_END:
		handle_art_gc_wait(false);
		return true;
#endif
	default:
		break;
	}
	return false;
}
#endif

#ifdef CONFIG_TASK_COMM_STATIC_WHITELIST
void static_whitelist_update(struct task_struct *p)
{
#ifdef CONFIG_THERMAL_INTELLIGENT_FREQ_CTRL
	thermal_intelligent_whitelist_update(p);
#endif
}
#endif
