/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 */

#ifndef OPT_H
#define OPT_H

#include "stack_types.h"
#include "config.h"
#include "compile_config.h"

#ifndef SPL_IP_DEBUG
#define SPL_IP_DEBUG 1
#endif

#ifndef SPL_TCP_DEBUG
#define SPL_TCP_DEBUG 1
#endif

#ifndef TIME_RECORD
#define TIME_RECORD 0
#endif

#ifndef NO_BBR
#define NO_BBR
#endif

#ifndef SPL_REUSEPORT
#define SPL_REUSEPORT 1
#endif

#ifndef SPL_IPV6
#define SPL_IPV6 1
#endif

#ifndef SPL_ETH
#define SPL_ETH 1
#endif

#ifndef SPL_LINGER
#define SPL_LINGER 1
#endif

#ifndef SPL_TCP_SACK
#define SPL_TCP_SACK 1
#endif

#ifndef SPL_TCP_DEFER_ACCEPT
#define SPL_TCP_DEFER_ACCEPT 1
#endif

#ifndef SPL_TCP_TIMESTAMPS
#define SPL_TCP_TIMESTAMPS 1
#endif

#ifndef SPL_TCP_RACK
#define SPL_TCP_RACK 1
#endif

#ifndef SPL_TCP_CALC_RTT
#if SPL_TCP_RACK || !defined(NO_BBR) || !defined(NO_CUBIC)
#define SPL_TCP_CALC_RTT 1
#else
#define SPL_TCP_CALC_RTT 0
#endif
#endif

#ifndef SPL_HIGH_PRECISION_RTT
#define SPL_HIGH_PRECISION_RTT 0
#endif

#ifndef SPL_TCP_CALCULATE_EFF_SEND_MSS
#define SPL_TCP_CALCULATE_EFF_SEND_MSS 1
#endif

#ifndef SPL_LOOPBACK
#define SPL_LOOPBACK 1
#endif

#ifndef SPL_FLOW_CTL
#define SPL_FLOW_CTL 1
#endif

#ifndef SPL_CHKSUM_RX_IP
#define SPL_CHKSUM_RX_IP 1
#endif

#ifndef SPL_CHKSUM_RX_TCP
#define SPL_CHKSUM_RX_TCP 1
#endif

#ifndef SPL_CHKSUM_RX_UDP
#define SPL_CHKSUM_RX_UDP 1
#endif


/* STATS */
#ifndef SPL_STATS
#define SPL_STATS 1
#endif

#if SPL_STATS
#ifndef SPL_NETIF_STATS
#define SPL_NETIF_STATS 1
#endif

#ifndef SPL_ETH_STATS
#define SPL_ETH_STATS 1
#endif

#ifndef SPL_MSG_STATS
#define SPL_MSG_STATS 1
#endif

#ifndef SPL_IP_STATS
#define SPL_IP_STATS 1
#endif

#ifndef SPL_NETIFIP_STATS
#define SPL_NETIFIP_STATS 1
#endif

#ifndef SPL_ARP_STATS
#define SPL_ARP_STATS 1
#endif

#ifdef SPL_IPV6
#ifndef SPL_IP6_STATS
#define SPL_IP6_STATS 1
#endif

#ifndef SPL_ND6_STATS
#define SPL_ND6_STATS 1
#endif

#ifndef SPL_MLD6_STATS
#define SPL_MLD6_STATS 1
#endif

#else
#ifndef SPL_IP6_STATS
#define SPL_IP6_STATS 0
#endif

#ifndef SPL_ND6_STATS
#define SPL_ND6_STATS 0
#endif

#ifndef SPL_MLD6_STATS
#define SPL_MLD6_STATS 0
#endif
#endif /* SPL_IPV6 */

#ifndef SPL_UDP_STATS
#define SPL_UDP_STATS 1
#endif

#ifndef SPL_TCP_STATS
#define SPL_TCP_STATS 1
#endif

#else /* SPL_STATS */

#define SPL_NETIF_STATS 0
#define SPL_ETH_STATS 0
#define SPL_MSG_STATS 0
#define SPL_IP_STATS 0
#define SPL_NETIFIP_STATS 0
#define SPL_ARP_STATS 0
#define SPL_IP6_STATS 0
#define SPL_ND6_STATS 0
#define SPL_MLD6_STATS 0
#define SPL_UDP_STATS 0
#define SPL_TCP_STATS 0

#endif /* SPL_STATS */

#ifndef SPL_LITTLE_ENDIAN
#define SPL_LITTLE_ENDIAN 1234
#endif

#ifndef SPL_BIG_ENDIAN
#define SPL_BIG_ENDIAN 4321
#endif
#ifndef SPL_BYTE_ORDER
#define SPL_BYTE_ORDER SPL_LITTLE_ENDIAN
#endif

#ifndef COST_TIME_STAT
#define COST_TIME_STAT 1
#endif

#ifndef CONFIG_DPA_TC
#define CONFIG_DPA_TC 1
#endif

#endif /* __OPT_H__ */
