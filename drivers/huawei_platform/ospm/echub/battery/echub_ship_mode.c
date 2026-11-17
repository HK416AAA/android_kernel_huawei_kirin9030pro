/*
 * echub_ship_mode.c
 *
 * echub_ship_mode driver for echub
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
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
#include <linux/fs.h>
#include <securec.h>

#include "echub_battery.h"
#include "ospm_printf.h"

#define SET_MFG_TEST_MODE                    0x0408
#define READ_MFG_TEST_MODE_CMD               0x0488
#define SET_MFG_MODE                         0x0409
#define READ_MFG_MODE_CMD                    0x0489
#define SET_BATT_TEST_MODE_CMD               0x0440
#define SET_SHIP_MODE_STATE_CMD              0x0452
#define READ_SHIP_MODE_STATE_CMD             0x04C2
#define PWR_BUTTON_MODE_CMD                  0x04A4

#define GET_MFG_MODE_CMD                0x0283
#define SET_PD_TEST_MODE_CMD            0x0430
#define GET_PD_TEST_MODE_CMD            0x04B0
#define SET_GET_SCP_UFCS_CMD            0x04AD
#define SET_CHARGER_TEST_MODE_CMD       0x0440
#define GET_CHARGER_TEST_MODE_CMD       0x04C0
#define SET_CHARGER_NUM_CMD             0x0449
#define GET_CHARGER_CURRENT_CMD         0x044B
#define CHG_CMD_OUTPUT_LEN              4
#define SET_FAN_TEST_MODE_CMD           0x0401
#define GET_FAN_TEST_MODE_CMD           0x0481
#define SET_FAN_SPEED_CMD               0x0402
#define GET_FAN_SPEED_CMD               0x0482
#define SET_LIQUIDCOOL_TEST_MODE_CMD    0x0403
#define GET_LIQUIDCOOL_TEST_MODE_CMD    0x0483
#define SET_LIQUIDCOOL_STATUS_CMD       0x0404
#define GET_LIQUIDCOOL_STATUS_CMD       0x0484
#define SET_LED_TEST_MODE_CMD           0x0406
#define GET_LED_TEST_MODE_CMD           0x0486
#define SET_LED_STATUS_CMD              0x0407
#define GET_LED_STATUS_CMD              0x0487
#define CMD_ERROR                       1
#define NOT_MFG_MODE                    2

static bool g_mfg_mode = false; // not mfg mode default
static u8 g_pd_test_port = 1; // pd port start from 1, so default 1
static u8 g_led_test_type = 0; // default power led

static ssize_t mfg_test_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf);
static ssize_t mfg_test_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count);
static ssize_t mfg_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf);
static ssize_t mfg_mode_exit(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count);
static ssize_t ship_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf);
static ssize_t ship_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count);
static ssize_t powerbutton_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf);
static ssize_t powerbutton_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count);

static DEVICE_ATTR(mfg_mode, 0660, mfg_mode_show, mfg_mode_exit);
static DEVICE_ATTR(mfg_test_mode, 0660, mfg_test_mode_show, mfg_test_mode_store);
static DEVICE_ATTR(ship_mode, 0660, ship_mode_show, ship_mode_store);
static DEVICE_ATTR(powerbutton_mode, 0660, powerbutton_mode_show, powerbutton_mode_store);

static const struct attribute *mfg_attrs[] = {
    &dev_attr_mfg_test_mode.attr,
    &dev_attr_mfg_mode.attr,
    &dev_attr_ship_mode.attr,
    &dev_attr_powerbutton_mode.attr,
    NULL
};

static ssize_t mfg_test_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("show mfg test mode di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, READ_MFG_TEST_MODE_CMD, &wb, 0, &rb, 1);
    if (ret) {
        echub_err("get mfg test mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t mfg_test_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set mfg test mode di is null\n");
        return -ENODEV;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err(" mfg test mode incorrect format\n");
        return -EINVAL;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_MFG_TEST_MODE, &wb, 1, &rb, 0);
    if (ret) {
        echub_err("set mfg test mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t mfg_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("show mfg mode di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, READ_MFG_MODE_CMD, &wb, 0, &rb, 1);
    if (ret) {
        echub_err("get mfg mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t mfg_mode_exit(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("exit mfg mode di is null\n");
        return -ENODEV;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("exit mfg mode incorrect format\n");
        return -EINVAL;
    }
    if (wb != 0) {
        echub_err("input error mfg mode %d\n", wb);
        return -EINVAL;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_MFG_MODE, &wb, 1, &rb, 0);
    if (ret) {
        echub_err("exit mfg mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t ship_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    unsigned char test_mode = 1;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("show ship mode state di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_BATT_TEST_MODE_CMD, &test_mode, 1, &rb, 0);
    if (ret) {
        echub_err("enter test ship mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, READ_SHIP_MODE_STATE_CMD, &wb, 0, &rb, 1);
    if (ret) {
        echub_err("enter test ship mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t ship_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    unsigned char test_mode = 1;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set ship mode state di is null\n");
        return -ENODEV;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("%s incorrect format\n", __func__);
        return -EINVAL;
    }
    if (wb > 1) {
        echub_err("%s  input error ship mode %d\n", __func__, wb);
        return -EINVAL;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_BATT_TEST_MODE_CMD, &test_mode, 1, &rb, 0);
    if (ret) {
        echub_err("enter test ship mode %d failed, ret=%d\n", wb, ret);
        return -CMD_ERROR;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_SHIP_MODE_STATE_CMD, &wb, 1, &rb, 0);
    if (ret) {
        echub_err("set ship mode %d failed, ret=%d\n", wb, ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t powerbutton_mode_show(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();

    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("show powerbutton mode, di is null\n");
        return -ENODEV;
    }

    ret = di->echub_dev->transfer_func(di->echub_dev, PWR_BUTTON_MODE_CMD, &wb, 1, &rb, 1);
    if (ret) {
        echub_err("get powerbutton mode failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t powerbutton_mode_store(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();

    if (!buf || !di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set powerbutton mode, di is null\n");
        return -ENODEV;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("%s incorrect format\n", __func__);
        return -EINVAL;
    }
    if (wb != 1 && wb != 2) { // 1:disable; 2:enable
        echub_err("%s  input error powerbutton mode %d\n", __func__, wb);
        return -EINVAL;
    }

    echub_err("%s  input powerbutton mode %d : (1 - disable; 2 - enable)\n", __func__, wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, PWR_BUTTON_MODE_CMD, &wb, 1, &rb, 1);
    if (ret) {
        echub_err("set powerbutton mode %d failed, ret=%d\n", wb, ret);
        return -CMD_ERROR;
    }

    return count;
}

void echub_mfg_sysfs_create(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
    if (di == NULL) {
        echub_err("creat mfg sysfs di is null\n");
        return;
    }
	if (sysfs_create_files(&di->dev->kobj, mfg_attrs)) {
		echub_err("failed to create mfg sysfs");
	}
}

void echub_mfg_sysfs_remove(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
    if (di == NULL) {
        echub_err("remove mfg sysfs di is null\n");
        return;
    }
	sysfs_remove_files(&di->dev->kobj, mfg_attrs);
}

static ssize_t pd_test_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get pd test mode failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_PD_TEST_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get pd test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t pd_test_mode_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set pd test mode failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set pd test mode failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set pd test mode failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set pd test mode: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_PD_TEST_MODE_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set pd test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t chg_protocol_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    unsigned char wb[NUM_2];
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get chg protocol failed, di is null\n");
        return -ENODEV;
    }

    wb[0] = g_pd_test_port;
    wb[1] = 0; // read protocal type
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_GET_SCP_UFCS_CMD, wb, NUM_2, &rb, 1);
    if (ret) {
        echub_err("get port %d chg protocol failed, cmd ret=%d\n", wb[0], ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t chg_protocol_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char rb = 0;
    unsigned char wb[NUM_2];
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set chg protocol failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set chg protocol failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d %d", &wb[0], &wb[1]) != 2) { // get 2 paras from buf
        echub_err("set chg protocol failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set chg protocol: port %d, protocol type %d\n", wb[0], wb[1]);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_GET_SCP_UFCS_CMD, wb, NUM_2, &rb, 1);
    if (ret) {
        echub_err("set chg protocol failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    g_pd_test_port = wb[0];
    return count;
}

static ssize_t charger_test_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get charger test mode failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_CHARGER_TEST_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get charger test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t charger_test_mode_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set charger test mode failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set charger test mode failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set charger test mode failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set charger test mode: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_CHARGER_TEST_MODE_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set charger test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t charger_test_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb[CHG_CMD_OUTPUT_LEN];
    int cur_chg1;
    int cur_chg2;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get charger current failed, di is null\n");
        return -ENODEV;
    }

    ret = di->echub_dev->transfer_func(di->echub_dev, GET_CHARGER_CURRENT_CMD, NULL, 0, rb, CHG_CMD_OUTPUT_LEN);
    if (ret) {
        echub_err("get charger current failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    cur_chg1 = (rb[1] << NUM_8) | rb[0];
    cur_chg2 = (rb[NUM_3] << NUM_8) | rb[NUM_2];
    return sprintf_s(buf, PAGE_SIZE, "%d %d\n", cur_chg1, cur_chg2);
}

static ssize_t charger_test_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set charger test num failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set charger test num failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set charger test num failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set charger test num: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_CHARGER_NUM_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set charger test num failed, ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t fan_test_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get fan test mode failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_FAN_TEST_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get fan test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t fan_test_mode_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set fan test mode failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set fan test mode failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set fan test mode failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set fan test mode: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_FAN_TEST_MODE_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set fan test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t fan_speed_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char wb = 0;
    unsigned char rb = 0;
    int speed_fan0;
    int speed_fan1;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get fan speed failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_FAN_SPEED_CMD, &wb, 1, &rb, 1);
    if (ret) {
        echub_err("get fan0 speed failed, cmd ret=%d\n", ret);
        speed_fan0 = -1;
    } else {
        echub_info("get fan0 speed %d from EC\n", rb);
        speed_fan0 = rb * 100; // 100 unit
    }

    wb = 1;
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_FAN_SPEED_CMD, &wb, 1, &rb, 1);
    if (ret) {
        echub_err("get fan1 speed failed, cmd ret=%d\n", ret);
        speed_fan1 = -1;
    } else {
        echub_err("get fan1 speed %d from EC\n", rb);
        speed_fan1 = rb * 100; // 100 unit
    }

    return sprintf_s(buf, PAGE_SIZE, "%d %d\n", speed_fan0, speed_fan1);
}

static ssize_t fan_speed_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    u8 fan_id = 0;
    u8 fan_speed = 0;
    unsigned char wb[NUM_2];
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set fan speed failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set fan speed failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d %d", &fan_id, &fan_speed) != 2) { // get 2 paras from buf
        echub_err("set fan speed failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set fan %d speed %d\n", fan_id, fan_speed);
    wb[0] = fan_id;
    wb[1] = fan_speed;
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_FAN_SPEED_CMD, wb, NUM_2, NULL, 0);
    if (ret) {
        echub_err("set fan speed failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t liquidcool_test_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get liquidcool test mode failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_LIQUIDCOOL_TEST_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get liquidcool test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t liquidcool_test_mode_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set liquidcool test mode failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set liquidcool test mode failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set liquidcool test mode failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set liquidcool test mode: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_LIQUIDCOOL_TEST_MODE_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set liquidcool test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t liquidcool_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb[NUM_3];
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get liquidcool status failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_LIQUIDCOOL_STATUS_CMD, NULL, 0, rb, NUM_3);
    if (ret) {
        echub_err("get liquidcool status failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }

    return sprintf_s(buf, PAGE_SIZE, "%d %d %d\n", rb[0], rb[1], rb[NUM_2]);
}

static ssize_t liquidcool_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set liquidcool failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set liquidcool failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set liquidcool failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set liquidcool: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_LIQUIDCOOL_STATUS_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set liquidcool failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t led_test_mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get led test mode failed, di is null\n");
        return -ENODEV;
    }
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_LED_TEST_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get led test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t led_test_mode_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set led test mode failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set led test mode failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d", &wb) != 1) {
        echub_err("set led test mode failed, incorrect format\n");
        return -EINVAL;
    }
    echub_info("set led test mode: %d\n", wb);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_LED_TEST_MODE_CMD, &wb, 1, NULL, 0);
    if (ret) {
        echub_err("set led test mode failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    return count;
}

static ssize_t led_status_show(struct device *dev, struct device_attribute *attr, char *buf)
{
    int ret;
    unsigned char rb = 0;
    unsigned char wb;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("get led status failed, di is null\n");
        return -ENODEV;
    }

    wb = g_led_test_type;
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_LED_STATUS_CMD, &wb, 1, &rb, 1);
    if (ret) {
        echub_err("get led %d status failed, cmd ret=%d\n", wb, ret);
        return -CMD_ERROR;
    }

    return sprintf_s(buf, PAGE_SIZE, "%d\n", rb);
}

static ssize_t led_status_store(struct device *dev,
        struct device_attribute *attr, const char *buf, size_t count)
{
    int ret;
    unsigned char wb[NUM_2] = {0};
    u8 led_type = 0;
    u8 led_status = 0;
    struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("set led status failed, di is null\n");
        return -ENODEV;
    }
    if (!g_mfg_mode) {
        echub_err("set led status failed, not mfg mode\n");
        return -NOT_MFG_MODE;
    }
    if (sscanf_s(buf, "%d %d", &led_type, &led_status) != 2) { // get 2 paras from buf
        echub_err("set led status failed, incorrect format\n");
        return -EINVAL;
    }
    wb[0] = led_type;
    wb[1] = led_status;
    echub_info("set led %d to status %d\n", wb[0], wb[1]);
    ret = di->echub_dev->transfer_func(di->echub_dev, SET_LED_STATUS_CMD, wb, NUM_2, NULL, 0);
    if (ret) {
        echub_err("set led status failed, cmd ret=%d\n", ret);
        return -CMD_ERROR;
    }
    g_led_test_type = wb[0];
    return count;
}

static DEVICE_ATTR(pd_test_mode, 0660, pd_test_mode_show, pd_test_mode_store);
static DEVICE_ATTR(chg_protocol, 0660, chg_protocol_show, chg_protocol_store);
static DEVICE_ATTR(charger_test_mode, 0660, charger_test_mode_show, charger_test_mode_store);
static DEVICE_ATTR(charger_test, 0660, charger_test_show, charger_test_store);
static DEVICE_ATTR(fan_test_mode, 0660, fan_test_mode_show, fan_test_mode_store);
static DEVICE_ATTR(fan_speed, 0660, fan_speed_show, fan_speed_store);
static DEVICE_ATTR(liquidcool_test_mode, 0660, liquidcool_test_mode_show, liquidcool_test_mode_store);
static DEVICE_ATTR(liquidcool, 0660, liquidcool_show, liquidcool_store);
static DEVICE_ATTR(led_test_mode, 0660, led_test_mode_show, led_test_mode_store);
static DEVICE_ATTR(led_status, 0660, led_status_show, led_status_store);

static const struct attribute *mmi_interface_attrs[] = {
    &dev_attr_pd_test_mode.attr,
    &dev_attr_chg_protocol.attr,
    &dev_attr_charger_test_mode.attr,
    &dev_attr_charger_test.attr,
    &dev_attr_fan_test_mode.attr,
    &dev_attr_fan_speed.attr,
    &dev_attr_liquidcool_test_mode.attr,
    &dev_attr_liquidcool.attr,
    &dev_attr_led_test_mode.attr,
    &dev_attr_led_status.attr,
    NULL
};

static u8 get_mfg_mode(struct echub_batt_device_info *di)
{
    int ret;
    u8 rb = 0;
    ret = di->echub_dev->transfer_func(di->echub_dev, GET_MFG_MODE_CMD, NULL, 0, &rb, 1);
    if (ret) {
        echub_err("get mfg_mode failed, ret=%d\n", ret);
        return 0;
    }

    echub_err("get mfg_mode %d\n", rb);
    return rb;
}

void echub_mmi_interface_sysfs_create(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
    if (!di || !di->echub_dev || !di->echub_dev->transfer_func) {
        echub_err("creat mfg sysfs di is null\n");
        return;
    }

    g_mfg_mode = get_mfg_mode(di);
	if (sysfs_create_files(&di->dev->kobj, mmi_interface_attrs)) {
		echub_err("failed to create mfg sysfs");
	}
}

void echub_mmi_interface_sysfs_remove(void)
{
	struct echub_batt_device_info *di = echub_get_batt_di();
    if (di == NULL) {
        echub_err("remove mfg sysfs di is null\n");
        return;
    }
	sysfs_remove_files(&di->dev->kobj, mmi_interface_attrs);
}