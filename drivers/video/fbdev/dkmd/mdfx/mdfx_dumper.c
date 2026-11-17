/*
 * Copyright (c) 2019-2019, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/time.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <linux/sched/clock.h>
#include <linux/fs.h>
#include <linux/sched/task_stack.h>
#ifdef CONFIG_MDFX_KMD_CALL_STACK
#include <asm/stacktrace.h>
#include <asm/traps.h>
#endif
#include <linux/slab.h>
#include <linux/dirent.h>
#include <securec.h>
#include "mdfx_utils.h"
#include "mdfx_dumper.h"
#include "mdfx_priv.h"
#include "mdfx_file.h"

#define FREQ_AND_VOLTAGE_BUF_LEN 1024
#define BUF_SIZE 8192

static char *g_dump_buf = NULL;
static uint32_t g_dump_buf_len;

#ifdef CONFIG_MDFX_KMD_CALL_STACK
/*
 * Dump out the contents of some kernel memory nicely...
 */
static void mdfx_dump_mem(const char *lvl, const char *str,
			unsigned long bottom, unsigned long top, int64_t id)
{
	unsigned long first;
	mm_segment_t fs;
	int i;

	/*
	 * We need to switch to kernel mode so that we can use __get_user
	 * to safely read from kernel space.
	 */
	fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "%s%s(0x%016lx to 0x%016lx)\n", lvl, str, bottom, top);

	for (first = bottom & ~31; first < top; first += 32) {
		unsigned long p;
		char str[sizeof(" 12345678") * 8 + 1]; //lint !e578

		(void)memset_s(str, sizeof(str), ' ', sizeof(str));
		str[sizeof(str) - 1] = '\0';

		for (p = first, i = 0; i < (32 / 8) && (p < top); i++, p += 8) {
			if (p >= bottom && p < top) {
				unsigned long val;
				if (__get_user(val, (unsigned long *)(uintptr_t)p) == 0)
					sprintf(str + i * 17, " %016lx", val); //lint !e530
				else
					sprintf(str + i * 17, " ????????????????"); //lint !e585
			}
		}
		mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "%s%04lx:%s\n", lvl, first & 0xffff, str);
	}

	set_fs(fs);
}

static inline void mdfx_dump_backtrace_entry(unsigned long where, int64_t id)
{
	/*
	 * Note that 'where' can have a physical address, but it's not handled.
	 */
	mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "[<%p>] %pS\n", (void *)(uintptr_t)where, (void *)(uintptr_t)where);
}

static void mdfx_dump_backtrace(struct pt_regs *regs, struct task_struct *tsk, int64_t id)
{
	struct stackframe frame;
	unsigned long last_pc = 0;
	unsigned long count = 0;
	unsigned long stack;
	struct stack_info stack_info;
	int ret;
	bool skip = false;

	if (!tsk)
		tsk = current;

	if (!try_get_task_stack(tsk))
		return;

	if (tsk == current) {
		frame.fp = (unsigned long)(uintptr_t)__builtin_frame_address(0);
		frame.pc = (unsigned long)(uintptr_t)dump_backtrace;
	} else {
		/*
		 * task blocked in __switch_to
		 */
		frame.fp = thread_saved_fp(tsk);
		frame.pc = thread_saved_pc(tsk);
	}

	mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "Call trace:\n");

	skip = !!regs;
	while (1) {
		/* skip until specified stack frame */
		if (!skip) {
			/* to solve the dump backtrace infinite loop problem */
			if (frame.pc == last_pc) {
				count++;
				if (count >= MAX_BACKTRACE_COUNT) {
					mdfx_pr_err("count is overflow");
					mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "(backtrace infinite loop:fp %p pc %p)\n",
							(void *)(uintptr_t)frame.fp, (void *)(uintptr_t)frame.pc);
					break;
				}
			} else {
				last_pc = frame.pc;
				count = 0;
			}

			mdfx_dump_backtrace_entry(frame.pc, id);
		} else if (frame.fp == regs->regs[29]) {
			skip = false;
			/*
			 * Mostly, this is the case where this function is
			 * called in panic/abort. As exception handler's
			 * stack frame does not contain the corresponding pc
			 * at which an exception has taken place, use regs->pc
			 * instead.
			 */
			mdfx_dump_backtrace_entry(regs->pc, id);
		}

		ret = unwind_frame(tsk, &frame);
		if (ret < 0) {
			mdfx_pr_err("ret=%d, count=%lu", ret, count);
			break;
		}

		if (in_entry_text(frame.pc)) {
			stack = frame.fp - offsetof(struct pt_regs, stackframe);
			if (on_accessible_stack(tsk, stack, &stack_info))
				mdfx_dump_mem("", "Exception stack", stack,
					 stack + sizeof(struct pt_regs), id);
		}
	}

	put_task_stack(tsk);
}

static void mdfx_dump_stack_print_info(struct task_struct *tsk, int64_t id)
{
	struct task_struct *task = NULL;
	int tmp;

	task = (tsk == NULL) ? current : tsk;
#ifdef CONFIG_SMP
#ifdef CONFIG_THREAD_INFO_IN_TASK
	tmp = task->cpu;
#else
	tmp = -1;
#endif
#else
	tmp = 0;
#endif

	mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "Comm: %.20s Current CPU: %d PID: %d\n", task->comm, tmp, task->pid);

	/*
	 * In different processes, some threads may have the same name.
	 * So we need to get the tgid and the comm of thread's group_leader.
	 */
	mdfx_dump_msg(g_dump_buf, g_dump_buf_len, "TGID: %d Comm: %.20s\n",
		task->tgid, task->group_leader->comm);
}

static void mdfx_show_stack(struct task_struct *tsk, struct pt_regs *regs, int64_t id)
{
	mdfx_dump_stack_print_info(tsk, id);
	mdfx_dump_backtrace(regs, tsk, id);
	barrier();
}

/*
 * dfx_dump_stack - dump the current task information and its stack trace
 */
#ifdef CONFIG_SMP
static atomic_t mdfx_bt_dump_lock = ATOMIC_INIT(-1);
static void mdfx_dump_stack(struct task_struct *tsk, struct pt_regs *regs, int64_t id)
{
	int was_locked;
	int old;
	int cpu;

	/*
	 * Permit this cpu to perform nested stack dumps while serialising
	 * against other CPUs
	 */
retry:
	cpu = smp_processor_id();
	old = atomic_cmpxchg(&mdfx_bt_dump_lock, -1, cpu); //lint !e571
	if (old == -1) {
		was_locked = 0;
	} else if (old == cpu) {
		was_locked = 1;
	} else {
		cpu_relax();
		goto retry;
	}

	mdfx_show_stack(tsk, regs, id);

	if (!was_locked)
		atomic_set(&mdfx_bt_dump_lock, -1);
}
#else
static void mdfx_dump_stack(struct task_struct *tsk, struct pt_regs *regs, int64_t id)
{
	mdfx_show_stack(tsk, regs, id);
}
#endif

static DEFINE_SPINLOCK(show_stack_lock);
static void mdfx_show_runing_cpu_stack(void *dummy)
{
	struct task_struct *task = NULL;
	unsigned long flags = 0;
	int64_t id = 0;

	if (idle_cpu(smp_processor_id()))
		return;

	spin_lock_irqsave(&show_stack_lock, flags);

	mdfx_pr_err("dump stack cpu:%d", smp_processor_id());

	/* look up all runnable task, and then dump its backtrace */
	mdfx_for_each_process(task) {
		if (task != NULL && !task->state)
			mdfx_dump_stack(task, NULL, id);
	}

	mdfx_pr_info("dump_buf_len=%u", g_dump_buf_len);

	spin_unlock_irqrestore(&show_stack_lock, flags);
}

static void mdfx_dump_runnable_task(int64_t id, const char *event_name)
{
	char postfix[FILENAME_LEN] = {0};
	int ret;

	if (IS_ERR_OR_NULL(g_dump_buf)) {
		g_dump_buf = kzalloc(MAX_BACKTRACE_LEN, GFP_KERNEL);
		if (g_dump_buf == NULL) 
			return;

		g_dump_buf_len = 0;
	}

	smp_call_function(mdfx_show_runing_cpu_stack, NULL, 1);

	mdfx_pr_info("g_dump_buf_len=%u", g_dump_buf_len);
	if (event_name[0] != '\0')
		ret = scnprintf(postfix, FILENAME_LEN, "event[%s]_id[%lld]_backtrace", event_name, id);
	else
		ret = scnprintf(postfix, FILENAME_LEN, "%s_id[%lld]_backtrace", MDFX_NORMAL_NAME_PREFIX, id);
	if (ret > 0)
		mdfx_save_buffer_to_file(postfix, g_dump_buf, g_dump_buf_len);

	kfree(g_dump_buf);
	g_dump_buf = NULL;
	g_dump_buf_len = 0;
}
#else
static void mdfx_dump_runnable_task(int64_t id, const char *event_name)
{}
#endif

/*
 * dumper dumps various of system info: frequency and voltage, cmdlist, cpu runnable, client callstack.
 * if the client gave callback interface, execute it.
 * dynamic allocated memory space that param data pointed, take care of releasing it.
 */
static void mdfx_dump_detail(struct mdfx_dumper_ctrl *dumper_ctrl, char *event_name, char *timestamp)
{
	struct mdfx_visitor_node* visitor = NULL;
	uint64_t detail;
	visitor_cb_param_t param = {0};

	if (IS_ERR_OR_NULL(dumper_ctrl)) {
		mdfx_pr_err("data is null");
		return;
	}

	detail = dumper_ctrl->desc.dump_infos & DUMPER_NEED_DUMP_DETAIL;
	if (detail == 0)
		return;

	mdfx_pr_info("detail=%llu", detail);

	if (IS_ENABLE_BITS_FIELD(detail, DUMP_DETAIL_ALL_CPU_RUNNABLE))
		mdfx_dump_runnable_task(dumper_ctrl->desc.id, "cpu_backtrace");

	if (IS_ENABLE_BITS_FIELD(detail, NOTIFY_DETAIL_MASK)) {
		visitor = mdfx_get_visitor(&g_mdfx_data->visitors, dumper_ctrl->desc.id);
		if (visitor == NULL)
			return;

		if (visitor->callback) {
			param.id = dumper_ctrl->desc.id;
			param.actions = detail;
			param.even_name = event_name;
			param.timestamp = timestamp;
			param.data = visitor->callback_data;
			param.value = dumper_ctrl->value;

            visitor->callback(&param);
		}
	}

	mdfx_remove_redundant_files(DFX_DUMPER_DIR);
}

static uint64_t mdfx_dump_is_need_dump_detail(struct mdfx_event *desc)
{
	return desc->desc.current_visitor_actions & DUMPER_NEED_DUMP_DETAIL;
}

static int mdfx_dump_event_act(struct mdfx_pri_data *mdfx_data, struct mdfx_event *event, void *value)
{
	struct mdfx_dumper_ctrl *dumper_ctrl = NULL;
	uint64_t detail = 0;

	if (IS_ERR_OR_NULL(mdfx_data) || IS_ERR_OR_NULL(event) || !in_task())
		return -1;

	if (!MDFX_HAS_CAPABILITY(g_mdfx_caps, MDFX_CAP_DUMPER))
		return 0;

	dumper_ctrl = (struct mdfx_dumper_ctrl *)mdfx_data->actors[ACTOR_DUMPER].actor_data;
	if (dumper_ctrl == NULL)
		return 0;

	detail = mdfx_dump_is_need_dump_detail(event);
	if (detail == 0)
		return 0;

	down(&dumper_ctrl->dump_sem);

	dumper_ctrl->desc.dump_infos = detail;
	dumper_ctrl->desc.id = event->visitor_id;
	dumper_ctrl->value = value;
	mdfx_dump_detail(dumper_ctrl, event->desc.event_name, event->timestamp);

	mdfx_pr_info("dump exit");
	up(&dumper_ctrl->dump_sem);
	return 0;
}

static int mdfx_dump_sysinfo(struct mdfx_pri_data *data, const void __user *argp)
{
	struct mdfx_dumper_ctrl *dumper_ctrl = NULL;
	char timestamp[MDFX_EVENT_TIMESTAMP_MAX] = {0};

	if ((data == NULL) || (argp == NULL))
		return -EINVAL;

	dumper_ctrl = (struct mdfx_dumper_ctrl *)data->actors[ACTOR_DUMPER].actor_data;
	if (dumper_ctrl == NULL)
		return -1;

	mdfx_get_file_name_timestamp(timestamp, MDFX_EVENT_TIMESTAMP_MAX);

	down(&dumper_ctrl->dump_sem);
	if (copy_from_user(&dumper_ctrl->desc, argp, sizeof(dumper_ctrl->desc))) {
		mdfx_pr_err("dumper copy from user fail");
		up(&dumper_ctrl->dump_sem);
		return -1;
	}

	if (dumper_ctrl->desc.dump_infos == 0) {
		up(&dumper_ctrl->dump_sem);
        return 0;
    }

	dumper_ctrl->value = NULL;

	mdfx_pr_info("triggle mdfx_dump_detail");
	mdfx_dump_detail(dumper_ctrl, "triggle_by_io", timestamp);

	(void)memset_s(dumper_ctrl, sizeof(*dumper_ctrl), 0, sizeof(*dumper_ctrl));
	up(&dumper_ctrl->dump_sem);
	return 0;
}

static struct mdfx_actor_ops_t dumper_ops = {
	.act = mdfx_dump_event_act,
	.do_ioctl = mdfx_dump_sysinfo,
};

void mdfx_dumper_init_actor(struct mdfx_actor_t *actor)
{
	struct mdfx_dumper_ctrl *dumper_ctrl = NULL;

	dumper_ctrl = kzalloc(sizeof(struct mdfx_dumper_ctrl), GFP_KERNEL);
	if (dumper_ctrl == NULL)
		return;

	sema_init(&dumper_ctrl->dump_sem, 1);

	actor->actor_type = ACTOR_DUMPER;
	actor->ops = &dumper_ops;
	actor->actor_data = dumper_ctrl;
}
