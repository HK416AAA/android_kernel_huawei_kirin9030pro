/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: vi5302 driver
 */

#ifndef VI5302_H
#define VI5302_H

#include <linux/types.h>
#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/miscdevice.h>
#include <linux/regulator/consumer.h>
#include <platform_include/camera/native/laser_cfg.h>
#include "hw_laser_dmd.h"

#define VI5302_CHIP_ADDR 0xD8

#define MAX_WAIT_RETRY 	5
#define FW_PAGE_SIZE 	64
#define MAX_FPS			45
#define OTP_MAX_SIZE	61

#define REG_MCU_CFG          0x00
#define REG_SYS_CFG          0x01
#define REG_DEV_STAT         0x02
#define REG_INT_STATUS       0x03
#define REG_INTR_MASK        0x04
#define REG_DEV_ADDR         0x06
#define REG_PW_CTRL          0x07
#define REG_SPECIAL_PURP1    0x08
#define REG_SPECIAL_PURP2    0x09
#define REG_CMD              0x0A
#define REG_SIZE             0x0B
#define REG_SCRATCH_PAD_BASE 0x0C
#define REG_USER_DATA        0x0F
#define REG_DTOP_3           0x54
#define REG_DTOP_5           0x56
#define REG_CHIPID_BASE      0x4C
#define REG_POWER_CTRL       0x65

#define CMD_WRITEFW             0x03
#define CMD_USER_CFG            0x09
#define CMD_XTALK               0x0D
#define CMD_SINGLE_RANGE        0x0E
#define CMD_CONTINOUS_RANGE     0x0F
#define CMD_STOP_RANGE          0x1F

#define SUBCMD_READ_SYSTEM_DATA     0x00
#define SUBCMD_WRITE_SYSTEM_DATA    0x01
#define SUBCMD_WRITE_OTP          0x02
#define SUBCMD_READ_OTP           0x03
#define SUBCMD_READ_FW_VERSION      0x06

typedef int32_t vi5302_error;
typedef struct vi5302_data* vi5302_dev;

#define VI5302_ERROR_NONE 			((vi5302_error) 0)
#define VI5302_ERROR_CPU_BUSY 		((vi5302_error) -1)
#define VI5302_ERROR_ENABLE_INTR 	((vi5302_error) -2)
#define VI5302_ERROR_XTALK_CALIB 	((vi5302_error) -3)
#define VI5302_ERROR_OFFSET_CALIB 	((vi5302_error) -4)
#define VI5302_ERROR_XTALK_CONFIG 	((vi5302_error) -5)
#define VI5302_ERROR_SINGLE_CMD 	((vi5302_error) -6)
#define VI5302_ERROR_CONTINUOUS_CMD ((vi5302_error) -7)
#define VI5302_ERROR_GET_DATA 		((vi5302_error) -8)
#define VI5302_ERROR_STOP_CMD 		((vi5302_error) -9)
#define VI5302_ERROR_IRQ_STATE 		((vi5302_error) -10)
#define VI5302_ERROR_FW_FAILURE 	((vi5302_error) -11)
#define VI5302_ERROR_POWER_ON 		((vi5302_error) -12)
#define VI5302_ERROR_POWER_OFF 		((vi5302_error) -13)
#define VI5302_ERROR_OTP		 	((vi5302_error) -14)
#define VI5302_ERROR_SET_FPS		((vi5302_error) -15)

#define START_WAKE_LOCK_TIMEOUT       10000  /* 10000ms */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

struct vi5302_xtalk_calib_data {
	int8_t xtalk_cal;
	uint16_t xtalk_peak;
};

struct vi5302_offset_calib_data { 
	int16_t offset_cal;
	int16_t ref_tof; // not use, to seam with vi5300
};

struct vi5302_data {
 	struct device *dev;
	struct class *dev_class;
 	const char *dev_name;
	const struct attribute_group *vi5302_attr_group;
	struct VI5300_Measurement_Data range_data; // vi5300 & vi5302 measure_data already adapted
	struct vi5302_xtalk_calib_data xtalk_data;
	struct vi5302_offset_calib_data offset_data;
	struct vi5302_xtalk_calib_data xtalk_config;
	struct i2c_client *client;
	struct input_dev *input_dev;
	struct miscdevice miscdev;
	struct timespec64 start_ts;
	int irq_gpio;
	int xshut_gpio;
	int irq;
	uint32_t chip_enable;
	uint32_t enable_debug;
	uint8_t intr_state;
	uint8_t fwdl_status;
	int16_t offset_config;
	uint32_t fps;
	uint8_t ma_sum;
	uint8_t chip_version;
	struct mutex work_mutex;
	struct wakeup_source *wake_lock;
	struct regulator *lvdd;
	hw_laser_ctrl_t *ctrl;
	/* first valid data after start */
	int is_first_valid_data;
 };

enum VI5302_INT_STATUS {
	VI5302_INTR_DISABLED = 0,
	VI5302_INTR_ENABLED,
};

#define DEBUG
#define vi5302_infomsg(str, args...) \
	 pr_info("%s: " str, __func__, ##args)
#define vi5302_dbgmsg(str, args...) \
	 pr_debug("%s: " str, __func__, ##args)
#define vi5302_errmsg(str, args...) \
	 pr_err("%s: " str, __func__, ##args)

int vi5302_probe(struct i2c_client *client, const struct i2c_device_id *id);
int vi5302_remove(struct i2c_client *client);
long vi5302_ioctl(void *hw_data, unsigned int cmd, void *p);
#endif
