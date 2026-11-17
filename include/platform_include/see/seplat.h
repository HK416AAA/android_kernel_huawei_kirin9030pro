/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: seplat interface at kernel.
 * Create : 2024/07/15
 */
#ifndef __SEPLAT_H__
#define __SEPLAT_H__
 
#include <linux/types.h>
 
int seplat_get_dieid(char *dieid, u32 len);
 
#endif /* __SEPLAT_H__ */
