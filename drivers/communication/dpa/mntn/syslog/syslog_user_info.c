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
#include "syslog_file.h"
#include "syslog_task.h"
#include "syslog_dmi.h"
#include "syslog_output.h"
#include "syslog_user.h"

struct syslog_user_mem_info g_syslog_user_info[SYSLOG_FILE_TYPE_CNT];
struct syslog_user_info_ctrl g_syslog_user_info_ctrl;

void syslog_user_info_init(void)
{
    u32 i;
    for (i = 0; i < SYSLOG_FILE_TYPE_CNT; i++) {
        spin_lock_init(&g_syslog_user_info_ctrl.lock[i]);
    }
    g_syslog_user_info_ctrl.state = SYSLOG_USER_DATA_INFO_STATE_OK;
}
// 考虑单独复位，得加锁保护
// 在DPA HOST和DPA FW初始化时会调用
int syslog_user_info_register(unsigned int index, struct log_mem_stru *data)
{
    unsigned long flags;
    if (g_syslog_user_info_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return -1;
    }
    if (index >= SYSLOG_FILE_TYPE_CNT || data == NULL) {
        return -1;
    }
    dpa_pr_err("syslog_user_info_register %u\n", index);
    spin_lock_irqsave(&g_syslog_user_info_ctrl.lock[index], flags);
    g_syslog_user_info[index].log_info.magic = data->log_info.magic;
    g_syslog_user_info[index].log_info.size = data->log_info.size;
    g_syslog_user_info[index].log_info.write = data->log_info.write;
    g_syslog_user_info[index].log_info.app_is_active = SYSLOG_ACTIVE_MAGIC;
    g_syslog_user_info[index].log_info.read = 0;
    g_syslog_user_info[index].log_mem_fw = data;
    spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
    return 0;
}
// 考虑单独复位，得加锁保护
// 在DPA 单独复位的Before流程中会调用
int syslog_user_info_unregister(unsigned int index)
{
    unsigned long flags;
    if (g_syslog_user_info_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return -1;
    }
    if (index >= SYSLOG_FILE_TYPE_CNT || g_syslog_user_info[index].log_mem_fw == NULL) {
        return -1;
    }
    spin_lock_irqsave(&g_syslog_user_info_ctrl.lock[index], flags);
    g_syslog_user_info[index].log_info.app_is_active = 0;
    spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
    return 0;
}

void syslog_user_save_open(void)
{
    u32 index;
    struct syslog_user_mem_info *logmem;
    unsigned long flags;
    for (index = 0; index < SYSLOG_FILE_TYPE_CNT; index++) {
        spin_lock_irqsave(&g_syslog_user_info_ctrl.lock[index], flags);
        logmem = &g_syslog_user_info[index];
        if (logmem == NULL || logmem->log_info.app_is_active != SYSLOG_PREPARE_MAGIC) {
            spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
            continue;
        }
        logmem->log_info.app_is_active = SYSLOG_ACTIVE_MAGIC;
        spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
    }
}
int syslog_user_save_close(void)
{
    u32 index;
    struct syslog_user_mem_info *logmem;
    unsigned long flags;
    int ret = -1;
    if (g_syslog_user_info_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return -1;
    }
    // 关闭触发日志保存功能
    for (index = 0; index < SYSLOG_FILE_TYPE_CNT; index++) {
        spin_lock_irqsave(&g_syslog_user_info_ctrl.lock[index], flags);
        logmem = &g_syslog_user_info[index];
        if (logmem == NULL || logmem->log_info.app_is_active != SYSLOG_ACTIVE_MAGIC) {
            spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
            continue;
        }
        // 已触发保存日志功能，不需要再触发。待保存完日志再将次标记置位
        logmem->log_info.app_is_active = SYSLOG_PREPARE_MAGIC;
        spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
        ret = 0;
    }
    // 正在保存中，或者没有可保存的资源，则返回失败
    return ret;
}
static void syslog_user_data_save_only(void)
{
    u32 index;
    u32 writep, readp, size;
    struct syslog_user_mem_info *logmem;
    unsigned long flags;
    for (index = 0; index < SYSLOG_FILE_TYPE_CNT; index++) {
        // 加锁保护，以防单独复位时，内存被释放
        spin_lock_irqsave(&g_syslog_user_info_ctrl.lock[index], flags);
        logmem = &g_syslog_user_info[index];
        if (logmem == NULL || logmem->log_mem_fw == NULL ||
            logmem->log_info.app_is_active != SYSLOG_PREPARE_MAGIC) {
            spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
            continue;
        }
        // 写指针来自FW，读指针来自HOST
        writep = logmem->log_mem_fw->log_info.write;
        readp = logmem->log_info.read;
        size = logmem->log_info.size;
        if (writep == readp || writep >= size || readp >= size) {
            spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
            continue;
        }
        // 读指针只在任务中更新
        logmem->log_info.read = writep;
        spin_unlock_irqrestore(&g_syslog_user_info_ctrl.lock[index], flags);
        if (writep > readp) {
            syslog_file_save(index, logmem->log_mem_fw->log_buf + readp, writep - readp);
            continue;
        }
        syslog_file_save(index, logmem->log_mem_fw->log_buf + readp, size - readp);
        syslog_file_save(index, logmem->log_mem_fw->log_buf, writep);
    }
}
void syslog_user_data_save(void)
{
    // DPA单独复位的时候，也可以触发保存，但是此时DPA的信息已经去注册，因此不会再存DPA的信息。
    // 同时要保证不往FW发消息
    if (g_syslog_user_info_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return;
    }
    syslog_user_data_save_only();
    // 设置标记，表示HOST可以再次触发日志保存
    syslog_user_save_open();
}

void syslog_save_force(void)
{
    if (g_syslog_user_info_ctrl.state == SYSLOG_USER_DATA_INFO_STATE_INIT) {
        return;
    }
    syslog_user_data_save_only();
    dpa_pr_err("save syslog finish\n");
    // 设置标记，表示HOST可以再次触发日志保存
    syslog_user_save_open();
}