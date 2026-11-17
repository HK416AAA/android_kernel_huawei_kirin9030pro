/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: wireless charge interference function
 * Author: platform drivers
 */

#ifdef CONFIG_MPXX_IO_DIE_HIPHYIO
#include <linux/notifier.h>
#include "external/pcie_interface.h"
#include "plat_debug.h"
#include "plat_pm.h"
#include "plat_pm_wlan.h"

#include <chipset_common/hwpower/common_module/power_event_ne.h>

static bool g_has_intf = false;
static volatile bool g_wl_charge_state = false;

static int wl_charge_event(struct notifier_block *nb, unsigned long event, void *data);

static struct notifier_block g_charge_notifier = {
    .notifier_call = wl_charge_event,
};

static void wl_handle_wireless_charge_event(bool on)
{
    uint32_t ret;

    if (g_wl_charge_state == false && on == false) {
        g_wl_charge_state = on;
        ps_print_info("is not wireless disconnect event, ignore\n", on);
        return;
    }
    g_wl_charge_state = on;
    if (wlan_is_shutdown()) {
        ps_print_info("wlan is down, ignore wireless charge event\n");
        return;
    }
    if (on) {
        ret = wlan_pm_disable();
        ps_print_info("disable low power,ret:%u\n", ret);
    } else {
        ret = wlan_pm_enable();
        ps_print_info("enable low power,ret:%u\n", ret);
    }
}

static int wl_charge_event(struct notifier_block *nb, unsigned long event, void *data)
{
    ps_print_info("nc charge event:%lu\n", event);
    switch (event) {
        case POWER_NE_WIRELESS_CONNECT:
            wl_handle_wireless_charge_event(true);
            break;
        case POWER_NE_WIRELESS_DISCONNECT:
            wl_handle_wireless_charge_event(false);
            break;
        default:
            break;
    }
    return NOTIFY_DONE;
}

int register_wl_charge_event(void)
{
    int ret;

    g_has_intf = mpxx_wireless_charge_intf();
    if (!g_has_intf) {
        ps_print_info("has no wireless charge intf\n");
        return OAL_SUCC;
    }
    ret = power_event_bnc_register(POWER_BNT_CONNECT, &g_charge_notifier);
    if (ret) {
        ps_print_err("register wireless charge notifier failed\n");
    } else {
        ps_print_info("register wireless charge notifier succ\n");
    }
    return (ret == 0) ? OAL_SUCC : -OAL_FAIL;
}

int unregister_wl_charge_event(void)
{
    int ret;

    if (!g_has_intf) {
        ps_print_info("has no wireless charge intf\n");
        return OAL_SUCC;
    }
    ret = power_event_bnc_unregister(POWER_BNT_CONNECT, &g_charge_notifier);
    if (ret) {
        ps_print_err("unregister wireless charge notifier failed\n");
    } else {
        ps_print_info("unregister wireless charge notifier succ\n");
    }
    return (ret == 0) ? OAL_SUCC : -OAL_FAIL;
}

bool is_wireless_charging(void)
{
    return g_wl_charge_state;
}

void pm_state_notify_wl_charge(int state)
{
    uint32_t ret;

    if (state == WIFI_STATE_ON && g_wl_charge_state) {
        ret = wlan_pm_disable();
        ps_print_info("disable low power,ret:%u\n", ret);
    }
}
#endif /* CONFIG_MPXX_IO_DIE_HIPHYIO */
