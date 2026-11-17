/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: itrustee defines
 * Create: 2019-11-09
 */

#ifndef ITRUSTEE_H_INCLUDED
#define ITRUSTEE_H_INCLUDED

void wakeup_tc_siq(void);
bool is_tee_hungtask(struct task_struct *t);

#endif
