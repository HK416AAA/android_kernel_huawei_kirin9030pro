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
#ifndef __DUMP_BASEINFO_H__
#define __DUMP_BASEINFO_H__

#include <linux/types.h>
#include <dump_exception.h>
#include <dump_errno.h>
#include <dump_mem.h>

#define DUMP_BASEINFO_SENCE_LEN (16)
#define DUMP_BASEINFO_NAME_STEP (4)

typedef struct {
    u32 reboot_cpu;      /* 0x00  */
    u32 reboot_context;  /* 0x00  */
    u32 reboot_task;     /* 0x04  */
    u32 reboot_task_tcb; /* 0x04  */
    u8 task_name[DUMP_NAME_LEN];    /* 0x08  */
    u32 reboot_int;      /* 0x18  */
    u32 reboot_time;     /* 0x84 */

    u32 mod_id;      /* 0x1c  */
    u32 arg1;        /* 0x20  */
    u32 arg2;        /* 0x24  */
    u32 arg3;        /* 0x28  */
    u32 arg3_length; /* 0x2c  */
    u32 vec;         /* 0x30  */

    u32 cpu_max_num;     /* 0x88 */
    u32 cpu_online_num;  /* 0x88 */
    u8 version[DUMP_PRODUCT_VERSION_LEN];      /* 0xA0 */
    u8 compile_time[DUMP_BUILD_TIME_LEN]; /* 0xB0 */
    u32 reboot_reason;   /* m3专用 */
    u8 version_uuid[DUMP_IMAGEID_LEN];
    struct {
        char biref[DUMP_BASEINFO_EXC_DESC_LEN];
        char module[DUMP_BASEINFO_EXC_DESC_LEN];
        char detail[DUMP_BASEINFO_EXC_DESC_LEN];
    } extra_exc_desc;
} dump_base_info_s;

// dpahost-hal层实现，只有phone平台需要实现baseinfo，mbb与adump baseinfo 复用,该接口是桩
void dump_save_base_info(u32 mod_id, u32 arg1, u32 arg2, const char *data, u32 length, const char *sence);
void dump_save_rdr_baseinfo(const dump_exc_log_desc_s *exc_desc);
int dump_base_info_init(void);
int dump_base_info_reset(void);

#endif
