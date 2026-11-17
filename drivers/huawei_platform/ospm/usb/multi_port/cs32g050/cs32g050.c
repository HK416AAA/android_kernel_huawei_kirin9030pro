/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * cs32g050.c
 *
 * cs32g050 multi port driver
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
#include <linux/pm.h>
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
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/platform_drivers/usb/tca.h>
#include <linux/notifier.h>
#include <linux/kernel.h>
#include <securec.h>
#include "cs32g050.h"
#include "cs32g050_fw.h"
#include "hw_peripheral/dp2mipi/hw_lt6911gxd.h"
#include "hw_cs32g050.h"
#include <platform_include/cee/linux/ulsr.h>
#include <chipset_common/hwpower/common_module/power_event_ne.h>
#include <linux/timer.h>
#include <linux/pm_wakeup.h>
#include "echub/hmi/hmi.h"
#include "echub/echub_i2c.h"
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif

#define I2C_RETRY_TIME 5
#define MAX_PORT_NUM 3
#define PORT_ROLE_NUM 3
#define PORT_ROLE_ATTR_NUM 4
#define STR_DEBUG_NODE "hdc_usb_debug_mode"
#define PORTMODEFLAG_VALUE     1
#define PD_IC_MODE 1
#define PM_WAKE_LOCK_TIMES    2000
#define PORT_INDEX_ZERO       0
#define PORT_INDEX_ONE        1
#define PORT_INDEX_TWO        2
#define POWER_ROLE_INDEX      0
#define DATA_ROLE_INDEX       1
#define PORT_MODE_INDEX       2
#define SUPPORTED_MODE_INDEX  3
#define PORT_ROLE_INDEX_ZERO  0
#define PORT_ROLE_INDEX_ONE   1
#define PORT_ROLE_INDEX_TWO   2
#define DATA_CNT              2
#define DPIN_PLUG_HANDLE_TIME 100
#define REGDATA_U8_NUM        2

#define MAX_EVENT_TYPE 12
#define MAX_DATA_LEN 2
#define MAX_PROCESS_LEN 0x0F
#define PROCESS_1_LEN 7
#define BYTE_FF 0xFF
#define OFFSET_3 3
#define OFFSET_8 8
#define MAX_KEY_LEN 64
#define RECORD_TO_ALL_PORT 0xFF

// port have external screen connected; false: no, true: yes
bool g_dp_status[MAX_PORT_NUM] = {false, false, false};
bool g_support_dpin = false;
u64 g_last_port_status[MAX_PORT_NUM] = {0, 0, 0};
static struct class *g_class = NULL;
static struct class *g_dual_port_class = NULL;
static struct device *g_usb_port_node_dev[MAX_PORT_NUM] = {NULL, NULL, NULL};
const char *g_usb_port_node_name[MAX_PORT_NUM] = {"port0", "port1", "port2"};
const char *g_usb_data_role[PORT_ROLE_NUM] = {"host", "device", "none"};
const char *g_usb_power_role[PORT_ROLE_NUM] = {"source", "sink", "none"};
const char *g_usb_port_mode[PORT_ROLE_NUM] = {"DFP", "UFP", "DRP"};
const char *g_usb_supported_mode[PORT_ROLE_NUM] = {"drp", "none"}; //drp for support dpin
const char *g_usb_node_attribute[PORT_ROLE_ATTR_NUM] = {"power_role", "data_role", "port_mode", "supported_mode"};
static dev_t g_devno;
static struct cdev  g_cdev;
static struct cs32g050_port_device *g_port0_dev;
bool g_debug_node_exist = false;
static u8 g_real_port_num = 0;
static int g_max_speed = 0;
static struct cs32g050_dispatcher *g_dispatcher_pdphy = NULL;
static struct notifier_block g_hmi_event_nb;
bool g_pd_ic_mode = false;

static struct timer_list pm_lock_timer;
struct wakeup_source *g_pd_wake_ws = NULL;
bool g_pd_wake_ws_enable = false;
bool g_cs32g050_probe[MAX_PORT_NUM] = {false, false, false};
bool g_dp_first_in[MAX_PORT_NUM] = {false, false, false};

static u8 g_cmd_pd_byte3 = 0;
static bool g_in_dpin = false;
long long g_process_code[MAX_PORT_NUM][MAX_DATA_LEN] = {{0x01, 0x00},{0x01, 0x00},{0x01, 0x00}}; // default index is 1

typedef struct {
	int typeid;
	enum tca_irq_type_e irq_type;
	enum tcpc_mux_ctrl_type mode_type;
	enum tca_device_type_e dev_type;
	enum typec_plug_orien_e typec_orien;
} TypecContext;

static TypecContext g_tc_data[MAX_EVENT_TYPE] = {
	{IRQ_HPD_IN_AND_DP_MODE_AND_DP_IN, TCA_IRQ_HPD_IN, TCPC_MUX_MODE_MAX, TCA_DP_IN},
	{IRQ_HPD_IN_AND_DP_MODE_AND_HOST_IN, TCA_IRQ_HPD_IN, TCPC_MUX_MODE_MAX, TCA_ID_FALL_EVENT},
	{IRQ_HPD_IN_AND_USB31_MODE_AND_HOST_IN, TCA_IRQ_HPD_IN, TCPC_USB31_CONNECTED, TCA_ID_FALL_EVENT},
	{IRQ_HPD_IN_AND_USB31_MODE_AND_DEVICE_IN, TCA_IRQ_HPD_IN, TCPC_USB31_CONNECTED, TCA_CHARGER_CONNECT_EVENT},
	{IRQ_HPD_IN_AND_USB31DP_MODE_AND_HOST_IN, TCA_IRQ_HPD_IN, TCPC_USB31_AND_DP_2LINE, TCA_ID_FALL_EVENT},
	{IRQ_SHORT_HPD_AND_DP_MODE_AND_DP_IN, TCA_IRQ_SHORT, TCPC_MUX_MODE_MAX, TCA_DP_IN},
	{IRQ_HPD_OUT_AND_DP_MODE_AND_DP_OUT, TCA_IRQ_HPD_OUT, TCPC_MUX_MODE_MAX, TCA_DP_OUT},
	{IRQ_HPD_OUT_AND_NC_MODE_AND_HOST_OUT, TCA_IRQ_HPD_OUT, TCPC_NC, TCA_ID_RISE_EVENT},
	{IRQ_HPD_OUT_AND_NC_MODE_AND_DEVICE_OUT, TCA_IRQ_HPD_OUT, TCPC_NC, TCA_CHARGER_DISCONNECT_EVENT},
	{IRQ_HPD_OUT_AND_USB31_MODE_AND_HOST_OUT, TCA_IRQ_HPD_OUT, TCPC_USB31_CONNECTED, TCA_ID_RISE_EVENT},
	{IRQ_HPD_OUT_AND_USB31_MODE_AND_DEVICE_OUT, TCA_IRQ_HPD_OUT, TCPC_USB31_CONNECTED, TCA_CHARGER_DISCONNECT_EVENT}
};

static DECLARE_COMPLETION(g_cs32g050_comp);
struct mutex cs32g050_mutex;

#define MAX_EVENTS 10
 
typedef struct {
    cs32g050_register_module module_type;
    event_notify_t callback;
} event_registration;
 
event_registration cs32g050_event_table[MAX_EVENTS] = {0};

u64 *cs32g050_get_g_last_port_status(void)
{
	return g_last_port_status;
}
 
void cs32g050_register_event(cs32g050_register_module type, event_notify_t notify)
{
    for (int i = 0; i < MAX_EVENTS; ++i) {
        if (cs32g050_event_table[i].module_type == 0) {
            cs32g050_event_table[i].module_type = type;
            cs32g050_event_table[i].callback = notify;
            pr_info("%s: Event type %d registered.\n", __func__, cs32g050_event_table[i].module_type);
            return;
        }
    }
    pr_err("%s: cannot register more events.\n", __func__);
}
 
static void cs32g050_post_event(cs32g050_register_module type, dp_in_status event_type, dp_in_status event_data)
{
	pr_info("%s: module_type = %d event_type = %d event_data = %d\n", __func__, type, event_type, event_data);
    for (int i = 0; i < MAX_EVENTS; ++i) {
        if (cs32g050_event_table[i].module_type == type) {
            if (cs32g050_event_table[i].callback) {
                cs32g050_event_table[i].callback((int)event_type, (int)event_data);
                return;
            }
        }
    }
    pr_err("%s: No handler found for event type %d.\n", __func__, event_type);
}

static bool is_data_connected(u64 port_status)
{
	return ((port_status & CS32G050_DATA_CONNECTION) != 0) ? true : false;
}

static bool get_plug_orien(u64 port_status)
{
	return ((port_status & CS32G050_CONNECT_ORIENTATION) != 0) ? true : false;
}

static bool is_usb2_connected(u64 port_status)
{
	return ((port_status & CS32G050_USB2_CONNECT_STATE) != 0) ? true : false;
}

static bool is_usb3_connected(u64 port_status)
{
	return ((port_status & CS32G050_USB3_CONNECT_STATE) != 0) ? true : false;
}

static bool is_mode_device(u64 port_status)
{
	return ((port_status & CS32G050_USB_DATA_ROLE) != 0) ? true : false;
}

static bool is_dp_connected(u64 port_status)
{
	return ((port_status & CS32G050_DP_CONNECTION) != 0) ? true : false;
}

static bool is_dp_source_sink(u64 port_status)
{
	return ((port_status & CS32G050_DP_SOURCE_SINK) != 0) ? true : false;
}

static bool is_hpd_irq(u64 port_status)
{
	return ((port_status & CS32G050_HPD_IRQ) != 0) ? true : false;
}

static bool is_hpd_high(u64 port_status)
{
	return ((port_status & CS32G050_HPD_LEVEL_STATE) != 0) ? true : false;
}

static bool is_analog_earphones(u64 port_status)
{
	return ((port_status & CS32G050_ANALOG_EARPHONE_CONNECTION) != 0) ? true : false;
}

static bool is_port_status_fail(u64 port_status)
{
	return ((port_status & CS32G050_READ_STATUS_FAIL) == CS32G050_READ_STATUS_FAIL) ? true : false;
}

static int calculate_port_role(u8 port_id)
{
	int ret = PORT_ROLE_INDEX_ZERO;
	u64 port_status = g_last_port_status[port_id];
	if (is_data_connected(port_status)) {
		if (is_mode_device(port_status))
			ret = PORT_ROLE_INDEX_ONE;
	} else {
		ret = PORT_ROLE_INDEX_TWO;
	}
	return ret;
}

static int get_support_dpin_index(u8 port_id)
{
	int ret = PORT_ROLE_INDEX_ONE;
	if (port_id == 0 && g_support_dpin) { // only port0 support dpin
		ret = PORT_ROLE_INDEX_ZERO;
	}
	return ret;
}

static ssize_t cs32g050_get_attribute(struct device_attribute *attr, int port_id, char *buf)
{
	int index = -1;
	if ((attr == NULL) || (attr->attr.name == NULL)) {
		pr_err("%s: invalid param attr\n", __func__);
		return 0;
	}
	for (int i = 0; i < PORT_ROLE_ATTR_NUM; i++) {
		if (strncmp(attr->attr.name, g_usb_node_attribute[i], sizeof(attr->attr.name) - 1) == 0) {
			index = i;
			break;
		}
	}
	switch (index) {
	case POWER_ROLE_INDEX:
		return sprintf_s(buf, PAGE_SIZE, "%s", g_usb_power_role[calculate_port_role(port_id)]);
	case DATA_ROLE_INDEX:
		return sprintf_s(buf, PAGE_SIZE, "%s", g_usb_data_role[calculate_port_role(port_id)]);
	case PORT_MODE_INDEX:
		return sprintf_s(buf, PAGE_SIZE, "%s", g_usb_port_mode[calculate_port_role(port_id)]);
	case SUPPORTED_MODE_INDEX:
		return sprintf_s(buf, PAGE_SIZE, "%s", g_usb_supported_mode[get_support_dpin_index(port_id)]);
	default:
		pr_err("%s: invalid attr->attr.name\n", __func__);
		return 0;
	}
}

static int cs32g050_i2c_swap_role(struct i2c_client *client, u8 mode);
static ssize_t cs32g050_set_attribute(struct device_attribute *attr, const char *buf, size_t count)
{
	if ((attr == NULL) || (attr->attr.name == NULL) || (buf == NULL)) {
		pr_err("%s: invalid param attr\n", __func__);
		return 0;
	}
	if (!g_support_dpin) {
		pr_err("%s: product unsupport set.\n", __func__);
		return 0;
	}
	if (strncmp(attr->attr.name, ATTR_DATA_ROLE, sizeof(ATTR_DATA_ROLE) - 1) == 0) {
		if (strncmp(buf, g_usb_data_role[0], strlen(buf) - 1) == 0) {
			pr_info("%s: input host swap.\n", __func__);
			g_cmd_pd_byte3 = 0x0;
			cs32g050_i2c_swap_role(g_port0_dev->client, CS32G050_DPIN_OFF_CMD);
			cs32g050_post_event(DPIN_EVENT, DPIN_DP_MODE, 0);
		} else if (strncmp(buf, g_usb_data_role[1], strlen(buf) - 1) == 0) {
			pr_info("%s: input device swap.\n", __func__);
			g_cmd_pd_byte3 = 0x10;
			cs32g050_i2c_swap_role(g_port0_dev->client, CS32G050_DPIN_ON_CMD);
			cs32g050_post_event(DPIN_EVENT, DPIN_DP_MODE, 1);
		} else {
			pr_err("%s: invalid input buf.\n", __func__);
		}
	} else {
		pr_err("%s: invalid attr->attr.name\n", __func__);
	}
	return count;
}

static ssize_t port0_attr_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return cs32g050_get_attribute(attr, PORT_INDEX_ZERO, buf);
}
static ssize_t port0_attr_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	return cs32g050_set_attribute(attr, buf, count);
}

static ssize_t port0_orien_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int ret_orien = 0;
	if (is_data_connected(g_last_port_status[0])) {
		ret_orien = (int)get_plug_orien(g_last_port_status[0]) + 1; // plug_orien: 1 normal , 2 reverse
	}
	return sprintf_s(buf, PAGE_SIZE, "%d\n", ret_orien);
}

static ssize_t port0_speed_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	switch (g_max_speed) {
	case 1:
		return sprintf_s(buf, PAGE_SIZE, "%s", STR_HIGH_SPEED);
	case 2:
		return sprintf_s(buf, PAGE_SIZE, "%s", STR_SUPER_SPEED);
	default:
		return sprintf_s(buf, PAGE_SIZE, "%s", STR_UNKNOWN_SPEED);
	}
}

static ssize_t port1_attr_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return cs32g050_get_attribute(attr, PORT_INDEX_ONE, buf);
}

static ssize_t port2_attr_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return cs32g050_get_attribute(attr, PORT_INDEX_TWO, buf);
}

static struct device_attribute dev0_attr_power_role = __ATTR(power_role, 0664, port0_attr_show, port0_attr_store);
static struct device_attribute dev0_attr_data_role = __ATTR(data_role, 0664, port0_attr_show, port0_attr_store);
static struct device_attribute dev0_attr_port_mode = __ATTR(port_mode, 0664, port0_attr_show, port0_attr_store);
static struct device_attribute dev0_attr_supported_mode = __ATTR(supported_mode, 0444, port0_attr_show, NULL);
static struct device_attribute dev0_attr_usb_orien = __ATTR(usb_orien, 0444, port0_orien_show, NULL);
static struct device_attribute dev0_attr_usb_speed = __ATTR(usb_speed, 0444, port0_speed_show, NULL);

static struct device_attribute dev1_attr_power_role = __ATTR(power_role, 0444, port1_attr_show, NULL);
static struct device_attribute dev1_attr_data_role = __ATTR(data_role, 0444, port1_attr_show, NULL);
static struct device_attribute dev1_attr_port_mode = __ATTR(port_mode, 0444, port1_attr_show, NULL);
static struct device_attribute dev1_attr_supported_mode = __ATTR(supported_mode, 0444, port1_attr_show, NULL);

static struct device_attribute dev2_attr_power_role = __ATTR(power_role, 0444, port2_attr_show, NULL);
static struct device_attribute dev2_attr_data_role = __ATTR(data_role, 0444, port2_attr_show, NULL);
static struct device_attribute dev2_attr_port_mode = __ATTR(port_mode, 0444, port2_attr_show, NULL);
static struct device_attribute dev2_attr_supported_mode = __ATTR(supported_mode, 0444, port2_attr_show, NULL);

static struct attribute *_port0_attrs[] = {
	&dev0_attr_power_role.attr,
	&dev0_attr_data_role.attr,
	&dev0_attr_port_mode.attr,
	&dev0_attr_supported_mode.attr,
	&dev0_attr_usb_orien.attr,
	&dev0_attr_usb_speed.attr,
	NULL,
};
static struct attribute *_port1_attrs[] = {
	&dev1_attr_power_role.attr,
	&dev1_attr_data_role.attr,
	&dev1_attr_port_mode.attr,
	&dev1_attr_supported_mode.attr,
	NULL,
};
static struct attribute *_port2_attrs[] = {
	&dev2_attr_power_role.attr,
	&dev2_attr_data_role.attr,
	&dev2_attr_port_mode.attr,
	&dev2_attr_supported_mode.attr,
	NULL,
};

static const struct attribute_group port0_attr_group = {
	.attrs = _port0_attrs,
};
static const struct attribute_group port1_attr_group = {
	.attrs = _port1_attrs,
};
static const struct attribute_group port2_attr_group = {
	.attrs = _port2_attrs,
};

static const struct attribute_group *pd_node_attr_groups[MAX_PORT_NUM + 1] = {
	&port0_attr_group,
	&port1_attr_group,
	&port2_attr_group,
	NULL,
};
#ifdef CONFIG_HISYSEVENT
static void hiview_hisysevent_cs32g050_event(int portid, bool is_error)
{
	struct hiview_hisysevent *event = NULL;
	int ret;

	if (is_error) {
		event = hisysevent_create("PC_USB", "ERROR_CODE", STATISTIC);
	} else {
		event = hisysevent_create("PC_USB", "PROCESS_CODE", STATISTIC);
	}

	if (event == NULL) {
		pr_err("cs32g050 failed to create event\n");
		return;
	}

	for (int i = 0; i < MAX_PORT_NUM; i++) {
		if (portid != RECORD_TO_ALL_PORT) {
			i = portid;
			pr_info("index is %d\n", i);
		}

		ret = hisysevent_put_string(event, "CALLER", "CS32G050");
		if (ret != 0) {
			pr_err("failed to put to event, CALLER ret=%d\n", ret);
			goto hisysevent_end;
		}

		ret = hisysevent_put_integer(event, "PORT_NUM", i);
		if (ret != 0) {
			pr_err("failed to put to event, PORT_NUM ret=%d\n", ret);
			goto hisysevent_end;
		}

		ret = hisysevent_put_integer(event, "DATA0", g_process_code[i][0]);
		if (ret != 0) {
			pr_err("failed to put to event, DATA0 ret=%d\n", ret);
			goto hisysevent_end;
		}

		ret = hisysevent_put_integer(event, "DATA1", g_process_code[i][1]);
		if (ret != 0) {
			pr_err("failed to put to event, DATA1 ret=%d\n", ret);
			goto hisysevent_end;
		}
		if (portid != RECORD_TO_ALL_PORT) {
			break;
		}
	}

	ret = hisysevent_write(event);
	if (ret < 0) {
		pr_err("failed to write event, ret=%d\n", ret);
	}

hisysevent_end:
	hisysevent_destroy(&event);
}
#endif

/*******************************************************************************
  函 数 名	:  write_process_code
  功能描述	:  wtrie process code to big data platfrom, Keep the last 15 reported data
  输入参数	:  @param portid port id
			  @param type u8 report type
			  @param is_error bool, record in ERR_CODE or PROC_CODE
			  @param needupdate shoul update immediately
  输出参数	:  None
  返 回 值	:  None
  数据规则	:  Big Endian Format
				data[0] index   0 : the last index of report type
						index 1~7 : report data
				data[1] index 0~7(or relative to the index0 8~F) : report data
*******************************************************************************/
static void write_process_code(int portid, u8 type, bool is_error, bool needupload)
{
    int index, offset, id;
    long long mask;

	if ((portid > MAX_PORT_NUM) && (portid != RECORD_TO_ALL_PORT)) {
		pr_err("cs32g050 error port id\n");
		return;
	}

	for (int i = 0; i < MAX_PORT_NUM; i++) {
		if (portid != RECORD_TO_ALL_PORT) {
			i = portid;
		}

		index = (g_process_code[i][0] & BYTE_FF) + 1;
		id = 0;
		if (index > MAX_PROCESS_LEN) {
			index = 1;
		}

		mask = (long long)~(BYTE_FF);
		g_process_code[i][0] &= mask;  // clear index 0
		g_process_code[i][0] |= index; // fill new index
		if (index > PROCESS_1_LEN) { // index in data[1]
			id = 1;
			index -= PROCESS_1_LEN + 1;
		}

		offset = index << OFFSET_3; // caculate offset by index
		mask = (long long)~((long long)0xFF << offset);
		g_process_code[i][id] &= mask; // clear old code
		g_process_code[i][id] |= ((long long)type << offset); // fill the new code

		if (portid != RECORD_TO_ALL_PORT) {
			break;
		}
	}

#ifdef CONFIG_HISYSEVENT
	if (needupload) {
		hiview_hisysevent_cs32g050_event(portid, is_error);
	}
#endif
}

static void pm_lock_callback(struct timer_list *timelist)
{
	if (!g_pd_wake_ws_enable) {
		pr_info("%s: pd not hold wake lock\n", __func__);
		return;
	}

	if (g_pd_wake_ws != NULL) {
		pr_info("%s: do pm relax\n", __func__);
		__pm_relax(g_pd_wake_ws);
	}
	g_pd_wake_ws_enable = false;
	pr_info("%s: pd wake lock relax\n", __func__);
}

static void set_dp_status(int port_id, bool status)
{
	if ((port_id >= 0) && (port_id < MAX_PORT_NUM))
		g_dp_status[port_id] = status;
    else
		pr_err("%s: invalid port_id\n", __func__);
}

static int cs32g050_i2c_write(struct i2c_client *client, u8 *value, u16 num_bytes)
{
	struct i2c_msg msg[1];
	u8 buf[I2C_DATA_MAX_LEN] = {0};
	if ((!client) || (!value) || (num_bytes > (I2C_DATA_MAX_LEN - 1))) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	buf[0] = CS32G050_CONTROL_REG;
	if (memcpy_s(&buf[1], num_bytes, value, num_bytes) != 0) {
		pr_err("%s: memcpy_s failed\n", __func__);
		return -ENOMEM;
	}

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = buf;
	msg[0].len = num_bytes + 1;

	if (i2c_transfer(client->adapter, msg, 1) != 1) {
		pr_err("%s: i2c_transfer failed\n", __func__);
		return -EIO;
	}

	return 0;
}

static int cs32g050_i2c_read(struct i2c_client *client, u8 *value, u16 num_bytes)
{
	struct i2c_msg msg[2];
	u8 reg = CS32G050_STATUS_REG;
	if ((!client) || (!value) || (num_bytes > CS32G050_STATUS_REG_LEN)) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].buf = &reg;
	msg[0].len = 1;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].buf = value;
	msg[1].len = num_bytes;
	if (i2c_transfer(client->adapter, msg, DATA_CNT) != DATA_CNT) {
		pr_err("%s: i2c_transfer failed\n", __func__);
		return -EIO;
	}

	return 0;
}

static int cs32g050_i2c_swap_role(struct i2c_client *client, u8 mode)
{
	union cs32g050_reg_data regdata;
	u64 u64_port_status = 0;
	if (!client) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}
	regdata.data = 0;
	regdata.u8_data[0] = CS32G050_PD_ROLE_SWAP_DATA0;
	regdata.u8_data[1] = CS32G050_PD_ROLE_SWAP_DATA1;
	regdata.u8_data[INDEX_2] = mode;
	pr_info("%s: cmd = 0X%X\n", __func__, regdata.data);
	mutex_lock(&cs32g050_mutex);
	if (cs32g050_i2c_write(client, (u8 *)&(regdata.data), I2C_WRITE_LEN) != 0) {
		mutex_unlock(&cs32g050_mutex);
		pr_err("%s: cs32g050_i2c_write failed\n", __func__);
		return -EIO;
	}
	if (cs32g050_i2c_read(client, (u8 *)&u64_port_status, CS32G050_STATUS_REG_LEN) != 0) {
		mutex_unlock(&cs32g050_mutex);
		pr_err("%s: cs32g050_i2c_read failed\n", __func__);
		return -EIO;
	}
	mutex_unlock(&cs32g050_mutex);
	u64_port_status >>= EIGHT_BIT;
	pr_info("%s: read portstatus = 0X%llX\n", __func__, u64_port_status);
	return 0;
}

static uint8_t cs32g050_get_dpline(u64 port_status)
{
	uint8_t dp_line  = TCPC_USB31_AND_DP_2LINE;
	if (is_usb3_connected(port_status))
		dp_line = TCPC_USB31_AND_DP_2LINE; // usb & dp 2 line
	else
		dp_line = TCPC_DP; // dp 4 line

	return dp_line;
}

static int cs32g050_event_notify_by_type(struct cs32g050_port_device *port_dev, int type, u64 last_port_status)
{
	int ret = -EINVAL;
	bool is_type_valid = false;
	enum tca_irq_type_e irq_type;
	enum tcpc_mux_ctrl_type mode_type;
	enum tca_device_type_e dev_type;

	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}
	pr_err("%s: type = %d\n", __func__, type);
	write_process_code(port_dev->port_id, (u8)type, false, true);

	for (int index = 0; index < MAX_EVENT_TYPE; index++) {
		if (type == g_tc_data[index].typeid) {
			irq_type = g_tc_data[index].irq_type;
			mode_type = g_tc_data[index].mode_type;
			dev_type =  g_tc_data[index].dev_type;
			if (mode_type == TCPC_MUX_MODE_MAX) {
				mode_type = (enum tcpc_mux_ctrl_type)cs32g050_get_dpline(port_dev->last_port_status);
			}
			is_type_valid = true;
			break;
		}
	}

	if (!is_type_valid) {
		pr_err("%s: invalid type %d\n", __func__, type);
		write_process_code(port_dev->port_id, PROCESS_TYPE_INVALID, true, true);
		return ret;
	}
	ret = pd_event_notify_by_portid(port_dev->port_id, irq_type, mode_type, dev_type, port_dev->plug_orien);
	if (ret != 0) {
		write_process_code(port_dev->port_id, PROCESS_NOTIFY_FAILED, true, true);
		pr_err("%s: event notify failed, type is %d\n", __func__, type);
	}

	return ret;
}

static u64 cs32g050_calculate_port_status(u8 *databuf, u8 buflen)
{
	u64 port_status = 0x0;
	for (int i = 1; i < buflen; i++)
		port_status = (port_status << EIGHT_BIT) + databuf[buflen - i];

	return port_status;
}

static int cs32g050_clean_irq(struct cs32g050_port_device *port_dev, u16 clean_irq_cmd)
{
	union cs32g050_reg_data regdata;
	if (!port_dev->client) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	regdata.data = 0;
	regdata.u8_data[0] = CS32G050_CLEAN_IRQ_CMD_LEN;
	regdata.u8_data[1] = clean_irq_cmd & LOW_ONE_BYTE;
	regdata.u8_data[2] = port_dev->port_id == 0 ? g_cmd_pd_byte3 : 0;
	if (clean_irq_cmd == CS32G050_CLEAN_HPD_IRQ_CMD)
		regdata.u8_data[INDEX_2] = clean_irq_cmd >> EIGHT_BIT;
	pr_err("%s: cmd = 0X%X\n", __func__, regdata.data);

	for (int i = 0; i < I2C_RETRY_TIME; i++) {
		if (cs32g050_i2c_write(port_dev->client, (u8 *)&(regdata.data), I2C_WRITE_LEN) != 0) {
			pr_err("%s: cs32g050_i2c_write failed, retry time %d. \n", __func__, i + 1);
			msleep(50); // sleep 50ms
			if (i >= I2C_RETRY_TIME - 1) {
				write_process_code(port_dev->port_id, PROCESS_CLEAN_IRQ_ERROR, true, true);
				return -EIO;
			}
		} else {
			break;
		}
	}

	return 0;
}

static u64 cs32g050_read_port_status(struct cs32g050_port_device *port_dev)
{
	u16 u16_port_status = 0;
	u64 u64_port_status = 0;
	int ret;

	if (!port_dev->client) {
		pr_err("%s: invalid parameter\n", __func__);
		return CS32G050_READ_STATUS_FAIL;
	}

	for (int i = 0; i < CS32G050_I2C_RETRY_DELAY; i++) {
		ret = cs32g050_i2c_read(port_dev->client, (u8 *)&u64_port_status, CS32G050_STATUS_REG_LEN);
		if(ret != 0) {
			u64_port_status = 0;
			u16_port_status = 0;
			msleep(CS32G050_I2C_RETRY_DELAY);
			pr_err("%s: cs32g050_i2c_read i2c retry %d times\n", __func__, i);
			continue;
		}
		u64_port_status >>= EIGHT_BIT; // delete length
		u16_port_status = u64_port_status & CS32G050_READ_STATUS_FAIL; // cut low 16 bit
		if (u16_port_status == CS32G050_READ_STATUS_FAIL) {
			u64_port_status = 0;
			u16_port_status = 0;
			msleep(CS32G050_I2C_RETRY_DELAY);
			pr_err("%s: cs32g050_i2c_read port retry %d times\n", __func__, i);
			continue;
		}
		return u64_port_status;
	}
	pr_err("%s: cs32g050_i2c_read failed\n", __func__);
	write_process_code(port_dev->port_id, PROCESS_READ_PORT_ERROR, true, true);
	return CS32G050_READ_STATUS_FAIL;
}

static int cs32g050_write_request_pdphy(struct cs32g050_port_device *port_dev)
{
	struct echub_i2c_dev *echub_dev = get_echub_dev();
	int ret;
	u8 write_buf[CS32G050_HMI_PDPHY_WRITE_LEN_FOR_WRITE_CMD] = {0};
	if (echub_dev == NULL || echub_dev->transfer_func == NULL) {
		pr_err("%s: echub_dev is NULL\n", __func__);
		return -EINVAL;
	}
	pr_info("%s: echub-write\n", __func__);
	write_buf[0] = port_dev->port_id;
	write_buf[1] = CS32G050_HMI_PDPHY_DATA1_FOR_WRITE_CMD; // HMI_PDPHY transfer data1
	write_buf[2] = CS32G050_HMI_PDPHY_DATA2_FOR_WRITE_CMD; // HMI_PDPHY transfer data2
	write_buf[3] = CS32G050_HMI_PDPHY_DATA3_FOR_WRITE_CMD; // HMI_PDPHY transfer data3
	ret = echub_dev->transfer_func(echub_dev, CS32G050_HMI_PDPHY_WRITE_CMD,
			write_buf, CS32G050_HMI_PDPHY_WRITE_LEN_FOR_WRITE_CMD, NULL, 0);
	if (ret != 0) {
		pr_err("%s i2c transfer failed, ret=%d\n", __func__, ret);
		write_process_code(port_dev->port_id, PROCESS_WRITE_REQUEST_ERROR, true, true);
		return -EINVAL;
	}
	return 0;
}

static u64 cs32g050_read_port_status_pdphy(struct cs32g050_port_device *port_dev)
{
	struct echub_i2c_dev *echub_dev = get_echub_dev();
	u64 u64_port_status;
	int ret;
	u8 write_buf[CS32G050_HMI_PDPHY_WRITE_LEN_FOR_READ_CMD] = {0};
	u8 recvbuf[CS32G050_HMI_PDPHY_READ_LEN_FOR_READ_CMD] = {0};
	if (echub_dev == NULL || echub_dev->transfer_func == NULL) {
		pr_err("%s: echub_dev is NULL\n", __func__);
		return CS32G050_READ_STATUS_FAIL;
	}
	pr_info("%s: echub-write\n", __func__);
	write_buf[0] = port_dev->port_id;
	write_buf[1] = CS32G050_HMI_PDPHY_DATA1_FOR_READ_CMD;
	ret = echub_dev->transfer_func(echub_dev, CS32G050_HMI_PDPHY_READ_CMD, write_buf,
		CS32G050_HMI_PDPHY_WRITE_LEN_FOR_READ_CMD, recvbuf, CS32G050_HMI_PDPHY_READ_LEN_FOR_READ_CMD);
	if (ret != 0) {
		pr_err("%s i2c transfer failed, ret=%d\n", __func__, ret);
		write_process_code(port_dev->port_id, PROCESS_READ_PORT_ERROR, true, true);
		return CS32G050_READ_STATUS_FAIL;
	}
	u64_port_status = cs32g050_calculate_port_status(recvbuf, CS32G050_HMI_PDPHY_READ_LEN_FOR_READ_CMD);

	return u64_port_status;
}

// update port_status
static void cs32g050_modify_port_status(struct cs32g050_port_device *port_dev, u64 *port_status)
{
	if (port_dev->port_id != 0) {
		*port_status &= (~CS32G050_USB_DATA_ROLE);
	}
}

static void cs32g050_hpd_step_in_handle(struct cs32g050_port_device *port_dev, u64 last_port_status)
{
	int type = IRQ_HPD_IN_AND_DP_MODE_AND_DP_IN;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if ((is_hpd_high(last_port_status)) && (!is_hpd_irq(last_port_status)))
		return;

	set_dp_status(port_dev->port_id, true);
	if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
}

static void cs32g050_hpd_step_out_handle(struct cs32g050_port_device *port_dev, u64 last_port_status)
{
	int type = IRQ_HPD_OUT_AND_DP_MODE_AND_DP_OUT;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
}

static void cs32g050_hpd_specific_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	int type = -EPERM;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if (is_usb3_connected(port_status)) // dp & usb
		type = IRQ_HPD_IN_AND_USB31DP_MODE_AND_HOST_IN;
	else // dp
		type = IRQ_HPD_IN_AND_DP_MODE_AND_HOST_IN;

	if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
}

static void cs32g050_dp_dev_irq_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	int type_irq = IRQ_SHORT_HPD_AND_DP_MODE_AND_DP_IN;
	int type_hpd = IRQ_HPD_IN_AND_DP_MODE_AND_DP_IN;
	// clean hpd irq
	if (g_pd_ic_mode) {
		mutex_lock(&cs32g050_mutex);
		if (cs32g050_clean_irq(port_dev, CS32G050_CLEAN_HPD_IRQ_CMD) != 0)
			pr_err("%s: clean_hpd_irq fail!\n", __func__);
		mutex_unlock(&cs32g050_mutex);
	} else {
		if (cs32g050_write_request_pdphy(port_dev) != 0)
			pr_err("%s: write_request transfer failed\n", __func__);
	}

	if (!is_dp_connected(last_port_status)) {
		cs32g050_hpd_specific_handle(port_dev, port_status, last_port_status);
		msleep(100); // sleep 100ms
	}

	set_dp_status(port_dev->port_id, true);
	if (g_cs32g050_probe[port_dev->port_id] || g_dp_first_in[port_dev->port_id]) {
		pr_info("%s: send hpd before irq when first irq in!\n", __func__);
		if (cs32g050_event_notify_by_type(port_dev, type_hpd, last_port_status) != 0)
			pr_err("%s: cs32g050_event_notify_by_type added failed type = %d\n", __func__, type_hpd);
		g_cs32g050_probe[port_dev->port_id] = false;
		g_dp_first_in[port_dev->port_id] = false;
	}

	if (cs32g050_event_notify_by_type(port_dev, type_irq, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type_irq);
}

static int cs32g050_dp_dev_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	// hpd irq err case
	if (is_hpd_irq(port_status)) {
		cs32g050_dp_dev_irq_handle(port_dev,  port_status, last_port_status);
		return 0;
	}

	// hpd step in
	if (is_hpd_high(port_status)) {
		if (!is_dp_connected(last_port_status)) {
			set_dp_status(port_dev->port_id, true);
			cs32g050_hpd_specific_handle(port_dev, port_status, last_port_status);
			msleep(100); // sleep 100ms
		}

		cs32g050_hpd_step_in_handle(port_dev, last_port_status);
		return 0;
	}

	// hpd step out
	if (is_hpd_high(last_port_status)) {
		cs32g050_hpd_step_out_handle(port_dev, last_port_status);
		return 0;
	}

	return -EINVAL;
}

static void cs32g050_dock_dev_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	int type = -EPERM;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if (!is_dp_connected(last_port_status)) { // dp step in
		if (is_usb3_connected(port_status)) // dp & usb
			type = IRQ_HPD_IN_AND_USB31DP_MODE_AND_HOST_IN;
		else // dp
			type = IRQ_HPD_IN_AND_DP_MODE_AND_HOST_IN;

		if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
			pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
	}
}

static void cs32g050_usb_dev_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	int type = -EPERM;
	bool usb2_connected = false;
	bool last_usb2_connected = false;
	bool mode_device = false;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	usb2_connected = is_usb2_connected(port_status);
	last_usb2_connected = is_usb2_connected(last_port_status);
	mode_device = is_mode_device(port_status);

	if ((!last_usb2_connected) && (usb2_connected)) { // usb step in
		if (mode_device)
			type = IRQ_HPD_IN_AND_USB31_MODE_AND_DEVICE_IN;
		else
			type = IRQ_HPD_IN_AND_USB31_MODE_AND_HOST_IN;
	} else {
		return;
	}

	if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
}

static void cs32g050_analog_earphone_handle(struct cs32g050_port_device *port_dev)
{
	pr_info("%s: notify USB_HEADPHONE IN.\n", __func__);
	write_process_code(port_dev->port_id, PROCESS_EARPHONE_IN, false, false);
	power_event_bnc_notify(POWER_BNT_HW_USB, POWER_NE_HW_USB_HEADPHONE, NULL);
}

static void cs32g050_analog_earphone_out_handle(struct cs32g050_port_device *port_dev)
{
	pr_info("%s: notify USB_HEADPHONE OUT.\n", __func__);
	write_process_code(port_dev->port_id, PROCESS_EARPHONE_OUT, false, false);
	power_event_bnc_notify(POWER_BNT_HW_USB, POWER_NE_HW_USB_HEADPHONE_OUT, NULL);
}

static void usb2_plug_out_handle(struct cs32g050_port_device *port_dev, u64 last_port_status)
{
	int type = -EPERM;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if (is_mode_device(last_port_status))
		type = IRQ_HPD_OUT_AND_NC_MODE_AND_DEVICE_OUT;
	else
		type = IRQ_HPD_OUT_AND_NC_MODE_AND_HOST_OUT;

	if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0)
		pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
}

static void cs32g050_DPIN_plug_in_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
    int status = 0;
	if (is_dp_connected(port_status) && is_dp_source_sink(port_status)) {
		if (get_plug_orien(port_status)) {
			status = DP_IN_STATUS_NEGATIVE;
		} else {
			status = DP_IN_STATUS_POSITIVE;
		}
		cs32g050_post_event(DPIN_EVENT, DPIN_CONFIG, status);
	} else {
		g_in_dpin = false;
		status = DP_IN_STATUS_UNSUPPORT;
		cs32g050_post_event(DPIN_EVENT, DPIN_CONFIG, status);
	}
	port_dev->last_port_status = 0x00;
}

static void cs32g050_DPIN_plug_out_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	if (g_in_dpin) {
		return;
	}
	port_dev->plug_orien = get_plug_orien(last_port_status);

	if (is_analog_earphones(last_port_status)) { // analog earphones device out
		cs32g050_analog_earphone_out_handle(port_dev);
		return;
	}

	if (is_hpd_high(last_port_status)) { // hpd step out
		set_dp_status(port_dev->port_id, false);
		cs32g050_hpd_step_out_handle(port_dev, last_port_status);
		msleep(100); // sleep 100ms
	}

	if (is_usb2_connected(last_port_status)) // usb device out
		usb2_plug_out_handle(port_dev, last_port_status);
}

static void cs32g050_DPIN_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	pr_info("%s: in port_id = %d\n", __func__, port_dev->port_id);
	if (is_data_connected(port_status)) {
		if (g_in_dpin)
			return;
		cs32g050_post_event(DPIN_EVENT, DPIN_PLUG_DEVICE_STATUS, DP_IN_STATUS_PLUG_IN);
		cs32g050_DPIN_plug_in_handle(port_dev, port_status, last_port_status);
	} else {
		cs32g050_post_event(DPIN_EVENT, DPIN_PLUG_DEVICE_STATUS, DP_IN_STATUS_PLUG_OUT);
		cs32g050_DPIN_plug_out_handle(port_dev, port_status, last_port_status);
		g_in_dpin = false;
	}
}

static void cs32g050_dp_dock_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 last_port_status)
{
	int type = -EPERM;
	if (is_dp_source_sink(port_status)) {
		pr_err("%s: DP_SOURCE_SINK, not upload.\n", __func__);
		return;
	}
	if (!is_dp_connected(last_port_status)) { // dp step in
		type = IRQ_HPD_OUT_AND_USB31_MODE_AND_HOST_OUT;
		if (cs32g050_event_notify_by_type(port_dev, type, last_port_status) != 0) {
			pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
		}
		msleep(100); // sleep 100ms
	}

	if (cs32g050_dp_dev_handle(port_dev, port_status, last_port_status) != 0) {
		cs32g050_dock_dev_handle(port_dev, port_status, last_port_status);
	}
}

static void cs32g050_role_swap_handle(struct cs32g050_port_device *port_dev, u64 port_status, u64 *last_port_status)
{
	int type = -EPERM;
	u64 last_status = *last_port_status;
	if (is_mode_device(last_status) && !is_mode_device(port_status)) {
		type = IRQ_HPD_OUT_AND_USB31_MODE_AND_DEVICE_OUT;
	} else if (is_data_connected(last_status) && !is_mode_device(last_status) && is_mode_device(port_status)) {
		type = IRQ_HPD_OUT_AND_USB31_MODE_AND_HOST_OUT;
    }

	if (type != -EPERM) {
		if (cs32g050_event_notify_by_type(port_dev, type, last_status) != 0)
			pr_err("%s: cs32g050_event_notify_by_type failed type = %d\n", __func__, type);
		*last_port_status = 0;
		msleep(100); // sleep 100ms
	}
}

static void cs32g050_port_status_parse(struct cs32g050_port_device *port_dev, u64 port_status)
{
	u64 last_port_status = 0;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	last_port_status = port_dev->last_port_status;
	port_dev->last_port_status = port_status;
	if (port_status == last_port_status && !is_hpd_irq(port_status)) {
		return;
	}

	pr_info("%s: read port[%d] status = 0X%X\n", __func__, port_dev->port_id, port_status);
	if (port_dev->port_id == 0 && ((g_support_dpin && g_cmd_pd_byte3 == CS32G050_DPIN_ON_CMD) || g_in_dpin)) {
		cs32g050_DPIN_handle(port_dev, port_status, last_port_status);
		return;
	}

	if (is_data_connected(port_status)) {
		port_dev->plug_orien = get_plug_orien(port_status);

		if (is_analog_earphones(port_status)) { // analog earphones device in
			cs32g050_analog_earphone_handle(port_dev);
			return;
		}
		cs32g050_role_swap_handle(port_dev, port_status, &last_port_status);
		if (is_dp_connected(port_status)) { // dp or dock device in
			cs32g050_dp_dock_handle(port_dev, port_status, last_port_status);
		} else { // usb device in
			cs32g050_usb_dev_handle(port_dev, port_status, last_port_status);
		}
	} else {
		port_dev->plug_orien = get_plug_orien(last_port_status);

		if (is_analog_earphones(last_port_status)) { // analog earphones device out
			cs32g050_analog_earphone_out_handle(port_dev);
			return;
		}

		if (is_hpd_high(last_port_status)) { // hpd step out
			set_dp_status(port_dev->port_id, false);
			cs32g050_hpd_step_out_handle(port_dev, last_port_status);
			msleep(100); // sleep 100ms
		}

		if (is_usb2_connected(last_port_status)) // usb device out
			usb2_plug_out_handle(port_dev, last_port_status);
	}
}

static void cs32g050_port_handle(struct cs32g050_port_device *port_dev)
{
	u64 port_status = 0;
	if ((!port_dev) || (!(port_dev->client))) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}
	if (g_pd_ic_mode) {
		mutex_lock(&cs32g050_mutex);
		if (cs32g050_clean_irq(port_dev, CS32G050_CLEAN_I2C_IRQ_CMD) != 0) {
			pr_err("%s: clean_i2c_irq failed\n", __func__);
			mutex_unlock(&cs32g050_mutex);
			return;
		}
		port_status = cs32g050_read_port_status(port_dev);
		mutex_unlock(&cs32g050_mutex);
	} else {
		if (cs32g050_write_request_pdphy(port_dev) != 0) {
			pr_err("%s: write_request transfer failed\n", __func__);
			return;
		}
		port_status = cs32g050_read_port_status_pdphy(port_dev);
	}

	#ifdef CONFIG_DFX_DEBUG_FS
		if (port_dev->dispatcher->use_pd_flag == NO_NEED_PD_FLAG) {
			pr_err("%s: NO_NEED_PD_FLAG, return\n", __func__);
			return;
		}
	#endif /* CONFIG_DFX_DEBUG_FS */

	if (is_port_status_fail(port_status)) {
		pr_err("%s: cs32g050_read_port_status failed port_status is 0x%llx\n", __func__, port_status);
		return;
	}

	cs32g050_modify_port_status(port_dev, &port_status);
	write_process_code(port_dev->port_id, (u8)(port_status & BYTE_FF), false, false);
	write_process_code(port_dev->port_id, (u8)(port_status >> OFFSET_8), false, false);
	pr_info("%s: after modify port[%d] status = 0X%llX\n", __func__, port_dev->port_id, port_status);
	if (is_mode_device(port_status)) {
		pr_err("%s: send usb connect.\n", __func__);
		power_event_bnc_notify(POWER_BNT_CONNECT, POWER_NE_USB_CONNECT, NULL);
	} else if (is_mode_device(port_dev->last_port_status)) {
		pr_err("%s: send usb disconnect.\n", __func__);
		power_event_bnc_notify(POWER_BNT_CONNECT, POWER_NE_USB_DISCONNECT, NULL);
	}

	if (is_data_connected(port_status) == false && is_data_connected(port_dev->last_port_status))
		cs32g050_fw_reboot_unattach(port_dev->port_id, port_dev->client);

	cs32g050_port_status_parse(port_dev, port_status);
	g_last_port_status[port_dev->port_id] = port_status;
	g_cs32g050_probe[port_dev->port_id] = false;
}

static irqreturn_t cs32g050_port_irq_handler(int irq, void *data)
{
	struct cs32g050_dispatcher *dispatcher = NULL;
	if (!data) {
		pr_err("%s: data in NULL!\n", __func__);
		return IRQ_HANDLED;
	}
	pr_err("%s: irq trigger!\n", __func__);
	write_process_code(RECORD_TO_ALL_PORT, PROCESS_IRQ_IN, false, false);
	if (g_pd_wake_ws != NULL) {
		g_pd_wake_ws_enable = true;
		__pm_stay_awake(g_pd_wake_ws);
		pr_info("%s: pd wake lock hold\n", __func__);
	}

	mod_timer(&pm_lock_timer, jiffies + msecs_to_jiffies(PM_WAKE_LOCK_TIMES));
	dispatcher = (struct cs32g050_dispatcher *)data;
	queue_work(dispatcher->wq, &dispatcher->work);
	return IRQ_HANDLED;
}

static int echub_pdphy_event_notifier_call(struct notifier_block *nb, unsigned long event, void *data)
{
	pr_info("%s: enter. event = 0X%X\n", __func__, event);
	switch (event) {
	case NOTIFY_PDPHY_IRQ:
		pr_info("%s: PD_phy irq notiry.\n", __func__);
		if (g_dispatcher_pdphy == NULL) {
			pr_err("%s: dispatcher is NULL!\n", __func__);
			return NOTIFY_OK;
		}
		queue_work(g_dispatcher_pdphy->wq, &g_dispatcher_pdphy->work);
		break;
    default:
		break;
	}
	return NOTIFY_OK;
}

static void cs32g050_port_handle_work(struct work_struct *work)
{
	struct cs32g050_port_device *port_dev = NULL;
	struct cs32g050_port_device *tmp = NULL;
	struct cs32g050_dispatcher *dispatcher = NULL;
	if (!work) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	if (g_pd_ic_mode) {
		dispatcher = container_of(work, struct cs32g050_dispatcher, work);
	} else {
		dispatcher = g_dispatcher_pdphy;
	}
    if (!dispatcher) {
		pr_err("%s: dispatcher is null\n", __func__);
		return;
    }
	list_for_each_entry_safe(port_dev, tmp, &dispatcher->dev_list, node)
		cs32g050_port_handle(port_dev);
}

static void cs32g050_cleanup(struct cs32g050_dispatcher *dispatcher)
{
	if (dispatcher != NULL) {
		if (dispatcher->wq != NULL) {
			destroy_workqueue(dispatcher->wq);
		}
		kfree(dispatcher);
	}
}

static void cs32g050_setup_notify_event(void);
static struct cs32g050_dispatcher *cs32g050_create_dispatcher(struct cs32g050_port_device *port_dev, int gpio)
{
	int ret, irq;
	struct cs32g050_dispatcher *dispatcher = NULL;
	cs32g050_setup_notify_event();
	if ((!gpio_is_valid(gpio)) || (!port_dev)) {
		pr_err("%s: invalid parameter\n", __func__);
		goto error;
	}

	ret = gpio_request_one(gpio, GPIOF_IN, "cs32-multi-port");
	if (ret < 0) {
		pr_err("%s: failed to request gpio %d\n", __func__, gpio);
		goto error;
	}

	dispatcher = kzalloc(sizeof(struct cs32g050_dispatcher), GFP_KERNEL);
	if (!dispatcher) {
		pr_err("%s: no memory for dispatcher\n", __func__);
		goto error;
	}

	irq = gpio_to_irq(gpio);
	dispatcher->irq = irq;
	dispatcher->gpio = gpio;
	dispatcher->client = port_dev->client;
	#ifdef CONFIG_DFX_DEBUG_FS
		dispatcher->use_pd_flag = PD_INIT_FLAG;
		dispatcher->debug_dir = debugfs_create_dir("pd", NULL);
		if (IS_ERR_OR_NULL(dispatcher->debug_dir)) {
			pr_err("failed to create pd dir\n");
			goto error;
		}
	#endif /* CONFIG_DFX_DEBUG_FS */
	INIT_LIST_HEAD(&dispatcher->dev_list);
	INIT_WORK(&dispatcher->work, cs32g050_port_handle_work);
	dispatcher->wq = create_singlethread_workqueue("cs32-multi-port");
	if (!(dispatcher->wq)) {
		pr_err("%s: no workqueue for dispatcher\n", __func__);
		goto error;
	}

	ret = request_threaded_irq(irq, NULL, cs32g050_port_irq_handler,
		IRQF_SHARED | IRQF_TRIGGER_FALLING | IRQF_NO_SUSPEND | IRQF_ONESHOT, "cs32-multi-port", dispatcher);
	if (ret < 0) {
		pr_err("%s: request irq failed\n", __func__);
		goto error;
	}

	return dispatcher;
error:
	cs32g050_cleanup(dispatcher);
	gpio_free(gpio);
	return NULL;
}

static struct cs32g050_dispatcher *cs32g050_create_dispatcher_pdphy(struct cs32g050_port_device *port_dev)
{
	int ret;
	struct cs32g050_dispatcher *dispatcher = NULL;
	if (!port_dev) {
		pr_err("%s: invalid parameter\n", __func__);
		return NULL;
	}
 
	dispatcher = kzalloc(sizeof(struct cs32g050_dispatcher), GFP_KERNEL);
	if (!dispatcher) {
		pr_err("%s: no memory for dispatcher\n", __func__);
		return NULL;
	}
 
	dispatcher->client = port_dev->client;
	INIT_LIST_HEAD(&dispatcher->dev_list);
	INIT_WORK(&dispatcher->work, cs32g050_port_handle_work);
	dispatcher->wq = create_singlethread_workqueue("cs32-multi-port");
	if (!(dispatcher->wq)) {
		pr_err("%s: no workqueue for dispatcher\n", __func__);
		goto error;
	}
 
	g_hmi_event_nb.notifier_call = echub_pdphy_event_notifier_call;
	ret = hmi_event_bnc_register(HMI_PD_EVENT, &g_hmi_event_nb);
	if (ret != 0) {
		pr_err("%s: hmi event bnc register fail\n", __func__);
		goto error;
	}
 
	return dispatcher;
error:
	cs32g050_cleanup(dispatcher);
	return NULL;
}

static struct list_head dispatcher_list = LIST_HEAD_INIT(dispatcher_list);

static struct cs32g050_dispatcher *cs32g050_get_dispatcher(int gpio)
{
	struct cs32g050_dispatcher *dispatcher = NULL;
	if (!gpio_is_valid(gpio)) {
		pr_err("%s: invalid parameter\n", __func__);
		return NULL;
	}

	list_for_each_entry(dispatcher, &dispatcher_list, node) {
		if (dispatcher->gpio == gpio)
			return dispatcher;
	}
	return NULL;
}

static int cs32g050_assign_dispatcher_pdic(struct cs32g050_port_device *port_dev)
{
	int gpio = -EPERM;
	struct device_node *np = NULL;
	struct cs32g050_dispatcher *dispatcher = NULL;
	if ((!port_dev) || (!(port_dev->dev)) || (!(port_dev->dev->of_node))) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	np = port_dev->dev->of_node;
	gpio = of_get_named_gpio(np, "gpio_int", 0);
	if (gpio < 0) {
		pr_err("%s: failed to get gpio %d\n", __func__, gpio);
		return -EINVAL;
	}

	if (gpio_direction_input(gpio) < 0) {
		pr_err("%s: failed to set gpio %d as input pin\n", __func__, gpio);
		return -EINVAL;
	}

	dispatcher = cs32g050_get_dispatcher(gpio);
	if (dispatcher != NULL) {
		pr_err("%s: already have dispatcher\n", __func__);
		goto assign_dispatcher;
	}
	dispatcher = cs32g050_create_dispatcher(port_dev, gpio);
	if (!dispatcher) {
		pr_err("%s: failed to create dispatcher\n", __func__);
		return -EFAULT;
	}
	#ifdef CONFIG_DFX_DEBUG_FS
		use_pd_flag_debugfs_create_x32(use_pd_flag, dispatcher);
	#endif /* CONFIG_DFX_DEBUG_FS */
	list_add_tail(&dispatcher->node, &dispatcher_list);

assign_dispatcher:
	port_dev->dispatcher = dispatcher;
	list_add_tail(&port_dev->node, &dispatcher->dev_list);
	atomic_inc(&dispatcher->ref);
	return 0;
}

static int cs32g050_assign_dispatcher_pdphy(struct cs32g050_port_device *port_dev)
{
	struct cs32g050_dispatcher *dispatcher = NULL;
	if ((!port_dev) || (!(port_dev->dev)) || (!(port_dev->dev->of_node))) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}
 
	if (g_dispatcher_pdphy != NULL) {
		pr_info("%s: already have dispatcher\n", __func__);
		goto assign_dispatcher;
	}
 
	dispatcher = cs32g050_create_dispatcher_pdphy(port_dev);
	if (!dispatcher) {
		pr_err("%s: failed to create dispatcher\n", __func__);
		return -EFAULT;
	}
	g_dispatcher_pdphy = dispatcher;
 
assign_dispatcher:
	port_dev->dispatcher = g_dispatcher_pdphy;
	list_add_tail(&port_dev->node, &g_dispatcher_pdphy->dev_list);
	atomic_inc(&g_dispatcher_pdphy->ref);
	return 0;
}

static int cs32g050_assign_dispatcher(struct cs32g050_port_device *port_dev)
{
	int ret = -EPERM;
	g_cs32g050_probe[port_dev->port_id] = true;
	if (g_pd_ic_mode) {
		ret = cs32g050_assign_dispatcher_pdic(port_dev);
	} else {
		ret = cs32g050_assign_dispatcher_pdphy(port_dev);
	}
	return ret;
}
 
static void cs32g050_parse_product_dts(void)
{
	struct device_node *node = NULL;
	int usb_pd_ic_flag;
	node = of_find_compatible_node(NULL, NULL, "cs32g050,port0-pcui");
	if (node == NULL) {
		pr_err("%s: node not match\n", __func__);
		return;
	}
	int ret = 0;
	g_support_dpin = of_property_read_bool(node, "support_dpin");
	ret += of_property_read_u32(node, "usb_pd_ic_flag", &usb_pd_ic_flag);
	ret += of_property_read_u32(node, "usb_speed", &g_max_speed);
	if (ret != 0) {
		pr_err("%s: of_property_read_u32 failed\n", __func__);
		return;
	}
	g_pd_ic_mode = (usb_pd_ic_flag == PD_IC_MODE);
}

static int cs32g050_parse_dts(struct cs32g050_port_device *port_dev)
{
	struct device_node *np = NULL;
	int ret;

	if ((!port_dev) || (!(port_dev->dev)) || (!(port_dev->dev->of_node))) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	np = port_dev->dev->of_node;
	port_dev->first_update_addr = CS32G050_FIRMWARE_UPDATE_FIRST_ADDR;
	port_dev->firmware_update_delay = CS32G050_FIRMWARE_UPDATE_DELAY;
	port_dev->firmware_update_mode = CS32G050_FIRMWARE_UPDATE_DEFAULT_MODE;
	ret = of_property_read_u32(np, "first_update_addr", &port_dev->first_update_addr);
	ret += of_property_read_u32(np, "firmware_update_delay", &port_dev->firmware_update_delay);
	ret += of_property_read_u32(np, "firmware_update_mode", &port_dev->firmware_update_mode);
	ret += of_property_read_u32(np, "port_id", &port_dev->port_id);
	if (ret != 0) {
		pr_err("%s: of_property_read_u32 failed\n", __func__);
		return -EIO;
	}
	if (port_dev->port_id == 0)
		g_port0_dev = port_dev;

	return 0;
}

static void cs32g050_fw_update_work(struct work_struct *work)
{
	struct device_node *node = NULL;
	struct cs32g050_port_device *port_dev = NULL;

	if (!work) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}

	port_dev = container_of(work, struct cs32g050_port_device, fw_update_work.work);
	if ((!port_dev) || (!(port_dev->client)) || (!(port_dev->dev)) || (!(port_dev->dev->of_node))) {
		pr_err("%s: port_dev is invalid parameter\n", __func__);
		return;
	}

	node = port_dev->dev->of_node;
	if (port_dev->client->addr != port_dev->first_update_addr)
		wait_for_completion(&g_cs32g050_comp);

	pr_err("%s: firmware update begin client_addr = 0X%X\n", __func__, port_dev->client->addr);
	cs32g050_update(port_dev->port_id, port_dev->client, node, port_dev->firmware_update_mode);
	if (!completion_done(&g_cs32g050_comp))
		complete(&g_cs32g050_comp);

	pr_err("%s: firmware update done client_addr = 0X%X\n", __func__, port_dev->client->addr);
}

//Reserved for future modification.
static struct file_operations usb_hdc_debug_mode_fops = {
	.owner = THIS_MODULE,
};

static struct device *cs32g050_sysfs_create_group(
	const char *cls_name, const char *dev_name, const struct attribute_group *group)
{
	struct device *dev = NULL;

	if (!cls_name || !dev_name || !group) {
        pr_err("%s: invalid parameter\n", __func__);
        return NULL;
	}

	if (!g_dual_port_class) {
		g_dual_port_class = class_create(THIS_MODULE, cls_name);
		if (!g_dual_port_class) {
			pr_err("%s: class_create failed\n", __func__);
			return NULL;
		}
	}

	dev = device_create(g_dual_port_class, NULL, 0, NULL, "%s", dev_name);
	if (!dev) {
		pr_err("%s: device_create failed\n", __func__);
        return NULL;
	}

	if (sysfs_create_group(&dev->kobj, group) != 0) {
		pr_err("%s: sysfs_create_group failed\n", __func__);
        device_destroy(g_dual_port_class, 0);
		return NULL;
	}
	return dev;
}

static void cs32g050_sysfs_remove_group(struct device *dev, const struct attribute_group *group)
{
	if (!dev || !group) {
        pr_err("%s: invalid parameter\n", __func__);
        return;
	}
	sysfs_remove_group(&dev->kobj, group);
    put_device(dev);
	device_unregister(dev);
}

static void usb_node_create_group(void)
{
	for (int i = 0; (i < g_real_port_num && i < MAX_PORT_NUM); i++)
		g_usb_port_node_dev[i] = cs32g050_sysfs_create_group(DUAL_PD_CLASS_NAME,
		g_usb_port_node_name[i], pd_node_attr_groups[i]);
}

static void usb_node_remove_group(void)
{
	for (int i = 0; (i < g_real_port_num && i < MAX_PORT_NUM); i++)
		cs32g050_sysfs_remove_group(g_usb_port_node_dev[i], pd_node_attr_groups[i]);
}

static int usb_hdc_debug_mode_probe(void)
{
	int ret = 0;
	struct device *i_device = NULL;
	ret = alloc_chrdev_region(&g_devno, 0, 1, STR_DEBUG_NODE);
	if (ret < 0) {
		pr_err("%s: alloc_chrdev_region fail.\n", __func__);
		return ret;
	}
	cdev_init(&g_cdev, &usb_hdc_debug_mode_fops);
	ret = cdev_add(&g_cdev, g_devno, 1);
	if (ret < 0) {
		pr_err("%s: cdev_add fail.\n", __func__);
		return ret;
	}
	g_class = class_create(THIS_MODULE, STR_DEBUG_NODE);
	if (!g_class) {
		pr_err("%s: class_create fail.\n", __func__);
		cdev_del(&g_cdev);
		unregister_chrdev_region(&g_cdev, 1);
		return -EINVAL;
	}
	i_device = device_create(g_class, NULL, g_devno, NULL, STR_DEBUG_NODE);
	if (!i_device) {
		pr_err("%s: device_create fail.\n", __func__);
		cdev_del(&g_cdev);
		unregister_chrdev_region(&g_cdev, 1);
		class_destroy(g_class);
		return -EINVAL;
	}
	pr_err("%s: device create success.\n", __func__);
	return 0;
}

static void usb_hdc_debug_mode_remove(void)
{
	pr_err("%s: node remove enter.\n", __func__);
	usb_node_remove_group();
	device_destroy(g_class, g_devno);
	cdev_del(&g_cdev);
	class_destroy(g_class);
	unregister_chrdev_region(g_devno, 1);
	pr_err("%s: device remove success.\n", __func__);
}

static void cs32g050_ready_to_attention(int value)
{
	union cs32g050_reg_data regdata;
	if (!g_port0_dev->client) {
		pr_err("%s: invalid parameter", __func__);
		return;
	}
	regdata.data = 0;
	regdata.u8_data[0] = 0x06;
	regdata.u8_data[1] = 0x04;
	regdata.u8_data[REGDATA_U8_NUM] = 0x50;
	g_in_dpin = true;
	pr_info("%s: cmd = 0X%X\n", __func__, regdata.data);
	if (cs32g050_i2c_write(g_port0_dev->client, (u8 *)&(regdata.data), I2C_WRITE_LEN) != 0) {
		pr_err("%s: cs32g050_i2c_write failed\n", __func__);
		return;
	}
	u64 port_status = 0;
	if (cs32g050_i2c_read(g_port0_dev->client, (u8 *)&port_status, CS32G050_STATUS_REG_LEN) != 0) {
		pr_err("%s: cs32g050_i2c_read failed\n", __func__);
		return;
	}
}
 
static void cs32g050_switch_events(int event_type, int event_data)
{
	pr_info("%s: event_type = %d, event_data = %d\n", __func__, event_type, event_data);
	if (event_type == DP_IN_SEND_ATTENTION) {
		cs32g050_ready_to_attention(event_data);
	} else {
		pr_err("%s: invalid event_type\n", __func__);
	}
}
 
static void cs32g050_setup_notify_event(void)
{
	if (g_support_dpin)
		lt6911gxd_register_event(PD_EVENT, cs32g050_switch_events);
}

static int cs32g050_multi_port_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret = -EPERM;
	struct cs32g050_port_device *port_dev = NULL;
	if (!client) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}
	g_real_port_num += 1;
	cs32g050_parse_product_dts();

	pr_err("%s: client_addr = 0X%X\n", __func__, client->addr);

	port_dev = devm_kzalloc(&client->dev, sizeof(struct cs32g050_port_device), GFP_KERNEL);
	if (!port_dev) {
		pr_err("%s: devm_kzalloc port_dev failed\n", __func__);
		return -ENOMEM;
	}
	port_dev->dev = &client->dev;
	port_dev->client = client;
	port_dev->last_port_status = 0;

	device_init_wakeup(&client->dev, true);

	if (!g_pd_wake_ws) {
		g_pd_wake_ws = wakeup_source_register(NULL, "pd_wakeup_rcv_msg");
		pr_err("%s: wakeup source registered\n", __func__);
	}

	ret = cs32g050_parse_dts(port_dev);
	if (ret != 0) {
		pr_err("%s: cs32g050 parse dts failed\n", __func__);
		return ret;
	}
	pr_err("%s: port_id = %d\n", __func__, port_dev->port_id);

	ret = cs32g050_assign_dispatcher(port_dev);
	if (ret != 0) {
		pr_err("%s: cs32g050_assign_dispatcher failed\n", __func__);
		return ret;
	}

	i2c_set_clientdata(client, port_dev);
    if (!(port_dev->dispatcher)) {
        pr_err("%s: port_dev->dispatcher is null\n", __func__);
		return -EINVAL;
    }
	queue_work(port_dev->dispatcher->wq, &port_dev->dispatcher->work);
	(void)flush_work(&port_dev->dispatcher->work);
	if (g_pd_ic_mode) {
		INIT_DELAYED_WORK(&port_dev->fw_update_work, cs32g050_fw_update_work);
		schedule_delayed_work(&port_dev->fw_update_work, msecs_to_jiffies(port_dev->firmware_update_delay));
	}

	pr_err("%s: port[%d] success\n", __func__, port_dev->port_id);
	return 0;
}

static int cs32g050_multi_port_remove(struct i2c_client *client)
{
	pr_err("%s: driver remove enter\n", __func__);
	struct cs32g050_port_device *port_dev = NULL;
	struct cs32g050_dispatcher *dispatcher = NULL;
	if (!client) {
		pr_err("%s: invalid parameter\n", __func__);
		return -EINVAL;
	}

	port_dev = i2c_get_clientdata(client);
    if ((!port_dev) || (!(port_dev->dispatcher))) {
		pr_err("%s: port_dev is invalid parameter\n", __func__);
		return -EINVAL;
    }
	dispatcher = port_dev->dispatcher;

	list_del(&port_dev->node);

	if (atomic_dec_return(&port_dev->dispatcher->ref) == 0) {
		if (g_pd_ic_mode) {
			list_del(&dispatcher->node);
			gpio_free(dispatcher->gpio);
		}
		destroy_workqueue(dispatcher->wq);
		kfree(dispatcher);
	}
	return 0;
}

int cs32g050_get_dp_status(void)
{
	return g_dp_status[0] | g_dp_status[1] | g_dp_status[INDEX_2];
}

MODULE_DEVICE_TABLE(i2c, cs32g050_multi_port_drv);
const static struct of_device_id cs32g050_multi_port_of_match[] = {
	{
		.compatible = "cs32g050,multi-port",
		.data = NULL,
	},
	{},
};

static int cs32g050_dev2irq(struct cs32g050_port_device *port_dev)
{
    struct device_node *np = NULL;
    np = port_dev->dev->of_node;
    int gpio = of_get_named_gpio(np, "gpio_int", 0);
    int irq = gpio_to_irq(gpio);
    return irq;
}

static void cs32g050_last_port_storage(struct cs32g050_port_device *port_dev)
{
	u64 port_status = 0;
	if ((!port_dev) || (!(port_dev->client))) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}
	if (g_pd_ic_mode) {
		mutex_lock(&cs32g050_mutex);
		if (cs32g050_clean_irq(port_dev, CS32G050_CLEAN_I2C_IRQ_CMD) != 0) {
			pr_err("%s: clean_i2c_irq failed\n", __func__);
			mutex_unlock(&cs32g050_mutex);
			return;
		}
		port_status = cs32g050_read_port_status(port_dev);
		mutex_unlock(&cs32g050_mutex);
	} else {
		if (cs32g050_write_request_pdphy(port_dev) != 0) {
			pr_err("%s: write_request transfer failed\n", __func__);
			return;
		}
		port_status = cs32g050_read_port_status_pdphy(port_dev);
	}
	if (is_port_status_fail(port_status)) {
		pr_err("%s: cs32g050_read_port_status failed\n", __func__);
		return;
	}
	cs32g050_modify_port_status(port_dev, &port_status);
	g_last_port_status[port_dev->port_id] = port_status;
	pr_err("%s: storage port[%d] status = 0X%llX\n", __func__, port_dev->port_id, port_status);
}
 
static void cs32g050_last_port_update(struct cs32g050_port_device *port_dev)
{
	u64 port_status = 0;
	if ((!port_dev) || (!(port_dev->client))) {
		pr_err("%s: invalid parameter\n", __func__);
		return;
	}
	if (g_pd_ic_mode) {
		mutex_lock(&cs32g050_mutex);
		if (cs32g050_clean_irq(port_dev, CS32G050_CLEAN_I2C_IRQ_CMD) != 0) {
			pr_err("%s: clean_i2c_irq failed\n", __func__);
			mutex_unlock(&cs32g050_mutex);
			return;
		}
		port_status = cs32g050_read_port_status(port_dev);
		mutex_unlock(&cs32g050_mutex);
	} else {
		if (cs32g050_write_request_pdphy(port_dev) != 0) {
			pr_err("%s: write_request transfer failed\n", __func__);
			return;
		}
		port_status = cs32g050_read_port_status_pdphy(port_dev);
	}
	if (is_port_status_fail(port_status)) {
		pr_err("%s: cs32g050_read_port_status failed\n", __func__);
		return;
	}
	cs32g050_modify_port_status(port_dev, &port_status);
	if (port_status == g_last_port_status[port_dev->port_id]) {
		pr_err("%s: port[%d] status = 0X%llX, did not change\n", __func__, port_dev->port_id, port_status);
		return;
	}
	port_dev->last_port_status = g_last_port_status[port_dev->port_id];
	pr_err("%s: port[%d] status = 0X%llX, different from last_status = 0X%llX \n",
		__func__, port_dev->port_id, port_status, port_dev->last_port_status);
	if (is_data_connected(port_status)) {
		if (is_data_connected(port_dev->last_port_status)) {
			cs32g050_port_status_parse(port_dev, 0);
			msleep(100); // sleep 100ms
		}		
		if (is_hpd_irq(port_status))
			g_dp_first_in[port_dev->port_id] = true;
	}
	cs32g050_port_status_parse(port_dev, port_status);
}

static int cs32g050_multi_port_pm_freeze(struct device *dev)
{
	struct cs32g050_port_device *port_dev = (struct cs32g050_port_device*)(dev->driver_data);
	cs32g050_last_port_storage(port_dev);
	int irq = cs32g050_dev2irq(port_dev);
	disable_irq(irq);
	pr_err("%s: disable irq %d\n", __func__, irq);
	return 0;
}
 
static int cs32g050_multi_port_pm_restore(struct device *dev)
{
	struct cs32g050_port_device *port_dev = (struct cs32g050_port_device*)(dev->driver_data);
	int irq = cs32g050_dev2irq(port_dev);
	enable_irq(irq);
	pr_err("%s: enable irq %d\n", __func__, irq);
	cs32g050_last_port_update(port_dev);
	return 0;
}

static int cs32g050_multi_port_pm_thaw(struct device *dev)
{
	cs32g050_multi_port_pm_restore(dev);
	return 0;
}

static int cs32g050_multi_port_pm_suspend(struct device *dev)
{
	if (!is_ulsr()) {
		return 0;
	}
	cs32g050_multi_port_pm_freeze(dev);
	return 0;
}
 
static int cs32g050_multi_port_pm_resume(struct device *dev)
{
	if (!is_ulsr()) {
		return 0;
	}
	cs32g050_multi_port_pm_restore(dev);
	return 0;
}

static const struct dev_pm_ops cs32g050_multi_port_pm_ops = {
    .suspend = cs32g050_multi_port_pm_suspend,
    .resume = cs32g050_multi_port_pm_resume,
    .freeze = cs32g050_multi_port_pm_freeze,
    .restore = cs32g050_multi_port_pm_restore,
    .thaw = cs32g050_multi_port_pm_thaw,
};

static struct i2c_driver cs32g050_multi_port_driver = {
	.probe = cs32g050_multi_port_probe,
	.remove = cs32g050_multi_port_remove,
	.driver = {
		.name = "cs32g050_multi_port_drv",
		.owner = THIS_MODULE,
		.pm = &cs32g050_multi_port_pm_ops,
		.of_match_table = of_match_ptr(cs32g050_multi_port_of_match),
	},
};

static void cs32g050_mutex_param_init(void)
{
	mutex_init(&cs32g050_mutex);
	if (g_pd_ic_mode)
		init_completion(&g_cs32g050_comp);
}

static int __init cs32g050_multi_port_init(void)
{
	// 初始化定时器
	timer_setup(&pm_lock_timer, pm_lock_callback, 0);
	int ret = i2c_add_driver(&cs32g050_multi_port_driver);
	cs32g050_mutex_param_init();
	usb_node_create_group();
	if (!g_debug_node_exist) {
		if (usb_hdc_debug_mode_probe() == 0) {
			g_debug_node_exist = true;
		}
	}
	if (ret != 0)
		pr_err("%s: i2c_add_driver error!!!\n", __func__);

	return ret;
}

static void __exit cs32g050_multi_port_exit(void)
{
	i2c_del_driver(&cs32g050_multi_port_driver);
	if (g_debug_node_exist) {
		usb_hdc_debug_mode_remove();
		g_debug_node_exist = false;
	}
	del_timer(&pm_lock_timer);
}


late_initcall(cs32g050_multi_port_init);
module_exit(cs32g050_multi_port_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("cs32g050 multi port driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");