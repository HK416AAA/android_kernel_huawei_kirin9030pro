/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:oam_dsm.c header file
 * Author: platform drivers
 */

#ifndef OAM_DSM_H
#define OAM_DSM_H

#ifdef CONFIG_MPXX_DSM
/* 标准dsm_id引用 */
#if defined(_PRE_PRODUCT_HI1620S_KUNPENG) || defined(_PRE_WINDOWS_SUPPORT)
#include <linux/huawei/dsm/dsm_pub.h>
#else
#include <dsm/dsm_pub.h>
#endif
#else
/* CONFIG_MPXX_DSM 未定义，标准dsm_id打桩 */
#define DSM_WIFI_PCIE_LINKDOWN			909030024
#endif
#include "oal_types.h"

/* 私有定制dsm_id，若需扩展，需备案申请  */
#define DSM_MPXX_TCXO_ERROR        909030001
#define DSM_PCIE_ENMU_FAIL         909030002
#define DSM_MPXX_DOWNLOAD_FIRMWARE 909030033
#define DSM_BUCK_PROTECTED         909030034
#define DSM_MPXX_HALT              909030035
#define DSM_WIFI_FEMERROR          909030036
#define DSM_PCIE_SWITCH_SDIO_FAIL  909030043
#define DSM_PCIE_SWITCH_SDIO_SUCC  909030044
#define DSM_WIFI_LNAERROR          909030046
#define DSM_PMU_ERROR              909030047
#define DSM_WIFI_SAWERROR          909030048
#define DSM_HIO_ERROE              909030049
#define DSM_BT_FEMERROR            913002007

// 子系统定义头文件解耦
typedef enum sub_system {
    SYSTEM_TYPE_WIFI = 0,
    SYSTEM_TYPE_BT = 1,
    SYSTEM_TYPE_GNSS = 2,
    SYSTEM_TYPE_FM = 3,
    SYSTEM_TYPE_PLATFORM = 4,
    SYSTEM_TYPE_BFG = 5,
    SYSTEM_TYPE_IR = 6,
    SYSTEM_TYPE_NFC = 7,
    SYSTEM_TYPE_BUT,
} sub_system_enum;

/* 每个DSM_ID消息备案的最长长度有差别，请先了解清楚长度和消息ID的对应关系 */
#define DSM_BUF_MAX_SIZE           256 /* DSM最大上报长度 */
#ifdef CONFIG_MPXX_DSM
void hw_mpxx_dsm_client_notify(int sub_sys, int dsm_id, const char *fmt, ...);
void hw_mpxx_register_dsm_client(void);
void hw_mpxx_unregister_dsm_client(void);
#else
static inline void hw_mpxx_dsm_client_notify(int sub_sys, int dsm_id, const char *fmt, ...)
{
    oal_reference(sub_sys);
    oal_reference(dsm_id);
    oal_reference(fmt);
}
static inline void hw_mpxx_register_dsm_client(void)
{
}
static inline void hw_mpxx_unregister_dsm_client(void)
{
}
#endif
#endif // OAM_DSM_H__
