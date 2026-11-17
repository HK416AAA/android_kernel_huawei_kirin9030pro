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
#ifndef __DUMP_RESET_LOG_H__
#define __DUMP_RESET_LOG_H__

#include <linux/types.h>
#include <dump_frame.h>
#include "dump_mem.h"

// reset reason
#define UNKNOW "UNKNOW"
#define PROCESSOR_ABORT "abort"
#define WDT "wdg"
#define NOARMAL "syserr"
#define UNDEFFINE "undefine"
#define QIC "qic"
#define DMSS "dmss"
#define RST_FAIL "rst_fail"
#define RST_NOT_SUPPORT "rst_not_support"
#define DLOCK "bus_dlock"
#define RST_FREQ "reset_freq"

#define DUMP_APR_BRIEFTYPE_LEN (32)
#define DUMP_APR_MODULE_NAME_LEN (12)
#define DUMP_APR_TASK_NAME_LEN (16)
#define DUMP_APR_REBOOT_CORE_LEN (12)
#define DUMP_APR_REBOOT_REASON_LEN (16)
#define DUMP_APR_CUST_EXC_DESC_LEN 48

#define DUMP_ARP_LOG_BUF_LEN (512)

typedef enum {
    APR_DPA,
    APR_BUTT,
} apr_type_e;
#define DUMP_SHOW_APR_DPA_ALL_TABLE (0)
#define DUMP_SHOW_APR_DPA_INT_TABLE (2)
#define DUMP_SHOW_APR_DPA_TSK_TABLE (3)
#define DUMP_SHOW_APR_DPA_MOD_TABLE (4)

typedef struct {
    u32 moudle_sum; /* 组件总数 */
    struct {
        u32 module;                            /* 责任组件 */
        char module_name[DUMP_NAME_LEN_SHORT]; /* 责任组件名称 */
    } module_info[1];
} module_info_s;

typedef struct modid_info {
    u32 moudid_sum; /* 范围总数 */
    struct {
        u32 modid_start;                  /* 组件主动复位modid起始值 */
        u32 modid_end;                    /* 组件主动复位modid结束值 */
        char module[DUMP_NAME_LEN_SHORT]; /* 责任组件 */
    } modid_info[1];
} modid_info_s;
typedef struct {
    u32 task_sum; /* 任务总数 */
    struct {
        char task_name[DUMP_APR_TASK_NAME_LEN]; /* 任务名 */
        char module[DUMP_NAME_LEN_SHORT];       /* 责任组件 */
    } task_info[1];
} task_table_s;

typedef struct {
    u32 intrupt_sum; /* 中断总数 */
    struct {
        u32 interrpt_id;                  /* 中断号 */
        char module[DUMP_NAME_LEN_SHORT]; /* 责任组件 */
    } interupt_info[1];
} interupt_table_s;

typedef struct {
    u32 except_core;
    u32 except_reason;
    u32 mod_id;
    u32 reboot_context;
    u32 reboot_task;
    u32 reboot_int;
} dump_except_info_s;

typedef struct {
    char brieftype[DUMP_APR_BRIEFTYPE_LEN];     /* module */
    char module_name[DUMP_APR_MODULE_NAME_LEN]; /* 根因组件名 */
    char task_name[DUMP_APR_TASK_NAME_LEN]; /* 复位任务名,如果为中断则为中断号,如果临终为任务则为任务名 */
    u32 reboot_int;                       /* 复位中断号 */
    u32 modid;                            /* 复位modid,system_error的第一个入参 */
    char reboot_core[DUMP_APR_REBOOT_CORE_LEN];    /* 取值AP DPA */
    char reboot_reson[DUMP_APR_REBOOT_REASON_LEN]; /* 取值Normal/DataAbort/Wdt */
    char cust_brief[DUMP_APR_CUST_EXC_DESC_LEN]; /* 拼接到F1name:brief,组件复位时定制 */
    char cust_task[DUMP_APR_CUST_EXC_DESC_LEN]; /* 拼接到F2name:task_name,组件复位时定制 */
    char cust_modid[DUMP_APR_CUST_EXC_DESC_LEN]; /* 拼接到F3name:modid,组件复位时定制 */
} dump_reset_log_s;

typedef struct {
    /* 存储dpa中断信息 中断号 责任组件 */
    interupt_table_s *dpa_interupt_table;
    /* 存储dpa任务 责任组件信息 */
    task_table_s *dpa_task_table;
    /* 存储modid范围 责任组件信息 */
    modid_info_s *modid_table;
} dump_apr_info_s;

typedef struct {
    u8 *virt_addr;
    u8 *phy_addr;
} dump_apr_addr_s;

int dump_reset_log_init(void);
void dpa_dump_apr_get_reset_info(char *reset_info, u32 size, const dump_exc_log_desc_s *exc_desc, dump_apr_info_s *dump_apr_info);
#endif
