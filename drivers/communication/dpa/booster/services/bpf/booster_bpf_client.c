/*
* Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
* Description: This file is the impl file of acpu communicate with bpf_dpa.
* Author: hejingyu
* Create: 2025-05-10
*/
#include "booster_bpf_client.h"

#include "booster_dmi_client.h"
#include "booster_features.h"
#include "bpf_dpa_netlink.h"

#define HED_LEN (sizeof(struct nlmsghdr) + sizeof (bpf_op_code))

static void handle_msg_from_DPA(unsigned short cmd, unsigned char *data, unsigned int len)
{
    // 当前仅有此消息类型需要返回
    if (cmd != NETLINK_BPF_READ_CONNLOSSSTATMAP) {
        printk(KERN_ERR "[booster_bpf_client] recv msg from DPA wrong type!\n");
        return;
    }
    if (len != sizeof(struct bpf_packet_msg)) {
        printk(KERN_ERR "[booster_bpf_client] recv msg from DPA wrong len!\n");
        return;
    }
    if (send_resp_msg(NETLINK_BPF_READ_CONNLOSSSTATMAP, (struct bpf_packet_msg *)data) != 0 ){
        printk(KERN_ERR "[booster_bpf_client] send msg to kernel failed.\n");
    }
}

void bpf_client_init(void)
{
    if (bpf_dpa_netlink_module_init() != 0) {
        printk(KERN_ERR "[booster_bpf_client] bpf netlink init failed!\n");
        return;
    }
    register_handle_response_func(BPF_MAP_OP, handle_msg_from_DPA);
    printk(KERN_INFO "[booster_bpf_client] bpf client init success!\n");
}