/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#include <securec.h>
#include <bsp_diag.h>
#include <bsp_dmi.h>
#include <bsp_print.h>
#include "bsp_slice.h"
#include "dpa_om.h"
#include "dpa_om_hids.h"
#include "dpa_om_msg.h"

#define FUZZY_ADDR 0U
#define FUZZY_PORT 0xFFFF

struct hds_ctrl_ctx g_hds_ctrl;
unsigned int g_dpa_freq;

unsigned int timestamp_to_us(unsigned int timestamp)
{
    return timestamp * SLICE_CONVERT_DELTA * SLICE_CONVERT_DELTA / g_dpa_freq;
}

static void fill_in_ipv4_hdr(struct dpa_hids_pkt_info *info, struct iphdr *hdr)
{
    struct hds_iphdr *iphdr = &info->u.ip4;

    iphdr->version = hdr->version;
    iphdr->hdr_len = hdr->ihl;
    iphdr->tos = hdr->tos;
    iphdr->total_len = ntohs(hdr->tot_len);
    iphdr->id = ntohs(hdr->id);
    iphdr->offset = ntohs(hdr->frag_off);
    iphdr->ttl = hdr->ttl;
    iphdr->protocol = hdr->protocol;
    iphdr->checksum = ntohs(hdr->check);

    (void)memcpy_s(&(iphdr->saddr[0]), sizeof(unsigned int), &hdr->saddr, sizeof(unsigned int));
    (void)memcpy_s(&(iphdr->daddr[0]), sizeof(unsigned int), &hdr->daddr, sizeof(unsigned int));

    if (g_hds_ctrl.fuzzy_disabled == 0) {
        iphdr->saddr[0] = FUZZY_ADDR;
        iphdr->saddr[1] = FUZZY_ADDR;
        iphdr->daddr[0] = FUZZY_ADDR;
        iphdr->daddr[1] = FUZZY_ADDR;
    }
}

static void fill_in_ipv6_hdr(struct dpa_hids_pkt_info *info, struct ipv6hdr *hdr)
{
    struct hds_ip6hdr *iphdr = &info->u.ip6;
    iphdr->version = hdr->version;
    iphdr->tc = hdr->priority;
    iphdr->flow_id = ntohl((hdr->flow_lbl[0] << 16 | hdr->flow_lbl[1] << 8 | hdr->flow_lbl[2]) & 0xFFFFFFFF);
    iphdr->payload_len = ntohs(hdr->payload_len);
    iphdr->next_header = hdr->nexthdr;
    iphdr->hop_limit = hdr->hop_limit;

    (void)memcpy_s(&(iphdr->saddr[0]), sizeof(struct in6_addr), &hdr->saddr, sizeof(struct in6_addr));
    (void)memcpy_s(&(iphdr->daddr[0]), sizeof(struct in6_addr), &hdr->daddr, sizeof(struct in6_addr));

    int i;
    for (i = 0; i < IP6_ADDR_LEN; i++) {
        iphdr->saddr[i] = ntohs(iphdr->saddr[i]);
        iphdr->daddr[i] = ntohs(iphdr->daddr[i]);
    }

    if (g_hds_ctrl.fuzzy_disabled == 0) {
        iphdr->saddr[0] = FUZZY_ADDR;
        iphdr->saddr[1] = FUZZY_ADDR;
        iphdr->saddr[2] = FUZZY_ADDR;
        iphdr->daddr[0] = FUZZY_ADDR;
        iphdr->daddr[1] = FUZZY_ADDR;
        iphdr->daddr[2] = FUZZY_ADDR;
    }
}

static void fill_in_tcp_info(struct dpa_hids_pkt_info *info, struct tcphdr *hdr)
{
    struct hds_tcpinfo *tcpinfo = &info->v.tcp;

    if (g_hds_ctrl.fuzzy_disabled != 0) {
        tcpinfo->src_port = ntohs(hdr->source);
        tcpinfo->dst_port = ntohs(hdr->dest);
    } else {
        tcpinfo->src_port = FUZZY_PORT;
        tcpinfo->dst_port = FUZZY_PORT;
    }

    tcpinfo->seq = ntohl(hdr->seq);
    tcpinfo->ack_seq = ntohl(hdr->ack_seq);
    tcpinfo->data_offset = hdr->doff;
    tcpinfo->window = ntohs(hdr->window);
    tcpinfo->checksum = ntohs(hdr->check);
}

static void fill_in_udp_info(struct dpa_hids_pkt_info *info, struct udphdr *hdr)
{
    struct hds_udpinfo *udpinfo = &info->v.udp;

    if (g_hds_ctrl.fuzzy_disabled != 0) {
        udpinfo->src_port = ntohs(hdr->source);
        udpinfo->dst_port = ntohs(hdr->dest);
    } else {
        udpinfo->src_port = FUZZY_PORT;
        udpinfo->dst_port = FUZZY_PORT;
    }

    udpinfo->length = ntohs(hdr->len);
    udpinfo->checksum = ntohs(hdr->check);
}

static void fill_in_icmp_info(struct dpa_hids_pkt_info *info, void *hdr)
{
    struct hds_icmpinfo *icmpinfo = &info->v.icmp;
    struct icmphdr *icmp_hdr = (struct icmphdr *)hdr;

    icmpinfo->type = icmp_hdr->type;
    icmpinfo->code = icmp_hdr->code;
    icmpinfo->checksum = ntohs(icmp_hdr->checksum);
}

static int dpa_hds_ip6_proc(struct dpa_hids_pkt_info *info, struct sk_buff *p)
{
    struct udphdr *uhdr = NULL;
    struct tcphdr *thdr = NULL;
    struct icmp6hdr *icmp6_hdr = NULL;

    struct ipv6hdr *ip6hdr = (struct ipv6hdr *)skb_network_header(p);
    fill_in_ipv6_hdr(info, ip6hdr);
    info->ip_type = IP_VERSION6;
    info->trans_type = ip6hdr->nexthdr;
    switch (ip6hdr->nexthdr) {
        case IPPROTO_NONE:
            break;
        case IPPROTO_TCP:
            thdr = (struct tcphdr *)skb_transport_header(p);
            fill_in_tcp_info(info, thdr);
            break;
        case IPPROTO_UDP:
            uhdr = (struct udphdr *)skb_transport_header(p);
            fill_in_udp_info(info, uhdr);
            break;
        case IPPROTO_ICMPV6:
            icmp6_hdr = (struct icmp6hdr *)skb_transport_header(p);
            fill_in_icmp_info(info, icmp6_hdr);
            break;
        default:
            break;
    }

    return 0;
}

static int dpa_hds_ip4_proc(struct dpa_hids_pkt_info *info, struct sk_buff *p)
{
    struct udphdr *uhdr = NULL;
    struct tcphdr *thdr = NULL;
    struct icmphdr *icmp_hdr = NULL;

    struct iphdr *ip4hdr = (struct iphdr *)skb_network_header(p);
    fill_in_ipv4_hdr(info, ip4hdr);
    info->ip_type = IP_VERSION4;
    info->trans_type = ip4hdr->protocol;
    switch (ip4hdr->protocol) {
        case IPPROTO_TCP:
            thdr = (struct tcphdr *)skb_transport_header(p);
            fill_in_tcp_info(info, thdr);
            break;
        case IPPROTO_UDP:
            uhdr = (struct udphdr *)skb_transport_header(p);
            fill_in_udp_info(info, uhdr);
            break;
        case IPPROTO_ICMP:
            icmp_hdr = (struct icmphdr *)skb_transport_header(p);
            fill_in_icmp_info(info, icmp_hdr);
            break;
        default:
            break;
        }
    return 0;
}

static int dpa_hds_delay_proc(struct dpa_hids_pkt_info *info, cost_time_stats *time_stats, int link_type)
{
    unsigned int tmp_delay = 0;
    if (time_stats->enabled == 0) {
        return 0;
    }
    /* 32k时间戳计算 */
    info->netif_layer_delay = time_stats->netif_cost_time;
    info->ip_layer_delay = time_stats->ip_cost_time;
    info->trans_layer_delay = time_stats->trans_cost_time;
    info->bridge_delay = time_stats->msg_cost_time;
    tmp_delay = info->netif_layer_delay + info->ip_layer_delay + info->trans_layer_delay + info->bridge_delay;
    if (link_type == PKT_UPLINK) {
        /* 上行时间戳 */
        info->total_delay = get_timer_slice_delta(time_stats->sock_timestamp, time_stats->if_timestamp);
        info->sock_delay = (info->total_delay - tmp_delay) >= 0 ? (info->total_delay - tmp_delay) : 0;
    } else {
        /* 下行时间戳 */
        info->total_delay = get_timer_slice_delta(time_stats->if_timestamp, time_stats->sock_timestamp);
        info->sock_delay = (info->total_delay - tmp_delay) >= 0 ? (info->total_delay - tmp_delay) : 0;
    }

    /* 转化为us */
    info->netif_layer_delay = timestamp_to_us(info->netif_layer_delay);
    info->ip_layer_delay    = timestamp_to_us(info->ip_layer_delay);
    info->trans_layer_delay = timestamp_to_us(info->trans_layer_delay);
    info->bridge_delay      = timestamp_to_us(info->bridge_delay);
    info->sock_delay        = timestamp_to_us(info->sock_delay);
    info->total_delay       = timestamp_to_us(info->total_delay);

    return 0;
}

int dpa_host_pkt_report(void *p, cost_time_stats *stat, int link_type)
{
    if (p == NULL || stat == NULL) {
        return -1;
    }
    int msg_id = link_type == PKT_UPLINK ? DPA_NET_OM_MSGID_DPA_UL_PKT_INFO : DPA_NET_OM_MSGID_DPA_DL_PKT_INFO;
    int pid = DIAG_DRV_HDS_PID;
    int ret;
    struct sk_buff *skb = NULL;
    struct dpa_hids_pkt_info info = {0};

    if (link_type == PKT_DOWNLINK) {
        skb = (struct sk_buff *)p;
    } else {
        return 0;
    }
    struct iphdr *ip_hdr = (struct iphdr *)skb_network_header(skb);
    info.link_type = link_type;
    info.version = ip_hdr->version;

    if (info.version == IP_VERSION4) {
        dpa_hds_ip4_proc(&info, p);
    } else {
        dpa_hds_ip6_proc(&info, p);
    }

    dpa_hds_delay_proc(&info, stat, link_type);

    ret = bsp_dpa_diag_trans_report(msg_id, pid, (unsigned char *)&info, sizeof(struct dpa_hids_pkt_info));

    return ret;
}

static int dpa_stack_hids_pkt_onoff(int en_flag)
{
    if (en_flag) {
        sbr_register_time_stat_cb(dpa_host_pkt_report);
    } else {
        sbr_register_time_stat_cb(NULL);
    }

    return 0;
}

int dpa_host_pkt_report_ctrl(unsigned char *data, unsigned int size)
{
    if (data == NULL || size < OM_MSG_SIZE(sizeof(ctrl_pkt))) {
        return -1;
    }

    int ret;
    dpa_om_msg *msg = (dpa_om_msg *)data;
    ctrl_pkt *ctrl = (ctrl_pkt *)msg->buffer;
    g_hds_ctrl.report_enabled = ctrl->report_enable;
#ifdef CONFIG_DPA_OM_FUZZY_OFF
    g_hds_ctrl.fuzzy_disabled = ctrl->fuzzy_disable;
#endif
    ret = dpa_stack_hids_pkt_onoff(g_hds_ctrl.report_enabled);

    return ret;
}

void dpa_om_hds_report_init(void)
{
    g_dpa_freq = bsp_get_slice_freq();
    g_hds_ctrl.report_enabled = 0;
    g_hds_ctrl.fuzzy_disabled = 0;
    return;
}
