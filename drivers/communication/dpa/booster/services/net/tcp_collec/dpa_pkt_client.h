/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 * Description: This file is the interface file of acpu communicate with pkt.
 * Author: tianlei
 * Create: 2024-12-12
 */

#ifndef DPA_PKT_CLIENT_H
#define DPA_PKT_CLIENT_H
 
void dpa_pkt_num_dmi_client_init(void);
typedef void (*get_pkt_num)(long *tcp_rx, long *tcp_tx, long *dns_rx, long *dns_tx);
extern void register_tcp_pkt_num_dmi_ops(get_pkt_num func);

#endif // !DPA_PKT_CLIENT_H