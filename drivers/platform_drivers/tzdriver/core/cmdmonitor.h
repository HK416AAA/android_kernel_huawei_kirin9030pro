/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: cmdmonitor function declaration
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
#ifndef CMD_MONITOR_H
#define CMD_MONITOR_H

#include "tzdebug.h"
#include <linux/version.h>
#include "teek_ns_client.h"
#include "smc_smp.h"

#if (KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE)
#define TASK_COMM_LEN 16
#endif

#define TEEC_ERROR_TA_ANTI_ROLLBACK 0xFFFF920D
#define TEEC_ERROR_RPMB_WRITE_FAIL 0xFFFF7005
#define TEEC_ERROR_RPMB_READ_FAIL 0xFFFF7006
#define TEEC_ERROR_INVALID_TA_FORMAT 0xFFFF9118

enum {
	TYPE_CRASH_TEE = 1,
	TYPE_CRASH_TA = 2,
	TYPE_KILLED_TA = 3,
	TYPE_TA_LOAD_FAIL_COMMON = 4,
	TYPE_TA_LOAD_FAIL_FOR_RPMB_ERROR = 5,
	TYPE_TA_ANTI_ROLLBACK = 6,
	TYPE_INVALID_TA_FORMAT = 7,
};

/*
 * when cmd execute more than 25s in tee,
 * it will be terminated when CA is killed
 */
#define CMD_MAX_EXECUTE_TIME 10U
#define S_TO_MS 1000
#define S_TO_US 1000000

struct time_spec {
#if (LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0))
	struct timespec ts;
#else
	struct timespec64 ts;
#endif
};

enum {
	AGENT_RECV_TEE_CMD = 1,
	AGENT_WAKEUP_REE_THREAD = 2,
	AGENT_REE_THREAD_WORK_DONE = 3,
	AGENT_RET_TO_TEE = 4,
};

struct cmd_monitor {
	struct list_head list;
	struct time_spec sendtime;
	struct time_spec lasttime;
	int32_t timer_index;
	int count;
	bool returned;
	bool is_reported;
	pid_t pid;
	pid_t tid;
	char pname[TASK_COMM_LEN];
	char tname[TASK_COMM_LEN];
	unsigned int lastcmdid;
	unsigned int lastcmdtype;
	long long timetotal;
	int agent_call_count;
	int agent_status;
	u64 kernel_start_time; /* start stime of this thread running in kernel mode */
	u64 kernel_end_time; /* end stime of this thread running in kernel mode */
};

struct cmd_monitor *cmd_monitor_log(const struct tc_ns_smc_cmd *cmd);
void cmd_monitor_reset_context(void);
void cmd_monitor_set_agent_status(int status);
void cmd_monitor_logend(struct cmd_monitor *item);
void init_cmd_monitor(void);
void free_cmd_monitor_list(void);
void free_cmd_monitor(void);
void do_cmd_need_archivelog(void);
bool is_thread_reported(pid_t tid);
void cmd_monitor_fault_crash(int32_t type, const uint8_t *ta_uuid, uint32_t uuid_len);
void cmd_monitor_ta_load_failed(int32_t type, struct tc_uuid *ta_uuid, uint32_t uuid_len, uint32_t ta_ver,
	uint32_t ta_ver_in_rpmb);
void get_time_spec(struct time_spec *time);
#ifdef CONFIG_CONFIDENTIAL_TEE
bool check_running_ca(void);
#endif
#endif
