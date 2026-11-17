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

#ifndef BSP_DPA_H
#define BSP_DPA_H
#include <linux/types.h>

typedef enum {
    MODEM_REST_BEFORE_REQ = 1,
    MODEM_REST_BEFORE_FAIL,
    MODEM_REST_BEFORE_DONE,
    MODEM_REST_AFTER_REQ,
    MODEM_REST_AFTER_FAIL,
    MODEM_REST_AFTER_DONE,
    MODEM_REST_BEGIN,
    MODEM_REST_END,
    STATUS_BUTT
} mdm_rst_status_e;

typedef enum dpa_clk_grade {
    DPA_CLK_GRADE_200M,
    DPA_CLK_GRADE_400M,
    DPA_CLK_GRADE_800M,
    DPA_CLK_GRADE_BOTTOM
} dpa_clk_grade_e;

typedef enum peri_volt_trend {
    PERI_VOLT_NO_CHANGE,
    PERI_VOLT_DOWN,
    PERI_VOLT_UP,
    PERI_VOLT_TREND_BOTTOM
} peri_volt_trend_e;

typedef enum {
    DPA_REGS_ACCESS_DPA_SYSCTRL_CRG = 0,
    DPA_REGS_ACCESS_TSP_MPSS,
    DPA_REGS_ACCESS_TSP_DSS0,
    DPA_REGS_ACCESS_BUTT,
} dpa_regs_access_state_e;

typedef enum {
    DPA_DVFS_PFA,
    DPA_DVFS_TYPE_MAX,
} dpa_dvfs_type_e;

typedef void (*dpa_dvfs_ops)(unsigned int time, unsigned int *speed);
static inline int bsp_dpapm_get_dpa_access_state(dpa_regs_access_state_e dpa_regs_region)
{
    return -1;
}

struct clk_notify {
    struct list_head list;
    void (*dpa_clk_max_notify)(void);
    void (*dpa_clk_descent_notify)(void);
};
int bsp_clk_reg_notify(struct clk_notify *notify);
#endif
