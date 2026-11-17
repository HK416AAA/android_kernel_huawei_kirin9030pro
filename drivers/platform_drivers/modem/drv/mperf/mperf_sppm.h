/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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
 */
 
#ifndef __BSP_MPERF_SPPM_H__
#define __BSP_MPERF_SPPM_H__

#include <osl_types.h>
#include <bsp_sppm.h>
#include "../sppm/sppm_device.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MPERF_MXT,
    MPERF_QS,
    MPERF_BetaClub
} mperf_config_from_tool;

typedef struct {
    char name[SPPM_SRC_NAME_LEN];
    u32 type_id;
    u32 freq;
    u32 event_ids[SPPM_MAX_REGS_EACH_CHAN];
    u32 event_id_num;
    u32 config_core;
    char private_data[SPPM_SRC_PRIV_LEN];
} sppm_read_event;

typedef struct {
    char name[SPPM_SRC_NAME_LEN];
    u32 type_id;
    u32 thread_id;
    char private_data[SPPM_SRC_PRIV_LEN];
} sppm_write_event;

typedef struct {
    u32 from_tool;
    u32 buffer_size;
    u32 flag_circular;
    sppm_read_event read_events[SPPM_ACPU_RCHAN_NUM];
    u32 read_event_num;
} sppm_acore_config;

typedef struct {
    sppm_write_event write_events[SPPM_EACH_CORE_WCHAN_NUM];
    u32 write_event_num;
} sppm_dpa_config;

typedef struct {
    u32 type;
    sppm_acore_config acore_data;
    sppm_dpa_config dpa_data;
} mperf_acore_message;

typedef struct {
    u32 type;
    sppm_dpa_config dpa_data;
} mperf_dpa_message;

void mperf_sppm_handler_init(void);
void mperf_sppm_message_parse(unsigned char *data);

int mperf_buffer_flush(void);

int mperf_msg_send_dpa(void *data, u32 len);
int mperf_msg_response_send(u32 type, int res);

int mperf_dpa_info_buf_alloc(void *data, u32 data_len);
int mperf_dpa_info_buf_flush(void *data, u32 data_len);
mperf_dpa_dev_info *mperf_get_dpa_dev_info(void);
int mperf_dpa_ringbuff_alloc(void);
int mperf_dpa_ringbuff_release(void);

#ifdef __cplusplus
}
#endif
#endif
