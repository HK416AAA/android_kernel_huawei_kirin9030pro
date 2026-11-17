/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description:
 * Miscellaneous little independent features, which don't worth a single file.
 */
#ifndef __SCHED_MISC_H
#define __SCHED_MISC_H

#ifdef CONFIG_GICD_MISS_PPI_WAKE_REQ_WORKAROUND
void check_gic_missed_wakeup(void);
#endif

#ifdef CONFIG_SCHED_DFX
extern unsigned int sched_dfx_report_preempt_off;
extern unsigned int sched_dfx_report_period;
void sched_dfx_report_long_preempt_off(long delta);
#endif

#ifdef CONFIG_SCHED_SETSCHEDULER_EXTEND_CUSTOM_EVENT
bool sched_setscheduler_handle_extended_user_event(int event, int *ret);
#endif

#endif
