/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _TEMP_DPA_MSG_TASK_H
#define _TEMP_DPA_MSG_TASK_H
#include <linux/version.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>

#include "dpa_msg_cmsg.h"

#define DPA_MSG_CHN_STATUS_UNINIT 0
#define DPA_MSG_CHN_STATUS_INITING 1
#define DPA_MSG_CHN_STATUS_INITED 2

struct dpa_msg_task_t {
    u32 status;
    struct task_struct *worker;
    struct semaphore worker_sem;
    struct wakeup_source *worker_wakelock;
};
struct dpa_channel_ctrl_t;
struct dpa_msg_task_ctrl_t {
    struct dpa_channel_ctrl_t *p_channel_ctrl;
    struct dpa_msg_task_t task;
};
int dpa_fipc_recv_proc(void *arg);
int dpa_msg_task_init(struct dpa_msg_task_ctrl_t *p_ctrl);
#endif