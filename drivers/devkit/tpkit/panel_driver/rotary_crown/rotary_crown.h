/*
 * head file for rotary crown driver
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

#ifndef __ROTARY_CROWN_H__
#define __ROTARY_CROWN_H__

#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/time.h>
#include <linux/cdev.h>
#include <linux/fb.h>
#include <linux/pm.h>
#include <linux/ctype.h>

#include <huawei_platform/log/hw_log.h>
#ifdef CONFIG_LCD_KIT_HYBRID
#include "huawei_ts_kit_hybrid_core.h"
#endif

#ifndef NULL
#define NULL 0
#endif

// hw log define
#ifdef HWLOG_TAG
#undef HWLOG_TAG
#endif
#define HWLOG_TAG   ROTARY_CROWN

HWLOG_REGIST();

#define rc_debug(x...) _hwlog_debug(HWLOG_TAG, ##x)
#define rc_info(x...)  _hwlog_info(HWLOG_TAG, ##x)
#define rc_warn(x...)  _hwlog_warn(HWLOG_TAG, ##x)
#define rc_err(x...)   _hwlog_err(HWLOG_TAG, ##x)


#define NO_ERR 0
#define EC_SUCCESS (NO_ERR)
#define EC_FAILURE (-1)

// i2c define
#define ROTARY_I2C_TYPE       "i2c_type"
#define ROTARY_I2C_MSG_LEN    2
#define ROTARY_I2C_MSG_INDEX0 0
#define ROTARY_I2C_MSG_INDEX1 1
#define I2C_WAIT_TIME         25 // 25ms wait period
#define I2C_RW_TRIES          3  // retry 3 times
#define SEND_MCU_TRIES        3
#define ROTARY_I2C_ADDR_1     0x75
#define ROTARY_I2C_ADDR_2     0x32

// dts define
#define ROTARY_CROWN_DRV_NAME         "rotary_crown"
#define ROTARY_IRQ_GPIO               "irq_gpio"
#define ROTARY_CROWN_INPUT_DEV_NAME   "rotary_crown"
#define ROTARY_CROWN_MT3501_TARGET_X  "mt3501_target_x"
#define ROTARY_CROWN_PAT9126_TARGET_X "pat9126_target_x"
#define ROTARY_CROWN_NV_NUMBER        "nv_number"

// chip define
#define ROTARY_REG_ADDR_LEN         1
#define ROTARY_REG_VALUE_LEN        1
#define ROTARY_REG_WRITE_LEN        2
#define ROTARY_DELAY_1_MS           1
#define ROTARY_READ_DELTA_DELAY     10
#define ROTARY_RESET_DELAY          1
#define ROTARY_READ_MOTION_TIMES    3
#define ROTARY_SMOOTH_DATA_NUM      5
#define ROTARY_MOTION_VALID_MASK    0x80
#define ROTARY_HIGH_DELTA_SHIFT     4
#define ROTARY_HIGH_DELTA_SIGH_MASK 0x0800
#define ROTARY_HIGH_DELTA_SIGH      0xF000
#define ROTARY_HIGH_DELTA_MASK      0x0F00
#define ROTARY_STD_DELTA_VAL        532
#define ROTARY_STR_LEN              128
#define ROTARY_SPEED                14666  //rotary speed times(us)
#define ROTARY_DEFAULT_TIMES        5000   //Default delay times

// register value
#define PA_DEFAULT_CHIP_ID1   0x31
#define PA_PAGE_BANK_0        0    // set PA_PAGE_BANK_CONTROL to bank 0
#define PA_CHIP_RESET         0x97 // software reset and power down mode
#define PA_CHIP_EXIT_RESET    0x17 // exit software reset
#define PA_CHIP_POWER_DOWN    0x1F // enter power down mode
#define PA_DISABLE_WR_PROTECT 0x5A // disable write protect
#define PA_ENABLE_WR_PROTECT  0x00 // enable write protect
#define PA_X_RES_VALUE        0x80 // x resolution
#define PA_Y_RES_VALUE        0x00 // y resolution
#define PA_USE_12_BIT_FMT     0x04 // usr 12-bit X/Y data format
#define PA_SET_POWER_SAVING   0x04 // set power saving
#define PA_PERF_CFG1_VAL      0x6D // trace performance config 1
#define PA_PERF_CFG2_VAL      0x00 // trace performance config 2
#define PA_PERF_CFG3_VAL      0x82 // trace performance config 3
#define PA_ENTER_SLEEP1_MODE  0xB2 // enter sleep 1 mode

// nv define
#define RC_RES_NV_DATA_SIZE 4
#define NV_READ_TIMEOUT 30
#define NV_WRITE_OPERATION 0
#define NV_READ_OPERATION 1
#define RC_NV_NAME_LEN 6
#define ROTARY_MIN_RES_X    ((PA_X_RES_VALUE * 8) / 10)
#define ROTARY_MAX_RES_X    ((PA_X_RES_VALUE * 13) / 10)

#define ROTARY_MT3501_MIN_RES_X    ((MT3501_RES_X_DEFAULT * 8) / 10)
#define ROTARY_MT3501_MAX_RES_X    ((MT3501_RES_X_DEFAULT * 12) / 10)
#define ROTARY_HX3509_MIN_RES_X    ((HX3509_CAILCOEF_DEFAULT * 9) / 10)
#define ROTARY_HX3509_MAX_RES_X    ((HX3509_CAILCOEF_DEFAULT * 11) / 10)

// timer call back recovery duration
#define CROWN_RECOVERY_TIME 5
// timer call back check duration
#define CROWN_CHECK_TIME 4
#define CROWN_RESET_IRQ_TIME 1
// startup read times
#define MAX_READ_NV_TIMES 10

#define MT3501_REG_LEN 1
#define MT3501_POWERON_DELAY 5
#define MT3501_POWEROFF_DELAY 5
#define MT3501_HIGHPOWER_DELAY 5
#define MT3501_LOWPOWER_DELAY 1
#define MT3501_REG_INIT_NUM 38
#define MT3501_CALIB_TBL_NUM 6
#define MT3501_XH_SHIFT 4
#define MT3501_YH_SHIFT 8
#define MT3501_READ_PERIOD 20
#define MT3501_SHIFT_HIGH_BIT 32
#define MT3501_STOP_WORK_TIMES 2
/* reg value or cmd */
#define MT3501_PID1 0x41
#define MT3501_PID2 0xA2
#define HX3509_PID1 0x35
#define MT3501_RESET_CMD 0x80
#define MT3501_WRITE_PROTECT_DISABLE 0x5A
#define MT3501_WRITE_PROTECT_ENABLE 0x00
#define MT3501_RES_X_DEFAULT 0x40
#define MT3501_RES_Y_DEFAULT 0x00
#define MT3501_WAKEUP 0x19
#define MT3501_REG_PAGE_ONE 0x01
#define MT3501_REG_PAGE_TWO 0x02
#define MT3501_ENABLE_CLEAR 0x30
#define MT3501_DISABLE_CLEAR 0x20
#define MT3501_CHIP_POWER_DOWN    0x4 // enter power down mode
#define MT3501_CHIP_ENTER_SLEEP1 0x24
#define MT3501__RESET 0x96
/* reg addr */
#define MT3501_PID1_REG 0x00
#define MT3501_PID2_REG 0x01
#define MT3501_INT_MOTION_STATUS 0x02
#define MT3501_X_L_REG 0x03
#define MT3501_Y_L_REG 0x04
#define MT3501_OPERATION_MODE 0x05
#define MT3501_CONFIG_ADDR 0x06
#define MT3501_XY_H_REG 0x12
#define MT3501_WIRTE_PROTECT 0x09
#define MT3501_RES_X_REG 0x0D
#define MT3501_RES_Y_REG 0x0E
#define MT3501_TURN_REG_PAGE 0x7E
#define MT3501_AUTO_CLEAR_REG 0x23
#define MT3501_RESET_ADDR 0x49

#define HX3509_REG_LEN 1
#define HX3509_POWERON_DELAY 5
#define HX3509_POWEROFF_DELAY 5
#define HX3509_HIGHPOWER_DELAY 10
#define HX3509_LOWPOWER_DELAY 1
#define HX3509_CMD_DELAY 10
#define HX3509_WORK_DELAY 60
#define HX3509_REG_INIT_NUM 38
#define HX3509_CALIB_TBL_NUM 6
#define HX3509_XH_SHIFT 4
#define HX3509_YH_SHIFT 8
#define HX3509_READ_PERIOD 16
#define HX3509_SHIFT_HIGH_BIT 8
#define HX3509_STOP_WORK_TIMES 2
/* reg value or cmd */
#define HX3509_PID 0x35
#define HX3509_RESET_CMD1 0x41
#define HX3509_RESET_CMD2 0x40
#define HX3509_CAILCOEF_DEFAULT 1000
#define HX3509_COEF_ZOOM 1000
#define HX3509_FROCE_RUN 0x02
#define HX3509_OFF_RUN 0xFD
#define HX3509_VOLTAGE 0x04
#define HX3509_SCAN_ENABLE 0x1D
/* reg addr */
#define HX3509_PID_REG 0x00
#define HX3509_INT_MOTION_STATUS 0x02
#define HX3509_OP_MODE 0x03
#define HX3509_OPERATION_MODE 0x04
#define HX3509_X_L_REG 0x06
#define HX3509_Y_L_REG 0x07
#define HX3509_X_H_REG 0x08
#define HX3509_Y_H_REG 0x09
#define HX3509_ANA_CONFIG 0x60
#define HX3509_RESET_ADDR 0x6C

enum {
	MT3501_STATUS_OFF,
	MT3501_STATUS_ON,
};

enum {
	CR_PAT9126 = 0x01,
	CR_PAT9125 = 0x02,
	CR_MT3501 = 0x03,
	CR_HX3509 = 0x04,
};

/* reg address map */
enum {
	PA_PRODUCT_ID1 = 0x00,
	PA_PRODUCT_ID2,
	PA_MOTION_STATUS,
	PA_DELTA_X_LOW,
	PA_DELTA_Y_LOW,
	PA_OPERATION_MODE,
	PA_DEVICE_CONTROL,
	PA_WRITE_PROTECT = 0x09,
	PA_SLEEP1_CONFIG,
	PA_SLEEP2_CONFIG,
	PA_RESOLUTION_X_CONFIG = 0x0D,
	PA_RESOLUTION_Y_CONFIG,
	PA_DELTA_XY_HIGH = 0x12,
	PA_FRAME_AVERAGE = 0x17,
	PA_DELTA_DATA_FORMAT = 0x19,
	PA_TRACE_PERF_CONFIG1 = 0x2B,
	PA_TRACE_PERF_CONFIG2 = 0x2D,
	PA_LOW_VOL_CONFIG = 0x4B,
	PA_TRACE_PERF_CONFIG3 = 0x7C,
	PA_PAGE_BANK_CONTROL = 0x7F,
	PA_PAGE_REG = 0xFF,
};

/* reg address map */
uint8_t reg_can_read[] = {
	0x00, 1, 2, 3, 4, 5, 6, 0x09, 0xa, 0xb, 0xc, \
	0xd, 0xe, 0xf, 0x12, 0x1a, 0x7f, 0x28, 0x29, 0x2a
};

typedef struct {
	uint8_t reg_addr;
	uint8_t reg_value;
} mt3501_reg_info;

typedef struct {
    uint8_t regAddr;
    uint8_t regValue;
} Hx3509RegInfo;

typedef struct {
	uint8_t reserved : 7;
	uint8_t motion : 1;
} mt3501_int_status;

/* platform data that can be configured by extern */
struct rotary_crown_data {
	struct i2c_client *client;
	struct device *dev;
	struct input_dev *input_dev;
	struct work_struct work;
	uint16_t chip_id;
	uint16_t target_x;
	uint16_t nv_number;
    uint16_t cailbCoef;
	uint8_t is_suspend;
	uint8_t is_idle;
	uint8_t is_one_byte;
	uint8_t is_init_ok;
	uint8_t sys_file_ok;
	uint8_t res_x_nv;
	uint8_t is_working;
	uint8_t is_calib_test;
	int irq_gpio;
	uint irq_cnt;
	/* lock for enable/disable crown irq */
	struct mutex irq_lock;
	uint enable_irq_depth;
	uint nv_status_count;
	struct pinctrl *rc_pinctrl;
	struct pinctrl_state *pinctrl_state_active;
	struct pinctrl_state *pinctrl_state_suspend;
};

void enable_crown_irq(void);

void disable_crown_irq(void);
#endif // __ROTARY_CROWN_H__
