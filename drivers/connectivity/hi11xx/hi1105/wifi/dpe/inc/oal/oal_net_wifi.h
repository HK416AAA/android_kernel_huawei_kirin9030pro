/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef OAL_NET_WIFI_H
#define OAL_NET_WIFI_H

/* 其他头文件包含 */

#include "oal_types.h"
#include "sbuf_api.h"
#include "dev_api.h"
#include "oal_schedule_wifi.h"
/* 2.13 ETHER宏定义 */
#define ETHER_ADDR_LEN 6 /* length of an Ethernet address */
#define ETHER_TYPE_LEN 2 /* length of the Ethernet type field */
#define ETHER_CRC_LEN  4 /* length of the Ethernet CRC */
#define ETHER_HDR_LEN  14
#define ETHER_MAX_LEN  1518
#define ETHER_MTU      (ETHER_MAX_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)

enum nl80211_key_type {
    NL80211_KEYTYPE_GROUP,
    NL80211_KEYTYPE_PAIRWISE,
    NL80211_KEYTYPE_PEERKEY,
    NUM_NL80211_KEYTYPES
};
typedef enum nl80211_key_type oal_nl80211_key_type;

#define OAL_MAC_ADDR_LEN            6
#define OAL_WPA_KEY_LEN             32
#define OAL_WPA_SEQ_LEN             16

/*
 * Structure of the IP frame
 */
struct oal_ip_header {
#if (_PRE_LITTLE_CPU_ENDIAN == _PRE_CPU_ENDIAN) /* LITTLE_ENDIAN */
    uint8_t us_ihl : 4,
              uc_version_ihl : 4;
#else
    uint8_t uc_version_ihl : 4,
              us_ihl : 4;
#endif
    /* liuming modifed proxyst end */
    uint8_t uc_tos;
    uint16_t us_tot_len;
    uint16_t us_id;
    uint16_t us_frag_off;
    uint8_t uc_ttl;
    uint8_t uc_protocol;
    uint16_t us_check;
    uint32_t saddr;
    uint32_t daddr;
    /* The options start here. */
} ;
typedef struct oal_ip_header oal_ip_header_stru;

#define ETHER_ADDR_LEN            6 /* length of an Ethernet address */
#define ETH_SENDER_IP_ADDR_LEN 4 /* length of an Ethernet send ip address */
#define ETH_TARGET_IP_ADDR_LEN 4 /* length of an Ethernet target ip address */
typedef struct {
    uint16_t us_ar_hrd; /* format of hardware address */
    uint16_t us_ar_pro; /* format of protocol address */

    uint8_t uc_ar_hln; /* length of hardware address */
    uint8_t uc_ar_pln; /* length of protocol address */
    uint16_t us_ar_op; /* ARP opcode (command) */

    uint8_t auc_ar_sha[ETHER_ADDR_LEN];         /* sender hardware address */
    uint8_t auc_ar_sip[ETH_SENDER_IP_ADDR_LEN]; /* sender IP address */
    uint8_t auc_ar_tha[ETHER_ADDR_LEN];         /* target hardware address */
    uint8_t auc_ar_tip[ETH_TARGET_IP_ADDR_LEN]; /* target IP address */
} oal_eth_arphdr_stru;

struct ipv6hdr {
    uint8_t  nexthdr;
    uint16_t payload_len;
};
typedef struct ipv6hdr oal_ipv6hdr_stru; // 打桩

typedef struct comm_dev oal_net_device_stru;

OAL_STATIC OAL_INLINE void *oal_comm_dev_priv(oal_net_device_stru *dev)
{
    return dev_get_priv(dev);
}
OAL_STATIC OAL_INLINE char *oal_get_netdev_ifname(oal_net_device_stru *dev)
{
    return dev_get_if_name(dev);
}

OAL_STATIC OAL_INLINE void oal_set_netdev_flags(oal_net_device_stru *dev, uint32_t net_dev_flags)
{
    dev_set_flags(dev, net_dev_flags);
}
OAL_STATIC OAL_INLINE void oal_set_netdev_type(oal_net_device_stru *dev, uint16_t type)
{
    dev_set_type(dev, type);
}

OAL_STATIC OAL_INLINE void oal_set_netdev_tx_handler(oal_net_device_stru *dev, tx_handler handler)
{
    dev_set_tx_handler(dev, handler);
}
OAL_STATIC OAL_INLINE void oal_set_netdev_features(oal_net_device_stru *dev, uint64_t features)
{
    dev_set_features(dev, features);
}
OAL_STATIC OAL_INLINE void oal_set_netdev_hwaddr(oal_net_device_stru *dev, uint8_t *addr)
{
    dev_set_hwaddr(dev, addr);
}
OAL_STATIC OAL_INLINE void oal_set_netdev_hwaddr_len(oal_net_device_stru *dev, uint8_t hwaddr_len)
{
    dev_set_hwaddr_len(dev, hwaddr_len);
}

// 入参netbuf->ifindex，返回  &net_if->comm
OAL_STATIC OAL_INLINE oal_net_device_stru *oal_get_netif_comm_dev(signed int ifindex)
{
    return get_dev_by_ifindex(ifindex);
}

#define ether_is_multicast(_a) ((uint8_t)(*(_a))&0x01)

#define oal_swap_byteorder_16(_val) ((((_val) & 0x00FF) << 8) + (((_val) & 0xFF00) >> 8))
#define oal_swap_byteorder_32(_val)            \
    (((uint32_t)((_val) & 0x000000FF) << 24) + \
        (((_val) & 0x0000FF00) << 8) +           \
        (((_val) & 0x00FF0000) >> 8) +           \
        ((uint32_t)((_val) & 0xFF000000) >> 24))
#define oal_host2net_short(_x)  oal_swap_byteorder_16(_x)
#define oal_net2host_short(_x)  oal_swap_byteorder_16(_x)
#define oal_host2net_long(_x)   oal_swap_byteorder_32(_x)
#define oal_net2host_long(_x)   oal_swap_byteorder_32(_x)

typedef struct {
    uint8_t op;                                     /* packet opcode type */
    uint8_t htype;                                  /* hardware addr type */
    uint8_t hlen;                                   /* hardware addr length */
    uint8_t hops;                                   /* gateway hops */
    uint32_t xid;                                   /* transaction ID */
    uint16_t secs;                                  /* seconds since boot began */
    uint16_t flags;                                 /* flags */
    uint32_t ciaddr;                                /* client IP address */
    uint32_t yiaddr;                                /* 'your' IP address */
    uint32_t siaddr;                                /* server IP address */
    uint32_t giaddr;                                /* gateway IP address */
    uint8_t chaddr[1];       /* client hardware address */
    uint8_t sname[1];        /* server host name */
    uint8_t file[1];      /* boot file name */
    uint8_t options[1]; /* variable-length options field */
} oal_dhcp_packet_stru;
typedef struct {
    uint16_t source;
    uint16_t dest;
    uint16_t len;
    uint16_t check;
} oal_udp_header_stru;

struct icmp6hdr {
    uint8_t icmp6_type;
};
typedef struct icmp6hdr oal_icmp6hdr_stru; // 打桩

#define IPPROTO_ICMPV6  58
#define OAL_IPPROTO_ICMPV6 IPPROTO_ICMPV6 /* ICMPv6 */

/* ether type */
#define ETHER_TYPE_PAE      0x888e /* EAPOL PAE/802.1x */
#define ETHER_TYPE_IP       0x0800 /* IP protocol */
#define ETHER_TYPE_AARP     0x80f3 /* Appletalk AARP protocol */
#define ETHER_TYPE_IPX      0x8137 /* IPX over DIX protocol */
#define ETHER_TYPE_ARP      0x0806 /* ARP protocol */
#define ETHER_TYPE_IPV6     0x86dd /* IPv6 */
#define ETHER_TYPE_TDLS     0x890d /* TDLS */
#define ETHER_TYPE_VLAN     0x8100 /* VLAN TAG protocol */
#define ETHER_TYPE_WAI      0x88b4 /* WAI/WAPI */
#define ETHER_LLTD_TYPE     0x88D9 /* LLTD */
#define ETHER_ONE_X_TYPE    0x888E /* 802.1x Authentication */
#define ETHER_TUNNEL_TYPE   0x88bd /* 自定义tunnel协议 */
#define ETHER_TYPE_PPP_DISC 0x8863 /* PPPoE discovery messages */
#define ETHER_TYPE_PPP_SES  0x8864 /* PPPoE session messages */
#define ETHER_TYPE_HIGAME_DC  0x0888 /* HIGAME DC */

#define MAX_ML_LINK_NUM 2

/* wiphy  */
#define IEEE80211_HT_MCS_MASK_LEN 10

#define WLAN_DATA_VIP_TID WLAN_TIDNO_BCAST

/* ICMP codes for neighbour discovery messages */
#define OAL_NDISC_ROUTER_SOLICITATION     133
#define OAL_NDISC_ROUTER_ADVERTISEMENT    134
#define OAL_NDISC_NEIGHBOUR_SOLICITATION  135
#define OAL_NDISC_NEIGHBOUR_ADVERTISEMENT 136
#define OAL_NDISC_REDIRECT                137

#define OAL_ND_OPT_TARGET_LL_ADDR 2
#define OAL_ND_OPT_SOURCE_LL_ADDR 1
#define OAL_IPV6_ADDR_ANY         0x0000U
#define OAL_IPV6_ADDR_MULTICAST   0x0002U
#define OAL_IPV6_MAC_ADDR_LEN     16

#define OAL_IPV4_ADDR_SIZE   4
#define OAL_IPV6_ADDR_SIZE   16
#define OAL_IP_ADDR_MAX_SIZE OAL_IPV6_ADDR_SIZE

// netbuf链表头初始化，不带锁
OAL_STATIC OAL_INLINE void oal_netbuf_list_head_init_nolock(oal_netbuf_head_stru *netbuf_head)
{
    sbuf_queue_head_init(&netbuf_head->hdr);
}
// 尾添加，不带锁
OAL_STATIC OAL_INLINE void oal_netbuf_list_tail_nolock(oal_netbuf_head_stru *netbuf_head, oal_netbuf_stru *newsk)
{
    oal_netbuf_addlist_tail_nolock(netbuf_head, newsk);
}
// 尾添加，带锁
OAL_STATIC OAL_INLINE void oal_netbuf_add_to_list_tail(oal_netbuf_stru *newsk, oal_netbuf_head_stru *netbuf_head)
{
    // 改成无锁 oal_netbuf_addlist_tail(netbuf_head, newsk);
    oal_netbuf_addlist_tail_nolock(netbuf_head, newsk);
}
// 获取队列头的第一个skb
OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuf_peek(oal_netbuf_head_stru *netbuf_head)
{
    return oal_netbuf_head_next(netbuf_head);
}
// 获取队尾的第一个skb
OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuf_tail(oal_netbuf_head_stru *pst_head)
{
    return oal_netbuf_tail_next(pst_head);
}
// 从队列头出队一个skb，不带锁
OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuf_delist_nolock(oal_netbuf_head_stru *netbuf_head)
{
    return oal_netbuf_delist_head_nolock(netbuf_head);
}
// 从队列头出队一个skb，带锁
OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuf_delist(oal_netbuf_head_stru *netbuf_head)
{
    return oal_netbuf_delist_head_nolock(netbuf_head);
    // 改成无锁 return oal_netbuf_delist_head(netbuf_head);
}

OAL_STATIC OAL_INLINE void oal_net_tx_stop_all_queues(oal_net_device_stru *pst_dev)
{
    // DPA无需适配
}
OAL_STATIC OAL_INLINE void oal_net_tx_wake_all_queues(oal_net_device_stru *pst_dev)
{
    // DPA无需适配
}

OAL_STATIC OAL_INLINE void oal_set_netbuf_next(oal_netbuf_stru *pst_buf, oal_netbuf_stru *next)
{
    if (pst_buf == NULL) {
        return;
    } else {
        set_sbuf_next(pst_buf, next);
    }
}

OAL_STATIC OAL_INLINE void oal_set_netbuf_prev(oal_netbuf_stru *pst_buf, oal_netbuf_stru *prev)
{
    if (pst_buf == NULL) {
        return;
    } else {
        set_sbuf_prev(pst_buf, prev);
    }
}

OAL_STATIC OAL_INLINE oal_netbuf_stru *oal_netbuf_next(oal_netbuf_stru *pst_buf)
{
    return ((pst_buf != NULL) ? get_sbuf_next(pst_buf) : NULL);
}
OAL_STATIC OAL_INLINE signed int oal_get_netbuf_ifindex(oal_netbuf_stru *pst_buf)
{
    return sbuf_get_ifindex(pst_buf);
}
OAL_STATIC OAL_INLINE void oal_set_netbuf_ifindex(oal_netbuf_stru *pst_buf, int32_t ifindex)
{
    sbuf_set_ifindex(pst_buf, ifindex);
}
OAL_STATIC OAL_INLINE void oal_set_netbuf_deliv_flag(oal_netbuf_stru *netbuf, unsigned int value)
{
    sbuf_set_flags_deliv_oth(netbuf, value);
}
OAL_STATIC OAL_INLINE void oal_set_netbuf_cb_len(oal_netbuf_stru *netbuf, unsigned short len)
{
    set_userdata_len(netbuf, len);
}
// 获取payload的头部信息的长度
OAL_STATIC OAL_INLINE uint8_t oal_get_payload_header_len(oal_netbuf_stru *netbuf)
{
    return sbuf_get_headerlen(netbuf);
}

//  设置sbuf中的flags的ip_csum_flag、l4_csum_flag, value配置的值，0：csum未校验；1：csum已校验。
OAL_STATIC OAL_INLINE void oal_set_netbuf_csum_flag(oal_netbuf_stru *netbuf, unsigned int value)
{
    sbuf_set_flags_csum(netbuf, value);
}

OAL_STATIC OAL_INLINE uint32_t oal_netbuf_get_appointed_netbuf(oal_netbuf_stru *pst_netbuf, uint8_t uc_num,
                                                               oal_netbuf_stru **pst_expect_netbuf)
{
    uint8_t uc_buf_num;

    if (oal_unlikely(oal_any_null_ptr2(pst_netbuf, pst_expect_netbuf))) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    *pst_expect_netbuf = NULL;

    for (uc_buf_num = 0; uc_buf_num < uc_num; uc_buf_num++) {
        *pst_expect_netbuf = oal_netbuf_next(pst_netbuf);

        if (*pst_expect_netbuf == NULL) {
            break;
        }

        pst_netbuf = *pst_expect_netbuf;
    }

    return OAL_SUCC;
}

OAL_STATIC OAL_INLINE void oal_netbuf_set_len(oal_netbuf_stru *pst_netbuf, uint32_t ul_len)
{
    if (oal_netbuf_len(pst_netbuf) > ul_len) {
        sbuf_trim(pst_netbuf, ul_len);
    } else {
        sbuf_put(pst_netbuf, (ul_len - oal_netbuf_len(pst_netbuf)));
    }
}

OAL_STATIC OAL_INLINE void oal_skb_set_queue_mapping(oal_netbuf_stru *pst_skb, uint16_t queue_mapping)
{
    // DPA不涉及，无需适配
}

/* 2.10 IP宏定义 */
#define WLAN_DSCP_PRI_SHIFT      2
#define WLAN_IP_PRI_SHIFT        5
#define WLAN_IPV6_PRIORITY_MASK  0x0FF00000
#define WLAN_IPV6_PRIORITY_SHIFT 20

/* 2.12 LLC SNAP宏定义 */
#define LLC_UI                    0x3
#define SNAP_LLC_FRAME_LEN        8
#define SNAP_LLC_LSAP             0xaa
#define SNAP_BRIDGE_SPANNING_TREE 0x42
#define SNAP_IBM_LAN_MANAGEMENT   0xf5
#define SNAP_RFC1042_ORGCODE_0    0x00
#define SNAP_RFC1042_ORGCODE_1    0x00
#define SNAP_RFC1042_ORGCODE_2    0x00
#define SNAP_BTEP_ORGCODE_0       0x00
#define SNAP_BTEP_ORGCODE_1       0x00
#define SNAP_BTEP_ORGCODE_2       0xf8

/* ip头到协议类型字段的偏移 */
#define IP_PROTOCOL_TYPE_OFFSET 9
#define IP_HDR_LEN              20

#define ICMP_PROTOCAL 1
#define TCP_PROTOCAL 6
#define UDP_PROTOCAL 17
#define DHCPV6_CLIENT_PORT 546
#define DHCPV6_SERVER_PORT 547

struct mac_vlan_tag {
    uint16_t us_tpid;           // tag   ID
    uint16_t bit_user_pri : 3,  // 帧的优先级
               bit_cfi : 1,
               bit_vlan_id : 12;  // 可配置的VLAN ID
};
typedef struct mac_vlan_tag mac_vlan_tag_stru;

struct vlan_ethhdr {
    uint16_t h_vlan_encapsulated_proto; // 打桩
};
typedef struct vlan_ethhdr oal_vlan_ethhdr_stru;

typedef struct {
    uint16_t us_sport;
    uint16_t us_dport;
    uint32_t seqnum;
    uint32_t acknum;
    uint8_t uc_offset;
    uint8_t uc_flags;
    uint16_t us_window;
    uint16_t us_check;
    uint16_t us_urgent;
} oal_tcp_header_stru;

typedef enum _wlan_net_queue_type_ {
    WLAN_HI_QUEUE = 0,
    WLAN_NORMAL_QUEUE,

    WLAN_TCP_DATA_QUEUE,
    WLAN_TCP_ACK_QUEUE,

    WLAN_UDP_BK_QUEUE,
    WLAN_UDP_BE_QUEUE,
    WLAN_UDP_VI_QUEUE,
    WLAN_UDP_VO_QUEUE,

    WLAN_NET_QUEUE_BUTT
} wlan_net_queue_type;
#endif /* end of wal_ext_if.h */
