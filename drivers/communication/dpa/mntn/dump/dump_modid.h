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
#ifndef _DUMP_MODID_H_
#define _DUMP_MODID_H_

// modem qic modid, may need dpa dump
#define RDR_MODEM_NOC_MOD_ID 0x82000030                 /* NOC异常, 保存log，phone独有, */
#define RDR_MODEM_DMSS_MOD_ID 0x82000031                /* DMSS异常, 保存log，phone独有, */
#define RDR_MODEM_LPMCU_MOD_ID 0x82000057               /* mdm lpmcu异常, 保存log, 可能是lpmcu mdm&dpa公共模块调用接口，保存dpa log */

#define DUMP_DPA_MOD_ID_START 0
#define DUMP_DPA_MOD_ID_END 0xFFFFFFFF

#ifdef CONFIG_ACPU_RDR_DPA_FEATURE_ON
// todo acpu rdr dpa子系统相关枚举适配完成后再使用该分支
#define DUMP_RDR_DPA_MODID_START 0xc0008000
#define DUMP_RDR_DPA_MODID_END 0xC0008FFF
#else
#define DUMP_RDR_DPA_MODID_START 0x82E08000
#define DUMP_RDR_DPA_MODID_END 0x82E08FFF
#endif

enum dpa_exc_modid {
    RDR_DPA_HOST_EXC_MODID_START = DUMP_RDR_DPA_MODID_START,
    RDR_ACPU_QIC_DPA_EXC_MODID = RDR_DPA_HOST_EXC_MODID_START, // 0xC0008000
    RDR_DPA_HOST_MODID, // 0xC0008001
    RDR_DPA_HOST_DPA_QIC_MODID, // 0xC0008002
    RDR_DPA_HOST_MODEM_PERI_QIC_MODID, // 0xC0008003
    RDR_DPA_HOST_MODEM_PERI_PDLOCK_MODID, // 0xC0008004
    RDR_DPA_DPA_RESET_FAIL_MODID, // 0xC0008005
    RDR_DPA_HOST_DRV_MODID, // 0xC0008006
    RDR_DPA_HOST_WLAN_MODID, // 0xC0008007
    RDR_DPA_HOST_STACK_MODID, // 0xC0008008
    RDR_DPA_HOST_BOOSTER_MODID, // 0xC0008009
    RDR_DPA_HOST_RPM_MODID, // 0xC000800A
    RDR_DPA_HOST_DMI_MODID, // 0xC000800B
    RDR_DPA_HOST_LPMCU_MODID, // 0xC000800C
    RDR_DPA_HOST_DPA_FREQ_MODID, // 0xC000800D
    RDR_DPA_HOST_RST_DPA_TEST_NORMALRESET = DUMP_RDR_DPA_MODID_START + 0x7FD, // 0xC00087FD
    RDR_DPA_HOST_RST_DPA_TEST = DUMP_RDR_DPA_MODID_START + 0x7FE, // 0xC00087FE
    RDR_DPA_HOST_EXC_MODID_END = DUMP_RDR_DPA_MODID_START + 0x7FF,

    RDR_DPA_FW_EXC_MODID_START = DUMP_RDR_DPA_MODID_START + 0x800,
    RDR_DPA_FW_MODID = RDR_DPA_FW_EXC_MODID_START, // 0xC0008800
    RDR_DPA_FW_WDT_MODID, // 0xC0008801
    RDR_DPA_FW_PANIC_MODID, // 0xC0008802
    RDR_DPA_FW_DRV_MODID, // 0xC0008803
    RDR_DPA_FW_WLAN_MODID, // 0xC0008804
    RDR_DPA_FW_NSTACK_MODID, // 0xC0008805
    RDR_DPA_FW_EXC_MODID_END = DUMP_RDR_DPA_MODID_END
};

#endif