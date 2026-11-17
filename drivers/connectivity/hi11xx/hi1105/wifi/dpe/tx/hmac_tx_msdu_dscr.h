/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : hmac_tx_msdu_dscr.c 的头文件
 * 作者       : wifi
 * 创建日期   : 2020年02月12日
 */

#ifndef HMAC_TX_MSDU_DSCR_H
#define HMAC_TX_MSDU_DSCR_H

/* 1 其他头文件包含 */
#include "oal_ext_if.h"
#include "dpe_wlan_tid.h"
#include "dpe_wlan_vap.h"
#include "host_hal_ext_if.h"
#include "dpe_wlan_vap.h"
#include "dpe_wlan_stat.h"
#include "hmac_tid_sche.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_DRIVER_HMAC_TX_MSDU_DSCR_H
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define CSUM_TYPE_IPV4_TCP 1
#define CSUM_TYPE_IPV4_UDP 2
#define CSUM_TYPE_IPV6_TCP 3
#define CSUM_TYPE_IPV6_UDP 4

static inline uint32_t get_low_32_bits(uint64_t value)
{
    return ((uint32_t)(((uint64_t)(value)) & 0x00000000FFFFFFFFUL));
}
static inline uint32_t get_high_32_bits(uint64_t value)
{
    return ((uint32_t)((((uint64_t)(value)) & 0xFFFFFFFF00000000UL) >> 32UL));
}
#define HOST_AL_TX_FLAG   0x5a

static inline uint8_t hmac_tid_is_host_ring_tx(hmac_tid_info_stru *tid_info)
{
    uint8_t ring_tx_mode = (uint8_t)oal_atomic_read(&tid_info->ring_tx_mode);

    return ring_tx_mode == HOST_RING_TX_MODE || ring_tx_mode == H2D_SWITCHING_MODE;
}
/*
 * 功能描述 : 获取ring状态, 若ring不在inited状态, 说明ring已去初始化/初始化未完成, 不允许发帧
 * 1.日    期 : 2020年6月1日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_get_tx_ring_inited(uint16_t user_idx, uint8_t tid)
{
    hmac_tid_info_stru *tid_info = dpe_get_tx_tid_info(user_idx, tid);
    if (tid_info == NULL) {
        return OAL_FALSE;
    }
    return oal_atomic_read(&tid_info->tx_ring.inited);
}

/*
 * 功能描述 : 判断ring是否已满
 * 1.日    期 : 2020年6月1日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_tid_ring_full(hmac_msdu_info_ring_stru *tx_msdu_ring)
{
    un_rw_ptr write_ptr = { .rw_ptr = tx_msdu_ring->base_ring_info.write_index };
    un_rw_ptr release_ptr = { .rw_ptr = tx_msdu_ring->release_index };

    if (!is_rw_ring_full(&release_ptr, &write_ptr)) {
        return OAL_FALSE;
    }

    tx_msdu_ring->push_ring_full_cnt++;
    return OAL_TRUE;
}

static inline uint8_t hmac_tid_ring_empty(hmac_msdu_info_ring_stru *tx_msdu_ring)
{
    return tx_msdu_ring->base_ring_info.write_index == tx_msdu_ring->base_ring_info.read_index;
}

/* ptr1 - ptr2 */
static inline uint16_t hmac_tid_ring_ptr_diff(un_rw_ptr *ptr1, un_rw_ptr *ptr2, uint16_t ring_size)
{
    return ptr1->st_rw_ptr.bit_wrap_flag == ptr2->st_rw_ptr.bit_wrap_flag ?
           ptr1->st_rw_ptr.bit_rw_ptr - ptr2->st_rw_ptr.bit_rw_ptr :
           ptr1->st_rw_ptr.bit_rw_ptr + ring_size - ptr2->st_rw_ptr.bit_rw_ptr;
}

/*
 * 功能描述 : 使用完msdu info后需要清空包括硬件回填字段在内的msdu info内容,
 *            否则硬件下次获取同一位置数据时可能会因为回填字段未清零而产生异常
 * 1.日    期 : 2020年5月29日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_tx_reset_msdu_info(hmac_msdu_info_ring_stru *tx_ring, un_rw_ptr reset_ptr)
{
    if (oal_likely(tx_ring->host_tx_flag != HOST_AL_TX_FLAG)) {
        hal_host_tx_reset_msdu_ring(&tx_ring->ring_buf, reset_ptr.st_rw_ptr.bit_rw_ptr);
    }
}

/*
 * 功能描述 : ring指针++
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_tx_rw_ptr_inc(un_rw_ptr *rw_ptr, uint16_t ring_size)
{
    oal_smp_mb();

    if (++rw_ptr->st_rw_ptr.bit_rw_ptr >= ring_size) {
        rw_ptr->st_rw_ptr.bit_rw_ptr = 0;
        rw_ptr->st_rw_ptr.bit_wrap_flag = !rw_ptr->st_rw_ptr.bit_wrap_flag;
    }
}

/*
 * 功能描述 : 更新ring的释放指针
 * 1.日    期 : 2020年4月22日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_tx_msdu_ring_inc_release_ptr(hmac_msdu_info_ring_stru *tx_ring)
{
    un_rw_ptr release_ptr = { .rw_ptr = tx_ring->release_index };

    hmac_tx_rw_ptr_inc(&release_ptr, hal_host_tx_tid_ring_depth_get(tx_ring->base_ring_info.size));

    tx_ring->release_index = release_ptr.rw_ptr;
}
/*
 * 功能描述 : 发送完成释放描述符内存和报文内存
 * 1.日    期 : 2020年2月12日
 *   作    者 : wifi
 *   修改内容 : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_tx_msdu_update_free_cnt(hmac_msdu_info_ring_stru *tx_ring, uint32_t msdu_cnt)
{
    dpe_wlan_tx_stat_stru *dpe_tx_stat = dpe_wlan_tx_stat_get();
    dpe_tx_stat->tx_host_ring_tx_comp += msdu_cnt;

    oal_atomic_sub(&tx_ring->msdu_cnt, msdu_cnt);
    oal_atomic_sub(&g_tid_sche_ring_mpdu_num, msdu_cnt);
}

/* 10 函数声明 */
uint32_t hmac_tx_ring_push_msdu(dpe_wlan_vap_stru *dpe_vap, hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf);
uint32_t hmac_altx_hostva_to_devva(oal_netbuf_stru *netbuf, uint32_t alloc_size, uint64_t *devva);
uint32_t hmac_tx_sync_ring_info(hmac_tid_info_stru *tx_tid_info, tid_cmd_enum_uint8 cmd);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
void hmac_tx_ring_unmap_netbuf(hmac_msdu_info_ring_stru *tx_ring, oal_netbuf_stru *netbuf, uint16_t release_index);
uint32_t hmac_tx_unmap_msdu_dma_addr(hmac_msdu_info_ring_stru *tx_ring, msdu_info_stru *msdu_info, uint32_t netbuf_len);
#endif
void hmac_tx_msdu_ring_inc_write_ptr(hmac_msdu_info_ring_stru *tx_ring);
uint32_t dpe_get_host_ring_state(void);
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
uint32_t hmac_get_host_ring_state(frw_event_mem_stru *event_mem);
#endif
void hmac_tx_sched_trigger(uint8_t vap_idx, hmac_tid_info_stru *tid_info);
uint32_t hmac_tx_reg_read_rptr(hmac_tid_info_stru *tid_info, uint32_t *rptr);
oal_netbuf_stru *hmac_tx_ring_get_netbuf(hmac_msdu_info_ring_stru *tx_ring, un_rw_ptr netbuf_ptr);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
