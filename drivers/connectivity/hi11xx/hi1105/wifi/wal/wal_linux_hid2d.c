/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * 功能说明 : wal_linux_hid2d.c
 * 作    者 : wifi
 * 创建日期 : 2025年08月27日
 */

#ifdef _PRE_WLAN_FEATURE_HID2D

#include "wal_linux_hid2d.h"
#include "oal_types.h"
#include "hmac_hid2d.h"
#ifdef CONFIG_HW_NSTACK_MINTP_WLAN_HOOK
#include <emcom/nstack/mintp/mintp.h>
#endif
/* MINTP钩子结构体 */
#ifdef CONFIG_HW_NSTACK_MINTP_WLAN_HOOK
typedef struct mintp_wlan_ops wal_mintp_ops_stru;
#else
typedef struct {
    int32_t (*config_low_latency)(oal_net_device_stru *, uint8_t);
} wal_mintp_ops_stru;
#endif

wal_mintp_ops_stru g_wal_mintp_ops = {
    .config_low_latency = wal_ioctl_config_low_latency_mintp_conn,
};

int32_t wal_register_mintp_ops(void)
{
#ifdef CONFIG_HW_NSTACK_MINTP_WLAN_HOOK
    mintp_register_wlan_ops(&g_wal_mintp_ops);
#else
    oam_warning_log0(0, OAM_SF_ANY, "{wal_register_mintp_ops:: Not support HW_NSTACK_MINTP!}");
#endif
    return OAL_SUCC;
}

int32_t wal_unregister_mintp_ops(void)
{
#ifdef CONFIG_HW_NSTACK_MINTP_WLAN_HOOK
    mintp_unregister_wlan_ops();
#else
    oam_warning_log0(0, OAM_SF_ANY, "{wal_unregister_mintp_ops:: Not support HW_NSTACK_MINTP!}");
#endif
    return OAL_SUCC;
}

#endif /* end of this file */