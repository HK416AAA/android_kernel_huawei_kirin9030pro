/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2021-2023. All rights reserved.
 * 功能说明 : HOST HAL DEVICE
 * 作    者 : wifi
 * 创建日期 : 2020年03月17日
 */
#ifndef HOST_HAL_DEVICE_H
#define HOST_HAL_DEVICE_H

#include "oal_ext_if.h"
#include "frw_ext_if.h"
#include "hal_common.h"
#include "mac_common.h"
#include "hd_event.h"
#include "wlan_spec_cfg.h"
#include "wlan_spec_host.h"
#ifndef _PRE_MULTI_CORE_DPE_OFFLOAD
#include "wlan_oneimage_define.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef enum {
    HAL_COMMON_TIMER_MODE_ONE_SHOT = 0,
    HAL_COMMON_TIMER_MODE_CIRCULAR,

    HAL_COMMON_TIMER_MODE_BUTT,
} hal_common_timer_mode_enum;
typedef uint8_t hal_common_timer_mode_enum_uint8;

typedef enum {
    HAL_COMMON_TIMER_UNIT_Point1US = 0,
    HAL_COMMON_TIMER_UNIT_1US,
    HAL_COMMON_TIMER_UNIT_RESERVED,
    HAL_COMMON_TIMER_UNIT_1MS,

    HAL_COMMON_TIMER_UNIT_BUTT,
} hal_common_timer_unit_enum;
typedef uint8_t hal_common_timer_unit_enum_uint8;

typedef struct  {
    uint32_t base_lsb;
    uint32_t base_msb;
    uint32_t len;
    uint32_t size;
    uint32_t wptr_reg;
    uint32_t rptr_reg;
    uint32_t cfg_wptr_reg;
    uint32_t cfg_rptr_reg;
    uint32_t rx_ring_reset;
} hal_ring_mac_regs_info;

/* MAC指针上报到Host的结构 */
typedef struct {
    uint16_t ptr;
    uint16_t reserved_0;
} hal_rx_ring_mac_ptr_info;

/* MAC指针上报Host的相关地址和寄存器配置 */
typedef struct {
    uint64_t rbase_bus_addr;              /* MAC指针上报到Host DDR的dma地址 */
    uint32_t ring_ptr_rpt_mode;             /* MAC指针上报模式配置寄存器 */
    uint32_t mac_ptr_rpt_host_addr_lsb;     /* MAC指针上报Host DDR低32位地址 */
    uint32_t mac_ptr_rpt_host_addr_msb;     /* MAC指针上报Host DDR高32位地址 */
} hal_rx_ring_mac_ptr_addr;

#define HMAC_MSDU_RX_MAX_BUFF_NUM    1024

/* 接收PING-PANG队列 */
#define HAL_MPDU_RXQ_NUM             2
#define HAL_HOST_RX_NORMAL_BUFF_NUM  512
#define HAL_HOST_RX_SMALL_BUFF_NUM   64
#define HAL_HOST_BAINFO_NUM          64
#define HAL_HOST_CMP_RING_NUM       (HAL_HOST_RX_NORMAL_BUFF_NUM + HAL_HOST_RX_SMALL_BUFF_NUM)
#define HAL_RX_MSDU_ADDR_BUCKET_NUM  HMAC_MSDU_RX_MAX_BUFF_NUM
#define HAL_RX_MSDU_ADDR_NODE_NUM   (HMAC_MSDU_RX_MAX_BUFF_NUM * 4)
#define RXQ_NUM                      2
#define HAL_MAX_LUT                  WLAN_ASSOC_USER_MAX_NUM
#define CSI_INFO_LEN 19
#define HMAC_CSI_BUFF_SIZE (1024 * 15) /* 4x4 最大27104字节，160M抽取减半 */

typedef struct {
    uint32_t nfree_ring_add;
    uint32_t sfree_ring_add;
    uint32_t comp_ring_get;
    uint32_t rx_exception_free_cnt;
} hal_rx_buf_statics;


typedef struct {
    /* ring的类型: free ring或者complete ring */
    uint8_t ring_type;
    uint8_t ring_subtype;
    uint16_t resv;
    /* ring的深度 */
    uint16_t entries;
    /* ring中每个元素的大小,例如, BA info元素大小64字节 */
    uint16_t entry_size;
    /* 软件操作的 */
    union {
        uint16_t read_ptr; /* read index */
        struct {
            uint16_t bit_read_ptr  : 15,
                     bit_wrap_flag : 1;
        } st_read_ptr;
    } un_read_ptr;

    union {
        uint16_t write_ptr; /* write index */
        struct {
            uint16_t bit_write_ptr : 15,
                     bit_wrap_flag : 1;
        } st_write_ptr;
    } un_write_ptr;

    /* ring基地址 */
    uint64_t *p_entries;
    uint64_t devva;

    /* 寄存器地址 */
    volatile uint64_t write_ptr_reg;
    volatile uint64_t read_ptr_reg;
    volatile uint64_t ring_size_reg;
    volatile uint64_t ring_base_reg;
    volatile uint64_t cfg_write_ptr_reg;
    volatile uint64_t cfg_read_ptr_reg;
    volatile uint64_t base_lsb;
    volatile uint64_t base_msb;
    volatile uint64_t len_reg;
    volatile uint64_t rx_ring_reset;
} hal_host_ring_ctl_stru;

typedef enum {
    HAL_RING_TYPE_L_F,
    /* Free ring: 软件操作write ptr, HW操作read ptr */
    HAL_RING_TYPE_S_F,
    /* Complete ring: 软件操作read ptr, HW操作write ptr */
    HAL_RING_TYPE_COMP,
    /* Tx complete ba ring: 软件操作read ptr, HW操作write ptr */
    TX_BA_INFO_RING,
#ifdef _PRE_WLAN_FEATURE_SNIFFER
    /* Rx ppdu free ring: 存放从device拷贝到host的rx ppdu描述符数据结构 */
    HAL_RING_TYPE_P_F,
#endif
    HAL_RING_ID_BUTT
} hal_host_ring_id_enum;

/* MAC上报host ring指针类型枚举（负载优化需求） */
typedef enum {
    HAL_RX_NORM_DATA_FREE_RPTR,
    HAL_RX_SMALL_DATA_FREE_RPTR,
    HAL_RX_NORM_MGMT_FREE_RPTR,
    HAL_RX_SMALL_MGMT_FREE_RPTR,
    HAL_RX_LARGE_MGMT_FREE_RPTR,
    HAL_RX_PPDU_DESC_FREE_RPTR,
    HAL_RX_PPDU_HOST_DESC_FREE_RPTR,
    HAL_RX_DATA_COMP_WPTR,
    HAL_RX_MGMT_COMP_WPTR,
    HAL_RX_PPDU_DESC_COMP_WPTR,
    HAL_MAC_PTR_RPT_HOST_BUTT
} hal_mac_ptr_rpt_host_enum;

typedef struct {
    volatile uint64_t irq_status_reg;
    volatile uint64_t irq_status_mask_reg;
    volatile uint64_t irq_clr_reg;
    volatile uint64_t tsf_lo_reg;
    volatile uint64_t irq_common_status_reg;
    volatile uint64_t irq_common_status_mask_reg;
    volatile uint64_t irq_common_clr_reg;
} hal_host_mac_regs;

typedef struct {
    volatile uint64_t w_soft_int_set_aon_reg;
    volatile uint64_t host_intr_raw_status_reg;
    volatile uint64_t host_intr_mask_reg;
    volatile uint64_t host_intr_status_reg;
} hal_host_soc_regs;

typedef struct {
    volatile uint64_t irq_status_reg;
    volatile uint64_t irq_status_mask_reg;
    volatile uint64_t irq_clr_reg;
    volatile uint64_t irq_status_reg2;
    volatile uint64_t irq_status_mask_reg2;
    volatile uint64_t irq_clr_reg2;
} hal_host_phy_regs;

typedef struct {
    volatile uint8_t inited;
    /* 基地址 */
    void *rbase_vaddr;
    uint64_t rbase_bus_addr;              /* MAC指针上报到Host DDR的dma地址 */
    uint64_t devva;
    /* 寄存器地址 */
    volatile uint64_t base_lsb;
    volatile uint64_t base_msb;
    volatile uint64_t size;
    volatile uint64_t csi_pro_reg;
    volatile uint64_t chn_set;
    volatile uint64_t rx_ctrl_reg;
    volatile uint64_t white_addr_msb;
    volatile uint64_t white_addr_lsb;
    volatile uint64_t location_info;
    volatile uint64_t csi_info_lsb;
    volatile uint64_t csi_info_msb;
} hal_host_csi_regs;

typedef struct {
    /* MAC通用定时器 */
    uint8_t timer_id;                            /* 定时器id */
    volatile uint64_t mask_reg_addr;            /* mask寄存器 */
    volatile uint64_t timer_ctrl_addr;          /* timer ctrl寄存器 */
    volatile uint64_t timer_val_addr;           /* tmer val超时值 */
    oal_bool_enum_uint8 timer_en;                /* 是否使能定时器 */
    oal_bool_enum_uint8 timer_mask_en;           /* 是否屏蔽中断 */
    hal_common_timer_mode_enum_uint8 timer_mode; /* 定时器触发方式 */
    hal_common_timer_unit_enum_uint8 timer_unit; /* 定时器精度 */
    uint32_t common_timer_val;                   /* 通用定时器定时值配置 */
    uint32_t start_time;
    void (*func)(void*);
} hal_mac_common_timer;

typedef struct {
    volatile uint8_t inited;
    /* 基地址 */
    void *rbase_vaddr;
    uint64_t rbase_bus_addr;              /* MAC指针上报到Host DDR的dma地址 */
    uint64_t devva;
    /* 寄存器地址 */
    volatile uint64_t base_lsb;
    volatile uint64_t base_msb;
    volatile uint64_t ftm_pro_reg;
    volatile uint64_t ftm_cfg_reg;
    volatile uint64_t ftm_cali_reg;
    volatile uint64_t fifo_force_reg;
    volatile uint64_t rx_ctrl_reg;
    volatile uint64_t white_addr_msb;
    volatile uint64_t white_addr_lsb;
    volatile uint64_t ftm_info_lsb;
    volatile uint64_t ftm_info_msb;
    volatile uint64_t ftm_phy_bw_mode;
    volatile uint64_t ftm_gc_weak_sig_en;
} hal_host_ftm_regs;

/* device 申请hal vap 同步给hmac */
typedef struct {
    uint8_t hal_vap_valid;
    uint8_t mac_vap_id;
} hal_vap_status_info;

typedef struct {
    uint8_t user_valid;
    uint16_t user_id;
} hal_user_status_info;

typedef struct {
    uint32_t                          rx_ppdu_succ_num;
    uint32_t                          rx_normal_mdpu_succ_num;
    uint32_t                          rx_ampdu_succ_num;
    uint32_t                          rx_ppdu_fail_num;
    uint32_t                          rx_delimiter_pass_mdpu_num;
    uint32_t                          rx_fcs_pass_mdpu_num;
    uint32_t                          rx_first_delimiter_err;
    uint32_t                          rx_first_fcs_err;
    int16_t                           s_always_rx_rssi;

    hal_device_always_rx_state_enum   en_al_rx_flag;
    int8_t                            c_rpt_rssi_lltf_ant0;
    int8_t                            c_rpt_rssi_lltf_ant1;
    uint8_t                           auc_resv[3];  /* 3 对齐 */
} mac_al_rx_stru;

typedef struct {
    oal_netbuf_head_stru    rx_alloc_list;
    uint8_t                 rx_alloc_list_lock_idx;
}hal_host_rx_alloc_list_stru;

typedef struct {
    oal_dlist_head_stru list_head;
    uint32_t list_num;
}hal_host_rx_ppdu_dscr_list_head_stru;

typedef enum {
    INIT_BA_INFO_RING,
    HOST_BA_INFO_RING,
    DEVICE_BA_INFO_RING,
} hal_ba_info_ring_type_enum;

typedef struct {
    oal_atomic    rx_mode;
} dpe_hal_dev_atomic_var;

typedef struct {
    uint8_t                            chip_id;
    uint8_t                            device_id;      /* 此id用来获取hal device */
    uint8_t                            mac_device_id;  /* 此id用来获取mac dmac hmac device */
    uint8_t                            rx_q_inited;
    uint8_t                            rx_alloc_list_inited;

    uint8_t                            host_ba_ring_regs_inited;
    uint8_t                            intr_inited;
    uint8_t                            is_al_tx_flag;
    uint8_t                            mac_intr_error_cnt;
    uint8_t                            ba_ring_type;
    hal_host_soc_regs                  soc_regs;
    hal_host_mac_regs                  mac_regs;
    hal_host_phy_regs                  phy_regs;
    hal_host_csi_regs                  csi_regs;
    hal_host_ftm_regs                  ftm_regs;
    hal_host_ring_ctl_stru             st_host_rx_normal_free_ring;
    hal_host_rx_alloc_list_stru        host_rx_normal_alloc_list;
    hal_host_ring_ctl_stru             st_host_rx_small_free_ring;
    hal_host_rx_alloc_list_stru        host_rx_small_alloc_list;
#ifdef _PRE_WLAN_FEATURE_SNIFFER
    hal_host_ring_ctl_stru             host_rx_ppdu_free_ring;
    hal_host_rx_ppdu_dscr_list_head_stru host_rx_ppdu_alloc_list;
#endif
    hal_host_ring_ctl_stru             st_host_rx_complete_ring;
    hal_host_ring_ctl_stru             host_ba_info_ring;
    hal_host_ring_ctl_stru             device_ba_info_ring;
#ifdef _PRE_WLAN_FEATURE_VSP
    oal_netbuf_head_stru               vsp_netbuf_recycle_list; /* vsp回收netbuf队列 */
#endif
    uint64_t                          dscr_prev; /* 处理的上一个rx comp ring中的地址， 用于检查是否duplicate */

    hal_rx_buf_statics                 rx_statics;
    hal_rx_mpdu_que                    st_rx_mpdu;
    hal_vap_status_info                hal_vap_sts_info[HAL_MAX_VAP_NUM];
    mac_al_rx_stru                     st_alrx;

    dpe_hal_dev_atomic_var            *atomic_val;
} hal_host_device_stru;

typedef struct {
    uint8_t     vap_index;
    uint8_t     csi_data[CSI_INFO_LEN];
    uint16_t    rpt_info_len;
} hmac_csi_info_stru;
#pragma pack(push, 1)
#define FTM_MAX_POWER_NUM 32 /* HWMAC上报32个word用于FTM功率相关峰计算 */

typedef union {
    uint32_t reg_value;
    struct {
        uint32_t bit_lsb : 16;
        uint32_t bit_msb : 16;
    } reg;
} hal_ftm_correlation_peak_union;
typedef struct {
    uint8_t   device_id;
    uint8_t   ftm_init_resp_flag : 1;
    uint8_t   ftm_intp_time : 5;
    uint8_t   ftm_frame_type;
    uint8_t   ftm_vap_index;
    uint8_t   ftm_dialog_token;
    uint8_t   ftm_ra[WLAN_MAC_ADDR_LEN];
    uint8_t   ftm_ta[WLAN_MAC_ADDR_LEN];
    uint8_t   ftm_snr_ant[HAL_HOST_MAX_RF_NUM];
    int8_t    ftm_rssi_ant[HAL_HOST_MAX_RF_NUM];
    uint16_t  ftm_info_len;
    uint32_t  ftm_phase_incr_ant;
    uint64_t  ftm_rx_time;
    uint64_t  ftm_tx_time;
    uint64_t  ftm_timestamp;
    hal_ftm_correlation_peak_union ftm_power[FTM_MAX_POWER_NUM];
} hal_ftm_info_stru;
#pragma pack(pop)

typedef struct tag_hal_hal_chip_stru {
    uint8_t                   chip_id;            /* 芯片ID */
    uint8_t                   device_nums;        /* chip下device的数目 */
    uint8_t                   device_id_bitmap;   /* 用于标识device分配情况 (需要提供内部的get和clear，add使用) */
    uint8_t                   resv;
    uint32_t                  chip_version;       /* 芯片版本 */
    hal_host_device_stru      hal_device[WLAN_DEVICE_MAX_NUM_PER_CHIP];
    hal_user_status_info      user_sts_info[HAL_MAX_LUT]; /* lut -- user映射关系 */
    hal_rx_ring_mac_ptr_info *rx_ring_mac_ptr_info;
    hal_rx_ring_mac_ptr_addr  rx_ring_mac_ptr_addr;
} hal_host_chip_stru;

static inline uint8_t mac_chip_get_hal_dev_num(void)
{
    return g_wlan_spec_cfg->hal_dev_num;
}
static inline uint8_t mac_chip_is_support_slave(void)
{
    return g_wlan_spec_cfg->hal_dev_num > HAL_DEVICE_ID_SLAVE;
}

/* 功能描述: 获取最大hal_vap个数 */
static inline uint8_t mac_chip_get_hal_max_vap_num(void)
{
    return g_wlan_spec_cfg->hal_max_vap_num;
}
/* 功能描述: 获取最大vap个数, 即配置vap个数+WIFI业务vap个数 */
static inline uint8_t mac_chip_get_vap_support_max_num_limit(void)
{
    return g_wlan_spec_cfg->vap_support_max_num_limit;
}
void hal_host_rx_mpdu_que_pop(hal_host_device_stru *hal_device, oal_netbuf_head_stru *netbuf_head);
void hal_host_rx_mpdu_que_pop_designate_list(hal_host_device_stru *hal_device,
    oal_netbuf_head_stru *netbuf_head, uint32_t number);
uint8_t hal_rx_mpdu_que_is_full(hal_rx_mpdu_que *rx_mpdu);
hal_host_chip_stru *hal_get_host_chip(void);
hal_host_device_stru *hal_get_host_device(uint8_t dev_id);
hal_host_chip_stru *hal_get_host_chip(void);
hal_host_device_stru *hal_comm_rx_get_host_device(void);
hal_host_device_stru *hal_pcie_down_get_hal_dev(uint8_t dev_idx);
void hal_host_board_init(void);
void hal_device_reset_rx_res(void);
void hal_set_alrx_status(uint8_t hal_dev_id, uint8_t status);
void hal_set_altx_status(uint8_t hal_dev_id, uint8_t status);
uint8_t hal_device_is_ddr_rx(void);
uint8_t hal_master_is_in_ddr_rx(void);
uint8_t hal_slave_is_in_ddr_rx(void);
uint8_t hal_is_host_forbid_sleep(void);
uint8_t hal_device_is_al_trx(void);
void wlan_hal_ops_init(void);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
