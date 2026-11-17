/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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
#include <osl_sem.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <securec.h>
#include <bsp_ipc_fusion.h>

#include "sensorhub_dump.h"
#include "sensorhub_reset.h"

struct sensorhub_rst_dump_info *g_sensorhub_rst_dump_info = NULL;

void sensorhub_rst_dump_record(sensorhub_rst_stamp_id idx, unsigned int arg1, unsigned int arg2)
{
    struct sensorhub_rst_dump_info *dump_info = g_sensorhub_rst_dump_info;
    if (dump_info == NULL) {
        return;
    }
    if (idx >= SENSHUB_RST_STAMP_NUM) {
        return;
    }
    dump_info->record_point[idx].timestamp = bsp_get_slice_value();
    dump_info->record_point[idx].arg1 = arg1;
    dump_info->record_point[idx].arg2 = arg2;
    return;
}

int sensorhub_rst_dump_init(void)
{
    int ret;
    unsigned int dump_size;

    dump_size = sizeof(struct sensorhub_rst_dump_info);
    if (dump_size > SENSORHUB_RST_DUMP_SIZE) {
        sensorhub_rst_err("dump_size is overflow\n");
        return SENSORHUB_RST_ERR;
    }

    g_sensorhub_rst_dump_info = (struct sensorhub_rst_dump_info *)
        bsp_dump_register_field(DUMP_MODEMAP_SENSORHUB_RST, "SENSORHUB_RST", dump_size, 0);
    if (g_sensorhub_rst_dump_info == NULL) {
        sensorhub_rst_err("dump space register failed\n");
        return SENSORHUB_RST_ERR;
    }

    (void)memset_s(g_sensorhub_rst_dump_info, dump_size, 0, dump_size);
    g_sensorhub_rst_dump_info->len = dump_size;
    g_sensorhub_rst_dump_info->version = SENSORHUB_RST_DUMP_VERSION;

    return SENSORHUB_RST_OK;
}