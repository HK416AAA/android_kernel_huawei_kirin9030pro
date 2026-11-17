/*
 * echub_basp.c
 *
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
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#include "securec.h"
#include "echub_battery.h"
#include "ospm_printf.h"
#include "echub_basp.h"
 
#define DECIMAL_COUNT_BASE 10000
#define DECIMAL_DIVISOR 100

#define EC_I2C_READ  1
#define EC_I2C_WRITE 0
#define EC_I2C_READ_CHECK  2
#define EC_I2C_WRITE_CHECK 3
#define EC_I2C_BUSY_FLAG   1
#define EC_SPECIAL_REG  0x44
#define FCL_FLASH_W_ADDR 0x7777
#define FCL_PAGE_ADDR 0x77

#define BATT_MODEL_MAX_LEN 21
#define I2C_DATA_MAX_LEN 32
#define I2C_SEND_MAX_LEN 37    // 5 + 32
#define I2C_RECV_MAX_LEN 34	   // 2 + 32
#define I2C_SEND_BUF_OFFSET 5
#define I2C_RECV_BUF_OFFSET 2

#define NORMAL_WRITE_BUFLEN 11
#define UNLOCK_CMD_LEN 4
#define STORE_DATA_MAX_LEN 4
#define I2C_LOCK_LEN 2
#define BASP_VERSION_BYTE 32

#define SHIFT_OFFSET_1_BYTE 8
#define SHIFT_OFFSET_2_BYTE 16
#define SHIFT_OFFSET_3_BYTE 24
#define SHIFT_OFFSET_5_BITS 5
#define SHIFT_OFFSET_9_BITS 9

#define BASP_READ_BACK_ENABLE   1
#define BASP_READ_BACK_DISABLE  0

#define BATT_I2C_LOCK_BEGIN   0x55
#define BATT_I2C_LOCK_END     0xAA

#define BATT_DEFAULT_VERSION  0xA1
#define EC_BASP_NORMAL_REG_CMD      0x02C6

enum echub_basp_sysfs_type {
	ECHUB_BASP_SYSFS_BEGIN = 0,
	ECHUB_BASP_SYSFS_GAUGE_READ = ECHUB_BASP_SYSFS_BEGIN,
	ECHUB_BASP_SYSFS_GAUGE_WRITE,
	ECHUB_BASP_SYSFS_UNLOCK_BATT,
	ECHUB_BASP_SYSFS_LOCK_BATT,
	ECHUB_BASP_SYSFS_BATT_DEVICENAME,
	ECHUB_BASP_SYSFS_BATT_STATUS,
	ECHUB_BASP_SYSFS_BATT_SOFTVERSION,
	ECHUB_BASP_SYSFS_I2C_LOCK,
	ECHUB_BASP_SYSFS_END,
};

struct echub_basp_para_cmd {
	u32 type;
	u32 regbase;
	u32 rwflag;
	u32 initlen;    // the expected len read from os
	u32 address;
	u32 brflag;     // back read flag for write cmd   en/dis 1/0
};

static char g_normal_read_buf[I2C_DATA_MAX_LEN] = {0};

static struct echub_basp_para_cmd echub_basp_command_tbl[] = {
	{ECHUB_BASP_SYSFS_GAUGE_READ, 			0xFF, EC_I2C_READ,  0x20, 0xFFFF, 0},
	{ECHUB_BASP_SYSFS_GAUGE_WRITE, 			0xFF, EC_I2C_WRITE, 0xFF, 0xFFFF, 1},
	{ECHUB_BASP_SYSFS_UNLOCK_BATT, 		    0x00, EC_I2C_WRITE, 0x02, 0x0000, 0},
	{ECHUB_BASP_SYSFS_LOCK_BATT, 		  	0x44, EC_I2C_WRITE, 0x00, 0x0030, 0},
	{ECHUB_BASP_SYSFS_BATT_DEVICENAME, 		0x21, EC_I2C_READ,  0x10, 0x0000, 0},
	{ECHUB_BASP_SYSFS_BATT_STATUS, 		  	0x44, EC_I2C_READ,  0x04, 0x0054, 0},
	{ECHUB_BASP_SYSFS_BATT_SOFTVERSION,  	0x44, EC_I2C_READ,  0x20, 0x0070, 0},
};

static void comfig_write_buffer(char *buf, int len, int rwflag, struct echub_basp_para_cmd para)
{
	// write_buffer : reg(1byte) + rw(1byte) + slen(1byte) + offset(2) + buffer(N))
	buf[0] = para.regbase;                           // byte0 regbase
	buf[1] = rwflag;                                 // byte1 rwflag
	buf[2] = para.initlen;                           // byte2 sendbuf len
	buf[3] = (char)(para.address & 0xFF);            // byte3 address low byte
	buf[4] = para.address >> SHIFT_OFFSET_1_BYTE;    // byte4 address high byte
}

static int echub_basp_i2c_transfer(char* write_buffer, int wlen, char *read_buffer, int rlen)
{
	int ret = 0;
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("[%s] di is null\n", __func__);
		return -EINVAL;
	}
	ret = di->echub_dev->transfer_func(di->echub_dev, EC_BASP_NORMAL_REG_CMD,
		write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
	if (ret) {
		echub_err("[%s] cmd ERROR! ret=%d\n", __func__, ret);
		return -EINVAL;
	} else if (read_buffer[0] != EC_I2C_BUSY_FLAG || read_buffer[1] > I2C_DATA_MAX_LEN) {
		echub_err("[%s] ERROR! rbuf[0]=%d rbuf[1]=%d\n", __func__, read_buffer[0], read_buffer[1]);
		return -EINVAL;
	}
	return 0;
}

static int echub_basp_check_busy_state(char* write_buffer, int wlen, char *read_buffer, int rlen)
{
	int ret = 0;
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("[%s:%dL] di is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}

	for (int i = 0; i < 3; i++) { //  retry 3 times
		mdelay(10);    //    EC is busy, delay 10ms and retry
		ret = di->echub_dev->transfer_func(di->echub_dev, EC_BASP_NORMAL_REG_CMD,
			write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
		if (ret) {
			echub_err("[%s] cmd ERROR! ret=%d, retry_time : %d\n", __func__, ret, i + 1);
			continue;
		} else if (read_buffer[1] > I2C_DATA_MAX_LEN) {
			echub_err("[%s] read ERROR! rbuf[0]=%d rbuf[1]=%d  retry_time : %d\n",
				__func__, read_buffer[0], read_buffer[1], i + 1);
			continue;
		}

		if (read_buffer[0] == EC_I2C_BUSY_FLAG)
			return 0;
	}
	echub_err("[%s] 3 times retry! ec is busy\n", __func__);
	return -EINVAL;
}

static int get_read_buf_from_ec(char* buf, int len, struct echub_basp_para_cmd para)
{
	int ret = 0;
	int i;
	char* write_buffer = NULL;
	char* read_buffer = NULL;

	write_buffer = kzalloc(I2C_SEND_MAX_LEN, GFP_KERNEL);
	if (!write_buffer)
		return -ENOMEM;
	read_buffer = kzalloc(I2C_RECV_MAX_LEN, GFP_KERNEL);
	if (!read_buffer) {
		kfree(write_buffer);
		return -ENOMEM;
	}
	/* 0x44 RegBase Commands need to write offset before read */
	if (para.regbase == EC_SPECIAL_REG) {
		comfig_write_buffer(write_buffer, I2C_SEND_MAX_LEN, EC_I2C_WRITE, para);
		write_buffer[2] = 0;    // byte 2 the write command length must be 0
		ret = echub_basp_i2c_transfer(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
		if (ret) {
			write_buffer[1] = EC_I2C_WRITE_CHECK; // byte1 rwflag
			if (echub_basp_check_busy_state(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN)) {
				echub_err("[%s] read back write check fail exit!\n", __func__);
				goto read_free_mem;
			}
		}
	}
	comfig_write_buffer(write_buffer, I2C_SEND_MAX_LEN, EC_I2C_READ, para);
	ret = echub_basp_i2c_transfer(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
	if (ret) {
		write_buffer[1] = EC_I2C_READ_CHECK; // byte1 rwflag
		ret = echub_basp_check_busy_state(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
		if (ret) {
			echub_err("[%s] read back read check fail exit!\n", __func__);
			ret = -EINVAL;
			goto read_free_mem;
		}
	}

	if (read_buffer[1] < 0 || read_buffer[1] > I2C_DATA_MAX_LEN) {
		echub_err("[%s] read_buffer invalid! size = %d\n", __func__, read_buffer[1]);
		goto read_free_mem;
	}
	for (i = 0; i < read_buffer[1]; i++)
		buf[i] = read_buffer[i + I2C_RECV_BUF_OFFSET];

read_free_mem:
	kfree(read_buffer);
	kfree(write_buffer);
	return ret;
}

static int set_write_buffer_to_ec(const char *buf, size_t count, struct echub_basp_para_cmd para)
{
	int ret = 0;
	char* write_buffer = NULL;
	char* read_buffer = NULL;

	write_buffer = kzalloc(I2C_SEND_MAX_LEN, GFP_KERNEL);
	if (!write_buffer)
		return -ENOMEM;
	read_buffer = kzalloc(I2C_RECV_MAX_LEN, GFP_KERNEL);
	if (!read_buffer) {
		kfree(write_buffer);
		return -ENOMEM;
	}

	if (para.initlen > I2C_DATA_MAX_LEN)
		goto write_free_mem;

	/* config write buffer */
	comfig_write_buffer(write_buffer, I2C_SEND_MAX_LEN, EC_I2C_WRITE, para);
	ret = memcpy_s(write_buffer + I2C_SEND_BUF_OFFSET, I2C_DATA_MAX_LEN, buf, para.initlen);
	if (ret) {
		echub_err("[%s] memcpy_s failed\n", __func__);
		goto write_free_mem;
	}
	// recheck regstatus
	ret = echub_basp_i2c_transfer(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
	if (ret) {
		write_buffer[1] = EC_I2C_WRITE_CHECK; // byte 1 rwflag
		ret = echub_basp_check_busy_state(write_buffer, I2C_SEND_MAX_LEN, read_buffer, I2C_RECV_MAX_LEN);
		if (ret)
			goto write_free_mem;
	}
	// Read back buffer to check if write success
	if (para.brflag == BASP_READ_BACK_ENABLE) {
		(void)memset_s(read_buffer, I2C_RECV_MAX_LEN, 0, I2C_RECV_MAX_LEN);
		ret = get_read_buf_from_ec(read_buffer, I2C_RECV_MAX_LEN, para);
		if (ret) {
			echub_err("[%s] Read back i2c read fail ret = %d\n", __func__, ret);
			goto write_free_mem;
		}
		ret = strncmp(buf, read_buffer, para.initlen);
		if (ret)
			echub_err("[%s] recheck reg data failed!\n", __func__);
	}
write_free_mem:
	kfree(read_buffer);
	kfree(write_buffer);
	return ret;
}

static ssize_t echub_basp_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf);
static ssize_t echub_basp_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info echub_basp_sysfs_field_tbl[] = {
	power_sysfs_attr_rw(echub_basp, 0660, ECHUB_BASP_SYSFS_GAUGE_READ,  	 read_gauge),
	power_sysfs_attr_wo(echub_basp, 0220, ECHUB_BASP_SYSFS_GAUGE_WRITE, 	 write_gauge),
	power_sysfs_attr_wo(echub_basp, 0220, ECHUB_BASP_SYSFS_UNLOCK_BATT,      batt_unlock),
	power_sysfs_attr_wo(echub_basp, 0220, ECHUB_BASP_SYSFS_LOCK_BATT,        batt_lock),
	power_sysfs_attr_ro(echub_basp, 0440, ECHUB_BASP_SYSFS_BATT_DEVICENAME,  batt_devicename),
	power_sysfs_attr_ro(echub_basp, 0440, ECHUB_BASP_SYSFS_BATT_STATUS,      batt_status),
	power_sysfs_attr_rw(echub_basp, 0660, ECHUB_BASP_SYSFS_BATT_SOFTVERSION, batt_softversion),
	power_sysfs_attr_wo(echub_basp, 0220, ECHUB_BASP_SYSFS_I2C_LOCK,    	 batt_i2c_lock),
};

static int basp_show_print(char *buf, int buflen, char *temp, int len, int index)
{
	int ret;
	char lock_bit0, lock_bit1;

	switch (index) {
	case ECHUB_BASP_SYSFS_BATT_DEVICENAME:    // 21 bytes string for battery model
		ret = memset_s(buf, PAGE_SIZE, 0, len + 1);
		if (ret) {
			echub_err("[%s] memset_s failed\n", __func__);
			return 0;
		}
		ret = memcpy_s(buf, PAGE_SIZE, temp, len);
		if (ret) {
			echub_err("Failed to convert battery model, ret = %d\n", ret);
			return 0;
		}
		return len;
	case ECHUB_BASP_SYSFS_BATT_STATUS:    // Status[bit9: bit8] ( 11=lock  10=halflock  01=unlock )
		lock_bit0 = (temp[1] & 0x01) == 0x01 ? 1 : 0;    // bit8
		lock_bit1 = (temp[1] & 0x02) == 0x02 ? 1 : 0;    // bit9
		echub_info("BATT_STATUS lock_bit1:lock_bit0 = %d:%d\n", lock_bit1, lock_bit0);
		return scnprintf(buf, PAGE_SIZE, "%d%d", lock_bit1, lock_bit0);
	case ECHUB_BASP_SYSFS_BATT_SOFTVERSION:    // basp version is the no.32 byte of read buffer
		echub_info("BASP VERSION READ 32 BYTE value = 0x%x\n", temp[BASP_VERSION_BYTE - 1]);
		return scnprintf(buf, PAGE_SIZE, "%x", temp[BASP_VERSION_BYTE - 1]);
	default:
		return 0;
	}
}

static int basp_store_input_transfer(const char *buf, int buflen, char *temp, int len, struct echub_basp_para_cmd para)
{
	int ret, i;
	u32 num;

	switch (para.type) {
	case ECHUB_BASP_SYSFS_UNLOCK_BATT:    // unlock type : 0xAABBCCDD  4 BYTES
		ret = sscanf_s(buf, "0x%x", &num);
		if (ret != 1) {
    		echub_err("Failed to convert string to array, ret = %d\n", ret);
			return -EINVAL;
		}
		for (i = 0; i < UNLOCK_CMD_LEN; i++)
			temp[i] = (char)((num >> (SHIFT_OFFSET_1_BYTE * i)) & 0xFF);
		break;

	case ECHUB_BASP_SYSFS_LOCK_BATT:    // lock type do not need data input
		echub_info("LOCK_BATT do nothing to input para!\n");
		break;

	default:    // default transfer inputbuf to 1 byte uint num
		ret = kstrtouint(buf, 0, &num);
		if (ret < 0) {
			echub_err("transfer to int fail\n");
			return ret;
		}
		echub_info("[%s] transfer to uint : 0x%x\n", __func__, num);
		if (para.initlen > I2C_DATA_MAX_LEN) {
			echub_err("[%s] para.initlen is invalid! len = %d\n", __func__, para.initlen);
			return -EINVAL;
		}
		for (i = 0; i < para.initlen; i++)
			temp[i] = (char)(num >> (SHIFT_OFFSET_1_BYTE * i));
	}
	return 0;
}

static int basp_ascii2hex(char c)
{
	int res = 0;

	if (c >= '0' && c <= '9') {
		res = c - '0';
	} else if (c >= 'a' && c <= 'f') {
		res = c - 'a' + 10;    // a is 10 in ascii table
	} else if (c >= 'A' && c <= 'F') {
		res = c - 'A' + 10;    // A is 10 in ascii table
	} else {
		echub_err("[%s] Input char is not match hex value\n", __func__);
		return -EINVAL;
	}

	return res;
}

static int basp_strtohex(char *str, int slen, char *rbuf, int rlen, int *cnt)
{
    int i, count = 0;
	char high, low;

    for (i = slen - 2; i >= 2; i -= 2) {    // exclude the first 2 char '0x'
        high = basp_ascii2hex(str[i]);
		low = basp_ascii2hex(str[i + 1]);
		if (high < 0 || low < 0) {
			echub_err("[%s] Failed to convert string to hex\n", __func__);
			return -EINVAL;
		}
		rbuf[count++] = (high * 16) + low; // 16:dec to hex
		if (i == 3 && slen % 2 != 0) // data 3 only 1 char when slen % 2 != 0
			rbuf[count++] = basp_ascii2hex(str[i - 1]);
    }

	*cnt = count;
    return 0;
}

static int gauge_read_get_paras(char* buf, int len)
{
	int ret;

	ret = memcpy_s(buf, len, g_normal_read_buf, I2C_DATA_MAX_LEN);
	if (ret) {
		echub_err("[%s] memcpy_s fail\n", __func__);
		return ret;
	}

	ret = memset_s(g_normal_read_buf, I2C_DATA_MAX_LEN, 0, I2C_DATA_MAX_LEN);
	if (ret)
		echub_err("[%s] memset_s fail\n", __func__);

	return ret;
}

static int normal_write_gauge_read(char* buf, int len, int regbase, int address)
{
	struct echub_basp_para_cmd *p_table = echub_basp_command_tbl;
	int ret;

	p_table[ECHUB_BASP_SYSFS_GAUGE_READ].regbase = regbase;
	p_table[ECHUB_BASP_SYSFS_GAUGE_READ].address = address;
	ret = get_read_buf_from_ec(buf, len, p_table[ECHUB_BASP_SYSFS_GAUGE_READ]);
	if (ret) {
		echub_err("[%s] get_read_buf_from_ec fail\n", __func__);
		return ret;
	}
	ret = memcpy_s(g_normal_read_buf, I2C_DATA_MAX_LEN, buf, len);
	if (ret)
		echub_err("[%s] memcpy_s fail\n", __func__);
	return ret;
}

static int normal_write_gauge_write(const char* buf, size_t count, char* temp, int len)
{
	struct echub_basp_para_cmd *p_table = echub_basp_command_tbl;
	char data[I2C_DATA_MAX_LEN] = {0};
	int ret, regbase, address, initlen;

	ret = sscanf_s(buf, "0x%x:0x%x:%s", &regbase, &address, data, sizeof(data));
	if (ret != 3) { // 3 para 0xaa:0xbbcc:"str"
		echub_err("[%s] GAUGE_WRITE para num not match! ret = %d\n", __func__, ret);
		return -EINVAL;
	}
	ret = basp_strtohex(data, strlen(data), temp, I2C_DATA_MAX_LEN, &initlen);
	if (ret) {
		echub_err("[%s] GAUGE_WRITE str err! ret = %d\n", __func__, ret);
		return -EINVAL;
	}
	p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].regbase = regbase;
	p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].address = address;
	p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].initlen = initlen;
	if (regbase == EC_SPECIAL_REG && address != FCL_FLASH_W_ADDR) {
		p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].brflag = BASP_READ_BACK_ENABLE;
	} else if (regbase == FCL_PAGE_ADDR || address == FCL_FLASH_W_ADDR) {
		p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].brflag = BASP_READ_BACK_DISABLE;
	} else {
		p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE].brflag = BASP_READ_BACK_ENABLE;
	}
	ret = set_write_buffer_to_ec(temp, I2C_DATA_MAX_LEN, p_table[ECHUB_BASP_SYSFS_GAUGE_WRITE]);
	if (ret)
		echub_err("[%s] set_write_buffer_to_ec fail! ret = %d\n", __func__, ret);
	return ret;
}

static int normal_write_para_to_ec(const char* buf, size_t count, int type)
{
	int ret, regbase, address;
	char *temp = NULL;

	if (count < NORMAL_WRITE_BUFLEN || count > I2C_DATA_MAX_LEN) {
		echub_err("[%s] store len(%d) is out of i2c source!\n", __func__, count);
		return -EINVAL;
	}
	temp = kzalloc(I2C_DATA_MAX_LEN, GFP_KERNEL);
	if (!temp) {
		echub_err("[%s] alloc temp buffer fail\n", __func__);
		return -ENOMEM;
	}
	if (type == ECHUB_BASP_SYSFS_GAUGE_READ) {
		// only send regoffset, must be a write before normal read.
		ret = sscanf_s(buf, "0x%x:0x%x", &regbase, &address);
		if (count == NORMAL_WRITE_BUFLEN && ret == 2) { // 2 para 0xaa:0xbbcc
			ret = normal_write_gauge_read(temp, I2C_DATA_MAX_LEN, regbase, address);
			if (ret)
				echub_err("[%s] normal_write_gauge_read fail\n", __func__);
			goto normal_write_free;
		}
		echub_err("[%s] GAUGE_READ para num not match! ret = %d\n", __func__, ret);
	} else if (type == ECHUB_BASP_SYSFS_GAUGE_WRITE) {
		ret = normal_write_gauge_write(buf, count, temp, I2C_DATA_MAX_LEN);
		if (ret)
			echub_err("[%s] normal_write_gauge_write fail\n", __func__);
	} else {
		echub_err("[%s] type is not matched!\n", __func__);
		ret = -EINVAL;
	}
normal_write_free:
	kfree(temp);
	return ret;
}

static int echub_basp_unlock_battery(const char* buf, size_t count)
{
	struct echub_basp_para_cmd *p_table = echub_basp_command_tbl;
	int ret;
	char temp[I2C_SEND_MAX_LEN] = { 0 };
	char temp1[I2C_SEND_MAX_LEN] = { 0 };
	char temp2[I2C_SEND_MAX_LEN] = { 0 };

	ret = basp_store_input_transfer(buf, PAGE_SIZE, temp, I2C_SEND_MAX_LEN, p_table[ECHUB_BASP_SYSFS_UNLOCK_BATT]);
	if (ret < 0) {
		echub_err("[%s] basp_store_input_transfer fail\n", __func__);
		return ret;
	}
	// unlock type : 0xAABBCCDD  4 BYTES
	temp1[0] = temp[0]; // Unlock code byte 0
	temp1[1] = temp[1]; // Unlock code byte 1
	ret = set_write_buffer_to_ec(temp1, I2C_SEND_MAX_LEN, p_table[ECHUB_BASP_SYSFS_UNLOCK_BATT]);
	if (ret) {
		echub_err("[%s:%dL]Failed to write first byte to ec\n", __func__, __LINE__);
		return ret;
	}
	temp2[0] = temp[2]; // Unlock code byte 2
	temp2[1] = temp[3]; // Unlock code byte 3
	ret = set_write_buffer_to_ec(temp2, I2C_SEND_MAX_LEN, p_table[ECHUB_BASP_SYSFS_UNLOCK_BATT]);
	if (ret)
		echub_err("[%s:%dL]Failed to write last byte to ec\n", __func__, __LINE__);
	return ret;
}

static int echub_basp_lock_battery(const char* buf, size_t count)
{
	struct echub_basp_para_cmd *p_table = echub_basp_command_tbl;
	int ret;
	char temp[I2C_SEND_MAX_LEN] = { 0 };

	ret = basp_store_input_transfer(buf, PAGE_SIZE, temp, I2C_SEND_MAX_LEN, p_table[ECHUB_BASP_SYSFS_LOCK_BATT]);
	if (ret < 0) {
		echub_err("[%s] basp_store_input_transfer fail\n", __func__);
		return ret;
	}

	ret = set_write_buffer_to_ec(temp, I2C_SEND_MAX_LEN, p_table[ECHUB_BASP_SYSFS_LOCK_BATT]);
	if (ret)
		echub_err("[%s:%dL]Failed to write last byte to ec\n", __func__, __LINE__);
	return ret;
}

static int echub_basp_batt_i2c_lock(const char *buf, int count)
{
	int ret, type;
	char sbuf[I2C_LOCK_LEN] = {0};
	char rbuf[I2C_LOCK_LEN] = {0};
	struct echub_batt_device_info *di = echub_get_batt_di();

	if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
		echub_err("%s di is null\n", __func__);
		return -EINVAL;
	}

	ret = kstrtouint(buf, 0, &type);
	if (ret < 0 || (type != 0 && type != 1)) {
		echub_err("[%s] transfer to int fail. type = 0x%x\n", __func__, type);
		return ret;
	}
	
	sbuf[0] = (type == 0) ? BATT_I2C_LOCK_END : BATT_I2C_LOCK_BEGIN;
	sbuf[1] = BATT_DEFAULT_VERSION;
	ret = di->echub_dev->transfer_func(di->echub_dev, 0x02EC, sbuf, I2C_LOCK_LEN, rbuf, I2C_LOCK_LEN);
	if (ret < 0) {
		echub_err("[%s] batt_i2c_lock fail! type = %d\n", __func__, type);
		return ret;
	}
	if (type == 1)
		mdelay(1000); // 1000ms wait EC after i2c lock command
	return ret;
}

#ifdef CONFIG_SYSFS

#define ECHUB_BASP_SYSFS_ATTRS_SIZE  ARRAY_SIZE(echub_basp_sysfs_field_tbl)

static struct attribute *echub_basp_sysfs_attrs[ECHUB_BASP_SYSFS_ATTRS_SIZE + 1];

static const struct attribute_group echub_basp_group = {
	.attrs = echub_basp_sysfs_attrs,
};

static ssize_t echub_basp_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct echub_basp_para_cmd *p_table = echub_basp_command_tbl;
	int i, ret;
	int len = 0;
	char temp[I2C_DATA_MAX_LEN] = { 0 };

	if (!buf || !attr) {
		echub_err("[%s:%dL] input buf or attr is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	info = power_sysfs_lookup_attr(attr->attr.name,
		echub_basp_sysfs_field_tbl, ECHUB_BASP_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;

	if (info->name == ECHUB_BASP_SYSFS_GAUGE_READ) {
		echub_info("basp show normal func!\n");
		ret = gauge_read_get_paras(temp, I2C_DATA_MAX_LEN);
		if (ret)
			return -EINVAL;
		return scnprintf(buf, PAGE_SIZE, "%s", temp);
	}

	for (i = 0; i < ECHUB_BASP_SYSFS_ATTRS_SIZE; i++) {
		if (info->name == p_table[i].type && p_table[i].rwflag == EC_I2C_READ) {
			echub_info("basp show usual func!\n");
			ret = get_read_buf_from_ec(temp, I2C_DATA_MAX_LEN, p_table[i]);
			if (ret) {
				echub_err("[%s] Read back i2c read fail ret = %d\n", __func__, ret);
				return -EINVAL;
			}
			len = p_table[i].initlen;
			break;
		}
	}

	return basp_show_print(buf, PAGE_SIZE, temp, len, info->name);
}

static ssize_t echub_basp_sysfs_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct power_sysfs_attr_info *info = NULL;
	int ret;

	mdelay(10); // delay 10ms for each write operation
	if (!buf || !attr) {
		echub_err("[%s:%dL] input buf or attr is NULL\n", __func__, __LINE__);
		return -EINVAL;
	}
	info = power_sysfs_lookup_attr(attr->attr.name, echub_basp_sysfs_field_tbl, ECHUB_BASP_SYSFS_ATTRS_SIZE);
	if (!info)
		return -EINVAL;
	
	switch (info->name) {
	case ECHUB_BASP_SYSFS_GAUGE_READ:
	case ECHUB_BASP_SYSFS_GAUGE_WRITE:
		ret = normal_write_para_to_ec(buf, count, info->name);
		if (ret) {
			echub_err("[%s:%dL] basp store normal func fail\n", __func__, __LINE__);
			return -EINVAL;
		}
		return count;
	case ECHUB_BASP_SYSFS_UNLOCK_BATT:
		ret = echub_basp_unlock_battery(buf, count);
		if (ret) {
			echub_err("[%s:%dL] basp store unlock battery func fail\n", __func__, __LINE__);
			return -EINVAL;
		}
		return count;
	case ECHUB_BASP_SYSFS_LOCK_BATT:
		ret = echub_basp_lock_battery(buf, count);
		if (ret) {
			echub_err("[%s:%dL] basp store unlock battery func fail\n", __func__, __LINE__);
			return -EINVAL;
		}
		return count;
	case ECHUB_BASP_SYSFS_I2C_LOCK:
		ret = echub_basp_batt_i2c_lock(buf, count);
		if (ret) {
			echub_err("[%s:%dL] basp store i2c lock func fail\n", __func__, __LINE__);
			return -EINVAL;
		}
		return count;
	default:
		echub_err("[%s:%dL] command not found\n", __func__, __LINE__);
		return -EINVAL;
	}
}

struct device *echub_basp_create_group(void)
{
	power_sysfs_init_attrs(echub_basp_sysfs_attrs,
		echub_basp_sysfs_field_tbl, ECHUB_BASP_SYSFS_ATTRS_SIZE);
	return power_sysfs_create_group("hw_echub", "echub_basp",
		&echub_basp_group);
}

void echub_basp_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &echub_basp_group);
}
#else
struct device *echub_basp_create_group(void)
{
	return NULL;
}
 
void echub_basp_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */