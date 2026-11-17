/*
 * test_result.h
 *
 * test result manager
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

#ifndef _TEST_RESULT_H_
#define _TEST_RESULT_H_

#include <linux/debugfs.h>
#include <linux/dcache.h>

struct test_result;
struct test_case;

struct test_result *test_alloc_result(struct test_case *tcase);
void test_report_once_result(struct test_result *result, int ret, uint64_t ticks);
void test_report_final_result(struct test_result *result, uint64_t totals);
void test_free_result(struct test_result *result);

#endif /* _TEST_RESULT_H_ */