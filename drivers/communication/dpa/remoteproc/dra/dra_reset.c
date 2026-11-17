/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include <linux/netdevice.h>
#include <linux/kthread.h>
#include <uapi/linux/sched/types.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/kfifo.h>
#include <securec.h>
#include <bsp_print.h>
#include <bsp_slice.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>
#include <bsp_mem_layout.h>
#include <bsp_dpa_sysctrl.h>
#include <bsp_sms.h>
#include <dpa_reset.h>
#include "dra.h"
#include "dra_hal.h"
#include "dra_def.h"

#define DPA_MAP_MAGIC 0x123

static void dra_fifo_clear(struct dra_fifo *fifo)
{
    int ret;

    fifo->idx = 0;
    fifo->write = 0;
    fifo->read = 0;
    fifo->empty = 1;

    ret = memset_s(fifo->local_buf, DRA_BURST_LEN * sizeof(unsigned long long), 0, DRA_BURST_LEN * sizeof(unsigned long long));
    if (ret) {
        dra_err("memset_s fail\n");
    }

    if (fifo->update_write_virt != 0) {
        *(unsigned int *)(uintptr_t)fifo->update_write_virt = 0;
    }

    if (fifo->update_read_virt != 0) {
        *(unsigned int *)(uintptr_t)fifo->update_read_virt = 0;
    }
}

// IP不复位
void dra_kfifo_recycle(struct dra_opipe *opipe)
{
    struct list_head *list = &opipe->map.busy_list;
    struct dra_tab *tmp = NULL;
    struct dra_tab *next = NULL;
    struct page *page = NULL;

    opipe->reuse_fifo.kfifo.in = 0;
    opipe->reuse_fifo.kfifo.out = 0;
    list_for_each_entry_safe(tmp, next, list, list) {
        page = phys_to_page(bsp_dra_to_phy(tmp->dra_addr));
        kfifo_in(&opipe->reuse_fifo, &tmp->dra_addr, 1);
    }
}

void dra_clear_tcpip(struct dra *dra, int level)
{
    struct dra_map *map = NULL;
    struct dra_tab *tab = NULL;
    struct dra_tab *tmp = NULL;
    struct dra_opipe *opipe = NULL;
    struct sk_buff *skb = NULL;
    unsigned long flags;

    opipe = &dra->opipes[level];
    map = &opipe->map;

    spin_lock_irqsave(&opipe->lock, flags);
    list_for_each_entry_safe(tab, tmp, &map->busy_list, list) {
        if (tab->magic == DRA_OWN) {
            skb = dra_unmap_tcpip_skb_unlock(dra, (dra_buf_t)tab->dra_addr);
            if (skb != NULL) {
                dev_kfree_skb_any(skb);
            }
        }
    }
    spin_unlock_irqrestore(&opipe->lock, flags);
}

// IP不复位
/* dra重配置一套level内存池：1、关闭alloc，2、关闭rls和bigpool，3、重新配置ddrbuf的读写指针 */
void dra_chn_reinit(struct dra *dra, unsigned int level)
{
    dra_fifo_clear(&dra->rls_opipes[level].fifo);
    if (dra->para->rls_chn_depth[level] != 0) {
        dra_rls_fifo_init(dra, &dra->rls_opipes[level], level);
    }
    dra_enable_big_pool(dra, level, 0);
    dra_fifo_clear(&dra->opipes[level].fifo);
    dra_fifo_reinit(dra, &dra->opipes[level].fifo, level);
    dra_ddr_buf_ptr_clear(dra, level);
}

static inline void dra_chn_refill(struct dra *dra, unsigned int level)
{
    if (dra->para->oparamter.disable_irq[level]) {
        //全部补充
        dra_err("reset fill buf:%d\n", level);
        dra_fill_fifo(dra, &dra->opipes[level].fifo, dra->opipes[level].map.tab_max_size);
    } else {
        dra_fill_fifo(dra, &dra->opipes[level].fifo, dra->opipes[level].fifo.dthrl);
    }
}

/* sne acpu口下移前：tcpip内存全回收；sne acpu口下移后：tcpip内存回收发送给modem的，其余按照正常流程，等对应的gso分片内存回收完后释放 */
void dra_rst_buf_process_level0(struct dra *dra, unsigned int level)
{
    dra_err("dra_rst_buf_process:%d\n", level);
    if (dpa_sms_filter_cpu_port_offload_en()) {
        return;
    }

    dra_recycle_func(dra);
    dra_clear_tcpip(dra, DRA_OPIPE_LEVEL_0);
}

/* 回收还在modem内的（tab外的），数据不走dpa：不会map tab，全回收；数据走dpa时，map到tab */
void dra_rst_buf_process_level8(struct dra *dra, unsigned int level)
{
    int j;
    struct dra_tab_info *tab_info = NULL;
    struct dra_tab *tab = NULL;
    unsigned long flags;
    LIST_HEAD(local_list);

    dra_err("dra_rst_buf_process:%d\n", level);

    INIT_LIST_HEAD(&local_list);
    tab_info = dra->tab_info_level8;
    for (j = 0; j < dra->para->oparamter.tab_size[level]; j++) {
        spin_lock_irqsave(&dra->opipes[level].lock, flags);
        if (tab_info[j].buf != 0) {
            tab = dra_get_tab(dra, (dra_buf_t)tab_info[j].buf);
            list_move_tail(&tab->list, &local_list); // 从busylist删除，然后把busylist中剩余的内存回收
        }
        spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
    }

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    dra_kfifo_recycle(&dra->opipes[level]); //page必须使用fifo判断refcnt回收内存
    list_splice_init(&local_list, &dra->opipes[level].map.busy_list);
    dra_chn_reinit(dra, level);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra_chn_refill(dra, level);
}

/* 该level对应的通道全部重新初始化+内存全回收 */
void dra_rst_buf_process_level_comm(struct dra *dra, unsigned int level)
{
    unsigned long flags;

    dra_err("dra_rst_buf_process:%d\n", level);

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    list_splice_init(&dra->opipes[level].map.busy_list, &dra->opipes[level].map.reclaim_list);
    dra->opipes[level].reclaim_depth += dra->opipes[level].busy_depth;
    dra->opipes[level].delay_free_cnt += dra->opipes[level].busy_depth;
    dra->opipes[level].busy_depth = 0;

    dra_chn_reinit(dra, level);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra_chn_refill(dra, level);
}

void dra_rst_buf_process(struct dra *dra)
{
    dra_rst_buf_process_level8(dra, DRA_OPIPE_LEVEL_8);

    dra_rst_buf_process_level_comm(dra, DRA_OPIPE_LEVEL_2);
    dra_rst_buf_process_level_comm(dra, DRA_OPIPE_LEVEL_3);
    dra_rst_buf_process_level_comm(dra, DRA_OPIPE_LEVEL_7);

    dra_rst_buf_process_level0(dra, DRA_OPIPE_LEVEL_0);
}

// mdm单独复位前
int dra_deinit(void)
{
    struct dra *dra = g_dra_ctx;

    disable_irq(dra->irq);

    set_bit(DRA_EVENT_RESETTING_BIT, (void *)&dra->event);
    set_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event);
    wake_up(&dra->wqueue);
    wait_event(dra->wqueue, test_bit(DRA_EVENT_THREAD_STOPED_BIT, (void *)&dra->event) && !test_bit(DRA_EVENT_REPORT_BIT, (void *)&dra->event));

    mod_timer(&dra->timer, jiffies + DRA_TIMER_EXPIRES);

    dra->deinit_cnt++;
    return 0;
}
EXPORT_SYMBOL(dra_deinit);

int dra_interrupt_reinit(struct dra *dra)
{
    unsigned int level;

    dra->int_mask = 0;
    for (level = 0; level <= dra->max_opipes; level++) {
        if (!dra->para->oparamter.disable_irq[level]) {
            dra->int_mask |= 1 << level;
        }
    }

    dra->event = 0;
    dra_interupt_init(dra);
    enable_irq(dra->irq);
    return 0;
}

// mdm单独复位中,dra回收内存及通道恢复
int bsp_dra_reinit(void)
{
    struct dra *dra = g_dra_ctx;
    dra_rst_buf_process(dra);
    dra_interrupt_reinit(dra);
    dra->reinit_cnt++;
    return 0;
}
EXPORT_SYMBOL(bsp_dra_reinit);

// dpa单独复位,modem侧独立使用的level不回收，2,3,7
unsigned int g_dra_dpa_rst_level[] = {DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_9};

void dra_dpa_rst_chn_reinit(struct dra *dra, unsigned int level)
{
    // 重置顺序rls->bigpool->ddr_buf->alloc
    dra_fifo_clear(&dra->rls_opipes[level].fifo);
    if (dra->para->rls_chn_depth[level] != 0) {
        dra_rls_fifo_init(dra, &dra->rls_opipes[level], level);
    }
    dra_enable_big_pool(dra, level, 0);
    dra_fifo_clear(&dra->opipes[level].fifo);
    dra_fifo_reinit(dra, &dra->opipes[level].fifo, level);
    dra_ddr_buf_ptr_clear(dra, level);

    dra_fifo_clear(&dra->cpu_ipipes[level].fifo);
    dra_ipipe_init(dra, &dra->cpu_ipipes[level], dra->para->iparamter.ipipeidx[level]);
}

int dra_dpa_rst_deinit(void)
{
    struct dra *dra = g_dra_ctx;
    unsigned long flags;
    unsigned int level;
    int i;

    // 关闭中断
    disable_irq(dra->irq);

    set_bit(DRA_EVENT_RESETTING_BIT, (void *)&dra->event);
    set_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event);
    wake_up(&dra->wqueue);
    wait_event(dra->wqueue, test_bit(DRA_EVENT_THREAD_STOPED_BIT, (void *)&dra->event) && !test_bit(DRA_EVENT_REPORT_BIT, (void *)&dra->event));

    mod_timer(&dra->timer, jiffies + DRA_TIMER_EXPIRES);
    for (i = 0; i < sizeof(g_dra_dpa_rst_level) / sizeof(unsigned int); i++) {
        level = g_dra_dpa_rst_level[i];
        spin_lock_irqsave(&dra->opipes[level].lock, flags);
        dra_enable_alloc_ch(dra, dra->cpu_ipipes[level].idx, 0);
        dra_enable_rls_ch(dra, dra->rls_opipes[level].idx, 0);
        dra_enable_big_pool(dra, dra->opipes[level].level, 0);
        spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
    }
    level = DRA_OPIPE_LEVEL_10;
    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    dra_enable_alloc_ch(dra, dra->cpu_ipipes[level].idx, 0);
    dra_enable_big_pool(dra, dra->opipes[level].level, 0);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra->deinit_cnt++;
    return 0;
}

void dra_dpa_rst_buf_process_level0(struct dra *dra, unsigned int level)
{
    struct dra_map *map = NULL;
    struct dra_tab *tab = NULL;
    struct dra_tab *tmp = NULL;
    struct dra_opipe *opipe = NULL;
    struct sk_buff *skb = NULL;
    unsigned long flags;

    dra_err("reset bigpool:%d\n", level);
    opipe = &dra->opipes[level];
    map = &opipe->map;

    spin_lock_irqsave(&opipe->lock, flags);
    list_for_each_entry_safe(tab, tmp, &map->busy_list, list) {
        if (tab->magic == DRA_OWN_DPA) {
            skb = dra_unmap_tcpip_skb_unlock(dra, (dra_buf_t)tab->dra_addr);
            if (skb != NULL) {
                dev_kfree_skb_any(skb);
            }
        }
    }
    spin_unlock_irqrestore(&opipe->lock, flags);
}

/* 回收发送给modem的，acpu口下移前：不使用AP2K内存，不会回收；acpu口下移后：回收tab内的（发送给mdoem的） */
void dra_dpa_rst_buf_process_level1(struct dra *dra, unsigned int level)
{
    int j;
    struct dra_tab_info *tab_info = NULL;
    struct dra_tab *tab = NULL;
    unsigned long flags;
    LIST_HEAD(local_list);

    dra_err("reset bigpool:%d\n", level);

    INIT_LIST_HEAD(&local_list);
    // AP2K tab中的内存是modem发到dpa并且还未回收的，回收tab外的
    tab_info = dra->tab_info_level1;
    for (j = 0; j < dra->para->oparamter.tab_size[level]; j++) {
        if (tab_info[j].buf != 0) {
            tab_info[j].tcpip_buf = 0;
            spin_lock_irqsave(&dra->opipes[level].lock, flags);
            tab = dra_get_tab(dra, (dra_buf_t)tab_info[j].buf);
            list_move_tail(&tab->list, &local_list); // 从busylist删除，然后把busylist中剩余的内存回收
            spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
        }
    }

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    dra_kfifo_recycle(&dra->opipes[level]); //page必须使用fifo判断refcnt回收内存
    list_splice_init(&local_list, &dra->opipes[level].map.busy_list);
    dra_dpa_rst_chn_reinit(dra, level);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra_chn_refill(dra, level);
}

/* 回收还在modem内的（tab外的），数据不走dpa：不会map tab，全回收；数据走dpa时，map到tab */
void dra_dpa_rst_buf_process_level8(struct dra *dra, unsigned int level)
{
    int j;
    struct dra_tab_info *tab_info = NULL;
    struct dra_tab *tab = NULL;
    unsigned long flags;

    dra_err("reset bigpool:%d\n", level);
    spin_lock_irqsave(&dra->opipes[level].lock, flags);

    tab_info = dra->tab_info_level8;
    for (j = 0; j < dra->para->oparamter.tab_size[level]; j++) {
        if (tab_info[j].buf == 0) {
            continue;
        }

        tab = dra_get_tab(dra, (dra_buf_t)tab_info[j].buf);
        if (tab->magic == DRA_OWN) {
            dra_rls_input(dra, (tab_info[j].buf & DRA_ADDR_MASK) + DRA_SKB_RESERVE_SIZE, &dra->rls_opipes[level], level);
        } else {
            dra_err("reset err buf:0x%llx-0x%x\n", tab_info[j].buf, tab->magic);
        }
        tab_info[j].buf = 0;
    }
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
}

/* 回收DRA_OWN的 */
void dra_dpa_rst_buf_process_level9(struct dra *dra, unsigned int level)
{
    unsigned long flags;
    struct dra_shm_info *info = NULL;
    struct list_head *list = &dra->opipes[level].map.busy_list;
    struct dra_map *map = &dra->opipes[level].map;
    struct dra_tab *tmp = NULL;
    struct dra_tab *next = NULL;

    dra_err("reset bigpool:%d\n", level);

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    list_for_each_entry_safe(tmp, next, list, list) {
        info = tmp->manager - sizeof(struct dra_shm_info);
        if (info->magic == DRA_OWN) {
            list_move_tail(&tmp->list, &map->reclaim_list);
            dra->opipes[level].reclaim_depth++;
            dra->opipes[level].delay_free_cnt++;
            dra->opipes[level].busy_depth--;
        }
    }
    dra_dpa_rst_chn_reinit(dra, level);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra_chn_refill(dra, level);
}

/* 该level对应的通道全部重新初始化+内存全回收 */
void dra_dpa_rst_buf_process_level_comm(struct dra *dra, unsigned int level)
{
    unsigned long flags;

    dra_err("reset bigpool:%d\n", level);

    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    list_splice_init(&dra->opipes[level].map.busy_list, &dra->opipes[level].map.reclaim_list);
    dra->opipes[level].reclaim_depth += dra->opipes[level].busy_depth;
    dra->opipes[level].delay_free_cnt += dra->opipes[level].busy_depth;
    dra->opipes[level].busy_depth = 0;
    dra_dpa_rst_chn_reinit(dra, level);
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    dra_chn_refill(dra, level);
}

// 内存回收要放在dpa停止工作和重启之前
void dra_dpa_rst_buf_process(struct dra *dra)
{
    dra_dpa_rst_buf_process_level0(dra, DRA_OPIPE_LEVEL_0);
    dra_dpa_rst_buf_process_level1(dra, DRA_OPIPE_LEVEL_1);
    dra_dpa_rst_buf_process_level8(dra, DRA_OPIPE_LEVEL_8);
    dra_dpa_rst_buf_process_level9(dra, DRA_OPIPE_LEVEL_9);
    dra_dpa_rst_buf_process_level_comm(dra, DRA_OPIPE_LEVEL_10);
}

int dra_dpa_reset_cb(dpa_reset_stage_e enparam, int arg)
{
    struct dra *dra = g_dra_ctx;
    if (enparam == DPA_RESET_BEFORE) {
        dra_err("dra rst before\n");
        dra_sync_for_dpa();
        return dra_dpa_rst_deinit();
    } else if (enparam == DPA_RESET_AFTER) {
        dra_err("dra rst after\n");
        dra_interrupt_reinit(dra);
        return 0;
    }
    return 0;
}

void bsp_dra_dpa_rst(void)
{
    struct dra *dra = g_dra_ctx;
    dra_dpa_rst_buf_process(dra);
}

int dra_dpa_rst_init(void)
{
    int ret;

    ret = bsp_dpa_reset_register_cb("dra", dra_dpa_reset_cb, 0, DPA_RESET_CB_LEVEL_DRA);
    if (ret) {
        dra_err("reg dpa rst fail:%d\n", ret);
    }
    return ret;
}