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

#ifdef CONFIG_TEE_LOG_EXCEPTION
#include <chipset_common/log/imonitor.h>
#define IMONITOR_TA_CRASH_EVENT_ID 901002003
#define IMONITOR_MEMSTAT_EVENT_ID 940007001
#define IMONITOR_TAMEMSTAT_EVENT_ID 940007002
#elif (defined CONFIG_TEE_LOG_EXCEPTION_SINGLE)
#include <dfx/hiview_hisysevent.h>
#endif

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
#if (defined CONFIG_TEE_LOG_EXCEPTION) || (defined CONFIG_TEE_LOG_EXCEPTION_SINGLE)
/* report 2 hours */
#define MEMSTAT_REPORT_FREQ (2 * 60 * 60 * 1000)
#define MAX_CRASH_INFO_LEN 100
#endif
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

#ifdef CONFIG_TEE_LOG_EXCEPTION
#define FAIL_RET (-1)
#define SUCC_RET 0

static int send_memstat_packet(const struct tee_mem *meminfo)
{
	struct imonitor_eventobj *memstat = NULL;
	uint32_t result = 0;
	struct time_spec nowtime;
	int ret;
	get_time_spec(&nowtime);

	memstat = imonitor_create_eventobj(IMONITOR_MEMSTAT_EVENT_ID);
	if (!memstat) {
		tloge("create eventobj failed\n");
		return FAIL_RET;
	}

	result |= (uint32_t)imonitor_set_param_integer_v2(memstat, "totalmem", meminfo->total_mem);
	result |= (uint32_t)imonitor_set_param_integer_v2(memstat, "mem", meminfo->pmem);
	result |= (uint32_t)imonitor_set_param_integer_v2(memstat, "freemem", meminfo->free_mem);
	result |= (uint32_t)imonitor_set_param_integer_v2(memstat, "freememmin", meminfo->free_mem_min);
	result |= (uint32_t)imonitor_set_param_integer_v2(memstat, "tanum", meminfo->ta_num);
	result |= (uint32_t)imonitor_set_time(memstat, nowtime.ts.tv_sec);
	if (result) {
		tloge("set param integer1 failed ret=%u\n", result);
		imonitor_destroy_eventobj(memstat);
		return FAIL_RET;
	}

	ret = imonitor_send_event(memstat);
	imonitor_destroy_eventobj(memstat);
	if (ret <= 0) {
		tloge("imonitor send memstat packet failed\n");
		return FAIL_RET;
	}

	return SUCC_RET;
}

static void report_imonitor(const struct tee_mem *meminfo)
{
	int ret;
	uint32_t result = 0;
	uint32_t i;
	struct imonitor_eventobj *pamemobj = NULL;
	struct time_spec nowtime;
	get_time_spec(&nowtime);

	if (!meminfo)
		return;

	if (meminfo->ta_num > MEMINFO_TA_MAX)
		return;

	if (send_memstat_packet(meminfo))
		return;

	for (i = 0; i < meminfo->ta_num; i++) {
		pamemobj =
			imonitor_create_eventobj(IMONITOR_TAMEMSTAT_EVENT_ID);
		if (!pamemobj) {
			tloge("create obj failed\n");
			break;
		}

		result |= (uint32_t)imonitor_set_param_string_v2(pamemobj,
			"NAME", meminfo->ta_mem_info[i].ta_name);
		result |= (uint32_t)imonitor_set_param_integer_v2(pamemobj,
			"MEM", meminfo->ta_mem_info[i].pmem);
		result |= (uint32_t)imonitor_set_param_integer_v2(pamemobj,
			"MEMMAX", meminfo->ta_mem_info[i].pmem_max);
		result |= (uint32_t)imonitor_set_param_integer_v2(pamemobj,
			"MEMLIMIT", meminfo->ta_mem_info[i].pmem_limit);
		result |= (uint32_t)imonitor_set_time(pamemobj,
			nowtime.ts.tv_sec);
		if (result) {
			tloge("set param integer2 failed ret=%d\n", result);
			imonitor_destroy_eventobj(pamemobj);
			return;
		}
		ret = imonitor_send_event(pamemobj);
		imonitor_destroy_eventobj(pamemobj);
		if (ret <= 0) {
			tloge("imonitor send pamem packet failed\n");
			break;
		}
	}
}

static void memstat_report(void)
{
	int ret;
	struct tee_mem *meminfo = NULL;

	meminfo = mailbox_alloc(sizeof(*meminfo), MB_FLAG_ZERO);
	if (!meminfo) {
		tloge("mailbox alloc failed\n");
		return;
	}

	ret = get_tee_meminfo(meminfo);
	if (ret == 0) {
		tlogd("report imonitor\n");
		report_imonitor(meminfo);
	} else {
		tlogd("get meminfo failed\n");
	}

	mailbox_free(meminfo);
}
#endif

void cmd_monitor_set_agent_status(int status)
{
#ifndef CONFIG_DISABLE_SHOW_AGENT_STATUS
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
#else
	(void)status;
#endif
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

#ifdef CONFIG_TEE_LOG_EXCEPTION
static struct time_spec g_memstat_check_time;
static bool g_after_loader = false;

static void auto_report_memstat(void)
{
	long long timedif;
	struct time_spec nowtime;
	get_time_spec(&nowtime);

	/*
	 * get time value D (timedif=nowtime-sendtime),
	 * we do not care about overflow
	 * 1 year means 1000 * (60*60*24*365) = 0x757B12C00
	 * only 5bytes, will not overflow
	 */
	timedif = S_TO_MS * (nowtime.ts.tv_sec - g_memstat_check_time.ts.tv_sec) +
		(nowtime.ts.tv_nsec - g_memstat_check_time.ts.tv_nsec) / S_TO_US;
	if (timedif > MEMSTAT_REPORT_FREQ && g_after_loader) {
		tlogi("cmdmonitor auto report memstat\n");
		memstat_report();
		g_memstat_check_time = nowtime;
	}

	if (!g_after_loader) {
		g_memstat_check_time = nowtime;
		g_after_loader = true;
	}
}
#endif

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
#ifdef CONFIG_TEE_LOG_EXCEPTION
	auto_report_memstat();
#endif
}

static void cmd_monitor_tickfn(struct work_struct *work)
{
	(void)(work);
	cmd_monitor_tick();
	/* check tlogcat if have new log */
	tz_log_write();
}

#ifdef CONFIG_TEE_LOG_EXCEPTION
int teeos_log_exception_archive(unsigned int eventid,
    const char *exceptioninfo)
{
	int ret;
	struct imonitor_eventobj *teeos_obj = NULL;
 
	teeos_obj = imonitor_create_eventobj(eventid);
	if (exceptioninfo) {
		tlogi("upload exception info: [%s]\n", exceptioninfo);
		ret = imonitor_set_param(teeos_obj, 0,
			(long)(uintptr_t)exceptioninfo);
	} else {
		ret = imonitor_set_param(teeos_obj, 0,
			(long)(uintptr_t)"teeos something crash");
	}
	if (ret) {
		tloge("imonitor_set_param failed\n");
		imonitor_destroy_eventobj(teeos_obj);
		return ret;
	}
	ret = imonitor_add_dynamic_path(teeos_obj,
		"/data/vendor/log/hisi_logs/tee");
	if (ret) {
		tloge("add path failed\n");
		imonitor_destroy_eventobj(teeos_obj);
		return ret;
	}
	ret = imonitor_add_dynamic_path(teeos_obj, "/data/log/tee");
	if (ret) {
		tloge("add path failed\n");
		imonitor_destroy_eventobj(teeos_obj);
		return ret;
	}
	ret = imonitor_send_event(teeos_obj);
	imonitor_destroy_eventobj(teeos_obj);
	return ret;
}
#endif
 
#ifdef CONFIG_TEE_LOG_EXCEPTION_SINGLE
void send_ta_abnormal_event(const char *event_reason, const char *uuid, const char *ta_version)
{
	if (event_reason == NULL || uuid == NULL || ta_version == NULL) {
		tloge("Bad TA_ABNORMAL event info!\n");
		return;
	}
	int ret;
	struct hiview_hisysevent *event = NULL;
 
	event = hisysevent_create("RELIABILITY", "TA_ABNORMAL", FAULT);
	if (!event) {
		tloge("[ta_abnormal]failed to create event");
		return;
	}
	ret = hisysevent_put_string(event, "REASON", event_reason);
	if (ret != 0) {
		tloge("[ta_abnormal]failed to put reason string to event, ret = %d", ret);
		goto exit;
	}
	ret = hisysevent_put_string(event, "UUID", uuid);
	if (ret != 0) {
		tloge("[ta_abnormal]failed to put uuid string to event, ret = %d", ret);
		goto exit;
	}
	ret = hisysevent_put_string(event, "VERSION", ta_version);
	if (ret != 0) {
		tloge("[ta_abnormal]failed to put version string to event, ret = %d", ret);
		goto exit;
	}
	ret = hisysevent_write(event);
	if (ret < 0)
		tloge("[ta_abnormal]failed to send event, ret = %d", ret);
	else
		tlogi("[ta_abnormal]send event successfully.");
exit:
	hisysevent_destroy(&event);
	return;
}
#endif

#if (defined CONFIG_TEE_LOG_EXCEPTION_SINGLE) || (defined CONFIG_TEE_LOG_EXCEPTION)
static void gen_ta_crash_report_info(const char *prefix_info, const char *ta_version, struct tc_uuid *ta_uuid)
{
	const char crash_info_get_failed[] = "ta crash: get uuid failed";
	const char ta_uuid_get_failed[] = "get uuid failed";
	char buffer[MAX_CRASH_INFO_LEN] = {0};
	char uuid_str[MAX_CRASH_INFO_LEN] = {0};
	const char *crash_info = buffer;
	int ret;
	int result = EOK;
	static struct tc_uuid ta_uuid_temp = {0};
	if (memcmp(&ta_uuid_temp, ta_uuid, sizeof(struct tc_uuid)) != 0) {
		ret = snprintf_s(uuid_str, sizeof(uuid_str), sizeof(uuid_str) - 1,
			"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
			ta_uuid->time_low, ta_uuid->time_mid, ta_uuid->timehi_and_version,
			ta_uuid->clockseq_and_node[0], ta_uuid->clockseq_and_node[1],
			ta_uuid->clockseq_and_node[2], ta_uuid->clockseq_and_node[3],
			ta_uuid->clockseq_and_node[4], ta_uuid->clockseq_and_node[5],
			ta_uuid->clockseq_and_node[6], ta_uuid->clockseq_and_node[7]);
		if (ret <= 0) {
			tlogw("append uuid info failed\n");
			result = memcpy_s(uuid_str, sizeof(uuid_str), ta_uuid_get_failed, sizeof(ta_uuid_get_failed));
		}
	} else {
		result = memcpy_s(uuid_str, sizeof(uuid_str), ta_uuid_get_failed, sizeof(ta_uuid_get_failed));
	}
#ifdef CONFIG_TEE_LOG_EXCEPTION_SINGLE
	ret = snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, "%s", uuid_str);
#elif (defined CONFIG_TEE_LOG_EXCEPTION)
	const char *ta_version_info = ta_version ? ta_version : "";
	ret = snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1,
		"%s %s: %s", prefix_info, ta_version_info, uuid_str);
#endif
	if (ret <= 0 || result != EOK) {
		tlogw("append crash info failed\n");
		crash_info = crash_info_get_failed;
	}
#ifdef CONFIG_TEE_LOG_EXCEPTION_SINGLE
	const char *ta_version_info = ta_version;
	const char no_need_ta_verison[] = "no need";
	if (ta_version == NULL) {
		ta_version_info = no_need_ta_verison;
	}
	send_ta_abnormal_event(prefix_info, crash_info, ta_version_info);
#elif (defined CONFIG_TEE_LOG_EXCEPTION)
	if (teeos_log_exception_archive(IMONITOR_TA_CRASH_EVENT_ID, crash_info) < 0)
		tloge("log exception archive failed\n");
#endif
}

static void report_ta_anti_rollback_info(uint32_t ta_ver, uint32_t ta_ver_in_rpmb, struct tc_uuid *ta_uuid)
{
	const char no_need_ta_verison[] = "get ta version failed";
	const char ta_anti_rollback[] = "ta load failed(version abnormal)";
	char buffer[MAX_CRASH_INFO_LEN] = {0};
	const char *ta_verison = buffer;
	int ret;
	if (ta_ver_in_rpmb == 0) {
		ret = snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, "ta_verison:%u, rpmb_verison:%s",
			ta_ver, "get ta verison in rpmb failed");
	} else {
		ret = snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1, "ta_verison:%u, rpmb_verison:%u",
			ta_ver, ta_ver_in_rpmb);
	}
	if (ret <= 0) {
		tlogw("append crash info failed\n");
		ta_verison = no_need_ta_verison;
	}
	gen_ta_crash_report_info(ta_anti_rollback, ta_verison, ta_uuid);
}
#endif

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
#if (defined CONFIG_TEE_LOG_EXCEPTION_SINGLE) || (defined CONFIG_TEE_LOG_EXCEPTION)
	} else if (fault_type == TYPE_CRASH_TA) {
		const char crash_prefix[] = "ta crash";
		gen_ta_crash_report_info(crash_prefix, NULL, &ta_uuid);
	} else if (fault_type == TYPE_KILLED_TA) {
		const char killed_prefix[] = "ta timeout and killed";
		gen_ta_crash_report_info(killed_prefix, NULL, &ta_uuid);
	} else if (fault_type == TYPE_TA_LOAD_FAIL_COMMON) {
		const char ta_load_failed[] = "ta load failed";
		gen_ta_crash_report_info(ta_load_failed, NULL, &ta_uuid);
	} else if (fault_type == TYPE_TA_LOAD_FAIL_FOR_RPMB_ERROR) {
		const char ta_load_failed[] = "ta load failed(rpmb operate failed)";
		gen_ta_crash_report_info(ta_load_failed, NULL, &ta_uuid);
	} else if (fault_type == TYPE_TA_ANTI_ROLLBACK) {
		report_ta_anti_rollback_info(ta_ver, ta_ver_in_rpmb, &ta_uuid);
	} else if (fault_type == TYPE_INVALID_TA_FORMAT) {
		const char ta_load_failed[] = "ta load failed(invaid ta format)";
		gen_ta_crash_report_info(ta_load_failed, NULL, &ta_uuid);
#endif
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
#ifdef CONFIG_TEE_TELEPORT_SUPPORT
	if (cmd->cmd_id == GLOBAL_CMD_ID_PORTAL_WORK)
		return NULL;
#endif

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
#ifndef CONFIG_BIG_SESSION
			if (g_cmd_monitor_list_size > MAX_CMD_MONITOR_LIST - 1) {
				tloge("monitor reach max node num\n");
				monitor = NULL;
				break;
			}
#endif
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
#ifdef CONFIG_CONFIDENTIAL_TEE
#define INSMOD_THREAD "insmod"
#define TEECD_THREAD "teecd"
bool check_running_ca(void)
{
	struct cmd_monitor *monitor = NULL;
	bool has_running_ca = false;
    mutex_lock(&g_cmd_monitor_lock);
	list_for_each_entry(monitor, &g_cmd_monitor_list, list) {
		char pname[TASK_COMM_LEN] = {0};
		if (get_pid_name(monitor->pid, pname, sizeof(pname)) != 0) {
			continue;
		}
		if (strncmp(pname, INSMOD_THREAD, sizeof(INSMOD_THREAD)) != 0 &&
			strncmp(pname, TEECD_THREAD, sizeof(TEECD_THREAD)) != 0) {
			tloge("detect running thread task:%s, please stop\n", pname);
			has_running_ca = true;
		}
	}
	mutex_unlock(&g_cmd_monitor_lock);
	return has_running_ca;
}
#endif
