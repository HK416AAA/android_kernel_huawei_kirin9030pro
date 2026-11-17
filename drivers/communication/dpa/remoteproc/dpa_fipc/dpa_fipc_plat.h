/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2025. All rights reserved.
 */
#ifndef _DPA_FIPC_PLAT_H_
#define _DPA_FIPC_PLAT_H_

#include <linux/version.h>
#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/kthread.h>  /* struct task_struct */
#include <linux/spinlock.h> /* struct spinlock */
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <uapi/linux/sched/types.h> /* struct sched_param */
#include <linux/types.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>

#include "securec.h"
#include "bsp_print.h"
#include "bsp_dpa_fipc.h"

#define THIS_MODU mod_dpa_fipc
#define dpa_fipc_crit(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_fipc_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_fipc_warn(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_fipc_print(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_fipc_always(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_fipc_trace(fmt, ...)

#define dpa_fipc_roundup(x, n) (((x) + (n)-1) & (~((n)-1)))

enum dpa_fipc_chn_stat {
    DPA_FIPC_CHN_INIT = 0x0001,         /* 初始化完的状态，以及调用close之后的状态 */
    DPA_FIPC_CHN_OPEN = 0x0002,         /* 调用open后打开的状态 */
    DPA_FIPC_CHN_OPENNOSR = 0x0003,     /* 某些特殊通道调用open后打开的状态 */
    DPA_FIPC_CHN_OSUSPENDING = 0x0004,  /* 低功耗正在关闭opipe的状态 */
    DPA_FIPC_CHN_OSUSPENDED = 0x0005,   /* 低功耗已经关闭opipe的状态 */
    DPA_FIPC_CHN_ISUSPENDING = 0x0006,  /* 低功耗正在关闭ipipe的状态 */
    DPA_FIPC_CHN_ISUSPENDED = 0x0007,   /* 低功耗已经关闭ipipe的状态 */
    DPA_FIPC_CHN_SUSPENDED = 0x0008,    /* 低功耗已经完成empty检查，完成低功耗的状态 */
    DPA_FIPC_CHN_DSSSUSPENDED = 0x0009, /* 某些特殊通道低功耗已经完成empty检查，完成低功耗的状态 */
    DPA_FIPC_CHN_CLOSING = 0x000A,      /* 调用close的中间的状态 */
    DPA_FIPC_CHN_ORESETTING = 0x000B,   /* 单独复位正在关闭opipe的状态 */
    DPA_FIPC_CHN_ORESETTED = 0x000C,    /* 单独复位已经关闭opipe的状态 */
    DPA_FIPC_CHN_IRESETTING = 0x000D,   /* 单独复位正在关闭ipipe的状态 */
    DPA_FIPC_CHN_IRESETTED = 0x000E,    /* 单独复位已经关闭ipipe的状态 */
    DPA_FIPC_CHN_RESETTED = 0x000F,     /* 单独复位已经完成关闭pipe的状态 */
};

static inline u32 DPA_FIPC_ADDR_LO(dpafipcsoc_ptr_t soc_addr)
{
    return (u32)soc_addr;
}
static inline u32 DPA_FIPC_ADDR_HI(dpafipcsoc_ptr_t soc_addr)
{
    return (u32)0;
}
static inline void *dpa_fipc_malloc(u32 size)
{
    return kmalloc(size, GFP_KERNEL);
}
static inline void dpa_fipc_free(const void *paddr)
{
    kfree(paddr);
}

void *dpa_fipc_alloc_coherent(u32 size, dpafipcsoc_ptr_t *pa, u32 align);
void dpa_fipc_free_coherent(u32 size, void *va, dpafipcsoc_ptr_t pa);
int bsp_dpa_fipc_suspend(void);
int bsp_dpa_fipc_resume(void);
#endif