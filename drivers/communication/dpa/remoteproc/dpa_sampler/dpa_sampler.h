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
#ifndef __BSP_DPA_SAMPLER_H__
#define __BSP_DPA_SAMPLER_H__

#include <bsp_print.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>

#define dpa_sampler_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#ifdef __cplusplus
extern "C" {
#endif

#define DPA_SAMPLER_VERSION 0x5A5A5A02

#define DPA_SAMPLER_ERR 0x01
#define DPA_SAMPLER_OK 0x00

#define DPA_SAMPLER_RUNNING 0x01
#define DPA_SAMPLER_STOP 0x0

#define DPA_CORE_MAX_NUM 4

#define DPA_SAMPLER_MAX_FREQ 10000

#define DPA_SAMPLER_PC_MAX_FREQ 50000

#define DPA_SAMPLER_RW_FILE_MODE 0666
#define DPA_SAMPLER_DATA_FILE "/data/hisi_logs/dpa_cs_raw.bin"

#define DPA_SAMPLER_DMI_TIMEOUT 1000

#define DPA_SAMPLER_MIN_BUF_SIZE 256

#pragma pack(push, 4)

typedef enum {
    MODE_DPA_CALLSTACK = 0,
    MODE_DPA_PC,
    MODE_DPA_PMU,
    MODE_DPA_CALLSTACK_AND_PMU,
    MODE_MAX,
} dpa_sample_mode;

typedef enum {
    CYCLE_WRITE = 0,
    WRITE_FULL,
} buffer_mode;

typedef enum {
    DPA_SAMPLER_MSG_BUF_TO_DPA = 0,
    DPA_SAMPLER_MSG_BUF_TO_DPA_RES,
    DPA_SAMPLER_MSG_GET_BUF,
    DPA_SAMPLER_MSG_GET_BUF_RES,
    DPA_SAMPLER_MSG_GET_ASLR,
    DPA_SAMPLER_MSG_GET_ASLR_RES,
    DPA_SAMPLER_MSG_MAX,
} dpa_sampler_msg_type;

typedef struct {
    unsigned int sample_type;  // 采样类型 火焰图：0, 热点函数：1, pmu：2, 火焰图+pmu：3
    unsigned int sample_freq;  // 采样频率
    unsigned int sample_dur;   // 采样时长
    unsigned int sample_core;  // 采样核号 1:core1, 2:core2, 3:all core
    unsigned int buffer_size;  // 预留ringbuffer大小
    unsigned int buffer_mode;  // 采样模式 循环覆盖: 0, 写满停止：1
} dpa_sampler_config_params;

typedef struct {
    unsigned long long phy_addr;   // buffer物理地址
    unsigned long long virt_addr;  // buffer虚拟地址
    unsigned int buffer_size;      // ringbuffer大小
    unsigned int buffer_mode;      // 采样模式 循环覆盖: 0, 写满停止：1
    unsigned int rb_rptr;          // 读指针
    unsigned int rb_wptr;          // 写指针
    unsigned int data_size;        // 已填充数据长度
} dpa_sampler_buffer;

typedef struct {
    dpa_sampler_buffer buffers[DPA_CORE_MAX_NUM];
    unsigned int dpa_core_num;
    unsigned int dpa_core_bitmask;
    unsigned int sample_core_num;
    unsigned int aslr_data;
    unsigned int bsae_pa;
    unsigned int mo_base_pa;
    unsigned int pl1text_base_pa;
    unsigned int dpa_core_pc_regs[DPA_CORE_MAX_NUM];
    void * dpa_core_pc_regs_virt[DPA_CORE_MAX_NUM];
    struct hrtimer hrtimer_handle;
    ktime_t hrtimer_period;
    unsigned int sample_count;
    unsigned int state;
} dpa_sampler_ctrl_t;

typedef struct {
    void *pc_reg_core1;
    void *pc_reg_core2;
} dpa_sampler_pc_regs;

typedef struct {
    unsigned int msg_type;
    unsigned int aslr;
    unsigned int bsae_pa;
    unsigned int mo_base_pa;
    unsigned int pl1text_base_pa;
    unsigned int sample_type;
    unsigned int sample_core;
    dpa_sampler_buffer buffers[DPA_CORE_MAX_NUM];
} dpa_sampler_msg;

#pragma pack(pop)

dpa_sampler_config_params *dpa_sampler_get_config(void);
dpa_sampler_ctrl_t *dpa_sampler_get_ctrl(void);

int dpa_sampler_rb_alloc(void);
int dpa_sampler_rb_release(void);
int dpa_sampler_rb_write(dpa_sampler_buffer *buf, u32 mode, void *data, u32 data_len);

#ifdef __cplusplus
}
#endif
#endif