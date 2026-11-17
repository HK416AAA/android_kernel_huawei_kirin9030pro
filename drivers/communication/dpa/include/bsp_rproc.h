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

#ifndef __BSP_RPROC_H__
#define __BSP_RPROC_H__

#include <linux/printk.h>
#include <linux/remoteproc.h>
#include <dpa_rproc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RPROC_DPA_INIT_STEP2 0x2
#define RPROC_DPA_INIT_STEP3 0x3

#define RPROC_EVENT_DPA_FW_MODULE_INIT_DONE 0
#define RPROC_EVENT_DPA_HOST_INIT_AFTER_FW_DRST_DONE 1

typedef int (*dpa_powerup_cb)(unsigned int step);

int bsp_rproc_stop(void);
int bsp_rproc_boot(void);

#ifdef CONFIG_DPA_PM
int bsp_rproc_dpa_get_stat(void);
void bsp_rproc_reg_dpa_powerup_cb(dpa_powerup_cb cb);
void bsp_rproc_set_event(unsigned int event);
bool is_wan_path_switch_acpu(void);
void bsp_rproc_report_crash(void);
#else
static inline int bsp_rproc_dpa_get_stat(void)
{
    return RPROC_OFFLINE;
}
static inline void bsp_rproc_reg_dpa_powerup_cb(dpa_powerup_cb cb)
{
    return;
}
static inline void bsp_rproc_set_event(unsigned int event)
{
    return;
}
#endif
#ifdef __cplusplus
}
#endif

#endif