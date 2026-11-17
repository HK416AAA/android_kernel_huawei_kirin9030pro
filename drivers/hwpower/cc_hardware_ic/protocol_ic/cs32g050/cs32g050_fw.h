/* SPDX-License-Identifier: GPL-2.0 */
/*
 * cs32g050_fw.c
 *
 * cs32g050 firmware update
 *
 * Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
 *
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

#include "cs32g050.h"

#define CS32G050_CRC_INIT_VALUE                            0x0000
#define CS32G050_CRC_POLY_VALUE                            0x1021
#define CS32G050_CRC_CALC_VALUE                            0x8000
#define CS32G050_FIRMWARE_UPDATE_DELAY                     5000
#define CS32G050_FW_UPDATE_RETRY_CNT                       3
#define CS32G050_FW_UPDATE_RETRY_COUNT                     15
#define CS32G050_FIRMWARE_VERSION_DEFAULT                  0x00011915
#ifdef CONFIG_CHARGER_OHOS
#define CS32G050_BIN_FILE_PATH_1                           "/chip_prod/etc/firmware/cs32g050_firmware/app0.bin"
#define CS32G050_BIN_FILE_PATH_2                           "/chip_prod/etc/firmware/cs32g050_firmware/app1.bin"
#else
#define CS32G050_BIN_FILE_PATH_1                           "/odm/etc/firmware/cs32g050_firmware/app0.bin"
#define CS32G050_BIN_FILE_PATH_2                           "/odm/etc/firmware/cs32g050_firmware/app1.bin"
#endif /* CONFIG_CHARGER_OHOS */
#define CS32G050_GET_INFO                                  0x80
#define CS32G050_CMD_MCU_CTRL                              0x01, 0x03, 0xDA, 0x0B
#define CS32G050_CMD_MCU_CTRL_LEN                          5
#define CS32G050_CMD_CTRL_FLASH_INIT                       0x03
#define CS32G050_CMD_FLASH_WRITE                           0x13
#define CS32G050_CMD_VALIDATION                            0x16, 0x01, 0x01
#define CS32G050_CMD_VALIDATION_LEN                        3
#define CS32G050_CMD_RESET_TO_FLASH                        0x05, 0x03, 0xDA, 0x0B, 0x01
#define CS32G050_MCU_REBOOT_BUF_LEN                        5
#define CS32G050_BANK_PARTITION_A                          1
#define CS32G050_BANK_PARTITION_B                          2
#define CS32G050_FW_BLOCK_SIZE                             29
#define CS32G050_MAX_RETRY_TIME                            5
#define CS32G050_SHORT_SLEEP                               50
#define CS32G050_LONG_SLEEP                                600
#define CS32G050_VALIDATION_SLEEP                          5000
#define CS32G050_REBOOT_SLEEP                              4000
#define CS32G050_BLOCK_DATA_HEADER_LEN                     5
#define CS32G050_BLOCK_DATA_INFO_LEN                       3
#define CS32G050_FILE_SIZE_MAX                             (126 * 1024)
#define CS32G050_I2C_MAX_LEN                               (CS32G050_BLOCK_DATA_HEADER_LEN + CS32G050_FW_BLOCK_SIZE)
#define MAX_LEN_512                                        512

int cs32g050_fw_update(struct cs32g050_device_info *di);
int cs32g050_fw_reboot_unattach(struct cs32g050_device_info *di);
int cs32g050_fw_param_init(struct cs32g050_device_info *di);
#endif /* CS32G050_FW_H */
