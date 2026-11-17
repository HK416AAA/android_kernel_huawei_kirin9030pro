/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2024. All rights reserved.
 * Description: for ffts drv log
 */
#ifndef _FFTS_LOG_H_
#define _FFTS_LOG_H_

#include <linux/sched.h>

#define drv_printk(level, module, fmt, ...) \
	printk(level " [%s] [%d] [%s %d] " fmt, module, \
		current->tgid, __func__, __LINE__, ## __VA_ARGS__)

#define MODULE_DEVDRV   "FFTS_DRV"
#define ffts_drv_err(fmt, ...)  \
	drv_printk(KERN_ERR, MODULE_DEVDRV"] [E",  fmt, ## __VA_ARGS__)
#define ffts_drv_warn(fmt, ...) \
	drv_printk(KERN_WARNING, MODULE_DEVDRV"] [W",  fmt, ## __VA_ARGS__)
#define ffts_drv_info(fmt, ...)
#define ffts_drv_debug(fmt, ...)

#define cond_return_error(COND, ERRCODE, ...) \
			cond_return_((COND), ERRCODE, ##__VA_ARGS__)

#define cond_return_void(COND, ...) \
			cond_return_((COND), , ##__VA_ARGS__)

// Do NOT use this Marco directly
#define cond_return_(COND, ERRCODE, ...) \
			if ((COND)) { \
				ffts_drv_err(__VA_ARGS__); \
				return ERRCODE; \
			}

#define cond_goto_error(COND, LABEL, ERROR, ERRCODE, ...) \
	cond_goto_with_errcode_((COND), LABEL, ERROR, ERRCODE, ##__VA_ARGS__)

#define cond_goto_debug(COND, LABEL, ERROR, ERRCODE, ...) \
	cond_goto_with_errcode_debug_((COND), LABEL, ERROR, ERRCODE, ##__VA_ARGS__)

#define cond_goto_nolog(COND, LABEL, ERROR, ERRCODE) \
			cond_goto_with_errcode_nolog_((COND), LABEL, ERROR, ERRCODE)

// Do NOT use this Marco directly
#define cond_goto_with_errcode_(COND, LABEL, ERROR, ERRCODE, ...) \
			if (COND) { \
				ffts_drv_err(__VA_ARGS__); \
				ERROR = (ERRCODE); \
				goto LABEL; \
			}

// Do NOT use this Marco directly
#define cond_goto_with_errcode_debug_(COND, LABEL, ERROR, ERRCODE, ...) \
			if (COND) { \
				ffts_drv_debug(__VA_ARGS__); \
				ERROR = (ERRCODE); \
				goto LABEL; \
			}

// Do NOT use this Marco directly
#define cond_goto_with_errcode_nolog_(COND, LABEL, ERROR, ERRCODE) \
			if (COND) { \
				ERROR = (ERRCODE); \
				goto LABEL; \
			}

#endif /* _DRV_LOG_H_ */
