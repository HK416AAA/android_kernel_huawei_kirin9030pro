/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef __DEVFREQ_PERF_CTRL_H
#define __DEVFREQ_PERF_CTRL_H

#if defined(CONFIG_DEVFREQ_GOV_MEMLAT_SET_IMMUTABLE_FLAG) && \
	defined(CONFIG_HUAWEI_DEV_PERF_CTRL)
extern void memlat_set_immutable_flag(unsigned int flag);
int perf_ctrl_set_memlat_immutable_flag(void __user *uarg);
#else
static inline int perf_ctrl_set_memlat_immutable_flag(void __user *uarg)
{
	return -ENODEV;
}
#endif

#endif
