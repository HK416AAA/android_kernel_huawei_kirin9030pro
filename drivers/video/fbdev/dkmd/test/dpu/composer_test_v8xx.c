/**
 * @file composer_test.c
 * @brief test unit for composer
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "kunit.h"
#include "stub.h"
#include "dkmd_comp.h"
#include "gfxdev_mgr.h"
#include "dpu_config_utils.h"
#include "dkmd_alsc_interface.h"
#ifdef CONFIG_BUILD_TESTCASE_SUITE
#include "testcases.h"
#endif
#include "lbuf_mgr_v8xx.h"
#include "res_mgr.h"

/**
 * @brief Test the following interface
 *    dpu_config_get_scf_lut_addr_tlb
 *    dpu_config_get_arsr_lut_addr_tlb
 *
 */
static void test_dpu_config_itf(void)
{
	int32_t length = 0;
	uint32_t *lut_addr_tlb = NULL;

	lut_addr_tlb = dpu_config_get_scf_lut_addr_tlb(&length);
	CHECK_PTR_NOT_NULL(lut_addr_tlb);
	CHECK_NOT_EQUAL(length, 0);

	lut_addr_tlb = NULL;
	length = 0;
	lut_addr_tlb = dpu_config_get_arsr_lut_addr_tlb(&length);
	CHECK_PTR_NOT_NULL(lut_addr_tlb);
	CHECK_NOT_EQUAL(length, 0);
}

/**
 * @brief Test the following interface
 *    dkmd_alsc_enable
 *    dkmd_alsc_disable
 *    dkmd_alsc_update_bl_param
 *    dkmd_alsc_update_degamma_coef
 *    dkmd_alsc_register_cb_func
 *
 */
static void test_dkmd_alsc_itf(void)
{
	struct dkmd_alsc *alsc = NULL;

	alsc = (struct dkmd_alsc *)kzalloc(sizeof(struct dkmd_alsc), GFP_KERNEL);
	CHECK_NOT_EQUAL(dkmd_alsc_param_init(NULL, 0), 0);
	CHECK_EQUAL(dkmd_alsc_param_init(alsc, 0), 0);

	CHECK_NOT_EQUAL(dkmd_alsc_update_bl_param(NULL, 0), 0);
	CHECK_EQUAL(dkmd_alsc_update_bl_param(&alsc->bl_param, 0), 0);

	CHECK_NOT_EQUAL(dkmd_alsc_update_degamma_coef(NULL, 0), 0);
	CHECK_EQUAL(dkmd_alsc_update_degamma_coef(&alsc->degamma_coef, 0), 0);

	CHECK_NOT_EQUAL(dkmd_alsc_register_cb_func(NULL, NULL), 0);
	kfree(alsc);
	alsc = NULL;
}

static void test_set_lb_request_num(struct req_lbuf_info *lb_info, uint32_t lb0, uint32_t lb1, uint32_t lb3)
{
	lb_info->part_num = 3;
	lb_info->req_part_info[0].part_id = 0;
	lb_info->req_part_info[0].used_lb = lb0;
	lb_info->req_part_info[1].part_id = 1;
	lb_info->req_part_info[1].used_lb = lb1;
	lb_info->req_part_info[2].part_id = 3;
	lb_info->req_part_info[2].used_lb = lb3;
}

static void test_lbuf_mgr_itf0(void)
{
	struct dpu_lbuf_mgr *lbuf_mgr = NULL;
	struct req_lbuf_info lb_info = {0};
	uint32_t max_lb0 = PART0_LB_NUM_MAX - LB0_RSERVED_NUM_SCENEALL - LB0_RSERVED_NUM_SCENE4;
	uint32_t max_lb1 = ((g_dpu_config_data.version.info.soc_type == DPU_SOC_TYPE_CS) ?
		PART1_LB_NUM_FOR_FREQ_CONSTRAINT : PART1_LB_NUM_FOR_FREQ_CONSTRAINT_ES) - LB1_RSERVED_NUM_SCENE4;
	uint32_t max_lb2 = PART2_LB_NUM_MAX;
	uint32_t max_lb3 = PART3_LB_NUM_MAX - LB3_RSERVED_NUM_SCENE4;

	lbuf_mgr = (struct dpu_lbuf_mgr *)lbuf_mgr_init(NULL);
	CHECK_NOT_EQUAL(lbuf_mgr, NULL);
	CHECK_EQUAL(lbuf_mgr->part_num, LBUF_PART_NUM_MAX);
	CHECK_NOT_EQUAL(lbuf_mgr->lb_part_info, NULL);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].max_lb, max_lb0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].max_lb, max_lb1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].max_lb, max_lb2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].max_lb, max_lb3);

	lb_info.user_type = SCENE_USER_HDM;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.opt = LB_REQUEST;
	test_set_lb_request_num(&lb_info, 6, 2, 16);

	lb_info.user_type = SCENE_USER_MAX;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.user_type = SCENE_USER_HDM;

	lb_info.scene_id = DPU_SCENE_MAX;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.scene_id = DPU_SCENE_ONLINE_0;

	lb_info.opt = 255;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.opt = LB_REQUEST;

	lb_info.part_num = 255;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.part_num = 3;

	lb_info.req_part_info[0].part_id = 255;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.req_part_info[0].part_id = 0;

	lb_info.req_part_info[0].used_lb = 255;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	lb_info.req_part_info[0].used_lb = 6;

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lb_info.opt = LB_RELEASE;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 0);

	lbuf_mgr_deinit(lbuf_mgr);
}

static void test_lbuf_mgr_itf1(void)
{
	struct dpu_lbuf_mgr *lbuf_mgr = NULL;
	struct req_lbuf_info lb_info = {0};
	uint32_t max_lb0 = PART0_LB_NUM_MAX - LB0_RSERVED_NUM_SCENEALL - LB0_RSERVED_NUM_SCENE4;
	uint32_t max_lb1 = ((g_dpu_config_data.version.info.soc_type == DPU_SOC_TYPE_CS) ?
		PART1_LB_NUM_FOR_FREQ_CONSTRAINT : PART1_LB_NUM_FOR_FREQ_CONSTRAINT_ES) - LB1_RSERVED_NUM_SCENE4;
	uint32_t max_lb3 = PART3_LB_NUM_MAX - LB3_RSERVED_NUM_SCENE4;

	lbuf_mgr = (struct dpu_lbuf_mgr *)lbuf_mgr_init(NULL);
	CHECK_NOT_EQUAL(lbuf_mgr, NULL);

	lb_info.user_type = SCENE_USER_HDM;
	lb_info.scene_id = DPU_SCENE_ONLINE_2;
	lb_info.opt = LB_RESERVE;
	test_set_lb_request_num(&lb_info, 6, 1, 16);

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lb_info.opt = LB_REQUEST;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.req_part_info[0].used_lb = max_lb0 - 6 - 10;
	lb_info.req_part_info[1].used_lb = max_lb1 - 1 - 1;
	lb_info.req_part_info[2].used_lb = max_lb3 - 16 - 8;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0 - 10);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1 - 1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3 - 8);

	lb_info.opt = LB_RESERVE;
	lb_info.scene_id = DPU_SCENE_ONLINE_2;
	lb_info.req_part_info[0].used_lb = 6 + 10 + 5;
	lb_info.req_part_info[1].used_lb = 1 + 1 + 1;
	lb_info.req_part_info[2].used_lb = 16 + 8 + 6;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3);

	lb_info.opt = LB_REQUEST;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.req_part_info[0].used_lb = 5;
	lb_info.req_part_info[1].used_lb = 1;
	lb_info.req_part_info[2].used_lb = 6;
	CHECK_NOT_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3);

	lb_info.opt = LB_RELEASE;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.req_part_info[0].used_lb = 5 + 4;
	lb_info.req_part_info[1].used_lb = 1 + 1;
	lb_info.req_part_info[2].used_lb = 6 + 5;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0 - 5 - 4);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1 - 1 - 1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3 - 6 - 5);

	lb_info.opt = LB_RESERVE;
	lb_info.scene_id = DPU_SCENE_ONLINE_2;
	lb_info.req_part_info[0].used_lb = 6 + 10 + 5;
	lb_info.req_part_info[1].used_lb = 1 + 1 + 1;
	lb_info.req_part_info[2].used_lb = 16 + 8 + 6;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0 - 4);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1 - 1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3 - 5);

	lb_info.opt = LB_FREE_RESERVED;
	lb_info.scene_id = DPU_SCENE_ONLINE_2;
	lb_info.req_part_info[0].used_lb = 6 + 10 + 5;
	lb_info.req_part_info[1].used_lb = 1 + 1 + 1;
	lb_info.req_part_info[2].used_lb = 16 + 8 + 6;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0 - 4 - 21);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1 - 1 - 3);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3 - 5 - 30);

	lb_info.opt = LB_REQUEST;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.req_part_info[0].used_lb = 4 + 21;
	lb_info.req_part_info[1].used_lb = 1 + 3;
	lb_info.req_part_info[2].used_lb = 5 + 30;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3);

	lb_info.opt = LB_RELEASE;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.req_part_info[0].used_lb = 16;
	lb_info.req_part_info[1].used_lb = 3;
	lb_info.req_part_info[2].used_lb = 48;
	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, max_lb0 - 16);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, max_lb1 - 3);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, max_lb3 - 48);

	lbuf_mgr_deinit(lbuf_mgr);
}

static void test_lbuf_mgr_itf2(void)
{
	struct dpu_lbuf_mgr *lbuf_mgr = NULL;
	struct req_lbuf_info lb_info = {0};

	lbuf_mgr = (struct dpu_lbuf_mgr *)lbuf_mgr_init(NULL);
	CHECK_NOT_EQUAL(lbuf_mgr, NULL);

	lb_info.user_type = SCENE_USER_HDM;
	lb_info.scene_id = DPU_SCENE_ONLINE_2;
	lb_info.opt = LB_RESERVE;
	test_set_lb_request_num(&lb_info, 6, 2, 16);

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lbuf_mgr_release(lbuf_mgr);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 0);

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lbuf_mgr_reset(lbuf_mgr);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 0);

	lbuf_mgr_deinit(lbuf_mgr);
}

static void test_lbuf_mgr_itf3(void)
{
	struct dpu_lbuf_mgr *lbuf_mgr = NULL;
	struct req_lbuf_info lb_info = {0};

	lbuf_mgr = (struct dpu_lbuf_mgr *)lbuf_mgr_init(NULL);
	CHECK_NOT_EQUAL(lbuf_mgr, NULL);

	lb_info.user_type = SCENE_USER_HDM;
	lb_info.scene_id = DPU_SCENE_ONLINE_0;
	lb_info.opt = LB_REQUEST;
	test_set_lb_request_num(&lb_info, 6, 2, 16);

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lbuf_mgr_release(lbuf_mgr);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 0);

	CHECK_EQUAL(lbuf_mgr_handle_lb_opt(lbuf_mgr, &lb_info), 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 6);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 2);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 16);

	lbuf_mgr_reset(lbuf_mgr);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[0].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[1].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[2].used_lb, 0);
	CHECK_EQUAL(lbuf_mgr->lb_part_info[3].used_lb, 0);

	lbuf_mgr_deinit(lbuf_mgr);
}

ku_test_info composer_test[] = {
	{ "test_dpu_config_itf", test_dpu_config_itf },
	{ "test_dkmd_alsc_itf", test_dkmd_alsc_itf },
	{ "test_lbuf_mgr_itf0", test_lbuf_mgr_itf0 },
	{ "test_lbuf_mgr_itf1", test_lbuf_mgr_itf1 },
	{ "test_lbuf_mgr_itf2", test_lbuf_mgr_itf2 },
	{ "test_lbuf_mgr_itf3", test_lbuf_mgr_itf3 },
	KU_TEST_INFO_NULL
};

int32_t composer_test_suite_init(void)
{
	pr_info("composer_test device init!\n");
	return 0;
}

int32_t composer_test_suite_clean(void)
{
	pr_info("composer_test device deinit!\n");
	return 0;
}

#ifndef CONFIG_BUILD_TESTCASE_SUITE
ku_suite_info composer_test_suites[]= {
	{"composer_test_init", composer_test_suite_init, composer_test_suite_clean, composer_test, KU_TRUE},
	KU_SUITE_INFO_NULL
};

static int32_t composer_test_init(void)
{
	pr_info("+++++++++++++++++++++++++ hello, composer_test kunit +++++++++++++++++++++++!\n");

	run_all_tests(composer_test_suites,"/data/log/composer_test");
	return 0;
}

static void composer_test_exit(void)
{
	pr_info("----------------------- bye, composer_test kunit --------------------!\n");
}

module_init(composer_test_init);
module_exit(composer_test_exit);

#endif

MODULE_LICENSE("GPL");