/*
 * test_case.c
 *
 * test case manager
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

#include "test_case.h"
#include <linux/idr.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/timex.h>
#include <securec.h>
#include "test_system.h"
#include "test_result.h"

#define TEST_CASE_DIR_LEN 32

#define state_to_string(state) #state

struct test_case_pool {
	struct idr cases;
	spinlock_t case_lock;
};

struct test_case_pool *test_create_case_pool(void)
{
	struct test_case_pool *pool = NULL;

	pool = kzalloc(sizeof(*pool), GFP_KERNEL);
	if (!pool)
		return NULL;

	spin_lock_init(&pool->case_lock);
	idr_init(&pool->cases);
	return pool;
}

static int test_insert_case(struct test_case_pool *pool,
	struct test_case *tcase, int id)
{
	int ret;

	spin_lock(&pool->case_lock);
	ret = idr_alloc(&pool->cases, tcase, id, id + 1, GFP_KERNEL);
	spin_unlock(&pool->case_lock);
	if (ret < 0) {
		pr_err("%s idr_alloc fail ret=%d\n", __func__, ret);
		return ret;
	}

	tcase->id = ret;
	return 0;
}

static void test_remove_case(struct test_case_pool *pool, int id)
{
	spin_lock(&pool->case_lock);
	idr_remove(&pool->cases, id);
	spin_unlock(&pool->case_lock);
}

static struct dentry *test_create_case_dir(struct test_case *tcase,
	struct test_func *func)
{
	int ret;
	struct dentry *parent = test_get_func_dir(func);
	char case_dir_name[TEST_CASE_DIR_LEN] = {0};

	if (!parent)
		return NULL;

	ret = snprintf_s(case_dir_name, TEST_CASE_DIR_LEN,
		TEST_CASE_DIR_LEN - 1, "%d", tcase->id);
	if (ret < 0) {
		pr_err("%s snprintf_s fail\n", __func__);
		return NULL;
	}
	case_dir_name[TEST_CASE_DIR_LEN - 1] = '\0';
	return debugfs_create_dir(case_dir_name, parent);
}

static void test_set_case_fin(struct test_case *tcase)
{
	struct test_system *sys = test_get_system();

	if (!sys)
		return;

	tcase->state = TCASE_FIN;
	test_move_case(sys->active_cases, sys->inactive_cases, tcase);
}

static void test_run_case_work(struct test_case *tcase)
{
	int i;
	int tmp_ret;
	struct test_context *ctx = &tcase->context;
	ktime_t kstart, k1;

	if (test_setup_context(ctx) != 0) {
		test_report_once_result(tcase->result, -EAGAIN, 0);
		test_report_final_result(tcase->result, 0);
		return;
	}

	tcase->state = TCASE_RUN;
	kstart = ktime_get();
	for (i = 0; i < ctx->run_loops; i++) {
		k1 = ktime_get();
		tmp_ret = test_run_func(tcase->context.func,
			ctx->sub_context, ctx->args);
		test_report_once_result(tcase->result, tmp_ret,
			ktime_us_delta(ktime_get(), k1));
	}
	test_report_final_result(tcase->result,
		ktime_us_delta(ktime_get(), kstart));
	test_set_case_fin(tcase);
	test_teardown_context(ctx);
}

static int test_start_case(void *data, u64 val)
{
	struct test_case *tcase = data;

	mutex_lock(&tcase->lock);
	if (tcase->state != TCASE_WAIT)
		goto ulock_case;

	test_run_case_work(tcase);

ulock_case:
	mutex_unlock(&tcase->lock);
	return 0;
}
DEFINE_DEBUGFS_ATTRIBUTE(test_start_case_fops,
	NULL, test_start_case, "%llu\n");

static int test_delete_case(void *data, u64 val)
{
	struct test_case *tcase = data;

	mutex_lock(&tcase->lock);
	if (tcase->state == TCASE_FIN) {
		tcase->state = TCASE_DEL;
	} else if (tcase->state == TCASE_WAIT ||
		tcase->state == TCASE_RUN) {
		test_set_case_fin(tcase);
		tcase->state = TCASE_DEL;
	}
	mutex_unlock(&tcase->lock);
	test_try_reclaim_case();
	return 0;
}
DEFINE_DEBUGFS_ATTRIBUTE(test_delete_case_fops,
	NULL, test_delete_case, "%llu\n");

static const char *test_case_string_state[] = {
	state_to_string(TCASE_WAIT),
	state_to_string(TCASE_RUN),
	state_to_string(TCASE_FIN),
	state_to_string(TCASE_DEL),
};

static ssize_t test_get_case_state(struct file *file, char __user *user_buf,
	size_t count, loff_t *ppos)
{
	struct test_case *tcase = file->private_data;
	int len;
	int ret;

	mutex_lock(&tcase->lock);
	if ((tcase->state < TCASE_WAIT) || (tcase->state >= TCASE_MAX)) {
		mutex_unlock(&tcase->lock);
		return -EINVAL;
	}

	len = strlen(test_case_string_state[tcase->state]) + 1;
	ret = simple_read_from_buffer(user_buf, count, ppos,
		test_case_string_state[tcase->state], len);
	mutex_unlock(&tcase->lock);
	return ret;
}

static const struct file_operations test_case_state_fops = {
	.read = test_get_case_state,
	.open = simple_open,
	.llseek = default_llseek,
};

#define test_seq_printf_result_int(param) \
	seq_printf(s, "%s=%d\n", #param, tcase->result->param)

#define test_seq_printf_result_u64(param) \
	seq_printf(s, "%s=%llu\n", #param, tcase->result->param)

static int test_case_info_show(struct seq_file *s, void *what)
{
	struct test_case *tcase = s->private;
	struct test_object *obj = test_get_func_obj(tcase->context.func);

	mutex_lock(&tcase->lock);
	seq_printf(s, "object=%s\n", test_get_obj_name(obj));
	seq_printf(s, "func=%s\n", test_get_func_name(tcase->context.func));
	mutex_unlock(&tcase->lock);
	return 0;
}
DEFINE_SHOW_ATTRIBUTE(test_case_info);

static void test_create_case_file(struct test_case *tcase)
{
	debugfs_create_file("start", 0200,
		tcase->dir, tcase, &test_start_case_fops);
	debugfs_create_file("delete", 0200,
		tcase->dir, tcase, &test_delete_case_fops);
	debugfs_create_file("state", 0400,
		tcase->dir, tcase, &test_case_state_fops);
	debugfs_create_file("info", 0400,
		tcase->dir, tcase, &test_case_info_fops);
}

static int test_init_case(struct test_case *tcase, struct test_func *func)
{
	int ret;

	tcase->dir = test_create_case_dir(tcase, func);
	if (!tcase->dir) {
		pr_err("%s create case dir fail\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&tcase->lock);
	test_create_case_file(tcase);

	ret = test_init_context(&tcase->context, func, tcase->dir);
	if (ret != 0) {
		pr_err("%s int case context fail\n", __func__);
		goto init_context_fail;
	}

	tcase->result = test_alloc_result(tcase);
	if (!tcase->result) {
		pr_err("%s create case result fail\n", __func__);
		ret = -ENOMEM;
		goto alloc_result_fail;
	}
	return 0;

alloc_result_fail:
	test_deinit_context(&tcase->context);
init_context_fail:
	debugfs_remove_recursive(tcase->dir);
	mutex_destroy(&tcase->lock);
	return ret;
}

static void test_deinit_case(struct test_case *tcase)
{
	test_deinit_context(&tcase->context);

	test_free_result(tcase->result);
	tcase->result = NULL;

	if (!tcase->dir)
		return;
	debugfs_remove_recursive(tcase->dir);
	mutex_destroy(&tcase->lock);
	pr_info("%s deinit case %d\n", __func__, tcase->id);
}

int test_alloc_case(struct test_case_pool *pool, int id,
	struct test_func *func)
{
	struct test_case *tcase = NULL;
	struct test_system *sys = test_get_system();

	if (!pool || !sys || !func)
		return -EINVAL;

	tcase = kzalloc(sizeof(*tcase), GFP_KERNEL);
	if (!tcase)
		return -ENOMEM;

	if (test_insert_case(pool, tcase, id) < 0)
		goto insert_case_fail;

	BUG_ON(tcase->id != id);

	if (tcase->id > sys->max_case_id)
		sys->max_case_id = tcase->id;

	if (test_init_case(tcase, func) != 0)
		goto init_case_fail;
	return 0;

init_case_fail:
	test_remove_case(pool, tcase->id);
insert_case_fail:
	kfree(tcase);
	return -ENOMEM;
}

struct test_case *test_find_case(struct test_case_pool *pool, int id)
{
	struct test_case *tcase = NULL;

	if (!pool)
		return NULL;

	spin_lock(&pool->case_lock);
	tcase = idr_find(&pool->cases, id);
	spin_unlock(&pool->case_lock);
	return tcase;
}

void test_free_case(struct test_case_pool *pool, struct test_case *tcase)
{
	if (!pool || !tcase)
		return;

	test_remove_case(pool, tcase->id);
	test_deinit_case(tcase);
	kfree(tcase);
}

int test_move_case(struct test_case_pool *old, struct test_case_pool *new,
	struct test_case *tcase)
{
	int id;

	if (!old || !new || !tcase)
		return -EINVAL;

	id = tcase->id;

	if (test_insert_case(new, tcase, id) < 0)
		return -EINVAL;

	BUG_ON(tcase->id != id);
	test_remove_case(old, tcase->id);
	return 0;
}

void test_del_unuse_case(struct test_case_pool *pool)
{
	struct test_case *tcase = NULL;
	struct idr *idp = NULL;
	int id;

	if (!pool)
		return;
	idp = &pool->cases;

	idr_for_each_entry(idp, tcase, id) {
		if ((tcase == NULL) || (tcase->state != TCASE_DEL))
			continue;
		test_free_case(pool, tcase);
	}
}

void test_destroy_case_pool(struct test_case_pool *pool)
{
	struct test_case *tcase = NULL;
	struct idr *idp = NULL;
	int id;

	if (!pool)
		return;
	idp = &pool->cases;

	idr_for_each_entry(idp, tcase, id) {
		if (tcase != NULL) {
			test_deinit_case(tcase);
			kfree(tcase);
		}
	}
	idr_destroy(&pool->cases);
	kfree(pool);
}
