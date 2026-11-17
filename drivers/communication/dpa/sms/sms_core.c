/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
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

#include "bsp_print.h"
#include "bsp_sms.h"

struct dpa_sms_ops g_sms_ops = {
    .dpa_sms_sync_netdev = dpa_sms_sync_netdev,
    .dpa_sms_filter_add_entry = dpa_sms_filter_add_entry,
    .dpa_sms_tx = dpa_sms_tx,
    .dpa_sms_rx_callback_register = dpa_sms_rx_callback_register,
    .dpa_sms_get_netdev_feature = dpa_sms_get_netdev_feature,
    .dpa_sms_tx_nodrop = dpa_sms_tx_nodrop,
    .dpa_sms_tx_unblock_cb_register = dpa_sms_tx_unblock_cb_register,
};

int bsp_sms_init(void)
{
    int ret;

    /* netdev init*/
    ret = bsp_dpa_sms_netdev_init();
    if (ret) {
        dpa_pr_fatal("sms netdev init faill\n");
        return ret;
    }

    /* filter init */
    ret = sms_filter_init();
    if (ret) {
        dpa_pr_fatal("sms netdev init faill\n");
        return ret;
    }

    /* rx gro init */
    ret = sms_gro_init();
    if (ret) {
        dpa_pr_fatal("sms netdev init faill\n");
        return ret;
    }

    /* tx gso init */
    ret = sms_gso_init();
    if (ret) {
        dpa_pr_fatal("sms netdev init faill\n");
        return ret;
    }

    /* api register */
    ret = dpa_sms_api_register(&g_sms_ops);
    if (ret) {
        dpa_pr_fatal("sms api regist fail\n");
        return ret;
    }

    return 0;
}
