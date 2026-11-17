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

#include <linux/i2c.h>
#include <linux/hid.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <securec.h>
#include "touchpad_log.h"
#include "touchpad_api.h"

#define MAIN_BOOT_MODE_VAL	1
#define MAIN_APP_MODE_VAL	2
#define SLAVE_BOOT_MODE_VAL	3
#define SLAVE_APP_MODE_VAL	4

#define BOOTLOADER_CMD		0x7

#define GPIO_LOW			0
#define GPIO_TIMEOUT_CODE	-110

#define HW_UPDATA_LEN					1024
#define HW_XINHAI_UPDATA_LEN			128
#define HW_COMMEND_CALL_BACK_TIMEOUT	1000
#define HW_UPDATE_CALL_BACK_TIMEOUT		5000
#define HW_UPDATE_LAST_PACKAGE_TIMEOUT	10000
#define HW_UPLOAD_PACKEAGE_TIMES		3
#define HW_CMD_REPLY_LEN				64
#define HW_TOUCHPAD_WAIT_DATA_READY		500

#define BTL_GO_APP_COMMAND					0xff
#define SEND_BIN_CMD_REPORT_ID				0x0a
#define CHECK_COMMAND_REPORT_ID				0x09
#define SEND_COMMEND_REPORT_ID				0x08
#define UPGRADE_UPLOAD_PACKAGE_REPORT_ID	0x04
#define COMMEND_CALLBACK_REPORT_ID			0x16
#define UPGRADE_UPLOAD_PACKAGE_CALLBACK_ID	0x32
#define GET_FW_VERSION_REPORT_ID			0x17
#define TOUCHPAD_SET_TIME_REPORT_ID			0x64

enum boot_mode {
	GO_BOOT = 0,
	GO_APP = 1
};

enum reply_result {
	ACK = 0,
	NACK = 1,
	STANDBY = 255,
};

union cmd_reply_t {
	u8 data[HW_CMD_REPLY_LEN];
	struct {
		__le16 data_reg;
		u8 report_id;
		u8 cmd_id;
		u8 result;
	} __packed c;
};

union command_t {
	u8 data[0];
	struct {
		u8 report_id;
		u8 cmd_id;
		u8 cmd_val;
	} __packed c;
};

union cmd_check_t {
	u8 data[0];
	struct {
		u8 report_id;
		u8 cmd_id;
		u16 cmd_val;
	} __packed tp;
};

struct update_package {
	__le16 report_id;
	u8 feature_code[FEATURE_CODE_LEN];
	__le16 total_pkg_num;
	__le16 pkg_idx;
	u8 update_data[HW_UPDATA_LEN];
	__le16 crc;
} __packed;

static u8 g_feature_code[FEATURE_CODE_LEN];
static int g_mcu_status_gpio = -1;

static int query_total_package_num(int fw_size, int type)
{
	int len = (type == MAIN_BIN ? HW_UPDATA_LEN : HW_XINHAI_UPDATA_LEN);
	if (type == BTL_BIN) {
		len = HW_UPDATA_LEN;
	}
	return (fw_size % len == 0) ? (fw_size / len) : (fw_size / len + 1);
}

static int get_boot_cmd_value(int type, int mode)
{
	if (type == MAIN_BIN) {
		return mode == GO_BOOT ? MAIN_BOOT_MODE_VAL : MAIN_APP_MODE_VAL;
	} else if (type == BTL_BIN) {
		return mode == GO_BOOT ? type : BTL_GO_APP_COMMAND;
	} else {
		return mode == GO_BOOT ? SLAVE_BOOT_MODE_VAL : SLAVE_APP_MODE_VAL;
	}
}

static int wait_gpio_status(int gpio, int status, int wait_time)
{
	int times;
	const int schedule_time = 10;

	for (times = 0; times < wait_time; times += schedule_time) {
		if (gpio_get_value(gpio) == status)
			return 0;

		msleep(schedule_time);
	}

	return -ETIMEDOUT;
}

static int check_reply_result(struct i2c_client *client, u8 cmd_id, int wait_time)
{
	int ret;
	union cmd_reply_t reply;
	if (!client)
		return -EINVAL;

	ret = wait_gpio_status(g_mcu_status_gpio, GPIO_LOW, wait_time);
	if (ret)
		return ret;
	
	ret = i2c_master_recv(client, reply.data, sizeof(reply));
	if (ret != sizeof(reply)) {
		tp_log_err("recv reply data failed, ret: %d", ret);
		return -EIO;
	}

	if (reply.c.report_id != COMMEND_CALLBACK_REPORT_ID || reply.c.cmd_id != cmd_id || reply.c.result != ACK) {
		tp_log_err("invalid reply, report_id: 0x%x, cmd_id: 0x%x, result: %d\n",
			reply.c.report_id, reply.c.cmd_id, reply.c.result);
		return -EIO;
	}

	return 0;
}

static int send_command(struct hid_device *hdev, union command_t *cmd, int wait_time)
{
	int ret;

	if (!hdev || !hdev->driver_data || !cmd)
		return -EINVAL;

	if (wait_time < HW_COMMEND_CALL_BACK_TIMEOUT)
		wait_time = HW_COMMEND_CALL_BACK_TIMEOUT;

	ret = hid_hw_raw_request(hdev, cmd->c.report_id, cmd->data, sizeof(union command_t),
		HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
	if (ret != sizeof(union command_t))
		return -EIO;

	return check_reply_result(hdev->driver_data, cmd->c.cmd_id, wait_time);
}

static int send_bootloader_cmd(struct hid_device *hdev, int type, int mode)
{
	union command_t cmd;
	int ret;
	int retry_idx;

	if (!hdev)
		return -EINVAL;

	if (mode != GO_BOOT && mode != GO_APP) {
		tp_log_err("%s failed, mode: %d\n", __func__, mode);
		return -EINVAL;
	}

	if (type == BTL_BIN) {
		cmd.c.report_id = SEND_BIN_CMD_REPORT_ID;
	} else {
		cmd.c.report_id = SEND_COMMEND_REPORT_ID;
	}
	cmd.c.cmd_id = BOOTLOADER_CMD;
	cmd.c.cmd_val = get_boot_cmd_value(type, mode);

	for (retry_idx = 0; retry_idx < HW_UPLOAD_PACKEAGE_TIMES; retry_idx++) {
		ret = send_command(hdev, &cmd, HW_COMMEND_CALL_BACK_TIMEOUT);
		if (!ret) {
			tp_log_info("enter mode(0-boot/1-app): %d ok", mode);
			break;
		}
		tp_log_err("enter mode(0-boot/1-app): %d failed, ret: %d, retry: %d", mode, ret, retry_idx);
		/* if failed, delay more time for touchpad ready */
		msleep(HW_TOUCHPAD_WAIT_DATA_READY * (retry_idx + 1));
	}

	return ret;
}

static u16 update_crc16(u16 crc_in, u8 byte)
{
	u32 crc = crc_in;
	u32 in = byte | 0x100;

	do {
		crc <<= 1;
		in <<= 1;
		if (in & 0x100)
			++crc;

		if (crc & 0x10000)
			crc ^= 0x1021;
	} while (!(in & 0x10000));

	return crc & 0xffffu;
}

static u16 cal_crc16(const u8 *p_data, u32 size)
{
	u32 crc = 0;
	if (!p_data) {
		tp_log_err("calculate check err, invalid value");
		return 0;
	}

	const u8 *end = p_data + size;

	while (p_data < end)
		crc = update_crc16(crc, *p_data++);

	crc = update_crc16(crc, 0);
	crc = update_crc16(crc, 0);

	return crc & 0xFFFFU;
}

// 校验tp整包数据完整性
u16 verify_fullpkg_signature(const u8 *fw_data, u32 len)
{
	u32 i;
	u16 ret = 0;

	if (!fw_data || len < 0) {
		tp_log_err("check full pkg err, invalid value");
		return ret;
	}

	for (i = 0; i < len; i++) {
		ret += fw_data[i];
	}

	if (len % HW_UPDATA_LEN != 0) {
		for (i = len % HW_UPDATA_LEN; i < HW_UPDATA_LEN; i++) { // 数据包必须满足1k的整数
			ret += 0xff;
		}
	}
	return ret;
}

static int update_set_package(struct update_package *package, int idx, int total_pkg,
	const u8 *fw_data, int fw_size, int type)
{
	int ret;
	int update_len;
	if (!fw_data || !package)
		return -EINVAL;

	package->report_id = UPGRADE_UPLOAD_PACKAGE_REPORT_ID;
	package->feature_code[0] = g_feature_code[0];
	package->feature_code[1] = g_feature_code[1];
	package->feature_code[2] = g_feature_code[2];
	package->total_pkg_num = total_pkg;
	package->pkg_idx = idx;

	ret = memset_s(package->update_data, HW_UPDATA_LEN, 0xff, HW_UPDATA_LEN);
	if (ret)
		tp_log_err("memset_s failed, ret: %d", ret);

	if (type == MAIN_BIN || type == BTL_BIN)
		update_len = HW_UPDATA_LEN;
	else
		update_len = HW_XINHAI_UPDATA_LEN;

	if (fw_size >= (update_len * (idx + 1))) {
		ret = memcpy_s(package->update_data, sizeof(package->update_data), fw_data + update_len * idx, update_len);
	} else {
		ret = memcpy_s(package->update_data, sizeof(package->update_data),
			fw_data + update_len * idx, fw_size - (update_len * idx));
	}

	if (ret) {
		tp_log_err("memcpy_s failed, ret: %d", ret);
		return -EIO;
	}
	package->crc = cal_crc16((const u8 *)package->update_data, HW_UPDATA_LEN * sizeof(u8));
	return 0;
}

static int deliver_one_package(struct i2c_client *client, struct update_package *package, bool last_pkg)
{
	int retry_idx;
	int ret;
	int wait_time;

	if (!client || !package)
		return -EINVAL;

	for (retry_idx = 0; retry_idx < HW_UPLOAD_PACKEAGE_TIMES; retry_idx++) {
		ret = i2c_master_send(client, (u8 *)package, sizeof(struct update_package));
		if (ret != sizeof(struct update_package)) {
			ret = -EIO;
			msleep(100);
			continue;
		}

		if (unlikely(last_pkg))
			wait_time = HW_UPDATE_LAST_PACKAGE_TIMEOUT;
		else
			wait_time = HW_UPDATE_CALL_BACK_TIMEOUT;

		ret = check_reply_result(client, UPGRADE_UPLOAD_PACKAGE_CALLBACK_ID, wait_time);
		if (ret == GPIO_TIMEOUT_CODE) {
			tp_log_err("send package gpio time out, continue to send next");
			return 0;
		}
		if (ret) {
			tp_log_err("check reply failed, ret: %d, retry: %d\n", ret, retry_idx);
			continue;
		}

		return 0;
	}
	return ret;
}

static int deliver_packages(struct i2c_client *client, int total_pkg, const u8 *fw_data, u32 fw_size, int type)
{
	int ret = 0;
	int pkg_idx;
	struct update_package package;

	if (!client || !fw_data)
		return -EINVAL;

	for (pkg_idx = 0; pkg_idx < total_pkg - 1; pkg_idx++) {
		(void)update_set_package(&package, pkg_idx, total_pkg, fw_data, fw_size, type);
		if (type == BTL_BIN) {
			msleep(10); /* wait 10ms for mcu ready per package. mcu pkg not need */
		}
		ret = deliver_one_package(client, &package, false);
		if (ret) {
			tp_log_err("deliver package %d failed, ret: %d\n", pkg_idx, ret);
			break;
		}
	}

	if (!ret) {
		(void)update_set_package(&package, pkg_idx, total_pkg, fw_data, fw_size, type);
		ret = deliver_one_package(client, &package, true);
		if (ret)
			tp_log_err("deliver last package failed, ret: %d\n", ret);
	}
	return ret;
}

// tp升级总包校验
int touchpad_tp_fullpkg_check(struct hid_device *hdev, const u8 *fw_data, u32 fw_size)
{
	tp_log_info("start to check full package");
	union cmd_check_t cmd;
	union cmd_reply_t reply;
	int ret = -1;

	if (!hdev || !fw_data)
		return -EINVAL;

	cmd.tp.report_id = CHECK_COMMAND_REPORT_ID;
	cmd.tp.cmd_id = BOOTLOADER_CMD;
	cmd.tp.cmd_val = verify_fullpkg_signature(fw_data, fw_size);

	// 发送校验和
	ret = hid_hw_raw_request(hdev, CHECK_COMMAND_REPORT_ID, cmd.data, sizeof(union cmd_check_t),
		HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
	if (ret != sizeof(union cmd_check_t)) {
		tp_log_err("check full package wrong: send error");
	}

	ret = wait_gpio_status(g_mcu_status_gpio, GPIO_LOW, HW_COMMEND_CALL_BACK_TIMEOUT);
	if (ret) {
		tp_log_err("check full package wrong: wait gpio error");
		return ret;
	}

	// 接收数据
	ret = i2c_master_recv(hdev->driver_data, reply.data, sizeof(reply));
	if (ret != sizeof(reply)) {
		tp_log_err("recv reply data failed, ret: %d", ret);
		return -EIO;
	}
	tp_log_err("check full package reply: report_id: 0x%x, cmd_id: 0x%x, result: %d\n",
		reply.c.report_id, reply.c.cmd_id, reply.c.result);

	return 0;

}

int touchpad_update_mcu_fw(struct hid_device *hdev, const u8 *fw_data, u32 fw_size, int type, int mcu_status_gpio)
{
	int ret;
	int total_pkg_num;
	int retry_idx;

	if (!hdev || !hdev->driver_data || !fw_data || !fw_size || !gpio_is_valid(mcu_status_gpio))
		return -EINVAL;

	if (type != MAIN_BIN && type != SLAVE_BIN && type != BTL_BIN)
		return -EINVAL;

	g_mcu_status_gpio = mcu_status_gpio;
	ret = send_bootloader_cmd(hdev, type, GO_BOOT);
	if (ret) {
		tp_log_err("enter boot mode failed, ret: %d\n", ret);
		return ret;
	}

	// wait 50ms for mcu ready
	msleep(50);
	total_pkg_num = query_total_package_num(fw_size, type);
	tp_log_info("total_pkg_num: %d\n", total_pkg_num);
	// update start
	for (retry_idx = 0; retry_idx < HW_UPLOAD_PACKEAGE_TIMES; retry_idx++) {
		ret = deliver_packages(hdev->driver_data, total_pkg_num, fw_data, fw_size, type);
		if (ret)
			tp_log_err("deliver packages failed, ret: %d, retry: %d\n", ret, retry_idx);
		else {
			tp_log_info("deliver packages success!");
			break;
		}
	}
	
	if (type == BTL_BIN) {
		touchpad_tp_fullpkg_check(hdev, fw_data, fw_size);
	}
	/* wait for all package is received */
	msleep(HW_TOUCHPAD_WAIT_DATA_READY);
	ret = send_bootloader_cmd(hdev, type, GO_APP);
	if (ret) {
		tp_log_err("back to app mode failed, ret: %d\n", ret);
		return ret;
	}
	return 0;
}

int touchpad_get_mcu_fw_version(struct hid_device *hdev, struct fw_version *ver)
{
	int ret;

	if (!hdev || !ver)
		return -EINVAL;

	ret = hid_hw_raw_request(hdev, GET_FW_VERSION_REPORT_ID, (u8*)ver, sizeof(struct fw_version),
		HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
	if (ret != sizeof(struct fw_version)) {
		tp_log_err("mcu version size err, ret: %d, expected: %d", ret, sizeof(struct fw_version));
		if (ret == MCU_VERSION_OLD_SIZE) { // 兼容老版本version数据
			tp_log_info("old mcu version size, not err");
		} else {
			return -EIO;
		}
	}

	if (ver->report_id != GET_FW_VERSION_REPORT_ID)
		return -EFAULT;

	return 0;
}

int touchpad_get_package_version(const u8 *fw_data, u32 fw_len, struct fw_version *ver)
{
	int i;
	const u8 pkg_tag[] = {'F', 'r', 'e', 'e', 'T', 'o', 'u', 'c', 'h'};

	if (!fw_data || !ver || fw_len < sizeof(pkg_tag) + sizeof(ver->version))
		return -EINVAL;

	if (memcmp(pkg_tag, fw_data, sizeof(pkg_tag)) != 0)
		return -EINVAL;

	for (i = 0; i < sizeof(ver->version); i++)
		ver->version[i] = fw_data[sizeof(pkg_tag) + i];

	return 0;
}

int set_fw_feature_code(const u8 *feature_code, int len)
{
	int i;

	if (!feature_code || len != FEATURE_CODE_LEN)
		return -EINVAL;

	for (i = 0; i < FEATURE_CODE_LEN; i++)
		g_feature_code[i] = feature_code[i];

	tp_log_info("feature code: [0x%x, 0x%x, 0x%x]\n", feature_code[0], feature_code[1], feature_code[2]);
	return 0;
}

int touchpad_sync_time(struct i2c_client *client, uint64_t time)
{
	int ret;
	struct touchpad_cmd_pkg pkg;
	const uint8_t hid_head[] = {0x05, 0x00, 0x0F, 0x03, 0x64, 0x00, 0x00};
	uint8_t send_buf[sizeof(hid_head) + sizeof(struct touchpad_cmd_pkg)];

	if (client == NULL)
		return -EINVAL;

	pkg.len = sizeof(pkg);
	pkg.report_id = TOUCHPAD_SET_TIME_REPORT_ID;
	pkg.cmd_id = 0;
	pkg.cmd_dir = 0;
	pkg.total_pkg = 0;
	pkg.current_pkg = 0;

	ret = memcpy_s(pkg.buf, sizeof(pkg.buf), (uint8_t*)&time, sizeof(time));
	if (ret != EOK) {
		tp_log_err("copy time failed, ret: %d\n", ret);
		return ret;
	}

	ret = memcpy_s(send_buf, sizeof(send_buf), hid_head, sizeof(hid_head));
	if (ret != EOK) {
		tp_log_err("copy hid head failed, ret: %d\n", ret);
		return ret;
	}

	ret = memcpy_s(send_buf + sizeof(hid_head), sizeof(send_buf) - sizeof(hid_head), (uint8_t *)&pkg, sizeof(pkg));
	if (ret != EOK) {
		tp_log_err("copy pkg failed, ret: %d\n", ret);
		return ret;
	}

	ret = i2c_master_send(client, send_buf, sizeof(send_buf));
	if (ret != sizeof(send_buf))
		return -EREMOTEIO;

	return 0;
}