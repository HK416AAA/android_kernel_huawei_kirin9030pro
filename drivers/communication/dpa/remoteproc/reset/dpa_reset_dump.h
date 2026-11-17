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

#ifndef DPA_RESET_DUMP_H_
#define DPA_RESET_DUMP_H_

#include <linux/types.h>
#include <linux/list.h>
#include <dpa_reset.h>
#include "dpa_reset_frame.h"

#define DPA_RESET_FW_DUMP_SIZE 560

#define DPA_RESET_FRAME_NAME_MAX_LEN 12
#define RESET_NAME_MAX_LEN 10
#define DPA_RESET_RECORD_MAX_NUM 4u

#define DPA_RESET_DUMP_HEAD_MAGIC 0xABABEEFF
#define DPA_RESET_DUMP_HEAD_END_MAGIC 0xBABAFFEE
#define DPA_RESET_PRIMARY_END_MAGIC 0xAABBEFEF
#define DPA_RESET_SECONDARY_END_MAGIC 0xBBAAFEFE

typedef struct {
    unsigned int magic;
    unsigned int size; // acore申请的用于dpa_fw使用的dump大小；
    unsigned int host_num; // dpa_fw回填模块数量
    unsigned int core_num;
    unsigned int frame_num;
    unsigned int rsv[2];
    unsigned int end_magic;
} reset_dump_head_s;

/* DPA FW单独复位框架维测结构 */
typedef struct {
    char name[DPA_RESET_FRAME_NAME_MAX_LEN];
    unsigned int slice;
} dpa_reset_frame_record_s;
/* DPA FW单独复位框架记录的各个master的维测结构 */
typedef struct {
    char name[RESET_NAME_MAX_LEN];
    unsigned short record_num;
    unsigned int start_slice;
    unsigned int end_slice;
    unsigned int result;
    unsigned int records[DPA_RESET_RECORD_MAX_NUM];
} dpa_reset_host_record_s;

// DPA host下打点信息
#define DPA_RESET_HOST_DUMP_OK 0xAA000000
#define DPA_RESET_HOST_DUMP_FAIL 0xEE000000
#define DPA_RESET_HOST_MAGIC 0xCCDDDDCC

typedef struct {
    unsigned int magic;
    unsigned int dump_size;
    unsigned int version;
    unsigned int record_num;
} dpa_reset_host_dump_head_s;

typedef struct {
    unsigned int type;
    unsigned int slice;
    unsigned int val;
} dpa_reset_host_dump_item_s;

enum dpa_reset_stamp_stage {
    DPA_RESET_STAMP_STAGE_1 = 1,
    DPA_RESET_STAMP_STAGE_2,
    DPA_RESET_STAMP_STAGE_3
};

enum dpa_reset_host_dump_stamp {
    DPA_RESET_HOST_DUMP_PREPARE,
    DPA_RESET_HOST_DUMP_CHECK_ACTION,
    DPA_RESET_HOST_DUMP_PREPARE_DONE,

    DPA_RESET_HOST_DUMP_TSK_SEMDOWN,
    DPA_RESET_HOST_DUMP_TSK_POFF,
    DPA_RESET_HOST_DUMP_TSK_PON,
    DPA_RESET_HOST_DUMP_TSK_RESET,
    DPA_RESET_HOST_DUMP_TSK_ACTION_DONE,
    DPA_RESET_HOST_DUMP_TSK_SUM_DONE,
    DPA_RESET_HOST_DUMP_TSK_EXIT,

    DPA_RESET_HOST_DUMP_POFF_START,
    DPA_RESET_HOST_DUMP_POFF_WAKEUP,
    DPA_RESET_HOST_DUMP_POFF_DO_BEFORE,
    DPA_RESET_HOST_DUMP_POFF_CLR_DUMP,
    DPA_RESET_HOST_DUMP_POFF_RECV_RESP,
    DPA_RESET_HOST_DUMP_POFF_NMI,
    DPA_RESET_HOST_DUMP_POFF_DUMP_PARSE,
    DPA_RESET_HOST_DUMP_POFF_FIPC_BEFORE,
    DPA_RESET_HOST_DUMP_POFF_DONE,

    DPA_RESET_HOST_DUMP_PON_START,
    DPA_RESET_HOST_DUMP_PON_DOING,
    DPA_RESET_HOST_DUMP_PON_RECV_RESP,
    DPA_RESET_HOST_DUMP_PON_WAIT_DONE,
    DPA_RESET_HOST_DUMP_PON_FIPC_AFTER,
    DPA_RESET_HOST_DUMP_PON_DO_AFTER,
    DPA_RESET_HOST_DUMP_PON_WAKEUP,

    DPA_RESET_HOST_DUMP_MAX
};

#define DPA_RESET_DUMP_NAME_LEN 12
#define DPA_RESET_HOST_MAX_NUM 15
#define DPA_RESET_TIME_CNT (DPA_RESET_TO_BYPASS_TIME_CNT * 2)

typedef struct dpa_reset_mod_dump {
    char name[DPA_RESET_DUMP_NAME_LEN];
    unsigned int start_slice;
    unsigned int end_slice;
    unsigned int ret;
    unsigned int prio;
} dpa_reset_mod_dump_s;

typedef struct dpa_reset_bypass_info {
    unsigned int reset_times[DPA_RESET_TIME_CNT];
    unsigned int bypass_flag;
    unsigned int bypass_slice;
} dpa_reset_bypass_info_s;

typedef struct dpa_reset_host_dump {
    dpa_reset_host_dump_head_s head;
    dpa_reset_host_dump_item_s items[DPA_RESET_HOST_DUMP_MAX];
    dpa_reset_mod_dump_s mods[DPA_RESET_STAGE_MAX][DPA_RESET_HOST_MAX_NUM];
    dpa_reset_bypass_info_s bypass_info;
} dpa_reset_host_dump_s;

void dpa_reset_fw_dump_parse(void);
void dpa_reset_fw_dump_clear(void);

int dpa_reset_dump_init(void);

void dpa_reset_host_dump(unsigned int dos, unsigned int type, unsigned int val);
void dpa_reset_mod_dump_before(unsigned int stage, unsigned int idx, const char *name, unsigned int prio);
void dpa_reset_mod_dump_after(unsigned int stage, unsigned int idx, unsigned int ret);
void dpa_reset_time_dump(unsigned int cnts, unsigned int time);
void dpa_reset_bypass_dump(unsigned int flag);

#endif // DPA_RESET_DUMP_H_