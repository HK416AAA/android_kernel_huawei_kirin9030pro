/*
 * Huawei Touchscreen Driver
 *
 * Copyright (c) 2024-2024 Huawei Technologies Co., Ltd.
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
#include <kunit/test.h>
#include "power_adapter/power_platform_resource.h"
#include "huawei_thp.h"
#include "power_adapter/tdev_power_func.h"
#include "power_adapter/power_adapter.h"
#include <linux/random.h>
#include <linux/kernel.h>

void get_random_number(unsigned int *random_num)
{
	*random_num = get_random_u32();
}

static void thp_power_adapt_test(struct kunit *test)
{
	unsigned int random_num;
	unsigned int test_count = 100;
	// 进行测试的代码逻辑
	while (test_count--) {
		get_random_number(&random_num);
		pr_info("Random number: %u\n", random_num);
		if (random_num >= 3) {
			KUNIT_EXPECT_EQ(test, NULL, thp_power_adapt(random_num));
		} else if (random_num == USE_INDEPENDENT_POWER) {
			KUNIT_EXPECT_NE(test, NULL, thp_power_adapt(USE_INDEPENDENT_POWER));
		} else if (random_num == MULTI_PANEL_USE_SINGEL_POWER) {
			KUNIT_EXPECT_NE(test, NULL, thp_power_adapt(MULTI_PANEL_USE_SINGEL_POWER));
		} else if (random_num == TP_USE_TDDI_POWER) {
			KUNIT_EXPECT_NE(test, NULL, thp_power_adapt(TP_USE_TDDI_POWER));
		}
	}
}

static void power_adapter_release_test(struct kunit *test)
{
	struct thp_power_adapter* power_adapter = kzalloc(sizeof(struct thp_power_adapter), GFP_KERNEL);
	power_adapter->ops = kzalloc(sizeof(struct thp_power_ops), GFP_KERNEL);

	KUNIT_EXPECT_NE(test, NULL, power_adapter);
	KUNIT_EXPECT_NE(test, NULL, power_adapter->ops);
	thp_power_adapter_release(&power_adapter);
	KUNIT_EXPECT_EQ(test, NULL, power_adapter);
	KUNIT_EXPECT_EQ(test, NULL, power_adapter->ops);
	return;
}

static struct kunit_case power_adapter_test_cases[] = {
	KUNIT_CASE(thp_power_adapt_test),
	KUNIT_CASE(power_adapter_release_test),
	{}
};

static struct kunit_suite power_adapter_test_suite = {
	.name = "power_adapter_test_suite",
	.test_cases = power_adapter_test_cases,
};

kunit_test_suite(power_adapter_test_suite);
MODULE_LICENSE("GPL");