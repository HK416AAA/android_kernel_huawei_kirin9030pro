/*
 * Thp driver code for yuwei
 *
 * Copyright (c) 2012-2024 Huawei Technologies Co., Ltd.
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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/spi/spi.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/string.h>
#include <linux/time.h>
#include <linux/syscalls.h>
#include <securec.h>
#include "huawei_thp.h"
#include "huawei_pen_clk.h"
#include "power_adapter/huawei_power_adapter.h"
#include "power_adapter/huawei_tdev_power_func.h"
#include "bus_adapter/huawei_bus_adapter.h"
#include "bus_adapter/huawei_spi_bus_platform.h"
#include "bus_adapter/huawei_spi_bus_config_parse.h"

#define NO_ERR 0
#define ENABLE 1
#define YUWEI_IC_NAME "yuwei"
#define THP_YUWEI_DEV_NODE_NAME "yuwei_thp"
#define MODULE_INFO_READ_RETRY_TIMES 5
#define FW_INFO_READ_RETRY_TIMES 3
#define SEND_COMMAND_RETRY_TIMES 3
#define CHECK_COMMAND_RETRY_TIMES 3
#define GESTURE_EVENT_RETRY_TIMES 10
#define MODULE_INFO_READ_RETRY_DELAY_MIN 10000
#define MODULE_INFO_READ_RETRY_DELAY_MAX 11000
#define FRAME_HEAD_LEN 16
#define DEFAULT_FRAME_LEN 2500
#define YUWEI_FRAME_ADDR_DEFAULT 0x8C05
#define YUWEI_CMD_ADDR_DEFAULT 0x58BF
#define YUWEI_FW_STATE_ADDR_DEFAULT 0xBFDE
#define YUWEI_FW_STATE_LEN_DEFAULT 10
#define YUWEI_MODULE_INFO_ADDR_DEFAULT 0x452C
#define YUWEI_PROJECT_ID_ADDR_DEFAULT 0xBDB4
#define YUWEI_AFE_INFO_ADDR_DEFAULT 0x6D20
#define YUWEI_MAX_AFE_LEN_DEFAULT 300
#define YUWEI_FRAME_LEN_OFFSET_DEFAULT 20
#define YUWEI_FRAME_ADDR_OFFSET_DEFAULT 22
#define YUWEI_FW_STATUS_LEN_OFFSET_DEFAULT 91
#define YUWEI_FW_STATUS_ADDR_OFFSET_DEFAULT 93
#define YUWEI_CMD_ADDR_OFFSET_DEFAULT 102
#define YUWEI_MODULE_INFO_ROW_SIZE 32
#define YUWEI_MODULE_INFO_GROUP_NUM 3
#define CMD_ACK_OFFSET 4
#define YUWEI_SPI_READ_XFER_LEN 2
#define FW_STAUTE_DATA_MASK  0x04
#define FW_STAUTE_DATA_FLAG  0xAA
#define FW_STAUTE_DATA_FLAG_OFFSET 3
#define YUWEI_SPI_ACTIVE_DELAY 1000
#define YUWEI_AFTER_IOVDD_DELAY_YWT 7
#define YUWEI_AFTER_DVDD_RST_DELAY_YWT 12
#define YUWEI_TOUCH_ADDR_FOR_YWT_DUAL 0x101A0
#define YUWEI_CMD_ACK_OFFSET_YWT 1
#define CMD_PT_MODE_YWT 0x84
#define CMD_GESTURE_MODE_YWT 0xA6
#define YUWET_MASK_ID_FOR_YWT_NOCODE "NOCODE"
#define YUWEI_SEND_CMD_WAIT_DELAY_YWT 10
#define GESTURE_CMD_SWITCH_YWT 0x02
#define CMD_SWITCH_INT_PIN 0xA9
#define CMD_SWITCH_INT_PIN_YWT 0xA5
#define CMD_SWITCH_INT_AP 0x0
#define CMD_SWITCH_INT_SH 0x1
#define CMD_GESTURE_DOUBLE 0x02
#define SENSORHUB_SUPPORT_GESTURE 2
/* 9X stylus3 bt connect status config info */
#define BT_CONNECT_STATUS_ADDR 0x10180
#define BT_CONNECT_STATUS_BUF_LEN 7
#define BT_CONNECT_BUF2 0x05
#define BT_CONNECT_BUF3 0xA4
#define BT_CONNECT_BUF4 0x02
#define BT_CONNECT_BUF5 0xAB
#define BT_DISCONNECT_BUF2 0x05
#define BT_DISCONNECT_BUF3 0xA4
#define BT_DISCONNECT_BUF5 0xA9
#define BT_ADSORPTION_BUF2 0x05
#define BT_ADSORPTION_BUF3 0xBB
#define BT_ADSORPTION_BUF4 0x01
#define BT_ADSORPTION_BUF5 0xC1
#define SEND_BT_CONNECT_STATUS_AFTER_RESET_DELAY 200
#define BT_CONNECT_STATUS_CHECK_ADDR 0x10169
#define BT_CONNECT_STATUS_CHECK_ADDR_YWT672T 0x10219
#define BT_CONNECT_CMD_RETRY 3
#define BT_CHECK_DATA_LEN 1
#define BT_CONNECT_VALUE 1
#define BT_DISCONNECT_VALUE 0
#define BT_ADSORPTION_VALUE 2
#define BT_AFTER_WRITE_CMD_DELAY 20
#define BT_STYLUS3_CONNECTED_MASK (1 << 1)
#define STYLUS3_ADSORPTION_MASK (1 << 5)
#define CMD_ACK_BUSY_YWT 0x02
#define CMD_ACK_BUFFER_OVERFLOW_YWT 0x03
#define CMD_ACK_OK_YWT 0x80
/* YWT672T default addr */
#define YUWEI_FRAME_ADDR_DEFAULT_YWT672T 0x1058C
#define YUWEI_CMD_ADDR_DEFAULT_YWT672T 0x10174
#define YUWEI_MODULE_INFO_ADDR_YWT672T 0x10014
#define YUWEI_PROJECT_ID_ADDR_YWT672T 0x10030
#define YUWEI_FRAME_LEN_MAX_YWT672T 5120
#define YUWEI_READ_BYTE_OFFSET_YWT672T 8
#define YUWEI_WRITE_BYTE_OFFSET_YWT672T 5
#define YUWEI_GESTURE_ADDR_DEFAULT_YWT672T 0x10274
#define YUWEI_MASK_ID_FOR_YWT "BERLIN"
/* YWT680T default addr */
#define YUWEI_FRAME_ADDR_DEFAULT_YUT680T 0x10400
#define YUWEI_FRAME_LEN_MAX_YWT680T 2500
/* YWT650C default addr */
#define YUWEI_FRAME_ADDR_DEFAULT_YWT650C 0x10474
#define YUWEI_CMD_ADDR_DEFAULT_YWT650C 0x10274
#define YUWEI_FRAME_LEN_MAX_YWT650C (1024 * 20)
#define CMD_ACK_BUF_OVERFLOW 0x01
#define CMD_ACK_CHECKSUM_ERROR 0x02
#define CMD_ACK_BUSY 0x04
#define CMD_ACK_OK 0x80
#define CMD_ACK_IDLE 0xFF
#define CMD_ACK_UNKNOWN 0x00
#define CMD_ACK_ERROR (-1)
#define CMD_FRAME_DATA 0x90
#define CMD_HOVER 0x91
#define CMD_FORCE 0x92
#define CMD_SLEEP 0x96
#define CMD_SCREEN_ON_OFF 0x96
#define CMD_SCREEN_ON_OFF_YWT 0xa5
#define CMD_PT_MODE 0x05
#define CMD_GESTURE_MODE 0xB5
#define IC_STATUS_GESTURE 0x01
#define IC_STATUS_POWEROF 0x02
#define IC_STATUS_UDFP 0x04
#define IC_STATUS_PT_TEST 0x08
#define PT_MODE 0
#define FEATURE_ENABLE 1
#define FEATURE_DISABLE 0
#define SPI_FLAG_WR 0xF0
#define SPI_FLAG_RD 0xF1
#define MASK_8BIT 0xFF
#define MASK_1BIT 0x01
#define MASK_32BIT 0xFFFF
#define YUWEI_MASK_ID_DEFAULT "NOR_G1"
#define YUWEI_MASK_ID_LEN_DEFAULT 6
#define MOVE_8BIT 8
#define MOVE_16BIT 16
#define MOVE_24BIT 24
#define MAX_FW_STATUS_DATA_LEN 64
#define SEND_COMMAND_WAIT_DELAY 10
#define SEND_COMMAND_END_DELAY 2
#define SEND_COMMAND_SPI_READ_LEN 1
#define COMMAND_BUF_LEN 5
#define COMMUNI_CHECK_RETRY_DELAY 10
#define DELAY_1MS 1
#define NO_DELAY 0
#define GET_AFE_INFO_RETRY_DELAY 10
#define DEBUG_AFE_DATA_BUF_LEN 20
#define DISABLE_FRAME_WAIT_DELAY 16
#define DEBUG_AFE_DATA_BUF_OFFSET 20
#define INFO_ADDR_BUF_LEN 2
#define IRQ_EVENT_TYPE_FRAME 0x80
#define IRQ_EVENT_TYPE_GESTURE 0x81
#define IRQ_EVENT_TYPE_GESTURE_YWT_DUAL 0x20
#define GESTURE_EVENT_HEAD_LEN 6
#define GESTURE_TYPE_DOUBLE_TAP 0x01
#define GESTURE_EVENT_HEAD_LEN_YWT_DUAL 8
#define GESTURE_TYPE_VALUE_YWT_DUAL 4
#define GESTURE_TYPE_DOUBLE_TAP_YWT_DUAL 0xCC
#define GESTURE_TYPE_PEN_SINGLE_TAP_YWT_DUAL 0xD0
#define GESTURE_DATA_MINI_SIZE_YWT_DUAL 2
#define YUWEI_CUSTOME_INFO_LEN 30
#define YUWEI_GET_PROJECT_ID_RETRY_TIMES 3
#define YUWEI_GET_PROJECT_RETRY_DELAY_10MS 10
#define IDLE_WAKE_FLAG 0xF0
#define IDLE_SPI_SPEED 3500
#define ACTIVE_SPI_SPEED 7500000
#define READ_WRITE_BYTE_OFFSET 1
#define READ_CMD_BUF_LEN 3
#define CMD_TOUCH_REPORT 0xAC
#define WAIT_FOR_SPI_BUS_RESUMED_DELAY 20
#define WAIT_FOR_SPI_BUS_READ_DELAY 5
#define SPI_WAKEUP_RETRY 8
#define YUWEI_LCD_EFFECT_FLAG_POSITION 12
#define GET_AFE_BUF_LEN 2
#define WAIT_FOR_COMMUNICATION_CHECK_DELAY 10
#define YUWEI_BE_MODE 0
#define YUWEI_LE_MODE 1
#define SPI_READ_RETRY_TIME 20
#define SPI_DELAY_MS 5
#define YUWEI_SWITCH_CMD_LEN_YWT 6
#define YUWEI_SWITCH_DATA_LEN_YWT 2
#define YUWEI_SWITCH_BUFF_LEN_YWT 8
#define POWER_OFF 0
#define POWER_ON 1
#define YUWEI_CMD_GESTURE_MODE 0x12
#define GESTURE_DATA_LEN 4
#define DISABLE_DOUBLE_CLICK 0x80
#define DISABLE_SINGLE_CLICK 0x10
#define YUWEI_CMD_RAWDATA 0x90
#define WORK_IN_SUSPEND 1
#define POWER_OFF_IN_SUSPEND 0
#define TAS_EVENT_TO_UDFP_MODE_TWO 2
#define MAX_CMD_DATA_LEN 10
#define MAX_CMD_BUF_LEN 16
#define REG_INT_CMD 0x10180
#define SEND_CMD_LEN 0x08
#define READ_CMD_TIMES 3
#define WRITE_CMD_TIMES 2
#define U32_CHECKSUM_FACTOR 2
#define U32_CHECKSUM_DATA_OFFSET1 1
#define U32_CHECKSUM_DATA_OFFSET2 2
#define U32_CHECKSUM_DATA_OFFSET3 3
#define COMMUNICATION_REUSE_IC_BEFORE_DELAY 5
#define SEND_GESTURE_CMD_BEFORE_DELAY 20
#define READ_CMD_ACK_BEFORE_DELAY 5
#define SEND_CMD_OFFSET_LEN 2
#define SEND_TP_AP_EVENT_BEFORE_DELAY 10

struct yuwei_cmd {
	union {
		struct {
			u8 state;
			u8 ack;
			u8 len;
			u8 cmd;
			u8 data[MAX_CMD_DATA_LEN];
		};
		u8 buf[MAX_CMD_BUF_LEN];
	};
};

#pragma pack(1)
struct thp_yuwei_cmd_ywt {
	union {
		struct {
			u8 state;
			u8 ack;
			u8 len;
			u8 cmd;
			u8 data[YUWEI_SWITCH_DATA_LEN_YWT];
			u16 checksum;
		};
		u8 buf[YUWEI_SWITCH_BUFF_LEN_YWT];
	};
};
#pragma pack()

#pragma pack(1)
struct yuwei_module_info {
	u8 mask_id[6]; /* 6 is mask id len */
	u8 mask_vid[3]; /* 3 is mask vid len */
	u8 pid[8]; /* 8 is pid len */
	u8 vid[4]; /* 4 is vid len */
	u8 sensor_id;
	u8 reserved[49]; /* 49 is reserved len */
	u8 checksum;
};
#pragma pack()

#pragma pack(1)
struct yuwei_module_info_for_ywt {
	u8 rom_pid[6]; /* rom PID */
	u8 rom_vid[3]; /* Mask VID */
	u8 rom_vid_reserved;
	u8 patch_pid[8]; /* Patch PID */
	u8 patch_vid[4]; /* Patch VID */
	u8 patch_vid_reserved;
	u8 sensor_id;
	u8 reserved[2];
	u16 checksum;
};
#pragma pack()

enum yuwei_ic_type {
	NONE_IC_TYPE = 0,
	YWT650C = 1,
	YWT680T = 2,
	YWT672T = 3,
};
enum data_offset_yuwei {
	DATA0 = 0,
	DATA1,
	DATA2,
};

struct yuewi_config_data {
	unsigned int irq_sync_method;
};

static u8 bt_connect_buf[BT_CONNECT_STATUS_BUF_LEN] = {
	0, 0, BT_CONNECT_BUF2, BT_CONNECT_BUF3,
	BT_CONNECT_BUF4, BT_CONNECT_BUF5, 0
};
static u8 bt_disconnect_buf[BT_CONNECT_STATUS_BUF_LEN] = {
	0, 0, BT_DISCONNECT_BUF2, BT_DISCONNECT_BUF3,
	0, BT_DISCONNECT_BUF5, 0
};
static u8 bt_adsorption_buf[BT_CONNECT_STATUS_BUF_LEN] = {
	0, 0, BT_ADSORPTION_BUF2, BT_ADSORPTION_BUF3,
	BT_ADSORPTION_BUF4, BT_ADSORPTION_BUF5, 0
};

struct gesture_info {
	u16 gesture_type;
	unsigned int gesture_value;
};

static struct gesture_info gesture_info_tab_for_ywt_dual[] = {
	{ GESTURE_TYPE_DOUBLE_TAP_YWT_DUAL, TS_DOUBLE_CLICK },
	{ GESTURE_TYPE_PEN_SINGLE_TAP_YWT_DUAL, TS_STYLUS_WAKEUP_TO_MEMO }
};

static struct yuwei_module_info module_info[TOTAL_PANEL_NUM];
static struct yuwei_module_info_for_ywt module_info_for_ywt[TOTAL_PANEL_NUM];
static struct yuewi_config_data config_data[TOTAL_PANEL_NUM];

static int g_yuwei_frame_addr[TOTAL_PANEL_NUM];
static int g_yuwei_frame_len[TOTAL_PANEL_NUM];
static int g_yuwei_cmd_addr[TOTAL_PANEL_NUM];
static int g_yuwei_fw_status_addr = YUWEI_FW_STATE_ADDR_DEFAULT;
static int g_yuwei_fw_status_len = YUWEI_FW_STATE_LEN_DEFAULT;
/*
 * g_yuwei_touch_addr is used only for tablet products.
 * Multi-screen resource extension is not supported currently.
 */
static int g_yuwei_touch_addr = YUWEI_TOUCH_ADDR_FOR_YWT_DUAL;
static unsigned int g_thp_udfp_status[TOTAL_PANEL_NUM];
static unsigned int g_yuwei_ring_setting_switch[TOTAL_PANEL_NUM];
static unsigned int g_yuwei_stylus_status[TOTAL_PANEL_NUM];
static unsigned int g_work_status[TOTAL_PANEL_NUM];
static unsigned int g_aod_touch_status[TOTAL_PANEL_NUM];
static u8 *g_yuwei_spi_tx_buf[TOTAL_PANEL_NUM];
static unsigned int g_power_off_staus[TOTAL_PANEL_NUM];
static char *tx_frame_buff[TOTAL_PANEL_NUM];
static char *rx_frame_buff[TOTAL_PANEL_NUM];

static int touch_driver_9x_bt_handler(struct thp_device *tdev,
	bool delay_enable);
static int touch_driver_gesture_event(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value);
static int touch_driver_gesture_event_for_ywt_dual(
	struct thp_device *tdev, unsigned int *gesture_wakeup_value);
static int touch_driver_switch_cmd(struct thp_device *tdev, u8 cmd, u8 status);
static int touch_driver_idle_wakeup(struct thp_device *tdev);
static int touch_driver_spi_active(struct thp_device *tdev);
static int touch_driver_spi_write_for_ywt(struct thp_device *tdev,
	u8 *tx_buf, unsigned int addr, struct spi_transfer *xfers,
	u8 *data, unsigned int len);
static int touch_driver_suspend_ap(struct thp_device *tdev);
static int touch_driver_spi_write(struct thp_device *tdev,
	unsigned int addr, u8 *data, unsigned int len);

static void touch_driver_clear_irq(struct thp_device *tdev)
{
	int ret;
	u8 sync_flag = 0;
	u32 panel_id = tdev->thp_core->panel_id;

	if (!config_data[panel_id].irq_sync_method)
		return;
	ret = touch_driver_spi_write(tdev, g_yuwei_frame_addr[panel_id], &sync_flag, 1);
	if (ret)
		thp_log_err("%s: clean sync flag fail\n", __func__);
}

static int touch_driver_spi_read_check(struct thp_device *tdev, unsigned int len)
{
	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C)) {
		if ((len + YUWEI_READ_BYTE_OFFSET_YWT672T) >
			thp_get_max_frame_size(tdev->thp_core)) {
			thp_log_err("%s: invalid len:%u\n", __func__, len);
			return -EINVAL;
		}
	} else {
		if ((len + READ_WRITE_BYTE_OFFSET) > thp_get_max_frame_size(tdev->thp_core)) {
			thp_log_err("%s: invalid len:%u\n", __func__, len);
			return -EINVAL;
		}
	}
	return NO_ERR;
}

static int touch_driver_spi_sync(struct thp_device *tdev,
	struct spi_device *spi, struct spi_message *spi_msg)
{
	int ret = NO_ERR;

	ret = thp_bus_lock(tdev);
	if (ret < 0) {
		thp_log_err("%s: get lock failed:%d\n", __func__, ret);
		return ret;
	}
	ret = thp_spi_sync(spi, spi_msg);
	thp_bus_unlock(tdev);
	if (ret < 0) {
		thp_log_err("Spi transfer error:%d\n", ret);
		return ret;
	}
	return ret;
}

static int touch_driver_spi_transfer(struct thp_device *tdev,
	struct spi_device *spi, struct spi_message *spi_msg)
{
	int ret = NO_ERR;

	ret = touch_driver_spi_sync(tdev, spi, spi_msg);
	if (ret < 0) {
		thp_log_err("%s: get spi sync failed:%d\n", __func__, ret);
		return ret;
	}
	return ret;
}

static int touch_driver_spi_copy_data(struct thp_device *tdev, u8 *rx_buf,
	u8 *data, unsigned int len)
{
	int ret;

	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		ret = memcpy_s(data, len, &rx_buf[YUWEI_READ_BYTE_OFFSET_YWT672T],
			len);
	else
		ret = memcpy_s(data, len, &rx_buf[READ_WRITE_BYTE_OFFSET], len);
	if (ret != EOK)
		thp_log_err("%s: copy data from rx_buf to data fail\n", __func__);
	return ret;
}

static void touch_driver_spi_read_for_default(u8 *start_cmd_buf,
	unsigned int addr, unsigned int len, struct spi_transfer *xfers,
	struct spi_message *spi_msg, u8 *tx_buf, u8 *rx_buf)
{
	int index = 0;

	start_cmd_buf[index++] = SPI_FLAG_WR; /* 0xF0 start write flag */
	start_cmd_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	start_cmd_buf[index++] = addr & MASK_8BIT;
	xfers[0].tx_buf = start_cmd_buf;
	xfers[0].rx_buf = rx_buf;
	xfers[0].len = READ_CMD_BUF_LEN;
	xfers[0].cs_change = 1;
	spi_message_add_tail(&xfers[0], spi_msg);
	tx_buf[0] = SPI_FLAG_RD; /* 0xF1 start read flag */
	xfers[1].tx_buf = tx_buf;
	xfers[1].rx_buf = rx_buf;
	xfers[1].len = len + READ_WRITE_BYTE_OFFSET;
	xfers[1].cs_change = 1;
	spi_message_add_tail(&xfers[1], spi_msg);
}

static void touch_driver_spi_read_for_ywt(unsigned int addr, unsigned int len,
	struct spi_transfer *xfers, struct spi_message *spi_msg,
	u8 *tx_buf, u8 *rx_buf)
{
	int index = 0;

	tx_buf[index++] = SPI_FLAG_RD; /* 0xF1 start read flag */
	tx_buf[index++] = (addr >> MOVE_24BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	xfers[0].tx_buf = tx_buf;
	xfers[0].rx_buf = rx_buf;
	xfers[0].len = len + YUWEI_READ_BYTE_OFFSET_YWT672T;
	xfers[0].cs_change = 1;
	spi_message_add_tail(xfers, spi_msg);
}

static int touch_driver_spi_read(struct thp_device *tdev, unsigned int addr,
	u8 *data, unsigned int len)
{
	struct thp_core_data *cd = tdev->thp_core;
	struct spi_device *spi = NULL;
	u8 *rx_buf = NULL;
	u8 *tx_buf = NULL;
	u8 *start_cmd_buf = g_yuwei_spi_tx_buf[cd->panel_id];
	struct spi_transfer xfers[YUWEI_SPI_READ_XFER_LEN];
	struct spi_message spi_msg;
	int ret;
	bool check_flag = false;

	check_flag = ((start_cmd_buf == NULL) || (data == NULL) ||
		(tdev->tx_buff == NULL) || (tdev->rx_buff == NULL) || (cd->sdev == NULL));
	if (check_flag) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	ret = touch_driver_spi_read_check(tdev, len);
	if (ret)
		return ret;
	spi = cd->sdev;
	rx_buf = tdev->rx_buff;
	tx_buf = tdev->tx_buff;
	spi_message_init(&spi_msg);
	memset_s(xfers, sizeof(xfers), 0, sizeof(xfers));
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		touch_driver_spi_read_for_ywt(addr, len, &xfers[0], &spi_msg, tx_buf, rx_buf);
	else
		touch_driver_spi_read_for_default(start_cmd_buf, addr, len,
			&xfers[0], &spi_msg, tx_buf, rx_buf);
	ret = touch_driver_spi_transfer(tdev, spi, &spi_msg);
	if (ret < 0)
		return ret;
	ret = touch_driver_spi_copy_data(tdev, rx_buf, data, len);
	return ret;
}

static int touch_driver_spi_read_frame(struct thp_device *tdev, unsigned int addr,
	u8 *data, unsigned int len)
{
	struct thp_core_data *cd = tdev->thp_core;
	struct spi_device *spi = NULL;
	u8 *rx_buf = NULL;
	u8 *tx_buf = NULL;
	u8 *start_cmd_buf = g_yuwei_spi_tx_buf[cd->panel_id];
	struct spi_transfer xfers[YUWEI_SPI_READ_XFER_LEN];
	struct spi_message spi_msg;
	int ret;
	bool check_flag = false;

	check_flag = ((start_cmd_buf == NULL) || (data == NULL) ||
		(tdev->tx_buff == NULL) || (tdev->rx_buff == NULL) || (cd->sdev == NULL));
	if (check_flag) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	ret = touch_driver_spi_read_check(tdev, len);
	if (ret)
		return ret;
	spi = cd->sdev;
	rx_buf = rx_frame_buff[cd->panel_id];
	tx_buf = tx_frame_buff[cd->panel_id];
	spi_message_init(&spi_msg);
	memset_s(xfers, sizeof(xfers), 0, sizeof(xfers));
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		touch_driver_spi_read_for_ywt(addr, len, &xfers[0], &spi_msg, tx_buf, rx_buf);
	else
		touch_driver_spi_read_for_default(start_cmd_buf, addr, len,
			&xfers[0], &spi_msg, tx_buf, rx_buf);
	ret = touch_driver_spi_transfer(tdev, spi, &spi_msg);
	if (ret < 0)
		return ret;
	ret = touch_driver_spi_copy_data(tdev, rx_buf, data, len);
	return ret;
}

static int touch_driver_spi_write(struct thp_device *tdev,
	unsigned int addr, u8 *data, unsigned int len)
{
	struct spi_device *spi = NULL;
	u8 *tx_buf = NULL;
	struct spi_transfer xfers;
	struct spi_message spi_msg;
	int ret = NO_ERR;
	struct thp_core_data *cd = NULL;

	if ((tdev == NULL) || (data == NULL) || (tdev->tx_buff == NULL) ||
		(tdev->rx_buff == NULL) || (tdev->thp_core == NULL) ||
		(tdev->thp_core->sdev == NULL)) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	spi = tdev->thp_core->sdev;
	tx_buf = tdev->tx_buff;
	cd = tdev->thp_core;
	spi_message_init(&spi_msg);
	memset_s(&xfers, sizeof(xfers), 0, sizeof(xfers));
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C)) {
		touch_driver_spi_write_for_ywt(tdev, tx_buf, addr,
			&xfers, data, len);
	} else {
		if (memcpy_s(&tx_buf[0], len, data, len) != EOK) {
			thp_log_err("%s: copy data to tx_buf fail\n");
			return -EINVAL;
		}
		xfers.len = len;
	}
	xfers.tx_buf = tx_buf;
	xfers.rx_buf = tdev->rx_buff;
	xfers.cs_change = 1;
	spi_message_add_tail(&xfers, &spi_msg);
	ret = thp_bus_lock(tdev);
	if (ret < 0) {
		thp_log_err("%s: get lock failed:%d\n", __func__, ret);
		return ret;
	}
	ret = thp_spi_sync(spi, &spi_msg);
	thp_bus_unlock(tdev);
	if (ret < 0)
		thp_log_err("Spi transfer error:%d, addr 0x%x\n", ret, addr);
	return ret;
}

static int touch_driver_spi_write_for_ywt(struct thp_device *tdev,
	u8 *tx_buf, unsigned int addr, struct spi_transfer *xfers,
	u8 *data, unsigned int len)
{
	int index = 0;

	if (tdev == NULL) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	tx_buf[index++] = SPI_FLAG_WR; /* 0xF1 start read flag */
	tx_buf[index++] = (addr >> MOVE_24BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	if (memcpy_s(&tx_buf[index++], len, data, len) != EOK) {
		thp_log_err("%s: copy data to tx_buf fail\n", __func__);
		return -EINVAL;
	}
	xfers->len = len + YUWEI_WRITE_BYTE_OFFSET_YWT672T; /* 5:WR header buf len */
	return NO_ERR;
}
static int touch_driver_get_cmd_ack(struct thp_device *tdev,
	unsigned int ack_reg)
{
	int ret;
	int i;
	u8 cmd_ack = 0;

	for (i = 0; i < CHECK_COMMAND_RETRY_TIMES; i++) {
		/* check command result */
		ret = touch_driver_spi_read(tdev, ack_reg,
			&cmd_ack, 1);
		if (ret < 0) {
			thp_log_err("%s: failed read cmd ack info, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		if (cmd_ack != CMD_ACK_OK) {
			ret = CMD_ACK_ERROR;
			if (cmd_ack == CMD_ACK_BUF_OVERFLOW) {
				mdelay(10); /* delay 10 ms */
				break;
			} else if ((cmd_ack == CMD_ACK_BUSY) ||
				(cmd_ack == CMD_ACK_UNKNOWN)) {
				mdelay(1); /* delay 1 ms */
				continue;
			}
			mdelay(1); /* delay 1 ms */
			break;
		}
		ret = NO_ERR;
		mdelay(SEND_COMMAND_END_DELAY);
		goto exit;
	}
exit:
	return ret;
}

static int touch_driver_get_cmd_ack_for_ywt(struct thp_device *tdev,
	unsigned int ack_reg)
{
	int ret;
	int i;
	u8 cmd_ack = 0;

	for (i = 0; i < CHECK_COMMAND_RETRY_TIMES; i++) {
		/* check command result */
		ret = touch_driver_spi_read(tdev, ack_reg,
			&cmd_ack, 1);
		if (ret < 0) {
			thp_log_err("%s: failed read cmd ack info, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		if (cmd_ack != CMD_ACK_OK_YWT) {
			ret = CMD_ACK_ERROR;
			if (cmd_ack == CMD_ACK_BUFFER_OVERFLOW_YWT) {
				mdelay(10); /* delay 10 ms */
				break;
			} else if ((cmd_ack == CMD_ACK_BUSY_YWT) ||
				(cmd_ack == CMD_ACK_UNKNOWN)) {
				mdelay(1); /* delay 1 ms */
				continue;
			}
			mdelay(1); /* delay 1 ms */
			break;
		}
		ret = NO_ERR;
		msleep(YUWEI_SEND_CMD_WAIT_DELAY_YWT);
		goto exit;
	}
exit:
	return ret;
}

static int touch_drive_switch_cmd_for_ywt(
	struct thp_device *tdev, u8 cmd, u16 data)
{
	int ret;
	int i;
	struct thp_yuwei_cmd_ywt cmd_send;
	struct thp_core_data *cd = tdev->thp_core;

	memset_s(&cmd_send, sizeof(cmd_send), 0, sizeof(cmd_send));
	cmd_send.len = YUWEI_SWITCH_CMD_LEN_YWT;
	cmd_send.cmd = cmd;
	cmd_send.data[0] = data & MASK_8BIT;
	cmd_send.data[1] = (data >> MOVE_8BIT) & MASK_8BIT;
	cmd_send.checksum = cpu_to_le16(cmd_send.len + cmd_send.cmd +
		cmd_send.data[0] + cmd_send.data[1]);
	for (i = 0; i < SEND_COMMAND_RETRY_TIMES; i++) {
		ret = touch_driver_spi_write(tdev, g_yuwei_cmd_addr[cd->panel_id],
			cmd_send.buf, sizeof(cmd_send));
		if (ret < 0) {
			thp_log_err("%s: failed send command, ret %d\n", __func__, ret);
			return -EINVAL;
		}
		ret = touch_driver_get_cmd_ack_for_ywt(tdev,
			g_yuwei_cmd_addr[cd->panel_id] + YUWEI_CMD_ACK_OFFSET_YWT);
		if (ret == CMD_ACK_ERROR) {
			thp_log_err("%s: cmd ack info is error\n", __func__);
			continue;
		} else {
			break;
		}
	}
	return ret;
}

static int touch_driver_switch_cmd_for_default(struct thp_device *tdev,
	u8 cmd, u8 status)
{
	int ret = NO_ERR;
	int retry = 0;
	int index = 0;
	u8 cmd_buf[COMMAND_BUF_LEN];
	u8 cmd_ack = 0;

	if (touch_driver_idle_wakeup(tdev)) {
		thp_log_err("%s: failed wakeup idle before send command\n", __func__);
		return -EINVAL;
	}
	cmd_buf[index++] = cmd;
	cmd_buf[index++] = status;
	cmd_buf[index++] = (u8)(0 - cmd_buf[1] - cmd_buf[0]); /* use complementary code for checksum */
	cmd_buf[index++] = 0;
	cmd_buf[index++] = 0; /* use to clear cmd ack flag */
	while (retry++ < SEND_COMMAND_RETRY_TIMES) {
		ret = touch_driver_spi_write(tdev, g_yuwei_cmd_addr[tdev->thp_core->panel_id],
			cmd_buf, sizeof(cmd_buf));
		if (ret < 0) {
			thp_log_err("%s: failed send command, ret %d\n", __func__, ret);
			return -EINVAL;
		}
		ret = touch_driver_spi_read(tdev,
			g_yuwei_cmd_addr[tdev->thp_core->panel_id] + CMD_ACK_OFFSET,
			&cmd_ack, SEND_COMMAND_SPI_READ_LEN);
		if (ret < 0) {
			thp_log_err("%s: failed read command ack info, ret %d\n", __func__, ret);
			return -EINVAL;
		}
		if (cmd_ack != CMD_ACK_OK) {
			ret = -EINVAL;
			thp_log_debug("%s: command state ack info 0x%x\n", __func__, cmd_ack);
			if (cmd_ack == CMD_ACK_BUF_OVERFLOW || cmd_ack == CMD_ACK_BUSY)
				mdelay(SEND_COMMAND_WAIT_DELAY);
		} else {
			ret = NO_ERR;
			mdelay(SEND_COMMAND_END_DELAY);
			break;
		}
	}
	return ret;
}

static int touch_driver_switch_cmd(struct thp_device *tdev,
	u8 cmd, u8 status)
{
	struct thp_core_data *cd = NULL;

	if ((tdev == NULL) || (tdev->thp_core == NULL)) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	thp_log_info("%s: called cmd = %x, status = %u\n", __func__, cmd, status);
	cd = tdev->thp_core;
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		return touch_drive_switch_cmd_for_ywt(tdev, cmd, status);
	else
		return touch_driver_switch_cmd_for_default(tdev, cmd, status);
}

static int thp_parse_feature_ic_config(struct device_node *thp_node,
	struct thp_core_data *cd)
{
	if (cd->support_vendor_ic_type == YWT672T)
		cd->cmd_gesture_mode = CMD_GESTURE_MODE_YWT;
	else
		cd->cmd_gesture_mode = CMD_GESTURE_MODE;
	thp_parse_dts_u32(thp_node, "cmd_gesture_mode", &cd->cmd_gesture_mode, __func__);
	thp_log_info("%s:cd->cmd_gesture_mode = 0x%X\n", __func__, cd->cmd_gesture_mode);
	if (of_property_read_string(thp_node, "multi_vendor_name", &cd->thp_dev->multi_vendor_name))
		cd->thp_dev->multi_vendor_name = "null";
	cd->sensorhub_support_gesture = 0;
	thp_parse_dts_u32(thp_node, "sensorhub_support_gesture", &cd->sensorhub_support_gesture, __func__);
	cd->gesture_mode_double_tap = 0;
	thp_parse_dts_u32(thp_node, "gesture_mode_double_tap", &cd->gesture_mode_double_tap, __func__);
	thp_parse_dts_u32(thp_node, "support_fake_panel", &cd->support_fake_panel, __func__);
	/*
	 * 0: Asynchronous, 1:Synchronous
	 */
	config_data[cd->panel_id].irq_sync_method = 0;
	thp_parse_dts_u32(thp_node, "irq_sync_method",
		&config_data[cd->panel_id].irq_sync_method, __func__);
	cd->support_reuse_ic_type = 0;
	thp_parse_dts_u32(thp_node, "support_reuse_ic_type", &cd->support_reuse_ic_type, __func__);
	cd->not_reuse_ic_type = 0;
	thp_parse_dts_u32(thp_node, "not_reuse_ic_type", &cd->not_reuse_ic_type, __func__);
	cd->disable_frame_report = 0;
	thp_parse_dts_u32(thp_node, "disable_frame_report", &cd->disable_frame_report, __func__);
	cd->need_extra_system_clk = 0;
	thp_parse_dts_u32(thp_node, "need_extra_system_clk", &cd->need_extra_system_clk, __func__);
	cd->support_fw_xtal_switch = 0;
	thp_parse_dts_u32(thp_node, "support_fw_xtal_switch", &cd->support_fw_xtal_switch, __func__);
	return NO_ERR;
}

static int touch_driver_init(struct thp_device *tdev)
{
	int rc;
	struct thp_core_data *cd = NULL;
	struct device_node *yuwei_node = NULL;

	if (tdev == NULL) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	yuwei_node = of_get_child_by_name(cd->thp_node, THP_YUWEI_DEV_NODE_NAME);
	thp_log_info("%s: called, ic_type %d\n", __func__,
		cd->support_vendor_ic_type);
	if (!yuwei_node) {
		thp_log_err("%s: dev not config in dts\n", __func__);
		return -ENODEV;
	}
	rc = thp_parse_spi_config(yuwei_node, cd);
	if (rc)
		thp_log_err("%s: spi config parse fail\n", __func__);
	rc = thp_parse_timing_config(yuwei_node, &tdev->timing_config);
	if (rc)
		thp_log_err("%s: timing config parse fail\n", __func__);
	rc = thp_parse_feature_config(yuwei_node, cd);
	if (rc)
		thp_log_err("%s: feature_config fail\n", __func__);
	rc = thp_parse_feature_ic_config(yuwei_node, cd);
	if (rc)
		thp_log_err("%s: feature_ic_config fail, use default\n", __func__);
	if (cd->support_gesture_mode) {
		cd->easy_wakeup_info.sleep_mode = TS_POWER_OFF_MODE;
		cd->easy_wakeup_info.easy_wakeup_gesture = false;
		cd->easy_wakeup_info.off_motion_on = false;
	}
	rc = thp_parse_trigger_config(yuwei_node, cd);
	if (rc)
		thp_log_err("%s: trigger_config fail\n", __func__);
	return NO_ERR;
}

static u8 checksum_u8(u8 *data, u32 size)
{
	u8 checksum = 0;
	u32 i;
	u32 zero_count = 0;

	for (i = 0; i < size; i++) {
		checksum += data[i];
		if (!data[i])
			zero_count++;
	}
	return (zero_count == size) ? MASK_8BIT : checksum;
}

static u16 checksum16_cmp(u8 *data, u32 size, int mode)
{
	u16 cal_checksum = 0;
	u16 checksum;
	u32 i;

	if (size < sizeof(checksum)) {
		thp_log_err("%s: inval parm\n", __func__);
		return 1;
	}
	for (i = 0; i < size - sizeof(checksum); i++)
		cal_checksum += data[i];
	if (mode == YUWEI_BE_MODE)
		checksum = (data[size - sizeof(checksum)] << MOVE_8BIT) +
			data[size - 1];
	else
		checksum = data[size - sizeof(checksum)] +
			(data[size - 1] << MOVE_8BIT);
	return (cal_checksum == checksum) ? 0 : 1;
}

static int touch_driver_communication_check_for_ywt(struct thp_device *tdev)
{
	int len;
	int ret;
	int retry;
	u32 panel_id = tdev->thp_core->panel_id;

	len = sizeof(module_info_for_ywt[panel_id]);
	memset_s(&module_info_for_ywt[panel_id], len, 0, len);
	for (retry = 0; retry < MODULE_INFO_READ_RETRY_TIMES; retry++) {
		ret = touch_driver_spi_read(tdev, YUWEI_MODULE_INFO_ADDR_YWT672T,
			(u8 *)&module_info_for_ywt[panel_id], len);
		thp_log_debug("module_info:%*ph\n", len, (u8 *)&module_info_for_ywt[panel_id]);
		if (!ret && !checksum16_cmp((u8 *)&module_info_for_ywt[panel_id],
			len, YUWEI_LE_MODE))
			break;
		/* retry need delay 10ms */
		usleep_range(MODULE_INFO_READ_RETRY_DELAY_MIN, MODULE_INFO_READ_RETRY_DELAY_MAX);
	}
	thp_log_info("%s: module_info: ret %d, retry %d\n", __func__, ret, retry);
	if (retry == MODULE_INFO_READ_RETRY_TIMES) {
		thp_log_err("%s: failed read module info\n", __func__);
		return -EINVAL;
	}
	if (memcmp(module_info_for_ywt[panel_id].rom_pid, YUWEI_MASK_ID_FOR_YWT,
		YUWEI_MASK_ID_LEN_DEFAULT)) {
		thp_log_err("invalied mask id %s != %s\n",
			module_info_for_ywt[panel_id].rom_pid, YUWEI_MASK_ID_FOR_YWT);
		if (memcmp(module_info_for_ywt[panel_id].rom_pid,
			YUWET_MASK_ID_FOR_YWT_NOCODE, YUWEI_MASK_ID_LEN_DEFAULT)) {
			thp_log_err("invalied mask id %s != %s\n",
				module_info_for_ywt[panel_id].rom_pid, YUWET_MASK_ID_FOR_YWT_NOCODE);
			return -EINVAL;
		}
	}
	thp_log_info("%s: rom_pid:%s\n", __func__, module_info_for_ywt[panel_id].rom_pid);
	thp_log_info("%s: rom_vid:%*ph\n", __func__, sizeof(module_info_for_ywt[panel_id].rom_vid),
		module_info_for_ywt[panel_id].rom_vid);
	thp_log_info("%s: patch_pid:%s\n", __func__, module_info_for_ywt[panel_id].patch_pid);
	thp_log_info("%s: patch_vid:%*ph\n", __func__, sizeof(module_info_for_ywt[panel_id].patch_vid),
		module_info_for_ywt[panel_id].patch_vid);
	return NO_ERR;
}

static int touch_driver_communication_check_for_defalut(struct thp_device *tdev)
{
	int ret;
	int len;
	int retry;
	u8 checksum;
	u32 panel_id = tdev->thp_core->panel_id;

	len = sizeof(module_info[panel_id]);
	memset_s(&module_info[panel_id], len, 0, len);
	for (retry = 0; retry < MODULE_INFO_READ_RETRY_TIMES; retry++) {
		ret = touch_driver_spi_read(tdev, YUWEI_MODULE_INFO_ADDR_DEFAULT,
			(u8 *)&module_info[panel_id], len);
		/* print 32*3 data (rowsize=32,groupsize=3) */
		print_hex_dump(KERN_INFO, "[I/THP] module info: ", DUMP_PREFIX_NONE,
			YUWEI_MODULE_INFO_ROW_SIZE, YUWEI_MODULE_INFO_GROUP_NUM,
			(u8 *)&module_info[panel_id], len, 0);
		checksum = checksum_u8((u8 *)&module_info[panel_id], len);
		if (!ret && !checksum)
			break;
		mdelay(COMMUNI_CHECK_RETRY_DELAY);
	}
	thp_log_info("hw info: ret %d, checksum 0x%x, retry %d\n", ret,
		checksum, retry);
	if (retry == MODULE_INFO_READ_RETRY_TIMES) {
		thp_log_err("%s: failed read module info\n", __func__);
		return -EINVAL;
	}
	if (memcmp(module_info[panel_id].mask_id, YUWEI_MASK_ID_DEFAULT,
			sizeof(YUWEI_MASK_ID_DEFAULT) - 1)) {
		thp_log_err("%s: invalied mask id %s != %s\n",
			__func__, module_info[panel_id].mask_id, YUWEI_MASK_ID_DEFAULT);
		return -EINVAL;
	}
	thp_log_info("%s: communication check passed\n", __func__);
	thp_log_info("MASK_ID %s : ver %*ph\n", module_info[panel_id].mask_id,
		(u32)sizeof(module_info[panel_id].mask_vid), module_info[panel_id].mask_vid);
	thp_log_info("PID %s : ver %*ph\n", module_info[panel_id].pid,
		(u32)sizeof(module_info[panel_id].vid), module_info[panel_id].vid);
	return NO_ERR;
}

static int touch_driver_communication_check(struct thp_device *tdev)
{
	struct thp_core_data *cd = NULL;

	if ((tdev == NULL) || (tdev->thp_core == NULL)) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	thp_log_info("%s: ic_type %d\n", __func__, cd->support_vendor_ic_type);
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		return touch_driver_communication_check_for_ywt(tdev);
	else
		return touch_driver_communication_check_for_defalut(tdev);
}

static int touch_driver_power_init(u32 panel_id)
{
	int ret;
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	if (cd->power_cfg.power_supply_mode)
		return NO_ERR;
	ret = thp_power_supply_get(THP_VCC, panel_id);
	if (ret)
		thp_log_err("%s: vcc fail\n", __func__);
	ret = thp_power_supply_get(THP_IOVDD, panel_id);
	if (ret)
		thp_log_err("%s: iovdd fail\n", __func__);
	return NO_ERR;
}

static void touch_driver_power_release(u32 panel_id)
{
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	if (cd->power_cfg.power_supply_mode)
		return;
	thp_power_supply_put(THP_VCC, panel_id);
	thp_power_supply_put(THP_IOVDD, panel_id);
}

static int touch_driver_power_on(struct thp_device *tdev)
{
	int ret;

	thp_log_info("%s: called\n", __func__);
	if (tdev->thp_core->power_cfg.power_supply_mode)
		return NO_ERR;
	if (!tdev->thp_core->not_support_cs_control)
		gpio_direction_output(tdev->gpios->cs_gpio, GPIO_HIGH);
	ret = thp_power_supply_ctrl(THP_VCC, THP_POWER_ON, 0, 
		tdev->thp_core->panel_id);
	if (ret)
		thp_log_err("%s: vcc fail\n", __func__);
	ret = thp_power_supply_ctrl(THP_IOVDD, THP_POWER_ON, 1,
		tdev->thp_core->panel_id);
	if (ret)
		thp_log_err("%s: iovdd fail\n", __func__);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
	return ret;
}

static int touch_driver_power_on_reset(struct thp_device *tdev)
{
	if (tdev == NULL) {
		thp_log_err("%s: have null point\n", __func__);
		return -EINVAL;
	}
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	mdelay(tdev->timing_config.resume_reset_after_delay_ms);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
	return NO_ERR;
}

static int thp_power_on_iovdd_vcc_ywt(struct thp_core_data *cd)
{
	int ret;
		
	ret = thp_power_supply_ctrl(THP_IOVDD, THP_POWER_ON,
		YUWEI_AFTER_IOVDD_DELAY_YWT, cd->panel_id);
	if (ret)
		thp_log_err("%s: vddio fail\n", __func__);
	ret = thp_power_supply_ctrl(THP_VCC, THP_POWER_ON,
		YUWEI_AFTER_DVDD_RST_DELAY_YWT, cd->panel_id);
	if (ret)
		thp_log_err("%s: vcc fail\n", __func__);
	thp_log_info("%s: pull up tp ic reset\n", __func__);
	return ret;
}

static int touch_driver_power_on_for_ywt(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = NULL;
	bool flag;

	flag = (tdev == NULL || tdev->thp_core == NULL);
	if (flag) {
		thp_log_err("%s: have null point\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	if (cd->power_cfg.power_supply_mode)
		return NO_ERR;
	thp_log_info("%s: called\n", __func__);
	if (cd->not_control_power)
		return touch_driver_power_on_reset(tdev);
	if (!cd->not_support_cs_control)
		gpio_direction_output(tdev->gpios->cs_gpio, GPIO_HIGH);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	ret = thp_power_on_iovdd_vcc_ywt(cd);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
	return ret;
}

static int touch_driver_power_on_for_ictype(struct thp_device *tdev)
{
	int ret;

	thp_log_info("%s : called\n", __func__);
	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		ret = touch_driver_power_on_for_ywt(tdev);
	else
		ret = touch_driver_power_on(tdev);
	return ret;
}

static int power_off(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = thp_get_core_data(tdev->thp_core->panel_id);

	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	thp_do_time_delay(tdev->timing_config.suspend_reset_after_delay_ms);
	ret = thp_power_supply_ctrl(THP_IOVDD, THP_POWER_OFF, NO_DELAY, cd->panel_id);
	if (ret)
		thp_log_err("%s: iovdd fail\n", __func__);
	ret = thp_power_supply_ctrl(THP_VCC, THP_POWER_OFF,
		tdev->timing_config.later_power_off_delay_ms, cd->panel_id);
	if (ret)
		thp_log_err("%s: vcc fail\n", __func__);
	if (!cd->not_support_cs_control)
		gpio_direction_output(tdev->gpios->cs_gpio, GPIO_LOW);
	return ret;
}

static int touch_driver_power_off(struct thp_device *tdev)
{
	int ret = NO_ERR;
	struct thp_core_data *cd = NULL;
	bool flag;

	flag = (tdev == NULL || tdev->thp_core == NULL);
	if (flag) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	cd = thp_get_core_data(tdev->thp_core->panel_id);
	if (cd->power_cfg.power_supply_mode)
		return NO_ERR;
	thp_log_info("%s: pull down tp ic reset\n", __func__);
	ret = power_off(tdev);
	return ret;
}

static void touch_driver_timing_work(struct thp_device *tdev)
{
	if (tdev == NULL) {
		thp_log_err("%s: tdev null\n", __func__);
		return;
	}
	thp_log_info("%s: called,do hard reset delay:%d\n", __func__,
		tdev->timing_config.boot_reset_after_delay_ms);
	gpio_direction_output(tdev->gpios->rst_gpio, THP_RESET_HIGH);
	thp_do_time_delay(tdev->timing_config.boot_reset_after_delay_ms);
}

static u16 checksum_16(u8 *data, int size)
{
	int i;
	int non_zero_count = 0;
	u16 checksum = 0;

	if ((data == NULL) || (size <= sizeof(u16))) {
		thp_log_err("%s: tdev null\n", __func__);
		return MASK_8BIT;
	}
	for (i = 0; i < (size - sizeof(u16)); i++) {
		checksum += data[i];
		if (data[i])
			non_zero_count++;
	}
	checksum += (data[i] << MOVE_8BIT) + data[i + 1];
	return non_zero_count ? checksum : MASK_8BIT;
}

static u32 checksum_32(u8 *data, int size)
{
	int i;
	const int factor = U32_CHECKSUM_FACTOR;
	int non_zero_count = 0;
	u32 checksum = 0;

	if ((data == NULL) || (size <= sizeof(u32))) {
		thp_log_err("%s: tdev null\n", __func__);
		return MASK_8BIT;
	}
	for (i = 0; i < (size - sizeof(u32)); i += factor) {
		checksum += ((data[i] << MOVE_8BIT) | data[i + 1]);
		if (data[i] || data[i + 1])
			non_zero_count++;
	}
	checksum += (data[i] << MOVE_24BIT) + (data[i + U32_CHECKSUM_DATA_OFFSET1] << MOVE_16BIT) +
		    (data[i + U32_CHECKSUM_DATA_OFFSET2] << MOVE_8BIT) + data[i + U32_CHECKSUM_DATA_OFFSET3];
	return non_zero_count ? checksum : MASK_8BIT;
}

static int touch_driver_get_afe_info_for_ywt(struct thp_device *tdev)
{
	struct thp_core_data *cd = tdev->thp_core;

	if (cd->support_vendor_ic_type == YWT650C) {
		g_yuwei_frame_addr[cd->panel_id] = YUWEI_FRAME_ADDR_DEFAULT_YWT650C;
		g_yuwei_frame_len[cd->panel_id] = YUWEI_FRAME_LEN_MAX_YWT650C;
	} else if (cd->support_vendor_ic_type == YWT680T) {
		g_yuwei_frame_addr[cd->panel_id] = YUWEI_FRAME_ADDR_DEFAULT_YUT680T;
		g_yuwei_frame_len[cd->panel_id] = YUWEI_FRAME_LEN_MAX_YWT680T;
	} else if (cd->support_vendor_ic_type == YWT672T) {
		g_yuwei_frame_addr[cd->panel_id] = YUWEI_FRAME_ADDR_DEFAULT_YWT672T;
		g_yuwei_frame_len[cd->panel_id] = YUWEI_FRAME_LEN_MAX_YWT672T;
	}
	if (cd->support_vendor_ic_type == YWT650C)
		g_yuwei_cmd_addr[cd->panel_id] = YUWEI_CMD_ADDR_DEFAULT_YWT650C;
	else
		g_yuwei_cmd_addr[cd->panel_id] = YUWEI_CMD_ADDR_DEFAULT_YWT672T;
	thp_log_info("%s: addr info, frame 0x%x:%d, cmd 0x%x\n",
		__func__, g_yuwei_frame_addr[cd->panel_id],
		g_yuwei_frame_len[cd->panel_id], g_yuwei_cmd_addr[cd->panel_id]);
	return NO_ERR;
}

static void touch_driver_show_afe_debug_info(u8 *debug_buf, int len,
	int debug_info_count)
{
	int i;

	if ((len <= 0) || (len > YUWEI_MAX_AFE_LEN_DEFAULT) ||
		((debug_info_count * DEBUG_AFE_DATA_BUF_OFFSET) > YUWEI_MAX_AFE_LEN_DEFAULT)) {
		thp_log_err("%s: invalid len:%d, count:%d\n", __func__,
			len, debug_info_count);
		return;
	}
	for (i = 0; i < debug_info_count; i++)
		thp_log_info("debug_buf[%d-%d] %*ph\n", i * DEBUG_AFE_DATA_BUF_OFFSET,
			(i + 1) * DEBUG_AFE_DATA_BUF_OFFSET, DEBUG_AFE_DATA_BUF_LEN,
			debug_buf + i * DEBUG_AFE_DATA_BUF_OFFSET);
}

static void touch_driver_get_afe_addr_for_default(const u8 * const afe_data_buf,
	unsigned int len, u32 panel_id)
{
	if ((len == 0) || (len > YUWEI_MAX_AFE_LEN_DEFAULT)) {
		thp_log_err("%s: invalid len:%d\n", __func__, len);
		return;
	}
	thp_log_info("%s: try get useful info from afe data\n", __func__);
	g_yuwei_frame_addr[panel_id] =
		(afe_data_buf[YUWEI_FRAME_ADDR_OFFSET_DEFAULT] << MOVE_8BIT) +
		afe_data_buf[YUWEI_FRAME_ADDR_OFFSET_DEFAULT + 1];
	g_yuwei_frame_len[panel_id] =
		(afe_data_buf[YUWEI_FRAME_LEN_OFFSET_DEFAULT] << MOVE_8BIT) +
		afe_data_buf[YUWEI_FRAME_LEN_OFFSET_DEFAULT + 1];
	g_yuwei_cmd_addr[panel_id] =
		(afe_data_buf[YUWEI_CMD_ADDR_OFFSET_DEFAULT] << MOVE_8BIT) +
		afe_data_buf[YUWEI_CMD_ADDR_OFFSET_DEFAULT + 1];
	g_yuwei_fw_status_addr =
		(afe_data_buf[YUWEI_FW_STATUS_ADDR_OFFSET_DEFAULT] <<
		MOVE_8BIT) +
		afe_data_buf[YUWEI_FW_STATUS_ADDR_OFFSET_DEFAULT + 1];
	g_yuwei_fw_status_len =
		(afe_data_buf[YUWEI_FW_STATUS_LEN_OFFSET_DEFAULT] <<
		MOVE_8BIT) +
		afe_data_buf[YUWEI_FW_STATUS_LEN_OFFSET_DEFAULT + 1];
	thp_log_info("%s: frame addr 0x%x, len %d, cmd addr 0x%x\n",
		__func__, g_yuwei_frame_addr[panel_id],
		g_yuwei_frame_len[panel_id], g_yuwei_cmd_addr[panel_id]);
	thp_log_info("%s: fw status addr 0x%x, len %d\n", __func__,
		g_yuwei_fw_status_addr, g_yuwei_fw_status_len);
}

static int touch_driver_get_afe_info_for_default(struct thp_device *tdev)
{
	int ret;
	int retry;
	unsigned int afe_data_len;
	u8 buf[INFO_ADDR_BUF_LEN] = {0};
	u8 afe_data_buf[YUWEI_MAX_AFE_LEN_DEFAULT] = {0};
	struct thp_core_data *cd = tdev->thp_core;

	for (retry = 0; retry < FW_INFO_READ_RETRY_TIMES; retry++) {
		ret = touch_driver_spi_read(tdev, YUWEI_AFE_INFO_ADDR_DEFAULT, buf, sizeof(buf));
		if (ret) {
			thp_log_err("%s: failed read afe data length, ret %d\n", __func__, ret);
			goto err_out;
		}
		afe_data_len = (buf[0] << MOVE_8BIT) | buf[1];
		/* data len must be equal or less than YUWEI_MAX_AFE_LEN_DEFAULT */
		if ((afe_data_len == 0) || (afe_data_len > YUWEI_MAX_AFE_LEN_DEFAULT) ||
			(afe_data_len & MASK_1BIT)) {
			thp_log_err("%s: invalied afe_data_len 0x%x retry\n", __func__, afe_data_len);
			mdelay(GET_AFE_INFO_RETRY_DELAY);
			continue;
		}
		thp_log_info("%s: got afe data len %d\n", __func__, afe_data_len);
		ret = touch_driver_spi_read(tdev, YUWEI_AFE_INFO_ADDR_DEFAULT + INFO_ADDR_BUF_LEN,
			afe_data_buf, afe_data_len);
		if (ret) {
			thp_log_err("%s: failed read afe data, ret %d\n", __func__, ret);
			goto err_out;
		}
		if (!checksum_32(afe_data_buf, afe_data_len)) {
			thp_log_info("%s: successfuly read afe data\n", __func__);
			break;
		}
		thp_log_err("%s: afe data checksum error, retry\n", __func__);
		/* print 5 rounds of debug info  */
		touch_driver_show_afe_debug_info(afe_data_buf, YUWEI_MAX_AFE_LEN_DEFAULT, 5);
		mdelay(GET_AFE_INFO_RETRY_DELAY);
	}
	if (retry != FW_INFO_READ_RETRY_TIMES) {
		touch_driver_get_afe_addr_for_default(afe_data_buf, YUWEI_MAX_AFE_LEN_DEFAULT, cd->panel_id);
		return NO_ERR;
	}
err_out:
	thp_log_err("%s: failed get afe info, use default\n", __func__);
	g_yuwei_frame_addr[cd->panel_id] = YUWEI_FRAME_ADDR_DEFAULT;
	g_yuwei_cmd_addr[cd->panel_id] = YUWEI_CMD_ADDR_DEFAULT;
	thp_log_info("%s: frame addr 0x%x, len %d, cmd addr 0x%x\n",
		__func__, g_yuwei_frame_addr[cd->panel_id],
		g_yuwei_frame_len[cd->panel_id], g_yuwei_cmd_addr[cd->panel_id]);
	thp_log_info("%s: fw status addr 0x%x, len %d\n", __func__,
		g_yuwei_fw_status_addr, g_yuwei_fw_status_len);
	return -EINVAL;
}

static int touch_driver_get_afe_info(struct thp_device *tdev)
{
	struct thp_core_data *cd = tdev->thp_core;

	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		return touch_driver_get_afe_info_for_ywt(tdev);
	return touch_driver_get_afe_info_for_default(tdev);
}

static void fastboot_booting_mm_release(struct thp_device *tdev)
{
	struct thp_core_data *cd = NULL;

	if (!tdev) {
		thp_log_err("%s: tdev is null, return\n", __func__);
		return;
	}
	cd = tdev->thp_core;
	if (tdev->thp_core->fast_booting_solution) {
		kfree(tdev->tx_buff);
		tdev->tx_buff = NULL;
		kfree(tdev->rx_buff);
		tdev->rx_buff = NULL;
		kfree(tx_frame_buff[cd->panel_id]);
		tx_frame_buff[cd->panel_id] = NULL;
		kfree(rx_frame_buff[cd->panel_id]);
		rx_frame_buff[cd->panel_id] = NULL;
		kfree(tdev);
		tdev = NULL;
	}
}

static int alloc_spi_memory_in_dma(struct thp_core_data *cd)
{
	thp_log_info("%s: apply_spi_memory_in_dma: %d\n", __func__, cd->apply_spi_memory_in_dma);
	if (cd->apply_spi_memory_in_dma)
		g_yuwei_spi_tx_buf[cd->panel_id] = kzalloc(READ_CMD_BUF_LEN, GFP_KERNEL | GFP_DMA);
	else
		g_yuwei_spi_tx_buf[cd->panel_id] = kzalloc(READ_CMD_BUF_LEN, GFP_KERNEL);
	if (g_yuwei_spi_tx_buf[cd->panel_id] == NULL) {
		thp_log_err("%s: panel %u g_yuwei_spi_tx_buf null\n", __func__, cd->panel_id);
		return -ENOMEM;
	}
	return NO_ERR;
}

static int chip_detect_fail_check_communication(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;

	if (touch_driver_communication_check(tdev)) {
		thp_log_err("%s: communication check fail\n", __func__);
		touch_driver_power_off(tdev);
		if (cd->not_reuse_ic_type) {
			touch_driver_power_release(cd->panel_id);
			return -ENODEV;
		}
		/* check old panel */
		if (cd->support_reuse_ic_type == YWT680T) {
			msleep(COMMUNICATION_REUSE_IC_BEFORE_DELAY); /* delay time 5ms */
			cd->support_vendor_ic_type = YWT680T;
			ret = touch_driver_power_on_for_ywt(tdev);
		}
		touch_driver_timing_work(tdev);
		if (touch_driver_communication_check(tdev)) {
			thp_log_err("%s: check old fail\n", __func__);
			touch_driver_power_off(tdev);
			touch_driver_power_release(cd->panel_id);
			return -ENODEV;
		}
	}
	return NO_ERR;
}

static int touch_driver_chip_detect(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;

	thp_log_info("%s: called\n", __func__);
	ret = alloc_spi_memory_in_dma(cd);
	if (ret)
		goto exit;
	thp_log_info("%s: ic_type %d\n", __func__, cd->support_vendor_ic_type);
	if (cd->support_adapter_mode) {
		ret = support_power_adapter_mode(tdev, THP_POWER_ON);
		if (ret)
			goto exit;
	} else {
		touch_driver_power_init(tdev->thp_core->panel_id);
		ret = touch_driver_power_on_for_ictype(tdev);
		if (ret)
			thp_log_err("%s: power on failed\n", __func__);
	}
	touch_driver_timing_work(tdev);
	ret = chip_detect_fail_check_communication(tdev);
	if (ret)
		goto exit;
	if (cd->send_bt_status_to_fw && cd->support_dual_chip_arch) {
		cd->enter_stylus3_mmi_test = false;
		if (touch_driver_9x_bt_handler(tdev, false))
			thp_log_err("power on send stylus3 connect status fail\n");
	}
	pen_clk_control(CLK_ENABLE, tdev->thp_core->panel_id);
	if (touch_driver_get_afe_info(tdev))
		thp_log_err("%s: failed get afe addr info\n", __func__);
	return NO_ERR;
exit:
	kfree(g_yuwei_spi_tx_buf[cd->panel_id]);
	g_yuwei_spi_tx_buf[cd->panel_id] = NULL;
	if (tdev->thp_core->support_adapter_mode)
		thp_power_adapter_release(&tdev->thp_core->power_adapter);
	fastboot_booting_mm_release(tdev);
	return ret;
}

#pragma pack(1)
struct frame_head {
	u8 sync;
	u16 frame_index;
	u16 cur_frame_len;
	u16 nxt_frame_len;
	/* 0- 7 for pack_en; 8 - 31 for type en */
	u32 data_en;
	u8 touch_pack_index;
	u8 stylus_pack_index;
	u8 res;
	u16 checksum;
};
#pragma pack()

static int le16_data_check(u8 *data, int size)
{
	int i;
	int non_zero_count = 0;
	u16 checksum = 0;

	for (i = 0; i < (size - (int)(sizeof(u16))); i++) {
		checksum += data[i];
		if (data[i])
			non_zero_count++;
	}
	checksum -= data[i] + (data[i + 1] << MOVE_8BIT);
	return non_zero_count ? checksum : MASK_8BIT;
}

static int touch_driver_get_next_frame_len(struct thp_device *tdev, u8 *buf)
{
	struct frame_head cur_head;
	static struct frame_head pre_head = {
		0, 0, 0, FRAME_HEAD_LEN,
		FRAME_HEAD_LEN, 0, 0, 0, 0
	};

	if (memcpy_s(&cur_head, sizeof(cur_head), buf, sizeof(cur_head)) != EOK) {
		thp_log_err("cp cur head from buf fail\n");
		return pre_head.nxt_frame_len;
	}
	cur_head.frame_index = le16_to_cpu(cur_head.frame_index);
	cur_head.cur_frame_len = le16_to_cpu(cur_head.cur_frame_len);
	cur_head.nxt_frame_len = le16_to_cpu(cur_head.nxt_frame_len);
	cur_head.checksum = le16_to_cpu(cur_head.checksum);
	if (le16_data_check(buf, sizeof(cur_head))) {
		thp_log_err("frame head checksum erro\n");
		return pre_head.nxt_frame_len;
	}
	if ((cur_head.nxt_frame_len < sizeof(cur_head)) ||
		(cur_head.nxt_frame_len > thp_get_max_frame_size(tdev->thp_core))) {
		thp_log_err("next frame len invalid %d\n",
			cur_head.nxt_frame_len);
		return pre_head.nxt_frame_len;
	}
	pre_head = cur_head;
	return cur_head.nxt_frame_len;
}

static int touch_driver_get_frame(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int ret;
	static int frame_len = DEFAULT_FRAME_LEN;
	bool ic_flag = false;

	if ((tdev == NULL) || (buf == NULL)) {
		thp_log_err("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if (!len) {
		thp_log_err("%s: read len illegal\n", __func__);
		return -ENOMEM;
	}
	ic_flag = ((tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C)) &&
		(tdev->thp_core->support_dual_chip_arch);
	if (ic_flag) {
		ret = touch_driver_spi_read_frame(tdev, g_yuwei_frame_addr[tdev->thp_core->panel_id],
			buf, frame_len);
		frame_len = touch_driver_get_next_frame_len(tdev, buf);
		return ret;
	}
	return touch_driver_spi_read_frame(tdev, g_yuwei_frame_addr[tdev->thp_core->panel_id], buf, len);
}

static int touch_driver_gesture_report(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	int retval;

	thp_log_info("%s: \n", __func__);
	if (!tdev) {
		thp_log_err("%s: input dev null\n", __func__);
		return -EINVAL;
	}
	if (((tdev->thp_core->support_vendor_ic_type == YWT672T)) &&
		(tdev->thp_core->support_dual_chip_arch))
		retval = touch_driver_gesture_event_for_ywt_dual(tdev,
			gesture_wakeup_value);
	else
		retval = touch_driver_gesture_event(tdev, gesture_wakeup_value);
	if (retval != 0) {
		thp_log_err("%s: ->get event failed\n", __func__);
		return -EINVAL;
	}
	return NO_ERR;
}

static int touch_driver_wakeup_gesture_enable_switch(
	struct thp_device *tdev, u8 switch_value)
{
	int retval = NO_ERR;
	int result;
	struct thp_core_data *cd = tdev->thp_core;

	if (switch_value) {
		result = touch_driver_switch_cmd(tdev,
			cd->cmd_gesture_mode, FEATURE_ENABLE);
		if (result)
			thp_log_err("failed enable gesture mode\n");

		retval = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF,
				FEATURE_ENABLE);
		if (result || retval) {
			thp_log_err("failed enable gesture mode\n");
		} else {
			g_work_status[cd->panel_id] |= IC_STATUS_GESTURE;
			thp_log_info("enable gesture mode\n");
		}
	} else {
		retval =  touch_driver_switch_cmd(tdev,
			cd->cmd_gesture_mode, FEATURE_DISABLE);
		if (retval) {
			thp_log_err("failed disable gesture mode\n");
		} else {
			thp_log_info("disable gesture mode\n");
			g_work_status[cd->panel_id] &= ~IC_STATUS_GESTURE;
		}
	}
	thp_log_info("%s: write TP IC\n", __func__);
	return retval;
}

static int touch_driver_wakeup_gesture_enable_switch_ywt(
	struct thp_device *tdev, u8 switch_value)
{
	int retval;
	int result;
	struct thp_core_data *cd = tdev->thp_core;

	if (switch_value) {
		retval = touch_driver_switch_cmd(tdev,
			CMD_SCREEN_ON_OFF_YWT, 1);
		msleep(SEND_GESTURE_CMD_BEFORE_DELAY); /* delay time 20ms */
		result = touch_driver_switch_cmd(tdev,
			cd->cmd_gesture_mode,
			GESTURE_CMD_SWITCH_YWT);
		if (!(result || retval)) {
			g_work_status[cd->panel_id] |= IC_STATUS_GESTURE;
			thp_log_info("enable gesture mode\n");
			return retval;
		}
		thp_log_err("failed enable gesture mode\n");
		return -EINVAL;
	}
	retval = touch_driver_switch_cmd(tdev,
		cd->cmd_gesture_mode, FEATURE_DISABLE);
	if (retval) {
		thp_log_err("failed disable gesture mode\n");
	} else {
		thp_log_info("disable gesture mode\n");
		g_work_status[cd->panel_id] &= ~IC_STATUS_GESTURE;
	}
	return retval;
}

static int touch_driver_wrong_touch(struct thp_device *tdev)
{
	if (!tdev) {
		thp_log_err("%s: input dev is null\n", __func__);
		return -EINVAL;
	}
	if (tdev->thp_core->support_gesture_mode) {
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		tdev->thp_core->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		thp_log_info("%s: ->done\n", __func__);
	}
	return NO_ERR;
}

static int touch_driver_parse_gesture_data(struct thp_device *tdev,
	u8 *gesture_data, int len, unsigned int *gesture_wakeup_value)
{
	u16 gesture_type = 0;

	if (len < GESTURE_EVENT_HEAD_LEN + 1) {
		thp_log_err("%s: gestur data len is invalid len = %d\n",
			__func__, len);
		return -EINVAL;
	}
	gesture_type = (gesture_data[DATA1] << MOVE_8BIT) + gesture_data[DATA2];
	if (gesture_type == GESTURE_TYPE_DOUBLE_TAP) {
		thp_log_info("%s: found valid gesture type\n", __func__);
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		if (tdev->thp_core->easy_wakeup_info.off_motion_on == true) {
			tdev->thp_core->easy_wakeup_info.off_motion_on = false;
			*gesture_wakeup_value = TS_DOUBLE_CLICK;
		}
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		return NO_ERR;
	} else {
		thp_log_err("%s: found invalid gesture type:0x%x\n",
			__func__, gesture_type);
		return -EINVAL;
	}
}

static int touch_driver_check_gesture_data(u8 *gesture_data, int len)
{
	if (len < GESTURE_EVENT_HEAD_LEN + 1) {
		thp_log_err("%s: gestur data len is invalid len = %d\n",
			__func__, len);
		return -EINVAL;
	}
	if (gesture_data[0] != IRQ_EVENT_TYPE_GESTURE) {
		thp_log_err("%s: not gesture irq event, event_type 0x%x\n",
			__func__, gesture_data[0]);
		return -EINVAL;
	}
	if (checksum_16(gesture_data + 1, GESTURE_EVENT_HEAD_LEN)) {
		thp_log_err("gesture data checksum error\n");
		return -EINVAL;
	}
	return NO_ERR;
}

static int touch_driver_read_gesture_data(struct thp_device *tdev,
	u8 *gesture_data, int len)
{
	int i;
	int ret;

	/* wait spi bus resume */
	for (i = 0; i < GESTURE_EVENT_RETRY_TIMES; i++) {
		ret = touch_driver_spi_read(tdev, g_yuwei_frame_addr[tdev->thp_core->panel_id],
			gesture_data, len);
		if (ret == 0)
			break;
		thp_log_err("%s: spi not work normal, ret %d retry\n", __func__, ret);
		msleep(WAIT_FOR_SPI_BUS_READ_DELAY);
	}
	if (ret) {
		thp_log_err("%s: failed read gesture data, ret %d\n", __func__, ret);
		return -EINVAL;
	}
	thp_log_info("gesute_data:%*ph\n", len, gesture_data);

	return ret;
}

/* call this founction when TPIC in gesture mode
 *  return: if get valied gesture type 0 is returened
 */
static int touch_driver_gesture_event(struct thp_device *tdev,
	unsigned int *gesture_wakeup_value)
{
	u8 sync_flag = 0;
	int retval;
	u8 gesture_event_head[GESTURE_EVENT_HEAD_LEN + 1] = { 0 };
	int result;
	struct thp_core_data *cd = tdev->thp_core;

	if (!(g_work_status[cd->panel_id] & IC_STATUS_GESTURE)) {
		thp_log_err("%s: please enable gesture mode first\n", __func__);
		retval = -EINVAL;
		goto err_out;
	}
	msleep(WAIT_FOR_SPI_BUS_RESUMED_DELAY);
	retval = touch_driver_read_gesture_data(tdev,
		gesture_event_head, sizeof(gesture_event_head));
	if (retval) {
		thp_log_err("%s: read gesture data faild\n", __func__);
		goto err_out;
	}
	retval = touch_driver_check_gesture_data(gesture_event_head,
		sizeof(gesture_event_head));
	if (retval) {
		thp_log_err("%s: check gesture data faild\n", __func__);
		goto err_out;
	}
	retval = touch_driver_parse_gesture_data(tdev, gesture_event_head,
		sizeof(gesture_event_head), gesture_wakeup_value);
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, g_yuwei_frame_addr[cd->panel_id], &sync_flag, 1))
		thp_log_err("%s: clean sync flag fail", __func__);
	return retval;
err_out:
	/* clean sync flag */
	if (touch_driver_spi_write(tdev, g_yuwei_frame_addr[cd->panel_id], &sync_flag, 1))
		thp_log_err("%s: clean sync flag fail", __func__);
	/* resend gesture command */
	result = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF,
		FEATURE_ENABLE);
	if (result)
		thp_log_err("resend SCREEN_ON_OFF command\n");
	retval = touch_driver_switch_cmd(tdev,
		cd->cmd_gesture_mode, FEATURE_ENABLE);
	g_work_status[cd->panel_id] |= IC_STATUS_GESTURE;
	if (result || retval)
		thp_log_err("resend gesture command\n");
	else
		thp_log_info("success resend gesture command\n");
	return -EINVAL;
}

static void touch_driver_resend_gesture_cmd_for_ywt_dual(
	struct thp_device *tdev, u8 sync_flag)
{
	int result;
	int retval;
	struct thp_core_data *cd = tdev->thp_core;

	/* clean sync flag */
	if (touch_driver_spi_write(tdev, g_yuwei_touch_addr, &sync_flag, 1))
		thp_log_err("clean sync flag before resend gesture cmd fail\n");
	/* resend gesture command */
	result = touch_driver_switch_cmd(tdev,
		CMD_SCREEN_ON_OFF, FEATURE_ENABLE);
	if (result)
		thp_log_err("resend SCREEN_ON_OFF command\n");
	retval = touch_driver_switch_cmd(tdev,
		cd->cmd_gesture_mode, FEATURE_ENABLE);
	g_work_status[cd->panel_id] |= IC_STATUS_GESTURE;
	if (result || retval)
		thp_log_err("resend gesture command\n");
	else
		thp_log_info("success resend gesture command\n");
}

static int touch_driver_parse_gesture_data_for_ywt_dual(
	struct thp_device *tdev, u16 gesture_type,
	unsigned int *gesture_wakeup_value)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(gesture_info_tab_for_ywt_dual); i++) {
		if (gesture_type == gesture_info_tab_for_ywt_dual[i].gesture_type) {
			thp_log_info("found valid gesture type: 0x%x\n", gesture_type);
			mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
			*gesture_wakeup_value = gesture_info_tab_for_ywt_dual[i].gesture_value;
			mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
			return NO_ERR;
		}
	}
	thp_log_err("found invalid gesture type:0x%x\n", gesture_type);
	return -EINVAL;
}

static u32 checksum32_cmp(u8 *data, int size)
{
	u32 cal_checksum = 0;
	u32 r_checksum;
	int i;

	if (size < GESTURE_DATA_MINI_SIZE_YWT_DUAL) {
		thp_log_err("%s: inval parm\n", __func__);
		return MASK_32BIT;
	}
	for (i = 0; i < size - GESTURE_DATA_MINI_SIZE_YWT_DUAL; i++)
		cal_checksum += data[i];
	r_checksum = data[size - DATA2] + (data[size - DATA1] << MOVE_8BIT);
	return ((cal_checksum & MASK_32BIT) == r_checksum) ? 0 : MASK_32BIT;
}

static int touch_driver_check_gesture_data_for_ywt_dual(
	u8 *gesture_data, int len)
{
	int ret = NO_ERR;

	if (gesture_data[0] != IRQ_EVENT_TYPE_GESTURE_YWT_DUAL) {
		thp_log_err("not gesture irq event, event_type 0x%x\n",
			gesture_data[0]);
		ret = -EINVAL;
	}
	if (checksum32_cmp(gesture_data, len)) {
		thp_log_err("gesture data checksum error\n");
		ret = -EINVAL;
	}
	return ret;
}

static int touch_driver_get_gesture_data_for_ywt_dual(
	struct thp_device *tdev, u8 *gesture_data, unsigned int len)
{
	int ret;
	int i;

	if (tdev->thp_core->support_vendor_ic_type == YWT672T)
		g_yuwei_touch_addr = YUWEI_GESTURE_ADDR_DEFAULT_YWT672T;
	msleep(WAIT_FOR_SPI_BUS_RESUMED_DELAY);
	/* wait spi bus resume */
	for (i = 0; i < GESTURE_EVENT_RETRY_TIMES; i++) {
		ret = touch_driver_spi_read(tdev, g_yuwei_touch_addr,
			gesture_data, len);
		if (!ret)
			break;
		thp_log_err("spi not work normal, ret %d retry\n", ret);
		msleep(WAIT_FOR_SPI_BUS_READ_DELAY);
	}
	return ret;
}

static int touch_driver_gesture_event_for_ywt_dual(
	struct thp_device *tdev, unsigned int *gesture_wakeup_value)
{
	u8 sync_flag = 0;
	int retval;
	u16 gesture_type;
	u8 gesture_event_head[GESTURE_EVENT_HEAD_LEN_YWT_DUAL] = {0};
	bool gesture_enable = false;
	struct thp_core_data *cd = tdev->thp_core;

	gesture_enable = g_work_status[cd->panel_id] & IC_STATUS_GESTURE;
	if (!gesture_enable) {
		thp_log_err("please enable gesture mode first\n");
		retval = -EINVAL;
		goto err_out;
	}
	retval = touch_driver_get_gesture_data_for_ywt_dual(tdev,
		gesture_event_head, sizeof(gesture_event_head));
	if (retval) {
		thp_log_err("failed read gesture head info, ret %d\n", retval);
		return -EINVAL;
	}
	thp_log_info("gesture_data:%*ph\n", (u32)sizeof(gesture_event_head),
		gesture_event_head);
	retval = touch_driver_check_gesture_data_for_ywt_dual(
		gesture_event_head, GESTURE_EVENT_HEAD_LEN_YWT_DUAL);
	if (retval) {
		thp_log_err("check gesture data failed\n");
		retval = -EINVAL;
		goto err_out;
	}
	gesture_type = gesture_event_head[GESTURE_TYPE_VALUE_YWT_DUAL];
	retval = touch_driver_parse_gesture_data_for_ywt_dual(tdev,
		gesture_type, gesture_wakeup_value);
		/* clean sync flag */
	if (touch_driver_spi_write(tdev, g_yuwei_touch_addr, &sync_flag, 1))
		thp_log_err("clean sync flag fail\n");
	return retval;
err_out:
	touch_driver_resend_gesture_cmd_for_ywt_dual(tdev, sync_flag);
	return -EINVAL;
}

static int touch_driver_resume_ap(struct thp_device *tdev)
{
	thp_log_info("%s: enter\n", __func__);

	if (tdev->thp_core->use_ap_gesture ||
		tdev->thp_core->double_click_use_ap_gesture) {
		/* need disable irq before reset tp ic */
		thp_set_irq_status(tdev->thp_core, THP_IRQ_DISABLE);
		thp_log_info("%s: disable irq, wait afehal init ok\n", __func__);
	}
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	mdelay(tdev->timing_config.resume_reset_after_delay_ms);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
	thp_log_info("%s: out\n", __func__);
	return NO_ERR;
}

#ifdef CONFIG_HUAWEI_SHB_THP
#define NEED_RESET 1
static int touch_driver_resume_shb(struct thp_device *tdev)
{
	int ret = NO_ERR;

	if ((!tdev) || (!tdev->thp_core) || (!tdev->gpios)) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	if (tdev->thp_core->need_resume_reset == NEED_RESET) {
		gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
		mdelay(tdev->timing_config.resume_reset_after_delay_ms);
		gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
		thp_log_info("%s: reset when resume\n", __func__);
		return NO_ERR;
	}
	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_YWT,
			CMD_SWITCH_INT_AP);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_AP);
	if (ret) {
		thp_log_err("%s: touch_driver_switch_cmd send err, ret = %d\n",
			__func__, ret);
		return ret;
	}
	thp_log_info("%s: touch_driver_switch_cmd send: switch int ap\n", __func__);
	return ret;
}
#endif

static int touch_driver_resume_gesture(struct thp_device *tdev)
{
	int ret = NO_ERR;

	thp_log_info("%s: gesture or fingerprint mode\n", __func__);
	if (tdev->thp_core->gesture_from_sensorhub) {
#ifdef CONFIG_HUAWEI_SHB_THP
		ret = send_thp_driver_status_cmd(POWER_ON,
			tdev->thp_core->multi_panel_index,
			ST_CMD_TYPE_MULTI_TP_UD_STATUS);
#endif
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->pins_default);
		thp_log_info("%s: call sensorhub gestrue disable\n", __func__);
	}
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	mdelay(tdev->timing_config.resume_reset_after_delay_ms);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_HIGH);
	if (tdev->thp_core->gesture_from_sensorhub)
		thp_set_irq_status(tdev->thp_core, THP_IRQ_ENABLE);
	return ret;
}

static int touch_driver_resume(struct thp_device *tdev)
{
	int ret = NO_ERR;
	struct thp_core_data *cd = tdev->thp_core;
	bool resume_flag;

	thp_log_info("%s: ic_type %d\n", __func__,
		cd->support_vendor_ic_type);
	pen_clk_control(CLK_ENABLE, cd->panel_id);
	/* if pt mode, we should reset */
	if (is_pt_test_mode(tdev)) {
		ret = touch_driver_resume_ap(tdev);
		thp_log_info("%s: pt mode called end\n", __func__);
		return ret;
	}
	if (cd->sensorhub_support_gesture) {
		if (g_power_off_staus[cd->panel_id] == WORK_IN_SUSPEND)
			return touch_driver_resume_gesture(tdev);
		else
			return touch_driver_power_on_for_ywt(tdev);
	}
	resume_flag = (cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) ||
		g_thp_udfp_status[cd->panel_id] || g_yuwei_stylus_status[cd->panel_id] ||
		g_aod_touch_status[cd->panel_id] || g_yuwei_ring_setting_switch[cd->panel_id] ||
		cd->power_cfg.power_supply_mode;
	if (resume_flag) {
#ifdef CONFIG_HUAWEI_SHB_THP
		if (cd->support_shb_thp)
			ret = touch_driver_resume_shb(tdev);
		else
#endif
			ret = touch_driver_resume_ap(tdev);
		thp_log_info("%s: called end\n", __func__);
		return ret;
	}
	ret = touch_driver_power_on_for_ictype(tdev);
	thp_log_info("%s: called end\n", __func__);
	return ret;
}

static int touch_driver_after_resume(struct thp_device *tdev)
{
	int ret = NO_ERR;
	struct thp_core_data *cd = tdev->thp_core;

	thp_log_info("%s: called\n", __func__);
	thp_do_time_delay(tdev->timing_config.boot_reset_after_delay_ms);
	if (!g_thp_udfp_status[cd->panel_id] && !is_pt_test_mode(tdev)) {
		/* Turn off sensorhub report when
		 * fingerprintud  isn't in work state.
		 */
		ret = touch_driver_switch_cmd(tdev, CMD_TOUCH_REPORT, 0);
		if (ret)
			thp_log_err("failed send CMD_TOUCH_REPORT mode\n");
	}
	return ret;
}

static int send_stylus3_status_to_fw(struct thp_device *tdev,
	u8 *bt_status_buf, u8 check_status_data)
{
	int i;
	int ret;
	int connect_addr;
	int connect_check_addr;
	u8 check_value;

	thp_log_info("check_status_data = %d\n", check_status_data);
	if (tdev->thp_core->support_vendor_ic_type == YWT672T) {
		connect_addr = YUWEI_CMD_ADDR_DEFAULT_YWT672T;
		connect_check_addr = BT_CONNECT_STATUS_CHECK_ADDR_YWT672T;
	} else {
		connect_addr = BT_CONNECT_STATUS_ADDR;
		connect_check_addr = BT_CONNECT_STATUS_CHECK_ADDR;
	}
	for (i = 0; i < BT_CONNECT_CMD_RETRY; i++) {
		ret = touch_driver_spi_write(tdev, connect_addr,
			bt_status_buf, BT_CONNECT_STATUS_BUF_LEN);
		if (ret)
			continue;
		msleep(BT_AFTER_WRITE_CMD_DELAY);

		ret = touch_driver_spi_read(tdev, connect_check_addr,
			&check_value, BT_CHECK_DATA_LEN);
		if (ret)
			continue;

		if (check_status_data == check_value)
			break;
	}
	if (i == BT_CONNECT_CMD_RETRY)
		ret = -EINVAL;
	return ret;
}

static bool touch_driver_get_stylus3_adsorption_status(struct thp_device *tdev)
{
	int stylus3_bt_status;
	int stylus_adsorption_status;
	bool cur_stylus3_status;

	stylus3_bt_status = atomic_read(&tdev->thp_core->last_stylus3_status);
	stylus_adsorption_status =
		atomic_read(&tdev->thp_core->last_stylus_adsorption_status);
	thp_log_info("%s: stylus3_bt_status = %d, stylus_adsorption_status = %d\n",
		__func__, stylus3_bt_status, stylus_adsorption_status);
	cur_stylus3_status = ((stylus3_bt_status == BT_STYLUS3_CONNECTED_MASK) &&
		(stylus_adsorption_status == STYLUS3_ADSORPTION_MASK));
	return cur_stylus3_status;
}

static bool touch_driver_get_stylus3_status(struct thp_device *tdev)
{
	int stylus3_bt_status;
	int stylus_adsorption_status;
	int current_stylus3_work_mode;
	int current_app_dsi_status;
	bool cur_stylus3_status;

	stylus3_bt_status = atomic_read(&tdev->thp_core->last_stylus3_status);
	stylus_adsorption_status =
		atomic_read(&tdev->thp_core->last_stylus_adsorption_status);
	current_stylus3_work_mode =
		atomic_read(&tdev->thp_core->last_stylus3_work_mode);
	current_app_dsi_status =
		atomic_read(&tdev->thp_core->app_dsi_status);
	thp_log_info("%s: stylus3_bt_status = %d, stylus_adsorption_status = %d\n",
		__func__, stylus3_bt_status, stylus_adsorption_status);
	thp_log_info("%s: current_stylus3_work_mode = %d, current_app_dsi_status = %d\n",
		__func__, current_stylus3_work_mode, current_app_dsi_status);
	cur_stylus3_status = ((stylus3_bt_status == BT_STYLUS3_CONNECTED_MASK) &&
		(stylus_adsorption_status != STYLUS3_ADSORPTION_MASK) &&
		(current_stylus3_work_mode == 0) && (current_app_dsi_status == 0));
	return cur_stylus3_status;
}

static void touch_driver_set_stylus3_link_info(struct thp_device *tdev,
	bool delay_enable, bool link_enable, u8 **connect_cmd, u8 *connect_value)
{
	bool stylus_adsorption_status;

	stylus_adsorption_status = touch_driver_get_stylus3_adsorption_status(tdev);
	if (delay_enable)
		msleep(SEND_BT_CONNECT_STATUS_AFTER_RESET_DELAY);
	if (link_enable) {
		*connect_cmd = bt_connect_buf;
		*connect_value = BT_CONNECT_VALUE;
	} else if (stylus_adsorption_status) {
		*connect_cmd = bt_adsorption_buf;
		*connect_value = BT_ADSORPTION_VALUE;
	} else {
		*connect_cmd = bt_disconnect_buf;
		*connect_value = BT_DISCONNECT_VALUE;
	}
	thp_log_info("%s: stylus3 connect_value = %d\n", __func__, *connect_value);
}

static int touch_driver_ai_bt_handler(struct thp_device *tdev,
	bool delay_enable)
{
	int ret;
	u8 bt_connect_value = 0;
	u8 *bt_status_buf_addr = NULL;
	bool scan_status;

	scan_status = touch_driver_get_stylus3_status(tdev);
	touch_driver_set_stylus3_link_info(tdev, delay_enable, scan_status,
		&bt_status_buf_addr, &bt_connect_value);
	ret = send_stylus3_status_to_fw(tdev,
		bt_status_buf_addr, bt_connect_value);
	if (ret) {
		thp_log_err("%s: send stylus3 status to fw fail\n", __func__);
		return ret;
	}
	thp_log_info("%s: send stylus3 status to fw succ\n", __func__);
	return ret;
}

static int touch_driver_9x_bt_handler(struct thp_device *tdev,
	bool delay_enable)
{
	int ret;
	int stylus3_status = 0;
	u8 bt_connect_value = 0;
	u8 *bt_status_buf_addr = NULL;
	bool tp_is_power_off = false;
	bool scan_status = false;

	tp_is_power_off = tdev->thp_core->suspended &&
		(tdev->thp_core->easy_wakeup_info.sleep_mode == TS_POWER_OFF_MODE);
	if (tp_is_power_off) {
		thp_log_info("tp is power off , do not need send bt status to fw\n");
		return NO_ERR;
	}
	if (tdev->thp_core->support_vendor_ic_type == YWT672T)
		return touch_driver_ai_bt_handler(tdev, delay_enable);
	stylus3_status = atomic_read(&tdev->thp_core->last_stylus3_status);
	scan_status = (stylus3_status > 0) ? true : false;
	touch_driver_set_stylus3_link_info(tdev, delay_enable, scan_status,
		&bt_status_buf_addr, &bt_connect_value);
	ret = send_stylus3_status_to_fw(tdev,
		bt_status_buf_addr, bt_connect_value);
	if (ret) {
		thp_log_err("%s: send stylus3 status to fw fail\n", __func__);
		return ret;
	}
	thp_log_info("%s: send stylus3 status to fw succ\n", __func__);
	return ret;
}

static int touch_driver_suspend_ap(struct thp_device *tdev)
{
	int ret;
	struct thp_core_data *cd = tdev->thp_core;

	if (((cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT650C)) &&
		cd->gesture_mode_double_tap) {
		thp_log_info("%s: send screen on off cmd\n", __func__);
		ret = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF_YWT, 1);
	} else {
		ret = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF, 1);
	}
	if (ret)
		thp_log_err("failed to screen_on off\n");
#if (defined(CONFIG_HUAWEI_THP_MTK) || defined(CONFIG_HUAWEI_THP_QCOM))
	if (cd->use_ap_gesture) {
		ret = touch_driver_set_ap_state(tdev);
		if (ret)
			thp_log_err("failed to set ap state\n");
#ifdef CONFIG_HUAWEI_THP_QCOM
		thp_log_info("%s: resend screen on off cmd\n", __func__);
		ret = touch_driver_switch_cmd(tdev, CMD_SCREEN_ON_OFF_YWT, 1);
#endif
		return ret;
	}
#endif
	if (cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) {
		thp_log_info("%s: TS_GESTURE_MODE\n", __func__);
		if (((cd->support_vendor_ic_type == YWT680T) ||
			(cd->support_vendor_ic_type == YWT650C)) &&
			cd->gesture_mode_double_tap)
			ret = touch_driver_wakeup_gesture_enable_switch_ywt(tdev, FEATURE_ENABLE);
		else
			ret = touch_driver_wakeup_gesture_enable_switch(tdev, FEATURE_ENABLE);
		if (ret)
			thp_log_err("failed to wakeup gesture enable\n");
		mutex_lock(&cd->thp_wrong_touch_lock);
		cd->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&cd->thp_wrong_touch_lock);
	}
#ifdef CONFIG_HUAWEI_SHB_THP
	if (cd->tsa_event_to_udfp && g_thp_udfp_status[cd->panel_id]) {
		mdelay(SEND_TP_AP_EVENT_BEFORE_DELAY);
		ret = send_tp_ap_event(sizeof(g_thp_udfp_status[cd->panel_id]),
			(void *)&g_thp_udfp_status[cd->panel_id],
			ST_CMD_TYPE_FINGERPRINT_SWITCH);
	}
#endif
	return ret;
}

#ifdef CONFIG_HUAWEI_SHB_THP
/* use kit in sensorhub, sensorhub push-down */
static int touch_driver_suspend_shb_thp_2(struct thp_device *tdev)
{
	int ret;

	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_YWT,
			CMD_SWITCH_INT_SH);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_SH);
	if (ret) {
		thp_log_err("%s: touch_driver_switch_cmd send err, ret = %d\n",
			__func__, ret);
		return ret;
	}
	thp_log_info("%s: touch_driver_switch_cmd send: switch int shb\n",__func__);
	return ret;
}

/* use kit in sensorhub, sensorhub no push-down */
static int touch_driver_suspend_shb_thp_1(struct thp_device *tdev)
{
	int ret = NO_ERR;

	if (!tdev) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	thp_log_info("%s: enter\n", __func__);
	if (tdev->thp_core->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) {
		ret = touch_driver_switch_cmd(tdev, CMD_GESTURE_MODE_YWT,
			CMD_GESTURE_DOUBLE);
		if (ret)
			thp_log_err("failed to set_double_click_gesture\n");
	}
	ret = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_YWT,
		CMD_SWITCH_INT_SH);
	if (ret)
		thp_log_err("failed to set_touch_gesture\n");
	touch_driver_clear_irq(tdev);
	thp_log_info("%s: out\n", __func__);
	return ret;
}

#define INPUTHUB_POWER_SWITCH_START_BIT 9
#define INPUTHUB_POWER_SWITCH_START_OFFSET 1
static void touch_driver_poweroff_status(struct thp_device *tdev)
{
	struct thp_core_data *cd = thp_get_core_data(tdev->thp_core->panel_id);

	cd->poweroff_function_status =
		((cd->double_click_switch << THP_DOUBLE_CLICK_ON) |
		(g_thp_udfp_status[cd->panel_id] << THP_TPUD_ON) |
		(cd->ring_setting_switch << THP_RING_SUPPORT) |
		(cd->ring_switch << THP_RING_ON) |
		(g_yuwei_stylus_status[cd->panel_id] << THP_PEN_MODE_ON) |
		(cd->phone_status << THP_PHONE_STATUS) |
		(cd->single_click_switch << THP_SINGLE_CLICK_ON) |
		(cd->volume_side_status << THP_VOLUME_SIDE_STATUS_LEFT));
	if (cd->aod_display_support)
		cd->poweroff_function_status |=
		(cd->aod_touch_status << THP_AOD_TOUCH_STATUS);
	if ((cd->power_switch >= POWER_KEY_OFF_CTRL) &&
		(cd->power_switch < POWER_MAX_STATUS))
	/*
	 * cd->poweroff_function_status 0~8 bit saved function flag
	 * eg:double_click, finger_status, ring_switch,and so on.
	 * cd->poweroff_function_status 9~16 bit saved screen-on-off reason flag
	 * cd->power_switch is a value(1~8) which stand for screen-on-off reason
	 */
		cd->poweroff_function_status |=
			(1 << (INPUTHUB_POWER_SWITCH_START_BIT +
			cd->power_switch - INPUTHUB_POWER_SWITCH_START_OFFSET));
}
#endif

static u32 touch_driver_append_checksum(u8 *data, int len)
{
	u32 checksum;
	int i;

	checksum = 0;
	for (i = 0; i < len; i++)
		checksum += data[i];
	data[len] = checksum & 0xff;
	data[len + 1] = (checksum >> MOVE_8BIT) & 0xff;
	return 0xFFFF & checksum;
}

static int touch_driver_send_cmd(struct thp_device *tdev, unsigned char cmd,
	u8 *data)
{
	int ret;
	int i;
	int retry = 0;
	struct yuwei_cmd cmd_send;
	struct yuwei_cmd cmd_ack;

	memset_s(&cmd_send, sizeof(cmd_send), 0, sizeof(cmd_send));
	memset_s(&cmd_ack, sizeof(cmd_ack), 0, sizeof(cmd_ack));
	cmd_send.cmd = cmd;
	cmd_send.len = SEND_CMD_LEN;
	cmd_send.data[DATA0] = data[DATA0];
	cmd_send.data[DATA1] = data[DATA1];
	touch_driver_append_checksum(&(cmd_send.buf[DATA2]), cmd_send.len - SEND_CMD_OFFSET_LEN);
	while (retry++ < WRITE_CMD_TIMES) {
		thp_log_info("%s: send cmd: %*ph\n", __func__,
			sizeof(cmd_send), cmd_send.buf);
		ret = touch_driver_spi_write(tdev, REG_INT_CMD,
			cmd_send.buf, sizeof(cmd_send));
		if (ret < 0) {
			thp_log_err("%s: failed send command, ret %d\n",
				__func__, ret);
			return -EINVAL;
		}
		for (i = 0; i < READ_CMD_TIMES; i++) {
			mdelay(READ_CMD_ACK_BEFORE_DELAY); /* delay 5ms before read ack */
			ret = touch_driver_spi_read(tdev, REG_INT_CMD,
				cmd_ack.buf, sizeof(cmd_ack));
			thp_log_info("%s: ack: %*ph\n", __func__,
				sizeof(cmd_ack), cmd_ack.buf);
			if (ret < 0) {
				thp_log_err("failed read command ack, %d\n", ret);
				goto exit;
			}
			if (cmd_ack.ack != CMD_ACK_OK)
				ret = -EINVAL;
			else
				goto exit;
		}
	}
exit:
	return ret;
}

#ifdef CONFIG_HUAWEI_SHB_THP
static void touch_driver_suspend_gesture_for_dual_shb_1(struct thp_device *tdev)
{
	int ret = NO_ERR;
	struct thp_core_data *cd = NULL;

	cd = tdev->thp_core;
	if (cd->sensorhub_support_gesture == SENSORHUB_SUPPORT_GESTURE) {
		ret = touch_driver_suspend_shb_thp_1(tdev);
		thp_log_info("%s: ret is %d\n", __func__, ret);
	}
}
#endif

static int touch_driver_suspend_gesture(struct thp_device *tdev)
{
	int ret = NO_ERR;
	struct thp_core_data *cd = NULL;
	u8 data[GESTURE_DATA_LEN] = { 0 };

	if ((tdev == NULL) || (tdev->thp_core == NULL)) {
		thp_log_err("%s: invalid input\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	if (cd->disable_frame_report) {
		thp_log_info("%s: disable frame report\n", __func__);
		ret = touch_driver_send_cmd(tdev, YUWEI_CMD_RAWDATA, data);
		thp_log_info("%s: ret is %d\n", __func__, ret);
		if (ret)
			thp_log_err("disable frame report failed\n");
		mdelay(DISABLE_FRAME_WAIT_DELAY);
	}
	thp_log_info("%s: enter gesture mode,aod:%d,gesture:%d\n",
		__func__, cd->easy_wakeup_info.aod_mode, cd->easy_wakeup_info.sleep_mode);
	thp_log_info("%s: aod_touch_status:%u\n", __func__, g_aod_touch_status[cd->panel_id]);
	if (cd->sensorhub_support_gesture == 1) {
		if ((!cd->easy_wakeup_info.aod_mode) &&
			!(g_aod_touch_status[cd->panel_id] && (cd->multi_panel_index == SINGLE_TOUCH_PANEL)))
			data[1] = DISABLE_SINGLE_CLICK;
		if (!cd->easy_wakeup_info.sleep_mode)
			data[0] = DISABLE_DOUBLE_CLICK;
		ret = touch_driver_send_cmd(tdev, YUWEI_CMD_GESTURE_MODE, data);
		thp_log_info("%s: ret is %d\n", __func__, ret);
	}
#ifdef CONFIG_HUAWEI_SHB_THP
	touch_driver_suspend_gesture_for_dual_shb_1(tdev);
#endif
#ifndef CONFIG_HUAWEI_THP_MTK
	if (tdev->thp_core->gesture_from_sensorhub) {
		thp_set_irq_status(tdev->thp_core, THP_IRQ_DISABLE);
#ifdef CONFIG_HUAWEI_SHB_THP
		pinctrl_select_state(tdev->thp_core->pctrl,
			tdev->thp_core->pins_idle);
		ret = send_thp_driver_status_cmd(POWER_OFF,
			tdev->thp_core->multi_panel_index,
			ST_CMD_TYPE_MULTI_TP_UD_STATUS);
#endif
		thp_log_info("ts call sensorhub gestrue enable\n");
		}
#endif
	if (ret)
		thp_log_err("ts suspend failed\n");
	return ret;
}

static int touch_driver_suspend_pt_mode(struct thp_device *tdev)
{
	int ret;

	thp_log_info("%s: suspend PT mode\n", __func__);
	if ((tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		ret = touch_driver_switch_cmd(tdev, CMD_PT_MODE_YWT, PT_MODE);
	else
		ret = touch_driver_switch_cmd(tdev, CMD_PT_MODE, PT_MODE);
	if (ret)
		thp_log_err("failed enable PT mode\n");
	return ret;
}

static int touch_driver_suspend_guesture_mode(struct thp_device *tdev)
{
	int ret = NO_ERR;

	if (tdev->thp_core->support_shb_thp) {
#ifdef CONFIG_HUAWEI_SHB_THP
		touch_driver_poweroff_status(tdev);
		ret = touch_driver_suspend_shb_thp_2(tdev);
#endif
	} else {
		if (tdev->thp_core->tsa_event_to_udfp == TAS_EVENT_TO_UDFP_MODE_TWO) {
#ifdef CONFIG_HUAWEI_SHB_THP
			ret = touch_driver_suspend_shb_thp_1(tdev);
#endif
		} else {
			ret = touch_driver_suspend_ap(tdev);
		}
	}
	return ret;
}

static int touch_driver_suspend_poweroff_mode(struct thp_device *tdev)
{
	int ret = NO_ERR;

	if (tdev->thp_core->support_shb_thp)
		/* 0:all function was closed */
		tdev->thp_core->poweroff_function_status = 0;
	g_power_off_staus[tdev->thp_core->panel_id] = POWER_OFF_IN_SUSPEND;
	if (tdev->thp_core->power_cfg.power_supply_mode)
		ret = touch_driver_suspend_pt_mode(tdev);
	else
		ret = touch_driver_power_off(tdev);
	thp_log_info("enter poweroff mode: ret = %d\n", ret);
	return ret;
}

static int touch_driver_suspend(struct thp_device *tdev)
{
	int ret = NO_ERR;
	unsigned int gesture_status;
	struct thp_core_data *cd = NULL;

	if ((tdev == NULL) || (tdev->thp_core == NULL)) {
		thp_log_err("%s: invalid input\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	g_thp_udfp_status[cd->panel_id] = cd->suspend_udfp_status;
	g_yuwei_stylus_status[cd->panel_id] = !!(thp_get_status(THP_STATUS_STYLUS, cd->panel_id)) |
		(cd->suspend_stylus3_status & (cd->support_quick_note ? cd->quick_note : 1));
	g_aod_touch_status[cd->panel_id] = cd->aod_touch_status;
	if ((cd->support_vendor_ic_type == YWT672T) &&
		(cd->support_dual_chip_arch) &&
		(cd->easy_wakeup_info.sleep_mode == TS_POWER_OFF_MODE))
		g_yuwei_stylus_status[cd->panel_id] = FEATURE_DISABLE;
	g_yuwei_ring_setting_switch[cd->panel_id] = cd->ring_setting_switch;
	thp_log_info("%s:gesture_status:%d,finger_status:%u\n",
		__func__, cd->easy_wakeup_info.sleep_mode, g_thp_udfp_status[cd->panel_id]);
	thp_log_info(
		"%s:ring_support:%u,ring_switch:%u,phone_status:%u,ring_setting_switch:%u\n",
		__func__, cd->support_ring_feature, cd->ring_switch,
		cd->phone_status, g_yuwei_ring_setting_switch[cd->panel_id]);
	thp_log_info("%s:stylus_status:%u,aod_touch_status:%u\n", __func__,
		g_yuwei_stylus_status[cd->panel_id], cd->aod_touch_status);
	gesture_status = cd->sensorhub_support_gesture &&
		((tdev->thp_core->easy_wakeup_info.aod_mode) ||
		(tdev->thp_core->easy_wakeup_info.sleep_mode) ||
		(g_aod_touch_status[cd->panel_id] && (cd->multi_panel_index == SINGLE_TOUCH_PANEL)));
	if (gesture_status) {
		g_power_off_staus[cd->panel_id] = WORK_IN_SUSPEND;
		return touch_driver_suspend_gesture(tdev);
	}
	if (is_pt_test_mode(tdev))
		ret = touch_driver_suspend_pt_mode(tdev);
	else if (g_thp_udfp_status[cd->panel_id] || g_yuwei_ring_setting_switch[cd->panel_id] ||
		(cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) ||
		g_yuwei_stylus_status[cd->panel_id] || cd->aod_touch_status)
		ret = touch_driver_suspend_guesture_mode(tdev);
	else
		ret = touch_driver_suspend_poweroff_mode(tdev);
	mdelay(tdev->timing_config.before_pen_clk_disable_delay_ms);
	pen_clk_control(CLK_DISABLE, cd->panel_id);
	thp_log_info("%s: called end\n", __func__);
	return ret;
}

static void touch_driver_get_oem_info(struct thp_device *tdev,
	const char *buff)
{
	struct thp_core_data *cd = NULL;
	char lcd_effect_flag;
	int ret;
	bool flag;

	flag = (!tdev) || (!buff) || (!tdev->thp_core);
	if (flag) {
		thp_log_err("%s: tdev null\n", __func__);
		return;
	}
	cd = tdev->thp_core;
	if (tdev->thp_core->support_oem_info == THP_OEM_INFO_LCD_EFFECT_TYPE) {
		/* The 12th byte is lcd_effect_flag, and 0xaa is valid */
		lcd_effect_flag = buff[YUWEI_LCD_EFFECT_FLAG_POSITION - 1];
		memset_s(cd->oem_info_data, sizeof(cd->oem_info_data), 0, sizeof(cd->oem_info_data));
		ret = snprintf_s(cd->oem_info_data, OEM_INFO_DATA_LENGTH,
			OEM_INFO_DATA_LENGTH - 1, "0x%x", lcd_effect_flag);
		if (ret < 0)
			thp_log_err("%s:snprintf error\n", __func__);
		thp_log_info("%s:lcd effect flag :%s\n", __func__,
			cd->oem_info_data);
		return;
	}
	thp_log_info("%s:not support oem info\n", __func__);
}

static bool touch_driver_is_valid_project_id(const char *id)
{
	int i;

	if (id == NULL)
		return false;
	for (i = 0; i < THP_PROJECT_ID_LEN; i++) {
		if (!isascii(*id) || !isalnum(*id))
			return false;
		id++;
	}
	return true;
}

static int touch_driver_get_project_id_for_ywt(struct thp_device *tdev,
	unsigned int addr, char *buf, unsigned int len)
{
	char proj_id[THP_PROJECT_ID_LEN + 1] = {0};
	int ret;
	struct thp_core_data *cd = NULL;

	cd = tdev->thp_core;
	ret = touch_driver_spi_read(tdev, addr, proj_id, THP_PROJECT_ID_LEN);
	if (ret)
		thp_log_err("%s:Project_id Read ERR\n", __func__);
	proj_id[THP_PROJECT_ID_LEN] = '\0';
	thp_log_info("PROJECT_ID[0-9] %*ph\n", THP_PROJECT_ID_LEN, proj_id);
	if (touch_driver_is_valid_project_id(proj_id)) {
		strncpy_s(buf, len + 1, proj_id, len);
	} else {
		thp_log_err("%s:get project id fail\n", __func__);
		if (cd->project_id_dummy) {
			thp_log_err("%s:use dummy prj id\n", __func__);
			strncpy_s(buf, len + 1, cd->project_id_dummy, len);
			return NO_ERR;
		}
		return -EIO;
	}
	thp_log_info("%s call end\n", __func__);
	return NO_ERR;
}

static int touch_driver_get_project_id(struct thp_device *tdev,
	char *buf, unsigned int len)
{
	int retry;
	char proj_id[YUWEI_CUSTOME_INFO_LEN + 1] = { 0 };
	int ret = NO_ERR;
	struct thp_core_data *cd = NULL;

	if ((tdev == NULL) || (buf == NULL)) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;
	if ((cd->support_vendor_ic_type == YWT680T) ||
		(cd->support_vendor_ic_type == YWT672T) ||
		(cd->support_vendor_ic_type == YWT650C))
		return touch_driver_get_project_id_for_ywt(tdev,
			YUWEI_PROJECT_ID_ADDR_YWT672T, buf, len);
	for (retry = 0; retry < YUWEI_GET_PROJECT_ID_RETRY_TIMES; retry++) {
		ret = touch_driver_spi_read(tdev, YUWEI_PROJECT_ID_ADDR_DEFAULT,
			proj_id, YUWEI_CUSTOME_INFO_LEN);
		if (ret) {
			thp_log_err("Project_id Read ERR\n");
			return -EIO;
		}
		if (!checksum_u8(proj_id, YUWEI_CUSTOME_INFO_LEN)) {
			proj_id[THP_PROJECT_ID_LEN] = '\0';
			if (!is_valid_project_id(proj_id)) {
				thp_log_err("get project id fail\n");
				return -EIO;
			}
			strncpy_s(buf, len + 1, proj_id, len);
			thp_log_info("%s:get project id:%s\n", __func__, buf);
			touch_driver_get_oem_info(tdev, proj_id);
			return NO_ERR;
		}
		thp_log_err("proj_id[0-30] %*ph\n", YUWEI_CUSTOME_INFO_LEN, proj_id);
		thp_log_err("%s:get project id fail, retry\n", __func__);
		mdelay(YUWEI_GET_PROJECT_RETRY_DELAY_10MS);
	}
	return -EIO;
}

static void touch_driver_exit(struct thp_device *tdev)
{
	struct thp_core_data *cd = tdev->thp_core;

	thp_log_info("%s: called\n", __func__);
	kfree(tdev->tx_buff);
	kfree(tdev->rx_buff);
	kfree(tdev);
	kfree(tx_frame_buff[cd->panel_id]);
	tx_frame_buff[cd->panel_id] = NULL;
	kfree(rx_frame_buff[cd->panel_id]);
	rx_frame_buff[cd->panel_id] = NULL;
	kfree(g_yuwei_spi_tx_buf[cd->panel_id]);
	g_yuwei_spi_tx_buf[cd->panel_id] = NULL;
}

static int touch_driver_afe_notify_callback(struct thp_device *tdev,
	unsigned long event)
{
	if (tdev == NULL) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}
	return touch_driver_get_afe_info(tdev);
}

int touch_driver_spi_active(struct thp_device *tdev)
{
	int ret;
	u8 wake_flag = IDLE_WAKE_FLAG;

	ret = thp_set_spi_max_speed(IDLE_SPI_SPEED, tdev->thp_core->panel_id);
	if (ret) {
		thp_log_err("failed set spi speed to %dHz, ret %d\n",
			IDLE_SPI_SPEED, ret);
		return ret;
	}
	ret = touch_driver_spi_write(tdev, 0, &wake_flag, sizeof(wake_flag));
	if (ret)
		thp_log_err("failed write wakeup flag %x, ret %d",
			wake_flag, ret);
	thp_log_info("[%s] tdev->sdev->max_speed_hz-> %d\n", __func__,
		tdev->sdev->max_speed_hz);
	ret = thp_set_spi_max_speed(ACTIVE_SPI_SPEED, tdev->thp_core->panel_id);
	if (ret) {
		thp_log_err("failed reset speed to %dHz, ret %d\n",
			tdev->sdev->max_speed_hz, ret);
		return ret;
	}
	udelay(YUWEI_SPI_ACTIVE_DELAY);
	return ret;
}

static int touch_driver_idle_wakeup(struct thp_device *tdev)
{
	int ret;
	int i;
	u8 fw_status_data[MAX_FW_STATUS_DATA_LEN] = { 0 };

	thp_log_debug("%s\n", __func__);
	if (!g_yuwei_fw_status_addr || !g_yuwei_fw_status_len ||
		g_yuwei_fw_status_len > MAX_FW_STATUS_DATA_LEN) {
		thp_log_err("%s: invalid fw status reg, length: %d\n",
			__func__, g_yuwei_fw_status_len);
		return NO_ERR;
	}
	ret = touch_driver_spi_read(tdev, g_yuwei_fw_status_addr,
		fw_status_data, g_yuwei_fw_status_len);
	if (ret) {
		thp_log_err("failed read fw status info data, ret %d\n", ret);
		return -EIO;
	}
	if (!checksum_16(fw_status_data, g_yuwei_fw_status_len) &&
		!(fw_status_data[0] & FW_STAUTE_DATA_MASK) &&
		(fw_status_data[g_yuwei_fw_status_len - FW_STAUTE_DATA_FLAG_OFFSET] ==
			FW_STAUTE_DATA_FLAG))
		return NO_ERR;
	thp_log_debug("fw status data:%*ph\n", g_yuwei_fw_status_len, fw_status_data);
	thp_log_debug("need do spi wakeup\n");
	for (i = 0; i < SPI_WAKEUP_RETRY; i++) {
		ret = touch_driver_spi_active(tdev);
		if (ret) {
			thp_log_debug("failed write spi active flag, ret %d\n", ret);
			continue;
		}
		/* recheck spi state */
		ret = touch_driver_spi_read(tdev, g_yuwei_fw_status_addr,
			fw_status_data, g_yuwei_fw_status_len);
		if (ret) {
			thp_log_err("[recheck]failed read fw status info data, ret %d\n", ret);
			continue;
		}
		if (!checksum_16(fw_status_data, g_yuwei_fw_status_len) &&
			!(fw_status_data[0] & FW_STAUTE_DATA_MASK) &&
			(fw_status_data[g_yuwei_fw_status_len - FW_STAUTE_DATA_FLAG_OFFSET] ==
				FW_STAUTE_DATA_FLAG))
			return NO_ERR;
		thp_log_debug("fw status data:%*ph\n", g_yuwei_fw_status_len,
			fw_status_data);
		thp_log_debug("failed wakeup form idle retry %d\n", i);
	}
	return -EIO;
}

#ifdef CONFIG_HUAWEI_SHB_THP
static int touch_driver_switch_int_sh(struct thp_device *tdev)
{
	int retval;

	thp_log_info("%s: called\n", __func__);
	if (tdev->thp_core->use_ap_sh_common_int && tdev->thp_core->support_pinctrl)
		thp_pinctrl_select_lowpower(tdev->thp_core->thp_dev);
	if ((tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_YWT,
			CMD_SWITCH_INT_SH);
	else
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_SH);
	if (retval != 0) {
		thp_log_err("%s: switch int to shb failed\n", __func__);
		return -EINVAL;
	}
	return NO_ERR;
}

static int touch_driver_switch_int_ap(struct thp_device *tdev)
{
	int retval;

	thp_log_info("%s: called\n", __func__);
	if (tdev->thp_core->use_ap_sh_common_int && tdev->thp_core->support_pinctrl)
		thp_pinctrl_select_normal(tdev->thp_core->thp_dev);
	if ((tdev->thp_core->support_vendor_ic_type == YWT672T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT680T) ||
		(tdev->thp_core->support_vendor_ic_type == YWT650C))
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN_YWT,
			CMD_SWITCH_INT_AP);
	else
		retval = touch_driver_switch_cmd(tdev, CMD_SWITCH_INT_PIN,
			CMD_SWITCH_INT_AP);
	if (retval != 0) {
		thp_log_err("%s: switch int to ap failed\n", __func__);
		return -EINVAL;
	}
	return NO_ERR;
}
#endif

static struct thp_device_ops yuwei_dev_ops = {
	.init = touch_driver_init,
	.detect = touch_driver_chip_detect,
	.get_frame = touch_driver_get_frame,
	.resume = touch_driver_resume,
	.after_resume = touch_driver_after_resume,
	.suspend = touch_driver_suspend,
	.get_project_id = touch_driver_get_project_id,
	.exit = touch_driver_exit,
	.afe_notify = touch_driver_afe_notify_callback,
	.chip_wakeup_gesture_enable_switch =
		touch_driver_wakeup_gesture_enable_switch,
	.chip_wrong_touch = touch_driver_wrong_touch,
	.chip_gesture_report = touch_driver_gesture_report,
	.bt_handler = touch_driver_9x_bt_handler,
#ifdef CONFIG_HUAWEI_SHB_THP
	.switch_int_sh = touch_driver_switch_int_sh,
	.switch_int_ap = touch_driver_switch_int_ap,
#endif
};

static void touch_driver_dev_free(struct thp_device *tdev,
	struct thp_core_data *cd)
{
	kfree(tx_frame_buff[cd->panel_id]);
	tx_frame_buff[cd->panel_id] = NULL;
	kfree(rx_frame_buff[cd->panel_id]);
	rx_frame_buff[cd->panel_id] = NULL;
	kfree(tdev->tx_buff);
	tdev->tx_buff = NULL;
	kfree(tdev->rx_buff);
	tdev->rx_buff = NULL;
	kfree(tdev);
	tdev = NULL;
}

static int thp_module_init(u32 panel_id)
{
	int rc = NO_ERR;
	struct thp_core_data *cd = NULL;
	struct thp_device *dev = NULL;

	thp_log_info("%s: called\n", __func__);
	cd = thp_get_core_data(panel_id);
	if (!cd) {
		thp_log_err("%s: cd is null\n", __func__);
		return -EINVAL;
	}
	dev = kzalloc(sizeof(struct thp_device), GFP_KERNEL);
	if (dev == NULL) {
		thp_log_err("%s: thp device malloc fail\n", __func__);
		return -ENOMEM;
	}
	dev->tx_buff = kzalloc(thp_get_max_frame_size(cd), GFP_KERNEL);
	dev->rx_buff = kzalloc(thp_get_max_frame_size(cd), GFP_KERNEL);
	tx_frame_buff[cd->panel_id] = kzalloc(thp_get_max_frame_size(cd), GFP_KERNEL);
	rx_frame_buff[cd->panel_id] = kzalloc(thp_get_max_frame_size(cd), GFP_KERNEL);
	if ((dev->tx_buff == NULL) || (dev->rx_buff == NULL) ||
		(tx_frame_buff[cd->panel_id] == NULL) || (rx_frame_buff[cd->panel_id] == NULL)) {
		thp_log_err("%s: out of memory\n", __func__);
		rc = -ENOMEM;
		goto err;
	}
	dev->ic_name = YUWEI_IC_NAME;
	dev->dev_node_name = THP_YUWEI_DEV_NODE_NAME;
	dev->ops = &yuwei_dev_ops;
	if (cd->fast_booting_solution) {
		thp_send_detect_cmd(dev, panel_id, NO_SYNC_TIMEOUT);
		/*
		 * The thp_register_dev will be called later to complete
		 * the real detect action.If it fails, the detect function will
		 * release the resources requested here.
		 */
		return NO_ERR;
	}
	rc = thp_register_dev(dev, panel_id);
	if (rc) {
		thp_log_err("%s: register fail\n", __func__);
		goto err;
	}
	return rc;
err:
	touch_driver_dev_free(dev, cd);
	return rc;
}

static int __init touch_driver_module_init(void)
{
	int rc = NO_ERR;
	struct device_node *dn = NULL;
	u32 i;

	thp_log_info("%s: called\n", __func__);
	for (i = 0; i < TOTAL_PANEL_NUM; i++) {
		dn = get_thp_node(i);
		if (dn && of_get_child_by_name(dn, THP_YUWEI_DEV_NODE_NAME))
			rc = thp_module_init(i);
	}
	return rc;
}

static void __exit touch_driver_module_exit(void)
{
	thp_log_info("%s: called\n", __func__);
};

#ifdef CONFIG_HUAWEI_THP_QCOM
late_initcall(touch_driver_module_init);
#else
module_init(touch_driver_module_init);
#endif
module_exit(touch_driver_module_exit);
MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");