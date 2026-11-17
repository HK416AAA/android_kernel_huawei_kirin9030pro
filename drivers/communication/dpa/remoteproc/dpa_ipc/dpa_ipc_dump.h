/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef _DPA_IPC_DUMP_H
#define _DPA_IPC_DUMP_H

#include <bsp_dpa_ipc.h>
#include "dpa_ipc.h"
#include "dpa_ipc_dump.h"

#define DPA_IPC_DUMP_SIZE (0x2000)
#define DPA_IPCMSG_EVENT_REC_NUM_MAX 8 // 每个事件的流水打点

struct dpa_ipcmsg_dump_mem_info_t {
    unsigned char *addr;
    unsigned int len;
};

struct dpa_ipcmsg_dump_head {
    unsigned int modid;
    unsigned int version;
    unsigned int len;
    unsigned int magic;
};

struct dpa_ipcmsg_dpa_reset_info_t {
    u32 last_before_reset;
    u32 last_after_reset;
};

struct dpa_ipcmsg_event_rec_t {
    u32 ts;
    int ret;
};

struct dpa_ipcmsg_event_info_t {
    u32 res_id;
    u32 cnt;
    struct dpa_ipcmsg_event_rec_t rec[DPA_IPCMSG_EVENT_REC_NUM_MAX];
};

struct dpa_ipcmsg_regs_dump_t {
    u32 mbx;
    u32 mbx_src;
    u32 mbx_dst;
    u32 mbx_mode;
    u32 mbx_imask;
    u32 mbx_data[DPA_IPC_RECV_EVENT_MAX_NUM];
};

void dpa_ipc_before_resetting_dump(void);
void dpa_ipc_after_resetting_dump(void);
void dpa_ipc_event_send_dump(int reg_id, dpa_ipc_res_id_e res_id, int ret);
void dpa_ipc_event_recv_dump(int reg_id, dpa_ipc_res_id_e res_id, int ret, int offset);
int dpa_ipc_dump_init(void);
#endif