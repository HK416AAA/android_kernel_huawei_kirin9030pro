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
#ifndef __EDP_FACTORY_H__
#define __EDP_FACTORY_H__
 
#define EDP_FAC_SYSFS_ATTRS_NUM 20
 
struct edp_fact_desc {
	/* test config */
	char lcd_cmd_now[EDP_CMD_NAME_MAX];
};
 
struct edp_fact_ops {
	ssize_t (*gram_check_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*gram_check_store)(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count);
	ssize_t (*err_rate_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*ddrt_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*crack_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*close_tcon_te_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*switch_tcon_fps_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*switch_tcon_fps_store)(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count);
	ssize_t (*screen_sn_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*test_config_show)(struct device *dev,
		struct device_attribute *attr, char *buf);
	ssize_t (*test_config_store)(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count);
    ssize_t (*panel_update_extra_tconic_fw_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_ext_update_status_show)(struct device *dev, struct device_attribute *attr, char *buf);
    ssize_t (*panel_update_extra_tconic_store)(struct device *dev, struct device_attribute *attr,
                                               const char *buf, size_t count);
};
 
/* variable declare */
struct edp_fact_desc *edp_get_fact_info(void);
#define FACT_INFO edp_get_fact_info()
 
/* function declare */
int edp_fact_ops_register(struct edp_fact_ops *ops);
int edp_fact_ops_unregister(struct edp_fact_ops *ops);
struct edp_fact_ops *edp_get_fact_ops(void);
int edp_create_fact_sysfs(struct kobject *obj);
int edp_get_test_config(char *buf);
int edp_set_test_config(const char *buf);
 
#endif /* EDP_FACTORY_H */