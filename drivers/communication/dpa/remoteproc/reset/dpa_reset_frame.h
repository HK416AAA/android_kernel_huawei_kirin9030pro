/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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

#ifndef DPA_RESET_FRAME_H_
#define DPA_RESET_FRAME_H_

#include <linux/types.h>
#include <linux/list.h>
#include <linux/workqueue.h>
#include <linux/semaphore.h>
#include <linux/spinlock.h>

#define DPA_RESET_WAIT_START_TIMEOUT (5000)              /* ms, time of wating for reply from hifi/mcu */
#define DPA_RESET_WAIT_FW_IDLE_TIMEOUT (3100)     /* ms, time of wating for reply from modem in idle */
#define DPA_RESET_TIMEOUT (10000)

#define DPA_RESET_ENABLE 1
#define DPA_RESET_DISABLE 0

#define DPA_RESET_ERR_GEN(val) (0x80000000 | (val))

#define DPA_RESET_INIT_OK 1

#define RESET_OK 0

// 单独复位逃生措施次数
#define DPA_RESET_TO_BYPASS_TIME_CNT 3
#define DPA_RESET_TIME_SLICE (60 * 0x8000)
#define DPA_RESET_BYPASS_FLAG 0xEDDE

enum dpa_reset_action {
    DPA_RESET_NORMAL_STATUS,
    DPA_RESET_POWERON,
    DPA_RESET_POWEROFF,
    DPA_RESET_DO_RESET,
    DPA_RESET_INVALID_ACTION,
};

enum dpa_fail_action {
    DPA_RESET_TRIGGER_FULL_RESET,
    DPA_RESET_GOING,
};

enum dpa_reset_err {
    DPA_RESET_IS_DISABLE,
    DPA_RESET_NOT_INIT,
    DPA_RESET_TASK_INIT_ERR,
    DPA_RESET_INIT_DT_ERR,
    DPA_RESET_TASK_EXIT_ERR,
    DPA_RESET_DUMP_MALLOC_ERR,
    DPA_RESET_ACTION_INVALID,
    DPA_RESET_WORKQUEQUE_INIT_ERR,
    DPA_RESET_INPUT_NAME_ERR,
    DPA_RESET_CREATE_NODE_ERR,
    DPA_RESET_CB_REGISTER_FAIL,
    DPA_RESET_WAKEUP_REG_ERR,
    DPA_RESET_DEV_CLASS_ERR,
    DPA_RESET_DEV_DEVICE_ERR,
};

enum dpa_reset_err_sub_mod {
    DPA_RESET_INIT_ERR = 0x1000,
    DPA_RESET_FULL_ERSET_ERR,
    DPA_RESET_WAIT_IDLE_DONE,
    DPA_RESET_WAIT_START_DONE,
    DPA_RESET_PON_ERR,
    DPA_RESET_POFF_ERR,
    DPA_RESET_CB_BEFORE_ERR,
    DPA_RESET_CB_AFTET_ERR,
};

typedef struct semaphore reset_sem_id;

#define DPA_RESET_MOD_NAME_LEN 11
/* Record information of callback functions */
struct reset_cb_info {
    char name[DPA_RESET_MOD_NAME_LEN + 1];
    unsigned int priolevel;
    dpa_reset_cb cbfun;
    int userdata;
};

struct reset_cb_list {
    struct reset_cb_list *next;
    struct reset_cb_list *prev;
    struct reset_cb_info cb_info;
};

struct dpa_reset_ctrl {
    struct task_struct *task;
    unsigned int reset_action;
    unsigned int reset_action_status;
    spinlock_t action_lock;
    spinlock_t list_lock;
    reset_sem_id action_sem;
    reset_sem_id task_sem;
    reset_sem_id wait_reset_ok_sem;
    reset_sem_id wait_host_in_idle_sem;
    struct reset_cb_list *list_head;
    struct reset_cb_list *list_tail;
    struct workqueue_struct *reset_wq;
    struct work_struct work_reset;
    struct wakeup_source *wake_lock;
    uintptr_t fw_dump_addr;
    uintptr_t host_dump_addr;
    unsigned int start_slice;
    unsigned int end_slice;
    unsigned int mods_cnt;
    unsigned int reset_cnt;
    unsigned int reset_time[DPA_RESET_TO_BYPASS_TIME_CNT];
    unsigned int is_reset_wait_bypass;
    unsigned int reset_enable;
    unsigned int reset_status;
    unsigned int is_idle_timeout_reset;
    unsigned int is_init;
};

struct dpa_reset_ctrl *dpa_reset_get_ctrl(void);

static inline void reset_sem_down(reset_sem_id *sem)
{
    while (down_interruptible(sem) != 0);
}

#endif // DPA_RESET_FRAME_H_