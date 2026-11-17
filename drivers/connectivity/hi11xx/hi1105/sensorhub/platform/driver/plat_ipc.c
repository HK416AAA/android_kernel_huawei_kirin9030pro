/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for ipc
 * Author: plat drivers
 */

#include <hal_pm.h>
#include "sw_gt_modechange_api.h"
#include "hal_str_status.h"
#include "oal_net.h"
#include "plat_pm.h"
#include "bfgx_dev.h"
#include "plat_debug.h"
#include "mpxx_dev.h"
#include "plat_debug_cmd.h"
#include "plat_exception_rst.h"
#include "plat_ipc.h"

#define IPC_GNSS_OPEN_WAIT_TIMEOUT    10000   /* 10s */
#define IPC_GNSS_CLOSE_WAIT_TIMEOUT   5000    /* 5s */

#define WAIT_AP_CHANGE_MODE_MAX       100

hw_plat_ipc_ctx_t g_hw_ipc_ctx;

uint8_t g_bfgx_subsys_type[BFGN_OP_SUBSYS_BUTT] = {
    BFGX_BT,
    BFGX_SLE,
};

hw_plat_ipc_ctx_t *hw_plat_get_ipc_ctx(void)
{
    return &g_hw_ipc_ctx;
}

void bfgn_sys_status_notify_handle(const uint8_t *data)
{
    status_notify_cmd_t* cmd = (status_notify_cmd_t*)data;
    PRINT_INFO("bcpu_op_status, op_subsys=%d, status=%d", cmd->subsys, cmd->status);
    if (cmd->status == BFGN_OP_STATUS_OPEN) {
        bfgx_power_on(pm_get_drvdata(BUART), g_bfgx_subsys_type[cmd->subsys]);
    } else if (cmd->status == BFGN_OP_STATUS_CLOSE) {
        bfgx_power_off(pm_get_drvdata(BUART), g_bfgx_subsys_type[cmd->subsys]);
    }
    PRINT_INFO("bcpu_op_status: bt state=%d! sle state=%d", hw_get_bt_state(), hw_get_sle_state());
}

void mcu_cust_cfg_handle(const uint8_t *data, int16_t len)
{
    mcu_cust_cfg_cmd_t* cmd = (mcu_cust_cfg_cmd_t*)data;

    if (len != sizeof(mcu_cust_cfg_cmd_t)) {
        PRINT_ERR("mcu_cust_cfg_handle: data len %d not match size %d", len, sizeof(mcu_cust_cfg_cmd_t));
        return;
    }
    if (cmd->mcu_cust.pm_switch_exist == OAL_TRUE) {
        bfgx_set_pm_switch(pm_get_drvdata(BUART), cmd->mcu_cust.pm_switch_value);
    }

    if (cmd->mcu_cust.pm_sleep_period_exist == OAL_TRUE && cmd->mcu_cust.pm_sleep_period_value != 0) {
        bfgx_set_sleep_period(pm_get_drvdata(BUART), cmd->mcu_cust.pm_sleep_period_value);
    }

    if (cmd->mcu_cust.dfr_switch_exist == OAL_TRUE) {
        plat_exception_set_switch(cmd->mcu_cust.dfr_switch_value);
    }
}

static void cmd_connect_msg_handle(const uint8_t *data, uint16_t len)
{
    plat_ipc_hdr_t* ipc_hdr = (plat_ipc_hdr_t*)data;

    if (ipc_hdr == NULL) {
        PRINT_ERR("cmd_connect_msg_handle: data is null");
        return;
    }
    if (ipc_hdr->msg_len != len) {
        PRINT_ERR("cmd_connect_msg_handle: lenth error");
        return;
    }

    PRINT_INFO("cmd_connect_msg_handle, msg_code=%d, len=%d", ipc_hdr->msg_code, len);
    switch (ipc_hdr->msg_code) {
        case BFGN_OP_CODE_STATUS_NOTIFY:
            bfgn_sys_status_notify_handle(data);
            break;
        case BFGN_OP_CODE_UART_LOOP_START:
            conn_test_buart_loop();
            break;
        case BFGN_OP_CODE_MCU_CUST:
            mcu_cust_cfg_handle(data, len);
            break;
        case BFGN_OP_CODE_MCU_DBG:
            mcu_debug_cmd_proc(data, len);
            break;
        case BFGN_OP_CODE_BT_INIT_STATUS_REQ:
            bfgx_send_device_init_status_to_ap();
            break;
        default:
            break;
    }
}

static void plat_ipc_ap_msg_proc(uint32_t param, const void *data, uint32_t len)
{
    (void)param;

    if ((data == NULL) || (len < sizeof(pkt_header_sensorhub_t))) {
        PRINT_ERR("plat_ipc_ap_msg_proc: param error");
        return;
    }

    const pkt_header_sensorhub_t *pkt = (const pkt_header_sensorhub_t *)data;
    switch (pkt->cmd) {
        case CMD_CONNECT_AP_TO_MCU:
            cmd_connect_msg_handle((const uint8_t *)&pkt[1], pkt->length);
            break;

        default:
            break;
    }
}

int32_t plat_str_mode_exit(void)
{
    int32_t ret = 0;
    uint32_t wait_cnt = 0;

    /* 已处于SW_MODE */
    if (is_ap_str() == false) {
        return OAL_SUCC;
    }

    PRINT_WARN("exiting str mode ......");

    /* STR_MODE时发退出请求 */
    ret = ReqSwGtModeCH(GT_TO_SW_FROM_USER);
    if (ret != 0) {
        PRINT_ERR("failed to request sw mode ret %d", ret);
        // 可能正好已经退出了STR模式，不能重复请求. 返回succ.
        return OAL_SUCC;
    }

    /* 等待AP回到SW_MODE */
    do {
        oal_msleep(50);  // delay 50ms后检查STR状态
        if (wait_cnt++ > WAIT_AP_CHANGE_MODE_MAX) {
            PRINT_ERR("wait exit str mode timeout");
            return -OAL_FAIL;
        }
    } while (is_ap_str() == true);

    return OAL_SUCC;
}

void plat_ipc_send_cmd(uint8_t cmd, const uint8_t *data, uint16_t len)
{
    if (((data == NULL) && (len != 0)) || ((data != NULL) && (len == 0))) {
        PRINT_ERR("plat_ipc_send_cmd %d: param error", cmd);
        return;
    }

    if (plat_str_mode_exit() != OAL_SUCC) {
        PRINT_ERR("plat_ipc_send_cmd %d fail: exit str_mode error", cmd);
        return;
    }

    size_t size = sizeof(pkt_header_sensorhub_t) + len;
    uint8_t *buf = oal_large_malloc(sizeof(pkt_header_sensorhub_t) + len);
    if (buf == NULL) {
        PRINT_ERR("plat_ipc_send_cmd: oal_large_malloc failed, size: %d", size);
        return;
    }

    pkt_header_sensorhub_t *pkt_hdr = (pkt_header_sensorhub_t *)buf;
    pkt_hdr->tag = TAG_CONNECTIVITY_SW;
    pkt_hdr->cmd = cmd;
    pkt_hdr->core = CORE_AP;
    pkt_hdr->resp = 0;
    pkt_hdr->length = len;
    if (len > 0) {
        (void)memcpy_s(buf + sizeof(pkt_header_sensorhub_t), len, data, len);
    }

    struct send_para send_msg;
    send_msg.ver = TCP_AMSM;
    send_msg.send.amsm.buffer = buf;
    send_msg.send.amsm.len = sizeof(pkt_header_sensorhub_t) + len;
    send_msg.send.amsm.crg = 0;

    uint32_t ret = hal_send(&send_msg);
    if (ret != send_msg.send.amsm.len) {
        PRINT_ERR("plat_ipc_send_cmd, cmd:%0x, len: 0x%x, ret: 0x%x",
            cmd, send_msg.send.amsm.len, ret);
    } else {
        if (cmd == CMD_CONNECT_MCU_TO_AP) {
            plat_ipc_hdr_t *hdr = (plat_ipc_hdr_t *)data;
            PRINT_INFO("plat_ipc_send succ! op=%d seq=%d", hdr->msg_code, hdr->seq);
        }
    }

    oal_large_free(buf);
}

int32_t mcu_uart_loop_done_notify_ap_bt(void)
{
    hw_plat_ipc_ctx_t *ctx = hw_plat_get_ipc_ctx();
    uint8_t loop_res = (uint8_t)conn_test_uart_loop_result();

    uart_loop_cmd_t  loop_cmd;
    loop_cmd.ipc_hdr.msg_code = BFGN_OP_CODE_UART_LOOP_DONE;
    loop_cmd.ipc_hdr.msg_len = sizeof(uart_loop_cmd_t);
    loop_cmd.ipc_hdr.seq = ctx->seq++;
    loop_cmd.core = BFGN_CORE_BCPU;
    loop_cmd.result = loop_res;

    plat_ipc_send_cmd(CMD_CONNECT_MCU_TO_AP, (const uint8_t *)&loop_cmd, sizeof(uart_loop_cmd_t));

    PRINT_ERR("mcu_uart_loop_done_notify_ap_bt!");
    return 0;
}

void plat_ipc_init(void)
{
    struct recv_para para;

    /* register communication operation. */
    para.ver = TCP_AMSM;
    para.recv.amsm.tag = TAG_CONNECTIVITY_SW;
    para.recv.amsm.cb = plat_ipc_ap_msg_proc;
    para.recv.amsm.para = 0;
    para.core = BIT(CORE_AP);
    int32_t ret = hal_message_register(&para);
    PRINT_ERR("plat_ipc init ret: %d", ret);

    (void)memset_s(&g_hw_ipc_ctx, sizeof(g_hw_ipc_ctx), 0, sizeof(g_hw_ipc_ctx));
    (void)oal_sema_init(&g_hw_ipc_ctx.ipc_sem, 0);
    (void)oal_sema_init(&g_hw_ipc_ctx.lock_sem, 1);
}


sys_late_initcall(plat_ipc_init);
