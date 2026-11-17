/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2021. All rights reserved.
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

#ifndef __SC_PMU_H_
#define __SC_PMU_H_

#include <bsp_sppm.h>

#define SYSCACHE_CFG_BASE 0xE2800000
#define SYSCACHE_CFG_LEN 0x50000

#define SC_PMU_SPPM_SEL(n) ((n) & 0xff)
#define SC_PMU_MAX 8

#define SC_STATIS_SLICE_CTRL0(slc, sc_static_num) ((slc) * 0x10000 + 0x200 + (sc_static_num) * 0x8)
#define SC_STATIS_SLICE_CTRL1(slc, sc_static_num) ((slc) * 0x10000 + 0x204 + (sc_static_num) * 0x8)


#define SC_STATIS_GLB_EN 0x220

#define SC_PMU_EVCNT(slc, pmu_id) ((slc) * 0x10000 + 0x2000 + 0xD80 + (pmu_id) * 04)
#define SC_PMU_CNTEN(slc) ((slc) * 0x10000 + 0x2000 + 0xDE0)
#define SC_PMU_CFG(slc) ((slc) * 0x10000 + 0x2000 + 0xDE8)
#define SC_PMU_CAPR(slc) ((slc) * 0x10000 + 0x2000 + 0xDEC)

#define SC_PMU_FLT_CTRL0(slc) ((slc) * 0x10000 + 0x2000 + 0xC70)
#define SC_PMU_FLT_CTRL1(slc) ((slc) * 0x10000 + 0x2000 + 0xC74)
#define SC_PMU_FLT_CTRL3(slc) ((slc) * 0x10000 + 0x2000 + 0xc7c)
#define SC_PMU_FLT_CTRL4(slc) ((slc) * 0x10000 + 0x2000 + 0xc80)
#define SC_PMU_EVTYPE(slc, sc_pmu_idx) (((slc) * 0x10000 + 0x2000 + 0xdc0) + (sc_pmu_idx) * 0x4)


#define COUNT_TYPE_CHI 0x5000
#define COUNT_TYPE_QTPE 0xa000
#define SC_PMU_GID_CFG 0xfff0000
#define SC_PMU_FLT_MID_SNE_CFG 0xffff1414
#define SC_PMU_FLT_MID_L2DLE_CFG 0xffff9a9a
#define SC_PMU_FLT_MID_ACPU_CFG 0xffff3030

#define SC_PMU_REQ_OPC_CFG_READONCE_READCLEAN 0x3FFF0103
#define SC_PMU_REQ_OPC_CFG_READONSD_READUNIQUE 0x3FFF03A6
#define SC_PMU_REQ_OPC_CFG_WRITENOSNP_WRITENOSNPPTRL 0x3FFF0E1D
#define SC_PMU_REQ_OPC_CFG_WRITEUNIQUE_WRITEUNIQUEPTRL 0x3FFF0C19

#define SC_PMU_REQ_OPC_CFG_READNOSNP  0x3FFF0004
#define SC_PMU_REQ_OPC_CFG_READ_ONCE_CLEAN_INVALID 0x3FFF0024

#define SC_SLICE_CNT 4

#define SC_PMU_EVENT_SF_HIT_FLT0 0x25
#define SC_PMU_EVENT_SF_HIT_FLT1 0x26
#define SC_PMU_EVENT_SF_ACCESS_FLT0 0x27
#define SC_PMU_EVENT_SF_ACCESS_FLT1 0x28

#define SC_PMU_EVENT_TAG_HIT_FLT0 0x2B
#define SC_PMU_EVENT_TAG_HIT_FLT1 0x2C
#define SC_PMU_EVENT_TAG_ACCESS_FIT0 0x2D
#define SC_PMU_EVENT_TAG_ACCESS_FIT1 0x2E
#define SC_PMU_EVENT_SC_FLT0 0x2F
#define SC_PMU_EVENT_SC_FLT1 0x30


typedef union {
    struct {
        unsigned int statis_mid : 8;
        unsigned int statis_mid_mask_n : 8;
        unsigned int gid_statis_en : 16;
    } bits;
    unsigned int val;
} sc_statis_slice_ctrl0;

typedef union {
    struct {
        unsigned int type_statis_en : 11;
        unsigned int statis_mode : 1;
        unsigned int bypass_statis_en : 3;
        unsigned int slice_statis_en : 1;
        unsigned int statis_pgid : 6;
        unsigned int reserved0 : 2;
        unsigned int statis_pgid_mask_n : 6;
        unsigned int reserved1 : 2;
    } bits;
    unsigned int val;
} sc_statis_slice_ctrl1;

typedef union {
    struct {
        unsigned int pmu_en : 1;
        unsigned int pmu_ovcap_en : 1;
        unsigned int pmu_ckg_byp : 1;
        unsigned int pmu_cap_clear_en : 1;
        unsigned int pmu_cfg_non_ull_en : 1;
        unsigned int reserved : 27;
    } bits;
    unsigned int val;
} sc_pmu_cfg;


typedef struct {
    u32 sel;
} sc_pmu_sppm_cfg_s;

typedef struct {
    sc_pmu_sppm_cfg_s sppm_cfg;
    char *regs_pmu;
    u32 sppm_chan;
    u32 sppm_bak_flag;
    sppm_client_pd_notify sppm_notify;
} sc_pmu_sppm_info_s;


void sc_pmu_sppm_register(void);

#endif