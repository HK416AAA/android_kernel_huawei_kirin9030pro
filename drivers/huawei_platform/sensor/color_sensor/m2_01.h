/*
 * si_m201.h
 *
 * code for SI m201 sensor
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
#ifndef __M201_H__
#define __M201_H__
#include "color_sensor.h"

/* M201 Register map */
#define M201_I2C_ADDR 0x5B
/* Register definitions */
/* M201 Register map */
#define M201_LOW_POWER_CTRL 0x02
#define M201_RST_CTRL 0x05
#define M201_INT_CTRL 0x06
#define M201_ALS_ENABLE 0x50
#define M201_ALS_CTRL0 0x51
#define M201_ALS_CTRL1 0x52
#define M201_ALS_INT_EN 0x53
#define M201_ALS_DATA_LOW_TH_H 0x54
#define M201_ALS_DATA_LOW_TH_L 0x55
#define M201_ALS_DATA_HIGH_TH_H 0x56
#define M201_ALS_DATA_HIGH_TH_L 0x57
#define M201_ALS_INTE_STEP_TIME_H 0x58
#define M201_ALS_INTE_STEP_TIME_M 0x59
#define M201_ALS_INTE_STEP_TIME_L 0x5A
#define M201_ALS_PERIOD_STEP 0x5B
#define M201_ALS_PERIOD_TIME 0x5C
#define M201_RST_NUM 0x5D
#define M201_ALS_AZ_AUTO_NUM 0x5E
#define M201_ALS_AZ_EN 0x5F
#define M201_RESERVE 0x60
#define M201_ALS_GAIN 0x62
#define M201_FLK_GAIN 0x63
#define M201_PD_SEL0 0x6F
#define M201_PD_SEL1 0x70
#define M201_FLK_CTRL 0x71
#define M201_FLK_INTE_TIME_H 0x73
#define M201_FLK_INTE_TIME_M 0x74
#define M201_FLK_INTE_TIME_L 0x75
#define M201_ALS_INT_STATUS 0x81
#define M201_DATA_VALID 0x84
#define M201_ALS_DATA 0x90
#define M201_ALS_DATA_H 0x94
#define M201_ALS_DATA_L 0x95
#define M201_WB_DATA_H 0x96
#define M201_WB_DATA_L 0x97
#define M201_ALS_FDATA 0x9F
#define M201_FIFO_STATUS 0xA0
#define M201_FIFO_LVL 0xA1
#define M201_FIFO_THRESH 0xA2
#define M201_FMODE0 0xA3
#define M201_FMODE1 0xA4
#define M201_SYNC_CTRL 0xE0
#define M201_SYNCDLY_CNT_H 0xE2
#define M201_SYNCDLY_CNT_L 0xE3
#define M201_SYNCTRIG_CNT 0xE4
#define M201_SYNCWDT_CNT_H 0xE8
#define M201_SYNCWDT_CNT_L 0xE9
#define M201_SYNCFERQ_CHG_THRESH_H 0xEA
#define M201_SYNCFERQ_CHG_THRESH_L 0xEB
#define M201_SYNCPERIOD_H 0xEC
#define M201_SYNCPERIOD_M 0xED
#define M201_SYNCPERIOD_L 0xEE
// m201_RST_CTRL_REG @0x05
#define OSC_EN (0x01 << 1)
#define SOFT_RST_N (0x01 << 0)

// m201_INT_CTRL_REG @0x06
#define INT_EN (0x01 << 2)
#define INT_POLARITY (0x01 << 1)
#define INT_CLEAR_MODE (0x01 << 0)

// m201_ALS_ENABLE   @0x50
#define ALS_FLK_EN (0x01 << 5)
#define ALS_WB_EN (0x01 << 4)
#define AL0_EN (0x01 << 3)
#define ALS_EN (0x01 << 0)
#define AL_EN_ALL (ALS_EN | AL0_EN | ALS_WB_EN)
// m201_ALS_CTRL0  @0x51
#define ALS_PERIOD_EN (0x01 << 0)

// m201_ALS_CTRL1  @0x52
#define ALS_PERSIST_NUM (0x0F << 4)
#define ALS_TRIGGER_MODE (0x01 << 0)

// m201_ALS_INT_EN @0x53
#define ALS_CH_INT_SEL (0x01 << 6)
#define ALS_ERR_INT_EN (0x01 << 3)
#define ALS_SAT_ANA_INT_EN (0x01 << 2)
#define ALS_SAT_DIG_INT_EN (0x01 << 1)
#define ALS_DATA_INT_EN (0x01 << 0)

// m201_ALS_GAIN  @0x62
#define ALS1_GAIN_MASK (0x0F << 4)
#define ALS0_GAIN_MASK (0x0F << 0)

// m201_ALS_GAIN2  @0x63
#define FLK_GAIN_MASK (0x0F << 0)

// m201_ALS_INT_STATUS @0x81
#define FIFO_INT (0x01 << 7)
#define SYNC_CHG_INT (0x01 << 6)
#define SYNC_LOST_INT (0x01 << 5)
#define FLK_SAT_INT (0x01 << 4)
#define ALS_ERR_INT (0x01 << 3)
#define ALS_SAT_ANA_INT (0x01 << 2)
#define ALS_SAT_DIG_INT (0x01 << 1)
#define ALS_DATA_INT (0x01 << 0)

// m201_DATA_VALID @0x84
#define ALS_DATA_VALID (0x01 << 2)

// m201_FIFO_STATUS @0xA0
#define FIFO_LVL_L (0x01 << 5)
#define FIFO_FULL (0x01 << 4)
#define FIFO_EMPTY (0x01 << 3)
#define FIFO_AF_INT (0x01 << 2)
#define FIFO_AE_INT (0x01 << 1)

// m201_FMODE0 @0xA3
#define FIFO_ALFLAG_STICKY_EN (0x01 << 6)
#define FIFO_INT_EN (0x01 << 5)
#define FIFO_CLEAR (0x01 << 4)
#define FIFO_MODE (0x01 << 3)

// m201_FMODE1 @0xA4
#define SAVE_DATA_TO_FIFO (0x01 << 4)
#define FIFO_DATA_SRC_SEL (0x01 << 0)

// m201_SYNC_CTRL @0xE0
#define SYNC_LOST_FSM_EN (0x01 << 4)
#define SYNC_FREQ_INT_EN (0x01 << 3)
#define SYNC_LOST_INT_EN (0x01 << 2)
#define SYNC_POL (0x01 << 1)
#define WDT_EN (0x01 << 0)

#define CHANNEL_NUM 2
#define ATIME_DUTY_CYCLE 1358 //1.358us
#define SCALER	1000
#define DEFAULT_ITIME 100 // ms, ALS inte-time, = FLICKER_ITIME * ALS_BUF_SIZE
#define SHORT_ITIME 5
#define FLICKER_ITIME 500 //us, flicker inte-time,
#define DEFAULT_IGAIN 128
#define DEFAULT_IGAIN_COUNT 9
#define FIRST_IGAIN 6
#define DEFAULT_AWTIME 55 // ms
#define ALS_BUF_SIZE 54 // frames in DEFAULT_ITIME
#define LOW_AUTO_GAIN_VALUE 3
#define AUTO_GAIN_DIV 2
#define SATURATION_LOW_PERCENT 60
#define SATURATION_HIGH_PERCENT 85
#define PERCENT_BASE 100
#define LOWEST_GAIN_ID 0
#define INTEGER_SIZE 12
#define MAX_GAIN_ID 12
#define CHIPID_GET_TIME 3
#define M201_ADC_BYTES 8
#define MAX_THRESHOLD 65535
#define DEVICE_ID 0x06
#define M201_ID_REG 0x03
#define SHIFT_4 4
#define SHIFT_8 8
#define SHIFT_16 16
#define I2C_SPEED 400000
#define GAIN_RATIO 100
#define ASTEP_LEN 2
#define UNIT_MS_TO_NS 1000000
#define ALS_DELAY_TIME (100 * UNIT_MS_TO_NS)
#define FLICKER_DELAY_TIME (16 * UNIT_MS_TO_NS)  // 16 fllicker frames in 16 ms
#define LIGHT_STATE_INIT (-1)

#define REPORT_FIFO_LEN 256
#define MAX_FIFO_LEVEL 256
#define FD_POLLING_TIME 22
#define FLK_CALI_POLLING_TIME 50
#define MAX_BUFFER_SIZE 512
#define BUF_RATIO_8_16BIT 2
#define FIRST_FLK_TIMER 6
#define SIP_LOG_LENGTH 10
#define MAX_REPORT_LOGCOUNT 10000
#define SIDRIVER_ALS_ENABLE 1
#define SIDRIVER_ALS_DISABLE 0

#define SIDRIVER_FD_ENABLE 1
#define SIDRIVER_FD_DISABLE 0
#define SET_ENABLE_COMPLETE 1
#define AUTOZERO_TIMER_OFFSET 15
#define HIGH_TIMER_OFFSET 150
#define FIRST_FRAME_COUNT_MAX 20

#define MAX_ALS_VALUE (0xFFFF)
#define M201_MAX_LUX (0xFFFF)

#define MAX_FIFO_BYTES (512)  // max = 512, and must > ALS_BUF_SIZE
#define MAX_FIFO_SIZE (MAX_FIFO_BYTES / 2)
#define MAX_FLICKER_REPORT_SIZE (16)

#define MAX_DETECT_RETRY_TIMES (30)

#define DUMP_REGISTER_OPTION 0
#define USE_LUX_COEF_OPTION 1
#define USE_LONG_INTE_TIME_OPTION 0
#define USE_AWTIME_OPTION 0
#define USE_INTERRUPT_OPTION 0
#define USE_SHUNT_GAIN_OPTION 0

#ifndef ARR_SIZE
#define ARR_SIZE(a) ((sizeof(a)) / (sizeof((a)[0])))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif /* ARR_SIZE */
#define SI_REPORT_DATA_LEN  2
#define SI_CALI_DATA_LEN 4
#define SI_M201_GAIN_OF_GOLDEN 256
#define SI_M201_FD_GAIN_OF_GOLDEN 256
#define DEFAULT_ALS_GAIN_ID 4
#define M201_CAL_RATIO 10000
#define RGBAP_CALI_DATA_NV_NUM 383
#define SI_M201_FLOAT_TO_FIX 10000
#define SI_REPORT_LOG_COUNT_NUM 20
#define M201_GAIN_SCALE 1000
#define GAIN_LEVEL_1 1
#define GAIN_LEVEL_2 4
#define GAIN_LEVEL_3 16
#define GAIN_LEVEL_4 64
#define GAIN_LEVEL_5 256
#define GAIN_LEVEL_6 512

#define GAIN_CALI_LEVEL_1               1
#define GAIN_CALI_LEVEL_2               4
#define GAIN_CALI_LEVEL_3               16
#define GAIN_CALI_LEVEL_4               64
#define GAIN_CALI_LEVEL_5               256

#define FD_GAIN_LEVEL_1 2
#define FD_GAIN_LEVEL_2 8
#define FD_GAIN_LEVEL_3 64
#define FD_GAIN_LEVEL_4 256
#define FD_GAIN_LEVEL_5 1024

#define ALS_GAIN_VALUE_1 0 // 0.25
#define ALS_GAIN_VALUE_2 1 // 0.5
#define ALS_GAIN_VALUE_3 2 // 1
#define ALS_GAIN_VALUE_4 4
#define ALS_GAIN_VALUE_5 8
#define ALS_GAIN_VALUE_6 16
#define ALS_GAIN_VALUE_7 32
#define ALS_GAIN_VALUE_8 64
#define ALS_GAIN_VALUE_9 128
#define ALS_GAIN_VALUE_10 256
#define ALS_GAIN_VALUE_11 512
#define ALS_GAIN_VALUE_12 1024
#define ALS_GAIN_VALUE_13 2048

#define FREQUENCY_TOLERANCE_PERCENT 10 // Deviation Threshold（10/1000）

enum tcs_hal_algo_t {
	SI_UNSUPPORT_ALGO,
};

struct m201_reg_setting_t {
	uint8_t reg;
	uint8_t value;
};


enum m201_power_mode_t {
	SI_M201_FEATURE_ALS = (1 << 0),
	SI_M201_FEATURE_LAST
};

struct m201_adc_data_t {
	uint16_t als;
	uint16_t wb;
};

#define SI_MUTEX_LOCK(m) \
	{ mutex_lock(m); }
#define SI_MUTEX_UNLOCK(m) \
	{ mutex_unlock(m); }

struct m201_flc_ctx_t {
	UINT32 fd_gain;
	UINT16 fd_time_ms;
	struct mutex lock;
	bool first_fd_inte;
	bool enable;
	uint16_t max_flicker_range;
	uint32_t fgain;
	uint8_t gain_flicker_count;
};

struct m201_als_ctx_t {
	UINT16 saturation;
	UINT8 gain_id;
	UINT32 gain;
	uint32_t itime_ms;
	UINT16 astep;
	UINT8 atime;
	UINT8 status;
	UINT8 data_valid;
	UINT8 status2;
	UINT8 als_update;
	//enum Measurement_Steps meas_steps;
	bool load_calibration;
	UINT32 data[SI_REPORT_DATA_LEN];
	UINT8 enabled;
	uint16_t max_range;
	uint32_t tgain0;
	uint32_t tgain1;
	uint8_t gain0_count;
	uint8_t gain1_count;
	uint32_t cpl0;
	uint32_t cpl1;
	bool is_first_frame;
	struct m201_adc_data_t adc_data;
	uint8_t first_frame_count;
	uint32_t curr_itime;
};

struct m201_calib_ctx_t {
	uint32_t target[SI_REPORT_DATA_LEN];
	uint32_t ratio[SI_REPORT_DATA_LEN];
	uint8_t reserved[16];
};

struct m201_flicker_cali_ctx_t {
	uint32_t time_start;
	uint32_t time_end;
	uint16_t fd_timer_cnt;
	uint16_t fd_data_cnt;
	uint16_t target_data_cnt;
};

struct m201_ctx {
	struct i2c_client *handle;
	struct m201_als_ctx_t als_ctx;
	struct m201_flc_ctx_t flc_ctx;
	struct m201_calib_ctx_t cal_ctx;
	struct m201_flicker_cali_ctx_t flc_cali_ctx;
};

struct export_alsdata_t {
	uint32_t raw_als;
	uint32_t raw_wb;
};


static UINT8 const m201_ids[] = {
	0x06,  // m201 chip id val
};

static const struct m201_reg_setting_t m201_settings[] = {
	{M201_RST_CTRL, 0x03},
	{M201_ALS_AZ_AUTO_NUM, 0xFF},
	{M201_ALS_AZ_EN, 0xC1},
	{M201_PD_SEL0, 0xF6},
	// flicker initial
	{M201_PD_SEL1, 0xF5},
	{M201_FLK_CTRL, 0x00},
	{M201_FMODE0, 0x08},
	{M201_FMODE1, 0X00},
};

static uint32_t const m201_als_gain_conv[] = {
	(GAIN_CALI_LEVEL_1 * M201_GAIN_SCALE),
	(GAIN_CALI_LEVEL_2 * M201_GAIN_SCALE),
	(GAIN_CALI_LEVEL_3 * M201_GAIN_SCALE),
	(GAIN_CALI_LEVEL_4 * M201_GAIN_SCALE),
	(GAIN_CALI_LEVEL_5 * M201_GAIN_SCALE)
};
static uint32_t const m201_als_gain_lvl[] = {
	GAIN_LEVEL_1, GAIN_LEVEL_2, GAIN_LEVEL_3, GAIN_LEVEL_4, GAIN_LEVEL_5
};

static uint16_t const m201_als_gain[] = {
	ALS_GAIN_VALUE_1,  // actual gain is 0.5
	ALS_GAIN_VALUE_2,  ALS_GAIN_VALUE_3,  ALS_GAIN_VALUE_4,	 ALS_GAIN_VALUE_5,
	ALS_GAIN_VALUE_6,  ALS_GAIN_VALUE_7,  ALS_GAIN_VALUE_8,	 ALS_GAIN_VALUE_9,
	ALS_GAIN_VALUE_10, ALS_GAIN_VALUE_11, ALS_GAIN_VALUE_12, ALS_GAIN_VALUE_13
};

extern UINT32 flicker_support;
extern int color_report_val[MAX_REPORT_LEN];
extern int (*color_default_enable)(bool enable);

#endif
