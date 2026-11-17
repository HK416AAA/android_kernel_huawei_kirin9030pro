/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
 
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <securec.h>
#include "dkmd_dp_interface.h"
#include "edp_drv/edp_panel_drv.h"
#include "edp_sysfs.h"
#include "edp_sysfs_fact.h"
#include "edp_log.h"
#include "tcon_i2c/tcon_i2c_upgrade.h"
#include "tcon_i2c/tcon_i2c.h"
#include "tcon_uart/tcon_uart.h"
#include "edp_sysfs_common.h"

#define MAX_EDID_INFO_LEN (6 * 128)
#define MAX_ELEMENT_NUM 4
#define FACTORY_EDID_MAX_LEN 20
#define GET_FPS_DATA 0xFF00CA84
#define GET_DRIVER_LOCK1 0xff00c098
#define GET_DRIVER_LOCK2 0xff200300
#define GET_START_TIME 0xF10100D8
#define GET_MUTE_STATE 0xF10100DC
#define GET_DEMURA_STATE 0xFF01B84C
#define GET_DBV_DATA 0xFF01C034
#define GET_EDPRX_DATA1 0xFF400210
#define GET_EDPRX_DATA2 0xFF400214
#define GET_EDPRX_TRAINING_STATE1 0xFF500584
#define GET_EDPRX_TRAINING_STATE2 0xFF400214
#define GET_EDPRX_ERROR 0xFF500ECC
#define GET_EDPRX_FPS_COUNT 0xFF50147C
#define GET_DPCD_PSR_SWITCH 0xFF400170
#define GET_DPCD_PSR_STATE  0xFF402008
#define GET_EDPRX_SIGNAL_STATE 0xFF600010
#define EDP_FPS_STR_LENGTH_MAX 500

static int parse_factory_info(uint8_t* factory_edid_info, uint32_t len, struct edp_edid_info* edid_info)
{
	int ret = 0;
    struct edp_drv_info *tcon_info = NULL;

    if (!factory_edid_info || len < FACTORY_EDID_MAX_LEN) {
        edp_err("factory edid info is null");
        return -EINVAL;
    }

    tcon_info = get_edp_drv_info();
    if (!tcon_info) {
        edp_err("tcon_info is null\n");
        return -EINVAL;
    }
    if ((!tcon_info->sn_code || !tcon_info->vendor) && edp_get_panel_on_state()) {
        parse_edp_tcon_info();
    }
    ret = snprintf_s(edid_info->sncode, PANEL_SNCODE_LEN, PANEL_SNCODE_LEN - 1, "%08X", tcon_info->sn_code);
    if (ret != PANEL_SNCODE_LEN - 1) {
        edp_err("snprintf sncode fail, errlen = %d\n", ret);
        return ret;
    }
    ret = snprintf_s(edid_info->hardwareid, HARD_WARE_LEN, HARD_WARE_LEN - 1, "%04X%02X%02X",
                     tcon_info->vendor, factory_edid_info[2], factory_edid_info[3]);
    if (ret != HARD_WARE_LEN - 1) {
        edp_err("snprintf hardware id fail, errlen = %d\n\n", ret);
        return ret;
    }
    edp_info("hardware_id %s", edid_info->hardwareid);
    return 0;
}

int parse_edp_info(struct edp_edid_info* edid_info)
{
    uint32_t port_id;
    int ret = 0;
    struct dp_link_info dp_edid_info;

    if (!edid_info) {
        edp_err("dp_edid_info is null");
        return -EINVAL;
    }
    dp_edid_info.edid =  kmalloc(MAX_EDID_INFO_LEN, GFP_KERNEL);
    if (dp_edid_info.edid == NULL) {
        edp_err("malloc edid fail");
        return -ENOMEM;
    }
    dp_edid_info.edid_len = MAX_EDID_INFO_LEN;
    port_id = get_edp_port_id();
    ret = get_dp_edid_info(port_id, &dp_edid_info);
    if (ret) {
        edp_err("get_dp_edid_info fail\n");
        goto err;
    }
    edid_info->xres = dp_edid_info.xres;
    edid_info->yres = dp_edid_info.yres;
    edid_info->fps = dp_edid_info.fps;
    ret = parse_factory_info(dp_edid_info.factory_edid_info, sizeof(dp_edid_info.factory_edid_info), edid_info);
    if (ret) {
        edp_err("parse_factory_info fail\n");
        goto err;
    }
    kfree(dp_edid_info.edid);
    return 0;
err:
    kfree(dp_edid_info.edid);
    return -EINVAL;
}

static ssize_t edp_panel_sncode_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
    int ret;
    struct edp_edid_info edid_info;

    if (!buf) {
        edp_err("sncode show buf null\n");
        return 0;
    }
    ret = parse_edp_info(&edid_info);
    if (ret || !edid_info.sncode) {
        edp_err("[eDP] edp sn code is null\n");
        return 0;
    }
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", edid_info.sncode);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_hardware_id_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret;
    struct edp_edid_info edid_info;

    if (!buf) {
        edp_err("hardware id show buf null\n");
        return 0;
    }
    ret = parse_edp_info(&edid_info);
    if (ret || !edid_info.hardwareid) {
        edp_err("[eDP] edp hardware id is null\n");
        return 0;
    }
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "%s\n", edid_info.hardwareid);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static int fps_info_cat(char *out, int max_len)
{
    int len = 0;
    int ret = 0;
    int i;
    struct edp_drv_info *edp_info = NULL;
    edp_info = get_edp_drv_info();

    ret = snprintf_s(out + len, max_len - len, max_len - len, "current_fps:%d;", edp_info->current_fps);
    if (ret < 0)
        edp_err("snprintf current_fps fail\n");
    else
        len += ret;
    ret = snprintf_s(out + len, max_len - len, max_len - len, "default_fps:%d;support_fps_list:",
                     edp_info->default_fps);
    if (ret < 0)
        edp_err("snprintf default_fps fail\n");
    else
        len += ret;
    for (i = 0; i < edp_info->fps_list.fps_list_num; i++) {
        ret = snprintf_s(out + len, max_len - len, max_len - len, "%d", edp_info->fps_list.fps_list[i]);
        if (ret < 0)
            edp_err("snprintf fps fail\n");
        else
            len += ret;
        if (i < edp_info->fps_list.fps_list_num - 1) {
            ret = snprintf_s(out + len, max_len - len, max_len - len, ",");
            if (ret < 0)
                edp_err("snprintf , fail\n");
            else
                len += ret;
        } else {
            ret = snprintf_s(out + len, max_len - len, max_len - len, ";");
            if (ret < 0)
                edp_err("snprintf ; fail\n");
            else
                len += ret;
        }
    }
    return len;
}

static int product_info_cat(char *out, int max_len)
{
    int len = 0;
    int ret = 0;
    ret = snprintf_s(out, max_len, max_len, "product_panel_num:1;current_panel_id:0;");
    if (ret < 0)
        edp_err("snprintf product_info fail\n");
    else
        len += ret;
    return len;
}

static int panel_info_cat(char *out, int max_len)
{
    int len = 0;
    int ret = 0;
    struct edp_drv_info *edp_info = NULL;
    int i;

    edp_info = get_edp_drv_info();
    if (edp_info == NULL) {
        edp_err("edp_info is NULL\n");
        return len;
    }
    ret = snprintf_s(out + len, max_len - len, max_len - len, "panel_id:0;panel_type:");
    if (ret < 0)
        edp_err("snprintf panel_id fail\n");
    else
        len += ret;
    if (edp_info->oled_type == LTPS) {
        ret = snprintf_s(out + len, max_len - len, max_len - len, "LTPS;support_fps:");
        if (ret < 0)
            edp_err("snprintf LTPS fail\n");
        else
            len += ret;
    } else if (edp_info->oled_type == LTPO) {
        ret = snprintf_s(out + len, max_len - len, max_len - len, "LTPO;support_fps:");
        if (ret < 0)
            edp_err("snprintf LTPO fail\n");
        else
            len += ret;
    }
    for (i = 0; i < edp_info->fps_list.fps_list_num; i++) {
        ret = snprintf_s(out + len, max_len - len, max_len - len, "%d", edp_info->fps_list.fps_list[i]);
        if (ret < 0)
            edp_err("snprintf support_fps fail\n");
        else
            len += ret;
        if (i < edp_info->fps_list.fps_list_num - 1) {
            ret = snprintf_s(out + len, max_len - len, max_len - len, ",");
            if (ret < 0)
                edp_err("snprintf , fail\n");
            else
                len += ret;
        }
    }
    return len;
}

static void fps_scence_show(char *out, int max_len)
{
    int len = 0;
    len += fps_info_cat(out + len, max_len - len);
    len += product_info_cat(out + len, max_len - len);
    len += panel_info_cat(out + len, max_len - len);
}

static ssize_t edp_panel_res_fps_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
    int ret;
    struct edp_edid_info edid_info;
    char fps_str[EDP_FPS_STR_LENGTH_MAX] = {0};

	if (!buf) {
        edp_err("res fps show buf null\n");
        return 0;
    }
    ret = parse_edp_info(&edid_info);
    if (ret || !edid_info.xres || !edid_info.yres || !edid_info.fps) {
        edp_err("edp_sn_code is null\n");
        return 0;
    }

    fps_scence_show(fps_str, EDP_FPS_STR_LENGTH_MAX - 1);
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, fps_str);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_tconic_vendor_show(struct device *dev,
	struct device_attribute *attr, char *buf)
{
    int ret;
    uint16_t vendor = 0;
    uint16_t version = 0;

	if (!buf) {
        edp_err("tconic vendor show buf null\n");
        return 0;
    }
    if (edp_get_panel_on_state()) {
        mutex_lock(&tcon_i2c_mutex);
        ret = get_tconic_vendor(&vendor, &version);
        mutex_unlock(&tcon_i2c_mutex);
        if (ret) {
            edp_err("get tconic vendor fail %d\n", ret);
            return 0;
        }
    }
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "vendor=%x version=%x\n", vendor, version);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_brightness_path_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret;
    int port_id;
    char bkl_path[10];

	if (!buf) {
        edp_err("edp_panel_brightness_path_show buf is null\n");
        return 0;
    }
    port_id = get_edp_port_id();
    ret = get_dp_name(port_id, bkl_path);
    if (ret) {
        edp_err("get_dp_name fail!\n");
        return 0;
    }
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "/sys/class/%s/%s/brightness", bkl_path, bkl_path);
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static int parse_tcon_maintenance_info(struct edp_tcon_maintenance_info* tinfo)
{
    int ret;

    ret = get_tconic_vendor(&tinfo->vendor, &tinfo->version);
    if (ret) {
        edp_err("get tconic vendor fail %d\n", ret);
        return ret;
    }

    tinfo->fps = tcon_i2c_read_addr(GET_FPS_DATA);
    tinfo->driver_lock1 = tcon_i2c_read_addr(GET_DRIVER_LOCK1);
    tinfo->driver_lock2 = tcon_i2c_read_addr(GET_DRIVER_LOCK2);
    tinfo->start_time = tcon_i2c_read_addr(GET_START_TIME);
    tinfo->mute_state = tcon_i2c_read_addr(GET_MUTE_STATE);
    tinfo->demura_state = tcon_i2c_read_addr(GET_DEMURA_STATE);
    tinfo->dbv = tcon_i2c_read_addr(GET_DBV_DATA);
    tinfo->edprx_err_data1 = tcon_i2c_read_addr(GET_EDPRX_DATA1);
    tinfo->edprx_err_data2 = tcon_i2c_read_addr(GET_EDPRX_DATA2);
    tinfo->edprx_train_state1 = tcon_i2c_read_addr(GET_EDPRX_TRAINING_STATE1);
    tinfo->edprx_train_state2 = tcon_i2c_read_addr(GET_EDPRX_TRAINING_STATE2);
    tinfo->edprx_interrupts = tcon_i2c_read_addr(GET_EDPRX_ERROR);
    tinfo->edprx_fps_count = tcon_i2c_read_addr(GET_EDPRX_FPS_COUNT);
    tinfo->dpcd_psr_switch = tcon_i2c_read_addr(GET_DPCD_PSR_SWITCH);
    tinfo->dpcd_psr_state = tcon_i2c_read_addr(GET_DPCD_PSR_STATE);
    tinfo->edprx_signal_state = tcon_i2c_read_addr(GET_EDPRX_SIGNAL_STATE);

    return 0;
}

static ssize_t edp_tcon_debug_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;
    struct edp_tcon_maintenance_info tinfo;

    if (!buf) {
        edp_err("edp_tcon_debug_show buf is null\n");
        return 0;
    }
    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon is not on state!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }

    mutex_lock(&tcon_i2c_mutex);
    ret = parse_tcon_maintenance_info(&tinfo);
    mutex_unlock(&tcon_i2c_mutex);
    if (ret)
        edp_warn("parse tcon maintenance info error\n");

    edp_info("vendor=%04x version=%04x fps = 0x%08x driver_lock1 = 0x%08x driver_lock2 = 0x%08x\n",
        tinfo.vendor, tinfo.version, tinfo.fps, tinfo.driver_lock1, tinfo.driver_lock2);
    edp_info("start_time = 0x%08x, mute_state = 0x%08x demura_state = 0x%08x dbv = 0x%08x\n",
        tinfo.start_time, tinfo.mute_state, tinfo.demura_state, tinfo.dbv);
    edp_info("edprx_err_data1 = 0x%08x edprx_err_data2 = 0x%08x\n",
        tinfo.edprx_err_data1, tinfo.edprx_err_data2);
    edp_info("edprx_train_state1 = 0x%08x edprx_train_state2 = 0x%08x\n",
        tinfo.edprx_train_state1, tinfo.edprx_train_state2);
    edp_info("edprx_interrupts = 0x%08x edprx_fps_count = 0x%08x dpcd_psr_switch = 0x%08x dpcd_psr_state = 0x%08x\n",
        tinfo.edprx_interrupts, tinfo.edprx_fps_count, tinfo.dpcd_psr_switch, tinfo.dpcd_psr_state);
    edp_info("edprx_signal_state = 0x%08x\n", tinfo.edprx_signal_state);

    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "success\n");
    if (ret < 0) {
        edp_err("snprintf_s fail\n");
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_tcon_upgrade_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;

    if (!buf) {
        edp_err("edp_panel_tcon_upgrade_show buf is null\n");
        return 0;
    }
    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon is not on state!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }

    edp_info("NOW UPDATE MAIN_PARTITION !");
    ret = update_tconic_tool(buf, MAIN_PARTITION);

    return ret;
}

static ssize_t update_ext_tcon_tool(char *buf)
{
    uint32_t check_num = 0;
    int ret = 0;

    edp_info("NOW UPDATE EXT_PARTITION !");
    ret = update_tconic_tool(buf, EXT_PARTITION);
    if (strstr(buf, "fail")) {
        edp_err("update_tconic_tool errdate %s", buf);
        return ret;
    }

    mdelay(50); // delay 50ms between the upgrade and partition switch
    ret = edp_change_boot(buf, CHANGE_EXT);
    if (!ret) {
        edp_err("edp_change_boot fail\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "CHANGE EXT PARTITION FAIL!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }
    mdelay(20); // delay 20ms between the partition switch and partition check
    check_num = tcon_i2c_read_addr(CHECK_CHANGE_PARTITIONS_ADDR);
    if (check_num != CHANGE_EXT) {
        edp_err("check ext partition fail\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "CHANGE EXT PARTITION FAIL!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }
    edp_info("change ext partition success!");
    ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "edp ext tcon upgarde success!\n");
    if (ret < 0) {
        edp_err("snprintf_s fail %d", ret);
        return 0;
    }
    return ret;
}

static ssize_t edp_panel_ext_tcon_upgrade_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;

    if (!buf) {
        edp_err("edp_panel_ext_tcon_upgrade_show buf is null\n");
        return 0;
    }
    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon is not on state!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }

    ret = update_ext_tcon_tool(buf);
    return ret;
}

static ssize_t edp_panel_current_partition_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;

    if (!buf) {
        edp_err("edp_panel_current_partition_show buf is null\n");
        return 0;
    }
    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon is not on state!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }

    ret = edp_check_now_boot(buf);
    return ret;
}

static ssize_t edp_panel_switch_main_partition_show(struct device *dev,
    struct device_attribute *attr, char *buf)
{
    int ret = 0;

    if (!buf) {
        edp_err("edp_panel_switch_main_partition_show buf is null\n");
        return 0;
    }
    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        ret = snprintf_s(buf, PAGE_SIZE, PAGE_SIZE - 1, "tcon is not on state!");
        if (ret < 0) {
            edp_err("snprintf_s fail\n");
            return 0;
        }
        return ret;
    }

    ret = edp_change_boot(buf, CHANGE_MAIN);
    return ret;
}

static ssize_t edp_tcon_uart_write(struct device *dev,
    struct device_attribute *attr, const char *buf, size_t count)
{
    int ret = 0;

    if (!buf || !count) {
        edp_err("tcon uart write buf/len error\n");
        return 0;
    }

    if (!edp_get_panel_on_state()) {
        edp_err("tcon is not on state!\n");
        return 0;
    }

    ret = tcon_uart_write(buf, count);
    if (ret < 0) {
        edp_err("tcon_uart_write fail\n");
        return 0;
    }

    return count;
}

static int edp_check_support(int index)
{
    switch (index) {
        case EDP_SN_CODE:
            return SYSFS_SUPPORT;
        case EDP_PIXELS:
            return SYSFS_SUPPORT;
        case EDP_TCON_VENDOR:
            return SYSFS_SUPPORT;
        case EDP_HARDWARE_ID:
            return SYSFS_SUPPORT;
        case EDP_BKL_PATH:
            return SYSFS_SUPPORT;
        case EDP_TCON_DEBUG:
            return SYSFS_SUPPORT;
        case EDP_TCON_UPGRADE:
            return SYSFS_SUPPORT;
        case EDP_EXT_TCON_UPGRADE:
            return SYSFS_SUPPORT;
        case EDP_TCON_SWITCH_MAIN_BOOT:
            return SYSFS_SUPPORT;
        case EDP_TCON_CHECK_NOW_BOOT:
            return SYSFS_SUPPORT;
        case EDP_TCON_CHECK_TCON_UART:
            return SYSFS_SUPPORT;
        default:
            return SYSFS_NOT_SUPPORT;
    }
}

static struct edp_sysfs_ops g_edp_sysfs_ops = {
    .check_support = edp_check_support,
    .panel_sncode_show = edp_panel_sncode_show,
    .panel_tconic_vendor_show = edp_panel_tconic_vendor_show,
    .panel_hardware_id_show = edp_panel_hardware_id_show,
    .panel_res_fps_show = edp_panel_res_fps_show,
    .panel_brightness_path_show = edp_panel_brightness_path_show,
    .panel_tcon_debug_show = edp_tcon_debug_show,
    .panel_tcon_upgrade_show = edp_panel_tcon_upgrade_show,
    .panel_ext_tcon_upgrade_show = edp_panel_ext_tcon_upgrade_show,
    .panel_current_partition_show = edp_panel_current_partition_show,
    .panel_switch_main_partition_show = edp_panel_switch_main_partition_show,
    .panel_tcon_uart_write = edp_tcon_uart_write,
};

int32_t edp_sysfs_init(struct device *dev)
{
	int ret;

	edp_sysfs_ops_register(&g_edp_sysfs_ops);
	ret = edp_create_sysfs(&dev->kobj);
	if (ret) {
		edp_err("[eDP] create sysfs node fail\n");
		return ret;
	}

#ifdef EDP_FACTORY_MODE
	/* create factory fs */
	ret = edp_sysfs_fact_init(dev);
	if (ret) {
		edp_err("[eDP] create factory sysfs node fail\n");
		return ret;
	}
#endif

	return 0;
}

MODULE_AUTHOR("huawei");
MODULE_DESCRIPTION("huawei driver");
MODULE_LICENSE("GPL");
