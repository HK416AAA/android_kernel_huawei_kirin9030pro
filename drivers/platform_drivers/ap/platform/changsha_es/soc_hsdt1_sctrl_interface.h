#ifndef __SOC_HSDT1_SCTRL_INTERFACE_H__
#define __SOC_HSDT1_SCTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_HSDT1_SCTRL_usbdp_phy_iso_en_ADDR(base) ((base) + 0x010cUL)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ADDR(base) ((base) + 0x800UL)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_ADDR(base) ((base) + 0xC00UL)
#else
#define SOC_HSDT1_SCTRL_usbdp_phy_iso_en_ADDR(base) ((base) + 0x010c)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ADDR(base) ((base) + 0x800)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_ADDR(base) ((base) + 0xC00)
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int usbdp_phy_iso_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_HSDT1_SCTRL_usbdp_phy_iso_en_UNION;
#endif
#define SOC_HSDT1_SCTRL_usbdp_phy_iso_en_usbdp_phy_iso_en_START (0)
#define SOC_HSDT1_SCTRL_usbdp_phy_iso_en_usbdp_phy_iso_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int ioc_sd_htol_test_sel : 1;
        unsigned int ioc_htol_messure_clk_en : 1;
        unsigned int ioc_htol_test_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_UNION;
#endif
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_sd_htol_test_sel_START (0)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_sd_htol_test_sel_END (0)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_htol_messure_clk_en_START (1)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_htol_messure_clk_en_END (1)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_htol_test_sel_START (2)
#define SOC_HSDT1_SCTRL_HSDT1_htol_ctrl_ioc_htol_test_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union {
    unsigned int value;
    struct {
        unsigned int dss_lite_stream_to_dp_sel : 1;
        unsigned int dss_stream0_to_dp_sel : 1;
        unsigned int dss_stream1_to_dp_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_HSDT1_SCTRL_DSS_STREAM_SEL_UNION;
#endif
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_lite_stream_to_dp_sel_START (0)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_lite_stream_to_dp_sel_END (0)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_stream0_to_dp_sel_START (1)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_stream0_to_dp_sel_END (1)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_stream1_to_dp_sel_START (2)
#define SOC_HSDT1_SCTRL_DSS_STREAM_SEL_dss_stream1_to_dp_sel_END (2)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
