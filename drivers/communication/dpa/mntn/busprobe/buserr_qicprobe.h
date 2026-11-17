/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
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

#ifndef __BUSERR_QICPROBE_H__
#define __BUSERR_QICPROBE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define QIC_EM_NAME            16
#define QIC_STATE_REG_MAGIC    (0xABABABAB)
#define QIC_DUMP_VID           0x2
#define QIC_PARSER_EM_MAX      0x4

#define qic_printf(fmt, ...)   dpa_pr_err("[qic]" "<%s>" fmt, __FUNCTION__, ##__VA_ARGS__)

enum {
    QIC_STATE_INVALID = 0,  /* IB_STATE或者INT state无效 */
    QIC_STATE_VALID = 1     /* IB_STATE或者INT state有效或者中断清除 */
};

enum {
    QIC_NO_IB_STATE = 0xA001,
    QIC_NULL_POINTER = 0xA002,
    QIC_PARA_ERROR = 0xA003,
    QIC_EXC_BRANCH = 0xA003,
    QIC_QCR_TIMEOUT = 0xA004,
};

typedef struct {
    u32 magic_num;
    u32 chip_version;
    u32 dump_idx;
    u32 base_addr;
    u32 slice;
    u32 valid_state;
    u32 err_reg[0x9]; /* 保存9个寄存器值，由于不连续，用数组方式存 */
} qic_dump_head_s;

typedef struct {
    void *irq_reg;   /* 中断状态寄存器 */
    u32 irq_bit;     /* 中断状态寄存器的bit位 */
    u32 phy_base;    /* em的寄存器物理基地址 */
    void *base;      /* em的寄存器虚拟基地址 */
    char name[QIC_EM_NAME];
    u32 powerdown_check; /* 是否判断总线已下电 */
    u32 ibq_cnt;
    void **ibq_addr;
} qic_em_s;

typedef struct {
    qic_em_s *em;                  /* qic 物理地址和虚拟地址 */
    qic_dump_head_s *dump_addr;     /* 中断触发保存第一现场日志 */
    qic_dump_head_s *dump_record;   /* system error后再存一份 */
    u32 em_cnt;
    u32 irq_count;                  /* 进中断次数统计 */
    u32 reset_flag;                 /* 复位标志 */
    u32 dump_times;                 /* 复位时间记录 */
    u32 ibq_cnt;
    u32 *ibq_addr;
    u32 em_flag[QIC_PARSER_EM_MAX]; /* 标记被置位 em */
    u32 chip_version;
} qic_errprobe_s;

#ifdef __cplusplus
}
#endif

#endif
