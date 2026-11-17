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
#ifndef __EDP_SYSFS_FACT_H__
#define __EDP_SYSFS_FACT_H__
 
int32_t edp_sysfs_fact_init(struct device *dev);
ssize_t update_tconic_tool(char *buf, bool main_flag);
ssize_t edp_check_now_boot(char *buf);
ssize_t edp_change_boot(char *buf, unsigned char patition);
 
#endif /* EDP_SYSFS_FACT_H */