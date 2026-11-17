/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_COMLETION_H
#define OAL_COMLETION_H

#include "los_sys.h"
#include "oal_list.h"
#include "los_list.h"
#include <stdint.h>
#include <stdbool.h>


typedef enum CompletionState {
    COMPLETION_ONE,
    COMPLETION_ALL
} CompletionState;

#define COMPLETION_EVT 0x1

typedef struct oal_completion {
    LOS_DL_LIST pend_list;
    uint32_t com_count;
    enum CompletionState state;
} oal_completion, oal_completion_t;

#ifndef _PRE_LINUX_TEST
void oal_init_completion(oal_completion_t *x);
void oal_complete(oal_completion_t *x);
void oal_complete_all(oal_completion_t *x);

#define oal_reinit_completion(x)    oal_init_completion(&(x))
#else
#define oal_init_completion(_my_completion) {}
#define oal_complete(_my_completion) {}
#define oal_complete_all (_my_completion) {}
#define oal_reinit_completion(_my_completion) {}
#endif

#endif
