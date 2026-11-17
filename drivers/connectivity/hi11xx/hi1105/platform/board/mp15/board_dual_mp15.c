/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Driver Entry Function Declaration.
 * Author: platform drivers
 */

#ifdef _PRE_DUAL_CHIP
/* 头文件包含 */
#include "plat_common_clk.h"
#include "plat_firmware.h"
#include "plat_firmware_download.h"
#include "plat_debug.h"
#include "plat_pm.h"
#include "board_mp15.h"
#include "board_dual_mp15.h"

void hi_wlan_power_set_by_id(int32_t dev_id, int32_t on)
{
    if (dev_id > HCC_EP_WIFI_DEV1) {
        ps_print_info("dev_id [%d] is out of range\n", dev_id);
        return;
    }

#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
    if (on) {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dev[%d] probe:pull up power on gpio", dev_id);
        board_host_wakeup_dev_set_by_id(dev_id, 0);
        board_power_on(W_SYS);
    } else {
        oal_print_mpxx_log(MPXX_LOG_INFO, "dev[%d] probe:pull down power on gpio", dev_id);
        board_power_off(W_SYS);
        board_host_wakeup_dev_set_by_id(dev_id, 0);
    }
#endif
}

STATIC void mp15_board_chip_power_on(uint32_t dev_id)
{
    int32_t type = conn_get_gpio_type_by_id(dev_id, CHIP_POWR);

    ps_print_info("chip_power[%d] on called by %pF\n", dev_id, (void*)(uintptr_t)_RET_IP_);

    if (enable_board_pmu_clk32k() != BOARD_SUCC) {
        ps_print_err("mpxx enable 32k clk fail.\n");
    }

    power_state_change(type, BOARD_POWER_ON);
}

STATIC void mp15_board_chip_power_off(uint32_t dev_id)
{
    int32_t type = conn_get_gpio_type_by_id(dev_id, CHIP_POWR);
    ps_print_info("chip_power[%d] off called by %pF\n", dev_id, (void*)(uintptr_t)_RET_IP_);

    power_state_change(type, BOARD_POWER_OFF);

    board_host_wakeup_dev_set_by_id(dev_id, 0);
    if (disable_board_pmu_clk32k() != BOARD_SUCC) {
        ps_print_err("mp15 disable 32k clk fail.\n");
    }
}

STATIC int32_t mp15_wifi_enable(hcc_bus *hi_bus)
{
    int32_t ret;
    int64_t gpio_type = conn_get_gpio_type_by_id(hi_bus->dev_id, W_POWER);

    if (hcc_bus_get_shutdown_flag() == OAL_TRUE) {
        ps_print_err("mp15_wifi_enable::hcc shutdown or not probe, exit");
        return -OAL_EFAIL;
    }

    ps_print_info("mp15_wifi_enable::hi_bus->dev_id[%d], gpio_type[%d]", hi_bus->dev_id, (int32_t)gpio_type);

    /* 第一次枚举时BUS 还未初始化 */
    ret = hcc_bus_power_ctrl_register(hi_bus, HCC_BUS_CTRL_POWER_UP,
                                      board_wlan_gpio_power_on, (void *)gpio_type);
    if (ret) {
        ps_print_warning("mp15_wifi_enable::power ctrl down reg failed, ret=%d\n", ret);
    }
    ret = hcc_bus_power_action(hi_bus, HCC_BUS_POWER_UP);
    return ret;
}

STATIC int32_t mp15_wifi_disable(hcc_bus *hi_bus)
{
    int32_t ret;
    int64_t gpio_type = conn_get_gpio_type_by_id(hi_bus->dev_id, W_POWER);

    ret = hcc_bus_power_ctrl_register(hi_bus, HCC_BUS_CTRL_POWER_DOWN, board_wlan_gpio_power_off, (void *)gpio_type);
    if (ret) {
        ps_print_info("mp15_wifi_disable::power ctrl down reg failed, ret=%d", ret);
    }
    ret = hcc_bus_power_action(hi_bus, HCC_BUS_POWER_DOWN);
    power_state_change(gpio_type, BOARD_POWER_OFF); /* 确保w_en拉低 */
    return ret;
}

STATIC int32_t mp15_board_w_sys_enable(hcc_bus *hi_bus)
{
    return mp15_wifi_enable(hi_bus);
}

STATIC int32_t mp15_board_b_sys_enable(void)
{
    power_state_change(BFGX_POWER, BOARD_POWER_ON);
    return SUCC;
}

STATIC int32_t mp15_board_w_sys_disable(hcc_bus *hi_bus)
{
    return mp15_wifi_disable(hi_bus);
}

STATIC int32_t mp15_board_b_sys_disable(void)
{
    power_state_change(BFGX_POWER, BOARD_POWER_OFF);
    return SUCC;
}

STATIC int32_t mp15_board_w_power_on(hcc_bus *hi_bus)
{
    int32_t ret = SUCC;

    if ((hi_bus->dev_id == HCC_EP_WIFI_DEV) && (bfgx_is_shutdown())) {
        ps_print_info("wifi pull up power_on_enable gpio!\n");
        mp15_board_chip_power_on(HCC_EP_WIFI_DEV);
        if (mp15_board_w_sys_enable(hi_bus)) {
            ret = WIFI_POWER_BFGX_OFF_PULL_WLEN_FAIL;
        }
        if (mpxx_firmware_download_mode() == MODE_COMBO) {
            mp15_board_b_sys_enable();
        }
    } else {
        if (hi_bus->dev_id == HCC_EP_WIFI_DEV1) {
            ps_print_info("wifi dev1 pull up power_on_enable gpio!\n");
            mp15_board_chip_power_on(HCC_EP_WIFI_DEV1);
        }
        if (mp15_board_w_sys_enable(hi_bus)) {
            ret = WIFI_POWER_BFGX_ON_PULL_WLEN_FAIL;
        }
    }

    return ret;
}

STATIC int32_t mp15_board_b_power_on(hcc_bus *hi_bus)
{
    int32_t ret = SUCC;

#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    if (wlan_is_shutdown()) {
        ps_print_info("bfgx pull up power_on_enable gpio!\n");
        mp15_board_chip_power_on(HCC_EP_WIFI_DEV);
        ret = mp15_board_w_sys_enable(hi_bus);
        mp15_board_b_sys_enable();
    } else {
        mp15_board_b_sys_enable();
    }
#else
    mp15_board_chip_power_on(HCC_EP_WIFI_DEV);
    mp15_board_b_sys_enable();
#endif
    return ret;
}

STATIC int32_t mp15_board_power_on(uint32_t ul_subsystem)
{
    uint32_t dev_id = hcc_get_main_dev();
    hcc_bus *hi_bus = NULL;

    if (dev_id > HCC_EP_WIFI_DEV1) {
        ps_print_err("dev_id [%d] is out of range\n", dev_id);
        return -FAILURE;
    }

    hi_bus = hcc_get_bus(dev_id);
    if (hi_bus == NULL) {
        ps_print_info("hi_bus[%d] is NULL", dev_id);
        return -OAL_EFAIL;
    }

    if (ul_subsystem == W_SYS) {
        mp15_board_w_power_on(hi_bus);
    } else if (ul_subsystem == B_SYS) {
        mp15_board_b_power_on(hi_bus);
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
        return WIFI_POWER_FAIL;
    }

    return SUCC;
}

STATIC int32_t mp15_board_w_power_off(hcc_bus *hi_bus)
{
    if ((hi_bus->dev_id == HCC_EP_WIFI_DEV) && (bfgx_is_shutdown())) {
        ps_print_info("wifi pull down power_on_enable!\n");
        mp15_board_w_sys_disable(hi_bus);
        mp15_board_b_sys_disable();
        board_chip_power_off();
    } else {
        mp15_board_w_sys_disable(hi_bus);
        if (hi_bus->dev_id == HCC_EP_WIFI_DEV1) {
            ps_print_info("wifi dev1 pull down power_on_enable!\n");
            mp15_board_chip_power_off(HCC_EP_WIFI_DEV1);
        }
    }

    return SUCC;
}

STATIC int32_t mp15_board_b_power_off(hcc_bus *hi_bus)
{
#ifndef BFGX_UART_DOWNLOAD_SUPPORT
    if (wlan_is_shutdown()) {
        ps_print_info("bfgx pull down power_on_enable!\n");
        mp15_board_b_sys_disable();
        mp15_board_w_sys_disable(hi_bus);
        board_chip_power_off();
    } else {
        mp15_board_b_sys_disable();
    }
#else
    mp15_board_b_sys_disable();
    board_chip_power_off();
#endif
    return SUCC;
}

STATIC int32_t mp15_board_power_off(uint32_t ul_subsystem)
{
    uint32_t dev_id = hcc_get_main_dev();
    hcc_bus *hi_bus = NULL;

    if (dev_id > HCC_EP_WIFI_DEV1) {
        ps_print_err("mp15_board_power_off::dev_id [%d] is out of range\n", dev_id);
        return -FAILURE;
    }

    hi_bus = hcc_get_bus(dev_id);
    if (hi_bus == NULL) {
        ps_print_info("mp15_board_power_off::hi_bus[%d] is NULL", dev_id);
        return -OAL_EFAIL;
    }

    if (ul_subsystem == W_SYS) {
        return mp15_board_w_power_off(hi_bus);
    } else if (ul_subsystem == B_SYS) {
        return mp15_board_b_power_off(hi_bus);
    } else {
        ps_print_err("power input system:%d error\n", ul_subsystem);
        return -EFAIL;
    }

    return SUCC;
}

STATIC int32_t mp15_wlan_power_off(void)
{
    uint32_t dev_id = hcc_get_main_dev();
    struct wlan_pm_s *wlan_pm_info = NULL;
    hcc_bus *hi_bus = hcc_get_bus(dev_id);

    if (hi_bus == NULL) {
        ps_print_err("hi_bus[%d] is NULL!\n", dev_id);
        return -FAILURE;
    }

    wlan_pm_info = wlan_pm_get_drv_by_id(dev_id);
    if (wlan_pm_info == NULL) {
        ps_print_err("wlan_pm_info[%d] is NULL!\n", dev_id);
        return -FAILURE;
    }

    ps_print_info("mp15_wlan_power_off dev_id [%d]!\n", dev_id);

    if (dev_id == HCC_EP_WIFI_DEV) {
        wifi_notify_bfgx_status(SYS_CFG_NOTIFY_WIFI_CLOSE);
    }

    /* 先关闭SDIO TX通道 */
    hcc_bus_disable_state(hi_bus, OAL_BUS_STATE_TX);

    /* wakeup dev,send poweroff cmd to wifi */
    if (wlan_pm_poweroff_cmd() != OAL_SUCC) {
        /* wifi self close 失败了也继续往下执行，uart关闭WCPU，异常恢复推迟到wifi下次open的时候执行 */
        declare_dft_trace_key_info("wlan_poweroff_cmd_fail", OAL_DFT_TRACE_FAIL);
    }
    hcc_bus_disable_state(hi_bus, OAL_BUS_STATE_ALL);

    (void)mp15_board_w_power_off(hi_bus);

    if (wlan_pm_info != NULL) {
        wlan_pm_info->wlan_power_state = POWER_STATE_SHUTDOWN;
    }
    return SUCCESS;
}

STATIC int32_t mp15_wlan_firmware_download(uint32_t bus_dev_id)
{
    int32_t ret;
    int32_t error;
    struct wlan_pm_s *wlan_pm_info = NULL;
    hcc_bus *hi_bus = hcc_get_bus(bus_dev_id);

    if (hi_bus == NULL) {
        ps_print_err("hi_bus[%d] is NULL!\n", bus_dev_id);
        return -FAILURE;
    }

    wlan_pm_info = wlan_pm_get_drv_by_id(bus_dev_id);
    if (wlan_pm_info == NULL) {
        ps_print_err("wlan_pm_info[%d] is NULL!\n", bus_dev_id);
        return -FAILURE;
    }

    hcc_bus_power_action(hi_bus, HCC_BUS_POWER_PATCH_LOAD_PREPARE);

    if (bus_dev_id == HCC_EP_WIFI_DEV1) {
        error = firmware_download_function(WIFI_COMB_CFG, hi_bus);
    } else if (is_bfgx_support() && bfgx_is_shutdown() && (mpxx_firmware_download_mode() == MODE_COMBO)) {
        error = firmware_download_function(BFGX_AND_WIFI_CFG, hi_bus);
        mp15_board_b_sys_disable();
    } else {
        error = firmware_download_function(WIFI_CFG, hi_bus);
    }

    if (error != WIFI_POWER_SUCCESS) {
        ps_print_err("firmware download [%d] fail\n", bus_dev_id);
        if (error == -OAL_EINTR) {
            error = WIFI_POWER_ON_FIRMWARE_DOWNLOAD_INTERRUPT;
        } else if (error == -OAL_ENOPERMI) {
            error = WIFI_POWER_ON_FIRMWARE_FILE_OPEN_FAIL;
        } else {
            error = WIFI_POWER_BFGX_OFF_FIRMWARE_DOWNLOAD_FAIL;
        }
        return error;
    } else {
        wlan_pm_info->wlan_power_state = POWER_STATE_OPEN;
    }

    ret = hcc_bus_power_action(hi_bus, HCC_BUS_POWER_PATCH_LAUCH);
    if (ret != 0) {
        declare_dft_trace_key_info("wlan_poweron HCC_BUS_POWER_PATCH_LAUCH by gpio_fail", OAL_DFT_TRACE_FAIL);
        ps_print_err("wlan_poweron[%d] HCC_BUS_POWER_PATCH_LAUCH by gpio fail ret=%d", bus_dev_id, ret);
        error = WIFI_POWER_BFGX_OFF_BOOT_UP_FAIL;
        return error;
    }

    return WIFI_POWER_SUCCESS;
}

STATIC int32_t mp15_wlan_power_on(void)
{
    int32_t ret;
    uint32_t dev_id = hcc_get_main_dev();
    if (dev_id > HCC_EP_WIFI_DEV1) {
        ps_print_err("mp15_wlan_power_on::dev_id [%d] is out of range\n", dev_id);
        return -FAILURE;
    }

    ps_print_info("mp15_wlan_power_on::dev_id [%d]!\n", dev_id);

    if (mp15_board_power_on(W_SYS)) {
        ps_print_err("mp15_wlan_power_on::wlan[%d] failed\n", dev_id);
        return -FAILURE;
    }

    ret = mp15_wlan_firmware_download(dev_id);
    if (ret != WIFI_POWER_SUCCESS) {
        return ret;
    }

    if (dev_id == HCC_EP_WIFI_DEV) {
        wifi_notify_bfgx_status(SYS_CFG_NOTIFY_WIFI_OPEN);
    }

    return ret;
}

void board_callback_init_dual_mp15_power(void)
{
    if (get_g_bus_dev_num_from_ini() == 1) {
        ps_print_warning("ini cfg bus_dev_num is 1\n");
        return;
    }

    g_st_board_info.bd_ops.board_power_on = mp15_board_power_on;
    g_st_board_info.bd_ops.board_power_off = mp15_board_power_off;
    g_st_board_info.bd_ops.wlan_power_on = mp15_wlan_power_on;
    g_st_board_info.bd_ops.wlan_power_off = mp15_wlan_power_off;
}
#endif
