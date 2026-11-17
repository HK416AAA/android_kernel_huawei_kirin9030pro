/*
 * Huawei freetouch goodix ic firmware update
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

#include "goodix_firmware_update.h"
#include <linux/i2c.h>
#include <linux/delay.h>
#include <asm/unaligned.h>
#include <securec.h>
#include "touchpad_log.h"
#include "touchpad_tp_ic_update.h"

#define GOODIX_DELAY_MS			msleep
#define TP_LOG_PRINTF			tp_log_info

#define PKG_REPORT_ID			0x0E
#define PACKAGE_LEN				65
#define PACKAGE_WRITE_HEAD		8
#define GDIX_PRE_HEAD_LEN		5
#define GDIX_DATA_HEAD_LEN		5
#define GTX8_SUB_FW_DATA_OFFSET	256
#define FW_SUBSYS_INFO_OFFSET	32
#define RAM_BUFFER_SIZE			4096
#define FLASH_LOAD_CMD_HEAD		5
#define FLASH_LOAD_CMD_DATA		6

#define CMD_ADDR				0x60CC
#define BL_STATE_ADDR			0x5095
#define FLASH_BUFFER_ADDR		0xC000
#define FLASH_RESULT_ADDR		0x5096

#define CFG_START_ADDR			0x60DC

#define VERSION_ADDR			0x452C
#define VERSION_LEN				72
#define I2C_DIRECT_RW			0x20
#define FIRMFARE_FLAG			0x0C

#define GOODIX_PID_MAX_LEN		8
#define GOODIX_VID_MAX_LEN		4

/* 错误信息 */
enum {
	GOODIX_ERR_OK = 0,
	GOODIX_ERR_CHECK_VER,    /* check version failed */
	GOODIX_ERR_TRANSFER,     /* host_i2c_transfer 接口调用错误 */
	GOODIX_ERR_PKGLEN_OVER,  /* 包长度超出PACKAGE_LEN */
	GOODIX_ERR_READ_INDEX,   /* read_pkg 中取出包的 index错误 */
	GOODIX_ERR_READ_LEN,     /* read_pkg 中包的长度与预期不符 */
	GOODIX_ERR_CHECKSUM,     /* 校验错误 */
	GOODIX_ERR_CLOSE_REPORT, /* close report 错误 */
	GOODIX_ERR_STATE,        /* CFG更新中，ic状态错误 */
	GOODIX_ERR_UPDATE_FW,    /* 固件更新出错 */
	GOODIX_ERR_FW_CHECKSUM,  /* 固件check错误 */
	GOODIX_ERR_RESET,        /* reset ic 错误 */
	GOODIX_ERR_PTP_MODE,     /* 切换到ptp模式错误 */
};

struct goodix_ts_version {
	uint8_t pid[GOODIX_PID_MAX_LEN];
	uint8_t vid[GOODIX_VID_MAX_LEN];
	uint8_t cid;
	uint8_t sensor_id;
	uint8_t config_id;
} __packed;

struct firmware_info {
	uint32_t size;
	uint16_t checksum;
	uint8_t hw_pid[6];
	uint8_t hw_vid[3];
	uint8_t fw_pid[GOODIX_PID_MAX_LEN];
	uint8_t fw_vid[GOODIX_VID_MAX_LEN];
	uint8_t subsys_num;
	uint8_t chip_type;
	uint8_t protocol_ver;
	uint8_t reserved[2];
} __packed;

static bool g_update_config = false;
static bool g_update_fw = false;

static inline uint8_t checksum_u8(uint8_t *data, int len)
{
	uint8_t chksum = 0;
	int i;

	if (!data) {
		TP_LOG_PRINTF("check sum err, invalid value\n");
		return 0;
	}

	for (i = 0; i < len; i++)
		chksum += data[i];

	return chksum;
}

static int get_report(struct i2c_client *client, uint8_t *buf, uint8_t buf_len)
{
	int ret;
	int retry;
	int reply_index;
	uint8_t temp_buf[PACKAGE_LEN + 5]; // 5: Add 5 bytes, prevent out-of-bounds access in memcpy_s.
	const uint8_t recv_head_buf[] = { 0x05, 0x00, 0x1E, 0x02, 0x06, 0x00 };

	if (!client || !buf || !buf_len) {
		TP_LOG_PRINTF("get report err, invalid value\n");
		return -EINVAL;
	}

	ret = i2c_master_send(client, recv_head_buf, sizeof(recv_head_buf));
	if (ret != sizeof(recv_head_buf)) {
		TP_LOG_PRINTF("send recv head failed\n");
		return GOODIX_ERR_TRANSFER;
	}

	GOODIX_DELAY_MS(5);

	/* retry 3 times */
	for (retry = 0; retry < 3; retry++) {
		ret = i2c_master_recv(client, temp_buf, sizeof(temp_buf));
		if (ret != sizeof(temp_buf)) {
			TP_LOG_PRINTF("recv report failed, retry: %d\n", retry);
			GOODIX_DELAY_MS(5);
			continue;
		}

		/* find reply data start index */
		for (reply_index = 1; reply_index <= 3; reply_index++) {
			if (temp_buf[reply_index] != PKG_REPORT_ID)
				continue;

			ret = memcpy_s(buf, buf_len, &temp_buf[reply_index], PACKAGE_LEN);
			if (ret)
				TP_LOG_PRINTF("memcpy_s failed, ret: %d\n", ret);
			return ret;
		}
	}

	return GOODIX_ERR_TRANSFER;
}

static int hid_write_pkg(struct i2c_client *client, const uint8_t *buf, uint8_t len)
{
	int ret;
	/* system head */
	uint8_t pkg_buf[PACKAGE_WRITE_HEAD + PACKAGE_LEN] = { 0x05, 0x00, 0x2E, 0x03, 0x06, 0x00, 0x43, 0x00 };

	if (!client || !buf) {
		TP_LOG_PRINTF("write pkg err, invalid value\n");
		return -EINVAL;
	}

	if (len > PACKAGE_LEN)
		return GOODIX_ERR_PKGLEN_OVER;

	ret = memcpy_s(&pkg_buf[PACKAGE_WRITE_HEAD], PACKAGE_LEN, buf, len);
	if (ret) {
		TP_LOG_PRINTF("memcpy_s failed, ret: %d\n", ret);
		return ret;
	}

	ret = i2c_master_send(client, pkg_buf, sizeof(pkg_buf));
	if (ret != sizeof(pkg_buf))
		return GOODIX_ERR_TRANSFER;

	GOODIX_DELAY_MS(5);
	return GOODIX_ERR_OK;
}

static int hid_read_pkg(struct i2c_client *client, uint32_t addr, uint8_t *buf, uint8_t len)
{
	int ret;
	/* report_id, flag, has_follow_pkg, pkg_idx, header_len */
	uint8_t pkg_buf[PACKAGE_LEN] = { PKG_REPORT_ID, I2C_DIRECT_RW, 0, 0, 5 };
	uint32_t pkg_idx;

	if (!client || !buf) {
		TP_LOG_PRINTF("read pkg err, invalid value\n");
		return -EINVAL;
	}

	pkg_idx = 0;                        /* the get report pkg index should be 0 */
	pkg_buf[5] = 1;                     /* read operation flag */
	pkg_buf[6] = (addr >> 8) & 0xff;    /* addr high byte */
	pkg_buf[7] = addr & 0xff;           /* addr low byte */
	pkg_buf[8] = 0;                     /* len high byte */
	pkg_buf[9] = len & 0xff;            /* len low byte */

	ret = hid_write_pkg(client, pkg_buf, GDIX_PRE_HEAD_LEN + GDIX_DATA_HEAD_LEN);
	if (ret) {
		TP_LOG_PRINTF("write pkg failed, ret: %d\n", ret);
		return ret;
	}

	ret = get_report(client, pkg_buf, sizeof(pkg_buf));
	if (ret) {
		TP_LOG_PRINTF("fail to get report, ret: %d\n", ret);
		return ret;
	}

	if (pkg_idx != pkg_buf[3]) {
		TP_LOG_PRINTF("pkg_idx %d != pkg_buf[3](%d)\n", pkg_idx, pkg_buf[3]);
		return GOODIX_ERR_READ_INDEX;
	}

	if (pkg_buf[4] != len) {
		TP_LOG_PRINTF("Data length err: %d != %d\n", pkg_buf[4], len);
		return GOODIX_ERR_READ_LEN;
	}
	ret = memcpy_s(buf, pkg_buf[4], &pkg_buf[5], pkg_buf[4]);
	if (ret) {
		TP_LOG_PRINTF("memcpy_s failed, ret: %d\n", ret);
		return ret;
	}

	return GOODIX_ERR_OK;
}

static int goodix_hid_send_cmd(struct i2c_client *client, const uint8_t *buf, uint8_t len)
{
	if (!client || !buf) {
		TP_LOG_PRINTF("hid send cmd err, invalid value\n");
		return -EINVAL;
	}

	return hid_write_pkg(client, buf, len);
}

static int goodix_hid_write(struct i2c_client *client, uint32_t addr, const uint8_t *buf, uint32_t len)
{
	int ret;
	int retry;
	/* report_id, flag, has_follow_pkg, pkg_idx, header_len */
	uint8_t pkg_buf[PACKAGE_LEN] = { PKG_REPORT_ID, I2C_DIRECT_RW, 0, 0, 5 };
	uint8_t pkg_idx = 0;    /* pkg index need to send */
	uint32_t pos = 0;       /* the current send position */
	uint8_t trans_len = 0;  /* max size: 55 */

	if (!client || !buf || !len) {
		TP_LOG_PRINTF("hid write err, invalid value\n");
		return -EINVAL;
	}

	while (pos != len) {
		if (len - pos > PACKAGE_LEN - GDIX_PRE_HEAD_LEN - GDIX_DATA_HEAD_LEN) {
			/* data len more than 55, need to send with subpackages */
			trans_len = PACKAGE_LEN - GDIX_PRE_HEAD_LEN - GDIX_DATA_HEAD_LEN;
			pkg_buf[2] = 0x01; /* has follow package */
		} else {
			trans_len = len - pos;
			pkg_buf[2] = 0x00; /* last package */
		}

		pkg_buf[3] = pkg_idx++;                       /* set pkg index */
		pkg_buf[4] = trans_len + GDIX_DATA_HEAD_LEN;  /* set HID package length = data_len + GDIX_DATA_HEAD_LEN */
		pkg_buf[5] = 0;                               /* write operation flag */
		pkg_buf[6] = (addr >> 8) & 0xff;              /* addr high byte */
		pkg_buf[7] = addr & 0xff;                     /* addr low byte */
		pkg_buf[8] = 0;                               /* len high byte */
		pkg_buf[9] = trans_len;                       /* len low byte */
		ret = memcpy_s(&pkg_buf[GDIX_PRE_HEAD_LEN + GDIX_DATA_HEAD_LEN],
			PACKAGE_LEN - GDIX_PRE_HEAD_LEN - GDIX_DATA_HEAD_LEN, &buf[pos], trans_len);
		if (ret) {
			TP_LOG_PRINTF("memcpy_s failed, ret: %d\n", ret);
			return ret;
		}

		for (retry = 0; retry < 3; retry++) {
			ret = hid_write_pkg(client, pkg_buf, trans_len + GDIX_PRE_HEAD_LEN + GDIX_DATA_HEAD_LEN);
			if (!ret)
				break;

			GOODIX_DELAY_MS(10);
		}

		if (ret) {
			TP_LOG_PRINTF("Failed write data to addr=0x%x, len=%d,ret = %d\n", addr, trans_len, ret);
			return ret;
		}
		pos += trans_len;
		addr += trans_len;
	}
	return GOODIX_ERR_OK;
}

static int goodix_hid_write_reg(struct i2c_client *client, uint32_t addr, const uint8_t val)
{
	if (!client) {
		TP_LOG_PRINTF("hid write reg err, invalid value\n");
		return -EINVAL;
	}

	return goodix_hid_write(client, addr, &val, sizeof(uint8_t));
}

static int goodix_hid_read(struct i2c_client *client, const uint32_t addr, uint8_t *buf, uint32_t len)
{
	int i;
	int ret;
	int retry;
	int pkg_num;           /* the total pkg number need to seed */
	int left_len = len;    /* the left length to read */
	uint32_t cur_addr;     /* current read address */
	uint8_t read_len;      /* the length this step to read */
	const uint8_t pkg_size = PACKAGE_LEN - GDIX_PRE_HEAD_LEN - GDIX_DATA_HEAD_LEN; /* max pkg size: 55 */

	if (!client || !buf || !len) {
		TP_LOG_PRINTF("hid read err, invalid value\n");
		return -EINVAL;
	}

	pkg_num = left_len / pkg_size + 1;
	cur_addr = addr;
	read_len = pkg_size;
	for (i = 0; i < pkg_num; i++) {
		if (read_len > left_len)
			read_len = (uint8_t)left_len;
		/*read data*/
		for (retry = 0; retry < 3; retry++) {
			ret = hid_read_pkg(client, cur_addr, &buf[cur_addr - addr], read_len);
			if (!ret)
				break;

			GOODIX_DELAY_MS(10);
		}
		if (ret)
			return ret;

		cur_addr += read_len;
		left_len -= read_len;
			
		if (left_len <= 0)
			break;
	}
	return GOODIX_ERR_OK;
}

static int goodix_hid_read_reg(struct i2c_client *client, uint32_t addr, uint8_t *val)
{
	if (!client || !val) {
		TP_LOG_PRINTF("hid read reg err, invalid value\n");
		return -EINVAL;
	}

	return goodix_hid_read(client, addr, val, sizeof(uint8_t));
}

static int goodix_get_version(struct i2c_client *client, struct goodix_ts_version *version)
{
	int ret;
	uint8_t cfg_ver = 0;
	uint16_t checksum;
	uint8_t pkg_buf[VERSION_LEN];

	if (!client || !version) {
		TP_LOG_PRINTF("get version err, invalid value\n");
		return -EINVAL;
	}

	ret = goodix_hid_read(client, VERSION_ADDR, pkg_buf, VERSION_LEN);
	if (ret) {
		TP_LOG_PRINTF("Read version base failed, ret: %d\n", ret);
		return ret;
	}

	checksum = checksum_u8(pkg_buf, VERSION_LEN);
	if (checksum) {
		TP_LOG_PRINTF("Read version checksum error\n");
		return GOODIX_ERR_CHECKSUM;
	}

	ret = goodix_hid_read(client, CFG_START_ADDR, &cfg_ver, sizeof(cfg_ver));
	if (ret) {
		TP_LOG_PRINTF("Read config version failed\n");
		return ret;
	}

	ret = memcpy_s(version->pid, GOODIX_PID_MAX_LEN, pkg_buf + 9, GOODIX_PID_MAX_LEN); /* pid position */
	if (ret) {
		TP_LOG_PRINTF("cpy pid err, memcpy ret:%d\n", ret);
		return ret;
	}
	version->cid = pkg_buf[17]; /* cid position */
	ret = memcpy_s(version->vid, GOODIX_VID_MAX_LEN, pkg_buf + 17, GOODIX_VID_MAX_LEN); /* vid position */
	if (ret) {
		TP_LOG_PRINTF("cpy vid err, memcpy ret:%d\n", ret);
		return ret;
	}
	version->sensor_id = pkg_buf[21] & 0x0f; /* sensor id position */
	version->config_id = cfg_ver;

	return GOODIX_ERR_OK;
}

static int goodix_disable_report(struct i2c_client *client)
{
	int ret;
	int retry;
	const uint8_t disable_cmd[] = { 0x33, 0x00, 0xCD };
	const uint8_t confirm_cmd[] = { 0x35, 0x00, 0xCB };
	uint8_t buf[3] = { 0 }; /* CMD length is 3 */

	if (!client) {
		TP_LOG_PRINTF("disable report err, invalid value\n");
		return -EINVAL;
	}

	for (retry = 0; retry < 3; retry++) {
		ret = goodix_hid_write(client, CMD_ADDR, disable_cmd, sizeof(disable_cmd));
		if (ret == GOODIX_ERR_OK)
			break;

		GOODIX_DELAY_MS(10);
	}

	if (ret != GOODIX_ERR_OK) {
		TP_LOG_PRINTF("send close report cmd failed\n");
		return ret;
	}

	ret = goodix_hid_write(client, CMD_ADDR, confirm_cmd, sizeof(confirm_cmd));
	if (ret) {
		TP_LOG_PRINTF("send confirm cmd failed\n");
		return ret;
	}
	GOODIX_DELAY_MS(30);

	ret = goodix_hid_read(client, CMD_ADDR, buf, sizeof(buf));
	if (ret) {
		TP_LOG_PRINTF("read confirm flag failed\n");
		return ret;
	}

	/* close report code */
	if (buf[1] != 1) {
		TP_LOG_PRINTF("close report failed, flag[0x%02X]\n", buf[1]);
		return GOODIX_ERR_CLOSE_REPORT;
	}

	return GOODIX_ERR_OK;
}

static int goodix_check_reg_state(struct i2c_client *client, uint32_t addr, int state)
{
	uint8_t val = 0;
	int ret;
	int retry;

	if (!client) {
		TP_LOG_PRINTF("check reg state err, invalid value\n");
		return -EINVAL;
	}

	for (retry = 0; retry < 3; retry++) {
		ret = goodix_hid_read_reg(client, addr, &val);
		if (!ret && val == state)
			return GOODIX_ERR_OK;

		TP_LOG_PRINTF("wait ic state failed, addr: 0x%x, state: 0x%x, val: 0x%x, retry!\n",
			addr, state, val);
		GOODIX_DELAY_MS(1);
	}

	return GOODIX_ERR_STATE;
}

static int goodix_update_cfg(struct i2c_client *client, const uint8_t *cfg_data, int cfg_len)
{
	int ret;
	const uint8_t start_update_cfg_cmd[] = { 0x80, 0x0, 0x80 };

	if (!client || !cfg_data || cfg_len <= 0) {
		TP_LOG_PRINTF("update cfg err, invalid value\n");
		return -EINVAL;
	}

	TP_LOG_PRINTF("update config!\n");
	/* wait untill ic is free */
	ret = goodix_check_reg_state(client, CMD_ADDR, 0xff);
	if (ret) {
		TP_LOG_PRINTF("wait ic idle failed\n");
		return ret;
	}

	/* tell ic i want to send cfg */
	ret = goodix_hid_write(client, CMD_ADDR, start_update_cfg_cmd, sizeof(start_update_cfg_cmd));
	if (ret) {
		TP_LOG_PRINTF("failed send start update config cmd\n");
		return ret;
	}

	/* wait ic to confirm */
	GOODIX_DELAY_MS(250);

	ret = goodix_check_reg_state(client, CMD_ADDR, 0x82);
	if (ret) {
		TP_LOG_PRINTF("wait ic confirm failed\n");
		return ret;
	}

	/* start load config */
	ret = goodix_hid_write(client, CFG_START_ADDR, cfg_data, cfg_len);
	if (ret) {
		TP_LOG_PRINTF("Failed write cfg to xdata, ret=%d\n", ret);
		return ret;
	}
	GOODIX_DELAY_MS(1);

	/* tell ic cfg is ready in xdata */
	ret = goodix_hid_write_reg(client, CMD_ADDR, 0x83);
	if (ret) {
		TP_LOG_PRINTF("Failed write send cfg finish cmd\n");
		return ret;
	}

	/* check if ic is ok with the cfg */
	GOODIX_DELAY_MS(100);

	ret = goodix_check_reg_state(client, CMD_ADDR, 0xff);
	if (ret) {
		TP_LOG_PRINTF("check ic ok failed\n");
		return ret;
	}

	TP_LOG_PRINTF("update config success!\n");
	return GOODIX_ERR_OK;
}

static int check_sub_fw_flash_result(struct i2c_client *client, uint16_t len, uint32_t addr, uint16_t check_sum)
{
	int ret;
	uint8_t flash_load_cmd[FLASH_LOAD_CMD_HEAD + FLASH_LOAD_CMD_DATA] = { 0x0e, 0x12, 0x00, 0x00, 0x06 };

	if (!client) {
		TP_LOG_PRINTF("check sub fw flash err, invalid value\n");
		return -EINVAL;
	}

	flash_load_cmd[FLASH_LOAD_CMD_HEAD] = (len >> 8) & 0xFF;
	flash_load_cmd[FLASH_LOAD_CMD_HEAD + 1] = len & 0xFF;
	flash_load_cmd[FLASH_LOAD_CMD_HEAD + 2] = (addr >> 16) & 0xFF;
	flash_load_cmd[FLASH_LOAD_CMD_HEAD + 3] = (addr >> 8) & 0xFF;
	flash_load_cmd[FLASH_LOAD_CMD_HEAD + 4] = (check_sum >> 8) & 0xFF;
	flash_load_cmd[FLASH_LOAD_CMD_HEAD + 5] = check_sum & 0xFF;

	ret = goodix_hid_send_cmd(client, flash_load_cmd, sizeof(flash_load_cmd));
	if (ret) {
		TP_LOG_PRINTF("write load flash command failed, ret = %d\n", ret);
		return ret;
	}

	GOODIX_DELAY_MS(45); /* delay 90ms wait flash write ok */

	/* wait flash write ok */
	ret = goodix_check_reg_state(client, FLASH_RESULT_ADDR, 0xAA);
	if (ret) {
		TP_LOG_PRINTF("read flash result failed\n");
		return GOODIX_ERR_FW_CHECKSUM;
	}

	return GOODIX_ERR_OK;
}

static int load_sub_firmware(struct i2c_client *client, uint32_t flash_addr, const uint8_t *fw_data, uint32_t len)
{
	int i;
	int ret;
	uint16_t unitlen;
	uint16_t check_sum;
	uint32_t load_fw_offset = 0;

	if (!client || !fw_data) {
		TP_LOG_PRINTF("load sub fw err, invalid value\n");
		return -EINVAL;
	}

	while (load_fw_offset < len) {
		unitlen = (len - load_fw_offset > RAM_BUFFER_SIZE) ? RAM_BUFFER_SIZE : (len - load_fw_offset);

		for (check_sum = 0, i = 0; i < unitlen; i += 2) {
			check_sum += (fw_data[load_fw_offset + i] << 8) + fw_data[load_fw_offset + i + 1];
		}

		/* retry 3 times for package */
		for (i = 0; i < 3; i++) {
			ret = goodix_hid_write(client, FLASH_BUFFER_ADDR, &fw_data[load_fw_offset], unitlen);
			if (ret) {
				TP_LOG_PRINTF("goodix_hid_write failed, retry!\n");
				GOODIX_DELAY_MS(10);
				continue;
			}

			ret = check_sub_fw_flash_result(client, unitlen, flash_addr, check_sum);
			if (!ret)
				break;

			TP_LOG_PRINTF("check firmware flash result failed, retry!\n");
			GOODIX_DELAY_MS(10);
		}

		if (ret) {
			TP_LOG_PRINTF("load fw failed, len %d : addr 0x%x, ret=%d\n", unitlen, flash_addr, ret);
			return ret;
		}

		GOODIX_DELAY_MS(1);

		load_fw_offset += unitlen;
		flash_addr += unitlen;
		ret = goodix_hid_write_reg(client, FLASH_RESULT_ADDR, 0);
		if (ret) {
			TP_LOG_PRINTF("erase flash result reg failed, ret: %d\n", ret);
			return ret;
		}
	}

	return ret;
}

static bool is_skip_sub_firmware(uint32_t flash_addr)
{
	int i;
	const uint32_t skipped_flash_addr[] = { 0x0, 0x1000, 0x2000, 0xC000, 0xD000,
		0xE000, 0x10000, 0x12000, 0x13000, 0x17000, 0x18000 };

	for (i = 0; i < sizeof(skipped_flash_addr) / sizeof(skipped_flash_addr[0]); i++) {
		if (flash_addr == skipped_flash_addr[i])
			return true;
	}
	return false;
}

static int goodix_load_fwpkg(struct i2c_client *client, const uint8_t *fw_data, int fw_len)
{
	int i;
	int retry;
	int ret;
	uint8_t sub_fw_type;
	uint32_t sub_fw_flash_addr;
	uint32_t sub_fw_len;
	uint32_t sub_fw_info_pos = FW_SUBSYS_INFO_OFFSET;
	uint32_t fw_image_offset = GTX8_SUB_FW_DATA_OFFSET;

	if (!client || !fw_data) {
		TP_LOG_PRINTF("load fwpkg err, invalid value\n");
		return -EINVAL;
	}
	if (fw_len < sub_fw_info_pos || fw_len < fw_image_offset) {
		TP_LOG_PRINTF("fw_len not in range, return %d\n", GOODIX_ERR_READ_LEN);
		return GOODIX_ERR_READ_LEN;
	}

	for (i = 0; i < ((struct firmware_info *)fw_data)->subsys_num; i++) {
		/* sub_fw_type: 1 byte */
		sub_fw_type = fw_data[sub_fw_info_pos];
		sub_fw_info_pos += sizeof(sub_fw_type);
		/* sub_fw_len: 4 byte */
		sub_fw_len = (fw_data[sub_fw_info_pos] << 24) | (fw_data[sub_fw_info_pos + 1] << 16) |
					 (fw_data[sub_fw_info_pos + 2] << 8) | fw_data[sub_fw_info_pos + 3];
		sub_fw_info_pos += sizeof(sub_fw_len);
		/* sub_fw_flash_addr: 2 byte */
		sub_fw_flash_addr = (fw_data[sub_fw_info_pos] << 8) | fw_data[sub_fw_info_pos + 1];
		sub_fw_flash_addr = sub_fw_flash_addr << 8;
		sub_fw_info_pos += 3;

		if (!(FIRMFARE_FLAG & (0x01 << sub_fw_type)) || is_skip_sub_firmware(sub_fw_flash_addr)) {
			fw_image_offset += sub_fw_len;
			continue;
		}
		/* retry 3 times for every sub firmware */
		for (retry = 0; retry < 3; retry++) {
			ret = load_sub_firmware(client, sub_fw_flash_addr, &fw_data[fw_image_offset], sub_fw_len);
			if (!ret)
				break;

			TP_LOG_PRINTF("load sub firmware err, retry it!, ret=%d\n", ret);
			GOODIX_DELAY_MS(10);
		}
		if (ret) {
			TP_LOG_PRINTF("Failed load sub firmware, ret: %d, sub_fw_flash_addr: 0x%x\n",
				ret, sub_fw_flash_addr);
			return ret;
		}
		fw_image_offset += sub_fw_len;
	}
	return GOODIX_ERR_OK;
}

static int goodix_reset_ic(struct i2c_client *client)
{
	int ret;
	int retry;
	const uint8_t restart_cmd[] = { 0x0E, 0x13, 0x00, 0x00, 0x01, 0x01 }; /* restart cmd */
	const uint8_t switch_ptp_mode_cmd[] = { 0x03, 0x03, 0x00, 0x00, 0x01, 0x01 };

	if (!client) {
		TP_LOG_PRINTF("reset ic err, invalid value\n");
		return -EINVAL;
	}

	/* reset IC */
	TP_LOG_PRINTF("reset ic\n");
	for (retry = 0; retry < 3; retry++) {
		ret = goodix_hid_send_cmd(client, restart_cmd, sizeof(restart_cmd));
		if (!ret)
			break;

		GOODIX_DELAY_MS(20);
	}
	if (ret) {
		TP_LOG_PRINTF("failed to reset ic\n");
		return GOODIX_ERR_RESET;
	}

	GOODIX_DELAY_MS(350);

	if (goodix_hid_send_cmd(client, switch_ptp_mode_cmd, sizeof(switch_ptp_mode_cmd))) {
		TP_LOG_PRINTF("failed switch to ptp mode\n");
		return GOODIX_ERR_PTP_MODE;
	}

	return GOODIX_ERR_OK;
}

static int reset_mcu(struct i2c_client *client)
{
	int retry;
	const uint8_t mcu_reset_cmd[] = { "MCU_Reset" };

	if (!client) {
		TP_LOG_PRINTF("reset mcu err, invalid value\n");
		return -EINVAL;
	}

	for (retry = 0; retry < 3; retry++) {
		if (!goodix_hid_send_cmd(client, mcu_reset_cmd, sizeof(mcu_reset_cmd)))
			return GOODIX_ERR_OK;
	}

	return GOODIX_ERR_RESET;
}

static int goodix_switch_patch(struct i2c_client *client)
{
	int ret;
	const uint8_t switch_to_patch_cmd[] = { 0x0E, 0x10, 0x00, 0x00, 0x01, 0x01 };

	if (!client) {
		TP_LOG_PRINTF("switch patch err, invalid value\n");
		return -EINVAL;
	}

	ret = goodix_hid_send_cmd(client, switch_to_patch_cmd, sizeof(switch_to_patch_cmd));
	if (ret) {
		TP_LOG_PRINTF("Failed switch to patch\n");
		return ret;
	}

	return GOODIX_ERR_OK;
}

int goodix_check_version(struct i2c_client *client, const uint8_t *fw_data, int fw_len,
	const uint8_t *cfg_data, int cfg_len)
{
	int ret;
	struct goodix_ts_version fw_ver;
	struct firmware_info *fw_info = (struct firmware_info *)fw_data;

	if (!client || !fw_data || !fw_len || !cfg_data || !cfg_len)
		return -EINVAL;

	ret = goodix_get_version(client, &fw_ver);
	if (ret) {
		TP_LOG_PRINTF("failed to get version: ret: %d\n", ret);
		return ret;
	}

	TP_LOG_PRINTF("ic vid:[%d.%d.%d.%d], pkg vid:[%d.%d.%d.%d]\n",
		fw_ver.vid[0], fw_ver.vid[1], fw_ver.vid[2], fw_ver.vid[3],
		fw_info->fw_vid[0], fw_info->fw_vid[1], fw_info->fw_vid[2], fw_info->fw_vid[3]);
	/* check ic fw version */
	if (memcmp(fw_ver.vid, fw_info->fw_vid, GOODIX_VID_MAX_LEN))
		g_update_fw = true;

	TP_LOG_PRINTF("ic cfg_id: %d, fw cfg_id: %d\n", fw_ver.config_id, cfg_data[0]);
	/* check cfg version */
	if (fw_ver.config_id != cfg_data[0])
		g_update_config = true;

	if (g_update_fw || g_update_config)
		return GOODIX_ERR_OK;

	return GOODIX_ERR_CHECK_VER;
}

static int goodix_prepare_update(struct i2c_client *client)
{
	int ret;
	const uint8_t start_update_cmd[] = { 0x0E, 0x11, 0x00, 0x00, 0x01, 0x01 };

	if (!client) {
		TP_LOG_PRINTF("prepare update err, invalid value\n");
		return -EINVAL;
	}

	ret = goodix_disable_report(client);
	if (ret) {
		TP_LOG_PRINTF("disable report failed, ret: %d\n", ret);
		return ret;
	}

	ret = goodix_switch_patch(client);
	if (ret) {
		TP_LOG_PRINTF("switch patch failed, ret: %d\n", ret);
		return ret;
	}

	GOODIX_DELAY_MS(250);

	/* check state */
	ret = goodix_check_reg_state(client, BL_STATE_ADDR, 0xdd);
	if (ret) {
		TP_LOG_PRINTF("check bl state failed\n");
		return GOODIX_ERR_UPDATE_FW;
	}

	ret = goodix_disable_report(client);
	if (ret) {
		TP_LOG_PRINTF("re disable report failed, ret: %d\n", ret);
		return ret;
	}

	ret = goodix_hid_send_cmd(client, start_update_cmd, sizeof(start_update_cmd));
	if (ret) {
		TP_LOG_PRINTF("start update failed, ret: %d\n", ret);
		return ret;
	}

	return 0;
}

int goodix_update_fw(struct i2c_client *client, const uint8_t *fw_data, int fw_len,
	const uint8_t *cfg_data, int cfg_len)
{
	int ret;
	struct goodix_ts_version fw_ver;

	if (!client || !fw_data || fw_len <= 0 || !cfg_data || cfg_len <= 0)
		return -EINVAL;

	/* update config */
	if (g_update_config) {
		ret = goodix_update_cfg(client, cfg_data, cfg_len);
		if (ret)
			TP_LOG_PRINTF("cfg update error\n");
	}

	if (!g_update_fw) {
		TP_LOG_PRINTF("no need update fw\n");
		return GOODIX_ERR_OK;
	}

	ret = goodix_prepare_update(client);
	if (ret)
		goto err_reset_ic;

	GOODIX_DELAY_MS(10);

	/* load firmware */
	ret = goodix_load_fwpkg(client, fw_data, fw_len);
	if (ret)
		goto err_reset_ic;

err_reset_ic:
	if (goodix_reset_ic(client))
		TP_LOG_PRINTF("reset ic error\n");

	GOODIX_DELAY_MS(100);

	(void)goodix_get_version(client, &fw_ver);
	TP_LOG_PRINTF("ic vid after update:[%d.%d.%d.%d], config ver: %d\n",
		fw_ver.vid[0], fw_ver.vid[1], fw_ver.vid[2], fw_ver.vid[3], fw_ver.config_id);

	if (reset_mcu(client))
		TP_LOG_PRINTF("reset mcu error\n");

	return ret;
}