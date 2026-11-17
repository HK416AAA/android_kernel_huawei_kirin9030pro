/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for plat exception
 * Author: plat drivers
 */

#include "plat_ipc.h"
#include "securec.h"
#include "hw_bfg_ps.h"
#include "plat_pm.h"
#include "plat_debug.h"
#include "plat_exception_rst.h"

#define EXCEP_DEBUG_PARA_MAX  4   // 命令最多4个参数

/* 全局变量定义 */
OAL_STATIC struct st_exception_info g_hi110x_exception_info;

/*
* 命令格式：excep_debug,xxx
* xxx: debug cmd index
*/
uint32_t excep_debug_cmd(const uint8_t *data, uint16_t data_len)
{
    char *ptr = (char *)data;
    char *token = NULL;
    char *next_token = NULL;
    uint32_t debug_id = 0;
    uint32_t tmp[EXCEP_DEBUG_PARA_MAX] = {0};
    uint8_t idx = 0;

    token = strtok_s((char*)ptr, ",", &next_token); // 第1个分段是key
    token = strtok_s(NULL, ",", &next_token);       // 第2个分段开始是参数
    while (token != NULL) {
        tmp[idx++] = strtoul(token, NULL, 10); // 10: 十六进制
        token = strtok_s(NULL, ",", &next_token);
        if (idx >= EXCEP_DEBUG_PARA_MAX) {
            break;
        }
    }
    PRINT_INFO("excep_debug %d %d", tmp[0], tmp[1]);

    debug_id = tmp[0];   // 0: 第一个参数固定是id

    if (debug_id >= EXCEP_DEBUG_ID_BUTT) {
        PRINT_ERR("excep_debug para error");
        return OAL_FAIL;
    }

    switch (debug_id) {
        case EXCEP_DEBUG_WAKEUP_FAIL:
            plat_exception_handler(SUBSYS_BFGX, BFGX_WAKEUP_FAIL, NULL, 0);
            break;
        default:
            break;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名  : get_exception_info_reference
 * 功能描述  : 获得保存异常信息的全局变量
 */
struct st_exception_info *get_exception_info_reference(void)
{
    return &g_hi110x_exception_info;
}

int32_t is_plat_exception(void)
{
    struct st_exception_info *pst_exception_data = get_exception_info_reference();
    return oal_atomic_read(&pst_exception_data->is_reseting_device);
}

/*
 * 函 数 名  : plat_exception_handler
 * 功能描述  : 平台mcu异常处理总入口函数，填充异常信息，并触发起新线程处理异常
 * 输入参数  : subsys_type:调用异常处理的子系统，WIFI或者BFGX
 *             exception_type:异常的类型
 * 返 回 值  : 异常处理成功返回0，否则返回1
 */
int32_t plat_exception_handler(uint32_t subsys_type, uint32_t exception_type, uint8_t *buf, uint16_t len)
{
    uint8_t idx;
    uint16_t dfx_len = len;
    dfr_notify_cmd_t  dfr_cmd;

    if (is_plat_exception() == PLAT_EXCEPTION_RESET_BUSY) {
        PRINT_ERR("[HISI_DFR] plat is processing exception! subsys_type=%d exception=%d", subsys_type, exception_type);
        return EXCEPTION_FAIL;
    }
    PRINT_ERR("[HISI_DFR]exception! subsys_type=%d exception=%d", subsys_type, exception_type);

    if (dfx_len > MCU_DFX_INFO_LEN) {
        dfx_len = MCU_DFX_INFO_LEN;
        PRINT_ERR("[HISI_DFR] The current length[%d] exceeds the maximum supported length.", len);
    }

    // 关闭所有子系统
    for (idx = 0; idx < BFGN_OP_SUBSYS_BUTT; idx++) {
        bfgx_power_off(pm_get_drvdata(BUART), g_bfgx_subsys_type[idx]);
    }

    dfr_cmd.ipc_hdr.msg_code = BFGN_OP_CODE_DRF_NOTIFY;
    dfr_cmd.ipc_hdr.msg_len = sizeof(dfr_notify_cmd_t);
    dfr_cmd.ipc_hdr.seq = 0;
    dfr_cmd.subsys = subsys_type;
    dfr_cmd.excep_type = exception_type;
    dfr_cmd.dfx_len = dfx_len;

    if (dfx_len != 0) {
        if (memcpy_s(dfr_cmd.dfx_info, MCU_DFX_INFO_LEN, buf, dfx_len) != 0) {
            PRINT_ERR("[HISI_DFR] buf is not enough, memcopy fail");
        }
    }
    plat_ipc_send_cmd(CMD_CONNECT_MCU_TO_AP, (const uint8_t *)&dfr_cmd, sizeof(dfr_notify_cmd_t));
    return EXCEPTION_SUCCESS;
}

/*
 * 函 数 名  : plat_exception_reset_clear
 * 功能描述  : 平台异常处理模块上电复位
 */
int32_t plat_exception_reset_clear(void)
{
    struct st_exception_info *p_exception_data = &g_hi110x_exception_info;

    p_exception_data->subsys_type = SUBSYS_BOTTOM;
    p_exception_data->excetion_type = EXCEPTION_TYPE_BOTTOM;
    oal_atomic_set(&p_exception_data->is_reseting_device, PLAT_EXCEPTION_RESET_IDLE);

    PRINT_INFO("plat exception reset clear success");
    return EXCEPTION_SUCCESS;
}

/*
 * 函 数 名  : plat_exception_reset_clear
 * 功能描述  : 平台异常处理模块上电复位
 */
void plat_exception_set_switch(uint32_t value)
{
    struct st_exception_info *p_exception_data = &g_hi110x_exception_info;
    p_exception_data->exception_reset_enable = value;
    PRINT_INFO("plat exception reset switch is %d", p_exception_data->exception_reset_enable);
}

/*
 * 函 数 名  : plat_exception_reset_init
 * 功能描述  : 平台异常处理模块初始化函数
 */
int32_t plat_exception_reset_init(void)
{
    struct st_exception_info *p_exception_data = &g_hi110x_exception_info;

    p_exception_data->subsys_type = SUBSYS_BOTTOM;
    p_exception_data->excetion_type = EXCEPTION_TYPE_BOTTOM;
    p_exception_data->total_excep_cnt = 0;
    p_exception_data->exception_reset_enable = PLAT_EXCEPTION_ENABLE;
    oal_atomic_set(&p_exception_data->is_reseting_device, PLAT_EXCEPTION_RESET_IDLE);

    PRINT_INFO("plat exception reset init success");
    return EXCEPTION_SUCCESS;
}

/*
 * 函 数 名  : plat_exception_reset_exit
 * 功能描述  : 平台异常处理模块退出清理函数
 */
int32_t plat_exception_reset_exit(void)
{
    return EXCEPTION_SUCCESS;
}
