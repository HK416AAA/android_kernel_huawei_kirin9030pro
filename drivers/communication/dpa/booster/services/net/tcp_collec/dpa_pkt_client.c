/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
* Description: This file is the impl file of acpu communicate with pkt.
* Author: tianlei
* Create: 2025-05-10
*/
#include "dpa_pkt_client.h"
#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <securec.h>
#include "interface/client/booster_dmi_client.h"
#include "hwnet/booster/tcp_para_collec.h"
 
static struct tcp_collec *g_pkt_num_packet = NULL;
 
typedef struct tcp_collec {
    unsigned int tcp_tx_pkt_sum;
    unsigned int tcp_rx_pkt_sum;
    unsigned int dns_tx_pkt_sum;
    unsigned int dns_rx_pkt_sum;
} tcp_collec_t;
 
#define ARR_LEN 2
static char booster_arr[ARR_LEN] = {0x01, 0x02};
 
static void tcp_pkt_num_response_handler(unsigned short cmd, unsigned char *data, unsigned int len)
{
    if (cmd == GET_PKT_NUM) {
        if (data == NULL) {
            return;
        }
        if (len > sizeof(tcp_collec_t)) {
            pr_err("[dpa_chr] len out of limit!");
            return;
        }
        int ret = memcpy_s(g_pkt_num_packet, len, data, len);
        pr_info("dpa tcp_rx_num=%d, tcp_tx_num=%d, dns_rx_num=%d, dns_tx_num=%d.",
                g_pkt_num_packet->tcp_rx_pkt_sum,
                g_pkt_num_packet->tcp_tx_pkt_sum,
                g_pkt_num_packet->dns_rx_pkt_sum,
                g_pkt_num_packet->dns_tx_pkt_sum);
        if (ret != EOK) {
            pr_err("handle_get_pkt_num_response memcpy_s failed!");
        }
    }
}
 
void get_pkt_num_res(long *tcp_rx, long *tcp_tx, long *dns_rx, long *dns_tx)
{
    int ret = booster_dpa_request_async(TCP_PKT_COLLEC, GET_PKT_NUM, booster_arr, ARR_LEN);
    if (ret != 0) {
        pr_info("dpa get pkt num request fail");
    }
    *tcp_rx = *tcp_rx + g_pkt_num_packet->tcp_rx_pkt_sum;
    *tcp_tx = *tcp_tx + g_pkt_num_packet->tcp_tx_pkt_sum;
    *dns_rx = *dns_rx + g_pkt_num_packet->dns_rx_pkt_sum;
    *dns_tx = *dns_tx + g_pkt_num_packet->dns_tx_pkt_sum;
    memset_s(g_pkt_num_packet, sizeof(struct tcp_collec), 0, sizeof(struct tcp_collec));
}
 
void dpa_pkt_num_dmi_client_init(void)
{
#ifdef CONFIG_HW_BOOSTER
    register_tcp_pkt_num_dmi_ops(get_pkt_num_res);
#endif
    g_pkt_num_packet = (struct tcp_collec *)kmalloc(sizeof(struct tcp_collec), GFP_KERNEL);
    if (g_pkt_num_packet == NULL) {
        return;
    }
    register_handle_response_func(TCP_PKT_COLLEC, tcp_pkt_num_response_handler);
    pr_info("dpa pkt num dmi client init");
}