/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: usb phy chip basic interface defination
 * Author: Hisilicon
 * Create: 2025-2-20
 *
 * This software is distributed under the terms of the GNU General
 * Public License ("GPL") as published by the Free Software Foundation,
 * either version 2 of that License or (at your option) any later version.
 */
#ifndef __HIV500_GPIO_DUMP_H__
#define __HIV500_GPIO_DUMP_H__

#ifdef CONFIG_GPIO_SUPPORT_IOMCU
void gpio_mask_info(unsigned);
void gpio_clk_info(void);
#endif

#endif /* __HIV500_GPIO_DUMP_H__ */
