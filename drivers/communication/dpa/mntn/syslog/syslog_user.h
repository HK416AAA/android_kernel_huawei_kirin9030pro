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

#ifndef __SYSLOG_USER_H__
#define __SYSLOG_USER_H__

#include <linux/miscdevice.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include "syslog_output.h"

/* log缓冲区满阈值，buffer空闲空间小于200字符，认为buffer已满 */
#define LOG_BUFFER_FULL_THRESHOLD 200

#define LOG_MOD_DELAY_30000 30000
#define LOG_MOD_DELAY_5000 5000
#define LOG_MOD_DELAY_10000 10000

/* log buffer满，输出提示 */
#define LOG_DROPPED_MESSAGE "log buffer full, data dropped\n"
/* dpa host record设备名 */
#define DPA_HOST_RECORD_DEV_NAME "dpa_host_record"
/* dpa fw record设备名 */
#define DPA_FW_RECORD_DEV_NAME "dpa_fw_record"
/* dpa fw syslog设备名 */
#define DPA_FW_SYSLOG_DEV_NAME "dpa_fw_syslog"

struct logger_info_stru {
    struct miscdevice misc; /* misc device */
    wait_queue_head_t wq;   /* wait queue */
    u32 in_use;             /* whether device is in use */
    u32 sleep_flag;         /* whether app is sleep */
    spinlock_t lock;
    struct list_head logs;
    struct log_mem_stru *log_mem;
};

struct bsp_earlylog_info {
    unsigned char *data_addr;
    unsigned int data_len;
};

struct log_usr_info;

/* if return val == 0 success, else fail */
typedef int (*USR_READ_FUNC)(struct log_usr_info *usr_info, char *buf, u32 count);

/* if return val == 0 success, else fail */
typedef int (*USR_OPEN_FUNC)(struct log_usr_info *usr_info);

/* if return val == 0 success, else fail */
typedef int (*USR_CLOSE_FUNC)(struct log_usr_info *usr_info);

/**
 * struct log_usr_info - represents user information which register to dpa log
 * This structure is allocated by writer
 */
struct log_usr_info {
    char               *dev_name;     /* misc device name */
    u32                mem_is_ok;     /* whether are two momory block(ring buffer & ring buffer info) initilized  */
    char               *ring_buf;     /* The data area(ring buffer) */
    struct log_mem     *mem;          /* The management area(ring buffer info) */
    u32                wake_interval; /* The interval of wakeup acore to trigger log file write, just used in ccore */
    USR_READ_FUNC      read_func;     /* user function in log read method */
    USR_OPEN_FUNC      open_func;     /* user function in log open method */
    USR_CLOSE_FUNC     close_func;    /* user function in log release method */
    struct log_mem     mem_local;    /* local ring buffer info */
};

struct syslog_user_info_ctrl {
    u32 state;
    u32 work_state;
    spinlock_t lock[SYSLOG_DPA_DEV_INFO_MAX];
};
enum syslog_user_data_info_state {
    SYSLOG_USER_DATA_INFO_STATE_INIT = 0,
    SYSLOG_USER_DATA_INFO_STATE_OK,
    SYSLOG_USER_DATA_INFO_STATE_RST_BF,
};
int syslog_user_dev_register(unsigned int index, struct log_mem_stru *data);
int syslog_user_dev_unregister(unsigned int index);
int syslog_user_info_register(unsigned int index, struct log_mem_stru *data);
int syslog_user_info_unregister(unsigned int index);
void syslog_user_info_init(void);
#endif
