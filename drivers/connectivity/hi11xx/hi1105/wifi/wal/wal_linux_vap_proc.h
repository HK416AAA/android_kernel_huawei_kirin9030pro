/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2024. All rights reserved.
 * 功能说明 : wal_linux_vap_proc.c 的头文件 proc 文件系统 E5 产品使用
 * 作    者 : wifi3
 * 创建日期 : 2024年5月18日
 */
#ifndef WAL_LINUX_VAP_PROC_H
#define WAL_LINUX_VAP_PROC_H

#ifdef _PRE_WLAN_VAP_PROC
#include "wal_linux_ioctl.h"
#include "wal_dfx.h"
#include "hd_event_vap.h"
#include "oam_stat_wifi.h"
#include "wal_linux_vendor.h"
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,59)) && (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#include "internal.h"
#endif

void wal_add_vap_proc_file(oal_net_device_stru *net_dev);
void wal_del_vap_proc_file(oal_net_device_stru *net_dev);
int32_t wal_vendor_query_vap_info_ext(mac_vap_stru *mac_vap);
int32_t wal_vendor_get_user_info_ext(mac_vap_stru *mac_vap, uint8_t *mac_addr);
#endif

#endif
