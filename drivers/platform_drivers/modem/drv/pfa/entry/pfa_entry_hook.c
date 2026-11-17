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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/netfilter_bridge.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/switchdev.h>
#include "pfa_direct_fw.h"
#include "pfa.h"
#include "pfa_ip_entry.h"
#include "pfa_mac_entry.h"
#include "pfa_port.h"
#include "pfa_dbg.h"
#include "pfa_port.h"
#include "pfa_direct_fw.h"

#ifdef CONFIG_PFA_DIRECT_FW
#include <net/netfilter/br_netfilter.h>
#ifdef CONFIG_DPA_PROTO
#include <pfa_interface.h>
#else
#include <linux/pfa/pfa_interface.h>
#endif
#endif

#ifdef CONFIG_PFA_DIRECT_FW
struct pfa_hook_ops g_pfa_hook = {0};
#endif

#ifdef CONFIG_PFA_DIRECT_FW

int pfa_skb_is_updateonly(void *skb)
{
    struct sk_buff *pfa_skb = NULL;

    pfa_skb = (struct sk_buff *)skb;

    if (pfa_skb->update_only) {
        g_pfa.cpuport.cpu_updonly_comp++;
        if (unlikely(g_pfa.msg_level & PFA_MSG_TUPLE)) {
            PFA_ERR("update only complete! \n");
        }
    }
    return (int)(pfa_skb->update_only);
}

unsigned int pfa_ip_hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    struct nf_conn *ct = NULL;
    enum ip_conntrack_info ctinfo;

    ct = nf_ct_get(skb, &ctinfo);
    if (ct != NULL) {
#ifdef CONFIG_DPA_PROTO
        ct->pfa_ip_ct_status |= IPS_PFA_FORWARD;
#else
        ct->status |= IPS_PFA_FORWARD;
#endif
    } else {
        g_pfa.stat.ip_hook_ct_null++;
    }

    return NF_ACCEPT;
}

int bsp_pfa_enable_macfw_to_ip(unsigned int vir_portno, unsigned int enable)
{
    struct pfa *pfa = &g_pfa;
    struct pfa_port_ctrl *port_ctrl = NULL;
    unsigned int portno = PFA_GET_PHY_PORT(vir_portno);

    if (portno >= PFA_PORT_NUM) {
        return -1;
    }

    port_ctrl = &pfa->ports[portno].ctrl;
    port_ctrl->port_flags.mac_to_ip_enable = (enable == 0) ? 0 : 1;

    pfa->hal->enable_macfw_to_ip(pfa, portno, port_ctrl->port_flags.mac_to_ip_enable);

    if (pfa->direct_fw.direct_fw_timer_add == 0) {
        add_timer(&pfa->direct_fw.direct_fw_timer);
        pfa->direct_fw.direct_fw_timer_add = 1;
    }

    return 0;
}

unsigned int pfa_mac_to_ip_hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state)
{
    struct pfa_direct_fw_entry_ctx ctx;
    struct ethhdr *eth_hdr;
    struct pfa *pfa = &g_pfa;
    struct pfa_port_ctrl *in_port_ctrl = NULL;
    struct pfa_port_ctrl *out_port_ctrl = NULL;
    unsigned int in_port, out_port;
    struct pfa_build_fw_entry_info info = {0};

    // filter skb
    if (state->in == NULL || state->out == NULL) {
        PFA_ERR("stat dev is null\n");
        return NF_ACCEPT;
    }
    in_port = PFA_GET_PHY_PORT(state->in->pfa_portno);
    out_port = PFA_GET_PHY_PORT(state->out->pfa_portno);
    in_port_ctrl = &pfa->ports[in_port].ctrl;
    out_port_ctrl = &pfa->ports[out_port].ctrl;
    if (!(in_port_ctrl->port_flags.mac_to_ip_enable || out_port_ctrl->port_flags.mac_to_ip_enable) ||
        (skb->update_only == 1)) {
        return NF_ACCEPT;
    }

    if (pfa->ops.pfa_ip_fw_add_filter && pfa->ops.pfa_ip_fw_add_filter(skb)) {
        pfa->stat.ipfw_mac_to_ip_filter++;
        return NF_ACCEPT;
    }

    clear_bit(PFA_EVENT_MAC_TO_IP_STOPED_BIT, (void *)&pfa->event);
    if (test_bit(PFA_EVENT_RESETTING_BIT, (void *)&pfa->event)) {
        set_bit(PFA_EVENT_MAC_TO_IP_STOPED_BIT, (void *)&pfa->event);
        wake_up(&pfa->wqueue);
        return NOTIFY_DONE;
    }

    ctx.net_id = 0;
    ctx.maped = 1;
    ctx.skb_cb_info = 0;
    ctx.add_wan_info = 0;
    ctx.l2_hdr_len = ETH_HLEN;

    skb_push(skb, ETH_HLEN);
    eth_hdr = (struct ethhdr *)(uintptr_t)skb->data;
    ether_addr_copy(ctx.dest_hd, eth_hdr->h_dest);
    ether_addr_copy(ctx.src_hd, eth_hdr->h_source);

    info.skb = skb;
    info.ctx = &ctx;
    info.portno = state->out->pfa_portno;
    info.macfw_to_ip = 1;
    info.state = state;
    pfa_build_fw_entry(&info);
    skb_pull(skb, ETH_HLEN);

    set_bit(PFA_EVENT_MAC_TO_IP_STOPED_BIT, (void *)&pfa->event);
    wake_up(&pfa->wqueue);
    return NF_ACCEPT;
}

const struct nf_hook_ops g_pfa_nf_ops[] = {
    {
        .hook =     pfa_ip_hook_func,
        .pf =       NFPROTO_IPV4,
        .hooknum =  NF_INET_FORWARD,
        .priority = NF_IP_PRI_FIRST,
    },
    {
        .hook =     pfa_ip_hook_func,
        .pf =       NFPROTO_IPV6,
        .hooknum =  NF_INET_FORWARD,
        .priority = NF_IP_PRI_FIRST,
    },
};

int pfa_hook_init(void)
{
    int ret = 0;

    ret = nf_register_net_hooks(&init_net, g_pfa_nf_ops, ARRAY_SIZE(g_pfa_nf_ops));
    if (ret) {
        PFA_ERR("registering netfilter hooks fail.\n");
    }
    return ret;
}

void __net_exit pfa_hook_exit(void)
{
    nf_unregister_net_hooks(&init_net, g_pfa_nf_ops, ARRAY_SIZE(g_pfa_nf_ops));
    return;
}

int pfa_switchdev_event(struct notifier_block *nb, unsigned long event, void *ptr)
{
    struct net_device *dev = switchdev_notifier_info_to_dev(ptr);
    struct switchdev_notifier_fdb_info *fdb_info = ptr;
    struct net_bridge_port *p = br_port_get_rcu(dev);
    struct net_bridge *br = NULL;
    struct pfa *pfa = &g_pfa;
    unsigned int portno;

    if (p == NULL) {
        PFA_ERR(" dev correspond port of br is null, please check.\n");
        return NOTIFY_DONE;
    }

    clear_bit(PFA_EVENT_FDB_STOPED_BIT, (void *)&pfa->event);
    if (test_bit(PFA_EVENT_RESETTING_BIT, (void *)&pfa->event)) {
        set_bit(PFA_EVENT_FDB_STOPED_BIT, (void *)&pfa->event);
        wake_up(&pfa->wqueue);
        return NOTIFY_DONE;
    }

    br = p->br;
    portno = fdb_info->info.dev->pfa_portno;
    if (portno == PFA_CCORE_PORT_BEGIN && pfa->macfw_relay_en) {
        portno = PFA_CCORE_PORT_BEGIN + 1;
    }
    switch (event) {
        case SWITCHDEV_FDB_ADD_TO_DEVICE:
            pfa->macfw.macfw_fdb_dev_add++;
            pfa_mac_fw_add((char *)fdb_info->addr,
                is_vlan_dev(fdb_info->info.dev) ? vlan_dev_vlan_id(fdb_info->info.dev) : 0,
                br->dev->pfa_portno, portno, 0, is_vlan_dev(fdb_info->info.dev) ? 1 : 0);
            break;
        case SWITCHDEV_FDB_DEL_TO_DEVICE:
            pfa->macfw.macfw_fdb_dev_del++;
            pfa_mac_fw_del((char *)fdb_info->addr,
                is_vlan_dev(fdb_info->info.dev) ? vlan_dev_vlan_id(fdb_info->info.dev) : 0,
                br->dev->pfa_portno, portno, is_vlan_dev(fdb_info->info.dev) ? 1 : 0);
            break;
        default:
            break;
    }
    set_bit(PFA_EVENT_FDB_STOPED_BIT, (void *)&pfa->event);
    wake_up(&pfa->wqueue);

    return NOTIFY_DONE;
}

struct notifier_block g_pfa_switchdev_notifier = {
    .notifier_call = pfa_switchdev_event,
};

EXPORT_SYMBOL(bsp_pfa_enable_macfw_to_ip);
EXPORT_SYMBOL(pfa_mac_to_ip_hook_func);
#endif


#ifdef CONFIG_PFA_DIRECT_FW
void pfa_hook_register(void)
{
    int ret;

    g_pfa_hook.ipfw_entry_add = pfa_ip_fw_add;
    g_pfa_hook.ipfw_entry_del = pfa_ip_fw_del;
    g_pfa_hook.is_updateonly = pfa_skb_is_updateonly;

#ifdef CONFIG_DPA_API
    dpa_pfa_api_register(&g_pfa_hook);
#endif
    ret = pfa_hook_init();
    if (ret) {
        PFA_ERR("pfa hook init fail. \n");
    }
#ifndef CONFIG_PFA_PHONE_SOC
    ret = pfa_macfw_hook_init();
    if (ret) {
        PFA_ERR("pfa macfw hook init fail.\n");
    }
#endif
    return;
}

void pfa_hook_unregister(void)
{
    g_pfa_hook.ipfw_entry_add = NULL;
    g_pfa_hook.ipfw_entry_del = NULL;
    g_pfa_hook.is_updateonly = NULL;

    pfa_hook_exit();
    pfa_macfw_hook_exit();
}
#endif
MODULE_ALIAS("network hardware accelerator driver");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("smart packet engine(pfa) driver");
