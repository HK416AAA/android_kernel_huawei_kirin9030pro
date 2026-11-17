/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: interface header file
 * Author: plat drivers
 */

#ifndef OAL_WORKQUEUE_H
#define OAL_WORKQUEUE_H

#include "oal_list.h"
#include "los_task.h"


typedef struct LosTaskCB task_struct;

struct work_struct;
typedef void (*work_func_t)(struct work_struct *);

typedef struct work_struct {
    oal_list_head_stru entry;    /**< Pointer to a doubly linked list of a work. */
    work_func_t func;            /**< Work handling function. */
    uint32_t work_status;          /**< Work status. */
} oal_work_stru, oal_work_struct_stru;

typedef struct tag_cpu_workqueue_struct {
    oal_list_head_stru worklist;       /* Pointer to a work doubly linked list. */
    oal_work_struct_stru *current_work;  /* Work that is being executed. */
    struct oal_workqueue_struct *wq;       /* Workqueue that contains the workqueue control structure. */
    task_struct *thread;               /* Workqueue handling thread. */
} cpu_workqueue_struct;

typedef struct oal_workqueue_struct {
    cpu_workqueue_struct *cpu_wq;   /**< Workqueue control structure. */
    oal_list_head_stru list;        /**< Pointer to a workqueue doubly linked list. */
    oal_list_head_stru pendList;
    unsigned int wq_id;             /**< Workqueue ID. */
    int delayed_work_count;         /**< Number of delayed works in a workqueue. */
    char *name;                     /**< Workqueue name. */
    int singlethread;               /**< Whether to create a new working task. 0 indicates that
                                         the default working task will be used. */
    int wq_status;                  /**< Workqueue status. */
    int freezeable;                 /**< Not in use temporarily. */
    int rt;                         /**< Not in use temporarily. */
} oal_workqueue_stru_t, oal_workqueue_stru;


#define INIT_WORK(work, callbackFunc)  do { \
    oal_list_init_head(&((work)->entry));         \
    (work)->func = (callbackFunc);          \
    (work)->work_status = 0;                \
} while (0)


oal_workqueue_stru_t *create_singlethread_workqueue(char *name);
bool cancel_work_sync(oal_work_stru *work);
void destroy_workqueue(oal_workqueue_stru_t *wq);

#endif
