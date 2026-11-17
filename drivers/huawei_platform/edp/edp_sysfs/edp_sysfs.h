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
#ifndef __EDP_SYSFS_H__
#define __EDP_SYSFS_H__

#define EDP_SYSFS_MAX 20
#define CHANGE_MAIN 0XA
#define CHANGE_EXT 0XB

enum edp_sysfs_index {
    EDP_SN_CODE,
    EDP_TCON_VENDOR,
    EDP_HARDWARE_ID,
    EDP_PIXELS,
    EDP_BKL_PATH,
    EDP_TCON_DEBUG,
    EDP_TCON_UPGRADE,
    EDP_EXT_TCON_UPGRADE,
    EDP_TCON_SWITCH_MAIN_BOOT,
    EDP_TCON_CHECK_NOW_BOOT,
    EDP_TCON_CHECK_TCON_UART,
};

/* sysfs support enum */
enum edp_sysfs_support {
	SYSFS_NOT_SUPPORT,
	SYSFS_SUPPORT,
};

struct edp_sysfs_ops {
    int (*check_support)(int index);
    ssize_t (*panel_sncode_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_tconic_vendor_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_hardware_id_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_res_fps_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_brightness_path_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_tcon_debug_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_tcon_upgrade_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_ext_tcon_upgrade_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_switch_main_partition_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_current_partition_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_tcon_uart_write)(struct device *dev, struct device_attribute *attr, const char *buf, size_t count);
};

int edp_sysfs_ops_register(struct edp_sysfs_ops *ops);
int edp_sysfs_ops_unregister(struct edp_sysfs_ops *ops);
struct edp_sysfs_ops *edp_get_sysfs_ops(void);
int edp_create_sysfs(struct kobject *obj);
void edp_remove_sysfs(struct kobject *obj);
#endif /* EDP_SYSFS_H */