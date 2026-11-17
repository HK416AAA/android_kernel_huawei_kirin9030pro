/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */
#ifndef _DPA_MSG_CMSG_H
#define _DPA_MSG_CMSG_H

#include "dpa_msg_plat.h"
#include "dpa_msg_dts.h"
#include "bsp_dpa_fipc.h"

#define CMSG_SEND_TRY_WAIT_TIMES 200
#define DPA_MSG_CORE_CNTMAX 8
#define MID_ATTR_INIT_MAGIC 0xAABBCCDD

#define DPA_MSG_FICC_CHN 0x1
#define DPA_MSG_IPCMSG_CHN 0x2

/* 如果使用的通道数量超出最大值，该宏要扩大 */
#define CUSTOM_CHANNEL_MAX 0x1

#define DPA_MSG_PHYCHN_SEND(mode) ((mode)&0x1)
#define DPA_MSG_PHYCHN_RECV(mode) ((mode)&0x2)

typedef struct {
    unsigned cnt;
    struct {
        void *buf;
        unsigned len;
    } datablk[0x3];
} dpa_msg_blkx3_desc_t;

struct dpa_channel_ctrl_t;
struct dpa_cmsg_ctrl_t;

struct dpa_channel_ctrl_t {
    unsigned int cid;
    unsigned int phychnid;
    unsigned int status;
    unsigned int smsg_sz;
    void *smsg_buf;
    void *cmsg_chn;
    struct dpa_msg_task_t *task;
};

struct dpa_cmsg_ctrl_t {
    struct dpa_channel_ctrl_t *default_ctrl[DPA_MSG_CORE_CNTMAX];
};

struct dpa_fipc_cmsg_chn_t {
    unsigned int buf_sz;
    dpa_fipc_chn_t handle;
};
void *dpa_msg_dma_buf_alloc(size_t size, dma_addr_t *dma_handle);
int dpa_msg_crosscore_init(void);
int dpa_msg_lite_callback(const struct dpa_msg_addr *src_addr, const struct dpa_msg_addr *dst_addr, void *buf, unsigned int len);
int dpa_send_lite_msg(const struct dpa_msg_addr *src_addr, const struct dpa_msg_addr *dst_addr, void *buf, unsigned int len);
#endif
