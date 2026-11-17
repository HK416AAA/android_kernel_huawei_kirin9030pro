/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: This file is the internal header file for the
 *              TCP/IP parameter collection module.
 */

#ifndef _NETWORKSLICE_IP_PARA_COLLEC_H
#define _NETWORKSLICE_IP_PARA_COLLEC_H

#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/netfilter.h>
#include <linux/rtc.h>
#include <linux/timer.h>
#include <linux/timekeeping.h>
#include <uapi/linux/netfilter.h>
#include <uapi/linux/netfilter_ipv4.h>
#include <net/sock.h>
#include "netmanagerext_netlink.h"
#include "data_dubai_collect.h"

#define NF_INET_BUFHOOK NF_INET_NUMHOOKS
#define NS_CONVERT_MS 1048576
#define BUF_MAX 10000
#endif // _NETWORKSLICE_IP_PARA_COLLEC_H
