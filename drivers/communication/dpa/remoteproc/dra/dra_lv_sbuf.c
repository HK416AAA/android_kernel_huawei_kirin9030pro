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

/* 这些定义需要保持和DPA一致，且需要考虑DPA的cacheline大小 */
#define DPA_SBUF_CTRL_SIZE 256
#define DPA_SBUF_DATA_SIZE 256
#define DPA_SBUF_CNT_PER_PAGE 8
/* 编译拦截，这样代码中有些判断可以省掉，提高执行效率 */
#if ((DPA_SBUF_DATA_SIZE + DPA_SBUF_CTRL_SIZE) * DPA_SBUF_CNT_PER_PAGE) > PAGE_SIZE
#error "Please check sbuf alloctor implement."
#endif

#define DPA_SBUF_GET_PAGE_ADDR(phy_addr) (phy_addr & (~(PAGE_SIZE - 1)))
#define DPA_SBUF_GET_CTRL_BYIDX(page_addr, idx) ((page_addr) + ((idx) * (DPA_SBUF_CTRL_SIZE + DPA_SBUF_DATA_SIZE)))
#define DPA_SBUF_GET_IDX_BYCTRL(ctrl_addr) (((ctrl_addr) >> 9) & 0x7)
#define DPA_SBUF_GET_DATA_BYIDX(page_addr, idx) (DPA_SBUF_GET_CTRL_BYIDX(page_addr, idx) + DPA_SBUF_CTRL_SIZE)
#define DPA_SBUF_GET_IDX_BY_DATA(data_addr) DPA_SBUF_GET_IDX_BYCTRL((data_addr) - DPA_SBUF_CTRL_SIZE)

/* 尝试往opipe中添加cnt个地址，返回成功的cnt数量 */
unsigned dra_sbuf_fill(struct dra *dra, struct dra_opipe *opipe, unsigned cnt)
{
    struct page *page = NULL;
    dma_addr_t page_phys_addr;
    void *page_virt_addr = NULL; 

    unsigned int i;
    dma_addr_t phys_addr;
    unsigned long long maa_addr;

    unsigned fill_cnt;
    unsigned level = opipe->level;

    fill_cnt = 0;
    while (fill_cnt < cnt) {
        if (test_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event)) {
            // 防止fill_cnt过大时，恰好发生单独复位，处理完成这么多的fill花费的时间太长,所以需要尽快返回
            break;
        }
        /* 这里申请出来的是cache一致性CMA，由SC保持一致性 */
        page_virt_addr = bsp_dpa_cma_cache_alloc(PAGE_SIZE, &page_phys_addr, GFP_KERNEL);
        if (unlikely(page_virt_addr == NULL)) {
            break;
        }
        if (test_bit(DRA_EVENT_THREAD_STOPING_BIT, (void *)&dra->event)) {
            // 由于bsp_dpa_cma_cache_alloc可能会因为内存不足而阻塞, bsp_dpa_cma_cache_alloc不返回可能导致dpa单独复位失败
            dra_err("bsp_dpa_cma_cache_alloc when dpa in resetting.\n");
            bsp_dpa_cma_cache_free(PAGE_SIZE, page_virt_addr, page_phys_addr);
            break;
        }
        dra->opipe_status[level].alloc_success++;
        page = virt_to_page(page_virt_addr);
        for(i = 0; i < DPA_SBUF_CNT_PER_PAGE && fill_cnt < cnt; i++){
            phys_addr = DPA_SBUF_GET_CTRL_BYIDX(page_phys_addr, i);

            // 从freelist中获得一个struct dra_tab，使用idx组成maa_addr，然后把dra_tab加入busylist
            // 同时增加opipe的busy_depth
            maa_addr = dra_map_single(dra, phys_addr, page, DRA_SKB_FROM_OWN, level, DRA_OWN);
            if (unlikely(maa_addr == 0)) {
                if (i == 0) {
                    bsp_dpa_cma_cache_free(PAGE_SIZE, page_virt_addr, page_phys_addr);
                    dra->opipe_status[level].free++;
                }
                dra->opipe_status[level].map_own_fail++;
                break;
            }
            get_page(page);
            dra->opipe_status[level].map_own_success++;
            dra_bigpool_input(dra, maa_addr, opipe);
            fill_cnt++;
        }
    }
    return fill_cnt;
}

/* 尝试从ipipe中取出cnt个地址并归还系统，返回成功的数量 */
unsigned dra_sbuf_release(struct dra *dra, struct dra_ipipe *ipipe __maybe_unused, unsigned cnt)
{
    struct page *page = NULL;
    dma_addr_t page_phys_addr;
    void *page_virt_addr = NULL; 
    
    unsigned i;
    dma_addr_t phys_addr;
    dra_buf_t maa_addr;

    unsigned release_cnt;
    unsigned level = ipipe->level;

    release_cnt = 0;
    for (i = 0; i < cnt; i ++) {
        maa_addr.addr = dra_ipipe_alloc(DRA_OPIPE_LEVEL_10_SIZE);
        if (maa_addr.addr == 0) {
            break;
        }

        phys_addr = maa_addr.bits.phyaddr;
        page_phys_addr = DPA_SBUF_GET_PAGE_ADDR(phys_addr);
        page_virt_addr = (void *)phys_to_virt(page_phys_addr);
        page = virt_to_page(page_virt_addr);

        if(dra_unmap_single(dra, &maa_addr, NULL, NULL)){
            dra->opipe_status[level].unmap_own_fail++;
            dpa_system_error(DRV_ERRNO_DRA_MEM, DRA_OPIPE_LEVEL_10, 0, (char *)(void *)&maa_addr, sizeof(maa_addr));
            continue;
        }
        release_cnt++;
        dra->opipe_status[level].unmap_own++;
        put_page(page);
        if(page_ref_count(page) == 1) {
            dra->opipe_status[level].free++;
            bsp_dpa_cma_cache_free(PAGE_SIZE, page_virt_addr, page_phys_addr);
        }
    }
    return release_cnt;
}


unsigned dra_fill_lv10(struct dra *dra, struct dra_opipe *opipe, unsigned cnt)
{
    unsigned can_fill;
    unsigned need_fill;
    struct dra_map *map = NULL;
    unsigned level = opipe->level;
    unsigned long flags;

    map = &opipe->map;
    spin_lock_irqsave(&opipe->lock, flags);
    if (unlikely(list_empty(&map->free_list))) {
        dra->opipe_status[level].free_list_empty++;
        spin_unlock_irqrestore(&opipe->lock, flags);
        return 0;
    }
    can_fill = map->free;
    spin_unlock_irqrestore(&opipe->lock, flags);
    need_fill = min(cnt, can_fill);
    return dra_sbuf_fill(dra, opipe, need_fill);
}

unsigned dra_release_lv10(struct dra *dra,unsigned level)
{
    unsigned cnt;
    struct dra_opipe *opipe = NULL;
    struct dra_ipipe *ipipe = NULL;

    ipipe = &dra->cpu_ipipes[level];
    opipe = &dra->opipes[level];
    // 释放的水线应该设置多大：规格确定，现在是按照lv8 lv1来
    if (opipe->busy_depth > (dra->ddr_buf[level].fifo.dthrl + 0x1000)) {
        cnt = opipe->busy_depth - dra->ddr_buf[level].fifo.dthrl - 0x1000;
    } else {
        return 0;
    }
    return dra_sbuf_release(dra, ipipe, cnt);
}
