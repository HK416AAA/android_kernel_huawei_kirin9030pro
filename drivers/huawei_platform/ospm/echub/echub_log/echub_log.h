/*
 * echub_log.h
 *
 * echub log interface
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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

#ifndef _ECHUB_LOG
#define _ECHUB_LOG

/* config for KLV */
#define ECLOG_DUMP_SIZE            256
#define ECLOG_DUMP_CMD             0xdb01
#define ECLOG_DUMP_START_ADDR      0x2000
#define ECLOG_DUMP_TIMES           64
#define ECLOG_CMD_TYPE             1
#define ECLOG_OUTPUT_SIZE          (128 * 1024)

/* config for Harden and later  product */
#define ECLOG_QUERY_DATA_SIZE      253
#define ECLOG_SHUTDOWN_DATA_SIZE   128
#define ECLOG_KEYBOARD_SIZE        1024
#define ECLOG_QUERY_CMD            0x02b7
#define ECLOG_QUERY_SHUTDOWN_CODE  0x02b8
#define ECLOG_LOG_TYPE_SHUTDOWN    0x00
#define ECLOG_LOG_TYPE_TRACE       0x02
#define ECLOG_LOG_TYPE_FP          0x03
#define ECLOG_LOG_TYPE_CRITICAL    0x05
#define ECLOG_LOG_TYPE_FLASH       0x06
#define ECLOG_LOG_TYPE_PD          0x07
#define ECLOG_LOG_TYPE_KBD         0x0A

#define EC_SHUTDOWN_DUMP_TIMES     8
#define EC_FP_LOG_DUMP_TIMES       48
#define EC_CRITICAL_DUMP_TIMES     32
#define EC_KBD_DUMP_TIMES          4
#define EC_KBD_FILENAME_LEN	       9
#define EC_KBD_FILE_MAX_SIZE       100

#define ECLOG_ONE_LINE_BYTES       16

#define EC_MAIN_VERSION_CMD        0x0681
#define EC_SUB_VERSION_CMD         0x0691
#define EC_VERSION_SIZE            0x05
#define EC_VERSION_OUTPUT_SIZE     0x0E
#define EC_ERRORCODE_SIZE          0x04

#define upper_byte(n) ((u8)(((u16)(n)) >> 8))
#define lower_byte(n) ((u8)(u16)(n))

#ifndef PATH_MAX_LEN
#define PATH_MAX_LEN 128
#endif
struct ec_log_file {
	u8 log_type;
	char *log_filename;
};

#define EC_LOG_ROOT_DIR "/data/log/eclog/"
struct ec_log_file g_eclog_file[] = {
    {ECLOG_LOG_TYPE_SHUTDOWN, "shutdowncause"},
    {ECLOG_LOG_TYPE_TRACE, "tracelog"},
    {ECLOG_LOG_TYPE_FLASH, "flashlog"},
};

enum EcErrorCode {
    /* PWR BTN long press shutdown */
    ABNORMAL_SHUTDOWN_CAUSE_4_S_PWRBTN_OVERWRITE                = 0x06,
    ABNORMAL_SHUTDOWN_CAUSE_10_S_PWRBTN_OVERWRITE               = 0x07,
    /* poweron seq timeout */
    ABNORMAL_SHUTDOWN_CAUSE_SX_TO_S0_SOFT_WDT                   = 0x09,
    /* OTP shutdown */
    ABNORMAL_SHUTDOWN_CAUSE_CPU_DTS                             = 0x30,
    ABNORMAL_SHUTDOWN_CAUSE_SOC_NTC                             = 0x31,
    ABNORMAL_SHUTDOWN_CAUSE_SOC_NTC_2                           = 0x32,
    ABNORMAL_SHUTDOWN_CAUSE_DGPU_DTS                            = 0x33,
    ABNORMAL_SHUTDOWN_CAUSE_DGPU_NTC                            = 0x34,
    ABNORMAL_SHUTDOWN_CAUSE_DDR_NTC                             = 0x35,
    ABNORMAL_SHUTDOWN_CAUSE_AMB_NTC                             = 0x37,
    ABNORMAL_SHUTDOWN_CAUSE_SSD_NTC                             = 0x38,
    ABNORMAL_SHUTDOWN_CAUSE_BAT_NTC                             = 0x39,
    ABNORMAL_SHUTDOWN_CAUSE_CHARGER_NTC                         = 0x3A,
    ABNORMAL_SHUTDOWN_CAUSE_TYPEC_NTC                           = 0x3B,
    ABNORMAL_SHUTDOWN_CAUSE_TYPEC_CN_2_NTC                      = 0x3C,
    ABNORMAL_SHUTDOWN_CAUSE_CPU_VRM_NTC                         = 0x3D,
    ABNORMAL_SHUTDOWN_CAUSE_OTP_TEMP                            = 0x3E,
    ABNORMAL_SHUTDOWN_CAUSE_CAMERA_SENSOR_TEMP                  = 0x3F,
    ABNORMAL_SHUTDOWN_CAUSE_SSD_TEMP_1                          = 0x40,
    /* abnormal shutdown */
    ABNORMAL_SHUTDOWN_CAUSE_EC_ABNORMAL_POWER_OFF               = 0xEE,
    /* abnormal reset */
    ABNORMAL_SHUTDOWN_CAUSE_EC_INTERNAL_WDT                     = 0xF0,
    /* battery over discharge shutdown */
    ABNORMAL_SHUTDOWN_CAUSE_EC_BAT_PROTECT_OVER_DISCHARGE       = 0xF1
};

struct eclog_event_info {
    int errcode;
	char *eventname;
};

struct eclog_event_info g_eclog_event[] = {
    {ABNORMAL_SHUTDOWN_CAUSE_4_S_PWRBTN_OVERWRITE, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_10_S_PWRBTN_OVERWRITE, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_SX_TO_S0_SOFT_WDT, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_CPU_DTS, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_SOC_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_SOC_NTC_2, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_DGPU_DTS, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_DGPU_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_DDR_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_AMB_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_SSD_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_BAT_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_CHARGER_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_TYPEC_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_TYPEC_CN_2_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_CPU_VRM_NTC, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_OTP_TEMP, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_CAMERA_SENSOR_TEMP, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_SSD_TEMP_1, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_EC_ABNORMAL_POWER_OFF, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_EC_INTERNAL_WDT, "ABNORMAL_SHUTDOWN"},
    {ABNORMAL_SHUTDOWN_CAUSE_EC_BAT_PROTECT_OVER_DISCHARGE, "ABNORMAL_SHUTDOWN"},
};

#endif