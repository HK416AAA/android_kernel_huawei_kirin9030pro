/*
 * pahaptic_dmd.h
 *
 * common logic for haptic dmd
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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
#ifndef _PAHAPTIC_DMD_H_
#define _PAHAPTIC_DMD_H_

#include "pa_haptic.h"
#include <linux/workqueue.h>

// vibrator dmd
#define DSM_VIBRATOR_ABNORMAL_ERROR         1
#define DSM_VIBRATOR_OCP_ERROR              2
#define DSM_VIBRATOR_UVP_ERROR              3
#define DSM_VIBRATOR_POWER_DOWN             4
#define DSM_VIBRATOR_OTP_ERROR              5
#define DSM_VIBRATOR_F0_ERROR               6
#define I2C_ERR_CNT_MAX                     500
#define DMD_REPORT_MAX_CNT                  20
#define HAPTIC_EXCEPTION_EVENT_ID           916200102

typedef enum {
	HAPTIC_OVERHEAT = 0,
	HAPTIC_V_EXCEED,
	HAPTIC_BROKEN_CIRCUIT,
	HAPTIC_SHORT_CIRCUIT,
	HAPTIC_DSP_SOFTWARE_ERR,
} haptic_err_type_t;

typedef enum {
	LEVEL_INFO = 0,
	LEVEL_WARNING,
	LEVEL_ERROR,
	LEVEL_FATAL,
} haptic_err_level_t;

struct error_info {
	haptic_err_type_t error_code;
	const char *error_message;
	haptic_err_level_t error_level;
};

enum haptic_num{
	HAPTIC_0,
	HAPTIC_1,
	HAPTIC_MAX_NUM
};

typedef struct {
    uint16_t msg_id;
    uint16_t reserved;
    uint32_t pa_vendor_id[HAPTIC_MAX_NUM];
    uint32_t motor_vendor_id[HAPTIC_MAX_NUM];
    int32_t i_scale[HAPTIC_MAX_NUM];
    int32_t v_scale[HAPTIC_MAX_NUM];
    int32_t re_scale[HAPTIC_MAX_NUM];
    uint32_t cali_f0[HAPTIC_MAX_NUM];
    uint32_t cali_r0[HAPTIC_MAX_NUM];
    uint32_t tracking_f0[HAPTIC_MAX_NUM];
    int32_t output_rms[HAPTIC_MAX_NUM];
    int32_t output_valid_cnt[HAPTIC_MAX_NUM];
    int32_t output_total_cnt[HAPTIC_MAX_NUM];
    int32_t i_rms[HAPTIC_MAX_NUM];
    int32_t i_valid_cnt[HAPTIC_MAX_NUM];
    int32_t i_total_cnt[HAPTIC_MAX_NUM];
    int32_t v_rms[HAPTIC_MAX_NUM];
    int32_t v_valid_cnt[HAPTIC_MAX_NUM];
    int32_t v_total_cnt[HAPTIC_MAX_NUM];
    int32_t i_rms_while_v_valid[HAPTIC_MAX_NUM];
    int32_t r_avg[HAPTIC_MAX_NUM];
    int32_t v_exceed_cnt[HAPTIC_MAX_NUM];
    int32_t overheat_cnt[HAPTIC_MAX_NUM];
    int32_t broken_cnt[HAPTIC_MAX_NUM];
    int32_t short_cnt[HAPTIC_MAX_NUM];
    uint64_t dsp_err_code;
} haptic_bigdata; // xxxx[1] is not used for single haptic

struct haptic_bigdata_work_t{
    uint32_t err_flag;
    unsigned long last_report;
    struct work_struct bigdata_work;
    haptic_bigdata bigdata;
};

void pa_haptic_dmd_work(uint8_t num);
void pa_haptic_dsm_register(void);
void i2c_err_dmd(struct pa_paptic_t *haptic_dev);
void haptic_bigdata_report(struct work_struct *work);

#endif
