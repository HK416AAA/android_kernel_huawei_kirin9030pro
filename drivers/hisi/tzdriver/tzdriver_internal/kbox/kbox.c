/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2023. All rights reserved.
 * Description: For bbox log cfg api define
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
#include <securec.h>
#include <linux/sched/clock.h>
#include <drv_oper.h>

#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "cmdmonitor.h"

#define NS_TO_SEC           1000000000
#define NS_TO_USEC          1000
#define MAX_CRASH_INFO_LEN  100
#define MAX_BUF             256

static void kbox_print(int fd, const char *fmt, ...)
{
	va_list args;
	int32_t len;
	int32_t ret;
	int8_t buff[MAX_BUF] = { 0 };

	if (fmt == NULL)
		return;

	va_start(args, fmt);
	len = vsnprintf_s(buff, MAX_BUF, MAX_BUF - 1, fmt, args);
	va_end(args);

	if (len <= 0) {
		tloge("vsnprintf failed\n");
		return;
	}
	ret = kbox_log_write(fd, buff, (uint32_t)len);
	if (ret < 0)
		tloge("store kbox log fail. ret=%d\n", ret);
}


static void show_system_crash(void)
{
	uint64_t cur_time = (uint64_t)local_clock();
	uint64_t sec = cur_time / NS_TO_SEC;
	uint64_t usec = cur_time % NS_TO_SEC / NS_TO_USEC;

	int fd = kbox_log_open(cur_time);
	if (fd < 0) {
		tloge("kbox open failed, fd is %d\n", fd);
		return;
	}

	kbox_print(fd, "[ %llu.%llu] [tzdriver] %s\n", sec, usec, "tee system crash");
	kbox_log_close(fd);
}

static void show_ta_crash(int32_t crash_type, const struct tc_uuid *uuid)
{
	uint64_t cur_time = (uint64_t)local_clock();
	uint64_t sec = cur_time / NS_TO_SEC;
	uint64_t usec = cur_time % NS_TO_SEC / NS_TO_USEC;

	int fd = kbox_log_open(cur_time);
	if (fd < 0) {
		tloge("kbox open failed, fd is %d\n", fd);
		return;
	}

	const char crash_prefix[] = "ta crash: ";
	const char killed_prefix[] = "ta timeout and killed: ";
	const char crash_info_get_failed[] = "ta crash: get uuid failed";
	char buffer[MAX_CRASH_INFO_LEN] = {0};
	const char *crash_info = buffer;
	int ret = snprintf_s(buffer, sizeof(buffer), sizeof(buffer) - 1,
		"%s%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		(crash_type == TYPE_CRASH_TA) ? crash_prefix : killed_prefix,
		uuid->time_low, uuid->time_mid,
		uuid->timehi_and_version,
		uuid->clockseq_and_node[0], uuid->clockseq_and_node[1],
		uuid->clockseq_and_node[2], uuid->clockseq_and_node[3],
		uuid->clockseq_and_node[4], uuid->clockseq_and_node[5],
		uuid->clockseq_and_node[6], uuid->clockseq_and_node[7]);
	if (ret <= 0) {
		tlogw("append crash info failed\n");
		crash_info = crash_info_get_failed;
	}

	kbox_print(fd, "[ %llu.%llu] [tzdriver] %s\n", sec, usec, crash_info);
	kbox_log_close(fd);
}

void kbox_report(int32_t type, const uint8_t *ta_uuid, uint32_t uuid_len)
{
	struct tc_uuid crash_uuid = { 0 };
	if (type == TYPE_CRASH_TEE) {
		show_system_crash();
		return;
	}
	/* TA crash */
	if (ta_uuid == NULL) {
		tloge("invalid uuid\n");
		return;
	}

	(void)memcpy_s(&crash_uuid, sizeof(struct tc_uuid), ta_uuid, uuid_len);
	show_ta_crash(type, &crash_uuid);
}
