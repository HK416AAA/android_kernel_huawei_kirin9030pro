/*
 * dsm_blk.h
 *
 * deal with dsm_blk
 *
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef LINUX_DSM_BLK_H
#define LINUX_DSM_BLK_H

#ifdef CONFIG_HUAWEI_BLOCK_DSM

#include <linux/spinlock.h>
#include <linux/printk.h>
#include <dsm/dsm_pub.h>

/* err code for hievent */
#define DSM_BLK_BIO_DISCARD         928008200
#define DSM_BLK_REQ_ERR             928008201

/* dsm blk error event reporting time threshold */
#define DSM_BLK_EVENT_NS_THRESHOLD  600000000000ULL  /* 600s */

/* buffer size for record dsm_blk log */
#define DSM_BLK_BUFFER_SIZE         1024U

/* dsm_blk log ctrl block */
struct dsm_blk_cb {
    spinlock_t lock;                    /* lock */
    struct dsm_client *blk_dclient;     /* dsm_client for blk */
};

/* error event reporting time struct */
struct dsm_blk_error_ns_record {
    int err_no;
    u64 last_report_time;
};

extern bool dsm_blk_could_error_report(int err_code);
extern struct dsm_client *dsm_blk_get_dclient(void);
unsigned long dsm_blk_lock(void);
void dsm_blk_unlock(unsigned long flags);

#define DSM_BLK_FMT_PREFIX(fmt)  "[blk][%s,%d]" fmt, __func__, __LINE__

#define dsm_blk_log(err_code, fmt, ...)                                    \
    do {                                                                   \
        struct dsm_client *blk_dclient = dsm_blk_get_dclient();            \
        if (unlikely(blk_dclient == NULL)) {                               \
            break;                                                         \
        }                                                                  \
        unsigned long irqflag = dsm_blk_lock();                            \
        if (dsm_blk_could_error_report(err_code)) {                        \
            if (!dsm_client_ocuppy(blk_dclient)) {                         \
                dsm_client_record(blk_dclient, DSM_BLK_FMT_PREFIX(fmt),    \
                                  ##__VA_ARGS__);                          \
                dsm_client_notify(blk_dclient, (err_code));                \
                printk(DSM_BLK_FMT_PREFIX(fmt), ##__VA_ARGS__);            \
            }                                                              \
        }                                                                  \
        dsm_blk_unlock(irqflag);                                           \
    } while (false)

#define dsm_blk_log_with_bio(bio, err_code, fmt, ...)                      \
    do {                                                                   \
        if (unlikely(((bio) == NULL) || ((bio)->bi_disk == NULL))) {       \
            break;                                                         \
        }                                                                  \
        dsm_blk_log((err_code),                                            \
                    "[task:%s][disk:%s][bi_opf:0x%x][bi_status:0x%x] " fmt,\
                    current->comm, (bio)->bi_disk->disk_name,              \
                    (bio)->bi_opf, (bio)->bi_status, ##__VA_ARGS__);       \
    } while (false)

#define dsm_blk_log_with_request(rq, err_code, fmt, ...)                   \
    do {                                                                   \
        if (unlikely(((rq) == NULL) || ((rq)->rq_disk == NULL))) {         \
            break;                                                         \
        }                                                                  \
        dsm_blk_log((err_code),                                            \
                    "[disk:%s][cmd_flags:0x%x][rq_flags:0x%x] " fmt,       \
                    (rq)->rq_disk->disk_name, (rq)->cmd_flags,             \
                    (rq)->rq_flags, ##__VA_ARGS__);                        \
    } while (false)

#else /* !CONFIG_HUAWEI_BLOCK_DSM */
#define dsm_blk_log(err_code, fmt, ...)
#define dsm_blk_log_with_bio(bio, err_code, fmt, ...)
#define dsm_blk_log_with_request(rq, err_code, fmt, ...)
#endif /* !CONFIG_HUAWEI_BLOCK_DSM */

#endif /* LINUX_DSM_BLK_H */
