/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#ifndef __DPA_SMS_H
#define __DPA_SMS_H

#include <net/netfilter/nf_conntrack_tuple.h>

#ifdef __cplusplus /* __cplusplus */
extern "C"
{
#endif /* __cplusplus */

enum nic_sync_event_type {
    NIC_SYNC_EVENT_ADD = 0,
    NIC_SYNC_EVENT_DEL,
    NIC_SYNC_EVENT_UP,
    NIC_SYNC_EVENT_DOWN,
    NIC_SYNC_EVENT_CHANGE_NAME,
    NIC_SYNC_EVENT_UPDATE_INFO,
    NIC_SYNC_EVENT_CHANGE,
    NIC_SYNC_EVENT_MAX,
};

enum dpa_sms_nic {
    DPA_SMS_NIC_WAN,
    DPA_SMS_NIC_WLAN,
    DPA_SMS_NIC_END
};

struct dpa_sms_rx_callback_s {
    void (*rx)(struct sk_buff* skb, void* usr_data);
    void (*rx_complete)(void);
};

struct dpa_sms_filter_usr_info {
    unsigned short out_port;
    unsigned int usr_para;
    struct net_device *dev;
};

struct dpa_sms_filter_pkt_info {
    unsigned long long dra_addr;
    unsigned int pkt_len;
    unsigned int stream_id;
    unsigned int update_only_flag;
    unsigned int userfield0;
    unsigned int userfield1;
    unsigned int userfield2;
};

struct dpa_sms_filter_callback_s {
    void* (*add_flow)(struct nf_conntrack_tuple* tuple, struct dpa_sms_filter_usr_info* usr_data);
    void (*del_flow)(void* handler);
    int (*add_entry)(struct sk_buff *skb, unsigned int portno);
};

#define DPA_SMS_TX_OFFLOAD_FLAG BIT(0)
#define DPA_SMS_TX_TCPIP_FREE_FLAG BIT(1)
#define DPA_SMS_TX_RET_OK 0
#define DPA_SMS_TX_RET_BLOCK 1
#define DPA_SMS_TX_RET_NOMEM 2
#define DPA_SMS_TX_RET_MAPFAIL 3
#define DPA_SMS_TX_RET_IOERR 4
#define DPA_SMS_TX_RET_BADPARA 5
struct dpa_sms_ops {
    int (*dpa_sms_sync_netdev)(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event);
    int (*dpa_sms_filter_add_entry)(enum dpa_sms_nic nic, struct sk_buff *skb);
    int (*dpa_sms_tx)(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
    int (*dpa_sms_rx_callback_register)(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb);
    unsigned long long (*dpa_sms_get_netdev_feature)(void);
    int (*dpa_sms_tx_nodrop)(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
    int (*dpa_sms_tx_unblock_cb_register)(void (*)(void));
};

int dpa_sms_api_register(struct dpa_sms_ops *sms_ops);
int dpa_sms_sync_netdev_ops(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event);
int dpa_sms_filter_add_entry_ops(enum dpa_sms_nic nic, struct sk_buff *skb);
int dpa_sms_tx_ops(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
int dpa_sms_rx_callback_register_ops(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb);
unsigned long long dpa_sms_get_netdev_feature_ops(void);
int dpa_sms_tx_nodrop_ops(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
int dpa_sms_tx_unblock_cb_register_ops(void (*cb)(void));

#ifdef CONFIG_DPA_NETDEV
int dpa_sms_sync_netdev(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event);
/**
 * @brief 获取网卡虚拟id
 * @par 描述:
 * @attention
 * @param[in]  dev;
 * @param[in]
 * @retval >=0,表示成功获取虚拟网卡id。
 * @retval < 0,表示函数执行失败，没有找到对应的物理网卡。
 * @see
 */
int bsp_dpa_sms_netdev_get_vir_id(struct net_device *dev);

/**
 * @brief 根据网卡ifindex，判断该网卡是否在卸载到dpa的网卡列表里
 * @par 描述:
 * @attention
 * @param[in]  网卡id，ifindex;
 * @param[in]
 * @retval true,表示网卡卸载。
 * @retval false 表项网卡不在卸载列表。
 * @see
 */
bool dpa_nic_invalid_check_by_id(int ifindex);

/**
 * @brief 根据网卡dev，判断该网卡是否在卸载到dpa的网卡列表里
 * @par 描述:
 * @attention
 * @param[in]  网卡dev;
 * @param[in]
 * @retval true,表示网卡卸载。
 * @retval false 表项网卡不在卸载列表。
 * @see
 */
bool dpa_nic_invalid_check_by_dev(struct net_device *dev);

#else
static inline int dpa_sms_sync_netdev(enum dpa_sms_nic nic, struct net_device *dev, char priv_info[64], enum nic_sync_event_type event)
{
    return 0;
}
static inline int bsp_dpa_sms_netdev_get_vir_id(struct net_device *dev)
{
    return -1;
}

static inline bool dpa_nic_invalid_check_by_id(int ifindex)
{
    return false;
}

static inline bool dpa_nic_invalid_check_by_dev(struct net_device *dev)
{
    return false;
}
#endif

#ifdef CONFIG_DPA_SMS_GSO
int dpa_sms_tx(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
int dpa_sms_tx_nodrop(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en);
int dpa_sms_tx_unblock_cb_register(void (*cb)(void));
unsigned long long dpa_sms_get_netdev_feature(void);
#else
static inline int dpa_sms_tx(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en)
{
    return 0;
}
static inline int dpa_sms_tx_nodrop(struct sk_buff *skb, enum dpa_sms_nic nic, unsigned int offload_en)
{
    return 0;
}
static inline int dpa_sms_tx_unblock_cb_register(void (*cb)(void))
{
    return 0;
}
static inline unsigned long long dpa_sms_get_netdev_feature(void)
{
    return 0;
}
#endif

#ifdef CONFIG_DPA_SMS_GRO
int dpa_sms_rx_callback_register(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb);
#else
static inline int dpa_sms_rx_callback_register(enum dpa_sms_nic nic, struct dpa_sms_rx_callback_s* cb)
{
    return 0;
}
#endif

#ifdef CONFIG_DPA_SMS_FILTER
int dpa_sms_filter_callback_register(struct dpa_sms_filter_callback_s* cb);
int dpa_sms_filter_add_entry(enum dpa_sms_nic nic, struct sk_buff *skb);
int dpa_sms_filter_config_port(void);
unsigned int dpa_sms_filter_cpu_port_offload_en(void);
int dpa_sms_get_wlan_port(void);
void dpa_sms_wlan_pfa_netif_rx(struct sk_buff *skb, void *priv);
void dpa_sms_wlan_pfa_rx(void *info, void *priv);
void dpa_sms_wlan_pfa_complete_rd(void *priv);
void dpa_sms_wlan_set_usr_info(unsigned int offset, unsigned int len);
#else
static inline int dpa_sms_filter_callback_register(struct dpa_sms_filter_callback_s* cb)
{
    return 0;
}
static inline int dpa_sms_filter_add_entry(enum dpa_sms_nic nic, struct sk_buff *skb)
{
    return 0;
}
static inline int dpa_sms_filter_config_port(void)
{
    return 0;
}
static inline unsigned int dpa_sms_filter_cpu_port_offload_en(void)
{
    return 0;
}
static inline int dpa_sms_get_wlan_port(void)
{
    return -1;
}
static inline void dpa_sms_wlan_pfa_netif_rx(struct sk_buff *info, void *priv)
{
}
static inline void dpa_sms_wlan_pfa_rx(void *info, void *priv)
{
}
static inline void dpa_sms_wlan_pfa_complete_rd(void *priv)
{
}
static inline void dpa_sms_wlan_set_usr_info(unsigned int offset, unsigned int len)
{
}
#endif

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */

#endif /* __DPA_SMS_H */
