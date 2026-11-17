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
#ifndef __EDP_LOG_H__
#define __EDP_LOG_H__
 
#define edp_err(msg, ...)  do { \
 		pr_err("E eDP[%s:%d]"msg, __func__, __LINE__, ## __VA_ARGS__); \
 	} while (0)
 
#define edp_warn(msg, ...) do { \
 		pr_warn("W eDP[%s:%d]"msg, __func__, __LINE__, ## __VA_ARGS__); \
 	} while (0)
 
#define edp_info(msg, ...) do { \
 		pr_info("I eDP[%s:%d]"msg, __func__, __LINE__, ## __VA_ARGS__); \
 	} while (0)
 
#define edp_debug(msg, ...) do { \
		pr_debug("D eDP[%s:%d]"msg, __func__, __LINE__, ## __VA_ARGS__); \
 	} while (0)
 
#endif /* EDP_LOG_H */