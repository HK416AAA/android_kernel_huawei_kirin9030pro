/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
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
 */

#ifndef DPA_CLK_H
#define DPA_CLK_H
#include <linux/workqueue.h>

#define DFS_MAX_LEVEL 10
typedef struct {
    struct clk **clks;
    unsigned int clks_num;
    unsigned int clk_dpa_index;
    unsigned int clk_div;
    unsigned int dpa_fre_grade_max;
    unsigned int div_profile[DFS_MAX_LEVEL];
    unsigned int cur_profile;
    unsigned int low_temprature_freq;
    unsigned int freq_lock;

    spinlock_t lock;
    unsigned int stat;
    unsigned int *profile_sync;
    struct workqueue_struct *workqueue;
    struct work_struct work;
    struct wakeup_source *ws;

    unsigned int load_max;
} dpa_clk_ctrl_s;

#ifdef CONFIG_DPA_PM
void dpa_set_clk_rate(unsigned int freq_value);
void dpa_disable_clks(void);
int dpa_enable_clks(void);
int dpa_init_clks(struct platform_device *pdev, struct device_node *np);
#else
static inline void dpa_set_clk_rate(unsigned int freq_value)
{
    return;
}
static inline void dpa_disable_clks(void)
{
    return;
}
static inline int dpa_enable_clks(void)
{
    return 0;
}
static inline int dpa_init_clks(struct platform_device *pdev, struct device_node *np)
{
    return 0;
}
#endif
#endif
