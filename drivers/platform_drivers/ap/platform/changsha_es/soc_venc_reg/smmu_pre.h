#ifndef __SMMU_PRE_H__
#define __SMMU_PRE_H__ 
typedef union
{
    struct
    {
        unsigned int dpm_freq_sel : 3 ;
        unsigned int smmu_clkgate : 1 ;
        unsigned int smmu_softrst : 1 ;
        unsigned int reserved_0 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_DPM_FREQ_SEL;
typedef union
{
    struct
    {
        unsigned int ddr_addr_intercept_en : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_INTERCEPT_EN;
typedef union
{
    struct
    {
        unsigned int ddr_waddr_over_state_clr : 1 ;
        unsigned int ddr_raddr_over_state_clr : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_OVER_STATE_CLR;
typedef union
{
    struct
    {
        unsigned int ddr_waddr_over_state : 1 ;
        unsigned int ddr_raddr_over_state : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_OVER_STATE;
typedef union
{
    struct
    {
        unsigned int sc_esp_hint_l0 : 4 ;
        unsigned int sc_esp_hint_l1 : 4 ;
        unsigned int sc_esp_hint_l2 : 4 ;
        unsigned int sc_esp_hint_en : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_REFLD_ESP_HINT;
typedef union
{
    struct
    {
        unsigned int waddr_over_id : 7 ;
        unsigned int raddr_over_id : 6 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_OVERID;
typedef union
{
    struct
    {
        unsigned int awqos : 4 ;
        unsigned int arqos : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_QOS;
typedef union
{
    struct
    {
        unsigned int ckg_en_2to1_matrix : 1 ;
        unsigned int mst_priority_m : 2 ;
        unsigned int dlock_and_dbg_clr : 1 ;
        unsigned int ckg_en_64to128 : 1 ;
        unsigned int reserved_0 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_CTRL;
typedef union
{
    struct
    {
        unsigned int dlock_slv : 2 ;
        unsigned int dlock_mst : 4 ;
        unsigned int reserved_0 : 26 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_DLOCK;
typedef union
{
    struct
    {
        unsigned int hiaxi_2to1_idle : 1 ;
        unsigned int hiaxi_64to128_idle : 1 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_IDLE;
typedef union
{
    struct
    {
        unsigned int dbg_awid : 9 ;
        unsigned int reserved_0 : 23 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWID;
typedef union
{
    struct
    {
        unsigned int dbg_awaddr_0 : 31 ;
        unsigned int reserved_0 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWADDR_0;
typedef union
{
    struct
    {
        unsigned int dbg_awaddr_1 : 5 ;
        unsigned int reserved_0 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWADDR_1;
typedef union
{
    struct
    {
        unsigned int dbg_awlen : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWLEN;
typedef union
{
    struct
    {
        unsigned int dbg_awsize : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWSIZE;
typedef union
{
    struct
    {
        unsigned int dbg_awburst : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWBURST;
typedef union
{
    struct
    {
        unsigned int dbg_awlock : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWLOCK;
typedef union
{
    struct
    {
        unsigned int dbg_awcache : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWCACHE;
typedef union
{
    struct
    {
        unsigned int dbg_awprot : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWPROT;
typedef union
{
    struct
    {
        unsigned int dbg_awvalid : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_AWVALID;
typedef union
{
    struct
    {
        unsigned int dbg_arid : 9 ;
        unsigned int reserved_0 : 23 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARID;
typedef union
{
    struct
    {
        unsigned int dbg_araddr_0 : 31 ;
        unsigned int reserved_0 : 1 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARADDR_0;
typedef union
{
    struct
    {
        unsigned int dbg_araddr_1 : 5 ;
        unsigned int reserved_0 : 27 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARADDR_1;
typedef union
{
    struct
    {
        unsigned int dbg_arlen : 8 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARLEN;
typedef union
{
    struct
    {
        unsigned int dbg_arsize : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARSIZE;
typedef union
{
    struct
    {
        unsigned int dbg_arburst : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARBURST;
typedef union
{
    struct
    {
        unsigned int dbg_arlock : 2 ;
        unsigned int reserved_0 : 30 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARLOCK;
typedef union
{
    struct
    {
        unsigned int dbg_arcache : 4 ;
        unsigned int reserved_0 : 28 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARCACHE;
typedef union
{
    struct
    {
        unsigned int dbg_arprot : 3 ;
        unsigned int reserved_0 : 29 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARPROT;
typedef union
{
    struct
    {
        unsigned int dbg_arvalid : 1 ;
        unsigned int reserved_0 : 31 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ARVALID;
typedef union
{
    struct
    {
        unsigned int dbg_ar_dcdrerr_secerr_slverr_viserr_s0 : 4 ;
        unsigned int dbg_aw_dcdrerr_secerr_slverr_viserr_s0 : 4 ;
        unsigned int reserved_0 : 24 ;
    } bits;
    unsigned int u32;
} U_VEDU_HIAXI_DBG_ERR;
typedef union
{
    struct
    {
        unsigned int va_str : 24 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_VA_STR;
typedef union
{
    struct
    {
        unsigned int va_end : 24 ;
        unsigned int reserved_0 : 8 ;
    } bits;
    unsigned int u32;
} U_VEDU_DDR_ADDR_VA_END;
typedef union
{
    struct
    {
        unsigned int cache_as_ful : 1 ;
        unsigned int sc_gid_hint : 6 ;
        unsigned int sc_new_hint : 4 ;
        unsigned int cache : 4 ;
        unsigned int domain : 2 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_CACHE_AS_FUL;
typedef union
{
    struct
    {
        unsigned int cache_as_ful_safe : 1 ;
        unsigned int sc_gid_hint_safe : 6 ;
        unsigned int sc_new_hint_safe : 4 ;
        unsigned int cache_safe : 4 ;
        unsigned int domain_safe : 2 ;
        unsigned int reserved_0 : 15 ;
    } bits;
    unsigned int u32;
} U_VEDU_CACHE_AS_FUL_SAFE;
typedef union
{
    struct
    {
        unsigned int sc_esp_hint_l0_safe : 4 ;
        unsigned int sc_esp_hint_l1_safe : 4 ;
        unsigned int sc_esp_hint_l2_safe : 4 ;
        unsigned int sc_esp_hint_en_safe : 1 ;
        unsigned int reserved_0 : 19 ;
    } bits;
    unsigned int u32;
} U_VEDU_REFLD_ESP_HINT_SAFE;
typedef struct
{
    volatile U_VEDU_DPM_FREQ_SEL VEDU_DPM_FREQ_SEL ;
    volatile unsigned int reserved_0[3] ;
    volatile U_VEDU_DDR_ADDR_INTERCEPT_EN VEDU_DDR_ADDR_INTERCEPT_EN ;
    volatile U_VEDU_DDR_ADDR_OVER_STATE_CLR VEDU_DDR_ADDR_OVER_STATE_CLR[32] ;
    volatile U_VEDU_DDR_ADDR_OVER_STATE VEDU_DDR_ADDR_OVER_STATE[32] ;
    volatile unsigned int reserved_1 ;
    volatile unsigned int VEDU_DDR_RADDR_OVER_ADDR[32] ;
    volatile unsigned int VEDU_DDR_WADDR_OVER_ADDR[32] ;
    volatile U_VEDU_REFLD_ESP_HINT VEDU_REFLD_ESP_HINT[32] ;
    volatile unsigned int reserved_2[245] ;
    volatile U_VEDU_DDR_ADDR_OVERID VEDU_DDR_ADDR_OVERID[32] ;
    volatile U_VEDU_DDR_QOS VEDU_DDR_QOS[32] ;
    volatile unsigned int reserved_3[62] ;
    volatile U_VEDU_HIAXI_DBG_CTRL VEDU_HIAXI_DBG_CTRL[32] ;
    volatile U_VEDU_HIAXI_DBG_DLOCK VEDU_HIAXI_DBG_DLOCK[32] ;
    volatile U_VEDU_HIAXI_IDLE VEDU_HIAXI_IDLE[32] ;
    volatile U_VEDU_HIAXI_DBG_AWID VEDU_HIAXI_DBG_AWID[32] ;
    volatile U_VEDU_HIAXI_DBG_AWADDR_0 VEDU_HIAXI_DBG_AWADDR_0[32] ;
    volatile U_VEDU_HIAXI_DBG_AWADDR_1 VEDU_HIAXI_DBG_AWADDR_1[32] ;
    volatile U_VEDU_HIAXI_DBG_AWLEN VEDU_HIAXI_DBG_AWLEN[32] ;
    volatile U_VEDU_HIAXI_DBG_AWSIZE VEDU_HIAXI_DBG_AWSIZE[32] ;
    volatile U_VEDU_HIAXI_DBG_AWBURST VEDU_HIAXI_DBG_AWBURST[32] ;
    volatile U_VEDU_HIAXI_DBG_AWLOCK VEDU_HIAXI_DBG_AWLOCK[32] ;
    volatile U_VEDU_HIAXI_DBG_AWCACHE VEDU_HIAXI_DBG_AWCACHE[32] ;
    volatile U_VEDU_HIAXI_DBG_AWPROT VEDU_HIAXI_DBG_AWPROT[32] ;
    volatile U_VEDU_HIAXI_DBG_AWVALID VEDU_HIAXI_DBG_AWVALID[32] ;
    volatile U_VEDU_HIAXI_DBG_ARID VEDU_HIAXI_DBG_ARID[32] ;
    volatile U_VEDU_HIAXI_DBG_ARADDR_0 VEDU_HIAXI_DBG_ARADDR_0[32] ;
    volatile U_VEDU_HIAXI_DBG_ARADDR_1 VEDU_HIAXI_DBG_ARADDR_1[32] ;
    volatile U_VEDU_HIAXI_DBG_ARLEN VEDU_HIAXI_DBG_ARLEN[32] ;
    volatile U_VEDU_HIAXI_DBG_ARSIZE VEDU_HIAXI_DBG_ARSIZE[32] ;
    volatile U_VEDU_HIAXI_DBG_ARBURST VEDU_HIAXI_DBG_ARBURST[32] ;
    volatile U_VEDU_HIAXI_DBG_ARLOCK VEDU_HIAXI_DBG_ARLOCK[32] ;
    volatile U_VEDU_HIAXI_DBG_ARCACHE VEDU_HIAXI_DBG_ARCACHE[32] ;
    volatile U_VEDU_HIAXI_DBG_ARPROT VEDU_HIAXI_DBG_ARPROT[32] ;
    volatile U_VEDU_HIAXI_DBG_ARVALID VEDU_HIAXI_DBG_ARVALID[32] ;
    volatile U_VEDU_HIAXI_DBG_ERR VEDU_HIAXI_DBG_ERR[32] ;
    volatile unsigned int reserved_4[40] ;
    volatile U_VEDU_DDR_ADDR_VA_STR VEDU_DDR_ADDR_VA_STR[32] ;
    volatile unsigned int reserved_5[33] ;
    volatile U_VEDU_DDR_ADDR_VA_END VEDU_DDR_ADDR_VA_END[32] ;
    volatile unsigned int reserved_6[33] ;
    volatile U_VEDU_CACHE_AS_FUL VEDU_CACHE_AS_FUL[32] ;
    volatile unsigned int reserved_7[33] ;
    volatile U_VEDU_CACHE_AS_FUL_SAFE VEDU_CACHE_AS_FUL_SAFE[32] ;
    volatile unsigned int reserved_8[101] ;
    volatile U_VEDU_REFLD_ESP_HINT_SAFE VEDU_REFLD_ESP_HINT_SAFE[32] ;
} S_SMMU_PRE_REGS_TYPE;
#endif
