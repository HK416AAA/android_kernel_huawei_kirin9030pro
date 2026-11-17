/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 *
 * Description:plat_pm_mcu.c header file
 * Author: platform drivers
 */

#ifndef PLAT_PM_MCU_H
#define PLAT_PM_MCU_H

#define HW_MCU_PM_SWITCH      "mcu_pm_switch"          // ini中低功耗开关配置项名称
#define HW_MCU_SLEEP_PERIOD   "mcu_sleep_period"      // ini中睡眠定时器周期配置项名称
#define HW_MCU_DFR_SWITCH     "plat_dfr_enable"       // ini中DFR开关配置项名称

/*
 * Prototype    : plat_pm_mcu_init
 * Description  : mcu low power init, read ini cfg and ipc send to mcu
 */
void plat_pm_mcu_init(void);
void pm_status_notify_msg_process(uint8_t *msg_buffer, uint16_t len);
int32_t plat_ipc_send_mcu_cust(void);

#endif