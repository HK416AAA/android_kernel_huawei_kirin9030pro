#ifndef __SOC_MEDIA2_CRG_INTERFACE_H__
#define __SOC_MEDIA2_CRG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define SOC_MEDIA2_CRG_PEREN0_ADDR(base) ((base) + (0x000UL))
#define SOC_MEDIA2_CRG_PERDIS0_ADDR(base) ((base) + (0x004UL))
#define SOC_MEDIA2_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008UL))
#define SOC_MEDIA2_CRG_PERSTAT0_ADDR(base) ((base) + (0x00CUL))
#define SOC_MEDIA2_CRG_PEREN1_ADDR(base) ((base) + (0x010UL))
#define SOC_MEDIA2_CRG_PERDIS1_ADDR(base) ((base) + (0x014UL))
#define SOC_MEDIA2_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018UL))
#define SOC_MEDIA2_CRG_PERSTAT1_ADDR(base) ((base) + (0x01CUL))
#define SOC_MEDIA2_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030UL))
#define SOC_MEDIA2_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038UL))
#define SOC_MEDIA2_CRG_CLKDIV0_ADDR(base) ((base) + (0x080UL))
#define SOC_MEDIA2_CRG_CLKDIV1_ADDR(base) ((base) + (0x084UL))
#define SOC_MEDIA2_CRG_CLKDIV2_ADDR(base) ((base) + (0x088UL))
#define SOC_MEDIA2_CRG_CLKDIV3_ADDR(base) ((base) + (0x08CUL))
#define SOC_MEDIA2_CRG_CLKDIV4_ADDR(base) ((base) + (0x090UL))
#define SOC_MEDIA2_CRG_CLKDIV5_ADDR(base) ((base) + (0x094UL))
#define SOC_MEDIA2_CRG_CLKDIV6_ADDR(base) ((base) + (0x098UL))
#define SOC_MEDIA2_CRG_CLKDIV7_ADDR(base) ((base) + (0x09CUL))
#define SOC_MEDIA2_CRG_CLKDIV8_ADDR(base) ((base) + (0x0A0UL))
#define SOC_MEDIA2_CRG_CLKDIV9_ADDR(base) ((base) + (0x0A4UL))
#define SOC_MEDIA2_CRG_CLKDIV10_ADDR(base) ((base) + (0x0A8UL))
#define SOC_MEDIA2_CRG_CLKDIV11_ADDR(base) ((base) + (0x0ACUL))
#define SOC_MEDIA2_CRG_CLKDIV12_ADDR(base) ((base) + (0x0B0UL))
#define SOC_MEDIA2_CRG_CLKDIV13_ADDR(base) ((base) + (0x0B4UL))
#define SOC_MEDIA2_CRG_CLKDIV14_ADDR(base) ((base) + (0x0B8UL))
#define SOC_MEDIA2_CRG_CLKDIV15_ADDR(base) ((base) + (0x0BCUL))
#define SOC_MEDIA2_CRG_CLKDIV16_ADDR(base) ((base) + (0x0C0UL))
#define SOC_MEDIA2_CRG_CLKDIV17_ADDR(base) ((base) + (0x0C4UL))
#define SOC_MEDIA2_CRG_CLKDIV18_ADDR(base) ((base) + (0x0C8UL))
#define SOC_MEDIA2_CRG_CLKDIV19_ADDR(base) ((base) + (0x0CCUL))
#define SOC_MEDIA2_CRG_PERI_STAT0_ADDR(base) ((base) + (0x120UL))
#define SOC_MEDIA2_CRG_PERI_STAT1_ADDR(base) ((base) + (0x124UL))
#define SOC_MEDIA2_CRG_PERI_STAT2_ADDR(base) ((base) + (0x128UL))
#define SOC_MEDIA2_CRG_PERI_STAT3_ADDR(base) ((base) + (0x12CUL))
#define SOC_MEDIA2_CRG_ISPCPU_CLKEN_ADDR(base) ((base) + (0x140UL))
#define SOC_MEDIA2_CRG_ISPCPU_RSTEN_ADDR(base) ((base) + (0x144UL))
#define SOC_MEDIA2_CRG_ISPCPU_RSTDIS_ADDR(base) ((base) + (0x148UL))
#define SOC_MEDIA2_CRG_ISPCPU_RSTSTAT_ADDR(base) ((base) + (0x14CUL))
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_ADDR(base) ((base) + (0x150UL))
#define SOC_MEDIA2_CRG_ISP_CPU_STATE1_ADDR(base) ((base) + (0x154UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160UL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x16cUL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x170UL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x174UL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP2_BYPASS_ADDR(base) ((base) + (0x178UL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP3_BYPASS_ADDR(base) ((base) + (0x17cUL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP4_BYPASS_ADDR(base) ((base) + (0x180UL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP5_BYPASS_ADDR(base) ((base) + (0x184UL))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP6_BYPASS_ADDR(base) ((base) + (0x188UL))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x18cUL))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x190UL))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP2_BYPASS_ADDR(base) ((base) + (0x194UL))
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_ADDR(base) ((base) + (0x198UL))
#define SOC_MEDIA2_CRG_ISPTOMED_RESERVE_OUT_ADDR(base) ((base) + (0x19cUL))
#define SOC_MEDIA2_CRG_PERI_AUTODIV_STAT_ADDR(base) ((base) + (0x1A0UL))
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0UL))
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4UL))
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x1D8UL))
#define SOC_MEDIA2_CRG_HPM_CFG_ADDR(base) ((base) + (0x200UL))
#define SOC_MEDIA2_CRG_HPM_READ_BACK_ADDR(base) ((base) + (0x204UL))
#define SOC_MEDIA2_CRG_HPMX_CFG_ADDR(base) ((base) + (0x208UL))
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_ADDR(base) ((base) + (0x20CUL))
#define SOC_MEDIA2_CRG_HPM0_CFG_ADDR(base) ((base) + (0x210UL))
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_ADDR(base) ((base) + (0x214UL))
#define SOC_MEDIA2_CRG_HPMX0_CFG_ADDR(base) ((base) + (0x218UL))
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_ADDR(base) ((base) + (0x21CUL))
#define SOC_MEDIA2_CRG_HPM1_CFG_ADDR(base) ((base) + (0x220UL))
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_ADDR(base) ((base) + (0x224UL))
#define SOC_MEDIA2_CRG_HPMX1_CFG_ADDR(base) ((base) + (0x228UL))
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_ADDR(base) ((base) + (0x22CUL))
#define SOC_MEDIA2_CRG_ISP_READ_BACK0_ADDR(base) ((base) + (0x408UL))
#define SOC_MEDIA2_CRG_ISP_READ_BACK1_ADDR(base) ((base) + (0x40CUL))
#define SOC_MEDIA2_CRG_ISP_HIMINIBUS_CTRL_ADDR(base) ((base) + (0x410UL))
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ADDR(base) ((base) + (0xC00UL))
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ADDR(base) ((base) + (0xC04UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ADDR(base) ((base) + (0xC08UL))
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_ADDR(base) ((base) + (0xC30UL))
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_ADDR(base) ((base) + (0xC34UL))
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_ADDR(base) ((base) + (0xC38UL))
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_ADDR(base) ((base) + (0xC3CUL))
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ADDR(base) ((base) + (0xD00UL))
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ADDR(base) ((base) + (0xD04UL))
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ADDR(base) ((base) + (0xD08UL))
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_ADDR(base) ((base) + (0xD10UL))
#define SOC_MEDIA2_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00UL))
#else
#define SOC_MEDIA2_CRG_PEREN0_ADDR(base) ((base) + (0x000))
#define SOC_MEDIA2_CRG_PERDIS0_ADDR(base) ((base) + (0x004))
#define SOC_MEDIA2_CRG_PERCLKEN0_ADDR(base) ((base) + (0x008))
#define SOC_MEDIA2_CRG_PERSTAT0_ADDR(base) ((base) + (0x00C))
#define SOC_MEDIA2_CRG_PEREN1_ADDR(base) ((base) + (0x010))
#define SOC_MEDIA2_CRG_PERDIS1_ADDR(base) ((base) + (0x014))
#define SOC_MEDIA2_CRG_PERCLKEN1_ADDR(base) ((base) + (0x018))
#define SOC_MEDIA2_CRG_PERSTAT1_ADDR(base) ((base) + (0x01C))
#define SOC_MEDIA2_CRG_PERRSTEN0_ADDR(base) ((base) + (0x030))
#define SOC_MEDIA2_CRG_PERRSTDIS0_ADDR(base) ((base) + (0x034))
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ADDR(base) ((base) + (0x038))
#define SOC_MEDIA2_CRG_CLKDIV0_ADDR(base) ((base) + (0x080))
#define SOC_MEDIA2_CRG_CLKDIV1_ADDR(base) ((base) + (0x084))
#define SOC_MEDIA2_CRG_CLKDIV2_ADDR(base) ((base) + (0x088))
#define SOC_MEDIA2_CRG_CLKDIV3_ADDR(base) ((base) + (0x08C))
#define SOC_MEDIA2_CRG_CLKDIV4_ADDR(base) ((base) + (0x090))
#define SOC_MEDIA2_CRG_CLKDIV5_ADDR(base) ((base) + (0x094))
#define SOC_MEDIA2_CRG_CLKDIV6_ADDR(base) ((base) + (0x098))
#define SOC_MEDIA2_CRG_CLKDIV7_ADDR(base) ((base) + (0x09C))
#define SOC_MEDIA2_CRG_CLKDIV8_ADDR(base) ((base) + (0x0A0))
#define SOC_MEDIA2_CRG_CLKDIV9_ADDR(base) ((base) + (0x0A4))
#define SOC_MEDIA2_CRG_CLKDIV10_ADDR(base) ((base) + (0x0A8))
#define SOC_MEDIA2_CRG_CLKDIV11_ADDR(base) ((base) + (0x0AC))
#define SOC_MEDIA2_CRG_CLKDIV12_ADDR(base) ((base) + (0x0B0))
#define SOC_MEDIA2_CRG_CLKDIV13_ADDR(base) ((base) + (0x0B4))
#define SOC_MEDIA2_CRG_CLKDIV14_ADDR(base) ((base) + (0x0B8))
#define SOC_MEDIA2_CRG_CLKDIV15_ADDR(base) ((base) + (0x0BC))
#define SOC_MEDIA2_CRG_CLKDIV16_ADDR(base) ((base) + (0x0C0))
#define SOC_MEDIA2_CRG_CLKDIV17_ADDR(base) ((base) + (0x0C4))
#define SOC_MEDIA2_CRG_CLKDIV18_ADDR(base) ((base) + (0x0C8))
#define SOC_MEDIA2_CRG_CLKDIV19_ADDR(base) ((base) + (0x0CC))
#define SOC_MEDIA2_CRG_PERI_STAT0_ADDR(base) ((base) + (0x120))
#define SOC_MEDIA2_CRG_PERI_STAT1_ADDR(base) ((base) + (0x124))
#define SOC_MEDIA2_CRG_PERI_STAT2_ADDR(base) ((base) + (0x128))
#define SOC_MEDIA2_CRG_PERI_STAT3_ADDR(base) ((base) + (0x12C))
#define SOC_MEDIA2_CRG_ISPCPU_CLKEN_ADDR(base) ((base) + (0x140))
#define SOC_MEDIA2_CRG_ISPCPU_RSTEN_ADDR(base) ((base) + (0x144))
#define SOC_MEDIA2_CRG_ISPCPU_RSTDIS_ADDR(base) ((base) + (0x148))
#define SOC_MEDIA2_CRG_ISPCPU_RSTSTAT_ADDR(base) ((base) + (0x14C))
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_ADDR(base) ((base) + (0x150))
#define SOC_MEDIA2_CRG_ISP_CPU_STATE1_ADDR(base) ((base) + (0x154))
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_ADDR(base) ((base) + (0x160))
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_ADDR(base) ((base) + (0x16c))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x170))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x174))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP2_BYPASS_ADDR(base) ((base) + (0x178))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP3_BYPASS_ADDR(base) ((base) + (0x17c))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP4_BYPASS_ADDR(base) ((base) + (0x180))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP5_BYPASS_ADDR(base) ((base) + (0x184))
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP6_BYPASS_ADDR(base) ((base) + (0x188))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP0_BYPASS_ADDR(base) ((base) + (0x18c))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP1_BYPASS_ADDR(base) ((base) + (0x190))
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP2_BYPASS_ADDR(base) ((base) + (0x194))
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_ADDR(base) ((base) + (0x198))
#define SOC_MEDIA2_CRG_ISPTOMED_RESERVE_OUT_ADDR(base) ((base) + (0x19c))
#define SOC_MEDIA2_CRG_PERI_AUTODIV_STAT_ADDR(base) ((base) + (0x1A0))
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D0))
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_ADDR(base) ((base) + (0x1D4))
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_ADDR(base) ((base) + (0x1D8))
#define SOC_MEDIA2_CRG_HPM_CFG_ADDR(base) ((base) + (0x200))
#define SOC_MEDIA2_CRG_HPM_READ_BACK_ADDR(base) ((base) + (0x204))
#define SOC_MEDIA2_CRG_HPMX_CFG_ADDR(base) ((base) + (0x208))
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_ADDR(base) ((base) + (0x20C))
#define SOC_MEDIA2_CRG_HPM0_CFG_ADDR(base) ((base) + (0x210))
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_ADDR(base) ((base) + (0x214))
#define SOC_MEDIA2_CRG_HPMX0_CFG_ADDR(base) ((base) + (0x218))
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_ADDR(base) ((base) + (0x21C))
#define SOC_MEDIA2_CRG_HPM1_CFG_ADDR(base) ((base) + (0x220))
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_ADDR(base) ((base) + (0x224))
#define SOC_MEDIA2_CRG_HPMX1_CFG_ADDR(base) ((base) + (0x228))
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_ADDR(base) ((base) + (0x22C))
#define SOC_MEDIA2_CRG_ISP_READ_BACK0_ADDR(base) ((base) + (0x408))
#define SOC_MEDIA2_CRG_ISP_READ_BACK1_ADDR(base) ((base) + (0x40C))
#define SOC_MEDIA2_CRG_ISP_HIMINIBUS_CTRL_ADDR(base) ((base) + (0x410))
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ADDR(base) ((base) + (0xC00))
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ADDR(base) ((base) + (0xC04))
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ADDR(base) ((base) + (0xC08))
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_ADDR(base) ((base) + (0xC30))
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_ADDR(base) ((base) + (0xC34))
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_ADDR(base) ((base) + (0xC38))
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_ADDR(base) ((base) + (0xC3C))
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ADDR(base) ((base) + (0xD00))
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ADDR(base) ((base) + (0xD04))
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ADDR(base) ((base) + (0xD08))
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_ADDR(base) ((base) + (0xD10))
#define SOC_MEDIA2_CRG_DECPROT0SET_ADDR(base) ((base) + (0xF00))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_clk_isp_oisp : 1;
        unsigned int gt_clk_csi_idi : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_atclk_isp_cpu : 1;
        unsigned int gt_clk_isp_in_sys : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_p2j : 1;
        unsigned int gt_pclk_csi_wrapper_cfg : 1;
        unsigned int gt_pclk_isp : 1;
        unsigned int gt_clk_qic_tcu_m2 : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_qic_m2 : 1;
        unsigned int gt_clk_isp_i3c : 1;
        unsigned int gt_clk_ipp : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_isp_srt : 1;
        unsigned int gt_clk_isp_nrt : 1;
        unsigned int gt_clk_isp_rt : 1;
        unsigned int gt_clk_isp_spi : 1;
        unsigned int gt_clk_qice_isp : 1;
        unsigned int gt_clk_qice_data_media2 : 1;
        unsigned int gt_pclk_autodiv_aclk_qic_tcu : 1;
        unsigned int gt_clk_miniisp_csi : 1;
        unsigned int gt_pclk_dbg_isp : 1;
        unsigned int gt_clk_isp_top : 1;
        unsigned int gt_clk_isp_hpm : 1;
        unsigned int gt_clk_lat_mon_isp : 1;
        unsigned int gt_clk_lat_mon_miniisp : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_MEDIA2_CRG_PEREN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_hpm_START (0)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_hpm_END (0)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_oisp_START (1)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_oisp_END (1)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgm_isp_START (3)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_atgm_isp_END (3)
#define SOC_MEDIA2_CRG_PEREN0_gt_atclk_isp_cpu_START (4)
#define SOC_MEDIA2_CRG_PEREN0_gt_atclk_isp_cpu_END (4)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_in_sys_START (5)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_in_sys_END (5)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_p2j_START (7)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_p2j_END (7)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_isp_START (9)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_isp_END (9)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qic_tcu_m2_START (10)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qic_tcu_m2_END (10)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_isp_START (11)
#define SOC_MEDIA2_CRG_PEREN0_gt_aclk_isp_END (11)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qic_m2_START (12)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qic_m2_END (12)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_i3c_START (13)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_i3c_END (13)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ipp_START (14)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_ipp_END (14)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_cpu_START (15)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_cpu_END (15)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_srt_START (16)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_srt_END (16)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_nrt_START (17)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_nrt_END (17)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_rt_START (18)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_rt_END (18)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_spi_START (19)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_spi_END (19)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qice_isp_START (20)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qice_isp_END (20)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qice_data_media2_START (21)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_qice_data_media2_END (21)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_aclk_qic_tcu_START (22)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_autodiv_aclk_qic_tcu_END (22)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_miniisp_csi_START (23)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_miniisp_csi_END (23)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_dbg_isp_START (24)
#define SOC_MEDIA2_CRG_PEREN0_gt_pclk_dbg_isp_END (24)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_top_START (25)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_top_END (25)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_hpm_START (26)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_isp_hpm_END (26)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_lat_mon_isp_START (27)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_lat_mon_isp_END (27)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_lat_mon_miniisp_START (28)
#define SOC_MEDIA2_CRG_PEREN0_gt_clk_lat_mon_miniisp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_clk_isp_oisp : 1;
        unsigned int gt_clk_csi_idi : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_atclk_isp_cpu : 1;
        unsigned int gt_clk_isp_in_sys : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_p2j : 1;
        unsigned int gt_pclk_csi_wrapper_cfg : 1;
        unsigned int gt_pclk_isp : 1;
        unsigned int gt_clk_qic_tcu_m2 : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_qic_m2 : 1;
        unsigned int gt_clk_isp_i3c : 1;
        unsigned int gt_clk_ipp : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_isp_srt : 1;
        unsigned int gt_clk_isp_nrt : 1;
        unsigned int gt_clk_isp_rt : 1;
        unsigned int gt_clk_isp_spi : 1;
        unsigned int gt_clk_qice_isp : 1;
        unsigned int gt_clk_qice_data_media2 : 1;
        unsigned int gt_pclk_autodiv_aclk_qic_tcu : 1;
        unsigned int gt_clk_miniisp_csi : 1;
        unsigned int gt_pclk_dbg_isp : 1;
        unsigned int gt_clk_isp_top : 1;
        unsigned int gt_clk_isp_hpm : 1;
        unsigned int gt_clk_lat_mon_isp : 1;
        unsigned int gt_clk_lat_mon_miniisp : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERDIS0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_hpm_START (0)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_hpm_END (0)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_oisp_START (1)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_oisp_END (1)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgm_isp_START (3)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_atgm_isp_END (3)
#define SOC_MEDIA2_CRG_PERDIS0_gt_atclk_isp_cpu_START (4)
#define SOC_MEDIA2_CRG_PERDIS0_gt_atclk_isp_cpu_END (4)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_in_sys_START (5)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_in_sys_END (5)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_p2j_START (7)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_p2j_END (7)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_isp_START (9)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_isp_END (9)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qic_tcu_m2_START (10)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qic_tcu_m2_END (10)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_isp_START (11)
#define SOC_MEDIA2_CRG_PERDIS0_gt_aclk_isp_END (11)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qic_m2_START (12)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qic_m2_END (12)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_i3c_START (13)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_i3c_END (13)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ipp_START (14)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_ipp_END (14)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_cpu_START (15)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_cpu_END (15)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_srt_START (16)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_srt_END (16)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_nrt_START (17)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_nrt_END (17)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_rt_START (18)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_rt_END (18)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_spi_START (19)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_spi_END (19)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qice_isp_START (20)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qice_isp_END (20)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qice_data_media2_START (21)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_qice_data_media2_END (21)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_aclk_qic_tcu_START (22)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_autodiv_aclk_qic_tcu_END (22)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_miniisp_csi_START (23)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_miniisp_csi_END (23)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_dbg_isp_START (24)
#define SOC_MEDIA2_CRG_PERDIS0_gt_pclk_dbg_isp_END (24)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_top_START (25)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_top_END (25)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_hpm_START (26)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_isp_hpm_END (26)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_lat_mon_isp_START (27)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_lat_mon_isp_END (27)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_lat_mon_miniisp_START (28)
#define SOC_MEDIA2_CRG_PERDIS0_gt_clk_lat_mon_miniisp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_hpm : 1;
        unsigned int gt_clk_isp_oisp : 1;
        unsigned int gt_clk_csi_idi : 1;
        unsigned int gt_pclk_atgm_isp : 1;
        unsigned int gt_atclk_isp_cpu : 1;
        unsigned int gt_clk_isp_in_sys : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_pclk_p2j : 1;
        unsigned int gt_pclk_csi_wrapper_cfg : 1;
        unsigned int gt_pclk_isp : 1;
        unsigned int gt_clk_qic_tcu_m2 : 1;
        unsigned int gt_aclk_isp : 1;
        unsigned int gt_clk_qic_m2 : 1;
        unsigned int gt_clk_isp_i3c : 1;
        unsigned int gt_clk_ipp : 1;
        unsigned int gt_clk_isp_cpu : 1;
        unsigned int gt_clk_isp_srt : 1;
        unsigned int gt_clk_isp_nrt : 1;
        unsigned int gt_clk_isp_rt : 1;
        unsigned int gt_clk_isp_spi : 1;
        unsigned int gt_clk_qice_isp : 1;
        unsigned int gt_clk_qice_data_media2 : 1;
        unsigned int gt_pclk_autodiv_aclk_qic_tcu : 1;
        unsigned int gt_clk_miniisp_csi : 1;
        unsigned int gt_pclk_dbg_isp : 1;
        unsigned int gt_clk_isp_top : 1;
        unsigned int gt_clk_isp_hpm : 1;
        unsigned int gt_clk_lat_mon_isp : 1;
        unsigned int gt_clk_lat_mon_miniisp : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERCLKEN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_hpm_START (0)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_hpm_END (0)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_oisp_START (1)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_oisp_END (1)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgm_isp_START (3)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_atgm_isp_END (3)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_atclk_isp_cpu_START (4)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_atclk_isp_cpu_END (4)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_in_sys_START (5)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_in_sys_END (5)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_p2j_START (7)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_p2j_END (7)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_isp_START (9)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_isp_END (9)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qic_tcu_m2_START (10)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qic_tcu_m2_END (10)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_isp_START (11)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_aclk_isp_END (11)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qic_m2_START (12)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qic_m2_END (12)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_i3c_START (13)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_i3c_END (13)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ipp_START (14)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_ipp_END (14)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_cpu_START (15)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_cpu_END (15)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_srt_START (16)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_srt_END (16)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_nrt_START (17)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_nrt_END (17)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_rt_START (18)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_rt_END (18)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_spi_START (19)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_spi_END (19)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qice_isp_START (20)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qice_isp_END (20)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qice_data_media2_START (21)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_qice_data_media2_END (21)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_aclk_qic_tcu_START (22)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_autodiv_aclk_qic_tcu_END (22)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_miniisp_csi_START (23)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_miniisp_csi_END (23)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_dbg_isp_START (24)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_pclk_dbg_isp_END (24)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_top_START (25)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_top_END (25)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_hpm_START (26)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_isp_hpm_END (26)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_lat_mon_isp_START (27)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_lat_mon_isp_END (27)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_lat_mon_miniisp_START (28)
#define SOC_MEDIA2_CRG_PERCLKEN0_gt_clk_lat_mon_miniisp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_hpm : 1;
        unsigned int st_clk_isp_oisp : 1;
        unsigned int st_clk_csi_idi : 1;
        unsigned int st_pclk_atgm_isp : 1;
        unsigned int st_atclk_isp_cpu : 1;
        unsigned int st_clk_isp_in_sys : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_pclk_p2j : 1;
        unsigned int st_pclk_csi_wrapper_cfg : 1;
        unsigned int st_pclk_isp : 1;
        unsigned int st_clk_qic_tcu_m2 : 1;
        unsigned int st_aclk_isp : 1;
        unsigned int st_clk_qic_m2 : 1;
        unsigned int st_clk_isp_i3c : 1;
        unsigned int st_clk_ipp : 1;
        unsigned int st_clk_isp_cpu : 1;
        unsigned int st_clk_isp_srt : 1;
        unsigned int st_clk_isp_nrt : 1;
        unsigned int st_clk_isp_rt : 1;
        unsigned int st_clk_isp_spi : 1;
        unsigned int st_clk_qice_isp : 1;
        unsigned int st_clk_qice_data_media2 : 1;
        unsigned int st_pclk_autodiv_aclk_qic_tcu : 1;
        unsigned int st_clk_miniisp_csi : 1;
        unsigned int st_pclk_dbg_isp : 1;
        unsigned int st_clk_isp_top : 1;
        unsigned int st_clk_isp_hpm : 1;
        unsigned int st_clk_lat_mon_isp : 1;
        unsigned int st_clk_lat_mon_miniisp : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERSTAT0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_hpm_START (0)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_hpm_END (0)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_oisp_START (1)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_oisp_END (1)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgm_isp_START (3)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_atgm_isp_END (3)
#define SOC_MEDIA2_CRG_PERSTAT0_st_atclk_isp_cpu_START (4)
#define SOC_MEDIA2_CRG_PERSTAT0_st_atclk_isp_cpu_END (4)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_in_sys_START (5)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_in_sys_END (5)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_p2j_START (7)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_p2j_END (7)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_isp_START (9)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_isp_END (9)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qic_tcu_m2_START (10)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qic_tcu_m2_END (10)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_isp_START (11)
#define SOC_MEDIA2_CRG_PERSTAT0_st_aclk_isp_END (11)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qic_m2_START (12)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qic_m2_END (12)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_i3c_START (13)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_i3c_END (13)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ipp_START (14)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_ipp_END (14)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_cpu_START (15)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_cpu_END (15)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_srt_START (16)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_srt_END (16)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_nrt_START (17)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_nrt_END (17)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_rt_START (18)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_rt_END (18)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_spi_START (19)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_spi_END (19)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qice_isp_START (20)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qice_isp_END (20)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qice_data_media2_START (21)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_qice_data_media2_END (21)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_aclk_qic_tcu_START (22)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_autodiv_aclk_qic_tcu_END (22)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_miniisp_csi_START (23)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_miniisp_csi_END (23)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_dbg_isp_START (24)
#define SOC_MEDIA2_CRG_PERSTAT0_st_pclk_dbg_isp_END (24)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_top_START (25)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_top_END (25)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_hpm_START (26)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_isp_hpm_END (26)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_lat_mon_isp_START (27)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_lat_mon_isp_END (27)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_lat_mon_miniisp_START (28)
#define SOC_MEDIA2_CRG_PERSTAT0_st_clk_lat_mon_miniisp_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ispcpu_gic : 1;
        unsigned int gt_clk_ispcpu_periph : 1;
        unsigned int gt_clk_ispcpu_periph_core : 1;
        unsigned int gt_clk_ispcpu_djtag : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_ispcpu_dldo : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 22;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_MEDIA2_CRG_PEREN1_UNION;
#endif
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_gic_START (0)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_gic_END (0)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_periph_START (1)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_periph_END (1)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_periph_core_START (2)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_periph_core_END (2)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_djtag_START (3)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_djtag_END (3)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_dldo_START (5)
#define SOC_MEDIA2_CRG_PEREN1_gt_clk_ispcpu_dldo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ispcpu_gic : 1;
        unsigned int gt_clk_ispcpu_periph : 1;
        unsigned int gt_clk_ispcpu_periph_core : 1;
        unsigned int gt_clk_ispcpu_djtag : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_ispcpu_dldo : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 22;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERDIS1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_gic_START (0)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_gic_END (0)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_periph_START (1)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_periph_END (1)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_periph_core_START (2)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_periph_core_END (2)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_djtag_START (3)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_djtag_END (3)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_dldo_START (5)
#define SOC_MEDIA2_CRG_PERDIS1_gt_clk_ispcpu_dldo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_ispcpu_gic : 1;
        unsigned int gt_clk_ispcpu_periph : 1;
        unsigned int gt_clk_ispcpu_periph_core : 1;
        unsigned int gt_clk_ispcpu_djtag : 1;
        unsigned int reserved_0 : 1;
        unsigned int gt_clk_ispcpu_dldo : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 22;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERCLKEN1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_gic_START (0)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_gic_END (0)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_periph_START (1)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_periph_END (1)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_periph_core_START (2)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_periph_core_END (2)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_djtag_START (3)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_djtag_END (3)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_dldo_START (5)
#define SOC_MEDIA2_CRG_PERCLKEN1_gt_clk_ispcpu_dldo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_ispcpu_gic : 1;
        unsigned int st_clk_ispcpu_periph : 1;
        unsigned int st_clk_ispcpu_periph_core : 1;
        unsigned int st_clk_ispcpu_djtag : 1;
        unsigned int reserved_0 : 1;
        unsigned int st_clk_ispcpu_dldo : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 22;
        unsigned int reserved_5 : 1;
    } reg;
} SOC_MEDIA2_CRG_PERSTAT1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_gic_START (0)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_gic_END (0)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_periph_START (1)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_periph_END (1)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_periph_core_START (2)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_periph_core_END (2)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_djtag_START (3)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_djtag_END (3)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_dldo_START (5)
#define SOC_MEDIA2_CRG_PERSTAT1_st_clk_ispcpu_dldo_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_isp_qic : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_media2_qic_data : 1;
        unsigned int ip_rst_tcu : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_p2j : 1;
        unsigned int ip_rst_isp_hpm0 : 1;
        unsigned int ip_rst_isp_hpm1 : 1;
        unsigned int ip_rst_isp_perf : 1;
        unsigned int ip_rst_isp_rt : 1;
        unsigned int ip_rst_isp_srt : 1;
        unsigned int ip_rst_isp_nrt : 1;
        unsigned int ip_rst_lat_mon_isp : 1;
        unsigned int ip_rst_lat_mon_miniisp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgm_isp_qic_START (0)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_prst_atgm_isp_qic_END (0)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_qice_data_START (1)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_qice_data_END (1)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_media2_qic_data_START (2)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_media2_qic_data_END (2)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_tcu_START (3)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_tcu_END (3)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_hpm_START (4)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_hpm_END (4)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_p2j_START (5)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_p2j_END (5)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_hpm0_START (6)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_hpm0_END (6)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_hpm1_START (7)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_hpm1_END (7)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_perf_START (8)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_perf_END (8)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_rt_START (9)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_rt_END (9)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_srt_START (10)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_srt_END (10)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_nrt_START (11)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_isp_nrt_END (11)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_lat_mon_isp_START (12)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_lat_mon_isp_END (12)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_lat_mon_miniisp_START (13)
#define SOC_MEDIA2_CRG_PERRSTEN0_ip_rst_lat_mon_miniisp_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_isp_qic : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_media2_qic_data : 1;
        unsigned int ip_rst_tcu : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_p2j : 1;
        unsigned int ip_rst_isp_hpm0 : 1;
        unsigned int ip_rst_isp_hpm1 : 1;
        unsigned int ip_rst_isp_perf : 1;
        unsigned int ip_rst_isp_rt : 1;
        unsigned int ip_rst_isp_srt : 1;
        unsigned int ip_rst_isp_nrt : 1;
        unsigned int ip_rst_lat_mon_isp : 1;
        unsigned int ip_rst_lat_mon_miniisp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgm_isp_qic_START (0)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_prst_atgm_isp_qic_END (0)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_qice_data_START (1)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_qice_data_END (1)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_media2_qic_data_START (2)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_media2_qic_data_END (2)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_tcu_START (3)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_tcu_END (3)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_hpm_START (4)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_hpm_END (4)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_p2j_START (5)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_p2j_END (5)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_hpm0_START (6)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_hpm0_END (6)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_hpm1_START (7)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_hpm1_END (7)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_perf_START (8)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_perf_END (8)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_rt_START (9)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_rt_END (9)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_srt_START (10)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_srt_END (10)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_nrt_START (11)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_isp_nrt_END (11)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_lat_mon_isp_START (12)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_lat_mon_isp_END (12)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_lat_mon_miniisp_START (13)
#define SOC_MEDIA2_CRG_PERRSTDIS0_ip_rst_lat_mon_miniisp_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_prst_atgm_isp_qic : 1;
        unsigned int ip_rst_qice_data : 1;
        unsigned int ip_rst_media2_qic_data : 1;
        unsigned int ip_rst_tcu : 1;
        unsigned int ip_rst_hpm : 1;
        unsigned int ip_rst_p2j : 1;
        unsigned int ip_rst_isp_hpm0 : 1;
        unsigned int ip_rst_isp_hpm1 : 1;
        unsigned int ip_rst_isp_perf : 1;
        unsigned int ip_rst_isp_rt : 1;
        unsigned int ip_rst_isp_srt : 1;
        unsigned int ip_rst_isp_nrt : 1;
        unsigned int ip_rst_lat_mon_isp : 1;
        unsigned int ip_rst_lat_mon_miniisp : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 12;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgm_isp_qic_START (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_prst_atgm_isp_qic_END (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_qice_data_START (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_qice_data_END (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_media2_qic_data_START (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_media2_qic_data_END (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_tcu_START (3)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_tcu_END (3)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_hpm_START (4)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_hpm_END (4)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_p2j_START (5)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_p2j_END (5)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_hpm0_START (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_hpm0_END (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_hpm1_START (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_hpm1_END (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_perf_START (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_perf_END (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_rt_START (9)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_rt_END (9)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_srt_START (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_srt_END (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_nrt_START (11)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_isp_nrt_END (11)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_lat_mon_isp_START (12)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_lat_mon_isp_END (12)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_lat_mon_miniisp_START (13)
#define SOC_MEDIA2_CRG_PERRSTSTAT0_ip_rst_lat_mon_miniisp_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_isp_srt_pll : 4;
        unsigned int sel_isp_rt_pll : 4;
        unsigned int sel_isp_nrt_pll : 4;
        unsigned int sel_isp_srt_2sw_pll : 1;
        unsigned int sel_isp_nrt_2sw_pll : 1;
        unsigned int reserved : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV0_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_srt_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_srt_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_rt_pll_START (4)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_rt_pll_END (7)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_nrt_pll_START (8)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_nrt_pll_END (11)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_srt_2sw_pll_START (12)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_srt_2sw_pll_END (12)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_nrt_2sw_pll_START (13)
#define SOC_MEDIA2_CRG_CLKDIV0_sel_isp_nrt_2sw_pll_END (13)
#define SOC_MEDIA2_CRG_CLKDIV0_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV0_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_miniisp_pll : 4;
        unsigned int sel_clk_csi_idi_pll : 4;
        unsigned int sel_clk_idi2axi_csid : 4;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV1_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV1_sel_miniisp_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV1_sel_miniisp_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV1_sel_clk_csi_idi_pll_START (4)
#define SOC_MEDIA2_CRG_CLKDIV1_sel_clk_csi_idi_pll_END (7)
#define SOC_MEDIA2_CRG_CLKDIV1_sel_clk_idi2axi_csid_START (8)
#define SOC_MEDIA2_CRG_CLKDIV1_sel_clk_idi2axi_csid_END (11)
#define SOC_MEDIA2_CRG_CLKDIV1_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV1_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_isp_cpu_pll : 4;
        unsigned int sel_qic_m2_data_pll : 4;
        unsigned int sel_isp_top_pll : 4;
        unsigned int sel_ispcpu_4sw_pll : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV2_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV2_sel_isp_cpu_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_isp_cpu_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_qic_m2_data_pll_START (4)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_qic_m2_data_pll_END (7)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_isp_top_pll_START (8)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_isp_top_pll_END (11)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_ispcpu_4sw_pll_START (12)
#define SOC_MEDIA2_CRG_CLKDIV2_sel_ispcpu_4sw_pll_END (15)
#define SOC_MEDIA2_CRG_CLKDIV2_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV2_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_hpm_pll : 4;
        unsigned int sel_isp_oisp_pll : 4;
        unsigned int sel_ipp_pll : 4;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV3_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV3_sel_hpm_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV3_sel_hpm_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV3_sel_isp_oisp_pll_START (4)
#define SOC_MEDIA2_CRG_CLKDIV3_sel_isp_oisp_pll_END (7)
#define SOC_MEDIA2_CRG_CLKDIV3_sel_ipp_pll_START (8)
#define SOC_MEDIA2_CRG_CLKDIV3_sel_ipp_pll_END (11)
#define SOC_MEDIA2_CRG_CLKDIV3_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV3_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_ispcpu_gic_pll : 4;
        unsigned int sel_ispcpu_periph_pll : 4;
        unsigned int sel_ispcpu_periph_core_pll : 4;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV4_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_gic_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_gic_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_periph_pll_START (4)
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_periph_pll_END (7)
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_periph_core_pll_START (8)
#define SOC_MEDIA2_CRG_CLKDIV4_sel_ispcpu_periph_core_pll_END (11)
#define SOC_MEDIA2_CRG_CLKDIV4_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV4_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sel_ispcpu_djtag_pll : 4;
        unsigned int reserved_0 : 4;
        unsigned int sel_ispcpu_dldo_pll : 4;
        unsigned int reserved_1 : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV5_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV5_sel_ispcpu_djtag_pll_START (0)
#define SOC_MEDIA2_CRG_CLKDIV5_sel_ispcpu_djtag_pll_END (3)
#define SOC_MEDIA2_CRG_CLKDIV5_sel_ispcpu_dldo_pll_START (8)
#define SOC_MEDIA2_CRG_CLKDIV5_sel_ispcpu_dldo_pll_END (11)
#define SOC_MEDIA2_CRG_CLKDIV5_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV5_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_clk_isp_srt : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_clk_isp_rt : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV6_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV6_div_clk_isp_srt_START (0)
#define SOC_MEDIA2_CRG_CLKDIV6_div_clk_isp_srt_END (5)
#define SOC_MEDIA2_CRG_CLKDIV6_div_clk_isp_rt_START (8)
#define SOC_MEDIA2_CRG_CLKDIV6_div_clk_isp_rt_END (13)
#define SOC_MEDIA2_CRG_CLKDIV6_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV6_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_qic_m2 : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_miniisp : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV7_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV7_div_qic_m2_START (0)
#define SOC_MEDIA2_CRG_CLKDIV7_div_qic_m2_END (5)
#define SOC_MEDIA2_CRG_CLKDIV7_div_miniisp_START (8)
#define SOC_MEDIA2_CRG_CLKDIV7_div_miniisp_END (13)
#define SOC_MEDIA2_CRG_CLKDIV7_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV7_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_clk_idi2axi_csid : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_isp_i3c : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV8_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV8_div_clk_idi2axi_csid_START (0)
#define SOC_MEDIA2_CRG_CLKDIV8_div_clk_idi2axi_csid_END (5)
#define SOC_MEDIA2_CRG_CLKDIV8_div_isp_i3c_START (8)
#define SOC_MEDIA2_CRG_CLKDIV8_div_isp_i3c_END (13)
#define SOC_MEDIA2_CRG_CLKDIV8_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV8_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_isp_spi : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_isp_oisp : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV9_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV9_div_isp_spi_START (0)
#define SOC_MEDIA2_CRG_CLKDIV9_div_isp_spi_END (5)
#define SOC_MEDIA2_CRG_CLKDIV9_div_isp_oisp_START (8)
#define SOC_MEDIA2_CRG_CLKDIV9_div_isp_oisp_END (13)
#define SOC_MEDIA2_CRG_CLKDIV9_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV9_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_clk_isp_nrt : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_clk_isp_cpu : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV10_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV10_div_clk_isp_nrt_START (0)
#define SOC_MEDIA2_CRG_CLKDIV10_div_clk_isp_nrt_END (5)
#define SOC_MEDIA2_CRG_CLKDIV10_div_clk_isp_cpu_START (8)
#define SOC_MEDIA2_CRG_CLKDIV10_div_clk_isp_cpu_END (13)
#define SOC_MEDIA2_CRG_CLKDIV10_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV10_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_csi_idi : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_isp_top : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV11_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV11_div_csi_idi_START (0)
#define SOC_MEDIA2_CRG_CLKDIV11_div_csi_idi_END (5)
#define SOC_MEDIA2_CRG_CLKDIV11_div_isp_top_START (8)
#define SOC_MEDIA2_CRG_CLKDIV11_div_isp_top_END (13)
#define SOC_MEDIA2_CRG_CLKDIV11_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV11_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_hpm : 6;
        unsigned int reserved_0: 2;
        unsigned int div_ipp : 6;
        unsigned int reserved_1: 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV12_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV12_div_hpm_START (0)
#define SOC_MEDIA2_CRG_CLKDIV12_div_hpm_END (5)
#define SOC_MEDIA2_CRG_CLKDIV12_div_ipp_START (8)
#define SOC_MEDIA2_CRG_CLKDIV12_div_ipp_END (13)
#define SOC_MEDIA2_CRG_CLKDIV12_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV12_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ispcpu_periph : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_ispcpu_gic : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV13_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV13_div_ispcpu_periph_START (0)
#define SOC_MEDIA2_CRG_CLKDIV13_div_ispcpu_periph_END (5)
#define SOC_MEDIA2_CRG_CLKDIV13_div_ispcpu_gic_START (8)
#define SOC_MEDIA2_CRG_CLKDIV13_div_ispcpu_gic_END (13)
#define SOC_MEDIA2_CRG_CLKDIV13_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV13_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ispcpu_periph_core : 6;
        unsigned int reserved_0 : 2;
        unsigned int div_ispcpu_djtag : 6;
        unsigned int reserved_1 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV14_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV14_div_ispcpu_periph_core_START (0)
#define SOC_MEDIA2_CRG_CLKDIV14_div_ispcpu_periph_core_END (5)
#define SOC_MEDIA2_CRG_CLKDIV14_div_ispcpu_djtag_START (8)
#define SOC_MEDIA2_CRG_CLKDIV14_div_ispcpu_djtag_END (13)
#define SOC_MEDIA2_CRG_CLKDIV14_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV14_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int div_ispcpu_dldo : 6;
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 2;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV15_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV15_div_ispcpu_dldo_START (0)
#define SOC_MEDIA2_CRG_CLKDIV15_div_ispcpu_dldo_END (5)
#define SOC_MEDIA2_CRG_CLKDIV15_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV15_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_csi_idi : 1;
        unsigned int sc_gt_clk_i3c : 1;
        unsigned int sc_gt_clk_hpm : 1;
        unsigned int sc_gt_clk_miniisp : 1;
        unsigned int sc_gt_clk_isp_cpu : 1;
        unsigned int sc_gt_clk_qic_m2 : 1;
        unsigned int sc_gt_clk_isp_srt : 1;
        unsigned int sc_gt_clk_isp_nrt : 1;
        unsigned int sc_gt_clk_isp_rt : 1;
        unsigned int sc_gt_clk_idi2axi_csid : 1;
        unsigned int sc_gt_clk_isp_spi : 1;
        unsigned int sc_gt_clk_isp_top : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV16_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_csi_idi_START (0)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_csi_idi_END (0)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_i3c_START (1)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_i3c_END (1)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_hpm_START (2)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_hpm_END (2)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_miniisp_START (3)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_miniisp_END (3)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_cpu_START (4)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_cpu_END (4)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_qic_m2_START (5)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_qic_m2_END (5)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_srt_START (6)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_srt_END (6)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_nrt_START (7)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_nrt_END (7)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_rt_START (8)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_rt_END (8)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_idi2axi_csid_START (9)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_idi2axi_csid_END (9)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_spi_START (10)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_spi_END (10)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_top_START (11)
#define SOC_MEDIA2_CRG_CLKDIV16_sc_gt_clk_isp_top_END (11)
#define SOC_MEDIA2_CRG_CLKDIV16_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV16_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sc_gt_clk_isp_oisp : 1;
        unsigned int sc_gt_clk_ipp : 1;
        unsigned int sc_gt_clk_ispcpu_gic : 1;
        unsigned int sc_gt_clk_ispcpu_periph : 1;
        unsigned int sc_gt_clk_ispcpu_periph_core : 1;
        unsigned int sc_gt_clk_ispcpu_djtag : 1;
        unsigned int sc_gt_clk_ispcpu_dldo : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 8;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV17_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_isp_oisp_START (0)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_isp_oisp_END (0)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ipp_START (1)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ipp_END (1)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_gic_START (2)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_gic_END (2)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_periph_START (3)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_periph_END (3)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_periph_core_START (4)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_periph_core_END (4)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_djtag_START (5)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_djtag_END (5)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_dldo_START (6)
#define SOC_MEDIA2_CRG_CLKDIV17_sc_gt_clk_ispcpu_dldo_END (6)
#define SOC_MEDIA2_CRG_CLKDIV17_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV17_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdbat_drop_freq_down_isp_cpu_bypass : 1;
        unsigned int div_isp_cpu_vbat_drop_freq_down : 5;
        unsigned int vdbat_drop_freq_down_isp_srt_bypass : 1;
        unsigned int div_isp_srt_vbat_drop_freq_down : 5;
        unsigned int reserved : 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV18_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV18_vdbat_drop_freq_down_isp_cpu_bypass_START (0)
#define SOC_MEDIA2_CRG_CLKDIV18_vdbat_drop_freq_down_isp_cpu_bypass_END (0)
#define SOC_MEDIA2_CRG_CLKDIV18_div_isp_cpu_vbat_drop_freq_down_START (1)
#define SOC_MEDIA2_CRG_CLKDIV18_div_isp_cpu_vbat_drop_freq_down_END (5)
#define SOC_MEDIA2_CRG_CLKDIV18_vdbat_drop_freq_down_isp_srt_bypass_START (6)
#define SOC_MEDIA2_CRG_CLKDIV18_vdbat_drop_freq_down_isp_srt_bypass_END (6)
#define SOC_MEDIA2_CRG_CLKDIV18_div_isp_srt_vbat_drop_freq_down_START (7)
#define SOC_MEDIA2_CRG_CLKDIV18_div_isp_srt_vbat_drop_freq_down_END (11)
#define SOC_MEDIA2_CRG_CLKDIV18_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV18_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vdbat_drop_freq_down_isp_nrt_bypass : 1;
        unsigned int div_isp_nrt_vbat_drop_freq_down : 5;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 6;
        unsigned int reserved_2 : 3;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_CLKDIV19_UNION;
#endif
#define SOC_MEDIA2_CRG_CLKDIV19_vdbat_drop_freq_down_isp_nrt_bypass_START (0)
#define SOC_MEDIA2_CRG_CLKDIV19_vdbat_drop_freq_down_isp_nrt_bypass_END (0)
#define SOC_MEDIA2_CRG_CLKDIV19_div_isp_nrt_vbat_drop_freq_down_START (1)
#define SOC_MEDIA2_CRG_CLKDIV19_div_isp_nrt_vbat_drop_freq_down_END (5)
#define SOC_MEDIA2_CRG_CLKDIV19_bitmasken_START (16)
#define SOC_MEDIA2_CRG_CLKDIV19_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int swdone_clk_hpm_div : 1;
        unsigned int swdone_clk_isp_spi_div : 1;
        unsigned int swdone_clk_isp_top_div : 1;
        unsigned int swdone_clk_csi_idi_div : 1;
        unsigned int swdone_clk_isp_i3c_div : 1;
        unsigned int swdone_clk_idi2axi_csid_div : 1;
        unsigned int swdone_clk_miniisp_div : 1;
        unsigned int swdone_clk_qic_m2_data_div : 1;
        unsigned int swdone_clk_isp_cpu_div : 1;
        unsigned int swdone_clk_isp_rt_div : 1;
        unsigned int swdone_clk_isp_srt_div : 1;
        unsigned int swdone_clk_isp_nrt_div : 1;
        unsigned int swdone_clk_isp_oisp : 1;
        unsigned int swdone_clk_ipp : 1;
        unsigned int swdone_clk_ispcpu_gic : 1;
        unsigned int swdone_clk_ispcpu_periph : 1;
        unsigned int swdone_clk_ispcpu_periph_core : 1;
        unsigned int swdone_clk_ispcpu_djtag : 1;
        unsigned int reserved_0 : 1;
        unsigned int swdone_clk_ispcpu_dldo : 1;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_MEDIA2_CRG_PERI_STAT0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_hpm_div_START (0)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_hpm_div_END (0)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_spi_div_START (1)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_spi_div_END (1)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_top_div_START (2)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_top_div_END (2)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_csi_idi_div_START (3)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_csi_idi_div_END (3)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_i3c_div_START (4)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_i3c_div_END (4)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_idi2axi_csid_div_START (5)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_idi2axi_csid_div_END (5)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_miniisp_div_START (6)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_miniisp_div_END (6)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_qic_m2_data_div_START (7)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_qic_m2_data_div_END (7)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_cpu_div_START (8)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_cpu_div_END (8)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_rt_div_START (9)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_rt_div_END (9)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_srt_div_START (10)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_srt_div_END (10)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_nrt_div_START (11)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_nrt_div_END (11)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_oisp_START (12)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_isp_oisp_END (12)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ipp_START (13)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ipp_END (13)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_gic_START (14)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_gic_END (14)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_periph_START (15)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_periph_END (15)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_periph_core_START (16)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_periph_core_END (16)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_djtag_START (17)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_djtag_END (17)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_dldo_START (19)
#define SOC_MEDIA2_CRG_PERI_STAT0_swdone_clk_ispcpu_dldo_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ack_clk_qic_m2_data_sw : 4;
        unsigned int sw_ack_clk_idi2axi_csid_sw : 4;
        unsigned int sw_ack_clk_csi_idi_sw : 4;
        unsigned int sw_ack_clk_miniisp_sw : 4;
        unsigned int sw_ack_clk_isp_cpu_sw : 4;
        unsigned int sw_ack_clk_isp_rt_sw : 4;
        unsigned int sw_ack_clk_isp_srt_sw : 4;
        unsigned int sw_ack_clk_isp_nrt_sw : 4;
    } reg;
} SOC_MEDIA2_CRG_PERI_STAT1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_qic_m2_data_sw_START (0)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_qic_m2_data_sw_END (3)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_idi2axi_csid_sw_START (4)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_idi2axi_csid_sw_END (7)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_csi_idi_sw_START (8)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_csi_idi_sw_END (11)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_miniisp_sw_START (12)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_miniisp_sw_END (15)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_cpu_sw_START (16)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_cpu_sw_END (19)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_rt_sw_START (20)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_rt_sw_END (23)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_srt_sw_START (24)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_srt_sw_END (27)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_nrt_sw_START (28)
#define SOC_MEDIA2_CRG_PERI_STAT1_sw_ack_clk_isp_nrt_sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ack_clk_hpm_sw : 4;
        unsigned int sw_ack_clk_isp_oisp_sw : 4;
        unsigned int sw_ack_clk_ipp_sw : 4;
        unsigned int sw_ack_clk_ispcpu_gic_sw : 4;
        unsigned int sw_ack_clk_ispcpu_periph_sw : 4;
        unsigned int sw_ack_clk_ispcpu_periph_core_sw : 4;
        unsigned int sw_ack_clk_ispcpu_djtag_sw : 4;
        unsigned int sw_ack_clk_ispcpu_4sw : 4;
    } reg;
} SOC_MEDIA2_CRG_PERI_STAT2_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_hpm_sw_START (0)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_hpm_sw_END (3)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_isp_oisp_sw_START (4)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_isp_oisp_sw_END (7)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ipp_sw_START (8)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ipp_sw_END (11)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_gic_sw_START (12)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_gic_sw_END (15)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_periph_sw_START (16)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_periph_sw_END (19)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_periph_core_sw_START (20)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_periph_core_sw_END (23)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_djtag_sw_START (24)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_djtag_sw_END (27)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_4sw_START (28)
#define SOC_MEDIA2_CRG_PERI_STAT2_sw_ack_clk_ispcpu_4sw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_ack_clk_ispcpu_dldo_sw : 4;
        unsigned int sw_ack_clk_isp_top_sw : 4;
        unsigned int sw_ack_clk_isp_srt_2sw : 2;
        unsigned int sw_ack_clk_isp_nrt_2sw : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_MEDIA2_CRG_PERI_STAT3_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_ispcpu_dldo_sw_START (0)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_ispcpu_dldo_sw_END (3)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_top_sw_START (4)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_top_sw_END (7)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_srt_2sw_START (8)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_srt_2sw_END (9)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_nrt_2sw_START (10)
#define SOC_MEDIA2_CRG_PERI_STAT3_sw_ack_clk_isp_nrt_2sw_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 2;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 2;
        unsigned int reserved_8: 4;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_ISPCPU_CLKEN_UNION;
#endif
#define SOC_MEDIA2_CRG_ISPCPU_CLKEN_bitmasken_START (16)
#define SOC_MEDIA2_CRG_ISPCPU_CLKEN_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 2;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 18;
    } reg;
} SOC_MEDIA2_CRG_ISPCPU_RSTEN_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 2;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 18;
    } reg;
} SOC_MEDIA2_CRG_ISPCPU_RSTDIS_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 2;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 18;
    } reg;
} SOC_MEDIA2_CRG_ISPCPU_RSTSTAT_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int c0_sys_halt_r : 1;
        unsigned int c0_sys_sleep_r : 1;
        unsigned int c1_sys_halt_r : 1;
        unsigned int c1_sys_sleep_r : 1;
        unsigned int c0_sys_tf_halt_r : 1;
        unsigned int c0_sys_sleep_mode : 3;
        unsigned int c1_sys_tf_halt_r : 1;
        unsigned int c1_sys_sleep_mode : 3;
        unsigned int c0_arc_halt_ack : 1;
        unsigned int c0_arc_run_ack : 1;
        unsigned int c1_arc_halt_ack : 1;
        unsigned int c1_arc_run_ack : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_MEDIA2_CRG_ISP_CPU_STATE0_UNION;
#endif
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_halt_r_START (0)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_halt_r_END (0)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_sleep_r_START (1)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_sleep_r_END (1)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_halt_r_START (2)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_halt_r_END (2)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_sleep_r_START (3)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_sleep_r_END (3)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_tf_halt_r_START (4)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_tf_halt_r_END (4)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_sleep_mode_START (5)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_sys_sleep_mode_END (7)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_tf_halt_r_START (8)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_tf_halt_r_END (8)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_sleep_mode_START (9)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_sys_sleep_mode_END (11)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_arc_halt_ack_START (12)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_arc_halt_ack_END (12)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_arc_run_ack_START (13)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c0_arc_run_ack_END (13)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_arc_halt_ack_START (14)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_arc_halt_ack_END (14)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_arc_run_ack_START (15)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE0_c1_arc_run_ack_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_cpu_state1 : 32;
    } reg;
} SOC_MEDIA2_CRG_ISP_CPU_STATE1_UNION;
#endif
#define SOC_MEDIA2_CRG_ISP_CPU_STATE1_isp_cpu_state1_START (0)
#define SOC_MEDIA2_CRG_ISP_CPU_STATE1_isp_cpu_state1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_m2_div_auto_reduce_bypass : 1;
        unsigned int qic_m2_auto_waitcfg_in : 10;
        unsigned int qic_m2_auto_waitcfg_out : 10;
        unsigned int qic_m2_div_auto_cfg : 6;
        unsigned int reserved : 5;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV0_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_div_auto_reduce_bypass_START (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_div_auto_reduce_bypass_END (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_auto_waitcfg_in_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_auto_waitcfg_in_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_auto_waitcfg_out_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_auto_waitcfg_out_END (20)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_div_auto_cfg_START (21)
#define SOC_MEDIA2_CRG_PERI_AUTODIV0_qic_m2_div_auto_cfg_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isp_idle_flag_bypass : 1;
        unsigned int tcu_idle_flag_bypass : 1;
        unsigned int idi2axi_idle_flag_bypass : 1;
        unsigned int perf_idle_isp_0_bypass : 1;
        unsigned int perf_idle_isp_1_bypass : 1;
        unsigned int perf_idle_isp_2_bypass : 1;
        unsigned int perf_idle_isp_3_bypass : 1;
        unsigned int perf_idle_isp_4_bypass : 1;
        unsigned int perf_idle_isp_5_bypass : 1;
        unsigned int perf_idle_isp_6_bypass : 1;
        unsigned int perf_idle_tcu_bypass : 1;
        unsigned int perf_idle_ibqe_bypass : 1;
        unsigned int qice_bus_media2_nopending_comb_bypass : 1;
        unsigned int perf_idle_miniisp_bypass : 1;
        unsigned int perf_idle_idi2axi_bypass : 1;
        unsigned int isp_cpu_idle_flag_bypass : 1;
        unsigned int isp_subsys_qic_nopending_bypass : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV1_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_idle_flag_bypass_START (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_idle_flag_bypass_END (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_tcu_idle_flag_bypass_START (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_tcu_idle_flag_bypass_END (1)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_idi2axi_idle_flag_bypass_START (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_idi2axi_idle_flag_bypass_END (2)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_0_bypass_START (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_0_bypass_END (3)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_1_bypass_START (4)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_1_bypass_END (4)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_2_bypass_START (5)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_2_bypass_END (5)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_3_bypass_START (6)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_3_bypass_END (6)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_4_bypass_START (7)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_4_bypass_END (7)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_5_bypass_START (8)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_5_bypass_END (8)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_6_bypass_START (9)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_isp_6_bypass_END (9)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_tcu_bypass_START (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_tcu_bypass_END (10)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_ibqe_bypass_START (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_ibqe_bypass_END (11)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_qice_bus_media2_nopending_comb_bypass_START (12)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_qice_bus_media2_nopending_comb_bypass_END (12)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_miniisp_bypass_START (13)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_miniisp_bypass_END (13)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_idi2axi_bypass_START (14)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_perf_idle_idi2axi_bypass_END (14)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_cpu_idle_flag_bypass_START (15)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_cpu_idle_flag_bypass_END (15)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_subsys_qic_nopending_bypass_START (16)
#define SOC_MEDIA2_CRG_PERI_AUTODIV1_isp_subsys_qic_nopending_bypass_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp0_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP0_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP0_BYPASS_qic_bus_isp_nopending_grp0_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP0_BYPASS_qic_bus_isp_nopending_grp0_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp1_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP1_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP1_BYPASS_qic_bus_isp_nopending_grp1_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP1_BYPASS_qic_bus_isp_nopending_grp1_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp2_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP2_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP2_BYPASS_qic_bus_isp_nopending_grp2_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP2_BYPASS_qic_bus_isp_nopending_grp2_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp3_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP3_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP3_BYPASS_qic_bus_isp_nopending_grp3_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP3_BYPASS_qic_bus_isp_nopending_grp3_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp4_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP4_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP4_BYPASS_qic_bus_isp_nopending_grp4_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP4_BYPASS_qic_bus_isp_nopending_grp4_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp5_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP5_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP5_BYPASS_qic_bus_isp_nopending_grp5_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP5_BYPASS_qic_bus_isp_nopending_grp5_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_isp_nopending_grp6_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP6_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP6_BYPASS_qic_bus_isp_nopending_grp6_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_ISP_NOPENDING_GRP6_BYPASS_qic_bus_isp_nopending_grp6_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media2_nopending_grp0_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP0_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP0_BYPASS_qic_bus_media2_nopending_grp0_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP0_BYPASS_qic_bus_media2_nopending_grp0_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media2_nopending_grp1_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP1_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP1_BYPASS_qic_bus_media2_nopending_grp1_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP1_BYPASS_qic_bus_media2_nopending_grp1_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qic_bus_media2_nopending_grp2_bypass : 32;
    } reg;
} SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP2_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP2_BYPASS_qic_bus_media2_nopending_grp2_bypass_START (0)
#define SOC_MEDIA2_CRG_QIC_BUS_MEDIA2_NOPENDING_GRP2_BYPASS_qic_bus_media2_nopending_grp2_bypass_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vbat_drop_freq_down_isp_cpu_stat : 1;
        unsigned int vbat_drop_freq_down_isp_nrt_stat : 1;
        unsigned int vbat_drop_freq_down_isp_srt_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 23;
    } reg;
} SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_UNION;
#endif
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_cpu_stat_START (0)
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_cpu_stat_END (0)
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_nrt_stat_START (1)
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_nrt_stat_END (1)
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_srt_stat_START (2)
#define SOC_MEDIA2_CRG_MEDIA_AUTODIV_STAT_vbat_drop_freq_down_isp_srt_stat_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int isptomed_reserve_stat : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_MEDIA2_CRG_ISPTOMED_RESERVE_OUT_UNION;
#endif
#define SOC_MEDIA2_CRG_ISPTOMED_RESERVE_OUT_isptomed_reserve_stat_START (0)
#define SOC_MEDIA2_CRG_ISPTOMED_RESERVE_OUT_isptomed_reserve_stat_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int autodiv_qic_m2_stat : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 27;
    } reg;
} SOC_MEDIA2_CRG_PERI_AUTODIV_STAT_UNION;
#endif
#define SOC_MEDIA2_CRG_PERI_AUTODIV_STAT_autodiv_qic_m2_stat_START (0)
#define SOC_MEDIA2_CRG_PERI_AUTODIV_STAT_autodiv_qic_m2_stat_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_clr_media2bus_nonidle_pend : 1;
        unsigned int intr_mask_media2_nonidle_pend : 1;
        unsigned int intr_mask_ibqe_nonidle_pend : 1;
        unsigned int intr_mask_ispbus_nonidle_pend : 1;
        unsigned int intr_mask_idi2axi_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 7;
        unsigned int bitmasken : 16;
    } reg;
} SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_clr_media2bus_nonidle_pend_START (0)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_clr_media2bus_nonidle_pend_END (0)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_media2_nonidle_pend_START (1)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_media2_nonidle_pend_END (1)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_ibqe_nonidle_pend_START (2)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_ibqe_nonidle_pend_END (2)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_ispbus_nonidle_pend_START (3)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_ispbus_nonidle_pend_END (3)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_idi2axi_nonidle_pend_START (4)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_intr_mask_idi2axi_nonidle_pend_END (4)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_bitmasken_START (16)
#define SOC_MEDIA2_CRG_INTR_BUS_NONIDLE_PEND_bitmasken_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int intr_stat_vcodecbus_nonidle_pend : 1;
        unsigned int intr_stat_ibqe_nonidle_pend : 1;
        unsigned int intr_stat_ispbus_nonidle_pend : 1;
        unsigned int intr_stat_idi2axi_nonidle_pend : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 8;
        unsigned int reserved_5 : 16;
    } reg;
} SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_UNION;
#endif
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_vcodecbus_nonidle_pend_START (0)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_vcodecbus_nonidle_pend_END (0)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_ibqe_nonidle_pend_START (1)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_ibqe_nonidle_pend_END (1)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_ispbus_nonidle_pend_START (2)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_ispbus_nonidle_pend_END (2)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_idi2axi_nonidle_pend_START (3)
#define SOC_MEDIA2_CRG_INTR_STAT_BUS_NONIDLE_PEND_intr_stat_idi2axi_nonidle_pend_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int tcu_cfg_clkrst_bypass : 1;
        unsigned int csi_wrapper_cfg_clkrst_bypass : 1;
        unsigned int idi2axi_cfg_clkrst_bypass : 1;
        unsigned int miniisp_cfg_clkrst_bypass : 1;
        unsigned int p2j_clkrst_bypass : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_MEDIA2_CRG_IPCLKRST_BYPASS_UNION;
#endif
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_tcu_cfg_clkrst_bypass_START (0)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_tcu_cfg_clkrst_bypass_END (0)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_csi_wrapper_cfg_clkrst_bypass_START (1)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_csi_wrapper_cfg_clkrst_bypass_END (1)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_idi2axi_cfg_clkrst_bypass_START (2)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_idi2axi_cfg_clkrst_bypass_END (2)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_miniisp_cfg_clkrst_bypass_START (3)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_miniisp_cfg_clkrst_bypass_END (3)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_p2j_clkrst_bypass_START (4)
#define SOC_MEDIA2_CRG_IPCLKRST_BYPASS_p2j_clkrst_bypass_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_en : 1;
        unsigned int hpm_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hpm_clk_div : 7;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPM_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_en_START (0)
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_en_END (0)
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_opc_min_en_END (1)
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_clk_div_START (4)
#define SOC_MEDIA2_CRG_HPM_CFG_hpm_clk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm_opc_vld : 1;
        unsigned int hpm_opc : 10;
        unsigned int hpm_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPM_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_START (1)
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_END (10)
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPM_READ_BACK_hpm_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx_en : 1;
        unsigned int hpmx_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPMX_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX_CFG_hpmx_en_START (0)
#define SOC_MEDIA2_CRG_HPMX_CFG_hpmx_en_END (0)
#define SOC_MEDIA2_CRG_HPMX_CFG_hpmx_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPMX_CFG_hpmx_opc_min_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx_opc_vld : 1;
        unsigned int hpmx_opc : 10;
        unsigned int hpmx_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPMX_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_START (1)
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_END (10)
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPMX_READ_BACK_hpmx_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm0_en : 1;
        unsigned int hpm0_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hpm0_clk_div : 7;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPM0_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_en_START (0)
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_en_END (0)
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_opc_min_en_END (1)
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_clk_div_START (4)
#define SOC_MEDIA2_CRG_HPM0_CFG_hpm0_clk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm0_opc_vld : 1;
        unsigned int hpm0_opc : 10;
        unsigned int hpm0_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPM0_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_START (1)
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_END (10)
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPM0_READ_BACK_hpm0_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx0_en : 1;
        unsigned int hpmx0_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPMX0_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX0_CFG_hpmx0_en_START (0)
#define SOC_MEDIA2_CRG_HPMX0_CFG_hpmx0_en_END (0)
#define SOC_MEDIA2_CRG_HPMX0_CFG_hpmx0_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPMX0_CFG_hpmx0_opc_min_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx0_opc_vld : 1;
        unsigned int hpmx0_opc : 10;
        unsigned int hpmx0_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPMX0_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_START (1)
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_END (10)
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPMX0_READ_BACK_hpmx0_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm1_en : 1;
        unsigned int hpm1_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int hpm1_clk_div : 7;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPM1_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_en_START (0)
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_en_END (0)
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_opc_min_en_END (1)
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_clk_div_START (4)
#define SOC_MEDIA2_CRG_HPM1_CFG_hpm1_clk_div_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpm1_opc_vld : 1;
        unsigned int hpm1_opc : 10;
        unsigned int hpm1_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPM1_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_START (1)
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_END (10)
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPM1_READ_BACK_hpm1_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx1_en : 1;
        unsigned int hpmx1_opc_min_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 12;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_MEDIA2_CRG_HPMX1_CFG_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX1_CFG_hpmx1_en_START (0)
#define SOC_MEDIA2_CRG_HPMX1_CFG_hpmx1_en_END (0)
#define SOC_MEDIA2_CRG_HPMX1_CFG_hpmx1_opc_min_en_START (1)
#define SOC_MEDIA2_CRG_HPMX1_CFG_hpmx1_opc_min_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hpmx1_opc_vld : 1;
        unsigned int hpmx1_opc : 10;
        unsigned int hpmx1_opc_min : 10;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_MEDIA2_CRG_HPMX1_READ_BACK_UNION;
#endif
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_vld_START (0)
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_vld_END (0)
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_START (1)
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_END (10)
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_min_START (11)
#define SOC_MEDIA2_CRG_HPMX1_READ_BACK_hpmx1_opc_min_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 4;
        unsigned int reserved_1 : 10;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 4;
        unsigned int reserved_4 : 4;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 4;
        unsigned int isp_himinibus_tcmdma_sport_2to1_dlock_slv : 2;
    } reg;
} SOC_MEDIA2_CRG_ISP_READ_BACK0_UNION;
#endif
#define SOC_MEDIA2_CRG_ISP_READ_BACK0_isp_himinibus_tcmdma_sport_2to1_dlock_slv_START (30)
#define SOC_MEDIA2_CRG_ISP_READ_BACK0_isp_himinibus_tcmdma_sport_2to1_dlock_slv_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 4;
        unsigned int reserved_1: 4;
        unsigned int reserved_2: 8;
        unsigned int reserved_3: 16;
    } reg;
} SOC_MEDIA2_CRG_ISP_READ_BACK1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 5;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 4;
        unsigned int reserved_9: 16;
    } reg;
} SOC_MEDIA2_CRG_ISP_HIMINIBUS_CTRL_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_miniisp : 1;
        unsigned int ip_rst_idi2axi_csid : 1;
        unsigned int ip_rst_fp_idi : 1;
        unsigned int ip_rst_miniisp_cfg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_miniisp_START (0)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_miniisp_END (0)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_idi2axi_csid_START (1)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_idi2axi_csid_END (1)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_fp_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_fp_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_miniisp_cfg_START (3)
#define SOC_MEDIA2_CRG_PERRSTEN_GENERAL_SEC_ip_rst_miniisp_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_miniisp : 1;
        unsigned int ip_rst_idi2axi_csid : 1;
        unsigned int ip_rst_fp_idi : 1;
        unsigned int ip_rst_miniisp_cfg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_miniisp_START (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_miniisp_END (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_idi2axi_csid_START (1)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_idi2axi_csid_END (1)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_fp_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_fp_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_miniisp_cfg_START (3)
#define SOC_MEDIA2_CRG_PERRSTDIS_GENERAL_SEC_ip_rst_miniisp_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_miniisp : 1;
        unsigned int ip_rst_idi2axi_csid : 1;
        unsigned int ip_rst_fp_idi : 1;
        unsigned int ip_rst_miniisp_cfg : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_miniisp_START (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_miniisp_END (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_idi2axi_csid_START (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_idi2axi_csid_END (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_fp_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_fp_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_miniisp_cfg_START (3)
#define SOC_MEDIA2_CRG_PERRSTSTAT_GENERAL_SEC_ip_rst_miniisp_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_idi2axi_csid : 1;
        unsigned int gt_clk_fp_idi : 1;
        unsigned int gt_clk_miniisp : 1;
        unsigned int gt_pclk_miniisp : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_idi2axi_csid_START (0)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_idi2axi_csid_END (0)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_fp_idi_START (1)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_fp_idi_END (1)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_miniisp_START (2)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_clk_miniisp_END (2)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_pclk_miniisp_START (3)
#define SOC_MEDIA2_CRG_PEREN0_GENERAL_SEC_gt_pclk_miniisp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_idi2axi_csid : 1;
        unsigned int gt_clk_fp_idi : 1;
        unsigned int gt_clk_miniisp : 1;
        unsigned int gt_pclk_miniisp : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_idi2axi_csid_START (0)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_idi2axi_csid_END (0)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_fp_idi_START (1)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_fp_idi_END (1)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_miniisp_START (2)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_clk_miniisp_END (2)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_pclk_miniisp_START (3)
#define SOC_MEDIA2_CRG_PERDIS0_GENERAL_SEC_gt_pclk_miniisp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gt_clk_idi2axi_csid : 1;
        unsigned int gt_clk_fp_idi : 1;
        unsigned int gt_clk_miniisp : 1;
        unsigned int gt_pclk_miniisp : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_idi2axi_csid_START (0)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_idi2axi_csid_END (0)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_fp_idi_START (1)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_fp_idi_END (1)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_miniisp_START (2)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_clk_miniisp_END (2)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_pclk_miniisp_START (3)
#define SOC_MEDIA2_CRG_PERCLKEN0_GENERAL_SEC_gt_pclk_miniisp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int st_clk_idi2axi_csid : 1;
        unsigned int st_clk_fp_idi : 1;
        unsigned int st_clk_miniisp : 1;
        unsigned int st_pclk_miniisp : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_idi2axi_csid_START (0)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_idi2axi_csid_END (0)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_fp_idi_START (1)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_fp_idi_END (1)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_miniisp_START (2)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_clk_miniisp_END (2)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_pclk_miniisp_START (3)
#define SOC_MEDIA2_CRG_PERSTAT0_GENERAL_SEC_st_pclk_miniisp_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp_top : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_csi_idi : 1;
        unsigned int ip_rst_isp_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_isp : 1;
        unsigned int ip_rst_isp_oisp : 1;
        unsigned int ip_rst_isp_i3c : 1;
        unsigned int ip_rst_csi_wrapper_cfg : 1;
        unsigned int ip_rst_isp_spi : 1;
        unsigned int ip_rst_ipp : 1;
        unsigned int ip_rst_raw_ispcpu_core : 1;
        unsigned int ip_rst_raw_ispcpu_other : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ispcpu_periph : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ispcpu_dldo : 1;
        unsigned int ip_rst_isp_dbg_cs : 1;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_top_START (0)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_top_END (0)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_qice_START (3)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_qice_END (3)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_prst_isp_START (5)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_prst_isp_END (5)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_oisp_START (6)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_oisp_END (6)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_i3c_START (7)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_i3c_END (7)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_spi_START (9)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_spi_END (9)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ipp_START (10)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ipp_END (10)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_raw_ispcpu_core_START (11)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_raw_ispcpu_core_END (11)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_raw_ispcpu_other_START (12)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_raw_ispcpu_other_END (12)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ispcpu_periph_START (14)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ispcpu_periph_END (14)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ispcpu_dldo_START (16)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_ispcpu_dldo_END (16)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_dbg_cs_START (17)
#define SOC_MEDIA2_CRG_PERRSTEN_ISP_SEC_ip_rst_isp_dbg_cs_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp_top : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_csi_idi : 1;
        unsigned int ip_rst_isp_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_isp : 1;
        unsigned int ip_rst_isp_oisp : 1;
        unsigned int ip_rst_isp_i3c : 1;
        unsigned int ip_rst_csi_wrapper_cfg : 1;
        unsigned int ip_rst_isp_spi : 1;
        unsigned int ip_rst_ipp : 1;
        unsigned int ip_rst_raw_ispcpu_core : 1;
        unsigned int ip_rst_raw_ispcpu_other : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ispcpu_periph : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ispcpu_dldo : 1;
        unsigned int ip_rst_isp_dbg_cs : 1;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_top_START (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_top_END (0)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_qice_START (3)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_qice_END (3)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_prst_isp_START (5)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_prst_isp_END (5)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_oisp_START (6)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_oisp_END (6)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_i3c_START (7)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_i3c_END (7)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_spi_START (9)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_spi_END (9)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ipp_START (10)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ipp_END (10)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_raw_ispcpu_core_START (11)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_raw_ispcpu_core_END (11)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_raw_ispcpu_other_START (12)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_raw_ispcpu_other_END (12)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ispcpu_periph_START (14)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ispcpu_periph_END (14)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ispcpu_dldo_START (16)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_ispcpu_dldo_END (16)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_dbg_cs_START (17)
#define SOC_MEDIA2_CRG_PERRSTDIS_ISP_SEC_ip_rst_isp_dbg_cs_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_rst_isp_top : 1;
        unsigned int ip_arst_isp : 1;
        unsigned int ip_rst_csi_idi : 1;
        unsigned int ip_rst_isp_qice : 1;
        unsigned int reserved_0 : 1;
        unsigned int ip_prst_isp : 1;
        unsigned int ip_rst_isp_oisp : 1;
        unsigned int ip_rst_isp_i3c : 1;
        unsigned int ip_rst_csi_wrapper_cfg : 1;
        unsigned int ip_rst_isp_spi : 1;
        unsigned int ip_rst_ipp : 1;
        unsigned int ip_rst_raw_ispcpu_core : 1;
        unsigned int ip_rst_raw_ispcpu_other : 1;
        unsigned int reserved_1 : 1;
        unsigned int ip_rst_ispcpu_periph : 1;
        unsigned int reserved_2 : 1;
        unsigned int ip_rst_ispcpu_dldo : 1;
        unsigned int ip_rst_isp_dbg_cs : 1;
        unsigned int reserved_3 : 14;
    } reg;
} SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_top_START (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_top_END (0)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_arst_isp_START (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_arst_isp_END (1)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_csi_idi_START (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_csi_idi_END (2)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_qice_START (3)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_qice_END (3)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_prst_isp_START (5)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_prst_isp_END (5)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_oisp_START (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_oisp_END (6)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_i3c_START (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_i3c_END (7)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_csi_wrapper_cfg_START (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_csi_wrapper_cfg_END (8)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_spi_START (9)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_spi_END (9)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ipp_START (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ipp_END (10)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_raw_ispcpu_core_START (11)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_raw_ispcpu_core_END (11)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_raw_ispcpu_other_START (12)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_raw_ispcpu_other_END (12)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ispcpu_periph_START (14)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ispcpu_periph_END (14)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ispcpu_dldo_START (16)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_ispcpu_dldo_END (16)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_dbg_cs_START (17)
#define SOC_MEDIA2_CRG_PERRSTSTAT_ISP_SEC_ip_rst_isp_dbg_cs_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int c0_arc_event_a : 1;
        unsigned int c1_arc_event_a : 1;
        unsigned int c0_arc_halt_req : 1;
        unsigned int c0_arc_run_req : 1;
        unsigned int c1_arc_halt_req : 1;
        unsigned int c1_arc_run_req : 1;
        unsigned int isp_arc_mem_ctrl_s : 26;
    } reg;
} SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_UNION;
#endif
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_event_a_START (0)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_event_a_END (0)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_event_a_START (1)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_event_a_END (1)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_halt_req_START (2)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_halt_req_END (2)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_run_req_START (3)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c0_arc_run_req_END (3)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_halt_req_START (4)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_halt_req_END (4)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_run_req_START (5)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_c1_arc_run_req_END (5)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_isp_arc_mem_ctrl_s_START (6)
#define SOC_MEDIA2_CRG_ISPCPU_CTRL0_SEC_isp_arc_mem_ctrl_s_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 29;
    } reg;
} SOC_MEDIA2_CRG_DECPROT0SET_UNION;
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
