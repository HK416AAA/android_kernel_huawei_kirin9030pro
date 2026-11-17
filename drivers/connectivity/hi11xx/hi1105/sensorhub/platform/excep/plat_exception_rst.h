/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: plat exception header file
 * Author: plat drivers
 */

#ifndef __PLAT_EXCEPTION_RST_H__
#define __PLAT_EXCEPTION_RST_H__

#include <stdint.h>
#include "plat_type.h"
#include "oal_atomic.h"
#include "oal_types.h"

/* plat cfg cmd */
#define PLAT_EXCEPTION_ENABLE  1
#define PLAT_EXCEPTION_DISABLE 0

#define PLAT_EXCEPTION_RESET_IDLE  0 /* plat 没有在处理异常 */
#define PLAT_EXCEPTION_RESET_BUSY  1 /* plat 正在处理异常 */

#define EXCEPTION_SUCCESS 0
#define EXCEPTION_FAIL    1

enum subsystem_enum {
    SUBSYS_BFGX = 1,

    SUBSYS_BOTTOM
};

enum exception_type_enum {
    /* bfgx */
    BFGX_BEATHEART_TIMEOUT = 0, /* 心跳超时 */
    BFGX_WAKEUP_FAIL = 1,       /* 唤醒失败 */
    BFGX_SLEEP_FAIL = 2,        /* 睡眠失败 */

    EXCEPTION_TYPE_BOTTOM
};

typedef enum {
    EXCEP_DEBUG_WAKEUP_FAIL = 0,

    EXCEP_DEBUG_ID_BUTT,
} excep_debug_id_t;

struct st_exception_info {
    uint8_t exception_reset_enable;
    uint8_t subsys_type;
    uint8_t excetion_type;
    uint32_t total_excep_cnt;
    oal_atomic_t is_reseting_device;
};

/* EXTERN FUNCTION */
int32_t plat_exception_reset_init(void);
int32_t plat_exception_reset_exit(void);
int32_t plat_exception_reset_clear(void);
void plat_exception_set_switch(uint32_t value);
int32_t plat_exception_handler(uint32_t subsys_type, uint32_t exception_type, uint8_t *buf, uint16_t len);
uint32_t excep_debug_cmd(const uint8_t *data, uint16_t data_len);

#endif
