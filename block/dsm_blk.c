/*
 * dsm_blk.c
 *
 * deal with dsm_blk
 *
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
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

#ifdef CONFIG_HUAWEI_BLOCK_DSM

#include <linux/printk.h>
#include <linux/time.h>
#include <linux/module.h>
#include <securec.h>
#ifdef CONFIG_HISYSEVENT
#include "hiview_hievent.h"
#endif
#include "dsm_blk.h"

#ifdef CONFIG_HISYSEVENT
struct blk_error_no_map {
    int error_no;
    char *name;
};
 
static int blk_errorno_to_str(int error_no, char *str, int str_len)
{
    int ret;
    struct blk_error_no_map blk_error_to_str_map[] = {
        {DSM_BLK_BIO_DISCARD, "DSM_BLK_BIO_DISCARD"},
        {DSM_BLK_REQ_ERR, "DSM_BLK_REQ_ERR"},
    };

    if ((str == NULL) || (str_len == 0)) {
        pr_err("[%s, %d] invalid str or str_len\n", __fun__, __LINE__);
        return ERR;
    }
    for (size_t i = 0; i < ARRAY_SIZE(blk_error_to_str_map); i++) {
        if (blk_error_to_str_map[i].error_no != error_no) {
            continue;
        }
        if (strlen(blk_error_to_str_map[i].name) >= str_len) {
            pr_err("[%s, %d] str_len: %d is too small\n", __fun__, __LINE__, str_len);
            return ERR;
        }
        (void)memset_s(str, str_len, 0, str_len);
        ret = strncpy_s(str, str_len, blk_error_to_str_map[i].name, str_len - 1);
        if (ret != EOK) {
            pr_err("[%s, %d] strncpy_s failed, ret:%d\n", __fun__, __LINE__, ret);
            return ERR;
        }
        return OK;
    }
    return ERR;
}

static int blk_errorno_get_event_type(int error_no)
{
    (void)error_no;
    return FAULT; /* fault event */
}

static struct dsm_client_ops g_dsm_blk_client_ops = {
    .poll_state = NULL,
    .dump_func = NULL,
    .errorno_to_str = blk_errorno_to_str,
    .errorno_get_event_type = blk_errorno_get_event_type,
};
#endif /* CONFIG_HISYSEVENT */

/* args for register dsm client */
static struct dsm_dev g_dsm_blk_dev = {
#ifdef CONFIG_HISYSEVENT
    .name = "storage_dsm_blk_report",
    .device_name = NULL,
    .ic_name = NULL,
    .module_name = NULL,
    .fops = &g_dsm_blk_client_ops,
    .buff_size = DSM_BLK_BUFFER_SIZE,
#else
    .name = "dsm_blk_report",
    .buff_size = DSM_BLK_BUFFER_SIZE,
#endif
};

/* dsm_blk log print ctrl block */
static struct dsm_blk_cb g_dsm_blk_cb = {0};

/* list that records the reporting time of dsm_blk error event */
static struct dsm_blk_error_ns_record g_dsm_blk_error_ns_record_list[] = {
    {DSM_BLK_BIO_DISCARD, 0U},
    {DSM_BLK_REQ_ERR, 0U},
};

/*
 * Check whether the input error code meets the reporting time threshold.
 * @err_code: error code which to be checked.
 * @return: true: can be reported; false: shouldn't be reported.
 */
bool dsm_blk_could_error_report(int err_code)
{
    u64 now = ktime_get_ns();
    for (size_t i = 0; i < ARRAY_SIZE(g_dsm_blk_error_ns_record_list); i++) {
        if (err_code != g_dsm_blk_error_ns_record_list[i].err_no) {
            continue;
        }
        if ((abs(now - g_dsm_blk_error_ns_record_list[i].last_report_time) > DSM_BLK_EVENT_NS_THRESHOLD) ||
            (g_dsm_blk_error_ns_record_list[i].last_report_time == 0U)) {
            g_dsm_blk_error_ns_record_list[i].last_report_time = now;
            return true;
        }
    }
    return false;
} 

/* 
 * Get the pointer of blk_dclient.
 * The caller should check whether the return pointer is NULL.
 */
struct dsm_client *dsm_blk_get_dclient(void)
{
    return g_dsm_blk_cb.blk_dclient;
}

unsigned long dsm_blk_lock(void)
{
    unsigned long tmpFlags;
    spin_lock_irqsave(&g_dsm_blk_cb.lock, tmpFlags);
    return tmpFlags;
}

void dsm_blk_unlock(unsigned long flags)
{
    spin_unlock_irqrestore(&g_dsm_blk_cb.lock, flags);
}

static int __init dsm_blk_init(void)
{
    if (g_dsm_blk_cb.blk_dclient != NULL) {
        pr_warn("dsm_blk client has been registered\n");
        return -EBUSY;
    }

    spin_lock_init(&g_dsm_blk_cb.lock);

    g_dsm_blk_cb.blk_dclient = dsm_register_client(&g_dsm_blk_dev);
    if (g_dsm_blk_cb.blk_dclient == NULL) {
        pr_err("register client for dsm_blk failed\n");
        return -EINVAL;
    }
    return 0;
}

module_init(dsm_blk_init);

#endif /* CONFIG_HUAWEI_BLOCK_DSM */