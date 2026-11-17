/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for completion
 * Author: plat drivers
 */

#include "oal_completion.h"
#include "limits.h"
#include "los_task_pri.h"
#include "los_mp_pri.h"
#include "plat_debug.h"
#ifdef __RTOS_LITE__
#include "osal_lite.h"
#endif

#define ALL_NODES_OF_LIST 0

/* wake pendlist task */
static VOID WakeupFromPendList(LOS_DL_LIST *list, UINT32 nodeCnt)
{
    LosTaskCB *tcb = NULL;

    if (list == NULL) {
        return;
    }

    UINT32 wakeCnt = 0;
    while (!LOS_ListEmpty(list)) {
        tcb = OS_TCB_FROM_PENDLIST(LOS_DL_LIST_FIRST(list));
        OsTaskWake(tcb, OS_TASK_STATUS_PEND);

        /* count wake-up nodes */
        if ((nodeCnt != ALL_NODES_OF_LIST) && ((++wakeCnt) == nodeCnt)) {
            break;
        }
    }
}


/* add running task to specified pendlist and pend timeout ticks and return remain ticks */
static UINT32 BlockOnPendList(LOS_DL_LIST *list, UINT32 timeout)
{
    LosTaskCB *task = OsCurrTaskGet();

    if (OS_INT_ACTIVE || (task->taskFlags & OS_TASK_FLAG_SYSTEM)) {
        PRINT_ERR("DO NOT call BlockOnPendList in system tasks or interrupt callback.\n");
        return timeout;
    }

    if (timeout == LOS_NO_WAIT) {
        return 0;
    }

    if (list == NULL) {
        PRINT_ERR("list is NULL!\n");
        return 0;
    }

    UINT64 startTicks = LOS_TickCountGet();

    OsTaskWait(list, OS_TASK_STATUS_PEND, timeout);
    OsSchedResched();

    /* timeout */
    if (task->taskStatus & OS_TASK_STATUS_TIMEOUT) {
        task->taskStatus &= ~OS_TASK_STATUS_TIMEOUT;
        return 0;
    }

    UINT64 usedTicks = LOS_TickCountGet() - startTicks;

    /* less than timeout ticks, return remain ticks, else return 1 tick */
    return usedTicks < timeout ? (timeout - (UINT32)usedTicks) : 1;
}


void oal_init_completion(oal_completion_t *x)
{
    uint32_t int_save;

    if (x == NULL) {
        return;
    }

    SCHEDULER_LOCK(int_save);
    LOS_ListInit(&x->pend_list);
    x->com_count = 0;
    x->state = COMPLETION_ONE;

    SCHEDULER_UNLOCK(int_save);
    return;
}

static bool no_need_wait(oal_completion_t *x)
{
    if (x->state == COMPLETION_ALL) {
        return true;
    }

    if (x->com_count > 0) {
        x->com_count--;
        return true;
    }

    return false;
}

void oal_complete(oal_completion_t *x)
{
    uint32_t int_save;

    if (x == NULL) {
        return;
    }

    SCHEDULER_LOCK(int_save);
    if (!LOS_ListEmpty(&x->pend_list)) {
        WakeupFromPendList(&x->pend_list, 1);
        SCHEDULER_UNLOCK(int_save);
        LOS_MpSchedule(OS_MP_CPU_ALL);
        LOS_Schedule();
        return;
    }

    if (x->com_count != UINT_MAX) {
        x->com_count++;
    }

    SCHEDULER_UNLOCK(int_save);
}

void oal_complete_all(oal_completion_t *x)
{
    uint32_t int_save;

    if (x == NULL) {
        return;
    }

    SCHEDULER_LOCK(int_save);
    x->state = COMPLETION_ALL;
    if (LOS_ListEmpty(&x->pend_list)) {
        SCHEDULER_UNLOCK(int_save);
        return;
    }

    WakeupFromPendList(&x->pend_list, ALL_NODES_OF_LIST);
    SCHEDULER_UNLOCK(int_save);
    LOS_MpSchedule(OS_MP_CPU_ALL);
    LOS_Schedule();
}
