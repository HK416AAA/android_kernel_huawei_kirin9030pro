/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : hmac_rx_reorder.c 的头文件
 * 作    者 :
 * 创建日期 : 2013年4月8日
 */

#ifndef HMAC_RX_REORDER_H
#define HMAC_RX_REORDER_H

/* 1 其他头文件包含 */
#include "oal_ext_if.h"
#include "hmac_ext_if.h"
#include "hmac_rx.h"
#include "mac_frame_inl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RX_REORDER_H

#define DMAC_BA_MAX_SEQNO_BY_TWO          2048
#define DMAC_BA_GREATER_THAN_SEQHI  1
#define DMAC_BA_BETWEEN_SEQLO_SEQHI 2

#define HMAC_BA_SEQNO_MASK              0x0FFF /* max sequece number */
#define hmac_ba_seqno_sub(_seq1, _seq2) (((_seq1) - (_seq2)) & HMAC_BA_SEQNO_MASK)
#define hmac_ba_seqno_add(_seq1, _seq2) (((_seq1) + (_seq2)) & HMAC_BA_SEQNO_MASK)
#define MAX_BA_SN    4095
#define HMAC_U32_MAX 0xffffffff

#define ADDBA_EXTENDED_BUFFER_SIZE_MASK   0xE0
#define ADDBA_EXTENDED_BUFFER_SIZE_OFFSET 0x5
#define ADDBA_EXTENDED_BUFFER_SIZE_UNIT   1024 /* buffer size:Extended Buffer Size × 1024 + Buffer Size */

typedef struct {
    uint8_t tidno;
    uint8_t dialog_token;               /* ADDBA交互帧的dialog token */
    uint8_t ba_policy;                  /* Immediate=1 Delayed=0 */
    oal_bool_enum_uint8 amsdu_supp;     /* BLOCK ACK支持AMSDU的标识 */
    uint16_t status_code;               /* 返回状态码 */
    uint16_t ba_timeout;                /* BA会话交互超时时间 */
    uint16_t baw_size;
    uint8_t extension_ie_received;     /* 接收到addba extension IE,则addba rsp中也要带此IE */
    uint8_t addba_para_set; /* ADDBA Additional Parameter Set */
} hmac_ba_rx_rsp_stru;

typedef struct {
    uint8_t no_frag              : 1;
    uint8_t he_frag_oper         : 2;
    uint8_t reserved             : 2;
    uint8_t extended_buffer_size : 3;
} hmac_addba_exten_ie_stru;

typedef union {
    uint8_t                     value;
    hmac_addba_exten_ie_stru    exten_ie;
} hmac_addba_exten_ie_union;
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 inline函数定义 */
/*
 * 函 数 名  : hmac_ba_rx_seqno_lt
 * 功能描述  : 判断seq1是否小于seq2
 * 1.日    期  : 2014年8月15日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_rx_seqno_lt(uint16_t us_seq1, uint16_t us_seq2)
{
    return (((us_seq1 < us_seq2) && ((us_seq2 - us_seq1) < DMAC_BA_MAX_SEQNO_BY_TWO)) ||
            ((us_seq1 > us_seq2) && ((us_seq1 - us_seq2) > DMAC_BA_MAX_SEQNO_BY_TWO)));
}

/*
 * 函 数 名  : dmac_ba_rx_seqno_gt
 * 功能描述  : 判断seq1是否大于seq2
 * 1.日    期  : 2014年8月15日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_rx_seqno_gt(uint16_t us_seq1, uint16_t us_seq2)
{
    return hmac_ba_rx_seqno_lt(us_seq2, us_seq1);
}

/*
 * 函 数 名  : dmac_ba_seqno_lt
 * 功能描述  : 判断seq1是否小于seq2
 * 1.日    期  : 2013年4月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_seqno_lt(uint16_t us_seq1, uint16_t us_seq2)
{
    return (((us_seq1 < us_seq2) && ((us_seq2 - us_seq1) < DMAC_BA_MAX_SEQNO_BY_TWO)) ||
            ((us_seq1 > us_seq2) && ((us_seq1 - us_seq2) > DMAC_BA_MAX_SEQNO_BY_TWO)));
}

/*
 * 函 数 名  : dmac_ba_seqno_gt
 * 1.日    期  : 2013年4月15日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_seqno_gt(uint16_t us_seq1, uint16_t us_seq2)
{
    return hmac_ba_seqno_lt(us_seq2, us_seq1);
}

/*
 * 函 数 名  : hmac_ba_rx_seqno_leq
 * 功能描述  : 判断seq1是否小于或等于seq2
 * 1.日    期  : 2014年8月15日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_rx_seqno_leq(uint16_t us_seq1, uint16_t us_seq2)
{
    return (((us_seq1 <= us_seq2) && ((us_seq2 - us_seq1) < DMAC_BA_MAX_SEQNO_BY_TWO)) ||
            ((us_seq1 > us_seq2) && ((us_seq1 - us_seq2) > DMAC_BA_MAX_SEQNO_BY_TWO)));
}

/*
 * 函 数 名  : hmac_ba_rx_seqno_geq
 * 功能描述  : 判断seq1是否大于或等于seq2
 * 1.日    期  : 2014年8月15日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_rx_seqno_geq(uint16_t us_seq1, uint16_t us_seq2)
{
    return hmac_ba_rx_seqno_leq(us_seq2, us_seq1);
}

/* 计算seq num到ba窗start的偏移量 */
#define hmac_ba_index(_st, _seq) (((_seq) - (_st)) & 0xFFF)

#define HMAC_RX_BUF_BITMAP_LOG2_WORD_SIZE 5 /* 5代表log2(32) = 5 */
/* 发送BA窗口记录seq number的bitmap所使用的类型长度 */
#define HMAC_RX_BUF_BITMAP_WORD_SIZE 32

#define HMAC_RX_BUF_BITMAP_WORD_MASK (HMAC_RX_BUF_BITMAP_WORD_SIZE - 1)

static inline void hmac_rx_buf_bitmap_set(uint32_t *bitmap, uint16_t idx)
{
    if ((idx >> HMAC_RX_BUF_BITMAP_LOG2_WORD_SIZE) >= BYTE_OFFSET_8) {
        return;
    }
    bitmap[idx >> HMAC_RX_BUF_BITMAP_LOG2_WORD_SIZE] |= (1 << (idx & HMAC_RX_BUF_BITMAP_WORD_MASK));
}

static inline void hmac_rx_buf_bitmap_clr(uint32_t *bitmap, uint16_t idx)
{
    if ((idx >> HMAC_RX_BUF_BITMAP_LOG2_WORD_SIZE) >= BYTE_OFFSET_8) {
        return;
    }
    bitmap[idx >> HMAC_RX_BUF_BITMAP_LOG2_WORD_SIZE] &= ~((uint32_t)(1 << (idx & HMAC_RX_BUF_BITMAP_WORD_MASK)));
}

/* 重排序队列保留bitmap用于缓存乱序帧 */
#define HMAC_BA_BMP_SIZE 64

/* 判断index为n 在bitmap中的bit位是否是1 */
static inline oal_bool_enum_uint8 hmac_ba_isset_m(uint32_t *bm, uint16_t n)
{
    return ((n < (HMAC_BA_BMP_SIZE)) && (bm[n >> BIT_OFFSET_5] & (1 << (n & 31)))); // BA BMP MASK 31
}

/* 判断一个seq num是否在发送窗口内 */
static inline oal_bool_enum_uint8 hmac_baw_within(uint16_t start, uint8_t bawsz, uint16_t seqno)
{
    return ((seqno >= start) ? (((seqno - start) & 0xFFF) < bawsz) : (((seqno + 0x1000 - start) & 0xFFF) < bawsz));
}

/* 判断一个seq num是否在发送窗口右边 */
static inline oal_bool_enum_uint8 hmac_baw_rightside(uint16_t start, uint16_t seqno)
{
    return (((seqno >= start) ? (((seqno - start) & 0xFFF) < (0x800)) :
            (((seqno + 0x10000 - start) & 0xFFF) < (0x800))) && (start != seqno));
}

/*
 * 函 数 名  : hmac_ba_isset
 * 1.日    期  : 2015年5月4日
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE oal_bool_enum_uint8 hmac_ba_isset(hmac_ba_rx_stru *pst_ba_rx_hdl, uint16_t us_seqno)
{
    uint16_t us_index;

    if (hmac_baw_within(pst_ba_rx_hdl->us_baw_head, HMAC_BA_BMP_SIZE, us_seqno)) {
        us_index = us_seqno & (HMAC_BA_BMP_SIZE - 1);

        if (hmac_ba_isset_m(pst_ba_rx_hdl->aul_rx_buf_bitmap, us_index)) {
            return OAL_TRUE;
        }
    }

    return OAL_FALSE;
}

/*
 * 函 数 名  : hmac_ba_addto_rx_bitmap
 * 1.日    期  : 2016年3月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_ba_addto_rx_bitmap(hmac_ba_rx_stru *pst_ba_rx_hdl, uint16_t us_seqno)
{
    uint16_t us_index;

    if (hmac_baw_within(pst_ba_rx_hdl->us_baw_head, HMAC_BA_BMP_SIZE, us_seqno)) {
        us_index = us_seqno & (HMAC_BA_BMP_SIZE - 1);
        hmac_rx_buf_bitmap_set(pst_ba_rx_hdl->aul_rx_buf_bitmap, us_index);
    }
}

/*
 * 函 数 名  : hmac_ba_clear_rx_bitmap
 * 1.日    期  : 2016年3月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE void hmac_ba_clear_rx_bitmap(hmac_ba_rx_stru *pst_ba_rx_hdl)
{
    uint16_t us_index;

    us_index = mac_ba_seqno_sub(pst_ba_rx_hdl->us_baw_head, 1) & (HMAC_BA_BMP_SIZE - 1);
    hmac_rx_buf_bitmap_clr(pst_ba_rx_hdl->aul_rx_buf_bitmap, us_index);
}

/*
 * 函 数 名  : hmac_ba_seqno_bound_chk
 * 功能描述  : This function compares the given sequence number with the specified
 *                upper and lower bounds and returns its position relative to them.
 * 1.日    期  : 2013年4月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE uint8_t hmac_ba_seqno_bound_chk(uint16_t us_seq_lo, uint16_t us_seq_hi, uint16_t us_seq)
{
    oal_bool_enum_uint8 en_lo_chk;
    oal_bool_enum_uint8 en_hi_chk;
    uint8_t uc_chk_res = 0;

    en_lo_chk = hmac_ba_rx_seqno_leq(us_seq_lo, us_seq);
    en_hi_chk = hmac_ba_rx_seqno_leq(us_seq, us_seq_hi);
    if ((en_lo_chk == OAL_TRUE) && (en_hi_chk == OAL_TRUE)) {
        uc_chk_res = DMAC_BA_BETWEEN_SEQLO_SEQHI;
    } else if (en_hi_chk == OAL_FALSE) {
        uc_chk_res = DMAC_BA_GREATER_THAN_SEQHI;
    }

    return uc_chk_res;
}

/* This function reads out the TX-Dscr indexed by the specified sequence number in */
/* the Retry-Q Ring-Buffer. */
OAL_STATIC OAL_INLINE hmac_rx_buf_stru *hmac_get_ba_rx_dhl(hmac_ba_rx_stru *ba_rx_hdl, uint16_t idx)
{
    return &(ba_rx_hdl->ast_re_order_list[idx]);
}
/*
 * 函 数 名  : dmac_get_frame_from_reorder_q
 * 功能描述  : This function reads out the TX-Dscr indexed by the specified sequence number in
 *             the Retry-Q Ring-Buffer.
 * 1.日    期  : 2013年4月11日
 *   作    者  : wifi
 *   修改内容  : 新生成函数
 */
OAL_STATIC OAL_INLINE hmac_rx_buf_stru *hmac_get_ba_rx_dhl_by_seq(
    hmac_ba_rx_stru *pst_ba_rx_hdl, uint16_t us_seq_num)
{
    uint16_t us_idx = (us_seq_num & (WLAN_AMPDU_RX_HE_BUFFER_SIZE - 1));
    hmac_rx_buf_stru *pst_rx_buff = hmac_get_ba_rx_dhl(pst_ba_rx_hdl, us_idx);

    if ((pst_rx_buff->in_use == 0) || (pst_rx_buff->us_seq_num != us_seq_num)) {
        return NULL;
    }

    return pst_rx_buff;
}
OAL_STATIC OAL_INLINE uint8_t hmac_ba_get_lut_index(uint8_t *puc_ba_lut_index_table,
                                                    uint16_t us_start,
                                                    uint16_t us_stop)
{
    return oal_get_lut_index(puc_ba_lut_index_table, MAC_RX_BA_LUT_BMAP_LEN, HAL_MAX_RX_BA_LUT_SIZE, us_start, us_stop);
}

OAL_STATIC OAL_INLINE void hmac_ba_del_lut_index(uint8_t *puc_ba_lut_index_table, uint8_t uc_lut_index)
{
    oal_del_lut_index(puc_ba_lut_index_table, uc_lut_index);
}
/* buffer size: Extended Buffer Size × 1024 + Buffer Size */
OAL_STATIC OAL_INLINE uint16_t hmac_addba_get_buffer_size(uint16_t buffer_size)
{
    return buffer_size % ADDBA_EXTENDED_BUFFER_SIZE_UNIT;
}

OAL_STATIC OAL_INLINE uint8_t hmac_addba_get_extended_buffer_size(uint16_t buffer_size)
{
    return (uint8_t)(buffer_size / ADDBA_EXTENDED_BUFFER_SIZE_UNIT);
}

/*****************************************************************************
  10 数声明
*****************************************************************************/
#ifdef _PRE_MULTI_CORE_DPE_OFFLOAD
int hmac_ba_timeout_fn(int p_arg);
#else
uint32_t hmac_ba_timeout_fn(void *p_arg);
#endif
void hmac_ba_send_frames_add_list(hmac_rx_buf_stru *pst_rx_buf, oal_netbuf_stru *pst_netbuf,
    oal_netbuf_head_stru *pst_netbuf_header);
void hmac_ba_update_rx_bitmap(uint16_t user_idx, mac_ieee80211_frame_stru *pst_frame_hdr);
void hmac_reorder_ba_rx_buffer_bar(uint16_t user_idx, uint8_t tidno, uint16_t us_start_seq_num);
uint32_t hmac_ba_reset_rx_handle(uint16_t user_idx, uint8_t uc_tid, oal_bool_enum_uint8 en_is_aging);
uint32_t hmac_ba_send_reorder_timeout(hmac_ba_rx_stru *rx_ba, dpe_wlan_vap_stru *dpe_vap,
    hmac_ba_alarm_stru *alarm_data, uint32_t *timeout);
uint16_t hmac_ba_send_frames_in_order(hmac_ba_rx_stru *pst_ba_rx_hdl, oal_netbuf_head_stru *pst_netbuf_header,
    hmac_tid_ba_stru *hmac_tid);
uint32_t hmac_ba_send_frames_with_gap(hmac_ba_rx_stru *pst_ba_rx_hdl, hmac_tid_ba_stru *hmac_tid,
    oal_netbuf_head_stru *pst_netbuf_header, uint16_t us_last_seqnum);
void hmac_ba_flush_reorder_q(hmac_ba_rx_stru *pst_rx_ba);
uint32_t hmac_rx_proc_reorder(hmac_host_rx_context_stru *rx_context,
    oal_netbuf_head_stru *rpt_list, uint8_t *buff_is_valid);
uint32_t hmac_ba_check_rx_aggrate(dpe_wlan_vap_stru *dpe_vap, mac_rx_ctl_stru *rx_ctl, dpe_wlan_user_stru *dpe_user);
void hmac_ba_rx_hdl_hold(hmac_ba_rx_stru *ba_rx_hdl);
void hmac_ba_rx_hdl_put(hmac_ba_rx_stru *ba_rx_hdl);
uint32_t hmac_ba_rx_data_release(hmac_host_rx_context_stru *rx_context,
    hmac_ba_rx_stru *ba_rx_hdl, oal_netbuf_head_stru *rpt_list, uint8_t *buff_is_valid);
uint32_t hmac_ba_rx_data_buffer(hmac_host_rx_context_stru *rx_context,
    hmac_ba_rx_stru *ba_rx_hdl, oal_netbuf_head_stru *rpt_list, uint8_t *buff_is_valid);
uint32_t hmac_ba_send_ring_reorder_timeout(hmac_ba_rx_stru *rx_ba, dpe_wlan_vap_stru *dpe_vap,
    hmac_ba_alarm_stru *alarm_data, uint32_t *p_timeout);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_rx_reorder.h */
