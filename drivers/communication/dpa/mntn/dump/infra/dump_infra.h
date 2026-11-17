/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2025. All rights reserved.
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
#ifndef _DUMP_INFRA_H_
#define _DUMP_INFRA_H_

#include <linux/sched.h>
#include <linux/printk.h>
#include <bsp_print.h>
#include "dump_errno.h"

#undef THIS_MODU
#define THIS_MODU mod_dump

#ifndef UNUSED
#define UNUSED(a) (void)(a)
#endif

#define dump_info(fmt, ...) dpa_pr_info("[dump]" "[L%d]" fmt, __LINE__, ##__VA_ARGS__)
#define dump_debug(fmt, ...) dpa_pr_debug("[dump]" "<%s>" fmt, __FUNCTION__, ##__VA_ARGS__)
#define dump_warning(fmt, ...) dpa_pr_wrn("[dump]" "[L%d]" fmt, __LINE__, ##__VA_ARGS__)
#define dump_error(fmt, ...) dpa_pr_err("[dump]" "<%s>" fmt, __FUNCTION__, ##__VA_ARGS__)
#define dump_print(fmt, ...) dpa_pr_err("[dump]" fmt, ##__VA_ARGS__)

#define DUMP_BIT(nr) (1UL << (nr))
#define DUMP_BVAL(val, n) (((val) & DUMP_BIT(n)) >> (n))

#define DUMP_10HZ_SLEEP_6S 60
#define DUMP_10HZ_SLEEP_3S 30
#define DUMP_SLEEP_5MS_NUM 5
#define DUMP_WAIT_1S_NUM 1000

#define RDR_DUMP_FILE_PATH_LEN 128
#define RDR_DUMP_FILE_DPA_PATH "dpa_log/"
#define DUMP_SAVE_FLAG "DPA_DONE"
#define RDR_DUMP_DIR_PTH_LEN (RDR_DUMP_FILE_PATH_LEN - strlen(RDR_DUMP_FILE_DPA_PATH))

#define DUMP_LOG_YEAR_START 1900
#define DUMP_MAX_MODULE_LEN 16

typedef enum {
    DUMP_MBB = 0,
    DUMP_PHONE,
    DUMP_PRODUCT_BUTT
} dump_product_type_e;

typedef enum {
    DUMP_SAVE_FILE_NORMAL = 0x0,
    DUMP_SAVE_FILE_NEED = 0xAABBCCDD,
    DUMP_SAVE_FILE_END = 0x5A5A5A5A
} dump_save_flag_e;

typedef enum {
    DUMP_START_POWER_ON = 0,
    DUMP_START_REBOOT = 0x5A5A1111,
    DUMP_START_EXCH = 0x5A5A2222,
    DUMP_START_CRASH = 0x5A5A3333
} dump_start_flag_e;

typedef enum {
    DUMP_REASON_NORMAL = 0x0,
    DUMP_REASON_PROCESSOR = 0x1,
    DUMP_REASON_STACKFLOW = 0x2,
    DUMP_REASON_WDT = 0x3,
    DUMP_REASON_PMU = 0x4,
    DUMP_REASON_REBOOT = 0x5,
    DUMP_REASON_QIC = 0x6,
    DUMP_REASON_DMSS = 0x7,
    DUMP_REASON_RST_FAIL = 0x8,
    DUMP_REASON_RST_NOT_SUPPORT = 0x9,
    DUMP_REASON_DLOCK = 0x10,
    DUMP_REASON_RST_FREQ = 0x11,
    DUMP_REASON_PDLOCK = 0x12,
    DUMP_REASON_AMON = 0x13,
    DUMP_REASON_UNDEF = 0xff
} dump_reboot_reason_e;

static inline void dump_wait_done(volatile const u64 *flag, u64 expect_flag, int *time)
{
    while (((*flag) & expect_flag) != expect_flag) {
        set_current_state(TASK_INTERRUPTIBLE);
        (void)schedule_timeout(HZ / 10); /* 10 means wait 100ms */
        if (((*time)--) <= 0) {
            break;
        }
    }
}

#ifdef DRV_BUILD_LLT
#include <linux/export.h>
#define DUMP_LLT_EXPORT_SYMBOL(x) EXPORT_SYMBOL(x)
#else
#define DUMP_LLT_EXPORT_SYMBOL(x)
#endif

#endif