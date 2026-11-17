/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
 */
#ifndef __BSP_MPERF_H__
#define __BSP_MPERF_H__

#include <bsp_print.h>
#include <osl_sem.h>

#define mperf_err(fmt, ...) (bsp_err("<%s> " fmt, __FUNCTION__, ##__VA_ARGS__))

#ifdef __cplusplus
extern "C" {
#endif

/*
 * mperf message define
 *
 * mperf_message_init    : mperf_message.data = mperf_message_cfg + mperf_message_event
 * mperf_message_start   : mperf_message.data = mperf_message_event
 * mperf_message_stop    : mperf_message.data = NULL
 */
typedef enum {
    MPERF_MSG_CONNECT,
    MPERF_MSG_INIT,
    MPERF_MSG_START,
    MPERF_MSG_COOKIE,
    MPERF_MSG_STOP,
    MPERF_MSG_SHUTDOWN,
    MPERF_MSG_ICC_CHANNEL_TEST,
    MPERF_MSG_TIME_SYNC,
    MPERF_MSG_SPPM_PWR_EN,
    MPERF_MSG_SPPM_CHAN_EN,
    MPERF_MSG_SPPM_ONLINE,
    MPERF_MSG_SPPM_PWR_DIS,
    MPERF_MSG_SPPM_CHAN_DIS,
    MPERF_MSG_SPPM_OFFLINE,
    MPERF_MSG_SPPM_START_TRACE,
    MPERF_MSG_SPPM_STOP_TRACE,
    MPERF_MSG_INIT_RES,
    MPERF_MSG_SPPM_PWR_EN_RES,
    MPERF_MSG_SPPM_CHAN_EN_RES,
    MPERF_MSG_SPPM_ONLINE_RES,
    MPERF_MSG_SPPM_PWR_DIS_RES,
    MPERF_MSG_SPPM_CHAN_DIS_RES,
    MPERF_MSG_SPPM_OFFLINE_RES,
    MPERF_MSG_SPPM_START_TRACE_RES,
    MPERF_MSG_SPPM_STOP_TRACE_RES,
    MPERF_MSG_MAX,
} mperf_message_cmd_e;

typedef struct {
    u32 config_from_tool;
    u32 final_buffer_flush;
    osl_sem_id sppm_sem;
} mperf_ctrl_t;

typedef struct {
    struct device *dev;

    unsigned long long virt_addr;    // ringbuffer A核可访问虚拟地址
    unsigned long long rb_phy_addr;  // ringbuffer sppm数据的物理地址
    unsigned int rb_size;            // ringbuffer 物理地址大小
    unsigned int data_size;          // 实际数据大小
} mperf_dpa_dev_info;

extern u64 trace_clock(void);
extern u64 ktime_get_boot_fast_ns(void);
extern u64 dfx_getcurtime(void);

mperf_ctrl_t *mperf_ctrl_get(void);

int mperf_msg_send(void *data, u32 len, u32 dst_core);

#ifdef __cplusplus
}
#endif
#endif
