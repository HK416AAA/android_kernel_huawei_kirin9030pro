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
#include <linux/random.h>
#include <linux/kernel.h>
#include "huawei_thp.h"
#include "screen_switch_adapter/huawei_screen_switch_adapter.h"

void get_random_number(unsigned int *random_num)
{
	*random_num = get_random_u32();
}

static void thp_screen_adapt_test(struct kunit *test)
{
	struct thp_core_data *cd = thp_get_core_data(MAIN_TOUCH_PANEL);
	unsigned int random_num;
	unsigned int test_count = 100;

	while (test_count--) {
		get_random_number(&random_num);
		pr_info("Random number: %u\n", random_num);
		if (random_num < 0 || random_num >= 3) {
			KUNIT_EXPECT_EQ(test, NULL, thp_screen_switch_adapt(random_num,random_num,random_num));
		} else if (random_num == SEQ0) {
			KUNIT_EXPECT_NE(test, NULL, thp_screen_switch_adapt(DUAL_THP,random_num,random_num));
		} else if (random_num == SEQ1) {
			cd->thp_tskit_fold_scheme = LCD_SEQ0;
			KUNIT_EXPECT_NE(test, NULL, thp_screen_switch_adapt(THP_TSKIT,random_num,random_num));
		} else if (random_num == SEQ2) {
			cd->thp_tskit_fold_scheme = LCD_SEQ1;
			KUNIT_EXPECT_NE(test, NULL, thp_screen_switch_adapt(THP_TSKIT,random_num,random_num));
		}
	}
}

static void screen_adapter_release_test(struct kunit *test)
{
	struct screen_switch_adapter* screen_adapter = kzalloc(sizeof(struct screen_switch_adapter), GFP_KERNEL);
	if (!screen_adapter) {
        thp_log_err("failed to kzalloc screen_adapter\n");
        return;
    }
	screen_adapter->ops = kzalloc(sizeof(struct thp_screen_ops), GFP_KERNEL);
	if (!screen_adapter->ops) {
        thp_log_err("failed to kzalloc screen_adapter->ops\n");
		kfree(screen_adapter);
		screen_adapter = NULL;
        return;
    }

	KUNIT_EXPECT_NE(test, NULL, screen_adapter);
	KUNIT_EXPECT_NE(test, NULL, screen_adapter->ops);
	screen_switch_adapter_release(screen_adapter);
	KUNIT_EXPECT_EQ(test, NULL, screen_adapter);
	KUNIT_EXPECT_EQ(test, NULL, screen_adapter->ops);
	return;
}

static struct kunit_case screen_adapter_test_cases[] = {
	KUNIT_CASE(thp_screen_adapt_test),
	KUNIT_CASE(screen_adapter_release_test),
	{}
};

static struct kunit_suite screen_adapter_test_suite = {
	.name = "screen_adapter_test_suite",
	.test_cases = screen_adapter_test_cases,
};

kunit_test_suite(screen_adapter_test_suite);
MODULE_LICENSE("GPL");