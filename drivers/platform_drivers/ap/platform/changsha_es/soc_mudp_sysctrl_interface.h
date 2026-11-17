#ifndef __SOC_MUDP_SYSCTRL_INTERFACE_H__
#define __SOC_MUDP_SYSCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_SYSCTRL_MUDP_MEM_CTRL_SPC_ADDR(base) (base)
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_ADDR(base) ((base) + 0x004UL)
#define SOC_MUDP_SYSCTRL_MUDP_TP_SEL_ADDR(base) ((base) + 0x008UL)
#define SOC_MUDP_SYSCTRL_PLL_LOCK_ADDR(base) ((base) + 0x00CUL)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_ADDR(base) ((base) + 0x0010UL)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_ADDR(base) ((base) + 0x0014UL)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00UL)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04UL)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08UL)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_LOCK_ADDR(base) ((base) + 0xD00UL)
#else
#define SOC_MUDP_SYSCTRL_MUDP_MEM_CTRL_SPC_ADDR(base) (base)
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_ADDR(base) ((base) + 0x004)
#define SOC_MUDP_SYSCTRL_MUDP_TP_SEL_ADDR(base) ((base) + 0x008)
#define SOC_MUDP_SYSCTRL_PLL_LOCK_ADDR(base) ((base) + 0x00C)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_ADDR(base) ((base) + 0x0010)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_ADDR(base) ((base) + 0x0014)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_ADDR(base) ((base) + 0xC00)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_ADDR(base) ((base) + 0xC04)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_ADDR(base) ((base) + 0xC08)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_LOCK_ADDR(base) ((base) + 0xD00)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mem_ctrl_spc : 26;
        unsigned int reserved : 6;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_MEM_CTRL_SPC_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_MEM_CTRL_SPC_mem_ctrl_spc_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_MEM_CTRL_SPC_mem_ctrl_spc_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int idi_async_overflow_en : 1;
        unsigned int idi_async_overflow : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_idi_async_overflow_en_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_idi_async_overflow_en_END (0)
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_idi_async_overflow_START (1)
#define SOC_MUDP_SYSCTRL_MUDP_IDI_ASYNC_OVERLFLOW_EN_idi_async_overflow_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tp_mudp_sel : 3;
        unsigned int reserved : 29;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_TP_SEL_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_TP_SEL_tp_mudp_sel_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_TP_SEL_tp_mudp_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mudp_phy_pll_lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_SYSCTRL_PLL_LOCK_UNION;
#endif
#define SOC_MUDP_SYSCTRL_PLL_LOCK_mudp_phy_pll_lock_START (0)
#define SOC_MUDP_SYSCTRL_PLL_LOCK_mudp_phy_pll_lock_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mudp_phy_lvr_enb_dvddh8 : 1;
        unsigned int mudp_phy_iso_enb_dvddh8 : 1;
        unsigned int mudp_phy_rx0_sqdet_pwrdnb : 1;
        unsigned int mudp_phy_rx1_sqdet_pwrdnb : 1;
        unsigned int mudp_phy_rx2_sqdet_pwrdnb : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_lvr_enb_dvddh8_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_lvr_enb_dvddh8_END (0)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_iso_enb_dvddh8_START (1)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_iso_enb_dvddh8_END (1)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx0_sqdet_pwrdnb_START (2)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx0_sqdet_pwrdnb_END (2)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx1_sqdet_pwrdnb_START (3)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx1_sqdet_pwrdnb_END (3)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx2_sqdet_pwrdnb_START (4)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL0_mudp_phy_rx2_sqdet_pwrdnb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mudp_phy_rx0_stalldet_hys : 3;
        unsigned int reserved_0 : 1;
        unsigned int mudp_phy_rx1_stalldet_hys : 3;
        unsigned int reserved_1 : 1;
        unsigned int mudp_phy_rx2_stalldet_hys : 3;
        unsigned int reserved_2 : 1;
        unsigned int mudp_phy_rx0_sqdet_vref_sel : 3;
        unsigned int reserved_3 : 1;
        unsigned int mudp_phy_rx1_sqdet_vref_sel : 3;
        unsigned int reserved_4 : 1;
        unsigned int mudp_phy_rx2_sqdet_vref_sel : 3;
        unsigned int reserved_5 : 1;
        unsigned int mudp_phy_rx0_sqdet_polarity : 1;
        unsigned int mudp_phy_rx1_sqdet_polarity : 1;
        unsigned int mudp_phy_rx2_sqdet_polarity : 1;
        unsigned int reserved_6 : 5;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_stalldet_hys_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_stalldet_hys_END (2)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_stalldet_hys_START (4)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_stalldet_hys_END (6)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_stalldet_hys_START (8)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_stalldet_hys_END (10)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_sqdet_vref_sel_START (12)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_sqdet_vref_sel_END (14)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_sqdet_vref_sel_START (16)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_sqdet_vref_sel_END (18)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_sqdet_vref_sel_START (20)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_sqdet_vref_sel_END (22)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_sqdet_polarity_START (24)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx0_sqdet_polarity_END (24)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_sqdet_polarity_START (25)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx1_sqdet_polarity_END (25)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_sqdet_polarity_START (26)
#define SOC_MUDP_SYSCTRL_MUDP_PHY_CTRL1_mudp_phy_rx2_sqdet_polarity_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_mudp_phy_set : 1;
        unsigned int tz_secure_n_mudp_link_set : 1;
        unsigned int tz_secure_n_mudp_pix_rx_set : 1;
        unsigned int tz_secure_n_mudp_trace_set : 1;
        unsigned int tz_secure_n_mudp_sctrl_ns_set : 1;
        unsigned int tz_secure_n_mudp_sctrl_s_set : 1;
        unsigned int tz_secure_n_mudp_crg_ns_set : 1;
        unsigned int tz_secure_n_mdup_crg_s_set : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_phy_set_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_phy_set_END (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_link_set_START (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_link_set_END (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_pix_rx_set_START (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_pix_rx_set_END (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_trace_set_START (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_trace_set_END (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_sctrl_ns_set_START (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_sctrl_ns_set_END (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_sctrl_s_set_START (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_sctrl_s_set_END (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_crg_ns_set_START (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mudp_crg_ns_set_END (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mdup_crg_s_set_START (7)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_EN_tz_secure_n_mdup_crg_s_set_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_mudp_phy_clr : 1;
        unsigned int tz_secure_n_mudp_link_clr : 1;
        unsigned int tz_secure_n_mudp_pix_rx_clr : 1;
        unsigned int tz_secure_n_mudp_trace_clr : 1;
        unsigned int tz_secure_n_mudp_sctrl_ns_clr : 1;
        unsigned int tz_secure_n_mudp_sctrl_s_clr : 1;
        unsigned int tz_secure_n_mudp_crg_ns_clr : 1;
        unsigned int tz_secure_n_mdup_crg_s_clr : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_phy_clr_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_phy_clr_END (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_link_clr_START (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_link_clr_END (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_pix_rx_clr_START (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_pix_rx_clr_END (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_trace_clr_START (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_trace_clr_END (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_sctrl_ns_clr_START (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_sctrl_ns_clr_END (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_sctrl_s_clr_START (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_sctrl_s_clr_END (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_crg_ns_clr_START (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mudp_crg_ns_clr_END (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mdup_crg_s_clr_START (7)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_DIS_tz_secure_n_mdup_crg_s_clr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int tz_secure_n_mudp_phy : 1;
        unsigned int tz_secure_n_mudp_link : 1;
        unsigned int tz_secure_n_mudp_pix_rx : 1;
        unsigned int tz_secure_n_mudp_trace : 1;
        unsigned int tz_secure_n_mudp_sctrl_ns : 1;
        unsigned int tz_secure_n_mudp_sctrl_s : 1;
        unsigned int tz_secure_n_mudp_crg_ns : 1;
        unsigned int tz_secure_n_mdup_crg_s : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_phy_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_phy_END (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_link_START (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_link_END (1)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_pix_rx_START (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_pix_rx_END (2)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_trace_START (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_trace_END (3)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_sctrl_ns_START (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_sctrl_ns_END (4)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_sctrl_s_START (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_sctrl_s_END (5)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_crg_ns_START (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mudp_crg_ns_END (6)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mdup_crg_s_START (7)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_GRP0_LOCK_STA_tz_secure_n_mdup_crg_s_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int lock : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_MUDP_SYSCTRL_MUDP_TZPC_LOCK_UNION;
#endif
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_LOCK_lock_START (0)
#define SOC_MUDP_SYSCTRL_MUDP_TZPC_LOCK_lock_END (0)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
