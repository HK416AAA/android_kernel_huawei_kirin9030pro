/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
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

#ifndef __BUSERR_PDLOCK_H__
#define __BUSERR_PDLOCK_H__

#include <bsp_print.h>

#ifdef __cplusplus
extern "C" {
#endif

#define pdlock_print(fmt, ...)    dpa_pr_err("[pdlock]" "<%s>" fmt, __FUNCTION__, ##__VA_ARGS__)

#define PDLK_REG_SZ2 (2)
#define PDLK_REG_SZ3 (3)
#define PDLOCK_RECORD_MAGIC_NUM 0x1A2B3C4D

#define PDLOCK_OK (0)
#define PDLOCK_ERROR (-1)
#define PDLK_BUS_NAME_LEN       32
#define PDLK_REG_VER_LEN        32
#define PDLOCK_SCTRL_REG_ARRY   2

/* sysctrl buserr state reg info */
#define PDLOCK_ERR_ID_MASK    0xFFFF
#define PDLOCK_ERR_ID_BIT     16
#define PDLOCK_ERR_CODE_MASK  0xFF
#define PDLOCK_ERR_CODE_BIT   8
#define PDLOCK_ERR_OPC_MASK   0x1
#define PDLOCK_ERR_OPC_BIT    1
#define PDLOCK_ERR_STATE_MASK 0x1
#define PDLOCK_ERR_STATE_BIT  0

#define PDLOCK_COFIG_REG_MAX  5

enum {
    PDLOCK_DISABLE = 0,
    PDLOCK_ENABLE = 1
};

enum {
    PDLOCK_REG_BASE = 0,
    PDLOCK_REG_OFFSET = 1,
    PDLOCK_REG_START_BIT = 2,
    PDLOCK_REG_END_BIT = 3,
    PDLOCK_REG_SET_VAL = 4,
    PDLOCK_REG_BUTT
};
enum {
    PDLOCK_SRST_OFFSET = 0,
    PDLOCK_SRST_START_BIT = 1,
    PDLOCK_SRST_END_BIT = 2,
    PDLOCK_SRST_BUTT
};

typedef struct {
    u32 offset;         /* 寄存器偏移 */
    u32 start_bit;      /* 寄存器起始位 */
    u32 end_bit;        /* 寄存器终止位 */
} pdlock_reg_s;

typedef struct {
    u32   phy_addr;
    void *vir_addr;
    u32 offset;         /* 寄存器偏移 */
    u32 start_bit;      /* 寄存器起始位 */
    u32 end_bit;        /* 寄存器终止位 */
    u32 set_val;        /* 寄存器配置值 */
} pdlock_config_reg_s;

typedef struct {
    u32   phy_addr;
    void *vir_addr;
    char  err_bus_name[PDLK_BUS_NAME_LEN];
    u32   err_reg;
    u32   err_addr;
    pdlock_reg_s srst_reg;
    u32   powerdown_check;
} pdlock_apb_ahb_state_reg_s;

typedef struct {
    u32 init_flag;
    u32 err_base_idx;
    u32 err_base_num;
    u32 err_mid;
    u32 chipid;
    pdlock_apb_ahb_state_reg_s *err_base;
    u32 config_reg_cnt;
    pdlock_config_reg_s *config_reg;
} pdlock_axb_err_info_s;

struct pdlock_dump_record {
    u32 magic_num;
    u32 chip_version;
    u32 axi_base_addr; /* phy_addr */
    u32 idx;
    char err_bus_name[PDLK_BUS_NAME_LEN];
    u32 errlog1;
    u32 errlog2;
    u32 rsv;
};

s32 bsp_pdlock_init(void);

#ifdef __cplusplus
}
#endif

#endif
