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

#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <linux/route.h>
#include <linux/notifier.h>
#include <net/if_inet6.h>
#include <net/addrconf.h>
#include <net/netevent.h>
#include <linux/netdevice.h>
#include <linux/inetdevice.h>
#include <linux/route.h>
#include <linux/notifier.h>
#include <linux/slab.h>
#include <securec.h>
#include <dpa_reset.h>
#include "nic_sync.h"

struct nic_sync_ctx g_nic_sync_ctx = {0};

int nic_sync_check_netdev(struct net_device *dev)
{
    int i;
    struct nic_sync_ctx *ctx = &g_nic_sync_ctx;

    for (i = 0; i < NIC_SYNC_NET_NUM_MAX; i++) {
        if (ctx->net_map[i].dev == dev && ctx->net_map[i].valid) {
            return i;
        }
    }
    return i;
}

int nic_sync_send_msg(struct nic_sync_ctx *ctx, struct dmi_msg *msg, unsigned int msg_len)
{
    int ret;

    msg->plane = DMI_SERVICE_TYPE_CTRL;
    msg->type = DMI_SERVICE_TYPE_REQUEST;
    msg->dmi_id = DMI_SERVICE_NIC_SYNC;
    msg->data.len = msg_len - sizeof(struct dmi_msg);

    ret = bsp_dmi_client_request(msg, msg_len);
    if (ret) {
        NIC_SYNC_ERR("nic sync client send fail:%d\n", ret); // 消息同步网卡失败处理策略，
        ctx->stat.msg_send_fail++;
        return ret;
    }

    ctx->stat.msg_send_success++;

    return 0;
}

int nic_sync_get_event(int tcp_ip_event)
{
    int event = NIC_SYNC_EVENT_MAX;

    switch (tcp_ip_event) {
        case NETDEV_UP:
            event = NIC_SYNC_EVENT_UP;
            break;
        case NETDEV_DOWN:
            event = NIC_SYNC_EVENT_DOWN;
            break;
        case NETDEV_CHANGE:
            event = NIC_SYNC_EVENT_CHANGE;
            break;
        default:
            event = NIC_SYNC_EVENT_MAX;
    }
    return event;
}

static void nic_sync_get_kernel_ip(struct nic_sync_net_dev_para *buf, struct net_device *netdev)
{
    struct ifreq ifr;
    struct sockaddr_in *sin = (struct sockaddr_in *)&ifr.ifr_addr;
    struct in_ifaddr __rcu **ifap = NULL;
    struct in_ifaddr *ifa = NULL;
    struct in_device *in_dev = __in_dev_get_rtnl(netdev);

    memset_s(sin, sizeof(*sin), 0, sizeof(*sin));
    int ret = strcpy_s(ifr.ifr_name, IFNAMSIZ, netdev->name);
    if (ret != EOK) {
        NIC_SYNC_ERR("nic sync strcpy_s name ret:%d\n", ret);
        return;
    }

    if (in_dev) {
        for (ifap = &in_dev->ifa_list;
            (ifa = rtnl_dereference(*ifap)) != NULL;
            ifap = &ifa->ifa_next) {
            if ((strcmp(ifr.ifr_name, ifa->ifa_label) == 0) &&
                sin->sin_addr.s_addr == ifa->ifa_local) {
                break; /* found */
            }
        }

        if (!ifa) {
            for (ifap = &in_dev->ifa_list;
                (ifa = rtnl_dereference(*ifap)) != NULL;
                ifap = &ifa->ifa_next)
                if (strcmp(ifr.ifr_name, ifa->ifa_label) == 0) {
                    break;
                }
        }
    }
    if (ifa == NULL) {
        NIC_SYNC_ERR("no local IP info");
        return;
    }
    buf->ipaddr_local = ifa->ifa_local;
    buf->iplocal_mask = ifa->ifa_mask;
    buf->iplocal_valid = 1;
}

static void nic_sync_get_kernel_ipv6_addr(struct nic_sync_net_dev_para *buf, struct net_device *netdev)
{
    struct inet6_dev *idev = __in6_dev_get(netdev);

    if (idev == NULL) {
        return;
    }

    struct inet6_ifaddr *ifa = NULL;
    struct nic_sync_ip6_addr addr = {{0}};
    list_for_each_entry(ifa, &idev->addr_list, if_list) {
        if (ifa->scope == IPV6_ADDR_ANY) {
            if (unlikely(memcpy_s(&buf->ip6addr, sizeof(addr.addr), ifa->addr.s6_addr32, sizeof(ifa->addr.s6_addr32)))) {
                g_nic_sync_ctx.stat.mcpy_fail++;
            }
            NIC_SYNC_ERR("flag=%u, scope=%hu, prefix_len=%u", ifa->flags, ifa->scope, ifa->prefix_len);
            buf->ip6_len = ifa->prefix_len;
            buf->ip6_valid = 1;
        } else if (ifa->scope == IPV6_ADDR_LINKLOCAL) {
            if (unlikely(memcpy_s(&buf->ip6addr_local, sizeof(addr.addr), ifa->addr.s6_addr32, sizeof(ifa->addr.s6_addr32)))) {
                g_nic_sync_ctx.stat.mcpy_fail++;
            }
            NIC_SYNC_ERR("flag=%u, scope=%hu, prefix_len=%u", ifa->flags, ifa->scope, ifa->prefix_len);
            buf->ip6local_len = ifa->prefix_len;
            buf->ip6_local_valid = 1;
        }
    }
    if (buf->ip6_valid == 0 || buf->ip6_local_valid == 0) {
        NIC_SYNC_ERR("no IPv6 addr is found");
    }
}

void nic_sync_build_ipaddr(struct nic_sync_net_dev_para *buf, struct net_device *dev)
{
    nic_sync_get_kernel_ip(buf, dev);
    nic_sync_get_kernel_ipv6_addr(buf, dev);
}

int nic_sync_get_netdev_map_idx(struct nic_sync_ctx *ctx, struct net_device *dev, enum nic_sync_event_type event,
    enum dpa_sms_nic nic)
{
    int map_idx;

    if (event == NIC_SYNC_EVENT_ADD) {
        ctx->stat.dev_add++;
        map_idx = nic_sync_check_netdev(dev);
        if (map_idx < NIC_SYNC_NET_NUM_MAX) {
            NIC_SYNC_ERR("dev already add\n");
            return -1;
        }
        map_idx = find_first_zero_bit(&ctx->netmap, NIC_SYNC_NET_NUM_MAX);
        if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
            NIC_SYNC_ERR("nic sync add netdev fail, map full map_idx:%d, name:%s\n", map_idx, dev->name);
            return -1;
        }
        set_bit(map_idx, &ctx->netmap);
        ctx->net_map[map_idx].dev = dev;
        ctx->net_map[map_idx].valid = 1;
        ctx->net_map[map_idx].src_nic = nic;
        if (nic == DPA_SMS_NIC_WLAN) {
            if (dpa_sms_get_wlan_port() > 0) {
                dev->pfa_portno = dpa_sms_get_wlan_port();
            }
        }
    } else if (event == NIC_SYNC_EVENT_DEL) {
        ctx->stat.dev_del++;
        map_idx = nic_sync_check_netdev(dev);
        if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
            NIC_SYNC_ERR("del dev, no dev, name:%s\n", dev->name);
            return -1;
        }
        ctx->net_map[map_idx].valid = 0;
        clear_bit(map_idx, &ctx->netmap);
    } else {
        ctx->stat.dev_update++;
        map_idx = nic_sync_check_netdev(dev);
        if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
            NIC_SYNC_ERR("update dev, no dev, name:%s\n", dev->name);
            return -1;
        }
    }

    return map_idx;
}

void sms_sync_netdev_build_para(enum dpa_sms_nic nic, struct nic_sync_net_dev_para *buf, struct net_device *dev,
    int map_idx, enum nic_sync_event_type event, char priv_info[64])
{
    struct nic_sync_ctx *ctx = &g_nic_sync_ctx;

    memset_s(buf, sizeof(struct nic_sync_net_dev_para), 0, sizeof(struct nic_sync_net_dev_para));
    buf->net_map_idx = map_idx;
    buf->ifindex = dev->ifindex;
    buf->dev_phy_id = dev->ifindex;
    buf->event = event;
    buf->src_nic = nic;
    buf->flags = dev->flags;
    buf->mtu = dev->mtu;
    if (unlikely(memcpy_s(buf->name, sizeof(buf->name), dev->name, sizeof(dev->name)))) {
        ctx->stat.mcpy_fail++;
    }
    ether_addr_copy(buf->mac.addr, dev->dev_addr);
    if (priv_info != NULL) {
        if (unlikely(memcpy_s(buf->priv_info, sizeof(buf->priv_info), priv_info, NIC_SYNC_NET_PRIV_INFO_SIZE))) {
            ctx->stat.mcpy_fail++;
        }
        if (unlikely(memcpy_s(ctx->net_map[map_idx].priv_info, sizeof(ctx->net_map[map_idx].priv_info), priv_info,
            NIC_SYNC_NET_PRIV_INFO_SIZE))) {
            ctx->stat.mcpy_fail++;
        }
    }
}

int sms_sync_netdev(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event,
    int restore_dev_flag, int idx)
{
    struct nic_sync_ctx *ctx = &g_nic_sync_ctx;
    int ret, map_idx;
    struct nic_sync_net_dev_para *buf;
    unsigned int len = sizeof(struct dmi_msg) + sizeof(struct nic_sync_net_dev_para);
    struct dmi_msg *msg = NULL;
    unsigned long flags = 0;
    struct nic_sync_net_dev_para net_dev_para;

    spin_lock_irqsave(&g_nic_sync_ctx.lock, flags);
    if (restore_dev_flag) {
        if (ctx->net_map[idx].dev == NULL || ctx->net_map[idx].valid == 0) {
            spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
            return 0;
        }
        map_idx = idx;
    } else {
        map_idx = nic_sync_get_netdev_map_idx(ctx, dev, event, nic);
        if (map_idx < 0) {
            spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
            return -1;
        }
    }
    sms_sync_netdev_build_para(nic, &net_dev_para, dev, map_idx, event, priv_info);
    spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);

    NIC_SYNC_ERR("netdev event %d, dev name:%s, flags 0x%x\n", event, dev->name, dev->flags);
    if (event == NIC_SYNC_EVENT_ADD) {
        nic_sync_build_ipaddr(&net_dev_para, dev);
    }

    spin_lock_irqsave(&g_nic_sync_ctx.lock, flags);
    if (ctx->dpa_stat == NIC_SYNC_RESET) {
        spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
        return 0;
    }
    msg = bsp_dmi_msg_alloc(DMI_SERVICE_NIC_SYNC, len);
    if (unlikely(msg == NULL)) {
        spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
        dpa_pr_err("msg malloc fail\n");
        return -1;
    }

    buf = (struct nic_sync_net_dev_para *)msg->data.buf;
    *buf = net_dev_para;

    ret = nic_sync_send_msg(ctx, msg, len);
    if (ret) {
        bsp_dmi_msg_free(&msg->data);
        spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
        return ret;
    }
    spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);

    return 0;
}

int dpa_sms_sync_netdev(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event)
{
    int ret;

    if (unlikely(dev == NULL)) {
        NIC_SYNC_ERR("sms sync dev null\n");
        return -1;
    }

    if (nic == DPA_SMS_NIC_WLAN) {
        g_nic_sync_ctx.wlan_dpa_en = 1;
    }

    ret = sms_sync_netdev(nic, dev, priv_info, event, 0, 0);

    return ret;
}

bool dpa_nic_invalid_check_by_id(int ifindex)
{
    int map_idx;

    struct net_device *dev = dev_get_by_index(&init_net, ifindex);
    if (unlikely(dev == NULL)) {
        return false;
    }
    map_idx = nic_sync_check_netdev(dev);
    dev_put(dev);
    if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
        return false;
    }

    return true;
}
EXPORT_SYMBOL(dpa_nic_invalid_check_by_id);

bool dpa_nic_invalid_check_by_dev(struct net_device *dev)
{
    int map_idx;

    if (unlikely(dev == NULL)) {
        return false;
    }
    map_idx = nic_sync_check_netdev(dev);
    if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
        return false;
    }

    return true;
}
EXPORT_SYMBOL(dpa_nic_invalid_check_by_dev);

int bsp_dpa_sms_netdev_get_vir_id(struct net_device *dev)
{
    int map_idx;

    if (unlikely(dev == NULL)) {
        return -1;
    }
    map_idx = nic_sync_check_netdev(dev);
    if (map_idx >= NIC_SYNC_NET_NUM_MAX) {
        g_nic_sync_ctx.stat.no_dev++;
        return -1;
    }

    return map_idx;
}
EXPORT_SYMBOL(bsp_dpa_sms_netdev_get_vir_id);

void nic_sync_debug_show(void)
{
    struct nic_sync_ctx *ctx = &g_nic_sync_ctx;

    NIC_SYNC_ERR("msg_send_success:%d\n", ctx->stat.msg_send_success);
    NIC_SYNC_ERR("msg_send_fail:%d\n", ctx->stat.msg_send_fail);
    NIC_SYNC_ERR("dev_add:%d\n", ctx->stat.dev_add);
    NIC_SYNC_ERR("dev_del:%d\n", ctx->stat.dev_del);
    NIC_SYNC_ERR("dev_update:%d\n", ctx->stat.dev_update);
    NIC_SYNC_ERR("vir_id_err:%d\n", ctx->stat.vir_id_err);
    NIC_SYNC_ERR("vir_id_no_dev:%d\n", ctx->stat.vir_id_no_dev);
    NIC_SYNC_ERR("phy_id_no_dev:%d\n", ctx->stat.phy_id_no_dev);
    NIC_SYNC_ERR("no_dev:%d\n", ctx->stat.no_dev);
}

static int nic_sync_netdev_event(struct notifier_block *this, unsigned long event, void *ptr)
{
    struct net_device *dev = netdev_notifier_info_to_dev(ptr);
    int ret;

    if (event == NETDEV_UP || event == NETDEV_DOWN || event == NETDEV_CHANGE) {
        ret = sms_sync_netdev(0, dev, NULL, nic_sync_get_event(event), 0, 0);
        if (ret) {
            return NOTIFY_DONE;
        }
    }

    return NOTIFY_DONE;
}

static struct notifier_block g_nic_sync_notifier = {
    .notifier_call = nic_sync_netdev_event,
};

void sms_sync_clear_netdev(struct nic_sync_ctx *ctx, int idx)
{
    unsigned long flags = 0;

    spin_lock_irqsave(&g_nic_sync_ctx.lock, flags);
    ctx->net_map[idx].valid = 0;
    clear_bit(idx, &ctx->netmap);
    spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
}

int sms_nic_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    int i;
    int ret;
    struct nic_sync_ctx *ctx = &g_nic_sync_ctx;
    unsigned long flags = 0;

    NIC_SYNC_ERR("sms_nic_dpa_reset_cb %d\n", enparam);

    if (enparam == DPA_RESET_BEFORE) {
        spin_lock_irqsave(&g_nic_sync_ctx.lock, flags);
        ctx->dpa_stat = NIC_SYNC_RESET;
        spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
    } else if (enparam == DPA_RESET_AFTER) {
        spin_lock_irqsave(&g_nic_sync_ctx.lock, flags);
        ctx->dpa_stat = 0;
        spin_unlock_irqrestore(&g_nic_sync_ctx.lock, flags);
        for (i = 0; i < NIC_SYNC_NET_NUM_MAX; i++) {
            if (ctx->net_map[i].src_nic == DPA_SMS_NIC_WLAN) {
                sms_sync_clear_netdev(ctx, i);
            } else {
                ret = sms_sync_netdev(ctx->net_map[i].src_nic, ctx->net_map[i].dev, ctx->net_map[i].priv_info,
                    NIC_SYNC_EVENT_ADD, 1, i);
                if (ret) {
                    NIC_SYNC_ERR("dpa reset add dev err, src_nic:%d, net_map_idx:%d, name:%s\n", ctx->net_map[i].src_nic, i,
                    ctx->net_map[i].dev->name);
                    return ret;
                }
            }
        }
    }
    return 0;
}

int nic_sync_init(void)
{
    int ret;

    ret = register_netdevice_notifier(&g_nic_sync_notifier);
    if (ret) {
        NIC_SYNC_ERR("register_inetaddr_notifier err ret:%d\n", ret);
    }

    spin_lock_init(&g_nic_sync_ctx.lock);
    ret = bsp_dpa_reset_register_cb("sms_nic", sms_nic_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_SMS_NIC);
    if (ret != 0) {
        NIC_SYNC_ERR("nic sync dpa reset call back func failed\n");
    }

    return ret;
}

int bsp_dpa_sms_netdev_init(void)
{
    return nic_sync_init();
}

EXPORT_SYMBOL(dpa_sms_sync_netdev);
EXPORT_SYMBOL(nic_sync_debug_show);