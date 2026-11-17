/*
 * Huawei freetouch api
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

#ifndef __HUAWEI_TOUCHPAD_FW_UPDATE_IMPL_H__
#define __HUAWEI_TOUCHPAD_FW_UPDATE_IMPL_H__

#define HW_FREETOUCH_FW_VERSION_LENTH	8
#define HW_FREETOUCH_FW_MCU_VERSION_LEN	4
#define FEATURE_CODE_LEN				3
#define TOUCHPAD_CMD_PKG_LEN			256

#define MAIN_BIN	0
#define BTL_BIN		0x12
#define SLAVE_BIN	1

#define BTL_UPDATE_SIGN 4

#define MCU_VERSION_OLD_SIZE	5

struct fw_version {
	u8 report_id;
	u8 version[HW_FREETOUCH_FW_VERSION_LENTH];
} __attribute__((packed));

struct touchpad_cmd_pkg {
	uint16_t len;
	uint8_t report_id;
	uint8_t cmd_id;
	uint8_t cmd_dir;
	uint16_t total_pkg;
	uint16_t current_pkg;
	uint8_t buf[TOUCHPAD_CMD_PKG_LEN];
} __attribute__((packed));

int set_fw_feature_code(const u8 *feature_code, int len);

int touchpad_update_mcu_fw(struct hid_device *hid, const u8 *fw_data, u32 fw_len, int type, int mcu_status_gpio);

int touchpad_get_mcu_fw_version(struct hid_device *hdev, struct fw_version *ver);

int touchpad_get_package_version(const u8 *fw_data, u32 fw_len, struct fw_version *ver);

int hid_dev_match(struct device *dev, const void *data);
int touchpad_sync_time(struct i2c_client *client, uint64_t time);

#endif
