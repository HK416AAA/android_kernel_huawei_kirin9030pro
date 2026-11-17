/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */

#include <linux/regulator/consumer.h>
#include "aae_res_mgr.h"
#include "akmd_log.h"
#include "tcu_power_mgr.h"

static int32_t do_tcu_power_on(struct aae_res_mgr *rm_dev)
{
	int32_t ret = 0;
	ret = regulator_enable(rm_dev->media1_subsys_regulator);
	if (ret)
		aae_pr_err("regulator enable media1_subsys failed, error=%d!", ret);

	ret = regulator_enable(rm_dev->vivobus_regulator);
	if (ret)
		aae_pr_err("regulator enable vivobus failed, error=%d!", ret);

	return ret;
}
 
static void do_tcu_power_off(struct aae_res_mgr *rm_dev)
{
	int32_t ret = 0;

	ret = regulator_disable(rm_dev->media1_subsys_regulator);
	if (ret)
		aae_pr_err("regulator enable media1_subsys failed, error=%d!", ret);

	ret = regulator_disable(rm_dev->vivobus_regulator);
	if (ret)
		aae_pr_err("regulator enable vivobus failed, error=%d!", ret);
}

bool tcu_ready_to_power_off(struct aae_res_mgr *rm_dev)
{
	bool ret = false;
	mutex_lock(&rm_dev->tcu_power_lock);
	ret = rm_dev->tcu_power_refcount == 1 ? true : false;
	mutex_unlock(&rm_dev->tcu_power_lock);

	return ret;
}

int32_t tcu_power_on_vote(struct aae_res_mgr *rm_dev)
{
	mutex_lock(&rm_dev->tcu_power_lock);
	if (rm_dev->tcu_power_refcount == 0 && rm_dev->tcu_power_status == 0) {
		(void)do_tcu_power_on(rm_dev);
		rm_dev->tcu_power_status = 1;
	}

	rm_dev->tcu_power_refcount++;
	mutex_unlock(&rm_dev->tcu_power_lock);

	return 0;
}

void tcu_power_off_vote(struct aae_res_mgr *rm_dev)
{
	mutex_lock(&rm_dev->tcu_power_lock);
	rm_dev->tcu_power_refcount--;
	if (rm_dev->tcu_power_refcount == 0 && rm_dev->tcu_power_status == 1) {
		do_tcu_power_off(rm_dev);
		rm_dev->tcu_power_status = 0;
	}

	mutex_unlock(&rm_dev->tcu_power_lock);
}

int32_t tcu_power_suspend(struct aae_res_mgr *rm_dev)
{
	mutex_lock(&rm_dev->tcu_power_lock);
	if (rm_dev->tcu_power_refcount > 0 && rm_dev->tcu_power_status == 1) {
		do_tcu_power_off(rm_dev);
		rm_dev->tcu_power_status = 0;
	}
	mutex_unlock(&rm_dev->tcu_power_lock);

	return 0;
}

int32_t tcu_power_resume(struct aae_res_mgr *rm_dev)
{
	mutex_lock(&rm_dev->tcu_power_lock);
	if (rm_dev->tcu_power_refcount > 0 && rm_dev->tcu_power_status == 0) {
		do_tcu_power_on(rm_dev);
		rm_dev->tcu_power_status = 1;
	}
	mutex_unlock(&rm_dev->tcu_power_lock);

	return 0;
}