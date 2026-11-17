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
#ifndef __NIC_SYNC_H__
#define __NIC_SYNC_H__

#include <bsp_dmi.h>
#include <bsp_print.h>
#include <bsp_sms.h>

#undef THIS_MODU
#define THIS_MODU mod_nic_sync

#define NIC_SYNC_ERR(fmt, ...) do { \
    dpa_pr_err(fmt, ##__VA_ARGS__); \
} while (0)

#define NIC_SYNC_IPV6_ADDR_LEN 4
struct nic_sync_ip6_addr {
    u32 addr[NIC_SYNC_IPV6_ADDR_LEN];
};
struct nic_sync_eth_addr {
    u8 addr[6];
};

#define NIC_SYNC_NET_PRIV_INFO_SIZE 64
#pragma pack(1)
struct nic_sync_net_dev_para {
    enum dpa_sms_nic src_nic;
    unsigned int net_map_idx;
    unsigned int dev_phy_id;
    unsigned int ifindex;
    unsigned int mtu;
    unsigned int flags;
    enum nic_sync_event_type event;
    char name[IFNAMSIZ];
    struct nic_sync_eth_addr mac;
    unsigned int ipaddr;
    unsigned int ip_mask;
    unsigned int ip_valid;
    unsigned int ipaddr_local;
    unsigned int iplocal_mask;
    unsigned int iplocal_valid;
    struct nic_sync_ip6_addr ip6addr;
    struct nic_sync_ip6_addr ip6addr_local;
    unsigned int ip6_local_valid;
    unsigned int ip6_len;
    unsigned int ip6local_len;
    unsigned int ip6_valid;
    char priv_info[NIC_SYNC_NET_PRIV_INFO_SIZE]; // 64byte, 4byte align
};
#pragma pack()

struct nic_sync_stat {
    unsigned int msg_send_success;
    unsigned int msg_send_fail;
    unsigned int dev_add;
    unsigned int dev_del;
    unsigned int dev_update;
    unsigned int mcpy_fail;
    unsigned int vir_id_err;
    unsigned int vir_id_no_dev;
    unsigned int phy_id_no_dev;
    unsigned int no_dev;
};

struct nic_sync_net_map {
    enum dpa_sms_nic src_nic;
    struct net_device *dev;
    int valid;
    char priv_info[NIC_SYNC_NET_PRIV_INFO_SIZE];
};

#define NIC_SYNC_NET_NUM_MAX 64
#define NIC_SYNC_RESET 11
struct nic_sync_ctx {
    unsigned long netmap;
    struct nic_sync_net_map net_map[NIC_SYNC_NET_NUM_MAX];
    struct nic_sync_stat stat;
    spinlock_t lock;
    unsigned int dpa_stat;
    unsigned int wlan_dpa_en;
};

#endif /* __NIC_SYNC_H__ */