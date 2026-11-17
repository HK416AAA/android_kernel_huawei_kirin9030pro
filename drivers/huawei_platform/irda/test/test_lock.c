/*
 * test_lock.c
 *
 * test lock
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

#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>
#include <linux/atomic.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/rwlock.h>
#include <linux/seqlock.h>
#include <linux/kernel.h>
#include "test_system.h"

#define TEST_LOCK_OBJ_NAME "lock"
#define TEST_ATOMIC_INIT_VALUE 1000

struct test_lock_context {
	u32 count;
	struct mutex mlock;
	spinlock_t slock;
	struct rw_semaphore rw_sem;
	rwlock_t rw_lock;
	seqlock_t seq_lock;
	atomic_t usages;
};

static void *test_lock_setup(struct dentry *dir)
{
	struct test_lock_context *ctx = NULL;

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return NULL;

	spin_lock_init(&ctx->slock);
	mutex_init(&ctx->mlock);
	init_rwsem(&ctx->rw_sem);
	rwlock_init(&ctx->rw_lock);
	seqlock_init(&ctx->seq_lock);
	atomic_set(&ctx->usages, TEST_ATOMIC_INIT_VALUE);
	return ctx;
}

static void test_lock_teardown(void *sub_context)
{
	struct test_lock_context *ctx = sub_context;

	if (!sub_context)
		return;
	mutex_destroy(&ctx->mlock);
	kfree(ctx);
}

static int test_mutex(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	mutex_lock(&ctx->mlock);
	ctx->count++;
	mutex_unlock(&ctx->mlock);
	return 0;
}

static int test_spin_lock(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	spin_lock(&ctx->slock);
	ctx->count++;
	spin_unlock(&ctx->slock);
	return 0;
}

static int test_spin_lock_irq(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	spin_lock_irq(&ctx->slock);
	ctx->count++;
	spin_unlock_irq(&ctx->slock);
	return 0;
}

static int test_spin_lock_irq_save(void *context, void *args)
{
	struct test_lock_context *ctx = context;
	unsigned long flags;

	if (!ctx)
		return -EINVAL;

	spin_lock_irqsave(&ctx->slock, flags);
	ctx->count++;
	spin_unlock_irqrestore(&ctx->slock, flags);
	return 0;
}

static int test_atomic_inc(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	atomic_inc(&ctx->usages);
	ctx->count = atomic_read(&ctx->usages);
	return 0;
}

static int test_atomic_dec(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	if (atomic_dec_and_test(&ctx->usages))
		atomic_set(&ctx->usages, TEST_ATOMIC_INIT_VALUE);

	return 0;
}

static int test_sem_read(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	down_read(&ctx->rw_sem);
	ctx->count++;
	up_read(&ctx->rw_sem);
	return 0;
}

static int test_sem_write(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	down_write(&ctx->rw_sem);
	ctx->count++;
	up_write(&ctx->rw_sem);
	return 0;
}

static int test_rwlock_read(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	read_lock(&ctx->rw_lock);
	ctx->count++;
	read_unlock(&ctx->rw_lock);
	return 0;
}

static int test_rwlock_write(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	write_lock(&ctx->rw_lock);
	ctx->count++;
	write_unlock(&ctx->rw_lock);
	return 0;
}

static int test_seqlock_read(void *context, void *args)
{
	struct test_lock_context *ctx = context;
	unsigned int seq;

	if (!ctx)
		return -EINVAL;

	do {
		seq = read_seqbegin(&ctx->seq_lock);
		ctx->count++;
	} while (read_seqretry(&ctx->seq_lock, seq));
	return 0;
}

static int test_seqlock_write(void *context, void *args)
{
	struct test_lock_context *ctx = context;

	if (!ctx)
		return -EINVAL;

	write_seqlock(&ctx->seq_lock);
	ctx->count++;
	write_sequnlock(&ctx->seq_lock);
	return 0;
}

static int __init test_lock_init(void)
{
	test_object(TEST_LOCK_OBJ_NAME, test_lock_setup,
		test_lock_teardown);
	test_f(TEST_LOCK_OBJ_NAME, "mutex",
		test_mutex);
	test_f(TEST_LOCK_OBJ_NAME, "spin_lock",
		test_spin_lock);
	test_f(TEST_LOCK_OBJ_NAME, "spin_lock_irq",
		test_spin_lock_irq);
	test_f(TEST_LOCK_OBJ_NAME, "spin_lock_irq_save",
		test_spin_lock_irq_save);
	test_f(TEST_LOCK_OBJ_NAME, "atomic_inc",
		test_atomic_inc);
	test_f(TEST_LOCK_OBJ_NAME, "atomic_dec",
		test_atomic_dec);
	test_f(TEST_LOCK_OBJ_NAME, "sem_read",
		test_sem_read);
	test_f(TEST_LOCK_OBJ_NAME, "sem_write",
		test_sem_write);
	test_f(TEST_LOCK_OBJ_NAME, "rwlock_read",
		test_rwlock_read);
	test_f(TEST_LOCK_OBJ_NAME, "rwlock_write",
		test_rwlock_write);
	test_f(TEST_LOCK_OBJ_NAME, "seqlock_read",
		test_seqlock_read);
	test_f(TEST_LOCK_OBJ_NAME, "seqlock_write",
		test_seqlock_write);
	return 0;
}

static void __exit test_lock_deinit(void)
{
}

module_init(test_lock_init);
module_exit(test_lock_deinit);