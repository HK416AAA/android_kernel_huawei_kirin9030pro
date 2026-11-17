/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for oam
 * Author: plat drivers
 */

#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bfgx_dev.h"
#include "bfgx_data_parse.h"
#include "plat_main.h"
#include "plat_uart.h"
#include "plat_debug.h"
#include "plat_oam.h"

#if defined(IDE_CONF_LOG_LEVEL) && defined(BETA_VERSIOIN) && (IDE_CONF_LOG_LEVEL == BETA_VERSIOIN)
#define OAM_BUFFER_SIZE      8192
#else
#define OAM_BUFFER_SIZE      2048
#endif
#define OAM_MUTEX_TIMEOUT       osWaitForever
#define OAM_SAVE_INTERVAL       2000000000

#define TIME_BASE_YEAR          1900
#define TIME_USEC_PER_MSEC      1000
#define TIME_USEC_TO_MSEC(x)    ((x) / TIME_USEC_PER_MSEC)

#define TIME_PKT_HEAD_LEN     18
#define TIME_PKT_LOW_LEN_IDX  2
#define TIME_PKT_HIGH_LEN_IDX 3
#define TIME_PKT_TIME_IDX     4

typedef struct {
    uint32_t    used_size;
    osMutexId_t mutex_id;
    uint64_t    last_send_time;
} oam_ctrl_t;

plat_oam_save_handle g_plat_oam_save_handle = NULL;
static oam_ctrl_t g_oam_ctrl = {0};
static uint8_t g_oam_msg_buffer[OAM_BUFFER_SIZE] = {0};
uint8_t g_oam_save_log_flag = OAM_SAVE_LOG_STOP;

typedef struct oam_sys_time {
    uint16_t tm_year; /* Year */
    uint16_t tm_mon;  /* Month */
    uint16_t tm_day;  /* Day */
    uint16_t tm_hour; /* Hour */
    uint16_t tm_min;  /* Minute */
    uint16_t tm_sec;  /* Second */
    uint16_t tm_msec; /* Ms */
} oam_sys_time_t;

void hal_get_timestamp(UINT64 *timestamp);

static void oam_get_time(uint8_t *oam_tm_buf, uint32_t size)
{
    time_t tmp_time = time(NULL);
    struct tm *tmp_tm = localtime(&tmp_time);
    struct timeval tv;
    uint32_t offset = 0;
    gettimeofday(&tv, NULL);

    (void)size;
    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_year + TIME_BASE_YEAR));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_year + TIME_BASE_YEAR));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_mon + 1));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_mon + 1));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_mday));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_mday));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_hour));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_hour));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_min));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_min));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)(tmp_tm->tm_sec));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)(tmp_tm->tm_sec));

    oam_tm_buf[offset++] = len_low_byte((uint16_t)TIME_USEC_TO_MSEC(tv.tv_usec));
    oam_tm_buf[offset++] = len_high_byte((uint16_t)TIME_USEC_TO_MSEC(tv.tv_usec));
}

static void oam_save_data(uint8_t *msg_buffer, uint32_t msg_len)
{
    uint32_t ret = 0;
    if (g_plat_oam_save_handle != NULL) {
        ret = g_plat_oam_save_handle(0, msg_buffer, msg_len);
        if (ret != 0) {
            PRINT_ERR("oam_save_data save data failed!, ret = 0x%x", ret);
        }
    } else {
        PRINT_ERR("oam_save_data save_handle is NULL!");
    }
}

static void oam_save_data_form_buffer(void)
{
    uint64_t current_tick;

    hal_get_timestamp(&current_tick);
    if ((current_tick - g_oam_ctrl.last_send_time >= OAM_SAVE_INTERVAL) && g_oam_ctrl.used_size != 0) {
        oam_save_data(g_oam_msg_buffer, g_oam_ctrl.used_size);
        g_oam_ctrl.used_size = 0;
        g_oam_ctrl.last_send_time = current_tick;
    }
}

static void oam_write_to_buffer(uint8_t uart, const uint8_t *data, uint16_t data_len)
{
    uint16_t pkt_len = data_len + TIME_PKT_HEAD_LEN; // 外部已确保不会溢出

    oam_save_data_form_buffer();

    if ((g_oam_ctrl.used_size + pkt_len > OAM_BUFFER_SIZE)) {
        return;
    }

    uint8_t *log_buf = &g_oam_msg_buffer[g_oam_ctrl.used_size];

    // 填写时间戳前缀
    log_buf[0] = 0xaa;
    log_buf[1] = 0x00;
    log_buf[TIME_PKT_LOW_LEN_IDX]  = len_low_byte(pkt_len);
    log_buf[TIME_PKT_HIGH_LEN_IDX] = len_high_byte(pkt_len);
    oam_get_time(&log_buf[TIME_PKT_TIME_IDX], sizeof(oam_sys_time_t));
    // 日志复制到log_buf
    (void)memcpy_s(&log_buf[TIME_PKT_HEAD_LEN], data_len, data, data_len);
    g_oam_ctrl.used_size += pkt_len;
    oam_save_data_form_buffer();
}

static void oam_msg_data_process(uint8_t uart, const char *data, uint16_t data_len)
{
    osMutexAcquire(g_oam_ctrl.mutex_id, OAM_MUTEX_TIMEOUT);

    if (g_oam_save_log_flag == OAM_SAVE_LOG_START) {
        oam_write_to_buffer(uart, (const uint8_t *)data, data_len);
    }

    osMutexRelease(g_oam_ctrl.mutex_id);
}

uint32_t plat_oam_msg_init(void)
{
    g_oam_ctrl.mutex_id = osMutexNew(NULL);
    if (g_oam_ctrl.mutex_id == NULL) {
        PRINT_ERR("plat_oam_msg_init create mutex failed.");
        return BFGN_FAIL;
    }

#if (IDE_CONF_LOG_LEVEL == RELEASE_VERSION)
    g_oam_save_log_flag = OAM_SAVE_LOG_STOP;
#else
    g_oam_save_log_flag = OAM_SAVE_LOG_START;
#endif

    bfgn_register_uart_data_handle(OML_MSG, oam_msg_data_process);

    return BFGN_SUCC;
}

void plat_oam_set_save_log(uint8_t state)
{
#if (IDE_CONF_LOG_LEVEL == RELEASE_VERSION)
    if (state == OAM_SAVE_LOG_START) {
        g_oam_save_log_flag = OAM_SAVE_LOG_START;
    } else {
        g_oam_save_log_flag = OAM_SAVE_LOG_STOP;
    }
#endif
}