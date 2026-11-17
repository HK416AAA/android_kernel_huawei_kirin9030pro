/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明   : hmac_vsp.c 的头文件
 * 作者       : wifi
 * 创建日期   : 2020年12月24日
 */

#ifndef HMAC_VSP_H
#define HMAC_VSP_H

#ifdef CONFIG_VCODEC_VSP_SUPPORT
#include "platform_source/vcodec/vdec/include/vdec_vsp.h"
#include "platform_source/vcodec/venc/include/venc_vsp.h"

typedef struct _rx_slice_mgmt rx_slice_mgmt;
typedef struct _tx_layer_ctrl tx_layer_ctrl;
typedef struct _send_result send_result;
#else
#include "hmac_vsp_vcodec_stub.h"
#endif
#include "hmac_vsp_stat.h"
#include "hmac_vsp_log.h"
#include "hmac_tx_msdu_dscr.h"

#ifdef _PRE_WLAN_FEATURE_VSP
#define VSP_MSDU_CB_LEN 64

#define VSP_TIMESTAMP_NOT_USED 0
#define VSP_TIMESTAMP_VENC 1
#define VSP_TIMESTAMP_WIFI 2

#define VSP_FRAME_ID_MASK 0x3F
#define VSP_FRAME_ID_TOTAL 63
#define VSP_INVALID_FRAME_ID 0xff

#define VSP_LAYER_FEEDBACK_SIZE 2

#define MAX_VSP_INFO_COUNT 2

#define INVALID_LAYER_NUM (4)

#define MAX_BATCH_SIZE (64)

enum vsp_type {
    VSP_TYPE_VIDEO = 0,
    VSP_TYPE_SX = 1,
    VSP_TYPE_BUTT,
};

enum vsp_version {
    VSP_VERSION_1 = 0,
    VSP_VERSION_2 = 1,
    VSP_VERSION_BUTT,
};

#pragma pack(push, 1)
/* VSPbuffer头描述 */
struct vsp_msdu_hdr {
    uint8_t ra[WLAN_MAC_ADDR_LEN];
    uint8_t sa[WLAN_MAC_ADDR_LEN];
    uint16_t type;
    uint16_t video : 1,
             layer_num : 3,
             slice_num : 4,
             last : 1,
             max_layer : 3,
             ver : 4;
    uint16_t number;
    uint16_t len;
    uint32_t frame_id : 6,
             ts_type : 2,
             rsv_bits : 24;
    uint32_t timestamp; // 同last_vsync 当前视频帧vsync同步时间戳
    uint32_t cfg_pkt : 1,
             reserve : 31;
};
typedef struct vsp_msdu_hdr vsp_msdu_hdr_stru;

typedef struct {
    uint8_t ra[WLAN_MAC_ADDR_LEN];
    uint8_t sa[WLAN_MAC_ADDR_LEN];
    uint16_t type;
    uint16_t frm_id : 6,
            peer : 1,
            is_cfg_pkt : 1,
            layer_num : 4,
            slice_id : 4;
    uint16_t layer_succ_num[];
} vsp_feedback_frame;
#pragma pack(pop)

typedef struct {
    int slice_cnt;
    int layer_cnt;
    int max_payload;
    int header_len;
    int tmax; /* 第slice0数据最晚传输时间 不能超过一个视频帧 */
    int tslice; /* 每个slice帧持续时长 以60帧为例，1000/60 = 16ms 每个视频帧分4个slice，那么tslice则为4ms */
    int tfeedback;
    char sa[OAL_MAC_ADDR_LEN];
    char ra[OAL_MAC_ADDR_LEN];
    int feedback_pkt_len;
    int version; // 0-1.0 1-2.0版本
} vsp_param;

typedef struct {
    uint8_t enable; // bitmap形式: bit0-视频 bit1-键鼠
    uint8_t mode;   // recv side: 0, send side 1
    hal_mac_common_timer timer;
    uint8_t timer_running;
    hmac_tid_info_stru *tid_info[VSP_TYPE_BUTT]; // 0:视频-tid4 1:键鼠-tid5
    hmac_user_stru *hmac_user;
    hmac_vap_stru *hmac_vap;
    hal_host_device_stru *host_hal_device;
    uint32_t timer_ref_vsync; /* 当前正在计时的frame参照的vsync，接收端和发送端都使用 */
    vsp_param param;
    oal_spin_lock_stru vsp_lock; /* 用于vsp tx ring锁 */
} hmac_vsp_info_stru;

typedef struct  {
    tx_layer_ctrl* layer_list;
    uint16_t tx_succ_packet_number; // 反馈回写：总发送成功包数
    uint32_t tx_delay;              // 反馈信息：输入到发送完成总时长
    uint32_t tx_count;              // 反馈信息：所有pkt发送总次数
    uint32_t buffer_remain;         // 反馈信息：ring buffer剩余空间
    uint8_t tx_result[MAX_BATCH_SIZE / 8]; // 反馈信息：逐包发送结果 bitmap // 决定要重传哪个包
} send_result_sx;

struct vcodec_sx_callback {
    void (*wifi_tx_send_done)(send_result_sx*);
    void (*wifi_rx_msdu)(oal_netbuf_stru* netbuf);
};

typedef struct {
    rx_slice_mgmt *(*alloc_slice_mgmt)(uint32_t);
    void (*rx_slice_done)(rx_slice_mgmt*);
} hmac_vsp_vcodec_vdec_ops;

typedef struct {
    void (*wifi_tx_pkg_done)(send_result*);
    void (*wifi_tx_send_done)(send_result*);
    void (*wifi_rx_msdu)(uint8_t*, uint32_t);
} hmac_vsp_vcodec_venc_ops;

typedef struct {
    void (*wifi_tx_send_done)(send_result_sx*);
    void (*wifi_rx_msdu)(oal_netbuf_stru* netbuf);
} hmac_vsp_sx_ops;

extern hmac_vsp_vcodec_vdec_ops *g_vsp_vcodec_vdec_ops;
extern hmac_vsp_vcodec_venc_ops *g_vsp_vcodec_venc_ops;
extern hmac_vsp_sx_ops *g_vsp_sx_ops;

uint32_t hmac_vsp_init(
    hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param, uint8_t mode);
uint32_t hmac_vsp_mode_init(
    hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user, vsp_param *param, uint8_t mode);
void hmac_vsp_deinit(hmac_vsp_info_stru *vsp_info, uint8_t mode);
uint8_t hmac_vsp_get_type_bitmask_by_cmd(char mode);
hmac_vsp_info_stru *hmac_vsp_get_current_handle(void);
void hmac_vsp_record_vsync_ts(hmac_vsp_info_stru *vsp_info);
uint32_t hmac_vsp_get_timestamp(hmac_vsp_info_stru *vsp_info);
void hmac_vsp_stop_timer(hmac_vsp_info_stru *vsp_info);
void hmac_vsp_stop_timer_no_pm_wakeup(hmac_vsp_info_stru *vsp_info);
void hmac_vsp_set_slice_timeout(hmac_vsp_info_stru *vsp_info, uint8_t slice_id, uint8_t is_cfg_pkt);
void hmac_vsp_set_vcodec_vdec_ops(hmac_vsp_vcodec_vdec_ops *ops);
void hmac_vsp_set_vcodec_venc_ops(hmac_vsp_vcodec_venc_ops *ops);
void hmac_vsp_set_sx_ops(hmac_vsp_sx_ops *ops);
uint32_t hmac_vsp_context_init(hmac_vsp_info_stru *vsp_info, hmac_vap_stru *hmac_vap, hmac_user_stru *hmac_user,
    uint8_t mode);
void hmac_vsp_context_deinit(hmac_vsp_info_stru *vsp_info, uint8_t mode);
void hmac_vsp_set_current_handle(hmac_vsp_info_stru *vsp_info);
hmac_vsp_info_stru *hmac_vsp_get_current_handle(void);
hmac_vsp_info_stru *hmac_vsp_get_common_info(void);
uint8_t hmac_vsp_get_type_by_mode(char mode);
static inline rx_slice_mgmt *vsp_vcodec_alloc_slice_mgmt(uint32_t size)
{
    if (!g_vsp_vcodec_vdec_ops->alloc_slice_mgmt) {
        return NULL;
    }
    return g_vsp_vcodec_vdec_ops->alloc_slice_mgmt(size);
}
static inline void vsp_vcodec_rx_slice_done(rx_slice_mgmt *rx_slice)
{
    if (!g_vsp_vcodec_vdec_ops->rx_slice_done) {
        return;
    }
    g_vsp_vcodec_vdec_ops->rx_slice_done(rx_slice);
}
static inline void vsp_vcodec_tx_pkt_done(send_result *snd_res)
{
    if (!g_vsp_vcodec_venc_ops->wifi_tx_pkg_done) {
        return;
    }
    g_vsp_vcodec_venc_ops->wifi_tx_pkg_done(snd_res);
}
static inline void vsp_vcodec_tx_send_done(send_result *snd_res)
{
    if (!g_vsp_vcodec_venc_ops->wifi_tx_send_done) {
        return;
    }
    g_vsp_vcodec_venc_ops->wifi_tx_send_done(snd_res);
}
static inline void vsp_vcodec_rx_msdu(uint8_t* msdu_data, uint32_t len)
{
    if (!g_vsp_vcodec_venc_ops->wifi_rx_msdu) {
        return;
    }
    g_vsp_vcodec_venc_ops->wifi_rx_msdu(msdu_data, len);
}
static inline void vsp_sx_tx_send_done(send_result_sx *snd_res)
{
    if (!g_vsp_sx_ops->wifi_tx_send_done) {
        return;
    }
    g_vsp_sx_ops->wifi_tx_send_done(snd_res);
}
static inline void vsp_sx_rx_msdu(oal_netbuf_stru* netbuf)
{
    if (!g_vsp_sx_ops->wifi_rx_msdu) {
        return;
    }
    g_vsp_sx_ops->wifi_rx_msdu(netbuf);
}
static inline uint8_t hmac_is_vsp_user(hmac_user_stru *hmac_user)
{
    hmac_vsp_info_stru *vsp_info = hmac_user->vsp_hdl;

    return vsp_info && vsp_info->enable;
}

static inline uint8_t hmac_is_vsp_tid(hmac_user_stru *hmac_user, uint8_t tidno)
{
    return hmac_is_vsp_user(hmac_user) && (tidno == WLAN_TIDNO_VSP || tidno == WLAN_TIDNO_VIDEO);
}

static inline uint8_t hmac_vsp_is_video_enable(hmac_vsp_info_stru *vsp_info)
{
    return ((vsp_info->enable & BIT(VSP_TYPE_VIDEO)) != 0);
}

static inline uint8_t hmac_vsp_is_sx_enable(hmac_vsp_info_stru *vsp_info)
{
    return ((vsp_info->enable & BIT(VSP_TYPE_SX)) != 0);
}

static inline uint32_t hmac_vsp_calc_runtime(uint32_t start, uint32_t end)
{
    return end - start;
}

static inline uint8_t hmac_vsp_tid_ring_empty(hmac_vsp_info_stru *vsp_info)
{
    return hmac_tid_ring_empty(&vsp_info->tid_info[VSP_TYPE_VIDEO]->tx_ring);
}

static inline mac_user_stru *hmac_vsp_info_get_mac_user(hmac_vsp_info_stru *vsp_info)
{
    return &vsp_info->hmac_user->st_user_base_info;
}

static inline mac_vap_stru *hmac_vsp_info_get_mac_vap(hmac_vsp_info_stru *vsp_info)
{
    return &vsp_info->hmac_vap->st_vap_base_info;
}

static inline uint8_t *hmac_vsp_info_get_mac_ra(hmac_vsp_info_stru *vsp_info)
{
    return hmac_vsp_info_get_mac_user(vsp_info)->auc_user_mac_addr;
}

static inline uint8_t *hmac_vsp_info_get_mac_sa(hmac_vsp_info_stru *vsp_info)
{
    return mac_mib_get_StationID(hmac_vsp_info_get_mac_vap(vsp_info));
}

static inline uint8_t hmac_vsp_info_get_vap_id(hmac_vsp_info_stru *vsp_info)
{
    return hmac_vsp_info_get_mac_vap(vsp_info)->uc_vap_id;
}

static inline uint16_t hmac_vsp_info_get_user_id(hmac_vsp_info_stru *vsp_info)
{
    return hmac_vsp_info_get_mac_user(vsp_info)->us_assoc_id;
}

static inline uint16_t hmac_vsp_info_get_feedback_pkt_len(hmac_vsp_info_stru *vsp_info)
{
    return vsp_info->param.feedback_pkt_len;
}

static inline uint16_t hmac_vsp_info_get_layer_num(hmac_vsp_info_stru *vsp_info)
{
    return vsp_info->param.layer_cnt;
}


#endif
#endif
