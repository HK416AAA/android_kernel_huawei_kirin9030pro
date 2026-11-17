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

#ifndef MDM_STR_H
#define MDM_STR_H

#include <bsp_print.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef THIS_MODU
#define THIS_MODU mod_mdm_str

#define mdm_str_err(fmt, ...) bsp_err(fmt, ##__VA_ARGS__)

#define MDM_STR_WAIT_TIME_MS 10000
#define MDM_STR_DUMP_SIZE 0x200
#define MDM_STR_DUMP_NODE_NUM 0x8

// 与终端、RIL 约定状态值，用于与底层软件状态解耦
#define MDM_ENTER_STR_MODE  (10) // 上层下发进入STR
#define MDM_ENTER_STR_STATE (11) // 返回上层进入STR状态
#define MDM_EXIT_STR_MODE   (12) // 上层下发退出STR
#define MDM_EXIT_STR_STATE  (13) // 返回上层退出STR状态
#define MDM_IN_STR_PROC     (66) // 返回上层正处于STR处理

enum {
    MDM_NOT_RESET = 1,
    MDM_IN_RESET,
};

/* 与其他核消息传递结构 */
struct mdm_str_msg {
    unsigned int val;
    unsigned int slice;
};

struct str_task_ctrl {
    struct task_struct *task;
    struct semaphore notice_sem;
    struct semaphore resp_sem;
};

struct str_state_ctrl {
    unsigned int str_node_state; /* 上下半部str处理完成状态 */
    unsigned int str_mode_state; /* 是否处于str状态 */
    unsigned int reset_state; /* mdm 单独复位状态 */
    struct spinlock lock;
};

struct mdm_str_ctrl {
    struct device *dev;
    msg_chn_t msg_hdl;
    mdm_str_proc_phase_e str_phase;
    unsigned int inited;
    struct str_task_ctrl tsk;
    struct str_state_ctrl state;
};

enum {
    NODE_WIRTE = 0,
    NODE_VAL,
    TASK_UP,
    NOTIFY,
    RESP_TIMEOUT,
    RESP_RECV,
    DUMP_STEP_NUM
};

struct mdm_str_mntn_ctrl {
    unsigned int type;
    unsigned int ver;
    unsigned int count;
    unsigned int val[DUMP_STEP_NUM * MDM_STR_DUMP_NODE_NUM];
};

#ifdef __cplusplus
}
#endif
#endif