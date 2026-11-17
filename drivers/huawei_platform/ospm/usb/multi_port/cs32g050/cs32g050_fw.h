/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * cs32g050_fw.h
 *
 * cs32g050 firmware update
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

#ifndef CS32G050_FW_H
#define CS32G050_FW_H

#include <huawei_platform/log/hw_log.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/platform_device.h>
#include <linux/platform_drivers/usb/tca.h>
#include <linux/time.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <securec.h>
#include <stdbool.h>
#include <uapi/asm-generic/fcntl.h>
#include <linux/mutex.h>

#define HWLOG_TAG cs32g050
HWLOG_REGIST();

#define CS32G050_CRC_INIT_VALUE                                         0x0000
#define CS32G050_CRC_POLICY_VALUE                                       0x11021
#define CS32G050_FIRMWARE_VERSION_DEFAULT                               0x00011915
#define CS32G050_BIN_FILE_PATH_1                     "/chip_prod/etc/firmware/cs32g050_firmware/app0.bin"
#define CS32G050_BIN_FILE_PATH_2                     "/chip_prod/etc/firmware/cs32g050_firmware/app1.bin"
#define CS32G050_CRC_SEND_BACK_DEFAULT_VALUE                            0
#define CS32G050_PING_STA_COMPLETE                                      0x01
#define CS32G050_PING_STA_CRC_ERR                                       0x02
#define CS32G050_PING_STA_ERROR                                         0x03
#define CS32G050_PING_STA_FLAG                                          0x03
#define CS32G050_PING_STA_HIGH_VALUE_OFFSET                             2
#define CS32G050_GET_IC_STATUS                                          0x3A, 0x03, 0x00, 0x00
#define CS32G050_GET_IC_STATUS_BUF_LEN                                  5
#define CS32G050_GET_INFO                                               0x80
#define CS32G050_CMD_MCU_CTRL                                           0x01, 0x03, 0xDA, 0x0B
#define CS32G050_CMD_MCU_CTRL_LEN                                       5
#define CS32G050_CMD_CTRL_FLASH_INIT                                    0x03
#define CS32G050_CMD_FLASH_WRITE                                        0x13
#define CS32G050_CMD_VALIDATION                                         0x16, 0x01, 0x01
#define CS32G050_CMD_VALIDATION_LEN                                     3
#define CS32G050_CMD_RESET_TO_FLASH                                     0x05, 0x03, 0xDA, 0x0B, 0x01
#define CS32G050_MCU_REBOOT_BUF_LEN                                     5
#define CS32G050_BANK_PARTITION_A                                       1
#define CS32G050_BANK_PARTITION_B                                       2
#define CS32G050_BANK_PARTITION_INDEX                                   2
#define CS32G050_FAIL_TIMES_INDEX                                   	11
#define CS32G050_FAIL_TIMES_MAX		                                  	5
#define CS32G050_FAIL_TIMES_DEFAULT_VALUE	                            0xFF
#define CS32G050_FW_BLOCK_SIZE                                          0x1D
#define CS32G050_MAX_RETRY_TIME                                         5
#define CS32G050_PING_RET_NUM                                           2
#define CS32G050_SHORT_SLEEP                                            50
#define CS32G050_LONG_SLEEP                                             600
#define CS32G050_REBOOT_SLEEP                                           4000
#define CS32G050_IC_STATUS_LEN                                          11
#define CS32G050_BYTE_LENGTH                                            8
#define CS32G050_UINT8_LENGTH                                           8
#define CS32G050_UINT16_LENGTH                                          16
#define CS32G050_UPDATE_FLASH_BLOCK_DELAY                               10
#define CS32G050_I2C_MSG_LEN                                            1
#define CS32G050_I2C_PING_BUF_LEN                                       1
#define CS32G050_I2C_STATUS_INFO_LEN                                    1
#define CS32G050_BLOCK_DATA_HEADER_LEN                                  5
#define CS32G050_BLOCK_DATA_INFO_LEN                                    3
#define CS32G050_CRC16_CALCULATE_VALUE                                  0x8000
#define CS32G050_APP_VERSION0_INDEX                                     7
#define CS32G050_APP_VERSION1_INDEX                                     8
#define CS32G050_APP_VERSION2_INDEX                                     9
#define CS32G050_APP_VERSION3_INDEX                                     10
#define CS32G050_APP_VERSION3_MOVED_BITS                                24
#define CS32G050_APP_VERSION2_MOVED_BITS                                16
#define CS32G050_APP_VERSION1_MOVED_BITS                                8
#define CS32G050_DATA_CRC_HIGH_INDEX                                    2
#define CS32G050_DATA_CRC_LOW_INDEX                                     3
#define CS32G050_INFO_CRC_HIGH_INDEX                                    1
#define CS32G050_INFO_CRC_LOW_INDEX                                     2
#define CS32G050_FILE_SIZE_MAX                                          (126 * 1024)
#define CS32G050_I2C_MAX_LEN        (CS32G050_BLOCK_DATA_HEADER_LEN + CS32G050_FW_BLOCK_SIZE)
#define MAX_LEN_512                                                     512
#define INDEX_0                                                     	0
#define INDEX_1                                                     	1
#define INDEX_2                                                     	2
#define INDEX_3                                                     	3
#define INDEX_4                                                     	4
#define INDEX_5                                                     	5
#define INDEX_6                                                     	6
#define INDEX_7                                                     	7
#define INDEX_8                                                     	8
#define INDEX_9                                                     	9
#define INDEX_10                                                     	10
#define INDEX_11                                                     	11

#ifndef MUTEX_CS32
#define MUTEX_CS32
extern struct mutex cs32g050_mutex;
#endif

struct update_para {
	uint8_t *bin_file1;
	uint8_t *bin_file2;
	uint8_t delay;
	uint8_t crc_check_enable;
	int force_upgrade;
	int bin_file1_size;
	int bin_file2_size;
	int firmware_version;
	int firmware_first_version;
};

int cs32g050_update(int portid, struct i2c_client *client, struct device_node *node, bool boot_mode);
int cs32g050_fw_reboot_unattach(int portid, struct i2c_client *client);
#endif // CS32G050_FW_H
