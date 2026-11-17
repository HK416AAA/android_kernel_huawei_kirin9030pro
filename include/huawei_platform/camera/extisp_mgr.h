/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.

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
#ifndef EXTISP_MGR_H
#define EXTISP_MGR_H

#define EXTISP_NO_NEED_MGR_CTRL 1

typedef enum extisp_type {
    EXTISP_TYPE_USB,
    EXTISP_TYPE_MIPI,
    EXTISP_TYPE_MAX
} extisp_type_t;

extern int register_extisp_dev(struct platform_device *pdev, extisp_type_t isp_type,
                                    int (* cb_probe)(struct platform_device *),
                                    int (* cb_remove)(struct platform_device *));
extern int unregister_extisp_dev(struct platform_device *pdev, extisp_type_t isp_type);
#endif