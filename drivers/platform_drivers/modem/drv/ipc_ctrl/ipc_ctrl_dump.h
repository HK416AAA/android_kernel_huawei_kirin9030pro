/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
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
#ifndef __IPC_CTRL_DUMP_H__
#define __IPC_CTRL_DUMP_H__

#define IPCCTRL_DUMP_VERSION     0x0
#define IPCCTRL_CHN_DUMP_VERSION 0x0

#define IPCCTRL_REGS_DUMP_NUM  7
#define IPCCTRL_TIMESTAMP_NUM  5
#define IPCCTRL_CHN_DUMP_NUM   7

enum {
    IDX_INT_EN           = 0,
    IDX_INT_CLR          = 1,
    IDX_INT_STAT         = 2,
    IDX_INT_MSK_EN       = 3,
    IDX_INT_MSK_DIS      = 4,
    IDX_INT_MSK_STAT     = 5,
    IDX_INT_MSK_INT_STAT = 6,
};
typedef struct {
    unsigned int version;                               // 被维测通道数据结构版本号
    unsigned int chn_id;                                // 被维测通道号
    unsigned int base_addr;                             // 被维测通道基地址
    unsigned int rs_cnt;                                // 被维测通道中断发送次数 recv or send cnt
    unsigned int regs_dump[IPCCTRL_REGS_DUMP_NUM];      // 被维测通道寄存器在dump时保存的值
    unsigned int timestamp[IPCCTRL_TIMESTAMP_NUM];      // 被维测通道接收/发送中断时间的流水打点
    unsigned int res_bit[IPCCTRL_TIMESTAMP_NUM];        // 被维测通道接收/发送中断的资源bit位
    unsigned int tim_idx;                               // 被维测通道时间流水打点索引
}chn_dump_t;

typedef struct {
    unsigned int version;                              // ipcctrl维测数据结构版本号
    unsigned int len;                                  // 维测内存总长度
    unsigned int chn_cnt;                              // 被维测通道数量
    chn_dump_t chn_dump[IPCCTRL_CHN_DUMP_NUM];         // 被维测通道的维测数据信息
}ipcctrl_dump_t;

void ipcctrl_dump_chn_fastptr_record(struct ipcctrl_channel_t *pchn);
void ipcctrl_dump_trace(u32 chn_index, u32 res_bit);
s32 ipcctrl_dump_init(void);

#endif