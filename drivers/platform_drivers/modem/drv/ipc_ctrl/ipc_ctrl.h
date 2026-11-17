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

#ifndef __IPC_CTRL_H__
#define __IPC_CTRL_H__

#include <osl_types.h>
#include <bsp_print.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef THIS_MODU
#define THIS_MODU mod_ipc_ctrl

#define ipcctrl_err(fmt, ...) bsp_err("[%s] :" fmt, __FUNCTION__, ##__VA_ARGS__)
#define ipcctrl_info(fmt, ...) bsp_info("[%s] :" fmt, __FUNCTION__, ##__VA_ARGS__)
#define ipcctrl_dbg(fmt, ...) do {                                       \
        if (g_dbg_print_sw) {                  \
            ipcctrl_err(fmt, ##__VA_ARGS__); \
        }                                      \
    } while (0)

#define IPCCTRL_OK         (0)
#define IPCCTRL_ERR        (-1)
#define IPCCTRL_HANDLE_ERR (-2)
#define IPCCTRL_MEM_ERR    (-3)

#define IPCCTRL_ACORE_DEVICE_NAME "/ipc_ctrl_device"
#define IPCCTRL_MAGIC 0xdcba

#define CHN_MAX_NUM     5  // 收发共用了5个通道
#define RES_MAX_NUM     32 // 每个通道上最多承载32个二级中断

#define IPCCTRL_BIT_MASK(n) (1UL << (n))
#define IPCCTRL_CPU_INT_EN           (0x000)  // 电平中断使能寄存器
#define IPCCTRL_CPU_INT_CLR          (0x004)  // 电平中断清除寄存器
#define IPCCTRL_CPU_INT_STAT         (0x008)  // 电平中断状态寄存器
#define IPCCTRL_CPU_INT_MSK_EN       (0x010)  // 电平中断屏蔽使能寄存器
#define IPCCTRL_CPU_INT_MSK_DIS      (0x014)  // 电平中断屏蔽去使能寄存器
#define IPCCTRL_CPU_INT_MSK_STAT     (0x018)  // 电平中断屏蔽状态寄存器
#define IPCCTRL_CPU_INT_MSK_INT_STAT (0x01c)  // 屏蔽后电平中断状态寄存器

struct ipc_handle {
    u32 res_bit : 5;
    u32 chn_index : 5;
    u32 magic : 22;
};

struct ipcctrl_res_t {
    u32 res_id;
    u32 res_bit;
    struct ipc_handle handle;
    struct ipc_entry ipc_int_table;
};

struct ipcctrl_channel_t {
    u32 chn_id;
    u32 irq_no;
    void *base_addr;
    u32 is_recv;
    u32 is_mdm;   // 标记该通道接收方是否是modem
    u32 dump_index; // 维测用的index
    struct ipcctrl_res_t *res[RES_MAX_NUM];
};

#ifdef __cplusplus
}
#endif /* define __cplusplus */

#endif