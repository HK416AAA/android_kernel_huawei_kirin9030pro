/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for sys msg disposal
 * Author: plat drivers
 */

#include "plat_sys_msg.h"
#include "plat_pm.h"
#include "plat_uart.h"
#include "hw_bfg_ps.h"
#include "bfgx_dev.h"
#include "plat_ipc.h"
#include "plat_debug.h"
#include "bfgx_platform_msg_handle.h"

STATIC void plat_sys_msg_handle(uint8_t uart, const char *data, uint16_t data_len)
{
    struct ps_core_s *ps_core_d = ps_get_core_reference(uart);
    if ((data == NULL) || (data_len == 0)) {
        return;
    }

    ps_exe_sys_func(ps_core_d, (uint8_t *)data);
}

uint32_t plat_sys_msg_init(void)
{
    bfgn_register_uart_data_handle(SYS_MSG, plat_sys_msg_handle);
    return BFGN_SUCC;
}
