/* SPDX-License-Identifier: GPL-2.0 */
/*
 * serial_gauge_power_saving.h
 *
 * self algorithm power saving header
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#ifndef _SERIAL_GAUGE_POWER_SAVING_H_
#define _SERIAL_GAUGE_POWER_SAVING_H_

#include <linux/rtc.h>

#include "serial_gauge_base.h"

extern struct rtc_wkalrm poweroff_rtc_alarm;

#define SERIAL_GAUGE_FW_SINGLE_BIT_LEN			 8
#define SERIAL_GAUGE_FW_SINGLE_BIT_MASK			 0xFF

/* reg address and sub cmd */
#define SERIAL_GAUGE_FW_REG						 0x44
#define SERIAL_GAUGE_OP_STAT_H_REG				 0x88
#define SERIAL_GAUGE_GAUGE_STAT_H_REG			 0x8C
#define SERIAL_GAUGE_POWER_SAVING_STATUS_REG     0x93

#define SERIAL_GAUGE_SUB_CMD_BOOT_FROM_INTELL_POWER  0x00A3
#define SERIAL_GAUGE_FW_SUB_CMD_READ_RTC		 0x9000
#define SERIAL_GAUGE_FW_SUB_CMD_WRITE_RTC		 0x9001
#define SERIAL_GAUGE_FW_SUB_CMD_SHUTDOWN_FLAG	 0x0012
#define SERIAL_GAUGE_SUB_CMD_SSS_SET         	 0x00A0
#define SERIAL_GAUGE_SUB_CMD_USER_DATA         	 0x0103

/* sub cmd index */
#define SERIAL_GAUGE_FW_SUB_CMD_INDEX			 1
#define SERIAL_GAUGE_FW_RTC_DATA_INDEX			 3
#define SERIAL_GAUGE_FW_WRITE_CMD_LEN			 2
#define SERIAL_GAUGE_FW_READ_RTC_1_LEN			 3
#define SERIAL_GAUGE_FW_READ_RTC_2_LEN			 8
#define SERIAL_GAUGE_FW_WRITE_RTC_LEN			 8
#define SERIAL_GAUGE_UPDATE_SHUTDOWN_FLAG_LEN    7
#define SERIAL_GAUGE_OP_STAT_H_SHUTDOWN_FLAG_BIT 15
#define SERIAL_GAUGE_SUB_CMD_TYPE_LEN            4
#define SERIAL_GAUGE_GAUGE_STAT_H_SSS_BIT        0
#define SERIAL_GAUGE_WRITE_BUF_LEN                3
#define SERIAL_GAUGE_READ_BUF_LEN                 5
#define SERIAL_GAUGE_GAUGE_STAT_H_SSS_MASK       0xF
#define SERIAL_GAUGE_GAUGE_STAT_H_SSS_BIT        0

/* rtc */
#define SERIAL_GAUGE_FW_READ_RTC_FORMAT_HEX		 0x00
#define SERIAL_GAUGE_FW_READ_RTC_FORMAT_BCD		 0x01
#define SERIAL_GAUGE_CUR_YEAR					 2000
#define SERIAL_GAUGE_BASE_YEAR					 1900

/* shutdown flag */
#define POWER_SAVING_DELAY_TIME_5MIN (3600 * 24 * 25)
#define POWER_SAVING_DELAY_TIME_7DAY (3600 * 24 * 7)

typedef enum {
    SOC_SYS_STATUS_BEGIN = 0,
    SOC_SYS_STATUS_S0 = SOC_SYS_STATUS_BEGIN,
    SOC_SYS_STATUS_S4,
    SOC_SYS_STATUS_S5,
    SOC_SYS_STATUS_END
} SocSysStatus;

/* power saving */
void serial_gauge_power_saving_restore(void);
void serial_gauge_power_saving_shutdown(void);
void serial_gauge_power_saving_free_resource(void);

/* self use func */
int set_coul_soc_system_status(struct serial_gauge_device *di, u8 status);

#endif /* _SERIAL_GAUGE_POWER_SAVING_H_ */