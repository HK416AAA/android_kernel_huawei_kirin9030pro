/*
 * touchpad.h
 *
 * touchpad log define
 *
 * Copyright (c) 2023-2023 Huawei Technologies Co., Ltd.
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
 
#define tp_log_debug(fmt, args...) do { printk(KERN_DEBUG   "[touchpad]" fmt, ## args); } while (0)
#define tp_log_info(fmt, args...)  do { printk(KERN_INFO    "[touchpad]" fmt, ## args); } while (0)
#define tp_log_warn(fmt, args...)  do { printk(KERN_WARNING "[touchpad]" fmt, ## args); } while (0)
#define tp_log_err(fmt, args...)   do { printk(KERN_ERR     "[touchpad]" fmt, ## args); } while (0)
