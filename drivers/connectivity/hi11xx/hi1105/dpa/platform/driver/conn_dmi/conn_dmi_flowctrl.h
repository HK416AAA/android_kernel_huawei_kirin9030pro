/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: dmi 流控
 * Author: dpa drivers
 */

#ifndef CONN_DMI_FLOWCTRL_H
#define CONN_DMI_FLOWCTRL_H

#include <stdint.h>
#include "oal_net.h"

void oal_netbuf_spinlock_init(void);
void oal_netbuf_spinlock_exit(void);
void netbuf_flowctrl_check(void);

void hcc_netbuf_addlist_tail_with_flowctrl(oal_netbuf_head_stru *head, oal_netbuf_stru *buf);
void hcc_netbuf_addlist_head_with_flowctrl(oal_netbuf_head_stru *head, oal_netbuf_stru *buf);
oal_netbuf_stru *hcc_netbuf_delist_head_with_flowctrl(oal_netbuf_head_stru *head);
oal_netbuf_stru *hcc_netbuf_delist_tail_with_flowctrl(oal_netbuf_head_stru *head);
int32_t hcc_netbuf_clear_list_with_flowctrl(oal_netbuf_head_stru *head);
void hcc_netbuf_delete_with_flowctrl(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *head);

#endif // CONN_DMI_FLOWCTRL_H