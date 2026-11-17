/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : Free/Complete ring基本操作
 * 作者       : wifi
 * 创建日期   : 2018年4月26日
 */

#include "securec.h"
#include "oal_util.h"
#include "oal_net.h"
#include "oal_ext_if.h"
#include "oam_ext_if.h"
#include "host_hal_ext_if.h"
#include "host_hal_device.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "pcie_linux.h"
#else
#include "pcie_host.h"
#endif
#include "pcie_host.h"
#include "host_hal_ring.h"
#include "host_hal_dma.h"
#include "dpe_mem.h"
#include "dpe_wlan_stat.h"
#include "dpe_tx_data.h"
#include "dpe_wlan_resource.h"
#undef THIS_FILE_ID
#define THIS_FILE_ID     OAM_FILE_ID_HAL_RING_C
#define HAL_WORD_TO_BYTE 4

/* tx流程访存优化，该全局变量用于批量写tx ring */
host_tx_msdu_ring_batch_stru g_host_tx_ring_msdu_batch;
host_rx_comp_buff_pool_stru  g_rx_comp_buff_pool;

host_tx_msdu_ring_batch_stru *hal_host_get_tx_ring_batch(void)
{
    return &g_host_tx_ring_msdu_batch;
}
host_rx_comp_buff_pool_stru *hal_host_get_rx_buff_pool(void)
{
    return &g_rx_comp_buff_pool;
}
void hal_host_rx_ring_init(void)
{
    g_rx_comp_buff_pool.buff_pool_depth = HAL_RX_COMPLETE_BUFF_POOL_SIZE;
    g_rx_comp_buff_pool.write_ptr = 0;
    g_rx_comp_buff_pool.read_ptr = 0;
    g_rx_comp_buff_pool.sbuf_num = 0;
    g_rx_comp_buff_pool.overloop = 0;
}
uint32_t hal_host_rx_add_buff_pool(hal_host_device_stru *hal_dev, uint64_t hw_dscr_addr)
{
    host_rx_comp_buff_pool_stru *rx_buff_pool = hal_host_get_rx_buff_pool();
    uint64_t host_iova;
    uint32_t write_idx;
    int32_t ret = pcie_if_devva_to_hostca(HCC_EP_WIFI_DEV, (uint64_t)hw_dscr_addr, (uint64_t *)&host_iova);
    if (ret != OAL_SUCC) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_host_rx_add_buff_pool:devva2hostca fail.}");
        return OAL_FAIL;
    }

    write_idx = rx_buff_pool->write_ptr;
  
    /* 异常检查: 写之前已超过深度越界, 异常处理 */
    if (write_idx >= rx_buff_pool->buff_pool_depth) {
        oam_error_log4(0, OAM_SF_DPA, "{hal_host_rx_add_buff_pool:err wr %d rd %d depth %d sbuf %d.}",
            write_idx, rx_buff_pool->read_ptr, rx_buff_pool->buff_pool_depth, rx_buff_pool->sbuf_num);
        hal_host_rx_ring_init();
        return OAL_FAIL;
    }
    if (rx_buff_pool->overloop != 0) {
        oam_error_log1(0, OAM_SF_DPA, "{hal_host_rx_add_buff_pool: add pool overloop %d.}", rx_buff_pool->overloop);
        return OAL_FAIL;
    }

    /* 写入 */
    rx_buff_pool->rx_comp_data_buff_pool[write_idx] = host_iova;
    dpe_wlan_rx_delay_notify(NULL, write_idx, RX_BUFF_POOL_START); // 时延打点
    rx_buff_pool->sbuf_num++;

    write_idx++;
    if (write_idx >= rx_buff_pool->buff_pool_depth) {
        /* 已到达ring的最后一个元素，index从0开始计数，并设置flag标志(flag翻转) */
        write_idx = 0;
    }
    /* 溢出检查: | ** | wr | rd | ** | */
    if (write_idx == rx_buff_pool->read_ptr) {
        rx_buff_pool->overloop = 1;
        oam_error_log2(0, OAM_SF_DPA, "{hal_host_rx_add_buff_pool: %d %d.}", write_idx, rx_buff_pool->read_ptr);
    } else {
        rx_buff_pool->overloop = 0;
    }
    /* 更新写指针 */
    rx_buff_pool->write_ptr = write_idx;
    return OAL_SUCC;
}

uint64_t hal_host_rx_get_from_buff_pool(void)
{
    host_rx_comp_buff_pool_stru *rx_buff_pool = hal_host_get_rx_buff_pool();
    uint64_t hw_dscr_addr;
    uint32_t read_idx = rx_buff_pool->read_ptr;

    /* 已经取空 */
    if (read_idx == rx_buff_pool->write_ptr) {
        return 0;
    }
    /* 维护异常 */
    if (read_idx >= rx_buff_pool->buff_pool_depth) {
        oam_error_log4(0, OAM_SF_DPA, "{hal_host_rx_get_from_buff_pool::rd %d wr %d depth %d sbuf %d.}",
            read_idx, rx_buff_pool->write_ptr, rx_buff_pool->buff_pool_depth, rx_buff_pool->sbuf_num);
        hal_host_rx_ring_init();
        return 0;
    }
    hw_dscr_addr = rx_buff_pool->rx_comp_data_buff_pool[read_idx];
    dpe_wlan_rx_delay_notify(NULL, read_idx, RX_BUFF_POOL_END);
    rx_buff_pool->sbuf_num--;

    read_idx++;
    if (read_idx >= rx_buff_pool->buff_pool_depth) {
        /* 已到达ring的最后一个元素，index从0开始计数，并设置flag标志(flag翻转) */
        read_idx = 0;
    }
    /* 更新读指针 */
    rx_buff_pool->read_ptr = read_idx;
    return hw_dscr_addr;
}
uint8_t hal_rx_buff_pool_is_empty(hal_host_device_stru *hal_dev)
{
    host_rx_comp_buff_pool_stru *rx_buff_pool = hal_host_get_rx_buff_pool();
    oal_uint lock_flag;
    uint8_t  empty;
    
    dpe_rx_mpdu_list_lock_irq_save(&hal_dev->st_rx_mpdu.st_spin_lock, &lock_flag);
    empty = (rx_buff_pool->read_ptr == rx_buff_pool->write_ptr); // 缓存队列空
    dpe_rx_mpdu_list_unlock_irq_restore(&hal_dev->st_rx_mpdu.st_spin_lock, &lock_flag);
    return empty;
}

/*
 * 功能描述   : 初始化ring，设置寄存器的值
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_host_ring_init(void)
{
    g_host_tx_ring_msdu_batch.ring_depth = TX_RING_MSDU_MAX_NUM;
    g_host_tx_ring_msdu_batch.batch_num = 0;

    hal_host_rx_ring_init();
}

/*
 * 功能描述   : 获取MAC上报到HOST的ring读写指针
 * 1.日    期   : 2024年10月28日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_get_mac_rpt_ptr(hal_host_ring_ctl_stru *ring_ctl)
{
    uint32_t ptr = HAL_HOST_READL_INVALID_VAL;
    hal_host_chip_stru *hal_chip = hal_get_host_chip();

    if (hal_chip->rx_ring_mac_ptr_info == NULL) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_mac_rpt_ptr::get rx ring mac ptr fail.}");
        return HAL_HOST_READL_INVALID_VAL;
    }

    switch (ring_ctl->ring_subtype) {
        case HAL_RING_TYPE_L_F:
            ptr = (uint32_t)hal_chip->rx_ring_mac_ptr_info[HAL_RX_NORM_DATA_FREE_RPTR].ptr;
            break;
        case HAL_RING_TYPE_S_F:
            ptr = (uint32_t)hal_chip->rx_ring_mac_ptr_info[HAL_RX_SMALL_DATA_FREE_RPTR].ptr;
            break;
        case HAL_RING_TYPE_COMP:
            ptr = (uint32_t)hal_chip->rx_ring_mac_ptr_info[HAL_RX_DATA_COMP_WPTR].ptr;
            break;
#ifdef _PRE_WLAN_FEATURE_SNIFFER
        case HAL_RING_TYPE_P_F:
            ptr = (uint32_t)hal_chip->rx_ring_mac_ptr_info[HAL_RX_PPDU_HOST_DESC_FREE_RPTR].ptr;
            break;
#endif
        default:
            break;
    }
    return ptr;
}

/*
 * 功能描述   : 1) free ring,从寄存器中读取read寄存器，并更新SW的read ptr
                2) complete ring,从寄存器中读取write寄存器，并更新SW的write ptr
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_ring_get_hw2sw(hal_host_ring_ctl_stru *ring_ctl)
{
    uint32_t reginfo;

    /* 入参判断 */
    if (oal_unlikely(ring_ctl == NULL)) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_hw2sw::ring_ctl NULL}");
        return;
    }

    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        if (g_wlan_spec_cfg->rx_ring_reduce_load_is_open == OAL_TRUE) {
            reginfo = hal_ring_get_mac_rpt_ptr(ring_ctl);
        } else {
            reginfo = hal_host_readl(ring_ctl->read_ptr_reg);
        }
        if (reginfo != HAL_HOST_READL_INVALID_VAL) {
            ring_ctl->un_read_ptr.read_ptr = (uint16_t)reginfo;
        }
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        if (g_wlan_spec_cfg->rx_ring_reduce_load_is_open == OAL_TRUE) {
            reginfo = hal_ring_get_mac_rpt_ptr(ring_ctl);
        } else {
            reginfo = hal_host_readl(ring_ctl->write_ptr_reg);
        }
        if (reginfo != HAL_HOST_READL_INVALID_VAL) {
            ring_ctl->un_write_ptr.write_ptr = (uint16_t)reginfo;
        }
    } else {
        return;
    }

    return;
}

/*
 * 功能描述   : 1) free ring,更新SW的write ptr到write寄存器
                2) complete ring,更新SW的read ptr到read寄存器
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_set_sw2hw(hal_host_ring_ctl_stru *ring_ctl)
{
    if (ring_ctl == NULL) {
        return OAL_FAIL;
    }

    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        hal_host_writel(ring_ctl->un_write_ptr.write_ptr, ring_ctl->write_ptr_reg);
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        hal_host_writel(ring_ctl->un_read_ptr.read_ptr, ring_ctl->read_ptr_reg);
    } else {
        oam_error_log1(0, OAM_SF_DPA, "{hal_ring_set_sw2hw::ring_type[%d] err.}", ring_ctl->ring_type);
    }

    return OAL_SUCC;
}

/*
 * 功能描述   : 获取(free)ring上待补充内存的元素个数
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_get_entry_count(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl, uint16_t *p_count)
{
    uint16_t count = 0;
    uint16_t read_idx;
    uint16_t write_idx;

    if (oal_unlikely(oal_any_null_ptr2(ring_ctl, p_count))) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entry_count::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    hal_ring_get_hw2sw(ring_ctl);
    if (ring_ctl->ring_type == HAL_RING_TYPE_FREE_RING) {
        if (hal_ring_is_full(ring_ctl)) {
            *p_count = 0;
            return OAL_SUCC;
        }
        write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
        read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;

        if (hal_ring_wrap_around(ring_ctl)) {
            count = read_idx - write_idx;
        } else {
            count = ring_ctl->entries - write_idx;
            count += read_idx;
        }
    } else if (ring_ctl->ring_type == HAL_RING_TYPE_COMPLETE_RING) {
        if (hal_ring_is_empty(ring_ctl)) {
            *p_count = 0;
            return OAL_SUCC;
        }
        write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
        read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
        if (!hal_ring_wrap_around(ring_ctl)) {
            count = write_idx - read_idx;
        } else {
            count = ring_ctl->entries - read_idx;
            count += write_idx;
        }
    }

    if (count > ring_ctl->entries) {
        oam_warning_log3(hal_dev->device_id, OAM_SF_DPA,
            "{hal_ring_get_entry_count::get error! count[%d]ring_type[%d].entries[%d]}",
            count, ring_ctl->ring_type, ring_ctl->entries);
        oam_warning_log2(hal_dev->device_id, OAM_SF_DPA,
            "{hal_ring_get_entry_count::write_ptr[%d]read_ptr[%d].}",
            ring_ctl->un_write_ptr.write_ptr, ring_ctl->un_read_ptr.read_ptr);
        return OAL_FAIL;
    }
    *p_count = count;
    return OAL_SUCC;
}

/*
 * 功能描述   : 按word获取ring内容
 * 1.日    期   : 2019年7月30日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
OAL_STATIC void hal_ring_get_ring(uint8_t *entries, uint8_t *src_addr, uint32_t size)
{
    volatile uint32_t *src_addr_volatile = NULL;
    uint32_t i;

    if ((size % HAL_WORD_TO_BYTE) != 0) {
        oam_error_log1(0, OAM_SF_DPA, "{hal_ring_get_ring::size = [%d].}", size);
        return;
    }

    src_addr_volatile = (volatile uint32_t *)src_addr;
    for (i = 0; i < size / HAL_WORD_TO_BYTE; i++) {
        *(uint32_t *)(entries + HAL_WORD_TO_BYTE * i) = *(src_addr_volatile + i);
    }
}

#define DDR_BURST_READ_LEVEL 16
uint64_t g_ddr_comp_ring_read[DDR_BURST_READ_LEVEL];
uint16_t hal_host_check_comp_ring_valid(uint16_t read_valid_cnt)
{
    uint16_t cur_idx;
    uint64_t ring_value;

    for (cur_idx = 0; cur_idx < read_valid_cnt; cur_idx++) {
        memcpy_s(&ring_value, HAL_RX_ENTRY_SIZE, &(g_ddr_comp_ring_read[cur_idx]), HAL_RX_ENTRY_SIZE);
        if (ring_value == 0) {
            return OAL_FALSE;
        }
    }
    return OAL_TRUE;
}

/* 批量noncache DDR读取 */
uint16_t hal_host_comp_ring_entry_get(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl,
    uint16_t read_valid_cnt)
{
    uint16_t read_idx, write_idx, pre_half, post_half, cpy_len;
    uint8_t *entries = (uint8_t *)(ring_ctl->p_entries);
    uint8_t *dst_addr = NULL;
    uint8_t *src_addr = NULL;

    write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;

    /* 需要读取的格子数 */
    if (!hal_ring_wrap_around(ring_ctl)) {
        pre_half = write_idx - read_idx;
        post_half = 0;
    } else {
        pre_half = ring_ctl->entries - read_idx;
        post_half = write_idx;
    }
    if (pre_half > read_valid_cnt) {
        pre_half = read_valid_cnt;
        post_half = 0;
    }
    if (pre_half + post_half > read_valid_cnt) {
        post_half = read_valid_cnt - pre_half;
    }

    if (pre_half != 0) {
        dst_addr = (uint8_t *)&g_ddr_comp_ring_read[0];
        src_addr = (entries + read_idx * HAL_RX_ENTRY_SIZE);
        cpy_len = pre_half * HAL_RX_ENTRY_SIZE;
        memcpy_s(dst_addr, cpy_len, src_addr, cpy_len);
    }
    if (post_half != 0) {
        dst_addr = (uint8_t *)&g_ddr_comp_ring_read[pre_half];
        src_addr = entries;
        cpy_len = post_half * HAL_RX_ENTRY_SIZE;
        memcpy_s(dst_addr, cpy_len, src_addr, cpy_len);
    }
    if (read_valid_cnt != pre_half + post_half) {
        oam_error_log4(0, OAM_SF_DPA, "{hal_host_comp_ring_entry_get::w[0x%x] r[0x%x] cnt %d rd %d.}",
            ring_ctl->un_write_ptr.write_ptr, ring_ctl->un_read_ptr.read_ptr, read_valid_cnt, pre_half + post_half);
    }
    if (pre_half == 0 && post_half == 0) {
        oam_error_log2(0, OAM_SF_DPA, "{hal_host_comp_ring_entry_get::size1 [%d] size2 [%d].}", pre_half, post_half);
    }
    return (pre_half + post_half);
}

#define COMPLETE_RING_WAIT_CNT 1000
uint32_t hal_host_comp_ring_wait_valid(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl,
    uint16_t read_valid_cnt)
{
    uint32_t wait_cnt = 0;
    uint16_t ring_valid_cnt;
    uint8_t ring_valid = OAL_FALSE;

    while (ring_valid != OAL_TRUE) {
        /* 重复burst取一次 */
        ring_valid_cnt = hal_host_comp_ring_entry_get(hal_dev, ring_ctl, read_valid_cnt);
        ring_valid = hal_host_check_comp_ring_valid(ring_valid_cnt);
        if (ring_valid == OAL_TRUE) {
            break;
        }

        wait_cnt++;
        if (wait_cnt > COMPLETE_RING_WAIT_CNT) {
            oam_warning_log1(hal_dev->device_id,
                OAM_SF_DPA, "hal_host_comp_ring_wait_valid:wait_cnt:%d exceeded.", wait_cnt);
            return OAL_FAIL;
        }
    }

    return OAL_SUCC;
}

/*
 * 函 数 名   : hal_comp_ring_wait_valid
 * 功能描述   : wait rx complete ring addr valid
 * 1.日    期   : 2021年4月17日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_comp_ring_wait_valid(hal_host_device_stru *hal_dev, hal_host_ring_ctl_stru *ring_ctl)
{
    uint16_t rd_idx;
    uint32_t wait_cnt = 0;
    uint8_t *entries = (uint8_t *)(ring_ctl->p_entries);

    rd_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    while (oal_unlikely(*(uint64_t *)(entries + ring_ctl->entry_size * rd_idx)) == 0) {
        /* 接收负载优化功能打开后由MAC提供保序功能，若ring中无数据说明保序功能失效 */
        if ((g_wlan_spec_cfg->rx_ring_reduce_load_is_open == OAL_TRUE) && (wait_cnt == 0)) {
            oam_error_log0(hal_dev->device_id, OAM_SF_DPA, "hal_comp_ring_wait_valid:mac keep order feature invalid.");
        }
#ifdef _PRE_EMU
        oal_udelay(300);  /* 延迟 300 微秒  */
#endif
        wait_cnt++;
        if (wait_cnt > COMPLETE_RING_WAIT_CNT) {
            oam_warning_log1(hal_dev->device_id, OAM_SF_DPA,
                "hal_comp_ring_wait_valid:wait_cnt:%d exceeded.", wait_cnt);
            return OAL_FAIL;
        }
    }

    return OAL_SUCC;
}

/*
 * 函 数 名   : hal_ring_entries_get
 * 功能描述   : 获取(complete)ring上待处理的"us_count"个元素，
                把元素的内容copy到"entries"中。
                注:该函数会更新ring_ctl中的read_ptr
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_get_entries(hal_host_ring_ctl_stru *ring_ctl,
    uint8_t *entries, uint16_t count)
{
    uint16_t entry_size;
    uint16_t remains;
    uint16_t read_idx;
    uint8_t *src_addr = NULL;
    /* 入参判断 */
    if (oal_unlikely(oal_any_null_ptr2(ring_ctl, entries))) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entries::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (ring_ctl->ring_type != HAL_RING_TYPE_COMPLETE_RING) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entries::not complete ring!.}");
        return OAL_FAIL;
    }

    if (hal_ring_is_empty(ring_ctl)) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entries::HAL_RING_IS_EMPTY!}");
        return OAL_FAIL;
    }

    entry_size = ring_ctl->entry_size;

    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    src_addr = (uint8_t *)(ring_ctl->p_entries) + entry_size * read_idx;
    if (count + read_idx >= ring_ctl->entries) {
        remains = (count + read_idx) % ring_ctl->entries;
        hal_ring_get_ring(entries, src_addr, entry_size * (ring_ctl->entries - read_idx));

        /* 内容读出后，清0 */
        memset_s(src_addr, entry_size * (ring_ctl->entries - read_idx),
            0, entry_size * (ring_ctl->entries - read_idx));
        if (remains != 0) {
            hal_ring_get_ring(entries + entry_size * (ring_ctl->entries - read_idx),
                (uint8_t *)(ring_ctl->p_entries), entry_size * remains);
            /* 内容读出后，清0 */
            memset_s(ring_ctl->p_entries, entry_size * remains, 0, entry_size * remains);
        }
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr = remains;
        ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag =
            !ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag;
    } else {
        hal_ring_get_ring(entries, src_addr, entry_size * count);
        /* 内容读出后，清0 */
        memset_s(src_addr, entry_size * count, 0, entry_size * count);
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr += count;
    }
    return OAL_SUCC;
}

/*
 * 函 数 名   : hal_ring_get_entries_without_reset
 * 功能描述   : 获取(complete)ring上待处理的count个元素，把元素的内容copy到entries中
               注：copy结束后不做清零操作
 * 日    期   : 2025年06月18日
 * 修改内容   : 新生成函数
 */
OAL_STATIC uint32_t hal_ring_get_entries_without_reset(hal_host_ring_ctl_stru *ring_ctl,
    uint8_t *entries, uint16_t count)
{
    uint16_t entry_size;
    uint16_t remains;
    uint16_t read_idx;
    uint8_t *src_addr = NULL;

    if (ring_ctl->ring_type != HAL_RING_TYPE_COMPLETE_RING) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entries::not complete ring!.}");
        return OAL_FAIL;
    }

    if (hal_ring_is_empty(ring_ctl)) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_get_entries::HAL_RING_IS_EMPTY!}");
        return OAL_FAIL;
    }

    entry_size = ring_ctl->entry_size;
    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    src_addr = (uint8_t *)(ring_ctl->p_entries) + entry_size * read_idx;

    if (count + read_idx >= ring_ctl->entries) {
        remains = (count + read_idx) % ring_ctl->entries;
        hal_ring_get_ring(entries, src_addr, entry_size * (ring_ctl->entries - read_idx));
        if (remains != 0) {
            hal_ring_get_ring(entries + entry_size * (ring_ctl->entries - read_idx),
                (uint8_t *)(ring_ctl->p_entries), entry_size * remains);
        }
    } else {
        hal_ring_get_ring(entries, src_addr, entry_size * count);
    }
    return OAL_SUCC;
}

/*
 * 函 数 名   : hal_ring_reset_entries
 * 功能描述   : 批量对comp ring上从read_idx位置开始的count个元素清零
 * 日    期   : 2025年06月16日
 * 修改内容   : 新生成函数
 */
uint32_t hal_ring_reset_entries(hal_host_ring_ctl_stru *ring_ctl, uint16_t read_idx, uint16_t count)
{
    uint16_t entry_size;
    uint16_t remains;
    uint8_t *src_addr = NULL;

    /* 入参判断 */
    if (oal_unlikely(oal_any_null_ptr1(ring_ctl))) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_reset_entries::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (ring_ctl->ring_type != HAL_RING_TYPE_COMPLETE_RING) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_ring_reset_entries::not complete ring!.}");
        return OAL_FAIL;
    }

    entry_size = ring_ctl->entry_size;
    src_addr = (uint8_t *)(ring_ctl->p_entries) + entry_size * read_idx;
    if (count + read_idx >= ring_ctl->entries) {
        remains = (count + read_idx) % ring_ctl->entries;
        memset_s(src_addr, entry_size * (ring_ctl->entries - read_idx),
            0, entry_size * (ring_ctl->entries - read_idx));
        if (remains != 0) {
            memset_s(ring_ctl->p_entries, entry_size * remains, 0, entry_size * remains);
        }
    } else {
        memset_s(src_addr, entry_size * count, 0, entry_size * count);
    }
    return OAL_SUCC;
}
void hal_rx_comp_ring_update_rptr(hal_host_ring_ctl_stru *ring_ctl, uint16_t count)
{
    uint16_t remains;
    uint16_t read_idx;

    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;

    if (count + read_idx >= ring_ctl->entries) {
        remains = (count + read_idx) % ring_ctl->entries;
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr = remains;
        ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag =
            !ring_ctl->un_read_ptr.st_read_ptr.bit_wrap_flag;
    } else {
        ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr += count;
    }
}

/*
 * 功能描述   : 设置/补充(free)ring上的元素，
                把entry放在write_ptr指向的位置，然后更新write_ptr(++)。
                注:该函数会更新ring_ctl中的write_ptr
                如果该函数返回失败，调用者负责释放entry内存
 * 1.日    期   : 2018年4月26日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_ring_set_entries(hal_host_ring_ctl_stru *ring_ctl, uint64_t entry)
{
    uint16_t write_idx;

    if (oal_any_null_ptr1(ring_ctl) || (!entry)) {
        return OAL_ERR_CODE_PTR_NULL;
    }

    if (ring_ctl->ring_type != HAL_RING_TYPE_FREE_RING) {
        return OAL_FAIL;
    }

    if (hal_ring_is_full(ring_ctl)) {
        return OAL_FAIL;
    }
    write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;

    *(uint64_t *)((uint8_t *)(ring_ctl->p_entries) + ring_ctl->entry_size * write_idx) = entry;
    write_idx++;
    if (write_idx >= ring_ctl->entries) {
        /* 已到达ring的最后一个元素，index从0开始计数，并设置flag标志(flag翻转) */
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = 0;
        ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag = !ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag;
    } else {
        /* 未到达ring的最后一个元素，index递增，flag标志保存不变 */
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = write_idx;
    }

    return OAL_SUCC;
}

/*
 * 功能描述   : 更新host free ring 的写指针
 * 1.日    期   : 2019年4月12日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
void hal_update_free_ring_wptr(hal_host_ring_ctl_stru *ring_ctl, uint16_t count)
{
    uint16_t remains;
    uint16_t write_idx;

    if (hal_ring_is_full(ring_ctl)) {
        return;
    }

    write_idx = ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr;
    if (count + write_idx >= ring_ctl->entries) {
        remains = (count + write_idx) % ring_ctl->entries;
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr = remains;
        ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag =
            !ring_ctl->un_write_ptr.st_write_ptr.bit_wrap_flag;
    } else {
        ring_ctl->un_write_ptr.st_write_ptr.bit_write_ptr += count;
    }
    return;
}

void hal_host_ring_tx_deinit(hal_host_device_stru *hal_device)
{
    hal_device->ba_ring_type = INIT_BA_INFO_RING;
    hal_device->host_ba_info_ring.un_read_ptr.read_ptr = 0;
    hal_device->host_ba_info_ring.un_write_ptr.write_ptr = 0;
}

uint32_t hal_host_tx_dma_alloc_ring_buf(hal_host_tx_ring_buf_stru *ring_buf, uint32_t mem_size, uint8_t mirror)
{
#ifdef WIN32
    void *vaddr = NULL;
    vaddr = oal_mem_alloc_m(OAL_MEM_POOL_ID_LOCAL, mem_size, OAL_FALSE);
    if (vaddr == NULL) {
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }
    memset_s(vaddr, mem_size, 0, mem_size);
    ring_buf->ring_buf = (uint8_t *)vaddr;
    ring_buf->mem_size = mem_size;
#else
    void *vaddr = NULL;
    uint64_t dma_addr = 0;

    dpe_dma_buff_alloc(mem_size, &vaddr, &dma_addr, DPE_GFP_ATOMIC);
    if (vaddr == NULL) {
        oam_error_log1(0, OAM_SF_DPA, "{hal_host_tx_dma_alloc_ring_buf::dma_alloc_coherent size[%d] failed}", mem_size);
        return OAL_ERR_CODE_ALLOC_MEM_FAIL;
    }
    memset_s(vaddr, mem_size, 0, mem_size);
    ring_buf->ring_buf = (uint8_t *)vaddr;
    ring_buf->bus_addr = dma_addr;
    ring_buf->mem_size = mem_size;

    /* 是否需要孪生镜像Ring设计 */
    if ((dpe_is_bypass_tx_mirror_ring() == OAL_FALSE) && (mirror == 1)) {
        ring_buf->ddr_ring_buf = oal_memalloc(mem_size);
        if (ring_buf->ddr_ring_buf != NULL) {
            memset_s(ring_buf->ddr_ring_buf, mem_size, 0, mem_size);
        }
    } else {
        ring_buf->ddr_ring_buf = NULL;
    }

    oam_warning_log3(0, OAM_SF_DPA, "{hal_host_tx_dma_alloc_ring_buf::tx mirror %d mirror %d size[%d]}",
        dpe_is_bypass_tx_mirror_ring(), ring_buf->ddr_ring_buf != NULL, mem_size);
#endif
    return OAL_SUCC;
}

uint32_t hal_host_tx_dma_release_ring_buf(hal_host_tx_ring_buf_stru *ring_buf)
{
#ifdef WIN32
    oal_mem_free_m(ring_buf->ring_buf, OAL_TRUE);
#else
    uint8_t *ddr_ring_buf = NULL;
    if (ring_buf->ring_buf == NULL || !ring_buf->bus_addr || !ring_buf->mem_size) {
        return OAL_FAIL;
    }
    dpe_dma_buff_free(ring_buf->mem_size, ring_buf->ring_buf, ring_buf->bus_addr);
    oam_warning_log3(0, OAM_SF_DPA, "{hal_host_tx_dma_release_ring_buf::tx mirror %d mirror %d size[%d]}",
        dpe_is_bypass_tx_mirror_ring(), ring_buf->ddr_ring_buf != NULL, ring_buf->mem_size);

    if ((dpe_is_bypass_tx_mirror_ring() == OAL_FALSE) && (ring_buf->ddr_ring_buf != NULL)) {
        ddr_ring_buf = ring_buf->ddr_ring_buf;
        ring_buf->ddr_ring_buf = NULL;
        oal_free(ddr_ring_buf);
    }
#endif
    return OAL_SUCC;
}

/*
 * 功能描述   : 从rx complete ring中的硬件地址，获取skb地址
 * 1.日    期   : 2019年12月10日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
static oal_netbuf_stru* hal_get_skb_from_ring_entry(uint64_t hw_dscr_addr, hal_host_ring_ctl_stru *ring_ctl,
    hal_host_device_stru *hal_dev)
{
    int32_t                      ret;
    uint64_t                     host_iova   = 0;
    uint32_t                     pre_num     = 0;
    oal_netbuf_stru             *skb = NULL;
    hal_host_rx_alloc_list_stru *alloc_list  = &hal_dev->host_rx_normal_alloc_list;  // 接收完成 dma by list
    oal_uint lock_flag;

    if (oal_unlikely(hw_dscr_addr == 0)) {
        oam_error_log1(0, OAM_SF_DPA, "{hal_get_skb_from_ring_entry:rd_idx[%d], addr is zero!}",
            ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr);
        return NULL;
    }

    if (hal_dev->dscr_prev == hw_dscr_addr) {
        oam_error_log2(0, OAM_SF_DPA, "{hal_get_skb_from_ring_entry:duplicate dscr 0x%x%x!}",
            (uint32_t)(hw_dscr_addr >> NUM_32_BYTES), (uint32_t)(hw_dscr_addr));
    }

    hal_dev->dscr_prev = hw_dscr_addr;
    ret = pcie_if_devva_to_hostca(HCC_EP_WIFI_DEV, (uint64_t)hw_dscr_addr, (uint64_t *)&host_iova);
    if (ret != OAL_SUCC) {
        oam_warning_log0(0, OAM_SF_DPA, "{hal_get_skb_from_ring_entry:devva2hostca fail.}");
        return NULL;
    }

    /* 中断下半部补充netbuf可能也会操作此链表 */
    oal_spin_lock_irq_save(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &lock_flag);
    skb = hal_alloc_list_delete_netbuf(hal_dev, alloc_list, host_iova, &pre_num);
    dpe_wlan_rx_delay_notify(skb, 0, RX_BUFF_POOL_START);
    oal_spin_unlock_irq_restore(dpe_get_dev_rx_alloc_list_lock(alloc_list->rx_alloc_list_lock_idx), &lock_flag);

    if (skb == NULL) {
        oam_warning_log1(hal_dev->device_id, OAM_SF_DPA, "get_skb_from_ring_entry:not found skb pre num[%d]", pre_num);
        return NULL;
    }
    return skb;
}

uint32_t hal_host_rx_ring_entry_burst(hal_host_device_stru *hal_dev,
    hal_host_ring_ctl_stru *ring_ctl, oal_netbuf_head_stru *netbuf_head, uint16_t count)
{
    uint16_t             remaining_count = count;
    uint16_t             read_burst_cnt = 0;
    uint16_t             cur_idx = 0;
    oal_uint             lock_flag;
    uint32_t             ret;
    uint64_t             hw_dscr_addr;
    oal_netbuf_stru     *netbuf = NULL;

    while (remaining_count) {
        /* 并发式回读 */
        if (read_burst_cnt == 0) {
            read_burst_cnt = oal_min(remaining_count, DDR_BURST_READ_LEVEL);    /* burst read 16 nodes(128B) */
            cur_idx = 0;
            /* check burst read nodes non-zero */
            if (hal_host_comp_ring_wait_valid(hal_dev, ring_ctl, read_burst_cnt) != OAL_SUCC) {
                break;
            }
        }

        memcpy_s(&hw_dscr_addr, HAL_RX_ENTRY_SIZE, &(g_ddr_comp_ring_read[cur_idx]), HAL_RX_ENTRY_SIZE);
        cur_idx++;

        /* 更新rptr */
        hal_rx_comp_ring_update_rptr(ring_ctl, 1);
        
        if (dpe_is_support_isr_rx_sbuf_by_addr() != OAL_TRUE) {
            /* 从物理地址获取skb地址, skb从alloc list摘除 */
            netbuf = hal_get_skb_from_ring_entry(hw_dscr_addr,  ring_ctl, hal_dev);
            if (netbuf != NULL) {
                oal_netbuf_list_tail_nolock(netbuf_head, netbuf);
            }
        } else {
            /* rx comp ring读取物理地址存入缓存池, skb依然在alloc list */
            dpe_rx_mpdu_list_lock_irq_save(&hal_dev->st_rx_mpdu.st_spin_lock, &lock_flag);
            ret = hal_host_rx_add_buff_pool(hal_dev, hw_dscr_addr);
            dpe_rx_mpdu_list_unlock_irq_restore(&hal_dev->st_rx_mpdu.st_spin_lock, &lock_flag);
            if (ret != OAL_SUCC) {
                /* 未读取成功 */
                break;
            }
        }

        remaining_count--;
        read_burst_cnt--;
    }
    return remaining_count;
}

uint32_t hal_host_rx_ring_entry_single(hal_host_device_stru *hal_dev,
    hal_host_ring_ctl_stru *ring_ctl, oal_netbuf_head_stru *netbuf_head, uint16_t count)
{
    uint16_t             remaining_count;
    uint64_t             hw_dscr_addr;
    uint32_t             ret;
    oal_netbuf_stru     *netbuf = NULL;

    remaining_count = count;
    while (remaining_count) {
        /* 循环处理每一个元素 */
        if (hal_comp_ring_wait_valid(hal_dev, ring_ctl) != OAL_SUCC) {
            break;
        }
        /* 读取ring上的元素 */
        hw_dscr_addr = 0;
        ret = hal_ring_get_entries_without_reset(ring_ctl, (uint8_t *)&hw_dscr_addr, 1);
        if (oal_unlikely(ret != OAL_SUCC)) {
            oam_error_log1(0, OAM_SF_DPA, "{hal_host_rx_ring_entry_get::return code:%d.}", ret);
            break;
        }

        /* 更新rptr */
        hal_rx_comp_ring_update_rptr(ring_ctl, 1);
        /* 从物理地址获取skb地址 */
        netbuf = hal_get_skb_from_ring_entry(hw_dscr_addr,  ring_ctl, hal_dev);
        if (netbuf != NULL) {
            oal_netbuf_list_tail_nolock(netbuf_head, netbuf);
        }
        remaining_count--;
    }
    return remaining_count;
}
/*
 * 功能描述   : 从rx complete ring中取描述符地址
 * 1.日    期   : 2020年04月03日
 *   作    者   : wifi
 *   修改内容   : 新生成函数
 */
uint32_t hal_host_rx_ring_entry_get(hal_host_device_stru *hal_dev,
    hal_host_ring_ctl_stru *ring_ctl, oal_netbuf_head_stru *netbuf_head)
{
    uint16_t             count, reset_num, read_idx;
    uint32_t             ret;
    dpe_wlan_rx_async_stat_stru *rx_stats = NULL;

    if (oal_unlikely(oal_any_null_ptr3(hal_dev, ring_ctl, netbuf_head))) {
        oam_error_log0(0, OAM_SF_DPA, "{hal_host_rx_ring_entry_get::input para null.}");
        return OAL_ERR_CODE_PTR_NULL;
    }

    /* 从HAL获取ring元素的个数 */
    ret = hal_ring_get_entry_count(hal_dev, ring_ctl, &count);
    if (ret != OAL_SUCC) {
        oam_warning_log1(hal_dev->device_id, OAM_SF_DPA, "{hal_host_rx_ring_entry_get::return code %d.}", ret);
        return ret;
    }

    /* 记录起始位置和取走的元素数量，批量清零时使用 */
    read_idx = ring_ctl->un_read_ptr.st_read_ptr.bit_read_ptr;
    reset_num = count;

    if ((g_wlan_spec_cfg->support_ring_burst_access == OAL_TRUE) &&
        (dpe_is_support_rx_ring_read_single() != OAL_TRUE)) {
        count = hal_host_rx_ring_entry_burst(hal_dev, ring_ctl, netbuf_head, count);
    } else {
        count = hal_host_rx_ring_entry_single(hal_dev, ring_ctl, netbuf_head, count);
    }
    /* 批量清零，reset_num - count可以保证读取元素失败时，只清零已成功读取的部分 */
    if (reset_num != count) {
        hal_ring_reset_entries(ring_ctl, read_idx, reset_num - count);
    }
    rx_stats = dpe_wlan_rx_async_stat_get();
    if (dpe_is_support_isr_rx_sbuf_by_addr() == OAL_TRUE) {
        rx_stats->rx_isr_rpt_cnt += reset_num - count;
    } else {
        rx_stats->rx_isr_rpt_cnt += oal_netbuf_list_len(netbuf_head);
    }

    /* 更新complete ring的rptr指针 */
    return hal_ring_set_sw2hw(ring_ctl);
}

uint16_t hal_host_tx_rw_smaller_ptr(uint16_t rptr_val1, uint16_t rptr_val2, uint16_t wptr_val)
{
    un_rw_ptr rptr1 = { .rw_ptr = rptr_val1 };
    un_rw_ptr rptr2 = { .rw_ptr = rptr_val2 };
    un_rw_ptr wptr = { .rw_ptr = wptr_val };

    if (rptr1.rw_ptr == rptr2.rw_ptr) {
        return rptr_val1;
    }

    if (rptr1.st_rw_ptr.bit_wrap_flag == rptr2.st_rw_ptr.bit_wrap_flag) {
        return (rptr1.st_rw_ptr.bit_rw_ptr > rptr2.st_rw_ptr.bit_rw_ptr) ? rptr_val2 : rptr_val1;
    }
    /* wrap flag不同时 */
    if (rptr1.st_rw_ptr.bit_rw_ptr < rptr2.st_rw_ptr.bit_rw_ptr) {
        return rptr_val2;
    }
    if (rptr1.st_rw_ptr.bit_rw_ptr > rptr2.st_rw_ptr.bit_rw_ptr) {
        return rptr_val1;
    }
    /* wrap flag不同, bit_rw_ptr值相等时，返回和wptr flag不同的 */
    if (rptr1.st_rw_ptr.bit_wrap_flag == wptr.st_rw_ptr.bit_wrap_flag) {
        return rptr_val2;
    }
    return rptr_val1;
}