/*
* Copyright (c) Huawei Technologies Co., Ltd. 2023-2024. All rights reserved.
* Description: interface defination for pcie misc driver
*
* This software is distributed under the terms of the GNU General
* Public License ("GPL") as published by the Free Software Foundation,
* either version 2 of that License or (at your option) any later version.
*/
#ifndef _PCIE_MISC_H_
#define _PCIE_MISC_H_

#define pciedev_debug(fmt, args...) printk(KERN_DEBUG "[pcie_misc]" fmt, ## args)
#define pciedev_info(fmt, args...) printk(KERN_INFO "[pcie_misc]" fmt, ## args)
#define pciedev_warn(fmt, args...) printk(KERN_WARNING "[pcie_misc]" fmt, ## args)
#define pciedev_err(fmt, args...) printk(KERN_ERR "[pcie_misc]" fmt, ## args)

#endif
