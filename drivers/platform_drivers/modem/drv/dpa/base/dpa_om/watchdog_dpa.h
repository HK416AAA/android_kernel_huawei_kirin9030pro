/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
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

#ifndef __WATCHDOG_DPA_H__
#define __WATCHDOG_DPA_H__

#include <osl_types.h>
#include <bsp_wdt.h>

#define DPA_WDT_MAXNUM 2
#define WDT_TIMEOUT_SLICE (60 * WDT_DEF_CLK_FREQ) // 30*32Khz

#define WDT_CLKREG 0
#define WDT_CLKCG_STAT0 0xC
#define WDT_CLKBIT(wid) (1U << (4 + (wid)))
#define WDT_SRSTREG 0x104
#define WDT_SRSTSTAT0 0x108
#define WDT_SRSTBIT(wid) (1U << (4 + (wid)))

typedef enum {
    WDT_IRQ_DISABLE = 0,
    WDT_IRQ_ENABLE  = 1,
} WDI_IRQ_OPS;

/*
 *    wdt 寄存器偏移定义（项目名_模块名_寄存器名_OFFSET)
 */
#define WDG_LOCKEN         (0x0)  /* 写权限锁寄存器，用于开锁 */
#define WDG_LOCKDIS        (0x4)  /* 写权限锁寄存器，用于关锁 */
#define WDG_LOCK           (0x8)  /* 写权限锁状态寄存器 */
#define WDG_INT_TIME       (0xC)  /* 中断时间设置寄存器，设置中断超时时间 */
#define WDG_RST_TIME       (0x10)  /* 复位时间设置寄存器，设置产生中断后，再产生复位信号的时间，该寄存器不使用。 */
#define WDG_CNT_EN         (0x14)  /* 看门狗使能寄存器，控制计数开关。 */
#define WDG_KICK           (0x18)  /* 喂狗寄存器。 */
#define WDG_INT_CLR        (0x1C)  /* 清中断寄存器 */
#define WDG_INT_MSK        (0x20)  /* 中断屏蔽寄存器，屏蔽后中断不上报。 */
#define WDG_RST_MSK        (0x24)  /* 复位屏蔽寄存器，屏蔽后复位信号不生效。 */
#define WDG_INT_RAW        (0x28)  /* 原始中断寄存器。 */
#define WDG_INT_STA        (0x2C)  /* 中断状态寄存器。 */
#define WDG_CNT_VALUE      (0x30)  /* 计数器回读寄存器。 */
#define WDG_DBG_GATE       (0x34)  /* debug门控状态寄存器。 */
#define WDG_ID_STA         (0xFFC)  /* ID状态寄存器。 */

#define WDOG_UNLOCK        0x1AAEE533
#define WDOG_LOCK          0x0
#define WDOG_FOOD          0x1
#define WDOG_DISABLE       0x0

struct wdt_dpa {
    int init_flag;
    int wdtnum;
    unsigned int timeout_slice;
    void *dpa_crg;
    void *base_addr[DPA_WDT_MAXNUM];
    int wdtirqs[DPA_WDT_MAXNUM];
    unsigned int clkreg;
    unsigned int srstreg;
    unsigned int clkcg_stat;
    unsigned int srststat;
    unsigned int timeout;
    unsigned int time_slice;
    unsigned int sr_status;
};
#endif