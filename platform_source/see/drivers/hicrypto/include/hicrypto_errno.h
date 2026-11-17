/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: define error coding
 * Create: 2023/03/07
 */
#ifndef __HICRYPTO_ERRNO_H__
#define __HICRYPTO_ERRNO_H__
#include <linux/errno.h>
#include <securec.h>

/**
 * @brief mudule id
 */
enum mudule_id {
	BSP_MODULE_SYS        = 0x00,
	BSP_MODULE_KM         = 0x02,
	BSP_MODULE_SCE        = 0x03,
	BSP_MODULE_HASH       = 0x04,
	BSP_MODULE_MAC        = 0x05,
	BSP_MODULE_SYMM       = 0x06,
	BSP_MODULE_ENGCTRL    = 0x0E,
	BSP_MODULE_UNKNOWN = 0x7F, /* unknown module */
};

/**
 * @brief error code
 *       Note: increase in order, not allowed to modify existed errcode
 *             0x5A is not allowed to use since it is same as OK
 */
enum errcode {
	ERRCODE_NULL = 0x01,	  /* pointer is null */
	ERRCODE_PARAMS = 0x02,	  /* parameter error */
	ERRCODE_INVALID = 0x03,	  /* data is invalid */
	ERRCODE_NOFOUND = 0x04,	  /* not found */
	ERRCODE_MEMORY = 0x05,	  /* out of memory or error */
	ERRCODE_VERIFY = 0x06,	  /* verify failed */
	ERRCODE_TIMEOUT = 0x07,	  /* timeout error */
	ERRCODE_READ = 0x08,	  /* read failed */
	ERRCODE_WRITE = 0x09,	  /* write failed */
	ERRCODE_REQUEST = 0x0A,	  /* request failed for communication */
	ERRCODE_ALARM = 0x0B,	  /* abnormal alarm */
	ERRCODE_UNSUPPORT = 0x0C, /* not supported */
	ERRCODE_ATTACK = 0x0D,	  /* be attacked */
	ERRCODE_SYS = 0x0E,	  /* system error, irq, cpu, libc etc. */
	ERRCODE_BUSY = 0x0F,	  /* busy status */
	ERRCODE_IRQ_NONE = 0x010,	  /* none irq */
	ERRCODE_IRQ_HANDLED = 0x011,	  /* irq handled */
	ERRCODE_MAX_LIST = 0x12,  /* up to max hd len */
	ERRCODE_HW_BUSY = 0x13,	  /* hardware busy */
	ERRCODE_NOREADY = 0x14,	  /* hardware not ready */
	ERRCODE_UNKNOWN = 0xFF,	  /* unknown(default, max enum value) */
};

/* BSP_RET_OK                : for success */
#ifndef BSP_RET_OK
#define BSP_RET_OK 0x00005A5A /**< success */
#endif			      /* BSP_RET_OK */

/*
 *  error coding
 *  prefix     error prefix is a bigger value and set to 0xA for safety
 *  line       code line, 1 byte, mod 0xFFF, range is 0~0xFFF
 *  module     module id, 1 byte(0~127) refer to ::bsp_module_e
 *             the highest bit 1 is HAL, 0 is DRV
 *  errcode    error code, refer to::errcode_e coding value
 * [note]: errno must include module id and errcode
 */
#ifndef err_makeup
#define err_makeup(prefix, line, module, errcode) \
	(int)((((int)(prefix)&0xF0) << 24) | (((line)&0xFFF) << 16) | (((module)&0xFF) << 8) | ((errcode)&0xFF))
#endif /* err_makeup */

/**< get module id */
#ifndef err_get_module
#define err_get_module(errno) (((int)(errno) >> 8) & 0x3F)
#endif /* err_get_module */

/**< get error code */
#ifndef err_get_errcode
#define err_get_errcode(errno) ((int)(errno)&0xFF)
#endif /* err_get_errcode */

#ifndef err_bsp
#define err_bsp(module, errcode) err_makeup(0x50, __LINE__, module, errcode)
#endif /* __ERR_BSP */

/* error coding of drv  */
#ifndef err_drv
#define err_drv(errcode) err_bsp(BSP_THIS_MODULE, errcode)
#endif /* err_drv */

/* error coding of hal */
#ifndef err_hal
#define err_hal(errcode) (int)((int)err_drv(errcode) | 0x4000U)
#endif /* err_hal */

/* error coding of api */
#ifndef err_api
#define err_api(errcode) (int)((int)err_drv(errcode) | 0x8000U)
#endif /* err_api */

/* convert memory libc error code to bsp error code */
#define libc_mem_cnv_errcode(libc_ret) (((libc_ret) != EOK) ? err_drv(ERRCODE_MEMORY) : BSP_RET_OK)
#endif /* __PAL_ERRNO_H__ */
