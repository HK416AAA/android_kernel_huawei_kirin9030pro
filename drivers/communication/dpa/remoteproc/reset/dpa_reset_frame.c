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

#include <securec.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>
#include <dpa_reset.h>
#include <bsp_nmi.h>
#include <bsp_dpa_ipc.h>
#include <bsp_dt.h>
#include <bsp_dra.h>
#include <bsp_rproc.h>
#include <bsp_mem_layout.h>
#include "dpa_reset_frame.h"
#include "dpa_reset_dev.h"
#include "dpa_reset_dump.h"
#include "bsp_dpa_fipc.h"
#include "bsp_dpa_ipc.h"

#define reset_err(fmt, ...) dpa_pr_err("[dpa_reset]"fmt, ##__VA_ARGS__)


struct dpa_reset_ctrl g_dpa_reset_ctrl;

struct dpa_reset_ops g_dpa_reset_host_ops = {
    .bsp_dpa_reset_register_cb = bsp_dpa_reset_register_cb,
};

struct dpa_reset_ctrl *dpa_reset_get_ctrl(void)
{
    return &g_dpa_reset_ctrl;
}

static void dpa_reset_fault_exit(unsigned int dos, unsigned int ret)
{
    unsigned long flags = 0;

    dpa_reset_host_dump(dos, DPA_RESET_HOST_DUMP_FAIL, ret);
    spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
    g_dpa_reset_ctrl.reset_action = DPA_RESET_INVALID_ACTION;
    g_dpa_reset_ctrl.reset_action_status = DPA_RESET_FAIL;
    spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);

    up(&(g_dpa_reset_ctrl.action_sem));
}

int dpa_reset_prepare(unsigned int action)
{
    unsigned long flags = 0;
    unsigned int current_action = (unsigned int)action;
    unsigned int global_action;
    spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
    global_action = g_dpa_reset_ctrl.reset_action;

    if (current_action == global_action || (global_action == (unsigned int)DPA_RESET_INVALID_ACTION)) {
        spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
        dpa_reset_host_dump(DPA_RESET_HOST_DUMP_CHECK_ACTION, DPA_RESET_HOST_DUMP_OK, action);
        return RESET_OK;
    } else if ((global_action == (unsigned int)DPA_RESET_NORMAL_STATUS) ||
        ((global_action == (unsigned int)DPA_RESET_POWEROFF) && (current_action == (unsigned int)DPA_RESET_POWERON))) {
        // 可进行reset
    } else {
        spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
        dpa_reset_host_dump(DPA_RESET_HOST_DUMP_CHECK_ACTION, DPA_RESET_HOST_DUMP_FAIL, action);
        reset_err(" not support %d action\n", action);
        return DPA_RESET_ERR_GEN(DPA_RESET_ACTION_INVALID);
    }
    g_dpa_reset_ctrl.reset_action = action;
    spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_CHECK_ACTION, DPA_RESET_HOST_DUMP_OK, action);
    __pm_stay_awake(g_dpa_reset_ctrl.wake_lock);
    reset_err("dpa_stay awake ok, 0x%x.\n", bsp_get_slice_value());

    up(&(g_dpa_reset_ctrl.task_sem));
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PREPARE_DONE, DPA_RESET_HOST_DUMP_OK, 0);
    return RESET_OK;
}

int dpa_reset_run_cb(dpa_reset_stage_e stage)
{
    struct reset_cb_list *p = NULL;
    struct reset_cb_list *next = NULL;
    int ret;
    unsigned int cnt = 0;

    reset_err("mods stage %d run cb at 0x%x.\n", (unsigned int)stage, bsp_get_slice_value());
    p = ((stage == DPA_RESET_BEFORE) ? g_dpa_reset_ctrl.list_head : g_dpa_reset_ctrl.list_tail);
    /* 根据回调函数优先级，调用回调函数 */
    while (p != NULL) {
        next = ((stage == DPA_RESET_BEFORE) ? p->next : p->prev);
        if (p->cb_info.cbfun == NULL) {
            p = next;
            continue;
        }
        dpa_reset_mod_dump_before(stage, cnt, p->cb_info.name, p->cb_info.priolevel);
        reset_err("mods stage: %d prio: %d name: %s cb start\n", stage, p->cb_info.priolevel, p->cb_info.name);
        ret = p->cb_info.cbfun(stage, p->cb_info.userdata);
        dpa_reset_mod_dump_after(stage, cnt, ret);
        if (ret) {
            reset_err("mods fail run cb %s, stage %d return %d\n", p->cb_info.name, stage, ret);
            return ret;
        }
        cnt++;
        p = next;
    }
    reset_err("mods stage %d cb done at 0x%x.\n", (unsigned int)stage, bsp_get_slice_value());

    return RESET_OK;
}

int dpa_reset_wait_start_done(unsigned int timeout)
{
    int ret;
    reset_err("wait reply from fw, slice:0x%x.\n", bsp_get_slice_value());
    ret = down_timeout(&(g_dpa_reset_ctrl.wait_reset_ok_sem), msecs_to_jiffies(timeout));
    if (ret) {
        reset_err("response from fw timeout 0x%x within %d.\n", ret, timeout);
        return ret;
    }

    reset_err("0x%x recv reply from fw\n", bsp_get_slice_value());
    return RESET_OK;
}

int dpa_reset_send_nmi(void)
{
    int ret;

    /* 发NMI通知fw处理 */
    ret = bsp_send_dpa_nmi(DPA_NMI_RESET);
    if (ret) {
        reset_err("dpa nmi send fail 0x%x.\n", ret);
    }
    ret = down_timeout(&(g_dpa_reset_ctrl.wait_host_in_idle_sem), msecs_to_jiffies(DPA_RESET_WAIT_FW_IDLE_TIMEOUT));
    if (ret) {
        reset_err("(0x%x) fw host in idle timeout\n", bsp_get_slice_value());
    } else {
        reset_err("(0x%x) fw host in idle successfully\n", bsp_get_slice_value());
    }
    return ret;
}

int dpa_reset_do_reseting(void)
{
    reset_err("dpa_reseting start: 0x%x.\n", bsp_get_slice_value());
    int ret = bsp_dpa_fipc_chn_before_resetting();
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_FIPC_BEFORE, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_FIPC_BEFORE, DPA_RESET_HOST_DUMP_OK, DPA_RESET_STAMP_STAGE_1);
    bsp_ipc_dpa_reset(DPA_RESET_BEFORE);
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_FIPC_BEFORE, DPA_RESET_HOST_DUMP_OK, DPA_RESET_STAMP_STAGE_2);
    ret = bsp_dpa_sc_flush_and_disable_gid_ctrl();
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_FIPC_BEFORE, ret);
        reset_err("dpa sc flush fail 0x%x, ret: 0x%x.\n", bsp_get_slice_value(), ret);
        return ret;
    }
    reset_err("dra reseting start\n");
    bsp_dra_dpa_rst();
    reset_err("dpa_reseting end: 0x%x.\n", bsp_get_slice_value());
    return RESET_OK;
}

int dpa_reset_do_power_off(unsigned int action)
{
    int ret;
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_START, DPA_RESET_HOST_DUMP_OK, action);
    // 发IPC 唤醒DPA
    ret = bsp_dpa_ipc_send(DPA_IPC_DPA_INT_SRC_ACPU_DPA_RESET);
    if (ret) {
        reset_err("(0x%x) fw wakeup fail 0x%x.\n", bsp_get_slice_value(), ret);
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_WAKEUP, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_WAKEUP, DPA_RESET_HOST_DUMP_OK, action);

    /* 复位前各组件回调 */
    ret = dpa_reset_run_cb(DPA_RESET_BEFORE);
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_DO_BEFORE, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_DO_BEFORE, DPA_RESET_HOST_DUMP_OK, action);
    // 复位前先清掉上次的fw dump
    dpa_reset_fw_dump_clear();
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_CLR_DUMP, DPA_RESET_HOST_DUMP_OK, action);

    ret = dpa_reset_send_nmi();
    /* 开关控制idle超时是否进行整机复位 */
    if ((ret != 0) && (g_dpa_reset_ctrl.is_idle_timeout_reset == DPA_RESET_TRIGGER_FULL_RESET)) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_NMI, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_NMI, DPA_RESET_HOST_DUMP_OK, ret);

    dpa_reset_fw_dump_parse();
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_DUMP_PARSE, DPA_RESET_HOST_DUMP_OK, action);
    ret = dpa_reset_do_reseting();
    if (ret) {
        return ret;
    }
    // power_down
    reset_err("dpa power down start 0x%x.\n", bsp_get_slice_value());
    // dpa子系统复位
    ret = bsp_rproc_stop();
    if (ret) {
        reset_err("dpa power down error 0x%x, 0x%x.\n", ret, bsp_get_slice_value());
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_POFF_DONE, ret);
        return ret;
    }
    reset_err("dpa power down ok 0x%x\n", bsp_get_slice_value());
    bsp_nmi_clear();
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_DONE, DPA_RESET_HOST_DUMP_OK, action);

    return RESET_OK;
}

int dpa_reset_do_power_on(unsigned int action)
{
    int ret;
    // DPA子系统下电和上电封装到一个接口内部了
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_START, DPA_RESET_HOST_DUMP_OK, action);
    // 镜像加载，power on
    ret = bsp_rproc_boot();
    if (ret) {
        reset_err("dpa power up error 0x%x, 0x%x.\n", ret, bsp_get_slice_value());
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_PON_DOING, ret);
        return ret;
    }
    reset_err("dpa power up has been ok 0x%x\n", bsp_get_slice_value());
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_DOING, DPA_RESET_HOST_DUMP_OK, action);

    ret = dpa_reset_wait_start_done(DPA_RESET_WAIT_START_TIMEOUT);
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_PON_WAIT_DONE, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_WAIT_DONE, DPA_RESET_HOST_DUMP_OK, ret);

    ret = bsp_dpa_fipc_chn_after_resetting();
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_PON_FIPC_AFTER, ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_FIPC_AFTER, DPA_RESET_HOST_DUMP_OK, DPA_RESET_STAMP_STAGE_1);
    bsp_ipc_dpa_reset(DPA_RESET_AFTER);
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_FIPC_AFTER, DPA_RESET_HOST_DUMP_OK, DPA_RESET_STAMP_STAGE_2);

    ret = dpa_reset_run_cb(DPA_RESET_AFTER);
    if (ret) {
        dpa_reset_fault_exit(DPA_RESET_HOST_DUMP_PON_DO_AFTER, ret);
        reset_err("do_power_on_after fail! ret:0x%x.\n", ret);
        return ret;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_DO_AFTER, DPA_RESET_HOST_DUMP_OK, ret);
    // 此阶段不用释放唤醒锁
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_WAKEUP, DPA_RESET_HOST_DUMP_OK, ret);

    return RESET_OK;
}

static int dpa_reset_do_reset(unsigned int action)
{
    int ret;

    ret = dpa_reset_do_power_off(action);
    if (ret) {
        return ret;
    }

    ret = dpa_reset_do_power_on(action);
    if (ret) {
        return ret;
    }

    return RESET_OK;
}


int dpa_reset_task(void *arg)
{
    unsigned int action;
    unsigned long flags = 0;
    unsigned int err_action = 0x0;
    int ret;

    while (!err_action) {
        reset_sem_down(&(g_dpa_reset_ctrl.task_sem));
        spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
        action = g_dpa_reset_ctrl.reset_action;
        spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
        dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_SEMDOWN, DPA_RESET_HOST_DUMP_OK, action);
        reset_err("reset task_sem up, slice:0x%x reset_action:%d.\n", bsp_get_slice_value(), action);
        if (action == DPA_RESET_POWEROFF) {
            ret = dpa_reset_do_power_off(action);
            dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_POFF, DPA_RESET_HOST_DUMP_OK, ret);
        } else if (action == DPA_RESET_POWERON) {
            ret = dpa_reset_do_power_on(action);
            dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_PON, DPA_RESET_HOST_DUMP_OK, ret);
        } else if (action == DPA_RESET_DO_RESET) {
            ret = dpa_reset_do_reset(action);
            g_dpa_reset_ctrl.reset_cnt++;
            dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_RESET, DPA_RESET_HOST_DUMP_OK, ret);
            reset_err("reset count: %d.\n", g_dpa_reset_ctrl.reset_cnt);
        } else if (action != DPA_RESET_NORMAL_STATUS && action != DPA_RESET_INVALID_ACTION) {
            reset_err("reset action err, dpa_reset_task exit:%d.\n", action);
            dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_ACTION_DONE, DPA_RESET_HOST_DUMP_FAIL, action);
            err_action = 0x1;
        }
        dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_ACTION_DONE, DPA_RESET_HOST_DUMP_OK, ret);

        spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
        if ((action == DPA_RESET_POWERON || action == DPA_RESET_DO_RESET) && (action == g_dpa_reset_ctrl.reset_action)) {
            g_dpa_reset_ctrl.reset_action = DPA_RESET_NORMAL_STATUS;
            g_dpa_reset_ctrl.reset_action_status = DPA_RESET_SUCCESS;
        }
        spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);

        up(&(g_dpa_reset_ctrl.action_sem));
        // 释放唤醒锁
        __pm_relax(g_dpa_reset_ctrl.wake_lock);
        g_dpa_reset_ctrl.end_slice = bsp_get_slice_value();
        reset_err("execute done, slice: 0x%x, diff cnt %d\n", g_dpa_reset_ctrl.end_slice,
            get_timer_slice_delta(g_dpa_reset_ctrl.start_slice, g_dpa_reset_ctrl.end_slice));
        dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_SUM_DONE, DPA_RESET_HOST_DUMP_OK, ret);
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_TSK_EXIT, DPA_RESET_HOST_DUMP_FAIL, ret);
    reset_err("reset task exit.\n");
    return DPA_RESET_ERR_GEN(DPA_RESET_TASK_EXIT_ERR);
}

static int dpa_reset_create_task(void)
{
    g_dpa_reset_ctrl.task = kthread_run(dpa_reset_task, NULL, "dpa_reset");
    if (g_dpa_reset_ctrl.task == NULL) {
        reset_err("create dpa_reset thread fail!\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_TASK_INIT_ERR);
    }
    return RESET_OK;
}

void dpa_reset_do_work(struct work_struct *work)
{
    int ret;
    g_dpa_reset_ctrl.start_slice = bsp_get_slice_value();
    reset_err("reset start, 0x%x;\n", g_dpa_reset_ctrl.start_slice);
    g_dpa_reset_ctrl.reset_status = DPA_RESET_RESETING;
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PREPARE, DPA_RESET_HOST_DUMP_OK, 0);
    ret = dpa_reset_prepare(DPA_RESET_DO_RESET);
    if (ret) {
        reset_err("reset prepare fail!");
    }
}

int dpa_reset_recv_idle_done(void *arg)
{
    reset_err("recv fw host in idle ipc, 0x%x.\n", bsp_get_slice_value());
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_POFF_RECV_RESP, DPA_RESET_HOST_DUMP_OK, 0);
    up(&(g_dpa_reset_ctrl.wait_host_in_idle_sem));
    return 0;
}

int dpa_reset_recv_start_done(void *arg)
{
    bsp_rproc_set_event(RPROC_EVENT_DPA_FW_MODULE_INIT_DONE);
    reset_err("recv fw start ok ipc, 0x%x.\n", bsp_get_slice_value());
    if (g_dpa_reset_ctrl.reset_status == DPA_RESET_NORMAL) {
        return 0;
    }
    dpa_reset_host_dump(DPA_RESET_HOST_DUMP_PON_RECV_RESP, DPA_RESET_HOST_DUMP_OK, 0);
    up(&(g_dpa_reset_ctrl.wait_reset_ok_sem));
    return 0;
}

static int dpa_reset_sys_init(void)
{
    unsigned long flags = 0;

    spin_lock_init(&g_dpa_reset_ctrl.action_lock);
    spin_lock_init(&g_dpa_reset_ctrl.list_lock);
    spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
    g_dpa_reset_ctrl.reset_action = DPA_RESET_NORMAL_STATUS;
    g_dpa_reset_ctrl.reset_action_status = DPA_RESET_SUCCESS;
    spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);

    sema_init(&g_dpa_reset_ctrl.wait_host_in_idle_sem, 0);
    sema_init(&g_dpa_reset_ctrl.wait_reset_ok_sem, 0);
    sema_init(&g_dpa_reset_ctrl.task_sem, 0);
    sema_init(&g_dpa_reset_ctrl.action_sem, 0);
    g_dpa_reset_ctrl.reset_wq = create_singlethread_workqueue("reset_wq");
    if (g_dpa_reset_ctrl.reset_wq == NULL) {
        reset_err("create reset wq fail!\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_WORKQUEQUE_INIT_ERR);
    }
    INIT_WORK(&(g_dpa_reset_ctrl.work_reset), dpa_reset_do_work);

    g_dpa_reset_ctrl.wake_lock = wakeup_source_register(NULL, "dpa_reset_wake");
    if (g_dpa_reset_ctrl.wake_lock == NULL) {
        reset_err("wakeup_source reg error\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_WAKEUP_REG_ERR);
    }

    return RESET_OK;
}

static int dpa_reset_ipc_init(void)
{
    int ret;
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_RESET_HOST_IDLE, (dpa_ipc_cbk)dpa_reset_recv_idle_done, 0);
    if (ret) {
        reset_err("ipc connect wait idle failed! ret:0x%x\n", ret);
        return ret;
    }
    ret = bsp_dpa_ipc_connect(DPA_IPC_ACPU_INT_SRC_DPA_RESET_START_OK, (dpa_ipc_cbk)dpa_reset_recv_start_done, 0);
    if (ret) {
        reset_err("ipc connect start done failed! ret:0x%x\n", ret);
        return ret;
    }
    return RESET_OK;
}

static int dpa_reset_config_init(void)
{
    int ret;
    device_node_s *node = NULL;
    node = bsp_dt_find_compatible_node(NULL, NULL, "dpa,reset");
    if (node == NULL) {
        reset_err("[dpa_reset]can't find reset node\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_INIT_DT_ERR);
    }

    ret = bsp_dt_property_read_u32(node, "enable", &g_dpa_reset_ctrl.reset_enable);
    if (ret) {
        reset_err("get enable fail, ret:0x%x\n", ret);
        g_dpa_reset_ctrl.reset_enable = DPA_RESET_UNSUPPORT;
    }
    // 启动阶段设置firmware的before处理超时强制往下执行;
    g_dpa_reset_ctrl.is_idle_timeout_reset = DPA_RESET_GOING;
    return ret;
}

int bsp_dpa_reset_pre_init(void)
{
    int ret;

    (void)memset_s((void *)&g_dpa_reset_ctrl, sizeof(g_dpa_reset_ctrl), 0, sizeof(g_dpa_reset_ctrl));

    ret = dpa_reset_sys_init();
    if (ret) {
        reset_err("dpa_reset_sys_init fail! 0x%x.\n", ret);
        return ret;
    }
    ret = dpa_reset_config_init();
    if (ret) {
        return ret;
    }

    ret = dpa_reset_dev_init();
    if (ret) {
        return ret;
    }
    ret = dpa_reset_api_register(&g_dpa_reset_host_ops);
    if (ret) {
        reset_err("dpa_reset api register fail! ret:0x%x\n", ret);
        return ret;
    }

    reset_err("dpa pre reset init ok\n");
    return ret;
}

int bsp_dpa_reset_init(void)
{
    int ret;
    ret = dpa_reset_ipc_init();
    if (ret) {
        return ret;
    }
    ret = dpa_reset_dump_init();
    if (ret) {
        return ret;
    }

    g_dpa_reset_ctrl.reset_status = DPA_RESET_NORMAL;
    g_dpa_reset_ctrl.is_init = DPA_RESET_INIT_OK;
    ret = dpa_reset_create_task();
    if (ret) {
        reset_err("dpa_reset_sys_init or task init fail!\n");
        return ret;
    }

    reset_err("dpa reset init ok\n");
    return 0;
}

static struct reset_cb_list *sort_list_insert(struct reset_cb_list *list_head, struct reset_cb_list *node,
    struct reset_cb_list **list_tail)
{
    struct reset_cb_list *head = list_head;
    struct reset_cb_list *curr = list_head;
    struct reset_cb_list *tail = list_head;

    if (list_head == NULL || list_tail == NULL || node == NULL) {
        return NULL;
    }
    while (curr != NULL) {
        /* 由小到大, 按优先级插入 */
        if (curr->cb_info.priolevel > node->cb_info.priolevel) {
            if (head == curr) {
                node->next = curr;
                curr->prev = node;
                head = node;
            } else {
                tail->next = node;
                node->prev = tail;
                node->next = curr;
                curr->prev = node;
            }
            break;
        }
        tail = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        tail->next = node;
        node->prev = tail;
        *list_tail = node;
    }
    return head;
}

int dpa_reset_cb_node_register(struct reset_cb_list *cb_func_node)
{
    unsigned long flags = 0;
    struct reset_cb_list *node = NULL;
    spin_lock_irqsave(&g_dpa_reset_ctrl.list_lock, flags);
    if (g_dpa_reset_ctrl.list_head == NULL) {
        g_dpa_reset_ctrl.list_head = cb_func_node;
        g_dpa_reset_ctrl.list_tail = cb_func_node;
    } else {
        node = sort_list_insert(g_dpa_reset_ctrl.list_head, cb_func_node, &g_dpa_reset_ctrl.list_tail);
        if (node == NULL) {
            return DPA_RESET_ERR_GEN(DPA_RESET_CB_REGISTER_FAIL);
        }
        g_dpa_reset_ctrl.list_head = node;
    }
    g_dpa_reset_ctrl.mods_cnt++;
    spin_unlock_irqrestore(&g_dpa_reset_ctrl.list_lock, flags);

    return RESET_OK;
}

struct reset_cb_list *dpa_reset_cb_node_create(const char *func_name, dpa_reset_cb func, int user_data, int prior)
{
    struct reset_cb_list *cb_func_node = NULL;
    unsigned int name_len;
    int ret;

    if (func_name == NULL || func == NULL ||
        (prior < DPA_RESET_CB_LEVEL_BASE || prior >= DPA_RESET_CB_LEVEL_MAX)) {
        reset_err("register fail, input error, prio=%d\n", prior);
        return NULL;
    }

    cb_func_node = (struct reset_cb_list *)kmalloc(sizeof(struct reset_cb_list), GFP_KERNEL);
    if (cb_func_node != NULL) {
        name_len = (unsigned int)min((unsigned int)DPA_RESET_MOD_NAME_LEN, (unsigned int)strlen(func_name));

        ret = memset_s((void *)(uintptr_t)cb_func_node, (sizeof(*cb_func_node)), 0, (sizeof(struct reset_cb_list)));
        if (ret) {
            reset_err("memset error%d\n", ret);
            kfree(cb_func_node);
            return NULL;
        }

        ret = memcpy_s((void *)cb_func_node->cb_info.name,
            (unsigned int)min((unsigned int)DPA_RESET_MOD_NAME_LEN, (unsigned int)strlen(func_name)), (void *)func_name, (int)name_len);
        if (ret) {
            reset_err("memcpy error%d\n", ret);
            kfree(cb_func_node);
            return NULL;
        }
        cb_func_node->cb_info.priolevel = prior;
        cb_func_node->cb_info.userdata = user_data;
        cb_func_node->cb_info.cbfun = func;
    } else {
        reset_err("register malloc fail, name:%s, prio=%d\n", func_name, prior);
        return NULL;
    }
    return cb_func_node;
}

int bsp_dpa_reset_register_cb(const char *name, dpa_reset_cb func, dpa_reset_stage_e user_data, int prior)
{
    int ret;
    struct reset_cb_list *node = NULL;

    if (name == NULL) {
        reset_err("register info name null, prio=%d.\n", prior);
        return DPA_RESET_ERR_GEN(DPA_RESET_INPUT_NAME_ERR);
    }

    node = dpa_reset_cb_node_create(name, func, user_data, prior);
    if (node == NULL) {
        return DPA_RESET_ERR_GEN(DPA_RESET_CREATE_NODE_ERR);
    }
    ret = dpa_reset_cb_node_register(node);
    if (ret) {
        reset_err("sort_list_insert fail!\n");
    }
    return ret;
}
EXPORT_SYMBOL(bsp_dpa_reset_register_cb);

int bsp_dpa_reset_is_successful(unsigned int timeout_ms)
{
    int ret;
    unsigned long flags = 0;
    ret = down_timeout(&(g_dpa_reset_ctrl.action_sem), msecs_to_jiffies(timeout_ms));

    g_dpa_reset_ctrl.reset_status = DPA_RESET_NORMAL; // 无论成功与否，状态都需要恢复，否则会影响下次reset的执行以及dpa dump的导出；
    spin_lock_irqsave(&g_dpa_reset_ctrl.action_lock, flags);
    if ((ret == 0) && (g_dpa_reset_ctrl.reset_action == DPA_RESET_NORMAL_STATUS)) {
        spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
        reset_err("dpa reset success!\n");
        return DPA_RESET_SUCCESS;
    }

    spin_unlock_irqrestore(&g_dpa_reset_ctrl.action_lock, flags);
    reset_err("dpa reset fail, ret:%d!\n", ret);
    return DPA_RESET_FAIL;
}

static int dpa_reset_check_cnt(void)
{
    unsigned int head;
    unsigned int tail;
    unsigned int diff = 0;
    head = (g_dpa_reset_ctrl.reset_cnt - 1) % DPA_RESET_TO_BYPASS_TIME_CNT;
    tail = (head + 1) % DPA_RESET_TO_BYPASS_TIME_CNT;
    diff = g_dpa_reset_ctrl.reset_time[head] - g_dpa_reset_ctrl.reset_time[tail];
    if ((g_dpa_reset_ctrl.reset_cnt > DPA_RESET_TO_BYPASS_TIME_CNT) &&
        (diff < DPA_RESET_TO_BYPASS_TIME_CNT * DPA_RESET_TIME_SLICE)) {
        return DPA_RESET_TO_BYPASS_TIME_CNT;
    }

    return 0;
}

int bsp_dpa_reset(void)
{
    int ret;
    unsigned int slice;
    if (g_dpa_reset_ctrl.is_init == 0) {
        reset_err("dpa reset not init\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_NOT_INIT);
    }
    if (g_dpa_reset_ctrl.reset_enable == DPA_RESET_UNSUPPORT) {
        reset_err("dpa reset disable\n");
        return DPA_RESET_ERR_GEN(DPA_RESET_IS_DISABLE);
    }
    queue_work(g_dpa_reset_ctrl.reset_wq, &(g_dpa_reset_ctrl.work_reset));

    ret = bsp_dpa_reset_is_successful(DPA_RESET_TIMEOUT);
    if (dpa_reset_check_cnt()) {
        reset_err("dpa_reset %d times in %d minutes, goto bypass, 0x%x.\n", DPA_RESET_TO_BYPASS_TIME_CNT,
            DPA_RESET_TO_BYPASS_TIME_CNT, bsp_get_slice_value());
        g_dpa_reset_ctrl.is_reset_wait_bypass = DPA_RESET_BYPASS_FLAG;
        dpa_reset_bypass_dump(DPA_RESET_BYPASS_FLAG);
        // ENG阶段整机复位，商用后等待用户整机复位
#ifdef CONFIG_DPA_RESET_DEBUG
        dpa_system_error(DRV_ERRNO_DPA_RESET, DPA_RESET_FULL_ERSET_ERR, DPA_RESET_TO_BYPASS_TIME_CNT, 0, 0);
#endif
    }
    if (ret == DPA_RESET_SUCCESS) {
        slice = bsp_get_slice_value();
        g_dpa_reset_ctrl.reset_time[g_dpa_reset_ctrl.reset_cnt % DPA_RESET_TO_BYPASS_TIME_CNT] = slice;
        dpa_reset_time_dump(g_dpa_reset_ctrl.reset_cnt, slice);
    }

    return ret;
}

enum dpa_reset_feature_status bsp_dpa_reset_is_feature_on(void)
{
    return g_dpa_reset_ctrl.reset_enable;
}

enum dpa_reset_status bsp_reset_dpa_is_reboot(void)
{
    return g_dpa_reset_ctrl.reset_status;
}

int dpa_reset_test(void)
{
    unsigned int slice = bsp_get_slice_value();
    reset_err("dpa_reset test start: 0x%x.\n", slice);
    dpa_system_error(DRV_ERRNO_DPA_RESET_TEST, slice, 0, 0, 0);
    return 0;
}

int dpa_normal_reset_test(void)
{
    unsigned int slice = bsp_get_slice_value();
    reset_err("dpa_normal_reset test start: 0x%x.\n", slice);
    dpa_system_error(DRV_ERRNO_DPA_RESET_TEST_NORMALRST, slice, 0, 0, 0);
    return 0;
}

EXPORT_SYMBOL(bsp_dpa_reset);
EXPORT_SYMBOL(dpa_reset_test);
EXPORT_SYMBOL(dpa_normal_reset_test);
