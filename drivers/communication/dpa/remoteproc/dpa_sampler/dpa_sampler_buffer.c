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

#include <asm/memory.h>
#include <asm/irq_regs.h>
#include <asm/irqflags.h>
#include <asm/string.h>
#include <securec.h>
#include <bsp_dt.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
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
#include <dpa_mem_layout.h>
#include "dpa_sampler.h"

#undef THIS_MODU
#define THIS_MODU mod_dpa_sampler

int dpa_sampler_rb_write(dpa_sampler_buffer *buf, u32 mode, void *data, u32 data_len)
{
    if (!buf || !buf->virt_addr || buf->buffer_size == 0 || !data || data_len == 0) {
        return DPA_SAMPLER_ERR;
    }

    unsigned char *addr = (unsigned char *)buf->virt_addr;
    const unsigned char *src = (const unsigned char *)data;

    if (mode == WRITE_FULL && buf->data_size == buf->buffer_size)
        return DPA_SAMPLER_OK;
    
    if (buf->rb_wptr == buf->buffer_size) {
        buf->rb_wptr = 0;
    }

    u32 first_chunk = buf->buffer_size - buf->rb_wptr;
    if (first_chunk > data_len) {
        first_chunk = data_len;
    }

    if (memcpy_s(addr + buf->rb_wptr, first_chunk, src, first_chunk)) {
        dpa_sampler_err("memcpy first err\n");
        return DPA_SAMPLER_ERR;
    }

    buf->rb_wptr += first_chunk;
    buf->data_size += first_chunk;
    buf->data_size = (buf->data_size > buf->buffer_size) ? buf->buffer_size : buf->data_size;

    u32 remaining = data_len - first_chunk;
    if (mode == CYCLE_WRITE && remaining > 0) {
        if (memcpy_s(addr, remaining, src + first_chunk, remaining)) {
            dpa_sampler_err("memcpy remain err\n");
            return DPA_SAMPLER_ERR;
        }
        buf->rb_wptr = remaining;
    }

    return DPA_SAMPLER_OK;
}

int dpa_sampler_rb_alloc(void)
{
    u32 i;
    dpa_sampler_ctrl_t *ctrl = dpa_sampler_get_ctrl();
    for (i = 0; i < ctrl->sample_core_num; i++) {
        void *virt_addr = NULL;
        dma_addr_t phy_addr;
        virt_addr = bsp_dpa_cma_alloc(ctrl->buffers[i].buffer_size, &phy_addr, GFP_KERNEL);
        if (virt_addr == NULL) {
            dpa_sampler_err("<%s> cannot allocate ring buffer\n", __func__);
            return DPA_SAMPLER_ERR;
        }
        ctrl->buffers[i].phy_addr = (uintptr_t)phy_addr;
        ctrl->buffers[i].virt_addr = (uintptr_t)virt_addr;
        (void)memset_s(
            (void *)ctrl->buffers[i].virt_addr, ctrl->buffers[i].buffer_size, 0x00, ctrl->buffers[i].buffer_size);
    }
    return DPA_SAMPLER_OK;
}

int dpa_sampler_rb_release(void)
{
    u32 i;
    dpa_sampler_ctrl_t *ctrl = dpa_sampler_get_ctrl();
    for (i = 0; i < ctrl->sample_core_num; i++) {
        if (ctrl->buffers[i].virt_addr) {
            bsp_dpa_cma_free(
                ctrl->buffers[i].buffer_size,
                (void *)ctrl->buffers[i].virt_addr,
                (dma_addr_t)ctrl->buffers[i].phy_addr);
            ctrl->buffers[i].virt_addr = 0x00UL;
            ctrl->buffers[i].phy_addr = 0x00UL;
            ctrl->buffers[i].buffer_size = 0x0;
            ctrl->buffers[i].rb_rptr = 0x0;
            ctrl->buffers[i].rb_wptr = 0x0;
            ctrl->buffers[i].data_size = 0x0;
        }
    }
    return DPA_SAMPLER_OK;
}
