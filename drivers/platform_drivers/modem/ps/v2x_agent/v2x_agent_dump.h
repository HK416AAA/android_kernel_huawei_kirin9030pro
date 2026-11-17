/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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
#ifndef _IOT_V2X_AGENT_DEBUG_H_
#define _IOT_V2X_AGENT_DEBUG_H_

#include <osl_types.h>
#include "v2x_agent.h"
#include "bsp_v2x_agent.h"

#define V2X_AGENT_DUMP_SIZE (1024)
#define V2X_AGENT_DUMP_DEBUG_SIZE (124)
#define V2X_AGENT_DUMP_HIDIS_SIZE (V2X_AGENT_DUMP_SIZE - V2X_AGENT_DUMP_DEBUG_SIZE)

struct v2x_agent_dump_t {
    /* 上下行eicc通道信息 */
    u32 recv_chn;                                /* eicc注册的接收通道 */
    u32 send_chn;                                /* eicc注册的发送通道 */
    /* mmap和ioctl的次数 */
    u32 mmap_count;                              /* 用户态mmap次数 */
    u32 downlink_len_ioctl_count;                /* 用户态获取下行buffer len次数 */
    u32 uplink_len_ioctl_count;                  /* 用户态获取上行buffer len次数 */
    u32 read_downlink_wptr_ioctl_count;          /* 用户态读取下行写指针次数 */
    u32 write_downlink_rptr_ioctl_count;         /* 用户态更新下行读指针次数 */
    u32 read_uplink_rptr_ioctl_count;            /* 用户态获取上行读指针次数 */
    u32 write_uplink_wptr_ioctl_count;           /* 用户态获取上行写指针次数 */
    u32 get_pm_ioctl_count;                      /* 用户态获取pm状态次数 */
    u32 set_gmecc_ioctl_count;                   /* 用户态更新gmecc数据次数 */
    /* LTEV相关的信息 */
    u32 ltev_send_count;                         /* LTEV调用发送接口次数 */
    u32 ltev_recv_count;                         /* LTEV接收回调接口次数 */
    u32 ltev_downlink_count;                     /* LTEV完成下行流程次数 */
    u32 ltev_uplink_count;                       /* LTEV完成上行流程次数 */
    /* eicc中断上报信息 */
    u32 downlink_intr_count;                     /* EICC接收完成中断次数 */
    u32 uplink_intr_count;                       /* EICC发送完成中断次数 */
    /* 上下行读写指针 */
    u32 downlink_rptr;                           /* 下行读指针 */
    u32 downlink_wptr;                           /* 下行写指针 */
    u32 uplink_rptr;                             /* 上行读指针 */
    u32 uplink_wptr;                             /* 上行写指针 */
};

struct v2x_agent_hids_info {
    u32 event;                                   /* 当前记录事件 */
    u32 timestamp;                               /* 当前记录时间 */
    u32 downlink_rptr;                           /* 下行读指针 */
    u32 downlink_wptr;                           /* 下行写指针 */
    u32 uplink_rptr;                             /* 上行读指针 */
    u32 uplink_wptr;                             /* 上行写指针 */
};

struct v2x_agent_dump_info{
    u8 *base_addr;                             /* dump空间基地址 */
    u8 *hids_info_addr;                         /* 流水信息基地址，同时上报hids */
    u32 cur;                                   /* 当前偏移 */
};

int v2x_agent_dump_init(void);

void bsp_v2x_agent_dump_rec(u32 event_index, u32 event_info);

#ifdef CONFIG_V2X_AGENT_DUMP
#define V2X_AGENT_RECORD_EVENT(event_index, event_info)       \
    do {                                                      \
        bsp_v2x_agent_dump_rec(event_index, event_info);      \
    } while (0)
#else
#define V2X_AGENT_RECORD_EVENT(event_index, event_info)
#endif

#endif
