/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * cs32g050_fw.c
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

#include "cs32g050_fw.h"
#include "cs32g050.h"
#include <linux/pm_wakeup.h>
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#define MAX_VER_NUM 3

uint8_t g_ic_status[CS32G050_IC_STATUS_LEN + 1] = {0};
int g_curr_version[MAX_VER_NUM] = {0x00, 0x00, 0x00};
int g_new_version[MAX_VER_NUM] = {0x00, 0x00, 0x00};
bool g_start_update = false;
bool g_ready_for_reboot[MAX_VER_NUM] = {false, false, false};


int get_ic_version()
{
	int ic_version;
	ic_version = (g_ic_status[CS32G050_APP_VERSION3_INDEX] << CS32G050_APP_VERSION3_MOVED_BITS) |
				(g_ic_status[CS32G050_APP_VERSION2_INDEX] << CS32G050_APP_VERSION2_MOVED_BITS) |
				(g_ic_status[CS32G050_APP_VERSION1_INDEX] << CS32G050_APP_VERSION1_MOVED_BITS) |
				g_ic_status[CS32G050_APP_VERSION0_INDEX];
	return ic_version;
}
#ifdef CONFIG_HISYSEVENT
static void hiview_pd_update_event(int portid, int is_succ)
{
	struct hiview_hisysevent *event = NULL;
	int ret;

	event = hisysevent_create("PC_USB", "FIRMWARE_UPDATE", STATISTIC);

	if (event == NULL) {
		pr_err("cs32g050 fwupdate failed to create event\n");
		return;
	}

	pr_info("cs32g050 report, portid:%d, g_curr_version:%llx, g_new_version:0x%llx\n",
			portid,  g_curr_version[portid], g_new_version[portid]);


	ret = hisysevent_put_string(event, "CALLER", "PD_UPDATE");
	if (ret != 0) {
		pr_err("failed to put to event, CALLER ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_put_integer(event, "PORT_NUM", portid);
	if (ret != 0) {
		pr_err("failed to put to event, PORT_NUM ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_put_integer(event, "VER_CURRENT",  g_curr_version[portid]);
	if (ret != 0) {
		pr_err("failed to put to event, VER_CURRENT ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_put_integer(event, "VER_TARGET",  g_new_version[portid]);
	if (ret != 0) {
		pr_err("failed to put to event, VER_TARGET ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_put_integer(event, "UPDATE_RESULT",  is_succ);
	if (ret != 0) {
		pr_err("failed to put to event, UPDATE_RESULT ret=%d\n", ret);
		goto hisysevent_end;
	}

	ret = hisysevent_write(event);
	if (ret < 0) {
		pr_err("failed to write event, ret=%d\n", ret);
	}

hisysevent_end:
	hisysevent_destroy(&event);
}
#endif

static void cs32g050_invert_uint8(uint8_t *dst_buf, const uint8_t src_buf)
{
	uint8_t tmp = 0;
	uint8_t i;

	if (!dst_buf) {
		hwlog_err("invert uint8 dst_buf null\n");
		return;
	}

	for (i = 0; i < CS32G050_UINT8_LENGTH; i++) {
		if (src_buf & (1 << i))
			tmp |= 1 << (CS32G050_UINT8_LENGTH - i - 1);
	}
	*dst_buf = tmp;
}

static void cs32g050_invert_uint16(uint16_t *dst_buf, const uint16_t src_buf)
{
	uint16_t tmp = 0;
	uint16_t i;

	if (!dst_buf) {
		hwlog_err("invert uint16 dst_buf null\n");
		return;
	}

	for (i = 0; i < CS32G050_UINT16_LENGTH; i++) {
		if (src_buf & (1 << i))
			tmp |= 1 << (CS32G050_UINT16_LENGTH - i - 1);
	}
	*dst_buf = tmp;
}

static bool cs32g050_update_file_open(struct file **f_bin1, struct file **f_bin2)
{
	*f_bin1 = filp_open(CS32G050_BIN_FILE_PATH_1, O_RDONLY, 0);
	if (IS_ERR(*f_bin1)) {
		hwlog_err("file %s open fail, PTR_ERR = %d\n", CS32G050_BIN_FILE_PATH_1, PTR_ERR(*f_bin1));
		return false;
	}
	*f_bin2 = filp_open(CS32G050_BIN_FILE_PATH_2, O_RDONLY, 0);
	if (IS_ERR(*f_bin2)) {
		hwlog_err("file %s open fail, PTR_ERR = %d\n", CS32G050_BIN_FILE_PATH_2, PTR_ERR(*f_bin2));
		filp_close(*f_bin1, NULL);
		return false;
	}

	if ((*f_bin1)->f_inode->i_size > CS32G050_FILE_SIZE_MAX || (*f_bin2)->f_inode->i_size > CS32G050_FILE_SIZE_MAX) {
		hwlog_err("f_bin1 size is %d\n", (*f_bin1)->f_inode->i_size);
		hwlog_err("f_bin2 size is %d\n", (*f_bin2)->f_inode->i_size);
		hwlog_err("firmware oversize, limit is %d B\n", CS32G050_FILE_SIZE_MAX);
		filp_close(*f_bin1, NULL);
		filp_close(*f_bin2, NULL);
		return false;
	}

	return true;
}

static uint16_t cs32g050_crc_func(const int size, uint8_t *content, const uint32_t crc_poly,
									const uint16_t init_value, const uint8_t ref_flag)
{
	uint16_t crc_reg = init_value;
	uint16_t tmp = 0;
	uint8_t data_byte = 0;
	int j;
	int i;

	if (!content) {
		hwlog_err("crc func content null\n");
		return 0;
	}

	for (i = 0; i < size; i++) {
		data_byte = content[i];
		if (ref_flag)
			cs32g050_invert_uint8(&data_byte, data_byte);
		crc_reg ^= data_byte << CS32G050_UINT8_LENGTH;
		for (j = 0; j < CS32G050_UINT8_LENGTH; j++) {
			tmp = crc_reg & CS32G050_CRC16_CALCULATE_VALUE;
			crc_reg <<= 1;
			if (tmp)
				crc_reg ^= crc_poly;
		}
	}

	if (ref_flag)
		cs32g050_invert_uint16(&crc_reg, crc_reg);

	return crc_reg;
}

static bool cs32g050_update_param_init(struct update_para *update_param)
{
	char *bin_file1 = NULL;
	char *bin_file2 = NULL;
	struct file *f_bin1 = NULL;
	struct file *f_bin2 = NULL;
	mm_segment_t fs;
	loff_t pos_a = 0;
	loff_t pos_b = 0;

	if (!cs32g050_update_file_open(&f_bin1, &f_bin2)) {
		return false;
	}

	update_param->bin_file1_size = f_bin1->f_inode->i_size;
	update_param->bin_file2_size = f_bin2->f_inode->i_size;
	bin_file1 = kzalloc(update_param->bin_file1_size, GFP_KERNEL);
	if (!bin_file1) {
		hwlog_err("bin_file1 kzalloc fail\n");
		goto err;
	};
	bin_file2 = kzalloc(update_param->bin_file2_size, GFP_KERNEL);
	if (!bin_file2) {
		hwlog_err("bin_file2 kzalloc fail\n");
		kfree(bin_file1);
		bin_file1 = NULL;
		goto err;
	};

	fs = get_fs();
	set_fs(KERNEL_DS);
	hwlog_info("file read begin\n");
	if (vfs_read(f_bin1, bin_file1, update_param->bin_file1_size, &pos_a) != update_param->bin_file1_size ||
		vfs_read(f_bin2, bin_file2, update_param->bin_file2_size, &pos_b) != update_param->bin_file2_size) {
		set_fs(fs);
		kfree(bin_file1);
		kfree(bin_file2);
		bin_file1 = NULL;
		bin_file2 = NULL;
		hwlog_info("file read fail\n");
		goto err;
	}
	hwlog_info("file read end\n");
	update_param->bin_file1 = bin_file1;
	update_param->bin_file2 = bin_file2;

	set_fs(fs);
	filp_close(f_bin1, NULL);
	filp_close(f_bin2, NULL);

	return true;
err:
	filp_close(f_bin1, NULL);
	filp_close(f_bin2, NULL);
	return false;
}

static bool cs32g050_i2c_firmware_read(struct i2c_client *client, u8 *value, u16 num_bytes)
{
	int i;
	struct i2c_msg msg[CS32G050_I2C_MSG_LEN];

	if (!client || !client->adapter || !value || (num_bytes == 0) || num_bytes > CS32G050_I2C_MAX_LEN) {
		hwlog_err("i2c read input params null\n");
		return 0;
	}

	msg[0].addr = client->addr;
	msg[0].flags = I2C_M_RD;
	msg[0].buf = value;
	msg[0].len = num_bytes;

	for (i = 0; i < CS32G050_MAX_RETRY_TIME; i++) {
		if (i2c_transfer(client->adapter, msg, CS32G050_I2C_MSG_LEN) == CS32G050_I2C_MSG_LEN)
			return true;
	}

	hwlog_err("i2c read fail\n");
	return false;
}

static int cs32g050_i2c_firmware_write(struct i2c_client *client, u8 *value, u16 num_bytes)
{
	int i;
	struct i2c_msg msg[CS32G050_I2C_MSG_LEN];

	if (!client || !client->adapter || !value || (num_bytes == 0) || num_bytes > CS32G050_I2C_MAX_LEN) {
		hwlog_err("i2c write input params error\n");
		return 0;
	}

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = value;
	msg[0].len = num_bytes;

	for (i = 0; i < CS32G050_MAX_RETRY_TIME; i++) {
		if (i2c_transfer(client->adapter, msg, CS32G050_I2C_MSG_LEN) == CS32G050_I2C_MSG_LEN)
			return CS32G050_I2C_MSG_LEN;
	}

	hwlog_err("i2c write fail\n");
	return 0;
}

static bool cs32g050_wait_ping_complete(struct i2c_client *client, uint8_t *ping_ret)
{
	int err_retry = 0;
	uint8_t buf;

	if (!client || !client->adapter || !ping_ret) {
		hwlog_err("wait ping complete input params null\n");
		return false;
	}

	while (err_retry < CS32G050_MAX_RETRY_TIME) {
		if (!cs32g050_i2c_firmware_read(client, &buf, CS32G050_I2C_PING_BUF_LEN)) {
			hwlog_err("wait ping complete fail\n");
			return false;
		}

		if ((buf & CS32G050_PING_STA_FLAG) == CS32G050_PING_STA_COMPLETE) {
			hwlog_info("wait ping complete success\n");
			ping_ret[0] = buf & CS32G050_PING_STA_FLAG;
			ping_ret[1] = buf >> CS32G050_PING_STA_HIGH_VALUE_OFFSET;
			return true;
		}

		if ((buf & CS32G050_PING_STA_FLAG) == CS32G050_PING_STA_ERROR) {
			err_retry += 1;
			hwlog_err("wait ping complete fail err_retry =%d\n", err_retry);
			msleep(CS32G050_SHORT_SLEEP);
		}
	}
	return false;
}

static bool cs32g050_get_status(struct i2c_client *client, uint8_t *info)
{
	uint8_t buf[CS32G050_GET_IC_STATUS_BUF_LEN] = {CS32G050_GET_IC_STATUS, CS32G050_IC_STATUS_LEN};
	uint8_t ping_result[CS32G050_PING_RET_NUM];
	uint8_t get_info[CS32G050_I2C_STATUS_INFO_LEN] = {CS32G050_GET_INFO};
	int read_info_len;

	if (!client || !client->adapter || !info) {
		hwlog_err("get status input params null\n");
		return false;
	}

	if (!cs32g050_i2c_firmware_write(client, buf, CS32G050_GET_IC_STATUS_BUF_LEN)) {
		hwlog_err("get status fail\n");
		return false;
	}

	msleep(CS32G050_SHORT_SLEEP);
	if (!cs32g050_wait_ping_complete(client, ping_result)) {
		hwlog_err("get status wait ping complete fail\n");
		return false;
	}
	if (ping_result[0] != CS32G050_PING_STA_COMPLETE) {
		hwlog_err("get status ping result fail\n");
		return false;
	}

	read_info_len = ping_result[1];

	if (read_info_len > (CS32G050_IC_STATUS_LEN + 1)) {
		hwlog_err("get status ping len fail\n");
		return false;
	}
	if (!cs32g050_i2c_firmware_write(client, get_info, CS32G050_I2C_STATUS_INFO_LEN) ||
		!cs32g050_i2c_firmware_read(client, info, read_info_len)) {
			hwlog_err("get status fail\n");
			return false;
		}

	hwlog_info("get status datalen = %x, chip_id = %x, run_bank = %x, bootversion0 = %x, bootver1 = %x,\
		bootver2 = %x, bootver3 = %x, app_version0 = %x, app_ver1 = %x, app_ver2 = %x, app_ver3 = %x, fail_times = %x\n",
		info[INDEX_0], info[INDEX_1], info[INDEX_2], info[INDEX_3], info[INDEX_4], info[INDEX_5], info[INDEX_6],
		info[INDEX_7], info[INDEX_8], info[INDEX_9], info[INDEX_10], info[INDEX_11]);
	return true;
}

static bool cs32g050_set_mcu(struct i2c_client *client, const uint8_t ctr_info)
{
	uint8_t buf[CS32G050_CMD_MCU_CTRL_LEN] = {CS32G050_CMD_MCU_CTRL, ctr_info};
	uint8_t ping_result[CS32G050_PING_RET_NUM];

	if (!client) {
		hwlog_err("set mcu input params null\n");
		return false;
	}

	if (!cs32g050_i2c_firmware_write(client, buf, CS32G050_CMD_MCU_CTRL_LEN)) {
		hwlog_err("set mcu fail\n");
		return false;
	}

	msleep(CS32G050_LONG_SLEEP);
	if (!cs32g050_wait_ping_complete(client, ping_result)) {
		hwlog_err("set mcu wait ping complete fail\n");
		return false;
	}
	if (ping_result[0] != CS32G050_PING_STA_COMPLETE) {
		hwlog_err("set mcu ping result fail\n");
		return false;
	}
	hwlog_info("set mcu success\n");
	return true;
}

static bool cs32g050_flash_check(struct i2c_client *client, uint8_t *data, int crc_check_enable)
{
	uint8_t ping_result[CS32G050_PING_RET_NUM];

	if (!client || !client->adapter || !data) {
		hwlog_err("flash check input params null\n");
		return false;
	}

	if (!cs32g050_wait_ping_complete(client, ping_result)) {
		hwlog_err("flash check wait ping complete fail\n");
		return false;
	}

	if (ping_result[0] == CS32G050_PING_STA_COMPLETE) {
		return true;
	} else if (ping_result[0] == CS32G050_PING_STA_CRC_ERR) {
		hwlog_err("flash check ping fail\n");
		return false;
	}

	hwlog_err("flash check ping result not as expected\n");
	return false;
}

static bool cs32g050_flash_block(struct i2c_client *client, uint8_t *block_data, uint8_t block_size,
								const bool first_block, const bool copy_timming, int crc_check_enable)
{
	bool ret  = false;
	int data_len = block_size + CS32G050_BLOCK_DATA_HEADER_LEN;
	uint16_t crc_result;
	uint8_t *data = NULL;

	if (!client || !client->adapter || !block_data) {
		hwlog_err("flash block input params null\n");
		return false;
	}

	crc_result = cs32g050_crc_func(block_size, block_data, CS32G050_CRC_POLICY_VALUE, CS32G050_CRC_INIT_VALUE, 0);
	data = kzalloc(data_len, GFP_KERNEL);
	if (!data) {
		hwlog_err("flash block kmalloc fail\n");
		return false;
	}
	data[0] = CS32G050_CMD_FLASH_WRITE;
	data[1] = block_size + CS32G050_BLOCK_DATA_INFO_LEN;
	data[INDEX_2] = (uint8_t)(crc_result & 0xFF); // 0xFF get low 8 byte
	data[INDEX_3] = (uint8_t)(crc_result >> CS32G050_BYTE_LENGTH);
	data[INDEX_4] = block_size;
	for (int j = 0; j < block_size; j++)
		data[j + CS32G050_BLOCK_DATA_HEADER_LEN] = block_data[j];

	mutex_lock(&cs32g050_mutex);
	if (!cs32g050_i2c_firmware_write(client, data, data_len)) {
		goto RETURN_FAIL;
	}
	msleep(1);
	if (first_block || copy_timming) {
		mutex_unlock(&cs32g050_mutex);
		msleep(CS32G050_UPDATE_FLASH_BLOCK_DELAY);
		if (first_block) {
			msleep(CS32G050_LONG_SLEEP);
		}
		mutex_lock(&cs32g050_mutex);
	}
	if (!cs32g050_flash_check(client, data, crc_check_enable)) {
		goto RETURN_FAIL;
	}
	ret = true;

RETURN_FAIL:
	mutex_unlock(&cs32g050_mutex);
    kfree(data);
    data = NULL;
    return ret;
}

static bool cs32g050_flash_fw(struct i2c_client *client, const uint8_t *fw,
							const int length, const int crc_check_enable)
{
	int fw_len;
	int i;
	int j;
	uint8_t *block = NULL;
	int page_len = 0;

	if (!client || !client->adapter || !fw) {
		hwlog_err("flash fw input params null\n");
		return false;
	}

	for (i = 0; i < length; i += CS32G050_FW_BLOCK_SIZE) {
		if (length - i > CS32G050_FW_BLOCK_SIZE) {
			fw_len = CS32G050_FW_BLOCK_SIZE;
		} else {
			fw_len = length - i;
		}
		block = kzalloc(fw_len, GFP_KERNEL);
		page_len += fw_len;
		if (!block) {
			hwlog_err("flash fw kmalloc fail\n");
			return false;
		}
		for (j = 0; j < fw_len; j++)
			block[j] = fw[i + j];
        
		msleep(1);
		if (!cs32g050_flash_block(client, block, fw_len, i == 0, page_len >= MAX_LEN_512, crc_check_enable)) {
			hwlog_err("flash block fail\n");
			kfree(block);
			block = NULL;
			return false;
		}
		if (page_len >= MAX_LEN_512) {
			page_len = page_len % MAX_LEN_512;
		}
		kfree(block);
		block = NULL;
	}
	return true;
}

static bool cs32g050_flash_validate(struct i2c_client *client)
{
	uint8_t data[CS32G050_CMD_VALIDATION_LEN] = {CS32G050_CMD_VALIDATION};
	uint8_t ping_result[CS32G050_PING_RET_NUM];

	if (!client) {
		hwlog_err("flash validate input params null\n");
		return false;
	}

	if (!cs32g050_i2c_firmware_write(client, data, CS32G050_CMD_VALIDATION_LEN)) {
		hwlog_err("flash validate fail\n");
		return false;
	}

	msleep(CS32G050_REBOOT_SLEEP);

	if (!cs32g050_wait_ping_complete(client, ping_result)) {
		hwlog_err("flash validate ping fail\n");
		return false;
	}

	if (ping_result[0] != CS32G050_PING_STA_COMPLETE) {
		hwlog_err("flash validate ping result fail\n");
		return false;
	}

	return true;
}

static bool cs32g050_mcu_reboot(struct i2c_client *client)
{
	uint8_t data[CS32G050_MCU_REBOOT_BUF_LEN] = {CS32G050_CMD_RESET_TO_FLASH};

	if (!client) {
		hwlog_err("mcu reboot input params null\n");
		return false;
	}

	if (!cs32g050_i2c_firmware_write(client, data, CS32G050_MCU_REBOOT_BUF_LEN)) {
		hwlog_err("mcu reboot fail\n");
		return false;
	}

	msleep(CS32G050_REBOOT_SLEEP);
	return true;
}

static bool cs32g050_version_check(const struct update_para *update_param, uint8_t *ic_status)
{
	int ic_version;

	if (!ic_status || !update_param) {
		hwlog_err("version check input params null\n");
		return false;
	}
	// ic_status : {datalen , chip_id, run_bank, bootversion0, bootversion1, bootversion2, bootversion3,
	// app_version0, app_version1, app_version2, app_version3}
	ic_version = get_ic_version();
	hwlog_info("begin check version, ic_version = %x, firmware_version = %x\n",
				ic_version, update_param->firmware_version);
	if (ic_version >= update_param->firmware_version) {
		hwlog_err("ic firmware version is newest, no need update\n");
		return false;
	}
	if (ic_version < update_param->firmware_first_version) {
		hwlog_err("ic firmware version is not upgradable, no need update\n");
		return false;
	}
	// Compatible with historical versions : return 0xFF in index 11
    if (ic_status[CS32G050_FAIL_TIMES_INDEX] != CS32G050_FAIL_TIMES_DEFAULT_VALUE) {
		if ((ic_status[CS32G050_FAIL_TIMES_INDEX] >= CS32G050_FAIL_TIMES_MAX) &&
							(update_param->force_upgrade == 0)) {
			hwlog_err("fail times = %d, reached the maximum = %d\n",
							ic_status[CS32G050_FAIL_TIMES_INDEX], CS32G050_FAIL_TIMES_MAX);
			return false;
		}
	}

	return true;
}

static int cs32g050_reboot_and_check(struct i2c_client *client)
{
	if (!cs32g050_mcu_reboot(client)) {
		hwlog_err("mcu reboot fail\n");
		return 0;
	}
	if (!cs32g050_get_status(client, g_ic_status))
		return 0;
	return 1;
}

static int cs32g050_silent_upgrade_proc(int portid, struct i2c_client *client, bool update_mode)
{
	u64 *port_status;
	if (!update_mode) {
		if (!cs32g050_reboot_and_check(client)) {
			return 0;
		}
	} else {
		port_status = cs32g050_get_g_last_port_status();
		if (port_status[portid] & CS32G050_DATA_CONNECTION == 0) {
			if (!cs32g050_reboot_and_check(client)) {
				return 0;
			}
		} else {
			g_ready_for_reboot[portid] = true;
			hwlog_info("ready for reboot\n");
		}
	}
	return 1;
}

static int cs32g050_flash_proc(int portid, struct i2c_client *client,
							   const struct update_para *update_param, bool update_mode)
{
	uint8_t *fw_file = NULL;
	int fw_size;

	if (!client || !client->adapter || !update_param) {
		hwlog_err("flash proc input params null\n");
		return 0;
	}

	if (!cs32g050_get_status(client, g_ic_status)) {
		hwlog_err("flash proc get status fail\n");
		return 0;
	}

	g_curr_version[portid] = get_ic_version();
	if (!cs32g050_version_check(update_param, g_ic_status))
		return 0;

	g_start_update = true;
	g_ready_for_reboot[portid] = false;
	if (g_ic_status[CS32G050_BANK_PARTITION_INDEX] == CS32G050_BANK_PARTITION_A) {
		fw_file = update_param->bin_file2;
		fw_size = update_param->bin_file2_size;
	} else if (g_ic_status[CS32G050_BANK_PARTITION_INDEX] == CS32G050_BANK_PARTITION_B) {
		fw_file = update_param->bin_file1;
		fw_size = update_param->bin_file1_size;
	} else {
		hwlog_err("not BANK_PARTITION_A or B g_ic_status[2] = %d\n", g_ic_status[CS32G050_BANK_PARTITION_INDEX]);
		return 0;
	}

	if (!cs32g050_set_mcu(client, CS32G050_CMD_CTRL_FLASH_INIT)) {
		hwlog_err("flash proc set mcu fail\n");
		return 0;
	}

	if (!cs32g050_flash_fw(client, fw_file, fw_size, update_param->crc_check_enable)) {
		hwlog_err("flash fw fail\n");
		return 0;
	}
	if (!cs32g050_flash_validate(client)) {
		hwlog_err("flash validate fail\n");
		return 0;
	}
	if (!cs32g050_silent_upgrade_proc(portid, client, update_mode)) {
		return 0;
	}
	return update_param->firmware_version;
}

int cs32g050_fw_reboot_unattach(int portid, struct i2c_client *client)
{
	if (g_ready_for_reboot[portid] == true) {
		if (!cs32g050_reboot_and_check(client)) {
			return 0;
		}
		g_new_version[portid] = get_ic_version();
#ifdef CONFIG_HISYSEVENT
		hiview_pd_update_event(portid, true);
#endif
		g_ready_for_reboot[portid] = false;
		hwlog_info("unattach mcu reboot succ\n");
		return 1;
	}

	hwlog_info("unattach mcu not ready for reboot\n");
	return -1;
}

static bool cs32g050_fw_parse_dts(struct device_node *node, struct update_para *update_param)
{
	int ret;

	if (!node || !update_param) {
		return false;
	}

	update_param->crc_check_enable = CS32G050_CRC_SEND_BACK_DEFAULT_VALUE;
	update_param->firmware_version = CS32G050_FIRMWARE_VERSION_DEFAULT;
	update_param->firmware_first_version = CS32G050_FIRMWARE_VERSION_DEFAULT;
	ret = of_property_read_u32(node, "firmware_version", &update_param->firmware_version);
	ret += of_property_read_u32(node, "firmware_first_upgradable_version", &update_param->firmware_first_version);
	ret += of_property_read_u32(node, "firmware_force_upgrade", &update_param->force_upgrade);
	if (ret != 0) {
		hwlog_err("read firmware_version fail\n");
		return false;
	}

	return true;
}

/***
 *
 * @param client i2c_client
 * @param update_mode 1 silent update, reboot to effect;0 effect Immediately,usb may disconnect
 * @return
 */
int cs32g050_update(int portid, struct i2c_client *client, struct device_node *node, bool update_mode)
{
	int ret;
	struct update_para update_param = {-1, -1, 0, 0, 0, 0, 0, 0, 0};

	if (!client || !client->adapter || !node) {
		hwlog_err("update firmware input params fail\n");
		return 0;
	}

	hwlog_info("cs32g050 update begin!!!\n");
	if (!cs32g050_fw_parse_dts(node, &update_param)) {
		hwlog_err("prase dts fail\n");
		return 0;
	}

	if (!cs32g050_update_param_init(&update_param)) {
		hwlog_err("update param init fail!!!\n");
		return 0;
	}

	__pm_stay_awake(client->dev.power.wakeup);
	hwlog_info("update pd_firmware lock pm\n");

	ret = cs32g050_flash_proc(portid, client, &update_param, update_mode);

	if (update_mode) { //normal update success need update current
		g_new_version[portid] = get_ic_version();
	}

	if (g_start_update) {
#ifdef CONFIG_HISYSEVENT
		hiview_pd_update_event(portid, ret);
#endif
		g_start_update = false;
	}

	kfree(update_param.bin_file2);
	kfree(update_param.bin_file1);
	update_param.bin_file1 = NULL;
	update_param.bin_file2 = NULL;
	if (!ret) {
		__pm_relax(client->dev.power.wakeup);
		hwlog_err("update firmware version fail,unlock pm\n");
		return ret;
	}
	__pm_relax(client->dev.power.wakeup);

	hwlog_info("flash proc success, final firmware version = %x,unlock pm\n", ret);
	msleep(CS32G050_LONG_SLEEP);

	return ret;
}
