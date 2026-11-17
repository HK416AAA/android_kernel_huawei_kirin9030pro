#ifndef __SOC_MUDP_CRG_INTERFACE_H__
#define __SOC_MUDP_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MUDP_CRG_PEREN0_ADDR(base) (base)
#define SOC_MUDP_CRG_PERDIS0_ADDR(base) ((base) + 0x004UL)
#define SOC_MUDP_CRG_PERCLKEN0_ADDR(base) ((base) + 0x008UL)
#define SOC_MUDP_CRG_PERSTAT0_ADDR(base) ((base) + 0x00CUL)
#define SOC_MUDP_CRG_PERRSTEN0_ADDR(base) ((base) + 0x010UL)
#define SOC_MUDP_CRG_PERRSTDIS0_ADDR(base) ((base) + 0x014UL)
#define SOC_MUDP_CRG_PERRSTSTAT0_ADDR(base) ((base) + 0x018UL)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x38UL)
#define SOC_MUDP_CRG_MUDP_STAT1_ADDR(base) ((base) + 0x48UL)
#else
#define SOC_MUDP_CRG_PEREN0_ADDR(base) (base)
#define SOC_MUDP_CRG_PERDIS0_ADDR(base) ((base) + 0x004)
#define SOC_MUDP_CRG_PERCLKEN0_ADDR(base) ((base) + 0x008)
#define SOC_MUDP_CRG_PERSTAT0_ADDR(base) ((base) + 0x00C)
#define SOC_MUDP_CRG_PERRSTEN0_ADDR(base) ((base) + 0x010)
#define SOC_MUDP_CRG_PERRSTDIS0_ADDR(base) ((base) + 0x014)
#define SOC_MUDP_CRG_PERRSTSTAT0_ADDR(base) ((base) + 0x018)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_ADDR(base) ((base) + 0x38)
#define SOC_MUDP_CRG_MUDP_STAT1_ADDR(base) ((base) + 0x48)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_mudp_apb_bridge : 1;
        unsigned int gt_pclk_mudp_pix_rx : 1;
        unsigned int gt_clk_mudp_pix_rx_sys : 1;
        unsigned int gt_pclk_mudp_link : 1;
        unsigned int gt_clk_mudp_link_sys : 1;
        unsigned int gt_clk_mudp_ref : 1;
        unsigned int gt_clk_mudp_axi2to1 : 1;
        unsigned int gt_pclk_mudp_trace : 1;
        unsigned int gt_pclk_mudp_sysctrl : 1;
        unsigned int gt_pclk_mudp_phy : 1;
        unsigned int gt_clk_mudp_phy_sys : 1;
        unsigned int gt_clk_mudp_idi_bridge : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 12;
    } reg;
} SOC_MUDP_CRG_PEREN0_UNION;
#endif
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_pix_rx_sys_START (2)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_pix_rx_sys_END (2)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_link_START (3)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_link_END (3)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_link_sys_START (4)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_link_sys_END (4)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_ref_START (5)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_ref_END (5)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_axi2to1_START (6)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_axi2to1_END (6)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_trace_START (7)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_trace_END (7)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_sysctrl_START (8)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_sysctrl_END (8)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_phy_START (9)
#define SOC_MUDP_CRG_PEREN0_gt_pclk_mudp_phy_END (9)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_phy_sys_START (10)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_phy_sys_END (10)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_idi_bridge_START (11)
#define SOC_MUDP_CRG_PEREN0_gt_clk_mudp_idi_bridge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_mudp_apb_bridge : 1;
        unsigned int gt_pclk_mudp_pix_rx : 1;
        unsigned int gt_clk_mudp_pix_rx_sys : 1;
        unsigned int gt_pclk_mudp_link : 1;
        unsigned int gt_clk_mudp_link_sys : 1;
        unsigned int gt_clk_mudp_ref : 1;
        unsigned int gt_clk_mudp_axi2to1 : 1;
        unsigned int gt_pclk_mudp_trace : 1;
        unsigned int gt_pclk_mudp_sysctrl : 1;
        unsigned int gt_pclk_mudp_phy : 1;
        unsigned int gt_clk_mudp_phy_sys : 1;
        unsigned int gt_clk_mudp_idi_bridge : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 12;
    } reg;
} SOC_MUDP_CRG_PERDIS0_UNION;
#endif
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_pix_rx_sys_START (2)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_pix_rx_sys_END (2)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_link_START (3)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_link_END (3)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_link_sys_START (4)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_link_sys_END (4)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_ref_START (5)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_ref_END (5)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_axi2to1_START (6)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_axi2to1_END (6)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_trace_START (7)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_trace_END (7)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_sysctrl_START (8)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_sysctrl_END (8)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERDIS0_gt_pclk_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_phy_sys_START (10)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_phy_sys_END (10)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_idi_bridge_START (11)
#define SOC_MUDP_CRG_PERDIS0_gt_clk_mudp_idi_bridge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int gt_pclk_mudp_apb_bridge : 1;
        unsigned int gt_pclk_mudp_pix_rx : 1;
        unsigned int gt_clk_mudp_pix_rx_sys : 1;
        unsigned int gt_pclk_mudp_link : 1;
        unsigned int gt_clk_mudp_link_sys : 1;
        unsigned int gt_clk_mudp_ref : 1;
        unsigned int gt_clk_mudp_axi2to1 : 1;
        unsigned int gt_pclk_mudp_trace : 1;
        unsigned int gt_pclk_mudp_sysctrl : 1;
        unsigned int gt_pclk_mudp_phy : 1;
        unsigned int gt_clk_mudp_phy_sys : 1;
        unsigned int gt_clk_mudp_idi_bridge : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 12;
    } reg;
} SOC_MUDP_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_pix_rx_sys_START (2)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_pix_rx_sys_END (2)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_link_START (3)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_link_END (3)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_link_sys_START (4)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_link_sys_END (4)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_ref_START (5)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_ref_END (5)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_axi2to1_START (6)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_axi2to1_END (6)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_trace_START (7)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_trace_END (7)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_sysctrl_START (8)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_sysctrl_END (8)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERCLKEN0_gt_pclk_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_phy_sys_START (10)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_phy_sys_END (10)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_idi_bridge_START (11)
#define SOC_MUDP_CRG_PERCLKEN0_gt_clk_mudp_idi_bridge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int st_pclk_mudp_apb_bridge : 1;
        unsigned int st_pclk_mudp_pix_rx : 1;
        unsigned int st_clk_mudp_pix_rx_sys : 1;
        unsigned int st_pclk_mudp_link : 1;
        unsigned int st_clk_mudp_link_sys : 1;
        unsigned int st_clk_mudp_ref : 1;
        unsigned int st_clk_mudp_axi2to1 : 1;
        unsigned int st_pclk_mudp_trace : 1;
        unsigned int st_pclk_mudp_sysctrl : 1;
        unsigned int st_pclk_mudp_phy : 1;
        unsigned int st_clk_mudp_phy_sys : 1;
        unsigned int st_clk_mudp_idi_bridge : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 12;
    } reg;
} SOC_MUDP_CRG_PERSTAT0_UNION;
#endif
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_pix_rx_sys_START (2)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_pix_rx_sys_END (2)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_link_START (3)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_link_END (3)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_link_sys_START (4)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_link_sys_END (4)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_ref_START (5)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_ref_END (5)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_axi2to1_START (6)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_axi2to1_END (6)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_trace_START (7)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_trace_END (7)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_sysctrl_START (8)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_sysctrl_END (8)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERSTAT0_st_pclk_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_phy_sys_START (10)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_phy_sys_END (10)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_idi_bridge_START (11)
#define SOC_MUDP_CRG_PERSTAT0_st_clk_mudp_idi_bridge_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_mudp_apb_bridge : 1;
        unsigned int ip_prst_mudp_pix_rx : 1;
        unsigned int ip_rst_mudp_pix_rx : 1;
        unsigned int ip_prst_mudp_link : 1;
        unsigned int ip_rst_mudp_link : 1;
        unsigned int ip_rst_mudp_axi2to1 : 1;
        unsigned int ip_prst_mudp_trace : 1;
        unsigned int ip_rst_mudp_sysctrl : 1;
        unsigned int ip_prst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy_tx0 : 1;
        unsigned int ip_rst_mudp_phy_tx1 : 1;
        unsigned int ip_rst_mudp_phy_tx2 : 1;
        unsigned int ip_rst_mudp_phy_rx0 : 1;
        unsigned int ip_rst_mudp_phy_rx1 : 1;
        unsigned int ip_rst_mudp_phy_rx2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 6;
    } reg;
} SOC_MUDP_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_pix_rx_START (2)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_pix_rx_END (2)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_link_START (3)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_link_END (3)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_link_START (4)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_link_END (4)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_axi2to1_START (5)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_axi2to1_END (5)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_trace_START (6)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_trace_END (6)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_sysctrl_START (7)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_sysctrl_END (7)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_phy_START (8)
#define SOC_MUDP_CRG_PERRSTEN0_ip_prst_mudp_phy_END (8)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx0_START (10)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx0_END (10)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx1_START (11)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx1_END (11)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx2_START (12)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_tx2_END (12)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx0_START (13)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx0_END (13)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx1_START (14)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx1_END (14)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx2_START (15)
#define SOC_MUDP_CRG_PERRSTEN0_ip_rst_mudp_phy_rx2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_mudp_apb_bridge : 1;
        unsigned int ip_prst_mudp_pix_rx : 1;
        unsigned int ip_rst_mudp_pix_rx : 1;
        unsigned int ip_prst_mudp_link : 1;
        unsigned int ip_rst_mudp_link : 1;
        unsigned int ip_rst_mudp_axi2to1 : 1;
        unsigned int ip_prst_mudp_trace : 1;
        unsigned int ip_rst_mudp_sysctrl : 1;
        unsigned int ip_prst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy_tx0 : 1;
        unsigned int ip_rst_mudp_phy_tx1 : 1;
        unsigned int ip_rst_mudp_phy_tx2 : 1;
        unsigned int ip_rst_mudp_phy_rx0 : 1;
        unsigned int ip_rst_mudp_phy_rx1 : 1;
        unsigned int ip_rst_mudp_phy_rx2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 6;
    } reg;
} SOC_MUDP_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_pix_rx_START (2)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_pix_rx_END (2)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_link_START (3)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_link_END (3)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_link_START (4)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_link_END (4)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_axi2to1_START (5)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_axi2to1_END (5)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_trace_START (6)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_trace_END (6)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_sysctrl_START (7)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_sysctrl_END (7)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_phy_START (8)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_prst_mudp_phy_END (8)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx0_START (10)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx0_END (10)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx1_START (11)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx1_END (11)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx2_START (12)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_tx2_END (12)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx0_START (13)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx0_END (13)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx1_START (14)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx1_END (14)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx2_START (15)
#define SOC_MUDP_CRG_PERRSTDIS0_ip_rst_mudp_phy_rx2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ip_prst_mudp_apb_bridge : 1;
        unsigned int ip_prst_mudp_pix_rx : 1;
        unsigned int ip_rst_mudp_pix_rx : 1;
        unsigned int ip_prst_mudp_link : 1;
        unsigned int ip_rst_mudp_link : 1;
        unsigned int ip_rst_mudp_axi2to1 : 1;
        unsigned int ip_prst_mudp_trace : 1;
        unsigned int ip_rst_mudp_sysctrl : 1;
        unsigned int ip_prst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy : 1;
        unsigned int ip_rst_mudp_phy_tx0 : 1;
        unsigned int ip_rst_mudp_phy_tx1 : 1;
        unsigned int ip_rst_mudp_phy_tx2 : 1;
        unsigned int ip_rst_mudp_phy_rx0 : 1;
        unsigned int ip_rst_mudp_phy_rx1 : 1;
        unsigned int ip_rst_mudp_phy_rx2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 6;
    } reg;
} SOC_MUDP_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_apb_bridge_START (0)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_apb_bridge_END (0)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_pix_rx_START (1)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_pix_rx_END (1)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_pix_rx_START (2)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_pix_rx_END (2)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_link_START (3)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_link_END (3)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_link_START (4)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_link_END (4)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_axi2to1_START (5)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_axi2to1_END (5)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_trace_START (6)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_trace_END (6)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_sysctrl_START (7)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_sysctrl_END (7)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_phy_START (8)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_prst_mudp_phy_END (8)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_START (9)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_END (9)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx0_START (10)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx0_END (10)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx1_START (11)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx1_END (11)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx2_START (12)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_tx2_END (12)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx0_START (13)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx0_END (13)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx1_START (14)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx1_END (14)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx2_START (15)
#define SOC_MUDP_CRG_PERRSTSTAT0_ip_rst_mudp_phy_rx2_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int mudp_apb_bridge_clkrst_bypass : 1;
        unsigned int mudp_pix_rx_clkrst_bypass : 1;
        unsigned int mudp_link_clkrst_bypass : 1;
        unsigned int mudp_trace_clkrst_bypass : 1;
        unsigned int mudp_phy_clkrst_bypass : 1;
        unsigned int mudp_sysctrl_clkrst_bypass : 1;
        unsigned int reserved_0 : 10;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 11;
    } reg;
} SOC_MUDP_CRG_IPCLKRST_BYPASS0_UNION;
#endif
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_apb_bridge_clkrst_bypass_START (0)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_apb_bridge_clkrst_bypass_END (0)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_pix_rx_clkrst_bypass_START (1)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_pix_rx_clkrst_bypass_END (1)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_link_clkrst_bypass_START (2)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_link_clkrst_bypass_END (2)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_trace_clkrst_bypass_START (3)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_trace_clkrst_bypass_END (3)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_phy_clkrst_bypass_START (4)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_phy_clkrst_bypass_END (4)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_sysctrl_clkrst_bypass_START (5)
#define SOC_MUDP_CRG_IPCLKRST_BYPASS0_mudp_sysctrl_clkrst_bypass_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int sds_sdpi_tx_ready : 3;
        unsigned int reserved_0 : 1;
        unsigned int sds_sdpi_rx_ready : 3;
        unsigned int reserved_1 : 1;
        unsigned int st_clk_mudp_trace_sys : 1;
        unsigned int st_clk_mudp_trace_rx : 1;
        unsigned int st_clk_mudp_trace_tx : 1;
        unsigned int st_clk_mudp_trace_rx_x4 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int reserved_14 : 1;
        unsigned int reserved_15 : 1;
        unsigned int reserved_16 : 6;
    } reg;
} SOC_MUDP_CRG_MUDP_STAT1_UNION;
#endif
#define SOC_MUDP_CRG_MUDP_STAT1_sds_sdpi_tx_ready_START (0)
#define SOC_MUDP_CRG_MUDP_STAT1_sds_sdpi_tx_ready_END (2)
#define SOC_MUDP_CRG_MUDP_STAT1_sds_sdpi_rx_ready_START (4)
#define SOC_MUDP_CRG_MUDP_STAT1_sds_sdpi_rx_ready_END (6)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_sys_START (8)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_sys_END (8)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_rx_START (9)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_rx_END (9)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_tx_START (10)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_tx_END (10)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_rx_x4_START (11)
#define SOC_MUDP_CRG_MUDP_STAT1_st_clk_mudp_trace_rx_x4_END (11)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
