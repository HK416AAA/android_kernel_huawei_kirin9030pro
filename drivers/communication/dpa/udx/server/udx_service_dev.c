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
#include <bsp_print.h>
#include <bsp_udx.h>
#include <bsp_print.h>
#include "udx_dev.h"
#include "udx_channel.h"

#define DEVICE_NAME "udx_service"
#define CLASS_NAME "udx"

static long udx_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    struct udx_service_alloc_channel buf;

    switch (cmd) {
        case UDX_CHANNEL_ALLOC:
            if (copy_from_user(&buf, (void __user *)arg, sizeof(buf))) {
                return -EFAULT;
            }
            if (buf.base.size != sizeof(buf)) {
                return -EINVAL;
            }
            if (buf.base.type != UDX_CHANNEL_ALLOC) {
                return -EINVAL;
            }
            buf.name[UDX_NAME_MAX_LEN - 1] = '\0';
            return channel_alloc_file(buf.name);
        default:
            return -ENOTTY;
    }
    return 0;
}

static struct file_operations service_fops =
{
    .unlocked_ioctl = udx_unlocked_ioctl,
};

int udx_service_dev_init(struct file_operations *fops)
{
    struct cdev *cd;
    struct device *dev;

    cd = cdev_alloc();
    if (cd == NULL) {
        dpa_pr_err("[%s] Failed to alloc cdev", __func__);
        return -1;
    }
    cdev_init(cd, &service_fops);
    dev = udx_cdev_create(cd, DEVICE_NAME, NULL);
    if (dev == NULL) {
        cdev_del(cd);
        dpa_pr_err("[%s] Failed to create device", __func__);
        return -1;
    }

    return 0;
}
