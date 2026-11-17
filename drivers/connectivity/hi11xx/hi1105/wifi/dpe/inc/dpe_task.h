/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_hcc_adapt.c 的头文件
 * 作    者 :
 * 创建日期 : 2012年9月18日
 */

#ifndef DPE_TASK_H
#define DPE_TASK_H

#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "dpe_hcc_if.h"
#include "osl_thread.h"
#include "mdrv_fiber.h"
#endif

#define DPE_CORE_0 0x1
#define DPE_CORE_1 0x2
#define CORE_NUM 2
#define FIBER_QUEUE_SIZE 10
#define FIBER_QUEUE_IRQ_SIZE 5

#ifndef WIN32
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
// fiber消息入队
#define dpe_sema_up_msg(_task_id, _p) mdrv_fiber_queue_send(_task_id, _p)
// task事件标记
#define dpe_sema_up_evt(_task_id, _p) mdrv_kevent_send(_task_id, _p)

#ifdef _PRE_MULTI_CORE_DPE_THREAD_FIBER
#define dpe_sema_up(_task_id, _msg, _evt)  dpe_sema_up_msg(_task_id, _msg)
#else
#define dpe_sema_up(_task_id, _msg, _evt)  dpe_sema_up_evt(_task_id, _evt)
#endif
#else // _PRE_MULTI_CORE_DPE_OFFLOAD
#define dpe_sema_up(_p)  up(_p)
#endif
#else
#define dpe_sema_up(_p)
#endif

#endif /* end of hmac_main */
