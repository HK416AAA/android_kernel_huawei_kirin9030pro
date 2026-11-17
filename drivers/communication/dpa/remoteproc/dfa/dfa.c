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

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <bsp_dmi.h>
#include <dpa_reset.h>
#include <bsp_mem_layout.h>
#include <bsp_print.h>
#include "dfa.h"

#define DFA_CMA_SIZE 0x9000

dma_addr_t g_dfa_cma_phy_addr = 0;

int dfa_send_to_dpa(void)
{
    int ret;
    struct dmi_msg *msg = NULL;
    struct dfa_cma_addr_para *buf = NULL;
    unsigned int len = sizeof(struct dmi_msg) + sizeof (struct dfa_cma_addr_para);

    msg = (struct dmi_msg *)kmalloc(len, GFP_KERNEL);

    buf = (struct dfa_cma_addr_para *)msg->data.buf;
    buf->dfa_cma_addr_phy = g_dfa_cma_phy_addr;
    buf->dfa_cma_size = DFA_CMA_SIZE;

    msg->plane = DMI_SERVICE_TYPE_COMM;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_DFA;
    msg->data.len = len - sizeof(struct dmi_msg);

    ret = bsp_dmi_client_request_comm_wake(msg, len);
    if (ret) {
        dpa_pr_err("dpa client dfa send fail:%d\n", ret);
    }
    kfree(msg);

    return 0;
}

int dfa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    switch (enparam) {
        case DPA_RESET_BEFORE:
            break;
        case DPA_RESET_AFTER:
            dfa_send_to_dpa();
            break;
        default:
            break;
    }
    return 0;
}

int dfa_alloc_cma_init(void)
{
    void *vaddr = NULL;

    vaddr = bsp_dpa_rsv_cma_alloc(DFA_CMA_SIZE, &g_dfa_cma_phy_addr);
    if (vaddr == NULL) {
        dpa_pr_err("dfa alloc cma mem faild\n");
    }

    dfa_send_to_dpa();

    if (bsp_dpa_reset_register_cb("dfa_reset", dfa_reset_cb, 0, DPA_RESET_CB_LEVEL_COMMON)) {
        dpa_pr_err("dfa reset register failed\n");
        return -1;
    }
    dpa_pr_err("dfa_alloc_cma_init\n");

    return 0;
}