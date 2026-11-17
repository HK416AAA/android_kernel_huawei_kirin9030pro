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

#include <bsp_dump.h>
#include "ddr_mntn.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include "adrv_ddr_stat.h"

ddr_dump_info_s g_ddr_dump = {0};
void ddr_dump_hook(void)
{
    u32 len;
    ddr_stat_bandwidth_mntn();
    len = ddr_stat_bandwidth_record_for_modem(
        (unsigned int *)g_ddr_dump.band_exception_base, g_ddr_dump.band_exception_size);
    return;
}

static int ddr_dump_register_field(void)
{
    ddr_dump_head_s *ddr_dump_head = NULL, *ddr_band_exception_head = NULL, *ddr_event_head = NULL;

    g_ddr_dump.dump_base = bsp_dump_register_field(DUMP_MODEMAP_MDM_DDR, "DDR", DDR_DUMP_SIZE, 0);
    if (g_ddr_dump.dump_base == NULL) {
        ddr_err("get ddr field fail!\n");
        return DDR_ERR_ENOMEM;
    }
    g_ddr_dump.dump_size = DDR_DUMP_SIZE;
    (void)memset_s(g_ddr_dump.dump_base, g_ddr_dump.dump_size, 0, g_ddr_dump.dump_size);

    ddr_dump_head = (ddr_dump_head_s *)g_ddr_dump.dump_base;
    ddr_dump_head->modid = DDR_DUMP_MAGIC;
    ddr_dump_head->len = DDR_DUMP_SIZE - sizeof(ddr_dump_head_s);

    ddr_band_exception_head = ddr_dump_head + 1;
    ddr_band_exception_head->modid = DDR_BAND_EXCEPTION_MAGIC;
    ddr_band_exception_head->len = DDR_BAND_EXCEPTION_SIZE - sizeof(ddr_dump_head_s);

    ddr_event_head = (ddr_dump_head_s *)((u8 *)ddr_band_exception_head + DDR_BAND_EXCEPTION_SIZE);
    ddr_event_head->modid = DDR_BAND_EVENT_MAGIC;
    ddr_event_head->len = DDR_BAND_EVENT_SIZE - sizeof(ddr_dump_head_s);

    g_ddr_dump.band_exception_base = (u8 *)(ddr_band_exception_head + 1);
    g_ddr_dump.band_exception_size = ddr_band_exception_head->len;

    g_ddr_dump.band_event_base = (u8 *)(ddr_event_head + 1);
    g_ddr_dump.band_event_size = ddr_event_head->len;

    if (bsp_dump_register_hook("DDR", (dump_hook)ddr_dump_hook) == -1) {
        ddr_err("ddr_dump_hook init fail\n");
        return DDR_ERR_EIO;
    }
    return 0;
}

int bsp_ddr_dump_init(void)
{
    int ret;

    ret = ddr_dump_register_field();
    if (ret != 0) {
        ddr_err("ddr_dump init err\n");
        return ret;
    }
    ddr_err("ddr_dump init ok\n");
    return 0;
}

EXPORT_SYMBOL(ddr_dump_hook);

#if !IS_ENABLED(CONFIG_MODEM_DRIVER)
module_init(bsp_ddr_dump_init);
#endif