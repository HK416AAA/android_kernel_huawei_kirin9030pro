/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
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

#include <asm/memory.h>
#include <asm/irq_regs.h>
#include <asm/irqflags.h>
#include <asm/string.h>
#include <bsp_sysctrl.h>
#include <securec.h>
#include <bsp_dt.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/of_platform.h>
#include <linux/mm.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/platform_device.h>
#include <linux/vmalloc.h>
#include <linux/gfp.h>
#include <linux/dma-direction.h>
#include <linux/dma-mapping.h>
#include <linux/dma-map-ops.h>
#include "bsp_mperf.h"
#include "../sppm/sppm_device.h"

#undef THIS_MODU
#define THIS_MODU mod_mperf
#define DIAG_ADD_MPERF_HEAD_LEN 128

mperf_dpa_dev_info g_mperf_dpa_dev_info = {0};

mperf_dpa_dev_info *mperf_get_dpa_dev_info(void)
{
    return &g_mperf_dpa_dev_info;
}

int mperf_dpa_ringbuff_alloc(void)
{
    mperf_dpa_dev_info *dev_info = &g_mperf_dpa_dev_info;
    sppm_dev_info *sppm_dev_info_t = sppm_get_dev_info();
    void *virt_addr = NULL;
    dma_addr_t phy_addr;
    dev_info->dev = sppm_dev_info_t->dev;
    virt_addr = dma_alloc_coherent(dev_info->dev, dev_info->rb_size + DIAG_ADD_MPERF_HEAD_LEN, &phy_addr, GFP_KERNEL);
    mperf_err("<%s>  ringbuff with size %d\n", __func__, dev_info->rb_size + DIAG_ADD_MPERF_HEAD_LEN);
    if (virt_addr == NULL) {
        mperf_err("<%s> cannot allocate ring buffer\n", __func__);
        return BSP_ERROR;
    }
    dev_info->virt_addr = (uintptr_t)virt_addr + DIAG_ADD_MPERF_HEAD_LEN;
    dev_info->rb_phy_addr = (uintptr_t)phy_addr + DIAG_ADD_MPERF_HEAD_LEN;
    (void)memset_s((void *)dev_info->virt_addr, dev_info->rb_size, 0x00, dev_info->rb_size);
    return BSP_OK;
}

int mperf_dpa_ringbuff_release(void)
{
    mperf_dpa_dev_info *dev_info = &g_mperf_dpa_dev_info;
    if (dev_info->virt_addr) {
        dma_free_coherent(
            dev_info->dev,
            dev_info->rb_size+DIAG_ADD_MPERF_HEAD_LEN,
            (void *)dev_info->virt_addr-DIAG_ADD_MPERF_HEAD_LEN,
            (dma_addr_t)dev_info->rb_phy_addr-DIAG_ADD_MPERF_HEAD_LEN);
    }
    dev_info->dev = NULL;
    dev_info->virt_addr = 0x00UL;
    dev_info->rb_phy_addr = 0x00UL;
    dev_info->rb_size = 0x00;
    dev_info->data_size = 0x00;
    return BSP_OK;
}