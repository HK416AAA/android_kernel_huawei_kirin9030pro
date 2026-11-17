/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description:  MAS MQ ioscheduler interface
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MAS_BLK_IOSCHED_INTERFACE_H__
#define __MAS_BLK_IOSCHED_INTERFACE_H__

#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/blk-mq.h>
#include <linux/version.h>
#include <linux/timer.h>

#include "blk.h"
#include "blk-mq.h"
#include "blk-mq-tag.h"

extern struct delayed_work mas_io_guard_work;

enum mas_ufs_mq_async_dispatch_mode {
	/* async io will be limited by a fixed value */
	MAS_UFS_MQ_ASYNC_NORMAL_MODE = 0,
	/* async io will be limited by sync io */
	MAS_UFS_MQ_ASYNC_FWB_MODE,
	/* async io will be dispatched a.s.a.p */
	MAS_UFS_MQ_ASYNC_LM_MODE,
};

/*
 * This struct defines all the variable for ufs mq io-scheduler per lld.
 */
struct mas_ufs_sched_ds_lld {
	struct blk_dev_lld *lld;

#define MAS_MQ_DEFAULT_CP_LIMIT 5
	unsigned int cp_io_limit;
	/* IOs with cp flag in low level driver */
	atomic_t cp_io_inflt_cnt;
	atomic_t cpp_io_inflt_cnt;

	/* MQ tag usage statistic */
	atomic_t mq_tag_used_cnt;
	atomic_t mq_resrvd_tag_used_cnt;
	atomic_t mq_prio_tag_used_cnt;
	/* count of VIP IOs that wait for tags */
	atomic_t vip_wait_cnt;

	/* Sync IOs in low level driver */
	atomic_t sync_io_inflt_cnt;
	/* Async IOs in low level driver */
	atomic_t async_io_inflt_cnt;
	/* VIP IOs in low level driver */
	atomic_t vip_io_inflt_cnt;
	/* FG IOs in low level driver */
	atomic_t fg_io_inflt_cnt;

	spinlock_t sync_disp_lock;
	/* List for all requeued high prio IOs */
	struct list_head hp_sync_disp_list;
	/* IO counts in high_prio_sync_dispatch_list */
	atomic_t hp_io_list_cnt;

	/* List for all requeued sync IOs */
	struct list_head sync_disp_list;
	/* IO counts in sync_dispatch_list */
	atomic_t sync_io_list_cnt;

	spinlock_t async_disp_lock;
	bool async_io_sched_inited;
	struct list_head async_fifo_list;
	/* IO counts in async_dispatch_list */
	atomic_t async_io_list_cnt;
#ifdef CONFIG_MAS_UNISTORE_PRESERVE
	struct list_head rec_bio_disp_list;
	spinlock_t rec_bio_disp_list_lock;
#endif
	/* Max sync IOs allowed */
	int sync_io_inflt_lmt;
	/* Max async IOs allowed */
	int async_io_inflt_lmt;
	unsigned int lmt_ratio;
#ifdef CONFIG_VIRTIO_BLK_COOKIE_FE
	atomic_t async_io_inflt_no_lmt;
	atomic_t async_io_last;
	atomic_t sync_pick_cnt;
	atomic_t async_pick_cnt;
#endif
	/* Submit time for latest sync io */
	ktime_t last_sync_io_submit_tm;
	/* Burst mode trigger time */
	ktime_t last_sync_burst_trig_tm;
	/* Complete time for latest sync io */
	ktime_t last_sync_io_compl_tm;
	/* Complete time for latest async io */
	ktime_t last_async_io_compl_tm;
	/* Last async inflight limit update time */
	ktime_t last_async_io_inflt_lmt_update_tm;
	struct timer_list sb_dispatch_check_timer;
	/* Status for sync burst state machine */
	atomic_t sb_dispatch_level;
	/* Dispatch mode for async io */
	enum mas_ufs_mq_async_dispatch_mode async_dispatch_mode;
	struct timer_list write_throttle_check_timer;
	spinlock_t async_limit_update_lock;
	bool async_limit_update_enable;

#ifdef CONFIG_MAS_QOS_MQ
	atomic_t per_cpu_io_inflt[NR_CPUS];
#endif
	atomic_t ref_cnt;

	struct timer_list turbo_timer;
	struct delayed_work datasync_work;
	bool turbo_mode;
};

struct mas_ufs_mq_work {
	ktime_t last_queue_tm;
	ktime_t last_enter_tm;
	ktime_t last_exit_tm;
	struct delayed_work io_dispatch_work;
	struct request_queue *queue;
};

struct mas_ufs_mq_sched {
	struct request_queue *q;
	/* The work will dispatch all the requeue sync IOs */
	struct mas_ufs_mq_work sync_dispatch_work;
	/* The work will dispatch all the requeue async IOs */
	struct mas_ufs_mq_work async_dispatch_work;
	struct list_head io_guard_list_node;
	struct mas_ufs_sched_ds_lld *sched_ds_lld;
};

extern blk_qc_t request_to_qc_t(struct blk_mq_hw_ctx *hctx, struct request *rq);
extern struct blk_tagset_ops mas_ufs_blk_tagset_ops;

extern struct mas_ufs_mq_priv mas_ufs_mq;
extern struct blk_mq_tags *ufs_tagset_init_tags(
	unsigned int total_tags, unsigned int reserved_tags,
	unsigned int high_prio_tags, int node, int alloc_policy);
extern void ufs_tagset_free_tags(const struct blk_mq_tags *tags);
extern void ufs_tagset_all_tag_busy_iter(
	struct blk_mq_tags *tags, busy_tag_iter_fn *fn,
	const void *priv);
extern void ufs_tagset_tag_busy_iter(
	struct blk_mq_hw_ctx *hctx, busy_iter_fn *fn, void *priv);
extern int ufs_mq_iosched_init(struct request_queue *q);
extern void ufs_mq_iosched_exit(struct request_queue *q);
extern void ufs_mq_req_alloc_prep(
	struct blk_mq_alloc_data *data, unsigned long ioflag, bool fs_submit);
extern void ufs_mq_req_init(const struct blk_mq_ctx *ctx, struct request *rq);
extern void ufs_mq_req_complete(
	struct request *rq, const struct request_queue *q, bool succ_done);
extern void ufs_mq_req_deinit(struct request *rq);
extern void ufs_mq_req_insert(
	struct request *req, struct request_queue *q);
extern void ufs_mq_req_requeue(
	struct request *req, const struct request_queue *q);
extern void ufs_mq_req_timeout_handler(struct request *req);
void ufs_mq_ctx_put(struct request_queue *q);
struct blk_mq_ctx *ufs_mq_ctx_get(struct request_queue *q);
extern void ufs_mq_hctx_get_by_req(
	const struct request *rq, struct blk_mq_hw_ctx **hctx);
extern unsigned int ufs_mq_tag_get(const struct blk_mq_alloc_data *data);
extern int ufs_mq_tag_put(
	const struct blk_mq_hw_ctx *hctx, unsigned int tag,
	const struct request *rq);
extern int ufs_mq_tag_update_depth(void);
extern int ufs_mq_tag_wakeup_all(struct blk_mq_tags *tags);
extern void ufs_mq_exec_queue(const struct request_queue *q);
extern void ufs_mq_run_hw_queue(const struct request_queue *q);
extern void ufs_mq_run_requeue(const struct request_queue *q);
extern void ufs_mq_poll_enable(bool *enable);
extern void ufs_mq_status_dump(
	const struct request_queue *q, enum blk_dump_scene s);
extern void ufs_mq_async_io_dispatch_work_fn(const struct work_struct *work);
extern void __ufs_mq_complete_request_remote(const void *data);
extern void ufs_mq_flush_plug_list(
	struct blk_plug *plug, bool from_schedule);

struct mas_ufs_sched_ds_lld;
extern void ufs_mq_sync_burst_check_timer_expire(struct mas_ufs_sched_ds_lld *sched_ds_lld);
extern void ufs_mq_sync_io_dispatch_work_fn(const struct work_struct *work);
extern void ufs_mq_write_throttle_check_timer_expire(struct mas_ufs_sched_ds_lld *sched_ds_lld);
extern void ufs_mq_write_throttle_handler(struct request_queue *q, bool level);
extern struct mas_ufs_sched_ds_lld *ufs_mq_write_throttle_check_timer_prepare(struct timer_list *timer);
extern void __cfi_ufs_mq_flush_plug_list(
	struct blk_plug *plug, bool from_schedule);
struct mas_ufs_sched_ds_lld *ufs_mq_sync_burst_check_timer_prepare(struct timer_list *timer);
extern void ufs_mq_io_guard_work_fn(void);
blk_qc_t __cfi_ufs_mq_make_request(struct bio *bio);
blk_qc_t ufs_mq_make_request(struct bio *bio);
struct request *__blk_mq_alloc_request(struct blk_mq_alloc_data *data);
extern void __blk_mq_requeue_request(struct request *rq);
extern void ufs_mq_dump_request(
	const struct request_queue *q, enum blk_dump_scene s);
extern void ufs_mq_lmt_ratio_update(struct request_queue *q, unsigned int ratio);
extern void ufs_tagset_power_off_proc(struct blk_dev_lld *lld);
void __cfi_ufs_mq_sync_io_delayed_work_init(struct mas_ufs_mq_sched *sched_ds);
void __cfi_ufs_mq_timer_setup_sync_burst_init(struct mas_ufs_sched_ds_lld *ds_lld);
void __cfi_ufs_mq_flush_plug_list_fn_init(void);
void __cfi__ufs_mq_request_remote_init(struct request *rq);
void __cfi_ufs_mq_async_io_delayed_work_init(struct mas_ufs_mq_sched *sched_ds);
void __cfi_ufs_mq_io_guard_delayed_work_init(void);
void __cfi_ufs_mq_timer_setup_write_throttle_init(struct mas_ufs_sched_ds_lld *ds_lld);
#endif /* __MAS_BLK_IOSCHED_INTERFACE_H__ */
