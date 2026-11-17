/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description:  mas block flush reduce interface
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

#include <linux/kthread.h>
#ifdef CONFIG_DFX_SH_TBC
#include <platform_include/cee/linux/sr.h>
#endif
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/module.h>
#include <linux/init.h>
#include "dfx_sh_core.h"


static struct task_struct *g_sh_thread;

int __cfi_sh_thread_body(void *arg)
{
    return sh_thread_body(arg);
}

static int __init sh_init(void)
{
	sh_wakeup_source_register();
	g_sh_thread = kthread_run(__cfi_sh_thread_body, NULL, "sh_thread");
	if (g_sh_thread == NULL) {
		sh_wakeup_source_unregister();
		pr_err("create sh thread failed\n");
		return -EINVAL;
	}
#ifdef CONFIG_DFX_SH_TBC
	sh_tbc_init();
#endif
	return 0;
}

static void __exit sh_exit(void)
{
	if (g_sh_thread != NULL)
		kthread_stop(g_sh_thread);
#ifdef CONFIG_DFX_SH_TBC
	sh_del_timer();
#endif
}

late_initcall(sh_init);
module_exit(sh_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("DFX_SH MODULE");