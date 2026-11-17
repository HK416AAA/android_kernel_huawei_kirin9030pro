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
#include <bsp_dpa_syscache.h>
#include <bsp_mem_layout.h>
#include <bsp_dpa_sysctrl.h>
#include <bsp_dpa.h>
#include "dra.h"
#include "dra_hal.h"
#include "dra_def.h"
#include "dra_lv_sbuf.h"

#define DRA_MEM_LINE_DEAULT 100

#define DRA_CURRETN_AVAIL_MEM ((unsigned int)si_mem_available() << (PAGE_SHIFT - 10))
#define DRA_TWO_BURST_RESERVE (2 * DRA_BURST_LEN)

#define DRA_RECYCLE_CH_CNT 2
#define DRA_THREAD_PRIORITY (MAX_RT_PRIO - 1)
#define DRA_FIFO_MIN_DEPTH 0x20
#define DRA_SCHED_GAP 10
#define DRA_PAGE_MASK (PAGE_SIZE - 1)
#define DRA_FIRST_OR_SECOND_2K(addr) (((addr) & DRA_PAGE_MASK) ? 1 : 0) // addr must 2k align

#define DRA_MAX_SKB_SIZE (max(sizeof(struct sk_buff), sizeof(struct skb_shared_info)))
#define DRA_SKB_OFFSET(X) ((X) - DRA_MAX_SKB_SIZE - sizeof(struct dra_tab))
#define DRA_UNREUSE_THRESHOLD 128
#define DRA_SHM_BLK_SIZE (1024)
struct dra *g_dra_ctx;
EXPORT_SYMBOL(g_dra_ctx);

unsigned int g_dra_once_flag = 0;
#define dra_err_once(fmt, ...)           \
    do {                                 \
        if (!g_dra_once_flag) {          \
            dra_err("Warning once \n");  \
            dra_err(fmt, ##__VA_ARGS__); \
            g_dra_once_flag = 1;         \
        }                                \
    } while (0)

#define dra_print_slice(fmt, ...)                          \
    do {                                                   \
        if (dra->dbg & DRA_DEBUG_PRINT_SLICE) {            \
            bsp_info("<%s>" fmt, __func__, ##__VA_ARGS__); \
        }                                                  \
    } while (0)

#define dra_bug_on()                                                 \
    do {                                                             \
        dump_stack();                                                \
        if (dra->dbg & DRA_DEBUG_BUGON) {                            \
            BUG_ON(1);                                               \
        }                                                            \
    } while (0)

/* dra alloc buff size */
static const int g_level_size[DRA_OPIPE_MAX] = {
    DRA_OPIPE_LEVEL_0_BUFF_SIZE, DRA_OPIPE_LEVEL_1_BUFF_SIZE, DRA_OPIPE_LEVEL_2_SIZE,
    DRA_OPIPE_LEVEL_3_BUFF_SIZE, DRA_OPIPE_LEVEL_4_SIZE, DRA_OPIPE_LEVEL_5_SIZE,
    DRA_OPIPE_LEVEL_6_SIZE, DRA_OPIPE_LEVEL_7_SIZE, DRA_OPIPE_LEVEL_1_BUFF_SIZE,
    DRA_OPIPE_LEVEL_9_SIZE, DRA_OPIPE_LEVEL_10_SIZE
};

/* data size in buff */
static const int g_level_data_size[DRA_OPIPE_MAX] = {
    DRA_OPIPE_LEVEL_0_SIZE, DRA_OPIPE_LEVEL_1_SIZE, DRA_OPIPE_LEVEL_2_SIZE, DRA_OPIPE_LEVEL_3_SIZE,
    0, 0, 0, 0, DRA_OPIPE_LEVEL_1_SIZE, DRA_OPIPE_LEVEL_9_SIZE + sizeof(dra_buf_t), DRA_OPIPE_LEVEL_10_SIZE
};

static const int g_dra_report_level[] = {
    DRA_OPIPE_LEVEL_0, DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_2, DRA_OPIPE_LEVEL_3, DRA_OPIPE_LEVEL_7, DRA_OPIPE_LEVEL_8, DRA_OPIPE_LEVEL_9
};

static const int g_dra_alloc_report_level[DRA_ALLOC_REPORT_CNT] = {
    DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_9
};

static const unsigned int g_dra_timer_level[] = {
    DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_10
};

unsigned long long bsp_dra_page_to_dra(struct page *page, unsigned int offset)
{
    struct dra_tab *tab = NULL;
    char *buff = NULL;

    buff = (char *)((unsigned long long)(uintptr_t)(page_to_virt(page) + offset) & (~(2048 - 1)));
    tab = (struct dra_tab *)DRA_BUF_TO_TAB(buff, g_level_size[DRA_OPIPE_LEVEL_1]);

    if (tab->magic == DRA_OWN) {
        return tab->dra_addr;
    } else {
        return 0;
    }
}

struct sk_buff *dra_unmap_tcpip_skb_unlock(struct dra *dra, dra_buf_t buf)
{
    struct dra_opipe *opipe = NULL;
    struct dra_map *map = NULL;
    struct dra_tab *tab = NULL;
    struct sk_buff *skb = NULL;
    unsigned int level = buf.bits.level;
    unsigned int idx = buf.bits.idx;

    if (unlikely(level != DRA_OPIPE_LEVEL_0)) {
        dra_err("tcpip buf level error:0x%llx", buf.addr);
        return NULL;
    }

    opipe = &dra->opipes[level];
    map = &opipe->map;

    if (unlikely(idx < DRA_TABEL_START || idx > (map->tab_max_size - 1))) {
        dra_err("tcpip buf error:0x%llx", buf.addr);
        return NULL;
    }

    tab = &map->tab[idx];

    if (unlikely(tab->magic != DRA_OWN && tab->magic != DRA_OWN_DPA)) {
        dra_err("buf already free:0x%llx", buf.addr);
        return NULL;
    }

    skb = (struct sk_buff *)tab->manager;
    tab->manager = (void *)(uintptr_t)(buf.addr + 1);
    tab->magic = DRA_FREE;
    tab->dra_addr = (unsigned long long)((uintptr_t)skb) + 1;

    list_move_tail(&tab->list, &map->free_list);
    dra->opipes[level].busy_depth--;
    map->busy--;
    map->free++;
    map->curr = tab->idx;
    dra->opipe_status[level].unmap_tcp_ip++;

    if (skb->len) {
        bsp_dpa_sc_dma_unmap_single(dra->dev, (dma_addr_t)virt_to_phys(skb->data), skb->len, DMA_TO_DEVICE);
    } else {
        dra_err("skb->len is zero\n");
    }

    return skb;
}

unsigned long long dra_map_tcpip_skb(struct dra *dra, struct sk_buff *skb, unsigned int reserve, unsigned int magic)
{
    unsigned long long reversed_addr;
    unsigned long long phy;
    unsigned int level;

    if (dra->event & DRA_EVENT_RESETTING) {
        return 0;
    }

    level = DRA_OPIPE_LEVEL_0; // tcpip包独立通道
    if (dra_tab_is_empty(dra, level)) {
        dra->opipe_status[level].map_tcp_ip_fail++;
        return 0;
    }
    /* draaddr point to iphead */
    phy = bsp_dpa_sc_dma_map_single(dra->dev, skb->data, skb_headlen(skb), DMA_TO_DEVICE);

    reversed_addr = dra_map_single(dra, phy + reserve, skb, DRA_SKB_FROM_TCP_IP, level, magic);
    if (!reversed_addr) {
        dra->opipe_status[level].map_tcp_ip_fail++;
        return 0;
    }
    dra->opipe_status[level].map_tcp_ip_ok++;

    return reversed_addr;
}

struct sk_buff *dra_unmap_tcpip_skb(struct dra *dra, dra_buf_t buf)
{
    struct dra_opipe *opipe = NULL;
    struct dra_map *map = NULL;
    struct dra_tab *tab = NULL;
    struct sk_buff *skb = NULL;
    unsigned int level = buf.bits.level;
    unsigned int idx = buf.bits.idx;
    unsigned long flags = 0;

    if (unlikely(level != DRA_OPIPE_LEVEL_0)) {
        dra_err("tcpip buf level error:0x%llx", buf.addr);
        return NULL;
    }

    opipe = &dra->opipes[level];
    map = &opipe->map;

    if (unlikely(idx < DRA_TABEL_START || idx > (map->tab_max_size - 1))) {
        dra_err("tcpip buf error:0x%llx", buf.addr);
        return NULL;
    }

    spin_lock_irqsave(&opipe->lock, flags);
    tab = &map->tab[idx];

    if (unlikely(tab->magic != DRA_OWN && tab->magic != DRA_OWN_DPA)) {
        spin_unlock_irqrestore(&opipe->lock, flags);
        dra_err("buf already free:0x%llx", buf.addr);
        return NULL;
    }

    skb = (struct sk_buff *)tab->manager;
    tab->manager = (void *)(uintptr_t)(buf.addr + 1);
    tab->magic = DRA_FREE;
    tab->dra_addr = (unsigned long long)((uintptr_t)skb) + 1;

    list_move_tail(&tab->list, &map->free_list);
    dra->opipes[level].busy_depth--;
    map->busy--;
    map->free++;
    map->curr = tab->idx;
    dra->opipe_status[level].unmap_tcp_ip++;
    spin_unlock_irqrestore(&opipe->lock, flags);

    if (skb->len) {
        bsp_dpa_sc_dma_unmap_single(dra->dev, (dma_addr_t)virt_to_phys(skb->data), skb->len, DMA_TO_DEVICE);
    } else {
        dra_err("skb->len is zero\n");
    }

    return skb;
}

static inline char *dra_check_own_buf(struct dra *dra, dra_buf_t buf)
{
    char *buf_virt = NULL;
    unsigned int idx;

    /* 涉及9k内存回收处理 */
    if (buf.bits_1.level == DRA_OPIPE_LEVEL_1 || buf.bits_1.level == DRA_OPIPE_LEVEL_8) {
        idx = buf.bits_1.idx;
    } else {
        idx = buf.bits.idx;
    }

    if (unlikely(buf.bits_1.level == DRA_OPIPE_LEVEL_3)) {
        if (unlikely(idx != DRA_SKB_OFFSET(g_level_size[buf.bits_1.level]))) {
            dra_err("invalid  idx dra 0x%llx\n", buf.addr);
            dra->status.unmap_invalid_idx++;
            return NULL;
        }
    } else {
        if (unlikely(idx > dra->para->oparamter.tab_size[buf.bits.level])) {
            dra_err("invalid  idx dra 0x%llx\n", buf.addr);
            dra->status.unmap_invalid_idx++;
            return NULL;
        }
    }

    buf_virt = (char *)phys_to_virt((buf.bits_1.phyaddr & DRA_ADDR_MASK));
    return buf_virt;
}

struct dra_tab *dra_get_tab(struct dra *dra, dra_buf_t buf)
{
    struct dra_map *map = NULL;
    unsigned int level = buf.bits.level;
    struct dra_tab *tab = NULL;
    char *buf_virt = NULL;

    /* 涉及9k内存回收处理 */
    if (unlikely(buf.bits.level != DRA_OPIPE_LEVEL_0 && buf.bits.level != DRA_OPIPE_LEVEL_1
        && buf.bits.level != DRA_OPIPE_LEVEL_3 && buf.bits.level != DRA_OPIPE_LEVEL_8
        && buf.bits.level != DRA_OPIPE_LEVEL_9 && buf.bits.level != DRA_OPIPE_LEVEL_10)) {
        dra_err("invalid level dra 0x%llx\n", buf.addr);
        dra->status.unmap_invalid_level++;
        dra_bug_on();
        return NULL;
    }

    if (dra->opipes[level].use_tab) {
        map = &dra->opipes[level].map;
        if (unlikely(buf.bits.idx < DRA_TABEL_START || buf.bits.idx > (map->tab_max_size - 1))) {
            goto fail;
        }
        tab =  &map->tab[buf.bits.idx];
    } else {
        buf_virt = dra_check_own_buf(dra, buf);
        if (unlikely(buf_virt == NULL)) {
            goto fail;
        }

        tab = (struct dra_tab *)DRA_BUF_TO_TAB(buf_virt, g_level_size[buf.bits.level]);
    }

    if (unlikely(tab->magic != DRA_OWN && tab->magic != DRA_UNMAP)) {
        dra_err("magic %x, dra 0x%llx, olddra 0x%llx\n", tab->magic, buf.addr, tab->dra_addr);
        dra->status.maybe_dobulefree_or_modified++;
        dra_bug_on();
        return NULL;
    }

    return tab;

fail:
    dra->status.unmap_invalid_idx++;
    dra_err("invalid idx dra 0x%llx\n", buf.addr);
    dra_bug_on();
    return NULL;
}

void dra_hds_transreport(void)
{
    int i, level;
    struct dra *dra = g_dra_ctx;
    struct dra_debug_info *dbg_info = &dra->hds_debug_info;

    set_bit(DRA_EVENT_REPORT_BIT, (void *)&dra->event);
    if (!test_bit(DRA_EVENT_RESETTING_BIT, (void *)&dra->event)) {
        dra_hds_transreport_hal(dra, dbg_info);
    }
    clear_bit(DRA_EVENT_REPORT_BIT, (void *)&dra->event);
    wake_up(&dra->wqueue);

    dbg_info->work_resetting = dra->status.work_resetting;
    dbg_info->work_start = dra->status.work_start;
    dbg_info->work_end = dra->status.work_end;
    dbg_info->refill_succ = dra->status.refill_succ;
    dbg_info->sche_cnt = dra->status.sche_cnt;
    dbg_info->mem_protect = dra->status.mem_protect;
    dbg_info->map_invalid_level = dra->status.map_invalid_level;
    dbg_info->unmap_invalid_level = dra->status.unmap_invalid_level;

    for (i = 0; i < DRA_ALLOC_REPORT_CNT; i++) {
        unsigned int level = g_dra_alloc_report_level[i];
        (void)memcpy_s(&dbg_info->alloc[i], sizeof(dbg_info->alloc[i]), &dra->cpu_ipipes[level].debug, sizeof(dra->cpu_ipipes[level].debug));
    }

    for (i = 0; i < sizeof(g_dra_report_level) / sizeof(int); i++) {
        level = g_dra_report_level[i];
        dbg_info->opipe_dbg[level].skb_alloc_success = dra->opipe_status[level].alloc_success;
        dbg_info->opipe_dbg[level].skb_own_free = dra->opipe_status[level].skb_own_free;
        dbg_info->opipe_dbg[level].map_own_success = dra->opipe_status[level].map_own_success;
        dbg_info->opipe_dbg[level].map_own_fail = dra->opipe_status[level].map_own_fail;
        dbg_info->opipe_dbg[level].alloc_map_own_fail = dra->opipe_status[level].alloc_map_own_fail;
        dbg_info->opipe_dbg[level].free_list_empty = dra->opipe_status[level].free_list_empty;
        dbg_info->opipe_dbg[level].skb_alloc_fail = dra->opipe_status[level].alloc_fail;
        dbg_info->opipe_dbg[level].unmap_own = dra->opipe_status[level].unmap_own;
        dbg_info->opipe_dbg[level].map_fail_skb_free = dra->opipe_status[level].map_fail_skb_free;
        if (level == DRA_OPIPE_LEVEL_1 || level == DRA_OPIPE_LEVEL_8) {
            dbg_info->opipe_dbg[level].map_tcp_ip_ok = dra->opipes[level].busy_depth;

            dbg_info->opipe_dbg[level].map_tcp_ip_fail = atomic_read(&dra->opipe_status[level].unmap_reuse);
            dbg_info->opipe_dbg[level].unmap_tcp_ip = dra->opipes[level].page_unreuse;
            dbg_info->opipe_dbg[level].unmap_test_tcp_ip = kfifo_len(&dra->opipes[level].reuse_fifo);
        } else {
            dbg_info->opipe_dbg[level].map_tcp_ip_ok = dra->opipe_status[level].map_tcp_ip_ok;
            dbg_info->opipe_dbg[level].map_tcp_ip_fail = dra->opipe_status[level].map_tcp_ip_fail;
            dbg_info->opipe_dbg[level].unmap_tcp_ip = dra->opipe_status[level].unmap_tcp_ip;
            dbg_info->opipe_dbg[level].unmap_test_tcp_ip = dra->opipe_status[level].unmap_test_tcp_ip;
        }
        dbg_info->opipe_dbg[level].delay_free_cnt = dra->opipes[level].delay_free_cnt;
        dbg_info->opipe_dbg[level].reclaim_cnt = dra->opipes[level].reclaim_cnt;
        dbg_info->opipe_dbg[level].max_alloc_cnt = dra->opipes[level].max_alloc_cnt;
        dbg_info->opipe_dbg[level].min_alloc_cnt = dra->opipes[level].min_alloc_cnt;
        dbg_info->opipe_dbg[level].free = dra->opipe_status[level].free;
        dbg_info->opipe_dbg[level].free_to_kernel = dra->opipe_status[level].free_to_kernel;
        dbg_info->opipe_dbg[level].reclaim_depth = dra->opipes[level].reclaim_depth;
    }
}
EXPORT_SYMBOL(dra_hds_transreport);

int dra_get_om_info(char **buf, unsigned int *size)
{
    *buf = (char *)&g_dra_ctx->hds_debug_info;
    *size = sizeof(g_dra_ctx->hds_debug_info);
    return 0;
}
EXPORT_SYMBOL(dra_get_om_info);

int dra_sys_mem_protect(struct dra *dra)
{
    long avail;
    if (dra->protect_thresh) {
        avail = DRA_CURRETN_AVAIL_MEM;
        if (avail < dra->protect_thresh) {
            dra->status.mem_protect++;
            return 0;
        }
    }
    return 1;
}

static inline struct dra_allc_para *dra_get_alloc_para(struct dra *dra, enum dra_ipipe_idx ipipe_id)
{
    unsigned int i;
    for (i = 0; i < dra->allc_para_size; i++) {
        if (dra->allc_para[i].ipipe_id == ipipe_id && dra->allc_para[i].idx != DRA_ALLOC_PARA_MAGIC) {
            return &dra->allc_para[i];
        }
    }
    dra_err("dra_get_ipipe_level not support:%d\n", ipipe_id);
    return NULL;
}

static inline struct dra_rls_para *dra_get_rls_para(struct dra *dra, enum dra_rls_idx rls_id)
{
    unsigned int i;
    for (i = 0; i < dra->rls_para_size; i++) {
        if (dra->rls_para[i].rls_id == rls_id && dra->rls_para[i].idx != DRA_ALLOC_PARA_MAGIC) {
            return &dra->rls_para[i];
        }
    }
    dra_err("dra_get_rls_level not support:%d\n", rls_id);
    return NULL;
}

unsigned int dra_set_adqbase(struct dra *dra, unsigned long long adqbase, unsigned int update_ptr, unsigned int depth,
    unsigned int id)
{
    struct dra_allc_para *alloc_para = NULL;

    alloc_para = dra_get_alloc_para(dra, id);
    if (alloc_para == NULL) {
        return 0;
    }

    if (!dra_opipe_is_enable(dra, alloc_para->level)) {
        return 0;
    }

    return dra_hal_set_adq(dra, alloc_para->level, adqbase, update_ptr, depth, alloc_para->idx);
}

unsigned int dra_set_rlsbase(struct dra *dra, unsigned long long rlsbase, unsigned int update_ptr, unsigned int depth,
    unsigned int id)
{
    struct dra_rls_para *rls_para = NULL;

    rls_para = dra_get_rls_para(dra, id);
    if (rls_para == NULL) {
        return 0;
    }

    if (!dra_opipe_is_enable(dra, rls_para->level)) {
        return 0;
    }

    return dra_hal_set_rls(dra, rlsbase, update_ptr, depth, rls_para);
}

int dra_enable_alloc(struct dra *dra, unsigned int idx, int enable)
{
    struct dra_allc_para *alloc_para = NULL;

    alloc_para = dra_get_alloc_para(dra, idx);
    if (alloc_para == NULL) {
        return -1;
    }

    return dra_enable_alloc_ch(dra, alloc_para->idx, enable);
}

int dra_enable_rls(struct dra *dra, unsigned int idx, int enable)
{
    struct dra_rls_para *rls_para = NULL;

    rls_para = dra_get_rls_para(dra, idx);
    if (rls_para == NULL) {
        return -1;
    }

    return dra_enable_rls_ch(dra, rls_para->idx, enable);
}

int dra_rls_chn_init(struct dra *dra, unsigned int level)
{
    struct dra_fifo *fifo = NULL;

    spin_lock_init(&dra->rls_opipes[level].lock);
    fifo = &dra->rls_opipes[level].fifo;
    fifo->depth = dra->para->rls_chn_depth[level];
    dra->rls_opipes[level].idx = dra->para->rls_chn_idx[level];

    fifo->base = dra->virt_base + dra->offset;
    fifo->phy = dra->dma_base + dra->offset;
    dra->offset += fifo->depth * sizeof(dra_buf_t);

    fifo->update_read_virt = dra->virt_base + dra->offset;
    fifo->update_read_addr = dra->dma_base + dra->offset;
    dra->offset += sizeof(unsigned long long);

    fifo->dbg_idx = dra->para->rls_chn_dbg_idx[level];
    *(unsigned int *)(uintptr_t)fifo->update_read_virt = 0;
    dra_rls_fifo_init(dra, &dra->rls_opipes[level], level);

    return 0;
}

static int dra_cpu_ipipe_config(struct dra *dra, unsigned int level)
{
    unsigned int idx;
    struct dra_fifo *fifo = NULL;
    idx = dra->para->iparamter.ipipeidx[level];

    if (!dra->para->iparamter.depth[level]) {
        dra_err("ipipe %u depth is zero\n", level);
        return -1;
    }
    spin_lock_init(&dra->cpu_ipipes[level].lock);
    dra->cpu_ipipes[level].idx = idx;
    dra->cpu_ipipes[level].level = level;
    if (DRA_OPIPE_LEVEL_INVALID != g_level_size[dra->cpu_ipipes[level].level]) {
        dra_err("ipipe %u,level %u,using\n", idx, dra->cpu_ipipes[level].level);
    }

    fifo = &dra->cpu_ipipes[level].fifo;
    fifo->depth = dra->para->iparamter.depth[level];

    fifo->base = dra->virt_base + dra->offset;
    fifo->phy = dra->dma_base + dra->offset;
    dra->offset += fifo->depth * sizeof(dra_buf_t);

    fifo->update_write_virt = dra->virt_base + dra->offset;
    fifo->update_write_addr = dra->dma_base + dra->offset;
    dra->offset += sizeof(unsigned long long);

    fifo->empty = 1;
    fifo->size = g_level_size[dra->cpu_ipipes[level].level];
    fifo->uthrl = fifo->depth * 3 / 4; // set uthrl as 3 / 4 depth
    fifo->dthrl = fifo->depth / 2; // set dthrl as 1 / 2 depth
    fifo->dbg_idx = dra->para->iparamter.dbg_idx[level];
    dra_ipipe_init(dra, &dra->cpu_ipipes[level], idx);
    return 0;
}

static unsigned int dra_local_fifo_input(struct dra *dra, struct dra_ipipe *ipipe)
{
    struct dra_fifo *fifo = &ipipe->fifo;
    unsigned int busy_num;
    int ret;

    fifo->write = *(unsigned int *)(uintptr_t)fifo->update_write_virt;
    busy_num = dra_get_busy_num(fifo->write, fifo->read, fifo->depth);
    if (busy_num < DRA_BURST_LEN) {
        ipipe->debug.ipipe_empty++;
        return 0;
    }
    ret = memcpy_s((void *)fifo->local_buf, sizeof(fifo->local_buf),
        (dra_buf_t *)(uintptr_t)fifo->base + fifo->read, DRA_BURST_LEN * sizeof(dra_buf_t));
    if (ret) {
        dra_err("memcpy_s failed\n");
        return 0;
    }

    fifo->read += DRA_BURST_LEN;
    if (fifo->read >= fifo->depth) {
        fifo->read = 0;
    }
    dra_ipipe_read_update(dra, fifo->read, ipipe->idx);

    return DRA_BURST_LEN;
}

static unsigned long long dra_ipipe_get_buf(struct dra *dra, struct dra_ipipe *ipipe)
{
    unsigned long flags;
    unsigned long long buf = 0;
    struct dra_fifo *fifo = &ipipe->fifo;
    int ret;

    spin_lock_irqsave(&ipipe->lock, flags);
    if (fifo->idx == DRA_BURST_LEN || fifo->empty) {
        ret = dra_local_fifo_input(dra, ipipe);
        if (ret == DRA_BURST_LEN) {
            fifo->empty = 0;
        } else {
            fifo->empty = 1;
        }
        fifo->idx = 0;
    }

    if (!fifo->empty) {
        buf = fifo->local_buf[fifo->idx];
        fifo->idx++;
        ipipe->debug.alloc++;
    }
    if (buf != 0 && ipipe->level == DRA_OPIPE_LEVEL_9) {
        dra_shm_set_flag((dra_buf_t)buf, DRA_UNMAP);
    }

    spin_unlock_irqrestore(&ipipe->lock, flags);
    return buf;
}

unsigned long long dra_ipipe_alloc(unsigned int size)
{
    unsigned int level;
    dra_buf_t buf;
    struct dra_ipipe *ipipe = NULL;
    struct dra *dra = g_dra_ctx;

    level = dra_len_to_levels(size);
    if (level == DRA_OPIPE_LEVEL_INVALID) {
        return 0;
    }

    ipipe = &dra->cpu_ipipes[level];
    if (!ipipe->fifo.update_write_virt || !ipipe->fifo.base) {
        return 0;
    }

    buf.addr = dra_ipipe_get_buf(dra, ipipe);

    return buf.addr;
}

int dra_tab_is_empty(struct dra *dra, unsigned int level)
{
    struct dra_map *map = NULL;

    if (unlikely(!dra_opipe_is_enable(dra, level))) {
        dra_err("invalid level\n");
        dra->status.map_invalid_level++;
        return -1;
    }

    map = &dra->opipes[level].map;

    if (list_empty(&map->free_list)) {
        dra->opipe_status[level].free_list_empty++;
        return 1;
    }

    return 0;
}

static unsigned long long dra_create_desc(struct dra *dra, unsigned long long phyaddr, unsigned int idx,
    unsigned int level, unsigned int from)
{
    dra_buf_t buf;
    unsigned int bitcnt;

    buf.addr = 0;
    buf.bits.phyaddr = phyaddr;
    buf.bits.sc_mode = dra->para->sc_mode;
    buf.bits.idx = idx;
    buf.bits.from = from;
    buf.bits.level = level;
    buf.bits.crc = 0;
    bitcnt = __sw_hweight64(buf.addr);
    if (bitcnt & 1) {
        buf.bits.crc = 1;
    }

    return buf.addr;
}

unsigned long long dra_map_single(struct dra *dra, unsigned long long phy, void *manager, int from,
    unsigned int level, unsigned int magic)
{
    struct dra_map *map = NULL;
    struct dra_tab *tab = NULL;
    dra_buf_t buf;
    unsigned long flags;

    if (unlikely(!dra_opipe_is_enable(dra, level))) {
        dra_err("invalid level\n");
        dra->status.map_invalid_level++;
        return 0;
    }
    map = &dra->opipes[level].map;
    spin_lock_irqsave(&dra->opipes[level].lock, flags);
    if (unlikely(list_empty(&map->free_list))) {
        dra->opipe_status[level].free_list_empty++;
        spin_unlock_irqrestore(&dra->opipes[level].lock, flags);
        return 0;
    }

    tab = list_first_entry(&map->free_list, struct dra_tab, list);
    map->free--;
    tab->manager = manager;
    tab->magic = magic;
    buf.addr = dra_create_desc(dra, phy, tab->idx, level, from);
    tab->dra_addr = buf.addr;
    map->busy++;
    list_move_tail(&tab->list, &map->busy_list);
    dra->opipes[level].busy_depth++;
    spin_unlock_irqrestore(&dra->opipes[level].lock, flags);

    return buf.addr;
}

int dra_unmap_single(struct dra *dra, dra_buf_t *dra_buf, void **pmanger, unsigned int *pmagic)
{
    unsigned long flags;
    unsigned level;
    struct dra_tab *tab = NULL;
    struct dra_opipe *opipe = NULL;
    struct dra_map *map = NULL;

    if (dra == NULL || dra_buf == NULL) {
        return -1;
    }
    tab = dra_get_tab(dra, *dra_buf);
    if (unlikely(tab == NULL)) {
        return -1;
    }

    level = dra_buf->bits.level;
    map = &dra->opipes[level].map;
    opipe = &dra->opipes[level];

    spin_lock_irqsave(&opipe->lock, flags);
    list_del(&tab->list);
    map->busy--;
    opipe->busy_depth--;
    if (pmanger) {
        *pmanger = tab->manager;
    }
    if (pmagic) {
        *pmagic = tab->magic;
    }
    tab->magic = DRA_FREE;
    list_add_tail(&tab->list, &map->free_list);
    map->free++;
    spin_unlock_irqrestore(&opipe->lock, flags);

    return 0;
}

struct sk_buff *dra_list_del(struct dra *dra, dra_buf_t buf, dra_buf_t *p)
{
    struct dra_opipe *opipe = NULL;
    struct sk_buff *skb = NULL;
    unsigned int level = buf.bits.level;
    unsigned int idx = buf.bits.idx;
    unsigned long flags;
    struct dra_tab *tab = NULL;

    tab = dra_get_tab(dra, buf);
    if (unlikely(tab == NULL)) {
        dra->opipe_status[level].unmap_own_fail++;
        return NULL;
    }

    opipe = &dra->opipes[level];
    spin_lock_irqsave(&opipe->lock, flags);
    list_del(&tab->list);
    opipe->busy_depth--;
    tab->magic = DRA_FREE;
    kfifo_in(&opipe->idx_fifo, &idx, 1);
    dra->opipe_status[level].unmap_own++;
    spin_unlock_irqrestore(&opipe->lock, flags);

    p->addr = tab->dra_addr;
    skb = (struct sk_buff *)tab->manager;

    return skb;
}

static inline void dra_buf_cache_flush(struct dra *dra, dra_buf_t buf, unsigned int size)
{
    buf.addr = buf.addr & DRA_ADDR_MASK;
    bsp_dpa_sc_dma_unmap_single(dra->dev, buf.bits.phyaddr, size, DMA_FROM_DEVICE);
    dra->opipe_status[buf.bits.level].unmap_cache_flush++;
}

/* 回收9k内存处理 涉及该流程的函数修改注意该流程 */
static inline void dra_recycle_mem(struct dra *dra, dra_buf_t buf)
{
    struct dra_opipe *opipe = NULL;
    struct dra_tab *tab = NULL;

    tab = dra_get_tab(dra, buf);
    if (tab == NULL) {
        return;
    }

    opipe = &dra->opipes[buf.bits.level];
    dra->opipe_status[buf.bits.level].free++;
    dra_input(dra, tab->dra_addr, opipe);
}

static struct sk_buff *__dra_unmap_skb(struct dra *dra, dra_buf_t buf, unsigned long long *orig_addr)
{
    struct sk_buff *skb = NULL;
    dra_buf_t true_addr;

    skb = dra_list_del(dra, buf, &true_addr);
    if (skb == NULL) {
        return NULL;
    }

    if (orig_addr != NULL) {
        *orig_addr = true_addr.addr;
    }
    return skb;
}

static struct sk_buff* __dra_alloc_skb(struct dra *dra, unsigned int level, unsigned int data_size, gfp_t gfp)
{
    struct sk_buff *skb = NULL;
    char *buff = NULL;
    unsigned int len = g_level_size[level];
    int ret;

    buff = (char *)kmalloc(len, gfp);
    if (unlikely(buff == NULL)) {
        return NULL;
    }

    skb = (struct sk_buff *)(buff + DRA_SKB_OFFSET(len));
    ret = memset_s((void *)skb, sizeof(*skb), 0, sizeof(struct sk_buff));
    if (ret != EOK) {
        dra_err("mem set fail:%d\n", ret);
        kfree(buff);
        return NULL;
    }
    skb->head = buff;
    skb->data = buff;
    skb_reset_tail_pointer(skb);
    skb->end = DRA_SKB_RESERVE_SIZE + data_size;
    dra->opipe_status[level].alloc_success++;

    return skb;
}

unsigned long long dra_alloc_skb(struct dra *dra, struct dra_opipe *opipe, gfp_t gfp)
{
    struct sk_buff *skb = NULL;
    struct dra_tab *tab = NULL;
    unsigned long long addr;
    unsigned int level = opipe->level;
    unsigned int head_rom = DRA_SKB_RESERVE_SIZE;
    unsigned int data_size = g_level_data_size[level];
    unsigned int offset;
    unsigned long flags;

    if (dra_list_is_full(dra, level)) {
        dra->opipe_status[level].map_own_fail++;
        return 0;
    }

    skb = __dra_alloc_skb(dra, level, data_size, gfp);
    if (unlikely(skb == NULL)) {
        dra->opipe_status[level].alloc_fail++;
        dra_err("skb == NULL\n");
        return 0;
    }

    offset = DRA_SKB_OFFSET(g_level_size[level]);
    addr = dra_create_desc(dra, virt_to_phys(skb->data) + head_rom, offset, level, DRA_SKB_FROM_OWN);

    (void)bsp_dpa_sc_dma_map_single(dra->dev, skb->head, head_rom + data_size, DMA_FROM_DEVICE);
    skb_reserve(skb, head_rom);
    dra->opipe_status[level].map_own_success++;

    tab = (struct dra_tab *)DRA_BUF_TO_TAB(skb->head, g_level_size[level]);
    tab->dra_addr = addr;
    tab->magic = DRA_OWN;
    tab->manager = skb;

    spin_lock_irqsave(&opipe->lock, flags);
    list_add_tail(&tab->list, &opipe->map.busy_list);
    opipe->busy_depth++;
    spin_unlock_irqrestore(&opipe->lock, flags);
    return addr;
}

static int dpa_shm_init(struct dra *dra)
{
    struct shm_ctx *shm = &dra->shm;
    shm->size = dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_9];
    dra_err("cma shm size:%u\n", (unsigned int)shm->size);
    shm->index = 0;
    /* bsp_dpa_cma_cache_alloc的到的CMA内存已经进行了SC映射,此内存用于LV9 DMI-BUF */
    shm->mem = bsp_dpa_cma_cache_alloc(shm->size * sizeof(struct shm_blk), &shm->phys, GFP_KERNEL);
    if (shm->mem  == NULL) {
        dra_err("dpa_shm_init failed\n");
        return -1;
    }

    return 0;
}

static char *dpa_shm_get_blk(struct dra *dra, dma_addr_t *addr)
{
    struct shm_ctx *shm = &dra->shm;

    if (shm->index >= shm->size) {
        return NULL;
    }

    struct shm_blk *blk = (struct shm_blk *)shm->mem;
    *addr = shm->phys + shm->index * sizeof(struct shm_blk);
    return (char *)&blk[shm->index++];
}

unsigned long long dra_alloc_mem(struct dra *dra, struct dra_opipe *opipe, gfp_t gfp)
{
    struct dra_shm_info *shm_info;
    struct dra_map *map = &opipe->map;
    struct dra_tab *tab = NULL;
    dma_addr_t phys, ori_phys;
    unsigned long long addr;
    unsigned int level = opipe->level;
    unsigned long flags;

    if (dra_list_is_full(dra, level)) {
        dra->opipe_status[level].map_own_fail++;
        return 0;
    }

    shm_info = (struct dra_shm_info *)dpa_shm_get_blk(dra, &ori_phys);
    if (unlikely(shm_info == NULL)) {
        dra->opipe_status[level].alloc_fail++;
        dra_err("local_alloc failed\n");
        return 0;
    }

    phys = ori_phys + sizeof(struct dra_shm_info);

    spin_lock_irqsave(&opipe->lock, flags);
    if (unlikely(list_empty(&map->free_list))) {
        dra->opipe_status[level].free_list_empty++;
        spin_unlock_irqrestore(&opipe->lock, flags);
        return 0;
    }

    tab = list_first_entry(&map->free_list, struct dra_tab, list);
    map->free--;

    addr = dra_create_desc(dra, phys, tab->idx, level, DRA_SKB_FROM_OWN);
    shm_info->buf.addr = addr;
    shm_info->magic = DRA_OWN;
    bsp_dpa_sc_dma_map_single(dra->dev, shm_info, sizeof(struct shm_blk), DMA_TO_DEVICE);
    tab->dra_addr = addr;
    tab->manager = shm_info->data;
    tab->magic = DRA_OWN;
    map->busy++;
    list_move_tail(&tab->list, &map->busy_list);
    opipe->busy_depth++;
    dra->opipe_status[level].map_own_success++;
    spin_unlock_irqrestore(&opipe->lock, flags);
    return addr;
}

static inline struct sk_buff* dra_gen_page_skb(struct dra *dra, char *buff, unsigned int level, unsigned int data_size)
{
    struct sk_buff *skb = NULL;
    unsigned int len = g_level_size[level];

    skb = (struct sk_buff *)(buff + DRA_SKB_OFFSET(len));
    (void)memset_s((void *)skb, sizeof(*skb), 0, sizeof(struct sk_buff));
    skb->head = buff;
    skb->data = buff;
    skb_reset_tail_pointer(skb);
    skb->end = DRA_SKB_RESERVE_SIZE + data_size;
    skb_reserve(skb, DRA_SKB_RESERVE_SIZE);

    return skb;
}

unsigned long long dra_alloc_skb_list(struct dra *dra, char *buff, struct dra_opipe *opipe)
{
    struct sk_buff *skb = NULL;
    struct dra_tab *tab = NULL;
    unsigned long long addr;
    unsigned int level = opipe->level;
    unsigned int head_rom = DRA_SKB_RESERVE_SIZE;
    unsigned int data_size = g_level_data_size[level];
    unsigned int idx;
    int ret;

    skb = dra_gen_page_skb(dra, buff, level, data_size);
    ret = kfifo_out(&opipe->idx_fifo, &idx, 1);
    if (ret == 0) {
        dra_err("idx fifo enpty:%d\n", level);
    }
    addr = dra_create_desc(dra, virt_to_phys(skb->head) + head_rom, idx, level, DRA_SKB_FROM_OWN);
    dra->opipe_status[level].map_own_success++;
    dra->opipe_status[level].alloc_success++;

    tab = (struct dra_tab *)(skb->head + g_level_size[level] - sizeof(struct dra_tab));
    tab->dra_addr = addr;
    tab->magic = DRA_OWN;
    tab->manager = skb;

    list_add_tail(&tab->list, &opipe->local_list);
    return addr;
}
EXPORT_SYMBOL(dra_alloc_skb_list);

void _dra_alloc_page_skb(struct dra *dra, struct dra_opipe *opipe, struct dra_fifo *fifo, unsigned long long page_virt)
{
    unsigned j;
    unsigned long long buf;
    unsigned long flags;
    struct page *page = NULL;
    char *buff = NULL;


    buff = (char *)(uintptr_t)page_virt;
    page = (struct page *)virt_to_page(buff);
    page_ref_add(page, DRA_PAGE_INIT_REF_CNT_HALF(0) + DRA_PAGE_INIT_REF_CNT_HALF(1));

    (void)bsp_dpa_sc_dma_map_single(dra->dev, (void *)buff, PAGE_SIZE, DMA_TO_DEVICE);
    for (j = 0; j < 2; j++) {
        buf = dra_alloc_skb_list(dra, buff + j * 2048, opipe);
        fifo->local_buf[fifo->idx++] = buf;
        spin_lock_irqsave(&opipe->lock, flags);
        if (opipe->wlan_dev != NULL) {
            dra_map_smmu(dra, opipe->wlan_dev, (dra_buf_t*)&buf, 1);
        }
        spin_unlock_irqrestore(&opipe->lock, flags);

        if (fifo->idx == DRA_BURST_LEN) {
            fifo->idx = 0;
            spin_lock_irqsave(&opipe->lock, flags);
            list_splice_tail_init(&opipe->local_list, &opipe->map.busy_list);
            spin_unlock_irqrestore(&opipe->lock, flags);
            dra_bigpool_input_batch(dra, opipe);
        }
    }
    return;
}

unsigned int dra_alloc_page_skb(struct dra *dra, struct dra_opipe *opipe, struct dra_fifo *fifo, unsigned int cnt)
{
    unsigned long flags;
    unsigned int free_cnt, fill_cnt;
    unsigned long long page_virt;
    unsigned int level = opipe->level;
    unsigned int i;

    if (dra_list_is_full(dra, level)) {
        dra->opipe_status[level].map_own_fail++;
        return 0;
    }

    free_cnt =  dra->para->oparamter.tab_size[level] - opipe->busy_depth - opipe->reclaim_depth;
    fill_cnt = min(cnt, free_cnt);
    fill_cnt = fill_cnt & (~1);

    for (i = 0; i < fill_cnt; i += 2) {
        if (test_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event)) {
            // 防止fill_cnt过大时，恰好发生单独复位，处理完成这么多的fill花费的时间太长,所以需要尽快返回
            break;
        }
        page_virt = __get_free_page(GFP_KERNEL);
        if (unlikely(!page_virt)) {
            dra->opipe_status[level].alloc_fail++;
            break;
        }
        if (test_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event)) {
            dra_err("__get_free_page when dpa in resetting.\n");
            free_page(page_virt);
            break;
        }
        _dra_alloc_page_skb(dra, opipe, fifo, page_virt);
    }

    spin_lock_irqsave(&opipe->lock, flags);
    opipe->busy_depth += i;
    list_splice_tail_init(&opipe->local_list, &opipe->map.busy_list);
    spin_unlock_irqrestore(&opipe->lock, flags);

    return i;
}

void dra_free_half_page(struct dra *dra, dra_buf_t buf, struct page *page, unsigned int ref_cnt)
{
    struct sk_buff *skb = NULL;
    unsigned int j;

    j = DRA_FIRST_OR_SECOND_2K(buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE);
    page_ref_sub(page, DRA_PAGE_BASE_REF_CNT_HLAF(j));

    skb = __dra_unmap_skb(dra, buf, NULL);
    if (skb != NULL && skb->head != NULL) {
        dra_buf_cache_flush(dra, buf, DRA_SKB_RESERVE_SIZE + g_level_data_size[buf.bits.level]);
        /* 只有当另一半释放后才能把page释放 */
        if (!((ref_cnt & DRA_PAGE_BASE_REFCOUNT) == DRA_PAGE_BASE_REFCOUNT)) {
            dra->opipe_status[buf.bits.level].put_page++;
            dra_unmap_smmu(dra, buf);
            dra_dbg("dra put page ref:0x%x\n", page_ref_count(page));
            put_page(page);
        }
    } else {
        dra_err("skb null\n");
    }
}

unsigned int dra_reuse_page(struct dra *dra, struct dra_fifo *fifo, struct dra_opipe *opipe, unsigned int cnt)
{
    unsigned int i = 0;
    dra_buf_t buf;
    unsigned int j, k = 0, ref_cnt;
    struct page *page = NULL;
    char *buff = NULL;
    int ret, free;
    unsigned int fifo_cnt = kfifo_len(&opipe->reuse_fifo);
    struct dra_tab *tab = NULL;

    free = opipe->busy_depth > opipe->map.tab_max_size - 0x400;
    do {
        if (i == cnt || k == fifo_cnt) {
            break;
        }
        ret = kfifo_out(&opipe->reuse_fifo, &buf.addr, 1);
        if (ret == 0) {
            opipe->kfifo_empty++;
            break;
        }

        k++;
        page = phys_to_page(buf.bits.phyaddr);
        ref_cnt = page_ref_count(page);
        if ((ref_cnt & (~(DRA_PAGE_BASE_REFCOUNT | DRA_PAGE_OWN_REFCOUNT | DRA_DYNAMIC_REF_CNT_MASK))) != 0) {
            dra->opipe_status[1].refcnt_err++;
        }

        tab = (struct dra_tab *)DRA_BUF_TO_TAB(dra_check_own_buf(dra, buf), g_level_size[buf.bits.level]);

        if (DRA_PAGE_ALL_FREE_BY_KERNEL(ref_cnt) /*two packet has been recyle to maa*/
            || DRA_PAGE_ONE_FREE_BY_KERNEL(ref_cnt)) {/*only one packet netif_rx to tcp/ip, and has been recyle to maa*/

            tab->magic = DRA_OWN;

            j = DRA_FIRST_OR_SECOND_2K(buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE);
            if (!(ref_cnt & DRA_PAGE_OWN_REF_CNT_HLAF(j))) { // 当前这一半引用计数已经有了就不加了
                page_ref_add(page, DRA_PAGE_OWN_REF_CNT_HLAF(j) | 0x1);
            }

            buff = phys_to_virt(buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE);
            (void)dra_gen_page_skb(dra, buff, DRA_OPIPE_LEVEL_1, DRA_OPIPE_LEVEL_1_SIZE);

            //内核可能修改data 需要保证cache一致性
            (void)bsp_dpa_sc_dma_map_single(dra->dev, (void *)buff, DRA_SKB_RESERVE_SIZE + DRA_OPIPE_LEVEL_1_SIZE, DMA_TO_DEVICE);
            fifo->local_buf[fifo->idx++] = buf.addr;
            if (fifo->idx == DRA_BURST_LEN) {
                fifo->idx = 0;
                dra_bigpool_input_batch(dra, opipe);
            }
            i++;
        } else if ((ref_cnt & DRA_PAGE_OWN_REFCOUNT) == DRA_PAGE_OWN_REFCOUNT) {
            tab->magic = DRA_OWN;
            dra_bigpool_input(dra, buf.addr, opipe);
            i++;
        } else {
            opipe->page_unreuse++;
            /* 两块内存都进入reuse队列后才触发unreuse释放回内核，保证只在该任务中判断refcnt后释放page */
            if (free && ((ref_cnt & DRA_PAGE_OWN_REFCOUNT) == 0)) {
                dra_free_half_page(dra, buf, page, ref_cnt);
            } else {
                kfifo_in_spinlocked(&opipe->reuse_fifo, &buf.addr, 1, &dra->lock);
            }
        }
    } while (1);

    return i;
}

void dra_free_one_buf(struct dra *dra, dra_buf_t buf, struct page *page, unsigned int free)
{
    struct sk_buff *skb = NULL;

    skb = __dra_unmap_skb(dra, buf, NULL);
    if (skb != NULL && skb->head != NULL) {
        dra_buf_cache_flush(dra, buf, DRA_SKB_RESERVE_SIZE + g_level_data_size[buf.bits.level]);
        if (free && ((page_ref_count(page) & (DRA_PAGE_BASE_SMMU - 1)) == 1)) {
            dra->opipe_status[buf.bits.level].free_page++;
            dra_unmap_smmu(dra, buf);
            dra_dbg("dra free page ref:0x%x\n", page_ref_count(page));
            free_page((unsigned long)skb->head);
        }
    } else {
        dra_err("skb null\n");
    }
}

void dra_free_to_kernel(struct dra *dra, unsigned int level)
{
    struct dra_opipe *opipe = NULL;
    struct dra_ipipe *ipipe = NULL;
    dra_buf_t dra_buf;
    int i, j, cnt;
    struct page *page = NULL;
    unsigned int ref_cnt, free;

    ipipe = &dra->cpu_ipipes[level];
    opipe = &dra->opipes[level];
    if (opipe->busy_depth > (dra->ddr_buf[level].fifo.dthrl + 0x1000)) {
        cnt = opipe->busy_depth - dra->ddr_buf[level].fifo.dthrl - 0x1000;
    } else {
        return;
    }

    for (i = 0; i < cnt; i++) {
        dra_buf.addr = dra_ipipe_get_buf(dra, ipipe);
        if (dra_buf.addr == 0) {
            continue;
        }

        page = phys_to_page(dra_buf.bits.phyaddr);
        j = DRA_FIRST_OR_SECOND_2K(dra_buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE);
        ref_cnt = page_ref_count(page);
        /* 只有当另一半释放后才能把page释放 */
        if ((ref_cnt & DRA_PAGE_BASE_REFCOUNT) == DRA_PAGE_BASE_REFCOUNT) {
            free = 0;
        } else {
            free = 1;
        }
        page_ref_sub(page, DRA_PAGE_BASE_REF_CNT_HLAF(j) | DRA_PAGE_OWN_REF_CNT_HLAF(j) | 1);
        dra_free_one_buf(dra, dra_buf, page, free);
        dra->opipe_status[level].free_to_kernel++;
        dra->opipe_status[level].skb_own_free++;
    }
}

static inline struct sk_buff *dra_build_skb(char *buff)
{
    struct sk_buff *skb_new = NULL;

    skb_new = build_skb((void *)buff, DRA_OPIPE_LEVEL_1_SIZE + DRA_SKB_RESERVE_SIZE + SKB_DATA_ALIGN(sizeof(struct skb_shared_info)));
    if (skb_new == NULL) {
        return NULL;
    }
    skb_reserve(skb_new, DRA_SKB_RESERVE_SIZE);

    return skb_new;
}

void dra_clear_tab_info(struct dra *dra, dra_buf_t buf)
{
    struct dra_tab_info *tab_info = NULL;
    unsigned long flags;

    if (buf.bits.level == DRA_OPIPE_LEVEL_8 && buf.bits.idx < dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_8]) {
        tab_info = dra->tab_info_level8;
        spin_lock_irqsave(&dra->opipes[buf.bits.level].lock, flags);
        tab_info[buf.bits.idx].buf = 0;
        spin_unlock_irqrestore(&dra->opipes[buf.bits.level].lock, flags);
    } else if (buf.bits.level == DRA_OPIPE_LEVEL_1 && buf.bits.idx < dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_1]) {
        tab_info = dra->tab_info_level1;
        spin_lock_irqsave(&dra->opipes[buf.bits.level].lock, flags);
        tab_info[buf.bits.idx].buf = 0;
        spin_unlock_irqrestore(&dra->opipes[buf.bits.level].lock, flags);
    } else {
        dra_err("clear buf err:0x%llx\n", buf.addr);
    }
}

struct sk_buff *dra_unmap_skb(struct dra *dra, dra_buf_t buf, unsigned long long *orig, unsigned int reuse)
{
    struct sk_buff *skb_new = NULL;
    unsigned int i;
    struct page *page = NULL;
    unsigned int refcount;
    struct dra_tab *tab = NULL;

    if (unlikely(buf.bits.level == DRA_OPIPE_LEVEL_3)) {
        dra_recycle_mem(dra, buf);
        dra_err("used ap 9k\n");
        return NULL;
    }

    buf.addr = buf.addr & DRA_ADDR_MASK;//2K align
    page = (struct page *)phys_to_page(buf.bits.phyaddr);
    i = DRA_FIRST_OR_SECOND_2K(buf.bits.phyaddr);

    buf.addr += DRA_SKB_RESERVE_SIZE;
    tab = dra_get_tab(dra, buf);
    if (unlikely(tab == NULL || tab->magic == DRA_UNMAP)) {
        dra->opipe_status[1].unmap_own_fail++;
        dra_err("dra magic err:0x%llx\n", buf.addr);
        return NULL;
    }

    page_ref_sub(page, DRA_PAGE_OWN_REF_CNT_HLAF(i));
    refcount = page_ref_count(page);
    /* 当另一半释放后减去base和dra引用计数 让内核回收page */
    if ((refcount & DRA_PAGE_BASE_REFCOUNT) != DRA_PAGE_BASE_REFCOUNT) {
        page_ref_sub(page, DRA_PAGE_BASE_REF_CNT_HLAF(i) | 0x1);
        dra_dbg("page ref:%d addr:0x%llx\n", page_ref_count(page), buf.addr);
        skb_new = __dra_unmap_skb(dra, buf, NULL);
        if (skb_new == NULL) {
            return NULL;
        }
        dra_unmap_smmu(dra, buf);
        dra_dbg("dra unmap page ref:0x%x\n", page_ref_count(page));
    } else {
        // unmap释放到回收队列
        kfifo_in_spinlocked(&dra->opipes[buf.bits.level].reuse_fifo, &buf.addr, 1, &dra->lock);
        atomic_inc(&dra->opipe_status[buf.bits.level].unmap_reuse);
        tab->magic = DRA_UNMAP;
    }
    if (reuse) {
        skb_new = (struct sk_buff *)tab->manager;
        bsp_dra_reset_skb(skb_new);
    } else {
        skb_new = dra_build_skb((char *)phys_to_virt(buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE));
    }
    if (unlikely(skb_new == NULL)) {
        bsp_info("build skb fail\n");
        return NULL;
    }

    if (orig) {
        *orig = buf.addr;
    }

    dra_clear_tab_info(dra, buf);

    return skb_new;
}

void dra_free_kernel_test(unsigned int level, unsigned int cnt)
{
    struct dra *dra = g_dra_ctx;
    struct dra_ipipe *ipipe = NULL;
    dra_buf_t dra_buf;
    int i, j;
    struct page *page = NULL;
    unsigned int ref_cnt, free;

    ipipe = &dra->cpu_ipipes[level];
    for (i = 0; i < cnt; i++) {
        dra_buf.addr = dra_ipipe_get_buf(dra, ipipe);
        if (dra_buf.addr == 0) {
            continue;
        }
        page = phys_to_page(dra_buf.bits.phyaddr);
        j = DRA_FIRST_OR_SECOND_2K(dra_buf.bits.phyaddr - DRA_SKB_RESERVE_SIZE);
        ref_cnt = page_ref_count(page);
        if ((ref_cnt & DRA_PAGE_BASE_REFCOUNT) == DRA_PAGE_BASE_REFCOUNT) {
            free = 0;
        } else {
            free = 1;
        }
        page_ref_sub(page, DRA_PAGE_BASE_REF_CNT_HLAF(j) | DRA_PAGE_OWN_REF_CNT_HLAF(j) | 1);
        dra_dbg("free:0x%llx page ref:0x%x\n", dra_buf.addr, page_ref_count(page));
        dra_free_one_buf(dra, dra_buf, page, free);
        dra->opipe_status[level].free_to_kernel++;
        dra->opipe_status[level].skb_own_free++;
    }
}


unsigned long long dra_alloc_page(struct dra *dra, struct dra_opipe *opipe, unsigned int level)
{
    unsigned long page;
    u64 phy;
    u64 addr;

    if (dra_tab_is_empty(dra, level)) {
        dra->opipe_status[level].map_own_fail++;
        dra->int_mask &= ~(BIT(level));
        return 0;
    }

    if (level == DRA_OPIPE_LEVEL_7) {
        page = bsp_dpa_sc_alloc_page(dra->para->gid[level], GFP_KERNEL);
    } else {
        page = __get_free_page(GFP_KERNEL);
    }
    if (unlikely(!page)) {
        dra->opipe_status[level].alloc_fail++;
        return 0;
    }
    dra->opipe_status[level].alloc_success++;

    phy = virt_to_phys((void *)(uintptr_t)page);
    addr = dra_map_single(dra, phy, (void *)(uintptr_t)page, DRA_SKB_FROM_OWN, level, DRA_OWN);
    if (unlikely(!addr)) {
        free_page(page);
        dra->opipe_status[level].map_own_fail++;
        return 0;
    }

    (void)bsp_dpa_sc_dma_map_single(dra->dev, (void *)(uintptr_t)page, PAGE_SIZE, DMA_FROM_DEVICE);
    dra->opipe_status[level].map_own_success++;
    return addr;
}

void dra_free_buf(struct dra *dra, dra_buf_t buf)
{
    struct sk_buff *skb = NULL;
    unsigned long flags;

    if (unlikely(buf.bits.level == DRA_OPIPE_LEVEL_3)) {
        dra_recycle_mem(dra, buf);
        bsp_info("used ap 9k\n");
        return;
    }

    if (unlikely(buf.bits.sc_mode != dra->para->sc_mode)) {
        dra_err("dra check sc mode error, 0x%llx\n", buf.addr);
        return;
    }

    if (buf.bits.from == DRA_SKB_FROM_OWN) {
        if (buf.bits.level != DRA_OPIPE_LEVEL_9) {
            buf.addr = (buf.addr & DRA_ADDR_MASK) + DRA_SKB_RESERVE_SIZE;
            if (buf.bits.level == DRA_OPIPE_LEVEL_8) {
                dra_clear_tab_info(dra, buf);
            }
        } else {
            spin_lock_irqsave(&dra->opipes[DRA_OPIPE_LEVEL_9].lock, flags);
            dra_shm_set_flag((dra_buf_t)buf, DRA_OWN);
            spin_unlock_irqrestore(&dra->opipes[DRA_OPIPE_LEVEL_9].lock, flags);
        }

        dra_rls_input(dra, buf.addr, &dra->rls_opipes[buf.bits.level], buf.bits.level);
    } else if (buf.bits.from == DRA_SKB_FROM_TCP_IP) {
        skb = dra_unmap_tcpip_skb(dra, buf);
        if (skb != NULL) {
            dev_kfree_skb_any(skb);
        }
    } else {
        dra_err("dra check dra error, 0x%llx\n", buf.addr);
    }
    return;
}

static unsigned int dra_fill_from_alloc(struct dra *dra, struct dra_opipe *opipe, struct dra_fifo *fifo, unsigned int cnt)
{
    dra_buf_t mbuf;
    unsigned int i = 0;

    if (!dra_sys_mem_protect(dra)) {
        return 0;
    }

    switch (opipe->level) {
        case DRA_OPIPE_LEVEL_1:
        case DRA_OPIPE_LEVEL_8:
            i = dra_alloc_page_skb(dra, opipe, fifo, cnt);
            break;

        case DRA_OPIPE_LEVEL_2:
        case DRA_OPIPE_LEVEL_7:
            for (i = 0; i < cnt; i++) {
                mbuf.addr = dra_alloc_page(dra, opipe, opipe->level);
                if (unlikely(mbuf.addr == 0)) {
                    break;
                }
                dra_bigpool_input(dra, mbuf.addr, opipe);
            }
            break;

        case DRA_OPIPE_LEVEL_3:
            for (i = 0; i < cnt; i++) {
                mbuf.addr = dra_alloc_skb(dra, opipe, GFP_KERNEL);
                if (unlikely(mbuf.addr == 0)) {
                    break;
                }
                dra_bigpool_input(dra, mbuf.addr, opipe);
            }
            break;

        case DRA_OPIPE_LEVEL_9:
            for (i = 0; i < cnt; i++) {
                // use tab, alloc from dpa cma remain for dmi
                mbuf.addr = dra_alloc_mem(dra, opipe, GFP_KERNEL);
                if (unlikely(mbuf.addr == 0)) {
                    break;
                }
                dra_bigpool_input(dra, mbuf.addr, opipe);
            }
            break;
        case DRA_OPIPE_LEVEL_10:
            i = dra_fill_lv10(dra, opipe, cnt);
            break;

        default:
            dra_err("alloc mem level err:%d\n", opipe->level);
    }

    return i;
}

void dra_show_kfifo(unsigned int level)
{
    struct dra *dra = g_dra_ctx;
    struct page *page = NULL;
    dra_buf_t buf;
    int ret;
    unsigned int total = kfifo_len(&dra->opipes[level].reuse_fifo);

    while (total) {
        ret = kfifo_out_spinlocked(&dra->opipes[level].reuse_fifo, &buf.addr, 1, &dra->lock);
        if (ret == sizeof(unsigned long long)) {
            page = phys_to_page(buf.bits.phyaddr & (~DRA_PAGE_MASK));
            dra_err("buf:0x%llx, ref_cnt:0x%x\n", buf.addr, page_ref_count(page));
            ret = kfifo_in_spinlocked(&dra->opipes[level].reuse_fifo, &buf.addr, 1, &dra->lock);
            if (ret != sizeof(unsigned long long)) {
                dra_err("fifo in fail\n");
            }
        } else {
            dra_err("buf zero:%d\n", ret);
        }
        total--;
    }
}

void dra_show_kfifo_len(unsigned int level)
{
    struct dra *dra = g_dra_ctx;

    dra_err("kfifo len:0x%x\n", kfifo_len(&dra->opipes[level].reuse_fifo));
}

unsigned int dra_ref[0x1000][2];
void dra_show(unsigned int level)
{
    struct dra_tab *tab_mtp = NULL;
    struct page *page = NULL;
    dra_buf_t buf;
    unsigned int ref_cnt;
    int i;

    list_for_each_entry (tab_mtp, &g_dra_ctx->opipes[level].map.busy_list, list) {
        buf.addr = tab_mtp->dra_addr;
        page = phys_to_page(buf.bits.phyaddr & (~DRA_PAGE_MASK));
        i = 0;
        for (; i < 0x1000; i++) {
            ref_cnt = page_ref_count(page);
            if (dra_ref[i][0] == ref_cnt) {
                break;
            } else if (dra_ref[i][0] == 0) {
                dra_ref[i][0] = ref_cnt;
                break;
            }
        }
        dra_ref[i][1]++;
    }

    for (i = 0; i < 0x1000; i++) {
        if (dra_ref[i][0] != 0) {
            dra_err("ref_cnt:0x%x, cnt:0x%x\n", dra_ref[i][0], dra_ref[i][1]);
            dra_ref[i][0] = 0;
            dra_ref[i][1] = 0;
        } else {
            break;
        }
    }
}

unsigned int dra_fill_fifo(struct dra *dra, struct dra_fifo *fifo, unsigned int cnt)
{
    struct dra_tab *tab = NULL;
    struct dra_opipe *opipe = container_of(fifo, struct dra_opipe, fifo);
    unsigned long flag;
    unsigned int i = 0;
    unsigned int fill_cnt;

    if (!list_empty(&opipe->map.reclaim_list)) {
        spin_lock_irqsave(&opipe->lock, flag);
        while (unlikely(!list_empty(&opipe->map.reclaim_list) && (i < cnt))) {
            tab = list_first_entry(&opipe->map.reclaim_list, struct dra_tab, list);
            list_move_tail(&tab->list, &opipe->map.busy_list);
            opipe->busy_depth++;
            opipe->reclaim_depth--;
            if (DRA_OPIPE_LEVEL_2 == opipe->level) {
                dra_input(dra, tab->dra_addr, opipe);
            } else {
                dra_bigpool_input(dra, tab->dra_addr, opipe);
            }
            opipe->reclaim_cnt++;
            i++;
        }
        spin_unlock_irqrestore(&opipe->lock, flag);
    }

    if (likely(DRA_OPIPE_LEVEL_1 == opipe->level || DRA_OPIPE_LEVEL_8 == opipe->level)) {
        fill_cnt = dra_reuse_page(dra, fifo, opipe, cnt - i);
        i += fill_cnt;
        opipe->refill_from_kfifo += fill_cnt;
    }

    if (i < cnt) {
        fill_cnt = dra_fill_from_alloc(dra, opipe, fifo, cnt - i);
        i += fill_cnt;
        opipe->refill_from_alloc += fill_cnt;
    }

    /* when num of fill is cnt return 0 else return 1
     alloc page align down 2, may be less than cnt */
    return !(i + 1 >= cnt);
}

void dra_bigpool_timer(struct timer_list *t)
{
    struct dra *dra = from_timer(dra, t, timer);
    int i, j;
    unsigned int wptr, rptr;

    if (dra->event & DRA_EVENT_RESETTING) {
        mod_timer(&dra->timer, jiffies + DRA_TIMER_EXPIRES);
        dra->timer_cnt++;
        dra_err("dra is resetting, event:0x%x\n", dra->event);
        return;
    }

    for (j = 0; j < sizeof(g_dra_timer_level) / sizeof(unsigned int); j++) {
        i = g_dra_timer_level[j];
        if (dra->opipes[i].used != DRA_OPIPE_USED_MAGIC) {
            continue;
        }
        dra_get_big_pool_ptr(dra, &dra->opipes[i], &wptr, &rptr);
        if ((dra->opipes[i].last_wptr == wptr) && (dra->opipes[i].last_rptr == rptr)) {
            dra->opipes[i].equal_times++;
        } else {
            dra->opipes[i].equal_times = 0;
        }

        dra->opipes[i].last_wptr = wptr;
        dra->opipes[i].last_rptr = rptr;
        if (dra->opipes[i].equal_times > 3) { // try 3 times to make sure idle
            if (i == DRA_OPIPE_LEVEL_10) {
                dra_release_lv10(dra, i);
            } else {
                dra_free_to_kernel(dra, i);
            }
            dra->opipes[i].equal_times = 0;
            dra->opipes[i].timer_free_cnt++;
        }
    }

    mod_timer(&dra->timer, jiffies + DRA_TIMER_EXPIRES);
    dra->timer_cnt++;

    return;
}

struct sk_buff *dra_to_skb(struct dra *dra, unsigned long long addr, unsigned long long *orig)
{
    struct sk_buff *skb = NULL;
    dra_buf_t buf;
    struct dra_tab *tab = NULL;

    buf.addr = addr;

    if (unlikely(buf.bits.level == DRA_OPIPE_LEVEL_3)) {
        dra_recycle_mem(dra, buf);
        bsp_info("used ap 9k\n");
        return NULL;
    }

    tab = dra_get_tab(dra, buf);
    if (tab == NULL) {
        return NULL;
    }

    skb = (struct sk_buff *)tab->manager;
    if (orig != NULL) {
        *orig = tab->dra_addr;
    }

    return skb;
}

void __dra_recycle_func(struct dra *dra, dra_buf_t *local_buf, unsigned int cnt)
{
    dra_buf_t buf;
    unsigned int i;
    struct sk_buff *skb = NULL;

    for (i = 0; i < cnt; i++) {
        buf = local_buf[i];
        if (unlikely(buf.bits.from != DRA_SKB_FROM_TCP_IP)) {
            dra_err("dra recycle dra error, 0x%llx\n", buf.addr);
            continue;
        }

        skb = dra_unmap_tcpip_skb(dra, buf);
        if (skb != NULL) {
            dev_kfree_skb_any(skb);
        }
    }
}

void dra_recycle_func(struct dra *dra)
{
    struct dra_recycle_pool *recycle = &dra->recycle[0];
    dra_buf_t *base = (dra_buf_t *)(uintptr_t)recycle->fifo.base;
    unsigned int max_free_cnt = 0;
    int ret;
    unsigned int rsl_busy_cnt;
    unsigned int cnt = 0;
    unsigned int tail_num;

    recycle->fifo.write = dra_get_rls(dra, 0);

    while (recycle->fifo.write != recycle->fifo.read) {
        rsl_busy_cnt = dra_get_busy_num(recycle->fifo.write, recycle->fifo.read, recycle->fifo.depth);
        if (rsl_busy_cnt > DRA_BURST_LEN) {
            cnt = DRA_BURST_LEN;
        } else {
            cnt = rsl_busy_cnt;
        }
        if (recycle->fifo.read + cnt <= recycle->fifo.depth) {
            ret = memcpy_s(recycle->local_buf, sizeof(recycle->local_buf), base + recycle->fifo.read,
                cnt * sizeof(dra_buf_t));
        } else {
            /* copy two space */
            tail_num = recycle->fifo.depth - recycle->fifo.read;
            ret = memcpy_s(recycle->local_buf, sizeof(recycle->local_buf), base + recycle->fifo.read,
                tail_num * sizeof(dra_buf_t));
            ret = memcpy_s(recycle->local_buf + tail_num,
                sizeof(recycle->local_buf) - tail_num * sizeof(dra_buf_t), base,
                (cnt - tail_num) * sizeof(dra_buf_t));
        }
        if (ret) {
            recycle->mcp_fail++;
        }
        max_free_cnt += cnt;
        __dra_recycle_func(dra, recycle->local_buf, cnt);
        recycle->fifo.read += cnt;
        if (recycle->fifo.read >= recycle->fifo.depth) {
            recycle->fifo.read -= recycle->fifo.depth;
        }
    }
    if (recycle->max_free_cnt < max_free_cnt) {
        recycle->max_free_cnt = max_free_cnt;
    }
    if (recycle->min_free_cnt > max_free_cnt) {
        recycle->min_free_cnt = max_free_cnt;
    }

    dra_set_rls(dra, recycle->fifo.read, 0);
}

int dra_refill_bigpool_work(struct dra *dra)
{
    unsigned int i;
    unsigned int total;
    int ret = 0;

    dra->status.work_start = bsp_get_slice_value();
    dra->irq_status = dra_get_intr_status(dra);
    dra_recycle_func(dra);
    for (i = 1; i <= dra->max_opipes; i++) {
        if ((dra->int_mask & BIT(i)) && (dra->irq_status & BIT(i))) {
            total = dra_get_space(dra, &dra->opipes[i]);
            if (total) {
                ret |= dra_fill_fifo(dra, &dra->opipes[i].fifo, total - dra->opipes[i].fifo.idx);
            }
        }
    }

    dra->status.work_end = bsp_get_slice_value();
    if (dra->status.work_start - dra->irq_time > DRA_SCHED_GAP) {
        dra_print_slice("dra sche time:%u, irq:%u, work:%u end:%u\n", dra->status.work_start - dra->irq_time,
            dra->irq_time, dra->status.work_start, dra->status.work_end);
    }

    return ret;
}

static int dra_thread(void *data)
{
    struct dra *dra = g_dra_ctx;
    int ret;

    while (1) {
        wait_event(dra->wqueue, test_bit(DRA_EVENT_THREAD_RUNNING_BIT, (void *)&dra->event)
            || test_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event));
        if (unlikely(dra->event & DRA_EVENT_THREAD_STOPING)) {
            dra_err("rst stoping\n");
            __pm_relax(dra->wake_lock);
            clear_bit(DRA_EVENT_THREAD_RUNNING_BIT, (void *)&dra->event);
            clear_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event);
            set_bit(DRA_EVENT_THREAD_STOPED_BIT, (void *)&dra->event);
            dra_err("rst stoping:%d\n", dra->event);
            wake_up(&dra->wqueue);
            continue;
        }

        ret = dra_refill_bigpool_work(dra);
        if (ret) {
            dra->status.sche_cnt++;
            msleep(1);
            continue;
        }

        __pm_relax(dra->wake_lock);
        clear_bit(DRA_EVENT_THREAD_RUNNING_BIT, (void *)&dra->event); // before enable intr
        dra_set_intr(dra); // enable intr
        dra->status.refill_succ++;
    }

    return 0;
}

irqreturn_t dra_interrupt(int irq, void *dev_id)
{
    struct dra *dra = (struct dra *)dev_id;

    __pm_stay_awake(dra->wake_lock);
    dra_top_intr(dra);

    dra->irq_time = bsp_get_slice_value();

    set_bit(DRA_EVENT_THREAD_RUNNING_BIT, (void *)&dra->event);
    wake_up(&dra->wqueue);

    return IRQ_HANDLED;
}

static unsigned int dra_set_dthrl(struct dra *dra, struct dra_fifo *fifo, int level)
{
    unsigned int depth;

    switch (level) {
        case DRA_OPIPE_LEVEL_0:
        case DRA_OPIPE_LEVEL_1:
        case DRA_OPIPE_LEVEL_2:
        case DRA_OPIPE_LEVEL_7:
        case DRA_OPIPE_LEVEL_8:
            depth = fifo->depth >> 4;
            break;
        case DRA_OPIPE_LEVEL_10:
            depth = (fifo->depth >> 3) + (fifo->depth >> 4); // 3/16 这个dts配置总数上线12W个，初始化补充2W左右，所以水线大概3/8
            break;
        default:
            depth = fifo->depth - DRA_TWO_BURST_RESERVE - 1;
    }

    //不开中断时bigpool和ddrbuf补满该level最大值，下水线设置为深度保证ddrbuf从bigpool里取走描述符
    if (dra->para->oparamter.disable_irq[level]) {
        depth = fifo->depth;
    }

    return (depth > DRA_FIFO_MIN_DEPTH) ? depth : DRA_FIFO_MIN_DEPTH;
}

int dra_ddr_buf_init(struct dra *dra, unsigned int level)
{
    struct dra_fifo *fifo = &dra->ddr_buf[level].fifo;

    fifo->depth = dra->para->ddr_buf_depth[level];
    if (fifo->depth == 0) {
        return 0;
    }

    fifo->base = dra->virt_base + dra->offset;
    fifo->phy = dra->dma_base + dra->offset;
    dra->offset += fifo->depth * sizeof(dra_buf_t);

    fifo->dthrl = dra_set_dthrl(dra, fifo, level);
    fifo->dbg_idx = dra->para->ddr_buf_dbg_idx[level];

    dra_ddr_buf_fifo_init(dra, fifo, level);

    return 0;
}

int dra_create_tab(struct dra *dra, struct dra_map *map, unsigned int level)
{
    unsigned int i;
    struct dra_tab *tmp = NULL;
    unsigned alloc_total_len;

    INIT_LIST_HEAD(&map->free_list);
    INIT_LIST_HEAD(&map->busy_list);
    INIT_LIST_HEAD(&map->reclaim_list);

    map->tab_max_size = dra->para->oparamter.tab_size[level];
    if (!dra->opipes[level].use_tab) {
        dra_err("level:%u no use tab\n", level);
        return 0;
    }
    alloc_total_len = sizeof(struct dra_tab) * map->tab_max_size;
    map->tab = (struct dra_tab *)vmalloc(alloc_total_len);
    if (map->tab == NULL) {
        dra_err("no map tab alloc\n");
        return -ENOMEM;
    }
    (void)memset_s(map->tab, alloc_total_len, 0, alloc_total_len);

    for (i = DRA_TABEL_START; i < map->tab_max_size; i++) {
        tmp = map->tab + i;
        tmp->idx = i;
        map->total++;
        map->free++;
        list_add_tail(&tmp->list, &map->free_list);
    }

    return 0;
}

int dra_opipe_init(struct dra *dra, int level)
{
    int ret, i;
    struct dra_map *map = &dra->opipes[level].map;
    struct dra_fifo *fifo = &dra->opipes[level].fifo;
    spin_lock_init(&dra->opipes[level].lock);

    fifo->depth = dra->para->oparamter.depth[level];
    dra->opipes[level].from = dra->para->oparamter.from[level];
    dra->opipes[level].level = level;
    INIT_LIST_HEAD(&dra->opipes[level].local_list);

    ret = dra_create_tab(dra, map, level);
    if (ret) {
        return ret;
    }

    if (fifo->depth == 0) {
        dra_err("level:%u no use opipe\n", level);
        return 0;
    }

    if (level == DRA_OPIPE_LEVEL_1 || level == DRA_OPIPE_LEVEL_8) {
        ret = kfifo_alloc(&dra->opipes[level].reuse_fifo, dra->para->oparamter.tab_size[level], GFP_KERNEL);
        ret = kfifo_alloc(&dra->opipes[level].idx_fifo, dra->para->oparamter.tab_size[level], GFP_KERNEL);
        if (ret) {
            dra_err("kfifo_alloc fail ret=%d\n", ret);
            return -1;
        }
        for (i = 0; i < dra->para->oparamter.tab_size[level]; i++) {
            kfifo_in(&dra->opipes[level].idx_fifo, &i, 1);
        }
    }

    fifo->base = dra->virt_base + dra->offset;
    fifo->phy = dra->dma_base + dra->offset;
    dra->offset += fifo->depth * sizeof(dra_buf_t);

    fifo->update_read_virt = dra->virt_base + dra->offset;
    fifo->update_read_addr = dra->dma_base + dra->offset;
    dra->offset += sizeof(unsigned long long);

    fifo->size = g_level_size[level];
    fifo->uthrl = fifo->depth - DRA_BURST_LEN - 1;
    fifo->dthrl = dra_set_dthrl(dra, fifo, level);
    fifo->free = fifo->depth - fifo->dthrl;
    fifo->dbg_idx = dra->para->oparamter.dbg_idx[level];
    dra_fifo_init(dra, fifo, level);

    if (dra->para->oparamter.disable_irq[level]) {
        //全部补充
        dra_fill_fifo(dra, fifo, map->tab_max_size);
    } else {
        dra->int_mask |= 1 << (unsigned int)level;
        dra_fill_fifo(dra, fifo, fifo->dthrl);
    }

    dra->opipes[level].status = DRA_OPIPE_STATUS_INIT;
    return 0;
}

void dra_recycle_pool_init(struct dra *dra)
{
    struct dra_fifo *fifo = NULL;
    int i;

    for (i = 0; i < DRA_RECYCLE_CH_CNT; i++) {
        fifo = &dra->recycle[i].fifo;

        if (fifo->depth == 0) {
            continue;
        }

        fifo->base = dra->virt_base + dra->offset;
        fifo->phy = dra->dma_base + dra->offset;
        dra->offset += fifo->depth * sizeof(dra_buf_t);

        __dra_recycle_pool_init(dra, i); // hal
    }
}

void dra_global_init(struct dra *dra)
{
    dra->int_mask = 0;
}

static void dra_dump_hook(void)
{
    unsigned int *reg = NULL;
    unsigned int i, j;
    unsigned int num = 0;
    struct dra *dra = g_dra_ctx;

    for (i = 0; i < DRA_BACK_REGS_NUM && (dra != NULL); i++) {
        for (j = 0; j < dra->back[i].num; j++) {
            reg = dra->dump_base + num + j;
            *reg = readl((void *)(dra->back[i].start + j * sizeof(unsigned int)));
        }
        num += dra->back[i].num;
    }

    reg = dra->dump_base + num;
    (void)memcpy_s(reg, sizeof(struct dra_opipe_debug), &dra->opipe_status[1], sizeof(dra->opipe_status[1]));
}

void dra_save_file_hook(const char *dir_name)
{
    if (dir_name == NULL || dir_name[0] == '\0') {
        dra_err("log path empty\n");
        return;
    }
    if ((g_dra_ctx->shm.mem != NULL) && (g_dra_ctx->shm.size != 0)) {
        (void)bsp_dpa_dump_log_save(dir_name, "dra_shm.bin", g_dra_ctx->shm.mem, g_dra_ctx->shm.size * sizeof(struct shm_blk));
    }
    if ((g_dra_ctx->tab_virt_base != NULL) && (g_dra_ctx->cma_size != 0)) {
        (void)bsp_dpa_dump_log_save(dir_name, "dra_tab.bin", g_dra_ctx->tab_virt_base, g_dra_ctx->cma_size);
    }
    if ((g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_1].fifo.base != 0) && (g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_1].fifo.depth != 0)) {
        (void)bsp_dpa_dump_log_save(dir_name, "dra_ddr_buf1.bin",
                    (void *)(uintptr_t)g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_1].fifo.base, g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_1].fifo.depth * sizeof(dra_buf_t));
    }
    if ((g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_8].fifo.base != 0) && (g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_8].fifo.depth != 0)) {
        (void)bsp_dpa_dump_log_save(dir_name, "dra_ddr_buf8.bin",
                    (void *)(uintptr_t)g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_8].fifo.base, g_dra_ctx->ddr_buf[DRA_OPIPE_LEVEL_8].fifo.depth * sizeof(dra_buf_t));
    }
}

static void dra_dump_init(struct dra *dra)
{
    int ret;

    dra_set_backup_regs(dra);
    dra->dump_base = (unsigned int *)bsp_dpa_dump_register_field(OM_DPAHOST_DRA, "DRA", DRA_DUMP_SIZE, 0);
    if (dra->dump_base == NULL) {
        dra_err("dump mem alloc fail\n");
        return;
    }
    ret = (int)memset_s(dra->dump_base, DRA_DUMP_SIZE, 0, DRA_DUMP_SIZE);
    if (ret) {
        dra_err("dump memset_s fail\n");
    }

    ret = bsp_dpa_dump_register_hook("dra", dra_dump_hook);
    if (ret == -1) {
        dra_err("register om fail\n");
    }
    ret = bsp_dpa_dump_register_log_notifier(DUMP_SAVE_DRA_CMA_MEM, dra_save_file_hook);
    if (ret) {
        dra_err("register om file fail\n");
    }
}

static int dra_creat_thread(struct dra *dra)
{
    dra->thread = kthread_run(dra_thread, NULL, "dra_thread");
    if (dra->thread == NULL) {
        dra_err("creat thread fail\n");
        return -1;
    }

    return 0;
}

int dra_thread_init(void)
{
    struct dra *dra = g_dra_ctx;
#ifndef CONFIG_PREEMPT_RT
    struct sched_param sch_para = {
        .sched_priority = DRA_THREAD_PRIORITY
    };
#endif

    if (dra->thread == NULL) {
        return 0;
    }

#ifndef CONFIG_PREEMPT_RT
    if (sched_setscheduler(dra->thread, SCHED_FIFO, &sch_para)) {
        dra_err("change priority fail\n");
        return -1;
    }
#endif
    return 0;
}

int dra_thread_priority_init(void)
{
#ifndef CONFIG_PREEMPT_RT
    struct sched_param sch_para = {
        .sched_priority = DRA_THREAD_PRIORITY
    };
#endif

    if (g_dra_ctx == NULL) {
        dra_err("dra no init\n");
        return 0;
    }

#ifndef CONFIG_PREEMPT_RT
    if (sched_setscheduler(g_dra_ctx->thread, SCHED_FIFO, &sch_para)) {
        dra_err("change priority fail\n");
        return -1;
    }
#endif
    return 0;
}

int dra_alloc_dma_mem(struct dra *dra)
{
    unsigned int level, i;
    unsigned int size = 0;

    for (i = 0; i < DRA_RECYCLE_CH_CNT; i++) {
        size += (dra->recycle[i].fifo.depth) * sizeof(dra_buf_t);
    }

    for (level = 0; level <= dra->max_opipes; level++) {
        if (!dra_opipe_is_enable(dra, level)) {
            continue;
        }
        size += dra->para->ddr_buf_depth[level] * sizeof(dra_buf_t);
        size += dra->para->rls_chn_depth[level] * sizeof(dra_buf_t) + sizeof(unsigned long long);
        size += dra->para->iparamter.depth[level] * sizeof(dra_buf_t) + sizeof(unsigned long long);
        size += dra->para->oparamter.depth[level] * sizeof(dra_buf_t) + sizeof(unsigned long long);
    }

    dra->dma_size = size;
    dra->virt_base = (unsigned long long)(uintptr_t)dma_alloc_coherent(dra->dev, size, &dra->dma_base, GFP_KERNEL);
    if (dra->virt_base == 0) {
        dra_err("dma mem alloc fail\n");
        return -ENOMEM;
    }
    dra_err("dma mem alloc:0x%llx-0x%x\n", dra->virt_base, dra->dma_size);

    for (i = 0; i < DRA_OPIPE_ALLOC_LEVELS; i++) {
        dra_err("tab size:0x%x-0x%x\n", dra->para->oparamter.tab_size[i], dra->para->ddr_buf_depth[i]);
    }

    return 0;
}

void dra_set_interrupt(unsigned int val)
{
    struct dra *dra = g_dra_ctx;

    dra->int_mask = val;
    dra_interupt_init(dra);
}

int dra_mem_input(unsigned int cnt)
{
    struct dra *dra = g_dra_ctx;
    dra_buf_t mbuf;
    struct dra_opipe *opipe = &dra->opipes[DRA_OPIPE_LEVEL_1];
    unsigned int i = 0;

    for (i = 0; i < cnt; i++) {
        mbuf.addr = dra_alloc_skb(dra, opipe, GFP_KERNEL);
        if (unlikely(mbuf.addr == 0)) {
            break;
        }
        dra_rls_input(dra, mbuf.addr, &dra->rls_opipes[1], DRA_OPIPE_LEVEL_1);
    }

    return i;
}

int dra_init_for_dpa(struct dra *dra)
{
    unsigned int cma_size = 0;

    cma_size += dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_1] * sizeof(struct dra_tab_info);
    cma_size += dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_8] * sizeof(struct dra_tab_info);
    cma_size += dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_1] * sizeof(dra_buf_t);
    dra_err("cma size:0x%x-0x%x-0x%x-0x%x\n", cma_size, dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_0],
        dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_1], dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_8]);
    /* bsp_dpa_rsv_cma_cache_alloc会映性一致性SC */
    dra->tab_virt_base = bsp_dpa_rsv_cma_cache_alloc(cma_size, &dra->tab_cma_base);
    if (dra->tab_virt_base == NULL) {
        dra_err("cma mem alloc fail\n");
        return -ENOMEM;
    }
    (void)memset_s(dra->tab_virt_base, cma_size, 0, cma_size);

    dra_sync_for_dpa();

    dra->tab_info_level1 = dra->tab_virt_base;
    dra->tab_info_level8 = dra->tab_virt_base + dra->para->oparamter.tab_size[DRA_OPIPE_LEVEL_1] * sizeof(struct dra_tab_info);
    dra->cma_size = cma_size;

    return 0;
}

void dra_sync_for_dpa(void)
{
    struct dra *dra = g_dra_ctx;
    writel(dra->tab_cma_base, dra->regs + DRA_SC_REG(7));
}

static int dra_pipe_init(struct dra *dra)
{
    int ret;
    unsigned int level;
    
    /* ddr buf init must before opipe init */
    for (level = 0; level <= dra->max_opipes; level++) {
        if (!dra_opipe_is_enable(dra, level)) {
            continue;
        }

        ret = dra_ddr_buf_init(dra, level);
        if (ret) {
            dra_err("dra_ddr_buf_init failed\n");
            return -1;
        }

        ret = dra_opipe_init(dra, level);
        if (ret) {
            return -1;
        }
        if (dra->para->rls_chn_depth[level] != 0) {
            dra_rls_chn_init(dra, level);
        }
        dra_cpu_ipipe_config(dra, level);
    }
    return 0;
}

int dra_core_probe(struct dra *dra)
{
    int ret;
    g_dra_ctx = dra;

    BUILD_BUG_ON((DRA_SKB_RESERVE_SIZE + DRA_OPIPE_LEVEL_1_SIZE + sizeof(struct dra_tab) + DRA_MAX_SKB_SIZE)
        > DRA_OPIPE_LEVEL_1_BUFF_SIZE);
    BUILD_BUG_ON((DRA_SKB_RESERVE_SIZE + DRA_SKB_MAX_PKT_SIZE + sizeof(struct skb_shared_info))
        > DRA_OPIPE_LEVEL_1_BUFF_SIZE);

    dra_global_init(dra);
    dra_basic_cfg(dra);
    dpa_shm_init(dra);
    ret = dra_init_for_dpa(dra);
    if (ret) {
        dra_err("dra dpa init fail:%d\n", ret);
        return ret;
    }

    if (dra_alloc_dma_mem(dra)) {
        return -1;
    }
    dra_recycle_pool_init(dra);

    /* ddr buf init must before opipe init */
    if (dra_pipe_init(dra)) {
        return -1;
    }

    dra->event = 0;
    init_waitqueue_head(&dra->wqueue);
    if (dra_creat_thread(dra)) {
        return -1;
    }

    dra_interupt_init(dra);

    if (dra_dpa_rst_init()) {
        return -1;
    }

    dra_dump_init(dra);
    dra_err("[init] ok\n");

    return 0;
}

int dra_suspend(struct device *dev)
{
    return dra_hal_suspend(g_dra_ctx);
}
EXPORT_SYMBOL(dra_suspend);
int dra_resume(struct device *dev)
{
    return dra_hal_resume(g_dra_ctx);
}
EXPORT_SYMBOL(dra_resume);
