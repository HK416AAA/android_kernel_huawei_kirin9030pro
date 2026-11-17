/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: MP12 Exception Recovery Function Declaration.
 * Author: platform drivers
 */

#ifndef __MP12_EXCEPTION_RST_H__
#define __MP12_EXCEPTION_RST_H__

// 和main/device/platform/mp12/pilot/chip/port/common/inc/adapter_reboot_cause.h对应
typedef enum {
    REBOOT_CAUSE_WL_WATCHDOG = 0x2001,
    REBOOT_CAUSE_WL_PLT_HARDFAULT = 0x2002,
    REBOOT_CAUSE_WL_HARDFAULT = 0x2003,
    REBOOT_CAUSE_WL_PATCH_HARDFAULT = 0x2004,
    REBOOT_CAUSE_WL_OTHERS_HARDFAULT = 0x2005,
    REBOOT_CAUSE_WL_PCIE_POWERUP_FAIL = 0x2006,
    REBOOT_CAUSE_BGI_WATCHDOG = 0x8001,
    REBOOT_CAUSE_B_PLT_HARDFAULT = 0x8002,
    REBOOT_CAUSE_GNSS_HARDFAULT = 0x8003,
    REBOOT_CAUSE_BTC_HARDFAULT = 0x8004,
    REBOOT_CAUSE_BTH_HARDFAULT = 0x8005,
    REBOOT_CAUSE_B_PATCH_HARDFAULT = 0x8006,
    REBOOT_CAUSE_B_OTHERS_HARDFAULT = 0x8007,
} reboot_cause_t;

excp_chip_cfg_t *get_mp12_chip_cfg(void);
void bfgx_subsys_trigger_rst_register_set(oal_bool_enum en);
oal_bool_enum bfgx_subsys_trigger_rst_register_get(void);
#endif
