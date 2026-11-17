/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: camera debug log
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

#ifndef _CAM_DEBUG_LOG_H_
#define _CAM_DEBUG_LOG_H_

#define LOG_TAG "CAMERA_DEBUG"

#define PRINT_DEBUG 1
#define PRINT_INFO  1
#define PRINT_WARN  1
#define PRINT_ERR   1

#if PRINT_DEBUG
#define debug_dbg(fmt, ...) printk(KERN_INFO "[" LOG_TAG "]" "[D] %s:" fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#else
#define debug_dbg(fmt, ...) ((void)0)
#endif

#if PRINT_INFO
#define debug_info(fmt, ...) printk(KERN_INFO "[" LOG_TAG "]" "[INFO] %s:" fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#else
#define debug_info(fmt, ...) ((void)0)
#endif

#if PRINT_WARN
#define debug_warn(fmt, ...) printk(KERN_WARNING "[" LOG_TAG "]" "[WARN] %s:" fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#else
#define debug_warn(fmt, ...) ((void)0)
#endif

#if PRINT_ERR
#define debug_err(fmt, ...) printk(KERN_ERR "[" LOG_TAG "]" "[ERR] %s:" fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#else
#define debug_err(fmt, ...) ((void)0)
#endif

#endif

