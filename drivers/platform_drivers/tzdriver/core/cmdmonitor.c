/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: cmdmonitor function, monitor every cmd which is sent to TEE.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "cmdmonitor.h"
#include <linux/workqueue.h>
#include <linux/kthread.h>
#include <linux/list.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/timer.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <securec.h>


#include "smc_smp.h"
#include "internal_functions.h"
#include "mailbox_mempool.h"
#include "tlogger.h"
#include "agent.h"
#include "log_cfg_api.h"
#include "tui.h"
#include "tzdebug.h"
#include "tee_compat_check.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "tc_workqueue.h"

static int g_cmd_need_archivelog;
static LIST_HEAD(g_cmd_monitor_list);
static int g_cmd_monitor_list_size;
#define MAX_CMD_MONITOR_LIST 200
#define MAX_AGENT_CALL_COUNT 5000
static DEFINE_MUTEX(g_cmd_monitor_lock);

/* independent wq to avoid block system_wq */
static struct workqueue_struct *g_cmd_monitor_wq;
static struct delayed_work g_cmd_monitor_work;
static struct delayed_work g_cmd_monitor_work_archive;

void get_time_spec(struct time_spec *time)
{
	if (!time)
		return;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0))
	time->ts = current_kernel_time();
#else
	ktime_get_coarse_ts64(&time->ts);
#endif
}

static void schedule_cmd_monitor_work(struct delayed_work *work,
	unsigned long delay)
{
	if (g_cmd_monitor_wq)
		queue_delayed_work(g_cmd_monitor_wq, work, delay);
	else
		schedule_delayed_work(work, delay);
}

static void tz_archivelog(void)
{
	schedule_cmd_monitor_work(&g_cmd_monitor_work_archive, usecs_to_jiffies(0));
	flush_delayed_work(&g_cmd_monitor_work_archive);
}

static LIST_HEAD(g_ta_crash_info);
static DEFINE_MUTEX(g_ta_crash_info_lock);
 
struct fault_info {
	int32_t fault_type;
	uint32_t ta_ver;
	uint32_t ta_ver_in_rpmb;
	struct tc_uuid ta_uuid;
	struct list_head list;
};
 
static int pop_fault_crash_info(int32_t *type, struct tc_uuid *ta_uuid, uint32_t *ta_ver,
	uint32_t *ta_ver_in_rpmb)
{
    struct fault_info *crash_info;
    int ret = EFAULT;
 
    mutex_lock(&g_ta_crash_info_lock);
    if (!list_empty(&g_ta_crash_info)) {
        crash_info = list_first_entry(&g_ta_crash_info, struct fault_info, list);
        *type = crash_info->fault_type;
        *ta_ver = crash_info->ta_ver;
        *ta_ver_in_rpmb = crash_info->ta_ver_in_rpmb;
		if (memcpy_s(ta_uuid, sizeof(struct tc_uuid), &(crash_info->ta_uuid), sizeof(struct tc_uuid)) != EOK) {
			tloge("copy uuid failed from crash info list\n");
			mutex_unlock(&g_ta_crash_info_lock);
			return ret;
		} else {
			list_del(&crash_info->list);
			kfree(crash_info);
			ret = 0;
		}
    }
    mutex_unlock(&g_ta_crash_info_lock);
	tlogi("there is no ta crash info\n");
    return ret;
}
 
static void push_fault_crash_info(int32_t type, const uint8_t *ta_uuid, uint32_t uuid_len, uint32_t ta_ver,
	uint32_t ta_ver_in_rpmb)
{
	struct fault_info *new_info = NULL;
	new_info = kzalloc(sizeof(*new_info), GFP_KERNEL | __GFP_ZERO);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)new_info)) {
		tloge("[push_fault_crash_info]kzalloc failed\n");
		return;
	}
 
    new_info->fault_type = type;
	new_info->ta_ver = ta_ver;
	new_info->ta_ver_in_rpmb = ta_ver_in_rpmb;
	if (type != TYPE_CRASH_TEE &&
		ta_uuid != NULL && uuid_len == sizeof(struct tc_uuid)) {
		if (memcpy_s(&(new_info->ta_uuid), sizeof(new_info->ta_uuid), ta_uuid, uuid_len) != EOK)
			tloge("copy uuid failed when get ta crash info\n");
	}
    INIT_LIST_HEAD(&new_info->list);
    mutex_lock(&g_ta_crash_info_lock);
    list_add_tail(&new_info->list, &g_ta_crash_info);
    mutex_unlock(&g_ta_crash_info_lock);
}

void cmd_monitor_fault_crash(int32_t type, const uint8_t *ta_uuid, uint32_t uuid_len)
{
	push_fault_crash_info(type, ta_uuid, uuid_len, 0, 0);
	tz_archivelog();
	fault_monitor_start(type, ta_uuid);
	kbox_report(type, ta_uuid, uuid_len);
}
 
void cmd_monitor_ta_load_failed(int32_t type, struct tc_uuid *ta_uuid, uint32_t uuid_len, uint32_t ta_ver,
	uint32_t ta_ver_in_rpmb)
{
	if (type == TYPE_TA_ANTI_ROLLBACK)
		push_fault_crash_info(type, (const uint8_t *)ta_uuid, uuid_len, ta_ver, ta_ver_in_rpmb);
	else
		push_fault_crash_info(type, (const uint8_t *)ta_uuid, uuid_len, 0, 0);
	tz_archivelog();
}

bool is_thread_reported(pid_t tid)
{
	bool ret = false;
	struct cmd_monitor *monitor = NULL;

	mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry(monitor, &g_cmd_monitor_list, list) {
		if (monitor->tid == tid && !is_tui_in_use(monitor->tid)) {
			ret = (monitor->is_reported || monitor->agent_call_count > MAX_AGENT_CALL_COUNT);
			break;
		}
	}
	mutex_unlock(&g_cmd_monitor_lock);
	/* sometimes g_cmd_monitor_work will be scheduled after a long time,
	 * which cause kill command execute failed. So we flushed work here to
	 * ensure this work can be scheduled.
	 */
	flush_delayed_work(&g_cmd_monitor_work);
	return ret;
}


void cmd_monitor_set_agent_status(int status)
{
	struct cmd_monitor *monitor = NULL;
	pid_t pid = CURRENT_TGID;
	pid_t tid = CURRENT_PID;

	mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry(monitor, &g_cmd_monitor_list, list) {
		if (monitor->pid == pid && monitor->tid == tid) {
			monitor->agent_status = status;
			break;
		}
	}
	mutex_unlock(&g_cmd_monitor_lock);
}

void cmd_monitor_reset_context(void)
{
	struct cmd_monitor *monitor = NULL;
	pid_t pid = CURRENT_TGID;
	pid_t tid = CURRENT_PID;

	mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry(monitor, &g_cmd_monitor_list, list) {
		if (monitor->pid == pid && monitor->tid == tid) {
			get_time_spec(&monitor->sendtime);
			monitor->kernel_start_time = get_current_struct_stime();
			if (monitor->agent_call_count + 1 < 0)
				tloge("agent call count add overflow\n");
			else
				monitor->agent_call_count++;
			break;
		}
	}
	mutex_unlock(&g_cmd_monitor_lock);
}


/*
 * if one session timeout, monitor will print timedifs every step[n] in seconds,
 * if lasted more then 360s, monitor will print timedifs every 360s.
 */
const int32_t g_timer_step[] = {1, 1, 1, 2, 5, 10, 40, 120, 180, 360};
const int32_t g_timer_nums = sizeof(g_timer_step) / sizeof(int32_t);
static u64 get_kernel_end_time(struct cmd_monitor *monitor)
{
	u64 end_time = 0U;
	if (!(monitor->returned)) {
		if (!get_struct_stime_by_tid(monitor->tid, &end_time)) {
			end_time = monitor->kernel_start_time;
			tloge("cannot find current task_struct by tid %d\n", monitor->tid);
		}
	} else {
		end_time = monitor->kernel_end_time;
	}
 
	return end_time;
}

static void show_timeout_cmd_info(struct cmd_monitor *monitor, bool *has_print)
{
	long long timedif, timedif2;
	u64 end_time, running_time;
	struct time_spec nowtime;
	int32_t time_in_sec;
	get_time_spec(&nowtime);

	end_time = get_kernel_end_time(monitor);
 
	running_time = 0U;
	if (end_time > monitor->kernel_start_time)
		running_time = end_time - monitor->kernel_start_time;

	/*
	 * 1 year means 1000 * (60*60*24*365) = 0x757B12C00
	 * only 5bytes, so timedif (timedif=nowtime-sendtime) will not overflow
	 */
	timedif = S_TO_MS * (nowtime.ts.tv_sec - monitor->sendtime.ts.tv_sec) +
		(nowtime.ts.tv_nsec - monitor->sendtime.ts.tv_nsec) / S_TO_US;

	/* timeout to 10s, we log the teeos log, and report */
	if ((timedif > CMD_MAX_EXECUTE_TIME * S_TO_MS) && (!monitor->is_reported)) {
		monitor->is_reported = true;
		/*
		 * timedif: time since the new smc cmd is sent
		 * kernel_run_time: duration when the new smc_cmd working thread is running in kernel mode
		 */
		tlogw("[cmd_monitor_tick] pid=%d,pname=%s,tid=%d,"
			"tname=%s,lastcmdtype=%u,lastcmdid=%u,agent call count:%d,agent status:%d,"
			"running with timedif=%lld ms, kernel_run_time=%llu ns and report\n",
			monitor->pid, monitor->pname, monitor->tid,
			monitor->tname, monitor->lastcmdtype, monitor->lastcmdid,
			monitor->agent_call_count, monitor->agent_status,
			timedif, running_time);
		/* threads out of white table need info dump */
		tlogw("monitor: pid-%d\n", monitor->pid);
		if (*has_print == false) {
			show_agent_event_status();
			if (!is_tui_in_use(monitor->tid)) {
				show_cmd_bitmap();
				g_cmd_need_archivelog = 1;
				wakeup_tc_siq(SIQ_DUMP_TIMEOUT);
			}
			*has_print = true;
		}
	}

	timedif2 = S_TO_MS * (nowtime.ts.tv_sec - monitor->lasttime.ts.tv_sec) +
		(nowtime.ts.tv_nsec - monitor->lasttime.ts.tv_nsec) / S_TO_US;
	time_in_sec = monitor->timer_index >= g_timer_nums ?
		g_timer_step[g_timer_nums - 1] : g_timer_step[monitor->timer_index];
	if (timedif2 > time_in_sec * S_TO_MS) {
		monitor->lasttime = nowtime;
		monitor->timer_index = monitor->timer_index >= (int32_t)sizeof(g_timer_step) ?
			(int32_t)sizeof(g_timer_step) : (monitor->timer_index + 1);
		tlogw("[cmd_monitor_tick] pid=%d,pname=%s,tid=%d, tname=%s, "
			"lastcmdtype=%u,lastcmdid=%u,agent call count:%d, "
			"agent status:%d,timedif=%lld ms, kernel_run_time=%llu ns\n",
			monitor->pid, monitor->pname, monitor->tid, monitor->tname,
			monitor->lastcmdtype, monitor->lastcmdid, monitor->agent_call_count,
			monitor->agent_status, timedif, running_time);
	}
}

static void cmd_monitor_tick(void)
{
	struct cmd_monitor *monitor = NULL;
	struct cmd_monitor *tmp = NULL;
	/* we use has_print here to avoid printing cmd info and agent status repeatly */
	bool has_print = false;

	mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry_safe(monitor, tmp, &g_cmd_monitor_list, list) {
		if (monitor->returned) {
			g_cmd_monitor_list_size--;
			tlogd("[cmd_monitor_tick] pid=%d,pname=%s,tid=%d, "
				"tname=%s,lastcmdtype=%u,lastcmdid=%u,count=%d,agent call count=%d, "
				"timetotal=%lld us returned, remained command(s)=%d\n",
				monitor->pid, monitor->pname, monitor->tid, monitor->tname,
				monitor->lastcmdtype, monitor->lastcmdid, monitor->count,
				monitor->agent_call_count, monitor->timetotal, g_cmd_monitor_list_size);
			list_del(&monitor->list);
			kfree(monitor);
			continue;
		}
		show_timeout_cmd_info(monitor, &has_print);
	}

	/* if have cmd in monitor list, we need tick */
	if (g_cmd_monitor_list_size > 0)
		schedule_cmd_monitor_work(&g_cmd_monitor_work, usecs_to_jiffies(S_TO_US));
	mutex_unlock(&g_cmd_monitor_lock);
}

static void cmd_monitor_tickfn(struct work_struct *work)
{
	(void)(work);
	cmd_monitor_tick();
	/* check tlogcat if have new log */
	tz_log_write();
}

 


static void cmd_monitor_archivefn(struct work_struct *work)
{
	int32_t fault_type = 0;
	int32_t ret = 0;
	uint32_t ta_ver = 0;
	uint32_t ta_ver_in_rpmb = 0;
	struct tc_uuid ta_uuid = {0};
	(void)(work);
	if (tlogger_store_msg(CONFIG_TEE_LOG_ACHIVE_PATH,
		sizeof(CONFIG_TEE_LOG_ACHIVE_PATH)) < 0)
		tloge("[cmd_monitor_tick]tlogger store lastmsg failed\n");

	ret = pop_fault_crash_info(&fault_type, &ta_uuid, &ta_ver, &ta_ver_in_rpmb);
	if (ret != 0) {
		return;
	}
	if (fault_type == TYPE_CRASH_TEE) {
		tloge("detect teeos crash, panic\n");
		report_log_system_panic();
	}
}

static void init_cmd_monitor_value(struct cmd_monitor *monitor, const struct tc_ns_smc_cmd *cmd)
{
	get_time_spec(&monitor->sendtime);
	monitor->lasttime = monitor->sendtime;
	monitor->timer_index = 0;
	monitor->returned = false;
	monitor->is_reported = false;
	monitor->agent_call_count = 0;
	monitor->timetotal = 0;
	monitor->count++;
	monitor->lastcmdtype = cmd->cmd_type;
	monitor->lastcmdid = cmd->cmd_id;
	monitor->kernel_start_time = get_current_struct_stime();
	monitor->kernel_end_time = monitor->kernel_start_time;
}

static struct cmd_monitor *init_monitor_locked(const struct tc_ns_smc_cmd *cmd)
{
	struct cmd_monitor *newitem = NULL;

	newitem = kzalloc(sizeof(*newitem), GFP_KERNEL);
	if (ZERO_OR_NULL_PTR((unsigned long)(uintptr_t)newitem)) {
		tloge("[cmd_monitor_tick]kzalloc failed\n");
		return NULL;
	}

    newitem->count = 0;
	init_cmd_monitor_value(newitem, cmd);
	newitem->agent_status = 0;
	newitem->pid = CURRENT_TGID;
	newitem->tid = CURRENT_PID;
	if (get_pid_name(newitem->pid, newitem->pname,
		sizeof(newitem->pname)) != 0)
		newitem->pname[0] = '\0';
	if (get_pid_name(newitem->tid, newitem->tname,
		sizeof(newitem->tname)) != 0)
		newitem->tname[0] = '\0';
	INIT_LIST_HEAD(&newitem->list);
	list_add_tail(&newitem->list, &g_cmd_monitor_list);
	g_cmd_monitor_list_size++;
	return newitem;
}

struct cmd_monitor *cmd_monitor_log(const struct tc_ns_smc_cmd *cmd)
{
	bool found_flag = false;
	pid_t pid = CURRENT_TGID;
	pid_t tid = CURRENT_PID;
	struct cmd_monitor *monitor = NULL;

	if (!cmd)
		return NULL;

	/* It is normal for portal applications to be stuck for a long time.
	 * We do not need to add then to monitor list for checking. For example, if it starts a server,
	 * it will wait for a long time until the client connects. */

	mutex_lock(&g_cmd_monitor_lock);
	do {
		list_for_each_entry(monitor, &g_cmd_monitor_list, list) {
			if (monitor->pid == pid && monitor->tid == tid) {
				found_flag = true;
				/* restart */
				init_cmd_monitor_value(monitor, cmd);
				break;
			}
		}

		if (!found_flag) {
			if (g_cmd_monitor_list_size > MAX_CMD_MONITOR_LIST - 1) {
				tloge("monitor reach max node num\n");
				monitor = NULL;
				break;
			}
			monitor = init_monitor_locked(cmd);
			if (!monitor) {
				tloge("init monitor failed\n");
				break;
			}
			/* the first cmd will cause timer */
			if (g_cmd_monitor_list_size == 1)
				schedule_cmd_monitor_work(&g_cmd_monitor_work, usecs_to_jiffies(S_TO_US));
		}
	} while (0);
	mutex_unlock(&g_cmd_monitor_lock);

	return monitor;
}

void cmd_monitor_logend(struct cmd_monitor *item)
{
	struct time_spec nowtime;
	long long timedif;

	if (!item)
		return;

	get_time_spec(&nowtime);
	/*
	 * get time value D (timedif=nowtime-sendtime),
	 * we do not care about overflow
	 * 1 year means 1000000 * (60*60*24*365) = 0x1CAE8C13E000
	 * only 6bytes, will not overflow
	 */
	timedif = S_TO_US * (nowtime.ts.tv_sec - item->sendtime.ts.tv_sec) +
		(nowtime.ts.tv_nsec - item->sendtime.ts.tv_nsec) / S_TO_MS;
	item->timetotal += timedif;
	item->kernel_end_time = get_current_struct_stime();
	item->returned = true;
}

void do_cmd_need_archivelog(void)
{
	if (g_cmd_need_archivelog == 1) {
		g_cmd_need_archivelog = 0;
		schedule_cmd_monitor_work(&g_cmd_monitor_work_archive,
			usecs_to_jiffies(S_TO_US));
	}
}

void init_cmd_monitor(void)
{
	g_cmd_monitor_wq = alloc_workqueue("tz-monitor",
		WQ_UNBOUND, TZ_WQ_MAX_ACTIVE);
	if (!g_cmd_monitor_wq)
		tloge("alloc cmd monitor wq failed\n");
	else
		tz_workqueue_bind_mask(g_cmd_monitor_wq, 0);

	INIT_DEFERRABLE_WORK((struct delayed_work *)
		(uintptr_t)&g_cmd_monitor_work, cmd_monitor_tickfn);
	INIT_DEFERRABLE_WORK((struct delayed_work *)
		(uintptr_t)&g_cmd_monitor_work_archive, cmd_monitor_archivefn);
}

void free_cmd_monitor_list(void)
{
	struct cmd_monitor *monitor = NULL;
	struct cmd_monitor *tmp = NULL;

	mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry_safe(monitor, tmp, &g_cmd_monitor_list, list) {
		list_del(&monitor->list);
		kfree(monitor);
	}
	g_cmd_monitor_list_size = 0;
	mutex_unlock(&g_cmd_monitor_lock);
}

void free_cmd_monitor(void)
{
	free_cmd_monitor_list();
	cancel_delayed_work(&g_cmd_monitor_work);
	cancel_delayed_work(&g_cmd_monitor_work_archive);
	if (g_cmd_monitor_wq) {
		flush_workqueue(g_cmd_monitor_wq);
		destroy_workqueue(g_cmd_monitor_wq);
		g_cmd_monitor_wq = NULL;
	}
}
