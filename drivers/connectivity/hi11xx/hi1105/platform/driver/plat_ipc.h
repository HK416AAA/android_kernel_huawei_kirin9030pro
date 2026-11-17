/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:plat_ipc header
 * Author: platform drivers
 */

#ifndef PLAT_IPC_H
#define PLAT_IPC_H

#ifdef _PRE_PLAT_FEATURE_IPC
#include <linux/types.h>
#include "oal_workqueue.h"
#include "oal_schedule.h"

extern oal_completion g_mcu_uart_loop_done;
extern uint8_t g_mcu_uart_loop_result;
extern oal_completion g_mcu_init_done;
extern uint8_t g_mcu_init_result;

enum bfgn_core {
    BFGN_CORE_BCPU = 0,
    BFGN_CORE_GCPU,
    BFGN_CORE_BUTT
};

enum bfgn_op_subsys {
    BFGN_OP_SUBSYS_BT = 0,
    BFGN_OP_SUBSYS_SLE,
    BFGN_OP_SUBSYS_BUTT
};

enum bfgn_op_status {
    BFGN_OP_STATUS_CLOSE = 0,
    BFGN_OP_STATUS_OPEN,
    BFGN_OP_STATUS_BUTT
};

enum bfgn_op_code {
    BFGN_OP_CODE_STATUS_NOTIFY = 0,
    BFGN_OP_CODE_DRF_NOTIFY,
    BFGN_OP_CODE_UART_LOOP_START,
    BFGN_OP_CODE_UART_LOOP_DONE,
    BFGN_OP_CODE_MCU_CUST,
    BFGN_OP_CODE_MCU_DBG,
    BFGN_OP_CODE_PM_STATUS_NOTIFY,
    BFGN_OP_CODE_BT_INIT_STATUS_REQ,
    BFGN_OP_CODE_BT_INIT_STATUS_ACK,

    BFGN_OP_CODE_BUTT
};

enum plat_ipc_cmd {
    CMD_CONNECT_MCU_TO_AP = 1,
    CMD_CONNECT_AP_TO_MCU,
};

#pragma pack(1)
typedef struct {
    uint8_t msg_code;     // ipc msg消息类型
    uint8_t msg_len;      // 包括ipc hdr在内的消息总长度
    uint8_t seq;          // 请求序号，返回时状态时携带
} plat_ipc_hdr_t;

typedef struct {
    plat_ipc_hdr_t hdr;
    uint8_t  data[0];    // 用于发送大数据，动态申请内存
} plat_ipc_msg_t;

typedef struct uart_loop_cmd {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t core;           /* uart对接芯片core */
    uint8_t result;         /* loop done返回结果 */
} uart_loop_cmd_t;

typedef struct status_notify_cmd {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t core;
    uint8_t subsys;             /* 子系统 */
    uint8_t status;             /* 子系统状态 */
} status_notify_cmd_t;

#define MCU_DFX_INFO_LEN  64
typedef struct dfr_notify_cmd {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t subsys;
    uint8_t excep_type;         /* 异常类型 */
    uint8_t dfx_info[MCU_DFX_INFO_LEN];
    uint16_t dfx_len;
} dfr_notify_cmd_t;

typedef struct mcu_pm_status_notify {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t level;
    uint8_t event;
} mcu_pm_status_notify_t;

#define MCU_DBG_CMD_LEN  64
typedef struct mcu_debug_cmd {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t cmd_str[MCU_DBG_CMD_LEN];
    uint8_t cmd_len;
} mcu_debug_cmd_t;

typedef struct mcu_init_status_cmd {
    plat_ipc_hdr_t ipc_hdr;
    uint8_t status;
} mcu_init_status_cmd_t;

#pragma pack()

int32_t plat_ipc_send_cmd(uint8_t cmd, const uint8_t *data, uint16_t len);
int plat_ipc_init(void);
void plat_ipc_exit(void);
#endif
#endif