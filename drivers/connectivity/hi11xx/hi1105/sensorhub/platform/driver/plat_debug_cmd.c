/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for ipc
 * Author: plat drivers
 */
#include "oal_net.h"
#include "plat_pm.h"
#include "bfgx_dev.h"
#include "plat_debug.h"
#include "mpxx_dev.h"
#include "plat_ipc.h"
#include "plat_exception_rst.h"
#include "plat_debug_cmd.h"

#ifdef PLATFORM_DEBUG_ENABLE

typedef uint32_t (*cmd_process_func)(const uint8_t *data, uint16_t data_len);

typedef struct {
    char *cmd_key;
    cmd_process_func func;
} cmd_process_table;


static const cmd_process_table g_cmd_tbl[] = {
    { "pm_debug", pm_debug_cmd },
    { "excep_debug", excep_debug_cmd },
};

void mcu_debug_cmd_proc(const uint8_t *data, uint16_t len)
{
    mcu_debug_cmd_t* cmd = (mcu_debug_cmd_t*)data;
    uint32_t cmd_total = sizeof(g_cmd_tbl) / sizeof(cmd_process_table);
    uint32_t i;

    if (len != sizeof(mcu_debug_cmd_t)) {
        PRINT_ERR("mcu_debug_cmd_proc len not match %d", len);
        return;
    }

    for (i = 0; i < cmd_total; i++) {
        if (cmd->cmd_len < strlen(g_cmd_tbl[i].cmd_key) || g_cmd_tbl[i].func == NULL) {
            continue;
        }
        if (memcmp(g_cmd_tbl[i].cmd_key, cmd->cmd_str, strlen(g_cmd_tbl[i].cmd_key)) == 0) {
            g_cmd_tbl[i].func(data, len);
        }
    }
}

#endif