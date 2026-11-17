// SPDX-License-Identifier: GPL-2.0+
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

#include "cs32g050_fw.h"
#include "cs32g050_i2c.h"

#define HWLOG_TAG cs32g050_fw
HWLOG_REGIST();

static int cs32g050_fw_file_open(struct cs32g050_device_info *di, struct file **f_bin)
{
	char *path = NULL;

	if (di->ic_info.info.run_bank == CS32G050_BANK_PARTITION_A)
		path = CS32G050_BIN_FILE_PATH_2;
	else if (di->ic_info.info.run_bank == CS32G050_BANK_PARTITION_B)
		path = CS32G050_BIN_FILE_PATH_1;
	else
		return -EINVAL;

	*f_bin = filp_open(path, O_RDONLY, 0);
	if (IS_ERR(*f_bin)) {
		hwlog_err("%s filp open fail, err=%d\n", path, PTR_ERR(*f_bin));
		return -EINVAL;
	}

	if ((*f_bin)->f_inode->i_size > CS32G050_FILE_SIZE_MAX) {
		hwlog_err("file exceed the limit, f_bin size=%d, max_size=%d\n",
			(*f_bin)->f_inode->i_size, CS32G050_FILE_SIZE_MAX);
		filp_close(*f_bin, NULL);
		return -EINVAL;
	}

	hwlog_info("file open succ\n");
	return 0;
}

static u16 cs32g050_fw_crc_func(u8 *data, u8 size)
{
	u16 i, j;
	u16 crc = CS32G050_CRC_INIT_VALUE;

	for (i = 0; i < size; i++) {
		crc ^= (u16)(data[i] << POWER_BITS_PER_BYTE);
		for (j = 0; j < POWER_BITS_PER_BYTE; j++) {
			if (crc & CS32G050_CRC_CALC_VALUE)
				crc = (crc << 1) ^ CS32G050_CRC_POLY_VALUE;
			else
				crc = crc << 1;
		}
	}

	return crc;
}

int cs32g050_fw_param_init(struct cs32g050_device_info *di)
{
	char *bin_file = NULL;
	struct file *f_bin = NULL;
	mm_segment_t fs;
	loff_t pos = 0;

	if (cs32g050_fw_file_open(di, &f_bin)) {
		hwlog_err("fw file open fail\n");
		return -EINVAL;
	}

	di->fw_param.bin_size = f_bin->f_inode->i_size;
	bin_file = kzalloc(sizeof(u8) * di->fw_param.bin_size, GFP_KERNEL);
	if (!bin_file) {
		hwlog_err("bin_file alloc fail\n");
		goto file_alloc_err;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);
	if (vfs_read(f_bin, bin_file, di->fw_param.bin_size, &pos) != di->fw_param.bin_size) {
		hwlog_err("file read fail\n");
		goto check_size_err;
	}
	di->fw_param.bin_file = bin_file;

	set_fs(fs);
	filp_close(f_bin, NULL);

	hwlog_info("param init succ\n");
	return 0;

check_size_err:
	set_fs(fs);
	kfree(bin_file);
	bin_file = NULL;
file_alloc_err:
	filp_close(f_bin, NULL);
	return -EINVAL;
}

static int cs32g050_fw_set_mcu(struct cs32g050_device_info *di)
{
	u8 buf[CS32G050_CMD_MCU_CTRL_LEN] = { CS32G050_CMD_MCU_CTRL, CS32G050_CMD_CTRL_FLASH_INIT };
	u8 ping_ret_len = 0;
	int ret;

	ret = cs32g050_write_cmd_with_ping(di, buf, sizeof(buf), &ping_ret_len, CS32G050_LONG_SLEEP);
	if (ret) {
		hwlog_err("set mcu wait ping complete fail\n");
		return ret;
	}

	hwlog_info("set mcu succ\n");
	return 0;
}

static int cs32g050_fw_flash_firmware(struct cs32g050_device_info *di)
{
	int fw_len, i, ret;
	u8 *block = NULL;
	int page_len = 0;
	u16 crc_result;
	u8 ping_ret_len = 0;
	unsigned int ping_delay = CS32G050_LONG_SLEEP;

	block = kzalloc(sizeof(u8) *
		(CS32G050_FW_BLOCK_SIZE + CS32G050_BLOCK_DATA_HEADER_LEN), GFP_KERNEL);
	if (!block) {
		hwlog_err("block alloc fail\n");
		return -EINVAL;
	}

	for (i = 0; i < di->fw_param.bin_size; i += CS32G050_FW_BLOCK_SIZE) {
		fw_len = (di->fw_param.bin_size - i > CS32G050_FW_BLOCK_SIZE) ?
			CS32G050_FW_BLOCK_SIZE : (di->fw_param.bin_size - i);
		page_len += fw_len;
		ping_delay = i ? DT_MSLEEP_1MS : ping_delay;
		if (page_len >= MAX_LEN_512) {
			ping_delay = DT_MSLEEP_10MS;
			page_len = page_len % MAX_LEN_512;
		}

		crc_result = cs32g050_fw_crc_func(&di->fw_param.bin_file[i], fw_len);
		block[0] = CS32G050_CMD_FLASH_WRITE; /* flash fw block cmd */
		block[1] = fw_len + CS32G050_BLOCK_DATA_INFO_LEN; /* fw&crc len */
		block[2] = (u8)(crc_result & POWER_MASK_BYTE); /* fw crc */
		block[3] = (u8)(crc_result >> POWER_BITS_PER_BYTE); /* fw crc */
		block[4] = fw_len; /* fw len */
		ret = memcpy_s(block + CS32G050_BLOCK_DATA_HEADER_LEN,
			fw_len, &di->fw_param.bin_file[i], fw_len);
		if (ret) {
			hwlog_err("fw memcpy_s fail\n");
			goto fail_exit;
		}

		ret = cs32g050_write_cmd_with_ping(di, block, fw_len + CS32G050_BLOCK_DATA_HEADER_LEN,
			&ping_ret_len, ping_delay);
		if (ret) {
			hwlog_err("flash block fail\n");
			goto fail_exit;
		}
	}

	hwlog_info("flash firmware succ\n");
fail_exit:
	kfree(block);
	block = NULL;
	return ret;
}

static int cs32g050_fw_flash_validate(struct cs32g050_device_info *di)
{
	u8 data[CS32G050_CMD_VALIDATION_LEN] = { CS32G050_CMD_VALIDATION };
	u8 ping_ret_len = 0;
	int ret;

	ret = cs32g050_write_cmd_with_ping(di,
		data, sizeof(data), &ping_ret_len, CS32G050_VALIDATION_SLEEP);
	if (ret) {
		hwlog_err("flash validate ping fail\n");
		return ret;
	}

	hwlog_info("flash validate succ\n");
	return 0;
}

static int cs32g050_fw_mcu_reboot(struct cs32g050_device_info *di)
{
	u8 data[CS32G050_MCU_REBOOT_BUF_LEN] = { CS32G050_CMD_RESET_TO_FLASH };

	return cs32g050_write_cmd_with_ping(di, data, CS32G050_MCU_REBOOT_BUF_LEN, NULL, 0);
}

static int cs32g050_fw_reboot_check(struct cs32g050_device_info *di)
{
	int ret;

	ret = cs32g050_fw_mcu_reboot(di);
	if (ret) {
		hwlog_err("mcu reboot fail\n");
		return ret;
	}

	power_msleep(CS32G050_REBOOT_SLEEP, 0, NULL);
	ret = cs32g050_get_ic_status(di);
	if (ret) {
		hwlog_err("get status fail\n");
		return ret;
	}

	hwlog_info("reboot check, ic_version=%x, firmware_version=%x\n",
		di->ic_info.info.app_version, di->fw_param.fw_version);
	return 0;
}

static int cs32g050_fw_silent_upgrade_proc(struct cs32g050_device_info *di)
{
	if (di->fw_param.fw_update_mode && di->usb_connect) {
		di->ready_for_reboot = true;
		hwlog_info("ready for reboot\n");
		return 0;
	}

	return cs32g050_fw_reboot_check(di);
}

static int cs32g050_fw_flash_proc(struct cs32g050_device_info *di)
{
	int ret;

	ret = cs32g050_fw_set_mcu(di);
	if (ret) {
		hwlog_err("flash proc set mcu fail\n");
		return ret;
	}

	ret = cs32g050_fw_flash_firmware(di);
	if (ret) {
		hwlog_err("flash fw fail\n");
		return ret;
	}
	ret = cs32g050_fw_flash_validate(di);
	if (ret) {
		hwlog_err("flash validate fail\n");
		return ret;
	}
	ret = cs32g050_fw_silent_upgrade_proc(di);
	if (ret)
		return ret;

	hwlog_info("flash proc succ\n");
	return 0;
}

int cs32g050_fw_reboot_unattach(struct cs32g050_device_info *di)
{
	int ret;

	if (!di)
		return -ENODEV;

	if (di->ready_for_reboot) {
		hwlog_info("unattach mcu reboot\n");
		ret = cs32g050_fw_reboot_check(di);
		di->ready_for_reboot = false;

		return ret;
	}

	hwlog_info("unattach mcu not ready for reboot\n");
	return -EINVAL;
}

int cs32g050_fw_update(struct cs32g050_device_info *di)
{
	int ret, i;

	if (!di)
		return -ENODEV;

	hwlog_info("enter firmware update\n");
	di->ready_for_reboot = false;
	power_wakeup_lock(di->wakelock, false);

	for (i = 0; i < CS32G050_FW_UPDATE_RETRY_CNT; i++) {
		ret = cs32g050_fw_flash_proc(di);
		if (ret == 0)
			break;

		cs32g050_hard_reset(di);
		hwlog_info("fw update retry %d times\n", i + 1);
	}
	hwlog_info("firmware update %s\n", ret ? "fail" : "succ");

	kfree(di->fw_param.bin_file);
	di->fw_param.bin_file = NULL;
	di->fw_update = false;
	power_wakeup_unlock(di->wakelock, false);
	return ret;
}
