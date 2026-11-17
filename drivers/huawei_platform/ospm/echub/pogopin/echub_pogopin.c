/*
 * echub_pogopin.c
 *
 * pogopin driver for echub
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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/err.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/syscore_ops.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/notifier.h>
#include <linux/pm_wakeup.h>
#include <securec.h>
 
#include <chipset_common/hwpower/common_module/power_sysfs.h>
#ifdef CONFIG_SYS_PM_ULSR
#include <platform_include/cee/linux/ulsr.h>
#endif
#ifdef CONFIG_HISYSEVENT
#include <dfx/hiview_hisysevent.h>
#endif
#include "echub_i2c.h"
#include "ospm_printf.h"
#include "hmi/hmi.h"
 
#define EC_POGOPIN_GET_INFO_CMD      0x02D6

#define POGO_BASE_OCT                8
#define POGO_BASE_DEC                10
#define POGO_BASE_HEX                16

#define ECHUB_BT_MAC_LEN		     16
#define ECHUB_BT_MAC_PI_LEN          3

#define UEVENT_NAME_MAX_LEN          23
#define UEVENT_VALUE_MAX_LEN         31
#define UEVENT_DEV_INFO_LEN          (UEVENT_NAME_MAX_LEN + UEVENT_VALUE_MAX_LEN + 2)
#define UEVENT_DEV_INFO_MAX          512

#define EC_POGOPIN_MAC_LEN           6
#define EC_POGOPIN_MAC_LEN_MAX       10
#define EC_POGOPIN_MODEL_ID_LEN      3
#define KBD_INFO_RESERVED_LEN        2
#define POGO_INFO_RESERVED_LEN       7
#define EC_POGOPIN_I2C_RBUFF_LEN     16
#define EC_POGOPIN_POGO_STAT_BYTE    1
#define BT_ADDR_MAC_BYTE             0
#define SPARK_ADDR_MAC_BYTE          4

#define EC_POGOPIN_GET_MASTER_MAC    1
#define EC_POGOPIN_SEND_KBD_INFO     2
#define EC_POGOPIN_SEND_POGO_DFX     3

#define KBD_MAC_ADDR_LEN 18
#define KBD_MODEL_ID_LEN 7

#define POGO_HISYSEVENT_NUM 7

#pragma pack(1)
typedef struct {
	u8 op_type;
	u8 kbd_mac[EC_POGOPIN_MAC_LEN];
	u8 kbd_model_id[EC_POGOPIN_MODEL_ID_LEN];
	u8 kbd_submodel_id;
	u8 kbd_dev_version;
	u8 kbd_dev_business;
	u8 kbd_dev_sle;
	u8 reserved[KBD_INFO_RESERVED_LEN];
} echub_pogopin_kbd_info;

typedef struct {
	u8 op_type;
	u8 pogo_event;
	u8 charge_status;
	u8 snap_status;
	u8 c_port_status;
	u16 pogo_voltage;
	u16 pogo_current;
	u8 reserved[POGO_INFO_RESERVED_LEN];
} echub_pogopin_pogo_info;
#pragma pack()
struct echub_pogopin_kb_info {
	char name[UEVENT_NAME_MAX_LEN + 1];
	char value[UEVENT_VALUE_MAX_LEN + 1];
};

struct echub_pogopin_sw_dev_info {
	struct echub_pogopin_kb_info *key_info;
	u8 info_no; /* the informartion number of each device */
};

struct echub_pogopin_dev_info {
	struct device *dev;
	struct echub_i2c_dev *echub_dev;
	u8 master_mac[EC_POGOPIN_MAC_LEN_MAX];
	struct echub_pogopin_sw_dev_info dev_info;
	echub_pogopin_kbd_info kbd_info;
	echub_pogopin_pogo_info pogo_info;
};
enum echub_pogopin_sw_acc_info_index {
	ECHUB_POGOPIN_SW_ACC_INFO_BEGIN = 0,
	ECHUB_POGOPIN_SW_ACC_INFO_NO = ECHUB_POGOPIN_SW_ACC_INFO_BEGIN,
	ECHUB_POGOPIN_SW_ACC_INFO_STATE,
	ECHUB_POGOPIN_SW_ACC_INFO_MAC,
	ECHUB_POGOPIN_SW_ACC_INFO_MODEL_ID,
	ECHUB_POGOPIN_SW_ACC_INFO_SUBMODEL_ID,
	ECHUB_POGOPIN_SW_ACC_INFO_VERSION,
	ECHUB_POGOPIN_SW_ACC_INFO_BUSINESS,
	ECHUB_POGOPIN_SW_ACC_INFO_SLE,
	ECHUB_POGOPIN_SW_ACC_INFO_END,
};

enum echub_pogopin_sw_status {
	DISCONNECTED = 0,
	CONNECTED,
	PING_SUCC,
	ECHUB_POGOPIN_SW_KB_UNKNOWN,
};

static struct notifier_block g_hmi_pogopin_event_nb;

static struct echub_pogopin_kb_info g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_END] = {
	{ "DEVICENO", "2" },    // 2 MEANS pogopin
	{ "DEVICESTATE", "UNKNOWN" },
	{ "DEVICEMAC", "FF:FF:FF:FF:FF:FF" },
	{ "DEVICEMODELID", "000000" },
	{ "DEVICESUBMODELID", "00" },
	{ "DEVICEVERSION", "00" },
	{ "DEVICEBUSINESS", "00" },
	{ "DEVICESLEADDRFLAG", "0" },
};

static struct echub_pogopin_dev_info *g_ec_pogopin_di = NULL;
static struct device *g_dev = NULL;

u8 g_msg_bt_mac_addr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x57, 0xA8};

struct echub_pogopin_dev_info *get_pogopin_dev(void)
{
	return g_ec_pogopin_di;
}

enum hw_pogopin_sw_sysfs_type {
	HW_POGOPIN_SW_SYSFS_CHAGE_OPEN = 0,
	HW_POGOPIN_SW_SYSFS_BT_MAC_ADDR,
};
// 1. node write bt mac
static ssize_t hw_pogopin_sw_sysfs_show(struct device *dev, struct device_attribute *attr, char *buf);
static ssize_t hw_pogopin_sw_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count);

static struct power_sysfs_attr_info hw_pogopin_sw_sysfs_tbl[] = {
	power_sysfs_attr_rw(hw_pogopin_sw, 0644, HW_POGOPIN_SW_SYSFS_CHAGE_OPEN, chage_open),
	power_sysfs_attr_rw(hw_pogopin_sw, 0644, HW_POGOPIN_SW_SYSFS_BT_MAC_ADDR, bt_mac_addr),
};

static struct attribute *hw_pogopin_sw_sysfs_attrs[ARRAY_SIZE(hw_pogopin_sw_sysfs_tbl) + 1];

static const struct attribute_group hw_pogopin_sw_sysfs_attr_group = {
	.attrs = hw_pogopin_sw_sysfs_attrs,
};

static struct power_sysfs_attr_info *hw_pogopin_sw_sysfs_field_lookup(const char *name)
{
	int i;
	int limit = ARRAY_SIZE(hw_pogopin_sw_sysfs_tbl);
	int len;

	if (!name) {
		echub_err("[%s] name is null\n", __func__);
		return NULL;
	}

	len = strlen(name);

	for (i = 0; i < limit; i++) {
		if (!strncmp(name, hw_pogopin_sw_sysfs_tbl[i].attr.attr.name, len))
			break;
	}

	if (i >= limit)
		return NULL;

	return &hw_pogopin_sw_sysfs_tbl[i];
}

static ssize_t hw_pogopin_sw_sysfs_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	struct power_sysfs_attr_info *info = NULL;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;
	int len = 0;

	info = hw_pogopin_sw_sysfs_field_lookup(attr->attr.name);
	if (!info || !di) {
		echub_err("%s info or di is null\n", __func__);
		return -EINVAL;
	}

	if (!buf) {
		echub_err("%s buf is null\n", __func__);
		return -EINVAL;
	}

	switch (info->name) {
	case HW_POGOPIN_SW_SYSFS_CHAGE_OPEN:
		echub_info("%s: read chage_open succ\n", __func__);
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "1\n");
	case HW_POGOPIN_SW_SYSFS_BT_MAC_ADDR:
		echub_info("%s: read bt_mac_addr succ\n", __func__);
		return snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "FF:FF:FF:FF:FF:FF\n");
	default:
		echub_err("%s: NO THIS NODE:%d\n", __func__, info->name);
		break;
	}

	return len;
}

static int hw_pogopin_sw_ana_bt_mac(const char *buf, int len, struct echub_pogopin_dev_info *di)
{
	int i = 0;
	int j = 0;
	long val = 0;
	char hw_pogopin_sw_mac_addr[ECHUB_BT_MAC_PI_LEN] = {0};

	for (i = 0; i < len; i++) {
		if (snprintf_s(hw_pogopin_sw_mac_addr, ECHUB_BT_MAC_PI_LEN, ECHUB_BT_MAC_PI_LEN - 1, "%c%c",
			buf[i], buf[i + 1]) < 0) {
			echub_err("snprintf_s hw_pogopin_sw_mac_addr fail, index = %d\n", i);
			return -EINVAL;
		}
		if (kstrtol(hw_pogopin_sw_mac_addr, POGO_BASE_HEX, &val) < 0) {
			echub_err("%s: val is not valid\n", __func__);
			return -EINVAL;
		}
		g_msg_bt_mac_addr[j] = val;
		echub_info("[%s] master_mac[%d] = %02x\n", __func__, j, g_msg_bt_mac_addr[j]);
		j = j + 1;
		i = i + 1;
	}

	return 0;
}

static ssize_t hw_pogopin_sw_sysfs_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	struct power_sysfs_attr_info *info = NULL;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;
	int len = 0;

	info = hw_pogopin_sw_sysfs_field_lookup(attr->attr.name);
	if (!info || !di) {
		echub_err("%s info or di is null\n", __func__);
		return -EINVAL;
	}

	switch (info->name) {
	case HW_POGOPIN_SW_SYSFS_CHAGE_OPEN:
		break;
	case HW_POGOPIN_SW_SYSFS_BT_MAC_ADDR:
		len = strlen(buf);
		echub_info("[%s]: POGOPIN store mac buf[%s], len=%d\n", __func__, buf, len);
		if (len != ECHUB_BT_MAC_LEN) {
			echub_err("%s: buf len error is %d, correct len:%d\n", __func__, len, ECHUB_BT_MAC_LEN);
			return -EINVAL;
		}
		if (hw_pogopin_sw_ana_bt_mac(buf, len, di)) {
			echub_err("%s: hw_pogopin_sw_ana_bt_mac error\n", __func__);
			return -EINVAL;
		}
		break;
	default:
		echub_err("%s: NO THIS NODE:%d\n", __func__, info->name);
		break;
	}

	return count;
}

static void echub_pogopin_sw_sysfs_create_group(struct device *dev)
{
	power_sysfs_init_attrs(hw_pogopin_sw_sysfs_attrs,
		hw_pogopin_sw_sysfs_tbl, ARRAY_SIZE(hw_pogopin_sw_sysfs_tbl));

	power_sysfs_create_link_group("hw_power", "charger", "pogopin",
		dev, &hw_pogopin_sw_sysfs_attr_group);
}

static void echub_pogopin_sw_sysfs_remove_group(struct device *dev)
{
	power_sysfs_remove_link_group("hw_power", "charger", "pogopin",
		dev, &hw_pogopin_sw_sysfs_attr_group);
}
// 2. root read acc_dev_info
#ifdef CONFIG_SYSFS
static ssize_t pogopin_acc_dev_info_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int info_no;
	char acc_info[UEVENT_DEV_INFO_MAX] = { 0 };
	char *p_acc_info = acc_info;
	struct echub_pogopin_sw_dev_info *dev_info = NULL;
	struct echub_pogopin_kb_info *key_info = NULL;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;

	if (!di) {
		echub_err("%s di is null\n", __func__);
		goto out;
	}

	dev_info = &di->dev_info;
	if (!dev_info->key_info) {
		echub_info("acc dev info is null\n");
		goto out;
	}
	for (info_no = 0; info_no < dev_info->info_no; info_no++) {
		key_info = dev_info->key_info + info_no;
		if (strlen(acc_info) >= (UEVENT_DEV_INFO_MAX - UEVENT_DEV_INFO_LEN))
			goto out;

		if (snprintf_s(p_acc_info, UEVENT_DEV_INFO_LEN,
			UEVENT_DEV_INFO_LEN - 1, "%s=%s,", key_info->name, key_info->value) < 0)
			echub_err("snprintf_s acc_info fail\n");
		/* info contain '=' and ',' two bytes */
		p_acc_info += strlen(key_info->name) + strlen(key_info->value) + 2;    //  2 bytes for '=' and ','
	}
	/* two info separated by ','; two devices separated by ';' */
	acc_info[strlen(acc_info) - 1] = '\0';
out:
	return scnprintf(buf, PAGE_SIZE, "%s\n", acc_info);
}

static DEVICE_ATTR(dev, 0440, pogopin_acc_dev_info_show, NULL);

static struct attribute *pogopin_acc_attributes[] = {
	&dev_attr_dev.attr,
	NULL,
};

static const struct attribute_group pogopin_acc_attr_group = {
	.attrs = pogopin_acc_attributes,
};

static struct device *echub_pogopin_create_group(void)
{
	return power_sysfs_create_group("hw_accessory", "pogopin_monitor", &pogopin_acc_attr_group);
}

static void echub_pogopin_remove_group(struct device *dev)
{
	power_sysfs_remove_group(dev, &pogopin_acc_attr_group);
}
#else
static inline struct device *echub_pogopin_create_group(void)
{
    return NULL;
}

static inline void echub_pogopin_remove_group(struct device *dev)
{
}
#endif /* CONFIG_SYSFS */

static int pogopin_parse_dts(struct device_node *dev_node, struct echub_pogopin_dev_info *di)
{
	if (!dev_node || !di) {
		echub_err("%s dev_node is NULL!\n", __func__);
		return -ENODEV;
	}
 
	return 0;
}

static void echub_pogopin_print_kb_info(void)
{
	echub_info("============[pogopin] PRINT pogopin_kb_info start============\n");
	echub_info("            mac:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_MAC].value);
	echub_info("            model:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_MODEL_ID].value);
	echub_info("            sub_id:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_SUBMODEL_ID].value);
	echub_info("            dev_ver:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_VERSION].value);
	echub_info("            dev_biz:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_BUSINESS].value);
	echub_info("            dev_sle:%s\n", g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_SLE].value);
	echub_info("============[pogopin] PRINT pogopin_kb_info e n d============\n");
}

static void echub_pogopin_get_kbd_info(u8 *buffer, int len)
{
	int ret;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;

	if (!di) {
        echub_err("%s:%d di is null\n", __func__, __LINE__);
        return;
    }
	ret = memcpy_s(&(di->kbd_info), sizeof(di->kbd_info), buffer, len);
	if (ret != 0) {
		echub_err("memcpy pogopin kbd info failed:%d\n", ret);
		return;
	}

    // kbd_mac
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_MAC].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%02x:%02x:%02x:%02x:%02x:%02x", di->kbd_info.kbd_mac[NUM_5],
				di->kbd_info.kbd_mac[NUM_4], di->kbd_info.kbd_mac[NUM_3], di->kbd_info.kbd_mac[NUM_2],
				di->kbd_info.kbd_mac[1], di->kbd_info.kbd_mac[0]) < 0) {
		echub_err("%s:%d kbd_mac snprintf_s fail\n", __func__, __LINE__);
	}
	// kbd_model_id
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_MODEL_ID].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%02x%02x%02x", di->kbd_info.kbd_model_id[0],
				di->kbd_info.kbd_model_id[1], di->kbd_info.kbd_model_id[NUM_2]) < 0) {
		echub_err("%s:%d kbd_model_id snprintf_s fail\n", __func__, __LINE__);
	}
	// kbd_submodel_id
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_SUBMODEL_ID].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%02x", di->kbd_info.kbd_submodel_id) < 0) {
		echub_err("%s:%d kbd_submodel_id snprintf_s fail\n", __func__, __LINE__);
	}
	// kbd_dev_version
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_VERSION].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%02x", di->kbd_info.kbd_dev_version) < 0) {
		echub_err("%s:%d kbd_dev_version snprintf_s fail\n", __func__, __LINE__);
	}
	// kbd_dev_business
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_BUSINESS].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%02x", di->kbd_info.kbd_dev_business) < 0) {
		echub_err("%s:%d kbd_dev_business snprintf_s fail\n", __func__, __LINE__);
	}
	// kbd_dev_sle
	if (snprintf_s(g_echub_pogopin_kb_info[ECHUB_POGOPIN_SW_ACC_INFO_SLE].value, UEVENT_VALUE_MAX_LEN,
				UEVENT_VALUE_MAX_LEN - 1, "%x", di->kbd_info.kbd_dev_sle) < 0) {
		echub_err("%s:%d kbd_dev_sle snprintf_s fail\n", __func__, __LINE__);
	}
	echub_pogopin_print_kb_info();
}

static void echub_pogopin_get_pogo_info(u8 *buffer, int len)
{
	int ret;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;

	if (!di)
        echub_err("%s:%d di is null\n", __func__, __LINE__);

	ret = memcpy_s(&(di->pogo_info), sizeof(di->pogo_info), buffer, len);
	if (ret != 0) {
		echub_err("memcpy pogopin kbd info failed:%d\n", ret);
		return;
	}

	// print pogo_info buffer
	echub_info("============[pogopin] PRINT pogo_info start============\n");
	echub_info("            pogopin pogo_info.op_type = %d\n", di->pogo_info.op_type);
	echub_info("            pogopin pogo_info.pogo_event = %d\n", di->pogo_info.pogo_event);
	echub_info("            pogopin pogo_info.charge_status = %d\n", di->pogo_info.charge_status);
	echub_info("            pogopin pogo_info.snap_status = %d\n", di->pogo_info.snap_status);
	echub_info("            pogopin pogo_info.c_port_status = %d\n", di->pogo_info.c_port_status);
	echub_info("            pogopin pogo_info.pogo_voltage = 0x%04x\n", di->pogo_info.pogo_voltage);
	echub_info("            pogopin pogo_info.pogo_current = 0x%04x\n", di->pogo_info.pogo_current);
	echub_info("============[pogopin] PRINT pogo_info e n d============\n");
}

static void echub_pogopin_report_uevent(struct echub_pogopin_kb_info *kb_info)
{
	char *p_data = NULL;
	int i;
	char *p_uevent_data[UEVENT_DEV_INFO_LEN] = { 0 };
	char *p_data_tmp = NULL;
	u8 info_no = ECHUB_POGOPIN_SW_ACC_INFO_END;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;

	echub_err("%s accessory notify uevent begin process\n", __func__);
	if (!di || !di->dev) {
		echub_err("di or dev is null\n");
		return;
	}
	if (!kb_info) {
		echub_err("kb_info is null\n");
		return;
	}

	di->dev_info.info_no = info_no;
	di->dev_info.key_info = kb_info;

	p_data = kzalloc((info_no * UEVENT_DEV_INFO_LEN) + 1, GFP_KERNEL);
	if (!p_data) {
		echub_err("kzalloc p_data fail\n");
		return;
	}

	p_data_tmp = p_data;
	for (i = 0; i < info_no; i++) {
		if (snprintf_s(p_data_tmp, UEVENT_DEV_INFO_LEN, UEVENT_DEV_INFO_LEN - 1, "%s=%s",
			kb_info[i].name, kb_info[i].value) < 0)
			echub_err("[%s] snprintf_s fail\n", __func__);
		p_uevent_data[i] = p_data_tmp;
		p_data_tmp += UEVENT_DEV_INFO_LEN;
	}

	kobject_uevent_env(&di->dev->kobj, KOBJ_CHANGE, p_uevent_data);

	kfree(p_data);
	echub_err("accessory notify uevent end\n");
}

void echub_pogopin_sw_report_acc_info(struct echub_pogopin_kb_info *kb_info, enum echub_pogopin_sw_status type)
{
	if (type == DISCONNECTED) {
		if (snprintf_s(kb_info[ECHUB_POGOPIN_SW_ACC_INFO_STATE].value, UEVENT_VALUE_MAX_LEN,
			UEVENT_VALUE_MAX_LEN - 1, "%s", "DISCONNECTED") < 0)
			echub_err("snprintf_s report_acc_info_state_disconnect fail\n");
	} else if (type == CONNECTED) {
		if (snprintf_s(kb_info[ECHUB_POGOPIN_SW_ACC_INFO_STATE].value, UEVENT_VALUE_MAX_LEN,
			UEVENT_VALUE_MAX_LEN - 1, "%s", "CONNECTED") < 0)
			echub_err("snprintf_s report_acc_info_state_connect fail\n");
	} else if (type == PING_SUCC) {
		if (snprintf_s(kb_info[ECHUB_POGOPIN_SW_ACC_INFO_STATE].value, UEVENT_VALUE_MAX_LEN,
			UEVENT_VALUE_MAX_LEN - 1, "%s", "PING_SUCC") < 0)
			echub_err("snprintf_s report_acc_info_state_pingsucc fail\n");
	} else {
		echub_err("[%s] report invalid uevent type:%d\n", __func__, type);
		return;
	}
	echub_pogopin_report_uevent(kb_info);
}

static void echub_pogopin_get_master_mac(struct echub_pogopin_dev_info *di)
{
	int i;
	
	for (i = 0; i < EC_POGOPIN_MAC_LEN; i++)
		di->master_mac[i] = 0xFF;

	if (g_msg_bt_mac_addr[BT_ADDR_MAC_BYTE] != 0x01 || g_msg_bt_mac_addr[SPARK_ADDR_MAC_BYTE] != 0x02) {
		echub_err("[%s] Get Invalid MAC from BT, reset it to 0xFF\n", __func__);
		return;
	}

	for (i = 0; i < EC_POGOPIN_MAC_LEN; i++) {
		if (i < EC_POGOPIN_MAC_LEN / 2)    // 2 parts for MAC: 0~2-BT_MAC  3~5-SPARK_MAC
			di->master_mac[i] = g_msg_bt_mac_addr[i + 1];
		else
			di->master_mac[i] = g_msg_bt_mac_addr[i + 2];    // 2 BYTES Offset
	}
	echub_info("[%s] Get Real MAC[%s] from BT\n", __func__, di->master_mac);
}

static int echub_pogopin_get_operation_type(u8 *rbuffer, int len)
{
	int ret;
	struct echub_pogopin_dev_info *di = g_ec_pogopin_di;

	if (!di) {
        echub_err("%s:%d di is null\n", __func__, __LINE__);
        return -ENODEV;
    }

	echub_pogopin_get_master_mac(di);
	ret = di->echub_dev->transfer_func(di->echub_dev, EC_POGOPIN_GET_INFO_CMD, di->master_mac, EC_POGOPIN_MAC_LEN,
                                       rbuffer, len);
	if (ret) {
		echub_err("Got pogopin operation type failed:%d\n", ret);
		return ret;
	}
	return 0;
}

#ifdef CONFIG_HISYSEVENT
static int echub_hisysevent_put_pogo_data(struct hiview_hisysevent *event)
{
    struct echub_pogopin_dev_info *pogopin_dev = get_pogopin_dev();

    if (!event || !pogopin_dev) {
        echub_err("[%s] event or pogopin_dev is null\n", __func__);
        return -EINVAL;
    }

	if (hisysevent_put_integer(event, "EVENT_ID", pogopin_dev->pogo_info.pogo_event) != 0) {
		echub_err("[%s] failed to put EVENT_ID to event\n", __func__);
		return -EINVAL;
	}
	if (hisysevent_put_integer(event, "CHARGE_STATUS", pogopin_dev->pogo_info.charge_status) != 0) {
		echub_err("[%s] failed to put CHARGE_STATUS to event\n", __func__);
		return -EINVAL;
	}
	if (hisysevent_put_integer(event, "ISATTACHED", pogopin_dev->pogo_info.snap_status) != 0) {
		echub_err("[%s] failed to put ISATTACHED to event\n", __func__);
		return -EINVAL;
	}
	if (hisysevent_put_integer(event, "IS_SOURCE_MODE", pogopin_dev->pogo_info.c_port_status) != 0) {
		echub_err("[%s] failed to put IS_SOURCE_MODE to event\n", __func__);
		return -EINVAL;
	}
	if (hisysevent_put_integer(event, "VOLTAGE", pogopin_dev->pogo_info.pogo_voltage) != 0) {
		echub_err("[%s] failed to put VOLTAGE to event\n", __func__);
		return -EINVAL;
	}
	if (hisysevent_put_integer(event, "CURRENT", pogopin_dev->pogo_info.pogo_current) != 0) {
		echub_err("[%s] failed to put CURRENT to event\n", __func__);
		return -EINVAL;
	}

    return 0;
}

static void echub_pogopin_hisysevent_report(void)
{
    struct hiview_hisysevent *event = NULL;
    int ret;

    event = hisysevent_create("EC_FIRMWARE", "POGOPIN_STATUS", FAULT);
	if (!event) {
		echub_err("[%s] failed to create event\n", __func__);
		return;
	}

    ret = echub_hisysevent_put_pogo_data(event);
	if (ret != 0) {
		echub_err("[%s] failed to put value/str to event, ret=%d\n", __func__, ret);
		hisysevent_destroy(&event);
		return;
	}

	ret = hisysevent_write(event);
	if (ret != 0)
		echub_err("[%s] failed to write hisysevent fail\n", __func__);

	hisysevent_destroy(&event);
}

#else
static void echub_pogopin_hisysevent_report(void)
{
}
#endif

static void pogopin_qevent_callback(void)
{
    u8 opTypeBuffer[EC_POGOPIN_I2C_RBUFF_LEN] = {0};
    int ret;
    // get operation type from EC
    ret = echub_pogopin_get_operation_type(opTypeBuffer, EC_POGOPIN_I2C_RBUFF_LEN);
    if (ret) {
        echub_err("Got pogopin operation type failed:%d\n", ret);
        return;
    }

    switch (opTypeBuffer[0]) {
    case EC_POGOPIN_GET_MASTER_MAC:
        echub_info("[%s] Optype= %d : EC_POGOPIN_GET_MASTER_MAC\n", __func__, opTypeBuffer[0]);
		// send uevent PING_SUCC
		echub_pogopin_sw_report_acc_info(g_echub_pogopin_kb_info, PING_SUCC);
        break;
    case EC_POGOPIN_SEND_KBD_INFO:
        echub_info("[%s] Optype= %d : EC_POGOPIN_SEND_KBD_INFO\n", __func__, opTypeBuffer[0]);
		echub_pogopin_get_kbd_info(opTypeBuffer, EC_POGOPIN_I2C_RBUFF_LEN);
		// send uevent CONNECTED
		echub_pogopin_sw_report_acc_info(g_echub_pogopin_kb_info, CONNECTED);
        break;
    case EC_POGOPIN_SEND_POGO_DFX:
        echub_info("[%s] Optype= %d : EC_POGOPIN_SEND_POGO_DFX\n", __func__, opTypeBuffer[0]);
		echub_pogopin_get_pogo_info(opTypeBuffer, EC_POGOPIN_I2C_RBUFF_LEN);
		if (opTypeBuffer[EC_POGOPIN_POGO_STAT_BYTE] == 0) {
			// send uevent DISCONNECTED
			echub_pogopin_sw_report_acc_info(g_echub_pogopin_kb_info, DISCONNECTED);
		}
		if (opTypeBuffer[EC_POGOPIN_POGO_STAT_BYTE] >= 0x20 && opTypeBuffer[EC_POGOPIN_POGO_STAT_BYTE] <= 0x3f) {
			// 0x20~0x3f is pogopin error event
			echub_pogopin_hisysevent_report();
		}
        break;
    default:
        echub_err("[%s] Optype= %d : INVALID OPTYPE!\n", __func__, opTypeBuffer[0]);
        break;
    }
}

/**********************************************************
*  Function:       echub_pogopin_probe
*  Discription:    module probe
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_pogopin_probe(struct platform_device *pdev)
{
	struct echub_pogopin_dev_info *di = NULL;
	struct echub_i2c_dev *echub_dev = dev_get_drvdata(pdev->dev.parent);
    int ret;
 
	if (echub_dev == NULL) {
		echub_err("echub_dev is null, get echub_dev form tmp\n");
		echub_dev = get_echub_dev();
		if (echub_dev == NULL) {
			echub_err("echub_dev is NULL return\n");
			return -ENODEV;
		}
	}
 
	di = kzalloc(sizeof(*di), GFP_KERNEL);
	if (di == NULL) {
		echub_err("ec_pogopin_info is NULL!\n");
		return -ENOMEM;
	}
   
    di->dev = &pdev->dev;
	di->echub_dev = echub_dev;
 
	platform_set_drvdata(pdev, di);
	g_ec_pogopin_di = di;
    ret = pogopin_parse_dts(pdev->dev.of_node, g_ec_pogopin_di);
	if (ret < 0)
		echub_err("parse dts failed\n");
    g_dev = echub_pogopin_create_group();
	echub_pogopin_sw_sysfs_create_group(g_dev);
	/* FIRST LOAD DRIVER READ POGO ONE TIME FROM EC*/
	echub_info("[%s] Get pogo status from EC in probe\n", __func__);
	pogopin_qevent_callback();
	return 0;
}
 
/**********************************************************
*  Function:       echub_pogopin_remove
*  Discription:    module remove
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
static int echub_pogopin_remove(struct platform_device *pdev)
{
	struct echub_pogopin_dev_info *di = platform_get_drvdata(pdev);
 
    if (di == NULL) {
		echub_err("[%s]di is NULL!\n", __func__);
		return -ENODEV;
	}
 
    echub_pogopin_remove_group(g_dev);
	echub_pogopin_sw_sysfs_remove_group(g_dev);
	g_dev = NULL;
 
    platform_set_drvdata(pdev, NULL);
	kfree(di);
	di = NULL;
 
	return 0;
}
 
static struct of_device_id echub_pogopin_match_table[] = {
	{
		.compatible = "huawei,echub_pogopin",
		.data = NULL,
	},
	{
	},
};
static struct platform_driver echub_pogopin_driver = {
	.probe        = echub_pogopin_probe,
	.remove       = echub_pogopin_remove,
	.driver       = {
		.name           = "huawei,echub_pogopin",
		.owner          = THIS_MODULE,
		.of_match_table = of_match_ptr(echub_pogopin_match_table),
	},
};

static int hmi_pogopin_event_handler(struct notifier_block *nb, unsigned long event, void *data)
{
    if (event == NOTIFY_POPPIN_GET_KBD_EVENT) {
        pogopin_qevent_callback();
    } else {
        echub_err("[%s] event is invalid, event = %ld\n", __func__, event);
    }
    return NOTIFY_OK;
}

/**********************************************************
*  Function:       echub_pogopin_init
*  Discription:    module initialization
*  Parameters:     pdev:platform_device
*  return value:   0-sucess or others-fail
**********************************************************/
int __init echub_pogopin_init(void)
{
	int ret;

    g_hmi_pogopin_event_nb.notifier_call = hmi_pogopin_event_handler;
    ret = hmi_event_bnc_register(HMI_POPPIN_EVENT, &g_hmi_pogopin_event_nb);
    if (ret != 0) {
        echub_err("[%s]failed to init pogopin_notifier, ret=%d\n", __func__, ret);
        return ret;
    }
    return platform_driver_register(&echub_pogopin_driver);
}
 
/**********************************************************
*  Function:       echub_pogopin_exit
*  Discription:    module exit
*  Parameters:     NULL
*  return value:   NULL
**********************************************************/
void __exit echub_pogopin_exit(void)
{
	if (hmi_event_bnc_unregister(HMI_POPPIN_EVENT, &g_hmi_pogopin_event_nb) != 0)
        echub_err("[%s]failed to exit pogopin_notifier\n", __func__);
    platform_driver_unregister(&echub_pogopin_driver);
}
 
module_init(echub_pogopin_init);
module_exit(echub_pogopin_exit);
 
MODULE_ALIAS("armpc echub_pogopin");
MODULE_LICENSE("GPL");