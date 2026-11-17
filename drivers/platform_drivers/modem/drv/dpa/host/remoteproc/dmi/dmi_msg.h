/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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

#ifndef _DMI_MSG_H_
#define _DMI_MSG_H_

#include <linux/netdevice.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/wait.h>
#include <linux/dma-mapping.h>
#include <securec.h>
#include "bsp_dpa_msg.h"
#include "bsp_dpa_fipc.h"
#include <bsp_dmi.h>
#include <bsp_dra.h>
#include <bsp_dpa_chr.h>

#define DMI_BUF_SIZE (MAX_MSG_SIZE)
#define DMI_RST 0x111

#define DMI_EVENT_THREAD_STOPING_BIT(n) ((n) + DMI_SERVICE_TYPE_COMM)
#define DMI_EVENT_THREAD_STOPED_BIT(n) ((n) + DMI_SERVICE_TYPE_COMM * 2)

#define DMI_CHN_FIPC_RPTR_INVALID (0xffff)

typedef int (*dmi_msg_cbk)(void *, unsigned int, unsigned int);

struct dmi_dma_head {
    unsigned int chn;
    unsigned int len;
    unsigned long long gaddr;
};

struct dmi_msg_ctx_task {
    u32 chn;
    wait_queue_head_t wqueue;
    unsigned int event;
    struct wakeup_source *wakelock;
    struct task_struct *worker;
    unsigned int stat;
    unsigned int try_again;
    bool is_intr_dis;
    u32 intr_dis_thresh;
    u32 intr_dis_cnt;
    u32 intr_en_cnt;
};

struct dmi_msg_merge_cfg {
    u32 msglen_thresh;
    u32 intr_timeout;
    u32 overflow_th;
};

struct dmi_msg_ctx {
    dpa_fipc_chn_t dmi_msg_hdl[DMI_SERVICE_TYPE_PLANE_MAX];
    dmi_msg_cbk cbk[DMI_SERVICE_TYPE_PLANE_MAX];
};

void *dmi_msg_malloc(unsigned int len, u64 *pa);
void *dmi_client_dma_buf_alloc(size_t size, dma_addr_t *dma_handle);

int dmi_msg_send_ch_init(int chn, int chnid);
int dmi_msg_send(int chn, void *msg, u64 pa, unsigned int len);
int dmi_msg_send_sync(int chn, void *msg, u64 pa, unsigned int len);
int dmi_send_queue_clear(void);
void dmi_msg_send_stop(void);
int dmi_msg_send_restart(void);

int dmi_msg_recv_init(unsigned int chn);
int dmi_msg_recv_ch_init(int chn, int chnid, void *cbk);
void dmi_msg_recv_stop(unsigned int chn);
void dmi_msg_recv_restart(unsigned int chn);
void dmi_msg_recv_resume(void);
void dmi_client_chn_event_notify(unsigned int plane, enum dmi_event_type_e event);
#endif
