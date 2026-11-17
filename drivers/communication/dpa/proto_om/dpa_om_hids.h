/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef DPA_OM_HIDS_H
#define DPA_OM_HIDS_H

#include "linux/in.h"
#include "linux/in6.h"
#include "linux/udp.h"
#include "linux/tcp.h"
#include "linux/ip.h"
#include "linux/ipv6.h"
#include "linux/icmp.h"
#include "linux/icmpv6.h"

#define IP_VERSION4 4U
#define IP_VERSION6 6U

#define DPA_NET_OM_MSGID_DPA_DL_PKT_INFO        0x9f38051a
#define DPA_NET_OM_MSGID_DPA_UL_PKT_INFO        0x9f38051b
#ifndef DIAG_DRV_HDS_PID
#define DIAG_DRV_HDS_PID (0x8003)
#endif

#define IP4_ADDR_LEN 4
#define IP6_ADDR_LEN 8

struct hds_ctrl_ctx {
    int report_enabled;
    int fuzzy_disabled;
};

struct hds_iphdr {
    unsigned char version;
    unsigned char hdr_len;
    unsigned char tos;
    unsigned short total_len;
    unsigned short id;
    unsigned short offset;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short checksum;
    unsigned char saddr[IP4_ADDR_LEN];
    unsigned char daddr[IP4_ADDR_LEN];
};

struct hds_ip6hdr {
    unsigned char version;
    unsigned char tc;
    unsigned int flow_id;
    unsigned short payload_len;
    unsigned char next_header;
    unsigned char hop_limit;
    unsigned short saddr[IP6_ADDR_LEN];
    unsigned short daddr[IP6_ADDR_LEN];
};

struct hds_tcpinfo {
    unsigned short src_port;
    unsigned short dst_port;
    unsigned int seq;
    unsigned int ack_seq;
    unsigned short data_offset;
    unsigned short window;
    unsigned short checksum;
};

struct hds_udpinfo {
    unsigned short src_port;
    unsigned short dst_port;
    unsigned short length;
    unsigned short checksum;
};

struct hds_icmpinfo {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
};

struct dpa_hids_pkt_info {
    unsigned int version;
    unsigned int link_type;

    unsigned int netif_layer_delay;     /* us */
    unsigned int ip_layer_delay;        /* us */
    unsigned int trans_layer_delay;     /* us */
    unsigned int bridge_delay;          /* us */
    unsigned int sock_delay;            /* us */
    unsigned int total_delay;           /* us */

    unsigned int ip_type;
    union {
        struct hds_iphdr ip4;
        struct hds_ip6hdr ip6;
    } u;
    unsigned int trans_type;
    union {
        struct hds_tcpinfo tcp;
        struct hds_udpinfo udp;
        struct hds_icmpinfo icmp;
    } v;
};

int dpa_host_pkt_report_ctrl(unsigned char *data, unsigned int size);
void dpa_om_hds_report_init(void);

#endif