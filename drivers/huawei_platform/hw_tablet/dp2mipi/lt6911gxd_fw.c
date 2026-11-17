/*
  * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
  *
  * lt6911gxd_fw.c
  *
  * lt6911gxd firmware update
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

#include "lt6911gxd_fw.h"
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
#include <linux/time.h>
#include <linux/types.h>
#include <linux/workqueue.h>
#include <securec.h>
#include <stdbool.h>
#include <uapi/asm-generic/fcntl.h>

#define HWLOG_TAG lt6911gxd_fw
HWLOG_REGIST();

#define READ_ONE_TIME 32
#define WRITE_SRAM_ONE_TIME 256

#define LT6911GXD_I2C_MAX_LEN 300

#define LT6911GXD_FIRMWARE_VERSION_DEFAULT 0
#define LT6911GXD_BIN_FILE_PATH_1 "/chip_prod/etc/firmware/Hopper-LT6911GXD_V61-h0.pc.HPR.r1/lt6911gxd.bin"
#define FW_READ_WAIT_SECONDS 300

#define LT6911GXD_BYTE_LENGTH 8
#define LT6911GXD_REG_VERSION_H 0x82

#define READ_FW_DELAY_MS 5
#define READ_FW_DELAY_CNT 75

#define RESET_AFTER_DELAY 200
#define UPDATE_TRY_TIMES 3
#define UPDATE_TRY_DLY_MS 200
#define GET_IC_VER_TRY_TIMES 3
#define GET_IC_VER_TRY_DLY_MS 200

struct update_para {
	uint8_t *bin_file1;
	int bin_file1_size;
	int firmware_version;
};

int lt6911gxd_write_block(struct i2c_client *client, unsigned char reg,
			  unsigned char *value, unsigned short num_bytes)
{
	struct i2c_msg msg[1]; /* 1: number of msg struct is 1 */
	int ret;
	u8 buf[LT6911GXD_I2C_MAX_LEN] = { 0 };

	if (!client || !value) {
		hwlog_err("null ptr err\n");
		return -1;
	}

	if (num_bytes > LT6911GXD_I2C_MAX_LEN - 1) {
		hwlog_err("num_bytes exceeds buffer size\n");
		return -1;
	}

	buf[0] = reg;
	ret = memcpy_s(&buf[1], sizeof(buf) - 1, value, num_bytes);
	if (ret != 0) {
		hwlog_err("[%s] memcpy_s fail\n", __func__);
		return -1;
	}
	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = buf;
	msg[0].len = num_bytes + 1;

	/* i2c_transfer returns number of messages transferred */
	ret = i2c_transfer(client->adapter, msg, 1);
	if (ret != 1) {
		hwlog_err("i2c_write failed to transfer all messages\n");
		return -1;
	}
	return 0;
}

int lt6911gxd_read_block(struct i2c_client *client, unsigned char reg,
			 unsigned char *value, unsigned short num_bytes)
{
	struct i2c_msg msg[2]; /* 2: the length of msg is 2 */
	int ret;

	if (!client || !value) {
		hwlog_err("null ptr err\n");
		return -1;
	}

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = &reg;
	msg[0].len = 1;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = value;
	msg[1].len = num_bytes;

	/* i2c_transfer returns number of messages transferred */
	ret = i2c_transfer(client->adapter, msg, 2); /* 2: the length of msg */
	if (ret != 2) {
		hwlog_err("i2c_read failed to transfer all messages\n");
		return -1;
	}
	return 0;
}

static void read_i2c_byte(struct i2c_client *client, u8 reg, u8 *readData)
{
	(void)lt6911gxd_read_block(client, reg, readData, 1);
}

static u8 read_i2c_n_byte(struct i2c_client *client, u8 reg, u8 *readData,
			  u8 len)
{
	return lt6911gxd_read_block(client, reg, readData, len);
}

static void write_i2c_byte(struct i2c_client *client, u8 reg, u8 data)
{
	(void)lt6911gxd_write_block(client, reg, &data, 1);
}

static void write_i2c_n_bytes(struct i2c_client *client, u8 reg, u8 *data,
			      u32 ulLength)
{
	(void)lt6911gxd_write_block(client, reg, data, ulLength);
}

static u8 flash_read_flash_status_reg(struct i2c_client *client)
{
	u8 ucFlashStatusReg = 0;

	write_i2c_byte(client, 0xFF, 0xE1); //fifo_rst_n
	write_i2c_byte(client, 0x03, 0x3F);
	write_i2c_byte(client, 0x03, 0xFF);

	write_i2c_byte(client, 0xFF, 0xE0);
	write_i2c_byte(client, 0x5e, 0x40);
	write_i2c_byte(client, 0x56, 0x05); //opcode=read status register
	write_i2c_byte(client, 0x55,
		       0x25); //[5]=rd_reg_flag;[2]=opcode_en;[1:0]=cmd_len
	write_i2c_byte(client, 0x55, 0x01);
	write_i2c_byte(client, 0x58, 0x21);

	(void)read_i2c_byte(client, 0x5f, &ucFlashStatusReg);
	hwlog_info("ucFlashStatusReg: 0x%02x\n", ucFlashStatusReg);

	return ucFlashStatusReg;
}

static void flash_configure_parameters(struct i2c_client *client)
{
	write_i2c_byte(client, 0xFF, 0xE0);
	write_i2c_byte(client, 0xEE, 0x01);
	write_i2c_byte(client, 0x5E, 0xC1);
	write_i2c_byte(client, 0x58, 0x00);
	write_i2c_byte(client, 0x59, 0x50);
	write_i2c_byte(client, 0x5A, 0x10);
	write_i2c_byte(client, 0x5A, 0x00);
	write_i2c_byte(client, 0x58, 0x21);
}

static void flash_block_erase(struct i2c_client *client)
{
	u32 i = 0;
	u8 ucFlashStatuss;
	write_i2c_byte(client, 0xFF, 0xE0);
	write_i2c_byte(client, 0xEE, 0x01);
	write_i2c_byte(client, 0x5A, 0x04);
	write_i2c_byte(client, 0x5A, 0x00);
	write_i2c_byte(client, 0x5B, 0x00);
	write_i2c_byte(client, 0x5C, 0x00);
	write_i2c_byte(client, 0x5D, 0x00);
	write_i2c_byte(client, 0x5A, 0x01);
	write_i2c_byte(client, 0x5A, 0x00);
	msleep(100);

	i = 0;
	while (1) {
		ucFlashStatuss = flash_read_flash_status_reg(client);
		if ((ucFlashStatuss & 0x01) == 0) {
			break;
		}

		if (i > 50) {
			break;
		}
		i++;
		msleep(50);
	}

	write_i2c_byte(client, 0xFF, 0xE0);
	write_i2c_byte(client, 0xEE, 0x01);
	write_i2c_byte(client, 0x5A, 0x04);
	write_i2c_byte(client, 0x5A, 0x00);
	write_i2c_byte(client, 0x5B, 0x00);
	write_i2c_byte(client, 0x5C, 0x80);
	write_i2c_byte(client, 0x5D, 0x00);
	write_i2c_byte(client, 0x5A, 0x01);
	write_i2c_byte(client, 0x5A, 0x00);
	msleep(100);

	i = 0;
	while (1) {
		ucFlashStatuss = flash_read_flash_status_reg(client);
		if ((ucFlashStatuss & 0x01) == 0) {
			break;
		}

		if (i > 50) {
			break;
		}
		i++;
		msleep(50);
	}
}

static void flash_write_disable(struct i2c_client *client)
{
	if (!client) {
		return;
	}
	write_i2c_byte(client, 0xFF, 0xE0);
	write_i2c_byte(client, 0x5A, 0x08);
	write_i2c_byte(client, 0x5A, 0x00);
}

static void flash_write_flash_with_sram(struct i2c_client *client, u8 *ucData,
					u32 ulOffset, u32 ulLength)
{
	u8 sramBuffer[WRITE_SRAM_ONE_TIME];
	int ret;
	if (!client || !ucData) {
		hwlog_err("ptr null\n");
		return;
	}

	if (memset_s(sramBuffer, sizeof(sramBuffer), 0xFF,
		     sizeof(sramBuffer))) {
		hwlog_err("memset_s err\n");
		return;
	}
	ret = memcpy_s(sramBuffer, sizeof(sramBuffer), &ucData[ulOffset],
		       ulLength);
	if (ret != 0) {
		hwlog_err("memcpy_s err\n");
		return;
	}

	write_i2c_byte(client, 0xFF, 0xE0); //Wren.

	write_i2c_byte(client, 0x55, 0x80); //I2c to sram
	write_i2c_byte(client, 0x5e, 0xc0);
	write_i2c_byte(client, 0x58, 0x21);

	//Write regsister 0xe059 with 256 bytes.
	write_i2c_n_bytes(client, 0x59, sramBuffer, sizeof(sramBuffer));
	//6ms at 400k i2c
	write_i2c_byte(client, 0x5A, 0x04);
	write_i2c_byte(client, 0x5A, 0x00); //spi write WREN cmd.

	write_i2c_byte(client, 0x5A, 0x30);
	write_i2c_byte(client, 0x5A, 0x00); //spi write 256 bytes
}

static void flash_write_sram_end(struct i2c_client *client)
{
	write_i2c_byte(client, 0xff, 0xe0);
	write_i2c_byte(client, 0x55, 0x00);
}

static int lt6911gxd_update_param_init(struct device_node *node,
				       struct update_para *update_param)
{
	int ret;
	if (!node || !update_param) {
		hwlog_err("update param input params null\n");
		return UPDATE_ECODE_NULL_PTR;
	}

	update_param->firmware_version = LT6911GXD_FIRMWARE_VERSION_DEFAULT;
	ret = of_property_read_u32(node, "firmware_version",
				   &update_param->firmware_version);
	if (ret != 0) {
		hwlog_err("read fw_version from dts err. ret = %d\n", ret);
		return UPDATE_ECODE_READ_DTS;
	}

	return UPDATE_ECODE_OK;
}

static int lt6911gxd_read_fw_file(struct device_node *node,
				  struct update_para *update_param)
{
	char *bin_file1;
	struct file *f_bin1 = NULL;
	mm_segment_t fs;
	loff_t pos_a = 0;

	if (!node || !update_param) {
		hwlog_err("update param input params null\n");
		return UPDATE_ECODE_NULL_PTR;
	}

	for (int i = 0; i < FW_READ_WAIT_SECONDS; i++) {
		f_bin1 = filp_open(LT6911GXD_BIN_FILE_PATH_1, O_RDONLY, 0);
		if (f_bin1 == NULL || IS_ERR(f_bin1) ||
		    f_bin1->f_inode == NULL) {
			hwlog_err("file %s open fail , times: %d\n",
				  LT6911GXD_BIN_FILE_PATH_1, i);
			msleep(1000);
		} else {
			break;
		}
	}
	if (f_bin1 == NULL || IS_ERR(f_bin1) || f_bin1->f_inode == NULL) {
		hwlog_err("file %s open fail,PTR_ERR = %d\n",
			  LT6911GXD_BIN_FILE_PATH_1, PTR_ERR(f_bin1));
		return UPDATE_ECODE_F_OPEN;
	}

	update_param->bin_file1_size = f_bin1->f_inode->i_size;

	bin_file1 = kzalloc(update_param->bin_file1_size, GFP_KERNEL);
	if (bin_file1 == NULL) {
		hwlog_err("kzalloc err\n");
		filp_close(f_bin1, NULL);
		return UPDATE_ECODE_KZALLOC;
	}

	fs = get_fs();
	set_fs(KERNEL_DS);
	hwlog_info("file read begin\n");
	if (vfs_read(f_bin1, bin_file1, update_param->bin_file1_size, &pos_a) !=
	    update_param->bin_file1_size) {
		set_fs(fs);
		filp_close(f_bin1, NULL);
		kfree(bin_file1);
		hwlog_info("file read fail\n");
		return UPDATE_ECODE_VFS_READ;
	}
	hwlog_info("file read end\n");
	update_param->bin_file1 = bin_file1;

	set_fs(fs);
	filp_close(f_bin1, NULL);

	return UPDATE_ECODE_OK;
}

void lt6911gxd_write_with_sram(struct i2c_client *client, u8 *ucData,
			       u32 ulFwSize)
{
	u32 ulLength;
	u32 i;
	u32 ulFlashAddr = 0;
	u8 ucLastDateLangth;
	hwlog_info("%s: begin\n", __func__);

	if (!client || !ucData) {
		hwlog_err("input params null\n");
		return;
	}

	ulLength = ulFwSize;
	hwlog_info("ucData ulLength:%d\n", ulLength);

	//write 256 bytes every time in sram mode.
	ulLength = (ulLength + (WRITE_SRAM_ONE_TIME - 1)) / WRITE_SRAM_ONE_TIME;

	hwlog_info("ucData ulLength around:%d\n", ulLength);

	ucLastDateLangth = ulFwSize % WRITE_SRAM_ONE_TIME;
	hwlog_info("ucData ucLastDateLangth:%d\n", ucLastDateLangth);

	flash_configure_parameters(client);
	flash_block_erase(client);

	for (i = 0; i < ulLength; i++) {
		// the last 256 bytes
		if ((ucLastDateLangth != 0) && (i == (ulLength - 1))) {
			flash_write_flash_with_sram(client, ucData, ulFlashAddr,
						    ucLastDateLangth);
		} else {
			flash_write_flash_with_sram(client, ucData, ulFlashAddr,
						    WRITE_SRAM_ONE_TIME);
		}
		ulFlashAddr += WRITE_SRAM_ONE_TIME;
	}

	flash_write_disable(client);
	flash_write_sram_end(client);
	hwlog_info("%s: end\n", __func__);
}

static int lt6911gxd_version_check(const struct update_para *update_param,
				   uint16_t ic_ver)
{
	if (!update_param) {
		hwlog_err("version check input params null\n");
		return UPDATE_ECODE_NULL_PTR;
	}

	if (ic_ver == update_param->firmware_version) {
		hwlog_err("no new version. ic_ver = %u, target = %u\n", ic_ver,
			  update_param->firmware_version);
		return UPDATE_ECODE_NO_NEW;
	}

	hwlog_info("ready to upgrade lt6911gxd from ver %d to %d\n", ic_ver,
		   update_param->firmware_version);
	return UPDATE_ECODE_OK;
}

static int lt6911gxd_get_ic_version(struct i2c_client *client, uint16_t *ver)
{
	if (!client || !ver) {
		hwlog_err("get ic_version params null\n");
		return UPDATE_ECODE_NULL_PTR;
	}
	uint8_t ic_ver[2] = { 0 };
	int ii;

	for (ii = 0; ii < GET_IC_VER_TRY_TIMES; ++ii) {
		if (read_i2c_n_byte(client, LT6911GXD_REG_VERSION_H, ic_ver,
				    sizeof(uint16_t)) == 0) {
			if (ic_ver[0] != 0 || ic_ver[1] != 0) {
				break;
			} else {
				hwlog_err("read ver ok but value zero\n");
			}
		}
		msleep(GET_IC_VER_TRY_DLY_MS);
		hwlog_err("get ic_version err. try times = %d\n", ii);
	}
	if (ii == GET_IC_VER_TRY_TIMES) {
		hwlog_err("get ic_version err finally. try all times = %d\n",
			  GET_IC_VER_TRY_TIMES);
		return UPDATE_ECODE_GET_IC_VER;
	}
	hwlog_info("get ic_version success. verion = 0x%02x 0x%02x\n",
		   ic_ver[0], ic_ver[1]);
	*ver = (ic_ver[0] << LT6911GXD_BYTE_LENGTH) | (ic_ver[1]);

	return UPDATE_ECODE_OK;
}

static void lt6911gxd_read_fw(struct i2c_client *client, uint8_t *fw_data,
			      uint32_t fw_size)
{
	hwlog_info("%s: begin. fw_size = %u\n", __func__, fw_size);
	if (!client || !fw_data) {
		hwlog_err("params null\n");
		return;
	}

	flash_configure_parameters(client);

	uint8_t key_addr[3] = { 0, 0, 0 };
	uint32_t start_addr = 0;
	uint16_t loop = 0;
	loop = (fw_size % READ_ONE_TIME != 0) ?
		       ((fw_size / READ_ONE_TIME) + 1) :
		       (fw_size / READ_ONE_TIME);

	for (int i = 0; i < loop; i++) {
		// flash to fifo
		write_i2c_byte(client, 0x5E, 0x5f);
		write_i2c_byte(client, 0x5A, 0x20);
		write_i2c_byte(client, 0x5A, 0x00);

		// set reading address
		write_i2c_byte(client, 0x5B, key_addr[0]);
		write_i2c_byte(client, 0x5C, key_addr[1]);
		write_i2c_byte(client, 0x5D, key_addr[2]);

		write_i2c_byte(client, 0x5A, 0x10);
		write_i2c_byte(client, 0x5A, 0x00);

		write_i2c_byte(client, 0x58, 0x21);
		// read 32 bytes of data from SPI FIFO
		(void)read_i2c_n_byte(client, 0x5F,
				      &(fw_data[i * READ_ONE_TIME]), 0x20);

		start_addr += READ_ONE_TIME;
		key_addr[0] = (start_addr & 0xFF0000) >> 16;
		key_addr[1] = (start_addr & 0xFF00) >> 8;
		key_addr[2] = (start_addr & 0xFF);
		if ((i % READ_FW_DELAY_CNT) == 0) {
			msleep(READ_FW_DELAY_MS);
		}
	}
	flash_write_disable(client);
}

static int lt6911gxd_flash_validate(struct i2c_client *client,
				    const struct update_para *para)
{
	uint8_t *fw = NULL;
	hwlog_info("%s: begin\n", __func__);

	if (!client || !para) {
		hwlog_err("%s: input params null\n", __func__);
		return UPDATE_ECODE_NULL_PTR;
	}

	if (para->bin_file1_size == 0 || para->bin_file1 == NULL) {
		hwlog_err("bin_file1 err\n");
		return UPDATE_ECODE_PARA;
	}

	fw = kzalloc(para->bin_file1_size, GFP_KERNEL);
	if (fw == NULL) {
		hwlog_err("kzalloc err\n");
		return UPDATE_ECODE_KZALLOC;
	}
	lt6911gxd_read_fw(client, fw, para->bin_file1_size);
	if (memcmp(fw, para->bin_file1, para->bin_file1_size)) {
		hwlog_err("firmware read memcmp err\n");
		kfree(fw);
		fw = NULL;
		return UPDATE_ECODE_FW_MEM_COMP;
	}
	kfree(fw);
	fw = NULL;

	hwlog_info("%s: success\n", __func__);
	return UPDATE_ECODE_OK;
}

static int lt6911gxd_flash_proc(struct i2c_client *client,
				struct update_para *update_param,
				bool update_mode, hard_reset_func_t reset_func)
{
	uint8_t *fw_file = NULL;
	int fw_size;
	uint16_t ic_ver = 0;
	struct device_node *node = NULL;
	if (!client || !update_param || !reset_func) {
		hwlog_err("%s: flash proc input params null\n", __func__);
		return UPDATE_ECODE_NULL_PTR;
	}
	reset_func();
	msleep(RESET_AFTER_DELAY);
	if (lt6911gxd_get_ic_version(client, &ic_ver) != UPDATE_ECODE_OK) {
		hwlog_err("%s:get_ic_ver fail at begin", __func__);
	} else {
		int ret = lt6911gxd_version_check(update_param, ic_ver);
		if (ret == UPDATE_ECODE_NO_NEW) {
			return UPDATE_ECODE_OK;
		}
		if (ret != UPDATE_ECODE_OK) {
			hwlog_err("%s:ver_check err\n", __func__);
			return ret;
		}
	}
	node = client->dev.of_node;
	if (lt6911gxd_read_fw_file(node, update_param) != UPDATE_ECODE_OK) {
		hwlog_err("[%s:] read firmware file fail!!!\n", __func__);
		return UPDATE_ECODE_VFS_READ;
	}
	fw_file = update_param->bin_file1;
	fw_size = update_param->bin_file1_size;
	lt6911gxd_write_with_sram(client, fw_file, fw_size);
	if (lt6911gxd_flash_validate(client, update_param) != UPDATE_ECODE_OK) {
		hwlog_err("flash validate fail.");
		return UPDATE_ECODE_FW_MEM_COMP;
	}
	reset_func();
	msleep(RESET_AFTER_DELAY);
	ic_ver = 0;
	if (lt6911gxd_get_ic_version(client, &ic_ver) != UPDATE_ECODE_OK) {
		hwlog_err("%s: get_ic_version failed at end.\n", __func__);
		return UPDATE_ECODE_GET_IC_VER;
	}
	if (ic_ver != update_param->firmware_version) {
		hwlog_err("%s: ver check after.ic=%u, tar=%d\n", __func__,
			  ic_ver, update_param->firmware_version);
	}
	return UPDATE_ECODE_OK;
}

/***
 *
 * @param client i2c_client
 * @param update_mode 1 silent update, reboot to effect;0 effect Immediately,usb may disconnect
 * @return
 */
int lt6911gxd_update(struct i2c_client *client, struct device_node *node,
		     bool update_mode, hard_reset_func_t reset_func)
{
	int ret;
	struct update_para update_param = { 0, 0, 0 };
	hwlog_info("%s: begin\n", __func__);

	if (!client || !node || !reset_func) {
		hwlog_err("update firmware input params fail\n");
		return UPDATE_ECODE_NULL_PTR;
	}

	ret = lt6911gxd_update_param_init(node, &update_param);
	if (ret != UPDATE_ECODE_OK) {
		hwlog_err("update param init fail!!!\n");
		reset_func();
		msleep(RESET_AFTER_DELAY);
		return ret;
	}

	for (int i = 0; i < UPDATE_TRY_TIMES; ++i) {
		ret = lt6911gxd_flash_proc(client, &update_param, update_mode,
					   reset_func);
		if (ret == UPDATE_ECODE_OK) {
			break;
		}
		msleep(UPDATE_TRY_DLY_MS);
	}

	if (update_param.bin_file1_size != 0) {
		kfree(update_param.bin_file1);
		update_param.bin_file1 = NULL;
		update_param.bin_file1_size = 0;
	}

	if (ret != UPDATE_ECODE_OK) {
		hwlog_err("lt6911gxd_flash_proc fail\n");
		return ret;
	}
	hwlog_info("%s: success\n", __func__);
	return ret;
}
