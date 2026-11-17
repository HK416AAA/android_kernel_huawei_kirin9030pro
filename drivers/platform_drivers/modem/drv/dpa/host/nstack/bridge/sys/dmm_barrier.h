/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2018-2019. All rights reserved.
 */


#ifndef DMM_BARRIER_H
#define DMM_BARRIER_H
#include <asm/barrier.h>

inline static void dmm_barrier(void)
{
    smp_mb();
}

#endif /* #ifndef DMM_BARRIER_H */
