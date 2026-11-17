/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */
#ifndef BSP_IPC_H
#define BSP_IPC_H
#include <dpa_reset.h>

typedef enum {
    DPA_IPC_ACPU_INT_SRC_DPA_POWERDOWN = 0x501B,
    DPA_IPC_ACPU_INT_SRC_DPA_DUMP = 0x501C,
    DPA_IPC_ACPU_INT_SRC_DPA_BEFORE_MDM_RESETTING = 0x501D,
    DPA_IPC_ACPU_INT_SRC_DPA_AFTER_MDM_RESETTING = 0x501E,
    DPA_IPC_ACPU_INT_SRC_DPA_RESUME_COMPLE_ACK = 0x501F,
    DPA_IPC_ACPU_INT_SRC_DPA_RESET_HOST_IDLE = 0x5027,
    DPA_IPC_ACPU_INT_SRC_DPA_RESET_START_OK = 0x5028,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_UP = 0x5029,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_DOWN = 0x502A,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_MIN = 0x502B,
    DPA_IPC_ACPU_INT_SRC_DPA_FREQ_LOAD_MAX = 0x502C,

    DPA_IPC_DPA_INT_SRC_ACPU_DUMP = 0x6000,
    DPA_IPC_DPA_INT_SRC_ACPU_BEFORE_MDM_RESETTING = 0x6001,
    DPA_IPC_DPA_INT_SRC_ACPU_AFTER_MDM_RESETTING = 0x6002,
    DPA_IPC_DPA_INT_SRC_ACPU_WAKE_UNLOCK = 0x6005,
    DPA_IPC_DPA_INT_SRC_ACPU_WAKE_LOCK = 0x6006,
    DPA_IPC_DPA_INT_SRC_ACPU_RFILE_NOTIFY = 0x6007,
    DPA_IPC_DPA_INT_SRC_ACPU_PM_DEBUG_REPORT = 0x6008,
    DPA_IPC_DPA_INT_SRC_ACPU_DPA_RESET = 0x6009,

    // m3到dpa host的ipc
    DPA_IPC_ACPU_INT_SRC_M3_LPMCU_READY = 0x8001,
    DPA_IPC_ACPU_INT_SRC_MCU_DPA_DUMP = 0x8002,

    // dpa host到teeos 转发给m3的ipc
    DPA_IPC_VERIFY_START = 0x9000,  // seccall到teeos转发给m3，需要对res_id进行校验
    DPA_IPC_LPM3_INT_SRC_DPA_TEST1 = DPA_IPC_VERIFY_START,
    DPA_IPC_LPMCU_INT_SRC_DPA_DUMP = 0x9001,
    DPA_IPC_VERIFY_END,
} dpa_ipc_res_id_e;


#define DPA_IPC_RECV_EVENT_MAX_NUM 12 // 可支持的事件数量，不能修改

typedef int (*dpa_ipc_cbk)(void *arg);

int bsp_dpa_ipc_send(dpa_ipc_res_id_e res_id);
int bsp_dpa_ipc_connect(dpa_ipc_res_id_e res_id, dpa_ipc_cbk handler, void *parameter);
void bsp_ipc_dpa_reset(dpa_reset_stage_e stage);
#endif
