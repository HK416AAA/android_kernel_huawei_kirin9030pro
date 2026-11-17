/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_MUTEX_H
#define OAL_MUTEX_H

#include <stdint.h>


#define OAL_MUTEX_WAIT_FOREVER  (-1)

typedef struct oal_mutex {
    void *mutex;
} oal_mutex_t;

typedef oal_mutex_t oal_mutex_stru;

int32_t oal_mutex_init(oal_mutex_t *mutex);
int32_t oal_mutex_lock(oal_mutex_t *mutex);
void oal_mutex_unlock(oal_mutex_t *mutex);
void oal_mutex_destroy(oal_mutex_t *mutex);

#endif
