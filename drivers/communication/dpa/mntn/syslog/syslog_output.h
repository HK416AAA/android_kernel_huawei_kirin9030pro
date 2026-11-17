/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __SYSLOG_OUTPUT_H__
#define __SYSLOG_OUTPUT_H__
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/semaphore.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/platform_device.h>
#include <linux/suspend.h>
#include <linux/pm_wakeup.h>
#include <linux/pm.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/spinlock.h>
#include <linux/miscdevice.h>
#include <linux/wait.h>
#include <securec.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_print.h>

#define BSP_OK (0)
#define BSP_ERROR (-1)

#define BSP_PRINT_BUF_LEN 192

typedef enum {
    SYSLOG_DPA_FW_PRINT_INFO = 0,
    SYSLOG_DPA_FW_RECORD_INFO,
    SYSLOG_DPA_HOST_RECORD_INFO,
    SYSLOG_DPA_DEV_INFO_MAX
} log_dev_e;

typedef enum {
    BSP_HIDS_LEVEL_ERROR = 1, /* 0x1:just for compatibility with previous version */
    BSP_HIDS_LEVEL_WARNING,   /* 0x2:warning conditions                           */
    BSP_HIDS_LEVEL_NOTICE,    /* 0x3:normal but significant condition             */
    BSP_HIDS_LEVEL_INFO,      /* 0x4:informational                                */
    BSP_HIDS_LEVEL_MAX
} bsp_hids_level_e;

/**
 * struct log_mem - represents shared information between reader & writer
 * This structure is allocated by writer
 */
struct log_mem {
    u32 magic;         /* magic number: protect memory  */
    u32 write;         /* write offset of ring buffer */
    u32 read;          /* read offset of ring buffer */
    u32 size;          /* ring buffer size */
    u32 app_is_active; /* reader's ready flag */
};

struct log_mem_stru {
    struct log_mem log_info;
    u32 logged_chars; /* number of chars in log buffer */
    u32 w_mark;       /* water mark, if logged chars exceed w_mark, ccore send IPC to acore */
    u32 reserved;     /* reserved for 32-byte align */
    u8 log_buf[0];      /* data area */
};
struct syslog_user_mem_info {
    struct log_mem log_info;    // HOST侧更新读指针
    struct log_mem_stru *log_mem_fw;   // 获取FW侧的写指针
};
void syslog_dpa_buf_store(char *buf, u32 len);
int syslog_user_init(void);
#endif
