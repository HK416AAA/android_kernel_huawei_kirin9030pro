/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: main.c
 * Author: dpa drivers
 */

#include "bsp_module.h"
#include "osl_types.h"
#include "oal_util.h"
#include "oal_types.h"
#include "board_pm.h"
#include "conn_dmi_msg.h"
#include "conn_dmi_drv.h"

int32_t conn_plat_main(void)
{
    int32_t ret;
    oal_print_mpxx_serial_log(MPXX_LOG_INFO, "conn plat init");
    ret = conn_dmi_drv_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "conn_dmi_drv_init fail ret = %d", ret);
        return ret;
    }
    ret = conn_dmi_msg_init();
    if (ret != OAL_SUCC) {
        oal_print_mpxx_serial_log(MPXX_LOG_ERR, "conn_dmi_msg_init fail ret = %d", ret);
        return ret;
    }
    board_pm_init();
    return OAL_SUCC;
}
module_init("pcie", mod_level_pcie, conn_plat_main);