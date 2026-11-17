/*
* Thp driver code for hisilicon
*
* Copyright (c) 2025-2025 Huawei Technologies Co., Ltd.
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
#include <linux/uaccess.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/spi/spi.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/string.h>
#include <linux/time.h>
#include <linux/syscalls.h>
#include <linux/inet.h>
#include "huawei_thp.h"
#include "huawei_pen_clk.h"
#include "securec.h"
#include "bus_adapter/huawei_bus_adapter.h"
#include "bus_adapter/huawei_spi_bus_platform.h"
#include "bus_adapter/huawei_spi_bus_config_parse.h"

#define HISILICON_IC_NAME               "hisilicon"
#define THP_HISI_DEV_NODE_NAME          "hisilicon_thp"

#define TOUCH_PROJECT_ID_LEN            10
#define MASK_8BIT                       0xFF
#define MOVE_8BIT                       8
#define MOVE_16BIT                      16
#define MOVE_24BIT                      24
#define S_US                            1000000
/* CMD */
#define CMD_ACK_OFFSET                  5
#define CMD_SEND_RETRY                  10
#define CMD_ACK_OK                      0x01
#define CMD_WAIT_COMPLETE               2
#define TOUCH_CMD_PREX                  0xC000
#define AP_CMD_MAX_LEN                  0x08
/* afe all reg addr */
#define MAPPING_TABLE_ADDR              0x20000
#define AFE_ADDR_LEN                    4
/* PID */
#define PROJ_ID_INFO_LEN                12
#define PID_MAIN_AREA                   0x7e000
#define PID_BACK_AREA                   0x7f000

#define TC_REG_FMC_CFG                  0x0000
#define TC_REG_FMC_GLOBAL_CFG           0x0004
#define TC_REG_FMC_INT_CLR              0x0020
#define TC_REG_FMC_CMD                  0x0024
#define TC_REG_FMC_ADDRL                0x002C
#define TC_REG_FMC_OP_CFG               0x0030
#define TC_REG_FMC_DATA_NUM             0x0038
#define TC_REG_FMC_OP                   0x003C

#define TC_REG_BASE_FMC                 0x000F0000
#define TC_BASE_FLASH_ADDR              0x00100000
#define TC_REG_FMC_DMA_SADDR_D0         0x004C
#define TC_REG_FMC_DMA_LEN              0x0040
#define TC_REG_FMC_OP_CTRL              0x0068

#define MOVE_FLASH_STATUS_REG_ADDR      0xF0018
#define FLASH_WRITE_TIMEOUT             500
#define MOVE_FLASH_SUCCESS_FLAG         1
#define TEN_MSECONDS                    10

#define FMC_BASE_ADDR               0xf0000
#define STATUS_REG_ADDR             0xA400C
#define IC_SYS_ID_ADDR              0xA4190
#define IC_SYS_ID_VALUE             0x36540100
#define CALL_STACK_ADDR2            0x27f6c
#define CALL_STACK_LEN2             128
#define FRAME_SYNC_CODE             0xffffffff

#define MAGIC_NUMBE_FLASH_ADDRESS   0x30000
#define RESET_LOW_DELAY_MS          1
#define RESET_HIGH_DELAY_MS         3

// gesture report
#define TOUCH_DATA_LEN_PREFIX 			8
#define TOUCH_DATA_LEN_DATA 			76
#define SPI_MAX_DATA_LEN (TOUCH_DATA_LEN_PREFIX + TOUCH_DATA_LEN_DATA)
#define WAIT_FOR_SPI_BUS_RESUMED_DELAY  20
#define GESTURE_EVENT_RETRY_TIME        20
#define GESTURE_BUF_LEN                 4
#define DATA_TYPE_GESTURE               0xEE
#define GESTURE_DOUBLE_TAP              0x3B
// TOUCH_EVENT_TYPE
#define TOUCH_EVENT_DOUBLE_CLK          6
#define GESTURE_READ_DELAY              5
// THP_AFE_GESTURE_ENUM
#define THP_AFE_GESTURE_NONE            0
#define THP_AFE_GESTURE_SINGLE_CLICK    (1 << 0)
#define THP_AFE_GESTURE_DOUBLE_CLICK    (1 << 1)
// report irq to sensorhub or AP
#define REPORT_IRQ_TO_SHB               0x01
#define REPORT_IRQ_TO_AP                0x00
// suspend status
#define SUSPEND_GESTURE_MODE            1
#define SUSPEND_POWER_OFF               0
/* SPI frame header format */
#define SPI_READ_HEADER_FORMAT          0xc9
#define SPI_WRITE_HEADER_FORMAT         0x49
#define SPI_READ_OFFSET                 11
#define SPI_WRITE_OFFSET                7
#define SPI_RW_OFFSET                   5
/* udfp data */
#define SCREENOFF_FRAME_LEN             32
#define SCREENON_EVENT_LEN              16
#define REPORT_TYPE_GESTURE             (1 << 2)
#define DOUBLE_CLICK                    2
#define STYLUS_SINGLE_CLICK             4
#define FMC_READ_TIMEOUT_CNT            20000
#define CRC_CHECK_NUM                   3
#define DOUBLE_TAP_FLAG                 2
#define SPI_READ_RETRY_TIME             20
#define SPI_DELAY_MS                    10
typedef enum {
    TOUCH_REPORT_EVENT = 1,
    TOUCH_REPORT_FRAME = 2,
    TOUCH_REPORT_GES_FRAME = 5,
} TOUCH_REPORT_TYPE;

typedef enum {
	TOUCH_WOKR_MODE_CFG = 1,
	TOUCH_WOKR_MODE_GESTURE = 9,
	TOUCH_WOKR_MODE_SLEEP = 10,
} TOUCH_WOKR_MODE;

typedef enum {
	DATA0 = 0,
	DATA1,
	DATA2,
	DATA3,
	DATA4,
} CMD_PARA;

enum afe_cmd {
	CMD_CHANGE_TOUCH_WORK_MODE          = (TOUCH_CMD_PREX | 0x05),
	CMD_AFE_SET_CLOCK_SOURCE            = (TOUCH_CMD_PREX | 0x19),
	// enable/disable feature
	CMD_ENABLE_GESTURE_FEATURE          = (TOUCH_CMD_PREX | 0x21),
	CMD_REPORT_ENABLE                   = (TOUCH_CMD_PREX | 0x88),
	CMD_PERIPH_WAKEUP                   = (TOUCH_CMD_PREX | 0xa0),
	CMD_UPDATE_FIRMWARE_POST_PROCESSING = (TOUCH_CMD_PREX | 0x0c1)
};

enum touch_data_type {
	TOUCH_DATATYPE_CMD = 5,
	TOUCH_DATATYPE_EVENT = 7,
	TOUCH_DATATYPE_MAX = 16,
};

enum touch_cmd_type {
	TOUCH_WFI_CMD = 0x01,
	TOUCH_VERIFY_BURN_STATUS_CMD = 0x02
};

struct touch_data_location_info {
	u32 data_addr_info[TOUCH_DATATYPE_MAX];
	u16 mapping_crc;
	u8 reservse[2];
};

struct link_ap_cmd {
	u16  cmd;
	u8   ack;
	u8   len;
	u8   param[AP_CMD_MAX_LEN];
	u16  cmdCrc;
	u8   reservse[2];
};

// global variable
static u32 g_hisi_report_addr = 0;
static u32 g_hisi_frame_addr = 0;
static u32 g_hisi_cmd_addr = 0;
static unsigned int need_power_off;

static inline u32 tc_get_bit(u32 value, u32 position)
{
	return (((value) >> (position)) & 1);
}

static void invert_uint32(u32 *src_buf, u32 len)
{
	u32 i;
	u32 tmp = 0;

	if (src_buf == NULL) {
		thp_log_err("%s: src_buf is null\n", __func__);
		return;
	}
	for (i = 0; i < len / sizeof(u32); i++) {
		tmp = ((src_buf[i] & 0xff000000) >> MOVE_24BIT) |
			((src_buf[i] & 0xff0000) >> MOVE_8BIT) |
			((src_buf[i] & 0xff00) << MOVE_8BIT) |
			((src_buf[i] & 0xff) << MOVE_24BIT);
		src_buf[i] = tmp;
	}
}

static u16 calc_xmode_crc16(unsigned char *push_msg, u32 us_data_len)
{
	u16 w_crc_in = 0xFFFF;  // crc default value 0xffff
	u16 w_crc_poly = 0x8005; // crc poly code 0x8005
	unsigned char w_char;
	int i;

	if (push_msg == NULL) {
		thp_log_err("%s: push_msg is null\n", __func__);
		return 0;
	}

	while (us_data_len--) {
		w_char = *push_msg++;
		w_crc_in ^= (w_char << MOVE_8BIT);
		for (i = 0; i < 8; i++) { // crc calc by 8 bit
			if (w_crc_in & 0x8000)
				w_crc_in = (w_crc_in << 1) ^ w_crc_poly;
			else
				w_crc_in = w_crc_in << 1;
		}
	}
	return w_crc_in;
}

static void touch_driver_spi_assign_buffer(u8 *rx_buf,  u8 *tx_buf, struct spi_transfer *xfers, u32 addr, u32 len)
{
	int index = 0;
	tx_buf[index++] = SPI_READ_HEADER_FORMAT;
	tx_buf[index++] = ((len - 1) >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = ((len - 1) >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = (len - 1) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	tx_buf[index++] = MASK_8BIT;
	xfers->tx_buf = tx_buf;
	xfers->rx_buf = rx_buf;
	xfers->len = len + SPI_READ_OFFSET;
}

static int touch_driver_spi_read_retry(struct thp_device *tdev,
	struct spi_device *spi, struct spi_message *spi_msg)
{
	int retry = 0;
	int ret = NO_ERR;

	while (retry < SPI_READ_RETRY_TIME) {
		ret = thp_spi_sync(spi, spi_msg);
		if (ret < 0) {
			thp_log_err("Spi transfer error:%d\n", ret);
			retry++;
			msleep(SPI_DELAY_MS);
			continue;
		}
		break;
	}
	return ret;
}

static int touch_driver_spi_read_once(struct thp_device *tdev,
	struct spi_device *spi, struct spi_message *spi_msg)
{
	int ret = NO_ERR;

	ret = thp_spi_sync(spi, spi_msg);
	if (ret < 0) {
		thp_log_err("Spi transfer error:%d\n", ret);
		return ret;
	}
	return ret;
}

static int touch_driver_spi_sync(struct thp_device *tdev,
	struct spi_device *spi, struct spi_message *spi_msg)
{
	struct thp_core_data *cd = tdev->thp_core;
	int ret = NO_ERR;

	if (cd->use_ap_gesture) {
		ret = touch_driver_spi_read_retry(tdev, spi, spi_msg);
		if (ret < 0)
			thp_log_err("%s:get retry failed:%d\n", __func__, ret);
	} else {
		ret = touch_driver_spi_read_once(tdev, spi, spi_msg);
		if (ret < 0)
			thp_log_err("%s:get spi sync failed:%d\n", __func__, ret);
	}

	return ret;
}

static int touch_driver_spi_read(struct thp_device *tdev, u32 addr, u8 *data, u32 len)
{
	u8 *rx_buf = NULL;
	u8 *tx_buf = NULL;
	int rc;
	struct spi_device *spi = NULL;
	struct spi_transfer *xfers;
	struct spi_message spi_msg;

	if (data == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}

	if ((len + SPI_RW_OFFSET) > THP_MAX_FRAME_SIZE) {
		thp_log_err("%s: invalid len: %d\n", __func__, len);
		return -EINVAL;
	}

	rc = thp_bus_lock(tdev);
	if (rc < 0) {
		thp_log_err("%s: get lock failed:%d\n", __func__, rc);
		return rc;
	}
	spi = tdev->thp_core->sdev;
	rx_buf = tdev->rx_buff;
	tx_buf = tdev->tx_buff;
	spi_message_init(&spi_msg);
	xfers = kzalloc(sizeof(struct spi_transfer), GFP_KERNEL);
	if (xfers == NULL) {
		thp_log_err("%s: kzalloc invalid xfers\n", __func__);
		thp_bus_unlock(tdev);
		return -EINVAL;
	}

	(void)memset_s(tx_buf, THP_MAX_FRAME_SIZE, 0, len + SPI_READ_OFFSET);
	touch_driver_spi_assign_buffer(rx_buf, tx_buf, xfers, addr, len);
	spi_message_init(&spi_msg);
	spi_message_add_tail(xfers, &spi_msg);
	rc = touch_driver_spi_sync(tdev, spi, &spi_msg);
	if (rc < 0) {
		thp_log_err("%s: spi transfer error:%d\n", __func__, rc);
		goto err;
	}
	rc = memcpy_s(data, len, &rx_buf[SPI_READ_OFFSET], len);
	if (rc) {
		thp_log_err("%s: memcpy_s error:%d\n", __func__, rc);
		goto err;
	}
err:
	thp_bus_unlock(tdev);
	kfree(xfers);
	return rc;
}

static int touch_driver_spi_write(struct thp_device *tdev, u32 addr, u8 *data, u32 len)
{
	struct spi_device *spi = NULL;
	u8 *tx_buf = NULL;
	u8 *rx_buf = NULL;
	struct spi_transfer xfers;
	struct spi_message spi_msg;
	int rc;
	int index = 0;

	if (data == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	spi = tdev->thp_core->sdev;
	rc = thp_bus_lock(tdev);
	if (rc < 0) {
		thp_log_err("%s: get lock failed:%d\n", __func__, rc);
		return rc;
	}
	tx_buf = tdev->tx_buff;
	rx_buf = tdev->rx_buff;
	spi_message_init(&spi_msg);
	(void)memset_s(&xfers, sizeof(xfers), 0, sizeof(xfers));

	tx_buf[index++] = SPI_WRITE_HEADER_FORMAT;
	tx_buf[index++] = ((len - 1) >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = ((len - 1) >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = (len - 1) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_16BIT) & MASK_8BIT;
	tx_buf[index++] = (addr >> MOVE_8BIT) & MASK_8BIT;
	tx_buf[index++] = addr & MASK_8BIT;
	rc = memcpy_s(&tx_buf[index], THP_MAX_FRAME_SIZE, data, len);
	if (rc) {
		thp_log_err("%s: memcpy_s error:%d\n", __func__, rc);
		thp_bus_unlock(tdev);
		return rc;
	}
	xfers.len = len + SPI_WRITE_OFFSET;
	xfers.tx_buf = tx_buf;
	xfers.rx_buf = rx_buf;
	spi_message_add_tail(&xfers, &spi_msg);
	rc = thp_spi_sync(spi, &spi_msg);
	thp_bus_unlock(tdev);
	if (rc < 0)
		thp_log_err("%s: spi transfer error:%d, addr 0x%x\n", __func__, rc, addr);

	return rc;
}

static int touch_driver_spi_read_with_invert(struct thp_device *tdev, u32 addr, u8 *data, u32 len)
{
	int rc = 0;

	if (data == NULL) {
		thp_log_err("%s: tdev or data is null\n", __func__);
		return -EINVAL;
	}
	rc = touch_driver_spi_read(tdev, addr, data, len);
	if (rc < 0) {
		thp_log_err("%s: spi read failed:%d\n", __func__, rc);
		return rc;
	}
	invert_uint32((u32 *)data, len);
	return rc;
}

static int touch_driver_spi_write_with_invert(struct thp_device *tdev, u32 addr, u8 *data, u32 len)
{
	int rc = 0;

	if (data == NULL) {
		thp_log_err("%s: tdev or data is null\n", __func__);
		return -EINVAL;
	}
	invert_uint32((u32 *)data, len);
	rc = touch_driver_spi_write(tdev, addr, data, len);
	if (rc < 0) {
		thp_log_err("%s: spi read failed:%d\n", __func__, rc);
		return rc;
	}
	invert_uint32((u32 *)data, len);
	return rc;
}

static int touch_driver_send_cmd(struct thp_device *tdev, u16 cmd, u8 *paras, u8 para_len, bool wait_flag)
{
	int rc;
	int i;
	struct link_ap_cmd cmd_data = {0};
	const int cmd_len = sizeof(cmd_data);
	struct link_ap_cmd ack_cmd;

	if (paras == NULL) {
		thp_log_err("%s: invalid param paras", __func__);
		return -EINVAL;
	}
	if (g_hisi_cmd_addr == 0) {
		thp_log_err("%s: cmd addr is 0\n", __func__);
		return -EINVAL;
	}

	cmd_data.cmd = cmd;
	if (para_len > 0) {
		rc = memcpy_s(cmd_data.param, AP_CMD_MAX_LEN, paras, para_len);
		if (rc) {
			thp_log_err("%s: memcpy_s error:%d\n", __func__, rc);
			return rc;
		}
		cmd_data.len = para_len;
	}
	cmd_data.cmdCrc = calc_xmode_crc16((u8 *)(&cmd_data), cmd_len - 4); /* crc + reser 4 bytes */
	thp_log_info("cmd: 0x%x cmdCrc: 0x%02x", cmd, cmd_data.cmdCrc);
	invert_uint32((u32 *)(&cmd_data), cmd_len);
	rc = touch_driver_spi_write(tdev, g_hisi_cmd_addr, (u8 *)(&cmd_data), cmd_len);
	if (rc != 0) {
		thp_log_err("%s: failed to send cmd: %d", __func__, rc);
		return rc;
	}

	if (wait_flag == false)
		return 0;

	for (i = 0; i < CMD_SEND_RETRY; i++) {
		msleep(CMD_WAIT_COMPLETE);
		rc = touch_driver_spi_read(tdev, g_hisi_cmd_addr, (u8 *)&ack_cmd, cmd_len);
		if (rc != 0) {
			thp_log_err("%s: failed to cmd ack", __func__);
			return rc;
		}
		invert_uint32((u32 *)&ack_cmd, cmd_len);
		if (ack_cmd.cmd == cmd && ack_cmd.ack == CMD_ACK_OK) {
			thp_log_info("cmd ack ok");
			return 0;
		}
	}
	thp_log_err("%s: send cmd failed", __func__);
	return -EREMOTEIO;
}

static void touch_driver_send_wakeup(struct thp_device *tdev)
{
	u8 cmd_para[] = {0x5a, 0x5a, 0x5a, 0x5a, 0, 0, 0};  // 0x5a is special code for wakeup tpic
	(void)touch_driver_send_cmd(tdev, CMD_PERIPH_WAKEUP, cmd_para, sizeof(cmd_para), false);
}

static int thp_parse_feature_ic_config(struct device_node *thp_node,
	struct thp_core_data *cd)
{
	cd->need_extra_system_clk = 0;
	thp_parse_dts_u32(thp_node, "need_extra_system_clk", &cd->need_extra_system_clk, __func__);

	cd->support_fw_xtal_switch = 0;
	thp_parse_dts_u32(thp_node, "support_fw_xtal_switch", &cd->support_fw_xtal_switch, __func__);

	cd->hard_reset_in_special_mode = 0;
	thp_parse_dts_u32(thp_node, "hard_reset_in_special_mode", &cd->hard_reset_in_special_mode, __func__);

	return NO_ERR;
}

static int touch_driver_init(struct thp_device *tdev)
{
	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	struct thp_core_data *cd = tdev->thp_core;
	struct device_node *hisi_node = of_get_child_by_name(cd->thp_node, THP_HISI_DEV_NODE_NAME);
	thp_log_info("%s: called xhs\n", __func__);
	if (hisi_node == NULL) {
		thp_log_err("%s: dev not config in dts\n", __func__);
		return -ENODEV;
	}

	(void)thp_parse_spi_config(hisi_node, cd);
	(void)thp_parse_timing_config(hisi_node, &tdev->timing_config);
	(void)thp_parse_feature_config(hisi_node, cd);
	(void)thp_parse_trigger_config(hisi_node, cd);
	(void)thp_parse_feature_ic_config(hisi_node, cd);
	of_node_put(hisi_node);
	return 0;
}

static int touch_driver_power_on(struct thp_device *tdev, u32 panel_id)
{
	int rc;
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	thp_log_info("%s: called \n", __func__);
	if (cd == NULL) {
		thp_log_err("%s: cd is null\n", __func__);
		return -EINVAL;
	}

	if (tdev->thp_core->support_adapter_mode) {
		thp_log_info("%s: power supoort adapter mode 1\n", __func__);
		return support_power_adapter_mode(tdev, THP_POWER_ON);
	}
	gpio_direction_input(tdev->gpios->irq_gpio);
	gpio_direction_output(tdev->gpios->rst_gpio, GPIO_LOW);
	rc = thp_power_supply_ctrl(THP_VCC, THP_POWER_ON, 1, panel_id);
	if (rc)
		thp_log_err("%s: vcc fail\n", __func__);

	rc = thp_power_supply_ctrl(THP_IOVDD, THP_POWER_ON, cd->iovdd_power_on_delay_ms, panel_id);
	if (rc)
		thp_log_err("%s: iovdd fail\n", __func__);
	if (!cd->not_support_cs_control)
		gpio_direction_output(tdev->gpios->cs_gpio, GPIO_HIGH);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
	thp_do_time_delay(tdev->timing_config.boot_reset_hi_delay_ms);

	return rc;
}

static void touch_driver_power_release(struct thp_device *tdev, u32 panel_id)
{
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	if (cd->power_cfg.power_supply_mode)
		return;
	thp_power_supply_put(THP_VCC, panel_id);
	thp_power_supply_put(THP_IOVDD, panel_id);
}

static int touch_driver_power_off(struct thp_device *tdev, u32 panel_id)
{
	int rc;
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	thp_log_info("%s: called \n", __func__);
	if (cd == NULL) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}

	if (tdev->thp_core->power_cfg.power_supply_mode)
		return 0;
	if (tdev->thp_core->support_adapter_mode) {
		thp_log_info("%s: power supoort adapter mode 1\n", __func__);
		return support_power_adapter_mode(tdev, THP_POWER_OFF);
	}
	thp_log_info("%s pull down tp ic reset\n", __func__);
	gpio_direction_output(tdev->gpios->irq_gpio, GPIO_LOW);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	if (!cd->not_support_cs_control)
		gpio_direction_output(tdev->gpios->cs_gpio, GPIO_LOW);
	thp_do_time_delay(tdev->timing_config.suspend_reset_after_delay_ms);

	rc = thp_power_supply_ctrl(THP_IOVDD, THP_POWER_OFF, 1, panel_id);
	if (rc)
		thp_log_err("%s: iovdd fail\n", __func__);

	rc = thp_power_supply_ctrl(THP_VCC, THP_POWER_OFF, 1, panel_id);
	if (rc)
		thp_log_err("%s: vcc fail\n", __func__);

	return rc;
}

static int touch_driver_power_init(u32 panel_id)
{
	int rc;
	struct thp_core_data *cd = thp_get_core_data(panel_id);

	if (cd == NULL) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}

	if (cd->power_cfg.power_supply_mode)
		return 0;

	rc = thp_power_supply_get(THP_VCC, panel_id);
	if (rc)
		thp_log_err("%s: vcc fail\n", __func__);

	rc = thp_power_supply_get(THP_IOVDD, panel_id);
	if (rc)
		thp_log_err("%s: iovdd fail\n", __func__);

	return 0;
}

static int touch_driver_read_sysid(struct thp_device *tdev)
{
	int rc;
	u32 sysid;

	rc = touch_driver_spi_read(tdev, IC_SYS_ID_ADDR, (u8 *)&sysid, AFE_ADDR_LEN);
	if (rc) {
		thp_log_err("%s: failed read sysid data, rc %d\n", __func__, rc);
		return rc;
	}
	invert_uint32(&sysid, AFE_ADDR_LEN);
	if (sysid != IC_SYS_ID_VALUE) {
		thp_log_err("%s: read reg sysid failed, sysid 0x%x\n", __func__, sysid);
		return -EINVAL;
	}
	thp_log_info("%s: sysid: 0x%x", __func__, sysid);
	return rc;
}

static int touch_driver_get_reg_addr(struct thp_device *tdev)
{
	int rc;
	u32 map_addr;
	struct touch_data_location_info *addr_info;
	const int len = sizeof(*addr_info);
	u8 addr_buf[len] = {0};
	bool crcSucess = false;
	if (touch_driver_read_sysid(tdev))
		return -EINVAL;

	for (int i = 1; i <= CRC_CHECK_NUM; i++) {
		rc = touch_driver_spi_read(tdev, MAPPING_TABLE_ADDR, (u8 *)&map_addr, AFE_ADDR_LEN);
		if (rc) {
			thp_log_err("%s: failed read regs data, rc %d\n", __func__, rc);
			return rc;
		}
		invert_uint32(&map_addr, AFE_ADDR_LEN);
		thp_log_info("%s: map_addr: 0x%x", __func__, map_addr);
		rc = touch_driver_spi_read(tdev, map_addr, addr_buf, len);
		if (rc) {
			thp_log_err("%s: read mapaddr failed\n", __func__);
			return rc;
		}
		invert_uint32((u32 *)addr_buf, len);
		addr_info = (struct touch_data_location_info *)addr_buf;
		u16 calcCrc = calc_xmode_crc16((u8*)addr_info, sizeof(addr_info->data_addr_info));
		if (calcCrc != addr_info->mapping_crc || addr_info->mapping_crc == 0) {
			thp_log_err("crc error, calcCrc:0x%x, mappingCrc:0x%x, retry:%d", calcCrc, addr_info->mapping_crc, i);
			msleep(CMD_SEND_RETRY);
			continue;
		}
		crcSucess = true;
		break;
	}
	if (!crcSucess)
		return 0;
	g_hisi_cmd_addr = addr_info->data_addr_info[TOUCH_DATATYPE_CMD];
	g_hisi_report_addr = addr_info->data_addr_info[TOUCH_DATATYPE_EVENT];
	rc = touch_driver_spi_read(tdev, g_hisi_report_addr, (u8 *)&g_hisi_frame_addr, AFE_ADDR_LEN);
	if (rc) {
		thp_log_err("%s: read afeFrameAddr failed", __func__);
		return rc;
	}
	invert_uint32((u32 *)&g_hisi_frame_addr, AFE_ADDR_LEN);
	thp_log_info("%s: reportAddr: 0x%x frameAddr: 0x%x cmdAddr: 0x%x",
		__func__, g_hisi_report_addr, g_hisi_frame_addr, g_hisi_cmd_addr);
	return rc;
}

static void touch_fmc_read(struct thp_device *tdev, unsigned int flash_addr, unsigned int ram_addr, unsigned int len)
{
	unsigned int value = 0;

	if (((flash_addr % 0x100) != 0) && (len >= 0x100)) {
		thp_log_err("error fmc read len.\n");
		return;
	}

	value = 0x1;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CFG, (u8 *)&value, sizeof(value));
	value = 0xff;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_INT_CLR, (u8 *)&value, sizeof(value));
	value = flash_addr;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_ADDRL, (u8 *)&value, sizeof(value));
	value = ram_addr;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_DMA_SADDR_D0, (u8 *)&value, sizeof(value));
	value = len;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_DMA_LEN, (u8 *)&value, sizeof(value));

	value = 0x0;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CFG, (u8 *)&value, sizeof(value));
	value = 0x30001;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CTRL, (u8 *)&value, sizeof(value));
	u32 time_out_cnt = 0;
	do {
		touch_driver_spi_read_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CTRL, (u8 *)&value, sizeof(value));
		time_out_cnt++;
		if (time_out_cnt > FMC_READ_TIMEOUT_CNT) {
			break;
		}
	} while (tc_get_bit(value, 0) != 0x0);
}

#define PID_MAIN_STORE_AREA 0x35000
#define PID_BACK_STORE_AREA 0x36000
static int get_project_id_from_flash(struct thp_device *tdev, char *getpid, u32 len)
{
	thp_log_info("%s: called \n", __func__);
	u32 rc = -EINVAL;
	u16 crc = 0;
	u16 crc_back = 0;
	u16 current_crc = 0;
	u8 buffer[PROJ_ID_INFO_LEN + sizeof(u32)] = {0};
	u8 pid[PROJ_ID_INFO_LEN] = {0};
	u8 pid_back[PROJ_ID_INFO_LEN] = {0};

	touch_fmc_read(tdev, PID_MAIN_AREA, PID_MAIN_STORE_AREA, sizeof(buffer));
	touch_driver_spi_read_with_invert(tdev, PID_MAIN_STORE_AREA, (u8 *)buffer, sizeof(buffer));
	(void)memcpy_s(pid, sizeof(pid), buffer, sizeof(pid));
	(void)memcpy_s(&crc, sizeof(crc), &buffer[PROJ_ID_INFO_LEN], sizeof(crc));

	(void)memset_s(buffer, sizeof(buffer), 0, sizeof(buffer));
	touch_fmc_read(tdev, PID_BACK_AREA, PID_BACK_STORE_AREA, sizeof(buffer));
	touch_driver_spi_read_with_invert(tdev, PID_BACK_STORE_AREA, (u8 *)buffer, sizeof(buffer));
	(void)memcpy_s(pid_back, sizeof(pid_back), buffer, sizeof(pid_back));
	(void)memcpy_s(&crc_back, sizeof(crc), &buffer[PROJ_ID_INFO_LEN], sizeof(crc));
	current_crc = calc_xmode_crc16((unsigned char *)pid, PROJ_ID_INFO_LEN);
	if (current_crc == crc) {
		(void)memcpy_s(getpid, len, pid, len);
		rc = 0;
		goto out;
	}

	current_crc = calc_xmode_crc16((unsigned char *)pid_back, PROJ_ID_INFO_LEN);
	if (current_crc == crc_back) {
		(void)memcpy_s(getpid, len, pid_back, len);
		rc = 0;
		goto out;
	}
	thp_log_err("pid error!!!\n");
out:
	thp_log_info("%s: read final_pid value:%s, current_crc:%x\n", __func__, getpid, current_crc);
	thp_log_info("%s: read1 out value:%s, crc:%x\n", __func__, (char *)pid, crc);
	thp_log_info("%s: read2 out value:%s, crc:%x\n", __func__, (char *)pid_back, crc_back);
	return rc;
}

static unsigned int cropping(unsigned int org_value, unsigned int low_bit, unsigned int high_bit)
{
	const unsigned int mask = ((0xFFFFFFFFu >> (31u - high_bit)) & (0xFFFFFFFFu << low_bit));
	return (org_value & mask) >> low_bit;
}

static void reset_device(struct thp_device *tdev)
{
	thp_log_info("%s: IN\n", __func__);
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_LOW);
	msleep(RESET_LOW_DELAY_MS);
	thp_log_info("rst gpio %d\n", gpio_get_value(tdev->gpios->rst_gpio));
	gpio_set_value(tdev->gpios->rst_gpio, GPIO_HIGH);
	msleep(RESET_HIGH_DELAY_MS);
	thp_log_info("rst gpio %d\n", gpio_get_value(tdev->gpios->rst_gpio));
}

static bool wr_enable(struct thp_device *tdev)
{
	// send an address: TC_REG_BASE_FMC(fmc base addr) and value: 0x1.
	int val = 0x01;

	if (touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC, (u8 *)(&val), sizeof(u32)) != 0) {
		thp_log_err("send 0x01 to base fmc failed\n");
		return false;
	}

	// send an address: TC_REG_FMC_INT_CLR and value: 0xff.
	val = 0xff;
	if (touch_driver_spi_write_with_invert(
		tdev, TC_REG_BASE_FMC + TC_REG_FMC_INT_CLR, (u8 *)(&val), sizeof(u32)) != 0) {
		thp_log_err("send 0xff to fcm int clr failed\n");
		return false;
	}

	// send an address: TC_REG_FMC_CMD and value: 0x6.
	val = 0x06;
	if (touch_driver_spi_write_with_invert(
		tdev, TC_REG_BASE_FMC + TC_REG_FMC_CMD, (u8 *)(&val), sizeof(u32)) != 0) {
		thp_log_err("send 0x06 to fmc cmd failed\n");
		return false;
	}

	// send an address: TC_REG_FMC_OP_CFG and value: 0x0.
	val = 0x0;
	if (touch_driver_spi_write_with_invert(
		tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CFG, (u8 *)(&val), sizeof(u32)) != 0) {
		thp_log_err("send 0x0 to fmc op cfg failed\n");
		return false;
	}

	// send an address: TC_REG_FMC_OP and value: 0x81
	val = 0x81;
	if (touch_driver_spi_write_with_invert(
		tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)(&val), sizeof(u32)) != 0) {
		thp_log_err("send 0x81 to fmc op failed\n");
		return false;
	}

	return true;
}

static bool get_erase_result(struct thp_device *tdev, int time_out, int register_addr, int wanted_value)
{
	// receive data
	int time = 0;
	int recv_result = 0;

	do {
		unsigned int value = 0;
		if (touch_driver_spi_read_with_invert(tdev, register_addr, (u8 *)(&value), sizeof(u32)) != 0) {
			thp_log_err("read 0x%x failed", register_addr);
			return false;
		}

		recv_result = cropping(value, 0, 0);
		if (recv_result == wanted_value)
			return true;

		time += TEN_MSECONDS;
		msleep(TEN_MSECONDS);
	} while (time < time_out + TEN_MSECONDS);

	thp_log_info("sending a address: 0x%x, recieved bit0: 0x%x, expected value:0x%x\n",
		register_addr, recv_result, wanted_value);
	thp_log_err("time_out error, the burning channel is blocked. please check\n");
	return false;
}

static void fmc_write_enable(struct thp_device *tdev)
{
	u32 value = 0;

	value = 0x1;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CFG, (u8 *)&value, sizeof(value));
	value = 0xff;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_INT_CLR, (u8 *)&value, sizeof(value));
	value = 0x6;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CMD, (u8 *)&value, sizeof(value));
	value = 0x0;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CFG, (u8 *)&value, sizeof(value));
	value = 0x81;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
	u32 time_out_cnt = 0;
	do {
		touch_driver_spi_read_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
		time_out_cnt++;
		if (time_out_cnt > FMC_READ_TIMEOUT_CNT)
			break;
	} while (tc_get_bit(value, 0) != 0x0);
}

static unsigned int fmc_read_status_one(struct thp_device *tdev, unsigned int cmd_value)
{
	unsigned int value = 0;
	unsigned int stat = 0;

	value = 0x0;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CFG, (u8 *)&value, sizeof(value));
	value = 0x1;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CFG, (u8 *)&value, sizeof(value));
	value = 0xC0;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_GLOBAL_CFG, (u8 *)&value, sizeof(value));
	value = cmd_value;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CMD, (u8 *)&value, sizeof(value));
	value = 0x01;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_DATA_NUM, (u8 *)&value, sizeof(value));
	value = 0x85;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
	u32 time_out_cnt = 0;
	do {
		touch_driver_spi_read_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
		time_out_cnt++;
		if (time_out_cnt > FMC_READ_TIMEOUT_CNT)
			break;
	} while (tc_get_bit(value, 0) != 0x0);
	touch_driver_spi_read_with_invert(tdev, TC_BASE_FLASH_ADDR, (u8 *)&stat, sizeof(u32));
	return (stat & 0xff);
}

static int fmc_read_status(struct thp_device *tdev)
{
	unsigned int lstat = fmc_read_status_one(tdev, 0x5);
	unsigned int hstat = fmc_read_status_one(tdev, 0x35);
	return ((hstat << 8) | lstat); // 8 bit
}

static bool touch_sector_erase(struct thp_device *tdev, u32 addr)
{
	u32 value = 0;

	fmc_write_enable(tdev);
	value = 0x1;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CFG, (u8 *)&value, sizeof(value));
	value = 0xff;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_INT_CLR, (u8 *)&value, sizeof(value));
	value = 0x20;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_CMD, (u8 *)&value, sizeof(value));
	value = addr;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_ADDRL, (u8 *)&value, sizeof(value));
	value = 0x30;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP_CFG, (u8 *)&value, sizeof(value));
	value = 0xC1;
	touch_driver_spi_write_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
	u32 time_out_cnt = 0;
	do {
		touch_driver_spi_read_with_invert(tdev, TC_REG_BASE_FMC + TC_REG_FMC_OP, (u8 *)&value, sizeof(value));
		value |= fmc_read_status(tdev);

		time_out_cnt++;
		if (time_out_cnt > FMC_READ_TIMEOUT_CNT)
			break;
	} while (tc_get_bit(value, 0) != 0x0);
	return true;
}

static bool query_is_wait_status(struct thp_device *tdev)
{
	unsigned int value = 0;
	int recv_val = 0;

	if (touch_driver_spi_read_with_invert(tdev, STATUS_REG_ADDR, (u8 *)(&value), sizeof(u32)) != 0) {
		thp_log_err("read STATUS_REG_ADDR failed");
		return false;
	}
	thp_log_info("value: 0x%x", value);

	recv_val = cropping(value, 1, 1);
	if (recv_val != 1) {
		thp_log_info("not wait status");
		return false;
	}

	thp_log_info("enter wait status");
	return true;
}

static int query_wait_status(struct thp_device *tdev)
{
	thp_log_info("querying the wait status of the cpu\n");
	// wakeup ic
	touch_driver_send_wakeup(tdev);
	msleep(CMD_WAIT_COMPLETE);
	if (!touch_sector_erase(tdev, MAGIC_NUMBE_FLASH_ADDRESS)) {
		thp_log_err("erase magic num from flash failed\n");
		return -EINVAL;
	}

	reset_device(tdev);
	if (query_is_wait_status(tdev) == false) {
		thp_log_err("enter wait status failed\n");
		return -EINVAL;
	}
	return 0;
}

static bool move_to_flash_by_two(struct thp_device *tdev,
	unsigned int flash_addr, unsigned int sRam_addr, unsigned int length)
{
	int val = 0;

	if (!wr_enable(tdev)) {
		thp_log_err("wr_enable failed");
		return false;
	}
	val = 0xff;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_INT_CLR, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc int clr 0x%x failed", val);
		return false;
	}
	val = 0x30;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_OP_CFG, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc op cfg 0x%x failed", val);
		return false;
	}
	val = flash_addr;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_ADDRL, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc addrl 0x%x failed.", flash_addr);
		return false;
	}
	val = sRam_addr;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_DMA_SADDR_D0, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc dma saddr 0x%x failed", sRam_addr);
		return false;
	}
	val = length;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_DMA_LEN, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc dma len 0x%x failed", length);
		return false;
	}
	val = 0x203;
	if (touch_driver_spi_write_with_invert(
		tdev, FMC_BASE_ADDR + TC_REG_FMC_OP_CTRL, (uint8_t *)(&val), sizeof(u32)) != 0) {
		thp_log_err("mw fmc op ctrl 0x%x failed", val);
		return false;
	}
	thp_log_info("move_to_flash_by_two success\n");
	return true;
}

#define MAGIC_NUMBER_LEN            20
#define CRC_TO_FLASH_LEN            16
#define MAGIC_NUMBE_VALUE           0x00ABCDEF
static bool send_magic_num_to_flash(struct thp_device *tdev)
{
	u8 magic_num_data[MAGIC_NUMBER_LEN] = {0};
	u32 magic_num = MAGIC_NUMBE_VALUE;

	(void)memset_s(magic_num_data, MAGIC_NUMBER_LEN, 0, MAGIC_NUMBER_LEN);
	(void)memcpy_s(magic_num_data + CRC_TO_FLASH_LEN, sizeof(u32), &magic_num, sizeof(u32));
	// move data to sram
	if (touch_driver_spi_write_with_invert(tdev, MAPPING_TABLE_ADDR, (u8 *)magic_num_data, MAGIC_NUMBER_LEN) != 0) {
		thp_log_err("Programe write mappting table failed.\n");
		return false;
	}
	// move data to flash
	if (!move_to_flash_by_two(tdev, MAGIC_NUMBE_FLASH_ADDRESS, MAPPING_TABLE_ADDR, MAGIC_NUMBER_LEN)) {
		thp_log_err("Move data to flash failed.\n");
		return false;
	}
	if (!get_erase_result(tdev, FLASH_WRITE_TIMEOUT, MOVE_FLASH_STATUS_REG_ADDR, MOVE_FLASH_SUCCESS_FLAG)) {
		thp_log_err("Read %d value is not %d.\n", MOVE_FLASH_STATUS_REG_ADDR, MOVE_FLASH_SUCCESS_FLAG);
		return false;
	}
	thp_log_info("send magic num to flash successfully.\n");
	return true;
}

static int get_project_id(struct thp_device *tdev, char *pid, u32 len)
{
	u32 rc = 0;
	u32 count = 0;
	u8 report_status = 0;
	thp_log_info("%s: called \n", __func__);

	touch_driver_send_cmd(tdev, CMD_REPORT_ENABLE, &report_status, sizeof(u8), true);
	msleep(CMD_WAIT_COMPLETE);

	// query cpu status if wait status
	do {
		count++;
		if (count == 4) { // max 4 count
			thp_log_err("%s: query cpu status failed\n", __func__);
			return -EINVAL;
		}
		rc = query_wait_status(tdev);
	} while (rc != 0);

	rc = get_project_id_from_flash(tdev, pid, len);
	// write magic num back
	send_magic_num_to_flash(tdev);
	// reset ic
	reset_device(tdev);
	return rc;
}

static bool touch_driver_spi_transfer_debug(struct thp_device *tdev, const char *tx_buf)
{
	struct link_ap_cmd *ap_cmd = (struct link_ap_cmd *)tx_buf;

	if (tx_buf == NULL) {
		thp_log_err("%s: tdev is null, tx_buf is null\n", __func__);
		return -EINVAL;
	}

	// after update firmware, refresh addr
	if (ap_cmd != NULL && ap_cmd->cmd == CMD_UPDATE_FIRMWARE_POST_PROCESSING) {
		int rc;
		thp_log_info("%s: after update firmware, refresh addr\n", __func__);
		rc = touch_driver_get_reg_addr(tdev);
		if (rc)
			thp_log_err("%s: failed get regs data\n", __func__);
		return true;
	}

	return false;
}

static int touch_driver_spi_transfer(struct thp_device *tdev, const char *tx_buf,
	char *rx_buf, u32 len)
{
	struct thp_core_data *cd;
	struct spi_transfer xfer = {
		.tx_buf = tx_buf,
		.rx_buf = rx_buf,
		.len = len,
	};
	struct spi_message msg;
	int rc;

	if (tdev == NULL || tx_buf == NULL) {
		thp_log_err("%s: tdev is null, tx_buf is null\n", __func__);
		return -EINVAL;
	}
	if (touch_driver_spi_transfer_debug(tdev, tx_buf))
		return 0;

	spi_message_init(&msg);
	spi_message_add_tail(&xfer, &msg);

	rc = thp_bus_lock(tdev);
	if (rc < 0) {
		thp_log_err("%s: get lock failed\n", __func__);
		return -EINVAL;
	}
#ifndef CONFIG_HUAWEI_THP_MTK
	thp_spi_cs_set(GPIO_HIGH);
#endif
	cd = thp_get_core_data(tdev->thp_core->panel_id);
	if (cd == NULL) {
		thp_log_err("%s: get thp_get_core_data failed\n", __func__);
		thp_bus_unlock(tdev);
		return -EINVAL;
	}
	rc = spi_sync(cd->sdev, &msg);
	if (rc < 0) {
		thp_log_err("%s: spi_sync failed\n", __func__);
		thp_bus_unlock(tdev);
		return -EINVAL;
	}
	thp_bus_unlock(tdev);

	return rc;
}

static int touch_driver_chip_detect(struct thp_device *tdev)
{
	int rc;
	thp_log_info("%s: called \n", __func__);

	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	rc = touch_driver_power_init(tdev->thp_core->panel_id);
	if (rc)
		thp_log_err("%s: power init failed\n", __func__);

	rc = touch_driver_power_on(tdev, tdev->thp_core->panel_id);
	if (rc)
		thp_log_err("%s: power on failed\n", __func__);

	rc = touch_driver_get_reg_addr(tdev);
	if (rc) {
		(void)touch_driver_power_off(tdev, tdev->thp_core->panel_id);
		touch_driver_power_release(tdev, tdev->thp_core->panel_id);
		thp_log_err("%s: failed get regs data\n", __func__);
		goto exit;
	}
	pen_clk_control(CLK_ENABLE, tdev->thp_core->panel_id);
	thp_log_info("[xhs]%s: succ\n", __func__);
	return 0;
exit:
	thp_log_info("[xhs]%s: failed\n", __func__);
	if (tdev->thp_core->support_adapter_mode)
		thp_power_adapter_release(&tdev->thp_core->power_adapter);
	if (tdev->thp_core->fast_booting_solution) {
		kfree(tdev->tx_buff);
		tdev->tx_buff = NULL;
		kfree(tdev->rx_buff);
		tdev->rx_buff = NULL;
		kfree(tdev);
		tdev = NULL;
	}
	return rc;
}

static int touch_driver_get_frame(struct thp_device *tdev, char *buf, u32 len)
{
	int rc;
	u32 value;

	if ((tdev == NULL) || (buf == NULL)) {
		thp_log_err("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if (!len) {
		thp_log_err("%s: read len illegal\n", __func__);
		return -ENOMEM;
	}
	if (g_hisi_frame_addr == 0 || g_hisi_report_addr == 0) {
		thp_log_err("%s: frame addr or report addr is 0\n", __func__);
		return -EINVAL;
	}

	value = FRAME_SYNC_CODE;
	rc = touch_driver_spi_read(tdev, g_hisi_frame_addr, buf, len);
	if (rc) {
		touch_driver_spi_write(tdev, g_hisi_report_addr, (u8 *)&value, sizeof(u32));
		thp_log_err("%s: read frame failed", __func__);
		return rc;
	}

	rc = touch_driver_spi_write(tdev, g_hisi_report_addr, (u8 *)&value, sizeof(u32));
	if (rc) {
		thp_log_err("%s: write FRAME_SYNC_CODE failed", __func__);
		return rc;
	}

	return rc;
}

static int touch_driver_get_project_id(struct thp_device *tdev, char *buf, u32 len)
{
	thp_log_info("%s: called \n", __func__);
	char pid[PROJ_ID_INFO_LEN] = {0};
	u32 copy_len;
	int rc;

	if ((tdev == NULL) || (buf == NULL)) {
		thp_log_err("%s: tdev or buf is null\n", __func__);
		return -EINVAL;
	}

	if (get_project_id(tdev, pid, PROJ_ID_INFO_LEN) != 0) {
		thp_log_err("%s: get_project_id failed\n", __func__);
		return -EINVAL;
	}
	(void)memset_s(buf, len, 0, len);
	rc = memcpy_s(buf, len, pid, TOUCH_PROJECT_ID_LEN);
	if (rc) {
		thp_log_err("%s: memcpy_s error:%d\n", __func__, rc);
		return rc;
	}
	thp_log_info("%s: len %d pid is %s, buf is %s\n", __func__, len, pid, buf);
	return 0;
}

static int touch_driver_after_resume(struct thp_device *tdev)
{
	thp_log_info("%s: called \n", __func__);
	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	thp_do_time_delay(tdev->timing_config.boot_reset_after_delay_ms);
	return 0;
}

static int touch_driver_wakeup_gesture_enable_switch(struct thp_device *tdev, u8 switch_value)
{
	int rc;
	u32 gesture;
	u8 cmdPara[DATA4];

	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	thp_log_info("%s: switch_value %d\n", __func__, switch_value);
	if ((switch_value & THP_AFE_GESTURE_DOUBLE_CLICK) != 0) {
		gesture = THP_AFE_GESTURE_SINGLE_CLICK | THP_AFE_GESTURE_DOUBLE_CLICK;
	} else if ((switch_value & THP_AFE_GESTURE_SINGLE_CLICK) != 0) {
		gesture = THP_AFE_GESTURE_SINGLE_CLICK;
	} else {
		gesture = THP_AFE_GESTURE_NONE;
	}

	cmdPara[DATA0] = (u8)(gesture & 0xff);
	cmdPara[DATA1] = (u8)((gesture >> MOVE_8BIT) & 0xff);
	cmdPara[DATA2] = (u8)((gesture >> MOVE_16BIT) & 0xff);
	cmdPara[DATA3] = (u8)((gesture >> MOVE_24BIT) & 0xff);
	rc = touch_driver_send_cmd(tdev, CMD_ENABLE_GESTURE_FEATURE, cmdPara, sizeof(cmdPara), true);
	if (rc != 0) {
		thp_log_err("%s: gesture switch %d failed\n", __func__, gesture);
		return -EINVAL;
	}
	thp_log_info("%s: gesture switch %d success\n", __func__, gesture);
	return rc;
}

static int touch_driver_wrong_touch(struct thp_device *tdev)
{
	thp_log_info("%s: called \n", __func__);
	if (tdev == NULL) {
		thp_log_err("%s: input dev is null\n", __func__);
		return -EINVAL;
	}

	if (tdev->thp_core->support_gesture_mode) {
		mutex_lock(&tdev->thp_core->thp_wrong_touch_lock);
		tdev->thp_core->easy_wakeup_info.off_motion_on = true;
		mutex_unlock(&tdev->thp_core->thp_wrong_touch_lock);
		thp_log_info("%s, done\n", __func__);
	}
	return 0;
}

static int touch_driver_gesture_report(struct thp_device *tdev, u32 *gesture_wakeup_value)
{
	thp_log_info("%s: called \n", __func__);
	if (tdev == NULL) {
		thp_log_err("%s: input dev null\n", __func__);
		return -ENOMEM;
	}
	if (!gesture_wakeup_value) {
		thp_log_err("%s: gesture_wakeup_value is null\n", __func__);
		return -EINVAL;
	}

	return 0;
}

static int touch_driver_spi_set_mosi_low(struct thp_device *tdev)
{
	u8 *rx_buf = NULL;
	u8 *tx_buf = NULL;
	uint32_t stash_value = 0;
	int rc;
	struct spi_device *spi = NULL;
	struct spi_transfer *xfers;
	struct spi_message spi_msg;

	spi = tdev->thp_core->sdev;
	rx_buf = tdev->rx_buff;
	tx_buf = tdev->tx_buff;
	spi_message_init(&spi_msg);
	xfers = kzalloc(sizeof(struct spi_transfer), GFP_KERNEL);
	if (xfers == NULL) {
		thp_log_err("%s: kzalloc invalid xfers\n", __func__);
		return -EINVAL;
	}

	(void)memset_s(tx_buf, THP_MAX_FRAME_SIZE, 0, THP_MAX_FRAME_SIZE);
	touch_driver_spi_assign_buffer(rx_buf, tx_buf, xfers, IC_SYS_ID_ADDR, AFE_ADDR_LEN);
	spi_message_init(&spi_msg);
	spi_message_add_tail(xfers, &spi_msg);
	rc = thp_spi_sync(spi, &spi_msg);
	if (rc < 0) {
		thp_log_err("%s: spi transfer error:%d\n", __func__, rc);
		goto out;
	}
	rc = memcpy_s((uint8_t *)&stash_value, AFE_ADDR_LEN, &rx_buf[SPI_READ_OFFSET], AFE_ADDR_LEN);
	if (rc) {
		thp_log_err("%s: memcpy_s error:%d\n", __func__, rc);
		goto out;
	}
	invert_uint32(&stash_value, AFE_ADDR_LEN);
	thp_log_info("%s: stash_value: 0x%x", __func__, stash_value);

out:
	kfree(xfers);
	return rc;
}

static int touch_driver_reset(struct thp_device *tdev)
{
	int rc = 0;

	if (!tdev->thp_core->hard_reset_in_special_mode) {
		reset_device(tdev);
		return rc;
	}

	touch_driver_send_wakeup(tdev);
	msleep(1);
	rc = thp_bus_lock(tdev);
	if (rc < 0) {
		thp_log_err("%s: get lock failed:%d\n", __func__, rc);
		return rc;
	}

	rc = touch_driver_spi_set_mosi_low(tdev);
	if (rc < 0) {
		thp_bus_unlock(tdev);
		thp_log_err("%s: touch_driver_spi_set_low failed:%d\n", __func__, rc);
		return rc;
	}

	reset_device(tdev);
	thp_bus_unlock(tdev);
	return rc;
}

static int touch_driver_resume(struct thp_device *tdev)
{
	int rc;
	u32 gesture_flag = 0;
	u32 stylus_status = 0;
	struct thp_core_data *cd = NULL;

	thp_log_info("%s: called \n", __func__);
	if (!tdev || !tdev->thp_core) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}

	cd = tdev->thp_core;
	gesture_flag = (cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE);
	gesture_flag = (gesture_flag || cd->suspend_udfp_status);
	stylus_status = !!(thp_get_status(THP_STATUS_STYLUS, cd->panel_id)) |
					cd->suspend_stylus3_status;
	gesture_flag = (gesture_flag || stylus_status);
	gesture_flag = (gesture_flag || cd->aod_touch_status);

	// power test, reset
	if (is_pt_test_mode(tdev))
		rc = touch_driver_reset(tdev);

	// gesture mode
	if (gesture_flag || need_power_off)
		rc = touch_driver_reset(tdev);
	else
		rc = touch_driver_power_on(tdev, tdev->thp_core->panel_id);

	pen_clk_control(CLK_ENABLE, tdev->thp_core->panel_id);
	return rc;
}

static int touch_driver_switch_pen_clk(struct thp_device *tdev)
{
	int rc;

	msleep(CMD_WAIT_COMPLETE);
	u8 cmdPara[] = { 0 };
	rc = touch_driver_send_cmd(tdev, CMD_AFE_SET_CLOCK_SOURCE, cmdPara, sizeof(cmdPara), true);
	if (rc)
		thp_log_err("%s: send set cur clock failed", __func__);

	msleep(CMD_WAIT_COMPLETE);
	return rc;
}

#ifdef CONFIG_HUAWEI_SHB_THP
#define INPUTHUB_POWER_SWITCH_START_BIT 9
#define INPUTHUB_POWER_SWITCH_START_OFFSET 1
static void touch_driver_poweroff_status(struct thp_device *tdev)
{
	struct thp_core_data *cd = thp_get_core_data(tdev->thp_core->panel_id);
	unsigned int finger_status = !!(thp_get_status(THP_STATUS_UDFP, cd->panel_id));
	unsigned int stylus_status = !!(thp_get_status(THP_STATUS_STYLUS, cd->panel_id)) |
		!!(thp_get_status(THP_STATUS_STYLUS3, cd->panel_id));

	cd->poweroff_function_status =
		(cd->double_click_switch << THP_DOUBLE_CLICK_ON) |
		(finger_status << THP_TPUD_ON) |
		(cd->ring_setting_switch << THP_RING_SUPPORT) |
		(cd->ring_switch << THP_RING_ON) |
		(stylus_status << THP_PEN_MODE_ON) |
		(cd->phone_status << THP_PHONE_STATUS) |
		(cd->single_click_switch << THP_SINGLE_CLICK_ON) |
		(cd->volume_side_status << THP_VOLUME_SIDE_STATUS_LEFT);
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

static int touch_driver_suspend_gesture(struct thp_device *tdev)
{
	int rc;
	u8 pm[2];
	u8 report_status = 0;
	int param_size = 0;

	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
#ifdef CONFIG_HUAWEI_SHB_THP
	if (tdev->thp_core->support_shb_thp)
		touch_driver_poweroff_status(tdev);
#endif
	rc = touch_driver_send_cmd(tdev, CMD_REPORT_ENABLE, &report_status, 1, true);
	msleep(1);
	rc = touch_driver_switch_pen_clk(tdev);
	if (rc)
		thp_log_err("%s: failed to change to pen clk\n", __func__);

	pm[0] = TOUCH_WOKR_MODE_GESTURE;
	pm[1] = 1;
	param_size = 2; // 2 bytes
	rc = touch_driver_send_cmd(tdev, CMD_CHANGE_TOUCH_WORK_MODE, pm, param_size, true);
	if (rc)
		thp_log_err("%s: failed to change to gesture\n", __func__);

	msleep(1);
	return rc;
}

static int touch_driver_suspend_poweroff(struct thp_device *tdev)
{
	int rc;

	/* 0:all function was closed */
	if (tdev->thp_core->support_shb_thp)
		tdev->thp_core->poweroff_function_status = 0;

	rc = touch_driver_power_off(tdev, tdev->thp_core->panel_id);
	if (rc)
		thp_log_err("%s: power off falied\n", __func__);
	msleep(CMD_WAIT_COMPLETE);
	return rc;
}

#define TS_AOD_MODE 1
static int touch_driver_gesture_enable_switch(struct thp_device *tdev, int gesture_mode, int aod_mode)
{
	int rc;
	struct thp_core_data *cd = NULL;

	if (!tdev || !tdev->thp_core) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;

	if (cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE) {
		rc = touch_driver_wakeup_gesture_enable_switch(tdev, THP_AFE_GESTURE_DOUBLE_CLICK);
	} else if (cd->aod_touch_status == TS_AOD_MODE) {
		rc = touch_driver_wakeup_gesture_enable_switch(tdev, THP_AFE_GESTURE_SINGLE_CLICK);
	} else {
		rc = touch_driver_wakeup_gesture_enable_switch(tdev, THP_AFE_GESTURE_NONE);
	}
	return rc;
}

static int touch_driver_suspend(struct thp_device *tdev)
{
	int rc;
	int param_size = 0;
	u8 pm[2];
	u32 stylus_status = 0;
	u32 gesture_flag = 0;
	struct thp_core_data *cd = NULL;

	if (!tdev || !tdev->thp_core) {
		thp_log_err("%s: tdev is null\n", __func__);
		return -EINVAL;
	}
	cd = tdev->thp_core;

	gesture_flag = (cd->easy_wakeup_info.sleep_mode == TS_GESTURE_MODE);
	gesture_flag = (gesture_flag || cd->suspend_udfp_status);
	stylus_status = !!(thp_get_status(THP_STATUS_STYLUS, cd->panel_id)) |
					cd->suspend_stylus3_status;
	gesture_flag = (gesture_flag || stylus_status);
	gesture_flag = (gesture_flag || cd->aod_touch_status);

	thp_log_info("%s:gesture_status:%d,udfp status:%u\n",
		__func__, cd->easy_wakeup_info.sleep_mode, cd->suspend_udfp_status);
	thp_log_info("%s:stylus_status:%u,aod_touch_status:%u\n", __func__,
		stylus_status, cd->aod_touch_status);
	touch_driver_send_wakeup(tdev);
	msleep(CMD_WAIT_COMPLETE);
	if (is_pt_test_mode(tdev)) {
		cd->need_work_in_suspend = true;
		pm[0] = TOUCH_WOKR_MODE_SLEEP;
		pm[1] = 1;
		param_size = 2; // 2 bytes
		rc = touch_driver_send_cmd(tdev, CMD_CHANGE_TOUCH_WORK_MODE, pm, param_size, true);
		gpio_set_value(tdev->gpios->cs_gpio, 0);
		cd->need_work_in_suspend = false;
		return rc;
	}

	thp_log_info("%s:gesture_flag:%u\n", __func__, gesture_flag);
	if (gesture_flag) {
		need_power_off = SUSPEND_GESTURE_MODE;
		rc = touch_driver_suspend_gesture(tdev);
		pen_clk_control(CLK_DISABLE, cd->panel_id);
		if (cd->use_ap_gesture)
			touch_driver_gesture_enable_switch(tdev, cd->easy_wakeup_info.sleep_mode, cd->aod_touch_status);
	} else {
		need_power_off = SUSPEND_POWER_OFF;
		rc = touch_driver_suspend_poweroff(tdev);
	}

	return rc;
}

static void touch_driver_exit(struct thp_device *tdev)
{
	thp_log_info("%s: called \n", __func__);
	if (tdev == NULL) {
		thp_log_err("%s: tdev is null\n", __func__);
		return;
	}
	if (tdev->tx_buff)
		kfree(tdev->tx_buff);
	tdev->tx_buff = NULL;
	if (tdev->rx_buff)
		kfree(tdev->rx_buff);
	tdev->rx_buff = NULL;
	kfree(tdev);
	tdev = NULL;
}

#ifdef CONFIG_HUAWEI_SHB_THP
static int touch_driver_switch_int_sh(struct thp_device *tdev)
{
	thp_log_info("%s: called\n", __func__);
	if (tdev->thp_core->use_ap_sh_common_int && tdev->thp_core->support_pinctrl)
		return thp_pinctrl_select_lowpower(tdev->thp_core->thp_dev);

	return 0;
}

static int touch_driver_switch_int_ap(struct thp_device *tdev)
{
	thp_log_info("%s: called\n", __func__);
	if (tdev->thp_core->use_ap_sh_common_int && tdev->thp_core->support_pinctrl)
		return thp_pinctrl_select_normal(tdev->thp_core->thp_dev);

	return 0;
}
#endif

static int touch_driver_afe_notify_callback(struct thp_device *tdev,
	unsigned long event)
{
	if (tdev == NULL) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}

	return touch_driver_get_reg_addr(tdev);
}

#define STR_LEN 256
static void common_read_reg_and_print(struct thp_device *tdev, u32 addr, u32 len)
{
	const u32 maxReadLen = (THP_MAX_FRAME_SIZE - SPI_RW_OFFSET) / (sizeof(unsigned int) * sizeof(unsigned int));
	u8 buffer[maxReadLen] = {0};
	u32 *ptr = NULL;
	u8 data[STR_LEN] = {0};
	int remainiLen = 0;
	int printLen = 0;
	int i = 0;
	int idx = 0;

	if (len > maxReadLen || len % sizeof(unsigned int) != 0) {
		thp_log_err("%s: len: %d error\n", __func__, len);
		return;
	}

	if (touch_driver_spi_read(tdev, addr, buffer, len) != 0) {
		thp_log_err("%s: spi read: 0x%x failed\n", __func__, addr);
		return;
	}

	ptr = (u32 *)buffer;
	remainiLen = len / sizeof(unsigned int);

	for (i = 0; i < (len / sizeof(unsigned int)); i++) {
		memset_s(data, sizeof(data), 0, sizeof(data));
		printLen = remainiLen > 8 ? 8 : remainiLen; // Print 8 addresses per line
		for (idx = 0; idx < printLen; idx++) {
			(void)sprintf_s(data + strlen(data), sizeof(data) - strlen(data), " 0x%08x", ptr[idx]);
		}
		thp_log_info("0x%x: %s.", addr + i * 32, data);
		remainiLen = remainiLen - printLen;
		if (remainiLen <= 0) {
			break;
		}
		ptr += printLen;
	}
}

#define SKIP_CRC_BYTES 4
static int touch_driver_check_gesture_data(struct thp_device *tdev, u8 *touch_data, u32 len)
{
	u16 frameLen = 0;
	u16 icCrc = 0;
	u16 crc = 0;
	u16 reportType = 0;

	if (len > SPI_MAX_DATA_LEN) {
		thp_log_err("length: %d error\n", len);
		return -1;
	}
	common_read_reg_and_print(tdev, CALL_STACK_ADDR2, CALL_STACK_LEN2);

	frameLen = *(u16*)(touch_data + sizeof(u32) + sizeof(u16));
	if (frameLen < sizeof(u32) || frameLen > SPI_MAX_DATA_LEN) {
		thp_log_err("frameLen: %d error\n", frameLen, reportType);
		return -1;
	}
	icCrc = *(u16*)(touch_data);
	crc = calc_xmode_crc16(touch_data + SKIP_CRC_BYTES, frameLen - SKIP_CRC_BYTES);
	if (crc != icCrc) {
		thp_log_err("CRC verification failed! icCrc: %d, crc: %d frameLen: %d\n", icCrc, crc, frameLen);
		return -1;
	}

	reportType = *(u16*)(touch_data + sizeof(u32));
	if (reportType != TOUCH_REPORT_GES_FRAME) {
		thp_log_err("reportType: %d error\n", reportType);
		return -1;
	}

	return 0;
}

static int touch_driver_get_event_info(struct thp_device *tdev, struct thp_udfp_data *udfp_data)
{
	int ret;
	u32 value;
	u8 touch_data[SPI_MAX_DATA_LEN];
	u32 *data;

	if (tdev == NULL || udfp_data == NULL) {
		thp_log_err("%s: input dev or udfp_data is null\n", __func__);
		return -EINVAL;
	}

	ret = touch_driver_spi_read(tdev, g_hisi_frame_addr, touch_data, SPI_MAX_DATA_LEN);
	if (ret) {
		thp_log_err("%s: read frame failed\n", __func__);
		goto out;
	}

	invert_uint32((u32 *)touch_data, SPI_MAX_DATA_LEN);
	if (touch_driver_check_gesture_data(tdev, touch_data, SPI_MAX_DATA_LEN) < 0) {
		goto out;
	}
	data = (u32 *)(touch_data + 16); // prefix data

	// tp_x
	udfp_data->tpud_data.tp_x = data[0];
	// tp_y
	udfp_data->tpud_data.tp_y = data[1];
	// tp_fingersize
	udfp_data->tpud_data.tp_fingersize = data[2];
	// tp_peak
	udfp_data->tpud_data.tp_peak = data[3];
	// aod_event
	udfp_data->aod_event = data[4];
	// key_event
	udfp_data->key_event = data[5];

	udfp_data->tpud_data.tp_major = data[7];
	udfp_data->tpud_data.tp_minor = data[8];
	udfp_data->tpud_data.tp_ori = data[9];

	// not reported
	udfp_data->tpud_data.tp_event = data[6];
	udfp_data->tpud_data.version = data[10];
	udfp_data->tpud_data.tp_source = data[11]; // max_diff is no have place to put it
	udfp_data->tpud_data.mis_touch_count_area = data[12];
	udfp_data->tpud_data.tp_coverage = data[13];
	udfp_data->tpud_data.touch_to_fingerdown_time = data[14];
	udfp_data->tpud_data.pressure = data[15];
	udfp_data->tpud_data.mis_touch_count_pressure = data[16];

	thp_log_info("%s: aod:%u, key:%u, fingersize:%u, x:%d, y=%d\n", __func__,
		udfp_data->aod_event, udfp_data->key_event,
		udfp_data->tpud_data.tp_fingersize, udfp_data->tpud_data.tp_x, udfp_data->tpud_data.tp_y);
	if (udfp_data->key_event == DOUBLE_TAP_FLAG)
		udfp_data->key_event = TS_DOUBLE_CLICK;
out:
	value = FRAME_SYNC_CODE;
	ret = touch_driver_spi_write(tdev, g_hisi_report_addr, (u8 *)&value, sizeof(u32));
	if (ret) {
		thp_log_err("%s: write 0xFFFFFFFF failed\n", __func__);
	}

	return ret;
}

static int touch_driver_set_lowpower_state(struct thp_device *tdev, u8 state)
{
	int ret;
	thp_log_info("%s: status: %d\n", __func__, state);
	if (tdev == NULL || tdev->thp_core == NULL) {
		thp_log_err("%s: have null ptr\n", __func__);
		return -EINVAL;
	}
	if (tdev->thp_core->work_status != SUSPEND_DONE) {
		thp_log_info("%s: resumed, not handle lp\n", __func__);
		return 0;
	}

	u8 cmdPara[] = {0x5a, 0x5a, 0x5a, 0x5a, 0, 0, 0};  // 0x5a is special code for wakeup tpic
	ret = touch_driver_send_cmd(tdev, CMD_PERIPH_WAKEUP, cmdPara, sizeof(cmdPara), false);
	if (ret)
		goto out;
	msleep(CMD_WAIT_COMPLETE);

	if (state) {
		u8 cmdReportPara[] = { 0 };
		ret = touch_driver_send_cmd(tdev, CMD_REPORT_ENABLE, cmdReportPara, sizeof(u8), true);
		if (ret)
			goto out;

		u8 cmdModePara[] = {TOUCH_WOKR_MODE_CFG, 1};
		ret = touch_driver_send_cmd(tdev, CMD_CHANGE_TOUCH_WORK_MODE, cmdModePara, sizeof(cmdModePara), true);
		if (ret)
			goto out;
	} else {
		u8 cmdReportPara[] = { 1 };
		ret = touch_driver_send_cmd(tdev, CMD_REPORT_ENABLE, cmdReportPara, sizeof(u8), true);
		if (ret)
			goto out;
		u8 cmdPara[] = {TOUCH_WOKR_MODE_GESTURE, 1};
		ret = touch_driver_send_cmd(tdev, CMD_CHANGE_TOUCH_WORK_MODE, cmdPara, sizeof(cmdPara), true);
		if (ret)
			goto out;
	}
out:
	if (ret)
		thp_log_err("%s: failed set lowpower_mode\n", __func__);

	return ret;
}

static int touch_driver_set_aod_state(struct thp_device *tdev, u8 state, struct thp_aod_window window)
{
	if (!tdev) {
		thp_log_err("%s: tdev null\n", __func__);
		return -EINVAL;
	}

	thp_log_info("%s: state %u, x0: %u, y0: %u, x1: %u, y1: %u\n", __func__,
		state, window.x0, window.y0, window.x1, window.y1);

	return 0;
}

struct thp_device_ops hisilicon_dev_ops = {
	.reset = touch_driver_reset,
	.init = touch_driver_init,
	.detect = touch_driver_chip_detect,
	.get_frame = touch_driver_get_frame,
	.get_project_id = touch_driver_get_project_id,
	.resume = touch_driver_resume,
	.after_resume = touch_driver_after_resume,
	.spi_transfer = touch_driver_spi_transfer,
	.chip_wakeup_gesture_enable_switch = touch_driver_wakeup_gesture_enable_switch,
	.chip_wrong_touch = touch_driver_wrong_touch,
	.chip_gesture_report = touch_driver_gesture_report,
	.suspend = touch_driver_suspend,
	.exit = touch_driver_exit,
#ifdef CONFIG_HUAWEI_SHB_THP
	.switch_int_sh = touch_driver_switch_int_sh,
	.switch_int_ap = touch_driver_switch_int_ap,
#endif
	.afe_notify = touch_driver_afe_notify_callback,
	.get_event_info = touch_driver_get_event_info,
	.tp_lowpower_ctrl = touch_driver_set_lowpower_state,
	.tp_aod_event_ctrl = touch_driver_set_aod_state,
};

static int thp_module_init(u32 panel_id)
{
	int rc = 0;
	struct thp_device *dev = NULL;
	struct thp_core_data *cd = thp_get_core_data(panel_id);
	thp_log_info("%s: called \n", __func__);

	dev = kzalloc(sizeof(struct thp_device), GFP_KERNEL);
	if (!dev) {
		thp_log_err("%s: thp device malloc failed\n", __func__);
		return -ENOMEM;
	}
	dev->tx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	dev->rx_buff = kzalloc(THP_MAX_FRAME_SIZE, GFP_KERNEL);
	if (!dev->tx_buff || !dev->rx_buff) {
		thp_log_err("%s: out of memory\n", __func__);
		rc = -ENOMEM;
		goto error;
	}

	dev->ic_name = HISILICON_IC_NAME;
	dev->dev_node_name = THP_HISI_DEV_NODE_NAME;
	dev->ops = &hisilicon_dev_ops;

	if (cd && cd->fast_booting_solution) {
		thp_log_err("%s: send cmd when fast boot solution is true \n", __func__);
		/*
		* The thp_register_dev will be called later to complete
		* the real detect action. If it fails, the detect function will
		* release the resources requested here.
		*/
		thp_send_detect_cmd(dev, panel_id, NO_SYNC_TIMEOUT);
		return 0;
	}
	rc = thp_register_dev(dev, panel_id);
	if (rc) {
		thp_log_err("%s: register fail \n", __func__);
		goto error;
	}
	thp_log_info("%s: register success \n", __func__);
	return rc;
error:
	if (dev) {
		if (dev->rx_buff)
			kfree(dev->rx_buff);
		dev->rx_buff = NULL;
		if (dev->tx_buff)
			kfree(dev->tx_buff);
		dev->tx_buff = NULL;
		kfree(dev);
		dev = NULL;
	}
	return rc;
}

static int __init touch_driver_module_init(void)
{
	int rc = 0;
	struct device_node *dn = NULL;
	u32 i;

	thp_log_info("%s: called \n", __func__);
	for (i = 0; i < TOTAL_PANEL_NUM; i++) {
		dn = get_thp_node(i);
		if (dn && of_get_child_by_name(dn, THP_HISI_DEV_NODE_NAME))
			rc = thp_module_init(i);
	}
	thp_log_info("%s: end \n", __func__);
	return rc;
}

static void __exit touch_driver_module_exit(void)
{
	thp_log_info("%s: called \n", __func__);
};

#ifdef CONFIG_HUAWEI_THP_QCOM
late_initcall(touch_driver_module_init);
#else
module_init(touch_driver_module_init);
#endif
module_exit(touch_driver_module_exit);
MODULE_AUTHOR("hisilicon");
MODULE_DESCRIPTION("hisilicon driver");
MODULE_LICENSE("GPL");
