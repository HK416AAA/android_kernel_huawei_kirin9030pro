// SPDX-License-Identifier: GPL-2.0
/*
 * Detect hard lockups on a system
 *
 * started by Don Zickus, Copyright (C) 2010 Red Hat, Inc.
 *
 * Note: Most of this code is borrowed heavily from the original softlockup
 * detector, so thanks to Ingo for the initial implementation.
 * Some chunks also taken from the old x86-specific nmi watchdog code, thanks
 * to those contributors as well.
 */

#define pr_fmt(fmt) "NMI watchdog: " fmt

#include <linux/nmi.h>
#include <linux/atomic.h>
#include <linux/module.h>
#include <linux/sched/debug.h>
#include <linux/cpufreq.h>
#include <asm/system_misc.h>
#include <asm/irq_regs.h>
#include <linux/perf_event.h>

static DEFINE_PER_CPU(bool, hard_watchdog_warn);
static DEFINE_PER_CPU(bool, watchdog_nmi_touch);
#ifdef CONFIG_HARDLOCKUP_DETECTOR_PERF
static DEFINE_PER_CPU(struct perf_event *, watchdog_ev);
static DEFINE_PER_CPU(struct perf_event *, dead_event);
static struct cpumask dead_events_mask;
static atomic_t watchdog_cpus = ATOMIC_INIT(0);
#endif
static unsigned long hardlockup_allcpu_dumped;
#ifdef CONFIG_HARDLOCKUP_DETECTOR_BUDDY
static cpumask_t __read_mostly watchdog_cpus_mask;
#endif

notrace void arch_touch_nmi_watchdog(void)
{
	/*
	 * Using __raw here because some code paths have
	 * preemption enabled.  If preemption is enabled
	 * then interrupts should be enabled too, in which
	 * case we shouldn't have to worry about the watchdog
	 * going off.
	 */
	raw_cpu_write(watchdog_nmi_touch, true);
}
EXPORT_SYMBOL(arch_touch_nmi_watchdog);

static void watchdog_hardlockup_touch_cpu(int cpu)
{
	per_cpu(watchdog_nmi_touch, cpu) = true;
}

#ifdef CONFIG_HARDLOCKUP_CHECK_TIMESTAMP
static DEFINE_PER_CPU(ktime_t, last_timestamp);
static DEFINE_PER_CPU(unsigned int, nmi_rearmed);
static ktime_t watchdog_hrtimer_sample_threshold __read_mostly;

void watchdog_update_hrtimer_threshold(u64 period)
{
	/*
	 * The hrtimer runs with a period of (watchdog_threshold * 2) / 5
	 *
	 * So it runs effectively with 2.5 times the rate of the NMI
	 * watchdog. That means the hrtimer should fire 2-3 times before
	 * the NMI watchdog expires. The NMI watchdog on x86 is based on
	 * unhalted CPU cycles, so if Turbo-Mode is enabled the CPU cycles
	 * might run way faster than expected and the NMI fires in a
	 * smaller period than the one deduced from the nominal CPU
	 * frequency. Depending on the Turbo-Mode factor this might be fast
	 * enough to get the NMI period smaller than the hrtimer watchdog
	 * period and trigger false positives.
	 *
	 * The sample threshold is used to check in the NMI handler whether
	 * the minimum time between two NMI samples has elapsed. That
	 * prevents false positives.
	 *
	 * Set this to 4/5 of the actual watchdog threshold period so the
	 * hrtimer is guaranteed to fire at least once within the real
	 * watchdog threshold.
	 */
	watchdog_hrtimer_sample_threshold = period * 2;
}

static bool watchdog_check_timestamp(void)
{
	ktime_t delta, now = ktime_get_mono_fast_ns();

	delta = now - __this_cpu_read(last_timestamp);
	if (delta < watchdog_hrtimer_sample_threshold) {
		/*
		 * If ktime is jiffies based, a stalled timer would prevent
		 * jiffies from being incremented and the filter would look
		 * at a stale timestamp and never trigger.
		 */
		if (__this_cpu_inc_return(nmi_rearmed) < 10)
			return false;
	}
	__this_cpu_write(nmi_rearmed, 0);
	__this_cpu_write(last_timestamp, now);
	return true;
}
#else
static inline bool watchdog_check_timestamp(void)
{
	return true;
}
#endif

#ifdef CONFIG_HARDLOCKUP_DETECTOR_PERF
static struct perf_event_attr wd_hw_attr = {
	.type		= PERF_TYPE_HARDWARE,
	.config		= PERF_COUNT_HW_CPU_CYCLES,
	.size		= sizeof(struct perf_event_attr),
	.pinned		= 1,
	.disabled	= 1,
};

/* Callback function for perf event subsystem */
static void watchdog_overflow_callback(struct perf_event *event,
				       struct perf_sample_data *data,
				       struct pt_regs *regs)
{
	/* Ensure the watchdog never gets throttled */
	event->hw.interrupts = 0;

	if (__this_cpu_read(watchdog_nmi_touch) == true) {
		__this_cpu_write(watchdog_nmi_touch, false);
		return;
	}

	if (!watchdog_check_timestamp())
		return;

	/* check for a hardlockup
	 * This is done by making sure our timer interrupt
	 * is incrementing.  The timer interrupt should have
	 * fired multiple times before we overflow'd.  If it hasn't
	 * then this is a good indication the cpu is stuck
	 */
	int this_cpu = smp_processor_id();
	if (is_hardlockup(this_cpu)) {

		/* only print hardlockups once */
		if (__this_cpu_read(hard_watchdog_warn) == true)
			return;

		pr_emerg("Watchdog detected hard LOCKUP on cpu %d\n",
			 this_cpu);
		print_modules();
		print_irqtrace_events(current);
		if (regs)
			__show_regs(regs);
		dump_stack_lvl(KERN_EMERG);

		/*
		 * Perform all-CPU dump only once to avoid multiple hardlockups
		 * generating interleaving traces
		 */
		if (sysctl_hardlockup_all_cpu_backtrace &&
				!test_and_set_bit(0, &hardlockup_allcpu_dumped))
			nmi_trigger_cpumask_backtrace(cpu_online_mask, true, arm64_backtrace_ipi);

		if (hardlockup_panic)
			nmi_panic(regs, "Hard LOCKUP");

		__this_cpu_write(hard_watchdog_warn, true);
		return;
	}

	__this_cpu_write(hard_watchdog_warn, false);
	return;
}

/*
 * Safe maximum CPU frequency in case a particular platform doesn't implement
 * cpufreq driver. Although, architecture doesn't put any restrictions on
 * maximum frequency but 5 GHz seems to be safe maximum given the available
 * Arm CPUs in the market which are clocked much less than 5 GHz. On the other
 * hand, we can't make it much higher as it would lead to a large hard-lockup
 * detection timeout on parts which are running slower (eg. 1GHz on
 * Developerbox) and doesn't possess a cpufreq driver.
 */
#define SAFE_MAX_CPU_FREQ	5000000000UL // 5 GHz
u64 hw_nmi_get_sample_period(int watchdog_thresh)
{
	unsigned int cpu = smp_processor_id();
	unsigned long max_cpu_freq;

	max_cpu_freq = cpufreq_get_hw_max_freq(cpu) * 1000UL;
	if (!max_cpu_freq)
		max_cpu_freq = SAFE_MAX_CPU_FREQ;

	return (u64)max_cpu_freq * watchdog_thresh;
}

static int hardlockup_detector_event_create(void)
{
	unsigned int cpu = smp_processor_id();
	struct perf_event_attr *wd_attr;
	struct perf_event *evt;

	wd_attr = &wd_hw_attr;
	wd_attr->sample_period = hw_nmi_get_sample_period(watchdog_thresh);
	if (!wd_attr->sample_period)
		return -EINVAL;

	/* Try to register using hardware perf events */
	evt = perf_event_create_kernel_counter(wd_attr, cpu, NULL,
					       watchdog_overflow_callback, NULL);
	if (IS_ERR(evt)) {
		pr_debug("Perf event create on CPU %d failed with %ld\n", cpu,
			 PTR_ERR(evt));
		return PTR_ERR(evt);
	}
	this_cpu_write(watchdog_ev, evt);
	return 0;
}

/**
 * hardlockup_detector_perf_enable - Enable the local event
 */
void hardlockup_detector_perf_enable(void)
{
	if (hardlockup_detector_event_create())
		return;

	/* use original value for check */
	if (!atomic_fetch_inc(&watchdog_cpus))
		pr_info("Enabled. Permanently consumes one hw-PMU counter.\n");

	perf_event_enable(this_cpu_read(watchdog_ev));
}

/**
 * hardlockup_detector_perf_disable - Disable the local event
 */
void hardlockup_detector_perf_disable(void)
{
	struct perf_event *event = this_cpu_read(watchdog_ev);

	if (event) {
		perf_event_disable(event);
		this_cpu_write(watchdog_ev, NULL);
		this_cpu_write(dead_event, event);
		cpumask_set_cpu(smp_processor_id(), &dead_events_mask);
		atomic_dec(&watchdog_cpus);
	}
}

/**
 * hardlockup_detector_perf_cleanup - Cleanup disabled events and destroy them
 *
 * Called from lockup_detector_cleanup(). Serialized by the caller.
 */
void hardlockup_detector_perf_cleanup(void)
{
	int cpu;

	for_each_cpu(cpu, &dead_events_mask) {
		struct perf_event *event = per_cpu(dead_event, cpu);

		/*
		 * Required because for_each_cpu() reports  unconditionally
		 * CPU0 as set on UP kernels. Sigh.
		 */
		if (event)
			perf_event_release_kernel(event);
		per_cpu(dead_event, cpu) = NULL;
	}
	cpumask_clear(&dead_events_mask);
}

/**
 * hardlockup_detector_perf_stop - Globally stop watchdog events
 *
 * Special interface for x86 to handle the perf HT bug.
 */
void __init hardlockup_detector_perf_stop(void)
{
	int cpu;

	lockdep_assert_cpus_held();

	for_each_online_cpu(cpu) {
		struct perf_event *event = per_cpu(watchdog_ev, cpu);

		if (event)
			perf_event_disable(event);
	}
}

/**
 * hardlockup_detector_perf_restart - Globally restart watchdog events
 *
 * Special interface for x86 to handle the perf HT bug.
 */
void __init hardlockup_detector_perf_restart(void)
{
	int cpu;

	lockdep_assert_cpus_held();

	if (!(watchdog_enabled & NMI_WATCHDOG_ENABLED))
		return;

	for_each_online_cpu(cpu) {
		struct perf_event *event = per_cpu(watchdog_ev, cpu);

		if (event)
			perf_event_enable(event);
	}
}

/**
 * hardlockup_detector_perf_init - Probe whether NMI event is available at all
 */
int __init hardlockup_detector_perf_init(void)
{
	int ret = hardlockup_detector_event_create();

	if (ret) {
		pr_info("Perf NMI watchdog permanently disabled\n");
	} else {
		perf_event_release_kernel(this_cpu_read(watchdog_ev));
		this_cpu_write(watchdog_ev, NULL);
	}
	return ret;
}
#endif

#ifdef CONFIG_HARDLOCKUP_DETECTOR_BUDDY
bool watchdog_hardlockup_check(unsigned int cpu, struct pt_regs *regs)
{
	if (per_cpu(watchdog_nmi_touch, cpu)) {
		per_cpu(watchdog_nmi_touch, cpu) = false;
		return false;
	}

	/*
	 * Check for a hardlockup by making sure the CPU's timer
	 * interrupt is incrementing. The timer interrupt should have
	 * fired multiple times before we overflow'd. If it hasn't
	 * then this is a good indication the cpu is stuck
	 */
	if (is_hardlockup(cpu)) {
		unsigned int this_cpu = smp_processor_id();

		/* Only print hardlockups once. */
		if (per_cpu(hard_watchdog_warn, cpu))
			return true;

		/*
		 * NOTE: we call printk_cpu_sync_get_irqsave() after printing
		 * the lockup message. While it would be nice to serialize
		 * that printout, we really want to make sure that if some
		 * other CPU somehow locked up while holding the lock associated
		 * with printk_cpu_sync_get_irqsave() that we can still at least
		 * get the message about the lockup out.
		 */
		pr_emerg("CPU%u: Watchdog detected hard LOCKUP on cpu %u\n", this_cpu, cpu);

		print_modules();
		print_irqtrace_events(current);
		if (cpu == this_cpu) {
			if (regs)
				__show_regs(regs);
			dump_stack_lvl(KERN_EMERG);
		} else {
			nmi_trigger_cpumask_backtrace(cpumask_of(cpu), false, arm64_backtrace_ipi);
		}

		/*
		 * Perform all-CPU dump only once to avoid multiple hardlockups
		 * generating interleaving traces
		 */
		if (sysctl_hardlockup_all_cpu_backtrace &&
				!test_and_set_bit(0, &hardlockup_allcpu_dumped))
			nmi_trigger_cpumask_backtrace(cpu_online_mask, true, arm64_backtrace_ipi);

		if (hardlockup_panic)
			nmi_panic(regs, "Hard LOCKUP");
		per_cpu(hard_watchdog_warn, cpu) = true;
		return true;
	} else {
		per_cpu(hard_watchdog_warn, cpu) = false;
		return false;
	}
}

static unsigned int watchdog_next_cpu(unsigned int cpu)
{
	unsigned int next_cpu;

	next_cpu = cpumask_next(cpu, &watchdog_cpus_mask);
	if (next_cpu >= nr_cpu_ids)
		next_cpu = cpumask_first(&watchdog_cpus_mask);

	if (next_cpu == cpu)
		return nr_cpu_ids;

	return next_cpu;
}

int __init watchdog_hardlockup_probe(void)
{
	return 0;
}

void watchdog_hardlockup_enable(unsigned int cpu)
{
	unsigned int next_cpu;

	/*
	 * The new CPU will be marked online before the hrtimer interrupt
	 * gets a chance to run on it. If another CPU tests for a
	 * hardlockup on the new CPU before it has run its the hrtimer
	 * interrupt, it will get a false positive. Touch the watchdog on
	 * the new CPU to delay the check for at least 3 sampling periods
	 * to guarantee one hrtimer has run on the new CPU.
	 */
	watchdog_hardlockup_touch_cpu(cpu);

	/*
	 * We are going to check the next CPU. Our watchdog_hrtimer
	 * need not be zero if the CPU has already been online earlier.
	 * Touch the watchdog on the next CPU to avoid false positive
	 * if we try to check it in less then 3 interrupts.
	 */
	next_cpu = watchdog_next_cpu(cpu);
	if (next_cpu < nr_cpu_ids)
		watchdog_hardlockup_touch_cpu(next_cpu);

	/*
	 * Makes sure that watchdog is touched on this CPU before
	 * other CPUs could see it in watchdog_cpus_mask. The counter
	 * part is in watchdog_buddy_check_hardlockup().
	 */
	smp_wmb();

	cpumask_set_cpu(cpu, &watchdog_cpus_mask);
}

void watchdog_hardlockup_disable(unsigned int cpu)
{
	unsigned int next_cpu = watchdog_next_cpu(cpu);

	/*
	 * Offlining this CPU will cause the CPU before this one to start
	 * checking the one after this one. If this CPU just finished checking
	 * the next CPU and updating hrtimer_interrupts_saved, and then the
	 * previous CPU checks it within one sample period, it will trigger a
	 * false positive. Touch the watchdog on the next CPU to prevent it.
	 */
	if (next_cpu < nr_cpu_ids)
		watchdog_hardlockup_touch_cpu(next_cpu);

	/*
	 * Makes sure that watchdog is touched on the next CPU before
	 * this CPU disappear in watchdog_cpus_mask. The counter part is in
	 * watchdog_buddy_check_hardlockup().
	 */
	smp_wmb();

	cpumask_clear_cpu(cpu, &watchdog_cpus_mask);
}

void watchdog_buddy_check_hardlockup(unsigned long hrtimer_interrupts)
{
	unsigned int next_cpu;

	/*
	 * Test for hardlockups every 3 samples. The sample period is
	 *  watchdog_thresh * 2 / 5, so 3 samples gets us back to slightly over
	 *  watchdog_thresh (over by 20%).
	 */
	if (hrtimer_interrupts % 3 != 0)
		return;

	/* check for a hardlockup on the next CPU */
	next_cpu = watchdog_next_cpu(smp_processor_id());
	if (next_cpu >= nr_cpu_ids)
		return;

	/*
	 * Make sure that the watchdog was touched on next CPU when
	 * watchdog_next_cpu() returned another one because of
	 * a change in watchdog_hardlockup_enable()/disable().
	 */
	smp_rmb();
	watchdog_hardlockup_check(next_cpu, NULL);
}
#endif