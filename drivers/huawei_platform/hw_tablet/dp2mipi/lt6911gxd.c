/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * lt6911gxd.c
 *
 * lt6911gxd dp2mipi driver
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
#include <linux/device.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/interrupt.h>
#include <linux/of_gpio.h>
#include <linux/irq.h>
#include <linux/time.h>
#include <linux/proc_fs.h>
#include <securec.h>
#include "huawei_platform/ospm/usb/multi_port/cs32g050/hw_cs32g050.h"
#include "hw_lt6911gxd.h"
#include <platform_include/cee/linux/ulsr.h>
#include "lt6911gxd.h"
#include "lt6911gxd_fw.h"
#include "dpin_params_notify.h"

#ifdef CONFIG_HUAWEI_PLATFORM
#include <huawei_platform/log/log_exception.h>
#include <huawei_platform/log/hw_log.h>
#define HWLOG_TAG lt6911gxd
HWLOG_REGIST();
#else
#define hwlog_debug(fmt, args...) pr_debug("[lt6911gxd]" fmt, ##args)
#define hwlog_info(fmt, args...) pr_info("[lt6911gxd]" fmt, ##args)
#define hwlog_warn(fmt, args...) pr_warn("[lt6911gxd]" fmt, ##args)
#define hwlog_err(fmt, args...) pr_err("[lt6911gxd]" fmt, ##args)
#endif /* CONFIG_HUAWEI_PLATFORM */

#define POWER_ON_1V2_DELAY_MS 5
#define POWER_ON_3V3_DELAY_MS 25
#define POWER_OFF_3V3_DELAY_MS 5
#define RESET_OFF_ON_DELAY_MS 30
#define WAIT_HPD_MS 10
#define WAIT_HPD_TIMES 200

#define READ_REG_CHIP_ID_H 0x00
#define READ_REG_CHIP_ID_L 0x01

#define READ_REG_CHIP_NAME_H 0x80
#define READ_REG_CHIP_NAME_L 0x81

#define READ_REG_VERSION_H 0x82
#define READ_REG_VERSION_L 0x83

#define READ_REG_INTERRUPT_TYPE 0x84

#define READ_REG_PCLOCK_THIRD 0x85
#define READ_REG_PCLOCK_SECOND 0x86
#define READ_REG_PCLOCK_FIRST 0x87

#define READ_REG_HTOTAL_H 0x88
#define READ_REG_HTOTAL_L 0x89

#define READ_REG_VTOTAL_H 0x8A
#define READ_REG_VTOTAL_L 0x8B

#define READ_REG_HACTIVE_H 0x8C
#define READ_REG_HACTIVE_L 0x8D

#define READ_REG_VACTIVE_H 0x8E
#define READ_REG_VACTIVE_L 0x8F

#define READ_REG_AUDIO_FS_HIGH 0x90
#define READ_REG_AUDIO_FS_LOW 0x91

#define READ_REG_BYTE_CLOCK_THIRD 0x92
#define READ_REG_BYTE_CLOCK_SECOND 0x93
#define READ_REG_BYTE_CLOCK_FIRST 0x94

#define READ_REG_LANE_NUMBER 0xA0
#define READ_REG_PORT_NUMBER 0xA1
#define READ_REG_AUX_STATUS 0xAA

#define WRITE_BANK_REG 0xff
#define BANK_E0 0xe0
#define BANK_E1 0xe1
#define ONE_BYTE_BITS 8
#define TWO_BYTE_BITS 16
#define THREE_BYTE_BITS 24

#define WRITE_REG_ENABLE_MIPI 0xB0
#define SET_EVENTS_TYPE_SLEEP 5
#define LT6911GXD_POWER_ON_RESET_SLEEP 100
#define LT6911GXD_GET_HPD_STATUS_TIMES 50
#define LT6911GXD_GET_HPD_STATUS_SLEEP 10
#define LT6911GXD_GET_AUX_STATUS_TIMES 50
#define LT6911GXD_GET_AUX_STATUS_SLEEP 10
#define SIGNAL_IS_APPEAR 1
#define SIGNAL_IS_DISAPPEAR 0
#define PLUG_IN 1
#define PLUG_OUT 0
#define DPIN_MODE_ON 1
#define DPIN_MODE_OFF 0
#define NUMBER_ONE 1
#define NUMBER_TWO 2
#define NUMBER_THREE 3
#define NUMBER_FOUR 4
#define NUMBER_FIVE 5
#define NUMBER_SIX 6
#define NUMBER_SEVEN 7
#define NUMBER_EIGHT 8
#define NUMBER_NINE 9
#define VIDEO_DISAPPEAR 0
#define VIDEO_APPEAR 1
#define AUDIO_APPEAR 2
#define PIXEL_UNIT 1000
#define LT6911GXD_DELAY_GET_HPD_STATUS_TIME 50
#define LT6911GXD_DELAY_SEND_ATTENTION_TIME 500
#define LT6911GXD_DELAY_SEND_PLUGOUT_TIME 200
#define REQUEST_CHECK_HVACTIVE 2
#define IRQ_TYPE_VIDEO_DISAPPEAR 0
#define IRQ_TYPE_VIDEO_APPEAR 1

#define NO_AUX_CONNECT 0
#define AUX_CONNECT_SUCC 1
#define AUX_CONNECT_FAIL 2
#define SET_EVENTS_TYPE_RETRY_TIMES 3
#define READ_STREAM_INFO_RETRY_TIMES 3
#define DELAY_READ_STREAM_INFO_TIME 5

static int lt6911gxd_get_hvactive(unsigned int *h_active,
				  unsigned int *v_active);
static int lt6911gxd_get_frame(uint32_t *frame_rate);
static int lt6911gxd_get_version(unsigned short *ver);
static void lt6911gxd_get_aux_status(unsigned char *aux_status);
static void stream_work_handler(struct work_struct *work);
static bool is_valid_streaminfo(uint32_t hactive, uint32_t vactive);
static void process_stream_status(int intType);

static struct lt6911gxd_device *g_lt6911gxd_device = NULL;
static bool g_update_finished = false;
static int g_video_status = 0;
static int g_audio_status = 0;
static int g_dpin_status = 0;
uint16_t AT_chip_version = 0;
static struct work_struct hpd_work;
static struct work_struct stream_work;
static bool g_hpd_work_start = false;
static lt6911gxd_stream_status g_stream_status = STREAM_OFF;
#define MAX_EVENTS 10

typedef struct {
	lt6911gxd_register_module module_type;
	event_notify_t callback;
} event_registration;

event_registration lt6911gxd_event_table[MAX_EVENTS] = { 0 };

typedef struct {
	uint32_t hactive;
	uint32_t vactive;
} valid_streaminfo;

static const valid_streaminfo g_valid_streaminfo[] = { { 3296, 2472 }, { 3200, 2400 },
					  { 2560, 1920 }, { 2560, 1440 },
					  { 1920, 1080 }, { 1280, 720 } };

static void unplug_hal_params_clear(void)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_vdev->params.is_signal_appear = 0;
	g_vdev->params.is_device_support = 0;
	g_vdev->params.hactive = 0;
	g_vdev->params.vactive = 0;
	g_vdev->params.frame = 0;
	g_vdev->params.error_code = 0;
	hwlog_info("%s: clear dpin params\n", __func__);
}

static void set_events_type(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	for (int i = 0; i < SET_EVENTS_TYPE_RETRY_TIMES; ++i) {
		if (atomic_read(&g_vdev->data_ready)) {
			hwlog_info("%s: delay send events\n", __func__);
			msleep(SET_EVENTS_TYPE_SLEEP);
		}
	}
	g_vdev->params.event_type = date;
	msleep(SET_EVENTS_TYPE_SLEEP);
	hal_trigger_event();
	hwlog_info("%s: set event type = %d\n", __func__, date);
}

static void set_events_plug_status(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	if (date == g_vdev->params.plug_status) {
		return;
	}
	g_vdev->params.plug_status = date;
	hwlog_info("%s: set plug status = %d\n", __func__, date);
	if (date == PLUG_OUT) {
		unplug_hal_params_clear();
	}
	set_events_type(PLUG_STATUS_EVENT);
}

static void set_events_signal_status(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	if (date == g_vdev->params.is_signal_appear) {
		return;
	}
	g_vdev->params.is_signal_appear = date;
	if (date == 1) {
		set_events_type(VIDEO_PARAMS_EVENT);
	}
	hwlog_info("%s: set signal_appear = %d\n", __func__, date);
}

static void set_events_device_support(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_vdev->params.is_device_support = date;
	set_events_type(DEVICE_SUPPORT_EVENT);
	hwlog_info("%s: set device_support = %d\n", __func__, date);
}

static void set_events_hactive(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_vdev->params.hactive = date;
	hwlog_info("%s: set hactive = %d\n", __func__, date);
}

static void set_events_vactive(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_vdev->params.vactive = date;
	hwlog_info("%s: set vactive = %d\n", __func__, date);
}

static void set_events_frame(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_vdev->params.frame = date;
	hwlog_info("%s: set frame = %d\n", __func__, date);
}

static void set_events_error_code(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	if (date == ERROR_CODE_OK) {
		g_stream_status = STREAM_VALID;
	} else if (date == INVALID_STREAM_INFO) {
		g_stream_status = STREAM_INVALID;
	} else {
		g_stream_status = STREAM_OFF;
	}
	hwlog_info("%s: g_stream_status = %d\n", __func__, g_stream_status);
	if (date == g_vdev->params.error_code) {
		return;
	}
	g_vdev->params.error_code = date;
	hwlog_info("%s: set error_code = %d\n", __func__, date);
}

static void set_events_pd_mode(int date)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	if (date == g_vdev->params.dp_mode) {
		return;
	}
	if (date == 1 && g_vdev->params.plug_status == 1) {
		g_vdev->params.plug_status = 0;
		hwlog_err("%s: last plug status err", __func__);
	}
	g_vdev->params.dp_mode = date;
	set_events_type(DP_MODE_EVENT);
	hwlog_info("%s: set dp mode = %d\n", __func__, date);
}

void lt6911gxd_register_event(lt6911gxd_register_module type,
			      event_notify_t notify)
{
	for (int i = 0; i < MAX_EVENTS; ++i) {
		if (lt6911gxd_event_table[i].module_type == 0) {
			lt6911gxd_event_table[i].module_type = type;
			lt6911gxd_event_table[i].callback = notify;
			hwlog_info("%s: Event type %d registered.\n", __func__,
				   lt6911gxd_event_table[i].module_type);
			return;
		}
	}
	hwlog_err("%s: cannot register more events.\n", __func__);
}

static void lt6911gxd_post_event(lt6911gxd_register_module type, int event_type,
				 int event_data)
{
	hwlog_info("%s: module_type = %d event_type = %d event_date = %d\n",
		   __func__, type, event_type, event_data);
	for (int i = 0; i < MAX_EVENTS; ++i) {
		if (lt6911gxd_event_table[i].module_type == type) {
			if (lt6911gxd_event_table[i].callback) {
				lt6911gxd_event_table[i].callback(event_type,
								  event_data);
				return;
			}
		}
	}
	hwlog_err("%s: No handle for event type %d.\n", __func__, event_type);
}

static int lt6911gxd_read_byte(struct i2c_client *client, unsigned char reg,
			       unsigned char *readData)
{
	return lt6911gxd_read_block(client, reg, readData, 1);
}

static int lt6911gxd_read_n_bytes(struct i2c_client *client, unsigned char reg,
				  unsigned char *readData, unsigned int len)
{
	return lt6911gxd_read_block(client, reg, readData, len);
}

static int lt6911gxd_write_byte(struct i2c_client *client, unsigned char reg,
				unsigned char data)
{
	return lt6911gxd_write_block(client, reg, &data, 1);
}

static int lt6911gxd_write_n_bytes(struct i2c_client *client, unsigned char reg,
				   unsigned char *data, unsigned int ulLength)
{
	return lt6911gxd_write_block(client, reg, data, ulLength);
}

static int lt6911gxd_power_on(struct lt6911gxd_device *port_dev)
{
	hwlog_info("%s: in\n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	gpio_set_value(port_dev->gpio_o_1v2_power, 1);
	msleep(POWER_ON_1V2_DELAY_MS);
	gpio_set_value(port_dev->gpio_o_3v3_power, 1);
	msleep(POWER_ON_3V3_DELAY_MS);
	gpio_set_value(port_dev->gpio_o_reset, 0);
	hwlog_info("%s: success\n", __func__);
	return 0;
}

static int lt6911gxd_power_off(struct lt6911gxd_device *port_dev)
{
	hwlog_info("%s: in\n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter port_dev\n", __func__);
		return -EINVAL;
	}

	gpio_set_value(port_dev->gpio_o_3v3_power, 0);
	msleep(POWER_OFF_3V3_DELAY_MS);
	gpio_set_value(port_dev->gpio_o_1v2_power, 0);
	gpio_set_value(port_dev->gpio_o_reset, 1);
	hwlog_info("%s: success\n", __func__);
	return 0;
}

static int lt6911gxd_power_on_reset(struct lt6911gxd_device *port_dev)
{
	hwlog_info("%s: in \n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter port_dev\n", __func__);
		return -EINVAL;
	}
	int val = 0xff;
	val = gpio_get_value(port_dev->gpio_o_reset);
	hwlog_info("%s: before reset val = %d\n", __func__, val);

	gpio_set_value(port_dev->gpio_o_reset, 1);

	val = gpio_get_value(port_dev->gpio_o_reset);
	hwlog_info("%s: step1 reset val = %d\n", __func__, val);

	msleep(LT6911GXD_POWER_ON_RESET_SLEEP);

	gpio_set_value(port_dev->gpio_o_reset, 0);

	val = gpio_get_value(port_dev->gpio_o_reset);
	hwlog_info("%s: step2 reset val = %d\n", __func__, val);

	hwlog_info("%s: success \n", __func__);
	return 0;
}

static int lt6911gxd_hard_reset(struct lt6911gxd_device *port_dev)
{
	hwlog_info("%s: in\n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter port_dev\n", __func__);
		return -EINVAL;
	}

	int ret;
	ret = lt6911gxd_power_off(port_dev);
	if (ret != 0) {
		return ret;
	}
	msleep(RESET_OFF_ON_DELAY_MS);
	ret = lt6911gxd_power_on(port_dev);
	if (ret != 0) {
		return ret;
	}
	hwlog_info("%s: success\n", __func__);
	return 0;
}

static int lt6911gxd_init_gpio_config(struct lt6911gxd_device *port_dev)
{
	if (!port_dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	int ret = gpio_request_one(port_dev->gpio_i_irq, GPIOF_IN, "lt6911-irq");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio irq\n", __func__);
		return -EINVAL;
	}

	ret = gpio_request_one(port_dev->gpio_o_cc1, GPIOF_OUT_INIT_LOW, "lt6911-cc1");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio cc1\n", __func__);
		goto fail_free_irq;
	}

	ret = gpio_request_one(port_dev->gpio_i_hpd, GPIOF_IN, "lt6911-hpd");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio hpd\n", __func__);
		goto fail_free_cc1;
	}

	ret = gpio_request_one(port_dev->gpio_o_reset, GPIOF_OUT_INIT_HIGH, "lt6911-reset");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio reset\n", __func__);
		goto fail_free_hpd;
	}

	ret = gpio_request_one(port_dev->gpio_o_1v2_power, GPIOF_OUT_INIT_LOW, "lt6911-1v2-power");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio 1v2\n", __func__);
		goto fail_free_reset;
	}

	ret = gpio_request_one(port_dev->gpio_o_3v3_power, GPIOF_OUT_INIT_LOW, "lt6911-3v3-power");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio 3v3\n", __func__);
		goto fail_free_1v2;
	}

	ret = gpio_request_one(port_dev->gpio_o_mux_sel, GPIOF_OUT_INIT_LOW, "lt6911-mux-sel");
	if (ret < 0) {
		hwlog_err("%s: failed to request gpio mux\n", __func__);
		goto fail_free_3v3;
	}

	return 0;

fail_free_3v3:
	gpio_free(port_dev->gpio_o_3v3_power);
fail_free_1v2:
	gpio_free(port_dev->gpio_o_1v2_power);
fail_free_reset:
	gpio_free(port_dev->gpio_o_reset);
fail_free_hpd:
	gpio_free(port_dev->gpio_i_hpd);
fail_free_cc1:
	gpio_free(port_dev->gpio_o_cc1);

fail_free_irq:
	gpio_free(port_dev->gpio_i_irq);

	return -EINVAL;
}

static int lt6911gxd_parse_gpio_dts(struct lt6911gxd_device *port_dev)
{
	struct device_node *np = NULL;

	if (!port_dev || !port_dev->dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	np = port_dev->dev->of_node;

	port_dev->gpio_i_irq = of_get_named_gpio(np, "gpio_irq", 0);
	if (port_dev->gpio_i_irq < 0) {
		hwlog_err("%s: failed to get gpio irq\n", __func__);
		return -EINVAL;
	}

	port_dev->gpio_o_cc1 = of_get_named_gpio(np, "gpio_cc1", 0);
	if (port_dev->gpio_o_cc1 < 0) {
		hwlog_err("%s: failed to get gpio cc1\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_output(port_dev->gpio_o_cc1, 0);

	port_dev->gpio_i_hpd = of_get_named_gpio(np, "gpio_hpd", 0);
	if (port_dev->gpio_i_hpd < 0) {
		hwlog_err("%s: failed to get gpio hpd\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_input(port_dev->gpio_i_hpd);

	port_dev->gpio_o_reset = of_get_named_gpio(np, "gpio_reset", 0);
	if (port_dev->gpio_o_reset < 0) {
		hwlog_err("%s: failed to get gpio reset\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_output(port_dev->gpio_o_reset, 0);

	port_dev->gpio_o_1v2_power = of_get_named_gpio(np, "gpio_1v2_power", 0);
	if (port_dev->gpio_o_1v2_power < 0) {
		hwlog_err("%s: failed to get gpio 1v2\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_output(port_dev->gpio_o_1v2_power, 0);

	port_dev->gpio_o_3v3_power = of_get_named_gpio(np, "gpio_3v3_power", 0);
	if (port_dev->gpio_o_3v3_power < 0) {
		hwlog_err("%s: failed to get gpio 3v3\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_output(port_dev->gpio_o_3v3_power, 0);

	port_dev->gpio_o_mux_sel = of_get_named_gpio(np, "gpio_mux_sel", 0);
	if (port_dev->gpio_o_mux_sel < 0) {
		hwlog_err("%s: failed to get gpio mux\n", __func__);
		return -EINVAL;
	}
	(void)gpio_direction_output(port_dev->gpio_o_mux_sel, 0);

	return 0;
}

static int lt6911gxd_parse_dts(struct lt6911gxd_device *port_dev)
{
	if (!port_dev || !port_dev->dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	port_dev->first_update_addr = LT6911GXD_FIRMWARE_UPDATE_FIRST_ADDR;
	port_dev->firmware_update_delay = LT6911GXD_FIRMWARE_UPDATE_DELAY;
	port_dev->firmware_update_mode = LT6911GXD_FIRMWARE_UPDATE_DEFAULT_MODE;
	return 0;
}

static void lt6911gxd_fw_reset(void)
{
	if (g_lt6911gxd_device == NULL) {
		return;
	}
	(void)lt6911gxd_hard_reset(g_lt6911gxd_device);
}

static void lt6911gxd_fw_update_work(struct work_struct *work)
{
	struct device_node *node = NULL;
	struct lt6911gxd_device *port_dev = NULL;
	int ret;
	hwlog_info("%s: begin\n", __func__);
	if (!work) {
		hwlog_err("%s: invalid parameter\n", __func__);
		goto func_out;
	}

	port_dev = container_of(work, struct lt6911gxd_device,
				fw_update_work.work);
	if (!port_dev || !port_dev->dev) {
		hwlog_err("%s: devm_kzalloc port_dev failed\n", __func__);
		goto func_out;
	}

	node = port_dev->dev->of_node;
	hwlog_info("%s: firmware update begin\n", __func__);
	ret = lt6911gxd_update(port_dev->client, node,
			       port_dev->firmware_update_mode,
			       lt6911gxd_fw_reset);
	if (ret != 0) {
		hwlog_err("%s: lt6911gxd_update failed. ret =%d\n", __func__,
			  ret);
		goto func_out;
	}
	hwlog_info("%s: lt6911gxd_update success\n", __func__);
func_out:
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		return;
	}
	g_update_finished = true;
	lt6911gxd_get_version(&AT_chip_version);
	hwlog_info("%s: AT_chip_version = %u\n", __func__, AT_chip_version);
	hwlog_info("%s: update end. gpio irq value1 = %d\n", __func__,
		   gpio_get_value(g_lt6911gxd_device->irq));
	gpio_set_value(g_lt6911gxd_device->gpio_o_reset, 1);
	hwlog_info("%s: update end. gpio irq value2 = %d\n", __func__,
		   gpio_get_value(g_lt6911gxd_device->irq));
	enable_irq(g_lt6911gxd_device->irq);
	lt6911gxd_power_off(g_lt6911gxd_device);
}

static void hpd_work_handler(struct work_struct *work)
{
	g_hpd_work_start = true;
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		g_hpd_work_start = false;
		return;
	}

	hwlog_info("%s: begin\n", __func__);
	int val = 0xff;
	for (int i = 0; i < LT6911GXD_GET_HPD_STATUS_TIMES; i++) {
		if (is_ulsr()) {
			g_hpd_work_start = false;
			return;
		}
		if (gpio_get_value(g_lt6911gxd_device->gpio_o_reset) == 1) {
			g_hpd_work_start = false;
			return;
		}
		val = gpio_get_value(g_lt6911gxd_device->gpio_i_hpd);
		hwlog_info("%s times: %d  hpd_status : %d\n", __func__, i, val);
		if (val == 0x00) {
			msleep(LT6911GXD_GET_HPD_STATUS_SLEEP);
			continue;
		} else if (val == 0x01) {
			msleep(LT6911GXD_DELAY_SEND_ATTENTION_TIME);
			hwlog_info("%s: delay attention %dms\n", __func__,
				   LT6911GXD_DELAY_SEND_ATTENTION_TIME);
			lt6911gxd_post_event(PD_EVENT, DP_IN_SEND_ATTENTION,
					     DP_IN_ENABLE);
			break;
		}
	}
	if (val) {
		uint8_t aux_status = 0;
		for (int i = 0; i < LT6911GXD_GET_AUX_STATUS_TIMES; ++i) {
			lt6911gxd_get_aux_status(&aux_status);
			if (aux_status) {
				set_events_device_support(AUX_CONNECT_SUCC);
				g_hpd_work_start = false;
				return;
			}
			msleep(LT6911GXD_GET_AUX_STATUS_SLEEP);
		}
		set_events_device_support(AUX_CONNECT_FAIL);
	}
	g_hpd_work_start = false;
}

static int lt6911gxd_init_gpio(struct lt6911gxd_device *port_dev)
{
	int ret;
	hwlog_info("%s: in\n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	ret = lt6911gxd_parse_gpio_dts(port_dev);
	if (ret != 0) {
		hwlog_err("%s: lt6911gxd_parse_gpio_dts failed\n", __func__);
		return ret;
	}

	ret = lt6911gxd_init_gpio_config(port_dev);
	if (ret != 0) {
		hwlog_err("%s: lt6911gxd_init_gpio_config failed\n", __func__);
		return ret;
	}

	hwlog_info("%s: success\n", __func__);
	return 0;
}

static int lt6911gxd_i2c_pre_check(void)
{
	if (!g_update_finished) {
		hwlog_err("%s: update not finished \n", __func__);
		return DP_IN_CHIP_ECODE_UPDAE_ING;
	}

	if (!g_lt6911gxd_device || !g_lt6911gxd_device->client) {
		hwlog_err("%s: client invalid \n", __func__);
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}

	if (lt6911gxd_write_byte(g_lt6911gxd_device->client, WRITE_BANK_REG,
				 BANK_E0) != 0) {
		hwlog_err("%s: write byte failed \n", __func__);
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}

	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_version(unsigned short *ver)
{
	if (!ver) {
		hwlog_err("%s: invalid params", __func__);
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		hwlog_err("%s: i2c pre check fail ret = %d\n", __func__, ret);
		return ret;
	}

	uint8_t version[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_VERSION_H, version,
				   sizeof(version)) != 0) {
		hwlog_err("%s: i2c read byte fail\n", __func__);
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}

	*ver = ((unsigned short)version[0] << ONE_BYTE_BITS) |
	       (unsigned short)version[1];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_video_interrupt_type(unsigned char *status)
{
	if (!status) {
		hwlog_err("%s: invalid params", __func__);
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t video_status = 0;
	if (lt6911gxd_read_byte(g_lt6911gxd_device->client,
				READ_REG_INTERRUPT_TYPE, &video_status) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*status = video_status;
	return DP_IN_CHIP_ECODE_OK;
}

static void lt6911gxd_get_aux_status(unsigned char *aux_status)
{
	if (!aux_status) {
		hwlog_err("%s: invalid params", __func__);
		return;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		hwlog_err("%s: i2c pre check fail", __func__);
		return;
	}

	uint8_t status = 0;
	if (lt6911gxd_read_byte(g_lt6911gxd_device->client, READ_REG_AUX_STATUS,
				&status) != 0) {
		hwlog_err("%s: read reg aux status fail", __func__);
		return;
	}
	*aux_status = status;
}

static int lt6911gxd_get_pixel_clock_khz(unsigned int *pclock)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !pclock) {
		return ret;
	}

	uint8_t clock[NUMBER_THREE] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_PCLOCK_THIRD, clock,
				   sizeof(clock)) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*pclock = ((unsigned int)clock[0] << TWO_BYTE_BITS) |
		  ((unsigned int)clock[1] << ONE_BYTE_BITS) | clock[NUMBER_TWO];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_htotal(unsigned int *h_total)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !h_total) {
		return ret;
	}

	uint8_t htotal[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_HTOTAL_H, htotal,
				   NUMBER_TWO) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*h_total = (htotal[0] << ONE_BYTE_BITS) | htotal[NUMBER_ONE];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_vtotal(unsigned int *v_total)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !v_total) {
		return ret;
	}

	uint8_t vtotal[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_VTOTAL_H, vtotal,
				   NUMBER_TWO) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*v_total = (vtotal[0] << ONE_BYTE_BITS) | vtotal[NUMBER_ONE];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_frame(uint32_t *frame_rate)
{
	hwlog_info("%s: in\n", __func__);
	if (!frame_rate) {
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t total[NUMBER_SEVEN] = { 0 };
	uint32_t pixel_clock = 0;
	uint32_t htotal = 0;
	uint32_t vtotal = 0;
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_PCLOCK_THIRD, total,
				   sizeof(total)) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	pixel_clock = (total[0] << TWO_BYTE_BITS) |
		      (total[NUMBER_ONE] << ONE_BYTE_BITS) | total[NUMBER_TWO];
	htotal = (total[NUMBER_THREE] << ONE_BYTE_BITS) | total[NUMBER_FOUR];
	vtotal = (total[NUMBER_FIVE] << ONE_BYTE_BITS) | total[NUMBER_SIX];
	hwlog_info("%s: pixel_clock = %u, total=%u,%u\n", __func__, pixel_clock,
		   htotal, vtotal);
	if (pixel_clock == 0 || htotal == 0 || vtotal == 0) {
		*frame_rate = 0;
	} else {
		*frame_rate = (pixel_clock * PIXEL_UNIT) / (htotal * vtotal);
	}

	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_hactive(unsigned int *h_active)
{
	if (!h_active) {
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t hactive[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_HACTIVE_H, hactive,
				   NUMBER_TWO) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*h_active = (hactive[0] << ONE_BYTE_BITS) | hactive[NUMBER_ONE];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_vactive(unsigned int *v_active)
{
	if (!v_active) {
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t vactive[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_VACTIVE_H, vactive,
				   NUMBER_TWO) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*v_active = (vactive[0] << ONE_BYTE_BITS) | vactive[NUMBER_ONE];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_hvactive(unsigned int *h_active,
				  unsigned int *v_active)
{
	if (!h_active || !v_active) {
		return DP_IN_CHIP_ECODE_PARA_INVALID;
	}
	int ret = lt6911gxd_i2c_pre_check();
	hwlog_info("%s: ret = %d\n", __func__, ret);
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t active[NUMBER_FOUR] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_HACTIVE_H, active,
				   sizeof(active)) != 0) {
		hwlog_err("%s: read n bytes failed\n", __func__);
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	hwlog_info(
		"%s: active[0] = %d, active[1] = %d, active[2] = %d, active[3] = %d\n",
		__func__, active[0], active[NUMBER_ONE], active[NUMBER_TWO],
		active[NUMBER_THREE]);
	*h_active = (active[0] << ONE_BYTE_BITS) | active[1];
	*v_active = (active[NUMBER_TWO] << ONE_BYTE_BITS) |
		    active[NUMBER_THREE];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_byte_clock_khz(unsigned int *byte_clock)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !byte_clock) {
		return ret;
	}

	uint8_t clock[NUMBER_THREE] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_BYTE_CLOCK_THIRD, clock,
				   sizeof(clock)) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*byte_clock = (clock[0] << TWO_BYTE_BITS) |
		      (clock[NUMBER_ONE] << ONE_BYTE_BITS) | clock[NUMBER_TWO];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_lane_number(unsigned char *lane_num)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !lane_num) {
		return ret;
	}

	uint8_t lane = 0;
	if (lt6911gxd_read_byte(g_lt6911gxd_device->client,
				READ_REG_LANE_NUMBER, &lane) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*lane_num = lane;
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_get_port_number(unsigned char *port_num)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !port_num) {
		return ret;
	}

	uint8_t port = 0;
	if (lt6911gxd_read_byte(g_lt6911gxd_device->client,
				READ_REG_PORT_NUMBER, &port) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	*port_num = port;
	return DP_IN_CHIP_ECODE_OK;
}

static ssize_t chip_version_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	hwlog_info("%s: ver = %u\n", __func__, AT_chip_version);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n",
			  AT_chip_version);
}

static ssize_t audio_status_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	int ret = 0;
	if (g_audio_status == AUDIO_APPEAR) {
		ret = 1;
	} else {
		ret = 0;
	}
	hwlog_info("%s: ret : = %d\n", __func__, ret);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", ret);
}

static ssize_t video_status_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	int ret = 0;
	if (g_video_status == 1) {
		ret = 1;
	} else {
		ret = 0;
	}
	hwlog_info("%s: ret : = %d\n", __func__, ret);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", ret);
}

static ssize_t video_active_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	uint32_t hactive = 0;
	uint32_t vactive = 0;
	int ret = lt6911gxd_get_hvactive(&hactive, &vactive);
	if (ret != 0) {
		hwlog_err("%s: Failed to get video active values, ret = %d\n",
			  __func__, ret);
		return -EIO;
	}
	hwlog_info("%s: ret = %d, active = %u,%u\n", __func__, ret, hactive,
		   vactive);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u,%u\n", hactive,
			  vactive);
}

static ssize_t video_frame_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	hwlog_info("%s: in\n", __func__);
	uint32_t frame = 0;
	int ret = lt6911gxd_get_frame(&frame);
	hwlog_info("%s: ret = %d, frame = %u\n", __func__, ret, frame);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n", frame);
}

static ssize_t dpin_enable_show(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	if (!g_vdev) {
		hwlog_err("%s: NULL pointer!", __func__);
		return -EINVAL;
	}
	hwlog_info("%s: in\n", __func__);

	hwlog_info("%s: value=%d\n", __func__, g_vdev->params.dp_mode);
	return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%u\n",
			  g_vdev->params.dp_mode);
}

static ssize_t dpin_enable_store(struct device *dev,
				 struct device_attribute *attr, const char *buf,
				 size_t count)
{
	hwlog_info("%s: in\n", __func__);
	uint32_t val = 0;
	int rc = 0;

	rc = kstrtouint(buf, 0, &val);
	if (rc < 0) {
		return rc;
	}
	hwlog_info("%s: value=%d\n", __func__, val);
	if (val != 0 && val != 1) {
		hwlog_err("%s: invalid param\n", __func__);
		return count;
	}
	lt6911gxd_post_event(PD_EVENT, DP_IN_SET_MODE, val);
	return count;
}

static ssize_t chip_check_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	uint16_t ver = 0;
	int ret = lt6911gxd_get_version(&ver);
	hwlog_info("%s: ret = %d, ver = %u\n", __func__, ret, ver);
	if (AT_chip_version != 0) {
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "OK\n");
	} else {
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "FAILED\n");
	}
}

static int lt6911gxd_get_audio_fs(unsigned int *fs)
{
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK || !fs) {
		return ret;
	}

	uint8_t audio_fs[NUMBER_TWO] = { 0 };
	if (lt6911gxd_read_n_bytes(g_lt6911gxd_device->client,
				   READ_REG_AUDIO_FS_HIGH, audio_fs,
				   NUMBER_TWO) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	hwlog_info("%s : high: %x: low: %x\n", __func__, audio_fs[0],
		   audio_fs[1]);
	*fs = ((unsigned short)audio_fs[0] << ONE_BYTE_BITS) |
	      (unsigned short)audio_fs[1];
	return DP_IN_CHIP_ECODE_OK;
}

static int lt6911gxd_enable_mipi_stream(int enable)
{
	hwlog_info("%s: in\n", __func__);
	int ret = lt6911gxd_i2c_pre_check();
	if (ret != DP_IN_CHIP_ECODE_OK) {
		return ret;
	}

	uint8_t en = (enable != 0);
	if (lt6911gxd_write_byte(g_lt6911gxd_device->client,
				 WRITE_REG_ENABLE_MIPI, en) != 0) {
		return DP_IN_CHIP_ECODE_I2C_COMM;
	}
	return DP_IN_CHIP_ECODE_OK;
}

static ssize_t dpin_stream_store(struct device *dev,
				 struct device_attribute *attr, const char *buf,
				 size_t count)
{
	uint32_t val = 0;
	int rc = 0;

	rc = kstrtouint(buf, 0, &val);
	if (rc < 0) {
		return rc;
	}
	hwlog_info("%s: value=%d\n", __func__, val);
	if (val != 0 && val != 1 && val != REQUEST_CHECK_HVACTIVE) {
		hwlog_err("%s: invalid param\n", __func__);
		return count;
	}
	if (val == 0 || val == 1) {
		if (!g_lt6911gxd_device) {
			hwlog_err("%s: NULL pointer!", __func__);
			return count;
		}
		mutex_lock(&g_lt6911gxd_device->lock);
		lt6911gxd_enable_mipi_stream(val);
		mutex_unlock(&g_lt6911gxd_device->lock);
		return count;
	}
	if (g_dpin_status == DP_IN_STATUS_PLUG_OUT) {
		return count;
	}

	hwlog_info("%s: start process_stream_status, g_stream_status = %d\n", __func__, g_stream_status);
	mutex_lock(&g_lt6911gxd_device->lock);
	process_stream_status(1);
	mutex_unlock(&g_lt6911gxd_device->lock);
	return count;
}

static DEVICE_ATTR_RO(chip_version);
static DEVICE_ATTR_RO(video_active);
static DEVICE_ATTR_RO(video_frame);
static DEVICE_ATTR_RO(video_status);
static DEVICE_ATTR_RO(audio_status);
static DEVICE_ATTR_RW(dpin_enable);
static DEVICE_ATTR_RO(chip_check);
static DEVICE_ATTR_WO(dpin_stream);
static struct attribute *dpin_attributes[] = { &dev_attr_chip_version.attr,
					       &dev_attr_video_active.attr,
					       &dev_attr_video_frame.attr,
					       &dev_attr_dpin_enable.attr,
					       &dev_attr_chip_check.attr,
					       &dev_attr_dpin_stream.attr,
					       &dev_attr_video_status.attr,
					       &dev_attr_audio_status.attr,
					       NULL };

static struct attribute_group dpin_attribute_group = {
	.attrs = dpin_attributes
};

static enum led_brightness brightness_get(struct led_classdev *cdev)
{
	return LED_OFF;
}

static void brightness_set(struct led_classdev *cdev, enum led_brightness level)
{
	return;
}

static void process_stream_status(int intType)
{
	uint32_t hactive = 0;
	uint32_t vactive = 0;
	uint32_t frame = 0;
	lt6911gxd_get_hvactive(&hactive, &vactive);
	lt6911gxd_get_frame(&frame);
	hwlog_info("%s:intType = %d, g_stream_status = %d, h = %d, v = %d, f = %d\n",
			__func__, intType, g_stream_status, hactive, vactive, frame);

	if (intType == IRQ_TYPE_VIDEO_DISAPPEAR || hactive == 0 || vactive == 0 || frame == 0) {
		g_stream_status = STREAM_OFF;
		set_events_hactive(SIGNAL_IS_DISAPPEAR);
		set_events_vactive(SIGNAL_IS_DISAPPEAR);
		set_events_frame(SIGNAL_IS_DISAPPEAR);
		set_events_signal_status(SIGNAL_IS_DISAPPEAR);
		set_events_error_code(NO_SIGNAL);
		set_events_type(ERROR_CODE_EVENT);
		return;
	}

	if (!is_valid_streaminfo(hactive, vactive)) {
		g_stream_status = STREAM_INVALID;
		set_events_error_code(INVALID_STREAM_INFO);
		set_events_type(ERROR_CODE_EVENT);
		return;
	}

	g_stream_status = STREAM_VALID;
	set_events_hactive(hactive);
	set_events_vactive(vactive);
	set_events_frame(frame);
	set_events_signal_status(SIGNAL_IS_APPEAR);
	set_events_error_code(ERROR_CODE_OK);
}

static irqreturn_t lt6911gxd_irq_handle(int irq, void *data)
{
	struct lt6911gxd_device *port_dev = NULL;
	if (!data)
		return IRQ_HANDLED;
	port_dev = (struct lt6911gxd_device *)data;
	if (!g_update_finished) {
		hwlog_err("%s: update is not finish but rcv irq value = %d\n",
			  __func__, gpio_get_value(port_dev->irq));
		return IRQ_HANDLED;
	}

	int ret;
	uint8_t status = 0;
	mutex_lock(&g_lt6911gxd_device->lock);
	ret = lt6911gxd_get_video_interrupt_type(&status);
	status = status & 0x01;
	hwlog_info("%s: ret = %d, interrupt type = %u, g_stream_status = %d before\n", __func__, ret,
		   status, g_stream_status);
	if ((status == IRQ_TYPE_VIDEO_DISAPPEAR && (g_stream_status != STREAM_OFF)) || (status == IRQ_TYPE_VIDEO_APPEAR &&
			(g_stream_status == STREAM_OFF || g_stream_status == STREAM_INVALID))) {
		process_stream_status(status);
	}
	mutex_unlock(&g_lt6911gxd_device->lock);
	hwlog_info("%s:g_stream_status = %d after\n", __func__, g_stream_status);
	return IRQ_HANDLED;
}

static void stream_work_handler(struct work_struct *work)
{
	uint32_t hactive = 0;
	uint32_t vactive = 0;
	uint32_t frame = 0;
	lt6911gxd_get_hvactive(&hactive, &vactive);
	lt6911gxd_get_frame(&frame);
	for (int i = 0; i < READ_STREAM_INFO_RETRY_TIMES; ++i) {
		if (hactive == 0 || vactive == 0 || frame == 0 || !is_valid_streaminfo(hactive, vactive)) {
			hwlog_err("%s: streaminfo: %dX%d, %d, retry", __func__,
			   hactive, vactive, frame);
			msleep(DELAY_READ_STREAM_INFO_TIME);
			lt6911gxd_get_hvactive(&hactive, &vactive);
			lt6911gxd_get_frame(&frame);
			continue;
		}
		hwlog_info("%s: valid streaminfo", __func__);
		set_events_hactive(hactive);
		set_events_vactive(vactive);
		set_events_frame(frame);
		set_events_signal_status(SIGNAL_IS_APPEAR);
		set_events_error_code(ERROR_CODE_OK);
		return;
	}

	if (hactive == 0 || vactive == 0 || frame == 0) {
		set_events_hactive(SIGNAL_IS_DISAPPEAR);
		set_events_vactive(SIGNAL_IS_DISAPPEAR);
		set_events_frame(SIGNAL_IS_DISAPPEAR);
		set_events_signal_status(SIGNAL_IS_DISAPPEAR);
		set_events_error_code(NO_SIGNAL);
		set_events_type(ERROR_CODE_EVENT);
	} else {
		set_events_error_code(INVALID_STREAM_INFO);
		set_events_type(ERROR_CODE_EVENT);
	}
}

static bool is_valid_streaminfo(uint32_t hactive, uint32_t vactive)
{
	for (int i = 0;
	     i < sizeof(g_valid_streaminfo) / sizeof(g_valid_streaminfo[0]);
	     ++i) {
		if (hactive == g_valid_streaminfo[i].hactive &&
		    vactive == g_valid_streaminfo[i].vactive) {
			return true;
		}
	}
	return false;
}

static int lt6911gxd_init_irq(struct lt6911gxd_device *port_dev)
{
	int ret = -EPERM;
	hwlog_info("%s: in\n", __func__);
	if (!port_dev) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	port_dev->irq = gpio_to_irq(port_dev->gpio_i_irq);
	if (port_dev->irq < 0) {
		hwlog_err("%s: gpio %d map to irq fail\n", __func__,
			  port_dev->gpio_i_irq);
		gpio_free(port_dev->gpio_i_irq);
		return -EINVAL;
	}

	enable_irq_wake(port_dev->irq);
	disable_irq(port_dev->irq);

	ret = request_threaded_irq(port_dev->irq, NULL, lt6911gxd_irq_handle,
				   IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
				   "lt6911gxd_irq", port_dev);
	if (ret) {
		hwlog_err("%s: request thread fail ret = %d\n", __func__, ret);
		port_dev->irq = -1;
		gpio_free(port_dev->gpio_i_irq);
		return ret;
	}

	hwlog_info("%s: success, gpio irq is %d\n", __func__, port_dev->irq);
	return 0;
}

static void lt6911gxd_process_dpin(int date)
{
	dp_in_status status = (dp_in_status)date;
	g_dpin_status = status;
	hwlog_info("%s: status = %d\n", __func__, status);
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: dev not init\n", __func__);
		return;
	}
	if (!g_update_finished) {
		hwlog_err("%s: update not finish\n", __func__);
		return;
	}
	if (is_ulsr()) {
		hwlog_err("%s: in ulsr", __func__);
		return;
	}
	if (status == DP_IN_STATUS_POSITIVE) {
		hwlog_info("%s: process DP_IN_STATUS_POSITIVE\n", __func__);
		gpio_set_value(g_lt6911gxd_device->gpio_o_mux_sel, 1);
		gpio_set_value(g_lt6911gxd_device->gpio_o_cc1, 0);
		lt6911gxd_power_on(g_lt6911gxd_device);

		if (!g_hpd_work_start) {
			schedule_work(&hpd_work);
		}
	} else if (status == DP_IN_STATUS_NEGATIVE) {
		hwlog_info("%s: process DP_IN_STATUS_NEGATIVE\n", __func__);
		gpio_set_value(g_lt6911gxd_device->gpio_o_mux_sel, 1);
		gpio_set_value(g_lt6911gxd_device->gpio_o_cc1, 1);
		lt6911gxd_power_on(g_lt6911gxd_device);

		if (!g_hpd_work_start) {
			schedule_work(&hpd_work);
		}
	} else if (status == DP_IN_STATUS_PLUG_OUT) {
		hwlog_info("%s: process DP_IN_STATUS_PLUG_OUT\n", __func__);
		gpio_set_value(g_lt6911gxd_device->gpio_o_mux_sel, 0);
		gpio_set_value(g_lt6911gxd_device->gpio_o_cc1, 0);
		lt6911gxd_power_off(g_lt6911gxd_device);
	} else {
		hwlog_err("%s: invalid dp_in_status\n", __func__);
	}
}

static void lt6911gxd_send_uevent(void)
{
	if (!g_lt6911gxd_device || !g_lt6911gxd_device->c_dev.dev) {
		hwlog_err("%s: null ptr\n", __func__);
		return;
	}
	char event_buf[] = "dpin=devplugin";
	char *envp[] = { event_buf, NULL };
	int ret;

	ret = kobject_uevent_env(&g_lt6911gxd_device->c_dev.dev->kobj,
				 KOBJ_CHANGE, envp);
	if (ret) {
		hwlog_err("%s: send uevent failed %d\n", __func__, ret);
	} else {
		hwlog_info("%s: send uevent %s success\n", __func__, envp[0]);
	}
}

void lt6911gxd_switch_events(int event_type, int event_data)
{
	hwlog_info("%s: event_type = %d, event_data = %d\n", __func__,
		   event_type, event_data);
	switch (event_type) {
	case DPIN_CONFIG:
		lt6911gxd_process_dpin(event_data);
		break;
	case DPIN_PLUG_DEVICE_STATUS:
		if (event_data == DP_IN_STATUS_PLUG_OUT) {
			lt6911gxd_process_dpin(event_data);
			msleep(LT6911GXD_DELAY_SEND_PLUGOUT_TIME);
			set_events_plug_status(PLUG_OUT);
			set_events_device_support(NO_AUX_CONNECT);
			g_stream_status = STREAM_OFF;
		} else if (event_data == DP_IN_STATUS_PLUG_IN) {
			lt6911gxd_send_uevent();
			set_events_plug_status(PLUG_IN);
		}
		break;
	case DPIN_DP_MODE:
		set_events_pd_mode(event_data);
		break;
	default:
		hwlog_err("%s: invalid event_type\n", __func__);
		break;
	}
	hwlog_info("%s: \n", __func__);
}

static void lt6911gxd_setup_notify_event(void)
{
	cs32g050_register_event(DPIN_EVENT, lt6911gxd_switch_events);
}
static int lt6911gxd_probe(struct i2c_client *client,
			   const struct i2c_device_id *id)
{
	hwlog_info("%s: in\n", __func__);
	int ret = -EPERM;
	struct lt6911gxd_device *port_dev = NULL;
	if (!client) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}
	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		hwlog_err("%s: i2c_check_functionality error!\n", __func__);
		return -EINVAL;
	}

	hwlog_info("%s: client_addr = 0X%X\n", __func__, client->addr);

	port_dev = devm_kzalloc(&client->dev, sizeof(struct lt6911gxd_device),
				GFP_KERNEL);
	if (!port_dev) {
		hwlog_err("%s: devm_kzalloc port_dev failed\n", __func__);
		return -ENOMEM;
	}
	port_dev->dev = &client->dev;
	port_dev->client = client;

	ret = lt6911gxd_parse_dts(port_dev);
	if (ret != 0) {
		hwlog_err("%s: parse dts failed\n", __func__);
		devm_kfree(&client->dev, port_dev);
		return -EPERM;
	}

	ret = lt6911gxd_init_gpio(port_dev);
	if (ret != 0) {
		hwlog_err("%s: init_gpio failed\n", __func__);
		devm_kfree(&client->dev, port_dev);
		return -EPERM;
	}

	i2c_set_clientdata(client, port_dev);
	dev_set_drvdata(&client->dev, port_dev);
	g_lt6911gxd_device = port_dev;

	port_dev->c_dev.name = "dpin";
	port_dev->c_dev.brightness_get = brightness_get;
	port_dev->c_dev.brightness_set = brightness_set;
	ret = devm_led_classdev_register(&port_dev->client->dev,
					 &port_dev->c_dev);
	if (ret < 0) {
		hwlog_err("%s: fail to create led dev", __func__);
		devm_kfree(&client->dev, port_dev);
		return ret;
	}
	ret = sysfs_create_group(&port_dev->c_dev.dev->kobj,
				 &dpin_attribute_group);
	if (ret < 0) {
		hwlog_err("%s: error creating sysfs attr files", __func__);
		devm_kfree(&client->dev, port_dev);
		return ret;
	}
	lt6911gxd_setup_notify_event();
	INIT_DELAYED_WORK(&port_dev->fw_update_work, lt6911gxd_fw_update_work);
	schedule_delayed_work(
		&port_dev->fw_update_work,
		msecs_to_jiffies(port_dev->firmware_update_delay));
	mutex_init(&port_dev->lock);

	ret = lt6911gxd_init_irq(port_dev);
	if (ret != 0) {
		hwlog_err("%s: init_irq failed\n", __func__);
		devm_kfree(&client->dev, port_dev);
		return -EPERM;
	}

	hwlog_info("%s: probe done\n", __func__);

	return 0;
}

static int lt6911gxd_remove(struct i2c_client *client)
{
	hwlog_info("%s: in\n", __func__);
	struct lt6911gxd_device *port_dev = NULL;

	if (!client) {
		hwlog_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	g_lt6911gxd_device = NULL;
	port_dev = i2c_get_clientdata(client);
	if (!port_dev || !port_dev->client) {
		return 0;
	}
	devm_led_classdev_unregister(&port_dev->client->dev, &port_dev->c_dev);

	gpio_free(port_dev->gpio_i_hpd);
	gpio_free(port_dev->gpio_o_cc1);

	gpio_free(port_dev->gpio_i_irq);

	gpio_free(port_dev->gpio_o_reset);
	gpio_free(port_dev->gpio_o_1v2_power);
	gpio_free(port_dev->gpio_o_3v3_power);
	gpio_free(port_dev->gpio_o_mux_sel);
	devm_kfree(&client->dev, port_dev);
	hwlog_info("%s: remove done\n", __func__);
	return 0;
}

MODULE_DEVICE_TABLE(i2c, lt6911gxd_drv);
const static struct of_device_id lt6911gxd_of_match[] = {
	{
		.compatible = "lontium,lt6911gxd",
		.data = NULL,
	},
	{},
};

static int lt6911gxd_pm_suspend(struct device *dev)
{
	hwlog_info("%s: in", __func__);
	if (!is_ulsr()) {
		hwlog_err("%s: doesn't in ulsr", __func__);
		return 0;
	}
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		return 0;
	}
	disable_irq(g_lt6911gxd_device->gpio_i_irq);
	hwlog_info("%s: in ulsr", __func__);
	return 0;
}

static int lt6911gxd_pm_resume(struct device *dev) //恢复
{
	hwlog_info("%s: in", __func__);
	if (!is_ulsr()) {
		hwlog_info("%s: doesn't in ulsr", __func__);
		return 0;
	}
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		return 0;
	}
	gpio_direction_input(g_lt6911gxd_device->gpio_i_hpd);
	gpio_direction_output(g_lt6911gxd_device->gpio_o_mux_sel, 0);
	gpio_direction_output(g_lt6911gxd_device->gpio_o_reset, 1);
	hwlog_info("%s :lt6911gxd exit ulsr, resume gpio", __func__);

	return 0;
}

static int lt6911gxd_pm_freeze(struct device *dev)
{
	hwlog_info("%s: in\n", __func__);
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		return -EINVAL;
	}
	disable_irq(g_lt6911gxd_device->gpio_i_irq);
	return 0;
}

static int lt6911gxd_pm_restore(struct device *dev)
{
	hwlog_info("%s: in\n", __func__);
	if (!g_lt6911gxd_device) {
		hwlog_err("%s: NULL pointer!", __func__);
		return -EINVAL;
	}
	gpio_direction_input(g_lt6911gxd_device->gpio_i_hpd);
	gpio_direction_output(g_lt6911gxd_device->gpio_o_mux_sel, 0);
	gpio_direction_output(g_lt6911gxd_device->gpio_o_cc1, 0);

	enable_irq(g_lt6911gxd_device->gpio_i_irq);
	return 0;
}

static const struct dev_pm_ops lt6911gxd_pm_ops = {
	.suspend = lt6911gxd_pm_suspend,
	.resume = lt6911gxd_pm_resume,
	.freeze = lt6911gxd_pm_freeze,
	.restore = lt6911gxd_pm_restore,
};

static struct i2c_driver lt6911gxd_driver = {
	.probe = lt6911gxd_probe,
	.remove = lt6911gxd_remove,
	.driver = {
		.name = "lt6911gxd_drv",
		.owner = THIS_MODULE,
		.pm = &lt6911gxd_pm_ops,
		.of_match_table = of_match_ptr(lt6911gxd_of_match),
	},
};

static int __init lt6911gxd_init(void)
{
	hwlog_info("%s: begin\n", __func__);
	int ret = i2c_add_driver(&lt6911gxd_driver);
	if (ret != 0)
		hwlog_err("%s: i2c_add_driver error!!!\n", __func__);
	INIT_WORK(&hpd_work, hpd_work_handler);
	INIT_WORK(&stream_work, stream_work_handler);
	hwlog_info("%s: end\n", __func__);
	return ret;
}

static void __exit lt6911gxd_exit(void)
{
	hwlog_info("%s: begin\n", __func__);
	i2c_del_driver(&lt6911gxd_driver);
	flush_work(&hpd_work);
	flush_work(&stream_work);
	hwlog_info("%s: end\n", __func__);
}

late_initcall(lt6911gxd_init);
module_exit(lt6911gxd_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("lt6911gxd driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");