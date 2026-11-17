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
 *
 */

#ifndef BSP_DPA_SYSCTRL_H
#define BSP_DPA_SYSCTRL_H

#define SC_SOFT_RSV_CTRL0 0xA00
#define SC_SOFT_RSV_CTRL1 0xA04
#define SC_SOFT_RSV_CTRL2 0xA08
#define SC_SOFT_RSV_CTRL3 0xA0C
#define SC_SOFT_RSV_CTRL4 0xA10
#define SC_SOFT_RSV_CTRL5 0xA14
#define SC_SOFT_RSV_CTRL6 0xA18
#define SC_SOFT_RSV_CTRL7 0xA1C
#define SC_SOFT_RSV_CTRL8 0xA20
#define SC_SOFT_RSV_CTRL9 0xA24
#define SC_SOFT_RSV_CTRL10 0xA28
#define SC_SOFT_RSV_CTRL11 0xA2C
#define SC_SOFT_RSV_CTRL12 0xA30
#define SC_SOFT_RSV_CTRL13 0xA34
#define SC_SOFT_RSV_CTRL14 0xA38
#define SC_SOFT_RSV_CTRL15 0xA3C

/* 预留寄存器8用于ATE测试，hiboot传入 */
#define DPA_ATE_TEST SC_SOFT_RSV_CTRL8

/* 以下几个预留寄存器，由TEEOS驱动配置，DPA启动时使用 */
#define DPA_DDR_ASLR_OFFSET SC_SOFT_RSV_CTRL10
#define DPA_BOOT_DUMP_BASE SC_SOFT_RSV_CTRL13
#define DPA_BOOT_DUMP_SIZE SC_SOFT_RSV_CTRL14

#endif
