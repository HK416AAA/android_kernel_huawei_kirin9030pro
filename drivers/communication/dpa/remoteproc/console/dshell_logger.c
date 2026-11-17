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

#include <linux/module.h>
#include <linux/init.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/sysfs.h>
#include <linux/kallsyms.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <linux/sched.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include <linux/wait.h>
#include "dshell_console.h"

#include <linux/kernel.h>


#undef THIS_MODU
#define THIS_MODU mod_dshell
#define LOGGER_LOG_DSHELL "dshell_log"

#define TMP_BUFF_SIZE 128

wait_queue_head_t g_read_waitq;
int dshell_legal_chr(char chr)
{
    if (chr >= 0x20 && chr <= 0x7E) { /* visible character */
        return 1;
    }
    if (chr == '\r' || chr == '\n' || chr == 0x8 || /* backspace */
        chr == 0x7F ||                              /* del */
        chr == 0x1B || /* esc(1b) for up(1b 5b 41)/down(1b 5b 42)/left(1b 5b 44)/right(1b 5b 43) */
        chr == 0x4 ||  /* ctrl+d */
        chr == '\t') {
        return 1;
    }

    return 0;
}

static ssize_t dshell_con_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
    int len = 0;
    int ret;
    static unsigned char g_tmpbuf[TMP_BUFF_SIZE] = { 0, };
    size_t read_len = min(count, sizeof(g_tmpbuf));

    if (kfifo_is_empty(g_dshell_ap.logbuf)) {
        ret = wait_event_interruptible(g_read_waitq, !kfifo_is_empty(g_dshell_ap.logbuf));
        if (ret) {
            dshell_port_err("wait_event_interruptible failed ret = %d\n", ret);
            if (ret == -ERESTARTSYS)
                return -ERESTARTSYS;
            return ret;
        }
    }
    len = g_dshell_ap.logbuff_out(g_dshell_ap.logbuf, g_tmpbuf, read_len);
    if (copy_to_user(usr_buf, g_tmpbuf, len)) {
        dshell_port_err("copy to user failed\n");
        return -EFAULT;
    }
    return len;
}

static ssize_t dshell_con_write(struct file *filp, const char __user *user_buffer, size_t len, loff_t *offset)
{
    ssize_t ret;
    int cnt;
    char *kbuf = NULL;
    if (len > (1U << CMD_BUF_SHIFT)) {
        return -EFAULT;
    }

    kbuf = vmalloc(len);
    if (!kbuf) {
        return -EFAULT;
    }

    if (copy_from_user(kbuf, user_buffer, len)) {
        goto out;
    }

    for (cnt = 0; cnt < len; cnt++) {
        if (!dshell_legal_chr(kbuf[cnt])) {
            dshell_port_err("illegal character %c\n", kbuf[cnt]);
            goto out;
        }
    }
    ret = g_dshell_ap.cmdbuff_in(&g_dshell_ap, (unsigned char *)kbuf, len);
    if (ret < 0) {
        dshell_port_err("dshell cmd in fail, ret = %zd\n", ret);
        goto out;
    }
    vfree(kbuf);
    return len;

out:
    vfree(kbuf);
    return -EFAULT;
}

static int dshell_con_open(struct inode *inode, struct file *file)
{
    dshell_port_info(KERN_INFO "dshell opened\n");
    return 0;
}

static int dshell_con_release(struct inode *inode, struct file *file)
{
    dshell_port_info(KERN_INFO "dshell closed\n");
    return 0;
}

static const struct file_operations g_dshell_dev_fops = {
    .read = dshell_con_read,
    .open = dshell_con_open,
    .write = dshell_con_write,
    .release = dshell_con_release,
};

int dshell_con_dev_register(struct dshell_info* dshell_info_p)
{
    int ret;
    dshell_info_p->misc.minor = MISC_DYNAMIC_MINOR;
    dshell_info_p->misc.name = kstrdup("dshelldev", GFP_KERNEL);
    if (dshell_info_p->misc.name == NULL) {
        ret = EINVAL;
        goto out;
    }

    dshell_info_p->misc.fops = &g_dshell_dev_fops;
    dshell_info_p->misc.parent = NULL;

    ret = misc_register(&dshell_info_p->misc);
    if (ret) {
        dshell_port_err("failed to register misc device for dshell");
        goto out_free_name;
    }

    dshell_port_print("created misc dev %s.\n", dshell_info_p->misc.name);
    return 0;

out_free_name:
    kfree(dshell_info_p->misc.name);
    dshell_info_p->misc.name = NULL;
out:
    return ret;
}


int dshell_logger_init(void)
{
    int ret;

    init_waitqueue_head(&g_read_waitq);

    ret = dshell_con_dev_register(&g_dshell_ap);
    if (ret) {
        dshell_port_err("dshell con register failed\n");
    }

    dshell_port_print("DSHELL INIT OK\n");

    return 0;
}
