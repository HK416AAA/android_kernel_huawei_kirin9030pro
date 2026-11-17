/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:pm functional module
 * Author: platform drivers
 */

/* 头文件包含 */
#include "board.h"
#include "securec.h"
#include "plat_ipc.h"
#include "board_pm.h"
#include "plat_pm.h"
#include "plat_pm_mcu.h"

#ifdef _PRE_PLAT_FEATURE_IPC
#pragma pack(1)
typedef struct mcu_cust_cfg {
    uint32_t pm_switch_exist : 1;           // pm_switch配置项存在
    uint32_t pm_switch_value : 31;          // pm_switch配置项值
    uint32_t pm_sleep_period_exist : 1;     // sleep_period配置项存在
    uint32_t pm_sleep_period_value : 31;    // sleep_period配置值
    uint32_t dfr_switch_exist : 1;          // dfr_switch配置项存在
    uint32_t dfr_switch_value : 31;         // dfr_switch配置值
} mcu_cust_cfg_t;

typedef struct mcu_cust_cfg_cmd {
    plat_ipc_hdr_t ipc_hdr;
    mcu_cust_cfg_t mcu_cust;
} mcu_cust_cfg_cmd_t;
#pragma pack()

typedef enum PM_NOTIFY_LEVEL {
    PM_NOTIFY_LEVEL_ERR = 0,
    PM_NOTIFY_LEVEL_INFO = 1,

    PM_NOTIFY_LEVEL_BUTT
} pm_notify_level_t;

typedef enum PM_STATUS_NOTIFY {
    PM_NOTIFY_SLEEP_SUCC = 0,
    PM_NOTIFY_SLEEP_FAIL = 1,
    PM_NOTIFY_WAKEUP_DEV_SUCC = 2,
    PM_NOTIFY_WAKEUP_DEV_FAIL = 3,
    PM_NOTIFY_SLEEP_CONTINUE_FAIL = 4,

    PM_NOTIFY_EVENT_BUTT
} pm_notify_event_t;

mcu_cust_cfg_t g_mcu_cust_cfg = { 0 };

int32_t plat_ipc_send_mcu_cust(void)
{
    mcu_cust_cfg_cmd_t cmd;

    cmd.ipc_hdr.msg_code = BFGN_OP_CODE_MCU_CUST;
    cmd.ipc_hdr.msg_len = sizeof(mcu_cust_cfg_cmd_t);
    cmd.mcu_cust = g_mcu_cust_cfg;

    return plat_ipc_send_cmd(CMD_CONNECT_AP_TO_MCU, (const uint8_t *)&cmd, sizeof(mcu_cust_cfg_cmd_t));
}

STATIC void get_pm_mcu_pm_switch_ini(void)
{
    int32_t ret;
    int32_t cfg_value = OAL_TRUE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, HW_MCU_PM_SWITCH, &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("%s not defined\n", HW_MCU_PM_SWITCH);
        g_mcu_cust_cfg.pm_switch_exist = OAL_FALSE;
        return;
    }
    g_mcu_cust_cfg.pm_switch_exist = OAL_TRUE;
    g_mcu_cust_cfg.pm_switch_value = (cfg_value == 0) ? OAL_FALSE : OAL_TRUE;
    ps_print_info("get from ini, %s=%d\n", HW_MCU_PM_SWITCH, g_mcu_cust_cfg.pm_switch_value);
}

STATIC void get_pm_sleep_period_ini(void)
{
    int32_t ret;
    int32_t cfg_value = OAL_TRUE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, HW_MCU_SLEEP_PERIOD, &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("%s not defined\n", HW_MCU_SLEEP_PERIOD);
        g_mcu_cust_cfg.pm_sleep_period_exist = OAL_FALSE;
        return;
    }
    g_mcu_cust_cfg.pm_sleep_period_exist = OAL_TRUE;
    g_mcu_cust_cfg.pm_sleep_period_value = (uint32_t)cfg_value;
    ps_print_info("get from ini, %s=%d\n", HW_MCU_SLEEP_PERIOD, g_mcu_cust_cfg.pm_sleep_period_value);
}

void pm_status_notify_msg_process(uint8_t *msg_buffer, uint16_t len)
{
    mcu_pm_status_notify_t* pm_status;
    if (len < sizeof(mcu_pm_status_notify_t)) {
        ps_print_err("Invalid message length\n");
        return;
    }
    pm_status = (mcu_pm_status_notify_t*)msg_buffer;
    ps_print_info("mcu pm_status_event level[%d]:event %d\n", pm_status->level, pm_status->event);
    if (pm_status->event == PM_NOTIFY_WAKEUP_DEV_FAIL) {
        declare_dft_trace_key_info("mcu_wakeup_dev fail", OAL_DFT_TRACE_EXCEP);
    }
    return;
}

STATIC void get_mcu_dfr_switch_ini(void)
{
    int32_t ret;
    int32_t cfg_value = OAL_TRUE;

    /* 获取ini的配置值 */
    ret = get_cust_conf_int32(INI_MODU_PLAT, HW_MCU_DFR_SWITCH, &cfg_value);
    if (ret == INI_FAILED) {
        ps_print_info("%s not defined\n", HW_MCU_DFR_SWITCH);
        g_mcu_cust_cfg.dfr_switch_exist = OAL_FALSE;
        return;
    }
    g_mcu_cust_cfg.dfr_switch_exist = OAL_TRUE;
    g_mcu_cust_cfg.dfr_switch_value = (cfg_value == 0) ? OAL_FALSE : OAL_TRUE;
    ps_print_info("get from ini, %s=%d\n", HW_MCU_DFR_SWITCH, g_mcu_cust_cfg.dfr_switch_value);
}
#endif

void plat_pm_mcu_init(void)
{
#ifdef _PRE_PLAT_FEATURE_IPC
    get_pm_mcu_pm_switch_ini();
    get_pm_sleep_period_ini();
    get_mcu_dfr_switch_ini();
    plat_ipc_send_mcu_cust();
#endif
}
