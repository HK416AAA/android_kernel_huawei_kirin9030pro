/*
 * mem_ama.h
 *
 * Copyright(C) 2022 Hisilicon Technologies Co., Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _LINUX_MM_AMA_H
#define _LINUX_MM_AMA_H

#include <linux/device.h>
#include <linux/mm.h>
#include <linux/mmzone.h>
#include <linux/sizes.h>
#include <linux/hp/memcg_policy.h>
#include <internal.h>

#define AMA_MAX_KILL_NUM	(5)

typedef enum {
	LOCAL_NODE0 = 0,
	LOCAL_NODE1,
	LOCAL_NODE2,
	NR_LOCAL_NODE,
} ama_node_id;

typedef enum {
	AMA_FILE = 0,
	AMA_ANON_FG,
	AMA_ANON_BG,
	AMA_ZRAM,
	AMA_KALLOC,
	/* e.g. ion&gpu */
	AMA_MEDIA,
	AMA_BIGBW,
	AMA_INTERLEAVE,
	NR_AMA_TYPE,
} ama_policy_type;

extern unsigned int sysctl_ama_migrate_scan_size;
extern unsigned int sysctl_ama_migrate_scan_period;
extern unsigned int sysctl_ama_kshrinkd_watermark;
extern unsigned int sysctl_ama_kshrinkd_scan_delay;
extern unsigned int sysctl_ama_kslabd_watermark;
extern unsigned int sysctl_ama_kslabd_scan_delay;

static inline bool is_node_part0(int nid)
{
	return (nid == LOCAL_NODE0);
}

static inline bool is_node_part1(int nid)
{
	return (nid == LOCAL_NODE1);
}

static inline bool is_node_part2(int nid)
{
	return (nid == LOCAL_NODE2);
}

struct page *ama_alloc_kernel_large(gfp_t gfp, unsigned int order);
struct page *ama_alloc_page_cache(gfp_t gfp, unsigned int order);
struct page *ama_alloc_anon_pages(gfp_t gfp, unsigned int order);
struct page *ama_alloc_zram_page(gfp_t gfp);
struct page *ama_alloc_meida_pages(gfp_t gfp, unsigned int order);
unsigned long ama_alloc_media_pages_bulk_list(
	gfp_t gfp, int nr_pages, struct list_head *page_list);
struct page *ama_alloc_bigbw_pages(gfp_t gfp, unsigned int order);
unsigned long ama_alloc_bigbw_pages_bulk_list(
	gfp_t gfp, int nr_pages, struct list_head *page_list);
struct devres *ama_alloc_dr(dr_release_t release,
				size_t size, gfp_t gfp);

vm_fault_t do_ama_page(struct vm_fault *vmf);
void wake_ama_kworker(int nid);
void wake_all_kshrinkd(void);
void wake_all_kslabd(void);
unsigned int get_ama_ch24_intlv_en(void);

void ama_shrink_node(pg_data_t *pgdat, struct scan_control *sc);
#endif
