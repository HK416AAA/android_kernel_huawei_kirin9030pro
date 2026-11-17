/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: wireless charge interference
 * Author: platform drivers
 */

#ifndef WIRELESS_CHARGE_INTF_H
#define WIRELESS_CHARGE_INTF_H
#ifdef _PRE_LINUX_TEST
#include <stdbool.h>
#else
#include <linux/types.h>
#endif

#ifdef CONFIG_MPXX_IO_DIE_HIPHYIO
int register_wl_charge_event(void);
int unregister_wl_charge_event(void);
bool is_wireless_charging(void);
void pm_state_notify_wl_charge(int state);
#else
static inline int register_wl_charge_event(void)
{
    return 0;
}

static inline int unregister_wl_charge_event(void)
{
    return 0;
}

static inline bool is_wireless_charging(void)
{
    return false;
}

static inline void pm_state_notify_wl_charge(int state)
{
}
#endif

#endif // WIRELESS_CHARGE_INTF_H
