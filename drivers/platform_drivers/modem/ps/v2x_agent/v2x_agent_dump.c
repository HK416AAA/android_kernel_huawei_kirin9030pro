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
#include <securec.h>
#include "bsp_v2x_agent.h"
#include "mdrv_om.h"
#include "mdrv_timer.h"
#include "v2x_agent.h"
#include "v2x_agent_dump.h"
#include "v2x_agent_log_print.h"

struct v2x_agent_dump_info g_v2x_agent_dump_info = {0};

int v2x_agent_dump_init(void)
{
    g_v2x_agent_dump_info.base_addr = mdrv_om_register_field(OM_AP_V2X_AGENT, "v2x_agent", V2X_AGENT_DUMP_SIZE, 0);
    if (g_v2x_agent_dump_info.base_addr == NULL) {
        v2x_print_error("get v2x_agent dump fail!\n");
        return -1;
    }

    if (memset_s((void *)g_v2x_agent_dump_info.base_addr, V2X_AGENT_DUMP_SIZE, 0, V2X_AGENT_DUMP_SIZE)) {
        v2x_print_error("v2x_agent dump memset_s error!\n");
        return -1;
    }

    g_v2x_agent_dump_info.hids_info_addr = g_v2x_agent_dump_info.base_addr + V2X_AGENT_DUMP_DEBUG_SIZE;
    return 0;
}

void bsp_v2x_agent_dump_rec(u32 event_index, u32 event_info)
{
    int ret, dump_cur;
    struct v2x_agent_hids_info hids_info;
    if (event_index >= V2X_AGENT_EVENT_MAX || g_v2x_agent_dump_info.base_addr == NULL) {
        return;
    }


    *((u32 *)g_v2x_agent_dump_info.base_addr + event_index) = event_info;

    hids_info.event = event_index;
    hids_info.timestamp = mdrv_timer_get_normal_timestamp();
    hids_info.downlink_rptr = *((u32 *)g_v2x_agent_dump_info.base_addr + V2X_AGENT_DOWNLINK_RPTR);
    hids_info.downlink_wptr = *((u32 *)g_v2x_agent_dump_info.base_addr + V2X_AGENT_DOWNLINK_WPTR);
    hids_info.uplink_rptr = *((u32 *)g_v2x_agent_dump_info.base_addr + V2X_AGENT_UPLINK_RPTR);
    hids_info.uplink_wptr = *((u32 *)g_v2x_agent_dump_info.base_addr + V2X_AGENT_UPLINK_WPTR);

    dump_cur = g_v2x_agent_dump_info.cur;
    if (dump_cur >= (V2X_AGENT_DUMP_HIDIS_SIZE / sizeof(struct v2x_agent_hids_info))) {
        dump_cur = 0;
    }

    ret = memcpy_s((struct v2x_agent_hids_info *)g_v2x_agent_dump_info.hids_info_addr + dump_cur,
        sizeof(struct v2x_agent_hids_info), (void *)&hids_info, sizeof(struct v2x_agent_hids_info));
    if (ret) {
        v2x_print_error("memcpy_s error, ret = 0x%x\n", ret);
        return;
    }

    g_v2x_agent_dump_info.cur = (dump_cur + 1) % (V2X_AGENT_DUMP_HIDIS_SIZE / sizeof(struct v2x_agent_hids_info));
    return;
}
