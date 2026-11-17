/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <bsp_print.h>
#include <bsp_udx.h>
#include "udx_service.h"

#define DEVICE_NAME "udx_device"
#define CLASS_NAME "udx"
#define MAX_UDX_DEV_SIZE 256
#define MAX_UDX_SERVICE_SIZE 32

struct udx_cdev_cmn
{
    dev_t devt;
    struct class* udx_class;
};

struct udx_cdev_ctx
{
    struct udx_cdev_cmn cmn;
    struct cdev *udx_dev;
    struct cdev *udx_service[MAX_UDX_SERVICE_SIZE];
    int service_count;
};

static struct udx_cdev_ctx *g_udx_cdev_ctx = NULL;
static struct udx_cdev_ctx *get_udx_cdev_ctx(void)
{
    if (g_udx_cdev_ctx == NULL) {
        g_udx_cdev_ctx = kzalloc(sizeof(struct udx_cdev_ctx), GFP_KERNEL);
    }
    return g_udx_cdev_ctx;
}

int ioctl_count = 0;
int ioctl_succeed = 0;
int read_count = 0;

static ssize_t udx_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
    ssize_t ret;
    void *user_arg;

    if(*ppos > 0) {
        return -EINVAL;
    }

    if (count < sizeof(struct udx_ioctl_base) || count > sizeof(struct udx_dev_ioctl_add_param)) {
        return -EINVAL;
    }

    user_arg = kmalloc(count, GFP_KERNEL);
    if (user_arg == NULL) {
        return -ENOMEM;
    }

    if (copy_from_user(user_arg, buffer, count)) {
        kfree(user_arg);
        return -EFAULT;
    }

    switch (((struct udx_ioctl_base *)user_arg)->type) {
        case UDX_IOCTL_ADD_SERVICE:
            if (((struct udx_ioctl_base *)user_arg)->size != sizeof(struct udx_dev_ioctl_add_service)
                || count != sizeof(struct udx_dev_ioctl_add_service)) {
                ret = -EINVAL;
                break;
            }
            ((struct udx_dev_ioctl_add_service *)user_arg)->name[UDX_NAME_MAX_LEN - 1] = 0;
            udx_service_add_by_name(((struct udx_dev_ioctl_add_service *)user_arg)->name);
            ret = count;
            break;
        case UDX_IOCTL_ADD_PARAMS:
            if (((struct udx_ioctl_base *)user_arg)->size != sizeof(struct udx_dev_ioctl_add_param)
                || count != sizeof(struct udx_dev_ioctl_add_param)) {
                ret = -EINVAL;
                break;
            }
            ((struct udx_dev_ioctl_add_param *)user_arg)->param_name[UDX_NAME_MAX_LEN - 1] = 0;
            ((struct udx_dev_ioctl_add_param *)user_arg)->service_name[UDX_NAME_MAX_LEN - 1] = 0;
            udx_service_add_param_int(((struct udx_dev_ioctl_add_param *)user_arg)->service_name,
                ((struct udx_dev_ioctl_add_param *)user_arg)->param_name,
                ((struct udx_dev_ioctl_add_param *)user_arg)->value);
            ret = count;
            break;
        default:
            ret = -EINVAL;
            break;
    }

    kfree(user_arg);
    return ret;
}

static struct file_operations dev_fops =
{
    .open = 0,
    .release = 0,
    .write = udx_write,
};

int udx_common_init(struct udx_cdev_cmn *cmn)
{
    alloc_chrdev_region(&cmn->devt, 0, MAX_UDX_DEV_SIZE, "udx");
    cmn->udx_class = class_create(THIS_MODULE, CLASS_NAME);
    if (IS_ERR(cmn->udx_class)) {
        return -1;
    }
    return 0;
}

struct device *udx_cdev_create(struct cdev *cdev, char *name, void *priv)
{
    struct device *dev;
    struct udx_cdev_ctx *ctx = get_udx_cdev_ctx();
    struct udx_cdev_cmn *cmn = &ctx->cmn;
    dev_t devt = cmn->devt + 1;

    if (cdev_add(cdev, devt, 1)) {
        return NULL;
    }

    dev = device_create(cmn->udx_class, NULL, devt, priv, "%s", name);
    if (IS_ERR(dev)) {
        return NULL;
    }

    cmn->devt = devt;

    return dev;
}

void udx_cdev_del(struct cdev *cdev)
{
    struct udx_cdev_ctx *ctx = get_udx_cdev_ctx();
    struct udx_cdev_cmn *cmn = &ctx->cmn;

    device_destroy(cmn->udx_class, cdev->dev);

    cdev_del(cdev);
}

int udx_create_device(void)
{
    struct cdev *cd;
    struct device *dev;

    cd = cdev_alloc();
    if (cd == NULL) {
        dpa_pr_err("[%s] Failed to alloc cdev", __func__);
        return -1;
    }
    cdev_init(cd, &dev_fops);

    dev = udx_cdev_create(cd, DEVICE_NAME, NULL);
    if (dev == NULL) {
        cdev_del(cd);
        dpa_pr_err("[%s] Failed to create device", __func__);
        return -1;
    }
    return 0;
}

int udx_dev_init(void)
{
    struct udx_cdev_ctx *ctx = get_udx_cdev_ctx();

    if (udx_common_init(&ctx->cmn)) {
        dpa_pr_err("[%s] Failed to init common", __func__);
        return -1;
    }

    if (udx_create_device()) {
        dpa_pr_err("[%s] Failed to create device", __func__);
        return -1;
    }

    return 0;
}

