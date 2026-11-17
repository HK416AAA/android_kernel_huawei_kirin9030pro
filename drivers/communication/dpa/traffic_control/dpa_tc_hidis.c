/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2025. All rights reserved.
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

#include <securec.h>
#include "bsp_dpa_net_om.h"
#include "dpa_tc_hidis.h"
#include "dpa_tc_util.h"

static dpa_tc_stats_info_s g_dpa_tc_info = {0};
static struct net_om_info g_dpa_tc_report_attr = {0};

static void dpa_tc_statistics_translate(void){
    int index;
    g_dpa_tc_info.print_mask = g_dpa_tc_print;
    g_dpa_tc_info.func_mask = g_dpa_tc_func;
    (void)strcpy_s(g_dpa_tc_info.stats_ver, STATS_VER_LEN, TC_STATS_VER);

    for (index = 0; index < MAX_STATS_NUM && index < MAX_REPORT_STATS_NUM ; index++){
        g_dpa_tc_info.statistics[index] = atomic_read(&g_dpa_tc_statistics[index]);
    }

    if (MAX_STATS_NUM > MAX_REPORT_STATS_NUM) {
        TC_PRINT_ERR("dpa tc hidis report error: max stats num %d > max report stat num %d\n", 
                        MAX_STATS_NUM, MAX_REPORT_STATS_NUM);
    }

    return;
}

void dpa_tc_hidis_report_register(void)
{
    struct net_om_info *info = &g_dpa_tc_report_attr;
    int ret;

    info->ul_msg_id = DPA_HOST_NET_OM_TC_STATS;
    info->data = (void *)&g_dpa_tc_info;
    info->size = sizeof(g_dpa_tc_info);
    info->func_cb = dpa_tc_statistics_translate;
    INIT_LIST_HEAD(&info->list);

    ret = bsp_dpa_net_report_register(info);
    if (ret) {
        TC_PRINT_ERR("dpa tc hidis report register fail\n");
        return;
    }

    TC_PRINT_ERR("dpa tc hidis report register success\n");
    return;
}
