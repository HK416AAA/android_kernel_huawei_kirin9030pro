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
#include <linux/spinlock.h>
#include <securec.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_print.h>
#include <bsp_module_init.h>
#include <dpa_reset.h>
#include "syslog_output.h"
#include "syslog_dmesg.h"
#include "syslog_task.h"
#include "syslog_dmi.h"
#include "syslog_dmesg.h"
#include "syslog_user.h"

unsigned int g_syslog_level = BSP_P_ERR;

static DEFINE_SPINLOCK(g_syslog_spinlock);
#define __LOG_BUF_LEN (1 << 14)
static char g_syslog_buffer[__LOG_BUF_LEN] = {0};
static u32 g_syslog_index = 0;
#define LOG_BUF_MASK (__LOG_BUF_LEN - 1)
#define LOG_BUF(idx) (g_syslog_buffer[(idx) & (LOG_BUF_MASK)])
#define LOG_BUF_TIMESLICE_LEN 16

void dpa_syslog_buf_flush(const char *buf, u32 len)
{
    unsigned long flags;
    u32 i = 0;
    spin_lock_irqsave(&g_syslog_spinlock, flags);
    for (i = 0; i < len; i++) {
        LOG_BUF(g_syslog_index) = *(buf + i);
        g_syslog_index++;
    }
    spin_unlock_irqrestore(&g_syslog_spinlock, flags);
    return;
}

void syslog_dpa_buf_store(char *buf, u32 len)
{
    u32 i = 0;
    u32 tempindex = 0;
    u32 length = 0;
    unsigned long flags;
    if ((buf == NULL) || (!len))
        return;
    length = (len > __LOG_BUF_LEN) ? __LOG_BUF_LEN : len;
    // 加锁会导致另一个thread有打印时，阻塞
    spin_lock_irqsave(&g_syslog_spinlock, flags);
    if (g_syslog_index < (__LOG_BUF_LEN - 1)) {
        tempindex = g_syslog_index < length ? 0 : g_syslog_index - length;
    } else {
        tempindex = (g_syslog_index + __LOG_BUF_LEN - length) & LOG_BUF_MASK;
    }
    for (i = 0; i < length; i++) {
        *(buf + i) = LOG_BUF(tempindex);
        tempindex = (tempindex + 1) & LOG_BUF_MASK;
    }
    spin_unlock_irqrestore(&g_syslog_spinlock, flags);
    return;
}

/*
 * 功能描述: 系统级别设置
 * 输入参数: u32 console：控制台打印级别；u32 logbuf：default for acore
 * 输出参数: BSP_OK/BSP_ERROR
 */
s32 dpa_logs(u32 console)
{
    if (console >= BSP_LEVEL_BUTT)
        return BSP_ERROR;
    g_syslog_level = console;
    return BSP_OK;
}
/*
 * 功能描述: inquire level
 * 输入参数: 
 * 输出参数: NA
 */
void dpa_logc(void)
{
    dpa_pr_err("con_level:%d\n", g_syslog_level);
}


static unsigned int syslog_tag_fill(char *buf, int size)
{
    unsigned int time = bsp_get_slice_value();
    unsigned int offset = 0;
    unsigned char *time_temp = (unsigned char *)(uintptr_t)&time;
    static const char num2char[0x10] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
        };
    // 为了提高性能，自定义格式化
    // [12345678]
    buf[offset++] = '[';
    buf[offset++] = num2char[time_temp[0x3] >> 0x4];
    buf[offset++] = num2char[time_temp[0x3] & 0xf];
    buf[offset++] = num2char[time_temp[0x2] >> 0x4];
    buf[offset++] = num2char[time_temp[0x2] & 0xf];
    buf[offset++] = num2char[time_temp[0x1] >> 0x4];
    buf[offset++] = num2char[time_temp[0x1] & 0xf];
    buf[offset++] = num2char[time_temp[0x0] >> 0x4];
    buf[offset++] = num2char[time_temp[0x0] & 0xf];
    buf[offset++] = ']';
    return offset;
}
void __bsp_dpa_print( unsigned int level, const char *fmt, va_list arglist)
{
    u32 used_size;
    int ret;
    // 为了保存结束符
    char print_buffer[BSP_PRINT_BUF_LEN + 1];

    used_size = syslog_tag_fill(print_buffer, BSP_PRINT_BUF_LEN);
    ret = vsnprintf_s(print_buffer + used_size, BSP_PRINT_BUF_LEN - used_size,
        (BSP_PRINT_BUF_LEN - used_size - 1), fmt, arglist);
    if (ret < 0) {
        return;
    }
    used_size += ret;
    print_buffer[used_size] = '\0';
    used_size += 1;
    (void)dpa_syslog_buf_flush(print_buffer, used_size);
}
/*
 * 功能描述: print
 * 输入参数: BSP_LOG_LEVEL level: print level, char *fmt: string
 */
void bsp_dpa_print(enum bsp_log_level level, char *fmt, ...)
{
    va_list arglist;

    if (level == BSP_PRINT_OFF || level > g_syslog_level) {
        return;
    }
    va_start(arglist, fmt);
    __bsp_dpa_print(level, fmt, arglist);
    va_end(arglist);
}

EXPORT_SYMBOL_GPL(bsp_dpa_print);
EXPORT_SYMBOL_GPL(dpa_logs);
EXPORT_SYMBOL_GPL(dpa_logc);

static int syslog_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    if (enparam == DPA_RESET_BEFORE) {
        syslog_dmi_switch_close();
    } else if (enparam == DPA_RESET_AFTER) {
        syslog_dmi_switch_init();
        syslog_dmi_sever_reset_after();
    }
    return 0;
}
int syslog_output_init(void)
{
    syslog_dmesg_init();
    if (syslog_task_init() != 0) {
        return -1;
    }
    if (syslog_file_init() != 0) {
        return -1;
    }
    syslog_user_info_init();
    if (syslog_dmi_init() != 0) {
        return -1;
    }
    syslog_user_init();
    if (bsp_dpa_reset_register_cb("syslog_reset", syslog_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON)) {
        dpa_pr_err("syslog reset register failed\n");
        return -1;
    }
    dpa_pr_err("syslog output init ok\n");
    return 0;
}
