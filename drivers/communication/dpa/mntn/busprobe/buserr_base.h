/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
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

#ifndef __BUSERR_BASE_H__
#define __BUSERR_BASE_H__

#include <bsp_print.h>

#ifdef __cplusplus
extern "C" {
#endif

#define bus_printf(fmt, ...)     dpa_pr_err("[buserr]" "<%s>" fmt, __FUNCTION__, ##__VA_ARGS__)

#define BUS_ERR_MAGIC_NUM  0x33333333
#define BUS_ERR_REG_SIZE   3
#define IOREMAP_LENGTH     0x1000
#define ERR_NAME_LENGTH    32
#define BUS_BIT_MAX        32

enum {
    BUS_ERR_DISABLE = 0,
    BUS_ERR_ENABLE = 1
};

struct buserr_state_bit {
    u32 bit;
    char err_name[ERR_NAME_LENGTH];
    u32 err_type;
};

struct buserr_state_reg {
    u32 err_state_reg_offset;
    u32 bit_sum;
    struct buserr_state_bit *err_state_bit;
};

struct buserr_sysctrl {
    u32 int_counter;
    u32 irq;
    u32 reg_sum;
    void *base_addr;
    struct buserr_state_reg *err_state_reg;
};

struct buserr_cfg {
    unsigned int int_en;
    unsigned int axi_rst;
    unsigned int qic_rst;
};

typedef struct buserr_ctrl {
    struct buserr_cfg cfg;
    struct buserr_sysctrl sctrl_peri; /* sys bus */
} buserr_ctrl_s;

buserr_ctrl_s* bsp_buserr_ctrl(void);
struct buserr_sysctrl *bsp_buserr_sctrl_get_by_irq(u32 irq);
s32 bsp_buserr_probe_init(void);

#ifdef __cplusplus
}
#endif

#endif