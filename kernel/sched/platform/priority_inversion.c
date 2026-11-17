// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Apply a vruntime_offset (similar to assign a low latency_nice) for cfs tasks
 * holding any kernel lock to help to resolve priority inversion, typically
 * when critical tasks block by kernelspace rwsem held by a background task.
 * Now enabled for background tasks. Support mutex, rcu, rwsem, percpu-rwsem.
 * See the Kconfig entry for more information.
 */
#include "sched.h"
#include <trace/events/sched.h>

void critical_section_init(struct task_struct *p)
{
	critical_section_reset(p);
#ifdef CONFIG_SCHED_PI_DEBUG_LOCK_NESTING
	current->raw_lock_nesting = 0;
#endif
}

unsigned int __read_mostly max_vruntime_offset = 8 * NSEC_PER_MSEC;
void update_vruntime_offset(void)
{
	unsigned int sleep_offset = sysctl_sched_latency >> 1; /* 5ms */
	unsigned int extra_offset = sysctl_sched_min_granularity; /* 3ms */
	max_vruntime_offset = sleep_offset + extra_offset;
}

/*
 * When task is holding kernel locks and going to unlock later, it may
 * block any other tasks including ux tasks. We would like to have the
 * scheduler to temporarily prioritize it with an offset on vruntime
 * (and also don't increase its vruntime too much due to large nice).
 * That is similar to have kernel-lock-helding tasks on a special list
 * and pick them first in cfs, but better.
 *
 * In the detailed implementation we have critical_section_enter/exit()
 * doing current->lock_nesting++/--. That is good, unless the enter
 * and exit are separated to different threads.
 * For example, a task or a syscall acquires a mutex lock and queue a
 * kwork to do some future jobs and unlock the mutex.
 * We can ignore the asynchronous task that doing the unlock but we should
 * not leave any task with an unwanted lock nesting state for long. So we
 * got 2 places for resetting the state.
 * 1. EL1 return to EL0.
 *    When returned to EL0, the task must not be in a critical section
 *    of kernel lock literally. So there's no reason to prioritize it. And
 *    also we never like to prioritize untrusted userspace code.
 * 2. Timeout.
 *    Sometimes we don't have 1, e.g. a kernel task. So we need a timeout,
 *    which is implemented about 4~8ms in critical_section_update_delta().
 *    Note that the timeout is not only for escaping from an unexpected
 *    lock nesting state due to unmatched locking, but also prevent kernel
 *    tasks who hold locks too long to be always prioritized in scheduler.
 * There can be other cases, for example a kernel task doing lock and
 * unlock frequently so that it's always prioritized.
 * But looking back to what we do in scheduler:
 * It's just similar to temorarily set a latency_nice and clamp >0 nice
 * to 0 for critical section part of a task, but in a low overhead way.
 * So rare occurrence of weird cases won't break fairness for user experience.
 * And to be more conservative we only enable this feature for BG tasks now
 * as the first step.
 */
asmlinkage void noinstr critical_section_ret_to_user(void)
{
	if (unlikely(current->lock_nesting > 0))
		critical_section_reset(current);

	debug_critical_section_ret_to_user();
}

static void dec_vruntime_offset(struct task_struct *p, s64 delta)
{
	if (unlikely(delta < 0))
		delta = 0;
	else if (delta > p->vruntime_offset)
		delta = p->vruntime_offset;

	p->vruntime_offset -= delta;
	trace_perf(dec_vruntime_offset, p, p->vruntime_offset, delta);
}

/*
 * Called by calc_delta_fair_for_vruntime().
 * *delta: the realtime delta_exec.
 * Return true means calculate the vruntime delta and save the value back
 * to *delta.
 * Return false means leave further functions to calculate vruntime delta
 * and keep *delta unchanged.
 */
bool critical_section_update_delta(struct sched_entity *se, u64 *delta)
{
	struct task_struct *p = NULL;
	u64 realtime_delta, vruntime_delta;
	s64 offset_delta;

	/*
	 * Why only task level?
	 * The ideal solution would be disable FAIR_GROUP_SCHED, or in
	 * other words use CONFIG_SEPARATE_SCHED_TUNE_AND_GROUP_SCHED
	 * instead of CONFIG_SCHED_FAIR_GROUP_SHARE_BYPASS. Then we
	 * won't get trouble in the group level sched entity.
	 * If we have FAIR_GROUP_SCHED and no *_BYPASS, we have
	 * each group level se's weight of 1024 (NICE_0_LOAD), or a
	 * configured value based on 1024. Then we don't need to clamp
	 * nice but only need to add a vruntime_offset. The 8ms offset
	 * works in realtime 8ms for 1024 weight ses. Our opt still
	 * can work.
	 * But now we have *_BYPASS, which makes future optimizations
	 * hard to implement. It adjust weight of group level se
	 * dynamically. So we can't add any vruntime_offset since the
	 * weight can be very large.
	 * So we can only do our opt in task level, which means, a
	 * TA task X preempts BG lock-helding task Y, Y has no benefits.
	 * BG task Y is only preferred when comparing with other BG tasks.
	 */
	if (!entity_is_task(se))
		return false;

	p = task_of(se);
	if (!p->vruntime_offset || !task_group(p)->prior_cs_task)
		return false;

	realtime_delta = *delta;

	/*
	 * We must not increase a in-critical-section task's vruntime
	 * too much due to its large nice (i.e. low weight). We have
	 * no choice.
	 * Here we treat load < NICE_0_LOAD as NICE_0_LOAD (i.e. >0 nice
	 * as 0 nice), which apply no scale for realtime delta.
	 */
	if (se->load.weight > NICE_0_LOAD)
		*delta = calc_delta(*delta, NICE_0_LOAD, &se->load);

	vruntime_delta = *delta;

	/*
	 * At the first time we see a task in critical section, we have
	 * to give it a enough offset to compete others, which has to
	 * be about 8ms.
	 * As time passes, should we degrade it? How?
	 *
	 * In the earlier patch I've implemented a 10ms timeout for tasks
	 * in critical section for very long or unmatched lock nesting.
	 * But soon I realized that we don't need another member to do so.
	 * We can degrade vruntime_offset to 0 in a timeout instead.
	 * So how do we degrade vruntime_offset? We degrade it consistently,
	 * and the time it takes degrading to 0 determines the speed and
	 * fairness.
	 * In the following formula:
	 * - Very low nice tasks degrade to 0 in 4ms (VRUNTIME_OFFSET/2).
	 * - Normal nice tasks degrade to 0 in 8ms (VRUNTIME_OFFSET).
	 * All tasks in critical section have a init vruntime offset of
	 * 8ms and after they run for 4ms, the vruntime_of() must increase
	 * 8ms, regardless of their nice.
	 * This may seem tricky, but simple and clear.
	 */
	offset_delta = realtime_delta * 2 - vruntime_delta;
	dec_vruntime_offset(p, offset_delta);

	if (p->vruntime_offset == 0) {
		/*
		 * We need to reset lock_nesting to protect the lock
		 * unmatched case. Note that the scheduler should not
		 * be aware of the lock_nesting of a task but only the
		 * vruntime_offset. There're 2 places calling
		 * critical_section_reset() to help the lock unmatched
		 * case, see comment of the other one.
		 */
		critical_section_reset(p);
	}

	return true;
}

#ifdef CONFIG_SCHED_PI_DEBUG_LOCK_NESTING
/*
 * Note that, lock/unlock may be separated in two different threads.
 * So there could be false positives. But we must need it to check if
 * we add critical_section_enter/exit() correctly otherwise this
 * whole feature is broken.
 */
unsigned int __read_mostly sysctl_debug_lock_nesting;
static noinline void debug_show_stack(const char *msg)
{
	trace_perf(critical_section, 'U', CALLER_ADDR2, CALLER_ADDR1);

	if (unlikely(sysctl_debug_lock_nesting))
		printk_deferred("Unmatched lock nesting in %s."
			" Callstack %pS->%pS->%pS\n",
			msg, CALLER_ADDR3, CALLER_ADDR2, CALLER_ADDR1);
}

/*
 * Why do we need a raw_lock_nesting?
 * When decreasing vruntime_offset to 0, we must also clear lock_nesting
 * so that unmatched lock nesting will have a timeout and we are able to
 * init_vruntime_offset() at next critical_section_enter() of the task.
 * But we can't say the critical_section_reset() at decreasing
 * vruntime_offset to 0 is a invalid case. That could be correct lock
 * nesting but a little bit long.
 * So the only difference is, raw_lock_nesting don't change when degrading
 * vruntime_offset to 0.
 */
void debug_critical_section_enter(void)
{
	if (unlikely(current->raw_lock_nesting >= 32))
		debug_show_stack("enter");
	else
		current->raw_lock_nesting++;

	trace_perf(critical_section, '+', CALLER_ADDR1, CALLER_ADDR0);
}

void debug_critical_section_exit(void)
{
	if (unlikely(current->raw_lock_nesting <= 0))
		debug_show_stack("exit");
	else
		current->raw_lock_nesting--;

	trace_perf(critical_section, '-', CALLER_ADDR1, CALLER_ADDR0);
}

void debug_critical_section_ret_to_user(void)
{
	if (unlikely(current->raw_lock_nesting > 0)) {
		debug_show_stack("ret_to_user");
		current->raw_lock_nesting = 0;
		trace_perf(critical_section, '^', CALLER_ADDR1, CALLER_ADDR0);
	}
}
#endif /* CONFIG_SCHED_PI_DEBUG_LOCK_NESTING */

/*
 * The cgroup_threadgroup_rwsem is extremely important for worst-case user
 * experience so it deserves a single enhancement.
 * Note that fork and exit are cgroup_threadgroup_rwsem readers. We've
 * received many issues for a long time when the critical path is doing
 * pthread_create (cgroup_css_set_fork) and the system is killing
 * background process (exit_signals on each thread). And when they meet
 * another condition that there is any writer (e.g. writing cgroup_procs)
 * the readers are synchronized (i.e. rwsem acts like mutex when writer
 * blocks). So, we want to solve this issue since it is highly possible
 * and hurts user experience very much.
 * Possible solutions:
 * 1. Implement cgroup_threadgroup_critical_section_enter() as
 *    critical_section_enter().
 *    Good. But there are two shortcomings:
 *    1.1 As explained in critical_section_update_delta() comments, we've
 *    lost the opportunity of disabling group sched. So that we are not able
 *    to prior critical section tasks across different cgroups. We've been
 *    reported that a thread in background app A are holding reader lock
 *    and runnable for 100+ms and system is killing background app B but app
 *    B is on the progress of migrating to background cpu cgroup (the
 *    progress is blocked) so app B is in the background cpuset but top-app
 *    cpu cgroup. In this case we can't have critical_section_enter() work.
 *    1.2 Even if our feature can work, killing background process can involve
 *    hundreds or thousands of bg threads. At lease we need to do better than
 *    a normal critical_section_enter().
 * 2. Since it's highly possible that critical path is a reader and the
 *    runnable bg threads are also readers, why don't we sacrifice the
 *    fairness of rwsem writer a little bit and let RT readers go though
 *    when there're no writers holding it.
 *    Good idea and possible. I will definitely choose this way if on HM
 *    kernel or Linux kernel years before. But now we shouldn't.
 * 3. Simply boost all users (including readers) of cgroup_threadgroup_rwsem
 *    in a low overhead way.
 *    We still have two choices: hw vip or hisi vip. Hisi vip has higher
 *    overhead but much better infrastructure.
 *    Boosting simple kernel functions will bring no harm except the overhead.
 *    So we build a low overhead hisi vip boost infrastructure and worry about
 *    nothing else.
 * In brief, we need 3 to make up for the issue that critical_section_enter()
 * can't work across cgroups when there're extreme performance requirements.
 */
void cgroup_threadgroup_critical_section_enter(void)
{
#ifdef CONFIG_ENHANCED_CGROUP_RWSEM_PI_OPT
	request_vip_boost(current, 1, VIP_BOOST_CGROUP_RWSEM_DEFERRED);
#else
	critical_section_enter();
#endif
}

void cgroup_threadgroup_critical_section_exit(void)
{
#ifdef CONFIG_ENHANCED_CGROUP_RWSEM_PI_OPT
	clear_vip_boost(current, VIP_BOOST_CGROUP_RWSEM_DEFERRED);
#else
	critical_section_exit();
#endif
}
