/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Header file of the external public interface of the OAM Wi-Fi
 * Author: dpa drivers
 */

#ifndef OAM_LOGGER_H
#define OAM_LOGGER_H

#include "oal_types.h"
#include "bsp_record.h"
#include "oam_wdk.h"

#define PRINT_OAM_BSP_LOG

#define KERN_ERR        "[DPA_MPXX][E]"
#define KERN_WARNING    "[DPA_MPXX][W]"
#define KERN_INFO       "[DPA_MPXX][I]"

#define oam_wifi_log_para_press(vap_id, feature_id, fileid, lev) \
    ((((fileid) & 0xFFFF) | (((feature_id) & 0xFF) << 16) | (((vap_id) & 0xF) << 24) | (((lev) & 0xF) << 28)))

#if defined(PRINT_OAM_BSP_LOG)
#define oam_info_log0(vap_id, feature_id, fmt) do {                                                     \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__);                                                                            \
} while (0)

#define oam_info_log1(vap_id, feature_id, fmt, p1) do {                                                 \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1));                                                             \
} while (0)

#define oam_info_log2(vap_id, feature_id, fmt, p1, p2) do {                                             \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2));                                              \
} while (0)

#define oam_info_log3(vap_id, feature_id, fmt, p1, p2, p3) do {                                         \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3));                               \
} while (0)

#define oam_info_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) do {                                     \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4));                \
} while (0)

#define oam_warning_log0(vap_id, feature_id, fmt) do {                                                      \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING),  \
        (uint16_t)__LINE__);                                                                                \
    bsp_dpa_record(KERN_WARNING "" fmt "" NEWLINE);                                                              \
} while (0)

#define oam_warning_log1(vap_id, feature_id, fmt, p1) do {                                                  \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING),  \
        (uint16_t)__LINE__, (int32_t)(p1));                                                                 \
    bsp_dpa_record(KERN_WARNING "" fmt "" NEWLINE, p1);                                                          \
} while (0)

#define oam_warning_log2(vap_id, feature_id, fmt, p1, p2) do {                                              \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING),  \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2));                                                  \
    bsp_dpa_record(KERN_WARNING "" fmt "" NEWLINE, p1, p2);                                                      \
} while (0)

#define oam_warning_log3(vap_id, feature_id, fmt, p1, p2, p3) do {                                          \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING),  \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3));                                   \
    bsp_dpa_record(KERN_WARNING "" fmt "" NEWLINE, p1, p2, p3);                                                  \
} while (0)

#define oam_warning_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) do {                                      \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING),  \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4));                    \
    bsp_dpa_record(KERN_WARNING "" fmt "" NEWLINE, p1, p2, p3, p4);                                              \
} while (0)

#define oam_error_log0(vap_id, feature_id, fmt) do {                                                        \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR),    \
        (uint16_t)__LINE__);                                                                                \
    bsp_dpa_record(KERN_ERR "" fmt "" NEWLINE);                                                                  \
} while (0)

#define oam_error_log1(vap_id, feature_id, fmt, p1) do {                                                    \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR),    \
        (uint16_t)__LINE__, (int32_t)(p1));                                                                 \
    bsp_dpa_record(KERN_ERR "" fmt "" NEWLINE, p1);                                                              \
} while (0)

#define oam_error_log2(vap_id, feature_id, fmt, p1, p2) do {                                                \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR),    \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2));                                                  \
    bsp_dpa_record(KERN_ERR "" fmt "" NEWLINE, p1, p2);                                                          \
} while (0)

#define oam_error_log3(vap_id, feature_id, fmt, p1, p2, p3) do {                                            \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR),    \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3));                                   \
    bsp_dpa_record(KERN_ERR "" fmt "" NEWLINE, p1, p2, p3);                                                      \
} while (0)

#define oam_error_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) do {                                        \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR),    \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4));                    \
    bsp_dpa_record(KERN_ERR "" fmt "" NEWLINE, p1, p2, p3, p4);                                                  \
} while (0)
#elif defined(PRINT_OAM_LOG)
#define oam_info_log0(vap_id, feature_id, fmt) \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__)

#define oam_info_log1(vap_id, feature_id, fmt, p1) \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1))

#define oam_info_log2(vap_id, feature_id, fmt, p1, p2) \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2))

#define oam_info_log3(vap_id, feature_id, fmt, p1, p2, p3) \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3))

#define oam_info_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_INFO), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4))

#define oam_warning_log0(vap_id, feature_id, fmt) \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING), \
        (uint16_t)__LINE__)

#define oam_warning_log1(vap_id, feature_id, fmt, p1) \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING), \
        (uint16_t)__LINE__, (int32_t)(p1))

#define oam_warning_log2(vap_id, feature_id, fmt, p1, p2) \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2))

#define oam_warning_log3(vap_id, feature_id, fmt, p1, p2, p3) \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3))

#define oam_warning_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_WARNING), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4))

#define oam_error_log0(vap_id, feature_id, fmt) \
    oam_log_print0_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR), \
        (uint16_t)__LINE__)

#define oam_error_log1(vap_id, feature_id, fmt, p1) \
    oam_log_print1_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR), \
        (uint16_t)__LINE__, (int32_t)(p1))

#define oam_error_log2(vap_id, feature_id, fmt, p1, p2) \
    oam_log_print2_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2))

#define oam_error_log3(vap_id, feature_id, fmt, p1, p2, p3) \
    oam_log_print3_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3))

#define oam_error_log4(vap_id, feature_id, fmt, p1, p2, p3, p4) \
    oam_log_print4_press(oam_wifi_log_para_press(vap_id, feature_id, THIS_FILE_ID, OAM_LOG_LEVEL_ERROR), \
        (uint16_t)__LINE__, (int32_t)(p1), (int32_t)(p2), (int32_t)(p3), (int32_t)(p4))
#else
#define oam_info_log0(vap_id, feature_id, fmt)
#define oam_info_log1(vap_id, feature_id, fmt, p1)
#define oam_info_log2(vap_id, feature_id, fmt, p1, p2)
#define oam_info_log3(vap_id, feature_id, fmt, p1, p2, p3)
#define oam_info_log4(vap_id, feature_id, fmt, p1, p2, p3, p4)
#define oam_warning_log0(vap_id, feature_id, fmt)
#define oam_warning_log1(vap_id, feature_id, fmt, p1)
#define oam_warning_log2(vap_id, feature_id, fmt, p1, p2)
#define oam_warning_log3(vap_id, feature_id, fmt, p1, p2, p3)
#define oam_warning_log4(vap_id, feature_id, fmt, p1, p2, p3, p4)
#define oam_error_log0(vap_id, feature_id, fmt)
#define oam_error_log1(vap_id, feature_id, fmt, p1)
#define oam_error_log2(vap_id, feature_id, fmt, p1, p2)
#define oam_error_log3(vap_id, feature_id, fmt, p1, p2, p3)
#define oam_error_log4(vap_id, feature_id, fmt, p1, p2, p3, p4)
#endif

/* 特性宏的缩写见gst_oam_feature_list */
typedef enum {
    OAM_SF_DPA = 109, /* OAM_SF_DPA for dpe */
} oam_feature_enum;

/* 日志级别 */
typedef enum {
    OAM_LOG_LEVEL_ERROR = 1, /* ERROR级别打印 */
    OAM_LOG_LEVEL_WARNING,   /* WARNING级别打印 */
    OAM_LOG_LEVEL_INFO,      /* INFO级别打印 */

    OAM_LOG_LEVEL_BUTT
} oam_log_level_enum;

uint32_t oam_log_print0_press(uint32_t para_press, uint16_t line_num);
uint32_t oam_log_print1_press(uint32_t para_press, uint16_t line_num, int32_t param1);
uint32_t oam_log_print2_press(uint32_t para_press, uint16_t line_num, int32_t param1, int32_t param2);
uint32_t oam_log_print3_press(uint32_t para_press, uint16_t line_num,
                              int32_t param1, int32_t param2, int32_t param3);
uint32_t oam_log_print4_press(uint32_t para_press, uint16_t line_num,
                              int32_t param1, int32_t param2, int32_t param3, int32_t param4);

#endif /* end of oam_logger.h */
