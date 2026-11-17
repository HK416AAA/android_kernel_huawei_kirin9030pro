/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 */
#ifndef FRW_EXT_IF_H
#define FRW_EXT_IF_H

/* 其他头文件包含 */
#include "oal_ext_if.h"
#include "bsp_timer.h"
#include "bsp_smt_call.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_FRW_EXT_IF_H

extern uint32_t g_add_timer_cnt;
extern uint32_t g_del_timer_cnt;
extern uint32_t g_del_timer_smt_cnt;

enum dpe_thread_event {
    DPE_FRW_THREAD_EVENT = 0x01,
    DPE_THREAD_SMT_EVENT = 0x8000,
};

typedef struct {
    void *p_timeout_arg;
    timer_handle_cb p_timeout_func;
    struct dpe_timer *frw_timeout;
} dpe_timer_args;
struct dpe_timer {
    void *p_timeout_arg;             /* 超时处理函数入参 */
    timer_handle_cb p_func;             /* 超时处理函数 */
    oal_bool_enum_uint8 en_is_registerd; /* 定时器是否已经注册 */
    oal_bool_enum_uint8 is_peroid;      /* 是否是周期性 */
    timer_handle timer;                 /* timer句柄 */
    unsigned int timer_region;
    dpe_timer_args dpe_args;
};
typedef struct dpe_timer frw_timeout_stru;

OAL_STATIC OAL_INLINE int dpe_timer_handle_timeout(int arg)
{
    dpe_timer_args *dpe_args = (dpe_timer_args *)arg;
    frw_timeout_stru *frw_timer = (frw_timeout_stru *)dpe_args->frw_timeout;
    if (frw_timer->is_peroid == OAL_FALSE) {
        frw_timer->en_is_registerd = OAL_FALSE;
        frw_timer->timer = -1;
        g_del_timer_cnt++;
    }
    dpe_args->p_timeout_func((int)dpe_args->p_timeout_arg);
    return 0;
}
OAL_STATIC OAL_INLINE int frw_timer_smt_call(frw_timeout_stru *pst_timeout, unsigned int cur_core_id)
{
    int ret = OAL_FAIL;
    mdrv_thread_type_t thread_type = mdrv_cur_context();
    if (thread_type == SYS_TASK) {
        g_del_timer_smt_cnt++;
        // task调用接口，dpa内部处理timer del，等到DPE_THREAD_SMT_EVENT事件，说明timer已经del完成
        ret = smt_call(pst_timeout->timer_region, (smt_call_func_t)bsp_timer_delete, pst_timeout->timer,
            DPE_THREAD_SMT_EVENT);
    } else if (thread_type == SYS_FIBER) {
        g_del_timer_smt_cnt++;
        // fiber调用接口，提交事件后即返回，此时timer还未真正del完成
        ret = smt_call_simple(pst_timeout->timer_region, (smt_call_func_t)bsp_timer_delete, pst_timeout->timer);
    } else {
        oam_error_log4(0, 0, "frw_timer_smt_call::timer[%d], not in task/fiber, core id[%d], smt_cnt[%d], context[%d]",
            pst_timeout->timer, cur_core_id, g_del_timer_smt_cnt, thread_type);
    }
    return ret;
}
// 当前接口，如果在fiber调用，需要将timeout超时函数处理的资源在删timer回调中异步释放
OAL_STATIC OAL_INLINE void frw_timer_immediate_destroy_timer_m(frw_timeout_stru *pst_timeout)
{
    unsigned int cur_core_id;
    int ret = OAL_FAIL;

    cur_core_id = mdrv_get_core_id();
    if (cur_core_id == pst_timeout->timer_region) {
        ret = bsp_timer_delete(pst_timeout->timer);
    } else {
        // 跨核删timer
        ret = frw_timer_smt_call(pst_timeout, cur_core_id);
    }
    if (ret != 0) {
        oam_error_log3(0, 0, "frw_timer_immediate_destroy_timer_m timer[%d] fail ret %d, del_timer_smt_cnt[%d]",
            pst_timeout->timer, ret, g_del_timer_smt_cnt);
    }
    pst_timeout->en_is_registerd = OAL_FALSE;
    pst_timeout->timer = -1;
    g_del_timer_cnt++;
}
/* 每核一个timer list, 无锁: */
OAL_STATIC OAL_INLINE void frw_timer_create_timer_m(frw_timeout_stru *pst_timeout, timer_handle_cb p_timeout_func,
    uint32_t timeout, void *p_timeout_arg, oal_bool_enum_uint8 en_is_periodic, uint16_t en_module_id, uint32_t core_id)
{
    timer_handle timer;
    timer_attr_s timerattr = { 0 }; // name成员未赋值
    unsigned int timer_flag = TIMER_FLAG_DEFAULT;
    if (pst_timeout->en_is_registerd == OAL_TRUE) {
        frw_timer_immediate_destroy_timer_m(pst_timeout);
    }
    pst_timeout->dpe_args.p_timeout_arg = p_timeout_arg;
    pst_timeout->dpe_args.p_timeout_func = p_timeout_func;
    pst_timeout->dpe_args.frw_timeout = (void *)pst_timeout;
    pst_timeout->is_peroid = en_is_periodic;

    if (timeout > 10) { // 唤醒timer不允许使用周期性定时，且最低不允许小于10ms
        timer_flag |= TIMER_WAKE; // 带有唤醒功能的timer标记
    }
    timerattr.time = timeout * 1000; /* timeout单位:ms * 1000 = us */
    timerattr.flag = en_is_periodic == OAL_TRUE ? TIMER_PERIOD : timer_flag;
    timerattr.callback = dpe_timer_handle_timeout;
    timerattr.para = (int)&pst_timeout->dpe_args;
    timer = bsp_timer_add(&timerattr); // add timer即启动定时
    if (timer < 0) {
        oam_error_log1(0, 0, "frw_timer_create_timer_m add err %d\n", timer);
        pst_timeout->en_is_registerd = OAL_FALSE;
        return;
    }
    pst_timeout->en_is_registerd = OAL_TRUE;
    pst_timeout->timer = timer;
    pst_timeout->timer_region = mdrv_get_core_id();
    g_add_timer_cnt++;
}

// 获取32bit 低精度毫秒时间戳
#define oal_time_get_stamp_ms() bsp_get_elapse_ms()
// 获取32bit 高精度纳秒时间戳
#define oal_time_get_stamp_ns() bsp_slice_getcurtime_hrt_ns()
// 计算时间差
#define oal_time_get_runtime(start, end) get_timer_slice_delta((start), (end))

#define oal_read_once(_p) (_p)

OAL_STATIC OAL_INLINE void oal_msleep(uint32_t ul_ms)
{
    udelay(ul_ms * 1000); //  使用高精度时间戳进行延时，占用CPU，1000 us级别。
}

OAL_STATIC OAL_INLINE void oal_udelay(uint32_t ul_ms)
{
    udelay(ul_ms); //  使用高精度时间戳进行延时，占用CPU，1000 us级别。
}

#endif /* end of wal_ext_if.h */
