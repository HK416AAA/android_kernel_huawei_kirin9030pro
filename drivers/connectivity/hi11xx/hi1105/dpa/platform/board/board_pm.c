/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: board_pm.c
 * Author: dpa drivers
 */

/* 头文件包含 */
#include <stdint.h>
#include "hcc_base.h"
#include "hcc_master.h"
#include "hcc_slave.h"
#include "pcie_chip.h"
#include "ete_host.h"
#include "hcc_adapter.h"
#include "oal_util.h"
#include "oam_main.h"
#include "conn_dmi_hcc.h"
#include "conn_dmi_msg.h"
#include "conn_dmi_flowctrl.h"
#include "dpe_main.h"
#include "pm_wlan.h"
#include "dpa_exception_rst.h"
#include "bsp_console.h"
#include "oam_logger.h"
#include "oam_wdk.h"
#include "board_pm.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_DPA_FILE_ID_BOARD_PM_C

static powerup_res_sync_stru g_powerup_res;
static uint8_t g_dpa_open_stat;

int32_t get_mpxx_subchip_type(void)
{
    return g_powerup_res.cfg.subchip_type;
}

int32_t dpa_in_excepion_reset(void)
{
    return g_powerup_res.cfg.in_excep_flag;
}

static int32_t powerup_software_res_init(powerup_res_sync_stru *pci_res)
{
    int32_t ret;
    memcpy_s((void *)&g_powerup_res, sizeof(powerup_res_sync_stru),
             pci_res, sizeof(powerup_res_sync_stru));
    exception_module_init();
    ret = oam_main_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_INFO, "oam_main_init fail, ret[0x%x]", ret);
        goto err_oam_main_init;
    }

    oal_netbuf_spinlock_init(); // dmi/hcc注册成功后, 操作队列会用到锁, 需提前初始化
    ret = hcc_dev_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_INFO, "hcc_dev_init fail, ret[0x%x]", ret);
        goto err_hcc_dev_init;
    }

    ret = dmi_hcc_transfer_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_INFO, "dmi_hcc_transfer_init fail, ret[0x%x]", ret);
        goto err_dmi_hcc_transfer_init;
    }

    ret = pm_wlan_module_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_INFO, "pm_wlan_module_init fail, ret[0x%x]", ret);
        goto err_pm_wlan_module_init;
    }

    return OAL_SUCC;

err_pm_wlan_module_init:
    dmi_hcc_transfer_deinit();
err_dmi_hcc_transfer_init:
    hcc_dev_deinit();
err_hcc_dev_init:
    oal_netbuf_spinlock_exit();
    oam_main_deinit();
err_oam_main_init:
    exception_module_deinit();
    return -OAL_FAIL;
}

static void shutdown_software_res_deinit(void)
{
    oal_netbuf_spinlock_exit();
    pm_wlan_module_deinit();
    dmi_hcc_transfer_deinit();
    hcc_dev_deinit();
    oam_main_deinit();
}

static int32_t powerup_hardware_res_init(void)
{
    return oal_pcie_bus_init(&g_powerup_res);
}

static void shutdown_hardware_res_deinit(void)
{
    if (g_powerup_res.cfg.in_excep_flag == OAL_TRUE) {
        return;
    }
    oal_pcie_bus_deinit();
}

/* open消息上半部持wakelock */
int32_t dpa_open_top(uint8_t *buf, uint16_t buf_len)
{
    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "dpa_open_top");
    oal_wake_lock(WIFI_WAKE_PM);
    return OAL_SUCC;
}

/* open消息下半部处理上电流程 */
int32_t dpa_open_bottom(uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;

    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "dpa_open_bottom");
    if (g_dpa_open_stat == OAL_TRUE) {
        oam_error_log0(0, OAM_SF_DPA, "dpa is already open");
    }

    exception_open_init();
    if (g_powerup_res.cfg.in_excep_flag == OAL_TRUE) {
        oam_warning_log0(0, OAM_SF_DPA, "dpa_open powerup_res_init");
        ret = powerup_hardware_res_init();
        if (ret != OAL_SUCC) {
            oam_error_log1(0, OAM_SF_DPA, "dpa_open powerup_res_init fail %d", ret);
            oal_wake_unlock(WIFI_WAKE_PM);
            return ret;
        }
        /* 硬件资源初始化并且上电成功, 清理本地资源 */
        g_powerup_res.cfg.in_excep_flag = OAL_FALSE;
        oam_warning_log0(0, OAM_SF_DPA, "dpa_open res init succ!");
    }
    netbuf_flowctrl_check();
    ret = hcc_master_power_action(HCC_BUS_POWER_UP);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "HCC_BUS_POWER_DOWN fail %d", ret);
        oal_wake_unlock(WIFI_WAKE_PM);
        return ret;
    }
    hcc_rx_action_init();
    hcc_thread_open();
    g_dpa_open_stat = OAL_TRUE;
    return OAL_SUCC;
}

int32_t dpa_close(uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;
    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "dpa_close");
    if (g_dpa_open_stat == OAL_FALSE) {
        oam_warning_log0(0, OAM_SF_DPA, "dpa not open, skip close process");
        oal_wake_unlock(WIFI_WAKE_PM);
        return OAL_SUCC;
    }

    hcc_thread_close();
    ret = hcc_master_power_action(HCC_BUS_POWER_DOWN);
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "HCC_BUS_POWER_DOWN fail %d", ret);
        pm_wlan_deinit();
        g_dpa_open_stat = OAL_FALSE;
        oal_wake_unlock(WIFI_WAKE_PM);
        return ret;
    }
    hcc_disable();
    netbuf_flowctrl_check();
    pm_wlan_deinit();
    g_dpa_open_stat = OAL_FALSE;
    oal_wake_unlock(WIFI_WAKE_PM);
    return OAL_SUCC;
}

int32_t powerup_process(uint8_t *buf, uint16_t buf_len)
{
    /* 枚举消息未加唤醒锁保护，流程中不能有等待中断触发的动作 */
    powerup_res_sync_stru *ptr = (powerup_res_sync_stru *)buf;

    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "enum_process");
    /* DPA接收到枚举消息后, 先初始化软件资源 */
    if (powerup_software_res_init(ptr) != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "powerup_software_res_init fail");
        return -OAL_FAIL;
    }

    /* 判断当前Device是否探测成功: 0表示探测成功, 继续执行; 1表示探测失败, 硬件资源初始化跟随opne消息处理 */
    if (g_powerup_res.cfg.in_excep_flag == OAL_FALSE && (powerup_hardware_res_init() != OAL_SUCC)) {
        /* Device探测成功, 枚举中直接对硬件资源初始化 */
        shutdown_software_res_deinit();
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "powerup_hardware_res_init fail");
        return -OAL_FAIL;
    }

    return OAL_SUCC;
}

int32_t shutdown_process(uint8_t *buf, uint16_t buf_len)
{
    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "shutdown_process");
    shutdown_hardware_res_deinit();
    shutdown_software_res_deinit();
    return OAL_SUCC;
}

int32_t wifi_ready_process(uint8_t *buf, uint16_t buf_len)
{
    int32_t ret;

    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "wifi_ready_process");
    pm_wlan_init();
    ret = oal_ete_rx_ringbuf_init();
    if (ret != OAL_SUCC) {
        oam_error_log1(0, OAM_SF_DPA, "oal_ete_rx_ringbuf_init fail %d", ret);
        pm_wlan_deinit();
        oal_wake_unlock(WIFI_WAKE_PM);
        return -OAL_FAIL;
    }
    hcc_enable();
    return OAL_SUCC;
}

void board_cosole_regist(void)
{
    bsp_mo_cmd_regist("pcie_trigger_dfr", (console_cmd_t)oal_pcie_trigger_dfr, 0, 1);
    bsp_mo_cmd_regist("oam_set_loglevel", (console_cmd_t)oam_log_set_log_level, 1, 1);
}

void board_pm_init(void)
{
    memset_s(&g_powerup_res, sizeof(g_powerup_res), 0, sizeof(g_powerup_res));
    conn_dmi_msg_regiser(CONN_DMI_MSG_POWERUP, NULL, powerup_process);
    conn_dmi_msg_regiser(CONN_DMI_MSG_SHUTDOWN, shutdown_process, NULL);
    conn_dmi_msg_regiser(CONN_DMI_MSG_OPEN, dpa_open_top, dpa_open_bottom);
    conn_dmi_msg_regiser(CONN_DMI_MSG_CLOSE, NULL, dpa_close);
    conn_dmi_msg_regiser(CONN_DMI_MSG_WIFI_READY, NULL, wifi_ready_process);

    board_cosole_regist();
    dpe_dmi_register();
}
