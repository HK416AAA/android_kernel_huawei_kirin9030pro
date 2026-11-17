/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Code source files for utils
 * Author: plat drivers
 */

#include "oal_net.h"
#include <sh_string.h>
#include "stdbool.h"
#include "osal_heap_mgr_wapper.h"
#include "plat_debug.h"
#include "hal_pm.h"
#include "hal_peri_pm.h"
#ifdef CONFIG_MEMORY_SEGMENTED_MALLOC
#include "bt_adapter.h"
#endif

void oal_gpio_direction_output(size_t gpio, size_t flag)
{
    gpio_direction_output(gpio, flag);
    // 待适配，拉gpio接口实现
}

void *oal_kmalloc(size_t size, int flags)
{
    return lalloc(size);
}

void *oal_kzalloc(size_t size, int flags)
{
    return lzalloc(size);
}

void *oal_vmalloc(size_t size)
{
    return lalloc(size);
}

void oal_kfree(void *ptr)
{
    lfree(ptr);
}

void oal_vfree(void *ptr)
{
    lfree(ptr);
}

int32_t g_ddr_vote_cnt = 0;

/*
 * Prototype    : oal_get_ddr_vote_cnt
 * Description  : 获取ddr投票计数用于维测
 */
int32_t oal_get_ddr_vote_cnt(void)
{
    return g_ddr_vote_cnt;
}
/*
 * Prototype    : oal_large_malloc
 * Description  : 调用堆申请接口申请内存。使用前需调用外设投票接口申请DDR使用投票
 * NOTE:        : 调用约束：
 *                1. 内部有线程调度，不能在中断和定时器回调调用，只能在TASK上下文调用
 *                2. 函数支持嵌套调用，需要成对使用
 */
void *oal_large_malloc(uint32_t size)
{
#ifdef CONFIG_MEMORY_SEGMENTED_MALLOC
    return BTDeviceMalloc(size);
#else
    void* addr;
    uint32_t int_flag;
#ifdef CONFIG_DDR_DYNAMICALLY_VOTE
    // 复用USER_GPS的ID给外设DDR投票
    if (peri_device_request(USER_GPS, B_DDR) != SUCCESS) {
        PRINT_ERR("oal_large_malloc peri_device_request B_DDR fail");
        return NULL;
    }
#endif
    addr = osa_large_heap_malloc(size);
    if (addr == NULL) {
#ifdef CONFIG_DDR_DYNAMICALLY_VOTE
        // 申请失败需释放外设投票
        if (peri_device_release(USER_GPS, B_DDR) != SUCCESS) {
            PRINT_ERR("oal_large_malloc peri_device_release B_DDR fail");
        }
#endif
        return NULL;
    }
    int_flag = osa_int_lock();
    g_ddr_vote_cnt++;
    osa_int_restore(int_flag);

    return addr;
#endif
}

/*
 * Prototype    : oal_large_free
 * Description  : 调用堆申请接口申请内存。使用前需调用外设投票释放接口释放DDR投票
 * NOTE:        : 调用约束：
 *                1. 内部有线程调度，不能在中断和定时器回调调用，只能在TASK上下文调用
 *                2. 函数支持嵌套调用，需要成对使用
 */
void oal_large_free(void *ptr)
{
#ifdef CONFIG_MEMORY_SEGMENTED_MALLOC
    BTDeviceFree(ptr);
#else
    uint32_t int_flag;
    osa_large_heap_free(ptr);
#ifdef CONFIG_DDR_DYNAMICALLY_VOTE
    if (peri_device_release(USER_GPS, B_DDR) != SUCCESS) {
        PRINT_ERR("oal_large_malloc peri_device_release B_DDR fail");
        return;
    }
#endif
    int_flag = osa_int_lock();
    g_ddr_vote_cnt--;
    if (g_ddr_vote_cnt < 0) {
        PRINT_ERR("oal_large_free double free occur");
    }
    osa_int_restore(int_flag);
#endif
}

int is_my_chip(void)
{
    return true;
}

int is_hisi_chiptype(int32_t chip)
{
    return true;
}

oal_netbuf_stru *oal_netbuf_alloc(unsigned int size, int gfp_mask)
{
    oal_netbuf_stru *pst_netbuf = NULL;
    uint8_t *data = NULL;
    unsigned int size_tmp = 0;

    /* Get the HEAD */
    pst_netbuf = oal_kzalloc(sizeof(oal_netbuf_stru), 0); // 分配存储空间
    if (!pst_netbuf) { goto out; }

    size_tmp = OAL_NETBUF_DATA_ALIGN(size); // 调整netbuf大小
    data = oal_kzalloc(size, 0); // 分配数据区
    if (!data) { goto nodata; }

    // 初始化数据区的指针
    pst_netbuf->head = data;
    pst_netbuf->data = data;
    pst_netbuf->tail = data;
    pst_netbuf->end = pst_netbuf->tail + size_tmp;
    pst_netbuf->len = 0;
out:
    return pst_netbuf;

nodata:
    oal_kfree(pst_netbuf);
    pst_netbuf = NULL;
    return pst_netbuf;
}

void oal_netbuf_free(oal_netbuf_stru *pst_netbuf)
{
    oal_kfree(pst_netbuf->data);
    pst_netbuf->data = NULL;
    oal_kfree(pst_netbuf);
    pst_netbuf = NULL;
}

void *oal_netbuf_put(oal_netbuf_stru *pst_netbuf, unsigned int len)
{
    unsigned char* tmp = pst_netbuf->tail;
    pst_netbuf->tail += len;
    pst_netbuf->len += len;
    return tmp;
}

void *oal_netbuf_pull(oal_netbuf_stru *pst_netbuf, unsigned int len)
{
    if (len > pst_netbuf->len) {
        return NULL;
    }
    pst_netbuf->len -= len;
    return pst_netbuf->data += len;
}

static inline void oal_netbuf_unlink(oal_netbuf_stru *pst_netbuf, oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *next, *prev;

    WRITE_ONCE(list->qlen, list->qlen - 1);
    next	   = pst_netbuf->next;
    prev	   = pst_netbuf->prev;
    pst_netbuf->next  = pst_netbuf->prev = NULL;
    WRITE_ONCE(next->prev, prev);
    WRITE_ONCE(prev->next, next);
}

oal_netbuf_stru *oal_netbuf_dequeue(oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *pst_netbuf = list->next;

    if (pst_netbuf == (oal_netbuf_stru *)list) {
        return NULL;
    }

    if (pst_netbuf != NULL) {
        oal_netbuf_unlink(pst_netbuf, list);
    }

    return pst_netbuf;
}

oal_netbuf_stru *oal_netbuf_dequeue_tail(oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *pst_netbuf = list->prev;

    if (pst_netbuf == (oal_netbuf_stru *)list) {
        return NULL;
    }

    if (pst_netbuf != NULL) {
        oal_netbuf_unlink(pst_netbuf, list);
    }

    return pst_netbuf;
}

static inline void oal_netbuf_insert(oal_netbuf_stru *newsk, oal_netbuf_stru *prev, oal_netbuf_stru *next,
    oal_netbuf_head_stru *list)
{
    WRITE_ONCE(newsk->next, next);
    WRITE_ONCE(newsk->prev, prev);
    WRITE_ONCE(next->prev, newsk);
    WRITE_ONCE(prev->next, newsk);
    list->qlen++;
}

static inline void oal_netbuf_queue_after(oal_netbuf_head_stru *list, oal_netbuf_stru *prev,
    oal_netbuf_stru *newsk)
{
    oal_netbuf_insert(newsk, prev, prev->next, list);
}

static inline void oal_netbuf_queue_before(oal_netbuf_head_stru *list, oal_netbuf_stru *next,
    oal_netbuf_stru *newsk)
{
    oal_netbuf_insert(newsk, next->prev, next, list);
}

void oal_netbuf_queue_tail(oal_netbuf_head_stru *list, oal_netbuf_stru *newsk)
{
    oal_netbuf_queue_before(list, (oal_netbuf_stru *)list, newsk);
}

unsigned char *oal_netbuf_tail_pointer(const oal_netbuf_stru *pst_netbuf)
{
    return pst_netbuf->tail;
}

void oal_netbuf_queue_head(oal_netbuf_head_stru *list, oal_netbuf_stru *newsk)
{
    oal_netbuf_queue_after(list, (oal_netbuf_stru *)list, newsk);
}

// 此接口功能待确认，如果可以废弃使用此接口
int oal_netbuf_tailroom(const oal_netbuf_stru *pst_netbuf)
{
    return (pst_netbuf->len) ? 0 : pst_netbuf->end - pst_netbuf->tail;
}

void oal_netbuf_queue_purge(oal_netbuf_head_stru *list)
{
    oal_netbuf_stru *pst_netbuf;
    while ((pst_netbuf = oal_netbuf_dequeue(list)) != NULL) {
        oal_netbuf_free(pst_netbuf);
    }
}
