/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: provide aae init function interfaces.
 */

#ifndef __AAE_INIT_H__
#define __AAE_INIT_H__

#include <linux/types.h>

struct aae_manager;
/* 
 * @brief aae init function, tbu connect, load the cmdlist node ch7&ch8 and start riscv
 * @param aae_mgr aae manager
 * @return 0 success, other fail
 */
int32_t aae_init(struct aae_manager *aae_mgr);
#endif