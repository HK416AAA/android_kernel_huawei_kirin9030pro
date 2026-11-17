/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 */
#ifndef SPL_IN_H
#define SPL_IN_H

#include "sockets.h"

#define SPL_IPPROTO_IP      0
#define SPL_IPPROTO_IGMP    2
#define SPL_IPPROTO_TCP     6
#define SPL_IPPROTO_UDP     17
#define SPL_IPPROTO_IPV6    41
#define SPL_IPPROTO_UDPLITE 136

/* IP_MTU_DISCOVER values */
#define IP_PMTUDISC_DONT 0
#define IP_PMTUDISC_WANT 1
#define IP_PMTUDISC_DO 2
#define IP_PMTUDISC_PROBE 3
#define IP_PMTUDISC_INTERFACE 4
#define IP_PMTUDISC_OMIT 5


#define IP_TOS 1
#define IP_TTL 2
#define IP_PKTINFO 8
#define IP_MTU_DISCOVER 10
#define IP_DROP_MEMBERSHIP 36
#define IP_MULTICAST_IF 32
#define IP_MULTICAST_TTL 33
#define IP_MULTICAST_LOOP 34
#define IP_ADD_MEMBERSHIP 35
#define IP_MULTICAST_ALL 49

#define INADDR_BROADCAST    ((unsigned long int) 0xffffffff)

struct spl_in_pktinfo {
    int ipi_ifindex;
    struct spl_in_addr ipi_spec_dst;
    struct spl_in_addr ipi_addr;
};

struct spl_ip_mreq  {
    struct spl_in_addr imr_multiaddr;
    struct spl_in_addr imr_interface;
};

struct spl_ip_mreqn {
    struct spl_in_addr imr_multiaddr;
    struct spl_in_addr imr_address;
    int imr_ifindex;
};

#endif /* SPL_IN_H */
