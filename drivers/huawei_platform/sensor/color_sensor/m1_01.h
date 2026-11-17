/*
 * m1_01.h
 *
 * code for M1 01 sensor
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: code for M1 01 sensor
 * Author: caozhipeng
 * Create: 2024-09-18
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

#ifndef M101_HW_H
#define M101_HW_H

#include "color_sensor.h"

#define DEBUG_FIFO_FD_DATA
#define M101_I2C_ADDR (0x39)

//init parameter
#define GAIN_TBL_SIZE               14
#define M101_CHIP_VALUE             0x5c
#define M101_SAMPLE_TIME            359
#define ALS_NR_SAMPLES              199
#define FD_NR_SAMPLES               200
#define ALS_QUICK_SAMPLE_TIME       14
#define FD_QUICK_NR_SAMPLES         15
#define ALS_DARK_DATA               30
#define MAX_BUFFER_SIZE             512
#define M101_WAIT_TIME              0
#define M101_AGC_MODE               0
#define M101_REPORT_DATA_LEN        2
#define M101_CALI_DATA_LEN          4
#define AGC_NUM_SAMPLES             19
#define M101_PERSIST                0
#define PD_GAIN_DEFAULT             8
#define FIFO_THRESHOLD              16
#define M101_DEVICE_ON              0x01
#define M101_ENABLE_ON              0x01
#define M101_ENABLE_OFF             0x00
#define ALS_NUM_CH                  3
#define ALS_CH_SIZE                 (sizeof(uint8_t) * 2)
#define MOD_CLOCK                   1389
#define ALS_ACCUMULATE_NO           3
#define CLOCK_DELAY_TIME            50
#define VSYNC_CFG_VAL               0x4
#define TRIGGER_MODE_VAL            0x5
#define INVALID_DENOMINATOR         0
#define HIGH_THRESHOLD              14305567 // (1.38889 + 1.38889 * 3%) * 10000000
#define LOW_THRESHOLD               13472233 // (1.38889 - 1.38889 * 3%) * 10000000
#define BUFF_LEN                    2
#define TIME_CONVERSION             10000
#define SAMPLE_2KHZ                 5000000000 // 500us*10000000
#define FLK_CALI_POLLING_TIME       50
#define SW_VSYNC_TRIGGER            1
#define SCALER                      1000
#define M101_MASK_AGAIN             0x03
#define INDOOR_LUX_TRIGGER	        6000
#define OUTDOOR_LUX_TRIGGER	        10000
#define M101_MAX_LUX		        0xffff
#define M101_MAX_ALS_VALUE	        0xffff
#define M101_ALS_LOW_THRESH         0x000000
#define M101_ALS_HIGH_THRESH        0xFFFFFF
#define M101_MIN_ALS_VALUE	        3
#define MAX_I2C_READ_LEN            128
#define MAX_DEVICE_FIFO_LEN         512
#define GC_AGAIN                    256
#define GAIN_RATIO                  100
#define MAX_ALS_GAIN_LEVEL          12
#define MAX_ALS_GAIN_PRE_LEVEL      11
#define MIN_ALS_GAIN_LEVEL          1
#define MIN_ALS_GAIN_STEP           1
#define MID_ALS_GAIN_STEP           2
#define MAX_FIFO_DATA_LEN           2048
#define FFT_MAX_SAMPLE_SIZE         1024
#define FFT_SAMPLE_FREQ             2000
#define FFT_BIN_COUNT               256
#define FIRST_FLK_TIMER             6
#define FD_POLLING_TIME             22
#define ALS_FAST_POLLING_TIME       10
#define ALS_POLLING_CNT             10
#define ALS_NORMAL_POLLING_TIME     270
#define BUF_RATIO_8_16BIT           2
#define ASTEP_LEN                   2
#define REPORT_FIFO_LEN             128
#define M101_CHAN_NUM               3
#define FLCKR_BUFFER_SZ             1024
#define FD_PACKET_COMPRESSED_SZ     7 // MOD_FD_FIFO_DATA7_WIDTH + 1(base 0) + 1(HW bit flag)
#define FD_FOOTER_SZ_BYTES          5 // size of the footer -  3 end marker bytes, 2 bytes for gain
#define FLICKER_BYTES_PER_SAMPLE    2
#define MAX_FD_NR_SAMPLES           (0x07ff + 1)
#define M101_DEFAULT_MODULATOR_PERIOD_TO_MS 1000
#define READ_TWO_BITS               2
#define READ_NINE_BITS              9
#define CHIPID_GET_TIME             3
#define SEQUENCER_INIT_VALUE        3
#define SAMPLE_TIME_LOW_MASK        0x00FF
#define SAMPLE_TIME_HIGH_MASK       0x0700
#define NUM_SAMPLES_LOW_MASK        0x00FF
#define NUM_SAMPLES_HIGH_MASK       0x0700
#define SHIFT_8                     8
#define SHIFT_4                     4
#define ALS_THRESH_MASK_0           0x000000FF
#define ALS_THRESH_MASK_1           0x0000FF00
#define ALS_THRESH_MASK_2           0x00FF0000
#define MOD_PHD_MASK                0x0F
#define HIGH_TIMER_OFFSET           30
#define M101_RBITS_VALUE_4		    1
#define M101_RBITS_VALUE_3		    2
#define M101_RBITS_VALUE_2		    3
#define M101_RBITS_VALUE_1		    4
#define EACH_TIME_WAIT_TIME         2
#define WAIT_TIME_MAX               70
// M101 FIFO settings
#define ALS_DATA_LENGTH             0
#define END_MARKER_SZ               3
#define M101_DRIVER_FD_ENABLE       1
#define M101_DRIVER_FD_DISABLE      0
#define M101_DRIVER_ALS_ENABLE      1
#define M101_DRIVER_ALS_DISABLE     0
#define GAIN_LEVEL_1                1
#define GAIN_LEVEL_2                4
#define GAIN_LEVEL_3                16
#define GAIN_LEVEL_4                64
#define GAIN_LEVEL_5                256
#define CAL_RATIO_DEFAULT			10000
#define FLOAT_TO_FIX			    10000
#define REPORT_LOG_COUNT_NUM	    10
#define MAX_REPORT_LOGCOUNT         10000
#define CANNEL_MAX_CONT             65535
#define IDLE_STEP                   0

// Register map
#define M101_ENABLE                          0x80
#define M101_MEAS_MODE0                      0x81
#define M101_MEAS_MODE1                      0x82
#define M101_SAMPLE_TIME0                    0x83
#define M101_SAMPLE_TIME1                    0x84
#define M101_ALS_NR_SAMPLES0                 0x85
#define M101_ALS_NR_SAMPLES1                 0x86
#define M101_FD_NR_SAMPLES0                  0x87
#define M101_FD_NR_SAMPLES1                  0x88
#define M101_WTIME                           0x89
#define M101_AILT0                           0x8A
#define M101_AILT1                           0x8B
#define M101_AILT2                           0x8C
#define M101_AIHT0                           0x8D
#define M101_AIHT1                           0x8E
#define M101_AIHT2                           0x8F
#define M101_AUXID                           0x90
#define M101_REVID                           0x91
#define M101_ID                              0x92
#define M101_STATUS                          0x93
#define M101_ALS_STATUS                      0x94
#define M101_DATAL0                          0x95
#define M101_DATAH0                          0x96
#define M101_DATAL1                          0x97
#define M101_DATAH1                          0x98
#define M101_DATAL2                          0x99
#define M101_DATAH2                          0x9A
#define M101_ALS_STATUS2                     0x9B
#define M101_ALS_STATUS3                     0x9C
#define M101_STATUS2                         0x9D
#define M101_STATUS3                         0x9E
#define M101_STATUS4                         0x9F
#define M101_STATUS5                         0xA0
#define M101_CFG0                            0xA1
#define M101_CFG1                            0xA2
#define M101_CFG2                            0xA3
#define M101_CFG3                            0xA4
#define M101_CFG4                            0xA5
#define M101_CFG5                            0xA6
#define M101_CFG6                            0xA7
#define M101_CFG7                            0xA8
#define M101_CFG8                            0xA9
#define M101_CFG9                            0xAA
#define M101_AGC_NR_SAMPLES_LO               0xAC
#define M101_AGC_NR_SAMPLES_HI               0xAD
#define M101_TRIGGER_MODE                    0xAE
#define M101_CONTROL                         0xB1
#define M101_INTENAB                         0xBA
#define M101_SIEN                            0xBB
#define M101_MOD_COMP_CFG1                   0xCE
#define M101_MEAS_SEQR_FD_0                  0xCF
#define M101_MEAS_SEQR_ALS_FD_1              0xD0
#define M101_MEAS_SEQR_APERS_AND_VSYNC_WAIT  0xD1
#define M101_MEAS_SEQR_RESIDUAL_0            0xD2
#define M101_MEAS_SEQR_RESIDUAL_1_AND_WAIT   0xD3
#define M101_MEAS_SEQR_STEP0_MOD_GAINX_L     0xD4
#define M101_MEAS_SEQR_STEP0_MOD_GAINX_H     0xD5
#define M101_MEAS_SEQR_STEP1_MOD_GAINX_L     0xD6
#define M101_MEAS_SEQR_STEP1_MOD_GAINX_H     0xD7
#define M101_MEAS_SEQR_STEP2_MOD_GAINX_L     0xD8
#define M101_MEAS_SEQR_STEP3_MOD_GAINX_L     0xDA
#define M101_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_L 0xDC
#define M101_MEAS_SEQR_STEP0_MOD_PHDX_SMUX_H 0xDD
#define M101_MEAS_SEQR_STEP1_MOD_PHDX_SMUX_L 0xDE
#define M101_MEAS_SEQR_STEP1_MOD_PHDX_SMUX_H 0xDF
#define M101_MEAS_SEQR_STEP2_MOD_PHDX_SMUX_L 0xE0
#define M101_MEAS_SEQR_STEP2_MOD_PHDX_SMUX_H 0xE1
#define M101_MEAS_SEQR_STEP3_MOD_PHDX_SMUX_L 0xE2
#define M101_MEAS_SEQR_STEP3_MOD_PHDX_SMUX_H 0xE3
#define M101_MOD_CALIB_CFG0                  0xE4
#define M101_MOD_CALIB_CFG2                  0xE6
#define M101_VSYNC_PERIOD_L                  0xF2
#define M101_VSYNC_PERIOD_H                  0xF3
#define M101_VSYNC_PERIOD_TARGET_L           0xF4
#define M101_VSYNC_PERIOD_TARGET_H           0xF5
#define M101_VSYNC_CONTROL                   0xF6
#define M101_VSYNC_CFG                       0xF7
#define M101_VSYNC_GPIO_INT                  0xF8
#define M101_MOD_FIFO_DATA_CFG0              0xF9
#define M101_MOD_FIFO_DATA_CFG1              0xFA
#define M101_MOD_FIFO_DATA_CFG2              0xFB
#define M101_FIFO_THR                        0xFC
#define M101_FIFO_LEVEL                      0xFD
#define M101_FIFO_STATUS0                    0xFE
#define M101_FIFO_DATA                       0xFF
/* Mask Macros */
#define M101_PON_SHIFT 0
#define M101_MASK_PON (1 << M101_PON_SHIFT)

#define M101_AEN_SHIFT 1
#define M101_MASK_AEN (1 << M101_AEN_SHIFT)

#define M101_FDEN_SHIFT 6
#define M101_MASK_FDEN (1 << M101_FDEN_SHIFT)

#define M101_MINT_SHIFT 7
#define M101_MASK_MINT (1 << M101_MINT_SHIFT)

#define M101_AINT_SHIFT 3
#define M101_MASK_AINT (1 << M101_AINT_SHIFT)

#define M101_FINT_SHIFT 2
#define M101_MASK_FINT (1 << M101_FINT_SHIFT)

#define M101_SINT_SHIFT 0
#define M101_MASK_SINT (1 << M101_SINT_SHIFT)

#define M101_MIEN_SHIFT 7
#define M101_MASK_MIEN (1 << M101_MIEN_SHIFT)

#define M101_AIEN_SHIFT 3
#define M101_MASK_AIEN (1 << M101_AIEN_SHIFT)

#define M101_FIEN_SHIFT 2
#define M101_MASK_FIEN (1 << M101_FIEN_SHIFT)

#define M101_SIEN_SHIFT 0
#define M101_MASK_SIEN (1 << M101_SIEN_SHIFT)

#define M101_APERS_SHIFT 0
#define M101_MASK_APERS (0xF << M101_APERS_SHIFT)

#define M101_ASAT_SHIFT 7
#define M101_MASK_ASAT (1 << M101_ASAT_SHIFT)

// Register bits map
// ENABLE @ 0x80
#define PON                                      (0x01 << 0)
#define AEN                                      (0x01 << 1)
#define PEN                                      (0x01 << 2)
#define WEN                                      (0x01 << 3)
#define SMUXEN                                   (0x01 << 4)
#define FDEN                                     (0x01 << 6)

#define M101_MEAS_MODE0_SHIFT_STOP_AFTER_NTH_ITER                (7)
#define M101_MEAS_MODE0_SHIFT_DOUBLE_STEP_DOWN   (6)
#define M101_MEAS_MODE0_MASK_ENABLE_AGC_ASAT_DOUBLE_STEP_DOWN (1 << M101_MEAS_MODE0_SHIFT_DOUBLE_STEP_DOWN)
#define M101_MEAS_MODE0_SHIFT_MEAS_SEQR_SINGLE_SHOT_MODE         (5)
#define M101_MEAS_MODE0_SHIFT_FIFO_ALS_STATUS_WRITE_ENABLE       (4)
#define M101_MEAS_MODE0_SHIFT_ALS_SCALE                          (0)
#define M101_MEAS_MODE0_MASK_ALS_SCALE   (0x0f << M101_MEAS_MODE0_SHIFT_ALS_SCALE)


#define M101_SHIFT_FD_END_MARKER_WRITE_EN    (7)
#define M101_FD_END_MARKER_WRITE_EN (1 << M101_SHIFT_FD_END_MARKER_WRITE_EN)
#define M101_SHIFT_FD_CHKSUM_MARKER_WRITE_EN (6)
#define M101_FD_CHKSUM_MARKER_WRITE_EN (1 << M101_SHIFT_FD_CHKSUM_MARKER_WRITE_EN)
#define M101_SHIFT_FD_GAIN_WRITE_EN          (5)
#define M101_FD_GAIN_WRITE_EN (1 << M101_SHIFT_FD_GAIN_WRITE_EN)
#define M101_MEAS_MODE1_SHIFT_ALS_MSB_POSITION                   (0)
#define M101_MEAS_MODE1_MASK_ALS_MSB_POSITION                    (0x1F << M101_MEAS_MODE1_SHIFT_ALS_MSB_POSITION)
#define DEFAULT_ALS_MSB_POSITION                                    (0x0C)

#define M101_MOD_CALIB_NTH_ITERATION_AGC_ENABLE_SHIFT 5
#define M101_MASK_MOD_CALIB_NTH_ITERATION_AGC_ENABLE (1 << M101_MOD_CALIB_NTH_ITERATION_AGC_ENABLE_SHIFT)

#define M101_MEASUREMENT_SEQ_AGC_ASAT_PATTERN_SHIFT 4
#define M101_MASK_MEASUREMENT_SEQ_AGC_ASAT_PATTERN (0x0F << M101_MEASUREMENT_SEQ_AGC_ASAT_PATTERN_SHIFT)

#define M101_MEASUREMENT_SEQ_AGC_PREDICT_PATTERN_SHIFT 4
#define M101_MASK_MEASUREMENT_SEQ_AGC_PREDICT_PATTERN (0x0F << M101_MEASUREMENT_SEQ_AGC_PREDICT_PATTERN_SHIFT)

#define M101_FIFO_OV_SHIFT 7
#define M101_MASK_FIFO_OV (1 << M101_FIFO_OV_SHIFT)

#define M101_FIFO_UF_SHIFT 6
#define M101_MASK_FIFO_UF (1 << M101_FIFO_UF_SHIFT)

#define M101_MOD_ALS_FIFO_DATAX_WRITE_ENABLE_SHIFT 7
#define M101_MASK_MOD_ALS_FIFO_DATAX_WRITE_ENABLE (0x01 << M101_MOD_ALS_FIFO_DATAX_WRITE_ENABLE_SHIFT)

#define M101_FIFO_THR_LSB_SHIFT 0
#define M101_MASK_FIFO_THR_LSB (0x0001 << M101_FIFO_THR_LSB_SHIFT)

#define M101_ALS_DATA0_SCALED_STATUS_SHIFT 2
#define M101_MASK_ALS_DATA0_SCALED_STATUS (0x01 << M101_ALS_DATA0_SCALED_STATUS_SHIFT)

#define M101_ALS_DATA1_SCALED_STATUS_SHIFT 1
#define M101_MASK_ALS_DATA1_SCALED_STATUS (0x01 << M101_ALS_DATA1_SCALED_STATUS_SHIFT)

#define M101_ALS_DATA2_SCALED_STATUS_SHIFT 0
#define M101_MASK_ALS_DATA2_SCALED_STATUS (0x01 << M101_ALS_DATA2_SCALED_STATUS_SHIFT)

#define M101_FD_NR_SAMPLES_HI_SHIFT 0
#define M101_MASK_FD_NR_SAMPLES_HI (0x07 << M101_FD_NR_SAMPLES_HI_SHIFT)

#define M101_FIFO_CLR_SHIFT 1
#define M101_MASK_FIFO_CLR (0x01 << M101_FIFO_CLR_SHIFT)

#define M101_MOD_CALIB_NTH_ITERATION_SHIFT 0
#define M101_MASK_MOD_CALIB_NTH_ITERATION (0xFF << M101_MOD_CALIB_NTH_ITERATION_SHIFT)

#define M101_SINT_MEASUREMENT_SEQUENCER_SHIFT 1
#define M101_MASK_SINT_MEASUREMENT_SEQUENCER (0x01 << M101_SINT_MEASUREMENT_SEQUENCER_SHIFT)

#define M101_SAI_ACTIVE_SHIFT 1
#define M101_MASK_SAI_ACTIVE (0x01 << M101_SAI_ACTIVE_SHIFT)

#define M101_CLEAR_SAI_ACTIVE_SHIFT 0
#define M101_MASK_CLEAR_SAI_ACTIVE (0x01 << M101_CLEAR_SAI_ACTIVE_SHIFT)

#define M101_SAI_SHIFT 6
#define M101_MASK_SAI (0x01 << M101_SAI_SHIFT)

#define M101_SIEN_MEASUREMENT_SEQUENCER_SHIFT 1
#define M101_MASK_SIEN_MEASUREMENT_SEQUENCER (0x01 << M101_SIEN_MEASUREMENT_SEQUENCER_SHIFT)

#define M101_MEASUREMENT_SEQUENCER_SINGLE_SHOT_SHIFT 5
#define M101_MASK_MEASUREMENT_SEQUENCER_SINGLE_SHOT (0x01 << M101_MEASUREMENT_SEQUENCER_SINGLE_SHOT_SHIFT)

#define M101_MEASUREMENT_SEQUENCER_MOD0_FD_PATTERN_SHIFT 0
#define M101_MASK_MEASUREMENT_SEQUENCER_MOD0_FD_PATTERN (0x0F << M101_MEASUREMENT_SEQUENCER_MOD0_FD_PATTERN_SHIFT)

#define M101_MEASUREMENT_SEQUENCER_MOD1_FD_PATTERN_SHIFT 4
#define M101_MASK_MEASUREMENT_SEQUENCER_MOD1_FD_PATTERN (0x0F << M101_MEASUREMENT_SEQUENCER_MOD1_FD_PATTERN_SHIFT)

#define M101_MEASUREMENT_SEQUENCER_MOD2_FD_PATTERN_SHIFT 4
#define M101_MASK_MEASUREMENT_SEQUENCER_MOD2_FD_PATTERN (0x0F << M101_MEASUREMENT_SEQUENCER_MOD2_FD_PATTERN_SHIFT)

#define M101_MEASUREMENT_SEQUENCER_ALS_PATTERN_SHIFT 0
#define M101_MASK_MEASUREMENT_SEQUENCER_ALS_PATTERN (0x0F << M101_MEASUREMENT_SEQUENCER_ALS_PATTERN_SHIFT)

// M101_REG_FIFO_LEVEL    0xFD
#define M101_SHIFT_FIFO_LEVEL                 (2)  // upper 2 bits of a 10 bit number
#define M101_SHIFT_STATUS0_FIFO_LVL_L    (0)
#define M101_MASK_STATUS0_FIFO_LVL_L     (3 << M101_SHIFT_STATUS0_FIFO_LVL_L)

/* M101_REG_CFG2    0xA3 */
#define M101_SHIFT_CFG2_FIFO_THRESH_L          (0)
#define M101_MASK_CFG2_FIFO_THRESH_L           (1 << M101_SHIFT_CFG2_FIFO_THRESH_L)

// M101_REG_FIFO_STATUS0     0xFE
#define M101_SHIFT_FIFO_STATUS0_FIFO_OVERFLOW      (7)
#define M101_MASK_FIFO_STATUS0_FIFO_OVERFLOW       (1 << M101_SHIFT_FIFO_STATUS0_FIFO_OVERFLOW)

#define M101_SHIFT_FIFO_STATUS0_FIFO_UNDERFLOW     (6)
#define M101_MASK_FIFO_STATUS0_FIFO_UNDERFLOW      (1 << M101_SHIFT_FIFO_STATUS0_FIFO_UNDERFLOW)

#define M101_REG_MOD_FIFO_DATA_WRITE_ENABLE_SHIFT 7
#define M101_REG_MOD_FIFO_DATA_WRITE_ENABLE_MASK (1 << M101_REG_MOD_FIFO_DATA_WRITE_ENABLE_SHIFT)

#define M101_SHIFT_ALS_STATUS_MEAS_SEQR_STEP      (6)
#define M101_MASK_ALS_STATUS_MEAS_SEQR_STEP       (3 << M101_SHIFT_ALS_STATUS_MEAS_SEQR_STEP)

#define M101_SHIFT_GAIN_MOD0         (0)
#define M101_SHIFT_GAIN_MOD1         (4)
#define M101_SHIFT_GAIN_MOD2         (0)

// M101_REG_STATUS     0x9D      STATUS2
#define STATUS2_ALS_DATA_VALID_SHIFT             6
#define STATUS2_ALS_DATA_VALID_MASK              (1 << STATUS2_ALS_DATA_VALID_SHIFT)

#define M101_SHIFT_CFG4_MEAS_SEQR_SINT_PER_STEP       (4)
#define M101_MASK_CFG4_MEAS_SEQR_SINT_PER_STEP        (1 << M101_SHIFT_CFG4_MEAS_SEQR_SINT_PER_STEP)

#define M101_SHIFT_CFG4_MOD_ALS_FIFO_DATA_FORMAT      (0)
#define M101_MASK_CFG4_MOD_ALS_FIFO_DATA_FORMAT       (3 << M101_SHIFT_CFG4_MOD_ALS_FIFO_DATA_FORMAT)

// M101_REG_STATUS4    0x9F
#define M101_REG_STATUS4_MOD_SAMPLE_TRIGGER_ERROR_SHIFT                  3
#define M101_MOD_SAMPLE_TRIGGER_ERROR     (1 << M101_REG_STATUS4_MOD_SAMPLE_TRIGGER_ERROR_SHIFT)

// M101_REG_SIEN     0xBB
#define M101_SHIFT_SIEN_SIEN_MEASR_SEQR               (1)
#define M101_MASK_SIEN_SIEN_MEASR_SEQR                (1 << M101_SHIFT_SIEN_SIEN_MEASR_SEQR)

// m101_als_chan_asat_mask
#define M101_ALS_STATUS_ALS_DATA2_SATURATION_SHIFT            3
#define M101_ALS_STATUS_ALS_DATA2_SATURATION_MASK             (1 << M101_ALS_STATUS_ALS_DATA2_SATURATION_SHIFT)

#define M101_ALS_STATUS_ALS_DATA1_SATURATION_SHIFT            4
#define M101_ALS_STATUS_ALS_DATA1_SATURATION_MASK             (1 << M101_ALS_STATUS_ALS_DATA1_SATURATION_SHIFT)

#define M101_ALS_STATUS_ALS_DATA0_SATURATION_SHIFT            5
#define M101_ALS_STATUS_ALS_DATA0_SATURATION_MASK             (1 << M101_ALS_STATUS_ALS_DATA0_SATURATION_SHIFT)

// M101_REG_MOD_COMP_CFG1     0xCE
#define M101_SHIFT_MOD_COMP_CFG1_IDAC_RANGE           (6)
#define M101_MASK_MOD_COMP_CFG1_IDAC_RANGE            (3 << M101_SHIFT_MOD_COMP_CFG1_IDAC_RANGE)

extern int color_report_val[MAX_REPORT_LEN];
extern uint32_t flicker_support;
extern int (*color_default_enable)(bool enable);
//supported fifo formats
enum m101_fifo_format_t {
	FIFO_FORMAT_UNCOMPRESSED = 1,
	FIFO_FORMAT_DIFFERENCE,
	FIFO_FORMAT_COMPRESSED,
	FIFO_FORMAT_DIFFERENCE_COMPRESSED,
	FIFO_FORMAT_MULTI_CHL_COMPRESSED,
	FIFO_FORMAT_MULTI_CHL_DIFFERENCE_COMPRESSED
};

enum m101_agc_hw_mode {
	AGC_HW_DISABLE_ALL = 0,
	AGC_Sat_ONLY,
	AGC_Pre_ONLY,
	AGC_HW_ENABLE_ALL,
};

enum m101_AGC_SW_mode {
	AGC_SW_DISABLE = 0,
	AGC_SW_ENABLE,
};

enum m101_pd_t {
	PD_CLEAR,
	PD_RED,
	PD_GREEN,
	PD_BLUE,
	PD_END,
};

enum m101_modulator_t {
	MODULATOR_0,
	MODULATOR_1,
	NUM_MODULATORS,
};

enum m101_stat_type_t {
	STAT,
	ALS_STAT,
	ALS_STAT2,
	ALS_STAT3,
	STAT2,
	STAT3,
	STAT4,
	STAT5,
	STAT_FIFO,
	STAT_END
};

enum m101_gains {
	M101_HALF_X_GAIN            = 0x00,
	M101_1_X_GAIN               = 0x01,
	M101_2_X_GAIN               = 0x02,
	M101_4_X_GAIN               = 0x03,
	M101_8_X_GAIN               = 0x04,
	M101_16_X_GAIN              = 0x05,
	M101_32_X_GAIN              = 0x06,
	M101_64_X_GAIN              = 0x07,
	M101_128_X_GAIN             = 0x08,
	M101_256_X_GAIN             = 0x09,
	M101_512_X_GAIN             = 0x0A,
	M101_1024_X_GAIN            = 0x0B,
	M101_2048_X_GAIN            = 0x0C,
	M101_4096_X_GAIN            = 0x0D,
};

enum m101_mod_idac_ranges {
	M101_IDAC_58UV,
	M101_IDAC_38UV,
	M101_IDAC_18UV,
	M101_IDAC_9UV,
};

enum m101_power_mode_t {
	M101_FEATURE_ALS = (1 << 0),
	M101_FEATURE_LAST
};

enum m101_sensor_id_t {
	UNKNOWN_DEVICE,
	M101_REV0
};

struct m101_als {
	int32_t raw_vis;
	int32_t raw_ir;
	int32_t raw_uv;
	uint8_t step;
	uint8_t analog_saturation[PD_END];
	uint8_t gains[PD_END];
	uint32_t agc_thr_high;
	uint32_t agc_thr_low;
	uint16_t cct;
	uint32_t raw_pds[NUM_MODULATORS];
	uint8_t pd_gain[NUM_MODULATORS];
	uint16_t saturation_high;
	uint16_t saturation_low;
};

struct m101_cal_ref {
	uint32_t channel_target[ALS_NUM_CH];
	uint8_t gain[ALS_NUM_CH];
};

// data struct for processing
struct m101_flicker {
	uint8_t flicker_data_h;
	uint8_t flicker_data_l;
	uint8_t flicker_data_l_filled;
	uint16_t flicker_data_number;
	uint16_t flicker_data[MAX_FD_NR_SAMPLES];
};

struct m101_als_ctx_t {
	UINT16 saturation;
	UINT8 gain_id;
	UINT32 gain;
	UINT32 itime_ms;
	UINT16 astep;
	UINT8 atime;
	UINT8 status;
	UINT8 status2;
	UINT8 als_update;
	bool load_calibration;
	UINT8 smux_mode;
	UINT8 enabled;
	UINT32 data[10];
	int als_polling_cnt;
	UINT8 als_polling_time;
	bool is_zoom_data;
	UINT8 step_status;
};

struct m101_calib_ctx_t {
	uint32_t target[M101_REPORT_DATA_LEN];
	uint32_t ratio[M101_REPORT_DATA_LEN];
	uint8_t reserved[16];
};

struct m101_ctx {
	uint8_t i2c_addr;
	struct i2c_client *handle;
	struct mutex lock;
	uint16_t sample_time;
	uint8_t wait_time;
	uint16_t atime_ms;
	uint8_t agc_mode;
	enum m101_agc_hw_mode hw_agc_mode;
	uint16_t agc_num_samples;
	uint8_t als_scale;
	uint16_t fifo_threshold;
	uint16_t fifo_level;
	uint16_t fd_nr_samples;
	uint16_t als_nr_samples;
	uint8_t persist;
	uint8_t gain_max;
	uint8_t gain[PD_END];
	uint8_t gain_reg[NUM_MODULATORS]; /* actual register value - only 1 modulator for flicker */
	uint8_t reg_status[STAT_END];
	uint32_t gain_mod[NUM_MODULATORS]; /* actual channel gain.. 2x, 4x, 8x, 16x... */
	uint32_t norm_pds[NUM_MODULATORS];
	uint32_t norm_data[PD_END];
	uint8_t enable;
	uint8_t step;
	uint32_t step0_c_val;
	uint32_t step1_c_val;
	bool is_change_gain;
	int als_first_report;
	struct m101_als als;
	struct m101_flicker fd;
	struct m101_als_ctx_t alg_ctx;
	struct m101_calib_ctx_t cal_ctx;
};

#endif /* M101_H */
