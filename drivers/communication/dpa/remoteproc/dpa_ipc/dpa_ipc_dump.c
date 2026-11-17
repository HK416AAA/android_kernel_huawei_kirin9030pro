/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */
#include <linux/io.h>
#include "securec.h"
#include "bsp_dump.h"
#include "dpa_ipc_dump.h"
#include "bsp_slice.h"
#include "dpa_ipc.h"

#define DPA_IPCMSG_DUMP_VERSION 0x1

#define DPA_IPCMSG_DUMP_RESET (0x0001)
#define DPA_IPCMSG_DUMP_RESET_VER (0x0001)
#define DPA_IPCMSG_DUMP_EVENT_SEND (0x0002)
#define DPA_IPCMSG_DUMP_EVENT_SEND_VER (0x0001)
#define DPA_IPCMSG_DUMP_EVENT_RECV (0x0003)
#define DPA_IPCMSG_DUMP_EVENT_RECV_VER (0x0001)
#define DPA_IPCMSG_DUMP_REGS (0x0004)
#define DPA_IPCMSG_DUMP_REGS_VER (0x0001)

#define DPA_IPCMSG_DUMP_MAGIC_NUM (0xFFFFABCD)
#define DPA_IPCMSG_DUMP_MBX_NUM 3

struct dpa_ipcmsg_dump_mem_info_t g_dpa_ipc_dump_mem_info;

struct dpa_ipcmsg_dpa_reset_info_t *g_dpa_ipc_reset_info = NULL;
struct dpa_ipcmsg_event_info_t *g_dpa_ipcmsg_event_send_info = NULL;
struct dpa_ipcmsg_event_info_t *g_dpa_ipcmsg_event_recv_info = NULL;
struct dpa_ipcmsg_regs_dump_t *g_dpa_ipcmsg_regs = NULL;

void dpa_ipc_before_resetting_dump(void)
{
    if (g_dpa_ipc_reset_info == NULL) {
        return;
    }
    g_dpa_ipc_reset_info->last_before_reset = bsp_get_slice_value();
}

void dpa_ipc_after_resetting_dump(void)
{
    if (g_dpa_ipc_reset_info == NULL) {
        return;
    }
    g_dpa_ipc_reset_info->last_after_reset = bsp_get_slice_value();
}

void dpa_ipc_event_send_dump(int reg_id, dpa_ipc_res_id_e res_id, int ret)
{
    struct dpa_ipcmsg_event_info_t *prec = NULL;
    u32 idx;
    if (g_dpa_ipcmsg_event_send_info == NULL || reg_id >= DPA_IPC_RECV_EVENT_MAX_NUM) {
        return;
    }
    prec = g_dpa_ipcmsg_event_send_info + reg_id;
    prec->res_id = res_id;
    idx = prec->cnt % DPA_IPCMSG_EVENT_REC_NUM_MAX;
    prec->cnt++;
    prec->rec[idx].ts = bsp_get_slice_value();
    prec->rec[idx].ret = ret;
}

void dpa_ipc_event_recv_dump(int reg_id, dpa_ipc_res_id_e res_id, int ret, int offset)
{
    struct dpa_ipcmsg_event_info_t *prec = NULL;
    u32 idx;
    if (g_dpa_ipcmsg_event_recv_info == NULL || reg_id >= DPA_IPC_RECV_EVENT_MAX_NUM) {
        return;
    }
    prec = g_dpa_ipcmsg_event_recv_info + reg_id + offset * DPA_IPC_RECV_EVENT_MAX_NUM;
    prec->res_id = res_id + offset * DPA_IPC_RECV_EVENT_MAX_NUM;
    idx = prec->cnt % DPA_IPCMSG_EVENT_REC_NUM_MAX;
    prec->cnt++;
    prec->rec[idx].ts = bsp_get_slice_value();
    prec->rec[idx].ret = ret;
}

int dpa_ipc_dump_reset_init(unsigned char *buf, unsigned int len)
{
    struct dpa_ipcmsg_dump_head *dump_head = (struct dpa_ipcmsg_dump_head *)buf;
    unsigned int dump_len = sizeof(struct dpa_ipcmsg_dump_head) + sizeof(struct dpa_ipcmsg_dpa_reset_info_t);
    if (buf == NULL || len < dump_len) {
        g_dpa_ipc_reset_info = NULL;
        return DPA_IPC_ERR;
    }
    dump_head->modid = DPA_IPCMSG_DUMP_RESET;
    dump_head->version = DPA_IPCMSG_DUMP_RESET_VER;
    dump_head->len = sizeof(struct dpa_ipcmsg_dpa_reset_info_t);
    dump_head->magic = DPA_IPCMSG_DUMP_MAGIC_NUM;
    g_dpa_ipc_reset_info = (struct dpa_ipcmsg_dpa_reset_info_t *)(dump_head + 1);
    return dump_len;
}

int dpa_ipc_dump_event_send_init(unsigned char *buf, unsigned int len)
{
    struct dpa_ipcmsg_dump_head *dump_head = (struct dpa_ipcmsg_dump_head *)buf;
    unsigned int dump_len =
        sizeof(struct dpa_ipcmsg_dump_head) + sizeof(struct dpa_ipcmsg_event_info_t) * DPA_IPC_RECV_EVENT_MAX_NUM;
    if (buf == NULL || len < dump_len) {
        g_dpa_ipcmsg_event_send_info = NULL;
        return DPA_IPC_ERR;
    }
    dump_head->modid = DPA_IPCMSG_DUMP_EVENT_SEND;
    dump_head->version = DPA_IPCMSG_DUMP_EVENT_SEND_VER;
    dump_head->len = sizeof(struct dpa_ipcmsg_event_info_t) * DPA_IPC_RECV_EVENT_MAX_NUM;
    ;
    dump_head->magic = DPA_IPCMSG_DUMP_MAGIC_NUM;
    g_dpa_ipcmsg_event_send_info = (struct dpa_ipcmsg_event_info_t *)(dump_head + 1);
    return dump_len;
}

int dpa_ipc_dump_event_recv_init(unsigned char *buf, unsigned int len)
{
    struct dpa_ipcmsg_dump_head *dump_head = (struct dpa_ipcmsg_dump_head *)buf;
    unsigned int dump_len =
        sizeof(struct dpa_ipcmsg_dump_head) +
        sizeof(struct dpa_ipcmsg_event_info_t) * DPA_IPC_RECV_EVENT_MAX_NUM * DPA_IPC_RECV_MAILBOX_NUM;
    if (buf == NULL || len < dump_len) {
        g_dpa_ipcmsg_event_recv_info = NULL;
        return DPA_IPC_ERR;
    }
    dump_head->modid = DPA_IPCMSG_DUMP_EVENT_RECV;
    dump_head->version = DPA_IPCMSG_DUMP_EVENT_RECV_VER;
    dump_head->len = sizeof(struct dpa_ipcmsg_event_info_t) * DPA_IPC_RECV_EVENT_MAX_NUM * DPA_IPC_RECV_MAILBOX_NUM;
    dump_head->magic = DPA_IPCMSG_DUMP_MAGIC_NUM;
    g_dpa_ipcmsg_event_recv_info = (struct dpa_ipcmsg_event_info_t *)(dump_head + 1);
    return dump_len;
}

int dpa_ipc_dump_regs_init(unsigned char *buf, unsigned int len)
{
    struct dpa_ipcmsg_dump_head *dump_head = (struct dpa_ipcmsg_dump_head *)buf;
    unsigned int dump_len =
        sizeof(struct dpa_ipcmsg_dump_head) + sizeof(struct dpa_ipcmsg_regs_dump_t) * DPA_IPCMSG_DUMP_MBX_NUM;
    if (buf == NULL || len < dump_len) {
        g_dpa_ipcmsg_regs = NULL;
        return DPA_IPC_ERR;
    }
    dump_head->modid = DPA_IPCMSG_DUMP_REGS;
    dump_head->version = DPA_IPCMSG_DUMP_REGS_VER;
    dump_head->len = sizeof(struct dpa_ipcmsg_regs_dump_t) * DPA_IPCMSG_DUMP_MBX_NUM;
    dump_head->magic = DPA_IPCMSG_DUMP_MAGIC_NUM;
    g_dpa_ipcmsg_regs = (struct dpa_ipcmsg_regs_dump_t *)(dump_head + 1);
    return dump_len;
}

void dpa_ipc_dump_mem_init(unsigned char *pbuf, unsigned int buf_len)
{
    int ret;
    u32 len;
    unsigned char *buf = NULL;
    u32 total_len;
    struct dpa_ipcmsg_dump_head *phead = NULL;
    if (buf_len <= sizeof(struct dpa_ipcmsg_dump_head)) {
        dpa_ipc_err("dpa_ipc_dump_mem_init failed!\n");
        return;
    }
    phead = (struct dpa_ipcmsg_dump_head *)pbuf;
    phead->magic = DPA_IPCMSG_DUMP_MAGIC_NUM;
    phead->version = DPA_IPCMSG_DUMP_VERSION;
    buf = (unsigned char *)(phead + 1);
    total_len = buf_len - sizeof(struct dpa_ipcmsg_dump_head);
    len = 0;
    ret = dpa_ipc_dump_reset_init(buf, total_len - len);
    if (ret <= 0) {
        dpa_ipc_err("dpa_ipc_dump_reset_init failed!\n");
        ret = 0;
    }
    buf = buf + ret;
    len += ret;
    ret = dpa_ipc_dump_event_send_init(buf, total_len - len);
    if (ret <= 0) {
        dpa_ipc_err("dpa_ipc_dump_event_send_init failed!\n");
        ret = 0;
    }
    buf = buf + ret;
    len += ret;
    ret = dpa_ipc_dump_event_recv_init(buf, total_len - len);
    if (ret <= 0) {
        dpa_ipc_err("dpa_ipc_dump_event_recv_init failed!\n");
        ret = 0;
    }
    buf = buf + ret;
    len += ret;
    ret = dpa_ipc_dump_regs_init(buf, total_len - len);
    if (ret <= 0) {
        dpa_ipc_err("dpa_ipc_dump_regs_init failed!\n");
        ret = 0;
    }
    len += ret;
    phead->len = len;
}

void dpa_ipcmsg_regs_dump(void *base, u32 mbx_id, struct dpa_ipcmsg_regs_dump_t *preg)
{
    u32 reg_id;
    if (base == NULL || preg == NULL) {
        return;
    }
    preg->mbx = mbx_id;
    preg->mbx_src = readl((void *)(uintptr_t)((u8 *)base + mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_SRC_REG));
    preg->mbx_dst = readl((void *)(uintptr_t)((u8 *)base + mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_DST_REG));
    preg->mbx_mode = readl((void *)(uintptr_t)((u8 *)base + mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_MODE_REG));
    preg->mbx_imask = readl((void *)(uintptr_t)((u8 *)base + mbx_id * DPA_IPCMSG_OFFSET + DPA_IPCMSG_IMASK_REG));
    for (reg_id = 0; reg_id < DPA_IPC_RECV_EVENT_MAX_NUM; reg_id++) {
        preg->mbx_data[reg_id] =
            readl((void *)(uintptr_t)((u8 *)base + DPA_IPC_MBX_DATA_ADDR(mbx_id, reg_id, DPA_IPCMSG_OFFSET)));
    }
}

void dpa_ipcmsg_dump(void)
{
    struct dpa_ipcmsg_device_t *pdev = dpa_ipcmsg_dev_get();
    struct dpa_ipcmsg_regs_dump_t *pregs = g_dpa_ipcmsg_regs;
    if (g_dpa_ipcmsg_regs == NULL || pdev == NULL) {
        return;
    }

    // 保存寄存器信息
    dpa_ipcmsg_regs_dump(pdev->base_va, pdev->send_mbx_id, pregs);
    // host接收来自dpafw的邮箱 dump。
    dpa_ipcmsg_regs_dump(pdev->base_va, pdev->recv_mbx_id[0], pregs + 1);
    // host接收来自m3的邮箱 dump
    dpa_ipcmsg_regs_dump(pdev->base_va, pdev->recv_mbx_id[1], pregs + 2);
}

int dpa_ipc_dump_init(void)
{
    int ret;
    g_dpa_ipc_dump_mem_info.len = DPA_IPC_DUMP_SIZE;
    g_dpa_ipc_dump_mem_info.addr =
        bsp_dpa_dump_register_field(OM_DPAHOST_FIELD_DPA_IPCMSG, "DPA_IPCMSG", DPA_IPC_DUMP_SIZE, 0);
    if (g_dpa_ipc_dump_mem_info.addr == NULL || g_dpa_ipc_dump_mem_info.len <= sizeof(struct dpa_ipcmsg_dump_head)) {
        dpa_ipc_err("dpa_ipc_dump_init space register failed!\n");
        return DPA_IPC_ERR_NOMEM;
    }
    (void)memset_s(g_dpa_ipc_dump_mem_info.addr, g_dpa_ipc_dump_mem_info.len, 0, g_dpa_ipc_dump_mem_info.len);

    dpa_ipc_dump_mem_init(g_dpa_ipc_dump_mem_info.addr, g_dpa_ipc_dump_mem_info.len);
    ret = bsp_dpa_dump_register_hook("DPA_IPCMSG", dpa_ipcmsg_dump);
    if (ret == -1) {
        dpa_ipc_err("dpa_fipc_dump_init register hook failed, ret=%d\n", ret);
        return DPA_IPC_ERR;
    }
    return DPA_IPC_OK;
}