/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description:流控接口函数
 * Author: dpa drivers
 */

#include "conn_dmi_msg.h"
#include "oal_util.h"
#include "oal_net.h"
#include "board_pm.h"
#include "conn_dmi_flowctrl.h"

static volatile int32_t g_flowctrl_alloc_cnt = 0;
static mdrv_spin_lock_t g_flowctrl_spinlock;

void oal_netbuf_spinlock_init(void)
{
    if (mdrv_spin_lock_zalloc(&g_flowctrl_spinlock) != OAL_SUCC) {
        bsp_print("g_flowctrl_spinlock init fail!\n");
        sys_abort(1);
    }
}

void oal_netbuf_spinlock_exit(void)
{
    mdrv_spin_lock_free(&g_flowctrl_spinlock);
}

static inline int32_t netbuf_flowctrl_on(uint32_t len)
{
    return 0;
}

static inline int32_t netbuf_flowctrl_off(uint32_t len)
{
    return 0;
}

/* 使用时需在外层持锁g_flowctrl_spinlock */
static inline void netbuf_flowctrl_cnt_inc(int32_t cnt)
{
    if (cnt == 0) {
        return;
    }

    if (g_flowctrl_alloc_cnt >= DPA_SBUF_FLOWCTRL_ON) {
        netbuf_flowctrl_on(g_flowctrl_alloc_cnt);
    }
    g_flowctrl_alloc_cnt += cnt;
}

/* 使用时需在外层持锁g_flowctrl_spinlock */
static inline void netbuf_flowctrl_cnt_dec(int32_t cnt)
{
    if (cnt == 0) {
        return;
    }

    if (g_flowctrl_alloc_cnt <= DPA_SBUF_FLOWCTRL_OFF) {
        netbuf_flowctrl_off(g_flowctrl_alloc_cnt);
    }
    if (g_flowctrl_alloc_cnt < cnt) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "plat_netbuf underflow. alloc:%d, dec:%d", g_flowctrl_alloc_cnt, cnt);
    }
    g_flowctrl_alloc_cnt -= cnt;
}

void netbuf_flowctrl_check(void)
{
    if (g_flowctrl_alloc_cnt != 0) {
        oal_print_mpxx_log(MPXX_LOG_ERR, "plat_sbuf_cnt:%d", g_flowctrl_alloc_cnt);
    }
}

/*
 * 平台流控基于平台所持有的sbuf数量实现
 * 通过统计平台hcc、dmi、ete各队列中的sbuf个数，分别在上下水线发起/解除流控
 */

void hcc_netbuf_addlist_tail_with_flowctrl(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    unsigned long irq_sts;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    oal_netbuf_addlist_tail(head, buf);
    netbuf_flowctrl_cnt_inc(1);
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
}

void hcc_netbuf_addlist_head_with_flowctrl(oal_netbuf_head_stru *head, oal_netbuf_stru *buf)
{
    unsigned long irq_sts;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    oal_netbuf_addlist_head(head, buf);
    netbuf_flowctrl_cnt_inc(1);
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
}

oal_netbuf_stru *hcc_netbuf_delist_head_with_flowctrl(oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;
    oal_netbuf_stru *netbuf = NULL;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    netbuf = oal_netbuf_delist_head(head);
    if (netbuf != NULL) {
        netbuf_flowctrl_cnt_dec(1);
    }
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
    return netbuf;
}

oal_netbuf_stru *hcc_netbuf_delist_tail_with_flowctrl(oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;
    oal_netbuf_stru *netbuf = NULL;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    netbuf = oal_netbuf_delist_tail(head);
    if (netbuf != NULL) {
        netbuf_flowctrl_cnt_dec(1);
    }
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
    return netbuf;
}

int32_t hcc_netbuf_clear_list_with_flowctrl(oal_netbuf_head_stru *head)
{
    int32_t ret;
    unsigned long irq_sts;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    ret = (int32_t)oal_netbuf_clear_list(head);
    netbuf_flowctrl_cnt_dec(ret);
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
    return ret;
}

void hcc_netbuf_delete_with_flowctrl(oal_netbuf_stru *netbuf, oal_netbuf_head_stru *head)
{
    unsigned long irq_sts;

    irq_sts = mdrv_spin_lock_irqsave(&g_flowctrl_spinlock);
    oal_netbuf_delete(netbuf, head);
    netbuf_flowctrl_cnt_dec(1);
    mdrv_spin_unlock_irqrestore(&g_flowctrl_spinlock, irq_sts);
}

