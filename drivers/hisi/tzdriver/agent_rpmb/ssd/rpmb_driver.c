/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: function for rpmb
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
#include "rpmb_driver.h"
#include <linux/kallsyms.h>
#include <linux/fs.h>
#include <linux/namei.h>
#include <linux/mm.h>
#include <linux/kernel.h>
#include <securec.h>
#include "agent_rpmb/core/agent_rpmb.h"
#include "teek_client_constants.h"
#include "tc_ns_log.h"
#include "tc_current_info.h"

/* For qemu VRPMB_PATH is "/vendor/bin/vrpmb.txt", we create vrpmb.txt manually
 * For SSD VRPMB_PATH is "/dev/block/by-name/secure_tee", hisi create this partition
*/
#define VRPMB_PATH ("/dev/block/by-name/secure_tee")
#define MAX_VRPMB_SHARED_MEM (30 * 1024)
#define MAX_SSD_SIZE (0Xc00000)

typedef struct {
	char send_magic[4]; /* magic[0] = 'r', magic[1] = 'p', magic[2] = 'm', magic[3] = 'b' */
	uint32_t rpmb_cmd; /* make it compatible to rpmb_driver.c */
	uint32_t ssd_cmd;   /* SSD_CMD_READ = 1、SSD_CMD_WRITE = 2 */
	uint32_t addr; /* read or write addr */
	uint32_t len;  /* read or write data length, MAX len is 30k,
					* if TA read len more than 30k, should do multi operation */
	int32_t reserve0;
	int32_t ree_result;
	int32_t reserve1;
	uint8_t reserve[96];  /* make vrpmb_info 128 bytes align */
} vrpmb_info_head_t;

/* New CMD for ssd read and write. */
typedef enum {
	SSD_CMD_NONE,
	SSD_CMD_READ,
	SSD_CMD_WRITE,
	SSD_CMD_INVALID,
} ssd_cmd_t;

static uint64_t dfx_get_time_ns(void)
{
#ifndef CONFIG_QEMU_SSD_VRPMB
	return dfx_getcurtime();
#else
	return 0;
#endif
}

static int write_data(loff_t offset, uint8_t *data, uint32_t datalen)
{
	int ret;
	struct file *fp = NULL;
	uint64_t time_start, time_end, time_cost;

	if (data == NULL)
		return TEEC_ERROR_BAD_PARAMETERS;

	fp = filp_open(VRPMB_PATH, O_RDWR | O_SYNC, 0);
	if (fp == NULL) {
		tloge("wr open vrpmb failed\n");
		return -1;
	}

	time_start = dfx_get_time_ns();
	ret = kernel_write(fp, data, datalen, &offset);
	time_end = dfx_get_time_ns();

	time_cost = (time_end - time_start) / NANOS_PER_MILLISECOND;
	if (time_cost > IOCTL_TIMEOUT_MILLISECOND) {
		tlogw("write_data: kernel_write cost %llu ms!!\n", time_cost);
	}

	filp_close(fp, 0);
	if (ret != datalen)
		return -EIO;

	return 0;
}

static int read_data(loff_t offset, uint8_t *data, uint32_t datalen)
{
	int ret;
	struct file *fp = NULL;
	uint64_t time_start, time_end, time_cost;

	if (data == NULL)
		return TEEC_ERROR_BAD_PARAMETERS;

	fp = filp_open(VRPMB_PATH, O_RDONLY, 0);
	if (fp == NULL) {
		tloge("rd open vrpmb failed\n");
		return -1;
	}

	time_start = dfx_get_time_ns();
	ret = kernel_read(fp, data, datalen, &offset);
	time_end = dfx_get_time_ns();

	time_cost = (time_end - time_start) / NANOS_PER_MILLISECOND;
	if (time_cost > IOCTL_TIMEOUT_MILLISECOND) {
		tlogw("read_data: kernel_read cost %llu ms!!\n", time_cost);
	}

	filp_close(fp, 0);
	if (ret != datalen)
		return -EIO;

	return 0;
}

static int vrpmb_check_head(vrpmb_info_head_t vrpmb_ctrl)
{
	char magic[] = "rpmb";
	if (memcmp(magic, vrpmb_ctrl.send_magic, strlen(magic)) != 0) {
		tloge("check rpmb magic failed, maybe cache failed\n");
		return TEEC_ERROR_VRPMB_AGENT_FAIL;
	}

	if (vrpmb_ctrl.len > MAX_VRPMB_SHARED_MEM || vrpmb_ctrl.len == 0) {
		tloge("invalid transfer len=%d\n", vrpmb_ctrl.len);
		return TEEC_ERROR_BAD_PARAMETERS;
	}

	if (vrpmb_ctrl.len + vrpmb_ctrl.addr >= MAX_SSD_SIZE) {
		tloge("invalid transfer len=%d, addr:%x\n", vrpmb_ctrl.len, vrpmb_ctrl.addr);
		return TEEC_ERROR_BAD_PARAMETERS;
	}

	return TEEC_SUCCESS;
}

int vrpmb_ioctl_cmd(uint8_t *share_buf, uint32_t buf_size)
{
	vrpmb_info_head_t vrpmb_ctrl;
	uint8_t *rw_data = NULL;
	int ret = 0;

	if (share_buf == NULL || buf_size < MAX_VRPMB_SHARED_MEM + sizeof(vrpmb_info_head_t))
		return TEEC_ERROR_BAD_PARAMETERS;

	(void)memset_s(&vrpmb_ctrl, sizeof(vrpmb_info_head_t), 0, sizeof(vrpmb_info_head_t));
	rw_data = share_buf + sizeof(vrpmb_info_head_t);

	(void)memcpy_s(&vrpmb_ctrl, sizeof(vrpmb_info_head_t), share_buf, sizeof(vrpmb_info_head_t));

	ret = vrpmb_check_head(vrpmb_ctrl);
	if (ret)
		goto clean;

	switch (vrpmb_ctrl.ssd_cmd) {
	case SSD_CMD_READ:
		ret = read_data(vrpmb_ctrl.addr, rw_data, vrpmb_ctrl.len);
		break;
	case SSD_CMD_WRITE:
		ret = write_data(vrpmb_ctrl.addr, rw_data, vrpmb_ctrl.len);
		break;
    default:
		tloge("invalid cmd=%d from tee\n", vrpmb_ctrl.ssd_cmd);
		ret = TEEC_ERROR_VRPMB_AGENT_FAIL;
		goto clean;
	}

	if (ret != 0) {
		tloge("rw file failed, %d, cmd:%d\n", ret, vrpmb_ctrl.ssd_cmd);
		ret = TEEC_ERROR_VRPMB_RW_FAIL;
	}

clean:
	vrpmb_ctrl.ree_result = ret;
	(void)memcpy_s(share_buf, sizeof(vrpmb_info_head_t), &vrpmb_ctrl, sizeof(vrpmb_info_head_t));

	return 0;
}
