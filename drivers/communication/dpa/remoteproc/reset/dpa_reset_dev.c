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

#include <linux/poll.h>
#include <linux/cdev.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <dpa_reset.h>
#include "dpa_reset_dev.h"
#include "dpa_reset_frame.h"

#define reset_err(fmt, ...) dpa_pr_err("[dpa_reset]"fmt, ##__VA_ARGS__)

static dpa_reset_dev_info_s g_dpa_reset_dev_info = {
    .name = "dpa_reset",
    .dpa_reset_stat = DPA_SYS_READY,
    .flag = 0,
};

static const char *g_dpa_state_str[DPA_SYS_STATE_MAX] = {
    "DPA_STATE_OFF\n",
    "DPA_STATE_READY\n"
};

static int dpa_reset_open(struct inode *inode, struct file *filp)
{
    if (inode == NULL) {
        return -EIO;
    }
    if (filp == NULL) {
        return -ENOENT;
    }
    if (MINOR(g_dpa_reset_dev_info.devt) == iminor(inode)) {
        filp->private_data = &g_dpa_reset_dev_info;
        reset_err("dpa_reset %s:%d init. devt:%d\n", __FUNCTION__, __LINE__, g_dpa_reset_dev_info.devt);
        return 0;
    }
    return 0;
}
static int dpa_reset_release(struct inode *inode, struct file *filp)
{
    if (inode == NULL) {
        return -EIO;
    }
    if (filp == NULL) {
        return -ENOENT;
    }
    return 0;
}
static ssize_t dpa_reset_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
    ssize_t len = 0;
    dpa_reset_dev_info_s *priv = NULL;
    if (filp == NULL) {
        return -ENOENT;
    }
    if (buf == NULL) {
        return -EFAULT;
    }
    if (ppos == NULL) {
        return -EFAULT;
    }
    reset_err("dpa_reset read node. \n");
    priv = (dpa_reset_dev_info_s *)filp->private_data;
    if (priv == NULL) {
        reset_err("dpa_reset %s:%d not init.\n", __FUNCTION__, __LINE__);
        return 0;
    }
    if (priv->dpa_reset_stat >= DPA_SYS_STATE_MAX) {
        reset_err("dpa_reset : %s:%d Invalid state 0x%x.\n", __FUNCTION__, __LINE__,
            priv->dpa_reset_stat);
        return 0;
    }
    if (wait_event_interruptible(priv->wait, priv->flag)) {
        return -ERESTARTSYS;
    }
    priv->flag = 0;
    len = strlen(g_dpa_state_str[priv->dpa_reset_stat]) + 1;
    reset_err("dpa_reset pos:%llu, count:%zu, len:%zd\n", *ppos, count, len);
    if (*ppos > 0) {
        reset_err("dpa_reset ppos is %llu\n", *ppos);
        return 0;
    }
    if (count < len) {
        reset_err("dpa_reset usr count need larger ,count is 0x%zd\n", len);
        return -EFAULT;
    }
    if (copy_to_user(buf, g_dpa_state_str[priv->dpa_reset_stat], len)) {
        reset_err("dpa_reset copy to user fail\n");
        return -EFAULT;
    }
    return len;
}

static unsigned int dpa_reset_poll(struct file *filp, poll_table *wait)
{
    dpa_reset_dev_info_s *priv = NULL;
    unsigned int mask = 0;
    if (filp == NULL) {
        return mask;
    }
    priv = filp->private_data;
    if (priv == NULL) {
        return mask;
    }
    reset_err("dpa_reset wait before\n");
    poll_wait(filp, &priv->wait, wait);
    reset_err("dpa_reset wait after\n");
    if (priv->flag != 0) {
        mask = POLLIN | POLLRDNORM;
        reset_err("dpa_reset read ready\n");
    }

    reset_err("dpa_reset wait after1\n");
    return mask;
}

static struct file_operations dpa_reset_fops = {
    .owner = THIS_MODULE,
    .open = dpa_reset_open,
    .read = dpa_reset_read,
    .release = dpa_reset_release,
    .poll = dpa_reset_poll,
};

static int dpa_reset_set_dpa_state(unsigned int state)
{
    if (state >= DPA_SYS_STATE_MAX) {
        reset_err("set state error, invalid state 0x%x.\n", state);
        return -EINVAL;
    }
    g_dpa_reset_dev_info.dpa_reset_stat = state;
    g_dpa_reset_dev_info.flag = 1;
    wake_up_interruptible(&g_dpa_reset_dev_info.wait);
    reset_err("set state %d. 0x%x.\n", state, bsp_get_slice_value());
    return 0;
}

static int dpa_reset_notify_app(dpa_reset_stage_e stage, int arg)
{
    int ret = 0;
    reset_err("reset notify app enter, stage %d, 0x%x.\n", stage, bsp_get_slice_value());
    if (DPA_RESET_BEFORE == stage) {
        ret = dpa_reset_set_dpa_state(DPA_SYS_NOT_READY);
    } else if (DPA_RESET_AFTER == stage) {
        ret = dpa_reset_set_dpa_state(DPA_SYS_READY);
    } else {
        reset_err("reset no need notify app!\n");
    }
    return ret;
}

int dpa_reset_dev_init(void)
{
    int ret;
    dev_t devt;
    struct device *dev = NULL;
    ret = alloc_chrdev_region(&devt, 0, DPA_RESET_DEV_NUM, "dpa_reset");
    if (ret) {
        reset_err("alloc_chrdev_region error, ret:%d.\n", ret);
        return ret;
    }
    init_waitqueue_head(&g_dpa_reset_dev_info.wait);
    g_dpa_reset_dev_info.devt = MKDEV(MAJOR(devt), 0);
    cdev_init(&g_dpa_reset_dev_info.reset_cdev, &dpa_reset_fops);
    ret = cdev_add(&g_dpa_reset_dev_info.reset_cdev, g_dpa_reset_dev_info.devt, 1);
    if (ret) {
        reset_err("cdev_add err, ret:%d.\n", ret);
        goto region_free;
    }
    g_dpa_reset_dev_info.class = class_create(THIS_MODULE, g_dpa_reset_dev_info.name);
    if (g_dpa_reset_dev_info.class == NULL) {
        reset_err("class create fail\n");
        ret = DPA_RESET_ERR_GEN(DPA_RESET_DEV_CLASS_ERR);
        goto dev_fail_del;
    }
    dev = device_create(g_dpa_reset_dev_info.class, NULL, g_dpa_reset_dev_info.devt, &g_dpa_reset_dev_info, "%s",
        g_dpa_reset_dev_info.name);
    if (IS_ERR(dev)) {
        reset_err("device_create err\n");
        ret = DPA_RESET_ERR_GEN(DPA_RESET_DEV_DEVICE_ERR);
        goto create_fail;
    }

    ret = bsp_dpa_reset_register_cb("app_notify", dpa_reset_notify_app, 0, DPA_RESET_CB_LEVEL_APP);
    if (ret) {
        dpa_pr_err("reset dev reset register failed, ret:0x%x.\n", ret);
        goto create_fail;
    }
    return 0;

create_fail:
    class_destroy(g_dpa_reset_dev_info.class);
dev_fail_del:
    cdev_del(&g_dpa_reset_dev_info.reset_cdev);
region_free:
    unregister_chrdev_region(devt, DPA_RESET_DEV_NUM);

    return ret;
}
