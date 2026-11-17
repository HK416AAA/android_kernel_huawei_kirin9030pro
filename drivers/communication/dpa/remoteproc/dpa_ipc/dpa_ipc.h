/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 */
#ifndef _DPA_IPC_H
#define _DPA_IPC_H
#include <linux/types.h>
#include <bsp_print.h>

#define THIS_MODU mod_dpa_ipc
#define dpa_ipc_crit(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_ipc_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_ipc_warn(fmt, ...)
#define dpa_ipc_print(fmt, ...)
#define dpa_ipc_always(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_ipc_trace(fmt, ...)
#define dpa_ipc_debug(fmt, ...)

#define DPA_IPC_OK (0)
#define DPA_IPC_ERR (-1)
#define DPA_IPC_ERR_RESET (-1000)
#define DPA_IPC_ERR_NOMEM (-12)
#define DPA_IPC_ERR_ENXIO (-6)
#define DPA_IPC_ERR_NO_CBK (-1111)

#define DPA_IPC_RECV_BEFORE (1000)

#define DPA_IPCMSG_SRC_REG  0x0
#define DPA_IPCMSG_DST_REG  0x4
#define DPA_IPCMSG_MODE_REG  0x10
#define DPA_IPCMSG_IMASK_REG  0x14
#define DPA_IPCMSG_SEND_REG  0x1C
#define DPA_IPCMSG_ICLR_REG  0x18
#define DPA_IPCMSG_DATA0_REG 0x20
#define DPA_IPCMSG_FAST_IPC 0xFFFFABCD

#define DPA_IPCMSG_OFFSET 128
#define DPA_IPCMSG_IMASK_ALL 0xFFFFFFFF

#define DPA_IPC_BIT_MASK(n) (1UL << (n))

#define DPA_IPC_MODE 0x1
#define DPA_IPC_RECV_MAILBOX_NUM 0x2 // 接收来自dpa fw、m3两个核的IPC中断

/*
 * 寄存器说明：数据寄存器。
 * 位域定义UNION结构:  IPC_MBX_DATA0_UNION
 */
#define DPA_IPC_MBX_DATA_ADDR(mbx_id, reg_idx, offset) (0x020 + (mbx_id) * (offset) + ((reg_idx) << 2))

struct dpa_ipcmsg_device_t {
    u32 base_pa;
    void *base_va;
    u32 size;
    u32 irq[DPA_IPC_RECV_MAILBOX_NUM];
#ifdef CONFIG_LIBLINUX
    u32 hwirq[DPA_IPC_RECV_MAILBOX_NUM];
#endif
    u32 send_mbx_id;
    u32 recv_mbx_id[DPA_IPC_RECV_MAILBOX_NUM];
    u32 local_id;
    u32 remote_id[DPA_IPC_RECV_MAILBOX_NUM];
};
struct dpa_ipcmsg_device_t *dpa_ipcmsg_dev_get(void);
#endif
