/*
 * cgroup_workingset_preread.c
 *
 * The preread part of control group workingset subsystem
 *
 * Copyright (c) 2020-2020 Huawei Technologies Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#define _GNU_SOURCE
#define pr_fmt(fmt) "workingset: " fmt
#include "cgroup_workingset_internal.h"

#include <securec.h>

#include <linux/backing-dev.h>
#include <linux/memcontrol.h>
#include <linux/mm.h>
#include <linux/mm_inline.h>
#include <linux/pagemap.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/cpumask.h>
#include <linux/swap.h>
#include <linux/syscalls.h>
#include <linux/version.h>
#include <linux/vmalloc.h>
#include <uapi/linux/sched/types.h>
#include <linux/freezer.h>
#if KERNEL_VERSION(4, 19, 0) <= LINUX_VERSION_CODE
long __sys_setresuid(uid_t ruid, uid_t euid, uid_t suid);

#define GFP_ALLOC_PAGES		(__GFP_RECLAIM | __GFP_IO)
#define GFP_ADD_PAGE_CACHE	(GFP_NOFS)
#else
#define GFP_ALLOC_PAGES		(__GFP_RECLAIM | __GFP_IO | __GFP_COLD)
#define GFP_ADD_PAGE_CACHE	(__GFP_COLD | GFP_NOFS)
#endif
#if KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
#define PAGE_SHIFT_BITS		PAGE_SHIFT
#else
#define PAGE_SHIFT_BITS		PAGE_CACHE_SHIFT
#endif
#define MAX_READ_PAGES		(unsigned long)(BIO_MAX_PAGES)

/* Use to interrupt prereading process. */
static atomic_t g_preread_abort = ATOMIC_INIT(0);
static enum ws_self_read_state g_selfread_state = E_SELFREAD_NONE;

static const char * const g_selfread_dir[] = {
	"/data/data/",
	"/data/user/",
	"/data/user_de/",
	"/storage/emulated/",
	NULL
};

void workingset_preread_qos_wsrcrdlocked(
	struct s_workingset *ws, struct s_ws_record *record)
{
	bool need_dirty = false;

	if (!record->leader_blkio_cnt &&
	    (record->state & E_RECORD_STATE_UPDATE_BASE_BLKIO) &&
	    ws->leader_blkio_cnt) {
		record->leader_blkio_cnt = ws->leader_blkio_cnt;
		need_dirty = true;
		ws_dbg("%s, preread first blkio count = %u\n",
			__func__, ws->leader_blkio_cnt);
	} else if (record->leader_blkio_cnt &&
	    (ws->leader_blkio_cnt >= CARE_BLKIO_MIN_THRESHOLD) &&
	    (record->leader_blkio_cnt * BLKIO_MULTIPLE_FOR_UPDATE <
	    ws->leader_blkio_cnt)) {
		record->need_update = 1;
		need_dirty = true;
		ws_dbg("%s, base blkio=%u,current blkio=%u\n", __func__,
			record->leader_blkio_cnt, ws->leader_blkio_cnt);
	} else if (ws->leader_blkio_cnt > (record->leader_blkio_cnt +
	    (record->data.pageseq_cnt *
	    BLKIO_PERCENTAGE_THRESHOLD_FOR_UPDATE / ONE_HUNDRED))) {
		if (!(record->state & E_RECORD_STATE_UPDATE_BASE_BLKIO) &&
		    !record->leader_blkio_cnt) {
			record->leader_blkio_cnt = ws->leader_blkio_cnt;
			ws_dbg("%s, preread base blkio count = %u\n",
				__func__, ws->leader_blkio_cnt);
		} else {
			record->need_update = 1;
			ws_dbg("%s, blkio=%u, pages = %u\n",
				__func__, ws->leader_blkio_cnt,
				record->data.pageseq_cnt);
		}
		need_dirty = true;
	}

	if (need_dirty && !(record->state & E_RECORD_STATE_DIRTY))
		record->state |= E_RECORD_STATE_DIRTY |
		    E_RECORD_STATE_UPDATE_HEADER_ONLY;
	ws->leader_blkio_cnt = 0;
	ws->leader_blkio_base = 0;
}

static inline struct page *workingset_preread_alloc_page(
	struct address_space *mapping)
{
	return alloc_pages((mapping_gfp_mask(mapping) & ~__GFP_FS) |
	    GFP_ALLOC_PAGES, 0);
}

/*
 * workingset_page_cache_read -
 * Adds requested page to the page cache if not already there.
 * @file:	file to read
 * @offset:	page index
 *
 * This adds the requested page to the page cache if it isn't already there,
 * and schedules an I/O to read in its contents from disk.
 */
static int workingset_page_cache_read(struct s_readpages_control *rpc)
{
	struct address_space *mapping = rpc->mapping;
	loff_t isize = i_size_read(mapping->host);
	struct page *page = NULL;
	int ret;

	if (!isize || (rpc->offset > ((isize - 1) >> PAGE_SHIFT)) ||
	    !mapping->a_ops->readpage)
		return -EINVAL;

	do {
		page = workingset_preread_alloc_page(mapping);
		if (!page) {
			pr_err("%s: out of memory!\n", __func__);
			return -ENOMEM;
		}

		ret = add_to_page_cache_lru(page, mapping, rpc->offset,
		    GFP_NOFS);
		if (ret == 0)
			ret = mapping->a_ops->readpage(rpc->filp, page);
		else if (ret == -EEXIST)
			ret = 0; /* Losing race to add is OK */

#if KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
		put_page(page);
#else
		page_cache_release(page);
#endif
	} while (ret == AOP_TRUNCATED_PAGE);

	return ret;
}

#ifdef CONFIG_TASK_PROTECT_LRU
static inline struct list_head *get_protect_head_lru(
	struct lruvec *lruvec, struct page *page)
{
	enum lru_list lru = page_lru(page);

	return &lruvec->heads[PROTECT_HEAD_END].protect_page[lru].lru;
}
#endif

/*
 * Move inactive page to head of the lru list.
 * @page:	page to move
 */
static bool workingset_adjust_page_lru(struct page *page)
{
	bool adjusted = false;

	if (!PageUnevictable(page) &&
#ifdef CONFIG_TASK_PROTECT_LRU
	    !PageProtect(page) &&
#endif
	    !PageActive(page)) {
		if (PageLRU(page)) {
			struct lruvec *lruvec = NULL;
			struct zone *zone = page_zone(page);
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
			spin_lock_irq(&zone->zone_pgdat->lru_lock);
			lruvec = mem_cgroup_page_lruvec(page,
			    zone->zone_pgdat);
#elif KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
			spin_lock_irq(zone_lru_lock(zone));
			lruvec = mem_cgroup_page_lruvec(page,
			    zone->zone_pgdat);
#else
			spin_lock_irq(&zone->lru_lock);
			lruvec = mem_cgroup_page_lruvec(page, zone);
#endif
#ifdef CONFIG_TASK_PROTECT_LRU
			if (PageLRU(page) && !PageProtect(page) &&
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
			    !PageTransCompound(page) &&
#endif
			    !PageSwapBacked(page) &&
			    !PageUnevictable(page)) {
				struct list_head *head;

				head = get_protect_head_lru(lruvec, page);
				list_move(&page->lru, head);
				adjusted = true;
			}
#else
			if (PageLRU(page) && !PageSwapBacked(page) &&
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
			    !PageTransCompound(page) &&
#endif
			    !PageUnevictable(page)) {
				list_move(&page->lru,
					&lruvec->lists[page_lru(page)]);
				adjusted = true;
			}
#endif
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
			spin_unlock_irq(&zone->zone_pgdat->lru_lock);
#elif KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
			spin_unlock_irq(zone_lru_lock(zone));
#else
			spin_unlock_irq(&zone->lru_lock);
#endif
		} else {
			mark_page_accessed(page);
			adjusted = true;
		}
	}
	return adjusted;
}

/*
 * Read contiguous filepage from disk.
 */
static int workingset_read_pages(
	struct address_space *mapping, struct file *filp,
	struct list_head *pages, unsigned int nr_pages)
{
	struct blk_plug plug;
	unsigned int page_idx;
	int ret;

	blk_start_plug(&plug);

	if (mapping->a_ops->readpages) {
		ret = mapping->a_ops->readpages(filp, mapping,
		    pages, nr_pages);
		/* Clean up the remaining pages */
		put_pages_list(pages);
		goto out;
	}

	for (page_idx = 0; page_idx < nr_pages; page_idx++) {
		struct page *page = list_entry((pages)->prev,
		    struct page, lru);
		list_del(&page->lru);
		if (mapping->a_ops->readpage &&
		    !add_to_page_cache_lru(page, mapping, page->index,
		    (mapping_gfp_mask(mapping) & ~__GFP_FS) |
		    GFP_ADD_PAGE_CACHE))
			mapping->a_ops->readpage(filp, page);
#if KERNEL_VERSION(4, 9, 0) <= LINUX_VERSION_CODE
		put_page(page);
#else
		page_cache_release(page);
#endif
	}
	ret = 0;

out:
	blk_finish_plug(&plug);

	return ret;
}

/*
 * Read contiguous filepage.
 */
/*lint -e548*/
static unsigned long get_max_read_limit(struct address_space *mapping)
{
	struct backing_dev_info *bdi = inode_to_bdi(mapping->host);

	return min_not_zero(MAX_READ_PAGES, bdi->io_pages);
}

static unsigned int workingset_page_cache_range_read(
	struct s_readpages_control *rpc)
{
	LIST_HEAD(page_pool);
	unsigned int page_idx;
	unsigned int ret = 0;
	unsigned int chunk = 0;
	struct page *page = NULL;
	loff_t isize = i_size_read(rpc->mapping->host);
	unsigned long max_to_read = get_max_read_limit(rpc->mapping);

	rpc->nr_adjusted = 0;
	if (isize == 0)
		goto out;
	/*
	 * Preallocate as many pages as we will need.
	 */
	for (page_idx = 0; page_idx < rpc->nr_to_read; page_idx++) {
		pgoff_t pageoffset = rpc->offset + page_idx;

		if (pageoffset > ((isize - 1) >> PAGE_SHIFT_BITS))
			break;
		page = find_get_page(rpc->mapping, pageoffset);
		if (page) {
			if (workingset_adjust_page_lru(page))
				rpc->nr_adjusted++;
			put_page(page);
			if (chunk)
				goto submit;
			continue;
		}

		page = workingset_preread_alloc_page(rpc->mapping);
		if (!page) {
			pr_err("%s: out of memory!\n", __func__);
			break;
		}
		page->index = pageoffset;
		list_add(&page->lru, &page_pool);
		chunk++;
		if (chunk == max_to_read) {
submit:
			workingset_read_pages(rpc->mapping, rpc->filp,
			    &page_pool, chunk);
			ret += chunk;
			chunk = 0;
			if ((atomic_read(&g_preread_abort) ||
			    fatal_signal_pending(current)))
			    break;
		}
	}
	if (chunk)
		workingset_read_pages(rpc->mapping, rpc->filp,
		    &page_pool, chunk);

	WARN_ON(!list_empty(&page_pool));
out:
	return ret + chunk;
}
/*lint +e548*/

static bool path_is_under_dirs(const char *path, const char * const dir[])
{
	int i = 0;

	while (dir[i] != NULL) {
		if (strncmp(path, dir[i], strlen(dir[i])) == 0)
			return true;
		i++;
	}
	return false;
}

static inline bool is_iaware_thread(void)
{
    return strncmp(current->comm, "iaware", TASK_COMM_LEN) == 0;
}

static void check_selfread_state(bool is_snapshot)
{
	if (!is_snapshot) {
		return;
	}

	bool is_iaware = is_iaware_thread();
	bool is_binder = (g_selfread_state == E_SELFREAD_DOING);

	if ((is_iaware && is_binder) || (!is_iaware && !is_binder)) {
		ws_dbg("%s: g_selfread_state is changed invalid. [iaware:%d, state:%d]\n",
			__func__, is_iaware, g_selfread_state);
	}
}

static bool workingset_prereader_can_open(const char *path, bool is_iaware)
{
	bool is_myself_dir = path_is_under_dirs(path, g_selfread_dir);
	if (is_iaware && is_myself_dir)
		return false;
	else if (!is_iaware && !is_myself_dir)
		return false;
	else
		return true;
}

static void workingset_prereader_setresuid(uid_t euid)
{
#ifdef CONFIG_ARCH_HAS_SYSCALL_WRAPPER
	__sys_setresuid((gid_t)-1, euid, (gid_t)-1);
#else
	sys_setresuid((gid_t)-1, euid, (gid_t)-1);
#endif
}

static void workingset_prereader_open_all_files_internal(
	struct s_ws_preread_control *prc, struct file **filpp, unsigned int record_state)
{
	int flags = O_RDONLY;
	unsigned int idx;
	unsigned int next_loop;
	struct s_ws_preread_data *data = &prc->data;
	const struct cred *mycred = current_cred(); /*lint !e666*/
	uid_t myself_euid;
	uid_t target_euid;
	bool is_iaware = is_iaware_thread();

	if (force_o_largefile())
		flags |= O_LARGEFILE;

	next_loop = 0;
	myself_euid = from_kuid_munged(mycred->user_ns, mycred->euid);
	while (next_loop < data->file_cnt) {
		int euid_changed = 0;
		target_euid = data->file_array[next_loop].owner_uid;
		if (target_euid != myself_euid) {
			if (!is_iaware) {
				next_loop++;
				continue;
			}
			workingset_prereader_setresuid(target_euid);
			euid_changed = 1;
		}

		for (idx = next_loop, next_loop = data->file_cnt;
			idx < data->file_cnt; idx++) {
			if (filpp[idx] || !data->file_array[idx].path ||
				!workingset_prereader_can_open(
			    data->file_array[idx].path, is_iaware))
				continue;

			if (target_euid != data->file_array[idx].owner_uid) {
				next_loop = (next_loop == data->file_cnt) ?
					idx : next_loop;
				continue;
			}

			filpp[idx] = filp_open(data->file_array[idx].path,
				flags, 0);

			if (!IS_ERR_OR_NULL(filpp[idx])) {
				continue;
			}
				
			ws_dbg("%s: open %s failed, ret=%d\n",
			    __func__, data->file_array[idx].path, filpp[idx]);
			if ((record_state & E_RECORD_STATE_EXTERNAL_FILEPATH) &&
				!data->file_array[idx].path)
				kfree(data->file_array[idx].path);

			data->file_array[idx].path = NULL;
			filpp[idx] = NULL;
		}

		if (euid_changed)
			workingset_prereader_setresuid(myself_euid);

		euid_changed = 0;
	}
}

static struct file **workingset_prereader_alloc_filepp_internal(
	struct s_ws_preread_control *prc)
{
	unsigned int idx;
	struct file **filpp = NULL;
	struct page *page = NULL;
	struct s_ws_preread_data *data = &prc->data;
	unsigned int need_pages;

	if (data->file_cnt <= FILPS_PER_PAGE) {
		return (struct file **)get_zeroed_page(GFP_NOFS);
	}

	need_pages = (data->file_cnt + FILPS_PER_PAGE - 1) / FILPS_PER_PAGE;

	for (idx = 0; idx < need_pages; idx++) {
		page = alloc_page(GFP_NOFS | __GFP_ZERO);
		if (!page) {
			pr_err("%s: OOM, alloc %u pages failed!\n",
				__func__, need_pages);
			break;
		}
		prc->filp_pages[idx] = page;
	}

	if (idx >= need_pages) {
		filpp = vmap(prc->filp_pages, need_pages, VM_MAP,
		    PAGE_KERNEL); /*lint !e446*/
	} else {
		filpp = NULL;
	}

	if (!filpp) {
		for (idx = 0; idx < need_pages; idx++) {
			if (prc->filp_pages[idx]) {
				__free_page(prc->filp_pages[idx]);
				prc->filp_pages[idx] = NULL;
			}
		}
	}

	return filpp;
}

static bool workingset_filepage_is_need_skip_read(
	struct s_read_control *rc, unsigned int idx,
	unsigned int stage, bool read_major, unsigned int *pfile_idx)
{
	bool ret = false;
	bool is_major;
	unsigned int file_idx;
	unsigned int stage_num;
	struct s_ws_preread_data *data = rc->data;
	struct file **filpp = rc->filpp;

	if (read_major) {
		stage_num = (data->cacheseq[idx] >> PAGE_STAGE_NUM_SHIFT) &
		    PAGE_STAGE_NUM_MASK;
		if (stage < stage_num) {
			rc->stage_end = idx;
			ret = true;
			goto out;
		}
	}

	file_idx = (data->cacheseq[idx] >> FILE_OFFSET_BITS) &
		MAX_TOUCHED_FILES_COUNT;
	if ((file_idx >= data->file_cnt) || !filpp[file_idx]) {
		ret = true;
		goto out;
	}

	is_major = data->cacheseq[idx] & (PAGE_MAJOR_MASK << PAGE_MAJOR_SHIFT);
	if ((read_major && !is_major) || (!read_major && is_major)) {
		ret = true;
		goto out;
	}
	*pfile_idx = file_idx;
out:
	return ret;
}

static void workingset_fill_rpt(struct s_readpages_control *rpc,
	struct file *filp)
{
#if defined(CONFIG_OVERLAY_FS) && (KERNEL_VERSION(4, 19, 0) <= LINUX_VERSION_CODE)
	struct file *real_file = get_real_file(filp);
	rpc->filp = real_file;
	rpc->mapping = real_file->f_mapping;
#else
	rpc->filp = filp;
	rpc->mapping = filp->f_mapping;
#endif
}

static void workingset_do_preread_pages(struct s_mt_preread_record *record, struct s_read_control *rc)
{
	struct s_readpages_control rpc;
	struct file *filp = record->filp;
	struct page *page = NULL;
	unsigned int cacheseq = record->cacheseq;
	unsigned int next_cacheseq = record->next_cacheseq;
	unsigned int read_count;

	if (!filp) {
		goto out;
	}

	/* Find file page in page cache. */
	workingset_fill_rpt(&rpc, filp);
	rpc.offset = cacheseq & MAX_TOUCHED_FILE_OFFSET;
	if (record->type == P_MULITY) {
		/* In the case, prereading multi file pages */
		rpc.nr_to_read = (next_cacheseq &
			MAX_TOUCHED_FILE_OFFSET) - rpc.offset;
		read_count = workingset_page_cache_range_read(&rpc);
		atomic_add(rpc.nr_to_read - read_count, &rc->present_pages_cnt);
		atomic_add(read_count, &rc->read_pages_cnt);
		atomic_add(rpc.nr_adjusted, &rc->move_lru_cnt);
		goto out;
	}

	/* In the case, prereading single file page */
	page = find_get_page(rpc.mapping, rpc.offset);
	if (page) {
		if (workingset_adjust_page_lru(page))
			atomic_inc(&rc->move_lru_cnt);
		put_page(page);
		atomic_inc(&rc->present_pages_cnt);
	} else if (!workingset_page_cache_read(&rpc)) {
		atomic_inc(&rc->read_pages_cnt);
	}

out:
	if (record) {
		kfree(record);
		record = NULL;
	}
}

static int workingset_read_filepage_looper(
	struct s_read_control *rc, unsigned int stage_begin,
	unsigned int stage, bool read_major, struct s_mt_preread_control *mpc, char *owner_name, bool is_snapshot)
{
	struct s_ws_preread_data *data = rc->data;
	struct file **filpp = rc->filpp;
	unsigned int idx;
	unsigned int file_idx;
	struct s_mt_preread_record *record;

	/*
	 * In some case, io request is congested, so we must be ensure
	 * read file page of main thread touched first.
	 */
	for (idx = stage_begin; idx < rc->stage_end;) {
		if (atomic_read(&g_preread_abort)) {
			return -EINTR;
		}

		if (fatal_signal_pending(current)) {
			return -EINTR;
		}

		if (workingset_filepage_is_need_skip_read(
			rc, idx, stage, read_major, &file_idx)) {
			idx++;
			continue;
		}

		record = kzalloc(sizeof(struct s_mt_preread_record), GFP_KERNEL);
		if (!record) {
			pr_err("%s: alloc record faild.\n", __func__);
			continue;
		}
   
        record->filp = filpp[file_idx];
        record->cacheseq = data->cacheseq[idx];
        
		if ((data->cacheseq[idx] >> PAGE_RANGE_HEAD_SHIFT) & PAGE_RANGE_HEAD_MASK) {
			record->next_cacheseq = data->cacheseq[++idx];
			record->type = P_MULITY;
		} else {
			record->type = P_SINGLE;
		}
		idx++;

		if (!mpc) {
			workingset_do_preread_pages(record, rc);
		} else {
			down(&mpc->sem);
			list_add_tail(&record->list, &mpc->file_list_head);
			up(&mpc->sem);
		}
	}

	return 0;
}

static void check_cachemiss_threshold_rcrdlocked(
	struct s_ws_record *record, unsigned int present,
	unsigned int absent)
{
	if ((((ONE_HUNDRED - CACHE_MISSED_THRESHOLD_FOR_BLKIO) *
	    (present + absent)) / ONE_HUNDRED) > present)
		record->state |= E_RECORD_STATE_UPDATE_BASE_BLKIO;
}

static bool mt_preread_task_has_sleeper(struct s_mt_preread_control *mpc)
{
	unsigned int i;
	unsigned int cnt = 0;

	while (true) {
		for (i = 0; i < mpc->thread_num; i++) {
			if (!wq_has_sleeper(&mpc->preread_tasks[i].preread_wait))
				break;
			cnt++;
			if (cnt == mpc->thread_num)
				return true;
		}
		set_current_state(TASK_UNINTERRUPTIBLE);
		schedule_timeout(4);
		set_current_state(TASK_RUNNING);
		cnt = 0;
	}
	return true;
}

static void mt_preread_task_wake_up(struct s_mt_preread_control *mpc)
{
	unsigned int i;

	for (i = 0; i < mpc->thread_num; i++) {
		struct s_mt_preread_task *preread_task = &mpc->preread_tasks[i];

		if (wq_has_sleeper(&preread_task->preread_wait)) {
			atomic_set(&preread_task->preread_wait_flag, 1);
			wake_up_interruptible(&preread_task->preread_wait);
		}
	}
}


static void workingset_read_filepages_internal(
	struct s_ws_preread_control *prc, struct file **filpp, struct s_mt_preread_control *mpc)
{
	struct s_ws_preread_data *data = &prc->data;
	unsigned int stage = 0;
	unsigned int stage_begin = 0;
	bool read_major = true;
	struct s_read_control rc = {
		.data = data,
		.filpp = filpp,
		.stage_end = data->pageseq_cnt,
		.present_pages_cnt = ATOMIC_INIT(0),
		.read_pages_cnt = ATOMIC_INIT(0),
		.move_lru_cnt = ATOMIC_INIT(0)
	};

    ws_dbg("%s beg: %s\n", __func__, prc->owner.name);
	if (mpc) {
		mpc->rc = &rc;
	}

	while (1) {
		if (!workingset_read_filepage_looper(
		    &rc, stage_begin, stage, read_major, mpc, prc->owner.name, prc->owner.is_snapshot)) {
			if (read_major) {
				read_major = false;
				continue;
			} else if (rc.stage_end < data->pageseq_cnt) {
				read_major = true;
				stage_begin = rc.stage_end;
				rc.stage_end = data->pageseq_cnt;
				stage++;
				continue;
			} else {
				break;
			}
		}
		break;
	}

	if (mpc) {
		atomic_set(&mpc->preread_control_wait_flag, 0);
		if (mt_preread_task_has_sleeper(mpc))
			mt_preread_task_wake_up(mpc);

		(void)wait_event_freezable(mpc->preread_control_wait,
				atomic_read(&mpc->preread_control_wait_flag));
	}

	ws_dbg("%s end: %s,%u fls,%u sqs,%u pgs,prsnt %u,mv %u,rd %u\n",
		__func__, prc->owner.name, data->file_cnt,
		data->pageseq_cnt, data->page_sum, atomic_read(&rc.present_pages_cnt),
		atomic_read(&rc.move_lru_cnt), atomic_read(&rc.read_pages_cnt));
}

static void workingset_preread_post_work_internal(
	struct s_ws_preread_control *prc, struct file **filpp)
{
    unsigned int file_idx;
	unsigned int idx;
	struct s_ws_preread_data *data = &prc->data;
	if (filpp) {
		for (file_idx = 0; file_idx < data->file_cnt; file_idx++) {
			if (filpp[file_idx]) {
				filp_close(filpp[file_idx], NULL);
			}
		}
	}

	for (idx = 0; idx < FILP_PAGES_COUNT; idx++) {
		if (prc->filp_pages[idx]) {
			if (filpp) {
				vunmap(filpp);
				filpp = NULL;
			}
			__free_page(prc->filp_pages[idx]);
			prc->filp_pages[idx] = NULL;
		}
	}

	if (filpp) {
		free_page((unsigned long)filpp);
		filpp = NULL;
	}
}

static int workingset_fill_prcowner_rcrdlocked (
	struct s_ws_owner *prc_owner, const struct s_ws_owner *owner)
{
	unsigned int name_len;
	unsigned int path_len;
	char *new_name = NULL;
	char *new_path = NULL;
	int ret = 0;

	if (!owner->name || !owner->record_path) {
		ws_dbg("%s:name=%s, record_path=%s\n",
		    __func__, owner->name, owner->record_path);
		return -EINVAL;
	}

	name_len = strlen(owner->name) + 1;
	path_len = strlen(owner->record_path) + 1;
	if (name_len <= 0 || name_len >= OWNER_MAX_CHAR ||
	    path_len <= 0 || path_len >= PATH_MAX_CHAR) {
		ws_dbg("%s:name_len=%d, path_len=%d\n",
		    __func__, name_len, path_len);
		return -EINVAL;
    }

    new_name = kzalloc(name_len, __GFP_ZERO);
	if (!new_name) {
	    ws_dbg("%s:new_name malloc error!\n", __func__);
		return -ENOMEM;
	}

    if (strncpy_s(new_name, name_len, owner->name, name_len)) {
        ws_dbg("%s:new_name copy failed!\n", __func__);
		ret = -EINVAL;
		goto copy_owner_failed;
	}

    new_path = kzalloc(path_len, __GFP_ZERO);
    if (!new_path) {
        ws_dbg("%s:new_path malloc error!\n", __func__);
        ret =  -ENOMEM;
        goto copy_owner_failed;
    }

    if (strncpy_s(new_path, path_len, owner->record_path, path_len)) {
	    ws_dbg("%s:new_path copy failed!\n", __func__);
		ret = -EINVAL;
		goto copy_ownerpath_failed;
	}

    // copy owner which preread control is working for.
	if (new_name) {
		prc_owner->name = new_name;
	}
	if (new_path) {
		prc_owner->record_path = new_path;
	}
    prc_owner->pid = owner->pid;
    prc_owner->uid = owner->uid;
    prc_owner->is_snapshot = owner->is_snapshot;

	return 0;
copy_ownerpath_failed:
    pr_err("%s: copy_ownerpath_failed ret=%d\n", __func__, ret);
	kfree(new_path);
	new_path = NULL;
copy_owner_failed:
    pr_err("%s: copy_owner_failed ret=%d\n", __func__, ret);
	kfree(new_name);
	new_name = NULL;
	return ret;
}

static void workingset_fill_prcdata_free_pages(struct page **pages, unsigned int page_num)
{
	int i;

	if (pages == NULL || page_num <= 0) {
		return;
	}

	for (i = 0; i < page_num; i++) {
		if (pages[i]) {
			__free_page(pages[i]);
		}
	}
	kfree(pages);
}

static struct page **workingset_fill_prcdata_prepare_pages(unsigned int num)
{
	struct page **pages = NULL;
	int idx;

	if (num <= 0) {
		return NULL;
	}

	pages = kcalloc(num, sizeof(struct page *), GFP_NOFS);
	if (!pages) {
		pr_err("%s: allocate pages for prcdata failed.\n", __func__);
		return NULL;
	}

	for (idx = 0; idx < num; idx++) {
		pages[idx] = alloc_page(GFP_NOFS);
		if (!pages[idx]) {
			pr_err("%s: OOM, alloc %u pages failed!\n", __func__, num);
			workingset_fill_prcdata_free_pages(pages, idx);
			return NULL;
		}
	}

	return pages;
}

static int workingset_fill_prcdata_fill_file_array(const struct s_ws_data *data, struct s_path_node *file_array)
{
	int idx;
    int path_len = 0;
    int sum_path_len = 0;
	int ret = 0;
	bool is_iaware = is_iaware_thread();

    for (idx = 0; idx < data->file_cnt; idx++) {
        char *new_path = NULL;

        if (!data->file_array[idx].path ||
            !workingset_prereader_can_open(
            data->file_array[idx].path, is_iaware)) {
            continue;
        }

        path_len = strlen(data->file_array[idx].path) + 1;
        new_path = kzalloc(path_len, __GFP_ZERO);
        if (!new_path) {
           ret =  -ENOMEM;
           return ret;
        }

        if (strncpy_s(new_path, path_len,
            data->file_array[idx].path, path_len)) {
            ret = -EINVAL;
            return ret;
        }
        file_array[idx].path = new_path;
        file_array[idx].owner_uid = data->file_array[idx].owner_uid;
        file_array[idx].hashcode = data->file_array[idx].hashcode;
        file_array[idx].pathlen = data->file_array[idx].pathlen;
        sum_path_len += data->file_array[idx].pathlen;
    }

    ws_dbg("%s:filecnt=%d, pagecnt=%d, sum_path_len=%d\n",
        __func__, data->file_cnt, data->pageseq_cnt, sum_path_len);

	return ret;
}

static void *workingset_fill_prcdata_allocate_vaddr(
	unsigned int length, struct page ***mapped_pages, unsigned int *num)
{
	void **array;
	struct page **pages = NULL;
	unsigned int page_num;

	if (length <= 0) {
		return NULL;
	}

	page_num = (length + PAGE_SIZE - 1) / PAGE_SIZE;
	pages = workingset_fill_prcdata_prepare_pages(page_num);
	if (pages == NULL) {
		pr_err("%s: prepare pages failed.\n", __func__);
       	return NULL;
	}

	array = vmap(pages, page_num, VM_MAP, PAGE_KERNEL);
	if (!array) {
		pr_err("%s: vmap pages failed.\n", __func__);
		goto allocate_failed;
	}

	if (memset_s(array, page_num * PAGE_SIZE,
	    0, page_num * PAGE_SIZE)) {
		pr_err("%s: clean array failed.\n", __func__);
		goto allocate_failed;
	}

	*mapped_pages = pages;
	*num = page_num;
	return array;

allocate_failed:
	if (pages != NULL) {
		workingset_fill_prcdata_free_pages(pages, page_num);
	}

	if (!array) {
		vunmap(array);
	}

	return NULL;
}

static int workingset_fill_prcdata_rcrdlocked(
    struct s_ws_preread_data *prc_data, const struct s_ws_data *data)
{
	int ret = 0;
    int idx = 0;
    unsigned int *cacheseq = NULL;
	struct page **cacheseq_pages = NULL;
	unsigned int cacheseq_pages_needed = 0;
	struct s_path_node *file_array = NULL;
	struct page **file_array_pages = NULL;
	unsigned int file_array_pages_needed = 0;

	cacheseq = (unsigned int *)workingset_fill_prcdata_allocate_vaddr(
		data->pageseq_cnt * sizeof(unsigned int), &cacheseq_pages, &cacheseq_pages_needed);
	if (cacheseq == NULL) {
		pr_err("%s: allocate cache pages failed.\n", __func__);
		ret = -ENOMEM;
		return ret;
	}

	for (idx = 0; idx < data->pageseq_cnt; idx++) {
        cacheseq[idx] = data->cacheseq[idx];
    }

	file_array = (struct s_path_node *)workingset_fill_prcdata_allocate_vaddr(
		data->file_cnt * sizeof(struct s_path_node), &file_array_pages, &file_array_pages_needed);
	if (file_array == NULL) {
		pr_err("%s: allocate file array failed.\n", __func__);
		ret = -ENOMEM;
    	goto copy_failed;
	}

	int res = workingset_fill_prcdata_fill_file_array(data, file_array);
	if (res) {
		ret = -ENOMEM;
    	goto copy_failed;
	}
	prc_data->cacheseq = cacheseq;
	prc_data->cacheseq_pages = cacheseq_pages;
	prc_data->cacheseq_pages_num = cacheseq_pages_needed;
	prc_data->file_array = file_array;
	prc_data->file_array_pages = file_array_pages;
	prc_data->file_array_pages_num = file_array_pages_needed;
	prc_data->pageseq_cnt = data->pageseq_cnt;
    prc_data->file_cnt = data->file_cnt;
    prc_data->page_sum = data->page_sum;
	return 0;

copy_failed:
	if (cacheseq != NULL) {
		workingset_fill_prcdata_free_pages(cacheseq_pages, cacheseq_pages_needed);
		cacheseq_pages = NULL;
		vunmap(cacheseq);
		cacheseq = NULL;
	}
	if (file_array != NULL) {
		for (idx = 0; idx < data->file_cnt; idx++) {
			if (!file_array[idx].path) {
				continue;
			}
			kfree(file_array[idx].path);
			file_array[idx].path = NULL;
		}
		workingset_fill_prcdata_free_pages(file_array_pages, file_array_pages_needed);
		file_array_pages = NULL;
		vunmap(file_array);
		file_array = NULL;
	}
    return ret;
}

static int workingset_fill_prc_rcrdlocked(
	struct s_ws_preread_control *prc, const struct s_ws_record *record)
{
    int ret = 0;

    ret = workingset_fill_prcowner_rcrdlocked(&prc->owner, &record->owner);
    if (ret) {
        pr_err("%s:%s prc owner fill failed ret=%d\n",
            __func__, current->comm, ret);
        return ret;
    }
    ret = workingset_fill_prcdata_rcrdlocked(&prc->data, &record->data);
    if (ret) {
        pr_err("%s:%s prc data fill failed ret=%d\n",
            __func__, current->comm, ret);
        goto fill_failed;
    }

    return 0;
fill_failed:
    pr_err("%s:%s prc fill failed ret=%d\n", __func__, current->comm, ret);
    if (prc->owner.name) {
        kfree(prc->owner.name);
        prc->owner.name = NULL;
    }

    if (prc->owner.record_path) {
        kfree(prc->owner.record_path);
        prc->owner.record_path = NULL;
    }

    return ret;
}

static void workingset_do_preread_post_prcwork(struct s_ws_preread_control *prc)
{
	unsigned int i;
	unsigned int idx = 0;

    if (prc->owner.name != NULL) {
        kfree(prc->owner.name);
        prc->owner.name = NULL;
    }

    if (prc->owner.record_path != NULL) {
        kfree(prc->owner.record_path);
        prc->owner.record_path = NULL;
    }

	if (prc->data.cacheseq_pages != NULL) {
		for (i = 0; i < prc->data.cacheseq_pages_num; i++) {
			if (prc->data.cacheseq_pages[i]) {
				__free_page(prc->data.cacheseq_pages[i]);
			}
		}
		kfree(prc->data.cacheseq_pages);
		prc->data.cacheseq_pages = NULL;
		prc->data.cacheseq_pages_num = 0;
	}

	if (prc->data.cacheseq != NULL) {
		vunmap(prc->data.cacheseq);
	    prc->data.cacheseq = NULL;
    }

    if (prc->data.file_array != NULL) {
		for (idx = 0; idx < prc->data.file_cnt; idx++) {
			if (prc->data.file_array[idx].path) {
				kfree(prc->data.file_array[idx].path);
				prc->data.file_array[idx].path = NULL;
			}
		}
    }

	if (prc->data.file_array_pages != NULL) {
		for (i = 0; i < prc->data.file_array_pages_num; i++) {
			if (prc->data.file_array_pages[i]) {
				__free_page(prc->data.file_array_pages[i]);
			}
		}
		kfree(prc->data.file_array_pages);
		prc->data.file_array_pages = NULL;
		prc->data.file_array_pages_num = 0;
	}

	if (prc->data.file_array != NULL) {
		vunmap(prc->data.file_array);
		prc->data.file_array = NULL;
	}
}

static void workingset_do_preread_prcwork(struct s_ws_preread_control *prc, struct s_mt_preread_control *mpc, unsigned int record_state)
{
    struct file **filpp = NULL;
    struct s_ws_preread_data *data = &prc->data;

    if (!data->file_cnt || !data->pageseq_cnt ||
        !data->file_array || !data->cacheseq) {
        ws_dbg("%s:end-%d:%d:%d:%d\n", __func__,
            data->file_cnt, data->pageseq_cnt, data->file_array, data->cacheseq);
        return;
    }

    if (atomic_read(&g_preread_abort)) {
        ws_dbg("%s:end-g_preread_abort\n", __func__);
        return;
    }

    /* Alloc pages for save opened struct files */
    filpp = workingset_prereader_alloc_filepp_internal(prc);
    if (!filpp) {
        ws_dbg("%s:end-filpp\n", __func__);
        return;
    }

    workingset_prereader_open_all_files_internal(prc, filpp, record_state);
    workingset_read_filepages_internal(prc, filpp, mpc);
    workingset_preread_post_work_internal(prc, filpp);
}

static void workingset_set_preread_scheduler(bool is_snapshot)
{
    struct sched_param param = { .sched_priority = is_snapshot ? 1 : 0 };

    if (is_snapshot){
        sched_setscheduler(current, SCHED_FIFO, &param);
    } else {
        sched_setscheduler(current, SCHED_NORMAL, &param);
    }
}

static int preread_thread(void *p)
{
    struct s_mt_preread_task *preread_task = (struct s_mt_preread_task *)p;
    struct s_mt_preread_control *mpc = preread_task->mpc;
	struct s_mt_preread_record *entry = NULL;

	set_freezable();

    while(!kthread_should_stop()) {
		(void)wait_event_freezable(preread_task->preread_wait,
				atomic_read(&preread_task->preread_wait_flag));
		down(&mpc->sem);
		if (!test_bit(preread_task->idx, &mpc->preread_task_mask))
			set_bit(preread_task->idx, &mpc->preread_task_mask);

		entry = list_first_entry_or_null(&mpc->file_list_head, struct s_mt_preread_record, list);
		if (!entry) {
			atomic_set(&preread_task->preread_wait_flag, 0);
			clear_bit(preread_task->idx, &mpc->preread_task_mask);
			if (mpc->preread_task_mask) {
				up(&mpc->sem);
				continue;
			}
			atomic_set(&mpc->preread_control_wait_flag, 1);
			wake_up_interruptible_all(&mpc->preread_control_wait);
			up(&mpc->sem);
			continue;
		}
		list_del(&entry->list);
		up(&mpc->sem);

		if (!mpc->rc) {
			pr_err("%s:rc is null\n",__func__);
			continue;
		}

		workingset_do_preread_pages(entry, mpc->rc);
    }

    return 0;
}

void workingset_do_preread_work(struct s_ws_record *record, struct s_mt_preread_control *mpc)
{
    int ret = 0;
    struct s_ws_preread_control prc = {0};

    if (!record)
        return;

    mutex_lock(&record->mutex);
    workingset_set_preread_scheduler(record->owner.is_snapshot);
    ret = workingset_fill_prc_rcrdlocked(&prc, record);
    record->state |= E_RECORD_STATE_PREREADING;
    mutex_unlock(&record->mutex);

    if (ret) {
        pr_err("%s:%s prc fill failed ret=%d\n",
                __func__, current->comm, ret);
    } else {
		workingset_do_preread_prcwork(&prc, mpc, record->state);
        workingset_do_preread_post_prcwork(&prc);
    }

    workingset_set_preread_scheduler(false);
}

void workingset_preread_by_self_internal(struct s_ws_record *record, struct s_mt_preread_control *mpc)
{
    struct task_struct *tsk = NULL;
    struct task_struct *leader = NULL;
    struct s_ws_preread_control prc = {0};
    int ret = 0;

    if (record)  {
        if(!(record->state & E_RECORD_STATE_PREREADING_BINDER)
            && mutex_trylock(&record->mutex)) {
            ret = workingset_fill_prc_rcrdlocked(&prc, record);
            mutex_unlock(&record->mutex);

            if (!ret) {
                mutex_lock(&record->mutex);
                record->state |= E_RECORD_STATE_PREREADING_BINDER;
                mutex_unlock(&record->mutex);
                workingset_do_preread_prcwork(&prc, mpc, record->state);
                workingset_do_preread_post_prcwork(&prc);

                mutex_lock(&record->mutex);
                record->state &= ~E_RECORD_STATE_PREREADING_BINDER;
                mutex_unlock(&record->mutex);
            }
        }
    }

	rcu_read_lock();
	leader = current->group_leader;
	tsk = leader;
	// cppcheck-suppress *
	do {
		tsk->ext_flags &= ~PF_EXT_WSCG_PREREAD;
	} while_each_thread(leader, tsk);
	rcu_read_unlock();
}

void workingset_preread_force_stop(void)
{
	atomic_set(&g_preread_abort, 1);
}

void workingset_preread_permmit(void)
{
	atomic_set(&g_preread_abort, 0);
}

enum ws_self_read_state workingset_get_preread_state(void)
{
	return g_selfread_state;
}

void workingset_set_preread_state(enum ws_self_read_state state)
{
	g_selfread_state = state;
}

int init_mt_preread_control(struct s_mt_preread_control *mpc)
{
	int i;
	int ret = 0;
	struct cpumask mask = CPU_MASK_NONE;
	struct sched_param param = { .sched_priority = 1 };
		
	mpc->preread_tasks = kzalloc(sizeof(struct s_mt_preread_control) * mpc->thread_num, GFP_KERNEL);
	if (!mpc->preread_tasks) {
		ret = -ENOMEM;
		return ret;
	}

	INIT_LIST_HEAD(&mpc->file_list_head);
	atomic_set(&mpc->preread_control_wait_flag, 0);
	init_waitqueue_head(&mpc->preread_control_wait);
	mpc->preread_task_mask = 0;
	sema_init(&mpc->sem, 1);

	for_each_possible_cpu(i) {
		if (topology_physical_package_id(i) == 1)
			cpumask_set_cpu(i, &mask);
	}

	for (i = 0; i < mpc->thread_num; i++) {
		struct s_mt_preread_task *preread_task = &mpc->preread_tasks[i];
		
		init_waitqueue_head(&preread_task->preread_wait);
		atomic_set(&preread_task->preread_wait_flag, 0);
		preread_task->idx = i;
		preread_task->mpc = mpc;
		preread_task->work = kthread_run(preread_thread, preread_task, "mt_preread_task%d", i);
		if (IS_ERR(preread_task->work)) {
			ws_dbg("failed to start new_preread_task%d\n", i);
			return PTR_ERR(preread_task->work);
		}

		set_cpus_allowed_ptr(preread_task->work, &mask);
		sched_setscheduler_nocheck(preread_task->work, SCHED_FIFO, &param);
	}

    return 0;
}

void exit_mt_preread_control(struct s_mt_preread_control *mpc)
{
	struct s_mt_preread_record *item, *tmp;
	int i;

	for (i = 0; i < mpc->thread_num; i++) {
		kthread_stop(mpc->preread_tasks[i].work);
		kfree(&mpc->preread_tasks[i]);
	}

	list_for_each_entry_safe(item, tmp, &mpc->file_list_head, list) {
		list_del(&item->list);
		kfree(item);
	}
	
	kfree(mpc);
	pr_err("%s mpc existed.\n",__func__);
}
