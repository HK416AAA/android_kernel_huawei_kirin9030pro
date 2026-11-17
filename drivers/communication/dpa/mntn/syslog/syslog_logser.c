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
#include <securec.h>
#include <linux/slab.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/suspend.h>
#include <linux/uaccess.h>
#include <linux/poll.h>
#include <linux/err.h>
#include <bsp_slice.h>
#include "syslog_ring_buffer.h"
#include "syslog_logser.h"
#include "syslog_user.h"
#include "syslog_dmi.h"

static LIST_HEAD(g_dpa_syslog_logser_list);
struct syslog_logser_ctrl g_dpa_syslog_logser_ctrl;

/*lint --e{64,826,785,528}*/
/* 64&826:list_for_each_entry, 785 Too few initializers for struct define; 528: module_init */
static struct logger_log *dpa_syslog_logser_from_name(const char *name)
{
    struct logger_log *log = NULL;

    list_for_each_entry(log, &g_dpa_syslog_logser_list, logs) {
        if (!strncmp(log->misc.name, name, DPA_SYSLOG_DEV_NAME_LEN)) {
            return log;
        }
    }

    return NULL;
}

struct logger_log *dpa_syslog_logser_from_minor(int minor)
{
    struct logger_log *log = NULL;

    list_for_each_entry(log, &g_dpa_syslog_logser_list, logs)
    {
        if (log->misc.minor == minor) {
            return log;
        }
    }

    return NULL;
}
EXPORT_SYMBOL(dpa_syslog_logser_from_minor);

static void dpa_syslog_logser_ring_buffer_get(struct log_usr_info *usr_info, struct dpa_ring_buffer *rb)
{
    int ret;
    if ((usr_info != NULL) && (usr_info->mem != NULL)) {
        rb->buf = usr_info->ring_buf;
        // 使用本核的读指针
        rb->read = usr_info->mem_local.read;
        rb->write = usr_info->mem->write;
        rb->size = usr_info->mem_local.size;
    } else {
        ret = memset_s((void *)rb, sizeof(struct dpa_ring_buffer), 0, sizeof(struct dpa_ring_buffer));
        if (ret) {
            syslog_pr_err("rb memset ret = %d\n", ret);
        }
    }
}

static unsigned int dpa_syslog_logser_poll(struct file *file, poll_table *wait)
{
    struct logger_log *log = NULL;
    unsigned int ret = 0;
    u32 read = 0;
    u32 write = 0;
    syslog_pr_debug("%s entry\n", __func__);
    if (!(file->f_mode & FMODE_READ)) {
        return ret;
    }

    log = file->private_data;
    if (unlikely(log == NULL)) { /*lint !e730: (Info -- Boolean argument to function)*/
        syslog_pr_err("device poll fail\n");
        return -ENODEV;
    }
    syslog_pr_debug("%s entry2\n", __func__);
    if (log->usr_info != NULL && log->usr_info->mem != NULL) {
        // 使用本核的读指针
        read = log->usr_info->mem_local.read;
        write = log->usr_info->mem->write;
        mutex_lock(&log->mutex);
        if (read != write) {
            ret = POLLIN | POLLRDNORM;
            if (log->usr_info->mem_local.app_is_active != SYSLOG_ACTIVE_MAGIC) {
                // 为防止异常情况下open和release不匹配，当有数据时，再次置上标记位
                log->usr_info->mem_local.app_is_active = SYSLOG_ACTIVE_MAGIC; /* reader is ready  */
            }
        }
        mutex_unlock(&log->mutex);
    }

    if (!ret) {
        poll_wait(file, &log->wq, wait);
    }
    syslog_pr_debug("%s exit\n", __func__);

    return ret;
}

static ssize_t dpa_syslog_logser_cpy_rb_to_user(struct logger_log *log, struct dpa_ring_buffer *rb, char __user *buf, size_t count)
{
    size_t len, left, cpy_len;
    ssize_t ret = 0;
    if (buf == NULL) {
        syslog_pr_err("dpa_syslog_logser_cpy_rb_to_user buf is NULL\n");
        return -1;
    }
    mutex_lock(&log->mutex);
    len = syslog_ring_buffer_readable_size(rb);
    len = min(len, count);
    if (len == 0) {
        goto out;
    }

    left = min(len, (size_t)(rb->size - rb->read));
    cpy_len = copy_to_user(buf, (rb->buf + rb->read), left);
    if (cpy_len != 0) {
        syslog_pr_err("copy_to_user err\n");
        ret = -1;
        goto out;
    }

    if ((len > left) && ((len - left) < count)) {
        cpy_len = copy_to_user((buf + left), rb->buf, (len - left));
        if (cpy_len != 0) {
            syslog_pr_err("copy_to_user left err\n");
            ret = -1;
            goto out;
        }
    }
    rb->read += (u32)len;
    rb->read %= (rb->size);

    ret = (ssize_t)len;
    // 更新本核的读指针
    log->usr_info->mem_local.read = rb->read;
out:
    mutex_unlock(&log->mutex);
    return ret;
}
static int dpa_syslog_logser_check_mem(struct logger_log *log)
{
    if (log->usr_info == NULL || log->usr_info->mem == NULL) {
        return -ENODEV;
    }
    if (!log->usr_info->mem_is_ok) {
        return -ENODEV;
    }
    if (log->usr_info->mem->magic != log->usr_info->mem_local.magic) {
        return -ENOMEM;
    }
    if (log->usr_info->mem_local.size >= DPA_SYSLOG_MAX_SIZE) {
        return -ENOMEM;
    }
    if (log->usr_info->mem->write >= log->usr_info->mem_local.size) {
        return -ENOMEM;
    }
    // 使用本核的读指针
    if (log->usr_info->mem_local.read >= log->usr_info->mem_local.size) {
        return -ENOMEM;
    }
    return 0;
}
/*
 * dpa_syslog_logser_read - our log's read() method
 * 1) O_NONBLOCK works
 * 2) If there are no log to read, blocks until log is written to
 *  3) Will set errno to EINVAL if read
 */
static ssize_t dpa_syslog_logser_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{ /*lint --e{715} suppress pos not referenced*/
    struct logger_log *log = (struct logger_log *)file->private_data;
    struct dpa_ring_buffer rb = { 0 };
    ssize_t ret = 1;

    if (log == NULL) { /*lint !e730: (Info -- Boolean argument to function)*/
        syslog_pr_err("device read fail\n");
        return -ENODEV;
    }
    mutex_lock(&log->mutex);
    ret = dpa_syslog_logser_check_mem(log);
    if (ret) {
        mutex_unlock(&log->mutex);
        goto read_out;
    }
    dpa_syslog_logser_ring_buffer_get(log->usr_info, &rb);

    ret = dpa_is_ring_buffer_empty(&rb);

    if (ret == 0 && log->usr_info->read_func != NULL && log->usr_info->read_func(log->usr_info, buf, (u32)count) != 0) {
        mutex_unlock(&log->mutex);
        syslog_pr_debug("[dpa log]user(%s) read method invoked\n", log->usr_info->dev_name);
        ret = -ENOMEM;
        goto read_out;
    }
    mutex_unlock(&log->mutex);
    if (!ret) { /* has data to be read, break out */
        goto read_out;
    }
    if (file->f_flags & O_NONBLOCK) {
        ret = -EAGAIN;
        goto read_out;
    }

    if (signal_pending(current)) {
        ret = -EINTR;
        goto read_out;
    }
read_out:
    if (ret) {
        // nodata to read
        return 0;
    }
    return dpa_syslog_logser_cpy_rb_to_user(log, &rb, buf, count);
}

/*
 * dpa_syslog_logser_open - our log's open() method, not support open twice by same application
 */
static int dpa_syslog_logser_open(struct inode *inode, struct file *file)
{
    struct logger_log *log = dpa_syslog_logser_from_minor(MINOR(inode->i_rdev));
    if (unlikely(log == NULL)) { /*lint !e730: (Info -- Boolean argument to function)*/
        syslog_pr_err("device get fail\n");
        return -ENODEV;
    }

    file->private_data = log;

    mutex_lock(&log->mutex);

    if (log->usr_info != NULL) {
        log->usr_info->mem_local.app_is_active = SYSLOG_ACTIVE_MAGIC; /* reader is ready  */
    }
    if (log->fopen_cnt != 0) {
        // chr服务会重新进入，导致重复打开
        mutex_unlock(&log->mutex);
        syslog_pr_err("file_open_cnt=%d\n", log->fopen_cnt);
        return -EBUSY;
    }
    log->fopen_cnt = 1;

    mutex_unlock(&log->mutex);
    /* indicate that application exit exceptionally, need to clear ring buffer */

    // 发送dmi，通知fw
    syslog_dmi_sever_switch_init();

    syslog_pr_err("%s entry\n", __func__);

    return 0;
}

/*
 * dpa_syslog_logser_release - our log's close() method
 */
static int dpa_syslog_logser_release(struct inode *inode, struct file *file)
{ /*lint --e{715} suppress inode not referenced*/
    struct logger_log *log = file->private_data;

    if (unlikely(log == NULL)) { /*lint !e730: (Info -- Boolean argument to function)*/
        syslog_pr_err("device release fail\n");
        return -ENODEV;
    }
    if (log->usr_info != NULL) {
        mutex_lock(&log->mutex);
        if (log->usr_info->close_func && log->usr_info->close_func(log->usr_info)) {
            syslog_pr_err("user(%s) release method error, exit\n", log->usr_info->dev_name);
        }
        if (log->fopen_cnt) {
            log->fopen_cnt--;
        }
        // 实测会存在异常退出的情况，导致open和release不匹配
        // 此标记只能用来判断是否水线触发，不影响poll。
        // 因此，为防止没有及时设置标记，导致误触发水线，这里默认设置成SYSLOG_INVALID_MAGIC，在poll函数中，设置成SYSLOG_ACTIVE_MAGIC
        log->usr_info->mem_local.app_is_active = SYSLOG_INVALID_MAGIC; /* reader cannot work  */
        mutex_unlock(&log->mutex);
    }
    syslog_pr_err("%s entry\n", __func__);
    return 0;
}

static const struct file_operations g_syslog_fops = {
    .read = dpa_syslog_logser_read,
    .poll = dpa_syslog_logser_poll,
    .open = dpa_syslog_logser_open,
    .release = dpa_syslog_logser_release,
};
static int dpa_syslog_logser_check_state_is_ok(struct log_usr_info *usr_info)
{
    if (usr_info == NULL) {
        return -ENODEV;
    }
    // 使用本核的读指针
    if (usr_info->mem != NULL && usr_info->mem_is_ok &&
        usr_info->mem_local.app_is_active == SYSLOG_ACTIVE_MAGIC &&
        usr_info->mem_local.read != usr_info->mem->write) {
        return 0;
    }
    return -ENOMEM;
}
/*
 * dpa_syslog_logser_wakeup_all - wake up all waitquque
 */
static void dpa_syslog_logser_wakeup_all(void)
{
    struct logger_log *log = NULL;
    list_for_each_entry(log, &g_dpa_syslog_logser_list, logs)
    {
        if (dpa_syslog_logser_check_state_is_ok(log->usr_info)) {
            continue;
        }
        wake_up_interruptible(&log->wq);
    }
}
void bsp_dpa_syslog_logser_wakeup_one(struct log_usr_info *usr_info)
{
    struct logger_log *log = NULL;

    if (usr_info == NULL) {
        return;
    }
    log = dpa_syslog_logser_from_name(usr_info->dev_name);
    if (log == NULL) {
        return;
    }
    /* if reader is not ready, no need to wakeup waitqueue */
    if (dpa_syslog_logser_check_state_is_ok(usr_info)) {
        return;
    }
    wake_up_interruptible(&log->wq);
}
EXPORT_SYMBOL(bsp_dpa_syslog_logser_wakeup_one);

/*
 * dpa_syslog_logser_notify - dpa log pm notify
 */
static s32 dpa_syslog_logser_notify(struct notifier_block *notify_block, unsigned long mode, void *unused)
{ /*lint --e{715} suppress notify_block&unused not referenced*/
    struct logger_log *log = NULL;

    syslog_pr_debug("entry\n");

    switch (mode) {
        case PM_POST_HIBERNATION:
            list_for_each_entry(log, &g_dpa_syslog_logser_list, logs)
            {
                if (dpa_syslog_logser_check_state_is_ok(log->usr_info)) {
                    continue;
                }
                wake_up_interruptible(&log->wq);
            }
            break;
        default:
            break;
    }

    return 0;
}

/*
 * bsp_dpa_syslog_logser_register - tell dpa log which user information is
 * @usr_info: information which dpa log need to know
 * Returns 0 if success
 */
s32 bsp_dpa_syslog_logser_register(struct log_usr_info *usr_info)
{
    s32 ret = 0;
    struct logger_log *log = NULL;

    if (unlikely(usr_info == NULL)) { /*lint !e730: (Info -- Boolean argument to function)*/
        ret = (s32)DPA_SYSLOG_NO_USR_INFO;
        syslog_pr_err("no user info to register\n");
        goto out;
    }
    log = kzalloc(sizeof(struct logger_log), GFP_KERNEL);
    if (log == NULL) {
        ret = (s32)DPA_SYSLOG_NO_MEM;
        goto out;
    }

    log->usr_info = usr_info;

    log->misc.minor = MISC_DYNAMIC_MINOR;
    log->misc.name = kstrdup(usr_info->dev_name, GFP_KERNEL);
    if (unlikely(log->misc.name == NULL)) { /*lint !e730: (Info -- Boolean argument to function)*/
        ret = (s32)DPA_SYSLOG_NO_MEM;
        goto out_free_log;
    }

    log->misc.fops = &g_syslog_fops;
    log->misc.parent = NULL;
    init_waitqueue_head(&log->wq);
    mutex_init(&log->mutex);
    INIT_LIST_HEAD(&log->logs);
    list_add_tail(&log->logs, &g_dpa_syslog_logser_list);
    /* finally, initialize the misc device for this log */
    ret = misc_register(&log->misc);
    if (unlikely(ret)) { /*lint !e730: (Info -- Boolean argument to function)*/
        syslog_pr_err("failed to register misc device for log '%s'!\n", log->misc.name); /*lint !e429*/
        goto out_rm_node;
    }
    syslog_pr_err("created log '%s'\n", log->misc.name);
    return 0; /*lint !e429*/
out_rm_node:
    syslog_pr_err("user info to register err\n");
    list_del(&log->logs);
    kfree(log->misc.name);
    log->misc.name = NULL;
out_free_log:
    kfree(log);
    log = NULL;
out:
    return ret;
}


/*
 * dpa_syslog_logser_fwrite_trigger_force - wakeup acore and trigger file write from ring buffer to log record file
 */
void dpa_syslog_logser_fwrite_trigger_force(void)
{
    dpa_syslog_logser_wakeup_all();
}
EXPORT_SYMBOL(dpa_syslog_logser_fwrite_trigger_force); /*lint !e19 */

int dpa_syslog_logser_init(void)
{
    g_dpa_syslog_logser_ctrl.pm_notify.notifier_call = dpa_syslog_logser_notify;
    register_pm_notifier(&g_dpa_syslog_logser_ctrl.pm_notify);
    g_dpa_syslog_logser_ctrl.init_flag = 1;
    syslog_pr_err("init ok\n");

    return 0;
}
