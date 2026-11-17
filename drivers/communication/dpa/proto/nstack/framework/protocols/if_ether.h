/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef SPL_IF_ETHER_H
#define SPL_IF_ETHER_H

#include "stack_types.h"

#define SPL_ETH_ALEN 6 /* ETH_ALEN Octets in one ethernet addr */

#define SPL_ETH_P_IP    0x0800 /* ETH_P_IP Internet Protocol packet */
#define SPL_ETH_P_ARP   0x0806 /* Address Resolution packet */
#define SPL_ETH_P_8021Q 0x8100 /* ETH_P_8021Q 802.1Q VLAN Extended Header */
#define SPL_ETH_P_IPV6  0x86DD /* ETH_P_IPV6 IPv6 over bluebook */

#pragma pack (4)
struct eth_addr {
    u8 addr[SPL_ETH_ALEN];
};
#pragma pack ()

#endif /* SPL_IF_ETHER_H */
