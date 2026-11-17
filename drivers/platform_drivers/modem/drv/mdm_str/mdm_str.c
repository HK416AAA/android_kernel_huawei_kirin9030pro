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

#include <osl_types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/kthread.h>
#include <linux/semaphore.h>
#include <linux/spinlock.h>
#include <securec.h>
#include <bsp_dump.h>
#include <bsp_slice.h>
#include <bsp_msg.h>
#include <msg_id.h>
#include <bsp_mdm_str.h>
#include "mdm_str.h"

// 状态相关设置成默认值
struct mdm_str_ctrl g_mdm_str_ctrl = {
    .inited = 0,
    .str_phase = PHASE_EXIT_MDM_STR,
    .state.reset_state = MDM_NOT_RESET,
    .state.str_node_state = MDM_EXIT_STR_STATE,
    .state.str_mode_state = PHASE_EXIT_MDM_STR,
};

mdm_str_proc_func g_mdm_str_proc_funcs[STR_MODULE_MAX] = {0};
struct mdm_str_mntn_ctrl *g_mdm_str_mntn_ctrl = NULL;

static inline unsigned int mode_covert_user2drv(unsigned int mode_val)
{
    return (mode_val == MDM_ENTER_STR_MODE ? PHASE_ENTER_MDM_STR : PHASE_EXIT_MDM_STR);
}

static inline unsigned int mode_covert_drv2user(unsigned int mode_val)
{
    return (mode_val == PHASE_ENTER_MDM_STR ? MDM_ENTER_STR_STATE : MDM_EXIT_STR_STATE);
}

static void mdm_str_mntn_record(int step, unsigned int val)
{
    int idx;
    if (unlikely(g_mdm_str_mntn_ctrl == NULL)) {
        return;
    }

    if (step == NODE_WIRTE) {
        g_mdm_str_mntn_ctrl->count++;
    }

    idx = g_mdm_str_mntn_ctrl->count & (MDM_STR_DUMP_NODE_NUM - 1U);
    g_mdm_str_mntn_ctrl->val[idx * MDM_STR_DUMP_NODE_NUM + step] = val;
}

int bsp_mdm_str_register(mdm_str_module_e module, mdm_str_proc_func func)
{
    if (module >= STR_MODULE_MAX || func == NULL) {
        return -1;
    }
    g_mdm_str_proc_funcs[module] = func;
    return 0;
}

int mdm_str_msg_proc(const struct msg_addr *src, void *buf, u32 len)
{
    if (src->chnid != MSG_CHN_MDM_STR || src->core != MSG_CORE_LPM) {
        mdm_str_err("invalid args chnid %d, core %d\n", src->chnid, src->core);
        return -1;
    }
    mdm_str_err("recv at 0x%x\n", bsp_get_slice_value());
    up(&g_mdm_str_ctrl.tsk.resp_sem);
    return 0;
}

static void mdm_str_acpu_proc(mdm_str_proc_phase_e str_phase)
{
    int idx, ret;
    for (idx = 0; idx < STR_MODULE_MAX; idx++) {
        if (g_mdm_str_proc_funcs[idx] == NULL) {
            continue;
        }
        ret = g_mdm_str_proc_funcs[idx](str_phase);
        mdm_str_err("idx:%d ret:%d\n", idx, ret);
    }
    mdm_str_err("mdm_str_acpu_proc: phase %d\n", str_phase);
}

static void mdm_str_notify_lpmcu(struct mdm_str_ctrl *ctrl)
{
    int ret;
    struct mdm_str_msg info;
    struct msg_addr dst;

    info.val = ctrl->str_phase;
    info.slice = bsp_get_slice_value();
    dst.chnid = MSG_CHN_MDM_STR;
    dst.core = MSG_CORE_LPM;
    ret = bsp_msg_lite_sendto(ctrl->msg_hdl, &dst, &info, sizeof(info));
    if (ret) {
        mdm_str_err("send msg err %d\n", ret);
    }
    mdm_str_mntn_record(NOTIFY, bsp_get_slice_value());
    mdm_str_err("notify at 0x%x\n", bsp_get_slice_value());
    return;
}

int mdm_str_thread(void *dev)
{
    unsigned long lockflags;
    struct mdm_str_ctrl *ctrl = dev_get_platdata(dev);
    while (!kthread_should_stop()) {
        down(&ctrl->tsk.notice_sem);
        mdm_str_mntn_record(TASK_UP, bsp_get_slice_value());
        mdm_str_acpu_proc(ctrl->str_phase);
        mdm_str_notify_lpmcu(ctrl);
        if (down_timeout(&ctrl->tsk.resp_sem, msecs_to_jiffies(MDM_STR_WAIT_TIME_MS))) {
            mdm_str_mntn_record(RESP_TIMEOUT, bsp_get_slice_value());
            mdm_str_err("notify timeout at 0x%x\n", bsp_get_slice_value());
        }
        mdm_str_mntn_record(RESP_RECV, bsp_get_slice_value());
        spin_lock_irqsave(&(ctrl->state.lock), lockflags);
        if (ctrl->str_phase == PHASE_EXIT_MDM_STR) {
            ctrl->state.str_mode_state = PHASE_EXIT_MDM_STR;
        }
        ctrl->state.str_node_state = mode_covert_drv2user(ctrl->str_phase);
        spin_unlock_irqrestore(&(ctrl->state.lock), lockflags);
        pm_relax(ctrl->dev);
    }

    return 0;
}

ssize_t mdm_str_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    struct mdm_str_ctrl *ctrl = dev_get_platdata(dev);

    ret = sprintf_s(buf, PAGE_SIZE, "%d", ctrl->state.str_node_state);
    if (ret < 0) {
        mdm_str_err("sprintf_s %d fail, ret %d\n", ctrl->state.str_node_state, ret);
        return -ENOMEM;
    }
    return ret;
}

ssize_t mdm_str_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    long mode_val = 0;
    unsigned long lockflags;
    mdm_str_proc_phase_e str_phase;
    struct mdm_str_ctrl *ctrl = dev_get_platdata(dev);

    if (kstrtol(buf, 10U, &mode_val) < 0) {
        return -EIO;
    }

    mdm_str_err("mode_val is %ld, count%lu\n", mode_val, count);
    if (mode_val != MDM_ENTER_STR_MODE && mode_val != MDM_EXIT_STR_MODE) {
        return -EINVAL;
    }

    spin_lock_irqsave(&ctrl->state.lock, lockflags);
    str_phase = mode_covert_user2drv(mode_val);
    if (ctrl->str_phase == str_phase) {
        spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
        mdm_str_err("mode_val %ld is same as the current val\n", mode_val);
        return -EINVAL;
    }
    ctrl->str_phase = str_phase;

    if (ctrl->state.str_node_state == MDM_IN_STR_PROC) {
        spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
        mdm_str_err("now is in str proc\n");
        return -EBUSY;
    }
    mdm_str_mntn_record(NODE_WIRTE, bsp_get_slice_value());
    mdm_str_mntn_record(NODE_VAL, str_phase);
    pm_stay_awake(dev);
    ctrl->state.str_node_state = MDM_IN_STR_PROC;

    if (str_phase == PHASE_ENTER_MDM_STR) {
        ctrl->state.str_mode_state = str_phase;
    }

    if (ctrl->state.reset_state == MDM_NOT_RESET) {
        up(&ctrl->tsk.notice_sem);
    } else {
        mdm_str_err("mdm in reset state: %d\n", ctrl->state.reset_state);
    }

    spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
    return count;
}

static DEVICE_ATTR(state, 0660, mdm_str_show, mdm_str_store);

int bsp_mdm_str_get_status(void)
{
    return g_mdm_str_ctrl.state.str_mode_state;
}

int bsp_mdm_str_before_mdm_reset(void)
{
    unsigned long lockflags;
    struct mdm_str_ctrl *ctrl = &g_mdm_str_ctrl;

    if (!ctrl->inited) {
        mdm_str_err("mdm str is uninited\n");
        return 0;
    }

    spin_lock_irqsave(&ctrl->state.lock, lockflags);
    if (ctrl->state.str_mode_state == PHASE_ENTER_MDM_STR) {
        spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
        system_error(DRV_ERRNO_MDM_STR_IN_RESET, 0, 0, NULL, 0);
        return 1;
    }
    ctrl->state.reset_state = MDM_IN_RESET;
    mdm_str_err("in reset state\n");
    spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
    return 0;
}

int bsp_mdm_str_after_mdm_reset(void)
{
    unsigned long lockflags;
    struct mdm_str_ctrl *ctrl = &g_mdm_str_ctrl;

    if (!ctrl->inited) {
        mdm_str_err("mdm str is uninited\n");
        return 0;
    }

    spin_lock_irqsave(&ctrl->state.lock, lockflags);
    ctrl->state.reset_state = MDM_NOT_RESET;
    if (ctrl->state.str_mode_state == PHASE_ENTER_MDM_STR) {
        up(&ctrl->tsk.notice_sem);
    }
    mdm_str_err("out reset state\n");
    spin_unlock_irqrestore(&ctrl->state.lock, lockflags);
    return 0;
}

void mdm_str_mntn_init(void)
{
    if (sizeof(struct mdm_str_mntn_ctrl) > MDM_STR_DUMP_SIZE) {
        mdm_str_err("size is out of range\n");
        return;
    }

    g_mdm_str_mntn_ctrl = (struct mdm_str_mntn_ctrl *)bsp_dump_register_field(DUMP_MODEMAP_MDM_STR, "MDM_STR", MDM_STR_DUMP_SIZE, 0);
    if (g_mdm_str_mntn_ctrl == NULL) {
        mdm_str_err("regist field fail!\n");
        return;
    }
    (void)memset_s(g_mdm_str_mntn_ctrl, sizeof(struct mdm_str_mntn_ctrl), 0, sizeof(struct mdm_str_mntn_ctrl));
    g_mdm_str_mntn_ctrl->type = 0;
    g_mdm_str_mntn_ctrl->ver = 0;
}

int mdm_str_probe(struct platform_device *pdev)
{
    int ret;
    struct mdm_str_ctrl *ctrl = dev_get_platdata(&pdev->dev);
    struct msgchn_attr attr = {0};
    ctrl->dev = &pdev->dev;

    sema_init(&ctrl->tsk.notice_sem, 0);
    sema_init(&ctrl->tsk.resp_sem, 0);
    spin_lock_init(&ctrl->state.lock);

    mdm_str_mntn_init();
    ret = device_init_wakeup(&pdev->dev, true);
    if (ret) {
        mdm_str_err("wakeup init err %d\n", ret);
        return ret;
    }

    ctrl->tsk.task = kthread_create(mdm_str_thread, &pdev->dev, "mdm_str");
    if (IS_ERR(ctrl->tsk.task)) {
        device_init_wakeup(&pdev->dev, false);
        mdm_str_err("create thread fail\n");
        return PTR_ERR(ctrl->tsk.task);
    }
    wake_up_process(ctrl->tsk.task);

    ret = device_create_file(&pdev->dev, &dev_attr_state);
    if (ret) {
        device_init_wakeup(&pdev->dev, false);
        mdm_str_err("create file err %d\n", ret);
        return ret;
    }

    bsp_msgchn_attr_init(&attr);
    attr.chnid = MSG_CHN_MDM_STR;
    attr.coremask = MSG_CORE_MASK(MSG_CORE_LPM);
    attr.lite_notify = mdm_str_msg_proc;
    ret = bsp_msg_lite_open(&ctrl->msg_hdl, &attr);
    if (ret) {
        mdm_str_err("msg init err %d\n", ret);
        return ret;
    }

    ctrl->inited = 1;
    mdm_str_err("mdm_str_probe ok");
    return 0;
}

static struct platform_device g_mdm_str_dev = {
    .name = "modem_str",
    .id = -1,
    .dev =
        {
            .platform_data = &g_mdm_str_ctrl,
        },
};

static struct platform_driver g_mdm_str_drv = {
    .probe = mdm_str_probe,
    .driver =
        {
            .name = "modem_str",
            .owner = THIS_MODULE,
            .probe_type = PROBE_FORCE_SYNCHRONOUS,
        },
};

int bsp_mdm_str_init(void)
{
    int ret;

    ret = platform_device_register(&g_mdm_str_dev);
    if (ret) {
        mdm_str_err("regist dev err: 0x%x", ret);
        return ret;
    }

    ret = platform_driver_register(&g_mdm_str_drv);
    if (ret) {
        mdm_str_err("regist drv err: 0x%x", ret);
        platform_device_unregister(&g_mdm_str_dev);
        return ret;
    }

    return ret;
}

// mdm_str初始化依赖msg，msg依赖dump，而dump等依赖mdm_str，所以mdm_str初始化放在最后，对外初始化调用的接口保证无依赖
#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
fs_initcall(bsp_mdm_str_init);
#endif