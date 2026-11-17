/*
 * Huawei freetouch btl ic firmware update
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

#include "btl_firmware_update.h"
#include <linux/i2c.h>
#include <linux/delay.h>
#include <securec.h>
#include "touchpad_log.h"
#include "touchpad_tp_ic_update.h"


#define BTL_DELAY_MS			msleep
#define TP_LOG_PRINTF			tp_log_info
#define BTL_BSP_I2C_TRANSFER		bsp_iic_tp_transfer

#define BTL_WIN_SYS_HEAD_SIZE		8
#define BTL_RX_REPORT_SIZE			(64)										/* from pack_len to data */
#define BTL_RX_VALID_DATA_SIZE		(BTL_RX_REPORT_SIZE - 7)						/* custom header size: 7(except report_id) */
#define BTL_RX_SYS_PACK_TOTLE_SIZE	(BTL_WIN_SYS_HEAD_SIZE + BTL_RX_REPORT_SIZE + 1)	/* one byte of report_id */

#define BTL_WIN_SYS_RX_HEAD_SIZE	6											/* tx_custom_header size except data */
#define BTL_TX_PACK_DATA_SIZE		64
#define BTL_TX_PACK_VALID_SIZE		(BTL_TX_PACK_DATA_SIZE - BTL_WIN_SYS_RX_HEAD_SIZE)
#define BTL_TX_PACK_TOTLE_SIZE		(BTL_TX_PACK_DATA_SIZE + 2)						/* two byte of report_len */

#define BTL_HID_DESC_SIZE			30
#define BTL_TP_IC_VERSION_LEN		2
#define BTL_CHIP_TYPE			0x41
#define BTL_FALSH_PAGE 				256
#define BTL_FALSH_SECTOR			512
#define BTL_FALSH_PAGE_PER_SECTOR	BTL_FALSH_SECTOR/BTL_FALSH_PAGE
#define BTL_BOOT_SECTOR_NUM		8
#define BTL_BIN_VER_OFFSET		(0xfc2a)
#define BTL_CHECKSUM_COMPLETE		1

/* 延时常量、重试常量 */
#define BTL_DELAY_TIME_1	1
#define BTL_DELAY_TIME_5	5
#define BTL_DELAY_TIME_10	10
#define BTL_DELAY_TIME_12	12
#define BTL_DELAY_TIME_20	20
#define BTL_DELAY_TIME_30	30
#define BTL_DELAY_TIME_50	50
#define BTL_DELAY_TIME_60	60
#define BTL_DELAY_TIME_1100	1100
#define BTL_RETRY_TIME_3	3
#define BTL_RETRY_TIME_5	5
#define BTL_RETRY_TIME_2	2
#define BTL_RETRY_TIME_40	40

struct st_hid_rx_custom_header {
	uint8_t report_id;
	uint8_t pack_len;	/* 此byte之后的包长度 */
	uint8_t checksum;
	uint8_t flag;
	uint8_t wlen_high;
	uint8_t wlen_low;
	uint8_t rlen_high;
	uint8_t rlen_low;
	uint8_t data[BTL_RX_VALID_DATA_SIZE + 1];	/* avoid overflow */
} __packed;

struct st_hid_rx_header {
	uint8_t sys_header[BTL_WIN_SYS_HEAD_SIZE];
	struct st_hid_rx_custom_header custom_header;
} __packed;

struct st_hid_tx_custom_header {
	uint16_t report_len;
	uint8_t report_id;
	uint8_t pack_len;
	uint8_t checksum;
	uint8_t flag;
	uint8_t data[BTL_TX_PACK_VALID_SIZE + 1];	/* avoid overflow */
} __packed;

enum {	/* 错误信息 */
	BTL_ERR_OK = 0,
	BTL_ERR_NEED_NOT_UPDATE,	/* 固件已是最新，不需要更新 */
	BTL_ERR_IIC_COM_FAIL,		/* IIC通信错误 */
	BTL_ERR_NORESPONSE,			/* transfer 无响应 */
	BTL_ERR_BIN_FMT_INVALID,	/* BIN文件的格式不对 */
	BTL_ERR_VER_READ_FAIL,		/* 读TP的版本错误 */
	BTL_ERR_UPDATE_FAIL,		/* 更新固件失败 */
	BTL_ERR_CHECKSUM_FAIL,		/* 更新完后，校验和检测错误 */
	BTL_ERR_ESD_FAIL,			/* 初始错误信息，没有执行到更新错误信息的位置 */
	BTL_ERR_ENTER_BURN_MODE,	/* 进入 burn_mode 失败 */
	BTL_ERR_READ_CHIPTYPE,		/* 读芯片错误 */
	BTL_ERR_EREASE_FLASH,		/* 清空flash错误 */
	BTL_ERR_EREASE_ENTIRE_FLASH,
	BTL_ERR_SWITCH_IIC,			/* switch to iic 错误 */
	BTL_ERR_FW_VER,				/* 读固件版本信息错误 */
	BTL_ERR_EXIT_BURN_MODE,		/* 退出 burn_mode 失败 */
	BTL_ERR_SOFT_RESET,			/* soft_reset 出错*/
	BTL_ERR_IIC_TRANSFER,		/* i2c_transfer_data 错误*/
	BTL_ERR_TPMODE_SWITCH,		/* switch to tpmode error*/
	BTL_ERR_EXIT_WFLASH,		/* 退出写flash模式失败 */
	BTL_ERR_CHIPID_UNMATCHED,	/* check_hid_des内出错*/
	BTL_ERR_UPDATE_RESET,		/* 更新前的复位操作失败 */
	BTL_ERR_ERASE_SECTOR,		/* sector擦除失败 */
	BTL_ERR_WRITE_SECTOR,		/* 写sector失败 */
	BLT_ERR_WRITE_PAGE,			/* 单页写失败 */
	BTL_ERR_WRITE_PAGE_TWICE,	/* 连续2次写page失败 */
};

/*
 * @brief	每8bit按位异或
 */
uint8_t cal_check_sum(uint8_t data[], uint8_t len)
{
	uint8_t i;
	uint8_t checksum;

	if (!data) {
		TP_LOG_PRINTF("check sum err, invalid value\n");
		return 0;
	}

	checksum = 0;
	for (i = 0; i < len; i++) {
		checksum ^= data[i];
	}
	checksum += 1;
	return checksum;
}

static int bsp_iic_tp_transfer(struct i2c_client *client, uint8_t* wbuf, uint16_t wlen, uint8_t* rbuf, uint16_t rlen)
{
	return i2c_transfer_data(client, wbuf, wlen, rbuf, rlen);
}

static int do_hid_transfer(struct i2c_client *client, uint8_t* wbuf, uint16_t wlen, uint8_t* rbuf, uint16_t rlen)
{
	int retry;
	int ret;
	struct st_hid_tx_custom_header* p_tx_header;

	if (!client || !wbuf || !rbuf) {
		TP_LOG_PRINTF("hid transfe enter error, invalid value\n");
		return -EINVAL;
	}

	/* retry 5 times */
	for (retry = 0; retry < BTL_RETRY_TIME_5; retry++) {
		ret = BTL_BSP_I2C_TRANSFER(client, wbuf, BTL_WIN_SYS_RX_HEAD_SIZE, rbuf, BTL_TX_PACK_TOTLE_SIZE);
		if (ret) {
			TP_LOG_PRINTF("I2C Transfer Rx Error[%d] error %d\n", retry, ret);
			ret = BTL_ERR_IIC_TRANSFER;
			BTL_DELAY_MS(BTL_DELAY_TIME_10);	/* delay 10ms and retry */
			continue;
		} else {
			p_tx_header = (struct st_hid_tx_custom_header*)(rbuf);
			if (p_tx_header->flag == 2) {			/* 2: pending */
				ret = BTL_ERR_IIC_TRANSFER;
				BTL_DELAY_MS(BTL_DELAY_TIME_12);					/* delay 12ms and retry */
				continue;
			} else if (p_tx_header->flag == 0xff)	/* noresponse */
				return BTL_ERR_NORESPONSE;

			TP_LOG_PRINTF("flag: %d\n", p_tx_header->flag);
			break;
		}
	}

	return ret;
}

static int iic_hid_write(struct i2c_client *client, uint8_t wbuf[], uint16_t wlen, uint16_t rlen)
{
	uint8_t wpack_buf[BTL_RX_SYS_PACK_TOTLE_SIZE] = { 0x05, 0x00, 0x2e, 0x03, 0x06, 0x00, 0x43, 0x00 };	/* win system header */
	uint16_t package_size;
	uint16_t package_left_size;
	uint8_t frame_flag = 0x0;	/* mean the first frame */
	int ret;
	struct st_hid_rx_custom_header* p_rx_header = &(((struct st_hid_rx_header*)wpack_buf)->custom_header);
	if (!client) {
		TP_LOG_PRINTF("hid write enter error\n");
		return -EINVAL;
	}
	p_rx_header->report_id = 0x0e;	/* touch pad report id */
	p_rx_header->wlen_high = (uint8_t)(wlen >> 8);
	p_rx_header->wlen_low = (uint8_t)(wlen);
	p_rx_header->rlen_high = (uint8_t)(rlen >> 8);
	p_rx_header->rlen_low = (uint8_t)(rlen);
	package_left_size = wlen;
	while (package_left_size > 0) {
		if (package_left_size > BTL_RX_VALID_DATA_SIZE)
			package_size = BTL_RX_VALID_DATA_SIZE;
		else
			package_size = package_left_size;
		ret = memset_s(p_rx_header->data, BTL_RX_VALID_DATA_SIZE, 0x0, package_size);
		if (ret) {
			TP_LOG_PRINTF("set data err, memset ret: %d\n", ret);
			return ret;
		}
		p_rx_header->pack_len = package_size + 6;	/* 6 means the size in custom_header from pack_len(end) to data(start) */
		p_rx_header->flag = frame_flag;

		ret = memcpy_s(p_rx_header->data, BTL_RX_VALID_DATA_SIZE, wbuf, package_size);
		if (ret) {
			TP_LOG_PRINTF("cpy data err, memcpy ret: %d\n", ret);
			return ret;
		}
		p_rx_header->checksum = cal_check_sum(&(p_rx_header->flag), p_rx_header->pack_len - 1);	/* check from flag to data(end) */
		frame_flag = 0x01;	/* the following frame is not the head */

		ret = BTL_BSP_I2C_TRANSFER(client, wpack_buf, BTL_RX_SYS_PACK_TOTLE_SIZE, NULL, 0);
		if (ret != BTL_ERR_OK) {
			TP_LOG_PRINTF("I2C Transfer Error %d\n", ret);
			return BTL_ERR_IIC_TRANSFER;
		}
		wbuf += package_size;
		package_left_size -= package_size;
	}
	BTL_DELAY_MS(BTL_DELAY_TIME_10);
	return BTL_ERR_OK;
}

static int iic_hid_read(struct i2c_client *client, uint8_t rbuf[], uint16_t rlen)
{
	uint8_t rx_header_buf[BTL_WIN_SYS_RX_HEAD_SIZE] = { 0x05, 0x00, 0x1e, 0x02, 0x06, 0x00 };	/* tx_custom_header */
	uint8_t rpack_buf[BTL_TX_PACK_TOTLE_SIZE + 1];
	uint16_t package_size;
	uint16_t package_left_size;
	int ret;
	struct st_hid_tx_custom_header* p_tx_header;

	if (!client || !rbuf) {
		TP_LOG_PRINTF("hid read enter error\n");
		return -EINVAL;
	}

	package_left_size = rlen;
	while (package_left_size > 0) {
		rpack_buf[0] = 0x0e;	/* before head to show package length */

		if (package_left_size > BTL_TX_PACK_VALID_SIZE)
			package_size = BTL_TX_PACK_VALID_SIZE;
		else
			package_size = package_left_size;

		ret = do_hid_transfer(client, rx_header_buf, BTL_WIN_SYS_RX_HEAD_SIZE, rpack_buf, BTL_TX_PACK_TOTLE_SIZE);	/* retry 5 times */
		if(ret)
			return ret;

		p_tx_header = (struct st_hid_tx_custom_header*)(rpack_buf);
		memcpy_s(&rbuf[rlen - package_left_size], BTL_TX_PACK_VALID_SIZE, p_tx_header->data, package_size);
		package_left_size -= package_size;
	}
	if (rlen > 0)
		BTL_DELAY_MS(BTL_DELAY_TIME_10);

	return BTL_ERR_OK;
}

/**
 * @description: 
 * @brief: 函数描述
 * @return {int}	0：成功。BTL_ERR_IIC_TRANSFER：调用接口出错
 * @Date: 2024-04-18 19:12:10
 * @param {i2c_client} *client
 * @param {uint8_t} wbuf
 * @param {uint16_t} wlen
 * @param {uint8_t} rbuf
 * @param {uint16_t} rlen
 */
static int iic_hid_transfer(struct i2c_client *client, uint8_t wbuf[], uint16_t wlen, uint8_t rbuf[], uint16_t rlen)
{
	int ret;

	if (!client) {
		TP_LOG_PRINTF("iic transfer enter error\n");
		return -EINVAL;
	}

	ret = iic_hid_write(client, wbuf, wlen, rlen);
	if (ret)
		return ret;

	ret = iic_hid_read(client, rbuf, rlen);
	if (ret)
		return ret;

	return BTL_ERR_OK;
}

/**
 * @description: 
 * @brief: 函数描述
 * @return {int}	0：成功。else：iic通信错误
 * @Date: 2024-04-18 19:15:16
 * @param {i2c_client} *client
 * @param {uint8_t} reg_addr
 * @param {uint8_t*} rbuf
 * @param {uint8_t} len
 */
static int iic_read(struct i2c_client *client, uint8_t reg_addr, uint8_t* rbuf, uint8_t len)
{
	int ret;

	if (!client || !rbuf) {
		TP_LOG_PRINTF("iic read enter error\n");
		return -EINVAL;
	}

	ret = iic_hid_transfer(client, &reg_addr, 1, rbuf, len);
	if (ret)
		TP_LOG_PRINTF("iic_read err, ret:%d\n", ret);
	return ret;
}

/**
 * @description: 
 * @brief: 函数描述
 * @return {int}	0：成功。else：iic通信错误
 * @Date: 2024-04-18 20:00:32
 * @param {i2c_client} *client
 * @param {uint8_t} reg_addr
 * @param {uint8_t} reg_val
 */
static int iic_write(struct i2c_client *client, uint8_t reg_addr, uint8_t reg_val)
{
	uint8_t wbuf[2];
	wbuf[0] = reg_addr;
	wbuf[1] = reg_val;

	if (!client) {
		TP_LOG_PRINTF("iic write enter error\n");
		return -EINVAL;
	}

	int ret = iic_hid_transfer(client, wbuf, 2, NULL, 0);
	if (ret)
		TP_LOG_PRINTF("iic_write err, ret:%d\n", ret);
	return ret;
}

/**
 * @description:
 * @brief	通过transfer调用，进入到某一模式。
 * 			错误时输出log信息。
 * @return {int}	0=BTL_ERR_OK：成功，
 *						14=BTL_ERR_SWITCH_IIC：错误码
 */
static int switch_to_normal_iic(struct i2c_client *client)
{
	int retry;
	uint8_t normal_iic_cmd[] = { 0x55, 0x46, 0x4F };	/* { 'U', 'F', 'O'}; */

	if (!client) {
		TP_LOG_PRINTF("switch normal enter error\n");
		return -EINVAL;
	}

	/* 失败后重试3次 */
	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_hid_transfer(client, normal_iic_cmd, sizeof(normal_iic_cmd), NULL, 0))
			return BTL_ERR_OK;
	}
	TP_LOG_PRINTF("switch_to_normal_iic err\n");
	return BTL_ERR_SWITCH_IIC;
}

/**
 * @description: 
 * @brief	写{退出命令}。3次retry
 * @return {int}	0=BTL_ERR_OK：成功，
 *						16=BTL_ERR_EXIT_BURN_MODE：失败
 * @Date: 2024-04-18 19:39:16
 * @param {i2c_client} *client
 */
static int exit_burn_mode(struct i2c_client *client)
{
	int retry;
	uint8_t exit_burn_mode_cmd[] = { 0x5a, 0xa5, 0x5a, 0xa5, 0x5a, 0xa5 };

	if (!client) {
		TP_LOG_PRINTF("burn mode exit error, invalid value\n");
		return BTL_ERR_EXIT_BURN_MODE;
	}

	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_hid_transfer(client, exit_burn_mode_cmd, sizeof(exit_burn_mode_cmd), NULL, 0))
			return BTL_ERR_OK;

		BTL_DELAY_MS(BTL_DELAY_TIME_30);
	}
	TP_LOG_PRINTF("exit burn mode err\n");
	return BTL_ERR_EXIT_BURN_MODE;
}

/**
 * @description: 
 * @brief		调用transfer接口
 * @return {int}	0：成功。BTL_ERR_SOFT_RESET：失败
 * @Date: 2024-04-29 11:04:07
 * @param {i2c_client} *client
 */
static int soft_reset(struct i2c_client *client)
{
	int i;
	uint8_t uc_rest_cmd[] = { 0x52, 0x52 };
	uint8_t uc_read_byte = 0;

	if (!client) {
		TP_LOG_PRINTF("soft reset enter error\n");
		return -EINVAL;
	}

	for (i = 0; i < BTL_RETRY_TIME_3; i++) {
		if (iic_write(client, 0xa5, 0)) { /* write, reg: 0xa5, val: 0 */
			TP_LOG_PRINTF("soft_reset iic_write err1\n");
			BTL_DELAY_MS(BTL_DELAY_TIME_20);
			continue;
		}
		if (iic_hid_transfer(client, uc_rest_cmd, sizeof(uc_rest_cmd), &uc_read_byte, 1)) {
			TP_LOG_PRINTF("soft_reset iic_hid_transfer err\n");
			BTL_DELAY_MS(BTL_DELAY_TIME_20);
			continue;
		}

		if (0x52 == uc_read_byte)	/* read 0x52 success */
			return BTL_ERR_OK;

		BTL_DELAY_MS(BTL_DELAY_TIME_20);
	}
	return BTL_ERR_SOFT_RESET;
}

/**
 * @description: 
 * @brief	不切模式，快速获取版本号信息，用于更新校验
 * @return {int}	0=BTL_ERR_OK：成功，
 * 						else：错误码
 * @param {i2c_client}	*client
 * @param {uint8_t} ic_ver	存储version信息的空间
 */
static int btl_get_firmware_version_quickly(struct i2c_client *client, uint8_t ic_ver[], int len)
{
	uint8_t hid_desc_cmd[2] = { 0x01, 0x00 }; /* 获取描述符命令，从描述符中取版本号 */
    uint8_t hid_desc[30] = { 0 };
	int ver_offset = 24; /* 版本号在 hid description 中的偏移量 */
    int ret;
    int retry;

	if (!client || !ic_ver || len == 0) {
		TP_LOG_PRINTF("get version quick enter error, invalid value\n");
		return -EINVAL;
	}

	if (!ic_ver || len != BTL_TP_IC_VERSION_LEN)
		return BTL_ERR_VER_READ_FAIL;

	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		ret = iic_hid_transfer(client, hid_desc_cmd, sizeof(hid_desc_cmd), hid_desc, sizeof(hid_desc));
		if (!ret) {
			*ic_ver = hid_desc[ver_offset];
			return BTL_ERR_OK;
		}
	}
	TP_LOG_PRINTF("btl_get_firmware_version err\n");
	return BTL_ERR_FW_VER;
}

/**
 * @description: 
 * @brief	获取tp ic系统版本信息，切模式
 * @return {int}	0=BTL_ERR_OK：成功，
 * 						else：错误码
 * @param {i2c_client}	*client
 * @param {uint8_t} ic_ver	存储version信息的空间
 * @note	成功后进入normal模式，触控板失效，需要切回原模式
 */
static int btl_get_firmware_version(struct i2c_client *client, uint8_t ic_ver[], int len)
{
	int retry;
	uint8_t chip_ver_cmd = 0xb6;	/* chip ver cmd */

	if (!client || !ic_ver || len == 0) {
		TP_LOG_PRINTF("get version enter error\n");
		return -EINVAL;
	}

	if (!ic_ver || len != BTL_TP_IC_VERSION_LEN)
		return BTL_ERR_VER_READ_FAIL;

	if (BTL_ERR_SWITCH_IIC == switch_to_normal_iic(client))
		return BTL_ERR_SWITCH_IIC;

	BTL_DELAY_MS(BTL_DELAY_TIME_1);

	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_read(client, chip_ver_cmd, ic_ver, len))
			return BTL_ERR_OK;
	}
	TP_LOG_PRINTF("btl_get_firmware_version err\n");
	return BTL_ERR_FW_VER;
}

/**
 * @description: 
 * @brief		进入刻录模式。写105 pair of (0x5a, 0xa5)
 * @return {int}	0：成功，
 *					else：i2c_transfer_data返回值代表的错误信息
 * @param {i2c_client} *client
 */
static int enter_burn_mode(struct i2c_client *client)
{
	uint8_t enter_burn_mode_cmd[210] = { 0x00 };  /* 105 pair of (0x5a, 0xa5) */
	int32_t i;
	int ret;

	if (!client) {
		TP_LOG_PRINTF("enter burn enter error\n");
		return -EINVAL;
	}

	for (i = 0; i < sizeof(enter_burn_mode_cmd); i += 2) {
		enter_burn_mode_cmd[i] = 0x5A;
		enter_burn_mode_cmd[i + 1] = 0xA5;
	}

	ret = iic_hid_transfer(client, enter_burn_mode_cmd, sizeof(enter_burn_mode_cmd), NULL, 0);
	if (ret)
		TP_LOG_PRINTF("enter_burn_mode err, ret:%d\n", ret);

	return ret;
}


/**
 * @description: 
 * @brief		将数据{ 0x0A, 0xF5, 0xE7 }写，并读出1byte 到 param2
 * @return {*}	transfer的返回值
 * @param {i2c_client} *client
 * @param {uint8_t*} p_chip_type
 */
static int read_chiptype_internal(struct i2c_client *client, uint8_t* p_chip_type)
{
	uint8_t chip_type_cmd[] = { 0x0A, 0xF5, 0xE7 };

	if (!client || !p_chip_type) {
		TP_LOG_PRINTF("client or p_chip_type is NULL\n");
		return -EINVAL;
	}

	return iic_hid_transfer(client, chip_type_cmd, sizeof(chip_type_cmd), p_chip_type, 1);
}

/**
 * @description:
 * @brief		将数据{ 0x06, 0xF9, 0x08, 0x7f }write
 * @return {int}	0=BTL_ERR_OK：成功，
 *						12=BTL_ERR_EREASE_FLASH：失败。
 * @param {i2c_client} *client
 */
static int erase_flash(struct i2c_client *client)
{
	int retry;
	uint8_t erase_flash_cmd[] = { 0x06, 0xF9, 0x08, 0x7f };	/* erase code */

	if (!client) {
		TP_LOG_PRINTF("erase flash enter error\n");
		return -EINVAL;
	}

	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_hid_transfer(client, erase_flash_cmd, sizeof(erase_flash_cmd), NULL, 0)) {
			return BTL_ERR_OK;
		}
	}
	TP_LOG_PRINTF("erase_flash err\n");
	return BTL_ERR_EREASE_FLASH;
}

/**
 * @description: 
 * @brief		erase flash
 * @return {int}	0=BTL_ERR_OK：成功
 *						13=BTL_ERR_EREASE_ENTIRE_FLASH：失败
 * @param {i2c_client} *client
 */
static int erase_entire_flash(struct i2c_client *client)
{
	int retry;
	uint8_t erase_flash_cmd[] = { 0x09, 0xF6 };	/* erase code */

	if (!client) {
		TP_LOG_PRINTF("erase entire enter error\n");
		return -EINVAL;
	}

	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_hid_transfer(client, erase_flash_cmd, sizeof(erase_flash_cmd), NULL, 0))
			return BTL_ERR_OK;
	}
	TP_LOG_PRINTF("erase_flash err\n");
	return BTL_ERR_EREASE_ENTIRE_FLASH;
}

static int exit_write_flash_mode(struct i2c_client *client)
{
	uint8_t sz_chipid_cmd[BTL_FALSH_PAGE];
	int ret;

	if (!client) {
		TP_LOG_PRINTF("write mode exit error\n");
		return -EINVAL;
	}

	ret = memset_s(sz_chipid_cmd, BTL_FALSH_PAGE, 0xff, BTL_FALSH_PAGE);
	if (ret) {
		TP_LOG_PRINTF("set cmd buff err, memset ret: %d\n", ret);
		return ret;
	}

	ret = iic_hid_transfer(client, sz_chipid_cmd, BTL_FALSH_PAGE, NULL, 0);
	if (ret) {	/* retry two times */
		BTL_DELAY_MS(BTL_DELAY_TIME_50);
		ret = iic_hid_transfer(client, sz_chipid_cmd, BTL_FALSH_PAGE, NULL, 0);
		if (ret) {
			TP_LOG_PRINTF("exit_write_flash_mode err,ret:%d\r\n", ret);
			return BTL_ERR_EXIT_WFLASH;
		}
	}
	return BTL_ERR_OK;
}

static int check_hid_desc(struct i2c_client *client, uint8_t* chip_type, uint8_t* fw_version_ptr)
{
	uint8_t hid_desc_cmd[] = { 0x01, 0x00 };
	uint8_t hid_desc[BTL_HID_DESC_SIZE];
	int ret = BTL_ERR_OK;
	int retry;

	if (!client || !chip_type || !fw_version_ptr) {
		TP_LOG_PRINTF("check desc enter error\n");
		return -EINVAL;
	}

	*chip_type = 0; /* 初始化为0，表示未成功 */
	for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {
		if (!iic_hid_transfer(client, hid_desc_cmd, sizeof(hid_desc_cmd), hid_desc, BTL_HID_DESC_SIZE)) {
			if (hid_desc[20] == 0x7d && hid_desc[21] == 0x34 && hid_desc[23] == 0x78) { /* 检查描述符内容保证更新前状态正常 */
				*chip_type = 1; /* 成功后置1 */
				*fw_version_ptr = hid_desc[24]; /* 版本信息在描述符中的偏移量 */
				TP_LOG_PRINTF("vid:%02x%02x,pid:%02x%02x,icFwVer:%02x\r\n", hid_desc[21], hid_desc[20], hid_desc[23], hid_desc[22], hid_desc[24]);
				return BTL_ERR_OK;
			} else
				ret = BTL_ERR_CHIPID_UNMATCHED;

		} else if (retry == BTL_RETRY_TIME_2) {
			TP_LOG_PRINTF("check_hid_des err\r\n");
			ret = BTL_ERR_IIC_COM_FAIL;
			break;
		}
		BTL_DELAY_MS(BTL_DELAY_TIME_20);
	}
	return ret;
}

/**
 * @description: 
 * @brief	升级执行前调用此接口，确保ic处于正常状态。
 * @return {int}
 * @Date: 2024-05-10 11:34:10
 * @param {uint8_t*} chip_type_ptr
 * @param {uint8_t*} fw_ver_ptr
 */
static int btl_check_tpchip(struct i2c_client *client, uint8_t* chip_type_ptr, uint8_t* fw_ver_ptr)
{
	uint8_t sz_chipid_cmd[] = { 0x0A, 0xF5, 0xE7 };
	uint8_t chip_type;
	int retry;
	int ret;

	if (!client || !chip_type_ptr || !fw_ver_ptr) {
		TP_LOG_PRINTF("check tpchip enter error\n");
		return -EINVAL;
	}

	chip_type = 0; /* 初始化为0 */
	*chip_type_ptr = 0;
	*fw_ver_ptr = 0xff; /* 版本号信息初始化为255 */

	/* make sure exit write flash mode */
	ret = exit_write_flash_mode(client);
	if(ret)
		return ret;

	BTL_DELAY_MS(BTL_DELAY_TIME_1);

	if (iic_hid_transfer(client, sz_chipid_cmd, sizeof(sz_chipid_cmd), &chip_type, 1)) /* chip_type为1字节 */
		return BTL_ERR_IIC_COM_FAIL;

	if (BTL_CHIP_TYPE != chip_type) {
		if (BTL_ERR_OK == check_hid_desc(client, &chip_type, fw_ver_ptr) && chip_type) {
			*chip_type_ptr = 1; /* 置1 */
			TP_LOG_PRINTF("check tpchip, hid ver:%02x\r\n", *fw_ver_ptr);
			return BTL_ERR_OK;
		}

		ret = enter_burn_mode(client);
		if (ret)
			return ret;

		BTL_DELAY_MS(BTL_DELAY_TIME_1);
		for (retry = 0; retry < BTL_RETRY_TIME_3; retry++) {	/* retry 3 times*/
			if (!iic_hid_transfer(client, sz_chipid_cmd, sizeof(sz_chipid_cmd), &chip_type, 1)) /* chip_type为1字节 */
				break;
		}
	}
	if (BTL_CHIP_TYPE == chip_type) {
		/* btl tp deteced */
		TP_LOG_PRINTF("chiptype:%02x\r\n", chip_type);
		*chip_type_ptr = 1; /* 置1 */
	} else
		ret = BTL_ERR_CHIPID_UNMATCHED;

	BTL_DELAY_MS(BTL_DELAY_TIME_20);

	ret = exit_burn_mode(client);
	if (ret)
		return ret;

	BTL_DELAY_MS(BTL_DELAY_TIME_60); /* wait to reboot */
	return ret;
}

static int btl_write_one_page(struct i2c_client *client, const uint8_t *ptr_firmware_bin, uint32_t page_offset)
{
	int ret;
	uint8_t burn_buf[BTL_FALSH_PAGE + BTL_WIN_SYS_RX_HEAD_SIZE];

	if (!client || !ptr_firmware_bin) {
		TP_LOG_PRINTF("write page enter error\n");
		return -EINVAL;
	}

	ret = memcpy_s(burn_buf + BTL_WIN_SYS_RX_HEAD_SIZE, BTL_FALSH_PAGE, ptr_firmware_bin + page_offset, BTL_FALSH_PAGE);
	if (ret) {
		TP_LOG_PRINTF("set cmd buff err, memcpy ret: %d\n", ret);
		return ret;
	}

	/* 设置系统RX包头内容 */
	burn_buf[0] = 0x0f;
	burn_buf[1] = 0xf0;
	burn_buf[2] = (uint8_t)(page_offset >> 8);
	burn_buf[3] = (uint8_t)(page_offset & 0xff);
	page_offset += BTL_FALSH_PAGE - 1;
	burn_buf[4] = (uint8_t)(page_offset >> 8);
	burn_buf[5] = (uint8_t)(page_offset & 0xff);

	if (iic_hid_transfer(client, burn_buf, sizeof(burn_buf), NULL, 0))
		return BLT_ERR_WRITE_PAGE;

	return BTL_ERR_OK;
}

/**
 * @description: 
 * @brief	擦除
 * @return {int}	BTL_ERR_ERASE_SECTOR、BTL_ERR_OK
 * @Date: 2024-05-14 12:04:14
 * @param {i2c_client} *client
 * @param {uint8_t} sector_offset
 */
static int erase_sector(struct i2c_client *client, uint8_t sector_offset)
{
	uint8_t sz_chipid_cmd[] = { 0x06, 0xF9, 0x08, 0x7f }; /* erase命令 */
	/* 设置擦除偏移量 */
	sz_chipid_cmd[2] = sector_offset;
	sz_chipid_cmd[3] = sector_offset + 1;

	if (!client) {
		TP_LOG_PRINTF("erase sector enter error\n");
		return -EINVAL;
	}

	if (iic_hid_transfer(client, sz_chipid_cmd, sizeof(sz_chipid_cmd), NULL, 0))
		return BTL_ERR_ERASE_SECTOR;

	TP_LOG_PRINTF("EraseFlash One Sector\r\n");
	return BTL_ERR_OK;
}

/**
 * @description: 
 * @brief	双页写
 * @return {int}	0：成功。else：BTL_ERR_WRITE_PAGE_TWICE、BTL_ERR_WRITE_SECTOR、BTL_ERR_ERASE_SECTOR
 * @Date: 2024-05-14 12:04:48
 * @param {i2c_client} *client
 * @param {uint8_t} *ptr_firmware_bin
 * @param {uint8_t} sector_offset
 */
static int btl_write_sector(struct i2c_client *client, const uint8_t *ptr_firmware_bin, uint8_t sector_offset)
{
	int page_offset;
	int flash_page;		/* one sector contains 2 flash */
	int rewrite = 0;	/* if write page fail, rewrite */
	int ret;

	if (!client || !ptr_firmware_bin) {
		TP_LOG_PRINTF("write sector enter error\n");
		return -EINVAL;
	}
	
	for (flash_page = 0; flash_page < BTL_FALSH_PAGE_PER_SECTOR; flash_page++) {
		page_offset = sector_offset * BTL_FALSH_SECTOR + flash_page * BTL_FALSH_PAGE;

		/* write one page */
		ret = btl_write_one_page(client, ptr_firmware_bin, page_offset);
		if(BTL_ERR_OK == ret)	/* success */
			continue;

		TP_LOG_PRINTF("write page error, try to rewrite\n");
		if (BTL_ERR_OK == erase_sector(client, sector_offset)) {	/* write page fail, erase and retry */
			ret = BTL_ERR_WRITE_SECTOR;
			if(rewrite == 2)	/* can not rewrite twice */
				return BTL_ERR_WRITE_PAGE_TWICE;
			else
				rewrite = 1;	/* re-write whole sector, only support rewrite once */
		} else
			return BTL_ERR_ERASE_SECTOR;

		BTL_DELAY_MS(BTL_DELAY_TIME_1);

		if (rewrite == 1) {		/* 此次需要重写 */
			flash_page = -1;	/* rewrite whole sector */
			rewrite = 2;		/* can not rewrite twice */
		}
	}
	return ret;
}

/**
 * @description: 
 * @brief		与iic通信
 * @return {int}		BTL_ERR_TPMODE_SWITCH：错误，
 * 							BTL_ERR_OK=0：成功
 * @param {i2c_client} *client
 * @param {uint8_t} mode	0：mode_p2p_to_mouse，
 * 							1：mode_mouse_to_p2p
 */
static int btl_tpmode_switch(struct i2c_client *client, uint8_t mode)
{
	int i;
	int err_code;
	uint8_t mode_p2p_to_mouse[] = { 0x05, 0x00, 0x33, 0x03, 0x06, 0x00, 0x04, 0x00, 0x03, 0x00 };
	uint8_t mode_mouse_to_p2p[] = { 0x05, 0x00, 0x33, 0x03, 0x06, 0x00, 0x04, 0x00, 0x03, 0x03 };
	uint8_t hid_desc[] = { 0x01, 0x00 };
	uint8_t uc_read_byte = 0;

	if (!client) {
		TP_LOG_PRINTF("mode switch enter error\n");
		return -EINVAL;
	}

	for (i = 0; i < BTL_RETRY_TIME_3; i++) { /* retry 3 times */
		if (iic_hid_transfer(client, hid_desc, sizeof(hid_desc), &uc_read_byte, 1)) {
			BTL_DELAY_MS(BTL_DELAY_TIME_10);
			continue;
		}

		if (uc_read_byte == 0x1e) {
			if (0 == mode)	/* p2p mode -> mouse mode */
				err_code = iic_hid_transfer(client, mode_p2p_to_mouse, sizeof(mode_p2p_to_mouse), NULL, 0);
			else
				err_code = iic_hid_transfer(client, mode_mouse_to_p2p, sizeof(mode_mouse_to_p2p), NULL, 0);
			if (!err_code)
				return BTL_ERR_OK;
		}
	}
	return BTL_ERR_TPMODE_SWITCH;
}

/**
 * @description: 
 * @brief		更新操作1
 * @return {int}	0=BTL_ERR_OK：成功，
 * 					else：错误码。
 * @param {i2c_client} *client
 * @param {uint8_t} *ptr_firmware_bin		固定值
 * @note	升级成功后默认mouse模式
 */
static int update_bin_to_flash(struct i2c_client *client, const uint8_t *ptr_firmware_bin, int fw_len)
{
	int i;
	uint32_t sector_count;
	uint32_t sector_start;
	uint8_t burn_buf[BTL_FALSH_PAGE + 6];	/* header size: 6 */
	uint8_t chip_type_val = 0;
	int err_code;

	if (!client || fw_len == 0 || !ptr_firmware_bin) {
		TP_LOG_PRINTF("update bin enter error\n");
		return -EINVAL;
	}

	/* 进入烧录模式失败，需要退出烧录模式 */
	if(enter_burn_mode(client)) {
		(void)exit_burn_mode(client);
		TP_LOG_PRINTF("enter burn mode error\n");
		return BTL_ERR_ENTER_BURN_MODE;
	}
	BTL_DELAY_MS(BTL_DELAY_TIME_5);

	if (read_chiptype_internal(client, &chip_type_val)) {
		TP_LOG_PRINTF("read chiptype error\n");
		return BTL_ERR_READ_CHIPTYPE;
	}

	if (erase_flash(client)) {
		TP_LOG_PRINTF("erase flash error\n");
		return BTL_ERR_EREASE_FLASH;
	}

	BTL_DELAY_MS(BTL_DELAY_TIME_1100);

	sector_start = BTL_BOOT_SECTOR_NUM;
	sector_count = fw_len / BTL_FALSH_SECTOR;
	TP_LOG_PRINTF("fwupdate begin, chiptype:0x%x\n", chip_type_val);
	/* start update */
	for (i = sector_start; i < sector_count; i++) {
		err_code = btl_write_sector(client, ptr_firmware_bin, i);	/* 内部有失败后retry机制 */
		if (err_code) {
			TP_LOG_PRINTF("write flash error:%3d\n", err_code);
			break;
		}
		BTL_DELAY_MS(BTL_DELAY_TIME_1);
	}
	TP_LOG_PRINTF("fwupdate end:%d\n", err_code);

	BTL_DELAY_MS(BTL_DELAY_TIME_20);

	if (exit_burn_mode(client)) {
		TP_LOG_PRINTF("exit burn error\n");
		return BTL_ERR_EXIT_BURN_MODE;
	}
	return err_code;
}

/**
 * @description: 
 * @brief		更新操作2
 * @return {int}	0=BTL_ERR_OK：成功，
 * 						else：错误码。
 * @param {i2c_client} *client
 * @param {uint8_t} *ptr_firmware_bin
 */
static int check_bin_check_sum(struct i2c_client *client, const uint8_t *ptr_firmware_bin, int fw_len)
{
	int i;
	int retry;
	uint8_t fw_ver[BTL_TP_IC_VERSION_LEN];
	uint8_t check_sum_arr[3];	/* 0: checksum status flag, 1: checksum high byte, 2: checksum low byte */
	uint16_t wlc_check_sum;
	uint16_t w_check_sum;

	if (!client || fw_len == 0 || !ptr_firmware_bin) {
		TP_LOG_PRINTF("check bin enter error\n");
		return -EINVAL;
	}

	if (btl_get_firmware_version(client, fw_ver, BTL_TP_IC_VERSION_LEN))
		return BTL_ERR_VER_READ_FAIL;
	TP_LOG_PRINTF("fw ver: %d, %d\n", fw_ver[0], fw_ver[1]);

	if (iic_write(client, 0x8a, 0xaa))	/* write reg: 0x8a, val: 0xaa; start calc check sum */
		return BTL_ERR_IIC_COM_FAIL;

	w_check_sum = 0;
	for (i = 0; i < fw_len; i++)
		w_check_sum += ptr_firmware_bin[i];

	BTL_DELAY_MS(BTL_DELAY_TIME_50);

	/* retry 40 times */
	for (retry = 0; retry < BTL_RETRY_TIME_40; retry++) {
		/* read reg 0x3f, read 3 bytes */
		if (!iic_read(client, 0x3f, check_sum_arr, sizeof(check_sum_arr)) && BTL_CHECKSUM_COMPLETE == check_sum_arr[0])
			break;

		BTL_DELAY_MS(BTL_DELAY_TIME_1);
	}

	if (soft_reset(client))
		return BTL_ERR_SOFT_RESET;

	BTL_DELAY_MS(BTL_DELAY_TIME_30); /* more than 15 */

	if (btl_tpmode_switch(client, 1)) /* switch to p2p mode */
		return BTL_ERR_IIC_COM_FAIL;

	wlc_check_sum = (((uint16_t)check_sum_arr[1]) << 8) + check_sum_arr[2]; /* 计算校验 */
	TP_LOG_PRINTF("checksum,read:0x%04X,bin:0x%04X\n", wlc_check_sum, w_check_sum);

	if (BTL_CHECKSUM_COMPLETE == check_sum_arr[0] && wlc_check_sum == w_check_sum)
		return BTL_ERR_OK;

	TP_LOG_PRINTF("Fw Update Fail!\n");
	return BTL_ERR_CHECKSUM_FAIL;
}


/**
 * @description: 
 * @brief	版本号验证，检查是否升级
 * @return {int} err_code	BTL_ERR_OK=0：继续往下走---升级，
 * 							else: 表示不升级,错误代码号
 * @param {i2c_client} *client
 * @param {uint8_t} *fw_data
 * @param {int} fw_len
 */
int btl_check_version(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len)
{
	int i;
	uint8_t ic_ver[BTL_TP_IC_VERSION_LEN];	/* 通过系统接口查找到的硬件版本号 */
	uint8_t pkg_ver[BTL_TP_IC_VERSION_LEN];	/* fw_data中的版本号，固定值 */

	if (!client || !fw_data || fw_len < BTL_BIN_VER_OFFSET + BTL_TP_IC_VERSION_LEN - 1)
		return -EINVAL;

	/* step2，取原始数据中的版本信息 */
	for (i = 0; i < BTL_TP_IC_VERSION_LEN; i++)
		pkg_ver[i] = fw_data[BTL_BIN_VER_OFFSET + i];

	/* major version range (0, 0x80) or 0xff */
	if ((pkg_ver[0] == 0x00 || pkg_ver[0] >= 0x80) && pkg_ver[0] != 0xff)
		return BTL_ERR_BIN_FMT_INVALID;

	/* step3，pkg版本校验成功后，进行ic-internal firmware ver校验 */
	if (btl_get_firmware_version_quickly(client, ic_ver, sizeof(ic_ver)))
		return BTL_ERR_VER_READ_FAIL;

	TP_LOG_PRINTF("version data getted: pkg_ver->%d----------ic_ver->%d\n", pkg_ver[0], ic_ver[0]);

	if (ic_ver[0] == 0x00 || ic_ver[0] >= 0x80)	/* major version range (0, 0x80) or 0xff，版本号invalid->更新 */
		return BTL_ERR_OK;
	else if (ic_ver[0] < pkg_ver[0])			/* 老版本->更新 */
		return BTL_ERR_OK;
	else if(ic_ver[0] == pkg_ver[0]) {			/* 不需要更新 */
		TP_LOG_PRINTF("Need not Update Fw\n");
		return BTL_ERR_NEED_NOT_UPDATE;
	}
	return BTL_ERR_ESD_FAIL;
}

/**
 * @description: 
 * @brief	更新固件
 * @return {int}	BTL_ERR_OK=0：完成更新,
 *					else：错误代码
 * @param {i2c_client} *client
 * @param {uint8_t} *fw_data
 * @param {int} fw_len
 */
int btl_update_fw(struct i2c_client *client, const u8 *fw_data, int fw_len, const u8 *cfg_data, int cfg_len)
{
	uint8_t is_btl_tp = 0;
	uint8_t fw_ver[BTL_TP_IC_VERSION_LEN];
	int ret;

	if (!client || !fw_data || fw_len < BTL_BIN_VER_OFFSET + BTL_TP_IC_VERSION_LEN - 1) {
		TP_LOG_PRINTF("update enter error\n");
		return -EINVAL;
	}

	if (btl_check_tpchip(client, &is_btl_tp, fw_ver)) /* 状态检查，确保状态正常 */ {
		TP_LOG_PRINTF("update check status error\n");
		return BTL_ERR_UPDATE_RESET;
	}

	ret = update_bin_to_flash(client, fw_data, fw_len);
	if (ret) {
		TP_LOG_PRINTF("update bin error\n");
		ret = BTL_ERR_UPDATE_FAIL;
	}

	BTL_DELAY_MS(BTL_DELAY_TIME_50);

	if (check_bin_check_sum(client, fw_data, fw_len)) { /* 失败后复位，保证功能正常 */
		TP_LOG_PRINTF("check sum error\n");
		if (soft_reset(client))
			return BTL_ERR_SOFT_RESET;

		BTL_DELAY_MS(BTL_DELAY_TIME_30); /* more than 15 */
		if (btl_tpmode_switch(client, 1)) /* switch to p2p mode */
			return BTL_ERR_IIC_COM_FAIL;
		
		return BTL_ERR_CHECKSUM_FAIL;
	}

	if (BTL_ERR_OK == ret) { /* update ok */
		TP_LOG_PRINTF("Update Fw Sucess!\n");
	}
	return ret;
}