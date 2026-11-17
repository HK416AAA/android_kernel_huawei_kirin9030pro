/**
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
 
#ifndef TCU_POWER_MGR_H
#define TCU_POWER_MGR_H
 
#include "aae_res_mgr.h"
 
/**
* called by task binder
*/
bool tcu_ready_to_power_off(struct aae_res_mgr *rm_dev);
int32_t tcu_power_on_vote(struct aae_res_mgr *rm_dev);
void tcu_power_off_vote(struct aae_res_mgr *rm_dev);
 
/**
* called by pm ops
*/
int32_t tcu_power_suspend(struct aae_res_mgr *rm_dev);
int32_t tcu_power_resume(struct aae_res_mgr *rm_dev);
#endif