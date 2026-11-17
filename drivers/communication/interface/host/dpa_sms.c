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
#include "dpa_version.h"
#include "dpa_sms.h"

static struct dpa_sms_ops *g_dpa_sms_ops;

int dpa_sms_api_register(struct dpa_sms_ops *sms_ops)
{
    if (sms_ops == NULL) {
        return -1;
    }

    g_dpa_sms_ops = sms_ops;

    return 0;
}
EXPORT_SYMBOL(dpa_sms_api_register);

int dpa_sms_sync_netdev_ops(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_sync_netdev == NULL) {
        dpa_err("Not Support dpa_sms_sync_netdev API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_sync_netdev(nic, dev, priv_info, event);
}
EXPORT_SYMBOL(dpa_sms_sync_netdev_ops);

int dpa_sms_filter_add_entry_ops(enum dpa_sms_nic nic, struct sk_buff *skb)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_filter_add_entry == NULL) {
        dpa_err("Not Support dpa_sms_filter_add_entry_ops API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_filter_add_entry(nic, skb);
}
EXPORT_SYMBOL(dpa_sms_filter_add_entry_ops);

int dpa_sms_tx_ops(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_tx == NULL) {
        dpa_err("Not Support dpa_sms_tx API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_tx(skb, nic, offload_en);
}
EXPORT_SYMBOL(dpa_sms_tx_ops);

int dpa_sms_rx_callback_register_ops(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_rx_callback_register == NULL) {
        dpa_err("Not Support dpa_sms_rx_callback_register API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_rx_callback_register(nic, cb);
}
EXPORT_SYMBOL(dpa_sms_rx_callback_register_ops);

unsigned long long dpa_sms_get_netdev_feature_ops(void)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_get_netdev_feature == NULL) {
        dpa_err("Not Support dpa_sms_get_netdev_feature API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_get_netdev_feature();
}
EXPORT_SYMBOL(dpa_sms_get_netdev_feature_ops);

int dpa_sms_tx_nodrop_ops(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en)
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_tx_nodrop == NULL) {
        dpa_err("Not Support dpa_sms_tx API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_tx_nodrop(skb, nic, offload_en);
}
EXPORT_SYMBOL(dpa_sms_tx_nodrop_ops);

int dpa_sms_tx_unblock_cb_register_ops(void (*cb)(void))
{
    if (g_dpa_sms_ops == NULL) {
        dpa_err("Not Register dpa sms API!\n");
        return -ENOSYS;
    }

    if (g_dpa_sms_ops->dpa_sms_tx_unblock_cb_register == NULL) {
        dpa_err("Not Support dpa_sms_tx API!\n");
        return -ENOSYS;
    }

    return g_dpa_sms_ops->dpa_sms_tx_unblock_cb_register(cb);
}
EXPORT_SYMBOL(dpa_sms_tx_unblock_cb_register_ops);