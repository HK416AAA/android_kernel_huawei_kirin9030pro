/*
 * test_system.c
 *
 * test system
 *
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include "test_system.h"
#include <linux/slab.h>
#include "test_case.h"

#define TEST_ROOT_DIR "kapi_test"

static struct test_system *g_tsys;

static void test_del_case_work(struct work_struct *work)
{
	struct test_system *sys = test_get_system();

	if (!sys)
		return;

	mutex_lock(&sys->dlock);
	pr_err("%s: before del unuse case\n", __func__);
	test_del_unuse_case(sys->inactive_cases);
	pr_err("%s: after del unuse case\n", __func__);
	mutex_unlock(&sys->dlock);
}

void test_try_reclaim_case(void)
{
	cancel_delayed_work_sync(&g_tsys->del_work);
	schedule_delayed_work(&g_tsys->del_work, msecs_to_jiffies(10));
}

static int test_init_system(struct test_system *sys)
{
	sys->active_cases = test_create_case_pool();
	if (!sys->active_cases) {
		pr_err("%s: create test active cases fail\n", __func__);
		return -ENOMEM;
	}

	sys->inactive_cases = test_create_case_pool();
	if (!sys->inactive_cases) {
		test_destroy_case_pool(sys->active_cases);
		sys->active_cases = NULL;
		pr_err("%s: create test inactive cases fail\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&sys->olock);
	mutex_init(&sys->dlock);
	sys->objects = RB_ROOT;
	sys->root_dir = debugfs_create_dir(TEST_ROOT_DIR, NULL);
	debugfs_create_x32("max_case_id", 0400, sys->root_dir,
		&sys->max_case_id);
	INIT_DELAYED_WORK(&sys->del_work, test_del_case_work);
	return 0;
}

struct test_system *test_get_system(void)
{
	struct test_system *sys = NULL;

	if (g_tsys)
		return g_tsys;

	sys = kzalloc(sizeof(*sys), GFP_KERNEL);
	if (!sys)
		return NULL;

	if (test_init_system(sys) != 0) {
		kfree(sys);
		return NULL;
	}
	g_tsys = sys;
	pr_info("%s: create test system\n", __func__);
	return g_tsys;
}