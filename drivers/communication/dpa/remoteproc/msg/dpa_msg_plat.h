/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2020. All rights reserved.
 */

#ifndef _DPA_MSG_PLAT_H
#define _DPA_MSG_PLAT_H

#include <linux/types.h>
#include <linux/kthread.h>  /* struct task_struct */
#include "bsp_dpa_msg.h"
#include "bsp_print.h"
#include "securec.h"
#include "bsp_diag.h"
// platform definition
#define THIS_CORE DPA_MSG_CORE_APP
#define THIS_MODU mod_dpa_msg
#define dpa_msg_crit(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_msg_err(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_msg_warn(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_msg_print(fmt, ...)
#define dpa_msg_always(fmt, ...) dpa_pr_err(fmt, ##__VA_ARGS__)
#define dpa_msg_trace(fmt, ...)
#define dpa_msg_print_diag_report(fmt, ...) bsp_dpa_diag_trans_report(fmt, ##__VA_ARGS__)

#define dpa_msg_roundup(x, n) (((x) + (n)-1) & (~((n)-1)))

static inline unsigned int dpa_msg_get_slice_value(void)
{
    return 0;
}

#endif
