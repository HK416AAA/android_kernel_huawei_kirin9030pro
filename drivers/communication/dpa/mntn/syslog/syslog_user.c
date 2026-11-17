/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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

/*
 * 1 头文件包含
 */
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/semaphore.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/platform_device.h>
#include <linux/suspend.h>
#include <linux/pm_wakeup.h>
#include <linux/pm.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_print.h>
#include <securec.h>
#include "syslog_user.h"
#include "syslog_logser.h"
#include "syslog_dmi.h"
struct log_usr_info g_syslog_user_dev[SYSLOG_DPA_DEV_INFO_MAX];
struct syslog_user_info_ctrl g_syslog_user_dev_ctrl;

static inline u32 syslog_writable_size_get(u32 write, u32 read, u32 ring_buffer_size)
{
    return (read > write) ? (read - write) : (ring_buffer_size - write + read);
}

static int syslog_read_data_to_user(const char *src, char *dst, u32 len)
{
    u32 ret;
    if (dst == NULL || len == 0) {
        return 0;
    }
    ret = (u32)copy_to_user(dst, src, len);
    /* 返回未能拷贝的数据长度 */
    return (int)(len - ret);
}

static int syslog_read(struct log_usr_info *usr_info, char *buf, u32 count)
{
    s32 ret = 0;
    u32 msg_len = 0;
    u32 write_p, read_p;
    if (usr_info == NULL || usr_info->mem == NULL) {
        return ret;
    }
    write_p = usr_info->mem->write;
    // 用本核的读指针作为判断标准，以防DUMP被踩导致有问题
    read_p = usr_info->mem_local.read;
    
    if (write_p >= usr_info->mem_local.size || read_p >= usr_info->mem_local.size) {
        return ret;
    }

    if (syslog_writable_size_get(write_p, read_p, usr_info->mem_local.size) <= LOG_BUFFER_FULL_THRESHOLD) {
        // 只更新本核的读指针，不修改DUMP内存中的读指针，防止两个核都在写，导致冲突
        usr_info->mem_local.read = write_p;
        msg_len = (u32)strlen(LOG_DROPPED_MESSAGE);
        count = min(msg_len, count);
        ret = syslog_read_data_to_user(LOG_DROPPED_MESSAGE, buf, count);
    }
    return ret;
}

int syslog_user_init(void)
{
    u32 i;
    for (i = 0; i < SYSLOG_DPA_DEV_INFO_MAX; i++) {
        spin_lock_init(&g_syslog_user_dev_ctrl.lock[i]);
    }
    g_syslog_user_dev_ctrl.state = SYSLOG_USER_DATA_INFO_STATE_OK;
    dpa_pr_err("syslog_user_init ok\n");
    return 0;
}
// 考虑单独复位，得加锁保护
// 在DPA HOST和DPA FW初始化时会调用
int syslog_user_dev_register(unsigned int index, struct log_mem_stru *data)
{
    unsigned long flags;
    struct log_usr_info *log_info;
    if (g_syslog_user_dev_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return -1;
    }
    if (index >= SYSLOG_DPA_DEV_INFO_MAX || data == NULL) {
        return -1;
    }
    dpa_pr_err("syslog_user_dev_register enter %u\n", index);
    log_info = &g_syslog_user_dev[index];
    if (log_info->mem != NULL && log_info->mem_is_ok) {
        dpa_pr_err("syslog_user_dev_register again %u\n", index);
        return 0;
    }
    spin_lock_irqsave(&g_syslog_user_dev_ctrl.lock[index], flags);
    switch (index) {
        case(SYSLOG_DPA_FW_PRINT_INFO):
            log_info->dev_name = DPA_FW_SYSLOG_DEV_NAME;
            break;
        case(SYSLOG_DPA_FW_RECORD_INFO):
            log_info->dev_name = DPA_FW_RECORD_DEV_NAME;
            break;
        case(SYSLOG_DPA_HOST_RECORD_INFO):
            log_info->dev_name = DPA_HOST_RECORD_DEV_NAME;
            break;
        default:
            break;
    }
    log_info->mem = (struct log_mem *)&data->log_info;
    log_info->ring_buf = (char *)log_info->mem + sizeof(struct log_mem_stru);
    log_info->mem_is_ok = 1;

    // 防止DUMP内存被踩
    log_info->mem_local.magic = data->log_info.magic;
    log_info->mem_local.write = data->log_info.write;
    log_info->mem_local.read = data->log_info.read;
    log_info->mem_local.size = data->log_info.size;
    // log_info->mem_local.app_is_active不能在此处赋值，只能在设备open时赋值

    log_info->read_func = (USR_READ_FUNC)syslog_read;
    spin_unlock_irqrestore(&g_syslog_user_dev_ctrl.lock[index], flags);
    return 0;
}
// 考虑单独复位，得加锁保护
// 在DPA 单独复位的Before流程中会调用
int syslog_user_dev_unregister(unsigned int index)
{
    unsigned long flags;
    if (g_syslog_user_dev_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return -1;
    }
    if (index >= SYSLOG_DPA_DEV_INFO_MAX || g_syslog_user_dev[index].mem == NULL) {
        return -1;
    }
    spin_lock_irqsave(&g_syslog_user_dev_ctrl.lock[index], flags);
    g_syslog_user_dev[index].mem_is_ok = 0;
    spin_unlock_irqrestore(&g_syslog_user_dev_ctrl.lock[index], flags);
    return 0;
}
int syslog_user_dev_init_one(unsigned int index, struct log_mem_stru *data)
{
    int ret;
    if (syslog_user_dev_register(index, data)) {
        return -1;
    }
    dpa_pr_err("syslog_user_dev_register %u\n", index);
    ret = bsp_dpa_syslog_logser_register(&g_syslog_user_dev[index]);
    dpa_pr_err("syslog_user_dev_register out %u\n", index);
    return ret;
}
int syslog_user_dev_init(void)
{
    int ret0, ret1;

    dpa_syslog_logser_init();

	ret0 = syslog_user_dev_init_one(SYSLOG_DPA_FW_PRINT_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_DMESG));
	ret1 = syslog_user_dev_init_one(SYSLOG_DPA_FW_RECORD_INFO, (struct log_mem_stru *)(uintptr_t)bsp_dpa_dump_get_field_addr(OM_DPAFW_RECORD));
    if (ret0 && ret1) {
        // 没有一个设备注册成功
        dpa_pr_err("syslog_user_dev_init err\n");
        return -1;
    }
    return 0;
}

void syslog_info_show(void)
{
    u32 i;
    for (i = 0; i < SYSLOG_DPA_DEV_INFO_MAX; i++) {
        if (g_syslog_user_dev[i].mem == NULL || g_syslog_user_dev[i].dev_name == NULL) {
            continue;
        }
        dpa_pr_err("dev_name: %s\n", g_syslog_user_dev[i].dev_name);
        dpa_pr_err("mem_is_ok: %x\n", g_syslog_user_dev[i].mem_is_ok);
        dpa_pr_err("mem->magic: %x\n", g_syslog_user_dev[i].mem->magic);
        dpa_pr_err("mem->write: %x\n", g_syslog_user_dev[i].mem->write);
        dpa_pr_err("mem->read: %x\n", g_syslog_user_dev[i].mem->read);
        dpa_pr_err("mem_local.size: %x\n", g_syslog_user_dev[i].mem_local.size);
        dpa_pr_err("mem->app_is_active: %x\n", g_syslog_user_dev[i].mem->app_is_active);
        dpa_pr_err("mem_local.magic: %x\n", g_syslog_user_dev[i].mem_local.magic);
        dpa_pr_err("mem_local.write: %x\n", g_syslog_user_dev[i].mem_local.write);
        dpa_pr_err("mem_local.read: %x\n", g_syslog_user_dev[i].mem_local.read);
        dpa_pr_err("mem_local.size: %x\n", g_syslog_user_dev[i].mem_local.size);
        dpa_pr_err("mem_local.app_is_active: %x\n", g_syslog_user_dev[i].mem_local.app_is_active);
    }
}