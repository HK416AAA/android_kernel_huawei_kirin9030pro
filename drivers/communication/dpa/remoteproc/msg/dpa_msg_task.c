/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <securec.h>
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include "dpa_msg_plat.h"
#include "dpa_msg_task.h"
#include "dpa_msg_error_code.h"

#define DPA_MSG_TASK_MAX 8

int dpa_msg_task_init(struct dpa_msg_task_ctrl_t *p_ctrl)
{
    struct sched_param param = {
        .sched_priority = 0x60
    };
    struct dpa_msg_task_t *ptask = NULL;
    int ret;

    if (p_ctrl == NULL) {
        dpa_msg_err("dpa_msg_task_init bad p_ctrl!\n");
        return MSG_ERR_EIO;
    }

    ptask = &p_ctrl->task;
    ptask->status = DPA_MSG_CHN_STATUS_INITING;
    sema_init(&ptask->worker_sem, 0);
    ptask->worker_wakelock = wakeup_source_register(NULL, "dpa_msg_wl");
    ptask->worker =
        kthread_run(dpa_fipc_recv_proc, p_ctrl, "dpa_msg%d", p_ctrl->p_channel_ctrl->phychnid);
    if (IS_ERR(ptask->worker)) {
        dpa_msg_err("kthread_run ipipe %d fail\n", p_ctrl->p_channel_ctrl->phychnid);
        return MSG_ERR_ESRCH;
    }
    ret = sched_setscheduler(ptask->worker, SCHED_FIFO, &param);
    if (ret) {
        dpa_msg_err("sched_setscheduler ipipe %d fail, %d\n", p_ctrl->p_channel_ctrl->phychnid, ret);
        return ret;
    }
    ptask->status = DPA_MSG_CHN_STATUS_INITED;
    return 0;
}