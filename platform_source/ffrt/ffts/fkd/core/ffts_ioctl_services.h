/*
 * ffts_devinit.h
 *
 * ffts device ioctl services head file
 *
 * Copyright (c) 2023-2030 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _FFTS_IOCTL_SERVICE_H_
#define _FFTS_IOCTL_SERVICE_H_

#include <linux/cdev.h>

#include "ffts_common.h"
#include "ffts_ddr_map.h"
#include "ffts_soc_defines.h"

#define FFTS_ID_MAGIC                 'F'
#define FFTS_GET_DEVICE_INFO          _IO(FFTS_ID_MAGIC, 1)
#define FFTS_GET_GLOBAL_EXCP_INFO	  _IO(FFTS_ID_MAGIC, 2)
#define FFTS_CHECK_SUBMIT_UNIT_DONE	  _IO(FFTS_ID_MAGIC, 3)
#define FFTS_GET_QOS_TASK_CNT		  _IO(FFTS_ID_MAGIC, 4)
#define FFTS_GET_TASK_STATUS_INFO     _IO(FFTS_ID_MAGIC, 5)
#define FFTS_SET_TASK_TCB_INFO	      _IO(FFTS_ID_MAGIC, 6)
#define FFTS_GET_DFX_RES_INFO	      _IO(FFTS_ID_MAGIC, 7)
#define FFTS_MAX_CMD                  32

typedef struct {
	size_t mem_size[FFTS_MEM_MAX];
} ffts_device_info_t;

typedef struct {
	int qos;
	int qos_task_cnt;
} ffts_qos_info_t;

typedef struct {
    uint32_t  total_taskcnt;
    uint32_t  total_vercnt;
    uint32_t  total_sigcnt;
} ffts_dfx_res_info_t;

long ffts_ioctl(struct file *filep, unsigned int cmd, unsigned long arg);

#endif