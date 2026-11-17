/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2024 Huawei Device Co., Ltd.
 *
 * Operations on the lowpower protocol
 * Authors: yangyanjun
 */
#ifndef __LOWPOWER_PROTOCOL_H
#define __LOWPOWER_PROTOCOL_H

#ifdef CONFIG_LOWPOWER_PROTOCOL
#include <linux/types.h>
#include <linux/uidgid.h>
#include <linux/printk.h>
#include <net/sock.h>
#include <net/ip.h>
#include <net/tcp.h>


typedef void(*ext_init)(void);
void regist_dpa_init(ext_init fun);
void __net_exit lowpower_protocol_net_exit(struct net *net);
void __net_init lowpower_protocol_net_init(struct net *net);
u32 dpa_uid_match(uid_t kuid);
bool get_dpa_stack_bypass_status(void);
u32 dpa_uid_list_cnt(void);
#endif /* CONFIG_LOWPOWER_PROTOCOL */
#endif /* __LOWPOWER_PROTOCOL_H */