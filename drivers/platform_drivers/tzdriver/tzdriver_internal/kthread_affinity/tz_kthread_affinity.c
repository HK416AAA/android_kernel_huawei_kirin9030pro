/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2022. All rights reserved.
 * Description: function for set kthread affinity.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "tz_kthread_affinity.h"
#include <linux/cpumask.h>
#include <linux/version.h>
#include <linux/workqueue.h>
#include "tc_ns_log.h"
#include "tc_current_info.h"
#include "ko_adapt.h"
#include "tz_kthread_cpumask.h"

static struct cpumask g_kthread_cpumask;

void init_kthread_cpumask(void)
{
	int ret;

	cpumask_clear(&g_kthread_cpumask);

	ret = get_kthread_cpumask(&g_kthread_cpumask);
	if (ret < 0)
		tlogi("cannot get kthread cpumask\n");
}

void tz_kthread_bind_mask(struct task_struct *kthread)
{
	if (!kthread)
		return;

	if (cpumask_empty(&g_kthread_cpumask))
		return;

	koadpt_kthread_bind_mask(kthread, &g_kthread_cpumask);
}

void tz_workqueue_bind_mask(struct workqueue_struct *wq, uint32_t flag)
{
	int ret;
	struct workqueue_attrs *attrs = NULL;

	if (!wq)
		return;

	if (cpumask_empty(&g_kthread_cpumask))
		return;

	attrs = koadpt_alloc_workqueue_attrs(GFP_KERNEL);
	if (!attrs) {
		tloge("alloc workqueue attrs failed\n");
		return;
	}
	attrs->nice = (flag & WQ_HIGHPRI) ? MIN_NICE : 0;
#if (KERNEL_VERSION(6, 6, 0) <= LINUX_VERSION_CODE)
	attrs->ordered = true;
#else
	attrs->no_numa = true;
#endif
	cpumask_copy(attrs->cpumask, &g_kthread_cpumask);

	ret = apply_workqueue_attrs(wq, attrs);
	if (ret != 0)
		tloge("apply workqueue attrs failed %d\n", ret);
	koadpt_free_workqueue_attrs(attrs);
}
