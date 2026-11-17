#ifndef __VDE_SMMU_PRE_CFG_C_UNION_DEFINE_H__
#define __VDE_SMMU_PRE_CFG_C_UNION_DEFINE_H__ 
typedef union {
    struct {
        unsigned int smmu_arsid : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSID;
typedef union {
    struct {
        unsigned int smmu_arssid : 12 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSSID;
typedef union {
    struct {
        unsigned int smmu_arssidv : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSSIDV;
typedef union {
    struct {
        unsigned int smmu_arsid_bp : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSID_BP;
typedef union {
    struct {
        unsigned int smmu_awsid : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSID;
typedef union {
    struct {
        unsigned int smmu_awssid : 12 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSSID;
typedef union {
    struct {
        unsigned int smmu_awssidv : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSSIDV;
typedef union {
    struct {
        unsigned int smmu_awsid_bp : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSID_BP;
typedef union {
    struct {
        unsigned int smmu_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_EN;
typedef union {
    struct {
        unsigned int vdec_softrst_req : 1 ;
        unsigned int reserved_0 : 7 ;
        unsigned int vdec_softrst_force_req : 1 ;
        unsigned int reserved_1 : 7 ;
        unsigned int vdec_softrst_ok : 1 ;
        unsigned int reserved_2 : 15 ;
    } bits;
    unsigned int u32;
} U_SOFTRST_CFG;
typedef union {
    struct {
        unsigned int pxphw_pdm_pwrd_req : 1 ;
        unsigned int pxphw_pds_pwrd_req : 1 ;
        unsigned int reserved_0 : 6 ;
        unsigned int pxphw_pdm_pwrd_ack : 1 ;
        unsigned int pxphw_pds_pwrd_ack : 1 ;
        unsigned int reserved_1 : 22 ;
    } bits;
    unsigned int u32;
} U_PXPHW_SOFTRST_CFG;
typedef union {
    struct {
        unsigned int pxphw_pdms_state : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_PXPHW_SOFTRST_STA0;
typedef union {
    struct {
        unsigned int ddr_addr_intercept_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_INTERCEPT_EN;
typedef union {
    struct {
        unsigned int ddr_waddr_over_state_clr : 1 ;
        unsigned int ddr_raddr_over_state_clr : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_OVER_STATE_CLR;
typedef union {
    struct {
        unsigned int ddr_waddr_over_state : 1 ;
        unsigned int ddr_raddr_over_state : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_OVER_STATE;
typedef union {
    struct {
        unsigned int sc_esp_hint_l0 : 4 ;
        unsigned int sc_esp_hint_l1 : 4 ;
        unsigned int sc_esp_hint_l2 : 4 ;
        unsigned int sc_esp_hint_en : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VDEC_REFLD_ESP_HINT;
typedef union {
    struct {
        unsigned int awqos : 4 ;
        unsigned int arqos : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_QOS;
typedef union {
    struct {
        unsigned int awqos_sc : 4 ;
        unsigned int arqos_sc : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_QOS_SC;
typedef union {
    struct {
        unsigned int awpush : 4 ;
        unsigned int arpush : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_PUSH;
typedef union {
    struct {
        unsigned int awpush_sc : 4 ;
        unsigned int arpush_sc : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_PUSH_SC;
typedef union {
    struct {
        unsigned int waddr_over_chid : 6 ;
        unsigned int raddr_over_chid : 6 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_OVERID;
typedef union {
    struct {
        unsigned int dbg_awid : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_AWID;
typedef union {
    struct {
        unsigned int dbg_awaddr_1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_AWADDR_1;
typedef union {
    struct {
        unsigned int dbg_awlen : 8 ;
        unsigned int dbg_awsize : 3 ;
        unsigned int reserved_0 : 1 ;
        unsigned int dbg_awburst : 2 ;
        unsigned int reserved_1 : 2 ;
        unsigned int dbg_awlock : 2 ;
        unsigned int reserved_2 : 2 ;
        unsigned int dbg_awcache : 4 ;
        unsigned int dbg_awprot : 3 ;
        unsigned int reserved_3 : 1 ;
        unsigned int dbg_awvalid : 1 ;
        unsigned int reserved_4 : 3 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_AWLEN;
typedef union {
    struct {
        unsigned int dbg_arid : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_ARID;
typedef union {
    struct {
        unsigned int dbg_araddr_1 : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_ARADDR_1;
typedef union {
    struct {
        unsigned int dbg_arlen : 8 ;
        unsigned int dbg_arsize : 3 ;
        unsigned int reserved_0 : 1 ;
        unsigned int dbg_arburst : 2 ;
        unsigned int reserved_1 : 2 ;
        unsigned int dbg_arlock : 2 ;
        unsigned int reserved_2 : 2 ;
        unsigned int dbg_arcache : 4 ;
        unsigned int dbg_arprot : 3 ;
        unsigned int reserved_3 : 1 ;
        unsigned int dbg_arvalid : 1 ;
        unsigned int reserved_4 : 3 ;
    } bits;
    unsigned int u32;
} U_VDEC_HIAXI_DBG_ARLEN;
typedef union {
    struct {
        unsigned int va_str : 24 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_VA_STR;
typedef union {
    struct {
        unsigned int va_end : 24 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VDEC_DDR_ADDR_VA_END;
typedef union {
    struct {
        unsigned int cache_as_ful_nsafe : 1 ;
        unsigned int sc_gid_hint_nsafe : 6 ;
        unsigned int sc_new_hint_nsafe : 4 ;
        unsigned int cache_nsafe : 4 ;
        unsigned int domain_nsafe : 2 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VDEC_CACHE_AS_FUL;
typedef union {
    struct {
        unsigned int smmu_secsid : 1 ;
        unsigned int smmu_secsid_mcu : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_SECSID;
typedef union {
    struct {
        unsigned int smmu_arsid_safe : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSID_SAFE;
typedef union {
    struct {
        unsigned int smmu_arssid_safe : 12 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSSID_SAFE;
typedef union {
    struct {
        unsigned int smmu_arssidv_safe : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSSIDV_SAFE;
typedef union {
    struct {
        unsigned int smmu_arsid_safe_bp : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_ARSID_SAFE_BP;
typedef union {
    struct {
        unsigned int smmu_awsid_safe : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSID_SAFE;
typedef union {
    struct {
        unsigned int smmu_awssid_safe : 12 ;
        unsigned int reserved_0 : 20 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSSID_SAFE;
typedef union {
    struct {
        unsigned int smmu_awssidv_safe : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSSIDV_SAFE;
typedef union {
    struct {
        unsigned int smmu_awsid_safe_bp : 6 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_AWSID_SAFE_BP;
typedef union {
    struct {
        unsigned int smmu_en_safe : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VDEC_SMMU_EN_SAFE;
typedef union {
    struct {
        unsigned int sc_esp_hint_l0_safe : 4 ;
        unsigned int sc_esp_hint_l1_safe : 4 ;
        unsigned int sc_esp_hint_l2_safe : 4 ;
        unsigned int sc_esp_hint_en_safe : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VDEC_ESP_HINT_SAFE;
typedef union {
    struct {
        unsigned int cache_as_ful_safe : 1 ;
        unsigned int sc_gid_hint_safe : 6 ;
        unsigned int sc_new_hint_safe : 4 ;
        unsigned int cache_safe : 4 ;
        unsigned int domain_safe : 2 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VDEC_CACHE_AS_FUL_SAFE;
typedef struct {
    volatile U_VDEC_SMMU_ARSID VDEC_SMMU_ARSID ;
    volatile U_VDEC_SMMU_ARSSID VDEC_SMMU_ARSSID ;
    volatile U_VDEC_SMMU_ARSSIDV VDEC_SMMU_ARSSIDV ;
    volatile U_VDEC_SMMU_ARSID_BP VDEC_SMMU_ARSID_BP ;
    volatile U_VDEC_SMMU_AWSID VDEC_SMMU_AWSID ;
    volatile U_VDEC_SMMU_AWSSID VDEC_SMMU_AWSSID ;
    volatile U_VDEC_SMMU_AWSSIDV VDEC_SMMU_AWSSIDV ;
    volatile U_VDEC_SMMU_AWSID_BP VDEC_SMMU_AWSID_BP ;
    volatile U_VDEC_SMMU_EN VDEC_SMMU_EN ;
    volatile unsigned int reserved_0[3] ;
    volatile U_SOFTRST_CFG SOFTRST_CFG ;
    volatile unsigned int SOFTRST_STA0 ;
    volatile unsigned int SOFTRST_STA1 ;
    volatile unsigned int reserved_1 ;
    volatile U_PXPHW_SOFTRST_CFG PXPHW_SOFTRST_CFG ;
    volatile U_PXPHW_SOFTRST_STA0 PXPHW_SOFTRST_STA0 ;
    volatile unsigned int reserved_2[2] ;
    volatile U_VDEC_DDR_ADDR_INTERCEPT_EN VDEC_DDR_ADDR_INTERCEPT_EN ;
    volatile U_VDEC_DDR_ADDR_OVER_STATE_CLR VDEC_DDR_ADDR_OVER_STATE_CLR[32] ;
    volatile U_VDEC_DDR_ADDR_OVER_STATE VDEC_DDR_ADDR_OVER_STATE[32] ;
    volatile unsigned int reserved_3 ;
    volatile unsigned int VDEC_DDR_RADDR_OVER_ADDR[32] ;
    volatile unsigned int VDEC_DDR_WADDR_OVER_ADDR[32] ;
    volatile U_VDEC_REFLD_ESP_HINT VDEC_REFLD_ESP_HINT[32] ;
    volatile unsigned int reserved_4[5] ;
    volatile U_VDEC_DDR_QOS VDEC_DDR_QOS[32] ;
    volatile U_VDEC_DDR_QOS_SC VDEC_DDR_QOS_SC[32] ;
    volatile U_VDEC_DDR_PUSH VDEC_DDR_PUSH[32] ;
    volatile U_VDEC_DDR_PUSH_SC VDEC_DDR_PUSH_SC[32] ;
    volatile unsigned int reserved_5[28] ;
    volatile U_VDEC_DDR_ADDR_OVERID VDEC_DDR_ADDR_OVERID[32] ;
    volatile unsigned int reserved_6[2] ;
    volatile U_VDEC_HIAXI_DBG_AWID VDEC_HIAXI_DBG_AWID[32] ;
    volatile unsigned int VDEC_HIAXI_DBG_AWADDR_0[32] ;
    volatile U_VDEC_HIAXI_DBG_AWADDR_1 VDEC_HIAXI_DBG_AWADDR_1[32] ;
    volatile U_VDEC_HIAXI_DBG_AWLEN VDEC_HIAXI_DBG_AWLEN[32] ;
    volatile unsigned int reserved_7 ;
    volatile U_VDEC_HIAXI_DBG_ARID VDEC_HIAXI_DBG_ARID[32] ;
    volatile unsigned int VDEC_HIAXI_DBG_ARADDR_0[32] ;
    volatile U_VDEC_HIAXI_DBG_ARADDR_1 VDEC_HIAXI_DBG_ARADDR_1[32] ;
    volatile U_VDEC_HIAXI_DBG_ARLEN VDEC_HIAXI_DBG_ARLEN[32] ;
    volatile unsigned int reserved_8[52] ;
    volatile U_VDEC_DDR_ADDR_VA_STR VDEC_DDR_ADDR_VA_STR[32] ;
    volatile unsigned int reserved_9[75] ;
    volatile U_VDEC_DDR_ADDR_VA_END VDEC_DDR_ADDR_VA_END[32] ;
    volatile unsigned int reserved_10[75] ;
    volatile U_VDEC_CACHE_AS_FUL VDEC_CACHE_AS_FUL[32] ;
    volatile unsigned int reserved_11[203] ;
    volatile U_VDEC_SMMU_SECSID VDEC_SMMU_SECSID ;
    volatile U_VDEC_SMMU_ARSID_SAFE VDEC_SMMU_ARSID_SAFE ;
    volatile U_VDEC_SMMU_ARSSID_SAFE VDEC_SMMU_ARSSID_SAFE ;
    volatile U_VDEC_SMMU_ARSSIDV_SAFE VDEC_SMMU_ARSSIDV_SAFE ;
    volatile U_VDEC_SMMU_ARSID_SAFE_BP VDEC_SMMU_ARSID_SAFE_BP ;
    volatile U_VDEC_SMMU_AWSID_SAFE VDEC_SMMU_AWSID_SAFE ;
    volatile U_VDEC_SMMU_AWSSID_SAFE VDEC_SMMU_AWSSID_SAFE ;
    volatile U_VDEC_SMMU_AWSSIDV_SAFE VDEC_SMMU_AWSSIDV_SAFE ;
    volatile U_VDEC_SMMU_AWSID_SAFE_BP VDEC_SMMU_AWSID_SAFE_BP ;
    volatile U_VDEC_SMMU_EN_SAFE VDEC_SMMU_EN_SAFE ;
    volatile unsigned int reserved_12[6] ;
    volatile U_VDEC_ESP_HINT_SAFE VDEC_ESP_HINT_SAFE[32] ;
    volatile unsigned int reserved_13[47] ;
    volatile U_VDEC_CACHE_AS_FUL_SAFE VDEC_CACHE_AS_FUL_SAFE[32] ;
} S_VDE_SMMU_PRE_CFG_REGS_TYPE;
typedef union {
    unsigned int u32;
    volatile U_VDEC_SMMU_ARSID VDEC_SMMU_ARSID;
    volatile U_VDEC_SMMU_ARSSID VDEC_SMMU_ARSSID;
    volatile U_VDEC_SMMU_ARSSIDV VDEC_SMMU_ARSSIDV;
    volatile U_VDEC_SMMU_ARSID_BP VDEC_SMMU_ARSID_BP;
    volatile U_VDEC_SMMU_AWSID VDEC_SMMU_AWSID;
    volatile U_VDEC_SMMU_AWSSID VDEC_SMMU_AWSSID;
    volatile U_VDEC_SMMU_AWSSIDV VDEC_SMMU_AWSSIDV;
    volatile U_VDEC_SMMU_AWSID_BP VDEC_SMMU_AWSID_BP;
    volatile U_VDEC_SMMU_EN VDEC_SMMU_EN;
    volatile U_SOFTRST_CFG SOFTRST_CFG;
    volatile U_PXPHW_SOFTRST_CFG PXPHW_SOFTRST_CFG;
    volatile U_PXPHW_SOFTRST_STA0 PXPHW_SOFTRST_STA0;
    volatile U_VDEC_DDR_ADDR_INTERCEPT_EN VDEC_DDR_ADDR_INTERCEPT_EN;
    volatile U_VDEC_DDR_ADDR_OVER_STATE_CLR VDEC_DDR_ADDR_OVER_STATE_CLR;
    volatile U_VDEC_DDR_ADDR_OVER_STATE VDEC_DDR_ADDR_OVER_STATE;
    volatile U_VDEC_REFLD_ESP_HINT VDEC_REFLD_ESP_HINT;
    volatile U_VDEC_DDR_QOS VDEC_DDR_QOS;
    volatile U_VDEC_DDR_QOS_SC VDEC_DDR_QOS_SC;
    volatile U_VDEC_DDR_PUSH VDEC_DDR_PUSH;
    volatile U_VDEC_DDR_PUSH_SC VDEC_DDR_PUSH_SC;
    volatile U_VDEC_DDR_ADDR_OVERID VDEC_DDR_ADDR_OVERID;
    volatile U_VDEC_HIAXI_DBG_AWID VDEC_HIAXI_DBG_AWID;
    volatile U_VDEC_HIAXI_DBG_AWADDR_1 VDEC_HIAXI_DBG_AWADDR_1;
    volatile U_VDEC_HIAXI_DBG_AWLEN VDEC_HIAXI_DBG_AWLEN;
    volatile U_VDEC_HIAXI_DBG_ARID VDEC_HIAXI_DBG_ARID;
    volatile U_VDEC_HIAXI_DBG_ARADDR_1 VDEC_HIAXI_DBG_ARADDR_1;
    volatile U_VDEC_HIAXI_DBG_ARLEN VDEC_HIAXI_DBG_ARLEN;
    volatile U_VDEC_DDR_ADDR_VA_STR VDEC_DDR_ADDR_VA_STR;
    volatile U_VDEC_DDR_ADDR_VA_END VDEC_DDR_ADDR_VA_END;
    volatile U_VDEC_CACHE_AS_FUL VDEC_CACHE_AS_FUL;
    volatile U_VDEC_SMMU_SECSID VDEC_SMMU_SECSID;
    volatile U_VDEC_SMMU_ARSID_SAFE VDEC_SMMU_ARSID_SAFE;
    volatile U_VDEC_SMMU_ARSSID_SAFE VDEC_SMMU_ARSSID_SAFE;
    volatile U_VDEC_SMMU_ARSSIDV_SAFE VDEC_SMMU_ARSSIDV_SAFE;
    volatile U_VDEC_SMMU_ARSID_SAFE_BP VDEC_SMMU_ARSID_SAFE_BP;
    volatile U_VDEC_SMMU_AWSID_SAFE VDEC_SMMU_AWSID_SAFE;
    volatile U_VDEC_SMMU_AWSSID_SAFE VDEC_SMMU_AWSSID_SAFE;
    volatile U_VDEC_SMMU_AWSSIDV_SAFE VDEC_SMMU_AWSSIDV_SAFE;
    volatile U_VDEC_SMMU_AWSID_SAFE_BP VDEC_SMMU_AWSID_SAFE_BP;
    volatile U_VDEC_SMMU_EN_SAFE VDEC_SMMU_EN_SAFE;
    volatile U_VDEC_ESP_HINT_SAFE VDEC_ESP_HINT_SAFE;
    volatile U_VDEC_CACHE_AS_FUL_SAFE VDEC_CACHE_AS_FUL_SAFE;
} U_VDE_SMMU_PRE_CFG_REGS_TYPE;
#endif
