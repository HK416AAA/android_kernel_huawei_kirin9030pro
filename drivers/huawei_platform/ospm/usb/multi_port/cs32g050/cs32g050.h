/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * cs32g050.c
 *
 * cs32g050 multi port driver
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, pmicstributed, and mopmicfied under those terms.
 *
 * This program is pmicstributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */
#ifndef _CS32G050_MULTI_PORT_H_
#define _CS32G050_MULTI_PORT_H_

#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/workqueue.h>
#include "hw_cs32g050.h"
#include <linux/types.h>
#ifdef CONFIG_DFX_DEBUG_FS
#include <linux/debugfs.h>
#endif /* CONFIG_DFX_DEBUG_FS */

#define CS32G050_CONTROL_REG                                   0X50
#define CS32G050_STATUS_REG                                    0X5F
#define CS32G050_STATUS_REG_LEN                                (5 + 1) // 5 byte data + 1 byte datalen
#define CS32G050_CLEAN_I2C_IRQ_CMD                             0x04
#define CS32G050_CLEAN_HPD_IRQ_CMD                             0x2000
#define CS32G050_CLEAN_IRQ_CMD_LEN                             0x06
#define CS32G050_READ_STATUS_FAIL                              0xFFFF
#define CS32G050_I2C_RETRY_TIMES                               10
#define CS32G050_I2C_RETRY_DELAY                               10

#define bit(x)								                   ((u16)(1 << (x)))

/* CS32G050_STATUS_REG BIT */
#define CS32G050_DATA_CONNECTION                               bit(0)
#define CS32G050_CONNECT_ORIENTATION                           bit(1)
#define CS32G050_USB2_CONNECT_STATE                            bit(4)
#define CS32G050_USB3_CONNECT_STATE                            bit(5)
#define CS32G050_USB_DATA_ROLE                                 bit(7)
#define CS32G050_DP_CONNECTION                                 bit(8)
#define CS32G050_DP_SOURCE_SINK                                bit(9)
#define CS32G050_HPD_IRQ                                       bit(14)
#define CS32G050_HPD_LEVEL_STATE                               bit(15)
#define CS32G050_ANALOG_EARPHONE_CONNECTION                    (1ULL << 39)

#define CS32G050_FIRMWARE_UPDATE_DELAY                         120000
#define CS32G050_FIRMWARE_UPDATE_DEFAULT_MODE                  1
#define CS32G050_FIRMWARE_UPDATE_FIRST_ADDR                    0x50
#define CS32G050_HMI_PDPHY_WRITE_CMD                           0x0230
#define CS32G050_HMI_PDPHY_READ_CMD                            0x0231
#define CS32G050_HMI_PDPHY_WRITE_LEN_FOR_WRITE_CMD             9
#define CS32G050_HMI_PDPHY_WRITE_LEN_FOR_READ_CMD              2
#define CS32G050_HMI_PDPHY_READ_LEN_FOR_READ_CMD               6
#define CS32G050_HMI_PDPHY_DATA1_FOR_WRITE_CMD                 0x50
#define CS32G050_HMI_PDPHY_DATA2_FOR_WRITE_CMD                 0x06
#define CS32G050_HMI_PDPHY_DATA3_FOR_WRITE_CMD                 0x04
#define CS32G050_HMI_PDPHY_DATA1_FOR_READ_CMD                  0x5F
#define CS32G050_DPIN_ON_CMD                                   0x10
#define CS32G050_DPIN_OFF_CMD                                  0x0
#define CS32G050_PD_ROLE_SWAP_DATA0                            0x06
#define CS32G050_PD_ROLE_SWAP_DATA1                            0x04

#define DUAL_PD_CLASS_NAME                                     "dual_role_pd"
#define ATTR_POWER_ROLE       								   "power_role"
#define ATTR_DATA_ROLE        								   "data_role"
#define ATTR_PORT_MODE        								   "port_mode"
#define ATTR_SUPPORTED_MODE   								   "supported_mode"
#define STR_HIGH_SPEED   								       "high-speed"
#define STR_SUPER_SPEED   								       "super-speed"
#define STR_UNKNOWN_SPEED   								   "unknown-speed"

#define EIGHT_BIT                                              8
#define LOW_ONE_BYTE                                           0XFF
#define I2C_WRITE_LEN                                          7
#define I2C_DATA_MAX_LEN                                       32

#define PROCESS_IRQ_IN                                         0xA0
#define PROCESS_EARPHONE_IN                                    0xA1
#define PROCESS_EARPHONE_OUT                                   0xA2

#define PROCESS_CLEAN_IRQ_ERROR                                0xE0
#define PROCESS_WRITE_REQUEST_ERROR                            0xE1
#define PROCESS_TYPE_INVALID                                   0xE2
#define PROCESS_NOTIFY_FAILED                                  0xE3

#define PROCESS_READ_PORT_ERROR                                0xFF

#ifdef CONFIG_DFX_DEBUG_FS
#define PD_INIT_FLAG        0
#define NO_NEED_PD_FLAG     1
 
#define use_pd_flag_debugfs_create_x32(flag, dispatcher_) \
	debugfs_create_x32(#flag, 0644, (dispatcher_)->debug_dir, &(dispatcher_)->use_pd_flag)
#endif /* CONFIG_DFX_DEBUG_FS */

union cs32g050_reg_data {
	u64 data;
	u8 u8_data[I2C_WRITE_LEN];
};

enum cs32g050_event_notify_type {
	IRQ_HPD_IN_AND_DP_MODE_AND_DP_IN = 0,
	IRQ_HPD_IN_AND_DP_MODE_AND_HOST_IN = 1,
	IRQ_HPD_IN_AND_USB31_MODE_AND_HOST_IN = 2,
	IRQ_HPD_IN_AND_USB31_MODE_AND_DEVICE_IN = 3,
	IRQ_HPD_IN_AND_USB31DP_MODE_AND_HOST_IN = 4,
	IRQ_SHORT_HPD_AND_DP_MODE_AND_DP_IN = 5,
	IRQ_HPD_OUT_AND_DP_MODE_AND_DP_OUT = 6,
	IRQ_HPD_OUT_AND_NC_MODE_AND_HOST_OUT = 7,
	IRQ_HPD_OUT_AND_NC_MODE_AND_DEVICE_OUT = 8,
	IRQ_HPD_OUT_AND_USB31_MODE_AND_HOST_OUT = 9,
	IRQ_HPD_OUT_AND_USB31_MODE_AND_DEVICE_OUT = 10,
};

struct cs32g050_dispatcher {
	atomic_t ref;
	struct list_head node;
	struct list_head dev_list;
	int gpio;
	int irq;
	struct workqueue_struct *wq;
	struct work_struct work;
	struct i2c_client *client;
	#ifdef CONFIG_DFX_DEBUG_FS
	struct dentry *debug_dir;
	u32 use_pd_flag;
	#endif /* CONFIG_DFX_DEBUG_FS */
};

struct cs32g050_port_device {
	struct list_head node;
	struct i2c_client *client;
	struct device *dev;
	struct cs32g050_dispatcher *dispatcher;
	struct delayed_work fw_update_work;
	int port_id;
	int first_update_addr;
	int firmware_update_delay;
	int firmware_update_mode;
	u64 last_port_status;
	bool plug_orien;
};

int cs32g050_get_dp_status(void);
u64 *cs32g050_get_g_last_port_status(void);

#endif